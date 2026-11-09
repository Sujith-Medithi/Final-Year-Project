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
struct MatrixBlock_R001574_7413_0
{
  int trace;
  short scale;
  int density;
  int dim;
  int buffer[3];
};
struct Transaction_R001574_7413_1
{
  int auth_code;
  int fee;
  int status;
  unsigned char account_id;
  int rate;
  int buffer[3];
};
struct Vector3D_R001574_7413_2
{
  unsigned char pitch;
  unsigned char coord_z;
  unsigned char heading;
  short coord_x;
  int coord_y;
  int norm_sq;
  int buffer[3];
};
struct AudioFrame_R001574_7413_3
{
  unsigned char sample_rate;
  int envelope;
  unsigned char gain;
  int peak;
  int buffer[3];
};
union RegisterBank_R001574_7413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R001574_7413_1
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
void fn_R001574_7413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st_1 = {0};
  struct MatrixBlock_R001574_7413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int residue_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_78_1 > 16)
  {
    acc_1 = ((acc_1 + (residue_78_1 * 2)) + 5) & 127;
    aux_1 ^= residue_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_78_2 > 16)
  {
    acc_2 = ((acc_2 + (residue_78_2 * 2)) + 5) & 127;
    aux_2 ^= residue_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_98_1 = local_arr_1[aux_1 % 3];
  int sample_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_98_2 * 2)) & 127;
  int checksum_77_1 = 0;
  int checksum_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_77_1 = ((checksum_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_77_2 = ((checksum_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_77_1) & 127;
    acc_2 = (acc_2 + checksum_77_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_78_1 == residue_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_98_1 == sample_98_2);
  assert(checksum_77_1 == checksum_77_2);
}

int fn_R001574_7413_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int residue_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_78 > 16)
  {
    acc = ((acc + (residue_78 * 2)) + 5) & 127;
    aux ^= residue_78 & 15;
  }
  else
  {
    acc = ((acc - residue_78) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_98 = local_arr[aux % 3];
  acc = (acc + (sample_98 * 2)) & 127;
  int checksum_77 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_77 = ((checksum_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_77) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001574_7413_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st_1 = {0};
  struct MatrixBlock_R001574_7413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int offset_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_36_1 > 36)
  {
    acc_1 = ((acc_1 + (offset_36_1 * 2)) + 5) & 127;
    aux_1 ^= offset_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_36_2 > 36)
  {
    acc_2 = ((acc_2 + (offset_36_2 * 2)) + 5) & 127;
    aux_2 ^= offset_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_58_1) & 63;
  aux_2 = (aux_2 + pivot_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_66_1 = local_arr_1[aux_1 % 3];
  int factor_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_66_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_36_1 == offset_36_2);
  assert(pivot_58_1 == pivot_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_66_1 == factor_66_2);
}

int fn_R001574_7413_1(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int offset_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_36 > 36)
  {
    acc = ((acc + (offset_36 * 2)) + 5) & 127;
    aux ^= offset_36 & 15;
  }
  else
  {
    acc = ((acc - offset_36) + 11) & 127;
    aux += 3;
  }
  int pivot_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_58) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_66 = local_arr[aux % 3];
  acc = (acc + (factor_66 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001574_7413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st_1 = {0};
  struct AudioFrame_R001574_7413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_92_1 = local_arr_1[aux_1 % 3];
  int pivot_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_92_2 * 2)) & 127;
  int window_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_38_1 > 17)
  {
    acc_1 = ((acc_1 + (window_38_1 * 2)) + 5) & 127;
    aux_1 ^= window_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_38_2 > 17)
  {
    acc_2 = ((acc_2 + (window_38_2 * 2)) + 5) & 127;
    aux_2 ^= window_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_16_1 = 0;
  int index_reg_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_16_1 = ((index_reg_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_16_2 = ((index_reg_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_16_1) & 127;
    acc_2 = (acc_2 + index_reg_16_2) & 127;
  }

  int residue_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_48_1) & 63;
  aux_2 = (aux_2 + residue_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_92_1 == pivot_92_2);
  assert(window_38_1 == window_38_2);
  assert(index_reg_16_1 == index_reg_16_2);
  assert(residue_48_1 == residue_48_2);
}

int fn_R001574_7413_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int pivot_92 = local_arr[aux % 3];
  acc = (acc + (pivot_92 * 2)) & 127;
  int window_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_38 > 17)
  {
    acc = ((acc + (window_38 * 2)) + 5) & 127;
    aux ^= window_38 & 15;
  }
  else
  {
    acc = ((acc - window_38) + 11) & 127;
    aux += 3;
  }
  int index_reg_16 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_16 = ((index_reg_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_16) & 127;
  }

  int residue_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001574_7413_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st_1 = {0};
  struct AudioFrame_R001574_7413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int bound_84_1 = 0;
  int bound_84_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_84_1 = ((bound_84_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_84_2 = ((bound_84_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_84_1) & 127;
    acc_2 = (acc_2 + bound_84_2) & 127;
  }

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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_84_1 == bound_84_2);
  assert(quotient_31_1 == quotient_31_2);
}

int fn_R001574_7413_3(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int bound_84 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_84 = ((bound_84 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_84) & 127;
  }

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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001574_7413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st_1 = {0};
  struct AudioFrame_R001574_7413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int phase_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_60_1)
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

  switch (phase_60_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_14_1 = local_arr_1[aux_1 % 3];
  int mask_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_14_2 * 2)) & 127;
  int quantum_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_88_1) & 63;
  aux_2 = (aux_2 + quantum_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_60_1 == phase_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_14_1 == mask_14_2);
  assert(quantum_88_1 == quantum_88_2);
}

