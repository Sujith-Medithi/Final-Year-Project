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
struct CipherContext_R000205_513_0
{
  int tag;
  short nonce;
  int round_key;
  int flags;
  int counter;
  int buffer[3];
};
struct MatrixBlock_R000205_513_1
{
  int determinant;
  short density;
  int stride;
  int trace;
  int buffer[3];
};
union RegisterBank_R000205_513_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000205_513_1
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
void fn_R000205_513_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st_1 = {0};
  struct MatrixBlock_R000205_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_20_1) & 63;
  aux_2 = (aux_2 + vector_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_71_1 > 25)
  {
    acc_1 = ((acc_1 + (tally_71_1 * 2)) + 5) & 127;
    aux_1 ^= tally_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_71_2 > 25)
  {
    acc_2 = ((acc_2 + (tally_71_2 * 2)) + 5) & 127;
    aux_2 ^= tally_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_26_1)
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

  switch (anchor_26_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_20_1 == vector_20_2);
  assert(tally_71_1 == tally_71_2);
  assert(anchor_26_1 == anchor_26_2);
}

int fn_R000205_513_0(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_20) & 63;
  acc ^= aux;
  int tally_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_71 > 25)
  {
    acc = ((acc + (tally_71 * 2)) + 5) & 127;
    aux ^= tally_71 & 15;
  }
  else
  {
    acc = ((acc - tally_71) + 11) & 127;
    aux += 3;
  }
  int anchor_26 = (aux + st.buffer[1]) & 3;
  switch (anchor_26)
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

void fn_R000205_513_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st_1 = {0};
  struct MatrixBlock_R000205_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_43_1)
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

  switch (parity_43_2)
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

  int quantum_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_21_1) & 63;
  aux_2 = (aux_2 + quantum_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_43_1 == parity_43_2);
  assert(quantum_21_1 == quantum_21_2);
}

int fn_R000205_513_1(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_43 = (aux + st.buffer[1]) & 3;
  switch (parity_43)
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

  int quantum_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000205_513_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st_1 = {0};
  struct CipherContext_R000205_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int delta_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_85_1 > 44)
  {
    acc_1 = ((acc_1 + (delta_85_1 * 2)) + 5) & 127;
    aux_1 ^= delta_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_85_2 > 44)
  {
    acc_2 = ((acc_2 + (delta_85_2 * 2)) + 5) & 127;
    aux_2 ^= delta_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_85_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_96_1 = local_arr_1[aux_1 % 3];
  int cursor_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_96_2 * 2)) & 127;
  int phase_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_20_1)
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

  switch (phase_20_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_85_1 == delta_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_96_1 == cursor_96_2);
  assert(phase_20_1 == phase_20_2);
}

int fn_R000205_513_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int delta_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_85 > 44)
  {
    acc = ((acc + (delta_85 * 2)) + 5) & 127;
    aux ^= delta_85 & 15;
  }
  else
  {
    acc = ((acc - delta_85) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int cursor_96 = local_arr[aux % 3];
  acc = (acc + (cursor_96 * 2)) & 127;
  int phase_20 = (aux + st.buffer[1]) & 3;
  switch (phase_20)
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

void fn_R000205_513_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st_1 = {0};
  struct CipherContext_R000205_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_78_1 = local_arr_1[aux_1 % 3];
  int anchor_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_78_2 * 2)) & 127;
  int quotient_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_51_1 > 10)
  {
    acc_1 = ((acc_1 + (quotient_51_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_51_2 > 10)
  {
    acc_2 = ((acc_2 + (quotient_51_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_77_1) & 63;
  aux_2 = (aux_2 + vector_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_78_1 == anchor_78_2);
  assert(quotient_51_1 == quotient_51_2);
  assert(vector_77_1 == vector_77_2);
}

int fn_R000205_513_3(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_78 = local_arr[aux % 3];
  acc = (acc + (anchor_78 * 2)) & 127;
  int quotient_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_51 > 10)
  {
    acc = ((acc + (quotient_51 * 2)) + 5) & 127;
    aux ^= quotient_51 & 15;
  }
  else
  {
    acc = ((acc - quotient_51) + 11) & 127;
    aux += 3;
  }
  int vector_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_77) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000205_513_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st_1 = {0};
  struct MatrixBlock_R000205_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int vector_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_31_1) & 63;
  aux_2 = (aux_2 + vector_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_21_1)
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

  switch (factor_21_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_31_1 == vector_31_2);
  assert(factor_21_1 == factor_21_2);
}

int fn_R000205_513_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int vector_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_31) & 63;
  acc ^= aux;
  int factor_21 = (aux + st.buffer[1]) & 3;
  switch (factor_21)
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

void fn_R000205_513_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st_1 = {0};
  struct MatrixBlock_R000205_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int margin_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_59_1) & 63;
  aux_2 = (aux_2 + margin_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_36_1)
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

  switch (delta_36_2)
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
  int tracker_71_1 = local_arr_1[aux_1 % 3];
  int tracker_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_71_2 * 2)) & 127;
  int scale_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_98_1 > 25)
  {
    acc_1 = ((acc_1 + (scale_98_1 * 2)) + 5) & 127;
    aux_1 ^= scale_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_98_2 > 25)
  {
    acc_2 = ((acc_2 + (scale_98_2 * 2)) + 5) & 127;
    aux_2 ^= scale_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_59_1 == margin_59_2);
  assert(delta_36_1 == delta_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_71_1 == tracker_71_2);
  assert(scale_98_1 == scale_98_2);
}

int fn_R000205_513_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int margin_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_59) & 63;
  acc ^= aux;
  int delta_36 = (aux + st.buffer[1]) & 3;
  switch (delta_36)
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
  int tracker_71 = local_arr[aux % 3];
  acc = (acc + (tracker_71 * 2)) & 127;
  int scale_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_98 > 25)
  {
    acc = ((acc + (scale_98 * 2)) + 5) & 127;
    aux ^= scale_98 & 15;
  }
  else
  {
    acc = ((acc - scale_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000205_513_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st_1 = {0};
  struct CipherContext_R000205_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
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

  int margin_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_35_1 > 34)
  {
    acc_1 = ((acc_1 + (margin_35_1 * 2)) + 5) & 127;
    aux_1 ^= margin_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_35_2 > 34)
  {
    acc_2 = ((acc_2 + (margin_35_2 * 2)) + 5) & 127;
    aux_2 ^= margin_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_87_1 = local_arr_1[aux_1 % 3];
  int mask_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_87_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_59_1 == damping_59_2);
  assert(margin_35_1 == margin_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_87_1 == mask_87_2);
}

int fn_R000205_513_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
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

  int margin_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_35 > 34)
  {
    acc = ((acc + (margin_35 * 2)) + 5) & 127;
    aux ^= margin_35 & 15;
  }
  else
  {
    acc = ((acc - margin_35) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_87 = local_arr[aux % 3];
  acc = (acc + (mask_87 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000205_513_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st_1 = {0};
  struct CipherContext_R000205_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_50_1 = local_arr_1[aux_1 % 3];
  int index_reg_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_50_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_47_1 > 15)
  {
    acc_1 = ((acc_1 + (window_47_1 * 2)) + 5) & 127;
    aux_1 ^= window_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_47_2 > 15)
  {
    acc_2 = ((acc_2 + (window_47_2 * 2)) + 5) & 127;
    aux_2 ^= window_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_47_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_50_1 == index_reg_50_2);
  assert(window_47_1 == window_47_2);
}

int fn_R000205_513_7(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int index_reg_50 = local_arr[aux % 3];
  acc = (acc + (index_reg_50 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_47 > 15)
  {
    acc = ((acc + (window_47 * 2)) + 5) & 127;
    aux ^= window_47 & 15;
  }
  else
  {
    acc = ((acc - window_47) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000205_513_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st_1 = {0};
  struct CipherContext_R000205_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_17_1 = local_arr_1[aux_1 % 3];
  int delta_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_17_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_41_1) & 63;
  aux_2 = (aux_2 + tracker_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_10_1 > 35)
  {
    acc_1 = ((acc_1 + (metric_10_1 * 2)) + 5) & 127;
    aux_1 ^= metric_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_10_2 > 35)
  {
    acc_2 = ((acc_2 + (metric_10_2 * 2)) + 5) & 127;
    aux_2 ^= metric_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_10_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_17_1 == delta_17_2);
  assert(tracker_41_1 == tracker_41_2);
  assert(metric_10_1 == metric_10_2);
}

int fn_R000205_513_8(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int delta_17 = local_arr[aux % 3];
  acc = (acc + (delta_17 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_41) & 63;
  acc ^= aux;
  int metric_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_10 > 35)
  {
    acc = ((acc + (metric_10 * 2)) + 5) & 127;
    aux ^= metric_10 & 15;
  }
  else
  {
    acc = ((acc - metric_10) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000205_513_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st_1 = {0};
  struct CipherContext_R000205_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int tracker_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_62_1)
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

  switch (tracker_62_2)
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
  int pivot_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_20_1 > 26)
  {
    acc_1 = ((acc_1 + (pivot_20_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_20_2 > 26)
  {
    acc_2 = ((acc_2 + (pivot_20_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_31_1) & 63;
  aux_2 = (aux_2 + tracker_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_62_1 == tracker_62_2);
  assert(pivot_20_1 == pivot_20_2);
  assert(tracker_31_1 == tracker_31_2);
}

int fn_R000205_513_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int tracker_62 = (aux + st.buffer[1]) & 3;
  switch (tracker_62)
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
  int pivot_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_20 > 26)
  {
    acc = ((acc + (pivot_20 * 2)) + 5) & 127;
    aux ^= pivot_20 & 15;
  }
  else
  {
    acc = ((acc - pivot_20) + 11) & 127;
    aux += 3;
  }
  int tracker_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000205_513_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st_1 = {0};
  struct MatrixBlock_R000205_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_86_1 = local_arr_1[aux_1 % 3];
  int checksum_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_86_2 * 2)) & 127;
  int stride_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_97_1 > 24)
  {
    acc_1 = ((acc_1 + (stride_97_1 * 2)) + 5) & 127;
    aux_1 ^= stride_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_97_2 > 24)
  {
    acc_2 = ((acc_2 + (stride_97_2 * 2)) + 5) & 127;
    aux_2 ^= stride_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_86_1 == checksum_86_2);
  assert(stride_97_1 == stride_97_2);
}

int fn_R000205_513_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int checksum_86 = local_arr[aux % 3];
  acc = (acc + (checksum_86 * 2)) & 127;
  int stride_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_97 > 24)
  {
    acc = ((acc + (stride_97 * 2)) + 5) & 127;
    aux ^= stride_97 & 15;
  }
  else
  {
    acc = ((acc - stride_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000205_513_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st_1 = {0};
  struct MatrixBlock_R000205_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int coefficient_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_37_1) & 63;
  aux_2 = (aux_2 + coefficient_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_36_1 = local_arr_1[aux_1 % 3];
  int scale_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_37_1 == coefficient_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_36_1 == scale_36_2);
}

int fn_R000205_513_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int coefficient_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_37) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_36 = local_arr[aux % 3];
  acc = (acc + (scale_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000205_513_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st_1 = {0};
  struct CipherContext_R000205_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_29_1 = local_arr_1[aux_1 % 3];
  int residue_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_29_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_29_1 == residue_29_2);
}

int fn_R000205_513_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int residue_29 = local_arr[aux % 3];
  acc = (acc + (residue_29 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000205_513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st_1 = {0};
  struct CipherContext_R000205_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int segment_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_91_1)
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

  switch (segment_91_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_46_1 = local_arr_1[aux_1 % 3];
  int segment_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_46_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_91_1 == segment_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_46_1 == segment_46_2);
}

int fn_R000205_513_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int segment_91 = (aux + st.buffer[1]) & 3;
  switch (segment_91)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int segment_46 = local_arr[aux % 3];
  acc = (acc + (segment_46 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000205_513_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st_1 = {0};
  struct MatrixBlock_R000205_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int cursor_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_56_1) & 63;
  aux_2 = (aux_2 + cursor_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_55_1 > 38)
  {
    acc_1 = ((acc_1 + (coefficient_55_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_55_2 > 38)
  {
    acc_2 = ((acc_2 + (coefficient_55_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_55_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_56_1 == cursor_56_2);
  assert(coefficient_55_1 == coefficient_55_2);
}

int fn_R000205_513_14(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int cursor_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_56) & 63;
  acc ^= aux;
  int coefficient_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_55 > 38)
  {
    acc = ((acc + (coefficient_55 * 2)) + 5) & 127;
    aux ^= coefficient_55 & 15;
  }
  else
  {
    acc = ((acc - coefficient_55) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000205_513_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st_1 = {0};
  struct CipherContext_R000205_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_89_1 = local_arr_1[aux_1 % 3];
  int checksum_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_89_2 * 2)) & 127;
  int accumulator_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_58_1) & 63;
  aux_2 = (aux_2 + accumulator_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_89_1 == checksum_89_2);
  assert(accumulator_58_1 == accumulator_58_2);
}

int fn_R000205_513_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int checksum_89 = local_arr[aux % 3];
  acc = (acc + (checksum_89 * 2)) & 127;
  int accumulator_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_58) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000205_513_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st_1 = {0};
  struct MatrixBlock_R000205_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int quotient_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_65_1 > 45)
  {
    acc_1 = ((acc_1 + (quotient_65_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_65_2 > 45)
  {
    acc_2 = ((acc_2 + (quotient_65_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_53_1)
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

  switch (factor_53_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_65_1 == quotient_65_2);
  assert(factor_53_1 == factor_53_2);
}

int fn_R000205_513_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quotient_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_65 > 45)
  {
    acc = ((acc + (quotient_65 * 2)) + 5) & 127;
    aux ^= quotient_65 & 15;
  }
  else
  {
    acc = ((acc - quotient_65) + 11) & 127;
    aux += 3;
  }
  int factor_53 = (aux + st.buffer[1]) & 3;
  switch (factor_53)
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

void fn_R000205_513_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st_1 = {0};
  struct CipherContext_R000205_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_25_1) & 63;
  aux_2 = (aux_2 + coefficient_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_52_1)
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

  switch (tracker_52_2)
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
  int accumulator_20_1 = local_arr_1[aux_1 % 3];
  int accumulator_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_20_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_25_1 == coefficient_25_2);
  assert(tracker_52_1 == tracker_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_20_1 == accumulator_20_2);
}

int fn_R000205_513_17(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_25) & 63;
  acc ^= aux;
  int tracker_52 = (aux + st.buffer[1]) & 3;
  switch (tracker_52)
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
  int accumulator_20 = local_arr[aux % 3];
  acc = (acc + (accumulator_20 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000205_513_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st_1 = {0};
  struct MatrixBlock_R000205_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_24_1 > 27)
  {
    acc_1 = ((acc_1 + (parity_24_1 * 2)) + 5) & 127;
    aux_1 ^= parity_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_24_2 > 27)
  {
    acc_2 = ((acc_2 + (parity_24_2 * 2)) + 5) & 127;
    aux_2 ^= parity_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_73_1) & 63;
  aux_2 = (aux_2 + stride_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_24_1 == parity_24_2);
  assert(stride_73_1 == stride_73_2);
}

int fn_R000205_513_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_24 > 27)
  {
    acc = ((acc + (parity_24 * 2)) + 5) & 127;
    aux ^= parity_24 & 15;
  }
  else
  {
    acc = ((acc - parity_24) + 11) & 127;
    aux += 3;
  }
  int stride_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_73) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000205_513_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st_1 = {0};
  struct CipherContext_R000205_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int stride_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_27_1 > 27)
  {
    acc_1 = ((acc_1 + (stride_27_1 * 2)) + 5) & 127;
    aux_1 ^= stride_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_27_2 > 27)
  {
    acc_2 = ((acc_2 + (stride_27_2 * 2)) + 5) & 127;
    aux_2 ^= stride_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_17_1)
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

  switch (damping_17_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_27_1 == stride_27_2);
  assert(damping_17_1 == damping_17_2);
}

int fn_R000205_513_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int stride_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_27 > 27)
  {
    acc = ((acc + (stride_27 * 2)) + 5) & 127;
    aux ^= stride_27 & 15;
  }
  else
  {
    acc = ((acc - stride_27) + 11) & 127;
    aux += 3;
  }
  int damping_17 = (aux + st.buffer[1]) & 3;
  switch (damping_17)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000205_513_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st_1 = {0};
  struct MatrixBlock_R000205_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int coefficient_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_17_1)
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

  switch (coefficient_17_2)
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

  int checksum_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_27_1) & 63;
  aux_2 = (aux_2 + checksum_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_17_1 == coefficient_17_2);
  assert(checksum_27_1 == checksum_27_2);
}

