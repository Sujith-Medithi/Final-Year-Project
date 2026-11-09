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
struct EventLog_R001566_6613_0
{
  unsigned char severity;
  unsigned char code;
  unsigned char timestamp;
  int buffer[3];
};
struct Vector3D_R001566_6613_1
{
  unsigned char coord_y;
  int coord_z;
  int norm_sq;
  unsigned char heading;
  short pitch;
  int buffer[3];
};
union RegisterBank_R001566_6613_0
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
void fn_R001566_6613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001566_6613_1 st_1 = {0};
  struct Vector3D_R001566_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_87_1)
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

  switch (weight_87_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_87_1 == weight_87_2);
}

int fn_R001566_6613_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001566_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_87 = (aux + st.buffer[1]) & 3;
  switch (weight_87)
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

void fn_R001566_6613_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001566_6613_1 st_1 = {0};
  struct Vector3D_R001566_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int delta_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_68_1 > 16)
  {
    acc_1 = ((acc_1 + (delta_68_1 * 2)) + 5) & 127;
    aux_1 ^= delta_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_68_2 > 16)
  {
    acc_2 = ((acc_2 + (delta_68_2 * 2)) + 5) & 127;
    aux_2 ^= delta_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_68_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_88_1 = local_arr_1[aux_1 % 3];
  int vector_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_88_2 * 2)) & 127;
  int quantum_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_82_1) & 63;
  aux_2 = (aux_2 + quantum_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_68_1 == delta_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_88_1 == vector_88_2);
  assert(quantum_82_1 == quantum_82_2);
}

int fn_R001566_6613_1(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001566_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int delta_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_68 > 16)
  {
    acc = ((acc + (delta_68 * 2)) + 5) & 127;
    aux ^= delta_68 & 15;
  }
  else
  {
    acc = ((acc - delta_68) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_88 = local_arr[aux % 3];
  acc = (acc + (vector_88 * 2)) & 127;
  int quantum_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_82) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001566_6613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001566_6613_1 st_1 = {0};
  struct Vector3D_R001566_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int margin_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_21_1)
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

  switch (margin_21_2)
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

  int window_74_1 = 0;
  int window_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_74_1 = ((window_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_74_2 = ((window_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_74_1) & 127;
    acc_2 = (acc_2 + window_74_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_70_1 = local_arr_1[aux_1 % 3];
  int segment_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_70_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_21_1 == margin_21_2);
  assert(window_74_1 == window_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_70_1 == segment_70_2);
}

int fn_R001566_6613_2(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001566_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int margin_21 = (aux + st.buffer[1]) & 3;
  switch (margin_21)
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

  int window_74 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_74 = ((window_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_74) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int segment_70 = local_arr[aux % 3];
  acc = (acc + (segment_70 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001566_6613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001566_6613_0 st_1 = {0};
  struct EventLog_R001566_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int residue_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_74_1 > 32)
  {
    acc_1 = ((acc_1 + (residue_74_1 * 2)) + 5) & 127;
    aux_1 ^= residue_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_74_2 > 32)
  {
    acc_2 = ((acc_2 + (residue_74_2 * 2)) + 5) & 127;
    aux_2 ^= residue_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_38_1)
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

  switch (bound_38_2)
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
  int parity_43_1 = local_arr_1[aux_1 % 3];
  int parity_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_43_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_74_1 == residue_74_2);
  assert(bound_38_1 == bound_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_43_1 == parity_43_2);
}

int fn_R001566_6613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001566_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int residue_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_74 > 32)
  {
    acc = ((acc + (residue_74 * 2)) + 5) & 127;
    aux ^= residue_74 & 15;
  }
  else
  {
    acc = ((acc - residue_74) + 11) & 127;
    aux += 3;
  }
  int bound_38 = (aux + st.buffer[1]) & 3;
  switch (bound_38)
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
  int parity_43 = local_arr[aux % 3];
  acc = (acc + (parity_43 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001566_6613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001566_6613_0 st_1 = {0};
  struct EventLog_R001566_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int metric_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_73_1)
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

  switch (metric_73_2)
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

  int anchor_71_1 = 0;
  int anchor_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_71_1 = ((anchor_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_71_2 = ((anchor_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_71_1) & 127;
    acc_2 = (acc_2 + anchor_71_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_73_1 == metric_73_2);
  assert(anchor_71_1 == anchor_71_2);
}

int fn_R001566_6613_4(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001566_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int metric_73 = (aux + st.buffer[1]) & 3;
  switch (metric_73)
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

  int anchor_71 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_71 = ((anchor_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_71) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001566_6613_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001566_6613_0 st_1 = {0};
  struct EventLog_R001566_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_44_1 = 0;
  int weight_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_44_1 = ((weight_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_44_2 = ((weight_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_44_1) & 127;
    acc_2 = (acc_2 + weight_44_2) & 127;
  }

  int window_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_73_1) & 63;
  aux_2 = (aux_2 + window_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_44_1 == weight_44_2);
  assert(window_73_1 == window_73_2);
}

int fn_R001566_6613_5(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001566_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_44 = ((weight_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_44) & 127;
  }

  int window_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_73) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001566_6613_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001566_6613_0 st_1 = {0};
  struct EventLog_R001566_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_55_1 = local_arr_1[aux_1 % 3];
  int checksum_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_55_2 * 2)) & 127;
  int metric_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_72_1)
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

  switch (metric_72_2)
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

  int parity_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_15_1) & 63;
  aux_2 = (aux_2 + parity_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_55_1 == checksum_55_2);
  assert(metric_72_1 == metric_72_2);
  assert(parity_15_1 == parity_15_2);
}

int fn_R001566_6613_6(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001566_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int checksum_55 = local_arr[aux % 3];
  acc = (acc + (checksum_55 * 2)) & 127;
  int metric_72 = (aux + st.buffer[1]) & 3;
  switch (metric_72)
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

  int parity_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_15) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001566_6613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001566_6613_1 st_1 = {0};
  struct Vector3D_R001566_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_92_1 = local_arr_1[aux_1 % 3];
  int offset_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_92_2 * 2)) & 127;
  int weight_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_35_1) & 63;
  aux_2 = (aux_2 + weight_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
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

  assert(offset_92_1 == offset_92_2);
  assert(weight_35_1 == weight_35_2);
}

int fn_R001566_6613_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001566_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int offset_92 = local_arr[aux % 3];
  acc = (acc + (offset_92 * 2)) & 127;
  int weight_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001566_6613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001566_6613_1 st_1 = {0};
  struct Vector3D_R001566_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int metric_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_39_1 > 47)
  {
    acc_1 = ((acc_1 + (metric_39_1 * 2)) + 5) & 127;
    aux_1 ^= metric_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_39_2 > 47)
  {
    acc_2 = ((acc_2 + (metric_39_2 * 2)) + 5) & 127;
    aux_2 ^= metric_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_39_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_39_1 == metric_39_2);
}

