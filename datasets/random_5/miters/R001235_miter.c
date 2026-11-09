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
struct MatrixBlock_R001235_3513_0
{
  unsigned char stride;
  int density;
  unsigned char scale;
  int trace;
  int buffer[3];
};
struct Vector3D_R001235_3513_1
{
  int norm_sq;
  int coord_y;
  int coord_x;
  int buffer[3];
};
struct SensorNode_R001235_3513_2
{
  short calib;
  unsigned char gain;
  int status;
  int offset;
  int reading;
  int buffer[3];
};
struct FilterState_R001235_3513_3
{
  int gain_db;
  unsigned char mode;
  short prev_in;
  int prev_out;
  unsigned char cutoff;
  int damping;
  int buffer[3];
};
union ColorPixel_R001235_3513_0
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
void fn_R001235_3513_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st_1 = {0};
  struct Vector3D_R001235_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int mask_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_79_1) & 63;
  aux_2 = (aux_2 + mask_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_75_1 = 0;
  int mask_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_75_1 = ((mask_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_75_2 = ((mask_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_75_1) & 127;
    acc_2 = (acc_2 + mask_75_2) & 127;
  }

  int index_reg_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_45_1 > 30)
  {
    acc_1 = ((acc_1 + (index_reg_45_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_45_2 > 30)
  {
    acc_2 = ((acc_2 + (index_reg_45_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_90_1)
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

  switch (index_reg_90_2)
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
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_79_1 == mask_79_2);
  assert(mask_75_1 == mask_75_2);
  assert(index_reg_45_1 == index_reg_45_2);
  assert(index_reg_90_1 == index_reg_90_2);
}

int fn_R001235_3513_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int mask_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_79) & 63;
  acc ^= aux;
  int mask_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_75 = ((mask_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_75) & 127;
  }

  int index_reg_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_45 > 30)
  {
    acc = ((acc + (index_reg_45 * 2)) + 5) & 127;
    aux ^= index_reg_45 & 15;
  }
  else
  {
    acc = ((acc - index_reg_45) + 11) & 127;
    aux += 3;
  }
  int index_reg_90 = (aux + st.buffer[1]) & 3;
  switch (index_reg_90)
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

void fn_R001235_3513_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001235_3513_3 st_1 = {0};
  struct FilterState_R001235_3513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int residue_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_78_1)
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

  switch (residue_78_2)
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

  int threshold_51_1 = 0;
  int threshold_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_51_1 = ((threshold_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_51_2 = ((threshold_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_51_1) & 127;
    acc_2 = (acc_2 + threshold_51_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_78_1 == residue_78_2);
  assert(threshold_51_1 == threshold_51_2);
}

int fn_R001235_3513_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001235_3513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int residue_78 = (aux + st.buffer[1]) & 3;
  switch (residue_78)
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

  int threshold_51 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_51 = ((threshold_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_51) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001235_3513_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st_1 = {0};
  struct Vector3D_R001235_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int cursor_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_39_1 > 41)
  {
    acc_1 = ((acc_1 + (cursor_39_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_39_2 > 41)
  {
    acc_2 = ((acc_2 + (cursor_39_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_14_1 = local_arr_1[aux_1 % 3];
  int parity_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_14_2 * 2)) & 127;
  int quantum_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_87_1) & 63;
  aux_2 = (aux_2 + quantum_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_39_1 == cursor_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_14_1 == parity_14_2);
  assert(quantum_87_1 == quantum_87_2);
}

int fn_R001235_3513_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int cursor_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_39 > 41)
  {
    acc = ((acc + (cursor_39 * 2)) + 5) & 127;
    aux ^= cursor_39 & 15;
  }
  else
  {
    acc = ((acc - cursor_39) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_14 = local_arr[aux % 3];
  acc = (acc + (parity_14 * 2)) & 127;
  int quantum_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_87) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001235_3513_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001235_3513_3 st_1 = {0};
  struct FilterState_R001235_3513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_57_1 = 0;
  int quantum_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_57_1 = ((quantum_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_57_2 = ((quantum_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_57_1) & 127;
    acc_2 = (acc_2 + quantum_57_2) & 127;
  }

  int pivot_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_73_1 > 29)
  {
    acc_1 = ((acc_1 + (pivot_73_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_73_2 > 29)
  {
    acc_2 = ((acc_2 + (pivot_73_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_73_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_57_1 == quantum_57_2);
  assert(pivot_73_1 == pivot_73_2);
}

int fn_R001235_3513_3(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001235_3513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_57 = ((quantum_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_57) & 127;
  }

  int pivot_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_73 > 29)
  {
    acc = ((acc + (pivot_73 * 2)) + 5) & 127;
    aux ^= pivot_73 & 15;
  }
  else
  {
    acc = ((acc - pivot_73) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001235_3513_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001235_3513_0 st_1 = {0};
  struct MatrixBlock_R001235_3513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int pivot_45_1 = 0;
  int pivot_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_45_1 = ((pivot_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_45_2 = ((pivot_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_45_1) & 127;
    acc_2 = (acc_2 + pivot_45_2) & 127;
  }

  int cursor_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_84_1) & 63;
  aux_2 = (aux_2 + cursor_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_45_1 == pivot_45_2);
  assert(cursor_84_1 == cursor_84_2);
}

int fn_R001235_3513_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001235_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int pivot_45 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_45 = ((pivot_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_45) & 127;
  }

  int cursor_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001235_3513_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st_1 = {0};
  struct Vector3D_R001235_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int cursor_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_22_1) & 63;
  aux_2 = (aux_2 + cursor_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_85_1 > 31)
  {
    acc_1 = ((acc_1 + (offset_85_1 * 2)) + 5) & 127;
    aux_1 ^= offset_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_85_2 > 31)
  {
    acc_2 = ((acc_2 + (offset_85_2 * 2)) + 5) & 127;
    aux_2 ^= offset_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_70_1 = local_arr_1[aux_1 % 3];
  int index_reg_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_70_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_22_1 == cursor_22_2);
  assert(offset_85_1 == offset_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_70_1 == index_reg_70_2);
}

int fn_R001235_3513_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int cursor_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_22) & 63;
  acc ^= aux;
  int offset_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_85 > 31)
  {
    acc = ((acc + (offset_85 * 2)) + 5) & 127;
    aux ^= offset_85 & 15;
  }
  else
  {
    acc = ((acc - offset_85) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_70 = local_arr[aux % 3];
  acc = (acc + (index_reg_70 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001235_3513_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001235_3513_0 st_1 = {0};
  struct MatrixBlock_R001235_3513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int stride_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_57_1)
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

  switch (stride_57_2)
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

  int tracker_86_1 = 0;
  int tracker_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_86_1 = ((tracker_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_86_2 = ((tracker_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_86_1) & 127;
    acc_2 = (acc_2 + tracker_86_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_57_1 == stride_57_2);
  assert(tracker_86_1 == tracker_86_2);
}

int fn_R001235_3513_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001235_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int stride_57 = (aux + st.buffer[1]) & 3;
  switch (stride_57)
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

  int tracker_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_86 = ((tracker_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_86) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001235_3513_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st_1 = {0};
  struct Vector3D_R001235_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int margin_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_42_1 > 34)
  {
    acc_1 = ((acc_1 + (margin_42_1 * 2)) + 5) & 127;
    aux_1 ^= margin_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_42_2 > 34)
  {
    acc_2 = ((acc_2 + (margin_42_2 * 2)) + 5) & 127;
    aux_2 ^= margin_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_42_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_18_1)
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

  switch (scale_18_2)
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
  int phase_45_1 = local_arr_1[aux_1 % 3];
  int phase_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_42_1 == margin_42_2);
  assert(scale_18_1 == scale_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_45_1 == phase_45_2);
}

int fn_R001235_3513_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int margin_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_42 > 34)
  {
    acc = ((acc + (margin_42 * 2)) + 5) & 127;
    aux ^= margin_42 & 15;
  }
  else
  {
    acc = ((acc - margin_42) + 11) & 127;
    aux += 3;
  }
  int scale_18 = (aux + st.buffer[1]) & 3;
  switch (scale_18)
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
  int phase_45 = local_arr[aux % 3];
  acc = (acc + (phase_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001235_3513_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001235_3513_3 st_1 = {0};
  struct FilterState_R001235_3513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_15_1 = local_arr_1[aux_1 % 3];
  int checksum_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_15_2 * 2)) & 127;
  int stride_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_46_1)
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

  switch (stride_46_2)
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

  int bound_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_85_1) & 63;
  aux_2 = (aux_2 + bound_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_15_1 == checksum_15_2);
  assert(stride_46_1 == stride_46_2);
  assert(bound_85_1 == bound_85_2);
}

int fn_R001235_3513_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001235_3513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int checksum_15 = local_arr[aux % 3];
  acc = (acc + (checksum_15 * 2)) & 127;
  int stride_46 = (aux + st.buffer[1]) & 3;
  switch (stride_46)
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

  int bound_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_85) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001235_3513_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001235_3513_0 st_1 = {0};
  struct MatrixBlock_R001235_3513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_21_1 > 34)
  {
    acc_1 = ((acc_1 + (scale_21_1 * 2)) + 5) & 127;
    aux_1 ^= scale_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_21_2 > 34)
  {
    acc_2 = ((acc_2 + (scale_21_2 * 2)) + 5) & 127;
    aux_2 ^= scale_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_88_1 = local_arr_1[aux_1 % 3];
  int parity_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_88_2 * 2)) & 127;
  int damping_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_42_1)
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

  switch (damping_42_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_21_1 == scale_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_88_1 == parity_88_2);
  assert(damping_42_1 == damping_42_2);
}

int fn_R001235_3513_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001235_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_21 > 34)
  {
    acc = ((acc + (scale_21 * 2)) + 5) & 127;
    aux ^= scale_21 & 15;
  }
  else
  {
    acc = ((acc - scale_21) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_88 = local_arr[aux % 3];
  acc = (acc + (parity_88 * 2)) & 127;
  int damping_42 = (aux + st.buffer[1]) & 3;
  switch (damping_42)
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

void fn_R001235_3513_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st_1 = {0};
  struct Vector3D_R001235_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int metric_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_84_1) & 63;
  aux_2 = (aux_2 + metric_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_68_1 = local_arr_1[aux_1 % 3];
  int factor_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_84_1 == metric_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_68_1 == factor_68_2);
}

int fn_R001235_3513_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int metric_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_84) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_68 = local_arr[aux % 3];
  acc = (acc + (factor_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001235_3513_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001235_3513_0 st_1 = {0};
  struct MatrixBlock_R001235_3513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int segment_20_1 = 0;
  int segment_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_20_1 = ((segment_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_20_2 = ((segment_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_20_1) & 127;
    acc_2 = (acc_2 + segment_20_2) & 127;
  }

  int mask_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_31_1)
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

  switch (mask_31_2)
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

  int tracker_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_94_1 > 32)
  {
    acc_1 = ((acc_1 + (tracker_94_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_94_2 > 32)
  {
    acc_2 = ((acc_2 + (tracker_94_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_94_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_20_1 == segment_20_2);
  assert(mask_31_1 == mask_31_2);
  assert(tracker_94_1 == tracker_94_2);
}

int fn_R001235_3513_11(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001235_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int segment_20 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_20 = ((segment_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_20) & 127;
  }

  int mask_31 = (aux + st.buffer[1]) & 3;
  switch (mask_31)
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

  int tracker_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_94 > 32)
  {
    acc = ((acc + (tracker_94 * 2)) + 5) & 127;
    aux ^= tracker_94 & 15;
  }
  else
  {
    acc = ((acc - tracker_94) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001235_3513_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st_1 = {0};
  struct Vector3D_R001235_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int index_reg_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_36_1) & 63;
  aux_2 = (aux_2 + index_reg_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_86_1 > 35)
  {
    acc_1 = ((acc_1 + (vector_86_1 * 2)) + 5) & 127;
    aux_1 ^= vector_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_86_2 > 35)
  {
    acc_2 = ((acc_2 + (vector_86_2 * 2)) + 5) & 127;
    aux_2 ^= vector_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_86_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_36_1 == index_reg_36_2);
  assert(vector_86_1 == vector_86_2);
}

int fn_R001235_3513_12(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int index_reg_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_36) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_86 > 35)
  {
    acc = ((acc + (vector_86 * 2)) + 5) & 127;
    aux ^= vector_86 & 15;
  }
  else
  {
    acc = ((acc - vector_86) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001235_3513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001235_3513_2 st_1 = {0};
  struct SensorNode_R001235_3513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int phase_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_12_1)
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

  switch (phase_12_2)
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

  int tally_19_1 = 0;
  int tally_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_19_1 = ((tally_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_19_2 = ((tally_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_19_1) & 127;
    acc_2 = (acc_2 + tally_19_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_12_1 == phase_12_2);
  assert(tally_19_1 == tally_19_2);
}

int fn_R001235_3513_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001235_3513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int phase_12 = (aux + st.buffer[1]) & 3;
  switch (phase_12)
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

  int tally_19 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_19 = ((tally_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_19) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001235_3513_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st_1 = {0};
  struct Vector3D_R001235_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int index_reg_92_1 = 0;
  int index_reg_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_92_1 = ((index_reg_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_92_2 = ((index_reg_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_92_1) & 127;
    acc_2 = (acc_2 + index_reg_92_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_75_1 = local_arr_1[aux_1 % 3];
  int quotient_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_75_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_92_1 == index_reg_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_75_1 == quotient_75_2);
}

int fn_R001235_3513_14(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int index_reg_92 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_92 = ((index_reg_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_92) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quotient_75 = local_arr[aux % 3];
  acc = (acc + (quotient_75 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001235_3513_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st_1 = {0};
  struct Vector3D_R001235_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int sample_98_1 = 0;
  int sample_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_98_1 = ((sample_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_98_2 = ((sample_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_98_1) & 127;
    acc_2 = (acc_2 + sample_98_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_85_1 = local_arr_1[aux_1 % 3];
  int vector_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_85_2 * 2)) & 127;
  int weight_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_16_1)
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

  switch (weight_16_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_98_1 == sample_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_85_1 == vector_85_2);
  assert(weight_16_1 == weight_16_2);
}

int fn_R001235_3513_15(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int sample_98 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_98 = ((sample_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_98) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int vector_85 = local_arr[aux % 3];
  acc = (acc + (vector_85 * 2)) & 127;
  int weight_16 = (aux + st.buffer[1]) & 3;
  switch (weight_16)
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

void fn_R001235_3513_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001235_3513_3 st_1 = {0};
  struct FilterState_R001235_3513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int margin_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_34_1 > 45)
  {
    acc_1 = ((acc_1 + (margin_34_1 * 2)) + 5) & 127;
    aux_1 ^= margin_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_34_2 > 45)
  {
    acc_2 = ((acc_2 + (margin_34_2 * 2)) + 5) & 127;
    aux_2 ^= margin_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_34_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_34_1 == margin_34_2);
}

int fn_R001235_3513_16(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001235_3513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int margin_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_34 > 45)
  {
    acc = ((acc + (margin_34 * 2)) + 5) & 127;
    aux ^= margin_34 & 15;
  }
  else
  {
    acc = ((acc - margin_34) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001235_3513_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st_1 = {0};
  struct Vector3D_R001235_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_57_1)
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

  switch (accumulator_57_2)
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

  int cursor_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_67_1 > 16)
  {
    acc_1 = ((acc_1 + (cursor_67_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_67_2 > 16)
  {
    acc_2 = ((acc_2 + (cursor_67_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_67_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_64_1 = 0;
  int vector_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_64_1 = ((vector_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_64_2 = ((vector_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_64_1) & 127;
    acc_2 = (acc_2 + vector_64_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_57_1 == accumulator_57_2);
  assert(cursor_67_1 == cursor_67_2);
  assert(vector_64_1 == vector_64_2);
}

int fn_R001235_3513_17(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_57 = (aux + st.buffer[1]) & 3;
  switch (accumulator_57)
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

  int cursor_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_67 > 16)
  {
    acc = ((acc + (cursor_67 * 2)) + 5) & 127;
    aux ^= cursor_67 & 15;
  }
  else
  {
    acc = ((acc - cursor_67) + 11) & 127;
    aux += 3;
  }
  int vector_64 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_64 = ((vector_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_64) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001235_3513_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001235_3513_0 st_1 = {0};
  struct MatrixBlock_R001235_3513_0 st_2 = {0};
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
  int scale_99_1 = local_arr_1[aux_1 % 3];
  int scale_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_99_2 * 2)) & 127;
  int segment_30_1 = 0;
  int segment_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_30_1 = ((segment_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_30_2 = ((segment_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_30_1) & 127;
    acc_2 = (acc_2 + segment_30_2) & 127;
  }

  int cursor_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_55_1) & 63;
  aux_2 = (aux_2 + cursor_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_99_1 == scale_99_2);
  assert(segment_30_1 == segment_30_2);
  assert(cursor_55_1 == cursor_55_2);
}

int fn_R001235_3513_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001235_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_99 = local_arr[aux % 3];
  acc = (acc + (scale_99 * 2)) & 127;
  int segment_30 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_30 = ((segment_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_30) & 127;
  }

  int cursor_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_55) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001235_3513_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st_1 = {0};
  struct Vector3D_R001235_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_96_1 = local_arr_1[aux_1 % 3];
  int mask_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_96_2 * 2)) & 127;
  int vector_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_58_1)
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

  switch (vector_58_2)
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

  int margin_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_33_1 > 14)
  {
    acc_1 = ((acc_1 + (margin_33_1 * 2)) + 5) & 127;
    aux_1 ^= margin_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_33_2 > 14)
  {
    acc_2 = ((acc_2 + (margin_33_2 * 2)) + 5) & 127;
    aux_2 ^= margin_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
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

  assert(mask_96_1 == mask_96_2);
  assert(vector_58_1 == vector_58_2);
  assert(margin_33_1 == margin_33_2);
}

int fn_R001235_3513_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int mask_96 = local_arr[aux % 3];
  acc = (acc + (mask_96 * 2)) & 127;
  int vector_58 = (aux + st.buffer[1]) & 3;
  switch (vector_58)
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

  int margin_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_33 > 14)
  {
    acc = ((acc + (margin_33 * 2)) + 5) & 127;
    aux ^= margin_33 & 15;
  }
  else
  {
    acc = ((acc - margin_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001235_3513_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st_1 = {0};
  struct Vector3D_R001235_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int margin_40_1 = 0;
  int margin_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_40_1 = ((margin_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_40_2 = ((margin_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_40_1) & 127;
    acc_2 = (acc_2 + margin_40_2) & 127;
  }

  int scale_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_50_1 > 40)
  {
    acc_1 = ((acc_1 + (scale_50_1 * 2)) + 5) & 127;
    aux_1 ^= scale_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_50_2 > 40)
  {
    acc_2 = ((acc_2 + (scale_50_2 * 2)) + 5) & 127;
    aux_2 ^= scale_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_61_1) & 63;
  aux_2 = (aux_2 + threshold_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_40_1 == margin_40_2);
  assert(scale_50_1 == scale_50_2);
  assert(threshold_61_1 == threshold_61_2);
}

int fn_R001235_3513_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001235_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int margin_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_40 = ((margin_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_40) & 127;
  }

  int scale_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_50 > 40)
  {
    acc = ((acc + (scale_50 * 2)) + 5) & 127;
    aux ^= scale_50 & 15;
  }
  else
  {
    acc = ((acc - scale_50) + 11) & 127;
    aux += 3;
  }
  int threshold_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_61) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001235_0_1;
  int sec_r001235_0_2;
  int sec_r001235_1_1;
  int sec_r001235_1_2;
  int sec_r001235_2_1;
  int sec_r001235_2_2;
  int sec_r001235_3_1;
  int sec_r001235_3_2;
  int sec_r001235_4_1;
  int sec_r001235_4_2;
  int sec_r001235_5_1;
  int sec_r001235_5_2;
  int sec_r001235_6_1;
  int sec_r001235_6_2;
  int sec_r001235_7_1;
  int sec_r001235_7_2;
  int sec_r001235_8_1;
  int sec_r001235_8_2;
  int sec_r001235_9_1;
  int sec_r001235_9_2;
  int sec_r001235_10_1;
  int sec_r001235_10_2;
  int sec_r001235_11_1;
  int sec_r001235_11_2;
  int sec_r001235_12_1;
  int sec_r001235_12_2;
  int sec_r001235_13_1;
  int sec_r001235_13_2;
  int sec_r001235_14_1;
  int sec_r001235_14_2;
  int sec_r001235_15_1;
  int sec_r001235_15_2;
  int sec_r001235_16_1;
  int sec_r001235_16_2;
  int pub_r001235_0_1;
  int pub_r001235_0_2;
  int pub_r001235_1_1;
  int pub_r001235_1_2;
  int pub_r001235_2_1;
  int pub_r001235_2_2;
  int pub_r001235_3_1;
  int pub_r001235_3_2;
  int pub_r001235_4_1;
  int pub_r001235_4_2;
  int pub_r001235_5_1;
  int pub_r001235_5_2;
  int pub_r001235_6_1;
  int pub_r001235_6_2;
  int pub_r001235_7_1;
  int pub_r001235_7_2;
  int pub_r001235_8_1;
  int pub_r001235_8_2;
  int pub_r001235_9_1;
  int pub_r001235_9_2;
  int pub_r001235_10_1;
  int pub_r001235_10_2;
  int pub_r001235_11_1;
  int pub_r001235_11_2;
  int pub_r001235_12_1;
  int pub_r001235_12_2;
  int pub_r001235_13_1;
  int pub_r001235_13_2;
  int pub_r001235_14_1;
  int pub_r001235_14_2;
  int pub_r001235_15_1;
  int pub_r001235_15_2;
  int pub_r001235_16_1;
  int pub_r001235_16_2;
  int pub_r001235_17_1;
  int pub_r001235_17_2;
  int pub_r001235_18_1;
  int pub_r001235_18_2;
  int pub_r001235_19_1;
  int pub_r001235_19_2;
  int pub_r001235_20_1;
  int pub_r001235_20_2;
  int pub_r001235_21_1;
  int pub_r001235_21_2;
  int pub_r001235_22_1;
  int pub_r001235_22_2;
  int pub_r001235_23_1;
  int pub_r001235_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001235_0_1 >= (-100)) && (pub_r001235_0_1 <= 100));
  __CPROVER_assume((pub_r001235_0_2 >= (-100)) && (pub_r001235_0_2 <= 100));
  __CPROVER_assume((pub_r001235_1_1 >= (-100)) && (pub_r001235_1_1 <= 100));
  __CPROVER_assume((pub_r001235_1_2 >= (-100)) && (pub_r001235_1_2 <= 100));
  __CPROVER_assume((pub_r001235_2_1 >= (-100)) && (pub_r001235_2_1 <= 100));
  __CPROVER_assume((pub_r001235_2_2 >= (-100)) && (pub_r001235_2_2 <= 100));
  __CPROVER_assume((pub_r001235_3_1 >= (-100)) && (pub_r001235_3_1 <= 100));
  __CPROVER_assume((pub_r001235_3_2 >= (-100)) && (pub_r001235_3_2 <= 100));
  __CPROVER_assume((pub_r001235_4_1 >= (-100)) && (pub_r001235_4_1 <= 100));
  __CPROVER_assume((pub_r001235_4_2 >= (-100)) && (pub_r001235_4_2 <= 100));
  __CPROVER_assume((pub_r001235_5_1 >= (-100)) && (pub_r001235_5_1 <= 100));
  __CPROVER_assume((pub_r001235_5_2 >= (-100)) && (pub_r001235_5_2 <= 100));
  __CPROVER_assume((pub_r001235_6_1 >= (-100)) && (pub_r001235_6_1 <= 100));
  __CPROVER_assume((pub_r001235_6_2 >= (-100)) && (pub_r001235_6_2 <= 100));
  __CPROVER_assume((pub_r001235_7_1 >= (-100)) && (pub_r001235_7_1 <= 100));
  __CPROVER_assume((pub_r001235_7_2 >= (-100)) && (pub_r001235_7_2 <= 100));
  __CPROVER_assume((pub_r001235_8_1 >= (-100)) && (pub_r001235_8_1 <= 100));
  __CPROVER_assume((pub_r001235_8_2 >= (-100)) && (pub_r001235_8_2 <= 100));
  __CPROVER_assume((pub_r001235_9_1 >= (-100)) && (pub_r001235_9_1 <= 100));
  __CPROVER_assume((pub_r001235_9_2 >= (-100)) && (pub_r001235_9_2 <= 100));
  __CPROVER_assume((pub_r001235_10_1 >= (-100)) && (pub_r001235_10_1 <= 100));
  __CPROVER_assume((pub_r001235_10_2 >= (-100)) && (pub_r001235_10_2 <= 100));
  __CPROVER_assume((pub_r001235_11_1 >= (-100)) && (pub_r001235_11_1 <= 100));
  __CPROVER_assume((pub_r001235_11_2 >= (-100)) && (pub_r001235_11_2 <= 100));
  __CPROVER_assume((pub_r001235_12_1 >= (-100)) && (pub_r001235_12_1 <= 100));
  __CPROVER_assume((pub_r001235_12_2 >= (-100)) && (pub_r001235_12_2 <= 100));
  __CPROVER_assume((pub_r001235_13_1 >= (-100)) && (pub_r001235_13_1 <= 100));
  __CPROVER_assume((pub_r001235_13_2 >= (-100)) && (pub_r001235_13_2 <= 100));
  __CPROVER_assume((pub_r001235_14_1 >= (-100)) && (pub_r001235_14_1 <= 100));
  __CPROVER_assume((pub_r001235_14_2 >= (-100)) && (pub_r001235_14_2 <= 100));
  __CPROVER_assume((pub_r001235_15_1 >= (-100)) && (pub_r001235_15_1 <= 100));
  __CPROVER_assume((pub_r001235_15_2 >= (-100)) && (pub_r001235_15_2 <= 100));
  __CPROVER_assume((pub_r001235_16_1 >= (-100)) && (pub_r001235_16_1 <= 100));
  __CPROVER_assume((pub_r001235_16_2 >= (-100)) && (pub_r001235_16_2 <= 100));
  __CPROVER_assume((pub_r001235_17_1 >= (-100)) && (pub_r001235_17_1 <= 100));
  __CPROVER_assume((pub_r001235_17_2 >= (-100)) && (pub_r001235_17_2 <= 100));
  __CPROVER_assume((pub_r001235_18_1 >= (-100)) && (pub_r001235_18_1 <= 100));
  __CPROVER_assume((pub_r001235_18_2 >= (-100)) && (pub_r001235_18_2 <= 100));
  __CPROVER_assume((pub_r001235_19_1 >= (-100)) && (pub_r001235_19_1 <= 100));
  __CPROVER_assume((pub_r001235_19_2 >= (-100)) && (pub_r001235_19_2 <= 100));
  __CPROVER_assume((pub_r001235_20_1 >= (-100)) && (pub_r001235_20_1 <= 100));
  __CPROVER_assume((pub_r001235_20_2 >= (-100)) && (pub_r001235_20_2 <= 100));
  __CPROVER_assume((pub_r001235_21_1 >= (-100)) && (pub_r001235_21_1 <= 100));
  __CPROVER_assume((pub_r001235_21_2 >= (-100)) && (pub_r001235_21_2 <= 100));
  __CPROVER_assume((pub_r001235_22_1 >= (-100)) && (pub_r001235_22_1 <= 100));
  __CPROVER_assume((pub_r001235_22_2 >= (-100)) && (pub_r001235_22_2 <= 100));
  __CPROVER_assume((pub_r001235_23_1 >= (-100)) && (pub_r001235_23_1 <= 100));
  __CPROVER_assume((pub_r001235_23_2 >= (-100)) && (pub_r001235_23_2 <= 100));
  __CPROVER_assume((sec_r001235_0_1 >= 0) && (sec_r001235_0_1 <= 255));
  __CPROVER_assume((sec_r001235_0_2 >= 0) && (sec_r001235_0_2 <= 255));
  __CPROVER_assume((sec_r001235_1_1 >= 0) && (sec_r001235_1_1 <= 255));
  __CPROVER_assume((sec_r001235_1_2 >= 0) && (sec_r001235_1_2 <= 255));
  __CPROVER_assume((sec_r001235_2_1 >= 0) && (sec_r001235_2_1 <= 255));
  __CPROVER_assume((sec_r001235_2_2 >= 0) && (sec_r001235_2_2 <= 255));
  __CPROVER_assume((sec_r001235_3_1 >= 0) && (sec_r001235_3_1 <= 255));
  __CPROVER_assume((sec_r001235_3_2 >= 0) && (sec_r001235_3_2 <= 255));
  __CPROVER_assume((sec_r001235_4_1 >= 0) && (sec_r001235_4_1 <= 255));
  __CPROVER_assume((sec_r001235_4_2 >= 0) && (sec_r001235_4_2 <= 255));
  __CPROVER_assume((sec_r001235_5_1 >= 0) && (sec_r001235_5_1 <= 255));
  __CPROVER_assume((sec_r001235_5_2 >= 0) && (sec_r001235_5_2 <= 255));
  __CPROVER_assume((sec_r001235_6_1 >= 0) && (sec_r001235_6_1 <= 255));
  __CPROVER_assume((sec_r001235_6_2 >= 0) && (sec_r001235_6_2 <= 255));
  __CPROVER_assume((sec_r001235_7_1 >= 0) && (sec_r001235_7_1 <= 255));
  __CPROVER_assume((sec_r001235_7_2 >= 0) && (sec_r001235_7_2 <= 255));
  __CPROVER_assume((sec_r001235_8_1 >= 0) && (sec_r001235_8_1 <= 255));
  __CPROVER_assume((sec_r001235_8_2 >= 0) && (sec_r001235_8_2 <= 255));
  __CPROVER_assume((sec_r001235_9_1 >= 0) && (sec_r001235_9_1 <= 255));
  __CPROVER_assume((sec_r001235_9_2 >= 0) && (sec_r001235_9_2 <= 255));
  __CPROVER_assume((sec_r001235_10_1 >= 0) && (sec_r001235_10_1 <= 255));
  __CPROVER_assume((sec_r001235_10_2 >= 0) && (sec_r001235_10_2 <= 255));
  __CPROVER_assume((sec_r001235_11_1 >= 0) && (sec_r001235_11_1 <= 255));
  __CPROVER_assume((sec_r001235_11_2 >= 0) && (sec_r001235_11_2 <= 255));
  __CPROVER_assume((sec_r001235_12_1 >= 0) && (sec_r001235_12_1 <= 255));
  __CPROVER_assume((sec_r001235_12_2 >= 0) && (sec_r001235_12_2 <= 255));
  __CPROVER_assume((sec_r001235_13_1 >= 0) && (sec_r001235_13_1 <= 255));
  __CPROVER_assume((sec_r001235_13_2 >= 0) && (sec_r001235_13_2 <= 255));
  __CPROVER_assume((sec_r001235_14_1 >= 0) && (sec_r001235_14_1 <= 255));
  __CPROVER_assume((sec_r001235_14_2 >= 0) && (sec_r001235_14_2 <= 255));
  __CPROVER_assume((sec_r001235_15_1 >= 0) && (sec_r001235_15_1 <= 255));
  __CPROVER_assume((sec_r001235_15_2 >= 0) && (sec_r001235_15_2 <= 255));
  __CPROVER_assume((sec_r001235_16_1 >= 0) && (sec_r001235_16_1 <= 255));
  __CPROVER_assume((sec_r001235_16_2 >= 0) && (sec_r001235_16_2 <= 255));
  struct MatrixBlock_R001235_3513_0 st_var_0_1 = {0};
  struct MatrixBlock_R001235_3513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001235_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001235_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001235_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001235_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001235_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001235_0_2 + 7) & 15;
  struct Vector3D_R001235_3513_1 st_var_1_1 = {0};
  struct Vector3D_R001235_3513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001235_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001235_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001235_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001235_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001235_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001235_0_2 + 9) & 15;
  struct SensorNode_R001235_3513_2 st_var_2_1 = {0};
  struct SensorNode_R001235_3513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001235_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001235_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001235_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001235_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001235_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001235_0_2 + 11) & 15;
  struct FilterState_R001235_3513_3 st_var_3_1 = {0};
  struct FilterState_R001235_3513_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001235_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001235_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001235_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001235_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001235_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001235_0_2 + 13) & 15;
  union ColorPixel_R001235_3513_0 u_var_1;
  union ColorPixel_R001235_3513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001235_3513_0(sec_r001235_0_1, pub_r001235_1_1, pub_r001235_2_1, pub_r001235_3_1, pub_r001235_4_1);
  int helper_flow_0_2 = fn_R001235_3513_0(sec_r001235_0_2, pub_r001235_1_2, pub_r001235_2_2, pub_r001235_3_2, pub_r001235_4_2);
  fn_R001235_3513_0_2(sec_r001235_0_1, pub_r001235_1_1, pub_r001235_2_1, pub_r001235_3_1, pub_r001235_4_1, sec_r001235_0_2, pub_r001235_1_2, pub_r001235_2_2, pub_r001235_3_2, pub_r001235_4_2);
  int helper_flow_1_1 = fn_R001235_3513_1(sec_r001235_1_1, sec_r001235_2_1, pub_r001235_3_1, pub_r001235_4_1);
  int helper_flow_1_2 = fn_R001235_3513_1(sec_r001235_1_2, sec_r001235_2_2, pub_r001235_3_2, pub_r001235_4_2);
  fn_R001235_3513_1_2(sec_r001235_1_1, sec_r001235_2_1, pub_r001235_3_1, pub_r001235_4_1, sec_r001235_1_2, sec_r001235_2_2, pub_r001235_3_2, pub_r001235_4_2);
  int helper_flow_2_1 = fn_R001235_3513_2(sec_r001235_2_1, sec_r001235_3_1, pub_r001235_4_1, pub_r001235_5_1);
  int helper_flow_2_2 = fn_R001235_3513_2(sec_r001235_2_2, sec_r001235_3_2, pub_r001235_4_2, pub_r001235_5_2);
  fn_R001235_3513_2_2(sec_r001235_2_1, sec_r001235_3_1, pub_r001235_4_1, pub_r001235_5_1, sec_r001235_2_2, sec_r001235_3_2, pub_r001235_4_2, pub_r001235_5_2);
  int helper_flow_3_1 = fn_R001235_3513_3(sec_r001235_3_1, sec_r001235_4_1, pub_r001235_5_1);
  int helper_flow_3_2 = fn_R001235_3513_3(sec_r001235_3_2, sec_r001235_4_2, pub_r001235_5_2);
  fn_R001235_3513_3_2(sec_r001235_3_1, sec_r001235_4_1, pub_r001235_5_1, sec_r001235_3_2, sec_r001235_4_2, pub_r001235_5_2);
  int helper_flow_4_1 = fn_R001235_3513_4(sec_r001235_4_1, pub_r001235_5_1, pub_r001235_6_1, pub_r001235_7_1, pub_r001235_8_1);
  int helper_flow_4_2 = fn_R001235_3513_4(sec_r001235_4_2, pub_r001235_5_2, pub_r001235_6_2, pub_r001235_7_2, pub_r001235_8_2);
  fn_R001235_3513_4_2(sec_r001235_4_1, pub_r001235_5_1, pub_r001235_6_1, pub_r001235_7_1, pub_r001235_8_1, sec_r001235_4_2, pub_r001235_5_2, pub_r001235_6_2, pub_r001235_7_2, pub_r001235_8_2);
  int helper_flow_5_1 = fn_R001235_3513_5(sec_r001235_5_1, pub_r001235_6_1, pub_r001235_7_1, pub_r001235_8_1, pub_r001235_9_1);
  int helper_flow_5_2 = fn_R001235_3513_5(sec_r001235_5_2, pub_r001235_6_2, pub_r001235_7_2, pub_r001235_8_2, pub_r001235_9_2);
  fn_R001235_3513_5_2(sec_r001235_5_1, pub_r001235_6_1, pub_r001235_7_1, pub_r001235_8_1, pub_r001235_9_1, sec_r001235_5_2, pub_r001235_6_2, pub_r001235_7_2, pub_r001235_8_2, pub_r001235_9_2);
  int helper_flow_6_1 = fn_R001235_3513_6(sec_r001235_6_1, sec_r001235_7_1, pub_r001235_8_1, pub_r001235_9_1, pub_r001235_10_1);
  int helper_flow_6_2 = fn_R001235_3513_6(sec_r001235_6_2, sec_r001235_7_2, pub_r001235_8_2, pub_r001235_9_2, pub_r001235_10_2);
  fn_R001235_3513_6_2(sec_r001235_6_1, sec_r001235_7_1, pub_r001235_8_1, pub_r001235_9_1, pub_r001235_10_1, sec_r001235_6_2, sec_r001235_7_2, pub_r001235_8_2, pub_r001235_9_2, pub_r001235_10_2);
  int helper_flow_7_1 = fn_R001235_3513_7(sec_r001235_7_1, pub_r001235_8_1, pub_r001235_9_1, pub_r001235_10_1);
  int helper_flow_7_2 = fn_R001235_3513_7(sec_r001235_7_2, pub_r001235_8_2, pub_r001235_9_2, pub_r001235_10_2);
  fn_R001235_3513_7_2(sec_r001235_7_1, pub_r001235_8_1, pub_r001235_9_1, pub_r001235_10_1, sec_r001235_7_2, pub_r001235_8_2, pub_r001235_9_2, pub_r001235_10_2);
  int helper_flow_8_1 = fn_R001235_3513_8(sec_r001235_8_1, sec_r001235_9_1, pub_r001235_10_1, pub_r001235_11_1);
  int helper_flow_8_2 = fn_R001235_3513_8(sec_r001235_8_2, sec_r001235_9_2, pub_r001235_10_2, pub_r001235_11_2);
  fn_R001235_3513_8_2(sec_r001235_8_1, sec_r001235_9_1, pub_r001235_10_1, pub_r001235_11_1, sec_r001235_8_2, sec_r001235_9_2, pub_r001235_10_2, pub_r001235_11_2);
  int stage_v_0_1 = ((sec_r001235_7_1 << 1) ^ (pub_r001235_8_1 >> 1)) & 127;
  int stage_v_0_2 = ((sec_r001235_7_2 << 1) ^ (pub_r001235_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_0_2 + 1) & 15;
  out_sink_1 ^= stage_v_0_1 & 63;
  out_sink_2 ^= stage_v_0_2 & 63;
  int stage_v_1_1 = ((pub_r001235_8_1 * 2) + 6) & 63;
  int stage_v_1_2 = ((pub_r001235_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001235_17_1 * 2) + 26) & 63;
  int stage_v_2_2 = ((pub_r001235_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001235_4_1 * 2) + 49) & 63;
  int stage_v_3_2 = ((pub_r001235_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((sec_r001235_2_1 << 1) ^ (pub_r001235_18_1 >> 1)) & 127;
  int stage_v_4_2 = ((sec_r001235_2_2 << 1) ^ (pub_r001235_18_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_4_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_4_2 + 1) & 15;
  out_sink_1 ^= stage_v_4_1 & 63;
  out_sink_2 ^= stage_v_4_2 & 63;
  int stage_v_5_1 = ((pub_r001235_5_1 * 2) + 8) & 63;
  int stage_v_5_2 = ((pub_r001235_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((helper_flow_1_1 << 1) ^ (pub_r001235_18_1 >> 1)) & 127;
  int stage_v_6_2 = ((helper_flow_1_2 << 1) ^ (pub_r001235_18_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_6_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_6_2 + 1) & 15;
  out_sink_1 ^= stage_v_6_1 & 63;
  out_sink_2 ^= stage_v_6_2 & 63;
  int stage_v_7_1 = ((pub_r001235_20_1 * 2) + 36) & 63;
  int stage_v_7_2 = ((pub_r001235_20_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((sec_r001235_2_1 << 1) ^ (pub_r001235_9_1 >> 1)) & 127;
  int stage_v_8_2 = ((sec_r001235_2_2 << 1) ^ (pub_r001235_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_8_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_8_2 + 1) & 15;
  out_sink_1 ^= stage_v_8_1 & 63;
  out_sink_2 ^= stage_v_8_2 & 63;
  int stage_v_9_1 = ((sec_r001235_9_1 << 1) ^ (pub_r001235_18_1 >> 1)) & 127;
  int stage_v_9_2 = ((sec_r001235_9_2 << 1) ^ (pub_r001235_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_9_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_9_2 + 1) & 15;
  out_sink_1 ^= stage_v_9_1 & 63;
  out_sink_2 ^= stage_v_9_2 & 63;
  int stage_v_10_1 = ((helper_flow_5_1 << 1) ^ (pub_r001235_14_1 >> 1)) & 127;
  int stage_v_10_2 = ((helper_flow_5_2 << 1) ^ (pub_r001235_14_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_10_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_10_2 + 1) & 15;
  out_sink_1 ^= stage_v_10_1 & 63;
  out_sink_2 ^= stage_v_10_2 & 63;
  int stage_v_11_1 = ((pub_r001235_23_1 * 2) + 48) & 63;
  int stage_v_11_2 = ((pub_r001235_23_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001235_4_1 * 2) + 20) & 63;
  int stage_v_12_2 = ((pub_r001235_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001235_21_1 * 2) + 44) & 63;
  int stage_v_13_2 = ((pub_r001235_21_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((helper_flow_7_1 << 1) ^ (pub_r001235_2_1 >> 1)) & 127;
  int stage_v_14_2 = ((helper_flow_7_2 << 1) ^ (pub_r001235_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_14_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_14_2 + 1) & 15;
  out_sink_1 ^= stage_v_14_1 & 63;
  out_sink_2 ^= stage_v_14_2 & 63;
  int stage_v_15_1 = ((helper_flow_1_1 << 1) ^ (pub_r001235_8_1 >> 1)) & 127;
  int stage_v_15_2 = ((helper_flow_1_2 << 1) ^ (pub_r001235_8_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_15_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_15_2 + 1) & 15;
  out_sink_1 ^= stage_v_15_1 & 63;
  out_sink_2 ^= stage_v_15_2 & 63;
  int stage_v_16_1 = ((pub_r001235_15_1 * 2) + 33) & 63;
  int stage_v_16_2 = ((pub_r001235_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001235_20_1 * 2) + 34) & 63;
  int stage_v_17_2 = ((pub_r001235_20_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001235_12_1 * 2) + 13) & 63;
  int stage_v_18_2 = ((pub_r001235_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001235_3_1 * 2) + 48) & 63;
  int stage_v_19_2 = ((pub_r001235_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001235_12_1 * 2) + 9) & 63;
  int stage_v_20_2 = ((pub_r001235_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001235_6_1 * 2) + 24) & 63;
  int stage_v_21_2 = ((pub_r001235_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001235_5_1 * 2) + 30) & 63;
  int stage_v_22_2 = ((pub_r001235_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((stage_v_6_1 << 1) ^ (pub_r001235_21_1 >> 1)) & 127;
  int stage_v_23_2 = ((stage_v_6_2 << 1) ^ (pub_r001235_21_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_23_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_23_2 + 1) & 15;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = ((pub_r001235_12_1 * 2) + 35) & 63;
  int stage_v_24_2 = ((pub_r001235_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((stage_v_23_1 << 1) ^ (pub_r001235_23_1 >> 1)) & 127;
  int stage_v_25_2 = ((stage_v_23_2 << 1) ^ (pub_r001235_23_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_25_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_25_2 + 1) & 15;
  out_sink_1 ^= stage_v_25_1 & 63;
  out_sink_2 ^= stage_v_25_2 & 63;
  int stage_v_26_1 = ((pub_r001235_21_1 * 2) + 35) & 63;
  int stage_v_26_2 = ((pub_r001235_21_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((stage_v_9_1 << 1) ^ (pub_r001235_6_1 >> 1)) & 127;
  int stage_v_27_2 = ((stage_v_9_2 << 1) ^ (pub_r001235_6_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_27_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_27_2 + 1) & 15;
  out_sink_1 ^= stage_v_27_1 & 63;
  out_sink_2 ^= stage_v_27_2 & 63;
  int stage_v_28_1 = ((pub_r001235_12_1 * 2) + 37) & 63;
  int stage_v_28_2 = ((pub_r001235_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((sec_r001235_15_1 << 1) ^ (pub_r001235_21_1 >> 1)) & 127;
  int stage_v_29_2 = ((sec_r001235_15_2 << 1) ^ (pub_r001235_21_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_29_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_29_2 + 1) & 15;
  out_sink_1 ^= stage_v_29_1 & 63;
  out_sink_2 ^= stage_v_29_2 & 63;
  int stage_v_30_1 = ((pub_r001235_6_1 * 2) + 37) & 63;
  int stage_v_30_2 = ((pub_r001235_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001235_16_1 * 2) + 7) & 63;
  int stage_v_31_2 = ((pub_r001235_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001235_4_1 * 2) + 34) & 63;
  int stage_v_32_2 = ((pub_r001235_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001235_12_1 * 2) + 49) & 63;
  int stage_v_33_2 = ((pub_r001235_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((sec_r001235_4_1 << 1) ^ (pub_r001235_11_1 >> 1)) & 127;
  int stage_v_34_2 = ((sec_r001235_4_2 << 1) ^ (pub_r001235_11_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_34_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_34_2 + 1) & 15;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = ((sec_r001235_4_1 << 1) ^ (pub_r001235_20_1 >> 1)) & 127;
  int stage_v_35_2 = ((sec_r001235_4_2 << 1) ^ (pub_r001235_20_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_35_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_35_2 + 1) & 15;
  out_sink_1 ^= stage_v_35_1 & 63;
  out_sink_2 ^= stage_v_35_2 & 63;
  int stage_v_36_1 = ((stage_v_29_1 << 1) ^ (pub_r001235_15_1 >> 1)) & 127;
  int stage_v_36_2 = ((stage_v_29_2 << 1) ^ (pub_r001235_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_36_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_36_2 + 1) & 15;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = ((pub_r001235_18_1 * 2) + 13) & 63;
  int stage_v_37_2 = ((pub_r001235_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((stage_v_0_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_38_2 = ((stage_v_0_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_38_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_38_2 + 1) & 15;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = ((stage_v_34_1 << 1) ^ (pub_r001235_7_1 >> 1)) & 127;
  int stage_v_39_2 = ((stage_v_34_2 << 1) ^ (pub_r001235_7_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_39_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_39_2 + 1) & 15;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = ((sec_r001235_12_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_40_2 = ((sec_r001235_12_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_40_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_40_2 + 1) & 15;
  out_sink_1 ^= stage_v_40_1 & 63;
  out_sink_2 ^= stage_v_40_2 & 63;
  int stage_v_41_1 = ((stage_v_9_1 << 1) ^ (pub_r001235_23_1 >> 1)) & 127;
  int stage_v_41_2 = ((stage_v_9_2 << 1) ^ (pub_r001235_23_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_41_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_41_2 + 1) & 15;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = ((stage_v_25_1 << 1) ^ (pub_r001235_6_1 >> 1)) & 127;
  int stage_v_42_2 = ((stage_v_25_2 << 1) ^ (pub_r001235_6_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_42_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_42_2 + 1) & 15;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = ((stage_v_25_1 << 1) ^ (pub_r001235_14_1 >> 1)) & 127;
  int stage_v_43_2 = ((stage_v_25_2 << 1) ^ (pub_r001235_14_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_43_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_43_2 + 1) & 15;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = ((helper_flow_1_1 << 1) ^ (pub_r001235_18_1 >> 1)) & 127;
  int stage_v_44_2 = ((helper_flow_1_2 << 1) ^ (pub_r001235_18_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_44_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_44_2 + 1) & 15;
  out_sink_1 ^= stage_v_44_1 & 63;
  out_sink_2 ^= stage_v_44_2 & 63;
  int stage_v_45_1 = ((stage_v_25_1 << 1) ^ (pub_r001235_7_1 >> 1)) & 127;
  int stage_v_45_2 = ((stage_v_25_2 << 1) ^ (pub_r001235_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_45_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_45_2 + 1) & 15;
  out_sink_1 ^= stage_v_45_1 & 63;
  out_sink_2 ^= stage_v_45_2 & 63;
  int stage_v_46_1 = ((stage_v_0_1 << 1) ^ (pub_r001235_11_1 >> 1)) & 127;
  int stage_v_46_2 = ((stage_v_0_2 << 1) ^ (pub_r001235_11_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_46_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_46_2 + 1) & 15;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = ((sec_r001235_15_1 << 1) ^ (pub_r001235_11_1 >> 1)) & 127;
  int stage_v_47_2 = ((sec_r001235_15_2 << 1) ^ (pub_r001235_11_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_47_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_47_2 + 1) & 15;
  out_sink_1 ^= stage_v_47_1 & 63;
  out_sink_2 ^= stage_v_47_2 & 63;
  int stage_v_48_1 = ((helper_flow_5_1 << 1) ^ (pub_r001235_18_1 >> 1)) & 127;
  int stage_v_48_2 = ((helper_flow_5_2 << 1) ^ (pub_r001235_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_48_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_48_2 + 1) & 15;
  out_sink_1 ^= stage_v_48_1 & 63;
  out_sink_2 ^= stage_v_48_2 & 63;
  int stage_v_49_1 = ((stage_v_23_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_49_2 = ((stage_v_23_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_49_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_49_2 + 1) & 15;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = ((stage_v_47_1 << 1) ^ (pub_r001235_18_1 >> 1)) & 127;
  int stage_v_50_2 = ((stage_v_47_2 << 1) ^ (pub_r001235_18_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_50_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_50_2 + 1) & 15;
  out_sink_1 ^= stage_v_50_1 & 63;
  out_sink_2 ^= stage_v_50_2 & 63;
  int stage_v_51_1 = ((pub_r001235_7_1 * 2) + 35) & 63;
  int stage_v_51_2 = ((pub_r001235_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001235_5_1 * 2) + 22) & 63;
  int stage_v_52_2 = ((pub_r001235_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((helper_flow_5_1 << 1) ^ (pub_r001235_1_1 >> 1)) & 127;
  int stage_v_53_2 = ((helper_flow_5_2 << 1) ^ (pub_r001235_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_53_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_53_2 + 1) & 15;
  out_sink_1 ^= stage_v_53_1 & 63;
  out_sink_2 ^= stage_v_53_2 & 63;
  int stage_v_54_1 = ((pub_r001235_13_1 * 2) + 20) & 63;
  int stage_v_54_2 = ((pub_r001235_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((sec_r001235_5_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_55_2 = ((sec_r001235_5_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_55_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_55_2 + 1) & 15;
  out_sink_1 ^= stage_v_55_1 & 63;
  out_sink_2 ^= stage_v_55_2 & 63;
  int stage_v_56_1 = ((pub_r001235_19_1 * 2) + 40) & 63;
  int stage_v_56_2 = ((pub_r001235_19_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((stage_v_34_1 << 1) ^ (pub_r001235_10_1 >> 1)) & 127;
  int stage_v_57_2 = ((stage_v_34_2 << 1) ^ (pub_r001235_10_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_57_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_57_2 + 1) & 15;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = ((stage_v_40_1 << 1) ^ (pub_r001235_2_1 >> 1)) & 127;
  int stage_v_58_2 = ((stage_v_40_2 << 1) ^ (pub_r001235_2_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_58_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_58_2 + 1) & 15;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = ((pub_r001235_18_1 * 2) + 17) & 63;
  int stage_v_59_2 = ((pub_r001235_18_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((stage_v_4_1 << 1) ^ (pub_r001235_18_1 >> 1)) & 127;
  int stage_v_60_2 = ((stage_v_4_2 << 1) ^ (pub_r001235_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_60_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_60_2 + 1) & 15;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = ((stage_v_40_1 << 1) ^ (pub_r001235_20_1 >> 1)) & 127;
  int stage_v_61_2 = ((stage_v_40_2 << 1) ^ (pub_r001235_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_61_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_61_2 + 1) & 15;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = ((helper_flow_2_1 << 1) ^ (pub_r001235_22_1 >> 1)) & 127;
  int stage_v_62_2 = ((helper_flow_2_2 << 1) ^ (pub_r001235_22_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_62_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_62_2 + 1) & 15;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = ((pub_r001235_11_1 * 2) + 28) & 63;
  int stage_v_63_2 = ((pub_r001235_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001235_14_1 * 2) + 29) & 63;
  int stage_v_64_2 = ((pub_r001235_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001235_17_1 * 2) + 16) & 63;
  int stage_v_65_2 = ((pub_r001235_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((stage_v_14_1 << 1) ^ (pub_r001235_4_1 >> 1)) & 127;
  int stage_v_66_2 = ((stage_v_14_2 << 1) ^ (pub_r001235_4_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_66_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_66_2 + 1) & 15;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = ((stage_v_49_1 << 1) ^ (pub_r001235_8_1 >> 1)) & 127;
  int stage_v_67_2 = ((stage_v_49_2 << 1) ^ (pub_r001235_8_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_67_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_67_2 + 1) & 15;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = ((sec_r001235_14_1 << 1) ^ (pub_r001235_12_1 >> 1)) & 127;
  int stage_v_68_2 = ((sec_r001235_14_2 << 1) ^ (pub_r001235_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_68_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_68_2 + 1) & 15;
  out_sink_1 ^= stage_v_68_1 & 63;
  out_sink_2 ^= stage_v_68_2 & 63;
  int stage_v_69_1 = ((helper_flow_4_1 << 1) ^ (pub_r001235_18_1 >> 1)) & 127;
  int stage_v_69_2 = ((helper_flow_4_2 << 1) ^ (pub_r001235_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_69_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_69_2 + 1) & 15;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = ((sec_r001235_7_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_70_2 = ((sec_r001235_7_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_70_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_70_2 + 1) & 15;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = ((pub_r001235_16_1 * 2) + 10) & 63;
  int stage_v_71_2 = ((pub_r001235_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((helper_flow_8_1 << 1) ^ (pub_r001235_9_1 >> 1)) & 127;
  int stage_v_72_2 = ((helper_flow_8_2 << 1) ^ (pub_r001235_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_72_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_72_2 + 1) & 15;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = ((stage_v_15_1 << 1) ^ (pub_r001235_18_1 >> 1)) & 127;
  int stage_v_73_2 = ((stage_v_15_2 << 1) ^ (pub_r001235_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_73_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_73_2 + 1) & 15;
  out_sink_1 ^= stage_v_73_1 & 63;
  out_sink_2 ^= stage_v_73_2 & 63;
  int stage_v_74_1 = ((helper_flow_2_1 << 1) ^ (pub_r001235_8_1 >> 1)) & 127;
  int stage_v_74_2 = ((helper_flow_2_2 << 1) ^ (pub_r001235_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_74_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_74_2 + 1) & 15;
  out_sink_1 ^= stage_v_74_1 & 63;
  out_sink_2 ^= stage_v_74_2 & 63;
  int stage_v_75_1 = ((sec_r001235_13_1 << 1) ^ (pub_r001235_0_1 >> 1)) & 127;
  int stage_v_75_2 = ((sec_r001235_13_2 << 1) ^ (pub_r001235_0_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_75_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_75_2 + 1) & 15;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = ((pub_r001235_16_1 * 2) + 26) & 63;
  int stage_v_76_2 = ((pub_r001235_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001235_7_1 * 2) + 41) & 63;
  int stage_v_77_2 = ((pub_r001235_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((sec_r001235_15_1 << 1) ^ (pub_r001235_20_1 >> 1)) & 127;
  int stage_v_78_2 = ((sec_r001235_15_2 << 1) ^ (pub_r001235_20_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_78_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_78_2 + 1) & 15;
  out_sink_1 ^= stage_v_78_1 & 63;
  out_sink_2 ^= stage_v_78_2 & 63;
  int stage_v_79_1 = ((helper_flow_3_1 << 1) ^ (pub_r001235_23_1 >> 1)) & 127;
  int stage_v_79_2 = ((helper_flow_3_2 << 1) ^ (pub_r001235_23_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_79_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_79_2 + 1) & 15;
  out_sink_1 ^= stage_v_79_1 & 63;
  out_sink_2 ^= stage_v_79_2 & 63;
  int stage_v_80_1 = ((stage_v_9_1 << 1) ^ (pub_r001235_20_1 >> 1)) & 127;
  int stage_v_80_2 = ((stage_v_9_2 << 1) ^ (pub_r001235_20_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_80_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_80_2 + 1) & 15;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = ((pub_r001235_10_1 * 2) + 35) & 63;
  int stage_v_81_2 = ((pub_r001235_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((stage_v_62_1 << 1) ^ (pub_r001235_5_1 >> 1)) & 127;
  int stage_v_82_2 = ((stage_v_62_2 << 1) ^ (pub_r001235_5_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_82_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_82_2 + 1) & 15;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = ((sec_r001235_12_1 << 1) ^ (pub_r001235_9_1 >> 1)) & 127;
  int stage_v_83_2 = ((sec_r001235_12_2 << 1) ^ (pub_r001235_9_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_83_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_83_2 + 1) & 15;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = ((stage_v_42_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_84_2 = ((stage_v_42_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_84_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_84_2 + 1) & 15;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = ((pub_r001235_12_1 * 2) + 8) & 63;
  int stage_v_85_2 = ((pub_r001235_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((stage_v_29_1 << 1) ^ (pub_r001235_0_1 >> 1)) & 127;
  int stage_v_86_2 = ((stage_v_29_2 << 1) ^ (pub_r001235_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_86_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_86_2 + 1) & 15;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = ((stage_v_4_1 << 1) ^ (pub_r001235_21_1 >> 1)) & 127;
  int stage_v_87_2 = ((stage_v_4_2 << 1) ^ (pub_r001235_21_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_87_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_87_2 + 1) & 15;
  out_sink_1 ^= stage_v_87_1 & 63;
  out_sink_2 ^= stage_v_87_2 & 63;
  int stage_v_88_1 = ((pub_r001235_11_1 * 2) + 26) & 63;
  int stage_v_88_2 = ((pub_r001235_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((stage_v_39_1 << 1) ^ (pub_r001235_7_1 >> 1)) & 127;
  int stage_v_89_2 = ((stage_v_39_2 << 1) ^ (pub_r001235_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_89_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_89_2 + 1) & 15;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = ((pub_r001235_5_1 * 2) + 47) & 63;
  int stage_v_90_2 = ((pub_r001235_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001235_3_1 * 2) + 17) & 63;
  int stage_v_91_2 = ((pub_r001235_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((stage_v_55_1 << 1) ^ (pub_r001235_8_1 >> 1)) & 127;
  int stage_v_92_2 = ((stage_v_55_2 << 1) ^ (pub_r001235_8_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_92_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_92_2 + 1) & 15;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = ((pub_r001235_7_1 * 2) + 26) & 63;
  int stage_v_93_2 = ((pub_r001235_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((helper_flow_1_1 << 1) ^ (pub_r001235_1_1 >> 1)) & 127;
  int stage_v_94_2 = ((helper_flow_1_2 << 1) ^ (pub_r001235_1_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_94_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_94_2 + 1) & 15;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = ((sec_r001235_10_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_95_2 = ((sec_r001235_10_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_95_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_95_2 + 1) & 15;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = ((stage_v_58_1 << 1) ^ (pub_r001235_11_1 >> 1)) & 127;
  int stage_v_96_2 = ((stage_v_58_2 << 1) ^ (pub_r001235_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_96_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_96_2 + 1) & 15;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = ((pub_r001235_4_1 * 2) + 42) & 63;
  int stage_v_97_2 = ((pub_r001235_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((stage_v_58_1 << 1) ^ (pub_r001235_1_1 >> 1)) & 127;
  int stage_v_98_2 = ((stage_v_58_2 << 1) ^ (pub_r001235_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_98_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_98_2 + 1) & 15;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = ((sec_r001235_13_1 << 1) ^ (pub_r001235_12_1 >> 1)) & 127;
  int stage_v_99_2 = ((sec_r001235_13_2 << 1) ^ (pub_r001235_12_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_99_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_99_2 + 1) & 15;
  out_sink_1 ^= stage_v_99_1 & 63;
  out_sink_2 ^= stage_v_99_2 & 63;
  int stage_v_100_1 = ((pub_r001235_6_1 * 2) + 6) & 63;
  int stage_v_100_2 = ((pub_r001235_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001235_9_1 * 2) + 43) & 63;
  int stage_v_101_2 = ((pub_r001235_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((stage_v_44_1 << 1) ^ (pub_r001235_21_1 >> 1)) & 127;
  int stage_v_102_2 = ((stage_v_44_2 << 1) ^ (pub_r001235_21_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_102_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_102_2 + 1) & 15;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = ((pub_r001235_12_1 * 2) + 42) & 63;
  int stage_v_103_2 = ((pub_r001235_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((stage_v_60_1 << 1) ^ (pub_r001235_20_1 >> 1)) & 127;
  int stage_v_104_2 = ((stage_v_60_2 << 1) ^ (pub_r001235_20_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_104_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_104_2 + 1) & 15;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = ((stage_v_87_1 << 1) ^ (pub_r001235_3_1 >> 1)) & 127;
  int stage_v_105_2 = ((stage_v_87_2 << 1) ^ (pub_r001235_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_105_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_105_2 + 1) & 15;
  out_sink_1 ^= stage_v_105_1 & 63;
  out_sink_2 ^= stage_v_105_2 & 63;
  int stage_v_106_1 = ((pub_r001235_11_1 * 2) + 33) & 63;
  int stage_v_106_2 = ((pub_r001235_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001235_15_1 * 2) + 12) & 63;
  int stage_v_107_2 = ((pub_r001235_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001235_5_1 * 2) + 14) & 63;
  int stage_v_108_2 = ((pub_r001235_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_60_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_109_2 = ((stage_v_60_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_109_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_109_2 + 1) & 15;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = ((pub_r001235_21_1 * 2) + 43) & 63;
  int stage_v_110_2 = ((pub_r001235_21_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001235_8_1 * 2) + 36) & 63;
  int stage_v_111_2 = ((pub_r001235_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((sec_r001235_6_1 << 1) ^ (pub_r001235_18_1 >> 1)) & 127;
  int stage_v_112_2 = ((sec_r001235_6_2 << 1) ^ (pub_r001235_18_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_112_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_112_2 + 1) & 15;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = ((stage_v_62_1 << 1) ^ (pub_r001235_12_1 >> 1)) & 127;
  int stage_v_113_2 = ((stage_v_62_2 << 1) ^ (pub_r001235_12_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_113_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_113_2 + 1) & 15;
  out_sink_1 ^= stage_v_113_1 & 63;
  out_sink_2 ^= stage_v_113_2 & 63;
  int stage_v_114_1 = ((pub_r001235_6_1 * 2) + 49) & 63;
  int stage_v_114_2 = ((pub_r001235_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001235_8_1 * 2) + 24) & 63;
  int stage_v_115_2 = ((pub_r001235_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001235_17_1 * 2) + 29) & 63;
  int stage_v_116_2 = ((pub_r001235_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((sec_r001235_0_1 << 1) ^ (pub_r001235_21_1 >> 1)) & 127;
  int stage_v_117_2 = ((sec_r001235_0_2 << 1) ^ (pub_r001235_21_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_117_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_117_2 + 1) & 15;
  out_sink_1 ^= stage_v_117_1 & 63;
  out_sink_2 ^= stage_v_117_2 & 63;
  int stage_v_118_1 = ((stage_v_66_1 << 1) ^ (pub_r001235_6_1 >> 1)) & 127;
  int stage_v_118_2 = ((stage_v_66_2 << 1) ^ (pub_r001235_6_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_118_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_118_2 + 1) & 15;
  out_sink_1 ^= stage_v_118_1 & 63;
  out_sink_2 ^= stage_v_118_2 & 63;
  int stage_v_119_1 = ((helper_flow_8_1 << 1) ^ (pub_r001235_11_1 >> 1)) & 127;
  int stage_v_119_2 = ((helper_flow_8_2 << 1) ^ (pub_r001235_11_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_119_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_119_2 + 1) & 15;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = ((stage_v_66_1 << 1) ^ (pub_r001235_13_1 >> 1)) & 127;
  int stage_v_120_2 = ((stage_v_66_2 << 1) ^ (pub_r001235_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_120_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_120_2 + 1) & 15;
  out_sink_1 ^= stage_v_120_1 & 63;
  out_sink_2 ^= stage_v_120_2 & 63;
  int stage_v_121_1 = ((pub_r001235_12_1 * 2) + 46) & 63;
  int stage_v_121_2 = ((pub_r001235_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001235_8_1 * 2) + 27) & 63;
  int stage_v_122_2 = ((pub_r001235_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001235_21_1 * 2) + 19) & 63;
  int stage_v_123_2 = ((pub_r001235_21_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((stage_v_15_1 << 1) ^ (pub_r001235_3_1 >> 1)) & 127;
  int stage_v_124_2 = ((stage_v_15_2 << 1) ^ (pub_r001235_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_124_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_124_2 + 1) & 15;
  out_sink_1 ^= stage_v_124_1 & 63;
  out_sink_2 ^= stage_v_124_2 & 63;
  int stage_v_125_1 = ((stage_v_104_1 << 1) ^ (pub_r001235_7_1 >> 1)) & 127;
  int stage_v_125_2 = ((stage_v_104_2 << 1) ^ (pub_r001235_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_125_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_125_2 + 1) & 15;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = ((stage_v_38_1 << 1) ^ (pub_r001235_7_1 >> 1)) & 127;
  int stage_v_126_2 = ((stage_v_38_2 << 1) ^ (pub_r001235_7_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_126_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_126_2 + 1) & 15;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = ((pub_r001235_20_1 * 2) + 40) & 63;
  int stage_v_127_2 = ((pub_r001235_20_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((stage_v_44_1 << 1) ^ (pub_r001235_1_1 >> 1)) & 127;
  int stage_v_128_2 = ((stage_v_44_2 << 1) ^ (pub_r001235_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_128_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_128_2 + 1) & 15;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = ((stage_v_9_1 << 1) ^ (pub_r001235_8_1 >> 1)) & 127;
  int stage_v_129_2 = ((stage_v_9_2 << 1) ^ (pub_r001235_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_129_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_129_2 + 1) & 15;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = ((sec_r001235_6_1 << 1) ^ (pub_r001235_9_1 >> 1)) & 127;
  int stage_v_130_2 = ((sec_r001235_6_2 << 1) ^ (pub_r001235_9_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_130_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_130_2 + 1) & 15;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = ((pub_r001235_9_1 * 2) + 21) & 63;
  int stage_v_131_2 = ((pub_r001235_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((stage_v_118_1 << 1) ^ (pub_r001235_21_1 >> 1)) & 127;
  int stage_v_132_2 = ((stage_v_118_2 << 1) ^ (pub_r001235_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_132_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_132_2 + 1) & 15;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = ((stage_v_25_1 << 1) ^ (pub_r001235_13_1 >> 1)) & 127;
  int stage_v_133_2 = ((stage_v_25_2 << 1) ^ (pub_r001235_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_133_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_133_2 + 1) & 15;
  out_sink_1 ^= stage_v_133_1 & 63;
  out_sink_2 ^= stage_v_133_2 & 63;
  int stage_v_134_1 = ((pub_r001235_18_1 * 2) + 43) & 63;
  int stage_v_134_2 = ((pub_r001235_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((helper_flow_4_1 << 1) ^ (pub_r001235_2_1 >> 1)) & 127;
  int stage_v_135_2 = ((helper_flow_4_2 << 1) ^ (pub_r001235_2_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_135_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_135_2 + 1) & 15;
  out_sink_1 ^= stage_v_135_1 & 63;
  out_sink_2 ^= stage_v_135_2 & 63;
  int stage_v_136_1 = ((pub_r001235_8_1 * 2) + 13) & 63;
  int stage_v_136_2 = ((pub_r001235_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((stage_v_39_1 << 1) ^ (pub_r001235_4_1 >> 1)) & 127;
  int stage_v_137_2 = ((stage_v_39_2 << 1) ^ (pub_r001235_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_137_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_137_2 + 1) & 15;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = ((stage_v_60_1 << 1) ^ (pub_r001235_8_1 >> 1)) & 127;
  int stage_v_138_2 = ((stage_v_60_2 << 1) ^ (pub_r001235_8_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_138_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_138_2 + 1) & 15;
  out_sink_1 ^= stage_v_138_1 & 63;
  out_sink_2 ^= stage_v_138_2 & 63;
  int stage_v_139_1 = ((pub_r001235_9_1 * 2) + 27) & 63;
  int stage_v_139_2 = ((pub_r001235_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001235_7_1 * 2) + 35) & 63;
  int stage_v_140_2 = ((pub_r001235_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001235_1_1 * 2) + 44) & 63;
  int stage_v_141_2 = ((pub_r001235_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((stage_v_57_1 << 1) ^ (pub_r001235_16_1 >> 1)) & 127;
  int stage_v_142_2 = ((stage_v_57_2 << 1) ^ (pub_r001235_16_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_142_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_142_2 + 1) & 15;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = ((stage_v_42_1 << 1) ^ (pub_r001235_6_1 >> 1)) & 127;
  int stage_v_143_2 = ((stage_v_42_2 << 1) ^ (pub_r001235_6_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_143_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_143_2 + 1) & 15;
  out_sink_1 ^= stage_v_143_1 & 63;
  out_sink_2 ^= stage_v_143_2 & 63;
  int stage_v_144_1 = ((helper_flow_3_1 << 1) ^ (pub_r001235_1_1 >> 1)) & 127;
  int stage_v_144_2 = ((helper_flow_3_2 << 1) ^ (pub_r001235_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_144_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_144_2 + 1) & 15;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = ((stage_v_82_1 << 1) ^ (pub_r001235_13_1 >> 1)) & 127;
  int stage_v_145_2 = ((stage_v_82_2 << 1) ^ (pub_r001235_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_145_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_145_2 + 1) & 15;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = ((stage_v_79_1 << 1) ^ (pub_r001235_9_1 >> 1)) & 127;
  int stage_v_146_2 = ((stage_v_79_2 << 1) ^ (pub_r001235_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_146_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_146_2 + 1) & 15;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = ((stage_v_40_1 << 1) ^ (pub_r001235_20_1 >> 1)) & 127;
  int stage_v_147_2 = ((stage_v_40_2 << 1) ^ (pub_r001235_20_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_147_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_147_2 + 1) & 15;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = ((pub_r001235_10_1 * 2) + 6) & 63;
  int stage_v_148_2 = ((pub_r001235_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001235_11_1 * 2) + 21) & 63;
  int stage_v_149_2 = ((pub_r001235_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((stage_v_38_1 << 1) ^ (pub_r001235_23_1 >> 1)) & 127;
  int stage_v_150_2 = ((stage_v_38_2 << 1) ^ (pub_r001235_23_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_150_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_150_2 + 1) & 15;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = ((sec_r001235_16_1 << 1) ^ (pub_r001235_23_1 >> 1)) & 127;
  int stage_v_151_2 = ((sec_r001235_16_2 << 1) ^ (pub_r001235_23_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_151_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_151_2 + 1) & 15;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = ((stage_v_118_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_152_2 = ((stage_v_118_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_152_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_152_2 + 1) & 15;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = ((pub_r001235_8_1 * 2) + 45) & 63;
  int stage_v_153_2 = ((pub_r001235_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001235_7_1 * 2) + 6) & 63;
  int stage_v_154_2 = ((pub_r001235_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001235_5_1 * 2) + 19) & 63;
  int stage_v_155_2 = ((pub_r001235_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((stage_v_53_1 << 1) ^ (pub_r001235_3_1 >> 1)) & 127;
  int stage_v_156_2 = ((stage_v_53_2 << 1) ^ (pub_r001235_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_156_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_156_2 + 1) & 15;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = ((stage_v_151_1 << 1) ^ (pub_r001235_15_1 >> 1)) & 127;
  int stage_v_157_2 = ((stage_v_151_2 << 1) ^ (pub_r001235_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_157_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_157_2 + 1) & 15;
  out_sink_1 ^= stage_v_157_1 & 63;
  out_sink_2 ^= stage_v_157_2 & 63;
  int stage_v_158_1 = ((sec_r001235_11_1 << 1) ^ (pub_r001235_4_1 >> 1)) & 127;
  int stage_v_158_2 = ((sec_r001235_11_2 << 1) ^ (pub_r001235_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_158_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_158_2 + 1) & 15;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = ((stage_v_147_1 << 1) ^ (pub_r001235_4_1 >> 1)) & 127;
  int stage_v_159_2 = ((stage_v_147_2 << 1) ^ (pub_r001235_4_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_159_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_159_2 + 1) & 15;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = ((stage_v_60_1 << 1) ^ (pub_r001235_2_1 >> 1)) & 127;
  int stage_v_160_2 = ((stage_v_60_2 << 1) ^ (pub_r001235_2_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_160_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_160_2 + 1) & 15;
  out_sink_1 ^= stage_v_160_1 & 63;
  out_sink_2 ^= stage_v_160_2 & 63;
  int stage_v_161_1 = ((pub_r001235_0_1 * 2) + 11) & 63;
  int stage_v_161_2 = ((pub_r001235_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((stage_v_146_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_162_2 = ((stage_v_146_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_162_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_162_2 + 1) & 15;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = ((pub_r001235_9_1 * 2) + 6) & 63;
  int stage_v_163_2 = ((pub_r001235_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((sec_r001235_12_1 << 1) ^ (pub_r001235_12_1 >> 1)) & 127;
  int stage_v_164_2 = ((sec_r001235_12_2 << 1) ^ (pub_r001235_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_164_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_164_2 + 1) & 15;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = ((stage_v_57_1 << 1) ^ (pub_r001235_4_1 >> 1)) & 127;
  int stage_v_165_2 = ((stage_v_57_2 << 1) ^ (pub_r001235_4_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_165_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_165_2 + 1) & 15;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = ((pub_r001235_10_1 * 2) + 46) & 63;
  int stage_v_166_2 = ((pub_r001235_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001235_15_1 * 2) + 6) & 63;
  int stage_v_167_2 = ((pub_r001235_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((stage_v_98_1 << 1) ^ (pub_r001235_0_1 >> 1)) & 127;
  int stage_v_168_2 = ((stage_v_98_2 << 1) ^ (pub_r001235_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_168_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_168_2 + 1) & 15;
  out_sink_1 ^= stage_v_168_1 & 63;
  out_sink_2 ^= stage_v_168_2 & 63;
  int stage_v_169_1 = ((pub_r001235_13_1 * 2) + 27) & 63;
  int stage_v_169_2 = ((pub_r001235_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((stage_v_126_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_170_2 = ((stage_v_126_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_170_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_170_2 + 1) & 15;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = ((helper_flow_8_1 << 1) ^ (pub_r001235_7_1 >> 1)) & 127;
  int stage_v_171_2 = ((helper_flow_8_2 << 1) ^ (pub_r001235_7_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_171_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_171_2 + 1) & 15;
  out_sink_1 ^= stage_v_171_1 & 63;
  out_sink_2 ^= stage_v_171_2 & 63;
  int stage_v_172_1 = ((pub_r001235_0_1 * 2) + 7) & 63;
  int stage_v_172_2 = ((pub_r001235_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001235_14_1 * 2) + 26) & 63;
  int stage_v_173_2 = ((pub_r001235_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((helper_flow_4_1 << 1) ^ (pub_r001235_21_1 >> 1)) & 127;
  int stage_v_174_2 = ((helper_flow_4_2 << 1) ^ (pub_r001235_21_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_174_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_174_2 + 1) & 15;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = ((stage_v_43_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_175_2 = ((stage_v_43_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_175_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_175_2 + 1) & 15;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = ((stage_v_133_1 << 1) ^ (pub_r001235_21_1 >> 1)) & 127;
  int stage_v_176_2 = ((stage_v_133_2 << 1) ^ (pub_r001235_21_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_176_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_176_2 + 1) & 15;
  out_sink_1 ^= stage_v_176_1 & 63;
  out_sink_2 ^= stage_v_176_2 & 63;
  int stage_v_177_1 = ((pub_r001235_23_1 * 2) + 9) & 63;
  int stage_v_177_2 = ((pub_r001235_23_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001235_20_1 * 2) + 13) & 63;
  int stage_v_178_2 = ((pub_r001235_20_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((sec_r001235_15_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_179_2 = ((sec_r001235_15_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_179_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_179_2 + 1) & 15;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = ((pub_r001235_6_1 * 2) + 17) & 63;
  int stage_v_180_2 = ((pub_r001235_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((stage_v_69_1 << 1) ^ (pub_r001235_13_1 >> 1)) & 127;
  int stage_v_181_2 = ((stage_v_69_2 << 1) ^ (pub_r001235_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_181_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_181_2 + 1) & 15;
  out_sink_1 ^= stage_v_181_1 & 63;
  out_sink_2 ^= stage_v_181_2 & 63;
  int stage_v_182_1 = ((pub_r001235_8_1 * 2) + 35) & 63;
  int stage_v_182_2 = ((pub_r001235_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((stage_v_47_1 << 1) ^ (pub_r001235_4_1 >> 1)) & 127;
  int stage_v_183_2 = ((stage_v_47_2 << 1) ^ (pub_r001235_4_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_183_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_183_2 + 1) & 15;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = ((pub_r001235_15_1 * 2) + 42) & 63;
  int stage_v_184_2 = ((pub_r001235_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((stage_v_67_1 << 1) ^ (pub_r001235_16_1 >> 1)) & 127;
  int stage_v_185_2 = ((stage_v_67_2 << 1) ^ (pub_r001235_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_185_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_185_2 + 1) & 15;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = ((pub_r001235_17_1 * 2) + 43) & 63;
  int stage_v_186_2 = ((pub_r001235_17_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((stage_v_4_1 << 1) ^ (pub_r001235_18_1 >> 1)) & 127;
  int stage_v_187_2 = ((stage_v_4_2 << 1) ^ (pub_r001235_18_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_187_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_187_2 + 1) & 15;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = ((pub_r001235_17_1 * 2) + 27) & 63;
  int stage_v_188_2 = ((pub_r001235_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((stage_v_6_1 << 1) ^ (pub_r001235_1_1 >> 1)) & 127;
  int stage_v_189_2 = ((stage_v_6_2 << 1) ^ (pub_r001235_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_189_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_189_2 + 1) & 15;
  out_sink_1 ^= stage_v_189_1 & 63;
  out_sink_2 ^= stage_v_189_2 & 63;
  int stage_v_190_1 = ((stage_v_179_1 << 1) ^ (pub_r001235_9_1 >> 1)) & 127;
  int stage_v_190_2 = ((stage_v_179_2 << 1) ^ (pub_r001235_9_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_190_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_190_2 + 1) & 15;
  out_sink_1 ^= stage_v_190_1 & 63;
  out_sink_2 ^= stage_v_190_2 & 63;
  int stage_v_191_1 = ((stage_v_14_1 << 1) ^ (pub_r001235_2_1 >> 1)) & 127;
  int stage_v_191_2 = ((stage_v_14_2 << 1) ^ (pub_r001235_2_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_191_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_191_2 + 1) & 15;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = ((pub_r001235_3_1 * 2) + 31) & 63;
  int stage_v_192_2 = ((pub_r001235_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((stage_v_46_1 << 1) ^ (pub_r001235_15_1 >> 1)) & 127;
  int stage_v_193_2 = ((stage_v_46_2 << 1) ^ (pub_r001235_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_193_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_193_2 + 1) & 15;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = ((sec_r001235_0_1 << 1) ^ (pub_r001235_3_1 >> 1)) & 127;
  int stage_v_194_2 = ((sec_r001235_0_2 << 1) ^ (pub_r001235_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_194_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_194_2 + 1) & 15;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = ((pub_r001235_8_1 * 2) + 39) & 63;
  int stage_v_195_2 = ((pub_r001235_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((stage_v_112_1 << 1) ^ (pub_r001235_1_1 >> 1)) & 127;
  int stage_v_196_2 = ((stage_v_112_2 << 1) ^ (pub_r001235_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_196_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_196_2 + 1) & 15;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = ((pub_r001235_23_1 * 2) + 13) & 63;
  int stage_v_197_2 = ((pub_r001235_23_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((stage_v_87_1 << 1) ^ (pub_r001235_10_1 >> 1)) & 127;
  int stage_v_198_2 = ((stage_v_87_2 << 1) ^ (pub_r001235_10_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_198_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_198_2 + 1) & 15;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = ((stage_v_138_1 << 1) ^ (pub_r001235_14_1 >> 1)) & 127;
  int stage_v_199_2 = ((stage_v_138_2 << 1) ^ (pub_r001235_14_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_199_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_199_2 + 1) & 15;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = ((pub_r001235_6_1 * 2) + 21) & 63;
  int stage_v_200_2 = ((pub_r001235_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001235_1_1 * 2) + 14) & 63;
  int stage_v_201_2 = ((pub_r001235_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((stage_v_8_1 << 1) ^ (pub_r001235_11_1 >> 1)) & 127;
  int stage_v_202_2 = ((stage_v_8_2 << 1) ^ (pub_r001235_11_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_202_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_202_2 + 1) & 15;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = ((stage_v_67_1 << 1) ^ (pub_r001235_2_1 >> 1)) & 127;
  int stage_v_203_2 = ((stage_v_67_2 << 1) ^ (pub_r001235_2_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_203_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_203_2 + 1) & 15;
  out_sink_1 ^= stage_v_203_1 & 63;
  out_sink_2 ^= stage_v_203_2 & 63;
  int stage_v_204_1 = ((stage_v_87_1 << 1) ^ (pub_r001235_21_1 >> 1)) & 127;
  int stage_v_204_2 = ((stage_v_87_2 << 1) ^ (pub_r001235_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_204_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_204_2 + 1) & 15;
  out_sink_1 ^= stage_v_204_1 & 63;
  out_sink_2 ^= stage_v_204_2 & 63;
  int stage_v_205_1 = ((pub_r001235_18_1 * 2) + 36) & 63;
  int stage_v_205_2 = ((pub_r001235_18_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((sec_r001235_15_1 << 1) ^ (pub_r001235_8_1 >> 1)) & 127;
  int stage_v_206_2 = ((sec_r001235_15_2 << 1) ^ (pub_r001235_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_206_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_206_2 + 1) & 15;
  out_sink_1 ^= stage_v_206_1 & 63;
  out_sink_2 ^= stage_v_206_2 & 63;
  int stage_v_207_1 = ((pub_r001235_22_1 * 2) + 34) & 63;
  int stage_v_207_2 = ((pub_r001235_22_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001235_20_1 * 2) + 41) & 63;
  int stage_v_208_2 = ((pub_r001235_20_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((sec_r001235_15_1 << 1) ^ (pub_r001235_11_1 >> 1)) & 127;
  int stage_v_209_2 = ((sec_r001235_15_2 << 1) ^ (pub_r001235_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_209_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_209_2 + 1) & 15;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = ((pub_r001235_2_1 * 2) + 43) & 63;
  int stage_v_210_2 = ((pub_r001235_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001235_21_1 * 2) + 19) & 63;
  int stage_v_211_2 = ((pub_r001235_21_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((stage_v_174_1 << 1) ^ (pub_r001235_5_1 >> 1)) & 127;
  int stage_v_212_2 = ((stage_v_174_2 << 1) ^ (pub_r001235_5_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_212_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_212_2 + 1) & 15;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = ((sec_r001235_4_1 << 1) ^ (pub_r001235_15_1 >> 1)) & 127;
  int stage_v_213_2 = ((sec_r001235_4_2 << 1) ^ (pub_r001235_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_213_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_213_2 + 1) & 15;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = ((pub_r001235_13_1 * 2) + 7) & 63;
  int stage_v_214_2 = ((pub_r001235_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001235_22_1 * 2) + 11) & 63;
  int stage_v_215_2 = ((pub_r001235_22_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((stage_v_9_1 << 1) ^ (pub_r001235_0_1 >> 1)) & 127;
  int stage_v_216_2 = ((stage_v_9_2 << 1) ^ (pub_r001235_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_216_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_216_2 + 1) & 15;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = ((pub_r001235_22_1 * 2) + 8) & 63;
  int stage_v_217_2 = ((pub_r001235_22_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001235_11_1 * 2) + 34) & 63;
  int stage_v_218_2 = ((pub_r001235_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((stage_v_50_1 << 1) ^ (pub_r001235_11_1 >> 1)) & 127;
  int stage_v_219_2 = ((stage_v_50_2 << 1) ^ (pub_r001235_11_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_219_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_219_2 + 1) & 15;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = ((stage_v_190_1 << 1) ^ (pub_r001235_13_1 >> 1)) & 127;
  int stage_v_220_2 = ((stage_v_190_2 << 1) ^ (pub_r001235_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_220_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_220_2 + 1) & 15;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = ((stage_v_176_1 << 1) ^ (pub_r001235_7_1 >> 1)) & 127;
  int stage_v_221_2 = ((stage_v_176_2 << 1) ^ (pub_r001235_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_221_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_221_2 + 1) & 15;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = ((stage_v_125_1 << 1) ^ (pub_r001235_16_1 >> 1)) & 127;
  int stage_v_222_2 = ((stage_v_125_2 << 1) ^ (pub_r001235_16_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_222_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_222_2 + 1) & 15;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = ((pub_r001235_22_1 * 2) + 40) & 63;
  int stage_v_223_2 = ((pub_r001235_22_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((stage_v_132_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_224_2 = ((stage_v_132_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_224_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_224_2 + 1) & 15;
  out_sink_1 ^= stage_v_224_1 & 63;
  out_sink_2 ^= stage_v_224_2 & 63;
  int stage_v_225_1 = ((sec_r001235_6_1 << 1) ^ (pub_r001235_2_1 >> 1)) & 127;
  int stage_v_225_2 = ((sec_r001235_6_2 << 1) ^ (pub_r001235_2_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_225_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_225_2 + 1) & 15;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = ((pub_r001235_11_1 * 2) + 5) & 63;
  int stage_v_226_2 = ((pub_r001235_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((stage_v_157_1 << 1) ^ (pub_r001235_1_1 >> 1)) & 127;
  int stage_v_227_2 = ((stage_v_157_2 << 1) ^ (pub_r001235_1_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_227_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_227_2 + 1) & 15;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = ((pub_r001235_12_1 * 2) + 48) & 63;
  int stage_v_228_2 = ((pub_r001235_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001235_11_1 * 2) + 50) & 63;
  int stage_v_229_2 = ((pub_r001235_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001235_2_1 * 2) + 37) & 63;
  int stage_v_230_2 = ((pub_r001235_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001235_11_1 * 2) + 38) & 63;
  int stage_v_231_2 = ((pub_r001235_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((sec_r001235_1_1 << 1) ^ (pub_r001235_4_1 >> 1)) & 127;
  int stage_v_232_2 = ((sec_r001235_1_2 << 1) ^ (pub_r001235_4_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_232_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_232_2 + 1) & 15;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = ((helper_flow_0_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_233_2 = ((helper_flow_0_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_233_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_233_2 + 1) & 15;
  out_sink_1 ^= stage_v_233_1 & 63;
  out_sink_2 ^= stage_v_233_2 & 63;
  int stage_v_234_1 = ((stage_v_53_1 << 1) ^ (pub_r001235_10_1 >> 1)) & 127;
  int stage_v_234_2 = ((stage_v_53_2 << 1) ^ (pub_r001235_10_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_234_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_234_2 + 1) & 15;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = ((pub_r001235_11_1 * 2) + 44) & 63;
  int stage_v_235_2 = ((pub_r001235_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001235_0_1 * 2) + 24) & 63;
  int stage_v_236_2 = ((pub_r001235_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001235_23_1 * 2) + 11) & 63;
  int stage_v_237_2 = ((pub_r001235_23_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001235_1_1 * 2) + 34) & 63;
  int stage_v_238_2 = ((pub_r001235_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001235_13_1 * 2) + 46) & 63;
  int stage_v_239_2 = ((pub_r001235_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001235_8_1 * 2) + 19) & 63;
  int stage_v_240_2 = ((pub_r001235_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((stage_v_112_1 << 1) ^ (pub_r001235_13_1 >> 1)) & 127;
  int stage_v_241_2 = ((stage_v_112_2 << 1) ^ (pub_r001235_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_241_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_241_2 + 1) & 15;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = ((pub_r001235_13_1 * 2) + 31) & 63;
  int stage_v_242_2 = ((pub_r001235_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((stage_v_78_1 << 1) ^ (pub_r001235_16_1 >> 1)) & 127;
  int stage_v_243_2 = ((stage_v_78_2 << 1) ^ (pub_r001235_16_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_243_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_243_2 + 1) & 15;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = ((pub_r001235_18_1 * 2) + 27) & 63;
  int stage_v_244_2 = ((pub_r001235_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001235_12_1 * 2) + 34) & 63;
  int stage_v_245_2 = ((pub_r001235_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((stage_v_206_1 << 1) ^ (pub_r001235_23_1 >> 1)) & 127;
  int stage_v_246_2 = ((stage_v_206_2 << 1) ^ (pub_r001235_23_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_246_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_246_2 + 1) & 15;
  out_sink_1 ^= stage_v_246_1 & 63;
  out_sink_2 ^= stage_v_246_2 & 63;
  int stage_v_247_1 = ((stage_v_10_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_247_2 = ((stage_v_10_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_247_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_247_2 + 1) & 15;
  out_sink_1 ^= stage_v_247_1 & 63;
  out_sink_2 ^= stage_v_247_2 & 63;
  int stage_v_248_1 = ((stage_v_206_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_248_2 = ((stage_v_206_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_248_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_248_2 + 1) & 15;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = ((stage_v_42_1 << 1) ^ (pub_r001235_8_1 >> 1)) & 127;
  int stage_v_249_2 = ((stage_v_42_2 << 1) ^ (pub_r001235_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_249_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_249_2 + 1) & 15;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = ((pub_r001235_6_1 * 2) + 33) & 63;
  int stage_v_250_2 = ((pub_r001235_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((stage_v_82_1 << 1) ^ (pub_r001235_6_1 >> 1)) & 127;
  int stage_v_251_2 = ((stage_v_82_2 << 1) ^ (pub_r001235_6_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_251_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_251_2 + 1) & 15;
  out_sink_1 ^= stage_v_251_1 & 63;
  out_sink_2 ^= stage_v_251_2 & 63;
  int stage_v_252_1 = ((stage_v_171_1 << 1) ^ (pub_r001235_3_1 >> 1)) & 127;
  int stage_v_252_2 = ((stage_v_171_2 << 1) ^ (pub_r001235_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_252_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_252_2 + 1) & 15;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = ((pub_r001235_3_1 * 2) + 46) & 63;
  int stage_v_253_2 = ((pub_r001235_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((stage_v_98_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_254_2 = ((stage_v_98_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_254_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_254_2 + 1) & 15;
  out_sink_1 ^= stage_v_254_1 & 63;
  out_sink_2 ^= stage_v_254_2 & 63;
  int stage_v_255_1 = ((pub_r001235_8_1 * 2) + 43) & 63;
  int stage_v_255_2 = ((pub_r001235_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001235_23_1 * 2) + 15) & 63;
  int stage_v_256_2 = ((pub_r001235_23_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001235_3_1 * 2) + 30) & 63;
  int stage_v_257_2 = ((pub_r001235_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001235_14_1 * 2) + 24) & 63;
  int stage_v_258_2 = ((pub_r001235_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((sec_r001235_16_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_259_2 = ((sec_r001235_16_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_259_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_259_2 + 1) & 15;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = ((stage_v_78_1 << 1) ^ (pub_r001235_13_1 >> 1)) & 127;
  int stage_v_260_2 = ((stage_v_78_2 << 1) ^ (pub_r001235_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_260_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_260_2 + 1) & 15;
  out_sink_1 ^= stage_v_260_1 & 63;
  out_sink_2 ^= stage_v_260_2 & 63;
  int stage_v_261_1 = ((pub_r001235_20_1 * 2) + 17) & 63;
  int stage_v_261_2 = ((pub_r001235_20_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001235_3_1 * 2) + 12) & 63;
  int stage_v_262_2 = ((pub_r001235_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((stage_v_135_1 << 1) ^ (pub_r001235_22_1 >> 1)) & 127;
  int stage_v_263_2 = ((stage_v_135_2 << 1) ^ (pub_r001235_22_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_263_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_263_2 + 1) & 15;
  out_sink_1 ^= stage_v_263_1 & 63;
  out_sink_2 ^= stage_v_263_2 & 63;
  int stage_v_264_1 = ((pub_r001235_3_1 * 2) + 6) & 63;
  int stage_v_264_2 = ((pub_r001235_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((stage_v_220_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_265_2 = ((stage_v_220_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_265_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_265_2 + 1) & 15;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = ((stage_v_194_1 << 1) ^ (pub_r001235_18_1 >> 1)) & 127;
  int stage_v_266_2 = ((stage_v_194_2 << 1) ^ (pub_r001235_18_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_266_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_266_2 + 1) & 15;
  out_sink_1 ^= stage_v_266_1 & 63;
  out_sink_2 ^= stage_v_266_2 & 63;
  int stage_v_267_1 = ((pub_r001235_22_1 * 2) + 43) & 63;
  int stage_v_267_2 = ((pub_r001235_22_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((stage_v_216_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_268_2 = ((stage_v_216_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_268_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_268_2 + 1) & 15;
  out_sink_1 ^= stage_v_268_1 & 63;
  out_sink_2 ^= stage_v_268_2 & 63;
  int stage_v_269_1 = ((stage_v_265_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_269_2 = ((stage_v_265_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_269_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_269_2 + 1) & 15;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = ((stage_v_109_1 << 1) ^ (pub_r001235_15_1 >> 1)) & 127;
  int stage_v_270_2 = ((stage_v_109_2 << 1) ^ (pub_r001235_15_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_270_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_270_2 + 1) & 15;
  out_sink_1 ^= stage_v_270_1 & 63;
  out_sink_2 ^= stage_v_270_2 & 63;
  int stage_v_271_1 = ((pub_r001235_13_1 * 2) + 11) & 63;
  int stage_v_271_2 = ((pub_r001235_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((stage_v_78_1 << 1) ^ (pub_r001235_23_1 >> 1)) & 127;
  int stage_v_272_2 = ((stage_v_78_2 << 1) ^ (pub_r001235_23_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_272_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_272_2 + 1) & 15;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = ((stage_v_67_1 << 1) ^ (pub_r001235_11_1 >> 1)) & 127;
  int stage_v_273_2 = ((stage_v_67_2 << 1) ^ (pub_r001235_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_273_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_273_2 + 1) & 15;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = ((stage_v_62_1 << 1) ^ (pub_r001235_9_1 >> 1)) & 127;
  int stage_v_274_2 = ((stage_v_62_2 << 1) ^ (pub_r001235_9_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_274_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_274_2 + 1) & 15;
  out_sink_1 ^= stage_v_274_1 & 63;
  out_sink_2 ^= stage_v_274_2 & 63;
  int stage_v_275_1 = ((stage_v_4_1 << 1) ^ (pub_r001235_16_1 >> 1)) & 127;
  int stage_v_275_2 = ((stage_v_4_2 << 1) ^ (pub_r001235_16_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_275_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_275_2 + 1) & 15;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = ((stage_v_213_1 << 1) ^ (pub_r001235_22_1 >> 1)) & 127;
  int stage_v_276_2 = ((stage_v_213_2 << 1) ^ (pub_r001235_22_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_276_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_276_2 + 1) & 15;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = ((stage_v_120_1 << 1) ^ (pub_r001235_9_1 >> 1)) & 127;
  int stage_v_277_2 = ((stage_v_120_2 << 1) ^ (pub_r001235_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_277_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_277_2 + 1) & 15;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = ((stage_v_213_1 << 1) ^ (pub_r001235_11_1 >> 1)) & 127;
  int stage_v_278_2 = ((stage_v_213_2 << 1) ^ (pub_r001235_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_278_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_278_2 + 1) & 15;
  out_sink_1 ^= stage_v_278_1 & 63;
  out_sink_2 ^= stage_v_278_2 & 63;
  int stage_v_279_1 = ((stage_v_109_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_279_2 = ((stage_v_109_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_279_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_279_2 + 1) & 15;
  out_sink_1 ^= stage_v_279_1 & 63;
  out_sink_2 ^= stage_v_279_2 & 63;
  int stage_v_280_1 = ((stage_v_60_1 << 1) ^ (pub_r001235_13_1 >> 1)) & 127;
  int stage_v_280_2 = ((stage_v_60_2 << 1) ^ (pub_r001235_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_280_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_280_2 + 1) & 15;
  out_sink_1 ^= stage_v_280_1 & 63;
  out_sink_2 ^= stage_v_280_2 & 63;
  int stage_v_281_1 = ((pub_r001235_12_1 * 2) + 15) & 63;
  int stage_v_281_2 = ((pub_r001235_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((pub_r001235_1_1 * 2) + 25) & 63;
  int stage_v_282_2 = ((pub_r001235_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001235_3_1 * 2) + 9) & 63;
  int stage_v_283_2 = ((pub_r001235_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001235_18_1 * 2) + 27) & 63;
  int stage_v_284_2 = ((pub_r001235_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001235_18_1 * 2) + 44) & 63;
  int stage_v_285_2 = ((pub_r001235_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((stage_v_196_1 << 1) ^ (pub_r001235_8_1 >> 1)) & 127;
  int stage_v_286_2 = ((stage_v_196_2 << 1) ^ (pub_r001235_8_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_286_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_286_2 + 1) & 15;
  out_sink_1 ^= stage_v_286_1 & 63;
  out_sink_2 ^= stage_v_286_2 & 63;
  int stage_v_287_1 = ((stage_v_98_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_287_2 = ((stage_v_98_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_287_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_287_2 + 1) & 15;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = ((pub_r001235_15_1 * 2) + 5) & 63;
  int stage_v_288_2 = ((pub_r001235_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((stage_v_94_1 << 1) ^ (pub_r001235_20_1 >> 1)) & 127;
  int stage_v_289_2 = ((stage_v_94_2 << 1) ^ (pub_r001235_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_289_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_289_2 + 1) & 15;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = ((stage_v_42_1 << 1) ^ (pub_r001235_10_1 >> 1)) & 127;
  int stage_v_290_2 = ((stage_v_42_2 << 1) ^ (pub_r001235_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_290_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_290_2 + 1) & 15;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = ((pub_r001235_17_1 * 2) + 30) & 63;
  int stage_v_291_2 = ((pub_r001235_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((stage_v_246_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_292_2 = ((stage_v_246_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_292_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_292_2 + 1) & 15;
  out_sink_1 ^= stage_v_292_1 & 63;
  out_sink_2 ^= stage_v_292_2 & 63;
  int stage_v_293_1 = ((stage_v_118_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_293_2 = ((stage_v_118_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_293_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_293_2 + 1) & 15;
  out_sink_1 ^= stage_v_293_1 & 63;
  out_sink_2 ^= stage_v_293_2 & 63;
  int stage_v_294_1 = ((stage_v_34_1 << 1) ^ (pub_r001235_2_1 >> 1)) & 127;
  int stage_v_294_2 = ((stage_v_34_2 << 1) ^ (pub_r001235_2_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_294_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_294_2 + 1) & 15;
  out_sink_1 ^= stage_v_294_1 & 63;
  out_sink_2 ^= stage_v_294_2 & 63;
  int stage_v_295_1 = ((pub_r001235_22_1 * 2) + 19) & 63;
  int stage_v_295_2 = ((pub_r001235_22_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((pub_r001235_5_1 * 2) + 23) & 63;
  int stage_v_296_2 = ((pub_r001235_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001235_6_1 * 2) + 31) & 63;
  int stage_v_297_2 = ((pub_r001235_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((stage_v_102_1 << 1) ^ (pub_r001235_8_1 >> 1)) & 127;
  int stage_v_298_2 = ((stage_v_102_2 << 1) ^ (pub_r001235_8_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_298_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_298_2 + 1) & 15;
  out_sink_1 ^= stage_v_298_1 & 63;
  out_sink_2 ^= stage_v_298_2 & 63;
  int stage_v_299_1 = ((stage_v_9_1 << 1) ^ (pub_r001235_13_1 >> 1)) & 127;
  int stage_v_299_2 = ((stage_v_9_2 << 1) ^ (pub_r001235_13_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_299_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_299_2 + 1) & 15;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = ((stage_v_89_1 << 1) ^ (pub_r001235_0_1 >> 1)) & 127;
  int stage_v_300_2 = ((stage_v_89_2 << 1) ^ (pub_r001235_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_300_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_300_2 + 1) & 15;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = ((pub_r001235_11_1 * 2) + 48) & 63;
  int stage_v_301_2 = ((pub_r001235_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((stage_v_57_1 << 1) ^ (pub_r001235_23_1 >> 1)) & 127;
  int stage_v_302_2 = ((stage_v_57_2 << 1) ^ (pub_r001235_23_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_302_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_302_2 + 1) & 15;
  out_sink_1 ^= stage_v_302_1 & 63;
  out_sink_2 ^= stage_v_302_2 & 63;
  int stage_v_303_1 = ((stage_v_117_1 << 1) ^ (pub_r001235_10_1 >> 1)) & 127;
  int stage_v_303_2 = ((stage_v_117_2 << 1) ^ (pub_r001235_10_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_303_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_303_2 + 1) & 15;
  out_sink_1 ^= stage_v_303_1 & 63;
  out_sink_2 ^= stage_v_303_2 & 63;
  int stage_v_304_1 = ((pub_r001235_13_1 * 2) + 6) & 63;
  int stage_v_304_2 = ((pub_r001235_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((stage_v_158_1 << 1) ^ (pub_r001235_2_1 >> 1)) & 127;
  int stage_v_305_2 = ((stage_v_158_2 << 1) ^ (pub_r001235_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_305_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_305_2 + 1) & 15;
  out_sink_1 ^= stage_v_305_1 & 63;
  out_sink_2 ^= stage_v_305_2 & 63;
  int stage_v_306_1 = ((pub_r001235_11_1 * 2) + 24) & 63;
  int stage_v_306_2 = ((pub_r001235_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001235_3_1 * 2) + 9) & 63;
  int stage_v_307_2 = ((pub_r001235_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001235_8_1 * 2) + 14) & 63;
  int stage_v_308_2 = ((pub_r001235_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((stage_v_298_1 << 1) ^ (pub_r001235_15_1 >> 1)) & 127;
  int stage_v_309_2 = ((stage_v_298_2 << 1) ^ (pub_r001235_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_309_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_309_2 + 1) & 15;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = ((pub_r001235_21_1 * 2) + 50) & 63;
  int stage_v_310_2 = ((pub_r001235_21_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((pub_r001235_21_1 * 2) + 49) & 63;
  int stage_v_311_2 = ((pub_r001235_21_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((pub_r001235_18_1 * 2) + 18) & 63;
  int stage_v_312_2 = ((pub_r001235_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = ((pub_r001235_17_1 * 2) + 14) & 63;
  int stage_v_313_2 = ((pub_r001235_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = ((pub_r001235_10_1 * 2) + 48) & 63;
  int stage_v_314_2 = ((pub_r001235_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001235_10_1 * 2) + 21) & 63;
  int stage_v_315_2 = ((pub_r001235_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((stage_v_275_1 << 1) ^ (pub_r001235_22_1 >> 1)) & 127;
  int stage_v_316_2 = ((stage_v_275_2 << 1) ^ (pub_r001235_22_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_316_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_316_2 + 1) & 15;
  out_sink_1 ^= stage_v_316_1 & 63;
  out_sink_2 ^= stage_v_316_2 & 63;
  int stage_v_317_1 = ((stage_v_94_1 << 1) ^ (pub_r001235_14_1 >> 1)) & 127;
  int stage_v_317_2 = ((stage_v_94_2 << 1) ^ (pub_r001235_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_317_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_317_2 + 1) & 15;
  out_sink_1 ^= stage_v_317_1 & 63;
  out_sink_2 ^= stage_v_317_2 & 63;
  int stage_v_318_1 = ((helper_flow_2_1 << 1) ^ (pub_r001235_10_1 >> 1)) & 127;
  int stage_v_318_2 = ((helper_flow_2_2 << 1) ^ (pub_r001235_10_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_318_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_318_2 + 1) & 15;
  out_sink_1 ^= stage_v_318_1 & 63;
  out_sink_2 ^= stage_v_318_2 & 63;
  int stage_v_319_1 = ((stage_v_92_1 << 1) ^ (pub_r001235_5_1 >> 1)) & 127;
  int stage_v_319_2 = ((stage_v_92_2 << 1) ^ (pub_r001235_5_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_319_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_319_2 + 1) & 15;
  out_sink_1 ^= stage_v_319_1 & 63;
  out_sink_2 ^= stage_v_319_2 & 63;
  int stage_v_320_1 = ((stage_v_252_1 << 1) ^ (pub_r001235_7_1 >> 1)) & 127;
  int stage_v_320_2 = ((stage_v_252_2 << 1) ^ (pub_r001235_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_320_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_320_2 + 1) & 15;
  out_sink_1 ^= stage_v_320_1 & 63;
  out_sink_2 ^= stage_v_320_2 & 63;
  int stage_v_321_1 = ((stage_v_157_1 << 1) ^ (pub_r001235_11_1 >> 1)) & 127;
  int stage_v_321_2 = ((stage_v_157_2 << 1) ^ (pub_r001235_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_321_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_321_2 + 1) & 15;
  out_sink_1 ^= stage_v_321_1 & 63;
  out_sink_2 ^= stage_v_321_2 & 63;
  int stage_v_322_1 = ((stage_v_67_1 << 1) ^ (pub_r001235_5_1 >> 1)) & 127;
  int stage_v_322_2 = ((stage_v_67_2 << 1) ^ (pub_r001235_5_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_322_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_322_2 + 1) & 15;
  out_sink_1 ^= stage_v_322_1 & 63;
  out_sink_2 ^= stage_v_322_2 & 63;
  int stage_v_323_1 = ((stage_v_199_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_323_2 = ((stage_v_199_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_323_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_323_2 + 1) & 15;
  out_sink_1 ^= stage_v_323_1 & 63;
  out_sink_2 ^= stage_v_323_2 & 63;
  int stage_v_324_1 = ((pub_r001235_18_1 * 2) + 32) & 63;
  int stage_v_324_2 = ((pub_r001235_18_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((stage_v_159_1 << 1) ^ (pub_r001235_7_1 >> 1)) & 127;
  int stage_v_325_2 = ((stage_v_159_2 << 1) ^ (pub_r001235_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_325_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_325_2 + 1) & 15;
  out_sink_1 ^= stage_v_325_1 & 63;
  out_sink_2 ^= stage_v_325_2 & 63;
  int stage_v_326_1 = ((pub_r001235_13_1 * 2) + 8) & 63;
  int stage_v_326_2 = ((pub_r001235_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001235_17_1 * 2) + 49) & 63;
  int stage_v_327_2 = ((pub_r001235_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((stage_v_243_1 << 1) ^ (pub_r001235_1_1 >> 1)) & 127;
  int stage_v_328_2 = ((stage_v_243_2 << 1) ^ (pub_r001235_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_328_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_328_2 + 1) & 15;
  out_sink_1 ^= stage_v_328_1 & 63;
  out_sink_2 ^= stage_v_328_2 & 63;
  int stage_v_329_1 = ((pub_r001235_17_1 * 2) + 29) & 63;
  int stage_v_329_2 = ((pub_r001235_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((stage_v_299_1 << 1) ^ (pub_r001235_9_1 >> 1)) & 127;
  int stage_v_330_2 = ((stage_v_299_2 << 1) ^ (pub_r001235_9_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_330_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_330_2 + 1) & 15;
  out_sink_1 ^= stage_v_330_1 & 63;
  out_sink_2 ^= stage_v_330_2 & 63;
  int stage_v_331_1 = ((pub_r001235_0_1 * 2) + 32) & 63;
  int stage_v_331_2 = ((pub_r001235_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001235_8_1 * 2) + 49) & 63;
  int stage_v_332_2 = ((pub_r001235_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((stage_v_132_1 << 1) ^ (pub_r001235_15_1 >> 1)) & 127;
  int stage_v_333_2 = ((stage_v_132_2 << 1) ^ (pub_r001235_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_333_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_333_2 + 1) & 15;
  out_sink_1 ^= stage_v_333_1 & 63;
  out_sink_2 ^= stage_v_333_2 & 63;
  int stage_v_334_1 = ((stage_v_168_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_334_2 = ((stage_v_168_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_334_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_334_2 + 1) & 15;
  out_sink_1 ^= stage_v_334_1 & 63;
  out_sink_2 ^= stage_v_334_2 & 63;
  int stage_v_335_1 = ((pub_r001235_15_1 * 2) + 49) & 63;
  int stage_v_335_2 = ((pub_r001235_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((stage_v_246_1 << 1) ^ (pub_r001235_12_1 >> 1)) & 127;
  int stage_v_336_2 = ((stage_v_246_2 << 1) ^ (pub_r001235_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_336_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_336_2 + 1) & 15;
  out_sink_1 ^= stage_v_336_1 & 63;
  out_sink_2 ^= stage_v_336_2 & 63;
  int stage_v_337_1 = ((stage_v_112_1 << 1) ^ (pub_r001235_6_1 >> 1)) & 127;
  int stage_v_337_2 = ((stage_v_112_2 << 1) ^ (pub_r001235_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_337_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_337_2 + 1) & 15;
  out_sink_1 ^= stage_v_337_1 & 63;
  out_sink_2 ^= stage_v_337_2 & 63;
  int stage_v_338_1 = ((stage_v_50_1 << 1) ^ (pub_r001235_4_1 >> 1)) & 127;
  int stage_v_338_2 = ((stage_v_50_2 << 1) ^ (pub_r001235_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_338_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_338_2 + 1) & 15;
  out_sink_1 ^= stage_v_338_1 & 63;
  out_sink_2 ^= stage_v_338_2 & 63;
  int stage_v_339_1 = ((pub_r001235_18_1 * 2) + 39) & 63;
  int stage_v_339_2 = ((pub_r001235_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((stage_v_209_1 << 1) ^ (pub_r001235_2_1 >> 1)) & 127;
  int stage_v_340_2 = ((stage_v_209_2 << 1) ^ (pub_r001235_2_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_340_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_340_2 + 1) & 15;
  out_sink_1 ^= stage_v_340_1 & 63;
  out_sink_2 ^= stage_v_340_2 & 63;
  int stage_v_341_1 = ((stage_v_272_1 << 1) ^ (pub_r001235_14_1 >> 1)) & 127;
  int stage_v_341_2 = ((stage_v_272_2 << 1) ^ (pub_r001235_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_341_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_341_2 + 1) & 15;
  out_sink_1 ^= stage_v_341_1 & 63;
  out_sink_2 ^= stage_v_341_2 & 63;
  int stage_v_342_1 = ((stage_v_117_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_342_2 = ((stage_v_117_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_342_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_342_2 + 1) & 15;
  out_sink_1 ^= stage_v_342_1 & 63;
  out_sink_2 ^= stage_v_342_2 & 63;
  int stage_v_343_1 = ((pub_r001235_2_1 * 2) + 23) & 63;
  int stage_v_343_2 = ((pub_r001235_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((helper_flow_0_1 << 1) ^ (pub_r001235_7_1 >> 1)) & 127;
  int stage_v_344_2 = ((helper_flow_0_2 << 1) ^ (pub_r001235_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_344_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_344_2 + 1) & 15;
  out_sink_1 ^= stage_v_344_1 & 63;
  out_sink_2 ^= stage_v_344_2 & 63;
  int stage_v_345_1 = ((stage_v_272_1 << 1) ^ (pub_r001235_22_1 >> 1)) & 127;
  int stage_v_345_2 = ((stage_v_272_2 << 1) ^ (pub_r001235_22_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_345_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_345_2 + 1) & 15;
  out_sink_1 ^= stage_v_345_1 & 63;
  out_sink_2 ^= stage_v_345_2 & 63;
  int stage_v_346_1 = ((pub_r001235_22_1 * 2) + 49) & 63;
  int stage_v_346_2 = ((pub_r001235_22_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001235_3_1 * 2) + 7) & 63;
  int stage_v_347_2 = ((pub_r001235_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001235_22_1 * 2) + 42) & 63;
  int stage_v_348_2 = ((pub_r001235_22_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((helper_flow_1_1 << 1) ^ (pub_r001235_20_1 >> 1)) & 127;
  int stage_v_349_2 = ((helper_flow_1_2 << 1) ^ (pub_r001235_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_349_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_349_2 + 1) & 15;
  out_sink_1 ^= stage_v_349_1 & 63;
  out_sink_2 ^= stage_v_349_2 & 63;
  int stage_v_350_1 = ((sec_r001235_7_1 << 1) ^ (pub_r001235_2_1 >> 1)) & 127;
  int stage_v_350_2 = ((sec_r001235_7_2 << 1) ^ (pub_r001235_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_350_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_350_2 + 1) & 15;
  out_sink_1 ^= stage_v_350_1 & 63;
  out_sink_2 ^= stage_v_350_2 & 63;
  int stage_v_351_1 = ((stage_v_174_1 << 1) ^ (pub_r001235_10_1 >> 1)) & 127;
  int stage_v_351_2 = ((stage_v_174_2 << 1) ^ (pub_r001235_10_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_351_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_351_2 + 1) & 15;
  out_sink_1 ^= stage_v_351_1 & 63;
  out_sink_2 ^= stage_v_351_2 & 63;
  int stage_v_352_1 = ((pub_r001235_5_1 * 2) + 23) & 63;
  int stage_v_352_2 = ((pub_r001235_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001235_1_1 * 2) + 44) & 63;
  int stage_v_353_2 = ((pub_r001235_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((stage_v_287_1 << 1) ^ (pub_r001235_5_1 >> 1)) & 127;
  int stage_v_354_2 = ((stage_v_287_2 << 1) ^ (pub_r001235_5_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_354_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_354_2 + 1) & 15;
  out_sink_1 ^= stage_v_354_1 & 63;
  out_sink_2 ^= stage_v_354_2 & 63;
  int stage_v_355_1 = ((stage_v_277_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_355_2 = ((stage_v_277_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_355_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_355_2 + 1) & 15;
  out_sink_1 ^= stage_v_355_1 & 63;
  out_sink_2 ^= stage_v_355_2 & 63;
  int stage_v_356_1 = ((pub_r001235_23_1 * 2) + 27) & 63;
  int stage_v_356_2 = ((pub_r001235_23_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001235_11_1 * 2) + 29) & 63;
  int stage_v_357_2 = ((pub_r001235_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((stage_v_263_1 << 1) ^ (pub_r001235_23_1 >> 1)) & 127;
  int stage_v_358_2 = ((stage_v_263_2 << 1) ^ (pub_r001235_23_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_358_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_358_2 + 1) & 15;
  out_sink_1 ^= stage_v_358_1 & 63;
  out_sink_2 ^= stage_v_358_2 & 63;
  int stage_v_359_1 = ((stage_v_109_1 << 1) ^ (pub_r001235_9_1 >> 1)) & 127;
  int stage_v_359_2 = ((stage_v_109_2 << 1) ^ (pub_r001235_9_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_359_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_359_2 + 1) & 15;
  out_sink_1 ^= stage_v_359_1 & 63;
  out_sink_2 ^= stage_v_359_2 & 63;
  int stage_v_360_1 = ((stage_v_112_1 << 1) ^ (pub_r001235_18_1 >> 1)) & 127;
  int stage_v_360_2 = ((stage_v_112_2 << 1) ^ (pub_r001235_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_360_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_360_2 + 1) & 15;
  out_sink_1 ^= stage_v_360_1 & 63;
  out_sink_2 ^= stage_v_360_2 & 63;
  int stage_v_361_1 = ((stage_v_269_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_361_2 = ((stage_v_269_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_361_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_361_2 + 1) & 15;
  out_sink_1 ^= stage_v_361_1 & 63;
  out_sink_2 ^= stage_v_361_2 & 63;
  int stage_v_362_1 = ((stage_v_193_1 << 1) ^ (pub_r001235_15_1 >> 1)) & 127;
  int stage_v_362_2 = ((stage_v_193_2 << 1) ^ (pub_r001235_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_362_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_362_2 + 1) & 15;
  out_sink_1 ^= stage_v_362_1 & 63;
  out_sink_2 ^= stage_v_362_2 & 63;
  int stage_v_363_1 = ((stage_v_34_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_363_2 = ((stage_v_34_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_363_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_363_2 + 1) & 15;
  out_sink_1 ^= stage_v_363_1 & 63;
  out_sink_2 ^= stage_v_363_2 & 63;
  int stage_v_364_1 = ((sec_r001235_11_1 << 1) ^ (pub_r001235_20_1 >> 1)) & 127;
  int stage_v_364_2 = ((sec_r001235_11_2 << 1) ^ (pub_r001235_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_364_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_364_2 + 1) & 15;
  out_sink_1 ^= stage_v_364_1 & 63;
  out_sink_2 ^= stage_v_364_2 & 63;
  int stage_v_365_1 = ((stage_v_265_1 << 1) ^ (pub_r001235_15_1 >> 1)) & 127;
  int stage_v_365_2 = ((stage_v_265_2 << 1) ^ (pub_r001235_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_365_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_365_2 + 1) & 15;
  out_sink_1 ^= stage_v_365_1 & 63;
  out_sink_2 ^= stage_v_365_2 & 63;
  int stage_v_366_1 = ((stage_v_53_1 << 1) ^ (pub_r001235_16_1 >> 1)) & 127;
  int stage_v_366_2 = ((stage_v_53_2 << 1) ^ (pub_r001235_16_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_366_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_366_2 + 1) & 15;
  out_sink_1 ^= stage_v_366_1 & 63;
  out_sink_2 ^= stage_v_366_2 & 63;
  int stage_v_367_1 = ((pub_r001235_7_1 * 2) + 26) & 63;
  int stage_v_367_2 = ((pub_r001235_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001235_3_1 * 2) + 22) & 63;
  int stage_v_368_2 = ((pub_r001235_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((stage_v_365_1 << 1) ^ (pub_r001235_12_1 >> 1)) & 127;
  int stage_v_369_2 = ((stage_v_365_2 << 1) ^ (pub_r001235_12_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_369_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_369_2 + 1) & 15;
  out_sink_1 ^= stage_v_369_1 & 63;
  out_sink_2 ^= stage_v_369_2 & 63;
  int stage_v_370_1 = ((stage_v_225_1 << 1) ^ (pub_r001235_18_1 >> 1)) & 127;
  int stage_v_370_2 = ((stage_v_225_2 << 1) ^ (pub_r001235_18_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_370_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_370_2 + 1) & 15;
  out_sink_1 ^= stage_v_370_1 & 63;
  out_sink_2 ^= stage_v_370_2 & 63;
  int stage_v_371_1 = ((pub_r001235_10_1 * 2) + 7) & 63;
  int stage_v_371_2 = ((pub_r001235_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((stage_v_365_1 << 1) ^ (pub_r001235_2_1 >> 1)) & 127;
  int stage_v_372_2 = ((stage_v_365_2 << 1) ^ (pub_r001235_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_372_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_372_2 + 1) & 15;
  out_sink_1 ^= stage_v_372_1 & 63;
  out_sink_2 ^= stage_v_372_2 & 63;
  int stage_v_373_1 = ((pub_r001235_17_1 * 2) + 34) & 63;
  int stage_v_373_2 = ((pub_r001235_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((stage_v_220_1 << 1) ^ (pub_r001235_9_1 >> 1)) & 127;
  int stage_v_374_2 = ((stage_v_220_2 << 1) ^ (pub_r001235_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_374_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_374_2 + 1) & 15;
  out_sink_1 ^= stage_v_374_1 & 63;
  out_sink_2 ^= stage_v_374_2 & 63;
  int stage_v_375_1 = ((stage_v_68_1 << 1) ^ (pub_r001235_3_1 >> 1)) & 127;
  int stage_v_375_2 = ((stage_v_68_2 << 1) ^ (pub_r001235_3_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_375_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_375_2 + 1) & 15;
  out_sink_1 ^= stage_v_375_1 & 63;
  out_sink_2 ^= stage_v_375_2 & 63;
  int stage_v_376_1 = ((pub_r001235_14_1 * 2) + 19) & 63;
  int stage_v_376_2 = ((pub_r001235_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((stage_v_277_1 << 1) ^ (pub_r001235_0_1 >> 1)) & 127;
  int stage_v_377_2 = ((stage_v_277_2 << 1) ^ (pub_r001235_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_377_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_377_2 + 1) & 15;
  out_sink_1 ^= stage_v_377_1 & 63;
  out_sink_2 ^= stage_v_377_2 & 63;
  int stage_v_378_1 = ((stage_v_179_1 << 1) ^ (pub_r001235_10_1 >> 1)) & 127;
  int stage_v_378_2 = ((stage_v_179_2 << 1) ^ (pub_r001235_10_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_378_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_378_2 + 1) & 15;
  out_sink_1 ^= stage_v_378_1 & 63;
  out_sink_2 ^= stage_v_378_2 & 63;
  int stage_v_379_1 = ((pub_r001235_16_1 * 2) + 27) & 63;
  int stage_v_379_2 = ((pub_r001235_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = ((stage_v_365_1 << 1) ^ (pub_r001235_10_1 >> 1)) & 127;
  int stage_v_380_2 = ((stage_v_365_2 << 1) ^ (pub_r001235_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_380_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_380_2 + 1) & 15;
  out_sink_1 ^= stage_v_380_1 & 63;
  out_sink_2 ^= stage_v_380_2 & 63;
  int stage_v_381_1 = ((sec_r001235_4_1 << 1) ^ (pub_r001235_7_1 >> 1)) & 127;
  int stage_v_381_2 = ((sec_r001235_4_2 << 1) ^ (pub_r001235_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_381_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_381_2 + 1) & 15;
  out_sink_1 ^= stage_v_381_1 & 63;
  out_sink_2 ^= stage_v_381_2 & 63;
  int stage_v_382_1 = ((pub_r001235_2_1 * 2) + 31) & 63;
  int stage_v_382_2 = ((pub_r001235_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001235_21_1 * 2) + 5) & 63;
  int stage_v_383_2 = ((pub_r001235_21_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((stage_v_342_1 << 1) ^ (pub_r001235_14_1 >> 1)) & 127;
  int stage_v_384_2 = ((stage_v_342_2 << 1) ^ (pub_r001235_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_384_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_384_2 + 1) & 15;
  out_sink_1 ^= stage_v_384_1 & 63;
  out_sink_2 ^= stage_v_384_2 & 63;
  int stage_v_385_1 = ((stage_v_150_1 << 1) ^ (pub_r001235_5_1 >> 1)) & 127;
  int stage_v_385_2 = ((stage_v_150_2 << 1) ^ (pub_r001235_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_385_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_385_2 + 1) & 15;
  out_sink_1 ^= stage_v_385_1 & 63;
  out_sink_2 ^= stage_v_385_2 & 63;
  int stage_v_386_1 = ((pub_r001235_2_1 * 2) + 19) & 63;
  int stage_v_386_2 = ((pub_r001235_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((stage_v_146_1 << 1) ^ (pub_r001235_16_1 >> 1)) & 127;
  int stage_v_387_2 = ((stage_v_146_2 << 1) ^ (pub_r001235_16_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_387_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_387_2 + 1) & 15;
  out_sink_1 ^= stage_v_387_1 & 63;
  out_sink_2 ^= stage_v_387_2 & 63;
  int stage_v_388_1 = ((stage_v_43_1 << 1) ^ (pub_r001235_2_1 >> 1)) & 127;
  int stage_v_388_2 = ((stage_v_43_2 << 1) ^ (pub_r001235_2_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_388_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_388_2 + 1) & 15;
  out_sink_1 ^= stage_v_388_1 & 63;
  out_sink_2 ^= stage_v_388_2 & 63;
  int stage_v_389_1 = ((stage_v_193_1 << 1) ^ (pub_r001235_11_1 >> 1)) & 127;
  int stage_v_389_2 = ((stage_v_193_2 << 1) ^ (pub_r001235_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_389_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_389_2 + 1) & 15;
  out_sink_1 ^= stage_v_389_1 & 63;
  out_sink_2 ^= stage_v_389_2 & 63;
  int stage_v_390_1 = ((pub_r001235_12_1 * 2) + 40) & 63;
  int stage_v_390_2 = ((pub_r001235_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((stage_v_369_1 << 1) ^ (pub_r001235_0_1 >> 1)) & 127;
  int stage_v_391_2 = ((stage_v_369_2 << 1) ^ (pub_r001235_0_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_391_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_391_2 + 1) & 15;
  out_sink_1 ^= stage_v_391_1 & 63;
  out_sink_2 ^= stage_v_391_2 & 63;
  int stage_v_392_1 = ((stage_v_94_1 << 1) ^ (pub_r001235_9_1 >> 1)) & 127;
  int stage_v_392_2 = ((stage_v_94_2 << 1) ^ (pub_r001235_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_392_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_392_2 + 1) & 15;
  out_sink_1 ^= stage_v_392_1 & 63;
  out_sink_2 ^= stage_v_392_2 & 63;
  int stage_v_393_1 = ((pub_r001235_14_1 * 2) + 43) & 63;
  int stage_v_393_2 = ((pub_r001235_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((pub_r001235_4_1 * 2) + 35) & 63;
  int stage_v_394_2 = ((pub_r001235_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001235_0_1 * 2) + 12) & 63;
  int stage_v_395_2 = ((pub_r001235_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((stage_v_365_1 << 1) ^ (pub_r001235_21_1 >> 1)) & 127;
  int stage_v_396_2 = ((stage_v_365_2 << 1) ^ (pub_r001235_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_396_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_396_2 + 1) & 15;
  out_sink_1 ^= stage_v_396_1 & 63;
  out_sink_2 ^= stage_v_396_2 & 63;
  int stage_v_397_1 = ((pub_r001235_9_1 * 2) + 37) & 63;
  int stage_v_397_2 = ((pub_r001235_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((stage_v_325_1 << 1) ^ (pub_r001235_8_1 >> 1)) & 127;
  int stage_v_398_2 = ((stage_v_325_2 << 1) ^ (pub_r001235_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_398_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_398_2 + 1) & 15;
  out_sink_1 ^= stage_v_398_1 & 63;
  out_sink_2 ^= stage_v_398_2 & 63;
  int stage_v_399_1 = ((pub_r001235_17_1 * 2) + 39) & 63;
  int stage_v_399_2 = ((pub_r001235_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((stage_v_350_1 << 1) ^ (pub_r001235_13_1 >> 1)) & 127;
  int stage_v_400_2 = ((stage_v_350_2 << 1) ^ (pub_r001235_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_400_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_400_2 + 1) & 15;
  out_sink_1 ^= stage_v_400_1 & 63;
  out_sink_2 ^= stage_v_400_2 & 63;
  int stage_v_401_1 = ((stage_v_375_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_401_2 = ((stage_v_375_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_401_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_401_2 + 1) & 15;
  out_sink_1 ^= stage_v_401_1 & 63;
  out_sink_2 ^= stage_v_401_2 & 63;
  int stage_v_402_1 = ((stage_v_50_1 << 1) ^ (pub_r001235_9_1 >> 1)) & 127;
  int stage_v_402_2 = ((stage_v_50_2 << 1) ^ (pub_r001235_9_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_402_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_402_2 + 1) & 15;
  out_sink_1 ^= stage_v_402_1 & 63;
  out_sink_2 ^= stage_v_402_2 & 63;
  int stage_v_403_1 = ((stage_v_70_1 << 1) ^ (pub_r001235_17_1 >> 1)) & 127;
  int stage_v_403_2 = ((stage_v_70_2 << 1) ^ (pub_r001235_17_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_403_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_403_2 + 1) & 15;
  out_sink_1 ^= stage_v_403_1 & 63;
  out_sink_2 ^= stage_v_403_2 & 63;
  int stage_v_404_1 = ((stage_v_168_1 << 1) ^ (pub_r001235_10_1 >> 1)) & 127;
  int stage_v_404_2 = ((stage_v_168_2 << 1) ^ (pub_r001235_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_404_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_404_2 + 1) & 15;
  out_sink_1 ^= stage_v_404_1 & 63;
  out_sink_2 ^= stage_v_404_2 & 63;
  int stage_v_405_1 = ((stage_v_98_1 << 1) ^ (pub_r001235_7_1 >> 1)) & 127;
  int stage_v_405_2 = ((stage_v_98_2 << 1) ^ (pub_r001235_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_405_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_405_2 + 1) & 15;
  out_sink_1 ^= stage_v_405_1 & 63;
  out_sink_2 ^= stage_v_405_2 & 63;
  int stage_v_406_1 = ((pub_r001235_11_1 * 2) + 13) & 63;
  int stage_v_406_2 = ((pub_r001235_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((pub_r001235_11_1 * 2) + 16) & 63;
  int stage_v_407_2 = ((pub_r001235_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001235_3_1 * 2) + 43) & 63;
  int stage_v_408_2 = ((pub_r001235_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((stage_v_75_1 << 1) ^ (pub_r001235_22_1 >> 1)) & 127;
  int stage_v_409_2 = ((stage_v_75_2 << 1) ^ (pub_r001235_22_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_409_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_409_2 + 1) & 15;
  out_sink_1 ^= stage_v_409_1 & 63;
  out_sink_2 ^= stage_v_409_2 & 63;
  int stage_v_410_1 = ((pub_r001235_21_1 * 2) + 9) & 63;
  int stage_v_410_2 = ((pub_r001235_21_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((stage_v_126_1 << 1) ^ (pub_r001235_9_1 >> 1)) & 127;
  int stage_v_411_2 = ((stage_v_126_2 << 1) ^ (pub_r001235_9_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_411_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_411_2 + 1) & 15;
  out_sink_1 ^= stage_v_411_1 & 63;
  out_sink_2 ^= stage_v_411_2 & 63;
  int stage_v_412_1 = ((stage_v_378_1 << 1) ^ (pub_r001235_11_1 >> 1)) & 127;
  int stage_v_412_2 = ((stage_v_378_2 << 1) ^ (pub_r001235_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_412_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_412_2 + 1) & 15;
  out_sink_1 ^= stage_v_412_1 & 63;
  out_sink_2 ^= stage_v_412_2 & 63;
  int stage_v_413_1 = ((stage_v_95_1 << 1) ^ (pub_r001235_11_1 >> 1)) & 127;
  int stage_v_413_2 = ((stage_v_95_2 << 1) ^ (pub_r001235_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_413_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_413_2 + 1) & 15;
  out_sink_1 ^= stage_v_413_1 & 63;
  out_sink_2 ^= stage_v_413_2 & 63;
  int stage_v_414_1 = ((stage_v_162_1 << 1) ^ (pub_r001235_21_1 >> 1)) & 127;
  int stage_v_414_2 = ((stage_v_162_2 << 1) ^ (pub_r001235_21_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_414_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_414_2 + 1) & 15;
  out_sink_1 ^= stage_v_414_1 & 63;
  out_sink_2 ^= stage_v_414_2 & 63;
  int stage_v_415_1 = ((stage_v_279_1 << 1) ^ (pub_r001235_3_1 >> 1)) & 127;
  int stage_v_415_2 = ((stage_v_279_2 << 1) ^ (pub_r001235_3_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_415_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_415_2 + 1) & 15;
  out_sink_1 ^= stage_v_415_1 & 63;
  out_sink_2 ^= stage_v_415_2 & 63;
  int stage_v_416_1 = ((stage_v_138_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_416_2 = ((stage_v_138_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_416_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_416_2 + 1) & 15;
  out_sink_1 ^= stage_v_416_1 & 63;
  out_sink_2 ^= stage_v_416_2 & 63;
  int stage_v_417_1 = ((pub_r001235_10_1 * 2) + 30) & 63;
  int stage_v_417_2 = ((pub_r001235_10_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((stage_v_49_1 << 1) ^ (pub_r001235_19_1 >> 1)) & 127;
  int stage_v_418_2 = ((stage_v_49_2 << 1) ^ (pub_r001235_19_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_418_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_418_2 + 1) & 15;
  out_sink_1 ^= stage_v_418_1 & 63;
  out_sink_2 ^= stage_v_418_2 & 63;
  int stage_v_419_1 = ((pub_r001235_8_1 * 2) + 12) & 63;
  int stage_v_419_2 = ((pub_r001235_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = ((stage_v_220_1 << 1) ^ (pub_r001235_18_1 >> 1)) & 127;
  int stage_v_420_2 = ((stage_v_220_2 << 1) ^ (pub_r001235_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_420_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_420_2 + 1) & 15;
  out_sink_1 ^= stage_v_420_1 & 63;
  out_sink_2 ^= stage_v_420_2 & 63;
  int stage_v_421_1 = ((pub_r001235_10_1 * 2) + 16) & 63;
  int stage_v_421_2 = ((pub_r001235_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((pub_r001235_7_1 * 2) + 46) & 63;
  int stage_v_422_2 = ((pub_r001235_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((stage_v_269_1 << 1) ^ (pub_r001235_13_1 >> 1)) & 127;
  int stage_v_423_2 = ((stage_v_269_2 << 1) ^ (pub_r001235_13_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_423_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_423_2 + 1) & 15;
  out_sink_1 ^= stage_v_423_1 & 63;
  out_sink_2 ^= stage_v_423_2 & 63;
  int stage_v_424_1 = ((pub_r001235_1_1 * 2) + 40) & 63;
  int stage_v_424_2 = ((pub_r001235_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((stage_v_14_1 << 1) ^ (pub_r001235_6_1 >> 1)) & 127;
  int stage_v_425_2 = ((stage_v_14_2 << 1) ^ (pub_r001235_6_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_425_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_425_2 + 1) & 15;
  out_sink_1 ^= stage_v_425_1 & 63;
  out_sink_2 ^= stage_v_425_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001235_13_1 != sec_r001235_13_2);
  __CPROVER_assume(sec_r001235_10_1 != sec_r001235_10_2);
  __CPROVER_assume(sec_r001235_16_1 != sec_r001235_16_2);
  __CPROVER_assume(sec_r001235_14_1 != sec_r001235_14_2);
  __CPROVER_assume(pub_r001235_0_1 == pub_r001235_0_2);
  __CPROVER_assume(pub_r001235_11_1 == pub_r001235_11_2);
  __CPROVER_assume(pub_r001235_16_1 == pub_r001235_16_2);
  __CPROVER_assume(pub_r001235_21_1 == pub_r001235_21_2);
  __CPROVER_assume(pub_r001235_17_1 == pub_r001235_17_2);
  __CPROVER_assume(sec_r001235_15_1 != sec_r001235_15_2);
  __CPROVER_assume(pub_r001235_8_1 == pub_r001235_8_2);
  __CPROVER_assume(sec_r001235_2_1 != sec_r001235_2_2);
  __CPROVER_assume(sec_r001235_6_1 != sec_r001235_6_2);
  __CPROVER_assume(pub_r001235_4_1 == pub_r001235_4_2);
  __CPROVER_assume(pub_r001235_2_1 == pub_r001235_2_2);
  __CPROVER_assume(sec_r001235_12_1 != sec_r001235_12_2);
  __CPROVER_assume(pub_r001235_14_1 == pub_r001235_14_2);
  __CPROVER_assume(pub_r001235_20_1 == pub_r001235_20_2);
  __CPROVER_assume(pub_r001235_18_1 == pub_r001235_18_2);
  __CPROVER_assume(pub_r001235_1_1 == pub_r001235_1_2);
  __CPROVER_assume(pub_r001235_6_1 == pub_r001235_6_2);
  __CPROVER_assume(sec_r001235_4_1 != sec_r001235_4_2);
  __CPROVER_assume(sec_r001235_8_1 != sec_r001235_8_2);
  __CPROVER_assume(pub_r001235_3_1 == pub_r001235_3_2);
  __CPROVER_assume(pub_r001235_23_1 == pub_r001235_23_2);
  __CPROVER_assume(sec_r001235_9_1 != sec_r001235_9_2);
  __CPROVER_assume(sec_r001235_5_1 != sec_r001235_5_2);
  __CPROVER_assume(sec_r001235_7_1 != sec_r001235_7_2);
  __CPROVER_assume(pub_r001235_5_1 == pub_r001235_5_2);
  __CPROVER_assume(pub_r001235_10_1 == pub_r001235_10_2);
  __CPROVER_assume(pub_r001235_12_1 == pub_r001235_12_2);
  __CPROVER_assume(pub_r001235_15_1 == pub_r001235_15_2);
  __CPROVER_assume(sec_r001235_11_1 != sec_r001235_11_2);
  __CPROVER_assume(pub_r001235_19_1 == pub_r001235_19_2);
  __CPROVER_assume(pub_r001235_22_1 == pub_r001235_22_2);
  __CPROVER_assume(sec_r001235_0_1 != sec_r001235_0_2);
  __CPROVER_assume(pub_r001235_9_1 == pub_r001235_9_2);
  __CPROVER_assume(pub_r001235_13_1 == pub_r001235_13_2);
  __CPROVER_assume(sec_r001235_3_1 != sec_r001235_3_2);
  __CPROVER_assume(sec_r001235_1_1 != sec_r001235_1_2);
  __CPROVER_assume(pub_r001235_7_1 == pub_r001235_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.calib == st_var_2_2.calib);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.reading == st_var_2_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.gain_db == st_var_3_2.gain_db);
  assert(st_var_3_1.mode == st_var_3_2.mode);
  assert(st_var_3_1.prev_in == st_var_3_2.prev_in);
  assert(st_var_3_1.prev_out == st_var_3_2.prev_out);
  assert(st_var_3_1.cutoff == st_var_3_2.cutoff);
  assert(st_var_3_1.damping == st_var_3_2.damping);
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
}


