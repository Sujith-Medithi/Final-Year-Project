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
struct DeviceConfig_R000836_3613_0
{
  unsigned char port;
  short parity;
  int id;
  int baud_rate;
  unsigned char timeout;
  int stop_bits;
  int buffer[3];
};
struct Vector3D_R000836_3613_1
{
  unsigned char coord_z;
  int coord_y;
  unsigned char norm_sq;
  short coord_x;
  short heading;
  short pitch;
  int buffer[3];
};
union TelemetryField_R000836_3613_0
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
void fn_R000836_3613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st_1 = {0};
  struct DeviceConfig_R000836_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int pivot_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_49_1) & 63;
  aux_2 = (aux_2 + pivot_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_28_1 = local_arr_1[aux_1 % 3];
  int residue_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_28_2 * 2)) & 127;
  int bound_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_74_1)
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

  switch (bound_74_2)
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

  int quantum_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_94_1 > 49)
  {
    acc_1 = ((acc_1 + (quantum_94_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_94_2 > 49)
  {
    acc_2 = ((acc_2 + (quantum_94_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_94_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_49_1 == pivot_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_28_1 == residue_28_2);
  assert(bound_74_1 == bound_74_2);
  assert(quantum_94_1 == quantum_94_2);
}

int fn_R000836_3613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int pivot_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_49) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_28 = local_arr[aux % 3];
  acc = (acc + (residue_28 * 2)) & 127;
  int bound_74 = (aux + st.buffer[1]) & 3;
  switch (bound_74)
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

  int quantum_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_94 > 49)
  {
    acc = ((acc + (quantum_94 * 2)) + 5) & 127;
    aux ^= quantum_94 & 15;
  }
  else
  {
    acc = ((acc - quantum_94) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000836_3613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st_1 = {0};
  struct DeviceConfig_R000836_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int quotient_43_1 = 0;
  int quotient_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_43_1 = ((quotient_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_43_2 = ((quotient_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_43_1) & 127;
    acc_2 = (acc_2 + quotient_43_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_79_1 > 10)
  {
    acc_1 = ((acc_1 + (factor_79_1 * 2)) + 5) & 127;
    aux_1 ^= factor_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_79_2 > 10)
  {
    acc_2 = ((acc_2 + (factor_79_2 * 2)) + 5) & 127;
    aux_2 ^= factor_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_79_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_43_1 == quotient_43_2);
  assert(factor_79_1 == factor_79_2);
}

int fn_R000836_3613_1(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quotient_43 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_43 = ((quotient_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_43) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_79 > 10)
  {
    acc = ((acc + (factor_79 * 2)) + 5) & 127;
    aux ^= factor_79 & 15;
  }
  else
  {
    acc = ((acc - factor_79) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000836_3613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st_1 = {0};
  struct DeviceConfig_R000836_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int cursor_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_47_1) & 63;
  aux_2 = (aux_2 + cursor_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_61_1 = local_arr_1[aux_1 % 3];
  int weight_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_61_2 * 2)) & 127;
  int index_reg_79_1 = 0;
  int index_reg_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_79_1 = ((index_reg_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_79_2 = ((index_reg_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_79_1) & 127;
    acc_2 = (acc_2 + index_reg_79_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_47_1 == cursor_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_61_1 == weight_61_2);
  assert(index_reg_79_1 == index_reg_79_2);
}

int fn_R000836_3613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int cursor_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_47) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_61 = local_arr[aux % 3];
  acc = (acc + (weight_61 * 2)) & 127;
  int index_reg_79 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_79 = ((index_reg_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_79) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000836_3613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000836_3613_1 st_1 = {0};
  struct Vector3D_R000836_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_63_1 = local_arr_1[aux_1 % 3];
  int segment_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_63_2 * 2)) & 127;
  int tally_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_68_1)
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

  switch (tally_68_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
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

  assert(segment_63_1 == segment_63_2);
  assert(tally_68_1 == tally_68_2);
}

int fn_R000836_3613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000836_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int segment_63 = local_arr[aux % 3];
  acc = (acc + (segment_63 * 2)) & 127;
  int tally_68 = (aux + st.buffer[1]) & 3;
  switch (tally_68)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000836_3613_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st_1 = {0};
  struct DeviceConfig_R000836_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int metric_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_71_1 > 40)
  {
    acc_1 = ((acc_1 + (metric_71_1 * 2)) + 5) & 127;
    aux_1 ^= metric_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_71_2 > 40)
  {
    acc_2 = ((acc_2 + (metric_71_2 * 2)) + 5) & 127;
    aux_2 ^= metric_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_12_1 = 0;
  int factor_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_12_1 = ((factor_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_12_2 = ((factor_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_12_1) & 127;
    acc_2 = (acc_2 + factor_12_2) & 127;
  }

  int index_reg_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_11_1)
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

  switch (index_reg_11_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_71_1 == metric_71_2);
  assert(factor_12_1 == factor_12_2);
  assert(index_reg_11_1 == index_reg_11_2);
}

int fn_R000836_3613_4(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int metric_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_71 > 40)
  {
    acc = ((acc + (metric_71 * 2)) + 5) & 127;
    aux ^= metric_71 & 15;
  }
  else
  {
    acc = ((acc - metric_71) + 11) & 127;
    aux += 3;
  }
  int factor_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_12 = ((factor_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_12) & 127;
  }

  int index_reg_11 = (aux + st.buffer[1]) & 3;
  switch (index_reg_11)
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

void fn_R000836_3613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000836_3613_1 st_1 = {0};
  struct Vector3D_R000836_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int phase_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_22_1)
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

  switch (phase_22_2)
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

  int scale_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_63_1 > 16)
  {
    acc_1 = ((acc_1 + (scale_63_1 * 2)) + 5) & 127;
    aux_1 ^= scale_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_63_2 > 16)
  {
    acc_2 = ((acc_2 + (scale_63_2 * 2)) + 5) & 127;
    aux_2 ^= scale_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_59_1 = 0;
  int parity_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_59_1 = ((parity_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_59_2 = ((parity_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_59_1) & 127;
    acc_2 = (acc_2 + parity_59_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_22_1 == phase_22_2);
  assert(scale_63_1 == scale_63_2);
  assert(parity_59_1 == parity_59_2);
}

int fn_R000836_3613_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000836_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int phase_22 = (aux + st.buffer[1]) & 3;
  switch (phase_22)
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

  int scale_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_63 > 16)
  {
    acc = ((acc + (scale_63 * 2)) + 5) & 127;
    aux ^= scale_63 & 15;
  }
  else
  {
    acc = ((acc - scale_63) + 11) & 127;
    aux += 3;
  }
  int parity_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_59 = ((parity_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_59) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000836_3613_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000836_3613_1 st_1 = {0};
  struct Vector3D_R000836_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int quantum_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_39_1) & 63;
  aux_2 = (aux_2 + quantum_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_80_1)
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

  switch (index_reg_80_2)
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

  int tracker_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_97_1 > 48)
  {
    acc_1 = ((acc_1 + (tracker_97_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_97_2 > 48)
  {
    acc_2 = ((acc_2 + (tracker_97_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_39_1 == quantum_39_2);
  assert(index_reg_80_1 == index_reg_80_2);
  assert(tracker_97_1 == tracker_97_2);
}

int fn_R000836_3613_6(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000836_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int quantum_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_39) & 63;
  acc ^= aux;
  int index_reg_80 = (aux + st.buffer[1]) & 3;
  switch (index_reg_80)
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

  int tracker_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_97 > 48)
  {
    acc = ((acc + (tracker_97 * 2)) + 5) & 127;
    aux ^= tracker_97 & 15;
  }
  else
  {
    acc = ((acc - tracker_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000836_3613_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000836_3613_1 st_1 = {0};
  struct Vector3D_R000836_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int index_reg_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_18_1 > 41)
  {
    acc_1 = ((acc_1 + (index_reg_18_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_18_2 > 41)
  {
    acc_2 = ((acc_2 + (index_reg_18_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_88_1)
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

  switch (checksum_88_2)
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
  int weight_85_1 = local_arr_1[aux_1 % 3];
  int weight_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_85_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_18_1 == index_reg_18_2);
  assert(checksum_88_1 == checksum_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_85_1 == weight_85_2);
}

int fn_R000836_3613_7(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000836_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int index_reg_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_18 > 41)
  {
    acc = ((acc + (index_reg_18 * 2)) + 5) & 127;
    aux ^= index_reg_18 & 15;
  }
  else
  {
    acc = ((acc - index_reg_18) + 11) & 127;
    aux += 3;
  }
  int checksum_88 = (aux + st.buffer[1]) & 3;
  switch (checksum_88)
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
  int weight_85 = local_arr[aux % 3];
  acc = (acc + (weight_85 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000836_3613_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000836_3613_1 st_1 = {0};
  struct Vector3D_R000836_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_29_1 = local_arr_1[aux_1 % 3];
  int window_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_29_2 * 2)) & 127;
  int cursor_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_80_1 > 41)
  {
    acc_1 = ((acc_1 + (cursor_80_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_80_2 > 41)
  {
    acc_2 = ((acc_2 + (cursor_80_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_69_1 = 0;
  int bound_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_69_1 = ((bound_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_69_2 = ((bound_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_69_1) & 127;
    acc_2 = (acc_2 + bound_69_2) & 127;
  }

  int mask_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_67_1)
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

  switch (mask_67_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
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

  assert(window_29_1 == window_29_2);
  assert(cursor_80_1 == cursor_80_2);
  assert(bound_69_1 == bound_69_2);
  assert(mask_67_1 == mask_67_2);
}

int fn_R000836_3613_8(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000836_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int window_29 = local_arr[aux % 3];
  acc = (acc + (window_29 * 2)) & 127;
  int cursor_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_80 > 41)
  {
    acc = ((acc + (cursor_80 * 2)) + 5) & 127;
    aux ^= cursor_80 & 15;
  }
  else
  {
    acc = ((acc - cursor_80) + 11) & 127;
    aux += 3;
  }
  int bound_69 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_69 = ((bound_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_69) & 127;
  }

  int mask_67 = (aux + st.buffer[1]) & 3;
  switch (mask_67)
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

void fn_R000836_3613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st_1 = {0};
  struct DeviceConfig_R000836_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_84_1 > 32)
  {
    acc_1 = ((acc_1 + (metric_84_1 * 2)) + 5) & 127;
    aux_1 ^= metric_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_84_2 > 32)
  {
    acc_2 = ((acc_2 + (metric_84_2 * 2)) + 5) & 127;
    aux_2 ^= metric_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_85_1 = local_arr_1[aux_1 % 3];
  int delta_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_85_2 * 2)) & 127;
  int residue_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_80_1)
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

  switch (residue_80_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_84_1 == metric_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_85_1 == delta_85_2);
  assert(residue_80_1 == residue_80_2);
}

int fn_R000836_3613_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_84 > 32)
  {
    acc = ((acc + (metric_84 * 2)) + 5) & 127;
    aux ^= metric_84 & 15;
  }
  else
  {
    acc = ((acc - metric_84) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_85 = local_arr[aux % 3];
  acc = (acc + (delta_85 * 2)) & 127;
  int residue_80 = (aux + st.buffer[1]) & 3;
  switch (residue_80)
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

void fn_R000836_3613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st_1 = {0};
  struct DeviceConfig_R000836_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int quantum_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_23_1) & 63;
  aux_2 = (aux_2 + quantum_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_89_1 = 0;
  int segment_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_89_1 = ((segment_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_89_2 = ((segment_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_89_1) & 127;
    acc_2 = (acc_2 + segment_89_2) & 127;
  }

  int residue_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_88_1)
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

  switch (residue_88_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_23_1 == quantum_23_2);
  assert(segment_89_1 == segment_89_2);
  assert(residue_88_1 == residue_88_2);
}

int fn_R000836_3613_10(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int quantum_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_23) & 63;
  acc ^= aux;
  int segment_89 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_89 = ((segment_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_89) & 127;
  }

  int residue_88 = (aux + st.buffer[1]) & 3;
  switch (residue_88)
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

void fn_R000836_3613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st_1 = {0};
  struct DeviceConfig_R000836_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_55_1 = local_arr_1[aux_1 % 3];
  int stride_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_55_2 * 2)) & 127;
  int mask_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_68_1) & 63;
  aux_2 = (aux_2 + mask_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_23_1 = 0;
  int delta_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_23_1 = ((delta_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_23_2 = ((delta_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_23_1) & 127;
    acc_2 = (acc_2 + delta_23_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_55_1 == stride_55_2);
  assert(mask_68_1 == mask_68_2);
  assert(delta_23_1 == delta_23_2);
}

int fn_R000836_3613_11(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int stride_55 = local_arr[aux % 3];
  acc = (acc + (stride_55 * 2)) & 127;
  int mask_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_68) & 63;
  acc ^= aux;
  int delta_23 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_23 = ((delta_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_23) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000836_3613_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000836_3613_1 st_1 = {0};
  struct Vector3D_R000836_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_66_1)
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

  switch (pivot_66_2)
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
  int tally_23_1 = local_arr_1[aux_1 % 3];
  int tally_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_23_2 * 2)) & 127;
  int coefficient_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_40_1 > 17)
  {
    acc_1 = ((acc_1 + (coefficient_40_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_40_2 > 17)
  {
    acc_2 = ((acc_2 + (coefficient_40_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_40_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_66_1 == pivot_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_23_1 == tally_23_2);
  assert(coefficient_40_1 == coefficient_40_2);
}

int fn_R000836_3613_12(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000836_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_66 = (aux + st.buffer[1]) & 3;
  switch (pivot_66)
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
  int tally_23 = local_arr[aux % 3];
  acc = (acc + (tally_23 * 2)) & 127;
  int coefficient_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_40 > 17)
  {
    acc = ((acc + (coefficient_40 * 2)) + 5) & 127;
    aux ^= coefficient_40 & 15;
  }
  else
  {
    acc = ((acc - coefficient_40) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000836_3613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st_1 = {0};
  struct DeviceConfig_R000836_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int coefficient_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_51_1)
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

  switch (coefficient_51_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_51_1 == coefficient_51_2);
}

int fn_R000836_3613_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000836_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int coefficient_51 = (aux + st.buffer[1]) & 3;
  switch (coefficient_51)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000836_0_1;
  int sec_r000836_0_2;
  int sec_r000836_1_1;
  int sec_r000836_1_2;
  int sec_r000836_2_1;
  int sec_r000836_2_2;
  int sec_r000836_3_1;
  int sec_r000836_3_2;
  int sec_r000836_4_1;
  int sec_r000836_4_2;
  int sec_r000836_5_1;
  int sec_r000836_5_2;
  int sec_r000836_6_1;
  int sec_r000836_6_2;
  int sec_r000836_7_1;
  int sec_r000836_7_2;
  int sec_r000836_8_1;
  int sec_r000836_8_2;
  int sec_r000836_9_1;
  int sec_r000836_9_2;
  int sec_r000836_10_1;
  int sec_r000836_10_2;
  int sec_r000836_11_1;
  int sec_r000836_11_2;
  int sec_r000836_12_1;
  int sec_r000836_12_2;
  int sec_r000836_13_1;
  int sec_r000836_13_2;
  int sec_r000836_14_1;
  int sec_r000836_14_2;
  int sec_r000836_15_1;
  int sec_r000836_15_2;
  int sec_r000836_16_1;
  int sec_r000836_16_2;
  int sec_r000836_17_1;
  int sec_r000836_17_2;
  int pub_r000836_0_1;
  int pub_r000836_0_2;
  int pub_r000836_1_1;
  int pub_r000836_1_2;
  int pub_r000836_2_1;
  int pub_r000836_2_2;
  int pub_r000836_3_1;
  int pub_r000836_3_2;
  int pub_r000836_4_1;
  int pub_r000836_4_2;
  int pub_r000836_5_1;
  int pub_r000836_5_2;
  int pub_r000836_6_1;
  int pub_r000836_6_2;
  int pub_r000836_7_1;
  int pub_r000836_7_2;
  int pub_r000836_8_1;
  int pub_r000836_8_2;
  int pub_r000836_9_1;
  int pub_r000836_9_2;
  int pub_r000836_10_1;
  int pub_r000836_10_2;
  int pub_r000836_11_1;
  int pub_r000836_11_2;
  int pub_r000836_12_1;
  int pub_r000836_12_2;
  int pub_r000836_13_1;
  int pub_r000836_13_2;
  int pub_r000836_14_1;
  int pub_r000836_14_2;
  int pub_r000836_15_1;
  int pub_r000836_15_2;
  int pub_r000836_16_1;
  int pub_r000836_16_2;
  int pub_r000836_17_1;
  int pub_r000836_17_2;
  int pub_r000836_18_1;
  int pub_r000836_18_2;
  int pub_r000836_19_1;
  int pub_r000836_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000836_0_1 >= (-100)) && (pub_r000836_0_1 <= 100));
  __CPROVER_assume((pub_r000836_0_2 >= (-100)) && (pub_r000836_0_2 <= 100));
  __CPROVER_assume((pub_r000836_1_1 >= (-100)) && (pub_r000836_1_1 <= 100));
  __CPROVER_assume((pub_r000836_1_2 >= (-100)) && (pub_r000836_1_2 <= 100));
  __CPROVER_assume((pub_r000836_2_1 >= (-100)) && (pub_r000836_2_1 <= 100));
  __CPROVER_assume((pub_r000836_2_2 >= (-100)) && (pub_r000836_2_2 <= 100));
  __CPROVER_assume((pub_r000836_3_1 >= (-100)) && (pub_r000836_3_1 <= 100));
  __CPROVER_assume((pub_r000836_3_2 >= (-100)) && (pub_r000836_3_2 <= 100));
  __CPROVER_assume((pub_r000836_4_1 >= (-100)) && (pub_r000836_4_1 <= 100));
  __CPROVER_assume((pub_r000836_4_2 >= (-100)) && (pub_r000836_4_2 <= 100));
  __CPROVER_assume((pub_r000836_5_1 >= (-100)) && (pub_r000836_5_1 <= 100));
  __CPROVER_assume((pub_r000836_5_2 >= (-100)) && (pub_r000836_5_2 <= 100));
  __CPROVER_assume((pub_r000836_6_1 >= (-100)) && (pub_r000836_6_1 <= 100));
  __CPROVER_assume((pub_r000836_6_2 >= (-100)) && (pub_r000836_6_2 <= 100));
  __CPROVER_assume((pub_r000836_7_1 >= (-100)) && (pub_r000836_7_1 <= 100));
  __CPROVER_assume((pub_r000836_7_2 >= (-100)) && (pub_r000836_7_2 <= 100));
  __CPROVER_assume((pub_r000836_8_1 >= (-100)) && (pub_r000836_8_1 <= 100));
  __CPROVER_assume((pub_r000836_8_2 >= (-100)) && (pub_r000836_8_2 <= 100));
  __CPROVER_assume((pub_r000836_9_1 >= (-100)) && (pub_r000836_9_1 <= 100));
  __CPROVER_assume((pub_r000836_9_2 >= (-100)) && (pub_r000836_9_2 <= 100));
  __CPROVER_assume((pub_r000836_10_1 >= (-100)) && (pub_r000836_10_1 <= 100));
  __CPROVER_assume((pub_r000836_10_2 >= (-100)) && (pub_r000836_10_2 <= 100));
  __CPROVER_assume((pub_r000836_11_1 >= (-100)) && (pub_r000836_11_1 <= 100));
  __CPROVER_assume((pub_r000836_11_2 >= (-100)) && (pub_r000836_11_2 <= 100));
  __CPROVER_assume((pub_r000836_12_1 >= (-100)) && (pub_r000836_12_1 <= 100));
  __CPROVER_assume((pub_r000836_12_2 >= (-100)) && (pub_r000836_12_2 <= 100));
  __CPROVER_assume((pub_r000836_13_1 >= (-100)) && (pub_r000836_13_1 <= 100));
  __CPROVER_assume((pub_r000836_13_2 >= (-100)) && (pub_r000836_13_2 <= 100));
  __CPROVER_assume((pub_r000836_14_1 >= (-100)) && (pub_r000836_14_1 <= 100));
  __CPROVER_assume((pub_r000836_14_2 >= (-100)) && (pub_r000836_14_2 <= 100));
  __CPROVER_assume((pub_r000836_15_1 >= (-100)) && (pub_r000836_15_1 <= 100));
  __CPROVER_assume((pub_r000836_15_2 >= (-100)) && (pub_r000836_15_2 <= 100));
  __CPROVER_assume((pub_r000836_16_1 >= (-100)) && (pub_r000836_16_1 <= 100));
  __CPROVER_assume((pub_r000836_16_2 >= (-100)) && (pub_r000836_16_2 <= 100));
  __CPROVER_assume((pub_r000836_17_1 >= (-100)) && (pub_r000836_17_1 <= 100));
  __CPROVER_assume((pub_r000836_17_2 >= (-100)) && (pub_r000836_17_2 <= 100));
  __CPROVER_assume((pub_r000836_18_1 >= (-100)) && (pub_r000836_18_1 <= 100));
  __CPROVER_assume((pub_r000836_18_2 >= (-100)) && (pub_r000836_18_2 <= 100));
  __CPROVER_assume((pub_r000836_19_1 >= (-100)) && (pub_r000836_19_1 <= 100));
  __CPROVER_assume((pub_r000836_19_2 >= (-100)) && (pub_r000836_19_2 <= 100));
  __CPROVER_assume((sec_r000836_0_1 >= 0) && (sec_r000836_0_1 <= 255));
  __CPROVER_assume((sec_r000836_0_2 >= 0) && (sec_r000836_0_2 <= 255));
  __CPROVER_assume((sec_r000836_1_1 >= 0) && (sec_r000836_1_1 <= 255));
  __CPROVER_assume((sec_r000836_1_2 >= 0) && (sec_r000836_1_2 <= 255));
  __CPROVER_assume((sec_r000836_2_1 >= 0) && (sec_r000836_2_1 <= 255));
  __CPROVER_assume((sec_r000836_2_2 >= 0) && (sec_r000836_2_2 <= 255));
  __CPROVER_assume((sec_r000836_3_1 >= 0) && (sec_r000836_3_1 <= 255));
  __CPROVER_assume((sec_r000836_3_2 >= 0) && (sec_r000836_3_2 <= 255));
  __CPROVER_assume((sec_r000836_4_1 >= 0) && (sec_r000836_4_1 <= 255));
  __CPROVER_assume((sec_r000836_4_2 >= 0) && (sec_r000836_4_2 <= 255));
  __CPROVER_assume((sec_r000836_5_1 >= 0) && (sec_r000836_5_1 <= 255));
  __CPROVER_assume((sec_r000836_5_2 >= 0) && (sec_r000836_5_2 <= 255));
  __CPROVER_assume((sec_r000836_6_1 >= 0) && (sec_r000836_6_1 <= 255));
  __CPROVER_assume((sec_r000836_6_2 >= 0) && (sec_r000836_6_2 <= 255));
  __CPROVER_assume((sec_r000836_7_1 >= 0) && (sec_r000836_7_1 <= 255));
  __CPROVER_assume((sec_r000836_7_2 >= 0) && (sec_r000836_7_2 <= 255));
  __CPROVER_assume((sec_r000836_8_1 >= 0) && (sec_r000836_8_1 <= 255));
  __CPROVER_assume((sec_r000836_8_2 >= 0) && (sec_r000836_8_2 <= 255));
  __CPROVER_assume((sec_r000836_9_1 >= 0) && (sec_r000836_9_1 <= 255));
  __CPROVER_assume((sec_r000836_9_2 >= 0) && (sec_r000836_9_2 <= 255));
  __CPROVER_assume((sec_r000836_10_1 >= 0) && (sec_r000836_10_1 <= 255));
  __CPROVER_assume((sec_r000836_10_2 >= 0) && (sec_r000836_10_2 <= 255));
  __CPROVER_assume((sec_r000836_11_1 >= 0) && (sec_r000836_11_1 <= 255));
  __CPROVER_assume((sec_r000836_11_2 >= 0) && (sec_r000836_11_2 <= 255));
  __CPROVER_assume((sec_r000836_12_1 >= 0) && (sec_r000836_12_1 <= 255));
  __CPROVER_assume((sec_r000836_12_2 >= 0) && (sec_r000836_12_2 <= 255));
  __CPROVER_assume((sec_r000836_13_1 >= 0) && (sec_r000836_13_1 <= 255));
  __CPROVER_assume((sec_r000836_13_2 >= 0) && (sec_r000836_13_2 <= 255));
  __CPROVER_assume((sec_r000836_14_1 >= 0) && (sec_r000836_14_1 <= 255));
  __CPROVER_assume((sec_r000836_14_2 >= 0) && (sec_r000836_14_2 <= 255));
  __CPROVER_assume((sec_r000836_15_1 >= 0) && (sec_r000836_15_1 <= 255));
  __CPROVER_assume((sec_r000836_15_2 >= 0) && (sec_r000836_15_2 <= 255));
  __CPROVER_assume((sec_r000836_16_1 >= 0) && (sec_r000836_16_1 <= 255));
  __CPROVER_assume((sec_r000836_16_2 >= 0) && (sec_r000836_16_2 <= 255));
  __CPROVER_assume((sec_r000836_17_1 >= 0) && (sec_r000836_17_1 <= 255));
  __CPROVER_assume((sec_r000836_17_2 >= 0) && (sec_r000836_17_2 <= 255));
  struct DeviceConfig_R000836_3613_0 st_var_0_1 = {0};
  struct DeviceConfig_R000836_3613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000836_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000836_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000836_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000836_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000836_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000836_0_2 + 7) & 15;
  struct Vector3D_R000836_3613_1 st_var_1_1 = {0};
  struct Vector3D_R000836_3613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000836_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000836_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000836_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000836_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000836_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000836_0_2 + 9) & 15;
  union TelemetryField_R000836_3613_0 u_var_1;
  union TelemetryField_R000836_3613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_0_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_0_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_0_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 3) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 4) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = ((st_var_0_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_0_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 28)
    {
      chk_sum_1 ^= stage_v_6_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_6_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 28)
    {
      chk_sum_2 ^= stage_v_6_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = (st_var_0_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_0_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = ((st_var_1_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_1_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 41)
    {
      chk_sum_1 ^= stage_v_11_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_11_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 41)
    {
      chk_sum_2 ^= stage_v_11_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = ((st_var_1_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_1_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 30)
    {
      chk_sum_1 ^= stage_v_15_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_15_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 30)
    {
      chk_sum_2 ^= stage_v_15_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
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
  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  int stage_v_26_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (31 & 31);
  int stage_v_26_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (31 & 31);
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= (stage_v_26_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_26_2 << 1) & 127;
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_29_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (34 & 31);
  int stage_v_29_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (34 & 31);
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= (stage_v_29_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_29_2 << 1) & 127;
  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_33_1 = ((stage_v_33_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_33_2 = ((stage_v_33_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (st_var_1_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_1_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
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

  switch (stage_v_35_2)
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

  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
  int stage_v_38_1 = (st_var_0_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_0_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
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

  switch (stage_v_38_2)
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

  int stage_v_39_1 = ((st_var_1_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_1_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 51)
    {
      chk_sum_1 ^= stage_v_39_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_39_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 51)
    {
      chk_sum_2 ^= stage_v_39_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 37)
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
  if (stage_v_41_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 37)
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
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = table_1[3];
  int stage_v_43_2 = table_2[3];
  table_1[3] = (table_1[0] + 87) & 63;
  table_2[3] = (table_2[0] + 87) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
  int stage_v_45_1 = table_1[1];
  int stage_v_45_2 = table_2[1];
  table_1[1] = (table_1[2] + 91) & 63;
  table_2[1] = (table_2[2] + 91) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 53)
    {
      chk_sum_1 ^= stage_v_49_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_49_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 53)
    {
      chk_sum_2 ^= stage_v_49_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_50_1 = ((st_var_0_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_0_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 51)
    {
      chk_sum_1 ^= stage_v_50_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_50_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 51)
    {
      chk_sum_2 ^= stage_v_50_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((st_var_0_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_0_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 45)
    {
      chk_sum_1 ^= stage_v_52_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_52_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 45)
    {
      chk_sum_2 ^= stage_v_52_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = (st_var_0_1.buffer[0] ^ 57) & 3;
  int stage_v_54_2 = (st_var_0_2.buffer[0] ^ 57) & 3;
  switch (stage_v_54_1)
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

  switch (stage_v_54_2)
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

  int stage_v_55_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (60 & 31);
  int stage_v_55_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (60 & 31);
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= (stage_v_55_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_55_2 << 1) & 127;
  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_59_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 61) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 61) & 15;
  int stage_v_60_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_60_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= stage_v_60_1;
  chk_sum_2 ^= stage_v_60_2;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_61_1 = ((stage_v_61_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_61_2 = ((stage_v_61_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (67 & 31);
  int stage_v_62_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (67 & 31);
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= (stage_v_62_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_62_2 << 1) & 127;
  int stage_v_63_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_63_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_64_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (69 & 31);
  int stage_v_64_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (69 & 31);
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= (stage_v_64_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_64_2 << 1) & 127;
  int stage_v_65_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_65_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_65_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_65_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_66_1 = table_1[2];
  int stage_v_66_2 = table_2[2];
  table_1[2] = (table_1[3] + 133) & 63;
  table_2[2] = (table_2[3] + 133) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_67_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_67_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_67_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 70) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 70) & 15;
  int stage_v_69_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_69_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= stage_v_69_1;
  chk_sum_2 ^= stage_v_69_2;
  int stage_v_70_1 = table_1[2];
  int stage_v_70_2 = table_2[2];
  table_1[2] = (table_1[3] + 141) & 63;
  table_2[2] = (table_2[3] + 141) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (st_var_1_1.buffer[0] ^ 74) & 3;
  int stage_v_71_2 = (st_var_1_2.buffer[0] ^ 74) & 3;
  switch (stage_v_71_1)
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

  switch (stage_v_71_2)
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

  int stage_v_72_1 = (st_var_0_1.buffer[0] ^ 75) & 3;
  int stage_v_72_2 = (st_var_0_2.buffer[0] ^ 75) & 3;
  switch (stage_v_72_1)
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

  switch (stage_v_72_2)
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

  int stage_v_73_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_73_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_74_1 = (st_var_0_1.buffer[0] ^ 77) & 3;
  int stage_v_74_2 = (st_var_0_2.buffer[0] ^ 77) & 3;
  switch (stage_v_74_1)
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

  switch (stage_v_74_2)
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

  int stage_v_75_1 = ((st_var_1_1.buffer[0] * 2) + 232) & 63;
  int stage_v_75_2 = ((st_var_1_2.buffer[0] * 2) + 232) & 63;
  if (stage_v_75_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_75_1) - 5) & 255;
    if (stage_v_75_1 > 52)
    {
      chk_sum_1 ^= stage_v_75_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_75_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_75_2) - 5) & 255;
    if (stage_v_75_2 > 52)
    {
      chk_sum_2 ^= stage_v_75_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_76_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_76_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_76_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_76_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 80) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 80) & 15;
  int stage_v_79_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_79_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  chk_sum_1 ^= stage_v_79_1;
  chk_sum_2 ^= stage_v_79_2;
  int stage_v_80_1 = table_1[0];
  int stage_v_80_2 = table_2[0];
  table_1[0] = (table_1[1] + 161) & 63;
  table_2[0] = (table_2[1] + 161) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (86 & 31);
  int stage_v_81_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (86 & 31);
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  chk_sum_1 ^= (stage_v_81_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_81_2 << 1) & 127;
  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (st_var_1_1.buffer[0] ^ 86) & 3;
  int stage_v_83_2 = (st_var_1_2.buffer[0] ^ 86) & 3;
  switch (stage_v_83_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 8) & 255;
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

  switch (stage_v_83_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 8) & 255;
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

  int stage_v_84_1 = (st_var_0_1.buffer[0] ^ 87) & 3;
  int stage_v_84_2 = (st_var_0_2.buffer[0] ^ 87) & 3;
  switch (stage_v_84_1)
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

  switch (stage_v_84_2)
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

  int stage_v_85_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (90 & 31);
  int stage_v_85_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (90 & 31);
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= (stage_v_85_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_85_2 << 1) & 127;
  int stage_v_86_1 = (st_var_0_1.buffer[0] ^ 89) & 3;
  int stage_v_86_2 = (st_var_0_2.buffer[0] ^ 89) & 3;
  switch (stage_v_86_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 8) & 255;
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

  switch (stage_v_86_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 8) & 255;
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

  int stage_v_87_1 = ((st_var_1_1.buffer[0] * 2) + 268) & 63;
  int stage_v_87_2 = ((st_var_1_2.buffer[0] * 2) + 268) & 63;
  if (stage_v_87_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_87_1) - 5) & 255;
    if (stage_v_87_1 > 51)
    {
      chk_sum_1 ^= stage_v_87_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_87_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_87_2) - 5) & 255;
    if (stage_v_87_2 > 51)
    {
      chk_sum_2 ^= stage_v_87_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_88_1 = ((st_var_0_1.buffer[1] * 2) + 271) & 63;
  int stage_v_88_2 = ((st_var_0_2.buffer[1] * 2) + 271) & 63;
  if (stage_v_88_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_88_1) - 5) & 255;
    if (stage_v_88_1 > 42)
    {
      chk_sum_1 ^= stage_v_88_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_88_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_88_2) - 5) & 255;
    if (stage_v_88_2 > 42)
    {
      chk_sum_2 ^= stage_v_88_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_89_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (94 & 31);
  int stage_v_89_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (94 & 31);
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= (stage_v_89_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_89_2 << 1) & 127;
  int stage_v_90_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (95 & 31);
  int stage_v_90_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (95 & 31);
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  chk_sum_1 ^= (stage_v_90_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_90_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 92) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 92) & 15;
  int stage_v_91_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_91_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  chk_sum_1 ^= stage_v_91_1;
  chk_sum_2 ^= stage_v_91_2;
  int stage_v_92_1 = (st_var_0_1.buffer[0] ^ 95) & 3;
  int stage_v_92_2 = (st_var_0_2.buffer[0] ^ 95) & 3;
  switch (stage_v_92_1)
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

  switch (stage_v_92_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 94) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 94) & 15;
  int stage_v_93_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_93_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  chk_sum_1 ^= stage_v_93_1;
  chk_sum_2 ^= stage_v_93_2;
  int stage_v_94_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (99 & 31);
  int stage_v_94_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (99 & 31);
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  chk_sum_1 ^= (stage_v_94_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_94_2 << 1) & 127;
  int stage_v_95_1 = (st_var_1_1.buffer[0] ^ 98) & 3;
  int stage_v_95_2 = (st_var_1_2.buffer[0] ^ 98) & 3;
  switch (stage_v_95_1)
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

  switch (stage_v_95_2)
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

  int stage_v_96_1 = (st_var_0_1.buffer[0] ^ 99) & 3;
  int stage_v_96_2 = (st_var_0_2.buffer[0] ^ 99) & 3;
  switch (stage_v_96_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 8) & 255;
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

  switch (stage_v_96_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 8) & 255;
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

  int stage_v_97_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_97_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_97_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_97_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_98_1 = (st_var_0_1.buffer[0] ^ 101) & 3;
  int stage_v_98_2 = (st_var_0_2.buffer[0] ^ 101) & 3;
  switch (stage_v_98_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 3) & 255;
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

  switch (stage_v_98_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 3) & 255;
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

  int stage_v_99_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_99_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_99_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_99_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_100_1 = table_1[0];
  int stage_v_100_2 = table_2[0];
  table_1[0] = (table_1[1] + 201) & 63;
  table_2[0] = (table_2[1] + 201) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_101_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_101_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_101_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_102_1 = ((st_var_0_1.buffer[0] * 2) + 313) & 63;
  int stage_v_102_2 = ((st_var_0_2.buffer[0] * 2) + 313) & 63;
  if (stage_v_102_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_102_1) - 5) & 255;
    if (stage_v_102_1 > 49)
    {
      chk_sum_1 ^= stage_v_102_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_102_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_102_2) - 5) & 255;
    if (stage_v_102_2 > 49)
    {
      chk_sum_2 ^= stage_v_102_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 104) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 104) & 15;
  int stage_v_103_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_103_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  chk_sum_1 ^= stage_v_103_1;
  chk_sum_2 ^= stage_v_103_2;
  int stage_v_104_1 = table_1[0];
  int stage_v_104_2 = table_2[0];
  table_1[0] = (table_1[1] + 209) & 63;
  table_2[0] = (table_2[1] + 209) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (110 & 31);
  int stage_v_105_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (110 & 31);
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= (stage_v_105_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_105_2 << 1) & 127;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_106_1 = ((stage_v_106_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_106_2 = ((stage_v_106_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_107_1 = ((stage_v_107_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_107_2 = ((stage_v_107_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (st_var_0_1.buffer[0] ^ 111) & 3;
  int stage_v_108_2 = (st_var_0_2.buffer[0] ^ 111) & 3;
  switch (stage_v_108_1)
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

  switch (stage_v_108_2)
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

  int stage_v_109_1 = table_1[1];
  int stage_v_109_2 = table_2[1];
  table_1[1] = (table_1[2] + 219) & 63;
  table_2[1] = (table_2[2] + 219) & 63;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (st_var_0_1.buffer[0] ^ 113) & 3;
  int stage_v_110_2 = (st_var_0_2.buffer[0] ^ 113) & 3;
  switch (stage_v_110_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 3) & 255;
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

  switch (stage_v_110_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 3) & 255;
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

  int stage_v_111_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_111_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_111_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_111_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 113) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 113) & 15;
  int stage_v_112_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_112_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  chk_sum_1 ^= stage_v_112_1;
  chk_sum_2 ^= stage_v_112_2;
  int stage_v_113_1 = ((st_var_1_1.buffer[2] * 2) + 346) & 63;
  int stage_v_113_2 = ((st_var_1_2.buffer[2] * 2) + 346) & 63;
  if (stage_v_113_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_113_1) - 5) & 255;
    if (stage_v_113_1 > 30)
    {
      chk_sum_1 ^= stage_v_113_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_113_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_113_2) - 5) & 255;
    if (stage_v_113_2 > 30)
    {
      chk_sum_2 ^= stage_v_113_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_114_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (119 & 31);
  int stage_v_114_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (119 & 31);
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= (stage_v_114_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_114_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 116) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 116) & 15;
  int stage_v_115_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_115_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  chk_sum_1 ^= stage_v_115_1;
  chk_sum_2 ^= stage_v_115_2;
  int stage_v_116_1 = table_1[0];
  int stage_v_116_2 = table_2[0];
  table_1[0] = (table_1[1] + 233) & 63;
  table_2[0] = (table_2[1] + 233) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (st_var_1_1.buffer[0] ^ 120) & 3;
  int stage_v_117_2 = (st_var_1_2.buffer[0] ^ 120) & 3;
  switch (stage_v_117_1)
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

  switch (stage_v_117_2)
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

  int stage_v_118_1 = table_1[2];
  int stage_v_118_2 = table_2[2];
  table_1[2] = (table_1[3] + 237) & 63;
  table_2[2] = (table_2[3] + 237) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = table_1[3];
  int stage_v_119_2 = table_2[3];
  table_1[3] = (table_1[0] + 239) & 63;
  table_2[3] = (table_2[0] + 239) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (125 & 31);
  int stage_v_120_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (125 & 31);
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  chk_sum_1 ^= (stage_v_120_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_120_2 << 1) & 127;
  int stage_v_121_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_121_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_121_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_121_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_122_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_122_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_122_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_122_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_123_1 = ((stage_v_123_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_123_2 = ((stage_v_123_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = table_1[0];
  int stage_v_124_2 = table_2[0];
  table_1[0] = (table_1[1] + 249) & 63;
  table_2[0] = (table_2[1] + 249) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 126) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 126) & 15;
  int stage_v_125_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_125_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  chk_sum_1 ^= stage_v_125_1;
  chk_sum_2 ^= stage_v_125_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 127) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 127) & 15;
  int stage_v_126_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_126_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  chk_sum_1 ^= stage_v_126_1;
  chk_sum_2 ^= stage_v_126_2;
  int stage_v_127_1 = (st_var_1_1.buffer[0] ^ 130) & 3;
  int stage_v_127_2 = (st_var_1_2.buffer[0] ^ 130) & 3;
  switch (stage_v_127_1)
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

  switch (stage_v_127_2)
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

  int stage_v_128_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_128_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_128_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_128_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_129_1 = (st_var_1_1.buffer[0] ^ 132) & 3;
  int stage_v_129_2 = (st_var_1_2.buffer[0] ^ 132) & 3;
  switch (stage_v_129_1)
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

  switch (stage_v_129_2)
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

  int stage_v_130_1 = table_1[2];
  int stage_v_130_2 = table_2[2];
  table_1[2] = (table_1[3] + 261) & 63;
  table_2[2] = (table_2[3] + 261) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_131_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_131_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_131_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_132_1 = table_1[0];
  int stage_v_132_2 = table_2[0];
  table_1[0] = (table_1[1] + 265) & 63;
  table_2[0] = (table_2[1] + 265) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_133_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_133_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_133_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_134_1 = ((stage_v_134_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_134_2 = ((stage_v_134_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 136) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 136) & 15;
  int stage_v_135_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_135_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  chk_sum_1 ^= stage_v_135_1;
  chk_sum_2 ^= stage_v_135_2;
  int stage_v_136_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (141 & 31);
  int stage_v_136_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (141 & 31);
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  chk_sum_1 ^= (stage_v_136_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_136_2 << 1) & 127;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_137_1 = ((stage_v_137_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_137_2 = ((stage_v_137_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (st_var_0_1.buffer[0] ^ 141) & 3;
  int stage_v_138_2 = (st_var_0_2.buffer[0] ^ 141) & 3;
  switch (stage_v_138_1)
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

  switch (stage_v_138_2)
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

  int stage_v_139_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_139_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_139_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_139_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_140_1 = table_1[0];
  int stage_v_140_2 = table_2[0];
  table_1[0] = (table_1[1] + 281) & 63;
  table_2[0] = (table_2[1] + 281) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 142) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 142) & 15;
  int stage_v_141_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_141_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  chk_sum_1 ^= stage_v_141_1;
  chk_sum_2 ^= stage_v_141_2;
  int stage_v_142_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_142_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_142_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_142_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_144_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_144_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_144_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_145_1 = (st_var_1_1.buffer[0] ^ 148) & 3;
  int stage_v_145_2 = (st_var_1_2.buffer[0] ^ 148) & 3;
  switch (stage_v_145_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 8) & 255;
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

  switch (stage_v_145_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 8) & 255;
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

  int stage_v_146_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_146_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_146_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_146_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_147_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (152 & 31);
  int stage_v_147_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (152 & 31);
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  chk_sum_1 ^= (stage_v_147_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_147_2 << 1) & 127;
  int stage_v_148_1 = ((st_var_0_1.buffer[1] * 2) + 451) & 63;
  int stage_v_148_2 = ((st_var_0_2.buffer[1] * 2) + 451) & 63;
  if (stage_v_148_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_148_1) - 5) & 255;
    if (stage_v_148_1 > 35)
    {
      chk_sum_1 ^= stage_v_148_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_148_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_148_2) - 5) & 255;
    if (stage_v_148_2 > 35)
    {
      chk_sum_2 ^= stage_v_148_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_149_1 = ((st_var_1_1.buffer[2] * 2) + 454) & 63;
  int stage_v_149_2 = ((st_var_1_2.buffer[2] * 2) + 454) & 63;
  if (stage_v_149_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_149_1) - 5) & 255;
    if (stage_v_149_1 > 28)
    {
      chk_sum_1 ^= stage_v_149_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_149_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_149_2) - 5) & 255;
    if (stage_v_149_2 > 28)
    {
      chk_sum_2 ^= stage_v_149_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_150_1 = (st_var_0_1.buffer[0] ^ 153) & 3;
  int stage_v_150_2 = (st_var_0_2.buffer[0] ^ 153) & 3;
  switch (stage_v_150_1)
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

  switch (stage_v_150_2)
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

  int stage_v_151_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (156 & 31);
  int stage_v_151_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (156 & 31);
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  chk_sum_1 ^= (stage_v_151_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_151_2 << 1) & 127;
  int stage_v_152_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_152_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_153_1 = ((st_var_1_1.buffer[0] * 2) + 466) & 63;
  int stage_v_153_2 = ((st_var_1_2.buffer[0] * 2) + 466) & 63;
  if (stage_v_153_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_153_1) - 5) & 255;
    if (stage_v_153_1 > 28)
    {
      chk_sum_1 ^= stage_v_153_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_153_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_153_2) - 5) & 255;
    if (stage_v_153_2 > 28)
    {
      chk_sum_2 ^= stage_v_153_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_154_1 = (st_var_0_1.buffer[0] ^ 157) & 3;
  int stage_v_154_2 = (st_var_0_2.buffer[0] ^ 157) & 3;
  switch (stage_v_154_1)
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

  switch (stage_v_154_2)
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 156) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 156) & 15;
  int stage_v_155_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_155_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  chk_sum_1 ^= stage_v_155_1;
  chk_sum_2 ^= stage_v_155_2;
  int stage_v_156_1 = ((st_var_0_1.buffer[0] * 2) + 475) & 63;
  int stage_v_156_2 = ((st_var_0_2.buffer[0] * 2) + 475) & 63;
  if (stage_v_156_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_156_1) - 5) & 255;
    if (stage_v_156_1 > 42)
    {
      chk_sum_1 ^= stage_v_156_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_156_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_156_2) - 5) & 255;
    if (stage_v_156_2 > 42)
    {
      chk_sum_2 ^= stage_v_156_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_157_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (162 & 31);
  int stage_v_157_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (162 & 31);
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  chk_sum_1 ^= (stage_v_157_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_157_2 << 1) & 127;
  int stage_v_158_1 = ((st_var_0_1.buffer[2] * 2) + 481) & 63;
  int stage_v_158_2 = ((st_var_0_2.buffer[2] * 2) + 481) & 63;
  if (stage_v_158_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_158_1) - 5) & 255;
    if (stage_v_158_1 > 40)
    {
      chk_sum_1 ^= stage_v_158_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_158_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_158_2) - 5) & 255;
    if (stage_v_158_2 > 40)
    {
      chk_sum_2 ^= stage_v_158_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 160) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 160) & 15;
  int stage_v_159_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_159_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  chk_sum_1 ^= stage_v_159_1;
  chk_sum_2 ^= stage_v_159_2;
  int stage_v_160_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_160_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_160_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_160_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 162) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 162) & 15;
  int stage_v_161_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_161_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  chk_sum_1 ^= stage_v_161_1;
  chk_sum_2 ^= stage_v_161_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 163) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 163) & 15;
  int stage_v_162_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_162_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  chk_sum_1 ^= stage_v_162_1;
  chk_sum_2 ^= stage_v_162_2;
  int stage_v_163_1 = (st_var_1_1.buffer[0] ^ 166) & 3;
  int stage_v_163_2 = (st_var_1_2.buffer[0] ^ 166) & 3;
  switch (stage_v_163_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 3) & 255;
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

  switch (stage_v_163_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 3) & 255;
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 165) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 165) & 15;
  int stage_v_164_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_164_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  chk_sum_1 ^= stage_v_164_1;
  chk_sum_2 ^= stage_v_164_2;
  int stage_v_165_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_165_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_165_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_165_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_166_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_166_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_166_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_166_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_167_1 = table_1[3];
  int stage_v_167_2 = table_2[3];
  table_1[3] = (table_1[0] + 335) & 63;
  table_2[3] = (table_2[0] + 335) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_168_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_168_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_168_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_169_1 = ((st_var_1_1.buffer[1] * 2) + 514) & 63;
  int stage_v_169_2 = ((st_var_1_2.buffer[1] * 2) + 514) & 63;
  if (stage_v_169_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_169_1) - 5) & 255;
    if (stage_v_169_1 > 31)
    {
      chk_sum_1 ^= stage_v_169_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_169_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_169_2) - 5) & 255;
    if (stage_v_169_2 > 31)
    {
      chk_sum_2 ^= stage_v_169_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 171) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 171) & 15;
  int stage_v_170_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_170_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  chk_sum_1 ^= stage_v_170_1;
  chk_sum_2 ^= stage_v_170_2;
  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_171_1 = ((stage_v_171_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_171_2 = ((stage_v_171_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_172_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_172_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_172_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_173_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (178 & 31);
  int stage_v_173_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (178 & 31);
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  chk_sum_1 ^= (stage_v_173_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_173_2 << 1) & 127;
  int stage_v_174_1 = (st_var_0_1.buffer[0] ^ 177) & 3;
  int stage_v_174_2 = (st_var_0_2.buffer[0] ^ 177) & 3;
  switch (stage_v_174_1)
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

  switch (stage_v_174_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 176) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 176) & 15;
  int stage_v_175_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_175_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  chk_sum_1 ^= stage_v_175_1;
  chk_sum_2 ^= stage_v_175_2;
  int stage_v_176_1 = (st_var_0_1.buffer[0] ^ 179) & 3;
  int stage_v_176_2 = (st_var_0_2.buffer[0] ^ 179) & 3;
  switch (stage_v_176_1)
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

  switch (stage_v_176_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 178) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 178) & 15;
  int stage_v_177_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_177_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  chk_sum_1 ^= stage_v_177_1;
  chk_sum_2 ^= stage_v_177_2;
  int stage_v_178_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_178_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_178_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_178_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_179_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (184 & 31);
  int stage_v_179_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (184 & 31);
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  chk_sum_1 ^= (stage_v_179_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_179_2 << 1) & 127;
  int stage_v_180_1 = (st_var_0_1.buffer[0] ^ 183) & 3;
  int stage_v_180_2 = (st_var_0_2.buffer[0] ^ 183) & 3;
  switch (stage_v_180_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 8) & 255;
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

  switch (stage_v_180_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 8) & 255;
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

  int stage_v_181_1 = table_1[1];
  int stage_v_181_2 = table_2[1];
  table_1[1] = (table_1[2] + 363) & 63;
  table_2[1] = (table_2[2] + 363) & 63;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_182_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_182_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_182_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_183_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_183_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_183_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_183_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_184_1 = 0;
  int stage_v_184_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_184_1 = ((stage_v_184_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_184_2 = ((stage_v_184_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((st_var_1_1.buffer[2] * 2) + 562) & 63;
  int stage_v_185_2 = ((st_var_1_2.buffer[2] * 2) + 562) & 63;
  if (stage_v_185_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_185_1) - 5) & 255;
    if (stage_v_185_1 > 29)
    {
      chk_sum_1 ^= stage_v_185_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_185_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_185_2) - 5) & 255;
    if (stage_v_185_2 > 29)
    {
      chk_sum_2 ^= stage_v_185_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_186_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_186_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_186_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_186_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_187_1 = table_1[3];
  int stage_v_187_2 = table_2[3];
  table_1[3] = (table_1[0] + 375) & 63;
  table_2[3] = (table_2[0] + 375) & 63;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = table_1[0];
  int stage_v_188_2 = table_2[0];
  table_1[0] = (table_1[1] + 377) & 63;
  table_2[0] = (table_2[1] + 377) & 63;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 190) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 190) & 15;
  int stage_v_189_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_189_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  chk_sum_1 ^= stage_v_189_1;
  chk_sum_2 ^= stage_v_189_2;
  int stage_v_190_1 = ((st_var_0_1.buffer[1] * 2) + 577) & 63;
  int stage_v_190_2 = ((st_var_0_2.buffer[1] * 2) + 577) & 63;
  if (stage_v_190_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_190_1) - 5) & 255;
    if (stage_v_190_1 > 34)
    {
      chk_sum_1 ^= stage_v_190_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_190_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_190_2) - 5) & 255;
    if (stage_v_190_2 > 34)
    {
      chk_sum_2 ^= stage_v_190_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_191_1 = 0;
  int stage_v_191_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_191_1 = ((stage_v_191_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_191_2 = ((stage_v_191_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_192_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_192_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_192_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 194) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 194) & 15;
  int stage_v_193_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_193_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  chk_sum_1 ^= stage_v_193_1;
  chk_sum_2 ^= stage_v_193_2;
  int stage_v_194_1 = table_1[2];
  int stage_v_194_2 = table_2[2];
  table_1[2] = (table_1[3] + 389) & 63;
  table_2[2] = (table_2[3] + 389) & 63;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (st_var_1_1.buffer[0] ^ 198) & 3;
  int stage_v_195_2 = (st_var_1_2.buffer[0] ^ 198) & 3;
  switch (stage_v_195_1)
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

  switch (stage_v_195_2)
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

  int stage_v_196_1 = table_1[0];
  int stage_v_196_2 = table_2[0];
  table_1[0] = (table_1[1] + 393) & 63;
  table_2[0] = (table_2[1] + 393) & 63;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = table_1[1];
  int stage_v_197_2 = table_2[1];
  table_1[1] = (table_1[2] + 395) & 63;
  table_2[1] = (table_2[2] + 395) & 63;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((st_var_0_1.buffer[0] * 2) + 601) & 63;
  int stage_v_198_2 = ((st_var_0_2.buffer[0] * 2) + 601) & 63;
  if (stage_v_198_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_198_1) - 5) & 255;
    if (stage_v_198_1 > 54)
    {
      chk_sum_1 ^= stage_v_198_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_198_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_198_2) - 5) & 255;
    if (stage_v_198_2 > 54)
    {
      chk_sum_2 ^= stage_v_198_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_199_1 = 0;
  int stage_v_199_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_199_1 = ((stage_v_199_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_199_2 = ((stage_v_199_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = table_1[0];
  int stage_v_200_2 = table_2[0];
  table_1[0] = (table_1[1] + 401) & 63;
  table_2[0] = (table_2[1] + 401) & 63;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = 0;
  int stage_v_201_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_201_1 = ((stage_v_201_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_201_2 = ((stage_v_201_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = table_1[2];
  int stage_v_202_2 = table_2[2];
  table_1[2] = (table_1[3] + 405) & 63;
  table_2[2] = (table_2[3] + 405) & 63;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = table_1[3];
  int stage_v_203_2 = table_2[3];
  table_1[3] = (table_1[0] + 407) & 63;
  table_2[3] = (table_2[0] + 407) & 63;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = 0;
  int stage_v_204_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_204_1 = ((stage_v_204_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_204_2 = ((stage_v_204_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = (st_var_1_1.buffer[0] ^ 208) & 3;
  int stage_v_205_2 = (st_var_1_2.buffer[0] ^ 208) & 3;
  switch (stage_v_205_1)
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

  switch (stage_v_205_2)
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

  int stage_v_206_1 = (st_var_0_1.buffer[0] ^ 209) & 3;
  int stage_v_206_2 = (st_var_0_2.buffer[0] ^ 209) & 3;
  switch (stage_v_206_1)
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

  switch (stage_v_206_2)
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

  int stage_v_207_1 = 0;
  int stage_v_207_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_207_1 = ((stage_v_207_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_207_2 = ((stage_v_207_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = table_1[0];
  int stage_v_208_2 = table_2[0];
  table_1[0] = (table_1[1] + 417) & 63;
  table_2[0] = (table_2[1] + 417) & 63;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = table_1[1];
  int stage_v_209_2 = table_2[1];
  table_1[1] = (table_1[2] + 419) & 63;
  table_2[1] = (table_2[2] + 419) & 63;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 211) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 211) & 15;
  int stage_v_210_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_210_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  chk_sum_1 ^= stage_v_210_1;
  chk_sum_2 ^= stage_v_210_2;
  int stage_v_211_1 = (st_var_1_1.buffer[0] ^ 214) & 3;
  int stage_v_211_2 = (st_var_1_2.buffer[0] ^ 214) & 3;
  switch (stage_v_211_1)
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

  switch (stage_v_211_2)
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

  int stage_v_212_1 = table_1[0];
  int stage_v_212_2 = table_2[0];
  table_1[0] = (table_1[1] + 425) & 63;
  table_2[0] = (table_2[1] + 425) & 63;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int s_lut_1[4] = {61, 98, 30, 55};
  int s_lut_2[4] = {61, 98, 30, 55};
  int s_idx_1 = sec_r000836_1_1 & 3;
  int s_idx_2 = sec_r000836_1_2 & 3;
  out_sink_1 += s_lut_1[s_idx_1];
  out_sink_2 += s_lut_2[s_idx_2];
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000836_2_1 != sec_r000836_2_2);
  __CPROVER_assume(pub_r000836_6_1 == pub_r000836_6_2);
  __CPROVER_assume(sec_r000836_1_1 != sec_r000836_1_2);
  __CPROVER_assume(sec_r000836_0_1 != sec_r000836_0_2);
  __CPROVER_assume(pub_r000836_13_1 == pub_r000836_13_2);
  __CPROVER_assume(sec_r000836_8_1 != sec_r000836_8_2);
  __CPROVER_assume(pub_r000836_16_1 == pub_r000836_16_2);
  __CPROVER_assume(sec_r000836_6_1 != sec_r000836_6_2);
  __CPROVER_assume(sec_r000836_12_1 != sec_r000836_12_2);
  __CPROVER_assume(pub_r000836_2_1 == pub_r000836_2_2);
  __CPROVER_assume(pub_r000836_1_1 == pub_r000836_1_2);
  __CPROVER_assume(pub_r000836_8_1 == pub_r000836_8_2);
  __CPROVER_assume(pub_r000836_14_1 == pub_r000836_14_2);
  __CPROVER_assume(pub_r000836_15_1 == pub_r000836_15_2);
  __CPROVER_assume(sec_r000836_17_1 != sec_r000836_17_2);
  __CPROVER_assume(pub_r000836_0_1 == pub_r000836_0_2);
  __CPROVER_assume(sec_r000836_4_1 != sec_r000836_4_2);
  __CPROVER_assume(pub_r000836_3_1 == pub_r000836_3_2);
  __CPROVER_assume(sec_r000836_10_1 != sec_r000836_10_2);
  __CPROVER_assume(pub_r000836_12_1 == pub_r000836_12_2);
  __CPROVER_assume(pub_r000836_10_1 == pub_r000836_10_2);
  __CPROVER_assume(sec_r000836_13_1 != sec_r000836_13_2);
  __CPROVER_assume(sec_r000836_15_1 != sec_r000836_15_2);
  __CPROVER_assume(sec_r000836_5_1 != sec_r000836_5_2);
  __CPROVER_assume(pub_r000836_4_1 == pub_r000836_4_2);
  __CPROVER_assume(pub_r000836_19_1 == pub_r000836_19_2);
  __CPROVER_assume(pub_r000836_18_1 == pub_r000836_18_2);
  __CPROVER_assume(pub_r000836_7_1 == pub_r000836_7_2);
  __CPROVER_assume(sec_r000836_16_1 != sec_r000836_16_2);
  __CPROVER_assume(sec_r000836_9_1 != sec_r000836_9_2);
  __CPROVER_assume(pub_r000836_11_1 == pub_r000836_11_2);
  __CPROVER_assume(sec_r000836_7_1 != sec_r000836_7_2);
  __CPROVER_assume(sec_r000836_14_1 != sec_r000836_14_2);
  __CPROVER_assume(pub_r000836_17_1 == pub_r000836_17_2);
  __CPROVER_assume(sec_r000836_11_1 != sec_r000836_11_2);
  __CPROVER_assume(sec_r000836_3_1 != sec_r000836_3_2);
  __CPROVER_assume(pub_r000836_9_1 == pub_r000836_9_2);
  __CPROVER_assume(pub_r000836_5_1 == pub_r000836_5_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
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
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    assert(s_lut_1[i_0] == s_lut_2[i_0]);
  }

  assert(s_idx_1 == s_idx_2);
}


