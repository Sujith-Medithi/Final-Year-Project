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
struct DeviceConfig_R001033_3313_0
{
  int port;
  unsigned char stop_bits;
  short parity;
  int buffer[3];
};
struct MatrixBlock_R001033_3313_1
{
  short density;
  unsigned char stride;
  short determinant;
  int buffer[3];
};
union TelemetryField_R001033_3313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R001033_3313_1
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
void fn_R001033_3313_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st_1 = {0};
  struct DeviceConfig_R001033_3313_0 st_2 = {0};
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
  int anchor_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_46_1)
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

  switch (anchor_46_2)
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
  int phase_96_1 = local_arr_1[aux_1 % 3];
  int phase_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_96_2 * 2)) & 127;
  int quantum_93_1 = 0;
  int quantum_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_93_1 = ((quantum_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_93_2 = ((quantum_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_93_1) & 127;
    acc_2 = (acc_2 + quantum_93_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_46_1 == anchor_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_96_1 == phase_96_2);
  assert(quantum_93_1 == quantum_93_2);
}

int fn_R001033_3313_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_46 = (aux + st.buffer[1]) & 3;
  switch (anchor_46)
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
  int phase_96 = local_arr[aux % 3];
  acc = (acc + (phase_96 * 2)) & 127;
  int quantum_93 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_93 = ((quantum_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_93) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001033_3313_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st_1 = {0};
  struct MatrixBlock_R001033_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_95_1 = 0;
  int parity_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_95_1 = ((parity_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_95_2 = ((parity_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_95_1) & 127;
    acc_2 = (acc_2 + parity_95_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_95_1 == parity_95_2);
}

int fn_R001033_3313_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_95 = ((parity_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_95) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001033_3313_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st_1 = {0};
  struct MatrixBlock_R001033_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int mask_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_33_1)
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

  switch (mask_33_2)
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

  int vector_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_85_1 > 32)
  {
    acc_1 = ((acc_1 + (vector_85_1 * 2)) + 5) & 127;
    aux_1 ^= vector_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_85_2 > 32)
  {
    acc_2 = ((acc_2 + (vector_85_2 * 2)) + 5) & 127;
    aux_2 ^= vector_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_37_1 = local_arr_1[aux_1 % 3];
  int cursor_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_37_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_33_1 == mask_33_2);
  assert(vector_85_1 == vector_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_37_1 == cursor_37_2);
}

int fn_R001033_3313_2(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int mask_33 = (aux + st.buffer[1]) & 3;
  switch (mask_33)
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

  int vector_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_85 > 32)
  {
    acc = ((acc + (vector_85 * 2)) + 5) & 127;
    aux ^= vector_85 & 15;
  }
  else
  {
    acc = ((acc - vector_85) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_37 = local_arr[aux % 3];
  acc = (acc + (cursor_37 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001033_3313_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st_1 = {0};
  struct DeviceConfig_R001033_3313_0 st_2 = {0};
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
  int margin_28_1 = 0;
  int margin_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_28_1 = ((margin_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_28_2 = ((margin_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_28_1) & 127;
    acc_2 = (acc_2 + margin_28_2) & 127;
  }

  int bound_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_86_1)
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

  switch (bound_86_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_28_1 == margin_28_2);
  assert(bound_86_1 == bound_86_2);
}

int fn_R001033_3313_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_28 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_28 = ((margin_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_28) & 127;
  }

  int bound_86 = (aux + st.buffer[1]) & 3;
  switch (bound_86)
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

void fn_R001033_3313_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st_1 = {0};
  struct DeviceConfig_R001033_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_48_1 = local_arr_1[aux_1 % 3];
  int damping_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_48_2 * 2)) & 127;
  int quotient_46_1 = 0;
  int quotient_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_46_1 = ((quotient_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_46_2 = ((quotient_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_46_1) & 127;
    acc_2 = (acc_2 + quotient_46_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_48_1 == damping_48_2);
  assert(quotient_46_1 == quotient_46_2);
}

int fn_R001033_3313_4(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int damping_48 = local_arr[aux % 3];
  acc = (acc + (damping_48 * 2)) & 127;
  int quotient_46 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_46 = ((quotient_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_46) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001033_3313_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st_1 = {0};
  struct DeviceConfig_R001033_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_61_1 = local_arr_1[aux_1 % 3];
  int checksum_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_61_2 * 2)) & 127;
  int damping_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_59_1)
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

  switch (damping_59_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_61_1 == checksum_61_2);
  assert(damping_59_1 == damping_59_2);
}

int fn_R001033_3313_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int checksum_61 = local_arr[aux % 3];
  acc = (acc + (checksum_61 * 2)) & 127;
  int damping_59 = (aux + st.buffer[1]) & 3;
  switch (damping_59)
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

void fn_R001033_3313_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st_1 = {0};
  struct DeviceConfig_R001033_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int residue_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_54_1) & 63;
  aux_2 = (aux_2 + residue_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_43_1)
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

  switch (mask_43_2)
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
  int parity_76_1 = local_arr_1[aux_1 % 3];
  int parity_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_76_2 * 2)) & 127;
  int tracker_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_48_1 > 42)
  {
    acc_1 = ((acc_1 + (tracker_48_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_48_2 > 42)
  {
    acc_2 = ((acc_2 + (tracker_48_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_48_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_54_1 == residue_54_2);
  assert(mask_43_1 == mask_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_76_1 == parity_76_2);
  assert(tracker_48_1 == tracker_48_2);
}

int fn_R001033_3313_6(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int residue_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_54) & 63;
  acc ^= aux;
  int mask_43 = (aux + st.buffer[1]) & 3;
  switch (mask_43)
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
  int parity_76 = local_arr[aux % 3];
  acc = (acc + (parity_76 * 2)) & 127;
  int tracker_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_48 > 42)
  {
    acc = ((acc + (tracker_48 * 2)) + 5) & 127;
    aux ^= tracker_48 & 15;
  }
  else
  {
    acc = ((acc - tracker_48) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001033_3313_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st_1 = {0};
  struct MatrixBlock_R001033_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int segment_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_30_1) & 63;
  aux_2 = (aux_2 + segment_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_30_1 == segment_30_2);
}

int fn_R001033_3313_7(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int segment_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_30) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001033_3313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st_1 = {0};
  struct MatrixBlock_R001033_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int bound_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_53_1)
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

  switch (bound_53_2)
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

  int margin_28_1 = 0;
  int margin_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_28_1 = ((margin_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_28_2 = ((margin_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_28_1) & 127;
    acc_2 = (acc_2 + margin_28_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_53_1 == bound_53_2);
  assert(margin_28_1 == margin_28_2);
}

int fn_R001033_3313_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int bound_53 = (aux + st.buffer[1]) & 3;
  switch (bound_53)
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

  int margin_28 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_28 = ((margin_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_28) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001033_3313_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st_1 = {0};
  struct MatrixBlock_R001033_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int pivot_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_84_1 > 19)
  {
    acc_1 = ((acc_1 + (pivot_84_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_84_2 > 19)
  {
    acc_2 = ((acc_2 + (pivot_84_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_84_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_76_1 = local_arr_1[aux_1 % 3];
  int metric_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_76_2 * 2)) & 127;
  int sample_79_1 = 0;
  int sample_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_79_1 = ((sample_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_79_2 = ((sample_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_79_1) & 127;
    acc_2 = (acc_2 + sample_79_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_84_1 == pivot_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_76_1 == metric_76_2);
  assert(sample_79_1 == sample_79_2);
}

int fn_R001033_3313_9(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int pivot_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_84 > 19)
  {
    acc = ((acc + (pivot_84 * 2)) + 5) & 127;
    aux ^= pivot_84 & 15;
  }
  else
  {
    acc = ((acc - pivot_84) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_76 = local_arr[aux % 3];
  acc = (acc + (metric_76 * 2)) & 127;
  int sample_79 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_79 = ((sample_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_79) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001033_3313_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st_1 = {0};
  struct MatrixBlock_R001033_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_24_1)
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

  switch (pivot_24_2)
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

  int index_reg_31_1 = 0;
  int index_reg_31_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_31_1 = ((index_reg_31_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_31_2 = ((index_reg_31_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_31_1) & 127;
    acc_2 = (acc_2 + index_reg_31_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_24_1 == pivot_24_2);
  assert(index_reg_31_1 == index_reg_31_2);
}

int fn_R001033_3313_10(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_24 = (aux + st.buffer[1]) & 3;
  switch (pivot_24)
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

  int index_reg_31 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_31 = ((index_reg_31 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_31) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001033_3313_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st_1 = {0};
  struct MatrixBlock_R001033_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int offset_77_1 = 0;
  int offset_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_77_1 = ((offset_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_77_2 = ((offset_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_77_1) & 127;
    acc_2 = (acc_2 + offset_77_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_41_1)
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

  switch (anchor_41_2)
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
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_77_1 == offset_77_2);
  assert(anchor_41_1 == anchor_41_2);
}

int fn_R001033_3313_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int offset_77 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_77 = ((offset_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_77) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_41 = (aux + st.buffer[1]) & 3;
  switch (anchor_41)
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

void fn_R001033_3313_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st_1 = {0};
  struct DeviceConfig_R001033_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int mask_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_86_1)
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

  switch (mask_86_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_66_1 = local_arr_1[aux_1 % 3];
  int phase_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_66_2 * 2)) & 127;
  int segment_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_32_1) & 63;
  aux_2 = (aux_2 + segment_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_86_1 == mask_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_66_1 == phase_66_2);
  assert(segment_32_1 == segment_32_2);
}

int fn_R001033_3313_12(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int mask_86 = (aux + st.buffer[1]) & 3;
  switch (mask_86)
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

  int local_arr[3] = {4, 9, 15};
  int phase_66 = local_arr[aux % 3];
  acc = (acc + (phase_66 * 2)) & 127;
  int segment_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_32) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001033_3313_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st_1 = {0};
  struct MatrixBlock_R001033_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int checksum_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_82_1)
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

  switch (checksum_82_2)
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

  int window_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_10_1 > 30)
  {
    acc_1 = ((acc_1 + (window_10_1 * 2)) + 5) & 127;
    aux_1 ^= window_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_10_2 > 30)
  {
    acc_2 = ((acc_2 + (window_10_2 * 2)) + 5) & 127;
    aux_2 ^= window_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_10_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_86_1) & 63;
  aux_2 = (aux_2 + tracker_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_82_1 == checksum_82_2);
  assert(window_10_1 == window_10_2);
  assert(tracker_86_1 == tracker_86_2);
}

int fn_R001033_3313_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int checksum_82 = (aux + st.buffer[1]) & 3;
  switch (checksum_82)
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

  int window_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_10 > 30)
  {
    acc = ((acc + (window_10 * 2)) + 5) & 127;
    aux ^= window_10 & 15;
  }
  else
  {
    acc = ((acc - window_10) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001033_3313_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st_1 = {0};
  struct MatrixBlock_R001033_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_19_1)
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

  switch (segment_19_2)
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

  int margin_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_36_1 > 16)
  {
    acc_1 = ((acc_1 + (margin_36_1 * 2)) + 5) & 127;
    aux_1 ^= margin_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_36_2 > 16)
  {
    acc_2 = ((acc_2 + (margin_36_2 * 2)) + 5) & 127;
    aux_2 ^= margin_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_36_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_19_1 == segment_19_2);
  assert(margin_36_1 == margin_36_2);
}

int fn_R001033_3313_14(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001033_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_19 = (aux + st.buffer[1]) & 3;
  switch (segment_19)
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

  int margin_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_36 > 16)
  {
    acc = ((acc + (margin_36 * 2)) + 5) & 127;
    aux ^= margin_36 & 15;
  }
  else
  {
    acc = ((acc - margin_36) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001033_3313_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st_1 = {0};
  struct DeviceConfig_R001033_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int anchor_78_1 = 0;
  int anchor_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_78_1 = ((anchor_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_78_2 = ((anchor_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_78_1) & 127;
    acc_2 = (acc_2 + anchor_78_2) & 127;
  }

  int phase_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_77_1) & 63;
  aux_2 = (aux_2 + phase_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_57_1 = local_arr_1[aux_1 % 3];
  int sample_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_57_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_78_1 == anchor_78_2);
  assert(phase_77_1 == phase_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_57_1 == sample_57_2);
}

int fn_R001033_3313_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int anchor_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_78 = ((anchor_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_78) & 127;
  }

  int phase_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_77) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_57 = local_arr[aux % 3];
  acc = (acc + (sample_57 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001033_3313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st_1 = {0};
  struct DeviceConfig_R001033_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int quotient_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_31_1)
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

  switch (quotient_31_2)
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

  int checksum_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_48_1) & 63;
  aux_2 = (aux_2 + checksum_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_68_1 > 12)
  {
    acc_1 = ((acc_1 + (cursor_68_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_68_2 > 12)
  {
    acc_2 = ((acc_2 + (cursor_68_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_68_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_31_1 == quotient_31_2);
  assert(checksum_48_1 == checksum_48_2);
  assert(cursor_68_1 == cursor_68_2);
}

int fn_R001033_3313_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001033_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int quotient_31 = (aux + st.buffer[1]) & 3;
  switch (quotient_31)
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

  int checksum_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_48) & 63;
  acc ^= aux;
  int cursor_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_68 > 12)
  {
    acc = ((acc + (cursor_68 * 2)) + 5) & 127;
    aux ^= cursor_68 & 15;
  }
  else
  {
    acc = ((acc - cursor_68) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001033_0_1;
  int sec_r001033_0_2;
  int sec_r001033_1_1;
  int sec_r001033_1_2;
  int sec_r001033_2_1;
  int sec_r001033_2_2;
  int sec_r001033_3_1;
  int sec_r001033_3_2;
  int sec_r001033_4_1;
  int sec_r001033_4_2;
  int sec_r001033_5_1;
  int sec_r001033_5_2;
  int sec_r001033_6_1;
  int sec_r001033_6_2;
  int sec_r001033_7_1;
  int sec_r001033_7_2;
  int sec_r001033_8_1;
  int sec_r001033_8_2;
  int sec_r001033_9_1;
  int sec_r001033_9_2;
  int sec_r001033_10_1;
  int sec_r001033_10_2;
  int sec_r001033_11_1;
  int sec_r001033_11_2;
  int sec_r001033_12_1;
  int sec_r001033_12_2;
  int sec_r001033_13_1;
  int sec_r001033_13_2;
  int sec_r001033_14_1;
  int sec_r001033_14_2;
  int sec_r001033_15_1;
  int sec_r001033_15_2;
  int sec_r001033_16_1;
  int sec_r001033_16_2;
  int sec_r001033_17_1;
  int sec_r001033_17_2;
  int sec_r001033_18_1;
  int sec_r001033_18_2;
  int sec_r001033_19_1;
  int sec_r001033_19_2;
  int sec_r001033_20_1;
  int sec_r001033_20_2;
  int pub_r001033_0_1;
  int pub_r001033_0_2;
  int pub_r001033_1_1;
  int pub_r001033_1_2;
  int pub_r001033_2_1;
  int pub_r001033_2_2;
  int pub_r001033_3_1;
  int pub_r001033_3_2;
  int pub_r001033_4_1;
  int pub_r001033_4_2;
  int pub_r001033_5_1;
  int pub_r001033_5_2;
  int pub_r001033_6_1;
  int pub_r001033_6_2;
  int pub_r001033_7_1;
  int pub_r001033_7_2;
  int pub_r001033_8_1;
  int pub_r001033_8_2;
  int pub_r001033_9_1;
  int pub_r001033_9_2;
  int pub_r001033_10_1;
  int pub_r001033_10_2;
  int pub_r001033_11_1;
  int pub_r001033_11_2;
  int pub_r001033_12_1;
  int pub_r001033_12_2;
  int pub_r001033_13_1;
  int pub_r001033_13_2;
  int pub_r001033_14_1;
  int pub_r001033_14_2;
  int pub_r001033_15_1;
  int pub_r001033_15_2;
  int pub_r001033_16_1;
  int pub_r001033_16_2;
  int pub_r001033_17_1;
  int pub_r001033_17_2;
  int pub_r001033_18_1;
  int pub_r001033_18_2;
  int pub_r001033_19_1;
  int pub_r001033_19_2;
  int pub_r001033_20_1;
  int pub_r001033_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001033_0_1 >= (-100)) && (pub_r001033_0_1 <= 100));
  __CPROVER_assume((pub_r001033_0_2 >= (-100)) && (pub_r001033_0_2 <= 100));
  __CPROVER_assume((pub_r001033_1_1 >= (-100)) && (pub_r001033_1_1 <= 100));
  __CPROVER_assume((pub_r001033_1_2 >= (-100)) && (pub_r001033_1_2 <= 100));
  __CPROVER_assume((pub_r001033_2_1 >= (-100)) && (pub_r001033_2_1 <= 100));
  __CPROVER_assume((pub_r001033_2_2 >= (-100)) && (pub_r001033_2_2 <= 100));
  __CPROVER_assume((pub_r001033_3_1 >= (-100)) && (pub_r001033_3_1 <= 100));
  __CPROVER_assume((pub_r001033_3_2 >= (-100)) && (pub_r001033_3_2 <= 100));
  __CPROVER_assume((pub_r001033_4_1 >= (-100)) && (pub_r001033_4_1 <= 100));
  __CPROVER_assume((pub_r001033_4_2 >= (-100)) && (pub_r001033_4_2 <= 100));
  __CPROVER_assume((pub_r001033_5_1 >= (-100)) && (pub_r001033_5_1 <= 100));
  __CPROVER_assume((pub_r001033_5_2 >= (-100)) && (pub_r001033_5_2 <= 100));
  __CPROVER_assume((pub_r001033_6_1 >= (-100)) && (pub_r001033_6_1 <= 100));
  __CPROVER_assume((pub_r001033_6_2 >= (-100)) && (pub_r001033_6_2 <= 100));
  __CPROVER_assume((pub_r001033_7_1 >= (-100)) && (pub_r001033_7_1 <= 100));
  __CPROVER_assume((pub_r001033_7_2 >= (-100)) && (pub_r001033_7_2 <= 100));
  __CPROVER_assume((pub_r001033_8_1 >= (-100)) && (pub_r001033_8_1 <= 100));
  __CPROVER_assume((pub_r001033_8_2 >= (-100)) && (pub_r001033_8_2 <= 100));
  __CPROVER_assume((pub_r001033_9_1 >= (-100)) && (pub_r001033_9_1 <= 100));
  __CPROVER_assume((pub_r001033_9_2 >= (-100)) && (pub_r001033_9_2 <= 100));
  __CPROVER_assume((pub_r001033_10_1 >= (-100)) && (pub_r001033_10_1 <= 100));
  __CPROVER_assume((pub_r001033_10_2 >= (-100)) && (pub_r001033_10_2 <= 100));
  __CPROVER_assume((pub_r001033_11_1 >= (-100)) && (pub_r001033_11_1 <= 100));
  __CPROVER_assume((pub_r001033_11_2 >= (-100)) && (pub_r001033_11_2 <= 100));
  __CPROVER_assume((pub_r001033_12_1 >= (-100)) && (pub_r001033_12_1 <= 100));
  __CPROVER_assume((pub_r001033_12_2 >= (-100)) && (pub_r001033_12_2 <= 100));
  __CPROVER_assume((pub_r001033_13_1 >= (-100)) && (pub_r001033_13_1 <= 100));
  __CPROVER_assume((pub_r001033_13_2 >= (-100)) && (pub_r001033_13_2 <= 100));
  __CPROVER_assume((pub_r001033_14_1 >= (-100)) && (pub_r001033_14_1 <= 100));
  __CPROVER_assume((pub_r001033_14_2 >= (-100)) && (pub_r001033_14_2 <= 100));
  __CPROVER_assume((pub_r001033_15_1 >= (-100)) && (pub_r001033_15_1 <= 100));
  __CPROVER_assume((pub_r001033_15_2 >= (-100)) && (pub_r001033_15_2 <= 100));
  __CPROVER_assume((pub_r001033_16_1 >= (-100)) && (pub_r001033_16_1 <= 100));
  __CPROVER_assume((pub_r001033_16_2 >= (-100)) && (pub_r001033_16_2 <= 100));
  __CPROVER_assume((pub_r001033_17_1 >= (-100)) && (pub_r001033_17_1 <= 100));
  __CPROVER_assume((pub_r001033_17_2 >= (-100)) && (pub_r001033_17_2 <= 100));
  __CPROVER_assume((pub_r001033_18_1 >= (-100)) && (pub_r001033_18_1 <= 100));
  __CPROVER_assume((pub_r001033_18_2 >= (-100)) && (pub_r001033_18_2 <= 100));
  __CPROVER_assume((pub_r001033_19_1 >= (-100)) && (pub_r001033_19_1 <= 100));
  __CPROVER_assume((pub_r001033_19_2 >= (-100)) && (pub_r001033_19_2 <= 100));
  __CPROVER_assume((pub_r001033_20_1 >= (-100)) && (pub_r001033_20_1 <= 100));
  __CPROVER_assume((pub_r001033_20_2 >= (-100)) && (pub_r001033_20_2 <= 100));
  __CPROVER_assume((sec_r001033_0_1 >= 0) && (sec_r001033_0_1 <= 255));
  __CPROVER_assume((sec_r001033_0_2 >= 0) && (sec_r001033_0_2 <= 255));
  __CPROVER_assume((sec_r001033_1_1 >= 0) && (sec_r001033_1_1 <= 255));
  __CPROVER_assume((sec_r001033_1_2 >= 0) && (sec_r001033_1_2 <= 255));
  __CPROVER_assume((sec_r001033_2_1 >= 0) && (sec_r001033_2_1 <= 255));
  __CPROVER_assume((sec_r001033_2_2 >= 0) && (sec_r001033_2_2 <= 255));
  __CPROVER_assume((sec_r001033_3_1 >= 0) && (sec_r001033_3_1 <= 255));
  __CPROVER_assume((sec_r001033_3_2 >= 0) && (sec_r001033_3_2 <= 255));
  __CPROVER_assume((sec_r001033_4_1 >= 0) && (sec_r001033_4_1 <= 255));
  __CPROVER_assume((sec_r001033_4_2 >= 0) && (sec_r001033_4_2 <= 255));
  __CPROVER_assume((sec_r001033_5_1 >= 0) && (sec_r001033_5_1 <= 255));
  __CPROVER_assume((sec_r001033_5_2 >= 0) && (sec_r001033_5_2 <= 255));
  __CPROVER_assume((sec_r001033_6_1 >= 0) && (sec_r001033_6_1 <= 255));
  __CPROVER_assume((sec_r001033_6_2 >= 0) && (sec_r001033_6_2 <= 255));
  __CPROVER_assume((sec_r001033_7_1 >= 0) && (sec_r001033_7_1 <= 255));
  __CPROVER_assume((sec_r001033_7_2 >= 0) && (sec_r001033_7_2 <= 255));
  __CPROVER_assume((sec_r001033_8_1 >= 0) && (sec_r001033_8_1 <= 255));
  __CPROVER_assume((sec_r001033_8_2 >= 0) && (sec_r001033_8_2 <= 255));
  __CPROVER_assume((sec_r001033_9_1 >= 0) && (sec_r001033_9_1 <= 255));
  __CPROVER_assume((sec_r001033_9_2 >= 0) && (sec_r001033_9_2 <= 255));
  __CPROVER_assume((sec_r001033_10_1 >= 0) && (sec_r001033_10_1 <= 255));
  __CPROVER_assume((sec_r001033_10_2 >= 0) && (sec_r001033_10_2 <= 255));
  __CPROVER_assume((sec_r001033_11_1 >= 0) && (sec_r001033_11_1 <= 255));
  __CPROVER_assume((sec_r001033_11_2 >= 0) && (sec_r001033_11_2 <= 255));
  __CPROVER_assume((sec_r001033_12_1 >= 0) && (sec_r001033_12_1 <= 255));
  __CPROVER_assume((sec_r001033_12_2 >= 0) && (sec_r001033_12_2 <= 255));
  __CPROVER_assume((sec_r001033_13_1 >= 0) && (sec_r001033_13_1 <= 255));
  __CPROVER_assume((sec_r001033_13_2 >= 0) && (sec_r001033_13_2 <= 255));
  __CPROVER_assume((sec_r001033_14_1 >= 0) && (sec_r001033_14_1 <= 255));
  __CPROVER_assume((sec_r001033_14_2 >= 0) && (sec_r001033_14_2 <= 255));
  __CPROVER_assume((sec_r001033_15_1 >= 0) && (sec_r001033_15_1 <= 255));
  __CPROVER_assume((sec_r001033_15_2 >= 0) && (sec_r001033_15_2 <= 255));
  __CPROVER_assume((sec_r001033_16_1 >= 0) && (sec_r001033_16_1 <= 255));
  __CPROVER_assume((sec_r001033_16_2 >= 0) && (sec_r001033_16_2 <= 255));
  __CPROVER_assume((sec_r001033_17_1 >= 0) && (sec_r001033_17_1 <= 255));
  __CPROVER_assume((sec_r001033_17_2 >= 0) && (sec_r001033_17_2 <= 255));
  __CPROVER_assume((sec_r001033_18_1 >= 0) && (sec_r001033_18_1 <= 255));
  __CPROVER_assume((sec_r001033_18_2 >= 0) && (sec_r001033_18_2 <= 255));
  __CPROVER_assume((sec_r001033_19_1 >= 0) && (sec_r001033_19_1 <= 255));
  __CPROVER_assume((sec_r001033_19_2 >= 0) && (sec_r001033_19_2 <= 255));
  __CPROVER_assume((sec_r001033_20_1 >= 0) && (sec_r001033_20_1 <= 255));
  __CPROVER_assume((sec_r001033_20_2 >= 0) && (sec_r001033_20_2 <= 255));
  struct DeviceConfig_R001033_3313_0 st_var_0_1 = {0};
  struct DeviceConfig_R001033_3313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001033_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001033_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001033_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001033_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001033_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001033_0_2 + 7) & 15;
  struct MatrixBlock_R001033_3313_1 st_var_1_1 = {0};
  struct MatrixBlock_R001033_3313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001033_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001033_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001033_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001033_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001033_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001033_0_2 + 9) & 15;
  union TelemetryField_R001033_3313_0 u_var_1;
  union TelemetryField_R001033_3313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001033_3313_0(sec_r001033_0_1, sec_r001033_1_1, pub_r001033_2_1, pub_r001033_3_1, pub_r001033_4_1);
  int helper_flow_0_2 = fn_R001033_3313_0(sec_r001033_0_2, sec_r001033_1_2, pub_r001033_2_2, pub_r001033_3_2, pub_r001033_4_2);
  fn_R001033_3313_0_2(sec_r001033_0_1, sec_r001033_1_1, pub_r001033_2_1, pub_r001033_3_1, pub_r001033_4_1, sec_r001033_0_2, sec_r001033_1_2, pub_r001033_2_2, pub_r001033_3_2, pub_r001033_4_2);
  int helper_flow_1_1 = fn_R001033_3313_1(sec_r001033_1_1, sec_r001033_2_1, pub_r001033_3_1, pub_r001033_4_1);
  int helper_flow_1_2 = fn_R001033_3313_1(sec_r001033_1_2, sec_r001033_2_2, pub_r001033_3_2, pub_r001033_4_2);
  fn_R001033_3313_1_2(sec_r001033_1_1, sec_r001033_2_1, pub_r001033_3_1, pub_r001033_4_1, sec_r001033_1_2, sec_r001033_2_2, pub_r001033_3_2, pub_r001033_4_2);
  int helper_flow_2_1 = fn_R001033_3313_2(sec_r001033_2_1, sec_r001033_3_1, pub_r001033_4_1);
  int helper_flow_2_2 = fn_R001033_3313_2(sec_r001033_2_2, sec_r001033_3_2, pub_r001033_4_2);
  fn_R001033_3313_2_2(sec_r001033_2_1, sec_r001033_3_1, pub_r001033_4_1, sec_r001033_2_2, sec_r001033_3_2, pub_r001033_4_2);
  int helper_flow_3_1 = fn_R001033_3313_3(sec_r001033_3_1, pub_r001033_4_1, pub_r001033_5_1, pub_r001033_6_1, pub_r001033_7_1);
  int helper_flow_3_2 = fn_R001033_3313_3(sec_r001033_3_2, pub_r001033_4_2, pub_r001033_5_2, pub_r001033_6_2, pub_r001033_7_2);
  fn_R001033_3313_3_2(sec_r001033_3_1, pub_r001033_4_1, pub_r001033_5_1, pub_r001033_6_1, pub_r001033_7_1, sec_r001033_3_2, pub_r001033_4_2, pub_r001033_5_2, pub_r001033_6_2, pub_r001033_7_2);
  int helper_flow_4_1 = fn_R001033_3313_4(sec_r001033_4_1, sec_r001033_5_1);
  int helper_flow_4_2 = fn_R001033_3313_4(sec_r001033_4_2, sec_r001033_5_2);
  fn_R001033_3313_4_2(sec_r001033_4_1, sec_r001033_5_1, sec_r001033_4_2, sec_r001033_5_2);
  int helper_flow_5_1 = fn_R001033_3313_5(sec_r001033_5_1, sec_r001033_6_1, pub_r001033_7_1, pub_r001033_8_1, pub_r001033_9_1);
  int helper_flow_5_2 = fn_R001033_3313_5(sec_r001033_5_2, sec_r001033_6_2, pub_r001033_7_2, pub_r001033_8_2, pub_r001033_9_2);
  fn_R001033_3313_5_2(sec_r001033_5_1, sec_r001033_6_1, pub_r001033_7_1, pub_r001033_8_1, pub_r001033_9_1, sec_r001033_5_2, sec_r001033_6_2, pub_r001033_7_2, pub_r001033_8_2, pub_r001033_9_2);
  int stage_v_0_1 = (((sec_r001033_11_1 * 3) + pub_r001033_12_1) + 7) & 127;
  int stage_v_0_2 = (((sec_r001033_11_2 * 3) + pub_r001033_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = ((pub_r001033_6_1 * 2) + 41) & 63;
  int stage_v_1_2 = ((pub_r001033_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((helper_flow_0_1 * 3) + pub_r001033_15_1) + 12) & 127;
  int stage_v_2_2 = (((helper_flow_0_2 * 3) + pub_r001033_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = ((pub_r001033_16_1 * 2) + 22) & 63;
  int stage_v_3_2 = ((pub_r001033_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001033_15_1 * 2) + 25) & 63;
  int stage_v_4_2 = ((pub_r001033_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((sec_r001033_11_1 * 3) + pub_r001033_20_1) + 10) & 127;
  int stage_v_5_2 = (((sec_r001033_11_2 * 3) + pub_r001033_20_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = (((stage_v_2_1 * 3) + pub_r001033_19_1) + 27) & 127;
  int stage_v_6_2 = (((stage_v_2_2 * 3) + pub_r001033_19_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = (((sec_r001033_12_1 * 3) + pub_r001033_5_1) + 42) & 127;
  int stage_v_7_2 = (((sec_r001033_12_2 * 3) + pub_r001033_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001033_15_1 * 2) + 35) & 63;
  int stage_v_8_2 = ((pub_r001033_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (((helper_flow_3_1 * 3) + pub_r001033_10_1) + 44) & 127;
  int stage_v_9_2 = (((helper_flow_3_2 * 3) + pub_r001033_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = (((stage_v_7_1 * 3) + pub_r001033_11_1) + 33) & 127;
  int stage_v_10_2 = (((stage_v_7_2 * 3) + pub_r001033_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001033_4_1 * 2) + 24) & 63;
  int stage_v_11_2 = ((pub_r001033_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001033_0_1 * 2) + 48) & 63;
  int stage_v_12_2 = ((pub_r001033_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((sec_r001033_14_1 * 3) + pub_r001033_15_1) + 21) & 127;
  int stage_v_13_2 = (((sec_r001033_14_2 * 3) + pub_r001033_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = (((sec_r001033_12_1 * 3) + pub_r001033_3_1) + 21) & 127;
  int stage_v_14_2 = (((sec_r001033_12_2 * 3) + pub_r001033_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = ((pub_r001033_20_1 * 2) + 11) & 63;
  int stage_v_15_2 = ((pub_r001033_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001033_14_1 * 2) + 33) & 63;
  int stage_v_16_2 = ((pub_r001033_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001033_9_1 * 2) + 9) & 63;
  int stage_v_17_2 = ((pub_r001033_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001033_13_1 * 2) + 14) & 63;
  int stage_v_18_2 = ((pub_r001033_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001033_20_1 * 2) + 31) & 63;
  int stage_v_19_2 = ((pub_r001033_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001033_10_1 * 2) + 43) & 63;
  int stage_v_20_2 = ((pub_r001033_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((helper_flow_4_1 * 3) + pub_r001033_6_1) + 36) & 127;
  int stage_v_21_2 = (((helper_flow_4_2 * 3) + pub_r001033_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = ((pub_r001033_2_1 * 2) + 20) & 63;
  int stage_v_22_2 = ((pub_r001033_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((sec_r001033_13_1 * 3) + pub_r001033_15_1) + 32) & 127;
  int stage_v_23_2 = (((sec_r001033_13_2 * 3) + pub_r001033_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((sec_r001033_16_1 * 3) + pub_r001033_3_1) + 38) & 127;
  int stage_v_24_2 = (((sec_r001033_16_2 * 3) + pub_r001033_3_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = ((pub_r001033_15_1 * 2) + 16) & 63;
  int stage_v_25_2 = ((pub_r001033_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((sec_r001033_8_1 * 3) + pub_r001033_12_1) + 15) & 127;
  int stage_v_26_2 = (((sec_r001033_8_2 * 3) + pub_r001033_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = ((pub_r001033_12_1 * 2) + 17) & 63;
  int stage_v_27_2 = ((pub_r001033_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((sec_r001033_5_1 * 3) + pub_r001033_1_1) + 37) & 127;
  int stage_v_28_2 = (((sec_r001033_5_2 * 3) + pub_r001033_1_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = (((sec_r001033_1_1 * 3) + pub_r001033_20_1) + 44) & 127;
  int stage_v_29_2 = (((sec_r001033_1_2 * 3) + pub_r001033_20_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = ((pub_r001033_9_1 * 2) + 9) & 63;
  int stage_v_30_2 = ((pub_r001033_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001033_17_1 * 2) + 20) & 63;
  int stage_v_31_2 = ((pub_r001033_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001033_20_1 * 2) + 15) & 63;
  int stage_v_32_2 = ((pub_r001033_20_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((helper_flow_4_1 * 3) + pub_r001033_16_1) + 25) & 127;
  int stage_v_33_2 = (((helper_flow_4_2 * 3) + pub_r001033_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = ((pub_r001033_3_1 * 2) + 28) & 63;
  int stage_v_34_2 = ((pub_r001033_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001033_1_1 * 2) + 45) & 63;
  int stage_v_35_2 = ((pub_r001033_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001033_3_1 * 2) + 14) & 63;
  int stage_v_36_2 = ((pub_r001033_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((sec_r001033_19_1 * 3) + pub_r001033_11_1) + 33) & 127;
  int stage_v_37_2 = (((sec_r001033_19_2 * 3) + pub_r001033_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = ((pub_r001033_4_1 * 2) + 28) & 63;
  int stage_v_38_2 = ((pub_r001033_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001033_9_1 * 2) + 16) & 63;
  int stage_v_39_2 = ((pub_r001033_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001033_2_1 * 2) + 31) & 63;
  int stage_v_40_2 = ((pub_r001033_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((stage_v_10_1 * 3) + pub_r001033_14_1) + 45) & 127;
  int stage_v_41_2 = (((stage_v_10_2 * 3) + pub_r001033_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = (((sec_r001033_16_1 * 3) + pub_r001033_3_1) + 35) & 127;
  int stage_v_42_2 = (((sec_r001033_16_2 * 3) + pub_r001033_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = (((stage_v_5_1 * 3) + pub_r001033_2_1) + 20) & 127;
  int stage_v_43_2 = (((stage_v_5_2 * 3) + pub_r001033_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = (((sec_r001033_10_1 * 3) + pub_r001033_2_1) + 45) & 127;
  int stage_v_44_2 = (((sec_r001033_10_2 * 3) + pub_r001033_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = ((pub_r001033_7_1 * 2) + 44) & 63;
  int stage_v_45_2 = ((pub_r001033_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((stage_v_21_1 * 3) + pub_r001033_14_1) + 28) & 127;
  int stage_v_46_2 = (((stage_v_21_2 * 3) + pub_r001033_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001033_0_1 * 2) + 10) & 63;
  int stage_v_47_2 = ((pub_r001033_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001033_20_1 * 2) + 28) & 63;
  int stage_v_48_2 = ((pub_r001033_20_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((stage_v_14_1 * 3) + pub_r001033_2_1) + 24) & 127;
  int stage_v_49_2 = (((stage_v_14_2 * 3) + pub_r001033_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = ((pub_r001033_14_1 * 2) + 11) & 63;
  int stage_v_50_2 = ((pub_r001033_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001033_15_1 * 2) + 48) & 63;
  int stage_v_51_2 = ((pub_r001033_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((stage_v_44_1 * 3) + pub_r001033_12_1) + 43) & 127;
  int stage_v_52_2 = (((stage_v_44_2 * 3) + pub_r001033_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = ((pub_r001033_4_1 * 2) + 47) & 63;
  int stage_v_53_2 = ((pub_r001033_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001033_2_1 * 2) + 16) & 63;
  int stage_v_54_2 = ((pub_r001033_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((helper_flow_3_1 * 3) + pub_r001033_17_1) + 11) & 127;
  int stage_v_55_2 = (((helper_flow_3_2 * 3) + pub_r001033_17_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = ((pub_r001033_20_1 * 2) + 48) & 63;
  int stage_v_56_2 = ((pub_r001033_20_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (((sec_r001033_19_1 * 3) + pub_r001033_13_1) + 38) & 127;
  int stage_v_57_2 = (((sec_r001033_19_2 * 3) + pub_r001033_13_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((sec_r001033_7_1 * 3) + pub_r001033_0_1) + 23) & 127;
  int stage_v_58_2 = (((sec_r001033_7_2 * 3) + pub_r001033_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = (((sec_r001033_17_1 * 3) + pub_r001033_19_1) + 24) & 127;
  int stage_v_59_2 = (((sec_r001033_17_2 * 3) + pub_r001033_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = ((pub_r001033_7_1 * 2) + 36) & 63;
  int stage_v_60_2 = ((pub_r001033_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001033_16_1 * 2) + 35) & 63;
  int stage_v_61_2 = ((pub_r001033_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = (((sec_r001033_10_1 * 3) + pub_r001033_10_1) + 13) & 127;
  int stage_v_62_2 = (((sec_r001033_10_2 * 3) + pub_r001033_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = (((sec_r001033_13_1 * 3) + pub_r001033_15_1) + 38) & 127;
  int stage_v_63_2 = (((sec_r001033_13_2 * 3) + pub_r001033_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = ((pub_r001033_8_1 * 2) + 45) & 63;
  int stage_v_64_2 = ((pub_r001033_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001033_13_1 * 2) + 17) & 63;
  int stage_v_65_2 = ((pub_r001033_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((sec_r001033_8_1 * 3) + pub_r001033_11_1) + 25) & 127;
  int stage_v_66_2 = (((sec_r001033_8_2 * 3) + pub_r001033_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = ((pub_r001033_15_1 * 2) + 39) & 63;
  int stage_v_67_2 = ((pub_r001033_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (((sec_r001033_15_1 * 3) + pub_r001033_18_1) + 29) & 127;
  int stage_v_68_2 = (((sec_r001033_15_2 * 3) + pub_r001033_18_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = (((stage_v_43_1 * 3) + pub_r001033_0_1) + 42) & 127;
  int stage_v_69_2 = (((stage_v_43_2 * 3) + pub_r001033_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = (((stage_v_21_1 * 3) + pub_r001033_3_1) + 20) & 127;
  int stage_v_70_2 = (((stage_v_21_2 * 3) + pub_r001033_3_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = ((pub_r001033_8_1 * 2) + 47) & 63;
  int stage_v_71_2 = ((pub_r001033_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((stage_v_49_1 * 3) + pub_r001033_11_1) + 45) & 127;
  int stage_v_72_2 = (((stage_v_49_2 * 3) + pub_r001033_11_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = (((stage_v_69_1 * 3) + pub_r001033_0_1) + 8) & 127;
  int stage_v_73_2 = (((stage_v_69_2 * 3) + pub_r001033_0_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = (((helper_flow_0_1 * 3) + pub_r001033_4_1) + 43) & 127;
  int stage_v_74_2 = (((helper_flow_0_2 * 3) + pub_r001033_4_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = ((pub_r001033_12_1 * 2) + 32) & 63;
  int stage_v_75_2 = ((pub_r001033_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001033_19_1 * 2) + 5) & 63;
  int stage_v_76_2 = ((pub_r001033_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((stage_v_42_1 * 3) + pub_r001033_13_1) + 16) & 127;
  int stage_v_77_2 = (((stage_v_42_2 * 3) + pub_r001033_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = ((pub_r001033_9_1 * 2) + 32) & 63;
  int stage_v_78_2 = ((pub_r001033_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((stage_v_66_1 * 3) + pub_r001033_8_1) + 38) & 127;
  int stage_v_79_2 = (((stage_v_66_2 * 3) + pub_r001033_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = ((pub_r001033_20_1 * 2) + 24) & 63;
  int stage_v_80_2 = ((pub_r001033_20_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001033_7_1 * 2) + 45) & 63;
  int stage_v_81_2 = ((pub_r001033_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001033_15_1 * 2) + 41) & 63;
  int stage_v_82_2 = ((pub_r001033_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((stage_v_43_1 * 3) + pub_r001033_2_1) + 10) & 127;
  int stage_v_83_2 = (((stage_v_43_2 * 3) + pub_r001033_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = ((pub_r001033_15_1 * 2) + 38) & 63;
  int stage_v_84_2 = ((pub_r001033_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001033_8_1 * 2) + 23) & 63;
  int stage_v_85_2 = ((pub_r001033_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001033_8_1 * 2) + 35) & 63;
  int stage_v_86_2 = ((pub_r001033_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001033_6_1 * 2) + 48) & 63;
  int stage_v_87_2 = ((pub_r001033_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001033_6_1 * 2) + 47) & 63;
  int stage_v_88_2 = ((pub_r001033_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((helper_flow_5_1 * 3) + pub_r001033_9_1) + 32) & 127;
  int stage_v_89_2 = (((helper_flow_5_2 * 3) + pub_r001033_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = ((pub_r001033_19_1 * 2) + 17) & 63;
  int stage_v_90_2 = ((pub_r001033_19_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = (((stage_v_28_1 * 3) + pub_r001033_17_1) + 13) & 127;
  int stage_v_91_2 = (((stage_v_28_2 * 3) + pub_r001033_17_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = (((sec_r001033_11_1 * 3) + pub_r001033_18_1) + 40) & 127;
  int stage_v_92_2 = (((sec_r001033_11_2 * 3) + pub_r001033_18_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = ((pub_r001033_10_1 * 2) + 17) & 63;
  int stage_v_93_2 = ((pub_r001033_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((stage_v_6_1 * 3) + pub_r001033_3_1) + 30) & 127;
  int stage_v_94_2 = (((stage_v_6_2 * 3) + pub_r001033_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = (((sec_r001033_11_1 * 3) + pub_r001033_2_1) + 35) & 127;
  int stage_v_95_2 = (((sec_r001033_11_2 * 3) + pub_r001033_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = (((stage_v_13_1 * 3) + pub_r001033_10_1) + 17) & 127;
  int stage_v_96_2 = (((stage_v_13_2 * 3) + pub_r001033_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = ((pub_r001033_10_1 * 2) + 16) & 63;
  int stage_v_97_2 = ((pub_r001033_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_0_1 * 3) + pub_r001033_18_1) + 19) & 127;
  int stage_v_98_2 = (((stage_v_0_2 * 3) + pub_r001033_18_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = ((pub_r001033_12_1 * 2) + 6) & 63;
  int stage_v_99_2 = ((pub_r001033_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (((stage_v_24_1 * 3) + pub_r001033_16_1) + 38) & 127;
  int stage_v_100_2 = (((stage_v_24_2 * 3) + pub_r001033_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = (((stage_v_92_1 * 3) + pub_r001033_20_1) + 15) & 127;
  int stage_v_101_2 = (((stage_v_92_2 * 3) + pub_r001033_20_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = (((sec_r001033_4_1 * 3) + pub_r001033_14_1) + 26) & 127;
  int stage_v_102_2 = (((sec_r001033_4_2 * 3) + pub_r001033_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = (((stage_v_59_1 * 3) + pub_r001033_20_1) + 43) & 127;
  int stage_v_103_2 = (((stage_v_59_2 * 3) + pub_r001033_20_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = ((pub_r001033_3_1 * 2) + 23) & 63;
  int stage_v_104_2 = ((pub_r001033_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001033_5_1 * 2) + 33) & 63;
  int stage_v_105_2 = ((pub_r001033_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001033_7_1 * 2) + 34) & 63;
  int stage_v_106_2 = ((pub_r001033_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((stage_v_96_1 * 3) + pub_r001033_14_1) + 9) & 127;
  int stage_v_107_2 = (((stage_v_96_2 * 3) + pub_r001033_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = (((stage_v_63_1 * 3) + pub_r001033_9_1) + 10) & 127;
  int stage_v_108_2 = (((stage_v_63_2 * 3) + pub_r001033_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = (((helper_flow_2_1 * 3) + pub_r001033_17_1) + 28) & 127;
  int stage_v_109_2 = (((helper_flow_2_2 * 3) + pub_r001033_17_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = (((stage_v_95_1 * 3) + pub_r001033_18_1) + 38) & 127;
  int stage_v_110_2 = (((stage_v_95_2 * 3) + pub_r001033_18_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = (((stage_v_43_1 * 3) + pub_r001033_2_1) + 44) & 127;
  int stage_v_111_2 = (((stage_v_43_2 * 3) + pub_r001033_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = ((pub_r001033_15_1 * 2) + 35) & 63;
  int stage_v_112_2 = ((pub_r001033_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((sec_r001033_19_1 * 3) + pub_r001033_11_1) + 11) & 127;
  int stage_v_113_2 = (((sec_r001033_19_2 * 3) + pub_r001033_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = ((pub_r001033_9_1 * 2) + 22) & 63;
  int stage_v_114_2 = ((pub_r001033_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = (((stage_v_24_1 * 3) + pub_r001033_1_1) + 13) & 127;
  int stage_v_115_2 = (((stage_v_24_2 * 3) + pub_r001033_1_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = ((pub_r001033_11_1 * 2) + 15) & 63;
  int stage_v_116_2 = ((pub_r001033_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((stage_v_42_1 * 3) + pub_r001033_6_1) + 27) & 127;
  int stage_v_117_2 = (((stage_v_42_2 * 3) + pub_r001033_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = (((stage_v_66_1 * 3) + pub_r001033_13_1) + 39) & 127;
  int stage_v_118_2 = (((stage_v_66_2 * 3) + pub_r001033_13_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = (((sec_r001033_6_1 * 3) + pub_r001033_4_1) + 12) & 127;
  int stage_v_119_2 = (((sec_r001033_6_2 * 3) + pub_r001033_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = ((pub_r001033_9_1 * 2) + 25) & 63;
  int stage_v_120_2 = ((pub_r001033_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = (((stage_v_118_1 * 3) + pub_r001033_2_1) + 33) & 127;
  int stage_v_121_2 = (((stage_v_118_2 * 3) + pub_r001033_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = (((helper_flow_2_1 * 3) + pub_r001033_20_1) + 14) & 127;
  int stage_v_122_2 = (((helper_flow_2_2 * 3) + pub_r001033_20_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = (((stage_v_66_1 * 3) + pub_r001033_6_1) + 24) & 127;
  int stage_v_123_2 = (((stage_v_66_2 * 3) + pub_r001033_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = ((pub_r001033_16_1 * 2) + 39) & 63;
  int stage_v_124_2 = ((pub_r001033_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (((stage_v_62_1 * 3) + pub_r001033_7_1) + 24) & 127;
  int stage_v_125_2 = (((stage_v_62_2 * 3) + pub_r001033_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = (((stage_v_73_1 * 3) + pub_r001033_11_1) + 44) & 127;
  int stage_v_126_2 = (((stage_v_73_2 * 3) + pub_r001033_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = (((stage_v_98_1 * 3) + pub_r001033_16_1) + 39) & 127;
  int stage_v_127_2 = (((stage_v_98_2 * 3) + pub_r001033_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = ((pub_r001033_7_1 * 2) + 39) & 63;
  int stage_v_128_2 = ((pub_r001033_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((stage_v_115_1 * 3) + pub_r001033_18_1) + 25) & 127;
  int stage_v_129_2 = (((stage_v_115_2 * 3) + pub_r001033_18_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = (((stage_v_14_1 * 3) + pub_r001033_3_1) + 21) & 127;
  int stage_v_130_2 = (((stage_v_14_2 * 3) + pub_r001033_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = ((pub_r001033_14_1 * 2) + 40) & 63;
  int stage_v_131_2 = ((pub_r001033_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((stage_v_83_1 * 3) + pub_r001033_2_1) + 11) & 127;
  int stage_v_132_2 = (((stage_v_83_2 * 3) + pub_r001033_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = (((stage_v_28_1 * 3) + pub_r001033_8_1) + 35) & 127;
  int stage_v_133_2 = (((stage_v_28_2 * 3) + pub_r001033_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((sec_r001033_16_1 * 3) + pub_r001033_0_1) + 33) & 127;
  int stage_v_134_2 = (((sec_r001033_16_2 * 3) + pub_r001033_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((stage_v_13_1 * 3) + pub_r001033_9_1) + 16) & 127;
  int stage_v_135_2 = (((stage_v_13_2 * 3) + pub_r001033_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = ((pub_r001033_13_1 * 2) + 24) & 63;
  int stage_v_136_2 = ((pub_r001033_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001033_9_1 * 2) + 44) & 63;
  int stage_v_137_2 = ((pub_r001033_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((stage_v_108_1 * 3) + pub_r001033_9_1) + 31) & 127;
  int stage_v_138_2 = (((stage_v_108_2 * 3) + pub_r001033_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = (((stage_v_28_1 * 3) + pub_r001033_4_1) + 44) & 127;
  int stage_v_139_2 = (((stage_v_28_2 * 3) + pub_r001033_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = (((helper_flow_2_1 * 3) + pub_r001033_12_1) + 33) & 127;
  int stage_v_140_2 = (((helper_flow_2_2 * 3) + pub_r001033_12_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = (((stage_v_138_1 * 3) + pub_r001033_16_1) + 7) & 127;
  int stage_v_141_2 = (((stage_v_138_2 * 3) + pub_r001033_16_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = (((stage_v_10_1 * 3) + pub_r001033_10_1) + 11) & 127;
  int stage_v_142_2 = (((stage_v_10_2 * 3) + pub_r001033_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = ((pub_r001033_12_1 * 2) + 41) & 63;
  int stage_v_143_2 = ((pub_r001033_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001033_2_1 * 2) + 8) & 63;
  int stage_v_144_2 = ((pub_r001033_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001033_10_1 * 2) + 20) & 63;
  int stage_v_145_2 = ((pub_r001033_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001033_19_1 * 2) + 24) & 63;
  int stage_v_146_2 = ((pub_r001033_19_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001033_18_1 * 2) + 33) & 63;
  int stage_v_147_2 = ((pub_r001033_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001033_12_1 * 2) + 34) & 63;
  int stage_v_148_2 = ((pub_r001033_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (((stage_v_77_1 * 3) + pub_r001033_5_1) + 12) & 127;
  int stage_v_149_2 = (((stage_v_77_2 * 3) + pub_r001033_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((stage_v_6_1 * 3) + pub_r001033_14_1) + 41) & 127;
  int stage_v_150_2 = (((stage_v_6_2 * 3) + pub_r001033_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((stage_v_21_1 * 3) + pub_r001033_10_1) + 37) & 127;
  int stage_v_151_2 = (((stage_v_21_2 * 3) + pub_r001033_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = (((stage_v_142_1 * 3) + pub_r001033_10_1) + 5) & 127;
  int stage_v_152_2 = (((stage_v_142_2 * 3) + pub_r001033_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = ((pub_r001033_3_1 * 2) + 34) & 63;
  int stage_v_153_2 = ((pub_r001033_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001033_8_1 * 2) + 16) & 63;
  int stage_v_154_2 = ((pub_r001033_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001033_16_1 * 2) + 11) & 63;
  int stage_v_155_2 = ((pub_r001033_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((stage_v_134_1 * 3) + pub_r001033_17_1) + 29) & 127;
  int stage_v_156_2 = (((stage_v_134_2 * 3) + pub_r001033_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = ((pub_r001033_4_1 * 2) + 26) & 63;
  int stage_v_157_2 = ((pub_r001033_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001033_6_1 * 2) + 45) & 63;
  int stage_v_158_2 = ((pub_r001033_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((sec_r001033_17_1 * 3) + pub_r001033_8_1) + 44) & 127;
  int stage_v_159_2 = (((sec_r001033_17_2 * 3) + pub_r001033_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = ((pub_r001033_16_1 * 2) + 29) & 63;
  int stage_v_160_2 = ((pub_r001033_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_94_1 * 3) + pub_r001033_7_1) + 23) & 127;
  int stage_v_161_2 = (((stage_v_94_2 * 3) + pub_r001033_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = ((pub_r001033_15_1 * 2) + 43) & 63;
  int stage_v_162_2 = ((pub_r001033_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((stage_v_2_1 * 3) + pub_r001033_20_1) + 33) & 127;
  int stage_v_163_2 = (((stage_v_2_2 * 3) + pub_r001033_20_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = ((pub_r001033_8_1 * 2) + 40) & 63;
  int stage_v_164_2 = ((pub_r001033_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001033_8_1 * 2) + 45) & 63;
  int stage_v_165_2 = ((pub_r001033_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((stage_v_77_1 * 3) + pub_r001033_13_1) + 7) & 127;
  int stage_v_166_2 = (((stage_v_77_2 * 3) + pub_r001033_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = (((stage_v_159_1 * 3) + pub_r001033_1_1) + 5) & 127;
  int stage_v_167_2 = (((stage_v_159_2 * 3) + pub_r001033_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = ((pub_r001033_4_1 * 2) + 25) & 63;
  int stage_v_168_2 = ((pub_r001033_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001033_5_1 * 2) + 48) & 63;
  int stage_v_169_2 = ((pub_r001033_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((stage_v_55_1 * 3) + pub_r001033_5_1) + 17) & 127;
  int stage_v_170_2 = (((stage_v_55_2 * 3) + pub_r001033_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = ((pub_r001033_2_1 * 2) + 29) & 63;
  int stage_v_171_2 = ((pub_r001033_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001033_14_1 * 2) + 23) & 63;
  int stage_v_172_2 = ((pub_r001033_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001033_1_1 * 2) + 44) & 63;
  int stage_v_173_2 = ((pub_r001033_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (((stage_v_66_1 * 3) + pub_r001033_10_1) + 27) & 127;
  int stage_v_174_2 = (((stage_v_66_2 * 3) + pub_r001033_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = ((pub_r001033_4_1 * 2) + 46) & 63;
  int stage_v_175_2 = ((pub_r001033_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_135_1 * 3) + pub_r001033_20_1) + 35) & 127;
  int stage_v_176_2 = (((stage_v_135_2 * 3) + pub_r001033_20_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = ((pub_r001033_6_1 * 2) + 27) & 63;
  int stage_v_177_2 = ((pub_r001033_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001033_12_1 * 2) + 33) & 63;
  int stage_v_178_2 = ((pub_r001033_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001033_9_1 * 2) + 40) & 63;
  int stage_v_179_2 = ((pub_r001033_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_23_1 * 3) + pub_r001033_11_1) + 20) & 127;
  int stage_v_180_2 = (((stage_v_23_2 * 3) + pub_r001033_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = (((sec_r001033_4_1 * 3) + pub_r001033_18_1) + 41) & 127;
  int stage_v_181_2 = (((sec_r001033_4_2 * 3) + pub_r001033_18_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = (((sec_r001033_17_1 * 3) + pub_r001033_17_1) + 18) & 127;
  int stage_v_182_2 = (((sec_r001033_17_2 * 3) + pub_r001033_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = (((stage_v_37_1 * 3) + pub_r001033_9_1) + 15) & 127;
  int stage_v_183_2 = (((stage_v_37_2 * 3) + pub_r001033_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = ((pub_r001033_12_1 * 2) + 17) & 63;
  int stage_v_184_2 = ((pub_r001033_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001033_7_1 * 2) + 26) & 63;
  int stage_v_185_2 = ((pub_r001033_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_125_1 * 3) + pub_r001033_12_1) + 45) & 127;
  int stage_v_186_2 = (((stage_v_125_2 * 3) + pub_r001033_12_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = (((stage_v_41_1 * 3) + pub_r001033_14_1) + 36) & 127;
  int stage_v_187_2 = (((stage_v_41_2 * 3) + pub_r001033_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = ((pub_r001033_1_1 * 2) + 7) & 63;
  int stage_v_188_2 = ((pub_r001033_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001033_17_1 * 2) + 30) & 63;
  int stage_v_189_2 = ((pub_r001033_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001033_3_1 * 2) + 21) & 63;
  int stage_v_190_2 = ((pub_r001033_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001033_5_1 * 2) + 37) & 63;
  int stage_v_191_2 = ((pub_r001033_5_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = (((sec_r001033_8_1 * 3) + pub_r001033_13_1) + 7) & 127;
  int stage_v_192_2 = (((sec_r001033_8_2 * 3) + pub_r001033_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = (((stage_v_110_1 * 3) + pub_r001033_20_1) + 20) & 127;
  int stage_v_193_2 = (((stage_v_110_2 * 3) + pub_r001033_20_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001033_20_1 * 2) + 11) & 63;
  int stage_v_194_2 = ((pub_r001033_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001033_4_1 * 2) + 11) & 63;
  int stage_v_195_2 = ((pub_r001033_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001033_19_1 * 2) + 14) & 63;
  int stage_v_196_2 = ((pub_r001033_19_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((sec_r001033_5_1 * 3) + pub_r001033_0_1) + 22) & 127;
  int stage_v_197_2 = (((sec_r001033_5_2 * 3) + pub_r001033_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = ((pub_r001033_15_1 * 2) + 7) & 63;
  int stage_v_198_2 = ((pub_r001033_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_149_1 * 3) + pub_r001033_16_1) + 30) & 127;
  int stage_v_199_2 = (((stage_v_149_2 * 3) + pub_r001033_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = ((pub_r001033_9_1 * 2) + 31) & 63;
  int stage_v_200_2 = ((pub_r001033_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((stage_v_26_1 * 3) + pub_r001033_16_1) + 6) & 127;
  int stage_v_201_2 = (((stage_v_26_2 * 3) + pub_r001033_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = ((pub_r001033_15_1 * 2) + 38) & 63;
  int stage_v_202_2 = ((pub_r001033_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((stage_v_151_1 * 3) + pub_r001033_7_1) + 16) & 127;
  int stage_v_203_2 = (((stage_v_151_2 * 3) + pub_r001033_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = (((sec_r001033_0_1 * 3) + pub_r001033_13_1) + 33) & 127;
  int stage_v_204_2 = (((sec_r001033_0_2 * 3) + pub_r001033_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((stage_v_152_1 * 3) + pub_r001033_15_1) + 21) & 127;
  int stage_v_205_2 = (((stage_v_152_2 * 3) + pub_r001033_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = (((stage_v_115_1 * 3) + pub_r001033_11_1) + 41) & 127;
  int stage_v_206_2 = (((stage_v_115_2 * 3) + pub_r001033_11_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = ((pub_r001033_7_1 * 2) + 39) & 63;
  int stage_v_207_2 = ((pub_r001033_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = (((stage_v_83_1 * 3) + pub_r001033_14_1) + 45) & 127;
  int stage_v_208_2 = (((stage_v_83_2 * 3) + pub_r001033_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = (((stage_v_121_1 * 3) + pub_r001033_13_1) + 5) & 127;
  int stage_v_209_2 = (((stage_v_121_2 * 3) + pub_r001033_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = (((sec_r001033_14_1 * 3) + pub_r001033_20_1) + 7) & 127;
  int stage_v_210_2 = (((sec_r001033_14_2 * 3) + pub_r001033_20_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_58_1 * 3) + pub_r001033_1_1) + 4) & 127;
  int stage_v_211_2 = (((stage_v_58_2 * 3) + pub_r001033_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = (((stage_v_109_1 * 3) + pub_r001033_6_1) + 14) & 127;
  int stage_v_212_2 = (((stage_v_109_2 * 3) + pub_r001033_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = ((pub_r001033_1_1 * 2) + 11) & 63;
  int stage_v_213_2 = ((pub_r001033_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (((stage_v_140_1 * 3) + pub_r001033_20_1) + 10) & 127;
  int stage_v_214_2 = (((stage_v_140_2 * 3) + pub_r001033_20_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = (((stage_v_209_1 * 3) + pub_r001033_13_1) + 27) & 127;
  int stage_v_215_2 = (((stage_v_209_2 * 3) + pub_r001033_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_49_1 * 3) + pub_r001033_1_1) + 21) & 127;
  int stage_v_216_2 = (((stage_v_49_2 * 3) + pub_r001033_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001033_18_1 * 2) + 50) & 63;
  int stage_v_217_2 = ((pub_r001033_18_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001033_8_1 * 2) + 6) & 63;
  int stage_v_218_2 = ((pub_r001033_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((stage_v_109_1 * 3) + pub_r001033_2_1) + 44) & 127;
  int stage_v_219_2 = (((stage_v_109_2 * 3) + pub_r001033_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((stage_v_98_1 * 3) + pub_r001033_3_1) + 35) & 127;
  int stage_v_220_2 = (((stage_v_98_2 * 3) + pub_r001033_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = ((pub_r001033_5_1 * 2) + 8) & 63;
  int stage_v_221_2 = ((pub_r001033_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = (((stage_v_182_1 * 3) + pub_r001033_20_1) + 30) & 127;
  int stage_v_222_2 = (((stage_v_182_2 * 3) + pub_r001033_20_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = (((stage_v_209_1 * 3) + pub_r001033_7_1) + 24) & 127;
  int stage_v_223_2 = (((stage_v_209_2 * 3) + pub_r001033_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = ((pub_r001033_15_1 * 2) + 9) & 63;
  int stage_v_224_2 = ((pub_r001033_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_140_1 * 3) + pub_r001033_9_1) + 12) & 127;
  int stage_v_225_2 = (((stage_v_140_2 * 3) + pub_r001033_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = (((stage_v_199_1 * 3) + pub_r001033_3_1) + 10) & 127;
  int stage_v_226_2 = (((stage_v_199_2 * 3) + pub_r001033_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = ((pub_r001033_17_1 * 2) + 8) & 63;
  int stage_v_227_2 = ((pub_r001033_17_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = (((stage_v_41_1 * 3) + pub_r001033_16_1) + 25) & 127;
  int stage_v_228_2 = (((stage_v_41_2 * 3) + pub_r001033_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = ((pub_r001033_9_1 * 2) + 32) & 63;
  int stage_v_229_2 = ((pub_r001033_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = (((stage_v_13_1 * 3) + pub_r001033_9_1) + 20) & 127;
  int stage_v_230_2 = (((stage_v_13_2 * 3) + pub_r001033_9_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = (((stage_v_6_1 * 3) + pub_r001033_12_1) + 4) & 127;
  int stage_v_231_2 = (((stage_v_6_2 * 3) + pub_r001033_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = (((sec_r001033_12_1 * 3) + pub_r001033_13_1) + 10) & 127;
  int stage_v_232_2 = (((sec_r001033_12_2 * 3) + pub_r001033_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = (((stage_v_98_1 * 3) + pub_r001033_12_1) + 25) & 127;
  int stage_v_233_2 = (((stage_v_98_2 * 3) + pub_r001033_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = (((stage_v_59_1 * 3) + pub_r001033_19_1) + 14) & 127;
  int stage_v_234_2 = (((stage_v_59_2 * 3) + pub_r001033_19_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = ((pub_r001033_18_1 * 2) + 45) & 63;
  int stage_v_235_2 = ((pub_r001033_18_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = (((stage_v_180_1 * 3) + pub_r001033_7_1) + 4) & 127;
  int stage_v_236_2 = (((stage_v_180_2 * 3) + pub_r001033_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = ((pub_r001033_3_1 * 2) + 23) & 63;
  int stage_v_237_2 = ((pub_r001033_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001033_20_1 * 2) + 39) & 63;
  int stage_v_238_2 = ((pub_r001033_20_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = (((stage_v_161_1 * 3) + pub_r001033_1_1) + 30) & 127;
  int stage_v_239_2 = (((stage_v_161_2 * 3) + pub_r001033_1_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = (((stage_v_73_1 * 3) + pub_r001033_5_1) + 8) & 127;
  int stage_v_240_2 = (((stage_v_73_2 * 3) + pub_r001033_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = ((pub_r001033_1_1 * 2) + 26) & 63;
  int stage_v_241_2 = ((pub_r001033_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = (((stage_v_96_1 * 3) + pub_r001033_12_1) + 14) & 127;
  int stage_v_242_2 = (((stage_v_96_2 * 3) + pub_r001033_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = (((stage_v_130_1 * 3) + pub_r001033_16_1) + 16) & 127;
  int stage_v_243_2 = (((stage_v_130_2 * 3) + pub_r001033_16_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = ((pub_r001033_6_1 * 2) + 33) & 63;
  int stage_v_244_2 = ((pub_r001033_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001033_12_1 * 2) + 6) & 63;
  int stage_v_245_2 = ((pub_r001033_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001033_19_1 * 2) + 47) & 63;
  int stage_v_246_2 = ((pub_r001033_19_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = (((stage_v_159_1 * 3) + pub_r001033_12_1) + 37) & 127;
  int stage_v_247_2 = (((stage_v_159_2 * 3) + pub_r001033_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = ((pub_r001033_4_1 * 2) + 38) & 63;
  int stage_v_248_2 = ((pub_r001033_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = (((stage_v_28_1 * 3) + pub_r001033_8_1) + 8) & 127;
  int stage_v_249_2 = (((stage_v_28_2 * 3) + pub_r001033_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = ((pub_r001033_3_1 * 2) + 19) & 63;
  int stage_v_250_2 = ((pub_r001033_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001033_15_1 * 2) + 21) & 63;
  int stage_v_251_2 = ((pub_r001033_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = (((stage_v_231_1 * 3) + pub_r001033_11_1) + 45) & 127;
  int stage_v_252_2 = (((stage_v_231_2 * 3) + pub_r001033_11_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = (((sec_r001033_7_1 * 3) + pub_r001033_12_1) + 18) & 127;
  int stage_v_253_2 = (((sec_r001033_7_2 * 3) + pub_r001033_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = (((stage_v_197_1 * 3) + pub_r001033_8_1) + 30) & 127;
  int stage_v_254_2 = (((stage_v_197_2 * 3) + pub_r001033_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = ((pub_r001033_9_1 * 2) + 50) & 63;
  int stage_v_255_2 = ((pub_r001033_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = (((stage_v_102_1 * 3) + pub_r001033_16_1) + 33) & 127;
  int stage_v_256_2 = (((stage_v_102_2 * 3) + pub_r001033_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = ((pub_r001033_18_1 * 2) + 10) & 63;
  int stage_v_257_2 = ((pub_r001033_18_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_2_1 * 3) + pub_r001033_15_1) + 5) & 127;
  int stage_v_258_2 = (((stage_v_2_2 * 3) + pub_r001033_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = (((stage_v_83_1 * 3) + pub_r001033_11_1) + 6) & 127;
  int stage_v_259_2 = (((stage_v_83_2 * 3) + pub_r001033_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = ((pub_r001033_16_1 * 2) + 20) & 63;
  int stage_v_260_2 = ((pub_r001033_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((stage_v_14_1 * 3) + pub_r001033_18_1) + 13) & 127;
  int stage_v_261_2 = (((stage_v_14_2 * 3) + pub_r001033_18_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001033_15_1 * 2) + 27) & 63;
  int stage_v_262_2 = ((pub_r001033_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001033_11_1 * 2) + 20) & 63;
  int stage_v_263_2 = ((pub_r001033_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((pub_r001033_16_1 * 2) + 37) & 63;
  int stage_v_264_2 = ((pub_r001033_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001033_9_1 * 2) + 49) & 63;
  int stage_v_265_2 = ((pub_r001033_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = (((sec_r001033_11_1 * 3) + pub_r001033_12_1) + 5) & 127;
  int stage_v_266_2 = (((sec_r001033_11_2 * 3) + pub_r001033_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = ((pub_r001033_3_1 * 2) + 36) & 63;
  int stage_v_267_2 = ((pub_r001033_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001033_19_1 * 2) + 29) & 63;
  int stage_v_268_2 = ((pub_r001033_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = (((stage_v_231_1 * 3) + pub_r001033_0_1) + 38) & 127;
  int stage_v_269_2 = (((stage_v_231_2 * 3) + pub_r001033_0_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = (((stage_v_138_1 * 3) + pub_r001033_0_1) + 29) & 127;
  int stage_v_270_2 = (((stage_v_138_2 * 3) + pub_r001033_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = ((pub_r001033_10_1 * 2) + 44) & 63;
  int stage_v_271_2 = ((pub_r001033_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = (((stage_v_0_1 * 3) + pub_r001033_20_1) + 8) & 127;
  int stage_v_272_2 = (((stage_v_0_2 * 3) + pub_r001033_20_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = (((sec_r001033_3_1 * 3) + pub_r001033_19_1) + 19) & 127;
  int stage_v_273_2 = (((sec_r001033_3_2 * 3) + pub_r001033_19_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = (((stage_v_102_1 * 3) + pub_r001033_0_1) + 34) & 127;
  int stage_v_274_2 = (((stage_v_102_2 * 3) + pub_r001033_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = ((pub_r001033_16_1 * 2) + 32) & 63;
  int stage_v_275_2 = ((pub_r001033_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = (((stage_v_59_1 * 3) + pub_r001033_5_1) + 9) & 127;
  int stage_v_276_2 = (((stage_v_59_2 * 3) + pub_r001033_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = (((stage_v_254_1 * 3) + pub_r001033_1_1) + 3) & 127;
  int stage_v_277_2 = (((stage_v_254_2 * 3) + pub_r001033_1_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = ((pub_r001033_1_1 * 2) + 39) & 63;
  int stage_v_278_2 = ((pub_r001033_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001033_11_1 * 2) + 22) & 63;
  int stage_v_279_2 = ((pub_r001033_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001033_5_1 * 2) + 42) & 63;
  int stage_v_280_2 = ((pub_r001033_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = (((stage_v_26_1 * 3) + pub_r001033_1_1) + 15) & 127;
  int stage_v_281_2 = (((stage_v_26_2 * 3) + pub_r001033_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = (((sec_r001033_12_1 * 3) + pub_r001033_18_1) + 10) & 127;
  int stage_v_282_2 = (((sec_r001033_12_2 * 3) + pub_r001033_18_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = (((stage_v_140_1 * 3) + pub_r001033_1_1) + 4) & 127;
  int stage_v_283_2 = (((stage_v_140_2 * 3) + pub_r001033_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = (((stage_v_21_1 * 3) + pub_r001033_6_1) + 42) & 127;
  int stage_v_284_2 = (((stage_v_21_2 * 3) + pub_r001033_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = ((pub_r001033_5_1 * 2) + 38) & 63;
  int stage_v_285_2 = ((pub_r001033_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001033_4_1 * 2) + 15) & 63;
  int stage_v_286_2 = ((pub_r001033_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = (((stage_v_242_1 * 3) + pub_r001033_2_1) + 34) & 127;
  int stage_v_287_2 = (((stage_v_242_2 * 3) + pub_r001033_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = ((pub_r001033_9_1 * 2) + 12) & 63;
  int stage_v_288_2 = ((pub_r001033_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_101_1 * 3) + pub_r001033_10_1) + 28) & 127;
  int stage_v_289_2 = (((stage_v_101_2 * 3) + pub_r001033_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = ((pub_r001033_1_1 * 2) + 12) & 63;
  int stage_v_290_2 = ((pub_r001033_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((pub_r001033_11_1 * 2) + 49) & 63;
  int stage_v_291_2 = ((pub_r001033_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = (((stage_v_37_1 * 3) + pub_r001033_6_1) + 37) & 127;
  int stage_v_292_2 = (((stage_v_37_2 * 3) + pub_r001033_6_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = ((pub_r001033_13_1 * 2) + 28) & 63;
  int stage_v_293_2 = ((pub_r001033_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = (((stage_v_141_1 * 3) + pub_r001033_6_1) + 25) & 127;
  int stage_v_294_2 = (((stage_v_141_2 * 3) + pub_r001033_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = (((stage_v_152_1 * 3) + pub_r001033_14_1) + 42) & 127;
  int stage_v_295_2 = (((stage_v_152_2 * 3) + pub_r001033_14_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = ((pub_r001033_10_1 * 2) + 21) & 63;
  int stage_v_296_2 = ((pub_r001033_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = (((stage_v_208_1 * 3) + pub_r001033_15_1) + 7) & 127;
  int stage_v_297_2 = (((stage_v_208_2 * 3) + pub_r001033_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = (((sec_r001033_5_1 * 3) + pub_r001033_9_1) + 24) & 127;
  int stage_v_298_2 = (((sec_r001033_5_2 * 3) + pub_r001033_9_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = (((stage_v_133_1 * 3) + pub_r001033_8_1) + 31) & 127;
  int stage_v_299_2 = (((stage_v_133_2 * 3) + pub_r001033_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = ((pub_r001033_0_1 * 2) + 20) & 63;
  int stage_v_300_2 = ((pub_r001033_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001033_15_1 * 2) + 33) & 63;
  int stage_v_301_2 = ((pub_r001033_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001033_9_1 * 2) + 44) & 63;
  int stage_v_302_2 = ((pub_r001033_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = (((stage_v_24_1 * 3) + pub_r001033_3_1) + 29) & 127;
  int stage_v_303_2 = (((stage_v_24_2 * 3) + pub_r001033_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001033_4_1 * 2) + 41) & 63;
  int stage_v_304_2 = ((pub_r001033_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = (((helper_flow_2_1 * 3) + pub_r001033_10_1) + 13) & 127;
  int stage_v_305_2 = (((helper_flow_2_2 * 3) + pub_r001033_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_305_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_305_2 * 2)) & 255;
  int stage_v_306_1 = ((pub_r001033_4_1 * 2) + 10) & 63;
  int stage_v_306_2 = ((pub_r001033_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = (((stage_v_134_1 * 3) + pub_r001033_13_1) + 36) & 127;
  int stage_v_307_2 = (((stage_v_134_2 * 3) + pub_r001033_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = ((pub_r001033_17_1 * 2) + 46) & 63;
  int stage_v_308_2 = ((pub_r001033_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = (((stage_v_156_1 * 3) + pub_r001033_4_1) + 38) & 127;
  int stage_v_309_2 = (((stage_v_156_2 * 3) + pub_r001033_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = (((stage_v_222_1 * 3) + pub_r001033_5_1) + 41) & 127;
  int stage_v_310_2 = (((stage_v_222_2 * 3) + pub_r001033_5_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = (((stage_v_121_1 * 3) + pub_r001033_20_1) + 35) & 127;
  int stage_v_311_2 = (((stage_v_121_2 * 3) + pub_r001033_20_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = (((stage_v_117_1 * 3) + pub_r001033_19_1) + 43) & 127;
  int stage_v_312_2 = (((stage_v_117_2 * 3) + pub_r001033_19_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = (((sec_r001033_17_1 * 3) + pub_r001033_14_1) + 25) & 127;
  int stage_v_313_2 = (((sec_r001033_17_2 * 3) + pub_r001033_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001033_7_1 * 2) + 47) & 63;
  int stage_v_314_2 = ((pub_r001033_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = (((sec_r001033_17_1 * 3) + pub_r001033_13_1) + 32) & 127;
  int stage_v_315_2 = (((sec_r001033_17_2 * 3) + pub_r001033_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((stage_v_100_1 * 3) + pub_r001033_2_1) + 8) & 127;
  int stage_v_316_2 = (((stage_v_100_2 * 3) + pub_r001033_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((helper_flow_4_1 * 3) + pub_r001033_4_1) + 21) & 127;
  int stage_v_317_2 = (((helper_flow_4_2 * 3) + pub_r001033_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = ((pub_r001033_13_1 * 2) + 25) & 63;
  int stage_v_318_2 = ((pub_r001033_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = (((stage_v_94_1 * 3) + pub_r001033_2_1) + 19) & 127;
  int stage_v_319_2 = (((stage_v_94_2 * 3) + pub_r001033_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = ((pub_r001033_20_1 * 2) + 44) & 63;
  int stage_v_320_2 = ((pub_r001033_20_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = (((stage_v_6_1 * 3) + pub_r001033_19_1) + 22) & 127;
  int stage_v_321_2 = (((stage_v_6_2 * 3) + pub_r001033_19_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((stage_v_187_1 * 3) + pub_r001033_18_1) + 8) & 127;
  int stage_v_322_2 = (((stage_v_187_2 * 3) + pub_r001033_18_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = (((stage_v_159_1 * 3) + pub_r001033_16_1) + 31) & 127;
  int stage_v_323_2 = (((stage_v_159_2 * 3) + pub_r001033_16_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = (((sec_r001033_14_1 * 3) + pub_r001033_8_1) + 41) & 127;
  int stage_v_324_2 = (((sec_r001033_14_2 * 3) + pub_r001033_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = ((pub_r001033_4_1 * 2) + 8) & 63;
  int stage_v_325_2 = ((pub_r001033_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = (((stage_v_203_1 * 3) + pub_r001033_3_1) + 36) & 127;
  int stage_v_326_2 = (((stage_v_203_2 * 3) + pub_r001033_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = (((stage_v_107_1 * 3) + pub_r001033_3_1) + 43) & 127;
  int stage_v_327_2 = (((stage_v_107_2 * 3) + pub_r001033_3_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = (((stage_v_95_1 * 3) + pub_r001033_18_1) + 36) & 127;
  int stage_v_328_2 = (((stage_v_95_2 * 3) + pub_r001033_18_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = (((stage_v_134_1 * 3) + pub_r001033_8_1) + 12) & 127;
  int stage_v_329_2 = (((stage_v_134_2 * 3) + pub_r001033_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = ((pub_r001033_11_1 * 2) + 15) & 63;
  int stage_v_330_2 = ((pub_r001033_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = (((stage_v_166_1 * 3) + pub_r001033_16_1) + 44) & 127;
  int stage_v_331_2 = (((stage_v_166_2 * 3) + pub_r001033_16_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = ((pub_r001033_0_1 * 2) + 22) & 63;
  int stage_v_332_2 = ((pub_r001033_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = (((stage_v_297_1 * 3) + pub_r001033_14_1) + 44) & 127;
  int stage_v_333_2 = (((stage_v_297_2 * 3) + pub_r001033_14_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = ((pub_r001033_13_1 * 2) + 15) & 63;
  int stage_v_334_2 = ((pub_r001033_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = (((stage_v_57_1 * 3) + pub_r001033_0_1) + 42) & 127;
  int stage_v_335_2 = (((stage_v_57_2 * 3) + pub_r001033_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = (((stage_v_311_1 * 3) + pub_r001033_5_1) + 25) & 127;
  int stage_v_336_2 = (((stage_v_311_2 * 3) + pub_r001033_5_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((stage_v_208_1 * 3) + pub_r001033_20_1) + 41) & 127;
  int stage_v_337_2 = (((stage_v_208_2 * 3) + pub_r001033_20_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = ((pub_r001033_17_1 * 2) + 23) & 63;
  int stage_v_338_2 = ((pub_r001033_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = (((stage_v_269_1 * 3) + pub_r001033_11_1) + 7) & 127;
  int stage_v_339_2 = (((stage_v_269_2 * 3) + pub_r001033_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = ((pub_r001033_13_1 * 2) + 30) & 63;
  int stage_v_340_2 = ((pub_r001033_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = (((stage_v_46_1 * 3) + pub_r001033_2_1) + 19) & 127;
  int stage_v_341_2 = (((stage_v_46_2 * 3) + pub_r001033_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = ((pub_r001033_20_1 * 2) + 17) & 63;
  int stage_v_342_2 = ((pub_r001033_20_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = (((stage_v_94_1 * 3) + pub_r001033_15_1) + 14) & 127;
  int stage_v_343_2 = (((stage_v_94_2 * 3) + pub_r001033_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_311_1 * 3) + pub_r001033_7_1) + 20) & 127;
  int stage_v_344_2 = (((stage_v_311_2 * 3) + pub_r001033_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001033_19_1 * 2) + 46) & 63;
  int stage_v_345_2 = ((pub_r001033_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = (((stage_v_252_1 * 3) + pub_r001033_5_1) + 41) & 127;
  int stage_v_346_2 = (((stage_v_252_2 * 3) + pub_r001033_5_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = (((stage_v_309_1 * 3) + pub_r001033_10_1) + 39) & 127;
  int stage_v_347_2 = (((stage_v_309_2 * 3) + pub_r001033_10_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = ((pub_r001033_16_1 * 2) + 6) & 63;
  int stage_v_348_2 = ((pub_r001033_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = (((sec_r001033_9_1 * 3) + pub_r001033_11_1) + 42) & 127;
  int stage_v_349_2 = (((sec_r001033_9_2 * 3) + pub_r001033_11_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = ((pub_r001033_14_1 * 2) + 17) & 63;
  int stage_v_350_2 = ((pub_r001033_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = ((pub_r001033_18_1 * 2) + 29) & 63;
  int stage_v_351_2 = ((pub_r001033_18_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = (((stage_v_239_1 * 3) + pub_r001033_2_1) + 34) & 127;
  int stage_v_352_2 = (((stage_v_239_2 * 3) + pub_r001033_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = (((stage_v_141_1 * 3) + pub_r001033_7_1) + 12) & 127;
  int stage_v_353_2 = (((stage_v_141_2 * 3) + pub_r001033_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = ((pub_r001033_5_1 * 2) + 33) & 63;
  int stage_v_354_2 = ((pub_r001033_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001033_1_1 * 2) + 27) & 63;
  int stage_v_355_2 = ((pub_r001033_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = (((stage_v_122_1 * 3) + pub_r001033_4_1) + 38) & 127;
  int stage_v_356_2 = (((stage_v_122_2 * 3) + pub_r001033_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = (((stage_v_163_1 * 3) + pub_r001033_9_1) + 38) & 127;
  int stage_v_357_2 = (((stage_v_163_2 * 3) + pub_r001033_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = (((stage_v_259_1 * 3) + pub_r001033_7_1) + 26) & 127;
  int stage_v_358_2 = (((stage_v_259_2 * 3) + pub_r001033_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = ((pub_r001033_13_1 * 2) + 29) & 63;
  int stage_v_359_2 = ((pub_r001033_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = (((stage_v_13_1 * 3) + pub_r001033_17_1) + 29) & 127;
  int stage_v_360_2 = (((stage_v_13_2 * 3) + pub_r001033_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = ((pub_r001033_8_1 * 2) + 6) & 63;
  int stage_v_361_2 = ((pub_r001033_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001033_18_1 * 2) + 41) & 63;
  int stage_v_362_2 = ((pub_r001033_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001033_19_1 * 2) + 33) & 63;
  int stage_v_363_2 = ((pub_r001033_19_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001033_4_1 * 2) + 47) & 63;
  int stage_v_364_2 = ((pub_r001033_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = (((stage_v_37_1 * 3) + pub_r001033_10_1) + 38) & 127;
  int stage_v_365_2 = (((stage_v_37_2 * 3) + pub_r001033_10_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = ((pub_r001033_3_1 * 2) + 12) & 63;
  int stage_v_366_2 = ((pub_r001033_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = (((sec_r001033_3_1 * 3) + pub_r001033_8_1) + 39) & 127;
  int stage_v_367_2 = (((sec_r001033_3_2 * 3) + pub_r001033_8_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001033_0_1 * 2) + 8) & 63;
  int stage_v_368_2 = ((pub_r001033_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001033_6_1 * 2) + 6) & 63;
  int stage_v_369_2 = ((pub_r001033_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001033_5_1 * 2) + 23) & 63;
  int stage_v_370_2 = ((pub_r001033_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = (((stage_v_276_1 * 3) + pub_r001033_12_1) + 6) & 127;
  int stage_v_371_2 = (((stage_v_276_2 * 3) + pub_r001033_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = (((stage_v_333_1 * 3) + pub_r001033_14_1) + 40) & 127;
  int stage_v_372_2 = (((stage_v_333_2 * 3) + pub_r001033_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = ((pub_r001033_1_1 * 2) + 40) & 63;
  int stage_v_373_2 = ((pub_r001033_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = (((stage_v_109_1 * 3) + pub_r001033_5_1) + 19) & 127;
  int stage_v_374_2 = (((stage_v_109_2 * 3) + pub_r001033_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_337_1 * 3) + pub_r001033_13_1) + 3) & 127;
  int stage_v_375_2 = (((stage_v_337_2 * 3) + pub_r001033_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001033_15_1 * 2) + 15) & 63;
  int stage_v_376_2 = ((pub_r001033_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = (((stage_v_77_1 * 3) + pub_r001033_10_1) + 31) & 127;
  int stage_v_377_2 = (((stage_v_77_2 * 3) + pub_r001033_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = (((stage_v_333_1 * 3) + pub_r001033_20_1) + 45) & 127;
  int stage_v_378_2 = (((stage_v_333_2 * 3) + pub_r001033_20_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((stage_v_44_1 * 3) + pub_r001033_11_1) + 9) & 127;
  int stage_v_379_2 = (((stage_v_44_2 * 3) + pub_r001033_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = (((stage_v_167_1 * 3) + pub_r001033_4_1) + 36) & 127;
  int stage_v_380_2 = (((stage_v_167_2 * 3) + pub_r001033_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = (((sec_r001033_12_1 * 3) + pub_r001033_1_1) + 42) & 127;
  int stage_v_381_2 = (((sec_r001033_12_2 * 3) + pub_r001033_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = (((stage_v_69_1 * 3) + pub_r001033_4_1) + 44) & 127;
  int stage_v_382_2 = (((stage_v_69_2 * 3) + pub_r001033_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = ((pub_r001033_6_1 * 2) + 30) & 63;
  int stage_v_383_2 = ((pub_r001033_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001033_2_1 * 2) + 9) & 63;
  int stage_v_384_2 = ((pub_r001033_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = (((stage_v_303_1 * 3) + pub_r001033_20_1) + 38) & 127;
  int stage_v_385_2 = (((stage_v_303_2 * 3) + pub_r001033_20_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = ((pub_r001033_19_1 * 2) + 50) & 63;
  int stage_v_386_2 = ((pub_r001033_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = (((stage_v_52_1 * 3) + pub_r001033_11_1) + 11) & 127;
  int stage_v_387_2 = (((stage_v_52_2 * 3) + pub_r001033_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = ((pub_r001033_11_1 * 2) + 18) & 63;
  int stage_v_388_2 = ((pub_r001033_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001033_11_1 * 2) + 43) & 63;
  int stage_v_389_2 = ((pub_r001033_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = ((pub_r001033_17_1 * 2) + 24) & 63;
  int stage_v_390_2 = ((pub_r001033_17_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = (((stage_v_89_1 * 3) + pub_r001033_8_1) + 31) & 127;
  int stage_v_391_2 = (((stage_v_89_2 * 3) + pub_r001033_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((stage_v_230_1 * 3) + pub_r001033_1_1) + 44) & 127;
  int stage_v_392_2 = (((stage_v_230_2 * 3) + pub_r001033_1_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = ((pub_r001033_1_1 * 2) + 50) & 63;
  int stage_v_393_2 = ((pub_r001033_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = (((stage_v_212_1 * 3) + pub_r001033_11_1) + 36) & 127;
  int stage_v_394_2 = (((stage_v_212_2 * 3) + pub_r001033_11_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = ((pub_r001033_20_1 * 2) + 39) & 63;
  int stage_v_395_2 = ((pub_r001033_20_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((sec_r001033_11_1 * 3) + pub_r001033_5_1) + 43) & 127;
  int stage_v_396_2 = (((sec_r001033_11_2 * 3) + pub_r001033_5_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = ((pub_r001033_13_1 * 2) + 26) & 63;
  int stage_v_397_2 = ((pub_r001033_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = (((stage_v_212_1 * 3) + pub_r001033_7_1) + 29) & 127;
  int stage_v_398_2 = (((stage_v_212_2 * 3) + pub_r001033_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = (((stage_v_159_1 * 3) + pub_r001033_11_1) + 26) & 127;
  int stage_v_399_2 = (((stage_v_159_2 * 3) + pub_r001033_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = (((stage_v_327_1 * 3) + pub_r001033_14_1) + 22) & 127;
  int stage_v_400_2 = (((stage_v_327_2 * 3) + pub_r001033_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = (((stage_v_230_1 * 3) + pub_r001033_4_1) + 33) & 127;
  int stage_v_401_2 = (((stage_v_230_2 * 3) + pub_r001033_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_401_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_401_2 * 2)) & 255;
  int stage_v_402_1 = ((pub_r001033_10_1 * 2) + 33) & 63;
  int stage_v_402_2 = ((pub_r001033_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((pub_r001033_12_1 * 2) + 45) & 63;
  int stage_v_403_2 = ((pub_r001033_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = ((pub_r001033_4_1 * 2) + 36) & 63;
  int stage_v_404_2 = ((pub_r001033_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = (((stage_v_182_1 * 3) + pub_r001033_1_1) + 25) & 127;
  int stage_v_405_2 = (((stage_v_182_2 * 3) + pub_r001033_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = ((pub_r001033_9_1 * 2) + 50) & 63;
  int stage_v_406_2 = ((pub_r001033_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = (((stage_v_9_1 * 3) + pub_r001033_10_1) + 33) & 127;
  int stage_v_407_2 = (((stage_v_9_2 * 3) + pub_r001033_10_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_407_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_407_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_407_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_407_2 * 2)) & 255;
  int stage_v_408_1 = (((stage_v_232_1 * 3) + pub_r001033_16_1) + 44) & 127;
  int stage_v_408_2 = (((stage_v_232_2 * 3) + pub_r001033_16_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = (((stage_v_2_1 * 3) + pub_r001033_5_1) + 40) & 127;
  int stage_v_409_2 = (((stage_v_2_2 * 3) + pub_r001033_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_409_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_409_2 * 2)) & 255;
  int stage_v_410_1 = (((stage_v_208_1 * 3) + pub_r001033_5_1) + 6) & 127;
  int stage_v_410_2 = (((stage_v_208_2 * 3) + pub_r001033_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_410_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_410_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_410_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_410_2 * 2)) & 255;
  int stage_v_411_1 = (((stage_v_336_1 * 3) + pub_r001033_1_1) + 10) & 127;
  int stage_v_411_2 = (((stage_v_336_2 * 3) + pub_r001033_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_411_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_411_2 * 2)) & 255;
  int stage_v_412_1 = ((pub_r001033_19_1 * 2) + 22) & 63;
  int stage_v_412_2 = ((pub_r001033_19_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((pub_r001033_6_1 * 2) + 15) & 63;
  int stage_v_413_2 = ((pub_r001033_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = (((sec_r001033_10_1 * 3) + pub_r001033_1_1) + 8) & 127;
  int stage_v_414_2 = (((sec_r001033_10_2 * 3) + pub_r001033_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_414_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_414_2 * 2)) & 255;
  int stage_v_415_1 = (((stage_v_310_1 * 3) + pub_r001033_10_1) + 38) & 127;
  int stage_v_415_2 = (((stage_v_310_2 * 3) + pub_r001033_10_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = ((pub_r001033_19_1 * 2) + 30) & 63;
  int stage_v_416_2 = ((pub_r001033_19_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = (((stage_v_256_1 * 3) + pub_r001033_20_1) + 18) & 127;
  int stage_v_417_2 = (((stage_v_256_2 * 3) + pub_r001033_20_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = (((sec_r001033_13_1 * 3) + pub_r001033_16_1) + 34) & 127;
  int stage_v_418_2 = (((sec_r001033_13_2 * 3) + pub_r001033_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_418_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_418_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_418_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_418_2 * 2)) & 255;
  int stage_v_419_1 = (((stage_v_134_1 * 3) + pub_r001033_20_1) + 29) & 127;
  int stage_v_419_2 = (((stage_v_134_2 * 3) + pub_r001033_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = ((pub_r001033_15_1 * 2) + 7) & 63;
  int stage_v_420_2 = ((pub_r001033_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = ((pub_r001033_0_1 * 2) + 35) & 63;
  int stage_v_421_2 = ((pub_r001033_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = (((stage_v_49_1 * 3) + pub_r001033_0_1) + 45) & 127;
  int stage_v_422_2 = (((stage_v_49_2 * 3) + pub_r001033_0_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_422_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_422_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_422_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_422_2 * 2)) & 255;
  int stage_v_423_1 = ((pub_r001033_0_1 * 2) + 25) & 63;
  int stage_v_423_2 = ((pub_r001033_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001033_4_1 * 2) + 39) & 63;
  int stage_v_424_2 = ((pub_r001033_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = (((stage_v_378_1 * 3) + pub_r001033_7_1) + 34) & 127;
  int stage_v_425_2 = (((stage_v_378_2 * 3) + pub_r001033_7_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = ((pub_r001033_6_1 * 2) + 19) & 63;
  int stage_v_426_2 = ((pub_r001033_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((pub_r001033_9_1 * 2) + 44) & 63;
  int stage_v_427_2 = ((pub_r001033_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = ((pub_r001033_11_1 * 2) + 34) & 63;
  int stage_v_428_2 = ((pub_r001033_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = (((stage_v_23_1 * 3) + pub_r001033_13_1) + 38) & 127;
  int stage_v_429_2 = (((stage_v_23_2 * 3) + pub_r001033_13_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = (((stage_v_295_1 * 3) + pub_r001033_3_1) + 11) & 127;
  int stage_v_430_2 = (((stage_v_295_2 * 3) + pub_r001033_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_430_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_430_2 * 2)) & 255;
  int stage_v_431_1 = (((sec_r001033_20_1 * 3) + pub_r001033_7_1) + 10) & 127;
  int stage_v_431_2 = (((sec_r001033_20_2 * 3) + pub_r001033_7_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_431_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_431_2 * 2)) & 255;
  int stage_v_432_1 = ((pub_r001033_10_1 * 2) + 22) & 63;
  int stage_v_432_2 = ((pub_r001033_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = ((pub_r001033_2_1 * 2) + 25) & 63;
  int stage_v_433_2 = ((pub_r001033_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = ((pub_r001033_7_1 * 2) + 16) & 63;
  int stage_v_434_2 = ((pub_r001033_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = (((stage_v_151_1 * 3) + pub_r001033_16_1) + 18) & 127;
  int stage_v_435_2 = (((stage_v_151_2 * 3) + pub_r001033_16_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_435_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_435_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_435_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_435_2 * 2)) & 255;
  int stage_v_436_1 = ((pub_r001033_20_1 * 2) + 20) & 63;
  int stage_v_436_2 = ((pub_r001033_20_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = ((pub_r001033_10_1 * 2) + 31) & 63;
  int stage_v_437_2 = ((pub_r001033_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = ((pub_r001033_4_1 * 2) + 22) & 63;
  int stage_v_438_2 = ((pub_r001033_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = (((stage_v_401_1 * 3) + pub_r001033_0_1) + 9) & 127;
  int stage_v_439_2 = (((stage_v_401_2 * 3) + pub_r001033_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_439_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_439_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_439_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_439_2 * 2)) & 255;
  int stage_v_440_1 = ((pub_r001033_4_1 * 2) + 28) & 63;
  int stage_v_440_2 = ((pub_r001033_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = (((stage_v_5_1 * 3) + pub_r001033_3_1) + 17) & 127;
  int stage_v_441_2 = (((stage_v_5_2 * 3) + pub_r001033_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_441_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_441_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_441_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_441_2 * 2)) & 255;
  int stage_v_442_1 = ((pub_r001033_7_1 * 2) + 12) & 63;
  int stage_v_442_2 = ((pub_r001033_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = ((pub_r001033_2_1 * 2) + 15) & 63;
  int stage_v_443_2 = ((pub_r001033_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001033_5_1 * 2) + 19) & 63;
  int stage_v_444_2 = ((pub_r001033_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = (((helper_flow_3_1 * 3) + pub_r001033_2_1) + 19) & 127;
  int stage_v_445_2 = (((helper_flow_3_2 * 3) + pub_r001033_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_445_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_445_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_445_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_445_2 * 2)) & 255;
  int stage_v_446_1 = (((stage_v_349_1 * 3) + pub_r001033_10_1) + 12) & 127;
  int stage_v_446_2 = (((stage_v_349_2 * 3) + pub_r001033_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_446_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_446_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_446_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_446_2 * 2)) & 255;
  int stage_v_447_1 = (((stage_v_247_1 * 3) + pub_r001033_2_1) + 18) & 127;
  int stage_v_447_2 = (((stage_v_247_2 * 3) + pub_r001033_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_447_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_447_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_447_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_447_2 * 2)) & 255;
  int stage_v_448_1 = ((pub_r001033_16_1 * 2) + 49) & 63;
  int stage_v_448_2 = ((pub_r001033_16_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = (((stage_v_243_1 * 3) + pub_r001033_18_1) + 38) & 127;
  int stage_v_449_2 = (((stage_v_243_2 * 3) + pub_r001033_18_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_449_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_449_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_449_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_449_2 * 2)) & 255;
  int stage_v_450_1 = (((stage_v_83_1 * 3) + pub_r001033_15_1) + 17) & 127;
  int stage_v_450_2 = (((stage_v_83_2 * 3) + pub_r001033_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_450_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_450_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_450_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_450_2 * 2)) & 255;
  int stage_v_451_1 = ((pub_r001033_7_1 * 2) + 31) & 63;
  int stage_v_451_2 = ((pub_r001033_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_451_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_451_2) & 127;
  int stage_v_452_1 = ((pub_r001033_6_1 * 2) + 48) & 63;
  int stage_v_452_2 = ((pub_r001033_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((pub_r001033_7_1 * 2) + 5) & 63;
  int stage_v_453_2 = ((pub_r001033_7_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = ((pub_r001033_15_1 * 2) + 50) & 63;
  int stage_v_454_2 = ((pub_r001033_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = (((stage_v_89_1 * 3) + pub_r001033_7_1) + 37) & 127;
  int stage_v_455_2 = (((stage_v_89_2 * 3) + pub_r001033_7_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_455_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_455_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_455_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_455_2 * 2)) & 255;
  int stage_v_456_1 = ((pub_r001033_13_1 * 2) + 33) & 63;
  int stage_v_456_2 = ((pub_r001033_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_456_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_456_2) & 127;
  int stage_v_457_1 = (((stage_v_70_1 * 3) + pub_r001033_10_1) + 37) & 127;
  int stage_v_457_2 = (((stage_v_70_2 * 3) + pub_r001033_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_457_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_457_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_457_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_457_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001033_15_1 != sec_r001033_15_2);
  __CPROVER_assume(pub_r001033_19_1 == pub_r001033_19_2);
  __CPROVER_assume(pub_r001033_20_1 == pub_r001033_20_2);
  __CPROVER_assume(sec_r001033_5_1 != sec_r001033_5_2);
  __CPROVER_assume(pub_r001033_6_1 == pub_r001033_6_2);
  __CPROVER_assume(sec_r001033_14_1 != sec_r001033_14_2);
  __CPROVER_assume(pub_r001033_10_1 == pub_r001033_10_2);
  __CPROVER_assume(pub_r001033_15_1 == pub_r001033_15_2);
  __CPROVER_assume(pub_r001033_16_1 == pub_r001033_16_2);
  __CPROVER_assume(sec_r001033_17_1 != sec_r001033_17_2);
  __CPROVER_assume(pub_r001033_12_1 == pub_r001033_12_2);
  __CPROVER_assume(pub_r001033_5_1 == pub_r001033_5_2);
  __CPROVER_assume(pub_r001033_13_1 == pub_r001033_13_2);
  __CPROVER_assume(sec_r001033_7_1 != sec_r001033_7_2);
  __CPROVER_assume(pub_r001033_9_1 == pub_r001033_9_2);
  __CPROVER_assume(sec_r001033_3_1 != sec_r001033_3_2);
  __CPROVER_assume(sec_r001033_13_1 != sec_r001033_13_2);
  __CPROVER_assume(sec_r001033_6_1 != sec_r001033_6_2);
  __CPROVER_assume(pub_r001033_14_1 == pub_r001033_14_2);
  __CPROVER_assume(pub_r001033_2_1 == pub_r001033_2_2);
  __CPROVER_assume(pub_r001033_0_1 == pub_r001033_0_2);
  __CPROVER_assume(sec_r001033_8_1 != sec_r001033_8_2);
  __CPROVER_assume(sec_r001033_0_1 != sec_r001033_0_2);
  __CPROVER_assume(pub_r001033_1_1 == pub_r001033_1_2);
  __CPROVER_assume(pub_r001033_17_1 == pub_r001033_17_2);
  __CPROVER_assume(sec_r001033_1_1 != sec_r001033_1_2);
  __CPROVER_assume(pub_r001033_7_1 == pub_r001033_7_2);
  __CPROVER_assume(sec_r001033_2_1 != sec_r001033_2_2);
  __CPROVER_assume(sec_r001033_20_1 != sec_r001033_20_2);
  __CPROVER_assume(pub_r001033_3_1 == pub_r001033_3_2);
  __CPROVER_assume(sec_r001033_11_1 != sec_r001033_11_2);
  __CPROVER_assume(sec_r001033_10_1 != sec_r001033_10_2);
  __CPROVER_assume(pub_r001033_8_1 == pub_r001033_8_2);
  __CPROVER_assume(sec_r001033_18_1 != sec_r001033_18_2);
  __CPROVER_assume(sec_r001033_12_1 != sec_r001033_12_2);
  __CPROVER_assume(pub_r001033_4_1 == pub_r001033_4_2);
  __CPROVER_assume(sec_r001033_16_1 != sec_r001033_16_2);
  __CPROVER_assume(sec_r001033_19_1 != sec_r001033_19_2);
  __CPROVER_assume(sec_r001033_9_1 != sec_r001033_9_2);
  __CPROVER_assume(pub_r001033_11_1 == pub_r001033_11_2);
  __CPROVER_assume(pub_r001033_18_1 == pub_r001033_18_2);
  __CPROVER_assume(sec_r001033_4_1 != sec_r001033_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.density == st_var_1_2.density);
  assert(st_var_1_1.stride == st_var_1_2.stride);
  assert(st_var_1_1.determinant == st_var_1_2.determinant);
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
}


