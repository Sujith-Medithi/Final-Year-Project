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
struct Vector3D_R000124_2413_0
{
  unsigned char coord_y;
  short norm_sq;
  int coord_x;
  short coord_z;
  int pitch;
  int buffer[3];
};
struct StreamBuffer_R000124_2413_1
{
  short checksum;
  int capacity;
  int tail;
  int buffer[3];
};
struct SensorNode_R000124_2413_2
{
  int gain;
  unsigned char status;
  unsigned char calib;
  int offset;
  int reading;
  int buffer[3];
};
struct AudioFrame_R000124_2413_3
{
  int envelope;
  int peak;
  int rms;
  int gain;
  unsigned char channels;
  int sample_rate;
  int buffer[3];
};
union TelemetryField_R000124_2413_0
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
void fn_R000124_2413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000124_2413_1 st_1 = {0};
  struct StreamBuffer_R000124_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int margin_27_1 = 0;
  int margin_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_27_1 = ((margin_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_27_2 = ((margin_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_27_1) & 127;
    acc_2 = (acc_2 + margin_27_2) & 127;
  }

  int index_reg_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_29_1)
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

  switch (index_reg_29_2)
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
  int quotient_86_1 = local_arr_1[aux_1 % 3];
  int quotient_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_86_2 * 2)) & 127;
  int residue_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_78_1 > 42)
  {
    acc_1 = ((acc_1 + (residue_78_1 * 2)) + 5) & 127;
    aux_1 ^= residue_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_78_2 > 42)
  {
    acc_2 = ((acc_2 + (residue_78_2 * 2)) + 5) & 127;
    aux_2 ^= residue_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_27_1 == margin_27_2);
  assert(index_reg_29_1 == index_reg_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_86_1 == quotient_86_2);
  assert(residue_78_1 == residue_78_2);
}

