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
struct FilterState_R001694_9413_0
{
  unsigned char mode;
  short cutoff;
  int prev_out;
  short gain_db;
  unsigned char prev_in;
  int buffer[3];
};
struct Transaction_R001694_9413_1
{
  int auth_code;
  int account_id;
  short rate;
  int fee;
  short balance;
  int status;
  int buffer[3];
};
struct MatrixBlock_R001694_9413_2
{
  short scale;
  short density;
  short dim;
  int determinant;
  int buffer[3];
};
union RegisterBank_R001694_9413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001694_9413_1
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
void fn_R001694_9413_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st_1 = {0};
  struct FilterState_R001694_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_52_1 = local_arr_1[aux_1 % 3];
  int accumulator_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_52_2 * 2)) & 127;
  int vector_37_1 = 0;
  int vector_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_37_1 = ((vector_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_37_2 = ((vector_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_37_1) & 127;
    acc_2 = (acc_2 + vector_37_2) & 127;
  }

  int anchor_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_26_1)
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

  switch (anchor_26_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_52_1 == accumulator_52_2);
  assert(vector_37_1 == vector_37_2);
  assert(anchor_26_1 == anchor_26_2);
}

int fn_R001694_9413_0(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_52 = local_arr[aux % 3];
  acc = (acc + (accumulator_52 * 2)) & 127;
  int vector_37 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_37 = ((vector_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_37) & 127;
  }

  int anchor_26 = (aux + st.buffer[1]) & 3;
  switch (anchor_26)
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

void fn_R001694_9413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001694_9413_2 st_1 = {0};
  struct MatrixBlock_R001694_9413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int factor_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_49_1)
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

  switch (factor_49_2)
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

  int cursor_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_53_1) & 63;
  aux_2 = (aux_2 + cursor_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_14_1 > 21)
  {
    acc_1 = ((acc_1 + (quantum_14_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_14_2 > 21)
  {
    acc_2 = ((acc_2 + (quantum_14_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_14_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_49_1 == factor_49_2);
  assert(cursor_53_1 == cursor_53_2);
  assert(quantum_14_1 == quantum_14_2);
}

int fn_R001694_9413_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001694_9413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int factor_49 = (aux + st.buffer[1]) & 3;
  switch (factor_49)
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

  int cursor_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_53) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_14 > 21)
  {
    acc = ((acc + (quantum_14 * 2)) + 5) & 127;
    aux ^= quantum_14 & 15;
  }
  else
  {
    acc = ((acc - quantum_14) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001694_9413_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st_1 = {0};
  struct FilterState_R001694_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_91_1 = local_arr_1[aux_1 % 3];
  int delta_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_91_2 * 2)) & 127;
  int checksum_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_18_1) & 63;
  aux_2 = (aux_2 + checksum_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_32_1 = 0;
  int bound_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_32_1 = ((bound_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_32_2 = ((bound_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_32_1) & 127;
    acc_2 = (acc_2 + bound_32_2) & 127;
  }

  int index_reg_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_72_1)
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

  switch (index_reg_72_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_91_1 == delta_91_2);
  assert(checksum_18_1 == checksum_18_2);
  assert(bound_32_1 == bound_32_2);
  assert(index_reg_72_1 == index_reg_72_2);
}

int fn_R001694_9413_2(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int delta_91 = local_arr[aux % 3];
  acc = (acc + (delta_91 * 2)) & 127;
  int checksum_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_18) & 63;
  acc ^= aux;
  int bound_32 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_32 = ((bound_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_32) & 127;
  }

  int index_reg_72 = (aux + st.buffer[1]) & 3;
  switch (index_reg_72)
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

void fn_R001694_9413_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001694_9413_1 st_1 = {0};
  struct Transaction_R001694_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int accumulator_12_1 = 0;
  int accumulator_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_12_1 = ((accumulator_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_12_2 = ((accumulator_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_12_1) & 127;
    acc_2 = (acc_2 + accumulator_12_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_42_1 > 27)
  {
    acc_1 = ((acc_1 + (vector_42_1 * 2)) + 5) & 127;
    aux_1 ^= vector_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_42_2 > 27)
  {
    acc_2 = ((acc_2 + (vector_42_2 * 2)) + 5) & 127;
    aux_2 ^= vector_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_42_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_51_1)
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

  switch (vector_51_2)
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
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_12_1 == accumulator_12_2);
  assert(vector_42_1 == vector_42_2);
  assert(vector_51_1 == vector_51_2);
}

int fn_R001694_9413_3(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001694_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int accumulator_12 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_12 = ((accumulator_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_12) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_42 > 27)
  {
    acc = ((acc + (vector_42 * 2)) + 5) & 127;
    aux ^= vector_42 & 15;
  }
  else
  {
    acc = ((acc - vector_42) + 11) & 127;
    aux += 3;
  }
  int vector_51 = (aux + st.buffer[1]) & 3;
  switch (vector_51)
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

void fn_R001694_9413_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st_1 = {0};
  struct FilterState_R001694_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int pivot_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_19_1 > 26)
  {
    acc_1 = ((acc_1 + (pivot_19_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_19_2 > 26)
  {
    acc_2 = ((acc_2 + (pivot_19_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_71_1)
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

  switch (pivot_71_2)
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

  int quantum_86_1 = 0;
  int quantum_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_86_1 = ((quantum_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_86_2 = ((quantum_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_86_1) & 127;
    acc_2 = (acc_2 + quantum_86_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_19_1 == pivot_19_2);
  assert(pivot_71_1 == pivot_71_2);
  assert(quantum_86_1 == quantum_86_2);
}

int fn_R001694_9413_4(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int pivot_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_19 > 26)
  {
    acc = ((acc + (pivot_19 * 2)) + 5) & 127;
    aux ^= pivot_19 & 15;
  }
  else
  {
    acc = ((acc - pivot_19) + 11) & 127;
    aux += 3;
  }
  int pivot_71 = (aux + st.buffer[1]) & 3;
  switch (pivot_71)
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

  int quantum_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_86 = ((quantum_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_86) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001694_9413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001694_9413_1 st_1 = {0};
  struct Transaction_R001694_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int cursor_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_46_1 > 34)
  {
    acc_1 = ((acc_1 + (cursor_46_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_46_2 > 34)
  {
    acc_2 = ((acc_2 + (cursor_46_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_46_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_46_1 == cursor_46_2);
}

int fn_R001694_9413_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001694_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int cursor_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_46 > 34)
  {
    acc = ((acc + (cursor_46 * 2)) + 5) & 127;
    aux ^= cursor_46 & 15;
  }
  else
  {
    acc = ((acc - cursor_46) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001694_9413_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001694_9413_2 st_1 = {0};
  struct MatrixBlock_R001694_9413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int offset_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_71_1 > 44)
  {
    acc_1 = ((acc_1 + (offset_71_1 * 2)) + 5) & 127;
    aux_1 ^= offset_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_71_2 > 44)
  {
    acc_2 = ((acc_2 + (offset_71_2 * 2)) + 5) & 127;
    aux_2 ^= offset_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_82_1) & 63;
  aux_2 = (aux_2 + threshold_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_31_1)
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

  switch (index_reg_31_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_71_1 == offset_71_2);
  assert(threshold_82_1 == threshold_82_2);
  assert(index_reg_31_1 == index_reg_31_2);
}

int fn_R001694_9413_6(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001694_9413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int offset_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_71 > 44)
  {
    acc = ((acc + (offset_71 * 2)) + 5) & 127;
    aux ^= offset_71 & 15;
  }
  else
  {
    acc = ((acc - offset_71) + 11) & 127;
    aux += 3;
  }
  int threshold_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_82) & 63;
  acc ^= aux;
  int index_reg_31 = (aux + st.buffer[1]) & 3;
  switch (index_reg_31)
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

void fn_R001694_9413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st_1 = {0};
  struct FilterState_R001694_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_52_1 = local_arr_1[aux_1 % 3];
  int margin_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_52_2 * 2)) & 127;
  int damping_46_1 = 0;
  int damping_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_46_1 = ((damping_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_46_2 = ((damping_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_46_1) & 127;
    acc_2 = (acc_2 + damping_46_2) & 127;
  }

  int damping_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_53_1)
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

  switch (damping_53_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_52_1 == margin_52_2);
  assert(damping_46_1 == damping_46_2);
  assert(damping_53_1 == damping_53_2);
}

int fn_R001694_9413_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int margin_52 = local_arr[aux % 3];
  acc = (acc + (margin_52 * 2)) & 127;
  int damping_46 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_46 = ((damping_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_46) & 127;
  }

  int damping_53 = (aux + st.buffer[1]) & 3;
  switch (damping_53)
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

void fn_R001694_9413_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st_1 = {0};
  struct FilterState_R001694_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int segment_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_58_1)
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

  switch (segment_58_2)
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

  int segment_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_65_1 > 47)
  {
    acc_1 = ((acc_1 + (segment_65_1 * 2)) + 5) & 127;
    aux_1 ^= segment_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_65_2 > 47)
  {
    acc_2 = ((acc_2 + (segment_65_2 * 2)) + 5) & 127;
    aux_2 ^= segment_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_27_1 = 0;
  int bound_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_27_1 = ((bound_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_27_2 = ((bound_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_27_1) & 127;
    acc_2 = (acc_2 + bound_27_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_58_1 == segment_58_2);
  assert(segment_65_1 == segment_65_2);
  assert(bound_27_1 == bound_27_2);
}

int fn_R001694_9413_8(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int segment_58 = (aux + st.buffer[1]) & 3;
  switch (segment_58)
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

  int segment_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_65 > 47)
  {
    acc = ((acc + (segment_65 * 2)) + 5) & 127;
    aux ^= segment_65 & 15;
  }
  else
  {
    acc = ((acc - segment_65) + 11) & 127;
    aux += 3;
  }
  int bound_27 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_27 = ((bound_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_27) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001694_9413_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001694_9413_2 st_1 = {0};
  struct MatrixBlock_R001694_9413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int damping_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_34_1) & 63;
  aux_2 = (aux_2 + damping_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_30_1 = 0;
  int parity_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_30_1 = ((parity_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_30_2 = ((parity_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_30_1) & 127;
    acc_2 = (acc_2 + parity_30_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_34_1 == damping_34_2);
  assert(parity_30_1 == parity_30_2);
}

int fn_R001694_9413_9(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001694_9413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int damping_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_34) & 63;
  acc ^= aux;
  int parity_30 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_30 = ((parity_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_30) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001694_9413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001694_9413_1 st_1 = {0};
  struct Transaction_R001694_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_36_1 > 41)
  {
    acc_1 = ((acc_1 + (offset_36_1 * 2)) + 5) & 127;
    aux_1 ^= offset_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_36_2 > 41)
  {
    acc_2 = ((acc_2 + (offset_36_2 * 2)) + 5) & 127;
    aux_2 ^= offset_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_36_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_36_1 == offset_36_2);
}

int fn_R001694_9413_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001694_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_36 > 41)
  {
    acc = ((acc + (offset_36 * 2)) + 5) & 127;
    aux ^= offset_36 & 15;
  }
  else
  {
    acc = ((acc - offset_36) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001694_9413_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001694_9413_1 st_1 = {0};
  struct Transaction_R001694_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int vector_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_22_1 > 32)
  {
    acc_1 = ((acc_1 + (vector_22_1 * 2)) + 5) & 127;
    aux_1 ^= vector_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_22_2 > 32)
  {
    acc_2 = ((acc_2 + (vector_22_2 * 2)) + 5) & 127;
    aux_2 ^= vector_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_79_1 = 0;
  int phase_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_79_1 = ((phase_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_79_2 = ((phase_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_79_1) & 127;
    acc_2 = (acc_2 + phase_79_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_39_1 = local_arr_1[aux_1 % 3];
  int accumulator_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_39_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_22_1 == vector_22_2);
  assert(phase_79_1 == phase_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_39_1 == accumulator_39_2);
}

int fn_R001694_9413_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001694_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int vector_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_22 > 32)
  {
    acc = ((acc + (vector_22 * 2)) + 5) & 127;
    aux ^= vector_22 & 15;
  }
  else
  {
    acc = ((acc - vector_22) + 11) & 127;
    aux += 3;
  }
  int phase_79 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_79 = ((phase_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_79) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int accumulator_39 = local_arr[aux % 3];
  acc = (acc + (accumulator_39 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001694_9413_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st_1 = {0};
  struct FilterState_R001694_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int damping_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_17_1 > 47)
  {
    acc_1 = ((acc_1 + (damping_17_1 * 2)) + 5) & 127;
    aux_1 ^= damping_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_17_2 > 47)
  {
    acc_2 = ((acc_2 + (damping_17_2 * 2)) + 5) & 127;
    aux_2 ^= damping_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_81_1 = local_arr_1[aux_1 % 3];
  int accumulator_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_81_2 * 2)) & 127;
  int tally_87_1 = 0;
  int tally_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_87_1 = ((tally_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_87_2 = ((tally_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_87_1) & 127;
    acc_2 = (acc_2 + tally_87_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_17_1 == damping_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_81_1 == accumulator_81_2);
  assert(tally_87_1 == tally_87_2);
}

int fn_R001694_9413_12(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int damping_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_17 > 47)
  {
    acc = ((acc + (damping_17 * 2)) + 5) & 127;
    aux ^= damping_17 & 15;
  }
  else
  {
    acc = ((acc - damping_17) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_81 = local_arr[aux % 3];
  acc = (acc + (accumulator_81 * 2)) & 127;
  int tally_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_87 = ((tally_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_87) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001694_9413_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st_1 = {0};
  struct FilterState_R001694_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_41_1 = 0;
  int segment_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_41_1 = ((segment_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_41_2 = ((segment_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_41_1) & 127;
    acc_2 = (acc_2 + segment_41_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_41_1 == segment_41_2);
}

int fn_R001694_9413_13(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_41 = ((segment_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_41) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001694_9413_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001694_9413_1 st_1 = {0};
  struct Transaction_R001694_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_10_1 = local_arr_1[aux_1 % 3];
  int stride_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_10_2 * 2)) & 127;
  int index_reg_72_1 = 0;
  int index_reg_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_72_1 = ((index_reg_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_72_2 = ((index_reg_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_72_1) & 127;
    acc_2 = (acc_2 + index_reg_72_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_10_1 == stride_10_2);
  assert(index_reg_72_1 == index_reg_72_2);
}

int fn_R001694_9413_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001694_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int stride_10 = local_arr[aux % 3];
  acc = (acc + (stride_10 * 2)) & 127;
  int index_reg_72 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_72 = ((index_reg_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_72) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001694_9413_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001694_9413_1 st_1 = {0};
  struct Transaction_R001694_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int sample_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_54_1)
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

  switch (sample_54_2)
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

  int quotient_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_25_1 > 36)
  {
    acc_1 = ((acc_1 + (quotient_25_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_25_2 > 36)
  {
    acc_2 = ((acc_2 + (quotient_25_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_25_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_19_1 = local_arr_1[aux_1 % 3];
  int threshold_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_19_2 * 2)) & 127;
  int tally_30_1 = 0;
  int tally_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_30_1 = ((tally_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_30_2 = ((tally_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_30_1) & 127;
    acc_2 = (acc_2 + tally_30_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_54_1 == sample_54_2);
  assert(quotient_25_1 == quotient_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_19_1 == threshold_19_2);
  assert(tally_30_1 == tally_30_2);
}

int fn_R001694_9413_15(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001694_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int sample_54 = (aux + st.buffer[1]) & 3;
  switch (sample_54)
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

  int quotient_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_25 > 36)
  {
    acc = ((acc + (quotient_25 * 2)) + 5) & 127;
    aux ^= quotient_25 & 15;
  }
  else
  {
    acc = ((acc - quotient_25) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_19 = local_arr[aux % 3];
  acc = (acc + (threshold_19 * 2)) & 127;
  int tally_30 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_30 = ((tally_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_30) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001694_9413_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st_1 = {0};
  struct FilterState_R001694_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int window_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_68_1) & 63;
  aux_2 = (aux_2 + window_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_87_1)
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

  switch (threshold_87_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_68_1 == window_68_2);
  assert(threshold_87_1 == threshold_87_2);
}

int fn_R001694_9413_16(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int window_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_68) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_87 = (aux + st.buffer[1]) & 3;
  switch (threshold_87)
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

void fn_R001694_9413_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st_1 = {0};
  struct FilterState_R001694_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int quantum_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_73_1) & 63;
  aux_2 = (aux_2 + quantum_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_84_1 > 42)
  {
    acc_1 = ((acc_1 + (scale_84_1 * 2)) + 5) & 127;
    aux_1 ^= scale_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_84_2 > 42)
  {
    acc_2 = ((acc_2 + (scale_84_2 * 2)) + 5) & 127;
    aux_2 ^= scale_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_84_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_66_1 = 0;
  int factor_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_66_1 = ((factor_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_66_2 = ((factor_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_66_1) & 127;
    acc_2 = (acc_2 + factor_66_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_73_1 == quantum_73_2);
  assert(scale_84_1 == scale_84_2);
  assert(factor_66_1 == factor_66_2);
}

int fn_R001694_9413_17(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001694_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int quantum_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_73) & 63;
  acc ^= aux;
  int scale_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_84 > 42)
  {
    acc = ((acc + (scale_84 * 2)) + 5) & 127;
    aux ^= scale_84 & 15;
  }
  else
  {
    acc = ((acc - scale_84) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_66 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_66 = ((factor_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_66) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001694_9413_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001694_9413_2 st_1 = {0};
  struct MatrixBlock_R001694_9413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int scale_44_1 = 0;
  int scale_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_44_1 = ((scale_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_44_2 = ((scale_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_44_1) & 127;
    acc_2 = (acc_2 + scale_44_2) & 127;
  }

  int tally_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_56_1) & 63;
  aux_2 = (aux_2 + tally_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_44_1 == scale_44_2);
  assert(tally_56_1 == tally_56_2);
}

int fn_R001694_9413_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001694_9413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int scale_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_44 = ((scale_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_44) & 127;
  }

  int tally_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_56) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001694_9413_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001694_9413_2 st_1 = {0};
  struct MatrixBlock_R001694_9413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int phase_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_69_1) & 63;
  aux_2 = (aux_2 + phase_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_12_1 > 44)
  {
    acc_1 = ((acc_1 + (pivot_12_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_12_2 > 44)
  {
    acc_2 = ((acc_2 + (pivot_12_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_69_1 == phase_69_2);
  assert(pivot_12_1 == pivot_12_2);
}

int fn_R001694_9413_19(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001694_9413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int phase_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_69) & 63;
  acc ^= aux;
  int pivot_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_12 > 44)
  {
    acc = ((acc + (pivot_12 * 2)) + 5) & 127;
    aux ^= pivot_12 & 15;
  }
  else
  {
    acc = ((acc - pivot_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001694_9413_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001694_9413_1 st_1 = {0};
  struct Transaction_R001694_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int accumulator_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_31_1) & 63;
  aux_2 = (aux_2 + accumulator_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_31_1 == accumulator_31_2);
}

int fn_R001694_9413_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001694_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int accumulator_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_31) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001694_9413_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001694_9413_2 st_1 = {0};
  struct MatrixBlock_R001694_9413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int offset_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_42_1)
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

  switch (offset_42_2)
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

  int mask_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_14_1 > 46)
  {
    acc_1 = ((acc_1 + (mask_14_1 * 2)) + 5) & 127;
    aux_1 ^= mask_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_14_2 > 46)
  {
    acc_2 = ((acc_2 + (mask_14_2 * 2)) + 5) & 127;
    aux_2 ^= mask_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_87_1 = 0;
  int phase_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_87_1 = ((phase_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_87_2 = ((phase_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_87_1) & 127;
    acc_2 = (acc_2 + phase_87_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_42_1 == offset_42_2);
  assert(mask_14_1 == mask_14_2);
  assert(phase_87_1 == phase_87_2);
}

int fn_R001694_9413_21(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001694_9413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int offset_42 = (aux + st.buffer[1]) & 3;
  switch (offset_42)
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

  int mask_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_14 > 46)
  {
    acc = ((acc + (mask_14 * 2)) + 5) & 127;
    aux ^= mask_14 & 15;
  }
  else
  {
    acc = ((acc - mask_14) + 11) & 127;
    aux += 3;
  }
  int phase_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_87 = ((phase_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_87) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001694_0_1;
  int sec_r001694_0_2;
  int sec_r001694_1_1;
  int sec_r001694_1_2;
  int sec_r001694_2_1;
  int sec_r001694_2_2;
  int sec_r001694_3_1;
  int sec_r001694_3_2;
  int sec_r001694_4_1;
  int sec_r001694_4_2;
  int sec_r001694_5_1;
  int sec_r001694_5_2;
  int sec_r001694_6_1;
  int sec_r001694_6_2;
  int sec_r001694_7_1;
  int sec_r001694_7_2;
  int sec_r001694_8_1;
  int sec_r001694_8_2;
  int sec_r001694_9_1;
  int sec_r001694_9_2;
  int sec_r001694_10_1;
  int sec_r001694_10_2;
  int sec_r001694_11_1;
  int sec_r001694_11_2;
  int sec_r001694_12_1;
  int sec_r001694_12_2;
  int sec_r001694_13_1;
  int sec_r001694_13_2;
  int sec_r001694_14_1;
  int sec_r001694_14_2;
  int sec_r001694_15_1;
  int sec_r001694_15_2;
  int sec_r001694_16_1;
  int sec_r001694_16_2;
  int sec_r001694_17_1;
  int sec_r001694_17_2;
  int sec_r001694_18_1;
  int sec_r001694_18_2;
  int sec_r001694_19_1;
  int sec_r001694_19_2;
  int pub_r001694_0_1;
  int pub_r001694_0_2;
  int pub_r001694_1_1;
  int pub_r001694_1_2;
  int pub_r001694_2_1;
  int pub_r001694_2_2;
  int pub_r001694_3_1;
  int pub_r001694_3_2;
  int pub_r001694_4_1;
  int pub_r001694_4_2;
  int pub_r001694_5_1;
  int pub_r001694_5_2;
  int pub_r001694_6_1;
  int pub_r001694_6_2;
  int pub_r001694_7_1;
  int pub_r001694_7_2;
  int pub_r001694_8_1;
  int pub_r001694_8_2;
  int pub_r001694_9_1;
  int pub_r001694_9_2;
  int pub_r001694_10_1;
  int pub_r001694_10_2;
  int pub_r001694_11_1;
  int pub_r001694_11_2;
  int pub_r001694_12_1;
  int pub_r001694_12_2;
  int pub_r001694_13_1;
  int pub_r001694_13_2;
  int pub_r001694_14_1;
  int pub_r001694_14_2;
  int pub_r001694_15_1;
  int pub_r001694_15_2;
  int pub_r001694_16_1;
  int pub_r001694_16_2;
  int pub_r001694_17_1;
  int pub_r001694_17_2;
  int pub_r001694_18_1;
  int pub_r001694_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001694_0_1 >= (-100)) && (pub_r001694_0_1 <= 100));
  __CPROVER_assume((pub_r001694_0_2 >= (-100)) && (pub_r001694_0_2 <= 100));
  __CPROVER_assume((pub_r001694_1_1 >= (-100)) && (pub_r001694_1_1 <= 100));
  __CPROVER_assume((pub_r001694_1_2 >= (-100)) && (pub_r001694_1_2 <= 100));
  __CPROVER_assume((pub_r001694_2_1 >= (-100)) && (pub_r001694_2_1 <= 100));
  __CPROVER_assume((pub_r001694_2_2 >= (-100)) && (pub_r001694_2_2 <= 100));
  __CPROVER_assume((pub_r001694_3_1 >= (-100)) && (pub_r001694_3_1 <= 100));
  __CPROVER_assume((pub_r001694_3_2 >= (-100)) && (pub_r001694_3_2 <= 100));
  __CPROVER_assume((pub_r001694_4_1 >= (-100)) && (pub_r001694_4_1 <= 100));
  __CPROVER_assume((pub_r001694_4_2 >= (-100)) && (pub_r001694_4_2 <= 100));
  __CPROVER_assume((pub_r001694_5_1 >= (-100)) && (pub_r001694_5_1 <= 100));
  __CPROVER_assume((pub_r001694_5_2 >= (-100)) && (pub_r001694_5_2 <= 100));
  __CPROVER_assume((pub_r001694_6_1 >= (-100)) && (pub_r001694_6_1 <= 100));
  __CPROVER_assume((pub_r001694_6_2 >= (-100)) && (pub_r001694_6_2 <= 100));
  __CPROVER_assume((pub_r001694_7_1 >= (-100)) && (pub_r001694_7_1 <= 100));
  __CPROVER_assume((pub_r001694_7_2 >= (-100)) && (pub_r001694_7_2 <= 100));
  __CPROVER_assume((pub_r001694_8_1 >= (-100)) && (pub_r001694_8_1 <= 100));
  __CPROVER_assume((pub_r001694_8_2 >= (-100)) && (pub_r001694_8_2 <= 100));
  __CPROVER_assume((pub_r001694_9_1 >= (-100)) && (pub_r001694_9_1 <= 100));
  __CPROVER_assume((pub_r001694_9_2 >= (-100)) && (pub_r001694_9_2 <= 100));
  __CPROVER_assume((pub_r001694_10_1 >= (-100)) && (pub_r001694_10_1 <= 100));
  __CPROVER_assume((pub_r001694_10_2 >= (-100)) && (pub_r001694_10_2 <= 100));
  __CPROVER_assume((pub_r001694_11_1 >= (-100)) && (pub_r001694_11_1 <= 100));
  __CPROVER_assume((pub_r001694_11_2 >= (-100)) && (pub_r001694_11_2 <= 100));
  __CPROVER_assume((pub_r001694_12_1 >= (-100)) && (pub_r001694_12_1 <= 100));
  __CPROVER_assume((pub_r001694_12_2 >= (-100)) && (pub_r001694_12_2 <= 100));
  __CPROVER_assume((pub_r001694_13_1 >= (-100)) && (pub_r001694_13_1 <= 100));
  __CPROVER_assume((pub_r001694_13_2 >= (-100)) && (pub_r001694_13_2 <= 100));
  __CPROVER_assume((pub_r001694_14_1 >= (-100)) && (pub_r001694_14_1 <= 100));
  __CPROVER_assume((pub_r001694_14_2 >= (-100)) && (pub_r001694_14_2 <= 100));
  __CPROVER_assume((pub_r001694_15_1 >= (-100)) && (pub_r001694_15_1 <= 100));
  __CPROVER_assume((pub_r001694_15_2 >= (-100)) && (pub_r001694_15_2 <= 100));
  __CPROVER_assume((pub_r001694_16_1 >= (-100)) && (pub_r001694_16_1 <= 100));
  __CPROVER_assume((pub_r001694_16_2 >= (-100)) && (pub_r001694_16_2 <= 100));
  __CPROVER_assume((pub_r001694_17_1 >= (-100)) && (pub_r001694_17_1 <= 100));
  __CPROVER_assume((pub_r001694_17_2 >= (-100)) && (pub_r001694_17_2 <= 100));
  __CPROVER_assume((pub_r001694_18_1 >= (-100)) && (pub_r001694_18_1 <= 100));
  __CPROVER_assume((pub_r001694_18_2 >= (-100)) && (pub_r001694_18_2 <= 100));
  __CPROVER_assume((sec_r001694_0_1 >= 0) && (sec_r001694_0_1 <= 255));
  __CPROVER_assume((sec_r001694_0_2 >= 0) && (sec_r001694_0_2 <= 255));
  __CPROVER_assume((sec_r001694_1_1 >= 0) && (sec_r001694_1_1 <= 255));
  __CPROVER_assume((sec_r001694_1_2 >= 0) && (sec_r001694_1_2 <= 255));
  __CPROVER_assume((sec_r001694_2_1 >= 0) && (sec_r001694_2_1 <= 255));
  __CPROVER_assume((sec_r001694_2_2 >= 0) && (sec_r001694_2_2 <= 255));
  __CPROVER_assume((sec_r001694_3_1 >= 0) && (sec_r001694_3_1 <= 255));
  __CPROVER_assume((sec_r001694_3_2 >= 0) && (sec_r001694_3_2 <= 255));
  __CPROVER_assume((sec_r001694_4_1 >= 0) && (sec_r001694_4_1 <= 255));
  __CPROVER_assume((sec_r001694_4_2 >= 0) && (sec_r001694_4_2 <= 255));
  __CPROVER_assume((sec_r001694_5_1 >= 0) && (sec_r001694_5_1 <= 255));
  __CPROVER_assume((sec_r001694_5_2 >= 0) && (sec_r001694_5_2 <= 255));
  __CPROVER_assume((sec_r001694_6_1 >= 0) && (sec_r001694_6_1 <= 255));
  __CPROVER_assume((sec_r001694_6_2 >= 0) && (sec_r001694_6_2 <= 255));
  __CPROVER_assume((sec_r001694_7_1 >= 0) && (sec_r001694_7_1 <= 255));
  __CPROVER_assume((sec_r001694_7_2 >= 0) && (sec_r001694_7_2 <= 255));
  __CPROVER_assume((sec_r001694_8_1 >= 0) && (sec_r001694_8_1 <= 255));
  __CPROVER_assume((sec_r001694_8_2 >= 0) && (sec_r001694_8_2 <= 255));
  __CPROVER_assume((sec_r001694_9_1 >= 0) && (sec_r001694_9_1 <= 255));
  __CPROVER_assume((sec_r001694_9_2 >= 0) && (sec_r001694_9_2 <= 255));
  __CPROVER_assume((sec_r001694_10_1 >= 0) && (sec_r001694_10_1 <= 255));
  __CPROVER_assume((sec_r001694_10_2 >= 0) && (sec_r001694_10_2 <= 255));
  __CPROVER_assume((sec_r001694_11_1 >= 0) && (sec_r001694_11_1 <= 255));
  __CPROVER_assume((sec_r001694_11_2 >= 0) && (sec_r001694_11_2 <= 255));
  __CPROVER_assume((sec_r001694_12_1 >= 0) && (sec_r001694_12_1 <= 255));
  __CPROVER_assume((sec_r001694_12_2 >= 0) && (sec_r001694_12_2 <= 255));
  __CPROVER_assume((sec_r001694_13_1 >= 0) && (sec_r001694_13_1 <= 255));
  __CPROVER_assume((sec_r001694_13_2 >= 0) && (sec_r001694_13_2 <= 255));
  __CPROVER_assume((sec_r001694_14_1 >= 0) && (sec_r001694_14_1 <= 255));
  __CPROVER_assume((sec_r001694_14_2 >= 0) && (sec_r001694_14_2 <= 255));
  __CPROVER_assume((sec_r001694_15_1 >= 0) && (sec_r001694_15_1 <= 255));
  __CPROVER_assume((sec_r001694_15_2 >= 0) && (sec_r001694_15_2 <= 255));
  __CPROVER_assume((sec_r001694_16_1 >= 0) && (sec_r001694_16_1 <= 255));
  __CPROVER_assume((sec_r001694_16_2 >= 0) && (sec_r001694_16_2 <= 255));
  __CPROVER_assume((sec_r001694_17_1 >= 0) && (sec_r001694_17_1 <= 255));
  __CPROVER_assume((sec_r001694_17_2 >= 0) && (sec_r001694_17_2 <= 255));
  __CPROVER_assume((sec_r001694_18_1 >= 0) && (sec_r001694_18_1 <= 255));
  __CPROVER_assume((sec_r001694_18_2 >= 0) && (sec_r001694_18_2 <= 255));
  __CPROVER_assume((sec_r001694_19_1 >= 0) && (sec_r001694_19_1 <= 255));
  __CPROVER_assume((sec_r001694_19_2 >= 0) && (sec_r001694_19_2 <= 255));
  struct FilterState_R001694_9413_0 st_var_0_1 = {0};
  struct FilterState_R001694_9413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001694_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001694_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001694_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001694_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001694_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001694_0_2 + 7) & 15;
  struct Transaction_R001694_9413_1 st_var_1_1 = {0};
  struct Transaction_R001694_9413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001694_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001694_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001694_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001694_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001694_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001694_0_2 + 9) & 15;
  struct MatrixBlock_R001694_9413_2 st_var_2_1 = {0};
  struct MatrixBlock_R001694_9413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001694_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001694_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001694_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001694_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001694_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001694_0_2 + 11) & 15;
  union RegisterBank_R001694_9413_0 u_var_1;
  union RegisterBank_R001694_9413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001694_9413_0(sec_r001694_0_1, pub_r001694_1_1, pub_r001694_2_1);
  int helper_flow_0_2 = fn_R001694_9413_0(sec_r001694_0_2, pub_r001694_1_2, pub_r001694_2_2);
  fn_R001694_9413_0_2(sec_r001694_0_1, pub_r001694_1_1, pub_r001694_2_1, sec_r001694_0_2, pub_r001694_1_2, pub_r001694_2_2);
  int helper_flow_1_1 = fn_R001694_9413_1(sec_r001694_1_1, pub_r001694_2_1, pub_r001694_3_1, pub_r001694_4_1);
  int helper_flow_1_2 = fn_R001694_9413_1(sec_r001694_1_2, pub_r001694_2_2, pub_r001694_3_2, pub_r001694_4_2);
  fn_R001694_9413_1_2(sec_r001694_1_1, pub_r001694_2_1, pub_r001694_3_1, pub_r001694_4_1, sec_r001694_1_2, pub_r001694_2_2, pub_r001694_3_2, pub_r001694_4_2);
  int helper_flow_2_1 = fn_R001694_9413_2(sec_r001694_2_1, pub_r001694_3_1, pub_r001694_4_1);
  int helper_flow_2_2 = fn_R001694_9413_2(sec_r001694_2_2, pub_r001694_3_2, pub_r001694_4_2);
  fn_R001694_9413_2_2(sec_r001694_2_1, pub_r001694_3_1, pub_r001694_4_1, sec_r001694_2_2, pub_r001694_3_2, pub_r001694_4_2);
  int helper_flow_3_1 = fn_R001694_9413_3(sec_r001694_3_1, pub_r001694_4_1);
  int helper_flow_3_2 = fn_R001694_9413_3(sec_r001694_3_2, pub_r001694_4_2);
  fn_R001694_9413_3_2(sec_r001694_3_1, pub_r001694_4_1, sec_r001694_3_2, pub_r001694_4_2);
  int helper_flow_4_1 = fn_R001694_9413_4(sec_r001694_4_1, pub_r001694_5_1);
  int helper_flow_4_2 = fn_R001694_9413_4(sec_r001694_4_2, pub_r001694_5_2);
  fn_R001694_9413_4_2(sec_r001694_4_1, pub_r001694_5_1, sec_r001694_4_2, pub_r001694_5_2);
  int helper_flow_5_1 = fn_R001694_9413_5(sec_r001694_5_1, pub_r001694_6_1, pub_r001694_7_1, pub_r001694_8_1, pub_r001694_9_1);
  int helper_flow_5_2 = fn_R001694_9413_5(sec_r001694_5_2, pub_r001694_6_2, pub_r001694_7_2, pub_r001694_8_2, pub_r001694_9_2);
  fn_R001694_9413_5_2(sec_r001694_5_1, pub_r001694_6_1, pub_r001694_7_1, pub_r001694_8_1, pub_r001694_9_1, sec_r001694_5_2, pub_r001694_6_2, pub_r001694_7_2, pub_r001694_8_2, pub_r001694_9_2);
  int helper_flow_6_1 = fn_R001694_9413_6(sec_r001694_6_1, sec_r001694_7_1, pub_r001694_8_1);
  int helper_flow_6_2 = fn_R001694_9413_6(sec_r001694_6_2, sec_r001694_7_2, pub_r001694_8_2);
  fn_R001694_9413_6_2(sec_r001694_6_1, sec_r001694_7_1, pub_r001694_8_1, sec_r001694_6_2, sec_r001694_7_2, pub_r001694_8_2);
  int stage_v_0_1 = ((pub_r001694_4_1 * 2) + 6) & 63;
  int stage_v_0_2 = ((pub_r001694_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001694_2_1 * 2) + 15) & 63;
  int stage_v_1_2 = ((pub_r001694_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001694_11_1 * 2) + 19) & 63;
  int stage_v_2_2 = ((pub_r001694_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((helper_flow_2_1 * 3) + pub_r001694_13_1) + 11) & 127;
  int stage_v_3_2 = (((helper_flow_2_2 * 3) + pub_r001694_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = (((sec_r001694_2_1 * 3) + pub_r001694_8_1) + 41) & 127;
  int stage_v_4_2 = (((sec_r001694_2_2 * 3) + pub_r001694_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = (((sec_r001694_10_1 * 3) + pub_r001694_2_1) + 26) & 127;
  int stage_v_5_2 = (((sec_r001694_10_2 * 3) + pub_r001694_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = (((sec_r001694_14_1 * 3) + pub_r001694_7_1) + 41) & 127;
  int stage_v_6_2 = (((sec_r001694_14_2 * 3) + pub_r001694_7_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = ((pub_r001694_5_1 * 2) + 34) & 63;
  int stage_v_7_2 = ((pub_r001694_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001694_8_1 * 3) + pub_r001694_16_1) + 29) & 127;
  int stage_v_8_2 = (((sec_r001694_8_2 * 3) + pub_r001694_16_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = ((pub_r001694_9_1 * 2) + 9) & 63;
  int stage_v_9_2 = ((pub_r001694_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((sec_r001694_17_1 * 3) + pub_r001694_7_1) + 36) & 127;
  int stage_v_10_2 = (((sec_r001694_17_2 * 3) + pub_r001694_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = (((sec_r001694_10_1 * 3) + pub_r001694_14_1) + 20) & 127;
  int stage_v_11_2 = (((sec_r001694_10_2 * 3) + pub_r001694_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = (((sec_r001694_12_1 * 3) + pub_r001694_1_1) + 32) & 127;
  int stage_v_12_2 = (((sec_r001694_12_2 * 3) + pub_r001694_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = (((sec_r001694_19_1 * 3) + pub_r001694_7_1) + 18) & 127;
  int stage_v_13_2 = (((sec_r001694_19_2 * 3) + pub_r001694_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = (((helper_flow_6_1 * 3) + pub_r001694_1_1) + 30) & 127;
  int stage_v_14_2 = (((helper_flow_6_2 * 3) + pub_r001694_1_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((sec_r001694_1_1 * 3) + pub_r001694_2_1) + 4) & 127;
  int stage_v_15_2 = (((sec_r001694_1_2 * 3) + pub_r001694_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = ((pub_r001694_11_1 * 2) + 34) & 63;
  int stage_v_16_2 = ((pub_r001694_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((sec_r001694_17_1 * 3) + pub_r001694_17_1) + 23) & 127;
  int stage_v_17_2 = (((sec_r001694_17_2 * 3) + pub_r001694_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = ((pub_r001694_5_1 * 2) + 35) & 63;
  int stage_v_18_2 = ((pub_r001694_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001694_5_1 * 2) + 48) & 63;
  int stage_v_19_2 = ((pub_r001694_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (((sec_r001694_2_1 * 3) + pub_r001694_10_1) + 32) & 127;
  int stage_v_20_2 = (((sec_r001694_2_2 * 3) + pub_r001694_10_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = (((helper_flow_0_1 * 3) + pub_r001694_2_1) + 15) & 127;
  int stage_v_21_2 = (((helper_flow_0_2 * 3) + pub_r001694_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = (((sec_r001694_12_1 * 3) + pub_r001694_17_1) + 40) & 127;
  int stage_v_22_2 = (((sec_r001694_12_2 * 3) + pub_r001694_17_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = ((pub_r001694_6_1 * 2) + 33) & 63;
  int stage_v_23_2 = ((pub_r001694_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001694_12_1 * 2) + 45) & 63;
  int stage_v_24_2 = ((pub_r001694_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (((sec_r001694_6_1 * 3) + pub_r001694_13_1) + 25) & 127;
  int stage_v_25_2 = (((sec_r001694_6_2 * 3) + pub_r001694_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = ((pub_r001694_6_1 * 2) + 23) & 63;
  int stage_v_26_2 = ((pub_r001694_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001694_12_1 * 2) + 46) & 63;
  int stage_v_27_2 = ((pub_r001694_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001694_1_1 * 2) + 41) & 63;
  int stage_v_28_2 = ((pub_r001694_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001694_6_1 * 2) + 41) & 63;
  int stage_v_29_2 = ((pub_r001694_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((sec_r001694_6_1 * 3) + pub_r001694_4_1) + 43) & 127;
  int stage_v_30_2 = (((sec_r001694_6_2 * 3) + pub_r001694_4_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = (((stage_v_6_1 * 3) + pub_r001694_16_1) + 31) & 127;
  int stage_v_31_2 = (((stage_v_6_2 * 3) + pub_r001694_16_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = (((sec_r001694_7_1 * 3) + pub_r001694_13_1) + 10) & 127;
  int stage_v_32_2 = (((sec_r001694_7_2 * 3) + pub_r001694_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = ((pub_r001694_0_1 * 2) + 16) & 63;
  int stage_v_33_2 = ((pub_r001694_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001694_3_1 * 2) + 18) & 63;
  int stage_v_34_2 = ((pub_r001694_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (((stage_v_14_1 * 3) + pub_r001694_3_1) + 38) & 127;
  int stage_v_35_2 = (((stage_v_14_2 * 3) + pub_r001694_3_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = (((stage_v_21_1 * 3) + pub_r001694_0_1) + 17) & 127;
  int stage_v_36_2 = (((stage_v_21_2 * 3) + pub_r001694_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = (((sec_r001694_18_1 * 3) + pub_r001694_6_1) + 12) & 127;
  int stage_v_37_2 = (((sec_r001694_18_2 * 3) + pub_r001694_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = ((pub_r001694_17_1 * 2) + 49) & 63;
  int stage_v_38_2 = ((pub_r001694_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001694_11_1 * 2) + 31) & 63;
  int stage_v_39_2 = ((pub_r001694_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001694_2_1 * 2) + 32) & 63;
  int stage_v_40_2 = ((pub_r001694_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((sec_r001694_13_1 * 3) + pub_r001694_18_1) + 31) & 127;
  int stage_v_41_2 = (((sec_r001694_13_2 * 3) + pub_r001694_18_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = ((pub_r001694_11_1 * 2) + 28) & 63;
  int stage_v_42_2 = ((pub_r001694_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((sec_r001694_6_1 * 3) + pub_r001694_15_1) + 34) & 127;
  int stage_v_43_2 = (((sec_r001694_6_2 * 3) + pub_r001694_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = (((stage_v_17_1 * 3) + pub_r001694_13_1) + 39) & 127;
  int stage_v_44_2 = (((stage_v_17_2 * 3) + pub_r001694_13_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = ((pub_r001694_15_1 * 2) + 31) & 63;
  int stage_v_45_2 = ((pub_r001694_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((sec_r001694_6_1 * 3) + pub_r001694_1_1) + 26) & 127;
  int stage_v_46_2 = (((sec_r001694_6_2 * 3) + pub_r001694_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001694_4_1 * 2) + 37) & 63;
  int stage_v_47_2 = ((pub_r001694_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (((sec_r001694_8_1 * 3) + pub_r001694_3_1) + 45) & 127;
  int stage_v_48_2 = (((sec_r001694_8_2 * 3) + pub_r001694_3_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = ((pub_r001694_1_1 * 2) + 14) & 63;
  int stage_v_49_2 = ((pub_r001694_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (((helper_flow_0_1 * 3) + pub_r001694_5_1) + 14) & 127;
  int stage_v_50_2 = (((helper_flow_0_2 * 3) + pub_r001694_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = (((stage_v_21_1 * 3) + pub_r001694_6_1) + 32) & 127;
  int stage_v_51_2 = (((stage_v_21_2 * 3) + pub_r001694_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = (((stage_v_31_1 * 3) + pub_r001694_7_1) + 14) & 127;
  int stage_v_52_2 = (((stage_v_31_2 * 3) + pub_r001694_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = ((pub_r001694_1_1 * 2) + 22) & 63;
  int stage_v_53_2 = ((pub_r001694_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001694_8_1 * 2) + 28) & 63;
  int stage_v_54_2 = ((pub_r001694_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001694_6_1 * 2) + 50) & 63;
  int stage_v_55_2 = ((pub_r001694_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (((sec_r001694_13_1 * 3) + pub_r001694_5_1) + 38) & 127;
  int stage_v_56_2 = (((sec_r001694_13_2 * 3) + pub_r001694_5_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = (((sec_r001694_13_1 * 3) + pub_r001694_4_1) + 12) & 127;
  int stage_v_57_2 = (((sec_r001694_13_2 * 3) + pub_r001694_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((sec_r001694_6_1 * 3) + pub_r001694_1_1) + 42) & 127;
  int stage_v_58_2 = (((sec_r001694_6_2 * 3) + pub_r001694_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = (((stage_v_22_1 * 3) + pub_r001694_11_1) + 27) & 127;
  int stage_v_59_2 = (((stage_v_22_2 * 3) + pub_r001694_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = (((sec_r001694_7_1 * 3) + pub_r001694_8_1) + 20) & 127;
  int stage_v_60_2 = (((sec_r001694_7_2 * 3) + pub_r001694_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = ((pub_r001694_9_1 * 2) + 28) & 63;
  int stage_v_61_2 = ((pub_r001694_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = (((stage_v_10_1 * 3) + pub_r001694_9_1) + 39) & 127;
  int stage_v_62_2 = (((stage_v_10_2 * 3) + pub_r001694_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = ((pub_r001694_18_1 * 2) + 50) & 63;
  int stage_v_63_2 = ((pub_r001694_18_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (((stage_v_11_1 * 3) + pub_r001694_3_1) + 17) & 127;
  int stage_v_64_2 = (((stage_v_11_2 * 3) + pub_r001694_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = (((sec_r001694_16_1 * 3) + pub_r001694_5_1) + 6) & 127;
  int stage_v_65_2 = (((sec_r001694_16_2 * 3) + pub_r001694_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = (((sec_r001694_19_1 * 3) + pub_r001694_9_1) + 32) & 127;
  int stage_v_66_2 = (((sec_r001694_19_2 * 3) + pub_r001694_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = ((pub_r001694_9_1 * 2) + 35) & 63;
  int stage_v_67_2 = ((pub_r001694_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (((stage_v_56_1 * 3) + pub_r001694_4_1) + 18) & 127;
  int stage_v_68_2 = (((stage_v_56_2 * 3) + pub_r001694_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = ((pub_r001694_6_1 * 2) + 31) & 63;
  int stage_v_69_2 = ((pub_r001694_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((sec_r001694_14_1 * 3) + pub_r001694_10_1) + 7) & 127;
  int stage_v_70_2 = (((sec_r001694_14_2 * 3) + pub_r001694_10_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = (((sec_r001694_6_1 * 3) + pub_r001694_5_1) + 25) & 127;
  int stage_v_71_2 = (((sec_r001694_6_2 * 3) + pub_r001694_5_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = ((pub_r001694_15_1 * 2) + 16) & 63;
  int stage_v_72_2 = ((pub_r001694_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001694_8_1 * 2) + 19) & 63;
  int stage_v_73_2 = ((pub_r001694_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001694_4_1 * 2) + 40) & 63;
  int stage_v_74_2 = ((pub_r001694_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001694_13_1 * 2) + 22) & 63;
  int stage_v_75_2 = ((pub_r001694_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001694_4_1 * 2) + 10) & 63;
  int stage_v_76_2 = ((pub_r001694_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001694_12_1 * 2) + 11) & 63;
  int stage_v_77_2 = ((pub_r001694_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001694_2_1 * 2) + 41) & 63;
  int stage_v_78_2 = ((pub_r001694_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001694_11_1 * 2) + 44) & 63;
  int stage_v_79_2 = ((pub_r001694_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001694_4_1 * 2) + 34) & 63;
  int stage_v_80_2 = ((pub_r001694_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((stage_v_21_1 * 3) + pub_r001694_0_1) + 30) & 127;
  int stage_v_81_2 = (((stage_v_21_2 * 3) + pub_r001694_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = (((sec_r001694_13_1 * 3) + pub_r001694_8_1) + 33) & 127;
  int stage_v_82_2 = (((sec_r001694_13_2 * 3) + pub_r001694_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = ((pub_r001694_5_1 * 2) + 44) & 63;
  int stage_v_83_2 = ((pub_r001694_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((stage_v_58_1 * 3) + pub_r001694_4_1) + 20) & 127;
  int stage_v_84_2 = (((stage_v_58_2 * 3) + pub_r001694_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = ((pub_r001694_14_1 * 2) + 22) & 63;
  int stage_v_85_2 = ((pub_r001694_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001694_13_1 * 2) + 9) & 63;
  int stage_v_86_2 = ((pub_r001694_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001694_1_1 * 2) + 12) & 63;
  int stage_v_87_2 = ((pub_r001694_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((sec_r001694_11_1 * 3) + pub_r001694_6_1) + 16) & 127;
  int stage_v_88_2 = (((sec_r001694_11_2 * 3) + pub_r001694_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = (((stage_v_51_1 * 3) + pub_r001694_1_1) + 36) & 127;
  int stage_v_89_2 = (((stage_v_51_2 * 3) + pub_r001694_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((sec_r001694_19_1 * 3) + pub_r001694_2_1) + 20) & 127;
  int stage_v_90_2 = (((sec_r001694_19_2 * 3) + pub_r001694_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = (((sec_r001694_11_1 * 3) + pub_r001694_11_1) + 33) & 127;
  int stage_v_91_2 = (((sec_r001694_11_2 * 3) + pub_r001694_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = (((stage_v_65_1 * 3) + pub_r001694_11_1) + 22) & 127;
  int stage_v_92_2 = (((stage_v_65_2 * 3) + pub_r001694_11_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = ((pub_r001694_1_1 * 2) + 17) & 63;
  int stage_v_93_2 = ((pub_r001694_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((stage_v_14_1 * 3) + pub_r001694_1_1) + 9) & 127;
  int stage_v_94_2 = (((stage_v_14_2 * 3) + pub_r001694_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = (((stage_v_89_1 * 3) + pub_r001694_18_1) + 42) & 127;
  int stage_v_95_2 = (((stage_v_89_2 * 3) + pub_r001694_18_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = ((pub_r001694_18_1 * 2) + 35) & 63;
  int stage_v_96_2 = ((pub_r001694_18_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_6_1 * 3) + pub_r001694_16_1) + 45) & 127;
  int stage_v_97_2 = (((stage_v_6_2 * 3) + pub_r001694_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = (((stage_v_92_1 * 3) + pub_r001694_1_1) + 44) & 127;
  int stage_v_98_2 = (((stage_v_92_2 * 3) + pub_r001694_1_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = (((stage_v_11_1 * 3) + pub_r001694_12_1) + 22) & 127;
  int stage_v_99_2 = (((stage_v_11_2 * 3) + pub_r001694_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = ((pub_r001694_12_1 * 2) + 34) & 63;
  int stage_v_100_2 = ((pub_r001694_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_17_1 * 3) + pub_r001694_14_1) + 39) & 127;
  int stage_v_101_2 = (((stage_v_17_2 * 3) + pub_r001694_14_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = (((stage_v_60_1 * 3) + pub_r001694_6_1) + 12) & 127;
  int stage_v_102_2 = (((stage_v_60_2 * 3) + pub_r001694_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = (((stage_v_48_1 * 3) + pub_r001694_0_1) + 25) & 127;
  int stage_v_103_2 = (((stage_v_48_2 * 3) + pub_r001694_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = ((pub_r001694_18_1 * 2) + 12) & 63;
  int stage_v_104_2 = ((pub_r001694_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001694_9_1 * 2) + 5) & 63;
  int stage_v_105_2 = ((pub_r001694_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001694_2_1 * 2) + 8) & 63;
  int stage_v_106_2 = ((pub_r001694_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((helper_flow_3_1 * 3) + pub_r001694_9_1) + 22) & 127;
  int stage_v_107_2 = (((helper_flow_3_2 * 3) + pub_r001694_9_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = ((pub_r001694_1_1 * 2) + 38) & 63;
  int stage_v_108_2 = ((pub_r001694_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001694_13_1 * 2) + 5) & 63;
  int stage_v_109_2 = ((pub_r001694_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((stage_v_6_1 * 3) + pub_r001694_11_1) + 41) & 127;
  int stage_v_110_2 = (((stage_v_6_2 * 3) + pub_r001694_11_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = ((pub_r001694_2_1 * 2) + 21) & 63;
  int stage_v_111_2 = ((pub_r001694_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((stage_v_102_1 * 3) + pub_r001694_17_1) + 40) & 127;
  int stage_v_112_2 = (((stage_v_102_2 * 3) + pub_r001694_17_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = (((sec_r001694_10_1 * 3) + pub_r001694_1_1) + 10) & 127;
  int stage_v_113_2 = (((sec_r001694_10_2 * 3) + pub_r001694_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = (((stage_v_58_1 * 3) + pub_r001694_3_1) + 33) & 127;
  int stage_v_114_2 = (((stage_v_58_2 * 3) + pub_r001694_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = (((stage_v_62_1 * 3) + pub_r001694_0_1) + 12) & 127;
  int stage_v_115_2 = (((stage_v_62_2 * 3) + pub_r001694_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = ((pub_r001694_2_1 * 2) + 47) & 63;
  int stage_v_116_2 = ((pub_r001694_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((stage_v_50_1 * 3) + pub_r001694_10_1) + 9) & 127;
  int stage_v_117_2 = (((stage_v_50_2 * 3) + pub_r001694_10_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = ((pub_r001694_11_1 * 2) + 49) & 63;
  int stage_v_118_2 = ((pub_r001694_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001694_17_1 * 2) + 9) & 63;
  int stage_v_119_2 = ((pub_r001694_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((stage_v_5_1 * 3) + pub_r001694_14_1) + 4) & 127;
  int stage_v_120_2 = (((stage_v_5_2 * 3) + pub_r001694_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = (((stage_v_15_1 * 3) + pub_r001694_8_1) + 25) & 127;
  int stage_v_121_2 = (((stage_v_15_2 * 3) + pub_r001694_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = (((stage_v_35_1 * 3) + pub_r001694_13_1) + 12) & 127;
  int stage_v_122_2 = (((stage_v_35_2 * 3) + pub_r001694_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = ((pub_r001694_12_1 * 2) + 35) & 63;
  int stage_v_123_2 = ((pub_r001694_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001694_17_1 * 2) + 10) & 63;
  int stage_v_124_2 = ((pub_r001694_17_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001694_18_1 * 2) + 30) & 63;
  int stage_v_125_2 = ((pub_r001694_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((stage_v_70_1 * 3) + pub_r001694_17_1) + 25) & 127;
  int stage_v_126_2 = (((stage_v_70_2 * 3) + pub_r001694_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = ((pub_r001694_12_1 * 2) + 19) & 63;
  int stage_v_127_2 = ((pub_r001694_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001694_16_1 * 2) + 17) & 63;
  int stage_v_128_2 = ((pub_r001694_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((helper_flow_1_1 * 3) + pub_r001694_9_1) + 28) & 127;
  int stage_v_129_2 = (((helper_flow_1_2 * 3) + pub_r001694_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = ((pub_r001694_2_1 * 2) + 38) & 63;
  int stage_v_130_2 = ((pub_r001694_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001694_7_1 * 2) + 37) & 63;
  int stage_v_131_2 = ((pub_r001694_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001694_5_1 * 2) + 42) & 63;
  int stage_v_132_2 = ((pub_r001694_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((sec_r001694_19_1 * 3) + pub_r001694_4_1) + 8) & 127;
  int stage_v_133_2 = (((sec_r001694_19_2 * 3) + pub_r001694_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001694_10_1 * 2) + 27) & 63;
  int stage_v_134_2 = ((pub_r001694_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001694_13_1 * 2) + 11) & 63;
  int stage_v_135_2 = ((pub_r001694_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001694_15_1 * 2) + 23) & 63;
  int stage_v_136_2 = ((pub_r001694_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (((stage_v_81_1 * 3) + pub_r001694_7_1) + 29) & 127;
  int stage_v_137_2 = (((stage_v_81_2 * 3) + pub_r001694_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = ((pub_r001694_15_1 * 2) + 50) & 63;
  int stage_v_138_2 = ((pub_r001694_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((stage_v_94_1 * 3) + pub_r001694_0_1) + 7) & 127;
  int stage_v_139_2 = (((stage_v_94_2 * 3) + pub_r001694_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = (((stage_v_36_1 * 3) + pub_r001694_4_1) + 39) & 127;
  int stage_v_140_2 = (((stage_v_36_2 * 3) + pub_r001694_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = ((pub_r001694_10_1 * 2) + 44) & 63;
  int stage_v_141_2 = ((pub_r001694_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((stage_v_71_1 * 3) + pub_r001694_4_1) + 18) & 127;
  int stage_v_142_2 = (((stage_v_71_2 * 3) + pub_r001694_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = ((pub_r001694_0_1 * 2) + 28) & 63;
  int stage_v_143_2 = ((pub_r001694_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (((stage_v_103_1 * 3) + pub_r001694_8_1) + 30) & 127;
  int stage_v_144_2 = (((stage_v_103_2 * 3) + pub_r001694_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((stage_v_8_1 * 3) + pub_r001694_17_1) + 39) & 127;
  int stage_v_145_2 = (((stage_v_8_2 * 3) + pub_r001694_17_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001694_11_1 * 2) + 13) & 63;
  int stage_v_146_2 = ((pub_r001694_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((stage_v_137_1 * 3) + pub_r001694_3_1) + 30) & 127;
  int stage_v_147_2 = (((stage_v_137_2 * 3) + pub_r001694_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = ((pub_r001694_7_1 * 2) + 37) & 63;
  int stage_v_148_2 = ((pub_r001694_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (((sec_r001694_13_1 * 3) + pub_r001694_10_1) + 17) & 127;
  int stage_v_149_2 = (((sec_r001694_13_2 * 3) + pub_r001694_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = ((pub_r001694_11_1 * 2) + 47) & 63;
  int stage_v_150_2 = ((pub_r001694_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = (((helper_flow_3_1 * 3) + pub_r001694_16_1) + 26) & 127;
  int stage_v_151_2 = (((helper_flow_3_2 * 3) + pub_r001694_16_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = ((pub_r001694_14_1 * 2) + 28) & 63;
  int stage_v_152_2 = ((pub_r001694_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001694_13_1 * 2) + 17) & 63;
  int stage_v_153_2 = ((pub_r001694_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((stage_v_92_1 * 3) + pub_r001694_4_1) + 42) & 127;
  int stage_v_154_2 = (((stage_v_92_2 * 3) + pub_r001694_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = ((pub_r001694_11_1 * 2) + 26) & 63;
  int stage_v_155_2 = ((pub_r001694_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((sec_r001694_15_1 * 3) + pub_r001694_18_1) + 43) & 127;
  int stage_v_156_2 = (((sec_r001694_15_2 * 3) + pub_r001694_18_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((stage_v_64_1 * 3) + pub_r001694_15_1) + 32) & 127;
  int stage_v_157_2 = (((stage_v_64_2 * 3) + pub_r001694_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = (((stage_v_36_1 * 3) + pub_r001694_15_1) + 23) & 127;
  int stage_v_158_2 = (((stage_v_36_2 * 3) + pub_r001694_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = ((pub_r001694_10_1 * 2) + 16) & 63;
  int stage_v_159_2 = ((pub_r001694_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001694_8_1 * 2) + 28) & 63;
  int stage_v_160_2 = ((pub_r001694_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001694_5_1 * 2) + 32) & 63;
  int stage_v_161_2 = ((pub_r001694_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001694_0_1 * 2) + 8) & 63;
  int stage_v_162_2 = ((pub_r001694_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((stage_v_102_1 * 3) + pub_r001694_11_1) + 33) & 127;
  int stage_v_163_2 = (((stage_v_102_2 * 3) + pub_r001694_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = (((helper_flow_6_1 * 3) + pub_r001694_14_1) + 35) & 127;
  int stage_v_164_2 = (((helper_flow_6_2 * 3) + pub_r001694_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = (((stage_v_46_1 * 3) + pub_r001694_16_1) + 33) & 127;
  int stage_v_165_2 = (((stage_v_46_2 * 3) + pub_r001694_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = ((pub_r001694_12_1 * 2) + 23) & 63;
  int stage_v_166_2 = ((pub_r001694_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_113_1 * 3) + pub_r001694_11_1) + 4) & 127;
  int stage_v_167_2 = (((stage_v_113_2 * 3) + pub_r001694_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = (((stage_v_8_1 * 3) + pub_r001694_5_1) + 16) & 127;
  int stage_v_168_2 = (((stage_v_8_2 * 3) + pub_r001694_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = ((pub_r001694_14_1 * 2) + 10) & 63;
  int stage_v_169_2 = ((pub_r001694_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((stage_v_15_1 * 3) + pub_r001694_8_1) + 38) & 127;
  int stage_v_170_2 = (((stage_v_15_2 * 3) + pub_r001694_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = (((stage_v_31_1 * 3) + pub_r001694_11_1) + 23) & 127;
  int stage_v_171_2 = (((stage_v_31_2 * 3) + pub_r001694_11_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = (((stage_v_37_1 * 3) + pub_r001694_14_1) + 21) & 127;
  int stage_v_172_2 = (((stage_v_37_2 * 3) + pub_r001694_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = (((stage_v_71_1 * 3) + pub_r001694_8_1) + 14) & 127;
  int stage_v_173_2 = (((stage_v_71_2 * 3) + pub_r001694_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = (((stage_v_31_1 * 3) + pub_r001694_4_1) + 18) & 127;
  int stage_v_174_2 = (((stage_v_31_2 * 3) + pub_r001694_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = (((stage_v_43_1 * 3) + pub_r001694_13_1) + 14) & 127;
  int stage_v_175_2 = (((stage_v_43_2 * 3) + pub_r001694_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = ((pub_r001694_8_1 * 2) + 28) & 63;
  int stage_v_176_2 = ((pub_r001694_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (((stage_v_154_1 * 3) + pub_r001694_18_1) + 41) & 127;
  int stage_v_177_2 = (((stage_v_154_2 * 3) + pub_r001694_18_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = ((pub_r001694_16_1 * 2) + 45) & 63;
  int stage_v_178_2 = ((pub_r001694_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (((stage_v_113_1 * 3) + pub_r001694_14_1) + 15) & 127;
  int stage_v_179_2 = (((stage_v_113_2 * 3) + pub_r001694_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = ((pub_r001694_16_1 * 2) + 44) & 63;
  int stage_v_180_2 = ((pub_r001694_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((stage_v_101_1 * 3) + pub_r001694_18_1) + 6) & 127;
  int stage_v_181_2 = (((stage_v_101_2 * 3) + pub_r001694_18_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = ((pub_r001694_6_1 * 2) + 41) & 63;
  int stage_v_182_2 = ((pub_r001694_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_89_1 * 3) + pub_r001694_1_1) + 43) & 127;
  int stage_v_183_2 = (((stage_v_89_2 * 3) + pub_r001694_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((stage_v_149_1 * 3) + pub_r001694_1_1) + 42) & 127;
  int stage_v_184_2 = (((stage_v_149_2 * 3) + pub_r001694_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = (((stage_v_99_1 * 3) + pub_r001694_16_1) + 16) & 127;
  int stage_v_185_2 = (((stage_v_99_2 * 3) + pub_r001694_16_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = (((stage_v_30_1 * 3) + pub_r001694_16_1) + 38) & 127;
  int stage_v_186_2 = (((stage_v_30_2 * 3) + pub_r001694_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = (((stage_v_30_1 * 3) + pub_r001694_9_1) + 10) & 127;
  int stage_v_187_2 = (((stage_v_30_2 * 3) + pub_r001694_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = (((stage_v_11_1 * 3) + pub_r001694_7_1) + 31) & 127;
  int stage_v_188_2 = (((stage_v_11_2 * 3) + pub_r001694_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = ((pub_r001694_16_1 * 2) + 26) & 63;
  int stage_v_189_2 = ((pub_r001694_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((stage_v_64_1 * 3) + pub_r001694_1_1) + 39) & 127;
  int stage_v_190_2 = (((stage_v_64_2 * 3) + pub_r001694_1_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = (((stage_v_3_1 * 3) + pub_r001694_10_1) + 4) & 127;
  int stage_v_191_2 = (((stage_v_3_2 * 3) + pub_r001694_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = (((helper_flow_5_1 * 3) + pub_r001694_9_1) + 13) & 127;
  int stage_v_192_2 = (((helper_flow_5_2 * 3) + pub_r001694_9_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = ((pub_r001694_5_1 * 2) + 22) & 63;
  int stage_v_193_2 = ((pub_r001694_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (((stage_v_98_1 * 3) + pub_r001694_2_1) + 45) & 127;
  int stage_v_194_2 = (((stage_v_98_2 * 3) + pub_r001694_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = (((stage_v_145_1 * 3) + pub_r001694_11_1) + 39) & 127;
  int stage_v_195_2 = (((stage_v_145_2 * 3) + pub_r001694_11_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = ((pub_r001694_0_1 * 2) + 50) & 63;
  int stage_v_196_2 = ((pub_r001694_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((helper_flow_4_1 * 3) + pub_r001694_13_1) + 9) & 127;
  int stage_v_197_2 = (((helper_flow_4_2 * 3) + pub_r001694_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = (((sec_r001694_16_1 * 3) + pub_r001694_14_1) + 5) & 127;
  int stage_v_198_2 = (((sec_r001694_16_2 * 3) + pub_r001694_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = (((sec_r001694_16_1 * 3) + pub_r001694_10_1) + 10) & 127;
  int stage_v_199_2 = (((sec_r001694_16_2 * 3) + pub_r001694_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = (((stage_v_142_1 * 3) + pub_r001694_12_1) + 17) & 127;
  int stage_v_200_2 = (((stage_v_142_2 * 3) + pub_r001694_12_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = ((pub_r001694_4_1 * 2) + 26) & 63;
  int stage_v_201_2 = ((pub_r001694_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_129_1 * 3) + pub_r001694_11_1) + 11) & 127;
  int stage_v_202_2 = (((stage_v_129_2 * 3) + pub_r001694_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = (((stage_v_126_1 * 3) + pub_r001694_11_1) + 15) & 127;
  int stage_v_203_2 = (((stage_v_126_2 * 3) + pub_r001694_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = ((pub_r001694_14_1 * 2) + 13) & 63;
  int stage_v_204_2 = ((pub_r001694_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001694_4_1 * 2) + 13) & 63;
  int stage_v_205_2 = ((pub_r001694_4_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = (((stage_v_197_1 * 3) + pub_r001694_15_1) + 17) & 127;
  int stage_v_206_2 = (((stage_v_197_2 * 3) + pub_r001694_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = (((stage_v_43_1 * 3) + pub_r001694_4_1) + 34) & 127;
  int stage_v_207_2 = (((stage_v_43_2 * 3) + pub_r001694_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = ((pub_r001694_10_1 * 2) + 29) & 63;
  int stage_v_208_2 = ((pub_r001694_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001694_14_1 * 2) + 47) & 63;
  int stage_v_209_2 = ((pub_r001694_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((stage_v_15_1 * 3) + pub_r001694_4_1) + 39) & 127;
  int stage_v_210_2 = (((stage_v_15_2 * 3) + pub_r001694_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = ((pub_r001694_15_1 * 2) + 21) & 63;
  int stage_v_211_2 = ((pub_r001694_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = (((stage_v_170_1 * 3) + pub_r001694_4_1) + 30) & 127;
  int stage_v_212_2 = (((stage_v_170_2 * 3) + pub_r001694_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = ((pub_r001694_1_1 * 2) + 47) & 63;
  int stage_v_213_2 = ((pub_r001694_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001694_10_1 * 2) + 22) & 63;
  int stage_v_214_2 = ((pub_r001694_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001694_18_1 * 2) + 42) & 63;
  int stage_v_215_2 = ((pub_r001694_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001694_16_1 * 2) + 28) & 63;
  int stage_v_216_2 = ((pub_r001694_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((stage_v_121_1 * 3) + pub_r001694_9_1) + 21) & 127;
  int stage_v_217_2 = (((stage_v_121_2 * 3) + pub_r001694_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = ((pub_r001694_6_1 * 2) + 12) & 63;
  int stage_v_218_2 = ((pub_r001694_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001694_7_1 * 2) + 37) & 63;
  int stage_v_219_2 = ((pub_r001694_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001694_16_1 * 2) + 44) & 63;
  int stage_v_220_2 = ((pub_r001694_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001694_8_1 * 2) + 42) & 63;
  int stage_v_221_2 = ((pub_r001694_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = (((stage_v_88_1 * 3) + pub_r001694_17_1) + 36) & 127;
  int stage_v_222_2 = (((stage_v_88_2 * 3) + pub_r001694_17_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001694_14_1 * 2) + 43) & 63;
  int stage_v_223_2 = ((pub_r001694_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001694_10_1 * 2) + 9) & 63;
  int stage_v_224_2 = ((pub_r001694_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((sec_r001694_12_1 * 3) + pub_r001694_5_1) + 42) & 127;
  int stage_v_225_2 = (((sec_r001694_12_2 * 3) + pub_r001694_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = ((pub_r001694_18_1 * 2) + 22) & 63;
  int stage_v_226_2 = ((pub_r001694_18_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001694_10_1 * 2) + 36) & 63;
  int stage_v_227_2 = ((pub_r001694_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001694_18_1 * 2) + 17) & 63;
  int stage_v_228_2 = ((pub_r001694_18_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_133_1 * 3) + pub_r001694_2_1) + 11) & 127;
  int stage_v_229_2 = (((stage_v_133_2 * 3) + pub_r001694_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = (((stage_v_4_1 * 3) + pub_r001694_17_1) + 20) & 127;
  int stage_v_230_2 = (((stage_v_4_2 * 3) + pub_r001694_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = (((stage_v_84_1 * 3) + pub_r001694_10_1) + 24) & 127;
  int stage_v_231_2 = (((stage_v_84_2 * 3) + pub_r001694_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = ((pub_r001694_5_1 * 2) + 34) & 63;
  int stage_v_232_2 = ((pub_r001694_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001694_14_1 * 2) + 7) & 63;
  int stage_v_233_2 = ((pub_r001694_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001694_9_1 * 2) + 13) & 63;
  int stage_v_234_2 = ((pub_r001694_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = (((sec_r001694_0_1 * 3) + pub_r001694_0_1) + 45) & 127;
  int stage_v_235_2 = (((sec_r001694_0_2 * 3) + pub_r001694_0_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = ((pub_r001694_7_1 * 2) + 14) & 63;
  int stage_v_236_2 = ((pub_r001694_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001694_7_1 * 2) + 27) & 63;
  int stage_v_237_2 = ((pub_r001694_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001694_6_1 * 2) + 42) & 63;
  int stage_v_238_2 = ((pub_r001694_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = (((stage_v_183_1 * 3) + pub_r001694_16_1) + 36) & 127;
  int stage_v_239_2 = (((stage_v_183_2 * 3) + pub_r001694_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = ((pub_r001694_6_1 * 2) + 19) & 63;
  int stage_v_240_2 = ((pub_r001694_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((pub_r001694_4_1 * 2) + 8) & 63;
  int stage_v_241_2 = ((pub_r001694_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((pub_r001694_8_1 * 2) + 43) & 63;
  int stage_v_242_2 = ((pub_r001694_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = (((stage_v_25_1 * 3) + pub_r001694_6_1) + 10) & 127;
  int stage_v_243_2 = (((stage_v_25_2 * 3) + pub_r001694_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = ((pub_r001694_14_1 * 2) + 6) & 63;
  int stage_v_244_2 = ((pub_r001694_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = (((stage_v_91_1 * 3) + pub_r001694_6_1) + 20) & 127;
  int stage_v_245_2 = (((stage_v_91_2 * 3) + pub_r001694_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001694_4_1 * 2) + 49) & 63;
  int stage_v_246_2 = ((pub_r001694_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = (((stage_v_50_1 * 3) + pub_r001694_5_1) + 5) & 127;
  int stage_v_247_2 = (((stage_v_50_2 * 3) + pub_r001694_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = (((stage_v_195_1 * 3) + pub_r001694_1_1) + 34) & 127;
  int stage_v_248_2 = (((stage_v_195_2 * 3) + pub_r001694_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((helper_flow_6_1 * 3) + pub_r001694_0_1) + 21) & 127;
  int stage_v_249_2 = (((helper_flow_6_2 * 3) + pub_r001694_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((helper_flow_0_1 * 3) + pub_r001694_2_1) + 29) & 127;
  int stage_v_250_2 = (((helper_flow_0_2 * 3) + pub_r001694_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = ((pub_r001694_9_1 * 2) + 11) & 63;
  int stage_v_251_2 = ((pub_r001694_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((pub_r001694_0_1 * 2) + 32) & 63;
  int stage_v_252_2 = ((pub_r001694_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = (((stage_v_58_1 * 3) + pub_r001694_14_1) + 19) & 127;
  int stage_v_253_2 = (((stage_v_58_2 * 3) + pub_r001694_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = (((stage_v_88_1 * 3) + pub_r001694_10_1) + 43) & 127;
  int stage_v_254_2 = (((stage_v_88_2 * 3) + pub_r001694_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = ((pub_r001694_9_1 * 2) + 29) & 63;
  int stage_v_255_2 = ((pub_r001694_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001694_5_1 * 2) + 47) & 63;
  int stage_v_256_2 = ((pub_r001694_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = (((stage_v_248_1 * 3) + pub_r001694_18_1) + 40) & 127;
  int stage_v_257_2 = (((stage_v_248_2 * 3) + pub_r001694_18_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = ((pub_r001694_7_1 * 2) + 23) & 63;
  int stage_v_258_2 = ((pub_r001694_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001694_2_1 * 2) + 44) & 63;
  int stage_v_259_2 = ((pub_r001694_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = (((stage_v_115_1 * 3) + pub_r001694_11_1) + 35) & 127;
  int stage_v_260_2 = (((stage_v_115_2 * 3) + pub_r001694_11_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = ((pub_r001694_12_1 * 2) + 7) & 63;
  int stage_v_261_2 = ((pub_r001694_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001694_15_1 * 2) + 39) & 63;
  int stage_v_262_2 = ((pub_r001694_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((stage_v_10_1 * 3) + pub_r001694_1_1) + 30) & 127;
  int stage_v_263_2 = (((stage_v_10_2 * 3) + pub_r001694_1_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = (((sec_r001694_9_1 * 3) + pub_r001694_14_1) + 40) & 127;
  int stage_v_264_2 = (((sec_r001694_9_2 * 3) + pub_r001694_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = ((pub_r001694_0_1 * 2) + 24) & 63;
  int stage_v_265_2 = ((pub_r001694_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = (((stage_v_60_1 * 3) + pub_r001694_1_1) + 6) & 127;
  int stage_v_266_2 = (((stage_v_60_2 * 3) + pub_r001694_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = (((stage_v_225_1 * 3) + pub_r001694_8_1) + 27) & 127;
  int stage_v_267_2 = (((stage_v_225_2 * 3) + pub_r001694_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = (((stage_v_30_1 * 3) + pub_r001694_2_1) + 39) & 127;
  int stage_v_268_2 = (((stage_v_30_2 * 3) + pub_r001694_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = (((stage_v_112_1 * 3) + pub_r001694_4_1) + 25) & 127;
  int stage_v_269_2 = (((stage_v_112_2 * 3) + pub_r001694_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = ((pub_r001694_11_1 * 2) + 25) & 63;
  int stage_v_270_2 = ((pub_r001694_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001694_1_1 * 2) + 6) & 63;
  int stage_v_271_2 = ((pub_r001694_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001694_12_1 * 2) + 31) & 63;
  int stage_v_272_2 = ((pub_r001694_12_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = (((stage_v_245_1 * 3) + pub_r001694_10_1) + 3) & 127;
  int stage_v_273_2 = (((stage_v_245_2 * 3) + pub_r001694_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = ((pub_r001694_7_1 * 2) + 16) & 63;
  int stage_v_274_2 = ((pub_r001694_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = (((stage_v_98_1 * 3) + pub_r001694_10_1) + 39) & 127;
  int stage_v_275_2 = (((stage_v_98_2 * 3) + pub_r001694_10_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = (((stage_v_68_1 * 3) + pub_r001694_17_1) + 27) & 127;
  int stage_v_276_2 = (((stage_v_68_2 * 3) + pub_r001694_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = (((stage_v_163_1 * 3) + pub_r001694_8_1) + 36) & 127;
  int stage_v_277_2 = (((stage_v_163_2 * 3) + pub_r001694_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = (((stage_v_172_1 * 3) + pub_r001694_11_1) + 37) & 127;
  int stage_v_278_2 = (((stage_v_172_2 * 3) + pub_r001694_11_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = ((pub_r001694_15_1 * 2) + 24) & 63;
  int stage_v_279_2 = ((pub_r001694_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = (((stage_v_217_1 * 3) + pub_r001694_14_1) + 29) & 127;
  int stage_v_280_2 = (((stage_v_217_2 * 3) + pub_r001694_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = (((stage_v_56_1 * 3) + pub_r001694_5_1) + 22) & 127;
  int stage_v_281_2 = (((stage_v_56_2 * 3) + pub_r001694_5_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = ((pub_r001694_4_1 * 2) + 18) & 63;
  int stage_v_282_2 = ((pub_r001694_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001694_16_1 * 2) + 19) & 63;
  int stage_v_283_2 = ((pub_r001694_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = (((stage_v_190_1 * 3) + pub_r001694_16_1) + 20) & 127;
  int stage_v_284_2 = (((stage_v_190_2 * 3) + pub_r001694_16_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = (((stage_v_235_1 * 3) + pub_r001694_6_1) + 14) & 127;
  int stage_v_285_2 = (((stage_v_235_2 * 3) + pub_r001694_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = (((stage_v_202_1 * 3) + pub_r001694_2_1) + 11) & 127;
  int stage_v_286_2 = (((stage_v_202_2 * 3) + pub_r001694_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = (((stage_v_190_1 * 3) + pub_r001694_11_1) + 21) & 127;
  int stage_v_287_2 = (((stage_v_190_2 * 3) + pub_r001694_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((stage_v_248_1 * 3) + pub_r001694_7_1) + 20) & 127;
  int stage_v_288_2 = (((stage_v_248_2 * 3) + pub_r001694_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = (((stage_v_68_1 * 3) + pub_r001694_16_1) + 10) & 127;
  int stage_v_289_2 = (((stage_v_68_2 * 3) + pub_r001694_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_177_1 * 3) + pub_r001694_16_1) + 41) & 127;
  int stage_v_290_2 = (((stage_v_177_2 * 3) + pub_r001694_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = ((pub_r001694_1_1 * 2) + 46) & 63;
  int stage_v_291_2 = ((pub_r001694_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = (((stage_v_84_1 * 3) + pub_r001694_17_1) + 18) & 127;
  int stage_v_292_2 = (((stage_v_84_2 * 3) + pub_r001694_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = (((stage_v_8_1 * 3) + pub_r001694_10_1) + 23) & 127;
  int stage_v_293_2 = (((stage_v_8_2 * 3) + pub_r001694_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = (((stage_v_206_1 * 3) + pub_r001694_12_1) + 16) & 127;
  int stage_v_294_2 = (((stage_v_206_2 * 3) + pub_r001694_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = ((pub_r001694_0_1 * 2) + 47) & 63;
  int stage_v_295_2 = ((pub_r001694_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((pub_r001694_2_1 * 2) + 24) & 63;
  int stage_v_296_2 = ((pub_r001694_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = (((stage_v_266_1 * 3) + pub_r001694_13_1) + 42) & 127;
  int stage_v_297_2 = (((stage_v_266_2 * 3) + pub_r001694_13_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = (((stage_v_186_1 * 3) + pub_r001694_16_1) + 27) & 127;
  int stage_v_298_2 = (((stage_v_186_2 * 3) + pub_r001694_16_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001694_7_1 * 2) + 37) & 63;
  int stage_v_299_2 = ((pub_r001694_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = (((stage_v_154_1 * 3) + pub_r001694_13_1) + 25) & 127;
  int stage_v_300_2 = (((stage_v_154_2 * 3) + pub_r001694_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = ((pub_r001694_11_1 * 2) + 30) & 63;
  int stage_v_301_2 = ((pub_r001694_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = (((stage_v_248_1 * 3) + pub_r001694_9_1) + 42) & 127;
  int stage_v_302_2 = (((stage_v_248_2 * 3) + pub_r001694_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = (((stage_v_278_1 * 3) + pub_r001694_18_1) + 23) & 127;
  int stage_v_303_2 = (((stage_v_278_2 * 3) + pub_r001694_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001694_5_1 * 2) + 42) & 63;
  int stage_v_304_2 = ((pub_r001694_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = (((stage_v_289_1 * 3) + pub_r001694_12_1) + 11) & 127;
  int stage_v_305_2 = (((stage_v_289_2 * 3) + pub_r001694_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_305_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_305_2 * 2)) & 255;
  int stage_v_306_1 = ((pub_r001694_10_1 * 2) + 50) & 63;
  int stage_v_306_2 = ((pub_r001694_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = (((stage_v_103_1 * 3) + pub_r001694_10_1) + 5) & 127;
  int stage_v_307_2 = (((stage_v_103_2 * 3) + pub_r001694_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = (((sec_r001694_19_1 * 3) + pub_r001694_17_1) + 30) & 127;
  int stage_v_308_2 = (((sec_r001694_19_2 * 3) + pub_r001694_17_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = (((stage_v_165_1 * 3) + pub_r001694_7_1) + 24) & 127;
  int stage_v_309_2 = (((stage_v_165_2 * 3) + pub_r001694_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = ((pub_r001694_11_1 * 2) + 26) & 63;
  int stage_v_310_2 = ((pub_r001694_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = (((stage_v_305_1 * 3) + pub_r001694_15_1) + 7) & 127;
  int stage_v_311_2 = (((stage_v_305_2 * 3) + pub_r001694_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = (((stage_v_198_1 * 3) + pub_r001694_15_1) + 4) & 127;
  int stage_v_312_2 = (((stage_v_198_2 * 3) + pub_r001694_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = (((stage_v_179_1 * 3) + pub_r001694_1_1) + 45) & 127;
  int stage_v_313_2 = (((stage_v_179_2 * 3) + pub_r001694_1_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = (((stage_v_202_1 * 3) + pub_r001694_16_1) + 23) & 127;
  int stage_v_314_2 = (((stage_v_202_2 * 3) + pub_r001694_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = (((stage_v_276_1 * 3) + pub_r001694_8_1) + 13) & 127;
  int stage_v_315_2 = (((stage_v_276_2 * 3) + pub_r001694_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((stage_v_168_1 * 3) + pub_r001694_14_1) + 25) & 127;
  int stage_v_316_2 = (((stage_v_168_2 * 3) + pub_r001694_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((sec_r001694_13_1 * 3) + pub_r001694_18_1) + 38) & 127;
  int stage_v_317_2 = (((sec_r001694_13_2 * 3) + pub_r001694_18_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = (((stage_v_156_1 * 3) + pub_r001694_4_1) + 44) & 127;
  int stage_v_318_2 = (((stage_v_156_2 * 3) + pub_r001694_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = (((stage_v_185_1 * 3) + pub_r001694_12_1) + 43) & 127;
  int stage_v_319_2 = (((stage_v_185_2 * 3) + pub_r001694_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = (((stage_v_36_1 * 3) + pub_r001694_11_1) + 36) & 127;
  int stage_v_320_2 = (((stage_v_36_2 * 3) + pub_r001694_11_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = (((stage_v_97_1 * 3) + pub_r001694_16_1) + 19) & 127;
  int stage_v_321_2 = (((stage_v_97_2 * 3) + pub_r001694_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = ((pub_r001694_2_1 * 2) + 9) & 63;
  int stage_v_322_2 = ((pub_r001694_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = (((stage_v_225_1 * 3) + pub_r001694_4_1) + 5) & 127;
  int stage_v_323_2 = (((stage_v_225_2 * 3) + pub_r001694_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = ((pub_r001694_5_1 * 2) + 37) & 63;
  int stage_v_324_2 = ((pub_r001694_5_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = (((stage_v_36_1 * 3) + pub_r001694_0_1) + 4) & 127;
  int stage_v_325_2 = (((stage_v_36_2 * 3) + pub_r001694_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = (((stage_v_275_1 * 3) + pub_r001694_7_1) + 19) & 127;
  int stage_v_326_2 = (((stage_v_275_2 * 3) + pub_r001694_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = (((stage_v_286_1 * 3) + pub_r001694_13_1) + 27) & 127;
  int stage_v_327_2 = (((stage_v_286_2 * 3) + pub_r001694_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = (((stage_v_174_1 * 3) + pub_r001694_16_1) + 42) & 127;
  int stage_v_328_2 = (((stage_v_174_2 * 3) + pub_r001694_16_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = ((pub_r001694_16_1 * 2) + 48) & 63;
  int stage_v_329_2 = ((pub_r001694_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = (((stage_v_278_1 * 3) + pub_r001694_5_1) + 7) & 127;
  int stage_v_330_2 = (((stage_v_278_2 * 3) + pub_r001694_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = (((stage_v_137_1 * 3) + pub_r001694_18_1) + 44) & 127;
  int stage_v_331_2 = (((stage_v_137_2 * 3) + pub_r001694_18_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = ((pub_r001694_2_1 * 2) + 40) & 63;
  int stage_v_332_2 = ((pub_r001694_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001694_10_1 * 2) + 15) & 63;
  int stage_v_333_2 = ((pub_r001694_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001694_15_1 * 2) + 46) & 63;
  int stage_v_334_2 = ((pub_r001694_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = (((stage_v_319_1 * 3) + pub_r001694_7_1) + 16) & 127;
  int stage_v_335_2 = (((stage_v_319_2 * 3) + pub_r001694_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = (((stage_v_286_1 * 3) + pub_r001694_13_1) + 18) & 127;
  int stage_v_336_2 = (((stage_v_286_2 * 3) + pub_r001694_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((stage_v_284_1 * 3) + pub_r001694_0_1) + 43) & 127;
  int stage_v_337_2 = (((stage_v_284_2 * 3) + pub_r001694_0_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = ((pub_r001694_2_1 * 2) + 17) & 63;
  int stage_v_338_2 = ((pub_r001694_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((pub_r001694_3_1 * 2) + 25) & 63;
  int stage_v_339_2 = ((pub_r001694_3_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = (((stage_v_293_1 * 3) + pub_r001694_8_1) + 24) & 127;
  int stage_v_340_2 = (((stage_v_293_2 * 3) + pub_r001694_8_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = ((pub_r001694_15_1 * 2) + 6) & 63;
  int stage_v_341_2 = ((pub_r001694_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = (((stage_v_68_1 * 3) + pub_r001694_2_1) + 35) & 127;
  int stage_v_342_2 = (((stage_v_68_2 * 3) + pub_r001694_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = (((stage_v_302_1 * 3) + pub_r001694_14_1) + 14) & 127;
  int stage_v_343_2 = (((stage_v_302_2 * 3) + pub_r001694_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = ((pub_r001694_8_1 * 2) + 7) & 63;
  int stage_v_344_2 = ((pub_r001694_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = (((stage_v_230_1 * 3) + pub_r001694_13_1) + 41) & 127;
  int stage_v_345_2 = (((stage_v_230_2 * 3) + pub_r001694_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = (((helper_flow_3_1 * 3) + pub_r001694_16_1) + 4) & 127;
  int stage_v_346_2 = (((helper_flow_3_2 * 3) + pub_r001694_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = ((pub_r001694_11_1 * 2) + 36) & 63;
  int stage_v_347_2 = ((pub_r001694_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001694_0_1 * 2) + 11) & 63;
  int stage_v_348_2 = ((pub_r001694_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((pub_r001694_17_1 * 2) + 16) & 63;
  int stage_v_349_2 = ((pub_r001694_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = (((stage_v_164_1 * 3) + pub_r001694_8_1) + 45) & 127;
  int stage_v_350_2 = (((stage_v_164_2 * 3) + pub_r001694_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((stage_v_315_1 * 3) + pub_r001694_1_1) + 7) & 127;
  int stage_v_351_2 = (((stage_v_315_2 * 3) + pub_r001694_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = (((stage_v_163_1 * 3) + pub_r001694_10_1) + 41) & 127;
  int stage_v_352_2 = (((stage_v_163_2 * 3) + pub_r001694_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = ((pub_r001694_18_1 * 2) + 18) & 63;
  int stage_v_353_2 = ((pub_r001694_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001694_6_1 * 2) + 44) & 63;
  int stage_v_354_2 = ((pub_r001694_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = (((stage_v_192_1 * 3) + pub_r001694_8_1) + 5) & 127;
  int stage_v_355_2 = (((stage_v_192_2 * 3) + pub_r001694_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_352_1 * 3) + pub_r001694_12_1) + 22) & 127;
  int stage_v_356_2 = (((stage_v_352_2 * 3) + pub_r001694_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = ((pub_r001694_14_1 * 2) + 45) & 63;
  int stage_v_357_2 = ((pub_r001694_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = (((stage_v_183_1 * 3) + pub_r001694_3_1) + 44) & 127;
  int stage_v_358_2 = (((stage_v_183_2 * 3) + pub_r001694_3_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = ((pub_r001694_8_1 * 2) + 43) & 63;
  int stage_v_359_2 = ((pub_r001694_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((pub_r001694_18_1 * 2) + 48) & 63;
  int stage_v_360_2 = ((pub_r001694_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = (((stage_v_31_1 * 3) + pub_r001694_0_1) + 21) & 127;
  int stage_v_361_2 = (((stage_v_31_2 * 3) + pub_r001694_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = (((stage_v_65_1 * 3) + pub_r001694_9_1) + 15) & 127;
  int stage_v_362_2 = (((stage_v_65_2 * 3) + pub_r001694_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = ((pub_r001694_16_1 * 2) + 46) & 63;
  int stage_v_363_2 = ((pub_r001694_16_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001694_8_1 * 2) + 16) & 63;
  int stage_v_364_2 = ((pub_r001694_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = (((stage_v_331_1 * 3) + pub_r001694_6_1) + 19) & 127;
  int stage_v_365_2 = (((stage_v_331_2 * 3) + pub_r001694_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = ((pub_r001694_8_1 * 2) + 30) & 63;
  int stage_v_366_2 = ((pub_r001694_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((pub_r001694_14_1 * 2) + 11) & 63;
  int stage_v_367_2 = ((pub_r001694_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001694_15_1 * 2) + 7) & 63;
  int stage_v_368_2 = ((pub_r001694_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = (((stage_v_335_1 * 3) + pub_r001694_12_1) + 13) & 127;
  int stage_v_369_2 = (((stage_v_335_2 * 3) + pub_r001694_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = (((stage_v_343_1 * 3) + pub_r001694_9_1) + 35) & 127;
  int stage_v_370_2 = (((stage_v_343_2 * 3) + pub_r001694_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = ((pub_r001694_7_1 * 2) + 32) & 63;
  int stage_v_371_2 = ((pub_r001694_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001694_10_1 * 2) + 24) & 63;
  int stage_v_372_2 = ((pub_r001694_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001694_11_1 * 2) + 21) & 63;
  int stage_v_373_2 = ((pub_r001694_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = (((stage_v_6_1 * 3) + pub_r001694_2_1) + 22) & 127;
  int stage_v_374_2 = (((stage_v_6_2 * 3) + pub_r001694_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_177_1 * 3) + pub_r001694_7_1) + 3) & 127;
  int stage_v_375_2 = (((stage_v_177_2 * 3) + pub_r001694_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001694_4_1 * 2) + 31) & 63;
  int stage_v_376_2 = ((pub_r001694_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = (((stage_v_98_1 * 3) + pub_r001694_17_1) + 5) & 127;
  int stage_v_377_2 = (((stage_v_98_2 * 3) + pub_r001694_17_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = ((pub_r001694_5_1 * 2) + 22) & 63;
  int stage_v_378_2 = ((pub_r001694_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = (((stage_v_269_1 * 3) + pub_r001694_3_1) + 44) & 127;
  int stage_v_379_2 = (((stage_v_269_2 * 3) + pub_r001694_3_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = (((stage_v_203_1 * 3) + pub_r001694_1_1) + 45) & 127;
  int stage_v_380_2 = (((stage_v_203_2 * 3) + pub_r001694_1_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = ((pub_r001694_12_1 * 2) + 41) & 63;
  int stage_v_381_2 = ((pub_r001694_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = ((pub_r001694_2_1 * 2) + 9) & 63;
  int stage_v_382_2 = ((pub_r001694_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = (((sec_r001694_1_1 * 3) + pub_r001694_3_1) + 27) & 127;
  int stage_v_383_2 = (((sec_r001694_1_2 * 3) + pub_r001694_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = (((stage_v_302_1 * 3) + pub_r001694_18_1) + 40) & 127;
  int stage_v_384_2 = (((stage_v_302_2 * 3) + pub_r001694_18_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = ((pub_r001694_16_1 * 2) + 20) & 63;
  int stage_v_385_2 = ((pub_r001694_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001694_6_1 * 2) + 14) & 63;
  int stage_v_386_2 = ((pub_r001694_6_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = (((stage_v_365_1 * 3) + pub_r001694_14_1) + 3) & 127;
  int stage_v_387_2 = (((stage_v_365_2 * 3) + pub_r001694_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = (((stage_v_129_1 * 3) + pub_r001694_11_1) + 34) & 127;
  int stage_v_388_2 = (((stage_v_129_2 * 3) + pub_r001694_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = (((sec_r001694_7_1 * 3) + pub_r001694_9_1) + 11) & 127;
  int stage_v_389_2 = (((sec_r001694_7_2 * 3) + pub_r001694_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = ((pub_r001694_5_1 * 2) + 49) & 63;
  int stage_v_390_2 = ((pub_r001694_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((pub_r001694_17_1 * 2) + 34) & 63;
  int stage_v_391_2 = ((pub_r001694_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001694_4_1 * 2) + 17) & 63;
  int stage_v_392_2 = ((pub_r001694_4_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = (((helper_flow_2_1 * 3) + pub_r001694_17_1) + 28) & 127;
  int stage_v_393_2 = (((helper_flow_2_2 * 3) + pub_r001694_17_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = (((stage_v_207_1 * 3) + pub_r001694_10_1) + 20) & 127;
  int stage_v_394_2 = (((stage_v_207_2 * 3) + pub_r001694_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001694_3_1 != sec_r001694_3_2);
  __CPROVER_assume(pub_r001694_11_1 == pub_r001694_11_2);
  __CPROVER_assume(sec_r001694_15_1 != sec_r001694_15_2);
  __CPROVER_assume(pub_r001694_12_1 == pub_r001694_12_2);
  __CPROVER_assume(sec_r001694_8_1 != sec_r001694_8_2);
  __CPROVER_assume(pub_r001694_0_1 == pub_r001694_0_2);
  __CPROVER_assume(pub_r001694_17_1 == pub_r001694_17_2);
  __CPROVER_assume(sec_r001694_11_1 != sec_r001694_11_2);
  __CPROVER_assume(sec_r001694_7_1 != sec_r001694_7_2);
  __CPROVER_assume(sec_r001694_12_1 != sec_r001694_12_2);
  __CPROVER_assume(pub_r001694_15_1 == pub_r001694_15_2);
  __CPROVER_assume(pub_r001694_16_1 == pub_r001694_16_2);
  __CPROVER_assume(pub_r001694_18_1 == pub_r001694_18_2);
  __CPROVER_assume(sec_r001694_17_1 != sec_r001694_17_2);
  __CPROVER_assume(sec_r001694_1_1 != sec_r001694_1_2);
  __CPROVER_assume(pub_r001694_9_1 == pub_r001694_9_2);
  __CPROVER_assume(sec_r001694_6_1 != sec_r001694_6_2);
  __CPROVER_assume(sec_r001694_9_1 != sec_r001694_9_2);
  __CPROVER_assume(pub_r001694_4_1 == pub_r001694_4_2);
  __CPROVER_assume(pub_r001694_1_1 == pub_r001694_1_2);
  __CPROVER_assume(pub_r001694_2_1 == pub_r001694_2_2);
  __CPROVER_assume(sec_r001694_13_1 != sec_r001694_13_2);
  __CPROVER_assume(pub_r001694_10_1 == pub_r001694_10_2);
  __CPROVER_assume(pub_r001694_5_1 == pub_r001694_5_2);
  __CPROVER_assume(sec_r001694_16_1 != sec_r001694_16_2);
  __CPROVER_assume(sec_r001694_5_1 != sec_r001694_5_2);
  __CPROVER_assume(pub_r001694_3_1 == pub_r001694_3_2);
  __CPROVER_assume(sec_r001694_14_1 != sec_r001694_14_2);
  __CPROVER_assume(sec_r001694_18_1 != sec_r001694_18_2);
  __CPROVER_assume(pub_r001694_7_1 == pub_r001694_7_2);
  __CPROVER_assume(pub_r001694_8_1 == pub_r001694_8_2);
  __CPROVER_assume(sec_r001694_19_1 != sec_r001694_19_2);
  __CPROVER_assume(sec_r001694_10_1 != sec_r001694_10_2);
  __CPROVER_assume(pub_r001694_6_1 == pub_r001694_6_2);
  __CPROVER_assume(sec_r001694_0_1 != sec_r001694_0_2);
  __CPROVER_assume(pub_r001694_14_1 == pub_r001694_14_2);
  __CPROVER_assume(pub_r001694_13_1 == pub_r001694_13_2);
  __CPROVER_assume(sec_r001694_4_1 != sec_r001694_4_2);
  __CPROVER_assume(sec_r001694_2_1 != sec_r001694_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  assert(st_var_1_1.status == st_var_1_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.density == st_var_2_2.density);
  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.determinant == st_var_2_2.determinant);
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
  assert(stage_v_391_1 == stage_v_391_2);
  assert(stage_v_392_1 == stage_v_392_2);
  assert(stage_v_393_1 == stage_v_393_2);
  assert(stage_v_394_1 == stage_v_394_2);
}


