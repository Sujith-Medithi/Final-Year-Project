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
struct MatrixBlock_R001970_7013_0
{
  short trace;
  unsigned char scale;
  int determinant;
  int dim;
  int buffer[3];
};
struct StreamBuffer_R001970_7013_1
{
  unsigned char watermark;
  unsigned char head;
  int checksum;
  int state;
  int capacity;
  int buffer[3];
};
struct CipherContext_R001970_7013_2
{
  int round_key;
  unsigned char tag;
  int flags;
  int counter;
  short iv;
  int nonce;
  int buffer[3];
};
union ColorPixel_R001970_7013_0
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
void fn_R001970_7013_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st_1 = {0};
  struct CipherContext_R001970_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int checksum_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_61_1 > 26)
  {
    acc_1 = ((acc_1 + (checksum_61_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_61_2 > 26)
  {
    acc_2 = ((acc_2 + (checksum_61_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_15_1 = local_arr_1[aux_1 % 3];
  int window_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_15_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_86_1) & 63;
  aux_2 = (aux_2 + delta_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_61_1 == checksum_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_15_1 == window_15_2);
  assert(delta_86_1 == delta_86_2);
}

int fn_R001970_7013_0(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int checksum_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_61 > 26)
  {
    acc = ((acc + (checksum_61 * 2)) + 5) & 127;
    aux ^= checksum_61 & 15;
  }
  else
  {
    acc = ((acc - checksum_61) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_15 = local_arr[aux % 3];
  acc = (acc + (window_15 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001970_7013_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st_1 = {0};
  struct CipherContext_R001970_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int factor_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_22_1)
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

  switch (factor_22_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_22_1 == factor_22_2);
}

int fn_R001970_7013_1(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int factor_22 = (aux + st.buffer[1]) & 3;
  switch (factor_22)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001970_7013_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st_1 = {0};
  struct CipherContext_R001970_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int delta_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_65_1) & 63;
  aux_2 = (aux_2 + delta_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_84_1 = local_arr_1[aux_1 % 3];
  int residue_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_84_2 * 2)) & 127;
  int damping_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_17_1 > 13)
  {
    acc_1 = ((acc_1 + (damping_17_1 * 2)) + 5) & 127;
    aux_1 ^= damping_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_17_2 > 13)
  {
    acc_2 = ((acc_2 + (damping_17_2 * 2)) + 5) & 127;
    aux_2 ^= damping_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_17_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_65_1 == delta_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_84_1 == residue_84_2);
  assert(damping_17_1 == damping_17_2);
}

int fn_R001970_7013_2(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int delta_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_65) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_84 = local_arr[aux % 3];
  acc = (acc + (residue_84 * 2)) & 127;
  int damping_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_17 > 13)
  {
    acc = ((acc + (damping_17 * 2)) + 5) & 127;
    aux ^= damping_17 & 15;
  }
  else
  {
    acc = ((acc - damping_17) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001970_7013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st_1 = {0};
  struct CipherContext_R001970_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int cursor_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_62_1) & 63;
  aux_2 = (aux_2 + cursor_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_49_1)
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

  switch (parity_49_2)
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

  int delta_22_1 = 0;
  int delta_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_22_1 = ((delta_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_22_2 = ((delta_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_22_1) & 127;
    acc_2 = (acc_2 + delta_22_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_62_1 == cursor_62_2);
  assert(parity_49_1 == parity_49_2);
  assert(delta_22_1 == delta_22_2);
}

int fn_R001970_7013_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int cursor_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_62) & 63;
  acc ^= aux;
  int parity_49 = (aux + st.buffer[1]) & 3;
  switch (parity_49)
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

  int delta_22 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_22 = ((delta_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_22) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001970_7013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st_1 = {0};
  struct CipherContext_R001970_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int pivot_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_83_1)
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

  switch (pivot_83_2)
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
  int stride_51_1 = local_arr_1[aux_1 % 3];
  int stride_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_51_2 * 2)) & 127;
  int scale_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_64_1) & 63;
  aux_2 = (aux_2 + scale_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_45_1 > 42)
  {
    acc_1 = ((acc_1 + (pivot_45_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_45_2 > 42)
  {
    acc_2 = ((acc_2 + (pivot_45_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_45_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_83_1 == pivot_83_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_51_1 == stride_51_2);
  assert(scale_64_1 == scale_64_2);
  assert(pivot_45_1 == pivot_45_2);
}

int fn_R001970_7013_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int pivot_83 = (aux + st.buffer[1]) & 3;
  switch (pivot_83)
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
  int stride_51 = local_arr[aux % 3];
  acc = (acc + (stride_51 * 2)) & 127;
  int scale_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_64) & 63;
  acc ^= aux;
  int pivot_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_45 > 42)
  {
    acc = ((acc + (pivot_45 * 2)) + 5) & 127;
    aux ^= pivot_45 & 15;
  }
  else
  {
    acc = ((acc - pivot_45) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001970_7013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001970_7013_0 st_1 = {0};
  struct MatrixBlock_R001970_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int damping_88_1 = 0;
  int damping_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_88_1 = ((damping_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_88_2 = ((damping_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_88_1) & 127;
    acc_2 = (acc_2 + damping_88_2) & 127;
  }

  int tally_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_23_1 > 12)
  {
    acc_1 = ((acc_1 + (tally_23_1 * 2)) + 5) & 127;
    aux_1 ^= tally_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_23_2 > 12)
  {
    acc_2 = ((acc_2 + (tally_23_2 * 2)) + 5) & 127;
    aux_2 ^= tally_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_87_1)
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

  switch (tracker_87_2)
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
  int pivot_71_1 = local_arr_1[aux_1 % 3];
  int pivot_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_71_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_88_1 == damping_88_2);
  assert(tally_23_1 == tally_23_2);
  assert(tracker_87_1 == tracker_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_71_1 == pivot_71_2);
}

int fn_R001970_7013_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001970_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int damping_88 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_88 = ((damping_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_88) & 127;
  }

  int tally_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_23 > 12)
  {
    acc = ((acc + (tally_23 * 2)) + 5) & 127;
    aux ^= tally_23 & 15;
  }
  else
  {
    acc = ((acc - tally_23) + 11) & 127;
    aux += 3;
  }
  int tracker_87 = (aux + st.buffer[1]) & 3;
  switch (tracker_87)
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
  int pivot_71 = local_arr[aux % 3];
  acc = (acc + (pivot_71 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001970_7013_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001970_7013_0 st_1 = {0};
  struct MatrixBlock_R001970_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int quantum_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_20_1)
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

  switch (quantum_20_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_20_1 == quantum_20_2);
}

int fn_R001970_7013_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001970_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int quantum_20 = (aux + st.buffer[1]) & 3;
  switch (quantum_20)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001970_7013_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st_1 = {0};
  struct CipherContext_R001970_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int factor_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_10_1 > 24)
  {
    acc_1 = ((acc_1 + (factor_10_1 * 2)) + 5) & 127;
    aux_1 ^= factor_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_10_2 > 24)
  {
    acc_2 = ((acc_2 + (factor_10_2 * 2)) + 5) & 127;
    aux_2 ^= factor_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_78_1)
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

  switch (weight_78_2)
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
  int damping_93_1 = 0;
  int damping_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_93_1 = ((damping_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_93_2 = ((damping_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_93_1) & 127;
    acc_2 = (acc_2 + damping_93_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_10_1 == factor_10_2);
  assert(weight_78_1 == weight_78_2);
  assert(damping_93_1 == damping_93_2);
}

int fn_R001970_7013_7(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int factor_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_10 > 24)
  {
    acc = ((acc + (factor_10 * 2)) + 5) & 127;
    aux ^= factor_10 & 15;
  }
  else
  {
    acc = ((acc - factor_10) + 11) & 127;
    aux += 3;
  }
  int weight_78 = (aux + st.buffer[1]) & 3;
  switch (weight_78)
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
  int damping_93 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_93 = ((damping_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_93) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001970_7013_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001970_7013_1 st_1 = {0};
  struct StreamBuffer_R001970_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int stride_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_90_1)
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

  switch (stride_90_2)
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

  int tracker_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_92_1) & 63;
  aux_2 = (aux_2 + tracker_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_90_1 == stride_90_2);
  assert(tracker_92_1 == tracker_92_2);
}

int fn_R001970_7013_8(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001970_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int stride_90 = (aux + st.buffer[1]) & 3;
  switch (stride_90)
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

  int tracker_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001970_7013_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001970_7013_0 st_1 = {0};
  struct MatrixBlock_R001970_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_23_1 = local_arr_1[aux_1 % 3];
  int tracker_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_23_2 * 2)) & 127;
  int accumulator_48_1 = 0;
  int accumulator_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_48_1 = ((accumulator_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_48_2 = ((accumulator_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_48_1) & 127;
    acc_2 = (acc_2 + accumulator_48_2) & 127;
  }

  int checksum_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_10_1)
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

  switch (checksum_10_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_23_1 == tracker_23_2);
  assert(accumulator_48_1 == accumulator_48_2);
  assert(checksum_10_1 == checksum_10_2);
}

int fn_R001970_7013_9(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001970_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int tracker_23 = local_arr[aux % 3];
  acc = (acc + (tracker_23 * 2)) & 127;
  int accumulator_48 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_48 = ((accumulator_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_48) & 127;
  }

  int checksum_10 = (aux + st.buffer[1]) & 3;
  switch (checksum_10)
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

void fn_R001970_7013_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001970_7013_1 st_1 = {0};
  struct StreamBuffer_R001970_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int scale_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_89_1)
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

  switch (scale_89_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_72_1 = local_arr_1[aux_1 % 3];
  int phase_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_72_2 * 2)) & 127;
  int quantum_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_80_1) & 63;
  aux_2 = (aux_2 + quantum_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_89_1 == scale_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_72_1 == phase_72_2);
  assert(quantum_80_1 == quantum_80_2);
}

