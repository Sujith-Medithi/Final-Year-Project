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
struct DeviceConfig_R001343_4313_0
{
  unsigned char parity;
  int port;
  short id;
  int timeout;
  int buffer[3];
};
struct Vector3D_R001343_4313_1
{
  int norm_sq;
  int coord_x;
  unsigned char coord_y;
  int pitch;
  int buffer[3];
};
struct SensorNode_R001343_4313_2
{
  unsigned char threshold;
  int status;
  unsigned char calib;
  int offset;
  int reading;
  int gain;
  int buffer[3];
};
union ColorPixel_R001343_4313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001343_4313_1
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
void fn_R001343_4313_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st_1 = {0};
  struct DeviceConfig_R001343_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int pivot_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_34_1)
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

  switch (pivot_34_2)
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

  int factor_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_26_1 > 44)
  {
    acc_1 = ((acc_1 + (factor_26_1 * 2)) + 5) & 127;
    aux_1 ^= factor_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_26_2 > 44)
  {
    acc_2 = ((acc_2 + (factor_26_2 * 2)) + 5) & 127;
    aux_2 ^= factor_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_26_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_34_1 == pivot_34_2);
  assert(factor_26_1 == factor_26_2);
}

int fn_R001343_4313_0(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int pivot_34 = (aux + st.buffer[1]) & 3;
  switch (pivot_34)
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

  int factor_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_26 > 44)
  {
    acc = ((acc + (factor_26 * 2)) + 5) & 127;
    aux ^= factor_26 & 15;
  }
  else
  {
    acc = ((acc - factor_26) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001343_4313_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st_1 = {0};
  struct DeviceConfig_R001343_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int segment_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_57_1 > 45)
  {
    acc_1 = ((acc_1 + (segment_57_1 * 2)) + 5) & 127;
    aux_1 ^= segment_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_57_2 > 45)
  {
    acc_2 = ((acc_2 + (segment_57_2 * 2)) + 5) & 127;
    aux_2 ^= segment_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_60_1) & 63;
  aux_2 = (aux_2 + anchor_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_57_1 == segment_57_2);
  assert(anchor_60_1 == anchor_60_2);
}