int fn_R001574_7413_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int phase_60 = (aux + st.buffer[1]) & 3;
  switch (phase_60)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_14 = local_arr[aux % 3];
  acc = (acc + (mask_14 * 2)) & 127;
  int quantum_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_88) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001574_7413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st_1 = {0};
  struct MatrixBlock_R001574_7413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int pivot_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_97_1 > 43)
  {
    acc_1 = ((acc_1 + (pivot_97_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_97_2 > 43)
  {
    acc_2 = ((acc_2 + (pivot_97_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_95_1)
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

  switch (stride_95_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_97_1 == pivot_97_2);
  assert(stride_95_1 == stride_95_2);
}

int fn_R001574_7413_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int pivot_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_97 > 43)
  {
    acc = ((acc + (pivot_97 * 2)) + 5) & 127;
    aux ^= pivot_97 & 15;
  }
  else
  {
    acc = ((acc - pivot_97) + 11) & 127;
    aux += 3;
  }
  int stride_95 = (aux + st.buffer[1]) & 3;
  switch (stride_95)
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

void fn_R001574_7413_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st_1 = {0};
  struct MatrixBlock_R001574_7413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int weight_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_92_1 > 48)
  {
    acc_1 = ((acc_1 + (weight_92_1 * 2)) + 5) & 127;
    aux_1 ^= weight_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_92_2 > 48)
  {
    acc_2 = ((acc_2 + (weight_92_2 * 2)) + 5) & 127;
    aux_2 ^= weight_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_59_1) & 63;
  aux_2 = (aux_2 + index_reg_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_28_1 = 0;
  int stride_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_28_1 = ((stride_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_28_2 = ((stride_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_28_1) & 127;
    acc_2 = (acc_2 + stride_28_2) & 127;
  }

  int phase_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_88_1)
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

  switch (phase_88_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_92_1 == weight_92_2);
  assert(index_reg_59_1 == index_reg_59_2);
  assert(stride_28_1 == stride_28_2);
  assert(phase_88_1 == phase_88_2);
}

int fn_R001574_7413_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int weight_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_92 > 48)
  {
    acc = ((acc + (weight_92 * 2)) + 5) & 127;
    aux ^= weight_92 & 15;
  }
  else
  {
    acc = ((acc - weight_92) + 11) & 127;
    aux += 3;
  }
  int index_reg_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_59) & 63;
  acc ^= aux;
  int stride_28 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_28 = ((stride_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_28) & 127;
  }

  int phase_88 = (aux + st.buffer[1]) & 3;
  switch (phase_88)
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

void fn_R001574_7413_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st_1 = {0};
  struct MatrixBlock_R001574_7413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int residue_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_70_1)
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

  switch (residue_70_2)
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

  int accumulator_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_86_1 > 50)
  {
    acc_1 = ((acc_1 + (accumulator_86_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_86_2 > 50)
  {
    acc_2 = ((acc_2 + (accumulator_86_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_86_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_70_1 == residue_70_2);
  assert(accumulator_86_1 == accumulator_86_2);
}

int fn_R001574_7413_7(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int residue_70 = (aux + st.buffer[1]) & 3;
  switch (residue_70)
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

  int accumulator_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_86 > 50)
  {
    acc = ((acc + (accumulator_86 * 2)) + 5) & 127;
    aux ^= accumulator_86 & 15;
  }
  else
  {
    acc = ((acc - accumulator_86) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001574_7413_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001574_7413_2 st_1 = {0};
  struct Vector3D_R001574_7413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_17_1) & 63;
  aux_2 = (aux_2 + phase_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_61_1)
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

  switch (index_reg_61_2)
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

  int checksum_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_44_1 > 27)
  {
    acc_1 = ((acc_1 + (checksum_44_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_44_2 > 27)
  {
    acc_2 = ((acc_2 + (checksum_44_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_44_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_17_1 == phase_17_2);
  assert(index_reg_61_1 == index_reg_61_2);
  assert(checksum_44_1 == checksum_44_2);
}

int fn_R001574_7413_8(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001574_7413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_17) & 63;
  acc ^= aux;
  int index_reg_61 = (aux + st.buffer[1]) & 3;
  switch (index_reg_61)
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

  int checksum_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_44 > 27)
  {
    acc = ((acc + (checksum_44 * 2)) + 5) & 127;
    aux ^= checksum_44 & 15;
  }
  else
  {
    acc = ((acc - checksum_44) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001574_7413_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001574_7413_1 st_1 = {0};
  struct Transaction_R001574_7413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int damping_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_67_1) & 63;
  aux_2 = (aux_2 + damping_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_95_1 = local_arr_1[aux_1 % 3];
  int bound_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_95_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_73_1 > 19)
  {
    acc_1 = ((acc_1 + (weight_73_1 * 2)) + 5) & 127;
    aux_1 ^= weight_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_73_2 > 19)
  {
    acc_2 = ((acc_2 + (weight_73_2 * 2)) + 5) & 127;
    aux_2 ^= weight_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_73_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_67_1 == damping_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_95_1 == bound_95_2);
  assert(weight_73_1 == weight_73_2);
}

int fn_R001574_7413_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001574_7413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int damping_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_67) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_95 = local_arr[aux % 3];
  acc = (acc + (bound_95 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_73 > 19)
  {
    acc = ((acc + (weight_73 * 2)) + 5) & 127;
    aux ^= weight_73 & 15;
  }
  else
  {
    acc = ((acc - weight_73) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001574_7413_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st_1 = {0};
  struct MatrixBlock_R001574_7413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int delta_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_54_1 > 26)
  {
    acc_1 = ((acc_1 + (delta_54_1 * 2)) + 5) & 127;
    aux_1 ^= delta_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_54_2 > 26)
  {
    acc_2 = ((acc_2 + (delta_54_2 * 2)) + 5) & 127;
    aux_2 ^= delta_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_60_1 = local_arr_1[aux_1 % 3];
  int stride_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_60_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_54_1 == delta_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_60_1 == stride_60_2);
}

int fn_R001574_7413_10(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int delta_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_54 > 26)
  {
    acc = ((acc + (delta_54 * 2)) + 5) & 127;
    aux ^= delta_54 & 15;
  }
  else
  {
    acc = ((acc - delta_54) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int stride_60 = local_arr[aux % 3];
  acc = (acc + (stride_60 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001574_7413_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st_1 = {0};
  struct AudioFrame_R001574_7413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_58_1 = local_arr_1[aux_1 % 3];
  int coefficient_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_58_2 * 2)) & 127;
  int segment_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_63_1) & 63;
  aux_2 = (aux_2 + segment_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_68_1)
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

  switch (coefficient_68_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_58_1 == coefficient_58_2);
  assert(segment_63_1 == segment_63_2);
  assert(coefficient_68_1 == coefficient_68_2);
}

int fn_R001574_7413_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int coefficient_58 = local_arr[aux % 3];
  acc = (acc + (coefficient_58 * 2)) & 127;
  int segment_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_63) & 63;
  acc ^= aux;
  int coefficient_68 = (aux + st.buffer[1]) & 3;
  switch (coefficient_68)
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

void fn_R001574_7413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001574_7413_2 st_1 = {0};
  struct Vector3D_R001574_7413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_22_1 = local_arr_1[aux_1 % 3];
  int tally_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_22_2 * 2)) & 127;
  int offset_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_92_1) & 63;
  aux_2 = (aux_2 + offset_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_89_1 = 0;
  int index_reg_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_89_1 = ((index_reg_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_89_2 = ((index_reg_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_89_1) & 127;
    acc_2 = (acc_2 + index_reg_89_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_22_1 == tally_22_2);
  assert(offset_92_1 == offset_92_2);
  assert(index_reg_89_1 == index_reg_89_2);
}

int fn_R001574_7413_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001574_7413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int tally_22 = local_arr[aux % 3];
  acc = (acc + (tally_22 * 2)) & 127;
  int offset_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_92) & 63;
  acc ^= aux;
  int index_reg_89 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_89 = ((index_reg_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_89) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001574_7413_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001574_7413_1 st_1 = {0};
  struct Transaction_R001574_7413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int residue_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_75_1)
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

  switch (residue_75_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_89_1 = 0;
  int window_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_89_1 = ((window_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_89_2 = ((window_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_89_1) & 127;
    acc_2 = (acc_2 + window_89_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_64_1 = local_arr_1[aux_1 % 3];
  int delta_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_64_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_75_1 == residue_75_2);
  assert(window_89_1 == window_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_64_1 == delta_64_2);
}

int fn_R001574_7413_13(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001574_7413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int residue_75 = (aux + st.buffer[1]) & 3;
  switch (residue_75)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_89 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_89 = ((window_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_89) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int delta_64 = local_arr[aux % 3];
  acc = (acc + (delta_64 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001574_7413_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st_1 = {0};
  struct MatrixBlock_R001574_7413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int damping_94_1 = 0;
  int damping_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_94_1 = ((damping_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_94_2 = ((damping_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_94_1) & 127;
    acc_2 = (acc_2 + damping_94_2) & 127;
  }

  int weight_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_32_1) & 63;
  aux_2 = (aux_2 + weight_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_90_1 = local_arr_1[aux_1 % 3];
  int threshold_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_94_1 == damping_94_2);
  assert(weight_32_1 == weight_32_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_90_1 == threshold_90_2);
}

int fn_R001574_7413_14(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int damping_94 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_94 = ((damping_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_94) & 127;
  }

  int weight_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_32) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int threshold_90 = local_arr[aux % 3];
  acc = (acc + (threshold_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001574_7413_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st_1 = {0};
  struct AudioFrame_R001574_7413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_60_1 = local_arr_1[aux_1 % 3];
  int pivot_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_60_2 * 2)) & 127;
  int weight_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_11_1)
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

  switch (weight_11_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_76_1) & 63;
  aux_2 = (aux_2 + checksum_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_60_1 == pivot_60_2);
  assert(weight_11_1 == weight_11_2);
  assert(checksum_76_1 == checksum_76_2);
}

int fn_R001574_7413_15(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int pivot_60 = local_arr[aux % 3];
  acc = (acc + (pivot_60 * 2)) & 127;
  int weight_11 = (aux + st.buffer[1]) & 3;
  switch (weight_11)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_76) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001574_7413_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st_1 = {0};
  struct MatrixBlock_R001574_7413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int damping_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_22_1 > 34)
  {
    acc_1 = ((acc_1 + (damping_22_1 * 2)) + 5) & 127;
    aux_1 ^= damping_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_22_2 > 34)
  {
    acc_2 = ((acc_2 + (damping_22_2 * 2)) + 5) & 127;
    aux_2 ^= damping_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_17_1 = local_arr_1[aux_1 % 3];
  int weight_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_17_2 * 2)) & 127;
  int index_reg_57_1 = 0;
  int index_reg_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_57_1 = ((index_reg_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_57_2 = ((index_reg_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_57_1) & 127;
    acc_2 = (acc_2 + index_reg_57_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_22_1 == damping_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_17_1 == weight_17_2);
  assert(index_reg_57_1 == index_reg_57_2);
}

int fn_R001574_7413_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001574_7413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int damping_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_22 > 34)
  {
    acc = ((acc + (damping_22 * 2)) + 5) & 127;
    aux ^= damping_22 & 15;
  }
  else
  {
    acc = ((acc - damping_22) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int weight_17 = local_arr[aux % 3];
  acc = (acc + (weight_17 * 2)) & 127;
  int index_reg_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_57 = ((index_reg_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_57) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001574_7413_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st_1 = {0};
  struct AudioFrame_R001574_7413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int coefficient_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_52_1 > 30)
  {
    acc_1 = ((acc_1 + (coefficient_52_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_52_2 > 30)
  {
    acc_2 = ((acc_2 + (coefficient_52_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_40_1)
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

  switch (mask_40_2)
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
  int bound_46_1 = local_arr_1[aux_1 % 3];
  int bound_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_46_2 * 2)) & 127;
  int quantum_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_24_1) & 63;
  aux_2 = (aux_2 + quantum_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_52_1 == coefficient_52_2);
  assert(mask_40_1 == mask_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_46_1 == bound_46_2);
  assert(quantum_24_1 == quantum_24_2);
}

int fn_R001574_7413_17(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int coefficient_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_52 > 30)
  {
    acc = ((acc + (coefficient_52 * 2)) + 5) & 127;
    aux ^= coefficient_52 & 15;
  }
  else
  {
    acc = ((acc - coefficient_52) + 11) & 127;
    aux += 3;
  }
  int mask_40 = (aux + st.buffer[1]) & 3;
  switch (mask_40)
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
  int bound_46 = local_arr[aux % 3];
  acc = (acc + (bound_46 * 2)) & 127;
  int quantum_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_24) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001574_7413_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st_1 = {0};
  struct AudioFrame_R001574_7413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_19_1 > 49)
  {
    acc_1 = ((acc_1 + (segment_19_1 * 2)) + 5) & 127;
    aux_1 ^= segment_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_19_2 > 49)
  {
    acc_2 = ((acc_2 + (segment_19_2 * 2)) + 5) & 127;
    aux_2 ^= segment_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_82_1 = 0;
  int quotient_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_82_1 = ((quotient_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_82_2 = ((quotient_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_82_1) & 127;
    acc_2 = (acc_2 + quotient_82_2) & 127;
  }

  int quantum_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_68_1) & 63;
  aux_2 = (aux_2 + quantum_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_19_1 == segment_19_2);
  assert(quotient_82_1 == quotient_82_2);
  assert(quantum_68_1 == quantum_68_2);
}

int fn_R001574_7413_18(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_19 > 49)
  {
    acc = ((acc + (segment_19 * 2)) + 5) & 127;
    aux ^= segment_19 & 15;
  }
  else
  {
    acc = ((acc - segment_19) + 11) & 127;
    aux += 3;
  }
  int quotient_82 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_82 = ((quotient_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_82) & 127;
  }

  int quantum_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001574_7413_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st_1 = {0};
  struct AudioFrame_R001574_7413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_48_1 > 45)
  {
    acc_1 = ((acc_1 + (parity_48_1 * 2)) + 5) & 127;
    aux_1 ^= parity_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_48_2 > 45)
  {
    acc_2 = ((acc_2 + (parity_48_2 * 2)) + 5) & 127;
    aux_2 ^= parity_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_64_1)
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

  switch (tracker_64_2)
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

  int damping_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_48_1) & 63;
  aux_2 = (aux_2 + damping_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_48_1 == parity_48_2);
  assert(tracker_64_1 == tracker_64_2);
  assert(damping_48_1 == damping_48_2);
}

int fn_R001574_7413_19(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_48 > 45)
  {
    acc = ((acc + (parity_48 * 2)) + 5) & 127;
    aux ^= parity_48 & 15;
  }
  else
  {
    acc = ((acc - parity_48) + 11) & 127;
    aux += 3;
  }
  int tracker_64 = (aux + st.buffer[1]) & 3;
  switch (tracker_64)
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

  int damping_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001574_7413_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st_1 = {0};
  struct AudioFrame_R001574_7413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int delta_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_76_1 > 40)
  {
    acc_1 = ((acc_1 + (delta_76_1 * 2)) + 5) & 127;
    aux_1 ^= delta_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_76_2 > 40)
  {
    acc_2 = ((acc_2 + (delta_76_2 * 2)) + 5) & 127;
    aux_2 ^= delta_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_23_1 = local_arr_1[aux_1 % 3];
  int bound_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_23_2 * 2)) & 127;
  int threshold_36_1 = 0;
  int threshold_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_36_1 = ((threshold_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_36_2 = ((threshold_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_36_1) & 127;
    acc_2 = (acc_2 + threshold_36_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_76_1 == delta_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_23_1 == bound_23_2);
  assert(threshold_36_1 == threshold_36_2);
}

int fn_R001574_7413_20(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int delta_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_76 > 40)
  {
    acc = ((acc + (delta_76 * 2)) + 5) & 127;
    aux ^= delta_76 & 15;
  }
  else
  {
    acc = ((acc - delta_76) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_23 = local_arr[aux % 3];
  acc = (acc + (bound_23 * 2)) & 127;
  int threshold_36 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_36 = ((threshold_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_36) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001574_7413_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st_1 = {0};
  struct AudioFrame_R001574_7413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int delta_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_47_1)
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

  switch (delta_47_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_47_1 == delta_47_2);
}

int fn_R001574_7413_21(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001574_7413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int delta_47 = (aux + st.buffer[1]) & 3;
  switch (delta_47)
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
  return (acc + aux) & 255;
}

void fn_R001574_7413_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001574_7413_2 st_1 = {0};
  struct Vector3D_R001574_7413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int residue_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_89_1)
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

  switch (residue_89_2)
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
  int weight_18_1 = local_arr_1[aux_1 % 3];
  int weight_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_18_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_89_1 == residue_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_18_1 == weight_18_2);
}

int fn_R001574_7413_22(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001574_7413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int residue_89 = (aux + st.buffer[1]) & 3;
  switch (residue_89)
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
  int weight_18 = local_arr[aux % 3];
  acc = (acc + (weight_18 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001574_7413_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001574_7413_2 st_1 = {0};
  struct Vector3D_R001574_7413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int index_reg_18_1 = 0;
  int index_reg_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_18_1 = ((index_reg_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_18_2 = ((index_reg_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_18_1) & 127;
    acc_2 = (acc_2 + index_reg_18_2) & 127;
  }

  int threshold_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_99_1) & 63;
  aux_2 = (aux_2 + threshold_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_15_1)
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

  switch (margin_15_2)
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
  int segment_89_1 = local_arr_1[aux_1 % 3];
  int segment_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_89_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_18_1 == index_reg_18_2);
  assert(threshold_99_1 == threshold_99_2);
  assert(margin_15_1 == margin_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_89_1 == segment_89_2);
}

int fn_R001574_7413_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001574_7413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int index_reg_18 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_18 = ((index_reg_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_18) & 127;
  }

  int threshold_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_99) & 63;
  acc ^= aux;
  int margin_15 = (aux + st.buffer[1]) & 3;
  switch (margin_15)
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
  int segment_89 = local_arr[aux % 3];
  acc = (acc + (segment_89 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001574_0_1;
  int sec_r001574_0_2;
  int sec_r001574_1_1;
  int sec_r001574_1_2;
  int sec_r001574_2_1;
  int sec_r001574_2_2;
  int sec_r001574_3_1;
  int sec_r001574_3_2;
  int sec_r001574_4_1;
  int sec_r001574_4_2;
  int sec_r001574_5_1;
  int sec_r001574_5_2;
  int sec_r001574_6_1;
  int sec_r001574_6_2;
  int sec_r001574_7_1;
  int sec_r001574_7_2;
  int sec_r001574_8_1;
  int sec_r001574_8_2;
  int sec_r001574_9_1;
  int sec_r001574_9_2;
  int sec_r001574_10_1;
  int sec_r001574_10_2;
  int sec_r001574_11_1;
  int sec_r001574_11_2;
  int sec_r001574_12_1;
  int sec_r001574_12_2;
  int sec_r001574_13_1;
  int sec_r001574_13_2;
  int sec_r001574_14_1;
  int sec_r001574_14_2;
  int sec_r001574_15_1;
  int sec_r001574_15_2;
  int sec_r001574_16_1;
  int sec_r001574_16_2;
  int sec_r001574_17_1;
  int sec_r001574_17_2;
  int sec_r001574_18_1;
  int sec_r001574_18_2;
  int sec_r001574_19_1;
  int sec_r001574_19_2;
  int sec_r001574_20_1;
  int sec_r001574_20_2;
  int pub_r001574_0_1;
  int pub_r001574_0_2;
  int pub_r001574_1_1;
  int pub_r001574_1_2;
  int pub_r001574_2_1;
  int pub_r001574_2_2;
  int pub_r001574_3_1;
  int pub_r001574_3_2;
  int pub_r001574_4_1;
  int pub_r001574_4_2;
  int pub_r001574_5_1;
  int pub_r001574_5_2;
  int pub_r001574_6_1;
  int pub_r001574_6_2;
  int pub_r001574_7_1;
  int pub_r001574_7_2;
  int pub_r001574_8_1;
  int pub_r001574_8_2;
  int pub_r001574_9_1;
  int pub_r001574_9_2;
  int pub_r001574_10_1;
  int pub_r001574_10_2;
  int pub_r001574_11_1;
  int pub_r001574_11_2;
  int pub_r001574_12_1;
  int pub_r001574_12_2;
  int pub_r001574_13_1;
  int pub_r001574_13_2;
  int pub_r001574_14_1;
  int pub_r001574_14_2;
  int pub_r001574_15_1;
  int pub_r001574_15_2;
  int pub_r001574_16_1;
  int pub_r001574_16_2;
  int pub_r001574_17_1;
  int pub_r001574_17_2;
  int pub_r001574_18_1;
  int pub_r001574_18_2;
  int pub_r001574_19_1;
  int pub_r001574_19_2;
  int pub_r001574_20_1;
  int pub_r001574_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001574_0_1 >= (-100)) && (pub_r001574_0_1 <= 100));
  __CPROVER_assume((pub_r001574_0_2 >= (-100)) && (pub_r001574_0_2 <= 100));
  __CPROVER_assume((pub_r001574_1_1 >= (-100)) && (pub_r001574_1_1 <= 100));
  __CPROVER_assume((pub_r001574_1_2 >= (-100)) && (pub_r001574_1_2 <= 100));
  __CPROVER_assume((pub_r001574_2_1 >= (-100)) && (pub_r001574_2_1 <= 100));
  __CPROVER_assume((pub_r001574_2_2 >= (-100)) && (pub_r001574_2_2 <= 100));
  __CPROVER_assume((pub_r001574_3_1 >= (-100)) && (pub_r001574_3_1 <= 100));
  __CPROVER_assume((pub_r001574_3_2 >= (-100)) && (pub_r001574_3_2 <= 100));
  __CPROVER_assume((pub_r001574_4_1 >= (-100)) && (pub_r001574_4_1 <= 100));
  __CPROVER_assume((pub_r001574_4_2 >= (-100)) && (pub_r001574_4_2 <= 100));
  __CPROVER_assume((pub_r001574_5_1 >= (-100)) && (pub_r001574_5_1 <= 100));
  __CPROVER_assume((pub_r001574_5_2 >= (-100)) && (pub_r001574_5_2 <= 100));
  __CPROVER_assume((pub_r001574_6_1 >= (-100)) && (pub_r001574_6_1 <= 100));
  __CPROVER_assume((pub_r001574_6_2 >= (-100)) && (pub_r001574_6_2 <= 100));
  __CPROVER_assume((pub_r001574_7_1 >= (-100)) && (pub_r001574_7_1 <= 100));
  __CPROVER_assume((pub_r001574_7_2 >= (-100)) && (pub_r001574_7_2 <= 100));
  __CPROVER_assume((pub_r001574_8_1 >= (-100)) && (pub_r001574_8_1 <= 100));
  __CPROVER_assume((pub_r001574_8_2 >= (-100)) && (pub_r001574_8_2 <= 100));
  __CPROVER_assume((pub_r001574_9_1 >= (-100)) && (pub_r001574_9_1 <= 100));
  __CPROVER_assume((pub_r001574_9_2 >= (-100)) && (pub_r001574_9_2 <= 100));
  __CPROVER_assume((pub_r001574_10_1 >= (-100)) && (pub_r001574_10_1 <= 100));
  __CPROVER_assume((pub_r001574_10_2 >= (-100)) && (pub_r001574_10_2 <= 100));
  __CPROVER_assume((pub_r001574_11_1 >= (-100)) && (pub_r001574_11_1 <= 100));
  __CPROVER_assume((pub_r001574_11_2 >= (-100)) && (pub_r001574_11_2 <= 100));
  __CPROVER_assume((pub_r001574_12_1 >= (-100)) && (pub_r001574_12_1 <= 100));
  __CPROVER_assume((pub_r001574_12_2 >= (-100)) && (pub_r001574_12_2 <= 100));
  __CPROVER_assume((pub_r001574_13_1 >= (-100)) && (pub_r001574_13_1 <= 100));
  __CPROVER_assume((pub_r001574_13_2 >= (-100)) && (pub_r001574_13_2 <= 100));
  __CPROVER_assume((pub_r001574_14_1 >= (-100)) && (pub_r001574_14_1 <= 100));
  __CPROVER_assume((pub_r001574_14_2 >= (-100)) && (pub_r001574_14_2 <= 100));
  __CPROVER_assume((pub_r001574_15_1 >= (-100)) && (pub_r001574_15_1 <= 100));
  __CPROVER_assume((pub_r001574_15_2 >= (-100)) && (pub_r001574_15_2 <= 100));
  __CPROVER_assume((pub_r001574_16_1 >= (-100)) && (pub_r001574_16_1 <= 100));
  __CPROVER_assume((pub_r001574_16_2 >= (-100)) && (pub_r001574_16_2 <= 100));
  __CPROVER_assume((pub_r001574_17_1 >= (-100)) && (pub_r001574_17_1 <= 100));
  __CPROVER_assume((pub_r001574_17_2 >= (-100)) && (pub_r001574_17_2 <= 100));
  __CPROVER_assume((pub_r001574_18_1 >= (-100)) && (pub_r001574_18_1 <= 100));
  __CPROVER_assume((pub_r001574_18_2 >= (-100)) && (pub_r001574_18_2 <= 100));
  __CPROVER_assume((pub_r001574_19_1 >= (-100)) && (pub_r001574_19_1 <= 100));
  __CPROVER_assume((pub_r001574_19_2 >= (-100)) && (pub_r001574_19_2 <= 100));
  __CPROVER_assume((pub_r001574_20_1 >= (-100)) && (pub_r001574_20_1 <= 100));
  __CPROVER_assume((pub_r001574_20_2 >= (-100)) && (pub_r001574_20_2 <= 100));
  __CPROVER_assume((sec_r001574_0_1 >= 0) && (sec_r001574_0_1 <= 255));
  __CPROVER_assume((sec_r001574_0_2 >= 0) && (sec_r001574_0_2 <= 255));
  __CPROVER_assume((sec_r001574_1_1 >= 0) && (sec_r001574_1_1 <= 255));
  __CPROVER_assume((sec_r001574_1_2 >= 0) && (sec_r001574_1_2 <= 255));
  __CPROVER_assume((sec_r001574_2_1 >= 0) && (sec_r001574_2_1 <= 255));
  __CPROVER_assume((sec_r001574_2_2 >= 0) && (sec_r001574_2_2 <= 255));
  __CPROVER_assume((sec_r001574_3_1 >= 0) && (sec_r001574_3_1 <= 255));
  __CPROVER_assume((sec_r001574_3_2 >= 0) && (sec_r001574_3_2 <= 255));
  __CPROVER_assume((sec_r001574_4_1 >= 0) && (sec_r001574_4_1 <= 255));
  __CPROVER_assume((sec_r001574_4_2 >= 0) && (sec_r001574_4_2 <= 255));
  __CPROVER_assume((sec_r001574_5_1 >= 0) && (sec_r001574_5_1 <= 255));
  __CPROVER_assume((sec_r001574_5_2 >= 0) && (sec_r001574_5_2 <= 255));
  __CPROVER_assume((sec_r001574_6_1 >= 0) && (sec_r001574_6_1 <= 255));
  __CPROVER_assume((sec_r001574_6_2 >= 0) && (sec_r001574_6_2 <= 255));
  __CPROVER_assume((sec_r001574_7_1 >= 0) && (sec_r001574_7_1 <= 255));
  __CPROVER_assume((sec_r001574_7_2 >= 0) && (sec_r001574_7_2 <= 255));
  __CPROVER_assume((sec_r001574_8_1 >= 0) && (sec_r001574_8_1 <= 255));
  __CPROVER_assume((sec_r001574_8_2 >= 0) && (sec_r001574_8_2 <= 255));
  __CPROVER_assume((sec_r001574_9_1 >= 0) && (sec_r001574_9_1 <= 255));
  __CPROVER_assume((sec_r001574_9_2 >= 0) && (sec_r001574_9_2 <= 255));
  __CPROVER_assume((sec_r001574_10_1 >= 0) && (sec_r001574_10_1 <= 255));
  __CPROVER_assume((sec_r001574_10_2 >= 0) && (sec_r001574_10_2 <= 255));
  __CPROVER_assume((sec_r001574_11_1 >= 0) && (sec_r001574_11_1 <= 255));
  __CPROVER_assume((sec_r001574_11_2 >= 0) && (sec_r001574_11_2 <= 255));
  __CPROVER_assume((sec_r001574_12_1 >= 0) && (sec_r001574_12_1 <= 255));
  __CPROVER_assume((sec_r001574_12_2 >= 0) && (sec_r001574_12_2 <= 255));
  __CPROVER_assume((sec_r001574_13_1 >= 0) && (sec_r001574_13_1 <= 255));
  __CPROVER_assume((sec_r001574_13_2 >= 0) && (sec_r001574_13_2 <= 255));
  __CPROVER_assume((sec_r001574_14_1 >= 0) && (sec_r001574_14_1 <= 255));
  __CPROVER_assume((sec_r001574_14_2 >= 0) && (sec_r001574_14_2 <= 255));
  __CPROVER_assume((sec_r001574_15_1 >= 0) && (sec_r001574_15_1 <= 255));
  __CPROVER_assume((sec_r001574_15_2 >= 0) && (sec_r001574_15_2 <= 255));
  __CPROVER_assume((sec_r001574_16_1 >= 0) && (sec_r001574_16_1 <= 255));
  __CPROVER_assume((sec_r001574_16_2 >= 0) && (sec_r001574_16_2 <= 255));
  __CPROVER_assume((sec_r001574_17_1 >= 0) && (sec_r001574_17_1 <= 255));
  __CPROVER_assume((sec_r001574_17_2 >= 0) && (sec_r001574_17_2 <= 255));
  __CPROVER_assume((sec_r001574_18_1 >= 0) && (sec_r001574_18_1 <= 255));
  __CPROVER_assume((sec_r001574_18_2 >= 0) && (sec_r001574_18_2 <= 255));
  __CPROVER_assume((sec_r001574_19_1 >= 0) && (sec_r001574_19_1 <= 255));
  __CPROVER_assume((sec_r001574_19_2 >= 0) && (sec_r001574_19_2 <= 255));
  __CPROVER_assume((sec_r001574_20_1 >= 0) && (sec_r001574_20_1 <= 255));
  __CPROVER_assume((sec_r001574_20_2 >= 0) && (sec_r001574_20_2 <= 255));
  struct MatrixBlock_R001574_7413_0 st_var_0_1 = {0};
  struct MatrixBlock_R001574_7413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001574_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001574_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001574_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001574_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001574_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001574_0_2 + 7) & 15;
  struct Transaction_R001574_7413_1 st_var_1_1 = {0};
  struct Transaction_R001574_7413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001574_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001574_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001574_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001574_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001574_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001574_0_2 + 9) & 15;
  struct Vector3D_R001574_7413_2 st_var_2_1 = {0};
  struct Vector3D_R001574_7413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001574_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001574_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001574_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001574_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001574_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001574_0_2 + 11) & 15;
  struct AudioFrame_R001574_7413_3 st_var_3_1 = {0};
  struct AudioFrame_R001574_7413_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001574_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001574_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001574_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001574_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001574_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001574_0_2 + 13) & 15;
  union RegisterBank_R001574_7413_0 u_var_1;
  union RegisterBank_R001574_7413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001574_7413_0(sec_r001574_0_1, sec_r001574_1_1, pub_r001574_2_1, pub_r001574_3_1);
  int helper_flow_0_2 = fn_R001574_7413_0(sec_r001574_0_2, sec_r001574_1_2, pub_r001574_2_2, pub_r001574_3_2);
  fn_R001574_7413_0_2(sec_r001574_0_1, sec_r001574_1_1, pub_r001574_2_1, pub_r001574_3_1, sec_r001574_0_2, sec_r001574_1_2, pub_r001574_2_2, pub_r001574_3_2);
  int helper_flow_1_1 = fn_R001574_7413_1(sec_r001574_1_1, pub_r001574_2_1, pub_r001574_3_1);
  int helper_flow_1_2 = fn_R001574_7413_1(sec_r001574_1_2, pub_r001574_2_2, pub_r001574_3_2);
  fn_R001574_7413_1_2(sec_r001574_1_1, pub_r001574_2_1, pub_r001574_3_1, sec_r001574_1_2, pub_r001574_2_2, pub_r001574_3_2);
  int helper_flow_2_1 = fn_R001574_7413_2(sec_r001574_2_1, sec_r001574_3_1, pub_r001574_4_1, pub_r001574_5_1);
  int helper_flow_2_2 = fn_R001574_7413_2(sec_r001574_2_2, sec_r001574_3_2, pub_r001574_4_2, pub_r001574_5_2);
  fn_R001574_7413_2_2(sec_r001574_2_1, sec_r001574_3_1, pub_r001574_4_1, pub_r001574_5_1, sec_r001574_2_2, sec_r001574_3_2, pub_r001574_4_2, pub_r001574_5_2);
  int helper_flow_3_1 = fn_R001574_7413_3(sec_r001574_3_1, sec_r001574_4_1, pub_r001574_5_1);
  int helper_flow_3_2 = fn_R001574_7413_3(sec_r001574_3_2, sec_r001574_4_2, pub_r001574_5_2);
  fn_R001574_7413_3_2(sec_r001574_3_1, sec_r001574_4_1, pub_r001574_5_1, sec_r001574_3_2, sec_r001574_4_2, pub_r001574_5_2);
  int helper_flow_4_1 = fn_R001574_7413_4(sec_r001574_4_1, pub_r001574_5_1, pub_r001574_6_1, pub_r001574_7_1);
  int helper_flow_4_2 = fn_R001574_7413_4(sec_r001574_4_2, pub_r001574_5_2, pub_r001574_6_2, pub_r001574_7_2);
  fn_R001574_7413_4_2(sec_r001574_4_1, pub_r001574_5_1, pub_r001574_6_1, pub_r001574_7_1, sec_r001574_4_2, pub_r001574_5_2, pub_r001574_6_2, pub_r001574_7_2);
  int stage_v_0_1 = (((sec_r001574_16_1 * 3) + pub_r001574_3_1) + 40) & 127;
  int stage_v_0_2 = (((sec_r001574_16_2 * 3) + pub_r001574_3_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = (((sec_r001574_1_1 * 3) + pub_r001574_12_1) + 25) & 127;
  int stage_v_1_2 = (((sec_r001574_1_2 * 3) + pub_r001574_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = ((pub_r001574_0_1 * 2) + 39) & 63;
  int stage_v_2_2 = ((pub_r001574_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((sec_r001574_0_1 * 3) + pub_r001574_18_1) + 10) & 127;
  int stage_v_3_2 = (((sec_r001574_0_2 * 3) + pub_r001574_18_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = (((sec_r001574_18_1 * 3) + pub_r001574_9_1) + 34) & 127;
  int stage_v_4_2 = (((sec_r001574_18_2 * 3) + pub_r001574_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001574_1_1 * 2) + 41) & 63;
  int stage_v_5_2 = ((pub_r001574_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001574_15_1 * 2) + 38) & 63;
  int stage_v_6_2 = ((pub_r001574_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001574_4_1 * 2) + 39) & 63;
  int stage_v_7_2 = ((pub_r001574_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001574_17_1 * 3) + pub_r001574_11_1) + 25) & 127;
  int stage_v_8_2 = (((sec_r001574_17_2 * 3) + pub_r001574_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = ((pub_r001574_18_1 * 2) + 7) & 63;
  int stage_v_9_2 = ((pub_r001574_18_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((helper_flow_2_1 * 3) + pub_r001574_6_1) + 34) & 127;
  int stage_v_10_2 = (((helper_flow_2_2 * 3) + pub_r001574_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001574_18_1 * 2) + 33) & 63;
  int stage_v_11_2 = ((pub_r001574_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((sec_r001574_11_1 * 3) + pub_r001574_12_1) + 22) & 127;
  int stage_v_12_2 = (((sec_r001574_11_2 * 3) + pub_r001574_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = ((pub_r001574_11_1 * 2) + 13) & 63;
  int stage_v_13_2 = ((pub_r001574_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001574_7_1 * 2) + 49) & 63;
  int stage_v_14_2 = ((pub_r001574_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001574_0_1 * 2) + 42) & 63;
  int stage_v_15_2 = ((pub_r001574_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001574_5_1 * 2) + 17) & 63;
  int stage_v_16_2 = ((pub_r001574_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((sec_r001574_15_1 * 3) + pub_r001574_8_1) + 35) & 127;
  int stage_v_17_2 = (((sec_r001574_15_2 * 3) + pub_r001574_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = (((stage_v_1_1 * 3) + pub_r001574_16_1) + 12) & 127;
  int stage_v_18_2 = (((stage_v_1_2 * 3) + pub_r001574_16_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = (((helper_flow_4_1 * 3) + pub_r001574_16_1) + 18) & 127;
  int stage_v_19_2 = (((helper_flow_4_2 * 3) + pub_r001574_16_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = ((pub_r001574_19_1 * 2) + 19) & 63;
  int stage_v_20_2 = ((pub_r001574_19_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((stage_v_18_1 * 3) + pub_r001574_14_1) + 8) & 127;
  int stage_v_21_2 = (((stage_v_18_2 * 3) + pub_r001574_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = ((pub_r001574_12_1 * 2) + 5) & 63;
  int stage_v_22_2 = ((pub_r001574_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((sec_r001574_9_1 * 3) + pub_r001574_16_1) + 35) & 127;
  int stage_v_23_2 = (((sec_r001574_9_2 * 3) + pub_r001574_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((stage_v_23_1 * 3) + pub_r001574_18_1) + 4) & 127;
  int stage_v_24_2 = (((stage_v_23_2 * 3) + pub_r001574_18_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((sec_r001574_16_1 * 3) + pub_r001574_20_1) + 29) & 127;
  int stage_v_25_2 = (((sec_r001574_16_2 * 3) + pub_r001574_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = ((pub_r001574_11_1 * 2) + 23) & 63;
  int stage_v_26_2 = ((pub_r001574_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = (((stage_v_12_1 * 3) + pub_r001574_19_1) + 17) & 127;
  int stage_v_27_2 = (((stage_v_12_2 * 3) + pub_r001574_19_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = (((helper_flow_2_1 * 3) + pub_r001574_17_1) + 12) & 127;
  int stage_v_28_2 = (((helper_flow_2_2 * 3) + pub_r001574_17_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = ((pub_r001574_8_1 * 2) + 14) & 63;
  int stage_v_29_2 = ((pub_r001574_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001574_8_1 * 2) + 48) & 63;
  int stage_v_30_2 = ((pub_r001574_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001574_1_1 * 2) + 17) & 63;
  int stage_v_31_2 = ((pub_r001574_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (((stage_v_28_1 * 3) + pub_r001574_8_1) + 10) & 127;
  int stage_v_32_2 = (((stage_v_28_2 * 3) + pub_r001574_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = (((sec_r001574_4_1 * 3) + pub_r001574_16_1) + 14) & 127;
  int stage_v_33_2 = (((sec_r001574_4_2 * 3) + pub_r001574_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = ((pub_r001574_14_1 * 2) + 32) & 63;
  int stage_v_34_2 = ((pub_r001574_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (((sec_r001574_16_1 * 3) + pub_r001574_1_1) + 28) & 127;
  int stage_v_35_2 = (((sec_r001574_16_2 * 3) + pub_r001574_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = ((pub_r001574_8_1 * 2) + 28) & 63;
  int stage_v_36_2 = ((pub_r001574_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001574_12_1 * 2) + 43) & 63;
  int stage_v_37_2 = ((pub_r001574_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((stage_v_19_1 * 3) + pub_r001574_5_1) + 29) & 127;
  int stage_v_38_2 = (((stage_v_19_2 * 3) + pub_r001574_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = (((sec_r001574_16_1 * 3) + pub_r001574_16_1) + 33) & 127;
  int stage_v_39_2 = (((sec_r001574_16_2 * 3) + pub_r001574_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = ((pub_r001574_12_1 * 2) + 18) & 63;
  int stage_v_40_2 = ((pub_r001574_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001574_13_1 * 2) + 35) & 63;
  int stage_v_41_2 = ((pub_r001574_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001574_12_1 * 2) + 13) & 63;
  int stage_v_42_2 = ((pub_r001574_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((sec_r001574_18_1 * 3) + pub_r001574_3_1) + 16) & 127;
  int stage_v_43_2 = (((sec_r001574_18_2 * 3) + pub_r001574_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = (((stage_v_27_1 * 3) + pub_r001574_11_1) + 5) & 127;
  int stage_v_44_2 = (((stage_v_27_2 * 3) + pub_r001574_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = (((stage_v_21_1 * 3) + pub_r001574_5_1) + 40) & 127;
  int stage_v_45_2 = (((stage_v_21_2 * 3) + pub_r001574_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = (((stage_v_18_1 * 3) + pub_r001574_7_1) + 32) & 127;
  int stage_v_46_2 = (((stage_v_18_2 * 3) + pub_r001574_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001574_14_1 * 2) + 7) & 63;
  int stage_v_47_2 = ((pub_r001574_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (((stage_v_27_1 * 3) + pub_r001574_18_1) + 12) & 127;
  int stage_v_48_2 = (((stage_v_27_2 * 3) + pub_r001574_18_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = (((sec_r001574_20_1 * 3) + pub_r001574_15_1) + 17) & 127;
  int stage_v_49_2 = (((sec_r001574_20_2 * 3) + pub_r001574_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = ((pub_r001574_20_1 * 2) + 11) & 63;
  int stage_v_50_2 = ((pub_r001574_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001574_2_1 * 2) + 33) & 63;
  int stage_v_51_2 = ((pub_r001574_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((stage_v_38_1 * 3) + pub_r001574_5_1) + 45) & 127;
  int stage_v_52_2 = (((stage_v_38_2 * 3) + pub_r001574_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = (((sec_r001574_8_1 * 3) + pub_r001574_12_1) + 18) & 127;
  int stage_v_53_2 = (((sec_r001574_8_2 * 3) + pub_r001574_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = (((sec_r001574_1_1 * 3) + pub_r001574_0_1) + 6) & 127;
  int stage_v_54_2 = (((sec_r001574_1_2 * 3) + pub_r001574_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = (((stage_v_33_1 * 3) + pub_r001574_7_1) + 24) & 127;
  int stage_v_55_2 = (((stage_v_33_2 * 3) + pub_r001574_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = (((helper_flow_3_1 * 3) + pub_r001574_15_1) + 21) & 127;
  int stage_v_56_2 = (((helper_flow_3_2 * 3) + pub_r001574_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = (((sec_r001574_11_1 * 3) + pub_r001574_2_1) + 17) & 127;
  int stage_v_57_2 = (((sec_r001574_11_2 * 3) + pub_r001574_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((sec_r001574_8_1 * 3) + pub_r001574_3_1) + 15) & 127;
  int stage_v_58_2 = (((sec_r001574_8_2 * 3) + pub_r001574_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = (((stage_v_32_1 * 3) + pub_r001574_17_1) + 17) & 127;
  int stage_v_59_2 = (((stage_v_32_2 * 3) + pub_r001574_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = (((sec_r001574_12_1 * 3) + pub_r001574_13_1) + 11) & 127;
  int stage_v_60_2 = (((sec_r001574_12_2 * 3) + pub_r001574_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((sec_r001574_8_1 * 3) + pub_r001574_3_1) + 7) & 127;
  int stage_v_61_2 = (((sec_r001574_8_2 * 3) + pub_r001574_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001574_2_1 * 2) + 46) & 63;
  int stage_v_62_2 = ((pub_r001574_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((stage_v_43_1 * 3) + pub_r001574_3_1) + 13) & 127;
  int stage_v_63_2 = (((stage_v_43_2 * 3) + pub_r001574_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = ((pub_r001574_5_1 * 2) + 9) & 63;
  int stage_v_64_2 = ((pub_r001574_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001574_19_1 * 2) + 5) & 63;
  int stage_v_65_2 = ((pub_r001574_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((stage_v_3_1 * 3) + pub_r001574_19_1) + 42) & 127;
  int stage_v_66_2 = (((stage_v_3_2 * 3) + pub_r001574_19_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = ((pub_r001574_15_1 * 2) + 23) & 63;
  int stage_v_67_2 = ((pub_r001574_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (((sec_r001574_0_1 * 3) + pub_r001574_6_1) + 8) & 127;
  int stage_v_68_2 = (((sec_r001574_0_2 * 3) + pub_r001574_6_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = ((pub_r001574_20_1 * 2) + 30) & 63;
  int stage_v_69_2 = ((pub_r001574_20_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((sec_r001574_14_1 * 3) + pub_r001574_7_1) + 13) & 127;
  int stage_v_70_2 = (((sec_r001574_14_2 * 3) + pub_r001574_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = ((pub_r001574_17_1 * 2) + 29) & 63;
  int stage_v_71_2 = ((pub_r001574_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001574_0_1 * 2) + 21) & 63;
  int stage_v_72_2 = ((pub_r001574_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_58_1 * 3) + pub_r001574_15_1) + 23) & 127;
  int stage_v_73_2 = (((stage_v_58_2 * 3) + pub_r001574_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = ((pub_r001574_12_1 * 2) + 42) & 63;
  int stage_v_74_2 = ((pub_r001574_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((stage_v_24_1 * 3) + pub_r001574_12_1) + 7) & 127;
  int stage_v_75_2 = (((stage_v_24_2 * 3) + pub_r001574_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = (((stage_v_43_1 * 3) + pub_r001574_11_1) + 21) & 127;
  int stage_v_76_2 = (((stage_v_43_2 * 3) + pub_r001574_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = ((pub_r001574_15_1 * 2) + 16) & 63;
  int stage_v_77_2 = ((pub_r001574_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((stage_v_38_1 * 3) + pub_r001574_18_1) + 40) & 127;
  int stage_v_78_2 = (((stage_v_38_2 * 3) + pub_r001574_18_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = (((stage_v_4_1 * 3) + pub_r001574_7_1) + 21) & 127;
  int stage_v_79_2 = (((stage_v_4_2 * 3) + pub_r001574_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = (((helper_flow_0_1 * 3) + pub_r001574_0_1) + 38) & 127;
  int stage_v_80_2 = (((helper_flow_0_2 * 3) + pub_r001574_0_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = (((sec_r001574_11_1 * 3) + pub_r001574_8_1) + 29) & 127;
  int stage_v_81_2 = (((sec_r001574_11_2 * 3) + pub_r001574_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = ((pub_r001574_13_1 * 2) + 18) & 63;
  int stage_v_82_2 = ((pub_r001574_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001574_5_1 * 2) + 37) & 63;
  int stage_v_83_2 = ((pub_r001574_5_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((stage_v_79_1 * 3) + pub_r001574_9_1) + 18) & 127;
  int stage_v_84_2 = (((stage_v_79_2 * 3) + pub_r001574_9_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = (((stage_v_45_1 * 3) + pub_r001574_13_1) + 14) & 127;
  int stage_v_85_2 = (((stage_v_45_2 * 3) + pub_r001574_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = (((sec_r001574_12_1 * 3) + pub_r001574_7_1) + 15) & 127;
  int stage_v_86_2 = (((sec_r001574_12_2 * 3) + pub_r001574_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = (((sec_r001574_19_1 * 3) + pub_r001574_9_1) + 42) & 127;
  int stage_v_87_2 = (((sec_r001574_19_2 * 3) + pub_r001574_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = (((stage_v_12_1 * 3) + pub_r001574_19_1) + 16) & 127;
  int stage_v_88_2 = (((stage_v_12_2 * 3) + pub_r001574_19_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = (((stage_v_60_1 * 3) + pub_r001574_16_1) + 4) & 127;
  int stage_v_89_2 = (((stage_v_60_2 * 3) + pub_r001574_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((sec_r001574_10_1 * 3) + pub_r001574_17_1) + 35) & 127;
  int stage_v_90_2 = (((sec_r001574_10_2 * 3) + pub_r001574_17_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001574_16_1 * 2) + 41) & 63;
  int stage_v_91_2 = ((pub_r001574_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_81_1 * 3) + pub_r001574_1_1) + 16) & 127;
  int stage_v_92_2 = (((stage_v_81_2 * 3) + pub_r001574_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = (((stage_v_39_1 * 3) + pub_r001574_19_1) + 40) & 127;
  int stage_v_93_2 = (((stage_v_39_2 * 3) + pub_r001574_19_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = (((stage_v_57_1 * 3) + pub_r001574_4_1) + 10) & 127;
  int stage_v_94_2 = (((stage_v_57_2 * 3) + pub_r001574_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = (((stage_v_90_1 * 3) + pub_r001574_20_1) + 28) & 127;
  int stage_v_95_2 = (((stage_v_90_2 * 3) + pub_r001574_20_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = ((pub_r001574_16_1 * 2) + 25) & 63;
  int stage_v_96_2 = ((pub_r001574_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_0_1 * 3) + pub_r001574_5_1) + 32) & 127;
  int stage_v_97_2 = (((stage_v_0_2 * 3) + pub_r001574_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = ((pub_r001574_6_1 * 2) + 29) & 63;
  int stage_v_98_2 = ((pub_r001574_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (((stage_v_24_1 * 3) + pub_r001574_7_1) + 36) & 127;
  int stage_v_99_2 = (((stage_v_24_2 * 3) + pub_r001574_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = ((pub_r001574_8_1 * 2) + 38) & 63;
  int stage_v_100_2 = ((pub_r001574_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001574_13_1 * 2) + 26) & 63;
  int stage_v_101_2 = ((pub_r001574_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001574_9_1 * 2) + 42) & 63;
  int stage_v_102_2 = ((pub_r001574_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001574_12_1 * 2) + 10) & 63;
  int stage_v_103_2 = ((pub_r001574_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((stage_v_55_1 * 3) + pub_r001574_11_1) + 35) & 127;
  int stage_v_104_2 = (((stage_v_55_2 * 3) + pub_r001574_11_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = (((stage_v_43_1 * 3) + pub_r001574_19_1) + 42) & 127;
  int stage_v_105_2 = (((stage_v_43_2 * 3) + pub_r001574_19_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = ((pub_r001574_20_1 * 2) + 44) & 63;
  int stage_v_106_2 = ((pub_r001574_20_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((stage_v_28_1 * 3) + pub_r001574_3_1) + 30) & 127;
  int stage_v_107_2 = (((stage_v_28_2 * 3) + pub_r001574_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = (((sec_r001574_10_1 * 3) + pub_r001574_4_1) + 26) & 127;
  int stage_v_108_2 = (((sec_r001574_10_2 * 3) + pub_r001574_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = (((stage_v_27_1 * 3) + pub_r001574_1_1) + 26) & 127;
  int stage_v_109_2 = (((stage_v_27_2 * 3) + pub_r001574_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = (((stage_v_28_1 * 3) + pub_r001574_19_1) + 14) & 127;
  int stage_v_110_2 = (((stage_v_28_2 * 3) + pub_r001574_19_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = ((pub_r001574_15_1 * 2) + 31) & 63;
  int stage_v_111_2 = ((pub_r001574_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001574_11_1 * 2) + 34) & 63;
  int stage_v_112_2 = ((pub_r001574_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001574_20_1 * 2) + 36) & 63;
  int stage_v_113_2 = ((pub_r001574_20_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001574_0_1 * 2) + 25) & 63;
  int stage_v_114_2 = ((pub_r001574_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001574_15_1 * 2) + 34) & 63;
  int stage_v_115_2 = ((pub_r001574_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001574_12_1 * 2) + 45) & 63;
  int stage_v_116_2 = ((pub_r001574_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((stage_v_33_1 * 3) + pub_r001574_8_1) + 29) & 127;
  int stage_v_117_2 = (((stage_v_33_2 * 3) + pub_r001574_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = (((stage_v_18_1 * 3) + pub_r001574_19_1) + 43) & 127;
  int stage_v_118_2 = (((stage_v_18_2 * 3) + pub_r001574_19_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = ((pub_r001574_11_1 * 2) + 38) & 63;
  int stage_v_119_2 = ((pub_r001574_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((helper_flow_4_1 * 3) + pub_r001574_11_1) + 17) & 127;
  int stage_v_120_2 = (((helper_flow_4_2 * 3) + pub_r001574_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = ((pub_r001574_2_1 * 2) + 46) & 63;
  int stage_v_121_2 = ((pub_r001574_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001574_18_1 * 2) + 30) & 63;
  int stage_v_122_2 = ((pub_r001574_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001574_4_1 * 2) + 47) & 63;
  int stage_v_123_2 = ((pub_r001574_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((stage_v_109_1 * 3) + pub_r001574_14_1) + 36) & 127;
  int stage_v_124_2 = (((stage_v_109_2 * 3) + pub_r001574_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = (((stage_v_4_1 * 3) + pub_r001574_8_1) + 32) & 127;
  int stage_v_125_2 = (((stage_v_4_2 * 3) + pub_r001574_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = (((stage_v_90_1 * 3) + pub_r001574_6_1) + 36) & 127;
  int stage_v_126_2 = (((stage_v_90_2 * 3) + pub_r001574_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = ((pub_r001574_18_1 * 2) + 42) & 63;
  int stage_v_127_2 = ((pub_r001574_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001574_15_1 * 2) + 7) & 63;
  int stage_v_128_2 = ((pub_r001574_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001574_17_1 * 2) + 28) & 63;
  int stage_v_129_2 = ((pub_r001574_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001574_6_1 * 2) + 8) & 63;
  int stage_v_130_2 = ((pub_r001574_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((stage_v_59_1 * 3) + pub_r001574_4_1) + 33) & 127;
  int stage_v_131_2 = (((stage_v_59_2 * 3) + pub_r001574_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = (((sec_r001574_15_1 * 3) + pub_r001574_13_1) + 11) & 127;
  int stage_v_132_2 = (((sec_r001574_15_2 * 3) + pub_r001574_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = (((stage_v_107_1 * 3) + pub_r001574_14_1) + 18) & 127;
  int stage_v_133_2 = (((stage_v_107_2 * 3) + pub_r001574_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((stage_v_132_1 * 3) + pub_r001574_19_1) + 45) & 127;
  int stage_v_134_2 = (((stage_v_132_2 * 3) + pub_r001574_19_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((stage_v_108_1 * 3) + pub_r001574_9_1) + 33) & 127;
  int stage_v_135_2 = (((stage_v_108_2 * 3) + pub_r001574_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((stage_v_85_1 * 3) + pub_r001574_16_1) + 45) & 127;
  int stage_v_136_2 = (((stage_v_85_2 * 3) + pub_r001574_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = ((pub_r001574_11_1 * 2) + 14) & 63;
  int stage_v_137_2 = ((pub_r001574_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001574_4_1 * 2) + 24) & 63;
  int stage_v_138_2 = ((pub_r001574_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((stage_v_88_1 * 3) + pub_r001574_15_1) + 41) & 127;
  int stage_v_139_2 = (((stage_v_88_2 * 3) + pub_r001574_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = (((sec_r001574_13_1 * 3) + pub_r001574_13_1) + 22) & 127;
  int stage_v_140_2 = (((sec_r001574_13_2 * 3) + pub_r001574_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = (((sec_r001574_4_1 * 3) + pub_r001574_10_1) + 10) & 127;
  int stage_v_141_2 = (((sec_r001574_4_2 * 3) + pub_r001574_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = (((sec_r001574_6_1 * 3) + pub_r001574_4_1) + 35) & 127;
  int stage_v_142_2 = (((sec_r001574_6_2 * 3) + pub_r001574_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = (((stage_v_32_1 * 3) + pub_r001574_16_1) + 38) & 127;
  int stage_v_143_2 = (((stage_v_32_2 * 3) + pub_r001574_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = (((stage_v_52_1 * 3) + pub_r001574_20_1) + 4) & 127;
  int stage_v_144_2 = (((stage_v_52_2 * 3) + pub_r001574_20_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = ((pub_r001574_9_1 * 2) + 24) & 63;
  int stage_v_145_2 = ((pub_r001574_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001574_6_1 * 2) + 12) & 63;
  int stage_v_146_2 = ((pub_r001574_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001574_16_1 * 2) + 13) & 63;
  int stage_v_147_2 = ((pub_r001574_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001574_4_1 * 2) + 25) & 63;
  int stage_v_148_2 = ((pub_r001574_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (((sec_r001574_10_1 * 3) + pub_r001574_8_1) + 14) & 127;
  int stage_v_149_2 = (((sec_r001574_10_2 * 3) + pub_r001574_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((stage_v_99_1 * 3) + pub_r001574_12_1) + 14) & 127;
  int stage_v_150_2 = (((stage_v_99_2 * 3) + pub_r001574_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = ((pub_r001574_10_1 * 2) + 28) & 63;
  int stage_v_151_2 = ((pub_r001574_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001574_9_1 * 2) + 11) & 63;
  int stage_v_152_2 = ((pub_r001574_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001574_11_1 * 2) + 36) & 63;
  int stage_v_153_2 = ((pub_r001574_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((stage_v_8_1 * 3) + pub_r001574_16_1) + 21) & 127;
  int stage_v_154_2 = (((stage_v_8_2 * 3) + pub_r001574_16_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = ((pub_r001574_6_1 * 2) + 43) & 63;
  int stage_v_155_2 = ((pub_r001574_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001574_2_1 * 2) + 32) & 63;
  int stage_v_156_2 = ((pub_r001574_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = (((sec_r001574_4_1 * 3) + pub_r001574_6_1) + 21) & 127;
  int stage_v_157_2 = (((sec_r001574_4_2 * 3) + pub_r001574_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = (((helper_flow_0_1 * 3) + pub_r001574_8_1) + 16) & 127;
  int stage_v_158_2 = (((helper_flow_0_2 * 3) + pub_r001574_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = (((sec_r001574_7_1 * 3) + pub_r001574_6_1) + 31) & 127;
  int stage_v_159_2 = (((sec_r001574_7_2 * 3) + pub_r001574_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = ((pub_r001574_6_1 * 2) + 33) & 63;
  int stage_v_160_2 = ((pub_r001574_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001574_15_1 * 2) + 29) & 63;
  int stage_v_161_2 = ((pub_r001574_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001574_13_1 * 2) + 22) & 63;
  int stage_v_162_2 = ((pub_r001574_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001574_12_1 * 2) + 38) & 63;
  int stage_v_163_2 = ((pub_r001574_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((stage_v_57_1 * 3) + pub_r001574_6_1) + 10) & 127;
  int stage_v_164_2 = (((stage_v_57_2 * 3) + pub_r001574_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = (((stage_v_104_1 * 3) + pub_r001574_14_1) + 6) & 127;
  int stage_v_165_2 = (((stage_v_104_2 * 3) + pub_r001574_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = (((helper_flow_2_1 * 3) + pub_r001574_5_1) + 6) & 127;
  int stage_v_166_2 = (((helper_flow_2_2 * 3) + pub_r001574_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = ((pub_r001574_7_1 * 2) + 18) & 63;
  int stage_v_167_2 = ((pub_r001574_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = (((sec_r001574_2_1 * 3) + pub_r001574_17_1) + 33) & 127;
  int stage_v_168_2 = (((sec_r001574_2_2 * 3) + pub_r001574_17_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = (((stage_v_56_1 * 3) + pub_r001574_2_1) + 43) & 127;
  int stage_v_169_2 = (((stage_v_56_2 * 3) + pub_r001574_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = ((pub_r001574_11_1 * 2) + 11) & 63;
  int stage_v_170_2 = ((pub_r001574_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (((sec_r001574_6_1 * 3) + pub_r001574_8_1) + 27) & 127;
  int stage_v_171_2 = (((sec_r001574_6_2 * 3) + pub_r001574_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = (((stage_v_73_1 * 3) + pub_r001574_13_1) + 4) & 127;
  int stage_v_172_2 = (((stage_v_73_2 * 3) + pub_r001574_13_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = (((stage_v_10_1 * 3) + pub_r001574_8_1) + 42) & 127;
  int stage_v_173_2 = (((stage_v_10_2 * 3) + pub_r001574_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = (((stage_v_171_1 * 3) + pub_r001574_4_1) + 29) & 127;
  int stage_v_174_2 = (((stage_v_171_2 * 3) + pub_r001574_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = ((pub_r001574_20_1 * 2) + 40) & 63;
  int stage_v_175_2 = ((pub_r001574_20_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001574_9_1 * 2) + 37) & 63;
  int stage_v_176_2 = ((pub_r001574_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (((stage_v_52_1 * 3) + pub_r001574_18_1) + 22) & 127;
  int stage_v_177_2 = (((stage_v_52_2 * 3) + pub_r001574_18_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = ((pub_r001574_9_1 * 2) + 21) & 63;
  int stage_v_178_2 = ((pub_r001574_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001574_15_1 * 2) + 18) & 63;
  int stage_v_179_2 = ((pub_r001574_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_93_1 * 3) + pub_r001574_8_1) + 42) & 127;
  int stage_v_180_2 = (((stage_v_93_2 * 3) + pub_r001574_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = (((stage_v_25_1 * 3) + pub_r001574_14_1) + 18) & 127;
  int stage_v_181_2 = (((stage_v_25_2 * 3) + pub_r001574_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = (((stage_v_86_1 * 3) + pub_r001574_17_1) + 8) & 127;
  int stage_v_182_2 = (((stage_v_86_2 * 3) + pub_r001574_17_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = ((pub_r001574_4_1 * 2) + 40) & 63;
  int stage_v_183_2 = ((pub_r001574_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001574_9_1 * 2) + 17) & 63;
  int stage_v_184_2 = ((pub_r001574_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((sec_r001574_7_1 * 3) + pub_r001574_6_1) + 7) & 127;
  int stage_v_185_2 = (((sec_r001574_7_2 * 3) + pub_r001574_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = (((stage_v_158_1 * 3) + pub_r001574_19_1) + 31) & 127;
  int stage_v_186_2 = (((stage_v_158_2 * 3) + pub_r001574_19_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = (((stage_v_61_1 * 3) + pub_r001574_15_1) + 35) & 127;
  int stage_v_187_2 = (((stage_v_61_2 * 3) + pub_r001574_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = ((pub_r001574_20_1 * 2) + 38) & 63;
  int stage_v_188_2 = ((pub_r001574_20_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((stage_v_58_1 * 3) + pub_r001574_18_1) + 44) & 127;
  int stage_v_189_2 = (((stage_v_58_2 * 3) + pub_r001574_18_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = ((pub_r001574_13_1 * 2) + 43) & 63;
  int stage_v_190_2 = ((pub_r001574_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001574_0_1 * 2) + 29) & 63;
  int stage_v_191_2 = ((pub_r001574_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = (((stage_v_182_1 * 3) + pub_r001574_17_1) + 20) & 127;
  int stage_v_192_2 = (((stage_v_182_2 * 3) + pub_r001574_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = (((stage_v_166_1 * 3) + pub_r001574_18_1) + 43) & 127;
  int stage_v_193_2 = (((stage_v_166_2 * 3) + pub_r001574_18_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001574_9_1 * 2) + 35) & 63;
  int stage_v_194_2 = ((pub_r001574_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (((stage_v_126_1 * 3) + pub_r001574_20_1) + 26) & 127;
  int stage_v_195_2 = (((stage_v_126_2 * 3) + pub_r001574_20_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = (((stage_v_81_1 * 3) + pub_r001574_16_1) + 18) & 127;
  int stage_v_196_2 = (((stage_v_81_2 * 3) + pub_r001574_16_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = (((stage_v_150_1 * 3) + pub_r001574_6_1) + 38) & 127;
  int stage_v_197_2 = (((stage_v_150_2 * 3) + pub_r001574_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = (((stage_v_158_1 * 3) + pub_r001574_0_1) + 3) & 127;
  int stage_v_198_2 = (((stage_v_158_2 * 3) + pub_r001574_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001574_16_1 * 2) + 11) & 63;
  int stage_v_199_2 = ((pub_r001574_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((stage_v_143_1 * 3) + pub_r001574_11_1) + 33) & 127;
  int stage_v_200_2 = (((stage_v_143_2 * 3) + pub_r001574_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = ((pub_r001574_7_1 * 2) + 50) & 63;
  int stage_v_201_2 = ((pub_r001574_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((sec_r001574_14_1 * 3) + pub_r001574_9_1) + 10) & 127;
  int stage_v_202_2 = (((sec_r001574_14_2 * 3) + pub_r001574_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = ((pub_r001574_12_1 * 2) + 22) & 63;
  int stage_v_203_2 = ((pub_r001574_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((sec_r001574_16_1 * 3) + pub_r001574_2_1) + 39) & 127;
  int stage_v_204_2 = (((sec_r001574_16_2 * 3) + pub_r001574_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = ((pub_r001574_18_1 * 2) + 9) & 63;
  int stage_v_205_2 = ((pub_r001574_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = (((stage_v_99_1 * 3) + pub_r001574_11_1) + 20) & 127;
  int stage_v_206_2 = (((stage_v_99_2 * 3) + pub_r001574_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = ((pub_r001574_11_1 * 2) + 9) & 63;
  int stage_v_207_2 = ((pub_r001574_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = (((stage_v_104_1 * 3) + pub_r001574_9_1) + 25) & 127;
  int stage_v_208_2 = (((stage_v_104_2 * 3) + pub_r001574_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = ((pub_r001574_5_1 * 2) + 48) & 63;
  int stage_v_209_2 = ((pub_r001574_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001574_9_1 * 2) + 33) & 63;
  int stage_v_210_2 = ((pub_r001574_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_180_1 * 3) + pub_r001574_3_1) + 23) & 127;
  int stage_v_211_2 = (((stage_v_180_2 * 3) + pub_r001574_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = (((stage_v_157_1 * 3) + pub_r001574_14_1) + 45) & 127;
  int stage_v_212_2 = (((stage_v_157_2 * 3) + pub_r001574_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = (((stage_v_208_1 * 3) + pub_r001574_2_1) + 38) & 127;
  int stage_v_213_2 = (((stage_v_208_2 * 3) + pub_r001574_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = (((helper_flow_2_1 * 3) + pub_r001574_6_1) + 26) & 127;
  int stage_v_214_2 = (((helper_flow_2_2 * 3) + pub_r001574_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = (((stage_v_143_1 * 3) + pub_r001574_20_1) + 45) & 127;
  int stage_v_215_2 = (((stage_v_143_2 * 3) + pub_r001574_20_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = ((pub_r001574_4_1 * 2) + 8) & 63;
  int stage_v_216_2 = ((pub_r001574_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001574_16_1 * 2) + 22) & 63;
  int stage_v_217_2 = ((pub_r001574_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001574_0_1 * 2) + 48) & 63;
  int stage_v_218_2 = ((pub_r001574_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001574_19_1 * 2) + 12) & 63;
  int stage_v_219_2 = ((pub_r001574_19_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001574_12_1 * 2) + 41) & 63;
  int stage_v_220_2 = ((pub_r001574_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = (((stage_v_124_1 * 3) + pub_r001574_13_1) + 14) & 127;
  int stage_v_221_2 = (((stage_v_124_2 * 3) + pub_r001574_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = ((pub_r001574_7_1 * 2) + 10) & 63;
  int stage_v_222_2 = ((pub_r001574_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = (((stage_v_202_1 * 3) + pub_r001574_8_1) + 44) & 127;
  int stage_v_223_2 = (((stage_v_202_2 * 3) + pub_r001574_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = ((pub_r001574_20_1 * 2) + 33) & 63;
  int stage_v_224_2 = ((pub_r001574_20_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_124_1 * 3) + pub_r001574_17_1) + 39) & 127;
  int stage_v_225_2 = (((stage_v_124_2 * 3) + pub_r001574_17_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = ((pub_r001574_19_1 * 2) + 35) & 63;
  int stage_v_226_2 = ((pub_r001574_19_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001574_18_1 * 2) + 34) & 63;
  int stage_v_227_2 = ((pub_r001574_18_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001574_20_1 * 2) + 26) & 63;
  int stage_v_228_2 = ((pub_r001574_20_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_0_1 * 3) + pub_r001574_2_1) + 24) & 127;
  int stage_v_229_2 = (((stage_v_0_2 * 3) + pub_r001574_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = ((pub_r001574_5_1 * 2) + 35) & 63;
  int stage_v_230_2 = ((pub_r001574_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001574_4_1 * 2) + 6) & 63;
  int stage_v_231_2 = ((pub_r001574_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = (((stage_v_88_1 * 3) + pub_r001574_16_1) + 20) & 127;
  int stage_v_232_2 = (((stage_v_88_2 * 3) + pub_r001574_16_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = ((pub_r001574_13_1 * 2) + 24) & 63;
  int stage_v_233_2 = ((pub_r001574_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = (((stage_v_214_1 * 3) + pub_r001574_0_1) + 42) & 127;
  int stage_v_234_2 = (((stage_v_214_2 * 3) + pub_r001574_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = (((sec_r001574_14_1 * 3) + pub_r001574_10_1) + 21) & 127;
  int stage_v_235_2 = (((sec_r001574_14_2 * 3) + pub_r001574_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = (((stage_v_234_1 * 3) + pub_r001574_0_1) + 25) & 127;
  int stage_v_236_2 = (((stage_v_234_2 * 3) + pub_r001574_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = ((pub_r001574_15_1 * 2) + 37) & 63;
  int stage_v_237_2 = ((pub_r001574_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = (((sec_r001574_1_1 * 3) + pub_r001574_8_1) + 34) & 127;
  int stage_v_238_2 = (((sec_r001574_1_2 * 3) + pub_r001574_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = (((sec_r001574_4_1 * 3) + pub_r001574_2_1) + 4) & 127;
  int stage_v_239_2 = (((sec_r001574_4_2 * 3) + pub_r001574_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = (((stage_v_125_1 * 3) + pub_r001574_14_1) + 41) & 127;
  int stage_v_240_2 = (((stage_v_125_2 * 3) + pub_r001574_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((stage_v_59_1 * 3) + pub_r001574_9_1) + 33) & 127;
  int stage_v_241_2 = (((stage_v_59_2 * 3) + pub_r001574_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((stage_v_225_1 * 3) + pub_r001574_6_1) + 8) & 127;
  int stage_v_242_2 = (((stage_v_225_2 * 3) + pub_r001574_6_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = ((pub_r001574_14_1 * 2) + 42) & 63;
  int stage_v_243_2 = ((pub_r001574_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((stage_v_208_1 * 3) + pub_r001574_7_1) + 27) & 127;
  int stage_v_244_2 = (((stage_v_208_2 * 3) + pub_r001574_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((sec_r001574_18_1 * 3) + pub_r001574_7_1) + 28) & 127;
  int stage_v_245_2 = (((sec_r001574_18_2 * 3) + pub_r001574_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = (((stage_v_164_1 * 3) + pub_r001574_3_1) + 8) & 127;
  int stage_v_246_2 = (((stage_v_164_2 * 3) + pub_r001574_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = ((pub_r001574_0_1 * 2) + 21) & 63;
  int stage_v_247_2 = ((pub_r001574_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001574_17_1 * 2) + 18) & 63;
  int stage_v_248_2 = ((pub_r001574_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = (((stage_v_90_1 * 3) + pub_r001574_6_1) + 25) & 127;
  int stage_v_249_2 = (((stage_v_90_2 * 3) + pub_r001574_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = ((pub_r001574_7_1 * 2) + 24) & 63;
  int stage_v_250_2 = ((pub_r001574_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001574_7_1 * 2) + 13) & 63;
  int stage_v_251_2 = ((pub_r001574_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = (((helper_flow_3_1 * 3) + pub_r001574_8_1) + 45) & 127;
  int stage_v_252_2 = (((helper_flow_3_2 * 3) + pub_r001574_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = (((sec_r001574_12_1 * 3) + pub_r001574_13_1) + 16) & 127;
  int stage_v_253_2 = (((sec_r001574_12_2 * 3) + pub_r001574_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = ((pub_r001574_7_1 * 2) + 38) & 63;
  int stage_v_254_2 = ((pub_r001574_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = (((stage_v_189_1 * 3) + pub_r001574_15_1) + 19) & 127;
  int stage_v_255_2 = (((stage_v_189_2 * 3) + pub_r001574_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = (((sec_r001574_16_1 * 3) + pub_r001574_4_1) + 34) & 127;
  int stage_v_256_2 = (((sec_r001574_16_2 * 3) + pub_r001574_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = ((pub_r001574_19_1 * 2) + 10) & 63;
  int stage_v_257_2 = ((pub_r001574_19_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_229_1 * 3) + pub_r001574_1_1) + 29) & 127;
  int stage_v_258_2 = (((stage_v_229_2 * 3) + pub_r001574_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = (((stage_v_68_1 * 3) + pub_r001574_2_1) + 35) & 127;
  int stage_v_259_2 = (((stage_v_68_2 * 3) + pub_r001574_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = (((stage_v_54_1 * 3) + pub_r001574_13_1) + 5) & 127;
  int stage_v_260_2 = (((stage_v_54_2 * 3) + pub_r001574_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = (((stage_v_241_1 * 3) + pub_r001574_6_1) + 8) & 127;
  int stage_v_261_2 = (((stage_v_241_2 * 3) + pub_r001574_6_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001574_7_1 * 2) + 27) & 63;
  int stage_v_262_2 = ((pub_r001574_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001574_18_1 * 2) + 7) & 63;
  int stage_v_263_2 = ((pub_r001574_18_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((pub_r001574_2_1 * 2) + 43) & 63;
  int stage_v_264_2 = ((pub_r001574_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((stage_v_132_1 * 3) + pub_r001574_17_1) + 20) & 127;
  int stage_v_265_2 = (((stage_v_132_2 * 3) + pub_r001574_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = ((pub_r001574_13_1 * 2) + 49) & 63;
  int stage_v_266_2 = ((pub_r001574_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001574_18_1 * 2) + 5) & 63;
  int stage_v_267_2 = ((pub_r001574_18_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = (((sec_r001574_7_1 * 3) + pub_r001574_2_1) + 45) & 127;
  int stage_v_268_2 = (((sec_r001574_7_2 * 3) + pub_r001574_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = (((stage_v_32_1 * 3) + pub_r001574_5_1) + 34) & 127;
  int stage_v_269_2 = (((stage_v_32_2 * 3) + pub_r001574_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = ((pub_r001574_18_1 * 2) + 12) & 63;
  int stage_v_270_2 = ((pub_r001574_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001574_16_1 * 2) + 10) & 63;
  int stage_v_271_2 = ((pub_r001574_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001574_7_1 * 2) + 43) & 63;
  int stage_v_272_2 = ((pub_r001574_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001574_0_1 * 2) + 27) & 63;
  int stage_v_273_2 = ((pub_r001574_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((pub_r001574_16_1 * 2) + 39) & 63;
  int stage_v_274_2 = ((pub_r001574_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001574_11_1 * 2) + 39) & 63;
  int stage_v_275_2 = ((pub_r001574_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = (((stage_v_97_1 * 3) + pub_r001574_17_1) + 18) & 127;
  int stage_v_276_2 = (((stage_v_97_2 * 3) + pub_r001574_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = ((pub_r001574_6_1 * 2) + 37) & 63;
  int stage_v_277_2 = ((pub_r001574_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((pub_r001574_3_1 * 2) + 45) & 63;
  int stage_v_278_2 = ((pub_r001574_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001574_5_1 * 2) + 43) & 63;
  int stage_v_279_2 = ((pub_r001574_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = (((stage_v_196_1 * 3) + pub_r001574_1_1) + 26) & 127;
  int stage_v_280_2 = (((stage_v_196_2 * 3) + pub_r001574_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = ((pub_r001574_0_1 * 2) + 50) & 63;
  int stage_v_281_2 = ((pub_r001574_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = (((stage_v_181_1 * 3) + pub_r001574_5_1) + 35) & 127;
  int stage_v_282_2 = (((stage_v_181_2 * 3) + pub_r001574_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = ((pub_r001574_15_1 * 2) + 15) & 63;
  int stage_v_283_2 = ((pub_r001574_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001574_7_1 * 2) + 25) & 63;
  int stage_v_284_2 = ((pub_r001574_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = (((stage_v_35_1 * 3) + pub_r001574_15_1) + 41) & 127;
  int stage_v_285_2 = (((stage_v_35_2 * 3) + pub_r001574_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = (((stage_v_10_1 * 3) + pub_r001574_3_1) + 31) & 127;
  int stage_v_286_2 = (((stage_v_10_2 * 3) + pub_r001574_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = (((stage_v_196_1 * 3) + pub_r001574_4_1) + 44) & 127;
  int stage_v_287_2 = (((stage_v_196_2 * 3) + pub_r001574_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((stage_v_1_1 * 3) + pub_r001574_0_1) + 42) & 127;
  int stage_v_288_2 = (((stage_v_1_2 * 3) + pub_r001574_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = ((pub_r001574_3_1 * 2) + 33) & 63;
  int stage_v_289_2 = ((pub_r001574_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = (((stage_v_132_1 * 3) + pub_r001574_4_1) + 20) & 127;
  int stage_v_290_2 = (((stage_v_132_2 * 3) + pub_r001574_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = ((pub_r001574_16_1 * 2) + 29) & 63;
  int stage_v_291_2 = ((pub_r001574_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = (((sec_r001574_2_1 * 3) + pub_r001574_8_1) + 7) & 127;
  int stage_v_292_2 = (((sec_r001574_2_2 * 3) + pub_r001574_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = ((pub_r001574_10_1 * 2) + 16) & 63;
  int stage_v_293_2 = ((pub_r001574_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001574_5_1 * 2) + 43) & 63;
  int stage_v_294_2 = ((pub_r001574_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = (((stage_v_253_1 * 3) + pub_r001574_3_1) + 3) & 127;
  int stage_v_295_2 = (((stage_v_253_2 * 3) + pub_r001574_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = ((pub_r001574_17_1 * 2) + 17) & 63;
  int stage_v_296_2 = ((pub_r001574_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001574_6_1 * 2) + 10) & 63;
  int stage_v_297_2 = ((pub_r001574_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((stage_v_43_1 * 3) + pub_r001574_15_1) + 17) & 127;
  int stage_v_298_2 = (((stage_v_43_2 * 3) + pub_r001574_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001574_7_1 * 2) + 48) & 63;
  int stage_v_299_2 = ((pub_r001574_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001574_4_1 * 2) + 50) & 63;
  int stage_v_300_2 = ((pub_r001574_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = (((stage_v_259_1 * 3) + pub_r001574_6_1) + 44) & 127;
  int stage_v_301_2 = (((stage_v_259_2 * 3) + pub_r001574_6_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = ((pub_r001574_6_1 * 2) + 41) & 63;
  int stage_v_302_2 = ((pub_r001574_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = (((stage_v_73_1 * 3) + pub_r001574_15_1) + 26) & 127;
  int stage_v_303_2 = (((stage_v_73_2 * 3) + pub_r001574_15_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001574_9_1 * 2) + 18) & 63;
  int stage_v_304_2 = ((pub_r001574_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001574_4_1 * 2) + 7) & 63;
  int stage_v_305_2 = ((pub_r001574_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001574_10_1 * 2) + 34) & 63;
  int stage_v_306_2 = ((pub_r001574_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001574_18_1 * 2) + 35) & 63;
  int stage_v_307_2 = ((pub_r001574_18_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = (((stage_v_80_1 * 3) + pub_r001574_19_1) + 24) & 127;
  int stage_v_308_2 = (((stage_v_80_2 * 3) + pub_r001574_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = ((pub_r001574_11_1 * 2) + 15) & 63;
  int stage_v_309_2 = ((pub_r001574_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001574_18_1 * 2) + 40) & 63;
  int stage_v_310_2 = ((pub_r001574_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((pub_r001574_6_1 * 2) + 41) & 63;
  int stage_v_311_2 = ((pub_r001574_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = (((stage_v_107_1 * 3) + pub_r001574_12_1) + 43) & 127;
  int stage_v_312_2 = (((stage_v_107_2 * 3) + pub_r001574_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = (((stage_v_259_1 * 3) + pub_r001574_4_1) + 10) & 127;
  int stage_v_313_2 = (((stage_v_259_2 * 3) + pub_r001574_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001574_2_1 * 2) + 9) & 63;
  int stage_v_314_2 = ((pub_r001574_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001574_8_1 * 2) + 30) & 63;
  int stage_v_315_2 = ((pub_r001574_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001574_0_1 * 2) + 32) & 63;
  int stage_v_316_2 = ((pub_r001574_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = (((stage_v_206_1 * 3) + pub_r001574_11_1) + 40) & 127;
  int stage_v_317_2 = (((stage_v_206_2 * 3) + pub_r001574_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = (((stage_v_57_1 * 3) + pub_r001574_12_1) + 35) & 127;
  int stage_v_318_2 = (((stage_v_57_2 * 3) + pub_r001574_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = ((pub_r001574_11_1 * 2) + 16) & 63;
  int stage_v_319_2 = ((pub_r001574_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001574_7_1 * 2) + 46) & 63;
  int stage_v_320_2 = ((pub_r001574_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = (((stage_v_214_1 * 3) + pub_r001574_9_1) + 9) & 127;
  int stage_v_321_2 = (((stage_v_214_2 * 3) + pub_r001574_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = ((pub_r001574_19_1 * 2) + 39) & 63;
  int stage_v_322_2 = ((pub_r001574_19_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = (((stage_v_211_1 * 3) + pub_r001574_0_1) + 31) & 127;
  int stage_v_323_2 = (((stage_v_211_2 * 3) + pub_r001574_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = (((stage_v_172_1 * 3) + pub_r001574_12_1) + 29) & 127;
  int stage_v_324_2 = (((stage_v_172_2 * 3) + pub_r001574_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = ((pub_r001574_2_1 * 2) + 23) & 63;
  int stage_v_325_2 = ((pub_r001574_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = (((sec_r001574_20_1 * 3) + pub_r001574_6_1) + 30) & 127;
  int stage_v_326_2 = (((sec_r001574_20_2 * 3) + pub_r001574_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = (((stage_v_260_1 * 3) + pub_r001574_12_1) + 41) & 127;
  int stage_v_327_2 = (((stage_v_260_2 * 3) + pub_r001574_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = (((stage_v_73_1 * 3) + pub_r001574_20_1) + 17) & 127;
  int stage_v_328_2 = (((stage_v_73_2 * 3) + pub_r001574_20_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = ((pub_r001574_7_1 * 2) + 23) & 63;
  int stage_v_329_2 = ((pub_r001574_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001574_20_1 * 2) + 46) & 63;
  int stage_v_330_2 = ((pub_r001574_20_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001574_4_1 * 2) + 27) & 63;
  int stage_v_331_2 = ((pub_r001574_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = (((stage_v_202_1 * 3) + pub_r001574_10_1) + 24) & 127;
  int stage_v_332_2 = (((stage_v_202_2 * 3) + pub_r001574_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((stage_v_223_1 * 3) + pub_r001574_15_1) + 45) & 127;
  int stage_v_333_2 = (((stage_v_223_2 * 3) + pub_r001574_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = (((sec_r001574_7_1 * 3) + pub_r001574_9_1) + 4) & 127;
  int stage_v_334_2 = (((sec_r001574_7_2 * 3) + pub_r001574_9_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = ((pub_r001574_15_1 * 2) + 5) & 63;
  int stage_v_335_2 = ((pub_r001574_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((pub_r001574_8_1 * 2) + 8) & 63;
  int stage_v_336_2 = ((pub_r001574_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = (((stage_v_298_1 * 3) + pub_r001574_15_1) + 4) & 127;
  int stage_v_337_2 = (((stage_v_298_2 * 3) + pub_r001574_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = ((pub_r001574_8_1 * 2) + 15) & 63;
  int stage_v_338_2 = ((pub_r001574_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((pub_r001574_13_1 * 2) + 41) & 63;
  int stage_v_339_2 = ((pub_r001574_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = (((stage_v_197_1 * 3) + pub_r001574_6_1) + 13) & 127;
  int stage_v_340_2 = (((stage_v_197_2 * 3) + pub_r001574_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = (((stage_v_173_1 * 3) + pub_r001574_10_1) + 12) & 127;
  int stage_v_341_2 = (((stage_v_173_2 * 3) + pub_r001574_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = ((pub_r001574_2_1 * 2) + 43) & 63;
  int stage_v_342_2 = ((pub_r001574_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = (((helper_flow_3_1 * 3) + pub_r001574_19_1) + 9) & 127;
  int stage_v_343_2 = (((helper_flow_3_2 * 3) + pub_r001574_19_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_10_1 * 3) + pub_r001574_14_1) + 15) & 127;
  int stage_v_344_2 = (((stage_v_10_2 * 3) + pub_r001574_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001574_3_1 * 2) + 5) & 63;
  int stage_v_345_2 = ((pub_r001574_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = (((stage_v_38_1 * 3) + pub_r001574_2_1) + 8) & 127;
  int stage_v_346_2 = (((stage_v_38_2 * 3) + pub_r001574_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = (((stage_v_85_1 * 3) + pub_r001574_3_1) + 33) & 127;
  int stage_v_347_2 = (((stage_v_85_2 * 3) + pub_r001574_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = (((stage_v_234_1 * 3) + pub_r001574_20_1) + 44) & 127;
  int stage_v_348_2 = (((stage_v_234_2 * 3) + pub_r001574_20_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_333_1 * 3) + pub_r001574_10_1) + 45) & 127;
  int stage_v_349_2 = (((stage_v_333_2 * 3) + pub_r001574_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((sec_r001574_9_1 * 3) + pub_r001574_19_1) + 23) & 127;
  int stage_v_350_2 = (((sec_r001574_9_2 * 3) + pub_r001574_19_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = ((pub_r001574_13_1 * 2) + 28) & 63;
  int stage_v_351_2 = ((pub_r001574_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001574_13_1 * 2) + 36) & 63;
  int stage_v_352_2 = ((pub_r001574_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = (((stage_v_308_1 * 3) + pub_r001574_14_1) + 20) & 127;
  int stage_v_353_2 = (((stage_v_308_2 * 3) + pub_r001574_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = ((pub_r001574_14_1 * 2) + 33) & 63;
  int stage_v_354_2 = ((pub_r001574_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001574_7_1 * 2) + 36) & 63;
  int stage_v_355_2 = ((pub_r001574_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = (((stage_v_323_1 * 3) + pub_r001574_15_1) + 37) & 127;
  int stage_v_356_2 = (((stage_v_323_2 * 3) + pub_r001574_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = (((stage_v_214_1 * 3) + pub_r001574_7_1) + 28) & 127;
  int stage_v_357_2 = (((stage_v_214_2 * 3) + pub_r001574_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = ((pub_r001574_4_1 * 2) + 14) & 63;
  int stage_v_358_2 = ((pub_r001574_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = (((stage_v_140_1 * 3) + pub_r001574_19_1) + 11) & 127;
  int stage_v_359_2 = (((stage_v_140_2 * 3) + pub_r001574_19_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = ((pub_r001574_7_1 * 2) + 29) & 63;
  int stage_v_360_2 = ((pub_r001574_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((pub_r001574_4_1 * 2) + 30) & 63;
  int stage_v_361_2 = ((pub_r001574_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = (((stage_v_131_1 * 3) + pub_r001574_3_1) + 5) & 127;
  int stage_v_362_2 = (((stage_v_131_2 * 3) + pub_r001574_3_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = (((stage_v_140_1 * 3) + pub_r001574_14_1) + 7) & 127;
  int stage_v_363_2 = (((stage_v_140_2 * 3) + pub_r001574_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = ((pub_r001574_8_1 * 2) + 16) & 63;
  int stage_v_364_2 = ((pub_r001574_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = (((stage_v_66_1 * 3) + pub_r001574_6_1) + 13) & 127;
  int stage_v_365_2 = (((stage_v_66_2 * 3) + pub_r001574_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = (((stage_v_211_1 * 3) + pub_r001574_8_1) + 18) & 127;
  int stage_v_366_2 = (((stage_v_211_2 * 3) + pub_r001574_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = (((stage_v_357_1 * 3) + pub_r001574_8_1) + 33) & 127;
  int stage_v_367_2 = (((stage_v_357_2 * 3) + pub_r001574_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = (((stage_v_260_1 * 3) + pub_r001574_14_1) + 10) & 127;
  int stage_v_368_2 = (((stage_v_260_2 * 3) + pub_r001574_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = (((stage_v_187_1 * 3) + pub_r001574_4_1) + 8) & 127;
  int stage_v_369_2 = (((stage_v_187_2 * 3) + pub_r001574_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = ((pub_r001574_2_1 * 2) + 26) & 63;
  int stage_v_370_2 = ((pub_r001574_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = (((helper_flow_3_1 * 3) + pub_r001574_3_1) + 23) & 127;
  int stage_v_371_2 = (((helper_flow_3_2 * 3) + pub_r001574_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = (((stage_v_174_1 * 3) + pub_r001574_4_1) + 12) & 127;
  int stage_v_372_2 = (((stage_v_174_2 * 3) + pub_r001574_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = ((pub_r001574_1_1 * 2) + 25) & 63;
  int stage_v_373_2 = ((pub_r001574_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((pub_r001574_6_1 * 2) + 10) & 63;
  int stage_v_374_2 = ((pub_r001574_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = (((sec_r001574_8_1 * 3) + pub_r001574_5_1) + 15) & 127;
  int stage_v_375_2 = (((sec_r001574_8_2 * 3) + pub_r001574_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001574_8_1 * 2) + 49) & 63;
  int stage_v_376_2 = ((pub_r001574_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001574_13_1 * 2) + 35) & 63;
  int stage_v_377_2 = ((pub_r001574_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((pub_r001574_11_1 * 2) + 49) & 63;
  int stage_v_378_2 = ((pub_r001574_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = ((pub_r001574_4_1 * 2) + 44) & 63;
  int stage_v_379_2 = ((pub_r001574_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = (((stage_v_324_1 * 3) + pub_r001574_14_1) + 45) & 127;
  int stage_v_380_2 = (((stage_v_324_2 * 3) + pub_r001574_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = ((pub_r001574_7_1 * 2) + 9) & 63;
  int stage_v_381_2 = ((pub_r001574_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = (((stage_v_232_1 * 3) + pub_r001574_13_1) + 20) & 127;
  int stage_v_382_2 = (((stage_v_232_2 * 3) + pub_r001574_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = (((stage_v_164_1 * 3) + pub_r001574_10_1) + 30) & 127;
  int stage_v_383_2 = (((stage_v_164_2 * 3) + pub_r001574_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = (((stage_v_214_1 * 3) + pub_r001574_7_1) + 7) & 127;
  int stage_v_384_2 = (((stage_v_214_2 * 3) + pub_r001574_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = ((pub_r001574_19_1 * 2) + 26) & 63;
  int stage_v_385_2 = ((pub_r001574_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001574_8_1 * 2) + 18) & 63;
  int stage_v_386_2 = ((pub_r001574_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001574_19_1 * 2) + 16) & 63;
  int stage_v_387_2 = ((pub_r001574_19_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = (((stage_v_52_1 * 3) + pub_r001574_16_1) + 37) & 127;
  int stage_v_388_2 = (((stage_v_52_2 * 3) + pub_r001574_16_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = (((helper_flow_4_1 * 3) + pub_r001574_20_1) + 23) & 127;
  int stage_v_389_2 = (((helper_flow_4_2 * 3) + pub_r001574_20_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = (((stage_v_268_1 * 3) + pub_r001574_8_1) + 25) & 127;
  int stage_v_390_2 = (((stage_v_268_2 * 3) + pub_r001574_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001574_12_1 != sec_r001574_12_2);
  __CPROVER_assume(sec_r001574_15_1 != sec_r001574_15_2);
  __CPROVER_assume(pub_r001574_8_1 == pub_r001574_8_2);
  __CPROVER_assume(pub_r001574_2_1 == pub_r001574_2_2);
  __CPROVER_assume(pub_r001574_9_1 == pub_r001574_9_2);
  __CPROVER_assume(pub_r001574_18_1 == pub_r001574_18_2);
  __CPROVER_assume(pub_r001574_1_1 == pub_r001574_1_2);
  __CPROVER_assume(sec_r001574_6_1 != sec_r001574_6_2);
  __CPROVER_assume(pub_r001574_7_1 == pub_r001574_7_2);
  __CPROVER_assume(sec_r001574_16_1 != sec_r001574_16_2);
  __CPROVER_assume(pub_r001574_11_1 == pub_r001574_11_2);
  __CPROVER_assume(sec_r001574_14_1 != sec_r001574_14_2);
  __CPROVER_assume(pub_r001574_10_1 == pub_r001574_10_2);
  __CPROVER_assume(sec_r001574_2_1 != sec_r001574_2_2);
  __CPROVER_assume(sec_r001574_19_1 != sec_r001574_19_2);
  __CPROVER_assume(pub_r001574_0_1 == pub_r001574_0_2);
  __CPROVER_assume(pub_r001574_16_1 == pub_r001574_16_2);
  __CPROVER_assume(pub_r001574_19_1 == pub_r001574_19_2);
  __CPROVER_assume(sec_r001574_17_1 != sec_r001574_17_2);
  __CPROVER_assume(pub_r001574_14_1 == pub_r001574_14_2);
  __CPROVER_assume(pub_r001574_20_1 == pub_r001574_20_2);
  __CPROVER_assume(sec_r001574_8_1 != sec_r001574_8_2);
  __CPROVER_assume(sec_r001574_18_1 != sec_r001574_18_2);
  __CPROVER_assume(pub_r001574_3_1 == pub_r001574_3_2);
  __CPROVER_assume(pub_r001574_6_1 == pub_r001574_6_2);
  __CPROVER_assume(sec_r001574_9_1 != sec_r001574_9_2);
  __CPROVER_assume(pub_r001574_13_1 == pub_r001574_13_2);
  __CPROVER_assume(pub_r001574_17_1 == pub_r001574_17_2);
  __CPROVER_assume(sec_r001574_4_1 != sec_r001574_4_2);
  __CPROVER_assume(sec_r001574_5_1 != sec_r001574_5_2);
  __CPROVER_assume(sec_r001574_0_1 != sec_r001574_0_2);
  __CPROVER_assume(sec_r001574_10_1 != sec_r001574_10_2);
  __CPROVER_assume(pub_r001574_12_1 == pub_r001574_12_2);
  __CPROVER_assume(pub_r001574_15_1 == pub_r001574_15_2);
  __CPROVER_assume(pub_r001574_5_1 == pub_r001574_5_2);
  __CPROVER_assume(sec_r001574_20_1 != sec_r001574_20_2);
  __CPROVER_assume(sec_r001574_13_1 != sec_r001574_13_2);
  __CPROVER_assume(sec_r001574_3_1 != sec_r001574_3_2);
  __CPROVER_assume(pub_r001574_4_1 == pub_r001574_4_2);
  __CPROVER_assume(sec_r001574_1_1 != sec_r001574_1_2);
  __CPROVER_assume(sec_r001574_7_1 != sec_r001574_7_2);
  __CPROVER_assume(sec_r001574_11_1 != sec_r001574_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  assert(st_var_1_1.rate == st_var_1_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.pitch == st_var_2_2.pitch);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.sample_rate == st_var_3_2.sample_rate);
  assert(st_var_3_1.envelope == st_var_3_2.envelope);
  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.peak == st_var_3_2.peak);
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
}


