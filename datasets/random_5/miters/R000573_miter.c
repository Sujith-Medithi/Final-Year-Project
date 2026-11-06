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
struct Transaction_R000573_7313_0
{
  int status;
  short rate;
  int auth_code;
  int balance;
  int buffer[3];
};
struct MatrixBlock_R000573_7313_1
{
  int trace;
  unsigned char dim;
  int scale;
  short stride;
  int buffer[3];
};
struct CipherContext_R000573_7313_2
{
  int flags;
  unsigned char round_key;
  int counter;
  short iv;
  unsigned char nonce;
  int tag;
  int buffer[3];
};
struct SensorNode_R000573_7313_3
{
  int reading;
  short offset;
  short calib;
  int gain;
  int buffer[3];
};
union RegisterBank_R000573_7313_0
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
void fn_R000573_7313_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000573_7313_1 st_1 = {0};
  struct MatrixBlock_R000573_7313_1 st_2 = {0};
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
  int margin_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_13_1)
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

  switch (margin_13_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_13_1 == margin_13_2);
}

int fn_R000573_7313_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000573_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_13 = (aux + st.buffer[1]) & 3;
  switch (margin_13)
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

void fn_R000573_7313_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000573_7313_2 st_1 = {0};
  struct CipherContext_R000573_7313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int parity_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_12_1 > 44)
  {
    acc_1 = ((acc_1 + (parity_12_1 * 2)) + 5) & 127;
    aux_1 ^= parity_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_12_2 > 44)
  {
    acc_2 = ((acc_2 + (parity_12_2 * 2)) + 5) & 127;
    aux_2 ^= parity_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_47_1 = local_arr_1[aux_1 % 3];
  int phase_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_47_2 * 2)) & 127;
  int bound_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_99_1)
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

  switch (bound_99_2)
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

  int parity_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_38_1) & 63;
  aux_2 = (aux_2 + parity_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_12_1 == parity_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_47_1 == phase_47_2);
  assert(bound_99_1 == bound_99_2);
  assert(parity_38_1 == parity_38_2);
}

int fn_R000573_7313_1(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000573_7313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int parity_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_12 > 44)
  {
    acc = ((acc + (parity_12 * 2)) + 5) & 127;
    aux ^= parity_12 & 15;
  }
  else
  {
    acc = ((acc - parity_12) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int phase_47 = local_arr[aux % 3];
  acc = (acc + (phase_47 * 2)) & 127;
  int bound_99 = (aux + st.buffer[1]) & 3;
  switch (bound_99)
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

  int parity_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000573_7313_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000573_7313_2 st_1 = {0};
  struct CipherContext_R000573_7313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_66_1) & 63;
  aux_2 = (aux_2 + mask_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_19_1 > 30)
  {
    acc_1 = ((acc_1 + (phase_19_1 * 2)) + 5) & 127;
    aux_1 ^= phase_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_19_2 > 30)
  {
    acc_2 = ((acc_2 + (phase_19_2 * 2)) + 5) & 127;
    aux_2 ^= phase_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_19_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_66_1 == mask_66_2);
  assert(phase_19_1 == phase_19_2);
}

int fn_R000573_7313_2(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000573_7313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_66) & 63;
  acc ^= aux;
  int phase_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_19 > 30)
  {
    acc = ((acc + (phase_19 * 2)) + 5) & 127;
    aux ^= phase_19 & 15;
  }
  else
  {
    acc = ((acc - phase_19) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000573_7313_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st_1 = {0};
  struct Transaction_R000573_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_14_1 > 28)
  {
    acc_1 = ((acc_1 + (vector_14_1 * 2)) + 5) & 127;
    aux_1 ^= vector_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_14_2 > 28)
  {
    acc_2 = ((acc_2 + (vector_14_2 * 2)) + 5) & 127;
    aux_2 ^= vector_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_60_1 = local_arr_1[aux_1 % 3];
  int damping_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_60_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_14_1 == vector_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_60_1 == damping_60_2);
}

int fn_R000573_7313_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_14 > 28)
  {
    acc = ((acc + (vector_14 * 2)) + 5) & 127;
    aux ^= vector_14 & 15;
  }
  else
  {
    acc = ((acc - vector_14) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int damping_60 = local_arr[aux % 3];
  acc = (acc + (damping_60 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000573_7313_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000573_7313_2 st_1 = {0};
  struct CipherContext_R000573_7313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int bound_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_67_1)
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

  switch (bound_67_2)
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

  int index_reg_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_58_1 > 25)
  {
    acc_1 = ((acc_1 + (index_reg_58_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_58_2 > 25)
  {
    acc_2 = ((acc_2 + (index_reg_58_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_67_1 == bound_67_2);
  assert(index_reg_58_1 == index_reg_58_2);
}

int fn_R000573_7313_4(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000573_7313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int bound_67 = (aux + st.buffer[1]) & 3;
  switch (bound_67)
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

  int index_reg_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_58 > 25)
  {
    acc = ((acc + (index_reg_58 * 2)) + 5) & 127;
    aux ^= index_reg_58 & 15;
  }
  else
  {
    acc = ((acc - index_reg_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000573_7313_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st_1 = {0};
  struct Transaction_R000573_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int phase_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_61_1)
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

  switch (phase_61_2)
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

  int sample_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_84_1) & 63;
  aux_2 = (aux_2 + sample_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_69_1 > 49)
  {
    acc_1 = ((acc_1 + (threshold_69_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_69_2 > 49)
  {
    acc_2 = ((acc_2 + (threshold_69_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_69_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_61_1 == phase_61_2);
  assert(sample_84_1 == sample_84_2);
  assert(threshold_69_1 == threshold_69_2);
}

int fn_R000573_7313_5(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int phase_61 = (aux + st.buffer[1]) & 3;
  switch (phase_61)
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

  int sample_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_84) & 63;
  acc ^= aux;
  int threshold_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_69 > 49)
  {
    acc = ((acc + (threshold_69 * 2)) + 5) & 127;
    aux ^= threshold_69 & 15;
  }
  else
  {
    acc = ((acc - threshold_69) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000573_7313_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000573_7313_3 st_1 = {0};
  struct SensorNode_R000573_7313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_22_1 = local_arr_1[aux_1 % 3];
  int offset_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_22_2 * 2)) & 127;
  int bound_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_39_1)
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

  switch (bound_39_2)
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

  int tally_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_12_1 > 16)
  {
    acc_1 = ((acc_1 + (tally_12_1 * 2)) + 5) & 127;
    aux_1 ^= tally_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_12_2 > 16)
  {
    acc_2 = ((acc_2 + (tally_12_2 * 2)) + 5) & 127;
    aux_2 ^= tally_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_22_1 == offset_22_2);
  assert(bound_39_1 == bound_39_2);
  assert(tally_12_1 == tally_12_2);
}

int fn_R000573_7313_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000573_7313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int offset_22 = local_arr[aux % 3];
  acc = (acc + (offset_22 * 2)) & 127;
  int bound_39 = (aux + st.buffer[1]) & 3;
  switch (bound_39)
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

  int tally_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_12 > 16)
  {
    acc = ((acc + (tally_12 * 2)) + 5) & 127;
    aux ^= tally_12 & 15;
  }
  else
  {
    acc = ((acc - tally_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000573_7313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st_1 = {0};
  struct Transaction_R000573_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_29_1 = local_arr_1[aux_1 % 3];
  int pivot_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_29_2 * 2)) & 127;
  int damping_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_33_1) & 63;
  aux_2 = (aux_2 + damping_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_34_1)
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

  switch (cursor_34_2)
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

  int tracker_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_33_1 > 44)
  {
    acc_1 = ((acc_1 + (tracker_33_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_33_2 > 44)
  {
    acc_2 = ((acc_2 + (tracker_33_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_29_1 == pivot_29_2);
  assert(damping_33_1 == damping_33_2);
  assert(cursor_34_1 == cursor_34_2);
  assert(tracker_33_1 == tracker_33_2);
}

int fn_R000573_7313_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int pivot_29 = local_arr[aux % 3];
  acc = (acc + (pivot_29 * 2)) & 127;
  int damping_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_33) & 63;
  acc ^= aux;
  int cursor_34 = (aux + st.buffer[1]) & 3;
  switch (cursor_34)
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

  int tracker_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_33 > 44)
  {
    acc = ((acc + (tracker_33 * 2)) + 5) & 127;
    aux ^= tracker_33 & 15;
  }
  else
  {
    acc = ((acc - tracker_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000573_7313_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000573_7313_3 st_1 = {0};
  struct SensorNode_R000573_7313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_58_1 = local_arr_1[aux_1 % 3];
  int scale_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_58_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_99_1) & 63;
  aux_2 = (aux_2 + window_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_58_1 == scale_58_2);
  assert(window_99_1 == window_99_2);
}

int fn_R000573_7313_8(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000573_7313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int scale_58 = local_arr[aux % 3];
  acc = (acc + (scale_58 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000573_7313_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000573_7313_2 st_1 = {0};
  struct CipherContext_R000573_7313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_50_1 = local_arr_1[aux_1 % 3];
  int pivot_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_50_2 * 2)) & 127;
  int pivot_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_36_1) & 63;
  aux_2 = (aux_2 + pivot_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_29_1 > 20)
  {
    acc_1 = ((acc_1 + (metric_29_1 * 2)) + 5) & 127;
    aux_1 ^= metric_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_29_2 > 20)
  {
    acc_2 = ((acc_2 + (metric_29_2 * 2)) + 5) & 127;
    aux_2 ^= metric_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_50_1 == pivot_50_2);
  assert(pivot_36_1 == pivot_36_2);
  assert(metric_29_1 == metric_29_2);
}

int fn_R000573_7313_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000573_7313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int pivot_50 = local_arr[aux % 3];
  acc = (acc + (pivot_50 * 2)) & 127;
  int pivot_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_36) & 63;
  acc ^= aux;
  int metric_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_29 > 20)
  {
    acc = ((acc + (metric_29 * 2)) + 5) & 127;
    aux ^= metric_29 & 15;
  }
  else
  {
    acc = ((acc - metric_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000573_7313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st_1 = {0};
  struct Transaction_R000573_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int quantum_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_21_1)
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

  switch (quantum_21_2)
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

  int factor_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_12_1 > 30)
  {
    acc_1 = ((acc_1 + (factor_12_1 * 2)) + 5) & 127;
    aux_1 ^= factor_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_12_2 > 30)
  {
    acc_2 = ((acc_2 + (factor_12_2 * 2)) + 5) & 127;
    aux_2 ^= factor_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_93_1 = local_arr_1[aux_1 % 3];
  int tally_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_93_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_21_1 == quantum_21_2);
  assert(factor_12_1 == factor_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_93_1 == tally_93_2);
}

int fn_R000573_7313_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int quantum_21 = (aux + st.buffer[1]) & 3;
  switch (quantum_21)
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

  int factor_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_12 > 30)
  {
    acc = ((acc + (factor_12 * 2)) + 5) & 127;
    aux ^= factor_12 & 15;
  }
  else
  {
    acc = ((acc - factor_12) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_93 = local_arr[aux % 3];
  acc = (acc + (tally_93 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000573_7313_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st_1 = {0};
  struct Transaction_R000573_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int stride_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_93_1 > 50)
  {
    acc_1 = ((acc_1 + (stride_93_1 * 2)) + 5) & 127;
    aux_1 ^= stride_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_93_2 > 50)
  {
    acc_2 = ((acc_2 + (stride_93_2 * 2)) + 5) & 127;
    aux_2 ^= stride_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_30_1)
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

  switch (scale_30_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_68_1 = local_arr_1[aux_1 % 3];
  int stride_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_68_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_93_1 == stride_93_2);
  assert(scale_30_1 == scale_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_68_1 == stride_68_2);
}

int fn_R000573_7313_11(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int stride_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_93 > 50)
  {
    acc = ((acc + (stride_93 * 2)) + 5) & 127;
    aux ^= stride_93 & 15;
  }
  else
  {
    acc = ((acc - stride_93) + 11) & 127;
    aux += 3;
  }
  int scale_30 = (aux + st.buffer[1]) & 3;
  switch (scale_30)
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

  int local_arr[3] = {4, 9, 15};
  int stride_68 = local_arr[aux % 3];
  acc = (acc + (stride_68 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000573_7313_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st_1 = {0};
  struct Transaction_R000573_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int window_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_73_1 > 23)
  {
    acc_1 = ((acc_1 + (window_73_1 * 2)) + 5) & 127;
    aux_1 ^= window_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_73_2 > 23)
  {
    acc_2 = ((acc_2 + (window_73_2 * 2)) + 5) & 127;
    aux_2 ^= window_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_73_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_94_1) & 63;
  aux_2 = (aux_2 + parity_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_27_1)
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

  switch (threshold_27_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_73_1 == window_73_2);
  assert(parity_94_1 == parity_94_2);
  assert(threshold_27_1 == threshold_27_2);
}

int fn_R000573_7313_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int window_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_73 > 23)
  {
    acc = ((acc + (window_73 * 2)) + 5) & 127;
    aux ^= window_73 & 15;
  }
  else
  {
    acc = ((acc - window_73) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_94) & 63;
  acc ^= aux;
  int threshold_27 = (aux + st.buffer[1]) & 3;
  switch (threshold_27)
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

void fn_R000573_7313_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000573_7313_2 st_1 = {0};
  struct CipherContext_R000573_7313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_56_1 = local_arr_1[aux_1 % 3];
  int offset_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_56_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_56_1 == offset_56_2);
}

int fn_R000573_7313_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000573_7313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int offset_56 = local_arr[aux % 3];
  acc = (acc + (offset_56 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000573_7313_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000573_7313_1 st_1 = {0};
  struct MatrixBlock_R000573_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int tally_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_17_1) & 63;
  aux_2 = (aux_2 + tally_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_68_1)
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

  switch (scale_68_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_17_1 == tally_17_2);
  assert(scale_68_1 == scale_68_2);
}

int fn_R000573_7313_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000573_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int tally_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_17) & 63;
  acc ^= aux;
  int scale_68 = (aux + st.buffer[1]) & 3;
  switch (scale_68)
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

void fn_R000573_7313_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st_1 = {0};
  struct Transaction_R000573_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int vector_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_16_1)
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

  switch (vector_16_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_57_1 = local_arr_1[aux_1 % 3];
  int threshold_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_57_2 * 2)) & 127;
  int parity_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_27_1 > 16)
  {
    acc_1 = ((acc_1 + (parity_27_1 * 2)) + 5) & 127;
    aux_1 ^= parity_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_27_2 > 16)
  {
    acc_2 = ((acc_2 + (parity_27_2 * 2)) + 5) & 127;
    aux_2 ^= parity_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_54_1) & 63;
  aux_2 = (aux_2 + index_reg_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_16_1 == vector_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_57_1 == threshold_57_2);
  assert(parity_27_1 == parity_27_2);
  assert(index_reg_54_1 == index_reg_54_2);
}

int fn_R000573_7313_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int vector_16 = (aux + st.buffer[1]) & 3;
  switch (vector_16)
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

  int local_arr[3] = {4, 9, 15};
  int threshold_57 = local_arr[aux % 3];
  acc = (acc + (threshold_57 * 2)) & 127;
  int parity_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_27 > 16)
  {
    acc = ((acc + (parity_27 * 2)) + 5) & 127;
    aux ^= parity_27 & 15;
  }
  else
  {
    acc = ((acc - parity_27) + 11) & 127;
    aux += 3;
  }
  int index_reg_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000573_7313_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000573_7313_3 st_1 = {0};
  struct SensorNode_R000573_7313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int mask_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_22_1) & 63;
  aux_2 = (aux_2 + mask_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_54_1 = local_arr_1[aux_1 % 3];
  int parity_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_54_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_86_1)
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

  switch (sample_86_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_22_1 == mask_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_54_1 == parity_54_2);
  assert(sample_86_1 == sample_86_2);
}

int fn_R000573_7313_16(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000573_7313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int mask_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_22) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_54 = local_arr[aux % 3];
  acc = (acc + (parity_54 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_86 = (aux + st.buffer[1]) & 3;
  switch (sample_86)
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

void fn_R000573_7313_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000573_7313_3 st_1 = {0};
  struct SensorNode_R000573_7313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_20_1 = local_arr_1[aux_1 % 3];
  int delta_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_20_2 * 2)) & 127;
  int scale_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_34_1 > 19)
  {
    acc_1 = ((acc_1 + (scale_34_1 * 2)) + 5) & 127;
    aux_1 ^= scale_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_34_2 > 19)
  {
    acc_2 = ((acc_2 + (scale_34_2 * 2)) + 5) & 127;
    aux_2 ^= scale_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_56_1)
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

  switch (delta_56_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_20_1 == delta_20_2);
  assert(scale_34_1 == scale_34_2);
  assert(delta_56_1 == delta_56_2);
}

