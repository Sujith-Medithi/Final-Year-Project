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
struct CipherContext_R000913_1313_0
{
  int iv;
  int round_key;
  int counter;
  int buffer[3];
};
struct Vector3D_R000913_1313_1
{
  int coord_y;
  int heading;
  short coord_z;
  unsigned char coord_x;
  unsigned char norm_sq;
  int buffer[3];
};
union TelemetryField_R000913_1313_0
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
void fn_R000913_1313_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st_1 = {0};
  struct CipherContext_R000913_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_96_1)
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

  switch (tally_96_2)
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
  int bound_81_1 = local_arr_1[aux_1 % 3];
  int bound_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_96_1 == tally_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_81_1 == bound_81_2);
}

int fn_R000913_1313_0(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_96 = (aux + st.buffer[1]) & 3;
  switch (tally_96)
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
  int bound_81 = local_arr[aux % 3];
  acc = (acc + (bound_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000913_1313_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st_1 = {0};
  struct CipherContext_R000913_1313_0 st_2 = {0};
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
  int factor_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_21_1) & 63;
  aux_2 = (aux_2 + factor_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_12_1 = local_arr_1[aux_1 % 3];
  int tracker_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_21_1 == factor_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_12_1 == tracker_12_2);
}

int fn_R000913_1313_1(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_21) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_12 = local_arr[aux % 3];
  acc = (acc + (tracker_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000913_1313_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st_1 = {0};
  struct CipherContext_R000913_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quotient_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_31_1)
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

  switch (quotient_31_2)
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

  int anchor_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_21_1) & 63;
  aux_2 = (aux_2 + anchor_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_87_1 = local_arr_1[aux_1 % 3];
  int parity_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_87_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_31_1 == quotient_31_2);
  assert(anchor_21_1 == anchor_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_87_1 == parity_87_2);
}

int fn_R000913_1313_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quotient_31 = (aux + st.buffer[1]) & 3;
  switch (quotient_31)
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

  int anchor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_21) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_87 = local_arr[aux % 3];
  acc = (acc + (parity_87 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000913_1313_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st_1 = {0};
  struct CipherContext_R000913_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int residue_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_69_1)
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

  switch (residue_69_2)
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

  int segment_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_33_1) & 63;
  aux_2 = (aux_2 + segment_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_26_1 > 13)
  {
    acc_1 = ((acc_1 + (weight_26_1 * 2)) + 5) & 127;
    aux_1 ^= weight_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_26_2 > 13)
  {
    acc_2 = ((acc_2 + (weight_26_2 * 2)) + 5) & 127;
    aux_2 ^= weight_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_26_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_69_1 == residue_69_2);
  assert(segment_33_1 == segment_33_2);
  assert(weight_26_1 == weight_26_2);
}

int fn_R000913_1313_3(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int residue_69 = (aux + st.buffer[1]) & 3;
  switch (residue_69)
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

  int segment_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_33) & 63;
  acc ^= aux;
  int weight_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_26 > 13)
  {
    acc = ((acc + (weight_26 * 2)) + 5) & 127;
    aux ^= weight_26 & 15;
  }
  else
  {
    acc = ((acc - weight_26) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000913_1313_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st_1 = {0};
  struct Vector3D_R000913_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int accumulator_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_42_1)
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

  switch (accumulator_42_2)
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

  int factor_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_26_1 > 44)
  {
    acc_1 = ((acc_1 + (factor_26_1 * 2)) + 5) & 127;
    aux_1 ^= factor_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_26_2 > 44)
  {
    acc_2 = ((acc_2 + (factor_26_2 * 2)) + 5) & 127;
    aux_2 ^= factor_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_26_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_42_1 == accumulator_42_2);
  assert(factor_26_1 == factor_26_2);
}

int fn_R000913_1313_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int accumulator_42 = (aux + st.buffer[1]) & 3;
  switch (accumulator_42)
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

  int factor_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_26 > 44)
  {
    acc = ((acc + (factor_26 * 2)) + 5) & 127;
    aux ^= factor_26 & 15;
  }
  else
  {
    acc = ((acc - factor_26) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000913_1313_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st_1 = {0};
  struct Vector3D_R000913_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_70_1) & 63;
  aux_2 = (aux_2 + offset_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_70_1 == offset_70_2);
}

int fn_R000913_1313_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_70) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000913_1313_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st_1 = {0};
  struct Vector3D_R000913_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int weight_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_95_1)
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

  switch (weight_95_2)
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

  int window_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_31_1) & 63;
  aux_2 = (aux_2 + window_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_95_1 == weight_95_2);
  assert(window_31_1 == window_31_2);
}

int fn_R000913_1313_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int weight_95 = (aux + st.buffer[1]) & 3;
  switch (weight_95)
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

  int window_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000913_1313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st_1 = {0};
  struct CipherContext_R000913_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int accumulator_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_65_1 > 43)
  {
    acc_1 = ((acc_1 + (accumulator_65_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_65_2 > 43)
  {
    acc_2 = ((acc_2 + (accumulator_65_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_49_1) & 63;
  aux_2 = (aux_2 + quantum_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_52_1 = local_arr_1[aux_1 % 3];
  int residue_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_65_1 == accumulator_65_2);
  assert(quantum_49_1 == quantum_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_52_1 == residue_52_2);
}

int fn_R000913_1313_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int accumulator_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_65 > 43)
  {
    acc = ((acc + (accumulator_65 * 2)) + 5) & 127;
    aux ^= accumulator_65 & 15;
  }
  else
  {
    acc = ((acc - accumulator_65) + 11) & 127;
    aux += 3;
  }
  int quantum_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_49) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_52 = local_arr[aux % 3];
  acc = (acc + (residue_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000913_1313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st_1 = {0};
  struct CipherContext_R000913_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int tracker_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_41_1 > 25)
  {
    acc_1 = ((acc_1 + (tracker_41_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_41_2 > 25)
  {
    acc_2 = ((acc_2 + (tracker_41_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_41_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_63_1) & 63;
  aux_2 = (aux_2 + residue_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_41_1 == tracker_41_2);
  assert(residue_63_1 == residue_63_2);
}

int fn_R000913_1313_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int tracker_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_41 > 25)
  {
    acc = ((acc + (tracker_41 * 2)) + 5) & 127;
    aux ^= tracker_41 & 15;
  }
  else
  {
    acc = ((acc - tracker_41) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_63) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000913_1313_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st_1 = {0};
  struct CipherContext_R000913_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_63_1)
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

  switch (segment_63_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_63_1 == segment_63_2);
}

int fn_R000913_1313_9(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_63 = (aux + st.buffer[1]) & 3;
  switch (segment_63)
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

void fn_R000913_1313_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st_1 = {0};
  struct Vector3D_R000913_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int residue_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_28_1) & 63;
  aux_2 = (aux_2 + residue_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_88_1)
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

  switch (offset_88_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_28_1 == residue_28_2);
  assert(offset_88_1 == offset_88_2);
}

int fn_R000913_1313_10(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int residue_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_28) & 63;
  acc ^= aux;
  int offset_88 = (aux + st.buffer[1]) & 3;
  switch (offset_88)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000913_1313_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st_1 = {0};
  struct CipherContext_R000913_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int coefficient_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_65_1 > 17)
  {
    acc_1 = ((acc_1 + (coefficient_65_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_65_2 > 17)
  {
    acc_2 = ((acc_2 + (coefficient_65_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_74_1)
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

  switch (segment_74_2)
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
  int margin_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_49_1) & 63;
  aux_2 = (aux_2 + margin_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_65_1 == coefficient_65_2);
  assert(segment_74_1 == segment_74_2);
  assert(margin_49_1 == margin_49_2);
}

int fn_R000913_1313_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int coefficient_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_65 > 17)
  {
    acc = ((acc + (coefficient_65 * 2)) + 5) & 127;
    aux ^= coefficient_65 & 15;
  }
  else
  {
    acc = ((acc - coefficient_65) + 11) & 127;
    aux += 3;
  }
  int segment_74 = (aux + st.buffer[1]) & 3;
  switch (segment_74)
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
  int margin_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_49) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000913_1313_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st_1 = {0};
  struct CipherContext_R000913_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_20_1 = local_arr_1[aux_1 % 3];
  int parity_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_20_2 * 2)) & 127;
  int coefficient_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_50_1) & 63;
  aux_2 = (aux_2 + coefficient_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_96_1)
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

  switch (quantum_96_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_20_1 == parity_20_2);
  assert(coefficient_50_1 == coefficient_50_2);
  assert(quantum_96_1 == quantum_96_2);
}

int fn_R000913_1313_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int parity_20 = local_arr[aux % 3];
  acc = (acc + (parity_20 * 2)) & 127;
  int coefficient_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_50) & 63;
  acc ^= aux;
  int quantum_96 = (aux + st.buffer[1]) & 3;
  switch (quantum_96)
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

void fn_R000913_1313_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st_1 = {0};
  struct CipherContext_R000913_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int margin_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_94_1 > 45)
  {
    acc_1 = ((acc_1 + (margin_94_1 * 2)) + 5) & 127;
    aux_1 ^= margin_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_94_2 > 45)
  {
    acc_2 = ((acc_2 + (margin_94_2 * 2)) + 5) & 127;
    aux_2 ^= margin_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_10_1)
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

  switch (checksum_10_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_94_1 == margin_94_2);
  assert(checksum_10_1 == checksum_10_2);
}

int fn_R000913_1313_13(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int margin_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_94 > 45)
  {
    acc = ((acc + (margin_94 * 2)) + 5) & 127;
    aux ^= margin_94 & 15;
  }
  else
  {
    acc = ((acc - margin_94) + 11) & 127;
    aux += 3;
  }
  int checksum_10 = (aux + st.buffer[1]) & 3;
  switch (checksum_10)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000913_1313_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st_1 = {0};
  struct Vector3D_R000913_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int threshold_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_57_1) & 63;
  aux_2 = (aux_2 + threshold_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_57_1 == threshold_57_2);
}

int fn_R000913_1313_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int threshold_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_57) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000913_1313_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st_1 = {0};
  struct Vector3D_R000913_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int quantum_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_30_1)
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

  switch (quantum_30_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_30_1 == quantum_30_2);
}

int fn_R000913_1313_15(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int quantum_30 = (aux + st.buffer[1]) & 3;
  switch (quantum_30)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000913_1313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st_1 = {0};
  struct Vector3D_R000913_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_29_1 = local_arr_1[aux_1 % 3];
  int coefficient_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_29_2 * 2)) & 127;
  int pivot_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_76_1 > 42)
  {
    acc_1 = ((acc_1 + (pivot_76_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_76_2 > 42)
  {
    acc_2 = ((acc_2 + (pivot_76_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_26_1) & 63;
  aux_2 = (aux_2 + metric_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_29_1)
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

  switch (cursor_29_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_29_1 == coefficient_29_2);
  assert(pivot_76_1 == pivot_76_2);
  assert(metric_26_1 == metric_26_2);
  assert(cursor_29_1 == cursor_29_2);
}

int fn_R000913_1313_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int coefficient_29 = local_arr[aux % 3];
  acc = (acc + (coefficient_29 * 2)) & 127;
  int pivot_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_76 > 42)
  {
    acc = ((acc + (pivot_76 * 2)) + 5) & 127;
    aux ^= pivot_76 & 15;
  }
  else
  {
    acc = ((acc - pivot_76) + 11) & 127;
    aux += 3;
  }
  int metric_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_26) & 63;
  acc ^= aux;
  int cursor_29 = (aux + st.buffer[1]) & 3;
  switch (cursor_29)
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

void fn_R000913_1313_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st_1 = {0};
  struct Vector3D_R000913_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int coefficient_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_50_1) & 63;
  aux_2 = (aux_2 + coefficient_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_15_1 > 10)
  {
    acc_1 = ((acc_1 + (scale_15_1 * 2)) + 5) & 127;
    aux_1 ^= scale_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_15_2 > 10)
  {
    acc_2 = ((acc_2 + (scale_15_2 * 2)) + 5) & 127;
    aux_2 ^= scale_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_15_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_50_1 == coefficient_50_2);
  assert(scale_15_1 == scale_15_2);
}

int fn_R000913_1313_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int coefficient_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_50) & 63;
  acc ^= aux;
  int scale_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_15 > 10)
  {
    acc = ((acc + (scale_15 * 2)) + 5) & 127;
    aux ^= scale_15 & 15;
  }
  else
  {
    acc = ((acc - scale_15) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000913_1313_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st_1 = {0};
  struct Vector3D_R000913_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_73_1) & 63;
  aux_2 = (aux_2 + threshold_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_73_1 == threshold_73_2);
}

int fn_R000913_1313_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_73) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000913_1313_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st_1 = {0};
  struct CipherContext_R000913_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int stride_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_76_1 > 49)
  {
    acc_1 = ((acc_1 + (stride_76_1 * 2)) + 5) & 127;
    aux_1 ^= stride_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_76_2 > 49)
  {
    acc_2 = ((acc_2 + (stride_76_2 * 2)) + 5) & 127;
    aux_2 ^= stride_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_76_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_32_1 = local_arr_1[aux_1 % 3];
  int delta_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_76_1 == stride_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_32_1 == delta_32_2);
}

int fn_R000913_1313_19(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int stride_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_76 > 49)
  {
    acc = ((acc + (stride_76 * 2)) + 5) & 127;
    aux ^= stride_76 & 15;
  }
  else
  {
    acc = ((acc - stride_76) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_32 = local_arr[aux % 3];
  acc = (acc + (delta_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000913_1313_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st_1 = {0};
  struct Vector3D_R000913_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_22_1 = local_arr_1[aux_1 % 3];
  int metric_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_22_2 * 2)) & 127;
  int threshold_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_58_1) & 63;
  aux_2 = (aux_2 + threshold_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_22_1 == metric_22_2);
  assert(threshold_58_1 == threshold_58_2);
}

int fn_R000913_1313_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000913_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int metric_22 = local_arr[aux % 3];
  acc = (acc + (metric_22 * 2)) & 127;
  int threshold_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_58) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000913_1313_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st_1 = {0};
  struct CipherContext_R000913_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int tally_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_65_1)
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

  switch (tally_65_2)
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

  int damping_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_34_1) & 63;
  aux_2 = (aux_2 + damping_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_65_1 == tally_65_2);
  assert(damping_34_1 == damping_34_2);
}

