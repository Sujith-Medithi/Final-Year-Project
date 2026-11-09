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
struct Vector3D_R001080_8013_0
{
  short coord_y;
  int coord_z;
  unsigned char pitch;
  int buffer[3];
};
struct SensorNode_R001080_8013_1
{
  short calib;
  int status;
  int threshold;
  int offset;
  short reading;
  int gain;
  int buffer[3];
};
struct MatrixBlock_R001080_8013_2
{
  unsigned char determinant;
  int stride;
  int scale;
  int dim;
  unsigned char trace;
  int buffer[3];
};
union PacketPayload_R001080_8013_0
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
void fn_R001080_8013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001080_8013_1 st_1 = {0};
  struct SensorNode_R001080_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int anchor_91_1 = 0;
  int anchor_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_91_1 = ((anchor_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_91_2 = ((anchor_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_91_1) & 127;
    acc_2 = (acc_2 + anchor_91_2) & 127;
  }

  int parity_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_93_1) & 63;
  aux_2 = (aux_2 + parity_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_32_1 > 48)
  {
    acc_1 = ((acc_1 + (parity_32_1 * 2)) + 5) & 127;
    aux_1 ^= parity_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_32_2 > 48)
  {
    acc_2 = ((acc_2 + (parity_32_2 * 2)) + 5) & 127;
    aux_2 ^= parity_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_32_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_91_1 == anchor_91_2);
  assert(parity_93_1 == parity_93_2);
  assert(parity_32_1 == parity_32_2);
}

int fn_R001080_8013_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001080_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int anchor_91 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_91 = ((anchor_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_91) & 127;
  }

  int parity_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_93) & 63;
  acc ^= aux;
  int parity_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_32 > 48)
  {
    acc = ((acc + (parity_32 * 2)) + 5) & 127;
    aux ^= parity_32 & 15;
  }
  else
  {
    acc = ((acc - parity_32) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001080_8013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001080_8013_2 st_1 = {0};
  struct MatrixBlock_R001080_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_56_1 > 19)
  {
    acc_1 = ((acc_1 + (damping_56_1 * 2)) + 5) & 127;
    aux_1 ^= damping_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_56_2 > 19)
  {
    acc_2 = ((acc_2 + (damping_56_2 * 2)) + 5) & 127;
    aux_2 ^= damping_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_15_1 = local_arr_1[aux_1 % 3];
  int factor_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_15_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_56_1 == damping_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_15_1 == factor_15_2);
}