int fn_R001970_7013_10(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001970_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int scale_89 = (aux + st.buffer[1]) & 3;
  switch (scale_89)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_72 = local_arr[aux % 3];
  acc = (acc + (phase_72 * 2)) & 127;
  int quantum_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001970_7013_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001970_7013_0 st_1 = {0};
  struct MatrixBlock_R001970_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int quantum_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_60_1)
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

  switch (quantum_60_2)
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

  int index_reg_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_32_1) & 63;
  aux_2 = (aux_2 + index_reg_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_16_1 > 28)
  {
    acc_1 = ((acc_1 + (index_reg_16_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_16_2 > 28)
  {
    acc_2 = ((acc_2 + (index_reg_16_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_16_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_60_1 == quantum_60_2);
  assert(index_reg_32_1 == index_reg_32_2);
  assert(index_reg_16_1 == index_reg_16_2);
}

int fn_R001970_7013_11(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001970_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int quantum_60 = (aux + st.buffer[1]) & 3;
  switch (quantum_60)
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

  int index_reg_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_32) & 63;
  acc ^= aux;
  int index_reg_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_16 > 28)
  {
    acc = ((acc + (index_reg_16 * 2)) + 5) & 127;
    aux ^= index_reg_16 & 15;
  }
  else
  {
    acc = ((acc - index_reg_16) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001970_7013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st_1 = {0};
  struct CipherContext_R001970_7013_2 st_2 = {0};
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
  int damping_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_59_1 > 27)
  {
    acc_1 = ((acc_1 + (damping_59_1 * 2)) + 5) & 127;
    aux_1 ^= damping_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_59_2 > 27)
  {
    acc_2 = ((acc_2 + (damping_59_2 * 2)) + 5) & 127;
    aux_2 ^= damping_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_95_1)
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

  switch (bound_95_2)
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
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_59_1 == damping_59_2);
  assert(bound_95_1 == bound_95_2);
}

int fn_R001970_7013_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_59 > 27)
  {
    acc = ((acc + (damping_59 * 2)) + 5) & 127;
    aux ^= damping_59 & 15;
  }
  else
  {
    acc = ((acc - damping_59) + 11) & 127;
    aux += 3;
  }
  int bound_95 = (aux + st.buffer[1]) & 3;
  switch (bound_95)
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

void fn_R001970_7013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st_1 = {0};
  struct CipherContext_R001970_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_56_1) & 63;
  aux_2 = (aux_2 + scale_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_69_1)
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

  switch (weight_69_2)
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

  int stride_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_21_1 > 14)
  {
    acc_1 = ((acc_1 + (stride_21_1 * 2)) + 5) & 127;
    aux_1 ^= stride_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_21_2 > 14)
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
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_56_1 == scale_56_2);
  assert(weight_69_1 == weight_69_2);
  assert(stride_21_1 == stride_21_2);
}

int fn_R001970_7013_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_56) & 63;
  acc ^= aux;
  int weight_69 = (aux + st.buffer[1]) & 3;
  switch (weight_69)
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

  int stride_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_21 > 14)
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

