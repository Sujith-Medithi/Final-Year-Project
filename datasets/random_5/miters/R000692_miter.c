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
struct DeviceConfig_R000692_9213_0
{
  int port;
  unsigned char id;
  int baud_rate;
  short parity;
  int timeout;
  int stop_bits;
  int buffer[3];
};
struct Vector3D_R000692_9213_1
{
  unsigned char pitch;
  int coord_z;
  int norm_sq;
  int coord_y;
  int buffer[3];
};
union TelemetryField_R000692_9213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000692_9213_1
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
void fn_R000692_9213_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st_1 = {0};
  struct DeviceConfig_R000692_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int stride_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_72_1)
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

  switch (stride_72_2)
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

  int quotient_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_50_1 > 27)
  {
    acc_1 = ((acc_1 + (quotient_50_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_50_2 > 27)
  {
    acc_2 = ((acc_2 + (quotient_50_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_50_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_72_1 == stride_72_2);
  assert(quotient_50_1 == quotient_50_2);
}

int fn_R000692_9213_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int stride_72 = (aux + st.buffer[1]) & 3;
  switch (stride_72)
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

  int quotient_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_50 > 27)
  {
    acc = ((acc + (quotient_50 * 2)) + 5) & 127;
    aux ^= quotient_50 & 15;
  }
  else
  {
    acc = ((acc - quotient_50) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000692_9213_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st_1 = {0};
  struct DeviceConfig_R000692_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int checksum_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_37_1 > 28)
  {
    acc_1 = ((acc_1 + (checksum_37_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_37_2 > 28)
  {
    acc_2 = ((acc_2 + (checksum_37_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_37_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_77_1)
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

  switch (bound_77_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_37_1 == checksum_37_2);
  assert(bound_77_1 == bound_77_2);
}

int fn_R000692_9213_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int checksum_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_37 > 28)
  {
    acc = ((acc + (checksum_37 * 2)) + 5) & 127;
    aux ^= checksum_37 & 15;
  }
  else
  {
    acc = ((acc - checksum_37) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_77 = (aux + st.buffer[1]) & 3;
  switch (bound_77)
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

void fn_R000692_9213_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st_1 = {0};
  struct Vector3D_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int quantum_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_24_1 > 16)
  {
    acc_1 = ((acc_1 + (quantum_24_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_24_2 > 16)
  {
    acc_2 = ((acc_2 + (quantum_24_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_19_1)
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

  switch (pivot_19_2)
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
  int index_reg_23_1 = local_arr_1[aux_1 % 3];
  int index_reg_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_23_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_24_1 == quantum_24_2);
  assert(pivot_19_1 == pivot_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_23_1 == index_reg_23_2);
}

int fn_R000692_9213_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int quantum_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_24 > 16)
  {
    acc = ((acc + (quantum_24 * 2)) + 5) & 127;
    aux ^= quantum_24 & 15;
  }
  else
  {
    acc = ((acc - quantum_24) + 11) & 127;
    aux += 3;
  }
  int pivot_19 = (aux + st.buffer[1]) & 3;
  switch (pivot_19)
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
  int index_reg_23 = local_arr[aux % 3];
  acc = (acc + (index_reg_23 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000692_9213_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st_1 = {0};
  struct Vector3D_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int index_reg_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_87_1) & 63;
  aux_2 = (aux_2 + index_reg_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_28_1)
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

  switch (delta_28_2)
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
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_87_1 == index_reg_87_2);
  assert(delta_28_1 == delta_28_2);
}

int fn_R000692_9213_3(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int index_reg_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_87) & 63;
  acc ^= aux;
  int delta_28 = (aux + st.buffer[1]) & 3;
  switch (delta_28)
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

void fn_R000692_9213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st_1 = {0};
  struct Vector3D_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int margin_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_83_1)
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

  switch (margin_83_2)
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

  int margin_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_60_1 > 26)
  {
    acc_1 = ((acc_1 + (margin_60_1 * 2)) + 5) & 127;
    aux_1 ^= margin_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_60_2 > 26)
  {
    acc_2 = ((acc_2 + (margin_60_2 * 2)) + 5) & 127;
    aux_2 ^= margin_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_60_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_83_1 == margin_83_2);
  assert(margin_60_1 == margin_60_2);
}

int fn_R000692_9213_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int margin_83 = (aux + st.buffer[1]) & 3;
  switch (margin_83)
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

  int margin_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_60 > 26)
  {
    acc = ((acc + (margin_60 * 2)) + 5) & 127;
    aux ^= margin_60 & 15;
  }
  else
  {
    acc = ((acc - margin_60) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000692_9213_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st_1 = {0};
  struct Vector3D_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int stride_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_13_1)
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

  switch (stride_13_2)
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
  int sample_29_1 = local_arr_1[aux_1 % 3];
  int sample_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_29_2 * 2)) & 127;
  int tracker_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_32_1 > 21)
  {
    acc_1 = ((acc_1 + (tracker_32_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_32_2 > 21)
  {
    acc_2 = ((acc_2 + (tracker_32_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_32_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_13_1 == stride_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_29_1 == sample_29_2);
  assert(tracker_32_1 == tracker_32_2);
}

int fn_R000692_9213_5(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int stride_13 = (aux + st.buffer[1]) & 3;
  switch (stride_13)
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
  int sample_29 = local_arr[aux % 3];
  acc = (acc + (sample_29 * 2)) & 127;
  int tracker_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_32 > 21)
  {
    acc = ((acc + (tracker_32 * 2)) + 5) & 127;
    aux ^= tracker_32 & 15;
  }
  else
  {
    acc = ((acc - tracker_32) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000692_9213_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st_1 = {0};
  struct DeviceConfig_R000692_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_71_1 = local_arr_1[aux_1 % 3];
  int damping_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_71_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_43_1)
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

  switch (checksum_43_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
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

  assert(damping_71_1 == damping_71_2);
  assert(checksum_43_1 == checksum_43_2);
}

int fn_R000692_9213_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int damping_71 = local_arr[aux % 3];
  acc = (acc + (damping_71 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_43 = (aux + st.buffer[1]) & 3;
  switch (checksum_43)
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

void fn_R000692_9213_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st_1 = {0};
  struct DeviceConfig_R000692_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_80_1) & 63;
  aux_2 = (aux_2 + window_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_33_1 > 44)
  {
    acc_1 = ((acc_1 + (stride_33_1 * 2)) + 5) & 127;
    aux_1 ^= stride_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_33_2 > 44)
  {
    acc_2 = ((acc_2 + (stride_33_2 * 2)) + 5) & 127;
    aux_2 ^= stride_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_80_1 == window_80_2);
  assert(stride_33_1 == stride_33_2);
}

int fn_R000692_9213_7(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_80) & 63;
  acc ^= aux;
  int stride_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_33 > 44)
  {
    acc = ((acc + (stride_33 * 2)) + 5) & 127;
    aux ^= stride_33 & 15;
  }
  else
  {
    acc = ((acc - stride_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000692_9213_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st_1 = {0};
  struct Vector3D_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_30_1)
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

  switch (stride_30_2)
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

  int window_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_98_1 > 17)
  {
    acc_1 = ((acc_1 + (window_98_1 * 2)) + 5) & 127;
    aux_1 ^= window_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_98_2 > 17)
  {
    acc_2 = ((acc_2 + (window_98_2 * 2)) + 5) & 127;
    aux_2 ^= window_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_99_1) & 63;
  aux_2 = (aux_2 + bound_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_30_1 == stride_30_2);
  assert(window_98_1 == window_98_2);
  assert(bound_99_1 == bound_99_2);
}

int fn_R000692_9213_8(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_30 = (aux + st.buffer[1]) & 3;
  switch (stride_30)
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

  int window_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_98 > 17)
  {
    acc = ((acc + (window_98 * 2)) + 5) & 127;
    aux ^= window_98 & 15;
  }
  else
  {
    acc = ((acc - window_98) + 11) & 127;
    aux += 3;
  }
  int bound_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000692_9213_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st_1 = {0};
  struct Vector3D_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int accumulator_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_65_1) & 63;
  aux_2 = (aux_2 + accumulator_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_42_1)
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

  switch (stride_42_2)
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
  int quantum_50_1 = local_arr_1[aux_1 % 3];
  int quantum_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_50_2 * 2)) & 127;
  int quantum_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_48_1 > 42)
  {
    acc_1 = ((acc_1 + (quantum_48_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_48_2 > 42)
  {
    acc_2 = ((acc_2 + (quantum_48_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_48_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_65_1 == accumulator_65_2);
  assert(stride_42_1 == stride_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_50_1 == quantum_50_2);
  assert(quantum_48_1 == quantum_48_2);
}

int fn_R000692_9213_9(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int accumulator_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_65) & 63;
  acc ^= aux;
  int stride_42 = (aux + st.buffer[1]) & 3;
  switch (stride_42)
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
  int quantum_50 = local_arr[aux % 3];
  acc = (acc + (quantum_50 * 2)) & 127;
  int quantum_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_48 > 42)
  {
    acc = ((acc + (quantum_48 * 2)) + 5) & 127;
    aux ^= quantum_48 & 15;
  }
  else
  {
    acc = ((acc - quantum_48) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000692_9213_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st_1 = {0};
  struct Vector3D_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int cursor_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_32_1 > 39)
  {
    acc_1 = ((acc_1 + (cursor_32_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_32_2 > 39)
  {
    acc_2 = ((acc_2 + (cursor_32_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_86_1)
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

  switch (scale_86_2)
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
  int residue_74_1 = local_arr_1[aux_1 % 3];
  int residue_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_74_2 * 2)) & 127;
  int tally_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_26_1) & 63;
  aux_2 = (aux_2 + tally_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_32_1 == cursor_32_2);
  assert(scale_86_1 == scale_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_74_1 == residue_74_2);
  assert(tally_26_1 == tally_26_2);
}

int fn_R000692_9213_10(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int cursor_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_32 > 39)
  {
    acc = ((acc + (cursor_32 * 2)) + 5) & 127;
    aux ^= cursor_32 & 15;
  }
  else
  {
    acc = ((acc - cursor_32) + 11) & 127;
    aux += 3;
  }
  int scale_86 = (aux + st.buffer[1]) & 3;
  switch (scale_86)
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
  int residue_74 = local_arr[aux % 3];
  acc = (acc + (residue_74 * 2)) & 127;
  int tally_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_26) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000692_9213_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st_1 = {0};
  struct Vector3D_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_88_1 = local_arr_1[aux_1 % 3];
  int factor_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_88_2 * 2)) & 127;
  int tally_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_85_1) & 63;
  aux_2 = (aux_2 + tally_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_88_1 == factor_88_2);
  assert(tally_85_1 == tally_85_2);
}

int fn_R000692_9213_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int factor_88 = local_arr[aux % 3];
  acc = (acc + (factor_88 * 2)) & 127;
  int tally_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_85) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000692_9213_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st_1 = {0};
  struct Vector3D_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int offset_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_70_1)
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

  switch (offset_70_2)
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
  int parity_19_1 = local_arr_1[aux_1 % 3];
  int parity_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_19_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_70_1 == offset_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_19_1 == parity_19_2);
}

int fn_R000692_9213_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int offset_70 = (aux + st.buffer[1]) & 3;
  switch (offset_70)
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
  int parity_19 = local_arr[aux % 3];
  acc = (acc + (parity_19 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000692_9213_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st_1 = {0};
  struct Vector3D_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int window_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_62_1) & 63;
  aux_2 = (aux_2 + window_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_92_1)
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

  switch (stride_92_2)
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
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_62_1 == window_62_2);
  assert(stride_92_1 == stride_92_2);
}

int fn_R000692_9213_13(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int window_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_62) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_92 = (aux + st.buffer[1]) & 3;
  switch (stride_92)
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

void fn_R000692_9213_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st_1 = {0};
  struct DeviceConfig_R000692_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_37_1 = local_arr_1[aux_1 % 3];
  int sample_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_37_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_60_1) & 63;
  aux_2 = (aux_2 + vector_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
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

  assert(sample_37_1 == sample_37_2);
  assert(vector_60_1 == vector_60_2);
}

int fn_R000692_9213_14(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int sample_37 = local_arr[aux % 3];
  acc = (acc + (sample_37 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_60) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000692_9213_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st_1 = {0};
  struct Vector3D_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int accumulator_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_15_1) & 63;
  aux_2 = (aux_2 + accumulator_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_85_1 = local_arr_1[aux_1 % 3];
  int stride_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_85_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_12_1 > 43)
  {
    acc_1 = ((acc_1 + (phase_12_1 * 2)) + 5) & 127;
    aux_1 ^= phase_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_12_2 > 43)
  {
    acc_2 = ((acc_2 + (phase_12_2 * 2)) + 5) & 127;
    aux_2 ^= phase_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_15_1 == accumulator_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_85_1 == stride_85_2);
  assert(phase_12_1 == phase_12_2);
}

int fn_R000692_9213_15(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int accumulator_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_15) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_85 = local_arr[aux % 3];
  acc = (acc + (stride_85 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_12 > 43)
  {
    acc = ((acc + (phase_12 * 2)) + 5) & 127;
    aux ^= phase_12 & 15;
  }
  else
  {
    acc = ((acc - phase_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000692_9213_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st_1 = {0};
  struct DeviceConfig_R000692_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_32_1) & 63;
  aux_2 = (aux_2 + factor_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_32_1 == factor_32_2);
}

int fn_R000692_9213_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_32) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000692_9213_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st_1 = {0};
  struct DeviceConfig_R000692_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_65_1) & 63;
  aux_2 = (aux_2 + factor_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_34_1 = local_arr_1[aux_1 % 3];
  int segment_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_34_2 * 2)) & 127;
  int stride_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_14_1 > 21)
  {
    acc_1 = ((acc_1 + (stride_14_1 * 2)) + 5) & 127;
    aux_1 ^= stride_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_14_2 > 21)
  {
    acc_2 = ((acc_2 + (stride_14_2 * 2)) + 5) & 127;
    aux_2 ^= stride_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_14_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_65_1 == factor_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_34_1 == segment_34_2);
  assert(stride_14_1 == stride_14_2);
}