int fn_R000573_7313_17(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000573_7313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_20 = local_arr[aux % 3];
  acc = (acc + (delta_20 * 2)) & 127;
  int scale_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_34 > 19)
  {
    acc = ((acc + (scale_34 * 2)) + 5) & 127;
    aux ^= scale_34 & 15;
  }
  else
  {
    acc = ((acc - scale_34) + 11) & 127;
    aux += 3;
  }
  int delta_56 = (aux + st.buffer[1]) & 3;
  switch (delta_56)
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

void fn_R000573_7313_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000573_7313_1 st_1 = {0};
  struct MatrixBlock_R000573_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int bound_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_44_1) & 63;
  aux_2 = (aux_2 + bound_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_40_1 = local_arr_1[aux_1 % 3];
  int sample_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_40_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_77_1 > 33)
  {
    acc_1 = ((acc_1 + (metric_77_1 * 2)) + 5) & 127;
    aux_1 ^= metric_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_77_2 > 33)
  {
    acc_2 = ((acc_2 + (metric_77_2 * 2)) + 5) & 127;
    aux_2 ^= metric_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_77_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_44_1 == bound_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_40_1 == sample_40_2);
  assert(metric_77_1 == metric_77_2);
}

int fn_R000573_7313_18(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000573_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int bound_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_44) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_40 = local_arr[aux % 3];
  acc = (acc + (sample_40 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_77 > 33)
  {
    acc = ((acc + (metric_77 * 2)) + 5) & 127;
    aux ^= metric_77 & 15;
  }
  else
  {
    acc = ((acc - metric_77) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000573_7313_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000573_7313_3 st_1 = {0};
  struct SensorNode_R000573_7313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int quantum_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_61_1)
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

  switch (quantum_61_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_32_1 = local_arr_1[aux_1 % 3];
  int bound_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_61_1 == quantum_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_32_1 == bound_32_2);
}

int fn_R000573_7313_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000573_7313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int quantum_61 = (aux + st.buffer[1]) & 3;
  switch (quantum_61)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int bound_32 = local_arr[aux % 3];
  acc = (acc + (bound_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000573_7313_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st_1 = {0};
  struct Transaction_R000573_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int segment_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_17_1)
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

  switch (segment_17_2)
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

  int accumulator_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_28_1) & 63;
  aux_2 = (aux_2 + accumulator_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_17_1 == segment_17_2);
  assert(accumulator_28_1 == accumulator_28_2);
}

int fn_R000573_7313_20(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000573_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int segment_17 = (aux + st.buffer[1]) & 3;
  switch (segment_17)
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

  int accumulator_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_28) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000573_7313_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000573_7313_1 st_1 = {0};
  struct MatrixBlock_R000573_7313_1 st_2 = {0};
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

  switch (quotient_94_2)
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
  int quantum_31_1 = local_arr_1[aux_1 % 3];
  int quantum_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_31_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_94_1 == quotient_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_31_1 == quantum_31_2);
}

