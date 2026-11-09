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
struct Transaction_R001690_9013_0
{
  int balance;
  int status;
  int auth_code;
  unsigned char rate;
  int account_id;
  int buffer[3];
};
struct Vector3D_R001690_9013_1
{
  short coord_z;
  int coord_y;
  int heading;
  int coord_x;
  int buffer[3];
};
struct MatrixBlock_R001690_9013_2
{
  unsigned char stride;
  short scale;
  int density;
  int trace;
  int determinant;
  int buffer[3];
};
struct CipherContext_R001690_9013_3
{
  unsigned char round_key;
  unsigned char nonce;
  int counter;
  int buffer[3];
};
union ColorPixel_R001690_9013_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001690_9013_1
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
void fn_R001690_9013_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001690_9013_2 st_1 = {0};
  struct MatrixBlock_R001690_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int factor_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_19_1)
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

  switch (factor_19_2)
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

  int index_reg_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_37_1) & 63;
  aux_2 = (aux_2 + index_reg_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_19_1 == factor_19_2);
  assert(index_reg_37_1 == index_reg_37_2);
}

int fn_R001690_9013_0(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001690_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int factor_19 = (aux + st.buffer[1]) & 3;
  switch (factor_19)
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

  int index_reg_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_37) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001690_9013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001690_9013_3 st_1 = {0};
  struct CipherContext_R001690_9013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_31_1 = local_arr_1[aux_1 % 3];
  int damping_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_31_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_42_1) & 63;
  aux_2 = (aux_2 + tracker_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_31_1 == damping_31_2);
  assert(tracker_42_1 == tracker_42_2);
}

int fn_R001690_9013_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001690_9013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int damping_31 = local_arr[aux % 3];
  acc = (acc + (damping_31 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_42) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001690_9013_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001690_9013_3 st_1 = {0};
  struct CipherContext_R001690_9013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_54_1) & 63;
  aux_2 = (aux_2 + quantum_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_88_1 > 34)
  {
    acc_1 = ((acc_1 + (accumulator_88_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_88_2 > 34)
  {
    acc_2 = ((acc_2 + (accumulator_88_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_88_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_54_1 == quantum_54_2);
  assert(accumulator_88_1 == accumulator_88_2);
}

int fn_R001690_9013_2(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001690_9013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_54) & 63;
  acc ^= aux;
  int accumulator_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_88 > 34)
  {
    acc = ((acc + (accumulator_88 * 2)) + 5) & 127;
    aux ^= accumulator_88 & 15;
  }
  else
  {
    acc = ((acc - accumulator_88) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001690_9013_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001690_9013_1 st_1 = {0};
  struct Vector3D_R001690_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int quotient_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_94_1)
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

  switch (quotient_94_2)
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
  int phase_94_1 = local_arr_1[aux_1 % 3];
  int phase_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_94_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_94_1 == quotient_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_94_1 == phase_94_2);
}

int fn_R001690_9013_3(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001690_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quotient_94 = (aux + st.buffer[1]) & 3;
  switch (quotient_94)
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
  int phase_94 = local_arr[aux % 3];
  acc = (acc + (phase_94 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001690_9013_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001690_9013_3 st_1 = {0};
  struct CipherContext_R001690_9013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int tally_95_1 = 0;
  int tally_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_95_1 = ((tally_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_95_2 = ((tally_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_95_1) & 127;
    acc_2 = (acc_2 + tally_95_2) & 127;
  }

  int segment_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_54_1) & 63;
  aux_2 = (aux_2 + segment_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_95_1 == tally_95_2);
  assert(segment_54_1 == segment_54_2);
}

int fn_R001690_9013_4(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001690_9013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int tally_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_95 = ((tally_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_95) & 127;
  }

  int segment_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001690_9013_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001690_9013_3 st_1 = {0};
  struct CipherContext_R001690_9013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_14_1 = local_arr_1[aux_1 % 3];
  int anchor_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_14_2 * 2)) & 127;
  int tracker_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_17_1 > 12)
  {
    acc_1 = ((acc_1 + (tracker_17_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_17_2 > 12)
  {
    acc_2 = ((acc_2 + (tracker_17_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_12_1 = 0;
  int stride_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_12_1 = ((stride_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_12_2 = ((stride_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_12_1) & 127;
    acc_2 = (acc_2 + stride_12_2) & 127;
  }

  int quotient_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_90_1)
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

  switch (quotient_90_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_14_1 == anchor_14_2);
  assert(tracker_17_1 == tracker_17_2);
  assert(stride_12_1 == stride_12_2);
  assert(quotient_90_1 == quotient_90_2);
}

int fn_R001690_9013_5(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001690_9013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int anchor_14 = local_arr[aux % 3];
  acc = (acc + (anchor_14 * 2)) & 127;
  int tracker_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_17 > 12)
  {
    acc = ((acc + (tracker_17 * 2)) + 5) & 127;
    aux ^= tracker_17 & 15;
  }
  else
  {
    acc = ((acc - tracker_17) + 11) & 127;
    aux += 3;
  }
  int stride_12 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_12 = ((stride_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_12) & 127;
  }

  int quotient_90 = (aux + st.buffer[1]) & 3;
  switch (quotient_90)
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

  return (acc + aux) & 255;
}

void fn_R001690_9013_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001690_9013_2 st_1 = {0};
  struct MatrixBlock_R001690_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int metric_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_45_1)
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

  switch (metric_45_2)
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

  int delta_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_63_1 > 26)
  {
    acc_1 = ((acc_1 + (delta_63_1 * 2)) + 5) & 127;
    aux_1 ^= delta_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_63_2 > 26)
  {
    acc_2 = ((acc_2 + (delta_63_2 * 2)) + 5) & 127;
    aux_2 ^= delta_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_32_1 = local_arr_1[aux_1 % 3];
  int mask_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_45_1 == metric_45_2);
  assert(delta_63_1 == delta_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_32_1 == mask_32_2);
}

int fn_R001690_9013_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001690_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int metric_45 = (aux + st.buffer[1]) & 3;
  switch (metric_45)
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

  int delta_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_63 > 26)
  {
    acc = ((acc + (delta_63 * 2)) + 5) & 127;
    aux ^= delta_63 & 15;
  }
  else
  {
    acc = ((acc - delta_63) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_32 = local_arr[aux % 3];
  acc = (acc + (mask_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001690_9013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001690_9013_0 st_1 = {0};
  struct Transaction_R001690_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_46_1 = local_arr_1[aux_1 % 3];
  int sample_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_46_2 * 2)) & 127;
  int window_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_48_1) & 63;
  aux_2 = (aux_2 + window_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_42_1 = 0;
  int weight_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_42_1 = ((weight_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_42_2 = ((weight_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_42_1) & 127;
    acc_2 = (acc_2 + weight_42_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_46_1 == sample_46_2);
  assert(window_48_1 == window_48_2);
  assert(weight_42_1 == weight_42_2);
}

int fn_R001690_9013_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001690_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int sample_46 = local_arr[aux % 3];
  acc = (acc + (sample_46 * 2)) & 127;
  int window_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_48) & 63;
  acc ^= aux;
  int weight_42 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_42 = ((weight_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_42) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001690_9013_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001690_9013_2 st_1 = {0};
  struct MatrixBlock_R001690_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int weight_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_58_1 > 48)
  {
    acc_1 = ((acc_1 + (weight_58_1 * 2)) + 5) & 127;
    aux_1 ^= weight_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_58_2 > 48)
  {
    acc_2 = ((acc_2 + (weight_58_2 * 2)) + 5) & 127;
    aux_2 ^= weight_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_58_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_47_1)
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

  switch (tally_47_2)
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
  int residue_84_1 = local_arr_1[aux_1 % 3];
  int residue_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_84_2 * 2)) & 127;
  int vector_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_80_1) & 63;
  aux_2 = (aux_2 + vector_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_58_1 == weight_58_2);
  assert(tally_47_1 == tally_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_84_1 == residue_84_2);
  assert(vector_80_1 == vector_80_2);
}

int fn_R001690_9013_8(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001690_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int weight_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_58 > 48)
  {
    acc = ((acc + (weight_58 * 2)) + 5) & 127;
    aux ^= weight_58 & 15;
  }
  else
  {
    acc = ((acc - weight_58) + 11) & 127;
    aux += 3;
  }
  int tally_47 = (aux + st.buffer[1]) & 3;
  switch (tally_47)
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
  int residue_84 = local_arr[aux % 3];
  acc = (acc + (residue_84 * 2)) & 127;
  int vector_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001690_9013_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001690_9013_3 st_1 = {0};
  struct CipherContext_R001690_9013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int weight_16_1 = 0;
  int weight_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_16_1 = ((weight_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_16_2 = ((weight_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_16_1) & 127;
    acc_2 = (acc_2 + weight_16_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_27_1 = local_arr_1[aux_1 % 3];
  int parity_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_27_2 * 2)) & 127;
  int offset_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_46_1 > 46)
  {
    acc_1 = ((acc_1 + (offset_46_1 * 2)) + 5) & 127;
    aux_1 ^= offset_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_46_2 > 46)
  {
    acc_2 = ((acc_2 + (offset_46_2 * 2)) + 5) & 127;
    aux_2 ^= offset_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_16_1 == weight_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_27_1 == parity_27_2);
  assert(offset_46_1 == offset_46_2);
}

int fn_R001690_9013_9(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001690_9013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int weight_16 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_16 = ((weight_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_16) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int parity_27 = local_arr[aux % 3];
  acc = (acc + (parity_27 * 2)) & 127;
  int offset_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_46 > 46)
  {
    acc = ((acc + (offset_46 * 2)) + 5) & 127;
    aux ^= offset_46 & 15;
  }
  else
  {
    acc = ((acc - offset_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001690_9013_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001690_9013_2 st_1 = {0};
  struct MatrixBlock_R001690_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_67_1) & 63;
  aux_2 = (aux_2 + offset_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_67_1 == offset_67_2);
}

int fn_R001690_9013_10(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001690_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_67) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001690_9013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001690_9013_3 st_1 = {0};
  struct CipherContext_R001690_9013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_39_1 = local_arr_1[aux_1 % 3];
  int threshold_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_39_2 * 2)) & 127;
  int tracker_63_1 = 0;
  int tracker_63_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_63_1 = ((tracker_63_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_63_2 = ((tracker_63_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_63_1) & 127;
    acc_2 = (acc_2 + tracker_63_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_39_1 == threshold_39_2);
  assert(tracker_63_1 == tracker_63_2);
}

int fn_R001690_9013_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001690_9013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int threshold_39 = local_arr[aux % 3];
  acc = (acc + (threshold_39 * 2)) & 127;
  int tracker_63 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_63 = ((tracker_63 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_63) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001690_9013_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001690_9013_0 st_1 = {0};
  struct Transaction_R001690_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_47_1 = local_arr_1[aux_1 % 3];
  int parity_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_47_2 * 2)) & 127;
  int tally_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_52_1 > 40)
  {
    acc_1 = ((acc_1 + (tally_52_1 * 2)) + 5) & 127;
    aux_1 ^= tally_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_52_2 > 40)
  {
    acc_2 = ((acc_2 + (tally_52_2 * 2)) + 5) & 127;
    aux_2 ^= tally_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_52_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_47_1 == parity_47_2);
  assert(tally_52_1 == tally_52_2);
}

int fn_R001690_9013_12(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001690_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int parity_47 = local_arr[aux % 3];
  acc = (acc + (parity_47 * 2)) & 127;
  int tally_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_52 > 40)
  {
    acc = ((acc + (tally_52 * 2)) + 5) & 127;
    aux ^= tally_52 & 15;
  }
  else
  {
    acc = ((acc - tally_52) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001690_9013_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001690_9013_0 st_1 = {0};
  struct Transaction_R001690_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_90_1 = local_arr_1[aux_1 % 3];
  int quantum_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_90_2 * 2)) & 127;
  int weight_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_84_1) & 63;
  aux_2 = (aux_2 + weight_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_90_1 == quantum_90_2);
  assert(weight_84_1 == weight_84_2);
}

int fn_R001690_9013_13(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001690_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int quantum_90 = local_arr[aux % 3];
  acc = (acc + (quantum_90 * 2)) & 127;
  int weight_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001690_9013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001690_9013_1 st_1 = {0};
  struct Vector3D_R001690_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int anchor_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_27_1) & 63;
  aux_2 = (aux_2 + anchor_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_24_1 > 42)
  {
    acc_1 = ((acc_1 + (tally_24_1 * 2)) + 5) & 127;
    aux_1 ^= tally_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_24_2 > 42)
  {
    acc_2 = ((acc_2 + (tally_24_2 * 2)) + 5) & 127;
    aux_2 ^= tally_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_91_1)
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

  switch (offset_91_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_27_1 == anchor_27_2);
  assert(tally_24_1 == tally_24_2);
  assert(offset_91_1 == offset_91_2);
}

int fn_R001690_9013_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001690_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int anchor_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_27) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_24 > 42)
  {
    acc = ((acc + (tally_24 * 2)) + 5) & 127;
    aux ^= tally_24 & 15;
  }
  else
  {
    acc = ((acc - tally_24) + 11) & 127;
    aux += 3;
  }
  int offset_91 = (aux + st.buffer[1]) & 3;
  switch (offset_91)
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

