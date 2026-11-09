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
struct Vector3D_R001330_3013_0
{
  int coord_z;
  int pitch;
  int norm_sq;
  int buffer[3];
};
struct MatrixBlock_R001330_3013_1
{
  int stride;
  int density;
  short determinant;
  int trace;
  int scale;
  int dim;
  int buffer[3];
};
struct StreamBuffer_R001330_3013_2
{
  int state;
  int head;
  short watermark;
  short checksum;
  int buffer[3];
};
struct CipherContext_R001330_3013_3
{
  int nonce;
  short round_key;
  short iv;
  unsigned char flags;
  short tag;
  int buffer[3];
};
union PacketPayload_R001330_3013_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001330_3013_1
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
void fn_R001330_3013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001330_3013_1 st_1 = {0};
  struct MatrixBlock_R001330_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int phase_75_1 = 0;
  int phase_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_75_1 = ((phase_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_75_2 = ((phase_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_75_1) & 127;
    acc_2 = (acc_2 + phase_75_2) & 127;
  }

  int tracker_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_93_1 > 29)
  {
    acc_1 = ((acc_1 + (tracker_93_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_93_2 > 29)
  {
    acc_2 = ((acc_2 + (tracker_93_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_93_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_75_1 == phase_75_2);
  assert(tracker_93_1 == tracker_93_2);
}

int fn_R001330_3013_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001330_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int phase_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_75 = ((phase_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_75) & 127;
  }

  int tracker_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_93 > 29)
  {
    acc = ((acc + (tracker_93 * 2)) + 5) & 127;
    aux ^= tracker_93 & 15;
  }
  else
  {
    acc = ((acc - tracker_93) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001330_3013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001330_3013_3 st_1 = {0};
  struct CipherContext_R001330_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_62_1 = local_arr_1[aux_1 % 3];
  int delta_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_62_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_45_1 > 42)
  {
    acc_1 = ((acc_1 + (sample_45_1 * 2)) + 5) & 127;
    aux_1 ^= sample_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_45_2 > 42)
  {
    acc_2 = ((acc_2 + (sample_45_2 * 2)) + 5) & 127;
    aux_2 ^= sample_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_45_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_62_1 == delta_62_2);
  assert(sample_45_1 == sample_45_2);
}

int fn_R001330_3013_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001330_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int delta_62 = local_arr[aux % 3];
  acc = (acc + (delta_62 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_45 > 42)
  {
    acc = ((acc + (sample_45 * 2)) + 5) & 127;
    aux ^= sample_45 & 15;
  }
  else
  {
    acc = ((acc - sample_45) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001330_3013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001330_3013_1 st_1 = {0};
  struct MatrixBlock_R001330_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int residue_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_46_1 > 35)
  {
    acc_1 = ((acc_1 + (residue_46_1 * 2)) + 5) & 127;
    aux_1 ^= residue_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_46_2 > 35)
  {
    acc_2 = ((acc_2 + (residue_46_2 * 2)) + 5) & 127;
    aux_2 ^= residue_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_78_1)
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

  switch (margin_78_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_46_1 == residue_46_2);
  assert(margin_78_1 == margin_78_2);
}

int fn_R001330_3013_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001330_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int residue_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_46 > 35)
  {
    acc = ((acc + (residue_46 * 2)) + 5) & 127;
    aux ^= residue_46 & 15;
  }
  else
  {
    acc = ((acc - residue_46) + 11) & 127;
    aux += 3;
  }
  int margin_78 = (aux + st.buffer[1]) & 3;
  switch (margin_78)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001330_3013_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001330_3013_0 st_1 = {0};
  struct Vector3D_R001330_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_31_1 = local_arr_1[aux_1 % 3];
  int threshold_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_31_2 * 2)) & 127;
  int index_reg_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_31_1) & 63;
  aux_2 = (aux_2 + index_reg_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_37_1 = 0;
  int anchor_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_37_1 = ((anchor_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_37_2 = ((anchor_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_37_1) & 127;
    acc_2 = (acc_2 + anchor_37_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_31_1 == threshold_31_2);
  assert(index_reg_31_1 == index_reg_31_2);
  assert(anchor_37_1 == anchor_37_2);
}

int fn_R001330_3013_3(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001330_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int threshold_31 = local_arr[aux % 3];
  acc = (acc + (threshold_31 * 2)) & 127;
  int index_reg_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_31) & 63;
  acc ^= aux;
  int anchor_37 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_37 = ((anchor_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_37) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001330_3013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001330_3013_1 st_1 = {0};
  struct MatrixBlock_R001330_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int scale_67_1 = 0;
  int scale_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_67_1 = ((scale_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_67_2 = ((scale_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_67_1) & 127;
    acc_2 = (acc_2 + scale_67_2) & 127;
  }

  int delta_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_51_1) & 63;
  aux_2 = (aux_2 + delta_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_84_1 > 40)
  {
    acc_1 = ((acc_1 + (mask_84_1 * 2)) + 5) & 127;
    aux_1 ^= mask_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_84_2 > 40)
  {
    acc_2 = ((acc_2 + (mask_84_2 * 2)) + 5) & 127;
    aux_2 ^= mask_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_36_1 = local_arr_1[aux_1 % 3];
  int accumulator_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_67_1 == scale_67_2);
  assert(delta_51_1 == delta_51_2);
  assert(mask_84_1 == mask_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_36_1 == accumulator_36_2);
}

int fn_R001330_3013_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001330_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int scale_67 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_67 = ((scale_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_67) & 127;
  }

  int delta_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_51) & 63;
  acc ^= aux;
  int mask_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_84 > 40)
  {
    acc = ((acc + (mask_84 * 2)) + 5) & 127;
    aux ^= mask_84 & 15;
  }
  else
  {
    acc = ((acc - mask_84) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_36 = local_arr[aux % 3];
  acc = (acc + (accumulator_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001330_3013_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001330_3013_2 st_1 = {0};
  struct StreamBuffer_R001330_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int metric_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_87_1) & 63;
  aux_2 = (aux_2 + metric_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_21_1 > 13)
  {
    acc_1 = ((acc_1 + (anchor_21_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_21_2 > 13)
  {
    acc_2 = ((acc_2 + (anchor_21_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_21_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_87_1 == metric_87_2);
  assert(anchor_21_1 == anchor_21_2);
}

int fn_R001330_3013_5(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001330_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int metric_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_87) & 63;
  acc ^= aux;
  int anchor_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_21 > 13)
  {
    acc = ((acc + (anchor_21 * 2)) + 5) & 127;
    aux ^= anchor_21 & 15;
  }
  else
  {
    acc = ((acc - anchor_21) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001330_3013_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001330_3013_2 st_1 = {0};
  struct StreamBuffer_R001330_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int margin_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_95_1) & 63;
  aux_2 = (aux_2 + margin_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_10_1 = 0;
  int quantum_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_10_1 = ((quantum_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_10_2 = ((quantum_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_10_1) & 127;
    acc_2 = (acc_2 + quantum_10_2) & 127;
  }

  int mask_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_96_1)
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

  switch (mask_96_2)
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

  int residue_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_99_1 > 24)
  {
    acc_1 = ((acc_1 + (residue_99_1 * 2)) + 5) & 127;
    aux_1 ^= residue_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_99_2 > 24)
  {
    acc_2 = ((acc_2 + (residue_99_2 * 2)) + 5) & 127;
    aux_2 ^= residue_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_95_1 == margin_95_2);
  assert(quantum_10_1 == quantum_10_2);
  assert(mask_96_1 == mask_96_2);
  assert(residue_99_1 == residue_99_2);
}

int fn_R001330_3013_6(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001330_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int margin_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_95) & 63;
  acc ^= aux;
  int quantum_10 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_10 = ((quantum_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_10) & 127;
  }

  int mask_96 = (aux + st.buffer[1]) & 3;
  switch (mask_96)
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

  int residue_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_99 > 24)
  {
    acc = ((acc + (residue_99 * 2)) + 5) & 127;
    aux ^= residue_99 & 15;
  }
  else
  {
    acc = ((acc - residue_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001330_3013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001330_3013_3 st_1 = {0};
  struct CipherContext_R001330_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_97_1 = local_arr_1[aux_1 % 3];
  int offset_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_97_2 * 2)) & 127;
  int scale_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_32_1 > 24)
  {
    acc_1 = ((acc_1 + (scale_32_1 * 2)) + 5) & 127;
    aux_1 ^= scale_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_32_2 > 24)
  {
    acc_2 = ((acc_2 + (scale_32_2 * 2)) + 5) & 127;
    aux_2 ^= scale_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_46_1)
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

  switch (residue_46_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_97_1 == offset_97_2);
  assert(scale_32_1 == scale_32_2);
  assert(residue_46_1 == residue_46_2);
}

int fn_R001330_3013_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001330_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int offset_97 = local_arr[aux % 3];
  acc = (acc + (offset_97 * 2)) & 127;
  int scale_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_32 > 24)
  {
    acc = ((acc + (scale_32 * 2)) + 5) & 127;
    aux ^= scale_32 & 15;
  }
  else
  {
    acc = ((acc - scale_32) + 11) & 127;
    aux += 3;
  }
  int residue_46 = (aux + st.buffer[1]) & 3;
  switch (residue_46)
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

void fn_R001330_3013_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001330_3013_2 st_1 = {0};
  struct StreamBuffer_R001330_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int delta_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_98_1 > 35)
  {
    acc_1 = ((acc_1 + (delta_98_1 * 2)) + 5) & 127;
    aux_1 ^= delta_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_98_2 > 35)
  {
    acc_2 = ((acc_2 + (delta_98_2 * 2)) + 5) & 127;
    aux_2 ^= delta_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_15_1)
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

  switch (parity_15_2)
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
  int factor_63_1 = local_arr_1[aux_1 % 3];
  int factor_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_63_2 * 2)) & 127;
  int checksum_41_1 = 0;
  int checksum_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_41_1 = ((checksum_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_41_2 = ((checksum_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_41_1) & 127;
    acc_2 = (acc_2 + checksum_41_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_98_1 == delta_98_2);
  assert(parity_15_1 == parity_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_63_1 == factor_63_2);
  assert(checksum_41_1 == checksum_41_2);
}

int fn_R001330_3013_8(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001330_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int delta_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_98 > 35)
  {
    acc = ((acc + (delta_98 * 2)) + 5) & 127;
    aux ^= delta_98 & 15;
  }
  else
  {
    acc = ((acc - delta_98) + 11) & 127;
    aux += 3;
  }
  int parity_15 = (aux + st.buffer[1]) & 3;
  switch (parity_15)
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
  int factor_63 = local_arr[aux % 3];
  acc = (acc + (factor_63 * 2)) & 127;
  int checksum_41 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_41 = ((checksum_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_41) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001330_3013_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001330_3013_1 st_1 = {0};
  struct MatrixBlock_R001330_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int checksum_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_30_1 > 43)
  {
    acc_1 = ((acc_1 + (checksum_30_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_30_2 > 43)
  {
    acc_2 = ((acc_2 + (checksum_30_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_30_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_34_1 = 0;
  int window_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_34_1 = ((window_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_34_2 = ((window_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_34_1) & 127;
    acc_2 = (acc_2 + window_34_2) & 127;
  }

  int tracker_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_80_1)
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

  switch (tracker_80_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_30_1 == checksum_30_2);
  assert(window_34_1 == window_34_2);
  assert(tracker_80_1 == tracker_80_2);
}

int fn_R001330_3013_9(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001330_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int checksum_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_30 > 43)
  {
    acc = ((acc + (checksum_30 * 2)) + 5) & 127;
    aux ^= checksum_30 & 15;
  }
  else
  {
    acc = ((acc - checksum_30) + 11) & 127;
    aux += 3;
  }
  int window_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_34 = ((window_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_34) & 127;
  }

  int tracker_80 = (aux + st.buffer[1]) & 3;
  switch (tracker_80)
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

void fn_R001330_3013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001330_3013_3 st_1 = {0};
  struct CipherContext_R001330_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_10_1 = local_arr_1[aux_1 % 3];
  int quantum_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_10_2 * 2)) & 127;
  int metric_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_91_1 > 10)
  {
    acc_1 = ((acc_1 + (metric_91_1 * 2)) + 5) & 127;
    aux_1 ^= metric_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_91_2 > 10)
  {
    acc_2 = ((acc_2 + (metric_91_2 * 2)) + 5) & 127;
    aux_2 ^= metric_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_99_1)
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

  switch (weight_99_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_10_1 == quantum_10_2);
  assert(metric_91_1 == metric_91_2);
  assert(weight_99_1 == weight_99_2);
}

int fn_R001330_3013_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001330_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int quantum_10 = local_arr[aux % 3];
  acc = (acc + (quantum_10 * 2)) & 127;
  int metric_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_91 > 10)
  {
    acc = ((acc + (metric_91 * 2)) + 5) & 127;
    aux ^= metric_91 & 15;
  }
  else
  {
    acc = ((acc - metric_91) + 11) & 127;
    aux += 3;
  }
  int weight_99 = (aux + st.buffer[1]) & 3;
  switch (weight_99)
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

void fn_R001330_3013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001330_3013_3 st_1 = {0};
  struct CipherContext_R001330_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int stride_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_33_1 > 45)
  {
    acc_1 = ((acc_1 + (stride_33_1 * 2)) + 5) & 127;
    aux_1 ^= stride_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_33_2 > 45)
  {
    acc_2 = ((acc_2 + (stride_33_2 * 2)) + 5) & 127;
    aux_2 ^= stride_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_47_1 = 0;
  int threshold_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_47_1 = ((threshold_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_47_2 = ((threshold_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_47_1) & 127;
    acc_2 = (acc_2 + threshold_47_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_33_1 == stride_33_2);
  assert(threshold_47_1 == threshold_47_2);
}

int fn_R001330_3013_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001330_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int stride_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_33 > 45)
  {
    acc = ((acc + (stride_33 * 2)) + 5) & 127;
    aux ^= stride_33 & 15;
  }
  else
  {
    acc = ((acc - stride_33) + 11) & 127;
    aux += 3;
  }
  int threshold_47 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_47 = ((threshold_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_47) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001330_3013_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001330_3013_0 st_1 = {0};
  struct Vector3D_R001330_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_35_1 = local_arr_1[aux_1 % 3];
  int margin_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_35_2 * 2)) & 127;
  int offset_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_51_1 > 34)
  {
    acc_1 = ((acc_1 + (offset_51_1 * 2)) + 5) & 127;
    aux_1 ^= offset_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_51_2 > 34)
  {
    acc_2 = ((acc_2 + (offset_51_2 * 2)) + 5) & 127;
    aux_2 ^= offset_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_46_1 = 0;
  int quotient_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_46_1 = ((quotient_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_46_2 = ((quotient_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_46_1) & 127;
    acc_2 = (acc_2 + quotient_46_2) & 127;
  }

  int tally_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_57_1) & 63;
  aux_2 = (aux_2 + tally_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_35_1 == margin_35_2);
  assert(offset_51_1 == offset_51_2);
  assert(quotient_46_1 == quotient_46_2);
  assert(tally_57_1 == tally_57_2);
}

int fn_R001330_3013_12(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001330_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int margin_35 = local_arr[aux % 3];
  acc = (acc + (margin_35 * 2)) & 127;
  int offset_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_51 > 34)
  {
    acc = ((acc + (offset_51 * 2)) + 5) & 127;
    aux ^= offset_51 & 15;
  }
  else
  {
    acc = ((acc - offset_51) + 11) & 127;
    aux += 3;
  }
  int quotient_46 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_46 = ((quotient_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_46) & 127;
  }

  int tally_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_57) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001330_3013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001330_3013_0 st_1 = {0};
  struct Vector3D_R001330_3013_0 st_2 = {0};
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
  int cursor_36_1 = 0;
  int cursor_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_36_1 = ((cursor_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_36_2 = ((cursor_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_36_1) & 127;
    acc_2 = (acc_2 + cursor_36_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_36_1 == cursor_36_2);
}

int fn_R001330_3013_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001330_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_36 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_36 = ((cursor_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_36) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001330_3013_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001330_3013_1 st_1 = {0};
  struct MatrixBlock_R001330_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int quotient_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_13_1)
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

  switch (quotient_13_2)
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

  int threshold_37_1 = 0;
  int threshold_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_37_1 = ((threshold_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_37_2 = ((threshold_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_37_1) & 127;
    acc_2 = (acc_2 + threshold_37_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_13_1 == quotient_13_2);
  assert(threshold_37_1 == threshold_37_2);
}

int fn_R001330_3013_14(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001330_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int quotient_13 = (aux + st.buffer[1]) & 3;
  switch (quotient_13)
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

  int threshold_37 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_37 = ((threshold_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_37) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001330_3013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001330_3013_3 st_1 = {0};
  struct CipherContext_R001330_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int tracker_24_1 = 0;
  int tracker_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_24_1 = ((tracker_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_24_2 = ((tracker_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_24_1) & 127;
    acc_2 = (acc_2 + tracker_24_2) & 127;
  }

  int scale_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_75_1)
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

  switch (scale_75_2)
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
  int coefficient_70_1 = local_arr_1[aux_1 % 3];
  int coefficient_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_70_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_24_1 == tracker_24_2);
  assert(scale_75_1 == scale_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_70_1 == coefficient_70_2);
}

int fn_R001330_3013_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001330_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int tracker_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_24 = ((tracker_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_24) & 127;
  }

  int scale_75 = (aux + st.buffer[1]) & 3;
  switch (scale_75)
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
  int coefficient_70 = local_arr[aux % 3];
  acc = (acc + (coefficient_70 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001330_3013_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001330_3013_2 st_1 = {0};
  struct StreamBuffer_R001330_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int metric_53_1 = 0;
  int metric_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_53_1 = ((metric_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_53_2 = ((metric_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_53_1) & 127;
    acc_2 = (acc_2 + metric_53_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_69_1 = local_arr_1[aux_1 % 3];
  int threshold_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_69_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_23_1)
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

  switch (scale_23_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_53_1 == metric_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_69_1 == threshold_69_2);
  assert(scale_23_1 == scale_23_2);
}

int fn_R001330_3013_16(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001330_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int metric_53 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_53 = ((metric_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_53) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int threshold_69 = local_arr[aux % 3];
  acc = (acc + (threshold_69 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_23 = (aux + st.buffer[1]) & 3;
  switch (scale_23)
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

void main()
{
  int sec_r001330_0_1;
  int sec_r001330_0_2;
  int sec_r001330_1_1;
  int sec_r001330_1_2;
  int sec_r001330_2_1;
  int sec_r001330_2_2;
  int sec_r001330_3_1;
  int sec_r001330_3_2;
  int sec_r001330_4_1;
  int sec_r001330_4_2;
  int sec_r001330_5_1;
  int sec_r001330_5_2;
  int sec_r001330_6_1;
  int sec_r001330_6_2;
  int sec_r001330_7_1;
  int sec_r001330_7_2;
  int sec_r001330_8_1;
  int sec_r001330_8_2;
  int sec_r001330_9_1;
  int sec_r001330_9_2;
  int sec_r001330_10_1;
  int sec_r001330_10_2;
  int sec_r001330_11_1;
  int sec_r001330_11_2;
  int sec_r001330_12_1;
  int sec_r001330_12_2;
  int sec_r001330_13_1;
  int sec_r001330_13_2;
  int sec_r001330_14_1;
  int sec_r001330_14_2;
  int sec_r001330_15_1;
  int sec_r001330_15_2;
  int sec_r001330_16_1;
  int sec_r001330_16_2;
  int sec_r001330_17_1;
  int sec_r001330_17_2;
  int sec_r001330_18_1;
  int sec_r001330_18_2;
  int pub_r001330_0_1;
  int pub_r001330_0_2;
  int pub_r001330_1_1;
  int pub_r001330_1_2;
  int pub_r001330_2_1;
  int pub_r001330_2_2;
  int pub_r001330_3_1;
  int pub_r001330_3_2;
  int pub_r001330_4_1;
  int pub_r001330_4_2;
  int pub_r001330_5_1;
  int pub_r001330_5_2;
  int pub_r001330_6_1;
  int pub_r001330_6_2;
  int pub_r001330_7_1;
  int pub_r001330_7_2;
  int pub_r001330_8_1;
  int pub_r001330_8_2;
  int pub_r001330_9_1;
  int pub_r001330_9_2;
  int pub_r001330_10_1;
  int pub_r001330_10_2;
  int pub_r001330_11_1;
  int pub_r001330_11_2;
  int pub_r001330_12_1;
  int pub_r001330_12_2;
  int pub_r001330_13_1;
  int pub_r001330_13_2;
  int pub_r001330_14_1;
  int pub_r001330_14_2;
  int pub_r001330_15_1;
  int pub_r001330_15_2;
  int pub_r001330_16_1;
  int pub_r001330_16_2;
  int pub_r001330_17_1;
  int pub_r001330_17_2;
  int pub_r001330_18_1;
  int pub_r001330_18_2;
  int pub_r001330_19_1;
  int pub_r001330_19_2;
  int pub_r001330_20_1;
  int pub_r001330_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001330_0_1 >= (-100)) && (pub_r001330_0_1 <= 100));
  __CPROVER_assume((pub_r001330_0_2 >= (-100)) && (pub_r001330_0_2 <= 100));
  __CPROVER_assume((pub_r001330_1_1 >= (-100)) && (pub_r001330_1_1 <= 100));
  __CPROVER_assume((pub_r001330_1_2 >= (-100)) && (pub_r001330_1_2 <= 100));
  __CPROVER_assume((pub_r001330_2_1 >= (-100)) && (pub_r001330_2_1 <= 100));
  __CPROVER_assume((pub_r001330_2_2 >= (-100)) && (pub_r001330_2_2 <= 100));
  __CPROVER_assume((pub_r001330_3_1 >= (-100)) && (pub_r001330_3_1 <= 100));
  __CPROVER_assume((pub_r001330_3_2 >= (-100)) && (pub_r001330_3_2 <= 100));
  __CPROVER_assume((pub_r001330_4_1 >= (-100)) && (pub_r001330_4_1 <= 100));
  __CPROVER_assume((pub_r001330_4_2 >= (-100)) && (pub_r001330_4_2 <= 100));
  __CPROVER_assume((pub_r001330_5_1 >= (-100)) && (pub_r001330_5_1 <= 100));
  __CPROVER_assume((pub_r001330_5_2 >= (-100)) && (pub_r001330_5_2 <= 100));
  __CPROVER_assume((pub_r001330_6_1 >= (-100)) && (pub_r001330_6_1 <= 100));
  __CPROVER_assume((pub_r001330_6_2 >= (-100)) && (pub_r001330_6_2 <= 100));
  __CPROVER_assume((pub_r001330_7_1 >= (-100)) && (pub_r001330_7_1 <= 100));
  __CPROVER_assume((pub_r001330_7_2 >= (-100)) && (pub_r001330_7_2 <= 100));
  __CPROVER_assume((pub_r001330_8_1 >= (-100)) && (pub_r001330_8_1 <= 100));
  __CPROVER_assume((pub_r001330_8_2 >= (-100)) && (pub_r001330_8_2 <= 100));
  __CPROVER_assume((pub_r001330_9_1 >= (-100)) && (pub_r001330_9_1 <= 100));
  __CPROVER_assume((pub_r001330_9_2 >= (-100)) && (pub_r001330_9_2 <= 100));
  __CPROVER_assume((pub_r001330_10_1 >= (-100)) && (pub_r001330_10_1 <= 100));
  __CPROVER_assume((pub_r001330_10_2 >= (-100)) && (pub_r001330_10_2 <= 100));
  __CPROVER_assume((pub_r001330_11_1 >= (-100)) && (pub_r001330_11_1 <= 100));
  __CPROVER_assume((pub_r001330_11_2 >= (-100)) && (pub_r001330_11_2 <= 100));
  __CPROVER_assume((pub_r001330_12_1 >= (-100)) && (pub_r001330_12_1 <= 100));
  __CPROVER_assume((pub_r001330_12_2 >= (-100)) && (pub_r001330_12_2 <= 100));
  __CPROVER_assume((pub_r001330_13_1 >= (-100)) && (pub_r001330_13_1 <= 100));
  __CPROVER_assume((pub_r001330_13_2 >= (-100)) && (pub_r001330_13_2 <= 100));
  __CPROVER_assume((pub_r001330_14_1 >= (-100)) && (pub_r001330_14_1 <= 100));
  __CPROVER_assume((pub_r001330_14_2 >= (-100)) && (pub_r001330_14_2 <= 100));
  __CPROVER_assume((pub_r001330_15_1 >= (-100)) && (pub_r001330_15_1 <= 100));
  __CPROVER_assume((pub_r001330_15_2 >= (-100)) && (pub_r001330_15_2 <= 100));
  __CPROVER_assume((pub_r001330_16_1 >= (-100)) && (pub_r001330_16_1 <= 100));
  __CPROVER_assume((pub_r001330_16_2 >= (-100)) && (pub_r001330_16_2 <= 100));
  __CPROVER_assume((pub_r001330_17_1 >= (-100)) && (pub_r001330_17_1 <= 100));
  __CPROVER_assume((pub_r001330_17_2 >= (-100)) && (pub_r001330_17_2 <= 100));
  __CPROVER_assume((pub_r001330_18_1 >= (-100)) && (pub_r001330_18_1 <= 100));
  __CPROVER_assume((pub_r001330_18_2 >= (-100)) && (pub_r001330_18_2 <= 100));
  __CPROVER_assume((pub_r001330_19_1 >= (-100)) && (pub_r001330_19_1 <= 100));
  __CPROVER_assume((pub_r001330_19_2 >= (-100)) && (pub_r001330_19_2 <= 100));
  __CPROVER_assume((pub_r001330_20_1 >= (-100)) && (pub_r001330_20_1 <= 100));
  __CPROVER_assume((pub_r001330_20_2 >= (-100)) && (pub_r001330_20_2 <= 100));
  __CPROVER_assume((sec_r001330_0_1 >= 0) && (sec_r001330_0_1 <= 255));
  __CPROVER_assume((sec_r001330_0_2 >= 0) && (sec_r001330_0_2 <= 255));
  __CPROVER_assume((sec_r001330_1_1 >= 0) && (sec_r001330_1_1 <= 255));
  __CPROVER_assume((sec_r001330_1_2 >= 0) && (sec_r001330_1_2 <= 255));
  __CPROVER_assume((sec_r001330_2_1 >= 0) && (sec_r001330_2_1 <= 255));
  __CPROVER_assume((sec_r001330_2_2 >= 0) && (sec_r001330_2_2 <= 255));
  __CPROVER_assume((sec_r001330_3_1 >= 0) && (sec_r001330_3_1 <= 255));
  __CPROVER_assume((sec_r001330_3_2 >= 0) && (sec_r001330_3_2 <= 255));
  __CPROVER_assume((sec_r001330_4_1 >= 0) && (sec_r001330_4_1 <= 255));
  __CPROVER_assume((sec_r001330_4_2 >= 0) && (sec_r001330_4_2 <= 255));
  __CPROVER_assume((sec_r001330_5_1 >= 0) && (sec_r001330_5_1 <= 255));
  __CPROVER_assume((sec_r001330_5_2 >= 0) && (sec_r001330_5_2 <= 255));
  __CPROVER_assume((sec_r001330_6_1 >= 0) && (sec_r001330_6_1 <= 255));
  __CPROVER_assume((sec_r001330_6_2 >= 0) && (sec_r001330_6_2 <= 255));
  __CPROVER_assume((sec_r001330_7_1 >= 0) && (sec_r001330_7_1 <= 255));
  __CPROVER_assume((sec_r001330_7_2 >= 0) && (sec_r001330_7_2 <= 255));
  __CPROVER_assume((sec_r001330_8_1 >= 0) && (sec_r001330_8_1 <= 255));
  __CPROVER_assume((sec_r001330_8_2 >= 0) && (sec_r001330_8_2 <= 255));
  __CPROVER_assume((sec_r001330_9_1 >= 0) && (sec_r001330_9_1 <= 255));
  __CPROVER_assume((sec_r001330_9_2 >= 0) && (sec_r001330_9_2 <= 255));
  __CPROVER_assume((sec_r001330_10_1 >= 0) && (sec_r001330_10_1 <= 255));
  __CPROVER_assume((sec_r001330_10_2 >= 0) && (sec_r001330_10_2 <= 255));
  __CPROVER_assume((sec_r001330_11_1 >= 0) && (sec_r001330_11_1 <= 255));
  __CPROVER_assume((sec_r001330_11_2 >= 0) && (sec_r001330_11_2 <= 255));
  __CPROVER_assume((sec_r001330_12_1 >= 0) && (sec_r001330_12_1 <= 255));
  __CPROVER_assume((sec_r001330_12_2 >= 0) && (sec_r001330_12_2 <= 255));
  __CPROVER_assume((sec_r001330_13_1 >= 0) && (sec_r001330_13_1 <= 255));
  __CPROVER_assume((sec_r001330_13_2 >= 0) && (sec_r001330_13_2 <= 255));
  __CPROVER_assume((sec_r001330_14_1 >= 0) && (sec_r001330_14_1 <= 255));
  __CPROVER_assume((sec_r001330_14_2 >= 0) && (sec_r001330_14_2 <= 255));
  __CPROVER_assume((sec_r001330_15_1 >= 0) && (sec_r001330_15_1 <= 255));
  __CPROVER_assume((sec_r001330_15_2 >= 0) && (sec_r001330_15_2 <= 255));
  __CPROVER_assume((sec_r001330_16_1 >= 0) && (sec_r001330_16_1 <= 255));
  __CPROVER_assume((sec_r001330_16_2 >= 0) && (sec_r001330_16_2 <= 255));
  __CPROVER_assume((sec_r001330_17_1 >= 0) && (sec_r001330_17_1 <= 255));
  __CPROVER_assume((sec_r001330_17_2 >= 0) && (sec_r001330_17_2 <= 255));
  __CPROVER_assume((sec_r001330_18_1 >= 0) && (sec_r001330_18_1 <= 255));
  __CPROVER_assume((sec_r001330_18_2 >= 0) && (sec_r001330_18_2 <= 255));
  struct Vector3D_R001330_3013_0 st_var_0_1 = {0};
  struct Vector3D_R001330_3013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001330_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001330_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001330_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001330_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001330_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001330_0_2 + 7) & 15;
  struct MatrixBlock_R001330_3013_1 st_var_1_1 = {0};
  struct MatrixBlock_R001330_3013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001330_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001330_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001330_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001330_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001330_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001330_0_2 + 9) & 15;
  struct StreamBuffer_R001330_3013_2 st_var_2_1 = {0};
  struct StreamBuffer_R001330_3013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001330_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001330_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001330_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001330_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001330_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001330_0_2 + 11) & 15;
  struct CipherContext_R001330_3013_3 st_var_3_1 = {0};
  struct CipherContext_R001330_3013_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001330_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001330_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001330_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001330_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001330_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001330_0_2 + 13) & 15;
  union PacketPayload_R001330_3013_0 u_var_1;
  union PacketPayload_R001330_3013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001330_3013_0(sec_r001330_0_1, pub_r001330_1_1, pub_r001330_2_1, pub_r001330_3_1, pub_r001330_4_1);
  int helper_flow_0_2 = fn_R001330_3013_0(sec_r001330_0_2, pub_r001330_1_2, pub_r001330_2_2, pub_r001330_3_2, pub_r001330_4_2);
  fn_R001330_3013_0_2(sec_r001330_0_1, pub_r001330_1_1, pub_r001330_2_1, pub_r001330_3_1, pub_r001330_4_1, sec_r001330_0_2, pub_r001330_1_2, pub_r001330_2_2, pub_r001330_3_2, pub_r001330_4_2);
  int helper_flow_1_1 = fn_R001330_3013_1(sec_r001330_1_1, pub_r001330_2_1, pub_r001330_3_1, pub_r001330_4_1);
  int helper_flow_1_2 = fn_R001330_3013_1(sec_r001330_1_2, pub_r001330_2_2, pub_r001330_3_2, pub_r001330_4_2);
  fn_R001330_3013_1_2(sec_r001330_1_1, pub_r001330_2_1, pub_r001330_3_1, pub_r001330_4_1, sec_r001330_1_2, pub_r001330_2_2, pub_r001330_3_2, pub_r001330_4_2);
  int helper_flow_2_1 = fn_R001330_3013_2(sec_r001330_2_1, pub_r001330_3_1, pub_r001330_4_1, pub_r001330_5_1);
  int helper_flow_2_2 = fn_R001330_3013_2(sec_r001330_2_2, pub_r001330_3_2, pub_r001330_4_2, pub_r001330_5_2);
  fn_R001330_3013_2_2(sec_r001330_2_1, pub_r001330_3_1, pub_r001330_4_1, pub_r001330_5_1, sec_r001330_2_2, pub_r001330_3_2, pub_r001330_4_2, pub_r001330_5_2);
  int helper_flow_3_1 = fn_R001330_3013_3(sec_r001330_3_1, sec_r001330_4_1);
  int helper_flow_3_2 = fn_R001330_3013_3(sec_r001330_3_2, sec_r001330_4_2);
  fn_R001330_3013_3_2(sec_r001330_3_1, sec_r001330_4_1, sec_r001330_3_2, sec_r001330_4_2);
  int helper_flow_4_1 = fn_R001330_3013_4(sec_r001330_4_1, sec_r001330_5_1, pub_r001330_6_1, pub_r001330_7_1);
  int helper_flow_4_2 = fn_R001330_3013_4(sec_r001330_4_2, sec_r001330_5_2, pub_r001330_6_2, pub_r001330_7_2);
  fn_R001330_3013_4_2(sec_r001330_4_1, sec_r001330_5_1, pub_r001330_6_1, pub_r001330_7_1, sec_r001330_4_2, sec_r001330_5_2, pub_r001330_6_2, pub_r001330_7_2);
  int helper_flow_5_1 = fn_R001330_3013_5(sec_r001330_5_1, sec_r001330_6_1, pub_r001330_7_1);
  int helper_flow_5_2 = fn_R001330_3013_5(sec_r001330_5_2, sec_r001330_6_2, pub_r001330_7_2);
  fn_R001330_3013_5_2(sec_r001330_5_1, sec_r001330_6_1, pub_r001330_7_1, sec_r001330_5_2, sec_r001330_6_2, pub_r001330_7_2);
  int helper_flow_6_1 = fn_R001330_3013_6(sec_r001330_6_1, pub_r001330_7_1);
  int helper_flow_6_2 = fn_R001330_3013_6(sec_r001330_6_2, pub_r001330_7_2);
  fn_R001330_3013_6_2(sec_r001330_6_1, pub_r001330_7_1, sec_r001330_6_2, pub_r001330_7_2);
  int helper_flow_7_1 = fn_R001330_3013_7(sec_r001330_7_1, sec_r001330_8_1, pub_r001330_9_1, pub_r001330_10_1, pub_r001330_11_1);
  int helper_flow_7_2 = fn_R001330_3013_7(sec_r001330_7_2, sec_r001330_8_2, pub_r001330_9_2, pub_r001330_10_2, pub_r001330_11_2);
  fn_R001330_3013_7_2(sec_r001330_7_1, sec_r001330_8_1, pub_r001330_9_1, pub_r001330_10_1, pub_r001330_11_1, sec_r001330_7_2, sec_r001330_8_2, pub_r001330_9_2, pub_r001330_10_2, pub_r001330_11_2);
  int helper_flow_8_1 = fn_R001330_3013_8(sec_r001330_8_1, sec_r001330_9_1, pub_r001330_10_1);
  int helper_flow_8_2 = fn_R001330_3013_8(sec_r001330_8_2, sec_r001330_9_2, pub_r001330_10_2);
  fn_R001330_3013_8_2(sec_r001330_8_1, sec_r001330_9_1, pub_r001330_10_1, sec_r001330_8_2, sec_r001330_9_2, pub_r001330_10_2);
  int helper_flow_9_1 = fn_R001330_3013_9(sec_r001330_9_1, pub_r001330_10_1, pub_r001330_11_1);
  int helper_flow_9_2 = fn_R001330_3013_9(sec_r001330_9_2, pub_r001330_10_2, pub_r001330_11_2);
  fn_R001330_3013_9_2(sec_r001330_9_1, pub_r001330_10_1, pub_r001330_11_1, sec_r001330_9_2, pub_r001330_10_2, pub_r001330_11_2);
  int stage_v_0_1 = (((sec_r001330_5_1 ^ 0x2A) * 2) + pub_r001330_4_1) & 127;
  int stage_v_0_2 = (((sec_r001330_5_2 ^ 0x2A) * 2) + pub_r001330_4_2) & 127;
  if (stage_v_0_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((sec_r001330_8_1 ^ 0x2A) * 2) + pub_r001330_5_1) & 127;
  int stage_v_1_2 = (((sec_r001330_8_2 ^ 0x2A) * 2) + pub_r001330_5_2) & 127;
  if (stage_v_1_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((pub_r001330_2_1 * 2) + 8) & 63;
  int stage_v_2_2 = ((pub_r001330_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001330_9_1 * 2) + 27) & 63;
  int stage_v_3_2 = ((pub_r001330_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((sec_r001330_13_1 ^ 0x2A) * 2) + pub_r001330_4_1) & 127;
  int stage_v_4_2 = (((sec_r001330_13_2 ^ 0x2A) * 2) + pub_r001330_4_2) & 127;
  if (stage_v_4_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((sec_r001330_1_1 ^ 0x2A) * 2) + pub_r001330_5_1) & 127;
  int stage_v_5_2 = (((sec_r001330_1_2 ^ 0x2A) * 2) + pub_r001330_5_2) & 127;
  if (stage_v_5_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (((sec_r001330_10_1 ^ 0x2A) * 2) + pub_r001330_19_1) & 127;
  int stage_v_6_2 = (((sec_r001330_10_2 ^ 0x2A) * 2) + pub_r001330_19_2) & 127;
  if (stage_v_6_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001330_6_1) & 127;
  int stage_v_7_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001330_6_2) & 127;
  if (stage_v_7_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001330_0_1) & 127;
  int stage_v_8_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001330_0_2) & 127;
  if (stage_v_8_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((sec_r001330_16_1 ^ 0x2A) * 2) + pub_r001330_13_1) & 127;
  int stage_v_9_2 = (((sec_r001330_16_2 ^ 0x2A) * 2) + pub_r001330_13_2) & 127;
  if (stage_v_9_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001330_9_1) & 127;
  int stage_v_10_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001330_9_2) & 127;
  if (stage_v_10_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((sec_r001330_11_1 ^ 0x2A) * 2) + pub_r001330_5_1) & 127;
  int stage_v_11_2 = (((sec_r001330_11_2 ^ 0x2A) * 2) + pub_r001330_5_2) & 127;
  if (stage_v_11_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001330_16_1) & 127;
  int stage_v_12_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001330_16_2) & 127;
  if (stage_v_12_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((pub_r001330_18_1 * 2) + 39) & 63;
  int stage_v_13_2 = ((pub_r001330_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001330_1_1) & 127;
  int stage_v_14_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001330_1_2) & 127;
  if (stage_v_14_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (((sec_r001330_8_1 ^ 0x2A) * 2) + pub_r001330_14_1) & 127;
  int stage_v_15_2 = (((sec_r001330_8_2 ^ 0x2A) * 2) + pub_r001330_14_2) & 127;
  if (stage_v_15_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001330_5_1) & 127;
  int stage_v_16_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001330_5_2) & 127;
  if (stage_v_16_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001330_8_1) & 127;
  int stage_v_17_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001330_8_2) & 127;
  if (stage_v_17_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((sec_r001330_15_1 ^ 0x2A) * 2) + pub_r001330_3_1) & 127;
  int stage_v_18_2 = (((sec_r001330_15_2 ^ 0x2A) * 2) + pub_r001330_3_2) & 127;
  if (stage_v_18_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((sec_r001330_13_1 ^ 0x2A) * 2) + pub_r001330_19_1) & 127;
  int stage_v_19_2 = (((sec_r001330_13_2 ^ 0x2A) * 2) + pub_r001330_19_2) & 127;
  if (stage_v_19_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((sec_r001330_14_1 ^ 0x2A) * 2) + pub_r001330_8_1) & 127;
  int stage_v_20_2 = (((sec_r001330_14_2 ^ 0x2A) * 2) + pub_r001330_8_2) & 127;
  if (stage_v_20_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((sec_r001330_5_1 ^ 0x2A) * 2) + pub_r001330_0_1) & 127;
  int stage_v_21_2 = (((sec_r001330_5_2 ^ 0x2A) * 2) + pub_r001330_0_2) & 127;
  if (stage_v_21_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001330_3_1) & 127;
  int stage_v_22_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001330_3_2) & 127;
  if (stage_v_22_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001330_9_1) & 127;
  int stage_v_23_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001330_9_2) & 127;
  if (stage_v_23_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001330_20_1) & 127;
  int stage_v_24_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001330_20_2) & 127;
  if (stage_v_24_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001330_14_1) & 127;
  int stage_v_25_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001330_14_2) & 127;
  if (stage_v_25_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001330_16_1) & 127;
  int stage_v_26_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001330_16_2) & 127;
  if (stage_v_26_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001330_3_1) & 127;
  int stage_v_27_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001330_3_2) & 127;
  if (stage_v_27_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((pub_r001330_12_1 * 2) + 15) & 63;
  int stage_v_28_2 = ((pub_r001330_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001330_5_1) & 127;
  int stage_v_29_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001330_5_2) & 127;
  if (stage_v_29_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((pub_r001330_20_1 * 2) + 18) & 63;
  int stage_v_30_2 = ((pub_r001330_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001330_16_1) & 127;
  int stage_v_31_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001330_16_2) & 127;
  if (stage_v_31_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001330_11_1) & 127;
  int stage_v_32_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001330_11_2) & 127;
  if (stage_v_32_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((sec_r001330_16_1 ^ 0x2A) * 2) + pub_r001330_20_1) & 127;
  int stage_v_33_2 = (((sec_r001330_16_2 ^ 0x2A) * 2) + pub_r001330_20_2) & 127;
  if (stage_v_33_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001330_12_1) & 127;
  int stage_v_34_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001330_12_2) & 127;
  if (stage_v_34_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((sec_r001330_15_1 ^ 0x2A) * 2) + pub_r001330_20_1) & 127;
  int stage_v_35_2 = (((sec_r001330_15_2 ^ 0x2A) * 2) + pub_r001330_20_2) & 127;
  if (stage_v_35_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((pub_r001330_19_1 * 2) + 21) & 63;
  int stage_v_36_2 = ((pub_r001330_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001330_4_1 * 2) + 32) & 63;
  int stage_v_37_2 = ((pub_r001330_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((sec_r001330_11_1 ^ 0x2A) * 2) + pub_r001330_12_1) & 127;
  int stage_v_38_2 = (((sec_r001330_11_2 ^ 0x2A) * 2) + pub_r001330_12_2) & 127;
  if (stage_v_38_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((sec_r001330_0_1 ^ 0x2A) * 2) + pub_r001330_0_1) & 127;
  int stage_v_39_2 = (((sec_r001330_0_2 ^ 0x2A) * 2) + pub_r001330_0_2) & 127;
  if (stage_v_39_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (((sec_r001330_0_1 ^ 0x2A) * 2) + pub_r001330_11_1) & 127;
  int stage_v_40_2 = (((sec_r001330_0_2 ^ 0x2A) * 2) + pub_r001330_11_2) & 127;
  if (stage_v_40_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((pub_r001330_3_1 * 2) + 35) & 63;
  int stage_v_41_2 = ((pub_r001330_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (((sec_r001330_7_1 ^ 0x2A) * 2) + pub_r001330_17_1) & 127;
  int stage_v_42_2 = (((sec_r001330_7_2 ^ 0x2A) * 2) + pub_r001330_17_2) & 127;
  if (stage_v_42_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001330_20_1) & 127;
  int stage_v_43_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001330_20_2) & 127;
  if (stage_v_43_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001330_10_1) & 127;
  int stage_v_44_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001330_10_2) & 127;
  if (stage_v_44_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((sec_r001330_8_1 ^ 0x2A) * 2) + pub_r001330_5_1) & 127;
  int stage_v_45_2 = (((sec_r001330_8_2 ^ 0x2A) * 2) + pub_r001330_5_2) & 127;
  if (stage_v_45_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (((sec_r001330_9_1 ^ 0x2A) * 2) + pub_r001330_5_1) & 127;
  int stage_v_46_2 = (((sec_r001330_9_2 ^ 0x2A) * 2) + pub_r001330_5_2) & 127;
  if (stage_v_46_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((pub_r001330_4_1 * 2) + 35) & 63;
  int stage_v_47_2 = ((pub_r001330_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001330_0_1) & 127;
  int stage_v_48_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001330_0_2) & 127;
  if (stage_v_48_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((pub_r001330_6_1 * 2) + 19) & 63;
  int stage_v_49_2 = ((pub_r001330_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001330_4_1) & 127;
  int stage_v_50_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001330_4_2) & 127;
  if (stage_v_50_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001330_20_1) & 127;
  int stage_v_51_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001330_20_2) & 127;
  if (stage_v_51_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((pub_r001330_11_1 * 2) + 33) & 63;
  int stage_v_52_2 = ((pub_r001330_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001330_9_1) & 127;
  int stage_v_53_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001330_9_2) & 127;
  if (stage_v_53_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((pub_r001330_9_1 * 2) + 44) & 63;
  int stage_v_54_2 = ((pub_r001330_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001330_5_1) & 127;
  int stage_v_55_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001330_5_2) & 127;
  if (stage_v_55_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001330_12_1) & 127;
  int stage_v_56_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001330_12_2) & 127;
  if (stage_v_56_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((sec_r001330_4_1 ^ 0x2A) * 2) + pub_r001330_2_1) & 127;
  int stage_v_57_2 = (((sec_r001330_4_2 ^ 0x2A) * 2) + pub_r001330_2_2) & 127;
  if (stage_v_57_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((pub_r001330_13_1 * 2) + 12) & 63;
  int stage_v_58_2 = ((pub_r001330_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001330_3_1 * 2) + 24) & 63;
  int stage_v_59_2 = ((pub_r001330_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001330_0_1) & 127;
  int stage_v_60_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001330_0_2) & 127;
  if (stage_v_60_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001330_1_1) & 127;
  int stage_v_61_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001330_1_2) & 127;
  if (stage_v_61_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (((sec_r001330_13_1 ^ 0x2A) * 2) + pub_r001330_17_1) & 127;
  int stage_v_62_2 = (((sec_r001330_13_2 ^ 0x2A) * 2) + pub_r001330_17_2) & 127;
  if (stage_v_62_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001330_2_1) & 127;
  int stage_v_63_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001330_2_2) & 127;
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
  int stage_v_64_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001330_14_1) & 127;
  int stage_v_64_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001330_14_2) & 127;
  if (stage_v_64_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001330_13_1) & 127;
  int stage_v_65_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001330_13_2) & 127;
  if (stage_v_65_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((pub_r001330_19_1 * 2) + 33) & 63;
  int stage_v_66_2 = ((pub_r001330_19_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (((sec_r001330_10_1 ^ 0x2A) * 2) + pub_r001330_14_1) & 127;
  int stage_v_67_2 = (((sec_r001330_10_2 ^ 0x2A) * 2) + pub_r001330_14_2) & 127;
  if (stage_v_67_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((pub_r001330_19_1 * 2) + 46) & 63;
  int stage_v_68_2 = ((pub_r001330_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001330_17_1 * 2) + 45) & 63;
  int stage_v_69_2 = ((pub_r001330_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001330_19_1) & 127;
  int stage_v_70_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001330_19_2) & 127;
  if (stage_v_70_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((pub_r001330_9_1 * 2) + 27) & 63;
  int stage_v_71_2 = ((pub_r001330_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001330_19_1 * 2) + 46) & 63;
  int stage_v_72_2 = ((pub_r001330_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((sec_r001330_13_1 ^ 0x2A) * 2) + pub_r001330_9_1) & 127;
  int stage_v_73_2 = (((sec_r001330_13_2 ^ 0x2A) * 2) + pub_r001330_9_2) & 127;
  if (stage_v_73_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001330_2_1) & 127;
  int stage_v_74_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001330_2_2) & 127;
  if (stage_v_74_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001330_8_1) & 127;
  int stage_v_75_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001330_8_2) & 127;
  if (stage_v_75_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((sec_r001330_17_1 ^ 0x2A) * 2) + pub_r001330_0_1) & 127;
  int stage_v_76_2 = (((sec_r001330_17_2 ^ 0x2A) * 2) + pub_r001330_0_2) & 127;
  if (stage_v_76_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001330_14_1) & 127;
  int stage_v_77_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001330_14_2) & 127;
  if (stage_v_77_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (((sec_r001330_6_1 ^ 0x2A) * 2) + pub_r001330_3_1) & 127;
  int stage_v_78_2 = (((sec_r001330_6_2 ^ 0x2A) * 2) + pub_r001330_3_2) & 127;
  if (stage_v_78_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((pub_r001330_5_1 * 2) + 22) & 63;
  int stage_v_79_2 = ((pub_r001330_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001330_10_1 * 2) + 11) & 63;
  int stage_v_80_2 = ((pub_r001330_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001330_9_1) & 127;
  int stage_v_81_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001330_9_2) & 127;
  if (stage_v_81_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((sec_r001330_17_1 ^ 0x2A) * 2) + pub_r001330_15_1) & 127;
  int stage_v_82_2 = (((sec_r001330_17_2 ^ 0x2A) * 2) + pub_r001330_15_2) & 127;
  if (stage_v_82_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001330_7_1) & 127;
  int stage_v_83_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001330_7_2) & 127;
  if (stage_v_83_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001330_13_1) & 127;
  int stage_v_84_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001330_13_2) & 127;
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
  int stage_v_85_1 = (((stage_v_76_1 ^ 0x2A) * 2) + pub_r001330_9_1) & 127;
  int stage_v_85_2 = (((stage_v_76_2 ^ 0x2A) * 2) + pub_r001330_9_2) & 127;
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
  int stage_v_86_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001330_2_1) & 127;
  int stage_v_86_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001330_2_2) & 127;
  if (stage_v_86_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001330_11_1) & 127;
  int stage_v_87_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001330_11_2) & 127;
  if (stage_v_87_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((sec_r001330_16_1 ^ 0x2A) * 2) + pub_r001330_4_1) & 127;
  int stage_v_88_2 = (((sec_r001330_16_2 ^ 0x2A) * 2) + pub_r001330_4_2) & 127;
  if (stage_v_88_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001330_13_1) & 127;
  int stage_v_89_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001330_13_2) & 127;
  if (stage_v_89_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001330_3_1) & 127;
  int stage_v_90_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001330_3_2) & 127;
  if (stage_v_90_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((pub_r001330_3_1 * 2) + 5) & 63;
  int stage_v_91_2 = ((pub_r001330_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001330_12_1) & 127;
  int stage_v_92_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001330_12_2) & 127;
  if (stage_v_92_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((pub_r001330_11_1 * 2) + 44) & 63;
  int stage_v_93_2 = ((pub_r001330_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001330_16_1 * 2) + 38) & 63;
  int stage_v_94_2 = ((pub_r001330_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001330_18_1) & 127;
  int stage_v_95_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001330_18_2) & 127;
  if (stage_v_95_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((pub_r001330_19_1 * 2) + 17) & 63;
  int stage_v_96_2 = ((pub_r001330_19_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001330_19_1 * 2) + 16) & 63;
  int stage_v_97_2 = ((pub_r001330_19_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_67_1 ^ 0x2A) * 2) + pub_r001330_7_1) & 127;
  int stage_v_98_2 = (((stage_v_67_2 ^ 0x2A) * 2) + pub_r001330_7_2) & 127;
  if (stage_v_98_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((pub_r001330_17_1 * 2) + 17) & 63;
  int stage_v_99_2 = ((pub_r001330_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001330_16_1 * 2) + 26) & 63;
  int stage_v_100_2 = ((pub_r001330_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001330_6_1) & 127;
  int stage_v_101_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001330_6_2) & 127;
  if (stage_v_101_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((pub_r001330_15_1 * 2) + 38) & 63;
  int stage_v_102_2 = ((pub_r001330_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001330_3_1 * 2) + 44) & 63;
  int stage_v_103_2 = ((pub_r001330_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001330_11_1) & 127;
  int stage_v_104_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001330_11_2) & 127;
  if (stage_v_104_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001330_1_1) & 127;
  int stage_v_105_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001330_1_2) & 127;
  if (stage_v_105_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((sec_r001330_9_1 ^ 0x2A) * 2) + pub_r001330_7_1) & 127;
  int stage_v_106_2 = (((sec_r001330_9_2 ^ 0x2A) * 2) + pub_r001330_7_2) & 127;
  if (stage_v_106_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((pub_r001330_8_1 * 2) + 10) & 63;
  int stage_v_107_2 = ((pub_r001330_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001330_16_1) & 127;
  int stage_v_108_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001330_16_2) & 127;
  if (stage_v_108_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((pub_r001330_2_1 * 2) + 8) & 63;
  int stage_v_109_2 = ((pub_r001330_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001330_11_1) & 127;
  int stage_v_110_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001330_11_2) & 127;
  if (stage_v_110_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((sec_r001330_16_1 ^ 0x2A) * 2) + pub_r001330_2_1) & 127;
  int stage_v_111_2 = (((sec_r001330_16_2 ^ 0x2A) * 2) + pub_r001330_2_2) & 127;
  if (stage_v_111_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001330_19_1) & 127;
  int stage_v_112_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001330_19_2) & 127;
  if (stage_v_112_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001330_20_1) & 127;
  int stage_v_113_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001330_20_2) & 127;
  if (stage_v_113_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001330_8_1) & 127;
  int stage_v_114_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001330_8_2) & 127;
  if (stage_v_114_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001330_15_1) & 127;
  int stage_v_115_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001330_15_2) & 127;
  if (stage_v_115_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((pub_r001330_9_1 * 2) + 39) & 63;
  int stage_v_116_2 = ((pub_r001330_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001330_6_1) & 127;
  int stage_v_117_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001330_6_2) & 127;
  if (stage_v_117_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001330_0_1) & 127;
  int stage_v_118_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001330_0_2) & 127;
  if (stage_v_118_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001330_10_1) & 127;
  int stage_v_119_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001330_10_2) & 127;
  if (stage_v_119_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((pub_r001330_12_1 * 2) + 5) & 63;
  int stage_v_120_2 = ((pub_r001330_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001330_14_1 * 2) + 33) & 63;
  int stage_v_121_2 = ((pub_r001330_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001330_16_1) & 127;
  int stage_v_122_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001330_16_2) & 127;
  if (stage_v_122_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((sec_r001330_2_1 ^ 0x2A) * 2) + pub_r001330_5_1) & 127;
  int stage_v_123_2 = (((sec_r001330_2_2 ^ 0x2A) * 2) + pub_r001330_5_2) & 127;
  if (stage_v_123_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((stage_v_95_1 ^ 0x2A) * 2) + pub_r001330_13_1) & 127;
  int stage_v_124_2 = (((stage_v_95_2 ^ 0x2A) * 2) + pub_r001330_13_2) & 127;
  if (stage_v_124_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = (((sec_r001330_9_1 ^ 0x2A) * 2) + pub_r001330_14_1) & 127;
  int stage_v_125_2 = (((sec_r001330_9_2 ^ 0x2A) * 2) + pub_r001330_14_2) & 127;
  if (stage_v_125_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = (((sec_r001330_8_1 ^ 0x2A) * 2) + pub_r001330_12_1) & 127;
  int stage_v_126_2 = (((sec_r001330_8_2 ^ 0x2A) * 2) + pub_r001330_12_2) & 127;
  if (stage_v_126_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001330_1_1) & 127;
  int stage_v_127_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001330_1_2) & 127;
  if (stage_v_127_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001330_19_1) & 127;
  int stage_v_128_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001330_19_2) & 127;
  if (stage_v_128_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001330_1_1) & 127;
  int stage_v_129_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001330_1_2) & 127;
  if (stage_v_129_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001330_8_1) & 127;
  int stage_v_130_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001330_8_2) & 127;
  if (stage_v_130_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((sec_r001330_4_1 ^ 0x2A) * 2) + pub_r001330_2_1) & 127;
  int stage_v_131_2 = (((sec_r001330_4_2 ^ 0x2A) * 2) + pub_r001330_2_2) & 127;
  if (stage_v_131_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((pub_r001330_16_1 * 2) + 7) & 63;
  int stage_v_132_2 = ((pub_r001330_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001330_11_1) & 127;
  int stage_v_133_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001330_11_2) & 127;
  if (stage_v_133_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((pub_r001330_20_1 * 2) + 13) & 63;
  int stage_v_134_2 = ((pub_r001330_20_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001330_8_1) & 127;
  int stage_v_135_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001330_8_2) & 127;
  if (stage_v_135_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((pub_r001330_18_1 * 2) + 7) & 63;
  int stage_v_136_2 = ((pub_r001330_18_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001330_6_1) & 127;
  int stage_v_137_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001330_6_2) & 127;
  if (stage_v_137_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001330_19_1) & 127;
  int stage_v_138_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001330_19_2) & 127;
  if (stage_v_138_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((pub_r001330_4_1 * 2) + 7) & 63;
  int stage_v_139_2 = ((pub_r001330_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001330_11_1) & 127;
  int stage_v_140_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001330_11_2) & 127;
  if (stage_v_140_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((pub_r001330_0_1 * 2) + 38) & 63;
  int stage_v_141_2 = ((pub_r001330_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001330_9_1) & 127;
  int stage_v_142_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001330_9_2) & 127;
  if (stage_v_142_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001330_0_1) & 127;
  int stage_v_143_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001330_0_2) & 127;
  if (stage_v_143_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001330_9_1) & 127;
  int stage_v_144_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001330_9_2) & 127;
  if (stage_v_144_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((sec_r001330_17_1 ^ 0x2A) * 2) + pub_r001330_2_1) & 127;
  int stage_v_145_2 = (((sec_r001330_17_2 ^ 0x2A) * 2) + pub_r001330_2_2) & 127;
  if (stage_v_145_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001330_0_1) & 127;
  int stage_v_146_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001330_0_2) & 127;
  if (stage_v_146_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001330_0_1) & 127;
  int stage_v_147_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001330_0_2) & 127;
  if (stage_v_147_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001330_15_1) & 127;
  int stage_v_148_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001330_15_2) & 127;
  if (stage_v_148_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((pub_r001330_0_1 * 2) + 15) & 63;
  int stage_v_149_2 = ((pub_r001330_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (((sec_r001330_0_1 ^ 0x2A) * 2) + pub_r001330_19_1) & 127;
  int stage_v_150_2 = (((sec_r001330_0_2 ^ 0x2A) * 2) + pub_r001330_19_2) & 127;
  if (stage_v_150_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((pub_r001330_5_1 * 2) + 17) & 63;
  int stage_v_151_2 = ((pub_r001330_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001330_8_1) & 127;
  int stage_v_152_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001330_8_2) & 127;
  if (stage_v_152_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001330_0_1) & 127;
  int stage_v_153_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001330_0_2) & 127;
  if (stage_v_153_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001330_8_1) & 127;
  int stage_v_154_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001330_8_2) & 127;
  if (stage_v_154_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001330_3_1) & 127;
  int stage_v_155_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001330_3_2) & 127;
  if (stage_v_155_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((pub_r001330_12_1 * 2) + 27) & 63;
  int stage_v_156_2 = ((pub_r001330_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001330_9_1) & 127;
  int stage_v_157_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001330_9_2) & 127;
  if (stage_v_157_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((stage_v_133_1 ^ 0x2A) * 2) + pub_r001330_11_1) & 127;
  int stage_v_158_2 = (((stage_v_133_2 ^ 0x2A) * 2) + pub_r001330_11_2) & 127;
  if (stage_v_158_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001330_9_1) & 127;
  int stage_v_159_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001330_9_2) & 127;
  if (stage_v_159_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((pub_r001330_12_1 * 2) + 37) & 63;
  int stage_v_160_2 = ((pub_r001330_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((sec_r001330_17_1 ^ 0x2A) * 2) + pub_r001330_1_1) & 127;
  int stage_v_161_2 = (((sec_r001330_17_2 ^ 0x2A) * 2) + pub_r001330_1_2) & 127;
  if (stage_v_161_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((stage_v_115_1 ^ 0x2A) * 2) + pub_r001330_4_1) & 127;
  int stage_v_162_2 = (((stage_v_115_2 ^ 0x2A) * 2) + pub_r001330_4_2) & 127;
  if (stage_v_162_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001330_16_1) & 127;
  int stage_v_163_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001330_16_2) & 127;
  if (stage_v_163_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001330_8_1) & 127;
  int stage_v_164_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001330_8_2) & 127;
  if (stage_v_164_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001330_0_1) & 127;
  int stage_v_165_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001330_0_2) & 127;
  if (stage_v_165_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001330_6_1) & 127;
  int stage_v_166_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001330_6_2) & 127;
  if (stage_v_166_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_146_1 ^ 0x2A) * 2) + pub_r001330_1_1) & 127;
  int stage_v_167_2 = (((stage_v_146_2 ^ 0x2A) * 2) + pub_r001330_1_2) & 127;
  if (stage_v_167_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_33_1 ^ 0x2A) * 2) + pub_r001330_12_1) & 127;
  int stage_v_168_2 = (((stage_v_33_2 ^ 0x2A) * 2) + pub_r001330_12_2) & 127;
  if (stage_v_168_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001330_19_1) & 127;
  int stage_v_169_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001330_19_2) & 127;
  if (stage_v_169_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001330_18_1) & 127;
  int stage_v_170_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001330_18_2) & 127;
  if (stage_v_170_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((pub_r001330_4_1 * 2) + 46) & 63;
  int stage_v_171_2 = ((pub_r001330_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001330_8_1) & 127;
  int stage_v_172_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001330_8_2) & 127;
  if (stage_v_172_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((pub_r001330_12_1 * 2) + 13) & 63;
  int stage_v_173_2 = ((pub_r001330_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (((sec_r001330_17_1 ^ 0x2A) * 2) + pub_r001330_11_1) & 127;
  int stage_v_174_2 = (((sec_r001330_17_2 ^ 0x2A) * 2) + pub_r001330_11_2) & 127;
  if (stage_v_174_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001330_6_1) & 127;
  int stage_v_175_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001330_6_2) & 127;
  if (stage_v_175_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = (((stage_v_162_1 ^ 0x2A) * 2) + pub_r001330_17_1) & 127;
  int stage_v_176_2 = (((stage_v_162_2 ^ 0x2A) * 2) + pub_r001330_17_2) & 127;
  if (stage_v_176_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((pub_r001330_9_1 * 2) + 28) & 63;
  int stage_v_177_2 = ((pub_r001330_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001330_12_1 * 2) + 16) & 63;
  int stage_v_178_2 = ((pub_r001330_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001330_15_1) & 127;
  int stage_v_179_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001330_15_2) & 127;
  if (stage_v_179_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001330_20_1) & 127;
  int stage_v_180_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001330_20_2) & 127;
  if (stage_v_180_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001330_7_1) & 127;
  int stage_v_181_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001330_7_2) & 127;
  if (stage_v_181_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = (((sec_r001330_8_1 ^ 0x2A) * 2) + pub_r001330_11_1) & 127;
  int stage_v_182_2 = (((sec_r001330_8_2 ^ 0x2A) * 2) + pub_r001330_11_2) & 127;
  if (stage_v_182_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (((stage_v_168_1 ^ 0x2A) * 2) + pub_r001330_18_1) & 127;
  int stage_v_183_2 = (((stage_v_168_2 ^ 0x2A) * 2) + pub_r001330_18_2) & 127;
  if (stage_v_183_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001330_9_1) & 127;
  int stage_v_184_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001330_9_2) & 127;
  if (stage_v_184_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = (((stage_v_163_1 ^ 0x2A) * 2) + pub_r001330_4_1) & 127;
  int stage_v_185_2 = (((stage_v_163_2 ^ 0x2A) * 2) + pub_r001330_4_2) & 127;
  if (stage_v_185_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = (((sec_r001330_18_1 ^ 0x2A) * 2) + pub_r001330_8_1) & 127;
  int stage_v_186_2 = (((sec_r001330_18_2 ^ 0x2A) * 2) + pub_r001330_8_2) & 127;
  if (stage_v_186_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001330_9_1) & 127;
  int stage_v_187_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001330_9_2) & 127;
  if (stage_v_187_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((pub_r001330_1_1 * 2) + 40) & 63;
  int stage_v_188_2 = ((pub_r001330_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((stage_v_165_1 ^ 0x2A) * 2) + pub_r001330_8_1) & 127;
  int stage_v_189_2 = (((stage_v_165_2 ^ 0x2A) * 2) + pub_r001330_8_2) & 127;
  if (stage_v_189_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((pub_r001330_15_1 * 2) + 26) & 63;
  int stage_v_190_2 = ((pub_r001330_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((sec_r001330_0_1 ^ 0x2A) * 2) + pub_r001330_7_1) & 127;
  int stage_v_191_2 = (((sec_r001330_0_2 ^ 0x2A) * 2) + pub_r001330_7_2) & 127;
  if (stage_v_191_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((pub_r001330_9_1 * 2) + 12) & 63;
  int stage_v_192_2 = ((pub_r001330_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001330_6_1) & 127;
  int stage_v_193_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001330_6_2) & 127;
  if (stage_v_193_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((pub_r001330_3_1 * 2) + 32) & 63;
  int stage_v_194_2 = ((pub_r001330_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001330_14_1) & 127;
  int stage_v_195_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001330_14_2) & 127;
  if (stage_v_195_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((pub_r001330_8_1 * 2) + 24) & 63;
  int stage_v_196_2 = ((pub_r001330_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001330_1_1 * 2) + 15) & 63;
  int stage_v_197_2 = ((pub_r001330_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001330_11_1 * 2) + 36) & 63;
  int stage_v_198_2 = ((pub_r001330_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001330_9_1) & 127;
  int stage_v_199_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001330_9_2) & 127;
  if (stage_v_199_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = (((stage_v_105_1 ^ 0x2A) * 2) + pub_r001330_12_1) & 127;
  int stage_v_200_2 = (((stage_v_105_2 ^ 0x2A) * 2) + pub_r001330_12_2) & 127;
  if (stage_v_200_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001330_6_1) & 127;
  int stage_v_201_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001330_6_2) & 127;
  if (stage_v_201_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001330_10_1) & 127;
  int stage_v_202_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001330_10_2) & 127;
  if (stage_v_202_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001330_8_1) & 127;
  int stage_v_203_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001330_8_2) & 127;
  if (stage_v_203_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001330_1_1) & 127;
  int stage_v_204_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001330_1_2) & 127;
  if (stage_v_204_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001330_5_1) & 127;
  int stage_v_205_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001330_5_2) & 127;
  if (stage_v_205_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = (((stage_v_205_1 ^ 0x2A) * 2) + pub_r001330_6_1) & 127;
  int stage_v_206_2 = (((stage_v_205_2 ^ 0x2A) * 2) + pub_r001330_6_2) & 127;
  if (stage_v_206_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((stage_v_131_1 ^ 0x2A) * 2) + pub_r001330_18_1) & 127;
  int stage_v_207_2 = (((stage_v_131_2 ^ 0x2A) * 2) + pub_r001330_18_2) & 127;
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
  int stage_v_208_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001330_17_1) & 127;
  int stage_v_208_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001330_17_2) & 127;
  if (stage_v_208_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001330_3_1) & 127;
  int stage_v_209_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001330_3_2) & 127;
  if (stage_v_209_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = (((stage_v_168_1 ^ 0x2A) * 2) + pub_r001330_1_1) & 127;
  int stage_v_210_2 = (((stage_v_168_2 ^ 0x2A) * 2) + pub_r001330_1_2) & 127;
  if (stage_v_210_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = (((stage_v_165_1 ^ 0x2A) * 2) + pub_r001330_6_1) & 127;
  int stage_v_211_2 = (((stage_v_165_2 ^ 0x2A) * 2) + pub_r001330_6_2) & 127;
  if (stage_v_211_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((pub_r001330_10_1 * 2) + 28) & 63;
  int stage_v_212_2 = ((pub_r001330_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001330_1_1 * 2) + 47) & 63;
  int stage_v_213_2 = ((pub_r001330_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001330_7_1) & 127;
  int stage_v_214_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001330_7_2) & 127;
  if (stage_v_214_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001330_18_1) & 127;
  int stage_v_215_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001330_18_2) & 127;
  if (stage_v_215_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001330_6_1) & 127;
  int stage_v_216_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001330_6_2) & 127;
  if (stage_v_216_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = (((stage_v_206_1 ^ 0x2A) * 2) + pub_r001330_1_1) & 127;
  int stage_v_217_2 = (((stage_v_206_2 ^ 0x2A) * 2) + pub_r001330_1_2) & 127;
  if (stage_v_217_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((stage_v_166_1 ^ 0x2A) * 2) + pub_r001330_19_1) & 127;
  int stage_v_218_2 = (((stage_v_166_2 ^ 0x2A) * 2) + pub_r001330_19_2) & 127;
  if (stage_v_218_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = (((stage_v_191_1 ^ 0x2A) * 2) + pub_r001330_10_1) & 127;
  int stage_v_219_2 = (((stage_v_191_2 ^ 0x2A) * 2) + pub_r001330_10_2) & 127;
  if (stage_v_219_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((pub_r001330_10_1 * 2) + 5) & 63;
  int stage_v_220_2 = ((pub_r001330_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001330_0_1) & 127;
  int stage_v_221_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001330_0_2) & 127;
  if (stage_v_221_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((pub_r001330_5_1 * 2) + 45) & 63;
  int stage_v_222_2 = ((pub_r001330_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = (((stage_v_208_1 ^ 0x2A) * 2) + pub_r001330_2_1) & 127;
  int stage_v_223_2 = (((stage_v_208_2 ^ 0x2A) * 2) + pub_r001330_2_2) & 127;
  if (stage_v_223_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001330_5_1) & 127;
  int stage_v_224_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001330_5_2) & 127;
  if (stage_v_224_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
  }
  if (stage_v_224_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = (((sec_r001330_16_1 ^ 0x2A) * 2) + pub_r001330_13_1) & 127;
  int stage_v_225_2 = (((sec_r001330_16_2 ^ 0x2A) * 2) + pub_r001330_13_2) & 127;
  if (stage_v_225_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
  }
  if (stage_v_225_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((pub_r001330_20_1 * 2) + 21) & 63;
  int stage_v_226_2 = ((pub_r001330_20_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001330_11_1) & 127;
  int stage_v_227_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001330_11_2) & 127;
  if (stage_v_227_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
  }
  if (stage_v_227_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = (((stage_v_128_1 ^ 0x2A) * 2) + pub_r001330_8_1) & 127;
  int stage_v_228_2 = (((stage_v_128_2 ^ 0x2A) * 2) + pub_r001330_8_2) & 127;
  if (stage_v_228_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = (((sec_r001330_2_1 ^ 0x2A) * 2) + pub_r001330_4_1) & 127;
  int stage_v_229_2 = (((sec_r001330_2_2 ^ 0x2A) * 2) + pub_r001330_4_2) & 127;
  if (stage_v_229_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
  }
  if (stage_v_229_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001330_14_1) & 127;
  int stage_v_230_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001330_14_2) & 127;
  if (stage_v_230_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
  }
  if (stage_v_230_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001330_9_1) & 127;
  int stage_v_231_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001330_9_2) & 127;
  if (stage_v_231_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
  }
  if (stage_v_231_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001330_1_1) & 127;
  int stage_v_232_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001330_1_2) & 127;
  if (stage_v_232_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
  }
  if (stage_v_232_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = (((stage_v_191_1 ^ 0x2A) * 2) + pub_r001330_3_1) & 127;
  int stage_v_233_2 = (((stage_v_191_2 ^ 0x2A) * 2) + pub_r001330_3_2) & 127;
  if (stage_v_233_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
  }
  if (stage_v_233_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = (((stage_v_206_1 ^ 0x2A) * 2) + pub_r001330_3_1) & 127;
  int stage_v_234_2 = (((stage_v_206_2 ^ 0x2A) * 2) + pub_r001330_3_2) & 127;
  if (stage_v_234_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
  }
  if (stage_v_234_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((pub_r001330_5_1 * 2) + 22) & 63;
  int stage_v_235_2 = ((pub_r001330_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001330_12_1) & 127;
  int stage_v_236_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001330_12_2) & 127;
  if (stage_v_236_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
  }
  if (stage_v_236_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001330_9_1) & 127;
  int stage_v_237_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001330_9_2) & 127;
  if (stage_v_237_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
  }
  if (stage_v_237_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001330_20_1 == pub_r001330_20_2);
  __CPROVER_assume(sec_r001330_12_1 != sec_r001330_12_2);
  __CPROVER_assume(pub_r001330_3_1 == pub_r001330_3_2);
  __CPROVER_assume(sec_r001330_15_1 != sec_r001330_15_2);
  __CPROVER_assume(pub_r001330_18_1 == pub_r001330_18_2);
  __CPROVER_assume(pub_r001330_11_1 == pub_r001330_11_2);
  __CPROVER_assume(pub_r001330_17_1 == pub_r001330_17_2);
  __CPROVER_assume(sec_r001330_17_1 != sec_r001330_17_2);
  __CPROVER_assume(sec_r001330_18_1 != sec_r001330_18_2);
  __CPROVER_assume(pub_r001330_9_1 == pub_r001330_9_2);
  __CPROVER_assume(pub_r001330_0_1 == pub_r001330_0_2);
  __CPROVER_assume(pub_r001330_10_1 == pub_r001330_10_2);
  __CPROVER_assume(pub_r001330_19_1 == pub_r001330_19_2);
  __CPROVER_assume(sec_r001330_16_1 != sec_r001330_16_2);
  __CPROVER_assume(sec_r001330_6_1 != sec_r001330_6_2);
  __CPROVER_assume(sec_r001330_4_1 != sec_r001330_4_2);
  __CPROVER_assume(sec_r001330_0_1 != sec_r001330_0_2);
  __CPROVER_assume(pub_r001330_5_1 == pub_r001330_5_2);
  __CPROVER_assume(sec_r001330_14_1 != sec_r001330_14_2);
  __CPROVER_assume(sec_r001330_3_1 != sec_r001330_3_2);
  __CPROVER_assume(pub_r001330_15_1 == pub_r001330_15_2);
  __CPROVER_assume(pub_r001330_1_1 == pub_r001330_1_2);
  __CPROVER_assume(pub_r001330_7_1 == pub_r001330_7_2);
  __CPROVER_assume(sec_r001330_8_1 != sec_r001330_8_2);
  __CPROVER_assume(sec_r001330_11_1 != sec_r001330_11_2);
  __CPROVER_assume(sec_r001330_2_1 != sec_r001330_2_2);
  __CPROVER_assume(pub_r001330_12_1 == pub_r001330_12_2);
  __CPROVER_assume(pub_r001330_2_1 == pub_r001330_2_2);
  __CPROVER_assume(sec_r001330_7_1 != sec_r001330_7_2);
  __CPROVER_assume(sec_r001330_1_1 != sec_r001330_1_2);
  __CPROVER_assume(pub_r001330_6_1 == pub_r001330_6_2);
  __CPROVER_assume(pub_r001330_14_1 == pub_r001330_14_2);
  __CPROVER_assume(sec_r001330_9_1 != sec_r001330_9_2);
  __CPROVER_assume(pub_r001330_8_1 == pub_r001330_8_2);
  __CPROVER_assume(sec_r001330_5_1 != sec_r001330_5_2);
  __CPROVER_assume(pub_r001330_4_1 == pub_r001330_4_2);
  __CPROVER_assume(pub_r001330_13_1 == pub_r001330_13_2);
  __CPROVER_assume(sec_r001330_10_1 != sec_r001330_10_2);
  __CPROVER_assume(sec_r001330_13_1 != sec_r001330_13_2);
  __CPROVER_assume(pub_r001330_16_1 == pub_r001330_16_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.stride == st_var_1_2.stride);
  assert(st_var_1_1.density == st_var_1_2.density);
  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  assert(st_var_1_1.trace == st_var_1_2.trace);
  assert(st_var_1_1.scale == st_var_1_2.scale);
  assert(st_var_1_1.dim == st_var_1_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.watermark == st_var_2_2.watermark);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.nonce == st_var_3_2.nonce);
  assert(st_var_3_1.round_key == st_var_3_2.round_key);
  assert(st_var_3_1.iv == st_var_3_2.iv);
  assert(st_var_3_1.flags == st_var_3_2.flags);
  assert(st_var_3_1.tag == st_var_3_2.tag);
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
}


