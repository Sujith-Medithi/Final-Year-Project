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
struct DeviceConfig_R001870_7013_0
{
  short id;
  int stop_bits;
  int port;
  unsigned char baud_rate;
  unsigned char timeout;
  int parity;
  int buffer[3];
};
struct CipherContext_R001870_7013_1
{
  int flags;
  int round_key;
  short iv;
  int buffer[3];
};
struct FilterState_R001870_7013_2
{
  int prev_in;
  int prev_out;
  int damping;
  short cutoff;
  short gain_db;
  int buffer[3];
};
union PacketPayload_R001870_7013_0
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
void fn_R001870_7013_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st_1 = {0};
  struct FilterState_R001870_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_95_1)
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

  switch (quotient_95_2)
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
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_95_1 == quotient_95_2);
}

int fn_R001870_7013_0(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_95 = (aux + st.buffer[1]) & 3;
  switch (quotient_95)
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

void fn_R001870_7013_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001870_7013_1 st_1 = {0};
  struct CipherContext_R001870_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_40_1)
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

  switch (index_reg_40_2)
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

  int quotient_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_15_1) & 63;
  aux_2 = (aux_2 + quotient_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_79_1 = 0;
  int bound_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_79_1 = ((bound_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_79_2 = ((bound_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_79_1) & 127;
    acc_2 = (acc_2 + bound_79_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_40_1 == index_reg_40_2);
  assert(quotient_15_1 == quotient_15_2);
  assert(bound_79_1 == bound_79_2);
}

int fn_R001870_7013_1(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001870_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_40 = (aux + st.buffer[1]) & 3;
  switch (index_reg_40)
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

  int quotient_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_15) & 63;
  acc ^= aux;
  int bound_79 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_79 = ((bound_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_79) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001870_7013_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001870_7013_0 st_1 = {0};
  struct DeviceConfig_R001870_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int factor_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_13_1 > 11)
  {
    acc_1 = ((acc_1 + (factor_13_1 * 2)) + 5) & 127;
    aux_1 ^= factor_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_13_2 > 11)
  {
    acc_2 = ((acc_2 + (factor_13_2 * 2)) + 5) & 127;
    aux_2 ^= factor_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_53_1)
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

  switch (threshold_53_2)
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
  int mask_21_1 = local_arr_1[aux_1 % 3];
  int mask_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_21_2 * 2)) & 127;
  int residue_29_1 = 0;
  int residue_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_29_1 = ((residue_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_29_2 = ((residue_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_29_1) & 127;
    acc_2 = (acc_2 + residue_29_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_13_1 == factor_13_2);
  assert(threshold_53_1 == threshold_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_21_1 == mask_21_2);
  assert(residue_29_1 == residue_29_2);
}

int fn_R001870_7013_2(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001870_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int factor_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_13 > 11)
  {
    acc = ((acc + (factor_13 * 2)) + 5) & 127;
    aux ^= factor_13 & 15;
  }
  else
  {
    acc = ((acc - factor_13) + 11) & 127;
    aux += 3;
  }
  int threshold_53 = (aux + st.buffer[1]) & 3;
  switch (threshold_53)
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
  int mask_21 = local_arr[aux % 3];
  acc = (acc + (mask_21 * 2)) & 127;
  int residue_29 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_29 = ((residue_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_29) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001870_7013_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001870_7013_1 st_1 = {0};
  struct CipherContext_R001870_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int scale_62_1 = 0;
  int scale_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_62_1 = ((scale_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_62_2 = ((scale_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_62_1) & 127;
    acc_2 = (acc_2 + scale_62_2) & 127;
  }

  int threshold_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_87_1) & 63;
  aux_2 = (aux_2 + threshold_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_79_1 = local_arr_1[aux_1 % 3];
  int index_reg_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_79_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_62_1 == scale_62_2);
  assert(threshold_87_1 == threshold_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_79_1 == index_reg_79_2);
}

int fn_R001870_7013_3(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001870_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int scale_62 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_62 = ((scale_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_62) & 127;
  }

  int threshold_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_87) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_79 = local_arr[aux % 3];
  acc = (acc + (index_reg_79 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001870_7013_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st_1 = {0};
  struct FilterState_R001870_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int offset_75_1 = 0;
  int offset_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_75_1 = ((offset_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_75_2 = ((offset_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_75_1) & 127;
    acc_2 = (acc_2 + offset_75_2) & 127;
  }

  int coefficient_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_57_1)
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

  switch (coefficient_57_2)
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

  int damping_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_77_1) & 63;
  aux_2 = (aux_2 + damping_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_75_1 == offset_75_2);
  assert(coefficient_57_1 == coefficient_57_2);
  assert(damping_77_1 == damping_77_2);
}

int fn_R001870_7013_4(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int offset_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_75 = ((offset_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_75) & 127;
  }

  int coefficient_57 = (aux + st.buffer[1]) & 3;
  switch (coefficient_57)
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

  int damping_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_77) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001870_7013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001870_7013_0 st_1 = {0};
  struct DeviceConfig_R001870_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int window_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_22_1) & 63;
  aux_2 = (aux_2 + window_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_17_1 = 0;
  int margin_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_17_1 = ((margin_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_17_2 = ((margin_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_17_1) & 127;
    acc_2 = (acc_2 + margin_17_2) & 127;
  }

  int weight_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_20_1 > 49)
  {
    acc_1 = ((acc_1 + (weight_20_1 * 2)) + 5) & 127;
    aux_1 ^= weight_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_20_2 > 49)
  {
    acc_2 = ((acc_2 + (weight_20_2 * 2)) + 5) & 127;
    aux_2 ^= weight_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_36_1 = local_arr_1[aux_1 % 3];
  int cursor_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_22_1 == window_22_2);
  assert(margin_17_1 == margin_17_2);
  assert(weight_20_1 == weight_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_36_1 == cursor_36_2);
}

int fn_R001870_7013_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001870_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int window_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_22) & 63;
  acc ^= aux;
  int margin_17 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_17 = ((margin_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_17) & 127;
  }

  int weight_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_20 > 49)
  {
    acc = ((acc + (weight_20 * 2)) + 5) & 127;
    aux ^= weight_20 & 15;
  }
  else
  {
    acc = ((acc - weight_20) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_36 = local_arr[aux % 3];
  acc = (acc + (cursor_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001870_7013_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st_1 = {0};
  struct FilterState_R001870_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int segment_59_1 = 0;
  int segment_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_59_1 = ((segment_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_59_2 = ((segment_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_59_1) & 127;
    acc_2 = (acc_2 + segment_59_2) & 127;
  }

  int tracker_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_84_1 > 31)
  {
    acc_1 = ((acc_1 + (tracker_84_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_84_2 > 31)
  {
    acc_2 = ((acc_2 + (tracker_84_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_84_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_59_1 == segment_59_2);
  assert(tracker_84_1 == tracker_84_2);
}

int fn_R001870_7013_6(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int segment_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_59 = ((segment_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_59) & 127;
  }

  int tracker_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_84 > 31)
  {
    acc = ((acc + (tracker_84 * 2)) + 5) & 127;
    aux ^= tracker_84 & 15;
  }
  else
  {
    acc = ((acc - tracker_84) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001870_7013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st_1 = {0};
  struct FilterState_R001870_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_71_1 = local_arr_1[aux_1 % 3];
  int tally_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_71_2 * 2)) & 127;
  int weight_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_90_1)
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

  switch (weight_90_2)
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

  int scale_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_81_1) & 63;
  aux_2 = (aux_2 + scale_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_71_1 == tally_71_2);
  assert(weight_90_1 == weight_90_2);
  assert(scale_81_1 == scale_81_2);
}

int fn_R001870_7013_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int tally_71 = local_arr[aux % 3];
  acc = (acc + (tally_71 * 2)) & 127;
  int weight_90 = (aux + st.buffer[1]) & 3;
  switch (weight_90)
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

  int scale_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_81) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001870_7013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st_1 = {0};
  struct FilterState_R001870_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int threshold_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_53_1)
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

  switch (threshold_53_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_72_1) & 63;
  aux_2 = (aux_2 + weight_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_53_1 == threshold_53_2);
  assert(weight_72_1 == weight_72_2);
}

int fn_R001870_7013_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int threshold_53 = (aux + st.buffer[1]) & 3;
  switch (threshold_53)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_72) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001870_7013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st_1 = {0};
  struct FilterState_R001870_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_53_1 > 49)
  {
    acc_1 = ((acc_1 + (metric_53_1 * 2)) + 5) & 127;
    aux_1 ^= metric_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_53_2 > 49)
  {
    acc_2 = ((acc_2 + (metric_53_2 * 2)) + 5) & 127;
    aux_2 ^= metric_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_53_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_53_1 = 0;
  int parity_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_53_1 = ((parity_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_53_2 = ((parity_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_53_1) & 127;
    acc_2 = (acc_2 + parity_53_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_53_1 == metric_53_2);
  assert(parity_53_1 == parity_53_2);
}

int fn_R001870_7013_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_53 > 49)
  {
    acc = ((acc + (metric_53 * 2)) + 5) & 127;
    aux ^= metric_53 & 15;
  }
  else
  {
    acc = ((acc - metric_53) + 11) & 127;
    aux += 3;
  }
  int parity_53 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_53 = ((parity_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_53) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001870_7013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st_1 = {0};
  struct FilterState_R001870_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_83_1) & 63;
  aux_2 = (aux_2 + scale_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_11_1 > 25)
  {
    acc_1 = ((acc_1 + (parity_11_1 * 2)) + 5) & 127;
    aux_1 ^= parity_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_11_2 > 25)
  {
    acc_2 = ((acc_2 + (parity_11_2 * 2)) + 5) & 127;
    aux_2 ^= parity_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_11_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_83_1 == scale_83_2);
  assert(parity_11_1 == parity_11_2);
}

int fn_R001870_7013_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_83) & 63;
  acc ^= aux;
  int parity_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_11 > 25)
  {
    acc = ((acc + (parity_11 * 2)) + 5) & 127;
    aux ^= parity_11 & 15;
  }
  else
  {
    acc = ((acc - parity_11) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001870_7013_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001870_7013_1 st_1 = {0};
  struct CipherContext_R001870_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_69_1 = local_arr_1[aux_1 % 3];
  int parity_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_69_2 * 2)) & 127;
  int quantum_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_31_1 > 17)
  {
    acc_1 = ((acc_1 + (quantum_31_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_31_2 > 17)
  {
    acc_2 = ((acc_2 + (quantum_31_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_31_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_69_1 == parity_69_2);
  assert(quantum_31_1 == quantum_31_2);
}

int fn_R001870_7013_11(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001870_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_69 = local_arr[aux % 3];
  acc = (acc + (parity_69 * 2)) & 127;
  int quantum_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_31 > 17)
  {
    acc = ((acc + (quantum_31 * 2)) + 5) & 127;
    aux ^= quantum_31 & 15;
  }
  else
  {
    acc = ((acc - quantum_31) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001870_7013_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001870_7013_0 st_1 = {0};
  struct DeviceConfig_R001870_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_53_1 = local_arr_1[aux_1 % 3];
  int tracker_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_53_2 * 2)) & 127;
  int damping_95_1 = 0;
  int damping_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_95_1 = ((damping_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_95_2 = ((damping_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_95_1) & 127;
    acc_2 = (acc_2 + damping_95_2) & 127;
  }

  int tracker_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_92_1) & 63;
  aux_2 = (aux_2 + tracker_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_54_1)
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

  switch (mask_54_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_53_1 == tracker_53_2);
  assert(damping_95_1 == damping_95_2);
  assert(tracker_92_1 == tracker_92_2);
  assert(mask_54_1 == mask_54_2);
}

int fn_R001870_7013_12(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001870_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int tracker_53 = local_arr[aux % 3];
  acc = (acc + (tracker_53 * 2)) & 127;
  int damping_95 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_95 = ((damping_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_95) & 127;
  }

  int tracker_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_92) & 63;
  acc ^= aux;
  int mask_54 = (aux + st.buffer[1]) & 3;
  switch (mask_54)
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

void fn_R001870_7013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001870_7013_1 st_1 = {0};
  struct CipherContext_R001870_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int parity_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_87_1) & 63;
  aux_2 = (aux_2 + parity_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_47_1 = local_arr_1[aux_1 % 3];
  int anchor_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_47_2 * 2)) & 127;
  int cursor_24_1 = 0;
  int cursor_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_24_1 = ((cursor_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_24_2 = ((cursor_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_24_1) & 127;
    acc_2 = (acc_2 + cursor_24_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_87_1 == parity_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_47_1 == anchor_47_2);
  assert(cursor_24_1 == cursor_24_2);
}

int fn_R001870_7013_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001870_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int parity_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_87) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_47 = local_arr[aux % 3];
  acc = (acc + (anchor_47 * 2)) & 127;
  int cursor_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_24 = ((cursor_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_24) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001870_7013_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001870_7013_1 st_1 = {0};
  struct CipherContext_R001870_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int index_reg_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_78_1 > 48)
  {
    acc_1 = ((acc_1 + (index_reg_78_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_78_2 > 48)
  {
    acc_2 = ((acc_2 + (index_reg_78_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_78_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_22_1 = 0;
  int damping_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_22_1 = ((damping_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_22_2 = ((damping_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_22_1) & 127;
    acc_2 = (acc_2 + damping_22_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_78_1 == index_reg_78_2);
  assert(damping_22_1 == damping_22_2);
}

int fn_R001870_7013_14(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001870_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int index_reg_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_78 > 48)
  {
    acc = ((acc + (index_reg_78 * 2)) + 5) & 127;
    aux ^= index_reg_78 & 15;
  }
  else
  {
    acc = ((acc - index_reg_78) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_22 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_22 = ((damping_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_22) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001870_7013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st_1 = {0};
  struct FilterState_R001870_7013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_81_1 = local_arr_1[aux_1 % 3];
  int margin_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_81_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_81_1 == margin_81_2);
}

int fn_R001870_7013_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001870_7013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int margin_81 = local_arr[aux % 3];
  acc = (acc + (margin_81 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001870_7013_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001870_7013_1 st_1 = {0};
  struct CipherContext_R001870_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int sample_37_1 = 0;
  int sample_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_37_1 = ((sample_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_37_2 = ((sample_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_37_1) & 127;
    acc_2 = (acc_2 + sample_37_2) & 127;
  }

  int tracker_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_79_1)
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

  switch (tracker_79_2)
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

  int cursor_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_78_1 > 49)
  {
    acc_1 = ((acc_1 + (cursor_78_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_78_2 > 49)
  {
    acc_2 = ((acc_2 + (cursor_78_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_57_1 = local_arr_1[aux_1 % 3];
  int checksum_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_57_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_37_1 == sample_37_2);
  assert(tracker_79_1 == tracker_79_2);
  assert(cursor_78_1 == cursor_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_57_1 == checksum_57_2);
}

int fn_R001870_7013_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001870_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int sample_37 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_37 = ((sample_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_37) & 127;
  }

  int tracker_79 = (aux + st.buffer[1]) & 3;
  switch (tracker_79)
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

  int cursor_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_78 > 49)
  {
    acc = ((acc + (cursor_78 * 2)) + 5) & 127;
    aux ^= cursor_78 & 15;
  }
  else
  {
    acc = ((acc - cursor_78) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_57 = local_arr[aux % 3];
  acc = (acc + (checksum_57 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001870_7013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001870_7013_1 st_1 = {0};
  struct CipherContext_R001870_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int segment_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_79_1) & 63;
  aux_2 = (aux_2 + segment_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_51_1)
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

  switch (phase_51_2)
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
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_79_1 == segment_79_2);
  assert(phase_51_1 == phase_51_2);
}

int fn_R001870_7013_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001870_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int segment_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_79) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_51 = (aux + st.buffer[1]) & 3;
  switch (phase_51)
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

void main()
{
  int sec_r001870_0_1;
  int sec_r001870_0_2;
  int sec_r001870_1_1;
  int sec_r001870_1_2;
  int sec_r001870_2_1;
  int sec_r001870_2_2;
  int sec_r001870_3_1;
  int sec_r001870_3_2;
  int sec_r001870_4_1;
  int sec_r001870_4_2;
  int sec_r001870_5_1;
  int sec_r001870_5_2;
  int sec_r001870_6_1;
  int sec_r001870_6_2;
  int sec_r001870_7_1;
  int sec_r001870_7_2;
  int sec_r001870_8_1;
  int sec_r001870_8_2;
  int sec_r001870_9_1;
  int sec_r001870_9_2;
  int sec_r001870_10_1;
  int sec_r001870_10_2;
  int sec_r001870_11_1;
  int sec_r001870_11_2;
  int sec_r001870_12_1;
  int sec_r001870_12_2;
  int sec_r001870_13_1;
  int sec_r001870_13_2;
  int sec_r001870_14_1;
  int sec_r001870_14_2;
  int sec_r001870_15_1;
  int sec_r001870_15_2;
  int pub_r001870_0_1;
  int pub_r001870_0_2;
  int pub_r001870_1_1;
  int pub_r001870_1_2;
  int pub_r001870_2_1;
  int pub_r001870_2_2;
  int pub_r001870_3_1;
  int pub_r001870_3_2;
  int pub_r001870_4_1;
  int pub_r001870_4_2;
  int pub_r001870_5_1;
  int pub_r001870_5_2;
  int pub_r001870_6_1;
  int pub_r001870_6_2;
  int pub_r001870_7_1;
  int pub_r001870_7_2;
  int pub_r001870_8_1;
  int pub_r001870_8_2;
  int pub_r001870_9_1;
  int pub_r001870_9_2;
  int pub_r001870_10_1;
  int pub_r001870_10_2;
  int pub_r001870_11_1;
  int pub_r001870_11_2;
  int pub_r001870_12_1;
  int pub_r001870_12_2;
  int pub_r001870_13_1;
  int pub_r001870_13_2;
  int pub_r001870_14_1;
  int pub_r001870_14_2;
  int pub_r001870_15_1;
  int pub_r001870_15_2;
  int pub_r001870_16_1;
  int pub_r001870_16_2;
  int pub_r001870_17_1;
  int pub_r001870_17_2;
  int pub_r001870_18_1;
  int pub_r001870_18_2;
  int pub_r001870_19_1;
  int pub_r001870_19_2;
  int pub_r001870_20_1;
  int pub_r001870_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001870_0_1 >= (-100)) && (pub_r001870_0_1 <= 100));
  __CPROVER_assume((pub_r001870_0_2 >= (-100)) && (pub_r001870_0_2 <= 100));
  __CPROVER_assume((pub_r001870_1_1 >= (-100)) && (pub_r001870_1_1 <= 100));
  __CPROVER_assume((pub_r001870_1_2 >= (-100)) && (pub_r001870_1_2 <= 100));
  __CPROVER_assume((pub_r001870_2_1 >= (-100)) && (pub_r001870_2_1 <= 100));
  __CPROVER_assume((pub_r001870_2_2 >= (-100)) && (pub_r001870_2_2 <= 100));
  __CPROVER_assume((pub_r001870_3_1 >= (-100)) && (pub_r001870_3_1 <= 100));
  __CPROVER_assume((pub_r001870_3_2 >= (-100)) && (pub_r001870_3_2 <= 100));
  __CPROVER_assume((pub_r001870_4_1 >= (-100)) && (pub_r001870_4_1 <= 100));
  __CPROVER_assume((pub_r001870_4_2 >= (-100)) && (pub_r001870_4_2 <= 100));
  __CPROVER_assume((pub_r001870_5_1 >= (-100)) && (pub_r001870_5_1 <= 100));
  __CPROVER_assume((pub_r001870_5_2 >= (-100)) && (pub_r001870_5_2 <= 100));
  __CPROVER_assume((pub_r001870_6_1 >= (-100)) && (pub_r001870_6_1 <= 100));
  __CPROVER_assume((pub_r001870_6_2 >= (-100)) && (pub_r001870_6_2 <= 100));
  __CPROVER_assume((pub_r001870_7_1 >= (-100)) && (pub_r001870_7_1 <= 100));
  __CPROVER_assume((pub_r001870_7_2 >= (-100)) && (pub_r001870_7_2 <= 100));
  __CPROVER_assume((pub_r001870_8_1 >= (-100)) && (pub_r001870_8_1 <= 100));
  __CPROVER_assume((pub_r001870_8_2 >= (-100)) && (pub_r001870_8_2 <= 100));
  __CPROVER_assume((pub_r001870_9_1 >= (-100)) && (pub_r001870_9_1 <= 100));
  __CPROVER_assume((pub_r001870_9_2 >= (-100)) && (pub_r001870_9_2 <= 100));
  __CPROVER_assume((pub_r001870_10_1 >= (-100)) && (pub_r001870_10_1 <= 100));
  __CPROVER_assume((pub_r001870_10_2 >= (-100)) && (pub_r001870_10_2 <= 100));
  __CPROVER_assume((pub_r001870_11_1 >= (-100)) && (pub_r001870_11_1 <= 100));
  __CPROVER_assume((pub_r001870_11_2 >= (-100)) && (pub_r001870_11_2 <= 100));
  __CPROVER_assume((pub_r001870_12_1 >= (-100)) && (pub_r001870_12_1 <= 100));
  __CPROVER_assume((pub_r001870_12_2 >= (-100)) && (pub_r001870_12_2 <= 100));
  __CPROVER_assume((pub_r001870_13_1 >= (-100)) && (pub_r001870_13_1 <= 100));
  __CPROVER_assume((pub_r001870_13_2 >= (-100)) && (pub_r001870_13_2 <= 100));
  __CPROVER_assume((pub_r001870_14_1 >= (-100)) && (pub_r001870_14_1 <= 100));
  __CPROVER_assume((pub_r001870_14_2 >= (-100)) && (pub_r001870_14_2 <= 100));
  __CPROVER_assume((pub_r001870_15_1 >= (-100)) && (pub_r001870_15_1 <= 100));
  __CPROVER_assume((pub_r001870_15_2 >= (-100)) && (pub_r001870_15_2 <= 100));
  __CPROVER_assume((pub_r001870_16_1 >= (-100)) && (pub_r001870_16_1 <= 100));
  __CPROVER_assume((pub_r001870_16_2 >= (-100)) && (pub_r001870_16_2 <= 100));
  __CPROVER_assume((pub_r001870_17_1 >= (-100)) && (pub_r001870_17_1 <= 100));
  __CPROVER_assume((pub_r001870_17_2 >= (-100)) && (pub_r001870_17_2 <= 100));
  __CPROVER_assume((pub_r001870_18_1 >= (-100)) && (pub_r001870_18_1 <= 100));
  __CPROVER_assume((pub_r001870_18_2 >= (-100)) && (pub_r001870_18_2 <= 100));
  __CPROVER_assume((pub_r001870_19_1 >= (-100)) && (pub_r001870_19_1 <= 100));
  __CPROVER_assume((pub_r001870_19_2 >= (-100)) && (pub_r001870_19_2 <= 100));
  __CPROVER_assume((pub_r001870_20_1 >= (-100)) && (pub_r001870_20_1 <= 100));
  __CPROVER_assume((pub_r001870_20_2 >= (-100)) && (pub_r001870_20_2 <= 100));
  __CPROVER_assume((sec_r001870_0_1 >= 0) && (sec_r001870_0_1 <= 255));
  __CPROVER_assume((sec_r001870_0_2 >= 0) && (sec_r001870_0_2 <= 255));
  __CPROVER_assume((sec_r001870_1_1 >= 0) && (sec_r001870_1_1 <= 255));
  __CPROVER_assume((sec_r001870_1_2 >= 0) && (sec_r001870_1_2 <= 255));
  __CPROVER_assume((sec_r001870_2_1 >= 0) && (sec_r001870_2_1 <= 255));
  __CPROVER_assume((sec_r001870_2_2 >= 0) && (sec_r001870_2_2 <= 255));
  __CPROVER_assume((sec_r001870_3_1 >= 0) && (sec_r001870_3_1 <= 255));
  __CPROVER_assume((sec_r001870_3_2 >= 0) && (sec_r001870_3_2 <= 255));
  __CPROVER_assume((sec_r001870_4_1 >= 0) && (sec_r001870_4_1 <= 255));
  __CPROVER_assume((sec_r001870_4_2 >= 0) && (sec_r001870_4_2 <= 255));
  __CPROVER_assume((sec_r001870_5_1 >= 0) && (sec_r001870_5_1 <= 255));
  __CPROVER_assume((sec_r001870_5_2 >= 0) && (sec_r001870_5_2 <= 255));
  __CPROVER_assume((sec_r001870_6_1 >= 0) && (sec_r001870_6_1 <= 255));
  __CPROVER_assume((sec_r001870_6_2 >= 0) && (sec_r001870_6_2 <= 255));
  __CPROVER_assume((sec_r001870_7_1 >= 0) && (sec_r001870_7_1 <= 255));
  __CPROVER_assume((sec_r001870_7_2 >= 0) && (sec_r001870_7_2 <= 255));
  __CPROVER_assume((sec_r001870_8_1 >= 0) && (sec_r001870_8_1 <= 255));
  __CPROVER_assume((sec_r001870_8_2 >= 0) && (sec_r001870_8_2 <= 255));
  __CPROVER_assume((sec_r001870_9_1 >= 0) && (sec_r001870_9_1 <= 255));
  __CPROVER_assume((sec_r001870_9_2 >= 0) && (sec_r001870_9_2 <= 255));
  __CPROVER_assume((sec_r001870_10_1 >= 0) && (sec_r001870_10_1 <= 255));
  __CPROVER_assume((sec_r001870_10_2 >= 0) && (sec_r001870_10_2 <= 255));
  __CPROVER_assume((sec_r001870_11_1 >= 0) && (sec_r001870_11_1 <= 255));
  __CPROVER_assume((sec_r001870_11_2 >= 0) && (sec_r001870_11_2 <= 255));
  __CPROVER_assume((sec_r001870_12_1 >= 0) && (sec_r001870_12_1 <= 255));
  __CPROVER_assume((sec_r001870_12_2 >= 0) && (sec_r001870_12_2 <= 255));
  __CPROVER_assume((sec_r001870_13_1 >= 0) && (sec_r001870_13_1 <= 255));
  __CPROVER_assume((sec_r001870_13_2 >= 0) && (sec_r001870_13_2 <= 255));
  __CPROVER_assume((sec_r001870_14_1 >= 0) && (sec_r001870_14_1 <= 255));
  __CPROVER_assume((sec_r001870_14_2 >= 0) && (sec_r001870_14_2 <= 255));
  __CPROVER_assume((sec_r001870_15_1 >= 0) && (sec_r001870_15_1 <= 255));
  __CPROVER_assume((sec_r001870_15_2 >= 0) && (sec_r001870_15_2 <= 255));
  struct DeviceConfig_R001870_7013_0 st_var_0_1 = {0};
  struct DeviceConfig_R001870_7013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001870_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001870_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001870_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001870_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001870_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001870_0_2 + 7) & 15;
  struct CipherContext_R001870_7013_1 st_var_1_1 = {0};
  struct CipherContext_R001870_7013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001870_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001870_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001870_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001870_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001870_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001870_0_2 + 9) & 15;
  struct FilterState_R001870_7013_2 st_var_2_1 = {0};
  struct FilterState_R001870_7013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001870_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001870_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001870_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001870_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001870_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001870_0_2 + 11) & 15;
  union PacketPayload_R001870_7013_0 u_var_1;
  union PacketPayload_R001870_7013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001870_7013_0(sec_r001870_0_1, sec_r001870_1_1, pub_r001870_2_1);
  int helper_flow_0_2 = fn_R001870_7013_0(sec_r001870_0_2, sec_r001870_1_2, pub_r001870_2_2);
  fn_R001870_7013_0_2(sec_r001870_0_1, sec_r001870_1_1, pub_r001870_2_1, sec_r001870_0_2, sec_r001870_1_2, pub_r001870_2_2);
  int helper_flow_1_1 = fn_R001870_7013_1(sec_r001870_1_1, pub_r001870_2_1, pub_r001870_3_1);
  int helper_flow_1_2 = fn_R001870_7013_1(sec_r001870_1_2, pub_r001870_2_2, pub_r001870_3_2);
  fn_R001870_7013_1_2(sec_r001870_1_1, pub_r001870_2_1, pub_r001870_3_1, sec_r001870_1_2, pub_r001870_2_2, pub_r001870_3_2);
  int helper_flow_2_1 = fn_R001870_7013_2(sec_r001870_2_1, pub_r001870_3_1, pub_r001870_4_1);
  int helper_flow_2_2 = fn_R001870_7013_2(sec_r001870_2_2, pub_r001870_3_2, pub_r001870_4_2);
  fn_R001870_7013_2_2(sec_r001870_2_1, pub_r001870_3_1, pub_r001870_4_1, sec_r001870_2_2, pub_r001870_3_2, pub_r001870_4_2);
  int helper_flow_3_1 = fn_R001870_7013_3(sec_r001870_3_1, pub_r001870_4_1);
  int helper_flow_3_2 = fn_R001870_7013_3(sec_r001870_3_2, pub_r001870_4_2);
  fn_R001870_7013_3_2(sec_r001870_3_1, pub_r001870_4_1, sec_r001870_3_2, pub_r001870_4_2);
  int helper_flow_4_1 = fn_R001870_7013_4(sec_r001870_4_1, sec_r001870_5_1);
  int helper_flow_4_2 = fn_R001870_7013_4(sec_r001870_4_2, sec_r001870_5_2);
  fn_R001870_7013_4_2(sec_r001870_4_1, sec_r001870_5_1, sec_r001870_4_2, sec_r001870_5_2);
  int helper_flow_5_1 = fn_R001870_7013_5(sec_r001870_5_1, pub_r001870_6_1, pub_r001870_7_1, pub_r001870_8_1, pub_r001870_9_1);
  int helper_flow_5_2 = fn_R001870_7013_5(sec_r001870_5_2, pub_r001870_6_2, pub_r001870_7_2, pub_r001870_8_2, pub_r001870_9_2);
  fn_R001870_7013_5_2(sec_r001870_5_1, pub_r001870_6_1, pub_r001870_7_1, pub_r001870_8_1, pub_r001870_9_1, sec_r001870_5_2, pub_r001870_6_2, pub_r001870_7_2, pub_r001870_8_2, pub_r001870_9_2);
  int helper_flow_6_1 = fn_R001870_7013_6(sec_r001870_6_1, sec_r001870_7_1);
  int helper_flow_6_2 = fn_R001870_7013_6(sec_r001870_6_2, sec_r001870_7_2);
  fn_R001870_7013_6_2(sec_r001870_6_1, sec_r001870_7_1, sec_r001870_6_2, sec_r001870_7_2);
  int helper_flow_7_1 = fn_R001870_7013_7(sec_r001870_7_1, pub_r001870_8_1, pub_r001870_9_1, pub_r001870_10_1, pub_r001870_11_1);
  int helper_flow_7_2 = fn_R001870_7013_7(sec_r001870_7_2, pub_r001870_8_2, pub_r001870_9_2, pub_r001870_10_2, pub_r001870_11_2);
  fn_R001870_7013_7_2(sec_r001870_7_1, pub_r001870_8_1, pub_r001870_9_1, pub_r001870_10_1, pub_r001870_11_1, sec_r001870_7_2, pub_r001870_8_2, pub_r001870_9_2, pub_r001870_10_2, pub_r001870_11_2);
  int helper_flow_8_1 = fn_R001870_7013_8(sec_r001870_8_1, pub_r001870_9_1, pub_r001870_10_1, pub_r001870_11_1);
  int helper_flow_8_2 = fn_R001870_7013_8(sec_r001870_8_2, pub_r001870_9_2, pub_r001870_10_2, pub_r001870_11_2);
  fn_R001870_7013_8_2(sec_r001870_8_1, pub_r001870_9_1, pub_r001870_10_1, pub_r001870_11_1, sec_r001870_8_2, pub_r001870_9_2, pub_r001870_10_2, pub_r001870_11_2);
  int helper_flow_9_1 = fn_R001870_7013_9(sec_r001870_9_1, pub_r001870_10_1, pub_r001870_11_1, pub_r001870_12_1, pub_r001870_13_1);
  int helper_flow_9_2 = fn_R001870_7013_9(sec_r001870_9_2, pub_r001870_10_2, pub_r001870_11_2, pub_r001870_12_2, pub_r001870_13_2);
  fn_R001870_7013_9_2(sec_r001870_9_1, pub_r001870_10_1, pub_r001870_11_1, pub_r001870_12_1, pub_r001870_13_1, sec_r001870_9_2, pub_r001870_10_2, pub_r001870_11_2, pub_r001870_12_2, pub_r001870_13_2);
  int helper_flow_10_1 = fn_R001870_7013_10(sec_r001870_10_1, pub_r001870_11_1, pub_r001870_12_1, pub_r001870_13_1, pub_r001870_14_1);
  int helper_flow_10_2 = fn_R001870_7013_10(sec_r001870_10_2, pub_r001870_11_2, pub_r001870_12_2, pub_r001870_13_2, pub_r001870_14_2);
  fn_R001870_7013_10_2(sec_r001870_10_1, pub_r001870_11_1, pub_r001870_12_1, pub_r001870_13_1, pub_r001870_14_1, sec_r001870_10_2, pub_r001870_11_2, pub_r001870_12_2, pub_r001870_13_2, pub_r001870_14_2);
  int helper_flow_11_1 = fn_R001870_7013_11(sec_r001870_11_1, sec_r001870_12_1, pub_r001870_13_1);
  int helper_flow_11_2 = fn_R001870_7013_11(sec_r001870_11_2, sec_r001870_12_2, pub_r001870_13_2);
  fn_R001870_7013_11_2(sec_r001870_11_1, sec_r001870_12_1, pub_r001870_13_1, sec_r001870_11_2, sec_r001870_12_2, pub_r001870_13_2);
  int helper_flow_12_1 = fn_R001870_7013_12(sec_r001870_12_1, sec_r001870_13_1);
  int helper_flow_12_2 = fn_R001870_7013_12(sec_r001870_12_2, sec_r001870_13_2);
  fn_R001870_7013_12_2(sec_r001870_12_1, sec_r001870_13_1, sec_r001870_12_2, sec_r001870_13_2);
  int helper_flow_13_1 = fn_R001870_7013_13(sec_r001870_13_1, sec_r001870_14_1, pub_r001870_15_1, pub_r001870_16_1);
  int helper_flow_13_2 = fn_R001870_7013_13(sec_r001870_13_2, sec_r001870_14_2, pub_r001870_15_2, pub_r001870_16_2);
  fn_R001870_7013_13_2(sec_r001870_13_1, sec_r001870_14_1, pub_r001870_15_1, pub_r001870_16_1, sec_r001870_13_2, sec_r001870_14_2, pub_r001870_15_2, pub_r001870_16_2);
  int stage_v_0_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001870_6_1) & 127;
  int stage_v_0_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001870_6_2) & 127;
  if (stage_v_0_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((pub_r001870_0_1 * 2) + 9) & 63;
  int stage_v_1_2 = ((pub_r001870_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001870_1_1 ^ 0x2A) * 2) + pub_r001870_3_1) & 127;
  int stage_v_2_2 = (((sec_r001870_1_2 ^ 0x2A) * 2) + pub_r001870_3_2) & 127;
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
  int stage_v_3_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001870_2_1) & 127;
  int stage_v_3_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001870_2_2) & 127;
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
  int stage_v_4_1 = ((pub_r001870_3_1 * 2) + 26) & 63;
  int stage_v_4_2 = ((pub_r001870_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((sec_r001870_0_1 ^ 0x2A) * 2) + pub_r001870_5_1) & 127;
  int stage_v_5_2 = (((sec_r001870_0_2 ^ 0x2A) * 2) + pub_r001870_5_2) & 127;
  if (stage_v_5_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001870_9_1) & 127;
  int stage_v_6_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001870_9_2) & 127;
  if (stage_v_6_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((pub_r001870_19_1 * 2) + 24) & 63;
  int stage_v_7_2 = ((pub_r001870_19_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001870_11_1 ^ 0x2A) * 2) + pub_r001870_2_1) & 127;
  int stage_v_8_2 = (((sec_r001870_11_2 ^ 0x2A) * 2) + pub_r001870_2_2) & 127;
  if (stage_v_8_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((sec_r001870_13_1 ^ 0x2A) * 2) + pub_r001870_16_1) & 127;
  int stage_v_9_2 = (((sec_r001870_13_2 ^ 0x2A) * 2) + pub_r001870_16_2) & 127;
  if (stage_v_9_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = ((pub_r001870_3_1 * 2) + 8) & 63;
  int stage_v_10_2 = ((pub_r001870_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((sec_r001870_5_1 ^ 0x2A) * 2) + pub_r001870_6_1) & 127;
  int stage_v_11_2 = (((sec_r001870_5_2 ^ 0x2A) * 2) + pub_r001870_6_2) & 127;
  if (stage_v_11_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((pub_r001870_7_1 * 2) + 27) & 63;
  int stage_v_12_2 = ((pub_r001870_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((sec_r001870_14_1 ^ 0x2A) * 2) + pub_r001870_1_1) & 127;
  int stage_v_13_2 = (((sec_r001870_14_2 ^ 0x2A) * 2) + pub_r001870_1_2) & 127;
  if (stage_v_13_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((sec_r001870_6_1 ^ 0x2A) * 2) + pub_r001870_6_1) & 127;
  int stage_v_14_2 = (((sec_r001870_6_2 ^ 0x2A) * 2) + pub_r001870_6_2) & 127;
  if (stage_v_14_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001870_10_1) & 127;
  int stage_v_15_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001870_10_2) & 127;
  if (stage_v_15_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001870_17_1) & 127;
  int stage_v_16_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001870_17_2) & 127;
  if (stage_v_16_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((sec_r001870_11_1 ^ 0x2A) * 2) + pub_r001870_7_1) & 127;
  int stage_v_17_2 = (((sec_r001870_11_2 ^ 0x2A) * 2) + pub_r001870_7_2) & 127;
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
  int stage_v_18_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001870_7_1) & 127;
  int stage_v_18_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001870_7_2) & 127;
  if (stage_v_18_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001870_16_1) & 127;
  int stage_v_19_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001870_16_2) & 127;
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
  int stage_v_20_1 = ((pub_r001870_0_1 * 2) + 31) & 63;
  int stage_v_20_2 = ((pub_r001870_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001870_1_1) & 127;
  int stage_v_21_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001870_1_2) & 127;
  if (stage_v_21_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001870_16_1) & 127;
  int stage_v_22_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001870_16_2) & 127;
  if (stage_v_22_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((sec_r001870_15_1 ^ 0x2A) * 2) + pub_r001870_16_1) & 127;
  int stage_v_23_2 = (((sec_r001870_15_2 ^ 0x2A) * 2) + pub_r001870_16_2) & 127;
  if (stage_v_23_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001870_17_1) & 127;
  int stage_v_24_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001870_17_2) & 127;
  if (stage_v_24_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((pub_r001870_3_1 * 2) + 7) & 63;
  int stage_v_25_2 = ((pub_r001870_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((sec_r001870_5_1 ^ 0x2A) * 2) + pub_r001870_16_1) & 127;
  int stage_v_26_2 = (((sec_r001870_5_2 ^ 0x2A) * 2) + pub_r001870_16_2) & 127;
  if (stage_v_26_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001870_17_1) & 127;
  int stage_v_27_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001870_17_2) & 127;
  if (stage_v_27_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (((sec_r001870_9_1 ^ 0x2A) * 2) + pub_r001870_18_1) & 127;
  int stage_v_28_2 = (((sec_r001870_9_2 ^ 0x2A) * 2) + pub_r001870_18_2) & 127;
  if (stage_v_28_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001870_19_1) & 127;
  int stage_v_29_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001870_19_2) & 127;
  if (stage_v_29_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001870_2_1) & 127;
  int stage_v_30_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001870_2_2) & 127;
  if (stage_v_30_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001870_2_1) & 127;
  int stage_v_31_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001870_2_2) & 127;
  if (stage_v_31_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001870_12_1) & 127;
  int stage_v_32_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001870_12_2) & 127;
  if (stage_v_32_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((sec_r001870_1_1 ^ 0x2A) * 2) + pub_r001870_6_1) & 127;
  int stage_v_33_2 = (((sec_r001870_1_2 ^ 0x2A) * 2) + pub_r001870_6_2) & 127;
  if (stage_v_33_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = ((pub_r001870_19_1 * 2) + 38) & 63;
  int stage_v_34_2 = ((pub_r001870_19_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001870_18_1) & 127;
  int stage_v_35_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001870_18_2) & 127;
  if (stage_v_35_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001870_5_1) & 127;
  int stage_v_36_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001870_5_2) & 127;
  if (stage_v_36_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001870_2_1) & 127;
  int stage_v_37_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001870_2_2) & 127;
  if (stage_v_37_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001870_3_1) & 127;
  int stage_v_38_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001870_3_2) & 127;
  if (stage_v_38_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001870_2_1) & 127;
  int stage_v_39_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001870_2_2) & 127;
  if (stage_v_39_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001870_9_1) & 127;
  int stage_v_40_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001870_9_2) & 127;
  if (stage_v_40_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((sec_r001870_1_1 ^ 0x2A) * 2) + pub_r001870_17_1) & 127;
  int stage_v_41_2 = (((sec_r001870_1_2 ^ 0x2A) * 2) + pub_r001870_17_2) & 127;
  if (stage_v_41_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001870_19_1) & 127;
  int stage_v_42_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001870_19_2) & 127;
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
  int stage_v_43_1 = ((pub_r001870_1_1 * 2) + 36) & 63;
  int stage_v_43_2 = ((pub_r001870_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001870_8_1) & 127;
  int stage_v_44_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001870_8_2) & 127;
  if (stage_v_44_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001870_9_1) & 127;
  int stage_v_45_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001870_9_2) & 127;
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
  int stage_v_46_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001870_2_1) & 127;
  int stage_v_46_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001870_2_2) & 127;
  if (stage_v_46_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((pub_r001870_16_1 * 2) + 29) & 63;
  int stage_v_47_2 = ((pub_r001870_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (((stage_v_42_1 ^ 0x2A) * 2) + pub_r001870_17_1) & 127;
  int stage_v_48_2 = (((stage_v_42_2 ^ 0x2A) * 2) + pub_r001870_17_2) & 127;
  if (stage_v_48_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001870_8_1) & 127;
  int stage_v_49_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001870_8_2) & 127;
  if (stage_v_49_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001870_6_1) & 127;
  int stage_v_50_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001870_6_2) & 127;
  if (stage_v_50_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001870_12_1) & 127;
  int stage_v_51_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001870_12_2) & 127;
  if (stage_v_51_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (((sec_r001870_0_1 ^ 0x2A) * 2) + pub_r001870_6_1) & 127;
  int stage_v_52_2 = (((sec_r001870_0_2 ^ 0x2A) * 2) + pub_r001870_6_2) & 127;
  if (stage_v_52_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001870_19_1) & 127;
  int stage_v_53_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001870_19_2) & 127;
  if (stage_v_53_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((pub_r001870_18_1 * 2) + 49) & 63;
  int stage_v_54_2 = ((pub_r001870_18_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001870_1_1) & 127;
  int stage_v_55_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001870_1_2) & 127;
  if (stage_v_55_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001870_8_1) & 127;
  int stage_v_56_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001870_8_2) & 127;
  if (stage_v_56_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((pub_r001870_1_1 * 2) + 25) & 63;
  int stage_v_57_2 = ((pub_r001870_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001870_20_1 * 2) + 50) & 63;
  int stage_v_58_2 = ((pub_r001870_20_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001870_9_1) & 127;
  int stage_v_59_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001870_9_2) & 127;
  if (stage_v_59_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001870_20_1) & 127;
  int stage_v_60_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001870_20_2) & 127;
  if (stage_v_60_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001870_16_1) & 127;
  int stage_v_61_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001870_16_2) & 127;
  if (stage_v_61_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((pub_r001870_6_1 * 2) + 15) & 63;
  int stage_v_62_2 = ((pub_r001870_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001870_10_1) & 127;
  int stage_v_63_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001870_10_2) & 127;
  if (stage_v_63_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001870_3_1) & 127;
  int stage_v_64_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001870_3_2) & 127;
  if (stage_v_64_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001870_13_1) & 127;
  int stage_v_65_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001870_13_2) & 127;
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
  int stage_v_66_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001870_18_1) & 127;
  int stage_v_66_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001870_18_2) & 127;
  if (stage_v_66_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001870_2_1) & 127;
  int stage_v_67_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001870_2_2) & 127;
  if (stage_v_67_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((pub_r001870_18_1 * 2) + 38) & 63;
  int stage_v_68_2 = ((pub_r001870_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001870_10_1 * 2) + 8) & 63;
  int stage_v_69_2 = ((pub_r001870_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001870_8_1) & 127;
  int stage_v_70_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001870_8_2) & 127;
  if (stage_v_70_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((sec_r001870_6_1 ^ 0x2A) * 2) + pub_r001870_7_1) & 127;
  int stage_v_71_2 = (((sec_r001870_6_2 ^ 0x2A) * 2) + pub_r001870_7_2) & 127;
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
  int stage_v_72_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001870_8_1) & 127;
  int stage_v_72_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001870_8_2) & 127;
  if (stage_v_72_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((pub_r001870_7_1 * 2) + 9) & 63;
  int stage_v_73_2 = ((pub_r001870_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = (((sec_r001870_5_1 ^ 0x2A) * 2) + pub_r001870_12_1) & 127;
  int stage_v_74_2 = (((sec_r001870_5_2 ^ 0x2A) * 2) + pub_r001870_12_2) & 127;
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
  int stage_v_75_1 = ((pub_r001870_10_1 * 2) + 29) & 63;
  int stage_v_75_2 = ((pub_r001870_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001870_12_1) & 127;
  int stage_v_76_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001870_12_2) & 127;
  if (stage_v_76_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((pub_r001870_14_1 * 2) + 36) & 63;
  int stage_v_77_2 = ((pub_r001870_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001870_7_1) & 127;
  int stage_v_78_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001870_7_2) & 127;
  if (stage_v_78_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001870_2_1) & 127;
  int stage_v_79_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001870_2_2) & 127;
  if (stage_v_79_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((sec_r001870_0_1 ^ 0x2A) * 2) + pub_r001870_10_1) & 127;
  int stage_v_80_2 = (((sec_r001870_0_2 ^ 0x2A) * 2) + pub_r001870_10_2) & 127;
  if (stage_v_80_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001870_9_1) & 127;
  int stage_v_81_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001870_9_2) & 127;
  if (stage_v_81_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001870_0_1) & 127;
  int stage_v_82_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001870_0_2) & 127;
  if (stage_v_82_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((sec_r001870_4_1 ^ 0x2A) * 2) + pub_r001870_20_1) & 127;
  int stage_v_83_2 = (((sec_r001870_4_2 ^ 0x2A) * 2) + pub_r001870_20_2) & 127;
  if (stage_v_83_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((pub_r001870_20_1 * 2) + 31) & 63;
  int stage_v_84_2 = ((pub_r001870_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001870_18_1) & 127;
  int stage_v_85_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001870_18_2) & 127;
  if (stage_v_85_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001870_12_1) & 127;
  int stage_v_86_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001870_12_2) & 127;
  if (stage_v_86_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001870_17_1) & 127;
  int stage_v_87_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001870_17_2) & 127;
  if (stage_v_87_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001870_1_1) & 127;
  int stage_v_88_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001870_1_2) & 127;
  if (stage_v_88_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001870_1_1) & 127;
  int stage_v_89_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001870_1_2) & 127;
  if (stage_v_89_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((pub_r001870_14_1 * 2) + 31) & 63;
  int stage_v_90_2 = ((pub_r001870_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001870_16_1 * 2) + 25) & 63;
  int stage_v_91_2 = ((pub_r001870_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001870_2_1) & 127;
  int stage_v_92_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001870_2_2) & 127;
  if (stage_v_92_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((pub_r001870_10_1 * 2) + 7) & 63;
  int stage_v_93_2 = ((pub_r001870_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001870_20_1) & 127;
  int stage_v_94_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001870_20_2) & 127;
  if (stage_v_94_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((pub_r001870_15_1 * 2) + 8) & 63;
  int stage_v_95_2 = ((pub_r001870_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001870_10_1) & 127;
  int stage_v_96_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001870_10_2) & 127;
  if (stage_v_96_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((pub_r001870_20_1 * 2) + 6) & 63;
  int stage_v_97_2 = ((pub_r001870_20_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001870_1_1) & 127;
  int stage_v_98_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001870_1_2) & 127;
  if (stage_v_98_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001870_7_1) & 127;
  int stage_v_99_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001870_7_2) & 127;
  if (stage_v_99_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001870_4_1) & 127;
  int stage_v_100_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001870_4_2) & 127;
  if (stage_v_100_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001870_6_1) & 127;
  int stage_v_101_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001870_6_2) & 127;
  if (stage_v_101_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001870_0_1) & 127;
  int stage_v_102_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001870_0_2) & 127;
  if (stage_v_102_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001870_17_1) & 127;
  int stage_v_103_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001870_17_2) & 127;
  if (stage_v_103_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((sec_r001870_6_1 ^ 0x2A) * 2) + pub_r001870_0_1) & 127;
  int stage_v_104_2 = (((sec_r001870_6_2 ^ 0x2A) * 2) + pub_r001870_0_2) & 127;
  if (stage_v_104_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((pub_r001870_14_1 * 2) + 8) & 63;
  int stage_v_105_2 = ((pub_r001870_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001870_13_1) & 127;
  int stage_v_106_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001870_13_2) & 127;
  if (stage_v_106_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((pub_r001870_16_1 * 2) + 26) & 63;
  int stage_v_107_2 = ((pub_r001870_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001870_6_1) & 127;
  int stage_v_108_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001870_6_2) & 127;
  if (stage_v_108_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001870_18_1) & 127;
  int stage_v_109_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001870_18_2) & 127;
  if (stage_v_109_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((pub_r001870_1_1 * 2) + 7) & 63;
  int stage_v_110_2 = ((pub_r001870_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (((stage_v_67_1 ^ 0x2A) * 2) + pub_r001870_16_1) & 127;
  int stage_v_111_2 = (((stage_v_67_2 ^ 0x2A) * 2) + pub_r001870_16_2) & 127;
  if (stage_v_111_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001870_13_1) & 127;
  int stage_v_112_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001870_13_2) & 127;
  if (stage_v_112_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((pub_r001870_19_1 * 2) + 30) & 63;
  int stage_v_113_2 = ((pub_r001870_19_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((sec_r001870_3_1 ^ 0x2A) * 2) + pub_r001870_16_1) & 127;
  int stage_v_114_2 = (((sec_r001870_3_2 ^ 0x2A) * 2) + pub_r001870_16_2) & 127;
  if (stage_v_114_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = (((stage_v_72_1 ^ 0x2A) * 2) + pub_r001870_9_1) & 127;
  int stage_v_115_2 = (((stage_v_72_2 ^ 0x2A) * 2) + pub_r001870_9_2) & 127;
  if (stage_v_115_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001870_17_1) & 127;
  int stage_v_116_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001870_17_2) & 127;
  if (stage_v_116_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((pub_r001870_18_1 * 2) + 45) & 63;
  int stage_v_117_2 = ((pub_r001870_18_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001870_0_1 * 2) + 27) & 63;
  int stage_v_118_2 = ((pub_r001870_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((sec_r001870_4_1 ^ 0x2A) * 2) + pub_r001870_5_1) & 127;
  int stage_v_119_2 = (((sec_r001870_4_2 ^ 0x2A) * 2) + pub_r001870_5_2) & 127;
  if (stage_v_119_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001870_19_1) & 127;
  int stage_v_120_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001870_19_2) & 127;
  if (stage_v_120_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((pub_r001870_5_1 * 2) + 39) & 63;
  int stage_v_121_2 = ((pub_r001870_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001870_5_1) & 127;
  int stage_v_122_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001870_5_2) & 127;
  if (stage_v_122_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001870_9_1) & 127;
  int stage_v_123_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001870_9_2) & 127;
  if (stage_v_123_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((pub_r001870_17_1 * 2) + 14) & 63;
  int stage_v_124_2 = ((pub_r001870_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (((stage_v_116_1 ^ 0x2A) * 2) + pub_r001870_18_1) & 127;
  int stage_v_125_2 = (((stage_v_116_2 ^ 0x2A) * 2) + pub_r001870_18_2) & 127;
  if (stage_v_125_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((pub_r001870_20_1 * 2) + 15) & 63;
  int stage_v_126_2 = ((pub_r001870_20_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001870_18_1 * 2) + 38) & 63;
  int stage_v_127_2 = ((pub_r001870_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001870_17_1 * 2) + 47) & 63;
  int stage_v_128_2 = ((pub_r001870_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001870_19_1) & 127;
  int stage_v_129_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001870_19_2) & 127;
  if (stage_v_129_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((pub_r001870_13_1 * 2) + 9) & 63;
  int stage_v_130_2 = ((pub_r001870_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001870_5_1) & 127;
  int stage_v_131_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001870_5_2) & 127;
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
  int stage_v_132_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001870_6_1) & 127;
  int stage_v_132_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001870_6_2) & 127;
  if (stage_v_132_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((stage_v_129_1 ^ 0x2A) * 2) + pub_r001870_16_1) & 127;
  int stage_v_133_2 = (((stage_v_129_2 ^ 0x2A) * 2) + pub_r001870_16_2) & 127;
  if (stage_v_133_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001870_17_1) & 127;
  int stage_v_134_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001870_17_2) & 127;
  if (stage_v_134_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((pub_r001870_15_1 * 2) + 42) & 63;
  int stage_v_135_2 = ((pub_r001870_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001870_6_1) & 127;
  int stage_v_136_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001870_6_2) & 127;
  if (stage_v_136_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001870_6_1) & 127;
  int stage_v_137_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001870_6_2) & 127;
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
  int stage_v_138_1 = ((pub_r001870_3_1 * 2) + 10) & 63;
  int stage_v_138_2 = ((pub_r001870_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001870_10_1) & 127;
  int stage_v_139_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001870_10_2) & 127;
  if (stage_v_139_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((sec_r001870_6_1 ^ 0x2A) * 2) + pub_r001870_0_1) & 127;
  int stage_v_140_2 = (((sec_r001870_6_2 ^ 0x2A) * 2) + pub_r001870_0_2) & 127;
  if (stage_v_140_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001870_0_1) & 127;
  int stage_v_141_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001870_0_2) & 127;
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
  int stage_v_142_1 = (((stage_v_125_1 ^ 0x2A) * 2) + pub_r001870_8_1) & 127;
  int stage_v_142_2 = (((stage_v_125_2 ^ 0x2A) * 2) + pub_r001870_8_2) & 127;
  if (stage_v_142_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001870_8_1) & 127;
  int stage_v_143_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001870_8_2) & 127;
  if (stage_v_143_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_67_1 ^ 0x2A) * 2) + pub_r001870_16_1) & 127;
  int stage_v_144_2 = (((stage_v_67_2 ^ 0x2A) * 2) + pub_r001870_16_2) & 127;
  if (stage_v_144_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((pub_r001870_15_1 * 2) + 26) & 63;
  int stage_v_145_2 = ((pub_r001870_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001870_17_1) & 127;
  int stage_v_146_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001870_17_2) & 127;
  if (stage_v_146_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (((stage_v_104_1 ^ 0x2A) * 2) + pub_r001870_11_1) & 127;
  int stage_v_147_2 = (((stage_v_104_2 ^ 0x2A) * 2) + pub_r001870_11_2) & 127;
  if (stage_v_147_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001870_18_1) & 127;
  int stage_v_148_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001870_18_2) & 127;
  if (stage_v_148_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((pub_r001870_17_1 * 2) + 26) & 63;
  int stage_v_149_2 = ((pub_r001870_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001870_5_1) & 127;
  int stage_v_150_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001870_5_2) & 127;
  if (stage_v_150_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((pub_r001870_13_1 * 2) + 42) & 63;
  int stage_v_151_2 = ((pub_r001870_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001870_5_1) & 127;
  int stage_v_152_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001870_5_2) & 127;
  if (stage_v_152_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((pub_r001870_11_1 * 2) + 43) & 63;
  int stage_v_153_2 = ((pub_r001870_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001870_17_1 * 2) + 15) & 63;
  int stage_v_154_2 = ((pub_r001870_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001870_15_1) & 127;
  int stage_v_155_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001870_15_2) & 127;
  if (stage_v_155_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((sec_r001870_1_1 ^ 0x2A) * 2) + pub_r001870_1_1) & 127;
  int stage_v_156_2 = (((sec_r001870_1_2 ^ 0x2A) * 2) + pub_r001870_1_2) & 127;
  if (stage_v_156_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001870_4_1) & 127;
  int stage_v_157_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001870_4_2) & 127;
  if (stage_v_157_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001870_0_1) & 127;
  int stage_v_158_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001870_0_2) & 127;
  if (stage_v_158_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((pub_r001870_14_1 * 2) + 50) & 63;
  int stage_v_159_2 = ((pub_r001870_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001870_15_1 * 2) + 46) & 63;
  int stage_v_160_2 = ((pub_r001870_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001870_16_1) & 127;
  int stage_v_161_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001870_16_2) & 127;
  if (stage_v_161_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001870_2_1) & 127;
  int stage_v_162_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001870_2_2) & 127;
  if (stage_v_162_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001870_8_1) & 127;
  int stage_v_163_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001870_8_2) & 127;
  if (stage_v_163_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((pub_r001870_8_1 * 2) + 22) & 63;
  int stage_v_164_2 = ((pub_r001870_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_150_1 ^ 0x2A) * 2) + pub_r001870_20_1) & 127;
  int stage_v_165_2 = (((stage_v_150_2 ^ 0x2A) * 2) + pub_r001870_20_2) & 127;
  if (stage_v_165_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((pub_r001870_16_1 * 2) + 34) & 63;
  int stage_v_166_2 = ((pub_r001870_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001870_8_1) & 127;
  int stage_v_167_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001870_8_2) & 127;
  if (stage_v_167_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_141_1 ^ 0x2A) * 2) + pub_r001870_8_1) & 127;
  int stage_v_168_2 = (((stage_v_141_2 ^ 0x2A) * 2) + pub_r001870_8_2) & 127;
  if (stage_v_168_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001870_7_1) & 127;
  int stage_v_169_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001870_7_2) & 127;
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
  int stage_v_170_1 = ((pub_r001870_1_1 * 2) + 9) & 63;
  int stage_v_170_2 = ((pub_r001870_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001870_13_1 * 2) + 15) & 63;
  int stage_v_171_2 = ((pub_r001870_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001870_4_1 * 2) + 29) & 63;
  int stage_v_172_2 = ((pub_r001870_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (((sec_r001870_13_1 ^ 0x2A) * 2) + pub_r001870_2_1) & 127;
  int stage_v_173_2 = (((sec_r001870_13_2 ^ 0x2A) * 2) + pub_r001870_2_2) & 127;
  if (stage_v_173_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001870_9_1) & 127;
  int stage_v_174_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001870_9_2) & 127;
  if (stage_v_174_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001870_17_1) & 127;
  int stage_v_175_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001870_17_2) & 127;
  if (stage_v_175_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = (((stage_v_122_1 ^ 0x2A) * 2) + pub_r001870_15_1) & 127;
  int stage_v_176_2 = (((stage_v_122_2 ^ 0x2A) * 2) + pub_r001870_15_2) & 127;
  if (stage_v_176_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = (((stage_v_147_1 ^ 0x2A) * 2) + pub_r001870_16_1) & 127;
  int stage_v_177_2 = (((stage_v_147_2 ^ 0x2A) * 2) + pub_r001870_16_2) & 127;
  if (stage_v_177_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001870_16_1) & 127;
  int stage_v_178_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001870_16_2) & 127;
  if (stage_v_178_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((stage_v_161_1 ^ 0x2A) * 2) + pub_r001870_10_1) & 127;
  int stage_v_179_2 = (((stage_v_161_2 ^ 0x2A) * 2) + pub_r001870_10_2) & 127;
  if (stage_v_179_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((pub_r001870_6_1 * 2) + 8) & 63;
  int stage_v_180_2 = ((pub_r001870_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001870_17_1) & 127;
  int stage_v_181_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001870_17_2) & 127;
  if (stage_v_181_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((pub_r001870_19_1 * 2) + 31) & 63;
  int stage_v_182_2 = ((pub_r001870_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001870_14_1) & 127;
  int stage_v_183_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001870_14_2) & 127;
  if (stage_v_183_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = (((sec_r001870_0_1 ^ 0x2A) * 2) + pub_r001870_13_1) & 127;
  int stage_v_184_2 = (((sec_r001870_0_2 ^ 0x2A) * 2) + pub_r001870_13_2) & 127;
  if (stage_v_184_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001870_11_1) & 127;
  int stage_v_185_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001870_11_2) & 127;
  if (stage_v_185_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001870_17_1) & 127;
  int stage_v_186_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001870_17_2) & 127;
  if (stage_v_186_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((pub_r001870_9_1 * 2) + 29) & 63;
  int stage_v_187_2 = ((pub_r001870_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((stage_v_109_1 ^ 0x2A) * 2) + pub_r001870_6_1) & 127;
  int stage_v_188_2 = (((stage_v_109_2 ^ 0x2A) * 2) + pub_r001870_6_2) & 127;
  if (stage_v_188_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((pub_r001870_6_1 * 2) + 46) & 63;
  int stage_v_189_2 = ((pub_r001870_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((sec_r001870_2_1 ^ 0x2A) * 2) + pub_r001870_20_1) & 127;
  int stage_v_190_2 = (((sec_r001870_2_2 ^ 0x2A) * 2) + pub_r001870_20_2) & 127;
  if (stage_v_190_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001870_16_1) & 127;
  int stage_v_191_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001870_16_2) & 127;
  if (stage_v_191_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001870_20_1) & 127;
  int stage_v_192_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001870_20_2) & 127;
  if (stage_v_192_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((pub_r001870_18_1 * 2) + 8) & 63;
  int stage_v_193_2 = ((pub_r001870_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001870_13_1) & 127;
  int stage_v_194_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001870_13_2) & 127;
  if (stage_v_194_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001870_5_1) & 127;
  int stage_v_195_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001870_5_2) & 127;
  if (stage_v_195_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((pub_r001870_2_1 * 2) + 32) & 63;
  int stage_v_196_2 = ((pub_r001870_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((stage_v_192_1 ^ 0x2A) * 2) + pub_r001870_6_1) & 127;
  int stage_v_197_2 = (((stage_v_192_2 ^ 0x2A) * 2) + pub_r001870_6_2) & 127;
  if (stage_v_197_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = (((stage_v_178_1 ^ 0x2A) * 2) + pub_r001870_13_1) & 127;
  int stage_v_198_2 = (((stage_v_178_2 ^ 0x2A) * 2) + pub_r001870_13_2) & 127;
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
  int stage_v_199_1 = ((pub_r001870_4_1 * 2) + 10) & 63;
  int stage_v_199_2 = ((pub_r001870_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001870_5_1 * 2) + 42) & 63;
  int stage_v_200_2 = ((pub_r001870_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001870_18_1) & 127;
  int stage_v_201_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001870_18_2) & 127;
  if (stage_v_201_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001870_0_1) & 127;
  int stage_v_202_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001870_0_2) & 127;
  if (stage_v_202_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001870_19_1) & 127;
  int stage_v_203_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001870_19_2) & 127;
  if (stage_v_203_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((pub_r001870_13_1 * 2) + 29) & 63;
  int stage_v_204_2 = ((pub_r001870_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((sec_r001870_15_1 ^ 0x2A) * 2) + pub_r001870_7_1) & 127;
  int stage_v_205_2 = (((sec_r001870_15_2 ^ 0x2A) * 2) + pub_r001870_7_2) & 127;
  if (stage_v_205_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = (((stage_v_33_1 ^ 0x2A) * 2) + pub_r001870_0_1) & 127;
  int stage_v_206_2 = (((stage_v_33_2 ^ 0x2A) * 2) + pub_r001870_0_2) & 127;
  if (stage_v_206_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001870_16_1) & 127;
  int stage_v_207_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001870_16_2) & 127;
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
  int stage_v_208_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001870_14_1) & 127;
  int stage_v_208_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001870_14_2) & 127;
  if (stage_v_208_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001870_18_1) & 127;
  int stage_v_209_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001870_18_2) & 127;
  if (stage_v_209_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((pub_r001870_1_1 * 2) + 40) & 63;
  int stage_v_210_2 = ((pub_r001870_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001870_4_1) & 127;
  int stage_v_211_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001870_4_2) & 127;
  if (stage_v_211_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((pub_r001870_17_1 * 2) + 26) & 63;
  int stage_v_212_2 = ((pub_r001870_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001870_8_1) & 127;
  int stage_v_213_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001870_8_2) & 127;
  if (stage_v_213_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((pub_r001870_12_1 * 2) + 37) & 63;
  int stage_v_214_2 = ((pub_r001870_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001870_1_1) & 127;
  int stage_v_215_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001870_1_2) & 127;
  if (stage_v_215_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001870_8_1) & 127;
  int stage_v_216_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001870_8_2) & 127;
  if (stage_v_216_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001870_0_1) & 127;
  int stage_v_217_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001870_0_2) & 127;
  if (stage_v_217_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((pub_r001870_13_1 * 2) + 50) & 63;
  int stage_v_218_2 = ((pub_r001870_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((stage_v_162_1 ^ 0x2A) * 2) + pub_r001870_10_1) & 127;
  int stage_v_219_2 = (((stage_v_162_2 ^ 0x2A) * 2) + pub_r001870_10_2) & 127;
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
  int stage_v_220_1 = ((pub_r001870_13_1 * 2) + 13) & 63;
  int stage_v_220_2 = ((pub_r001870_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = (((stage_v_167_1 ^ 0x2A) * 2) + pub_r001870_11_1) & 127;
  int stage_v_221_2 = (((stage_v_167_2 ^ 0x2A) * 2) + pub_r001870_11_2) & 127;
  if (stage_v_221_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = (((sec_r001870_1_1 ^ 0x2A) * 2) + pub_r001870_18_1) & 127;
  int stage_v_222_2 = (((sec_r001870_1_2 ^ 0x2A) * 2) + pub_r001870_18_2) & 127;
  if (stage_v_222_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = (((stage_v_147_1 ^ 0x2A) * 2) + pub_r001870_11_1) & 127;
  int stage_v_223_2 = (((stage_v_147_2 ^ 0x2A) * 2) + pub_r001870_11_2) & 127;
  if (stage_v_223_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001870_5_1) & 127;
  int stage_v_224_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001870_5_2) & 127;
  if (stage_v_224_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
  }
  if (stage_v_224_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001870_19_1) & 127;
  int stage_v_225_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001870_19_2) & 127;
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
  int stage_v_226_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001870_13_1) & 127;
  int stage_v_226_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001870_13_2) & 127;
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
  int stage_v_227_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001870_2_1) & 127;
  int stage_v_227_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001870_2_2) & 127;
  if (stage_v_227_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
  }
  if (stage_v_227_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001870_0_1) & 127;
  int stage_v_228_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001870_0_2) & 127;
  if (stage_v_228_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001870_5_1) & 127;
  int stage_v_229_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001870_5_2) & 127;
  if (stage_v_229_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
  }
  if (stage_v_229_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((pub_r001870_0_1 * 2) + 16) & 63;
  int stage_v_230_2 = ((pub_r001870_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001870_16_1 * 2) + 16) & 63;
  int stage_v_231_2 = ((pub_r001870_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001870_10_1 * 2) + 49) & 63;
  int stage_v_232_2 = ((pub_r001870_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001870_19_1) & 127;
  int stage_v_233_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001870_19_2) & 127;
  if (stage_v_233_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
  }
  if (stage_v_233_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = (((stage_v_183_1 ^ 0x2A) * 2) + pub_r001870_13_1) & 127;
  int stage_v_234_2 = (((stage_v_183_2 ^ 0x2A) * 2) + pub_r001870_13_2) & 127;
  if (stage_v_234_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
  }
  if (stage_v_234_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((pub_r001870_10_1 * 2) + 12) & 63;
  int stage_v_235_2 = ((pub_r001870_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001870_0_1 * 2) + 36) & 63;
  int stage_v_236_2 = ((pub_r001870_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001870_19_1) & 127;
  int stage_v_237_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001870_19_2) & 127;
  if (stage_v_237_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
  }
  if (stage_v_237_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((pub_r001870_6_1 * 2) + 50) & 63;
  int stage_v_238_2 = ((pub_r001870_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = (((stage_v_152_1 ^ 0x2A) * 2) + pub_r001870_20_1) & 127;
  int stage_v_239_2 = (((stage_v_152_2 ^ 0x2A) * 2) + pub_r001870_20_2) & 127;
  if (stage_v_239_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
  }
  if (stage_v_239_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = (((stage_v_112_1 ^ 0x2A) * 2) + pub_r001870_13_1) & 127;
  int stage_v_240_2 = (((stage_v_112_2 ^ 0x2A) * 2) + pub_r001870_13_2) & 127;
  if (stage_v_240_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
  }
  if (stage_v_240_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((pub_r001870_12_1 * 2) + 43) & 63;
  int stage_v_241_2 = ((pub_r001870_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001870_9_1) & 127;
  int stage_v_242_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001870_9_2) & 127;
  if (stage_v_242_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
  }
  if (stage_v_242_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((pub_r001870_2_1 * 2) + 25) & 63;
  int stage_v_243_2 = ((pub_r001870_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001870_20_1) & 127;
  int stage_v_244_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001870_20_2) & 127;
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
  int stage_v_245_1 = ((pub_r001870_17_1 * 2) + 16) & 63;
  int stage_v_245_2 = ((pub_r001870_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001870_8_1) & 127;
  int stage_v_246_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001870_8_2) & 127;
  if (stage_v_246_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
  }
  if (stage_v_246_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001870_12_1 == pub_r001870_12_2);
  __CPROVER_assume(sec_r001870_10_1 != sec_r001870_10_2);
  __CPROVER_assume(pub_r001870_8_1 == pub_r001870_8_2);
  __CPROVER_assume(sec_r001870_1_1 != sec_r001870_1_2);
  __CPROVER_assume(sec_r001870_8_1 != sec_r001870_8_2);
  __CPROVER_assume(pub_r001870_9_1 == pub_r001870_9_2);
  __CPROVER_assume(pub_r001870_16_1 == pub_r001870_16_2);
  __CPROVER_assume(pub_r001870_19_1 == pub_r001870_19_2);
  __CPROVER_assume(sec_r001870_2_1 != sec_r001870_2_2);
  __CPROVER_assume(pub_r001870_7_1 == pub_r001870_7_2);
  __CPROVER_assume(pub_r001870_15_1 == pub_r001870_15_2);
  __CPROVER_assume(sec_r001870_13_1 != sec_r001870_13_2);
  __CPROVER_assume(sec_r001870_14_1 != sec_r001870_14_2);
  __CPROVER_assume(pub_r001870_5_1 == pub_r001870_5_2);
  __CPROVER_assume(pub_r001870_6_1 == pub_r001870_6_2);
  __CPROVER_assume(pub_r001870_0_1 == pub_r001870_0_2);
  __CPROVER_assume(pub_r001870_2_1 == pub_r001870_2_2);
  __CPROVER_assume(sec_r001870_7_1 != sec_r001870_7_2);
  __CPROVER_assume(sec_r001870_6_1 != sec_r001870_6_2);
  __CPROVER_assume(sec_r001870_11_1 != sec_r001870_11_2);
  __CPROVER_assume(sec_r001870_15_1 != sec_r001870_15_2);
  __CPROVER_assume(pub_r001870_18_1 == pub_r001870_18_2);
  __CPROVER_assume(pub_r001870_20_1 == pub_r001870_20_2);
  __CPROVER_assume(sec_r001870_0_1 != sec_r001870_0_2);
  __CPROVER_assume(pub_r001870_11_1 == pub_r001870_11_2);
  __CPROVER_assume(pub_r001870_3_1 == pub_r001870_3_2);
  __CPROVER_assume(pub_r001870_17_1 == pub_r001870_17_2);
  __CPROVER_assume(sec_r001870_12_1 != sec_r001870_12_2);
  __CPROVER_assume(pub_r001870_13_1 == pub_r001870_13_2);
  __CPROVER_assume(sec_r001870_3_1 != sec_r001870_3_2);
  __CPROVER_assume(sec_r001870_5_1 != sec_r001870_5_2);
  __CPROVER_assume(pub_r001870_10_1 == pub_r001870_10_2);
  __CPROVER_assume(sec_r001870_4_1 != sec_r001870_4_2);
  __CPROVER_assume(pub_r001870_4_1 == pub_r001870_4_2);
  __CPROVER_assume(pub_r001870_14_1 == pub_r001870_14_2);
  __CPROVER_assume(pub_r001870_1_1 == pub_r001870_1_2);
  __CPROVER_assume(sec_r001870_9_1 != sec_r001870_9_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.flags == st_var_1_2.flags);
  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.iv == st_var_1_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.prev_in == st_var_2_2.prev_in);
  assert(st_var_2_1.prev_out == st_var_2_2.prev_out);
  assert(st_var_2_1.damping == st_var_2_2.damping);
  assert(st_var_2_1.cutoff == st_var_2_2.cutoff);
  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
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
}


