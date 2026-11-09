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
struct AudioFrame_R001096_9613_0
{
  int gain;
  int sample_rate;
  unsigned char peak;
  int envelope;
  int buffer[3];
};
struct Vector3D_R001096_9613_1
{
  unsigned char coord_z;
  int coord_x;
  int pitch;
  int heading;
  int norm_sq;
  short coord_y;
  int buffer[3];
};
struct MatrixBlock_R001096_9613_2
{
  int stride;
  short determinant;
  int scale;
  short trace;
  int buffer[3];
};
struct DeviceConfig_R001096_9613_3
{
  int id;
  int stop_bits;
  short baud_rate;
  unsigned char parity;
  int buffer[3];
};
union RegisterBank_R001096_9613_0
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
void fn_R001096_9613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st_1 = {0};
  struct AudioFrame_R001096_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_72_1 > 40)
  {
    acc_1 = ((acc_1 + (offset_72_1 * 2)) + 5) & 127;
    aux_1 ^= offset_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_72_2 > 40)
  {
    acc_2 = ((acc_2 + (offset_72_2 * 2)) + 5) & 127;
    aux_2 ^= offset_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_11_1)
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

  switch (quantum_11_2)
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

  int stride_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_54_1) & 63;
  aux_2 = (aux_2 + stride_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_72_1 == offset_72_2);
  assert(quantum_11_1 == quantum_11_2);
  assert(stride_54_1 == stride_54_2);
}

int fn_R001096_9613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_72 > 40)
  {
    acc = ((acc + (offset_72 * 2)) + 5) & 127;
    aux ^= offset_72 & 15;
  }
  else
  {
    acc = ((acc - offset_72) + 11) & 127;
    aux += 3;
  }
  int quantum_11 = (aux + st.buffer[1]) & 3;
  switch (quantum_11)
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

  int stride_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001096_9613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001096_9613_3 st_1 = {0};
  struct DeviceConfig_R001096_9613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int accumulator_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_22_1) & 63;
  aux_2 = (aux_2 + accumulator_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_24_1)
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

  switch (stride_24_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_22_1 == accumulator_22_2);
  assert(stride_24_1 == stride_24_2);
}

int fn_R001096_9613_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001096_9613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int accumulator_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_22) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_24 = (aux + st.buffer[1]) & 3;
  switch (stride_24)
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

void fn_R001096_9613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st_1 = {0};
  struct AudioFrame_R001096_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_31_1 = local_arr_1[aux_1 % 3];
  int threshold_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_31_2 * 2)) & 127;
  int vector_21_1 = 0;
  int vector_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_21_1 = ((vector_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_21_2 = ((vector_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_21_1) & 127;
    acc_2 = (acc_2 + vector_21_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_89_1) & 63;
  aux_2 = (aux_2 + stride_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_31_1 == threshold_31_2);
  assert(vector_21_1 == vector_21_2);
  assert(stride_89_1 == stride_89_2);
}

int fn_R001096_9613_2(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int threshold_31 = local_arr[aux % 3];
  acc = (acc + (threshold_31 * 2)) & 127;
  int vector_21 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_21 = ((vector_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_21) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_89) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001096_9613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001096_9613_2 st_1 = {0};
  struct MatrixBlock_R001096_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int residue_51_1 = 0;
  int residue_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_51_1 = ((residue_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_51_2 = ((residue_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_51_1) & 127;
    acc_2 = (acc_2 + residue_51_2) & 127;
  }

  int delta_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_10_1) & 63;
  aux_2 = (aux_2 + delta_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_75_1 = local_arr_1[aux_1 % 3];
  int damping_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_75_2 * 2)) & 127;
  int stride_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_27_1)
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

  switch (stride_27_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_51_1 == residue_51_2);
  assert(delta_10_1 == delta_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_75_1 == damping_75_2);
  assert(stride_27_1 == stride_27_2);
}

int fn_R001096_9613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001096_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int residue_51 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_51 = ((residue_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_51) & 127;
  }

  int delta_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_10) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int damping_75 = local_arr[aux % 3];
  acc = (acc + (damping_75 * 2)) & 127;
  int stride_27 = (aux + st.buffer[1]) & 3;
  switch (stride_27)
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

