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
struct Vector3D_R001886_8613_0
{
  int coord_x;
  int norm_sq;
  unsigned char pitch;
  int buffer[3];
};
struct DeviceConfig_R001886_8613_1
{
  int stop_bits;
  int timeout;
  unsigned char parity;
  unsigned char id;
  unsigned char port;
  int buffer[3];
};
struct CipherContext_R001886_8613_2
{
  int iv;
  short counter;
  short tag;
  int buffer[3];
};
union ColorPixel_R001886_8613_0
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
void fn_R001886_8613_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st_1 = {0};
  struct CipherContext_R001886_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int quantum_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_99_1 > 28)
  {
    acc_1 = ((acc_1 + (quantum_99_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_99_2 > 28)
  {
    acc_2 = ((acc_2 + (quantum_99_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_79_1 = local_arr_1[aux_1 % 3];
  int bound_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_79_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_99_1 == quantum_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_79_1 == bound_79_2);
}

int fn_R001886_8613_0(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int quantum_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_99 > 28)
  {
    acc = ((acc + (quantum_99 * 2)) + 5) & 127;
    aux ^= quantum_99 & 15;
  }
  else
  {
    acc = ((acc - quantum_99) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_79 = local_arr[aux % 3];
  acc = (acc + (bound_79 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001886_8613_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st_1 = {0};
  struct DeviceConfig_R001886_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int coefficient_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_68_1) & 63;
  aux_2 = (aux_2 + coefficient_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_37_1 > 30)
  {
    acc_1 = ((acc_1 + (margin_37_1 * 2)) + 5) & 127;
    aux_1 ^= margin_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_37_2 > 30)
  {
    acc_2 = ((acc_2 + (margin_37_2 * 2)) + 5) & 127;
    aux_2 ^= margin_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_37_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_68_1 == coefficient_68_2);
  assert(margin_37_1 == margin_37_2);
}

int fn_R001886_8613_1(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int coefficient_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_68) & 63;
  acc ^= aux;
  int margin_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_37 > 30)
  {
    acc = ((acc + (margin_37 * 2)) + 5) & 127;
    aux ^= margin_37 & 15;
  }
  else
  {
    acc = ((acc - margin_37) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001886_8613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001886_8613_0 st_1 = {0};
  struct Vector3D_R001886_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int stride_48_1 = 0;
  int stride_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_48_1 = ((stride_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_48_2 = ((stride_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_48_1) & 127;
    acc_2 = (acc_2 + stride_48_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_33_1 = local_arr_1[aux_1 % 3];
  int vector_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_33_2 * 2)) & 127;
  int residue_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_59_1)
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

  switch (residue_59_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_48_1 == stride_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_33_1 == vector_33_2);
  assert(residue_59_1 == residue_59_2);
}

int fn_R001886_8613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001886_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int stride_48 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_48 = ((stride_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_48) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int vector_33 = local_arr[aux % 3];
  acc = (acc + (vector_33 * 2)) & 127;
  int residue_59 = (aux + st.buffer[1]) & 3;
  switch (residue_59)
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

void fn_R001886_8613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st_1 = {0};
  struct CipherContext_R001886_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int margin_70_1 = 0;
  int margin_70_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_70_1 = ((margin_70_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_70_2 = ((margin_70_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_70_1) & 127;
    acc_2 = (acc_2 + margin_70_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_61_1 > 26)
  {
    acc_1 = ((acc_1 + (pivot_61_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_61_2 > 26)
  {
    acc_2 = ((acc_2 + (pivot_61_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_86_1)
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

  switch (coefficient_86_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_70_1 == margin_70_2);
  assert(pivot_61_1 == pivot_61_2);
  assert(coefficient_86_1 == coefficient_86_2);
}

int fn_R001886_8613_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int margin_70 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_70 = ((margin_70 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_70) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_61 > 26)
  {
    acc = ((acc + (pivot_61 * 2)) + 5) & 127;
    aux ^= pivot_61 & 15;
  }
  else
  {
    acc = ((acc - pivot_61) + 11) & 127;
    aux += 3;
  }
  int coefficient_86 = (aux + st.buffer[1]) & 3;
  switch (coefficient_86)
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

void fn_R001886_8613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st_1 = {0};
  struct DeviceConfig_R001886_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int sample_55_1 = 0;
  int sample_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_55_1 = ((sample_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_55_2 = ((sample_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_55_1) & 127;
    acc_2 = (acc_2 + sample_55_2) & 127;
  }

  int tracker_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_56_1) & 63;
  aux_2 = (aux_2 + tracker_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_79_1)
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

  switch (threshold_79_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_55_1 == sample_55_2);
  assert(tracker_56_1 == tracker_56_2);
  assert(threshold_79_1 == threshold_79_2);
}

int fn_R001886_8613_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int sample_55 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_55 = ((sample_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_55) & 127;
  }

  int tracker_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_56) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_79 = (aux + st.buffer[1]) & 3;
  switch (threshold_79)
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

void fn_R001886_8613_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st_1 = {0};
  struct DeviceConfig_R001886_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int vector_66_1 = 0;
  int vector_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_66_1 = ((vector_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_66_2 = ((vector_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_66_1) & 127;
    acc_2 = (acc_2 + vector_66_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_52_1 = local_arr_1[aux_1 % 3];
  int segment_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_66_1 == vector_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_52_1 == segment_52_2);
}

int fn_R001886_8613_5(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int vector_66 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_66 = ((vector_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_66) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int segment_52 = local_arr[aux % 3];
  acc = (acc + (segment_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001886_8613_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st_1 = {0};
  struct DeviceConfig_R001886_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_60_1 = local_arr_1[aux_1 % 3];
  int parity_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_60_2 * 2)) & 127;
  int checksum_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_26_1)
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

  switch (checksum_26_2)
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

  int stride_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_90_1) & 63;
  aux_2 = (aux_2 + stride_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_60_1 == parity_60_2);
  assert(checksum_26_1 == checksum_26_2);
  assert(stride_90_1 == stride_90_2);
}

int fn_R001886_8613_6(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_60 = local_arr[aux % 3];
  acc = (acc + (parity_60 * 2)) & 127;
  int checksum_26 = (aux + st.buffer[1]) & 3;
  switch (checksum_26)
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

  int stride_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_90) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001886_8613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001886_8613_0 st_1 = {0};
  struct Vector3D_R001886_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_72_1 = local_arr_1[aux_1 % 3];
  int damping_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_72_2 * 2)) & 127;
  int accumulator_88_1 = 0;
  int accumulator_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_88_1 = ((accumulator_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_88_2 = ((accumulator_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_88_1) & 127;
    acc_2 = (acc_2 + accumulator_88_2) & 127;
  }

  int residue_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_31_1 > 46)
  {
    acc_1 = ((acc_1 + (residue_31_1 * 2)) + 5) & 127;
    aux_1 ^= residue_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_31_2 > 46)
  {
    acc_2 = ((acc_2 + (residue_31_2 * 2)) + 5) & 127;
    aux_2 ^= residue_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_31_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_72_1 == damping_72_2);
  assert(accumulator_88_1 == accumulator_88_2);
  assert(residue_31_1 == residue_31_2);
}

int fn_R001886_8613_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001886_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int damping_72 = local_arr[aux % 3];
  acc = (acc + (damping_72 * 2)) & 127;
  int accumulator_88 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_88 = ((accumulator_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_88) & 127;
  }

  int residue_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_31 > 46)
  {
    acc = ((acc + (residue_31 * 2)) + 5) & 127;
    aux ^= residue_31 & 15;
  }
  else
  {
    acc = ((acc - residue_31) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001886_8613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st_1 = {0};
  struct DeviceConfig_R001886_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int anchor_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_50_1) & 63;
  aux_2 = (aux_2 + anchor_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_62_1 = 0;
  int index_reg_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_62_1 = ((index_reg_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_62_2 = ((index_reg_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_62_1) & 127;
    acc_2 = (acc_2 + index_reg_62_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_50_1 == anchor_50_2);
  assert(index_reg_62_1 == index_reg_62_2);
}

int fn_R001886_8613_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int anchor_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_50) & 63;
  acc ^= aux;
  int index_reg_62 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_62 = ((index_reg_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_62) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001886_8613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st_1 = {0};
  struct CipherContext_R001886_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_12_1 = local_arr_1[aux_1 % 3];
  int accumulator_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_12_2 * 2)) & 127;
  int tally_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_48_1)
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

  switch (tally_48_2)
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

  int accumulator_36_1 = 0;
  int accumulator_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_36_1 = ((accumulator_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_36_2 = ((accumulator_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_36_1) & 127;
    acc_2 = (acc_2 + accumulator_36_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_12_1 == accumulator_12_2);
  assert(tally_48_1 == tally_48_2);
  assert(accumulator_36_1 == accumulator_36_2);
}

int fn_R001886_8613_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int accumulator_12 = local_arr[aux % 3];
  acc = (acc + (accumulator_12 * 2)) & 127;
  int tally_48 = (aux + st.buffer[1]) & 3;
  switch (tally_48)
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

  int accumulator_36 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_36 = ((accumulator_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_36) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001886_8613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st_1 = {0};
  struct CipherContext_R001886_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int bound_70_1 = 0;
  int bound_70_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_70_1 = ((bound_70_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_70_2 = ((bound_70_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_70_1) & 127;
    acc_2 = (acc_2 + bound_70_2) & 127;
  }

  int sample_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_34_1) & 63;
  aux_2 = (aux_2 + sample_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_70_1 == bound_70_2);
  assert(sample_34_1 == sample_34_2);
}

int fn_R001886_8613_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int bound_70 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_70 = ((bound_70 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_70) & 127;
  }

  int sample_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_34) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001886_8613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st_1 = {0};
  struct DeviceConfig_R001886_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int offset_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_55_1) & 63;
  aux_2 = (aux_2 + offset_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_52_1 = 0;
  int quotient_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_52_1 = ((quotient_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_52_2 = ((quotient_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_52_1) & 127;
    acc_2 = (acc_2 + quotient_52_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_55_1 == offset_55_2);
  assert(quotient_52_1 == quotient_52_2);
}

int fn_R001886_8613_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int offset_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_55) & 63;
  acc ^= aux;
  int quotient_52 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_52 = ((quotient_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_52) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001886_8613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st_1 = {0};
  struct DeviceConfig_R001886_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int offset_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_70_1 > 48)
  {
    acc_1 = ((acc_1 + (offset_70_1 * 2)) + 5) & 127;
    aux_1 ^= offset_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_70_2 > 48)
  {
    acc_2 = ((acc_2 + (offset_70_2 * 2)) + 5) & 127;
    aux_2 ^= offset_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_12_1)
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

  switch (vector_12_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_70_1 == offset_70_2);
  assert(vector_12_1 == vector_12_2);
}

int fn_R001886_8613_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int offset_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_70 > 48)
  {
    acc = ((acc + (offset_70 * 2)) + 5) & 127;
    aux ^= offset_70 & 15;
  }
  else
  {
    acc = ((acc - offset_70) + 11) & 127;
    aux += 3;
  }
  int vector_12 = (aux + st.buffer[1]) & 3;
  switch (vector_12)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001886_8613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001886_8613_0 st_1 = {0};
  struct Vector3D_R001886_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int mask_98_1 = 0;
  int mask_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_98_1 = ((mask_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_98_2 = ((mask_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_98_1) & 127;
    acc_2 = (acc_2 + mask_98_2) & 127;
  }

  int residue_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_90_1)
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

  switch (residue_90_2)
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

  int threshold_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_49_1 > 44)
  {
    acc_1 = ((acc_1 + (threshold_49_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_49_2 > 44)
  {
    acc_2 = ((acc_2 + (threshold_49_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_49_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_98_1 == mask_98_2);
  assert(residue_90_1 == residue_90_2);
  assert(threshold_49_1 == threshold_49_2);
}

int fn_R001886_8613_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001886_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int mask_98 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_98 = ((mask_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_98) & 127;
  }

  int residue_90 = (aux + st.buffer[1]) & 3;
  switch (residue_90)
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

  int threshold_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_49 > 44)
  {
    acc = ((acc + (threshold_49 * 2)) + 5) & 127;
    aux ^= threshold_49 & 15;
  }
  else
  {
    acc = ((acc - threshold_49) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001886_8613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st_1 = {0};
  struct CipherContext_R001886_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int segment_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_95_1 > 11)
  {
    acc_1 = ((acc_1 + (segment_95_1 * 2)) + 5) & 127;
    aux_1 ^= segment_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_95_2 > 11)
  {
    acc_2 = ((acc_2 + (segment_95_2 * 2)) + 5) & 127;
    aux_2 ^= segment_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_65_1) & 63;
  aux_2 = (aux_2 + scale_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_95_1 == segment_95_2);
  assert(scale_65_1 == scale_65_2);
}

int fn_R001886_8613_14(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int segment_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_95 > 11)
  {
    acc = ((acc + (segment_95 * 2)) + 5) & 127;
    aux ^= segment_95 & 15;
  }
  else
  {
    acc = ((acc - segment_95) + 11) & 127;
    aux += 3;
  }
  int scale_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_65) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001886_8613_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001886_8613_0 st_1 = {0};
  struct Vector3D_R001886_8613_0 st_2 = {0};
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
  int quotient_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_47_1)
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

  switch (quotient_47_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_47_1 == quotient_47_2);
  assert(factor_19_1 == factor_19_2);
}

int fn_R001886_8613_15(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001886_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_47 = (aux + st.buffer[1]) & 3;
  switch (quotient_47)
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

  int factor_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_19 = ((factor_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_19) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001886_8613_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st_1 = {0};
  struct CipherContext_R001886_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_55_1 = local_arr_1[aux_1 % 3];
  int phase_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_55_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_29_1 > 14)
  {
    acc_1 = ((acc_1 + (damping_29_1 * 2)) + 5) & 127;
    aux_1 ^= damping_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_29_2 > 14)
  {
    acc_2 = ((acc_2 + (damping_29_2 * 2)) + 5) & 127;
    aux_2 ^= damping_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_55_1 == phase_55_2);
  assert(damping_29_1 == damping_29_2);
}

int fn_R001886_8613_16(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int phase_55 = local_arr[aux % 3];
  acc = (acc + (phase_55 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_29 > 14)
  {
    acc = ((acc + (damping_29 * 2)) + 5) & 127;
    aux ^= damping_29 & 15;
  }
  else
  {
    acc = ((acc - damping_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001886_8613_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st_1 = {0};
  struct DeviceConfig_R001886_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_88_1 = local_arr_1[aux_1 % 3];
  int scale_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_88_2 * 2)) & 127;
  int scale_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_82_1)
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

  switch (scale_82_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_88_1 == scale_88_2);
  assert(scale_82_1 == scale_82_2);
}

int fn_R001886_8613_17(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int scale_88 = local_arr[aux % 3];
  acc = (acc + (scale_88 * 2)) & 127;
  int scale_82 = (aux + st.buffer[1]) & 3;
  switch (scale_82)
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

void fn_R001886_8613_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st_1 = {0};
  struct CipherContext_R001886_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int coefficient_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_38_1 > 13)
  {
    acc_1 = ((acc_1 + (coefficient_38_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_38_2 > 13)
  {
    acc_2 = ((acc_2 + (coefficient_38_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_24_1)
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

  switch (window_24_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_38_1 == coefficient_38_2);
  assert(window_24_1 == window_24_2);
}

int fn_R001886_8613_18(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int coefficient_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_38 > 13)
  {
    acc = ((acc + (coefficient_38 * 2)) + 5) & 127;
    aux ^= coefficient_38 & 15;
  }
  else
  {
    acc = ((acc - coefficient_38) + 11) & 127;
    aux += 3;
  }
  int window_24 = (aux + st.buffer[1]) & 3;
  switch (window_24)
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

void fn_R001886_8613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st_1 = {0};
  struct DeviceConfig_R001886_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int tally_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_95_1) & 63;
  aux_2 = (aux_2 + tally_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_52_1)
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

  switch (margin_52_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_95_1 == tally_95_2);
  assert(margin_52_1 == margin_52_2);
}

int fn_R001886_8613_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int tally_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_95) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_52 = (aux + st.buffer[1]) & 3;
  switch (margin_52)
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

void fn_R001886_8613_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st_1 = {0};
  struct CipherContext_R001886_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int factor_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_10_1) & 63;
  aux_2 = (aux_2 + factor_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_70_1)
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

  switch (delta_70_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_10_1 == factor_10_2);
  assert(delta_70_1 == delta_70_2);
}

int fn_R001886_8613_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int factor_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_10) & 63;
  acc ^= aux;
  int delta_70 = (aux + st.buffer[1]) & 3;
  switch (delta_70)
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

void fn_R001886_8613_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st_1 = {0};
  struct CipherContext_R001886_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int residue_12_1 = 0;
  int residue_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_12_1 = ((residue_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_12_2 = ((residue_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_12_1) & 127;
    acc_2 = (acc_2 + residue_12_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_17_1 = local_arr_1[aux_1 % 3];
  int bound_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_17_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_75_1)
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

  switch (weight_75_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_12_1 == residue_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_17_1 == bound_17_2);
  assert(weight_75_1 == weight_75_2);
}

int fn_R001886_8613_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001886_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int residue_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_12 = ((residue_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_12) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int bound_17 = local_arr[aux % 3];
  acc = (acc + (bound_17 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_75 = (aux + st.buffer[1]) & 3;
  switch (weight_75)
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

void fn_R001886_8613_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st_1 = {0};
  struct DeviceConfig_R001886_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_93_1 = local_arr_1[aux_1 % 3];
  int factor_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_93_2 * 2)) & 127;
  int scale_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_26_1)
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

  switch (scale_26_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_93_1 == factor_93_2);
  assert(scale_26_1 == scale_26_2);
}

int fn_R001886_8613_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001886_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int factor_93 = local_arr[aux % 3];
  acc = (acc + (factor_93 * 2)) & 127;
  int scale_26 = (aux + st.buffer[1]) & 3;
  switch (scale_26)
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

void main()
{
  int sec_r001886_0_1;
  int sec_r001886_0_2;
  int sec_r001886_1_1;
  int sec_r001886_1_2;
  int sec_r001886_2_1;
  int sec_r001886_2_2;
  int sec_r001886_3_1;
  int sec_r001886_3_2;
  int sec_r001886_4_1;
  int sec_r001886_4_2;
  int sec_r001886_5_1;
  int sec_r001886_5_2;
  int sec_r001886_6_1;
  int sec_r001886_6_2;
  int sec_r001886_7_1;
  int sec_r001886_7_2;
  int sec_r001886_8_1;
  int sec_r001886_8_2;
  int sec_r001886_9_1;
  int sec_r001886_9_2;
  int sec_r001886_10_1;
  int sec_r001886_10_2;
  int sec_r001886_11_1;
  int sec_r001886_11_2;
  int sec_r001886_12_1;
  int sec_r001886_12_2;
  int sec_r001886_13_1;
  int sec_r001886_13_2;
  int sec_r001886_14_1;
  int sec_r001886_14_2;
  int sec_r001886_15_1;
  int sec_r001886_15_2;
  int sec_r001886_16_1;
  int sec_r001886_16_2;
  int sec_r001886_17_1;
  int sec_r001886_17_2;
  int sec_r001886_18_1;
  int sec_r001886_18_2;
  int sec_r001886_19_1;
  int sec_r001886_19_2;
  int sec_r001886_20_1;
  int sec_r001886_20_2;
  int sec_r001886_21_1;
  int sec_r001886_21_2;
  int sec_r001886_22_1;
  int sec_r001886_22_2;
  int sec_r001886_23_1;
  int sec_r001886_23_2;
  int pub_r001886_0_1;
  int pub_r001886_0_2;
  int pub_r001886_1_1;
  int pub_r001886_1_2;
  int pub_r001886_2_1;
  int pub_r001886_2_2;
  int pub_r001886_3_1;
  int pub_r001886_3_2;
  int pub_r001886_4_1;
  int pub_r001886_4_2;
  int pub_r001886_5_1;
  int pub_r001886_5_2;
  int pub_r001886_6_1;
  int pub_r001886_6_2;
  int pub_r001886_7_1;
  int pub_r001886_7_2;
  int pub_r001886_8_1;
  int pub_r001886_8_2;
  int pub_r001886_9_1;
  int pub_r001886_9_2;
  int pub_r001886_10_1;
  int pub_r001886_10_2;
  int pub_r001886_11_1;
  int pub_r001886_11_2;
  int pub_r001886_12_1;
  int pub_r001886_12_2;
  int pub_r001886_13_1;
  int pub_r001886_13_2;
  int pub_r001886_14_1;
  int pub_r001886_14_2;
  int pub_r001886_15_1;
  int pub_r001886_15_2;
  int pub_r001886_16_1;
  int pub_r001886_16_2;
  int pub_r001886_17_1;
  int pub_r001886_17_2;
  int pub_r001886_18_1;
  int pub_r001886_18_2;
  int pub_r001886_19_1;
  int pub_r001886_19_2;
  int pub_r001886_20_1;
  int pub_r001886_20_2;
  int pub_r001886_21_1;
  int pub_r001886_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001886_0_1 >= (-100)) && (pub_r001886_0_1 <= 100));
  __CPROVER_assume((pub_r001886_0_2 >= (-100)) && (pub_r001886_0_2 <= 100));
  __CPROVER_assume((pub_r001886_1_1 >= (-100)) && (pub_r001886_1_1 <= 100));
  __CPROVER_assume((pub_r001886_1_2 >= (-100)) && (pub_r001886_1_2 <= 100));
  __CPROVER_assume((pub_r001886_2_1 >= (-100)) && (pub_r001886_2_1 <= 100));
  __CPROVER_assume((pub_r001886_2_2 >= (-100)) && (pub_r001886_2_2 <= 100));
  __CPROVER_assume((pub_r001886_3_1 >= (-100)) && (pub_r001886_3_1 <= 100));
  __CPROVER_assume((pub_r001886_3_2 >= (-100)) && (pub_r001886_3_2 <= 100));
  __CPROVER_assume((pub_r001886_4_1 >= (-100)) && (pub_r001886_4_1 <= 100));
  __CPROVER_assume((pub_r001886_4_2 >= (-100)) && (pub_r001886_4_2 <= 100));
  __CPROVER_assume((pub_r001886_5_1 >= (-100)) && (pub_r001886_5_1 <= 100));
  __CPROVER_assume((pub_r001886_5_2 >= (-100)) && (pub_r001886_5_2 <= 100));
  __CPROVER_assume((pub_r001886_6_1 >= (-100)) && (pub_r001886_6_1 <= 100));
  __CPROVER_assume((pub_r001886_6_2 >= (-100)) && (pub_r001886_6_2 <= 100));
  __CPROVER_assume((pub_r001886_7_1 >= (-100)) && (pub_r001886_7_1 <= 100));
  __CPROVER_assume((pub_r001886_7_2 >= (-100)) && (pub_r001886_7_2 <= 100));
  __CPROVER_assume((pub_r001886_8_1 >= (-100)) && (pub_r001886_8_1 <= 100));
  __CPROVER_assume((pub_r001886_8_2 >= (-100)) && (pub_r001886_8_2 <= 100));
  __CPROVER_assume((pub_r001886_9_1 >= (-100)) && (pub_r001886_9_1 <= 100));
  __CPROVER_assume((pub_r001886_9_2 >= (-100)) && (pub_r001886_9_2 <= 100));
  __CPROVER_assume((pub_r001886_10_1 >= (-100)) && (pub_r001886_10_1 <= 100));
  __CPROVER_assume((pub_r001886_10_2 >= (-100)) && (pub_r001886_10_2 <= 100));
  __CPROVER_assume((pub_r001886_11_1 >= (-100)) && (pub_r001886_11_1 <= 100));
  __CPROVER_assume((pub_r001886_11_2 >= (-100)) && (pub_r001886_11_2 <= 100));
  __CPROVER_assume((pub_r001886_12_1 >= (-100)) && (pub_r001886_12_1 <= 100));
  __CPROVER_assume((pub_r001886_12_2 >= (-100)) && (pub_r001886_12_2 <= 100));
  __CPROVER_assume((pub_r001886_13_1 >= (-100)) && (pub_r001886_13_1 <= 100));
  __CPROVER_assume((pub_r001886_13_2 >= (-100)) && (pub_r001886_13_2 <= 100));
  __CPROVER_assume((pub_r001886_14_1 >= (-100)) && (pub_r001886_14_1 <= 100));
  __CPROVER_assume((pub_r001886_14_2 >= (-100)) && (pub_r001886_14_2 <= 100));
  __CPROVER_assume((pub_r001886_15_1 >= (-100)) && (pub_r001886_15_1 <= 100));
  __CPROVER_assume((pub_r001886_15_2 >= (-100)) && (pub_r001886_15_2 <= 100));
  __CPROVER_assume((pub_r001886_16_1 >= (-100)) && (pub_r001886_16_1 <= 100));
  __CPROVER_assume((pub_r001886_16_2 >= (-100)) && (pub_r001886_16_2 <= 100));
  __CPROVER_assume((pub_r001886_17_1 >= (-100)) && (pub_r001886_17_1 <= 100));
  __CPROVER_assume((pub_r001886_17_2 >= (-100)) && (pub_r001886_17_2 <= 100));
  __CPROVER_assume((pub_r001886_18_1 >= (-100)) && (pub_r001886_18_1 <= 100));
  __CPROVER_assume((pub_r001886_18_2 >= (-100)) && (pub_r001886_18_2 <= 100));
  __CPROVER_assume((pub_r001886_19_1 >= (-100)) && (pub_r001886_19_1 <= 100));
  __CPROVER_assume((pub_r001886_19_2 >= (-100)) && (pub_r001886_19_2 <= 100));
  __CPROVER_assume((pub_r001886_20_1 >= (-100)) && (pub_r001886_20_1 <= 100));
  __CPROVER_assume((pub_r001886_20_2 >= (-100)) && (pub_r001886_20_2 <= 100));
  __CPROVER_assume((pub_r001886_21_1 >= (-100)) && (pub_r001886_21_1 <= 100));
  __CPROVER_assume((pub_r001886_21_2 >= (-100)) && (pub_r001886_21_2 <= 100));
  __CPROVER_assume((sec_r001886_0_1 >= 0) && (sec_r001886_0_1 <= 255));
  __CPROVER_assume((sec_r001886_0_2 >= 0) && (sec_r001886_0_2 <= 255));
  __CPROVER_assume((sec_r001886_1_1 >= 0) && (sec_r001886_1_1 <= 255));
  __CPROVER_assume((sec_r001886_1_2 >= 0) && (sec_r001886_1_2 <= 255));
  __CPROVER_assume((sec_r001886_2_1 >= 0) && (sec_r001886_2_1 <= 255));
  __CPROVER_assume((sec_r001886_2_2 >= 0) && (sec_r001886_2_2 <= 255));
  __CPROVER_assume((sec_r001886_3_1 >= 0) && (sec_r001886_3_1 <= 255));
  __CPROVER_assume((sec_r001886_3_2 >= 0) && (sec_r001886_3_2 <= 255));
  __CPROVER_assume((sec_r001886_4_1 >= 0) && (sec_r001886_4_1 <= 255));
  __CPROVER_assume((sec_r001886_4_2 >= 0) && (sec_r001886_4_2 <= 255));
  __CPROVER_assume((sec_r001886_5_1 >= 0) && (sec_r001886_5_1 <= 255));
  __CPROVER_assume((sec_r001886_5_2 >= 0) && (sec_r001886_5_2 <= 255));
  __CPROVER_assume((sec_r001886_6_1 >= 0) && (sec_r001886_6_1 <= 255));
  __CPROVER_assume((sec_r001886_6_2 >= 0) && (sec_r001886_6_2 <= 255));
  __CPROVER_assume((sec_r001886_7_1 >= 0) && (sec_r001886_7_1 <= 255));
  __CPROVER_assume((sec_r001886_7_2 >= 0) && (sec_r001886_7_2 <= 255));
  __CPROVER_assume((sec_r001886_8_1 >= 0) && (sec_r001886_8_1 <= 255));
  __CPROVER_assume((sec_r001886_8_2 >= 0) && (sec_r001886_8_2 <= 255));
  __CPROVER_assume((sec_r001886_9_1 >= 0) && (sec_r001886_9_1 <= 255));
  __CPROVER_assume((sec_r001886_9_2 >= 0) && (sec_r001886_9_2 <= 255));
  __CPROVER_assume((sec_r001886_10_1 >= 0) && (sec_r001886_10_1 <= 255));
  __CPROVER_assume((sec_r001886_10_2 >= 0) && (sec_r001886_10_2 <= 255));
  __CPROVER_assume((sec_r001886_11_1 >= 0) && (sec_r001886_11_1 <= 255));
  __CPROVER_assume((sec_r001886_11_2 >= 0) && (sec_r001886_11_2 <= 255));
  __CPROVER_assume((sec_r001886_12_1 >= 0) && (sec_r001886_12_1 <= 255));
  __CPROVER_assume((sec_r001886_12_2 >= 0) && (sec_r001886_12_2 <= 255));
  __CPROVER_assume((sec_r001886_13_1 >= 0) && (sec_r001886_13_1 <= 255));
  __CPROVER_assume((sec_r001886_13_2 >= 0) && (sec_r001886_13_2 <= 255));
  __CPROVER_assume((sec_r001886_14_1 >= 0) && (sec_r001886_14_1 <= 255));
  __CPROVER_assume((sec_r001886_14_2 >= 0) && (sec_r001886_14_2 <= 255));
  __CPROVER_assume((sec_r001886_15_1 >= 0) && (sec_r001886_15_1 <= 255));
  __CPROVER_assume((sec_r001886_15_2 >= 0) && (sec_r001886_15_2 <= 255));
  __CPROVER_assume((sec_r001886_16_1 >= 0) && (sec_r001886_16_1 <= 255));
  __CPROVER_assume((sec_r001886_16_2 >= 0) && (sec_r001886_16_2 <= 255));
  __CPROVER_assume((sec_r001886_17_1 >= 0) && (sec_r001886_17_1 <= 255));
  __CPROVER_assume((sec_r001886_17_2 >= 0) && (sec_r001886_17_2 <= 255));
  __CPROVER_assume((sec_r001886_18_1 >= 0) && (sec_r001886_18_1 <= 255));
  __CPROVER_assume((sec_r001886_18_2 >= 0) && (sec_r001886_18_2 <= 255));
  __CPROVER_assume((sec_r001886_19_1 >= 0) && (sec_r001886_19_1 <= 255));
  __CPROVER_assume((sec_r001886_19_2 >= 0) && (sec_r001886_19_2 <= 255));
  __CPROVER_assume((sec_r001886_20_1 >= 0) && (sec_r001886_20_1 <= 255));
  __CPROVER_assume((sec_r001886_20_2 >= 0) && (sec_r001886_20_2 <= 255));
  __CPROVER_assume((sec_r001886_21_1 >= 0) && (sec_r001886_21_1 <= 255));
  __CPROVER_assume((sec_r001886_21_2 >= 0) && (sec_r001886_21_2 <= 255));
  __CPROVER_assume((sec_r001886_22_1 >= 0) && (sec_r001886_22_1 <= 255));
  __CPROVER_assume((sec_r001886_22_2 >= 0) && (sec_r001886_22_2 <= 255));
  __CPROVER_assume((sec_r001886_23_1 >= 0) && (sec_r001886_23_1 <= 255));
  __CPROVER_assume((sec_r001886_23_2 >= 0) && (sec_r001886_23_2 <= 255));
  struct Vector3D_R001886_8613_0 st_var_0_1 = {0};
  struct Vector3D_R001886_8613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001886_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001886_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001886_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001886_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001886_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001886_0_2 + 7) & 15;
  struct DeviceConfig_R001886_8613_1 st_var_1_1 = {0};
  struct DeviceConfig_R001886_8613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001886_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001886_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001886_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001886_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001886_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001886_0_2 + 9) & 15;
  struct CipherContext_R001886_8613_2 st_var_2_1 = {0};
  struct CipherContext_R001886_8613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001886_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001886_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001886_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001886_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001886_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001886_0_2 + 11) & 15;
  union ColorPixel_R001886_8613_0 u_var_1;
  union ColorPixel_R001886_8613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001886_8613_0(sec_r001886_0_1, pub_r001886_1_1);
  int helper_flow_0_2 = fn_R001886_8613_0(sec_r001886_0_2, pub_r001886_1_2);
  fn_R001886_8613_0_2(sec_r001886_0_1, pub_r001886_1_1, sec_r001886_0_2, pub_r001886_1_2);
  int helper_flow_1_1 = fn_R001886_8613_1(sec_r001886_1_1, pub_r001886_2_1, pub_r001886_3_1);
  int helper_flow_1_2 = fn_R001886_8613_1(sec_r001886_1_2, pub_r001886_2_2, pub_r001886_3_2);
  fn_R001886_8613_1_2(sec_r001886_1_1, pub_r001886_2_1, pub_r001886_3_1, sec_r001886_1_2, pub_r001886_2_2, pub_r001886_3_2);
  int helper_flow_2_1 = fn_R001886_8613_2(sec_r001886_2_1, sec_r001886_3_1, pub_r001886_4_1, pub_r001886_5_1, pub_r001886_6_1);
  int helper_flow_2_2 = fn_R001886_8613_2(sec_r001886_2_2, sec_r001886_3_2, pub_r001886_4_2, pub_r001886_5_2, pub_r001886_6_2);
  fn_R001886_8613_2_2(sec_r001886_2_1, sec_r001886_3_1, pub_r001886_4_1, pub_r001886_5_1, pub_r001886_6_1, sec_r001886_2_2, sec_r001886_3_2, pub_r001886_4_2, pub_r001886_5_2, pub_r001886_6_2);
  int helper_flow_3_1 = fn_R001886_8613_3(sec_r001886_3_1, pub_r001886_4_1, pub_r001886_5_1, pub_r001886_6_1, pub_r001886_7_1);
  int helper_flow_3_2 = fn_R001886_8613_3(sec_r001886_3_2, pub_r001886_4_2, pub_r001886_5_2, pub_r001886_6_2, pub_r001886_7_2);
  fn_R001886_8613_3_2(sec_r001886_3_1, pub_r001886_4_1, pub_r001886_5_1, pub_r001886_6_1, pub_r001886_7_1, sec_r001886_3_2, pub_r001886_4_2, pub_r001886_5_2, pub_r001886_6_2, pub_r001886_7_2);
  int helper_flow_4_1 = fn_R001886_8613_4(sec_r001886_4_1, pub_r001886_5_1, pub_r001886_6_1, pub_r001886_7_1, pub_r001886_8_1);
  int helper_flow_4_2 = fn_R001886_8613_4(sec_r001886_4_2, pub_r001886_5_2, pub_r001886_6_2, pub_r001886_7_2, pub_r001886_8_2);
  fn_R001886_8613_4_2(sec_r001886_4_1, pub_r001886_5_1, pub_r001886_6_1, pub_r001886_7_1, pub_r001886_8_1, sec_r001886_4_2, pub_r001886_5_2, pub_r001886_6_2, pub_r001886_7_2, pub_r001886_8_2);
  int helper_flow_5_1 = fn_R001886_8613_5(sec_r001886_5_1, pub_r001886_6_1);
  int helper_flow_5_2 = fn_R001886_8613_5(sec_r001886_5_2, pub_r001886_6_2);
  fn_R001886_8613_5_2(sec_r001886_5_1, pub_r001886_6_1, sec_r001886_5_2, pub_r001886_6_2);
  int helper_flow_6_1 = fn_R001886_8613_6(sec_r001886_6_1, sec_r001886_7_1);
  int helper_flow_6_2 = fn_R001886_8613_6(sec_r001886_6_2, sec_r001886_7_2);
  fn_R001886_8613_6_2(sec_r001886_6_1, sec_r001886_7_1, sec_r001886_6_2, sec_r001886_7_2);
  int helper_flow_7_1 = fn_R001886_8613_7(sec_r001886_7_1, sec_r001886_8_1, pub_r001886_9_1, pub_r001886_10_1, pub_r001886_11_1);
  int helper_flow_7_2 = fn_R001886_8613_7(sec_r001886_7_2, sec_r001886_8_2, pub_r001886_9_2, pub_r001886_10_2, pub_r001886_11_2);
  fn_R001886_8613_7_2(sec_r001886_7_1, sec_r001886_8_1, pub_r001886_9_1, pub_r001886_10_1, pub_r001886_11_1, sec_r001886_7_2, sec_r001886_8_2, pub_r001886_9_2, pub_r001886_10_2, pub_r001886_11_2);
  int stage_v_0_1 = ((pub_r001886_11_1 * 2) + 32) & 63;
  int stage_v_0_2 = ((pub_r001886_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((helper_flow_7_1 + (pub_r001886_21_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((helper_flow_7_2 + (pub_r001886_21_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((pub_r001886_18_1 * 2) + 19) & 63;
  int stage_v_2_2 = ((pub_r001886_18_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((helper_flow_5_1 + (pub_r001886_14_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((helper_flow_5_2 + (pub_r001886_14_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((pub_r001886_15_1 * 2) + 19) & 63;
  int stage_v_4_2 = ((pub_r001886_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001886_11_1 * 2) + 28) & 63;
  int stage_v_5_2 = ((pub_r001886_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001886_1_1 * 2) + 41) & 63;
  int stage_v_6_2 = ((pub_r001886_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001886_0_1 * 2) + 43) & 63;
  int stage_v_7_2 = ((pub_r001886_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((sec_r001886_7_1 + (pub_r001886_20_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((sec_r001886_7_2 + (pub_r001886_20_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((pub_r001886_8_1 * 2) + 25) & 63;
  int stage_v_9_2 = ((pub_r001886_8_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((sec_r001886_16_1 + (pub_r001886_0_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((sec_r001886_16_2 + (pub_r001886_0_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((sec_r001886_17_1 + (pub_r001886_1_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((sec_r001886_17_2 + (pub_r001886_1_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((sec_r001886_16_1 + (pub_r001886_14_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001886_16_2 + (pub_r001886_14_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((pub_r001886_3_1 * 2) + 44) & 63;
  int stage_v_13_2 = ((pub_r001886_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001886_15_1 * 2) + 40) & 63;
  int stage_v_14_2 = ((pub_r001886_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001886_6_1 * 2) + 12) & 63;
  int stage_v_15_2 = ((pub_r001886_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((sec_r001886_15_1 + (pub_r001886_8_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((sec_r001886_15_2 + (pub_r001886_8_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((helper_flow_3_1 + (pub_r001886_8_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((helper_flow_3_2 + (pub_r001886_8_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((stage_v_12_1 + (pub_r001886_10_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((stage_v_12_2 + (pub_r001886_10_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((sec_r001886_6_1 + (pub_r001886_10_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((sec_r001886_6_2 + (pub_r001886_10_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((stage_v_18_1 + (pub_r001886_19_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((stage_v_18_2 + (pub_r001886_19_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((stage_v_19_1 + (pub_r001886_12_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_19_2 + (pub_r001886_12_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((stage_v_20_1 + (pub_r001886_3_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((stage_v_20_2 + (pub_r001886_3_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((stage_v_16_1 + (pub_r001886_14_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((stage_v_16_2 + (pub_r001886_14_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((helper_flow_4_1 + (pub_r001886_18_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((helper_flow_4_2 + (pub_r001886_18_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((sec_r001886_21_1 + (pub_r001886_19_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((sec_r001886_21_2 + (pub_r001886_19_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((helper_flow_7_1 + (pub_r001886_8_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((helper_flow_7_2 + (pub_r001886_8_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((sec_r001886_7_1 + (pub_r001886_20_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((sec_r001886_7_2 + (pub_r001886_20_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((pub_r001886_12_1 * 2) + 10) & 63;
  int stage_v_28_2 = ((pub_r001886_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((sec_r001886_13_1 + (pub_r001886_14_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001886_13_2 + (pub_r001886_14_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((pub_r001886_17_1 * 2) + 31) & 63;
  int stage_v_30_2 = ((pub_r001886_17_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001886_9_1 * 2) + 39) & 63;
  int stage_v_31_2 = ((pub_r001886_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((stage_v_26_1 + (pub_r001886_1_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((stage_v_26_2 + (pub_r001886_1_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((sec_r001886_17_1 + (pub_r001886_15_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((sec_r001886_17_2 + (pub_r001886_15_2 * 2)) + 104) & 127;
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
  int stage_v_34_1 = ((stage_v_19_1 + (pub_r001886_0_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((stage_v_19_2 + (pub_r001886_0_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((helper_flow_7_1 + (pub_r001886_14_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((helper_flow_7_2 + (pub_r001886_14_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((pub_r001886_1_1 * 2) + 15) & 63;
  int stage_v_36_2 = ((pub_r001886_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((helper_flow_5_1 + (pub_r001886_1_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((helper_flow_5_2 + (pub_r001886_1_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((pub_r001886_0_1 * 2) + 39) & 63;
  int stage_v_38_2 = ((pub_r001886_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((sec_r001886_7_1 + (pub_r001886_7_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((sec_r001886_7_2 + (pub_r001886_7_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((sec_r001886_12_1 + (pub_r001886_21_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((sec_r001886_12_2 + (pub_r001886_21_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((pub_r001886_0_1 * 2) + 19) & 63;
  int stage_v_41_2 = ((pub_r001886_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((sec_r001886_16_1 + (pub_r001886_0_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((sec_r001886_16_2 + (pub_r001886_0_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((stage_v_27_1 + (pub_r001886_15_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((stage_v_27_2 + (pub_r001886_15_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((sec_r001886_15_1 + (pub_r001886_8_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((sec_r001886_15_2 + (pub_r001886_8_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((pub_r001886_12_1 * 2) + 41) & 63;
  int stage_v_45_2 = ((pub_r001886_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((sec_r001886_14_1 + (pub_r001886_1_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((sec_r001886_14_2 + (pub_r001886_1_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((helper_flow_4_1 + (pub_r001886_15_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((helper_flow_4_2 + (pub_r001886_15_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((sec_r001886_22_1 + (pub_r001886_13_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((sec_r001886_22_2 + (pub_r001886_13_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((stage_v_40_1 + (pub_r001886_11_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((stage_v_40_2 + (pub_r001886_11_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((pub_r001886_21_1 * 2) + 5) & 63;
  int stage_v_50_2 = ((pub_r001886_21_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((sec_r001886_9_1 + (pub_r001886_3_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((sec_r001886_9_2 + (pub_r001886_3_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((sec_r001886_11_1 + (pub_r001886_1_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((sec_r001886_11_2 + (pub_r001886_1_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((pub_r001886_11_1 * 2) + 21) & 63;
  int stage_v_53_2 = ((pub_r001886_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001886_19_1 * 2) + 14) & 63;
  int stage_v_54_2 = ((pub_r001886_19_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((stage_v_17_1 + (pub_r001886_3_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((stage_v_17_2 + (pub_r001886_3_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((pub_r001886_13_1 * 2) + 7) & 63;
  int stage_v_56_2 = ((pub_r001886_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((sec_r001886_19_1 + (pub_r001886_19_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((sec_r001886_19_2 + (pub_r001886_19_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((sec_r001886_13_1 + (pub_r001886_11_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((sec_r001886_13_2 + (pub_r001886_11_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((pub_r001886_14_1 * 2) + 36) & 63;
  int stage_v_59_2 = ((pub_r001886_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001886_21_1 * 2) + 46) & 63;
  int stage_v_60_2 = ((pub_r001886_21_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((sec_r001886_3_1 + (pub_r001886_13_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((sec_r001886_3_2 + (pub_r001886_13_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((stage_v_22_1 + (pub_r001886_9_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((stage_v_22_2 + (pub_r001886_9_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((stage_v_20_1 + (pub_r001886_21_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_20_2 + (pub_r001886_21_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((stage_v_1_1 + (pub_r001886_4_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((stage_v_1_2 + (pub_r001886_4_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((stage_v_27_1 + (pub_r001886_6_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_27_2 + (pub_r001886_6_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((pub_r001886_19_1 * 2) + 39) & 63;
  int stage_v_66_2 = ((pub_r001886_19_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001886_15_1 * 2) + 38) & 63;
  int stage_v_67_2 = ((pub_r001886_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001886_12_1 * 2) + 42) & 63;
  int stage_v_68_2 = ((pub_r001886_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((sec_r001886_10_1 + (pub_r001886_5_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((sec_r001886_10_2 + (pub_r001886_5_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((sec_r001886_4_1 + (pub_r001886_11_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((sec_r001886_4_2 + (pub_r001886_11_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((sec_r001886_22_1 + (pub_r001886_18_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((sec_r001886_22_2 + (pub_r001886_18_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((stage_v_1_1 + (pub_r001886_18_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((stage_v_1_2 + (pub_r001886_18_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((pub_r001886_5_1 * 2) + 7) & 63;
  int stage_v_73_2 = ((pub_r001886_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001886_12_1 * 2) + 9) & 63;
  int stage_v_74_2 = ((pub_r001886_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((stage_v_11_1 + (pub_r001886_15_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_11_2 + (pub_r001886_15_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((pub_r001886_21_1 * 2) + 35) & 63;
  int stage_v_76_2 = ((pub_r001886_21_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((sec_r001886_7_1 + (pub_r001886_18_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((sec_r001886_7_2 + (pub_r001886_18_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((stage_v_58_1 + (pub_r001886_3_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_58_2 + (pub_r001886_3_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((stage_v_23_1 + (pub_r001886_8_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_23_2 + (pub_r001886_8_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((stage_v_27_1 + (pub_r001886_16_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_27_2 + (pub_r001886_16_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((pub_r001886_16_1 * 2) + 13) & 63;
  int stage_v_81_2 = ((pub_r001886_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((stage_v_79_1 + (pub_r001886_10_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((stage_v_79_2 + (pub_r001886_10_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((stage_v_46_1 + (pub_r001886_8_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_46_2 + (pub_r001886_8_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((pub_r001886_19_1 * 2) + 23) & 63;
  int stage_v_84_2 = ((pub_r001886_19_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001886_1_1 * 2) + 8) & 63;
  int stage_v_85_2 = ((pub_r001886_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((stage_v_3_1 + (pub_r001886_18_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_3_2 + (pub_r001886_18_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_64_1 + (pub_r001886_12_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_64_2 + (pub_r001886_12_2 * 2)) + 266) & 127;
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
  int stage_v_88_1 = ((stage_v_79_1 + (pub_r001886_3_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_79_2 + (pub_r001886_3_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((stage_v_44_1 + (pub_r001886_0_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_44_2 + (pub_r001886_0_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((pub_r001886_21_1 * 2) + 27) & 63;
  int stage_v_90_2 = ((pub_r001886_21_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001886_0_1 * 2) + 39) & 63;
  int stage_v_91_2 = ((pub_r001886_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((stage_v_16_1 + (pub_r001886_18_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_16_2 + (pub_r001886_18_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((pub_r001886_21_1 * 2) + 15) & 63;
  int stage_v_93_2 = ((pub_r001886_21_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001886_15_1 * 2) + 34) & 63;
  int stage_v_94_2 = ((pub_r001886_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((stage_v_55_1 + (pub_r001886_1_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_55_2 + (pub_r001886_1_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((stage_v_70_1 + (pub_r001886_7_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_70_2 + (pub_r001886_7_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((stage_v_86_1 + (pub_r001886_17_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_86_2 + (pub_r001886_17_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((stage_v_25_1 + (pub_r001886_2_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_25_2 + (pub_r001886_2_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((pub_r001886_15_1 * 2) + 33) & 63;
  int stage_v_99_2 = ((pub_r001886_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((sec_r001886_19_1 + (pub_r001886_7_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((sec_r001886_19_2 + (pub_r001886_7_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((stage_v_26_1 + (pub_r001886_3_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_26_2 + (pub_r001886_3_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((stage_v_33_1 + (pub_r001886_9_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_33_2 + (pub_r001886_9_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((stage_v_39_1 + (pub_r001886_1_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_39_2 + (pub_r001886_1_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((sec_r001886_18_1 + (pub_r001886_14_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((sec_r001886_18_2 + (pub_r001886_14_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((stage_v_47_1 + (pub_r001886_10_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_47_2 + (pub_r001886_10_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((stage_v_19_1 + (pub_r001886_2_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_19_2 + (pub_r001886_2_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((stage_v_86_1 + (pub_r001886_1_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_86_2 + (pub_r001886_1_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((pub_r001886_16_1 * 2) + 47) & 63;
  int stage_v_108_2 = ((pub_r001886_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_29_1 + (pub_r001886_18_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_29_2 + (pub_r001886_18_2 * 2)) + 332) & 127;
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
  int stage_v_110_1 = ((stage_v_43_1 + (pub_r001886_2_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((stage_v_43_2 + (pub_r001886_2_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((pub_r001886_20_1 * 2) + 46) & 63;
  int stage_v_111_2 = ((pub_r001886_20_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((stage_v_40_1 + (pub_r001886_6_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((stage_v_40_2 + (pub_r001886_6_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((helper_flow_6_1 + (pub_r001886_17_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((helper_flow_6_2 + (pub_r001886_17_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((pub_r001886_17_1 * 2) + 38) & 63;
  int stage_v_114_2 = ((pub_r001886_17_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001886_18_1 * 2) + 28) & 63;
  int stage_v_115_2 = ((pub_r001886_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((stage_v_70_1 + (pub_r001886_12_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_70_2 + (pub_r001886_12_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((sec_r001886_20_1 + (pub_r001886_18_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((sec_r001886_20_2 + (pub_r001886_18_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((stage_v_16_1 + (pub_r001886_21_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_16_2 + (pub_r001886_21_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((stage_v_48_1 + (pub_r001886_0_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_48_2 + (pub_r001886_0_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((stage_v_55_1 + (pub_r001886_8_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_55_2 + (pub_r001886_8_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((stage_v_96_1 + (pub_r001886_9_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_96_2 + (pub_r001886_9_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((sec_r001886_10_1 + (pub_r001886_16_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((sec_r001886_10_2 + (pub_r001886_16_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((pub_r001886_16_1 * 2) + 7) & 63;
  int stage_v_123_2 = ((pub_r001886_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((sec_r001886_2_1 + (pub_r001886_11_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((sec_r001886_2_2 + (pub_r001886_11_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((stage_v_106_1 + (pub_r001886_15_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_106_2 + (pub_r001886_15_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((stage_v_72_1 + (pub_r001886_4_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_72_2 + (pub_r001886_4_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((sec_r001886_23_1 + (pub_r001886_16_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((sec_r001886_23_2 + (pub_r001886_16_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((pub_r001886_21_1 * 2) + 14) & 63;
  int stage_v_128_2 = ((pub_r001886_21_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((stage_v_112_1 + (pub_r001886_12_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_112_2 + (pub_r001886_12_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((pub_r001886_11_1 * 2) + 32) & 63;
  int stage_v_130_2 = ((pub_r001886_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((stage_v_75_1 + (pub_r001886_4_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_75_2 + (pub_r001886_4_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((sec_r001886_6_1 + (pub_r001886_10_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((sec_r001886_6_2 + (pub_r001886_10_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((stage_v_61_1 + (pub_r001886_6_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_61_2 + (pub_r001886_6_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((pub_r001886_13_1 * 2) + 9) & 63;
  int stage_v_134_2 = ((pub_r001886_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((stage_v_116_1 + (pub_r001886_5_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_116_2 + (pub_r001886_5_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((stage_v_64_1 + (pub_r001886_18_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_64_2 + (pub_r001886_18_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((pub_r001886_5_1 * 2) + 13) & 63;
  int stage_v_137_2 = ((pub_r001886_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001886_2_1 * 2) + 46) & 63;
  int stage_v_138_2 = ((pub_r001886_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001886_13_1 * 2) + 28) & 63;
  int stage_v_139_2 = ((pub_r001886_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((stage_v_118_1 + (pub_r001886_14_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_118_2 + (pub_r001886_14_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((sec_r001886_2_1 + (pub_r001886_15_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((sec_r001886_2_2 + (pub_r001886_15_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((pub_r001886_6_1 * 2) + 44) & 63;
  int stage_v_142_2 = ((pub_r001886_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001886_9_1 * 2) + 5) & 63;
  int stage_v_143_2 = ((pub_r001886_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001886_21_1 * 2) + 31) & 63;
  int stage_v_144_2 = ((pub_r001886_21_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((stage_v_65_1 + (pub_r001886_11_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_65_2 + (pub_r001886_11_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((sec_r001886_19_1 + (pub_r001886_19_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((sec_r001886_19_2 + (pub_r001886_19_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((pub_r001886_1_1 * 2) + 14) & 63;
  int stage_v_147_2 = ((pub_r001886_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((helper_flow_4_1 + (pub_r001886_17_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((helper_flow_4_2 + (pub_r001886_17_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((stage_v_10_1 + (pub_r001886_18_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((stage_v_10_2 + (pub_r001886_18_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((stage_v_103_1 + (pub_r001886_1_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_103_2 + (pub_r001886_1_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((stage_v_3_1 + (pub_r001886_16_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_3_2 + (pub_r001886_16_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((pub_r001886_9_1 * 2) + 14) & 63;
  int stage_v_152_2 = ((pub_r001886_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001886_4_1 * 2) + 46) & 63;
  int stage_v_153_2 = ((pub_r001886_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((stage_v_40_1 + (pub_r001886_20_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((stage_v_40_2 + (pub_r001886_20_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((pub_r001886_12_1 * 2) + 22) & 63;
  int stage_v_155_2 = ((pub_r001886_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001886_18_1 * 2) + 14) & 63;
  int stage_v_156_2 = ((pub_r001886_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((stage_v_57_1 + (pub_r001886_11_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_57_2 + (pub_r001886_11_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((sec_r001886_2_1 + (pub_r001886_9_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((sec_r001886_2_2 + (pub_r001886_9_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((stage_v_120_1 + (pub_r001886_10_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_120_2 + (pub_r001886_10_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_129_1 + (pub_r001886_15_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_129_2 + (pub_r001886_15_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((stage_v_57_1 + (pub_r001886_17_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_57_2 + (pub_r001886_17_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((sec_r001886_8_1 + (pub_r001886_18_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((sec_r001886_8_2 + (pub_r001886_18_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((stage_v_12_1 + (pub_r001886_9_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_12_2 + (pub_r001886_9_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((sec_r001886_4_1 + (pub_r001886_8_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((sec_r001886_4_2 + (pub_r001886_8_2 * 2)) + 497) & 127;
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
  int stage_v_165_1 = ((pub_r001886_10_1 * 2) + 49) & 63;
  int stage_v_165_2 = ((pub_r001886_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001886_10_1 * 2) + 41) & 63;
  int stage_v_166_2 = ((pub_r001886_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((stage_v_136_1 + (pub_r001886_19_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_136_2 + (pub_r001886_19_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_33_1 + (pub_r001886_14_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_33_2 + (pub_r001886_14_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_150_1 + (pub_r001886_19_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_150_2 + (pub_r001886_19_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((pub_r001886_2_1 * 2) + 12) & 63;
  int stage_v_170_2 = ((pub_r001886_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((stage_v_92_1 + (pub_r001886_13_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_92_2 + (pub_r001886_13_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((stage_v_141_1 + (pub_r001886_10_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_141_2 + (pub_r001886_10_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((helper_flow_0_1 + (pub_r001886_10_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((helper_flow_0_2 + (pub_r001886_10_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((stage_v_21_1 + (pub_r001886_9_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_21_2 + (pub_r001886_9_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((helper_flow_2_1 + (pub_r001886_4_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((helper_flow_2_2 + (pub_r001886_4_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((pub_r001886_21_1 * 2) + 10) & 63;
  int stage_v_176_2 = ((pub_r001886_21_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((sec_r001886_17_1 + (pub_r001886_8_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((sec_r001886_17_2 + (pub_r001886_8_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((pub_r001886_20_1 * 2) + 30) & 63;
  int stage_v_178_2 = ((pub_r001886_20_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((sec_r001886_20_1 + (pub_r001886_19_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((sec_r001886_20_2 + (pub_r001886_19_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((pub_r001886_4_1 * 2) + 43) & 63;
  int stage_v_180_2 = ((pub_r001886_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001886_3_1 * 2) + 33) & 63;
  int stage_v_181_2 = ((pub_r001886_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_164_1 + (pub_r001886_8_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_164_2 + (pub_r001886_8_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_63_1 + (pub_r001886_14_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_63_2 + (pub_r001886_14_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((stage_v_168_1 + (pub_r001886_4_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_168_2 + (pub_r001886_4_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_19_1 + (pub_r001886_13_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_19_2 + (pub_r001886_13_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((sec_r001886_1_1 + (pub_r001886_10_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((sec_r001886_1_2 + (pub_r001886_10_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((stage_v_185_1 + (pub_r001886_0_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_185_2 + (pub_r001886_0_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((helper_flow_6_1 + (pub_r001886_5_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((helper_flow_6_2 + (pub_r001886_5_2 * 2)) + 569) & 127;
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
  int stage_v_189_1 = ((stage_v_96_1 + (pub_r001886_4_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_96_2 + (pub_r001886_4_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((stage_v_25_1 + (pub_r001886_17_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_25_2 + (pub_r001886_17_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((sec_r001886_16_1 + (pub_r001886_19_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((sec_r001886_16_2 + (pub_r001886_19_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((pub_r001886_11_1 * 2) + 23) & 63;
  int stage_v_192_2 = ((pub_r001886_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((stage_v_71_1 + (pub_r001886_8_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_71_2 + (pub_r001886_8_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((pub_r001886_19_1 * 2) + 46) & 63;
  int stage_v_194_2 = ((pub_r001886_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((stage_v_89_1 + (pub_r001886_2_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_89_2 + (pub_r001886_2_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((stage_v_80_1 + (pub_r001886_18_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_80_2 + (pub_r001886_18_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((pub_r001886_12_1 * 2) + 15) & 63;
  int stage_v_197_2 = ((pub_r001886_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001886_11_1 * 2) + 8) & 63;
  int stage_v_198_2 = ((pub_r001886_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001886_18_1 * 2) + 22) & 63;
  int stage_v_199_2 = ((pub_r001886_18_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((sec_r001886_23_1 + (pub_r001886_14_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((sec_r001886_23_2 + (pub_r001886_14_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((stage_v_154_1 + (pub_r001886_18_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_154_2 + (pub_r001886_18_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((pub_r001886_15_1 * 2) + 28) & 63;
  int stage_v_202_2 = ((pub_r001886_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((sec_r001886_23_1 + (pub_r001886_5_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((sec_r001886_23_2 + (pub_r001886_5_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001886_8_1 != sec_r001886_8_2);
  __CPROVER_assume(sec_r001886_5_1 != sec_r001886_5_2);
  __CPROVER_assume(sec_r001886_21_1 != sec_r001886_21_2);
  __CPROVER_assume(sec_r001886_4_1 != sec_r001886_4_2);
  __CPROVER_assume(sec_r001886_12_1 != sec_r001886_12_2);
  __CPROVER_assume(sec_r001886_7_1 != sec_r001886_7_2);
  __CPROVER_assume(sec_r001886_16_1 != sec_r001886_16_2);
  __CPROVER_assume(sec_r001886_20_1 != sec_r001886_20_2);
  __CPROVER_assume(pub_r001886_18_1 == pub_r001886_18_2);
  __CPROVER_assume(pub_r001886_6_1 == pub_r001886_6_2);
  __CPROVER_assume(pub_r001886_10_1 == pub_r001886_10_2);
  __CPROVER_assume(sec_r001886_3_1 != sec_r001886_3_2);
  __CPROVER_assume(pub_r001886_5_1 == pub_r001886_5_2);
  __CPROVER_assume(pub_r001886_3_1 == pub_r001886_3_2);
  __CPROVER_assume(sec_r001886_19_1 != sec_r001886_19_2);
  __CPROVER_assume(pub_r001886_7_1 == pub_r001886_7_2);
  __CPROVER_assume(pub_r001886_4_1 == pub_r001886_4_2);
  __CPROVER_assume(pub_r001886_2_1 == pub_r001886_2_2);
  __CPROVER_assume(sec_r001886_23_1 != sec_r001886_23_2);
  __CPROVER_assume(sec_r001886_6_1 != sec_r001886_6_2);
  __CPROVER_assume(pub_r001886_12_1 == pub_r001886_12_2);
  __CPROVER_assume(pub_r001886_14_1 == pub_r001886_14_2);
  __CPROVER_assume(pub_r001886_13_1 == pub_r001886_13_2);
  __CPROVER_assume(sec_r001886_10_1 != sec_r001886_10_2);
  __CPROVER_assume(pub_r001886_15_1 == pub_r001886_15_2);
  __CPROVER_assume(pub_r001886_16_1 == pub_r001886_16_2);
  __CPROVER_assume(pub_r001886_21_1 == pub_r001886_21_2);
  __CPROVER_assume(sec_r001886_18_1 != sec_r001886_18_2);
  __CPROVER_assume(sec_r001886_0_1 != sec_r001886_0_2);
  __CPROVER_assume(pub_r001886_0_1 == pub_r001886_0_2);
  __CPROVER_assume(pub_r001886_1_1 == pub_r001886_1_2);
  __CPROVER_assume(pub_r001886_9_1 == pub_r001886_9_2);
  __CPROVER_assume(sec_r001886_22_1 != sec_r001886_22_2);
  __CPROVER_assume(pub_r001886_19_1 == pub_r001886_19_2);
  __CPROVER_assume(sec_r001886_11_1 != sec_r001886_11_2);
  __CPROVER_assume(sec_r001886_13_1 != sec_r001886_13_2);
  __CPROVER_assume(sec_r001886_17_1 != sec_r001886_17_2);
  __CPROVER_assume(pub_r001886_8_1 == pub_r001886_8_2);
  __CPROVER_assume(pub_r001886_20_1 == pub_r001886_20_2);
  __CPROVER_assume(sec_r001886_2_1 != sec_r001886_2_2);
  __CPROVER_assume(pub_r001886_17_1 == pub_r001886_17_2);
  __CPROVER_assume(sec_r001886_15_1 != sec_r001886_15_2);
  __CPROVER_assume(sec_r001886_9_1 != sec_r001886_9_2);
  __CPROVER_assume(pub_r001886_11_1 == pub_r001886_11_2);
  __CPROVER_assume(sec_r001886_1_1 != sec_r001886_1_2);
  __CPROVER_assume(sec_r001886_14_1 != sec_r001886_14_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.port == st_var_1_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.counter == st_var_2_2.counter);
  assert(st_var_2_1.tag == st_var_2_2.tag);
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
}


