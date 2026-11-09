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
struct CipherContext_R001634_3413_0
{
  short iv;
  int nonce;
  short round_key;
  int buffer[3];
};
struct SensorNode_R001634_3413_1
{
  int offset;
  short gain;
  int reading;
  short calib;
  int threshold;
  int buffer[3];
};
struct Transaction_R001634_3413_2
{
  unsigned char auth_code;
  int balance;
  int fee;
  unsigned char status;
  short rate;
  unsigned char account_id;
  int buffer[3];
};
struct EventLog_R001634_3413_3
{
  short signature;
  int seq;
  short timestamp;
  int code;
  int facility;
  short severity;
  int buffer[3];
};
union RegisterBank_R001634_3413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R001634_3413_1
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
void fn_R001634_3413_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001634_3413_1 st_1 = {0};
  struct SensorNode_R001634_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int phase_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_81_1)
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

  switch (phase_81_2)
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

  int tally_69_1 = 0;
  int tally_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_69_1 = ((tally_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_69_2 = ((tally_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_69_1) & 127;
    acc_2 = (acc_2 + tally_69_2) & 127;
  }

  int sample_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_14_1) & 63;
  aux_2 = (aux_2 + sample_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_83_1 > 15)
  {
    acc_1 = ((acc_1 + (coefficient_83_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_83_2 > 15)
  {
    acc_2 = ((acc_2 + (coefficient_83_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_81_1 == phase_81_2);
  assert(tally_69_1 == tally_69_2);
  assert(sample_14_1 == sample_14_2);
  assert(coefficient_83_1 == coefficient_83_2);
}

int fn_R001634_3413_0(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001634_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int phase_81 = (aux + st.buffer[1]) & 3;
  switch (phase_81)
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

  int tally_69 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_69 = ((tally_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_69) & 127;
  }

  int sample_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_14) & 63;
  acc ^= aux;
  int coefficient_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_83 > 15)
  {
    acc = ((acc + (coefficient_83 * 2)) + 5) & 127;
    aux ^= coefficient_83 & 15;
  }
  else
  {
    acc = ((acc - coefficient_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001634_3413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st_1 = {0};
  struct Transaction_R001634_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int metric_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_26_1)
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

  switch (metric_26_2)
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

  int damping_60_1 = 0;
  int damping_60_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_60_1 = ((damping_60_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_60_2 = ((damping_60_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_60_1) & 127;
    acc_2 = (acc_2 + damping_60_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_53_1 = local_arr_1[aux_1 % 3];
  int stride_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_53_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_26_1 == metric_26_2);
  assert(damping_60_1 == damping_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_53_1 == stride_53_2);
}

int fn_R001634_3413_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int metric_26 = (aux + st.buffer[1]) & 3;
  switch (metric_26)
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

  int damping_60 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_60 = ((damping_60 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_60) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int stride_53 = local_arr[aux % 3];
  acc = (acc + (stride_53 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001634_3413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st_1 = {0};
  struct Transaction_R001634_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int weight_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_21_1) & 63;
  aux_2 = (aux_2 + weight_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_86_1 = 0;
  int factor_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_86_1 = ((factor_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_86_2 = ((factor_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_86_1) & 127;
    acc_2 = (acc_2 + factor_86_2) & 127;
  }

  int threshold_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_15_1 > 24)
  {
    acc_1 = ((acc_1 + (threshold_15_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_15_2 > 24)
  {
    acc_2 = ((acc_2 + (threshold_15_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_15_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_21_1 == weight_21_2);
  assert(factor_86_1 == factor_86_2);
  assert(threshold_15_1 == threshold_15_2);
}

int fn_R001634_3413_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int weight_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_21) & 63;
  acc ^= aux;
  int factor_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_86 = ((factor_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_86) & 127;
  }

  int threshold_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_15 > 24)
  {
    acc = ((acc + (threshold_15 * 2)) + 5) & 127;
    aux ^= threshold_15 & 15;
  }
  else
  {
    acc = ((acc - threshold_15) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001634_3413_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001634_3413_0 st_1 = {0};
  struct CipherContext_R001634_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int coefficient_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_54_1 > 20)
  {
    acc_1 = ((acc_1 + (coefficient_54_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_54_2 > 20)
  {
    acc_2 = ((acc_2 + (coefficient_54_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_25_1)
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

  switch (parity_25_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_54_1 == coefficient_54_2);
  assert(parity_25_1 == parity_25_2);
}

int fn_R001634_3413_3(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001634_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int coefficient_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_54 > 20)
  {
    acc = ((acc + (coefficient_54 * 2)) + 5) & 127;
    aux ^= coefficient_54 & 15;
  }
  else
  {
    acc = ((acc - coefficient_54) + 11) & 127;
    aux += 3;
  }
  int parity_25 = (aux + st.buffer[1]) & 3;
  switch (parity_25)
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

void fn_R001634_3413_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001634_3413_3 st_1 = {0};
  struct EventLog_R001634_3413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int tally_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_81_1) & 63;
  aux_2 = (aux_2 + tally_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_81_1 == tally_81_2);
}

int fn_R001634_3413_4(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001634_3413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int tally_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_81) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001634_3413_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001634_3413_0 st_1 = {0};
  struct CipherContext_R001634_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_50_1 = local_arr_1[aux_1 % 3];
  int quantum_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_50_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_42_1 > 39)
  {
    acc_1 = ((acc_1 + (weight_42_1 * 2)) + 5) & 127;
    aux_1 ^= weight_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_42_2 > 39)
  {
    acc_2 = ((acc_2 + (weight_42_2 * 2)) + 5) & 127;
    aux_2 ^= weight_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
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

  assert(quantum_50_1 == quantum_50_2);
  assert(weight_42_1 == weight_42_2);
}

int fn_R001634_3413_5(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001634_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int quantum_50 = local_arr[aux % 3];
  acc = (acc + (quantum_50 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_42 > 39)
  {
    acc = ((acc + (weight_42 * 2)) + 5) & 127;
    aux ^= weight_42 & 15;
  }
  else
  {
    acc = ((acc - weight_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001634_3413_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st_1 = {0};
  struct Transaction_R001634_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int cursor_88_1 = 0;
  int cursor_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_88_1 = ((cursor_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_88_2 = ((cursor_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_88_1) & 127;
    acc_2 = (acc_2 + cursor_88_2) & 127;
  }

  int scale_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_14_1) & 63;
  aux_2 = (aux_2 + scale_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_88_1 == cursor_88_2);
  assert(scale_14_1 == scale_14_2);
}

int fn_R001634_3413_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int cursor_88 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_88 = ((cursor_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_88) & 127;
  }

  int scale_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_14) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001634_3413_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001634_3413_0 st_1 = {0};
  struct CipherContext_R001634_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_70_1 = local_arr_1[aux_1 % 3];
  int metric_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_70_2 * 2)) & 127;
  int cursor_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_84_1 > 49)
  {
    acc_1 = ((acc_1 + (cursor_84_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_84_2 > 49)
  {
    acc_2 = ((acc_2 + (cursor_84_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_85_1 = 0;
  int offset_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_85_1 = ((offset_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_85_2 = ((offset_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_85_1) & 127;
    acc_2 = (acc_2 + offset_85_2) & 127;
  }

  int quotient_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_65_1) & 63;
  aux_2 = (aux_2 + quotient_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
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

  assert(metric_70_1 == metric_70_2);
  assert(cursor_84_1 == cursor_84_2);
  assert(offset_85_1 == offset_85_2);
  assert(quotient_65_1 == quotient_65_2);
}

int fn_R001634_3413_7(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001634_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int metric_70 = local_arr[aux % 3];
  acc = (acc + (metric_70 * 2)) & 127;
  int cursor_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_84 > 49)
  {
    acc = ((acc + (cursor_84 * 2)) + 5) & 127;
    aux ^= cursor_84 & 15;
  }
  else
  {
    acc = ((acc - cursor_84) + 11) & 127;
    aux += 3;
  }
  int offset_85 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_85 = ((offset_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_85) & 127;
  }

  int quotient_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_65) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001634_3413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001634_3413_3 st_1 = {0};
  struct EventLog_R001634_3413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int window_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_16_1) & 63;
  aux_2 = (aux_2 + window_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_16_1 == window_16_2);
}

int fn_R001634_3413_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001634_3413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int window_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_16) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001634_3413_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st_1 = {0};
  struct Transaction_R001634_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int delta_97_1 = 0;
  int delta_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_97_1 = ((delta_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_97_2 = ((delta_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_97_1) & 127;
    acc_2 = (acc_2 + delta_97_2) & 127;
  }

  int sample_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_47_1) & 63;
  aux_2 = (aux_2 + sample_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_43_1)
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

  switch (scale_43_2)
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
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_97_1 == delta_97_2);
  assert(sample_47_1 == sample_47_2);
  assert(scale_43_1 == scale_43_2);
}

int fn_R001634_3413_9(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int delta_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_97 = ((delta_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_97) & 127;
  }

  int sample_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_47) & 63;
  acc ^= aux;
  int scale_43 = (aux + st.buffer[1]) & 3;
  switch (scale_43)
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

void fn_R001634_3413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001634_3413_1 st_1 = {0};
  struct SensorNode_R001634_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int threshold_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_63_1) & 63;
  aux_2 = (aux_2 + threshold_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_32_1)
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

  switch (scale_32_2)
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

  int delta_41_1 = 0;
  int delta_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_41_1 = ((delta_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_41_2 = ((delta_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_41_1) & 127;
    acc_2 = (acc_2 + delta_41_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_63_1 == threshold_63_2);
  assert(scale_32_1 == scale_32_2);
  assert(delta_41_1 == delta_41_2);
}

int fn_R001634_3413_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001634_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int threshold_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_63) & 63;
  acc ^= aux;
  int scale_32 = (aux + st.buffer[1]) & 3;
  switch (scale_32)
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

  int delta_41 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_41 = ((delta_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_41) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001634_3413_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001634_3413_3 st_1 = {0};
  struct EventLog_R001634_3413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int pivot_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_53_1)
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

  switch (pivot_53_2)
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

  int tally_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_85_1 > 25)
  {
    acc_1 = ((acc_1 + (tally_85_1 * 2)) + 5) & 127;
    aux_1 ^= tally_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_85_2 > 25)
  {
    acc_2 = ((acc_2 + (tally_85_2 * 2)) + 5) & 127;
    aux_2 ^= tally_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_12_1 = local_arr_1[aux_1 % 3];
  int segment_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_53_1 == pivot_53_2);
  assert(tally_85_1 == tally_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_12_1 == segment_12_2);
}

int fn_R001634_3413_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001634_3413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int pivot_53 = (aux + st.buffer[1]) & 3;
  switch (pivot_53)
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

  int tally_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_85 > 25)
  {
    acc = ((acc + (tally_85 * 2)) + 5) & 127;
    aux ^= tally_85 & 15;
  }
  else
  {
    acc = ((acc - tally_85) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_12 = local_arr[aux % 3];
  acc = (acc + (segment_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001634_3413_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st_1 = {0};
  struct Transaction_R001634_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int residue_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_38_1 > 16)
  {
    acc_1 = ((acc_1 + (residue_38_1 * 2)) + 5) & 127;
    aux_1 ^= residue_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_38_2 > 16)
  {
    acc_2 = ((acc_2 + (residue_38_2 * 2)) + 5) & 127;
    aux_2 ^= residue_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_95_1) & 63;
  aux_2 = (aux_2 + index_reg_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_52_1 = 0;
  int index_reg_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_52_1 = ((index_reg_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_52_2 = ((index_reg_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_52_1) & 127;
    acc_2 = (acc_2 + index_reg_52_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_38_1 == residue_38_2);
  assert(index_reg_95_1 == index_reg_95_2);
  assert(index_reg_52_1 == index_reg_52_2);
}

int fn_R001634_3413_12(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int residue_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_38 > 16)
  {
    acc = ((acc + (residue_38 * 2)) + 5) & 127;
    aux ^= residue_38 & 15;
  }
  else
  {
    acc = ((acc - residue_38) + 11) & 127;
    aux += 3;
  }
  int index_reg_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_95) & 63;
  acc ^= aux;
  int index_reg_52 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_52 = ((index_reg_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_52) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001634_3413_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001634_3413_3 st_1 = {0};
  struct EventLog_R001634_3413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int mask_53_1 = 0;
  int mask_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_53_1 = ((mask_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_53_2 = ((mask_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_53_1) & 127;
    acc_2 = (acc_2 + mask_53_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_49_1 = local_arr_1[aux_1 % 3];
  int metric_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_49_2 * 2)) & 127;
  int delta_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_51_1 > 47)
  {
    acc_1 = ((acc_1 + (delta_51_1 * 2)) + 5) & 127;
    aux_1 ^= delta_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_51_2 > 47)
  {
    acc_2 = ((acc_2 + (delta_51_2 * 2)) + 5) & 127;
    aux_2 ^= delta_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_51_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_53_1 == mask_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_49_1 == metric_49_2);
  assert(delta_51_1 == delta_51_2);
}

int fn_R001634_3413_13(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001634_3413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int mask_53 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_53 = ((mask_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_53) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int metric_49 = local_arr[aux % 3];
  acc = (acc + (metric_49 * 2)) & 127;
  int delta_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_51 > 47)
  {
    acc = ((acc + (delta_51 * 2)) + 5) & 127;
    aux ^= delta_51 & 15;
  }
  else
  {
    acc = ((acc - delta_51) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001634_3413_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001634_3413_0 st_1 = {0};
  struct CipherContext_R001634_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int pivot_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_60_1) & 63;
  aux_2 = (aux_2 + pivot_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_84_1)
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

  switch (quantum_84_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_60_1 == pivot_60_2);
  assert(quantum_84_1 == quantum_84_2);
}

int fn_R001634_3413_14(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001634_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int pivot_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_60) & 63;
  acc ^= aux;
  int quantum_84 = (aux + st.buffer[1]) & 3;
  switch (quantum_84)
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

void fn_R001634_3413_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st_1 = {0};
  struct Transaction_R001634_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int window_77_1 = 0;
  int window_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_77_1 = ((window_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_77_2 = ((window_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_77_1) & 127;
    acc_2 = (acc_2 + window_77_2) & 127;
  }

  int damping_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_69_1) & 63;
  aux_2 = (aux_2 + damping_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_77_1 == window_77_2);
  assert(damping_69_1 == damping_69_2);
}

int fn_R001634_3413_15(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int window_77 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_77 = ((window_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_77) & 127;
  }

  int damping_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_69) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001634_3413_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st_1 = {0};
  struct Transaction_R001634_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int residue_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_72_1 > 47)
  {
    acc_1 = ((acc_1 + (residue_72_1 * 2)) + 5) & 127;
    aux_1 ^= residue_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_72_2 > 47)
  {
    acc_2 = ((acc_2 + (residue_72_2 * 2)) + 5) & 127;
    aux_2 ^= residue_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_25_1) & 63;
  aux_2 = (aux_2 + bound_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_72_1 == residue_72_2);
  assert(bound_25_1 == bound_25_2);
}

int fn_R001634_3413_16(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int residue_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_72 > 47)
  {
    acc = ((acc + (residue_72 * 2)) + 5) & 127;
    aux ^= residue_72 & 15;
  }
  else
  {
    acc = ((acc - residue_72) + 11) & 127;
    aux += 3;
  }
  int bound_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_25) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001634_3413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001634_3413_3 st_1 = {0};
  struct EventLog_R001634_3413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_73_1)
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

  switch (mask_73_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_73_1 == mask_73_2);
}

int fn_R001634_3413_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001634_3413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_73 = (aux + st.buffer[1]) & 3;
  switch (mask_73)
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

void fn_R001634_3413_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001634_3413_0 st_1 = {0};
  struct CipherContext_R001634_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int checksum_77_1 = 0;
  int checksum_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_77_1 = ((checksum_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_77_2 = ((checksum_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_77_1) & 127;
    acc_2 = (acc_2 + checksum_77_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_39_1 = local_arr_1[aux_1 % 3];
  int metric_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_39_2 * 2)) & 127;
  int tracker_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_81_1) & 63;
  aux_2 = (aux_2 + tracker_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_77_1 == checksum_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_39_1 == metric_39_2);
  assert(tracker_81_1 == tracker_81_2);
}

int fn_R001634_3413_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001634_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int checksum_77 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_77 = ((checksum_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_77) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int metric_39 = local_arr[aux % 3];
  acc = (acc + (metric_39 * 2)) & 127;
  int tracker_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_81) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001634_3413_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001634_3413_0 st_1 = {0};
  struct CipherContext_R001634_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int scale_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_77_1) & 63;
  aux_2 = (aux_2 + scale_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_77_1 == scale_77_2);
}

int fn_R001634_3413_19(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001634_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int scale_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_77) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001634_3413_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001634_3413_1 st_1 = {0};
  struct SensorNode_R001634_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int checksum_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_50_1 > 41)
  {
    acc_1 = ((acc_1 + (checksum_50_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_50_2 > 41)
  {
    acc_2 = ((acc_2 + (checksum_50_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_76_1)
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

  switch (window_76_2)
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

  int anchor_45_1 = 0;
  int anchor_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_45_1 = ((anchor_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_45_2 = ((anchor_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_45_1) & 127;
    acc_2 = (acc_2 + anchor_45_2) & 127;
  }

  int weight_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_53_1) & 63;
  aux_2 = (aux_2 + weight_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_50_1 == checksum_50_2);
  assert(window_76_1 == window_76_2);
  assert(anchor_45_1 == anchor_45_2);
  assert(weight_53_1 == weight_53_2);
}

int fn_R001634_3413_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001634_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int checksum_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_50 > 41)
  {
    acc = ((acc + (checksum_50 * 2)) + 5) & 127;
    aux ^= checksum_50 & 15;
  }
  else
  {
    acc = ((acc - checksum_50) + 11) & 127;
    aux += 3;
  }
  int window_76 = (aux + st.buffer[1]) & 3;
  switch (window_76)
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

  int anchor_45 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_45 = ((anchor_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_45) & 127;
  }

  int weight_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_53) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001634_3413_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st_1 = {0};
  struct Transaction_R001634_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int damping_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_66_1 > 13)
  {
    acc_1 = ((acc_1 + (damping_66_1 * 2)) + 5) & 127;
    aux_1 ^= damping_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_66_2 > 13)
  {
    acc_2 = ((acc_2 + (damping_66_2 * 2)) + 5) & 127;
    aux_2 ^= damping_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_66_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_66_1 == damping_66_2);
}

int fn_R001634_3413_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001634_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int damping_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_66 > 13)
  {
    acc = ((acc + (damping_66 * 2)) + 5) & 127;
    aux ^= damping_66 & 15;
  }
  else
  {
    acc = ((acc - damping_66) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001634_0_1;
  int sec_r001634_0_2;
  int sec_r001634_1_1;
  int sec_r001634_1_2;
  int sec_r001634_2_1;
  int sec_r001634_2_2;
  int sec_r001634_3_1;
  int sec_r001634_3_2;
  int sec_r001634_4_1;
  int sec_r001634_4_2;
  int sec_r001634_5_1;
  int sec_r001634_5_2;
  int sec_r001634_6_1;
  int sec_r001634_6_2;
  int sec_r001634_7_1;
  int sec_r001634_7_2;
  int sec_r001634_8_1;
  int sec_r001634_8_2;
  int sec_r001634_9_1;
  int sec_r001634_9_2;
  int sec_r001634_10_1;
  int sec_r001634_10_2;
  int sec_r001634_11_1;
  int sec_r001634_11_2;
  int sec_r001634_12_1;
  int sec_r001634_12_2;
  int sec_r001634_13_1;
  int sec_r001634_13_2;
  int sec_r001634_14_1;
  int sec_r001634_14_2;
  int sec_r001634_15_1;
  int sec_r001634_15_2;
  int sec_r001634_16_1;
  int sec_r001634_16_2;
  int sec_r001634_17_1;
  int sec_r001634_17_2;
  int sec_r001634_18_1;
  int sec_r001634_18_2;
  int sec_r001634_19_1;
  int sec_r001634_19_2;
  int pub_r001634_0_1;
  int pub_r001634_0_2;
  int pub_r001634_1_1;
  int pub_r001634_1_2;
  int pub_r001634_2_1;
  int pub_r001634_2_2;
  int pub_r001634_3_1;
  int pub_r001634_3_2;
  int pub_r001634_4_1;
  int pub_r001634_4_2;
  int pub_r001634_5_1;
  int pub_r001634_5_2;
  int pub_r001634_6_1;
  int pub_r001634_6_2;
  int pub_r001634_7_1;
  int pub_r001634_7_2;
  int pub_r001634_8_1;
  int pub_r001634_8_2;
  int pub_r001634_9_1;
  int pub_r001634_9_2;
  int pub_r001634_10_1;
  int pub_r001634_10_2;
  int pub_r001634_11_1;
  int pub_r001634_11_2;
  int pub_r001634_12_1;
  int pub_r001634_12_2;
  int pub_r001634_13_1;
  int pub_r001634_13_2;
  int pub_r001634_14_1;
  int pub_r001634_14_2;
  int pub_r001634_15_1;
  int pub_r001634_15_2;
  int pub_r001634_16_1;
  int pub_r001634_16_2;
  int pub_r001634_17_1;
  int pub_r001634_17_2;
  int pub_r001634_18_1;
  int pub_r001634_18_2;
  int pub_r001634_19_1;
  int pub_r001634_19_2;
  int pub_r001634_20_1;
  int pub_r001634_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001634_0_1 >= (-100)) && (pub_r001634_0_1 <= 100));
  __CPROVER_assume((pub_r001634_0_2 >= (-100)) && (pub_r001634_0_2 <= 100));
  __CPROVER_assume((pub_r001634_1_1 >= (-100)) && (pub_r001634_1_1 <= 100));
  __CPROVER_assume((pub_r001634_1_2 >= (-100)) && (pub_r001634_1_2 <= 100));
  __CPROVER_assume((pub_r001634_2_1 >= (-100)) && (pub_r001634_2_1 <= 100));
  __CPROVER_assume((pub_r001634_2_2 >= (-100)) && (pub_r001634_2_2 <= 100));
  __CPROVER_assume((pub_r001634_3_1 >= (-100)) && (pub_r001634_3_1 <= 100));
  __CPROVER_assume((pub_r001634_3_2 >= (-100)) && (pub_r001634_3_2 <= 100));
  __CPROVER_assume((pub_r001634_4_1 >= (-100)) && (pub_r001634_4_1 <= 100));
  __CPROVER_assume((pub_r001634_4_2 >= (-100)) && (pub_r001634_4_2 <= 100));
  __CPROVER_assume((pub_r001634_5_1 >= (-100)) && (pub_r001634_5_1 <= 100));
  __CPROVER_assume((pub_r001634_5_2 >= (-100)) && (pub_r001634_5_2 <= 100));
  __CPROVER_assume((pub_r001634_6_1 >= (-100)) && (pub_r001634_6_1 <= 100));
  __CPROVER_assume((pub_r001634_6_2 >= (-100)) && (pub_r001634_6_2 <= 100));
  __CPROVER_assume((pub_r001634_7_1 >= (-100)) && (pub_r001634_7_1 <= 100));
  __CPROVER_assume((pub_r001634_7_2 >= (-100)) && (pub_r001634_7_2 <= 100));
  __CPROVER_assume((pub_r001634_8_1 >= (-100)) && (pub_r001634_8_1 <= 100));
  __CPROVER_assume((pub_r001634_8_2 >= (-100)) && (pub_r001634_8_2 <= 100));
  __CPROVER_assume((pub_r001634_9_1 >= (-100)) && (pub_r001634_9_1 <= 100));
  __CPROVER_assume((pub_r001634_9_2 >= (-100)) && (pub_r001634_9_2 <= 100));
  __CPROVER_assume((pub_r001634_10_1 >= (-100)) && (pub_r001634_10_1 <= 100));
  __CPROVER_assume((pub_r001634_10_2 >= (-100)) && (pub_r001634_10_2 <= 100));
  __CPROVER_assume((pub_r001634_11_1 >= (-100)) && (pub_r001634_11_1 <= 100));
  __CPROVER_assume((pub_r001634_11_2 >= (-100)) && (pub_r001634_11_2 <= 100));
  __CPROVER_assume((pub_r001634_12_1 >= (-100)) && (pub_r001634_12_1 <= 100));
  __CPROVER_assume((pub_r001634_12_2 >= (-100)) && (pub_r001634_12_2 <= 100));
  __CPROVER_assume((pub_r001634_13_1 >= (-100)) && (pub_r001634_13_1 <= 100));
  __CPROVER_assume((pub_r001634_13_2 >= (-100)) && (pub_r001634_13_2 <= 100));
  __CPROVER_assume((pub_r001634_14_1 >= (-100)) && (pub_r001634_14_1 <= 100));
  __CPROVER_assume((pub_r001634_14_2 >= (-100)) && (pub_r001634_14_2 <= 100));
  __CPROVER_assume((pub_r001634_15_1 >= (-100)) && (pub_r001634_15_1 <= 100));
  __CPROVER_assume((pub_r001634_15_2 >= (-100)) && (pub_r001634_15_2 <= 100));
  __CPROVER_assume((pub_r001634_16_1 >= (-100)) && (pub_r001634_16_1 <= 100));
  __CPROVER_assume((pub_r001634_16_2 >= (-100)) && (pub_r001634_16_2 <= 100));
  __CPROVER_assume((pub_r001634_17_1 >= (-100)) && (pub_r001634_17_1 <= 100));
  __CPROVER_assume((pub_r001634_17_2 >= (-100)) && (pub_r001634_17_2 <= 100));
  __CPROVER_assume((pub_r001634_18_1 >= (-100)) && (pub_r001634_18_1 <= 100));
  __CPROVER_assume((pub_r001634_18_2 >= (-100)) && (pub_r001634_18_2 <= 100));
  __CPROVER_assume((pub_r001634_19_1 >= (-100)) && (pub_r001634_19_1 <= 100));
  __CPROVER_assume((pub_r001634_19_2 >= (-100)) && (pub_r001634_19_2 <= 100));
  __CPROVER_assume((pub_r001634_20_1 >= (-100)) && (pub_r001634_20_1 <= 100));
  __CPROVER_assume((pub_r001634_20_2 >= (-100)) && (pub_r001634_20_2 <= 100));
  __CPROVER_assume((sec_r001634_0_1 >= 0) && (sec_r001634_0_1 <= 255));
  __CPROVER_assume((sec_r001634_0_2 >= 0) && (sec_r001634_0_2 <= 255));
  __CPROVER_assume((sec_r001634_1_1 >= 0) && (sec_r001634_1_1 <= 255));
  __CPROVER_assume((sec_r001634_1_2 >= 0) && (sec_r001634_1_2 <= 255));
  __CPROVER_assume((sec_r001634_2_1 >= 0) && (sec_r001634_2_1 <= 255));
  __CPROVER_assume((sec_r001634_2_2 >= 0) && (sec_r001634_2_2 <= 255));
  __CPROVER_assume((sec_r001634_3_1 >= 0) && (sec_r001634_3_1 <= 255));
  __CPROVER_assume((sec_r001634_3_2 >= 0) && (sec_r001634_3_2 <= 255));
  __CPROVER_assume((sec_r001634_4_1 >= 0) && (sec_r001634_4_1 <= 255));
  __CPROVER_assume((sec_r001634_4_2 >= 0) && (sec_r001634_4_2 <= 255));
  __CPROVER_assume((sec_r001634_5_1 >= 0) && (sec_r001634_5_1 <= 255));
  __CPROVER_assume((sec_r001634_5_2 >= 0) && (sec_r001634_5_2 <= 255));
  __CPROVER_assume((sec_r001634_6_1 >= 0) && (sec_r001634_6_1 <= 255));
  __CPROVER_assume((sec_r001634_6_2 >= 0) && (sec_r001634_6_2 <= 255));
  __CPROVER_assume((sec_r001634_7_1 >= 0) && (sec_r001634_7_1 <= 255));
  __CPROVER_assume((sec_r001634_7_2 >= 0) && (sec_r001634_7_2 <= 255));
  __CPROVER_assume((sec_r001634_8_1 >= 0) && (sec_r001634_8_1 <= 255));
  __CPROVER_assume((sec_r001634_8_2 >= 0) && (sec_r001634_8_2 <= 255));
  __CPROVER_assume((sec_r001634_9_1 >= 0) && (sec_r001634_9_1 <= 255));
  __CPROVER_assume((sec_r001634_9_2 >= 0) && (sec_r001634_9_2 <= 255));
  __CPROVER_assume((sec_r001634_10_1 >= 0) && (sec_r001634_10_1 <= 255));
  __CPROVER_assume((sec_r001634_10_2 >= 0) && (sec_r001634_10_2 <= 255));
  __CPROVER_assume((sec_r001634_11_1 >= 0) && (sec_r001634_11_1 <= 255));
  __CPROVER_assume((sec_r001634_11_2 >= 0) && (sec_r001634_11_2 <= 255));
  __CPROVER_assume((sec_r001634_12_1 >= 0) && (sec_r001634_12_1 <= 255));
  __CPROVER_assume((sec_r001634_12_2 >= 0) && (sec_r001634_12_2 <= 255));
  __CPROVER_assume((sec_r001634_13_1 >= 0) && (sec_r001634_13_1 <= 255));
  __CPROVER_assume((sec_r001634_13_2 >= 0) && (sec_r001634_13_2 <= 255));
  __CPROVER_assume((sec_r001634_14_1 >= 0) && (sec_r001634_14_1 <= 255));
  __CPROVER_assume((sec_r001634_14_2 >= 0) && (sec_r001634_14_2 <= 255));
  __CPROVER_assume((sec_r001634_15_1 >= 0) && (sec_r001634_15_1 <= 255));
  __CPROVER_assume((sec_r001634_15_2 >= 0) && (sec_r001634_15_2 <= 255));
  __CPROVER_assume((sec_r001634_16_1 >= 0) && (sec_r001634_16_1 <= 255));
  __CPROVER_assume((sec_r001634_16_2 >= 0) && (sec_r001634_16_2 <= 255));
  __CPROVER_assume((sec_r001634_17_1 >= 0) && (sec_r001634_17_1 <= 255));
  __CPROVER_assume((sec_r001634_17_2 >= 0) && (sec_r001634_17_2 <= 255));
  __CPROVER_assume((sec_r001634_18_1 >= 0) && (sec_r001634_18_1 <= 255));
  __CPROVER_assume((sec_r001634_18_2 >= 0) && (sec_r001634_18_2 <= 255));
  __CPROVER_assume((sec_r001634_19_1 >= 0) && (sec_r001634_19_1 <= 255));
  __CPROVER_assume((sec_r001634_19_2 >= 0) && (sec_r001634_19_2 <= 255));
  struct CipherContext_R001634_3413_0 st_var_0_1 = {0};
  struct CipherContext_R001634_3413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001634_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001634_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001634_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001634_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001634_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001634_0_2 + 7) & 15;
  struct SensorNode_R001634_3413_1 st_var_1_1 = {0};
  struct SensorNode_R001634_3413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001634_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001634_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001634_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001634_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001634_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001634_0_2 + 9) & 15;
  struct Transaction_R001634_3413_2 st_var_2_1 = {0};
  struct Transaction_R001634_3413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001634_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001634_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001634_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001634_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001634_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001634_0_2 + 11) & 15;
  struct EventLog_R001634_3413_3 st_var_3_1 = {0};
  struct EventLog_R001634_3413_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001634_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001634_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001634_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001634_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001634_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001634_0_2 + 13) & 15;
  union RegisterBank_R001634_3413_0 u_var_1;
  union RegisterBank_R001634_3413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001634_3413_0(sec_r001634_0_1, pub_r001634_1_1);
  int helper_flow_0_2 = fn_R001634_3413_0(sec_r001634_0_2, pub_r001634_1_2);
  fn_R001634_3413_0_2(sec_r001634_0_1, pub_r001634_1_1, sec_r001634_0_2, pub_r001634_1_2);
  int helper_flow_1_1 = fn_R001634_3413_1(sec_r001634_1_1, sec_r001634_2_1, pub_r001634_3_1, pub_r001634_4_1);
  int helper_flow_1_2 = fn_R001634_3413_1(sec_r001634_1_2, sec_r001634_2_2, pub_r001634_3_2, pub_r001634_4_2);
  fn_R001634_3413_1_2(sec_r001634_1_1, sec_r001634_2_1, pub_r001634_3_1, pub_r001634_4_1, sec_r001634_1_2, sec_r001634_2_2, pub_r001634_3_2, pub_r001634_4_2);
  int helper_flow_2_1 = fn_R001634_3413_2(sec_r001634_2_1, pub_r001634_3_1, pub_r001634_4_1, pub_r001634_5_1, pub_r001634_6_1);
  int helper_flow_2_2 = fn_R001634_3413_2(sec_r001634_2_2, pub_r001634_3_2, pub_r001634_4_2, pub_r001634_5_2, pub_r001634_6_2);
  fn_R001634_3413_2_2(sec_r001634_2_1, pub_r001634_3_1, pub_r001634_4_1, pub_r001634_5_1, pub_r001634_6_1, sec_r001634_2_2, pub_r001634_3_2, pub_r001634_4_2, pub_r001634_5_2, pub_r001634_6_2);
  int helper_flow_3_1 = fn_R001634_3413_3(sec_r001634_3_1, sec_r001634_4_1);
  int helper_flow_3_2 = fn_R001634_3413_3(sec_r001634_3_2, sec_r001634_4_2);
  fn_R001634_3413_3_2(sec_r001634_3_1, sec_r001634_4_1, sec_r001634_3_2, sec_r001634_4_2);
  int helper_flow_4_1 = fn_R001634_3413_4(sec_r001634_4_1, sec_r001634_5_1);
  int helper_flow_4_2 = fn_R001634_3413_4(sec_r001634_4_2, sec_r001634_5_2);
  fn_R001634_3413_4_2(sec_r001634_4_1, sec_r001634_5_1, sec_r001634_4_2, sec_r001634_5_2);
  int helper_flow_5_1 = fn_R001634_3413_5(sec_r001634_5_1, pub_r001634_6_1, pub_r001634_7_1);
  int helper_flow_5_2 = fn_R001634_3413_5(sec_r001634_5_2, pub_r001634_6_2, pub_r001634_7_2);
  fn_R001634_3413_5_2(sec_r001634_5_1, pub_r001634_6_1, pub_r001634_7_1, sec_r001634_5_2, pub_r001634_6_2, pub_r001634_7_2);
  int stage_v_0_1 = ((pub_r001634_15_1 * 2) + 28) & 63;
  int stage_v_0_2 = ((pub_r001634_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((sec_r001634_12_1 * 3) + pub_r001634_6_1) + 4) & 127;
  int stage_v_1_2 = (((sec_r001634_12_2 * 3) + pub_r001634_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = ((pub_r001634_0_1 * 2) + 11) & 63;
  int stage_v_2_2 = ((pub_r001634_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001634_2_1 * 2) + 38) & 63;
  int stage_v_3_2 = ((pub_r001634_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((sec_r001634_16_1 * 3) + pub_r001634_0_1) + 24) & 127;
  int stage_v_4_2 = (((sec_r001634_16_2 * 3) + pub_r001634_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001634_6_1 * 2) + 7) & 63;
  int stage_v_5_2 = ((pub_r001634_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001634_8_1 * 2) + 50) & 63;
  int stage_v_6_2 = ((pub_r001634_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((sec_r001634_0_1 * 3) + pub_r001634_17_1) + 9) & 127;
  int stage_v_7_2 = (((sec_r001634_0_2 * 3) + pub_r001634_17_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001634_12_1 * 2) + 13) & 63;
  int stage_v_8_2 = ((pub_r001634_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001634_4_1 * 2) + 28) & 63;
  int stage_v_9_2 = ((pub_r001634_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001634_15_1 * 2) + 23) & 63;
  int stage_v_10_2 = ((pub_r001634_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001634_10_1 * 2) + 46) & 63;
  int stage_v_11_2 = ((pub_r001634_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((sec_r001634_9_1 * 3) + pub_r001634_16_1) + 35) & 127;
  int stage_v_12_2 = (((sec_r001634_9_2 * 3) + pub_r001634_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = (((stage_v_12_1 * 3) + pub_r001634_12_1) + 11) & 127;
  int stage_v_13_2 = (((stage_v_12_2 * 3) + pub_r001634_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = ((pub_r001634_6_1 * 2) + 25) & 63;
  int stage_v_14_2 = ((pub_r001634_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((sec_r001634_15_1 * 3) + pub_r001634_19_1) + 29) & 127;
  int stage_v_15_2 = (((sec_r001634_15_2 * 3) + pub_r001634_19_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = (((stage_v_7_1 * 3) + pub_r001634_11_1) + 45) & 127;
  int stage_v_16_2 = (((stage_v_7_2 * 3) + pub_r001634_11_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = (((helper_flow_5_1 * 3) + pub_r001634_19_1) + 43) & 127;
  int stage_v_17_2 = (((helper_flow_5_2 * 3) + pub_r001634_19_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = (((sec_r001634_7_1 * 3) + pub_r001634_1_1) + 45) & 127;
  int stage_v_18_2 = (((sec_r001634_7_2 * 3) + pub_r001634_1_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = (((stage_v_18_1 * 3) + pub_r001634_19_1) + 32) & 127;
  int stage_v_19_2 = (((stage_v_18_2 * 3) + pub_r001634_19_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = ((pub_r001634_5_1 * 2) + 6) & 63;
  int stage_v_20_2 = ((pub_r001634_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001634_11_1 * 2) + 34) & 63;
  int stage_v_21_2 = ((pub_r001634_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001634_11_1 * 2) + 45) & 63;
  int stage_v_22_2 = ((pub_r001634_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001634_0_1 * 2) + 14) & 63;
  int stage_v_23_2 = ((pub_r001634_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (((stage_v_4_1 * 3) + pub_r001634_2_1) + 44) & 127;
  int stage_v_24_2 = (((stage_v_4_2 * 3) + pub_r001634_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((sec_r001634_4_1 * 3) + pub_r001634_5_1) + 30) & 127;
  int stage_v_25_2 = (((sec_r001634_4_2 * 3) + pub_r001634_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((helper_flow_0_1 * 3) + pub_r001634_3_1) + 24) & 127;
  int stage_v_26_2 = (((helper_flow_0_2 * 3) + pub_r001634_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = (((stage_v_1_1 * 3) + pub_r001634_15_1) + 44) & 127;
  int stage_v_27_2 = (((stage_v_1_2 * 3) + pub_r001634_15_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = (((stage_v_13_1 * 3) + pub_r001634_17_1) + 16) & 127;
  int stage_v_28_2 = (((stage_v_13_2 * 3) + pub_r001634_17_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = (((stage_v_7_1 * 3) + pub_r001634_4_1) + 31) & 127;
  int stage_v_29_2 = (((stage_v_7_2 * 3) + pub_r001634_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = ((pub_r001634_12_1 * 2) + 16) & 63;
  int stage_v_30_2 = ((pub_r001634_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (((stage_v_1_1 * 3) + pub_r001634_17_1) + 4) & 127;
  int stage_v_31_2 = (((stage_v_1_2 * 3) + pub_r001634_17_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = (((stage_v_27_1 * 3) + pub_r001634_1_1) + 32) & 127;
  int stage_v_32_2 = (((stage_v_27_2 * 3) + pub_r001634_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = ((pub_r001634_7_1 * 2) + 26) & 63;
  int stage_v_33_2 = ((pub_r001634_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001634_4_1 * 2) + 14) & 63;
  int stage_v_34_2 = ((pub_r001634_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001634_5_1 * 2) + 15) & 63;
  int stage_v_35_2 = ((pub_r001634_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((sec_r001634_18_1 * 3) + pub_r001634_1_1) + 24) & 127;
  int stage_v_36_2 = (((sec_r001634_18_2 * 3) + pub_r001634_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = (((helper_flow_1_1 * 3) + pub_r001634_10_1) + 20) & 127;
  int stage_v_37_2 = (((helper_flow_1_2 * 3) + pub_r001634_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = ((pub_r001634_12_1 * 2) + 50) & 63;
  int stage_v_38_2 = ((pub_r001634_12_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001634_11_1 * 2) + 7) & 63;
  int stage_v_39_2 = ((pub_r001634_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001634_6_1 * 2) + 34) & 63;
  int stage_v_40_2 = ((pub_r001634_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001634_18_1 * 2) + 30) & 63;
  int stage_v_41_2 = ((pub_r001634_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (((sec_r001634_11_1 * 3) + pub_r001634_20_1) + 21) & 127;
  int stage_v_42_2 = (((sec_r001634_11_2 * 3) + pub_r001634_20_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = (((sec_r001634_10_1 * 3) + pub_r001634_9_1) + 37) & 127;
  int stage_v_43_2 = (((sec_r001634_10_2 * 3) + pub_r001634_9_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = ((pub_r001634_12_1 * 2) + 17) & 63;
  int stage_v_44_2 = ((pub_r001634_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((sec_r001634_14_1 * 3) + pub_r001634_8_1) + 17) & 127;
  int stage_v_45_2 = (((sec_r001634_14_2 * 3) + pub_r001634_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = ((pub_r001634_5_1 * 2) + 8) & 63;
  int stage_v_46_2 = ((pub_r001634_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((stage_v_1_1 * 3) + pub_r001634_19_1) + 41) & 127;
  int stage_v_47_2 = (((stage_v_1_2 * 3) + pub_r001634_19_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = (((sec_r001634_3_1 * 3) + pub_r001634_19_1) + 15) & 127;
  int stage_v_48_2 = (((sec_r001634_3_2 * 3) + pub_r001634_19_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = ((pub_r001634_15_1 * 2) + 7) & 63;
  int stage_v_49_2 = ((pub_r001634_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001634_9_1 * 2) + 21) & 63;
  int stage_v_50_2 = ((pub_r001634_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((helper_flow_3_1 * 3) + pub_r001634_3_1) + 42) & 127;
  int stage_v_51_2 = (((helper_flow_3_2 * 3) + pub_r001634_3_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = ((pub_r001634_1_1 * 2) + 17) & 63;
  int stage_v_52_2 = ((pub_r001634_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001634_5_1 * 2) + 18) & 63;
  int stage_v_53_2 = ((pub_r001634_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001634_17_1 * 2) + 20) & 63;
  int stage_v_54_2 = ((pub_r001634_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((helper_flow_1_1 * 3) + pub_r001634_0_1) + 30) & 127;
  int stage_v_55_2 = (((helper_flow_1_2 * 3) + pub_r001634_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = ((pub_r001634_6_1 * 2) + 48) & 63;
  int stage_v_56_2 = ((pub_r001634_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001634_1_1 * 2) + 50) & 63;
  int stage_v_57_2 = ((pub_r001634_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (((sec_r001634_13_1 * 3) + pub_r001634_6_1) + 43) & 127;
  int stage_v_58_2 = (((sec_r001634_13_2 * 3) + pub_r001634_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = ((pub_r001634_9_1 * 2) + 19) & 63;
  int stage_v_59_2 = ((pub_r001634_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((stage_v_43_1 * 3) + pub_r001634_5_1) + 5) & 127;
  int stage_v_60_2 = (((stage_v_43_2 * 3) + pub_r001634_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((stage_v_17_1 * 3) + pub_r001634_11_1) + 21) & 127;
  int stage_v_61_2 = (((stage_v_17_2 * 3) + pub_r001634_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001634_16_1 * 2) + 19) & 63;
  int stage_v_62_2 = ((pub_r001634_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((sec_r001634_15_1 * 3) + pub_r001634_13_1) + 27) & 127;
  int stage_v_63_2 = (((sec_r001634_15_2 * 3) + pub_r001634_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((stage_v_4_1 * 3) + pub_r001634_9_1) + 12) & 127;
  int stage_v_64_2 = (((stage_v_4_2 * 3) + pub_r001634_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = ((pub_r001634_8_1 * 2) + 35) & 63;
  int stage_v_65_2 = ((pub_r001634_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((stage_v_27_1 * 3) + pub_r001634_2_1) + 44) & 127;
  int stage_v_66_2 = (((stage_v_27_2 * 3) + pub_r001634_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = ((pub_r001634_16_1 * 2) + 20) & 63;
  int stage_v_67_2 = ((pub_r001634_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (((stage_v_13_1 * 3) + pub_r001634_12_1) + 12) & 127;
  int stage_v_68_2 = (((stage_v_13_2 * 3) + pub_r001634_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = ((pub_r001634_15_1 * 2) + 29) & 63;
  int stage_v_69_2 = ((pub_r001634_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001634_14_1 * 2) + 16) & 63;
  int stage_v_70_2 = ((pub_r001634_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001634_13_1 * 2) + 10) & 63;
  int stage_v_71_2 = ((pub_r001634_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((sec_r001634_8_1 * 3) + pub_r001634_18_1) + 38) & 127;
  int stage_v_72_2 = (((sec_r001634_8_2 * 3) + pub_r001634_18_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = (((stage_v_29_1 * 3) + pub_r001634_20_1) + 44) & 127;
  int stage_v_73_2 = (((stage_v_29_2 * 3) + pub_r001634_20_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = (((sec_r001634_12_1 * 3) + pub_r001634_19_1) + 12) & 127;
  int stage_v_74_2 = (((sec_r001634_12_2 * 3) + pub_r001634_19_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = (((sec_r001634_3_1 * 3) + pub_r001634_18_1) + 39) & 127;
  int stage_v_75_2 = (((sec_r001634_3_2 * 3) + pub_r001634_18_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = (((stage_v_36_1 * 3) + pub_r001634_20_1) + 43) & 127;
  int stage_v_76_2 = (((stage_v_36_2 * 3) + pub_r001634_20_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = (((sec_r001634_11_1 * 3) + pub_r001634_20_1) + 34) & 127;
  int stage_v_77_2 = (((sec_r001634_11_2 * 3) + pub_r001634_20_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = ((pub_r001634_12_1 * 2) + 36) & 63;
  int stage_v_78_2 = ((pub_r001634_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((stage_v_61_1 * 3) + pub_r001634_6_1) + 26) & 127;
  int stage_v_79_2 = (((stage_v_61_2 * 3) + pub_r001634_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = ((pub_r001634_6_1 * 2) + 32) & 63;
  int stage_v_80_2 = ((pub_r001634_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001634_10_1 * 2) + 50) & 63;
  int stage_v_81_2 = ((pub_r001634_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001634_5_1 * 2) + 39) & 63;
  int stage_v_82_2 = ((pub_r001634_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((sec_r001634_4_1 * 3) + pub_r001634_11_1) + 39) & 127;
  int stage_v_83_2 = (((sec_r001634_4_2 * 3) + pub_r001634_11_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = ((pub_r001634_20_1 * 2) + 49) & 63;
  int stage_v_84_2 = ((pub_r001634_20_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001634_6_1 * 2) + 17) & 63;
  int stage_v_85_2 = ((pub_r001634_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001634_1_1 * 2) + 30) & 63;
  int stage_v_86_2 = ((pub_r001634_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001634_12_1 * 2) + 12) & 63;
  int stage_v_87_2 = ((pub_r001634_12_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((stage_v_47_1 * 3) + pub_r001634_16_1) + 32) & 127;
  int stage_v_88_2 = (((stage_v_47_2 * 3) + pub_r001634_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = ((pub_r001634_17_1 * 2) + 40) & 63;
  int stage_v_89_2 = ((pub_r001634_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((stage_v_42_1 * 3) + pub_r001634_11_1) + 31) & 127;
  int stage_v_90_2 = (((stage_v_42_2 * 3) + pub_r001634_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = (((stage_v_64_1 * 3) + pub_r001634_18_1) + 38) & 127;
  int stage_v_91_2 = (((stage_v_64_2 * 3) + pub_r001634_18_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = ((pub_r001634_0_1 * 2) + 10) & 63;
  int stage_v_92_2 = ((pub_r001634_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (((sec_r001634_6_1 * 3) + pub_r001634_4_1) + 25) & 127;
  int stage_v_93_2 = (((sec_r001634_6_2 * 3) + pub_r001634_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = (((stage_v_24_1 * 3) + pub_r001634_5_1) + 42) & 127;
  int stage_v_94_2 = (((stage_v_24_2 * 3) + pub_r001634_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = ((pub_r001634_18_1 * 2) + 18) & 63;
  int stage_v_95_2 = ((pub_r001634_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((stage_v_16_1 * 3) + pub_r001634_7_1) + 42) & 127;
  int stage_v_96_2 = (((stage_v_16_2 * 3) + pub_r001634_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = (((stage_v_18_1 * 3) + pub_r001634_16_1) + 9) & 127;
  int stage_v_97_2 = (((stage_v_18_2 * 3) + pub_r001634_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = (((sec_r001634_18_1 * 3) + pub_r001634_7_1) + 34) & 127;
  int stage_v_98_2 = (((sec_r001634_18_2 * 3) + pub_r001634_7_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = ((pub_r001634_16_1 * 2) + 39) & 63;
  int stage_v_99_2 = ((pub_r001634_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (((sec_r001634_10_1 * 3) + pub_r001634_5_1) + 3) & 127;
  int stage_v_100_2 = (((sec_r001634_10_2 * 3) + pub_r001634_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = (((stage_v_61_1 * 3) + pub_r001634_19_1) + 29) & 127;
  int stage_v_101_2 = (((stage_v_61_2 * 3) + pub_r001634_19_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = (((stage_v_66_1 * 3) + pub_r001634_18_1) + 21) & 127;
  int stage_v_102_2 = (((stage_v_66_2 * 3) + pub_r001634_18_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = (((stage_v_29_1 * 3) + pub_r001634_6_1) + 44) & 127;
  int stage_v_103_2 = (((stage_v_29_2 * 3) + pub_r001634_6_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = ((pub_r001634_17_1 * 2) + 39) & 63;
  int stage_v_104_2 = ((pub_r001634_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001634_12_1 * 2) + 34) & 63;
  int stage_v_105_2 = ((pub_r001634_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001634_19_1 * 2) + 23) & 63;
  int stage_v_106_2 = ((pub_r001634_19_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001634_18_1 * 2) + 28) & 63;
  int stage_v_107_2 = ((pub_r001634_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((sec_r001634_11_1 * 3) + pub_r001634_18_1) + 27) & 127;
  int stage_v_108_2 = (((sec_r001634_11_2 * 3) + pub_r001634_18_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = (((stage_v_24_1 * 3) + pub_r001634_18_1) + 15) & 127;
  int stage_v_109_2 = (((stage_v_24_2 * 3) + pub_r001634_18_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = ((pub_r001634_2_1 * 2) + 17) & 63;
  int stage_v_110_2 = ((pub_r001634_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001634_19_1 * 2) + 7) & 63;
  int stage_v_111_2 = ((pub_r001634_19_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001634_12_1 * 2) + 32) & 63;
  int stage_v_112_2 = ((pub_r001634_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((helper_flow_1_1 * 3) + pub_r001634_2_1) + 40) & 127;
  int stage_v_113_2 = (((helper_flow_1_2 * 3) + pub_r001634_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = (((sec_r001634_3_1 * 3) + pub_r001634_15_1) + 20) & 127;
  int stage_v_114_2 = (((sec_r001634_3_2 * 3) + pub_r001634_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = (((stage_v_94_1 * 3) + pub_r001634_20_1) + 6) & 127;
  int stage_v_115_2 = (((stage_v_94_2 * 3) + pub_r001634_20_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = (((stage_v_90_1 * 3) + pub_r001634_17_1) + 17) & 127;
  int stage_v_116_2 = (((stage_v_90_2 * 3) + pub_r001634_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = ((pub_r001634_2_1 * 2) + 25) & 63;
  int stage_v_117_2 = ((pub_r001634_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((helper_flow_4_1 * 3) + pub_r001634_15_1) + 7) & 127;
  int stage_v_118_2 = (((helper_flow_4_2 * 3) + pub_r001634_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = ((pub_r001634_4_1 * 2) + 14) & 63;
  int stage_v_119_2 = ((pub_r001634_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((stage_v_15_1 * 3) + pub_r001634_10_1) + 27) & 127;
  int stage_v_120_2 = (((stage_v_15_2 * 3) + pub_r001634_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = ((pub_r001634_7_1 * 2) + 23) & 63;
  int stage_v_121_2 = ((pub_r001634_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((stage_v_72_1 * 3) + pub_r001634_3_1) + 26) & 127;
  int stage_v_122_2 = (((stage_v_72_2 * 3) + pub_r001634_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = (((stage_v_113_1 * 3) + pub_r001634_12_1) + 18) & 127;
  int stage_v_123_2 = (((stage_v_113_2 * 3) + pub_r001634_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((stage_v_115_1 * 3) + pub_r001634_10_1) + 8) & 127;
  int stage_v_124_2 = (((stage_v_115_2 * 3) + pub_r001634_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = (((sec_r001634_5_1 * 3) + pub_r001634_1_1) + 14) & 127;
  int stage_v_125_2 = (((sec_r001634_5_2 * 3) + pub_r001634_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = ((pub_r001634_7_1 * 2) + 35) & 63;
  int stage_v_126_2 = ((pub_r001634_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = (((stage_v_75_1 * 3) + pub_r001634_18_1) + 19) & 127;
  int stage_v_127_2 = (((stage_v_75_2 * 3) + pub_r001634_18_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = (((sec_r001634_19_1 * 3) + pub_r001634_17_1) + 20) & 127;
  int stage_v_128_2 = (((sec_r001634_19_2 * 3) + pub_r001634_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = (((sec_r001634_0_1 * 3) + pub_r001634_4_1) + 43) & 127;
  int stage_v_129_2 = (((sec_r001634_0_2 * 3) + pub_r001634_4_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = ((pub_r001634_19_1 * 2) + 50) & 63;
  int stage_v_130_2 = ((pub_r001634_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001634_3_1 * 2) + 32) & 63;
  int stage_v_131_2 = ((pub_r001634_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001634_5_1 * 2) + 20) & 63;
  int stage_v_132_2 = ((pub_r001634_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001634_11_1 * 2) + 10) & 63;
  int stage_v_133_2 = ((pub_r001634_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = (((stage_v_4_1 * 3) + pub_r001634_13_1) + 6) & 127;
  int stage_v_134_2 = (((stage_v_4_2 * 3) + pub_r001634_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((stage_v_74_1 * 3) + pub_r001634_12_1) + 30) & 127;
  int stage_v_135_2 = (((stage_v_74_2 * 3) + pub_r001634_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = ((pub_r001634_4_1 * 2) + 35) & 63;
  int stage_v_136_2 = ((pub_r001634_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001634_0_1 * 2) + 16) & 63;
  int stage_v_137_2 = ((pub_r001634_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001634_4_1 * 2) + 7) & 63;
  int stage_v_138_2 = ((pub_r001634_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001634_6_1 * 2) + 6) & 63;
  int stage_v_139_2 = ((pub_r001634_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001634_13_1 * 2) + 37) & 63;
  int stage_v_140_2 = ((pub_r001634_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (((stage_v_108_1 * 3) + pub_r001634_9_1) + 16) & 127;
  int stage_v_141_2 = (((stage_v_108_2 * 3) + pub_r001634_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = (((sec_r001634_4_1 * 3) + pub_r001634_13_1) + 5) & 127;
  int stage_v_142_2 = (((sec_r001634_4_2 * 3) + pub_r001634_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = (((sec_r001634_6_1 * 3) + pub_r001634_8_1) + 11) & 127;
  int stage_v_143_2 = (((sec_r001634_6_2 * 3) + pub_r001634_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = ((pub_r001634_1_1 * 2) + 50) & 63;
  int stage_v_144_2 = ((pub_r001634_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001634_1_1 * 2) + 7) & 63;
  int stage_v_145_2 = ((pub_r001634_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001634_18_1 * 2) + 40) & 63;
  int stage_v_146_2 = ((pub_r001634_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((stage_v_128_1 * 3) + pub_r001634_13_1) + 14) & 127;
  int stage_v_147_2 = (((stage_v_128_2 * 3) + pub_r001634_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = ((pub_r001634_7_1 * 2) + 21) & 63;
  int stage_v_148_2 = ((pub_r001634_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001634_12_1 * 2) + 32) & 63;
  int stage_v_149_2 = ((pub_r001634_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001634_13_1 * 2) + 47) & 63;
  int stage_v_150_2 = ((pub_r001634_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001634_14_1 * 2) + 15) & 63;
  int stage_v_151_2 = ((pub_r001634_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001634_14_1 * 2) + 46) & 63;
  int stage_v_152_2 = ((pub_r001634_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001634_9_1 * 2) + 48) & 63;
  int stage_v_153_2 = ((pub_r001634_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001634_16_1 * 2) + 30) & 63;
  int stage_v_154_2 = ((pub_r001634_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((stage_v_97_1 * 3) + pub_r001634_18_1) + 40) & 127;
  int stage_v_155_2 = (((stage_v_97_2 * 3) + pub_r001634_18_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((sec_r001634_0_1 * 3) + pub_r001634_20_1) + 14) & 127;
  int stage_v_156_2 = (((sec_r001634_0_2 * 3) + pub_r001634_20_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((sec_r001634_14_1 * 3) + pub_r001634_8_1) + 34) & 127;
  int stage_v_157_2 = (((sec_r001634_14_2 * 3) + pub_r001634_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = ((pub_r001634_15_1 * 2) + 23) & 63;
  int stage_v_158_2 = ((pub_r001634_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((stage_v_63_1 * 3) + pub_r001634_0_1) + 30) & 127;
  int stage_v_159_2 = (((stage_v_63_2 * 3) + pub_r001634_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = (((stage_v_18_1 * 3) + pub_r001634_20_1) + 14) & 127;
  int stage_v_160_2 = (((stage_v_18_2 * 3) + pub_r001634_20_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = (((stage_v_102_1 * 3) + pub_r001634_13_1) + 21) & 127;
  int stage_v_161_2 = (((stage_v_102_2 * 3) + pub_r001634_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = (((stage_v_123_1 * 3) + pub_r001634_3_1) + 22) & 127;
  int stage_v_162_2 = (((stage_v_123_2 * 3) + pub_r001634_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = (((stage_v_155_1 * 3) + pub_r001634_19_1) + 24) & 127;
  int stage_v_163_2 = (((stage_v_155_2 * 3) + pub_r001634_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = ((pub_r001634_3_1 * 2) + 30) & 63;
  int stage_v_164_2 = ((pub_r001634_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001634_0_1 * 2) + 47) & 63;
  int stage_v_165_2 = ((pub_r001634_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001634_5_1 * 2) + 37) & 63;
  int stage_v_166_2 = ((pub_r001634_5_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((sec_r001634_0_1 * 3) + pub_r001634_19_1) + 23) & 127;
  int stage_v_167_2 = (((sec_r001634_0_2 * 3) + pub_r001634_19_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = (((stage_v_90_1 * 3) + pub_r001634_6_1) + 24) & 127;
  int stage_v_168_2 = (((stage_v_90_2 * 3) + pub_r001634_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = ((pub_r001634_19_1 * 2) + 35) & 63;
  int stage_v_169_2 = ((pub_r001634_19_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((stage_v_141_1 * 3) + pub_r001634_11_1) + 34) & 127;
  int stage_v_170_2 = (((stage_v_141_2 * 3) + pub_r001634_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = (((sec_r001634_14_1 * 3) + pub_r001634_4_1) + 8) & 127;
  int stage_v_171_2 = (((sec_r001634_14_2 * 3) + pub_r001634_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = ((pub_r001634_8_1 * 2) + 16) & 63;
  int stage_v_172_2 = ((pub_r001634_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (((stage_v_97_1 * 3) + pub_r001634_19_1) + 44) & 127;
  int stage_v_173_2 = (((stage_v_97_2 * 3) + pub_r001634_19_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = (((sec_r001634_2_1 * 3) + pub_r001634_2_1) + 10) & 127;
  int stage_v_174_2 = (((sec_r001634_2_2 * 3) + pub_r001634_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = (((stage_v_25_1 * 3) + pub_r001634_17_1) + 44) & 127;
  int stage_v_175_2 = (((stage_v_25_2 * 3) + pub_r001634_17_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = (((sec_r001634_7_1 * 3) + pub_r001634_5_1) + 45) & 127;
  int stage_v_176_2 = (((sec_r001634_7_2 * 3) + pub_r001634_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = (((sec_r001634_16_1 * 3) + pub_r001634_11_1) + 11) & 127;
  int stage_v_177_2 = (((sec_r001634_16_2 * 3) + pub_r001634_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = (((stage_v_31_1 * 3) + pub_r001634_6_1) + 11) & 127;
  int stage_v_178_2 = (((stage_v_31_2 * 3) + pub_r001634_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = (((sec_r001634_17_1 * 3) + pub_r001634_14_1) + 16) & 127;
  int stage_v_179_2 = (((sec_r001634_17_2 * 3) + pub_r001634_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = ((pub_r001634_15_1 * 2) + 31) & 63;
  int stage_v_180_2 = ((pub_r001634_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001634_4_1 * 2) + 43) & 63;
  int stage_v_181_2 = ((pub_r001634_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((stage_v_125_1 * 3) + pub_r001634_8_1) + 21) & 127;
  int stage_v_182_2 = (((stage_v_125_2 * 3) + pub_r001634_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = ((pub_r001634_1_1 * 2) + 8) & 63;
  int stage_v_183_2 = ((pub_r001634_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (((stage_v_36_1 * 3) + pub_r001634_12_1) + 10) & 127;
  int stage_v_184_2 = (((stage_v_36_2 * 3) + pub_r001634_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = (((stage_v_168_1 * 3) + pub_r001634_1_1) + 15) & 127;
  int stage_v_185_2 = (((stage_v_168_2 * 3) + pub_r001634_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = (((stage_v_127_1 * 3) + pub_r001634_12_1) + 31) & 127;
  int stage_v_186_2 = (((stage_v_127_2 * 3) + pub_r001634_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = ((pub_r001634_10_1 * 2) + 18) & 63;
  int stage_v_187_2 = ((pub_r001634_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001634_4_1 * 2) + 39) & 63;
  int stage_v_188_2 = ((pub_r001634_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001634_8_1 * 2) + 34) & 63;
  int stage_v_189_2 = ((pub_r001634_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((stage_v_61_1 * 3) + pub_r001634_13_1) + 20) & 127;
  int stage_v_190_2 = (((stage_v_61_2 * 3) + pub_r001634_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = (((stage_v_29_1 * 3) + pub_r001634_1_1) + 12) & 127;
  int stage_v_191_2 = (((stage_v_29_2 * 3) + pub_r001634_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = (((stage_v_16_1 * 3) + pub_r001634_14_1) + 41) & 127;
  int stage_v_192_2 = (((stage_v_16_2 * 3) + pub_r001634_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = (((stage_v_32_1 * 3) + pub_r001634_18_1) + 6) & 127;
  int stage_v_193_2 = (((stage_v_32_2 * 3) + pub_r001634_18_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = (((stage_v_125_1 * 3) + pub_r001634_6_1) + 32) & 127;
  int stage_v_194_2 = (((stage_v_125_2 * 3) + pub_r001634_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = (((stage_v_129_1 * 3) + pub_r001634_20_1) + 44) & 127;
  int stage_v_195_2 = (((stage_v_129_2 * 3) + pub_r001634_20_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = (((stage_v_90_1 * 3) + pub_r001634_17_1) + 25) & 127;
  int stage_v_196_2 = (((stage_v_90_2 * 3) + pub_r001634_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = ((pub_r001634_7_1 * 2) + 37) & 63;
  int stage_v_197_2 = ((pub_r001634_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_175_1 * 3) + pub_r001634_15_1) + 35) & 127;
  int stage_v_198_2 = (((stage_v_175_2 * 3) + pub_r001634_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001634_17_1 * 2) + 46) & 63;
  int stage_v_199_2 = ((pub_r001634_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001634_12_1 * 2) + 36) & 63;
  int stage_v_200_2 = ((pub_r001634_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001634_13_1 * 2) + 43) & 63;
  int stage_v_201_2 = ((pub_r001634_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((sec_r001634_7_1 * 3) + pub_r001634_4_1) + 23) & 127;
  int stage_v_202_2 = (((sec_r001634_7_2 * 3) + pub_r001634_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = ((pub_r001634_7_1 * 2) + 16) & 63;
  int stage_v_203_2 = ((pub_r001634_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((sec_r001634_15_1 * 3) + pub_r001634_13_1) + 44) & 127;
  int stage_v_204_2 = (((sec_r001634_15_2 * 3) + pub_r001634_13_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((helper_flow_3_1 * 3) + pub_r001634_17_1) + 6) & 127;
  int stage_v_205_2 = (((helper_flow_3_2 * 3) + pub_r001634_17_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = ((pub_r001634_12_1 * 2) + 19) & 63;
  int stage_v_206_2 = ((pub_r001634_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001634_16_1 * 2) + 46) & 63;
  int stage_v_207_2 = ((pub_r001634_16_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = (((stage_v_109_1 * 3) + pub_r001634_3_1) + 22) & 127;
  int stage_v_208_2 = (((stage_v_109_2 * 3) + pub_r001634_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = ((pub_r001634_13_1 * 2) + 24) & 63;
  int stage_v_209_2 = ((pub_r001634_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((stage_v_123_1 * 3) + pub_r001634_9_1) + 36) & 127;
  int stage_v_210_2 = (((stage_v_123_2 * 3) + pub_r001634_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_17_1 * 3) + pub_r001634_15_1) + 7) & 127;
  int stage_v_211_2 = (((stage_v_17_2 * 3) + pub_r001634_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = (((stage_v_18_1 * 3) + pub_r001634_4_1) + 18) & 127;
  int stage_v_212_2 = (((stage_v_18_2 * 3) + pub_r001634_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = ((pub_r001634_8_1 * 2) + 42) & 63;
  int stage_v_213_2 = ((pub_r001634_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001634_3_1 * 2) + 8) & 63;
  int stage_v_214_2 = ((pub_r001634_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((stage_v_43_1 * 3) + pub_r001634_15_1) + 31) & 127;
  int stage_v_215_2 = (((stage_v_43_2 * 3) + pub_r001634_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = ((pub_r001634_17_1 * 2) + 15) & 63;
  int stage_v_216_2 = ((pub_r001634_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001634_8_1 * 2) + 26) & 63;
  int stage_v_217_2 = ((pub_r001634_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = (((stage_v_204_1 * 3) + pub_r001634_17_1) + 5) & 127;
  int stage_v_218_2 = (((stage_v_204_2 * 3) + pub_r001634_17_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = ((pub_r001634_10_1 * 2) + 21) & 63;
  int stage_v_219_2 = ((pub_r001634_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = (((stage_v_24_1 * 3) + pub_r001634_12_1) + 12) & 127;
  int stage_v_220_2 = (((stage_v_24_2 * 3) + pub_r001634_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = (((stage_v_72_1 * 3) + pub_r001634_7_1) + 33) & 127;
  int stage_v_221_2 = (((stage_v_72_2 * 3) + pub_r001634_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = (((stage_v_79_1 * 3) + pub_r001634_15_1) + 24) & 127;
  int stage_v_222_2 = (((stage_v_79_2 * 3) + pub_r001634_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001634_6_1 * 2) + 9) & 63;
  int stage_v_223_2 = ((pub_r001634_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001634_15_1 * 2) + 25) & 63;
  int stage_v_224_2 = ((pub_r001634_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001634_18_1 * 2) + 29) & 63;
  int stage_v_225_2 = ((pub_r001634_18_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = (((stage_v_159_1 * 3) + pub_r001634_17_1) + 11) & 127;
  int stage_v_226_2 = (((stage_v_159_2 * 3) + pub_r001634_17_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((stage_v_73_1 * 3) + pub_r001634_7_1) + 27) & 127;
  int stage_v_227_2 = (((stage_v_73_2 * 3) + pub_r001634_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = (((stage_v_12_1 * 3) + pub_r001634_2_1) + 33) & 127;
  int stage_v_228_2 = (((stage_v_12_2 * 3) + pub_r001634_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = ((pub_r001634_9_1 * 2) + 5) & 63;
  int stage_v_229_2 = ((pub_r001634_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = (((stage_v_51_1 * 3) + pub_r001634_9_1) + 40) & 127;
  int stage_v_230_2 = (((stage_v_51_2 * 3) + pub_r001634_9_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = ((pub_r001634_12_1 * 2) + 28) & 63;
  int stage_v_231_2 = ((pub_r001634_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = (((stage_v_42_1 * 3) + pub_r001634_8_1) + 26) & 127;
  int stage_v_232_2 = (((stage_v_42_2 * 3) + pub_r001634_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = ((pub_r001634_4_1 * 2) + 6) & 63;
  int stage_v_233_2 = ((pub_r001634_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001634_18_1 * 2) + 35) & 63;
  int stage_v_234_2 = ((pub_r001634_18_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = (((stage_v_90_1 * 3) + pub_r001634_10_1) + 34) & 127;
  int stage_v_235_2 = (((stage_v_90_2 * 3) + pub_r001634_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = (((stage_v_109_1 * 3) + pub_r001634_10_1) + 4) & 127;
  int stage_v_236_2 = (((stage_v_109_2 * 3) + pub_r001634_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = (((sec_r001634_18_1 * 3) + pub_r001634_5_1) + 18) & 127;
  int stage_v_237_2 = (((sec_r001634_18_2 * 3) + pub_r001634_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = (((sec_r001634_1_1 * 3) + pub_r001634_13_1) + 38) & 127;
  int stage_v_238_2 = (((sec_r001634_1_2 * 3) + pub_r001634_13_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = ((pub_r001634_16_1 * 2) + 17) & 63;
  int stage_v_239_2 = ((pub_r001634_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001634_7_1 * 2) + 20) & 63;
  int stage_v_240_2 = ((pub_r001634_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = (((stage_v_222_1 * 3) + pub_r001634_16_1) + 28) & 127;
  int stage_v_241_2 = (((stage_v_222_2 * 3) + pub_r001634_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((stage_v_241_1 * 3) + pub_r001634_19_1) + 22) & 127;
  int stage_v_242_2 = (((stage_v_241_2 * 3) + pub_r001634_19_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = ((pub_r001634_2_1 * 2) + 18) & 63;
  int stage_v_243_2 = ((pub_r001634_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((stage_v_186_1 * 3) + pub_r001634_10_1) + 28) & 127;
  int stage_v_244_2 = (((stage_v_186_2 * 3) + pub_r001634_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = ((pub_r001634_8_1 * 2) + 13) & 63;
  int stage_v_245_2 = ((pub_r001634_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001634_20_1 * 2) + 22) & 63;
  int stage_v_246_2 = ((pub_r001634_20_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = (((sec_r001634_17_1 * 3) + pub_r001634_16_1) + 21) & 127;
  int stage_v_247_2 = (((sec_r001634_17_2 * 3) + pub_r001634_16_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = ((pub_r001634_6_1 * 2) + 27) & 63;
  int stage_v_248_2 = ((pub_r001634_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = (((sec_r001634_17_1 * 3) + pub_r001634_14_1) + 9) & 127;
  int stage_v_249_2 = (((sec_r001634_17_2 * 3) + pub_r001634_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((stage_v_186_1 * 3) + pub_r001634_4_1) + 25) & 127;
  int stage_v_250_2 = (((stage_v_186_2 * 3) + pub_r001634_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = (((stage_v_129_1 * 3) + pub_r001634_4_1) + 20) & 127;
  int stage_v_251_2 = (((stage_v_129_2 * 3) + pub_r001634_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = (((stage_v_171_1 * 3) + pub_r001634_9_1) + 45) & 127;
  int stage_v_252_2 = (((stage_v_171_2 * 3) + pub_r001634_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = ((pub_r001634_1_1 * 2) + 47) & 63;
  int stage_v_253_2 = ((pub_r001634_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = (((stage_v_90_1 * 3) + pub_r001634_13_1) + 12) & 127;
  int stage_v_254_2 = (((stage_v_90_2 * 3) + pub_r001634_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = ((pub_r001634_12_1 * 2) + 34) & 63;
  int stage_v_255_2 = ((pub_r001634_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001634_2_1 * 2) + 26) & 63;
  int stage_v_256_2 = ((pub_r001634_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001634_11_1 * 2) + 45) & 63;
  int stage_v_257_2 = ((pub_r001634_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_215_1 * 3) + pub_r001634_4_1) + 30) & 127;
  int stage_v_258_2 = (((stage_v_215_2 * 3) + pub_r001634_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001634_7_1 * 2) + 48) & 63;
  int stage_v_259_2 = ((pub_r001634_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = (((sec_r001634_13_1 * 3) + pub_r001634_12_1) + 32) & 127;
  int stage_v_260_2 = (((sec_r001634_13_2 * 3) + pub_r001634_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = ((pub_r001634_2_1 * 2) + 38) & 63;
  int stage_v_261_2 = ((pub_r001634_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = (((stage_v_72_1 * 3) + pub_r001634_1_1) + 24) & 127;
  int stage_v_262_2 = (((stage_v_72_2 * 3) + pub_r001634_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = (((helper_flow_4_1 * 3) + pub_r001634_9_1) + 38) & 127;
  int stage_v_263_2 = (((helper_flow_4_2 * 3) + pub_r001634_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = (((stage_v_196_1 * 3) + pub_r001634_7_1) + 23) & 127;
  int stage_v_264_2 = (((stage_v_196_2 * 3) + pub_r001634_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = ((pub_r001634_5_1 * 2) + 39) & 63;
  int stage_v_265_2 = ((pub_r001634_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = (((stage_v_16_1 * 3) + pub_r001634_0_1) + 19) & 127;
  int stage_v_266_2 = (((stage_v_16_2 * 3) + pub_r001634_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = ((pub_r001634_14_1 * 2) + 29) & 63;
  int stage_v_267_2 = ((pub_r001634_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001634_20_1 * 2) + 21) & 63;
  int stage_v_268_2 = ((pub_r001634_20_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001634_2_1 * 2) + 9) & 63;
  int stage_v_269_2 = ((pub_r001634_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = (((stage_v_192_1 * 3) + pub_r001634_20_1) + 12) & 127;
  int stage_v_270_2 = (((stage_v_192_2 * 3) + pub_r001634_20_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = ((pub_r001634_10_1 * 2) + 13) & 63;
  int stage_v_271_2 = ((pub_r001634_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = (((stage_v_125_1 * 3) + pub_r001634_0_1) + 8) & 127;
  int stage_v_272_2 = (((stage_v_125_2 * 3) + pub_r001634_0_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = ((pub_r001634_17_1 * 2) + 48) & 63;
  int stage_v_273_2 = ((pub_r001634_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = (((sec_r001634_4_1 * 3) + pub_r001634_6_1) + 13) & 127;
  int stage_v_274_2 = (((sec_r001634_4_2 * 3) + pub_r001634_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = (((stage_v_179_1 * 3) + pub_r001634_7_1) + 39) & 127;
  int stage_v_275_2 = (((stage_v_179_2 * 3) + pub_r001634_7_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = (((stage_v_182_1 * 3) + pub_r001634_3_1) + 9) & 127;
  int stage_v_276_2 = (((stage_v_182_2 * 3) + pub_r001634_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = ((pub_r001634_7_1 * 2) + 6) & 63;
  int stage_v_277_2 = ((pub_r001634_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((pub_r001634_10_1 * 2) + 16) & 63;
  int stage_v_278_2 = ((pub_r001634_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001634_9_1 * 2) + 22) & 63;
  int stage_v_279_2 = ((pub_r001634_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = (((stage_v_94_1 * 3) + pub_r001634_19_1) + 30) & 127;
  int stage_v_280_2 = (((stage_v_94_2 * 3) + pub_r001634_19_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = (((stage_v_244_1 * 3) + pub_r001634_13_1) + 26) & 127;
  int stage_v_281_2 = (((stage_v_244_2 * 3) + pub_r001634_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = ((pub_r001634_7_1 * 2) + 29) & 63;
  int stage_v_282_2 = ((pub_r001634_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001634_0_1 * 2) + 40) & 63;
  int stage_v_283_2 = ((pub_r001634_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = (((stage_v_260_1 * 3) + pub_r001634_12_1) + 42) & 127;
  int stage_v_284_2 = (((stage_v_260_2 * 3) + pub_r001634_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = ((pub_r001634_2_1 * 2) + 29) & 63;
  int stage_v_285_2 = ((pub_r001634_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = (((stage_v_198_1 * 3) + pub_r001634_17_1) + 17) & 127;
  int stage_v_286_2 = (((stage_v_198_2 * 3) + pub_r001634_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = (((stage_v_270_1 * 3) + pub_r001634_4_1) + 9) & 127;
  int stage_v_287_2 = (((stage_v_270_2 * 3) + pub_r001634_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = ((pub_r001634_2_1 * 2) + 18) & 63;
  int stage_v_288_2 = ((pub_r001634_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_124_1 * 3) + pub_r001634_2_1) + 17) & 127;
  int stage_v_289_2 = (((stage_v_124_2 * 3) + pub_r001634_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_109_1 * 3) + pub_r001634_11_1) + 28) & 127;
  int stage_v_290_2 = (((stage_v_109_2 * 3) + pub_r001634_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = ((pub_r001634_6_1 * 2) + 15) & 63;
  int stage_v_291_2 = ((pub_r001634_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((pub_r001634_16_1 * 2) + 22) & 63;
  int stage_v_292_2 = ((pub_r001634_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001634_18_1 * 2) + 37) & 63;
  int stage_v_293_2 = ((pub_r001634_18_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001634_10_1 * 2) + 37) & 63;
  int stage_v_294_2 = ((pub_r001634_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = (((stage_v_68_1 * 3) + pub_r001634_7_1) + 40) & 127;
  int stage_v_295_2 = (((stage_v_68_2 * 3) + pub_r001634_7_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = (((stage_v_264_1 * 3) + pub_r001634_13_1) + 39) & 127;
  int stage_v_296_2 = (((stage_v_264_2 * 3) + pub_r001634_13_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = ((pub_r001634_18_1 * 2) + 10) & 63;
  int stage_v_297_2 = ((pub_r001634_18_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001634_1_1 * 2) + 41) & 63;
  int stage_v_298_2 = ((pub_r001634_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = (((stage_v_32_1 * 3) + pub_r001634_13_1) + 6) & 127;
  int stage_v_299_2 = (((stage_v_32_2 * 3) + pub_r001634_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = ((pub_r001634_9_1 * 2) + 47) & 63;
  int stage_v_300_2 = ((pub_r001634_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001634_0_1 * 2) + 26) & 63;
  int stage_v_301_2 = ((pub_r001634_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = (((stage_v_109_1 * 3) + pub_r001634_3_1) + 11) & 127;
  int stage_v_302_2 = (((stage_v_109_2 * 3) + pub_r001634_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = (((sec_r001634_10_1 * 3) + pub_r001634_7_1) + 8) & 127;
  int stage_v_303_2 = (((sec_r001634_10_2 * 3) + pub_r001634_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001634_9_1 * 2) + 26) & 63;
  int stage_v_304_2 = ((pub_r001634_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001634_1_1 * 2) + 23) & 63;
  int stage_v_305_2 = ((pub_r001634_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_192_1 * 3) + pub_r001634_1_1) + 6) & 127;
  int stage_v_306_2 = (((stage_v_192_2 * 3) + pub_r001634_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = (((stage_v_83_1 * 3) + pub_r001634_12_1) + 42) & 127;
  int stage_v_307_2 = (((stage_v_83_2 * 3) + pub_r001634_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = ((pub_r001634_13_1 * 2) + 16) & 63;
  int stage_v_308_2 = ((pub_r001634_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = (((stage_v_204_1 * 3) + pub_r001634_13_1) + 26) & 127;
  int stage_v_309_2 = (((stage_v_204_2 * 3) + pub_r001634_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = (((sec_r001634_16_1 * 3) + pub_r001634_12_1) + 44) & 127;
  int stage_v_310_2 = (((sec_r001634_16_2 * 3) + pub_r001634_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = (((stage_v_27_1 * 3) + pub_r001634_18_1) + 17) & 127;
  int stage_v_311_2 = (((stage_v_27_2 * 3) + pub_r001634_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = ((pub_r001634_13_1 * 2) + 38) & 63;
  int stage_v_312_2 = ((pub_r001634_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((stage_v_47_1 * 3) + pub_r001634_5_1) + 21) & 127;
  int stage_v_313_2 = (((stage_v_47_2 * 3) + pub_r001634_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = (((stage_v_135_1 * 3) + pub_r001634_3_1) + 34) & 127;
  int stage_v_314_2 = (((stage_v_135_2 * 3) + pub_r001634_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = ((pub_r001634_3_1 * 2) + 48) & 63;
  int stage_v_315_2 = ((pub_r001634_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = (((stage_v_93_1 * 3) + pub_r001634_13_1) + 6) & 127;
  int stage_v_316_2 = (((stage_v_93_2 * 3) + pub_r001634_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((sec_r001634_5_1 * 3) + pub_r001634_4_1) + 23) & 127;
  int stage_v_317_2 = (((sec_r001634_5_2 * 3) + pub_r001634_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = (((sec_r001634_0_1 * 3) + pub_r001634_7_1) + 14) & 127;
  int stage_v_318_2 = (((sec_r001634_0_2 * 3) + pub_r001634_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = ((pub_r001634_6_1 * 2) + 44) & 63;
  int stage_v_319_2 = ((pub_r001634_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = (((stage_v_250_1 * 3) + pub_r001634_12_1) + 44) & 127;
  int stage_v_320_2 = (((stage_v_250_2 * 3) + pub_r001634_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = (((stage_v_103_1 * 3) + pub_r001634_3_1) + 14) & 127;
  int stage_v_321_2 = (((stage_v_103_2 * 3) + pub_r001634_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((helper_flow_4_1 * 3) + pub_r001634_8_1) + 7) & 127;
  int stage_v_322_2 = (((helper_flow_4_2 * 3) + pub_r001634_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = ((pub_r001634_15_1 * 2) + 17) & 63;
  int stage_v_323_2 = ((pub_r001634_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001634_14_1 * 2) + 49) & 63;
  int stage_v_324_2 = ((pub_r001634_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = (((stage_v_91_1 * 3) + pub_r001634_13_1) + 13) & 127;
  int stage_v_325_2 = (((stage_v_91_2 * 3) + pub_r001634_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = (((stage_v_290_1 * 3) + pub_r001634_15_1) + 24) & 127;
  int stage_v_326_2 = (((stage_v_290_2 * 3) + pub_r001634_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = ((pub_r001634_0_1 * 2) + 29) & 63;
  int stage_v_327_2 = ((pub_r001634_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = (((stage_v_302_1 * 3) + pub_r001634_1_1) + 9) & 127;
  int stage_v_328_2 = (((stage_v_302_2 * 3) + pub_r001634_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = ((pub_r001634_11_1 * 2) + 37) & 63;
  int stage_v_329_2 = ((pub_r001634_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001634_16_1 * 2) + 39) & 63;
  int stage_v_330_2 = ((pub_r001634_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = (((helper_flow_3_1 * 3) + pub_r001634_0_1) + 24) & 127;
  int stage_v_331_2 = (((helper_flow_3_2 * 3) + pub_r001634_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = (((stage_v_116_1 * 3) + pub_r001634_1_1) + 11) & 127;
  int stage_v_332_2 = (((stage_v_116_2 * 3) + pub_r001634_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((stage_v_221_1 * 3) + pub_r001634_7_1) + 25) & 127;
  int stage_v_333_2 = (((stage_v_221_2 * 3) + pub_r001634_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = ((pub_r001634_15_1 * 2) + 7) & 63;
  int stage_v_334_2 = ((pub_r001634_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = (((stage_v_94_1 * 3) + pub_r001634_13_1) + 20) & 127;
  int stage_v_335_2 = (((stage_v_94_2 * 3) + pub_r001634_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = (((stage_v_155_1 * 3) + pub_r001634_11_1) + 27) & 127;
  int stage_v_336_2 = (((stage_v_155_2 * 3) + pub_r001634_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((stage_v_290_1 * 3) + pub_r001634_16_1) + 13) & 127;
  int stage_v_337_2 = (((stage_v_290_2 * 3) + pub_r001634_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = (((sec_r001634_6_1 * 3) + pub_r001634_6_1) + 13) & 127;
  int stage_v_338_2 = (((sec_r001634_6_2 * 3) + pub_r001634_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = (((sec_r001634_19_1 * 3) + pub_r001634_9_1) + 4) & 127;
  int stage_v_339_2 = (((sec_r001634_19_2 * 3) + pub_r001634_9_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = (((stage_v_205_1 * 3) + pub_r001634_4_1) + 45) & 127;
  int stage_v_340_2 = (((stage_v_205_2 * 3) + pub_r001634_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = ((pub_r001634_17_1 * 2) + 10) & 63;
  int stage_v_341_2 = ((pub_r001634_17_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001634_20_1 * 2) + 20) & 63;
  int stage_v_342_2 = ((pub_r001634_20_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = (((stage_v_58_1 * 3) + pub_r001634_17_1) + 39) & 127;
  int stage_v_343_2 = (((stage_v_58_2 * 3) + pub_r001634_17_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_122_1 * 3) + pub_r001634_5_1) + 7) & 127;
  int stage_v_344_2 = (((stage_v_122_2 * 3) + pub_r001634_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001634_12_1 * 2) + 24) & 63;
  int stage_v_345_2 = ((pub_r001634_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001634_15_1 * 2) + 25) & 63;
  int stage_v_346_2 = ((pub_r001634_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = (((stage_v_251_1 * 3) + pub_r001634_17_1) + 21) & 127;
  int stage_v_347_2 = (((stage_v_251_2 * 3) + pub_r001634_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = (((stage_v_191_1 * 3) + pub_r001634_7_1) + 21) & 127;
  int stage_v_348_2 = (((stage_v_191_2 * 3) + pub_r001634_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = ((pub_r001634_17_1 * 2) + 28) & 63;
  int stage_v_349_2 = ((pub_r001634_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = ((pub_r001634_1_1 * 2) + 33) & 63;
  int stage_v_350_2 = ((pub_r001634_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = (((stage_v_254_1 * 3) + pub_r001634_17_1) + 16) & 127;
  int stage_v_351_2 = (((stage_v_254_2 * 3) + pub_r001634_17_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = (((stage_v_254_1 * 3) + pub_r001634_1_1) + 5) & 127;
  int stage_v_352_2 = (((stage_v_254_2 * 3) + pub_r001634_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = ((pub_r001634_16_1 * 2) + 34) & 63;
  int stage_v_353_2 = ((pub_r001634_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001634_19_1 * 2) + 15) & 63;
  int stage_v_354_2 = ((pub_r001634_19_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001634_6_1 * 2) + 14) & 63;
  int stage_v_355_2 = ((pub_r001634_6_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = (((stage_v_118_1 * 3) + pub_r001634_9_1) + 34) & 127;
  int stage_v_356_2 = (((stage_v_118_2 * 3) + pub_r001634_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = ((pub_r001634_9_1 * 2) + 7) & 63;
  int stage_v_357_2 = ((pub_r001634_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001634_20_1 * 2) + 48) & 63;
  int stage_v_358_2 = ((pub_r001634_20_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001634_20_1 * 2) + 34) & 63;
  int stage_v_359_2 = ((pub_r001634_20_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = (((stage_v_79_1 * 3) + pub_r001634_18_1) + 5) & 127;
  int stage_v_360_2 = (((stage_v_79_2 * 3) + pub_r001634_18_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = ((pub_r001634_1_1 * 2) + 19) & 63;
  int stage_v_361_2 = ((pub_r001634_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001634_15_1 * 2) + 26) & 63;
  int stage_v_362_2 = ((pub_r001634_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001634_8_1 * 2) + 38) & 63;
  int stage_v_363_2 = ((pub_r001634_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001634_1_1 * 2) + 42) & 63;
  int stage_v_364_2 = ((pub_r001634_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = (((stage_v_103_1 * 3) + pub_r001634_14_1) + 44) & 127;
  int stage_v_365_2 = (((stage_v_103_2 * 3) + pub_r001634_14_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = (((stage_v_118_1 * 3) + pub_r001634_18_1) + 41) & 127;
  int stage_v_366_2 = (((stage_v_118_2 * 3) + pub_r001634_18_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = ((pub_r001634_0_1 * 2) + 35) & 63;
  int stage_v_367_2 = ((pub_r001634_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = (((stage_v_260_1 * 3) + pub_r001634_10_1) + 37) & 127;
  int stage_v_368_2 = (((stage_v_260_2 * 3) + pub_r001634_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = ((pub_r001634_16_1 * 2) + 42) & 63;
  int stage_v_369_2 = ((pub_r001634_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001634_17_1 * 2) + 16) & 63;
  int stage_v_370_2 = ((pub_r001634_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = (((stage_v_366_1 * 3) + pub_r001634_18_1) + 29) & 127;
  int stage_v_371_2 = (((stage_v_366_2 * 3) + pub_r001634_18_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = (((stage_v_4_1 * 3) + pub_r001634_17_1) + 35) & 127;
  int stage_v_372_2 = (((stage_v_4_2 * 3) + pub_r001634_17_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = ((pub_r001634_10_1 * 2) + 17) & 63;
  int stage_v_373_2 = ((pub_r001634_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = (((stage_v_266_1 * 3) + pub_r001634_1_1) + 37) & 127;
  int stage_v_374_2 = (((stage_v_266_2 * 3) + pub_r001634_1_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((sec_r001634_13_1 * 3) + pub_r001634_2_1) + 34) & 127;
  int stage_v_375_2 = (((sec_r001634_13_2 * 3) + pub_r001634_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = (((stage_v_174_1 * 3) + pub_r001634_4_1) + 38) & 127;
  int stage_v_376_2 = (((stage_v_174_2 * 3) + pub_r001634_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = (((stage_v_101_1 * 3) + pub_r001634_18_1) + 14) & 127;
  int stage_v_377_2 = (((stage_v_101_2 * 3) + pub_r001634_18_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = (((stage_v_31_1 * 3) + pub_r001634_9_1) + 4) & 127;
  int stage_v_378_2 = (((stage_v_31_2 * 3) + pub_r001634_9_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((stage_v_55_1 * 3) + pub_r001634_13_1) + 3) & 127;
  int stage_v_379_2 = (((stage_v_55_2 * 3) + pub_r001634_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = (((stage_v_72_1 * 3) + pub_r001634_2_1) + 27) & 127;
  int stage_v_380_2 = (((stage_v_72_2 * 3) + pub_r001634_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = (((sec_r001634_1_1 * 3) + pub_r001634_1_1) + 20) & 127;
  int stage_v_381_2 = (((sec_r001634_1_2 * 3) + pub_r001634_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = ((pub_r001634_8_1 * 2) + 48) & 63;
  int stage_v_382_2 = ((pub_r001634_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001634_20_1 * 2) + 11) & 63;
  int stage_v_383_2 = ((pub_r001634_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = (((stage_v_232_1 * 3) + pub_r001634_8_1) + 44) & 127;
  int stage_v_384_2 = (((stage_v_232_2 * 3) + pub_r001634_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = ((pub_r001634_18_1 * 2) + 29) & 63;
  int stage_v_385_2 = ((pub_r001634_18_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001634_1_1 * 2) + 40) & 63;
  int stage_v_386_2 = ((pub_r001634_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = (((stage_v_68_1 * 3) + pub_r001634_3_1) + 23) & 127;
  int stage_v_387_2 = (((stage_v_68_2 * 3) + pub_r001634_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = ((pub_r001634_2_1 * 2) + 19) & 63;
  int stage_v_388_2 = ((pub_r001634_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = (((stage_v_15_1 * 3) + pub_r001634_11_1) + 17) & 127;
  int stage_v_389_2 = (((stage_v_15_2 * 3) + pub_r001634_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = ((pub_r001634_20_1 * 2) + 30) & 63;
  int stage_v_390_2 = ((pub_r001634_20_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = (((stage_v_175_1 * 3) + pub_r001634_19_1) + 38) & 127;
  int stage_v_391_2 = (((stage_v_175_2 * 3) + pub_r001634_19_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((stage_v_309_1 * 3) + pub_r001634_10_1) + 14) & 127;
  int stage_v_392_2 = (((stage_v_309_2 * 3) + pub_r001634_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = ((pub_r001634_5_1 * 2) + 14) & 63;
  int stage_v_393_2 = ((pub_r001634_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = (((stage_v_135_1 * 3) + pub_r001634_5_1) + 30) & 127;
  int stage_v_394_2 = (((stage_v_135_2 * 3) + pub_r001634_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = ((pub_r001634_3_1 * 2) + 17) & 63;
  int stage_v_395_2 = ((pub_r001634_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((stage_v_227_1 * 3) + pub_r001634_4_1) + 24) & 127;
  int stage_v_396_2 = (((stage_v_227_2 * 3) + pub_r001634_4_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = (((stage_v_109_1 * 3) + pub_r001634_14_1) + 37) & 127;
  int stage_v_397_2 = (((stage_v_109_2 * 3) + pub_r001634_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = (((stage_v_202_1 * 3) + pub_r001634_5_1) + 17) & 127;
  int stage_v_398_2 = (((stage_v_202_2 * 3) + pub_r001634_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = (((stage_v_325_1 * 3) + pub_r001634_3_1) + 13) & 127;
  int stage_v_399_2 = (((stage_v_325_2 * 3) + pub_r001634_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = ((pub_r001634_6_1 * 2) + 20) & 63;
  int stage_v_400_2 = ((pub_r001634_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((pub_r001634_14_1 * 2) + 33) & 63;
  int stage_v_401_2 = ((pub_r001634_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = (((stage_v_204_1 * 3) + pub_r001634_18_1) + 26) & 127;
  int stage_v_402_2 = (((stage_v_204_2 * 3) + pub_r001634_18_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = ((pub_r001634_8_1 * 2) + 23) & 63;
  int stage_v_403_2 = ((pub_r001634_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = (((stage_v_384_1 * 3) + pub_r001634_8_1) + 36) & 127;
  int stage_v_404_2 = (((stage_v_384_2 * 3) + pub_r001634_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = (((stage_v_182_1 * 3) + pub_r001634_4_1) + 13) & 127;
  int stage_v_405_2 = (((stage_v_182_2 * 3) + pub_r001634_4_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = ((pub_r001634_1_1 * 2) + 31) & 63;
  int stage_v_406_2 = ((pub_r001634_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((pub_r001634_1_1 * 2) + 27) & 63;
  int stage_v_407_2 = ((pub_r001634_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001634_10_1 * 2) + 9) & 63;
  int stage_v_408_2 = ((pub_r001634_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((pub_r001634_12_1 * 2) + 41) & 63;
  int stage_v_409_2 = ((pub_r001634_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((pub_r001634_8_1 * 2) + 45) & 63;
  int stage_v_410_2 = ((pub_r001634_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = (((stage_v_161_1 * 3) + pub_r001634_0_1) + 15) & 127;
  int stage_v_411_2 = (((stage_v_161_2 * 3) + pub_r001634_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_411_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_411_2 * 2)) & 255;
  int stage_v_412_1 = (((stage_v_314_1 * 3) + pub_r001634_14_1) + 19) & 127;
  int stage_v_412_2 = (((stage_v_314_2 * 3) + pub_r001634_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = ((pub_r001634_4_1 * 2) + 39) & 63;
  int stage_v_413_2 = ((pub_r001634_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = (((stage_v_337_1 * 3) + pub_r001634_4_1) + 36) & 127;
  int stage_v_414_2 = (((stage_v_337_2 * 3) + pub_r001634_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_414_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_414_2 * 2)) & 255;
  int stage_v_415_1 = ((pub_r001634_20_1 * 2) + 40) & 63;
  int stage_v_415_2 = ((pub_r001634_20_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = (((stage_v_127_1 * 3) + pub_r001634_14_1) + 28) & 127;
  int stage_v_416_2 = (((stage_v_127_2 * 3) + pub_r001634_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = ((pub_r001634_18_1 * 2) + 23) & 63;
  int stage_v_417_2 = ((pub_r001634_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001634_8_1 * 2) + 13) & 63;
  int stage_v_418_2 = ((pub_r001634_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = (((stage_v_37_1 * 3) + pub_r001634_16_1) + 9) & 127;
  int stage_v_419_2 = (((stage_v_37_2 * 3) + pub_r001634_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = (((stage_v_321_1 * 3) + pub_r001634_10_1) + 40) & 127;
  int stage_v_420_2 = (((stage_v_321_2 * 3) + pub_r001634_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  int stage_v_421_1 = (((stage_v_336_1 * 3) + pub_r001634_2_1) + 45) & 127;
  int stage_v_421_2 = (((stage_v_336_2 * 3) + pub_r001634_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  int stage_v_422_1 = (((stage_v_27_1 * 3) + pub_r001634_14_1) + 6) & 127;
  int stage_v_422_2 = (((stage_v_27_2 * 3) + pub_r001634_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_422_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_422_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_422_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_422_2 * 2)) & 255;
  int stage_v_423_1 = ((pub_r001634_11_1 * 2) + 6) & 63;
  int stage_v_423_2 = ((pub_r001634_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001634_7_1 * 2) + 27) & 63;
  int stage_v_424_2 = ((pub_r001634_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((pub_r001634_17_1 * 2) + 6) & 63;
  int stage_v_425_2 = ((pub_r001634_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = (((stage_v_421_1 * 3) + pub_r001634_19_1) + 29) & 127;
  int stage_v_426_2 = (((stage_v_421_2 * 3) + pub_r001634_19_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_426_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_426_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_426_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_426_2 * 2)) & 255;
  int stage_v_427_1 = ((pub_r001634_6_1 * 2) + 47) & 63;
  int stage_v_427_2 = ((pub_r001634_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = (((stage_v_75_1 * 3) + pub_r001634_9_1) + 7) & 127;
  int stage_v_428_2 = (((stage_v_75_2 * 3) + pub_r001634_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  int stage_v_429_1 = (((sec_r001634_5_1 * 3) + pub_r001634_11_1) + 29) & 127;
  int stage_v_429_2 = (((sec_r001634_5_2 * 3) + pub_r001634_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = (((stage_v_24_1 * 3) + pub_r001634_14_1) + 3) & 127;
  int stage_v_430_2 = (((stage_v_24_2 * 3) + pub_r001634_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_430_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_430_2 * 2)) & 255;
  int stage_v_431_1 = (((stage_v_42_1 * 3) + pub_r001634_14_1) + 42) & 127;
  int stage_v_431_2 = (((stage_v_42_2 * 3) + pub_r001634_14_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_431_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_431_2 * 2)) & 255;
  int stage_v_432_1 = ((pub_r001634_16_1 * 2) + 49) & 63;
  int stage_v_432_2 = ((pub_r001634_16_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = (((stage_v_238_1 * 3) + pub_r001634_8_1) + 30) & 127;
  int stage_v_433_2 = (((stage_v_238_2 * 3) + pub_r001634_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = (((stage_v_310_1 * 3) + pub_r001634_7_1) + 40) & 127;
  int stage_v_434_2 = (((stage_v_310_2 * 3) + pub_r001634_7_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_434_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_434_2 * 2)) & 255;
  int stage_v_435_1 = ((pub_r001634_7_1 * 2) + 12) & 63;
  int stage_v_435_2 = ((pub_r001634_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = (((stage_v_141_1 * 3) + pub_r001634_3_1) + 10) & 127;
  int stage_v_436_2 = (((stage_v_141_2 * 3) + pub_r001634_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_436_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_436_2 * 2)) & 255;
  int stage_v_437_1 = ((pub_r001634_11_1 * 2) + 44) & 63;
  int stage_v_437_2 = ((pub_r001634_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = (((sec_r001634_2_1 * 3) + pub_r001634_16_1) + 44) & 127;
  int stage_v_438_2 = (((sec_r001634_2_2 * 3) + pub_r001634_16_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_438_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_438_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_438_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_438_2 * 2)) & 255;
  int stage_v_439_1 = ((pub_r001634_5_1 * 2) + 6) & 63;
  int stage_v_439_2 = ((pub_r001634_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = ((pub_r001634_17_1 * 2) + 27) & 63;
  int stage_v_440_2 = ((pub_r001634_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001634_16_1 * 2) + 43) & 63;
  int stage_v_441_2 = ((pub_r001634_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((pub_r001634_1_1 * 2) + 8) & 63;
  int stage_v_442_2 = ((pub_r001634_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = (((stage_v_68_1 * 3) + pub_r001634_16_1) + 16) & 127;
  int stage_v_443_2 = (((stage_v_68_2 * 3) + pub_r001634_16_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_443_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_443_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_443_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_443_2 * 2)) & 255;
  int stage_v_444_1 = ((pub_r001634_17_1 * 2) + 23) & 63;
  int stage_v_444_2 = ((pub_r001634_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((pub_r001634_1_1 * 2) + 49) & 63;
  int stage_v_445_2 = ((pub_r001634_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = (((stage_v_218_1 * 3) + pub_r001634_15_1) + 41) & 127;
  int stage_v_446_2 = (((stage_v_218_2 * 3) + pub_r001634_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_446_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_446_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_446_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_446_2 * 2)) & 255;
  int stage_v_447_1 = (((stage_v_220_1 * 3) + pub_r001634_18_1) + 20) & 127;
  int stage_v_447_2 = (((stage_v_220_2 * 3) + pub_r001634_18_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_447_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_447_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_447_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_447_2 * 2)) & 255;
  int stage_v_448_1 = (((stage_v_289_1 * 3) + pub_r001634_7_1) + 30) & 127;
  int stage_v_448_2 = (((stage_v_289_2 * 3) + pub_r001634_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_448_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_448_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_448_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_448_2 * 2)) & 255;
  int stage_v_449_1 = ((pub_r001634_12_1 * 2) + 45) & 63;
  int stage_v_449_2 = ((pub_r001634_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_449_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_449_2) & 127;
  int stage_v_450_1 = (((stage_v_36_1 * 3) + pub_r001634_16_1) + 30) & 127;
  int stage_v_450_2 = (((stage_v_36_2 * 3) + pub_r001634_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_450_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_450_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_450_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_450_2 * 2)) & 255;
  int stage_v_451_1 = (((sec_r001634_17_1 * 3) + pub_r001634_3_1) + 17) & 127;
  int stage_v_451_2 = (((sec_r001634_17_2 * 3) + pub_r001634_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_451_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_451_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_451_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_451_2 * 2)) & 255;
  int stage_v_452_1 = ((pub_r001634_14_1 * 2) + 33) & 63;
  int stage_v_452_2 = ((pub_r001634_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((pub_r001634_12_1 * 2) + 9) & 63;
  int stage_v_453_2 = ((pub_r001634_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = ((pub_r001634_7_1 * 2) + 22) & 63;
  int stage_v_454_2 = ((pub_r001634_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = (((stage_v_421_1 * 3) + pub_r001634_7_1) + 45) & 127;
  int stage_v_455_2 = (((stage_v_421_2 * 3) + pub_r001634_7_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_455_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_455_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_455_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_455_2 * 2)) & 255;
  int stage_v_456_1 = (((stage_v_348_1 * 3) + pub_r001634_9_1) + 6) & 127;
  int stage_v_456_2 = (((stage_v_348_2 * 3) + pub_r001634_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_456_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_456_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_456_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_456_2 * 2)) & 255;
  int stage_v_457_1 = (((stage_v_195_1 * 3) + pub_r001634_0_1) + 32) & 127;
  int stage_v_457_2 = (((stage_v_195_2 * 3) + pub_r001634_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_457_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_457_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_457_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_457_2 * 2)) & 255;
  int stage_v_458_1 = (((sec_r001634_9_1 * 3) + pub_r001634_12_1) + 35) & 127;
  int stage_v_458_2 = (((sec_r001634_9_2 * 3) + pub_r001634_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_458_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_458_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_458_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_458_2 * 2)) & 255;
  int stage_v_459_1 = (((stage_v_47_1 * 3) + pub_r001634_11_1) + 27) & 127;
  int stage_v_459_2 = (((stage_v_47_2 * 3) + pub_r001634_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_459_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_459_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_459_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_459_2 * 2)) & 255;
  int stage_v_460_1 = (((sec_r001634_14_1 * 3) + pub_r001634_20_1) + 36) & 127;
  int stage_v_460_2 = (((sec_r001634_14_2 * 3) + pub_r001634_20_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_460_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_460_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_460_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_460_2 * 2)) & 255;
  int stage_v_461_1 = ((pub_r001634_4_1 * 2) + 6) & 63;
  int stage_v_461_2 = ((pub_r001634_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = ((pub_r001634_18_1 * 2) + 32) & 63;
  int stage_v_462_2 = ((pub_r001634_18_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_462_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_462_2) & 127;
  int stage_v_463_1 = (((stage_v_286_1 * 3) + pub_r001634_13_1) + 32) & 127;
  int stage_v_463_2 = (((stage_v_286_2 * 3) + pub_r001634_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_463_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_463_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_463_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_463_2 * 2)) & 255;
  int stage_v_464_1 = (((stage_v_316_1 * 3) + pub_r001634_14_1) + 42) & 127;
  int stage_v_464_2 = (((stage_v_316_2 * 3) + pub_r001634_14_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_464_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_464_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_464_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_464_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001634_12_1 == pub_r001634_12_2);
  __CPROVER_assume(sec_r001634_17_1 != sec_r001634_17_2);
  __CPROVER_assume(sec_r001634_15_1 != sec_r001634_15_2);
  __CPROVER_assume(sec_r001634_6_1 != sec_r001634_6_2);
  __CPROVER_assume(sec_r001634_1_1 != sec_r001634_1_2);
  __CPROVER_assume(pub_r001634_3_1 == pub_r001634_3_2);
  __CPROVER_assume(pub_r001634_15_1 == pub_r001634_15_2);
  __CPROVER_assume(pub_r001634_11_1 == pub_r001634_11_2);
  __CPROVER_assume(sec_r001634_12_1 != sec_r001634_12_2);
  __CPROVER_assume(pub_r001634_4_1 == pub_r001634_4_2);
  __CPROVER_assume(sec_r001634_5_1 != sec_r001634_5_2);
  __CPROVER_assume(sec_r001634_2_1 != sec_r001634_2_2);
  __CPROVER_assume(pub_r001634_7_1 == pub_r001634_7_2);
  __CPROVER_assume(sec_r001634_0_1 != sec_r001634_0_2);
  __CPROVER_assume(sec_r001634_4_1 != sec_r001634_4_2);
  __CPROVER_assume(pub_r001634_10_1 == pub_r001634_10_2);
  __CPROVER_assume(sec_r001634_3_1 != sec_r001634_3_2);
  __CPROVER_assume(sec_r001634_10_1 != sec_r001634_10_2);
  __CPROVER_assume(sec_r001634_13_1 != sec_r001634_13_2);
  __CPROVER_assume(sec_r001634_8_1 != sec_r001634_8_2);
  __CPROVER_assume(sec_r001634_11_1 != sec_r001634_11_2);
  __CPROVER_assume(pub_r001634_0_1 == pub_r001634_0_2);
  __CPROVER_assume(pub_r001634_14_1 == pub_r001634_14_2);
  __CPROVER_assume(pub_r001634_20_1 == pub_r001634_20_2);
  __CPROVER_assume(sec_r001634_18_1 != sec_r001634_18_2);
  __CPROVER_assume(pub_r001634_13_1 == pub_r001634_13_2);
  __CPROVER_assume(sec_r001634_19_1 != sec_r001634_19_2);
  __CPROVER_assume(sec_r001634_7_1 != sec_r001634_7_2);
  __CPROVER_assume(pub_r001634_5_1 == pub_r001634_5_2);
  __CPROVER_assume(pub_r001634_8_1 == pub_r001634_8_2);
  __CPROVER_assume(pub_r001634_19_1 == pub_r001634_19_2);
  __CPROVER_assume(pub_r001634_2_1 == pub_r001634_2_2);
  __CPROVER_assume(sec_r001634_16_1 != sec_r001634_16_2);
  __CPROVER_assume(pub_r001634_9_1 == pub_r001634_9_2);
  __CPROVER_assume(pub_r001634_18_1 == pub_r001634_18_2);
  __CPROVER_assume(pub_r001634_6_1 == pub_r001634_6_2);
  __CPROVER_assume(pub_r001634_1_1 == pub_r001634_1_2);
  __CPROVER_assume(pub_r001634_17_1 == pub_r001634_17_2);
  __CPROVER_assume(pub_r001634_16_1 == pub_r001634_16_2);
  __CPROVER_assume(sec_r001634_14_1 != sec_r001634_14_2);
  __CPROVER_assume(sec_r001634_9_1 != sec_r001634_9_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  assert(st_var_2_1.balance == st_var_2_2.balance);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.signature == st_var_3_2.signature);
  assert(st_var_3_1.seq == st_var_3_2.seq);
  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
  assert(st_var_3_1.code == st_var_3_2.code);
  assert(st_var_3_1.facility == st_var_3_2.facility);
  assert(st_var_3_1.severity == st_var_3_2.severity);
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
  assert(stage_v_395_1 == stage_v_395_2);
  assert(stage_v_396_1 == stage_v_396_2);
  assert(stage_v_397_1 == stage_v_397_2);
  assert(stage_v_398_1 == stage_v_398_2);
  assert(stage_v_399_1 == stage_v_399_2);
  assert(stage_v_400_1 == stage_v_400_2);
  assert(stage_v_401_1 == stage_v_401_2);
  assert(stage_v_402_1 == stage_v_402_2);
  assert(stage_v_403_1 == stage_v_403_2);
  assert(stage_v_404_1 == stage_v_404_2);
  assert(stage_v_405_1 == stage_v_405_2);
  assert(stage_v_406_1 == stage_v_406_2);
  assert(stage_v_407_1 == stage_v_407_2);
  assert(stage_v_408_1 == stage_v_408_2);
  assert(stage_v_409_1 == stage_v_409_2);
  assert(stage_v_410_1 == stage_v_410_2);
  assert(stage_v_411_1 == stage_v_411_2);
  assert(stage_v_412_1 == stage_v_412_2);
  assert(stage_v_413_1 == stage_v_413_2);
  assert(stage_v_414_1 == stage_v_414_2);
  assert(stage_v_415_1 == stage_v_415_2);
  assert(stage_v_416_1 == stage_v_416_2);
  assert(stage_v_417_1 == stage_v_417_2);
  assert(stage_v_418_1 == stage_v_418_2);
  assert(stage_v_419_1 == stage_v_419_2);
  assert(stage_v_420_1 == stage_v_420_2);
  assert(stage_v_421_1 == stage_v_421_2);
  assert(stage_v_422_1 == stage_v_422_2);
  assert(stage_v_423_1 == stage_v_423_2);
  assert(stage_v_424_1 == stage_v_424_2);
  assert(stage_v_425_1 == stage_v_425_2);
  assert(stage_v_426_1 == stage_v_426_2);
  assert(stage_v_427_1 == stage_v_427_2);
  assert(stage_v_428_1 == stage_v_428_2);
  assert(stage_v_429_1 == stage_v_429_2);
  assert(stage_v_430_1 == stage_v_430_2);
  assert(stage_v_431_1 == stage_v_431_2);
  assert(stage_v_432_1 == stage_v_432_2);
  assert(stage_v_433_1 == stage_v_433_2);
  assert(stage_v_434_1 == stage_v_434_2);
  assert(stage_v_435_1 == stage_v_435_2);
  assert(stage_v_436_1 == stage_v_436_2);
  assert(stage_v_437_1 == stage_v_437_2);
  assert(stage_v_438_1 == stage_v_438_2);
  assert(stage_v_439_1 == stage_v_439_2);
  assert(stage_v_440_1 == stage_v_440_2);
  assert(stage_v_441_1 == stage_v_441_2);
  assert(stage_v_442_1 == stage_v_442_2);
  assert(stage_v_443_1 == stage_v_443_2);
  assert(stage_v_444_1 == stage_v_444_2);
  assert(stage_v_445_1 == stage_v_445_2);
  assert(stage_v_446_1 == stage_v_446_2);
  assert(stage_v_447_1 == stage_v_447_2);
  assert(stage_v_448_1 == stage_v_448_2);
  assert(stage_v_449_1 == stage_v_449_2);
  assert(stage_v_450_1 == stage_v_450_2);
  assert(stage_v_451_1 == stage_v_451_2);
  assert(stage_v_452_1 == stage_v_452_2);
  assert(stage_v_453_1 == stage_v_453_2);
  assert(stage_v_454_1 == stage_v_454_2);
  assert(stage_v_455_1 == stage_v_455_2);
  assert(stage_v_456_1 == stage_v_456_2);
  assert(stage_v_457_1 == stage_v_457_2);
  assert(stage_v_458_1 == stage_v_458_2);
  assert(stage_v_459_1 == stage_v_459_2);
  assert(stage_v_460_1 == stage_v_460_2);
  assert(stage_v_461_1 == stage_v_461_2);
  assert(stage_v_462_1 == stage_v_462_2);
  assert(stage_v_463_1 == stage_v_463_2);
  assert(stage_v_464_1 == stage_v_464_2);
}


