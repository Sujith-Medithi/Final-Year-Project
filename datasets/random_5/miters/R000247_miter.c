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
struct DeviceConfig_R000247_6724_0
{
  short port;
  int baud_rate;
  unsigned char id;
  int buffer[3];
};
struct EventLog_R000247_6724_1
{
  short timestamp;
  int severity;
  short code;
  int facility;
  int signature;
  int buffer[3];
};
struct MatrixBlock_R000247_6724_2
{
  int dim;
  int stride;
  unsigned char scale;
  int buffer[3];
};
struct CipherContext_R000247_6724_3
{
  short nonce;
  int round_key;
  int flags;
  int buffer[3];
};
union ColorPixel_R000247_6724_0
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
void fn_R000247_6724_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000247_6724_2 st_1 = {0};
  struct MatrixBlock_R000247_6724_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_24_1 = local_arr_1[aux_1 % 3];
  int segment_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_24_2 * 2)) & 127;
  int sample_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_11_1 > 27)
  {
    acc_1 = ((acc_1 + (sample_11_1 * 2)) + 5) & 127;
    aux_1 ^= sample_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_11_2 > 27)
  {
    acc_2 = ((acc_2 + (sample_11_2 * 2)) + 5) & 127;
    aux_2 ^= sample_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_21_1)
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

  switch (window_21_2)
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

  int pivot_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_10_1) & 63;
  aux_2 = (aux_2 + pivot_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_24_1 == segment_24_2);
  assert(sample_11_1 == sample_11_2);
  assert(window_21_1 == window_21_2);
  assert(pivot_10_1 == pivot_10_2);
}

int fn_R000247_6724_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000247_6724_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int segment_24 = local_arr[aux % 3];
  acc = (acc + (segment_24 * 2)) & 127;
  int sample_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_11 > 27)
  {
    acc = ((acc + (sample_11 * 2)) + 5) & 127;
    aux ^= sample_11 & 15;
  }
  else
  {
    acc = ((acc - sample_11) + 11) & 127;
    aux += 3;
  }
  int window_21 = (aux + st.buffer[1]) & 3;
  switch (window_21)
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

  int pivot_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_10) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000247_6724_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000247_6724_2 st_1 = {0};
  struct MatrixBlock_R000247_6724_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int pivot_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_56_1)
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

  switch (pivot_56_2)
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

  int damping_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_51_1 > 35)
  {
    acc_1 = ((acc_1 + (damping_51_1 * 2)) + 5) & 127;
    aux_1 ^= damping_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_51_2 > 35)
  {
    acc_2 = ((acc_2 + (damping_51_2 * 2)) + 5) & 127;
    aux_2 ^= damping_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_45_1 = local_arr_1[aux_1 % 3];
  int parity_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_56_1 == pivot_56_2);
  assert(damping_51_1 == damping_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_45_1 == parity_45_2);
}

int fn_R000247_6724_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000247_6724_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int pivot_56 = (aux + st.buffer[1]) & 3;
  switch (pivot_56)
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

  int damping_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_51 > 35)
  {
    acc = ((acc + (damping_51 * 2)) + 5) & 127;
    aux ^= damping_51 & 15;
  }
  else
  {
    acc = ((acc - damping_51) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_45 = local_arr[aux % 3];
  acc = (acc + (parity_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000247_6724_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000247_6724_1 st_1 = {0};
  struct EventLog_R000247_6724_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int vector_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_89_1)
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

  switch (vector_89_2)
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

  int bound_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_12_1 > 18)
  {
    acc_1 = ((acc_1 + (bound_12_1 * 2)) + 5) & 127;
    aux_1 ^= bound_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_12_2 > 18)
  {
    acc_2 = ((acc_2 + (bound_12_2 * 2)) + 5) & 127;
    aux_2 ^= bound_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_89_1 == vector_89_2);
  assert(bound_12_1 == bound_12_2);
}

int fn_R000247_6724_2(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000247_6724_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int vector_89 = (aux + st.buffer[1]) & 3;
  switch (vector_89)
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

  int bound_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_12 > 18)
  {
    acc = ((acc + (bound_12 * 2)) + 5) & 127;
    aux ^= bound_12 & 15;
  }
  else
  {
    acc = ((acc - bound_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000247_6724_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000247_6724_3 st_1 = {0};
  struct CipherContext_R000247_6724_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int quantum_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_87_1)
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

  switch (quantum_87_2)
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

  int delta_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_89_1 > 10)
  {
    acc_1 = ((acc_1 + (delta_89_1 * 2)) + 5) & 127;
    aux_1 ^= delta_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_89_2 > 10)
  {
    acc_2 = ((acc_2 + (delta_89_2 * 2)) + 5) & 127;
    aux_2 ^= delta_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_87_1 == quantum_87_2);
  assert(delta_89_1 == delta_89_2);
}

int fn_R000247_6724_3(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000247_6724_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int quantum_87 = (aux + st.buffer[1]) & 3;
  switch (quantum_87)
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

  int delta_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_89 > 10)
  {
    acc = ((acc + (delta_89 * 2)) + 5) & 127;
    aux ^= delta_89 & 15;
  }
  else
  {
    acc = ((acc - delta_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000247_6724_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000247_6724_0 st_1 = {0};
  struct DeviceConfig_R000247_6724_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int coefficient_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_17_1) & 63;
  aux_2 = (aux_2 + coefficient_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_11_1 = local_arr_1[aux_1 % 3];
  int segment_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_11_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_17_1 == coefficient_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_11_1 == segment_11_2);
}

int fn_R000247_6724_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000247_6724_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int coefficient_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_17) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_11 = local_arr[aux % 3];
  acc = (acc + (segment_11 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000247_6724_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000247_6724_2 st_1 = {0};
  struct MatrixBlock_R000247_6724_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int accumulator_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_34_1)
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

  switch (accumulator_34_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_40_1 = local_arr_1[aux_1 % 3];
  int stride_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_40_2 * 2)) & 127;
  int anchor_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_94_1) & 63;
  aux_2 = (aux_2 + anchor_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_34_1 == accumulator_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_40_1 == stride_40_2);
  assert(anchor_94_1 == anchor_94_2);
}

