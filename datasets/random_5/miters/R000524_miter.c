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
struct FilterState_R000524_2413_0
{
  int gain_db;
  unsigned char cutoff;
  int prev_out;
  int prev_in;
  int buffer[3];
};
struct CipherContext_R000524_2413_1
{
  short nonce;
  unsigned char counter;
  int iv;
  unsigned char round_key;
  int buffer[3];
};
struct EventLog_R000524_2413_2
{
  int facility;
  int signature;
  unsigned char seq;
  int severity;
  int buffer[3];
};
struct Transaction_R000524_2413_3
{
  short balance;
  int fee;
  short status;
  int account_id;
  int auth_code;
  int buffer[3];
};
union PacketPayload_R000524_2413_0
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
void fn_R000524_2413_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000524_2413_0 st_1 = {0};
  struct FilterState_R000524_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int coefficient_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_19_1) & 63;
  aux_2 = (aux_2 + coefficient_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_34_1 = local_arr_1[aux_1 % 3];
  int scale_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_34_2 * 2)) & 127;
  int sample_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_73_1)
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

  switch (sample_73_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_19_1 == coefficient_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_34_1 == scale_34_2);
  assert(sample_73_1 == sample_73_2);
}

int fn_R000524_2413_0(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000524_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int coefficient_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_19) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_34 = local_arr[aux % 3];
  acc = (acc + (scale_34 * 2)) & 127;
  int sample_73 = (aux + st.buffer[1]) & 3;
  switch (sample_73)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000524_2413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000524_2413_2 st_1 = {0};
  struct EventLog_R000524_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int coefficient_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_66_1)
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

  switch (coefficient_66_2)
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

  int parity_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_92_1) & 63;
  aux_2 = (aux_2 + parity_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_66_1 == coefficient_66_2);
  assert(parity_92_1 == parity_92_2);
}

int fn_R000524_2413_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000524_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int coefficient_66 = (aux + st.buffer[1]) & 3;
  switch (coefficient_66)
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

  int parity_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000524_2413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000524_2413_3 st_1 = {0};
  struct Transaction_R000524_2413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_17_1 = local_arr_1[aux_1 % 3];
  int threshold_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_17_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_17_1 == threshold_17_2);
}

int fn_R000524_2413_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000524_2413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int threshold_17 = local_arr[aux % 3];
  acc = (acc + (threshold_17 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000524_2413_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000524_2413_1 st_1 = {0};
  struct CipherContext_R000524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_24_1 = local_arr_1[aux_1 % 3];
  int parity_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_24_2 * 2)) & 127;
  int pivot_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_86_1) & 63;
  aux_2 = (aux_2 + pivot_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_24_1 == parity_24_2);
  assert(pivot_86_1 == pivot_86_2);
}

int fn_R000524_2413_3(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int parity_24 = local_arr[aux % 3];
  acc = (acc + (parity_24 * 2)) & 127;
  int pivot_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000524_2413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000524_2413_1 st_1 = {0};
  struct CipherContext_R000524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int quotient_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_78_1 > 13)
  {
    acc_1 = ((acc_1 + (quotient_78_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_78_2 > 13)
  {
    acc_2 = ((acc_2 + (quotient_78_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_97_1) & 63;
  aux_2 = (aux_2 + accumulator_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_78_1 == quotient_78_2);
  assert(accumulator_97_1 == accumulator_97_2);
}

int fn_R000524_2413_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int quotient_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_78 > 13)
  {
    acc = ((acc + (quotient_78 * 2)) + 5) & 127;
    aux ^= quotient_78 & 15;
  }
  else
  {
    acc = ((acc - quotient_78) + 11) & 127;
    aux += 3;
  }
  int accumulator_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000524_2413_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000524_2413_0 st_1 = {0};
  struct FilterState_R000524_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_54_1 = local_arr_1[aux_1 % 3];
  int quotient_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_54_2 * 2)) & 127;
  int bound_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_70_1 > 38)
  {
    acc_1 = ((acc_1 + (bound_70_1 * 2)) + 5) & 127;
    aux_1 ^= bound_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_70_2 > 38)
  {
    acc_2 = ((acc_2 + (bound_70_2 * 2)) + 5) & 127;
    aux_2 ^= bound_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_54_1 == quotient_54_2);
  assert(bound_70_1 == bound_70_2);
}

int fn_R000524_2413_5(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000524_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int quotient_54 = local_arr[aux % 3];
  acc = (acc + (quotient_54 * 2)) & 127;
  int bound_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_70 > 38)
  {
    acc = ((acc + (bound_70 * 2)) + 5) & 127;
    aux ^= bound_70 & 15;
  }
  else
  {
    acc = ((acc - bound_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000524_2413_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000524_2413_1 st_1 = {0};
  struct CipherContext_R000524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_27_1 = local_arr_1[aux_1 % 3];
  int tally_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_27_2 * 2)) & 127;
  int phase_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_85_1) & 63;
  aux_2 = (aux_2 + phase_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_61_1)
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

  switch (scale_61_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_27_1 == tally_27_2);
  assert(phase_85_1 == phase_85_2);
  assert(scale_61_1 == scale_61_2);
}

int fn_R000524_2413_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int tally_27 = local_arr[aux % 3];
  acc = (acc + (tally_27 * 2)) & 127;
  int phase_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_85) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_61 = (aux + st.buffer[1]) & 3;
  switch (scale_61)
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

void fn_R000524_2413_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000524_2413_3 st_1 = {0};
  struct Transaction_R000524_2413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_41_1 = local_arr_1[aux_1 % 3];
  int sample_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_41_2 * 2)) & 127;
  int vector_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_64_1 > 19)
  {
    acc_1 = ((acc_1 + (vector_64_1 * 2)) + 5) & 127;
    aux_1 ^= vector_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_64_2 > 19)
  {
    acc_2 = ((acc_2 + (vector_64_2 * 2)) + 5) & 127;
    aux_2 ^= vector_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_64_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_23_1) & 63;
  aux_2 = (aux_2 + anchor_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_13_1)
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

  switch (quantum_13_2)
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
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_41_1 == sample_41_2);
  assert(vector_64_1 == vector_64_2);
  assert(anchor_23_1 == anchor_23_2);
  assert(quantum_13_1 == quantum_13_2);
}

int fn_R000524_2413_7(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000524_2413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int sample_41 = local_arr[aux % 3];
  acc = (acc + (sample_41 * 2)) & 127;
  int vector_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_64 > 19)
  {
    acc = ((acc + (vector_64 * 2)) + 5) & 127;
    aux ^= vector_64 & 15;
  }
  else
  {
    acc = ((acc - vector_64) + 11) & 127;
    aux += 3;
  }
  int anchor_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_23) & 63;
  acc ^= aux;
  int quantum_13 = (aux + st.buffer[1]) & 3;
  switch (quantum_13)
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

void fn_R000524_2413_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000524_2413_0 st_1 = {0};
  struct FilterState_R000524_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int factor_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_27_1)
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

  switch (factor_27_2)
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

  int offset_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_64_1 > 32)
  {
    acc_1 = ((acc_1 + (offset_64_1 * 2)) + 5) & 127;
    aux_1 ^= offset_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_64_2 > 32)
  {
    acc_2 = ((acc_2 + (offset_64_2 * 2)) + 5) & 127;
    aux_2 ^= offset_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_64_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_98_1) & 63;
  aux_2 = (aux_2 + delta_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_27_1 == factor_27_2);
  assert(offset_64_1 == offset_64_2);
  assert(delta_98_1 == delta_98_2);
}

int fn_R000524_2413_8(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000524_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int factor_27 = (aux + st.buffer[1]) & 3;
  switch (factor_27)
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

  int offset_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_64 > 32)
  {
    acc = ((acc + (offset_64 * 2)) + 5) & 127;
    aux ^= offset_64 & 15;
  }
  else
  {
    acc = ((acc - offset_64) + 11) & 127;
    aux += 3;
  }
  int delta_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_98) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000524_2413_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000524_2413_1 st_1 = {0};
  struct CipherContext_R000524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int tracker_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_91_1 > 41)
  {
    acc_1 = ((acc_1 + (tracker_91_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_91_2 > 41)
  {
    acc_2 = ((acc_2 + (tracker_91_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_91_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_91_1 == tracker_91_2);
}

int fn_R000524_2413_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int tracker_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_91 > 41)
  {
    acc = ((acc + (tracker_91 * 2)) + 5) & 127;
    aux ^= tracker_91 & 15;
  }
  else
  {
    acc = ((acc - tracker_91) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000524_2413_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000524_2413_0 st_1 = {0};
  struct FilterState_R000524_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_59_1 = local_arr_1[aux_1 % 3];
  int window_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_59_2 * 2)) & 127;
  int quantum_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_99_1)
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

  switch (quantum_99_2)
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

  int pivot_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_94_1 > 20)
  {
    acc_1 = ((acc_1 + (pivot_94_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_94_2 > 20)
  {
    acc_2 = ((acc_2 + (pivot_94_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_94_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_59_1 == window_59_2);
  assert(quantum_99_1 == quantum_99_2);
  assert(pivot_94_1 == pivot_94_2);
}

int fn_R000524_2413_10(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000524_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int window_59 = local_arr[aux % 3];
  acc = (acc + (window_59 * 2)) & 127;
  int quantum_99 = (aux + st.buffer[1]) & 3;
  switch (quantum_99)
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

  int pivot_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_94 > 20)
  {
    acc = ((acc + (pivot_94 * 2)) + 5) & 127;
    aux ^= pivot_94 & 15;
  }
  else
  {
    acc = ((acc - pivot_94) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000524_2413_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000524_2413_2 st_1 = {0};
  struct EventLog_R000524_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int tracker_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_97_1 > 24)
  {
    acc_1 = ((acc_1 + (tracker_97_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_97_2 > 24)
  {
    acc_2 = ((acc_2 + (tracker_97_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_49_1 = local_arr_1[aux_1 % 3];
  int checksum_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_49_2 * 2)) & 127;
  int weight_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_53_1) & 63;
  aux_2 = (aux_2 + weight_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_46_1)
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

  switch (factor_46_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_97_1 == tracker_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_49_1 == checksum_49_2);
  assert(weight_53_1 == weight_53_2);
  assert(factor_46_1 == factor_46_2);
}

int fn_R000524_2413_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000524_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int tracker_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_97 > 24)
  {
    acc = ((acc + (tracker_97 * 2)) + 5) & 127;
    aux ^= tracker_97 & 15;
  }
  else
  {
    acc = ((acc - tracker_97) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_49 = local_arr[aux % 3];
  acc = (acc + (checksum_49 * 2)) & 127;
  int weight_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_53) & 63;
  acc ^= aux;
  int factor_46 = (aux + st.buffer[1]) & 3;
  switch (factor_46)
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

void fn_R000524_2413_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000524_2413_3 st_1 = {0};
  struct Transaction_R000524_2413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int delta_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_85_1) & 63;
  aux_2 = (aux_2 + delta_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_69_1)
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

  switch (mask_69_2)
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
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_85_1 == delta_85_2);
  assert(mask_69_1 == mask_69_2);
}

int fn_R000524_2413_12(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000524_2413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int delta_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_85) & 63;
  acc ^= aux;
  int mask_69 = (aux + st.buffer[1]) & 3;
  switch (mask_69)
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

void fn_R000524_2413_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000524_2413_2 st_1 = {0};
  struct EventLog_R000524_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_37_1 = local_arr_1[aux_1 % 3];
  int scale_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_37_2 * 2)) & 127;
  int phase_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_20_1) & 63;
  aux_2 = (aux_2 + phase_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_46_1 > 42)
  {
    acc_1 = ((acc_1 + (bound_46_1 * 2)) + 5) & 127;
    aux_1 ^= bound_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_46_2 > 42)
  {
    acc_2 = ((acc_2 + (bound_46_2 * 2)) + 5) & 127;
    aux_2 ^= bound_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_46_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_37_1 == scale_37_2);
  assert(phase_20_1 == phase_20_2);
  assert(bound_46_1 == bound_46_2);
}

int fn_R000524_2413_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000524_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int scale_37 = local_arr[aux % 3];
  acc = (acc + (scale_37 * 2)) & 127;
  int phase_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_20) & 63;
  acc ^= aux;
  int bound_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_46 > 42)
  {
    acc = ((acc + (bound_46 * 2)) + 5) & 127;
    aux ^= bound_46 & 15;
  }
  else
  {
    acc = ((acc - bound_46) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000524_2413_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000524_2413_1 st_1 = {0};
  struct CipherContext_R000524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int parity_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_26_1 > 15)
  {
    acc_1 = ((acc_1 + (parity_26_1 * 2)) + 5) & 127;
    aux_1 ^= parity_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_26_2 > 15)
  {
    acc_2 = ((acc_2 + (parity_26_2 * 2)) + 5) & 127;
    aux_2 ^= parity_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_26_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_89_1 = local_arr_1[aux_1 % 3];
  int accumulator_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_89_2 * 2)) & 127;
  int anchor_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_98_1)
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

  switch (anchor_98_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_26_1 == parity_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_89_1 == accumulator_89_2);
  assert(anchor_98_1 == anchor_98_2);
}