void fn_R001096_9613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st_1 = {0};
  struct AudioFrame_R001096_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_27_1 = local_arr_1[aux_1 % 3];
  int scale_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_27_2 * 2)) & 127;
  int weight_21_1 = 0;
  int weight_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_21_1 = ((weight_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_21_2 = ((weight_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_21_1) & 127;
    acc_2 = (acc_2 + weight_21_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_27_1 == scale_27_2);
  assert(weight_21_1 == weight_21_2);
}

int fn_R001096_9613_4(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int scale_27 = local_arr[aux % 3];
  acc = (acc + (scale_27 * 2)) & 127;
  int weight_21 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_21 = ((weight_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_21) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001096_9613_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001096_9613_2 st_1 = {0};
  struct MatrixBlock_R001096_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int margin_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_49_1) & 63;
  aux_2 = (aux_2 + margin_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_48_1 = local_arr_1[aux_1 % 3];
  int tally_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_48_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_49_1 == margin_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_48_1 == tally_48_2);
}

int fn_R001096_9613_5(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001096_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int margin_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_49) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_48 = local_arr[aux % 3];
  acc = (acc + (tally_48 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001096_9613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st_1 = {0};
  struct AudioFrame_R001096_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int segment_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_67_1) & 63;
  aux_2 = (aux_2 + segment_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_64_1 > 17)
  {
    acc_1 = ((acc_1 + (scale_64_1 * 2)) + 5) & 127;
    aux_1 ^= scale_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_64_2 > 17)
  {
    acc_2 = ((acc_2 + (scale_64_2 * 2)) + 5) & 127;
    aux_2 ^= scale_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_67_1 == segment_67_2);
  assert(scale_64_1 == scale_64_2);
}

int fn_R001096_9613_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int segment_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_67) & 63;
  acc ^= aux;
  int scale_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_64 > 17)
  {
    acc = ((acc + (scale_64 * 2)) + 5) & 127;
    aux ^= scale_64 & 15;
  }
  else
  {
    acc = ((acc - scale_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001096_9613_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001096_9613_1 st_1 = {0};
  struct Vector3D_R001096_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_78_1 = 0;
  int bound_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_78_1 = ((bound_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_78_2 = ((bound_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_78_1) & 127;
    acc_2 = (acc_2 + bound_78_2) & 127;
  }

  int checksum_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_79_1 > 12)
  {
    acc_1 = ((acc_1 + (checksum_79_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_79_2 > 12)
  {
    acc_2 = ((acc_2 + (checksum_79_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_75_1) & 63;
  aux_2 = (aux_2 + pivot_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_78_1 == bound_78_2);
  assert(checksum_79_1 == checksum_79_2);
  assert(pivot_75_1 == pivot_75_2);
}

int fn_R001096_9613_7(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001096_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_78 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_78 = ((bound_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_78) & 127;
  }

  int checksum_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_79 > 12)
  {
    acc = ((acc + (checksum_79 * 2)) + 5) & 127;
    aux ^= checksum_79 & 15;
  }
  else
  {
    acc = ((acc - checksum_79) + 11) & 127;
    aux += 3;
  }
  int pivot_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001096_9613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st_1 = {0};
  struct AudioFrame_R001096_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int cursor_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_65_1) & 63;
  aux_2 = (aux_2 + cursor_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_12_1 > 46)
  {
    acc_1 = ((acc_1 + (parity_12_1 * 2)) + 5) & 127;
    aux_1 ^= parity_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_12_2 > 46)
  {
    acc_2 = ((acc_2 + (parity_12_2 * 2)) + 5) & 127;
    aux_2 ^= parity_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_65_1 == cursor_65_2);
  assert(parity_12_1 == parity_12_2);
}

int fn_R001096_9613_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int cursor_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_65) & 63;
  acc ^= aux;
  int parity_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_12 > 46)
  {
    acc = ((acc + (parity_12 * 2)) + 5) & 127;
    aux ^= parity_12 & 15;
  }
  else
  {
    acc = ((acc - parity_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001096_9613_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st_1 = {0};
  struct AudioFrame_R001096_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int residue_99_1 = 0;
  int residue_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_99_1 = ((residue_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_99_2 = ((residue_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_99_1) & 127;
    acc_2 = (acc_2 + residue_99_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_99_1 == residue_99_2);
}

int fn_R001096_9613_9(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int residue_99 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_99 = ((residue_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_99) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001096_9613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001096_9613_2 st_1 = {0};
  struct MatrixBlock_R001096_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int coefficient_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_65_1)
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

  switch (coefficient_65_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_45_1 > 32)
  {
    acc_1 = ((acc_1 + (scale_45_1 * 2)) + 5) & 127;
    aux_1 ^= scale_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_45_2 > 32)
  {
    acc_2 = ((acc_2 + (scale_45_2 * 2)) + 5) & 127;
    aux_2 ^= scale_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_45_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_65_1 == coefficient_65_2);
  assert(scale_45_1 == scale_45_2);
}

int fn_R001096_9613_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001096_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int coefficient_65 = (aux + st.buffer[1]) & 3;
  switch (coefficient_65)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_45 > 32)
  {
    acc = ((acc + (scale_45 * 2)) + 5) & 127;
    aux ^= scale_45 & 15;
  }
  else
  {
    acc = ((acc - scale_45) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001096_9613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st_1 = {0};
  struct AudioFrame_R001096_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_32_1 = local_arr_1[aux_1 % 3];
  int parity_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_32_2 * 2)) & 127;
  int tracker_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_57_1)
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

  switch (tracker_57_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_32_1 == parity_32_2);
  assert(tracker_57_1 == tracker_57_2);
}

int fn_R001096_9613_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_32 = local_arr[aux % 3];
  acc = (acc + (parity_32 * 2)) & 127;
  int tracker_57 = (aux + st.buffer[1]) & 3;
  switch (tracker_57)
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

void fn_R001096_9613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001096_9613_2 st_1 = {0};
  struct MatrixBlock_R001096_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_67_1) & 63;
  aux_2 = (aux_2 + tracker_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_42_1)
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

  switch (residue_42_2)
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
  int sample_39_1 = local_arr_1[aux_1 % 3];
  int sample_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_39_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_67_1 == tracker_67_2);
  assert(residue_42_1 == residue_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_39_1 == sample_39_2);
}

int fn_R001096_9613_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001096_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_67) & 63;
  acc ^= aux;
  int residue_42 = (aux + st.buffer[1]) & 3;
  switch (residue_42)
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
  int sample_39 = local_arr[aux % 3];
  acc = (acc + (sample_39 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001096_9613_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001096_9613_1 st_1 = {0};
  struct Vector3D_R001096_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int parity_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_12_1 > 39)
  {
    acc_1 = ((acc_1 + (parity_12_1 * 2)) + 5) & 127;
    aux_1 ^= parity_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_12_2 > 39)
  {
    acc_2 = ((acc_2 + (parity_12_2 * 2)) + 5) & 127;
    aux_2 ^= parity_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_11_1) & 63;
  aux_2 = (aux_2 + quantum_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_12_1 == parity_12_2);
  assert(quantum_11_1 == quantum_11_2);
}

int fn_R001096_9613_13(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001096_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int parity_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_12 > 39)
  {
    acc = ((acc + (parity_12 * 2)) + 5) & 127;
    aux ^= parity_12 & 15;
  }
  else
  {
    acc = ((acc - parity_12) + 11) & 127;
    aux += 3;
  }
  int quantum_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_11) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001096_9613_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st_1 = {0};
  struct AudioFrame_R001096_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_30_1 = local_arr_1[aux_1 % 3];
  int vector_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_30_2 * 2)) & 127;
  int tally_40_1 = 0;
  int tally_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_40_1 = ((tally_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_40_2 = ((tally_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_40_1) & 127;
    acc_2 = (acc_2 + tally_40_2) & 127;
  }

  int parity_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_72_1 > 33)
  {
    acc_1 = ((acc_1 + (parity_72_1 * 2)) + 5) & 127;
    aux_1 ^= parity_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_72_2 > 33)
  {
    acc_2 = ((acc_2 + (parity_72_2 * 2)) + 5) & 127;
    aux_2 ^= parity_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_83_1)
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

  switch (coefficient_83_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_30_1 == vector_30_2);
  assert(tally_40_1 == tally_40_2);
  assert(parity_72_1 == parity_72_2);
  assert(coefficient_83_1 == coefficient_83_2);
}

int fn_R001096_9613_14(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int vector_30 = local_arr[aux % 3];
  acc = (acc + (vector_30 * 2)) & 127;
  int tally_40 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_40 = ((tally_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_40) & 127;
  }

  int parity_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_72 > 33)
  {
    acc = ((acc + (parity_72 * 2)) + 5) & 127;
    aux ^= parity_72 & 15;
  }
  else
  {
    acc = ((acc - parity_72) + 11) & 127;
    aux += 3;
  }
  int coefficient_83 = (aux + st.buffer[1]) & 3;
  switch (coefficient_83)
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

void fn_R001096_9613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st_1 = {0};
  struct AudioFrame_R001096_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int vector_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_57_1)
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

  switch (vector_57_2)
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
  int scale_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_65_1 > 28)
  {
    acc_1 = ((acc_1 + (scale_65_1 * 2)) + 5) & 127;
    aux_1 ^= scale_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_65_2 > 28)
  {
    acc_2 = ((acc_2 + (scale_65_2 * 2)) + 5) & 127;
    aux_2 ^= scale_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_65_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_57_1 == vector_57_2);
  assert(scale_65_1 == scale_65_2);
}