int fn_R000247_6724_5(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000247_6724_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int accumulator_34 = (aux + st.buffer[1]) & 3;
  switch (accumulator_34)
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

  int local_arr[3] = {4, 9, 15};
  int stride_40 = local_arr[aux % 3];
  acc = (acc + (stride_40 * 2)) & 127;
  int anchor_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_94) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000247_6724_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000247_6724_1 st_1 = {0};
  struct EventLog_R000247_6724_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int anchor_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_40_1) & 63;
  aux_2 = (aux_2 + anchor_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_40_1 == anchor_40_2);
}

int fn_R000247_6724_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000247_6724_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int anchor_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_40) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000247_6724_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000247_6724_3 st_1 = {0};
  struct CipherContext_R000247_6724_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_79_1)
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

  switch (stride_79_2)
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

  int tally_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_78_1 > 16)
  {
    acc_1 = ((acc_1 + (tally_78_1 * 2)) + 5) & 127;
    aux_1 ^= tally_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_78_2 > 16)
  {
    acc_2 = ((acc_2 + (tally_78_2 * 2)) + 5) & 127;
    aux_2 ^= tally_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_13_1 = local_arr_1[aux_1 % 3];
  int weight_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_79_1 == stride_79_2);
  assert(tally_78_1 == tally_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_13_1 == weight_13_2);
}

int fn_R000247_6724_7(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000247_6724_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_79 = (aux + st.buffer[1]) & 3;
  switch (stride_79)
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

  int tally_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_78 > 16)
  {
    acc = ((acc + (tally_78 * 2)) + 5) & 127;
    aux ^= tally_78 & 15;
  }
  else
  {
    acc = ((acc - tally_78) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int weight_13 = local_arr[aux % 3];
  acc = (acc + (weight_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000247_6724_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000247_6724_1 st_1 = {0};
  struct EventLog_R000247_6724_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int stride_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_20_1)
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

  switch (stride_20_2)
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

  int segment_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_21_1) & 63;
  aux_2 = (aux_2 + segment_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_81_1 = local_arr_1[aux_1 % 3];
  int tally_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_20_1 == stride_20_2);
  assert(segment_21_1 == segment_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_81_1 == tally_81_2);
}

int fn_R000247_6724_8(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000247_6724_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int stride_20 = (aux + st.buffer[1]) & 3;
  switch (stride_20)
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

  int segment_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_21) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_81 = local_arr[aux % 3];
  acc = (acc + (tally_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000247_6724_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000247_6724_1 st_1 = {0};
  struct EventLog_R000247_6724_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int quotient_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_78_1) & 63;
  aux_2 = (aux_2 + quotient_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_37_1 > 45)
  {
    acc_1 = ((acc_1 + (damping_37_1 * 2)) + 5) & 127;
    aux_1 ^= damping_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_37_2 > 45)
  {
    acc_2 = ((acc_2 + (damping_37_2 * 2)) + 5) & 127;
    aux_2 ^= damping_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_58_1)
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

  switch (offset_58_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_65_1 = local_arr_1[aux_1 % 3];
  int pivot_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_65_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_78_1 == quotient_78_2);
  assert(damping_37_1 == damping_37_2);
  assert(offset_58_1 == offset_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_65_1 == pivot_65_2);
}

int fn_R000247_6724_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000247_6724_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int quotient_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_78) & 63;
  acc ^= aux;
  int damping_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_37 > 45)
  {
    acc = ((acc + (damping_37 * 2)) + 5) & 127;
    aux ^= damping_37 & 15;
  }
  else
  {
    acc = ((acc - damping_37) + 11) & 127;
    aux += 3;
  }
  int offset_58 = (aux + st.buffer[1]) & 3;
  switch (offset_58)
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

  int local_arr[3] = {4, 9, 15};
  int pivot_65 = local_arr[aux % 3];
  acc = (acc + (pivot_65 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000247_6724_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000247_6724_0 st_1 = {0};
  struct DeviceConfig_R000247_6724_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int sample_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_59_1)
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

  switch (sample_59_2)
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

  int pivot_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_71_1) & 63;
  aux_2 = (aux_2 + pivot_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_25_1 = local_arr_1[aux_1 % 3];
  int delta_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_25_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_59_1 == sample_59_2);
  assert(pivot_71_1 == pivot_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_25_1 == delta_25_2);
}

int fn_R000247_6724_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000247_6724_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int sample_59 = (aux + st.buffer[1]) & 3;
  switch (sample_59)
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

  int pivot_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_71) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_25 = local_arr[aux % 3];
  acc = (acc + (delta_25 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000247_6724_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000247_6724_3 st_1 = {0};
  struct CipherContext_R000247_6724_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int pivot_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_24_1)
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

  switch (pivot_24_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_89_1 = local_arr_1[aux_1 % 3];
  int factor_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_89_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_24_1 == pivot_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_89_1 == factor_89_2);
}