int fn_R001343_4313_1(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int segment_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_57 > 45)
  {
    acc = ((acc + (segment_57 * 2)) + 5) & 127;
    aux ^= segment_57 & 15;
  }
  else
  {
    acc = ((acc - segment_57) + 11) & 127;
    aux += 3;
  }
  int anchor_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_60) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001343_4313_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st_1 = {0};
  struct DeviceConfig_R001343_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_59_1 = local_arr_1[aux_1 % 3];
  int pivot_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_59_2 * 2)) & 127;
  int quantum_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_14_1 > 17)
  {
    acc_1 = ((acc_1 + (quantum_14_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_14_2 > 17)
  {
    acc_2 = ((acc_2 + (quantum_14_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_63_1 = 0;
  int bound_63_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_63_1 = ((bound_63_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_63_2 = ((bound_63_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_63_1) & 127;
    acc_2 = (acc_2 + bound_63_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_59_1 == pivot_59_2);
  assert(quantum_14_1 == quantum_14_2);
  assert(bound_63_1 == bound_63_2);
}

int fn_R001343_4313_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int pivot_59 = local_arr[aux % 3];
  acc = (acc + (pivot_59 * 2)) & 127;
  int quantum_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_14 > 17)
  {
    acc = ((acc + (quantum_14 * 2)) + 5) & 127;
    aux ^= quantum_14 & 15;
  }
  else
  {
    acc = ((acc - quantum_14) + 11) & 127;
    aux += 3;
  }
  int bound_63 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_63 = ((bound_63 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_63) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001343_4313_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001343_4313_1 st_1 = {0};
  struct Vector3D_R001343_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int pivot_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_19_1 > 28)
  {
    acc_1 = ((acc_1 + (pivot_19_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_19_2 > 28)
  {
    acc_2 = ((acc_2 + (pivot_19_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_74_1 = 0;
  int factor_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_74_1 = ((factor_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_74_2 = ((factor_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_74_1) & 127;
    acc_2 = (acc_2 + factor_74_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_19_1 == pivot_19_2);
  assert(factor_74_1 == factor_74_2);
}

int fn_R001343_4313_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001343_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int pivot_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_19 > 28)
  {
    acc = ((acc + (pivot_19 * 2)) + 5) & 127;
    aux ^= pivot_19 & 15;
  }
  else
  {
    acc = ((acc - pivot_19) + 11) & 127;
    aux += 3;
  }
  int factor_74 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_74 = ((factor_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_74) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001343_4313_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st_1 = {0};
  struct DeviceConfig_R001343_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int residue_97_1 = 0;
  int residue_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_97_1 = ((residue_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_97_2 = ((residue_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_97_1) & 127;
    acc_2 = (acc_2 + residue_97_2) & 127;
  }

  int index_reg_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_75_1) & 63;
  aux_2 = (aux_2 + index_reg_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_97_1 == residue_97_2);
  assert(index_reg_75_1 == index_reg_75_2);
}

int fn_R001343_4313_4(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int residue_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_97 = ((residue_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_97) & 127;
  }

  int index_reg_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_75) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001343_4313_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001343_4313_1 st_1 = {0};
  struct Vector3D_R001343_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int mask_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_38_1)
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

  switch (mask_38_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_10_1) & 63;
  aux_2 = (aux_2 + coefficient_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_38_1 == mask_38_2);
  assert(coefficient_10_1 == coefficient_10_2);
}

int fn_R001343_4313_5(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001343_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int mask_38 = (aux + st.buffer[1]) & 3;
  switch (mask_38)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_10) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001343_4313_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001343_4313_2 st_1 = {0};
  struct SensorNode_R001343_4313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int tracker_67_1 = 0;
  int tracker_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_67_1 = ((tracker_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_67_2 = ((tracker_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_67_1) & 127;
    acc_2 = (acc_2 + tracker_67_2) & 127;
  }

  int anchor_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_69_1 > 36)
  {
    acc_1 = ((acc_1 + (anchor_69_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_69_2 > 36)
  {
    acc_2 = ((acc_2 + (anchor_69_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_69_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_67_1 == tracker_67_2);
  assert(anchor_69_1 == anchor_69_2);
}

int fn_R001343_4313_6(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001343_4313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int tracker_67 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_67 = ((tracker_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_67) & 127;
  }

  int anchor_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_69 > 36)
  {
    acc = ((acc + (anchor_69 * 2)) + 5) & 127;
    aux ^= anchor_69 & 15;
  }
  else
  {
    acc = ((acc - anchor_69) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001343_4313_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st_1 = {0};
  struct DeviceConfig_R001343_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int stride_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_31_1 > 15)
  {
    acc_1 = ((acc_1 + (stride_31_1 * 2)) + 5) & 127;
    aux_1 ^= stride_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_31_2 > 15)
  {
    acc_2 = ((acc_2 + (stride_31_2 * 2)) + 5) & 127;
    aux_2 ^= stride_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_31_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_80_1 = local_arr_1[aux_1 % 3];
  int checksum_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_31_1 == stride_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_80_1 == checksum_80_2);
}

int fn_R001343_4313_7(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int stride_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_31 > 15)
  {
    acc = ((acc + (stride_31 * 2)) + 5) & 127;
    aux ^= stride_31 & 15;
  }
  else
  {
    acc = ((acc - stride_31) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_80 = local_arr[aux % 3];
  acc = (acc + (checksum_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001343_4313_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001343_4313_1 st_1 = {0};
  struct Vector3D_R001343_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int margin_89_1 = 0;
  int margin_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_89_1 = ((margin_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_89_2 = ((margin_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_89_1) & 127;
    acc_2 = (acc_2 + margin_89_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_89_1 == margin_89_2);
}

int fn_R001343_4313_8(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001343_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int margin_89 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_89 = ((margin_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_89) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001343_4313_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st_1 = {0};
  struct DeviceConfig_R001343_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_63_1 = local_arr_1[aux_1 % 3];
  int accumulator_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_63_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_72_1) & 63;
  aux_2 = (aux_2 + coefficient_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_63_1 == accumulator_63_2);
  assert(coefficient_72_1 == coefficient_72_2);
}

int fn_R001343_4313_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int accumulator_63 = local_arr[aux % 3];
  acc = (acc + (accumulator_63 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_72) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001343_4313_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001343_4313_2 st_1 = {0};
  struct SensorNode_R001343_4313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int phase_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_77_1)
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

  switch (phase_77_2)
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

  int parity_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_22_1) & 63;
  aux_2 = (aux_2 + parity_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_33_1 = 0;
  int stride_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_33_1 = ((stride_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_33_2 = ((stride_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_33_1) & 127;
    acc_2 = (acc_2 + stride_33_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_77_1 == phase_77_2);
  assert(parity_22_1 == parity_22_2);
  assert(stride_33_1 == stride_33_2);
}

int fn_R001343_4313_10(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001343_4313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int phase_77 = (aux + st.buffer[1]) & 3;
  switch (phase_77)
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

  int parity_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_22) & 63;
  acc ^= aux;
  int stride_33 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_33 = ((stride_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_33) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001343_4313_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st_1 = {0};
  struct DeviceConfig_R001343_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int segment_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_48_1 > 27)
  {
    acc_1 = ((acc_1 + (segment_48_1 * 2)) + 5) & 127;
    aux_1 ^= segment_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_48_2 > 27)
  {
    acc_2 = ((acc_2 + (segment_48_2 * 2)) + 5) & 127;
    aux_2 ^= segment_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_15_1 = 0;
  int delta_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_15_1 = ((delta_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_15_2 = ((delta_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_15_1) & 127;
    acc_2 = (acc_2 + delta_15_2) & 127;
  }

  int stride_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_87_1)
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

  switch (stride_87_2)
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
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_48_1 == segment_48_2);
  assert(delta_15_1 == delta_15_2);
  assert(stride_87_1 == stride_87_2);
}

int fn_R001343_4313_11(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int segment_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_48 > 27)
  {
    acc = ((acc + (segment_48 * 2)) + 5) & 127;
    aux ^= segment_48 & 15;
  }
  else
  {
    acc = ((acc - segment_48) + 11) & 127;
    aux += 3;
  }
  int delta_15 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_15 = ((delta_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_15) & 127;
  }

  int stride_87 = (aux + st.buffer[1]) & 3;
  switch (stride_87)
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

void fn_R001343_4313_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st_1 = {0};
  struct DeviceConfig_R001343_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int delta_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_35_1 > 12)
  {
    acc_1 = ((acc_1 + (delta_35_1 * 2)) + 5) & 127;
    aux_1 ^= delta_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_35_2 > 12)
  {
    acc_2 = ((acc_2 + (delta_35_2 * 2)) + 5) & 127;
    aux_2 ^= delta_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_47_1)
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

  switch (phase_47_2)
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
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_35_1 == delta_35_2);
  assert(phase_47_1 == phase_47_2);
}

int fn_R001343_4313_12(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int delta_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_35 > 12)
  {
    acc = ((acc + (delta_35 * 2)) + 5) & 127;
    aux ^= delta_35 & 15;
  }
  else
  {
    acc = ((acc - delta_35) + 11) & 127;
    aux += 3;
  }
  int phase_47 = (aux + st.buffer[1]) & 3;
  switch (phase_47)
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

void fn_R001343_4313_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001343_4313_2 st_1 = {0};
  struct SensorNode_R001343_4313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int tally_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_36_1 > 28)
  {
    acc_1 = ((acc_1 + (tally_36_1 * 2)) + 5) & 127;
    aux_1 ^= tally_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_36_2 > 28)
  {
    acc_2 = ((acc_2 + (tally_36_2 * 2)) + 5) & 127;
    aux_2 ^= tally_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_36_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_17_1) & 63;
  aux_2 = (aux_2 + checksum_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_95_1 = local_arr_1[aux_1 % 3];
  int cursor_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_36_1 == tally_36_2);
  assert(checksum_17_1 == checksum_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_95_1 == cursor_95_2);
}

int fn_R001343_4313_13(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001343_4313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int tally_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_36 > 28)
  {
    acc = ((acc + (tally_36 * 2)) + 5) & 127;
    aux ^= tally_36 & 15;
  }
  else
  {
    acc = ((acc - tally_36) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_17) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_95 = local_arr[aux % 3];
  acc = (acc + (cursor_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001343_4313_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001343_4313_1 st_1 = {0};
  struct Vector3D_R001343_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int sample_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_35_1) & 63;
  aux_2 = (aux_2 + sample_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_36_1)
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

  switch (mask_36_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_68_1 = local_arr_1[aux_1 % 3];
  int coefficient_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_68_2 * 2)) & 127;
  int residue_27_1 = 0;
  int residue_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_27_1 = ((residue_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_27_2 = ((residue_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_27_1) & 127;
    acc_2 = (acc_2 + residue_27_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_35_1 == sample_35_2);
  assert(mask_36_1 == mask_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_68_1 == coefficient_68_2);
  assert(residue_27_1 == residue_27_2);
}

int fn_R001343_4313_14(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001343_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int sample_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_35) & 63;
  acc ^= aux;
  int mask_36 = (aux + st.buffer[1]) & 3;
  switch (mask_36)
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

  int local_arr[3] = {4, 9, 15};
  int coefficient_68 = local_arr[aux % 3];
  acc = (acc + (coefficient_68 * 2)) & 127;
  int residue_27 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_27 = ((residue_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_27) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001343_4313_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001343_4313_2 st_1 = {0};
  struct SensorNode_R001343_4313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int index_reg_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_21_1)
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

  switch (index_reg_21_2)
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

  int stride_63_1 = 0;
  int stride_63_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_63_1 = ((stride_63_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_63_2 = ((stride_63_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_63_1) & 127;
    acc_2 = (acc_2 + stride_63_2) & 127;
  }

  int damping_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_33_1 > 11)
  {
    acc_1 = ((acc_1 + (damping_33_1 * 2)) + 5) & 127;
    aux_1 ^= damping_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_33_2 > 11)
  {
    acc_2 = ((acc_2 + (damping_33_2 * 2)) + 5) & 127;
    aux_2 ^= damping_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_28_1) & 63;
  aux_2 = (aux_2 + damping_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_21_1 == index_reg_21_2);
  assert(stride_63_1 == stride_63_2);
  assert(damping_33_1 == damping_33_2);
  assert(damping_28_1 == damping_28_2);
}

int fn_R001343_4313_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001343_4313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int index_reg_21 = (aux + st.buffer[1]) & 3;
  switch (index_reg_21)
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

  int stride_63 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_63 = ((stride_63 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_63) & 127;
  }

  int damping_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_33 > 11)
  {
    acc = ((acc + (damping_33 * 2)) + 5) & 127;
    aux ^= damping_33 & 15;
  }
  else
  {
    acc = ((acc - damping_33) + 11) & 127;
    aux += 3;
  }
  int damping_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_28) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001343_4313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st_1 = {0};
  struct DeviceConfig_R001343_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int accumulator_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_19_1 > 25)
  {
    acc_1 = ((acc_1 + (accumulator_19_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_19_2 > 25)
  {
    acc_2 = ((acc_2 + (accumulator_19_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_50_1 = local_arr_1[aux_1 % 3];
  int tally_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_50_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_19_1 == accumulator_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_50_1 == tally_50_2);
}

int fn_R001343_4313_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int accumulator_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_19 > 25)
  {
    acc = ((acc + (accumulator_19 * 2)) + 5) & 127;
    aux ^= accumulator_19 & 15;
  }
  else
  {
    acc = ((acc - accumulator_19) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_50 = local_arr[aux % 3];
  acc = (acc + (tally_50 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001343_4313_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001343_4313_1 st_1 = {0};
  struct Vector3D_R001343_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_53_1 = local_arr_1[aux_1 % 3];
  int weight_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_53_2 * 2)) & 127;
  int quantum_47_1 = 0;
  int quantum_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_47_1 = ((quantum_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_47_2 = ((quantum_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_47_1) & 127;
    acc_2 = (acc_2 + quantum_47_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_53_1 == weight_53_2);
  assert(quantum_47_1 == quantum_47_2);
}

int fn_R001343_4313_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001343_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int weight_53 = local_arr[aux % 3];
  acc = (acc + (weight_53 * 2)) & 127;
  int quantum_47 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_47 = ((quantum_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_47) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001343_4313_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st_1 = {0};
  struct DeviceConfig_R001343_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int factor_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_91_1)
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

  switch (factor_91_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_75_1 > 46)
  {
    acc_1 = ((acc_1 + (quantum_75_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_75_2 > 46)
  {
    acc_2 = ((acc_2 + (quantum_75_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_52_1 = local_arr_1[aux_1 % 3];
  int cursor_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_91_1 == factor_91_2);
  assert(quantum_75_1 == quantum_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_52_1 == cursor_52_2);
}

int fn_R001343_4313_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001343_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int factor_91 = (aux + st.buffer[1]) & 3;
  switch (factor_91)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_75 > 46)
  {
    acc = ((acc + (quantum_75 * 2)) + 5) & 127;
    aux ^= quantum_75 & 15;
  }
  else
  {
    acc = ((acc - quantum_75) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_52 = local_arr[aux % 3];
  acc = (acc + (cursor_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001343_0_1;
  int sec_r001343_0_2;
  int sec_r001343_1_1;
  int sec_r001343_1_2;
  int sec_r001343_2_1;
  int sec_r001343_2_2;
  int sec_r001343_3_1;
  int sec_r001343_3_2;
  int sec_r001343_4_1;
  int sec_r001343_4_2;
  int sec_r001343_5_1;
  int sec_r001343_5_2;
  int sec_r001343_6_1;
  int sec_r001343_6_2;
  int sec_r001343_7_1;
  int sec_r001343_7_2;
  int sec_r001343_8_1;
  int sec_r001343_8_2;
  int sec_r001343_9_1;
  int sec_r001343_9_2;
  int sec_r001343_10_1;
  int sec_r001343_10_2;
  int sec_r001343_11_1;
  int sec_r001343_11_2;
  int sec_r001343_12_1;
  int sec_r001343_12_2;
  int sec_r001343_13_1;
  int sec_r001343_13_2;
  int sec_r001343_14_1;
  int sec_r001343_14_2;
  int sec_r001343_15_1;
  int sec_r001343_15_2;
  int sec_r001343_16_1;
  int sec_r001343_16_2;
  int sec_r001343_17_1;
  int sec_r001343_17_2;
  int sec_r001343_18_1;
  int sec_r001343_18_2;
  int sec_r001343_19_1;
  int sec_r001343_19_2;
  int sec_r001343_20_1;
  int sec_r001343_20_2;
  int sec_r001343_21_1;
  int sec_r001343_21_2;
  int sec_r001343_22_1;
  int sec_r001343_22_2;
  int pub_r001343_0_1;
  int pub_r001343_0_2;
  int pub_r001343_1_1;
  int pub_r001343_1_2;
  int pub_r001343_2_1;
  int pub_r001343_2_2;
  int pub_r001343_3_1;
  int pub_r001343_3_2;
  int pub_r001343_4_1;
  int pub_r001343_4_2;
  int pub_r001343_5_1;
  int pub_r001343_5_2;
  int pub_r001343_6_1;
  int pub_r001343_6_2;
  int pub_r001343_7_1;
  int pub_r001343_7_2;
  int pub_r001343_8_1;
  int pub_r001343_8_2;
  int pub_r001343_9_1;
  int pub_r001343_9_2;
  int pub_r001343_10_1;
  int pub_r001343_10_2;
  int pub_r001343_11_1;
  int pub_r001343_11_2;
  int pub_r001343_12_1;
  int pub_r001343_12_2;
  int pub_r001343_13_1;
  int pub_r001343_13_2;
  int pub_r001343_14_1;
  int pub_r001343_14_2;
  int pub_r001343_15_1;
  int pub_r001343_15_2;
  int pub_r001343_16_1;
  int pub_r001343_16_2;
  int pub_r001343_17_1;
  int pub_r001343_17_2;
  int pub_r001343_18_1;
  int pub_r001343_18_2;
  int pub_r001343_19_1;
  int pub_r001343_19_2;
  int pub_r001343_20_1;
  int pub_r001343_20_2;
  int pub_r001343_21_1;
  int pub_r001343_21_2;
  int pub_r001343_22_1;
  int pub_r001343_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001343_0_1 >= (-100)) && (pub_r001343_0_1 <= 100));
  __CPROVER_assume((pub_r001343_0_2 >= (-100)) && (pub_r001343_0_2 <= 100));
  __CPROVER_assume((pub_r001343_1_1 >= (-100)) && (pub_r001343_1_1 <= 100));
  __CPROVER_assume((pub_r001343_1_2 >= (-100)) && (pub_r001343_1_2 <= 100));
  __CPROVER_assume((pub_r001343_2_1 >= (-100)) && (pub_r001343_2_1 <= 100));
  __CPROVER_assume((pub_r001343_2_2 >= (-100)) && (pub_r001343_2_2 <= 100));
  __CPROVER_assume((pub_r001343_3_1 >= (-100)) && (pub_r001343_3_1 <= 100));
  __CPROVER_assume((pub_r001343_3_2 >= (-100)) && (pub_r001343_3_2 <= 100));
  __CPROVER_assume((pub_r001343_4_1 >= (-100)) && (pub_r001343_4_1 <= 100));
  __CPROVER_assume((pub_r001343_4_2 >= (-100)) && (pub_r001343_4_2 <= 100));
  __CPROVER_assume((pub_r001343_5_1 >= (-100)) && (pub_r001343_5_1 <= 100));
  __CPROVER_assume((pub_r001343_5_2 >= (-100)) && (pub_r001343_5_2 <= 100));
  __CPROVER_assume((pub_r001343_6_1 >= (-100)) && (pub_r001343_6_1 <= 100));
  __CPROVER_assume((pub_r001343_6_2 >= (-100)) && (pub_r001343_6_2 <= 100));
  __CPROVER_assume((pub_r001343_7_1 >= (-100)) && (pub_r001343_7_1 <= 100));
  __CPROVER_assume((pub_r001343_7_2 >= (-100)) && (pub_r001343_7_2 <= 100));
  __CPROVER_assume((pub_r001343_8_1 >= (-100)) && (pub_r001343_8_1 <= 100));
  __CPROVER_assume((pub_r001343_8_2 >= (-100)) && (pub_r001343_8_2 <= 100));
  __CPROVER_assume((pub_r001343_9_1 >= (-100)) && (pub_r001343_9_1 <= 100));
  __CPROVER_assume((pub_r001343_9_2 >= (-100)) && (pub_r001343_9_2 <= 100));
  __CPROVER_assume((pub_r001343_10_1 >= (-100)) && (pub_r001343_10_1 <= 100));
  __CPROVER_assume((pub_r001343_10_2 >= (-100)) && (pub_r001343_10_2 <= 100));
  __CPROVER_assume((pub_r001343_11_1 >= (-100)) && (pub_r001343_11_1 <= 100));
  __CPROVER_assume((pub_r001343_11_2 >= (-100)) && (pub_r001343_11_2 <= 100));
  __CPROVER_assume((pub_r001343_12_1 >= (-100)) && (pub_r001343_12_1 <= 100));
  __CPROVER_assume((pub_r001343_12_2 >= (-100)) && (pub_r001343_12_2 <= 100));
  __CPROVER_assume((pub_r001343_13_1 >= (-100)) && (pub_r001343_13_1 <= 100));
  __CPROVER_assume((pub_r001343_13_2 >= (-100)) && (pub_r001343_13_2 <= 100));
  __CPROVER_assume((pub_r001343_14_1 >= (-100)) && (pub_r001343_14_1 <= 100));
  __CPROVER_assume((pub_r001343_14_2 >= (-100)) && (pub_r001343_14_2 <= 100));
  __CPROVER_assume((pub_r001343_15_1 >= (-100)) && (pub_r001343_15_1 <= 100));
  __CPROVER_assume((pub_r001343_15_2 >= (-100)) && (pub_r001343_15_2 <= 100));
  __CPROVER_assume((pub_r001343_16_1 >= (-100)) && (pub_r001343_16_1 <= 100));
  __CPROVER_assume((pub_r001343_16_2 >= (-100)) && (pub_r001343_16_2 <= 100));
  __CPROVER_assume((pub_r001343_17_1 >= (-100)) && (pub_r001343_17_1 <= 100));
  __CPROVER_assume((pub_r001343_17_2 >= (-100)) && (pub_r001343_17_2 <= 100));
  __CPROVER_assume((pub_r001343_18_1 >= (-100)) && (pub_r001343_18_1 <= 100));
  __CPROVER_assume((pub_r001343_18_2 >= (-100)) && (pub_r001343_18_2 <= 100));
  __CPROVER_assume((pub_r001343_19_1 >= (-100)) && (pub_r001343_19_1 <= 100));
  __CPROVER_assume((pub_r001343_19_2 >= (-100)) && (pub_r001343_19_2 <= 100));
  __CPROVER_assume((pub_r001343_20_1 >= (-100)) && (pub_r001343_20_1 <= 100));
  __CPROVER_assume((pub_r001343_20_2 >= (-100)) && (pub_r001343_20_2 <= 100));
  __CPROVER_assume((pub_r001343_21_1 >= (-100)) && (pub_r001343_21_1 <= 100));
  __CPROVER_assume((pub_r001343_21_2 >= (-100)) && (pub_r001343_21_2 <= 100));
  __CPROVER_assume((pub_r001343_22_1 >= (-100)) && (pub_r001343_22_1 <= 100));
  __CPROVER_assume((pub_r001343_22_2 >= (-100)) && (pub_r001343_22_2 <= 100));
  __CPROVER_assume((sec_r001343_0_1 >= 0) && (sec_r001343_0_1 <= 255));
  __CPROVER_assume((sec_r001343_0_2 >= 0) && (sec_r001343_0_2 <= 255));
  __CPROVER_assume((sec_r001343_1_1 >= 0) && (sec_r001343_1_1 <= 255));
  __CPROVER_assume((sec_r001343_1_2 >= 0) && (sec_r001343_1_2 <= 255));
  __CPROVER_assume((sec_r001343_2_1 >= 0) && (sec_r001343_2_1 <= 255));
  __CPROVER_assume((sec_r001343_2_2 >= 0) && (sec_r001343_2_2 <= 255));
  __CPROVER_assume((sec_r001343_3_1 >= 0) && (sec_r001343_3_1 <= 255));
  __CPROVER_assume((sec_r001343_3_2 >= 0) && (sec_r001343_3_2 <= 255));
  __CPROVER_assume((sec_r001343_4_1 >= 0) && (sec_r001343_4_1 <= 255));
  __CPROVER_assume((sec_r001343_4_2 >= 0) && (sec_r001343_4_2 <= 255));
  __CPROVER_assume((sec_r001343_5_1 >= 0) && (sec_r001343_5_1 <= 255));
  __CPROVER_assume((sec_r001343_5_2 >= 0) && (sec_r001343_5_2 <= 255));
  __CPROVER_assume((sec_r001343_6_1 >= 0) && (sec_r001343_6_1 <= 255));
  __CPROVER_assume((sec_r001343_6_2 >= 0) && (sec_r001343_6_2 <= 255));
  __CPROVER_assume((sec_r001343_7_1 >= 0) && (sec_r001343_7_1 <= 255));
  __CPROVER_assume((sec_r001343_7_2 >= 0) && (sec_r001343_7_2 <= 255));
  __CPROVER_assume((sec_r001343_8_1 >= 0) && (sec_r001343_8_1 <= 255));
  __CPROVER_assume((sec_r001343_8_2 >= 0) && (sec_r001343_8_2 <= 255));
  __CPROVER_assume((sec_r001343_9_1 >= 0) && (sec_r001343_9_1 <= 255));
  __CPROVER_assume((sec_r001343_9_2 >= 0) && (sec_r001343_9_2 <= 255));
  __CPROVER_assume((sec_r001343_10_1 >= 0) && (sec_r001343_10_1 <= 255));
  __CPROVER_assume((sec_r001343_10_2 >= 0) && (sec_r001343_10_2 <= 255));
  __CPROVER_assume((sec_r001343_11_1 >= 0) && (sec_r001343_11_1 <= 255));
  __CPROVER_assume((sec_r001343_11_2 >= 0) && (sec_r001343_11_2 <= 255));
  __CPROVER_assume((sec_r001343_12_1 >= 0) && (sec_r001343_12_1 <= 255));
  __CPROVER_assume((sec_r001343_12_2 >= 0) && (sec_r001343_12_2 <= 255));
  __CPROVER_assume((sec_r001343_13_1 >= 0) && (sec_r001343_13_1 <= 255));
  __CPROVER_assume((sec_r001343_13_2 >= 0) && (sec_r001343_13_2 <= 255));
  __CPROVER_assume((sec_r001343_14_1 >= 0) && (sec_r001343_14_1 <= 255));
  __CPROVER_assume((sec_r001343_14_2 >= 0) && (sec_r001343_14_2 <= 255));
  __CPROVER_assume((sec_r001343_15_1 >= 0) && (sec_r001343_15_1 <= 255));
  __CPROVER_assume((sec_r001343_15_2 >= 0) && (sec_r001343_15_2 <= 255));
  __CPROVER_assume((sec_r001343_16_1 >= 0) && (sec_r001343_16_1 <= 255));
  __CPROVER_assume((sec_r001343_16_2 >= 0) && (sec_r001343_16_2 <= 255));
  __CPROVER_assume((sec_r001343_17_1 >= 0) && (sec_r001343_17_1 <= 255));
  __CPROVER_assume((sec_r001343_17_2 >= 0) && (sec_r001343_17_2 <= 255));
  __CPROVER_assume((sec_r001343_18_1 >= 0) && (sec_r001343_18_1 <= 255));
  __CPROVER_assume((sec_r001343_18_2 >= 0) && (sec_r001343_18_2 <= 255));
  __CPROVER_assume((sec_r001343_19_1 >= 0) && (sec_r001343_19_1 <= 255));
  __CPROVER_assume((sec_r001343_19_2 >= 0) && (sec_r001343_19_2 <= 255));
  __CPROVER_assume((sec_r001343_20_1 >= 0) && (sec_r001343_20_1 <= 255));
  __CPROVER_assume((sec_r001343_20_2 >= 0) && (sec_r001343_20_2 <= 255));
  __CPROVER_assume((sec_r001343_21_1 >= 0) && (sec_r001343_21_1 <= 255));
  __CPROVER_assume((sec_r001343_21_2 >= 0) && (sec_r001343_21_2 <= 255));
  __CPROVER_assume((sec_r001343_22_1 >= 0) && (sec_r001343_22_1 <= 255));
  __CPROVER_assume((sec_r001343_22_2 >= 0) && (sec_r001343_22_2 <= 255));
  struct DeviceConfig_R001343_4313_0 st_var_0_1 = {0};
  struct DeviceConfig_R001343_4313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001343_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001343_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001343_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001343_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001343_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001343_0_2 + 7) & 15;
  struct Vector3D_R001343_4313_1 st_var_1_1 = {0};
  struct Vector3D_R001343_4313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001343_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001343_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001343_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001343_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001343_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001343_0_2 + 9) & 15;
  struct SensorNode_R001343_4313_2 st_var_2_1 = {0};
  struct SensorNode_R001343_4313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001343_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001343_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001343_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001343_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001343_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001343_0_2 + 11) & 15;
  union ColorPixel_R001343_4313_0 u_var_1;
  union ColorPixel_R001343_4313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001343_4313_0(sec_r001343_0_1, sec_r001343_1_1, pub_r001343_2_1);
  int helper_flow_0_2 = fn_R001343_4313_0(sec_r001343_0_2, sec_r001343_1_2, pub_r001343_2_2);
  fn_R001343_4313_0_2(sec_r001343_0_1, sec_r001343_1_1, pub_r001343_2_1, sec_r001343_0_2, sec_r001343_1_2, pub_r001343_2_2);
  int helper_flow_1_1 = fn_R001343_4313_1(sec_r001343_1_1, pub_r001343_2_1, pub_r001343_3_1);
  int helper_flow_1_2 = fn_R001343_4313_1(sec_r001343_1_2, pub_r001343_2_2, pub_r001343_3_2);
  fn_R001343_4313_1_2(sec_r001343_1_1, pub_r001343_2_1, pub_r001343_3_1, sec_r001343_1_2, pub_r001343_2_2, pub_r001343_3_2);
  int helper_flow_2_1 = fn_R001343_4313_2(sec_r001343_2_1, sec_r001343_3_1, pub_r001343_4_1, pub_r001343_5_1, pub_r001343_6_1);
  int helper_flow_2_2 = fn_R001343_4313_2(sec_r001343_2_2, sec_r001343_3_2, pub_r001343_4_2, pub_r001343_5_2, pub_r001343_6_2);
  fn_R001343_4313_2_2(sec_r001343_2_1, sec_r001343_3_1, pub_r001343_4_1, pub_r001343_5_1, pub_r001343_6_1, sec_r001343_2_2, sec_r001343_3_2, pub_r001343_4_2, pub_r001343_5_2, pub_r001343_6_2);
  int helper_flow_3_1 = fn_R001343_4313_3(sec_r001343_3_1, pub_r001343_4_1, pub_r001343_5_1, pub_r001343_6_1, pub_r001343_7_1);
  int helper_flow_3_2 = fn_R001343_4313_3(sec_r001343_3_2, pub_r001343_4_2, pub_r001343_5_2, pub_r001343_6_2, pub_r001343_7_2);
  fn_R001343_4313_3_2(sec_r001343_3_1, pub_r001343_4_1, pub_r001343_5_1, pub_r001343_6_1, pub_r001343_7_1, sec_r001343_3_2, pub_r001343_4_2, pub_r001343_5_2, pub_r001343_6_2, pub_r001343_7_2);
  int helper_flow_4_1 = fn_R001343_4313_4(sec_r001343_4_1, pub_r001343_5_1);
  int helper_flow_4_2 = fn_R001343_4313_4(sec_r001343_4_2, pub_r001343_5_2);
  fn_R001343_4313_4_2(sec_r001343_4_1, pub_r001343_5_1, sec_r001343_4_2, pub_r001343_5_2);
  int helper_flow_5_1 = fn_R001343_4313_5(sec_r001343_5_1, pub_r001343_6_1, pub_r001343_7_1);
  int helper_flow_5_2 = fn_R001343_4313_5(sec_r001343_5_2, pub_r001343_6_2, pub_r001343_7_2);
  fn_R001343_4313_5_2(sec_r001343_5_1, pub_r001343_6_1, pub_r001343_7_1, sec_r001343_5_2, pub_r001343_6_2, pub_r001343_7_2);
  int helper_flow_6_1 = fn_R001343_4313_6(sec_r001343_6_1, sec_r001343_7_1, pub_r001343_8_1);
  int helper_flow_6_2 = fn_R001343_4313_6(sec_r001343_6_2, sec_r001343_7_2, pub_r001343_8_2);
  fn_R001343_4313_6_2(sec_r001343_6_1, sec_r001343_7_1, pub_r001343_8_1, sec_r001343_6_2, sec_r001343_7_2, pub_r001343_8_2);
  int helper_flow_7_1 = fn_R001343_4313_7(sec_r001343_7_1, pub_r001343_8_1, pub_r001343_9_1);
  int helper_flow_7_2 = fn_R001343_4313_7(sec_r001343_7_2, pub_r001343_8_2, pub_r001343_9_2);
  fn_R001343_4313_7_2(sec_r001343_7_1, pub_r001343_8_1, pub_r001343_9_1, sec_r001343_7_2, pub_r001343_8_2, pub_r001343_9_2);
  int stage_v_0_1 = ((pub_r001343_9_1 * 2) + 25) & 63;
  int stage_v_0_2 = ((pub_r001343_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001343_19_1 * 2) + 32) & 63;
  int stage_v_1_2 = ((pub_r001343_19_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001343_19_1 * 2) + 22) & 63;
  int stage_v_2_2 = ((pub_r001343_19_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001343_8_1 * 2) + 25) & 63;
  int stage_v_3_2 = ((pub_r001343_8_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((sec_r001343_7_1 * 3) + pub_r001343_16_1) + 14) & 127;
  int stage_v_4_2 = (((sec_r001343_7_2 * 3) + pub_r001343_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = (((sec_r001343_22_1 * 3) + pub_r001343_7_1) + 15) & 127;
  int stage_v_5_2 = (((sec_r001343_22_2 * 3) + pub_r001343_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = ((pub_r001343_4_1 * 2) + 30) & 63;
  int stage_v_6_2 = ((pub_r001343_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001343_21_1 * 2) + 30) & 63;
  int stage_v_7_2 = ((pub_r001343_21_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((helper_flow_5_1 * 3) + pub_r001343_18_1) + 21) & 127;
  int stage_v_8_2 = (((helper_flow_5_2 * 3) + pub_r001343_18_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = (((helper_flow_1_1 * 3) + pub_r001343_14_1) + 34) & 127;
  int stage_v_9_2 = (((helper_flow_1_2 * 3) + pub_r001343_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = (((sec_r001343_10_1 * 3) + pub_r001343_21_1) + 31) & 127;
  int stage_v_10_2 = (((sec_r001343_10_2 * 3) + pub_r001343_21_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001343_19_1 * 2) + 26) & 63;
  int stage_v_11_2 = ((pub_r001343_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((helper_flow_6_1 * 3) + pub_r001343_6_1) + 45) & 127;
  int stage_v_12_2 = (((helper_flow_6_2 * 3) + pub_r001343_6_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = ((pub_r001343_4_1 * 2) + 37) & 63;
  int stage_v_13_2 = ((pub_r001343_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((helper_flow_2_1 * 3) + pub_r001343_13_1) + 10) & 127;
  int stage_v_14_2 = (((helper_flow_2_2 * 3) + pub_r001343_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = ((pub_r001343_2_1 * 2) + 44) & 63;
  int stage_v_15_2 = ((pub_r001343_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001343_9_1 * 2) + 7) & 63;
  int stage_v_16_2 = ((pub_r001343_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((sec_r001343_3_1 * 3) + pub_r001343_14_1) + 38) & 127;
  int stage_v_17_2 = (((sec_r001343_3_2 * 3) + pub_r001343_14_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = ((pub_r001343_19_1 * 2) + 10) & 63;
  int stage_v_18_2 = ((pub_r001343_19_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001343_6_1 * 2) + 49) & 63;
  int stage_v_19_2 = ((pub_r001343_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (((helper_flow_1_1 * 3) + pub_r001343_5_1) + 35) & 127;
  int stage_v_20_2 = (((helper_flow_1_2 * 3) + pub_r001343_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = (((sec_r001343_8_1 * 3) + pub_r001343_5_1) + 18) & 127;
  int stage_v_21_2 = (((sec_r001343_8_2 * 3) + pub_r001343_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = ((pub_r001343_20_1 * 2) + 15) & 63;
  int stage_v_22_2 = ((pub_r001343_20_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001343_0_1 * 2) + 41) & 63;
  int stage_v_23_2 = ((pub_r001343_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (((stage_v_20_1 * 3) + pub_r001343_12_1) + 24) & 127;
  int stage_v_24_2 = (((stage_v_20_2 * 3) + pub_r001343_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = ((pub_r001343_8_1 * 2) + 17) & 63;
  int stage_v_25_2 = ((pub_r001343_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001343_12_1 * 2) + 10) & 63;
  int stage_v_26_2 = ((pub_r001343_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001343_3_1 * 2) + 40) & 63;
  int stage_v_27_2 = ((pub_r001343_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001343_8_1 * 2) + 23) & 63;
  int stage_v_28_2 = ((pub_r001343_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (((sec_r001343_1_1 * 3) + pub_r001343_13_1) + 43) & 127;
  int stage_v_29_2 = (((sec_r001343_1_2 * 3) + pub_r001343_13_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = ((pub_r001343_21_1 * 2) + 26) & 63;
  int stage_v_30_2 = ((pub_r001343_21_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (((sec_r001343_16_1 * 3) + pub_r001343_7_1) + 16) & 127;
  int stage_v_31_2 = (((sec_r001343_16_2 * 3) + pub_r001343_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = (((sec_r001343_11_1 * 3) + pub_r001343_14_1) + 24) & 127;
  int stage_v_32_2 = (((sec_r001343_11_2 * 3) + pub_r001343_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = (((sec_r001343_2_1 * 3) + pub_r001343_1_1) + 6) & 127;
  int stage_v_33_2 = (((sec_r001343_2_2 * 3) + pub_r001343_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = ((pub_r001343_2_1 * 2) + 37) & 63;
  int stage_v_34_2 = ((pub_r001343_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (((sec_r001343_18_1 * 3) + pub_r001343_18_1) + 5) & 127;
  int stage_v_35_2 = (((sec_r001343_18_2 * 3) + pub_r001343_18_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = ((pub_r001343_20_1 * 2) + 49) & 63;
  int stage_v_36_2 = ((pub_r001343_20_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((stage_v_10_1 * 3) + pub_r001343_11_1) + 38) & 127;
  int stage_v_37_2 = (((stage_v_10_2 * 3) + pub_r001343_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = (((sec_r001343_1_1 * 3) + pub_r001343_3_1) + 14) & 127;
  int stage_v_38_2 = (((sec_r001343_1_2 * 3) + pub_r001343_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = (((helper_flow_0_1 * 3) + pub_r001343_21_1) + 44) & 127;
  int stage_v_39_2 = (((helper_flow_0_2 * 3) + pub_r001343_21_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = ((pub_r001343_16_1 * 2) + 42) & 63;
  int stage_v_40_2 = ((pub_r001343_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((sec_r001343_9_1 * 3) + pub_r001343_3_1) + 20) & 127;
  int stage_v_41_2 = (((sec_r001343_9_2 * 3) + pub_r001343_3_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = ((pub_r001343_7_1 * 2) + 22) & 63;
  int stage_v_42_2 = ((pub_r001343_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((stage_v_14_1 * 3) + pub_r001343_20_1) + 11) & 127;
  int stage_v_43_2 = (((stage_v_14_2 * 3) + pub_r001343_20_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = (((sec_r001343_0_1 * 3) + pub_r001343_20_1) + 38) & 127;
  int stage_v_44_2 = (((sec_r001343_0_2 * 3) + pub_r001343_20_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = ((pub_r001343_13_1 * 2) + 42) & 63;
  int stage_v_45_2 = ((pub_r001343_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001343_13_1 * 2) + 45) & 63;
  int stage_v_46_2 = ((pub_r001343_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001343_18_1 * 2) + 42) & 63;
  int stage_v_47_2 = ((pub_r001343_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001343_7_1 * 2) + 38) & 63;
  int stage_v_48_2 = ((pub_r001343_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((sec_r001343_13_1 * 3) + pub_r001343_13_1) + 29) & 127;
  int stage_v_49_2 = (((sec_r001343_13_2 * 3) + pub_r001343_13_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = (((stage_v_41_1 * 3) + pub_r001343_10_1) + 14) & 127;
  int stage_v_50_2 = (((stage_v_41_2 * 3) + pub_r001343_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = ((pub_r001343_1_1 * 2) + 7) & 63;
  int stage_v_51_2 = ((pub_r001343_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001343_9_1 * 2) + 24) & 63;
  int stage_v_52_2 = ((pub_r001343_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((sec_r001343_9_1 * 3) + pub_r001343_7_1) + 21) & 127;
  int stage_v_53_2 = (((sec_r001343_9_2 * 3) + pub_r001343_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = ((pub_r001343_14_1 * 2) + 15) & 63;
  int stage_v_54_2 = ((pub_r001343_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001343_13_1 * 2) + 26) & 63;
  int stage_v_55_2 = ((pub_r001343_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (((stage_v_4_1 * 3) + pub_r001343_1_1) + 35) & 127;
  int stage_v_56_2 = (((stage_v_4_2 * 3) + pub_r001343_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = ((pub_r001343_17_1 * 2) + 37) & 63;
  int stage_v_57_2 = ((pub_r001343_17_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001343_22_1 * 2) + 17) & 63;
  int stage_v_58_2 = ((pub_r001343_22_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001343_17_1 * 2) + 23) & 63;
  int stage_v_59_2 = ((pub_r001343_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((sec_r001343_15_1 * 3) + pub_r001343_21_1) + 39) & 127;
  int stage_v_60_2 = (((sec_r001343_15_2 * 3) + pub_r001343_21_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((helper_flow_1_1 * 3) + pub_r001343_12_1) + 11) & 127;
  int stage_v_61_2 = (((helper_flow_1_2 * 3) + pub_r001343_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001343_15_1 * 2) + 40) & 63;
  int stage_v_62_2 = ((pub_r001343_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001343_1_1 * 2) + 20) & 63;
  int stage_v_63_2 = ((pub_r001343_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001343_17_1 * 2) + 42) & 63;
  int stage_v_64_2 = ((pub_r001343_17_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = (((stage_v_38_1 * 3) + pub_r001343_12_1) + 26) & 127;
  int stage_v_65_2 = (((stage_v_38_2 * 3) + pub_r001343_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = (((stage_v_4_1 * 3) + pub_r001343_9_1) + 13) & 127;
  int stage_v_66_2 = (((stage_v_4_2 * 3) + pub_r001343_9_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = (((sec_r001343_0_1 * 3) + pub_r001343_2_1) + 27) & 127;
  int stage_v_67_2 = (((sec_r001343_0_2 * 3) + pub_r001343_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = (((sec_r001343_7_1 * 3) + pub_r001343_0_1) + 19) & 127;
  int stage_v_68_2 = (((sec_r001343_7_2 * 3) + pub_r001343_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = ((pub_r001343_6_1 * 2) + 7) & 63;
  int stage_v_69_2 = ((pub_r001343_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001343_21_1 * 2) + 44) & 63;
  int stage_v_70_2 = ((pub_r001343_21_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001343_4_1 * 2) + 29) & 63;
  int stage_v_71_2 = ((pub_r001343_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((stage_v_12_1 * 3) + pub_r001343_11_1) + 11) & 127;
  int stage_v_72_2 = (((stage_v_12_2 * 3) + pub_r001343_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = ((pub_r001343_2_1 * 2) + 26) & 63;
  int stage_v_73_2 = ((pub_r001343_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = (((sec_r001343_4_1 * 3) + pub_r001343_3_1) + 30) & 127;
  int stage_v_74_2 = (((sec_r001343_4_2 * 3) + pub_r001343_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = (((stage_v_66_1 * 3) + pub_r001343_2_1) + 24) & 127;
  int stage_v_75_2 = (((stage_v_66_2 * 3) + pub_r001343_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = ((pub_r001343_4_1 * 2) + 7) & 63;
  int stage_v_76_2 = ((pub_r001343_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((stage_v_72_1 * 3) + pub_r001343_13_1) + 37) & 127;
  int stage_v_77_2 = (((stage_v_72_2 * 3) + pub_r001343_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = (((stage_v_61_1 * 3) + pub_r001343_17_1) + 18) & 127;
  int stage_v_78_2 = (((stage_v_61_2 * 3) + pub_r001343_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = ((pub_r001343_9_1 * 2) + 12) & 63;
  int stage_v_79_2 = ((pub_r001343_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001343_2_1 * 2) + 45) & 63;
  int stage_v_80_2 = ((pub_r001343_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((sec_r001343_11_1 * 3) + pub_r001343_14_1) + 9) & 127;
  int stage_v_81_2 = (((sec_r001343_11_2 * 3) + pub_r001343_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = (((stage_v_32_1 * 3) + pub_r001343_22_1) + 44) & 127;
  int stage_v_82_2 = (((stage_v_32_2 * 3) + pub_r001343_22_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = ((pub_r001343_4_1 * 2) + 16) & 63;
  int stage_v_83_2 = ((pub_r001343_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((sec_r001343_4_1 * 3) + pub_r001343_1_1) + 4) & 127;
  int stage_v_84_2 = (((sec_r001343_4_2 * 3) + pub_r001343_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = ((pub_r001343_16_1 * 2) + 8) & 63;
  int stage_v_85_2 = ((pub_r001343_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((sec_r001343_13_1 * 3) + pub_r001343_15_1) + 12) & 127;
  int stage_v_86_2 = (((sec_r001343_13_2 * 3) + pub_r001343_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = ((pub_r001343_7_1 * 2) + 31) & 63;
  int stage_v_87_2 = ((pub_r001343_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001343_9_1 * 2) + 22) & 63;
  int stage_v_88_2 = ((pub_r001343_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001343_8_1 * 2) + 41) & 63;
  int stage_v_89_2 = ((pub_r001343_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((sec_r001343_2_1 * 3) + pub_r001343_2_1) + 24) & 127;
  int stage_v_90_2 = (((sec_r001343_2_2 * 3) + pub_r001343_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = (((sec_r001343_8_1 * 3) + pub_r001343_17_1) + 42) & 127;
  int stage_v_91_2 = (((sec_r001343_8_2 * 3) + pub_r001343_17_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = (((helper_flow_2_1 * 3) + pub_r001343_10_1) + 34) & 127;
  int stage_v_92_2 = (((helper_flow_2_2 * 3) + pub_r001343_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = ((pub_r001343_14_1 * 2) + 5) & 63;
  int stage_v_93_2 = ((pub_r001343_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((helper_flow_3_1 * 3) + pub_r001343_17_1) + 17) & 127;
  int stage_v_94_2 = (((helper_flow_3_2 * 3) + pub_r001343_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = ((pub_r001343_22_1 * 2) + 40) & 63;
  int stage_v_95_2 = ((pub_r001343_22_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001343_2_1 * 2) + 10) & 63;
  int stage_v_96_2 = ((pub_r001343_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001343_1_1 * 2) + 44) & 63;
  int stage_v_97_2 = ((pub_r001343_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001343_0_1 * 2) + 44) & 63;
  int stage_v_98_2 = ((pub_r001343_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001343_15_1 * 2) + 16) & 63;
  int stage_v_99_2 = ((pub_r001343_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001343_10_1 * 2) + 22) & 63;
  int stage_v_100_2 = ((pub_r001343_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001343_4_1 * 2) + 49) & 63;
  int stage_v_101_2 = ((pub_r001343_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((stage_v_39_1 * 3) + pub_r001343_8_1) + 11) & 127;
  int stage_v_102_2 = (((stage_v_39_2 * 3) + pub_r001343_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = (((stage_v_77_1 * 3) + pub_r001343_1_1) + 39) & 127;
  int stage_v_103_2 = (((stage_v_77_2 * 3) + pub_r001343_1_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = ((pub_r001343_12_1 * 2) + 46) & 63;
  int stage_v_104_2 = ((pub_r001343_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_81_1 * 3) + pub_r001343_15_1) + 3) & 127;
  int stage_v_105_2 = (((stage_v_81_2 * 3) + pub_r001343_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = ((pub_r001343_15_1 * 2) + 9) & 63;
  int stage_v_106_2 = ((pub_r001343_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((stage_v_14_1 * 3) + pub_r001343_21_1) + 24) & 127;
  int stage_v_107_2 = (((stage_v_14_2 * 3) + pub_r001343_21_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = (((stage_v_8_1 * 3) + pub_r001343_3_1) + 11) & 127;
  int stage_v_108_2 = (((stage_v_8_2 * 3) + pub_r001343_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = (((helper_flow_5_1 * 3) + pub_r001343_19_1) + 38) & 127;
  int stage_v_109_2 = (((helper_flow_5_2 * 3) + pub_r001343_19_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = ((pub_r001343_21_1 * 2) + 14) & 63;
  int stage_v_110_2 = ((pub_r001343_21_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001343_3_1 * 2) + 11) & 63;
  int stage_v_111_2 = ((pub_r001343_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001343_14_1 * 2) + 31) & 63;
  int stage_v_112_2 = ((pub_r001343_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((stage_v_17_1 * 3) + pub_r001343_7_1) + 15) & 127;
  int stage_v_113_2 = (((stage_v_17_2 * 3) + pub_r001343_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = (((sec_r001343_4_1 * 3) + pub_r001343_18_1) + 26) & 127;
  int stage_v_114_2 = (((sec_r001343_4_2 * 3) + pub_r001343_18_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = (((stage_v_9_1 * 3) + pub_r001343_22_1) + 40) & 127;
  int stage_v_115_2 = (((stage_v_9_2 * 3) + pub_r001343_22_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = ((pub_r001343_18_1 * 2) + 7) & 63;
  int stage_v_116_2 = ((pub_r001343_18_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((stage_v_14_1 * 3) + pub_r001343_6_1) + 7) & 127;
  int stage_v_117_2 = (((stage_v_14_2 * 3) + pub_r001343_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = ((pub_r001343_21_1 * 2) + 6) & 63;
  int stage_v_118_2 = ((pub_r001343_21_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((stage_v_105_1 * 3) + pub_r001343_3_1) + 26) & 127;
  int stage_v_119_2 = (((stage_v_105_2 * 3) + pub_r001343_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = ((pub_r001343_11_1 * 2) + 22) & 63;
  int stage_v_120_2 = ((pub_r001343_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001343_6_1 * 2) + 13) & 63;
  int stage_v_121_2 = ((pub_r001343_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001343_17_1 * 2) + 27) & 63;
  int stage_v_122_2 = ((pub_r001343_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((sec_r001343_5_1 * 3) + pub_r001343_13_1) + 7) & 127;
  int stage_v_123_2 = (((sec_r001343_5_2 * 3) + pub_r001343_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((sec_r001343_7_1 * 3) + pub_r001343_12_1) + 42) & 127;
  int stage_v_124_2 = (((sec_r001343_7_2 * 3) + pub_r001343_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = (((stage_v_82_1 * 3) + pub_r001343_15_1) + 43) & 127;
  int stage_v_125_2 = (((stage_v_82_2 * 3) + pub_r001343_15_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = (((helper_flow_3_1 * 3) + pub_r001343_13_1) + 27) & 127;
  int stage_v_126_2 = (((helper_flow_3_2 * 3) + pub_r001343_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = (((stage_v_14_1 * 3) + pub_r001343_11_1) + 38) & 127;
  int stage_v_127_2 = (((stage_v_14_2 * 3) + pub_r001343_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = (((stage_v_9_1 * 3) + pub_r001343_19_1) + 34) & 127;
  int stage_v_128_2 = (((stage_v_9_2 * 3) + pub_r001343_19_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = ((pub_r001343_16_1 * 2) + 50) & 63;
  int stage_v_129_2 = ((pub_r001343_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (((stage_v_94_1 * 3) + pub_r001343_15_1) + 40) & 127;
  int stage_v_130_2 = (((stage_v_94_2 * 3) + pub_r001343_15_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = ((pub_r001343_17_1 * 2) + 22) & 63;
  int stage_v_131_2 = ((pub_r001343_17_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001343_13_1 * 2) + 15) & 63;
  int stage_v_132_2 = ((pub_r001343_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((sec_r001343_0_1 * 3) + pub_r001343_3_1) + 42) & 127;
  int stage_v_133_2 = (((sec_r001343_0_2 * 3) + pub_r001343_3_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001343_22_1 * 2) + 28) & 63;
  int stage_v_134_2 = ((pub_r001343_22_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((stage_v_39_1 * 3) + pub_r001343_9_1) + 44) & 127;
  int stage_v_135_2 = (((stage_v_39_2 * 3) + pub_r001343_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = ((pub_r001343_20_1 * 2) + 5) & 63;
  int stage_v_136_2 = ((pub_r001343_20_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (((stage_v_21_1 * 3) + pub_r001343_19_1) + 37) & 127;
  int stage_v_137_2 = (((stage_v_21_2 * 3) + pub_r001343_19_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = ((pub_r001343_2_1 * 2) + 44) & 63;
  int stage_v_138_2 = ((pub_r001343_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001343_9_1 * 2) + 49) & 63;
  int stage_v_139_2 = ((pub_r001343_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001343_0_1 * 2) + 37) & 63;
  int stage_v_140_2 = ((pub_r001343_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001343_3_1 * 2) + 37) & 63;
  int stage_v_141_2 = ((pub_r001343_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((stage_v_66_1 * 3) + pub_r001343_19_1) + 42) & 127;
  int stage_v_142_2 = (((stage_v_66_2 * 3) + pub_r001343_19_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = (((sec_r001343_12_1 * 3) + pub_r001343_14_1) + 17) & 127;
  int stage_v_143_2 = (((sec_r001343_12_2 * 3) + pub_r001343_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = (((stage_v_135_1 * 3) + pub_r001343_18_1) + 15) & 127;
  int stage_v_144_2 = (((stage_v_135_2 * 3) + pub_r001343_18_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = ((pub_r001343_1_1 * 2) + 39) & 63;
  int stage_v_145_2 = ((pub_r001343_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001343_15_1 * 2) + 9) & 63;
  int stage_v_146_2 = ((pub_r001343_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001343_1_1 * 2) + 16) & 63;
  int stage_v_147_2 = ((pub_r001343_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_75_1 * 3) + pub_r001343_14_1) + 11) & 127;
  int stage_v_148_2 = (((stage_v_75_2 * 3) + pub_r001343_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((sec_r001343_7_1 * 3) + pub_r001343_18_1) + 4) & 127;
  int stage_v_149_2 = (((sec_r001343_7_2 * 3) + pub_r001343_18_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((sec_r001343_19_1 * 3) + pub_r001343_7_1) + 18) & 127;
  int stage_v_150_2 = (((sec_r001343_19_2 * 3) + pub_r001343_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((stage_v_144_1 * 3) + pub_r001343_22_1) + 45) & 127;
  int stage_v_151_2 = (((stage_v_144_2 * 3) + pub_r001343_22_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = ((pub_r001343_8_1 * 2) + 36) & 63;
  int stage_v_152_2 = ((pub_r001343_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((stage_v_91_1 * 3) + pub_r001343_18_1) + 19) & 127;
  int stage_v_153_2 = (((stage_v_91_2 * 3) + pub_r001343_18_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = ((pub_r001343_17_1 * 2) + 16) & 63;
  int stage_v_154_2 = ((pub_r001343_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((sec_r001343_8_1 * 3) + pub_r001343_17_1) + 38) & 127;
  int stage_v_155_2 = (((sec_r001343_8_2 * 3) + pub_r001343_17_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((stage_v_107_1 * 3) + pub_r001343_16_1) + 35) & 127;
  int stage_v_156_2 = (((stage_v_107_2 * 3) + pub_r001343_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((stage_v_109_1 * 3) + pub_r001343_12_1) + 11) & 127;
  int stage_v_157_2 = (((stage_v_109_2 * 3) + pub_r001343_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = ((pub_r001343_17_1 * 2) + 30) & 63;
  int stage_v_158_2 = ((pub_r001343_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((helper_flow_4_1 * 3) + pub_r001343_8_1) + 15) & 127;
  int stage_v_159_2 = (((helper_flow_4_2 * 3) + pub_r001343_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = (((stage_v_72_1 * 3) + pub_r001343_20_1) + 43) & 127;
  int stage_v_160_2 = (((stage_v_72_2 * 3) + pub_r001343_20_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = ((pub_r001343_5_1 * 2) + 31) & 63;
  int stage_v_161_2 = ((pub_r001343_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001343_22_1 * 2) + 25) & 63;
  int stage_v_162_2 = ((pub_r001343_22_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((sec_r001343_18_1 * 3) + pub_r001343_2_1) + 11) & 127;
  int stage_v_163_2 = (((sec_r001343_18_2 * 3) + pub_r001343_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = (((stage_v_163_1 * 3) + pub_r001343_21_1) + 31) & 127;
  int stage_v_164_2 = (((stage_v_163_2 * 3) + pub_r001343_21_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = (((sec_r001343_9_1 * 3) + pub_r001343_19_1) + 36) & 127;
  int stage_v_165_2 = (((sec_r001343_9_2 * 3) + pub_r001343_19_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = (((stage_v_156_1 * 3) + pub_r001343_20_1) + 12) & 127;
  int stage_v_166_2 = (((stage_v_156_2 * 3) + pub_r001343_20_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = (((stage_v_29_1 * 3) + pub_r001343_12_1) + 18) & 127;
  int stage_v_167_2 = (((stage_v_29_2 * 3) + pub_r001343_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = ((pub_r001343_5_1 * 2) + 30) & 63;
  int stage_v_168_2 = ((pub_r001343_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001343_10_1 * 2) + 37) & 63;
  int stage_v_169_2 = ((pub_r001343_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001343_8_1 * 2) + 47) & 63;
  int stage_v_170_2 = ((pub_r001343_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (((stage_v_142_1 * 3) + pub_r001343_7_1) + 22) & 127;
  int stage_v_171_2 = (((stage_v_142_2 * 3) + pub_r001343_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = (((sec_r001343_21_1 * 3) + pub_r001343_5_1) + 42) & 127;
  int stage_v_172_2 = (((sec_r001343_21_2 * 3) + pub_r001343_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = ((pub_r001343_4_1 * 2) + 26) & 63;
  int stage_v_173_2 = ((pub_r001343_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (((sec_r001343_16_1 * 3) + pub_r001343_12_1) + 8) & 127;
  int stage_v_174_2 = (((sec_r001343_16_2 * 3) + pub_r001343_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = (((stage_v_113_1 * 3) + pub_r001343_12_1) + 43) & 127;
  int stage_v_175_2 = (((stage_v_113_2 * 3) + pub_r001343_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = (((stage_v_53_1 * 3) + pub_r001343_19_1) + 20) & 127;
  int stage_v_176_2 = (((stage_v_53_2 * 3) + pub_r001343_19_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = (((stage_v_84_1 * 3) + pub_r001343_13_1) + 10) & 127;
  int stage_v_177_2 = (((stage_v_84_2 * 3) + pub_r001343_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = ((pub_r001343_8_1 * 2) + 8) & 63;
  int stage_v_178_2 = ((pub_r001343_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001343_11_1 * 2) + 36) & 63;
  int stage_v_179_2 = ((pub_r001343_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001343_1_1 * 2) + 34) & 63;
  int stage_v_180_2 = ((pub_r001343_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001343_6_1 * 2) + 7) & 63;
  int stage_v_181_2 = ((pub_r001343_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001343_11_1 * 2) + 44) & 63;
  int stage_v_182_2 = ((pub_r001343_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_174_1 * 3) + pub_r001343_16_1) + 36) & 127;
  int stage_v_183_2 = (((stage_v_174_2 * 3) + pub_r001343_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((stage_v_82_1 * 3) + pub_r001343_1_1) + 39) & 127;
  int stage_v_184_2 = (((stage_v_82_2 * 3) + pub_r001343_1_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = ((pub_r001343_3_1 * 2) + 44) & 63;
  int stage_v_185_2 = ((pub_r001343_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_78_1 * 3) + pub_r001343_1_1) + 21) & 127;
  int stage_v_186_2 = (((stage_v_78_2 * 3) + pub_r001343_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = ((pub_r001343_21_1 * 2) + 30) & 63;
  int stage_v_187_2 = ((pub_r001343_21_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001343_4_1 * 2) + 9) & 63;
  int stage_v_188_2 = ((pub_r001343_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001343_11_1 * 2) + 50) & 63;
  int stage_v_189_2 = ((pub_r001343_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((stage_v_113_1 * 3) + pub_r001343_6_1) + 43) & 127;
  int stage_v_190_2 = (((stage_v_113_2 * 3) + pub_r001343_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = ((pub_r001343_0_1 * 2) + 10) & 63;
  int stage_v_191_2 = ((pub_r001343_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = (((helper_flow_1_1 * 3) + pub_r001343_1_1) + 38) & 127;
  int stage_v_192_2 = (((helper_flow_1_2 * 3) + pub_r001343_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = (((stage_v_153_1 * 3) + pub_r001343_8_1) + 5) & 127;
  int stage_v_193_2 = (((stage_v_153_2 * 3) + pub_r001343_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001343_3_1 * 2) + 43) & 63;
  int stage_v_194_2 = ((pub_r001343_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001343_12_1 * 2) + 20) & 63;
  int stage_v_195_2 = ((pub_r001343_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001343_5_1 * 2) + 50) & 63;
  int stage_v_196_2 = ((pub_r001343_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((sec_r001343_15_1 * 3) + pub_r001343_11_1) + 31) & 127;
  int stage_v_197_2 = (((sec_r001343_15_2 * 3) + pub_r001343_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = (((stage_v_167_1 * 3) + pub_r001343_22_1) + 29) & 127;
  int stage_v_198_2 = (((stage_v_167_2 * 3) + pub_r001343_22_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = (((stage_v_44_1 * 3) + pub_r001343_16_1) + 39) & 127;
  int stage_v_199_2 = (((stage_v_44_2 * 3) + pub_r001343_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = (((stage_v_148_1 * 3) + pub_r001343_4_1) + 39) & 127;
  int stage_v_200_2 = (((stage_v_148_2 * 3) + pub_r001343_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = (((stage_v_114_1 * 3) + pub_r001343_20_1) + 25) & 127;
  int stage_v_201_2 = (((stage_v_114_2 * 3) + pub_r001343_20_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = (((stage_v_184_1 * 3) + pub_r001343_20_1) + 23) & 127;
  int stage_v_202_2 = (((stage_v_184_2 * 3) + pub_r001343_20_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = ((pub_r001343_2_1 * 2) + 50) & 63;
  int stage_v_203_2 = ((pub_r001343_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((stage_v_148_1 * 3) + pub_r001343_22_1) + 40) & 127;
  int stage_v_204_2 = (((stage_v_148_2 * 3) + pub_r001343_22_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((stage_v_17_1 * 3) + pub_r001343_15_1) + 21) & 127;
  int stage_v_205_2 = (((stage_v_17_2 * 3) + pub_r001343_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = ((pub_r001343_3_1 * 2) + 35) & 63;
  int stage_v_206_2 = ((pub_r001343_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001343_2_1 * 2) + 21) & 63;
  int stage_v_207_2 = ((pub_r001343_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = (((stage_v_68_1 * 3) + pub_r001343_1_1) + 10) & 127;
  int stage_v_208_2 = (((stage_v_68_2 * 3) + pub_r001343_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = (((stage_v_175_1 * 3) + pub_r001343_21_1) + 45) & 127;
  int stage_v_209_2 = (((stage_v_175_2 * 3) + pub_r001343_21_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = ((pub_r001343_4_1 * 2) + 31) & 63;
  int stage_v_210_2 = ((pub_r001343_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_8_1 * 3) + pub_r001343_11_1) + 8) & 127;
  int stage_v_211_2 = (((stage_v_8_2 * 3) + pub_r001343_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = ((pub_r001343_4_1 * 2) + 44) & 63;
  int stage_v_212_2 = ((pub_r001343_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001343_4_1 * 2) + 45) & 63;
  int stage_v_213_2 = ((pub_r001343_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001343_7_1 * 2) + 15) & 63;
  int stage_v_214_2 = ((pub_r001343_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001343_8_1 * 2) + 47) & 63;
  int stage_v_215_2 = ((pub_r001343_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001343_14_1 * 2) + 40) & 63;
  int stage_v_216_2 = ((pub_r001343_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((stage_v_82_1 * 3) + pub_r001343_18_1) + 16) & 127;
  int stage_v_217_2 = (((stage_v_82_2 * 3) + pub_r001343_18_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = (((stage_v_61_1 * 3) + pub_r001343_10_1) + 27) & 127;
  int stage_v_218_2 = (((stage_v_61_2 * 3) + pub_r001343_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = (((stage_v_82_1 * 3) + pub_r001343_10_1) + 23) & 127;
  int stage_v_219_2 = (((stage_v_82_2 * 3) + pub_r001343_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = ((pub_r001343_21_1 * 2) + 19) & 63;
  int stage_v_220_2 = ((pub_r001343_21_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001343_18_1 * 2) + 15) & 63;
  int stage_v_221_2 = ((pub_r001343_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((pub_r001343_16_1 * 2) + 48) & 63;
  int stage_v_222_2 = ((pub_r001343_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001343_2_1 * 2) + 25) & 63;
  int stage_v_223_2 = ((pub_r001343_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001343_2_1 * 2) + 26) & 63;
  int stage_v_224_2 = ((pub_r001343_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_211_1 * 3) + pub_r001343_10_1) + 44) & 127;
  int stage_v_225_2 = (((stage_v_211_2 * 3) + pub_r001343_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = (((stage_v_159_1 * 3) + pub_r001343_8_1) + 37) & 127;
  int stage_v_226_2 = (((stage_v_159_2 * 3) + pub_r001343_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = ((pub_r001343_1_1 * 2) + 24) & 63;
  int stage_v_227_2 = ((pub_r001343_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001343_0_1 * 2) + 43) & 63;
  int stage_v_228_2 = ((pub_r001343_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_32_1 * 3) + pub_r001343_1_1) + 31) & 127;
  int stage_v_229_2 = (((stage_v_32_2 * 3) + pub_r001343_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = ((pub_r001343_11_1 * 2) + 44) & 63;
  int stage_v_230_2 = ((pub_r001343_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((stage_v_149_1 * 3) + pub_r001343_6_1) + 30) & 127;
  int stage_v_231_2 = (((stage_v_149_2 * 3) + pub_r001343_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = (((stage_v_156_1 * 3) + pub_r001343_19_1) + 29) & 127;
  int stage_v_232_2 = (((stage_v_156_2 * 3) + pub_r001343_19_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = (((stage_v_91_1 * 3) + pub_r001343_12_1) + 13) & 127;
  int stage_v_233_2 = (((stage_v_91_2 * 3) + pub_r001343_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = ((pub_r001343_18_1 * 2) + 30) & 63;
  int stage_v_234_2 = ((pub_r001343_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001343_7_1 * 2) + 8) & 63;
  int stage_v_235_2 = ((pub_r001343_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = (((stage_v_125_1 * 3) + pub_r001343_19_1) + 35) & 127;
  int stage_v_236_2 = (((stage_v_125_2 * 3) + pub_r001343_19_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = (((stage_v_151_1 * 3) + pub_r001343_7_1) + 7) & 127;
  int stage_v_237_2 = (((stage_v_151_2 * 3) + pub_r001343_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = ((pub_r001343_21_1 * 2) + 17) & 63;
  int stage_v_238_2 = ((pub_r001343_21_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001343_17_1 * 2) + 31) & 63;
  int stage_v_239_2 = ((pub_r001343_17_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((stage_v_128_1 * 3) + pub_r001343_12_1) + 14) & 127;
  int stage_v_240_2 = (((stage_v_128_2 * 3) + pub_r001343_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((stage_v_32_1 * 3) + pub_r001343_16_1) + 4) & 127;
  int stage_v_241_2 = (((stage_v_32_2 * 3) + pub_r001343_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = ((pub_r001343_18_1 * 2) + 33) & 63;
  int stage_v_242_2 = ((pub_r001343_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = (((stage_v_56_1 * 3) + pub_r001343_8_1) + 35) & 127;
  int stage_v_243_2 = (((stage_v_56_2 * 3) + pub_r001343_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = (((stage_v_183_1 * 3) + pub_r001343_14_1) + 25) & 127;
  int stage_v_244_2 = (((stage_v_183_2 * 3) + pub_r001343_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((stage_v_208_1 * 3) + pub_r001343_15_1) + 27) & 127;
  int stage_v_245_2 = (((stage_v_208_2 * 3) + pub_r001343_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001343_7_1 * 2) + 16) & 63;
  int stage_v_246_2 = ((pub_r001343_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001343_17_1 * 2) + 23) & 63;
  int stage_v_247_2 = ((pub_r001343_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = (((sec_r001343_19_1 * 3) + pub_r001343_1_1) + 43) & 127;
  int stage_v_248_2 = (((sec_r001343_19_2 * 3) + pub_r001343_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = ((pub_r001343_7_1 * 2) + 6) & 63;
  int stage_v_249_2 = ((pub_r001343_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001343_12_1 * 2) + 49) & 63;
  int stage_v_250_2 = ((pub_r001343_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = (((stage_v_150_1 * 3) + pub_r001343_14_1) + 20) & 127;
  int stage_v_251_2 = (((stage_v_150_2 * 3) + pub_r001343_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = ((pub_r001343_19_1 * 2) + 21) & 63;
  int stage_v_252_2 = ((pub_r001343_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = (((stage_v_38_1 * 3) + pub_r001343_20_1) + 44) & 127;
  int stage_v_253_2 = (((stage_v_38_2 * 3) + pub_r001343_20_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = (((stage_v_43_1 * 3) + pub_r001343_19_1) + 15) & 127;
  int stage_v_254_2 = (((stage_v_43_2 * 3) + pub_r001343_19_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = ((pub_r001343_20_1 * 2) + 38) & 63;
  int stage_v_255_2 = ((pub_r001343_20_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = (((stage_v_60_1 * 3) + pub_r001343_5_1) + 23) & 127;
  int stage_v_256_2 = (((stage_v_60_2 * 3) + pub_r001343_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = ((pub_r001343_13_1 * 2) + 25) & 63;
  int stage_v_257_2 = ((pub_r001343_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_78_1 * 3) + pub_r001343_20_1) + 12) & 127;
  int stage_v_258_2 = (((stage_v_78_2 * 3) + pub_r001343_20_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001343_3_1 * 2) + 47) & 63;
  int stage_v_259_2 = ((pub_r001343_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001343_14_1 * 2) + 19) & 63;
  int stage_v_260_2 = ((pub_r001343_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001343_4_1 * 2) + 23) & 63;
  int stage_v_261_2 = ((pub_r001343_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001343_18_1 * 2) + 10) & 63;
  int stage_v_262_2 = ((pub_r001343_18_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001343_7_1 * 2) + 19) & 63;
  int stage_v_263_2 = ((pub_r001343_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((pub_r001343_17_1 * 2) + 39) & 63;
  int stage_v_264_2 = ((pub_r001343_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((stage_v_12_1 * 3) + pub_r001343_10_1) + 5) & 127;
  int stage_v_265_2 = (((stage_v_12_2 * 3) + pub_r001343_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = ((pub_r001343_12_1 * 2) + 40) & 63;
  int stage_v_266_2 = ((pub_r001343_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = (((stage_v_205_1 * 3) + pub_r001343_14_1) + 41) & 127;
  int stage_v_267_2 = (((stage_v_205_2 * 3) + pub_r001343_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = (((stage_v_44_1 * 3) + pub_r001343_18_1) + 18) & 127;
  int stage_v_268_2 = (((stage_v_44_2 * 3) + pub_r001343_18_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = (((sec_r001343_12_1 * 3) + pub_r001343_12_1) + 3) & 127;
  int stage_v_269_2 = (((sec_r001343_12_2 * 3) + pub_r001343_12_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = ((pub_r001343_13_1 * 2) + 29) & 63;
  int stage_v_270_2 = ((pub_r001343_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001343_5_1 * 2) + 17) & 63;
  int stage_v_271_2 = ((pub_r001343_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = (((stage_v_166_1 * 3) + pub_r001343_19_1) + 17) & 127;
  int stage_v_272_2 = (((stage_v_166_2 * 3) + pub_r001343_19_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = ((pub_r001343_13_1 * 2) + 29) & 63;
  int stage_v_273_2 = ((pub_r001343_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((pub_r001343_4_1 * 2) + 7) & 63;
  int stage_v_274_2 = ((pub_r001343_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001343_13_1 * 2) + 38) & 63;
  int stage_v_275_2 = ((pub_r001343_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((pub_r001343_19_1 * 2) + 22) & 63;
  int stage_v_276_2 = ((pub_r001343_19_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = (((stage_v_49_1 * 3) + pub_r001343_3_1) + 14) & 127;
  int stage_v_277_2 = (((stage_v_49_2 * 3) + pub_r001343_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = ((pub_r001343_19_1 * 2) + 32) & 63;
  int stage_v_278_2 = ((pub_r001343_19_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001343_1_1 * 2) + 13) & 63;
  int stage_v_279_2 = ((pub_r001343_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001343_10_1 * 2) + 14) & 63;
  int stage_v_280_2 = ((pub_r001343_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = (((stage_v_68_1 * 3) + pub_r001343_22_1) + 10) & 127;
  int stage_v_281_2 = (((stage_v_68_2 * 3) + pub_r001343_22_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = ((pub_r001343_3_1 * 2) + 32) & 63;
  int stage_v_282_2 = ((pub_r001343_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = (((stage_v_5_1 * 3) + pub_r001343_5_1) + 45) & 127;
  int stage_v_283_2 = (((stage_v_5_2 * 3) + pub_r001343_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = (((stage_v_102_1 * 3) + pub_r001343_4_1) + 9) & 127;
  int stage_v_284_2 = (((stage_v_102_2 * 3) + pub_r001343_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = (((stage_v_21_1 * 3) + pub_r001343_12_1) + 4) & 127;
  int stage_v_285_2 = (((stage_v_21_2 * 3) + pub_r001343_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = (((stage_v_225_1 * 3) + pub_r001343_4_1) + 37) & 127;
  int stage_v_286_2 = (((stage_v_225_2 * 3) + pub_r001343_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = (((stage_v_75_1 * 3) + pub_r001343_10_1) + 3) & 127;
  int stage_v_287_2 = (((stage_v_75_2 * 3) + pub_r001343_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((stage_v_277_1 * 3) + pub_r001343_22_1) + 21) & 127;
  int stage_v_288_2 = (((stage_v_277_2 * 3) + pub_r001343_22_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = ((pub_r001343_16_1 * 2) + 9) & 63;
  int stage_v_289_2 = ((pub_r001343_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = (((helper_flow_0_1 * 3) + pub_r001343_0_1) + 31) & 127;
  int stage_v_290_2 = (((helper_flow_0_2 * 3) + pub_r001343_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = (((sec_r001343_11_1 * 3) + pub_r001343_12_1) + 40) & 127;
  int stage_v_291_2 = (((sec_r001343_11_2 * 3) + pub_r001343_12_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = ((pub_r001343_1_1 * 2) + 25) & 63;
  int stage_v_292_2 = ((pub_r001343_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001343_8_1 * 2) + 25) & 63;
  int stage_v_293_2 = ((pub_r001343_8_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = (((stage_v_283_1 * 3) + pub_r001343_0_1) + 39) & 127;
  int stage_v_294_2 = (((stage_v_283_2 * 3) + pub_r001343_0_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = ((pub_r001343_8_1 * 2) + 42) & 63;
  int stage_v_295_2 = ((pub_r001343_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = (((stage_v_248_1 * 3) + pub_r001343_4_1) + 21) & 127;
  int stage_v_296_2 = (((stage_v_248_2 * 3) + pub_r001343_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = (((stage_v_225_1 * 3) + pub_r001343_18_1) + 33) & 127;
  int stage_v_297_2 = (((stage_v_225_2 * 3) + pub_r001343_18_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = (((stage_v_296_1 * 3) + pub_r001343_5_1) + 3) & 127;
  int stage_v_298_2 = (((stage_v_296_2 * 3) + pub_r001343_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001343_4_1 * 2) + 48) & 63;
  int stage_v_299_2 = ((pub_r001343_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001343_3_1 * 2) + 41) & 63;
  int stage_v_300_2 = ((pub_r001343_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001343_8_1 * 2) + 9) & 63;
  int stage_v_301_2 = ((pub_r001343_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001343_14_1 * 2) + 14) & 63;
  int stage_v_302_2 = ((pub_r001343_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001343_9_1 * 2) + 11) & 63;
  int stage_v_303_2 = ((pub_r001343_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = (((stage_v_137_1 * 3) + pub_r001343_16_1) + 7) & 127;
  int stage_v_304_2 = (((stage_v_137_2 * 3) + pub_r001343_16_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = ((pub_r001343_7_1 * 2) + 7) & 63;
  int stage_v_305_2 = ((pub_r001343_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_232_1 * 3) + pub_r001343_1_1) + 31) & 127;
  int stage_v_306_2 = (((stage_v_232_2 * 3) + pub_r001343_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = ((pub_r001343_15_1 * 2) + 38) & 63;
  int stage_v_307_2 = ((pub_r001343_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = (((stage_v_211_1 * 3) + pub_r001343_6_1) + 3) & 127;
  int stage_v_308_2 = (((stage_v_211_2 * 3) + pub_r001343_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = ((pub_r001343_19_1 * 2) + 43) & 63;
  int stage_v_309_2 = ((pub_r001343_19_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001343_20_1 * 2) + 30) & 63;
  int stage_v_310_2 = ((pub_r001343_20_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((pub_r001343_0_1 * 2) + 11) & 63;
  int stage_v_311_2 = ((pub_r001343_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = (((stage_v_24_1 * 3) + pub_r001343_6_1) + 8) & 127;
  int stage_v_312_2 = (((stage_v_24_2 * 3) + pub_r001343_6_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = ((pub_r001343_11_1 * 2) + 49) & 63;
  int stage_v_313_2 = ((pub_r001343_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = ((pub_r001343_5_1 * 2) + 28) & 63;
  int stage_v_314_2 = ((pub_r001343_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = (((stage_v_114_1 * 3) + pub_r001343_22_1) + 17) & 127;
  int stage_v_315_2 = (((stage_v_114_2 * 3) + pub_r001343_22_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((stage_v_297_1 * 3) + pub_r001343_7_1) + 30) & 127;
  int stage_v_316_2 = (((stage_v_297_2 * 3) + pub_r001343_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = ((pub_r001343_19_1 * 2) + 32) & 63;
  int stage_v_317_2 = ((pub_r001343_19_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001343_9_1 * 2) + 18) & 63;
  int stage_v_318_2 = ((pub_r001343_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = (((stage_v_267_1 * 3) + pub_r001343_13_1) + 45) & 127;
  int stage_v_319_2 = (((stage_v_267_2 * 3) + pub_r001343_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = (((stage_v_159_1 * 3) + pub_r001343_10_1) + 45) & 127;
  int stage_v_320_2 = (((stage_v_159_2 * 3) + pub_r001343_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = (((stage_v_219_1 * 3) + pub_r001343_18_1) + 42) & 127;
  int stage_v_321_2 = (((stage_v_219_2 * 3) + pub_r001343_18_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((sec_r001343_16_1 * 3) + pub_r001343_18_1) + 27) & 127;
  int stage_v_322_2 = (((sec_r001343_16_2 * 3) + pub_r001343_18_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = ((pub_r001343_1_1 * 2) + 11) & 63;
  int stage_v_323_2 = ((pub_r001343_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = (((stage_v_60_1 * 3) + pub_r001343_7_1) + 11) & 127;
  int stage_v_324_2 = (((stage_v_60_2 * 3) + pub_r001343_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((stage_v_285_1 * 3) + pub_r001343_19_1) + 38) & 127;
  int stage_v_325_2 = (((stage_v_285_2 * 3) + pub_r001343_19_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = (((sec_r001343_12_1 * 3) + pub_r001343_19_1) + 19) & 127;
  int stage_v_326_2 = (((sec_r001343_12_2 * 3) + pub_r001343_19_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = ((pub_r001343_20_1 * 2) + 8) & 63;
  int stage_v_327_2 = ((pub_r001343_20_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001343_17_1 * 2) + 25) & 63;
  int stage_v_328_2 = ((pub_r001343_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = (((stage_v_35_1 * 3) + pub_r001343_1_1) + 12) & 127;
  int stage_v_329_2 = (((stage_v_35_2 * 3) + pub_r001343_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = ((pub_r001343_21_1 * 2) + 36) & 63;
  int stage_v_330_2 = ((pub_r001343_21_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = (((stage_v_285_1 * 3) + pub_r001343_14_1) + 35) & 127;
  int stage_v_331_2 = (((stage_v_285_2 * 3) + pub_r001343_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = (((stage_v_316_1 * 3) + pub_r001343_8_1) + 45) & 127;
  int stage_v_332_2 = (((stage_v_316_2 * 3) + pub_r001343_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = ((pub_r001343_13_1 * 2) + 41) & 63;
  int stage_v_333_2 = ((pub_r001343_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = (((stage_v_272_1 * 3) + pub_r001343_16_1) + 43) & 127;
  int stage_v_334_2 = (((stage_v_272_2 * 3) + pub_r001343_16_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = (((stage_v_119_1 * 3) + pub_r001343_13_1) + 32) & 127;
  int stage_v_335_2 = (((stage_v_119_2 * 3) + pub_r001343_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = (((sec_r001343_10_1 * 3) + pub_r001343_11_1) + 10) & 127;
  int stage_v_336_2 = (((sec_r001343_10_2 * 3) + pub_r001343_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((stage_v_229_1 * 3) + pub_r001343_22_1) + 31) & 127;
  int stage_v_337_2 = (((stage_v_229_2 * 3) + pub_r001343_22_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = ((pub_r001343_8_1 * 2) + 13) & 63;
  int stage_v_338_2 = ((pub_r001343_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((pub_r001343_22_1 * 2) + 11) & 63;
  int stage_v_339_2 = ((pub_r001343_22_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001343_2_1 * 2) + 45) & 63;
  int stage_v_340_2 = ((pub_r001343_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001343_14_1 * 2) + 46) & 63;
  int stage_v_341_2 = ((pub_r001343_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = (((stage_v_172_1 * 3) + pub_r001343_11_1) + 9) & 127;
  int stage_v_342_2 = (((stage_v_172_2 * 3) + pub_r001343_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = (((stage_v_90_1 * 3) + pub_r001343_8_1) + 38) & 127;
  int stage_v_343_2 = (((stage_v_90_2 * 3) + pub_r001343_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_322_1 * 3) + pub_r001343_17_1) + 40) & 127;
  int stage_v_344_2 = (((stage_v_322_2 * 3) + pub_r001343_17_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001343_4_1 * 2) + 22) & 63;
  int stage_v_345_2 = ((pub_r001343_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = (((stage_v_5_1 * 3) + pub_r001343_8_1) + 17) & 127;
  int stage_v_346_2 = (((stage_v_5_2 * 3) + pub_r001343_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = ((pub_r001343_3_1 * 2) + 16) & 63;
  int stage_v_347_2 = ((pub_r001343_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001343_9_1 * 2) + 26) & 63;
  int stage_v_348_2 = ((pub_r001343_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = (((stage_v_304_1 * 3) + pub_r001343_20_1) + 35) & 127;
  int stage_v_349_2 = (((stage_v_304_2 * 3) + pub_r001343_20_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = ((pub_r001343_16_1 * 2) + 21) & 63;
  int stage_v_350_2 = ((pub_r001343_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = (((stage_v_325_1 * 3) + pub_r001343_19_1) + 26) & 127;
  int stage_v_351_2 = (((stage_v_325_2 * 3) + pub_r001343_19_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = (((stage_v_316_1 * 3) + pub_r001343_5_1) + 38) & 127;
  int stage_v_352_2 = (((stage_v_316_2 * 3) + pub_r001343_5_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = (((stage_v_156_1 * 3) + pub_r001343_1_1) + 21) & 127;
  int stage_v_353_2 = (((stage_v_156_2 * 3) + pub_r001343_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = ((pub_r001343_15_1 * 2) + 10) & 63;
  int stage_v_354_2 = ((pub_r001343_15_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = (((sec_r001343_19_1 * 3) + pub_r001343_20_1) + 33) & 127;
  int stage_v_355_2 = (((sec_r001343_19_2 * 3) + pub_r001343_20_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_91_1 * 3) + pub_r001343_9_1) + 43) & 127;
  int stage_v_356_2 = (((stage_v_91_2 * 3) + pub_r001343_9_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = (((stage_v_193_1 * 3) + pub_r001343_21_1) + 10) & 127;
  int stage_v_357_2 = (((stage_v_193_2 * 3) + pub_r001343_21_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = (((sec_r001343_12_1 * 3) + pub_r001343_10_1) + 39) & 127;
  int stage_v_358_2 = (((sec_r001343_12_2 * 3) + pub_r001343_10_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = (((sec_r001343_6_1 * 3) + pub_r001343_2_1) + 22) & 127;
  int stage_v_359_2 = (((sec_r001343_6_2 * 3) + pub_r001343_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = ((pub_r001343_8_1 * 2) + 35) & 63;
  int stage_v_360_2 = ((pub_r001343_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = (((sec_r001343_19_1 * 3) + pub_r001343_21_1) + 37) & 127;
  int stage_v_361_2 = (((sec_r001343_19_2 * 3) + pub_r001343_21_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = ((pub_r001343_13_1 * 2) + 45) & 63;
  int stage_v_362_2 = ((pub_r001343_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001343_14_1 * 2) + 18) & 63;
  int stage_v_363_2 = ((pub_r001343_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = (((stage_v_312_1 * 3) + pub_r001343_18_1) + 43) & 127;
  int stage_v_364_2 = (((stage_v_312_2 * 3) + pub_r001343_18_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = (((stage_v_56_1 * 3) + pub_r001343_6_1) + 9) & 127;
  int stage_v_365_2 = (((stage_v_56_2 * 3) + pub_r001343_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = ((pub_r001343_16_1 * 2) + 27) & 63;
  int stage_v_366_2 = ((pub_r001343_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = (((stage_v_288_1 * 3) + pub_r001343_15_1) + 36) & 127;
  int stage_v_367_2 = (((stage_v_288_2 * 3) + pub_r001343_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = (((stage_v_32_1 * 3) + pub_r001343_18_1) + 20) & 127;
  int stage_v_368_2 = (((stage_v_32_2 * 3) + pub_r001343_18_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = (((stage_v_184_1 * 3) + pub_r001343_11_1) + 22) & 127;
  int stage_v_369_2 = (((stage_v_184_2 * 3) + pub_r001343_11_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = ((pub_r001343_18_1 * 2) + 18) & 63;
  int stage_v_370_2 = ((pub_r001343_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = (((sec_r001343_1_1 * 3) + pub_r001343_12_1) + 29) & 127;
  int stage_v_371_2 = (((sec_r001343_1_2 * 3) + pub_r001343_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001343_14_1 * 2) + 35) & 63;
  int stage_v_372_2 = ((pub_r001343_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001343_12_1 * 2) + 32) & 63;
  int stage_v_373_2 = ((pub_r001343_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = (((stage_v_50_1 * 3) + pub_r001343_15_1) + 45) & 127;
  int stage_v_374_2 = (((stage_v_50_2 * 3) + pub_r001343_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_368_1 * 3) + pub_r001343_9_1) + 5) & 127;
  int stage_v_375_2 = (((stage_v_368_2 * 3) + pub_r001343_9_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = (((stage_v_49_1 * 3) + pub_r001343_0_1) + 29) & 127;
  int stage_v_376_2 = (((stage_v_49_2 * 3) + pub_r001343_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = ((pub_r001343_1_1 * 2) + 6) & 63;
  int stage_v_377_2 = ((pub_r001343_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = (((sec_r001343_21_1 * 3) + pub_r001343_16_1) + 26) & 127;
  int stage_v_378_2 = (((sec_r001343_21_2 * 3) + pub_r001343_16_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((stage_v_352_1 * 3) + pub_r001343_0_1) + 9) & 127;
  int stage_v_379_2 = (((stage_v_352_2 * 3) + pub_r001343_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = ((pub_r001343_13_1 * 2) + 47) & 63;
  int stage_v_380_2 = ((pub_r001343_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = (((stage_v_142_1 * 3) + pub_r001343_3_1) + 22) & 127;
  int stage_v_381_2 = (((stage_v_142_2 * 3) + pub_r001343_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = ((pub_r001343_0_1 * 2) + 26) & 63;
  int stage_v_382_2 = ((pub_r001343_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = (((helper_flow_5_1 * 3) + pub_r001343_7_1) + 21) & 127;
  int stage_v_383_2 = (((helper_flow_5_2 * 3) + pub_r001343_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = ((pub_r001343_20_1 * 2) + 15) & 63;
  int stage_v_384_2 = ((pub_r001343_20_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001343_18_1 * 2) + 38) & 63;
  int stage_v_385_2 = ((pub_r001343_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001343_0_1 * 2) + 34) & 63;
  int stage_v_386_2 = ((pub_r001343_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001343_17_1 * 2) + 17) & 63;
  int stage_v_387_2 = ((pub_r001343_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001343_21_1 * 2) + 22) & 63;
  int stage_v_388_2 = ((pub_r001343_21_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = (((stage_v_365_1 * 3) + pub_r001343_2_1) + 29) & 127;
  int stage_v_389_2 = (((stage_v_365_2 * 3) + pub_r001343_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = ((pub_r001343_9_1 * 2) + 12) & 63;
  int stage_v_390_2 = ((pub_r001343_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = (((sec_r001343_14_1 * 3) + pub_r001343_9_1) + 27) & 127;
  int stage_v_391_2 = (((sec_r001343_14_2 * 3) + pub_r001343_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((stage_v_324_1 * 3) + pub_r001343_12_1) + 9) & 127;
  int stage_v_392_2 = (((stage_v_324_2 * 3) + pub_r001343_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = (((stage_v_143_1 * 3) + pub_r001343_17_1) + 37) & 127;
  int stage_v_393_2 = (((stage_v_143_2 * 3) + pub_r001343_17_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = ((pub_r001343_12_1 * 2) + 31) & 63;
  int stage_v_394_2 = ((pub_r001343_12_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = (((stage_v_236_1 * 3) + pub_r001343_14_1) + 41) & 127;
  int stage_v_395_2 = (((stage_v_236_2 * 3) + pub_r001343_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = (((stage_v_237_1 * 3) + pub_r001343_15_1) + 22) & 127;
  int stage_v_396_2 = (((stage_v_237_2 * 3) + pub_r001343_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = ((pub_r001343_3_1 * 2) + 45) & 63;
  int stage_v_397_2 = ((pub_r001343_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = (((stage_v_376_1 * 3) + pub_r001343_1_1) + 37) & 127;
  int stage_v_398_2 = (((stage_v_376_2 * 3) + pub_r001343_1_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = ((pub_r001343_22_1 * 2) + 45) & 63;
  int stage_v_399_2 = ((pub_r001343_22_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001343_17_1 * 2) + 42) & 63;
  int stage_v_400_2 = ((pub_r001343_17_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((pub_r001343_21_1 * 2) + 10) & 63;
  int stage_v_401_2 = ((pub_r001343_21_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = ((pub_r001343_8_1 * 2) + 30) & 63;
  int stage_v_402_2 = ((pub_r001343_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((pub_r001343_3_1 * 2) + 20) & 63;
  int stage_v_403_2 = ((pub_r001343_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = ((pub_r001343_4_1 * 2) + 33) & 63;
  int stage_v_404_2 = ((pub_r001343_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = (((stage_v_166_1 * 3) + pub_r001343_1_1) + 15) & 127;
  int stage_v_405_2 = (((stage_v_166_2 * 3) + pub_r001343_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = (((stage_v_396_1 * 3) + pub_r001343_4_1) + 11) & 127;
  int stage_v_406_2 = (((stage_v_396_2 * 3) + pub_r001343_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = (((stage_v_176_1 * 3) + pub_r001343_11_1) + 7) & 127;
  int stage_v_407_2 = (((stage_v_176_2 * 3) + pub_r001343_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_407_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_407_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_407_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_407_2 * 2)) & 255;
  int stage_v_408_1 = ((pub_r001343_6_1 * 2) + 44) & 63;
  int stage_v_408_2 = ((pub_r001343_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = (((stage_v_326_1 * 3) + pub_r001343_9_1) + 19) & 127;
  int stage_v_409_2 = (((stage_v_326_2 * 3) + pub_r001343_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_409_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_409_2 * 2)) & 255;
  int stage_v_410_1 = ((pub_r001343_8_1 * 2) + 14) & 63;
  int stage_v_410_2 = ((pub_r001343_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001343_3_1 * 2) + 26) & 63;
  int stage_v_411_2 = ((pub_r001343_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = (((stage_v_368_1 * 3) + pub_r001343_1_1) + 15) & 127;
  int stage_v_412_2 = (((stage_v_368_2 * 3) + pub_r001343_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = (((helper_flow_4_1 * 3) + pub_r001343_18_1) + 31) & 127;
  int stage_v_413_2 = (((helper_flow_4_2 * 3) + pub_r001343_18_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_413_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_413_2 * 2)) & 255;
  int stage_v_414_1 = (((stage_v_113_1 * 3) + pub_r001343_17_1) + 3) & 127;
  int stage_v_414_2 = (((stage_v_113_2 * 3) + pub_r001343_17_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_414_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_414_2 * 2)) & 255;
  int stage_v_415_1 = (((stage_v_144_1 * 3) + pub_r001343_13_1) + 14) & 127;
  int stage_v_415_2 = (((stage_v_144_2 * 3) + pub_r001343_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = ((pub_r001343_17_1 * 2) + 15) & 63;
  int stage_v_416_2 = ((pub_r001343_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = (((stage_v_201_1 * 3) + pub_r001343_1_1) + 9) & 127;
  int stage_v_417_2 = (((stage_v_201_2 * 3) + pub_r001343_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = ((pub_r001343_6_1 * 2) + 10) & 63;
  int stage_v_418_2 = ((pub_r001343_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((pub_r001343_8_1 * 2) + 12) & 63;
  int stage_v_419_2 = ((pub_r001343_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = ((pub_r001343_5_1 * 2) + 23) & 63;
  int stage_v_420_2 = ((pub_r001343_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = ((pub_r001343_20_1 * 2) + 13) & 63;
  int stage_v_421_2 = ((pub_r001343_20_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((pub_r001343_15_1 * 2) + 47) & 63;
  int stage_v_422_2 = ((pub_r001343_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = (((stage_v_164_1 * 3) + pub_r001343_10_1) + 39) & 127;
  int stage_v_423_2 = (((stage_v_164_2 * 3) + pub_r001343_10_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_423_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_423_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_423_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_423_2 * 2)) & 255;
  int stage_v_424_1 = (((stage_v_10_1 * 3) + pub_r001343_17_1) + 21) & 127;
  int stage_v_424_2 = (((stage_v_10_2 * 3) + pub_r001343_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_424_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_424_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_424_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_424_2 * 2)) & 255;
  int stage_v_425_1 = ((pub_r001343_0_1 * 2) + 48) & 63;
  int stage_v_425_2 = ((pub_r001343_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = ((pub_r001343_0_1 * 2) + 37) & 63;
  int stage_v_426_2 = ((pub_r001343_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((pub_r001343_16_1 * 2) + 21) & 63;
  int stage_v_427_2 = ((pub_r001343_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = (((stage_v_351_1 * 3) + pub_r001343_9_1) + 29) & 127;
  int stage_v_428_2 = (((stage_v_351_2 * 3) + pub_r001343_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  int stage_v_429_1 = (((stage_v_20_1 * 3) + pub_r001343_15_1) + 18) & 127;
  int stage_v_429_2 = (((stage_v_20_2 * 3) + pub_r001343_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = ((pub_r001343_3_1 * 2) + 14) & 63;
  int stage_v_430_2 = ((pub_r001343_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = (((stage_v_429_1 * 3) + pub_r001343_0_1) + 37) & 127;
  int stage_v_431_2 = (((stage_v_429_2 * 3) + pub_r001343_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_431_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_431_2 * 2)) & 255;
  int stage_v_432_1 = ((pub_r001343_8_1 * 2) + 15) & 63;
  int stage_v_432_2 = ((pub_r001343_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = ((pub_r001343_0_1 * 2) + 36) & 63;
  int stage_v_433_2 = ((pub_r001343_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = ((pub_r001343_4_1 * 2) + 48) & 63;
  int stage_v_434_2 = ((pub_r001343_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = ((pub_r001343_19_1 * 2) + 43) & 63;
  int stage_v_435_2 = ((pub_r001343_19_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = (((stage_v_395_1 * 3) + pub_r001343_13_1) + 35) & 127;
  int stage_v_436_2 = (((stage_v_395_2 * 3) + pub_r001343_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_436_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_436_2 * 2)) & 255;
  int stage_v_437_1 = (((stage_v_94_1 * 3) + pub_r001343_4_1) + 15) & 127;
  int stage_v_437_2 = (((stage_v_94_2 * 3) + pub_r001343_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  int stage_v_438_1 = (((stage_v_294_1 * 3) + pub_r001343_1_1) + 5) & 127;
  int stage_v_438_2 = (((stage_v_294_2 * 3) + pub_r001343_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_438_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_438_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_438_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_438_2 * 2)) & 255;
  int stage_v_439_1 = (((stage_v_219_1 * 3) + pub_r001343_5_1) + 21) & 127;
  int stage_v_439_2 = (((stage_v_219_2 * 3) + pub_r001343_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_439_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_439_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_439_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_439_2 * 2)) & 255;
  int stage_v_440_1 = ((pub_r001343_16_1 * 2) + 20) & 63;
  int stage_v_440_2 = ((pub_r001343_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001343_4_1 * 2) + 23) & 63;
  int stage_v_441_2 = ((pub_r001343_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((pub_r001343_21_1 * 2) + 19) & 63;
  int stage_v_442_2 = ((pub_r001343_21_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = (((stage_v_381_1 * 3) + pub_r001343_15_1) + 37) & 127;
  int stage_v_443_2 = (((stage_v_381_2 * 3) + pub_r001343_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_443_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_443_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_443_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_443_2 * 2)) & 255;
  int stage_v_444_1 = (((stage_v_56_1 * 3) + pub_r001343_11_1) + 40) & 127;
  int stage_v_444_2 = (((stage_v_56_2 * 3) + pub_r001343_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_444_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_444_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_444_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_444_2 * 2)) & 255;
  int stage_v_445_1 = (((stage_v_102_1 * 3) + pub_r001343_12_1) + 27) & 127;
  int stage_v_445_2 = (((stage_v_102_2 * 3) + pub_r001343_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_445_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_445_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_445_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_445_2 * 2)) & 255;
  int stage_v_446_1 = (((stage_v_4_1 * 3) + pub_r001343_12_1) + 17) & 127;
  int stage_v_446_2 = (((stage_v_4_2 * 3) + pub_r001343_12_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_446_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_446_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_446_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_446_2 * 2)) & 255;
  int stage_v_447_1 = (((stage_v_166_1 * 3) + pub_r001343_9_1) + 43) & 127;
  int stage_v_447_2 = (((stage_v_166_2 * 3) + pub_r001343_9_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_447_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_447_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_447_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_447_2 * 2)) & 255;
  int stage_v_448_1 = ((pub_r001343_18_1 * 2) + 6) & 63;
  int stage_v_448_2 = ((pub_r001343_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = ((pub_r001343_6_1 * 2) + 25) & 63;
  int stage_v_449_2 = ((pub_r001343_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_449_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_449_2) & 127;
  int stage_v_450_1 = (((stage_v_351_1 * 3) + pub_r001343_17_1) + 9) & 127;
  int stage_v_450_2 = (((stage_v_351_2 * 3) + pub_r001343_17_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_450_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_450_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_450_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_450_2 * 2)) & 255;
  int stage_v_451_1 = (((stage_v_226_1 * 3) + pub_r001343_5_1) + 37) & 127;
  int stage_v_451_2 = (((stage_v_226_2 * 3) + pub_r001343_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_451_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_451_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_451_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_451_2 * 2)) & 255;
  int stage_v_452_1 = (((stage_v_356_1 * 3) + pub_r001343_0_1) + 28) & 127;
  int stage_v_452_2 = (((stage_v_356_2 * 3) + pub_r001343_0_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_452_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_452_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_452_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_452_2 * 2)) & 255;
  int stage_v_453_1 = ((pub_r001343_17_1 * 2) + 50) & 63;
  int stage_v_453_2 = ((pub_r001343_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = ((pub_r001343_20_1 * 2) + 6) & 63;
  int stage_v_454_2 = ((pub_r001343_20_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = (((stage_v_281_1 * 3) + pub_r001343_14_1) + 45) & 127;
  int stage_v_455_2 = (((stage_v_281_2 * 3) + pub_r001343_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_455_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_455_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_455_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_455_2 * 2)) & 255;
  int stage_v_456_1 = (((stage_v_186_1 * 3) + pub_r001343_22_1) + 24) & 127;
  int stage_v_456_2 = (((stage_v_186_2 * 3) + pub_r001343_22_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_456_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_456_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_456_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_456_2 * 2)) & 255;
  int stage_v_457_1 = (((helper_flow_3_1 * 3) + pub_r001343_22_1) + 25) & 127;
  int stage_v_457_2 = (((helper_flow_3_2 * 3) + pub_r001343_22_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_457_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_457_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_457_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_457_2 * 2)) & 255;
  int stage_v_458_1 = ((pub_r001343_14_1 * 2) + 24) & 63;
  int stage_v_458_2 = ((pub_r001343_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = (((stage_v_353_1 * 3) + pub_r001343_6_1) + 36) & 127;
  int stage_v_459_2 = (((stage_v_353_2 * 3) + pub_r001343_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_459_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_459_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_459_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_459_2 * 2)) & 255;
  int stage_v_460_1 = (((stage_v_61_1 * 3) + pub_r001343_13_1) + 31) & 127;
  int stage_v_460_2 = (((stage_v_61_2 * 3) + pub_r001343_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_460_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_460_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_460_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_460_2 * 2)) & 255;
  int stage_v_461_1 = (((sec_r001343_14_1 * 3) + pub_r001343_14_1) + 3) & 127;
  int stage_v_461_2 = (((sec_r001343_14_2 * 3) + pub_r001343_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_461_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_461_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_461_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_461_2 * 2)) & 255;
  int stage_v_462_1 = (((stage_v_127_1 * 3) + pub_r001343_13_1) + 17) & 127;
  int stage_v_462_2 = (((stage_v_127_2 * 3) + pub_r001343_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_462_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_462_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_462_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_462_2 * 2)) & 255;
  int stage_v_463_1 = (((stage_v_29_1 * 3) + pub_r001343_18_1) + 37) & 127;
  int stage_v_463_2 = (((stage_v_29_2 * 3) + pub_r001343_18_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_463_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_463_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_463_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_463_2 * 2)) & 255;
  int stage_v_464_1 = (((stage_v_35_1 * 3) + pub_r001343_1_1) + 9) & 127;
  int stage_v_464_2 = (((stage_v_35_2 * 3) + pub_r001343_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_464_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_464_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_464_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_464_2 * 2)) & 255;
  int stage_v_465_1 = ((pub_r001343_8_1 * 2) + 18) & 63;
  int stage_v_465_2 = ((pub_r001343_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = ((pub_r001343_21_1 * 2) + 18) & 63;
  int stage_v_466_2 = ((pub_r001343_21_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_466_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_466_2) & 127;
  int stage_v_467_1 = (((stage_v_229_1 * 3) + pub_r001343_14_1) + 15) & 127;
  int stage_v_467_2 = (((stage_v_229_2 * 3) + pub_r001343_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_467_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_467_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_467_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_467_2 * 2)) & 255;
  int stage_v_468_1 = (((stage_v_200_1 * 3) + pub_r001343_10_1) + 34) & 127;
  int stage_v_468_2 = (((stage_v_200_2 * 3) + pub_r001343_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_468_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_468_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_468_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_468_2 * 2)) & 255;
  int stage_v_469_1 = (((stage_v_119_1 * 3) + pub_r001343_10_1) + 19) & 127;
  int stage_v_469_2 = (((stage_v_119_2 * 3) + pub_r001343_10_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_469_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_469_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_469_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_469_2 * 2)) & 255;
  int stage_v_470_1 = (((sec_r001343_22_1 * 3) + pub_r001343_18_1) + 9) & 127;
  int stage_v_470_2 = (((sec_r001343_22_2 * 3) + pub_r001343_18_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_470_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_470_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_470_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_470_2 * 2)) & 255;
  int stage_v_471_1 = (((stage_v_256_1 * 3) + pub_r001343_6_1) + 41) & 127;
  int stage_v_471_2 = (((stage_v_256_2 * 3) + pub_r001343_6_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_471_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_471_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_471_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_471_2 * 2)) & 255;
  int stage_v_472_1 = (((sec_r001343_22_1 * 3) + pub_r001343_20_1) + 38) & 127;
  int stage_v_472_2 = (((sec_r001343_22_2 * 3) + pub_r001343_20_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_472_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_472_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_472_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_472_2 * 2)) & 255;
  int stage_v_473_1 = ((pub_r001343_12_1 * 2) + 33) & 63;
  int stage_v_473_2 = ((pub_r001343_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_473_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_473_2) & 127;
  int stage_v_474_1 = (((stage_v_417_1 * 3) + pub_r001343_0_1) + 10) & 127;
  int stage_v_474_2 = (((stage_v_417_2 * 3) + pub_r001343_0_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_474_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_474_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_474_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_474_2 * 2)) & 255;
  int stage_v_475_1 = (((stage_v_231_1 * 3) + pub_r001343_15_1) + 44) & 127;
  int stage_v_475_2 = (((stage_v_231_2 * 3) + pub_r001343_15_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_475_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_475_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_475_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_475_2 * 2)) & 255;
  int stage_v_476_1 = (((stage_v_150_1 * 3) + pub_r001343_4_1) + 39) & 127;
  int stage_v_476_2 = (((stage_v_150_2 * 3) + pub_r001343_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_476_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_476_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_476_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_476_2 * 2)) & 255;
  int stage_v_477_1 = ((pub_r001343_12_1 * 2) + 43) & 63;
  int stage_v_477_2 = ((pub_r001343_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_477_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_477_2) & 127;
  int stage_v_478_1 = (((stage_v_405_1 * 3) + pub_r001343_19_1) + 5) & 127;
  int stage_v_478_2 = (((stage_v_405_2 * 3) + pub_r001343_19_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_478_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_478_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_478_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_478_2 * 2)) & 255;
  int stage_v_479_1 = ((pub_r001343_0_1 * 2) + 30) & 63;
  int stage_v_479_2 = ((pub_r001343_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_479_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_479_2) & 127;
  int stage_v_480_1 = ((pub_r001343_9_1 * 2) + 29) & 63;
  int stage_v_480_2 = ((pub_r001343_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_480_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_480_2) & 127;
  int stage_v_481_1 = (((stage_v_361_1 * 3) + pub_r001343_6_1) + 32) & 127;
  int stage_v_481_2 = (((stage_v_361_2 * 3) + pub_r001343_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_481_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_481_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_481_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_481_2 * 2)) & 255;
  int stage_v_482_1 = (((stage_v_439_1 * 3) + pub_r001343_8_1) + 41) & 127;
  int stage_v_482_2 = (((stage_v_439_2 * 3) + pub_r001343_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_482_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_482_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_482_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_482_2 * 2)) & 255;
  int stage_v_483_1 = (((stage_v_383_1 * 3) + pub_r001343_20_1) + 33) & 127;
  int stage_v_483_2 = (((stage_v_383_2 * 3) + pub_r001343_20_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_483_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_483_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_483_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_483_2 * 2)) & 255;
  int stage_v_484_1 = ((pub_r001343_14_1 * 2) + 11) & 63;
  int stage_v_484_2 = ((pub_r001343_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_484_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_484_2) & 127;
  int stage_v_485_1 = (((stage_v_444_1 * 3) + pub_r001343_2_1) + 15) & 127;
  int stage_v_485_2 = (((stage_v_444_2 * 3) + pub_r001343_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_485_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_485_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_485_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_485_2 * 2)) & 255;
  int stage_v_486_1 = (((stage_v_315_1 * 3) + pub_r001343_22_1) + 33) & 127;
  int stage_v_486_2 = (((stage_v_315_2 * 3) + pub_r001343_22_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_486_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_486_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_486_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_486_2 * 2)) & 255;
  int stage_v_487_1 = (((stage_v_5_1 * 3) + pub_r001343_20_1) + 6) & 127;
  int stage_v_487_2 = (((stage_v_5_2 * 3) + pub_r001343_20_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_487_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_487_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_487_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_487_2 * 2)) & 255;
  int stage_v_488_1 = (((stage_v_474_1 * 3) + pub_r001343_0_1) + 11) & 127;
  int stage_v_488_2 = (((stage_v_474_2 * 3) + pub_r001343_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_488_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_488_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_488_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_488_2 * 2)) & 255;
  int stage_v_489_1 = (((stage_v_393_1 * 3) + pub_r001343_7_1) + 27) & 127;
  int stage_v_489_2 = (((stage_v_393_2 * 3) + pub_r001343_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_489_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_489_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_489_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_489_2 * 2)) & 255;
  int stage_v_490_1 = (((stage_v_123_1 * 3) + pub_r001343_18_1) + 33) & 127;
  int stage_v_490_2 = (((stage_v_123_2 * 3) + pub_r001343_18_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_490_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_490_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_490_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_490_2 * 2)) & 255;
  int stage_v_491_1 = ((pub_r001343_0_1 * 2) + 40) & 63;
  int stage_v_491_2 = ((pub_r001343_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_491_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_491_2) & 127;
  int stage_v_492_1 = ((pub_r001343_13_1 * 2) + 44) & 63;
  int stage_v_492_2 = ((pub_r001343_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_492_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_492_2) & 127;
  int stage_v_493_1 = ((pub_r001343_4_1 * 2) + 48) & 63;
  int stage_v_493_2 = ((pub_r001343_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_493_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_493_2) & 127;
  int stage_v_494_1 = (((stage_v_177_1 * 3) + pub_r001343_5_1) + 12) & 127;
  int stage_v_494_2 = (((stage_v_177_2 * 3) + pub_r001343_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_494_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_494_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_494_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_494_2 * 2)) & 255;
  int stage_v_495_1 = ((pub_r001343_7_1 * 2) + 7) & 63;
  int stage_v_495_2 = ((pub_r001343_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_495_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_495_2) & 127;
  int stage_v_496_1 = (((stage_v_251_1 * 3) + pub_r001343_3_1) + 7) & 127;
  int stage_v_496_2 = (((stage_v_251_2 * 3) + pub_r001343_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_496_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_496_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_496_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_496_2 * 2)) & 255;
  int stage_v_497_1 = (((stage_v_391_1 * 3) + pub_r001343_7_1) + 26) & 127;
  int stage_v_497_2 = (((stage_v_391_2 * 3) + pub_r001343_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_497_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_497_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_497_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_497_2 * 2)) & 255;
  int stage_v_498_1 = (((stage_v_156_1 * 3) + pub_r001343_10_1) + 27) & 127;
  int stage_v_498_2 = (((stage_v_156_2 * 3) + pub_r001343_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_498_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_498_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_498_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_498_2 * 2)) & 255;
  int stage_v_499_1 = ((pub_r001343_7_1 * 2) + 6) & 63;
  int stage_v_499_2 = ((pub_r001343_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_499_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_499_2) & 127;
  int stage_v_500_1 = (((stage_v_149_1 * 3) + pub_r001343_19_1) + 14) & 127;
  int stage_v_500_2 = (((stage_v_149_2 * 3) + pub_r001343_19_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_500_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_500_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_500_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_500_2 * 2)) & 255;
  int stage_v_501_1 = (((stage_v_483_1 * 3) + pub_r001343_18_1) + 27) & 127;
  int stage_v_501_2 = (((stage_v_483_2 * 3) + pub_r001343_18_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_501_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_501_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_501_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_501_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001343_5_1 != sec_r001343_5_2);
  __CPROVER_assume(sec_r001343_3_1 != sec_r001343_3_2);
  __CPROVER_assume(sec_r001343_6_1 != sec_r001343_6_2);
  __CPROVER_assume(sec_r001343_7_1 != sec_r001343_7_2);
  __CPROVER_assume(pub_r001343_12_1 == pub_r001343_12_2);
  __CPROVER_assume(sec_r001343_12_1 != sec_r001343_12_2);
  __CPROVER_assume(sec_r001343_10_1 != sec_r001343_10_2);
  __CPROVER_assume(pub_r001343_17_1 == pub_r001343_17_2);
  __CPROVER_assume(sec_r001343_1_1 != sec_r001343_1_2);
  __CPROVER_assume(pub_r001343_2_1 == pub_r001343_2_2);
  __CPROVER_assume(pub_r001343_7_1 == pub_r001343_7_2);
  __CPROVER_assume(pub_r001343_11_1 == pub_r001343_11_2);
  __CPROVER_assume(pub_r001343_20_1 == pub_r001343_20_2);
  __CPROVER_assume(pub_r001343_18_1 == pub_r001343_18_2);
  __CPROVER_assume(sec_r001343_13_1 != sec_r001343_13_2);
  __CPROVER_assume(sec_r001343_17_1 != sec_r001343_17_2);
  __CPROVER_assume(pub_r001343_0_1 == pub_r001343_0_2);
  __CPROVER_assume(sec_r001343_20_1 != sec_r001343_20_2);
  __CPROVER_assume(sec_r001343_11_1 != sec_r001343_11_2);
  __CPROVER_assume(pub_r001343_16_1 == pub_r001343_16_2);
  __CPROVER_assume(pub_r001343_6_1 == pub_r001343_6_2);
  __CPROVER_assume(pub_r001343_4_1 == pub_r001343_4_2);
  __CPROVER_assume(pub_r001343_15_1 == pub_r001343_15_2);
  __CPROVER_assume(sec_r001343_2_1 != sec_r001343_2_2);
  __CPROVER_assume(sec_r001343_4_1 != sec_r001343_4_2);
  __CPROVER_assume(pub_r001343_8_1 == pub_r001343_8_2);
  __CPROVER_assume(pub_r001343_14_1 == pub_r001343_14_2);
  __CPROVER_assume(pub_r001343_1_1 == pub_r001343_1_2);
  __CPROVER_assume(pub_r001343_9_1 == pub_r001343_9_2);
  __CPROVER_assume(sec_r001343_0_1 != sec_r001343_0_2);
  __CPROVER_assume(sec_r001343_22_1 != sec_r001343_22_2);
  __CPROVER_assume(sec_r001343_9_1 != sec_r001343_9_2);
  __CPROVER_assume(sec_r001343_8_1 != sec_r001343_8_2);
  __CPROVER_assume(pub_r001343_10_1 == pub_r001343_10_2);
  __CPROVER_assume(pub_r001343_21_1 == pub_r001343_21_2);
  __CPROVER_assume(pub_r001343_22_1 == pub_r001343_22_2);
  __CPROVER_assume(pub_r001343_13_1 == pub_r001343_13_2);
  __CPROVER_assume(sec_r001343_15_1 != sec_r001343_15_2);
  __CPROVER_assume(sec_r001343_21_1 != sec_r001343_21_2);
  __CPROVER_assume(pub_r001343_19_1 == pub_r001343_19_2);
  __CPROVER_assume(pub_r001343_5_1 == pub_r001343_5_2);
  __CPROVER_assume(sec_r001343_19_1 != sec_r001343_19_2);
  __CPROVER_assume(pub_r001343_3_1 == pub_r001343_3_2);
  __CPROVER_assume(sec_r001343_16_1 != sec_r001343_16_2);
  __CPROVER_assume(sec_r001343_14_1 != sec_r001343_14_2);
  __CPROVER_assume(sec_r001343_18_1 != sec_r001343_18_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.calib == st_var_2_2.calib);
  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.reading == st_var_2_2.reading);
  assert(st_var_2_1.gain == st_var_2_2.gain);
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
  assert(stage_v_446_1 == stage_v_446_2);
  assert(stage_v_447_1 == stage_v_447_2);
  assert(stage_v_448_1 == stage_v_448_2);
  assert(stage_v_449_1 == stage_v_449_2);
  assert(stage_v_450_1 == stage_v_450_2);
  assert(stage_v_451_1 == stage_v_451_2);
  assert(stage_v_452_1 == stage_v_452_2);
  assert(stage_v_453_1 == stage_v_453_2);
  assert(stage_v_454_1 == stage_v_454_2);
  assert(stage_v_455_1 == stage_v_455_2);
  assert(stage_v_456_1 == stage_v_456_2);
  assert(stage_v_457_1 == stage_v_457_2);
  assert(stage_v_458_1 == stage_v_458_2);
  assert(stage_v_459_1 == stage_v_459_2);
  assert(stage_v_460_1 == stage_v_460_2);
  assert(stage_v_461_1 == stage_v_461_2);
  assert(stage_v_462_1 == stage_v_462_2);
  assert(stage_v_463_1 == stage_v_463_2);
  assert(stage_v_464_1 == stage_v_464_2);
  assert(stage_v_465_1 == stage_v_465_2);
  assert(stage_v_466_1 == stage_v_466_2);
  assert(stage_v_467_1 == stage_v_467_2);
  assert(stage_v_468_1 == stage_v_468_2);
  assert(stage_v_469_1 == stage_v_469_2);
  assert(stage_v_470_1 == stage_v_470_2);
  assert(stage_v_471_1 == stage_v_471_2);
  assert(stage_v_472_1 == stage_v_472_2);
  assert(stage_v_473_1 == stage_v_473_2);
  assert(stage_v_474_1 == stage_v_474_2);
  assert(stage_v_475_1 == stage_v_475_2);
  assert(stage_v_476_1 == stage_v_476_2);
  assert(stage_v_477_1 == stage_v_477_2);
  assert(stage_v_478_1 == stage_v_478_2);
  assert(stage_v_479_1 == stage_v_479_2);
  assert(stage_v_480_1 == stage_v_480_2);
  assert(stage_v_481_1 == stage_v_481_2);
  assert(stage_v_482_1 == stage_v_482_2);
  assert(stage_v_483_1 == stage_v_483_2);
  assert(stage_v_484_1 == stage_v_484_2);
  assert(stage_v_485_1 == stage_v_485_2);
  assert(stage_v_486_1 == stage_v_486_2);
  assert(stage_v_487_1 == stage_v_487_2);
  assert(stage_v_488_1 == stage_v_488_2);
  assert(stage_v_489_1 == stage_v_489_2);
  assert(stage_v_490_1 == stage_v_490_2);
  assert(stage_v_491_1 == stage_v_491_2);
  assert(stage_v_492_1 == stage_v_492_2);
  assert(stage_v_493_1 == stage_v_493_2);
  assert(stage_v_494_1 == stage_v_494_2);
  assert(stage_v_495_1 == stage_v_495_2);
  assert(stage_v_496_1 == stage_v_496_2);
  assert(stage_v_497_1 == stage_v_497_2);
  assert(stage_v_498_1 == stage_v_498_2);
  assert(stage_v_499_1 == stage_v_499_2);
  assert(stage_v_500_1 == stage_v_500_2);
  assert(stage_v_501_1 == stage_v_501_2);
}