void fn_R001690_9013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001690_9013_0 st_1 = {0};
  struct Transaction_R001690_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_67_1) & 63;
  aux_2 = (aux_2 + quotient_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_54_1)
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

  switch (stride_54_2)
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

  int checksum_27_1 = 0;
  int checksum_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_27_1 = ((checksum_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_27_2 = ((checksum_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_27_1) & 127;
    acc_2 = (acc_2 + checksum_27_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_67_1 == quotient_67_2);
  assert(stride_54_1 == stride_54_2);
  assert(checksum_27_1 == checksum_27_2);
}

int fn_R001690_9013_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001690_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_67) & 63;
  acc ^= aux;
  int stride_54 = (aux + st.buffer[1]) & 3;
  switch (stride_54)
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

  int checksum_27 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_27 = ((checksum_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_27) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001690_9013_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001690_9013_0 st_1 = {0};
  struct Transaction_R001690_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_85_1)
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

  switch (vector_85_2)
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
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_85_1 == vector_85_2);
}

int fn_R001690_9013_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001690_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_85 = (aux + st.buffer[1]) & 3;
  switch (vector_85)
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

void fn_R001690_9013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001690_9013_0 st_1 = {0};
  struct Transaction_R001690_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int pivot_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_90_1 > 21)
  {
    acc_1 = ((acc_1 + (pivot_90_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_90_2 > 21)
  {
    acc_2 = ((acc_2 + (pivot_90_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_90_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_57_1)
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

  switch (offset_57_2)
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
  int tally_65_1 = local_arr_1[aux_1 % 3];
  int tally_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_65_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_90_1 == pivot_90_2);
  assert(offset_57_1 == offset_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_65_1 == tally_65_2);
}

int fn_R001690_9013_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001690_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int pivot_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_90 > 21)
  {
    acc = ((acc + (pivot_90 * 2)) + 5) & 127;
    aux ^= pivot_90 & 15;
  }
  else
  {
    acc = ((acc - pivot_90) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_57 = (aux + st.buffer[1]) & 3;
  switch (offset_57)
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
  int tally_65 = local_arr[aux % 3];
  acc = (acc + (tally_65 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001690_9013_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001690_9013_1 st_1 = {0};
  struct Vector3D_R001690_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int checksum_37_1 = 0;
  int checksum_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_37_1 = ((checksum_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_37_2 = ((checksum_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_37_1) & 127;
    acc_2 = (acc_2 + checksum_37_2) & 127;
  }

  int margin_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_97_1) & 63;
  aux_2 = (aux_2 + margin_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_37_1 == checksum_37_2);
  assert(margin_97_1 == margin_97_2);
}

int fn_R001690_9013_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001690_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int checksum_37 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_37 = ((checksum_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_37) & 127;
  }

  int margin_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001690_0_1;
  int sec_r001690_0_2;
  int sec_r001690_1_1;
  int sec_r001690_1_2;
  int sec_r001690_2_1;
  int sec_r001690_2_2;
  int sec_r001690_3_1;
  int sec_r001690_3_2;
  int sec_r001690_4_1;
  int sec_r001690_4_2;
  int sec_r001690_5_1;
  int sec_r001690_5_2;
  int sec_r001690_6_1;
  int sec_r001690_6_2;
  int sec_r001690_7_1;
  int sec_r001690_7_2;
  int sec_r001690_8_1;
  int sec_r001690_8_2;
  int sec_r001690_9_1;
  int sec_r001690_9_2;
  int sec_r001690_10_1;
  int sec_r001690_10_2;
  int sec_r001690_11_1;
  int sec_r001690_11_2;
  int sec_r001690_12_1;
  int sec_r001690_12_2;
  int sec_r001690_13_1;
  int sec_r001690_13_2;
  int sec_r001690_14_1;
  int sec_r001690_14_2;
  int sec_r001690_15_1;
  int sec_r001690_15_2;
  int pub_r001690_0_1;
  int pub_r001690_0_2;
  int pub_r001690_1_1;
  int pub_r001690_1_2;
  int pub_r001690_2_1;
  int pub_r001690_2_2;
  int pub_r001690_3_1;
  int pub_r001690_3_2;
  int pub_r001690_4_1;
  int pub_r001690_4_2;
  int pub_r001690_5_1;
  int pub_r001690_5_2;
  int pub_r001690_6_1;
  int pub_r001690_6_2;
  int pub_r001690_7_1;
  int pub_r001690_7_2;
  int pub_r001690_8_1;
  int pub_r001690_8_2;
  int pub_r001690_9_1;
  int pub_r001690_9_2;
  int pub_r001690_10_1;
  int pub_r001690_10_2;
  int pub_r001690_11_1;
  int pub_r001690_11_2;
  int pub_r001690_12_1;
  int pub_r001690_12_2;
  int pub_r001690_13_1;
  int pub_r001690_13_2;
  int pub_r001690_14_1;
  int pub_r001690_14_2;
  int pub_r001690_15_1;
  int pub_r001690_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001690_0_1 >= (-100)) && (pub_r001690_0_1 <= 100));
  __CPROVER_assume((pub_r001690_0_2 >= (-100)) && (pub_r001690_0_2 <= 100));
  __CPROVER_assume((pub_r001690_1_1 >= (-100)) && (pub_r001690_1_1 <= 100));
  __CPROVER_assume((pub_r001690_1_2 >= (-100)) && (pub_r001690_1_2 <= 100));
  __CPROVER_assume((pub_r001690_2_1 >= (-100)) && (pub_r001690_2_1 <= 100));
  __CPROVER_assume((pub_r001690_2_2 >= (-100)) && (pub_r001690_2_2 <= 100));
  __CPROVER_assume((pub_r001690_3_1 >= (-100)) && (pub_r001690_3_1 <= 100));
  __CPROVER_assume((pub_r001690_3_2 >= (-100)) && (pub_r001690_3_2 <= 100));
  __CPROVER_assume((pub_r001690_4_1 >= (-100)) && (pub_r001690_4_1 <= 100));
  __CPROVER_assume((pub_r001690_4_2 >= (-100)) && (pub_r001690_4_2 <= 100));
  __CPROVER_assume((pub_r001690_5_1 >= (-100)) && (pub_r001690_5_1 <= 100));
  __CPROVER_assume((pub_r001690_5_2 >= (-100)) && (pub_r001690_5_2 <= 100));
  __CPROVER_assume((pub_r001690_6_1 >= (-100)) && (pub_r001690_6_1 <= 100));
  __CPROVER_assume((pub_r001690_6_2 >= (-100)) && (pub_r001690_6_2 <= 100));
  __CPROVER_assume((pub_r001690_7_1 >= (-100)) && (pub_r001690_7_1 <= 100));
  __CPROVER_assume((pub_r001690_7_2 >= (-100)) && (pub_r001690_7_2 <= 100));
  __CPROVER_assume((pub_r001690_8_1 >= (-100)) && (pub_r001690_8_1 <= 100));
  __CPROVER_assume((pub_r001690_8_2 >= (-100)) && (pub_r001690_8_2 <= 100));
  __CPROVER_assume((pub_r001690_9_1 >= (-100)) && (pub_r001690_9_1 <= 100));
  __CPROVER_assume((pub_r001690_9_2 >= (-100)) && (pub_r001690_9_2 <= 100));
  __CPROVER_assume((pub_r001690_10_1 >= (-100)) && (pub_r001690_10_1 <= 100));
  __CPROVER_assume((pub_r001690_10_2 >= (-100)) && (pub_r001690_10_2 <= 100));
  __CPROVER_assume((pub_r001690_11_1 >= (-100)) && (pub_r001690_11_1 <= 100));
  __CPROVER_assume((pub_r001690_11_2 >= (-100)) && (pub_r001690_11_2 <= 100));
  __CPROVER_assume((pub_r001690_12_1 >= (-100)) && (pub_r001690_12_1 <= 100));
  __CPROVER_assume((pub_r001690_12_2 >= (-100)) && (pub_r001690_12_2 <= 100));
  __CPROVER_assume((pub_r001690_13_1 >= (-100)) && (pub_r001690_13_1 <= 100));
  __CPROVER_assume((pub_r001690_13_2 >= (-100)) && (pub_r001690_13_2 <= 100));
  __CPROVER_assume((pub_r001690_14_1 >= (-100)) && (pub_r001690_14_1 <= 100));
  __CPROVER_assume((pub_r001690_14_2 >= (-100)) && (pub_r001690_14_2 <= 100));
  __CPROVER_assume((pub_r001690_15_1 >= (-100)) && (pub_r001690_15_1 <= 100));
  __CPROVER_assume((pub_r001690_15_2 >= (-100)) && (pub_r001690_15_2 <= 100));
  __CPROVER_assume((sec_r001690_0_1 >= 0) && (sec_r001690_0_1 <= 255));
  __CPROVER_assume((sec_r001690_0_2 >= 0) && (sec_r001690_0_2 <= 255));
  __CPROVER_assume((sec_r001690_1_1 >= 0) && (sec_r001690_1_1 <= 255));
  __CPROVER_assume((sec_r001690_1_2 >= 0) && (sec_r001690_1_2 <= 255));
  __CPROVER_assume((sec_r001690_2_1 >= 0) && (sec_r001690_2_1 <= 255));
  __CPROVER_assume((sec_r001690_2_2 >= 0) && (sec_r001690_2_2 <= 255));
  __CPROVER_assume((sec_r001690_3_1 >= 0) && (sec_r001690_3_1 <= 255));
  __CPROVER_assume((sec_r001690_3_2 >= 0) && (sec_r001690_3_2 <= 255));
  __CPROVER_assume((sec_r001690_4_1 >= 0) && (sec_r001690_4_1 <= 255));
  __CPROVER_assume((sec_r001690_4_2 >= 0) && (sec_r001690_4_2 <= 255));
  __CPROVER_assume((sec_r001690_5_1 >= 0) && (sec_r001690_5_1 <= 255));
  __CPROVER_assume((sec_r001690_5_2 >= 0) && (sec_r001690_5_2 <= 255));
  __CPROVER_assume((sec_r001690_6_1 >= 0) && (sec_r001690_6_1 <= 255));
  __CPROVER_assume((sec_r001690_6_2 >= 0) && (sec_r001690_6_2 <= 255));
  __CPROVER_assume((sec_r001690_7_1 >= 0) && (sec_r001690_7_1 <= 255));
  __CPROVER_assume((sec_r001690_7_2 >= 0) && (sec_r001690_7_2 <= 255));
  __CPROVER_assume((sec_r001690_8_1 >= 0) && (sec_r001690_8_1 <= 255));
  __CPROVER_assume((sec_r001690_8_2 >= 0) && (sec_r001690_8_2 <= 255));
  __CPROVER_assume((sec_r001690_9_1 >= 0) && (sec_r001690_9_1 <= 255));
  __CPROVER_assume((sec_r001690_9_2 >= 0) && (sec_r001690_9_2 <= 255));
  __CPROVER_assume((sec_r001690_10_1 >= 0) && (sec_r001690_10_1 <= 255));
  __CPROVER_assume((sec_r001690_10_2 >= 0) && (sec_r001690_10_2 <= 255));
  __CPROVER_assume((sec_r001690_11_1 >= 0) && (sec_r001690_11_1 <= 255));
  __CPROVER_assume((sec_r001690_11_2 >= 0) && (sec_r001690_11_2 <= 255));
  __CPROVER_assume((sec_r001690_12_1 >= 0) && (sec_r001690_12_1 <= 255));
  __CPROVER_assume((sec_r001690_12_2 >= 0) && (sec_r001690_12_2 <= 255));
  __CPROVER_assume((sec_r001690_13_1 >= 0) && (sec_r001690_13_1 <= 255));
  __CPROVER_assume((sec_r001690_13_2 >= 0) && (sec_r001690_13_2 <= 255));
  __CPROVER_assume((sec_r001690_14_1 >= 0) && (sec_r001690_14_1 <= 255));
  __CPROVER_assume((sec_r001690_14_2 >= 0) && (sec_r001690_14_2 <= 255));
  __CPROVER_assume((sec_r001690_15_1 >= 0) && (sec_r001690_15_1 <= 255));
  __CPROVER_assume((sec_r001690_15_2 >= 0) && (sec_r001690_15_2 <= 255));
  struct Transaction_R001690_9013_0 st_var_0_1 = {0};
  struct Transaction_R001690_9013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001690_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001690_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001690_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001690_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001690_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001690_0_2 + 7) & 15;
  struct Vector3D_R001690_9013_1 st_var_1_1 = {0};
  struct Vector3D_R001690_9013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001690_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001690_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001690_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001690_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001690_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001690_0_2 + 9) & 15;
  struct MatrixBlock_R001690_9013_2 st_var_2_1 = {0};
  struct MatrixBlock_R001690_9013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001690_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001690_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001690_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001690_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001690_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001690_0_2 + 11) & 15;
  struct CipherContext_R001690_9013_3 st_var_3_1 = {0};
  struct CipherContext_R001690_9013_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001690_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001690_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001690_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001690_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001690_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001690_0_2 + 13) & 15;
  union ColorPixel_R001690_9013_0 u_var_1;
  union ColorPixel_R001690_9013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001690_9013_0(sec_r001690_0_1, pub_r001690_1_1);
  int helper_flow_0_2 = fn_R001690_9013_0(sec_r001690_0_2, pub_r001690_1_2);
  fn_R001690_9013_0_2(sec_r001690_0_1, pub_r001690_1_1, sec_r001690_0_2, pub_r001690_1_2);
  int helper_flow_1_1 = fn_R001690_9013_1(sec_r001690_1_1, sec_r001690_2_1, pub_r001690_3_1, pub_r001690_4_1);
  int helper_flow_1_2 = fn_R001690_9013_1(sec_r001690_1_2, sec_r001690_2_2, pub_r001690_3_2, pub_r001690_4_2);
  fn_R001690_9013_1_2(sec_r001690_1_1, sec_r001690_2_1, pub_r001690_3_1, pub_r001690_4_1, sec_r001690_1_2, sec_r001690_2_2, pub_r001690_3_2, pub_r001690_4_2);
  int helper_flow_2_1 = fn_R001690_9013_2(sec_r001690_2_1, sec_r001690_3_1);
  int helper_flow_2_2 = fn_R001690_9013_2(sec_r001690_2_2, sec_r001690_3_2);
  fn_R001690_9013_2_2(sec_r001690_2_1, sec_r001690_3_1, sec_r001690_2_2, sec_r001690_3_2);
  int helper_flow_3_1 = fn_R001690_9013_3(sec_r001690_3_1, sec_r001690_4_1);
  int helper_flow_3_2 = fn_R001690_9013_3(sec_r001690_3_2, sec_r001690_4_2);
  fn_R001690_9013_3_2(sec_r001690_3_1, sec_r001690_4_1, sec_r001690_3_2, sec_r001690_4_2);
  int helper_flow_4_1 = fn_R001690_9013_4(sec_r001690_4_1, sec_r001690_5_1, pub_r001690_6_1);
  int helper_flow_4_2 = fn_R001690_9013_4(sec_r001690_4_2, sec_r001690_5_2, pub_r001690_6_2);
  fn_R001690_9013_4_2(sec_r001690_4_1, sec_r001690_5_1, pub_r001690_6_1, sec_r001690_4_2, sec_r001690_5_2, pub_r001690_6_2);
  int helper_flow_5_1 = fn_R001690_9013_5(sec_r001690_5_1, pub_r001690_6_1);
  int helper_flow_5_2 = fn_R001690_9013_5(sec_r001690_5_2, pub_r001690_6_2);
  fn_R001690_9013_5_2(sec_r001690_5_1, pub_r001690_6_1, sec_r001690_5_2, pub_r001690_6_2);
  int helper_flow_6_1 = fn_R001690_9013_6(sec_r001690_6_1, pub_r001690_7_1, pub_r001690_8_1, pub_r001690_9_1);
  int helper_flow_6_2 = fn_R001690_9013_6(sec_r001690_6_2, pub_r001690_7_2, pub_r001690_8_2, pub_r001690_9_2);
  fn_R001690_9013_6_2(sec_r001690_6_1, pub_r001690_7_1, pub_r001690_8_1, pub_r001690_9_1, sec_r001690_6_2, pub_r001690_7_2, pub_r001690_8_2, pub_r001690_9_2);
  int helper_flow_7_1 = fn_R001690_9013_7(sec_r001690_7_1, sec_r001690_8_1, pub_r001690_9_1, pub_r001690_10_1);
  int helper_flow_7_2 = fn_R001690_9013_7(sec_r001690_7_2, sec_r001690_8_2, pub_r001690_9_2, pub_r001690_10_2);
  fn_R001690_9013_7_2(sec_r001690_7_1, sec_r001690_8_1, pub_r001690_9_1, pub_r001690_10_1, sec_r001690_7_2, sec_r001690_8_2, pub_r001690_9_2, pub_r001690_10_2);
  int helper_flow_8_1 = fn_R001690_9013_8(sec_r001690_8_1, sec_r001690_9_1);
  int helper_flow_8_2 = fn_R001690_9013_8(sec_r001690_8_2, sec_r001690_9_2);
  fn_R001690_9013_8_2(sec_r001690_8_1, sec_r001690_9_1, sec_r001690_8_2, sec_r001690_9_2);
  int helper_flow_9_1 = fn_R001690_9013_9(sec_r001690_9_1, sec_r001690_10_1, pub_r001690_11_1);
  int helper_flow_9_2 = fn_R001690_9013_9(sec_r001690_9_2, sec_r001690_10_2, pub_r001690_11_2);
  fn_R001690_9013_9_2(sec_r001690_9_1, sec_r001690_10_1, pub_r001690_11_1, sec_r001690_9_2, sec_r001690_10_2, pub_r001690_11_2);
  int helper_flow_10_1 = fn_R001690_9013_10(sec_r001690_10_1, pub_r001690_11_1, pub_r001690_12_1);
  int helper_flow_10_2 = fn_R001690_9013_10(sec_r001690_10_2, pub_r001690_11_2, pub_r001690_12_2);
  fn_R001690_9013_10_2(sec_r001690_10_1, pub_r001690_11_1, pub_r001690_12_1, sec_r001690_10_2, pub_r001690_11_2, pub_r001690_12_2);
  int helper_flow_11_1 = fn_R001690_9013_11(sec_r001690_11_1, sec_r001690_12_1, pub_r001690_13_1, pub_r001690_14_1);
  int helper_flow_11_2 = fn_R001690_9013_11(sec_r001690_11_2, sec_r001690_12_2, pub_r001690_13_2, pub_r001690_14_2);
  fn_R001690_9013_11_2(sec_r001690_11_1, sec_r001690_12_1, pub_r001690_13_1, pub_r001690_14_1, sec_r001690_11_2, sec_r001690_12_2, pub_r001690_13_2, pub_r001690_14_2);
  int helper_flow_12_1 = fn_R001690_9013_12(sec_r001690_12_1, sec_r001690_13_1);
  int helper_flow_12_2 = fn_R001690_9013_12(sec_r001690_12_2, sec_r001690_13_2);
  fn_R001690_9013_12_2(sec_r001690_12_1, sec_r001690_13_1, sec_r001690_12_2, sec_r001690_13_2);
  int helper_flow_13_1 = fn_R001690_9013_13(sec_r001690_13_1, sec_r001690_14_1, pub_r001690_15_1);
  int helper_flow_13_2 = fn_R001690_9013_13(sec_r001690_13_2, sec_r001690_14_2, pub_r001690_15_2);
  fn_R001690_9013_13_2(sec_r001690_13_1, sec_r001690_14_1, pub_r001690_15_1, sec_r001690_13_2, sec_r001690_14_2, pub_r001690_15_2);
  int stage_v_0_1 = (((sec_r001690_9_1 ^ 0x2A) * 2) + pub_r001690_14_1) & 127;
  int stage_v_0_2 = (((sec_r001690_9_2 ^ 0x2A) * 2) + pub_r001690_14_2) & 127;
  if (stage_v_0_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001690_1_1) & 127;
  int stage_v_1_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001690_1_2) & 127;
  if (stage_v_1_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (((sec_r001690_13_1 ^ 0x2A) * 2) + pub_r001690_14_1) & 127;
  int stage_v_2_2 = (((sec_r001690_13_2 ^ 0x2A) * 2) + pub_r001690_14_2) & 127;
  if (stage_v_2_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((sec_r001690_0_1 ^ 0x2A) * 2) + pub_r001690_6_1) & 127;
  int stage_v_3_2 = (((sec_r001690_0_2 ^ 0x2A) * 2) + pub_r001690_6_2) & 127;
  if (stage_v_3_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001690_13_1) & 127;
  int stage_v_4_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001690_13_2) & 127;
  if (stage_v_4_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = ((pub_r001690_14_1 * 2) + 6) & 63;
  int stage_v_5_2 = ((pub_r001690_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001690_5_1 * 2) + 18) & 63;
  int stage_v_6_2 = ((pub_r001690_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((sec_r001690_15_1 ^ 0x2A) * 2) + pub_r001690_3_1) & 127;
  int stage_v_7_2 = (((sec_r001690_15_2 ^ 0x2A) * 2) + pub_r001690_3_2) & 127;
  if (stage_v_7_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001690_6_1) & 127;
  int stage_v_8_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001690_6_2) & 127;
  if (stage_v_8_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001690_11_1) & 127;
  int stage_v_9_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001690_11_2) & 127;
  if (stage_v_9_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (((sec_r001690_15_1 ^ 0x2A) * 2) + pub_r001690_12_1) & 127;
  int stage_v_10_2 = (((sec_r001690_15_2 ^ 0x2A) * 2) + pub_r001690_12_2) & 127;
  if (stage_v_10_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((sec_r001690_6_1 ^ 0x2A) * 2) + pub_r001690_7_1) & 127;
  int stage_v_11_2 = (((sec_r001690_6_2 ^ 0x2A) * 2) + pub_r001690_7_2) & 127;
  if (stage_v_11_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((pub_r001690_12_1 * 2) + 32) & 63;
  int stage_v_12_2 = ((pub_r001690_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((sec_r001690_9_1 ^ 0x2A) * 2) + pub_r001690_9_1) & 127;
  int stage_v_13_2 = (((sec_r001690_9_2 ^ 0x2A) * 2) + pub_r001690_9_2) & 127;
  if (stage_v_13_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((sec_r001690_6_1 ^ 0x2A) * 2) + pub_r001690_9_1) & 127;
  int stage_v_14_2 = (((sec_r001690_6_2 ^ 0x2A) * 2) + pub_r001690_9_2) & 127;
  if (stage_v_14_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((pub_r001690_15_1 * 2) + 17) & 63;
  int stage_v_15_2 = ((pub_r001690_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001690_15_1) & 127;
  int stage_v_16_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001690_15_2) & 127;
  if (stage_v_16_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = ((pub_r001690_8_1 * 2) + 16) & 63;
  int stage_v_17_2 = ((pub_r001690_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001690_8_1 * 2) + 31) & 63;
  int stage_v_18_2 = ((pub_r001690_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001690_1_1) & 127;
  int stage_v_19_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001690_1_2) & 127;
  if (stage_v_19_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((helper_flow_13_1 ^ 0x2A) * 2) + pub_r001690_10_1) & 127;
  int stage_v_20_2 = (((helper_flow_13_2 ^ 0x2A) * 2) + pub_r001690_10_2) & 127;
  if (stage_v_20_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((pub_r001690_14_1 * 2) + 26) & 63;
  int stage_v_21_2 = ((pub_r001690_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001690_5_1 * 2) + 22) & 63;
  int stage_v_22_2 = ((pub_r001690_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001690_1_1) & 127;
  int stage_v_23_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001690_1_2) & 127;
  if (stage_v_23_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001690_6_1) & 127;
  int stage_v_24_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001690_6_2) & 127;
  if (stage_v_24_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001690_8_1) & 127;
  int stage_v_25_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001690_8_2) & 127;
  if (stage_v_25_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((pub_r001690_0_1 * 2) + 11) & 63;
  int stage_v_26_2 = ((pub_r001690_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001690_15_1) & 127;
  int stage_v_27_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001690_15_2) & 127;
  if (stage_v_27_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001690_7_1) & 127;
  int stage_v_28_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001690_7_2) & 127;
  if (stage_v_28_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((pub_r001690_4_1 * 2) + 21) & 63;
  int stage_v_29_2 = ((pub_r001690_4_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001690_9_1) & 127;
  int stage_v_30_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001690_9_2) & 127;
  if (stage_v_30_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001690_15_1) & 127;
  int stage_v_31_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001690_15_2) & 127;
  if (stage_v_31_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001690_11_1) & 127;
  int stage_v_32_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001690_11_2) & 127;
  if (stage_v_32_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((pub_r001690_9_1 * 2) + 6) & 63;
  int stage_v_33_2 = ((pub_r001690_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001690_3_1) & 127;
  int stage_v_34_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001690_3_2) & 127;
  if (stage_v_34_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001690_1_1) & 127;
  int stage_v_35_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001690_1_2) & 127;
  if (stage_v_35_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((helper_flow_13_1 ^ 0x2A) * 2) + pub_r001690_8_1) & 127;
  int stage_v_36_2 = (((helper_flow_13_2 ^ 0x2A) * 2) + pub_r001690_8_2) & 127;
  if (stage_v_36_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001690_10_1) & 127;
  int stage_v_37_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001690_10_2) & 127;
  if (stage_v_37_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((pub_r001690_10_1 * 2) + 42) & 63;
  int stage_v_38_2 = ((pub_r001690_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = (((sec_r001690_3_1 ^ 0x2A) * 2) + pub_r001690_4_1) & 127;
  int stage_v_39_2 = (((sec_r001690_3_2 ^ 0x2A) * 2) + pub_r001690_4_2) & 127;
  if (stage_v_39_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (((sec_r001690_6_1 ^ 0x2A) * 2) + pub_r001690_12_1) & 127;
  int stage_v_40_2 = (((sec_r001690_6_2 ^ 0x2A) * 2) + pub_r001690_12_2) & 127;
  if (stage_v_40_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001690_12_1) & 127;
  int stage_v_41_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001690_12_2) & 127;
  if (stage_v_41_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001690_7_1) & 127;
  int stage_v_42_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001690_7_2) & 127;
  if (stage_v_42_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((sec_r001690_8_1 ^ 0x2A) * 2) + pub_r001690_3_1) & 127;
  int stage_v_43_2 = (((sec_r001690_8_2 ^ 0x2A) * 2) + pub_r001690_3_2) & 127;
  if (stage_v_43_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((pub_r001690_3_1 * 2) + 19) & 63;
  int stage_v_44_2 = ((pub_r001690_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001690_12_1 * 2) + 33) & 63;
  int stage_v_45_2 = ((pub_r001690_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001690_12_1 * 2) + 21) & 63;
  int stage_v_46_2 = ((pub_r001690_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001690_13_1) & 127;
  int stage_v_47_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001690_13_2) & 127;
  if (stage_v_47_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((pub_r001690_15_1 * 2) + 12) & 63;
  int stage_v_48_2 = ((pub_r001690_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001690_10_1) & 127;
  int stage_v_49_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001690_10_2) & 127;
  if (stage_v_49_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001690_2_1) & 127;
  int stage_v_50_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001690_2_2) & 127;
  if (stage_v_50_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001690_12_1) & 127;
  int stage_v_51_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001690_12_2) & 127;
  if (stage_v_51_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (((sec_r001690_2_1 ^ 0x2A) * 2) + pub_r001690_8_1) & 127;
  int stage_v_52_2 = (((sec_r001690_2_2 ^ 0x2A) * 2) + pub_r001690_8_2) & 127;
  if (stage_v_52_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((pub_r001690_8_1 * 2) + 43) & 63;
  int stage_v_53_2 = ((pub_r001690_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((sec_r001690_13_1 ^ 0x2A) * 2) + pub_r001690_15_1) & 127;
  int stage_v_54_2 = (((sec_r001690_13_2 ^ 0x2A) * 2) + pub_r001690_15_2) & 127;
  if (stage_v_54_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001690_13_1) & 127;
  int stage_v_55_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001690_13_2) & 127;
  if (stage_v_55_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((pub_r001690_3_1 * 2) + 28) & 63;
  int stage_v_56_2 = ((pub_r001690_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (((sec_r001690_0_1 ^ 0x2A) * 2) + pub_r001690_2_1) & 127;
  int stage_v_57_2 = (((sec_r001690_0_2 ^ 0x2A) * 2) + pub_r001690_2_2) & 127;
  if (stage_v_57_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001690_10_1) & 127;
  int stage_v_58_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001690_10_2) & 127;
  if (stage_v_58_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001690_8_1) & 127;
  int stage_v_59_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001690_8_2) & 127;
  if (stage_v_59_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001690_0_1) & 127;
  int stage_v_60_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001690_0_2) & 127;
  if (stage_v_60_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((pub_r001690_3_1 * 2) + 21) & 63;
  int stage_v_61_2 = ((pub_r001690_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001690_14_1 * 2) + 31) & 63;
  int stage_v_62_2 = ((pub_r001690_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((sec_r001690_11_1 ^ 0x2A) * 2) + pub_r001690_12_1) & 127;
  int stage_v_63_2 = (((sec_r001690_11_2 ^ 0x2A) * 2) + pub_r001690_12_2) & 127;
  if (stage_v_63_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001690_7_1) & 127;
  int stage_v_64_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001690_7_2) & 127;
  if (stage_v_64_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((helper_flow_13_1 ^ 0x2A) * 2) + pub_r001690_8_1) & 127;
  int stage_v_65_2 = (((helper_flow_13_2 ^ 0x2A) * 2) + pub_r001690_8_2) & 127;
  if (stage_v_65_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001690_11_1) & 127;
  int stage_v_66_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001690_11_2) & 127;
  if (stage_v_66_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001690_4_1) & 127;
  int stage_v_67_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001690_4_2) & 127;
  if (stage_v_67_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001690_15_1) & 127;
  int stage_v_68_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001690_15_2) & 127;
  if (stage_v_68_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((pub_r001690_10_1 * 2) + 14) & 63;
  int stage_v_69_2 = ((pub_r001690_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001690_12_1 * 2) + 28) & 63;
  int stage_v_70_2 = ((pub_r001690_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001690_10_1 * 2) + 37) & 63;
  int stage_v_71_2 = ((pub_r001690_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001690_4_1) & 127;
  int stage_v_72_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001690_4_2) & 127;
  if (stage_v_72_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((pub_r001690_4_1 * 2) + 28) & 63;
  int stage_v_73_2 = ((pub_r001690_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001690_2_1) & 127;
  int stage_v_74_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001690_2_2) & 127;
  if (stage_v_74_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((helper_flow_13_1 ^ 0x2A) * 2) + pub_r001690_14_1) & 127;
  int stage_v_75_2 = (((helper_flow_13_2 ^ 0x2A) * 2) + pub_r001690_14_2) & 127;
  if (stage_v_75_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001690_8_1) & 127;
  int stage_v_76_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001690_8_2) & 127;
  if (stage_v_76_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((pub_r001690_4_1 * 2) + 33) & 63;
  int stage_v_77_2 = ((pub_r001690_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001690_6_1) & 127;
  int stage_v_78_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001690_6_2) & 127;
  if (stage_v_78_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001690_0_1) & 127;
  int stage_v_79_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001690_0_2) & 127;
  if (stage_v_79_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001690_1_1) & 127;
  int stage_v_80_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001690_1_2) & 127;
  if (stage_v_80_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001690_6_1) & 127;
  int stage_v_81_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001690_6_2) & 127;
  if (stage_v_81_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001690_3_1) & 127;
  int stage_v_82_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001690_3_2) & 127;
  if (stage_v_82_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001690_13_1) & 127;
  int stage_v_83_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001690_13_2) & 127;
  if (stage_v_83_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001690_0_1) & 127;
  int stage_v_84_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001690_0_2) & 127;
  if (stage_v_84_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((pub_r001690_3_1 * 2) + 18) & 63;
  int stage_v_85_2 = ((pub_r001690_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001690_9_1 * 2) + 12) & 63;
  int stage_v_86_2 = ((pub_r001690_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001690_13_1) & 127;
  int stage_v_87_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001690_13_2) & 127;
  if (stage_v_87_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001690_9_1) & 127;
  int stage_v_88_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001690_9_2) & 127;
  if (stage_v_88_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001690_14_1) & 127;
  int stage_v_89_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001690_14_2) & 127;
  if (stage_v_89_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001690_5_1) & 127;
  int stage_v_90_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001690_5_2) & 127;
  if (stage_v_90_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((pub_r001690_10_1 * 2) + 7) & 63;
  int stage_v_91_2 = ((pub_r001690_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001690_7_1 * 2) + 34) & 63;
  int stage_v_92_2 = ((pub_r001690_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001690_15_1 * 2) + 38) & 63;
  int stage_v_93_2 = ((pub_r001690_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001690_8_1) & 127;
  int stage_v_94_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001690_8_2) & 127;
  if (stage_v_94_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (((sec_r001690_9_1 ^ 0x2A) * 2) + pub_r001690_4_1) & 127;
  int stage_v_95_2 = (((sec_r001690_9_2 ^ 0x2A) * 2) + pub_r001690_4_2) & 127;
  if (stage_v_95_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001690_6_1) & 127;
  int stage_v_96_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001690_6_2) & 127;
  if (stage_v_96_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001690_0_1) & 127;
  int stage_v_97_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001690_0_2) & 127;
  if (stage_v_97_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((pub_r001690_11_1 * 2) + 14) & 63;
  int stage_v_98_2 = ((pub_r001690_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001690_4_1 * 2) + 20) & 63;
  int stage_v_99_2 = ((pub_r001690_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001690_10_1) & 127;
  int stage_v_100_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001690_10_2) & 127;
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
  int stage_v_101_1 = ((pub_r001690_0_1 * 2) + 28) & 63;
  int stage_v_101_2 = ((pub_r001690_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((stage_v_96_1 ^ 0x2A) * 2) + pub_r001690_3_1) & 127;
  int stage_v_102_2 = (((stage_v_96_2 ^ 0x2A) * 2) + pub_r001690_3_2) & 127;
  if (stage_v_102_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((pub_r001690_11_1 * 2) + 18) & 63;
  int stage_v_103_2 = ((pub_r001690_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001690_5_1 * 2) + 41) & 63;
  int stage_v_104_2 = ((pub_r001690_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((sec_r001690_12_1 ^ 0x2A) * 2) + pub_r001690_2_1) & 127;
  int stage_v_105_2 = (((sec_r001690_12_2 ^ 0x2A) * 2) + pub_r001690_2_2) & 127;
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
  int stage_v_106_1 = ((pub_r001690_10_1 * 2) + 45) & 63;
  int stage_v_106_2 = ((pub_r001690_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001690_1_1) & 127;
  int stage_v_107_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001690_1_2) & 127;
  if (stage_v_107_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((stage_v_95_1 ^ 0x2A) * 2) + pub_r001690_6_1) & 127;
  int stage_v_108_2 = (((stage_v_95_2 ^ 0x2A) * 2) + pub_r001690_6_2) & 127;
  if (stage_v_108_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((pub_r001690_6_1 * 2) + 15) & 63;
  int stage_v_109_2 = ((pub_r001690_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001690_2_1) & 127;
  int stage_v_110_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001690_2_2) & 127;
  if (stage_v_110_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((pub_r001690_7_1 * 2) + 23) & 63;
  int stage_v_111_2 = ((pub_r001690_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001690_10_1 * 2) + 45) & 63;
  int stage_v_112_2 = ((pub_r001690_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001690_9_1 * 2) + 24) & 63;
  int stage_v_113_2 = ((pub_r001690_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001690_11_1 * 2) + 14) & 63;
  int stage_v_114_2 = ((pub_r001690_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001690_11_1 * 2) + 19) & 63;
  int stage_v_115_2 = ((pub_r001690_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001690_9_1) & 127;
  int stage_v_116_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001690_9_2) & 127;
  if (stage_v_116_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001690_4_1) & 127;
  int stage_v_117_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001690_4_2) & 127;
  if (stage_v_117_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((sec_r001690_5_1 ^ 0x2A) * 2) + pub_r001690_2_1) & 127;
  int stage_v_118_2 = (((sec_r001690_5_2 ^ 0x2A) * 2) + pub_r001690_2_2) & 127;
  if (stage_v_118_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001690_7_1) & 127;
  int stage_v_119_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001690_7_2) & 127;
  if (stage_v_119_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((pub_r001690_4_1 * 2) + 44) & 63;
  int stage_v_120_2 = ((pub_r001690_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001690_11_1) & 127;
  int stage_v_121_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001690_11_2) & 127;
  if (stage_v_121_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001690_15_1) & 127;
  int stage_v_122_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001690_15_2) & 127;
  if (stage_v_122_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001690_8_1) & 127;
  int stage_v_123_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001690_8_2) & 127;
  if (stage_v_123_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001690_6_1) & 127;
  int stage_v_124_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001690_6_2) & 127;
  if (stage_v_124_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((pub_r001690_11_1 * 2) + 30) & 63;
  int stage_v_125_2 = ((pub_r001690_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001690_1_1 * 2) + 17) & 63;
  int stage_v_126_2 = ((pub_r001690_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001690_1_1) & 127;
  int stage_v_127_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001690_1_2) & 127;
  if (stage_v_127_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001690_15_1) & 127;
  int stage_v_128_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001690_15_2) & 127;
  if (stage_v_128_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (((stage_v_95_1 ^ 0x2A) * 2) + pub_r001690_8_1) & 127;
  int stage_v_129_2 = (((stage_v_95_2 ^ 0x2A) * 2) + pub_r001690_8_2) & 127;
  if (stage_v_129_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001690_2_1) & 127;
  int stage_v_130_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001690_2_2) & 127;
  if (stage_v_130_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((sec_r001690_3_1 ^ 0x2A) * 2) + pub_r001690_1_1) & 127;
  int stage_v_131_2 = (((sec_r001690_3_2 ^ 0x2A) * 2) + pub_r001690_1_2) & 127;
  if (stage_v_131_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001690_12_1) & 127;
  int stage_v_132_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001690_12_2) & 127;
  if (stage_v_132_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001690_8_1) & 127;
  int stage_v_133_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001690_8_2) & 127;
  if (stage_v_133_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((stage_v_72_1 ^ 0x2A) * 2) + pub_r001690_11_1) & 127;
  int stage_v_134_2 = (((stage_v_72_2 ^ 0x2A) * 2) + pub_r001690_11_2) & 127;
  if (stage_v_134_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001690_13_1) & 127;
  int stage_v_135_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001690_13_2) & 127;
  if (stage_v_135_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001690_12_1) & 127;
  int stage_v_136_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001690_12_2) & 127;
  if (stage_v_136_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001690_7_1) & 127;
  int stage_v_137_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001690_7_2) & 127;
  if (stage_v_137_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001690_4_1) & 127;
  int stage_v_138_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001690_4_2) & 127;
  if (stage_v_138_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((pub_r001690_13_1 * 2) + 20) & 63;
  int stage_v_139_2 = ((pub_r001690_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001690_11_1) & 127;
  int stage_v_140_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001690_11_2) & 127;
  if (stage_v_140_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001690_4_1) & 127;
  int stage_v_141_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001690_4_2) & 127;
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
  int stage_v_142_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001690_13_1) & 127;
  int stage_v_142_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001690_13_2) & 127;
  if (stage_v_142_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((sec_r001690_14_1 ^ 0x2A) * 2) + pub_r001690_14_1) & 127;
  int stage_v_143_2 = (((sec_r001690_14_2 ^ 0x2A) * 2) + pub_r001690_14_2) & 127;
  if (stage_v_143_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001690_1_1) & 127;
  int stage_v_144_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001690_1_2) & 127;
  if (stage_v_144_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((sec_r001690_4_1 ^ 0x2A) * 2) + pub_r001690_13_1) & 127;
  int stage_v_145_2 = (((sec_r001690_4_2 ^ 0x2A) * 2) + pub_r001690_13_2) & 127;
  if (stage_v_145_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (((sec_r001690_2_1 ^ 0x2A) * 2) + pub_r001690_4_1) & 127;
  int stage_v_146_2 = (((sec_r001690_2_2 ^ 0x2A) * 2) + pub_r001690_4_2) & 127;
  if (stage_v_146_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001690_14_1) & 127;
  int stage_v_147_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001690_14_2) & 127;
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
  int stage_v_148_1 = (((sec_r001690_9_1 ^ 0x2A) * 2) + pub_r001690_11_1) & 127;
  int stage_v_148_2 = (((sec_r001690_9_2 ^ 0x2A) * 2) + pub_r001690_11_2) & 127;
  if (stage_v_148_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((stage_v_116_1 ^ 0x2A) * 2) + pub_r001690_8_1) & 127;
  int stage_v_149_2 = (((stage_v_116_2 ^ 0x2A) * 2) + pub_r001690_8_2) & 127;
  if (stage_v_149_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001690_10_1) & 127;
  int stage_v_150_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001690_10_2) & 127;
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
  int stage_v_151_1 = (((stage_v_76_1 ^ 0x2A) * 2) + pub_r001690_6_1) & 127;
  int stage_v_151_2 = (((stage_v_76_2 ^ 0x2A) * 2) + pub_r001690_6_2) & 127;
  if (stage_v_151_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = (((stage_v_132_1 ^ 0x2A) * 2) + pub_r001690_3_1) & 127;
  int stage_v_152_2 = (((stage_v_132_2 ^ 0x2A) * 2) + pub_r001690_3_2) & 127;
  if (stage_v_152_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((pub_r001690_2_1 * 2) + 5) & 63;
  int stage_v_153_2 = ((pub_r001690_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001690_2_1) & 127;
  int stage_v_154_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001690_2_2) & 127;
  if (stage_v_154_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001690_9_1) & 127;
  int stage_v_155_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001690_9_2) & 127;
  if (stage_v_155_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((pub_r001690_7_1 * 2) + 37) & 63;
  int stage_v_156_2 = ((pub_r001690_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001690_9_1) & 127;
  int stage_v_157_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001690_9_2) & 127;
  if (stage_v_157_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((sec_r001690_15_1 ^ 0x2A) * 2) + pub_r001690_1_1) & 127;
  int stage_v_158_2 = (((sec_r001690_15_2 ^ 0x2A) * 2) + pub_r001690_1_2) & 127;
  if (stage_v_158_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001690_12_1) & 127;
  int stage_v_159_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001690_12_2) & 127;
  if (stage_v_159_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001690_3_1) & 127;
  int stage_v_160_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001690_3_2) & 127;
  if (stage_v_160_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (((sec_r001690_2_1 ^ 0x2A) * 2) + pub_r001690_7_1) & 127;
  int stage_v_161_2 = (((sec_r001690_2_2 ^ 0x2A) * 2) + pub_r001690_7_2) & 127;
  if (stage_v_161_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((pub_r001690_14_1 * 2) + 17) & 63;
  int stage_v_162_2 = ((pub_r001690_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((stage_v_161_1 ^ 0x2A) * 2) + pub_r001690_10_1) & 127;
  int stage_v_163_2 = (((stage_v_161_2 ^ 0x2A) * 2) + pub_r001690_10_2) & 127;
  if (stage_v_163_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001690_8_1) & 127;
  int stage_v_164_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001690_8_2) & 127;
  if (stage_v_164_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001690_2_1) & 127;
  int stage_v_165_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001690_2_2) & 127;
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
  int stage_v_166_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001690_14_1) & 127;
  int stage_v_166_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001690_14_2) & 127;
  if (stage_v_166_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_95_1 ^ 0x2A) * 2) + pub_r001690_14_1) & 127;
  int stage_v_167_2 = (((stage_v_95_2 ^ 0x2A) * 2) + pub_r001690_14_2) & 127;
  if (stage_v_167_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_124_1 ^ 0x2A) * 2) + pub_r001690_12_1) & 127;
  int stage_v_168_2 = (((stage_v_124_2 ^ 0x2A) * 2) + pub_r001690_12_2) & 127;
  if (stage_v_168_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((sec_r001690_13_1 ^ 0x2A) * 2) + pub_r001690_3_1) & 127;
  int stage_v_169_2 = (((sec_r001690_13_2 ^ 0x2A) * 2) + pub_r001690_3_2) & 127;
  if (stage_v_169_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001690_10_1) & 127;
  int stage_v_170_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001690_10_2) & 127;
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
  int stage_v_171_1 = (((sec_r001690_15_1 ^ 0x2A) * 2) + pub_r001690_4_1) & 127;
  int stage_v_171_2 = (((sec_r001690_15_2 ^ 0x2A) * 2) + pub_r001690_4_2) & 127;
  if (stage_v_171_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001690_9_1) & 127;
  int stage_v_172_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001690_9_2) & 127;
  if (stage_v_172_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((pub_r001690_12_1 * 2) + 30) & 63;
  int stage_v_173_2 = ((pub_r001690_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001690_7_1 * 2) + 32) & 63;
  int stage_v_174_2 = ((pub_r001690_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001690_2_1) & 127;
  int stage_v_175_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001690_2_2) & 127;
  if (stage_v_175_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((pub_r001690_5_1 * 2) + 30) & 63;
  int stage_v_176_2 = ((pub_r001690_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (((stage_v_145_1 ^ 0x2A) * 2) + pub_r001690_15_1) & 127;
  int stage_v_177_2 = (((stage_v_145_2 ^ 0x2A) * 2) + pub_r001690_15_2) & 127;
  if (stage_v_177_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001690_3_1) & 127;
  int stage_v_178_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001690_3_2) & 127;
  if (stage_v_178_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001690_9_1) & 127;
  int stage_v_179_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001690_9_2) & 127;
  if (stage_v_179_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (((stage_v_168_1 ^ 0x2A) * 2) + pub_r001690_4_1) & 127;
  int stage_v_180_2 = (((stage_v_168_2 ^ 0x2A) * 2) + pub_r001690_4_2) & 127;
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
  int stage_v_181_1 = ((pub_r001690_15_1 * 2) + 17) & 63;
  int stage_v_181_2 = ((pub_r001690_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((stage_v_148_1 ^ 0x2A) * 2) + pub_r001690_6_1) & 127;
  int stage_v_182_2 = (((stage_v_148_2 ^ 0x2A) * 2) + pub_r001690_6_2) & 127;
  if (stage_v_182_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((pub_r001690_8_1 * 2) + 9) & 63;
  int stage_v_183_2 = ((pub_r001690_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001690_10_1) & 127;
  int stage_v_184_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001690_10_2) & 127;
  if (stage_v_184_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = (((sec_r001690_6_1 ^ 0x2A) * 2) + pub_r001690_1_1) & 127;
  int stage_v_185_2 = (((sec_r001690_6_2 ^ 0x2A) * 2) + pub_r001690_1_2) & 127;
  if (stage_v_185_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001690_8_1) & 127;
  int stage_v_186_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001690_8_2) & 127;
  if (stage_v_186_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001690_0_1) & 127;
  int stage_v_187_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001690_0_2) & 127;
  if (stage_v_187_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (((stage_v_143_1 ^ 0x2A) * 2) + pub_r001690_14_1) & 127;
  int stage_v_188_2 = (((stage_v_143_2 ^ 0x2A) * 2) + pub_r001690_14_2) & 127;
  if (stage_v_188_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((pub_r001690_15_1 * 2) + 26) & 63;
  int stage_v_189_2 = ((pub_r001690_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((stage_v_169_1 ^ 0x2A) * 2) + pub_r001690_10_1) & 127;
  int stage_v_190_2 = (((stage_v_169_2 ^ 0x2A) * 2) + pub_r001690_10_2) & 127;
  if (stage_v_190_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((stage_v_167_1 ^ 0x2A) * 2) + pub_r001690_5_1) & 127;
  int stage_v_191_2 = (((stage_v_167_2 ^ 0x2A) * 2) + pub_r001690_5_2) & 127;
  if (stage_v_191_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_116_1 ^ 0x2A) * 2) + pub_r001690_4_1) & 127;
  int stage_v_192_2 = (((stage_v_116_2 ^ 0x2A) * 2) + pub_r001690_4_2) & 127;
  if (stage_v_192_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((pub_r001690_0_1 * 2) + 22) & 63;
  int stage_v_193_2 = ((pub_r001690_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (((stage_v_192_1 ^ 0x2A) * 2) + pub_r001690_5_1) & 127;
  int stage_v_194_2 = (((stage_v_192_2 ^ 0x2A) * 2) + pub_r001690_5_2) & 127;
  if (stage_v_194_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((pub_r001690_1_1 * 2) + 27) & 63;
  int stage_v_195_2 = ((pub_r001690_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001690_5_1) & 127;
  int stage_v_196_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001690_5_2) & 127;
  if (stage_v_196_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((pub_r001690_5_1 * 2) + 34) & 63;
  int stage_v_197_2 = ((pub_r001690_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001690_2_1 * 2) + 24) & 63;
  int stage_v_198_2 = ((pub_r001690_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001690_11_1 * 2) + 40) & 63;
  int stage_v_199_2 = ((pub_r001690_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001690_15_1 * 2) + 22) & 63;
  int stage_v_200_2 = ((pub_r001690_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((stage_v_155_1 ^ 0x2A) * 2) + pub_r001690_10_1) & 127;
  int stage_v_201_2 = (((stage_v_155_2 ^ 0x2A) * 2) + pub_r001690_10_2) & 127;
  if (stage_v_201_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001690_8_1) & 127;
  int stage_v_202_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001690_8_2) & 127;
  if (stage_v_202_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001690_14_1) & 127;
  int stage_v_203_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001690_14_2) & 127;
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
  int stage_v_204_1 = ((pub_r001690_11_1 * 2) + 16) & 63;
  int stage_v_204_2 = ((pub_r001690_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001690_15_1) & 127;
  int stage_v_205_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001690_15_2) & 127;
  if (stage_v_205_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = (((stage_v_72_1 ^ 0x2A) * 2) + pub_r001690_0_1) & 127;
  int stage_v_206_2 = (((stage_v_72_2 ^ 0x2A) * 2) + pub_r001690_0_2) & 127;
  if (stage_v_206_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((stage_v_178_1 ^ 0x2A) * 2) + pub_r001690_15_1) & 127;
  int stage_v_207_2 = (((stage_v_178_2 ^ 0x2A) * 2) + pub_r001690_15_2) & 127;
  if (stage_v_207_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001690_15_1) & 127;
  int stage_v_208_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001690_15_2) & 127;
  if (stage_v_208_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001690_11_1) & 127;
  int stage_v_209_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001690_11_2) & 127;
  if (stage_v_209_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001690_4_1) & 127;
  int stage_v_210_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001690_4_2) & 127;
  if (stage_v_210_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((pub_r001690_2_1 * 2) + 18) & 63;
  int stage_v_211_2 = ((pub_r001690_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001690_12_1) & 127;
  int stage_v_212_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001690_12_2) & 127;
  if (stage_v_212_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001690_11_1) & 127;
  int stage_v_213_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001690_11_2) & 127;
  if (stage_v_213_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = (((stage_v_133_1 ^ 0x2A) * 2) + pub_r001690_11_1) & 127;
  int stage_v_214_2 = (((stage_v_133_2 ^ 0x2A) * 2) + pub_r001690_11_2) & 127;
  if (stage_v_214_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = (((stage_v_96_1 ^ 0x2A) * 2) + pub_r001690_10_1) & 127;
  int stage_v_215_2 = (((stage_v_96_2 ^ 0x2A) * 2) + pub_r001690_10_2) & 127;
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
  int stage_v_216_1 = ((pub_r001690_5_1 * 2) + 18) & 63;
  int stage_v_216_2 = ((pub_r001690_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((stage_v_150_1 ^ 0x2A) * 2) + pub_r001690_0_1) & 127;
  int stage_v_217_2 = (((stage_v_150_2 ^ 0x2A) * 2) + pub_r001690_0_2) & 127;
  if (stage_v_217_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((pub_r001690_9_1 * 2) + 5) & 63;
  int stage_v_218_2 = ((pub_r001690_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001690_0_1) & 127;
  int stage_v_219_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001690_0_2) & 127;
  if (stage_v_219_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((pub_r001690_14_1 * 2) + 18) & 63;
  int stage_v_220_2 = ((pub_r001690_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = (((stage_v_187_1 ^ 0x2A) * 2) + pub_r001690_11_1) & 127;
  int stage_v_221_2 = (((stage_v_187_2 ^ 0x2A) * 2) + pub_r001690_11_2) & 127;
  if (stage_v_221_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((pub_r001690_13_1 * 2) + 35) & 63;
  int stage_v_222_2 = ((pub_r001690_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = (((stage_v_116_1 ^ 0x2A) * 2) + pub_r001690_3_1) & 127;
  int stage_v_223_2 = (((stage_v_116_2 ^ 0x2A) * 2) + pub_r001690_3_2) & 127;
  if (stage_v_223_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = (((stage_v_122_1 ^ 0x2A) * 2) + pub_r001690_2_1) & 127;
  int stage_v_224_2 = (((stage_v_122_2 ^ 0x2A) * 2) + pub_r001690_2_2) & 127;
  if (stage_v_224_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
  }
  if (stage_v_224_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001690_2_1) & 127;
  int stage_v_225_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001690_2_2) & 127;
  if (stage_v_225_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
  }
  if (stage_v_225_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001690_5_1) & 127;
  int stage_v_226_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001690_5_2) & 127;
  if (stage_v_226_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
  }
  if (stage_v_226_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = (((stage_v_121_1 ^ 0x2A) * 2) + pub_r001690_9_1) & 127;
  int stage_v_227_2 = (((stage_v_121_2 ^ 0x2A) * 2) + pub_r001690_9_2) & 127;
  if (stage_v_227_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
  }
  if (stage_v_227_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((pub_r001690_14_1 * 2) + 30) & 63;
  int stage_v_228_2 = ((pub_r001690_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_96_1 ^ 0x2A) * 2) + pub_r001690_7_1) & 127;
  int stage_v_229_2 = (((stage_v_96_2 ^ 0x2A) * 2) + pub_r001690_7_2) & 127;
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
  int stage_v_230_1 = ((pub_r001690_5_1 * 2) + 22) & 63;
  int stage_v_230_2 = ((pub_r001690_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001690_7_1 == pub_r001690_7_2);
  __CPROVER_assume(pub_r001690_0_1 == pub_r001690_0_2);
  __CPROVER_assume(sec_r001690_7_1 != sec_r001690_7_2);
  __CPROVER_assume(pub_r001690_8_1 == pub_r001690_8_2);
  __CPROVER_assume(sec_r001690_6_1 != sec_r001690_6_2);
  __CPROVER_assume(pub_r001690_4_1 == pub_r001690_4_2);
  __CPROVER_assume(sec_r001690_12_1 != sec_r001690_12_2);
  __CPROVER_assume(sec_r001690_13_1 != sec_r001690_13_2);
  __CPROVER_assume(pub_r001690_3_1 == pub_r001690_3_2);
  __CPROVER_assume(sec_r001690_14_1 != sec_r001690_14_2);
  __CPROVER_assume(pub_r001690_6_1 == pub_r001690_6_2);
  __CPROVER_assume(sec_r001690_5_1 != sec_r001690_5_2);
  __CPROVER_assume(pub_r001690_9_1 == pub_r001690_9_2);
  __CPROVER_assume(pub_r001690_14_1 == pub_r001690_14_2);
  __CPROVER_assume(pub_r001690_2_1 == pub_r001690_2_2);
  __CPROVER_assume(sec_r001690_0_1 != sec_r001690_0_2);
  __CPROVER_assume(pub_r001690_1_1 == pub_r001690_1_2);
  __CPROVER_assume(pub_r001690_15_1 == pub_r001690_15_2);
  __CPROVER_assume(sec_r001690_4_1 != sec_r001690_4_2);
  __CPROVER_assume(pub_r001690_10_1 == pub_r001690_10_2);
  __CPROVER_assume(sec_r001690_15_1 != sec_r001690_15_2);
  __CPROVER_assume(sec_r001690_11_1 != sec_r001690_11_2);
  __CPROVER_assume(pub_r001690_11_1 == pub_r001690_11_2);
  __CPROVER_assume(sec_r001690_9_1 != sec_r001690_9_2);
  __CPROVER_assume(pub_r001690_12_1 == pub_r001690_12_2);
  __CPROVER_assume(sec_r001690_8_1 != sec_r001690_8_2);
  __CPROVER_assume(pub_r001690_13_1 == pub_r001690_13_2);
  __CPROVER_assume(pub_r001690_5_1 == pub_r001690_5_2);
  __CPROVER_assume(sec_r001690_3_1 != sec_r001690_3_2);
  __CPROVER_assume(sec_r001690_2_1 != sec_r001690_2_2);
  __CPROVER_assume(sec_r001690_10_1 != sec_r001690_10_2);
  __CPROVER_assume(sec_r001690_1_1 != sec_r001690_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.density == st_var_2_2.density);
  assert(st_var_2_1.trace == st_var_2_2.trace);
  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.round_key == st_var_3_2.round_key);
  assert(st_var_3_1.nonce == st_var_3_2.nonce);
  assert(st_var_3_1.counter == st_var_3_2.counter);
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
  assert(stage_v_226_1 == stage_v_226_2);
  assert(stage_v_227_1 == stage_v_227_2);
  assert(stage_v_228_1 == stage_v_228_2);
  assert(stage_v_229_1 == stage_v_229_2);
  assert(stage_v_230_1 == stage_v_230_2);
}