int fn_R001080_8013_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001080_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_56 > 19)
  {
    acc = ((acc + (damping_56 * 2)) + 5) & 127;
    aux ^= damping_56 & 15;
  }
  else
  {
    acc = ((acc - damping_56) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_15 = local_arr[aux % 3];
  acc = (acc + (factor_15 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001080_8013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001080_8013_1 st_1 = {0};
  struct SensorNode_R001080_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int cursor_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_51_1)
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

  switch (cursor_51_2)
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

  int quotient_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_35_1 > 10)
  {
    acc_1 = ((acc_1 + (quotient_35_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_35_2 > 10)
  {
    acc_2 = ((acc_2 + (quotient_35_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_35_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_51_1 == cursor_51_2);
  assert(quotient_35_1 == quotient_35_2);
}

int fn_R001080_8013_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001080_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int cursor_51 = (aux + st.buffer[1]) & 3;
  switch (cursor_51)
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

  int quotient_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_35 > 10)
  {
    acc = ((acc + (quotient_35 * 2)) + 5) & 127;
    aux ^= quotient_35 & 15;
  }
  else
  {
    acc = ((acc - quotient_35) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001080_8013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001080_8013_1 st_1 = {0};
  struct SensorNode_R001080_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int factor_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_99_1)
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

  switch (factor_99_2)
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

  int segment_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_92_1 > 27)
  {
    acc_1 = ((acc_1 + (segment_92_1 * 2)) + 5) & 127;
    aux_1 ^= segment_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_92_2 > 27)
  {
    acc_2 = ((acc_2 + (segment_92_2 * 2)) + 5) & 127;
    aux_2 ^= segment_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_55_1 = local_arr_1[aux_1 % 3];
  int pivot_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_55_2 * 2)) & 127;
  int factor_44_1 = 0;
  int factor_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_44_1 = ((factor_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_44_2 = ((factor_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_44_1) & 127;
    acc_2 = (acc_2 + factor_44_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_99_1 == factor_99_2);
  assert(segment_92_1 == segment_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_55_1 == pivot_55_2);
  assert(factor_44_1 == factor_44_2);
}

int fn_R001080_8013_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001080_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int factor_99 = (aux + st.buffer[1]) & 3;
  switch (factor_99)
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

  int segment_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_92 > 27)
  {
    acc = ((acc + (segment_92 * 2)) + 5) & 127;
    aux ^= segment_92 & 15;
  }
  else
  {
    acc = ((acc - segment_92) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int pivot_55 = local_arr[aux % 3];
  acc = (acc + (pivot_55 * 2)) & 127;
  int factor_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_44 = ((factor_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_44) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001080_8013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001080_8013_1 st_1 = {0};
  struct SensorNode_R001080_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_68_1) & 63;
  aux_2 = (aux_2 + sample_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_68_1 == sample_68_2);
}

int fn_R001080_8013_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001080_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001080_8013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001080_8013_0 st_1 = {0};
  struct Vector3D_R001080_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int quantum_79_1 = 0;
  int quantum_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_79_1 = ((quantum_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_79_2 = ((quantum_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_79_1) & 127;
    acc_2 = (acc_2 + quantum_79_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_37_1 = local_arr_1[aux_1 % 3];
  int factor_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_37_2 * 2)) & 127;
  int factor_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_10_1 > 30)
  {
    acc_1 = ((acc_1 + (factor_10_1 * 2)) + 5) & 127;
    aux_1 ^= factor_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_10_2 > 30)
  {
    acc_2 = ((acc_2 + (factor_10_2 * 2)) + 5) & 127;
    aux_2 ^= factor_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_10_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_79_1 == quantum_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_37_1 == factor_37_2);
  assert(factor_10_1 == factor_10_2);
}

int fn_R001080_8013_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001080_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int quantum_79 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_79 = ((quantum_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_79) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int factor_37 = local_arr[aux % 3];
  acc = (acc + (factor_37 * 2)) & 127;
  int factor_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_10 > 30)
  {
    acc = ((acc + (factor_10 * 2)) + 5) & 127;
    aux ^= factor_10 & 15;
  }
  else
  {
    acc = ((acc - factor_10) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001080_8013_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001080_8013_1 st_1 = {0};
  struct SensorNode_R001080_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int stride_43_1 = 0;
  int stride_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_43_1 = ((stride_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_43_2 = ((stride_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_43_1) & 127;
    acc_2 = (acc_2 + stride_43_2) & 127;
  }

  int tally_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_52_1 > 49)
  {
    acc_1 = ((acc_1 + (tally_52_1 * 2)) + 5) & 127;
    aux_1 ^= tally_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_52_2 > 49)
  {
    acc_2 = ((acc_2 + (tally_52_2 * 2)) + 5) & 127;
    aux_2 ^= tally_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_46_1) & 63;
  aux_2 = (aux_2 + tally_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_43_1 == stride_43_2);
  assert(tally_52_1 == tally_52_2);
  assert(tally_46_1 == tally_46_2);
}

int fn_R001080_8013_6(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001080_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int stride_43 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_43 = ((stride_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_43) & 127;
  }

  int tally_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_52 > 49)
  {
    acc = ((acc + (tally_52 * 2)) + 5) & 127;
    aux ^= tally_52 & 15;
  }
  else
  {
    acc = ((acc - tally_52) + 11) & 127;
    aux += 3;
  }
  int tally_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_46) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001080_8013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001080_8013_1 st_1 = {0};
  struct SensorNode_R001080_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_13_1 = local_arr_1[aux_1 % 3];
  int scale_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_13_2 * 2)) & 127;
  int segment_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_54_1) & 63;
  aux_2 = (aux_2 + segment_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_21_1 > 44)
  {
    acc_1 = ((acc_1 + (stride_21_1 * 2)) + 5) & 127;
    aux_1 ^= stride_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_21_2 > 44)
  {
    acc_2 = ((acc_2 + (stride_21_2 * 2)) + 5) & 127;
    aux_2 ^= stride_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_21_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_13_1 == scale_13_2);
  assert(segment_54_1 == segment_54_2);
  assert(stride_21_1 == stride_21_2);
}

int fn_R001080_8013_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001080_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int scale_13 = local_arr[aux % 3];
  acc = (acc + (scale_13 * 2)) & 127;
  int segment_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_54) & 63;
  acc ^= aux;
  int stride_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_21 > 44)
  {
    acc = ((acc + (stride_21 * 2)) + 5) & 127;
    aux ^= stride_21 & 15;
  }
  else
  {
    acc = ((acc - stride_21) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001080_8013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001080_8013_2 st_1 = {0};
  struct MatrixBlock_R001080_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_98_1 > 25)
  {
    acc_1 = ((acc_1 + (phase_98_1 * 2)) + 5) & 127;
    aux_1 ^= phase_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_98_2 > 25)
  {
    acc_2 = ((acc_2 + (phase_98_2 * 2)) + 5) & 127;
    aux_2 ^= phase_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_55_1) & 63;
  aux_2 = (aux_2 + vector_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_42_1 = 0;
  int checksum_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_42_1 = ((checksum_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_42_2 = ((checksum_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_42_1) & 127;
    acc_2 = (acc_2 + checksum_42_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_98_1 == phase_98_2);
  assert(vector_55_1 == vector_55_2);
  assert(checksum_42_1 == checksum_42_2);
}

int fn_R001080_8013_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001080_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_98 > 25)
  {
    acc = ((acc + (phase_98 * 2)) + 5) & 127;
    aux ^= phase_98 & 15;
  }
  else
  {
    acc = ((acc - phase_98) + 11) & 127;
    aux += 3;
  }
  int vector_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_55) & 63;
  acc ^= aux;
  int checksum_42 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_42 = ((checksum_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_42) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001080_8013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001080_8013_0 st_1 = {0};
  struct Vector3D_R001080_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int index_reg_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_56_1) & 63;
  aux_2 = (aux_2 + index_reg_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_58_1 = local_arr_1[aux_1 % 3];
  int vector_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_58_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_38_1 = 0;
  int bound_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_38_1 = ((bound_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_38_2 = ((bound_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_38_1) & 127;
    acc_2 = (acc_2 + bound_38_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_56_1 == index_reg_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_58_1 == vector_58_2);
  assert(bound_38_1 == bound_38_2);
}

int fn_R001080_8013_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001080_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int index_reg_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_56) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int vector_58 = local_arr[aux % 3];
  acc = (acc + (vector_58 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_38 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_38 = ((bound_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_38) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001080_8013_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001080_8013_0 st_1 = {0};
  struct Vector3D_R001080_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int bound_46_1 = 0;
  int bound_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_46_1 = ((bound_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_46_2 = ((bound_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_46_1) & 127;
    acc_2 = (acc_2 + bound_46_2) & 127;
  }

  int scale_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_84_1) & 63;
  aux_2 = (aux_2 + scale_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_46_1 == bound_46_2);
  assert(scale_84_1 == scale_84_2);
}

int fn_R001080_8013_10(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001080_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int bound_46 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_46 = ((bound_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_46) & 127;
  }

  int scale_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001080_8013_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001080_8013_0 st_1 = {0};
  struct Vector3D_R001080_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_93_1)
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

  switch (checksum_93_2)
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
  int index_reg_76_1 = local_arr_1[aux_1 % 3];
  int index_reg_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_76_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_93_1 == checksum_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_76_1 == index_reg_76_2);
}

int fn_R001080_8013_11(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001080_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_93 = (aux + st.buffer[1]) & 3;
  switch (checksum_93)
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
  int index_reg_76 = local_arr[aux % 3];
  acc = (acc + (index_reg_76 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001080_8013_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001080_8013_2 st_1 = {0};
  struct MatrixBlock_R001080_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_43_1 = local_arr_1[aux_1 % 3];
  int pivot_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_43_2 * 2)) & 127;
  int margin_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_26_1) & 63;
  aux_2 = (aux_2 + margin_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_38_1)
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

  switch (vector_38_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_43_1 == pivot_43_2);
  assert(margin_26_1 == margin_26_2);
  assert(vector_38_1 == vector_38_2);
}

int fn_R001080_8013_12(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001080_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_43 = local_arr[aux % 3];
  acc = (acc + (pivot_43 * 2)) & 127;
  int margin_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_26) & 63;
  acc ^= aux;
  int vector_38 = (aux + st.buffer[1]) & 3;
  switch (vector_38)
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

void fn_R001080_8013_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001080_8013_2 st_1 = {0};
  struct MatrixBlock_R001080_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int bound_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_13_1)
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

  switch (bound_13_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_44_1 = local_arr_1[aux_1 % 3];
  int accumulator_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_13_1 == bound_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_44_1 == accumulator_44_2);
}

int fn_R001080_8013_13(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001080_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int bound_13 = (aux + st.buffer[1]) & 3;
  switch (bound_13)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_44 = local_arr[aux % 3];
  acc = (acc + (accumulator_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001080_8013_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001080_8013_0 st_1 = {0};
  struct Vector3D_R001080_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int pivot_62_1 = 0;
  int pivot_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_62_1 = ((pivot_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_62_2 = ((pivot_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_62_1) & 127;
    acc_2 = (acc_2 + pivot_62_2) & 127;
  }

  int delta_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_69_1) & 63;
  aux_2 = (aux_2 + delta_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_67_1)
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

  switch (mask_67_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_62_1 == pivot_62_2);
  assert(delta_69_1 == delta_69_2);
  assert(mask_67_1 == mask_67_2);
}

int fn_R001080_8013_14(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001080_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int pivot_62 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_62 = ((pivot_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_62) & 127;
  }

  int delta_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_69) & 63;
  acc ^= aux;
  int mask_67 = (aux + st.buffer[1]) & 3;
  switch (mask_67)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001080_0_1;
  int sec_r001080_0_2;
  int sec_r001080_1_1;
  int sec_r001080_1_2;
  int sec_r001080_2_1;
  int sec_r001080_2_2;
  int sec_r001080_3_1;
  int sec_r001080_3_2;
  int sec_r001080_4_1;
  int sec_r001080_4_2;
  int sec_r001080_5_1;
  int sec_r001080_5_2;
  int sec_r001080_6_1;
  int sec_r001080_6_2;
  int sec_r001080_7_1;
  int sec_r001080_7_2;
  int sec_r001080_8_1;
  int sec_r001080_8_2;
  int sec_r001080_9_1;
  int sec_r001080_9_2;
  int sec_r001080_10_1;
  int sec_r001080_10_2;
  int sec_r001080_11_1;
  int sec_r001080_11_2;
  int sec_r001080_12_1;
  int sec_r001080_12_2;
  int sec_r001080_13_1;
  int sec_r001080_13_2;
  int sec_r001080_14_1;
  int sec_r001080_14_2;
  int sec_r001080_15_1;
  int sec_r001080_15_2;
  int sec_r001080_16_1;
  int sec_r001080_16_2;
  int sec_r001080_17_1;
  int sec_r001080_17_2;
  int pub_r001080_0_1;
  int pub_r001080_0_2;
  int pub_r001080_1_1;
  int pub_r001080_1_2;
  int pub_r001080_2_1;
  int pub_r001080_2_2;
  int pub_r001080_3_1;
  int pub_r001080_3_2;
  int pub_r001080_4_1;
  int pub_r001080_4_2;
  int pub_r001080_5_1;
  int pub_r001080_5_2;
  int pub_r001080_6_1;
  int pub_r001080_6_2;
  int pub_r001080_7_1;
  int pub_r001080_7_2;
  int pub_r001080_8_1;
  int pub_r001080_8_2;
  int pub_r001080_9_1;
  int pub_r001080_9_2;
  int pub_r001080_10_1;
  int pub_r001080_10_2;
  int pub_r001080_11_1;
  int pub_r001080_11_2;
  int pub_r001080_12_1;
  int pub_r001080_12_2;
  int pub_r001080_13_1;
  int pub_r001080_13_2;
  int pub_r001080_14_1;
  int pub_r001080_14_2;
  int pub_r001080_15_1;
  int pub_r001080_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001080_0_1 >= (-100)) && (pub_r001080_0_1 <= 100));
  __CPROVER_assume((pub_r001080_0_2 >= (-100)) && (pub_r001080_0_2 <= 100));
  __CPROVER_assume((pub_r001080_1_1 >= (-100)) && (pub_r001080_1_1 <= 100));
  __CPROVER_assume((pub_r001080_1_2 >= (-100)) && (pub_r001080_1_2 <= 100));
  __CPROVER_assume((pub_r001080_2_1 >= (-100)) && (pub_r001080_2_1 <= 100));
  __CPROVER_assume((pub_r001080_2_2 >= (-100)) && (pub_r001080_2_2 <= 100));
  __CPROVER_assume((pub_r001080_3_1 >= (-100)) && (pub_r001080_3_1 <= 100));
  __CPROVER_assume((pub_r001080_3_2 >= (-100)) && (pub_r001080_3_2 <= 100));
  __CPROVER_assume((pub_r001080_4_1 >= (-100)) && (pub_r001080_4_1 <= 100));
  __CPROVER_assume((pub_r001080_4_2 >= (-100)) && (pub_r001080_4_2 <= 100));
  __CPROVER_assume((pub_r001080_5_1 >= (-100)) && (pub_r001080_5_1 <= 100));
  __CPROVER_assume((pub_r001080_5_2 >= (-100)) && (pub_r001080_5_2 <= 100));
  __CPROVER_assume((pub_r001080_6_1 >= (-100)) && (pub_r001080_6_1 <= 100));
  __CPROVER_assume((pub_r001080_6_2 >= (-100)) && (pub_r001080_6_2 <= 100));
  __CPROVER_assume((pub_r001080_7_1 >= (-100)) && (pub_r001080_7_1 <= 100));
  __CPROVER_assume((pub_r001080_7_2 >= (-100)) && (pub_r001080_7_2 <= 100));
  __CPROVER_assume((pub_r001080_8_1 >= (-100)) && (pub_r001080_8_1 <= 100));
  __CPROVER_assume((pub_r001080_8_2 >= (-100)) && (pub_r001080_8_2 <= 100));
  __CPROVER_assume((pub_r001080_9_1 >= (-100)) && (pub_r001080_9_1 <= 100));
  __CPROVER_assume((pub_r001080_9_2 >= (-100)) && (pub_r001080_9_2 <= 100));
  __CPROVER_assume((pub_r001080_10_1 >= (-100)) && (pub_r001080_10_1 <= 100));
  __CPROVER_assume((pub_r001080_10_2 >= (-100)) && (pub_r001080_10_2 <= 100));
  __CPROVER_assume((pub_r001080_11_1 >= (-100)) && (pub_r001080_11_1 <= 100));
  __CPROVER_assume((pub_r001080_11_2 >= (-100)) && (pub_r001080_11_2 <= 100));
  __CPROVER_assume((pub_r001080_12_1 >= (-100)) && (pub_r001080_12_1 <= 100));
  __CPROVER_assume((pub_r001080_12_2 >= (-100)) && (pub_r001080_12_2 <= 100));
  __CPROVER_assume((pub_r001080_13_1 >= (-100)) && (pub_r001080_13_1 <= 100));
  __CPROVER_assume((pub_r001080_13_2 >= (-100)) && (pub_r001080_13_2 <= 100));
  __CPROVER_assume((pub_r001080_14_1 >= (-100)) && (pub_r001080_14_1 <= 100));
  __CPROVER_assume((pub_r001080_14_2 >= (-100)) && (pub_r001080_14_2 <= 100));
  __CPROVER_assume((pub_r001080_15_1 >= (-100)) && (pub_r001080_15_1 <= 100));
  __CPROVER_assume((pub_r001080_15_2 >= (-100)) && (pub_r001080_15_2 <= 100));
  __CPROVER_assume((sec_r001080_0_1 >= 0) && (sec_r001080_0_1 <= 255));
  __CPROVER_assume((sec_r001080_0_2 >= 0) && (sec_r001080_0_2 <= 255));
  __CPROVER_assume((sec_r001080_1_1 >= 0) && (sec_r001080_1_1 <= 255));
  __CPROVER_assume((sec_r001080_1_2 >= 0) && (sec_r001080_1_2 <= 255));
  __CPROVER_assume((sec_r001080_2_1 >= 0) && (sec_r001080_2_1 <= 255));
  __CPROVER_assume((sec_r001080_2_2 >= 0) && (sec_r001080_2_2 <= 255));
  __CPROVER_assume((sec_r001080_3_1 >= 0) && (sec_r001080_3_1 <= 255));
  __CPROVER_assume((sec_r001080_3_2 >= 0) && (sec_r001080_3_2 <= 255));
  __CPROVER_assume((sec_r001080_4_1 >= 0) && (sec_r001080_4_1 <= 255));
  __CPROVER_assume((sec_r001080_4_2 >= 0) && (sec_r001080_4_2 <= 255));
  __CPROVER_assume((sec_r001080_5_1 >= 0) && (sec_r001080_5_1 <= 255));
  __CPROVER_assume((sec_r001080_5_2 >= 0) && (sec_r001080_5_2 <= 255));
  __CPROVER_assume((sec_r001080_6_1 >= 0) && (sec_r001080_6_1 <= 255));
  __CPROVER_assume((sec_r001080_6_2 >= 0) && (sec_r001080_6_2 <= 255));
  __CPROVER_assume((sec_r001080_7_1 >= 0) && (sec_r001080_7_1 <= 255));
  __CPROVER_assume((sec_r001080_7_2 >= 0) && (sec_r001080_7_2 <= 255));
  __CPROVER_assume((sec_r001080_8_1 >= 0) && (sec_r001080_8_1 <= 255));
  __CPROVER_assume((sec_r001080_8_2 >= 0) && (sec_r001080_8_2 <= 255));
  __CPROVER_assume((sec_r001080_9_1 >= 0) && (sec_r001080_9_1 <= 255));
  __CPROVER_assume((sec_r001080_9_2 >= 0) && (sec_r001080_9_2 <= 255));
  __CPROVER_assume((sec_r001080_10_1 >= 0) && (sec_r001080_10_1 <= 255));
  __CPROVER_assume((sec_r001080_10_2 >= 0) && (sec_r001080_10_2 <= 255));
  __CPROVER_assume((sec_r001080_11_1 >= 0) && (sec_r001080_11_1 <= 255));
  __CPROVER_assume((sec_r001080_11_2 >= 0) && (sec_r001080_11_2 <= 255));
  __CPROVER_assume((sec_r001080_12_1 >= 0) && (sec_r001080_12_1 <= 255));
  __CPROVER_assume((sec_r001080_12_2 >= 0) && (sec_r001080_12_2 <= 255));
  __CPROVER_assume((sec_r001080_13_1 >= 0) && (sec_r001080_13_1 <= 255));
  __CPROVER_assume((sec_r001080_13_2 >= 0) && (sec_r001080_13_2 <= 255));
  __CPROVER_assume((sec_r001080_14_1 >= 0) && (sec_r001080_14_1 <= 255));
  __CPROVER_assume((sec_r001080_14_2 >= 0) && (sec_r001080_14_2 <= 255));
  __CPROVER_assume((sec_r001080_15_1 >= 0) && (sec_r001080_15_1 <= 255));
  __CPROVER_assume((sec_r001080_15_2 >= 0) && (sec_r001080_15_2 <= 255));
  __CPROVER_assume((sec_r001080_16_1 >= 0) && (sec_r001080_16_1 <= 255));
  __CPROVER_assume((sec_r001080_16_2 >= 0) && (sec_r001080_16_2 <= 255));
  __CPROVER_assume((sec_r001080_17_1 >= 0) && (sec_r001080_17_1 <= 255));
  __CPROVER_assume((sec_r001080_17_2 >= 0) && (sec_r001080_17_2 <= 255));
  struct Vector3D_R001080_8013_0 st_var_0_1 = {0};
  struct Vector3D_R001080_8013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001080_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001080_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001080_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001080_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001080_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001080_0_2 + 7) & 15;
  struct SensorNode_R001080_8013_1 st_var_1_1 = {0};
  struct SensorNode_R001080_8013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001080_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001080_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001080_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001080_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001080_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001080_0_2 + 9) & 15;
  struct MatrixBlock_R001080_8013_2 st_var_2_1 = {0};
  struct MatrixBlock_R001080_8013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001080_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001080_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001080_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001080_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001080_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001080_0_2 + 11) & 15;
  union PacketPayload_R001080_8013_0 u_var_1;
  union PacketPayload_R001080_8013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001080_8013_0(sec_r001080_0_1, sec_r001080_1_1, pub_r001080_2_1, pub_r001080_3_1, pub_r001080_4_1);
  int helper_flow_0_2 = fn_R001080_8013_0(sec_r001080_0_2, sec_r001080_1_2, pub_r001080_2_2, pub_r001080_3_2, pub_r001080_4_2);
  fn_R001080_8013_0_2(sec_r001080_0_1, sec_r001080_1_1, pub_r001080_2_1, pub_r001080_3_1, pub_r001080_4_1, sec_r001080_0_2, sec_r001080_1_2, pub_r001080_2_2, pub_r001080_3_2, pub_r001080_4_2);
  int helper_flow_1_1 = fn_R001080_8013_1(sec_r001080_1_1, pub_r001080_2_1, pub_r001080_3_1, pub_r001080_4_1);
  int helper_flow_1_2 = fn_R001080_8013_1(sec_r001080_1_2, pub_r001080_2_2, pub_r001080_3_2, pub_r001080_4_2);
  fn_R001080_8013_1_2(sec_r001080_1_1, pub_r001080_2_1, pub_r001080_3_1, pub_r001080_4_1, sec_r001080_1_2, pub_r001080_2_2, pub_r001080_3_2, pub_r001080_4_2);
  int helper_flow_2_1 = fn_R001080_8013_2(sec_r001080_2_1, pub_r001080_3_1, pub_r001080_4_1, pub_r001080_5_1);
  int helper_flow_2_2 = fn_R001080_8013_2(sec_r001080_2_2, pub_r001080_3_2, pub_r001080_4_2, pub_r001080_5_2);
  fn_R001080_8013_2_2(sec_r001080_2_1, pub_r001080_3_1, pub_r001080_4_1, pub_r001080_5_1, sec_r001080_2_2, pub_r001080_3_2, pub_r001080_4_2, pub_r001080_5_2);
  int helper_flow_3_1 = fn_R001080_8013_3(sec_r001080_3_1, pub_r001080_4_1, pub_r001080_5_1, pub_r001080_6_1, pub_r001080_7_1);
  int helper_flow_3_2 = fn_R001080_8013_3(sec_r001080_3_2, pub_r001080_4_2, pub_r001080_5_2, pub_r001080_6_2, pub_r001080_7_2);
  fn_R001080_8013_3_2(sec_r001080_3_1, pub_r001080_4_1, pub_r001080_5_1, pub_r001080_6_1, pub_r001080_7_1, sec_r001080_3_2, pub_r001080_4_2, pub_r001080_5_2, pub_r001080_6_2, pub_r001080_7_2);
  int helper_flow_4_1 = fn_R001080_8013_4(sec_r001080_4_1, pub_r001080_5_1, pub_r001080_6_1, pub_r001080_7_1, pub_r001080_8_1);
  int helper_flow_4_2 = fn_R001080_8013_4(sec_r001080_4_2, pub_r001080_5_2, pub_r001080_6_2, pub_r001080_7_2, pub_r001080_8_2);
  fn_R001080_8013_4_2(sec_r001080_4_1, pub_r001080_5_1, pub_r001080_6_1, pub_r001080_7_1, pub_r001080_8_1, sec_r001080_4_2, pub_r001080_5_2, pub_r001080_6_2, pub_r001080_7_2, pub_r001080_8_2);
  int helper_flow_5_1 = fn_R001080_8013_5(sec_r001080_5_1, sec_r001080_6_1, pub_r001080_7_1, pub_r001080_8_1, pub_r001080_9_1);
  int helper_flow_5_2 = fn_R001080_8013_5(sec_r001080_5_2, sec_r001080_6_2, pub_r001080_7_2, pub_r001080_8_2, pub_r001080_9_2);
  fn_R001080_8013_5_2(sec_r001080_5_1, sec_r001080_6_1, pub_r001080_7_1, pub_r001080_8_1, pub_r001080_9_1, sec_r001080_5_2, sec_r001080_6_2, pub_r001080_7_2, pub_r001080_8_2, pub_r001080_9_2);
  int helper_flow_6_1 = fn_R001080_8013_6(sec_r001080_6_1, pub_r001080_7_1, pub_r001080_8_1);
  int helper_flow_6_2 = fn_R001080_8013_6(sec_r001080_6_2, pub_r001080_7_2, pub_r001080_8_2);
  fn_R001080_8013_6_2(sec_r001080_6_1, pub_r001080_7_1, pub_r001080_8_1, sec_r001080_6_2, pub_r001080_7_2, pub_r001080_8_2);
  int helper_flow_7_1 = fn_R001080_8013_7(sec_r001080_7_1, sec_r001080_8_1, pub_r001080_9_1, pub_r001080_10_1);
  int helper_flow_7_2 = fn_R001080_8013_7(sec_r001080_7_2, sec_r001080_8_2, pub_r001080_9_2, pub_r001080_10_2);
  fn_R001080_8013_7_2(sec_r001080_7_1, sec_r001080_8_1, pub_r001080_9_1, pub_r001080_10_1, sec_r001080_7_2, sec_r001080_8_2, pub_r001080_9_2, pub_r001080_10_2);
  int helper_flow_8_1 = fn_R001080_8013_8(sec_r001080_8_1, pub_r001080_9_1, pub_r001080_10_1, pub_r001080_11_1);
  int helper_flow_8_2 = fn_R001080_8013_8(sec_r001080_8_2, pub_r001080_9_2, pub_r001080_10_2, pub_r001080_11_2);
  fn_R001080_8013_8_2(sec_r001080_8_1, pub_r001080_9_1, pub_r001080_10_1, pub_r001080_11_1, sec_r001080_8_2, pub_r001080_9_2, pub_r001080_10_2, pub_r001080_11_2);
  int helper_flow_9_1 = fn_R001080_8013_9(sec_r001080_9_1, pub_r001080_10_1, pub_r001080_11_1, pub_r001080_12_1, pub_r001080_13_1);
  int helper_flow_9_2 = fn_R001080_8013_9(sec_r001080_9_2, pub_r001080_10_2, pub_r001080_11_2, pub_r001080_12_2, pub_r001080_13_2);
  fn_R001080_8013_9_2(sec_r001080_9_1, pub_r001080_10_1, pub_r001080_11_1, pub_r001080_12_1, pub_r001080_13_1, sec_r001080_9_2, pub_r001080_10_2, pub_r001080_11_2, pub_r001080_12_2, pub_r001080_13_2);
  int stage_v_0_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_0_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_0_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((sec_r001080_1_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_1_2 = (((sec_r001080_1_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_1_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001080_13_1) & 127;
  int stage_v_2_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001080_13_2) & 127;
  if (stage_v_2_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = ((pub_r001080_2_1 * 2) + 50) & 63;
  int stage_v_3_2 = ((pub_r001080_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001080_5_1 * 2) + 23) & 63;
  int stage_v_4_2 = ((pub_r001080_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001080_13_1) & 127;
  int stage_v_5_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001080_13_2) & 127;
  if (stage_v_5_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_6_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_6_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((pub_r001080_6_1 * 2) + 25) & 63;
  int stage_v_7_2 = ((pub_r001080_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001080_0_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_8_2 = (((sec_r001080_0_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_8_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = ((pub_r001080_13_1 * 2) + 49) & 63;
  int stage_v_9_2 = ((pub_r001080_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001080_13_1) & 127;
  int stage_v_10_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001080_13_2) & 127;
  if (stage_v_10_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001080_5_1) & 127;
  int stage_v_11_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001080_5_2) & 127;
  if (stage_v_11_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((sec_r001080_16_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_12_2 = (((sec_r001080_16_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_12_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_13_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_13_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001080_9_1) & 127;
  int stage_v_14_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001080_9_2) & 127;
  if (stage_v_14_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((pub_r001080_12_1 * 2) + 41) & 63;
  int stage_v_15_2 = ((pub_r001080_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001080_8_1 * 2) + 50) & 63;
  int stage_v_16_2 = ((pub_r001080_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_17_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_17_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((sec_r001080_0_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_18_2 = (((sec_r001080_0_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_18_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((sec_r001080_1_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_19_2 = (((sec_r001080_1_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_19_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001080_0_1) & 127;
  int stage_v_20_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001080_0_2) & 127;
  if (stage_v_20_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((sec_r001080_9_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_21_2 = (((sec_r001080_9_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_21_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((sec_r001080_0_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_22_2 = (((sec_r001080_0_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_22_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((pub_r001080_4_1 * 2) + 50) & 63;
  int stage_v_23_2 = ((pub_r001080_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (((sec_r001080_15_1 ^ 0x2A) * 2) + pub_r001080_8_1) & 127;
  int stage_v_24_2 = (((sec_r001080_15_2 ^ 0x2A) * 2) + pub_r001080_8_2) & 127;
  if (stage_v_24_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001080_2_1) & 127;
  int stage_v_25_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001080_2_2) & 127;
  if (stage_v_25_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_26_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_26_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_27_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_27_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_28_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_28_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001080_13_1) & 127;
  int stage_v_29_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001080_13_2) & 127;
  if (stage_v_29_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_30_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_30_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((sec_r001080_6_1 ^ 0x2A) * 2) + pub_r001080_2_1) & 127;
  int stage_v_31_2 = (((sec_r001080_6_2 ^ 0x2A) * 2) + pub_r001080_2_2) & 127;
  if (stage_v_31_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((sec_r001080_11_1 ^ 0x2A) * 2) + pub_r001080_11_1) & 127;
  int stage_v_32_2 = (((sec_r001080_11_2 ^ 0x2A) * 2) + pub_r001080_11_2) & 127;
  if (stage_v_32_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((pub_r001080_0_1 * 2) + 25) & 63;
  int stage_v_33_2 = ((pub_r001080_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001080_5_1 * 2) + 11) & 63;
  int stage_v_34_2 = ((pub_r001080_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (((sec_r001080_11_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_35_2 = (((sec_r001080_11_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_35_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001080_7_1) & 127;
  int stage_v_36_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001080_7_2) & 127;
  if (stage_v_36_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_37_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_37_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((pub_r001080_14_1 * 2) + 10) & 63;
  int stage_v_38_2 = ((pub_r001080_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001080_8_1 * 2) + 7) & 63;
  int stage_v_39_2 = ((pub_r001080_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001080_15_1 * 2) + 11) & 63;
  int stage_v_40_2 = ((pub_r001080_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_41_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_41_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((sec_r001080_2_1 ^ 0x2A) * 2) + pub_r001080_7_1) & 127;
  int stage_v_42_2 = (((sec_r001080_2_2 ^ 0x2A) * 2) + pub_r001080_7_2) & 127;
  if (stage_v_42_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_43_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_43_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((pub_r001080_14_1 * 2) + 37) & 63;
  int stage_v_44_2 = ((pub_r001080_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001080_12_1 * 2) + 48) & 63;
  int stage_v_45_2 = ((pub_r001080_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001080_0_1) & 127;
  int stage_v_46_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001080_0_2) & 127;
  if (stage_v_46_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_47_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_47_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((sec_r001080_12_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_48_2 = (((sec_r001080_12_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_48_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_49_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_49_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_50_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_50_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001080_9_1) & 127;
  int stage_v_51_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001080_9_2) & 127;
  if (stage_v_51_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_52_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_52_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001080_6_1) & 127;
  int stage_v_53_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001080_6_2) & 127;
  if (stage_v_53_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_54_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_54_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_55_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_55_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001080_0_1) & 127;
  int stage_v_56_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001080_0_2) & 127;
  if (stage_v_56_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((pub_r001080_4_1 * 2) + 27) & 63;
  int stage_v_57_2 = ((pub_r001080_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001080_13_1 * 2) + 5) & 63;
  int stage_v_58_2 = ((pub_r001080_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_59_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_59_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((pub_r001080_3_1 * 2) + 8) & 63;
  int stage_v_60_2 = ((pub_r001080_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_61_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_61_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((pub_r001080_3_1 * 2) + 49) & 63;
  int stage_v_62_2 = ((pub_r001080_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_63_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_63_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001080_2_1) & 127;
  int stage_v_64_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001080_2_2) & 127;
  if (stage_v_64_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001080_2_1) & 127;
  int stage_v_65_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001080_2_2) & 127;
  if (stage_v_65_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_66_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_66_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((sec_r001080_6_1 ^ 0x2A) * 2) + pub_r001080_2_1) & 127;
  int stage_v_67_2 = (((sec_r001080_6_2 ^ 0x2A) * 2) + pub_r001080_2_2) & 127;
  if (stage_v_67_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001080_9_1) & 127;
  int stage_v_68_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001080_9_2) & 127;
  if (stage_v_68_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_69_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_69_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_70_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_70_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001080_10_1) & 127;
  int stage_v_71_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001080_10_2) & 127;
  if (stage_v_71_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_72_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_72_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001080_10_1) & 127;
  int stage_v_73_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001080_10_2) & 127;
  if (stage_v_73_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((sec_r001080_11_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_74_2 = (((sec_r001080_11_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_74_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001080_10_1) & 127;
  int stage_v_75_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001080_10_2) & 127;
  if (stage_v_75_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_76_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_76_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_77_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_77_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (((sec_r001080_8_1 ^ 0x2A) * 2) + pub_r001080_6_1) & 127;
  int stage_v_78_2 = (((sec_r001080_8_2 ^ 0x2A) * 2) + pub_r001080_6_2) & 127;
  if (stage_v_78_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((sec_r001080_2_1 ^ 0x2A) * 2) + pub_r001080_7_1) & 127;
  int stage_v_79_2 = (((sec_r001080_2_2 ^ 0x2A) * 2) + pub_r001080_7_2) & 127;
  if (stage_v_79_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_80_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_80_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001080_0_1) & 127;
  int stage_v_81_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001080_0_2) & 127;
  if (stage_v_81_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_82_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_82_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((pub_r001080_8_1 * 2) + 29) & 63;
  int stage_v_83_2 = ((pub_r001080_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_84_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_84_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001080_13_1) & 127;
  int stage_v_85_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001080_13_2) & 127;
  if (stage_v_85_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_86_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_86_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_87_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_87_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((sec_r001080_8_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_88_2 = (((sec_r001080_8_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_88_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((stage_v_80_1 ^ 0x2A) * 2) + pub_r001080_9_1) & 127;
  int stage_v_89_2 = (((stage_v_80_2 ^ 0x2A) * 2) + pub_r001080_9_2) & 127;
  if (stage_v_89_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001080_10_1) & 127;
  int stage_v_90_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001080_10_2) & 127;
  if (stage_v_90_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_91_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_91_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_92_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_92_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_93_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_93_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_94_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_94_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((pub_r001080_11_1 * 2) + 43) & 63;
  int stage_v_95_2 = ((pub_r001080_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_96_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_96_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((pub_r001080_7_1 * 2) + 29) & 63;
  int stage_v_97_2 = ((pub_r001080_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001080_13_1 * 2) + 31) & 63;
  int stage_v_98_2 = ((pub_r001080_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001080_2_1 * 2) + 12) & 63;
  int stage_v_99_2 = ((pub_r001080_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_100_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_100_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((pub_r001080_10_1 * 2) + 5) & 63;
  int stage_v_101_2 = ((pub_r001080_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((stage_v_69_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_102_2 = (((stage_v_69_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_102_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001080_8_1) & 127;
  int stage_v_103_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001080_8_2) & 127;
  if (stage_v_103_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001080_8_1) & 127;
  int stage_v_104_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001080_8_2) & 127;
  if (stage_v_104_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((pub_r001080_8_1 * 2) + 22) & 63;
  int stage_v_105_2 = ((pub_r001080_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001080_9_1) & 127;
  int stage_v_106_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001080_9_2) & 127;
  if (stage_v_106_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001080_5_1) & 127;
  int stage_v_107_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001080_5_2) & 127;
  if (stage_v_107_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((pub_r001080_5_1 * 2) + 24) & 63;
  int stage_v_108_2 = ((pub_r001080_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001080_15_1 * 2) + 30) & 63;
  int stage_v_109_2 = ((pub_r001080_15_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001080_6_1) & 127;
  int stage_v_110_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001080_6_2) & 127;
  if (stage_v_110_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_111_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_111_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((stage_v_76_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_112_2 = (((stage_v_76_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_112_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((sec_r001080_16_1 ^ 0x2A) * 2) + pub_r001080_6_1) & 127;
  int stage_v_113_2 = (((sec_r001080_16_2 ^ 0x2A) * 2) + pub_r001080_6_2) & 127;
  if (stage_v_113_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001080_6_1) & 127;
  int stage_v_114_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001080_6_2) & 127;
  if (stage_v_114_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_115_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_115_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001080_10_1) & 127;
  int stage_v_116_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001080_10_2) & 127;
  if (stage_v_116_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (((sec_r001080_6_1 ^ 0x2A) * 2) + pub_r001080_13_1) & 127;
  int stage_v_117_2 = (((sec_r001080_6_2 ^ 0x2A) * 2) + pub_r001080_13_2) & 127;
  if (stage_v_117_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((pub_r001080_4_1 * 2) + 27) & 63;
  int stage_v_118_2 = ((pub_r001080_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001080_9_1 * 2) + 26) & 63;
  int stage_v_119_2 = ((pub_r001080_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001080_7_1) & 127;
  int stage_v_120_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001080_7_2) & 127;
  if (stage_v_120_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001080_0_1) & 127;
  int stage_v_121_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001080_0_2) & 127;
  if (stage_v_121_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((pub_r001080_8_1 * 2) + 38) & 63;
  int stage_v_122_2 = ((pub_r001080_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001080_12_1 * 2) + 46) & 63;
  int stage_v_123_2 = ((pub_r001080_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_124_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_124_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_125_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_125_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = (((sec_r001080_5_1 ^ 0x2A) * 2) + pub_r001080_6_1) & 127;
  int stage_v_126_2 = (((sec_r001080_5_2 ^ 0x2A) * 2) + pub_r001080_6_2) & 127;
  if (stage_v_126_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001080_9_1) & 127;
  int stage_v_127_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001080_9_2) & 127;
  if (stage_v_127_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001080_11_1) & 127;
  int stage_v_128_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001080_11_2) & 127;
  if (stage_v_128_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001080_2_1) & 127;
  int stage_v_129_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001080_2_2) & 127;
  if (stage_v_129_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((pub_r001080_11_1 * 2) + 16) & 63;
  int stage_v_130_2 = ((pub_r001080_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001080_10_1) & 127;
  int stage_v_131_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001080_10_2) & 127;
  if (stage_v_131_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_132_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_132_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((stage_v_124_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_133_2 = (((stage_v_124_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_133_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001080_10_1) & 127;
  int stage_v_134_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001080_10_2) & 127;
  if (stage_v_134_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001080_13_1) & 127;
  int stage_v_135_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001080_13_2) & 127;
  if (stage_v_135_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = (((stage_v_81_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_136_2 = (((stage_v_81_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_136_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_137_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_137_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (((sec_r001080_9_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_138_2 = (((sec_r001080_9_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_138_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((pub_r001080_0_1 * 2) + 14) & 63;
  int stage_v_139_2 = ((pub_r001080_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001080_0_1 * 2) + 40) & 63;
  int stage_v_140_2 = ((pub_r001080_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (((sec_r001080_7_1 ^ 0x2A) * 2) + pub_r001080_5_1) & 127;
  int stage_v_141_2 = (((sec_r001080_7_2 ^ 0x2A) * 2) + pub_r001080_5_2) & 127;
  if (stage_v_141_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_142_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_142_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_143_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_143_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001080_11_1) & 127;
  int stage_v_144_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001080_11_2) & 127;
  if (stage_v_144_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((pub_r001080_15_1 * 2) + 12) & 63;
  int stage_v_145_2 = ((pub_r001080_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (((stage_v_124_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_146_2 = (((stage_v_124_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_146_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_147_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_147_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_148_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_148_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((sec_r001080_15_1 ^ 0x2A) * 2) + pub_r001080_8_1) & 127;
  int stage_v_149_2 = (((sec_r001080_15_2 ^ 0x2A) * 2) + pub_r001080_8_2) & 127;
  if (stage_v_149_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001080_6_1) & 127;
  int stage_v_150_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001080_6_2) & 127;
  if (stage_v_150_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = (((stage_v_125_1 ^ 0x2A) * 2) + pub_r001080_0_1) & 127;
  int stage_v_151_2 = (((stage_v_125_2 ^ 0x2A) * 2) + pub_r001080_0_2) & 127;
  if (stage_v_151_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((pub_r001080_7_1 * 2) + 47) & 63;
  int stage_v_152_2 = ((pub_r001080_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_153_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_153_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001080_0_1) & 127;
  int stage_v_154_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001080_0_2) & 127;
  if (stage_v_154_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_155_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_155_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_156_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_156_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_157_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_157_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001080_5_1) & 127;
  int stage_v_158_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001080_5_2) & 127;
  if (stage_v_158_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((pub_r001080_12_1 * 2) + 13) & 63;
  int stage_v_159_2 = ((pub_r001080_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001080_8_1) & 127;
  int stage_v_160_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001080_8_2) & 127;
  if (stage_v_160_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001080_9_1) & 127;
  int stage_v_161_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001080_9_2) & 127;
  if (stage_v_161_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((stage_v_143_1 ^ 0x2A) * 2) + pub_r001080_6_1) & 127;
  int stage_v_162_2 = (((stage_v_143_2 ^ 0x2A) * 2) + pub_r001080_6_2) & 127;
  if (stage_v_162_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((stage_v_133_1 ^ 0x2A) * 2) + pub_r001080_6_1) & 127;
  int stage_v_163_2 = (((stage_v_133_2 ^ 0x2A) * 2) + pub_r001080_6_2) & 127;
  if (stage_v_163_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_164_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_164_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((stage_v_117_1 ^ 0x2A) * 2) + pub_r001080_5_1) & 127;
  int stage_v_165_2 = (((stage_v_117_2 ^ 0x2A) * 2) + pub_r001080_5_2) & 127;
  if (stage_v_165_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((stage_v_157_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_166_2 = (((stage_v_157_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_166_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001080_7_1) & 127;
  int stage_v_167_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001080_7_2) & 127;
  if (stage_v_167_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_151_1 ^ 0x2A) * 2) + pub_r001080_5_1) & 127;
  int stage_v_168_2 = (((stage_v_151_2 ^ 0x2A) * 2) + pub_r001080_5_2) & 127;
  if (stage_v_168_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((pub_r001080_13_1 * 2) + 39) & 63;
  int stage_v_169_2 = ((pub_r001080_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_170_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_170_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((stage_v_166_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_171_2 = (((stage_v_166_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_171_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = (((stage_v_149_1 ^ 0x2A) * 2) + pub_r001080_5_1) & 127;
  int stage_v_172_2 = (((stage_v_149_2 ^ 0x2A) * 2) + pub_r001080_5_2) & 127;
  if (stage_v_172_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((stage_v_148_1 ^ 0x2A) * 2) + pub_r001080_9_1) & 127;
  int stage_v_173_2 = (((stage_v_148_2 ^ 0x2A) * 2) + pub_r001080_9_2) & 127;
  if (stage_v_173_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((stage_v_150_1 ^ 0x2A) * 2) + pub_r001080_13_1) & 127;
  int stage_v_174_2 = (((stage_v_150_2 ^ 0x2A) * 2) + pub_r001080_13_2) & 127;
  if (stage_v_174_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = (((stage_v_124_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_175_2 = (((stage_v_124_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_175_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((pub_r001080_0_1 * 2) + 39) & 63;
  int stage_v_176_2 = ((pub_r001080_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001080_7_1) & 127;
  int stage_v_177_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001080_7_2) & 127;
  if (stage_v_177_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((pub_r001080_11_1 * 2) + 42) & 63;
  int stage_v_178_2 = ((pub_r001080_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (((stage_v_150_1 ^ 0x2A) * 2) + pub_r001080_11_1) & 127;
  int stage_v_179_2 = (((stage_v_150_2 ^ 0x2A) * 2) + pub_r001080_11_2) & 127;
  if (stage_v_179_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((pub_r001080_2_1 * 2) + 27) & 63;
  int stage_v_180_2 = ((pub_r001080_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001080_15_1 * 2) + 44) & 63;
  int stage_v_181_2 = ((pub_r001080_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((stage_v_168_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_182_2 = (((stage_v_168_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_182_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (((stage_v_115_1 ^ 0x2A) * 2) + pub_r001080_5_1) & 127;
  int stage_v_183_2 = (((stage_v_115_2 ^ 0x2A) * 2) + pub_r001080_5_2) & 127;
  if (stage_v_183_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = (((stage_v_133_1 ^ 0x2A) * 2) + pub_r001080_5_1) & 127;
  int stage_v_184_2 = (((stage_v_133_2 ^ 0x2A) * 2) + pub_r001080_5_2) & 127;
  if (stage_v_184_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = (((stage_v_128_1 ^ 0x2A) * 2) + pub_r001080_5_1) & 127;
  int stage_v_185_2 = (((stage_v_128_2 ^ 0x2A) * 2) + pub_r001080_5_2) & 127;
  if (stage_v_185_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = (((stage_v_154_1 ^ 0x2A) * 2) + pub_r001080_13_1) & 127;
  int stage_v_186_2 = (((stage_v_154_2 ^ 0x2A) * 2) + pub_r001080_13_2) & 127;
  if (stage_v_186_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((pub_r001080_2_1 * 2) + 18) & 63;
  int stage_v_187_2 = ((pub_r001080_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_188_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_188_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((pub_r001080_6_1 * 2) + 13) & 63;
  int stage_v_189_2 = ((pub_r001080_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001080_6_1 * 2) + 39) & 63;
  int stage_v_190_2 = ((pub_r001080_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_191_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_191_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001080_8_1) & 127;
  int stage_v_192_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001080_8_2) & 127;
  if (stage_v_192_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((sec_r001080_4_1 ^ 0x2A) * 2) + pub_r001080_6_1) & 127;
  int stage_v_193_2 = (((sec_r001080_4_2 ^ 0x2A) * 2) + pub_r001080_6_2) & 127;
  if (stage_v_193_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_129_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_194_2 = (((stage_v_129_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_194_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001080_10_1) & 127;
  int stage_v_195_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001080_10_2) & 127;
  if (stage_v_195_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_196_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_196_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001080_13_1) & 127;
  int stage_v_197_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001080_13_2) & 127;
  if (stage_v_197_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((pub_r001080_6_1 * 2) + 30) & 63;
  int stage_v_198_2 = ((pub_r001080_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001080_11_1) & 127;
  int stage_v_199_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001080_11_2) & 127;
  if (stage_v_199_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = (((stage_v_104_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_200_2 = (((stage_v_104_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_200_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001080_7_1) & 127;
  int stage_v_201_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001080_7_2) & 127;
  if (stage_v_201_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = (((stage_v_186_1 ^ 0x2A) * 2) + pub_r001080_7_1) & 127;
  int stage_v_202_2 = (((stage_v_186_2 ^ 0x2A) * 2) + pub_r001080_7_2) & 127;
  if (stage_v_202_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((pub_r001080_0_1 * 2) + 20) & 63;
  int stage_v_203_2 = ((pub_r001080_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((stage_v_157_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_204_2 = (((stage_v_157_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_204_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = (((sec_r001080_3_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_205_2 = (((sec_r001080_3_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_205_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = (((stage_v_185_1 ^ 0x2A) * 2) + pub_r001080_2_1) & 127;
  int stage_v_206_2 = (((stage_v_185_2 ^ 0x2A) * 2) + pub_r001080_2_2) & 127;
  if (stage_v_206_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_207_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_207_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001080_9_1) & 127;
  int stage_v_208_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001080_9_2) & 127;
  if (stage_v_208_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((pub_r001080_5_1 * 2) + 50) & 63;
  int stage_v_209_2 = ((pub_r001080_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001080_8_1 * 2) + 28) & 63;
  int stage_v_210_2 = ((pub_r001080_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_211_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_211_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001080_5_1) & 127;
  int stage_v_212_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001080_5_2) & 127;
  if (stage_v_212_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = (((stage_v_146_1 ^ 0x2A) * 2) + pub_r001080_10_1) & 127;
  int stage_v_213_2 = (((stage_v_146_2 ^ 0x2A) * 2) + pub_r001080_10_2) & 127;
  if (stage_v_213_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = (((stage_v_172_1 ^ 0x2A) * 2) + pub_r001080_2_1) & 127;
  int stage_v_214_2 = (((stage_v_172_2 ^ 0x2A) * 2) + pub_r001080_2_2) & 127;
  if (stage_v_214_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = (((stage_v_172_1 ^ 0x2A) * 2) + pub_r001080_13_1) & 127;
  int stage_v_215_2 = (((stage_v_172_2 ^ 0x2A) * 2) + pub_r001080_13_2) & 127;
  if (stage_v_215_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((pub_r001080_4_1 * 2) + 11) & 63;
  int stage_v_216_2 = ((pub_r001080_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001080_2_1) & 127;
  int stage_v_217_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001080_2_2) & 127;
  if (stage_v_217_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((stage_v_131_1 ^ 0x2A) * 2) + pub_r001080_2_1) & 127;
  int stage_v_218_2 = (((stage_v_131_2 ^ 0x2A) * 2) + pub_r001080_2_2) & 127;
  if (stage_v_218_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_219_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_219_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((pub_r001080_2_1 * 2) + 6) & 63;
  int stage_v_220_2 = ((pub_r001080_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = (((stage_v_157_1 ^ 0x2A) * 2) + pub_r001080_5_1) & 127;
  int stage_v_221_2 = (((stage_v_157_2 ^ 0x2A) * 2) + pub_r001080_5_2) & 127;
  if (stage_v_221_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001080_13_1) & 127;
  int stage_v_222_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001080_13_2) & 127;
  if (stage_v_222_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((pub_r001080_2_1 * 2) + 50) & 63;
  int stage_v_223_2 = ((pub_r001080_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = (((stage_v_150_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_224_2 = (((stage_v_150_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_224_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
  }
  if (stage_v_224_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = (((sec_r001080_11_1 ^ 0x2A) * 2) + pub_r001080_9_1) & 127;
  int stage_v_225_2 = (((sec_r001080_11_2 ^ 0x2A) * 2) + pub_r001080_9_2) & 127;
  if (stage_v_225_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
  }
  if (stage_v_225_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = (((stage_v_133_1 ^ 0x2A) * 2) + pub_r001080_10_1) & 127;
  int stage_v_226_2 = (((stage_v_133_2 ^ 0x2A) * 2) + pub_r001080_10_2) & 127;
  if (stage_v_226_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
  }
  if (stage_v_226_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = (((stage_v_155_1 ^ 0x2A) * 2) + pub_r001080_11_1) & 127;
  int stage_v_227_2 = (((stage_v_155_2 ^ 0x2A) * 2) + pub_r001080_11_2) & 127;
  if (stage_v_227_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
  }
  if (stage_v_227_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = (((stage_v_214_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_228_2 = (((stage_v_214_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_228_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = (((stage_v_138_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_229_2 = (((stage_v_138_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_229_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
  }
  if (stage_v_229_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = (((stage_v_195_1 ^ 0x2A) * 2) + pub_r001080_11_1) & 127;
  int stage_v_230_2 = (((stage_v_195_2 ^ 0x2A) * 2) + pub_r001080_11_2) & 127;
  if (stage_v_230_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
  }
  if (stage_v_230_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = (((stage_v_227_1 ^ 0x2A) * 2) + pub_r001080_7_1) & 127;
  int stage_v_231_2 = (((stage_v_227_2 ^ 0x2A) * 2) + pub_r001080_7_2) & 127;
  if (stage_v_231_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
  }
  if (stage_v_231_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((pub_r001080_12_1 * 2) + 32) & 63;
  int stage_v_232_2 = ((pub_r001080_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_233_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_233_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
  }
  if (stage_v_233_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = (((stage_v_177_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_234_2 = (((stage_v_177_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_234_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
  }
  if (stage_v_234_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((pub_r001080_9_1 * 2) + 32) & 63;
  int stage_v_235_2 = ((pub_r001080_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001080_15_1 * 2) + 5) & 63;
  int stage_v_236_2 = ((pub_r001080_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001080_5_1) & 127;
  int stage_v_237_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001080_5_2) & 127;
  if (stage_v_237_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
  }
  if (stage_v_237_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = (((stage_v_146_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_238_2 = (((stage_v_146_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_238_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_238_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_238_1) + 13) & 255;
  }
  if (stage_v_238_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_238_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_238_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((pub_r001080_6_1 * 2) + 34) & 63;
  int stage_v_239_2 = ((pub_r001080_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((stage_v_206_1 ^ 0x2A) * 2) + pub_r001080_10_1) & 127;
  int stage_v_240_2 = (((stage_v_206_2 ^ 0x2A) * 2) + pub_r001080_10_2) & 127;
  if (stage_v_240_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
  }
  if (stage_v_240_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001080_0_1) & 127;
  int stage_v_241_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001080_0_2) & 127;
  if (stage_v_241_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
  }
  if (stage_v_241_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = (((stage_v_211_1 ^ 0x2A) * 2) + pub_r001080_0_1) & 127;
  int stage_v_242_2 = (((stage_v_211_2 ^ 0x2A) * 2) + pub_r001080_0_2) & 127;
  if (stage_v_242_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
  }
  if (stage_v_242_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_243_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_243_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_243_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_243_1) + 13) & 255;
  }
  if (stage_v_243_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_243_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_243_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001080_10_1) & 127;
  int stage_v_244_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001080_10_2) & 127;
  if (stage_v_244_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_244_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_244_1) + 13) & 255;
  }
  if (stage_v_244_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_244_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_244_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001080_0_1) & 127;
  int stage_v_245_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001080_0_2) & 127;
  if (stage_v_245_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_245_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_245_1) + 13) & 255;
  }
  if (stage_v_245_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_245_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_245_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_246_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_246_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
  }
  if (stage_v_246_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((pub_r001080_0_1 * 2) + 28) & 63;
  int stage_v_247_2 = ((pub_r001080_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = (((stage_v_134_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_248_2 = (((stage_v_134_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_248_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_248_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_248_1) + 13) & 255;
  }
  if (stage_v_248_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_248_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_248_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((pub_r001080_10_1 * 2) + 37) & 63;
  int stage_v_249_2 = ((pub_r001080_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_250_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_250_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_250_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_250_1) + 13) & 255;
  }
  if (stage_v_250_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_250_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_250_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_251_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_251_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_251_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_251_1) + 13) & 255;
  }
  if (stage_v_251_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_251_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_251_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001080_12_1) & 127;
  int stage_v_252_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001080_12_2) & 127;
  if (stage_v_252_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_252_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_252_1) + 13) & 255;
  }
  if (stage_v_252_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_252_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_252_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_253_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_253_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_253_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_253_1) + 13) & 255;
  }
  if (stage_v_253_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_253_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_253_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = (((sec_r001080_2_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_254_2 = (((sec_r001080_2_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_254_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_254_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_254_1) + 13) & 255;
  }
  if (stage_v_254_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_254_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_254_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001080_3_1) & 127;
  int stage_v_255_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001080_3_2) & 127;
  if (stage_v_255_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_255_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_255_1) + 13) & 255;
  }
  if (stage_v_255_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_255_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_255_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((pub_r001080_0_1 * 2) + 23) & 63;
  int stage_v_256_2 = ((pub_r001080_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001080_9_1 * 2) + 36) & 63;
  int stage_v_257_2 = ((pub_r001080_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001080_2_1) & 127;
  int stage_v_258_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001080_2_2) & 127;
  if (stage_v_258_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_258_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_258_1) + 13) & 255;
  }
  if (stage_v_258_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_258_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_258_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = (((stage_v_214_1 ^ 0x2A) * 2) + pub_r001080_2_1) & 127;
  int stage_v_259_2 = (((stage_v_214_2 ^ 0x2A) * 2) + pub_r001080_2_2) & 127;
  if (stage_v_259_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_259_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_259_1) + 13) & 255;
  }
  if (stage_v_259_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_259_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_259_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((pub_r001080_4_1 * 2) + 10) & 63;
  int stage_v_260_2 = ((pub_r001080_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001080_9_1 * 2) + 28) & 63;
  int stage_v_261_2 = ((pub_r001080_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001080_1_1 * 2) + 47) & 63;
  int stage_v_262_2 = ((pub_r001080_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((stage_v_166_1 ^ 0x2A) * 2) + pub_r001080_6_1) & 127;
  int stage_v_263_2 = (((stage_v_166_2 ^ 0x2A) * 2) + pub_r001080_6_2) & 127;
  if (stage_v_263_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_263_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_263_1) + 13) & 255;
  }
  if (stage_v_263_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_263_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_263_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001080_7_1) & 127;
  int stage_v_264_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001080_7_2) & 127;
  if (stage_v_264_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_264_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_264_1) + 13) & 255;
  }
  if (stage_v_264_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_264_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_264_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = (((stage_v_133_1 ^ 0x2A) * 2) + pub_r001080_4_1) & 127;
  int stage_v_265_2 = (((stage_v_133_2 ^ 0x2A) * 2) + pub_r001080_4_2) & 127;
  if (stage_v_265_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_265_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_265_1) + 13) & 255;
  }
  if (stage_v_265_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_265_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_265_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001080_14_1) & 127;
  int stage_v_266_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001080_14_2) & 127;
  if (stage_v_266_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_266_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_266_1) + 13) & 255;
  }
  if (stage_v_266_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_266_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_266_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001080_10_1) & 127;
  int stage_v_267_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001080_10_2) & 127;
  if (stage_v_267_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_267_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_267_1) + 13) & 255;
  }
  if (stage_v_267_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_267_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_267_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001080_13_1) & 127;
  int stage_v_268_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001080_13_2) & 127;
  if (stage_v_268_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_268_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_268_1) + 13) & 255;
  }
  if (stage_v_268_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_268_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_268_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((pub_r001080_7_1 * 2) + 37) & 63;
  int stage_v_269_2 = ((pub_r001080_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = (((stage_v_267_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_270_2 = (((stage_v_267_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_270_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_270_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_270_1) + 13) & 255;
  }
  if (stage_v_270_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_270_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_270_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((pub_r001080_7_1 * 2) + 9) & 63;
  int stage_v_271_2 = ((pub_r001080_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = (((stage_v_184_1 ^ 0x2A) * 2) + pub_r001080_15_1) & 127;
  int stage_v_272_2 = (((stage_v_184_2 ^ 0x2A) * 2) + pub_r001080_15_2) & 127;
  if (stage_v_272_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_272_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_272_1) + 13) & 255;
  }
  if (stage_v_272_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_272_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_272_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = (((stage_v_244_1 ^ 0x2A) * 2) + pub_r001080_0_1) & 127;
  int stage_v_273_2 = (((stage_v_244_2 ^ 0x2A) * 2) + pub_r001080_0_2) & 127;
  if (stage_v_273_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_273_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_273_1) + 13) & 255;
  }
  if (stage_v_273_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_273_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_273_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001080_2_1) & 127;
  int stage_v_274_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001080_2_2) & 127;
  if (stage_v_274_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_274_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_274_1) + 13) & 255;
  }
  if (stage_v_274_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_274_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_274_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = (((stage_v_237_1 ^ 0x2A) * 2) + pub_r001080_0_1) & 127;
  int stage_v_275_2 = (((stage_v_237_2 ^ 0x2A) * 2) + pub_r001080_0_2) & 127;
  if (stage_v_275_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_275_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_275_1) + 13) & 255;
  }
  if (stage_v_275_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_275_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_275_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = (((stage_v_270_1 ^ 0x2A) * 2) + pub_r001080_10_1) & 127;
  int stage_v_276_2 = (((stage_v_270_2 ^ 0x2A) * 2) + pub_r001080_10_2) & 127;
  if (stage_v_276_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_276_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_276_1) + 13) & 255;
  }
  if (stage_v_276_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_276_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_276_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = (((stage_v_167_1 ^ 0x2A) * 2) + pub_r001080_1_1) & 127;
  int stage_v_277_2 = (((stage_v_167_2 ^ 0x2A) * 2) + pub_r001080_1_2) & 127;
  if (stage_v_277_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_277_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_277_1) + 13) & 255;
  }
  if (stage_v_277_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_277_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_277_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = (((stage_v_156_1 ^ 0x2A) * 2) + pub_r001080_8_1) & 127;
  int stage_v_278_2 = (((stage_v_156_2 ^ 0x2A) * 2) + pub_r001080_8_2) & 127;
  if (stage_v_278_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_278_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_278_1) + 13) & 255;
  }
  if (stage_v_278_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_278_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_278_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((pub_r001080_15_1 * 2) + 26) & 63;
  int stage_v_279_2 = ((pub_r001080_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001080_0_1 == pub_r001080_0_2);
  __CPROVER_assume(sec_r001080_7_1 != sec_r001080_7_2);
  __CPROVER_assume(pub_r001080_12_1 == pub_r001080_12_2);
  __CPROVER_assume(sec_r001080_13_1 != sec_r001080_13_2);
  __CPROVER_assume(pub_r001080_11_1 == pub_r001080_11_2);
  __CPROVER_assume(sec_r001080_9_1 != sec_r001080_9_2);
  __CPROVER_assume(pub_r001080_2_1 == pub_r001080_2_2);
  __CPROVER_assume(pub_r001080_15_1 == pub_r001080_15_2);
  __CPROVER_assume(sec_r001080_0_1 != sec_r001080_0_2);
  __CPROVER_assume(pub_r001080_6_1 == pub_r001080_6_2);
  __CPROVER_assume(sec_r001080_6_1 != sec_r001080_6_2);
  __CPROVER_assume(sec_r001080_14_1 != sec_r001080_14_2);
  __CPROVER_assume(sec_r001080_16_1 != sec_r001080_16_2);
  __CPROVER_assume(pub_r001080_10_1 == pub_r001080_10_2);
  __CPROVER_assume(sec_r001080_17_1 != sec_r001080_17_2);
  __CPROVER_assume(sec_r001080_3_1 != sec_r001080_3_2);
  __CPROVER_assume(pub_r001080_1_1 == pub_r001080_1_2);
  __CPROVER_assume(sec_r001080_8_1 != sec_r001080_8_2);
  __CPROVER_assume(sec_r001080_2_1 != sec_r001080_2_2);
  __CPROVER_assume(pub_r001080_5_1 == pub_r001080_5_2);
  __CPROVER_assume(pub_r001080_4_1 == pub_r001080_4_2);
  __CPROVER_assume(pub_r001080_8_1 == pub_r001080_8_2);
  __CPROVER_assume(sec_r001080_15_1 != sec_r001080_15_2);
  __CPROVER_assume(pub_r001080_14_1 == pub_r001080_14_2);
  __CPROVER_assume(sec_r001080_10_1 != sec_r001080_10_2);
  __CPROVER_assume(pub_r001080_3_1 == pub_r001080_3_2);
  __CPROVER_assume(sec_r001080_1_1 != sec_r001080_1_2);
  __CPROVER_assume(pub_r001080_9_1 == pub_r001080_9_2);
  __CPROVER_assume(sec_r001080_4_1 != sec_r001080_4_2);
  __CPROVER_assume(sec_r001080_12_1 != sec_r001080_12_2);
  __CPROVER_assume(sec_r001080_5_1 != sec_r001080_5_2);
  __CPROVER_assume(pub_r001080_13_1 == pub_r001080_13_2);
  __CPROVER_assume(sec_r001080_11_1 != sec_r001080_11_2);
  __CPROVER_assume(pub_r001080_7_1 == pub_r001080_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.trace == st_var_2_2.trace);
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
  assert(helper_flow_8_1 == helper_flow_8_2);
  assert(helper_flow_9_1 == helper_flow_9_2);
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
}


