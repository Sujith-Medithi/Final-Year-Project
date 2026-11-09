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
struct Transaction_R001560_6013_0
{
  int auth_code;
  int account_id;
  unsigned char status;
  unsigned char balance;
  short rate;
  short fee;
  int buffer[3];
};
struct MatrixBlock_R001560_6013_1
{
  short scale;
  short trace;
  int determinant;
  short density;
  int dim;
  int buffer[3];
};
struct CipherContext_R001560_6013_2
{
  unsigned char tag;
  int nonce;
  int round_key;
  int buffer[3];
};
union PacketPayload_R001560_6013_0
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
void fn_R001560_6013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001560_6013_1 st_1 = {0};
  struct MatrixBlock_R001560_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int pivot_11_1 = 0;
  int pivot_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_11_1 = ((pivot_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_11_2 = ((pivot_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_11_1) & 127;
    acc_2 = (acc_2 + pivot_11_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_28_1)
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

  switch (residue_28_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_11_1 == pivot_11_2);
  assert(residue_28_1 == residue_28_2);
}

int fn_R001560_6013_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001560_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int pivot_11 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_11 = ((pivot_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_11) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_28 = (aux + st.buffer[1]) & 3;
  switch (residue_28)
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

void fn_R001560_6013_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st_1 = {0};
  struct CipherContext_R001560_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int segment_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_90_1)
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

  switch (segment_90_2)
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

  int anchor_45_1 = 0;
  int anchor_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_45_1 = ((anchor_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_45_2 = ((anchor_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_45_1) & 127;
    acc_2 = (acc_2 + anchor_45_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_90_1 == segment_90_2);
  assert(anchor_45_1 == anchor_45_2);
}

int fn_R001560_6013_1(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int segment_90 = (aux + st.buffer[1]) & 3;
  switch (segment_90)
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

  int anchor_45 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_45 = ((anchor_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_45) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001560_6013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st_1 = {0};
  struct CipherContext_R001560_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int quotient_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_74_1) & 63;
  aux_2 = (aux_2 + quotient_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_44_1 = local_arr_1[aux_1 % 3];
  int window_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_44_2 * 2)) & 127;
  int checksum_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_96_1 > 15)
  {
    acc_1 = ((acc_1 + (checksum_96_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_96_2 > 15)
  {
    acc_2 = ((acc_2 + (checksum_96_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_96_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_74_1 == quotient_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_44_1 == window_44_2);
  assert(checksum_96_1 == checksum_96_2);
}

int fn_R001560_6013_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int quotient_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_74) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_44 = local_arr[aux % 3];
  acc = (acc + (window_44 * 2)) & 127;
  int checksum_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_96 > 15)
  {
    acc = ((acc + (checksum_96 * 2)) + 5) & 127;
    aux ^= checksum_96 & 15;
  }
  else
  {
    acc = ((acc - checksum_96) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001560_6013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st_1 = {0};
  struct CipherContext_R001560_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_55_1 = local_arr_1[aux_1 % 3];
  int mask_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_55_2 * 2)) & 127;
  int parity_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_21_1)
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

  switch (parity_21_2)
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

  int vector_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_19_1 > 35)
  {
    acc_1 = ((acc_1 + (vector_19_1 * 2)) + 5) & 127;
    aux_1 ^= vector_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_19_2 > 35)
  {
    acc_2 = ((acc_2 + (vector_19_2 * 2)) + 5) & 127;
    aux_2 ^= vector_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_19_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_55_1 == mask_55_2);
  assert(parity_21_1 == parity_21_2);
  assert(vector_19_1 == vector_19_2);
}

int fn_R001560_6013_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int mask_55 = local_arr[aux % 3];
  acc = (acc + (mask_55 * 2)) & 127;
  int parity_21 = (aux + st.buffer[1]) & 3;
  switch (parity_21)
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

  int vector_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_19 > 35)
  {
    acc = ((acc + (vector_19 * 2)) + 5) & 127;
    aux ^= vector_19 & 15;
  }
  else
  {
    acc = ((acc - vector_19) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001560_6013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001560_6013_1 st_1 = {0};
  struct MatrixBlock_R001560_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int stride_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_35_1) & 63;
  aux_2 = (aux_2 + stride_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_65_1 > 22)
  {
    acc_1 = ((acc_1 + (mask_65_1 * 2)) + 5) & 127;
    aux_1 ^= mask_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_65_2 > 22)
  {
    acc_2 = ((acc_2 + (mask_65_2 * 2)) + 5) & 127;
    aux_2 ^= mask_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_75_1)
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

  switch (parity_75_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_56_1 = local_arr_1[aux_1 % 3];
  int pivot_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_35_1 == stride_35_2);
  assert(mask_65_1 == mask_65_2);
  assert(parity_75_1 == parity_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_56_1 == pivot_56_2);
}

int fn_R001560_6013_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001560_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int stride_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_35) & 63;
  acc ^= aux;
  int mask_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_65 > 22)
  {
    acc = ((acc + (mask_65 * 2)) + 5) & 127;
    aux ^= mask_65 & 15;
  }
  else
  {
    acc = ((acc - mask_65) + 11) & 127;
    aux += 3;
  }
  int parity_75 = (aux + st.buffer[1]) & 3;
  switch (parity_75)
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

  int local_arr[3] = {4, 9, 15};
  int pivot_56 = local_arr[aux % 3];
  acc = (acc + (pivot_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001560_6013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001560_6013_1 st_1 = {0};
  struct MatrixBlock_R001560_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int index_reg_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_86_1)
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

  switch (index_reg_86_2)
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

  int stride_20_1 = 0;
  int stride_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_20_1 = ((stride_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_20_2 = ((stride_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_20_1) & 127;
    acc_2 = (acc_2 + stride_20_2) & 127;
  }

  int delta_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_10_1 > 46)
  {
    acc_1 = ((acc_1 + (delta_10_1 * 2)) + 5) & 127;
    aux_1 ^= delta_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_10_2 > 46)
  {
    acc_2 = ((acc_2 + (delta_10_2 * 2)) + 5) & 127;
    aux_2 ^= delta_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_88_1 = local_arr_1[aux_1 % 3];
  int cursor_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_88_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_86_1 == index_reg_86_2);
  assert(stride_20_1 == stride_20_2);
  assert(delta_10_1 == delta_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_88_1 == cursor_88_2);
}

int fn_R001560_6013_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001560_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int index_reg_86 = (aux + st.buffer[1]) & 3;
  switch (index_reg_86)
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

  int stride_20 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_20 = ((stride_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_20) & 127;
  }

  int delta_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_10 > 46)
  {
    acc = ((acc + (delta_10 * 2)) + 5) & 127;
    aux ^= delta_10 & 15;
  }
  else
  {
    acc = ((acc - delta_10) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_88 = local_arr[aux % 3];
  acc = (acc + (cursor_88 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001560_6013_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st_1 = {0};
  struct CipherContext_R001560_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int delta_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_38_1 > 19)
  {
    acc_1 = ((acc_1 + (delta_38_1 * 2)) + 5) & 127;
    aux_1 ^= delta_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_38_2 > 19)
  {
    acc_2 = ((acc_2 + (delta_38_2 * 2)) + 5) & 127;
    aux_2 ^= delta_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_15_1 = local_arr_1[aux_1 % 3];
  int bound_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_15_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_38_1 == delta_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_15_1 == bound_15_2);
}

int fn_R001560_6013_6(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int delta_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_38 > 19)
  {
    acc = ((acc + (delta_38 * 2)) + 5) & 127;
    aux ^= delta_38 & 15;
  }
  else
  {
    acc = ((acc - delta_38) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_15 = local_arr[aux % 3];
  acc = (acc + (bound_15 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001560_6013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st_1 = {0};
  struct CipherContext_R001560_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_38_1 > 17)
  {
    acc_1 = ((acc_1 + (threshold_38_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_38_2 > 17)
  {
    acc_2 = ((acc_2 + (threshold_38_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_73_1 = local_arr_1[aux_1 % 3];
  int damping_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_73_2 * 2)) & 127;
  int threshold_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_12_1) & 63;
  aux_2 = (aux_2 + threshold_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_38_1 == threshold_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_73_1 == damping_73_2);
  assert(threshold_12_1 == threshold_12_2);
}

int fn_R001560_6013_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_38 > 17)
  {
    acc = ((acc + (threshold_38 * 2)) + 5) & 127;
    aux ^= threshold_38 & 15;
  }
  else
  {
    acc = ((acc - threshold_38) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int damping_73 = local_arr[aux % 3];
  acc = (acc + (damping_73 * 2)) & 127;
  int threshold_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_12) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001560_6013_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st_1 = {0};
  struct CipherContext_R001560_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int sample_28_1 = 0;
  int sample_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_28_1 = ((sample_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_28_2 = ((sample_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_28_1) & 127;
    acc_2 = (acc_2 + sample_28_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_80_1 = local_arr_1[aux_1 % 3];
  int segment_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_80_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_92_1 > 43)
  {
    acc_1 = ((acc_1 + (parity_92_1 * 2)) + 5) & 127;
    aux_1 ^= parity_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_92_2 > 43)
  {
    acc_2 = ((acc_2 + (parity_92_2 * 2)) + 5) & 127;
    aux_2 ^= parity_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_92_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_28_1 == sample_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_80_1 == segment_80_2);
  assert(parity_92_1 == parity_92_2);
}

int fn_R001560_6013_8(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int sample_28 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_28 = ((sample_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_28) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int segment_80 = local_arr[aux % 3];
  acc = (acc + (segment_80 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_92 > 43)
  {
    acc = ((acc + (parity_92 * 2)) + 5) & 127;
    aux ^= parity_92 & 15;
  }
  else
  {
    acc = ((acc - parity_92) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001560_6013_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st_1 = {0};
  struct CipherContext_R001560_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int index_reg_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_94_1) & 63;
  aux_2 = (aux_2 + index_reg_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_71_1 = 0;
  int coefficient_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_71_1 = ((coefficient_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_71_2 = ((coefficient_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_71_1) & 127;
    acc_2 = (acc_2 + coefficient_71_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_94_1 == index_reg_94_2);
  assert(coefficient_71_1 == coefficient_71_2);
}

int fn_R001560_6013_9(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int index_reg_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_94) & 63;
  acc ^= aux;
  int coefficient_71 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_71 = ((coefficient_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_71) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001560_6013_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001560_6013_0 st_1 = {0};
  struct Transaction_R001560_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int metric_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_36_1 > 33)
  {
    acc_1 = ((acc_1 + (metric_36_1 * 2)) + 5) & 127;
    aux_1 ^= metric_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_36_2 > 33)
  {
    acc_2 = ((acc_2 + (metric_36_2 * 2)) + 5) & 127;
    aux_2 ^= metric_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_36_2) + 11) & 127;
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_30_1) & 63;
  aux_2 = (aux_2 + segment_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_36_1 == metric_36_2);
  assert(metric_42_1 == metric_42_2);
  assert(segment_30_1 == segment_30_2);
}

int fn_R001560_6013_10(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001560_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int metric_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_36 > 33)
  {
    acc = ((acc + (metric_36 * 2)) + 5) & 127;
    aux ^= metric_36 & 15;
  }
  else
  {
    acc = ((acc - metric_36) + 11) & 127;
    aux += 3;
  }
  int metric_42 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_42 = ((metric_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_42) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_30) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001560_6013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001560_6013_1 st_1 = {0};
  struct MatrixBlock_R001560_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int tracker_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_16_1)
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

  switch (tracker_16_2)
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

  int segment_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_29_1 > 13)
  {
    acc_1 = ((acc_1 + (segment_29_1 * 2)) + 5) & 127;
    aux_1 ^= segment_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_29_2 > 13)
  {
    acc_2 = ((acc_2 + (segment_29_2 * 2)) + 5) & 127;
    aux_2 ^= segment_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_16_1 == tracker_16_2);
  assert(segment_29_1 == segment_29_2);
}

int fn_R001560_6013_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001560_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int tracker_16 = (aux + st.buffer[1]) & 3;
  switch (tracker_16)
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

  int segment_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_29 > 13)
  {
    acc = ((acc + (segment_29 * 2)) + 5) & 127;
    aux ^= segment_29 & 15;
  }
  else
  {
    acc = ((acc - segment_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001560_6013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st_1 = {0};
  struct CipherContext_R001560_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int weight_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_88_1)
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

  switch (weight_88_2)
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

  int stride_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_15_1 > 25)
  {
    acc_1 = ((acc_1 + (stride_15_1 * 2)) + 5) & 127;
    aux_1 ^= stride_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_15_2 > 25)
  {
    acc_2 = ((acc_2 + (stride_15_2 * 2)) + 5) & 127;
    aux_2 ^= stride_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_15_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_88_1 == weight_88_2);
  assert(stride_15_1 == stride_15_2);
}

int fn_R001560_6013_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int weight_88 = (aux + st.buffer[1]) & 3;
  switch (weight_88)
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

  int stride_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_15 > 25)
  {
    acc = ((acc + (stride_15 * 2)) + 5) & 127;
    aux ^= stride_15 & 15;
  }
  else
  {
    acc = ((acc - stride_15) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001560_6013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st_1 = {0};
  struct CipherContext_R001560_6013_2 st_2 = {0};
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
  int weight_18_1 = 0;
  int weight_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_18_1 = ((weight_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_18_2 = ((weight_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_18_1) & 127;
    acc_2 = (acc_2 + weight_18_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_18_1 == weight_18_2);
}

int fn_R001560_6013_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_18 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_18 = ((weight_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_18) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001560_6013_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001560_6013_0 st_1 = {0};
  struct Transaction_R001560_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int window_27_1 = 0;
  int window_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_27_1 = ((window_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_27_2 = ((window_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_27_1) & 127;
    acc_2 = (acc_2 + window_27_2) & 127;
  }

  int vector_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_41_1) & 63;
  aux_2 = (aux_2 + vector_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_57_1 = local_arr_1[aux_1 % 3];
  int parity_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_57_2 * 2)) & 127;
  int cursor_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_97_1 > 13)
  {
    acc_1 = ((acc_1 + (cursor_97_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_97_2 > 13)
  {
    acc_2 = ((acc_2 + (cursor_97_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_27_1 == window_27_2);
  assert(vector_41_1 == vector_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_57_1 == parity_57_2);
  assert(cursor_97_1 == cursor_97_2);
}

int fn_R001560_6013_14(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001560_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int window_27 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_27 = ((window_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_27) & 127;
  }

  int vector_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_41) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_57 = local_arr[aux % 3];
  acc = (acc + (parity_57 * 2)) & 127;
  int cursor_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_97 > 13)
  {
    acc = ((acc + (cursor_97 * 2)) + 5) & 127;
    aux ^= cursor_97 & 15;
  }
  else
  {
    acc = ((acc - cursor_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001560_6013_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001560_6013_0 st_1 = {0};
  struct Transaction_R001560_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int cursor_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_27_1 > 32)
  {
    acc_1 = ((acc_1 + (cursor_27_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_27_2 > 32)
  {
    acc_2 = ((acc_2 + (cursor_27_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_34_1) & 63;
  aux_2 = (aux_2 + window_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_27_1 == cursor_27_2);
  assert(window_34_1 == window_34_2);
}

int fn_R001560_6013_15(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001560_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int cursor_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_27 > 32)
  {
    acc = ((acc + (cursor_27 * 2)) + 5) & 127;
    aux ^= cursor_27 & 15;
  }
  else
  {
    acc = ((acc - cursor_27) + 11) & 127;
    aux += 3;
  }
  int window_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_34) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001560_6013_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st_1 = {0};
  struct CipherContext_R001560_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_48_1)
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

  switch (residue_48_2)
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

  int stride_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_32_1) & 63;
  aux_2 = (aux_2 + stride_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_39_1 > 13)
  {
    acc_1 = ((acc_1 + (weight_39_1 * 2)) + 5) & 127;
    aux_1 ^= weight_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_39_2 > 13)
  {
    acc_2 = ((acc_2 + (weight_39_2 * 2)) + 5) & 127;
    aux_2 ^= weight_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_48_1 == residue_48_2);
  assert(stride_32_1 == stride_32_2);
  assert(weight_39_1 == weight_39_2);
}

int fn_R001560_6013_16(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001560_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_48 = (aux + st.buffer[1]) & 3;
  switch (residue_48)
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

  int stride_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_32) & 63;
  acc ^= aux;
  int weight_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_39 > 13)
  {
    acc = ((acc + (weight_39 * 2)) + 5) & 127;
    aux ^= weight_39 & 15;
  }
  else
  {
    acc = ((acc - weight_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001560_6013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001560_6013_1 st_1 = {0};
  struct MatrixBlock_R001560_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_57_1) & 63;
  aux_2 = (aux_2 + threshold_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_57_1 == threshold_57_2);
}

int fn_R001560_6013_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001560_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_57) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001560_0_1;
  int sec_r001560_0_2;
  int sec_r001560_1_1;
  int sec_r001560_1_2;
  int sec_r001560_2_1;
  int sec_r001560_2_2;
  int sec_r001560_3_1;
  int sec_r001560_3_2;
  int sec_r001560_4_1;
  int sec_r001560_4_2;
  int sec_r001560_5_1;
  int sec_r001560_5_2;
  int sec_r001560_6_1;
  int sec_r001560_6_2;
  int sec_r001560_7_1;
  int sec_r001560_7_2;
  int sec_r001560_8_1;
  int sec_r001560_8_2;
  int sec_r001560_9_1;
  int sec_r001560_9_2;
  int sec_r001560_10_1;
  int sec_r001560_10_2;
  int sec_r001560_11_1;
  int sec_r001560_11_2;
  int sec_r001560_12_1;
  int sec_r001560_12_2;
  int sec_r001560_13_1;
  int sec_r001560_13_2;
  int sec_r001560_14_1;
  int sec_r001560_14_2;
  int sec_r001560_15_1;
  int sec_r001560_15_2;
  int sec_r001560_16_1;
  int sec_r001560_16_2;
  int sec_r001560_17_1;
  int sec_r001560_17_2;
  int sec_r001560_18_1;
  int sec_r001560_18_2;
  int sec_r001560_19_1;
  int sec_r001560_19_2;
  int sec_r001560_20_1;
  int sec_r001560_20_2;
  int sec_r001560_21_1;
  int sec_r001560_21_2;
  int sec_r001560_22_1;
  int sec_r001560_22_2;
  int sec_r001560_23_1;
  int sec_r001560_23_2;
  int pub_r001560_0_1;
  int pub_r001560_0_2;
  int pub_r001560_1_1;
  int pub_r001560_1_2;
  int pub_r001560_2_1;
  int pub_r001560_2_2;
  int pub_r001560_3_1;
  int pub_r001560_3_2;
  int pub_r001560_4_1;
  int pub_r001560_4_2;
  int pub_r001560_5_1;
  int pub_r001560_5_2;
  int pub_r001560_6_1;
  int pub_r001560_6_2;
  int pub_r001560_7_1;
  int pub_r001560_7_2;
  int pub_r001560_8_1;
  int pub_r001560_8_2;
  int pub_r001560_9_1;
  int pub_r001560_9_2;
  int pub_r001560_10_1;
  int pub_r001560_10_2;
  int pub_r001560_11_1;
  int pub_r001560_11_2;
  int pub_r001560_12_1;
  int pub_r001560_12_2;
  int pub_r001560_13_1;
  int pub_r001560_13_2;
  int pub_r001560_14_1;
  int pub_r001560_14_2;
  int pub_r001560_15_1;
  int pub_r001560_15_2;
  int pub_r001560_16_1;
  int pub_r001560_16_2;
  int pub_r001560_17_1;
  int pub_r001560_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001560_0_1 >= (-100)) && (pub_r001560_0_1 <= 100));
  __CPROVER_assume((pub_r001560_0_2 >= (-100)) && (pub_r001560_0_2 <= 100));
  __CPROVER_assume((pub_r001560_1_1 >= (-100)) && (pub_r001560_1_1 <= 100));
  __CPROVER_assume((pub_r001560_1_2 >= (-100)) && (pub_r001560_1_2 <= 100));
  __CPROVER_assume((pub_r001560_2_1 >= (-100)) && (pub_r001560_2_1 <= 100));
  __CPROVER_assume((pub_r001560_2_2 >= (-100)) && (pub_r001560_2_2 <= 100));
  __CPROVER_assume((pub_r001560_3_1 >= (-100)) && (pub_r001560_3_1 <= 100));
  __CPROVER_assume((pub_r001560_3_2 >= (-100)) && (pub_r001560_3_2 <= 100));
  __CPROVER_assume((pub_r001560_4_1 >= (-100)) && (pub_r001560_4_1 <= 100));
  __CPROVER_assume((pub_r001560_4_2 >= (-100)) && (pub_r001560_4_2 <= 100));
  __CPROVER_assume((pub_r001560_5_1 >= (-100)) && (pub_r001560_5_1 <= 100));
  __CPROVER_assume((pub_r001560_5_2 >= (-100)) && (pub_r001560_5_2 <= 100));
  __CPROVER_assume((pub_r001560_6_1 >= (-100)) && (pub_r001560_6_1 <= 100));
  __CPROVER_assume((pub_r001560_6_2 >= (-100)) && (pub_r001560_6_2 <= 100));
  __CPROVER_assume((pub_r001560_7_1 >= (-100)) && (pub_r001560_7_1 <= 100));
  __CPROVER_assume((pub_r001560_7_2 >= (-100)) && (pub_r001560_7_2 <= 100));
  __CPROVER_assume((pub_r001560_8_1 >= (-100)) && (pub_r001560_8_1 <= 100));
  __CPROVER_assume((pub_r001560_8_2 >= (-100)) && (pub_r001560_8_2 <= 100));
  __CPROVER_assume((pub_r001560_9_1 >= (-100)) && (pub_r001560_9_1 <= 100));
  __CPROVER_assume((pub_r001560_9_2 >= (-100)) && (pub_r001560_9_2 <= 100));
  __CPROVER_assume((pub_r001560_10_1 >= (-100)) && (pub_r001560_10_1 <= 100));
  __CPROVER_assume((pub_r001560_10_2 >= (-100)) && (pub_r001560_10_2 <= 100));
  __CPROVER_assume((pub_r001560_11_1 >= (-100)) && (pub_r001560_11_1 <= 100));
  __CPROVER_assume((pub_r001560_11_2 >= (-100)) && (pub_r001560_11_2 <= 100));
  __CPROVER_assume((pub_r001560_12_1 >= (-100)) && (pub_r001560_12_1 <= 100));
  __CPROVER_assume((pub_r001560_12_2 >= (-100)) && (pub_r001560_12_2 <= 100));
  __CPROVER_assume((pub_r001560_13_1 >= (-100)) && (pub_r001560_13_1 <= 100));
  __CPROVER_assume((pub_r001560_13_2 >= (-100)) && (pub_r001560_13_2 <= 100));
  __CPROVER_assume((pub_r001560_14_1 >= (-100)) && (pub_r001560_14_1 <= 100));
  __CPROVER_assume((pub_r001560_14_2 >= (-100)) && (pub_r001560_14_2 <= 100));
  __CPROVER_assume((pub_r001560_15_1 >= (-100)) && (pub_r001560_15_1 <= 100));
  __CPROVER_assume((pub_r001560_15_2 >= (-100)) && (pub_r001560_15_2 <= 100));
  __CPROVER_assume((pub_r001560_16_1 >= (-100)) && (pub_r001560_16_1 <= 100));
  __CPROVER_assume((pub_r001560_16_2 >= (-100)) && (pub_r001560_16_2 <= 100));
  __CPROVER_assume((pub_r001560_17_1 >= (-100)) && (pub_r001560_17_1 <= 100));
  __CPROVER_assume((pub_r001560_17_2 >= (-100)) && (pub_r001560_17_2 <= 100));
  __CPROVER_assume((sec_r001560_0_1 >= 0) && (sec_r001560_0_1 <= 255));
  __CPROVER_assume((sec_r001560_0_2 >= 0) && (sec_r001560_0_2 <= 255));
  __CPROVER_assume((sec_r001560_1_1 >= 0) && (sec_r001560_1_1 <= 255));
  __CPROVER_assume((sec_r001560_1_2 >= 0) && (sec_r001560_1_2 <= 255));
  __CPROVER_assume((sec_r001560_2_1 >= 0) && (sec_r001560_2_1 <= 255));
  __CPROVER_assume((sec_r001560_2_2 >= 0) && (sec_r001560_2_2 <= 255));
  __CPROVER_assume((sec_r001560_3_1 >= 0) && (sec_r001560_3_1 <= 255));
  __CPROVER_assume((sec_r001560_3_2 >= 0) && (sec_r001560_3_2 <= 255));
  __CPROVER_assume((sec_r001560_4_1 >= 0) && (sec_r001560_4_1 <= 255));
  __CPROVER_assume((sec_r001560_4_2 >= 0) && (sec_r001560_4_2 <= 255));
  __CPROVER_assume((sec_r001560_5_1 >= 0) && (sec_r001560_5_1 <= 255));
  __CPROVER_assume((sec_r001560_5_2 >= 0) && (sec_r001560_5_2 <= 255));
  __CPROVER_assume((sec_r001560_6_1 >= 0) && (sec_r001560_6_1 <= 255));
  __CPROVER_assume((sec_r001560_6_2 >= 0) && (sec_r001560_6_2 <= 255));
  __CPROVER_assume((sec_r001560_7_1 >= 0) && (sec_r001560_7_1 <= 255));
  __CPROVER_assume((sec_r001560_7_2 >= 0) && (sec_r001560_7_2 <= 255));
  __CPROVER_assume((sec_r001560_8_1 >= 0) && (sec_r001560_8_1 <= 255));
  __CPROVER_assume((sec_r001560_8_2 >= 0) && (sec_r001560_8_2 <= 255));
  __CPROVER_assume((sec_r001560_9_1 >= 0) && (sec_r001560_9_1 <= 255));
  __CPROVER_assume((sec_r001560_9_2 >= 0) && (sec_r001560_9_2 <= 255));
  __CPROVER_assume((sec_r001560_10_1 >= 0) && (sec_r001560_10_1 <= 255));
  __CPROVER_assume((sec_r001560_10_2 >= 0) && (sec_r001560_10_2 <= 255));
  __CPROVER_assume((sec_r001560_11_1 >= 0) && (sec_r001560_11_1 <= 255));
  __CPROVER_assume((sec_r001560_11_2 >= 0) && (sec_r001560_11_2 <= 255));
  __CPROVER_assume((sec_r001560_12_1 >= 0) && (sec_r001560_12_1 <= 255));
  __CPROVER_assume((sec_r001560_12_2 >= 0) && (sec_r001560_12_2 <= 255));
  __CPROVER_assume((sec_r001560_13_1 >= 0) && (sec_r001560_13_1 <= 255));
  __CPROVER_assume((sec_r001560_13_2 >= 0) && (sec_r001560_13_2 <= 255));
  __CPROVER_assume((sec_r001560_14_1 >= 0) && (sec_r001560_14_1 <= 255));
  __CPROVER_assume((sec_r001560_14_2 >= 0) && (sec_r001560_14_2 <= 255));
  __CPROVER_assume((sec_r001560_15_1 >= 0) && (sec_r001560_15_1 <= 255));
  __CPROVER_assume((sec_r001560_15_2 >= 0) && (sec_r001560_15_2 <= 255));
  __CPROVER_assume((sec_r001560_16_1 >= 0) && (sec_r001560_16_1 <= 255));
  __CPROVER_assume((sec_r001560_16_2 >= 0) && (sec_r001560_16_2 <= 255));
  __CPROVER_assume((sec_r001560_17_1 >= 0) && (sec_r001560_17_1 <= 255));
  __CPROVER_assume((sec_r001560_17_2 >= 0) && (sec_r001560_17_2 <= 255));
  __CPROVER_assume((sec_r001560_18_1 >= 0) && (sec_r001560_18_1 <= 255));
  __CPROVER_assume((sec_r001560_18_2 >= 0) && (sec_r001560_18_2 <= 255));
  __CPROVER_assume((sec_r001560_19_1 >= 0) && (sec_r001560_19_1 <= 255));
  __CPROVER_assume((sec_r001560_19_2 >= 0) && (sec_r001560_19_2 <= 255));
  __CPROVER_assume((sec_r001560_20_1 >= 0) && (sec_r001560_20_1 <= 255));
  __CPROVER_assume((sec_r001560_20_2 >= 0) && (sec_r001560_20_2 <= 255));
  __CPROVER_assume((sec_r001560_21_1 >= 0) && (sec_r001560_21_1 <= 255));
  __CPROVER_assume((sec_r001560_21_2 >= 0) && (sec_r001560_21_2 <= 255));
  __CPROVER_assume((sec_r001560_22_1 >= 0) && (sec_r001560_22_1 <= 255));
  __CPROVER_assume((sec_r001560_22_2 >= 0) && (sec_r001560_22_2 <= 255));
  __CPROVER_assume((sec_r001560_23_1 >= 0) && (sec_r001560_23_1 <= 255));
  __CPROVER_assume((sec_r001560_23_2 >= 0) && (sec_r001560_23_2 <= 255));
  struct Transaction_R001560_6013_0 st_var_0_1 = {0};
  struct Transaction_R001560_6013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001560_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001560_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001560_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001560_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001560_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001560_0_2 + 7) & 15;
  struct MatrixBlock_R001560_6013_1 st_var_1_1 = {0};
  struct MatrixBlock_R001560_6013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001560_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001560_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001560_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001560_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001560_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001560_0_2 + 9) & 15;
  struct CipherContext_R001560_6013_2 st_var_2_1 = {0};
  struct CipherContext_R001560_6013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001560_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001560_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001560_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001560_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001560_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001560_0_2 + 11) & 15;
  union PacketPayload_R001560_6013_0 u_var_1;
  union PacketPayload_R001560_6013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001560_6013_0(sec_r001560_0_1, sec_r001560_1_1, pub_r001560_2_1, pub_r001560_3_1, pub_r001560_4_1);
  int helper_flow_0_2 = fn_R001560_6013_0(sec_r001560_0_2, sec_r001560_1_2, pub_r001560_2_2, pub_r001560_3_2, pub_r001560_4_2);
  fn_R001560_6013_0_2(sec_r001560_0_1, sec_r001560_1_1, pub_r001560_2_1, pub_r001560_3_1, pub_r001560_4_1, sec_r001560_0_2, sec_r001560_1_2, pub_r001560_2_2, pub_r001560_3_2, pub_r001560_4_2);
  int helper_flow_1_1 = fn_R001560_6013_1(sec_r001560_1_1, sec_r001560_2_1, pub_r001560_3_1);
  int helper_flow_1_2 = fn_R001560_6013_1(sec_r001560_1_2, sec_r001560_2_2, pub_r001560_3_2);
  fn_R001560_6013_1_2(sec_r001560_1_1, sec_r001560_2_1, pub_r001560_3_1, sec_r001560_1_2, sec_r001560_2_2, pub_r001560_3_2);
  int helper_flow_2_1 = fn_R001560_6013_2(sec_r001560_2_1, pub_r001560_3_1, pub_r001560_4_1, pub_r001560_5_1, pub_r001560_6_1);
  int helper_flow_2_2 = fn_R001560_6013_2(sec_r001560_2_2, pub_r001560_3_2, pub_r001560_4_2, pub_r001560_5_2, pub_r001560_6_2);
  fn_R001560_6013_2_2(sec_r001560_2_1, pub_r001560_3_1, pub_r001560_4_1, pub_r001560_5_1, pub_r001560_6_1, sec_r001560_2_2, pub_r001560_3_2, pub_r001560_4_2, pub_r001560_5_2, pub_r001560_6_2);
  int helper_flow_3_1 = fn_R001560_6013_3(sec_r001560_3_1, sec_r001560_4_1, pub_r001560_5_1, pub_r001560_6_1);
  int helper_flow_3_2 = fn_R001560_6013_3(sec_r001560_3_2, sec_r001560_4_2, pub_r001560_5_2, pub_r001560_6_2);
  fn_R001560_6013_3_2(sec_r001560_3_1, sec_r001560_4_1, pub_r001560_5_1, pub_r001560_6_1, sec_r001560_3_2, sec_r001560_4_2, pub_r001560_5_2, pub_r001560_6_2);
  int helper_flow_4_1 = fn_R001560_6013_4(sec_r001560_4_1, sec_r001560_5_1, pub_r001560_6_1, pub_r001560_7_1);
  int helper_flow_4_2 = fn_R001560_6013_4(sec_r001560_4_2, sec_r001560_5_2, pub_r001560_6_2, pub_r001560_7_2);
  fn_R001560_6013_4_2(sec_r001560_4_1, sec_r001560_5_1, pub_r001560_6_1, pub_r001560_7_1, sec_r001560_4_2, sec_r001560_5_2, pub_r001560_6_2, pub_r001560_7_2);
  int helper_flow_5_1 = fn_R001560_6013_5(sec_r001560_5_1, sec_r001560_6_1, pub_r001560_7_1, pub_r001560_8_1, pub_r001560_9_1);
  int helper_flow_5_2 = fn_R001560_6013_5(sec_r001560_5_2, sec_r001560_6_2, pub_r001560_7_2, pub_r001560_8_2, pub_r001560_9_2);
  fn_R001560_6013_5_2(sec_r001560_5_1, sec_r001560_6_1, pub_r001560_7_1, pub_r001560_8_1, pub_r001560_9_1, sec_r001560_5_2, sec_r001560_6_2, pub_r001560_7_2, pub_r001560_8_2, pub_r001560_9_2);
  int helper_flow_6_1 = fn_R001560_6013_6(sec_r001560_6_1, pub_r001560_7_1);
  int helper_flow_6_2 = fn_R001560_6013_6(sec_r001560_6_2, pub_r001560_7_2);
  fn_R001560_6013_6_2(sec_r001560_6_1, pub_r001560_7_1, sec_r001560_6_2, pub_r001560_7_2);
  int helper_flow_7_1 = fn_R001560_6013_7(sec_r001560_7_1, sec_r001560_8_1, pub_r001560_9_1, pub_r001560_10_1, pub_r001560_11_1);
  int helper_flow_7_2 = fn_R001560_6013_7(sec_r001560_7_2, sec_r001560_8_2, pub_r001560_9_2, pub_r001560_10_2, pub_r001560_11_2);
  fn_R001560_6013_7_2(sec_r001560_7_1, sec_r001560_8_1, pub_r001560_9_1, pub_r001560_10_1, pub_r001560_11_1, sec_r001560_7_2, sec_r001560_8_2, pub_r001560_9_2, pub_r001560_10_2, pub_r001560_11_2);
  int helper_flow_8_1 = fn_R001560_6013_8(sec_r001560_8_1, sec_r001560_9_1);
  int helper_flow_8_2 = fn_R001560_6013_8(sec_r001560_8_2, sec_r001560_9_2);
  fn_R001560_6013_8_2(sec_r001560_8_1, sec_r001560_9_1, sec_r001560_8_2, sec_r001560_9_2);
  int stage_v_0_1 = ((pub_r001560_15_1 * 2) + 35) & 63;
  int stage_v_0_2 = ((pub_r001560_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001560_9_1 * 2) + 12) & 63;
  int stage_v_1_2 = ((pub_r001560_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001560_20_1 ^ 0x2A) * 2) + pub_r001560_3_1) & 127;
  int stage_v_2_2 = (((sec_r001560_20_2 ^ 0x2A) * 2) + pub_r001560_3_2) & 127;
  if (stage_v_2_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001560_2_1) & 127;
  int stage_v_3_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001560_2_2) & 127;
  if (stage_v_3_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((pub_r001560_13_1 * 2) + 12) & 63;
  int stage_v_4_2 = ((pub_r001560_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001560_12_1 * 2) + 25) & 63;
  int stage_v_5_2 = ((pub_r001560_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (((sec_r001560_5_1 ^ 0x2A) * 2) + pub_r001560_2_1) & 127;
  int stage_v_6_2 = (((sec_r001560_5_2 ^ 0x2A) * 2) + pub_r001560_2_2) & 127;
  if (stage_v_6_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((sec_r001560_20_1 ^ 0x2A) * 2) + pub_r001560_10_1) & 127;
  int stage_v_7_2 = (((sec_r001560_20_2 ^ 0x2A) * 2) + pub_r001560_10_2) & 127;
  if (stage_v_7_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((sec_r001560_8_1 ^ 0x2A) * 2) + pub_r001560_14_1) & 127;
  int stage_v_8_2 = (((sec_r001560_8_2 ^ 0x2A) * 2) + pub_r001560_14_2) & 127;
  if (stage_v_8_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001560_3_1) & 127;
  int stage_v_9_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001560_3_2) & 127;
  if (stage_v_9_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (((sec_r001560_5_1 ^ 0x2A) * 2) + pub_r001560_0_1) & 127;
  int stage_v_10_2 = (((sec_r001560_5_2 ^ 0x2A) * 2) + pub_r001560_0_2) & 127;
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
  int stage_v_11_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001560_15_1) & 127;
  int stage_v_11_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001560_15_2) & 127;
  if (stage_v_11_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001560_12_1) & 127;
  int stage_v_12_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001560_12_2) & 127;
  if (stage_v_12_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((pub_r001560_14_1 * 2) + 7) & 63;
  int stage_v_13_2 = ((pub_r001560_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((sec_r001560_23_1 ^ 0x2A) * 2) + pub_r001560_15_1) & 127;
  int stage_v_14_2 = (((sec_r001560_23_2 ^ 0x2A) * 2) + pub_r001560_15_2) & 127;
  if (stage_v_14_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((pub_r001560_2_1 * 2) + 35) & 63;
  int stage_v_15_2 = ((pub_r001560_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((sec_r001560_20_1 ^ 0x2A) * 2) + pub_r001560_5_1) & 127;
  int stage_v_16_2 = (((sec_r001560_20_2 ^ 0x2A) * 2) + pub_r001560_5_2) & 127;
  if (stage_v_16_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((sec_r001560_5_1 ^ 0x2A) * 2) + pub_r001560_4_1) & 127;
  int stage_v_17_2 = (((sec_r001560_5_2 ^ 0x2A) * 2) + pub_r001560_4_2) & 127;
  if (stage_v_17_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((sec_r001560_4_1 ^ 0x2A) * 2) + pub_r001560_12_1) & 127;
  int stage_v_18_2 = (((sec_r001560_4_2 ^ 0x2A) * 2) + pub_r001560_12_2) & 127;
  if (stage_v_18_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((sec_r001560_22_1 ^ 0x2A) * 2) + pub_r001560_8_1) & 127;
  int stage_v_19_2 = (((sec_r001560_22_2 ^ 0x2A) * 2) + pub_r001560_8_2) & 127;
  if (stage_v_19_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((pub_r001560_16_1 * 2) + 13) & 63;
  int stage_v_20_2 = ((pub_r001560_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((sec_r001560_13_1 ^ 0x2A) * 2) + pub_r001560_2_1) & 127;
  int stage_v_21_2 = (((sec_r001560_13_2 ^ 0x2A) * 2) + pub_r001560_2_2) & 127;
  if (stage_v_21_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((pub_r001560_16_1 * 2) + 7) & 63;
  int stage_v_22_2 = ((pub_r001560_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((sec_r001560_18_1 ^ 0x2A) * 2) + pub_r001560_9_1) & 127;
  int stage_v_23_2 = (((sec_r001560_18_2 ^ 0x2A) * 2) + pub_r001560_9_2) & 127;
  if (stage_v_23_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001560_13_1) & 127;
  int stage_v_24_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001560_13_2) & 127;
  if (stage_v_24_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001560_9_1) & 127;
  int stage_v_25_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001560_9_2) & 127;
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
  int stage_v_26_1 = ((pub_r001560_10_1 * 2) + 11) & 63;
  int stage_v_26_2 = ((pub_r001560_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = (((sec_r001560_20_1 ^ 0x2A) * 2) + pub_r001560_0_1) & 127;
  int stage_v_27_2 = (((sec_r001560_20_2 ^ 0x2A) * 2) + pub_r001560_0_2) & 127;
  if (stage_v_27_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001560_5_1) & 127;
  int stage_v_28_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001560_5_2) & 127;
  if (stage_v_28_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((sec_r001560_9_1 ^ 0x2A) * 2) + pub_r001560_10_1) & 127;
  int stage_v_29_2 = (((sec_r001560_9_2 ^ 0x2A) * 2) + pub_r001560_10_2) & 127;
  if (stage_v_29_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001560_13_1) & 127;
  int stage_v_30_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001560_13_2) & 127;
  if (stage_v_30_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001560_5_1) & 127;
  int stage_v_31_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001560_5_2) & 127;
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
  int stage_v_32_1 = (((sec_r001560_14_1 ^ 0x2A) * 2) + pub_r001560_2_1) & 127;
  int stage_v_32_2 = (((sec_r001560_14_2 ^ 0x2A) * 2) + pub_r001560_2_2) & 127;
  if (stage_v_32_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((pub_r001560_7_1 * 2) + 25) & 63;
  int stage_v_33_2 = ((pub_r001560_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001560_11_1) & 127;
  int stage_v_34_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001560_11_2) & 127;
  if (stage_v_34_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001560_0_1) & 127;
  int stage_v_35_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001560_0_2) & 127;
  if (stage_v_35_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001560_6_1) & 127;
  int stage_v_36_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001560_6_2) & 127;
  if (stage_v_36_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001560_11_1) & 127;
  int stage_v_37_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001560_11_2) & 127;
  if (stage_v_37_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((pub_r001560_6_1 * 2) + 21) & 63;
  int stage_v_38_2 = ((pub_r001560_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = (((sec_r001560_4_1 ^ 0x2A) * 2) + pub_r001560_8_1) & 127;
  int stage_v_39_2 = (((sec_r001560_4_2 ^ 0x2A) * 2) + pub_r001560_8_2) & 127;
  if (stage_v_39_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (((sec_r001560_10_1 ^ 0x2A) * 2) + pub_r001560_7_1) & 127;
  int stage_v_40_2 = (((sec_r001560_10_2 ^ 0x2A) * 2) + pub_r001560_7_2) & 127;
  if (stage_v_40_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001560_14_1) & 127;
  int stage_v_41_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001560_14_2) & 127;
  if (stage_v_41_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001560_5_1) & 127;
  int stage_v_42_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001560_5_2) & 127;
  if (stage_v_42_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001560_17_1) & 127;
  int stage_v_43_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001560_17_2) & 127;
  if (stage_v_43_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001560_17_1) & 127;
  int stage_v_44_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001560_17_2) & 127;
  if (stage_v_44_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001560_15_1) & 127;
  int stage_v_45_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001560_15_2) & 127;
  if (stage_v_45_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001560_13_1) & 127;
  int stage_v_46_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001560_13_2) & 127;
  if (stage_v_46_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001560_3_1) & 127;
  int stage_v_47_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001560_3_2) & 127;
  if (stage_v_47_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((pub_r001560_6_1 * 2) + 30) & 63;
  int stage_v_48_2 = ((pub_r001560_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001560_0_1) & 127;
  int stage_v_49_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001560_0_2) & 127;
  if (stage_v_49_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((pub_r001560_8_1 * 2) + 15) & 63;
  int stage_v_50_2 = ((pub_r001560_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((sec_r001560_4_1 ^ 0x2A) * 2) + pub_r001560_6_1) & 127;
  int stage_v_51_2 = (((sec_r001560_4_2 ^ 0x2A) * 2) + pub_r001560_6_2) & 127;
  if (stage_v_51_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((pub_r001560_2_1 * 2) + 16) & 63;
  int stage_v_52_2 = ((pub_r001560_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001560_2_1 * 2) + 36) & 63;
  int stage_v_53_2 = ((pub_r001560_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001560_9_1 * 2) + 13) & 63;
  int stage_v_54_2 = ((pub_r001560_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001560_7_1) & 127;
  int stage_v_55_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001560_7_2) & 127;
  if (stage_v_55_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001560_8_1) & 127;
  int stage_v_56_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001560_8_2) & 127;
  if (stage_v_56_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((sec_r001560_12_1 ^ 0x2A) * 2) + pub_r001560_15_1) & 127;
  int stage_v_57_2 = (((sec_r001560_12_2 ^ 0x2A) * 2) + pub_r001560_15_2) & 127;
  if (stage_v_57_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((pub_r001560_10_1 * 2) + 38) & 63;
  int stage_v_58_2 = ((pub_r001560_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001560_2_1 * 2) + 8) & 63;
  int stage_v_59_2 = ((pub_r001560_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((stage_v_42_1 ^ 0x2A) * 2) + pub_r001560_17_1) & 127;
  int stage_v_60_2 = (((stage_v_42_2 ^ 0x2A) * 2) + pub_r001560_17_2) & 127;
  if (stage_v_60_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001560_12_1) & 127;
  int stage_v_61_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001560_12_2) & 127;
  if (stage_v_61_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((pub_r001560_5_1 * 2) + 36) & 63;
  int stage_v_62_2 = ((pub_r001560_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((sec_r001560_20_1 ^ 0x2A) * 2) + pub_r001560_12_1) & 127;
  int stage_v_63_2 = (((sec_r001560_20_2 ^ 0x2A) * 2) + pub_r001560_12_2) & 127;
  if (stage_v_63_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((sec_r001560_20_1 ^ 0x2A) * 2) + pub_r001560_1_1) & 127;
  int stage_v_64_2 = (((sec_r001560_20_2 ^ 0x2A) * 2) + pub_r001560_1_2) & 127;
  if (stage_v_64_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001560_2_1) & 127;
  int stage_v_65_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001560_2_2) & 127;
  if (stage_v_65_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((pub_r001560_5_1 * 2) + 32) & 63;
  int stage_v_66_2 = ((pub_r001560_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001560_9_1) & 127;
  int stage_v_67_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001560_9_2) & 127;
  if (stage_v_67_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((pub_r001560_2_1 * 2) + 8) & 63;
  int stage_v_68_2 = ((pub_r001560_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001560_8_1 * 2) + 39) & 63;
  int stage_v_69_2 = ((pub_r001560_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001560_2_1) & 127;
  int stage_v_70_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001560_2_2) & 127;
  if (stage_v_70_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001560_13_1) & 127;
  int stage_v_71_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001560_13_2) & 127;
  if (stage_v_71_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((pub_r001560_3_1 * 2) + 6) & 63;
  int stage_v_72_2 = ((pub_r001560_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001560_6_1) & 127;
  int stage_v_73_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001560_6_2) & 127;
  if (stage_v_73_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001560_5_1) & 127;
  int stage_v_74_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001560_5_2) & 127;
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
  int stage_v_75_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001560_16_1) & 127;
  int stage_v_75_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001560_16_2) & 127;
  if (stage_v_75_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((pub_r001560_2_1 * 2) + 36) & 63;
  int stage_v_76_2 = ((pub_r001560_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001560_3_1) & 127;
  int stage_v_77_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001560_3_2) & 127;
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
  int stage_v_78_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001560_12_1) & 127;
  int stage_v_78_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001560_12_2) & 127;
  if (stage_v_78_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((pub_r001560_10_1 * 2) + 11) & 63;
  int stage_v_79_2 = ((pub_r001560_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001560_4_1) & 127;
  int stage_v_80_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001560_4_2) & 127;
  if (stage_v_80_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((pub_r001560_10_1 * 2) + 7) & 63;
  int stage_v_81_2 = ((pub_r001560_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((sec_r001560_13_1 ^ 0x2A) * 2) + pub_r001560_1_1) & 127;
  int stage_v_82_2 = (((sec_r001560_13_2 ^ 0x2A) * 2) + pub_r001560_1_2) & 127;
  if (stage_v_82_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((pub_r001560_14_1 * 2) + 50) & 63;
  int stage_v_83_2 = ((pub_r001560_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001560_13_1) & 127;
  int stage_v_84_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001560_13_2) & 127;
  if (stage_v_84_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((pub_r001560_17_1 * 2) + 27) & 63;
  int stage_v_85_2 = ((pub_r001560_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001560_4_1 * 2) + 24) & 63;
  int stage_v_86_2 = ((pub_r001560_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001560_8_1) & 127;
  int stage_v_87_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001560_8_2) & 127;
  if (stage_v_87_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((sec_r001560_19_1 ^ 0x2A) * 2) + pub_r001560_10_1) & 127;
  int stage_v_88_2 = (((sec_r001560_19_2 ^ 0x2A) * 2) + pub_r001560_10_2) & 127;
  if (stage_v_88_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((pub_r001560_4_1 * 2) + 24) & 63;
  int stage_v_89_2 = ((pub_r001560_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001560_8_1) & 127;
  int stage_v_90_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001560_8_2) & 127;
  if (stage_v_90_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((pub_r001560_17_1 * 2) + 10) & 63;
  int stage_v_91_2 = ((pub_r001560_17_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001560_17_1) & 127;
  int stage_v_92_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001560_17_2) & 127;
  if (stage_v_92_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001560_1_1) & 127;
  int stage_v_93_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001560_1_2) & 127;
  if (stage_v_93_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((pub_r001560_3_1 * 2) + 30) & 63;
  int stage_v_94_2 = ((pub_r001560_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001560_8_1 * 2) + 29) & 63;
  int stage_v_95_2 = ((pub_r001560_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((sec_r001560_1_1 ^ 0x2A) * 2) + pub_r001560_6_1) & 127;
  int stage_v_96_2 = (((sec_r001560_1_2 ^ 0x2A) * 2) + pub_r001560_6_2) & 127;
  if (stage_v_96_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001560_12_1) & 127;
  int stage_v_97_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001560_12_2) & 127;
  if (stage_v_97_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((sec_r001560_10_1 ^ 0x2A) * 2) + pub_r001560_11_1) & 127;
  int stage_v_98_2 = (((sec_r001560_10_2 ^ 0x2A) * 2) + pub_r001560_11_2) & 127;
  if (stage_v_98_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001560_12_1) & 127;
  int stage_v_99_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001560_12_2) & 127;
  if (stage_v_99_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001560_15_1) & 127;
  int stage_v_100_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001560_15_2) & 127;
  if (stage_v_100_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((pub_r001560_3_1 * 2) + 15) & 63;
  int stage_v_101_2 = ((pub_r001560_3_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001560_4_1) & 127;
  int stage_v_102_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001560_4_2) & 127;
  if (stage_v_102_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001560_11_1) & 127;
  int stage_v_103_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001560_11_2) & 127;
  if (stage_v_103_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001560_4_1) & 127;
  int stage_v_104_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001560_4_2) & 127;
  if (stage_v_104_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001560_16_1) & 127;
  int stage_v_105_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001560_16_2) & 127;
  if (stage_v_105_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((sec_r001560_15_1 ^ 0x2A) * 2) + pub_r001560_11_1) & 127;
  int stage_v_106_2 = (((sec_r001560_15_2 ^ 0x2A) * 2) + pub_r001560_11_2) & 127;
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
  int stage_v_107_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001560_17_1) & 127;
  int stage_v_107_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001560_17_2) & 127;
  if (stage_v_107_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001560_1_1) & 127;
  int stage_v_108_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001560_1_2) & 127;
  if (stage_v_108_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((pub_r001560_3_1 * 2) + 35) & 63;
  int stage_v_109_2 = ((pub_r001560_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001560_0_1) & 127;
  int stage_v_110_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001560_0_2) & 127;
  if (stage_v_110_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001560_12_1) & 127;
  int stage_v_111_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001560_12_2) & 127;
  if (stage_v_111_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((stage_v_97_1 ^ 0x2A) * 2) + pub_r001560_0_1) & 127;
  int stage_v_112_2 = (((stage_v_97_2 ^ 0x2A) * 2) + pub_r001560_0_2) & 127;
  if (stage_v_112_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001560_8_1) & 127;
  int stage_v_113_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001560_8_2) & 127;
  if (stage_v_113_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001560_11_1) & 127;
  int stage_v_114_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001560_11_2) & 127;
  if (stage_v_114_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001560_7_1) & 127;
  int stage_v_115_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001560_7_2) & 127;
  if (stage_v_115_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001560_10_1) & 127;
  int stage_v_116_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001560_10_2) & 127;
  if (stage_v_116_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((pub_r001560_11_1 * 2) + 48) & 63;
  int stage_v_117_2 = ((pub_r001560_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001560_14_1) & 127;
  int stage_v_118_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001560_14_2) & 127;
  if (stage_v_118_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((pub_r001560_3_1 * 2) + 7) & 63;
  int stage_v_119_2 = ((pub_r001560_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((sec_r001560_3_1 ^ 0x2A) * 2) + pub_r001560_16_1) & 127;
  int stage_v_120_2 = (((sec_r001560_3_2 ^ 0x2A) * 2) + pub_r001560_16_2) & 127;
  if (stage_v_120_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001560_6_1) & 127;
  int stage_v_121_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001560_6_2) & 127;
  if (stage_v_121_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((pub_r001560_12_1 * 2) + 20) & 63;
  int stage_v_122_2 = ((pub_r001560_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001560_4_1) & 127;
  int stage_v_123_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001560_4_2) & 127;
  if (stage_v_123_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((pub_r001560_7_1 * 2) + 33) & 63;
  int stage_v_124_2 = ((pub_r001560_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001560_3_1) & 127;
  int stage_v_125_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001560_3_2) & 127;
  if (stage_v_125_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001560_10_1) & 127;
  int stage_v_126_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001560_10_2) & 127;
  if (stage_v_126_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((sec_r001560_3_1 ^ 0x2A) * 2) + pub_r001560_5_1) & 127;
  int stage_v_127_2 = (((sec_r001560_3_2 ^ 0x2A) * 2) + pub_r001560_5_2) & 127;
  if (stage_v_127_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((sec_r001560_15_1 ^ 0x2A) * 2) + pub_r001560_7_1) & 127;
  int stage_v_128_2 = (((sec_r001560_15_2 ^ 0x2A) * 2) + pub_r001560_7_2) & 127;
  if (stage_v_128_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001560_13_1) & 127;
  int stage_v_129_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001560_13_2) & 127;
  if (stage_v_129_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001560_2_1) & 127;
  int stage_v_130_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001560_2_2) & 127;
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
  int stage_v_131_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001560_1_1) & 127;
  int stage_v_131_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001560_1_2) & 127;
  if (stage_v_131_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((pub_r001560_9_1 * 2) + 50) & 63;
  int stage_v_132_2 = ((pub_r001560_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001560_7_1) & 127;
  int stage_v_133_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001560_7_2) & 127;
  if (stage_v_133_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001560_12_1) & 127;
  int stage_v_134_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001560_12_2) & 127;
  if (stage_v_134_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001560_11_1) & 127;
  int stage_v_135_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001560_11_2) & 127;
  if (stage_v_135_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((pub_r001560_2_1 * 2) + 28) & 63;
  int stage_v_136_2 = ((pub_r001560_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001560_2_1) & 127;
  int stage_v_137_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001560_2_2) & 127;
  if (stage_v_137_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (((stage_v_135_1 ^ 0x2A) * 2) + pub_r001560_1_1) & 127;
  int stage_v_138_2 = (((stage_v_135_2 ^ 0x2A) * 2) + pub_r001560_1_2) & 127;
  if (stage_v_138_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((pub_r001560_11_1 * 2) + 48) & 63;
  int stage_v_139_2 = ((pub_r001560_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001560_1_1) & 127;
  int stage_v_140_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001560_1_2) & 127;
  if (stage_v_140_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001560_9_1) & 127;
  int stage_v_141_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001560_9_2) & 127;
  if (stage_v_141_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001560_6_1) & 127;
  int stage_v_142_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001560_6_2) & 127;
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
  int stage_v_143_1 = (((stage_v_104_1 ^ 0x2A) * 2) + pub_r001560_14_1) & 127;
  int stage_v_143_2 = (((stage_v_104_2 ^ 0x2A) * 2) + pub_r001560_14_2) & 127;
  if (stage_v_143_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001560_9_1) & 127;
  int stage_v_144_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001560_9_2) & 127;
  if (stage_v_144_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001560_8_1) & 127;
  int stage_v_145_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001560_8_2) & 127;
  if (stage_v_145_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((pub_r001560_6_1 * 2) + 45) & 63;
  int stage_v_146_2 = ((pub_r001560_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001560_17_1 * 2) + 50) & 63;
  int stage_v_147_2 = ((pub_r001560_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001560_7_1 * 2) + 42) & 63;
  int stage_v_148_2 = ((pub_r001560_7_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001560_10_1) & 127;
  int stage_v_149_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001560_10_2) & 127;
  if (stage_v_149_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001560_8_1) & 127;
  int stage_v_150_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001560_8_2) & 127;
  if (stage_v_150_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001560_10_1) & 127;
  int stage_v_151_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001560_10_2) & 127;
  if (stage_v_151_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((pub_r001560_11_1 * 2) + 39) & 63;
  int stage_v_152_2 = ((pub_r001560_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001560_10_1) & 127;
  int stage_v_153_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001560_10_2) & 127;
  if (stage_v_153_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((pub_r001560_5_1 * 2) + 34) & 63;
  int stage_v_154_2 = ((pub_r001560_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001560_11_1) & 127;
  int stage_v_155_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001560_11_2) & 127;
  if (stage_v_155_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((pub_r001560_8_1 * 2) + 6) & 63;
  int stage_v_156_2 = ((pub_r001560_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001560_7_1) & 127;
  int stage_v_157_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001560_7_2) & 127;
  if (stage_v_157_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((stage_v_97_1 ^ 0x2A) * 2) + pub_r001560_14_1) & 127;
  int stage_v_158_2 = (((stage_v_97_2 ^ 0x2A) * 2) + pub_r001560_14_2) & 127;
  if (stage_v_158_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((sec_r001560_13_1 ^ 0x2A) * 2) + pub_r001560_3_1) & 127;
  int stage_v_159_2 = (((sec_r001560_13_2 ^ 0x2A) * 2) + pub_r001560_3_2) & 127;
  if (stage_v_159_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001560_13_1) & 127;
  int stage_v_160_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001560_13_2) & 127;
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
  int stage_v_161_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001560_17_1) & 127;
  int stage_v_161_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001560_17_2) & 127;
  if (stage_v_161_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001560_16_1) & 127;
  int stage_v_162_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001560_16_2) & 127;
  if (stage_v_162_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001560_6_1) & 127;
  int stage_v_163_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001560_6_2) & 127;
  if (stage_v_163_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (((stage_v_133_1 ^ 0x2A) * 2) + pub_r001560_17_1) & 127;
  int stage_v_164_2 = (((stage_v_133_2 ^ 0x2A) * 2) + pub_r001560_17_2) & 127;
  if (stage_v_164_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001560_2_1) & 127;
  int stage_v_165_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001560_2_2) & 127;
  if (stage_v_165_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((pub_r001560_7_1 * 2) + 45) & 63;
  int stage_v_166_2 = ((pub_r001560_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_138_1 ^ 0x2A) * 2) + pub_r001560_13_1) & 127;
  int stage_v_167_2 = (((stage_v_138_2 ^ 0x2A) * 2) + pub_r001560_13_2) & 127;
  if (stage_v_167_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((pub_r001560_9_1 * 2) + 19) & 63;
  int stage_v_168_2 = ((pub_r001560_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((stage_v_96_1 ^ 0x2A) * 2) + pub_r001560_13_1) & 127;
  int stage_v_169_2 = (((stage_v_96_2 ^ 0x2A) * 2) + pub_r001560_13_2) & 127;
  if (stage_v_169_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((sec_r001560_15_1 ^ 0x2A) * 2) + pub_r001560_11_1) & 127;
  int stage_v_170_2 = (((sec_r001560_15_2 ^ 0x2A) * 2) + pub_r001560_11_2) & 127;
  if (stage_v_170_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((pub_r001560_7_1 * 2) + 13) & 63;
  int stage_v_171_2 = ((pub_r001560_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001560_0_1) & 127;
  int stage_v_172_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001560_0_2) & 127;
  if (stage_v_172_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001560_9_1) & 127;
  int stage_v_173_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001560_9_2) & 127;
  if (stage_v_173_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001560_3_1) & 127;
  int stage_v_174_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001560_3_2) & 127;
  if (stage_v_174_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((pub_r001560_9_1 * 2) + 34) & 63;
  int stage_v_175_2 = ((pub_r001560_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001560_11_1 * 2) + 40) & 63;
  int stage_v_176_2 = ((pub_r001560_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001560_6_1 * 2) + 15) & 63;
  int stage_v_177_2 = ((pub_r001560_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001560_13_1) & 127;
  int stage_v_178_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001560_13_2) & 127;
  if (stage_v_178_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((pub_r001560_5_1 * 2) + 26) & 63;
  int stage_v_179_2 = ((pub_r001560_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_118_1 ^ 0x2A) * 2) + pub_r001560_0_1) & 127;
  int stage_v_180_2 = (((stage_v_118_2 ^ 0x2A) * 2) + pub_r001560_0_2) & 127;
  if (stage_v_180_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001560_7_1) & 127;
  int stage_v_181_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001560_7_2) & 127;
  if (stage_v_181_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = (((stage_v_161_1 ^ 0x2A) * 2) + pub_r001560_0_1) & 127;
  int stage_v_182_2 = (((stage_v_161_2 ^ 0x2A) * 2) + pub_r001560_0_2) & 127;
  if (stage_v_182_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (((stage_v_150_1 ^ 0x2A) * 2) + pub_r001560_12_1) & 127;
  int stage_v_183_2 = (((stage_v_150_2 ^ 0x2A) * 2) + pub_r001560_12_2) & 127;
  if (stage_v_183_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001560_9_1) & 127;
  int stage_v_184_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001560_9_2) & 127;
  if (stage_v_184_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((pub_r001560_6_1 * 2) + 16) & 63;
  int stage_v_185_2 = ((pub_r001560_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001560_17_1) & 127;
  int stage_v_186_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001560_17_2) & 127;
  if (stage_v_186_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001560_1_1) & 127;
  int stage_v_187_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001560_1_2) & 127;
  if (stage_v_187_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (((stage_v_130_1 ^ 0x2A) * 2) + pub_r001560_14_1) & 127;
  int stage_v_188_2 = (((stage_v_130_2 ^ 0x2A) * 2) + pub_r001560_14_2) & 127;
  if (stage_v_188_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((sec_r001560_21_1 ^ 0x2A) * 2) + pub_r001560_9_1) & 127;
  int stage_v_189_2 = (((sec_r001560_21_2 ^ 0x2A) * 2) + pub_r001560_9_2) & 127;
  if (stage_v_189_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((sec_r001560_11_1 ^ 0x2A) * 2) + pub_r001560_10_1) & 127;
  int stage_v_190_2 = (((sec_r001560_11_2 ^ 0x2A) * 2) + pub_r001560_10_2) & 127;
  if (stage_v_190_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((stage_v_159_1 ^ 0x2A) * 2) + pub_r001560_12_1) & 127;
  int stage_v_191_2 = (((stage_v_159_2 ^ 0x2A) * 2) + pub_r001560_12_2) & 127;
  if (stage_v_191_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001560_1_1) & 127;
  int stage_v_192_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001560_1_2) & 127;
  if (stage_v_192_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_151_1 ^ 0x2A) * 2) + pub_r001560_16_1) & 127;
  int stage_v_193_2 = (((stage_v_151_2 ^ 0x2A) * 2) + pub_r001560_16_2) & 127;
  if (stage_v_193_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001560_16_1) & 127;
  int stage_v_194_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001560_16_2) & 127;
  if (stage_v_194_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((pub_r001560_3_1 * 2) + 39) & 63;
  int stage_v_195_2 = ((pub_r001560_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((stage_v_178_1 ^ 0x2A) * 2) + pub_r001560_13_1) & 127;
  int stage_v_196_2 = (((stage_v_178_2 ^ 0x2A) * 2) + pub_r001560_13_2) & 127;
  if (stage_v_196_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((stage_v_135_1 ^ 0x2A) * 2) + pub_r001560_12_1) & 127;
  int stage_v_197_2 = (((stage_v_135_2 ^ 0x2A) * 2) + pub_r001560_12_2) & 127;
  if (stage_v_197_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001560_10_1) & 127;
  int stage_v_198_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001560_10_2) & 127;
  if (stage_v_198_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001560_13_1) & 127;
  int stage_v_199_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001560_13_2) & 127;
  if (stage_v_199_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001560_3_1) & 127;
  int stage_v_200_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001560_3_2) & 127;
  if (stage_v_200_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001560_17_1) & 127;
  int stage_v_201_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001560_17_2) & 127;
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
  int stage_v_202_1 = ((pub_r001560_10_1 * 2) + 24) & 63;
  int stage_v_202_2 = ((pub_r001560_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((sec_r001560_11_1 ^ 0x2A) * 2) + pub_r001560_16_1) & 127;
  int stage_v_203_2 = (((sec_r001560_11_2 ^ 0x2A) * 2) + pub_r001560_16_2) & 127;
  if (stage_v_203_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001560_7_1) & 127;
  int stage_v_204_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001560_7_2) & 127;
  if (stage_v_204_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001560_11_1) & 127;
  int stage_v_205_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001560_11_2) & 127;
  if (stage_v_205_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001560_5_1) & 127;
  int stage_v_206_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001560_5_2) & 127;
  if (stage_v_206_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001560_14_1) & 127;
  int stage_v_207_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001560_14_2) & 127;
  if (stage_v_207_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((pub_r001560_2_1 * 2) + 18) & 63;
  int stage_v_208_2 = ((pub_r001560_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001560_16_1) & 127;
  int stage_v_209_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001560_16_2) & 127;
  if (stage_v_209_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = (((stage_v_155_1 ^ 0x2A) * 2) + pub_r001560_8_1) & 127;
  int stage_v_210_2 = (((stage_v_155_2 ^ 0x2A) * 2) + pub_r001560_8_2) & 127;
  if (stage_v_210_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((pub_r001560_6_1 * 2) + 46) & 63;
  int stage_v_211_2 = ((pub_r001560_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = (((stage_v_181_1 ^ 0x2A) * 2) + pub_r001560_16_1) & 127;
  int stage_v_212_2 = (((stage_v_181_2 ^ 0x2A) * 2) + pub_r001560_16_2) & 127;
  if (stage_v_212_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = (((stage_v_125_1 ^ 0x2A) * 2) + pub_r001560_14_1) & 127;
  int stage_v_213_2 = (((stage_v_125_2 ^ 0x2A) * 2) + pub_r001560_14_2) & 127;
  if (stage_v_213_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001560_4_1) & 127;
  int stage_v_214_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001560_4_2) & 127;
  if (stage_v_214_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = (((stage_v_194_1 ^ 0x2A) * 2) + pub_r001560_10_1) & 127;
  int stage_v_215_2 = (((stage_v_194_2 ^ 0x2A) * 2) + pub_r001560_10_2) & 127;
  if (stage_v_215_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((pub_r001560_13_1 * 2) + 38) & 63;
  int stage_v_216_2 = ((pub_r001560_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001560_6_1 * 2) + 5) & 63;
  int stage_v_217_2 = ((pub_r001560_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001560_5_1 * 2) + 44) & 63;
  int stage_v_218_2 = ((pub_r001560_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001560_14_1) & 127;
  int stage_v_219_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001560_14_2) & 127;
  if (stage_v_219_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = (((stage_v_133_1 ^ 0x2A) * 2) + pub_r001560_12_1) & 127;
  int stage_v_220_2 = (((stage_v_133_2 ^ 0x2A) * 2) + pub_r001560_12_2) & 127;
  if (stage_v_220_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
  }
  if (stage_v_220_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001560_16_1) & 127;
  int stage_v_221_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001560_16_2) & 127;
  if (stage_v_221_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001560_16_1) & 127;
  int stage_v_222_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001560_16_2) & 127;
  if (stage_v_222_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = (((sec_r001560_17_1 ^ 0x2A) * 2) + pub_r001560_11_1) & 127;
  int stage_v_223_2 = (((sec_r001560_17_2 ^ 0x2A) * 2) + pub_r001560_11_2) & 127;
  if (stage_v_223_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = (((stage_v_141_1 ^ 0x2A) * 2) + pub_r001560_5_1) & 127;
  int stage_v_224_2 = (((stage_v_141_2 ^ 0x2A) * 2) + pub_r001560_5_2) & 127;
  if (stage_v_224_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
  }
  if (stage_v_224_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001560_4_1) & 127;
  int stage_v_225_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001560_4_2) & 127;
  if (stage_v_225_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
  }
  if (stage_v_225_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = (((stage_v_173_1 ^ 0x2A) * 2) + pub_r001560_8_1) & 127;
  int stage_v_226_2 = (((stage_v_173_2 ^ 0x2A) * 2) + pub_r001560_8_2) & 127;
  if (stage_v_226_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
  }
  if (stage_v_226_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = (((stage_v_170_1 ^ 0x2A) * 2) + pub_r001560_9_1) & 127;
  int stage_v_227_2 = (((stage_v_170_2 ^ 0x2A) * 2) + pub_r001560_9_2) & 127;
  if (stage_v_227_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
  }
  if (stage_v_227_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((pub_r001560_10_1 * 2) + 16) & 63;
  int stage_v_228_2 = ((pub_r001560_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001560_11_1) & 127;
  int stage_v_229_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001560_11_2) & 127;
  if (stage_v_229_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
  }
  if (stage_v_229_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = (((stage_v_181_1 ^ 0x2A) * 2) + pub_r001560_6_1) & 127;
  int stage_v_230_2 = (((stage_v_181_2 ^ 0x2A) * 2) + pub_r001560_6_2) & 127;
  if (stage_v_230_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
  }
  if (stage_v_230_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((pub_r001560_17_1 * 2) + 16) & 63;
  int stage_v_231_2 = ((pub_r001560_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001560_6_1 * 2) + 42) & 63;
  int stage_v_232_2 = ((pub_r001560_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = (((stage_v_167_1 ^ 0x2A) * 2) + pub_r001560_0_1) & 127;
  int stage_v_233_2 = (((stage_v_167_2 ^ 0x2A) * 2) + pub_r001560_0_2) & 127;
  if (stage_v_233_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
  }
  if (stage_v_233_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = (((stage_v_189_1 ^ 0x2A) * 2) + pub_r001560_0_1) & 127;
  int stage_v_234_2 = (((stage_v_189_2 ^ 0x2A) * 2) + pub_r001560_0_2) & 127;
  if (stage_v_234_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
  }
  if (stage_v_234_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = (((stage_v_194_1 ^ 0x2A) * 2) + pub_r001560_5_1) & 127;
  int stage_v_235_2 = (((stage_v_194_2 ^ 0x2A) * 2) + pub_r001560_5_2) & 127;
  if (stage_v_235_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
  }
  if (stage_v_235_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001560_4_1) & 127;
  int stage_v_236_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001560_4_2) & 127;
  if (stage_v_236_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
  }
  if (stage_v_236_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001560_0_1) & 127;
  int stage_v_237_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001560_0_2) & 127;
  if (stage_v_237_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
  }
  if (stage_v_237_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001560_16_1) & 127;
  int stage_v_238_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001560_16_2) & 127;
  if (stage_v_238_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_238_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_238_1) + 13) & 255;
  }
  if (stage_v_238_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_238_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_238_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001560_5_1) & 127;
  int stage_v_239_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001560_5_2) & 127;
  if (stage_v_239_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
  }
  if (stage_v_239_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((pub_r001560_17_1 * 2) + 17) & 63;
  int stage_v_240_2 = ((pub_r001560_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((pub_r001560_15_1 * 2) + 43) & 63;
  int stage_v_241_2 = ((pub_r001560_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((pub_r001560_1_1 * 2) + 5) & 63;
  int stage_v_242_2 = ((pub_r001560_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = (((stage_v_174_1 ^ 0x2A) * 2) + pub_r001560_3_1) & 127;
  int stage_v_243_2 = (((stage_v_174_2 ^ 0x2A) * 2) + pub_r001560_3_2) & 127;
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
  int stage_v_244_1 = (((sec_r001560_10_1 ^ 0x2A) * 2) + pub_r001560_7_1) & 127;
  int stage_v_244_2 = (((sec_r001560_10_2 ^ 0x2A) * 2) + pub_r001560_7_2) & 127;
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
  int stage_v_245_1 = ((pub_r001560_10_1 * 2) + 31) & 63;
  int stage_v_245_2 = ((pub_r001560_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001560_9_1 * 2) + 41) & 63;
  int stage_v_246_2 = ((pub_r001560_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = (((stage_v_104_1 ^ 0x2A) * 2) + pub_r001560_1_1) & 127;
  int stage_v_247_2 = (((stage_v_104_2 ^ 0x2A) * 2) + pub_r001560_1_2) & 127;
  if (stage_v_247_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_247_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_247_1) + 13) & 255;
  }
  if (stage_v_247_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_247_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_247_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001560_17_1) & 127;
  int stage_v_248_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001560_17_2) & 127;
  if (stage_v_248_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_248_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_248_1) + 13) & 255;
  }
  if (stage_v_248_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_248_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_248_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001560_13_1) & 127;
  int stage_v_249_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001560_13_2) & 127;
  if (stage_v_249_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_249_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_249_1) + 13) & 255;
  }
  if (stage_v_249_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_249_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_249_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = (((stage_v_234_1 ^ 0x2A) * 2) + pub_r001560_7_1) & 127;
  int stage_v_250_2 = (((stage_v_234_2 ^ 0x2A) * 2) + pub_r001560_7_2) & 127;
  if (stage_v_250_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_250_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_250_1) + 13) & 255;
  }
  if (stage_v_250_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_250_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_250_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = (((stage_v_112_1 ^ 0x2A) * 2) + pub_r001560_4_1) & 127;
  int stage_v_251_2 = (((stage_v_112_2 ^ 0x2A) * 2) + pub_r001560_4_2) & 127;
  if (stage_v_251_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_251_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_251_1) + 13) & 255;
  }
  if (stage_v_251_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_251_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_251_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((pub_r001560_4_1 * 2) + 34) & 63;
  int stage_v_252_2 = ((pub_r001560_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001560_0_1) & 127;
  int stage_v_253_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001560_0_2) & 127;
  if (stage_v_253_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_253_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_253_1) + 13) & 255;
  }
  if (stage_v_253_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_253_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_253_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = (((stage_v_173_1 ^ 0x2A) * 2) + pub_r001560_8_1) & 127;
  int stage_v_254_2 = (((stage_v_173_2 ^ 0x2A) * 2) + pub_r001560_8_2) & 127;
  if (stage_v_254_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_254_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_254_1) + 13) & 255;
  }
  if (stage_v_254_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_254_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_254_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001560_9_1) & 127;
  int stage_v_255_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001560_9_2) & 127;
  if (stage_v_255_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_255_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_255_1) + 13) & 255;
  }
  if (stage_v_255_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_255_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_255_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((pub_r001560_0_1 * 2) + 36) & 63;
  int stage_v_256_2 = ((pub_r001560_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001560_14_1 * 2) + 41) & 63;
  int stage_v_257_2 = ((pub_r001560_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_158_1 ^ 0x2A) * 2) + pub_r001560_16_1) & 127;
  int stage_v_258_2 = (((stage_v_158_2 ^ 0x2A) * 2) + pub_r001560_16_2) & 127;
  if (stage_v_258_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_258_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_258_1) + 13) & 255;
  }
  if (stage_v_258_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_258_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_258_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001560_1_1) & 127;
  int stage_v_259_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001560_1_2) & 127;
  if (stage_v_259_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_259_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_259_1) + 13) & 255;
  }
  if (stage_v_259_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_259_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_259_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((pub_r001560_2_1 * 2) + 6) & 63;
  int stage_v_260_2 = ((pub_r001560_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001560_4_1 * 2) + 49) & 63;
  int stage_v_261_2 = ((pub_r001560_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = (((stage_v_170_1 ^ 0x2A) * 2) + pub_r001560_11_1) & 127;
  int stage_v_262_2 = (((stage_v_170_2 ^ 0x2A) * 2) + pub_r001560_11_2) & 127;
  if (stage_v_262_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_262_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_262_1) + 13) & 255;
  }
  if (stage_v_262_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_262_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_262_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = (((stage_v_160_1 ^ 0x2A) * 2) + pub_r001560_6_1) & 127;
  int stage_v_263_2 = (((stage_v_160_2 ^ 0x2A) * 2) + pub_r001560_6_2) & 127;
  if (stage_v_263_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_263_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_263_1) + 13) & 255;
  }
  if (stage_v_263_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_263_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_263_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001560_7_1 == pub_r001560_7_2);
  __CPROVER_assume(pub_r001560_1_1 == pub_r001560_1_2);
  __CPROVER_assume(sec_r001560_4_1 != sec_r001560_4_2);
  __CPROVER_assume(sec_r001560_22_1 != sec_r001560_22_2);
  __CPROVER_assume(sec_r001560_0_1 != sec_r001560_0_2);
  __CPROVER_assume(sec_r001560_10_1 != sec_r001560_10_2);
  __CPROVER_assume(pub_r001560_15_1 == pub_r001560_15_2);
  __CPROVER_assume(pub_r001560_9_1 == pub_r001560_9_2);
  __CPROVER_assume(sec_r001560_13_1 != sec_r001560_13_2);
  __CPROVER_assume(sec_r001560_21_1 != sec_r001560_21_2);
  __CPROVER_assume(pub_r001560_6_1 == pub_r001560_6_2);
  __CPROVER_assume(pub_r001560_0_1 == pub_r001560_0_2);
  __CPROVER_assume(sec_r001560_23_1 != sec_r001560_23_2);
  __CPROVER_assume(pub_r001560_12_1 == pub_r001560_12_2);
  __CPROVER_assume(pub_r001560_17_1 == pub_r001560_17_2);
  __CPROVER_assume(sec_r001560_19_1 != sec_r001560_19_2);
  __CPROVER_assume(pub_r001560_4_1 == pub_r001560_4_2);
  __CPROVER_assume(pub_r001560_2_1 == pub_r001560_2_2);
  __CPROVER_assume(sec_r001560_1_1 != sec_r001560_1_2);
  __CPROVER_assume(pub_r001560_16_1 == pub_r001560_16_2);
  __CPROVER_assume(sec_r001560_2_1 != sec_r001560_2_2);
  __CPROVER_assume(sec_r001560_6_1 != sec_r001560_6_2);
  __CPROVER_assume(pub_r001560_8_1 == pub_r001560_8_2);
  __CPROVER_assume(sec_r001560_5_1 != sec_r001560_5_2);
  __CPROVER_assume(sec_r001560_20_1 != sec_r001560_20_2);
  __CPROVER_assume(pub_r001560_13_1 == pub_r001560_13_2);
  __CPROVER_assume(sec_r001560_16_1 != sec_r001560_16_2);
  __CPROVER_assume(sec_r001560_14_1 != sec_r001560_14_2);
  __CPROVER_assume(pub_r001560_5_1 == pub_r001560_5_2);
  __CPROVER_assume(sec_r001560_18_1 != sec_r001560_18_2);
  __CPROVER_assume(sec_r001560_11_1 != sec_r001560_11_2);
  __CPROVER_assume(sec_r001560_15_1 != sec_r001560_15_2);
  __CPROVER_assume(sec_r001560_3_1 != sec_r001560_3_2);
  __CPROVER_assume(pub_r001560_11_1 == pub_r001560_11_2);
  __CPROVER_assume(sec_r001560_7_1 != sec_r001560_7_2);
  __CPROVER_assume(sec_r001560_17_1 != sec_r001560_17_2);
  __CPROVER_assume(sec_r001560_12_1 != sec_r001560_12_2);
  __CPROVER_assume(sec_r001560_9_1 != sec_r001560_9_2);
  __CPROVER_assume(pub_r001560_10_1 == pub_r001560_10_2);
  __CPROVER_assume(pub_r001560_14_1 == pub_r001560_14_2);
  __CPROVER_assume(pub_r001560_3_1 == pub_r001560_3_2);
  __CPROVER_assume(sec_r001560_8_1 != sec_r001560_8_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.scale == st_var_1_2.scale);
  assert(st_var_1_1.trace == st_var_1_2.trace);
  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  assert(st_var_1_1.density == st_var_1_2.density);
  assert(st_var_1_1.dim == st_var_1_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.tag == st_var_2_2.tag);
  assert(st_var_2_1.nonce == st_var_2_2.nonce);
  assert(st_var_2_1.round_key == st_var_2_2.round_key);
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
}