int fn_R001096_9613_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001096_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int vector_57 = (aux + st.buffer[1]) & 3;
  switch (vector_57)
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
  int scale_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_65 > 28)
  {
    acc = ((acc + (scale_65 * 2)) + 5) & 127;
    aux ^= scale_65 & 15;
  }
  else
  {
    acc = ((acc - scale_65) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001096_9613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001096_9613_1 st_1 = {0};
  struct Vector3D_R001096_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int anchor_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_54_1)
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

  switch (anchor_54_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_60_1 = local_arr_1[aux_1 % 3];
  int residue_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_60_2 * 2)) & 127;
  int stride_65_1 = 0;
  int stride_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_65_1 = ((stride_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_65_2 = ((stride_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_65_1) & 127;
    acc_2 = (acc_2 + stride_65_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_54_1 == anchor_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_60_1 == residue_60_2);
  assert(stride_65_1 == stride_65_2);
}

int fn_R001096_9613_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001096_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int anchor_54 = (aux + st.buffer[1]) & 3;
  switch (anchor_54)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_60 = local_arr[aux % 3];
  acc = (acc + (residue_60 * 2)) & 127;
  int stride_65 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_65 = ((stride_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_65) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001096_0_1;
  int sec_r001096_0_2;
  int sec_r001096_1_1;
  int sec_r001096_1_2;
  int sec_r001096_2_1;
  int sec_r001096_2_2;
  int sec_r001096_3_1;
  int sec_r001096_3_2;
  int sec_r001096_4_1;
  int sec_r001096_4_2;
  int sec_r001096_5_1;
  int sec_r001096_5_2;
  int sec_r001096_6_1;
  int sec_r001096_6_2;
  int sec_r001096_7_1;
  int sec_r001096_7_2;
  int sec_r001096_8_1;
  int sec_r001096_8_2;
  int sec_r001096_9_1;
  int sec_r001096_9_2;
  int sec_r001096_10_1;
  int sec_r001096_10_2;
  int sec_r001096_11_1;
  int sec_r001096_11_2;
  int sec_r001096_12_1;
  int sec_r001096_12_2;
  int sec_r001096_13_1;
  int sec_r001096_13_2;
  int sec_r001096_14_1;
  int sec_r001096_14_2;
  int sec_r001096_15_1;
  int sec_r001096_15_2;
  int pub_r001096_0_1;
  int pub_r001096_0_2;
  int pub_r001096_1_1;
  int pub_r001096_1_2;
  int pub_r001096_2_1;
  int pub_r001096_2_2;
  int pub_r001096_3_1;
  int pub_r001096_3_2;
  int pub_r001096_4_1;
  int pub_r001096_4_2;
  int pub_r001096_5_1;
  int pub_r001096_5_2;
  int pub_r001096_6_1;
  int pub_r001096_6_2;
  int pub_r001096_7_1;
  int pub_r001096_7_2;
  int pub_r001096_8_1;
  int pub_r001096_8_2;
  int pub_r001096_9_1;
  int pub_r001096_9_2;
  int pub_r001096_10_1;
  int pub_r001096_10_2;
  int pub_r001096_11_1;
  int pub_r001096_11_2;
  int pub_r001096_12_1;
  int pub_r001096_12_2;
  int pub_r001096_13_1;
  int pub_r001096_13_2;
  int pub_r001096_14_1;
  int pub_r001096_14_2;
  int pub_r001096_15_1;
  int pub_r001096_15_2;
  int pub_r001096_16_1;
  int pub_r001096_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001096_0_1 >= (-100)) && (pub_r001096_0_1 <= 100));
  __CPROVER_assume((pub_r001096_0_2 >= (-100)) && (pub_r001096_0_2 <= 100));
  __CPROVER_assume((pub_r001096_1_1 >= (-100)) && (pub_r001096_1_1 <= 100));
  __CPROVER_assume((pub_r001096_1_2 >= (-100)) && (pub_r001096_1_2 <= 100));
  __CPROVER_assume((pub_r001096_2_1 >= (-100)) && (pub_r001096_2_1 <= 100));
  __CPROVER_assume((pub_r001096_2_2 >= (-100)) && (pub_r001096_2_2 <= 100));
  __CPROVER_assume((pub_r001096_3_1 >= (-100)) && (pub_r001096_3_1 <= 100));
  __CPROVER_assume((pub_r001096_3_2 >= (-100)) && (pub_r001096_3_2 <= 100));
  __CPROVER_assume((pub_r001096_4_1 >= (-100)) && (pub_r001096_4_1 <= 100));
  __CPROVER_assume((pub_r001096_4_2 >= (-100)) && (pub_r001096_4_2 <= 100));
  __CPROVER_assume((pub_r001096_5_1 >= (-100)) && (pub_r001096_5_1 <= 100));
  __CPROVER_assume((pub_r001096_5_2 >= (-100)) && (pub_r001096_5_2 <= 100));
  __CPROVER_assume((pub_r001096_6_1 >= (-100)) && (pub_r001096_6_1 <= 100));
  __CPROVER_assume((pub_r001096_6_2 >= (-100)) && (pub_r001096_6_2 <= 100));
  __CPROVER_assume((pub_r001096_7_1 >= (-100)) && (pub_r001096_7_1 <= 100));
  __CPROVER_assume((pub_r001096_7_2 >= (-100)) && (pub_r001096_7_2 <= 100));
  __CPROVER_assume((pub_r001096_8_1 >= (-100)) && (pub_r001096_8_1 <= 100));
  __CPROVER_assume((pub_r001096_8_2 >= (-100)) && (pub_r001096_8_2 <= 100));
  __CPROVER_assume((pub_r001096_9_1 >= (-100)) && (pub_r001096_9_1 <= 100));
  __CPROVER_assume((pub_r001096_9_2 >= (-100)) && (pub_r001096_9_2 <= 100));
  __CPROVER_assume((pub_r001096_10_1 >= (-100)) && (pub_r001096_10_1 <= 100));
  __CPROVER_assume((pub_r001096_10_2 >= (-100)) && (pub_r001096_10_2 <= 100));
  __CPROVER_assume((pub_r001096_11_1 >= (-100)) && (pub_r001096_11_1 <= 100));
  __CPROVER_assume((pub_r001096_11_2 >= (-100)) && (pub_r001096_11_2 <= 100));
  __CPROVER_assume((pub_r001096_12_1 >= (-100)) && (pub_r001096_12_1 <= 100));
  __CPROVER_assume((pub_r001096_12_2 >= (-100)) && (pub_r001096_12_2 <= 100));
  __CPROVER_assume((pub_r001096_13_1 >= (-100)) && (pub_r001096_13_1 <= 100));
  __CPROVER_assume((pub_r001096_13_2 >= (-100)) && (pub_r001096_13_2 <= 100));
  __CPROVER_assume((pub_r001096_14_1 >= (-100)) && (pub_r001096_14_1 <= 100));
  __CPROVER_assume((pub_r001096_14_2 >= (-100)) && (pub_r001096_14_2 <= 100));
  __CPROVER_assume((pub_r001096_15_1 >= (-100)) && (pub_r001096_15_1 <= 100));
  __CPROVER_assume((pub_r001096_15_2 >= (-100)) && (pub_r001096_15_2 <= 100));
  __CPROVER_assume((pub_r001096_16_1 >= (-100)) && (pub_r001096_16_1 <= 100));
  __CPROVER_assume((pub_r001096_16_2 >= (-100)) && (pub_r001096_16_2 <= 100));
  __CPROVER_assume((sec_r001096_0_1 >= 0) && (sec_r001096_0_1 <= 255));
  __CPROVER_assume((sec_r001096_0_2 >= 0) && (sec_r001096_0_2 <= 255));
  __CPROVER_assume((sec_r001096_1_1 >= 0) && (sec_r001096_1_1 <= 255));
  __CPROVER_assume((sec_r001096_1_2 >= 0) && (sec_r001096_1_2 <= 255));
  __CPROVER_assume((sec_r001096_2_1 >= 0) && (sec_r001096_2_1 <= 255));
  __CPROVER_assume((sec_r001096_2_2 >= 0) && (sec_r001096_2_2 <= 255));
  __CPROVER_assume((sec_r001096_3_1 >= 0) && (sec_r001096_3_1 <= 255));
  __CPROVER_assume((sec_r001096_3_2 >= 0) && (sec_r001096_3_2 <= 255));
  __CPROVER_assume((sec_r001096_4_1 >= 0) && (sec_r001096_4_1 <= 255));
  __CPROVER_assume((sec_r001096_4_2 >= 0) && (sec_r001096_4_2 <= 255));
  __CPROVER_assume((sec_r001096_5_1 >= 0) && (sec_r001096_5_1 <= 255));
  __CPROVER_assume((sec_r001096_5_2 >= 0) && (sec_r001096_5_2 <= 255));
  __CPROVER_assume((sec_r001096_6_1 >= 0) && (sec_r001096_6_1 <= 255));
  __CPROVER_assume((sec_r001096_6_2 >= 0) && (sec_r001096_6_2 <= 255));
  __CPROVER_assume((sec_r001096_7_1 >= 0) && (sec_r001096_7_1 <= 255));
  __CPROVER_assume((sec_r001096_7_2 >= 0) && (sec_r001096_7_2 <= 255));
  __CPROVER_assume((sec_r001096_8_1 >= 0) && (sec_r001096_8_1 <= 255));
  __CPROVER_assume((sec_r001096_8_2 >= 0) && (sec_r001096_8_2 <= 255));
  __CPROVER_assume((sec_r001096_9_1 >= 0) && (sec_r001096_9_1 <= 255));
  __CPROVER_assume((sec_r001096_9_2 >= 0) && (sec_r001096_9_2 <= 255));
  __CPROVER_assume((sec_r001096_10_1 >= 0) && (sec_r001096_10_1 <= 255));
  __CPROVER_assume((sec_r001096_10_2 >= 0) && (sec_r001096_10_2 <= 255));
  __CPROVER_assume((sec_r001096_11_1 >= 0) && (sec_r001096_11_1 <= 255));
  __CPROVER_assume((sec_r001096_11_2 >= 0) && (sec_r001096_11_2 <= 255));
  __CPROVER_assume((sec_r001096_12_1 >= 0) && (sec_r001096_12_1 <= 255));
  __CPROVER_assume((sec_r001096_12_2 >= 0) && (sec_r001096_12_2 <= 255));
  __CPROVER_assume((sec_r001096_13_1 >= 0) && (sec_r001096_13_1 <= 255));
  __CPROVER_assume((sec_r001096_13_2 >= 0) && (sec_r001096_13_2 <= 255));
  __CPROVER_assume((sec_r001096_14_1 >= 0) && (sec_r001096_14_1 <= 255));
  __CPROVER_assume((sec_r001096_14_2 >= 0) && (sec_r001096_14_2 <= 255));
  __CPROVER_assume((sec_r001096_15_1 >= 0) && (sec_r001096_15_1 <= 255));
  __CPROVER_assume((sec_r001096_15_2 >= 0) && (sec_r001096_15_2 <= 255));
  struct AudioFrame_R001096_9613_0 st_var_0_1 = {0};
  struct AudioFrame_R001096_9613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001096_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001096_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001096_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001096_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001096_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001096_0_2 + 7) & 15;
  struct Vector3D_R001096_9613_1 st_var_1_1 = {0};
  struct Vector3D_R001096_9613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001096_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001096_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001096_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001096_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001096_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001096_0_2 + 9) & 15;
  struct MatrixBlock_R001096_9613_2 st_var_2_1 = {0};
  struct MatrixBlock_R001096_9613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001096_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001096_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001096_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001096_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001096_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001096_0_2 + 11) & 15;
  struct DeviceConfig_R001096_9613_3 st_var_3_1 = {0};
  struct DeviceConfig_R001096_9613_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001096_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001096_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001096_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001096_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001096_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001096_0_2 + 13) & 15;
  union RegisterBank_R001096_9613_0 u_var_1;
  union RegisterBank_R001096_9613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001096_9613_0(sec_r001096_0_1, sec_r001096_1_1, pub_r001096_2_1, pub_r001096_3_1);
  int helper_flow_0_2 = fn_R001096_9613_0(sec_r001096_0_2, sec_r001096_1_2, pub_r001096_2_2, pub_r001096_3_2);
  fn_R001096_9613_0_2(sec_r001096_0_1, sec_r001096_1_1, pub_r001096_2_1, pub_r001096_3_1, sec_r001096_0_2, sec_r001096_1_2, pub_r001096_2_2, pub_r001096_3_2);
  int helper_flow_1_1 = fn_R001096_9613_1(sec_r001096_1_1, pub_r001096_2_1, pub_r001096_3_1, pub_r001096_4_1);
  int helper_flow_1_2 = fn_R001096_9613_1(sec_r001096_1_2, pub_r001096_2_2, pub_r001096_3_2, pub_r001096_4_2);
  fn_R001096_9613_1_2(sec_r001096_1_1, pub_r001096_2_1, pub_r001096_3_1, pub_r001096_4_1, sec_r001096_1_2, pub_r001096_2_2, pub_r001096_3_2, pub_r001096_4_2);
  int helper_flow_2_1 = fn_R001096_9613_2(sec_r001096_2_1, sec_r001096_3_1);
  int helper_flow_2_2 = fn_R001096_9613_2(sec_r001096_2_2, sec_r001096_3_2);
  fn_R001096_9613_2_2(sec_r001096_2_1, sec_r001096_3_1, sec_r001096_2_2, sec_r001096_3_2);
  int helper_flow_3_1 = fn_R001096_9613_3(sec_r001096_3_1, pub_r001096_4_1, pub_r001096_5_1, pub_r001096_6_1);
  int helper_flow_3_2 = fn_R001096_9613_3(sec_r001096_3_2, pub_r001096_4_2, pub_r001096_5_2, pub_r001096_6_2);
  fn_R001096_9613_3_2(sec_r001096_3_1, pub_r001096_4_1, pub_r001096_5_1, pub_r001096_6_1, sec_r001096_3_2, pub_r001096_4_2, pub_r001096_5_2, pub_r001096_6_2);
  int helper_flow_4_1 = fn_R001096_9613_4(sec_r001096_4_1, pub_r001096_5_1);
  int helper_flow_4_2 = fn_R001096_9613_4(sec_r001096_4_2, pub_r001096_5_2);
  fn_R001096_9613_4_2(sec_r001096_4_1, pub_r001096_5_1, sec_r001096_4_2, pub_r001096_5_2);
  int helper_flow_5_1 = fn_R001096_9613_5(sec_r001096_5_1, sec_r001096_6_1);
  int helper_flow_5_2 = fn_R001096_9613_5(sec_r001096_5_2, sec_r001096_6_2);
  fn_R001096_9613_5_2(sec_r001096_5_1, sec_r001096_6_1, sec_r001096_5_2, sec_r001096_6_2);
  int helper_flow_6_1 = fn_R001096_9613_6(sec_r001096_6_1, sec_r001096_7_1, pub_r001096_8_1, pub_r001096_9_1);
  int helper_flow_6_2 = fn_R001096_9613_6(sec_r001096_6_2, sec_r001096_7_2, pub_r001096_8_2, pub_r001096_9_2);
  fn_R001096_9613_6_2(sec_r001096_6_1, sec_r001096_7_1, pub_r001096_8_1, pub_r001096_9_1, sec_r001096_6_2, sec_r001096_7_2, pub_r001096_8_2, pub_r001096_9_2);
  int helper_flow_7_1 = fn_R001096_9613_7(sec_r001096_7_1, sec_r001096_8_1, pub_r001096_9_1);
  int helper_flow_7_2 = fn_R001096_9613_7(sec_r001096_7_2, sec_r001096_8_2, pub_r001096_9_2);
  fn_R001096_9613_7_2(sec_r001096_7_1, sec_r001096_8_1, pub_r001096_9_1, sec_r001096_7_2, sec_r001096_8_2, pub_r001096_9_2);
  int helper_flow_8_1 = fn_R001096_9613_8(sec_r001096_8_1, sec_r001096_9_1, pub_r001096_10_1, pub_r001096_11_1);
  int helper_flow_8_2 = fn_R001096_9613_8(sec_r001096_8_2, sec_r001096_9_2, pub_r001096_10_2, pub_r001096_11_2);
  fn_R001096_9613_8_2(sec_r001096_8_1, sec_r001096_9_1, pub_r001096_10_1, pub_r001096_11_1, sec_r001096_8_2, sec_r001096_9_2, pub_r001096_10_2, pub_r001096_11_2);
  int stage_v_0_1 = ((helper_flow_7_1 + (pub_r001096_16_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_7_2 + (pub_r001096_16_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((sec_r001096_8_1 + (pub_r001096_7_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001096_8_2 + (pub_r001096_7_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((sec_r001096_9_1 + (pub_r001096_5_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((sec_r001096_9_2 + (pub_r001096_5_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((sec_r001096_10_1 + (pub_r001096_16_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001096_10_2 + (pub_r001096_16_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((pub_r001096_2_1 * 2) + 34) & 63;
  int stage_v_4_2 = ((pub_r001096_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((helper_flow_4_1 + (pub_r001096_0_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((helper_flow_4_2 + (pub_r001096_0_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((sec_r001096_1_1 + (pub_r001096_2_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001096_1_2 + (pub_r001096_2_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((pub_r001096_3_1 * 2) + 30) & 63;
  int stage_v_7_2 = ((pub_r001096_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001096_7_1 * 2) + 44) & 63;
  int stage_v_8_2 = ((pub_r001096_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001096_15_1 * 2) + 32) & 63;
  int stage_v_9_2 = ((pub_r001096_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001096_13_1 * 2) + 13) & 63;
  int stage_v_10_2 = ((pub_r001096_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001096_9_1 * 2) + 33) & 63;
  int stage_v_11_2 = ((pub_r001096_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001096_0_1 * 2) + 24) & 63;
  int stage_v_12_2 = ((pub_r001096_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((sec_r001096_9_1 + (pub_r001096_2_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001096_9_2 + (pub_r001096_2_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((pub_r001096_7_1 * 2) + 26) & 63;
  int stage_v_14_2 = ((pub_r001096_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((sec_r001096_7_1 + (pub_r001096_3_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((sec_r001096_7_2 + (pub_r001096_3_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((stage_v_6_1 + (pub_r001096_14_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((stage_v_6_2 + (pub_r001096_14_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((stage_v_1_1 + (pub_r001096_16_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((stage_v_1_2 + (pub_r001096_16_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((pub_r001096_1_1 * 2) + 50) & 63;
  int stage_v_18_2 = ((pub_r001096_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((helper_flow_5_1 + (pub_r001096_16_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((helper_flow_5_2 + (pub_r001096_16_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((helper_flow_6_1 + (pub_r001096_4_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((helper_flow_6_2 + (pub_r001096_4_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((stage_v_20_1 + (pub_r001096_5_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_20_2 + (pub_r001096_5_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((pub_r001096_16_1 * 2) + 40) & 63;
  int stage_v_22_2 = ((pub_r001096_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((sec_r001096_14_1 + (pub_r001096_3_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((sec_r001096_14_2 + (pub_r001096_3_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((stage_v_19_1 + (pub_r001096_14_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((stage_v_19_2 + (pub_r001096_14_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((stage_v_3_1 + (pub_r001096_12_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((stage_v_3_2 + (pub_r001096_12_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((pub_r001096_9_1 * 2) + 45) & 63;
  int stage_v_26_2 = ((pub_r001096_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((stage_v_1_1 + (pub_r001096_2_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((stage_v_1_2 + (pub_r001096_2_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((stage_v_27_1 + (pub_r001096_4_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((stage_v_27_2 + (pub_r001096_4_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((pub_r001096_12_1 * 2) + 21) & 63;
  int stage_v_29_2 = ((pub_r001096_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((helper_flow_1_1 + (pub_r001096_14_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((helper_flow_1_2 + (pub_r001096_14_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((helper_flow_4_1 + (pub_r001096_5_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((helper_flow_4_2 + (pub_r001096_5_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((pub_r001096_14_1 * 2) + 22) & 63;
  int stage_v_32_2 = ((pub_r001096_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((stage_v_31_1 + (pub_r001096_1_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((stage_v_31_2 + (pub_r001096_1_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((pub_r001096_3_1 * 2) + 21) & 63;
  int stage_v_34_2 = ((pub_r001096_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((helper_flow_1_1 + (pub_r001096_7_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((helper_flow_1_2 + (pub_r001096_7_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((stage_v_5_1 + (pub_r001096_2_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((stage_v_5_2 + (pub_r001096_2_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((helper_flow_1_1 + (pub_r001096_15_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((helper_flow_1_2 + (pub_r001096_15_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((stage_v_5_1 + (pub_r001096_10_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((stage_v_5_2 + (pub_r001096_10_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((stage_v_37_1 + (pub_r001096_16_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((stage_v_37_2 + (pub_r001096_16_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((stage_v_38_1 + (pub_r001096_11_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_38_2 + (pub_r001096_11_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((stage_v_27_1 + (pub_r001096_5_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((stage_v_27_2 + (pub_r001096_5_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((pub_r001096_2_1 * 2) + 46) & 63;
  int stage_v_42_2 = ((pub_r001096_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001096_11_1 * 2) + 40) & 63;
  int stage_v_43_2 = ((pub_r001096_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001096_1_1 * 2) + 8) & 63;
  int stage_v_44_2 = ((pub_r001096_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001096_0_1 * 2) + 25) & 63;
  int stage_v_45_2 = ((pub_r001096_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((helper_flow_0_1 + (pub_r001096_7_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((helper_flow_0_2 + (pub_r001096_7_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((sec_r001096_4_1 + (pub_r001096_6_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((sec_r001096_4_2 + (pub_r001096_6_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((stage_v_16_1 + (pub_r001096_1_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((stage_v_16_2 + (pub_r001096_1_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((sec_r001096_2_1 + (pub_r001096_1_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((sec_r001096_2_2 + (pub_r001096_1_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((pub_r001096_14_1 * 2) + 41) & 63;
  int stage_v_50_2 = ((pub_r001096_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001096_13_1 * 2) + 21) & 63;
  int stage_v_51_2 = ((pub_r001096_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001096_4_1 * 2) + 23) & 63;
  int stage_v_52_2 = ((pub_r001096_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((helper_flow_3_1 + (pub_r001096_2_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((helper_flow_3_2 + (pub_r001096_2_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((sec_r001096_12_1 + (pub_r001096_16_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((sec_r001096_12_2 + (pub_r001096_16_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((pub_r001096_12_1 * 2) + 34) & 63;
  int stage_v_55_2 = ((pub_r001096_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((stage_v_40_1 + (pub_r001096_2_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((stage_v_40_2 + (pub_r001096_2_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((stage_v_2_1 + (pub_r001096_13_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_2_2 + (pub_r001096_13_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((stage_v_30_1 + (pub_r001096_2_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_30_2 + (pub_r001096_2_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((helper_flow_0_1 + (pub_r001096_10_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((helper_flow_0_2 + (pub_r001096_10_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((stage_v_17_1 + (pub_r001096_3_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_17_2 + (pub_r001096_3_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((pub_r001096_3_1 * 2) + 6) & 63;
  int stage_v_61_2 = ((pub_r001096_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001096_4_1 * 2) + 38) & 63;
  int stage_v_62_2 = ((pub_r001096_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((sec_r001096_1_1 + (pub_r001096_7_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((sec_r001096_1_2 + (pub_r001096_7_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((pub_r001096_15_1 * 2) + 7) & 63;
  int stage_v_64_2 = ((pub_r001096_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((stage_v_33_1 + (pub_r001096_0_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_33_2 + (pub_r001096_0_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((stage_v_31_1 + (pub_r001096_10_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((stage_v_31_2 + (pub_r001096_10_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((stage_v_48_1 + (pub_r001096_1_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_48_2 + (pub_r001096_1_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((stage_v_56_1 + (pub_r001096_5_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_56_2 + (pub_r001096_5_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((helper_flow_4_1 + (pub_r001096_10_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((helper_flow_4_2 + (pub_r001096_10_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((stage_v_16_1 + (pub_r001096_10_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_16_2 + (pub_r001096_10_2 * 2)) + 215) & 127;
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
  int stage_v_71_1 = ((stage_v_6_1 + (pub_r001096_9_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_6_2 + (pub_r001096_9_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((pub_r001096_3_1 * 2) + 41) & 63;
  int stage_v_72_2 = ((pub_r001096_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((stage_v_68_1 + (pub_r001096_7_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_68_2 + (pub_r001096_7_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((stage_v_35_1 + (pub_r001096_3_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_35_2 + (pub_r001096_3_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((pub_r001096_4_1 * 2) + 49) & 63;
  int stage_v_75_2 = ((pub_r001096_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((stage_v_56_1 + (pub_r001096_2_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((stage_v_56_2 + (pub_r001096_2_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((pub_r001096_12_1 * 2) + 14) & 63;
  int stage_v_77_2 = ((pub_r001096_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((stage_v_40_1 + (pub_r001096_15_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_40_2 + (pub_r001096_15_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((helper_flow_1_1 + (pub_r001096_7_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((helper_flow_1_2 + (pub_r001096_7_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((helper_flow_6_1 + (pub_r001096_5_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((helper_flow_6_2 + (pub_r001096_5_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((pub_r001096_14_1 * 2) + 18) & 63;
  int stage_v_81_2 = ((pub_r001096_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((stage_v_54_1 + (pub_r001096_1_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((stage_v_54_2 + (pub_r001096_1_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((pub_r001096_15_1 * 2) + 36) & 63;
  int stage_v_83_2 = ((pub_r001096_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001096_8_1 * 2) + 40) & 63;
  int stage_v_84_2 = ((pub_r001096_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((sec_r001096_0_1 + (pub_r001096_0_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((sec_r001096_0_2 + (pub_r001096_0_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_20_1 + (pub_r001096_4_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_20_2 + (pub_r001096_4_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_67_1 + (pub_r001096_7_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_67_2 + (pub_r001096_7_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((sec_r001096_7_1 + (pub_r001096_2_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((sec_r001096_7_2 + (pub_r001096_2_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((stage_v_65_1 + (pub_r001096_2_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_65_2 + (pub_r001096_2_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((pub_r001096_9_1 * 2) + 12) & 63;
  int stage_v_90_2 = ((pub_r001096_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((stage_v_41_1 + (pub_r001096_2_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_41_2 + (pub_r001096_2_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((helper_flow_7_1 + (pub_r001096_4_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((helper_flow_7_2 + (pub_r001096_4_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((sec_r001096_15_1 + (pub_r001096_16_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((sec_r001096_15_2 + (pub_r001096_16_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((stage_v_53_1 + (pub_r001096_16_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_53_2 + (pub_r001096_16_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((helper_flow_6_1 + (pub_r001096_16_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((helper_flow_6_2 + (pub_r001096_16_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((pub_r001096_16_1 * 2) + 46) & 63;
  int stage_v_96_2 = ((pub_r001096_16_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((stage_v_88_1 + (pub_r001096_15_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_88_2 + (pub_r001096_15_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((helper_flow_7_1 + (pub_r001096_0_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((helper_flow_7_2 + (pub_r001096_0_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((pub_r001096_10_1 * 2) + 33) & 63;
  int stage_v_99_2 = ((pub_r001096_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001096_13_1 * 2) + 46) & 63;
  int stage_v_100_2 = ((pub_r001096_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001096_5_1 * 2) + 13) & 63;
  int stage_v_101_2 = ((pub_r001096_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001096_12_1 * 2) + 35) & 63;
  int stage_v_102_2 = ((pub_r001096_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001096_13_1 * 2) + 43) & 63;
  int stage_v_103_2 = ((pub_r001096_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((sec_r001096_3_1 + (pub_r001096_12_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((sec_r001096_3_2 + (pub_r001096_12_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((stage_v_91_1 + (pub_r001096_13_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_91_2 + (pub_r001096_13_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((stage_v_41_1 + (pub_r001096_9_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_41_2 + (pub_r001096_9_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((stage_v_3_1 + (pub_r001096_11_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_3_2 + (pub_r001096_11_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((sec_r001096_3_1 + (pub_r001096_9_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((sec_r001096_3_2 + (pub_r001096_9_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_35_1 + (pub_r001096_3_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_35_2 + (pub_r001096_3_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((pub_r001096_2_1 * 2) + 24) & 63;
  int stage_v_110_2 = ((pub_r001096_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((stage_v_76_1 + (pub_r001096_8_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_76_2 + (pub_r001096_8_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((stage_v_28_1 + (pub_r001096_3_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((stage_v_28_2 + (pub_r001096_3_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((sec_r001096_3_1 + (pub_r001096_6_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((sec_r001096_3_2 + (pub_r001096_6_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((sec_r001096_13_1 + (pub_r001096_14_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((sec_r001096_13_2 + (pub_r001096_14_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((stage_v_78_1 + (pub_r001096_16_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_78_2 + (pub_r001096_16_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((pub_r001096_0_1 * 2) + 29) & 63;
  int stage_v_116_2 = ((pub_r001096_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((helper_flow_3_1 + (pub_r001096_15_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((helper_flow_3_2 + (pub_r001096_15_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((pub_r001096_7_1 * 2) + 39) & 63;
  int stage_v_118_2 = ((pub_r001096_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001096_15_1 * 2) + 10) & 63;
  int stage_v_119_2 = ((pub_r001096_15_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((sec_r001096_9_1 + (pub_r001096_12_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((sec_r001096_9_2 + (pub_r001096_12_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((stage_v_48_1 + (pub_r001096_16_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_48_2 + (pub_r001096_16_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((stage_v_87_1 + (pub_r001096_6_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_87_2 + (pub_r001096_6_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_28_1 + (pub_r001096_15_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_28_2 + (pub_r001096_15_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((sec_r001096_8_1 + (pub_r001096_13_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((sec_r001096_8_2 + (pub_r001096_13_2 * 2)) + 377) & 127;
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
  int stage_v_125_1 = ((sec_r001096_5_1 + (pub_r001096_3_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((sec_r001096_5_2 + (pub_r001096_3_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((sec_r001096_5_1 + (pub_r001096_8_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((sec_r001096_5_2 + (pub_r001096_8_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((pub_r001096_16_1 * 2) + 50) & 63;
  int stage_v_127_2 = ((pub_r001096_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001096_0_1 * 2) + 17) & 63;
  int stage_v_128_2 = ((pub_r001096_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((stage_v_15_1 + (pub_r001096_15_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_15_2 + (pub_r001096_15_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((stage_v_66_1 + (pub_r001096_1_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_66_2 + (pub_r001096_1_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((stage_v_40_1 + (pub_r001096_16_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_40_2 + (pub_r001096_16_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((stage_v_35_1 + (pub_r001096_3_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_35_2 + (pub_r001096_3_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((stage_v_121_1 + (pub_r001096_4_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_121_2 + (pub_r001096_4_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((stage_v_132_1 + (pub_r001096_8_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_132_2 + (pub_r001096_8_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((sec_r001096_0_1 + (pub_r001096_11_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((sec_r001096_0_2 + (pub_r001096_11_2 * 2)) + 410) & 127;
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
  int stage_v_136_1 = ((stage_v_88_1 + (pub_r001096_1_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_88_2 + (pub_r001096_1_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((pub_r001096_16_1 * 2) + 6) & 63;
  int stage_v_137_2 = ((pub_r001096_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((stage_v_67_1 + (pub_r001096_10_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_67_2 + (pub_r001096_10_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((stage_v_133_1 + (pub_r001096_3_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((stage_v_133_2 + (pub_r001096_3_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((stage_v_121_1 + (pub_r001096_4_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_121_2 + (pub_r001096_4_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((pub_r001096_0_1 * 2) + 27) & 63;
  int stage_v_141_2 = ((pub_r001096_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((stage_v_57_1 + (pub_r001096_1_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_57_2 + (pub_r001096_1_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((stage_v_91_1 + (pub_r001096_14_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_91_2 + (pub_r001096_14_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((sec_r001096_2_1 + (pub_r001096_5_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((sec_r001096_2_2 + (pub_r001096_5_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((stage_v_28_1 + (pub_r001096_11_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_28_2 + (pub_r001096_11_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((stage_v_111_1 + (pub_r001096_15_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_111_2 + (pub_r001096_15_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((stage_v_131_1 + (pub_r001096_6_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_131_2 + (pub_r001096_6_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((stage_v_125_1 + (pub_r001096_13_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_125_2 + (pub_r001096_13_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((pub_r001096_12_1 * 2) + 46) & 63;
  int stage_v_149_2 = ((pub_r001096_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((stage_v_37_1 + (pub_r001096_16_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_37_2 + (pub_r001096_16_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((stage_v_131_1 + (pub_r001096_11_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_131_2 + (pub_r001096_11_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((pub_r001096_12_1 * 2) + 26) & 63;
  int stage_v_152_2 = ((pub_r001096_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((stage_v_131_1 + (pub_r001096_5_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_131_2 + (pub_r001096_5_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((pub_r001096_12_1 * 2) + 35) & 63;
  int stage_v_154_2 = ((pub_r001096_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001096_4_1 * 2) + 15) & 63;
  int stage_v_155_2 = ((pub_r001096_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((sec_r001096_9_1 + (pub_r001096_5_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((sec_r001096_9_2 + (pub_r001096_5_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((pub_r001096_9_1 * 2) + 18) & 63;
  int stage_v_157_2 = ((pub_r001096_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((stage_v_54_1 + (pub_r001096_16_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_54_2 + (pub_r001096_16_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((helper_flow_2_1 + (pub_r001096_14_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((helper_flow_2_2 + (pub_r001096_14_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_106_1 + (pub_r001096_14_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_106_2 + (pub_r001096_14_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((pub_r001096_8_1 * 2) + 39) & 63;
  int stage_v_161_2 = ((pub_r001096_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((stage_v_132_1 + (pub_r001096_5_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_132_2 + (pub_r001096_5_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((sec_r001096_4_1 + (pub_r001096_2_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((sec_r001096_4_2 + (pub_r001096_2_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((pub_r001096_10_1 * 2) + 27) & 63;
  int stage_v_164_2 = ((pub_r001096_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((stage_v_133_1 + (pub_r001096_16_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_133_2 + (pub_r001096_16_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_163_1 + (pub_r001096_10_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_163_2 + (pub_r001096_10_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((stage_v_21_1 + (pub_r001096_9_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_21_2 + (pub_r001096_9_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_112_1 + (pub_r001096_7_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_112_2 + (pub_r001096_7_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_98_1 + (pub_r001096_8_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_98_2 + (pub_r001096_8_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((pub_r001096_12_1 * 2) + 49) & 63;
  int stage_v_170_2 = ((pub_r001096_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001096_8_1 * 2) + 10) & 63;
  int stage_v_171_2 = ((pub_r001096_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001096_16_1 * 2) + 43) & 63;
  int stage_v_172_2 = ((pub_r001096_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((stage_v_74_1 + (pub_r001096_15_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_74_2 + (pub_r001096_15_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((sec_r001096_5_1 + (pub_r001096_12_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((sec_r001096_5_2 + (pub_r001096_12_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((pub_r001096_9_1 * 2) + 45) & 63;
  int stage_v_175_2 = ((pub_r001096_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((stage_v_82_1 + (pub_r001096_1_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_82_2 + (pub_r001096_1_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((pub_r001096_7_1 * 2) + 31) & 63;
  int stage_v_177_2 = ((pub_r001096_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((stage_v_168_1 + (pub_r001096_3_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_168_2 + (pub_r001096_3_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((sec_r001096_3_1 + (pub_r001096_9_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((sec_r001096_3_2 + (pub_r001096_9_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((stage_v_13_1 + (pub_r001096_1_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_13_2 + (pub_r001096_1_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((sec_r001096_14_1 + (pub_r001096_10_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((sec_r001096_14_2 + (pub_r001096_10_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((pub_r001096_3_1 * 2) + 50) & 63;
  int stage_v_182_2 = ((pub_r001096_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((sec_r001096_13_1 + (pub_r001096_16_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((sec_r001096_13_2 + (pub_r001096_16_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((sec_r001096_7_1 + (pub_r001096_8_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((sec_r001096_7_2 + (pub_r001096_8_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_138_1 + (pub_r001096_2_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_138_2 + (pub_r001096_2_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((pub_r001096_13_1 * 2) + 38) & 63;
  int stage_v_186_2 = ((pub_r001096_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((stage_v_23_1 + (pub_r001096_2_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_23_2 + (pub_r001096_2_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001096_3_1 * 2) + 15) & 63;
  int stage_v_188_2 = ((pub_r001096_3_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((helper_flow_1_1 + (pub_r001096_10_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((helper_flow_1_2 + (pub_r001096_10_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((pub_r001096_12_1 * 2) + 32) & 63;
  int stage_v_190_2 = ((pub_r001096_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((stage_v_129_1 + (pub_r001096_9_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((stage_v_129_2 + (pub_r001096_9_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((sec_r001096_11_1 + (pub_r001096_0_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((sec_r001096_11_2 + (pub_r001096_0_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((stage_v_98_1 + (pub_r001096_13_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_98_2 + (pub_r001096_13_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((stage_v_129_1 + (pub_r001096_12_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_129_2 + (pub_r001096_12_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((stage_v_86_1 + (pub_r001096_11_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_86_2 + (pub_r001096_11_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((pub_r001096_5_1 * 2) + 10) & 63;
  int stage_v_196_2 = ((pub_r001096_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001096_12_1 * 2) + 14) & 63;
  int stage_v_197_2 = ((pub_r001096_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((sec_r001096_12_1 + (pub_r001096_13_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((sec_r001096_12_2 + (pub_r001096_13_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_142_1 + (pub_r001096_8_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_142_2 + (pub_r001096_8_2 * 2)) + 602) & 127;
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
  int stage_v_200_1 = ((stage_v_20_1 + (pub_r001096_13_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_20_2 + (pub_r001096_13_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((stage_v_69_1 + (pub_r001096_2_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_69_2 + (pub_r001096_2_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_176_1 + (pub_r001096_5_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_176_2 + (pub_r001096_5_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((pub_r001096_14_1 * 2) + 38) & 63;
  int stage_v_203_2 = ((pub_r001096_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((stage_v_93_1 + (pub_r001096_6_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_93_2 + (pub_r001096_6_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((stage_v_111_1 + (pub_r001096_3_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_111_2 + (pub_r001096_3_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((stage_v_71_1 + (pub_r001096_9_1 * 2)) + 623) & 127;
  int stage_v_206_2 = ((stage_v_71_2 + (pub_r001096_9_2 * 2)) + 623) & 127;
  if (stage_v_206_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_206_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_206_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_206_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_207_1 = ((stage_v_176_1 + (pub_r001096_8_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((stage_v_176_2 + (pub_r001096_8_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((pub_r001096_7_1 * 2) + 40) & 63;
  int stage_v_208_2 = ((pub_r001096_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((sec_r001096_11_1 + (pub_r001096_5_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((sec_r001096_11_2 + (pub_r001096_5_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((stage_v_202_1 + (pub_r001096_15_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((stage_v_202_2 + (pub_r001096_15_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((helper_flow_1_1 + (pub_r001096_9_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((helper_flow_1_2 + (pub_r001096_9_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((pub_r001096_1_1 * 2) + 18) & 63;
  int stage_v_212_2 = ((pub_r001096_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((stage_v_91_1 + (pub_r001096_2_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((stage_v_91_2 + (pub_r001096_2_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((stage_v_109_1 + (pub_r001096_15_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_109_2 + (pub_r001096_15_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((pub_r001096_6_1 * 2) + 15) & 63;
  int stage_v_215_2 = ((pub_r001096_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((stage_v_60_1 + (pub_r001096_7_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((stage_v_60_2 + (pub_r001096_7_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((stage_v_115_1 + (pub_r001096_6_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_115_2 + (pub_r001096_6_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((stage_v_68_1 + (pub_r001096_5_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_68_2 + (pub_r001096_5_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((stage_v_176_1 + (pub_r001096_14_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_176_2 + (pub_r001096_14_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((pub_r001096_11_1 * 2) + 45) & 63;
  int stage_v_220_2 = ((pub_r001096_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001096_0_1 * 2) + 21) & 63;
  int stage_v_221_2 = ((pub_r001096_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((stage_v_49_1 + (pub_r001096_13_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_49_2 + (pub_r001096_13_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((stage_v_16_1 + (pub_r001096_16_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_16_2 + (pub_r001096_16_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((stage_v_146_1 + (pub_r001096_12_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((stage_v_146_2 + (pub_r001096_12_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((pub_r001096_2_1 * 2) + 21) & 63;
  int stage_v_225_2 = ((pub_r001096_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((stage_v_15_1 + (pub_r001096_0_1 * 2)) + 683) & 127;
  int stage_v_226_2 = ((stage_v_15_2 + (pub_r001096_0_2 * 2)) + 683) & 127;
  if (stage_v_226_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_226_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_226_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_226_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_227_1 = ((stage_v_217_1 + (pub_r001096_7_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((stage_v_217_2 + (pub_r001096_7_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_228_1 = ((stage_v_65_1 + (pub_r001096_12_1 * 2)) + 689) & 127;
  int stage_v_228_2 = ((stage_v_65_2 + (pub_r001096_12_2 * 2)) + 689) & 127;
  if (stage_v_228_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_228_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_228_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_228_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_229_1 = ((pub_r001096_16_1 * 2) + 10) & 63;
  int stage_v_229_2 = ((pub_r001096_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((stage_v_144_1 + (pub_r001096_5_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((stage_v_144_2 + (pub_r001096_5_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_231_1 = ((pub_r001096_8_1 * 2) + 6) & 63;
  int stage_v_231_2 = ((pub_r001096_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((stage_v_41_1 + (pub_r001096_0_1 * 2)) + 701) & 127;
  int stage_v_232_2 = ((stage_v_41_2 + (pub_r001096_0_2 * 2)) + 701) & 127;
  if (stage_v_232_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_232_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_232_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_232_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_233_1 = ((stage_v_33_1 + (pub_r001096_14_1 * 2)) + 704) & 127;
  int stage_v_233_2 = ((stage_v_33_2 + (pub_r001096_14_2 * 2)) + 704) & 127;
  if (stage_v_233_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_233_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_233_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_233_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_234_1 = ((pub_r001096_8_1 * 2) + 49) & 63;
  int stage_v_234_2 = ((pub_r001096_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((stage_v_104_1 + (pub_r001096_9_1 * 2)) + 710) & 127;
  int stage_v_235_2 = ((stage_v_104_2 + (pub_r001096_9_2 * 2)) + 710) & 127;
  if (stage_v_235_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_235_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_235_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_235_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_236_1 = ((pub_r001096_6_1 * 2) + 35) & 63;
  int stage_v_236_2 = ((pub_r001096_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((stage_v_174_1 + (pub_r001096_10_1 * 2)) + 716) & 127;
  int stage_v_237_2 = ((stage_v_174_2 + (pub_r001096_10_2 * 2)) + 716) & 127;
  if (stage_v_237_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_237_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_237_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_237_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_238_1 = ((stage_v_93_1 + (pub_r001096_10_1 * 2)) + 719) & 127;
  int stage_v_238_2 = ((stage_v_93_2 + (pub_r001096_10_2 * 2)) + 719) & 127;
  if (stage_v_238_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_238_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_238_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_238_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_238_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_238_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_238_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_238_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_239_1 = ((stage_v_181_1 + (pub_r001096_14_1 * 2)) + 722) & 127;
  int stage_v_239_2 = ((stage_v_181_2 + (pub_r001096_14_2 * 2)) + 722) & 127;
  if (stage_v_239_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_239_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_239_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_239_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_240_1 = ((stage_v_198_1 + (pub_r001096_4_1 * 2)) + 725) & 127;
  int stage_v_240_2 = ((stage_v_198_2 + (pub_r001096_4_2 * 2)) + 725) & 127;
  if (stage_v_240_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_240_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_240_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_240_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_241_1 = ((stage_v_167_1 + (pub_r001096_7_1 * 2)) + 728) & 127;
  int stage_v_241_2 = ((stage_v_167_2 + (pub_r001096_7_2 * 2)) + 728) & 127;
  if (stage_v_241_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_241_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_241_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_241_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_242_1 = ((helper_flow_7_1 + (pub_r001096_0_1 * 2)) + 731) & 127;
  int stage_v_242_2 = ((helper_flow_7_2 + (pub_r001096_0_2 * 2)) + 731) & 127;
  if (stage_v_242_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_242_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_242_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_242_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_243_1 = ((stage_v_28_1 + (pub_r001096_3_1 * 2)) + 734) & 127;
  int stage_v_243_2 = ((stage_v_28_2 + (pub_r001096_3_2 * 2)) + 734) & 127;
  if (stage_v_243_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_243_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_243_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_243_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_243_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_243_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_243_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_243_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_244_1 = ((stage_v_189_1 + (pub_r001096_12_1 * 2)) + 737) & 127;
  int stage_v_244_2 = ((stage_v_189_2 + (pub_r001096_12_2 * 2)) + 737) & 127;
  if (stage_v_244_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_244_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_244_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_244_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_244_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_244_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_244_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_244_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_245_1 = ((pub_r001096_14_1 * 2) + 19) & 63;
  int stage_v_245_2 = ((pub_r001096_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001096_1_1 * 2) + 25) & 63;
  int stage_v_246_2 = ((pub_r001096_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((stage_v_210_1 + (pub_r001096_11_1 * 2)) + 746) & 127;
  int stage_v_247_2 = ((stage_v_210_2 + (pub_r001096_11_2 * 2)) + 746) & 127;
  if (stage_v_247_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_247_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_247_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_247_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_247_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_247_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_247_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_247_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_248_1 = ((pub_r001096_15_1 * 2) + 41) & 63;
  int stage_v_248_2 = ((pub_r001096_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((stage_v_247_1 + (pub_r001096_15_1 * 2)) + 752) & 127;
  int stage_v_249_2 = ((stage_v_247_2 + (pub_r001096_15_2 * 2)) + 752) & 127;
  if (stage_v_249_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_249_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_249_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_249_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_249_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_249_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_249_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_249_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_250_1 = ((pub_r001096_13_1 * 2) + 30) & 63;
  int stage_v_250_2 = ((pub_r001096_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((stage_v_76_1 + (pub_r001096_5_1 * 2)) + 758) & 127;
  int stage_v_251_2 = ((stage_v_76_2 + (pub_r001096_5_2 * 2)) + 758) & 127;
  if (stage_v_251_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_251_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_251_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_251_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_251_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_251_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_251_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_251_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_252_1 = ((pub_r001096_13_1 * 2) + 28) & 63;
  int stage_v_252_2 = ((pub_r001096_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((stage_v_129_1 + (pub_r001096_1_1 * 2)) + 764) & 127;
  int stage_v_253_2 = ((stage_v_129_2 + (pub_r001096_1_2 * 2)) + 764) & 127;
  if (stage_v_253_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_253_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_253_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_253_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_253_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_253_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_253_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_253_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001096_0_1 == pub_r001096_0_2);
  __CPROVER_assume(pub_r001096_16_1 == pub_r001096_16_2);
  __CPROVER_assume(pub_r001096_6_1 == pub_r001096_6_2);
  __CPROVER_assume(sec_r001096_0_1 != sec_r001096_0_2);
  __CPROVER_assume(pub_r001096_8_1 == pub_r001096_8_2);
  __CPROVER_assume(pub_r001096_14_1 == pub_r001096_14_2);
  __CPROVER_assume(sec_r001096_8_1 != sec_r001096_8_2);
  __CPROVER_assume(sec_r001096_3_1 != sec_r001096_3_2);
  __CPROVER_assume(pub_r001096_15_1 == pub_r001096_15_2);
  __CPROVER_assume(sec_r001096_15_1 != sec_r001096_15_2);
  __CPROVER_assume(pub_r001096_3_1 == pub_r001096_3_2);
  __CPROVER_assume(sec_r001096_7_1 != sec_r001096_7_2);
  __CPROVER_assume(sec_r001096_6_1 != sec_r001096_6_2);
  __CPROVER_assume(pub_r001096_9_1 == pub_r001096_9_2);
  __CPROVER_assume(sec_r001096_11_1 != sec_r001096_11_2);
  __CPROVER_assume(pub_r001096_13_1 == pub_r001096_13_2);
  __CPROVER_assume(pub_r001096_5_1 == pub_r001096_5_2);
  __CPROVER_assume(sec_r001096_5_1 != sec_r001096_5_2);
  __CPROVER_assume(pub_r001096_7_1 == pub_r001096_7_2);
  __CPROVER_assume(pub_r001096_12_1 == pub_r001096_12_2);
  __CPROVER_assume(sec_r001096_13_1 != sec_r001096_13_2);
  __CPROVER_assume(pub_r001096_1_1 == pub_r001096_1_2);
  __CPROVER_assume(sec_r001096_12_1 != sec_r001096_12_2);
  __CPROVER_assume(pub_r001096_2_1 == pub_r001096_2_2);
  __CPROVER_assume(sec_r001096_10_1 != sec_r001096_10_2);
  __CPROVER_assume(sec_r001096_14_1 != sec_r001096_14_2);
  __CPROVER_assume(pub_r001096_11_1 == pub_r001096_11_2);
  __CPROVER_assume(sec_r001096_9_1 != sec_r001096_9_2);
  __CPROVER_assume(sec_r001096_2_1 != sec_r001096_2_2);
  __CPROVER_assume(pub_r001096_4_1 == pub_r001096_4_2);
  __CPROVER_assume(sec_r001096_1_1 != sec_r001096_1_2);
  __CPROVER_assume(sec_r001096_4_1 != sec_r001096_4_2);
  __CPROVER_assume(pub_r001096_10_1 == pub_r001096_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.trace == st_var_2_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.id == st_var_3_2.id);
  assert(st_var_3_1.stop_bits == st_var_3_2.stop_bits);
  assert(st_var_3_1.baud_rate == st_var_3_2.baud_rate);
  assert(st_var_3_1.parity == st_var_3_2.parity);
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
}