int fn_R000913_1313_21(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000913_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int tally_65 = (aux + st.buffer[1]) & 3;
  switch (tally_65)
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

  int damping_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_34) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000913_0_1;
  int sec_r000913_0_2;
  int sec_r000913_1_1;
  int sec_r000913_1_2;
  int sec_r000913_2_1;
  int sec_r000913_2_2;
  int sec_r000913_3_1;
  int sec_r000913_3_2;
  int sec_r000913_4_1;
  int sec_r000913_4_2;
  int sec_r000913_5_1;
  int sec_r000913_5_2;
  int sec_r000913_6_1;
  int sec_r000913_6_2;
  int sec_r000913_7_1;
  int sec_r000913_7_2;
  int sec_r000913_8_1;
  int sec_r000913_8_2;
  int sec_r000913_9_1;
  int sec_r000913_9_2;
  int sec_r000913_10_1;
  int sec_r000913_10_2;
  int sec_r000913_11_1;
  int sec_r000913_11_2;
  int sec_r000913_12_1;
  int sec_r000913_12_2;
  int sec_r000913_13_1;
  int sec_r000913_13_2;
  int sec_r000913_14_1;
  int sec_r000913_14_2;
  int sec_r000913_15_1;
  int sec_r000913_15_2;
  int sec_r000913_16_1;
  int sec_r000913_16_2;
  int pub_r000913_0_1;
  int pub_r000913_0_2;
  int pub_r000913_1_1;
  int pub_r000913_1_2;
  int pub_r000913_2_1;
  int pub_r000913_2_2;
  int pub_r000913_3_1;
  int pub_r000913_3_2;
  int pub_r000913_4_1;
  int pub_r000913_4_2;
  int pub_r000913_5_1;
  int pub_r000913_5_2;
  int pub_r000913_6_1;
  int pub_r000913_6_2;
  int pub_r000913_7_1;
  int pub_r000913_7_2;
  int pub_r000913_8_1;
  int pub_r000913_8_2;
  int pub_r000913_9_1;
  int pub_r000913_9_2;
  int pub_r000913_10_1;
  int pub_r000913_10_2;
  int pub_r000913_11_1;
  int pub_r000913_11_2;
  int pub_r000913_12_1;
  int pub_r000913_12_2;
  int pub_r000913_13_1;
  int pub_r000913_13_2;
  int pub_r000913_14_1;
  int pub_r000913_14_2;
  int pub_r000913_15_1;
  int pub_r000913_15_2;
  int pub_r000913_16_1;
  int pub_r000913_16_2;
  int pub_r000913_17_1;
  int pub_r000913_17_2;
  int pub_r000913_18_1;
  int pub_r000913_18_2;
  int pub_r000913_19_1;
  int pub_r000913_19_2;
  int pub_r000913_20_1;
  int pub_r000913_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000913_0_1 >= (-100)) && (pub_r000913_0_1 <= 100));
  __CPROVER_assume((pub_r000913_0_2 >= (-100)) && (pub_r000913_0_2 <= 100));
  __CPROVER_assume((pub_r000913_1_1 >= (-100)) && (pub_r000913_1_1 <= 100));
  __CPROVER_assume((pub_r000913_1_2 >= (-100)) && (pub_r000913_1_2 <= 100));
  __CPROVER_assume((pub_r000913_2_1 >= (-100)) && (pub_r000913_2_1 <= 100));
  __CPROVER_assume((pub_r000913_2_2 >= (-100)) && (pub_r000913_2_2 <= 100));
  __CPROVER_assume((pub_r000913_3_1 >= (-100)) && (pub_r000913_3_1 <= 100));
  __CPROVER_assume((pub_r000913_3_2 >= (-100)) && (pub_r000913_3_2 <= 100));
  __CPROVER_assume((pub_r000913_4_1 >= (-100)) && (pub_r000913_4_1 <= 100));
  __CPROVER_assume((pub_r000913_4_2 >= (-100)) && (pub_r000913_4_2 <= 100));
  __CPROVER_assume((pub_r000913_5_1 >= (-100)) && (pub_r000913_5_1 <= 100));
  __CPROVER_assume((pub_r000913_5_2 >= (-100)) && (pub_r000913_5_2 <= 100));
  __CPROVER_assume((pub_r000913_6_1 >= (-100)) && (pub_r000913_6_1 <= 100));
  __CPROVER_assume((pub_r000913_6_2 >= (-100)) && (pub_r000913_6_2 <= 100));
  __CPROVER_assume((pub_r000913_7_1 >= (-100)) && (pub_r000913_7_1 <= 100));
  __CPROVER_assume((pub_r000913_7_2 >= (-100)) && (pub_r000913_7_2 <= 100));
  __CPROVER_assume((pub_r000913_8_1 >= (-100)) && (pub_r000913_8_1 <= 100));
  __CPROVER_assume((pub_r000913_8_2 >= (-100)) && (pub_r000913_8_2 <= 100));
  __CPROVER_assume((pub_r000913_9_1 >= (-100)) && (pub_r000913_9_1 <= 100));
  __CPROVER_assume((pub_r000913_9_2 >= (-100)) && (pub_r000913_9_2 <= 100));
  __CPROVER_assume((pub_r000913_10_1 >= (-100)) && (pub_r000913_10_1 <= 100));
  __CPROVER_assume((pub_r000913_10_2 >= (-100)) && (pub_r000913_10_2 <= 100));
  __CPROVER_assume((pub_r000913_11_1 >= (-100)) && (pub_r000913_11_1 <= 100));
  __CPROVER_assume((pub_r000913_11_2 >= (-100)) && (pub_r000913_11_2 <= 100));
  __CPROVER_assume((pub_r000913_12_1 >= (-100)) && (pub_r000913_12_1 <= 100));
  __CPROVER_assume((pub_r000913_12_2 >= (-100)) && (pub_r000913_12_2 <= 100));
  __CPROVER_assume((pub_r000913_13_1 >= (-100)) && (pub_r000913_13_1 <= 100));
  __CPROVER_assume((pub_r000913_13_2 >= (-100)) && (pub_r000913_13_2 <= 100));
  __CPROVER_assume((pub_r000913_14_1 >= (-100)) && (pub_r000913_14_1 <= 100));
  __CPROVER_assume((pub_r000913_14_2 >= (-100)) && (pub_r000913_14_2 <= 100));
  __CPROVER_assume((pub_r000913_15_1 >= (-100)) && (pub_r000913_15_1 <= 100));
  __CPROVER_assume((pub_r000913_15_2 >= (-100)) && (pub_r000913_15_2 <= 100));
  __CPROVER_assume((pub_r000913_16_1 >= (-100)) && (pub_r000913_16_1 <= 100));
  __CPROVER_assume((pub_r000913_16_2 >= (-100)) && (pub_r000913_16_2 <= 100));
  __CPROVER_assume((pub_r000913_17_1 >= (-100)) && (pub_r000913_17_1 <= 100));
  __CPROVER_assume((pub_r000913_17_2 >= (-100)) && (pub_r000913_17_2 <= 100));
  __CPROVER_assume((pub_r000913_18_1 >= (-100)) && (pub_r000913_18_1 <= 100));
  __CPROVER_assume((pub_r000913_18_2 >= (-100)) && (pub_r000913_18_2 <= 100));
  __CPROVER_assume((pub_r000913_19_1 >= (-100)) && (pub_r000913_19_1 <= 100));
  __CPROVER_assume((pub_r000913_19_2 >= (-100)) && (pub_r000913_19_2 <= 100));
  __CPROVER_assume((pub_r000913_20_1 >= (-100)) && (pub_r000913_20_1 <= 100));
  __CPROVER_assume((pub_r000913_20_2 >= (-100)) && (pub_r000913_20_2 <= 100));
  __CPROVER_assume((sec_r000913_0_1 >= 0) && (sec_r000913_0_1 <= 255));
  __CPROVER_assume((sec_r000913_0_2 >= 0) && (sec_r000913_0_2 <= 255));
  __CPROVER_assume((sec_r000913_1_1 >= 0) && (sec_r000913_1_1 <= 255));
  __CPROVER_assume((sec_r000913_1_2 >= 0) && (sec_r000913_1_2 <= 255));
  __CPROVER_assume((sec_r000913_2_1 >= 0) && (sec_r000913_2_1 <= 255));
  __CPROVER_assume((sec_r000913_2_2 >= 0) && (sec_r000913_2_2 <= 255));
  __CPROVER_assume((sec_r000913_3_1 >= 0) && (sec_r000913_3_1 <= 255));
  __CPROVER_assume((sec_r000913_3_2 >= 0) && (sec_r000913_3_2 <= 255));
  __CPROVER_assume((sec_r000913_4_1 >= 0) && (sec_r000913_4_1 <= 255));
  __CPROVER_assume((sec_r000913_4_2 >= 0) && (sec_r000913_4_2 <= 255));
  __CPROVER_assume((sec_r000913_5_1 >= 0) && (sec_r000913_5_1 <= 255));
  __CPROVER_assume((sec_r000913_5_2 >= 0) && (sec_r000913_5_2 <= 255));
  __CPROVER_assume((sec_r000913_6_1 >= 0) && (sec_r000913_6_1 <= 255));
  __CPROVER_assume((sec_r000913_6_2 >= 0) && (sec_r000913_6_2 <= 255));
  __CPROVER_assume((sec_r000913_7_1 >= 0) && (sec_r000913_7_1 <= 255));
  __CPROVER_assume((sec_r000913_7_2 >= 0) && (sec_r000913_7_2 <= 255));
  __CPROVER_assume((sec_r000913_8_1 >= 0) && (sec_r000913_8_1 <= 255));
  __CPROVER_assume((sec_r000913_8_2 >= 0) && (sec_r000913_8_2 <= 255));
  __CPROVER_assume((sec_r000913_9_1 >= 0) && (sec_r000913_9_1 <= 255));
  __CPROVER_assume((sec_r000913_9_2 >= 0) && (sec_r000913_9_2 <= 255));
  __CPROVER_assume((sec_r000913_10_1 >= 0) && (sec_r000913_10_1 <= 255));
  __CPROVER_assume((sec_r000913_10_2 >= 0) && (sec_r000913_10_2 <= 255));
  __CPROVER_assume((sec_r000913_11_1 >= 0) && (sec_r000913_11_1 <= 255));
  __CPROVER_assume((sec_r000913_11_2 >= 0) && (sec_r000913_11_2 <= 255));
  __CPROVER_assume((sec_r000913_12_1 >= 0) && (sec_r000913_12_1 <= 255));
  __CPROVER_assume((sec_r000913_12_2 >= 0) && (sec_r000913_12_2 <= 255));
  __CPROVER_assume((sec_r000913_13_1 >= 0) && (sec_r000913_13_1 <= 255));
  __CPROVER_assume((sec_r000913_13_2 >= 0) && (sec_r000913_13_2 <= 255));
  __CPROVER_assume((sec_r000913_14_1 >= 0) && (sec_r000913_14_1 <= 255));
  __CPROVER_assume((sec_r000913_14_2 >= 0) && (sec_r000913_14_2 <= 255));
  __CPROVER_assume((sec_r000913_15_1 >= 0) && (sec_r000913_15_1 <= 255));
  __CPROVER_assume((sec_r000913_15_2 >= 0) && (sec_r000913_15_2 <= 255));
  __CPROVER_assume((sec_r000913_16_1 >= 0) && (sec_r000913_16_1 <= 255));
  __CPROVER_assume((sec_r000913_16_2 >= 0) && (sec_r000913_16_2 <= 255));
  struct CipherContext_R000913_1313_0 st_var_0_1 = {0};
  struct CipherContext_R000913_1313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000913_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000913_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000913_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000913_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000913_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000913_0_2 + 7) & 15;
  struct Vector3D_R000913_1313_1 st_var_1_1 = {0};
  struct Vector3D_R000913_1313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000913_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000913_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000913_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000913_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000913_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000913_0_2 + 9) & 15;
  union TelemetryField_R000913_1313_0 u_var_1;
  union TelemetryField_R000913_1313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_0_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_0_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_0_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_4_1 = ((stage_v_4_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_4_2 = ((stage_v_4_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (st_var_1_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_1_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = ((st_var_1_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_1_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 51)
    {
      chk_sum_1 ^= stage_v_11_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_11_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 51)
    {
      chk_sum_2 ^= stage_v_11_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = ((st_var_0_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_0_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 36)
    {
      chk_sum_1 ^= stage_v_14_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_14_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 36)
    {
      chk_sum_2 ^= stage_v_14_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 16) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = table_1[0];
  int stage_v_16_2 = table_2[0];
  table_1[0] = (table_1[1] + 33) & 63;
  table_2[0] = (table_2[1] + 33) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (st_var_1_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_1_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  int stage_v_19_1 = ((st_var_1_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_1_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 39)
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
  if (stage_v_19_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 39)
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
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (st_var_0_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_0_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = (st_var_1_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_1_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 27) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (st_var_0_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_0_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 30) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 30) & 15;
  int stage_v_29_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_29_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= stage_v_29_1;
  chk_sum_2 ^= stage_v_29_2;
  int stage_v_30_1 = ((st_var_0_1.buffer[0] * 2) + 97) & 63;
  int stage_v_30_2 = ((st_var_0_2.buffer[0] * 2) + 97) & 63;
  if (stage_v_30_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_30_1) - 5) & 255;
    if (stage_v_30_1 > 34)
    {
      chk_sum_1 ^= stage_v_30_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_30_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_30_2) - 5) & 255;
    if (stage_v_30_2 > 34)
    {
      chk_sum_2 ^= stage_v_30_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = (st_var_0_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_0_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
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

  switch (stage_v_32_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 34) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  int stage_v_37_1 = (st_var_1_1.buffer[0] ^ 40) & 3;
  int stage_v_37_2 = (st_var_1_2.buffer[0] ^ 40) & 3;
  switch (stage_v_37_1)
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

  switch (stage_v_37_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 39) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  int stage_v_39_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_39_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_40_1 = (st_var_0_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_0_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 44) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  int stage_v_44_1 = table_1[0];
  int stage_v_44_2 = table_2[0];
  table_1[0] = (table_1[1] + 89) & 63;
  table_2[0] = (table_2[1] + 89) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 47) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 47) & 15;
  int stage_v_46_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_46_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= stage_v_46_1;
  chk_sum_2 ^= stage_v_46_2;
  int stage_v_47_1 = (st_var_1_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_1_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
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

  switch (stage_v_47_2)
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

  int stage_v_48_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_48_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 49)
    {
      chk_sum_1 ^= stage_v_49_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_49_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 49)
    {
      chk_sum_2 ^= stage_v_49_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 51) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 51) & 15;
  int stage_v_50_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_50_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= stage_v_50_1;
  chk_sum_2 ^= stage_v_50_2;
  int stage_v_51_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (56 & 31);
  int stage_v_51_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (56 & 31);
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= (stage_v_51_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_51_2 << 1) & 127;
  int stage_v_52_1 = table_1[0];
  int stage_v_52_2 = table_2[0];
  table_1[0] = (table_1[1] + 105) & 63;
  table_2[0] = (table_2[1] + 105) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
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
  int stage_v_54_1 = ((st_var_0_1.buffer[0] * 2) + 169) & 63;
  int stage_v_54_2 = ((st_var_0_2.buffer[0] * 2) + 169) & 63;
  if (stage_v_54_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_54_1) - 5) & 255;
    if (stage_v_54_1 > 52)
    {
      chk_sum_1 ^= stage_v_54_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_54_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_54_2) - 5) & 255;
    if (stage_v_54_2 > 52)
    {
      chk_sum_2 ^= stage_v_54_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_55_1 = (st_var_1_1.buffer[0] ^ 58) & 3;
  int stage_v_55_2 = (st_var_1_2.buffer[0] ^ 58) & 3;
  switch (stage_v_55_1)
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

  switch (stage_v_55_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 57) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 57) & 15;
  int stage_v_56_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_56_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= stage_v_56_1;
  chk_sum_2 ^= stage_v_56_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 58) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= stage_v_57_1;
  chk_sum_2 ^= stage_v_57_2;
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_59_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 63) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 63) & 15;
  int stage_v_62_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_62_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= stage_v_62_1;
  chk_sum_2 ^= stage_v_62_2;
  int stage_v_63_1 = table_1[3];
  int stage_v_63_2 = table_2[3];
  table_1[3] = (table_1[0] + 127) & 63;
  table_2[3] = (table_2[0] + 127) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_64_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_65_1 = ((stage_v_65_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((st_var_1_1.buffer[1] * 2) + 208) & 63;
  int stage_v_67_2 = ((st_var_1_2.buffer[1] * 2) + 208) & 63;
  if (stage_v_67_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_67_1) - 5) & 255;
    if (stage_v_67_1 > 28)
    {
      chk_sum_1 ^= stage_v_67_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_67_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_67_2) - 5) & 255;
    if (stage_v_67_2 > 28)
    {
      chk_sum_2 ^= stage_v_67_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_68_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_68_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_68_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_68_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_69_1 = ((st_var_1_1.buffer[0] * 2) + 214) & 63;
  int stage_v_69_2 = ((st_var_1_2.buffer[0] * 2) + 214) & 63;
  if (stage_v_69_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_69_1) - 5) & 255;
    if (stage_v_69_1 > 49)
    {
      chk_sum_1 ^= stage_v_69_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_69_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_69_2) - 5) & 255;
    if (stage_v_69_2 > 49)
    {
      chk_sum_2 ^= stage_v_69_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_70_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (75 & 31);
  int stage_v_70_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (75 & 31);
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= (stage_v_70_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_70_2 << 1) & 127;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_71_1 = ((stage_v_71_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_71_2 = ((stage_v_71_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_72_1 = ((stage_v_72_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_72_2 = ((stage_v_72_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 74) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 74) & 15;
  int stage_v_73_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_73_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= stage_v_73_1;
  chk_sum_2 ^= stage_v_73_2;
  int stage_v_74_1 = (st_var_0_1.buffer[0] ^ 77) & 3;
  int stage_v_74_2 = (st_var_0_2.buffer[0] ^ 77) & 3;
  switch (stage_v_74_1)
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

  switch (stage_v_74_2)
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

  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((st_var_0_1.buffer[1] * 2) + 235) & 63;
  int stage_v_76_2 = ((st_var_0_2.buffer[1] * 2) + 235) & 63;
  if (stage_v_76_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_76_1) - 5) & 255;
    if (stage_v_76_1 > 49)
    {
      chk_sum_1 ^= stage_v_76_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_76_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_76_2) - 5) & 255;
    if (stage_v_76_2 > 49)
    {
      chk_sum_2 ^= stage_v_76_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_77_1 = (st_var_1_1.buffer[0] ^ 80) & 3;
  int stage_v_77_2 = (st_var_1_2.buffer[0] ^ 80) & 3;
  switch (stage_v_77_1)
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

  switch (stage_v_77_2)
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

  int stage_v_78_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (83 & 31);
  int stage_v_78_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (83 & 31);
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= (stage_v_78_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_78_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 80) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 80) & 15;
  int stage_v_79_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_79_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  chk_sum_1 ^= stage_v_79_1;
  chk_sum_2 ^= stage_v_79_2;
  int stage_v_80_1 = ((st_var_0_1.buffer[2] * 2) + 247) & 63;
  int stage_v_80_2 = ((st_var_0_2.buffer[2] * 2) + 247) & 63;
  if (stage_v_80_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_80_1) - 5) & 255;
    if (stage_v_80_1 > 45)
    {
      chk_sum_1 ^= stage_v_80_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_80_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_80_2) - 5) & 255;
    if (stage_v_80_2 > 45)
    {
      chk_sum_2 ^= stage_v_80_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (st_var_0_1.buffer[0] ^ 85) & 3;
  int stage_v_82_2 = (st_var_0_2.buffer[0] ^ 85) & 3;
  switch (stage_v_82_1)
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

  switch (stage_v_82_2)
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

  int stage_v_83_1 = ((st_var_1_1.buffer[2] * 2) + 256) & 63;
  int stage_v_83_2 = ((st_var_1_2.buffer[2] * 2) + 256) & 63;
  if (stage_v_83_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_83_1) - 5) & 255;
    if (stage_v_83_1 > 34)
    {
      chk_sum_1 ^= stage_v_83_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_83_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_83_2) - 5) & 255;
    if (stage_v_83_2 > 34)
    {
      chk_sum_2 ^= stage_v_83_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_84_1 = ((stage_v_84_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_84_2 = ((stage_v_84_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 86) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 86) & 15;
  int stage_v_85_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_85_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= stage_v_85_1;
  chk_sum_2 ^= stage_v_85_2;
  int stage_v_86_1 = (st_var_0_1.buffer[0] ^ 89) & 3;
  int stage_v_86_2 = (st_var_0_2.buffer[0] ^ 89) & 3;
  switch (stage_v_86_1)
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

  switch (stage_v_86_2)
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

  int stage_v_87_1 = ((st_var_1_1.buffer[0] * 2) + 268) & 63;
  int stage_v_87_2 = ((st_var_1_2.buffer[0] * 2) + 268) & 63;
  if (stage_v_87_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_87_1) - 5) & 255;
    if (stage_v_87_1 > 41)
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
  if (stage_v_87_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_87_2) - 5) & 255;
    if (stage_v_87_2 > 41)
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
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_88_1 = ((stage_v_88_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_88_2 = ((stage_v_88_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (94 & 31);
  int stage_v_89_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (94 & 31);
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= (stage_v_89_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_89_2 << 1) & 127;
  int sub_step_90_1 = ((sec_r000913_4_1 + pub_r000913_20_1) + 29) & 127;
  int sub_step_90_2 = ((sec_r000913_4_2 + pub_r000913_20_2) + 29) & 127;
  int stage_v_90_1 = ((sub_step_90_1 * 2) + pub_r000913_8_1) & 127;
  int stage_v_90_2 = ((sub_step_90_2 * 2) + pub_r000913_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_90_1 & 15;
  st_var_0_2.buffer[0] = stage_v_90_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int sub_step_91_1 = ((sec_r000913_2_1 + pub_r000913_0_1) + 18) & 127;
  int sub_step_91_2 = ((sec_r000913_2_2 + pub_r000913_0_2) + 18) & 127;
  int stage_v_91_1 = ((sub_step_91_1 * 2) + pub_r000913_15_1) & 127;
  int stage_v_91_2 = ((sub_step_91_2 * 2) + pub_r000913_15_2) & 127;
  st_var_1_1.buffer[1] = stage_v_91_1 & 15;
  st_var_1_2.buffer[1] = stage_v_91_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int sub_step_92_1 = ((stage_v_90_1 + pub_r000913_10_1) + 19) & 127;
  int sub_step_92_2 = ((stage_v_90_2 + pub_r000913_10_2) + 19) & 127;
  int stage_v_92_1 = ((sub_step_92_1 * 2) + pub_r000913_5_1) & 127;
  int stage_v_92_2 = ((sub_step_92_2 * 2) + pub_r000913_5_2) & 127;
  st_var_0_1.buffer[2] = stage_v_92_1 & 15;
  st_var_0_2.buffer[2] = stage_v_92_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int sub_step_93_1 = ((sub_step_91_1 + pub_r000913_10_1) + 31) & 127;
  int sub_step_93_2 = ((sub_step_91_2 + pub_r000913_10_2) + 31) & 127;
  int stage_v_93_1 = ((sub_step_93_1 * 2) + pub_r000913_14_1) & 127;
  int stage_v_93_2 = ((sub_step_93_2 * 2) + pub_r000913_14_2) & 127;
  st_var_1_1.buffer[0] = stage_v_93_1 & 15;
  st_var_1_2.buffer[0] = stage_v_93_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int sub_step_94_1 = ((stage_v_91_1 + pub_r000913_19_1) + 13) & 127;
  int sub_step_94_2 = ((stage_v_91_2 + pub_r000913_19_2) + 13) & 127;
  int stage_v_94_1 = ((sub_step_94_1 * 2) + pub_r000913_4_1) & 127;
  int stage_v_94_2 = ((sub_step_94_2 * 2) + pub_r000913_4_2) & 127;
  st_var_0_1.buffer[1] = stage_v_94_1 & 15;
  st_var_0_2.buffer[1] = stage_v_94_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int sub_step_95_1 = ((stage_v_93_1 + pub_r000913_20_1) + 9) & 127;
  int sub_step_95_2 = ((stage_v_93_2 + pub_r000913_20_2) + 9) & 127;
  int stage_v_95_1 = ((sub_step_95_1 * 2) + pub_r000913_14_1) & 127;
  int stage_v_95_2 = ((sub_step_95_2 * 2) + pub_r000913_14_2) & 127;
  st_var_1_1.buffer[2] = stage_v_95_1 & 15;
  st_var_1_2.buffer[2] = stage_v_95_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int sub_step_96_1 = ((stage_v_90_1 + pub_r000913_1_1) + 11) & 127;
  int sub_step_96_2 = ((stage_v_90_2 + pub_r000913_1_2) + 11) & 127;
  int stage_v_96_1 = ((sub_step_96_1 * 2) + pub_r000913_13_1) & 127;
  int stage_v_96_2 = ((sub_step_96_2 * 2) + pub_r000913_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_96_1 & 15;
  st_var_0_2.buffer[0] = stage_v_96_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int sub_step_97_1 = ((stage_v_91_1 + pub_r000913_0_1) + 11) & 127;
  int sub_step_97_2 = ((stage_v_91_2 + pub_r000913_0_2) + 11) & 127;
  int stage_v_97_1 = ((sub_step_97_1 * 2) + pub_r000913_4_1) & 127;
  int stage_v_97_2 = ((sub_step_97_2 * 2) + pub_r000913_4_2) & 127;
  st_var_1_1.buffer[1] = stage_v_97_1 & 15;
  st_var_1_2.buffer[1] = stage_v_97_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int sub_step_98_1 = ((stage_v_95_1 + pub_r000913_3_1) + 18) & 127;
  int sub_step_98_2 = ((stage_v_95_2 + pub_r000913_3_2) + 18) & 127;
  int stage_v_98_1 = ((sub_step_98_1 * 2) + pub_r000913_20_1) & 127;
  int stage_v_98_2 = ((sub_step_98_2 * 2) + pub_r000913_20_2) & 127;
  st_var_0_1.buffer[2] = stage_v_98_1 & 15;
  st_var_0_2.buffer[2] = stage_v_98_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int sub_step_99_1 = ((sec_r000913_15_1 + pub_r000913_17_1) + 35) & 127;
  int sub_step_99_2 = ((sec_r000913_15_2 + pub_r000913_17_2) + 35) & 127;
  int stage_v_99_1 = ((sub_step_99_1 * 2) + pub_r000913_9_1) & 127;
  int stage_v_99_2 = ((sub_step_99_2 * 2) + pub_r000913_9_2) & 127;
  st_var_1_1.buffer[0] = stage_v_99_1 & 15;
  st_var_1_2.buffer[0] = stage_v_99_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int sub_step_100_1 = ((stage_v_92_1 + pub_r000913_17_1) + 10) & 127;
  int sub_step_100_2 = ((stage_v_92_2 + pub_r000913_17_2) + 10) & 127;
  int stage_v_100_1 = ((sub_step_100_1 * 2) + pub_r000913_12_1) & 127;
  int stage_v_100_2 = ((sub_step_100_2 * 2) + pub_r000913_12_2) & 127;
  st_var_0_1.buffer[1] = stage_v_100_1 & 15;
  st_var_0_2.buffer[1] = stage_v_100_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int sub_step_101_1 = ((sec_r000913_16_1 + pub_r000913_15_1) + 16) & 127;
  int sub_step_101_2 = ((sec_r000913_16_2 + pub_r000913_15_2) + 16) & 127;
  int stage_v_101_1 = ((sub_step_101_1 * 2) + pub_r000913_3_1) & 127;
  int stage_v_101_2 = ((sub_step_101_2 * 2) + pub_r000913_3_2) & 127;
  st_var_1_1.buffer[2] = stage_v_101_1 & 15;
  st_var_1_2.buffer[2] = stage_v_101_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int sub_step_102_1 = ((sub_step_97_1 + pub_r000913_19_1) + 16) & 127;
  int sub_step_102_2 = ((sub_step_97_2 + pub_r000913_19_2) + 16) & 127;
  int stage_v_102_1 = ((sub_step_102_1 * 2) + pub_r000913_15_1) & 127;
  int stage_v_102_2 = ((sub_step_102_2 * 2) + pub_r000913_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_102_1 & 15;
  st_var_0_2.buffer[0] = stage_v_102_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int sub_step_103_1 = ((sub_step_97_1 + pub_r000913_4_1) + 20) & 127;
  int sub_step_103_2 = ((sub_step_97_2 + pub_r000913_4_2) + 20) & 127;
  int stage_v_103_1 = ((sub_step_103_1 * 2) + pub_r000913_2_1) & 127;
  int stage_v_103_2 = ((sub_step_103_2 * 2) + pub_r000913_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_103_1 & 15;
  st_var_1_2.buffer[1] = stage_v_103_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int sub_step_104_1 = ((sec_r000913_4_1 + pub_r000913_11_1) + 14) & 127;
  int sub_step_104_2 = ((sec_r000913_4_2 + pub_r000913_11_2) + 14) & 127;
  int stage_v_104_1 = ((sub_step_104_1 * 2) + pub_r000913_2_1) & 127;
  int stage_v_104_2 = ((sub_step_104_2 * 2) + pub_r000913_2_2) & 127;
  st_var_0_1.buffer[2] = stage_v_104_1 & 15;
  st_var_0_2.buffer[2] = stage_v_104_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int sub_step_105_1 = ((sub_step_100_1 + pub_r000913_19_1) + 5) & 127;
  int sub_step_105_2 = ((sub_step_100_2 + pub_r000913_19_2) + 5) & 127;
  int stage_v_105_1 = ((sub_step_105_1 * 2) + pub_r000913_3_1) & 127;
  int stage_v_105_2 = ((sub_step_105_2 * 2) + pub_r000913_3_2) & 127;
  st_var_1_1.buffer[0] = stage_v_105_1 & 15;
  st_var_1_2.buffer[0] = stage_v_105_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int sub_step_106_1 = ((sub_step_92_1 + pub_r000913_5_1) + 6) & 127;
  int sub_step_106_2 = ((sub_step_92_2 + pub_r000913_5_2) + 6) & 127;
  int stage_v_106_1 = ((sub_step_106_1 * 2) + pub_r000913_8_1) & 127;
  int stage_v_106_2 = ((sub_step_106_2 * 2) + pub_r000913_8_2) & 127;
  st_var_0_1.buffer[1] = stage_v_106_1 & 15;
  st_var_0_2.buffer[1] = stage_v_106_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int sub_step_107_1 = ((sec_r000913_14_1 + pub_r000913_8_1) + 17) & 127;
  int sub_step_107_2 = ((sec_r000913_14_2 + pub_r000913_8_2) + 17) & 127;
  int stage_v_107_1 = ((sub_step_107_1 * 2) + pub_r000913_5_1) & 127;
  int stage_v_107_2 = ((sub_step_107_2 * 2) + pub_r000913_5_2) & 127;
  st_var_1_1.buffer[2] = stage_v_107_1 & 15;
  st_var_1_2.buffer[2] = stage_v_107_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int sub_step_108_1 = ((sub_step_97_1 + pub_r000913_2_1) + 10) & 127;
  int sub_step_108_2 = ((sub_step_97_2 + pub_r000913_2_2) + 10) & 127;
  int stage_v_108_1 = ((sub_step_108_1 * 2) + pub_r000913_4_1) & 127;
  int stage_v_108_2 = ((sub_step_108_2 * 2) + pub_r000913_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_108_1 & 15;
  st_var_0_2.buffer[0] = stage_v_108_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int sub_step_109_1 = ((sec_r000913_15_1 + pub_r000913_0_1) + 30) & 127;
  int sub_step_109_2 = ((sec_r000913_15_2 + pub_r000913_0_2) + 30) & 127;
  int stage_v_109_1 = ((sub_step_109_1 * 2) + pub_r000913_15_1) & 127;
  int stage_v_109_2 = ((sub_step_109_2 * 2) + pub_r000913_15_2) & 127;
  st_var_1_1.buffer[1] = stage_v_109_1 & 15;
  st_var_1_2.buffer[1] = stage_v_109_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int sub_step_110_1 = ((stage_v_105_1 + pub_r000913_20_1) + 17) & 127;
  int sub_step_110_2 = ((stage_v_105_2 + pub_r000913_20_2) + 17) & 127;
  int stage_v_110_1 = ((sub_step_110_1 * 2) + pub_r000913_18_1) & 127;
  int stage_v_110_2 = ((sub_step_110_2 * 2) + pub_r000913_18_2) & 127;
  st_var_0_1.buffer[2] = stage_v_110_1 & 15;
  st_var_0_2.buffer[2] = stage_v_110_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int sub_step_111_1 = ((stage_v_98_1 + pub_r000913_10_1) + 31) & 127;
  int sub_step_111_2 = ((stage_v_98_2 + pub_r000913_10_2) + 31) & 127;
  int stage_v_111_1 = ((sub_step_111_1 * 2) + pub_r000913_6_1) & 127;
  int stage_v_111_2 = ((sub_step_111_2 * 2) + pub_r000913_6_2) & 127;
  st_var_1_1.buffer[0] = stage_v_111_1 & 15;
  st_var_1_2.buffer[0] = stage_v_111_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int sub_step_112_1 = ((stage_v_99_1 + pub_r000913_5_1) + 13) & 127;
  int sub_step_112_2 = ((stage_v_99_2 + pub_r000913_5_2) + 13) & 127;
  int stage_v_112_1 = ((sub_step_112_1 * 2) + pub_r000913_0_1) & 127;
  int stage_v_112_2 = ((sub_step_112_2 * 2) + pub_r000913_0_2) & 127;
  st_var_0_1.buffer[1] = stage_v_112_1 & 15;
  st_var_0_2.buffer[1] = stage_v_112_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int sub_step_113_1 = ((stage_v_105_1 + pub_r000913_1_1) + 9) & 127;
  int sub_step_113_2 = ((stage_v_105_2 + pub_r000913_1_2) + 9) & 127;
  int stage_v_113_1 = ((sub_step_113_1 * 2) + pub_r000913_15_1) & 127;
  int stage_v_113_2 = ((sub_step_113_2 * 2) + pub_r000913_15_2) & 127;
  st_var_1_1.buffer[2] = stage_v_113_1 & 15;
  st_var_1_2.buffer[2] = stage_v_113_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int sub_step_114_1 = ((stage_v_94_1 + pub_r000913_2_1) + 26) & 127;
  int sub_step_114_2 = ((stage_v_94_2 + pub_r000913_2_2) + 26) & 127;
  int stage_v_114_1 = ((sub_step_114_1 * 2) + pub_r000913_10_1) & 127;
  int stage_v_114_2 = ((sub_step_114_2 * 2) + pub_r000913_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_114_1 & 15;
  st_var_0_2.buffer[0] = stage_v_114_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int sub_step_115_1 = ((sec_r000913_3_1 + pub_r000913_4_1) + 12) & 127;
  int sub_step_115_2 = ((sec_r000913_3_2 + pub_r000913_4_2) + 12) & 127;
  int stage_v_115_1 = ((sub_step_115_1 * 2) + pub_r000913_15_1) & 127;
  int stage_v_115_2 = ((sub_step_115_2 * 2) + pub_r000913_15_2) & 127;
  st_var_1_1.buffer[1] = stage_v_115_1 & 15;
  st_var_1_2.buffer[1] = stage_v_115_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int sub_step_116_1 = ((stage_v_98_1 + pub_r000913_10_1) + 13) & 127;
  int sub_step_116_2 = ((stage_v_98_2 + pub_r000913_10_2) + 13) & 127;
  int stage_v_116_1 = ((sub_step_116_1 * 2) + pub_r000913_9_1) & 127;
  int stage_v_116_2 = ((sub_step_116_2 * 2) + pub_r000913_9_2) & 127;
  st_var_0_1.buffer[2] = stage_v_116_1 & 15;
  st_var_0_2.buffer[2] = stage_v_116_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int sub_step_117_1 = ((stage_v_100_1 + pub_r000913_10_1) + 12) & 127;
  int sub_step_117_2 = ((stage_v_100_2 + pub_r000913_10_2) + 12) & 127;
  int stage_v_117_1 = ((sub_step_117_1 * 2) + pub_r000913_3_1) & 127;
  int stage_v_117_2 = ((sub_step_117_2 * 2) + pub_r000913_3_2) & 127;
  st_var_1_1.buffer[0] = stage_v_117_1 & 15;
  st_var_1_2.buffer[0] = stage_v_117_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int sub_step_118_1 = ((sec_r000913_15_1 + pub_r000913_12_1) + 7) & 127;
  int sub_step_118_2 = ((sec_r000913_15_2 + pub_r000913_12_2) + 7) & 127;
  int stage_v_118_1 = ((sub_step_118_1 * 2) + pub_r000913_18_1) & 127;
  int stage_v_118_2 = ((sub_step_118_2 * 2) + pub_r000913_18_2) & 127;
  st_var_0_1.buffer[1] = stage_v_118_1 & 15;
  st_var_0_2.buffer[1] = stage_v_118_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int sub_step_119_1 = ((sub_step_101_1 + pub_r000913_10_1) + 11) & 127;
  int sub_step_119_2 = ((sub_step_101_2 + pub_r000913_10_2) + 11) & 127;
  int stage_v_119_1 = ((sub_step_119_1 * 2) + pub_r000913_6_1) & 127;
  int stage_v_119_2 = ((sub_step_119_2 * 2) + pub_r000913_6_2) & 127;
  st_var_1_1.buffer[2] = stage_v_119_1 & 15;
  st_var_1_2.buffer[2] = stage_v_119_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int sub_step_120_1 = ((sub_step_115_1 + pub_r000913_14_1) + 9) & 127;
  int sub_step_120_2 = ((sub_step_115_2 + pub_r000913_14_2) + 9) & 127;
  int stage_v_120_1 = ((sub_step_120_1 * 2) + pub_r000913_8_1) & 127;
  int stage_v_120_2 = ((sub_step_120_2 * 2) + pub_r000913_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_120_1 & 15;
  st_var_0_2.buffer[0] = stage_v_120_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int sub_step_121_1 = ((stage_v_99_1 + pub_r000913_7_1) + 11) & 127;
  int sub_step_121_2 = ((stage_v_99_2 + pub_r000913_7_2) + 11) & 127;
  int stage_v_121_1 = ((sub_step_121_1 * 2) + pub_r000913_13_1) & 127;
  int stage_v_121_2 = ((sub_step_121_2 * 2) + pub_r000913_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_121_1 & 15;
  st_var_1_2.buffer[1] = stage_v_121_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int sub_step_122_1 = ((sec_r000913_7_1 + pub_r000913_10_1) + 8) & 127;
  int sub_step_122_2 = ((sec_r000913_7_2 + pub_r000913_10_2) + 8) & 127;
  int stage_v_122_1 = ((sub_step_122_1 * 2) + pub_r000913_13_1) & 127;
  int stage_v_122_2 = ((sub_step_122_2 * 2) + pub_r000913_13_2) & 127;
  st_var_0_1.buffer[2] = stage_v_122_1 & 15;
  st_var_0_2.buffer[2] = stage_v_122_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int sub_step_123_1 = ((sub_step_90_1 + pub_r000913_9_1) + 29) & 127;
  int sub_step_123_2 = ((sub_step_90_2 + pub_r000913_9_2) + 29) & 127;
  int stage_v_123_1 = ((sub_step_123_1 * 2) + pub_r000913_10_1) & 127;
  int stage_v_123_2 = ((sub_step_123_2 * 2) + pub_r000913_10_2) & 127;
  st_var_1_1.buffer[0] = stage_v_123_1 & 15;
  st_var_1_2.buffer[0] = stage_v_123_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int sub_step_124_1 = ((sub_step_96_1 + pub_r000913_4_1) + 11) & 127;
  int sub_step_124_2 = ((sub_step_96_2 + pub_r000913_4_2) + 11) & 127;
  int stage_v_124_1 = ((sub_step_124_1 * 2) + pub_r000913_18_1) & 127;
  int stage_v_124_2 = ((sub_step_124_2 * 2) + pub_r000913_18_2) & 127;
  st_var_0_1.buffer[1] = stage_v_124_1 & 15;
  st_var_0_2.buffer[1] = stage_v_124_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int sub_step_125_1 = ((sec_r000913_2_1 + pub_r000913_17_1) + 20) & 127;
  int sub_step_125_2 = ((sec_r000913_2_2 + pub_r000913_17_2) + 20) & 127;
  int stage_v_125_1 = ((sub_step_125_1 * 2) + pub_r000913_11_1) & 127;
  int stage_v_125_2 = ((sub_step_125_2 * 2) + pub_r000913_11_2) & 127;
  st_var_1_1.buffer[2] = stage_v_125_1 & 15;
  st_var_1_2.buffer[2] = stage_v_125_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int sub_step_126_1 = ((stage_v_101_1 + pub_r000913_12_1) + 23) & 127;
  int sub_step_126_2 = ((stage_v_101_2 + pub_r000913_12_2) + 23) & 127;
  int stage_v_126_1 = ((sub_step_126_1 * 2) + pub_r000913_20_1) & 127;
  int stage_v_126_2 = ((sub_step_126_2 * 2) + pub_r000913_20_2) & 127;
  st_var_0_1.buffer[0] = stage_v_126_1 & 15;
  st_var_0_2.buffer[0] = stage_v_126_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int sub_step_127_1 = ((sub_step_121_1 + pub_r000913_14_1) + 17) & 127;
  int sub_step_127_2 = ((sub_step_121_2 + pub_r000913_14_2) + 17) & 127;
  int stage_v_127_1 = ((sub_step_127_1 * 2) + pub_r000913_9_1) & 127;
  int stage_v_127_2 = ((sub_step_127_2 * 2) + pub_r000913_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_127_1 & 15;
  st_var_1_2.buffer[1] = stage_v_127_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int sub_step_128_1 = ((stage_v_103_1 + pub_r000913_17_1) + 32) & 127;
  int sub_step_128_2 = ((stage_v_103_2 + pub_r000913_17_2) + 32) & 127;
  int stage_v_128_1 = ((sub_step_128_1 * 2) + pub_r000913_13_1) & 127;
  int stage_v_128_2 = ((sub_step_128_2 * 2) + pub_r000913_13_2) & 127;
  st_var_0_1.buffer[2] = stage_v_128_1 & 15;
  st_var_0_2.buffer[2] = stage_v_128_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int sub_step_129_1 = ((sec_r000913_9_1 + pub_r000913_18_1) + 7) & 127;
  int sub_step_129_2 = ((sec_r000913_9_2 + pub_r000913_18_2) + 7) & 127;
  int stage_v_129_1 = ((sub_step_129_1 * 2) + pub_r000913_16_1) & 127;
  int stage_v_129_2 = ((sub_step_129_2 * 2) + pub_r000913_16_2) & 127;
  st_var_1_1.buffer[0] = stage_v_129_1 & 15;
  st_var_1_2.buffer[0] = stage_v_129_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int sub_step_130_1 = ((sub_step_124_1 + pub_r000913_15_1) + 21) & 127;
  int sub_step_130_2 = ((sub_step_124_2 + pub_r000913_15_2) + 21) & 127;
  int stage_v_130_1 = ((sub_step_130_1 * 2) + pub_r000913_17_1) & 127;
  int stage_v_130_2 = ((sub_step_130_2 * 2) + pub_r000913_17_2) & 127;
  st_var_0_1.buffer[1] = stage_v_130_1 & 15;
  st_var_0_2.buffer[1] = stage_v_130_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int sub_step_131_1 = ((sec_r000913_11_1 + pub_r000913_18_1) + 10) & 127;
  int sub_step_131_2 = ((sec_r000913_11_2 + pub_r000913_18_2) + 10) & 127;
  int stage_v_131_1 = ((sub_step_131_1 * 2) + pub_r000913_15_1) & 127;
  int stage_v_131_2 = ((sub_step_131_2 * 2) + pub_r000913_15_2) & 127;
  st_var_1_1.buffer[2] = stage_v_131_1 & 15;
  st_var_1_2.buffer[2] = stage_v_131_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int sub_step_132_1 = ((stage_v_93_1 + pub_r000913_12_1) + 17) & 127;
  int sub_step_132_2 = ((stage_v_93_2 + pub_r000913_12_2) + 17) & 127;
  int stage_v_132_1 = ((sub_step_132_1 * 2) + pub_r000913_19_1) & 127;
  int stage_v_132_2 = ((sub_step_132_2 * 2) + pub_r000913_19_2) & 127;
  st_var_0_1.buffer[0] = stage_v_132_1 & 15;
  st_var_0_2.buffer[0] = stage_v_132_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int sub_step_133_1 = ((stage_v_123_1 + pub_r000913_11_1) + 18) & 127;
  int sub_step_133_2 = ((stage_v_123_2 + pub_r000913_11_2) + 18) & 127;
  int stage_v_133_1 = ((sub_step_133_1 * 2) + pub_r000913_17_1) & 127;
  int stage_v_133_2 = ((sub_step_133_2 * 2) + pub_r000913_17_2) & 127;
  st_var_1_1.buffer[1] = stage_v_133_1 & 15;
  st_var_1_2.buffer[1] = stage_v_133_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int sub_step_134_1 = ((sub_step_104_1 + pub_r000913_10_1) + 35) & 127;
  int sub_step_134_2 = ((sub_step_104_2 + pub_r000913_10_2) + 35) & 127;
  int stage_v_134_1 = ((sub_step_134_1 * 2) + pub_r000913_10_1) & 127;
  int stage_v_134_2 = ((sub_step_134_2 * 2) + pub_r000913_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_134_1 & 15;
  st_var_0_2.buffer[2] = stage_v_134_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int sub_step_135_1 = ((sec_r000913_3_1 + pub_r000913_19_1) + 33) & 127;
  int sub_step_135_2 = ((sec_r000913_3_2 + pub_r000913_19_2) + 33) & 127;
  int stage_v_135_1 = ((sub_step_135_1 * 2) + pub_r000913_0_1) & 127;
  int stage_v_135_2 = ((sub_step_135_2 * 2) + pub_r000913_0_2) & 127;
  st_var_1_1.buffer[0] = stage_v_135_1 & 15;
  st_var_1_2.buffer[0] = stage_v_135_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int sub_step_136_1 = ((sub_step_118_1 + pub_r000913_15_1) + 13) & 127;
  int sub_step_136_2 = ((sub_step_118_2 + pub_r000913_15_2) + 13) & 127;
  int stage_v_136_1 = ((sub_step_136_1 * 2) + pub_r000913_10_1) & 127;
  int stage_v_136_2 = ((sub_step_136_2 * 2) + pub_r000913_10_2) & 127;
  st_var_0_1.buffer[1] = stage_v_136_1 & 15;
  st_var_0_2.buffer[1] = stage_v_136_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int sub_step_137_1 = ((stage_v_101_1 + pub_r000913_12_1) + 29) & 127;
  int sub_step_137_2 = ((stage_v_101_2 + pub_r000913_12_2) + 29) & 127;
  int stage_v_137_1 = ((sub_step_137_1 * 2) + pub_r000913_3_1) & 127;
  int stage_v_137_2 = ((sub_step_137_2 * 2) + pub_r000913_3_2) & 127;
  st_var_1_1.buffer[2] = stage_v_137_1 & 15;
  st_var_1_2.buffer[2] = stage_v_137_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int sub_step_138_1 = ((sub_step_122_1 + pub_r000913_4_1) + 9) & 127;
  int sub_step_138_2 = ((sub_step_122_2 + pub_r000913_4_2) + 9) & 127;
  int stage_v_138_1 = ((sub_step_138_1 * 2) + pub_r000913_10_1) & 127;
  int stage_v_138_2 = ((sub_step_138_2 * 2) + pub_r000913_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_138_1 & 15;
  st_var_0_2.buffer[0] = stage_v_138_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int sub_step_139_1 = ((sec_r000913_0_1 + pub_r000913_1_1) + 29) & 127;
  int sub_step_139_2 = ((sec_r000913_0_2 + pub_r000913_1_2) + 29) & 127;
  int stage_v_139_1 = ((sub_step_139_1 * 2) + pub_r000913_6_1) & 127;
  int stage_v_139_2 = ((sub_step_139_2 * 2) + pub_r000913_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_139_1 & 15;
  st_var_1_2.buffer[1] = stage_v_139_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int sub_step_140_1 = ((stage_v_117_1 + pub_r000913_3_1) + 10) & 127;
  int sub_step_140_2 = ((stage_v_117_2 + pub_r000913_3_2) + 10) & 127;
  int stage_v_140_1 = ((sub_step_140_1 * 2) + pub_r000913_5_1) & 127;
  int stage_v_140_2 = ((sub_step_140_2 * 2) + pub_r000913_5_2) & 127;
  st_var_0_1.buffer[2] = stage_v_140_1 & 15;
  st_var_0_2.buffer[2] = stage_v_140_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int sub_step_141_1 = ((sub_step_106_1 + pub_r000913_6_1) + 16) & 127;
  int sub_step_141_2 = ((sub_step_106_2 + pub_r000913_6_2) + 16) & 127;
  int stage_v_141_1 = ((sub_step_141_1 * 2) + pub_r000913_7_1) & 127;
  int stage_v_141_2 = ((sub_step_141_2 * 2) + pub_r000913_7_2) & 127;
  st_var_1_1.buffer[0] = stage_v_141_1 & 15;
  st_var_1_2.buffer[0] = stage_v_141_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int sub_step_142_1 = ((sub_step_127_1 + pub_r000913_16_1) + 14) & 127;
  int sub_step_142_2 = ((sub_step_127_2 + pub_r000913_16_2) + 14) & 127;
  int stage_v_142_1 = ((sub_step_142_1 * 2) + pub_r000913_10_1) & 127;
  int stage_v_142_2 = ((sub_step_142_2 * 2) + pub_r000913_10_2) & 127;
  st_var_0_1.buffer[1] = stage_v_142_1 & 15;
  st_var_0_2.buffer[1] = stage_v_142_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int sub_step_143_1 = ((sec_r000913_10_1 + pub_r000913_3_1) + 13) & 127;
  int sub_step_143_2 = ((sec_r000913_10_2 + pub_r000913_3_2) + 13) & 127;
  int stage_v_143_1 = ((sub_step_143_1 * 2) + pub_r000913_8_1) & 127;
  int stage_v_143_2 = ((sub_step_143_2 * 2) + pub_r000913_8_2) & 127;
  st_var_1_1.buffer[2] = stage_v_143_1 & 15;
  st_var_1_2.buffer[2] = stage_v_143_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int sub_step_144_1 = ((sub_step_97_1 + pub_r000913_8_1) + 31) & 127;
  int sub_step_144_2 = ((sub_step_97_2 + pub_r000913_8_2) + 31) & 127;
  int stage_v_144_1 = ((sub_step_144_1 * 2) + pub_r000913_2_1) & 127;
  int stage_v_144_2 = ((sub_step_144_2 * 2) + pub_r000913_2_2) & 127;
  st_var_0_1.buffer[0] = stage_v_144_1 & 15;
  st_var_0_2.buffer[0] = stage_v_144_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int sub_step_145_1 = ((stage_v_142_1 + pub_r000913_3_1) + 11) & 127;
  int sub_step_145_2 = ((stage_v_142_2 + pub_r000913_3_2) + 11) & 127;
  int stage_v_145_1 = ((sub_step_145_1 * 2) + pub_r000913_10_1) & 127;
  int stage_v_145_2 = ((sub_step_145_2 * 2) + pub_r000913_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_145_1 & 15;
  st_var_1_2.buffer[1] = stage_v_145_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int sub_step_146_1 = ((sub_step_137_1 + pub_r000913_10_1) + 31) & 127;
  int sub_step_146_2 = ((sub_step_137_2 + pub_r000913_10_2) + 31) & 127;
  int stage_v_146_1 = ((sub_step_146_1 * 2) + pub_r000913_8_1) & 127;
  int stage_v_146_2 = ((sub_step_146_2 * 2) + pub_r000913_8_2) & 127;
  st_var_0_1.buffer[2] = stage_v_146_1 & 15;
  st_var_0_2.buffer[2] = stage_v_146_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int sub_step_147_1 = ((sub_step_99_1 + pub_r000913_1_1) + 31) & 127;
  int sub_step_147_2 = ((sub_step_99_2 + pub_r000913_1_2) + 31) & 127;
  int stage_v_147_1 = ((sub_step_147_1 * 2) + pub_r000913_20_1) & 127;
  int stage_v_147_2 = ((sub_step_147_2 * 2) + pub_r000913_20_2) & 127;
  st_var_1_1.buffer[0] = stage_v_147_1 & 15;
  st_var_1_2.buffer[0] = stage_v_147_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int sub_step_148_1 = ((sec_r000913_6_1 + pub_r000913_19_1) + 32) & 127;
  int sub_step_148_2 = ((sec_r000913_6_2 + pub_r000913_19_2) + 32) & 127;
  int stage_v_148_1 = ((sub_step_148_1 * 2) + pub_r000913_20_1) & 127;
  int stage_v_148_2 = ((sub_step_148_2 * 2) + pub_r000913_20_2) & 127;
  st_var_0_1.buffer[1] = stage_v_148_1 & 15;
  st_var_0_2.buffer[1] = stage_v_148_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int sub_step_149_1 = ((sub_step_142_1 + pub_r000913_0_1) + 35) & 127;
  int sub_step_149_2 = ((sub_step_142_2 + pub_r000913_0_2) + 35) & 127;
  int stage_v_149_1 = ((sub_step_149_1 * 2) + pub_r000913_4_1) & 127;
  int stage_v_149_2 = ((sub_step_149_2 * 2) + pub_r000913_4_2) & 127;
  st_var_1_1.buffer[2] = stage_v_149_1 & 15;
  st_var_1_2.buffer[2] = stage_v_149_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int sub_step_150_1 = ((stage_v_99_1 + pub_r000913_6_1) + 16) & 127;
  int sub_step_150_2 = ((stage_v_99_2 + pub_r000913_6_2) + 16) & 127;
  int stage_v_150_1 = ((sub_step_150_1 * 2) + pub_r000913_14_1) & 127;
  int stage_v_150_2 = ((sub_step_150_2 * 2) + pub_r000913_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_150_1 & 15;
  st_var_0_2.buffer[0] = stage_v_150_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int sub_step_151_1 = ((sub_step_116_1 + pub_r000913_13_1) + 30) & 127;
  int sub_step_151_2 = ((sub_step_116_2 + pub_r000913_13_2) + 30) & 127;
  int stage_v_151_1 = ((sub_step_151_1 * 2) + pub_r000913_13_1) & 127;
  int stage_v_151_2 = ((sub_step_151_2 * 2) + pub_r000913_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_151_1 & 15;
  st_var_1_2.buffer[1] = stage_v_151_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int sub_step_152_1 = ((sec_r000913_0_1 + pub_r000913_0_1) + 26) & 127;
  int sub_step_152_2 = ((sec_r000913_0_2 + pub_r000913_0_2) + 26) & 127;
  int stage_v_152_1 = ((sub_step_152_1 * 2) + pub_r000913_14_1) & 127;
  int stage_v_152_2 = ((sub_step_152_2 * 2) + pub_r000913_14_2) & 127;
  st_var_0_1.buffer[2] = stage_v_152_1 & 15;
  st_var_0_2.buffer[2] = stage_v_152_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int sub_step_153_1 = ((stage_v_123_1 + pub_r000913_8_1) + 28) & 127;
  int sub_step_153_2 = ((stage_v_123_2 + pub_r000913_8_2) + 28) & 127;
  int stage_v_153_1 = ((sub_step_153_1 * 2) + pub_r000913_4_1) & 127;
  int stage_v_153_2 = ((sub_step_153_2 * 2) + pub_r000913_4_2) & 127;
  st_var_1_1.buffer[0] = stage_v_153_1 & 15;
  st_var_1_2.buffer[0] = stage_v_153_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int sub_step_154_1 = ((stage_v_90_1 + pub_r000913_17_1) + 30) & 127;
  int sub_step_154_2 = ((stage_v_90_2 + pub_r000913_17_2) + 30) & 127;
  int stage_v_154_1 = ((sub_step_154_1 * 2) + pub_r000913_9_1) & 127;
  int stage_v_154_2 = ((sub_step_154_2 * 2) + pub_r000913_9_2) & 127;
  st_var_0_1.buffer[1] = stage_v_154_1 & 15;
  st_var_0_2.buffer[1] = stage_v_154_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int sub_step_155_1 = ((sec_r000913_8_1 + pub_r000913_5_1) + 28) & 127;
  int sub_step_155_2 = ((sec_r000913_8_2 + pub_r000913_5_2) + 28) & 127;
  int stage_v_155_1 = ((sub_step_155_1 * 2) + pub_r000913_11_1) & 127;
  int stage_v_155_2 = ((sub_step_155_2 * 2) + pub_r000913_11_2) & 127;
  st_var_1_1.buffer[2] = stage_v_155_1 & 15;
  st_var_1_2.buffer[2] = stage_v_155_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int sub_step_156_1 = ((sec_r000913_0_1 + pub_r000913_12_1) + 13) & 127;
  int sub_step_156_2 = ((sec_r000913_0_2 + pub_r000913_12_2) + 13) & 127;
  int stage_v_156_1 = ((sub_step_156_1 * 2) + pub_r000913_0_1) & 127;
  int stage_v_156_2 = ((sub_step_156_2 * 2) + pub_r000913_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_156_1 & 15;
  st_var_0_2.buffer[0] = stage_v_156_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int sub_step_157_1 = ((sub_step_105_1 + pub_r000913_11_1) + 29) & 127;
  int sub_step_157_2 = ((sub_step_105_2 + pub_r000913_11_2) + 29) & 127;
  int stage_v_157_1 = ((sub_step_157_1 * 2) + pub_r000913_12_1) & 127;
  int stage_v_157_2 = ((sub_step_157_2 * 2) + pub_r000913_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_157_1 & 15;
  st_var_1_2.buffer[1] = stage_v_157_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int sub_step_158_1 = ((sec_r000913_4_1 + pub_r000913_4_1) + 18) & 127;
  int sub_step_158_2 = ((sec_r000913_4_2 + pub_r000913_4_2) + 18) & 127;
  int stage_v_158_1 = ((sub_step_158_1 * 2) + pub_r000913_17_1) & 127;
  int stage_v_158_2 = ((sub_step_158_2 * 2) + pub_r000913_17_2) & 127;
  st_var_0_1.buffer[2] = stage_v_158_1 & 15;
  st_var_0_2.buffer[2] = stage_v_158_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int sub_step_159_1 = ((sec_r000913_15_1 + pub_r000913_17_1) + 26) & 127;
  int sub_step_159_2 = ((sec_r000913_15_2 + pub_r000913_17_2) + 26) & 127;
  int stage_v_159_1 = ((sub_step_159_1 * 2) + pub_r000913_5_1) & 127;
  int stage_v_159_2 = ((sub_step_159_2 * 2) + pub_r000913_5_2) & 127;
  st_var_1_1.buffer[0] = stage_v_159_1 & 15;
  st_var_1_2.buffer[0] = stage_v_159_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int sub_step_160_1 = ((sub_step_110_1 + pub_r000913_3_1) + 16) & 127;
  int sub_step_160_2 = ((sub_step_110_2 + pub_r000913_3_2) + 16) & 127;
  int stage_v_160_1 = ((sub_step_160_1 * 2) + pub_r000913_15_1) & 127;
  int stage_v_160_2 = ((sub_step_160_2 * 2) + pub_r000913_15_2) & 127;
  st_var_0_1.buffer[1] = stage_v_160_1 & 15;
  st_var_0_2.buffer[1] = stage_v_160_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int sub_step_161_1 = ((sec_r000913_16_1 + pub_r000913_10_1) + 9) & 127;
  int sub_step_161_2 = ((sec_r000913_16_2 + pub_r000913_10_2) + 9) & 127;
  int stage_v_161_1 = ((sub_step_161_1 * 2) + pub_r000913_13_1) & 127;
  int stage_v_161_2 = ((sub_step_161_2 * 2) + pub_r000913_13_2) & 127;
  st_var_1_1.buffer[2] = stage_v_161_1 & 15;
  st_var_1_2.buffer[2] = stage_v_161_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int sub_step_162_1 = ((sec_r000913_2_1 + pub_r000913_7_1) + 8) & 127;
  int sub_step_162_2 = ((sec_r000913_2_2 + pub_r000913_7_2) + 8) & 127;
  int stage_v_162_1 = ((sub_step_162_1 * 2) + pub_r000913_13_1) & 127;
  int stage_v_162_2 = ((sub_step_162_2 * 2) + pub_r000913_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_162_1 & 15;
  st_var_0_2.buffer[0] = stage_v_162_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int sub_step_163_1 = ((sub_step_132_1 + pub_r000913_12_1) + 31) & 127;
  int sub_step_163_2 = ((sub_step_132_2 + pub_r000913_12_2) + 31) & 127;
  int stage_v_163_1 = ((sub_step_163_1 * 2) + pub_r000913_3_1) & 127;
  int stage_v_163_2 = ((sub_step_163_2 * 2) + pub_r000913_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_163_1 & 15;
  st_var_1_2.buffer[1] = stage_v_163_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int sub_step_164_1 = ((stage_v_99_1 + pub_r000913_18_1) + 20) & 127;
  int sub_step_164_2 = ((stage_v_99_2 + pub_r000913_18_2) + 20) & 127;
  int stage_v_164_1 = ((sub_step_164_1 * 2) + pub_r000913_16_1) & 127;
  int stage_v_164_2 = ((sub_step_164_2 * 2) + pub_r000913_16_2) & 127;
  st_var_0_1.buffer[2] = stage_v_164_1 & 15;
  st_var_0_2.buffer[2] = stage_v_164_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int sub_step_165_1 = ((sub_step_103_1 + pub_r000913_20_1) + 28) & 127;
  int sub_step_165_2 = ((sub_step_103_2 + pub_r000913_20_2) + 28) & 127;
  int stage_v_165_1 = ((sub_step_165_1 * 2) + pub_r000913_15_1) & 127;
  int stage_v_165_2 = ((sub_step_165_2 * 2) + pub_r000913_15_2) & 127;
  st_var_1_1.buffer[0] = stage_v_165_1 & 15;
  st_var_1_2.buffer[0] = stage_v_165_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int sub_step_166_1 = ((stage_v_131_1 + pub_r000913_18_1) + 24) & 127;
  int sub_step_166_2 = ((stage_v_131_2 + pub_r000913_18_2) + 24) & 127;
  int stage_v_166_1 = ((sub_step_166_1 * 2) + pub_r000913_7_1) & 127;
  int stage_v_166_2 = ((sub_step_166_2 * 2) + pub_r000913_7_2) & 127;
  st_var_0_1.buffer[1] = stage_v_166_1 & 15;
  st_var_0_2.buffer[1] = stage_v_166_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int sub_step_167_1 = ((sec_r000913_10_1 + pub_r000913_10_1) + 26) & 127;
  int sub_step_167_2 = ((sec_r000913_10_2 + pub_r000913_10_2) + 26) & 127;
  int stage_v_167_1 = ((sub_step_167_1 * 2) + pub_r000913_8_1) & 127;
  int stage_v_167_2 = ((sub_step_167_2 * 2) + pub_r000913_8_2) & 127;
  st_var_1_1.buffer[2] = stage_v_167_1 & 15;
  st_var_1_2.buffer[2] = stage_v_167_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int sub_step_168_1 = ((stage_v_98_1 + pub_r000913_16_1) + 11) & 127;
  int sub_step_168_2 = ((stage_v_98_2 + pub_r000913_16_2) + 11) & 127;
  int stage_v_168_1 = ((sub_step_168_1 * 2) + pub_r000913_14_1) & 127;
  int stage_v_168_2 = ((sub_step_168_2 * 2) + pub_r000913_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_168_1 & 15;
  st_var_0_2.buffer[0] = stage_v_168_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int sub_step_169_1 = ((sec_r000913_15_1 + pub_r000913_2_1) + 17) & 127;
  int sub_step_169_2 = ((sec_r000913_15_2 + pub_r000913_2_2) + 17) & 127;
  int stage_v_169_1 = ((sub_step_169_1 * 2) + pub_r000913_2_1) & 127;
  int stage_v_169_2 = ((sub_step_169_2 * 2) + pub_r000913_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_169_1 & 15;
  st_var_1_2.buffer[1] = stage_v_169_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int sub_step_170_1 = ((sec_r000913_3_1 + pub_r000913_3_1) + 14) & 127;
  int sub_step_170_2 = ((sec_r000913_3_2 + pub_r000913_3_2) + 14) & 127;
  int stage_v_170_1 = ((sub_step_170_1 * 2) + pub_r000913_16_1) & 127;
  int stage_v_170_2 = ((sub_step_170_2 * 2) + pub_r000913_16_2) & 127;
  st_var_0_1.buffer[2] = stage_v_170_1 & 15;
  st_var_0_2.buffer[2] = stage_v_170_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int sub_step_171_1 = ((sec_r000913_15_1 + pub_r000913_6_1) + 18) & 127;
  int sub_step_171_2 = ((sec_r000913_15_2 + pub_r000913_6_2) + 18) & 127;
  int stage_v_171_1 = ((sub_step_171_1 * 2) + pub_r000913_10_1) & 127;
  int stage_v_171_2 = ((sub_step_171_2 * 2) + pub_r000913_10_2) & 127;
  st_var_1_1.buffer[0] = stage_v_171_1 & 15;
  st_var_1_2.buffer[0] = stage_v_171_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int sub_step_172_1 = ((sub_step_136_1 + pub_r000913_11_1) + 24) & 127;
  int sub_step_172_2 = ((sub_step_136_2 + pub_r000913_11_2) + 24) & 127;
  int stage_v_172_1 = ((sub_step_172_1 * 2) + pub_r000913_16_1) & 127;
  int stage_v_172_2 = ((sub_step_172_2 * 2) + pub_r000913_16_2) & 127;
  st_var_0_1.buffer[1] = stage_v_172_1 & 15;
  st_var_0_2.buffer[1] = stage_v_172_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int sub_step_173_1 = ((sec_r000913_13_1 + pub_r000913_3_1) + 35) & 127;
  int sub_step_173_2 = ((sec_r000913_13_2 + pub_r000913_3_2) + 35) & 127;
  int stage_v_173_1 = ((sub_step_173_1 * 2) + pub_r000913_7_1) & 127;
  int stage_v_173_2 = ((sub_step_173_2 * 2) + pub_r000913_7_2) & 127;
  st_var_1_1.buffer[2] = stage_v_173_1 & 15;
  st_var_1_2.buffer[2] = stage_v_173_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int sub_step_174_1 = ((sec_r000913_15_1 + pub_r000913_10_1) + 25) & 127;
  int sub_step_174_2 = ((sec_r000913_15_2 + pub_r000913_10_2) + 25) & 127;
  int stage_v_174_1 = ((sub_step_174_1 * 2) + pub_r000913_1_1) & 127;
  int stage_v_174_2 = ((sub_step_174_2 * 2) + pub_r000913_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_174_1 & 15;
  st_var_0_2.buffer[0] = stage_v_174_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int sub_step_175_1 = ((stage_v_130_1 + pub_r000913_8_1) + 5) & 127;
  int sub_step_175_2 = ((stage_v_130_2 + pub_r000913_8_2) + 5) & 127;
  int stage_v_175_1 = ((sub_step_175_1 * 2) + pub_r000913_2_1) & 127;
  int stage_v_175_2 = ((sub_step_175_2 * 2) + pub_r000913_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_175_1 & 15;
  st_var_1_2.buffer[1] = stage_v_175_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int sub_step_176_1 = ((sec_r000913_0_1 + pub_r000913_3_1) + 34) & 127;
  int sub_step_176_2 = ((sec_r000913_0_2 + pub_r000913_3_2) + 34) & 127;
  int stage_v_176_1 = ((sub_step_176_1 * 2) + pub_r000913_16_1) & 127;
  int stage_v_176_2 = ((sub_step_176_2 * 2) + pub_r000913_16_2) & 127;
  st_var_0_1.buffer[2] = stage_v_176_1 & 15;
  st_var_0_2.buffer[2] = stage_v_176_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int sub_step_177_1 = ((sub_step_111_1 + pub_r000913_6_1) + 14) & 127;
  int sub_step_177_2 = ((sub_step_111_2 + pub_r000913_6_2) + 14) & 127;
  int stage_v_177_1 = ((sub_step_177_1 * 2) + pub_r000913_0_1) & 127;
  int stage_v_177_2 = ((sub_step_177_2 * 2) + pub_r000913_0_2) & 127;
  st_var_1_1.buffer[0] = stage_v_177_1 & 15;
  st_var_1_2.buffer[0] = stage_v_177_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int sub_step_178_1 = ((stage_v_126_1 + pub_r000913_7_1) + 13) & 127;
  int sub_step_178_2 = ((stage_v_126_2 + pub_r000913_7_2) + 13) & 127;
  int stage_v_178_1 = ((sub_step_178_1 * 2) + pub_r000913_19_1) & 127;
  int stage_v_178_2 = ((sub_step_178_2 * 2) + pub_r000913_19_2) & 127;
  st_var_0_1.buffer[1] = stage_v_178_1 & 15;
  st_var_0_2.buffer[1] = stage_v_178_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int sub_step_179_1 = ((sec_r000913_10_1 + pub_r000913_16_1) + 18) & 127;
  int sub_step_179_2 = ((sec_r000913_10_2 + pub_r000913_16_2) + 18) & 127;
  int stage_v_179_1 = ((sub_step_179_1 * 2) + pub_r000913_20_1) & 127;
  int stage_v_179_2 = ((sub_step_179_2 * 2) + pub_r000913_20_2) & 127;
  st_var_1_1.buffer[2] = stage_v_179_1 & 15;
  st_var_1_2.buffer[2] = stage_v_179_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int sub_step_180_1 = ((sec_r000913_8_1 + pub_r000913_16_1) + 34) & 127;
  int sub_step_180_2 = ((sec_r000913_8_2 + pub_r000913_16_2) + 34) & 127;
  int stage_v_180_1 = ((sub_step_180_1 * 2) + pub_r000913_5_1) & 127;
  int stage_v_180_2 = ((sub_step_180_2 * 2) + pub_r000913_5_2) & 127;
  st_var_0_1.buffer[0] = stage_v_180_1 & 15;
  st_var_0_2.buffer[0] = stage_v_180_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int sub_step_181_1 = ((sec_r000913_13_1 + pub_r000913_0_1) + 11) & 127;
  int sub_step_181_2 = ((sec_r000913_13_2 + pub_r000913_0_2) + 11) & 127;
  int stage_v_181_1 = ((sub_step_181_1 * 2) + pub_r000913_5_1) & 127;
  int stage_v_181_2 = ((sub_step_181_2 * 2) + pub_r000913_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_181_1 & 15;
  st_var_1_2.buffer[1] = stage_v_181_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int sub_step_182_1 = ((sub_step_178_1 + pub_r000913_5_1) + 17) & 127;
  int sub_step_182_2 = ((sub_step_178_2 + pub_r000913_5_2) + 17) & 127;
  int stage_v_182_1 = ((sub_step_182_1 * 2) + pub_r000913_12_1) & 127;
  int stage_v_182_2 = ((sub_step_182_2 * 2) + pub_r000913_12_2) & 127;
  st_var_0_1.buffer[2] = stage_v_182_1 & 15;
  st_var_0_2.buffer[2] = stage_v_182_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int sub_step_183_1 = ((sec_r000913_5_1 + pub_r000913_17_1) + 10) & 127;
  int sub_step_183_2 = ((sec_r000913_5_2 + pub_r000913_17_2) + 10) & 127;
  int stage_v_183_1 = ((sub_step_183_1 * 2) + pub_r000913_17_1) & 127;
  int stage_v_183_2 = ((sub_step_183_2 * 2) + pub_r000913_17_2) & 127;
  st_var_1_1.buffer[0] = stage_v_183_1 & 15;
  st_var_1_2.buffer[0] = stage_v_183_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int sub_step_184_1 = ((sub_step_112_1 + pub_r000913_13_1) + 21) & 127;
  int sub_step_184_2 = ((sub_step_112_2 + pub_r000913_13_2) + 21) & 127;
  int stage_v_184_1 = ((sub_step_184_1 * 2) + pub_r000913_20_1) & 127;
  int stage_v_184_2 = ((sub_step_184_2 * 2) + pub_r000913_20_2) & 127;
  st_var_0_1.buffer[1] = stage_v_184_1 & 15;
  st_var_0_2.buffer[1] = stage_v_184_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int sub_step_185_1 = ((stage_v_127_1 + pub_r000913_1_1) + 5) & 127;
  int sub_step_185_2 = ((stage_v_127_2 + pub_r000913_1_2) + 5) & 127;
  int stage_v_185_1 = ((sub_step_185_1 * 2) + pub_r000913_20_1) & 127;
  int stage_v_185_2 = ((sub_step_185_2 * 2) + pub_r000913_20_2) & 127;
  st_var_1_1.buffer[2] = stage_v_185_1 & 15;
  st_var_1_2.buffer[2] = stage_v_185_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int sub_step_186_1 = ((sec_r000913_3_1 + pub_r000913_10_1) + 32) & 127;
  int sub_step_186_2 = ((sec_r000913_3_2 + pub_r000913_10_2) + 32) & 127;
  int stage_v_186_1 = ((sub_step_186_1 * 2) + pub_r000913_20_1) & 127;
  int stage_v_186_2 = ((sub_step_186_2 * 2) + pub_r000913_20_2) & 127;
  st_var_0_1.buffer[0] = stage_v_186_1 & 15;
  st_var_0_2.buffer[0] = stage_v_186_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int sub_step_187_1 = ((stage_v_178_1 + pub_r000913_3_1) + 26) & 127;
  int sub_step_187_2 = ((stage_v_178_2 + pub_r000913_3_2) + 26) & 127;
  int stage_v_187_1 = ((sub_step_187_1 * 2) + pub_r000913_5_1) & 127;
  int stage_v_187_2 = ((sub_step_187_2 * 2) + pub_r000913_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_187_1 & 15;
  st_var_1_2.buffer[1] = stage_v_187_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int sub_step_188_1 = ((sub_step_159_1 + pub_r000913_18_1) + 17) & 127;
  int sub_step_188_2 = ((sub_step_159_2 + pub_r000913_18_2) + 17) & 127;
  int stage_v_188_1 = ((sub_step_188_1 * 2) + pub_r000913_4_1) & 127;
  int stage_v_188_2 = ((sub_step_188_2 * 2) + pub_r000913_4_2) & 127;
  st_var_0_1.buffer[2] = stage_v_188_1 & 15;
  st_var_0_2.buffer[2] = stage_v_188_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int sub_step_189_1 = ((stage_v_148_1 + pub_r000913_3_1) + 20) & 127;
  int sub_step_189_2 = ((stage_v_148_2 + pub_r000913_3_2) + 20) & 127;
  int stage_v_189_1 = ((sub_step_189_1 * 2) + pub_r000913_6_1) & 127;
  int stage_v_189_2 = ((sub_step_189_2 * 2) + pub_r000913_6_2) & 127;
  st_var_1_1.buffer[0] = stage_v_189_1 & 15;
  st_var_1_2.buffer[0] = stage_v_189_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int sub_step_190_1 = ((sub_step_110_1 + pub_r000913_9_1) + 24) & 127;
  int sub_step_190_2 = ((sub_step_110_2 + pub_r000913_9_2) + 24) & 127;
  int stage_v_190_1 = ((sub_step_190_1 * 2) + pub_r000913_0_1) & 127;
  int stage_v_190_2 = ((sub_step_190_2 * 2) + pub_r000913_0_2) & 127;
  st_var_0_1.buffer[1] = stage_v_190_1 & 15;
  st_var_0_2.buffer[1] = stage_v_190_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int sub_step_191_1 = ((stage_v_118_1 + pub_r000913_4_1) + 9) & 127;
  int sub_step_191_2 = ((stage_v_118_2 + pub_r000913_4_2) + 9) & 127;
  int stage_v_191_1 = ((sub_step_191_1 * 2) + pub_r000913_13_1) & 127;
  int stage_v_191_2 = ((sub_step_191_2 * 2) + pub_r000913_13_2) & 127;
  st_var_1_1.buffer[2] = stage_v_191_1 & 15;
  st_var_1_2.buffer[2] = stage_v_191_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int sub_step_192_1 = ((sec_r000913_11_1 + pub_r000913_10_1) + 28) & 127;
  int sub_step_192_2 = ((sec_r000913_11_2 + pub_r000913_10_2) + 28) & 127;
  int stage_v_192_1 = ((sub_step_192_1 * 2) + pub_r000913_7_1) & 127;
  int stage_v_192_2 = ((sub_step_192_2 * 2) + pub_r000913_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_192_1 & 15;
  st_var_0_2.buffer[0] = stage_v_192_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int sub_step_193_1 = ((sec_r000913_12_1 + pub_r000913_17_1) + 6) & 127;
  int sub_step_193_2 = ((sec_r000913_12_2 + pub_r000913_17_2) + 6) & 127;
  int stage_v_193_1 = ((sub_step_193_1 * 2) + pub_r000913_1_1) & 127;
  int stage_v_193_2 = ((sub_step_193_2 * 2) + pub_r000913_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_193_1 & 15;
  st_var_1_2.buffer[1] = stage_v_193_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int sub_step_194_1 = ((stage_v_166_1 + pub_r000913_9_1) + 24) & 127;
  int sub_step_194_2 = ((stage_v_166_2 + pub_r000913_9_2) + 24) & 127;
  int stage_v_194_1 = ((sub_step_194_1 * 2) + pub_r000913_6_1) & 127;
  int stage_v_194_2 = ((sub_step_194_2 * 2) + pub_r000913_6_2) & 127;
  st_var_0_1.buffer[2] = stage_v_194_1 & 15;
  st_var_0_2.buffer[2] = stage_v_194_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int sub_step_195_1 = ((sub_step_185_1 + pub_r000913_6_1) + 31) & 127;
  int sub_step_195_2 = ((sub_step_185_2 + pub_r000913_6_2) + 31) & 127;
  int stage_v_195_1 = ((sub_step_195_1 * 2) + pub_r000913_19_1) & 127;
  int stage_v_195_2 = ((sub_step_195_2 * 2) + pub_r000913_19_2) & 127;
  st_var_1_1.buffer[0] = stage_v_195_1 & 15;
  st_var_1_2.buffer[0] = stage_v_195_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int sub_step_196_1 = ((stage_v_181_1 + pub_r000913_0_1) + 29) & 127;
  int sub_step_196_2 = ((stage_v_181_2 + pub_r000913_0_2) + 29) & 127;
  int stage_v_196_1 = ((sub_step_196_1 * 2) + pub_r000913_7_1) & 127;
  int stage_v_196_2 = ((sub_step_196_2 * 2) + pub_r000913_7_2) & 127;
  st_var_0_1.buffer[1] = stage_v_196_1 & 15;
  st_var_0_2.buffer[1] = stage_v_196_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int sub_step_197_1 = ((sub_step_136_1 + pub_r000913_7_1) + 21) & 127;
  int sub_step_197_2 = ((sub_step_136_2 + pub_r000913_7_2) + 21) & 127;
  int stage_v_197_1 = ((sub_step_197_1 * 2) + pub_r000913_13_1) & 127;
  int stage_v_197_2 = ((sub_step_197_2 * 2) + pub_r000913_13_2) & 127;
  st_var_1_1.buffer[2] = stage_v_197_1 & 15;
  st_var_1_2.buffer[2] = stage_v_197_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int sub_step_198_1 = ((sub_step_166_1 + pub_r000913_12_1) + 17) & 127;
  int sub_step_198_2 = ((sub_step_166_2 + pub_r000913_12_2) + 17) & 127;
  int stage_v_198_1 = ((sub_step_198_1 * 2) + pub_r000913_6_1) & 127;
  int stage_v_198_2 = ((sub_step_198_2 * 2) + pub_r000913_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_198_1 & 15;
  st_var_0_2.buffer[0] = stage_v_198_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int sub_step_199_1 = ((sub_step_117_1 + pub_r000913_17_1) + 35) & 127;
  int sub_step_199_2 = ((sub_step_117_2 + pub_r000913_17_2) + 35) & 127;
  int stage_v_199_1 = ((sub_step_199_1 * 2) + pub_r000913_4_1) & 127;
  int stage_v_199_2 = ((sub_step_199_2 * 2) + pub_r000913_4_2) & 127;
  st_var_1_1.buffer[1] = stage_v_199_1 & 15;
  st_var_1_2.buffer[1] = stage_v_199_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int sub_step_200_1 = ((sub_step_123_1 + pub_r000913_18_1) + 10) & 127;
  int sub_step_200_2 = ((sub_step_123_2 + pub_r000913_18_2) + 10) & 127;
  int stage_v_200_1 = ((sub_step_200_1 * 2) + pub_r000913_10_1) & 127;
  int stage_v_200_2 = ((sub_step_200_2 * 2) + pub_r000913_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_200_1 & 15;
  st_var_0_2.buffer[2] = stage_v_200_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int sub_step_201_1 = ((sec_r000913_5_1 + pub_r000913_13_1) + 17) & 127;
  int sub_step_201_2 = ((sec_r000913_5_2 + pub_r000913_13_2) + 17) & 127;
  int stage_v_201_1 = ((sub_step_201_1 * 2) + pub_r000913_3_1) & 127;
  int stage_v_201_2 = ((sub_step_201_2 * 2) + pub_r000913_3_2) & 127;
  st_var_1_1.buffer[0] = stage_v_201_1 & 15;
  st_var_1_2.buffer[0] = stage_v_201_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int sub_step_202_1 = ((stage_v_157_1 + pub_r000913_11_1) + 35) & 127;
  int sub_step_202_2 = ((stage_v_157_2 + pub_r000913_11_2) + 35) & 127;
  int stage_v_202_1 = ((sub_step_202_1 * 2) + pub_r000913_13_1) & 127;
  int stage_v_202_2 = ((sub_step_202_2 * 2) + pub_r000913_13_2) & 127;
  st_var_0_1.buffer[1] = stage_v_202_1 & 15;
  st_var_0_2.buffer[1] = stage_v_202_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int sub_step_203_1 = ((sec_r000913_3_1 + pub_r000913_18_1) + 29) & 127;
  int sub_step_203_2 = ((sec_r000913_3_2 + pub_r000913_18_2) + 29) & 127;
  int stage_v_203_1 = ((sub_step_203_1 * 2) + pub_r000913_14_1) & 127;
  int stage_v_203_2 = ((sub_step_203_2 * 2) + pub_r000913_14_2) & 127;
  st_var_1_1.buffer[2] = stage_v_203_1 & 15;
  st_var_1_2.buffer[2] = stage_v_203_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int sub_step_204_1 = ((stage_v_113_1 + pub_r000913_6_1) + 21) & 127;
  int sub_step_204_2 = ((stage_v_113_2 + pub_r000913_6_2) + 21) & 127;
  int stage_v_204_1 = ((sub_step_204_1 * 2) + pub_r000913_13_1) & 127;
  int stage_v_204_2 = ((sub_step_204_2 * 2) + pub_r000913_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_204_1 & 15;
  st_var_0_2.buffer[0] = stage_v_204_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int sub_step_205_1 = ((sec_r000913_4_1 + pub_r000913_9_1) + 18) & 127;
  int sub_step_205_2 = ((sec_r000913_4_2 + pub_r000913_9_2) + 18) & 127;
  int stage_v_205_1 = ((sub_step_205_1 * 2) + pub_r000913_2_1) & 127;
  int stage_v_205_2 = ((sub_step_205_2 * 2) + pub_r000913_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_205_1 & 15;
  st_var_1_2.buffer[1] = stage_v_205_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int sub_step_206_1 = ((sec_r000913_16_1 + pub_r000913_1_1) + 33) & 127;
  int sub_step_206_2 = ((sec_r000913_16_2 + pub_r000913_1_2) + 33) & 127;
  int stage_v_206_1 = ((sub_step_206_1 * 2) + pub_r000913_10_1) & 127;
  int stage_v_206_2 = ((sub_step_206_2 * 2) + pub_r000913_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_206_1 & 15;
  st_var_0_2.buffer[2] = stage_v_206_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int sub_step_207_1 = ((stage_v_163_1 + pub_r000913_1_1) + 24) & 127;
  int sub_step_207_2 = ((stage_v_163_2 + pub_r000913_1_2) + 24) & 127;
  int stage_v_207_1 = ((sub_step_207_1 * 2) + pub_r000913_19_1) & 127;
  int stage_v_207_2 = ((sub_step_207_2 * 2) + pub_r000913_19_2) & 127;
  st_var_1_1.buffer[0] = stage_v_207_1 & 15;
  st_var_1_2.buffer[0] = stage_v_207_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int sub_step_208_1 = ((stage_v_105_1 + pub_r000913_14_1) + 31) & 127;
  int sub_step_208_2 = ((stage_v_105_2 + pub_r000913_14_2) + 31) & 127;
  int stage_v_208_1 = ((sub_step_208_1 * 2) + pub_r000913_4_1) & 127;
  int stage_v_208_2 = ((sub_step_208_2 * 2) + pub_r000913_4_2) & 127;
  st_var_0_1.buffer[1] = stage_v_208_1 & 15;
  st_var_0_2.buffer[1] = stage_v_208_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int sub_step_209_1 = ((sub_step_182_1 + pub_r000913_9_1) + 32) & 127;
  int sub_step_209_2 = ((sub_step_182_2 + pub_r000913_9_2) + 32) & 127;
  int stage_v_209_1 = ((sub_step_209_1 * 2) + pub_r000913_17_1) & 127;
  int stage_v_209_2 = ((sub_step_209_2 * 2) + pub_r000913_17_2) & 127;
  st_var_1_1.buffer[2] = stage_v_209_1 & 15;
  st_var_1_2.buffer[2] = stage_v_209_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int sub_step_210_1 = ((sec_r000913_12_1 + pub_r000913_13_1) + 5) & 127;
  int sub_step_210_2 = ((sec_r000913_12_2 + pub_r000913_13_2) + 5) & 127;
  int stage_v_210_1 = ((sub_step_210_1 * 2) + pub_r000913_17_1) & 127;
  int stage_v_210_2 = ((sub_step_210_2 * 2) + pub_r000913_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_210_1 & 15;
  st_var_0_2.buffer[0] = stage_v_210_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int sub_step_211_1 = ((sec_r000913_1_1 + pub_r000913_1_1) + 6) & 127;
  int sub_step_211_2 = ((sec_r000913_1_2 + pub_r000913_1_2) + 6) & 127;
  int stage_v_211_1 = ((sub_step_211_1 * 2) + pub_r000913_0_1) & 127;
  int stage_v_211_2 = ((sub_step_211_2 * 2) + pub_r000913_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_211_1 & 15;
  st_var_1_2.buffer[1] = stage_v_211_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int sub_step_212_1 = ((sub_step_123_1 + pub_r000913_18_1) + 15) & 127;
  int sub_step_212_2 = ((sub_step_123_2 + pub_r000913_18_2) + 15) & 127;
  int stage_v_212_1 = ((sub_step_212_1 * 2) + pub_r000913_0_1) & 127;
  int stage_v_212_2 = ((sub_step_212_2 * 2) + pub_r000913_0_2) & 127;
  st_var_0_1.buffer[2] = stage_v_212_1 & 15;
  st_var_0_2.buffer[2] = stage_v_212_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int sub_step_213_1 = ((stage_v_151_1 + pub_r000913_16_1) + 5) & 127;
  int sub_step_213_2 = ((stage_v_151_2 + pub_r000913_16_2) + 5) & 127;
  int stage_v_213_1 = ((sub_step_213_1 * 2) + pub_r000913_12_1) & 127;
  int stage_v_213_2 = ((sub_step_213_2 * 2) + pub_r000913_12_2) & 127;
  st_var_1_1.buffer[0] = stage_v_213_1 & 15;
  st_var_1_2.buffer[0] = stage_v_213_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int sub_step_214_1 = ((stage_v_193_1 + pub_r000913_9_1) + 5) & 127;
  int sub_step_214_2 = ((stage_v_193_2 + pub_r000913_9_2) + 5) & 127;
  int stage_v_214_1 = ((sub_step_214_1 * 2) + pub_r000913_9_1) & 127;
  int stage_v_214_2 = ((sub_step_214_2 * 2) + pub_r000913_9_2) & 127;
  st_var_0_1.buffer[1] = stage_v_214_1 & 15;
  st_var_0_2.buffer[1] = stage_v_214_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int sub_step_215_1 = ((sub_step_91_1 + pub_r000913_8_1) + 11) & 127;
  int sub_step_215_2 = ((sub_step_91_2 + pub_r000913_8_2) + 11) & 127;
  int stage_v_215_1 = ((sub_step_215_1 * 2) + pub_r000913_10_1) & 127;
  int stage_v_215_2 = ((sub_step_215_2 * 2) + pub_r000913_10_2) & 127;
  st_var_1_1.buffer[2] = stage_v_215_1 & 15;
  st_var_1_2.buffer[2] = stage_v_215_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int sub_step_216_1 = ((sec_r000913_15_1 + pub_r000913_6_1) + 34) & 127;
  int sub_step_216_2 = ((sec_r000913_15_2 + pub_r000913_6_2) + 34) & 127;
  int stage_v_216_1 = ((sub_step_216_1 * 2) + pub_r000913_2_1) & 127;
  int stage_v_216_2 = ((sub_step_216_2 * 2) + pub_r000913_2_2) & 127;
  st_var_0_1.buffer[0] = stage_v_216_1 & 15;
  st_var_0_2.buffer[0] = stage_v_216_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int sub_step_217_1 = ((sub_step_213_1 + pub_r000913_11_1) + 16) & 127;
  int sub_step_217_2 = ((sub_step_213_2 + pub_r000913_11_2) + 16) & 127;
  int stage_v_217_1 = ((sub_step_217_1 * 2) + pub_r000913_18_1) & 127;
  int stage_v_217_2 = ((sub_step_217_2 * 2) + pub_r000913_18_2) & 127;
  st_var_1_1.buffer[1] = stage_v_217_1 & 15;
  st_var_1_2.buffer[1] = stage_v_217_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int sub_step_218_1 = ((sub_step_113_1 + pub_r000913_1_1) + 28) & 127;
  int sub_step_218_2 = ((sub_step_113_2 + pub_r000913_1_2) + 28) & 127;
  int stage_v_218_1 = ((sub_step_218_1 * 2) + pub_r000913_5_1) & 127;
  int stage_v_218_2 = ((sub_step_218_2 * 2) + pub_r000913_5_2) & 127;
  st_var_0_1.buffer[2] = stage_v_218_1 & 15;
  st_var_0_2.buffer[2] = stage_v_218_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int sub_step_219_1 = ((sec_r000913_7_1 + pub_r000913_17_1) + 35) & 127;
  int sub_step_219_2 = ((sec_r000913_7_2 + pub_r000913_17_2) + 35) & 127;
  int stage_v_219_1 = ((sub_step_219_1 * 2) + pub_r000913_6_1) & 127;
  int stage_v_219_2 = ((sub_step_219_2 * 2) + pub_r000913_6_2) & 127;
  st_var_1_1.buffer[0] = stage_v_219_1 & 15;
  st_var_1_2.buffer[0] = stage_v_219_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int sub_step_220_1 = ((sec_r000913_5_1 + pub_r000913_2_1) + 18) & 127;
  int sub_step_220_2 = ((sec_r000913_5_2 + pub_r000913_2_2) + 18) & 127;
  int stage_v_220_1 = ((sub_step_220_1 * 2) + pub_r000913_3_1) & 127;
  int stage_v_220_2 = ((sub_step_220_2 * 2) + pub_r000913_3_2) & 127;
  st_var_0_1.buffer[1] = stage_v_220_1 & 15;
  st_var_0_2.buffer[1] = stage_v_220_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int sub_step_221_1 = ((stage_v_213_1 + pub_r000913_12_1) + 15) & 127;
  int sub_step_221_2 = ((stage_v_213_2 + pub_r000913_12_2) + 15) & 127;
  int stage_v_221_1 = ((sub_step_221_1 * 2) + pub_r000913_14_1) & 127;
  int stage_v_221_2 = ((sub_step_221_2 * 2) + pub_r000913_14_2) & 127;
  st_var_1_1.buffer[2] = stage_v_221_1 & 15;
  st_var_1_2.buffer[2] = stage_v_221_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int sub_step_222_1 = ((sec_r000913_1_1 + pub_r000913_9_1) + 32) & 127;
  int sub_step_222_2 = ((sec_r000913_1_2 + pub_r000913_9_2) + 32) & 127;
  int stage_v_222_1 = ((sub_step_222_1 * 2) + pub_r000913_16_1) & 127;
  int stage_v_222_2 = ((sub_step_222_2 * 2) + pub_r000913_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_222_1 & 15;
  st_var_0_2.buffer[0] = stage_v_222_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int sub_step_223_1 = ((sec_r000913_16_1 + pub_r000913_17_1) + 30) & 127;
  int sub_step_223_2 = ((sec_r000913_16_2 + pub_r000913_17_2) + 30) & 127;
  int stage_v_223_1 = ((sub_step_223_1 * 2) + pub_r000913_6_1) & 127;
  int stage_v_223_2 = ((sub_step_223_2 * 2) + pub_r000913_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_223_1 & 15;
  st_var_1_2.buffer[1] = stage_v_223_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int sub_step_224_1 = ((sub_step_223_1 + pub_r000913_8_1) + 26) & 127;
  int sub_step_224_2 = ((sub_step_223_2 + pub_r000913_8_2) + 26) & 127;
  int stage_v_224_1 = ((sub_step_224_1 * 2) + pub_r000913_13_1) & 127;
  int stage_v_224_2 = ((sub_step_224_2 * 2) + pub_r000913_13_2) & 127;
  st_var_0_1.buffer[2] = stage_v_224_1 & 15;
  st_var_0_2.buffer[2] = stage_v_224_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int sub_step_225_1 = ((sub_step_128_1 + pub_r000913_14_1) + 24) & 127;
  int sub_step_225_2 = ((sub_step_128_2 + pub_r000913_14_2) + 24) & 127;
  int stage_v_225_1 = ((sub_step_225_1 * 2) + pub_r000913_1_1) & 127;
  int stage_v_225_2 = ((sub_step_225_2 * 2) + pub_r000913_1_2) & 127;
  st_var_1_1.buffer[0] = stage_v_225_1 & 15;
  st_var_1_2.buffer[0] = stage_v_225_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int sub_step_226_1 = ((sec_r000913_4_1 + pub_r000913_12_1) + 28) & 127;
  int sub_step_226_2 = ((sec_r000913_4_2 + pub_r000913_12_2) + 28) & 127;
  int stage_v_226_1 = ((sub_step_226_1 * 2) + pub_r000913_9_1) & 127;
  int stage_v_226_2 = ((sub_step_226_2 * 2) + pub_r000913_9_2) & 127;
  st_var_0_1.buffer[1] = stage_v_226_1 & 15;
  st_var_0_2.buffer[1] = stage_v_226_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int sub_step_227_1 = ((sec_r000913_15_1 + pub_r000913_18_1) + 27) & 127;
  int sub_step_227_2 = ((sec_r000913_15_2 + pub_r000913_18_2) + 27) & 127;
  int stage_v_227_1 = ((sub_step_227_1 * 2) + pub_r000913_6_1) & 127;
  int stage_v_227_2 = ((sub_step_227_2 * 2) + pub_r000913_6_2) & 127;
  st_var_1_1.buffer[2] = stage_v_227_1 & 15;
  st_var_1_2.buffer[2] = stage_v_227_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int sub_step_228_1 = ((sub_step_95_1 + pub_r000913_10_1) + 13) & 127;
  int sub_step_228_2 = ((sub_step_95_2 + pub_r000913_10_2) + 13) & 127;
  int stage_v_228_1 = ((sub_step_228_1 * 2) + pub_r000913_9_1) & 127;
  int stage_v_228_2 = ((sub_step_228_2 * 2) + pub_r000913_9_2) & 127;
  st_var_0_1.buffer[0] = stage_v_228_1 & 15;
  st_var_0_2.buffer[0] = stage_v_228_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int sub_step_229_1 = ((stage_v_204_1 + pub_r000913_9_1) + 21) & 127;
  int sub_step_229_2 = ((stage_v_204_2 + pub_r000913_9_2) + 21) & 127;
  int stage_v_229_1 = ((sub_step_229_1 * 2) + pub_r000913_3_1) & 127;
  int stage_v_229_2 = ((sub_step_229_2 * 2) + pub_r000913_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_229_1 & 15;
  st_var_1_2.buffer[1] = stage_v_229_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int sub_step_230_1 = ((sec_r000913_7_1 + pub_r000913_19_1) + 7) & 127;
  int sub_step_230_2 = ((sec_r000913_7_2 + pub_r000913_19_2) + 7) & 127;
  int stage_v_230_1 = ((sub_step_230_1 * 2) + pub_r000913_4_1) & 127;
  int stage_v_230_2 = ((sub_step_230_2 * 2) + pub_r000913_4_2) & 127;
  st_var_0_1.buffer[2] = stage_v_230_1 & 15;
  st_var_0_2.buffer[2] = stage_v_230_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int sub_step_231_1 = ((stage_v_141_1 + pub_r000913_17_1) + 26) & 127;
  int sub_step_231_2 = ((stage_v_141_2 + pub_r000913_17_2) + 26) & 127;
  int stage_v_231_1 = ((sub_step_231_1 * 2) + pub_r000913_4_1) & 127;
  int stage_v_231_2 = ((sub_step_231_2 * 2) + pub_r000913_4_2) & 127;
  st_var_1_1.buffer[0] = stage_v_231_1 & 15;
  st_var_1_2.buffer[0] = stage_v_231_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int sub_step_232_1 = ((sub_step_93_1 + pub_r000913_12_1) + 23) & 127;
  int sub_step_232_2 = ((sub_step_93_2 + pub_r000913_12_2) + 23) & 127;
  int stage_v_232_1 = ((sub_step_232_1 * 2) + pub_r000913_7_1) & 127;
  int stage_v_232_2 = ((sub_step_232_2 * 2) + pub_r000913_7_2) & 127;
  st_var_0_1.buffer[1] = stage_v_232_1 & 15;
  st_var_0_2.buffer[1] = stage_v_232_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int sub_step_233_1 = ((sec_r000913_2_1 + pub_r000913_20_1) + 30) & 127;
  int sub_step_233_2 = ((sec_r000913_2_2 + pub_r000913_20_2) + 30) & 127;
  int stage_v_233_1 = ((sub_step_233_1 * 2) + pub_r000913_10_1) & 127;
  int stage_v_233_2 = ((sub_step_233_2 * 2) + pub_r000913_10_2) & 127;
  st_var_1_1.buffer[2] = stage_v_233_1 & 15;
  st_var_1_2.buffer[2] = stage_v_233_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int sub_step_234_1 = ((sec_r000913_13_1 + pub_r000913_8_1) + 20) & 127;
  int sub_step_234_2 = ((sec_r000913_13_2 + pub_r000913_8_2) + 20) & 127;
  int stage_v_234_1 = ((sub_step_234_1 * 2) + pub_r000913_5_1) & 127;
  int stage_v_234_2 = ((sub_step_234_2 * 2) + pub_r000913_5_2) & 127;
  st_var_0_1.buffer[0] = stage_v_234_1 & 15;
  st_var_0_2.buffer[0] = stage_v_234_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int sub_step_235_1 = ((sec_r000913_0_1 + pub_r000913_6_1) + 34) & 127;
  int sub_step_235_2 = ((sec_r000913_0_2 + pub_r000913_6_2) + 34) & 127;
  int stage_v_235_1 = ((sub_step_235_1 * 2) + pub_r000913_0_1) & 127;
  int stage_v_235_2 = ((sub_step_235_2 * 2) + pub_r000913_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_235_1 & 15;
  st_var_1_2.buffer[1] = stage_v_235_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int sub_step_236_1 = ((stage_v_171_1 + pub_r000913_17_1) + 16) & 127;
  int sub_step_236_2 = ((stage_v_171_2 + pub_r000913_17_2) + 16) & 127;
  int stage_v_236_1 = ((sub_step_236_1 * 2) + pub_r000913_10_1) & 127;
  int stage_v_236_2 = ((sub_step_236_2 * 2) + pub_r000913_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_236_1 & 15;
  st_var_0_2.buffer[2] = stage_v_236_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int sub_step_237_1 = ((stage_v_233_1 + pub_r000913_5_1) + 28) & 127;
  int sub_step_237_2 = ((stage_v_233_2 + pub_r000913_5_2) + 28) & 127;
  int stage_v_237_1 = ((sub_step_237_1 * 2) + pub_r000913_3_1) & 127;
  int stage_v_237_2 = ((sub_step_237_2 * 2) + pub_r000913_3_2) & 127;
  st_var_1_1.buffer[0] = stage_v_237_1 & 15;
  st_var_1_2.buffer[0] = stage_v_237_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int sub_step_238_1 = ((stage_v_93_1 + pub_r000913_5_1) + 23) & 127;
  int sub_step_238_2 = ((stage_v_93_2 + pub_r000913_5_2) + 23) & 127;
  int stage_v_238_1 = ((sub_step_238_1 * 2) + pub_r000913_0_1) & 127;
  int stage_v_238_2 = ((sub_step_238_2 * 2) + pub_r000913_0_2) & 127;
  st_var_0_1.buffer[1] = stage_v_238_1 & 15;
  st_var_0_2.buffer[1] = stage_v_238_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int sub_step_239_1 = ((sub_step_167_1 + pub_r000913_9_1) + 7) & 127;
  int sub_step_239_2 = ((sub_step_167_2 + pub_r000913_9_2) + 7) & 127;
  int stage_v_239_1 = ((sub_step_239_1 * 2) + pub_r000913_18_1) & 127;
  int stage_v_239_2 = ((sub_step_239_2 * 2) + pub_r000913_18_2) & 127;
  st_var_1_1.buffer[2] = stage_v_239_1 & 15;
  st_var_1_2.buffer[2] = stage_v_239_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int sub_step_240_1 = ((sec_r000913_4_1 + pub_r000913_19_1) + 25) & 127;
  int sub_step_240_2 = ((sec_r000913_4_2 + pub_r000913_19_2) + 25) & 127;
  int stage_v_240_1 = ((sub_step_240_1 * 2) + pub_r000913_16_1) & 127;
  int stage_v_240_2 = ((sub_step_240_2 * 2) + pub_r000913_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_240_1 & 15;
  st_var_0_2.buffer[0] = stage_v_240_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int sub_step_241_1 = ((sub_step_119_1 + pub_r000913_8_1) + 35) & 127;
  int sub_step_241_2 = ((sub_step_119_2 + pub_r000913_8_2) + 35) & 127;
  int stage_v_241_1 = ((sub_step_241_1 * 2) + pub_r000913_10_1) & 127;
  int stage_v_241_2 = ((sub_step_241_2 * 2) + pub_r000913_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_241_1 & 15;
  st_var_1_2.buffer[1] = stage_v_241_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int sub_step_242_1 = ((sec_r000913_11_1 + pub_r000913_19_1) + 12) & 127;
  int sub_step_242_2 = ((sec_r000913_11_2 + pub_r000913_19_2) + 12) & 127;
  int stage_v_242_1 = ((sub_step_242_1 * 2) + pub_r000913_4_1) & 127;
  int stage_v_242_2 = ((sub_step_242_2 * 2) + pub_r000913_4_2) & 127;
  st_var_0_1.buffer[2] = stage_v_242_1 & 15;
  st_var_0_2.buffer[2] = stage_v_242_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int sub_step_243_1 = ((sec_r000913_14_1 + pub_r000913_9_1) + 32) & 127;
  int sub_step_243_2 = ((sec_r000913_14_2 + pub_r000913_9_2) + 32) & 127;
  int stage_v_243_1 = ((sub_step_243_1 * 2) + pub_r000913_13_1) & 127;
  int stage_v_243_2 = ((sub_step_243_2 * 2) + pub_r000913_13_2) & 127;
  st_var_1_1.buffer[0] = stage_v_243_1 & 15;
  st_var_1_2.buffer[0] = stage_v_243_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int sub_step_244_1 = ((stage_v_177_1 + pub_r000913_12_1) + 23) & 127;
  int sub_step_244_2 = ((stage_v_177_2 + pub_r000913_12_2) + 23) & 127;
  int stage_v_244_1 = ((sub_step_244_1 * 2) + pub_r000913_5_1) & 127;
  int stage_v_244_2 = ((sub_step_244_2 * 2) + pub_r000913_5_2) & 127;
  st_var_0_1.buffer[1] = stage_v_244_1 & 15;
  st_var_0_2.buffer[1] = stage_v_244_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int sub_step_245_1 = ((sec_r000913_8_1 + pub_r000913_0_1) + 31) & 127;
  int sub_step_245_2 = ((sec_r000913_8_2 + pub_r000913_0_2) + 31) & 127;
  int stage_v_245_1 = ((sub_step_245_1 * 2) + pub_r000913_1_1) & 127;
  int stage_v_245_2 = ((sub_step_245_2 * 2) + pub_r000913_1_2) & 127;
  st_var_1_1.buffer[2] = stage_v_245_1 & 15;
  st_var_1_2.buffer[2] = stage_v_245_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int sub_step_246_1 = ((stage_v_143_1 + pub_r000913_12_1) + 30) & 127;
  int sub_step_246_2 = ((stage_v_143_2 + pub_r000913_12_2) + 30) & 127;
  int stage_v_246_1 = ((sub_step_246_1 * 2) + pub_r000913_3_1) & 127;
  int stage_v_246_2 = ((sub_step_246_2 * 2) + pub_r000913_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_246_1 & 15;
  st_var_0_2.buffer[0] = stage_v_246_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int sub_step_247_1 = ((sec_r000913_13_1 + pub_r000913_20_1) + 6) & 127;
  int sub_step_247_2 = ((sec_r000913_13_2 + pub_r000913_20_2) + 6) & 127;
  int stage_v_247_1 = ((sub_step_247_1 * 2) + pub_r000913_20_1) & 127;
  int stage_v_247_2 = ((sub_step_247_2 * 2) + pub_r000913_20_2) & 127;
  st_var_1_1.buffer[1] = stage_v_247_1 & 15;
  st_var_1_2.buffer[1] = stage_v_247_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000913_13_1 != sec_r000913_13_2);
  __CPROVER_assume(sec_r000913_12_1 != sec_r000913_12_2);
  __CPROVER_assume(pub_r000913_8_1 == pub_r000913_8_2);
  __CPROVER_assume(pub_r000913_10_1 == pub_r000913_10_2);
  __CPROVER_assume(sec_r000913_3_1 != sec_r000913_3_2);
  __CPROVER_assume(sec_r000913_4_1 != sec_r000913_4_2);
  __CPROVER_assume(pub_r000913_13_1 == pub_r000913_13_2);
  __CPROVER_assume(pub_r000913_9_1 == pub_r000913_9_2);
  __CPROVER_assume(pub_r000913_7_1 == pub_r000913_7_2);
  __CPROVER_assume(sec_r000913_9_1 != sec_r000913_9_2);
  __CPROVER_assume(pub_r000913_18_1 == pub_r000913_18_2);
  __CPROVER_assume(pub_r000913_12_1 == pub_r000913_12_2);
  __CPROVER_assume(pub_r000913_6_1 == pub_r000913_6_2);
  __CPROVER_assume(sec_r000913_0_1 != sec_r000913_0_2);
  __CPROVER_assume(pub_r000913_3_1 == pub_r000913_3_2);
  __CPROVER_assume(sec_r000913_16_1 != sec_r000913_16_2);
  __CPROVER_assume(sec_r000913_11_1 != sec_r000913_11_2);
  __CPROVER_assume(sec_r000913_10_1 != sec_r000913_10_2);
  __CPROVER_assume(sec_r000913_2_1 != sec_r000913_2_2);
  __CPROVER_assume(sec_r000913_6_1 != sec_r000913_6_2);
  __CPROVER_assume(pub_r000913_15_1 == pub_r000913_15_2);
  __CPROVER_assume(pub_r000913_20_1 == pub_r000913_20_2);
  __CPROVER_assume(pub_r000913_2_1 == pub_r000913_2_2);
  __CPROVER_assume(pub_r000913_17_1 == pub_r000913_17_2);
  __CPROVER_assume(pub_r000913_1_1 == pub_r000913_1_2);
  __CPROVER_assume(sec_r000913_1_1 != sec_r000913_1_2);
  __CPROVER_assume(pub_r000913_5_1 == pub_r000913_5_2);
  __CPROVER_assume(pub_r000913_4_1 == pub_r000913_4_2);
  __CPROVER_assume(pub_r000913_11_1 == pub_r000913_11_2);
  __CPROVER_assume(sec_r000913_8_1 != sec_r000913_8_2);
  __CPROVER_assume(sec_r000913_14_1 != sec_r000913_14_2);
  __CPROVER_assume(sec_r000913_5_1 != sec_r000913_5_2);
  __CPROVER_assume(sec_r000913_7_1 != sec_r000913_7_2);
  __CPROVER_assume(sec_r000913_15_1 != sec_r000913_15_2);
  __CPROVER_assume(pub_r000913_0_1 == pub_r000913_0_2);
  __CPROVER_assume(pub_r000913_19_1 == pub_r000913_19_2);
  __CPROVER_assume(pub_r000913_16_1 == pub_r000913_16_2);
  __CPROVER_assume(pub_r000913_14_1 == pub_r000913_14_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
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
  assert(sub_step_90_1 == sub_step_90_2);
  assert(stage_v_90_1 == stage_v_90_2);
  assert(sub_step_91_1 == sub_step_91_2);
  assert(stage_v_91_1 == stage_v_91_2);
  assert(sub_step_92_1 == sub_step_92_2);
  assert(stage_v_92_1 == stage_v_92_2);
  assert(sub_step_93_1 == sub_step_93_2);
  assert(stage_v_93_1 == stage_v_93_2);
  assert(sub_step_94_1 == sub_step_94_2);
  assert(stage_v_94_1 == stage_v_94_2);
  assert(sub_step_95_1 == sub_step_95_2);
  assert(stage_v_95_1 == stage_v_95_2);
  assert(sub_step_96_1 == sub_step_96_2);
  assert(stage_v_96_1 == stage_v_96_2);
  assert(sub_step_97_1 == sub_step_97_2);
  assert(stage_v_97_1 == stage_v_97_2);
  assert(sub_step_98_1 == sub_step_98_2);
  assert(stage_v_98_1 == stage_v_98_2);
  assert(sub_step_99_1 == sub_step_99_2);
  assert(stage_v_99_1 == stage_v_99_2);
  assert(sub_step_100_1 == sub_step_100_2);
  assert(stage_v_100_1 == stage_v_100_2);
  assert(sub_step_101_1 == sub_step_101_2);
  assert(stage_v_101_1 == stage_v_101_2);
  assert(sub_step_102_1 == sub_step_102_2);
  assert(stage_v_102_1 == stage_v_102_2);
  assert(sub_step_103_1 == sub_step_103_2);
  assert(stage_v_103_1 == stage_v_103_2);
  assert(sub_step_104_1 == sub_step_104_2);
  assert(stage_v_104_1 == stage_v_104_2);
  assert(sub_step_105_1 == sub_step_105_2);
  assert(stage_v_105_1 == stage_v_105_2);
  assert(sub_step_106_1 == sub_step_106_2);
  assert(stage_v_106_1 == stage_v_106_2);
  assert(sub_step_107_1 == sub_step_107_2);
  assert(stage_v_107_1 == stage_v_107_2);
  assert(sub_step_108_1 == sub_step_108_2);
  assert(stage_v_108_1 == stage_v_108_2);
  assert(sub_step_109_1 == sub_step_109_2);
  assert(stage_v_109_1 == stage_v_109_2);
  assert(sub_step_110_1 == sub_step_110_2);
  assert(stage_v_110_1 == stage_v_110_2);
  assert(sub_step_111_1 == sub_step_111_2);
  assert(stage_v_111_1 == stage_v_111_2);
  assert(sub_step_112_1 == sub_step_112_2);
  assert(stage_v_112_1 == stage_v_112_2);
  assert(sub_step_113_1 == sub_step_113_2);
  assert(stage_v_113_1 == stage_v_113_2);
  assert(sub_step_114_1 == sub_step_114_2);
  assert(stage_v_114_1 == stage_v_114_2);
  assert(sub_step_115_1 == sub_step_115_2);
  assert(stage_v_115_1 == stage_v_115_2);
  assert(sub_step_116_1 == sub_step_116_2);
  assert(stage_v_116_1 == stage_v_116_2);
  assert(sub_step_117_1 == sub_step_117_2);
  assert(stage_v_117_1 == stage_v_117_2);
  assert(sub_step_118_1 == sub_step_118_2);
  assert(stage_v_118_1 == stage_v_118_2);
  assert(sub_step_119_1 == sub_step_119_2);
  assert(stage_v_119_1 == stage_v_119_2);
  assert(sub_step_120_1 == sub_step_120_2);
  assert(stage_v_120_1 == stage_v_120_2);
  assert(sub_step_121_1 == sub_step_121_2);
  assert(stage_v_121_1 == stage_v_121_2);
  assert(sub_step_122_1 == sub_step_122_2);
  assert(stage_v_122_1 == stage_v_122_2);
  assert(sub_step_123_1 == sub_step_123_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(sub_step_124_1 == sub_step_124_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(sub_step_125_1 == sub_step_125_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(sub_step_126_1 == sub_step_126_2);
  assert(stage_v_126_1 == stage_v_126_2);
  assert(sub_step_127_1 == sub_step_127_2);
  assert(stage_v_127_1 == stage_v_127_2);
  assert(sub_step_128_1 == sub_step_128_2);
  assert(stage_v_128_1 == stage_v_128_2);
  assert(sub_step_129_1 == sub_step_129_2);
  assert(stage_v_129_1 == stage_v_129_2);
  assert(sub_step_130_1 == sub_step_130_2);
  assert(stage_v_130_1 == stage_v_130_2);
  assert(sub_step_131_1 == sub_step_131_2);
  assert(stage_v_131_1 == stage_v_131_2);
  assert(sub_step_132_1 == sub_step_132_2);
  assert(stage_v_132_1 == stage_v_132_2);
  assert(sub_step_133_1 == sub_step_133_2);
  assert(stage_v_133_1 == stage_v_133_2);
  assert(sub_step_134_1 == sub_step_134_2);
  assert(stage_v_134_1 == stage_v_134_2);
  assert(sub_step_135_1 == sub_step_135_2);
  assert(stage_v_135_1 == stage_v_135_2);
  assert(sub_step_136_1 == sub_step_136_2);
  assert(stage_v_136_1 == stage_v_136_2);
  assert(sub_step_137_1 == sub_step_137_2);
  assert(stage_v_137_1 == stage_v_137_2);
  assert(sub_step_138_1 == sub_step_138_2);
  assert(stage_v_138_1 == stage_v_138_2);
  assert(sub_step_139_1 == sub_step_139_2);
  assert(stage_v_139_1 == stage_v_139_2);
  assert(sub_step_140_1 == sub_step_140_2);
  assert(stage_v_140_1 == stage_v_140_2);
  assert(sub_step_141_1 == sub_step_141_2);
  assert(stage_v_141_1 == stage_v_141_2);
  assert(sub_step_142_1 == sub_step_142_2);
  assert(stage_v_142_1 == stage_v_142_2);
  assert(sub_step_143_1 == sub_step_143_2);
  assert(stage_v_143_1 == stage_v_143_2);
  assert(sub_step_144_1 == sub_step_144_2);
  assert(stage_v_144_1 == stage_v_144_2);
  assert(sub_step_145_1 == sub_step_145_2);
  assert(stage_v_145_1 == stage_v_145_2);
  assert(sub_step_146_1 == sub_step_146_2);
  assert(stage_v_146_1 == stage_v_146_2);
  assert(sub_step_147_1 == sub_step_147_2);
  assert(stage_v_147_1 == stage_v_147_2);
  assert(sub_step_148_1 == sub_step_148_2);
  assert(stage_v_148_1 == stage_v_148_2);
  assert(sub_step_149_1 == sub_step_149_2);
  assert(stage_v_149_1 == stage_v_149_2);
  assert(sub_step_150_1 == sub_step_150_2);
  assert(stage_v_150_1 == stage_v_150_2);
  assert(sub_step_151_1 == sub_step_151_2);
  assert(stage_v_151_1 == stage_v_151_2);
  assert(sub_step_152_1 == sub_step_152_2);
  assert(stage_v_152_1 == stage_v_152_2);
  assert(sub_step_153_1 == sub_step_153_2);
  assert(stage_v_153_1 == stage_v_153_2);
  assert(sub_step_154_1 == sub_step_154_2);
  assert(stage_v_154_1 == stage_v_154_2);
  assert(sub_step_155_1 == sub_step_155_2);
  assert(stage_v_155_1 == stage_v_155_2);
  assert(sub_step_156_1 == sub_step_156_2);
  assert(stage_v_156_1 == stage_v_156_2);
  assert(sub_step_157_1 == sub_step_157_2);
  assert(stage_v_157_1 == stage_v_157_2);
  assert(sub_step_158_1 == sub_step_158_2);
  assert(stage_v_158_1 == stage_v_158_2);
  assert(sub_step_159_1 == sub_step_159_2);
  assert(stage_v_159_1 == stage_v_159_2);
  assert(sub_step_160_1 == sub_step_160_2);
  assert(stage_v_160_1 == stage_v_160_2);
  assert(sub_step_161_1 == sub_step_161_2);
  assert(stage_v_161_1 == stage_v_161_2);
  assert(sub_step_162_1 == sub_step_162_2);
  assert(stage_v_162_1 == stage_v_162_2);
  assert(sub_step_163_1 == sub_step_163_2);
  assert(stage_v_163_1 == stage_v_163_2);
  assert(sub_step_164_1 == sub_step_164_2);
  assert(stage_v_164_1 == stage_v_164_2);
  assert(sub_step_165_1 == sub_step_165_2);
  assert(stage_v_165_1 == stage_v_165_2);
  assert(sub_step_166_1 == sub_step_166_2);
  assert(stage_v_166_1 == stage_v_166_2);
  assert(sub_step_167_1 == sub_step_167_2);
  assert(stage_v_167_1 == stage_v_167_2);
  assert(sub_step_168_1 == sub_step_168_2);
  assert(stage_v_168_1 == stage_v_168_2);
  assert(sub_step_169_1 == sub_step_169_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(sub_step_170_1 == sub_step_170_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(sub_step_171_1 == sub_step_171_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(sub_step_172_1 == sub_step_172_2);
  assert(stage_v_172_1 == stage_v_172_2);
  assert(sub_step_173_1 == sub_step_173_2);
  assert(stage_v_173_1 == stage_v_173_2);
  assert(sub_step_174_1 == sub_step_174_2);
  assert(stage_v_174_1 == stage_v_174_2);
  assert(sub_step_175_1 == sub_step_175_2);
  assert(stage_v_175_1 == stage_v_175_2);
  assert(sub_step_176_1 == sub_step_176_2);
  assert(stage_v_176_1 == stage_v_176_2);
  assert(sub_step_177_1 == sub_step_177_2);
  assert(stage_v_177_1 == stage_v_177_2);
  assert(sub_step_178_1 == sub_step_178_2);
  assert(stage_v_178_1 == stage_v_178_2);
  assert(sub_step_179_1 == sub_step_179_2);
  assert(stage_v_179_1 == stage_v_179_2);
  assert(sub_step_180_1 == sub_step_180_2);
  assert(stage_v_180_1 == stage_v_180_2);
  assert(sub_step_181_1 == sub_step_181_2);
  assert(stage_v_181_1 == stage_v_181_2);
  assert(sub_step_182_1 == sub_step_182_2);
  assert(stage_v_182_1 == stage_v_182_2);
  assert(sub_step_183_1 == sub_step_183_2);
  assert(stage_v_183_1 == stage_v_183_2);
  assert(sub_step_184_1 == sub_step_184_2);
  assert(stage_v_184_1 == stage_v_184_2);
  assert(sub_step_185_1 == sub_step_185_2);
  assert(stage_v_185_1 == stage_v_185_2);
  assert(sub_step_186_1 == sub_step_186_2);
  assert(stage_v_186_1 == stage_v_186_2);
  assert(sub_step_187_1 == sub_step_187_2);
  assert(stage_v_187_1 == stage_v_187_2);
  assert(sub_step_188_1 == sub_step_188_2);
  assert(stage_v_188_1 == stage_v_188_2);
  assert(sub_step_189_1 == sub_step_189_2);
  assert(stage_v_189_1 == stage_v_189_2);
  assert(sub_step_190_1 == sub_step_190_2);
  assert(stage_v_190_1 == stage_v_190_2);
  assert(sub_step_191_1 == sub_step_191_2);
  assert(stage_v_191_1 == stage_v_191_2);
  assert(sub_step_192_1 == sub_step_192_2);
  assert(stage_v_192_1 == stage_v_192_2);
  assert(sub_step_193_1 == sub_step_193_2);
  assert(stage_v_193_1 == stage_v_193_2);
  assert(sub_step_194_1 == sub_step_194_2);
  assert(stage_v_194_1 == stage_v_194_2);
  assert(sub_step_195_1 == sub_step_195_2);
  assert(stage_v_195_1 == stage_v_195_2);
  assert(sub_step_196_1 == sub_step_196_2);
  assert(stage_v_196_1 == stage_v_196_2);
  assert(sub_step_197_1 == sub_step_197_2);
  assert(stage_v_197_1 == stage_v_197_2);
  assert(sub_step_198_1 == sub_step_198_2);
  assert(stage_v_198_1 == stage_v_198_2);
  assert(sub_step_199_1 == sub_step_199_2);
  assert(stage_v_199_1 == stage_v_199_2);
  assert(sub_step_200_1 == sub_step_200_2);
  assert(stage_v_200_1 == stage_v_200_2);
  assert(sub_step_201_1 == sub_step_201_2);
  assert(stage_v_201_1 == stage_v_201_2);
  assert(sub_step_202_1 == sub_step_202_2);
  assert(stage_v_202_1 == stage_v_202_2);
  assert(sub_step_203_1 == sub_step_203_2);
  assert(stage_v_203_1 == stage_v_203_2);
  assert(sub_step_204_1 == sub_step_204_2);
  assert(stage_v_204_1 == stage_v_204_2);
  assert(sub_step_205_1 == sub_step_205_2);
  assert(stage_v_205_1 == stage_v_205_2);
  assert(sub_step_206_1 == sub_step_206_2);
  assert(stage_v_206_1 == stage_v_206_2);
  assert(sub_step_207_1 == sub_step_207_2);
  assert(stage_v_207_1 == stage_v_207_2);
  assert(sub_step_208_1 == sub_step_208_2);
  assert(stage_v_208_1 == stage_v_208_2);
  assert(sub_step_209_1 == sub_step_209_2);
  assert(stage_v_209_1 == stage_v_209_2);
  assert(sub_step_210_1 == sub_step_210_2);
  assert(stage_v_210_1 == stage_v_210_2);
  assert(sub_step_211_1 == sub_step_211_2);
  assert(stage_v_211_1 == stage_v_211_2);
  assert(sub_step_212_1 == sub_step_212_2);
  assert(stage_v_212_1 == stage_v_212_2);
  assert(sub_step_213_1 == sub_step_213_2);
  assert(stage_v_213_1 == stage_v_213_2);
  assert(sub_step_214_1 == sub_step_214_2);
  assert(stage_v_214_1 == stage_v_214_2);
  assert(sub_step_215_1 == sub_step_215_2);
  assert(stage_v_215_1 == stage_v_215_2);
  assert(sub_step_216_1 == sub_step_216_2);
  assert(stage_v_216_1 == stage_v_216_2);
  assert(sub_step_217_1 == sub_step_217_2);
  assert(stage_v_217_1 == stage_v_217_2);
  assert(sub_step_218_1 == sub_step_218_2);
  assert(stage_v_218_1 == stage_v_218_2);
  assert(sub_step_219_1 == sub_step_219_2);
  assert(stage_v_219_1 == stage_v_219_2);
  assert(sub_step_220_1 == sub_step_220_2);
  assert(stage_v_220_1 == stage_v_220_2);
  assert(sub_step_221_1 == sub_step_221_2);
  assert(stage_v_221_1 == stage_v_221_2);
  assert(sub_step_222_1 == sub_step_222_2);
  assert(stage_v_222_1 == stage_v_222_2);
  assert(sub_step_223_1 == sub_step_223_2);
  assert(stage_v_223_1 == stage_v_223_2);
  assert(sub_step_224_1 == sub_step_224_2);
  assert(stage_v_224_1 == stage_v_224_2);
  assert(sub_step_225_1 == sub_step_225_2);
  assert(stage_v_225_1 == stage_v_225_2);
  assert(sub_step_226_1 == sub_step_226_2);
  assert(stage_v_226_1 == stage_v_226_2);
  assert(sub_step_227_1 == sub_step_227_2);
  assert(stage_v_227_1 == stage_v_227_2);
  assert(sub_step_228_1 == sub_step_228_2);
  assert(stage_v_228_1 == stage_v_228_2);
  assert(sub_step_229_1 == sub_step_229_2);
  assert(stage_v_229_1 == stage_v_229_2);
  assert(sub_step_230_1 == sub_step_230_2);
  assert(stage_v_230_1 == stage_v_230_2);
  assert(sub_step_231_1 == sub_step_231_2);
  assert(stage_v_231_1 == stage_v_231_2);
  assert(sub_step_232_1 == sub_step_232_2);
  assert(stage_v_232_1 == stage_v_232_2);
  assert(sub_step_233_1 == sub_step_233_2);
  assert(stage_v_233_1 == stage_v_233_2);
  assert(sub_step_234_1 == sub_step_234_2);
  assert(stage_v_234_1 == stage_v_234_2);
  assert(sub_step_235_1 == sub_step_235_2);
  assert(stage_v_235_1 == stage_v_235_2);
  assert(sub_step_236_1 == sub_step_236_2);
  assert(stage_v_236_1 == stage_v_236_2);
  assert(sub_step_237_1 == sub_step_237_2);
  assert(stage_v_237_1 == stage_v_237_2);
  assert(sub_step_238_1 == sub_step_238_2);
  assert(stage_v_238_1 == stage_v_238_2);
  assert(sub_step_239_1 == sub_step_239_2);
  assert(stage_v_239_1 == stage_v_239_2);
  assert(sub_step_240_1 == sub_step_240_2);
  assert(stage_v_240_1 == stage_v_240_2);
  assert(sub_step_241_1 == sub_step_241_2);
  assert(stage_v_241_1 == stage_v_241_2);
  assert(sub_step_242_1 == sub_step_242_2);
  assert(stage_v_242_1 == stage_v_242_2);
  assert(sub_step_243_1 == sub_step_243_2);
  assert(stage_v_243_1 == stage_v_243_2);
  assert(sub_step_244_1 == sub_step_244_2);
  assert(stage_v_244_1 == stage_v_244_2);
  assert(sub_step_245_1 == sub_step_245_2);
  assert(stage_v_245_1 == stage_v_245_2);
  assert(sub_step_246_1 == sub_step_246_2);
  assert(stage_v_246_1 == stage_v_246_2);
  assert(sub_step_247_1 == sub_step_247_2);
  assert(stage_v_247_1 == stage_v_247_2);
}