int fn_R000692_9213_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_65) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_34 = local_arr[aux % 3];
  acc = (acc + (segment_34 * 2)) & 127;
  int stride_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_14 > 21)
  {
    acc = ((acc + (stride_14 * 2)) + 5) & 127;
    aux ^= stride_14 & 15;
  }
  else
  {
    acc = ((acc - stride_14) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000692_9213_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st_1 = {0};
  struct DeviceConfig_R000692_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int quantum_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_28_1 > 26)
  {
    acc_1 = ((acc_1 + (quantum_28_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_28_2 > 26)
  {
    acc_2 = ((acc_2 + (quantum_28_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_28_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_79_1)
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

  switch (metric_79_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_28_1 == quantum_28_2);
  assert(metric_79_1 == metric_79_2);
}

int fn_R000692_9213_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000692_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int quantum_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_28 > 26)
  {
    acc = ((acc + (quantum_28 * 2)) + 5) & 127;
    aux ^= quantum_28 & 15;
  }
  else
  {
    acc = ((acc - quantum_28) + 11) & 127;
    aux += 3;
  }
  int metric_79 = (aux + st.buffer[1]) & 3;
  switch (metric_79)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000692_9213_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st_1 = {0};
  struct Vector3D_R000692_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int anchor_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_56_1 > 20)
  {
    acc_1 = ((acc_1 + (anchor_56_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_56_2 > 20)
  {
    acc_2 = ((acc_2 + (anchor_56_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_40_1 = local_arr_1[aux_1 % 3];
  int index_reg_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_40_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_56_1 == anchor_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_40_1 == index_reg_40_2);
}

int fn_R000692_9213_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000692_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int anchor_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_56 > 20)
  {
    acc = ((acc + (anchor_56 * 2)) + 5) & 127;
    aux ^= anchor_56 & 15;
  }
  else
  {
    acc = ((acc - anchor_56) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_40 = local_arr[aux % 3];
  acc = (acc + (index_reg_40 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000692_0_1;
  int sec_r000692_0_2;
  int sec_r000692_1_1;
  int sec_r000692_1_2;
  int sec_r000692_2_1;
  int sec_r000692_2_2;
  int sec_r000692_3_1;
  int sec_r000692_3_2;
  int sec_r000692_4_1;
  int sec_r000692_4_2;
  int sec_r000692_5_1;
  int sec_r000692_5_2;
  int sec_r000692_6_1;
  int sec_r000692_6_2;
  int sec_r000692_7_1;
  int sec_r000692_7_2;
  int sec_r000692_8_1;
  int sec_r000692_8_2;
  int sec_r000692_9_1;
  int sec_r000692_9_2;
  int sec_r000692_10_1;
  int sec_r000692_10_2;
  int sec_r000692_11_1;
  int sec_r000692_11_2;
  int sec_r000692_12_1;
  int sec_r000692_12_2;
  int sec_r000692_13_1;
  int sec_r000692_13_2;
  int sec_r000692_14_1;
  int sec_r000692_14_2;
  int sec_r000692_15_1;
  int sec_r000692_15_2;
  int sec_r000692_16_1;
  int sec_r000692_16_2;
  int sec_r000692_17_1;
  int sec_r000692_17_2;
  int pub_r000692_0_1;
  int pub_r000692_0_2;
  int pub_r000692_1_1;
  int pub_r000692_1_2;
  int pub_r000692_2_1;
  int pub_r000692_2_2;
  int pub_r000692_3_1;
  int pub_r000692_3_2;
  int pub_r000692_4_1;
  int pub_r000692_4_2;
  int pub_r000692_5_1;
  int pub_r000692_5_2;
  int pub_r000692_6_1;
  int pub_r000692_6_2;
  int pub_r000692_7_1;
  int pub_r000692_7_2;
  int pub_r000692_8_1;
  int pub_r000692_8_2;
  int pub_r000692_9_1;
  int pub_r000692_9_2;
  int pub_r000692_10_1;
  int pub_r000692_10_2;
  int pub_r000692_11_1;
  int pub_r000692_11_2;
  int pub_r000692_12_1;
  int pub_r000692_12_2;
  int pub_r000692_13_1;
  int pub_r000692_13_2;
  int pub_r000692_14_1;
  int pub_r000692_14_2;
  int pub_r000692_15_1;
  int pub_r000692_15_2;
  int pub_r000692_16_1;
  int pub_r000692_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000692_0_1 >= (-100)) && (pub_r000692_0_1 <= 100));
  __CPROVER_assume((pub_r000692_0_2 >= (-100)) && (pub_r000692_0_2 <= 100));
  __CPROVER_assume((pub_r000692_1_1 >= (-100)) && (pub_r000692_1_1 <= 100));
  __CPROVER_assume((pub_r000692_1_2 >= (-100)) && (pub_r000692_1_2 <= 100));
  __CPROVER_assume((pub_r000692_2_1 >= (-100)) && (pub_r000692_2_1 <= 100));
  __CPROVER_assume((pub_r000692_2_2 >= (-100)) && (pub_r000692_2_2 <= 100));
  __CPROVER_assume((pub_r000692_3_1 >= (-100)) && (pub_r000692_3_1 <= 100));
  __CPROVER_assume((pub_r000692_3_2 >= (-100)) && (pub_r000692_3_2 <= 100));
  __CPROVER_assume((pub_r000692_4_1 >= (-100)) && (pub_r000692_4_1 <= 100));
  __CPROVER_assume((pub_r000692_4_2 >= (-100)) && (pub_r000692_4_2 <= 100));
  __CPROVER_assume((pub_r000692_5_1 >= (-100)) && (pub_r000692_5_1 <= 100));
  __CPROVER_assume((pub_r000692_5_2 >= (-100)) && (pub_r000692_5_2 <= 100));
  __CPROVER_assume((pub_r000692_6_1 >= (-100)) && (pub_r000692_6_1 <= 100));
  __CPROVER_assume((pub_r000692_6_2 >= (-100)) && (pub_r000692_6_2 <= 100));
  __CPROVER_assume((pub_r000692_7_1 >= (-100)) && (pub_r000692_7_1 <= 100));
  __CPROVER_assume((pub_r000692_7_2 >= (-100)) && (pub_r000692_7_2 <= 100));
  __CPROVER_assume((pub_r000692_8_1 >= (-100)) && (pub_r000692_8_1 <= 100));
  __CPROVER_assume((pub_r000692_8_2 >= (-100)) && (pub_r000692_8_2 <= 100));
  __CPROVER_assume((pub_r000692_9_1 >= (-100)) && (pub_r000692_9_1 <= 100));
  __CPROVER_assume((pub_r000692_9_2 >= (-100)) && (pub_r000692_9_2 <= 100));
  __CPROVER_assume((pub_r000692_10_1 >= (-100)) && (pub_r000692_10_1 <= 100));
  __CPROVER_assume((pub_r000692_10_2 >= (-100)) && (pub_r000692_10_2 <= 100));
  __CPROVER_assume((pub_r000692_11_1 >= (-100)) && (pub_r000692_11_1 <= 100));
  __CPROVER_assume((pub_r000692_11_2 >= (-100)) && (pub_r000692_11_2 <= 100));
  __CPROVER_assume((pub_r000692_12_1 >= (-100)) && (pub_r000692_12_1 <= 100));
  __CPROVER_assume((pub_r000692_12_2 >= (-100)) && (pub_r000692_12_2 <= 100));
  __CPROVER_assume((pub_r000692_13_1 >= (-100)) && (pub_r000692_13_1 <= 100));
  __CPROVER_assume((pub_r000692_13_2 >= (-100)) && (pub_r000692_13_2 <= 100));
  __CPROVER_assume((pub_r000692_14_1 >= (-100)) && (pub_r000692_14_1 <= 100));
  __CPROVER_assume((pub_r000692_14_2 >= (-100)) && (pub_r000692_14_2 <= 100));
  __CPROVER_assume((pub_r000692_15_1 >= (-100)) && (pub_r000692_15_1 <= 100));
  __CPROVER_assume((pub_r000692_15_2 >= (-100)) && (pub_r000692_15_2 <= 100));
  __CPROVER_assume((pub_r000692_16_1 >= (-100)) && (pub_r000692_16_1 <= 100));
  __CPROVER_assume((pub_r000692_16_2 >= (-100)) && (pub_r000692_16_2 <= 100));
  __CPROVER_assume((sec_r000692_0_1 >= 0) && (sec_r000692_0_1 <= 255));
  __CPROVER_assume((sec_r000692_0_2 >= 0) && (sec_r000692_0_2 <= 255));
  __CPROVER_assume((sec_r000692_1_1 >= 0) && (sec_r000692_1_1 <= 255));
  __CPROVER_assume((sec_r000692_1_2 >= 0) && (sec_r000692_1_2 <= 255));
  __CPROVER_assume((sec_r000692_2_1 >= 0) && (sec_r000692_2_1 <= 255));
  __CPROVER_assume((sec_r000692_2_2 >= 0) && (sec_r000692_2_2 <= 255));
  __CPROVER_assume((sec_r000692_3_1 >= 0) && (sec_r000692_3_1 <= 255));
  __CPROVER_assume((sec_r000692_3_2 >= 0) && (sec_r000692_3_2 <= 255));
  __CPROVER_assume((sec_r000692_4_1 >= 0) && (sec_r000692_4_1 <= 255));
  __CPROVER_assume((sec_r000692_4_2 >= 0) && (sec_r000692_4_2 <= 255));
  __CPROVER_assume((sec_r000692_5_1 >= 0) && (sec_r000692_5_1 <= 255));
  __CPROVER_assume((sec_r000692_5_2 >= 0) && (sec_r000692_5_2 <= 255));
  __CPROVER_assume((sec_r000692_6_1 >= 0) && (sec_r000692_6_1 <= 255));
  __CPROVER_assume((sec_r000692_6_2 >= 0) && (sec_r000692_6_2 <= 255));
  __CPROVER_assume((sec_r000692_7_1 >= 0) && (sec_r000692_7_1 <= 255));
  __CPROVER_assume((sec_r000692_7_2 >= 0) && (sec_r000692_7_2 <= 255));
  __CPROVER_assume((sec_r000692_8_1 >= 0) && (sec_r000692_8_1 <= 255));
  __CPROVER_assume((sec_r000692_8_2 >= 0) && (sec_r000692_8_2 <= 255));
  __CPROVER_assume((sec_r000692_9_1 >= 0) && (sec_r000692_9_1 <= 255));
  __CPROVER_assume((sec_r000692_9_2 >= 0) && (sec_r000692_9_2 <= 255));
  __CPROVER_assume((sec_r000692_10_1 >= 0) && (sec_r000692_10_1 <= 255));
  __CPROVER_assume((sec_r000692_10_2 >= 0) && (sec_r000692_10_2 <= 255));
  __CPROVER_assume((sec_r000692_11_1 >= 0) && (sec_r000692_11_1 <= 255));
  __CPROVER_assume((sec_r000692_11_2 >= 0) && (sec_r000692_11_2 <= 255));
  __CPROVER_assume((sec_r000692_12_1 >= 0) && (sec_r000692_12_1 <= 255));
  __CPROVER_assume((sec_r000692_12_2 >= 0) && (sec_r000692_12_2 <= 255));
  __CPROVER_assume((sec_r000692_13_1 >= 0) && (sec_r000692_13_1 <= 255));
  __CPROVER_assume((sec_r000692_13_2 >= 0) && (sec_r000692_13_2 <= 255));
  __CPROVER_assume((sec_r000692_14_1 >= 0) && (sec_r000692_14_1 <= 255));
  __CPROVER_assume((sec_r000692_14_2 >= 0) && (sec_r000692_14_2 <= 255));
  __CPROVER_assume((sec_r000692_15_1 >= 0) && (sec_r000692_15_1 <= 255));
  __CPROVER_assume((sec_r000692_15_2 >= 0) && (sec_r000692_15_2 <= 255));
  __CPROVER_assume((sec_r000692_16_1 >= 0) && (sec_r000692_16_1 <= 255));
  __CPROVER_assume((sec_r000692_16_2 >= 0) && (sec_r000692_16_2 <= 255));
  __CPROVER_assume((sec_r000692_17_1 >= 0) && (sec_r000692_17_1 <= 255));
  __CPROVER_assume((sec_r000692_17_2 >= 0) && (sec_r000692_17_2 <= 255));
  struct DeviceConfig_R000692_9213_0 st_var_0_1 = {0};
  struct DeviceConfig_R000692_9213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000692_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000692_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000692_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000692_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000692_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000692_0_2 + 7) & 15;
  struct Vector3D_R000692_9213_1 st_var_1_1 = {0};
  struct Vector3D_R000692_9213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000692_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000692_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000692_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000692_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000692_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000692_0_2 + 9) & 15;
  union TelemetryField_R000692_9213_0 u_var_1;
  union TelemetryField_R000692_9213_0 u_var_2;
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
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 4) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 7) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = ((st_var_1_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_1_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 26)
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
  if (stage_v_7_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 26)
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
  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_11_1 = ((st_var_1_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_1_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 43)
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
  if (stage_v_11_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 43)
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
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 35)
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
  if (stage_v_12_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 35)
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
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 15) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 16) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = ((st_var_1_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_1_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 35)
    {
      chk_sum_1 ^= stage_v_17_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_17_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 35)
    {
      chk_sum_2 ^= stage_v_17_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 20) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 20) & 15;
  int stage_v_19_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_19_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= stage_v_19_1;
  chk_sum_2 ^= stage_v_19_2;
  int stage_v_20_1 = ((sec_r000692_10_1 + pub_r000692_13_1) + 38) & 127;
  int stage_v_20_2 = ((sec_r000692_10_2 + pub_r000692_13_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((sec_r000692_16_1 + pub_r000692_16_1) + 8) & 127;
  int stage_v_21_2 = ((sec_r000692_16_2 + pub_r000692_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((stage_v_21_1 + pub_r000692_0_1) + 7) & 127;
  int stage_v_22_2 = ((stage_v_21_2 + pub_r000692_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((sec_r000692_4_1 + pub_r000692_0_1) + 34) & 127;
  int stage_v_23_2 = ((sec_r000692_4_2 + pub_r000692_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = ((stage_v_20_1 + pub_r000692_9_1) + 17) & 127;
  int stage_v_24_2 = ((stage_v_20_2 + pub_r000692_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((sec_r000692_16_1 + pub_r000692_11_1) + 20) & 127;
  int stage_v_25_2 = ((sec_r000692_16_2 + pub_r000692_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((stage_v_22_1 + pub_r000692_8_1) + 5) & 127;
  int stage_v_26_2 = ((stage_v_22_2 + pub_r000692_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((stage_v_21_1 + pub_r000692_10_1) + 27) & 127;
  int stage_v_27_2 = ((stage_v_21_2 + pub_r000692_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((stage_v_21_1 + pub_r000692_5_1) + 40) & 127;
  int stage_v_28_2 = ((stage_v_21_2 + pub_r000692_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((stage_v_20_1 + pub_r000692_7_1) + 39) & 127;
  int stage_v_29_2 = ((stage_v_20_2 + pub_r000692_7_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((stage_v_24_1 + pub_r000692_4_1) + 47) & 127;
  int stage_v_30_2 = ((stage_v_24_2 + pub_r000692_4_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((sec_r000692_2_1 + pub_r000692_12_1) + 48) & 127;
  int stage_v_31_2 = ((sec_r000692_2_2 + pub_r000692_12_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((stage_v_22_1 + pub_r000692_5_1) + 39) & 127;
  int stage_v_32_2 = ((stage_v_22_2 + pub_r000692_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((sec_r000692_11_1 + pub_r000692_8_1) + 27) & 127;
  int stage_v_33_2 = ((sec_r000692_11_2 + pub_r000692_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = ((stage_v_33_1 + pub_r000692_8_1) + 4) & 127;
  int stage_v_34_2 = ((stage_v_33_2 + pub_r000692_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((stage_v_26_1 + pub_r000692_14_1) + 33) & 127;
  int stage_v_35_2 = ((stage_v_26_2 + pub_r000692_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((sec_r000692_4_1 + pub_r000692_4_1) + 49) & 127;
  int stage_v_36_2 = ((sec_r000692_4_2 + pub_r000692_4_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((stage_v_25_1 + pub_r000692_15_1) + 30) & 127;
  int stage_v_37_2 = ((stage_v_25_2 + pub_r000692_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((stage_v_22_1 + pub_r000692_2_1) + 21) & 127;
  int stage_v_38_2 = ((stage_v_22_2 + pub_r000692_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((sec_r000692_10_1 + pub_r000692_10_1) + 30) & 127;
  int stage_v_39_2 = ((sec_r000692_10_2 + pub_r000692_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((sec_r000692_7_1 + pub_r000692_3_1) + 46) & 127;
  int stage_v_40_2 = ((sec_r000692_7_2 + pub_r000692_3_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((stage_v_38_1 + pub_r000692_0_1) + 32) & 127;
  int stage_v_41_2 = ((stage_v_38_2 + pub_r000692_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((stage_v_32_1 + pub_r000692_4_1) + 3) & 127;
  int stage_v_42_2 = ((stage_v_32_2 + pub_r000692_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((stage_v_39_1 + pub_r000692_16_1) + 49) & 127;
  int stage_v_43_2 = ((stage_v_39_2 + pub_r000692_16_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((sec_r000692_5_1 + pub_r000692_6_1) + 26) & 127;
  int stage_v_44_2 = ((sec_r000692_5_2 + pub_r000692_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((sec_r000692_9_1 + pub_r000692_1_1) + 7) & 127;
  int stage_v_45_2 = ((sec_r000692_9_2 + pub_r000692_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((stage_v_39_1 + pub_r000692_15_1) + 6) & 127;
  int stage_v_46_2 = ((stage_v_39_2 + pub_r000692_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((stage_v_46_1 + pub_r000692_8_1) + 39) & 127;
  int stage_v_47_2 = ((stage_v_46_2 + pub_r000692_8_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((stage_v_47_1 + pub_r000692_13_1) + 29) & 127;
  int stage_v_48_2 = ((stage_v_47_2 + pub_r000692_13_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((sec_r000692_10_1 + pub_r000692_4_1) + 19) & 127;
  int stage_v_49_2 = ((sec_r000692_10_2 + pub_r000692_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((stage_v_29_1 + pub_r000692_7_1) + 18) & 127;
  int stage_v_50_2 = ((stage_v_29_2 + pub_r000692_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((stage_v_23_1 + pub_r000692_1_1) + 36) & 127;
  int stage_v_51_2 = ((stage_v_23_2 + pub_r000692_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((stage_v_39_1 + pub_r000692_5_1) + 38) & 127;
  int stage_v_52_2 = ((stage_v_39_2 + pub_r000692_5_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((stage_v_38_1 + pub_r000692_1_1) + 31) & 127;
  int stage_v_53_2 = ((stage_v_38_2 + pub_r000692_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((sec_r000692_12_1 + pub_r000692_11_1) + 17) & 127;
  int stage_v_54_2 = ((sec_r000692_12_2 + pub_r000692_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((sec_r000692_9_1 + pub_r000692_2_1) + 26) & 127;
  int stage_v_55_2 = ((sec_r000692_9_2 + pub_r000692_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((stage_v_34_1 + pub_r000692_13_1) + 42) & 127;
  int stage_v_56_2 = ((stage_v_34_2 + pub_r000692_13_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((stage_v_50_1 + pub_r000692_0_1) + 15) & 127;
  int stage_v_57_2 = ((stage_v_50_2 + pub_r000692_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((stage_v_53_1 + pub_r000692_4_1) + 33) & 127;
  int stage_v_58_2 = ((stage_v_53_2 + pub_r000692_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((stage_v_23_1 + pub_r000692_14_1) + 37) & 127;
  int stage_v_59_2 = ((stage_v_23_2 + pub_r000692_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((stage_v_25_1 + pub_r000692_2_1) + 14) & 127;
  int stage_v_60_2 = ((stage_v_25_2 + pub_r000692_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((stage_v_41_1 + pub_r000692_4_1) + 45) & 127;
  int stage_v_61_2 = ((stage_v_41_2 + pub_r000692_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((sec_r000692_14_1 + pub_r000692_15_1) + 46) & 127;
  int stage_v_62_2 = ((sec_r000692_14_2 + pub_r000692_15_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((stage_v_56_1 + pub_r000692_12_1) + 14) & 127;
  int stage_v_63_2 = ((stage_v_56_2 + pub_r000692_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((stage_v_24_1 + pub_r000692_12_1) + 7) & 127;
  int stage_v_64_2 = ((stage_v_24_2 + pub_r000692_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((stage_v_49_1 + pub_r000692_10_1) + 31) & 127;
  int stage_v_65_2 = ((stage_v_49_2 + pub_r000692_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((stage_v_33_1 + pub_r000692_4_1) + 37) & 127;
  int stage_v_66_2 = ((stage_v_33_2 + pub_r000692_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((stage_v_55_1 + pub_r000692_13_1) + 20) & 127;
  int stage_v_67_2 = ((stage_v_55_2 + pub_r000692_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((sec_r000692_15_1 + pub_r000692_1_1) + 20) & 127;
  int stage_v_68_2 = ((sec_r000692_15_2 + pub_r000692_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((stage_v_62_1 + pub_r000692_10_1) + 40) & 127;
  int stage_v_69_2 = ((stage_v_62_2 + pub_r000692_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((sec_r000692_10_1 + pub_r000692_7_1) + 19) & 127;
  int stage_v_70_2 = ((sec_r000692_10_2 + pub_r000692_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((stage_v_42_1 + pub_r000692_0_1) + 48) & 127;
  int stage_v_71_2 = ((stage_v_42_2 + pub_r000692_0_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((stage_v_49_1 + pub_r000692_4_1) + 49) & 127;
  int stage_v_72_2 = ((stage_v_49_2 + pub_r000692_4_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((sec_r000692_10_1 + pub_r000692_8_1) + 29) & 127;
  int stage_v_73_2 = ((sec_r000692_10_2 + pub_r000692_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((stage_v_25_1 + pub_r000692_7_1) + 26) & 127;
  int stage_v_74_2 = ((stage_v_25_2 + pub_r000692_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((stage_v_43_1 + pub_r000692_14_1) + 17) & 127;
  int stage_v_75_2 = ((stage_v_43_2 + pub_r000692_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((stage_v_32_1 + pub_r000692_15_1) + 48) & 127;
  int stage_v_76_2 = ((stage_v_32_2 + pub_r000692_15_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((stage_v_69_1 + pub_r000692_3_1) + 47) & 127;
  int stage_v_77_2 = ((stage_v_69_2 + pub_r000692_3_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((stage_v_30_1 + pub_r000692_12_1) + 31) & 127;
  int stage_v_78_2 = ((stage_v_30_2 + pub_r000692_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((stage_v_69_1 + pub_r000692_8_1) + 16) & 127;
  int stage_v_79_2 = ((stage_v_69_2 + pub_r000692_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((stage_v_46_1 + pub_r000692_12_1) + 31) & 127;
  int stage_v_80_2 = ((stage_v_46_2 + pub_r000692_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((stage_v_70_1 + pub_r000692_8_1) + 18) & 127;
  int stage_v_81_2 = ((stage_v_70_2 + pub_r000692_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((stage_v_64_1 + pub_r000692_11_1) + 46) & 127;
  int stage_v_82_2 = ((stage_v_64_2 + pub_r000692_11_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((stage_v_60_1 + pub_r000692_7_1) + 30) & 127;
  int stage_v_83_2 = ((stage_v_60_2 + pub_r000692_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((sec_r000692_2_1 + pub_r000692_12_1) + 3) & 127;
  int stage_v_84_2 = ((sec_r000692_2_2 + pub_r000692_12_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((stage_v_61_1 + pub_r000692_0_1) + 30) & 127;
  int stage_v_85_2 = ((stage_v_61_2 + pub_r000692_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((stage_v_49_1 + pub_r000692_11_1) + 22) & 127;
  int stage_v_86_2 = ((stage_v_49_2 + pub_r000692_11_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((stage_v_85_1 + pub_r000692_0_1) + 30) & 127;
  int stage_v_87_2 = ((stage_v_85_2 + pub_r000692_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((sec_r000692_1_1 + pub_r000692_1_1) + 48) & 127;
  int stage_v_88_2 = ((sec_r000692_1_2 + pub_r000692_1_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((sec_r000692_12_1 + pub_r000692_9_1) + 3) & 127;
  int stage_v_89_2 = ((sec_r000692_12_2 + pub_r000692_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((stage_v_78_1 + pub_r000692_9_1) + 36) & 127;
  int stage_v_90_2 = ((stage_v_78_2 + pub_r000692_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((stage_v_43_1 + pub_r000692_14_1) + 20) & 127;
  int stage_v_91_2 = ((stage_v_43_2 + pub_r000692_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((sec_r000692_10_1 + pub_r000692_10_1) + 11) & 127;
  int stage_v_92_2 = ((sec_r000692_10_2 + pub_r000692_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((sec_r000692_4_1 + pub_r000692_4_1) + 40) & 127;
  int stage_v_93_2 = ((sec_r000692_4_2 + pub_r000692_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((sec_r000692_8_1 + pub_r000692_7_1) + 14) & 127;
  int stage_v_94_2 = ((sec_r000692_8_2 + pub_r000692_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((sec_r000692_10_1 + pub_r000692_15_1) + 21) & 127;
  int stage_v_95_2 = ((sec_r000692_10_2 + pub_r000692_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((sec_r000692_10_1 + pub_r000692_15_1) + 22) & 127;
  int stage_v_96_2 = ((sec_r000692_10_2 + pub_r000692_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((stage_v_64_1 + pub_r000692_5_1) + 14) & 127;
  int stage_v_97_2 = ((stage_v_64_2 + pub_r000692_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((sec_r000692_9_1 + pub_r000692_14_1) + 25) & 127;
  int stage_v_98_2 = ((sec_r000692_9_2 + pub_r000692_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((sec_r000692_17_1 + pub_r000692_1_1) + 21) & 127;
  int stage_v_99_2 = ((sec_r000692_17_2 + pub_r000692_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((sec_r000692_7_1 + pub_r000692_12_1) + 30) & 127;
  int stage_v_100_2 = ((sec_r000692_7_2 + pub_r000692_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((sec_r000692_13_1 + pub_r000692_0_1) + 23) & 127;
  int stage_v_101_2 = ((sec_r000692_13_2 + pub_r000692_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((stage_v_82_1 + pub_r000692_3_1) + 11) & 127;
  int stage_v_102_2 = ((stage_v_82_2 + pub_r000692_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((stage_v_89_1 + pub_r000692_6_1) + 15) & 127;
  int stage_v_103_2 = ((stage_v_89_2 + pub_r000692_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((sec_r000692_12_1 + pub_r000692_10_1) + 26) & 127;
  int stage_v_104_2 = ((sec_r000692_12_2 + pub_r000692_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((sec_r000692_7_1 + pub_r000692_13_1) + 23) & 127;
  int stage_v_105_2 = ((sec_r000692_7_2 + pub_r000692_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((stage_v_25_1 + pub_r000692_6_1) + 7) & 127;
  int stage_v_106_2 = ((stage_v_25_2 + pub_r000692_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((sec_r000692_9_1 + pub_r000692_1_1) + 44) & 127;
  int stage_v_107_2 = ((sec_r000692_9_2 + pub_r000692_1_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((stage_v_31_1 + pub_r000692_8_1) + 33) & 127;
  int stage_v_108_2 = ((stage_v_31_2 + pub_r000692_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((stage_v_30_1 + pub_r000692_7_1) + 12) & 127;
  int stage_v_109_2 = ((stage_v_30_2 + pub_r000692_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((stage_v_74_1 + pub_r000692_6_1) + 38) & 127;
  int stage_v_110_2 = ((stage_v_74_2 + pub_r000692_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((stage_v_76_1 + pub_r000692_10_1) + 22) & 127;
  int stage_v_111_2 = ((stage_v_76_2 + pub_r000692_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((sec_r000692_6_1 + pub_r000692_1_1) + 36) & 127;
  int stage_v_112_2 = ((sec_r000692_6_2 + pub_r000692_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((stage_v_88_1 + pub_r000692_14_1) + 6) & 127;
  int stage_v_113_2 = ((stage_v_88_2 + pub_r000692_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((sec_r000692_17_1 + pub_r000692_0_1) + 24) & 127;
  int stage_v_114_2 = ((sec_r000692_17_2 + pub_r000692_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((sec_r000692_3_1 + pub_r000692_1_1) + 6) & 127;
  int stage_v_115_2 = ((sec_r000692_3_2 + pub_r000692_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((stage_v_27_1 + pub_r000692_13_1) + 15) & 127;
  int stage_v_116_2 = ((stage_v_27_2 + pub_r000692_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((stage_v_75_1 + pub_r000692_16_1) + 6) & 127;
  int stage_v_117_2 = ((stage_v_75_2 + pub_r000692_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((sec_r000692_7_1 + pub_r000692_13_1) + 46) & 127;
  int stage_v_118_2 = ((sec_r000692_7_2 + pub_r000692_13_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((stage_v_86_1 + pub_r000692_15_1) + 9) & 127;
  int stage_v_119_2 = ((stage_v_86_2 + pub_r000692_15_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((stage_v_119_1 + pub_r000692_11_1) + 17) & 127;
  int stage_v_120_2 = ((stage_v_119_2 + pub_r000692_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((sec_r000692_15_1 + pub_r000692_12_1) + 48) & 127;
  int stage_v_121_2 = ((sec_r000692_15_2 + pub_r000692_12_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((stage_v_113_1 + pub_r000692_14_1) + 20) & 127;
  int stage_v_122_2 = ((stage_v_113_2 + pub_r000692_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((stage_v_26_1 + pub_r000692_3_1) + 37) & 127;
  int stage_v_123_2 = ((stage_v_26_2 + pub_r000692_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((stage_v_117_1 + pub_r000692_2_1) + 46) & 127;
  int stage_v_124_2 = ((stage_v_117_2 + pub_r000692_2_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((sec_r000692_15_1 + pub_r000692_15_1) + 21) & 127;
  int stage_v_125_2 = ((sec_r000692_15_2 + pub_r000692_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((stage_v_51_1 + pub_r000692_4_1) + 15) & 127;
  int stage_v_126_2 = ((stage_v_51_2 + pub_r000692_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((sec_r000692_10_1 + pub_r000692_2_1) + 12) & 127;
  int stage_v_127_2 = ((sec_r000692_10_2 + pub_r000692_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((stage_v_115_1 + pub_r000692_14_1) + 3) & 127;
  int stage_v_128_2 = ((stage_v_115_2 + pub_r000692_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((stage_v_123_1 + pub_r000692_11_1) + 20) & 127;
  int stage_v_129_2 = ((stage_v_123_2 + pub_r000692_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((stage_v_104_1 + pub_r000692_0_1) + 7) & 127;
  int stage_v_130_2 = ((stage_v_104_2 + pub_r000692_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((stage_v_73_1 + pub_r000692_14_1) + 6) & 127;
  int stage_v_131_2 = ((stage_v_73_2 + pub_r000692_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((sec_r000692_15_1 + pub_r000692_12_1) + 49) & 127;
  int stage_v_132_2 = ((sec_r000692_15_2 + pub_r000692_12_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((stage_v_115_1 + pub_r000692_11_1) + 15) & 127;
  int stage_v_133_2 = ((stage_v_115_2 + pub_r000692_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((sec_r000692_14_1 + pub_r000692_2_1) + 8) & 127;
  int stage_v_134_2 = ((sec_r000692_14_2 + pub_r000692_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((stage_v_117_1 + pub_r000692_0_1) + 37) & 127;
  int stage_v_135_2 = ((stage_v_117_2 + pub_r000692_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((stage_v_74_1 + pub_r000692_13_1) + 3) & 127;
  int stage_v_136_2 = ((stage_v_74_2 + pub_r000692_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((sec_r000692_2_1 + pub_r000692_1_1) + 10) & 127;
  int stage_v_137_2 = ((sec_r000692_2_2 + pub_r000692_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((stage_v_22_1 + pub_r000692_0_1) + 7) & 127;
  int stage_v_138_2 = ((stage_v_22_2 + pub_r000692_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((stage_v_55_1 + pub_r000692_1_1) + 34) & 127;
  int stage_v_139_2 = ((stage_v_55_2 + pub_r000692_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((stage_v_65_1 + pub_r000692_15_1) + 34) & 127;
  int stage_v_140_2 = ((stage_v_65_2 + pub_r000692_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((sec_r000692_0_1 + pub_r000692_11_1) + 17) & 127;
  int stage_v_141_2 = ((sec_r000692_0_2 + pub_r000692_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((stage_v_137_1 + pub_r000692_9_1) + 23) & 127;
  int stage_v_142_2 = ((stage_v_137_2 + pub_r000692_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((sec_r000692_1_1 + pub_r000692_7_1) + 33) & 127;
  int stage_v_143_2 = ((sec_r000692_1_2 + pub_r000692_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((stage_v_97_1 + pub_r000692_16_1) + 18) & 127;
  int stage_v_144_2 = ((stage_v_97_2 + pub_r000692_16_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((stage_v_141_1 + pub_r000692_14_1) + 13) & 127;
  int stage_v_145_2 = ((stage_v_141_2 + pub_r000692_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((sec_r000692_2_1 + pub_r000692_6_1) + 19) & 127;
  int stage_v_146_2 = ((sec_r000692_2_2 + pub_r000692_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((stage_v_47_1 + pub_r000692_1_1) + 14) & 127;
  int stage_v_147_2 = ((stage_v_47_2 + pub_r000692_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((stage_v_137_1 + pub_r000692_3_1) + 42) & 127;
  int stage_v_148_2 = ((stage_v_137_2 + pub_r000692_3_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((stage_v_148_1 + pub_r000692_7_1) + 16) & 127;
  int stage_v_149_2 = ((stage_v_148_2 + pub_r000692_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((stage_v_35_1 + pub_r000692_15_1) + 19) & 127;
  int stage_v_150_2 = ((stage_v_35_2 + pub_r000692_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((sec_r000692_4_1 + pub_r000692_1_1) + 41) & 127;
  int stage_v_151_2 = ((sec_r000692_4_2 + pub_r000692_1_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((sec_r000692_3_1 + pub_r000692_16_1) + 41) & 127;
  int stage_v_152_2 = ((sec_r000692_3_2 + pub_r000692_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((sec_r000692_0_1 + pub_r000692_8_1) + 14) & 127;
  int stage_v_153_2 = ((sec_r000692_0_2 + pub_r000692_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((stage_v_49_1 + pub_r000692_14_1) + 6) & 127;
  int stage_v_154_2 = ((stage_v_49_2 + pub_r000692_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((stage_v_40_1 + pub_r000692_1_1) + 38) & 127;
  int stage_v_155_2 = ((stage_v_40_2 + pub_r000692_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((stage_v_43_1 + pub_r000692_8_1) + 11) & 127;
  int stage_v_156_2 = ((stage_v_43_2 + pub_r000692_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((stage_v_56_1 + pub_r000692_12_1) + 45) & 127;
  int stage_v_157_2 = ((stage_v_56_2 + pub_r000692_12_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((sec_r000692_6_1 + pub_r000692_3_1) + 11) & 127;
  int stage_v_158_2 = ((sec_r000692_6_2 + pub_r000692_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((stage_v_46_1 + pub_r000692_13_1) + 28) & 127;
  int stage_v_159_2 = ((stage_v_46_2 + pub_r000692_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((stage_v_83_1 + pub_r000692_10_1) + 46) & 127;
  int stage_v_160_2 = ((stage_v_83_2 + pub_r000692_10_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((stage_v_105_1 + pub_r000692_11_1) + 47) & 127;
  int stage_v_161_2 = ((stage_v_105_2 + pub_r000692_11_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((sec_r000692_12_1 + pub_r000692_0_1) + 25) & 127;
  int stage_v_162_2 = ((sec_r000692_12_2 + pub_r000692_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((stage_v_122_1 + pub_r000692_2_1) + 18) & 127;
  int stage_v_163_2 = ((stage_v_122_2 + pub_r000692_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((stage_v_27_1 + pub_r000692_4_1) + 27) & 127;
  int stage_v_164_2 = ((stage_v_27_2 + pub_r000692_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((stage_v_148_1 + pub_r000692_2_1) + 22) & 127;
  int stage_v_165_2 = ((stage_v_148_2 + pub_r000692_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((sec_r000692_11_1 + pub_r000692_11_1) + 42) & 127;
  int stage_v_166_2 = ((sec_r000692_11_2 + pub_r000692_11_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((sec_r000692_11_1 + pub_r000692_3_1) + 26) & 127;
  int stage_v_167_2 = ((sec_r000692_11_2 + pub_r000692_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((stage_v_60_1 + pub_r000692_8_1) + 41) & 127;
  int stage_v_168_2 = ((stage_v_60_2 + pub_r000692_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((stage_v_52_1 + pub_r000692_13_1) + 9) & 127;
  int stage_v_169_2 = ((stage_v_52_2 + pub_r000692_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((sec_r000692_17_1 + pub_r000692_1_1) + 25) & 127;
  int stage_v_170_2 = ((sec_r000692_17_2 + pub_r000692_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((sec_r000692_17_1 + pub_r000692_11_1) + 43) & 127;
  int stage_v_171_2 = ((sec_r000692_17_2 + pub_r000692_11_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((stage_v_132_1 + pub_r000692_12_1) + 24) & 127;
  int stage_v_172_2 = ((stage_v_132_2 + pub_r000692_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((sec_r000692_9_1 + pub_r000692_2_1) + 17) & 127;
  int stage_v_173_2 = ((sec_r000692_9_2 + pub_r000692_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((stage_v_121_1 + pub_r000692_2_1) + 45) & 127;
  int stage_v_174_2 = ((stage_v_121_2 + pub_r000692_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((sec_r000692_3_1 + pub_r000692_2_1) + 15) & 127;
  int stage_v_175_2 = ((sec_r000692_3_2 + pub_r000692_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((sec_r000692_17_1 + pub_r000692_8_1) + 10) & 127;
  int stage_v_176_2 = ((sec_r000692_17_2 + pub_r000692_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((sec_r000692_2_1 + pub_r000692_10_1) + 43) & 127;
  int stage_v_177_2 = ((sec_r000692_2_2 + pub_r000692_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((stage_v_49_1 + pub_r000692_15_1) + 8) & 127;
  int stage_v_178_2 = ((stage_v_49_2 + pub_r000692_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((stage_v_86_1 + pub_r000692_2_1) + 12) & 127;
  int stage_v_179_2 = ((stage_v_86_2 + pub_r000692_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((sec_r000692_11_1 + pub_r000692_6_1) + 49) & 127;
  int stage_v_180_2 = ((sec_r000692_11_2 + pub_r000692_6_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((stage_v_143_1 + pub_r000692_1_1) + 8) & 127;
  int stage_v_181_2 = ((stage_v_143_2 + pub_r000692_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((stage_v_56_1 + pub_r000692_5_1) + 4) & 127;
  int stage_v_182_2 = ((stage_v_56_2 + pub_r000692_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((stage_v_167_1 + pub_r000692_6_1) + 35) & 127;
  int stage_v_183_2 = ((stage_v_167_2 + pub_r000692_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((stage_v_74_1 + pub_r000692_10_1) + 25) & 127;
  int stage_v_184_2 = ((stage_v_74_2 + pub_r000692_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((stage_v_32_1 + pub_r000692_16_1) + 29) & 127;
  int stage_v_185_2 = ((stage_v_32_2 + pub_r000692_16_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((stage_v_150_1 + pub_r000692_2_1) + 4) & 127;
  int stage_v_186_2 = ((stage_v_150_2 + pub_r000692_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((sec_r000692_6_1 + pub_r000692_9_1) + 45) & 127;
  int stage_v_187_2 = ((sec_r000692_6_2 + pub_r000692_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((stage_v_139_1 + pub_r000692_16_1) + 9) & 127;
  int stage_v_188_2 = ((stage_v_139_2 + pub_r000692_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((stage_v_80_1 + pub_r000692_11_1) + 40) & 127;
  int stage_v_189_2 = ((stage_v_80_2 + pub_r000692_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((stage_v_139_1 + pub_r000692_11_1) + 5) & 127;
  int stage_v_190_2 = ((stage_v_139_2 + pub_r000692_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((stage_v_71_1 + pub_r000692_9_1) + 26) & 127;
  int stage_v_191_2 = ((stage_v_71_2 + pub_r000692_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((stage_v_22_1 + pub_r000692_9_1) + 41) & 127;
  int stage_v_192_2 = ((stage_v_22_2 + pub_r000692_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((sec_r000692_4_1 + pub_r000692_11_1) + 26) & 127;
  int stage_v_193_2 = ((sec_r000692_4_2 + pub_r000692_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((sec_r000692_1_1 + pub_r000692_14_1) + 11) & 127;
  int stage_v_194_2 = ((sec_r000692_1_2 + pub_r000692_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((stage_v_127_1 + pub_r000692_1_1) + 18) & 127;
  int stage_v_195_2 = ((stage_v_127_2 + pub_r000692_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((stage_v_195_1 + pub_r000692_6_1) + 42) & 127;
  int stage_v_196_2 = ((stage_v_195_2 + pub_r000692_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((stage_v_138_1 + pub_r000692_0_1) + 38) & 127;
  int stage_v_197_2 = ((stage_v_138_2 + pub_r000692_0_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((sec_r000692_15_1 + pub_r000692_12_1) + 19) & 127;
  int stage_v_198_2 = ((sec_r000692_15_2 + pub_r000692_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((stage_v_124_1 + pub_r000692_4_1) + 39) & 127;
  int stage_v_199_2 = ((stage_v_124_2 + pub_r000692_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((stage_v_29_1 + pub_r000692_16_1) + 37) & 127;
  int stage_v_200_2 = ((stage_v_29_2 + pub_r000692_16_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((sec_r000692_2_1 + pub_r000692_5_1) + 5) & 127;
  int stage_v_201_2 = ((sec_r000692_2_2 + pub_r000692_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((sec_r000692_11_1 + pub_r000692_3_1) + 48) & 127;
  int stage_v_202_2 = ((sec_r000692_11_2 + pub_r000692_3_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((stage_v_105_1 + pub_r000692_2_1) + 15) & 127;
  int stage_v_203_2 = ((stage_v_105_2 + pub_r000692_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((stage_v_55_1 + pub_r000692_15_1) + 30) & 127;
  int stage_v_204_2 = ((stage_v_55_2 + pub_r000692_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((sec_r000692_11_1 + pub_r000692_8_1) + 49) & 127;
  int stage_v_205_2 = ((sec_r000692_11_2 + pub_r000692_8_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((stage_v_183_1 + pub_r000692_7_1) + 40) & 127;
  int stage_v_206_2 = ((stage_v_183_2 + pub_r000692_7_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((sec_r000692_0_1 + pub_r000692_14_1) + 39) & 127;
  int stage_v_207_2 = ((sec_r000692_0_2 + pub_r000692_14_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((sec_r000692_6_1 + pub_r000692_1_1) + 32) & 127;
  int stage_v_208_2 = ((sec_r000692_6_2 + pub_r000692_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((sec_r000692_17_1 + pub_r000692_0_1) + 29) & 127;
  int stage_v_209_2 = ((sec_r000692_17_2 + pub_r000692_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((stage_v_94_1 + pub_r000692_5_1) + 32) & 127;
  int stage_v_210_2 = ((stage_v_94_2 + pub_r000692_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((stage_v_184_1 + pub_r000692_11_1) + 32) & 127;
  int stage_v_211_2 = ((stage_v_184_2 + pub_r000692_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((stage_v_150_1 + pub_r000692_12_1) + 37) & 127;
  int stage_v_212_2 = ((stage_v_150_2 + pub_r000692_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((stage_v_83_1 + pub_r000692_0_1) + 40) & 127;
  int stage_v_213_2 = ((stage_v_83_2 + pub_r000692_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((stage_v_55_1 + pub_r000692_9_1) + 36) & 127;
  int stage_v_214_2 = ((stage_v_55_2 + pub_r000692_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((sec_r000692_8_1 + pub_r000692_0_1) + 42) & 127;
  int stage_v_215_2 = ((sec_r000692_8_2 + pub_r000692_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((stage_v_106_1 + pub_r000692_13_1) + 32) & 127;
  int stage_v_216_2 = ((stage_v_106_2 + pub_r000692_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((sec_r000692_16_1 + pub_r000692_2_1) + 3) & 127;
  int stage_v_217_2 = ((sec_r000692_16_2 + pub_r000692_2_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((sec_r000692_2_1 + pub_r000692_1_1) + 14) & 127;
  int stage_v_218_2 = ((sec_r000692_2_2 + pub_r000692_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((sec_r000692_16_1 + pub_r000692_7_1) + 38) & 127;
  int stage_v_219_2 = ((sec_r000692_16_2 + pub_r000692_7_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((sec_r000692_4_1 + pub_r000692_14_1) + 29) & 127;
  int stage_v_220_2 = ((sec_r000692_4_2 + pub_r000692_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((stage_v_166_1 + pub_r000692_8_1) + 20) & 127;
  int stage_v_221_2 = ((stage_v_166_2 + pub_r000692_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((sec_r000692_6_1 + pub_r000692_3_1) + 39) & 127;
  int stage_v_222_2 = ((sec_r000692_6_2 + pub_r000692_3_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((stage_v_129_1 + pub_r000692_10_1) + 4) & 127;
  int stage_v_223_2 = ((stage_v_129_2 + pub_r000692_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((stage_v_220_1 + pub_r000692_10_1) + 22) & 127;
  int stage_v_224_2 = ((stage_v_220_2 + pub_r000692_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((stage_v_74_1 + pub_r000692_14_1) + 4) & 127;
  int stage_v_225_2 = ((stage_v_74_2 + pub_r000692_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((stage_v_201_1 + pub_r000692_6_1) + 36) & 127;
  int stage_v_226_2 = ((stage_v_201_2 + pub_r000692_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((stage_v_118_1 + pub_r000692_7_1) + 29) & 127;
  int stage_v_227_2 = ((stage_v_118_2 + pub_r000692_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((stage_v_102_1 + pub_r000692_7_1) + 17) & 127;
  int stage_v_228_2 = ((stage_v_102_2 + pub_r000692_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((sec_r000692_0_1 + pub_r000692_13_1) + 30) & 127;
  int stage_v_229_2 = ((sec_r000692_0_2 + pub_r000692_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((stage_v_141_1 + pub_r000692_8_1) + 11) & 127;
  int stage_v_230_2 = ((stage_v_141_2 + pub_r000692_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((sec_r000692_1_1 + pub_r000692_14_1) + 15) & 127;
  int stage_v_231_2 = ((sec_r000692_1_2 + pub_r000692_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((stage_v_205_1 + pub_r000692_7_1) + 42) & 127;
  int stage_v_232_2 = ((stage_v_205_2 + pub_r000692_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((sec_r000692_4_1 + pub_r000692_8_1) + 34) & 127;
  int stage_v_233_2 = ((sec_r000692_4_2 + pub_r000692_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((stage_v_143_1 + pub_r000692_1_1) + 40) & 127;
  int stage_v_234_2 = ((stage_v_143_2 + pub_r000692_1_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((sec_r000692_4_1 + pub_r000692_15_1) + 33) & 127;
  int stage_v_235_2 = ((sec_r000692_4_2 + pub_r000692_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((sec_r000692_0_1 + pub_r000692_12_1) + 49) & 127;
  int stage_v_236_2 = ((sec_r000692_0_2 + pub_r000692_12_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((sec_r000692_4_1 + pub_r000692_5_1) + 12) & 127;
  int stage_v_237_2 = ((sec_r000692_4_2 + pub_r000692_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((stage_v_89_1 + pub_r000692_14_1) + 19) & 127;
  int stage_v_238_2 = ((stage_v_89_2 + pub_r000692_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((stage_v_79_1 + pub_r000692_3_1) + 11) & 127;
  int stage_v_239_2 = ((stage_v_79_2 + pub_r000692_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((sec_r000692_6_1 + pub_r000692_6_1) + 35) & 127;
  int stage_v_240_2 = ((sec_r000692_6_2 + pub_r000692_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((sec_r000692_8_1 + pub_r000692_9_1) + 9) & 127;
  int stage_v_241_2 = ((sec_r000692_8_2 + pub_r000692_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((stage_v_85_1 + pub_r000692_2_1) + 21) & 127;
  int stage_v_242_2 = ((stage_v_85_2 + pub_r000692_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((sec_r000692_3_1 + pub_r000692_1_1) + 20) & 127;
  int stage_v_243_2 = ((sec_r000692_3_2 + pub_r000692_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((sec_r000692_2_1 + pub_r000692_1_1) + 29) & 127;
  int stage_v_244_2 = ((sec_r000692_2_2 + pub_r000692_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((stage_v_63_1 + pub_r000692_5_1) + 11) & 127;
  int stage_v_245_2 = ((stage_v_63_2 + pub_r000692_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((stage_v_115_1 + pub_r000692_9_1) + 49) & 127;
  int stage_v_246_2 = ((stage_v_115_2 + pub_r000692_9_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((stage_v_197_1 + pub_r000692_3_1) + 48) & 127;
  int stage_v_247_2 = ((stage_v_197_2 + pub_r000692_3_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((sec_r000692_15_1 + pub_r000692_9_1) + 35) & 127;
  int stage_v_248_2 = ((sec_r000692_15_2 + pub_r000692_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((stage_v_165_1 + pub_r000692_8_1) + 14) & 127;
  int stage_v_249_2 = ((stage_v_165_2 + pub_r000692_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((stage_v_70_1 + pub_r000692_2_1) + 36) & 127;
  int stage_v_250_2 = ((stage_v_70_2 + pub_r000692_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((stage_v_209_1 + pub_r000692_1_1) + 6) & 127;
  int stage_v_251_2 = ((stage_v_209_2 + pub_r000692_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((stage_v_51_1 + pub_r000692_14_1) + 12) & 127;
  int stage_v_252_2 = ((stage_v_51_2 + pub_r000692_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((sec_r000692_6_1 + pub_r000692_14_1) + 49) & 127;
  int stage_v_253_2 = ((sec_r000692_6_2 + pub_r000692_14_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((stage_v_106_1 + pub_r000692_13_1) + 45) & 127;
  int stage_v_254_2 = ((stage_v_106_2 + pub_r000692_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((stage_v_59_1 + pub_r000692_16_1) + 11) & 127;
  int stage_v_255_2 = ((stage_v_59_2 + pub_r000692_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((stage_v_69_1 + pub_r000692_12_1) + 7) & 127;
  int stage_v_256_2 = ((stage_v_69_2 + pub_r000692_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((stage_v_149_1 + pub_r000692_15_1) + 37) & 127;
  int stage_v_257_2 = ((stage_v_149_2 + pub_r000692_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((sec_r000692_0_1 + pub_r000692_16_1) + 14) & 127;
  int stage_v_258_2 = ((sec_r000692_0_2 + pub_r000692_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((stage_v_130_1 + pub_r000692_8_1) + 25) & 127;
  int stage_v_259_2 = ((stage_v_130_2 + pub_r000692_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((sec_r000692_13_1 + pub_r000692_15_1) + 21) & 127;
  int stage_v_260_2 = ((sec_r000692_13_2 + pub_r000692_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((sec_r000692_16_1 + pub_r000692_5_1) + 24) & 127;
  int stage_v_261_2 = ((sec_r000692_16_2 + pub_r000692_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((sec_r000692_4_1 + pub_r000692_4_1) + 8) & 127;
  int stage_v_262_2 = ((sec_r000692_4_2 + pub_r000692_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((stage_v_195_1 + pub_r000692_2_1) + 43) & 127;
  int stage_v_263_2 = ((stage_v_195_2 + pub_r000692_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((sec_r000692_10_1 + pub_r000692_15_1) + 5) & 127;
  int stage_v_264_2 = ((sec_r000692_10_2 + pub_r000692_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((stage_v_186_1 + pub_r000692_14_1) + 4) & 127;
  int stage_v_265_2 = ((stage_v_186_2 + pub_r000692_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((stage_v_244_1 + pub_r000692_9_1) + 8) & 127;
  int stage_v_266_2 = ((stage_v_244_2 + pub_r000692_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((stage_v_175_1 + pub_r000692_5_1) + 18) & 127;
  int stage_v_267_2 = ((stage_v_175_2 + pub_r000692_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((stage_v_221_1 + pub_r000692_14_1) + 26) & 127;
  int stage_v_268_2 = ((stage_v_221_2 + pub_r000692_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((stage_v_97_1 + pub_r000692_9_1) + 40) & 127;
  int stage_v_269_2 = ((stage_v_97_2 + pub_r000692_9_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((stage_v_91_1 + pub_r000692_1_1) + 43) & 127;
  int stage_v_270_2 = ((stage_v_91_2 + pub_r000692_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((sec_r000692_6_1 + pub_r000692_4_1) + 27) & 127;
  int stage_v_271_2 = ((sec_r000692_6_2 + pub_r000692_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((sec_r000692_1_1 + pub_r000692_11_1) + 14) & 127;
  int stage_v_272_2 = ((sec_r000692_1_2 + pub_r000692_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((stage_v_250_1 + pub_r000692_5_1) + 40) & 127;
  int stage_v_273_2 = ((stage_v_250_2 + pub_r000692_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((sec_r000692_10_1 + pub_r000692_12_1) + 39) & 127;
  int stage_v_274_2 = ((sec_r000692_10_2 + pub_r000692_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((sec_r000692_5_1 + pub_r000692_2_1) + 25) & 127;
  int stage_v_275_2 = ((sec_r000692_5_2 + pub_r000692_2_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((sec_r000692_11_1 + pub_r000692_15_1) + 24) & 127;
  int stage_v_276_2 = ((sec_r000692_11_2 + pub_r000692_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((stage_v_204_1 + pub_r000692_15_1) + 47) & 127;
  int stage_v_277_2 = ((stage_v_204_2 + pub_r000692_15_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((stage_v_269_1 + pub_r000692_12_1) + 46) & 127;
  int stage_v_278_2 = ((stage_v_269_2 + pub_r000692_12_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((stage_v_74_1 + pub_r000692_8_1) + 39) & 127;
  int stage_v_279_2 = ((stage_v_74_2 + pub_r000692_8_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((sec_r000692_7_1 + pub_r000692_8_1) + 30) & 127;
  int stage_v_280_2 = ((sec_r000692_7_2 + pub_r000692_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((sec_r000692_4_1 + pub_r000692_8_1) + 6) & 127;
  int stage_v_281_2 = ((sec_r000692_4_2 + pub_r000692_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((sec_r000692_8_1 + pub_r000692_16_1) + 46) & 127;
  int stage_v_282_2 = ((sec_r000692_8_2 + pub_r000692_16_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((stage_v_139_1 + pub_r000692_0_1) + 11) & 127;
  int stage_v_283_2 = ((stage_v_139_2 + pub_r000692_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((sec_r000692_4_1 + pub_r000692_12_1) + 32) & 127;
  int stage_v_284_2 = ((sec_r000692_4_2 + pub_r000692_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((stage_v_230_1 + pub_r000692_8_1) + 44) & 127;
  int stage_v_285_2 = ((stage_v_230_2 + pub_r000692_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((stage_v_102_1 + pub_r000692_13_1) + 25) & 127;
  int stage_v_286_2 = ((stage_v_102_2 + pub_r000692_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((stage_v_153_1 + pub_r000692_12_1) + 17) & 127;
  int stage_v_287_2 = ((stage_v_153_2 + pub_r000692_12_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((sec_r000692_7_1 + pub_r000692_15_1) + 48) & 127;
  int stage_v_288_2 = ((sec_r000692_7_2 + pub_r000692_15_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((sec_r000692_2_1 + pub_r000692_15_1) + 12) & 127;
  int stage_v_289_2 = ((sec_r000692_2_2 + pub_r000692_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((stage_v_166_1 + pub_r000692_11_1) + 10) & 127;
  int stage_v_290_2 = ((stage_v_166_2 + pub_r000692_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((sec_r000692_2_1 + pub_r000692_7_1) + 35) & 127;
  int stage_v_291_2 = ((sec_r000692_2_2 + pub_r000692_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((stage_v_127_1 + pub_r000692_3_1) + 32) & 127;
  int stage_v_292_2 = ((stage_v_127_2 + pub_r000692_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((stage_v_228_1 + pub_r000692_3_1) + 14) & 127;
  int stage_v_293_2 = ((stage_v_228_2 + pub_r000692_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((sec_r000692_1_1 + pub_r000692_2_1) + 37) & 127;
  int stage_v_294_2 = ((sec_r000692_1_2 + pub_r000692_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((stage_v_191_1 + pub_r000692_7_1) + 43) & 127;
  int stage_v_295_2 = ((stage_v_191_2 + pub_r000692_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((stage_v_213_1 + pub_r000692_7_1) + 6) & 127;
  int stage_v_296_2 = ((stage_v_213_2 + pub_r000692_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((stage_v_221_1 + pub_r000692_13_1) + 46) & 127;
  int stage_v_297_2 = ((stage_v_221_2 + pub_r000692_13_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((stage_v_154_1 + pub_r000692_12_1) + 21) & 127;
  int stage_v_298_2 = ((stage_v_154_2 + pub_r000692_12_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((stage_v_56_1 + pub_r000692_3_1) + 20) & 127;
  int stage_v_299_2 = ((stage_v_56_2 + pub_r000692_3_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((sec_r000692_5_1 + pub_r000692_2_1) + 19) & 127;
  int stage_v_300_2 = ((sec_r000692_5_2 + pub_r000692_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((stage_v_144_1 + pub_r000692_5_1) + 20) & 127;
  int stage_v_301_2 = ((stage_v_144_2 + pub_r000692_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((stage_v_138_1 + pub_r000692_1_1) + 33) & 127;
  int stage_v_302_2 = ((stage_v_138_2 + pub_r000692_1_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((stage_v_279_1 + pub_r000692_12_1) + 25) & 127;
  int stage_v_303_2 = ((stage_v_279_2 + pub_r000692_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((stage_v_289_1 + pub_r000692_8_1) + 25) & 127;
  int stage_v_304_2 = ((stage_v_289_2 + pub_r000692_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((stage_v_230_1 + pub_r000692_1_1) + 46) & 127;
  int stage_v_305_2 = ((stage_v_230_2 + pub_r000692_1_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((stage_v_165_1 + pub_r000692_1_1) + 34) & 127;
  int stage_v_306_2 = ((stage_v_165_2 + pub_r000692_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((stage_v_263_1 + pub_r000692_16_1) + 43) & 127;
  int stage_v_307_2 = ((stage_v_263_2 + pub_r000692_16_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((stage_v_224_1 + pub_r000692_0_1) + 31) & 127;
  int stage_v_308_2 = ((stage_v_224_2 + pub_r000692_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((sec_r000692_0_1 + pub_r000692_6_1) + 47) & 127;
  int stage_v_309_2 = ((sec_r000692_0_2 + pub_r000692_6_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((stage_v_33_1 + pub_r000692_8_1) + 44) & 127;
  int stage_v_310_2 = ((stage_v_33_2 + pub_r000692_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((sec_r000692_15_1 + pub_r000692_6_1) + 40) & 127;
  int stage_v_311_2 = ((sec_r000692_15_2 + pub_r000692_6_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((stage_v_73_1 + pub_r000692_5_1) + 18) & 127;
  int stage_v_312_2 = ((stage_v_73_2 + pub_r000692_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int stage_v_313_1 = ((stage_v_124_1 + pub_r000692_0_1) + 23) & 127;
  int stage_v_313_2 = ((stage_v_124_2 + pub_r000692_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int stage_v_314_1 = ((stage_v_26_1 + pub_r000692_0_1) + 12) & 127;
  int stage_v_314_2 = ((stage_v_26_2 + pub_r000692_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int stage_v_315_1 = ((stage_v_278_1 + pub_r000692_9_1) + 40) & 127;
  int stage_v_315_2 = ((stage_v_278_2 + pub_r000692_9_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  int stage_v_316_1 = ((stage_v_307_1 + pub_r000692_9_1) + 15) & 127;
  int stage_v_316_2 = ((stage_v_307_2 + pub_r000692_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_316_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_316_2) & 255;
  int stage_v_317_1 = ((stage_v_199_1 + pub_r000692_14_1) + 36) & 127;
  int stage_v_317_2 = ((stage_v_199_2 + pub_r000692_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_317_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_317_2) & 255;
  int stage_v_318_1 = ((sec_r000692_6_1 + pub_r000692_10_1) + 4) & 127;
  int stage_v_318_2 = ((sec_r000692_6_2 + pub_r000692_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_318_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_318_2) & 255;
  int stage_v_319_1 = ((stage_v_288_1 + pub_r000692_0_1) + 29) & 127;
  int stage_v_319_2 = ((stage_v_288_2 + pub_r000692_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_319_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_319_2) & 255;
  int stage_v_320_1 = ((stage_v_139_1 + pub_r000692_0_1) + 11) & 127;
  int stage_v_320_2 = ((stage_v_139_2 + pub_r000692_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_320_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_320_2) & 255;
  int stage_v_321_1 = ((stage_v_205_1 + pub_r000692_7_1) + 10) & 127;
  int stage_v_321_2 = ((stage_v_205_2 + pub_r000692_7_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_321_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_321_2) & 255;
  int stage_v_322_1 = ((stage_v_318_1 + pub_r000692_7_1) + 21) & 127;
  int stage_v_322_2 = ((stage_v_318_2 + pub_r000692_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_322_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_322_2) & 255;
  int stage_v_323_1 = ((stage_v_90_1 + pub_r000692_2_1) + 27) & 127;
  int stage_v_323_2 = ((stage_v_90_2 + pub_r000692_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_323_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_323_2) & 255;
  int stage_v_324_1 = ((stage_v_299_1 + pub_r000692_14_1) + 38) & 127;
  int stage_v_324_2 = ((stage_v_299_2 + pub_r000692_14_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_324_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_324_2) & 255;
  int stage_v_325_1 = ((stage_v_209_1 + pub_r000692_15_1) + 21) & 127;
  int stage_v_325_2 = ((stage_v_209_2 + pub_r000692_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_325_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_325_2) & 255;
  int stage_v_326_1 = ((stage_v_239_1 + pub_r000692_13_1) + 15) & 127;
  int stage_v_326_2 = ((stage_v_239_2 + pub_r000692_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_326_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_326_2) & 255;
  int stage_v_327_1 = ((stage_v_195_1 + pub_r000692_15_1) + 23) & 127;
  int stage_v_327_2 = ((stage_v_195_2 + pub_r000692_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_327_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_327_2) & 255;
  int stage_v_328_1 = ((sec_r000692_10_1 + pub_r000692_9_1) + 38) & 127;
  int stage_v_328_2 = ((sec_r000692_10_2 + pub_r000692_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_328_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_328_2) & 255;
  int stage_v_329_1 = ((sec_r000692_10_1 + pub_r000692_2_1) + 31) & 127;
  int stage_v_329_2 = ((sec_r000692_10_2 + pub_r000692_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_329_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_329_2) & 255;
  int stage_v_330_1 = ((stage_v_64_1 + pub_r000692_1_1) + 47) & 127;
  int stage_v_330_2 = ((stage_v_64_2 + pub_r000692_1_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_330_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_330_2) & 255;
  int stage_v_331_1 = ((stage_v_47_1 + pub_r000692_13_1) + 22) & 127;
  int stage_v_331_2 = ((stage_v_47_2 + pub_r000692_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_331_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_331_2) & 255;
  int stage_v_332_1 = ((sec_r000692_3_1 + pub_r000692_15_1) + 48) & 127;
  int stage_v_332_2 = ((sec_r000692_3_2 + pub_r000692_15_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_332_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_332_2) & 255;
  int stage_v_333_1 = ((sec_r000692_9_1 + pub_r000692_16_1) + 24) & 127;
  int stage_v_333_2 = ((sec_r000692_9_2 + pub_r000692_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_333_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_333_2) & 255;
  int stage_v_334_1 = ((stage_v_197_1 + pub_r000692_0_1) + 26) & 127;
  int stage_v_334_2 = ((stage_v_197_2 + pub_r000692_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_334_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_334_2) & 255;
  int stage_v_335_1 = ((sec_r000692_12_1 + pub_r000692_1_1) + 9) & 127;
  int stage_v_335_2 = ((sec_r000692_12_2 + pub_r000692_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_335_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_335_2) & 255;
  int stage_v_336_1 = ((sec_r000692_5_1 + pub_r000692_1_1) + 8) & 127;
  int stage_v_336_2 = ((sec_r000692_5_2 + pub_r000692_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_336_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_336_2) & 255;
  int stage_v_337_1 = ((sec_r000692_9_1 + pub_r000692_8_1) + 40) & 127;
  int stage_v_337_2 = ((sec_r000692_9_2 + pub_r000692_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_337_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_337_2) & 255;
  int stage_v_338_1 = ((stage_v_332_1 + pub_r000692_0_1) + 9) & 127;
  int stage_v_338_2 = ((stage_v_332_2 + pub_r000692_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_338_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_338_2) & 255;
  int stage_v_339_1 = ((stage_v_187_1 + pub_r000692_14_1) + 29) & 127;
  int stage_v_339_2 = ((stage_v_187_2 + pub_r000692_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_339_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_339_2) & 255;
  int stage_v_340_1 = ((sec_r000692_16_1 + pub_r000692_12_1) + 13) & 127;
  int stage_v_340_2 = ((sec_r000692_16_2 + pub_r000692_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_340_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_340_2) & 255;
  int stage_v_341_1 = ((stage_v_294_1 + pub_r000692_8_1) + 27) & 127;
  int stage_v_341_2 = ((stage_v_294_2 + pub_r000692_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_341_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_341_2) & 255;
  int stage_v_342_1 = ((stage_v_141_1 + pub_r000692_0_1) + 38) & 127;
  int stage_v_342_2 = ((stage_v_141_2 + pub_r000692_0_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_342_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_342_2) & 255;
  int stage_v_343_1 = ((stage_v_42_1 + pub_r000692_12_1) + 18) & 127;
  int stage_v_343_2 = ((stage_v_42_2 + pub_r000692_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_343_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_343_2) & 255;
  int stage_v_344_1 = ((stage_v_310_1 + pub_r000692_16_1) + 14) & 127;
  int stage_v_344_2 = ((stage_v_310_2 + pub_r000692_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_344_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_344_2) & 255;
  int stage_v_345_1 = ((sec_r000692_12_1 + pub_r000692_11_1) + 14) & 127;
  int stage_v_345_2 = ((sec_r000692_12_2 + pub_r000692_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_345_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_345_2) & 255;
  int stage_v_346_1 = ((stage_v_116_1 + pub_r000692_9_1) + 18) & 127;
  int stage_v_346_2 = ((stage_v_116_2 + pub_r000692_9_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_346_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_346_2) & 255;
  int stage_v_347_1 = ((stage_v_196_1 + pub_r000692_2_1) + 33) & 127;
  int stage_v_347_2 = ((stage_v_196_2 + pub_r000692_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_347_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_347_2) & 255;
  int stage_v_348_1 = ((stage_v_171_1 + pub_r000692_6_1) + 24) & 127;
  int stage_v_348_2 = ((stage_v_171_2 + pub_r000692_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_348_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_348_2) & 255;
  int stage_v_349_1 = ((sec_r000692_17_1 + pub_r000692_16_1) + 27) & 127;
  int stage_v_349_2 = ((sec_r000692_17_2 + pub_r000692_16_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_349_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_349_2) & 255;
  int stage_v_350_1 = ((stage_v_214_1 + pub_r000692_3_1) + 17) & 127;
  int stage_v_350_2 = ((stage_v_214_2 + pub_r000692_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_350_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_350_2) & 255;
  int stage_v_351_1 = ((stage_v_337_1 + pub_r000692_7_1) + 32) & 127;
  int stage_v_351_2 = ((stage_v_337_2 + pub_r000692_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_351_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_351_2) & 255;
  int stage_v_352_1 = ((sec_r000692_0_1 + pub_r000692_15_1) + 23) & 127;
  int stage_v_352_2 = ((sec_r000692_0_2 + pub_r000692_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_352_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_352_2) & 255;
  int stage_v_353_1 = ((stage_v_132_1 + pub_r000692_7_1) + 48) & 127;
  int stage_v_353_2 = ((stage_v_132_2 + pub_r000692_7_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_353_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_353_2) & 255;
  int stage_v_354_1 = ((sec_r000692_10_1 + pub_r000692_14_1) + 5) & 127;
  int stage_v_354_2 = ((sec_r000692_10_2 + pub_r000692_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_354_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_354_2) & 255;
  int stage_v_355_1 = ((stage_v_338_1 + pub_r000692_4_1) + 39) & 127;
  int stage_v_355_2 = ((stage_v_338_2 + pub_r000692_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_355_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_355_2) & 255;
  int stage_v_356_1 = ((stage_v_343_1 + pub_r000692_14_1) + 40) & 127;
  int stage_v_356_2 = ((stage_v_343_2 + pub_r000692_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_356_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_356_2) & 255;
  int stage_v_357_1 = ((sec_r000692_14_1 + pub_r000692_8_1) + 30) & 127;
  int stage_v_357_2 = ((sec_r000692_14_2 + pub_r000692_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_357_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_357_2) & 255;
  int stage_v_358_1 = ((stage_v_327_1 + pub_r000692_8_1) + 8) & 127;
  int stage_v_358_2 = ((stage_v_327_2 + pub_r000692_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_358_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_358_2) & 255;
  int stage_v_359_1 = ((stage_v_221_1 + pub_r000692_8_1) + 21) & 127;
  int stage_v_359_2 = ((stage_v_221_2 + pub_r000692_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_359_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_359_2) & 255;
  int stage_v_360_1 = ((sec_r000692_17_1 + pub_r000692_12_1) + 33) & 127;
  int stage_v_360_2 = ((sec_r000692_17_2 + pub_r000692_12_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_360_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_360_2) & 255;
  int stage_v_361_1 = ((sec_r000692_15_1 + pub_r000692_15_1) + 14) & 127;
  int stage_v_361_2 = ((sec_r000692_15_2 + pub_r000692_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_361_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_361_2) & 255;
  int stage_v_362_1 = ((sec_r000692_9_1 + pub_r000692_6_1) + 11) & 127;
  int stage_v_362_2 = ((sec_r000692_9_2 + pub_r000692_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_362_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_362_2) & 255;
  int stage_v_363_1 = ((sec_r000692_12_1 + pub_r000692_4_1) + 12) & 127;
  int stage_v_363_2 = ((sec_r000692_12_2 + pub_r000692_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_363_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_363_2) & 255;
  int stage_v_364_1 = ((stage_v_239_1 + pub_r000692_3_1) + 11) & 127;
  int stage_v_364_2 = ((stage_v_239_2 + pub_r000692_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_364_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_364_2) & 255;
  int stage_v_365_1 = ((stage_v_183_1 + pub_r000692_16_1) + 48) & 127;
  int stage_v_365_2 = ((stage_v_183_2 + pub_r000692_16_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_365_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_365_2) & 255;
  int stage_v_366_1 = ((stage_v_41_1 + pub_r000692_13_1) + 22) & 127;
  int stage_v_366_2 = ((stage_v_41_2 + pub_r000692_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_366_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_366_2) & 255;
  int stage_v_367_1 = ((sec_r000692_3_1 + pub_r000692_3_1) + 28) & 127;
  int stage_v_367_2 = ((sec_r000692_3_2 + pub_r000692_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_367_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_367_2) & 255;
  int stage_v_368_1 = ((stage_v_258_1 + pub_r000692_9_1) + 39) & 127;
  int stage_v_368_2 = ((stage_v_258_2 + pub_r000692_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_368_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_368_2) & 255;
  int stage_v_369_1 = ((sec_r000692_17_1 + pub_r000692_3_1) + 37) & 127;
  int stage_v_369_2 = ((sec_r000692_17_2 + pub_r000692_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_369_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_369_2) & 255;
  int stage_v_370_1 = ((stage_v_355_1 + pub_r000692_5_1) + 10) & 127;
  int stage_v_370_2 = ((stage_v_355_2 + pub_r000692_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_370_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_370_2) & 255;
  int stage_v_371_1 = ((stage_v_60_1 + pub_r000692_3_1) + 9) & 127;
  int stage_v_371_2 = ((stage_v_60_2 + pub_r000692_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_371_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_371_2) & 255;
  int stage_v_372_1 = ((stage_v_214_1 + pub_r000692_15_1) + 21) & 127;
  int stage_v_372_2 = ((stage_v_214_2 + pub_r000692_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_372_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_372_2) & 255;
  int stage_v_373_1 = ((stage_v_231_1 + pub_r000692_11_1) + 40) & 127;
  int stage_v_373_2 = ((stage_v_231_2 + pub_r000692_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_373_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_373_2) & 255;
  int stage_v_374_1 = ((stage_v_171_1 + pub_r000692_0_1) + 3) & 127;
  int stage_v_374_2 = ((stage_v_171_2 + pub_r000692_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_374_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_374_2) & 255;
  int stage_v_375_1 = ((stage_v_300_1 + pub_r000692_5_1) + 21) & 127;
  int stage_v_375_2 = ((stage_v_300_2 + pub_r000692_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_375_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_375_2) & 255;
  int stage_v_376_1 = ((sec_r000692_5_1 + pub_r000692_5_1) + 40) & 127;
  int stage_v_376_2 = ((sec_r000692_5_2 + pub_r000692_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_376_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_376_2) & 255;
  int stage_v_377_1 = ((stage_v_242_1 + pub_r000692_4_1) + 13) & 127;
  int stage_v_377_2 = ((stage_v_242_2 + pub_r000692_4_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_377_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_377_2) & 255;
  int stage_v_378_1 = ((stage_v_361_1 + pub_r000692_16_1) + 20) & 127;
  int stage_v_378_2 = ((stage_v_361_2 + pub_r000692_16_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_378_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_378_2) & 255;
  int stage_v_379_1 = ((stage_v_91_1 + pub_r000692_5_1) + 5) & 127;
  int stage_v_379_2 = ((stage_v_91_2 + pub_r000692_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_379_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_379_2) & 255;
  int stage_v_380_1 = ((sec_r000692_6_1 + pub_r000692_5_1) + 40) & 127;
  int stage_v_380_2 = ((sec_r000692_6_2 + pub_r000692_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_380_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_380_2) & 255;
  int stage_v_381_1 = ((sec_r000692_15_1 + pub_r000692_7_1) + 42) & 127;
  int stage_v_381_2 = ((sec_r000692_15_2 + pub_r000692_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_381_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_381_2) & 255;
  int stage_v_382_1 = ((stage_v_79_1 + pub_r000692_14_1) + 47) & 127;
  int stage_v_382_2 = ((stage_v_79_2 + pub_r000692_14_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_382_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_382_2) & 255;
  int stage_v_383_1 = ((stage_v_142_1 + pub_r000692_10_1) + 30) & 127;
  int stage_v_383_2 = ((stage_v_142_2 + pub_r000692_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_383_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_383_2) & 255;
  int stage_v_384_1 = ((stage_v_367_1 + pub_r000692_10_1) + 43) & 127;
  int stage_v_384_2 = ((stage_v_367_2 + pub_r000692_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_384_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_384_2) & 255;
  int stage_v_385_1 = ((stage_v_177_1 + pub_r000692_1_1) + 24) & 127;
  int stage_v_385_2 = ((stage_v_177_2 + pub_r000692_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_385_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_385_2) & 255;
  int stage_v_386_1 = ((stage_v_94_1 + pub_r000692_14_1) + 26) & 127;
  int stage_v_386_2 = ((stage_v_94_2 + pub_r000692_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_386_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_386_2) & 255;
  int stage_v_387_1 = ((stage_v_374_1 + pub_r000692_4_1) + 22) & 127;
  int stage_v_387_2 = ((stage_v_374_2 + pub_r000692_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_387_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_387_2) & 255;
  int stage_v_388_1 = ((stage_v_22_1 + pub_r000692_4_1) + 43) & 127;
  int stage_v_388_2 = ((stage_v_22_2 + pub_r000692_4_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_388_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_388_2) & 255;
  int stage_v_389_1 = ((stage_v_239_1 + pub_r000692_5_1) + 31) & 127;
  int stage_v_389_2 = ((stage_v_239_2 + pub_r000692_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_389_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_389_2) & 255;
  int stage_v_390_1 = ((stage_v_209_1 + pub_r000692_6_1) + 6) & 127;
  int stage_v_390_2 = ((stage_v_209_2 + pub_r000692_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_390_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_390_2) & 255;
  int stage_v_391_1 = ((sec_r000692_4_1 + pub_r000692_8_1) + 39) & 127;
  int stage_v_391_2 = ((sec_r000692_4_2 + pub_r000692_8_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_391_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_391_2) & 255;
  int stage_v_392_1 = ((sec_r000692_16_1 + pub_r000692_7_1) + 30) & 127;
  int stage_v_392_2 = ((sec_r000692_16_2 + pub_r000692_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_392_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_392_2) & 255;
  int stage_v_393_1 = ((sec_r000692_15_1 + pub_r000692_12_1) + 17) & 127;
  int stage_v_393_2 = ((sec_r000692_15_2 + pub_r000692_12_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_393_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_393_2) & 255;
  int stage_v_394_1 = ((stage_v_166_1 + pub_r000692_7_1) + 8) & 127;
  int stage_v_394_2 = ((stage_v_166_2 + pub_r000692_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_394_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_394_2) & 255;
  int stage_v_395_1 = ((stage_v_123_1 + pub_r000692_5_1) + 3) & 127;
  int stage_v_395_2 = ((stage_v_123_2 + pub_r000692_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_395_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_395_2) & 255;
  int stage_v_396_1 = ((stage_v_138_1 + pub_r000692_10_1) + 6) & 127;
  int stage_v_396_2 = ((stage_v_138_2 + pub_r000692_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_396_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_396_2) & 255;
  int stage_v_397_1 = ((stage_v_129_1 + pub_r000692_8_1) + 26) & 127;
  int stage_v_397_2 = ((stage_v_129_2 + pub_r000692_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_397_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_397_2) & 255;
  int stage_v_398_1 = ((stage_v_79_1 + pub_r000692_8_1) + 42) & 127;
  int stage_v_398_2 = ((stage_v_79_2 + pub_r000692_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_398_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_398_2) & 255;
  int stage_v_399_1 = ((stage_v_26_1 + pub_r000692_5_1) + 8) & 127;
  int stage_v_399_2 = ((stage_v_26_2 + pub_r000692_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_399_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_399_2) & 255;
  int stage_v_400_1 = ((stage_v_269_1 + pub_r000692_13_1) + 48) & 127;
  int stage_v_400_2 = ((stage_v_269_2 + pub_r000692_13_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_400_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_400_2) & 255;
  int stage_v_401_1 = ((stage_v_323_1 + pub_r000692_1_1) + 35) & 127;
  int stage_v_401_2 = ((stage_v_323_2 + pub_r000692_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_401_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_401_2) & 255;
  int stage_v_402_1 = ((stage_v_256_1 + pub_r000692_13_1) + 13) & 127;
  int stage_v_402_2 = ((stage_v_256_2 + pub_r000692_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_402_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_402_2) & 255;
  int stage_v_403_1 = ((sec_r000692_1_1 + pub_r000692_6_1) + 5) & 127;
  int stage_v_403_2 = ((sec_r000692_1_2 + pub_r000692_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_403_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_403_2) & 255;
  int stage_v_404_1 = ((sec_r000692_14_1 + pub_r000692_0_1) + 48) & 127;
  int stage_v_404_2 = ((sec_r000692_14_2 + pub_r000692_0_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_404_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_404_2) & 255;
  int stage_v_405_1 = ((stage_v_367_1 + pub_r000692_9_1) + 38) & 127;
  int stage_v_405_2 = ((stage_v_367_2 + pub_r000692_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_405_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_405_2) & 255;
  int stage_v_406_1 = ((stage_v_239_1 + pub_r000692_7_1) + 16) & 127;
  int stage_v_406_2 = ((stage_v_239_2 + pub_r000692_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_406_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_406_2) & 255;
  int stage_v_407_1 = ((stage_v_29_1 + pub_r000692_7_1) + 45) & 127;
  int stage_v_407_2 = ((stage_v_29_2 + pub_r000692_7_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_407_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_407_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_407_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_407_2) & 255;
  int stage_v_408_1 = ((sec_r000692_14_1 + pub_r000692_12_1) + 24) & 127;
  int stage_v_408_2 = ((sec_r000692_14_2 + pub_r000692_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_408_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_408_2) & 255;
  int stage_v_409_1 = ((stage_v_188_1 + pub_r000692_10_1) + 11) & 127;
  int stage_v_409_2 = ((stage_v_188_2 + pub_r000692_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_409_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_409_2) & 255;
  int stage_v_410_1 = ((stage_v_142_1 + pub_r000692_16_1) + 44) & 127;
  int stage_v_410_2 = ((stage_v_142_2 + pub_r000692_16_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_410_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_410_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_410_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_410_2) & 255;
  int stage_v_411_1 = ((sec_r000692_3_1 + pub_r000692_5_1) + 26) & 127;
  int stage_v_411_2 = ((sec_r000692_3_2 + pub_r000692_5_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_411_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_411_2) & 255;
  int stage_v_412_1 = ((stage_v_383_1 + pub_r000692_5_1) + 27) & 127;
  int stage_v_412_2 = ((stage_v_383_2 + pub_r000692_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_412_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_412_2) & 255;
  int stage_v_413_1 = ((sec_r000692_4_1 + pub_r000692_6_1) + 19) & 127;
  int stage_v_413_2 = ((sec_r000692_4_2 + pub_r000692_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_413_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_413_2) & 255;
  int stage_v_414_1 = ((sec_r000692_7_1 + pub_r000692_0_1) + 13) & 127;
  int stage_v_414_2 = ((sec_r000692_7_2 + pub_r000692_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_414_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_414_2) & 255;
  int stage_v_415_1 = ((sec_r000692_5_1 + pub_r000692_8_1) + 19) & 127;
  int stage_v_415_2 = ((sec_r000692_5_2 + pub_r000692_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_415_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_415_2) & 255;
  int stage_v_416_1 = ((sec_r000692_4_1 + pub_r000692_7_1) + 30) & 127;
  int stage_v_416_2 = ((sec_r000692_4_2 + pub_r000692_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_416_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_416_2) & 255;
  int stage_v_417_1 = ((stage_v_179_1 + pub_r000692_1_1) + 22) & 127;
  int stage_v_417_2 = ((stage_v_179_2 + pub_r000692_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_417_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_417_2) & 255;
  int stage_v_418_1 = ((stage_v_318_1 + pub_r000692_7_1) + 5) & 127;
  int stage_v_418_2 = ((stage_v_318_2 + pub_r000692_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_418_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_418_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_418_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_418_2) & 255;
  int stage_v_419_1 = ((sec_r000692_14_1 + pub_r000692_15_1) + 20) & 127;
  int stage_v_419_2 = ((sec_r000692_14_2 + pub_r000692_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_419_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_419_2) & 255;
  int stage_v_420_1 = ((stage_v_340_1 + pub_r000692_8_1) + 16) & 127;
  int stage_v_420_2 = ((stage_v_340_2 + pub_r000692_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_420_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_420_2) & 255;
  int stage_v_421_1 = ((stage_v_66_1 + pub_r000692_14_1) + 44) & 127;
  int stage_v_421_2 = ((stage_v_66_2 + pub_r000692_14_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_421_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_421_2) & 255;
  int stage_v_422_1 = ((sec_r000692_6_1 + pub_r000692_5_1) + 48) & 127;
  int stage_v_422_2 = ((sec_r000692_6_2 + pub_r000692_5_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_422_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_422_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_422_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_422_2) & 255;
  int stage_v_423_1 = ((sec_r000692_14_1 + pub_r000692_10_1) + 17) & 127;
  int stage_v_423_2 = ((sec_r000692_14_2 + pub_r000692_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_423_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_423_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_423_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_423_2) & 255;
  int stage_v_424_1 = ((sec_r000692_15_1 + pub_r000692_13_1) + 39) & 127;
  int stage_v_424_2 = ((sec_r000692_15_2 + pub_r000692_13_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_424_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_424_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_424_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_424_2) & 255;
  int stage_v_425_1 = ((stage_v_41_1 + pub_r000692_14_1) + 16) & 127;
  int stage_v_425_2 = ((stage_v_41_2 + pub_r000692_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_425_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_425_2) & 255;
  int stage_v_426_1 = ((stage_v_323_1 + pub_r000692_3_1) + 33) & 127;
  int stage_v_426_2 = ((stage_v_323_2 + pub_r000692_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_426_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_426_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_426_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_426_2) & 255;
  int stage_v_427_1 = ((stage_v_231_1 + pub_r000692_3_1) + 8) & 127;
  int stage_v_427_2 = ((stage_v_231_2 + pub_r000692_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_427_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_427_2) & 255;
  int stage_v_428_1 = ((sec_r000692_9_1 + pub_r000692_11_1) + 47) & 127;
  int stage_v_428_2 = ((sec_r000692_9_2 + pub_r000692_11_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_428_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_428_2) & 255;
  int stage_v_429_1 = ((sec_r000692_5_1 + pub_r000692_2_1) + 5) & 127;
  int stage_v_429_2 = ((sec_r000692_5_2 + pub_r000692_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_429_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_429_2) & 255;
  int stage_v_430_1 = ((sec_r000692_17_1 + pub_r000692_7_1) + 36) & 127;
  int stage_v_430_2 = ((sec_r000692_17_2 + pub_r000692_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_430_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_430_2) & 255;
  int stage_v_431_1 = ((sec_r000692_12_1 + pub_r000692_10_1) + 47) & 127;
  int stage_v_431_2 = ((sec_r000692_12_2 + pub_r000692_10_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_431_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_431_2) & 255;
  int stage_v_432_1 = ((sec_r000692_7_1 + pub_r000692_12_1) + 43) & 127;
  int stage_v_432_2 = ((sec_r000692_7_2 + pub_r000692_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_432_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_432_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000692_7_1 == pub_r000692_7_2);
  __CPROVER_assume(sec_r000692_2_1 != sec_r000692_2_2);
  __CPROVER_assume(pub_r000692_1_1 == pub_r000692_1_2);
  __CPROVER_assume(sec_r000692_4_1 != sec_r000692_4_2);
  __CPROVER_assume(pub_r000692_8_1 == pub_r000692_8_2);
  __CPROVER_assume(pub_r000692_10_1 == pub_r000692_10_2);
  __CPROVER_assume(sec_r000692_5_1 != sec_r000692_5_2);
  __CPROVER_assume(sec_r000692_0_1 != sec_r000692_0_2);
  __CPROVER_assume(pub_r000692_4_1 == pub_r000692_4_2);
  __CPROVER_assume(sec_r000692_6_1 != sec_r000692_6_2);
  __CPROVER_assume(pub_r000692_11_1 == pub_r000692_11_2);
  __CPROVER_assume(pub_r000692_9_1 == pub_r000692_9_2);
  __CPROVER_assume(sec_r000692_11_1 != sec_r000692_11_2);
  __CPROVER_assume(pub_r000692_2_1 == pub_r000692_2_2);
  __CPROVER_assume(pub_r000692_14_1 == pub_r000692_14_2);
  __CPROVER_assume(sec_r000692_8_1 != sec_r000692_8_2);
  __CPROVER_assume(sec_r000692_16_1 != sec_r000692_16_2);
  __CPROVER_assume(sec_r000692_9_1 != sec_r000692_9_2);
  __CPROVER_assume(sec_r000692_12_1 != sec_r000692_12_2);
  __CPROVER_assume(sec_r000692_17_1 != sec_r000692_17_2);
  __CPROVER_assume(pub_r000692_0_1 == pub_r000692_0_2);
  __CPROVER_assume(sec_r000692_3_1 != sec_r000692_3_2);
  __CPROVER_assume(sec_r000692_10_1 != sec_r000692_10_2);
  __CPROVER_assume(pub_r000692_5_1 == pub_r000692_5_2);
  __CPROVER_assume(pub_r000692_16_1 == pub_r000692_16_2);
  __CPROVER_assume(pub_r000692_12_1 == pub_r000692_12_2);
  __CPROVER_assume(pub_r000692_15_1 == pub_r000692_15_2);
  __CPROVER_assume(sec_r000692_15_1 != sec_r000692_15_2);
  __CPROVER_assume(sec_r000692_13_1 != sec_r000692_13_2);
  __CPROVER_assume(sec_r000692_1_1 != sec_r000692_1_2);
  __CPROVER_assume(pub_r000692_6_1 == pub_r000692_6_2);
  __CPROVER_assume(sec_r000692_14_1 != sec_r000692_14_2);
  __CPROVER_assume(sec_r000692_7_1 != sec_r000692_7_2);
  __CPROVER_assume(pub_r000692_13_1 == pub_r000692_13_2);
  __CPROVER_assume(pub_r000692_3_1 == pub_r000692_3_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
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
}