int fn_R000524_2413_14(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int parity_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_26 > 15)
  {
    acc = ((acc + (parity_26 * 2)) + 5) & 127;
    aux ^= parity_26 & 15;
  }
  else
  {
    acc = ((acc - parity_26) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_89 = local_arr[aux % 3];
  acc = (acc + (accumulator_89 * 2)) & 127;
  int anchor_98 = (aux + st.buffer[1]) & 3;
  switch (anchor_98)
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

void fn_R000524_2413_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000524_2413_0 st_1 = {0};
  struct FilterState_R000524_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int delta_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_60_1)
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

  switch (delta_60_2)
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

  int parity_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_41_1 > 30)
  {
    acc_1 = ((acc_1 + (parity_41_1 * 2)) + 5) & 127;
    aux_1 ^= parity_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_41_2 > 30)
  {
    acc_2 = ((acc_2 + (parity_41_2 * 2)) + 5) & 127;
    aux_2 ^= parity_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_37_1 = local_arr_1[aux_1 % 3];
  int accumulator_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_37_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_60_1 == delta_60_2);
  assert(parity_41_1 == parity_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_37_1 == accumulator_37_2);
}

int fn_R000524_2413_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000524_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int delta_60 = (aux + st.buffer[1]) & 3;
  switch (delta_60)
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

  int parity_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_41 > 30)
  {
    acc = ((acc + (parity_41 * 2)) + 5) & 127;
    aux ^= parity_41 & 15;
  }
  else
  {
    acc = ((acc - parity_41) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_37 = local_arr[aux % 3];
  acc = (acc + (accumulator_37 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000524_2413_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000524_2413_3 st_1 = {0};
  struct Transaction_R000524_2413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_78_1 = local_arr_1[aux_1 % 3];
  int metric_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_78_2 * 2)) & 127;
  int anchor_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_35_1) & 63;
  aux_2 = (aux_2 + anchor_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_17_1 > 44)
  {
    acc_1 = ((acc_1 + (factor_17_1 * 2)) + 5) & 127;
    aux_1 ^= factor_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_17_2 > 44)
  {
    acc_2 = ((acc_2 + (factor_17_2 * 2)) + 5) & 127;
    aux_2 ^= factor_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_17_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_78_1 == metric_78_2);
  assert(anchor_35_1 == anchor_35_2);
  assert(factor_17_1 == factor_17_2);
}

int fn_R000524_2413_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000524_2413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int metric_78 = local_arr[aux % 3];
  acc = (acc + (metric_78 * 2)) & 127;
  int anchor_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_35) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_17 > 44)
  {
    acc = ((acc + (factor_17 * 2)) + 5) & 127;
    aux ^= factor_17 & 15;
  }
  else
  {
    acc = ((acc - factor_17) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000524_2413_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000524_2413_3 st_1 = {0};
  struct Transaction_R000524_2413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int weight_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_51_1)
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

  switch (weight_51_2)
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

  int phase_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_50_1) & 63;
  aux_2 = (aux_2 + phase_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_64_1 = local_arr_1[aux_1 % 3];
  int scale_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_64_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_51_1 == weight_51_2);
  assert(phase_50_1 == phase_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_64_1 == scale_64_2);
}