int fn_R001566_6613_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001566_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int metric_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_39 > 47)
  {
    acc = ((acc + (metric_39 * 2)) + 5) & 127;
    aux ^= metric_39 & 15;
  }
  else
  {
    acc = ((acc - metric_39) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001566_6613_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001566_6613_1 st_1 = {0};
  struct Vector3D_R001566_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int accumulator_30_1 = 0;
  int accumulator_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_30_1 = ((accumulator_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_30_2 = ((accumulator_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_30_1) & 127;
    acc_2 = (acc_2 + accumulator_30_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_97_1 = local_arr_1[aux_1 % 3];
  int mask_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_97_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_30_1 == accumulator_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_97_1 == mask_97_2);
}

int fn_R001566_6613_9(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001566_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int accumulator_30 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_30 = ((accumulator_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_30) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int mask_97 = local_arr[aux % 3];
  acc = (acc + (mask_97 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001566_6613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001566_6613_0 st_1 = {0};
  struct EventLog_R001566_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int metric_58_1 = 0;
  int metric_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_58_1 = ((metric_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_58_2 = ((metric_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_58_1) & 127;
    acc_2 = (acc_2 + metric_58_2) & 127;
  }

  int phase_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_51_1) & 63;
  aux_2 = (aux_2 + phase_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_69_1 > 22)
  {
    acc_1 = ((acc_1 + (phase_69_1 * 2)) + 5) & 127;
    aux_1 ^= phase_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_69_2 > 22)
  {
    acc_2 = ((acc_2 + (phase_69_2 * 2)) + 5) & 127;
    aux_2 ^= phase_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_69_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_58_1 == metric_58_2);
  assert(phase_51_1 == phase_51_2);
  assert(phase_69_1 == phase_69_2);
}

int fn_R001566_6613_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001566_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int metric_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_58 = ((metric_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_58) & 127;
  }

  int phase_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_51) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_69 > 22)
  {
    acc = ((acc + (phase_69 * 2)) + 5) & 127;
    aux ^= phase_69 & 15;
  }
  else
  {
    acc = ((acc - phase_69) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001566_6613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001566_6613_0 st_1 = {0};
  struct EventLog_R001566_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int coefficient_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_21_1)
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

  switch (coefficient_21_2)
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

  int accumulator_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_79_1 > 24)
  {
    acc_1 = ((acc_1 + (accumulator_79_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_79_2 > 24)
  {
    acc_2 = ((acc_2 + (accumulator_79_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_79_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_97_1 = local_arr_1[aux_1 % 3];
  int anchor_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_97_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_21_1 == coefficient_21_2);
  assert(accumulator_79_1 == accumulator_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_97_1 == anchor_97_2);
}

int fn_R001566_6613_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001566_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int coefficient_21 = (aux + st.buffer[1]) & 3;
  switch (coefficient_21)
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

  int accumulator_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_79 > 24)
  {
    acc = ((acc + (accumulator_79 * 2)) + 5) & 127;
    aux ^= accumulator_79 & 15;
  }
  else
  {
    acc = ((acc - accumulator_79) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_97 = local_arr[aux % 3];
  acc = (acc + (anchor_97 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001566_6613_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001566_6613_0 st_1 = {0};
  struct EventLog_R001566_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int vector_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_35_1 > 28)
  {
    acc_1 = ((acc_1 + (vector_35_1 * 2)) + 5) & 127;
    aux_1 ^= vector_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_35_2 > 28)
  {
    acc_2 = ((acc_2 + (vector_35_2 * 2)) + 5) & 127;
    aux_2 ^= vector_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_19_1 = 0;
  int residue_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_19_1 = ((residue_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_19_2 = ((residue_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_19_1) & 127;
    acc_2 = (acc_2 + residue_19_2) & 127;
  }

  int metric_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_40_1) & 63;
  aux_2 = (aux_2 + metric_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_82_1 = local_arr_1[aux_1 % 3];
  int metric_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_35_1 == vector_35_2);
  assert(residue_19_1 == residue_19_2);
  assert(metric_40_1 == metric_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_82_1 == metric_82_2);
}

int fn_R001566_6613_12(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001566_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int vector_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_35 > 28)
  {
    acc = ((acc + (vector_35 * 2)) + 5) & 127;
    aux ^= vector_35 & 15;
  }
  else
  {
    acc = ((acc - vector_35) + 11) & 127;
    aux += 3;
  }
  int residue_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_19 = ((residue_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_19) & 127;
  }

  int metric_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_40) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int metric_82 = local_arr[aux % 3];
  acc = (acc + (metric_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001566_6613_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001566_6613_1 st_1 = {0};
  struct Vector3D_R001566_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_84_1)
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

  switch (mask_84_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_84_1 == mask_84_2);
}

int fn_R001566_6613_13(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001566_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_84 = (aux + st.buffer[1]) & 3;
  switch (mask_84)
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

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001566_0_1;
  int sec_r001566_0_2;
  int sec_r001566_1_1;
  int sec_r001566_1_2;
  int sec_r001566_2_1;
  int sec_r001566_2_2;
  int sec_r001566_3_1;
  int sec_r001566_3_2;
  int sec_r001566_4_1;
  int sec_r001566_4_2;
  int sec_r001566_5_1;
  int sec_r001566_5_2;
  int sec_r001566_6_1;
  int sec_r001566_6_2;
  int sec_r001566_7_1;
  int sec_r001566_7_2;
  int sec_r001566_8_1;
  int sec_r001566_8_2;
  int sec_r001566_9_1;
  int sec_r001566_9_2;
  int sec_r001566_10_1;
  int sec_r001566_10_2;
  int sec_r001566_11_1;
  int sec_r001566_11_2;
  int sec_r001566_12_1;
  int sec_r001566_12_2;
  int sec_r001566_13_1;
  int sec_r001566_13_2;
  int sec_r001566_14_1;
  int sec_r001566_14_2;
  int sec_r001566_15_1;
  int sec_r001566_15_2;
  int sec_r001566_16_1;
  int sec_r001566_16_2;
  int sec_r001566_17_1;
  int sec_r001566_17_2;
  int sec_r001566_18_1;
  int sec_r001566_18_2;
  int pub_r001566_0_1;
  int pub_r001566_0_2;
  int pub_r001566_1_1;
  int pub_r001566_1_2;
  int pub_r001566_2_1;
  int pub_r001566_2_2;
  int pub_r001566_3_1;
  int pub_r001566_3_2;
  int pub_r001566_4_1;
  int pub_r001566_4_2;
  int pub_r001566_5_1;
  int pub_r001566_5_2;
  int pub_r001566_6_1;
  int pub_r001566_6_2;
  int pub_r001566_7_1;
  int pub_r001566_7_2;
  int pub_r001566_8_1;
  int pub_r001566_8_2;
  int pub_r001566_9_1;
  int pub_r001566_9_2;
  int pub_r001566_10_1;
  int pub_r001566_10_2;
  int pub_r001566_11_1;
  int pub_r001566_11_2;
  int pub_r001566_12_1;
  int pub_r001566_12_2;
  int pub_r001566_13_1;
  int pub_r001566_13_2;
  int pub_r001566_14_1;
  int pub_r001566_14_2;
  int pub_r001566_15_1;
  int pub_r001566_15_2;
  int pub_r001566_16_1;
  int pub_r001566_16_2;
  int pub_r001566_17_1;
  int pub_r001566_17_2;
  int pub_r001566_18_1;
  int pub_r001566_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001566_0_1 >= (-100)) && (pub_r001566_0_1 <= 100));
  __CPROVER_assume((pub_r001566_0_2 >= (-100)) && (pub_r001566_0_2 <= 100));
  __CPROVER_assume((pub_r001566_1_1 >= (-100)) && (pub_r001566_1_1 <= 100));
  __CPROVER_assume((pub_r001566_1_2 >= (-100)) && (pub_r001566_1_2 <= 100));
  __CPROVER_assume((pub_r001566_2_1 >= (-100)) && (pub_r001566_2_1 <= 100));
  __CPROVER_assume((pub_r001566_2_2 >= (-100)) && (pub_r001566_2_2 <= 100));
  __CPROVER_assume((pub_r001566_3_1 >= (-100)) && (pub_r001566_3_1 <= 100));
  __CPROVER_assume((pub_r001566_3_2 >= (-100)) && (pub_r001566_3_2 <= 100));
  __CPROVER_assume((pub_r001566_4_1 >= (-100)) && (pub_r001566_4_1 <= 100));
  __CPROVER_assume((pub_r001566_4_2 >= (-100)) && (pub_r001566_4_2 <= 100));
  __CPROVER_assume((pub_r001566_5_1 >= (-100)) && (pub_r001566_5_1 <= 100));
  __CPROVER_assume((pub_r001566_5_2 >= (-100)) && (pub_r001566_5_2 <= 100));
  __CPROVER_assume((pub_r001566_6_1 >= (-100)) && (pub_r001566_6_1 <= 100));
  __CPROVER_assume((pub_r001566_6_2 >= (-100)) && (pub_r001566_6_2 <= 100));
  __CPROVER_assume((pub_r001566_7_1 >= (-100)) && (pub_r001566_7_1 <= 100));
  __CPROVER_assume((pub_r001566_7_2 >= (-100)) && (pub_r001566_7_2 <= 100));
  __CPROVER_assume((pub_r001566_8_1 >= (-100)) && (pub_r001566_8_1 <= 100));
  __CPROVER_assume((pub_r001566_8_2 >= (-100)) && (pub_r001566_8_2 <= 100));
  __CPROVER_assume((pub_r001566_9_1 >= (-100)) && (pub_r001566_9_1 <= 100));
  __CPROVER_assume((pub_r001566_9_2 >= (-100)) && (pub_r001566_9_2 <= 100));
  __CPROVER_assume((pub_r001566_10_1 >= (-100)) && (pub_r001566_10_1 <= 100));
  __CPROVER_assume((pub_r001566_10_2 >= (-100)) && (pub_r001566_10_2 <= 100));
  __CPROVER_assume((pub_r001566_11_1 >= (-100)) && (pub_r001566_11_1 <= 100));
  __CPROVER_assume((pub_r001566_11_2 >= (-100)) && (pub_r001566_11_2 <= 100));
  __CPROVER_assume((pub_r001566_12_1 >= (-100)) && (pub_r001566_12_1 <= 100));
  __CPROVER_assume((pub_r001566_12_2 >= (-100)) && (pub_r001566_12_2 <= 100));
  __CPROVER_assume((pub_r001566_13_1 >= (-100)) && (pub_r001566_13_1 <= 100));
  __CPROVER_assume((pub_r001566_13_2 >= (-100)) && (pub_r001566_13_2 <= 100));
  __CPROVER_assume((pub_r001566_14_1 >= (-100)) && (pub_r001566_14_1 <= 100));
  __CPROVER_assume((pub_r001566_14_2 >= (-100)) && (pub_r001566_14_2 <= 100));
  __CPROVER_assume((pub_r001566_15_1 >= (-100)) && (pub_r001566_15_1 <= 100));
  __CPROVER_assume((pub_r001566_15_2 >= (-100)) && (pub_r001566_15_2 <= 100));
  __CPROVER_assume((pub_r001566_16_1 >= (-100)) && (pub_r001566_16_1 <= 100));
  __CPROVER_assume((pub_r001566_16_2 >= (-100)) && (pub_r001566_16_2 <= 100));
  __CPROVER_assume((pub_r001566_17_1 >= (-100)) && (pub_r001566_17_1 <= 100));
  __CPROVER_assume((pub_r001566_17_2 >= (-100)) && (pub_r001566_17_2 <= 100));
  __CPROVER_assume((pub_r001566_18_1 >= (-100)) && (pub_r001566_18_1 <= 100));
  __CPROVER_assume((pub_r001566_18_2 >= (-100)) && (pub_r001566_18_2 <= 100));
  __CPROVER_assume((sec_r001566_0_1 >= 0) && (sec_r001566_0_1 <= 255));
  __CPROVER_assume((sec_r001566_0_2 >= 0) && (sec_r001566_0_2 <= 255));
  __CPROVER_assume((sec_r001566_1_1 >= 0) && (sec_r001566_1_1 <= 255));
  __CPROVER_assume((sec_r001566_1_2 >= 0) && (sec_r001566_1_2 <= 255));
  __CPROVER_assume((sec_r001566_2_1 >= 0) && (sec_r001566_2_1 <= 255));
  __CPROVER_assume((sec_r001566_2_2 >= 0) && (sec_r001566_2_2 <= 255));
  __CPROVER_assume((sec_r001566_3_1 >= 0) && (sec_r001566_3_1 <= 255));
  __CPROVER_assume((sec_r001566_3_2 >= 0) && (sec_r001566_3_2 <= 255));
  __CPROVER_assume((sec_r001566_4_1 >= 0) && (sec_r001566_4_1 <= 255));
  __CPROVER_assume((sec_r001566_4_2 >= 0) && (sec_r001566_4_2 <= 255));
  __CPROVER_assume((sec_r001566_5_1 >= 0) && (sec_r001566_5_1 <= 255));
  __CPROVER_assume((sec_r001566_5_2 >= 0) && (sec_r001566_5_2 <= 255));
  __CPROVER_assume((sec_r001566_6_1 >= 0) && (sec_r001566_6_1 <= 255));
  __CPROVER_assume((sec_r001566_6_2 >= 0) && (sec_r001566_6_2 <= 255));
  __CPROVER_assume((sec_r001566_7_1 >= 0) && (sec_r001566_7_1 <= 255));
  __CPROVER_assume((sec_r001566_7_2 >= 0) && (sec_r001566_7_2 <= 255));
  __CPROVER_assume((sec_r001566_8_1 >= 0) && (sec_r001566_8_1 <= 255));
  __CPROVER_assume((sec_r001566_8_2 >= 0) && (sec_r001566_8_2 <= 255));
  __CPROVER_assume((sec_r001566_9_1 >= 0) && (sec_r001566_9_1 <= 255));
  __CPROVER_assume((sec_r001566_9_2 >= 0) && (sec_r001566_9_2 <= 255));
  __CPROVER_assume((sec_r001566_10_1 >= 0) && (sec_r001566_10_1 <= 255));
  __CPROVER_assume((sec_r001566_10_2 >= 0) && (sec_r001566_10_2 <= 255));
  __CPROVER_assume((sec_r001566_11_1 >= 0) && (sec_r001566_11_1 <= 255));
  __CPROVER_assume((sec_r001566_11_2 >= 0) && (sec_r001566_11_2 <= 255));
  __CPROVER_assume((sec_r001566_12_1 >= 0) && (sec_r001566_12_1 <= 255));
  __CPROVER_assume((sec_r001566_12_2 >= 0) && (sec_r001566_12_2 <= 255));
  __CPROVER_assume((sec_r001566_13_1 >= 0) && (sec_r001566_13_1 <= 255));
  __CPROVER_assume((sec_r001566_13_2 >= 0) && (sec_r001566_13_2 <= 255));
  __CPROVER_assume((sec_r001566_14_1 >= 0) && (sec_r001566_14_1 <= 255));
  __CPROVER_assume((sec_r001566_14_2 >= 0) && (sec_r001566_14_2 <= 255));
  __CPROVER_assume((sec_r001566_15_1 >= 0) && (sec_r001566_15_1 <= 255));
  __CPROVER_assume((sec_r001566_15_2 >= 0) && (sec_r001566_15_2 <= 255));
  __CPROVER_assume((sec_r001566_16_1 >= 0) && (sec_r001566_16_1 <= 255));
  __CPROVER_assume((sec_r001566_16_2 >= 0) && (sec_r001566_16_2 <= 255));
  __CPROVER_assume((sec_r001566_17_1 >= 0) && (sec_r001566_17_1 <= 255));
  __CPROVER_assume((sec_r001566_17_2 >= 0) && (sec_r001566_17_2 <= 255));
  __CPROVER_assume((sec_r001566_18_1 >= 0) && (sec_r001566_18_1 <= 255));
  __CPROVER_assume((sec_r001566_18_2 >= 0) && (sec_r001566_18_2 <= 255));
  struct EventLog_R001566_6613_0 st_var_0_1 = {0};
  struct EventLog_R001566_6613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001566_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001566_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001566_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001566_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001566_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001566_0_2 + 7) & 15;
  struct Vector3D_R001566_6613_1 st_var_1_1 = {0};
  struct Vector3D_R001566_6613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001566_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001566_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001566_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001566_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001566_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001566_0_2 + 9) & 15;
  union RegisterBank_R001566_6613_0 u_var_1;
  union RegisterBank_R001566_6613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001566_6613_0(sec_r001566_0_1, sec_r001566_1_1, pub_r001566_2_1, pub_r001566_3_1, pub_r001566_4_1);
  int helper_flow_0_2 = fn_R001566_6613_0(sec_r001566_0_2, sec_r001566_1_2, pub_r001566_2_2, pub_r001566_3_2, pub_r001566_4_2);
  fn_R001566_6613_0_2(sec_r001566_0_1, sec_r001566_1_1, pub_r001566_2_1, pub_r001566_3_1, pub_r001566_4_1, sec_r001566_0_2, sec_r001566_1_2, pub_r001566_2_2, pub_r001566_3_2, pub_r001566_4_2);
  int helper_flow_1_1 = fn_R001566_6613_1(sec_r001566_1_1, sec_r001566_2_1, pub_r001566_3_1);
  int helper_flow_1_2 = fn_R001566_6613_1(sec_r001566_1_2, sec_r001566_2_2, pub_r001566_3_2);
  fn_R001566_6613_1_2(sec_r001566_1_1, sec_r001566_2_1, pub_r001566_3_1, sec_r001566_1_2, sec_r001566_2_2, pub_r001566_3_2);
  int helper_flow_2_1 = fn_R001566_6613_2(sec_r001566_2_1, pub_r001566_3_1);
  int helper_flow_2_2 = fn_R001566_6613_2(sec_r001566_2_2, pub_r001566_3_2);
  fn_R001566_6613_2_2(sec_r001566_2_1, pub_r001566_3_1, sec_r001566_2_2, pub_r001566_3_2);
  int helper_flow_3_1 = fn_R001566_6613_3(sec_r001566_3_1, sec_r001566_4_1, pub_r001566_5_1, pub_r001566_6_1);
  int helper_flow_3_2 = fn_R001566_6613_3(sec_r001566_3_2, sec_r001566_4_2, pub_r001566_5_2, pub_r001566_6_2);
  fn_R001566_6613_3_2(sec_r001566_3_1, sec_r001566_4_1, pub_r001566_5_1, pub_r001566_6_1, sec_r001566_3_2, sec_r001566_4_2, pub_r001566_5_2, pub_r001566_6_2);
  int helper_flow_4_1 = fn_R001566_6613_4(sec_r001566_4_1, pub_r001566_5_1);
  int helper_flow_4_2 = fn_R001566_6613_4(sec_r001566_4_2, pub_r001566_5_2);
  fn_R001566_6613_4_2(sec_r001566_4_1, pub_r001566_5_1, sec_r001566_4_2, pub_r001566_5_2);
  int helper_flow_5_1 = fn_R001566_6613_5(sec_r001566_5_1, pub_r001566_6_1);
  int helper_flow_5_2 = fn_R001566_6613_5(sec_r001566_5_2, pub_r001566_6_2);
  fn_R001566_6613_5_2(sec_r001566_5_1, pub_r001566_6_1, sec_r001566_5_2, pub_r001566_6_2);
  int helper_flow_6_1 = fn_R001566_6613_6(sec_r001566_6_1, pub_r001566_7_1, pub_r001566_8_1);
  int helper_flow_6_2 = fn_R001566_6613_6(sec_r001566_6_2, pub_r001566_7_2, pub_r001566_8_2);
  fn_R001566_6613_6_2(sec_r001566_6_1, pub_r001566_7_1, pub_r001566_8_1, sec_r001566_6_2, pub_r001566_7_2, pub_r001566_8_2);
  int helper_flow_7_1 = fn_R001566_6613_7(sec_r001566_7_1, sec_r001566_8_1, pub_r001566_9_1, pub_r001566_10_1, pub_r001566_11_1);
  int helper_flow_7_2 = fn_R001566_6613_7(sec_r001566_7_2, sec_r001566_8_2, pub_r001566_9_2, pub_r001566_10_2, pub_r001566_11_2);
  fn_R001566_6613_7_2(sec_r001566_7_1, sec_r001566_8_1, pub_r001566_9_1, pub_r001566_10_1, pub_r001566_11_1, sec_r001566_7_2, sec_r001566_8_2, pub_r001566_9_2, pub_r001566_10_2, pub_r001566_11_2);
  int helper_flow_8_1 = fn_R001566_6613_8(sec_r001566_8_1, sec_r001566_9_1, pub_r001566_10_1, pub_r001566_11_1);
  int helper_flow_8_2 = fn_R001566_6613_8(sec_r001566_8_2, sec_r001566_9_2, pub_r001566_10_2, pub_r001566_11_2);
  fn_R001566_6613_8_2(sec_r001566_8_1, sec_r001566_9_1, pub_r001566_10_1, pub_r001566_11_1, sec_r001566_8_2, sec_r001566_9_2, pub_r001566_10_2, pub_r001566_11_2);
  int stage_v_0_1 = ((helper_flow_5_1 + (pub_r001566_4_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_5_2 + (pub_r001566_4_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((sec_r001566_4_1 + (pub_r001566_14_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001566_4_2 + (pub_r001566_14_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((helper_flow_2_1 + (pub_r001566_5_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((helper_flow_2_2 + (pub_r001566_5_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((stage_v_1_1 + (pub_r001566_16_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((stage_v_1_2 + (pub_r001566_16_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((helper_flow_7_1 + (pub_r001566_15_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((helper_flow_7_2 + (pub_r001566_15_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((pub_r001566_1_1 * 2) + 28) & 63;
  int stage_v_5_2 = ((pub_r001566_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((helper_flow_8_1 + (pub_r001566_0_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((helper_flow_8_2 + (pub_r001566_0_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((sec_r001566_10_1 + (pub_r001566_17_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((sec_r001566_10_2 + (pub_r001566_17_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((sec_r001566_0_1 + (pub_r001566_14_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((sec_r001566_0_2 + (pub_r001566_14_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((sec_r001566_12_1 + (pub_r001566_0_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((sec_r001566_12_2 + (pub_r001566_0_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((pub_r001566_9_1 * 2) + 33) & 63;
  int stage_v_10_2 = ((pub_r001566_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001566_5_1 * 2) + 9) & 63;
  int stage_v_11_2 = ((pub_r001566_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001566_2_1 * 2) + 13) & 63;
  int stage_v_12_2 = ((pub_r001566_2_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((helper_flow_4_1 + (pub_r001566_18_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((helper_flow_4_2 + (pub_r001566_18_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((helper_flow_4_1 + (pub_r001566_13_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((helper_flow_4_2 + (pub_r001566_13_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((stage_v_2_1 + (pub_r001566_5_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((stage_v_2_2 + (pub_r001566_5_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((stage_v_2_1 + (pub_r001566_8_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((stage_v_2_2 + (pub_r001566_8_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((stage_v_15_1 + (pub_r001566_11_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((stage_v_15_2 + (pub_r001566_11_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((pub_r001566_5_1 * 2) + 17) & 63;
  int stage_v_18_2 = ((pub_r001566_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((helper_flow_1_1 + (pub_r001566_18_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((helper_flow_1_2 + (pub_r001566_18_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((pub_r001566_2_1 * 2) + 11) & 63;
  int stage_v_20_2 = ((pub_r001566_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((helper_flow_6_1 + (pub_r001566_14_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((helper_flow_6_2 + (pub_r001566_14_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((sec_r001566_2_1 + (pub_r001566_8_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((sec_r001566_2_2 + (pub_r001566_8_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((pub_r001566_5_1 * 2) + 26) & 63;
  int stage_v_23_2 = ((pub_r001566_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((sec_r001566_0_1 + (pub_r001566_17_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((sec_r001566_0_2 + (pub_r001566_17_2 * 2)) + 77) & 127;
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
  int stage_v_25_1 = ((sec_r001566_18_1 + (pub_r001566_2_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((sec_r001566_18_2 + (pub_r001566_2_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((stage_v_9_1 + (pub_r001566_13_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((stage_v_9_2 + (pub_r001566_13_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((stage_v_7_1 + (pub_r001566_4_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((stage_v_7_2 + (pub_r001566_4_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((sec_r001566_11_1 + (pub_r001566_4_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((sec_r001566_11_2 + (pub_r001566_4_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((sec_r001566_5_1 + (pub_r001566_6_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001566_5_2 + (pub_r001566_6_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((helper_flow_6_1 + (pub_r001566_8_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((helper_flow_6_2 + (pub_r001566_8_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((pub_r001566_6_1 * 2) + 27) & 63;
  int stage_v_31_2 = ((pub_r001566_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((helper_flow_1_1 + (pub_r001566_10_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((helper_flow_1_2 + (pub_r001566_10_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((stage_v_21_1 + (pub_r001566_3_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((stage_v_21_2 + (pub_r001566_3_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((stage_v_6_1 + (pub_r001566_13_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((stage_v_6_2 + (pub_r001566_13_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((stage_v_27_1 + (pub_r001566_16_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((stage_v_27_2 + (pub_r001566_16_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((helper_flow_5_1 + (pub_r001566_2_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((helper_flow_5_2 + (pub_r001566_2_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((stage_v_21_1 + (pub_r001566_8_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((stage_v_21_2 + (pub_r001566_8_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((pub_r001566_6_1 * 2) + 23) & 63;
  int stage_v_38_2 = ((pub_r001566_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001566_5_1 * 2) + 37) & 63;
  int stage_v_39_2 = ((pub_r001566_5_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((sec_r001566_16_1 + (pub_r001566_16_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((sec_r001566_16_2 + (pub_r001566_16_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((stage_v_2_1 + (pub_r001566_6_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((stage_v_2_2 + (pub_r001566_6_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((pub_r001566_2_1 * 2) + 39) & 63;
  int stage_v_42_2 = ((pub_r001566_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((stage_v_29_1 + (pub_r001566_14_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((stage_v_29_2 + (pub_r001566_14_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((pub_r001566_7_1 * 2) + 38) & 63;
  int stage_v_44_2 = ((pub_r001566_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((stage_v_24_1 + (pub_r001566_3_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((stage_v_24_2 + (pub_r001566_3_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((sec_r001566_18_1 + (pub_r001566_18_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((sec_r001566_18_2 + (pub_r001566_18_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((sec_r001566_7_1 + (pub_r001566_13_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((sec_r001566_7_2 + (pub_r001566_13_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((stage_v_41_1 + (pub_r001566_14_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((stage_v_41_2 + (pub_r001566_14_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((stage_v_24_1 + (pub_r001566_4_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((stage_v_24_2 + (pub_r001566_4_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((helper_flow_7_1 + (pub_r001566_15_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((helper_flow_7_2 + (pub_r001566_15_2 * 2)) + 155) & 127;
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
  int stage_v_51_1 = ((stage_v_43_1 + (pub_r001566_16_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((stage_v_43_2 + (pub_r001566_16_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((pub_r001566_13_1 * 2) + 18) & 63;
  int stage_v_52_2 = ((pub_r001566_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((stage_v_27_1 + (pub_r001566_13_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((stage_v_27_2 + (pub_r001566_13_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((stage_v_17_1 + (pub_r001566_5_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((stage_v_17_2 + (pub_r001566_5_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((stage_v_33_1 + (pub_r001566_18_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((stage_v_33_2 + (pub_r001566_18_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((sec_r001566_16_1 + (pub_r001566_14_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((sec_r001566_16_2 + (pub_r001566_14_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((sec_r001566_2_1 + (pub_r001566_1_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((sec_r001566_2_2 + (pub_r001566_1_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((pub_r001566_6_1 * 2) + 33) & 63;
  int stage_v_58_2 = ((pub_r001566_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((stage_v_57_1 + (pub_r001566_4_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((stage_v_57_2 + (pub_r001566_4_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((stage_v_28_1 + (pub_r001566_15_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_28_2 + (pub_r001566_15_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((stage_v_4_1 + (pub_r001566_10_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((stage_v_4_2 + (pub_r001566_10_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((stage_v_14_1 + (pub_r001566_14_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((stage_v_14_2 + (pub_r001566_14_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((stage_v_21_1 + (pub_r001566_9_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_21_2 + (pub_r001566_9_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((sec_r001566_2_1 + (pub_r001566_15_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((sec_r001566_2_2 + (pub_r001566_15_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((stage_v_64_1 + (pub_r001566_18_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_64_2 + (pub_r001566_18_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((sec_r001566_17_1 + (pub_r001566_8_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((sec_r001566_17_2 + (pub_r001566_8_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((pub_r001566_14_1 * 2) + 19) & 63;
  int stage_v_67_2 = ((pub_r001566_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001566_10_1 * 2) + 8) & 63;
  int stage_v_68_2 = ((pub_r001566_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((stage_v_49_1 + (pub_r001566_18_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((stage_v_49_2 + (pub_r001566_18_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((stage_v_62_1 + (pub_r001566_0_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_62_2 + (pub_r001566_0_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((stage_v_60_1 + (pub_r001566_4_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_60_2 + (pub_r001566_4_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((stage_v_2_1 + (pub_r001566_4_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((stage_v_2_2 + (pub_r001566_4_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((stage_v_15_1 + (pub_r001566_15_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_15_2 + (pub_r001566_15_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((stage_v_41_1 + (pub_r001566_3_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_41_2 + (pub_r001566_3_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((stage_v_36_1 + (pub_r001566_13_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_36_2 + (pub_r001566_13_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((stage_v_47_1 + (pub_r001566_11_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((stage_v_47_2 + (pub_r001566_11_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((sec_r001566_13_1 + (pub_r001566_4_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((sec_r001566_13_2 + (pub_r001566_4_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((helper_flow_3_1 + (pub_r001566_17_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((helper_flow_3_2 + (pub_r001566_17_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((sec_r001566_3_1 + (pub_r001566_14_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((sec_r001566_3_2 + (pub_r001566_14_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((stage_v_21_1 + (pub_r001566_13_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_21_2 + (pub_r001566_13_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((pub_r001566_5_1 * 2) + 44) & 63;
  int stage_v_81_2 = ((pub_r001566_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((stage_v_17_1 + (pub_r001566_6_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((stage_v_17_2 + (pub_r001566_6_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((stage_v_56_1 + (pub_r001566_0_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_56_2 + (pub_r001566_0_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((pub_r001566_10_1 * 2) + 8) & 63;
  int stage_v_84_2 = ((pub_r001566_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((stage_v_0_1 + (pub_r001566_13_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_0_2 + (pub_r001566_13_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((pub_r001566_9_1 * 2) + 24) & 63;
  int stage_v_86_2 = ((pub_r001566_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((stage_v_15_1 + (pub_r001566_18_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_15_2 + (pub_r001566_18_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((sec_r001566_6_1 + (pub_r001566_14_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((sec_r001566_6_2 + (pub_r001566_14_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((pub_r001566_9_1 * 2) + 37) & 63;
  int stage_v_89_2 = ((pub_r001566_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001566_12_1 * 2) + 38) & 63;
  int stage_v_90_2 = ((pub_r001566_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((stage_v_48_1 + (pub_r001566_5_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_48_2 + (pub_r001566_5_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((sec_r001566_13_1 + (pub_r001566_0_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((sec_r001566_13_2 + (pub_r001566_0_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((stage_v_41_1 + (pub_r001566_2_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_41_2 + (pub_r001566_2_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((helper_flow_3_1 + (pub_r001566_3_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((helper_flow_3_2 + (pub_r001566_3_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((helper_flow_5_1 + (pub_r001566_13_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((helper_flow_5_2 + (pub_r001566_13_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((sec_r001566_2_1 + (pub_r001566_0_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((sec_r001566_2_2 + (pub_r001566_0_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((sec_r001566_0_1 + (pub_r001566_17_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((sec_r001566_0_2 + (pub_r001566_17_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((pub_r001566_13_1 * 2) + 37) & 63;
  int stage_v_98_2 = ((pub_r001566_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((sec_r001566_8_1 + (pub_r001566_17_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((sec_r001566_8_2 + (pub_r001566_17_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((pub_r001566_0_1 * 2) + 40) & 63;
  int stage_v_100_2 = ((pub_r001566_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001566_15_1 * 2) + 28) & 63;
  int stage_v_101_2 = ((pub_r001566_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001566_3_1 * 2) + 44) & 63;
  int stage_v_102_2 = ((pub_r001566_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((stage_v_64_1 + (pub_r001566_16_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_64_2 + (pub_r001566_16_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((pub_r001566_4_1 * 2) + 47) & 63;
  int stage_v_104_2 = ((pub_r001566_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001566_4_1 * 2) + 35) & 63;
  int stage_v_105_2 = ((pub_r001566_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((stage_v_78_1 + (pub_r001566_2_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_78_2 + (pub_r001566_2_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((sec_r001566_14_1 + (pub_r001566_13_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((sec_r001566_14_2 + (pub_r001566_13_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((stage_v_49_1 + (pub_r001566_14_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_49_2 + (pub_r001566_14_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((sec_r001566_7_1 + (pub_r001566_2_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((sec_r001566_7_2 + (pub_r001566_2_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((stage_v_69_1 + (pub_r001566_16_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((stage_v_69_2 + (pub_r001566_16_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((stage_v_60_1 + (pub_r001566_17_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_60_2 + (pub_r001566_17_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((pub_r001566_12_1 * 2) + 42) & 63;
  int stage_v_112_2 = ((pub_r001566_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((stage_v_92_1 + (pub_r001566_7_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((stage_v_92_2 + (pub_r001566_7_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((helper_flow_2_1 + (pub_r001566_7_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((helper_flow_2_2 + (pub_r001566_7_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((stage_v_3_1 + (pub_r001566_15_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_3_2 + (pub_r001566_15_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((sec_r001566_8_1 + (pub_r001566_1_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((sec_r001566_8_2 + (pub_r001566_1_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((stage_v_82_1 + (pub_r001566_12_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((stage_v_82_2 + (pub_r001566_12_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((sec_r001566_14_1 + (pub_r001566_7_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((sec_r001566_14_2 + (pub_r001566_7_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((stage_v_80_1 + (pub_r001566_5_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_80_2 + (pub_r001566_5_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((stage_v_108_1 + (pub_r001566_15_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_108_2 + (pub_r001566_15_2 * 2)) + 365) & 127;
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
  int stage_v_121_1 = ((stage_v_64_1 + (pub_r001566_12_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_64_2 + (pub_r001566_12_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((pub_r001566_10_1 * 2) + 33) & 63;
  int stage_v_122_2 = ((pub_r001566_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((helper_flow_1_1 + (pub_r001566_16_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((helper_flow_1_2 + (pub_r001566_16_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((pub_r001566_10_1 * 2) + 6) & 63;
  int stage_v_124_2 = ((pub_r001566_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_88_1 + (pub_r001566_0_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_88_2 + (pub_r001566_0_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((pub_r001566_1_1 * 2) + 22) & 63;
  int stage_v_126_2 = ((pub_r001566_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((sec_r001566_6_1 + (pub_r001566_3_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((sec_r001566_6_2 + (pub_r001566_3_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((pub_r001566_4_1 * 2) + 18) & 63;
  int stage_v_128_2 = ((pub_r001566_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((stage_v_119_1 + (pub_r001566_14_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_119_2 + (pub_r001566_14_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((pub_r001566_1_1 * 2) + 23) & 63;
  int stage_v_130_2 = ((pub_r001566_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((sec_r001566_17_1 + (pub_r001566_4_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((sec_r001566_17_2 + (pub_r001566_4_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((sec_r001566_9_1 + (pub_r001566_8_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((sec_r001566_9_2 + (pub_r001566_8_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((stage_v_62_1 + (pub_r001566_7_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_62_2 + (pub_r001566_7_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((stage_v_79_1 + (pub_r001566_6_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_79_2 + (pub_r001566_6_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((stage_v_120_1 + (pub_r001566_5_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_120_2 + (pub_r001566_5_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((sec_r001566_14_1 + (pub_r001566_17_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((sec_r001566_14_2 + (pub_r001566_17_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_56_1 + (pub_r001566_6_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_56_2 + (pub_r001566_6_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((pub_r001566_14_1 * 2) + 29) & 63;
  int stage_v_138_2 = ((pub_r001566_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((sec_r001566_13_1 + (pub_r001566_3_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((sec_r001566_13_2 + (pub_r001566_3_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((stage_v_139_1 + (pub_r001566_10_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_139_2 + (pub_r001566_10_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((pub_r001566_16_1 * 2) + 18) & 63;
  int stage_v_141_2 = ((pub_r001566_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001566_12_1 * 2) + 42) & 63;
  int stage_v_142_2 = ((pub_r001566_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((stage_v_17_1 + (pub_r001566_17_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_17_2 + (pub_r001566_17_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((stage_v_116_1 + (pub_r001566_8_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_116_2 + (pub_r001566_8_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((stage_v_65_1 + (pub_r001566_15_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_65_2 + (pub_r001566_15_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((stage_v_106_1 + (pub_r001566_4_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_106_2 + (pub_r001566_4_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((stage_v_26_1 + (pub_r001566_11_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_26_2 + (pub_r001566_11_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((stage_v_32_1 + (pub_r001566_7_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_32_2 + (pub_r001566_7_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((sec_r001566_1_1 + (pub_r001566_15_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((sec_r001566_1_2 + (pub_r001566_15_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((stage_v_43_1 + (pub_r001566_16_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_43_2 + (pub_r001566_16_2 * 2)) + 455) & 127;
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
  int stage_v_151_1 = ((pub_r001566_8_1 * 2) + 18) & 63;
  int stage_v_151_2 = ((pub_r001566_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001566_5_1 * 2) + 46) & 63;
  int stage_v_152_2 = ((pub_r001566_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001566_9_1 * 2) + 34) & 63;
  int stage_v_153_2 = ((pub_r001566_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001566_1_1 * 2) + 5) & 63;
  int stage_v_154_2 = ((pub_r001566_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((sec_r001566_9_1 + (pub_r001566_8_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((sec_r001566_9_2 + (pub_r001566_8_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((stage_v_27_1 + (pub_r001566_6_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_27_2 + (pub_r001566_6_2 * 2)) + 473) & 127;
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
  int stage_v_157_1 = ((stage_v_87_1 + (pub_r001566_13_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_87_2 + (pub_r001566_13_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((sec_r001566_10_1 + (pub_r001566_10_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((sec_r001566_10_2 + (pub_r001566_10_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((stage_v_109_1 + (pub_r001566_4_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_109_2 + (pub_r001566_4_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_26_1 + (pub_r001566_15_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_26_2 + (pub_r001566_15_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((stage_v_143_1 + (pub_r001566_4_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_143_2 + (pub_r001566_4_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((sec_r001566_13_1 + (pub_r001566_14_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((sec_r001566_13_2 + (pub_r001566_14_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((pub_r001566_2_1 * 2) + 27) & 63;
  int stage_v_163_2 = ((pub_r001566_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_75_1 + (pub_r001566_1_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_75_2 + (pub_r001566_1_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((pub_r001566_17_1 * 2) + 6) & 63;
  int stage_v_165_2 = ((pub_r001566_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((sec_r001566_7_1 + (pub_r001566_11_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((sec_r001566_7_2 + (pub_r001566_11_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((stage_v_51_1 + (pub_r001566_2_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_51_2 + (pub_r001566_2_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_26_1 + (pub_r001566_16_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_26_2 + (pub_r001566_16_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((pub_r001566_14_1 * 2) + 21) & 63;
  int stage_v_169_2 = ((pub_r001566_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001566_6_1 * 2) + 16) & 63;
  int stage_v_170_2 = ((pub_r001566_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001566_6_1 * 2) + 38) & 63;
  int stage_v_171_2 = ((pub_r001566_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_75_1 + (pub_r001566_6_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_75_2 + (pub_r001566_6_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((pub_r001566_12_1 * 2) + 10) & 63;
  int stage_v_173_2 = ((pub_r001566_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((stage_v_144_1 + (pub_r001566_18_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_144_2 + (pub_r001566_18_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((pub_r001566_4_1 * 2) + 8) & 63;
  int stage_v_175_2 = ((pub_r001566_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001566_9_1 * 2) + 16) & 63;
  int stage_v_176_2 = ((pub_r001566_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001566_4_1 * 2) + 41) & 63;
  int stage_v_177_2 = ((pub_r001566_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001566_18_1 * 2) + 24) & 63;
  int stage_v_178_2 = ((pub_r001566_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((stage_v_29_1 + (pub_r001566_4_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_29_2 + (pub_r001566_4_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((pub_r001566_13_1 * 2) + 32) & 63;
  int stage_v_180_2 = ((pub_r001566_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((stage_v_19_1 + (pub_r001566_17_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_19_2 + (pub_r001566_17_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((pub_r001566_1_1 * 2) + 36) & 63;
  int stage_v_182_2 = ((pub_r001566_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((stage_v_179_1 + (pub_r001566_13_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_179_2 + (pub_r001566_13_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((helper_flow_7_1 + (pub_r001566_18_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((helper_flow_7_2 + (pub_r001566_18_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_111_1 + (pub_r001566_4_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_111_2 + (pub_r001566_4_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((pub_r001566_18_1 * 2) + 8) & 63;
  int stage_v_186_2 = ((pub_r001566_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((stage_v_96_1 + (pub_r001566_18_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_96_2 + (pub_r001566_18_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001566_17_1 * 2) + 16) & 63;
  int stage_v_188_2 = ((pub_r001566_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((stage_v_127_1 + (pub_r001566_0_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_127_2 + (pub_r001566_0_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((pub_r001566_4_1 * 2) + 9) & 63;
  int stage_v_190_2 = ((pub_r001566_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001566_10_1 * 2) + 34) & 63;
  int stage_v_191_2 = ((pub_r001566_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((stage_v_16_1 + (pub_r001566_14_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_16_2 + (pub_r001566_14_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((stage_v_157_1 + (pub_r001566_8_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_157_2 + (pub_r001566_8_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((pub_r001566_3_1 * 2) + 13) & 63;
  int stage_v_194_2 = ((pub_r001566_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001566_1_1 * 2) + 18) & 63;
  int stage_v_195_2 = ((pub_r001566_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001566_2_1 * 2) + 40) & 63;
  int stage_v_196_2 = ((pub_r001566_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001566_13_1 * 2) + 40) & 63;
  int stage_v_197_2 = ((pub_r001566_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((helper_flow_6_1 + (pub_r001566_16_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((helper_flow_6_2 + (pub_r001566_16_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_166_1 + (pub_r001566_3_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_166_2 + (pub_r001566_3_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_63_1 + (pub_r001566_17_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_63_2 + (pub_r001566_17_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((stage_v_157_1 + (pub_r001566_17_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_157_2 + (pub_r001566_17_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_71_1 + (pub_r001566_15_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_71_2 + (pub_r001566_15_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((stage_v_57_1 + (pub_r001566_3_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((stage_v_57_2 + (pub_r001566_3_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((stage_v_36_1 + (pub_r001566_16_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_36_2 + (pub_r001566_16_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((stage_v_116_1 + (pub_r001566_14_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_116_2 + (pub_r001566_14_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((pub_r001566_17_1 * 2) + 12) & 63;
  int stage_v_206_2 = ((pub_r001566_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((sec_r001566_12_1 + (pub_r001566_18_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((sec_r001566_12_2 + (pub_r001566_18_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((stage_v_59_1 + (pub_r001566_8_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_59_2 + (pub_r001566_8_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((stage_v_103_1 + (pub_r001566_13_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_103_2 + (pub_r001566_13_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((stage_v_172_1 + (pub_r001566_13_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((stage_v_172_2 + (pub_r001566_13_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((stage_v_103_1 + (pub_r001566_10_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((stage_v_103_2 + (pub_r001566_10_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((pub_r001566_14_1 * 2) + 40) & 63;
  int stage_v_212_2 = ((pub_r001566_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((stage_v_26_1 + (pub_r001566_8_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((stage_v_26_2 + (pub_r001566_8_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((pub_r001566_9_1 * 2) + 37) & 63;
  int stage_v_214_2 = ((pub_r001566_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001566_14_1 * 2) + 21) & 63;
  int stage_v_215_2 = ((pub_r001566_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001566_11_1 * 2) + 50) & 63;
  int stage_v_216_2 = ((pub_r001566_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((stage_v_51_1 + (pub_r001566_13_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_51_2 + (pub_r001566_13_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((pub_r001566_5_1 * 2) + 23) & 63;
  int stage_v_218_2 = ((pub_r001566_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((sec_r001566_16_1 + (pub_r001566_14_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((sec_r001566_16_2 + (pub_r001566_14_2 * 2)) + 662) & 127;
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
  int stage_v_220_1 = ((stage_v_94_1 + (pub_r001566_11_1 * 2)) + 665) & 127;
  int stage_v_220_2 = ((stage_v_94_2 + (pub_r001566_11_2 * 2)) + 665) & 127;
  if (stage_v_220_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_220_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_220_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_220_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_221_1 = ((stage_v_95_1 + (pub_r001566_4_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((stage_v_95_2 + (pub_r001566_4_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((stage_v_16_1 + (pub_r001566_17_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_16_2 + (pub_r001566_17_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((stage_v_183_1 + (pub_r001566_4_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_183_2 + (pub_r001566_4_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((pub_r001566_7_1 * 2) + 33) & 63;
  int stage_v_224_2 = ((pub_r001566_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((stage_v_74_1 + (pub_r001566_14_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_74_2 + (pub_r001566_14_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_226_1 = ((pub_r001566_10_1 * 2) + 5) & 63;
  int stage_v_226_2 = ((pub_r001566_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((stage_v_65_1 + (pub_r001566_9_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((stage_v_65_2 + (pub_r001566_9_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_228_1 = ((pub_r001566_13_1 * 2) + 10) & 63;
  int stage_v_228_2 = ((pub_r001566_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((sec_r001566_5_1 + (pub_r001566_0_1 * 2)) + 692) & 127;
  int stage_v_229_2 = ((sec_r001566_5_2 + (pub_r001566_0_2 * 2)) + 692) & 127;
  if (stage_v_229_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_229_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_229_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_229_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_230_1 = ((stage_v_34_1 + (pub_r001566_8_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((stage_v_34_2 + (pub_r001566_8_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_231_1 = ((stage_v_99_1 + (pub_r001566_12_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((stage_v_99_2 + (pub_r001566_12_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((stage_v_167_1 + (pub_r001566_14_1 * 2)) + 701) & 127;
  int stage_v_232_2 = ((stage_v_167_2 + (pub_r001566_14_2 * 2)) + 701) & 127;
  if (stage_v_232_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_232_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_232_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_232_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_233_1 = ((stage_v_189_1 + (pub_r001566_6_1 * 2)) + 704) & 127;
  int stage_v_233_2 = ((stage_v_189_2 + (pub_r001566_6_2 * 2)) + 704) & 127;
  if (stage_v_233_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_233_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_233_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_233_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_234_1 = ((stage_v_232_1 + (pub_r001566_0_1 * 2)) + 707) & 127;
  int stage_v_234_2 = ((stage_v_232_2 + (pub_r001566_0_2 * 2)) + 707) & 127;
  if (stage_v_234_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_234_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_234_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_234_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_235_1 = ((stage_v_48_1 + (pub_r001566_0_1 * 2)) + 710) & 127;
  int stage_v_235_2 = ((stage_v_48_2 + (pub_r001566_0_2 * 2)) + 710) & 127;
  if (stage_v_235_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_235_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_235_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_235_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_236_1 = ((pub_r001566_16_1 * 2) + 23) & 63;
  int stage_v_236_2 = ((pub_r001566_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001566_17_1 * 2) + 38) & 63;
  int stage_v_237_2 = ((pub_r001566_17_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((stage_v_15_1 + (pub_r001566_7_1 * 2)) + 719) & 127;
  int stage_v_238_2 = ((stage_v_15_2 + (pub_r001566_7_2 * 2)) + 719) & 127;
  if (stage_v_238_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_238_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_238_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_238_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_238_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_238_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_238_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_238_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_239_1 = ((stage_v_77_1 + (pub_r001566_3_1 * 2)) + 722) & 127;
  int stage_v_239_2 = ((stage_v_77_2 + (pub_r001566_3_2 * 2)) + 722) & 127;
  if (stage_v_239_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_239_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_239_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_239_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_240_1 = ((stage_v_93_1 + (pub_r001566_17_1 * 2)) + 725) & 127;
  int stage_v_240_2 = ((stage_v_93_2 + (pub_r001566_17_2 * 2)) + 725) & 127;
  if (stage_v_240_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_240_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_240_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_240_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_241_1 = ((stage_v_91_1 + (pub_r001566_18_1 * 2)) + 728) & 127;
  int stage_v_241_2 = ((stage_v_91_2 + (pub_r001566_18_2 * 2)) + 728) & 127;
  if (stage_v_241_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_241_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_241_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_241_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_242_1 = ((stage_v_203_1 + (pub_r001566_4_1 * 2)) + 731) & 127;
  int stage_v_242_2 = ((stage_v_203_2 + (pub_r001566_4_2 * 2)) + 731) & 127;
  if (stage_v_242_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_242_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_242_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_242_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_243_1 = ((stage_v_174_1 + (pub_r001566_11_1 * 2)) + 734) & 127;
  int stage_v_243_2 = ((stage_v_174_2 + (pub_r001566_11_2 * 2)) + 734) & 127;
  if (stage_v_243_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_243_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_243_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_243_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_243_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_243_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_243_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_243_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_244_1 = ((stage_v_78_1 + (pub_r001566_3_1 * 2)) + 737) & 127;
  int stage_v_244_2 = ((stage_v_78_2 + (pub_r001566_3_2 * 2)) + 737) & 127;
  if (stage_v_244_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_244_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_244_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_244_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_244_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_244_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_244_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_244_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_245_1 = ((stage_v_119_1 + (pub_r001566_5_1 * 2)) + 740) & 127;
  int stage_v_245_2 = ((stage_v_119_2 + (pub_r001566_5_2 * 2)) + 740) & 127;
  if (stage_v_245_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_245_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_245_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_245_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_245_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_245_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_245_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_245_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_246_1 = ((stage_v_172_1 + (pub_r001566_10_1 * 2)) + 743) & 127;
  int stage_v_246_2 = ((stage_v_172_2 + (pub_r001566_10_2 * 2)) + 743) & 127;
  if (stage_v_246_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_246_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_246_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_246_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_247_1 = ((pub_r001566_10_1 * 2) + 43) & 63;
  int stage_v_247_2 = ((pub_r001566_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001566_5_1 == pub_r001566_5_2);
  __CPROVER_assume(pub_r001566_2_1 == pub_r001566_2_2);
  __CPROVER_assume(sec_r001566_17_1 != sec_r001566_17_2);
  __CPROVER_assume(pub_r001566_16_1 == pub_r001566_16_2);
  __CPROVER_assume(pub_r001566_7_1 == pub_r001566_7_2);
  __CPROVER_assume(pub_r001566_1_1 == pub_r001566_1_2);
  __CPROVER_assume(sec_r001566_8_1 != sec_r001566_8_2);
  __CPROVER_assume(pub_r001566_8_1 == pub_r001566_8_2);
  __CPROVER_assume(sec_r001566_14_1 != sec_r001566_14_2);
  __CPROVER_assume(pub_r001566_13_1 == pub_r001566_13_2);
  __CPROVER_assume(sec_r001566_12_1 != sec_r001566_12_2);
  __CPROVER_assume(sec_r001566_10_1 != sec_r001566_10_2);
  __CPROVER_assume(pub_r001566_0_1 == pub_r001566_0_2);
  __CPROVER_assume(pub_r001566_15_1 == pub_r001566_15_2);
  __CPROVER_assume(sec_r001566_4_1 != sec_r001566_4_2);
  __CPROVER_assume(pub_r001566_3_1 == pub_r001566_3_2);
  __CPROVER_assume(sec_r001566_9_1 != sec_r001566_9_2);
  __CPROVER_assume(pub_r001566_9_1 == pub_r001566_9_2);
  __CPROVER_assume(sec_r001566_3_1 != sec_r001566_3_2);
  __CPROVER_assume(sec_r001566_16_1 != sec_r001566_16_2);
  __CPROVER_assume(pub_r001566_4_1 == pub_r001566_4_2);
  __CPROVER_assume(sec_r001566_5_1 != sec_r001566_5_2);
  __CPROVER_assume(pub_r001566_12_1 == pub_r001566_12_2);
  __CPROVER_assume(pub_r001566_6_1 == pub_r001566_6_2);
  __CPROVER_assume(pub_r001566_17_1 == pub_r001566_17_2);
  __CPROVER_assume(sec_r001566_18_1 != sec_r001566_18_2);
  __CPROVER_assume(sec_r001566_6_1 != sec_r001566_6_2);
  __CPROVER_assume(sec_r001566_11_1 != sec_r001566_11_2);
  __CPROVER_assume(sec_r001566_13_1 != sec_r001566_13_2);
  __CPROVER_assume(pub_r001566_11_1 == pub_r001566_11_2);
  __CPROVER_assume(sec_r001566_7_1 != sec_r001566_7_2);
  __CPROVER_assume(sec_r001566_0_1 != sec_r001566_0_2);
  __CPROVER_assume(sec_r001566_1_1 != sec_r001566_1_2);
  __CPROVER_assume(sec_r001566_15_1 != sec_r001566_15_2);
  __CPROVER_assume(pub_r001566_18_1 == pub_r001566_18_2);
  __CPROVER_assume(pub_r001566_10_1 == pub_r001566_10_2);
  __CPROVER_assume(pub_r001566_14_1 == pub_r001566_14_2);
  __CPROVER_assume(sec_r001566_2_1 != sec_r001566_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.heading == st_var_1_2.heading);
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
}