int fn_R000205_513_20(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int coefficient_17 = (aux + st.buffer[1]) & 3;
  switch (coefficient_17)
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

  int checksum_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_27) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000205_513_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st_1 = {0};
  struct CipherContext_R000205_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int quantum_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_15_1 > 32)
  {
    acc_1 = ((acc_1 + (quantum_15_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_15_2 > 32)
  {
    acc_2 = ((acc_2 + (quantum_15_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_15_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_98_1 = local_arr_1[aux_1 % 3];
  int threshold_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_98_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_15_1 == quantum_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_98_1 == threshold_98_2);
}

int fn_R000205_513_21(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int quantum_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_15 > 32)
  {
    acc = ((acc + (quantum_15 * 2)) + 5) & 127;
    aux ^= quantum_15 & 15;
  }
  else
  {
    acc = ((acc - quantum_15) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_98 = local_arr[aux % 3];
  acc = (acc + (threshold_98 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000205_513_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st_1 = {0};
  struct MatrixBlock_R000205_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int threshold_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_74_1 > 28)
  {
    acc_1 = ((acc_1 + (threshold_74_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_74_2 > 28)
  {
    acc_2 = ((acc_2 + (threshold_74_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_10_1) & 63;
  aux_2 = (aux_2 + metric_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_52_1 = local_arr_1[aux_1 % 3];
  int tally_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_74_1 == threshold_74_2);
  assert(metric_10_1 == metric_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_52_1 == tally_52_2);
}

int fn_R000205_513_22(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int threshold_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_74 > 28)
  {
    acc = ((acc + (threshold_74 * 2)) + 5) & 127;
    aux ^= threshold_74 & 15;
  }
  else
  {
    acc = ((acc - threshold_74) + 11) & 127;
    aux += 3;
  }
  int metric_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_10) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_52 = local_arr[aux % 3];
  acc = (acc + (tally_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000205_0_1;
  int sec_r000205_0_2;
  int sec_r000205_1_1;
  int sec_r000205_1_2;
  int sec_r000205_2_1;
  int sec_r000205_2_2;
  int sec_r000205_3_1;
  int sec_r000205_3_2;
  int sec_r000205_4_1;
  int sec_r000205_4_2;
  int sec_r000205_5_1;
  int sec_r000205_5_2;
  int sec_r000205_6_1;
  int sec_r000205_6_2;
  int sec_r000205_7_1;
  int sec_r000205_7_2;
  int sec_r000205_8_1;
  int sec_r000205_8_2;
  int sec_r000205_9_1;
  int sec_r000205_9_2;
  int sec_r000205_10_1;
  int sec_r000205_10_2;
  int sec_r000205_11_1;
  int sec_r000205_11_2;
  int sec_r000205_12_1;
  int sec_r000205_12_2;
  int sec_r000205_13_1;
  int sec_r000205_13_2;
  int sec_r000205_14_1;
  int sec_r000205_14_2;
  int sec_r000205_15_1;
  int sec_r000205_15_2;
  int sec_r000205_16_1;
  int sec_r000205_16_2;
  int sec_r000205_17_1;
  int sec_r000205_17_2;
  int sec_r000205_18_1;
  int sec_r000205_18_2;
  int sec_r000205_19_1;
  int sec_r000205_19_2;
  int sec_r000205_20_1;
  int sec_r000205_20_2;
  int sec_r000205_21_1;
  int sec_r000205_21_2;
  int sec_r000205_22_1;
  int sec_r000205_22_2;
  int sec_r000205_23_1;
  int sec_r000205_23_2;
  int pub_r000205_0_1;
  int pub_r000205_0_2;
  int pub_r000205_1_1;
  int pub_r000205_1_2;
  int pub_r000205_2_1;
  int pub_r000205_2_2;
  int pub_r000205_3_1;
  int pub_r000205_3_2;
  int pub_r000205_4_1;
  int pub_r000205_4_2;
  int pub_r000205_5_1;
  int pub_r000205_5_2;
  int pub_r000205_6_1;
  int pub_r000205_6_2;
  int pub_r000205_7_1;
  int pub_r000205_7_2;
  int pub_r000205_8_1;
  int pub_r000205_8_2;
  int pub_r000205_9_1;
  int pub_r000205_9_2;
  int pub_r000205_10_1;
  int pub_r000205_10_2;
  int pub_r000205_11_1;
  int pub_r000205_11_2;
  int pub_r000205_12_1;
  int pub_r000205_12_2;
  int pub_r000205_13_1;
  int pub_r000205_13_2;
  int pub_r000205_14_1;
  int pub_r000205_14_2;
  int pub_r000205_15_1;
  int pub_r000205_15_2;
  int pub_r000205_16_1;
  int pub_r000205_16_2;
  int pub_r000205_17_1;
  int pub_r000205_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000205_0_1 >= (-100)) && (pub_r000205_0_1 <= 100));
  __CPROVER_assume((pub_r000205_0_2 >= (-100)) && (pub_r000205_0_2 <= 100));
  __CPROVER_assume((pub_r000205_1_1 >= (-100)) && (pub_r000205_1_1 <= 100));
  __CPROVER_assume((pub_r000205_1_2 >= (-100)) && (pub_r000205_1_2 <= 100));
  __CPROVER_assume((pub_r000205_2_1 >= (-100)) && (pub_r000205_2_1 <= 100));
  __CPROVER_assume((pub_r000205_2_2 >= (-100)) && (pub_r000205_2_2 <= 100));
  __CPROVER_assume((pub_r000205_3_1 >= (-100)) && (pub_r000205_3_1 <= 100));
  __CPROVER_assume((pub_r000205_3_2 >= (-100)) && (pub_r000205_3_2 <= 100));
  __CPROVER_assume((pub_r000205_4_1 >= (-100)) && (pub_r000205_4_1 <= 100));
  __CPROVER_assume((pub_r000205_4_2 >= (-100)) && (pub_r000205_4_2 <= 100));
  __CPROVER_assume((pub_r000205_5_1 >= (-100)) && (pub_r000205_5_1 <= 100));
  __CPROVER_assume((pub_r000205_5_2 >= (-100)) && (pub_r000205_5_2 <= 100));
  __CPROVER_assume((pub_r000205_6_1 >= (-100)) && (pub_r000205_6_1 <= 100));
  __CPROVER_assume((pub_r000205_6_2 >= (-100)) && (pub_r000205_6_2 <= 100));
  __CPROVER_assume((pub_r000205_7_1 >= (-100)) && (pub_r000205_7_1 <= 100));
  __CPROVER_assume((pub_r000205_7_2 >= (-100)) && (pub_r000205_7_2 <= 100));
  __CPROVER_assume((pub_r000205_8_1 >= (-100)) && (pub_r000205_8_1 <= 100));
  __CPROVER_assume((pub_r000205_8_2 >= (-100)) && (pub_r000205_8_2 <= 100));
  __CPROVER_assume((pub_r000205_9_1 >= (-100)) && (pub_r000205_9_1 <= 100));
  __CPROVER_assume((pub_r000205_9_2 >= (-100)) && (pub_r000205_9_2 <= 100));
  __CPROVER_assume((pub_r000205_10_1 >= (-100)) && (pub_r000205_10_1 <= 100));
  __CPROVER_assume((pub_r000205_10_2 >= (-100)) && (pub_r000205_10_2 <= 100));
  __CPROVER_assume((pub_r000205_11_1 >= (-100)) && (pub_r000205_11_1 <= 100));
  __CPROVER_assume((pub_r000205_11_2 >= (-100)) && (pub_r000205_11_2 <= 100));
  __CPROVER_assume((pub_r000205_12_1 >= (-100)) && (pub_r000205_12_1 <= 100));
  __CPROVER_assume((pub_r000205_12_2 >= (-100)) && (pub_r000205_12_2 <= 100));
  __CPROVER_assume((pub_r000205_13_1 >= (-100)) && (pub_r000205_13_1 <= 100));
  __CPROVER_assume((pub_r000205_13_2 >= (-100)) && (pub_r000205_13_2 <= 100));
  __CPROVER_assume((pub_r000205_14_1 >= (-100)) && (pub_r000205_14_1 <= 100));
  __CPROVER_assume((pub_r000205_14_2 >= (-100)) && (pub_r000205_14_2 <= 100));
  __CPROVER_assume((pub_r000205_15_1 >= (-100)) && (pub_r000205_15_1 <= 100));
  __CPROVER_assume((pub_r000205_15_2 >= (-100)) && (pub_r000205_15_2 <= 100));
  __CPROVER_assume((pub_r000205_16_1 >= (-100)) && (pub_r000205_16_1 <= 100));
  __CPROVER_assume((pub_r000205_16_2 >= (-100)) && (pub_r000205_16_2 <= 100));
  __CPROVER_assume((pub_r000205_17_1 >= (-100)) && (pub_r000205_17_1 <= 100));
  __CPROVER_assume((pub_r000205_17_2 >= (-100)) && (pub_r000205_17_2 <= 100));
  __CPROVER_assume((sec_r000205_0_1 >= 0) && (sec_r000205_0_1 <= 255));
  __CPROVER_assume((sec_r000205_0_2 >= 0) && (sec_r000205_0_2 <= 255));
  __CPROVER_assume((sec_r000205_1_1 >= 0) && (sec_r000205_1_1 <= 255));
  __CPROVER_assume((sec_r000205_1_2 >= 0) && (sec_r000205_1_2 <= 255));
  __CPROVER_assume((sec_r000205_2_1 >= 0) && (sec_r000205_2_1 <= 255));
  __CPROVER_assume((sec_r000205_2_2 >= 0) && (sec_r000205_2_2 <= 255));
  __CPROVER_assume((sec_r000205_3_1 >= 0) && (sec_r000205_3_1 <= 255));
  __CPROVER_assume((sec_r000205_3_2 >= 0) && (sec_r000205_3_2 <= 255));
  __CPROVER_assume((sec_r000205_4_1 >= 0) && (sec_r000205_4_1 <= 255));
  __CPROVER_assume((sec_r000205_4_2 >= 0) && (sec_r000205_4_2 <= 255));
  __CPROVER_assume((sec_r000205_5_1 >= 0) && (sec_r000205_5_1 <= 255));
  __CPROVER_assume((sec_r000205_5_2 >= 0) && (sec_r000205_5_2 <= 255));
  __CPROVER_assume((sec_r000205_6_1 >= 0) && (sec_r000205_6_1 <= 255));
  __CPROVER_assume((sec_r000205_6_2 >= 0) && (sec_r000205_6_2 <= 255));
  __CPROVER_assume((sec_r000205_7_1 >= 0) && (sec_r000205_7_1 <= 255));
  __CPROVER_assume((sec_r000205_7_2 >= 0) && (sec_r000205_7_2 <= 255));
  __CPROVER_assume((sec_r000205_8_1 >= 0) && (sec_r000205_8_1 <= 255));
  __CPROVER_assume((sec_r000205_8_2 >= 0) && (sec_r000205_8_2 <= 255));
  __CPROVER_assume((sec_r000205_9_1 >= 0) && (sec_r000205_9_1 <= 255));
  __CPROVER_assume((sec_r000205_9_2 >= 0) && (sec_r000205_9_2 <= 255));
  __CPROVER_assume((sec_r000205_10_1 >= 0) && (sec_r000205_10_1 <= 255));
  __CPROVER_assume((sec_r000205_10_2 >= 0) && (sec_r000205_10_2 <= 255));
  __CPROVER_assume((sec_r000205_11_1 >= 0) && (sec_r000205_11_1 <= 255));
  __CPROVER_assume((sec_r000205_11_2 >= 0) && (sec_r000205_11_2 <= 255));
  __CPROVER_assume((sec_r000205_12_1 >= 0) && (sec_r000205_12_1 <= 255));
  __CPROVER_assume((sec_r000205_12_2 >= 0) && (sec_r000205_12_2 <= 255));
  __CPROVER_assume((sec_r000205_13_1 >= 0) && (sec_r000205_13_1 <= 255));
  __CPROVER_assume((sec_r000205_13_2 >= 0) && (sec_r000205_13_2 <= 255));
  __CPROVER_assume((sec_r000205_14_1 >= 0) && (sec_r000205_14_1 <= 255));
  __CPROVER_assume((sec_r000205_14_2 >= 0) && (sec_r000205_14_2 <= 255));
  __CPROVER_assume((sec_r000205_15_1 >= 0) && (sec_r000205_15_1 <= 255));
  __CPROVER_assume((sec_r000205_15_2 >= 0) && (sec_r000205_15_2 <= 255));
  __CPROVER_assume((sec_r000205_16_1 >= 0) && (sec_r000205_16_1 <= 255));
  __CPROVER_assume((sec_r000205_16_2 >= 0) && (sec_r000205_16_2 <= 255));
  __CPROVER_assume((sec_r000205_17_1 >= 0) && (sec_r000205_17_1 <= 255));
  __CPROVER_assume((sec_r000205_17_2 >= 0) && (sec_r000205_17_2 <= 255));
  __CPROVER_assume((sec_r000205_18_1 >= 0) && (sec_r000205_18_1 <= 255));
  __CPROVER_assume((sec_r000205_18_2 >= 0) && (sec_r000205_18_2 <= 255));
  __CPROVER_assume((sec_r000205_19_1 >= 0) && (sec_r000205_19_1 <= 255));
  __CPROVER_assume((sec_r000205_19_2 >= 0) && (sec_r000205_19_2 <= 255));
  __CPROVER_assume((sec_r000205_20_1 >= 0) && (sec_r000205_20_1 <= 255));
  __CPROVER_assume((sec_r000205_20_2 >= 0) && (sec_r000205_20_2 <= 255));
  __CPROVER_assume((sec_r000205_21_1 >= 0) && (sec_r000205_21_1 <= 255));
  __CPROVER_assume((sec_r000205_21_2 >= 0) && (sec_r000205_21_2 <= 255));
  __CPROVER_assume((sec_r000205_22_1 >= 0) && (sec_r000205_22_1 <= 255));
  __CPROVER_assume((sec_r000205_22_2 >= 0) && (sec_r000205_22_2 <= 255));
  __CPROVER_assume((sec_r000205_23_1 >= 0) && (sec_r000205_23_1 <= 255));
  __CPROVER_assume((sec_r000205_23_2 >= 0) && (sec_r000205_23_2 <= 255));
  struct CipherContext_R000205_513_0 st_var_0_1 = {0};
  struct CipherContext_R000205_513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000205_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000205_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000205_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000205_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000205_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000205_0_2 + 7) & 15;
  struct MatrixBlock_R000205_513_1 st_var_1_1 = {0};
  struct MatrixBlock_R000205_513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000205_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000205_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000205_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000205_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000205_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000205_0_2 + 9) & 15;
  union RegisterBank_R000205_513_0 u_var_1;
  union RegisterBank_R000205_513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 52)
    {
      chk_sum_1 ^= stage_v_4_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_4_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 52)
    {
      chk_sum_2 ^= stage_v_4_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = (st_var_0_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_0_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 11) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
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
  if (stage_v_13_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 25)
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
  if (stage_v_13_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 25)
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
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 16) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  int stage_v_17_1 = (st_var_1_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_1_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = (st_var_0_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_0_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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

  int stage_v_19_1 = ((st_var_1_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_1_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 41)
    {
      chk_sum_1 ^= stage_v_19_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_19_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 41)
    {
      chk_sum_2 ^= stage_v_19_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_22_1 = (st_var_0_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_0_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = (st_var_1_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_1_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 31) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 32) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= stage_v_31_1;
  chk_sum_2 ^= stage_v_31_2;
  int stage_v_32_1 = ((st_var_0_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_0_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 35)
    {
      chk_sum_1 ^= stage_v_32_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_32_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 35)
    {
      chk_sum_2 ^= stage_v_32_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_33_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_33_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_34_1 = ((st_var_0_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_0_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 31)
    {
      chk_sum_1 ^= stage_v_34_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_34_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 31)
    {
      chk_sum_2 ^= stage_v_34_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 44)
    {
      chk_sum_1 ^= stage_v_36_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_36_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 44)
    {
      chk_sum_2 ^= stage_v_36_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = table_1[2];
  int stage_v_38_2 = table_2[2];
  table_1[2] = (table_1[3] + 77) & 63;
  table_2[2] = (table_2[3] + 77) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_39_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 41) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (47 & 31);
  int stage_v_42_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (47 & 31);
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= (stage_v_42_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_42_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 44) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = table_1[3];
  int stage_v_47_2 = table_2[3];
  table_1[3] = (table_1[0] + 95) & 63;
  table_2[3] = (table_2[0] + 95) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (54 & 31);
  int stage_v_49_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (54 & 31);
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= (stage_v_49_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_49_2 << 1) & 127;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_50_1 = ((stage_v_50_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_50_2 = ((stage_v_50_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
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
  int stage_v_53_1 = ((st_var_1_1.buffer[2] * 2) + 166) & 63;
  int stage_v_53_2 = ((st_var_1_2.buffer[2] * 2) + 166) & 63;
  if (stage_v_53_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_53_1) - 5) & 255;
    if (stage_v_53_1 > 42)
    {
      chk_sum_1 ^= stage_v_53_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_53_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_53_2) - 5) & 255;
    if (stage_v_53_2 > 42)
    {
      chk_sum_2 ^= stage_v_53_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_54_1 = table_1[2];
  int stage_v_54_2 = table_2[2];
  table_1[2] = (table_1[3] + 109) & 63;
  table_2[2] = (table_2[3] + 109) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_55_1 = ((stage_v_55_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((st_var_0_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_0_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 31)
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
  if (stage_v_56_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 31)
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
  int stage_v_57_1 = ((st_var_1_1.buffer[0] * 2) + 178) & 63;
  int stage_v_57_2 = ((st_var_1_2.buffer[0] * 2) + 178) & 63;
  if (stage_v_57_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_57_1) - 5) & 255;
    if (stage_v_57_1 > 25)
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
  if (stage_v_57_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_57_2) - 5) & 255;
    if (stage_v_57_2 > 25)
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
  int stage_v_58_1 = ((st_var_0_1.buffer[1] * 2) + 181) & 63;
  int stage_v_58_2 = ((st_var_0_2.buffer[1] * 2) + 181) & 63;
  if (stage_v_58_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_58_1) - 5) & 255;
    if (stage_v_58_1 > 43)
    {
      chk_sum_1 ^= stage_v_58_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_58_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_58_2) - 5) & 255;
    if (stage_v_58_2 > 43)
    {
      chk_sum_2 ^= stage_v_58_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 60) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 60) & 15;
  int stage_v_59_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_59_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= stage_v_59_1;
  chk_sum_2 ^= stage_v_59_2;
  int stage_v_60_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (65 & 31);
  int stage_v_60_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (65 & 31);
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= (stage_v_60_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_60_2 << 1) & 127;
  int stage_v_61_1 = (((sec_r000205_4_1 << 2) ^ (sec_r000205_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_61_2 = (((sec_r000205_4_2 << 2) ^ (sec_r000205_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = (((stage_v_61_1 << 2) ^ (sec_r000205_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_62_2 = (((stage_v_61_2 << 2) ^ (sec_r000205_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = (((stage_v_62_1 << 1) ^ (sec_r000205_20_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_63_2 = (((stage_v_62_2 << 1) ^ (sec_r000205_20_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = (((stage_v_62_1 << 1) ^ (sec_r000205_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_64_2 = (((stage_v_62_2 << 1) ^ (sec_r000205_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_64_1 & 63;
  out_sink_2 ^= stage_v_64_2 & 63;
  int stage_v_65_1 = (((stage_v_62_1 << 1) ^ (sec_r000205_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_65_2 = (((stage_v_62_2 << 1) ^ (sec_r000205_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_65_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_65_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = (((stage_v_65_1 << 1) ^ (sec_r000205_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_66_2 = (((stage_v_65_2 << 1) ^ (sec_r000205_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_66_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_66_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = (((sec_r000205_18_1 << 1) ^ (sec_r000205_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_67_2 = (((sec_r000205_18_2 << 1) ^ (sec_r000205_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_67_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_67_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = (((sec_r000205_0_1 << 2) ^ (sec_r000205_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_68_2 = (((sec_r000205_0_2 << 2) ^ (sec_r000205_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_68_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_68_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_68_1 & 63;
  out_sink_2 ^= stage_v_68_2 & 63;
  int stage_v_69_1 = (((stage_v_64_1 << 1) ^ (sec_r000205_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_69_2 = (((stage_v_64_2 << 1) ^ (sec_r000205_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = (((stage_v_65_1 << 1) ^ (sec_r000205_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_70_2 = (((stage_v_65_2 << 1) ^ (sec_r000205_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = (((sec_r000205_21_1 << 2) ^ (sec_r000205_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_71_2 = (((sec_r000205_21_2 << 2) ^ (sec_r000205_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_71_1 & 63;
  out_sink_2 ^= stage_v_71_2 & 63;
  int stage_v_72_1 = (((stage_v_71_1 << 2) ^ (sec_r000205_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_72_2 = (((stage_v_71_2 << 2) ^ (sec_r000205_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = (((stage_v_72_1 << 1) ^ (sec_r000205_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_73_2 = (((stage_v_72_2 << 1) ^ (sec_r000205_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_73_1 & 63;
  out_sink_2 ^= stage_v_73_2 & 63;
  int stage_v_74_1 = (((sec_r000205_15_1 << 2) ^ (sec_r000205_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_74_2 = (((sec_r000205_15_2 << 2) ^ (sec_r000205_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_74_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_74_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_74_1 & 63;
  out_sink_2 ^= stage_v_74_2 & 63;
  int stage_v_75_1 = (((sec_r000205_12_1 << 1) ^ (sec_r000205_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_75_2 = (((sec_r000205_12_2 << 1) ^ (sec_r000205_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = (((stage_v_70_1 << 2) ^ (sec_r000205_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_76_2 = (((stage_v_70_2 << 2) ^ (sec_r000205_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_76_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_76_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = (((stage_v_68_1 << 1) ^ (sec_r000205_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_77_2 = (((stage_v_68_2 << 1) ^ (sec_r000205_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_77_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_77_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = (((stage_v_75_1 << 1) ^ (sec_r000205_22_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_78_2 = (((stage_v_75_2 << 1) ^ (sec_r000205_22_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_78_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_78_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_78_1 & 63;
  out_sink_2 ^= stage_v_78_2 & 63;
  int stage_v_79_1 = (((stage_v_61_1 << 1) ^ (sec_r000205_22_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_79_2 = (((stage_v_61_2 << 1) ^ (sec_r000205_22_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_79_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_79_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_79_1 & 63;
  out_sink_2 ^= stage_v_79_2 & 63;
  int stage_v_80_1 = (((sec_r000205_15_1 << 1) ^ (sec_r000205_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_80_2 = (((sec_r000205_15_2 << 1) ^ (sec_r000205_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_80_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_80_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = (((stage_v_80_1 << 2) ^ (sec_r000205_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_81_2 = (((stage_v_80_2 << 2) ^ (sec_r000205_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_81_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_81_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = (((stage_v_63_1 << 2) ^ (sec_r000205_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_82_2 = (((stage_v_63_2 << 2) ^ (sec_r000205_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_82_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_82_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = (((stage_v_75_1 << 1) ^ (sec_r000205_20_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_83_2 = (((stage_v_75_2 << 1) ^ (sec_r000205_20_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_83_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_83_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = (((stage_v_75_1 << 1) ^ (sec_r000205_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_84_2 = (((stage_v_75_2 << 1) ^ (sec_r000205_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = (((stage_v_75_1 << 1) ^ (sec_r000205_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_85_2 = (((stage_v_75_2 << 1) ^ (sec_r000205_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_85_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_85_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_85_1 & 63;
  out_sink_2 ^= stage_v_85_2 & 63;
  int stage_v_86_1 = (((stage_v_62_1 << 2) ^ (sec_r000205_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_86_2 = (((stage_v_62_2 << 2) ^ (sec_r000205_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = (((stage_v_76_1 << 1) ^ (sec_r000205_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_87_2 = (((stage_v_76_2 << 1) ^ (sec_r000205_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_87_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_87_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_87_1 & 63;
  out_sink_2 ^= stage_v_87_2 & 63;
  int stage_v_88_1 = (((stage_v_87_1 << 2) ^ (sec_r000205_20_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_88_2 = (((stage_v_87_2 << 2) ^ (sec_r000205_20_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_88_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_88_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_88_1 & 63;
  out_sink_2 ^= stage_v_88_2 & 63;
  int stage_v_89_1 = (((stage_v_76_1 << 2) ^ (sec_r000205_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_89_2 = (((stage_v_76_2 << 2) ^ (sec_r000205_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_89_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_89_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = (((sec_r000205_21_1 << 2) ^ (sec_r000205_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_90_2 = (((sec_r000205_21_2 << 2) ^ (sec_r000205_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_90_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_90_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_90_1 & 63;
  out_sink_2 ^= stage_v_90_2 & 63;
  int stage_v_91_1 = (((stage_v_69_1 << 1) ^ (sec_r000205_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_91_2 = (((stage_v_69_2 << 1) ^ (sec_r000205_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_91_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_91_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_91_1 & 63;
  out_sink_2 ^= stage_v_91_2 & 63;
  int stage_v_92_1 = (((sec_r000205_11_1 << 2) ^ (sec_r000205_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_92_2 = (((sec_r000205_11_2 << 2) ^ (sec_r000205_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_92_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_92_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = (((sec_r000205_3_1 << 2) ^ (sec_r000205_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_93_2 = (((sec_r000205_3_2 << 2) ^ (sec_r000205_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_93_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_93_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = (((sec_r000205_8_1 << 1) ^ (sec_r000205_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_94_2 = (((sec_r000205_8_2 << 1) ^ (sec_r000205_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_94_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_94_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = (((sec_r000205_3_1 << 2) ^ (sec_r000205_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_95_2 = (((sec_r000205_3_2 << 2) ^ (sec_r000205_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_95_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_95_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = (((sec_r000205_8_1 << 2) ^ (sec_r000205_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_96_2 = (((sec_r000205_8_2 << 2) ^ (sec_r000205_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_96_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_96_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = (((stage_v_86_1 << 1) ^ (sec_r000205_21_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_97_2 = (((stage_v_86_2 << 1) ^ (sec_r000205_21_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_97_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_97_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_97_1 & 63;
  out_sink_2 ^= stage_v_97_2 & 63;
  int stage_v_98_1 = (((stage_v_91_1 << 2) ^ (sec_r000205_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_98_2 = (((stage_v_91_2 << 2) ^ (sec_r000205_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_98_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_98_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = (((stage_v_77_1 << 1) ^ (sec_r000205_22_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_99_2 = (((stage_v_77_2 << 1) ^ (sec_r000205_22_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_99_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_99_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_99_1 & 63;
  out_sink_2 ^= stage_v_99_2 & 63;
  int stage_v_100_1 = (((sec_r000205_5_1 << 2) ^ (sec_r000205_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_100_2 = (((sec_r000205_5_2 << 2) ^ (sec_r000205_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_100_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_100_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = (((stage_v_67_1 << 1) ^ (sec_r000205_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_101_2 = (((stage_v_67_2 << 1) ^ (sec_r000205_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_101_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_101_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = (((sec_r000205_7_1 << 2) ^ (sec_r000205_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_102_2 = (((sec_r000205_7_2 << 2) ^ (sec_r000205_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_102_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_102_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = (((stage_v_71_1 << 2) ^ (sec_r000205_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_103_2 = (((stage_v_71_2 << 2) ^ (sec_r000205_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_103_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_103_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = (((stage_v_63_1 << 1) ^ (sec_r000205_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_104_2 = (((stage_v_63_2 << 1) ^ (sec_r000205_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_104_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_104_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = (((sec_r000205_11_1 << 1) ^ (sec_r000205_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_105_2 = (((sec_r000205_11_2 << 1) ^ (sec_r000205_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_105_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_105_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_105_1 & 63;
  out_sink_2 ^= stage_v_105_2 & 63;
  int stage_v_106_1 = (((stage_v_97_1 << 1) ^ (sec_r000205_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_106_2 = (((stage_v_97_2 << 1) ^ (sec_r000205_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_106_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_106_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_106_1 & 63;
  out_sink_2 ^= stage_v_106_2 & 63;
  int stage_v_107_1 = (((sec_r000205_5_1 << 2) ^ (sec_r000205_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_107_2 = (((sec_r000205_5_2 << 2) ^ (sec_r000205_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_107_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_107_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_107_1 & 63;
  out_sink_2 ^= stage_v_107_2 & 63;
  int stage_v_108_1 = (((sec_r000205_18_1 << 1) ^ (sec_r000205_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_108_2 = (((sec_r000205_18_2 << 1) ^ (sec_r000205_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_108_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_108_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_108_1 & 63;
  out_sink_2 ^= stage_v_108_2 & 63;
  int stage_v_109_1 = (((stage_v_63_1 << 1) ^ (sec_r000205_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_109_2 = (((stage_v_63_2 << 1) ^ (sec_r000205_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_109_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_109_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = (((stage_v_109_1 << 2) ^ (sec_r000205_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_110_2 = (((stage_v_109_2 << 2) ^ (sec_r000205_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_110_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_110_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = (((sec_r000205_20_1 << 1) ^ (sec_r000205_20_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_111_2 = (((sec_r000205_20_2 << 1) ^ (sec_r000205_20_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_111_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_111_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = (((sec_r000205_2_1 << 1) ^ (sec_r000205_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_112_2 = (((sec_r000205_2_2 << 1) ^ (sec_r000205_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_112_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_112_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = (((stage_v_110_1 << 2) ^ (sec_r000205_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_113_2 = (((stage_v_110_2 << 2) ^ (sec_r000205_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_113_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_113_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_113_1 & 63;
  out_sink_2 ^= stage_v_113_2 & 63;
  int stage_v_114_1 = (((stage_v_67_1 << 1) ^ (sec_r000205_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_114_2 = (((stage_v_67_2 << 1) ^ (sec_r000205_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_114_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_114_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_114_1 & 63;
  out_sink_2 ^= stage_v_114_2 & 63;
  int stage_v_115_1 = (((stage_v_100_1 << 2) ^ (sec_r000205_20_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_115_2 = (((stage_v_100_2 << 2) ^ (sec_r000205_20_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_115_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_115_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = (((sec_r000205_21_1 << 1) ^ (sec_r000205_21_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_116_2 = (((sec_r000205_21_2 << 1) ^ (sec_r000205_21_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_116_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_116_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_116_1 & 63;
  out_sink_2 ^= stage_v_116_2 & 63;
  int stage_v_117_1 = (((stage_v_101_1 << 2) ^ (sec_r000205_20_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_117_2 = (((stage_v_101_2 << 2) ^ (sec_r000205_20_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_117_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_117_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_117_1 & 63;
  out_sink_2 ^= stage_v_117_2 & 63;
  int stage_v_118_1 = (((sec_r000205_1_1 << 2) ^ (sec_r000205_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_118_2 = (((sec_r000205_1_2 << 2) ^ (sec_r000205_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_118_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_118_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_118_1 & 63;
  out_sink_2 ^= stage_v_118_2 & 63;
  int stage_v_119_1 = (((sec_r000205_17_1 << 1) ^ (sec_r000205_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_119_2 = (((sec_r000205_17_2 << 1) ^ (sec_r000205_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_119_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_119_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = (((stage_v_78_1 << 1) ^ (sec_r000205_20_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_120_2 = (((stage_v_78_2 << 1) ^ (sec_r000205_20_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_120_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_120_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_120_1 & 63;
  out_sink_2 ^= stage_v_120_2 & 63;
  int stage_v_121_1 = (((sec_r000205_20_1 << 1) ^ (sec_r000205_20_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_121_2 = (((sec_r000205_20_2 << 1) ^ (sec_r000205_20_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_121_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_121_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = (((stage_v_102_1 << 2) ^ (sec_r000205_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_122_2 = (((stage_v_102_2 << 2) ^ (sec_r000205_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_122_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_122_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = (((stage_v_92_1 << 2) ^ (sec_r000205_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_123_2 = (((stage_v_92_2 << 2) ^ (sec_r000205_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_123_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_123_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = (((stage_v_92_1 << 1) ^ (sec_r000205_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_124_2 = (((stage_v_92_2 << 1) ^ (sec_r000205_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_124_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_124_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_124_1 & 63;
  out_sink_2 ^= stage_v_124_2 & 63;
  int stage_v_125_1 = (((sec_r000205_10_1 << 2) ^ (sec_r000205_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_125_2 = (((sec_r000205_10_2 << 2) ^ (sec_r000205_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_125_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_125_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = (((stage_v_80_1 << 2) ^ (sec_r000205_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_126_2 = (((stage_v_80_2 << 2) ^ (sec_r000205_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_126_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_126_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = (((stage_v_110_1 << 1) ^ (sec_r000205_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_127_2 = (((stage_v_110_2 << 1) ^ (sec_r000205_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_127_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_127_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = (((stage_v_79_1 << 2) ^ (sec_r000205_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_128_2 = (((stage_v_79_2 << 2) ^ (sec_r000205_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_128_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_128_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = (((sec_r000205_20_1 << 2) ^ (sec_r000205_20_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_129_2 = (((sec_r000205_20_2 << 2) ^ (sec_r000205_20_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_129_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_129_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = (((stage_v_125_1 << 1) ^ (sec_r000205_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_130_2 = (((stage_v_125_2 << 1) ^ (sec_r000205_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_130_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_130_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = (((sec_r000205_23_1 << 1) ^ (sec_r000205_23_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_131_2 = (((sec_r000205_23_2 << 1) ^ (sec_r000205_23_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_131_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_131_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = (((stage_v_122_1 << 1) ^ (sec_r000205_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_132_2 = (((stage_v_122_2 << 1) ^ (sec_r000205_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_132_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_132_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = (((stage_v_72_1 << 1) ^ (sec_r000205_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_133_2 = (((stage_v_72_2 << 1) ^ (sec_r000205_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_133_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_133_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_133_1 & 63;
  out_sink_2 ^= stage_v_133_2 & 63;
  int stage_v_134_1 = (((stage_v_76_1 << 1) ^ (sec_r000205_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_134_2 = (((stage_v_76_2 << 1) ^ (sec_r000205_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_134_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_134_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_134_1 & 63;
  out_sink_2 ^= stage_v_134_2 & 63;
  int stage_v_135_1 = (((stage_v_82_1 << 2) ^ (sec_r000205_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_135_2 = (((stage_v_82_2 << 2) ^ (sec_r000205_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_135_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_135_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_135_1 & 63;
  out_sink_2 ^= stage_v_135_2 & 63;
  int stage_v_136_1 = (((stage_v_109_1 << 1) ^ (sec_r000205_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_136_2 = (((stage_v_109_2 << 1) ^ (sec_r000205_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_136_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_136_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = (((sec_r000205_7_1 << 1) ^ (sec_r000205_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_137_2 = (((sec_r000205_7_2 << 1) ^ (sec_r000205_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = (((stage_v_98_1 << 2) ^ (sec_r000205_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_138_2 = (((stage_v_98_2 << 2) ^ (sec_r000205_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_138_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_138_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_138_1 & 63;
  out_sink_2 ^= stage_v_138_2 & 63;
  int stage_v_139_1 = (((stage_v_77_1 << 2) ^ (sec_r000205_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_139_2 = (((stage_v_77_2 << 2) ^ (sec_r000205_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_139_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_139_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_139_1 & 63;
  out_sink_2 ^= stage_v_139_2 & 63;
  int stage_v_140_1 = (((sec_r000205_21_1 << 2) ^ (sec_r000205_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_140_2 = (((sec_r000205_21_2 << 2) ^ (sec_r000205_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_140_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_140_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_140_1 & 63;
  out_sink_2 ^= stage_v_140_2 & 63;
  int stage_v_141_1 = (((sec_r000205_17_1 << 1) ^ (sec_r000205_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_141_2 = (((sec_r000205_17_2 << 1) ^ (sec_r000205_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_141_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_141_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = (((stage_v_137_1 << 1) ^ (sec_r000205_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_142_2 = (((stage_v_137_2 << 1) ^ (sec_r000205_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_142_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_142_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = (((stage_v_76_1 << 2) ^ (sec_r000205_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_143_2 = (((stage_v_76_2 << 2) ^ (sec_r000205_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_143_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_143_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_143_1 & 63;
  out_sink_2 ^= stage_v_143_2 & 63;
  int stage_v_144_1 = (((sec_r000205_4_1 << 2) ^ (sec_r000205_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_144_2 = (((sec_r000205_4_2 << 2) ^ (sec_r000205_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_144_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_144_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = (((stage_v_135_1 << 2) ^ (sec_r000205_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_145_2 = (((stage_v_135_2 << 2) ^ (sec_r000205_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_145_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_145_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = (((stage_v_87_1 << 1) ^ (sec_r000205_21_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_146_2 = (((stage_v_87_2 << 1) ^ (sec_r000205_21_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_146_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_146_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = (((sec_r000205_11_1 << 2) ^ (sec_r000205_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_147_2 = (((sec_r000205_11_2 << 2) ^ (sec_r000205_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_147_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_147_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = (((stage_v_112_1 << 1) ^ (sec_r000205_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_148_2 = (((stage_v_112_2 << 1) ^ (sec_r000205_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_148_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_148_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_148_1 & 63;
  out_sink_2 ^= stage_v_148_2 & 63;
  int stage_v_149_1 = (((stage_v_109_1 << 2) ^ (sec_r000205_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_149_2 = (((stage_v_109_2 << 2) ^ (sec_r000205_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_149_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_149_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_149_1 & 63;
  out_sink_2 ^= stage_v_149_2 & 63;
  int stage_v_150_1 = (((sec_r000205_2_1 << 1) ^ (sec_r000205_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_150_2 = (((sec_r000205_2_2 << 1) ^ (sec_r000205_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_150_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_150_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = (((stage_v_124_1 << 1) ^ (sec_r000205_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_151_2 = (((stage_v_124_2 << 1) ^ (sec_r000205_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_151_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_151_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = (((stage_v_69_1 << 1) ^ (sec_r000205_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_152_2 = (((stage_v_69_2 << 1) ^ (sec_r000205_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = (((sec_r000205_13_1 << 2) ^ (sec_r000205_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_153_2 = (((sec_r000205_13_2 << 2) ^ (sec_r000205_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_153_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_153_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = (((sec_r000205_13_1 << 1) ^ (sec_r000205_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_154_2 = (((sec_r000205_13_2 << 1) ^ (sec_r000205_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_154_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_154_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_154_1 & 63;
  out_sink_2 ^= stage_v_154_2 & 63;
  int stage_v_155_1 = (((stage_v_140_1 << 1) ^ (sec_r000205_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_155_2 = (((stage_v_140_2 << 1) ^ (sec_r000205_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_155_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_155_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = (((sec_r000205_17_1 << 1) ^ (sec_r000205_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_156_2 = (((sec_r000205_17_2 << 1) ^ (sec_r000205_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_156_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_156_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = (((sec_r000205_22_1 << 1) ^ (sec_r000205_22_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_157_2 = (((sec_r000205_22_2 << 1) ^ (sec_r000205_22_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_157_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_157_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_157_1 & 63;
  out_sink_2 ^= stage_v_157_2 & 63;
  int stage_v_158_1 = (((stage_v_142_1 << 2) ^ (sec_r000205_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_158_2 = (((stage_v_142_2 << 2) ^ (sec_r000205_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_158_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_158_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = (((stage_v_135_1 << 2) ^ (sec_r000205_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_159_2 = (((stage_v_135_2 << 2) ^ (sec_r000205_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_159_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_159_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = (((stage_v_153_1 << 2) ^ (sec_r000205_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_160_2 = (((stage_v_153_2 << 2) ^ (sec_r000205_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_160_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_160_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_160_1 & 63;
  out_sink_2 ^= stage_v_160_2 & 63;
  int stage_v_161_1 = (((stage_v_90_1 << 1) ^ (sec_r000205_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_161_2 = (((stage_v_90_2 << 1) ^ (sec_r000205_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_161_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_161_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_161_1 & 63;
  out_sink_2 ^= stage_v_161_2 & 63;
  int stage_v_162_1 = (((stage_v_99_1 << 1) ^ (sec_r000205_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_162_2 = (((stage_v_99_2 << 1) ^ (sec_r000205_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_162_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_162_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = (((stage_v_71_1 << 1) ^ (sec_r000205_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_163_2 = (((stage_v_71_2 << 1) ^ (sec_r000205_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_163_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_163_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_163_1 & 63;
  out_sink_2 ^= stage_v_163_2 & 63;
  int stage_v_164_1 = (((sec_r000205_3_1 << 2) ^ (sec_r000205_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_164_2 = (((sec_r000205_3_2 << 2) ^ (sec_r000205_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_164_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_164_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = (((sec_r000205_1_1 << 2) ^ (sec_r000205_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_165_2 = (((sec_r000205_1_2 << 2) ^ (sec_r000205_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_165_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_165_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = (((stage_v_63_1 << 1) ^ (sec_r000205_22_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_166_2 = (((stage_v_63_2 << 1) ^ (sec_r000205_22_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_166_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_166_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = (((sec_r000205_13_1 << 2) ^ (sec_r000205_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_167_2 = (((sec_r000205_13_2 << 2) ^ (sec_r000205_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_167_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_167_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = (((stage_v_63_1 << 2) ^ (sec_r000205_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_168_2 = (((stage_v_63_2 << 2) ^ (sec_r000205_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_168_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_168_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_168_1 & 63;
  out_sink_2 ^= stage_v_168_2 & 63;
  int stage_v_169_1 = (((stage_v_124_1 << 1) ^ (sec_r000205_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_169_2 = (((stage_v_124_2 << 1) ^ (sec_r000205_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_169_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_169_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_169_1 & 63;
  out_sink_2 ^= stage_v_169_2 & 63;
  int stage_v_170_1 = (((stage_v_159_1 << 2) ^ (sec_r000205_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_170_2 = (((stage_v_159_2 << 2) ^ (sec_r000205_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_170_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_170_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = (((sec_r000205_16_1 << 1) ^ (sec_r000205_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_171_2 = (((sec_r000205_16_2 << 1) ^ (sec_r000205_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_171_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_171_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_171_1 & 63;
  out_sink_2 ^= stage_v_171_2 & 63;
  int stage_v_172_1 = (((sec_r000205_22_1 << 2) ^ (sec_r000205_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_172_2 = (((sec_r000205_22_2 << 2) ^ (sec_r000205_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_172_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_172_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_172_1 & 63;
  out_sink_2 ^= stage_v_172_2 & 63;
  int stage_v_173_1 = (((stage_v_170_1 << 1) ^ (sec_r000205_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_173_2 = (((stage_v_170_2 << 1) ^ (sec_r000205_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_173_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_173_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_173_1 & 63;
  out_sink_2 ^= stage_v_173_2 & 63;
  int stage_v_174_1 = (((stage_v_111_1 << 2) ^ (sec_r000205_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_174_2 = (((stage_v_111_2 << 2) ^ (sec_r000205_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_174_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_174_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = (((sec_r000205_4_1 << 1) ^ (sec_r000205_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_175_2 = (((sec_r000205_4_2 << 1) ^ (sec_r000205_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_175_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_175_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = (((sec_r000205_3_1 << 2) ^ (sec_r000205_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_176_2 = (((sec_r000205_3_2 << 2) ^ (sec_r000205_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_176_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_176_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_176_1 & 63;
  out_sink_2 ^= stage_v_176_2 & 63;
  int stage_v_177_1 = (((sec_r000205_20_1 << 2) ^ (sec_r000205_20_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_177_2 = (((sec_r000205_20_2 << 2) ^ (sec_r000205_20_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_177_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_177_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_177_1 & 63;
  out_sink_2 ^= stage_v_177_2 & 63;
  int stage_v_178_1 = (((stage_v_122_1 << 1) ^ (sec_r000205_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_178_2 = (((stage_v_122_2 << 1) ^ (sec_r000205_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_178_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_178_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = (((stage_v_96_1 << 1) ^ (sec_r000205_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_179_2 = (((stage_v_96_2 << 1) ^ (sec_r000205_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_179_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_179_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = (((sec_r000205_8_1 << 1) ^ (sec_r000205_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_180_2 = (((sec_r000205_8_2 << 1) ^ (sec_r000205_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_180_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_180_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_180_1 & 63;
  out_sink_2 ^= stage_v_180_2 & 63;
  int stage_v_181_1 = (((sec_r000205_2_1 << 1) ^ (sec_r000205_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_181_2 = (((sec_r000205_2_2 << 1) ^ (sec_r000205_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_181_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_181_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_181_1 & 63;
  out_sink_2 ^= stage_v_181_2 & 63;
  int stage_v_182_1 = (((stage_v_76_1 << 1) ^ (sec_r000205_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_182_2 = (((stage_v_76_2 << 1) ^ (sec_r000205_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_182_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_182_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_182_1 & 63;
  out_sink_2 ^= stage_v_182_2 & 63;
  int stage_v_183_1 = (((stage_v_132_1 << 2) ^ (sec_r000205_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_183_2 = (((stage_v_132_2 << 2) ^ (sec_r000205_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_183_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_183_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = (((sec_r000205_17_1 << 1) ^ (sec_r000205_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_184_2 = (((sec_r000205_17_2 << 1) ^ (sec_r000205_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_184_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_184_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_184_1 & 63;
  out_sink_2 ^= stage_v_184_2 & 63;
  int stage_v_185_1 = (((stage_v_131_1 << 2) ^ (sec_r000205_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_185_2 = (((stage_v_131_2 << 2) ^ (sec_r000205_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_185_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_185_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = (((sec_r000205_10_1 << 2) ^ (sec_r000205_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_186_2 = (((sec_r000205_10_2 << 2) ^ (sec_r000205_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_186_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_186_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_186_1 & 63;
  out_sink_2 ^= stage_v_186_2 & 63;
  int stage_v_187_1 = (((sec_r000205_1_1 << 1) ^ (sec_r000205_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_187_2 = (((sec_r000205_1_2 << 1) ^ (sec_r000205_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_187_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_187_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = (((stage_v_99_1 << 2) ^ (sec_r000205_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_188_2 = (((stage_v_99_2 << 2) ^ (sec_r000205_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_188_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_188_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_188_1 & 63;
  out_sink_2 ^= stage_v_188_2 & 63;
  int stage_v_189_1 = (((stage_v_101_1 << 1) ^ (sec_r000205_23_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_189_2 = (((stage_v_101_2 << 1) ^ (sec_r000205_23_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_189_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_189_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_189_1 & 63;
  out_sink_2 ^= stage_v_189_2 & 63;
  int stage_v_190_1 = (((sec_r000205_10_1 << 2) ^ (sec_r000205_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_190_2 = (((sec_r000205_10_2 << 2) ^ (sec_r000205_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_190_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_190_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_190_1 & 63;
  out_sink_2 ^= stage_v_190_2 & 63;
  int stage_v_191_1 = (((sec_r000205_22_1 << 1) ^ (sec_r000205_22_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_191_2 = (((sec_r000205_22_2 << 1) ^ (sec_r000205_22_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_191_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_191_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = (((stage_v_132_1 << 1) ^ (sec_r000205_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_192_2 = (((stage_v_132_2 << 1) ^ (sec_r000205_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_192_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_192_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = (((stage_v_159_1 << 1) ^ (sec_r000205_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_193_2 = (((stage_v_159_2 << 1) ^ (sec_r000205_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_193_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_193_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = (((sec_r000205_12_1 << 2) ^ (sec_r000205_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_194_2 = (((sec_r000205_12_2 << 2) ^ (sec_r000205_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_194_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_194_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = (((sec_r000205_0_1 << 2) ^ (sec_r000205_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_195_2 = (((sec_r000205_0_2 << 2) ^ (sec_r000205_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_195_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_195_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_195_1 & 63;
  out_sink_2 ^= stage_v_195_2 & 63;
  int stage_v_196_1 = (((stage_v_175_1 << 2) ^ (sec_r000205_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_196_2 = (((stage_v_175_2 << 2) ^ (sec_r000205_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_196_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_196_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = (((sec_r000205_17_1 << 1) ^ (sec_r000205_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_197_2 = (((sec_r000205_17_2 << 1) ^ (sec_r000205_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_197_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_197_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = (((sec_r000205_10_1 << 2) ^ (sec_r000205_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_198_2 = (((sec_r000205_10_2 << 2) ^ (sec_r000205_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_198_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_198_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = (((sec_r000205_20_1 << 2) ^ (sec_r000205_20_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_199_2 = (((sec_r000205_20_2 << 2) ^ (sec_r000205_20_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_199_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_199_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = (((stage_v_64_1 << 1) ^ (sec_r000205_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_200_2 = (((stage_v_64_2 << 1) ^ (sec_r000205_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_200_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_200_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = (((sec_r000205_17_1 << 1) ^ (sec_r000205_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_201_2 = (((sec_r000205_17_2 << 1) ^ (sec_r000205_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_201_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_201_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = (((stage_v_126_1 << 2) ^ (sec_r000205_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_202_2 = (((stage_v_126_2 << 2) ^ (sec_r000205_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_202_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_202_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = (((sec_r000205_5_1 << 2) ^ (sec_r000205_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_203_2 = (((sec_r000205_5_2 << 2) ^ (sec_r000205_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_203_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_203_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_203_1 & 63;
  out_sink_2 ^= stage_v_203_2 & 63;
  int stage_v_204_1 = (((stage_v_136_1 << 1) ^ (sec_r000205_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_204_2 = (((stage_v_136_2 << 1) ^ (sec_r000205_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_204_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_204_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_204_1 & 63;
  out_sink_2 ^= stage_v_204_2 & 63;
  int stage_v_205_1 = (((stage_v_61_1 << 1) ^ (sec_r000205_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_205_2 = (((stage_v_61_2 << 1) ^ (sec_r000205_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_205_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_205_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = (((sec_r000205_0_1 << 2) ^ (sec_r000205_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_206_2 = (((sec_r000205_0_2 << 2) ^ (sec_r000205_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_206_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_206_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_206_1 & 63;
  out_sink_2 ^= stage_v_206_2 & 63;
  int stage_v_207_1 = (((sec_r000205_5_1 << 2) ^ (sec_r000205_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_207_2 = (((sec_r000205_5_2 << 2) ^ (sec_r000205_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_207_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_207_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_207_1 & 63;
  out_sink_2 ^= stage_v_207_2 & 63;
  int stage_v_208_1 = (((stage_v_101_1 << 2) ^ (sec_r000205_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_208_2 = (((stage_v_101_2 << 2) ^ (sec_r000205_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_208_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_208_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = (((stage_v_83_1 << 2) ^ (sec_r000205_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_209_2 = (((stage_v_83_2 << 2) ^ (sec_r000205_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_209_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_209_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = (((stage_v_204_1 << 2) ^ (sec_r000205_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_210_2 = (((stage_v_204_2 << 2) ^ (sec_r000205_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_210_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_210_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = (((sec_r000205_2_1 << 1) ^ (sec_r000205_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_211_2 = (((sec_r000205_2_2 << 1) ^ (sec_r000205_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_211_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_211_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = (((sec_r000205_4_1 << 1) ^ (sec_r000205_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_212_2 = (((sec_r000205_4_2 << 1) ^ (sec_r000205_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_212_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_212_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = (((stage_v_110_1 << 1) ^ (sec_r000205_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_213_2 = (((stage_v_110_2 << 1) ^ (sec_r000205_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_213_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_213_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = (((stage_v_199_1 << 1) ^ (sec_r000205_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_214_2 = (((stage_v_199_2 << 1) ^ (sec_r000205_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_214_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_214_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = (((stage_v_156_1 << 1) ^ (sec_r000205_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_215_2 = (((stage_v_156_2 << 1) ^ (sec_r000205_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_215_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_215_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_215_1 & 63;
  out_sink_2 ^= stage_v_215_2 & 63;
  int stage_v_216_1 = (((stage_v_173_1 << 2) ^ (sec_r000205_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_216_2 = (((stage_v_173_2 << 2) ^ (sec_r000205_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_216_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_216_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = (((stage_v_61_1 << 2) ^ (sec_r000205_23_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_217_2 = (((stage_v_61_2 << 2) ^ (sec_r000205_23_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_217_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_217_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_217_1 & 63;
  out_sink_2 ^= stage_v_217_2 & 63;
  int stage_v_218_1 = (((stage_v_120_1 << 1) ^ (sec_r000205_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_218_2 = (((stage_v_120_2 << 1) ^ (sec_r000205_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_218_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_218_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_218_1 & 63;
  out_sink_2 ^= stage_v_218_2 & 63;
  int stage_v_219_1 = (((stage_v_75_1 << 1) ^ (sec_r000205_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_219_2 = (((stage_v_75_2 << 1) ^ (sec_r000205_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_219_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_219_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = (((sec_r000205_5_1 << 1) ^ (sec_r000205_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_220_2 = (((sec_r000205_5_2 << 1) ^ (sec_r000205_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_220_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_220_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = (((stage_v_120_1 << 1) ^ (sec_r000205_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_221_2 = (((stage_v_120_2 << 1) ^ (sec_r000205_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_221_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_221_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = (((stage_v_186_1 << 2) ^ (sec_r000205_20_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_222_2 = (((stage_v_186_2 << 2) ^ (sec_r000205_20_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_222_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_222_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = (((sec_r000205_0_1 << 1) ^ (sec_r000205_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_223_2 = (((sec_r000205_0_2 << 1) ^ (sec_r000205_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_223_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_223_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_223_1 & 63;
  out_sink_2 ^= stage_v_223_2 & 63;
  int stage_v_224_1 = (((stage_v_182_1 << 1) ^ (sec_r000205_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_224_2 = (((stage_v_182_2 << 1) ^ (sec_r000205_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_224_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_224_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_224_1 & 63;
  out_sink_2 ^= stage_v_224_2 & 63;
  int stage_v_225_1 = (((stage_v_167_1 << 1) ^ (sec_r000205_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_225_2 = (((stage_v_167_2 << 1) ^ (sec_r000205_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_225_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_225_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = (((sec_r000205_18_1 << 1) ^ (sec_r000205_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_226_2 = (((sec_r000205_18_2 << 1) ^ (sec_r000205_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_226_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_226_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_226_1 & 63;
  out_sink_2 ^= stage_v_226_2 & 63;
  int stage_v_227_1 = (((sec_r000205_8_1 << 2) ^ (sec_r000205_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_227_2 = (((sec_r000205_8_2 << 2) ^ (sec_r000205_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_227_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_227_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = (((sec_r000205_7_1 << 1) ^ (sec_r000205_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_228_2 = (((sec_r000205_7_2 << 1) ^ (sec_r000205_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_228_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_228_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_228_1 & 63;
  out_sink_2 ^= stage_v_228_2 & 63;
  int stage_v_229_1 = (((stage_v_120_1 << 1) ^ (sec_r000205_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_229_2 = (((stage_v_120_2 << 1) ^ (sec_r000205_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_229_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_229_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_229_1 & 63;
  out_sink_2 ^= stage_v_229_2 & 63;
  int stage_v_230_1 = (((sec_r000205_13_1 << 1) ^ (sec_r000205_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_230_2 = (((sec_r000205_13_2 << 1) ^ (sec_r000205_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_230_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_230_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = (((stage_v_123_1 << 2) ^ (sec_r000205_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_231_2 = (((stage_v_123_2 << 2) ^ (sec_r000205_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_231_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_231_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_231_1 & 63;
  out_sink_2 ^= stage_v_231_2 & 63;
  int stage_v_232_1 = (((stage_v_228_1 << 2) ^ (sec_r000205_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_232_2 = (((stage_v_228_2 << 2) ^ (sec_r000205_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_232_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_232_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = (((sec_r000205_4_1 << 2) ^ (sec_r000205_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_233_2 = (((sec_r000205_4_2 << 2) ^ (sec_r000205_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_233_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_233_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_233_1 & 63;
  out_sink_2 ^= stage_v_233_2 & 63;
  int stage_v_234_1 = (((sec_r000205_2_1 << 2) ^ (sec_r000205_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_234_2 = (((sec_r000205_2_2 << 2) ^ (sec_r000205_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_234_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_234_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = (((stage_v_77_1 << 2) ^ (sec_r000205_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_235_2 = (((stage_v_77_2 << 2) ^ (sec_r000205_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_235_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_235_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = (((stage_v_187_1 << 1) ^ (sec_r000205_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_236_2 = (((stage_v_187_2 << 1) ^ (sec_r000205_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_236_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_236_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = (((stage_v_157_1 << 2) ^ (sec_r000205_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_237_2 = (((stage_v_157_2 << 2) ^ (sec_r000205_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_237_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_237_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_237_1 & 63;
  out_sink_2 ^= stage_v_237_2 & 63;
  int stage_v_238_1 = (((sec_r000205_1_1 << 2) ^ (sec_r000205_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_238_2 = (((sec_r000205_1_2 << 2) ^ (sec_r000205_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_238_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_238_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_238_1 & 63;
  out_sink_2 ^= stage_v_238_2 & 63;
  int stage_v_239_1 = (((stage_v_168_1 << 2) ^ (sec_r000205_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_239_2 = (((stage_v_168_2 << 2) ^ (sec_r000205_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_239_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_239_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = (((sec_r000205_4_1 << 1) ^ (sec_r000205_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_240_2 = (((sec_r000205_4_2 << 1) ^ (sec_r000205_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_240_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_240_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = (((sec_r000205_18_1 << 1) ^ (sec_r000205_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_241_2 = (((sec_r000205_18_2 << 1) ^ (sec_r000205_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_241_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_241_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = (((sec_r000205_1_1 << 1) ^ (sec_r000205_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_242_2 = (((sec_r000205_1_2 << 1) ^ (sec_r000205_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_242_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_242_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_242_1 & 63;
  out_sink_2 ^= stage_v_242_2 & 63;
  int stage_v_243_1 = (((stage_v_141_1 << 1) ^ (sec_r000205_21_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_243_2 = (((stage_v_141_2 << 1) ^ (sec_r000205_21_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_243_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_243_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = (((stage_v_194_1 << 2) ^ (sec_r000205_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_244_2 = (((stage_v_194_2 << 2) ^ (sec_r000205_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_244_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_244_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_244_1 & 63;
  out_sink_2 ^= stage_v_244_2 & 63;
  int stage_v_245_1 = (((stage_v_141_1 << 1) ^ (sec_r000205_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_245_2 = (((stage_v_141_2 << 1) ^ (sec_r000205_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_245_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_245_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_245_1 & 63;
  out_sink_2 ^= stage_v_245_2 & 63;
  int stage_v_246_1 = (((sec_r000205_22_1 << 1) ^ (sec_r000205_22_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_246_2 = (((sec_r000205_22_2 << 1) ^ (sec_r000205_22_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_246_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_246_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_246_1 & 63;
  out_sink_2 ^= stage_v_246_2 & 63;
  int stage_v_247_1 = (((stage_v_124_1 << 2) ^ (sec_r000205_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_247_2 = (((stage_v_124_2 << 2) ^ (sec_r000205_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_247_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_247_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_247_1 & 63;
  out_sink_2 ^= stage_v_247_2 & 63;
  int stage_v_248_1 = (((stage_v_156_1 << 1) ^ (sec_r000205_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_248_2 = (((stage_v_156_2 << 1) ^ (sec_r000205_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_248_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_248_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = (((stage_v_189_1 << 1) ^ (sec_r000205_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_249_2 = (((stage_v_189_2 << 1) ^ (sec_r000205_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_249_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_249_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = (((stage_v_178_1 << 1) ^ (sec_r000205_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_250_2 = (((stage_v_178_2 << 1) ^ (sec_r000205_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_250_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_250_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_250_1 & 63;
  out_sink_2 ^= stage_v_250_2 & 63;
  int stage_v_251_1 = (((sec_r000205_0_1 << 2) ^ (sec_r000205_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_251_2 = (((sec_r000205_0_2 << 2) ^ (sec_r000205_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_251_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_251_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_251_1 & 63;
  out_sink_2 ^= stage_v_251_2 & 63;
  int stage_v_252_1 = (((stage_v_129_1 << 2) ^ (sec_r000205_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_252_2 = (((stage_v_129_2 << 2) ^ (sec_r000205_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_252_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_252_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = (((stage_v_80_1 << 1) ^ (sec_r000205_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_253_2 = (((stage_v_80_2 << 1) ^ (sec_r000205_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_253_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_253_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = (((sec_r000205_4_1 << 1) ^ (sec_r000205_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_254_2 = (((sec_r000205_4_2 << 1) ^ (sec_r000205_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_254_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_254_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_254_1 & 63;
  out_sink_2 ^= stage_v_254_2 & 63;
  int stage_v_255_1 = (((stage_v_218_1 << 2) ^ (sec_r000205_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_255_2 = (((stage_v_218_2 << 2) ^ (sec_r000205_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_255_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_255_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_255_1 & 63;
  out_sink_2 ^= stage_v_255_2 & 63;
  int stage_v_256_1 = (((sec_r000205_3_1 << 1) ^ (sec_r000205_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_256_2 = (((sec_r000205_3_2 << 1) ^ (sec_r000205_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_256_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_256_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = (((sec_r000205_14_1 << 1) ^ (sec_r000205_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_257_2 = (((sec_r000205_14_2 << 1) ^ (sec_r000205_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_257_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_257_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = (((stage_v_245_1 << 1) ^ (sec_r000205_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_258_2 = (((stage_v_245_2 << 1) ^ (sec_r000205_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_258_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_258_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_258_1 & 63;
  out_sink_2 ^= stage_v_258_2 & 63;
  int stage_v_259_1 = (((sec_r000205_2_1 << 1) ^ (sec_r000205_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_259_2 = (((sec_r000205_2_2 << 1) ^ (sec_r000205_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_259_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_259_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = (((sec_r000205_21_1 << 2) ^ (sec_r000205_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_260_2 = (((sec_r000205_21_2 << 2) ^ (sec_r000205_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_260_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_260_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_260_1 & 63;
  out_sink_2 ^= stage_v_260_2 & 63;
  int stage_v_261_1 = (((sec_r000205_4_1 << 1) ^ (sec_r000205_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_261_2 = (((sec_r000205_4_2 << 1) ^ (sec_r000205_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_261_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_261_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_261_1 & 63;
  out_sink_2 ^= stage_v_261_2 & 63;
  int stage_v_262_1 = (((sec_r000205_19_1 << 2) ^ (sec_r000205_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_262_2 = (((sec_r000205_19_2 << 2) ^ (sec_r000205_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_262_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_262_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_262_1 & 63;
  out_sink_2 ^= stage_v_262_2 & 63;
  int stage_v_263_1 = (((sec_r000205_20_1 << 2) ^ (sec_r000205_20_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_263_2 = (((sec_r000205_20_2 << 2) ^ (sec_r000205_20_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_263_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_263_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_263_1 & 63;
  out_sink_2 ^= stage_v_263_2 & 63;
  int stage_v_264_1 = (((sec_r000205_4_1 << 2) ^ (sec_r000205_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_264_2 = (((sec_r000205_4_2 << 2) ^ (sec_r000205_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_264_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_264_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_264_1 & 63;
  out_sink_2 ^= stage_v_264_2 & 63;
  int stage_v_265_1 = (((sec_r000205_22_1 << 2) ^ (sec_r000205_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_265_2 = (((sec_r000205_22_2 << 2) ^ (sec_r000205_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_265_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_265_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = (((sec_r000205_18_1 << 2) ^ (sec_r000205_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_266_2 = (((sec_r000205_18_2 << 2) ^ (sec_r000205_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_266_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_266_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_266_1 & 63;
  out_sink_2 ^= stage_v_266_2 & 63;
  int stage_v_267_1 = (((stage_v_257_1 << 1) ^ (sec_r000205_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_267_2 = (((stage_v_257_2 << 1) ^ (sec_r000205_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_267_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_267_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_267_1 & 63;
  out_sink_2 ^= stage_v_267_2 & 63;
  int stage_v_268_1 = (((stage_v_111_1 << 1) ^ (sec_r000205_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_268_2 = (((stage_v_111_2 << 1) ^ (sec_r000205_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_268_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_268_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_268_1 & 63;
  out_sink_2 ^= stage_v_268_2 & 63;
  int stage_v_269_1 = (((stage_v_204_1 << 1) ^ (sec_r000205_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_269_2 = (((stage_v_204_2 << 1) ^ (sec_r000205_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_269_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_269_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = (((stage_v_193_1 << 1) ^ (sec_r000205_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_270_2 = (((stage_v_193_2 << 1) ^ (sec_r000205_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_270_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_270_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_270_1 & 63;
  out_sink_2 ^= stage_v_270_2 & 63;
  int stage_v_271_1 = (((stage_v_177_1 << 2) ^ (sec_r000205_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_271_2 = (((stage_v_177_2 << 2) ^ (sec_r000205_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_271_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_271_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_271_1 & 63;
  out_sink_2 ^= stage_v_271_2 & 63;
  int stage_v_272_1 = (((stage_v_191_1 << 1) ^ (sec_r000205_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_272_2 = (((stage_v_191_2 << 1) ^ (sec_r000205_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_272_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_272_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = (((stage_v_162_1 << 1) ^ (sec_r000205_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_273_2 = (((stage_v_162_2 << 1) ^ (sec_r000205_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_273_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_273_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = (((stage_v_157_1 << 1) ^ (sec_r000205_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_274_2 = (((stage_v_157_2 << 1) ^ (sec_r000205_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_274_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_274_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_274_1 & 63;
  out_sink_2 ^= stage_v_274_2 & 63;
  int stage_v_275_1 = (((stage_v_105_1 << 1) ^ (sec_r000205_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_275_2 = (((stage_v_105_2 << 1) ^ (sec_r000205_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_275_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_275_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = (((stage_v_223_1 << 1) ^ (sec_r000205_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_276_2 = (((stage_v_223_2 << 1) ^ (sec_r000205_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_276_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_276_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = (((stage_v_114_1 << 1) ^ (sec_r000205_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_277_2 = (((stage_v_114_2 << 1) ^ (sec_r000205_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_277_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_277_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = (((stage_v_190_1 << 2) ^ (sec_r000205_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_278_2 = (((stage_v_190_2 << 2) ^ (sec_r000205_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_278_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_278_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_278_1 & 63;
  out_sink_2 ^= stage_v_278_2 & 63;
  int stage_v_279_1 = (((sec_r000205_6_1 << 2) ^ (sec_r000205_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_279_2 = (((sec_r000205_6_2 << 2) ^ (sec_r000205_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_279_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_279_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_279_1 & 63;
  out_sink_2 ^= stage_v_279_2 & 63;
  int stage_v_280_1 = (((stage_v_262_1 << 1) ^ (sec_r000205_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_280_2 = (((stage_v_262_2 << 1) ^ (sec_r000205_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_280_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_280_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_280_1 & 63;
  out_sink_2 ^= stage_v_280_2 & 63;
  int stage_v_281_1 = (((stage_v_155_1 << 2) ^ (sec_r000205_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_281_2 = (((stage_v_155_2 << 2) ^ (sec_r000205_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_281_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_281_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_281_1 & 63;
  out_sink_2 ^= stage_v_281_2 & 63;
  int stage_v_282_1 = (((sec_r000205_16_1 << 1) ^ (sec_r000205_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_282_2 = (((sec_r000205_16_2 << 1) ^ (sec_r000205_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_282_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_282_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = (((sec_r000205_5_1 << 2) ^ (sec_r000205_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_283_2 = (((sec_r000205_5_2 << 2) ^ (sec_r000205_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_283_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_283_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_283_1 & 63;
  out_sink_2 ^= stage_v_283_2 & 63;
  int stage_v_284_1 = (((stage_v_152_1 << 2) ^ (sec_r000205_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_284_2 = (((stage_v_152_2 << 2) ^ (sec_r000205_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_284_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_284_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_284_1 & 63;
  out_sink_2 ^= stage_v_284_2 & 63;
  int stage_v_285_1 = (((stage_v_244_1 << 2) ^ (sec_r000205_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_285_2 = (((stage_v_244_2 << 2) ^ (sec_r000205_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_285_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_285_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_285_1 & 63;
  out_sink_2 ^= stage_v_285_2 & 63;
  int stage_v_286_1 = (((sec_r000205_13_1 << 1) ^ (sec_r000205_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_286_2 = (((sec_r000205_13_2 << 1) ^ (sec_r000205_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_286_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_286_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_286_1 & 63;
  out_sink_2 ^= stage_v_286_2 & 63;
  int stage_v_287_1 = (((sec_r000205_10_1 << 2) ^ (sec_r000205_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_287_2 = (((sec_r000205_10_2 << 2) ^ (sec_r000205_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_287_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_287_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = (((sec_r000205_2_1 << 2) ^ (sec_r000205_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_288_2 = (((sec_r000205_2_2 << 2) ^ (sec_r000205_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_288_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_288_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_288_1 & 63;
  out_sink_2 ^= stage_v_288_2 & 63;
  int stage_v_289_1 = (((stage_v_256_1 << 2) ^ (sec_r000205_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_289_2 = (((stage_v_256_2 << 2) ^ (sec_r000205_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_289_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_289_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = (((stage_v_134_1 << 2) ^ (sec_r000205_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_290_2 = (((stage_v_134_2 << 2) ^ (sec_r000205_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_290_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_290_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = (((stage_v_176_1 << 1) ^ (sec_r000205_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_291_2 = (((stage_v_176_2 << 1) ^ (sec_r000205_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_291_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_291_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_291_1 & 63;
  out_sink_2 ^= stage_v_291_2 & 63;
  int stage_v_292_1 = (((sec_r000205_11_1 << 1) ^ (sec_r000205_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_292_2 = (((sec_r000205_11_2 << 1) ^ (sec_r000205_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_292_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_292_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_292_1 & 63;
  out_sink_2 ^= stage_v_292_2 & 63;
  int stage_v_293_1 = (((stage_v_250_1 << 1) ^ (sec_r000205_22_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_293_2 = (((stage_v_250_2 << 1) ^ (sec_r000205_22_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_293_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_293_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_293_1 & 63;
  out_sink_2 ^= stage_v_293_2 & 63;
  int stage_v_294_1 = (((sec_r000205_7_1 << 2) ^ (sec_r000205_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_294_2 = (((sec_r000205_7_2 << 2) ^ (sec_r000205_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_294_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_294_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_294_1 & 63;
  out_sink_2 ^= stage_v_294_2 & 63;
  int stage_v_295_1 = (((stage_v_95_1 << 1) ^ (sec_r000205_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_295_2 = (((stage_v_95_2 << 1) ^ (sec_r000205_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_295_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_295_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_295_1 & 63;
  out_sink_2 ^= stage_v_295_2 & 63;
  int stage_v_296_1 = (((sec_r000205_21_1 << 1) ^ (sec_r000205_21_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_296_2 = (((sec_r000205_21_2 << 1) ^ (sec_r000205_21_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_296_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_296_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_296_1 & 63;
  out_sink_2 ^= stage_v_296_2 & 63;
  int stage_v_297_1 = (((stage_v_104_1 << 1) ^ (sec_r000205_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_297_2 = (((stage_v_104_2 << 1) ^ (sec_r000205_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_297_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_297_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_297_1 & 63;
  out_sink_2 ^= stage_v_297_2 & 63;
  int stage_v_298_1 = (((sec_r000205_15_1 << 2) ^ (sec_r000205_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_298_2 = (((sec_r000205_15_2 << 2) ^ (sec_r000205_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_298_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_298_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_298_1 & 63;
  out_sink_2 ^= stage_v_298_2 & 63;
  int stage_v_299_1 = (((stage_v_62_1 << 1) ^ (sec_r000205_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_299_2 = (((stage_v_62_2 << 1) ^ (sec_r000205_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_299_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_299_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = (((stage_v_237_1 << 2) ^ (sec_r000205_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_300_2 = (((stage_v_237_2 << 2) ^ (sec_r000205_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_300_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_300_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = (((stage_v_69_1 << 1) ^ (sec_r000205_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_301_2 = (((stage_v_69_2 << 1) ^ (sec_r000205_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_301_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_301_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_301_1 & 63;
  out_sink_2 ^= stage_v_301_2 & 63;
  int stage_v_302_1 = (((sec_r000205_14_1 << 2) ^ (sec_r000205_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_302_2 = (((sec_r000205_14_2 << 2) ^ (sec_r000205_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_302_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_302_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_302_1 & 63;
  out_sink_2 ^= stage_v_302_2 & 63;
  int stage_v_303_1 = (((stage_v_140_1 << 2) ^ (sec_r000205_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_303_2 = (((stage_v_140_2 << 2) ^ (sec_r000205_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_303_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_303_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_303_1 & 63;
  out_sink_2 ^= stage_v_303_2 & 63;
  int stage_v_304_1 = (((stage_v_127_1 << 2) ^ (sec_r000205_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_304_2 = (((stage_v_127_2 << 2) ^ (sec_r000205_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_304_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_304_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_304_1 & 63;
  out_sink_2 ^= stage_v_304_2 & 63;
  int stage_v_305_1 = (((stage_v_106_1 << 2) ^ (sec_r000205_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_305_2 = (((stage_v_106_2 << 2) ^ (sec_r000205_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_305_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_305_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_305_1 & 63;
  out_sink_2 ^= stage_v_305_2 & 63;
  int stage_v_306_1 = (((stage_v_176_1 << 1) ^ (sec_r000205_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_306_2 = (((stage_v_176_2 << 1) ^ (sec_r000205_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_306_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_306_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = (((sec_r000205_18_1 << 2) ^ (sec_r000205_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_307_2 = (((sec_r000205_18_2 << 2) ^ (sec_r000205_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_307_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_307_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_307_1 & 63;
  out_sink_2 ^= stage_v_307_2 & 63;
  int stage_v_308_1 = (((sec_r000205_20_1 << 2) ^ (sec_r000205_20_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_308_2 = (((sec_r000205_20_2 << 2) ^ (sec_r000205_20_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_308_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_308_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = (((stage_v_270_1 << 1) ^ (sec_r000205_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_309_2 = (((stage_v_270_2 << 1) ^ (sec_r000205_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_309_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_309_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = (((sec_r000205_5_1 << 1) ^ (sec_r000205_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_310_2 = (((sec_r000205_5_2 << 1) ^ (sec_r000205_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_310_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_310_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_310_1 & 63;
  out_sink_2 ^= stage_v_310_2 & 63;
  int stage_v_311_1 = (((stage_v_175_1 << 1) ^ (sec_r000205_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_311_2 = (((stage_v_175_2 << 1) ^ (sec_r000205_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_311_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_311_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = (((stage_v_213_1 << 2) ^ (sec_r000205_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_312_2 = (((stage_v_213_2 << 2) ^ (sec_r000205_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_312_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_312_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = (((sec_r000205_22_1 << 2) ^ (sec_r000205_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_313_2 = (((sec_r000205_22_2 << 2) ^ (sec_r000205_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_313_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_313_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = (((stage_v_271_1 << 1) ^ (sec_r000205_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_314_2 = (((stage_v_271_2 << 1) ^ (sec_r000205_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_314_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_314_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_314_1 & 63;
  out_sink_2 ^= stage_v_314_2 & 63;
  int stage_v_315_1 = (((stage_v_82_1 << 1) ^ (sec_r000205_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_315_2 = (((stage_v_82_2 << 1) ^ (sec_r000205_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_315_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_315_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_315_1 & 63;
  out_sink_2 ^= stage_v_315_2 & 63;
  int stage_v_316_1 = (((stage_v_315_1 << 1) ^ (sec_r000205_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_316_2 = (((stage_v_315_2 << 1) ^ (sec_r000205_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_316_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_316_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_316_1 & 63;
  out_sink_2 ^= stage_v_316_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000205_13_1 != sec_r000205_13_2);
  __CPROVER_assume(pub_r000205_9_1 == pub_r000205_9_2);
  __CPROVER_assume(pub_r000205_5_1 == pub_r000205_5_2);
  __CPROVER_assume(sec_r000205_4_1 != sec_r000205_4_2);
  __CPROVER_assume(pub_r000205_7_1 == pub_r000205_7_2);
  __CPROVER_assume(sec_r000205_11_1 != sec_r000205_11_2);
  __CPROVER_assume(pub_r000205_6_1 == pub_r000205_6_2);
  __CPROVER_assume(pub_r000205_8_1 == pub_r000205_8_2);
  __CPROVER_assume(pub_r000205_15_1 == pub_r000205_15_2);
  __CPROVER_assume(sec_r000205_6_1 != sec_r000205_6_2);
  __CPROVER_assume(sec_r000205_5_1 != sec_r000205_5_2);
  __CPROVER_assume(sec_r000205_19_1 != sec_r000205_19_2);
  __CPROVER_assume(sec_r000205_21_1 != sec_r000205_21_2);
  __CPROVER_assume(pub_r000205_16_1 == pub_r000205_16_2);
  __CPROVER_assume(sec_r000205_14_1 != sec_r000205_14_2);
  __CPROVER_assume(pub_r000205_14_1 == pub_r000205_14_2);
  __CPROVER_assume(pub_r000205_1_1 == pub_r000205_1_2);
  __CPROVER_assume(pub_r000205_17_1 == pub_r000205_17_2);
  __CPROVER_assume(sec_r000205_17_1 != sec_r000205_17_2);
  __CPROVER_assume(pub_r000205_2_1 == pub_r000205_2_2);
  __CPROVER_assume(sec_r000205_3_1 != sec_r000205_3_2);
  __CPROVER_assume(pub_r000205_10_1 == pub_r000205_10_2);
  __CPROVER_assume(pub_r000205_11_1 == pub_r000205_11_2);
  __CPROVER_assume(sec_r000205_23_1 != sec_r000205_23_2);
  __CPROVER_assume(pub_r000205_12_1 == pub_r000205_12_2);
  __CPROVER_assume(sec_r000205_18_1 != sec_r000205_18_2);
  __CPROVER_assume(sec_r000205_1_1 != sec_r000205_1_2);
  __CPROVER_assume(pub_r000205_13_1 == pub_r000205_13_2);
  __CPROVER_assume(sec_r000205_8_1 != sec_r000205_8_2);
  __CPROVER_assume(sec_r000205_22_1 != sec_r000205_22_2);
  __CPROVER_assume(sec_r000205_0_1 != sec_r000205_0_2);
  __CPROVER_assume(sec_r000205_20_1 != sec_r000205_20_2);
  __CPROVER_assume(pub_r000205_4_1 == pub_r000205_4_2);
  __CPROVER_assume(sec_r000205_16_1 != sec_r000205_16_2);
  __CPROVER_assume(sec_r000205_10_1 != sec_r000205_10_2);
  __CPROVER_assume(pub_r000205_3_1 == pub_r000205_3_2);
  __CPROVER_assume(sec_r000205_9_1 != sec_r000205_9_2);
  __CPROVER_assume(sec_r000205_2_1 != sec_r000205_2_2);
  __CPROVER_assume(sec_r000205_7_1 != sec_r000205_7_2);
  __CPROVER_assume(pub_r000205_0_1 == pub_r000205_0_2);
  __CPROVER_assume(sec_r000205_12_1 != sec_r000205_12_2);
  __CPROVER_assume(sec_r000205_15_1 != sec_r000205_15_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  assert(st_var_1_1.density == st_var_1_2.density);
  assert(st_var_1_1.stride == st_var_1_2.stride);
  assert(st_var_1_1.trace == st_var_1_2.trace);
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
}