void fn_R001970_7013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st_1 = {0};
  struct CipherContext_R001970_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_58_1 = 0;
  int stride_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_58_1 = ((stride_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_58_2 = ((stride_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_58_1) & 127;
    acc_2 = (acc_2 + stride_58_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_36_1 = local_arr_1[aux_1 % 3];
  int bound_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_58_1 == stride_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_36_1 == bound_36_2);
}

int fn_R001970_7013_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_58 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_58 = ((stride_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_58) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int bound_36 = local_arr[aux % 3];
  acc = (acc + (bound_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001970_7013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001970_7013_1 st_1 = {0};
  struct StreamBuffer_R001970_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int margin_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_45_1)
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

  switch (margin_45_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_95_1 > 24)
  {
    acc_1 = ((acc_1 + (scale_95_1 * 2)) + 5) & 127;
    aux_1 ^= scale_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_95_2 > 24)
  {
    acc_2 = ((acc_2 + (scale_95_2 * 2)) + 5) & 127;
    aux_2 ^= scale_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_95_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_45_1 == margin_45_2);
  assert(scale_95_1 == scale_95_2);
}

int fn_R001970_7013_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001970_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int margin_45 = (aux + st.buffer[1]) & 3;
  switch (margin_45)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_95 > 24)
  {
    acc = ((acc + (scale_95 * 2)) + 5) & 127;
    aux ^= scale_95 & 15;
  }
  else
  {
    acc = ((acc - scale_95) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001970_7013_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001970_7013_0 st_1 = {0};
  struct MatrixBlock_R001970_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int weight_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_13_1 > 42)
  {
    acc_1 = ((acc_1 + (weight_13_1 * 2)) + 5) & 127;
    aux_1 ^= weight_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_13_2 > 42)
  {
    acc_2 = ((acc_2 + (weight_13_2 * 2)) + 5) & 127;
    aux_2 ^= weight_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_31_1 = local_arr_1[aux_1 % 3];
  int parity_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_31_2 * 2)) & 127;
  int tally_38_1 = 0;
  int tally_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_38_1 = ((tally_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_38_2 = ((tally_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_38_1) & 127;
    acc_2 = (acc_2 + tally_38_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_13_1 == weight_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_31_1 == parity_31_2);
  assert(tally_38_1 == tally_38_2);
}

int fn_R001970_7013_16(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001970_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int weight_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_13 > 42)
  {
    acc = ((acc + (weight_13 * 2)) + 5) & 127;
    aux ^= weight_13 & 15;
  }
  else
  {
    acc = ((acc - weight_13) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_31 = local_arr[aux % 3];
  acc = (acc + (parity_31 * 2)) & 127;
  int tally_38 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_38 = ((tally_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_38) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001970_7013_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001970_7013_0 st_1 = {0};
  struct MatrixBlock_R001970_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int delta_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_13_1) & 63;
  aux_2 = (aux_2 + delta_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_16_1 > 49)
  {
    acc_1 = ((acc_1 + (anchor_16_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_16_2 > 49)
  {
    acc_2 = ((acc_2 + (anchor_16_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_95_1 = 0;
  int residue_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_95_1 = ((residue_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_95_2 = ((residue_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_95_1) & 127;
    acc_2 = (acc_2 + residue_95_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_13_1 == delta_13_2);
  assert(anchor_16_1 == anchor_16_2);
  assert(residue_95_1 == residue_95_2);
}

int fn_R001970_7013_17(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001970_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int delta_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_13) & 63;
  acc ^= aux;
  int anchor_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_16 > 49)
  {
    acc = ((acc + (anchor_16 * 2)) + 5) & 127;
    aux ^= anchor_16 & 15;
  }
  else
  {
    acc = ((acc - anchor_16) + 11) & 127;
    aux += 3;
  }
  int residue_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_95 = ((residue_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_95) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001970_7013_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001970_7013_1 st_1 = {0};
  struct StreamBuffer_R001970_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int residue_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_24_1) & 63;
  aux_2 = (aux_2 + residue_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_92_1 = local_arr_1[aux_1 % 3];
  int coefficient_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_92_2 * 2)) & 127;
  int quantum_29_1 = 0;
  int quantum_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_29_1 = ((quantum_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_29_2 = ((quantum_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_29_1) & 127;
    acc_2 = (acc_2 + quantum_29_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_24_1 == residue_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_92_1 == coefficient_92_2);
  assert(quantum_29_1 == quantum_29_2);
}

int fn_R001970_7013_18(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001970_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int residue_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_24) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_92 = local_arr[aux % 3];
  acc = (acc + (coefficient_92 * 2)) & 127;
  int quantum_29 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_29 = ((quantum_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_29) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001970_7013_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001970_7013_1 st_1 = {0};
  struct StreamBuffer_R001970_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int offset_29_1 = 0;
  int offset_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_29_1 = ((offset_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_29_2 = ((offset_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_29_1) & 127;
    acc_2 = (acc_2 + offset_29_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_33_1 = local_arr_1[aux_1 % 3];
  int phase_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_33_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_29_1 == offset_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_33_1 == phase_33_2);
}

int fn_R001970_7013_19(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001970_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int offset_29 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_29 = ((offset_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_29) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int phase_33 = local_arr[aux % 3];
  acc = (acc + (phase_33 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001970_7013_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st_1 = {0};
  struct CipherContext_R001970_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int offset_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_99_1) & 63;
  aux_2 = (aux_2 + offset_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_53_1 = local_arr_1[aux_1 % 3];
  int damping_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_53_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_99_1 == offset_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_53_1 == damping_53_2);
}

int fn_R001970_7013_20(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int offset_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_99) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_53 = local_arr[aux % 3];
  acc = (acc + (damping_53 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001970_7013_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st_1 = {0};
  struct CipherContext_R001970_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int phase_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_55_1 > 22)
  {
    acc_1 = ((acc_1 + (phase_55_1 * 2)) + 5) & 127;
    aux_1 ^= phase_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_55_2 > 22)
  {
    acc_2 = ((acc_2 + (phase_55_2 * 2)) + 5) & 127;
    aux_2 ^= phase_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_13_1 = local_arr_1[aux_1 % 3];
  int scale_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_55_1 == phase_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_13_1 == scale_13_2);
}

int fn_R001970_7013_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int phase_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_55 > 22)
  {
    acc = ((acc + (phase_55 * 2)) + 5) & 127;
    aux ^= phase_55 & 15;
  }
  else
  {
    acc = ((acc - phase_55) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int scale_13 = local_arr[aux % 3];
  acc = (acc + (scale_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001970_7013_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st_1 = {0};
  struct CipherContext_R001970_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_29_1 = local_arr_1[aux_1 % 3];
  int bound_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_29_1 == bound_29_2);
}

int fn_R001970_7013_22(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001970_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int bound_29 = local_arr[aux % 3];
  acc = (acc + (bound_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001970_0_1;
  int sec_r001970_0_2;
  int sec_r001970_1_1;
  int sec_r001970_1_2;
  int sec_r001970_2_1;
  int sec_r001970_2_2;
  int sec_r001970_3_1;
  int sec_r001970_3_2;
  int sec_r001970_4_1;
  int sec_r001970_4_2;
  int sec_r001970_5_1;
  int sec_r001970_5_2;
  int sec_r001970_6_1;
  int sec_r001970_6_2;
  int sec_r001970_7_1;
  int sec_r001970_7_2;
  int sec_r001970_8_1;
  int sec_r001970_8_2;
  int sec_r001970_9_1;
  int sec_r001970_9_2;
  int sec_r001970_10_1;
  int sec_r001970_10_2;
  int sec_r001970_11_1;
  int sec_r001970_11_2;
  int sec_r001970_12_1;
  int sec_r001970_12_2;
  int sec_r001970_13_1;
  int sec_r001970_13_2;
  int sec_r001970_14_1;
  int sec_r001970_14_2;
  int sec_r001970_15_1;
  int sec_r001970_15_2;
  int sec_r001970_16_1;
  int sec_r001970_16_2;
  int sec_r001970_17_1;
  int sec_r001970_17_2;
  int pub_r001970_0_1;
  int pub_r001970_0_2;
  int pub_r001970_1_1;
  int pub_r001970_1_2;
  int pub_r001970_2_1;
  int pub_r001970_2_2;
  int pub_r001970_3_1;
  int pub_r001970_3_2;
  int pub_r001970_4_1;
  int pub_r001970_4_2;
  int pub_r001970_5_1;
  int pub_r001970_5_2;
  int pub_r001970_6_1;
  int pub_r001970_6_2;
  int pub_r001970_7_1;
  int pub_r001970_7_2;
  int pub_r001970_8_1;
  int pub_r001970_8_2;
  int pub_r001970_9_1;
  int pub_r001970_9_2;
  int pub_r001970_10_1;
  int pub_r001970_10_2;
  int pub_r001970_11_1;
  int pub_r001970_11_2;
  int pub_r001970_12_1;
  int pub_r001970_12_2;
  int pub_r001970_13_1;
  int pub_r001970_13_2;
  int pub_r001970_14_1;
  int pub_r001970_14_2;
  int pub_r001970_15_1;
  int pub_r001970_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001970_0_1 >= (-100)) && (pub_r001970_0_1 <= 100));
  __CPROVER_assume((pub_r001970_0_2 >= (-100)) && (pub_r001970_0_2 <= 100));
  __CPROVER_assume((pub_r001970_1_1 >= (-100)) && (pub_r001970_1_1 <= 100));
  __CPROVER_assume((pub_r001970_1_2 >= (-100)) && (pub_r001970_1_2 <= 100));
  __CPROVER_assume((pub_r001970_2_1 >= (-100)) && (pub_r001970_2_1 <= 100));
  __CPROVER_assume((pub_r001970_2_2 >= (-100)) && (pub_r001970_2_2 <= 100));
  __CPROVER_assume((pub_r001970_3_1 >= (-100)) && (pub_r001970_3_1 <= 100));
  __CPROVER_assume((pub_r001970_3_2 >= (-100)) && (pub_r001970_3_2 <= 100));
  __CPROVER_assume((pub_r001970_4_1 >= (-100)) && (pub_r001970_4_1 <= 100));
  __CPROVER_assume((pub_r001970_4_2 >= (-100)) && (pub_r001970_4_2 <= 100));
  __CPROVER_assume((pub_r001970_5_1 >= (-100)) && (pub_r001970_5_1 <= 100));
  __CPROVER_assume((pub_r001970_5_2 >= (-100)) && (pub_r001970_5_2 <= 100));
  __CPROVER_assume((pub_r001970_6_1 >= (-100)) && (pub_r001970_6_1 <= 100));
  __CPROVER_assume((pub_r001970_6_2 >= (-100)) && (pub_r001970_6_2 <= 100));
  __CPROVER_assume((pub_r001970_7_1 >= (-100)) && (pub_r001970_7_1 <= 100));
  __CPROVER_assume((pub_r001970_7_2 >= (-100)) && (pub_r001970_7_2 <= 100));
  __CPROVER_assume((pub_r001970_8_1 >= (-100)) && (pub_r001970_8_1 <= 100));
  __CPROVER_assume((pub_r001970_8_2 >= (-100)) && (pub_r001970_8_2 <= 100));
  __CPROVER_assume((pub_r001970_9_1 >= (-100)) && (pub_r001970_9_1 <= 100));
  __CPROVER_assume((pub_r001970_9_2 >= (-100)) && (pub_r001970_9_2 <= 100));
  __CPROVER_assume((pub_r001970_10_1 >= (-100)) && (pub_r001970_10_1 <= 100));
  __CPROVER_assume((pub_r001970_10_2 >= (-100)) && (pub_r001970_10_2 <= 100));
  __CPROVER_assume((pub_r001970_11_1 >= (-100)) && (pub_r001970_11_1 <= 100));
  __CPROVER_assume((pub_r001970_11_2 >= (-100)) && (pub_r001970_11_2 <= 100));
  __CPROVER_assume((pub_r001970_12_1 >= (-100)) && (pub_r001970_12_1 <= 100));
  __CPROVER_assume((pub_r001970_12_2 >= (-100)) && (pub_r001970_12_2 <= 100));
  __CPROVER_assume((pub_r001970_13_1 >= (-100)) && (pub_r001970_13_1 <= 100));
  __CPROVER_assume((pub_r001970_13_2 >= (-100)) && (pub_r001970_13_2 <= 100));
  __CPROVER_assume((pub_r001970_14_1 >= (-100)) && (pub_r001970_14_1 <= 100));
  __CPROVER_assume((pub_r001970_14_2 >= (-100)) && (pub_r001970_14_2 <= 100));
  __CPROVER_assume((pub_r001970_15_1 >= (-100)) && (pub_r001970_15_1 <= 100));
  __CPROVER_assume((pub_r001970_15_2 >= (-100)) && (pub_r001970_15_2 <= 100));
  __CPROVER_assume((sec_r001970_0_1 >= 0) && (sec_r001970_0_1 <= 255));
  __CPROVER_assume((sec_r001970_0_2 >= 0) && (sec_r001970_0_2 <= 255));
  __CPROVER_assume((sec_r001970_1_1 >= 0) && (sec_r001970_1_1 <= 255));
  __CPROVER_assume((sec_r001970_1_2 >= 0) && (sec_r001970_1_2 <= 255));
  __CPROVER_assume((sec_r001970_2_1 >= 0) && (sec_r001970_2_1 <= 255));
  __CPROVER_assume((sec_r001970_2_2 >= 0) && (sec_r001970_2_2 <= 255));
  __CPROVER_assume((sec_r001970_3_1 >= 0) && (sec_r001970_3_1 <= 255));
  __CPROVER_assume((sec_r001970_3_2 >= 0) && (sec_r001970_3_2 <= 255));
  __CPROVER_assume((sec_r001970_4_1 >= 0) && (sec_r001970_4_1 <= 255));
  __CPROVER_assume((sec_r001970_4_2 >= 0) && (sec_r001970_4_2 <= 255));
  __CPROVER_assume((sec_r001970_5_1 >= 0) && (sec_r001970_5_1 <= 255));
  __CPROVER_assume((sec_r001970_5_2 >= 0) && (sec_r001970_5_2 <= 255));
  __CPROVER_assume((sec_r001970_6_1 >= 0) && (sec_r001970_6_1 <= 255));
  __CPROVER_assume((sec_r001970_6_2 >= 0) && (sec_r001970_6_2 <= 255));
  __CPROVER_assume((sec_r001970_7_1 >= 0) && (sec_r001970_7_1 <= 255));
  __CPROVER_assume((sec_r001970_7_2 >= 0) && (sec_r001970_7_2 <= 255));
  __CPROVER_assume((sec_r001970_8_1 >= 0) && (sec_r001970_8_1 <= 255));
  __CPROVER_assume((sec_r001970_8_2 >= 0) && (sec_r001970_8_2 <= 255));
  __CPROVER_assume((sec_r001970_9_1 >= 0) && (sec_r001970_9_1 <= 255));
  __CPROVER_assume((sec_r001970_9_2 >= 0) && (sec_r001970_9_2 <= 255));
  __CPROVER_assume((sec_r001970_10_1 >= 0) && (sec_r001970_10_1 <= 255));
  __CPROVER_assume((sec_r001970_10_2 >= 0) && (sec_r001970_10_2 <= 255));
  __CPROVER_assume((sec_r001970_11_1 >= 0) && (sec_r001970_11_1 <= 255));
  __CPROVER_assume((sec_r001970_11_2 >= 0) && (sec_r001970_11_2 <= 255));
  __CPROVER_assume((sec_r001970_12_1 >= 0) && (sec_r001970_12_1 <= 255));
  __CPROVER_assume((sec_r001970_12_2 >= 0) && (sec_r001970_12_2 <= 255));
  __CPROVER_assume((sec_r001970_13_1 >= 0) && (sec_r001970_13_1 <= 255));
  __CPROVER_assume((sec_r001970_13_2 >= 0) && (sec_r001970_13_2 <= 255));
  __CPROVER_assume((sec_r001970_14_1 >= 0) && (sec_r001970_14_1 <= 255));
  __CPROVER_assume((sec_r001970_14_2 >= 0) && (sec_r001970_14_2 <= 255));
  __CPROVER_assume((sec_r001970_15_1 >= 0) && (sec_r001970_15_1 <= 255));
  __CPROVER_assume((sec_r001970_15_2 >= 0) && (sec_r001970_15_2 <= 255));
  __CPROVER_assume((sec_r001970_16_1 >= 0) && (sec_r001970_16_1 <= 255));
  __CPROVER_assume((sec_r001970_16_2 >= 0) && (sec_r001970_16_2 <= 255));
  __CPROVER_assume((sec_r001970_17_1 >= 0) && (sec_r001970_17_1 <= 255));
  __CPROVER_assume((sec_r001970_17_2 >= 0) && (sec_r001970_17_2 <= 255));
  struct MatrixBlock_R001970_7013_0 st_var_0_1 = {0};
  struct MatrixBlock_R001970_7013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001970_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001970_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001970_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001970_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001970_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001970_0_2 + 7) & 15;
  struct StreamBuffer_R001970_7013_1 st_var_1_1 = {0};
  struct StreamBuffer_R001970_7013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001970_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001970_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001970_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001970_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001970_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001970_0_2 + 9) & 15;
  struct CipherContext_R001970_7013_2 st_var_2_1 = {0};
  struct CipherContext_R001970_7013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001970_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001970_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001970_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001970_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001970_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001970_0_2 + 11) & 15;
  union ColorPixel_R001970_7013_0 u_var_1;
  union ColorPixel_R001970_7013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001970_7013_0(sec_r001970_0_1, pub_r001970_1_1);
  int helper_flow_0_2 = fn_R001970_7013_0(sec_r001970_0_2, pub_r001970_1_2);
  fn_R001970_7013_0_2(sec_r001970_0_1, pub_r001970_1_1, sec_r001970_0_2, pub_r001970_1_2);
  int helper_flow_1_1 = fn_R001970_7013_1(sec_r001970_1_1, sec_r001970_2_1, pub_r001970_3_1);
  int helper_flow_1_2 = fn_R001970_7013_1(sec_r001970_1_2, sec_r001970_2_2, pub_r001970_3_2);
  fn_R001970_7013_1_2(sec_r001970_1_1, sec_r001970_2_1, pub_r001970_3_1, sec_r001970_1_2, sec_r001970_2_2, pub_r001970_3_2);
  int helper_flow_2_1 = fn_R001970_7013_2(sec_r001970_2_1, pub_r001970_3_1, pub_r001970_4_1);
  int helper_flow_2_2 = fn_R001970_7013_2(sec_r001970_2_2, pub_r001970_3_2, pub_r001970_4_2);
  fn_R001970_7013_2_2(sec_r001970_2_1, pub_r001970_3_1, pub_r001970_4_1, sec_r001970_2_2, pub_r001970_3_2, pub_r001970_4_2);
  int helper_flow_3_1 = fn_R001970_7013_3(sec_r001970_3_1, sec_r001970_4_1, pub_r001970_5_1, pub_r001970_6_1, pub_r001970_7_1);
  int helper_flow_3_2 = fn_R001970_7013_3(sec_r001970_3_2, sec_r001970_4_2, pub_r001970_5_2, pub_r001970_6_2, pub_r001970_7_2);
  fn_R001970_7013_3_2(sec_r001970_3_1, sec_r001970_4_1, pub_r001970_5_1, pub_r001970_6_1, pub_r001970_7_1, sec_r001970_3_2, sec_r001970_4_2, pub_r001970_5_2, pub_r001970_6_2, pub_r001970_7_2);
  int helper_flow_4_1 = fn_R001970_7013_4(sec_r001970_4_1, pub_r001970_5_1, pub_r001970_6_1, pub_r001970_7_1, pub_r001970_8_1);
  int helper_flow_4_2 = fn_R001970_7013_4(sec_r001970_4_2, pub_r001970_5_2, pub_r001970_6_2, pub_r001970_7_2, pub_r001970_8_2);
  fn_R001970_7013_4_2(sec_r001970_4_1, pub_r001970_5_1, pub_r001970_6_1, pub_r001970_7_1, pub_r001970_8_1, sec_r001970_4_2, pub_r001970_5_2, pub_r001970_6_2, pub_r001970_7_2, pub_r001970_8_2);
  int helper_flow_5_1 = fn_R001970_7013_5(sec_r001970_5_1, sec_r001970_6_1, pub_r001970_7_1, pub_r001970_8_1);
  int helper_flow_5_2 = fn_R001970_7013_5(sec_r001970_5_2, sec_r001970_6_2, pub_r001970_7_2, pub_r001970_8_2);
  fn_R001970_7013_5_2(sec_r001970_5_1, sec_r001970_6_1, pub_r001970_7_1, pub_r001970_8_1, sec_r001970_5_2, sec_r001970_6_2, pub_r001970_7_2, pub_r001970_8_2);
  int helper_flow_6_1 = fn_R001970_7013_6(sec_r001970_6_1, pub_r001970_7_1, pub_r001970_8_1, pub_r001970_9_1);
  int helper_flow_6_2 = fn_R001970_7013_6(sec_r001970_6_2, pub_r001970_7_2, pub_r001970_8_2, pub_r001970_9_2);
  fn_R001970_7013_6_2(sec_r001970_6_1, pub_r001970_7_1, pub_r001970_8_1, pub_r001970_9_1, sec_r001970_6_2, pub_r001970_7_2, pub_r001970_8_2, pub_r001970_9_2);
  int helper_flow_7_1 = fn_R001970_7013_7(sec_r001970_7_1, sec_r001970_8_1);
  int helper_flow_7_2 = fn_R001970_7013_7(sec_r001970_7_2, sec_r001970_8_2);
  fn_R001970_7013_7_2(sec_r001970_7_1, sec_r001970_8_1, sec_r001970_7_2, sec_r001970_8_2);
  int helper_flow_8_1 = fn_R001970_7013_8(sec_r001970_8_1, sec_r001970_9_1);
  int helper_flow_8_2 = fn_R001970_7013_8(sec_r001970_8_2, sec_r001970_9_2);
  fn_R001970_7013_8_2(sec_r001970_8_1, sec_r001970_9_1, sec_r001970_8_2, sec_r001970_9_2);
  int helper_flow_9_1 = fn_R001970_7013_9(sec_r001970_9_1, sec_r001970_10_1);
  int helper_flow_9_2 = fn_R001970_7013_9(sec_r001970_9_2, sec_r001970_10_2);
  fn_R001970_7013_9_2(sec_r001970_9_1, sec_r001970_10_1, sec_r001970_9_2, sec_r001970_10_2);
  int helper_flow_10_1 = fn_R001970_7013_10(sec_r001970_10_1, sec_r001970_11_1);
  int helper_flow_10_2 = fn_R001970_7013_10(sec_r001970_10_2, sec_r001970_11_2);
  fn_R001970_7013_10_2(sec_r001970_10_1, sec_r001970_11_1, sec_r001970_10_2, sec_r001970_11_2);
  int helper_flow_11_1 = fn_R001970_7013_11(sec_r001970_11_1, pub_r001970_12_1);
  int helper_flow_11_2 = fn_R001970_7013_11(sec_r001970_11_2, pub_r001970_12_2);
  fn_R001970_7013_11_2(sec_r001970_11_1, pub_r001970_12_1, sec_r001970_11_2, pub_r001970_12_2);
  int helper_flow_12_1 = fn_R001970_7013_12(sec_r001970_12_1, sec_r001970_13_1, pub_r001970_14_1, pub_r001970_15_1);
  int helper_flow_12_2 = fn_R001970_7013_12(sec_r001970_12_2, sec_r001970_13_2, pub_r001970_14_2, pub_r001970_15_2);
  fn_R001970_7013_12_2(sec_r001970_12_1, sec_r001970_13_1, pub_r001970_14_1, pub_r001970_15_1, sec_r001970_12_2, sec_r001970_13_2, pub_r001970_14_2, pub_r001970_15_2);
  int helper_flow_13_1 = fn_R001970_7013_13(sec_r001970_13_1, sec_r001970_14_1, pub_r001970_15_1, pub_r001970_0_1);
  int helper_flow_13_2 = fn_R001970_7013_13(sec_r001970_13_2, sec_r001970_14_2, pub_r001970_15_2, pub_r001970_0_2);
  fn_R001970_7013_13_2(sec_r001970_13_1, sec_r001970_14_1, pub_r001970_15_1, pub_r001970_0_1, sec_r001970_13_2, sec_r001970_14_2, pub_r001970_15_2, pub_r001970_0_2);
  int stage_v_0_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001970_4_1) & 127;
  int stage_v_0_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001970_4_2) & 127;
  if (stage_v_0_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((sec_r001970_3_1 ^ 0x2A) * 2) + pub_r001970_4_1) & 127;
  int stage_v_1_2 = (((sec_r001970_3_2 ^ 0x2A) * 2) + pub_r001970_4_2) & 127;
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
  int stage_v_2_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001970_12_1) & 127;
  int stage_v_2_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001970_12_2) & 127;
  if (stage_v_2_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001970_8_1) & 127;
  int stage_v_3_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001970_8_2) & 127;
  if (stage_v_3_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((sec_r001970_15_1 ^ 0x2A) * 2) + pub_r001970_13_1) & 127;
  int stage_v_4_2 = (((sec_r001970_15_2 ^ 0x2A) * 2) + pub_r001970_13_2) & 127;
  if (stage_v_4_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((sec_r001970_11_1 ^ 0x2A) * 2) + pub_r001970_7_1) & 127;
  int stage_v_5_2 = (((sec_r001970_11_2 ^ 0x2A) * 2) + pub_r001970_7_2) & 127;
  if (stage_v_5_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001970_4_1) & 127;
  int stage_v_6_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001970_4_2) & 127;
  if (stage_v_6_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001970_7_1) & 127;
  int stage_v_7_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001970_7_2) & 127;
  if (stage_v_7_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001970_1_1) & 127;
  int stage_v_8_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001970_1_2) & 127;
  if (stage_v_8_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((sec_r001970_6_1 ^ 0x2A) * 2) + pub_r001970_9_1) & 127;
  int stage_v_9_2 = (((sec_r001970_6_2 ^ 0x2A) * 2) + pub_r001970_9_2) & 127;
  if (stage_v_9_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001970_13_1) & 127;
  int stage_v_10_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001970_13_2) & 127;
  if (stage_v_10_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((sec_r001970_9_1 ^ 0x2A) * 2) + pub_r001970_6_1) & 127;
  int stage_v_11_2 = (((sec_r001970_9_2 ^ 0x2A) * 2) + pub_r001970_6_2) & 127;
  if (stage_v_11_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((sec_r001970_11_1 ^ 0x2A) * 2) + pub_r001970_12_1) & 127;
  int stage_v_12_2 = (((sec_r001970_11_2 ^ 0x2A) * 2) + pub_r001970_12_2) & 127;
  if (stage_v_12_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001970_8_1) & 127;
  int stage_v_13_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001970_8_2) & 127;
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
  int stage_v_14_1 = ((pub_r001970_4_1 * 2) + 43) & 63;
  int stage_v_14_2 = ((pub_r001970_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((sec_r001970_16_1 ^ 0x2A) * 2) + pub_r001970_3_1) & 127;
  int stage_v_15_2 = (((sec_r001970_16_2 ^ 0x2A) * 2) + pub_r001970_3_2) & 127;
  if (stage_v_15_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((pub_r001970_8_1 * 2) + 8) & 63;
  int stage_v_16_2 = ((pub_r001970_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001970_1_1 * 2) + 30) & 63;
  int stage_v_17_2 = ((pub_r001970_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (((sec_r001970_9_1 ^ 0x2A) * 2) + pub_r001970_15_1) & 127;
  int stage_v_18_2 = (((sec_r001970_9_2 ^ 0x2A) * 2) + pub_r001970_15_2) & 127;
  if (stage_v_18_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001970_11_1) & 127;
  int stage_v_19_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001970_11_2) & 127;
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
  int stage_v_20_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001970_13_1) & 127;
  int stage_v_20_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001970_13_2) & 127;
  if (stage_v_20_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001970_3_1) & 127;
  int stage_v_21_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001970_3_2) & 127;
  if (stage_v_21_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001970_11_1) & 127;
  int stage_v_22_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001970_11_2) & 127;
  if (stage_v_22_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001970_9_1) & 127;
  int stage_v_23_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001970_9_2) & 127;
  if (stage_v_23_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = ((pub_r001970_5_1 * 2) + 39) & 63;
  int stage_v_24_2 = ((pub_r001970_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001970_15_1 * 2) + 36) & 63;
  int stage_v_25_2 = ((pub_r001970_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((sec_r001970_15_1 ^ 0x2A) * 2) + pub_r001970_11_1) & 127;
  int stage_v_26_2 = (((sec_r001970_15_2 ^ 0x2A) * 2) + pub_r001970_11_2) & 127;
  if (stage_v_26_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((sec_r001970_6_1 ^ 0x2A) * 2) + pub_r001970_10_1) & 127;
  int stage_v_27_2 = (((sec_r001970_6_2 ^ 0x2A) * 2) + pub_r001970_10_2) & 127;
  if (stage_v_27_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((pub_r001970_9_1 * 2) + 14) & 63;
  int stage_v_28_2 = ((pub_r001970_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001970_14_1 * 2) + 48) & 63;
  int stage_v_29_2 = ((pub_r001970_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001970_14_1) & 127;
  int stage_v_30_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001970_14_2) & 127;
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
  int stage_v_31_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001970_9_1) & 127;
  int stage_v_31_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001970_9_2) & 127;
  if (stage_v_31_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((sec_r001970_9_1 ^ 0x2A) * 2) + pub_r001970_4_1) & 127;
  int stage_v_32_2 = (((sec_r001970_9_2 ^ 0x2A) * 2) + pub_r001970_4_2) & 127;
  if (stage_v_32_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((pub_r001970_5_1 * 2) + 13) & 63;
  int stage_v_33_2 = ((pub_r001970_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001970_14_1) & 127;
  int stage_v_34_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001970_14_2) & 127;
  if (stage_v_34_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((sec_r001970_2_1 ^ 0x2A) * 2) + pub_r001970_8_1) & 127;
  int stage_v_35_2 = (((sec_r001970_2_2 ^ 0x2A) * 2) + pub_r001970_8_2) & 127;
  if (stage_v_35_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001970_5_1) & 127;
  int stage_v_36_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001970_5_2) & 127;
  if (stage_v_36_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001970_0_1) & 127;
  int stage_v_37_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001970_0_2) & 127;
  if (stage_v_37_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((pub_r001970_2_1 * 2) + 6) & 63;
  int stage_v_38_2 = ((pub_r001970_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001970_15_1) & 127;
  int stage_v_39_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001970_15_2) & 127;
  if (stage_v_39_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001970_14_1) & 127;
  int stage_v_40_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001970_14_2) & 127;
  if (stage_v_40_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001970_5_1) & 127;
  int stage_v_41_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001970_5_2) & 127;
  if (stage_v_41_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((pub_r001970_0_1 * 2) + 18) & 63;
  int stage_v_42_2 = ((pub_r001970_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001970_15_1) & 127;
  int stage_v_43_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001970_15_2) & 127;
  if (stage_v_43_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001970_15_1) & 127;
  int stage_v_44_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001970_15_2) & 127;
  if (stage_v_44_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001970_11_1) & 127;
  int stage_v_45_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001970_11_2) & 127;
  if (stage_v_45_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((pub_r001970_3_1 * 2) + 44) & 63;
  int stage_v_46_2 = ((pub_r001970_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001970_2_1) & 127;
  int stage_v_47_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001970_2_2) & 127;
  if (stage_v_47_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001970_5_1) & 127;
  int stage_v_48_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001970_5_2) & 127;
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
  int stage_v_49_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001970_13_1) & 127;
  int stage_v_49_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001970_13_2) & 127;
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
  int stage_v_50_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001970_14_1) & 127;
  int stage_v_50_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001970_14_2) & 127;
  if (stage_v_50_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((sec_r001970_0_1 ^ 0x2A) * 2) + pub_r001970_13_1) & 127;
  int stage_v_51_2 = (((sec_r001970_0_2 ^ 0x2A) * 2) + pub_r001970_13_2) & 127;
  if (stage_v_51_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((pub_r001970_1_1 * 2) + 42) & 63;
  int stage_v_52_2 = ((pub_r001970_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001970_5_1) & 127;
  int stage_v_53_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001970_5_2) & 127;
  if (stage_v_53_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001970_12_1) & 127;
  int stage_v_54_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001970_12_2) & 127;
  if (stage_v_54_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001970_3_1) & 127;
  int stage_v_55_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001970_3_2) & 127;
  if (stage_v_55_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((pub_r001970_8_1 * 2) + 33) & 63;
  int stage_v_56_2 = ((pub_r001970_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (((sec_r001970_15_1 ^ 0x2A) * 2) + pub_r001970_14_1) & 127;
  int stage_v_57_2 = (((sec_r001970_15_2 ^ 0x2A) * 2) + pub_r001970_14_2) & 127;
  if (stage_v_57_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((sec_r001970_8_1 ^ 0x2A) * 2) + pub_r001970_12_1) & 127;
  int stage_v_58_2 = (((sec_r001970_8_2 ^ 0x2A) * 2) + pub_r001970_12_2) & 127;
  if (stage_v_58_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001970_1_1) & 127;
  int stage_v_59_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001970_1_2) & 127;
  if (stage_v_59_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001970_0_1) & 127;
  int stage_v_60_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001970_0_2) & 127;
  if (stage_v_60_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001970_8_1) & 127;
  int stage_v_61_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001970_8_2) & 127;
  if (stage_v_61_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001970_0_1) & 127;
  int stage_v_62_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001970_0_2) & 127;
  if (stage_v_62_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((pub_r001970_11_1 * 2) + 40) & 63;
  int stage_v_63_2 = ((pub_r001970_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001970_4_1) & 127;
  int stage_v_64_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001970_4_2) & 127;
  if (stage_v_64_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001970_5_1) & 127;
  int stage_v_65_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001970_5_2) & 127;
  if (stage_v_65_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((pub_r001970_4_1 * 2) + 46) & 63;
  int stage_v_66_2 = ((pub_r001970_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001970_1_1) & 127;
  int stage_v_67_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001970_1_2) & 127;
  if (stage_v_67_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001970_0_1) & 127;
  int stage_v_68_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001970_0_2) & 127;
  if (stage_v_68_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001970_4_1) & 127;
  int stage_v_69_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001970_4_2) & 127;
  if (stage_v_69_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001970_9_1) & 127;
  int stage_v_70_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001970_9_2) & 127;
  if (stage_v_70_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001970_9_1) & 127;
  int stage_v_71_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001970_9_2) & 127;
  if (stage_v_71_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001970_12_1) & 127;
  int stage_v_72_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001970_12_2) & 127;
  if (stage_v_72_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001970_13_1) & 127;
  int stage_v_73_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001970_13_2) & 127;
  if (stage_v_73_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((pub_r001970_12_1 * 2) + 23) & 63;
  int stage_v_74_2 = ((pub_r001970_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001970_11_1 * 2) + 48) & 63;
  int stage_v_75_2 = ((pub_r001970_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = (((sec_r001970_8_1 ^ 0x2A) * 2) + pub_r001970_3_1) & 127;
  int stage_v_76_2 = (((sec_r001970_8_2 ^ 0x2A) * 2) + pub_r001970_3_2) & 127;
  if (stage_v_76_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((pub_r001970_13_1 * 2) + 30) & 63;
  int stage_v_77_2 = ((pub_r001970_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001970_14_1) & 127;
  int stage_v_78_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001970_14_2) & 127;
  if (stage_v_78_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((sec_r001970_9_1 ^ 0x2A) * 2) + pub_r001970_1_1) & 127;
  int stage_v_79_2 = (((sec_r001970_9_2 ^ 0x2A) * 2) + pub_r001970_1_2) & 127;
  if (stage_v_79_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((pub_r001970_0_1 * 2) + 40) & 63;
  int stage_v_80_2 = ((pub_r001970_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001970_11_1) & 127;
  int stage_v_81_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001970_11_2) & 127;
  if (stage_v_81_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((pub_r001970_11_1 * 2) + 21) & 63;
  int stage_v_82_2 = ((pub_r001970_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001970_7_1) & 127;
  int stage_v_83_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001970_7_2) & 127;
  if (stage_v_83_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001970_3_1) & 127;
  int stage_v_84_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001970_3_2) & 127;
  if (stage_v_84_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (((sec_r001970_1_1 ^ 0x2A) * 2) + pub_r001970_1_1) & 127;
  int stage_v_85_2 = (((sec_r001970_1_2 ^ 0x2A) * 2) + pub_r001970_1_2) & 127;
  if (stage_v_85_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (((sec_r001970_14_1 ^ 0x2A) * 2) + pub_r001970_10_1) & 127;
  int stage_v_86_2 = (((sec_r001970_14_2 ^ 0x2A) * 2) + pub_r001970_10_2) & 127;
  if (stage_v_86_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((pub_r001970_15_1 * 2) + 26) & 63;
  int stage_v_87_2 = ((pub_r001970_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001970_6_1) & 127;
  int stage_v_88_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001970_6_2) & 127;
  if (stage_v_88_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((sec_r001970_10_1 ^ 0x2A) * 2) + pub_r001970_7_1) & 127;
  int stage_v_89_2 = (((sec_r001970_10_2 ^ 0x2A) * 2) + pub_r001970_7_2) & 127;
  if (stage_v_89_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001970_12_1) & 127;
  int stage_v_90_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001970_12_2) & 127;
  if (stage_v_90_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001970_2_1) & 127;
  int stage_v_91_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001970_2_2) & 127;
  if (stage_v_91_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((pub_r001970_3_1 * 2) + 14) & 63;
  int stage_v_92_2 = ((pub_r001970_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001970_0_1 * 2) + 21) & 63;
  int stage_v_93_2 = ((pub_r001970_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001970_5_1 * 2) + 32) & 63;
  int stage_v_94_2 = ((pub_r001970_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001970_0_1) & 127;
  int stage_v_95_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001970_0_2) & 127;
  if (stage_v_95_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001970_7_1) & 127;
  int stage_v_96_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001970_7_2) & 127;
  if (stage_v_96_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001970_15_1) & 127;
  int stage_v_97_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001970_15_2) & 127;
  if (stage_v_97_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((stage_v_69_1 ^ 0x2A) * 2) + pub_r001970_2_1) & 127;
  int stage_v_98_2 = (((stage_v_69_2 ^ 0x2A) * 2) + pub_r001970_2_2) & 127;
  if (stage_v_98_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001970_2_1) & 127;
  int stage_v_99_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001970_2_2) & 127;
  if (stage_v_99_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001970_2_1) & 127;
  int stage_v_100_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001970_2_2) & 127;
  if (stage_v_100_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (((sec_r001970_11_1 ^ 0x2A) * 2) + pub_r001970_3_1) & 127;
  int stage_v_101_2 = (((sec_r001970_11_2 ^ 0x2A) * 2) + pub_r001970_3_2) & 127;
  if (stage_v_101_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((pub_r001970_4_1 * 2) + 41) & 63;
  int stage_v_102_2 = ((pub_r001970_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((helper_flow_12_1 ^ 0x2A) * 2) + pub_r001970_6_1) & 127;
  int stage_v_103_2 = (((helper_flow_12_2 ^ 0x2A) * 2) + pub_r001970_6_2) & 127;
  if (stage_v_103_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((pub_r001970_0_1 * 2) + 49) & 63;
  int stage_v_104_2 = ((pub_r001970_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001970_0_1) & 127;
  int stage_v_105_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001970_0_2) & 127;
  if (stage_v_105_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001970_7_1) & 127;
  int stage_v_106_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001970_7_2) & 127;
  if (stage_v_106_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001970_9_1) & 127;
  int stage_v_107_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001970_9_2) & 127;
  if (stage_v_107_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001970_1_1) & 127;
  int stage_v_108_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001970_1_2) & 127;
  if (stage_v_108_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((pub_r001970_2_1 * 2) + 38) & 63;
  int stage_v_109_2 = ((pub_r001970_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001970_10_1) & 127;
  int stage_v_110_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001970_10_2) & 127;
  if (stage_v_110_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((pub_r001970_2_1 * 2) + 25) & 63;
  int stage_v_111_2 = ((pub_r001970_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((stage_v_72_1 ^ 0x2A) * 2) + pub_r001970_10_1) & 127;
  int stage_v_112_2 = (((stage_v_72_2 ^ 0x2A) * 2) + pub_r001970_10_2) & 127;
  if (stage_v_112_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001970_6_1) & 127;
  int stage_v_113_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001970_6_2) & 127;
  if (stage_v_113_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001970_10_1) & 127;
  int stage_v_114_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001970_10_2) & 127;
  if (stage_v_114_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((pub_r001970_7_1 * 2) + 34) & 63;
  int stage_v_115_2 = ((pub_r001970_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001970_8_1 * 2) + 12) & 63;
  int stage_v_116_2 = ((pub_r001970_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001970_13_1 * 2) + 11) & 63;
  int stage_v_117_2 = ((pub_r001970_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001970_9_1) & 127;
  int stage_v_118_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001970_9_2) & 127;
  if (stage_v_118_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((pub_r001970_10_1 * 2) + 6) & 63;
  int stage_v_119_2 = ((pub_r001970_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001970_13_1 * 2) + 40) & 63;
  int stage_v_120_2 = ((pub_r001970_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001970_12_1 * 2) + 46) & 63;
  int stage_v_121_2 = ((pub_r001970_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001970_15_1) & 127;
  int stage_v_122_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001970_15_2) & 127;
  if (stage_v_122_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001970_13_1) & 127;
  int stage_v_123_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001970_13_2) & 127;
  if (stage_v_123_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((pub_r001970_9_1 * 2) + 22) & 63;
  int stage_v_124_2 = ((pub_r001970_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001970_7_1) & 127;
  int stage_v_125_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001970_7_2) & 127;
  if (stage_v_125_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = (((sec_r001970_0_1 ^ 0x2A) * 2) + pub_r001970_6_1) & 127;
  int stage_v_126_2 = (((sec_r001970_0_2 ^ 0x2A) * 2) + pub_r001970_6_2) & 127;
  if (stage_v_126_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((pub_r001970_11_1 * 2) + 8) & 63;
  int stage_v_127_2 = ((pub_r001970_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001970_5_1 * 2) + 30) & 63;
  int stage_v_128_2 = ((pub_r001970_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001970_6_1) & 127;
  int stage_v_129_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001970_6_2) & 127;
  if (stage_v_129_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_122_1 ^ 0x2A) * 2) + pub_r001970_3_1) & 127;
  int stage_v_130_2 = (((stage_v_122_2 ^ 0x2A) * 2) + pub_r001970_3_2) & 127;
  if (stage_v_130_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((pub_r001970_6_1 * 2) + 37) & 63;
  int stage_v_131_2 = ((pub_r001970_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001970_5_1) & 127;
  int stage_v_132_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001970_5_2) & 127;
  if (stage_v_132_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((stage_v_67_1 ^ 0x2A) * 2) + pub_r001970_15_1) & 127;
  int stage_v_133_2 = (((stage_v_67_2 ^ 0x2A) * 2) + pub_r001970_15_2) & 127;
  if (stage_v_133_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((pub_r001970_0_1 * 2) + 14) & 63;
  int stage_v_134_2 = ((pub_r001970_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001970_7_1 * 2) + 29) & 63;
  int stage_v_135_2 = ((pub_r001970_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001970_0_1) & 127;
  int stage_v_136_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001970_0_2) & 127;
  if (stage_v_136_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001970_1_1) & 127;
  int stage_v_137_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001970_1_2) & 127;
  if (stage_v_137_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((pub_r001970_7_1 * 2) + 21) & 63;
  int stage_v_138_2 = ((pub_r001970_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((sec_r001970_12_1 ^ 0x2A) * 2) + pub_r001970_8_1) & 127;
  int stage_v_139_2 = (((sec_r001970_12_2 ^ 0x2A) * 2) + pub_r001970_8_2) & 127;
  if (stage_v_139_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001970_11_1) & 127;
  int stage_v_140_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001970_11_2) & 127;
  if (stage_v_140_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((stage_v_112_1 ^ 0x2A) * 2) + pub_r001970_2_1) & 127;
  int stage_v_141_2 = (((stage_v_112_2 ^ 0x2A) * 2) + pub_r001970_2_2) & 127;
  if (stage_v_141_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001970_2_1) & 127;
  int stage_v_142_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001970_2_2) & 127;
  if (stage_v_142_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001970_9_1) & 127;
  int stage_v_143_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001970_9_2) & 127;
  if (stage_v_143_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001970_1_1) & 127;
  int stage_v_144_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001970_1_2) & 127;
  if (stage_v_144_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001970_0_1) & 127;
  int stage_v_145_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001970_0_2) & 127;
  if (stage_v_145_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001970_5_1) & 127;
  int stage_v_146_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001970_5_2) & 127;
  if (stage_v_146_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001970_1_1) & 127;
  int stage_v_147_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001970_1_2) & 127;
  if (stage_v_147_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = (((helper_flow_12_1 ^ 0x2A) * 2) + pub_r001970_7_1) & 127;
  int stage_v_148_2 = (((helper_flow_12_2 ^ 0x2A) * 2) + pub_r001970_7_2) & 127;
  if (stage_v_148_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001970_2_1) & 127;
  int stage_v_149_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001970_2_2) & 127;
  if (stage_v_149_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((sec_r001970_14_1 ^ 0x2A) * 2) + pub_r001970_11_1) & 127;
  int stage_v_150_2 = (((sec_r001970_14_2 ^ 0x2A) * 2) + pub_r001970_11_2) & 127;
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
  int stage_v_151_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001970_5_1) & 127;
  int stage_v_151_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001970_5_2) & 127;
  if (stage_v_151_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001970_6_1) & 127;
  int stage_v_152_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001970_6_2) & 127;
  if (stage_v_152_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001970_10_1) & 127;
  int stage_v_153_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001970_10_2) & 127;
  if (stage_v_153_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (((sec_r001970_17_1 ^ 0x2A) * 2) + pub_r001970_6_1) & 127;
  int stage_v_154_2 = (((sec_r001970_17_2 ^ 0x2A) * 2) + pub_r001970_6_2) & 127;
  if (stage_v_154_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((stage_v_152_1 ^ 0x2A) * 2) + pub_r001970_6_1) & 127;
  int stage_v_155_2 = (((stage_v_152_2 ^ 0x2A) * 2) + pub_r001970_6_2) & 127;
  if (stage_v_155_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001970_7_1) & 127;
  int stage_v_156_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001970_7_2) & 127;
  if (stage_v_156_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001970_5_1) & 127;
  int stage_v_157_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001970_5_2) & 127;
  if (stage_v_157_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001970_11_1) & 127;
  int stage_v_158_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001970_11_2) & 127;
  if (stage_v_158_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((stage_v_76_1 ^ 0x2A) * 2) + pub_r001970_8_1) & 127;
  int stage_v_159_2 = (((stage_v_76_2 ^ 0x2A) * 2) + pub_r001970_8_2) & 127;
  if (stage_v_159_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((pub_r001970_14_1 * 2) + 37) & 63;
  int stage_v_160_2 = ((pub_r001970_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_130_1 ^ 0x2A) * 2) + pub_r001970_3_1) & 127;
  int stage_v_161_2 = (((stage_v_130_2 ^ 0x2A) * 2) + pub_r001970_3_2) & 127;
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
  int stage_v_162_1 = (((sec_r001970_15_1 ^ 0x2A) * 2) + pub_r001970_13_1) & 127;
  int stage_v_162_2 = (((sec_r001970_15_2 ^ 0x2A) * 2) + pub_r001970_13_2) & 127;
  if (stage_v_162_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((sec_r001970_14_1 ^ 0x2A) * 2) + pub_r001970_11_1) & 127;
  int stage_v_163_2 = (((sec_r001970_14_2 ^ 0x2A) * 2) + pub_r001970_11_2) & 127;
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
  int stage_v_164_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001970_6_1) & 127;
  int stage_v_164_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001970_6_2) & 127;
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
  int stage_v_165_1 = ((pub_r001970_3_1 * 2) + 17) & 63;
  int stage_v_165_2 = ((pub_r001970_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((stage_v_148_1 ^ 0x2A) * 2) + pub_r001970_1_1) & 127;
  int stage_v_166_2 = (((stage_v_148_2 ^ 0x2A) * 2) + pub_r001970_1_2) & 127;
  if (stage_v_166_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((sec_r001970_12_1 ^ 0x2A) * 2) + pub_r001970_0_1) & 127;
  int stage_v_167_2 = (((sec_r001970_12_2 ^ 0x2A) * 2) + pub_r001970_0_2) & 127;
  if (stage_v_167_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_154_1 ^ 0x2A) * 2) + pub_r001970_4_1) & 127;
  int stage_v_168_2 = (((stage_v_154_2 ^ 0x2A) * 2) + pub_r001970_4_2) & 127;
  if (stage_v_168_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((stage_v_166_1 ^ 0x2A) * 2) + pub_r001970_10_1) & 127;
  int stage_v_169_2 = (((stage_v_166_2 ^ 0x2A) * 2) + pub_r001970_10_2) & 127;
  if (stage_v_169_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((sec_r001970_6_1 ^ 0x2A) * 2) + pub_r001970_9_1) & 127;
  int stage_v_170_2 = (((sec_r001970_6_2 ^ 0x2A) * 2) + pub_r001970_9_2) & 127;
  if (stage_v_170_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((pub_r001970_11_1 * 2) + 11) & 63;
  int stage_v_171_2 = ((pub_r001970_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((sec_r001970_13_1 ^ 0x2A) * 2) + pub_r001970_11_1) & 127;
  int stage_v_172_2 = (((sec_r001970_13_2 ^ 0x2A) * 2) + pub_r001970_11_2) & 127;
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
  int stage_v_173_1 = (((sec_r001970_8_1 ^ 0x2A) * 2) + pub_r001970_1_1) & 127;
  int stage_v_173_2 = (((sec_r001970_8_2 ^ 0x2A) * 2) + pub_r001970_1_2) & 127;
  if (stage_v_173_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((stage_v_156_1 ^ 0x2A) * 2) + pub_r001970_0_1) & 127;
  int stage_v_174_2 = (((stage_v_156_2 ^ 0x2A) * 2) + pub_r001970_0_2) & 127;
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
  int stage_v_175_1 = ((pub_r001970_10_1 * 2) + 38) & 63;
  int stage_v_175_2 = ((pub_r001970_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_69_1 ^ 0x2A) * 2) + pub_r001970_11_1) & 127;
  int stage_v_176_2 = (((stage_v_69_2 ^ 0x2A) * 2) + pub_r001970_11_2) & 127;
  if (stage_v_176_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((pub_r001970_14_1 * 2) + 18) & 63;
  int stage_v_177_2 = ((pub_r001970_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((sec_r001970_7_1 ^ 0x2A) * 2) + pub_r001970_15_1) & 127;
  int stage_v_178_2 = (((sec_r001970_7_2 ^ 0x2A) * 2) + pub_r001970_15_2) & 127;
  if (stage_v_178_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001970_0_1) & 127;
  int stage_v_179_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001970_0_2) & 127;
  if (stage_v_179_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((pub_r001970_14_1 * 2) + 13) & 63;
  int stage_v_180_2 = ((pub_r001970_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((sec_r001970_17_1 ^ 0x2A) * 2) + pub_r001970_1_1) & 127;
  int stage_v_181_2 = (((sec_r001970_17_2 ^ 0x2A) * 2) + pub_r001970_1_2) & 127;
  if (stage_v_181_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((pub_r001970_0_1 * 2) + 18) & 63;
  int stage_v_182_2 = ((pub_r001970_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001970_11_1 * 2) + 25) & 63;
  int stage_v_183_2 = ((pub_r001970_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001970_12_1 * 2) + 16) & 63;
  int stage_v_184_2 = ((pub_r001970_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001970_1_1 * 2) + 31) & 63;
  int stage_v_185_2 = ((pub_r001970_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_154_1 ^ 0x2A) * 2) + pub_r001970_5_1) & 127;
  int stage_v_186_2 = (((stage_v_154_2 ^ 0x2A) * 2) + pub_r001970_5_2) & 127;
  if (stage_v_186_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((pub_r001970_1_1 * 2) + 13) & 63;
  int stage_v_187_2 = ((pub_r001970_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001970_8_1) & 127;
  int stage_v_188_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001970_8_2) & 127;
  if (stage_v_188_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((stage_v_181_1 ^ 0x2A) * 2) + pub_r001970_14_1) & 127;
  int stage_v_189_2 = (((stage_v_181_2 ^ 0x2A) * 2) + pub_r001970_14_2) & 127;
  if (stage_v_189_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001970_2_1) & 127;
  int stage_v_190_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001970_2_2) & 127;
  if (stage_v_190_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001970_10_1) & 127;
  int stage_v_191_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001970_10_2) & 127;
  if (stage_v_191_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((pub_r001970_6_1 * 2) + 22) & 63;
  int stage_v_192_2 = ((pub_r001970_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001970_12_1) & 127;
  int stage_v_193_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001970_12_2) & 127;
  if (stage_v_193_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_149_1 ^ 0x2A) * 2) + pub_r001970_12_1) & 127;
  int stage_v_194_2 = (((stage_v_149_2 ^ 0x2A) * 2) + pub_r001970_12_2) & 127;
  if (stage_v_194_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((stage_v_130_1 ^ 0x2A) * 2) + pub_r001970_6_1) & 127;
  int stage_v_195_2 = (((stage_v_130_2 ^ 0x2A) * 2) + pub_r001970_6_2) & 127;
  if (stage_v_195_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((pub_r001970_7_1 * 2) + 39) & 63;
  int stage_v_196_2 = ((pub_r001970_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((stage_v_194_1 ^ 0x2A) * 2) + pub_r001970_0_1) & 127;
  int stage_v_197_2 = (((stage_v_194_2 ^ 0x2A) * 2) + pub_r001970_0_2) & 127;
  if (stage_v_197_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((pub_r001970_14_1 * 2) + 5) & 63;
  int stage_v_198_2 = ((pub_r001970_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001970_1_1 * 2) + 24) & 63;
  int stage_v_199_2 = ((pub_r001970_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001970_9_1) & 127;
  int stage_v_200_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001970_9_2) & 127;
  if (stage_v_200_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001970_0_1) & 127;
  int stage_v_201_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001970_0_2) & 127;
  if (stage_v_201_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001970_1_1) & 127;
  int stage_v_202_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001970_1_2) & 127;
  if (stage_v_202_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001970_2_1) & 127;
  int stage_v_203_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001970_2_2) & 127;
  if (stage_v_203_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001970_13_1) & 127;
  int stage_v_204_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001970_13_2) & 127;
  if (stage_v_204_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = (((stage_v_190_1 ^ 0x2A) * 2) + pub_r001970_8_1) & 127;
  int stage_v_205_2 = (((stage_v_190_2 ^ 0x2A) * 2) + pub_r001970_8_2) & 127;
  if (stage_v_205_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001970_12_1) & 127;
  int stage_v_206_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001970_12_2) & 127;
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
  int stage_v_207_1 = (((stage_v_161_1 ^ 0x2A) * 2) + pub_r001970_6_1) & 127;
  int stage_v_207_2 = (((stage_v_161_2 ^ 0x2A) * 2) + pub_r001970_6_2) & 127;
  if (stage_v_207_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((pub_r001970_11_1 * 2) + 49) & 63;
  int stage_v_208_2 = ((pub_r001970_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001970_4_1 * 2) + 24) & 63;
  int stage_v_209_2 = ((pub_r001970_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001970_3_1 * 2) + 41) & 63;
  int stage_v_210_2 = ((pub_r001970_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001970_9_1) & 127;
  int stage_v_211_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001970_9_2) & 127;
  if (stage_v_211_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((pub_r001970_4_1 * 2) + 19) & 63;
  int stage_v_212_2 = ((pub_r001970_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001970_12_1 * 2) + 43) & 63;
  int stage_v_213_2 = ((pub_r001970_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (((stage_v_205_1 ^ 0x2A) * 2) + pub_r001970_14_1) & 127;
  int stage_v_214_2 = (((stage_v_205_2 ^ 0x2A) * 2) + pub_r001970_14_2) & 127;
  if (stage_v_214_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((pub_r001970_2_1 * 2) + 18) & 63;
  int stage_v_215_2 = ((pub_r001970_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001970_1_1 * 2) + 26) & 63;
  int stage_v_216_2 = ((pub_r001970_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001970_1_1) & 127;
  int stage_v_217_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001970_1_2) & 127;
  if (stage_v_217_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((stage_v_153_1 ^ 0x2A) * 2) + pub_r001970_11_1) & 127;
  int stage_v_218_2 = (((stage_v_153_2 ^ 0x2A) * 2) + pub_r001970_11_2) & 127;
  if (stage_v_218_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = (((stage_v_162_1 ^ 0x2A) * 2) + pub_r001970_11_1) & 127;
  int stage_v_219_2 = (((stage_v_162_2 ^ 0x2A) * 2) + pub_r001970_11_2) & 127;
  if (stage_v_219_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001970_10_1) & 127;
  int stage_v_220_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001970_10_2) & 127;
  if (stage_v_220_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
  }
  if (stage_v_220_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = (((stage_v_194_1 ^ 0x2A) * 2) + pub_r001970_7_1) & 127;
  int stage_v_221_2 = (((stage_v_194_2 ^ 0x2A) * 2) + pub_r001970_7_2) & 127;
  if (stage_v_221_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001970_15_1) & 127;
  int stage_v_222_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001970_15_2) & 127;
  if (stage_v_222_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001970_0_1) & 127;
  int stage_v_223_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001970_0_2) & 127;
  if (stage_v_223_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001970_4_1) & 127;
  int stage_v_224_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001970_4_2) & 127;
  if (stage_v_224_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
  }
  if (stage_v_224_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((pub_r001970_9_1 * 2) + 45) & 63;
  int stage_v_225_2 = ((pub_r001970_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001970_1_1 == pub_r001970_1_2);
  __CPROVER_assume(sec_r001970_8_1 != sec_r001970_8_2);
  __CPROVER_assume(sec_r001970_12_1 != sec_r001970_12_2);
  __CPROVER_assume(pub_r001970_2_1 == pub_r001970_2_2);
  __CPROVER_assume(pub_r001970_15_1 == pub_r001970_15_2);
  __CPROVER_assume(pub_r001970_0_1 == pub_r001970_0_2);
  __CPROVER_assume(sec_r001970_14_1 != sec_r001970_14_2);
  __CPROVER_assume(sec_r001970_10_1 != sec_r001970_10_2);
  __CPROVER_assume(pub_r001970_9_1 == pub_r001970_9_2);
  __CPROVER_assume(pub_r001970_7_1 == pub_r001970_7_2);
  __CPROVER_assume(sec_r001970_7_1 != sec_r001970_7_2);
  __CPROVER_assume(pub_r001970_4_1 == pub_r001970_4_2);
  __CPROVER_assume(pub_r001970_10_1 == pub_r001970_10_2);
  __CPROVER_assume(pub_r001970_14_1 == pub_r001970_14_2);
  __CPROVER_assume(sec_r001970_6_1 != sec_r001970_6_2);
  __CPROVER_assume(sec_r001970_1_1 != sec_r001970_1_2);
  __CPROVER_assume(sec_r001970_2_1 != sec_r001970_2_2);
  __CPROVER_assume(sec_r001970_5_1 != sec_r001970_5_2);
  __CPROVER_assume(sec_r001970_0_1 != sec_r001970_0_2);
  __CPROVER_assume(sec_r001970_16_1 != sec_r001970_16_2);
  __CPROVER_assume(sec_r001970_17_1 != sec_r001970_17_2);
  __CPROVER_assume(pub_r001970_12_1 == pub_r001970_12_2);
  __CPROVER_assume(pub_r001970_13_1 == pub_r001970_13_2);
  __CPROVER_assume(pub_r001970_3_1 == pub_r001970_3_2);
  __CPROVER_assume(sec_r001970_13_1 != sec_r001970_13_2);
  __CPROVER_assume(sec_r001970_11_1 != sec_r001970_11_2);
  __CPROVER_assume(sec_r001970_9_1 != sec_r001970_9_2);
  __CPROVER_assume(sec_r001970_3_1 != sec_r001970_3_2);
  __CPROVER_assume(sec_r001970_4_1 != sec_r001970_4_2);
  __CPROVER_assume(pub_r001970_6_1 == pub_r001970_6_2);
  __CPROVER_assume(sec_r001970_15_1 != sec_r001970_15_2);
  __CPROVER_assume(pub_r001970_5_1 == pub_r001970_5_2);
  __CPROVER_assume(pub_r001970_8_1 == pub_r001970_8_2);
  __CPROVER_assume(pub_r001970_11_1 == pub_r001970_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.round_key == st_var_2_2.round_key);
  assert(st_var_2_1.tag == st_var_2_2.tag);
  assert(st_var_2_1.flags == st_var_2_2.flags);
  assert(st_var_2_1.counter == st_var_2_2.counter);
  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.nonce == st_var_2_2.nonce);
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
  assert(helper_flow_10_1 == helper_flow_10_2);
  assert(helper_flow_11_1 == helper_flow_11_2);
  assert(helper_flow_12_1 == helper_flow_12_2);
  assert(helper_flow_13_1 == helper_flow_13_2);
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
}