int fn_R000524_2413_17(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000524_2413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int weight_51 = (aux + st.buffer[1]) & 3;
  switch (weight_51)
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

  int phase_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_50) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_64 = local_arr[aux % 3];
  acc = (acc + (scale_64 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000524_2413_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000524_2413_0 st_1 = {0};
  struct FilterState_R000524_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int checksum_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_89_1 > 26)
  {
    acc_1 = ((acc_1 + (checksum_89_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_89_2 > 26)
  {
    acc_2 = ((acc_2 + (checksum_89_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_55_1 = local_arr_1[aux_1 % 3];
  int margin_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_55_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_89_1 == checksum_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_55_1 == margin_55_2);
}

int fn_R000524_2413_18(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000524_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int checksum_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_89 > 26)
  {
    acc = ((acc + (checksum_89 * 2)) + 5) & 127;
    aux ^= checksum_89 & 15;
  }
  else
  {
    acc = ((acc - checksum_89) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_55 = local_arr[aux % 3];
  acc = (acc + (margin_55 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000524_2413_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000524_2413_1 st_1 = {0};
  struct CipherContext_R000524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int quantum_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_79_1) & 63;
  aux_2 = (aux_2 + quantum_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_49_1)
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

  switch (residue_49_2)
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
  int anchor_79_1 = local_arr_1[aux_1 % 3];
  int anchor_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_79_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_79_1 == quantum_79_2);
  assert(residue_49_1 == residue_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_79_1 == anchor_79_2);
}

int fn_R000524_2413_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int quantum_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_79) & 63;
  acc ^= aux;
  int residue_49 = (aux + st.buffer[1]) & 3;
  switch (residue_49)
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
  int anchor_79 = local_arr[aux % 3];
  acc = (acc + (anchor_79 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000524_2413_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000524_2413_0 st_1 = {0};
  struct FilterState_R000524_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_80_1 = local_arr_1[aux_1 % 3];
  int mask_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_80_2 * 2)) & 127;
  int threshold_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_32_1) & 63;
  aux_2 = (aux_2 + threshold_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_88_1 > 42)
  {
    acc_1 = ((acc_1 + (offset_88_1 * 2)) + 5) & 127;
    aux_1 ^= offset_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_88_2 > 42)
  {
    acc_2 = ((acc_2 + (offset_88_2 * 2)) + 5) & 127;
    aux_2 ^= offset_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_88_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_77_1)
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

  switch (phase_77_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_80_1 == mask_80_2);
  assert(threshold_32_1 == threshold_32_2);
  assert(offset_88_1 == offset_88_2);
  assert(phase_77_1 == phase_77_2);
}

int fn_R000524_2413_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000524_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int mask_80 = local_arr[aux % 3];
  acc = (acc + (mask_80 * 2)) & 127;
  int threshold_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_32) & 63;
  acc ^= aux;
  int offset_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_88 > 42)
  {
    acc = ((acc + (offset_88 * 2)) + 5) & 127;
    aux ^= offset_88 & 15;
  }
  else
  {
    acc = ((acc - offset_88) + 11) & 127;
    aux += 3;
  }
  int phase_77 = (aux + st.buffer[1]) & 3;
  switch (phase_77)
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

void main()
{
  int sec_r000524_0_1;
  int sec_r000524_0_2;
  int sec_r000524_1_1;
  int sec_r000524_1_2;
  int sec_r000524_2_1;
  int sec_r000524_2_2;
  int sec_r000524_3_1;
  int sec_r000524_3_2;
  int sec_r000524_4_1;
  int sec_r000524_4_2;
  int sec_r000524_5_1;
  int sec_r000524_5_2;
  int sec_r000524_6_1;
  int sec_r000524_6_2;
  int sec_r000524_7_1;
  int sec_r000524_7_2;
  int sec_r000524_8_1;
  int sec_r000524_8_2;
  int sec_r000524_9_1;
  int sec_r000524_9_2;
  int sec_r000524_10_1;
  int sec_r000524_10_2;
  int sec_r000524_11_1;
  int sec_r000524_11_2;
  int sec_r000524_12_1;
  int sec_r000524_12_2;
  int sec_r000524_13_1;
  int sec_r000524_13_2;
  int sec_r000524_14_1;
  int sec_r000524_14_2;
  int sec_r000524_15_1;
  int sec_r000524_15_2;
  int sec_r000524_16_1;
  int sec_r000524_16_2;
  int sec_r000524_17_1;
  int sec_r000524_17_2;
  int sec_r000524_18_1;
  int sec_r000524_18_2;
  int sec_r000524_19_1;
  int sec_r000524_19_2;
  int sec_r000524_20_1;
  int sec_r000524_20_2;
  int pub_r000524_0_1;
  int pub_r000524_0_2;
  int pub_r000524_1_1;
  int pub_r000524_1_2;
  int pub_r000524_2_1;
  int pub_r000524_2_2;
  int pub_r000524_3_1;
  int pub_r000524_3_2;
  int pub_r000524_4_1;
  int pub_r000524_4_2;
  int pub_r000524_5_1;
  int pub_r000524_5_2;
  int pub_r000524_6_1;
  int pub_r000524_6_2;
  int pub_r000524_7_1;
  int pub_r000524_7_2;
  int pub_r000524_8_1;
  int pub_r000524_8_2;
  int pub_r000524_9_1;
  int pub_r000524_9_2;
  int pub_r000524_10_1;
  int pub_r000524_10_2;
  int pub_r000524_11_1;
  int pub_r000524_11_2;
  int pub_r000524_12_1;
  int pub_r000524_12_2;
  int pub_r000524_13_1;
  int pub_r000524_13_2;
  int pub_r000524_14_1;
  int pub_r000524_14_2;
  int pub_r000524_15_1;
  int pub_r000524_15_2;
  int pub_r000524_16_1;
  int pub_r000524_16_2;
  int pub_r000524_17_1;
  int pub_r000524_17_2;
  int pub_r000524_18_1;
  int pub_r000524_18_2;
  int pub_r000524_19_1;
  int pub_r000524_19_2;
  int pub_r000524_20_1;
  int pub_r000524_20_2;
  int pub_r000524_21_1;
  int pub_r000524_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000524_0_1 >= (-100)) && (pub_r000524_0_1 <= 100));
  __CPROVER_assume((pub_r000524_0_2 >= (-100)) && (pub_r000524_0_2 <= 100));
  __CPROVER_assume((pub_r000524_1_1 >= (-100)) && (pub_r000524_1_1 <= 100));
  __CPROVER_assume((pub_r000524_1_2 >= (-100)) && (pub_r000524_1_2 <= 100));
  __CPROVER_assume((pub_r000524_2_1 >= (-100)) && (pub_r000524_2_1 <= 100));
  __CPROVER_assume((pub_r000524_2_2 >= (-100)) && (pub_r000524_2_2 <= 100));
  __CPROVER_assume((pub_r000524_3_1 >= (-100)) && (pub_r000524_3_1 <= 100));
  __CPROVER_assume((pub_r000524_3_2 >= (-100)) && (pub_r000524_3_2 <= 100));
  __CPROVER_assume((pub_r000524_4_1 >= (-100)) && (pub_r000524_4_1 <= 100));
  __CPROVER_assume((pub_r000524_4_2 >= (-100)) && (pub_r000524_4_2 <= 100));
  __CPROVER_assume((pub_r000524_5_1 >= (-100)) && (pub_r000524_5_1 <= 100));
  __CPROVER_assume((pub_r000524_5_2 >= (-100)) && (pub_r000524_5_2 <= 100));
  __CPROVER_assume((pub_r000524_6_1 >= (-100)) && (pub_r000524_6_1 <= 100));
  __CPROVER_assume((pub_r000524_6_2 >= (-100)) && (pub_r000524_6_2 <= 100));
  __CPROVER_assume((pub_r000524_7_1 >= (-100)) && (pub_r000524_7_1 <= 100));
  __CPROVER_assume((pub_r000524_7_2 >= (-100)) && (pub_r000524_7_2 <= 100));
  __CPROVER_assume((pub_r000524_8_1 >= (-100)) && (pub_r000524_8_1 <= 100));
  __CPROVER_assume((pub_r000524_8_2 >= (-100)) && (pub_r000524_8_2 <= 100));
  __CPROVER_assume((pub_r000524_9_1 >= (-100)) && (pub_r000524_9_1 <= 100));
  __CPROVER_assume((pub_r000524_9_2 >= (-100)) && (pub_r000524_9_2 <= 100));
  __CPROVER_assume((pub_r000524_10_1 >= (-100)) && (pub_r000524_10_1 <= 100));
  __CPROVER_assume((pub_r000524_10_2 >= (-100)) && (pub_r000524_10_2 <= 100));
  __CPROVER_assume((pub_r000524_11_1 >= (-100)) && (pub_r000524_11_1 <= 100));
  __CPROVER_assume((pub_r000524_11_2 >= (-100)) && (pub_r000524_11_2 <= 100));
  __CPROVER_assume((pub_r000524_12_1 >= (-100)) && (pub_r000524_12_1 <= 100));
  __CPROVER_assume((pub_r000524_12_2 >= (-100)) && (pub_r000524_12_2 <= 100));
  __CPROVER_assume((pub_r000524_13_1 >= (-100)) && (pub_r000524_13_1 <= 100));
  __CPROVER_assume((pub_r000524_13_2 >= (-100)) && (pub_r000524_13_2 <= 100));
  __CPROVER_assume((pub_r000524_14_1 >= (-100)) && (pub_r000524_14_1 <= 100));
  __CPROVER_assume((pub_r000524_14_2 >= (-100)) && (pub_r000524_14_2 <= 100));
  __CPROVER_assume((pub_r000524_15_1 >= (-100)) && (pub_r000524_15_1 <= 100));
  __CPROVER_assume((pub_r000524_15_2 >= (-100)) && (pub_r000524_15_2 <= 100));
  __CPROVER_assume((pub_r000524_16_1 >= (-100)) && (pub_r000524_16_1 <= 100));
  __CPROVER_assume((pub_r000524_16_2 >= (-100)) && (pub_r000524_16_2 <= 100));
  __CPROVER_assume((pub_r000524_17_1 >= (-100)) && (pub_r000524_17_1 <= 100));
  __CPROVER_assume((pub_r000524_17_2 >= (-100)) && (pub_r000524_17_2 <= 100));
  __CPROVER_assume((pub_r000524_18_1 >= (-100)) && (pub_r000524_18_1 <= 100));
  __CPROVER_assume((pub_r000524_18_2 >= (-100)) && (pub_r000524_18_2 <= 100));
  __CPROVER_assume((pub_r000524_19_1 >= (-100)) && (pub_r000524_19_1 <= 100));
  __CPROVER_assume((pub_r000524_19_2 >= (-100)) && (pub_r000524_19_2 <= 100));
  __CPROVER_assume((pub_r000524_20_1 >= (-100)) && (pub_r000524_20_1 <= 100));
  __CPROVER_assume((pub_r000524_20_2 >= (-100)) && (pub_r000524_20_2 <= 100));
  __CPROVER_assume((pub_r000524_21_1 >= (-100)) && (pub_r000524_21_1 <= 100));
  __CPROVER_assume((pub_r000524_21_2 >= (-100)) && (pub_r000524_21_2 <= 100));
  __CPROVER_assume((sec_r000524_0_1 >= 0) && (sec_r000524_0_1 <= 255));
  __CPROVER_assume((sec_r000524_0_2 >= 0) && (sec_r000524_0_2 <= 255));
  __CPROVER_assume((sec_r000524_1_1 >= 0) && (sec_r000524_1_1 <= 255));
  __CPROVER_assume((sec_r000524_1_2 >= 0) && (sec_r000524_1_2 <= 255));
  __CPROVER_assume((sec_r000524_2_1 >= 0) && (sec_r000524_2_1 <= 255));
  __CPROVER_assume((sec_r000524_2_2 >= 0) && (sec_r000524_2_2 <= 255));
  __CPROVER_assume((sec_r000524_3_1 >= 0) && (sec_r000524_3_1 <= 255));
  __CPROVER_assume((sec_r000524_3_2 >= 0) && (sec_r000524_3_2 <= 255));
  __CPROVER_assume((sec_r000524_4_1 >= 0) && (sec_r000524_4_1 <= 255));
  __CPROVER_assume((sec_r000524_4_2 >= 0) && (sec_r000524_4_2 <= 255));
  __CPROVER_assume((sec_r000524_5_1 >= 0) && (sec_r000524_5_1 <= 255));
  __CPROVER_assume((sec_r000524_5_2 >= 0) && (sec_r000524_5_2 <= 255));
  __CPROVER_assume((sec_r000524_6_1 >= 0) && (sec_r000524_6_1 <= 255));
  __CPROVER_assume((sec_r000524_6_2 >= 0) && (sec_r000524_6_2 <= 255));
  __CPROVER_assume((sec_r000524_7_1 >= 0) && (sec_r000524_7_1 <= 255));
  __CPROVER_assume((sec_r000524_7_2 >= 0) && (sec_r000524_7_2 <= 255));
  __CPROVER_assume((sec_r000524_8_1 >= 0) && (sec_r000524_8_1 <= 255));
  __CPROVER_assume((sec_r000524_8_2 >= 0) && (sec_r000524_8_2 <= 255));
  __CPROVER_assume((sec_r000524_9_1 >= 0) && (sec_r000524_9_1 <= 255));
  __CPROVER_assume((sec_r000524_9_2 >= 0) && (sec_r000524_9_2 <= 255));
  __CPROVER_assume((sec_r000524_10_1 >= 0) && (sec_r000524_10_1 <= 255));
  __CPROVER_assume((sec_r000524_10_2 >= 0) && (sec_r000524_10_2 <= 255));
  __CPROVER_assume((sec_r000524_11_1 >= 0) && (sec_r000524_11_1 <= 255));
  __CPROVER_assume((sec_r000524_11_2 >= 0) && (sec_r000524_11_2 <= 255));
  __CPROVER_assume((sec_r000524_12_1 >= 0) && (sec_r000524_12_1 <= 255));
  __CPROVER_assume((sec_r000524_12_2 >= 0) && (sec_r000524_12_2 <= 255));
  __CPROVER_assume((sec_r000524_13_1 >= 0) && (sec_r000524_13_1 <= 255));
  __CPROVER_assume((sec_r000524_13_2 >= 0) && (sec_r000524_13_2 <= 255));
  __CPROVER_assume((sec_r000524_14_1 >= 0) && (sec_r000524_14_1 <= 255));
  __CPROVER_assume((sec_r000524_14_2 >= 0) && (sec_r000524_14_2 <= 255));
  __CPROVER_assume((sec_r000524_15_1 >= 0) && (sec_r000524_15_1 <= 255));
  __CPROVER_assume((sec_r000524_15_2 >= 0) && (sec_r000524_15_2 <= 255));
  __CPROVER_assume((sec_r000524_16_1 >= 0) && (sec_r000524_16_1 <= 255));
  __CPROVER_assume((sec_r000524_16_2 >= 0) && (sec_r000524_16_2 <= 255));
  __CPROVER_assume((sec_r000524_17_1 >= 0) && (sec_r000524_17_1 <= 255));
  __CPROVER_assume((sec_r000524_17_2 >= 0) && (sec_r000524_17_2 <= 255));
  __CPROVER_assume((sec_r000524_18_1 >= 0) && (sec_r000524_18_1 <= 255));
  __CPROVER_assume((sec_r000524_18_2 >= 0) && (sec_r000524_18_2 <= 255));
  __CPROVER_assume((sec_r000524_19_1 >= 0) && (sec_r000524_19_1 <= 255));
  __CPROVER_assume((sec_r000524_19_2 >= 0) && (sec_r000524_19_2 <= 255));
  __CPROVER_assume((sec_r000524_20_1 >= 0) && (sec_r000524_20_1 <= 255));
  __CPROVER_assume((sec_r000524_20_2 >= 0) && (sec_r000524_20_2 <= 255));
  struct FilterState_R000524_2413_0 st_var_0_1 = {0};
  struct FilterState_R000524_2413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000524_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000524_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000524_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000524_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000524_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000524_0_2 + 7) & 15;
  struct CipherContext_R000524_2413_1 st_var_1_1 = {0};
  struct CipherContext_R000524_2413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000524_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000524_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000524_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000524_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000524_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000524_0_2 + 9) & 15;
  struct EventLog_R000524_2413_2 st_var_2_1 = {0};
  struct EventLog_R000524_2413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000524_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000524_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000524_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000524_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000524_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000524_0_2 + 11) & 15;
  struct Transaction_R000524_2413_3 st_var_3_1 = {0};
  struct Transaction_R000524_2413_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000524_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000524_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000524_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000524_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000524_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000524_0_2 + 13) & 15;
  union PacketPayload_R000524_2413_0 u_var_1;
  union PacketPayload_R000524_2413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (5 & 31);
  int stage_v_0_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (5 & 31);
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= (stage_v_0_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_0_2 << 1) & 127;
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_4_1 = ((((sec_r000524_7_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_14_1) + 6) & 127;
  int stage_v_4_2 = ((((sec_r000524_7_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_4_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_4_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = ((((stage_v_4_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_7_1) + 21) & 127;
  int stage_v_5_2 = ((((stage_v_4_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_5_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_5_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = ((((sec_r000524_8_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_3_1) + 22) & 127;
  int stage_v_6_2 = ((((sec_r000524_8_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_6_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_6_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((((stage_v_5_1 * 3) + (sec_r000524_14_1 * 2)) - pub_r000524_1_1) + 25) & 127;
  int stage_v_7_2 = ((((stage_v_5_2 * 3) + (sec_r000524_14_2 * 2)) - pub_r000524_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_7_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_7_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = ((((stage_v_5_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_19_1) + 15) & 127;
  int stage_v_8_2 = ((((stage_v_5_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_19_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_8_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_8_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = ((((stage_v_7_1 * 3) + (sec_r000524_15_1 * 2)) - pub_r000524_10_1) + 3) & 127;
  int stage_v_9_2 = ((((stage_v_7_2 * 3) + (sec_r000524_15_2 * 2)) - pub_r000524_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_9_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_9_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = ((((sec_r000524_6_1 * 3) + (sec_r000524_6_1 * 2)) - pub_r000524_21_1) + 5) & 127;
  int stage_v_10_2 = ((((sec_r000524_6_2 * 3) + (sec_r000524_6_2 * 2)) - pub_r000524_21_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_10_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_10_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((((stage_v_5_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_18_1) + 11) & 127;
  int stage_v_11_2 = ((((stage_v_5_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_18_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_11_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_11_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((((stage_v_8_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_17_1) + 9) & 127;
  int stage_v_12_2 = ((((stage_v_8_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_17_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_12_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_12_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((((stage_v_10_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_16_1) + 33) & 127;
  int stage_v_13_2 = ((((stage_v_10_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_13_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_13_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = ((((sec_r000524_8_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_1_1) + 6) & 127;
  int stage_v_14_2 = ((((sec_r000524_8_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_14_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_14_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((((stage_v_6_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_7_1) + 19) & 127;
  int stage_v_15_2 = ((((stage_v_6_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_15_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_15_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((((stage_v_9_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_19_1) + 6) & 127;
  int stage_v_16_2 = ((((stage_v_9_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_19_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_16_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_16_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = ((((sec_r000524_19_1 * 3) + (sec_r000524_19_1 * 2)) - pub_r000524_4_1) + 28) & 127;
  int stage_v_17_2 = ((((sec_r000524_19_2 * 3) + (sec_r000524_19_2 * 2)) - pub_r000524_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_17_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_17_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = ((((stage_v_8_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_3_1) + 36) & 127;
  int stage_v_18_2 = ((((stage_v_8_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_18_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_18_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = ((((stage_v_11_1 * 3) + (sec_r000524_17_1 * 2)) - pub_r000524_15_1) + 7) & 127;
  int stage_v_19_2 = ((((stage_v_11_2 * 3) + (sec_r000524_17_2 * 2)) - pub_r000524_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_19_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_19_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((((stage_v_8_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_19_1) + 13) & 127;
  int stage_v_20_2 = ((((stage_v_8_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_19_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_20_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_20_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((((stage_v_19_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_3_1) + 24) & 127;
  int stage_v_21_2 = ((((stage_v_19_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_21_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_21_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((((sec_r000524_20_1 * 3) + (sec_r000524_20_1 * 2)) - pub_r000524_12_1) + 15) & 127;
  int stage_v_22_2 = ((((sec_r000524_20_2 * 3) + (sec_r000524_20_2 * 2)) - pub_r000524_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_22_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_22_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((((stage_v_14_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_11_1) + 17) & 127;
  int stage_v_23_2 = ((((stage_v_14_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_23_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_23_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = ((((stage_v_19_1 * 3) + (sec_r000524_12_1 * 2)) - pub_r000524_3_1) + 6) & 127;
  int stage_v_24_2 = ((((stage_v_19_2 * 3) + (sec_r000524_12_2 * 2)) - pub_r000524_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_24_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_24_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((((stage_v_19_1 * 3) + (sec_r000524_4_1 * 2)) - pub_r000524_7_1) + 12) & 127;
  int stage_v_25_2 = ((((stage_v_19_2 * 3) + (sec_r000524_4_2 * 2)) - pub_r000524_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_25_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_25_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((((stage_v_14_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_14_1) + 21) & 127;
  int stage_v_26_2 = ((((stage_v_14_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_26_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_26_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((((sec_r000524_4_1 * 3) + (sec_r000524_4_1 * 2)) - pub_r000524_1_1) + 33) & 127;
  int stage_v_27_2 = ((((sec_r000524_4_2 * 3) + (sec_r000524_4_2 * 2)) - pub_r000524_1_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_27_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_27_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((((sec_r000524_20_1 * 3) + (sec_r000524_20_1 * 2)) - pub_r000524_8_1) + 4) & 127;
  int stage_v_28_2 = ((((sec_r000524_20_2 * 3) + (sec_r000524_20_2 * 2)) - pub_r000524_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_28_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_28_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((((stage_v_14_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_0_1) + 25) & 127;
  int stage_v_29_2 = ((((stage_v_14_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_29_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_29_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((((stage_v_23_1 * 3) + (sec_r000524_17_1 * 2)) - pub_r000524_18_1) + 35) & 127;
  int stage_v_30_2 = ((((stage_v_23_2 * 3) + (sec_r000524_17_2 * 2)) - pub_r000524_18_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_30_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_30_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((((sec_r000524_6_1 * 3) + (sec_r000524_6_1 * 2)) - pub_r000524_11_1) + 25) & 127;
  int stage_v_31_2 = ((((sec_r000524_6_2 * 3) + (sec_r000524_6_2 * 2)) - pub_r000524_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_31_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_31_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((((sec_r000524_6_1 * 3) + (sec_r000524_6_1 * 2)) - pub_r000524_2_1) + 30) & 127;
  int stage_v_32_2 = ((((sec_r000524_6_2 * 3) + (sec_r000524_6_2 * 2)) - pub_r000524_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_32_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_32_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((((stage_v_12_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_2_1) + 18) & 127;
  int stage_v_33_2 = ((((stage_v_12_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_33_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_33_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = ((((stage_v_29_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_4_1) + 10) & 127;
  int stage_v_34_2 = ((((stage_v_29_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_34_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_34_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((((sec_r000524_6_1 * 3) + (sec_r000524_6_1 * 2)) - pub_r000524_15_1) + 6) & 127;
  int stage_v_35_2 = ((((sec_r000524_6_2 * 3) + (sec_r000524_6_2 * 2)) - pub_r000524_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_35_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_35_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((((stage_v_7_1 * 3) + (sec_r000524_14_1 * 2)) - pub_r000524_20_1) + 26) & 127;
  int stage_v_36_2 = ((((stage_v_7_2 * 3) + (sec_r000524_14_2 * 2)) - pub_r000524_20_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_36_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_36_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((((stage_v_31_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_8_1) + 32) & 127;
  int stage_v_37_2 = ((((stage_v_31_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_37_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_37_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((((sec_r000524_10_1 * 3) + (sec_r000524_10_1 * 2)) - pub_r000524_9_1) + 25) & 127;
  int stage_v_38_2 = ((((sec_r000524_10_2 * 3) + (sec_r000524_10_2 * 2)) - pub_r000524_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_38_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_38_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((((sec_r000524_18_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_8_1) + 18) & 127;
  int stage_v_39_2 = ((((sec_r000524_18_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_39_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_39_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((((stage_v_17_1 * 3) + (sec_r000524_14_1 * 2)) - pub_r000524_11_1) + 3) & 127;
  int stage_v_40_2 = ((((stage_v_17_2 * 3) + (sec_r000524_14_2 * 2)) - pub_r000524_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_40_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_40_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((((stage_v_39_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_0_1) + 16) & 127;
  int stage_v_41_2 = ((((stage_v_39_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_41_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_41_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((((sec_r000524_2_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_13_1) + 18) & 127;
  int stage_v_42_2 = ((((sec_r000524_2_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_42_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_42_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((((sec_r000524_6_1 * 3) + (sec_r000524_6_1 * 2)) - pub_r000524_7_1) + 7) & 127;
  int stage_v_43_2 = ((((sec_r000524_6_2 * 3) + (sec_r000524_6_2 * 2)) - pub_r000524_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_43_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_43_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((((stage_v_26_1 * 3) + (sec_r000524_20_1 * 2)) - pub_r000524_10_1) + 19) & 127;
  int stage_v_44_2 = ((((stage_v_26_2 * 3) + (sec_r000524_20_2 * 2)) - pub_r000524_10_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_44_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_44_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((((sec_r000524_16_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_5_1) + 12) & 127;
  int stage_v_45_2 = ((((sec_r000524_16_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_45_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_45_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((((stage_v_33_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_4_1) + 12) & 127;
  int stage_v_46_2 = ((((stage_v_33_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_46_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_46_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((((stage_v_28_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_9_1) + 19) & 127;
  int stage_v_47_2 = ((((stage_v_28_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_47_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_47_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((((stage_v_6_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_4_1) + 35) & 127;
  int stage_v_48_2 = ((((stage_v_6_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_48_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_48_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((((stage_v_32_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_1_1) + 24) & 127;
  int stage_v_49_2 = ((((stage_v_32_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_49_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_49_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((((stage_v_46_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_2_1) + 18) & 127;
  int stage_v_50_2 = ((((stage_v_46_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_50_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_50_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((((stage_v_10_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_17_1) + 7) & 127;
  int stage_v_51_2 = ((((stage_v_10_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_17_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_51_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_51_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((((stage_v_42_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_14_1) + 30) & 127;
  int stage_v_52_2 = ((((stage_v_42_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_52_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_52_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((((sec_r000524_19_1 * 3) + (sec_r000524_19_1 * 2)) - pub_r000524_1_1) + 17) & 127;
  int stage_v_53_2 = ((((sec_r000524_19_2 * 3) + (sec_r000524_19_2 * 2)) - pub_r000524_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_53_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_53_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((((stage_v_33_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_16_1) + 35) & 127;
  int stage_v_54_2 = ((((stage_v_33_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_54_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_54_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((((sec_r000524_5_1 * 3) + (sec_r000524_5_1 * 2)) - pub_r000524_11_1) + 14) & 127;
  int stage_v_55_2 = ((((sec_r000524_5_2 * 3) + (sec_r000524_5_2 * 2)) - pub_r000524_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_55_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_55_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((((stage_v_35_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_16_1) + 30) & 127;
  int stage_v_56_2 = ((((stage_v_35_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_56_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_56_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((((stage_v_40_1 * 3) + (sec_r000524_15_1 * 2)) - pub_r000524_18_1) + 37) & 127;
  int stage_v_57_2 = ((((stage_v_40_2 * 3) + (sec_r000524_15_2 * 2)) - pub_r000524_18_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_57_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_57_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((((stage_v_56_1 * 3) + (sec_r000524_15_1 * 2)) - pub_r000524_15_1) + 32) & 127;
  int stage_v_58_2 = ((((stage_v_56_2 * 3) + (sec_r000524_15_2 * 2)) - pub_r000524_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_58_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_58_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((((sec_r000524_13_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_8_1) + 11) & 127;
  int stage_v_59_2 = ((((sec_r000524_13_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_59_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_59_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((((stage_v_45_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_19_1) + 29) & 127;
  int stage_v_60_2 = ((((stage_v_45_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_19_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((((stage_v_24_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_19_1) + 32) & 127;
  int stage_v_61_2 = ((((stage_v_24_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_19_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_61_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_61_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((((stage_v_33_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_16_1) + 31) & 127;
  int stage_v_62_2 = ((((stage_v_33_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_16_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_62_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_62_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((((stage_v_8_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_10_1) + 7) & 127;
  int stage_v_63_2 = ((((stage_v_8_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_10_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_63_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_63_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((((stage_v_29_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_4_1) + 32) & 127;
  int stage_v_64_2 = ((((stage_v_29_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_4_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_64_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_64_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((((sec_r000524_2_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_12_1) + 7) & 127;
  int stage_v_65_2 = ((((sec_r000524_2_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_65_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_65_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((((sec_r000524_19_1 * 3) + (sec_r000524_19_1 * 2)) - pub_r000524_19_1) + 4) & 127;
  int stage_v_66_2 = ((((sec_r000524_19_2 * 3) + (sec_r000524_19_2 * 2)) - pub_r000524_19_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_66_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_66_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((((sec_r000524_17_1 * 3) + (sec_r000524_17_1 * 2)) - pub_r000524_14_1) + 8) & 127;
  int stage_v_67_2 = ((((sec_r000524_17_2 * 3) + (sec_r000524_17_2 * 2)) - pub_r000524_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_67_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_67_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((((stage_v_47_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_7_1) + 24) & 127;
  int stage_v_68_2 = ((((stage_v_47_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_68_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_68_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((((stage_v_27_1 * 3) + (sec_r000524_10_1 * 2)) - pub_r000524_1_1) + 5) & 127;
  int stage_v_69_2 = ((((stage_v_27_2 * 3) + (sec_r000524_10_2 * 2)) - pub_r000524_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_69_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_69_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((((sec_r000524_16_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_20_1) + 13) & 127;
  int stage_v_70_2 = ((((sec_r000524_16_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_20_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_70_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_70_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((((sec_r000524_9_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_11_1) + 21) & 127;
  int stage_v_71_2 = ((((sec_r000524_9_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_71_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_71_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((((stage_v_61_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_13_1) + 17) & 127;
  int stage_v_72_2 = ((((stage_v_61_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_72_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_72_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((((stage_v_63_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_7_1) + 21) & 127;
  int stage_v_73_2 = ((((stage_v_63_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((((stage_v_50_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_13_1) + 24) & 127;
  int stage_v_74_2 = ((((stage_v_50_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_13_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_74_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_74_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((((stage_v_4_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_12_1) + 30) & 127;
  int stage_v_75_2 = ((((stage_v_4_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_75_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_75_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((((stage_v_8_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_0_1) + 16) & 127;
  int stage_v_76_2 = ((((stage_v_8_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((((sec_r000524_4_1 * 3) + (sec_r000524_4_1 * 2)) - pub_r000524_6_1) + 9) & 127;
  int stage_v_77_2 = ((((sec_r000524_4_2 * 3) + (sec_r000524_4_2 * 2)) - pub_r000524_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((((stage_v_65_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_16_1) + 16) & 127;
  int stage_v_78_2 = ((((stage_v_65_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_16_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((((stage_v_34_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_5_1) + 10) & 127;
  int stage_v_79_2 = ((((stage_v_34_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_79_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_79_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((((stage_v_69_1 * 3) + (sec_r000524_11_1 * 2)) - pub_r000524_0_1) + 23) & 127;
  int stage_v_80_2 = ((((stage_v_69_2 * 3) + (sec_r000524_11_2 * 2)) - pub_r000524_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((((stage_v_6_1 * 3) + (sec_r000524_12_1 * 2)) - pub_r000524_16_1) + 22) & 127;
  int stage_v_81_2 = ((((stage_v_6_2 * 3) + (sec_r000524_12_2 * 2)) - pub_r000524_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((((stage_v_23_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_6_1) + 21) & 127;
  int stage_v_82_2 = ((((stage_v_23_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((((sec_r000524_17_1 * 3) + (sec_r000524_17_1 * 2)) - pub_r000524_10_1) + 33) & 127;
  int stage_v_83_2 = ((((sec_r000524_17_2 * 3) + (sec_r000524_17_2 * 2)) - pub_r000524_10_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((((stage_v_72_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_3_1) + 9) & 127;
  int stage_v_84_2 = ((((stage_v_72_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((((stage_v_37_1 * 3) + (sec_r000524_11_1 * 2)) - pub_r000524_17_1) + 27) & 127;
  int stage_v_85_2 = ((((stage_v_37_2 * 3) + (sec_r000524_11_2 * 2)) - pub_r000524_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((((sec_r000524_9_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_21_1) + 30) & 127;
  int stage_v_86_2 = ((((sec_r000524_9_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_21_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((((stage_v_27_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_10_1) + 15) & 127;
  int stage_v_87_2 = ((((stage_v_27_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((((sec_r000524_0_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_12_1) + 14) & 127;
  int stage_v_88_2 = ((((sec_r000524_0_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((((sec_r000524_3_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_0_1) + 31) & 127;
  int stage_v_89_2 = ((((sec_r000524_3_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((((stage_v_17_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_6_1) + 12) & 127;
  int stage_v_90_2 = ((((stage_v_17_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((((stage_v_20_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_8_1) + 22) & 127;
  int stage_v_91_2 = ((((stage_v_20_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_8_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((((stage_v_89_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_8_1) + 26) & 127;
  int stage_v_92_2 = ((((stage_v_89_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((((stage_v_53_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_13_1) + 8) & 127;
  int stage_v_93_2 = ((((stage_v_53_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((((stage_v_64_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_1_1) + 10) & 127;
  int stage_v_94_2 = ((((stage_v_64_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((((sec_r000524_12_1 * 3) + (sec_r000524_12_1 * 2)) - pub_r000524_1_1) + 20) & 127;
  int stage_v_95_2 = ((((sec_r000524_12_2 * 3) + (sec_r000524_12_2 * 2)) - pub_r000524_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((((sec_r000524_5_1 * 3) + (sec_r000524_5_1 * 2)) - pub_r000524_17_1) + 4) & 127;
  int stage_v_96_2 = ((((sec_r000524_5_2 * 3) + (sec_r000524_5_2 * 2)) - pub_r000524_17_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((((sec_r000524_20_1 * 3) + (sec_r000524_20_1 * 2)) - pub_r000524_21_1) + 11) & 127;
  int stage_v_97_2 = ((((sec_r000524_20_2 * 3) + (sec_r000524_20_2 * 2)) - pub_r000524_21_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((((sec_r000524_3_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_0_1) + 21) & 127;
  int stage_v_98_2 = ((((sec_r000524_3_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((((stage_v_17_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_18_1) + 8) & 127;
  int stage_v_99_2 = ((((stage_v_17_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_18_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((((sec_r000524_15_1 * 3) + (sec_r000524_15_1 * 2)) - pub_r000524_20_1) + 11) & 127;
  int stage_v_100_2 = ((((sec_r000524_15_2 * 3) + (sec_r000524_15_2 * 2)) - pub_r000524_20_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((((stage_v_93_1 * 3) + (sec_r000524_10_1 * 2)) - pub_r000524_2_1) + 6) & 127;
  int stage_v_101_2 = ((((stage_v_93_2 * 3) + (sec_r000524_10_2 * 2)) - pub_r000524_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((((stage_v_82_1 * 3) + (sec_r000524_4_1 * 2)) - pub_r000524_9_1) + 6) & 127;
  int stage_v_102_2 = ((((stage_v_82_2 * 3) + (sec_r000524_4_2 * 2)) - pub_r000524_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((((stage_v_71_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_15_1) + 19) & 127;
  int stage_v_103_2 = ((((stage_v_71_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((((stage_v_42_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_4_1) + 31) & 127;
  int stage_v_104_2 = ((((stage_v_42_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((((sec_r000524_2_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_21_1) + 23) & 127;
  int stage_v_105_2 = ((((sec_r000524_2_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_21_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((((stage_v_18_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_4_1) + 20) & 127;
  int stage_v_106_2 = ((((stage_v_18_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((((stage_v_82_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_8_1) + 32) & 127;
  int stage_v_107_2 = ((((stage_v_82_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((((sec_r000524_9_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_21_1) + 9) & 127;
  int stage_v_108_2 = ((((sec_r000524_9_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_21_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((((sec_r000524_15_1 * 3) + (sec_r000524_15_1 * 2)) - pub_r000524_20_1) + 35) & 127;
  int stage_v_109_2 = ((((sec_r000524_15_2 * 3) + (sec_r000524_15_2 * 2)) - pub_r000524_20_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((((stage_v_73_1 * 3) + (sec_r000524_17_1 * 2)) - pub_r000524_17_1) + 8) & 127;
  int stage_v_110_2 = ((((stage_v_73_2 * 3) + (sec_r000524_17_2 * 2)) - pub_r000524_17_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((((stage_v_65_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_1_1) + 36) & 127;
  int stage_v_111_2 = ((((stage_v_65_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((((stage_v_76_1 * 3) + (sec_r000524_14_1 * 2)) - pub_r000524_18_1) + 25) & 127;
  int stage_v_112_2 = ((((stage_v_76_2 * 3) + (sec_r000524_14_2 * 2)) - pub_r000524_18_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((((sec_r000524_14_1 * 3) + (sec_r000524_14_1 * 2)) - pub_r000524_11_1) + 12) & 127;
  int stage_v_113_2 = ((((sec_r000524_14_2 * 3) + (sec_r000524_14_2 * 2)) - pub_r000524_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((((sec_r000524_3_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_20_1) + 36) & 127;
  int stage_v_114_2 = ((((sec_r000524_3_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_20_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((((stage_v_105_1 * 3) + (sec_r000524_19_1 * 2)) - pub_r000524_0_1) + 15) & 127;
  int stage_v_115_2 = ((((stage_v_105_2 * 3) + (sec_r000524_19_2 * 2)) - pub_r000524_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((((sec_r000524_14_1 * 3) + (sec_r000524_14_1 * 2)) - pub_r000524_10_1) + 36) & 127;
  int stage_v_116_2 = ((((sec_r000524_14_2 * 3) + (sec_r000524_14_2 * 2)) - pub_r000524_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((((stage_v_5_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_1_1) + 25) & 127;
  int stage_v_117_2 = ((((stage_v_5_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((((stage_v_4_1 * 3) + (sec_r000524_12_1 * 2)) - pub_r000524_7_1) + 21) & 127;
  int stage_v_118_2 = ((((stage_v_4_2 * 3) + (sec_r000524_12_2 * 2)) - pub_r000524_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((((stage_v_37_1 * 3) + (sec_r000524_6_1 * 2)) - pub_r000524_1_1) + 4) & 127;
  int stage_v_119_2 = ((((stage_v_37_2 * 3) + (sec_r000524_6_2 * 2)) - pub_r000524_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((((sec_r000524_15_1 * 3) + (sec_r000524_15_1 * 2)) - pub_r000524_0_1) + 12) & 127;
  int stage_v_120_2 = ((((sec_r000524_15_2 * 3) + (sec_r000524_15_2 * 2)) - pub_r000524_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((((sec_r000524_11_1 * 3) + (sec_r000524_11_1 * 2)) - pub_r000524_13_1) + 18) & 127;
  int stage_v_121_2 = ((((sec_r000524_11_2 * 3) + (sec_r000524_11_2 * 2)) - pub_r000524_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((((stage_v_43_1 * 3) + (sec_r000524_12_1 * 2)) - pub_r000524_18_1) + 30) & 127;
  int stage_v_122_2 = ((((stage_v_43_2 * 3) + (sec_r000524_12_2 * 2)) - pub_r000524_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((((stage_v_75_1 * 3) + (sec_r000524_6_1 * 2)) - pub_r000524_4_1) + 7) & 127;
  int stage_v_123_2 = ((((stage_v_75_2 * 3) + (sec_r000524_6_2 * 2)) - pub_r000524_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((((sec_r000524_2_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_18_1) + 29) & 127;
  int stage_v_124_2 = ((((sec_r000524_2_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_18_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((((sec_r000524_15_1 * 3) + (sec_r000524_15_1 * 2)) - pub_r000524_14_1) + 4) & 127;
  int stage_v_125_2 = ((((sec_r000524_15_2 * 3) + (sec_r000524_15_2 * 2)) - pub_r000524_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((((sec_r000524_2_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_17_1) + 29) & 127;
  int stage_v_126_2 = ((((sec_r000524_2_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((((sec_r000524_11_1 * 3) + (sec_r000524_11_1 * 2)) - pub_r000524_9_1) + 26) & 127;
  int stage_v_127_2 = ((((sec_r000524_11_2 * 3) + (sec_r000524_11_2 * 2)) - pub_r000524_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((((stage_v_92_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_7_1) + 23) & 127;
  int stage_v_128_2 = ((((stage_v_92_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((((stage_v_74_1 * 3) + (sec_r000524_17_1 * 2)) - pub_r000524_12_1) + 23) & 127;
  int stage_v_129_2 = ((((stage_v_74_2 * 3) + (sec_r000524_17_2 * 2)) - pub_r000524_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((((stage_v_75_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_0_1) + 16) & 127;
  int stage_v_130_2 = ((((stage_v_75_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((((sec_r000524_5_1 * 3) + (sec_r000524_5_1 * 2)) - pub_r000524_17_1) + 33) & 127;
  int stage_v_131_2 = ((((sec_r000524_5_2 * 3) + (sec_r000524_5_2 * 2)) - pub_r000524_17_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((((stage_v_68_1 * 3) + (sec_r000524_14_1 * 2)) - pub_r000524_1_1) + 22) & 127;
  int stage_v_132_2 = ((((stage_v_68_2 * 3) + (sec_r000524_14_2 * 2)) - pub_r000524_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((((sec_r000524_6_1 * 3) + (sec_r000524_6_1 * 2)) - pub_r000524_12_1) + 31) & 127;
  int stage_v_133_2 = ((((sec_r000524_6_2 * 3) + (sec_r000524_6_2 * 2)) - pub_r000524_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((((stage_v_38_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_7_1) + 11) & 127;
  int stage_v_134_2 = ((((stage_v_38_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((((sec_r000524_0_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_8_1) + 8) & 127;
  int stage_v_135_2 = ((((sec_r000524_0_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((((sec_r000524_10_1 * 3) + (sec_r000524_10_1 * 2)) - pub_r000524_0_1) + 18) & 127;
  int stage_v_136_2 = ((((sec_r000524_10_2 * 3) + (sec_r000524_10_2 * 2)) - pub_r000524_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((((stage_v_82_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_15_1) + 14) & 127;
  int stage_v_137_2 = ((((stage_v_82_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((((sec_r000524_10_1 * 3) + (sec_r000524_10_1 * 2)) - pub_r000524_6_1) + 15) & 127;
  int stage_v_138_2 = ((((sec_r000524_10_2 * 3) + (sec_r000524_10_2 * 2)) - pub_r000524_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((((sec_r000524_11_1 * 3) + (sec_r000524_11_1 * 2)) - pub_r000524_17_1) + 37) & 127;
  int stage_v_139_2 = ((((sec_r000524_11_2 * 3) + (sec_r000524_11_2 * 2)) - pub_r000524_17_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((((stage_v_53_1 * 3) + (sec_r000524_14_1 * 2)) - pub_r000524_6_1) + 22) & 127;
  int stage_v_140_2 = ((((stage_v_53_2 * 3) + (sec_r000524_14_2 * 2)) - pub_r000524_6_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((((sec_r000524_3_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_8_1) + 17) & 127;
  int stage_v_141_2 = ((((sec_r000524_3_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((((stage_v_9_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_3_1) + 36) & 127;
  int stage_v_142_2 = ((((stage_v_9_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((((sec_r000524_13_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_4_1) + 29) & 127;
  int stage_v_143_2 = ((((sec_r000524_13_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((((stage_v_27_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_16_1) + 32) & 127;
  int stage_v_144_2 = ((((stage_v_27_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((((sec_r000524_2_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_0_1) + 14) & 127;
  int stage_v_145_2 = ((((sec_r000524_2_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((((stage_v_17_1 * 3) + (sec_r000524_4_1 * 2)) - pub_r000524_12_1) + 29) & 127;
  int stage_v_146_2 = ((((stage_v_17_2 * 3) + (sec_r000524_4_2 * 2)) - pub_r000524_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((((stage_v_5_1 * 3) + (sec_r000524_15_1 * 2)) - pub_r000524_13_1) + 3) & 127;
  int stage_v_147_2 = ((((stage_v_5_2 * 3) + (sec_r000524_15_2 * 2)) - pub_r000524_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((((sec_r000524_9_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_10_1) + 30) & 127;
  int stage_v_148_2 = ((((sec_r000524_9_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((((stage_v_24_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_16_1) + 24) & 127;
  int stage_v_149_2 = ((((stage_v_24_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((((stage_v_24_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_6_1) + 4) & 127;
  int stage_v_150_2 = ((((stage_v_24_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((((stage_v_72_1 * 3) + (sec_r000524_14_1 * 2)) - pub_r000524_19_1) + 19) & 127;
  int stage_v_151_2 = ((((stage_v_72_2 * 3) + (sec_r000524_14_2 * 2)) - pub_r000524_19_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((((sec_r000524_7_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_14_1) + 35) & 127;
  int stage_v_152_2 = ((((sec_r000524_7_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((((sec_r000524_17_1 * 3) + (sec_r000524_17_1 * 2)) - pub_r000524_12_1) + 27) & 127;
  int stage_v_153_2 = ((((sec_r000524_17_2 * 3) + (sec_r000524_17_2 * 2)) - pub_r000524_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((((sec_r000524_3_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_15_1) + 17) & 127;
  int stage_v_154_2 = ((((sec_r000524_3_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((((sec_r000524_0_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_7_1) + 22) & 127;
  int stage_v_155_2 = ((((sec_r000524_0_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((((sec_r000524_1_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_1_1) + 20) & 127;
  int stage_v_156_2 = ((((sec_r000524_1_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((((stage_v_29_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_20_1) + 16) & 127;
  int stage_v_157_2 = ((((stage_v_29_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_20_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((((sec_r000524_18_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_2_1) + 11) & 127;
  int stage_v_158_2 = ((((sec_r000524_18_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((((stage_v_16_1 * 3) + (sec_r000524_11_1 * 2)) - pub_r000524_6_1) + 15) & 127;
  int stage_v_159_2 = ((((stage_v_16_2 * 3) + (sec_r000524_11_2 * 2)) - pub_r000524_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((((stage_v_102_1 * 3) + (sec_r000524_6_1 * 2)) - pub_r000524_14_1) + 8) & 127;
  int stage_v_160_2 = ((((stage_v_102_2 * 3) + (sec_r000524_6_2 * 2)) - pub_r000524_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((((sec_r000524_10_1 * 3) + (sec_r000524_10_1 * 2)) - pub_r000524_6_1) + 13) & 127;
  int stage_v_161_2 = ((((sec_r000524_10_2 * 3) + (sec_r000524_10_2 * 2)) - pub_r000524_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((((sec_r000524_16_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_19_1) + 24) & 127;
  int stage_v_162_2 = ((((sec_r000524_16_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((((stage_v_24_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_18_1) + 9) & 127;
  int stage_v_163_2 = ((((stage_v_24_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_18_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((((stage_v_128_1 * 3) + (sec_r000524_11_1 * 2)) - pub_r000524_20_1) + 36) & 127;
  int stage_v_164_2 = ((((stage_v_128_2 * 3) + (sec_r000524_11_2 * 2)) - pub_r000524_20_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((((stage_v_42_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_1_1) + 15) & 127;
  int stage_v_165_2 = ((((stage_v_42_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((((stage_v_105_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_18_1) + 19) & 127;
  int stage_v_166_2 = ((((stage_v_105_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_18_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((((stage_v_67_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_20_1) + 22) & 127;
  int stage_v_167_2 = ((((stage_v_67_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_20_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((((stage_v_106_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_17_1) + 16) & 127;
  int stage_v_168_2 = ((((stage_v_106_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_17_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((((stage_v_126_1 * 3) + (sec_r000524_14_1 * 2)) - pub_r000524_16_1) + 14) & 127;
  int stage_v_169_2 = ((((stage_v_126_2 * 3) + (sec_r000524_14_2 * 2)) - pub_r000524_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((((stage_v_98_1 * 3) + (sec_r000524_5_1 * 2)) - pub_r000524_3_1) + 15) & 127;
  int stage_v_170_2 = ((((stage_v_98_2 * 3) + (sec_r000524_5_2 * 2)) - pub_r000524_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((((stage_v_25_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_14_1) + 4) & 127;
  int stage_v_171_2 = ((((stage_v_25_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((((stage_v_62_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_17_1) + 7) & 127;
  int stage_v_172_2 = ((((stage_v_62_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_17_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((((sec_r000524_12_1 * 3) + (sec_r000524_12_1 * 2)) - pub_r000524_0_1) + 14) & 127;
  int stage_v_173_2 = ((((sec_r000524_12_2 * 3) + (sec_r000524_12_2 * 2)) - pub_r000524_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((((stage_v_110_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_12_1) + 6) & 127;
  int stage_v_174_2 = ((((stage_v_110_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((((stage_v_83_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_6_1) + 36) & 127;
  int stage_v_175_2 = ((((stage_v_83_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((((stage_v_114_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_3_1) + 12) & 127;
  int stage_v_176_2 = ((((stage_v_114_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((((sec_r000524_0_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_17_1) + 3) & 127;
  int stage_v_177_2 = ((((sec_r000524_0_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_17_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((((sec_r000524_0_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_13_1) + 27) & 127;
  int stage_v_178_2 = ((((sec_r000524_0_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((((stage_v_66_1 * 3) + (sec_r000524_19_1 * 2)) - pub_r000524_6_1) + 9) & 127;
  int stage_v_179_2 = ((((stage_v_66_2 * 3) + (sec_r000524_19_2 * 2)) - pub_r000524_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((((stage_v_99_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_11_1) + 20) & 127;
  int stage_v_180_2 = ((((stage_v_99_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((((stage_v_78_1 * 3) + (sec_r000524_19_1 * 2)) - pub_r000524_0_1) + 18) & 127;
  int stage_v_181_2 = ((((stage_v_78_2 * 3) + (sec_r000524_19_2 * 2)) - pub_r000524_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((((stage_v_23_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_19_1) + 14) & 127;
  int stage_v_182_2 = ((((stage_v_23_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_19_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((((sec_r000524_1_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_0_1) + 16) & 127;
  int stage_v_183_2 = ((((sec_r000524_1_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((((stage_v_4_1 * 3) + (sec_r000524_5_1 * 2)) - pub_r000524_19_1) + 22) & 127;
  int stage_v_184_2 = ((((stage_v_4_2 * 3) + (sec_r000524_5_2 * 2)) - pub_r000524_19_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((((sec_r000524_8_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_10_1) + 5) & 127;
  int stage_v_185_2 = ((((sec_r000524_8_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((((stage_v_184_1 * 3) + (sec_r000524_10_1 * 2)) - pub_r000524_15_1) + 36) & 127;
  int stage_v_186_2 = ((((stage_v_184_2 * 3) + (sec_r000524_10_2 * 2)) - pub_r000524_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((((stage_v_19_1 * 3) + (sec_r000524_4_1 * 2)) - pub_r000524_3_1) + 27) & 127;
  int stage_v_187_2 = ((((stage_v_19_2 * 3) + (sec_r000524_4_2 * 2)) - pub_r000524_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((((sec_r000524_19_1 * 3) + (sec_r000524_19_1 * 2)) - pub_r000524_9_1) + 16) & 127;
  int stage_v_188_2 = ((((sec_r000524_19_2 * 3) + (sec_r000524_19_2 * 2)) - pub_r000524_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((((stage_v_167_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_20_1) + 7) & 127;
  int stage_v_189_2 = ((((stage_v_167_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_20_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((((stage_v_175_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_9_1) + 27) & 127;
  int stage_v_190_2 = ((((stage_v_175_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((((stage_v_94_1 * 3) + (sec_r000524_11_1 * 2)) - pub_r000524_10_1) + 14) & 127;
  int stage_v_191_2 = ((((stage_v_94_2 * 3) + (sec_r000524_11_2 * 2)) - pub_r000524_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((((stage_v_86_1 * 3) + (sec_r000524_15_1 * 2)) - pub_r000524_9_1) + 10) & 127;
  int stage_v_192_2 = ((((stage_v_86_2 * 3) + (sec_r000524_15_2 * 2)) - pub_r000524_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((((sec_r000524_15_1 * 3) + (sec_r000524_15_1 * 2)) - pub_r000524_14_1) + 12) & 127;
  int stage_v_193_2 = ((((sec_r000524_15_2 * 3) + (sec_r000524_15_2 * 2)) - pub_r000524_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((((stage_v_121_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_9_1) + 4) & 127;
  int stage_v_194_2 = ((((stage_v_121_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_9_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((((stage_v_15_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_21_1) + 33) & 127;
  int stage_v_195_2 = ((((stage_v_15_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_21_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((((sec_r000524_5_1 * 3) + (sec_r000524_5_1 * 2)) - pub_r000524_2_1) + 23) & 127;
  int stage_v_196_2 = ((((sec_r000524_5_2 * 3) + (sec_r000524_5_2 * 2)) - pub_r000524_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((((sec_r000524_15_1 * 3) + (sec_r000524_15_1 * 2)) - pub_r000524_21_1) + 35) & 127;
  int stage_v_197_2 = ((((sec_r000524_15_2 * 3) + (sec_r000524_15_2 * 2)) - pub_r000524_21_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((((sec_r000524_16_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_0_1) + 23) & 127;
  int stage_v_198_2 = ((((sec_r000524_16_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((((sec_r000524_7_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_4_1) + 22) & 127;
  int stage_v_199_2 = ((((sec_r000524_7_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((((sec_r000524_0_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_9_1) + 36) & 127;
  int stage_v_200_2 = ((((sec_r000524_0_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((((stage_v_37_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_19_1) + 22) & 127;
  int stage_v_201_2 = ((((stage_v_37_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_19_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((((sec_r000524_8_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_11_1) + 18) & 127;
  int stage_v_202_2 = ((((sec_r000524_8_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_11_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_202_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_202_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((((stage_v_123_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_1_1) + 28) & 127;
  int stage_v_203_2 = ((((stage_v_123_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((((stage_v_113_1 * 3) + (sec_r000524_17_1 * 2)) - pub_r000524_2_1) + 30) & 127;
  int stage_v_204_2 = ((((stage_v_113_2 * 3) + (sec_r000524_17_2 * 2)) - pub_r000524_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((((stage_v_5_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_10_1) + 29) & 127;
  int stage_v_205_2 = ((((stage_v_5_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_205_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_205_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((((stage_v_142_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_16_1) + 19) & 127;
  int stage_v_206_2 = ((((stage_v_142_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_206_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_206_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((((stage_v_158_1 * 3) + (sec_r000524_10_1 * 2)) - pub_r000524_11_1) + 32) & 127;
  int stage_v_207_2 = ((((stage_v_158_2 * 3) + (sec_r000524_10_2 * 2)) - pub_r000524_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((((sec_r000524_14_1 * 3) + (sec_r000524_14_1 * 2)) - pub_r000524_1_1) + 15) & 127;
  int stage_v_208_2 = ((((sec_r000524_14_2 * 3) + (sec_r000524_14_2 * 2)) - pub_r000524_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_208_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_208_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((((stage_v_136_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_3_1) + 36) & 127;
  int stage_v_209_2 = ((((stage_v_136_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((((sec_r000524_19_1 * 3) + (sec_r000524_19_1 * 2)) - pub_r000524_1_1) + 24) & 127;
  int stage_v_210_2 = ((((sec_r000524_19_2 * 3) + (sec_r000524_19_2 * 2)) - pub_r000524_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_210_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_210_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((((stage_v_179_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_7_1) + 9) & 127;
  int stage_v_211_2 = ((((stage_v_179_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_211_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_211_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((((stage_v_174_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_19_1) + 18) & 127;
  int stage_v_212_2 = ((((stage_v_174_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_19_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_212_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_212_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((((stage_v_142_1 * 3) + (sec_r000524_10_1 * 2)) - pub_r000524_20_1) + 12) & 127;
  int stage_v_213_2 = ((((stage_v_142_2 * 3) + (sec_r000524_10_2 * 2)) - pub_r000524_20_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_213_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_213_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((((sec_r000524_9_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_4_1) + 19) & 127;
  int stage_v_214_2 = ((((sec_r000524_9_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_214_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_214_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((((sec_r000524_13_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_16_1) + 13) & 127;
  int stage_v_215_2 = ((((sec_r000524_13_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_215_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_215_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((((stage_v_129_1 * 3) + (sec_r000524_10_1 * 2)) - pub_r000524_13_1) + 15) & 127;
  int stage_v_216_2 = ((((stage_v_129_2 * 3) + (sec_r000524_10_2 * 2)) - pub_r000524_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_216_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_216_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((((stage_v_124_1 * 3) + (sec_r000524_10_1 * 2)) - pub_r000524_13_1) + 25) & 127;
  int stage_v_217_2 = ((((stage_v_124_2 * 3) + (sec_r000524_10_2 * 2)) - pub_r000524_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_217_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_217_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((((stage_v_88_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_7_1) + 20) & 127;
  int stage_v_218_2 = ((((stage_v_88_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_218_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_218_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((((stage_v_120_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_14_1) + 23) & 127;
  int stage_v_219_2 = ((((stage_v_120_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_219_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_219_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((((sec_r000524_13_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_13_1) + 30) & 127;
  int stage_v_220_2 = ((((sec_r000524_13_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_220_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_220_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((((stage_v_12_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_15_1) + 21) & 127;
  int stage_v_221_2 = ((((stage_v_12_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_221_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_221_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((((stage_v_74_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_10_1) + 26) & 127;
  int stage_v_222_2 = ((((stage_v_74_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_222_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_222_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((((sec_r000524_19_1 * 3) + (sec_r000524_19_1 * 2)) - pub_r000524_5_1) + 23) & 127;
  int stage_v_223_2 = ((((sec_r000524_19_2 * 3) + (sec_r000524_19_2 * 2)) - pub_r000524_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_223_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_223_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((((stage_v_8_1 * 3) + (sec_r000524_5_1 * 2)) - pub_r000524_14_1) + 18) & 127;
  int stage_v_224_2 = ((((stage_v_8_2 * 3) + (sec_r000524_5_2 * 2)) - pub_r000524_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_224_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_224_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((((sec_r000524_16_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_1_1) + 16) & 127;
  int stage_v_225_2 = ((((sec_r000524_16_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_225_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_225_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((((stage_v_54_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_8_1) + 36) & 127;
  int stage_v_226_2 = ((((stage_v_54_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_226_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_226_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((((stage_v_157_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_9_1) + 10) & 127;
  int stage_v_227_2 = ((((stage_v_157_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_227_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_227_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((((sec_r000524_18_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_8_1) + 36) & 127;
  int stage_v_228_2 = ((((sec_r000524_18_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_228_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_228_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((((stage_v_207_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_21_1) + 14) & 127;
  int stage_v_229_2 = ((((stage_v_207_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_21_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_229_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_229_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((((sec_r000524_2_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_10_1) + 28) & 127;
  int stage_v_230_2 = ((((sec_r000524_2_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_230_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_230_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((((sec_r000524_5_1 * 3) + (sec_r000524_5_1 * 2)) - pub_r000524_16_1) + 5) & 127;
  int stage_v_231_2 = ((((sec_r000524_5_2 * 3) + (sec_r000524_5_2 * 2)) - pub_r000524_16_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_231_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_231_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((((stage_v_172_1 * 3) + (sec_r000524_4_1 * 2)) - pub_r000524_16_1) + 22) & 127;
  int stage_v_232_2 = ((((stage_v_172_2 * 3) + (sec_r000524_4_2 * 2)) - pub_r000524_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_232_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_232_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((((stage_v_53_1 * 3) + (sec_r000524_4_1 * 2)) - pub_r000524_2_1) + 18) & 127;
  int stage_v_233_2 = ((((stage_v_53_2 * 3) + (sec_r000524_4_2 * 2)) - pub_r000524_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_233_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_233_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((((stage_v_188_1 * 3) + (sec_r000524_17_1 * 2)) - pub_r000524_16_1) + 35) & 127;
  int stage_v_234_2 = ((((stage_v_188_2 * 3) + (sec_r000524_17_2 * 2)) - pub_r000524_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_234_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_234_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((((stage_v_95_1 * 3) + (sec_r000524_4_1 * 2)) - pub_r000524_7_1) + 24) & 127;
  int stage_v_235_2 = ((((stage_v_95_2 * 3) + (sec_r000524_4_2 * 2)) - pub_r000524_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_235_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_235_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((((sec_r000524_3_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_20_1) + 27) & 127;
  int stage_v_236_2 = ((((sec_r000524_3_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_20_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_236_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_236_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((((stage_v_16_1 * 3) + (sec_r000524_6_1 * 2)) - pub_r000524_9_1) + 19) & 127;
  int stage_v_237_2 = ((((stage_v_16_2 * 3) + (sec_r000524_6_2 * 2)) - pub_r000524_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_237_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_237_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((((stage_v_30_1 * 3) + (sec_r000524_14_1 * 2)) - pub_r000524_6_1) + 27) & 127;
  int stage_v_238_2 = ((((stage_v_30_2 * 3) + (sec_r000524_14_2 * 2)) - pub_r000524_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_238_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_238_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((((stage_v_67_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_1_1) + 12) & 127;
  int stage_v_239_2 = ((((stage_v_67_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_239_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_239_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((((stage_v_222_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_10_1) + 8) & 127;
  int stage_v_240_2 = ((((stage_v_222_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_240_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_240_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((((stage_v_226_1 * 3) + (sec_r000524_5_1 * 2)) - pub_r000524_18_1) + 14) & 127;
  int stage_v_241_2 = ((((stage_v_226_2 * 3) + (sec_r000524_5_2 * 2)) - pub_r000524_18_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_241_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_241_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((((stage_v_107_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_3_1) + 24) & 127;
  int stage_v_242_2 = ((((stage_v_107_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_242_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_242_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((((stage_v_107_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_7_1) + 25) & 127;
  int stage_v_243_2 = ((((stage_v_107_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_243_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_243_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((((stage_v_203_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_13_1) + 17) & 127;
  int stage_v_244_2 = ((((stage_v_203_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_244_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_244_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((((sec_r000524_1_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_13_1) + 31) & 127;
  int stage_v_245_2 = ((((sec_r000524_1_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_245_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_245_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((((stage_v_156_1 * 3) + (sec_r000524_17_1 * 2)) - pub_r000524_12_1) + 28) & 127;
  int stage_v_246_2 = ((((stage_v_156_2 * 3) + (sec_r000524_17_2 * 2)) - pub_r000524_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_246_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_246_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((((stage_v_117_1 * 3) + (sec_r000524_6_1 * 2)) - pub_r000524_18_1) + 31) & 127;
  int stage_v_247_2 = ((((stage_v_117_2 * 3) + (sec_r000524_6_2 * 2)) - pub_r000524_18_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_247_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_247_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((((stage_v_88_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_16_1) + 19) & 127;
  int stage_v_248_2 = ((((stage_v_88_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_248_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_248_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((((stage_v_122_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_5_1) + 29) & 127;
  int stage_v_249_2 = ((((stage_v_122_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_249_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_249_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((((sec_r000524_10_1 * 3) + (sec_r000524_10_1 * 2)) - pub_r000524_9_1) + 9) & 127;
  int stage_v_250_2 = ((((sec_r000524_10_2 * 3) + (sec_r000524_10_2 * 2)) - pub_r000524_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_250_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_250_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((((sec_r000524_10_1 * 3) + (sec_r000524_10_1 * 2)) - pub_r000524_18_1) + 36) & 127;
  int stage_v_251_2 = ((((sec_r000524_10_2 * 3) + (sec_r000524_10_2 * 2)) - pub_r000524_18_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_251_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_251_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((((stage_v_23_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_15_1) + 33) & 127;
  int stage_v_252_2 = ((((stage_v_23_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_252_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_252_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((((stage_v_246_1 * 3) + (sec_r000524_4_1 * 2)) - pub_r000524_2_1) + 28) & 127;
  int stage_v_253_2 = ((((stage_v_246_2 * 3) + (sec_r000524_4_2 * 2)) - pub_r000524_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_253_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_253_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((((stage_v_202_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_8_1) + 3) & 127;
  int stage_v_254_2 = ((((stage_v_202_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_254_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_254_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((((stage_v_190_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_6_1) + 33) & 127;
  int stage_v_255_2 = ((((stage_v_190_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_255_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_255_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((((sec_r000524_2_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_12_1) + 31) & 127;
  int stage_v_256_2 = ((((sec_r000524_2_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_256_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_256_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((((stage_v_168_1 * 3) + (sec_r000524_12_1 * 2)) - pub_r000524_5_1) + 35) & 127;
  int stage_v_257_2 = ((((stage_v_168_2 * 3) + (sec_r000524_12_2 * 2)) - pub_r000524_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_257_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_257_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((((stage_v_87_1 * 3) + (sec_r000524_6_1 * 2)) - pub_r000524_21_1) + 21) & 127;
  int stage_v_258_2 = ((((stage_v_87_2 * 3) + (sec_r000524_6_2 * 2)) - pub_r000524_21_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_258_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_258_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((((sec_r000524_4_1 * 3) + (sec_r000524_4_1 * 2)) - pub_r000524_5_1) + 22) & 127;
  int stage_v_259_2 = ((((sec_r000524_4_2 * 3) + (sec_r000524_4_2 * 2)) - pub_r000524_5_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_259_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_259_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((((stage_v_233_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_17_1) + 22) & 127;
  int stage_v_260_2 = ((((stage_v_233_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_260_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_260_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((((stage_v_65_1 * 3) + (sec_r000524_6_1 * 2)) - pub_r000524_17_1) + 16) & 127;
  int stage_v_261_2 = ((((stage_v_65_2 * 3) + (sec_r000524_6_2 * 2)) - pub_r000524_17_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_261_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_261_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((((sec_r000524_18_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_2_1) + 36) & 127;
  int stage_v_262_2 = ((((sec_r000524_18_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_262_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_262_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((((stage_v_124_1 * 3) + (sec_r000524_10_1 * 2)) - pub_r000524_12_1) + 37) & 127;
  int stage_v_263_2 = ((((stage_v_124_2 * 3) + (sec_r000524_10_2 * 2)) - pub_r000524_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_263_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_263_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((((stage_v_38_1 * 3) + (sec_r000524_17_1 * 2)) - pub_r000524_21_1) + 19) & 127;
  int stage_v_264_2 = ((((stage_v_38_2 * 3) + (sec_r000524_17_2 * 2)) - pub_r000524_21_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_264_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_264_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((((sec_r000524_3_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_3_1) + 11) & 127;
  int stage_v_265_2 = ((((sec_r000524_3_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_265_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_265_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((((stage_v_111_1 * 3) + (sec_r000524_15_1 * 2)) - pub_r000524_11_1) + 11) & 127;
  int stage_v_266_2 = ((((stage_v_111_2 * 3) + (sec_r000524_15_2 * 2)) - pub_r000524_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_266_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_266_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((((stage_v_261_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_17_1) + 36) & 127;
  int stage_v_267_2 = ((((stage_v_261_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_17_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_267_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_267_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((((stage_v_189_1 * 3) + (sec_r000524_14_1 * 2)) - pub_r000524_8_1) + 3) & 127;
  int stage_v_268_2 = ((((stage_v_189_2 * 3) + (sec_r000524_14_2 * 2)) - pub_r000524_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_268_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_268_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((((stage_v_42_1 * 3) + (sec_r000524_5_1 * 2)) - pub_r000524_7_1) + 27) & 127;
  int stage_v_269_2 = ((((stage_v_42_2 * 3) + (sec_r000524_5_2 * 2)) - pub_r000524_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_269_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_269_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((((stage_v_90_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_1_1) + 11) & 127;
  int stage_v_270_2 = ((((stage_v_90_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_270_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_270_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((((stage_v_42_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_4_1) + 4) & 127;
  int stage_v_271_2 = ((((stage_v_42_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_271_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_271_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((((stage_v_90_1 * 3) + (sec_r000524_15_1 * 2)) - pub_r000524_20_1) + 28) & 127;
  int stage_v_272_2 = ((((stage_v_90_2 * 3) + (sec_r000524_15_2 * 2)) - pub_r000524_20_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_272_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_272_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((((sec_r000524_4_1 * 3) + (sec_r000524_4_1 * 2)) - pub_r000524_17_1) + 27) & 127;
  int stage_v_273_2 = ((((sec_r000524_4_2 * 3) + (sec_r000524_4_2 * 2)) - pub_r000524_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_273_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_273_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((((stage_v_70_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_15_1) + 7) & 127;
  int stage_v_274_2 = ((((stage_v_70_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_274_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_274_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((((stage_v_158_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_9_1) + 5) & 127;
  int stage_v_275_2 = ((((stage_v_158_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_9_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_275_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_275_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((((stage_v_51_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_19_1) + 31) & 127;
  int stage_v_276_2 = ((((stage_v_51_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_19_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_276_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_276_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((((stage_v_230_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_10_1) + 17) & 127;
  int stage_v_277_2 = ((((stage_v_230_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_277_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_277_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((((stage_v_79_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_4_1) + 34) & 127;
  int stage_v_278_2 = ((((stage_v_79_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_278_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_278_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((((stage_v_7_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_10_1) + 22) & 127;
  int stage_v_279_2 = ((((stage_v_7_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_279_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_279_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((((sec_r000524_15_1 * 3) + (sec_r000524_15_1 * 2)) - pub_r000524_18_1) + 25) & 127;
  int stage_v_280_2 = ((((sec_r000524_15_2 * 3) + (sec_r000524_15_2 * 2)) - pub_r000524_18_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_280_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_280_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((((stage_v_173_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_16_1) + 28) & 127;
  int stage_v_281_2 = ((((stage_v_173_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_281_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_281_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((((stage_v_29_1 * 3) + (sec_r000524_17_1 * 2)) - pub_r000524_14_1) + 11) & 127;
  int stage_v_282_2 = ((((stage_v_29_2 * 3) + (sec_r000524_17_2 * 2)) - pub_r000524_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_282_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_282_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((((stage_v_45_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_14_1) + 36) & 127;
  int stage_v_283_2 = ((((stage_v_45_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_283_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_283_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((((sec_r000524_0_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_5_1) + 24) & 127;
  int stage_v_284_2 = ((((sec_r000524_0_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_284_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_284_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((((stage_v_254_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_5_1) + 27) & 127;
  int stage_v_285_2 = ((((stage_v_254_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_285_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_285_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((((stage_v_94_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_4_1) + 17) & 127;
  int stage_v_286_2 = ((((stage_v_94_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_4_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_286_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_286_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((((sec_r000524_3_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_11_1) + 11) & 127;
  int stage_v_287_2 = ((((sec_r000524_3_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_287_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_287_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((((stage_v_199_1 * 3) + (sec_r000524_10_1 * 2)) - pub_r000524_13_1) + 19) & 127;
  int stage_v_288_2 = ((((stage_v_199_2 * 3) + (sec_r000524_10_2 * 2)) - pub_r000524_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_288_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_288_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((((stage_v_232_1 * 3) + (sec_r000524_3_1 * 2)) - pub_r000524_11_1) + 36) & 127;
  int stage_v_289_2 = ((((stage_v_232_2 * 3) + (sec_r000524_3_2 * 2)) - pub_r000524_11_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_289_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_289_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((((sec_r000524_12_1 * 3) + (sec_r000524_12_1 * 2)) - pub_r000524_4_1) + 14) & 127;
  int stage_v_290_2 = ((((sec_r000524_12_2 * 3) + (sec_r000524_12_2 * 2)) - pub_r000524_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_290_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_290_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((((stage_v_191_1 * 3) + (sec_r000524_14_1 * 2)) - pub_r000524_21_1) + 29) & 127;
  int stage_v_291_2 = ((((stage_v_191_2 * 3) + (sec_r000524_14_2 * 2)) - pub_r000524_21_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_291_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_291_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((((stage_v_244_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_1_1) + 21) & 127;
  int stage_v_292_2 = ((((stage_v_244_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_292_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_292_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((((sec_r000524_1_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_19_1) + 9) & 127;
  int stage_v_293_2 = ((((sec_r000524_1_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_19_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_293_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_293_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((((stage_v_289_1 * 3) + (sec_r000524_8_1 * 2)) - pub_r000524_17_1) + 15) & 127;
  int stage_v_294_2 = ((((stage_v_289_2 * 3) + (sec_r000524_8_2 * 2)) - pub_r000524_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_294_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_294_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((((stage_v_95_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_17_1) + 22) & 127;
  int stage_v_295_2 = ((((stage_v_95_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_295_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_295_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((((sec_r000524_9_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_4_1) + 26) & 127;
  int stage_v_296_2 = ((((sec_r000524_9_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_296_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_296_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((((stage_v_208_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_10_1) + 21) & 127;
  int stage_v_297_2 = ((((stage_v_208_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_297_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_297_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((((sec_r000524_5_1 * 3) + (sec_r000524_5_1 * 2)) - pub_r000524_5_1) + 5) & 127;
  int stage_v_298_2 = ((((sec_r000524_5_2 * 3) + (sec_r000524_5_2 * 2)) - pub_r000524_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_298_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_298_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((((stage_v_215_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_18_1) + 17) & 127;
  int stage_v_299_2 = ((((stage_v_215_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_299_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_299_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((((stage_v_230_1 * 3) + (sec_r000524_11_1 * 2)) - pub_r000524_5_1) + 33) & 127;
  int stage_v_300_2 = ((((stage_v_230_2 * 3) + (sec_r000524_11_2 * 2)) - pub_r000524_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_300_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_300_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((((stage_v_277_1 * 3) + (sec_r000524_5_1 * 2)) - pub_r000524_14_1) + 19) & 127;
  int stage_v_301_2 = ((((stage_v_277_2 * 3) + (sec_r000524_5_2 * 2)) - pub_r000524_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_301_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_301_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((((stage_v_100_1 * 3) + (sec_r000524_9_1 * 2)) - pub_r000524_17_1) + 21) & 127;
  int stage_v_302_2 = ((((stage_v_100_2 * 3) + (sec_r000524_9_2 * 2)) - pub_r000524_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_302_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_302_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((((stage_v_30_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_1_1) + 22) & 127;
  int stage_v_303_2 = ((((stage_v_30_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_303_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_303_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((((stage_v_200_1 * 3) + (sec_r000524_11_1 * 2)) - pub_r000524_9_1) + 3) & 127;
  int stage_v_304_2 = ((((stage_v_200_2 * 3) + (sec_r000524_11_2 * 2)) - pub_r000524_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_304_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_304_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((((sec_r000524_13_1 * 3) + (sec_r000524_13_1 * 2)) - pub_r000524_14_1) + 23) & 127;
  int stage_v_305_2 = ((((sec_r000524_13_2 * 3) + (sec_r000524_13_2 * 2)) - pub_r000524_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_305_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_305_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((((stage_v_130_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_11_1) + 8) & 127;
  int stage_v_306_2 = ((((stage_v_130_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_306_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_306_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((((stage_v_104_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_8_1) + 16) & 127;
  int stage_v_307_2 = ((((stage_v_104_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_307_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_307_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((((sec_r000524_1_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_10_1) + 29) & 127;
  int stage_v_308_2 = ((((sec_r000524_1_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_308_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_308_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((((stage_v_91_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_13_1) + 36) & 127;
  int stage_v_309_2 = ((((stage_v_91_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_309_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_309_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((((stage_v_167_1 * 3) + (sec_r000524_19_1 * 2)) - pub_r000524_2_1) + 8) & 127;
  int stage_v_310_2 = ((((stage_v_167_2 * 3) + (sec_r000524_19_2 * 2)) - pub_r000524_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_310_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_310_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((((sec_r000524_18_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_16_1) + 8) & 127;
  int stage_v_311_2 = ((((sec_r000524_18_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_311_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_311_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((((sec_r000524_16_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_4_1) + 19) & 127;
  int stage_v_312_2 = ((((sec_r000524_16_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_312_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_312_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int stage_v_313_1 = ((((sec_r000524_11_1 * 3) + (sec_r000524_11_1 * 2)) - pub_r000524_11_1) + 4) & 127;
  int stage_v_313_2 = ((((sec_r000524_11_2 * 3) + (sec_r000524_11_2 * 2)) - pub_r000524_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_313_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_313_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int stage_v_314_1 = ((((stage_v_4_1 * 3) + (sec_r000524_12_1 * 2)) - pub_r000524_18_1) + 13) & 127;
  int stage_v_314_2 = ((((stage_v_4_2 * 3) + (sec_r000524_12_2 * 2)) - pub_r000524_18_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_314_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_314_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int stage_v_315_1 = ((((sec_r000524_0_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_6_1) + 19) & 127;
  int stage_v_315_2 = ((((sec_r000524_0_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_315_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_315_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  int stage_v_316_1 = ((((stage_v_315_1 * 3) + (sec_r000524_6_1 * 2)) - pub_r000524_6_1) + 24) & 127;
  int stage_v_316_2 = ((((stage_v_315_2 * 3) + (sec_r000524_6_2 * 2)) - pub_r000524_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_316_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_316_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_316_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_316_2) & 255;
  int stage_v_317_1 = ((((sec_r000524_12_1 * 3) + (sec_r000524_12_1 * 2)) - pub_r000524_11_1) + 17) & 127;
  int stage_v_317_2 = ((((sec_r000524_12_2 * 3) + (sec_r000524_12_2 * 2)) - pub_r000524_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_317_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_317_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_317_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_317_2) & 255;
  int stage_v_318_1 = ((((sec_r000524_14_1 * 3) + (sec_r000524_14_1 * 2)) - pub_r000524_17_1) + 20) & 127;
  int stage_v_318_2 = ((((sec_r000524_14_2 * 3) + (sec_r000524_14_2 * 2)) - pub_r000524_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_318_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_318_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_318_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_318_2) & 255;
  int stage_v_319_1 = ((((sec_r000524_1_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_5_1) + 18) & 127;
  int stage_v_319_2 = ((((sec_r000524_1_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_319_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_319_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_319_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_319_2) & 255;
  int stage_v_320_1 = ((((sec_r000524_11_1 * 3) + (sec_r000524_11_1 * 2)) - pub_r000524_11_1) + 33) & 127;
  int stage_v_320_2 = ((((sec_r000524_11_2 * 3) + (sec_r000524_11_2 * 2)) - pub_r000524_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_320_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_320_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_320_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_320_2) & 255;
  int stage_v_321_1 = ((((stage_v_181_1 * 3) + (sec_r000524_0_1 * 2)) - pub_r000524_10_1) + 6) & 127;
  int stage_v_321_2 = ((((stage_v_181_2 * 3) + (sec_r000524_0_2 * 2)) - pub_r000524_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_321_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_321_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_321_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_321_2) & 255;
  int stage_v_322_1 = ((((stage_v_186_1 * 3) + (sec_r000524_11_1 * 2)) - pub_r000524_5_1) + 6) & 127;
  int stage_v_322_2 = ((((stage_v_186_2 * 3) + (sec_r000524_11_2 * 2)) - pub_r000524_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_322_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_322_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_322_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_322_2) & 255;
  int stage_v_323_1 = ((((stage_v_173_1 * 3) + (sec_r000524_16_1 * 2)) - pub_r000524_14_1) + 22) & 127;
  int stage_v_323_2 = ((((stage_v_173_2 * 3) + (sec_r000524_16_2 * 2)) - pub_r000524_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_323_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_323_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_323_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_323_2) & 255;
  int stage_v_324_1 = ((((sec_r000524_17_1 * 3) + (sec_r000524_17_1 * 2)) - pub_r000524_11_1) + 6) & 127;
  int stage_v_324_2 = ((((sec_r000524_17_2 * 3) + (sec_r000524_17_2 * 2)) - pub_r000524_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_324_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_324_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_324_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_324_2) & 255;
  int stage_v_325_1 = ((((sec_r000524_4_1 * 3) + (sec_r000524_4_1 * 2)) - pub_r000524_21_1) + 27) & 127;
  int stage_v_325_2 = ((((sec_r000524_4_2 * 3) + (sec_r000524_4_2 * 2)) - pub_r000524_21_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_325_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_325_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_325_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_325_2) & 255;
  int stage_v_326_1 = ((((stage_v_21_1 * 3) + (sec_r000524_7_1 * 2)) - pub_r000524_19_1) + 8) & 127;
  int stage_v_326_2 = ((((stage_v_21_2 * 3) + (sec_r000524_7_2 * 2)) - pub_r000524_19_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_326_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_326_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_326_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_326_2) & 255;
  int stage_v_327_1 = ((((sec_r000524_12_1 * 3) + (sec_r000524_12_1 * 2)) - pub_r000524_5_1) + 30) & 127;
  int stage_v_327_2 = ((((sec_r000524_12_2 * 3) + (sec_r000524_12_2 * 2)) - pub_r000524_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_327_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_327_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_327_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_327_2) & 255;
  int stage_v_328_1 = ((((stage_v_271_1 * 3) + (sec_r000524_2_1 * 2)) - pub_r000524_20_1) + 11) & 127;
  int stage_v_328_2 = ((((stage_v_271_2 * 3) + (sec_r000524_2_2 * 2)) - pub_r000524_20_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_328_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_328_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_328_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_328_2) & 255;
  int stage_v_329_1 = ((((sec_r000524_12_1 * 3) + (sec_r000524_12_1 * 2)) - pub_r000524_1_1) + 11) & 127;
  int stage_v_329_2 = ((((sec_r000524_12_2 * 3) + (sec_r000524_12_2 * 2)) - pub_r000524_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_329_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_329_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_329_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_329_2) & 255;
  int stage_v_330_1 = ((((stage_v_272_1 * 3) + (sec_r000524_1_1 * 2)) - pub_r000524_3_1) + 7) & 127;
  int stage_v_330_2 = ((((stage_v_272_2 * 3) + (sec_r000524_1_2 * 2)) - pub_r000524_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_330_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_330_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_330_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_330_2) & 255;
  int stage_v_331_1 = ((((stage_v_95_1 * 3) + (sec_r000524_19_1 * 2)) - pub_r000524_16_1) + 25) & 127;
  int stage_v_331_2 = ((((stage_v_95_2 * 3) + (sec_r000524_19_2 * 2)) - pub_r000524_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_331_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_331_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_331_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_331_2) & 255;
  int stage_v_332_1 = ((((sec_r000524_18_1 * 3) + (sec_r000524_18_1 * 2)) - pub_r000524_19_1) + 3) & 127;
  int stage_v_332_2 = ((((sec_r000524_18_2 * 3) + (sec_r000524_18_2 * 2)) - pub_r000524_19_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_332_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_332_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_332_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_332_2) & 255;
  int stage_v_333_1 = ((((stage_v_85_1 * 3) + (sec_r000524_6_1 * 2)) - pub_r000524_9_1) + 21) & 127;
  int stage_v_333_2 = ((((stage_v_85_2 * 3) + (sec_r000524_6_2 * 2)) - pub_r000524_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_333_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_333_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_333_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_333_2) & 255;
  int stage_v_334_1 = ((((sec_r000524_12_1 * 3) + (sec_r000524_12_1 * 2)) - pub_r000524_17_1) + 12) & 127;
  int stage_v_334_2 = ((((sec_r000524_12_2 * 3) + (sec_r000524_12_2 * 2)) - pub_r000524_17_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_334_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_334_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_334_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_334_2) & 255;
  int stage_v_335_1 = ((((stage_v_110_1 * 3) + (sec_r000524_12_1 * 2)) - pub_r000524_17_1) + 33) & 127;
  int stage_v_335_2 = ((((stage_v_110_2 * 3) + (sec_r000524_12_2 * 2)) - pub_r000524_17_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_335_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_335_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_335_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_335_2) & 255;
  int stage_v_336_1 = ((((stage_v_263_1 * 3) + (sec_r000524_11_1 * 2)) - pub_r000524_14_1) + 20) & 127;
  int stage_v_336_2 = ((((stage_v_263_2 * 3) + (sec_r000524_11_2 * 2)) - pub_r000524_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_336_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_336_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_336_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_336_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000524_7_1 != sec_r000524_7_2);
  __CPROVER_assume(pub_r000524_1_1 == pub_r000524_1_2);
  __CPROVER_assume(sec_r000524_6_1 != sec_r000524_6_2);
  __CPROVER_assume(pub_r000524_8_1 == pub_r000524_8_2);
  __CPROVER_assume(pub_r000524_14_1 == pub_r000524_14_2);
  __CPROVER_assume(pub_r000524_20_1 == pub_r000524_20_2);
  __CPROVER_assume(pub_r000524_21_1 == pub_r000524_21_2);
  __CPROVER_assume(sec_r000524_0_1 != sec_r000524_0_2);
  __CPROVER_assume(sec_r000524_4_1 != sec_r000524_4_2);
  __CPROVER_assume(sec_r000524_17_1 != sec_r000524_17_2);
  __CPROVER_assume(sec_r000524_12_1 != sec_r000524_12_2);
  __CPROVER_assume(pub_r000524_6_1 == pub_r000524_6_2);
  __CPROVER_assume(pub_r000524_10_1 == pub_r000524_10_2);
  __CPROVER_assume(pub_r000524_19_1 == pub_r000524_19_2);
  __CPROVER_assume(sec_r000524_16_1 != sec_r000524_16_2);
  __CPROVER_assume(sec_r000524_13_1 != sec_r000524_13_2);
  __CPROVER_assume(sec_r000524_5_1 != sec_r000524_5_2);
  __CPROVER_assume(pub_r000524_7_1 == pub_r000524_7_2);
  __CPROVER_assume(pub_r000524_11_1 == pub_r000524_11_2);
  __CPROVER_assume(sec_r000524_19_1 != sec_r000524_19_2);
  __CPROVER_assume(sec_r000524_14_1 != sec_r000524_14_2);
  __CPROVER_assume(pub_r000524_0_1 == pub_r000524_0_2);
  __CPROVER_assume(pub_r000524_15_1 == pub_r000524_15_2);
  __CPROVER_assume(pub_r000524_2_1 == pub_r000524_2_2);
  __CPROVER_assume(pub_r000524_17_1 == pub_r000524_17_2);
  __CPROVER_assume(sec_r000524_2_1 != sec_r000524_2_2);
  __CPROVER_assume(sec_r000524_8_1 != sec_r000524_8_2);
  __CPROVER_assume(pub_r000524_18_1 == pub_r000524_18_2);
  __CPROVER_assume(sec_r000524_9_1 != sec_r000524_9_2);
  __CPROVER_assume(sec_r000524_11_1 != sec_r000524_11_2);
  __CPROVER_assume(sec_r000524_3_1 != sec_r000524_3_2);
  __CPROVER_assume(pub_r000524_3_1 == pub_r000524_3_2);
  __CPROVER_assume(sec_r000524_15_1 != sec_r000524_15_2);
  __CPROVER_assume(pub_r000524_13_1 == pub_r000524_13_2);
  __CPROVER_assume(sec_r000524_18_1 != sec_r000524_18_2);
  __CPROVER_assume(sec_r000524_10_1 != sec_r000524_10_2);
  __CPROVER_assume(pub_r000524_9_1 == pub_r000524_9_2);
  __CPROVER_assume(pub_r000524_5_1 == pub_r000524_5_2);
  __CPROVER_assume(pub_r000524_12_1 == pub_r000524_12_2);
  __CPROVER_assume(sec_r000524_1_1 != sec_r000524_1_2);
  __CPROVER_assume(pub_r000524_16_1 == pub_r000524_16_2);
  __CPROVER_assume(sec_r000524_20_1 != sec_r000524_20_2);
  __CPROVER_assume(pub_r000524_4_1 == pub_r000524_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  assert(st_var_1_1.counter == st_var_1_2.counter);
  assert(st_var_1_1.iv == st_var_1_2.iv);
  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.facility == st_var_2_2.facility);
  assert(st_var_2_1.signature == st_var_2_2.signature);
  assert(st_var_2_1.seq == st_var_2_2.seq);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.balance == st_var_3_2.balance);
  assert(st_var_3_1.fee == st_var_3_2.fee);
  assert(st_var_3_1.status == st_var_3_2.status);
  assert(st_var_3_1.account_id == st_var_3_2.account_id);
  assert(st_var_3_1.auth_code == st_var_3_2.auth_code);
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
}