int fn_R000573_7313_21(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000573_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quotient_94 = (aux + st.buffer[1]) & 3;
  switch (quotient_94)
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
  int quantum_31 = local_arr[aux % 3];
  acc = (acc + (quantum_31 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000573_7313_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000573_7313_1 st_1 = {0};
  struct MatrixBlock_R000573_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int threshold_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_98_1) & 63;
  aux_2 = (aux_2 + threshold_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_20_1 > 19)
  {
    acc_1 = ((acc_1 + (residue_20_1 * 2)) + 5) & 127;
    aux_1 ^= residue_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_20_2 > 19)
  {
    acc_2 = ((acc_2 + (residue_20_2 * 2)) + 5) & 127;
    aux_2 ^= residue_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_20_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_98_1 == threshold_98_2);
  assert(residue_20_1 == residue_20_2);
}

int fn_R000573_7313_22(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000573_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int threshold_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_98) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_20 > 19)
  {
    acc = ((acc + (residue_20 * 2)) + 5) & 127;
    aux ^= residue_20 & 15;
  }
  else
  {
    acc = ((acc - residue_20) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000573_7313_23_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000573_7313_3 st_1 = {0};
  struct SensorNode_R000573_7313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int checksum_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_99_1 > 48)
  {
    acc_1 = ((acc_1 + (checksum_99_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_99_2 > 48)
  {
    acc_2 = ((acc_2 + (checksum_99_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_84_1)
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

  switch (margin_84_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_99_1 == checksum_99_2);
  assert(margin_84_1 == margin_84_2);
}

int fn_R000573_7313_23(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000573_7313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int checksum_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_99 > 48)
  {
    acc = ((acc + (checksum_99 * 2)) + 5) & 127;
    aux ^= checksum_99 & 15;
  }
  else
  {
    acc = ((acc - checksum_99) + 11) & 127;
    aux += 3;
  }
  int margin_84 = (aux + st.buffer[1]) & 3;
  switch (margin_84)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000573_0_1;
  int sec_r000573_0_2;
  int sec_r000573_1_1;
  int sec_r000573_1_2;
  int sec_r000573_2_1;
  int sec_r000573_2_2;
  int sec_r000573_3_1;
  int sec_r000573_3_2;
  int sec_r000573_4_1;
  int sec_r000573_4_2;
  int sec_r000573_5_1;
  int sec_r000573_5_2;
  int sec_r000573_6_1;
  int sec_r000573_6_2;
  int sec_r000573_7_1;
  int sec_r000573_7_2;
  int sec_r000573_8_1;
  int sec_r000573_8_2;
  int sec_r000573_9_1;
  int sec_r000573_9_2;
  int sec_r000573_10_1;
  int sec_r000573_10_2;
  int sec_r000573_11_1;
  int sec_r000573_11_2;
  int sec_r000573_12_1;
  int sec_r000573_12_2;
  int sec_r000573_13_1;
  int sec_r000573_13_2;
  int sec_r000573_14_1;
  int sec_r000573_14_2;
  int sec_r000573_15_1;
  int sec_r000573_15_2;
  int sec_r000573_16_1;
  int sec_r000573_16_2;
  int sec_r000573_17_1;
  int sec_r000573_17_2;
  int sec_r000573_18_1;
  int sec_r000573_18_2;
  int sec_r000573_19_1;
  int sec_r000573_19_2;
  int sec_r000573_20_1;
  int sec_r000573_20_2;
  int pub_r000573_0_1;
  int pub_r000573_0_2;
  int pub_r000573_1_1;
  int pub_r000573_1_2;
  int pub_r000573_2_1;
  int pub_r000573_2_2;
  int pub_r000573_3_1;
  int pub_r000573_3_2;
  int pub_r000573_4_1;
  int pub_r000573_4_2;
  int pub_r000573_5_1;
  int pub_r000573_5_2;
  int pub_r000573_6_1;
  int pub_r000573_6_2;
  int pub_r000573_7_1;
  int pub_r000573_7_2;
  int pub_r000573_8_1;
  int pub_r000573_8_2;
  int pub_r000573_9_1;
  int pub_r000573_9_2;
  int pub_r000573_10_1;
  int pub_r000573_10_2;
  int pub_r000573_11_1;
  int pub_r000573_11_2;
  int pub_r000573_12_1;
  int pub_r000573_12_2;
  int pub_r000573_13_1;
  int pub_r000573_13_2;
  int pub_r000573_14_1;
  int pub_r000573_14_2;
  int pub_r000573_15_1;
  int pub_r000573_15_2;
  int pub_r000573_16_1;
  int pub_r000573_16_2;
  int pub_r000573_17_1;
  int pub_r000573_17_2;
  int pub_r000573_18_1;
  int pub_r000573_18_2;
  int pub_r000573_19_1;
  int pub_r000573_19_2;
  int pub_r000573_20_1;
  int pub_r000573_20_2;
  int pub_r000573_21_1;
  int pub_r000573_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000573_0_1 >= (-100)) && (pub_r000573_0_1 <= 100));
  __CPROVER_assume((pub_r000573_0_2 >= (-100)) && (pub_r000573_0_2 <= 100));
  __CPROVER_assume((pub_r000573_1_1 >= (-100)) && (pub_r000573_1_1 <= 100));
  __CPROVER_assume((pub_r000573_1_2 >= (-100)) && (pub_r000573_1_2 <= 100));
  __CPROVER_assume((pub_r000573_2_1 >= (-100)) && (pub_r000573_2_1 <= 100));
  __CPROVER_assume((pub_r000573_2_2 >= (-100)) && (pub_r000573_2_2 <= 100));
  __CPROVER_assume((pub_r000573_3_1 >= (-100)) && (pub_r000573_3_1 <= 100));
  __CPROVER_assume((pub_r000573_3_2 >= (-100)) && (pub_r000573_3_2 <= 100));
  __CPROVER_assume((pub_r000573_4_1 >= (-100)) && (pub_r000573_4_1 <= 100));
  __CPROVER_assume((pub_r000573_4_2 >= (-100)) && (pub_r000573_4_2 <= 100));
  __CPROVER_assume((pub_r000573_5_1 >= (-100)) && (pub_r000573_5_1 <= 100));
  __CPROVER_assume((pub_r000573_5_2 >= (-100)) && (pub_r000573_5_2 <= 100));
  __CPROVER_assume((pub_r000573_6_1 >= (-100)) && (pub_r000573_6_1 <= 100));
  __CPROVER_assume((pub_r000573_6_2 >= (-100)) && (pub_r000573_6_2 <= 100));
  __CPROVER_assume((pub_r000573_7_1 >= (-100)) && (pub_r000573_7_1 <= 100));
  __CPROVER_assume((pub_r000573_7_2 >= (-100)) && (pub_r000573_7_2 <= 100));
  __CPROVER_assume((pub_r000573_8_1 >= (-100)) && (pub_r000573_8_1 <= 100));
  __CPROVER_assume((pub_r000573_8_2 >= (-100)) && (pub_r000573_8_2 <= 100));
  __CPROVER_assume((pub_r000573_9_1 >= (-100)) && (pub_r000573_9_1 <= 100));
  __CPROVER_assume((pub_r000573_9_2 >= (-100)) && (pub_r000573_9_2 <= 100));
  __CPROVER_assume((pub_r000573_10_1 >= (-100)) && (pub_r000573_10_1 <= 100));
  __CPROVER_assume((pub_r000573_10_2 >= (-100)) && (pub_r000573_10_2 <= 100));
  __CPROVER_assume((pub_r000573_11_1 >= (-100)) && (pub_r000573_11_1 <= 100));
  __CPROVER_assume((pub_r000573_11_2 >= (-100)) && (pub_r000573_11_2 <= 100));
  __CPROVER_assume((pub_r000573_12_1 >= (-100)) && (pub_r000573_12_1 <= 100));
  __CPROVER_assume((pub_r000573_12_2 >= (-100)) && (pub_r000573_12_2 <= 100));
  __CPROVER_assume((pub_r000573_13_1 >= (-100)) && (pub_r000573_13_1 <= 100));
  __CPROVER_assume((pub_r000573_13_2 >= (-100)) && (pub_r000573_13_2 <= 100));
  __CPROVER_assume((pub_r000573_14_1 >= (-100)) && (pub_r000573_14_1 <= 100));
  __CPROVER_assume((pub_r000573_14_2 >= (-100)) && (pub_r000573_14_2 <= 100));
  __CPROVER_assume((pub_r000573_15_1 >= (-100)) && (pub_r000573_15_1 <= 100));
  __CPROVER_assume((pub_r000573_15_2 >= (-100)) && (pub_r000573_15_2 <= 100));
  __CPROVER_assume((pub_r000573_16_1 >= (-100)) && (pub_r000573_16_1 <= 100));
  __CPROVER_assume((pub_r000573_16_2 >= (-100)) && (pub_r000573_16_2 <= 100));
  __CPROVER_assume((pub_r000573_17_1 >= (-100)) && (pub_r000573_17_1 <= 100));
  __CPROVER_assume((pub_r000573_17_2 >= (-100)) && (pub_r000573_17_2 <= 100));
  __CPROVER_assume((pub_r000573_18_1 >= (-100)) && (pub_r000573_18_1 <= 100));
  __CPROVER_assume((pub_r000573_18_2 >= (-100)) && (pub_r000573_18_2 <= 100));
  __CPROVER_assume((pub_r000573_19_1 >= (-100)) && (pub_r000573_19_1 <= 100));
  __CPROVER_assume((pub_r000573_19_2 >= (-100)) && (pub_r000573_19_2 <= 100));
  __CPROVER_assume((pub_r000573_20_1 >= (-100)) && (pub_r000573_20_1 <= 100));
  __CPROVER_assume((pub_r000573_20_2 >= (-100)) && (pub_r000573_20_2 <= 100));
  __CPROVER_assume((pub_r000573_21_1 >= (-100)) && (pub_r000573_21_1 <= 100));
  __CPROVER_assume((pub_r000573_21_2 >= (-100)) && (pub_r000573_21_2 <= 100));
  __CPROVER_assume((sec_r000573_0_1 >= 0) && (sec_r000573_0_1 <= 255));
  __CPROVER_assume((sec_r000573_0_2 >= 0) && (sec_r000573_0_2 <= 255));
  __CPROVER_assume((sec_r000573_1_1 >= 0) && (sec_r000573_1_1 <= 255));
  __CPROVER_assume((sec_r000573_1_2 >= 0) && (sec_r000573_1_2 <= 255));
  __CPROVER_assume((sec_r000573_2_1 >= 0) && (sec_r000573_2_1 <= 255));
  __CPROVER_assume((sec_r000573_2_2 >= 0) && (sec_r000573_2_2 <= 255));
  __CPROVER_assume((sec_r000573_3_1 >= 0) && (sec_r000573_3_1 <= 255));
  __CPROVER_assume((sec_r000573_3_2 >= 0) && (sec_r000573_3_2 <= 255));
  __CPROVER_assume((sec_r000573_4_1 >= 0) && (sec_r000573_4_1 <= 255));
  __CPROVER_assume((sec_r000573_4_2 >= 0) && (sec_r000573_4_2 <= 255));
  __CPROVER_assume((sec_r000573_5_1 >= 0) && (sec_r000573_5_1 <= 255));
  __CPROVER_assume((sec_r000573_5_2 >= 0) && (sec_r000573_5_2 <= 255));
  __CPROVER_assume((sec_r000573_6_1 >= 0) && (sec_r000573_6_1 <= 255));
  __CPROVER_assume((sec_r000573_6_2 >= 0) && (sec_r000573_6_2 <= 255));
  __CPROVER_assume((sec_r000573_7_1 >= 0) && (sec_r000573_7_1 <= 255));
  __CPROVER_assume((sec_r000573_7_2 >= 0) && (sec_r000573_7_2 <= 255));
  __CPROVER_assume((sec_r000573_8_1 >= 0) && (sec_r000573_8_1 <= 255));
  __CPROVER_assume((sec_r000573_8_2 >= 0) && (sec_r000573_8_2 <= 255));
  __CPROVER_assume((sec_r000573_9_1 >= 0) && (sec_r000573_9_1 <= 255));
  __CPROVER_assume((sec_r000573_9_2 >= 0) && (sec_r000573_9_2 <= 255));
  __CPROVER_assume((sec_r000573_10_1 >= 0) && (sec_r000573_10_1 <= 255));
  __CPROVER_assume((sec_r000573_10_2 >= 0) && (sec_r000573_10_2 <= 255));
  __CPROVER_assume((sec_r000573_11_1 >= 0) && (sec_r000573_11_1 <= 255));
  __CPROVER_assume((sec_r000573_11_2 >= 0) && (sec_r000573_11_2 <= 255));
  __CPROVER_assume((sec_r000573_12_1 >= 0) && (sec_r000573_12_1 <= 255));
  __CPROVER_assume((sec_r000573_12_2 >= 0) && (sec_r000573_12_2 <= 255));
  __CPROVER_assume((sec_r000573_13_1 >= 0) && (sec_r000573_13_1 <= 255));
  __CPROVER_assume((sec_r000573_13_2 >= 0) && (sec_r000573_13_2 <= 255));
  __CPROVER_assume((sec_r000573_14_1 >= 0) && (sec_r000573_14_1 <= 255));
  __CPROVER_assume((sec_r000573_14_2 >= 0) && (sec_r000573_14_2 <= 255));
  __CPROVER_assume((sec_r000573_15_1 >= 0) && (sec_r000573_15_1 <= 255));
  __CPROVER_assume((sec_r000573_15_2 >= 0) && (sec_r000573_15_2 <= 255));
  __CPROVER_assume((sec_r000573_16_1 >= 0) && (sec_r000573_16_1 <= 255));
  __CPROVER_assume((sec_r000573_16_2 >= 0) && (sec_r000573_16_2 <= 255));
  __CPROVER_assume((sec_r000573_17_1 >= 0) && (sec_r000573_17_1 <= 255));
  __CPROVER_assume((sec_r000573_17_2 >= 0) && (sec_r000573_17_2 <= 255));
  __CPROVER_assume((sec_r000573_18_1 >= 0) && (sec_r000573_18_1 <= 255));
  __CPROVER_assume((sec_r000573_18_2 >= 0) && (sec_r000573_18_2 <= 255));
  __CPROVER_assume((sec_r000573_19_1 >= 0) && (sec_r000573_19_1 <= 255));
  __CPROVER_assume((sec_r000573_19_2 >= 0) && (sec_r000573_19_2 <= 255));
  __CPROVER_assume((sec_r000573_20_1 >= 0) && (sec_r000573_20_1 <= 255));
  __CPROVER_assume((sec_r000573_20_2 >= 0) && (sec_r000573_20_2 <= 255));
  struct Transaction_R000573_7313_0 st_var_0_1 = {0};
  struct Transaction_R000573_7313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000573_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000573_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000573_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000573_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000573_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000573_0_2 + 7) & 15;
  struct MatrixBlock_R000573_7313_1 st_var_1_1 = {0};
  struct MatrixBlock_R000573_7313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000573_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000573_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000573_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000573_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000573_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000573_0_2 + 9) & 15;
  struct CipherContext_R000573_7313_2 st_var_2_1 = {0};
  struct CipherContext_R000573_7313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000573_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000573_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000573_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000573_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000573_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000573_0_2 + 11) & 15;
  struct SensorNode_R000573_7313_3 st_var_3_1 = {0};
  struct SensorNode_R000573_7313_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000573_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000573_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000573_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000573_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000573_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000573_0_2 + 13) & 15;
  union RegisterBank_R000573_7313_0 u_var_1;
  union RegisterBank_R000573_7313_0 u_var_2;
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
  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (st_var_3_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_3_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = ((st_var_1_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_1_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 37)
    {
      chk_sum_1 ^= stage_v_9_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_9_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 37)
    {
      chk_sum_2 ^= stage_v_9_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
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
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  int stage_v_19_1 = (st_var_3_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_3_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 29) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 30) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 30) & 15;
  int stage_v_29_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_29_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= stage_v_29_1;
  chk_sum_2 ^= stage_v_29_2;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 31) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  int stage_v_34_1 = ((st_var_2_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_2_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 52)
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
  if (stage_v_34_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 52)
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
  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_36_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (43 & 31);
  int stage_v_38_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (43 & 31);
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= (stage_v_38_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_38_2 << 1) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 40) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 41) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = (st_var_1_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_1_2.buffer[0] ^ 44) & 3;
  switch (stage_v_41_1)
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

  switch (stage_v_41_2)
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

  int stage_v_42_1 = (st_var_2_1.buffer[0] ^ 45) & 3;
  int stage_v_42_2 = (st_var_2_2.buffer[0] ^ 45) & 3;
  switch (stage_v_42_1)
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

  switch (stage_v_42_2)
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

  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((st_var_0_1.buffer[2] * 2) + 139) & 63;
  int stage_v_44_2 = ((st_var_0_2.buffer[2] * 2) + 139) & 63;
  if (stage_v_44_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 48)
    {
      chk_sum_1 ^= stage_v_44_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_44_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 48)
    {
      chk_sum_2 ^= stage_v_44_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_45_1 = (st_var_1_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_1_2.buffer[0] ^ 48) & 3;
  switch (stage_v_45_1)
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

  switch (stage_v_45_2)
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

  int stage_v_46_1 = (st_var_2_1.buffer[0] ^ 49) & 3;
  int stage_v_46_2 = (st_var_2_2.buffer[0] ^ 49) & 3;
  switch (stage_v_46_1)
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

  switch (stage_v_46_2)
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

  int stage_v_47_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_47_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = (st_var_1_1.buffer[0] ^ 52) & 3;
  int stage_v_49_2 = (st_var_1_2.buffer[0] ^ 52) & 3;
  switch (stage_v_49_1)
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

  switch (stage_v_49_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 51) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 51) & 15;
  int stage_v_50_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_50_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= stage_v_50_1;
  chk_sum_2 ^= stage_v_50_2;
  int stage_v_51_1 = ((st_var_3_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_3_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 34)
    {
      chk_sum_1 ^= stage_v_51_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_51_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 34)
    {
      chk_sum_2 ^= stage_v_51_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_52_1 = (st_var_0_1.buffer[0] ^ 55) & 3;
  int stage_v_52_2 = (st_var_0_2.buffer[0] ^ 55) & 3;
  switch (stage_v_52_1)
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

  switch (stage_v_52_2)
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

  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = (st_var_2_1.buffer[0] ^ 57) & 3;
  int stage_v_54_2 = (st_var_2_2.buffer[0] ^ 57) & 3;
  switch (stage_v_54_1)
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

  switch (stage_v_54_2)
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

  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((st_var_0_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_0_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 52)
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
  if (stage_v_56_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 52)
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
  if (stage_v_57_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_57_1) - 5) & 255;
    if (stage_v_57_1 > 35)
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
  if (stage_v_57_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_57_2) - 5) & 255;
    if (stage_v_57_2 > 35)
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
  int stage_v_58_1 = table_1[2];
  int stage_v_58_2 = table_2[2];
  table_1[2] = (table_1[3] + 117) & 63;
  table_2[2] = (table_2[3] + 117) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_59_1 = ((stage_v_59_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_59_2 = ((stage_v_59_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = table_1[0];
  int stage_v_60_2 = table_2[0];
  table_1[0] = (table_1[1] + 121) & 63;
  table_2[0] = (table_2[1] + 121) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 62) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 62) & 15;
  int stage_v_61_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_61_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= stage_v_61_1;
  chk_sum_2 ^= stage_v_61_2;
  int stage_v_62_1 = (st_var_2_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_2_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 65) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 65) & 15;
  int stage_v_64_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_64_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= stage_v_64_1;
  chk_sum_2 ^= stage_v_64_2;
  int stage_v_65_1 = table_1[1];
  int stage_v_65_2 = table_2[1];
  table_1[1] = (table_1[2] + 131) & 63;
  table_2[1] = (table_2[2] + 131) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 67) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 67) & 15;
  int stage_v_66_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_66_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= stage_v_66_1;
  chk_sum_2 ^= stage_v_66_2;
  int stage_v_67_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (72 & 31);
  int stage_v_67_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (72 & 31);
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= (stage_v_67_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_67_2 << 1) & 127;
  int stage_v_68_1 = ((st_var_0_1.buffer[2] * 2) + 211) & 63;
  int stage_v_68_2 = ((st_var_0_2.buffer[2] * 2) + 211) & 63;
  if (stage_v_68_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_68_1) - 5) & 255;
    if (stage_v_68_1 > 44)
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
  if (stage_v_68_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_68_2) - 5) & 255;
    if (stage_v_68_2 > 44)
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
  int stage_v_69_1 = ((st_var_1_1.buffer[0] * 2) + 214) & 63;
  int stage_v_69_2 = ((st_var_1_2.buffer[0] * 2) + 214) & 63;
  if (stage_v_69_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_69_1) - 5) & 255;
    if (stage_v_69_1 > 51)
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
  if (stage_v_69_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_69_2) - 5) & 255;
    if (stage_v_69_2 > 51)
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
  int stage_v_70_1 = ((st_var_2_1.buffer[1] * 2) + 217) & 63;
  int stage_v_70_2 = ((st_var_2_2.buffer[1] * 2) + 217) & 63;
  if (stage_v_70_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_70_1) - 5) & 255;
    if (stage_v_70_1 > 42)
    {
      chk_sum_1 ^= stage_v_70_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_70_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_70_2) - 5) & 255;
    if (stage_v_70_2 > 42)
    {
      chk_sum_2 ^= stage_v_70_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_71_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_71_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_72_1 = (st_var_0_1.buffer[0] ^ 75) & 3;
  int stage_v_72_2 = (st_var_0_2.buffer[0] ^ 75) & 3;
  switch (stage_v_72_1)
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

  switch (stage_v_72_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 74) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 74) & 15;
  int stage_v_73_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_73_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= stage_v_73_1;
  chk_sum_2 ^= stage_v_73_2;
  int stage_v_74_1 = table_1[2];
  int stage_v_74_2 = table_2[2];
  table_1[2] = (table_1[3] + 149) & 63;
  table_2[2] = (table_2[3] + 149) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (st_var_3_1.buffer[0] ^ 78) & 3;
  int stage_v_75_2 = (st_var_3_2.buffer[0] ^ 78) & 3;
  switch (stage_v_75_1)
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

  switch (stage_v_75_2)
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

  int stage_v_76_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (81 & 31);
  int stage_v_76_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (81 & 31);
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= (stage_v_76_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_76_2 << 1) & 127;
  int stage_v_77_1 = table_1[1];
  int stage_v_77_2 = table_2[1];
  table_1[1] = (table_1[2] + 155) & 63;
  table_2[1] = (table_2[2] + 155) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int sub_step_78_1 = ((sec_r000573_1_1 + pub_r000573_17_1) + 27) & 127;
  int sub_step_78_2 = ((sec_r000573_1_2 + pub_r000573_17_2) + 27) & 127;
  int stage_v_78_1 = ((sub_step_78_1 * 2) + pub_r000573_3_1) & 127;
  int stage_v_78_2 = ((sub_step_78_2 * 2) + pub_r000573_3_2) & 127;
  st_var_2_1.buffer[0] = stage_v_78_1 & 15;
  st_var_2_2.buffer[0] = stage_v_78_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int sub_step_79_1 = ((stage_v_78_1 + pub_r000573_12_1) + 11) & 127;
  int sub_step_79_2 = ((stage_v_78_2 + pub_r000573_12_2) + 11) & 127;
  int stage_v_79_1 = ((sub_step_79_1 * 2) + pub_r000573_16_1) & 127;
  int stage_v_79_2 = ((sub_step_79_2 * 2) + pub_r000573_16_2) & 127;
  st_var_3_1.buffer[1] = stage_v_79_1 & 15;
  st_var_3_2.buffer[1] = stage_v_79_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int sub_step_80_1 = ((sub_step_78_1 + pub_r000573_15_1) + 27) & 127;
  int sub_step_80_2 = ((sub_step_78_2 + pub_r000573_15_2) + 27) & 127;
  int stage_v_80_1 = ((sub_step_80_1 * 2) + pub_r000573_13_1) & 127;
  int stage_v_80_2 = ((sub_step_80_2 * 2) + pub_r000573_13_2) & 127;
  st_var_0_1.buffer[2] = stage_v_80_1 & 15;
  st_var_0_2.buffer[2] = stage_v_80_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int sub_step_81_1 = ((sec_r000573_3_1 + pub_r000573_12_1) + 13) & 127;
  int sub_step_81_2 = ((sec_r000573_3_2 + pub_r000573_12_2) + 13) & 127;
  int stage_v_81_1 = ((sub_step_81_1 * 2) + pub_r000573_19_1) & 127;
  int stage_v_81_2 = ((sub_step_81_2 * 2) + pub_r000573_19_2) & 127;
  st_var_1_1.buffer[0] = stage_v_81_1 & 15;
  st_var_1_2.buffer[0] = stage_v_81_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int sub_step_82_1 = ((sec_r000573_20_1 + pub_r000573_8_1) + 9) & 127;
  int sub_step_82_2 = ((sec_r000573_20_2 + pub_r000573_8_2) + 9) & 127;
  int stage_v_82_1 = ((sub_step_82_1 * 2) + pub_r000573_13_1) & 127;
  int stage_v_82_2 = ((sub_step_82_2 * 2) + pub_r000573_13_2) & 127;
  st_var_2_1.buffer[1] = stage_v_82_1 & 15;
  st_var_2_2.buffer[1] = stage_v_82_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int sub_step_83_1 = ((sec_r000573_12_1 + pub_r000573_6_1) + 23) & 127;
  int sub_step_83_2 = ((sec_r000573_12_2 + pub_r000573_6_2) + 23) & 127;
  int stage_v_83_1 = ((sub_step_83_1 * 2) + pub_r000573_14_1) & 127;
  int stage_v_83_2 = ((sub_step_83_2 * 2) + pub_r000573_14_2) & 127;
  st_var_3_1.buffer[2] = stage_v_83_1 & 15;
  st_var_3_2.buffer[2] = stage_v_83_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int sub_step_84_1 = ((stage_v_83_1 + pub_r000573_16_1) + 18) & 127;
  int sub_step_84_2 = ((stage_v_83_2 + pub_r000573_16_2) + 18) & 127;
  int stage_v_84_1 = ((sub_step_84_1 * 2) + pub_r000573_10_1) & 127;
  int stage_v_84_2 = ((sub_step_84_2 * 2) + pub_r000573_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_84_1 & 15;
  st_var_0_2.buffer[0] = stage_v_84_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int sub_step_85_1 = ((sec_r000573_5_1 + pub_r000573_21_1) + 28) & 127;
  int sub_step_85_2 = ((sec_r000573_5_2 + pub_r000573_21_2) + 28) & 127;
  int stage_v_85_1 = ((sub_step_85_1 * 2) + pub_r000573_13_1) & 127;
  int stage_v_85_2 = ((sub_step_85_2 * 2) + pub_r000573_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_85_1 & 15;
  st_var_1_2.buffer[1] = stage_v_85_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int sub_step_86_1 = ((sec_r000573_2_1 + pub_r000573_5_1) + 34) & 127;
  int sub_step_86_2 = ((sec_r000573_2_2 + pub_r000573_5_2) + 34) & 127;
  int stage_v_86_1 = ((sub_step_86_1 * 2) + pub_r000573_4_1) & 127;
  int stage_v_86_2 = ((sub_step_86_2 * 2) + pub_r000573_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_86_1 & 15;
  st_var_2_2.buffer[2] = stage_v_86_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int sub_step_87_1 = ((sec_r000573_2_1 + pub_r000573_3_1) + 8) & 127;
  int sub_step_87_2 = ((sec_r000573_2_2 + pub_r000573_3_2) + 8) & 127;
  int stage_v_87_1 = ((sub_step_87_1 * 2) + pub_r000573_15_1) & 127;
  int stage_v_87_2 = ((sub_step_87_2 * 2) + pub_r000573_15_2) & 127;
  st_var_3_1.buffer[0] = stage_v_87_1 & 15;
  st_var_3_2.buffer[0] = stage_v_87_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int sub_step_88_1 = ((sec_r000573_0_1 + pub_r000573_13_1) + 34) & 127;
  int sub_step_88_2 = ((sec_r000573_0_2 + pub_r000573_13_2) + 34) & 127;
  int stage_v_88_1 = ((sub_step_88_1 * 2) + pub_r000573_14_1) & 127;
  int stage_v_88_2 = ((sub_step_88_2 * 2) + pub_r000573_14_2) & 127;
  st_var_0_1.buffer[1] = stage_v_88_1 & 15;
  st_var_0_2.buffer[1] = stage_v_88_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int sub_step_89_1 = ((stage_v_81_1 + pub_r000573_16_1) + 10) & 127;
  int sub_step_89_2 = ((stage_v_81_2 + pub_r000573_16_2) + 10) & 127;
  int stage_v_89_1 = ((sub_step_89_1 * 2) + pub_r000573_6_1) & 127;
  int stage_v_89_2 = ((sub_step_89_2 * 2) + pub_r000573_6_2) & 127;
  st_var_1_1.buffer[2] = stage_v_89_1 & 15;
  st_var_1_2.buffer[2] = stage_v_89_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int sub_step_90_1 = ((stage_v_79_1 + pub_r000573_13_1) + 30) & 127;
  int sub_step_90_2 = ((stage_v_79_2 + pub_r000573_13_2) + 30) & 127;
  int stage_v_90_1 = ((sub_step_90_1 * 2) + pub_r000573_7_1) & 127;
  int stage_v_90_2 = ((sub_step_90_2 * 2) + pub_r000573_7_2) & 127;
  st_var_2_1.buffer[0] = stage_v_90_1 & 15;
  st_var_2_2.buffer[0] = stage_v_90_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int sub_step_91_1 = ((sec_r000573_18_1 + pub_r000573_16_1) + 8) & 127;
  int sub_step_91_2 = ((sec_r000573_18_2 + pub_r000573_16_2) + 8) & 127;
  int stage_v_91_1 = ((sub_step_91_1 * 2) + pub_r000573_21_1) & 127;
  int stage_v_91_2 = ((sub_step_91_2 * 2) + pub_r000573_21_2) & 127;
  st_var_3_1.buffer[1] = stage_v_91_1 & 15;
  st_var_3_2.buffer[1] = stage_v_91_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int sub_step_92_1 = ((sec_r000573_10_1 + pub_r000573_20_1) + 34) & 127;
  int sub_step_92_2 = ((sec_r000573_10_2 + pub_r000573_20_2) + 34) & 127;
  int stage_v_92_1 = ((sub_step_92_1 * 2) + pub_r000573_14_1) & 127;
  int stage_v_92_2 = ((sub_step_92_2 * 2) + pub_r000573_14_2) & 127;
  st_var_0_1.buffer[2] = stage_v_92_1 & 15;
  st_var_0_2.buffer[2] = stage_v_92_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int sub_step_93_1 = ((sub_step_80_1 + pub_r000573_21_1) + 11) & 127;
  int sub_step_93_2 = ((sub_step_80_2 + pub_r000573_21_2) + 11) & 127;
  int stage_v_93_1 = ((sub_step_93_1 * 2) + pub_r000573_18_1) & 127;
  int stage_v_93_2 = ((sub_step_93_2 * 2) + pub_r000573_18_2) & 127;
  st_var_1_1.buffer[0] = stage_v_93_1 & 15;
  st_var_1_2.buffer[0] = stage_v_93_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int sub_step_94_1 = ((sec_r000573_13_1 + pub_r000573_0_1) + 35) & 127;
  int sub_step_94_2 = ((sec_r000573_13_2 + pub_r000573_0_2) + 35) & 127;
  int stage_v_94_1 = ((sub_step_94_1 * 2) + pub_r000573_17_1) & 127;
  int stage_v_94_2 = ((sub_step_94_2 * 2) + pub_r000573_17_2) & 127;
  st_var_2_1.buffer[1] = stage_v_94_1 & 15;
  st_var_2_2.buffer[1] = stage_v_94_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int sub_step_95_1 = ((sec_r000573_2_1 + pub_r000573_7_1) + 24) & 127;
  int sub_step_95_2 = ((sec_r000573_2_2 + pub_r000573_7_2) + 24) & 127;
  int stage_v_95_1 = ((sub_step_95_1 * 2) + pub_r000573_21_1) & 127;
  int stage_v_95_2 = ((sub_step_95_2 * 2) + pub_r000573_21_2) & 127;
  st_var_3_1.buffer[2] = stage_v_95_1 & 15;
  st_var_3_2.buffer[2] = stage_v_95_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int sub_step_96_1 = ((sec_r000573_20_1 + pub_r000573_17_1) + 34) & 127;
  int sub_step_96_2 = ((sec_r000573_20_2 + pub_r000573_17_2) + 34) & 127;
  int stage_v_96_1 = ((sub_step_96_1 * 2) + pub_r000573_10_1) & 127;
  int stage_v_96_2 = ((sub_step_96_2 * 2) + pub_r000573_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_96_1 & 15;
  st_var_0_2.buffer[0] = stage_v_96_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int sub_step_97_1 = ((stage_v_95_1 + pub_r000573_12_1) + 17) & 127;
  int sub_step_97_2 = ((stage_v_95_2 + pub_r000573_12_2) + 17) & 127;
  int stage_v_97_1 = ((sub_step_97_1 * 2) + pub_r000573_10_1) & 127;
  int stage_v_97_2 = ((sub_step_97_2 * 2) + pub_r000573_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_97_1 & 15;
  st_var_1_2.buffer[1] = stage_v_97_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int sub_step_98_1 = ((stage_v_94_1 + pub_r000573_19_1) + 11) & 127;
  int sub_step_98_2 = ((stage_v_94_2 + pub_r000573_19_2) + 11) & 127;
  int stage_v_98_1 = ((sub_step_98_1 * 2) + pub_r000573_3_1) & 127;
  int stage_v_98_2 = ((sub_step_98_2 * 2) + pub_r000573_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_98_1 & 15;
  st_var_2_2.buffer[2] = stage_v_98_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int sub_step_99_1 = ((sec_r000573_11_1 + pub_r000573_20_1) + 21) & 127;
  int sub_step_99_2 = ((sec_r000573_11_2 + pub_r000573_20_2) + 21) & 127;
  int stage_v_99_1 = ((sub_step_99_1 * 2) + pub_r000573_3_1) & 127;
  int stage_v_99_2 = ((sub_step_99_2 * 2) + pub_r000573_3_2) & 127;
  st_var_3_1.buffer[0] = stage_v_99_1 & 15;
  st_var_3_2.buffer[0] = stage_v_99_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int sub_step_100_1 = ((sec_r000573_4_1 + pub_r000573_13_1) + 14) & 127;
  int sub_step_100_2 = ((sec_r000573_4_2 + pub_r000573_13_2) + 14) & 127;
  int stage_v_100_1 = ((sub_step_100_1 * 2) + pub_r000573_16_1) & 127;
  int stage_v_100_2 = ((sub_step_100_2 * 2) + pub_r000573_16_2) & 127;
  st_var_0_1.buffer[1] = stage_v_100_1 & 15;
  st_var_0_2.buffer[1] = stage_v_100_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int sub_step_101_1 = ((stage_v_91_1 + pub_r000573_10_1) + 9) & 127;
  int sub_step_101_2 = ((stage_v_91_2 + pub_r000573_10_2) + 9) & 127;
  int stage_v_101_1 = ((sub_step_101_1 * 2) + pub_r000573_11_1) & 127;
  int stage_v_101_2 = ((sub_step_101_2 * 2) + pub_r000573_11_2) & 127;
  st_var_1_1.buffer[2] = stage_v_101_1 & 15;
  st_var_1_2.buffer[2] = stage_v_101_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int sub_step_102_1 = ((stage_v_94_1 + pub_r000573_5_1) + 33) & 127;
  int sub_step_102_2 = ((stage_v_94_2 + pub_r000573_5_2) + 33) & 127;
  int stage_v_102_1 = ((sub_step_102_1 * 2) + pub_r000573_2_1) & 127;
  int stage_v_102_2 = ((sub_step_102_2 * 2) + pub_r000573_2_2) & 127;
  st_var_2_1.buffer[0] = stage_v_102_1 & 15;
  st_var_2_2.buffer[0] = stage_v_102_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int sub_step_103_1 = ((sec_r000573_2_1 + pub_r000573_8_1) + 20) & 127;
  int sub_step_103_2 = ((sec_r000573_2_2 + pub_r000573_8_2) + 20) & 127;
  int stage_v_103_1 = ((sub_step_103_1 * 2) + pub_r000573_6_1) & 127;
  int stage_v_103_2 = ((sub_step_103_2 * 2) + pub_r000573_6_2) & 127;
  st_var_3_1.buffer[1] = stage_v_103_1 & 15;
  st_var_3_2.buffer[1] = stage_v_103_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int sub_step_104_1 = ((sec_r000573_0_1 + pub_r000573_0_1) + 34) & 127;
  int sub_step_104_2 = ((sec_r000573_0_2 + pub_r000573_0_2) + 34) & 127;
  int stage_v_104_1 = ((sub_step_104_1 * 2) + pub_r000573_10_1) & 127;
  int stage_v_104_2 = ((sub_step_104_2 * 2) + pub_r000573_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_104_1 & 15;
  st_var_0_2.buffer[2] = stage_v_104_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int sub_step_105_1 = ((sec_r000573_17_1 + pub_r000573_14_1) + 32) & 127;
  int sub_step_105_2 = ((sec_r000573_17_2 + pub_r000573_14_2) + 32) & 127;
  int stage_v_105_1 = ((sub_step_105_1 * 2) + pub_r000573_1_1) & 127;
  int stage_v_105_2 = ((sub_step_105_2 * 2) + pub_r000573_1_2) & 127;
  st_var_1_1.buffer[0] = stage_v_105_1 & 15;
  st_var_1_2.buffer[0] = stage_v_105_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int sub_step_106_1 = ((stage_v_94_1 + pub_r000573_9_1) + 11) & 127;
  int sub_step_106_2 = ((stage_v_94_2 + pub_r000573_9_2) + 11) & 127;
  int stage_v_106_1 = ((sub_step_106_1 * 2) + pub_r000573_10_1) & 127;
  int stage_v_106_2 = ((sub_step_106_2 * 2) + pub_r000573_10_2) & 127;
  st_var_2_1.buffer[1] = stage_v_106_1 & 15;
  st_var_2_2.buffer[1] = stage_v_106_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int sub_step_107_1 = ((sec_r000573_17_1 + pub_r000573_21_1) + 32) & 127;
  int sub_step_107_2 = ((sec_r000573_17_2 + pub_r000573_21_2) + 32) & 127;
  int stage_v_107_1 = ((sub_step_107_1 * 2) + pub_r000573_3_1) & 127;
  int stage_v_107_2 = ((sub_step_107_2 * 2) + pub_r000573_3_2) & 127;
  st_var_3_1.buffer[2] = stage_v_107_1 & 15;
  st_var_3_2.buffer[2] = stage_v_107_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int sub_step_108_1 = ((sub_step_79_1 + pub_r000573_0_1) + 29) & 127;
  int sub_step_108_2 = ((sub_step_79_2 + pub_r000573_0_2) + 29) & 127;
  int stage_v_108_1 = ((sub_step_108_1 * 2) + pub_r000573_15_1) & 127;
  int stage_v_108_2 = ((sub_step_108_2 * 2) + pub_r000573_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_108_1 & 15;
  st_var_0_2.buffer[0] = stage_v_108_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int sub_step_109_1 = ((stage_v_86_1 + pub_r000573_19_1) + 29) & 127;
  int sub_step_109_2 = ((stage_v_86_2 + pub_r000573_19_2) + 29) & 127;
  int stage_v_109_1 = ((sub_step_109_1 * 2) + pub_r000573_7_1) & 127;
  int stage_v_109_2 = ((sub_step_109_2 * 2) + pub_r000573_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_109_1 & 15;
  st_var_1_2.buffer[1] = stage_v_109_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int sub_step_110_1 = ((sec_r000573_14_1 + pub_r000573_19_1) + 11) & 127;
  int sub_step_110_2 = ((sec_r000573_14_2 + pub_r000573_19_2) + 11) & 127;
  int stage_v_110_1 = ((sub_step_110_1 * 2) + pub_r000573_15_1) & 127;
  int stage_v_110_2 = ((sub_step_110_2 * 2) + pub_r000573_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_110_1 & 15;
  st_var_2_2.buffer[2] = stage_v_110_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int sub_step_111_1 = ((stage_v_87_1 + pub_r000573_17_1) + 10) & 127;
  int sub_step_111_2 = ((stage_v_87_2 + pub_r000573_17_2) + 10) & 127;
  int stage_v_111_1 = ((sub_step_111_1 * 2) + pub_r000573_0_1) & 127;
  int stage_v_111_2 = ((sub_step_111_2 * 2) + pub_r000573_0_2) & 127;
  st_var_3_1.buffer[0] = stage_v_111_1 & 15;
  st_var_3_2.buffer[0] = stage_v_111_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int sub_step_112_1 = ((sec_r000573_1_1 + pub_r000573_4_1) + 21) & 127;
  int sub_step_112_2 = ((sec_r000573_1_2 + pub_r000573_4_2) + 21) & 127;
  int stage_v_112_1 = ((sub_step_112_1 * 2) + pub_r000573_18_1) & 127;
  int stage_v_112_2 = ((sub_step_112_2 * 2) + pub_r000573_18_2) & 127;
  st_var_0_1.buffer[1] = stage_v_112_1 & 15;
  st_var_0_2.buffer[1] = stage_v_112_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int sub_step_113_1 = ((sec_r000573_1_1 + pub_r000573_19_1) + 29) & 127;
  int sub_step_113_2 = ((sec_r000573_1_2 + pub_r000573_19_2) + 29) & 127;
  int stage_v_113_1 = ((sub_step_113_1 * 2) + pub_r000573_17_1) & 127;
  int stage_v_113_2 = ((sub_step_113_2 * 2) + pub_r000573_17_2) & 127;
  st_var_1_1.buffer[2] = stage_v_113_1 & 15;
  st_var_1_2.buffer[2] = stage_v_113_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int sub_step_114_1 = ((sub_step_94_1 + pub_r000573_7_1) + 22) & 127;
  int sub_step_114_2 = ((sub_step_94_2 + pub_r000573_7_2) + 22) & 127;
  int stage_v_114_1 = ((sub_step_114_1 * 2) + pub_r000573_13_1) & 127;
  int stage_v_114_2 = ((sub_step_114_2 * 2) + pub_r000573_13_2) & 127;
  st_var_2_1.buffer[0] = stage_v_114_1 & 15;
  st_var_2_2.buffer[0] = stage_v_114_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int sub_step_115_1 = ((sub_step_78_1 + pub_r000573_0_1) + 23) & 127;
  int sub_step_115_2 = ((sub_step_78_2 + pub_r000573_0_2) + 23) & 127;
  int stage_v_115_1 = ((sub_step_115_1 * 2) + pub_r000573_1_1) & 127;
  int stage_v_115_2 = ((sub_step_115_2 * 2) + pub_r000573_1_2) & 127;
  st_var_3_1.buffer[1] = stage_v_115_1 & 15;
  st_var_3_2.buffer[1] = stage_v_115_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int sub_step_116_1 = ((sub_step_84_1 + pub_r000573_11_1) + 32) & 127;
  int sub_step_116_2 = ((sub_step_84_2 + pub_r000573_11_2) + 32) & 127;
  int stage_v_116_1 = ((sub_step_116_1 * 2) + pub_r000573_3_1) & 127;
  int stage_v_116_2 = ((sub_step_116_2 * 2) + pub_r000573_3_2) & 127;
  st_var_0_1.buffer[2] = stage_v_116_1 & 15;
  st_var_0_2.buffer[2] = stage_v_116_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int sub_step_117_1 = ((sub_step_86_1 + pub_r000573_16_1) + 9) & 127;
  int sub_step_117_2 = ((sub_step_86_2 + pub_r000573_16_2) + 9) & 127;
  int stage_v_117_1 = ((sub_step_117_1 * 2) + pub_r000573_19_1) & 127;
  int stage_v_117_2 = ((sub_step_117_2 * 2) + pub_r000573_19_2) & 127;
  st_var_1_1.buffer[0] = stage_v_117_1 & 15;
  st_var_1_2.buffer[0] = stage_v_117_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int sub_step_118_1 = ((sub_step_85_1 + pub_r000573_19_1) + 33) & 127;
  int sub_step_118_2 = ((sub_step_85_2 + pub_r000573_19_2) + 33) & 127;
  int stage_v_118_1 = ((sub_step_118_1 * 2) + pub_r000573_3_1) & 127;
  int stage_v_118_2 = ((sub_step_118_2 * 2) + pub_r000573_3_2) & 127;
  st_var_2_1.buffer[1] = stage_v_118_1 & 15;
  st_var_2_2.buffer[1] = stage_v_118_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int sub_step_119_1 = ((stage_v_84_1 + pub_r000573_5_1) + 7) & 127;
  int sub_step_119_2 = ((stage_v_84_2 + pub_r000573_5_2) + 7) & 127;
  int stage_v_119_1 = ((sub_step_119_1 * 2) + pub_r000573_16_1) & 127;
  int stage_v_119_2 = ((sub_step_119_2 * 2) + pub_r000573_16_2) & 127;
  st_var_3_1.buffer[2] = stage_v_119_1 & 15;
  st_var_3_2.buffer[2] = stage_v_119_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int sub_step_120_1 = ((stage_v_105_1 + pub_r000573_2_1) + 18) & 127;
  int sub_step_120_2 = ((stage_v_105_2 + pub_r000573_2_2) + 18) & 127;
  int stage_v_120_1 = ((sub_step_120_1 * 2) + pub_r000573_13_1) & 127;
  int stage_v_120_2 = ((sub_step_120_2 * 2) + pub_r000573_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_120_1 & 15;
  st_var_0_2.buffer[0] = stage_v_120_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int sub_step_121_1 = ((sec_r000573_2_1 + pub_r000573_10_1) + 26) & 127;
  int sub_step_121_2 = ((sec_r000573_2_2 + pub_r000573_10_2) + 26) & 127;
  int stage_v_121_1 = ((sub_step_121_1 * 2) + pub_r000573_7_1) & 127;
  int stage_v_121_2 = ((sub_step_121_2 * 2) + pub_r000573_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_121_1 & 15;
  st_var_1_2.buffer[1] = stage_v_121_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int sub_step_122_1 = ((sec_r000573_20_1 + pub_r000573_16_1) + 8) & 127;
  int sub_step_122_2 = ((sec_r000573_20_2 + pub_r000573_16_2) + 8) & 127;
  int stage_v_122_1 = ((sub_step_122_1 * 2) + pub_r000573_3_1) & 127;
  int stage_v_122_2 = ((sub_step_122_2 * 2) + pub_r000573_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_122_1 & 15;
  st_var_2_2.buffer[2] = stage_v_122_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int sub_step_123_1 = ((sec_r000573_6_1 + pub_r000573_3_1) + 6) & 127;
  int sub_step_123_2 = ((sec_r000573_6_2 + pub_r000573_3_2) + 6) & 127;
  int stage_v_123_1 = ((sub_step_123_1 * 2) + pub_r000573_15_1) & 127;
  int stage_v_123_2 = ((sub_step_123_2 * 2) + pub_r000573_15_2) & 127;
  st_var_3_1.buffer[0] = stage_v_123_1 & 15;
  st_var_3_2.buffer[0] = stage_v_123_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int sub_step_124_1 = ((sec_r000573_7_1 + pub_r000573_6_1) + 15) & 127;
  int sub_step_124_2 = ((sec_r000573_7_2 + pub_r000573_6_2) + 15) & 127;
  int stage_v_124_1 = ((sub_step_124_1 * 2) + pub_r000573_2_1) & 127;
  int stage_v_124_2 = ((sub_step_124_2 * 2) + pub_r000573_2_2) & 127;
  st_var_0_1.buffer[1] = stage_v_124_1 & 15;
  st_var_0_2.buffer[1] = stage_v_124_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int sub_step_125_1 = ((stage_v_118_1 + pub_r000573_1_1) + 19) & 127;
  int sub_step_125_2 = ((stage_v_118_2 + pub_r000573_1_2) + 19) & 127;
  int stage_v_125_1 = ((sub_step_125_1 * 2) + pub_r000573_20_1) & 127;
  int stage_v_125_2 = ((sub_step_125_2 * 2) + pub_r000573_20_2) & 127;
  st_var_1_1.buffer[2] = stage_v_125_1 & 15;
  st_var_1_2.buffer[2] = stage_v_125_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int sub_step_126_1 = ((stage_v_122_1 + pub_r000573_7_1) + 11) & 127;
  int sub_step_126_2 = ((stage_v_122_2 + pub_r000573_7_2) + 11) & 127;
  int stage_v_126_1 = ((sub_step_126_1 * 2) + pub_r000573_12_1) & 127;
  int stage_v_126_2 = ((sub_step_126_2 * 2) + pub_r000573_12_2) & 127;
  st_var_2_1.buffer[0] = stage_v_126_1 & 15;
  st_var_2_2.buffer[0] = stage_v_126_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int sub_step_127_1 = ((sec_r000573_7_1 + pub_r000573_12_1) + 30) & 127;
  int sub_step_127_2 = ((sec_r000573_7_2 + pub_r000573_12_2) + 30) & 127;
  int stage_v_127_1 = ((sub_step_127_1 * 2) + pub_r000573_10_1) & 127;
  int stage_v_127_2 = ((sub_step_127_2 * 2) + pub_r000573_10_2) & 127;
  st_var_3_1.buffer[1] = stage_v_127_1 & 15;
  st_var_3_2.buffer[1] = stage_v_127_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int sub_step_128_1 = ((stage_v_92_1 + pub_r000573_19_1) + 25) & 127;
  int sub_step_128_2 = ((stage_v_92_2 + pub_r000573_19_2) + 25) & 127;
  int stage_v_128_1 = ((sub_step_128_1 * 2) + pub_r000573_2_1) & 127;
  int stage_v_128_2 = ((sub_step_128_2 * 2) + pub_r000573_2_2) & 127;
  st_var_0_1.buffer[2] = stage_v_128_1 & 15;
  st_var_0_2.buffer[2] = stage_v_128_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int sub_step_129_1 = ((sec_r000573_15_1 + pub_r000573_11_1) + 22) & 127;
  int sub_step_129_2 = ((sec_r000573_15_2 + pub_r000573_11_2) + 22) & 127;
  int stage_v_129_1 = ((sub_step_129_1 * 2) + pub_r000573_5_1) & 127;
  int stage_v_129_2 = ((sub_step_129_2 * 2) + pub_r000573_5_2) & 127;
  st_var_1_1.buffer[0] = stage_v_129_1 & 15;
  st_var_1_2.buffer[0] = stage_v_129_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int sub_step_130_1 = ((sub_step_99_1 + pub_r000573_20_1) + 10) & 127;
  int sub_step_130_2 = ((sub_step_99_2 + pub_r000573_20_2) + 10) & 127;
  int stage_v_130_1 = ((sub_step_130_1 * 2) + pub_r000573_3_1) & 127;
  int stage_v_130_2 = ((sub_step_130_2 * 2) + pub_r000573_3_2) & 127;
  st_var_2_1.buffer[1] = stage_v_130_1 & 15;
  st_var_2_2.buffer[1] = stage_v_130_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int sub_step_131_1 = ((sec_r000573_19_1 + pub_r000573_17_1) + 10) & 127;
  int sub_step_131_2 = ((sec_r000573_19_2 + pub_r000573_17_2) + 10) & 127;
  int stage_v_131_1 = ((sub_step_131_1 * 2) + pub_r000573_1_1) & 127;
  int stage_v_131_2 = ((sub_step_131_2 * 2) + pub_r000573_1_2) & 127;
  st_var_3_1.buffer[2] = stage_v_131_1 & 15;
  st_var_3_2.buffer[2] = stage_v_131_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int sub_step_132_1 = ((stage_v_119_1 + pub_r000573_6_1) + 30) & 127;
  int sub_step_132_2 = ((stage_v_119_2 + pub_r000573_6_2) + 30) & 127;
  int stage_v_132_1 = ((sub_step_132_1 * 2) + pub_r000573_8_1) & 127;
  int stage_v_132_2 = ((sub_step_132_2 * 2) + pub_r000573_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_132_1 & 15;
  st_var_0_2.buffer[0] = stage_v_132_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int sub_step_133_1 = ((sec_r000573_2_1 + pub_r000573_21_1) + 13) & 127;
  int sub_step_133_2 = ((sec_r000573_2_2 + pub_r000573_21_2) + 13) & 127;
  int stage_v_133_1 = ((sub_step_133_1 * 2) + pub_r000573_3_1) & 127;
  int stage_v_133_2 = ((sub_step_133_2 * 2) + pub_r000573_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_133_1 & 15;
  st_var_1_2.buffer[1] = stage_v_133_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int sub_step_134_1 = ((stage_v_93_1 + pub_r000573_17_1) + 25) & 127;
  int sub_step_134_2 = ((stage_v_93_2 + pub_r000573_17_2) + 25) & 127;
  int stage_v_134_1 = ((sub_step_134_1 * 2) + pub_r000573_10_1) & 127;
  int stage_v_134_2 = ((sub_step_134_2 * 2) + pub_r000573_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_134_1 & 15;
  st_var_2_2.buffer[2] = stage_v_134_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int sub_step_135_1 = ((sec_r000573_19_1 + pub_r000573_18_1) + 26) & 127;
  int sub_step_135_2 = ((sec_r000573_19_2 + pub_r000573_18_2) + 26) & 127;
  int stage_v_135_1 = ((sub_step_135_1 * 2) + pub_r000573_12_1) & 127;
  int stage_v_135_2 = ((sub_step_135_2 * 2) + pub_r000573_12_2) & 127;
  st_var_3_1.buffer[0] = stage_v_135_1 & 15;
  st_var_3_2.buffer[0] = stage_v_135_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int sub_step_136_1 = ((sub_step_87_1 + pub_r000573_20_1) + 22) & 127;
  int sub_step_136_2 = ((sub_step_87_2 + pub_r000573_20_2) + 22) & 127;
  int stage_v_136_1 = ((sub_step_136_1 * 2) + pub_r000573_11_1) & 127;
  int stage_v_136_2 = ((sub_step_136_2 * 2) + pub_r000573_11_2) & 127;
  st_var_0_1.buffer[1] = stage_v_136_1 & 15;
  st_var_0_2.buffer[1] = stage_v_136_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int sub_step_137_1 = ((stage_v_92_1 + pub_r000573_14_1) + 16) & 127;
  int sub_step_137_2 = ((stage_v_92_2 + pub_r000573_14_2) + 16) & 127;
  int stage_v_137_1 = ((sub_step_137_1 * 2) + pub_r000573_11_1) & 127;
  int stage_v_137_2 = ((sub_step_137_2 * 2) + pub_r000573_11_2) & 127;
  st_var_1_1.buffer[2] = stage_v_137_1 & 15;
  st_var_1_2.buffer[2] = stage_v_137_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int sub_step_138_1 = ((sec_r000573_13_1 + pub_r000573_12_1) + 7) & 127;
  int sub_step_138_2 = ((sec_r000573_13_2 + pub_r000573_12_2) + 7) & 127;
  int stage_v_138_1 = ((sub_step_138_1 * 2) + pub_r000573_9_1) & 127;
  int stage_v_138_2 = ((sub_step_138_2 * 2) + pub_r000573_9_2) & 127;
  st_var_2_1.buffer[0] = stage_v_138_1 & 15;
  st_var_2_2.buffer[0] = stage_v_138_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int sub_step_139_1 = ((sub_step_84_1 + pub_r000573_20_1) + 22) & 127;
  int sub_step_139_2 = ((sub_step_84_2 + pub_r000573_20_2) + 22) & 127;
  int stage_v_139_1 = ((sub_step_139_1 * 2) + pub_r000573_18_1) & 127;
  int stage_v_139_2 = ((sub_step_139_2 * 2) + pub_r000573_18_2) & 127;
  st_var_3_1.buffer[1] = stage_v_139_1 & 15;
  st_var_3_2.buffer[1] = stage_v_139_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int sub_step_140_1 = ((sec_r000573_6_1 + pub_r000573_11_1) + 12) & 127;
  int sub_step_140_2 = ((sec_r000573_6_2 + pub_r000573_11_2) + 12) & 127;
  int stage_v_140_1 = ((sub_step_140_1 * 2) + pub_r000573_9_1) & 127;
  int stage_v_140_2 = ((sub_step_140_2 * 2) + pub_r000573_9_2) & 127;
  st_var_0_1.buffer[2] = stage_v_140_1 & 15;
  st_var_0_2.buffer[2] = stage_v_140_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int sub_step_141_1 = ((sec_r000573_8_1 + pub_r000573_0_1) + 16) & 127;
  int sub_step_141_2 = ((sec_r000573_8_2 + pub_r000573_0_2) + 16) & 127;
  int stage_v_141_1 = ((sub_step_141_1 * 2) + pub_r000573_9_1) & 127;
  int stage_v_141_2 = ((sub_step_141_2 * 2) + pub_r000573_9_2) & 127;
  st_var_1_1.buffer[0] = stage_v_141_1 & 15;
  st_var_1_2.buffer[0] = stage_v_141_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int sub_step_142_1 = ((sec_r000573_17_1 + pub_r000573_3_1) + 12) & 127;
  int sub_step_142_2 = ((sec_r000573_17_2 + pub_r000573_3_2) + 12) & 127;
  int stage_v_142_1 = ((sub_step_142_1 * 2) + pub_r000573_16_1) & 127;
  int stage_v_142_2 = ((sub_step_142_2 * 2) + pub_r000573_16_2) & 127;
  st_var_2_1.buffer[1] = stage_v_142_1 & 15;
  st_var_2_2.buffer[1] = stage_v_142_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int sub_step_143_1 = ((sub_step_139_1 + pub_r000573_1_1) + 29) & 127;
  int sub_step_143_2 = ((sub_step_139_2 + pub_r000573_1_2) + 29) & 127;
  int stage_v_143_1 = ((sub_step_143_1 * 2) + pub_r000573_15_1) & 127;
  int stage_v_143_2 = ((sub_step_143_2 * 2) + pub_r000573_15_2) & 127;
  st_var_3_1.buffer[2] = stage_v_143_1 & 15;
  st_var_3_2.buffer[2] = stage_v_143_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int sub_step_144_1 = ((stage_v_131_1 + pub_r000573_16_1) + 34) & 127;
  int sub_step_144_2 = ((stage_v_131_2 + pub_r000573_16_2) + 34) & 127;
  int stage_v_144_1 = ((sub_step_144_1 * 2) + pub_r000573_18_1) & 127;
  int stage_v_144_2 = ((sub_step_144_2 * 2) + pub_r000573_18_2) & 127;
  st_var_0_1.buffer[0] = stage_v_144_1 & 15;
  st_var_0_2.buffer[0] = stage_v_144_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int sub_step_145_1 = ((stage_v_143_1 + pub_r000573_14_1) + 29) & 127;
  int sub_step_145_2 = ((stage_v_143_2 + pub_r000573_14_2) + 29) & 127;
  int stage_v_145_1 = ((sub_step_145_1 * 2) + pub_r000573_10_1) & 127;
  int stage_v_145_2 = ((sub_step_145_2 * 2) + pub_r000573_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_145_1 & 15;
  st_var_1_2.buffer[1] = stage_v_145_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int sub_step_146_1 = ((stage_v_125_1 + pub_r000573_6_1) + 30) & 127;
  int sub_step_146_2 = ((stage_v_125_2 + pub_r000573_6_2) + 30) & 127;
  int stage_v_146_1 = ((sub_step_146_1 * 2) + pub_r000573_10_1) & 127;
  int stage_v_146_2 = ((sub_step_146_2 * 2) + pub_r000573_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_146_1 & 15;
  st_var_2_2.buffer[2] = stage_v_146_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int sub_step_147_1 = ((sec_r000573_6_1 + pub_r000573_0_1) + 28) & 127;
  int sub_step_147_2 = ((sec_r000573_6_2 + pub_r000573_0_2) + 28) & 127;
  int stage_v_147_1 = ((sub_step_147_1 * 2) + pub_r000573_11_1) & 127;
  int stage_v_147_2 = ((sub_step_147_2 * 2) + pub_r000573_11_2) & 127;
  st_var_3_1.buffer[0] = stage_v_147_1 & 15;
  st_var_3_2.buffer[0] = stage_v_147_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int sub_step_148_1 = ((stage_v_146_1 + pub_r000573_3_1) + 23) & 127;
  int sub_step_148_2 = ((stage_v_146_2 + pub_r000573_3_2) + 23) & 127;
  int stage_v_148_1 = ((sub_step_148_1 * 2) + pub_r000573_8_1) & 127;
  int stage_v_148_2 = ((sub_step_148_2 * 2) + pub_r000573_8_2) & 127;
  st_var_0_1.buffer[1] = stage_v_148_1 & 15;
  st_var_0_2.buffer[1] = stage_v_148_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int sub_step_149_1 = ((sec_r000573_3_1 + pub_r000573_3_1) + 16) & 127;
  int sub_step_149_2 = ((sec_r000573_3_2 + pub_r000573_3_2) + 16) & 127;
  int stage_v_149_1 = ((sub_step_149_1 * 2) + pub_r000573_11_1) & 127;
  int stage_v_149_2 = ((sub_step_149_2 * 2) + pub_r000573_11_2) & 127;
  st_var_1_1.buffer[2] = stage_v_149_1 & 15;
  st_var_1_2.buffer[2] = stage_v_149_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int sub_step_150_1 = ((stage_v_93_1 + pub_r000573_18_1) + 13) & 127;
  int sub_step_150_2 = ((stage_v_93_2 + pub_r000573_18_2) + 13) & 127;
  int stage_v_150_1 = ((sub_step_150_1 * 2) + pub_r000573_9_1) & 127;
  int stage_v_150_2 = ((sub_step_150_2 * 2) + pub_r000573_9_2) & 127;
  st_var_2_1.buffer[0] = stage_v_150_1 & 15;
  st_var_2_2.buffer[0] = stage_v_150_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int sub_step_151_1 = ((sec_r000573_20_1 + pub_r000573_7_1) + 34) & 127;
  int sub_step_151_2 = ((sec_r000573_20_2 + pub_r000573_7_2) + 34) & 127;
  int stage_v_151_1 = ((sub_step_151_1 * 2) + pub_r000573_21_1) & 127;
  int stage_v_151_2 = ((sub_step_151_2 * 2) + pub_r000573_21_2) & 127;
  st_var_3_1.buffer[1] = stage_v_151_1 & 15;
  st_var_3_2.buffer[1] = stage_v_151_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int sub_step_152_1 = ((sec_r000573_4_1 + pub_r000573_2_1) + 29) & 127;
  int sub_step_152_2 = ((sec_r000573_4_2 + pub_r000573_2_2) + 29) & 127;
  int stage_v_152_1 = ((sub_step_152_1 * 2) + pub_r000573_15_1) & 127;
  int stage_v_152_2 = ((sub_step_152_2 * 2) + pub_r000573_15_2) & 127;
  st_var_0_1.buffer[2] = stage_v_152_1 & 15;
  st_var_0_2.buffer[2] = stage_v_152_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int sub_step_153_1 = ((stage_v_115_1 + pub_r000573_18_1) + 27) & 127;
  int sub_step_153_2 = ((stage_v_115_2 + pub_r000573_18_2) + 27) & 127;
  int stage_v_153_1 = ((sub_step_153_1 * 2) + pub_r000573_8_1) & 127;
  int stage_v_153_2 = ((sub_step_153_2 * 2) + pub_r000573_8_2) & 127;
  st_var_1_1.buffer[0] = stage_v_153_1 & 15;
  st_var_1_2.buffer[0] = stage_v_153_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int sub_step_154_1 = ((sec_r000573_5_1 + pub_r000573_15_1) + 10) & 127;
  int sub_step_154_2 = ((sec_r000573_5_2 + pub_r000573_15_2) + 10) & 127;
  int stage_v_154_1 = ((sub_step_154_1 * 2) + pub_r000573_17_1) & 127;
  int stage_v_154_2 = ((sub_step_154_2 * 2) + pub_r000573_17_2) & 127;
  st_var_2_1.buffer[1] = stage_v_154_1 & 15;
  st_var_2_2.buffer[1] = stage_v_154_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int sub_step_155_1 = ((sec_r000573_2_1 + pub_r000573_1_1) + 17) & 127;
  int sub_step_155_2 = ((sec_r000573_2_2 + pub_r000573_1_2) + 17) & 127;
  int stage_v_155_1 = ((sub_step_155_1 * 2) + pub_r000573_8_1) & 127;
  int stage_v_155_2 = ((sub_step_155_2 * 2) + pub_r000573_8_2) & 127;
  st_var_3_1.buffer[2] = stage_v_155_1 & 15;
  st_var_3_2.buffer[2] = stage_v_155_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int sub_step_156_1 = ((sec_r000573_3_1 + pub_r000573_15_1) + 35) & 127;
  int sub_step_156_2 = ((sec_r000573_3_2 + pub_r000573_15_2) + 35) & 127;
  int stage_v_156_1 = ((sub_step_156_1 * 2) + pub_r000573_14_1) & 127;
  int stage_v_156_2 = ((sub_step_156_2 * 2) + pub_r000573_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_156_1 & 15;
  st_var_0_2.buffer[0] = stage_v_156_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int sub_step_157_1 = ((sec_r000573_0_1 + pub_r000573_17_1) + 26) & 127;
  int sub_step_157_2 = ((sec_r000573_0_2 + pub_r000573_17_2) + 26) & 127;
  int stage_v_157_1 = ((sub_step_157_1 * 2) + pub_r000573_9_1) & 127;
  int stage_v_157_2 = ((sub_step_157_2 * 2) + pub_r000573_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_157_1 & 15;
  st_var_1_2.buffer[1] = stage_v_157_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int sub_step_158_1 = ((sub_step_124_1 + pub_r000573_16_1) + 16) & 127;
  int sub_step_158_2 = ((sub_step_124_2 + pub_r000573_16_2) + 16) & 127;
  int stage_v_158_1 = ((sub_step_158_1 * 2) + pub_r000573_0_1) & 127;
  int stage_v_158_2 = ((sub_step_158_2 * 2) + pub_r000573_0_2) & 127;
  st_var_2_1.buffer[2] = stage_v_158_1 & 15;
  st_var_2_2.buffer[2] = stage_v_158_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int sub_step_159_1 = ((stage_v_118_1 + pub_r000573_19_1) + 28) & 127;
  int sub_step_159_2 = ((stage_v_118_2 + pub_r000573_19_2) + 28) & 127;
  int stage_v_159_1 = ((sub_step_159_1 * 2) + pub_r000573_15_1) & 127;
  int stage_v_159_2 = ((sub_step_159_2 * 2) + pub_r000573_15_2) & 127;
  st_var_3_1.buffer[0] = stage_v_159_1 & 15;
  st_var_3_2.buffer[0] = stage_v_159_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int sub_step_160_1 = ((stage_v_126_1 + pub_r000573_10_1) + 30) & 127;
  int sub_step_160_2 = ((stage_v_126_2 + pub_r000573_10_2) + 30) & 127;
  int stage_v_160_1 = ((sub_step_160_1 * 2) + pub_r000573_3_1) & 127;
  int stage_v_160_2 = ((sub_step_160_2 * 2) + pub_r000573_3_2) & 127;
  st_var_0_1.buffer[1] = stage_v_160_1 & 15;
  st_var_0_2.buffer[1] = stage_v_160_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int sub_step_161_1 = ((sec_r000573_6_1 + pub_r000573_12_1) + 34) & 127;
  int sub_step_161_2 = ((sec_r000573_6_2 + pub_r000573_12_2) + 34) & 127;
  int stage_v_161_1 = ((sub_step_161_1 * 2) + pub_r000573_2_1) & 127;
  int stage_v_161_2 = ((sub_step_161_2 * 2) + pub_r000573_2_2) & 127;
  st_var_1_1.buffer[2] = stage_v_161_1 & 15;
  st_var_1_2.buffer[2] = stage_v_161_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int sub_step_162_1 = ((sub_step_100_1 + pub_r000573_2_1) + 15) & 127;
  int sub_step_162_2 = ((sub_step_100_2 + pub_r000573_2_2) + 15) & 127;
  int stage_v_162_1 = ((sub_step_162_1 * 2) + pub_r000573_17_1) & 127;
  int stage_v_162_2 = ((sub_step_162_2 * 2) + pub_r000573_17_2) & 127;
  st_var_2_1.buffer[0] = stage_v_162_1 & 15;
  st_var_2_2.buffer[0] = stage_v_162_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int sub_step_163_1 = ((sub_step_90_1 + pub_r000573_18_1) + 17) & 127;
  int sub_step_163_2 = ((sub_step_90_2 + pub_r000573_18_2) + 17) & 127;
  int stage_v_163_1 = ((sub_step_163_1 * 2) + pub_r000573_1_1) & 127;
  int stage_v_163_2 = ((sub_step_163_2 * 2) + pub_r000573_1_2) & 127;
  st_var_3_1.buffer[1] = stage_v_163_1 & 15;
  st_var_3_2.buffer[1] = stage_v_163_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int sub_step_164_1 = ((sec_r000573_2_1 + pub_r000573_15_1) + 32) & 127;
  int sub_step_164_2 = ((sec_r000573_2_2 + pub_r000573_15_2) + 32) & 127;
  int stage_v_164_1 = ((sub_step_164_1 * 2) + pub_r000573_10_1) & 127;
  int stage_v_164_2 = ((sub_step_164_2 * 2) + pub_r000573_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_164_1 & 15;
  st_var_0_2.buffer[2] = stage_v_164_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int sub_step_165_1 = ((stage_v_103_1 + pub_r000573_18_1) + 23) & 127;
  int sub_step_165_2 = ((stage_v_103_2 + pub_r000573_18_2) + 23) & 127;
  int stage_v_165_1 = ((sub_step_165_1 * 2) + pub_r000573_20_1) & 127;
  int stage_v_165_2 = ((sub_step_165_2 * 2) + pub_r000573_20_2) & 127;
  st_var_1_1.buffer[0] = stage_v_165_1 & 15;
  st_var_1_2.buffer[0] = stage_v_165_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int sub_step_166_1 = ((sub_step_112_1 + pub_r000573_13_1) + 22) & 127;
  int sub_step_166_2 = ((sub_step_112_2 + pub_r000573_13_2) + 22) & 127;
  int stage_v_166_1 = ((sub_step_166_1 * 2) + pub_r000573_4_1) & 127;
  int stage_v_166_2 = ((sub_step_166_2 * 2) + pub_r000573_4_2) & 127;
  st_var_2_1.buffer[1] = stage_v_166_1 & 15;
  st_var_2_2.buffer[1] = stage_v_166_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int sub_step_167_1 = ((sec_r000573_10_1 + pub_r000573_5_1) + 29) & 127;
  int sub_step_167_2 = ((sec_r000573_10_2 + pub_r000573_5_2) + 29) & 127;
  int stage_v_167_1 = ((sub_step_167_1 * 2) + pub_r000573_5_1) & 127;
  int stage_v_167_2 = ((sub_step_167_2 * 2) + pub_r000573_5_2) & 127;
  st_var_3_1.buffer[2] = stage_v_167_1 & 15;
  st_var_3_2.buffer[2] = stage_v_167_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int sub_step_168_1 = ((sub_step_111_1 + pub_r000573_10_1) + 5) & 127;
  int sub_step_168_2 = ((sub_step_111_2 + pub_r000573_10_2) + 5) & 127;
  int stage_v_168_1 = ((sub_step_168_1 * 2) + pub_r000573_19_1) & 127;
  int stage_v_168_2 = ((sub_step_168_2 * 2) + pub_r000573_19_2) & 127;
  st_var_0_1.buffer[0] = stage_v_168_1 & 15;
  st_var_0_2.buffer[0] = stage_v_168_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int sub_step_169_1 = ((sub_step_155_1 + pub_r000573_9_1) + 16) & 127;
  int sub_step_169_2 = ((sub_step_155_2 + pub_r000573_9_2) + 16) & 127;
  int stage_v_169_1 = ((sub_step_169_1 * 2) + pub_r000573_3_1) & 127;
  int stage_v_169_2 = ((sub_step_169_2 * 2) + pub_r000573_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_169_1 & 15;
  st_var_1_2.buffer[1] = stage_v_169_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int sub_step_170_1 = ((stage_v_121_1 + pub_r000573_20_1) + 13) & 127;
  int sub_step_170_2 = ((stage_v_121_2 + pub_r000573_20_2) + 13) & 127;
  int stage_v_170_1 = ((sub_step_170_1 * 2) + pub_r000573_8_1) & 127;
  int stage_v_170_2 = ((sub_step_170_2 * 2) + pub_r000573_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_170_1 & 15;
  st_var_2_2.buffer[2] = stage_v_170_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int sub_step_171_1 = ((sec_r000573_8_1 + pub_r000573_19_1) + 9) & 127;
  int sub_step_171_2 = ((sec_r000573_8_2 + pub_r000573_19_2) + 9) & 127;
  int stage_v_171_1 = ((sub_step_171_1 * 2) + pub_r000573_1_1) & 127;
  int stage_v_171_2 = ((sub_step_171_2 * 2) + pub_r000573_1_2) & 127;
  st_var_3_1.buffer[0] = stage_v_171_1 & 15;
  st_var_3_2.buffer[0] = stage_v_171_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int sub_step_172_1 = ((sub_step_154_1 + pub_r000573_17_1) + 27) & 127;
  int sub_step_172_2 = ((sub_step_154_2 + pub_r000573_17_2) + 27) & 127;
  int stage_v_172_1 = ((sub_step_172_1 * 2) + pub_r000573_15_1) & 127;
  int stage_v_172_2 = ((sub_step_172_2 * 2) + pub_r000573_15_2) & 127;
  st_var_0_1.buffer[1] = stage_v_172_1 & 15;
  st_var_0_2.buffer[1] = stage_v_172_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int sub_step_173_1 = ((stage_v_87_1 + pub_r000573_10_1) + 9) & 127;
  int sub_step_173_2 = ((stage_v_87_2 + pub_r000573_10_2) + 9) & 127;
  int stage_v_173_1 = ((sub_step_173_1 * 2) + pub_r000573_0_1) & 127;
  int stage_v_173_2 = ((sub_step_173_2 * 2) + pub_r000573_0_2) & 127;
  st_var_1_1.buffer[2] = stage_v_173_1 & 15;
  st_var_1_2.buffer[2] = stage_v_173_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int sub_step_174_1 = ((sub_step_134_1 + pub_r000573_14_1) + 14) & 127;
  int sub_step_174_2 = ((sub_step_134_2 + pub_r000573_14_2) + 14) & 127;
  int stage_v_174_1 = ((sub_step_174_1 * 2) + pub_r000573_9_1) & 127;
  int stage_v_174_2 = ((sub_step_174_2 * 2) + pub_r000573_9_2) & 127;
  st_var_2_1.buffer[0] = stage_v_174_1 & 15;
  st_var_2_2.buffer[0] = stage_v_174_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int sub_step_175_1 = ((stage_v_117_1 + pub_r000573_18_1) + 13) & 127;
  int sub_step_175_2 = ((stage_v_117_2 + pub_r000573_18_2) + 13) & 127;
  int stage_v_175_1 = ((sub_step_175_1 * 2) + pub_r000573_7_1) & 127;
  int stage_v_175_2 = ((sub_step_175_2 * 2) + pub_r000573_7_2) & 127;
  st_var_3_1.buffer[1] = stage_v_175_1 & 15;
  st_var_3_2.buffer[1] = stage_v_175_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int sub_step_176_1 = ((sec_r000573_6_1 + pub_r000573_2_1) + 24) & 127;
  int sub_step_176_2 = ((sec_r000573_6_2 + pub_r000573_2_2) + 24) & 127;
  int stage_v_176_1 = ((sub_step_176_1 * 2) + pub_r000573_21_1) & 127;
  int stage_v_176_2 = ((sub_step_176_2 * 2) + pub_r000573_21_2) & 127;
  st_var_0_1.buffer[2] = stage_v_176_1 & 15;
  st_var_0_2.buffer[2] = stage_v_176_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int sub_step_177_1 = ((sub_step_139_1 + pub_r000573_15_1) + 6) & 127;
  int sub_step_177_2 = ((sub_step_139_2 + pub_r000573_15_2) + 6) & 127;
  int stage_v_177_1 = ((sub_step_177_1 * 2) + pub_r000573_0_1) & 127;
  int stage_v_177_2 = ((sub_step_177_2 * 2) + pub_r000573_0_2) & 127;
  st_var_1_1.buffer[0] = stage_v_177_1 & 15;
  st_var_1_2.buffer[0] = stage_v_177_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int sub_step_178_1 = ((sub_step_168_1 + pub_r000573_12_1) + 25) & 127;
  int sub_step_178_2 = ((sub_step_168_2 + pub_r000573_12_2) + 25) & 127;
  int stage_v_178_1 = ((sub_step_178_1 * 2) + pub_r000573_5_1) & 127;
  int stage_v_178_2 = ((sub_step_178_2 * 2) + pub_r000573_5_2) & 127;
  st_var_2_1.buffer[1] = stage_v_178_1 & 15;
  st_var_2_2.buffer[1] = stage_v_178_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int sub_step_179_1 = ((stage_v_142_1 + pub_r000573_21_1) + 25) & 127;
  int sub_step_179_2 = ((stage_v_142_2 + pub_r000573_21_2) + 25) & 127;
  int stage_v_179_1 = ((sub_step_179_1 * 2) + pub_r000573_14_1) & 127;
  int stage_v_179_2 = ((sub_step_179_2 * 2) + pub_r000573_14_2) & 127;
  st_var_3_1.buffer[2] = stage_v_179_1 & 15;
  st_var_3_2.buffer[2] = stage_v_179_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int sub_step_180_1 = ((sub_step_96_1 + pub_r000573_5_1) + 9) & 127;
  int sub_step_180_2 = ((sub_step_96_2 + pub_r000573_5_2) + 9) & 127;
  int stage_v_180_1 = ((sub_step_180_1 * 2) + pub_r000573_9_1) & 127;
  int stage_v_180_2 = ((sub_step_180_2 * 2) + pub_r000573_9_2) & 127;
  st_var_0_1.buffer[0] = stage_v_180_1 & 15;
  st_var_0_2.buffer[0] = stage_v_180_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int sub_step_181_1 = ((stage_v_135_1 + pub_r000573_7_1) + 12) & 127;
  int sub_step_181_2 = ((stage_v_135_2 + pub_r000573_7_2) + 12) & 127;
  int stage_v_181_1 = ((sub_step_181_1 * 2) + pub_r000573_18_1) & 127;
  int stage_v_181_2 = ((sub_step_181_2 * 2) + pub_r000573_18_2) & 127;
  st_var_1_1.buffer[1] = stage_v_181_1 & 15;
  st_var_1_2.buffer[1] = stage_v_181_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int sub_step_182_1 = ((stage_v_121_1 + pub_r000573_16_1) + 11) & 127;
  int sub_step_182_2 = ((stage_v_121_2 + pub_r000573_16_2) + 11) & 127;
  int stage_v_182_1 = ((sub_step_182_1 * 2) + pub_r000573_9_1) & 127;
  int stage_v_182_2 = ((sub_step_182_2 * 2) + pub_r000573_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_182_1 & 15;
  st_var_2_2.buffer[2] = stage_v_182_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int sub_step_183_1 = ((sub_step_154_1 + pub_r000573_14_1) + 25) & 127;
  int sub_step_183_2 = ((sub_step_154_2 + pub_r000573_14_2) + 25) & 127;
  int stage_v_183_1 = ((sub_step_183_1 * 2) + pub_r000573_7_1) & 127;
  int stage_v_183_2 = ((sub_step_183_2 * 2) + pub_r000573_7_2) & 127;
  st_var_3_1.buffer[0] = stage_v_183_1 & 15;
  st_var_3_2.buffer[0] = stage_v_183_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int sub_step_184_1 = ((sub_step_102_1 + pub_r000573_19_1) + 19) & 127;
  int sub_step_184_2 = ((sub_step_102_2 + pub_r000573_19_2) + 19) & 127;
  int stage_v_184_1 = ((sub_step_184_1 * 2) + pub_r000573_14_1) & 127;
  int stage_v_184_2 = ((sub_step_184_2 * 2) + pub_r000573_14_2) & 127;
  st_var_0_1.buffer[1] = stage_v_184_1 & 15;
  st_var_0_2.buffer[1] = stage_v_184_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int sub_step_185_1 = ((sec_r000573_14_1 + pub_r000573_0_1) + 35) & 127;
  int sub_step_185_2 = ((sec_r000573_14_2 + pub_r000573_0_2) + 35) & 127;
  int stage_v_185_1 = ((sub_step_185_1 * 2) + pub_r000573_18_1) & 127;
  int stage_v_185_2 = ((sub_step_185_2 * 2) + pub_r000573_18_2) & 127;
  st_var_1_1.buffer[2] = stage_v_185_1 & 15;
  st_var_1_2.buffer[2] = stage_v_185_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int sub_step_186_1 = ((sec_r000573_3_1 + pub_r000573_8_1) + 29) & 127;
  int sub_step_186_2 = ((sec_r000573_3_2 + pub_r000573_8_2) + 29) & 127;
  int stage_v_186_1 = ((sub_step_186_1 * 2) + pub_r000573_5_1) & 127;
  int stage_v_186_2 = ((sub_step_186_2 * 2) + pub_r000573_5_2) & 127;
  st_var_2_1.buffer[0] = stage_v_186_1 & 15;
  st_var_2_2.buffer[0] = stage_v_186_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int sub_step_187_1 = ((stage_v_153_1 + pub_r000573_2_1) + 26) & 127;
  int sub_step_187_2 = ((stage_v_153_2 + pub_r000573_2_2) + 26) & 127;
  int stage_v_187_1 = ((sub_step_187_1 * 2) + pub_r000573_15_1) & 127;
  int stage_v_187_2 = ((sub_step_187_2 * 2) + pub_r000573_15_2) & 127;
  st_var_3_1.buffer[1] = stage_v_187_1 & 15;
  st_var_3_2.buffer[1] = stage_v_187_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int sub_step_188_1 = ((stage_v_120_1 + pub_r000573_21_1) + 12) & 127;
  int sub_step_188_2 = ((stage_v_120_2 + pub_r000573_21_2) + 12) & 127;
  int stage_v_188_1 = ((sub_step_188_1 * 2) + pub_r000573_11_1) & 127;
  int stage_v_188_2 = ((sub_step_188_2 * 2) + pub_r000573_11_2) & 127;
  st_var_0_1.buffer[2] = stage_v_188_1 & 15;
  st_var_0_2.buffer[2] = stage_v_188_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int sub_step_189_1 = ((sub_step_132_1 + pub_r000573_13_1) + 23) & 127;
  int sub_step_189_2 = ((sub_step_132_2 + pub_r000573_13_2) + 23) & 127;
  int stage_v_189_1 = ((sub_step_189_1 * 2) + pub_r000573_8_1) & 127;
  int stage_v_189_2 = ((sub_step_189_2 * 2) + pub_r000573_8_2) & 127;
  st_var_1_1.buffer[0] = stage_v_189_1 & 15;
  st_var_1_2.buffer[0] = stage_v_189_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int sub_step_190_1 = ((sec_r000573_7_1 + pub_r000573_8_1) + 7) & 127;
  int sub_step_190_2 = ((sec_r000573_7_2 + pub_r000573_8_2) + 7) & 127;
  int stage_v_190_1 = ((sub_step_190_1 * 2) + pub_r000573_19_1) & 127;
  int stage_v_190_2 = ((sub_step_190_2 * 2) + pub_r000573_19_2) & 127;
  st_var_2_1.buffer[1] = stage_v_190_1 & 15;
  st_var_2_2.buffer[1] = stage_v_190_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int sub_step_191_1 = ((sec_r000573_13_1 + pub_r000573_19_1) + 19) & 127;
  int sub_step_191_2 = ((sec_r000573_13_2 + pub_r000573_19_2) + 19) & 127;
  int stage_v_191_1 = ((sub_step_191_1 * 2) + pub_r000573_3_1) & 127;
  int stage_v_191_2 = ((sub_step_191_2 * 2) + pub_r000573_3_2) & 127;
  st_var_3_1.buffer[2] = stage_v_191_1 & 15;
  st_var_3_2.buffer[2] = stage_v_191_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int sub_step_192_1 = ((stage_v_84_1 + pub_r000573_0_1) + 28) & 127;
  int sub_step_192_2 = ((stage_v_84_2 + pub_r000573_0_2) + 28) & 127;
  int stage_v_192_1 = ((sub_step_192_1 * 2) + pub_r000573_7_1) & 127;
  int stage_v_192_2 = ((sub_step_192_2 * 2) + pub_r000573_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_192_1 & 15;
  st_var_0_2.buffer[0] = stage_v_192_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int sub_step_193_1 = ((sub_step_94_1 + pub_r000573_16_1) + 17) & 127;
  int sub_step_193_2 = ((sub_step_94_2 + pub_r000573_16_2) + 17) & 127;
  int stage_v_193_1 = ((sub_step_193_1 * 2) + pub_r000573_6_1) & 127;
  int stage_v_193_2 = ((sub_step_193_2 * 2) + pub_r000573_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_193_1 & 15;
  st_var_1_2.buffer[1] = stage_v_193_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int sub_step_194_1 = ((stage_v_168_1 + pub_r000573_16_1) + 29) & 127;
  int sub_step_194_2 = ((stage_v_168_2 + pub_r000573_16_2) + 29) & 127;
  int stage_v_194_1 = ((sub_step_194_1 * 2) + pub_r000573_9_1) & 127;
  int stage_v_194_2 = ((sub_step_194_2 * 2) + pub_r000573_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_194_1 & 15;
  st_var_2_2.buffer[2] = stage_v_194_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int sub_step_195_1 = ((sec_r000573_1_1 + pub_r000573_3_1) + 11) & 127;
  int sub_step_195_2 = ((sec_r000573_1_2 + pub_r000573_3_2) + 11) & 127;
  int stage_v_195_1 = ((sub_step_195_1 * 2) + pub_r000573_7_1) & 127;
  int stage_v_195_2 = ((sub_step_195_2 * 2) + pub_r000573_7_2) & 127;
  st_var_3_1.buffer[0] = stage_v_195_1 & 15;
  st_var_3_2.buffer[0] = stage_v_195_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int sub_step_196_1 = ((sub_step_164_1 + pub_r000573_19_1) + 35) & 127;
  int sub_step_196_2 = ((sub_step_164_2 + pub_r000573_19_2) + 35) & 127;
  int stage_v_196_1 = ((sub_step_196_1 * 2) + pub_r000573_6_1) & 127;
  int stage_v_196_2 = ((sub_step_196_2 * 2) + pub_r000573_6_2) & 127;
  st_var_0_1.buffer[1] = stage_v_196_1 & 15;
  st_var_0_2.buffer[1] = stage_v_196_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int sub_step_197_1 = ((sec_r000573_5_1 + pub_r000573_16_1) + 17) & 127;
  int sub_step_197_2 = ((sec_r000573_5_2 + pub_r000573_16_2) + 17) & 127;
  int stage_v_197_1 = ((sub_step_197_1 * 2) + pub_r000573_17_1) & 127;
  int stage_v_197_2 = ((sub_step_197_2 * 2) + pub_r000573_17_2) & 127;
  st_var_1_1.buffer[2] = stage_v_197_1 & 15;
  st_var_1_2.buffer[2] = stage_v_197_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int sub_step_198_1 = ((sub_step_139_1 + pub_r000573_14_1) + 17) & 127;
  int sub_step_198_2 = ((sub_step_139_2 + pub_r000573_14_2) + 17) & 127;
  int stage_v_198_1 = ((sub_step_198_1 * 2) + pub_r000573_1_1) & 127;
  int stage_v_198_2 = ((sub_step_198_2 * 2) + pub_r000573_1_2) & 127;
  st_var_2_1.buffer[0] = stage_v_198_1 & 15;
  st_var_2_2.buffer[0] = stage_v_198_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int sub_step_199_1 = ((sub_step_185_1 + pub_r000573_19_1) + 33) & 127;
  int sub_step_199_2 = ((sub_step_185_2 + pub_r000573_19_2) + 33) & 127;
  int stage_v_199_1 = ((sub_step_199_1 * 2) + pub_r000573_16_1) & 127;
  int stage_v_199_2 = ((sub_step_199_2 * 2) + pub_r000573_16_2) & 127;
  st_var_3_1.buffer[1] = stage_v_199_1 & 15;
  st_var_3_2.buffer[1] = stage_v_199_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int sub_step_200_1 = ((sec_r000573_8_1 + pub_r000573_2_1) + 35) & 127;
  int sub_step_200_2 = ((sec_r000573_8_2 + pub_r000573_2_2) + 35) & 127;
  int stage_v_200_1 = ((sub_step_200_1 * 2) + pub_r000573_7_1) & 127;
  int stage_v_200_2 = ((sub_step_200_2 * 2) + pub_r000573_7_2) & 127;
  st_var_0_1.buffer[2] = stage_v_200_1 & 15;
  st_var_0_2.buffer[2] = stage_v_200_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int sub_step_201_1 = ((sub_step_98_1 + pub_r000573_7_1) + 20) & 127;
  int sub_step_201_2 = ((sub_step_98_2 + pub_r000573_7_2) + 20) & 127;
  int stage_v_201_1 = ((sub_step_201_1 * 2) + pub_r000573_17_1) & 127;
  int stage_v_201_2 = ((sub_step_201_2 * 2) + pub_r000573_17_2) & 127;
  st_var_1_1.buffer[0] = stage_v_201_1 & 15;
  st_var_1_2.buffer[0] = stage_v_201_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int sub_step_202_1 = ((sec_r000573_6_1 + pub_r000573_11_1) + 24) & 127;
  int sub_step_202_2 = ((sec_r000573_6_2 + pub_r000573_11_2) + 24) & 127;
  int stage_v_202_1 = ((sub_step_202_1 * 2) + pub_r000573_7_1) & 127;
  int stage_v_202_2 = ((sub_step_202_2 * 2) + pub_r000573_7_2) & 127;
  st_var_2_1.buffer[1] = stage_v_202_1 & 15;
  st_var_2_2.buffer[1] = stage_v_202_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int sub_step_203_1 = ((sec_r000573_18_1 + pub_r000573_7_1) + 7) & 127;
  int sub_step_203_2 = ((sec_r000573_18_2 + pub_r000573_7_2) + 7) & 127;
  int stage_v_203_1 = ((sub_step_203_1 * 2) + pub_r000573_7_1) & 127;
  int stage_v_203_2 = ((sub_step_203_2 * 2) + pub_r000573_7_2) & 127;
  st_var_3_1.buffer[2] = stage_v_203_1 & 15;
  st_var_3_2.buffer[2] = stage_v_203_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int sub_step_204_1 = ((sec_r000573_1_1 + pub_r000573_19_1) + 28) & 127;
  int sub_step_204_2 = ((sec_r000573_1_2 + pub_r000573_19_2) + 28) & 127;
  int stage_v_204_1 = ((sub_step_204_1 * 2) + pub_r000573_10_1) & 127;
  int stage_v_204_2 = ((sub_step_204_2 * 2) + pub_r000573_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_204_1 & 15;
  st_var_0_2.buffer[0] = stage_v_204_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int sub_step_205_1 = ((sub_step_187_1 + pub_r000573_1_1) + 9) & 127;
  int sub_step_205_2 = ((sub_step_187_2 + pub_r000573_1_2) + 9) & 127;
  int stage_v_205_1 = ((sub_step_205_1 * 2) + pub_r000573_10_1) & 127;
  int stage_v_205_2 = ((sub_step_205_2 * 2) + pub_r000573_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_205_1 & 15;
  st_var_1_2.buffer[1] = stage_v_205_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int sub_step_206_1 = ((sec_r000573_9_1 + pub_r000573_9_1) + 30) & 127;
  int sub_step_206_2 = ((sec_r000573_9_2 + pub_r000573_9_2) + 30) & 127;
  int stage_v_206_1 = ((sub_step_206_1 * 2) + pub_r000573_18_1) & 127;
  int stage_v_206_2 = ((sub_step_206_2 * 2) + pub_r000573_18_2) & 127;
  st_var_2_1.buffer[2] = stage_v_206_1 & 15;
  st_var_2_2.buffer[2] = stage_v_206_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int sub_step_207_1 = ((sub_step_119_1 + pub_r000573_13_1) + 35) & 127;
  int sub_step_207_2 = ((sub_step_119_2 + pub_r000573_13_2) + 35) & 127;
  int stage_v_207_1 = ((sub_step_207_1 * 2) + pub_r000573_1_1) & 127;
  int stage_v_207_2 = ((sub_step_207_2 * 2) + pub_r000573_1_2) & 127;
  st_var_3_1.buffer[0] = stage_v_207_1 & 15;
  st_var_3_2.buffer[0] = stage_v_207_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int sub_step_208_1 = ((sec_r000573_17_1 + pub_r000573_6_1) + 7) & 127;
  int sub_step_208_2 = ((sec_r000573_17_2 + pub_r000573_6_2) + 7) & 127;
  int stage_v_208_1 = ((sub_step_208_1 * 2) + pub_r000573_15_1) & 127;
  int stage_v_208_2 = ((sub_step_208_2 * 2) + pub_r000573_15_2) & 127;
  st_var_0_1.buffer[1] = stage_v_208_1 & 15;
  st_var_0_2.buffer[1] = stage_v_208_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int sub_step_209_1 = ((stage_v_127_1 + pub_r000573_12_1) + 35) & 127;
  int sub_step_209_2 = ((stage_v_127_2 + pub_r000573_12_2) + 35) & 127;
  int stage_v_209_1 = ((sub_step_209_1 * 2) + pub_r000573_5_1) & 127;
  int stage_v_209_2 = ((sub_step_209_2 * 2) + pub_r000573_5_2) & 127;
  st_var_1_1.buffer[2] = stage_v_209_1 & 15;
  st_var_1_2.buffer[2] = stage_v_209_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int sub_step_210_1 = ((stage_v_203_1 + pub_r000573_18_1) + 21) & 127;
  int sub_step_210_2 = ((stage_v_203_2 + pub_r000573_18_2) + 21) & 127;
  int stage_v_210_1 = ((sub_step_210_1 * 2) + pub_r000573_6_1) & 127;
  int stage_v_210_2 = ((sub_step_210_2 * 2) + pub_r000573_6_2) & 127;
  st_var_2_1.buffer[0] = stage_v_210_1 & 15;
  st_var_2_2.buffer[0] = stage_v_210_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int sub_step_211_1 = ((sec_r000573_9_1 + pub_r000573_18_1) + 26) & 127;
  int sub_step_211_2 = ((sec_r000573_9_2 + pub_r000573_18_2) + 26) & 127;
  int stage_v_211_1 = ((sub_step_211_1 * 2) + pub_r000573_13_1) & 127;
  int stage_v_211_2 = ((sub_step_211_2 * 2) + pub_r000573_13_2) & 127;
  st_var_3_1.buffer[1] = stage_v_211_1 & 15;
  st_var_3_2.buffer[1] = stage_v_211_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int sub_step_212_1 = ((stage_v_124_1 + pub_r000573_14_1) + 34) & 127;
  int sub_step_212_2 = ((stage_v_124_2 + pub_r000573_14_2) + 34) & 127;
  int stage_v_212_1 = ((sub_step_212_1 * 2) + pub_r000573_21_1) & 127;
  int stage_v_212_2 = ((sub_step_212_2 * 2) + pub_r000573_21_2) & 127;
  st_var_0_1.buffer[2] = stage_v_212_1 & 15;
  st_var_0_2.buffer[2] = stage_v_212_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int sub_step_213_1 = ((sub_step_104_1 + pub_r000573_16_1) + 29) & 127;
  int sub_step_213_2 = ((sub_step_104_2 + pub_r000573_16_2) + 29) & 127;
  int stage_v_213_1 = ((sub_step_213_1 * 2) + pub_r000573_3_1) & 127;
  int stage_v_213_2 = ((sub_step_213_2 * 2) + pub_r000573_3_2) & 127;
  st_var_1_1.buffer[0] = stage_v_213_1 & 15;
  st_var_1_2.buffer[0] = stage_v_213_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int sub_step_214_1 = ((stage_v_183_1 + pub_r000573_10_1) + 15) & 127;
  int sub_step_214_2 = ((stage_v_183_2 + pub_r000573_10_2) + 15) & 127;
  int stage_v_214_1 = ((sub_step_214_1 * 2) + pub_r000573_8_1) & 127;
  int stage_v_214_2 = ((sub_step_214_2 * 2) + pub_r000573_8_2) & 127;
  st_var_2_1.buffer[1] = stage_v_214_1 & 15;
  st_var_2_2.buffer[1] = stage_v_214_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int sub_step_215_1 = ((stage_v_176_1 + pub_r000573_20_1) + 28) & 127;
  int sub_step_215_2 = ((stage_v_176_2 + pub_r000573_20_2) + 28) & 127;
  int stage_v_215_1 = ((sub_step_215_1 * 2) + pub_r000573_8_1) & 127;
  int stage_v_215_2 = ((sub_step_215_2 * 2) + pub_r000573_8_2) & 127;
  st_var_3_1.buffer[2] = stage_v_215_1 & 15;
  st_var_3_2.buffer[2] = stage_v_215_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int sub_step_216_1 = ((stage_v_149_1 + pub_r000573_16_1) + 22) & 127;
  int sub_step_216_2 = ((stage_v_149_2 + pub_r000573_16_2) + 22) & 127;
  int stage_v_216_1 = ((sub_step_216_1 * 2) + pub_r000573_2_1) & 127;
  int stage_v_216_2 = ((sub_step_216_2 * 2) + pub_r000573_2_2) & 127;
  st_var_0_1.buffer[0] = stage_v_216_1 & 15;
  st_var_0_2.buffer[0] = stage_v_216_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int sub_step_217_1 = ((sub_step_126_1 + pub_r000573_1_1) + 16) & 127;
  int sub_step_217_2 = ((sub_step_126_2 + pub_r000573_1_2) + 16) & 127;
  int stage_v_217_1 = ((sub_step_217_1 * 2) + pub_r000573_15_1) & 127;
  int stage_v_217_2 = ((sub_step_217_2 * 2) + pub_r000573_15_2) & 127;
  st_var_1_1.buffer[1] = stage_v_217_1 & 15;
  st_var_1_2.buffer[1] = stage_v_217_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int sub_step_218_1 = ((stage_v_204_1 + pub_r000573_0_1) + 12) & 127;
  int sub_step_218_2 = ((stage_v_204_2 + pub_r000573_0_2) + 12) & 127;
  int stage_v_218_1 = ((sub_step_218_1 * 2) + pub_r000573_3_1) & 127;
  int stage_v_218_2 = ((sub_step_218_2 * 2) + pub_r000573_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_218_1 & 15;
  st_var_2_2.buffer[2] = stage_v_218_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int sub_step_219_1 = ((stage_v_152_1 + pub_r000573_6_1) + 26) & 127;
  int sub_step_219_2 = ((stage_v_152_2 + pub_r000573_6_2) + 26) & 127;
  int stage_v_219_1 = ((sub_step_219_1 * 2) + pub_r000573_16_1) & 127;
  int stage_v_219_2 = ((sub_step_219_2 * 2) + pub_r000573_16_2) & 127;
  st_var_3_1.buffer[0] = stage_v_219_1 & 15;
  st_var_3_2.buffer[0] = stage_v_219_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int sub_step_220_1 = ((stage_v_80_1 + pub_r000573_0_1) + 27) & 127;
  int sub_step_220_2 = ((stage_v_80_2 + pub_r000573_0_2) + 27) & 127;
  int stage_v_220_1 = ((sub_step_220_1 * 2) + pub_r000573_10_1) & 127;
  int stage_v_220_2 = ((sub_step_220_2 * 2) + pub_r000573_10_2) & 127;
  st_var_0_1.buffer[1] = stage_v_220_1 & 15;
  st_var_0_2.buffer[1] = stage_v_220_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int sub_step_221_1 = ((sec_r000573_13_1 + pub_r000573_19_1) + 22) & 127;
  int sub_step_221_2 = ((sec_r000573_13_2 + pub_r000573_19_2) + 22) & 127;
  int stage_v_221_1 = ((sub_step_221_1 * 2) + pub_r000573_1_1) & 127;
  int stage_v_221_2 = ((sub_step_221_2 * 2) + pub_r000573_1_2) & 127;
  st_var_1_1.buffer[2] = stage_v_221_1 & 15;
  st_var_1_2.buffer[2] = stage_v_221_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int sub_step_222_1 = ((sub_step_144_1 + pub_r000573_0_1) + 15) & 127;
  int sub_step_222_2 = ((sub_step_144_2 + pub_r000573_0_2) + 15) & 127;
  int stage_v_222_1 = ((sub_step_222_1 * 2) + pub_r000573_21_1) & 127;
  int stage_v_222_2 = ((sub_step_222_2 * 2) + pub_r000573_21_2) & 127;
  st_var_2_1.buffer[0] = stage_v_222_1 & 15;
  st_var_2_2.buffer[0] = stage_v_222_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int sub_step_223_1 = ((sec_r000573_2_1 + pub_r000573_4_1) + 26) & 127;
  int sub_step_223_2 = ((sec_r000573_2_2 + pub_r000573_4_2) + 26) & 127;
  int stage_v_223_1 = ((sub_step_223_1 * 2) + pub_r000573_19_1) & 127;
  int stage_v_223_2 = ((sub_step_223_2 * 2) + pub_r000573_19_2) & 127;
  st_var_3_1.buffer[1] = stage_v_223_1 & 15;
  st_var_3_2.buffer[1] = stage_v_223_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int sub_step_224_1 = ((sec_r000573_19_1 + pub_r000573_7_1) + 23) & 127;
  int sub_step_224_2 = ((sec_r000573_19_2 + pub_r000573_7_2) + 23) & 127;
  int stage_v_224_1 = ((sub_step_224_1 * 2) + pub_r000573_10_1) & 127;
  int stage_v_224_2 = ((sub_step_224_2 * 2) + pub_r000573_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_224_1 & 15;
  st_var_0_2.buffer[2] = stage_v_224_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int sub_step_225_1 = ((stage_v_109_1 + pub_r000573_1_1) + 15) & 127;
  int sub_step_225_2 = ((stage_v_109_2 + pub_r000573_1_2) + 15) & 127;
  int stage_v_225_1 = ((sub_step_225_1 * 2) + pub_r000573_15_1) & 127;
  int stage_v_225_2 = ((sub_step_225_2 * 2) + pub_r000573_15_2) & 127;
  st_var_1_1.buffer[0] = stage_v_225_1 & 15;
  st_var_1_2.buffer[0] = stage_v_225_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int sub_step_226_1 = ((sec_r000573_15_1 + pub_r000573_19_1) + 9) & 127;
  int sub_step_226_2 = ((sec_r000573_15_2 + pub_r000573_19_2) + 9) & 127;
  int stage_v_226_1 = ((sub_step_226_1 * 2) + pub_r000573_9_1) & 127;
  int stage_v_226_2 = ((sub_step_226_2 * 2) + pub_r000573_9_2) & 127;
  st_var_2_1.buffer[1] = stage_v_226_1 & 15;
  st_var_2_2.buffer[1] = stage_v_226_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int sub_step_227_1 = ((sec_r000573_11_1 + pub_r000573_21_1) + 15) & 127;
  int sub_step_227_2 = ((sec_r000573_11_2 + pub_r000573_21_2) + 15) & 127;
  int stage_v_227_1 = ((sub_step_227_1 * 2) + pub_r000573_19_1) & 127;
  int stage_v_227_2 = ((sub_step_227_2 * 2) + pub_r000573_19_2) & 127;
  st_var_3_1.buffer[2] = stage_v_227_1 & 15;
  st_var_3_2.buffer[2] = stage_v_227_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int sub_step_228_1 = ((stage_v_179_1 + pub_r000573_11_1) + 27) & 127;
  int sub_step_228_2 = ((stage_v_179_2 + pub_r000573_11_2) + 27) & 127;
  int stage_v_228_1 = ((sub_step_228_1 * 2) + pub_r000573_16_1) & 127;
  int stage_v_228_2 = ((sub_step_228_2 * 2) + pub_r000573_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_228_1 & 15;
  st_var_0_2.buffer[0] = stage_v_228_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int sub_step_229_1 = ((stage_v_194_1 + pub_r000573_17_1) + 23) & 127;
  int sub_step_229_2 = ((stage_v_194_2 + pub_r000573_17_2) + 23) & 127;
  int stage_v_229_1 = ((sub_step_229_1 * 2) + pub_r000573_2_1) & 127;
  int stage_v_229_2 = ((sub_step_229_2 * 2) + pub_r000573_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_229_1 & 15;
  st_var_1_2.buffer[1] = stage_v_229_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int sub_step_230_1 = ((stage_v_208_1 + pub_r000573_2_1) + 16) & 127;
  int sub_step_230_2 = ((stage_v_208_2 + pub_r000573_2_2) + 16) & 127;
  int stage_v_230_1 = ((sub_step_230_1 * 2) + pub_r000573_12_1) & 127;
  int stage_v_230_2 = ((sub_step_230_2 * 2) + pub_r000573_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_230_1 & 15;
  st_var_2_2.buffer[2] = stage_v_230_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int sub_step_231_1 = ((sec_r000573_18_1 + pub_r000573_7_1) + 25) & 127;
  int sub_step_231_2 = ((sec_r000573_18_2 + pub_r000573_7_2) + 25) & 127;
  int stage_v_231_1 = ((sub_step_231_1 * 2) + pub_r000573_4_1) & 127;
  int stage_v_231_2 = ((sub_step_231_2 * 2) + pub_r000573_4_2) & 127;
  st_var_3_1.buffer[0] = stage_v_231_1 & 15;
  st_var_3_2.buffer[0] = stage_v_231_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int sub_step_232_1 = ((stage_v_226_1 + pub_r000573_18_1) + 11) & 127;
  int sub_step_232_2 = ((stage_v_226_2 + pub_r000573_18_2) + 11) & 127;
  int stage_v_232_1 = ((sub_step_232_1 * 2) + pub_r000573_9_1) & 127;
  int stage_v_232_2 = ((sub_step_232_2 * 2) + pub_r000573_9_2) & 127;
  st_var_0_1.buffer[1] = stage_v_232_1 & 15;
  st_var_0_2.buffer[1] = stage_v_232_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int sub_step_233_1 = ((stage_v_125_1 + pub_r000573_2_1) + 5) & 127;
  int sub_step_233_2 = ((stage_v_125_2 + pub_r000573_2_2) + 5) & 127;
  int stage_v_233_1 = ((sub_step_233_1 * 2) + pub_r000573_7_1) & 127;
  int stage_v_233_2 = ((sub_step_233_2 * 2) + pub_r000573_7_2) & 127;
  st_var_1_1.buffer[2] = stage_v_233_1 & 15;
  st_var_1_2.buffer[2] = stage_v_233_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int sub_step_234_1 = ((sub_step_101_1 + pub_r000573_20_1) + 27) & 127;
  int sub_step_234_2 = ((sub_step_101_2 + pub_r000573_20_2) + 27) & 127;
  int stage_v_234_1 = ((sub_step_234_1 * 2) + pub_r000573_19_1) & 127;
  int stage_v_234_2 = ((sub_step_234_2 * 2) + pub_r000573_19_2) & 127;
  st_var_2_1.buffer[0] = stage_v_234_1 & 15;
  st_var_2_2.buffer[0] = stage_v_234_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000573_1_1 != sec_r000573_1_2);
  __CPROVER_assume(sec_r000573_7_1 != sec_r000573_7_2);
  __CPROVER_assume(sec_r000573_20_1 != sec_r000573_20_2);
  __CPROVER_assume(pub_r000573_0_1 == pub_r000573_0_2);
  __CPROVER_assume(sec_r000573_18_1 != sec_r000573_18_2);
  __CPROVER_assume(pub_r000573_8_1 == pub_r000573_8_2);
  __CPROVER_assume(pub_r000573_14_1 == pub_r000573_14_2);
  __CPROVER_assume(sec_r000573_12_1 != sec_r000573_12_2);
  __CPROVER_assume(sec_r000573_3_1 != sec_r000573_3_2);
  __CPROVER_assume(pub_r000573_3_1 == pub_r000573_3_2);
  __CPROVER_assume(sec_r000573_14_1 != sec_r000573_14_2);
  __CPROVER_assume(sec_r000573_2_1 != sec_r000573_2_2);
  __CPROVER_assume(pub_r000573_15_1 == pub_r000573_15_2);
  __CPROVER_assume(pub_r000573_17_1 == pub_r000573_17_2);
  __CPROVER_assume(sec_r000573_0_1 != sec_r000573_0_2);
  __CPROVER_assume(sec_r000573_16_1 != sec_r000573_16_2);
  __CPROVER_assume(pub_r000573_7_1 == pub_r000573_7_2);
  __CPROVER_assume(pub_r000573_20_1 == pub_r000573_20_2);
  __CPROVER_assume(pub_r000573_4_1 == pub_r000573_4_2);
  __CPROVER_assume(pub_r000573_6_1 == pub_r000573_6_2);
  __CPROVER_assume(pub_r000573_2_1 == pub_r000573_2_2);
  __CPROVER_assume(pub_r000573_18_1 == pub_r000573_18_2);
  __CPROVER_assume(pub_r000573_21_1 == pub_r000573_21_2);
  __CPROVER_assume(sec_r000573_4_1 != sec_r000573_4_2);
  __CPROVER_assume(pub_r000573_19_1 == pub_r000573_19_2);
  __CPROVER_assume(pub_r000573_16_1 == pub_r000573_16_2);
  __CPROVER_assume(sec_r000573_11_1 != sec_r000573_11_2);
  __CPROVER_assume(sec_r000573_6_1 != sec_r000573_6_2);
  __CPROVER_assume(sec_r000573_19_1 != sec_r000573_19_2);
  __CPROVER_assume(pub_r000573_12_1 == pub_r000573_12_2);
  __CPROVER_assume(sec_r000573_17_1 != sec_r000573_17_2);
  __CPROVER_assume(sec_r000573_8_1 != sec_r000573_8_2);
  __CPROVER_assume(sec_r000573_9_1 != sec_r000573_9_2);
  __CPROVER_assume(sec_r000573_5_1 != sec_r000573_5_2);
  __CPROVER_assume(pub_r000573_5_1 == pub_r000573_5_2);
  __CPROVER_assume(pub_r000573_10_1 == pub_r000573_10_2);
  __CPROVER_assume(pub_r000573_13_1 == pub_r000573_13_2);
  __CPROVER_assume(pub_r000573_9_1 == pub_r000573_9_2);
  __CPROVER_assume(sec_r000573_10_1 != sec_r000573_10_2);
  __CPROVER_assume(pub_r000573_11_1 == pub_r000573_11_2);
  __CPROVER_assume(pub_r000573_1_1 == pub_r000573_1_2);
  __CPROVER_assume(sec_r000573_15_1 != sec_r000573_15_2);
  __CPROVER_assume(sec_r000573_13_1 != sec_r000573_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.trace == st_var_1_2.trace);
  assert(st_var_1_1.dim == st_var_1_2.dim);
  assert(st_var_1_1.scale == st_var_1_2.scale);
  assert(st_var_1_1.stride == st_var_1_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.flags == st_var_2_2.flags);
  assert(st_var_2_1.round_key == st_var_2_2.round_key);
  assert(st_var_2_1.counter == st_var_2_2.counter);
  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.nonce == st_var_2_2.nonce);
  assert(st_var_2_1.tag == st_var_2_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.reading == st_var_3_2.reading);
  assert(st_var_3_1.offset == st_var_3_2.offset);
  assert(st_var_3_1.calib == st_var_3_2.calib);
  assert(st_var_3_1.gain == st_var_3_2.gain);
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
  assert(sub_step_78_1 == sub_step_78_2);
  assert(stage_v_78_1 == stage_v_78_2);
  assert(sub_step_79_1 == sub_step_79_2);
  assert(stage_v_79_1 == stage_v_79_2);
  assert(sub_step_80_1 == sub_step_80_2);
  assert(stage_v_80_1 == stage_v_80_2);
  assert(sub_step_81_1 == sub_step_81_2);
  assert(stage_v_81_1 == stage_v_81_2);
  assert(sub_step_82_1 == sub_step_82_2);
  assert(stage_v_82_1 == stage_v_82_2);
  assert(sub_step_83_1 == sub_step_83_2);
  assert(stage_v_83_1 == stage_v_83_2);
  assert(sub_step_84_1 == sub_step_84_2);
  assert(stage_v_84_1 == stage_v_84_2);
  assert(sub_step_85_1 == sub_step_85_2);
  assert(stage_v_85_1 == stage_v_85_2);
  assert(sub_step_86_1 == sub_step_86_2);
  assert(stage_v_86_1 == stage_v_86_2);
  assert(sub_step_87_1 == sub_step_87_2);
  assert(stage_v_87_1 == stage_v_87_2);
  assert(sub_step_88_1 == sub_step_88_2);
  assert(stage_v_88_1 == stage_v_88_2);
  assert(sub_step_89_1 == sub_step_89_2);
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
}