int fn_R000247_6724_11(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000247_6724_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int pivot_24 = (aux + st.buffer[1]) & 3;
  switch (pivot_24)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int factor_89 = local_arr[aux % 3];
  acc = (acc + (factor_89 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000247_6724_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000247_6724_1 st_1 = {0};
  struct EventLog_R000247_6724_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int threshold_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_25_1) & 63;
  aux_2 = (aux_2 + threshold_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_15_1 > 36)
  {
    acc_1 = ((acc_1 + (quantum_15_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_15_2 > 36)
  {
    acc_2 = ((acc_2 + (quantum_15_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_15_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_25_1 == threshold_25_2);
  assert(quantum_15_1 == quantum_15_2);
}

int fn_R000247_6724_12(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000247_6724_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int threshold_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_25) & 63;
  acc ^= aux;
  int quantum_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_15 > 36)
  {
    acc = ((acc + (quantum_15 * 2)) + 5) & 127;
    aux ^= quantum_15 & 15;
  }
  else
  {
    acc = ((acc - quantum_15) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000247_6724_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000247_6724_2 st_1 = {0};
  struct MatrixBlock_R000247_6724_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_71_1) & 63;
  aux_2 = (aux_2 + accumulator_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_65_1)
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

  switch (margin_65_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_19_1 = local_arr_1[aux_1 % 3];
  int weight_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_71_1 == accumulator_71_2);
  assert(margin_65_1 == margin_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_19_1 == weight_19_2);
}

int fn_R000247_6724_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000247_6724_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_71) & 63;
  acc ^= aux;
  int margin_65 = (aux + st.buffer[1]) & 3;
  switch (margin_65)
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

  int local_arr[3] = {4, 9, 15};
  int weight_19 = local_arr[aux % 3];
  acc = (acc + (weight_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000247_6724_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000247_6724_1 st_1 = {0};
  struct EventLog_R000247_6724_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_84_1)
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

  switch (vector_84_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_84_1 == vector_84_2);
}

int fn_R000247_6724_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000247_6724_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_84 = (aux + st.buffer[1]) & 3;
  switch (vector_84)
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

void main()
{
  int sec_r000247_0_1;
  int sec_r000247_0_2;
  int sec_r000247_1_1;
  int sec_r000247_1_2;
  int sec_r000247_2_1;
  int sec_r000247_2_2;
  int sec_r000247_3_1;
  int sec_r000247_3_2;
  int sec_r000247_4_1;
  int sec_r000247_4_2;
  int sec_r000247_5_1;
  int sec_r000247_5_2;
  int sec_r000247_6_1;
  int sec_r000247_6_2;
  int sec_r000247_7_1;
  int sec_r000247_7_2;
  int sec_r000247_8_1;
  int sec_r000247_8_2;
  int sec_r000247_9_1;
  int sec_r000247_9_2;
  int sec_r000247_10_1;
  int sec_r000247_10_2;
  int sec_r000247_11_1;
  int sec_r000247_11_2;
  int sec_r000247_12_1;
  int sec_r000247_12_2;
  int sec_r000247_13_1;
  int sec_r000247_13_2;
  int sec_r000247_14_1;
  int sec_r000247_14_2;
  int sec_r000247_15_1;
  int sec_r000247_15_2;
  int sec_r000247_16_1;
  int sec_r000247_16_2;
  int sec_r000247_17_1;
  int sec_r000247_17_2;
  int sec_r000247_18_1;
  int sec_r000247_18_2;
  int pub_r000247_0_1;
  int pub_r000247_0_2;
  int pub_r000247_1_1;
  int pub_r000247_1_2;
  int pub_r000247_2_1;
  int pub_r000247_2_2;
  int pub_r000247_3_1;
  int pub_r000247_3_2;
  int pub_r000247_4_1;
  int pub_r000247_4_2;
  int pub_r000247_5_1;
  int pub_r000247_5_2;
  int pub_r000247_6_1;
  int pub_r000247_6_2;
  int pub_r000247_7_1;
  int pub_r000247_7_2;
  int pub_r000247_8_1;
  int pub_r000247_8_2;
  int pub_r000247_9_1;
  int pub_r000247_9_2;
  int pub_r000247_10_1;
  int pub_r000247_10_2;
  int pub_r000247_11_1;
  int pub_r000247_11_2;
  int pub_r000247_12_1;
  int pub_r000247_12_2;
  int pub_r000247_13_1;
  int pub_r000247_13_2;
  int pub_r000247_14_1;
  int pub_r000247_14_2;
  int pub_r000247_15_1;
  int pub_r000247_15_2;
  int pub_r000247_16_1;
  int pub_r000247_16_2;
  int pub_r000247_17_1;
  int pub_r000247_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000247_0_1 >= (-100)) && (pub_r000247_0_1 <= 100));
  __CPROVER_assume((pub_r000247_0_2 >= (-100)) && (pub_r000247_0_2 <= 100));
  __CPROVER_assume((pub_r000247_1_1 >= (-100)) && (pub_r000247_1_1 <= 100));
  __CPROVER_assume((pub_r000247_1_2 >= (-100)) && (pub_r000247_1_2 <= 100));
  __CPROVER_assume((pub_r000247_2_1 >= (-100)) && (pub_r000247_2_1 <= 100));
  __CPROVER_assume((pub_r000247_2_2 >= (-100)) && (pub_r000247_2_2 <= 100));
  __CPROVER_assume((pub_r000247_3_1 >= (-100)) && (pub_r000247_3_1 <= 100));
  __CPROVER_assume((pub_r000247_3_2 >= (-100)) && (pub_r000247_3_2 <= 100));
  __CPROVER_assume((pub_r000247_4_1 >= (-100)) && (pub_r000247_4_1 <= 100));
  __CPROVER_assume((pub_r000247_4_2 >= (-100)) && (pub_r000247_4_2 <= 100));
  __CPROVER_assume((pub_r000247_5_1 >= (-100)) && (pub_r000247_5_1 <= 100));
  __CPROVER_assume((pub_r000247_5_2 >= (-100)) && (pub_r000247_5_2 <= 100));
  __CPROVER_assume((pub_r000247_6_1 >= (-100)) && (pub_r000247_6_1 <= 100));
  __CPROVER_assume((pub_r000247_6_2 >= (-100)) && (pub_r000247_6_2 <= 100));
  __CPROVER_assume((pub_r000247_7_1 >= (-100)) && (pub_r000247_7_1 <= 100));
  __CPROVER_assume((pub_r000247_7_2 >= (-100)) && (pub_r000247_7_2 <= 100));
  __CPROVER_assume((pub_r000247_8_1 >= (-100)) && (pub_r000247_8_1 <= 100));
  __CPROVER_assume((pub_r000247_8_2 >= (-100)) && (pub_r000247_8_2 <= 100));
  __CPROVER_assume((pub_r000247_9_1 >= (-100)) && (pub_r000247_9_1 <= 100));
  __CPROVER_assume((pub_r000247_9_2 >= (-100)) && (pub_r000247_9_2 <= 100));
  __CPROVER_assume((pub_r000247_10_1 >= (-100)) && (pub_r000247_10_1 <= 100));
  __CPROVER_assume((pub_r000247_10_2 >= (-100)) && (pub_r000247_10_2 <= 100));
  __CPROVER_assume((pub_r000247_11_1 >= (-100)) && (pub_r000247_11_1 <= 100));
  __CPROVER_assume((pub_r000247_11_2 >= (-100)) && (pub_r000247_11_2 <= 100));
  __CPROVER_assume((pub_r000247_12_1 >= (-100)) && (pub_r000247_12_1 <= 100));
  __CPROVER_assume((pub_r000247_12_2 >= (-100)) && (pub_r000247_12_2 <= 100));
  __CPROVER_assume((pub_r000247_13_1 >= (-100)) && (pub_r000247_13_1 <= 100));
  __CPROVER_assume((pub_r000247_13_2 >= (-100)) && (pub_r000247_13_2 <= 100));
  __CPROVER_assume((pub_r000247_14_1 >= (-100)) && (pub_r000247_14_1 <= 100));
  __CPROVER_assume((pub_r000247_14_2 >= (-100)) && (pub_r000247_14_2 <= 100));
  __CPROVER_assume((pub_r000247_15_1 >= (-100)) && (pub_r000247_15_1 <= 100));
  __CPROVER_assume((pub_r000247_15_2 >= (-100)) && (pub_r000247_15_2 <= 100));
  __CPROVER_assume((pub_r000247_16_1 >= (-100)) && (pub_r000247_16_1 <= 100));
  __CPROVER_assume((pub_r000247_16_2 >= (-100)) && (pub_r000247_16_2 <= 100));
  __CPROVER_assume((pub_r000247_17_1 >= (-100)) && (pub_r000247_17_1 <= 100));
  __CPROVER_assume((pub_r000247_17_2 >= (-100)) && (pub_r000247_17_2 <= 100));
  __CPROVER_assume((sec_r000247_0_1 >= 0) && (sec_r000247_0_1 <= 255));
  __CPROVER_assume((sec_r000247_0_2 >= 0) && (sec_r000247_0_2 <= 255));
  __CPROVER_assume((sec_r000247_1_1 >= 0) && (sec_r000247_1_1 <= 255));
  __CPROVER_assume((sec_r000247_1_2 >= 0) && (sec_r000247_1_2 <= 255));
  __CPROVER_assume((sec_r000247_2_1 >= 0) && (sec_r000247_2_1 <= 255));
  __CPROVER_assume((sec_r000247_2_2 >= 0) && (sec_r000247_2_2 <= 255));
  __CPROVER_assume((sec_r000247_3_1 >= 0) && (sec_r000247_3_1 <= 255));
  __CPROVER_assume((sec_r000247_3_2 >= 0) && (sec_r000247_3_2 <= 255));
  __CPROVER_assume((sec_r000247_4_1 >= 0) && (sec_r000247_4_1 <= 255));
  __CPROVER_assume((sec_r000247_4_2 >= 0) && (sec_r000247_4_2 <= 255));
  __CPROVER_assume((sec_r000247_5_1 >= 0) && (sec_r000247_5_1 <= 255));
  __CPROVER_assume((sec_r000247_5_2 >= 0) && (sec_r000247_5_2 <= 255));
  __CPROVER_assume((sec_r000247_6_1 >= 0) && (sec_r000247_6_1 <= 255));
  __CPROVER_assume((sec_r000247_6_2 >= 0) && (sec_r000247_6_2 <= 255));
  __CPROVER_assume((sec_r000247_7_1 >= 0) && (sec_r000247_7_1 <= 255));
  __CPROVER_assume((sec_r000247_7_2 >= 0) && (sec_r000247_7_2 <= 255));
  __CPROVER_assume((sec_r000247_8_1 >= 0) && (sec_r000247_8_1 <= 255));
  __CPROVER_assume((sec_r000247_8_2 >= 0) && (sec_r000247_8_2 <= 255));
  __CPROVER_assume((sec_r000247_9_1 >= 0) && (sec_r000247_9_1 <= 255));
  __CPROVER_assume((sec_r000247_9_2 >= 0) && (sec_r000247_9_2 <= 255));
  __CPROVER_assume((sec_r000247_10_1 >= 0) && (sec_r000247_10_1 <= 255));
  __CPROVER_assume((sec_r000247_10_2 >= 0) && (sec_r000247_10_2 <= 255));
  __CPROVER_assume((sec_r000247_11_1 >= 0) && (sec_r000247_11_1 <= 255));
  __CPROVER_assume((sec_r000247_11_2 >= 0) && (sec_r000247_11_2 <= 255));
  __CPROVER_assume((sec_r000247_12_1 >= 0) && (sec_r000247_12_1 <= 255));
  __CPROVER_assume((sec_r000247_12_2 >= 0) && (sec_r000247_12_2 <= 255));
  __CPROVER_assume((sec_r000247_13_1 >= 0) && (sec_r000247_13_1 <= 255));
  __CPROVER_assume((sec_r000247_13_2 >= 0) && (sec_r000247_13_2 <= 255));
  __CPROVER_assume((sec_r000247_14_1 >= 0) && (sec_r000247_14_1 <= 255));
  __CPROVER_assume((sec_r000247_14_2 >= 0) && (sec_r000247_14_2 <= 255));
  __CPROVER_assume((sec_r000247_15_1 >= 0) && (sec_r000247_15_1 <= 255));
  __CPROVER_assume((sec_r000247_15_2 >= 0) && (sec_r000247_15_2 <= 255));
  __CPROVER_assume((sec_r000247_16_1 >= 0) && (sec_r000247_16_1 <= 255));
  __CPROVER_assume((sec_r000247_16_2 >= 0) && (sec_r000247_16_2 <= 255));
  __CPROVER_assume((sec_r000247_17_1 >= 0) && (sec_r000247_17_1 <= 255));
  __CPROVER_assume((sec_r000247_17_2 >= 0) && (sec_r000247_17_2 <= 255));
  __CPROVER_assume((sec_r000247_18_1 >= 0) && (sec_r000247_18_1 <= 255));
  __CPROVER_assume((sec_r000247_18_2 >= 0) && (sec_r000247_18_2 <= 255));
  struct DeviceConfig_R000247_6724_0 st_var_0_1 = {0};
  struct DeviceConfig_R000247_6724_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000247_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000247_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000247_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000247_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000247_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000247_0_2 + 7) & 15;
  struct EventLog_R000247_6724_1 st_var_1_1 = {0};
  struct EventLog_R000247_6724_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000247_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000247_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000247_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000247_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000247_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000247_0_2 + 9) & 15;
  struct MatrixBlock_R000247_6724_2 st_var_2_1 = {0};
  struct MatrixBlock_R000247_6724_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000247_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000247_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000247_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000247_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000247_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000247_0_2 + 11) & 15;
  struct CipherContext_R000247_6724_3 st_var_3_1 = {0};
  struct CipherContext_R000247_6724_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000247_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000247_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000247_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000247_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000247_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000247_0_2 + 13) & 15;
  union ColorPixel_R000247_6724_0 u_var_1;
  union ColorPixel_R000247_6724_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 44)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 44)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 3) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = ((st_var_3_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_3_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 36)
    {
      chk_sum_1 ^= stage_v_3_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_3_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 36)
    {
      chk_sum_2 ^= stage_v_3_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = (st_var_2_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_2_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 8) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = (st_var_0_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_0_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = (st_var_3_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_3_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = (st_var_3_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_3_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = ((st_var_0_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_0_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 32)
    {
      chk_sum_1 ^= stage_v_20_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_20_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 32)
    {
      chk_sum_2 ^= stage_v_20_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 24) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
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
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 31) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  int stage_v_35_1 = (st_var_3_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_3_2.buffer[0] ^ 38) & 3;
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

  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
  int stage_v_38_1 = ((st_var_2_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_2_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 50)
    {
      chk_sum_1 ^= stage_v_38_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_38_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 50)
    {
      chk_sum_2 ^= stage_v_38_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_39_1 = (st_var_3_1.buffer[0] ^ 42) & 3;
  int stage_v_39_2 = (st_var_3_2.buffer[0] ^ 42) & 3;
  switch (stage_v_39_1)
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

  switch (stage_v_39_2)
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

  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 32)
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
  if (stage_v_41_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 32)
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
  int stage_v_43_1 = ((st_var_3_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_3_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 36)
    {
      chk_sum_1 ^= stage_v_43_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_43_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 36)
    {
      chk_sum_2 ^= stage_v_43_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_45_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (50 & 31);
  int stage_v_45_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (50 & 31);
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= (stage_v_45_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_45_2 << 1) & 127;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (st_var_3_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_3_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
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

  switch (stage_v_47_2)
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

  int stage_v_48_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_48_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_49_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (54 & 31);
  int stage_v_49_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (54 & 31);
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= (stage_v_49_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_49_2 << 1) & 127;
  int stage_v_50_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (55 & 31);
  int stage_v_50_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (55 & 31);
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= (stage_v_50_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_50_2 << 1) & 127;
  int stage_v_51_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_51_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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

  int stage_v_53_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_53_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_54_1 = table_1[2];
  int stage_v_54_2 = table_2[2];
  table_1[2] = (table_1[3] + 109) & 63;
  table_2[2] = (table_2[3] + 109) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_55_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
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
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 59) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 59) & 15;
  int stage_v_58_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_58_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= stage_v_58_1;
  chk_sum_2 ^= stage_v_58_2;
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
  int stage_v_60_1 = (st_var_0_1.buffer[0] ^ 63) & 3;
  int stage_v_60_2 = (st_var_0_2.buffer[0] ^ 63) & 3;
  switch (stage_v_60_1)
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

  switch (stage_v_60_2)
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

  int stage_v_61_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (66 & 31);
  int stage_v_61_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (66 & 31);
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= (stage_v_61_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_61_2 << 1) & 127;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((sec_r000247_15_1 & 1) != 0)
  {
    if ((sec_r000247_3_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000247_10_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000247_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000247_10_1 + 7) & 127;
  }
  if ((sec_r000247_15_2 & 1) != 0)
  {
    if ((sec_r000247_3_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000247_10_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000247_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000247_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000247_8_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000247_4_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000247_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000247_4_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000247_8_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000247_4_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000247_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000247_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000247_2_1 & 1) != 0)
  {
    if ((sec_r000247_12_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000247_5_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000247_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000247_5_1 + 7) & 127;
  }
  if ((sec_r000247_2_2 & 1) != 0)
  {
    if ((sec_r000247_12_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000247_5_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000247_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000247_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000247_7_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000247_4_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000247_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000247_4_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000247_7_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000247_4_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000247_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000247_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000247_3_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000247_16_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000247_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000247_16_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000247_3_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000247_16_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000247_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000247_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000247_1_1 & 1) != 0)
  {
    if ((sec_r000247_7_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000247_5_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000247_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000247_5_1 + 7) & 127;
  }
  if ((sec_r000247_1_2 & 1) != 0)
  {
    if ((sec_r000247_7_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000247_5_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000247_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000247_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000247_1_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000247_10_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000247_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000247_10_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000247_1_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000247_10_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000247_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000247_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000247_3_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000247_15_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000247_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000247_15_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000247_3_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000247_15_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000247_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000247_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((sec_r000247_2_1 & 1) != 0)
  {
    if ((sec_r000247_8_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000247_6_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000247_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000247_6_1 + 7) & 127;
  }
  if ((sec_r000247_2_2 & 1) != 0)
  {
    if ((sec_r000247_8_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000247_6_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000247_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000247_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000247_9_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000247_9_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000247_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000247_9_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000247_9_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000247_9_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000247_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000247_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000247_4_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000247_17_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000247_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000247_17_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000247_4_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000247_17_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000247_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000247_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000247_9_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000247_9_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000247_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000247_9_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000247_9_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000247_9_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000247_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000247_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000247_6_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000247_11_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000247_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000247_11_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000247_6_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000247_11_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000247_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000247_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000247_9_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000247_13_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000247_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000247_13_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000247_9_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000247_13_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000247_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000247_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000247_1_1 & 1) != 0)
  {
    if ((sec_r000247_9_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000247_16_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000247_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000247_16_1 + 7) & 127;
  }
  if ((sec_r000247_1_2 & 1) != 0)
  {
    if ((sec_r000247_9_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000247_16_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000247_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000247_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000247_6_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000247_11_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000247_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000247_11_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000247_6_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000247_11_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000247_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000247_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000247_6_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000247_8_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000247_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000247_8_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000247_6_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000247_8_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000247_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000247_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000247_5_1 & 1) != 0)
  {
    if ((sec_r000247_13_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000247_10_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000247_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000247_10_1 + 7) & 127;
  }
  if ((sec_r000247_5_2 & 1) != 0)
  {
    if ((sec_r000247_13_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000247_10_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000247_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000247_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000247_12_1 & 1) != 0)
  {
    if ((sec_r000247_3_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000247_12_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000247_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000247_12_1 + 7) & 127;
  }
  if ((sec_r000247_12_2 & 1) != 0)
  {
    if ((sec_r000247_3_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000247_12_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000247_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000247_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000247_13_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000247_11_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000247_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000247_11_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000247_13_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000247_11_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000247_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000247_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000247_8_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000247_1_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000247_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000247_1_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000247_8_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000247_1_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000247_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000247_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000247_6_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000247_6_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000247_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000247_6_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000247_6_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000247_6_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000247_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000247_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000247_8_1 & 1) != 0)
  {
    if ((sec_r000247_13_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000247_0_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000247_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000247_0_1 + 7) & 127;
  }
  if ((sec_r000247_8_2 & 1) != 0)
  {
    if ((sec_r000247_13_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000247_0_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000247_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000247_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000247_11_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000247_0_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000247_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000247_0_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000247_11_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000247_0_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000247_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000247_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000247_13_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000247_14_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000247_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000247_14_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000247_13_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000247_14_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000247_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000247_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((sec_r000247_2_1 & 1) != 0)
  {
    if ((sec_r000247_1_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000247_7_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000247_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000247_7_1 + 7) & 127;
  }
  if ((sec_r000247_2_2 & 1) != 0)
  {
    if ((sec_r000247_1_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000247_7_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000247_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000247_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000247_12_1 & 1) != 0)
  {
    if ((sec_r000247_13_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000247_7_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000247_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000247_7_1 + 7) & 127;
  }
  if ((sec_r000247_12_2 & 1) != 0)
  {
    if ((sec_r000247_13_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000247_7_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000247_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000247_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000247_18_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000247_17_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000247_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000247_17_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000247_18_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000247_17_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000247_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000247_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000247_12_1 & 1) != 0)
  {
    if ((sec_r000247_11_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000247_12_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000247_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000247_12_1 + 7) & 127;
  }
  if ((sec_r000247_12_2 & 1) != 0)
  {
    if ((sec_r000247_11_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000247_12_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000247_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000247_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000247_5_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000247_17_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000247_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000247_17_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000247_5_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000247_17_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000247_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000247_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000247_9_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000247_12_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000247_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000247_12_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000247_9_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000247_12_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000247_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000247_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000247_13_1 & 1) != 0)
  {
    if ((sec_r000247_11_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000247_5_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000247_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000247_5_1 + 7) & 127;
  }
  if ((sec_r000247_13_2 & 1) != 0)
  {
    if ((sec_r000247_11_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000247_5_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000247_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000247_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000247_16_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000247_14_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000247_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000247_14_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000247_16_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000247_14_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000247_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000247_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000247_6_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000247_11_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000247_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000247_11_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000247_6_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000247_11_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000247_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000247_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000247_10_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000247_3_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000247_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000247_3_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000247_10_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000247_3_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000247_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000247_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000247_8_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000247_16_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000247_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000247_16_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000247_8_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000247_16_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000247_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000247_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000247_15_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000247_6_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000247_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000247_6_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000247_15_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000247_6_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000247_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000247_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000247_16_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000247_6_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000247_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000247_6_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000247_16_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000247_6_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000247_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000247_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000247_18_1 & 1) != 0)
  {
    if ((sec_r000247_0_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000247_15_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000247_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000247_15_1 + 7) & 127;
  }
  if ((sec_r000247_18_2 & 1) != 0)
  {
    if ((sec_r000247_0_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000247_15_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000247_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000247_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000247_5_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000247_7_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000247_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000247_7_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000247_5_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000247_7_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000247_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000247_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000247_4_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000247_4_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000247_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000247_4_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000247_4_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000247_4_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000247_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000247_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000247_7_1 & 1) != 0)
  {
    if ((sec_r000247_10_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000247_1_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000247_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000247_1_1 + 7) & 127;
  }
  if ((sec_r000247_7_2 & 1) != 0)
  {
    if ((sec_r000247_10_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000247_1_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000247_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000247_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000247_15_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000247_16_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000247_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000247_16_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000247_15_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000247_16_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000247_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000247_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000247_10_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000247_3_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000247_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000247_3_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000247_10_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000247_3_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000247_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000247_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000247_13_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000247_12_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000247_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000247_12_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000247_13_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000247_12_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000247_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000247_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000247_18_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000247_3_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000247_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000247_3_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000247_18_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000247_3_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000247_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000247_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000247_15_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000247_10_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000247_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000247_10_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000247_15_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000247_10_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000247_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000247_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000247_12_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000247_9_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000247_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000247_9_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000247_12_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000247_9_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000247_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000247_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000247_5_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000247_1_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000247_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000247_1_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000247_5_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000247_1_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000247_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000247_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000247_7_1 & 1) != 0)
  {
    if ((sec_r000247_17_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000247_1_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000247_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000247_1_1 + 7) & 127;
  }
  if ((sec_r000247_7_2 & 1) != 0)
  {
    if ((sec_r000247_17_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000247_1_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000247_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000247_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000247_15_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000247_6_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000247_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000247_6_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000247_15_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000247_6_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000247_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000247_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000247_17_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000247_17_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000247_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000247_17_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000247_17_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000247_17_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000247_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000247_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000247_5_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000247_3_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000247_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000247_3_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000247_5_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000247_3_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000247_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000247_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000247_13_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000247_14_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000247_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000247_14_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000247_13_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000247_14_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000247_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000247_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000247_9_1 & 1) != 0)
  {
    if ((sec_r000247_8_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000247_2_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000247_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000247_2_1 + 7) & 127;
  }
  if ((sec_r000247_9_2 & 1) != 0)
  {
    if ((sec_r000247_8_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000247_2_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000247_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000247_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000247_7_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000247_16_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000247_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000247_16_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000247_7_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000247_16_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000247_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000247_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000247_3_1 & 1) != 0)
  {
    if ((sec_r000247_6_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000247_3_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000247_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000247_3_1 + 7) & 127;
  }
  if ((sec_r000247_3_2 & 1) != 0)
  {
    if ((sec_r000247_6_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000247_3_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000247_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000247_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000247_4_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000247_6_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000247_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000247_6_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000247_4_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000247_6_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000247_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000247_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000247_15_1 & 1) != 0)
  {
    if ((sec_r000247_7_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000247_5_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000247_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000247_5_1 + 7) & 127;
  }
  if ((sec_r000247_15_2 & 1) != 0)
  {
    if ((sec_r000247_7_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000247_5_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000247_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000247_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000247_14_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000247_4_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000247_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000247_4_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000247_14_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000247_4_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000247_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000247_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000247_4_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000247_5_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000247_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000247_5_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000247_4_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000247_5_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000247_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000247_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000247_10_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000247_11_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000247_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000247_11_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000247_10_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000247_11_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000247_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000247_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000247_15_1 & 1) != 0)
  {
    if ((sec_r000247_14_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000247_13_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000247_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000247_13_1 + 7) & 127;
  }
  if ((sec_r000247_15_2 & 1) != 0)
  {
    if ((sec_r000247_14_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000247_13_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000247_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000247_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000247_7_1 & 1) != 0)
  {
    if ((sec_r000247_4_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000247_4_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000247_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000247_4_1 + 7) & 127;
  }
  if ((sec_r000247_7_2 & 1) != 0)
  {
    if ((sec_r000247_4_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000247_4_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000247_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000247_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000247_15_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000247_7_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000247_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000247_7_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000247_15_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000247_7_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000247_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000247_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000247_14_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000247_11_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000247_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000247_11_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000247_14_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000247_11_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000247_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000247_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000247_8_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000247_16_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000247_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000247_16_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000247_8_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000247_16_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000247_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000247_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000247_16_1 & 1) != 0)
  {
    if ((sec_r000247_15_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000247_17_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000247_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000247_17_1 + 7) & 127;
  }
  if ((sec_r000247_16_2 & 1) != 0)
  {
    if ((sec_r000247_15_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000247_17_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000247_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000247_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000247_15_1 & 1) != 0)
  {
    if ((sec_r000247_14_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000247_9_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000247_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000247_9_1 + 7) & 127;
  }
  if ((sec_r000247_15_2 & 1) != 0)
  {
    if ((sec_r000247_14_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000247_9_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000247_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000247_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000247_13_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000247_9_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000247_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000247_9_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000247_13_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000247_9_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000247_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000247_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000247_2_1 & 1) != 0)
  {
    if ((sec_r000247_7_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000247_4_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000247_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000247_4_1 + 7) & 127;
  }
  if ((sec_r000247_2_2 & 1) != 0)
  {
    if ((sec_r000247_7_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000247_4_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000247_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000247_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000247_9_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000247_11_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000247_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000247_11_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000247_9_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000247_11_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000247_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000247_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000247_14_1 & 1) != 0)
  {
    if ((sec_r000247_14_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000247_2_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000247_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000247_2_1 + 7) & 127;
  }
  if ((sec_r000247_14_2 & 1) != 0)
  {
    if ((sec_r000247_14_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000247_2_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000247_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000247_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r000247_7_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000247_2_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000247_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000247_2_1 + 7) & 127;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r000247_7_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000247_2_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000247_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000247_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000247_9_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000247_4_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000247_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000247_4_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000247_9_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000247_4_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000247_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000247_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((sec_r000247_17_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000247_11_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000247_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000247_11_1 + 7) & 127;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((sec_r000247_17_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000247_11_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000247_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000247_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000247_7_1 & 1) != 0)
  {
    if ((sec_r000247_12_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000247_10_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000247_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000247_10_1 + 7) & 127;
  }
  if ((sec_r000247_7_2 & 1) != 0)
  {
    if ((sec_r000247_12_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000247_10_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000247_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000247_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000247_12_1 & 1) != 0)
  {
    if ((sec_r000247_0_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000247_13_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000247_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000247_13_1 + 7) & 127;
  }
  if ((sec_r000247_12_2 & 1) != 0)
  {
    if ((sec_r000247_0_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000247_13_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000247_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000247_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000247_11_1 & 1) != 0)
  {
    if ((sec_r000247_2_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000247_15_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000247_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000247_15_1 + 7) & 127;
  }
  if ((sec_r000247_11_2 & 1) != 0)
  {
    if ((sec_r000247_2_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000247_15_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000247_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000247_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000247_16_1 & 1) != 0)
  {
    if ((sec_r000247_3_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000247_17_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000247_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000247_17_1 + 7) & 127;
  }
  if ((sec_r000247_16_2 & 1) != 0)
  {
    if ((sec_r000247_3_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000247_17_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000247_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000247_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000247_5_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000247_0_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000247_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000247_0_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000247_5_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000247_0_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000247_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000247_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r000247_4_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000247_8_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000247_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000247_8_1 + 7) & 127;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r000247_4_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000247_8_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000247_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000247_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000247_1_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000247_15_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000247_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000247_15_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000247_1_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000247_15_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000247_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000247_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((sec_r000247_7_1 & 1) != 0)
  {
    if ((sec_r000247_9_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000247_2_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000247_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000247_2_1 + 7) & 127;
  }
  if ((sec_r000247_7_2 & 1) != 0)
  {
    if ((sec_r000247_9_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000247_2_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000247_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000247_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000247_10_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000247_17_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000247_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000247_17_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000247_10_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000247_17_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000247_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000247_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((sec_r000247_10_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000247_12_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000247_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000247_12_1 + 7) & 127;
  }
  if ((stage_v_142_2 & 1) != 0)
  {
    if ((sec_r000247_10_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000247_12_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000247_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000247_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000247_16_1 & 1) != 0)
  {
    if ((sec_r000247_8_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000247_9_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000247_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000247_9_1 + 7) & 127;
  }
  if ((sec_r000247_16_2 & 1) != 0)
  {
    if ((sec_r000247_8_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000247_9_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000247_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000247_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000247_4_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000247_0_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000247_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000247_0_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000247_4_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000247_0_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000247_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000247_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((sec_r000247_16_1 & 1) != 0)
  {
    if ((sec_r000247_9_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000247_4_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000247_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000247_4_1 + 7) & 127;
  }
  if ((sec_r000247_16_2 & 1) != 0)
  {
    if ((sec_r000247_9_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000247_4_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000247_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000247_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000247_12_1 != sec_r000247_12_2);
  __CPROVER_assume(pub_r000247_16_1 == pub_r000247_16_2);
  __CPROVER_assume(pub_r000247_7_1 == pub_r000247_7_2);
  __CPROVER_assume(pub_r000247_9_1 == pub_r000247_9_2);
  __CPROVER_assume(pub_r000247_15_1 == pub_r000247_15_2);
  __CPROVER_assume(pub_r000247_3_1 == pub_r000247_3_2);
  __CPROVER_assume(sec_r000247_0_1 != sec_r000247_0_2);
  __CPROVER_assume(sec_r000247_9_1 != sec_r000247_9_2);
  __CPROVER_assume(pub_r000247_5_1 == pub_r000247_5_2);
  __CPROVER_assume(pub_r000247_12_1 == pub_r000247_12_2);
  __CPROVER_assume(sec_r000247_10_1 != sec_r000247_10_2);
  __CPROVER_assume(pub_r000247_14_1 == pub_r000247_14_2);
  __CPROVER_assume(sec_r000247_3_1 != sec_r000247_3_2);
  __CPROVER_assume(sec_r000247_16_1 != sec_r000247_16_2);
  __CPROVER_assume(pub_r000247_8_1 == pub_r000247_8_2);
  __CPROVER_assume(pub_r000247_17_1 == pub_r000247_17_2);
  __CPROVER_assume(sec_r000247_6_1 != sec_r000247_6_2);
  __CPROVER_assume(sec_r000247_1_1 != sec_r000247_1_2);
  __CPROVER_assume(sec_r000247_8_1 != sec_r000247_8_2);
  __CPROVER_assume(pub_r000247_6_1 == pub_r000247_6_2);
  __CPROVER_assume(sec_r000247_14_1 != sec_r000247_14_2);
  __CPROVER_assume(sec_r000247_17_1 != sec_r000247_17_2);
  __CPROVER_assume(pub_r000247_11_1 == pub_r000247_11_2);
  __CPROVER_assume(sec_r000247_13_1 != sec_r000247_13_2);
  __CPROVER_assume(pub_r000247_2_1 == pub_r000247_2_2);
  __CPROVER_assume(pub_r000247_13_1 == pub_r000247_13_2);
  __CPROVER_assume(pub_r000247_10_1 == pub_r000247_10_2);
  __CPROVER_assume(sec_r000247_7_1 != sec_r000247_7_2);
  __CPROVER_assume(sec_r000247_15_1 != sec_r000247_15_2);
  __CPROVER_assume(sec_r000247_18_1 != sec_r000247_18_2);
  __CPROVER_assume(sec_r000247_11_1 != sec_r000247_11_2);
  __CPROVER_assume(sec_r000247_4_1 != sec_r000247_4_2);
  __CPROVER_assume(sec_r000247_5_1 != sec_r000247_5_2);
  __CPROVER_assume(pub_r000247_4_1 == pub_r000247_4_2);
  __CPROVER_assume(sec_r000247_2_1 != sec_r000247_2_2);
  __CPROVER_assume(pub_r000247_0_1 == pub_r000247_0_2);
  __CPROVER_assume(pub_r000247_1_1 == pub_r000247_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.id == st_var_0_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.nonce == st_var_3_2.nonce);
  assert(st_var_3_1.round_key == st_var_3_2.round_key);
  assert(st_var_3_1.flags == st_var_3_2.flags);
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
}