int fn_R000124_2413_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000124_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int margin_27 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_27 = ((margin_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_27) & 127;
  }

  int index_reg_29 = (aux + st.buffer[1]) & 3;
  switch (index_reg_29)
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
  int quotient_86 = local_arr[aux % 3];
  acc = (acc + (quotient_86 * 2)) & 127;
  int residue_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_78 > 42)
  {
    acc = ((acc + (residue_78 * 2)) + 5) & 127;
    aux ^= residue_78 & 15;
  }
  else
  {
    acc = ((acc - residue_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000124_2413_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000124_2413_3 st_1 = {0};
  struct AudioFrame_R000124_2413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int delta_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_24_1)
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

  switch (delta_24_2)
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

  int metric_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_53_1) & 63;
  aux_2 = (aux_2 + metric_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_39_1 > 36)
  {
    acc_1 = ((acc_1 + (tracker_39_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_39_2 > 36)
  {
    acc_2 = ((acc_2 + (tracker_39_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_24_1 == delta_24_2);
  assert(metric_53_1 == metric_53_2);
  assert(tracker_39_1 == tracker_39_2);
}

int fn_R000124_2413_1(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000124_2413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int delta_24 = (aux + st.buffer[1]) & 3;
  switch (delta_24)
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

  int metric_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_53) & 63;
  acc ^= aux;
  int tracker_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_39 > 36)
  {
    acc = ((acc + (tracker_39 * 2)) + 5) & 127;
    aux ^= tracker_39 & 15;
  }
  else
  {
    acc = ((acc - tracker_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000124_2413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000124_2413_3 st_1 = {0};
  struct AudioFrame_R000124_2413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int damping_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_44_1 > 20)
  {
    acc_1 = ((acc_1 + (damping_44_1 * 2)) + 5) & 127;
    aux_1 ^= damping_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_44_2 > 20)
  {
    acc_2 = ((acc_2 + (damping_44_2 * 2)) + 5) & 127;
    aux_2 ^= damping_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_14_1 = local_arr_1[aux_1 % 3];
  int pivot_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_14_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_44_1 == damping_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_14_1 == pivot_14_2);
}

int fn_R000124_2413_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000124_2413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int damping_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_44 > 20)
  {
    acc = ((acc + (damping_44 * 2)) + 5) & 127;
    aux ^= damping_44 & 15;
  }
  else
  {
    acc = ((acc - damping_44) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int pivot_14 = local_arr[aux % 3];
  acc = (acc + (pivot_14 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000124_2413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000124_2413_0 st_1 = {0};
  struct Vector3D_R000124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int parity_80_1 = 0;
  int parity_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_80_1 = ((parity_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_80_2 = ((parity_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_80_1) & 127;
    acc_2 = (acc_2 + parity_80_2) & 127;
  }

  int coefficient_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_14_1)
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

  switch (coefficient_14_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_80_1 == parity_80_2);
  assert(coefficient_14_1 == coefficient_14_2);
}

int fn_R000124_2413_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int parity_80 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_80 = ((parity_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_80) & 127;
  }

  int coefficient_14 = (aux + st.buffer[1]) & 3;
  switch (coefficient_14)
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

void fn_R000124_2413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000124_2413_2 st_1 = {0};
  struct SensorNode_R000124_2413_2 st_2 = {0};
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
  int scale_32_1 = 0;
  int scale_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_32_1 = ((scale_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_32_2 = ((scale_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_32_1) & 127;
    acc_2 = (acc_2 + scale_32_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_32_1 == scale_32_2);
}

int fn_R000124_2413_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000124_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_32 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_32 = ((scale_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_32) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000124_2413_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000124_2413_0 st_1 = {0};
  struct Vector3D_R000124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_71_1 > 36)
  {
    acc_1 = ((acc_1 + (delta_71_1 * 2)) + 5) & 127;
    aux_1 ^= delta_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_71_2 > 36)
  {
    acc_2 = ((acc_2 + (delta_71_2 * 2)) + 5) & 127;
    aux_2 ^= delta_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_49_1 = local_arr_1[aux_1 % 3];
  int threshold_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_49_2 * 2)) & 127;
  int coefficient_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_87_1)
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

  switch (coefficient_87_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_71_1 == delta_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_49_1 == threshold_49_2);
  assert(coefficient_87_1 == coefficient_87_2);
}

int fn_R000124_2413_5(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_71 > 36)
  {
    acc = ((acc + (delta_71 * 2)) + 5) & 127;
    aux ^= delta_71 & 15;
  }
  else
  {
    acc = ((acc - delta_71) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_49 = local_arr[aux % 3];
  acc = (acc + (threshold_49 * 2)) & 127;
  int coefficient_87 = (aux + st.buffer[1]) & 3;
  switch (coefficient_87)
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

void fn_R000124_2413_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000124_2413_1 st_1 = {0};
  struct StreamBuffer_R000124_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int checksum_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_96_1)
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

  switch (checksum_96_2)
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

  int residue_16_1 = 0;
  int residue_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_16_1 = ((residue_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_16_2 = ((residue_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_16_1) & 127;
    acc_2 = (acc_2 + residue_16_2) & 127;
  }

  int coefficient_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_40_1 > 21)
  {
    acc_1 = ((acc_1 + (coefficient_40_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_40_2 > 21)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_96_1 == checksum_96_2);
  assert(residue_16_1 == residue_16_2);
  assert(coefficient_40_1 == coefficient_40_2);
}

int fn_R000124_2413_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000124_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int checksum_96 = (aux + st.buffer[1]) & 3;
  switch (checksum_96)
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

  int residue_16 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_16 = ((residue_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_16) & 127;
  }

  int coefficient_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_40 > 21)
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

void fn_R000124_2413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000124_2413_2 st_1 = {0};
  struct SensorNode_R000124_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int cursor_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_57_1)
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

  switch (cursor_57_2)
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

  int residue_94_1 = 0;
  int residue_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_94_1 = ((residue_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_94_2 = ((residue_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_94_1) & 127;
    acc_2 = (acc_2 + residue_94_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_57_1 == cursor_57_2);
  assert(residue_94_1 == residue_94_2);
}

int fn_R000124_2413_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000124_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int cursor_57 = (aux + st.buffer[1]) & 3;
  switch (cursor_57)
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

  int residue_94 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_94 = ((residue_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_94) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000124_2413_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000124_2413_1 st_1 = {0};
  struct StreamBuffer_R000124_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int quantum_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_68_1) & 63;
  aux_2 = (aux_2 + quantum_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_27_1 > 38)
  {
    acc_1 = ((acc_1 + (parity_27_1 * 2)) + 5) & 127;
    aux_1 ^= parity_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_27_2 > 38)
  {
    acc_2 = ((acc_2 + (parity_27_2 * 2)) + 5) & 127;
    aux_2 ^= parity_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_42_1 = local_arr_1[aux_1 % 3];
  int offset_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_42_2 * 2)) & 127;
  int sample_36_1 = 0;
  int sample_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_36_1 = ((sample_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_36_2 = ((sample_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_36_1) & 127;
    acc_2 = (acc_2 + sample_36_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_68_1 == quantum_68_2);
  assert(parity_27_1 == parity_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_42_1 == offset_42_2);
  assert(sample_36_1 == sample_36_2);
}

int fn_R000124_2413_8(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000124_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int quantum_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_68) & 63;
  acc ^= aux;
  int parity_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_27 > 38)
  {
    acc = ((acc + (parity_27 * 2)) + 5) & 127;
    aux ^= parity_27 & 15;
  }
  else
  {
    acc = ((acc - parity_27) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_42 = local_arr[aux % 3];
  acc = (acc + (offset_42 * 2)) & 127;
  int sample_36 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_36 = ((sample_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_36) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000124_2413_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000124_2413_0 st_1 = {0};
  struct Vector3D_R000124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int coefficient_59_1 = 0;
  int coefficient_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_59_1 = ((coefficient_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_59_2 = ((coefficient_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_59_1) & 127;
    acc_2 = (acc_2 + coefficient_59_2) & 127;
  }

  int factor_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_63_1) & 63;
  aux_2 = (aux_2 + factor_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_59_1 == coefficient_59_2);
  assert(factor_63_1 == factor_63_2);
}

int fn_R000124_2413_9(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int coefficient_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_59 = ((coefficient_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_59) & 127;
  }

  int factor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_63) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000124_2413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000124_2413_2 st_1 = {0};
  struct SensorNode_R000124_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int factor_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_66_1)
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

  switch (factor_66_2)
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
  int anchor_21_1 = local_arr_1[aux_1 % 3];
  int anchor_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_66_1 == factor_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_21_1 == anchor_21_2);
}

int fn_R000124_2413_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000124_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int factor_66 = (aux + st.buffer[1]) & 3;
  switch (factor_66)
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
  int anchor_21 = local_arr[aux % 3];
  acc = (acc + (anchor_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000124_2413_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000124_2413_0 st_1 = {0};
  struct Vector3D_R000124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int coefficient_49_1 = 0;
  int coefficient_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_49_1 = ((coefficient_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_49_2 = ((coefficient_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_49_1) & 127;
    acc_2 = (acc_2 + coefficient_49_2) & 127;
  }

  int coefficient_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_65_1) & 63;
  aux_2 = (aux_2 + coefficient_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_49_1 == coefficient_49_2);
  assert(coefficient_65_1 == coefficient_65_2);
}

int fn_R000124_2413_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int coefficient_49 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_49 = ((coefficient_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_49) & 127;
  }

  int coefficient_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_65) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000124_2413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000124_2413_3 st_1 = {0};
  struct AudioFrame_R000124_2413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int index_reg_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_26_1)
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

  switch (index_reg_26_2)
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

  int stride_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_19_1) & 63;
  aux_2 = (aux_2 + stride_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_26_1 == index_reg_26_2);
  assert(stride_19_1 == stride_19_2);
}

int fn_R000124_2413_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000124_2413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int index_reg_26 = (aux + st.buffer[1]) & 3;
  switch (index_reg_26)
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

  int stride_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_19) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000124_2413_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000124_2413_0 st_1 = {0};
  struct Vector3D_R000124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quotient_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_71_1 > 20)
  {
    acc_1 = ((acc_1 + (quotient_71_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_71_2 > 20)
  {
    acc_2 = ((acc_2 + (quotient_71_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_52_1)
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

  switch (threshold_52_2)
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
  int checksum_30_1 = local_arr_1[aux_1 % 3];
  int checksum_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_30_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_71_1 == quotient_71_2);
  assert(threshold_52_1 == threshold_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_30_1 == checksum_30_2);
}

int fn_R000124_2413_13(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quotient_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_71 > 20)
  {
    acc = ((acc + (quotient_71 * 2)) + 5) & 127;
    aux ^= quotient_71 & 15;
  }
  else
  {
    acc = ((acc - quotient_71) + 11) & 127;
    aux += 3;
  }
  int threshold_52 = (aux + st.buffer[1]) & 3;
  switch (threshold_52)
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
  int checksum_30 = local_arr[aux % 3];
  acc = (acc + (checksum_30 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000124_2413_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000124_2413_2 st_1 = {0};
  struct SensorNode_R000124_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_92_1)
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

  switch (stride_92_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_92_1 == stride_92_2);
}

int fn_R000124_2413_14(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000124_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_92 = (aux + st.buffer[1]) & 3;
  switch (stride_92)
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

void fn_R000124_2413_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000124_2413_2 st_1 = {0};
  struct SensorNode_R000124_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int quotient_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_61_1)
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

  switch (quotient_61_2)
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

  int tracker_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_19_1 > 50)
  {
    acc_1 = ((acc_1 + (tracker_19_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_19_2 > 50)
  {
    acc_2 = ((acc_2 + (tracker_19_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_68_1 = 0;
  int scale_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_68_1 = ((scale_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_68_2 = ((scale_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_68_1) & 127;
    acc_2 = (acc_2 + scale_68_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_31_1 = local_arr_1[aux_1 % 3];
  int offset_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_61_1 == quotient_61_2);
  assert(tracker_19_1 == tracker_19_2);
  assert(scale_68_1 == scale_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_31_1 == offset_31_2);
}

int fn_R000124_2413_15(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000124_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int quotient_61 = (aux + st.buffer[1]) & 3;
  switch (quotient_61)
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

  int tracker_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_19 > 50)
  {
    acc = ((acc + (tracker_19 * 2)) + 5) & 127;
    aux ^= tracker_19 & 15;
  }
  else
  {
    acc = ((acc - tracker_19) + 11) & 127;
    aux += 3;
  }
  int scale_68 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_68 = ((scale_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_68) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int offset_31 = local_arr[aux % 3];
  acc = (acc + (offset_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000124_2413_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000124_2413_0 st_1 = {0};
  struct Vector3D_R000124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int tally_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_59_1)
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

  switch (tally_59_2)
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

  int quantum_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_43_1 > 45)
  {
    acc_1 = ((acc_1 + (quantum_43_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_43_2 > 45)
  {
    acc_2 = ((acc_2 + (quantum_43_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_42_1 = 0;
  int metric_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_42_1 = ((metric_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_42_2 = ((metric_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_42_1) & 127;
    acc_2 = (acc_2 + metric_42_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_59_1 == tally_59_2);
  assert(quantum_43_1 == quantum_43_2);
  assert(metric_42_1 == metric_42_2);
}

int fn_R000124_2413_16(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int tally_59 = (aux + st.buffer[1]) & 3;
  switch (tally_59)
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

  int quantum_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_43 > 45)
  {
    acc = ((acc + (quantum_43 * 2)) + 5) & 127;
    aux ^= quantum_43 & 15;
  }
  else
  {
    acc = ((acc - quantum_43) + 11) & 127;
    aux += 3;
  }
  int metric_42 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_42 = ((metric_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_42) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000124_2413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000124_2413_1 st_1 = {0};
  struct StreamBuffer_R000124_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_52_1 = local_arr_1[aux_1 % 3];
  int damping_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_52_2 * 2)) & 127;
  int threshold_65_1 = 0;
  int threshold_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_65_1 = ((threshold_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_65_2 = ((threshold_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_65_1) & 127;
    acc_2 = (acc_2 + threshold_65_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_52_1 == damping_52_2);
  assert(threshold_65_1 == threshold_65_2);
}

int fn_R000124_2413_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000124_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_52 = local_arr[aux % 3];
  acc = (acc + (damping_52 * 2)) & 127;
  int threshold_65 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_65 = ((threshold_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_65) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000124_2413_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000124_2413_1 st_1 = {0};
  struct StreamBuffer_R000124_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_36_1 > 34)
  {
    acc_1 = ((acc_1 + (delta_36_1 * 2)) + 5) & 127;
    aux_1 ^= delta_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_36_2 > 34)
  {
    acc_2 = ((acc_2 + (delta_36_2 * 2)) + 5) & 127;
    aux_2 ^= delta_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_26_1 = 0;
  int accumulator_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_26_1 = ((accumulator_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_26_2 = ((accumulator_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_26_1) & 127;
    acc_2 = (acc_2 + accumulator_26_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_36_1 == delta_36_2);
  assert(accumulator_26_1 == accumulator_26_2);
}

int fn_R000124_2413_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000124_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_36 > 34)
  {
    acc = ((acc + (delta_36 * 2)) + 5) & 127;
    aux ^= delta_36 & 15;
  }
  else
  {
    acc = ((acc - delta_36) + 11) & 127;
    aux += 3;
  }
  int accumulator_26 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_26 = ((accumulator_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_26) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r000124_0_1;
  int sec_r000124_0_2;
  int sec_r000124_1_1;
  int sec_r000124_1_2;
  int sec_r000124_2_1;
  int sec_r000124_2_2;
  int sec_r000124_3_1;
  int sec_r000124_3_2;
  int sec_r000124_4_1;
  int sec_r000124_4_2;
  int sec_r000124_5_1;
  int sec_r000124_5_2;
  int sec_r000124_6_1;
  int sec_r000124_6_2;
  int sec_r000124_7_1;
  int sec_r000124_7_2;
  int sec_r000124_8_1;
  int sec_r000124_8_2;
  int sec_r000124_9_1;
  int sec_r000124_9_2;
  int sec_r000124_10_1;
  int sec_r000124_10_2;
  int sec_r000124_11_1;
  int sec_r000124_11_2;
  int sec_r000124_12_1;
  int sec_r000124_12_2;
  int sec_r000124_13_1;
  int sec_r000124_13_2;
  int sec_r000124_14_1;
  int sec_r000124_14_2;
  int sec_r000124_15_1;
  int sec_r000124_15_2;
  int sec_r000124_16_1;
  int sec_r000124_16_2;
  int sec_r000124_17_1;
  int sec_r000124_17_2;
  int sec_r000124_18_1;
  int sec_r000124_18_2;
  int sec_r000124_19_1;
  int sec_r000124_19_2;
  int pub_r000124_0_1;
  int pub_r000124_0_2;
  int pub_r000124_1_1;
  int pub_r000124_1_2;
  int pub_r000124_2_1;
  int pub_r000124_2_2;
  int pub_r000124_3_1;
  int pub_r000124_3_2;
  int pub_r000124_4_1;
  int pub_r000124_4_2;
  int pub_r000124_5_1;
  int pub_r000124_5_2;
  int pub_r000124_6_1;
  int pub_r000124_6_2;
  int pub_r000124_7_1;
  int pub_r000124_7_2;
  int pub_r000124_8_1;
  int pub_r000124_8_2;
  int pub_r000124_9_1;
  int pub_r000124_9_2;
  int pub_r000124_10_1;
  int pub_r000124_10_2;
  int pub_r000124_11_1;
  int pub_r000124_11_2;
  int pub_r000124_12_1;
  int pub_r000124_12_2;
  int pub_r000124_13_1;
  int pub_r000124_13_2;
  int pub_r000124_14_1;
  int pub_r000124_14_2;
  int pub_r000124_15_1;
  int pub_r000124_15_2;
  int pub_r000124_16_1;
  int pub_r000124_16_2;
  int pub_r000124_17_1;
  int pub_r000124_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000124_0_1 >= (-100)) && (pub_r000124_0_1 <= 100));
  __CPROVER_assume((pub_r000124_0_2 >= (-100)) && (pub_r000124_0_2 <= 100));
  __CPROVER_assume((pub_r000124_1_1 >= (-100)) && (pub_r000124_1_1 <= 100));
  __CPROVER_assume((pub_r000124_1_2 >= (-100)) && (pub_r000124_1_2 <= 100));
  __CPROVER_assume((pub_r000124_2_1 >= (-100)) && (pub_r000124_2_1 <= 100));
  __CPROVER_assume((pub_r000124_2_2 >= (-100)) && (pub_r000124_2_2 <= 100));
  __CPROVER_assume((pub_r000124_3_1 >= (-100)) && (pub_r000124_3_1 <= 100));
  __CPROVER_assume((pub_r000124_3_2 >= (-100)) && (pub_r000124_3_2 <= 100));
  __CPROVER_assume((pub_r000124_4_1 >= (-100)) && (pub_r000124_4_1 <= 100));
  __CPROVER_assume((pub_r000124_4_2 >= (-100)) && (pub_r000124_4_2 <= 100));
  __CPROVER_assume((pub_r000124_5_1 >= (-100)) && (pub_r000124_5_1 <= 100));
  __CPROVER_assume((pub_r000124_5_2 >= (-100)) && (pub_r000124_5_2 <= 100));
  __CPROVER_assume((pub_r000124_6_1 >= (-100)) && (pub_r000124_6_1 <= 100));
  __CPROVER_assume((pub_r000124_6_2 >= (-100)) && (pub_r000124_6_2 <= 100));
  __CPROVER_assume((pub_r000124_7_1 >= (-100)) && (pub_r000124_7_1 <= 100));
  __CPROVER_assume((pub_r000124_7_2 >= (-100)) && (pub_r000124_7_2 <= 100));
  __CPROVER_assume((pub_r000124_8_1 >= (-100)) && (pub_r000124_8_1 <= 100));
  __CPROVER_assume((pub_r000124_8_2 >= (-100)) && (pub_r000124_8_2 <= 100));
  __CPROVER_assume((pub_r000124_9_1 >= (-100)) && (pub_r000124_9_1 <= 100));
  __CPROVER_assume((pub_r000124_9_2 >= (-100)) && (pub_r000124_9_2 <= 100));
  __CPROVER_assume((pub_r000124_10_1 >= (-100)) && (pub_r000124_10_1 <= 100));
  __CPROVER_assume((pub_r000124_10_2 >= (-100)) && (pub_r000124_10_2 <= 100));
  __CPROVER_assume((pub_r000124_11_1 >= (-100)) && (pub_r000124_11_1 <= 100));
  __CPROVER_assume((pub_r000124_11_2 >= (-100)) && (pub_r000124_11_2 <= 100));
  __CPROVER_assume((pub_r000124_12_1 >= (-100)) && (pub_r000124_12_1 <= 100));
  __CPROVER_assume((pub_r000124_12_2 >= (-100)) && (pub_r000124_12_2 <= 100));
  __CPROVER_assume((pub_r000124_13_1 >= (-100)) && (pub_r000124_13_1 <= 100));
  __CPROVER_assume((pub_r000124_13_2 >= (-100)) && (pub_r000124_13_2 <= 100));
  __CPROVER_assume((pub_r000124_14_1 >= (-100)) && (pub_r000124_14_1 <= 100));
  __CPROVER_assume((pub_r000124_14_2 >= (-100)) && (pub_r000124_14_2 <= 100));
  __CPROVER_assume((pub_r000124_15_1 >= (-100)) && (pub_r000124_15_1 <= 100));
  __CPROVER_assume((pub_r000124_15_2 >= (-100)) && (pub_r000124_15_2 <= 100));
  __CPROVER_assume((pub_r000124_16_1 >= (-100)) && (pub_r000124_16_1 <= 100));
  __CPROVER_assume((pub_r000124_16_2 >= (-100)) && (pub_r000124_16_2 <= 100));
  __CPROVER_assume((pub_r000124_17_1 >= (-100)) && (pub_r000124_17_1 <= 100));
  __CPROVER_assume((pub_r000124_17_2 >= (-100)) && (pub_r000124_17_2 <= 100));
  __CPROVER_assume((sec_r000124_0_1 >= 0) && (sec_r000124_0_1 <= 255));
  __CPROVER_assume((sec_r000124_0_2 >= 0) && (sec_r000124_0_2 <= 255));
  __CPROVER_assume((sec_r000124_1_1 >= 0) && (sec_r000124_1_1 <= 255));
  __CPROVER_assume((sec_r000124_1_2 >= 0) && (sec_r000124_1_2 <= 255));
  __CPROVER_assume((sec_r000124_2_1 >= 0) && (sec_r000124_2_1 <= 255));
  __CPROVER_assume((sec_r000124_2_2 >= 0) && (sec_r000124_2_2 <= 255));
  __CPROVER_assume((sec_r000124_3_1 >= 0) && (sec_r000124_3_1 <= 255));
  __CPROVER_assume((sec_r000124_3_2 >= 0) && (sec_r000124_3_2 <= 255));
  __CPROVER_assume((sec_r000124_4_1 >= 0) && (sec_r000124_4_1 <= 255));
  __CPROVER_assume((sec_r000124_4_2 >= 0) && (sec_r000124_4_2 <= 255));
  __CPROVER_assume((sec_r000124_5_1 >= 0) && (sec_r000124_5_1 <= 255));
  __CPROVER_assume((sec_r000124_5_2 >= 0) && (sec_r000124_5_2 <= 255));
  __CPROVER_assume((sec_r000124_6_1 >= 0) && (sec_r000124_6_1 <= 255));
  __CPROVER_assume((sec_r000124_6_2 >= 0) && (sec_r000124_6_2 <= 255));
  __CPROVER_assume((sec_r000124_7_1 >= 0) && (sec_r000124_7_1 <= 255));
  __CPROVER_assume((sec_r000124_7_2 >= 0) && (sec_r000124_7_2 <= 255));
  __CPROVER_assume((sec_r000124_8_1 >= 0) && (sec_r000124_8_1 <= 255));
  __CPROVER_assume((sec_r000124_8_2 >= 0) && (sec_r000124_8_2 <= 255));
  __CPROVER_assume((sec_r000124_9_1 >= 0) && (sec_r000124_9_1 <= 255));
  __CPROVER_assume((sec_r000124_9_2 >= 0) && (sec_r000124_9_2 <= 255));
  __CPROVER_assume((sec_r000124_10_1 >= 0) && (sec_r000124_10_1 <= 255));
  __CPROVER_assume((sec_r000124_10_2 >= 0) && (sec_r000124_10_2 <= 255));
  __CPROVER_assume((sec_r000124_11_1 >= 0) && (sec_r000124_11_1 <= 255));
  __CPROVER_assume((sec_r000124_11_2 >= 0) && (sec_r000124_11_2 <= 255));
  __CPROVER_assume((sec_r000124_12_1 >= 0) && (sec_r000124_12_1 <= 255));
  __CPROVER_assume((sec_r000124_12_2 >= 0) && (sec_r000124_12_2 <= 255));
  __CPROVER_assume((sec_r000124_13_1 >= 0) && (sec_r000124_13_1 <= 255));
  __CPROVER_assume((sec_r000124_13_2 >= 0) && (sec_r000124_13_2 <= 255));
  __CPROVER_assume((sec_r000124_14_1 >= 0) && (sec_r000124_14_1 <= 255));
  __CPROVER_assume((sec_r000124_14_2 >= 0) && (sec_r000124_14_2 <= 255));
  __CPROVER_assume((sec_r000124_15_1 >= 0) && (sec_r000124_15_1 <= 255));
  __CPROVER_assume((sec_r000124_15_2 >= 0) && (sec_r000124_15_2 <= 255));
  __CPROVER_assume((sec_r000124_16_1 >= 0) && (sec_r000124_16_1 <= 255));
  __CPROVER_assume((sec_r000124_16_2 >= 0) && (sec_r000124_16_2 <= 255));
  __CPROVER_assume((sec_r000124_17_1 >= 0) && (sec_r000124_17_1 <= 255));
  __CPROVER_assume((sec_r000124_17_2 >= 0) && (sec_r000124_17_2 <= 255));
  __CPROVER_assume((sec_r000124_18_1 >= 0) && (sec_r000124_18_1 <= 255));
  __CPROVER_assume((sec_r000124_18_2 >= 0) && (sec_r000124_18_2 <= 255));
  __CPROVER_assume((sec_r000124_19_1 >= 0) && (sec_r000124_19_1 <= 255));
  __CPROVER_assume((sec_r000124_19_2 >= 0) && (sec_r000124_19_2 <= 255));
  struct Vector3D_R000124_2413_0 st_var_0_1 = {0};
  struct Vector3D_R000124_2413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000124_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000124_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000124_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000124_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000124_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000124_0_2 + 7) & 15;
  struct StreamBuffer_R000124_2413_1 st_var_1_1 = {0};
  struct StreamBuffer_R000124_2413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000124_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000124_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000124_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000124_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000124_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000124_0_2 + 9) & 15;
  struct SensorNode_R000124_2413_2 st_var_2_1 = {0};
  struct SensorNode_R000124_2413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000124_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000124_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000124_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000124_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000124_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000124_0_2 + 11) & 15;
  struct AudioFrame_R000124_2413_3 st_var_3_1 = {0};
  struct AudioFrame_R000124_2413_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000124_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000124_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000124_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000124_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000124_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000124_0_2 + 13) & 15;
  union TelemetryField_R000124_2413_0 u_var_1;
  union TelemetryField_R000124_2413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 1) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 1) & 15;
  int stage_v_0_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_0_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= stage_v_0_1;
  chk_sum_2 ^= stage_v_0_2;
  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 4) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_3_2.buffer[0] * 3) & 63;
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
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 7) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 10) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 26)
    {
      chk_sum_1 ^= stage_v_13_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_13_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 26)
    {
      chk_sum_2 ^= stage_v_13_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 16) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_18_1 = ((st_var_2_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_2_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 38)
    {
      chk_sum_1 ^= stage_v_18_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_18_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 38)
    {
      chk_sum_2 ^= stage_v_18_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = ((st_var_1_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_1_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 55)
    {
      chk_sum_1 ^= stage_v_21_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_21_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 55)
    {
      chk_sum_2 ^= stage_v_21_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  int stage_v_23_1 = ((st_var_3_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_3_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 50)
    {
      chk_sum_1 ^= stage_v_23_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_23_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 50)
    {
      chk_sum_2 ^= stage_v_23_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 25) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 25) & 15;
  int stage_v_24_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_24_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= stage_v_24_1;
  chk_sum_2 ^= stage_v_24_2;
  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 32)
    {
      chk_sum_1 ^= stage_v_25_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_25_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 32)
    {
      chk_sum_2 ^= stage_v_25_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_26_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_26_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((st_var_0_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_0_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 42)
    {
      chk_sum_1 ^= stage_v_28_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_28_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 42)
    {
      chk_sum_2 ^= stage_v_28_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 30) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 30) & 15;
  int stage_v_29_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_29_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= stage_v_29_1;
  chk_sum_2 ^= stage_v_29_2;
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 32) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= stage_v_31_1;
  chk_sum_2 ^= stage_v_31_2;
  int stage_v_32_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_32_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_32_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_32_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 34) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 36) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= stage_v_35_1;
  chk_sum_2 ^= stage_v_35_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 37) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 37) & 15;
  int stage_v_36_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_36_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= stage_v_36_1;
  chk_sum_2 ^= stage_v_36_2;
  int stage_v_37_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_37_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_38_1 = (st_var_2_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_2_2.buffer[0] ^ 41) & 3;
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

  int stage_v_39_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (44 & 31);
  int stage_v_39_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (44 & 31);
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= (stage_v_39_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_39_2 << 1) & 127;
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (st_var_1_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_1_2.buffer[0] ^ 44) & 3;
  switch (stage_v_41_1)
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

  switch (stage_v_41_2)
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

  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_43_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_43_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_43_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = table_1[1];
  int stage_v_45_2 = table_2[1];
  table_1[1] = (table_1[2] + 91) & 63;
  table_2[1] = (table_2[2] + 91) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  int stage_v_47_1 = table_1[3];
  int stage_v_47_2 = table_2[3];
  table_1[3] = (table_1[0] + 95) & 63;
  table_2[3] = (table_2[0] + 95) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_49_1 = ((stage_v_49_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (55 & 31);
  int stage_v_50_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (55 & 31);
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= (stage_v_50_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_50_2 << 1) & 127;
  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (57 & 31);
  int stage_v_52_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (57 & 31);
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= (stage_v_52_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_52_2 << 1) & 127;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (59 & 31);
  int stage_v_54_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (59 & 31);
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= (stage_v_54_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_54_2 << 1) & 127;
  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((st_var_0_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_0_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 30)
    {
      chk_sum_1 ^= stage_v_56_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_56_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 30)
    {
      chk_sum_2 ^= stage_v_56_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_57_1 = (st_var_1_1.buffer[0] ^ 60) & 3;
  int stage_v_57_2 = (st_var_1_2.buffer[0] ^ 60) & 3;
  switch (stage_v_57_1)
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

  switch (stage_v_57_2)
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

  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = ((st_var_3_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_3_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 50)
    {
      chk_sum_1 ^= stage_v_59_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_59_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 50)
    {
      chk_sum_2 ^= stage_v_59_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_60_1 = ((stage_v_60_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_60_2 = ((stage_v_60_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_61_1 = ((stage_v_61_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_61_2 = ((stage_v_61_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (st_var_2_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_2_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = table_1[3];
  int stage_v_63_2 = table_2[3];
  table_1[3] = (table_1[0] + 127) & 63;
  table_2[3] = (table_2[0] + 127) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = table_1[0];
  int stage_v_64_2 = table_2[0];
  table_1[0] = (table_1[1] + 129) & 63;
  table_2[0] = (table_2[1] + 129) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 66) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 66) & 15;
  int stage_v_65_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_65_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= stage_v_65_1;
  chk_sum_2 ^= stage_v_65_2;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = table_1[3];
  int stage_v_67_2 = table_2[3];
  table_1[3] = (table_1[0] + 135) & 63;
  table_2[3] = (table_2[0] + 135) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((st_var_0_1.buffer[2] * 2) + 211) & 63;
  int stage_v_68_2 = ((st_var_0_2.buffer[2] * 2) + 211) & 63;
  if (stage_v_68_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_68_1) - 5) & 255;
    if (stage_v_68_1 > 34)
    {
      chk_sum_1 ^= stage_v_68_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_68_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_68_2) - 5) & 255;
    if (stage_v_68_2 > 34)
    {
      chk_sum_2 ^= stage_v_68_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_69_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (74 & 31);
  int stage_v_69_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (74 & 31);
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= (stage_v_69_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_69_2 << 1) & 127;
  int stage_v_70_1 = (st_var_2_1.buffer[0] ^ 73) & 3;
  int stage_v_70_2 = (st_var_2_2.buffer[0] ^ 73) & 3;
  switch (stage_v_70_1)
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

  switch (stage_v_70_2)
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

  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 72) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 72) & 15;
  int stage_v_71_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_71_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= stage_v_71_1;
  chk_sum_2 ^= stage_v_71_2;
  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 47)
    {
      chk_sum_1 ^= stage_v_72_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_72_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 47)
    {
      chk_sum_2 ^= stage_v_72_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_73_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (78 & 31);
  int stage_v_73_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (78 & 31);
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= (stage_v_73_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_73_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 75) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 75) & 15;
  int stage_v_74_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_74_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  chk_sum_1 ^= stage_v_74_1;
  chk_sum_2 ^= stage_v_74_2;
  int stage_v_75_1 = table_1[3];
  int stage_v_75_2 = table_2[3];
  table_1[3] = (table_1[0] + 151) & 63;
  table_2[3] = (table_2[0] + 151) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 77) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 77) & 15;
  int stage_v_76_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_76_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= stage_v_76_1;
  chk_sum_2 ^= stage_v_76_2;
  int stage_v_77_1 = ((st_var_1_1.buffer[2] * 2) + 238) & 63;
  int stage_v_77_2 = ((st_var_1_2.buffer[2] * 2) + 238) & 63;
  if (stage_v_77_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_77_1) - 5) & 255;
    if (stage_v_77_1 > 47)
    {
      chk_sum_1 ^= stage_v_77_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_77_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_77_2) - 5) & 255;
    if (stage_v_77_2 > 47)
    {
      chk_sum_2 ^= stage_v_77_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_78_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (83 & 31);
  int stage_v_78_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (83 & 31);
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= (stage_v_78_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_78_2 << 1) & 127;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (85 & 31);
  int stage_v_80_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (85 & 31);
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= (stage_v_80_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_80_2 << 1) & 127;
  int stage_v_81_1 = ((st_var_1_1.buffer[0] * 2) + 250) & 63;
  int stage_v_81_2 = ((st_var_1_2.buffer[0] * 2) + 250) & 63;
  if (stage_v_81_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_81_1) - 5) & 255;
    if (stage_v_81_1 > 40)
    {
      chk_sum_1 ^= stage_v_81_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_81_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_81_2) - 5) & 255;
    if (stage_v_81_2 > 40)
    {
      chk_sum_2 ^= stage_v_81_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = table_1[3];
  int stage_v_83_2 = table_2[3];
  table_1[3] = (table_1[0] + 167) & 63;
  table_2[3] = (table_2[0] + 167) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (st_var_0_1.buffer[0] ^ 87) & 3;
  int stage_v_84_2 = (st_var_0_2.buffer[0] ^ 87) & 3;
  switch (stage_v_84_1)
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

  switch (stage_v_84_2)
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

  int stage_v_85_1 = table_1[1];
  int stage_v_85_2 = table_2[1];
  table_1[1] = (table_1[2] + 171) & 63;
  table_2[1] = (table_2[2] + 171) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 87) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 87) & 15;
  int stage_v_86_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_86_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= stage_v_86_1;
  chk_sum_2 ^= stage_v_86_2;
  int stage_v_87_1 = ((st_var_3_1.buffer[0] * 2) + 268) & 63;
  int stage_v_87_2 = ((st_var_3_2.buffer[0] * 2) + 268) & 63;
  if (stage_v_87_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_87_1) - 5) & 255;
    if (stage_v_87_1 > 46)
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
  if (stage_v_87_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_87_2) - 5) & 255;
    if (stage_v_87_2 > 46)
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
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 89) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 89) & 15;
  int stage_v_88_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_88_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= stage_v_88_1;
  chk_sum_2 ^= stage_v_88_2;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_89_1 = ((stage_v_89_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_89_2 = ((stage_v_89_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((st_var_2_1.buffer[0] * 2) + 277) & 63;
  int stage_v_90_2 = ((st_var_2_2.buffer[0] * 2) + 277) & 63;
  if (stage_v_90_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_90_1) - 5) & 255;
    if (stage_v_90_1 > 54)
    {
      chk_sum_1 ^= stage_v_90_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_90_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_90_2) - 5) & 255;
    if (stage_v_90_2 > 54)
    {
      chk_sum_2 ^= stage_v_90_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_91_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (96 & 31);
  int stage_v_91_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (96 & 31);
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  chk_sum_1 ^= (stage_v_91_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_91_2 << 1) & 127;
  int stage_v_92_1 = (st_var_0_1.buffer[0] ^ 95) & 3;
  int stage_v_92_2 = (st_var_0_2.buffer[0] ^ 95) & 3;
  switch (stage_v_92_1)
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

  switch (stage_v_92_2)
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

  int stage_v_93_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (98 & 31);
  int stage_v_93_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (98 & 31);
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  chk_sum_1 ^= (stage_v_93_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_93_2 << 1) & 127;
  int stage_v_94_1 = ((st_var_2_1.buffer[1] * 2) + 289) & 63;
  int stage_v_94_2 = ((st_var_2_2.buffer[1] * 2) + 289) & 63;
  if (stage_v_94_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_94_1) - 5) & 255;
    if (stage_v_94_1 > 36)
    {
      chk_sum_1 ^= stage_v_94_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_94_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_94_2) - 5) & 255;
    if (stage_v_94_2 > 36)
    {
      chk_sum_2 ^= stage_v_94_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_95_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (100 & 31);
  int stage_v_95_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (100 & 31);
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  chk_sum_1 ^= (stage_v_95_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_95_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 97) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 97) & 15;
  int stage_v_96_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_96_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  chk_sum_1 ^= stage_v_96_1;
  chk_sum_2 ^= stage_v_96_2;
  int stage_v_97_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_97_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_97_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_97_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_98_1 = ((st_var_2_1.buffer[2] * 2) + 301) & 63;
  int stage_v_98_2 = ((st_var_2_2.buffer[2] * 2) + 301) & 63;
  if (stage_v_98_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_98_1) - 5) & 255;
    if (stage_v_98_1 > 48)
    {
      chk_sum_1 ^= stage_v_98_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_98_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_98_2) - 5) & 255;
    if (stage_v_98_2 > 48)
    {
      chk_sum_2 ^= stage_v_98_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_99_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_99_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_99_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_99_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 101) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 101) & 15;
  int stage_v_100_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_100_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= stage_v_100_1;
  chk_sum_2 ^= stage_v_100_2;
  int stage_v_101_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_101_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_101_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_101_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_102_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_102_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_102_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_102_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_103_1 = ((stage_v_103_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_103_2 = ((stage_v_103_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_104_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_104_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_104_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 106) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 106) & 15;
  int stage_v_105_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_105_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= stage_v_105_1;
  chk_sum_2 ^= stage_v_105_2;
  int stage_v_106_1 = (st_var_2_1.buffer[0] ^ 109) & 3;
  int stage_v_106_2 = (st_var_2_2.buffer[0] ^ 109) & 3;
  switch (stage_v_106_1)
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

  switch (stage_v_106_2)
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

  int stage_v_107_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_107_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_107_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_107_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_108_1 = table_1[0];
  int stage_v_108_2 = table_2[0];
  table_1[0] = (table_1[1] + 217) & 63;
  table_2[0] = (table_2[1] + 217) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_109_1 = ((stage_v_109_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_109_2 = ((stage_v_109_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((st_var_2_1.buffer[2] * 2) + 337) & 63;
  int stage_v_110_2 = ((st_var_2_2.buffer[2] * 2) + 337) & 63;
  if (stage_v_110_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_110_1) - 5) & 255;
    if (stage_v_110_1 > 34)
    {
      chk_sum_1 ^= stage_v_110_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_110_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_110_2) - 5) & 255;
    if (stage_v_110_2 > 34)
    {
      chk_sum_2 ^= stage_v_110_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_111_1 = table_1[3];
  int stage_v_111_2 = table_2[3];
  table_1[3] = (table_1[0] + 223) & 63;
  table_2[3] = (table_2[0] + 223) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (st_var_0_1.buffer[0] ^ 115) & 3;
  int stage_v_112_2 = (st_var_0_2.buffer[0] ^ 115) & 3;
  switch (stage_v_112_1)
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

  switch (stage_v_112_2)
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

  int stage_v_113_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_113_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_113_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_113_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_114_1 = ((stage_v_114_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_114_2 = ((stage_v_114_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = table_1[3];
  int stage_v_115_2 = table_2[3];
  table_1[3] = (table_1[0] + 231) & 63;
  table_2[3] = (table_2[0] + 231) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (st_var_0_1.buffer[0] ^ 119) & 3;
  int stage_v_116_2 = (st_var_0_2.buffer[0] ^ 119) & 3;
  switch (stage_v_116_1)
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

  switch (stage_v_116_2)
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

  int stage_v_117_1 = ((st_var_1_1.buffer[0] * 2) + 358) & 63;
  int stage_v_117_2 = ((st_var_1_2.buffer[0] * 2) + 358) & 63;
  if (stage_v_117_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_117_1) - 5) & 255;
    if (stage_v_117_1 > 48)
    {
      chk_sum_1 ^= stage_v_117_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_117_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_117_2) - 5) & 255;
    if (stage_v_117_2 > 48)
    {
      chk_sum_2 ^= stage_v_117_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
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
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_120_1 = ((stage_v_120_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_120_2 = ((stage_v_120_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_121_1 = ((stage_v_121_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_121_2 = ((stage_v_121_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (st_var_2_1.buffer[0] ^ 125) & 3;
  int stage_v_122_2 = (st_var_2_2.buffer[0] ^ 125) & 3;
  switch (stage_v_122_1)
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

  switch (stage_v_122_2)
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

  int stage_v_123_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_123_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_123_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_123_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_124_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_124_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_124_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_124_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_125_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_125_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_125_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_125_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_126_1 = ((stage_v_126_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_126_2 = ((stage_v_126_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_127_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_127_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_127_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_128_1 = (st_var_0_1.buffer[0] ^ 131) & 3;
  int stage_v_128_2 = (st_var_0_2.buffer[0] ^ 131) & 3;
  switch (stage_v_128_1)
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

  switch (stage_v_128_2)
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

  int stage_v_129_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_129_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_129_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_129_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_130_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_130_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_130_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_130_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 132) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 132) & 15;
  int stage_v_131_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_131_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  chk_sum_1 ^= stage_v_131_1;
  chk_sum_2 ^= stage_v_131_2;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_132_1 = ((stage_v_132_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_132_2 = ((stage_v_132_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((st_var_1_1.buffer[1] * 2) + 406) & 63;
  int stage_v_133_2 = ((st_var_1_2.buffer[1] * 2) + 406) & 63;
  if (stage_v_133_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_133_1) - 5) & 255;
    if (stage_v_133_1 > 45)
    {
      chk_sum_1 ^= stage_v_133_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_133_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_133_2) - 5) & 255;
    if (stage_v_133_2 > 45)
    {
      chk_sum_2 ^= stage_v_133_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_134_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (139 & 31);
  int stage_v_134_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (139 & 31);
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  chk_sum_1 ^= (stage_v_134_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_134_2 << 1) & 127;
  int stage_v_135_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_135_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_135_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_135_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_136_1 = (st_var_0_1.buffer[0] ^ 139) & 3;
  int stage_v_136_2 = (st_var_0_2.buffer[0] ^ 139) & 3;
  switch (stage_v_136_1)
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

  switch (stage_v_136_2)
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

  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_137_1 = ((stage_v_137_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_137_2 = ((stage_v_137_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_138_1 = ((stage_v_138_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_138_2 = ((stage_v_138_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((st_var_3_1.buffer[1] * 2) + 424) & 63;
  int stage_v_139_2 = ((st_var_3_2.buffer[1] * 2) + 424) & 63;
  if (stage_v_139_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_139_1) - 5) & 255;
    if (stage_v_139_1 > 48)
    {
      chk_sum_1 ^= stage_v_139_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_139_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_139_2) - 5) & 255;
    if (stage_v_139_2 > 48)
    {
      chk_sum_2 ^= stage_v_139_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 141) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 141) & 15;
  int stage_v_140_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_140_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  chk_sum_1 ^= stage_v_140_1;
  chk_sum_2 ^= stage_v_140_2;
  int stage_v_141_1 = (st_var_1_1.buffer[0] ^ 144) & 3;
  int stage_v_141_2 = (st_var_1_2.buffer[0] ^ 144) & 3;
  switch (stage_v_141_1)
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

  switch (stage_v_141_2)
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

  int stage_v_142_1 = table_1[2];
  int stage_v_142_2 = table_2[2];
  table_1[2] = (table_1[3] + 285) & 63;
  table_2[2] = (table_2[3] + 285) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((st_var_0_1.buffer[0] * 2) + 439) & 63;
  int stage_v_144_2 = ((st_var_0_2.buffer[0] * 2) + 439) & 63;
  if (stage_v_144_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_144_1) - 5) & 255;
    if (stage_v_144_1 > 40)
    {
      chk_sum_1 ^= stage_v_144_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_144_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_144_2) - 5) & 255;
    if (stage_v_144_2 > 40)
    {
      chk_sum_2 ^= stage_v_144_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_145_1 = ((stage_v_145_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_145_2 = ((stage_v_145_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (st_var_2_1.buffer[0] ^ 149) & 3;
  int stage_v_146_2 = (st_var_2_2.buffer[0] ^ 149) & 3;
  switch (stage_v_146_1)
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

  switch (stage_v_146_2)
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

  int stage_v_147_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (152 & 31);
  int stage_v_147_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (152 & 31);
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  chk_sum_1 ^= (stage_v_147_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_147_2 << 1) & 127;
  int stage_v_148_1 = (st_var_0_1.buffer[0] ^ 151) & 3;
  int stage_v_148_2 = (st_var_0_2.buffer[0] ^ 151) & 3;
  switch (stage_v_148_1)
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

  switch (stage_v_148_2)
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

  int stage_v_149_1 = table_1[1];
  int stage_v_149_2 = table_2[1];
  table_1[1] = (table_1[2] + 299) & 63;
  table_2[1] = (table_2[2] + 299) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_150_1 = ((stage_v_150_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_150_2 = ((stage_v_150_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_151_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_151_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_151_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_152_1 = ((st_var_0_1.buffer[2] * 2) + 463) & 63;
  int stage_v_152_2 = ((st_var_0_2.buffer[2] * 2) + 463) & 63;
  if (stage_v_152_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_152_1) - 5) & 255;
    if (stage_v_152_1 > 43)
    {
      chk_sum_1 ^= stage_v_152_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_152_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_152_2) - 5) & 255;
    if (stage_v_152_2 > 43)
    {
      chk_sum_2 ^= stage_v_152_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 154) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 154) & 15;
  int stage_v_153_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_153_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  chk_sum_1 ^= stage_v_153_1;
  chk_sum_2 ^= stage_v_153_2;
  int stage_v_154_1 = table_1[2];
  int stage_v_154_2 = table_2[2];
  table_1[2] = (table_1[3] + 309) & 63;
  table_2[2] = (table_2[3] + 309) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_155_1 = ((stage_v_155_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_155_2 = ((stage_v_155_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 157) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 157) & 15;
  int stage_v_156_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_156_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  chk_sum_1 ^= stage_v_156_1;
  chk_sum_2 ^= stage_v_156_2;
  int stage_v_157_1 = (st_var_1_1.buffer[0] ^ 160) & 3;
  int stage_v_157_2 = (st_var_1_2.buffer[0] ^ 160) & 3;
  switch (stage_v_157_1)
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

  switch (stage_v_157_2)
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

  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_158_1 = ((stage_v_158_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_158_2 = ((stage_v_158_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (st_var_3_1.buffer[0] ^ 162) & 3;
  int stage_v_159_2 = (st_var_3_2.buffer[0] ^ 162) & 3;
  switch (stage_v_159_1)
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

  switch (stage_v_159_2)
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

  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_160_1 = ((stage_v_160_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_160_2 = ((stage_v_160_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = table_1[1];
  int stage_v_161_2 = table_2[1];
  table_1[1] = (table_1[2] + 323) & 63;
  table_2[1] = (table_2[2] + 323) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (167 & 31);
  int stage_v_162_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (167 & 31);
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  chk_sum_1 ^= (stage_v_162_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_162_2 << 1) & 127;
  int stage_v_163_1 = (st_var_3_1.buffer[0] ^ 166) & 3;
  int stage_v_163_2 = (st_var_3_2.buffer[0] ^ 166) & 3;
  switch (stage_v_163_1)
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

  switch (stage_v_163_2)
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

  int stage_v_164_1 = ((st_var_0_1.buffer[2] * 2) + 499) & 63;
  int stage_v_164_2 = ((st_var_0_2.buffer[2] * 2) + 499) & 63;
  if (stage_v_164_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_164_1) - 5) & 255;
    if (stage_v_164_1 > 35)
    {
      chk_sum_1 ^= stage_v_164_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_164_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_164_2) - 5) & 255;
    if (stage_v_164_2 > 35)
    {
      chk_sum_2 ^= stage_v_164_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_165_1 = table_1[1];
  int stage_v_165_2 = table_2[1];
  table_1[1] = (table_1[2] + 331) & 63;
  table_2[1] = (table_2[2] + 331) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_166_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_166_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_166_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_167_1 = ((st_var_3_1.buffer[2] * 2) + 508) & 63;
  int stage_v_167_2 = ((st_var_3_2.buffer[2] * 2) + 508) & 63;
  if (stage_v_167_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_167_1) - 5) & 255;
    if (stage_v_167_1 > 47)
    {
      chk_sum_1 ^= stage_v_167_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_167_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_167_2) - 5) & 255;
    if (stage_v_167_2 > 47)
    {
      chk_sum_2 ^= stage_v_167_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_168_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (173 & 31);
  int stage_v_168_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (173 & 31);
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  chk_sum_1 ^= (stage_v_168_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_168_2 << 1) & 127;
  int stage_v_169_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (174 & 31);
  int stage_v_169_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (174 & 31);
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  chk_sum_1 ^= (stage_v_169_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_169_2 << 1) & 127;
  int stage_v_170_1 = (st_var_2_1.buffer[0] ^ 173) & 3;
  int stage_v_170_2 = (st_var_2_2.buffer[0] ^ 173) & 3;
  switch (stage_v_170_1)
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

  switch (stage_v_170_2)
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

  int stage_v_171_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_171_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_171_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_171_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_172_1 = ((st_var_0_1.buffer[1] * 2) + 523) & 63;
  int stage_v_172_2 = ((st_var_0_2.buffer[1] * 2) + 523) & 63;
  if (stage_v_172_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_172_1) - 5) & 255;
    if (stage_v_172_1 > 33)
    {
      chk_sum_1 ^= stage_v_172_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_172_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_172_2) - 5) & 255;
    if (stage_v_172_2 > 33)
    {
      chk_sum_2 ^= stage_v_172_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_173_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_173_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_173_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_173_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_174_1 = 0;
  int stage_v_174_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_174_1 = ((stage_v_174_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_174_2 = ((stage_v_174_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_175_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_175_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_175_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_176_1 = (st_var_0_1.buffer[0] ^ 179) & 3;
  int stage_v_176_2 = (st_var_0_2.buffer[0] ^ 179) & 3;
  switch (stage_v_176_1)
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

  switch (stage_v_176_2)
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

  int stage_v_177_1 = ((st_var_1_1.buffer[0] * 2) + 538) & 63;
  int stage_v_177_2 = ((st_var_1_2.buffer[0] * 2) + 538) & 63;
  if (stage_v_177_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_177_1) - 5) & 255;
    if (stage_v_177_1 > 47)
    {
      chk_sum_1 ^= stage_v_177_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_177_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_177_2) - 5) & 255;
    if (stage_v_177_2 > 47)
    {
      chk_sum_2 ^= stage_v_177_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_178_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_178_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_178_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_178_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_179_1 = 0;
  int stage_v_179_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_179_1 = ((stage_v_179_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_179_2 = ((stage_v_179_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (185 & 31);
  int stage_v_180_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (185 & 31);
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  chk_sum_1 ^= (stage_v_180_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_180_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 182) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 182) & 15;
  int stage_v_181_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_181_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  chk_sum_1 ^= stage_v_181_1;
  chk_sum_2 ^= stage_v_181_2;
  int stage_v_182_1 = 0;
  int stage_v_182_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_182_1 = ((stage_v_182_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_182_2 = ((stage_v_182_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (188 & 31);
  int stage_v_183_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (188 & 31);
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  chk_sum_1 ^= (stage_v_183_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_183_2 << 1) & 127;
  int stage_v_184_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_184_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_184_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_184_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 186) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 186) & 15;
  int stage_v_185_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_185_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  chk_sum_1 ^= stage_v_185_1;
  chk_sum_2 ^= stage_v_185_2;
  int stage_v_186_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (191 & 31);
  int stage_v_186_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (191 & 31);
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  chk_sum_1 ^= (stage_v_186_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_186_2 << 1) & 127;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 188) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 188) & 15;
  int stage_v_187_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_187_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  chk_sum_1 ^= stage_v_187_1;
  chk_sum_2 ^= stage_v_187_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 189) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 189) & 15;
  int stage_v_188_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_188_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  chk_sum_1 ^= stage_v_188_1;
  chk_sum_2 ^= stage_v_188_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 190) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 190) & 15;
  int stage_v_189_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_189_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  chk_sum_1 ^= stage_v_189_1;
  chk_sum_2 ^= stage_v_189_2;
  int stage_v_190_1 = (st_var_2_1.buffer[0] ^ 193) & 3;
  int stage_v_190_2 = (st_var_2_2.buffer[0] ^ 193) & 3;
  switch (stage_v_190_1)
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

  switch (stage_v_190_2)
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

  int stage_v_191_1 = ((st_var_3_1.buffer[2] * 2) + 580) & 63;
  int stage_v_191_2 = ((st_var_3_2.buffer[2] * 2) + 580) & 63;
  if (stage_v_191_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_191_1) - 5) & 255;
    if (stage_v_191_1 > 27)
    {
      chk_sum_1 ^= stage_v_191_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_191_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_191_2) - 5) & 255;
    if (stage_v_191_2 > 27)
    {
      chk_sum_2 ^= stage_v_191_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_192_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (197 & 31);
  int stage_v_192_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (197 & 31);
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  chk_sum_1 ^= (stage_v_192_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_192_2 << 1) & 127;
  int stage_v_193_1 = 0;
  int stage_v_193_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_193_1 = ((stage_v_193_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_193_2 = ((stage_v_193_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (st_var_2_1.buffer[0] ^ 197) & 3;
  int stage_v_194_2 = (st_var_2_2.buffer[0] ^ 197) & 3;
  switch (stage_v_194_1)
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

  switch (stage_v_194_2)
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

  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 196) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 196) & 15;
  int stage_v_195_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_195_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  chk_sum_1 ^= stage_v_195_1;
  chk_sum_2 ^= stage_v_195_2;
  int stage_v_196_1 = ((st_var_0_1.buffer[1] * 2) + 595) & 63;
  int stage_v_196_2 = ((st_var_0_2.buffer[1] * 2) + 595) & 63;
  if (stage_v_196_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_196_1) - 5) & 255;
    if (stage_v_196_1 > 45)
    {
      chk_sum_1 ^= stage_v_196_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_196_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_196_2) - 5) & 255;
    if (stage_v_196_2 > 45)
    {
      chk_sum_2 ^= stage_v_196_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_197_1 = table_1[1];
  int stage_v_197_2 = table_2[1];
  table_1[1] = (table_1[2] + 395) & 63;
  table_2[1] = (table_2[2] + 395) & 63;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 199) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 199) & 15;
  int stage_v_198_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_198_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  chk_sum_1 ^= stage_v_198_1;
  chk_sum_2 ^= stage_v_198_2;
  int stage_v_199_1 = ((st_var_3_1.buffer[1] * 2) + 604) & 63;
  int stage_v_199_2 = ((st_var_3_2.buffer[1] * 2) + 604) & 63;
  if (stage_v_199_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_199_1) - 5) & 255;
    if (stage_v_199_1 > 32)
    {
      chk_sum_1 ^= stage_v_199_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_199_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_199_2) - 5) & 255;
    if (stage_v_199_2 > 32)
    {
      chk_sum_2 ^= stage_v_199_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_200_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (205 & 31);
  int stage_v_200_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (205 & 31);
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  chk_sum_1 ^= (stage_v_200_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_200_2 << 1) & 127;
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
  int stage_v_203_1 = ((st_var_3_1.buffer[2] * 2) + 616) & 63;
  int stage_v_203_2 = ((st_var_3_2.buffer[2] * 2) + 616) & 63;
  if (stage_v_203_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_203_1) - 5) & 255;
    if (stage_v_203_1 > 29)
    {
      chk_sum_1 ^= stage_v_203_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_203_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_203_2) - 5) & 255;
    if (stage_v_203_2 > 29)
    {
      chk_sum_2 ^= stage_v_203_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_204_1 = table_1[0];
  int stage_v_204_2 = table_2[0];
  table_1[0] = (table_1[1] + 409) & 63;
  table_2[0] = (table_2[1] + 409) & 63;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = 0;
  int stage_v_205_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_205_1 = ((stage_v_205_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_205_2 = ((stage_v_205_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_206_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_206_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_206_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_207_1 = ((st_var_3_1.buffer[0] * 2) + 628) & 63;
  int stage_v_207_2 = ((st_var_3_2.buffer[0] * 2) + 628) & 63;
  if (stage_v_207_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_207_1) - 5) & 255;
    if (stage_v_207_1 > 37)
    {
      chk_sum_1 ^= stage_v_207_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_207_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_207_2) - 5) & 255;
    if (stage_v_207_2 > 37)
    {
      chk_sum_2 ^= stage_v_207_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_208_1 = (st_var_0_1.buffer[0] ^ 211) & 3;
  int stage_v_208_2 = (st_var_0_2.buffer[0] ^ 211) & 3;
  switch (stage_v_208_1)
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

  switch (stage_v_208_2)
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

  int stage_v_209_1 = (st_var_1_1.buffer[0] ^ 212) & 3;
  int stage_v_209_2 = (st_var_1_2.buffer[0] ^ 212) & 3;
  switch (stage_v_209_1)
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

  switch (stage_v_209_2)
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

  out_sink_1 += ((sec_r000124_19_1 * 1) + (sec_r000124_0_1 * 1)) & 255;
  out_sink_2 += ((sec_r000124_19_2 * 1) + (sec_r000124_0_2 * 1)) & 255;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000124_3_1 != sec_r000124_3_2);
  __CPROVER_assume(sec_r000124_5_1 != sec_r000124_5_2);
  __CPROVER_assume(sec_r000124_17_1 != sec_r000124_17_2);
  __CPROVER_assume(pub_r000124_13_1 == pub_r000124_13_2);
  __CPROVER_assume(sec_r000124_11_1 != sec_r000124_11_2);
  __CPROVER_assume(sec_r000124_4_1 != sec_r000124_4_2);
  __CPROVER_assume(sec_r000124_19_1 != sec_r000124_19_2);
  __CPROVER_assume(pub_r000124_2_1 == pub_r000124_2_2);
  __CPROVER_assume(sec_r000124_1_1 != sec_r000124_1_2);
  __CPROVER_assume(sec_r000124_0_1 != sec_r000124_0_2);
  __CPROVER_assume(sec_r000124_7_1 != sec_r000124_7_2);
  __CPROVER_assume(pub_r000124_6_1 == pub_r000124_6_2);
  __CPROVER_assume(sec_r000124_6_1 != sec_r000124_6_2);
  __CPROVER_assume(pub_r000124_0_1 == pub_r000124_0_2);
  __CPROVER_assume(pub_r000124_8_1 == pub_r000124_8_2);
  __CPROVER_assume(pub_r000124_7_1 == pub_r000124_7_2);
  __CPROVER_assume(pub_r000124_17_1 == pub_r000124_17_2);
  __CPROVER_assume(pub_r000124_9_1 == pub_r000124_9_2);
  __CPROVER_assume(sec_r000124_13_1 != sec_r000124_13_2);
  __CPROVER_assume(sec_r000124_10_1 != sec_r000124_10_2);
  __CPROVER_assume(sec_r000124_15_1 != sec_r000124_15_2);
  __CPROVER_assume(pub_r000124_4_1 == pub_r000124_4_2);
  __CPROVER_assume(pub_r000124_1_1 == pub_r000124_1_2);
  __CPROVER_assume(pub_r000124_3_1 == pub_r000124_3_2);
  __CPROVER_assume(sec_r000124_16_1 != sec_r000124_16_2);
  __CPROVER_assume(pub_r000124_12_1 == pub_r000124_12_2);
  __CPROVER_assume(pub_r000124_10_1 == pub_r000124_10_2);
  __CPROVER_assume(sec_r000124_8_1 != sec_r000124_8_2);
  __CPROVER_assume(sec_r000124_2_1 != sec_r000124_2_2);
  __CPROVER_assume(sec_r000124_14_1 != sec_r000124_14_2);
  __CPROVER_assume(pub_r000124_15_1 == pub_r000124_15_2);
  __CPROVER_assume(pub_r000124_5_1 == pub_r000124_5_2);
  __CPROVER_assume(pub_r000124_16_1 == pub_r000124_16_2);
  __CPROVER_assume(sec_r000124_9_1 != sec_r000124_9_2);
  __CPROVER_assume(pub_r000124_14_1 == pub_r000124_14_2);
  __CPROVER_assume(sec_r000124_18_1 != sec_r000124_18_2);
  __CPROVER_assume(sec_r000124_12_1 != sec_r000124_12_2);
  __CPROVER_assume(pub_r000124_11_1 == pub_r000124_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.calib == st_var_2_2.calib);
  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.reading == st_var_2_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.envelope == st_var_3_2.envelope);
  assert(st_var_3_1.peak == st_var_3_2.peak);
  assert(st_var_3_1.rms == st_var_3_2.rms);
  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.channels == st_var_3_2.channels);
  assert(st_var_3_1.sample_rate == st_var_3_2.sample_rate);
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
}


