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
struct DeviceConfig_R000212_1213_0
{
  unsigned char id;
  unsigned char baud_rate;
  int timeout;
  unsigned char stop_bits;
  short parity;
  int port;
  int buffer[3];
};
struct FilterState_R000212_1213_1
{
  unsigned char damping;
  int gain_db;
  short cutoff;
  int prev_out;
  int prev_in;
  int buffer[3];
};
struct Transaction_R000212_1213_2
{
  short auth_code;
  int rate;
  unsigned char balance;
  int account_id;
  unsigned char fee;
  int buffer[3];
};
struct CipherContext_R000212_1213_3
{
  int nonce;
  int flags;
  short round_key;
  short iv;
  unsigned char counter;
  int tag;
  int buffer[3];
};
union ColorPixel_R000212_1213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000212_1213_1
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
void fn_R000212_1213_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000212_1213_0 st_1 = {0};
  struct DeviceConfig_R000212_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int scale_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_71_1 > 11)
  {
    acc_1 = ((acc_1 + (scale_71_1 * 2)) + 5) & 127;
    aux_1 ^= scale_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_71_2 > 11)
  {
    acc_2 = ((acc_2 + (scale_71_2 * 2)) + 5) & 127;
    aux_2 ^= scale_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_71_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_16_1) & 63;
  aux_2 = (aux_2 + damping_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_71_1 == scale_71_2);
  assert(damping_16_1 == damping_16_2);
}

int fn_R000212_1213_0(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000212_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int scale_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_71 > 11)
  {
    acc = ((acc + (scale_71 * 2)) + 5) & 127;
    aux ^= scale_71 & 15;
  }
  else
  {
    acc = ((acc - scale_71) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000212_1213_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000212_1213_3 st_1 = {0};
  struct CipherContext_R000212_1213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int threshold_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_83_1) & 63;
  aux_2 = (aux_2 + threshold_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_96_1 > 25)
  {
    acc_1 = ((acc_1 + (sample_96_1 * 2)) + 5) & 127;
    aux_1 ^= sample_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_96_2 > 25)
  {
    acc_2 = ((acc_2 + (sample_96_2 * 2)) + 5) & 127;
    aux_2 ^= sample_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_10_1)
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

  switch (index_reg_10_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_83_1 == threshold_83_2);
  assert(sample_96_1 == sample_96_2);
  assert(index_reg_10_1 == index_reg_10_2);
}

int fn_R000212_1213_1(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000212_1213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int threshold_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_83) & 63;
  acc ^= aux;
  int sample_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_96 > 25)
  {
    acc = ((acc + (sample_96 * 2)) + 5) & 127;
    aux ^= sample_96 & 15;
  }
  else
  {
    acc = ((acc - sample_96) + 11) & 127;
    aux += 3;
  }
  int index_reg_10 = (aux + st.buffer[1]) & 3;
  switch (index_reg_10)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000212_1213_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000212_1213_0 st_1 = {0};
  struct DeviceConfig_R000212_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int anchor_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_79_1)
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

  switch (anchor_79_2)
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
  int coefficient_22_1 = local_arr_1[aux_1 % 3];
  int coefficient_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_22_2 * 2)) & 127;
  int accumulator_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_92_1) & 63;
  aux_2 = (aux_2 + accumulator_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_47_1 > 39)
  {
    acc_1 = ((acc_1 + (coefficient_47_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_47_2 > 39)
  {
    acc_2 = ((acc_2 + (coefficient_47_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_47_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_79_1 == anchor_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_22_1 == coefficient_22_2);
  assert(accumulator_92_1 == accumulator_92_2);
  assert(coefficient_47_1 == coefficient_47_2);
}

int fn_R000212_1213_2(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000212_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int anchor_79 = (aux + st.buffer[1]) & 3;
  switch (anchor_79)
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
  int coefficient_22 = local_arr[aux % 3];
  acc = (acc + (coefficient_22 * 2)) & 127;
  int accumulator_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_92) & 63;
  acc ^= aux;
  int coefficient_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_47 > 39)
  {
    acc = ((acc + (coefficient_47 * 2)) + 5) & 127;
    aux ^= coefficient_47 & 15;
  }
  else
  {
    acc = ((acc - coefficient_47) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000212_1213_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000212_1213_1 st_1 = {0};
  struct FilterState_R000212_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int threshold_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_15_1)
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

  switch (threshold_15_2)
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
  int tally_26_1 = local_arr_1[aux_1 % 3];
  int tally_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_26_2 * 2)) & 127;
  int pivot_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_22_1 > 34)
  {
    acc_1 = ((acc_1 + (pivot_22_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_22_2 > 34)
  {
    acc_2 = ((acc_2 + (pivot_22_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_14_1) & 63;
  aux_2 = (aux_2 + damping_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_15_1 == threshold_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_26_1 == tally_26_2);
  assert(pivot_22_1 == pivot_22_2);
  assert(damping_14_1 == damping_14_2);
}

int fn_R000212_1213_3(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000212_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int threshold_15 = (aux + st.buffer[1]) & 3;
  switch (threshold_15)
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
  int tally_26 = local_arr[aux % 3];
  acc = (acc + (tally_26 * 2)) & 127;
  int pivot_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_22 > 34)
  {
    acc = ((acc + (pivot_22 * 2)) + 5) & 127;
    aux ^= pivot_22 & 15;
  }
  else
  {
    acc = ((acc - pivot_22) + 11) & 127;
    aux += 3;
  }
  int damping_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_14) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000212_1213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st_1 = {0};
  struct Transaction_R000212_1213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_91_1) & 63;
  aux_2 = (aux_2 + sample_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_91_1 == sample_91_2);
}

int fn_R000212_1213_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_91) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000212_1213_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000212_1213_3 st_1 = {0};
  struct CipherContext_R000212_1213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quotient_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_35_1) & 63;
  aux_2 = (aux_2 + quotient_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_52_1 > 22)
  {
    acc_1 = ((acc_1 + (tracker_52_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_52_2 > 22)
  {
    acc_2 = ((acc_2 + (tracker_52_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_88_1 = local_arr_1[aux_1 % 3];
  int bound_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_88_2 * 2)) & 127;
  int residue_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_68_1)
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

  switch (residue_68_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_35_1 == quotient_35_2);
  assert(tracker_52_1 == tracker_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_88_1 == bound_88_2);
  assert(residue_68_1 == residue_68_2);
}

int fn_R000212_1213_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000212_1213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quotient_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_35) & 63;
  acc ^= aux;
  int tracker_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_52 > 22)
  {
    acc = ((acc + (tracker_52 * 2)) + 5) & 127;
    aux ^= tracker_52 & 15;
  }
  else
  {
    acc = ((acc - tracker_52) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_88 = local_arr[aux % 3];
  acc = (acc + (bound_88 * 2)) & 127;
  int residue_68 = (aux + st.buffer[1]) & 3;
  switch (residue_68)
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

void fn_R000212_1213_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st_1 = {0};
  struct Transaction_R000212_1213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int accumulator_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_38_1 > 44)
  {
    acc_1 = ((acc_1 + (accumulator_38_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_38_2 > 44)
  {
    acc_2 = ((acc_2 + (accumulator_38_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_38_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_84_1 = local_arr_1[aux_1 % 3];
  int delta_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_84_2 * 2)) & 127;
  int weight_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_22_1)
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

  switch (weight_22_2)
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
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_38_1 == accumulator_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_84_1 == delta_84_2);
  assert(weight_22_1 == weight_22_2);
}

int fn_R000212_1213_6(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int accumulator_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_38 > 44)
  {
    acc = ((acc + (accumulator_38 * 2)) + 5) & 127;
    aux ^= accumulator_38 & 15;
  }
  else
  {
    acc = ((acc - accumulator_38) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_84 = local_arr[aux % 3];
  acc = (acc + (delta_84 * 2)) & 127;
  int weight_22 = (aux + st.buffer[1]) & 3;
  switch (weight_22)
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

void fn_R000212_1213_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000212_1213_0 st_1 = {0};
  struct DeviceConfig_R000212_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int window_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_43_1) & 63;
  aux_2 = (aux_2 + window_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_44_1 = local_arr_1[aux_1 % 3];
  int quotient_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_44_2 * 2)) & 127;
  int window_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_95_1 > 49)
  {
    acc_1 = ((acc_1 + (window_95_1 * 2)) + 5) & 127;
    aux_1 ^= window_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_95_2 > 49)
  {
    acc_2 = ((acc_2 + (window_95_2 * 2)) + 5) & 127;
    aux_2 ^= window_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_95_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_43_1 == window_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_44_1 == quotient_44_2);
  assert(window_95_1 == window_95_2);
}

int fn_R000212_1213_7(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000212_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int window_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_43) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_44 = local_arr[aux % 3];
  acc = (acc + (quotient_44 * 2)) & 127;
  int window_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_95 > 49)
  {
    acc = ((acc + (window_95 * 2)) + 5) & 127;
    aux ^= window_95 & 15;
  }
  else
  {
    acc = ((acc - window_95) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000212_1213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000212_1213_3 st_1 = {0};
  struct CipherContext_R000212_1213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int pivot_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_14_1)
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

  switch (pivot_14_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_14_1 == pivot_14_2);
}

int fn_R000212_1213_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000212_1213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int pivot_14 = (aux + st.buffer[1]) & 3;
  switch (pivot_14)
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

void fn_R000212_1213_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st_1 = {0};
  struct Transaction_R000212_1213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int sample_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_80_1) & 63;
  aux_2 = (aux_2 + sample_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_51_1 = local_arr_1[aux_1 % 3];
  int quantum_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_51_2 * 2)) & 127;
  int phase_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_30_1)
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

  switch (phase_30_2)
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

  int index_reg_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_97_1 > 20)
  {
    acc_1 = ((acc_1 + (index_reg_97_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_97_2 > 20)
  {
    acc_2 = ((acc_2 + (index_reg_97_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_80_1 == sample_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_51_1 == quantum_51_2);
  assert(phase_30_1 == phase_30_2);
  assert(index_reg_97_1 == index_reg_97_2);
}

int fn_R000212_1213_9(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int sample_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_80) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quantum_51 = local_arr[aux % 3];
  acc = (acc + (quantum_51 * 2)) & 127;
  int phase_30 = (aux + st.buffer[1]) & 3;
  switch (phase_30)
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

  int index_reg_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_97 > 20)
  {
    acc = ((acc + (index_reg_97 * 2)) + 5) & 127;
    aux ^= index_reg_97 & 15;
  }
  else
  {
    acc = ((acc - index_reg_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000212_1213_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000212_1213_0 st_1 = {0};
  struct DeviceConfig_R000212_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int factor_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_25_1 > 34)
  {
    acc_1 = ((acc_1 + (factor_25_1 * 2)) + 5) & 127;
    aux_1 ^= factor_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_25_2 > 34)
  {
    acc_2 = ((acc_2 + (factor_25_2 * 2)) + 5) & 127;
    aux_2 ^= factor_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_25_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_65_1) & 63;
  aux_2 = (aux_2 + quotient_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_65_1)
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

  switch (sample_65_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_25_1 == factor_25_2);
  assert(quotient_65_1 == quotient_65_2);
  assert(sample_65_1 == sample_65_2);
}

int fn_R000212_1213_10(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000212_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int factor_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_25 > 34)
  {
    acc = ((acc + (factor_25 * 2)) + 5) & 127;
    aux ^= factor_25 & 15;
  }
  else
  {
    acc = ((acc - factor_25) + 11) & 127;
    aux += 3;
  }
  int quotient_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_65) & 63;
  acc ^= aux;
  int sample_65 = (aux + st.buffer[1]) & 3;
  switch (sample_65)
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

void fn_R000212_1213_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000212_1213_0 st_1 = {0};
  struct DeviceConfig_R000212_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int anchor_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_99_1 > 49)
  {
    acc_1 = ((acc_1 + (anchor_99_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_99_2 > 49)
  {
    acc_2 = ((acc_2 + (anchor_99_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_99_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_40_1) & 63;
  aux_2 = (aux_2 + segment_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_23_1 = local_arr_1[aux_1 % 3];
  int scale_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_23_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_99_1 == anchor_99_2);
  assert(segment_40_1 == segment_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_23_1 == scale_23_2);
}

int fn_R000212_1213_11(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000212_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int anchor_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_99 > 49)
  {
    acc = ((acc + (anchor_99 * 2)) + 5) & 127;
    aux ^= anchor_99 & 15;
  }
  else
  {
    acc = ((acc - anchor_99) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_40) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_23 = local_arr[aux % 3];
  acc = (acc + (scale_23 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000212_1213_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st_1 = {0};
  struct Transaction_R000212_1213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int window_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_18_1 > 11)
  {
    acc_1 = ((acc_1 + (window_18_1 * 2)) + 5) & 127;
    aux_1 ^= window_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_18_2 > 11)
  {
    acc_2 = ((acc_2 + (window_18_2 * 2)) + 5) & 127;
    aux_2 ^= window_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_18_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_12_1)
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

  switch (stride_12_2)
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
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_18_1 == window_18_2);
  assert(stride_12_1 == stride_12_2);
}

int fn_R000212_1213_12(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int window_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_18 > 11)
  {
    acc = ((acc + (window_18 * 2)) + 5) & 127;
    aux ^= window_18 & 15;
  }
  else
  {
    acc = ((acc - window_18) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_12 = (aux + st.buffer[1]) & 3;
  switch (stride_12)
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

void fn_R000212_1213_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000212_1213_0 st_1 = {0};
  struct DeviceConfig_R000212_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int pivot_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_93_1 > 39)
  {
    acc_1 = ((acc_1 + (pivot_93_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_93_2 > 39)
  {
    acc_2 = ((acc_2 + (pivot_93_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_21_1) & 63;
  aux_2 = (aux_2 + tally_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_30_1 = local_arr_1[aux_1 % 3];
  int damping_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_30_2 * 2)) & 127;
  int quotient_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_80_1)
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

  switch (quotient_80_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_93_1 == pivot_93_2);
  assert(tally_21_1 == tally_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_30_1 == damping_30_2);
  assert(quotient_80_1 == quotient_80_2);
}

int fn_R000212_1213_13(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000212_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int pivot_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_93 > 39)
  {
    acc = ((acc + (pivot_93 * 2)) + 5) & 127;
    aux ^= pivot_93 & 15;
  }
  else
  {
    acc = ((acc - pivot_93) + 11) & 127;
    aux += 3;
  }
  int tally_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_21) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int damping_30 = local_arr[aux % 3];
  acc = (acc + (damping_30 * 2)) & 127;
  int quotient_80 = (aux + st.buffer[1]) & 3;
  switch (quotient_80)
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

void fn_R000212_1213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000212_1213_3 st_1 = {0};
  struct CipherContext_R000212_1213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quotient_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_21_1) & 63;
  aux_2 = (aux_2 + quotient_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_60_1)
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

  switch (metric_60_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_21_1 == quotient_21_2);
  assert(metric_60_1 == metric_60_2);
}

int fn_R000212_1213_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000212_1213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quotient_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_21) & 63;
  acc ^= aux;
  int metric_60 = (aux + st.buffer[1]) & 3;
  switch (metric_60)
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

void fn_R000212_1213_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000212_1213_0 st_1 = {0};
  struct DeviceConfig_R000212_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int bound_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_41_1 > 19)
  {
    acc_1 = ((acc_1 + (bound_41_1 * 2)) + 5) & 127;
    aux_1 ^= bound_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_41_2 > 19)
  {
    acc_2 = ((acc_2 + (bound_41_2 * 2)) + 5) & 127;
    aux_2 ^= bound_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_22_1) & 63;
  aux_2 = (aux_2 + segment_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_41_1 == bound_41_2);
  assert(segment_22_1 == segment_22_2);
}

int fn_R000212_1213_15(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000212_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int bound_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_41 > 19)
  {
    acc = ((acc + (bound_41 * 2)) + 5) & 127;
    aux ^= bound_41 & 15;
  }
  else
  {
    acc = ((acc - bound_41) + 11) & 127;
    aux += 3;
  }
  int segment_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_22) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000212_1213_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st_1 = {0};
  struct Transaction_R000212_1213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_45_1)
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

  switch (margin_45_2)
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
  int segment_94_1 = local_arr_1[aux_1 % 3];
  int segment_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_94_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_45_1 == margin_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_94_1 == segment_94_2);
}

int fn_R000212_1213_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_45 = (aux + st.buffer[1]) & 3;
  switch (margin_45)
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
  int segment_94 = local_arr[aux % 3];
  acc = (acc + (segment_94 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000212_1213_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st_1 = {0};
  struct Transaction_R000212_1213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int pivot_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_49_1) & 63;
  aux_2 = (aux_2 + pivot_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_86_1 = local_arr_1[aux_1 % 3];
  int checksum_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_86_2 * 2)) & 127;
  int delta_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_99_1)
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

  switch (delta_99_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_49_1 == pivot_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_86_1 == checksum_86_2);
  assert(delta_99_1 == delta_99_2);
}

int fn_R000212_1213_17(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int pivot_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_49) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_86 = local_arr[aux % 3];
  acc = (acc + (checksum_86 * 2)) & 127;
  int delta_99 = (aux + st.buffer[1]) & 3;
  switch (delta_99)
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

void fn_R000212_1213_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000212_1213_1 st_1 = {0};
  struct FilterState_R000212_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_18_1 = local_arr_1[aux_1 % 3];
  int tracker_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_18_2 * 2)) & 127;
  int tally_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_36_1)
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

  switch (tally_36_2)
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
  assert(st_1.damping == st_2.damping);
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

  assert(tracker_18_1 == tracker_18_2);
  assert(tally_36_1 == tally_36_2);
}

int fn_R000212_1213_18(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000212_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int tracker_18 = local_arr[aux % 3];
  acc = (acc + (tracker_18 * 2)) & 127;
  int tally_36 = (aux + st.buffer[1]) & 3;
  switch (tally_36)
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

void fn_R000212_1213_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st_1 = {0};
  struct Transaction_R000212_1213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_53_1 = local_arr_1[aux_1 % 3];
  int damping_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_53_2 * 2)) & 127;
  int anchor_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_10_1 > 49)
  {
    acc_1 = ((acc_1 + (anchor_10_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_10_2 > 49)
  {
    acc_2 = ((acc_2 + (anchor_10_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_10_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_53_1 == damping_53_2);
  assert(anchor_10_1 == anchor_10_2);
}

int fn_R000212_1213_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int damping_53 = local_arr[aux % 3];
  acc = (acc + (damping_53 * 2)) & 127;
  int anchor_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_10 > 49)
  {
    acc = ((acc + (anchor_10 * 2)) + 5) & 127;
    aux ^= anchor_10 & 15;
  }
  else
  {
    acc = ((acc - anchor_10) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000212_1213_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000212_1213_3 st_1 = {0};
  struct CipherContext_R000212_1213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_67_1 > 37)
  {
    acc_1 = ((acc_1 + (metric_67_1 * 2)) + 5) & 127;
    aux_1 ^= metric_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_67_2 > 37)
  {
    acc_2 = ((acc_2 + (metric_67_2 * 2)) + 5) & 127;
    aux_2 ^= metric_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_67_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_10_1) & 63;
  aux_2 = (aux_2 + cursor_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_12_1)
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

  switch (delta_12_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_67_1 == metric_67_2);
  assert(cursor_10_1 == cursor_10_2);
  assert(delta_12_1 == delta_12_2);
}

int fn_R000212_1213_20(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000212_1213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_67 > 37)
  {
    acc = ((acc + (metric_67 * 2)) + 5) & 127;
    aux ^= metric_67 & 15;
  }
  else
  {
    acc = ((acc - metric_67) + 11) & 127;
    aux += 3;
  }
  int cursor_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_10) & 63;
  acc ^= aux;
  int delta_12 = (aux + st.buffer[1]) & 3;
  switch (delta_12)
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

void fn_R000212_1213_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st_1 = {0};
  struct Transaction_R000212_1213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_83_1) & 63;
  aux_2 = (aux_2 + tracker_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_83_1 == tracker_83_2);
}

int fn_R000212_1213_21(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000212_1213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_83) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000212_1213_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000212_1213_3 st_1 = {0};
  struct CipherContext_R000212_1213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int residue_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_85_1)
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

  switch (residue_85_2)
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

  int parity_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_96_1) & 63;
  aux_2 = (aux_2 + parity_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_85_1 == residue_85_2);
  assert(parity_96_1 == parity_96_2);
}

int fn_R000212_1213_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000212_1213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int residue_85 = (aux + st.buffer[1]) & 3;
  switch (residue_85)
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

  int parity_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000212_0_1;
  int sec_r000212_0_2;
  int sec_r000212_1_1;
  int sec_r000212_1_2;
  int sec_r000212_2_1;
  int sec_r000212_2_2;
  int sec_r000212_3_1;
  int sec_r000212_3_2;
  int sec_r000212_4_1;
  int sec_r000212_4_2;
  int sec_r000212_5_1;
  int sec_r000212_5_2;
  int sec_r000212_6_1;
  int sec_r000212_6_2;
  int sec_r000212_7_1;
  int sec_r000212_7_2;
  int sec_r000212_8_1;
  int sec_r000212_8_2;
  int sec_r000212_9_1;
  int sec_r000212_9_2;
  int sec_r000212_10_1;
  int sec_r000212_10_2;
  int sec_r000212_11_1;
  int sec_r000212_11_2;
  int sec_r000212_12_1;
  int sec_r000212_12_2;
  int sec_r000212_13_1;
  int sec_r000212_13_2;
  int sec_r000212_14_1;
  int sec_r000212_14_2;
  int sec_r000212_15_1;
  int sec_r000212_15_2;
  int sec_r000212_16_1;
  int sec_r000212_16_2;
  int sec_r000212_17_1;
  int sec_r000212_17_2;
  int sec_r000212_18_1;
  int sec_r000212_18_2;
  int sec_r000212_19_1;
  int sec_r000212_19_2;
  int sec_r000212_20_1;
  int sec_r000212_20_2;
  int pub_r000212_0_1;
  int pub_r000212_0_2;
  int pub_r000212_1_1;
  int pub_r000212_1_2;
  int pub_r000212_2_1;
  int pub_r000212_2_2;
  int pub_r000212_3_1;
  int pub_r000212_3_2;
  int pub_r000212_4_1;
  int pub_r000212_4_2;
  int pub_r000212_5_1;
  int pub_r000212_5_2;
  int pub_r000212_6_1;
  int pub_r000212_6_2;
  int pub_r000212_7_1;
  int pub_r000212_7_2;
  int pub_r000212_8_1;
  int pub_r000212_8_2;
  int pub_r000212_9_1;
  int pub_r000212_9_2;
  int pub_r000212_10_1;
  int pub_r000212_10_2;
  int pub_r000212_11_1;
  int pub_r000212_11_2;
  int pub_r000212_12_1;
  int pub_r000212_12_2;
  int pub_r000212_13_1;
  int pub_r000212_13_2;
  int pub_r000212_14_1;
  int pub_r000212_14_2;
  int pub_r000212_15_1;
  int pub_r000212_15_2;
  int pub_r000212_16_1;
  int pub_r000212_16_2;
  int pub_r000212_17_1;
  int pub_r000212_17_2;
  int pub_r000212_18_1;
  int pub_r000212_18_2;
  int pub_r000212_19_1;
  int pub_r000212_19_2;
  int pub_r000212_20_1;
  int pub_r000212_20_2;
  int pub_r000212_21_1;
  int pub_r000212_21_2;
  int pub_r000212_22_1;
  int pub_r000212_22_2;
  int pub_r000212_23_1;
  int pub_r000212_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000212_0_1 >= (-100)) && (pub_r000212_0_1 <= 100));
  __CPROVER_assume((pub_r000212_0_2 >= (-100)) && (pub_r000212_0_2 <= 100));
  __CPROVER_assume((pub_r000212_1_1 >= (-100)) && (pub_r000212_1_1 <= 100));
  __CPROVER_assume((pub_r000212_1_2 >= (-100)) && (pub_r000212_1_2 <= 100));
  __CPROVER_assume((pub_r000212_2_1 >= (-100)) && (pub_r000212_2_1 <= 100));
  __CPROVER_assume((pub_r000212_2_2 >= (-100)) && (pub_r000212_2_2 <= 100));
  __CPROVER_assume((pub_r000212_3_1 >= (-100)) && (pub_r000212_3_1 <= 100));
  __CPROVER_assume((pub_r000212_3_2 >= (-100)) && (pub_r000212_3_2 <= 100));
  __CPROVER_assume((pub_r000212_4_1 >= (-100)) && (pub_r000212_4_1 <= 100));
  __CPROVER_assume((pub_r000212_4_2 >= (-100)) && (pub_r000212_4_2 <= 100));
  __CPROVER_assume((pub_r000212_5_1 >= (-100)) && (pub_r000212_5_1 <= 100));
  __CPROVER_assume((pub_r000212_5_2 >= (-100)) && (pub_r000212_5_2 <= 100));
  __CPROVER_assume((pub_r000212_6_1 >= (-100)) && (pub_r000212_6_1 <= 100));
  __CPROVER_assume((pub_r000212_6_2 >= (-100)) && (pub_r000212_6_2 <= 100));
  __CPROVER_assume((pub_r000212_7_1 >= (-100)) && (pub_r000212_7_1 <= 100));
  __CPROVER_assume((pub_r000212_7_2 >= (-100)) && (pub_r000212_7_2 <= 100));
  __CPROVER_assume((pub_r000212_8_1 >= (-100)) && (pub_r000212_8_1 <= 100));
  __CPROVER_assume((pub_r000212_8_2 >= (-100)) && (pub_r000212_8_2 <= 100));
  __CPROVER_assume((pub_r000212_9_1 >= (-100)) && (pub_r000212_9_1 <= 100));
  __CPROVER_assume((pub_r000212_9_2 >= (-100)) && (pub_r000212_9_2 <= 100));
  __CPROVER_assume((pub_r000212_10_1 >= (-100)) && (pub_r000212_10_1 <= 100));
  __CPROVER_assume((pub_r000212_10_2 >= (-100)) && (pub_r000212_10_2 <= 100));
  __CPROVER_assume((pub_r000212_11_1 >= (-100)) && (pub_r000212_11_1 <= 100));
  __CPROVER_assume((pub_r000212_11_2 >= (-100)) && (pub_r000212_11_2 <= 100));
  __CPROVER_assume((pub_r000212_12_1 >= (-100)) && (pub_r000212_12_1 <= 100));
  __CPROVER_assume((pub_r000212_12_2 >= (-100)) && (pub_r000212_12_2 <= 100));
  __CPROVER_assume((pub_r000212_13_1 >= (-100)) && (pub_r000212_13_1 <= 100));
  __CPROVER_assume((pub_r000212_13_2 >= (-100)) && (pub_r000212_13_2 <= 100));
  __CPROVER_assume((pub_r000212_14_1 >= (-100)) && (pub_r000212_14_1 <= 100));
  __CPROVER_assume((pub_r000212_14_2 >= (-100)) && (pub_r000212_14_2 <= 100));
  __CPROVER_assume((pub_r000212_15_1 >= (-100)) && (pub_r000212_15_1 <= 100));
  __CPROVER_assume((pub_r000212_15_2 >= (-100)) && (pub_r000212_15_2 <= 100));
  __CPROVER_assume((pub_r000212_16_1 >= (-100)) && (pub_r000212_16_1 <= 100));
  __CPROVER_assume((pub_r000212_16_2 >= (-100)) && (pub_r000212_16_2 <= 100));
  __CPROVER_assume((pub_r000212_17_1 >= (-100)) && (pub_r000212_17_1 <= 100));
  __CPROVER_assume((pub_r000212_17_2 >= (-100)) && (pub_r000212_17_2 <= 100));
  __CPROVER_assume((pub_r000212_18_1 >= (-100)) && (pub_r000212_18_1 <= 100));
  __CPROVER_assume((pub_r000212_18_2 >= (-100)) && (pub_r000212_18_2 <= 100));
  __CPROVER_assume((pub_r000212_19_1 >= (-100)) && (pub_r000212_19_1 <= 100));
  __CPROVER_assume((pub_r000212_19_2 >= (-100)) && (pub_r000212_19_2 <= 100));
  __CPROVER_assume((pub_r000212_20_1 >= (-100)) && (pub_r000212_20_1 <= 100));
  __CPROVER_assume((pub_r000212_20_2 >= (-100)) && (pub_r000212_20_2 <= 100));
  __CPROVER_assume((pub_r000212_21_1 >= (-100)) && (pub_r000212_21_1 <= 100));
  __CPROVER_assume((pub_r000212_21_2 >= (-100)) && (pub_r000212_21_2 <= 100));
  __CPROVER_assume((pub_r000212_22_1 >= (-100)) && (pub_r000212_22_1 <= 100));
  __CPROVER_assume((pub_r000212_22_2 >= (-100)) && (pub_r000212_22_2 <= 100));
  __CPROVER_assume((pub_r000212_23_1 >= (-100)) && (pub_r000212_23_1 <= 100));
  __CPROVER_assume((pub_r000212_23_2 >= (-100)) && (pub_r000212_23_2 <= 100));
  __CPROVER_assume((sec_r000212_0_1 >= 0) && (sec_r000212_0_1 <= 255));
  __CPROVER_assume((sec_r000212_0_2 >= 0) && (sec_r000212_0_2 <= 255));
  __CPROVER_assume((sec_r000212_1_1 >= 0) && (sec_r000212_1_1 <= 255));
  __CPROVER_assume((sec_r000212_1_2 >= 0) && (sec_r000212_1_2 <= 255));
  __CPROVER_assume((sec_r000212_2_1 >= 0) && (sec_r000212_2_1 <= 255));
  __CPROVER_assume((sec_r000212_2_2 >= 0) && (sec_r000212_2_2 <= 255));
  __CPROVER_assume((sec_r000212_3_1 >= 0) && (sec_r000212_3_1 <= 255));
  __CPROVER_assume((sec_r000212_3_2 >= 0) && (sec_r000212_3_2 <= 255));
  __CPROVER_assume((sec_r000212_4_1 >= 0) && (sec_r000212_4_1 <= 255));
  __CPROVER_assume((sec_r000212_4_2 >= 0) && (sec_r000212_4_2 <= 255));
  __CPROVER_assume((sec_r000212_5_1 >= 0) && (sec_r000212_5_1 <= 255));
  __CPROVER_assume((sec_r000212_5_2 >= 0) && (sec_r000212_5_2 <= 255));
  __CPROVER_assume((sec_r000212_6_1 >= 0) && (sec_r000212_6_1 <= 255));
  __CPROVER_assume((sec_r000212_6_2 >= 0) && (sec_r000212_6_2 <= 255));
  __CPROVER_assume((sec_r000212_7_1 >= 0) && (sec_r000212_7_1 <= 255));
  __CPROVER_assume((sec_r000212_7_2 >= 0) && (sec_r000212_7_2 <= 255));
  __CPROVER_assume((sec_r000212_8_1 >= 0) && (sec_r000212_8_1 <= 255));
  __CPROVER_assume((sec_r000212_8_2 >= 0) && (sec_r000212_8_2 <= 255));
  __CPROVER_assume((sec_r000212_9_1 >= 0) && (sec_r000212_9_1 <= 255));
  __CPROVER_assume((sec_r000212_9_2 >= 0) && (sec_r000212_9_2 <= 255));
  __CPROVER_assume((sec_r000212_10_1 >= 0) && (sec_r000212_10_1 <= 255));
  __CPROVER_assume((sec_r000212_10_2 >= 0) && (sec_r000212_10_2 <= 255));
  __CPROVER_assume((sec_r000212_11_1 >= 0) && (sec_r000212_11_1 <= 255));
  __CPROVER_assume((sec_r000212_11_2 >= 0) && (sec_r000212_11_2 <= 255));
  __CPROVER_assume((sec_r000212_12_1 >= 0) && (sec_r000212_12_1 <= 255));
  __CPROVER_assume((sec_r000212_12_2 >= 0) && (sec_r000212_12_2 <= 255));
  __CPROVER_assume((sec_r000212_13_1 >= 0) && (sec_r000212_13_1 <= 255));
  __CPROVER_assume((sec_r000212_13_2 >= 0) && (sec_r000212_13_2 <= 255));
  __CPROVER_assume((sec_r000212_14_1 >= 0) && (sec_r000212_14_1 <= 255));
  __CPROVER_assume((sec_r000212_14_2 >= 0) && (sec_r000212_14_2 <= 255));
  __CPROVER_assume((sec_r000212_15_1 >= 0) && (sec_r000212_15_1 <= 255));
  __CPROVER_assume((sec_r000212_15_2 >= 0) && (sec_r000212_15_2 <= 255));
  __CPROVER_assume((sec_r000212_16_1 >= 0) && (sec_r000212_16_1 <= 255));
  __CPROVER_assume((sec_r000212_16_2 >= 0) && (sec_r000212_16_2 <= 255));
  __CPROVER_assume((sec_r000212_17_1 >= 0) && (sec_r000212_17_1 <= 255));
  __CPROVER_assume((sec_r000212_17_2 >= 0) && (sec_r000212_17_2 <= 255));
  __CPROVER_assume((sec_r000212_18_1 >= 0) && (sec_r000212_18_1 <= 255));
  __CPROVER_assume((sec_r000212_18_2 >= 0) && (sec_r000212_18_2 <= 255));
  __CPROVER_assume((sec_r000212_19_1 >= 0) && (sec_r000212_19_1 <= 255));
  __CPROVER_assume((sec_r000212_19_2 >= 0) && (sec_r000212_19_2 <= 255));
  __CPROVER_assume((sec_r000212_20_1 >= 0) && (sec_r000212_20_1 <= 255));
  __CPROVER_assume((sec_r000212_20_2 >= 0) && (sec_r000212_20_2 <= 255));
  struct DeviceConfig_R000212_1213_0 st_var_0_1 = {0};
  struct DeviceConfig_R000212_1213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000212_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000212_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000212_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000212_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000212_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000212_0_2 + 7) & 15;
  struct FilterState_R000212_1213_1 st_var_1_1 = {0};
  struct FilterState_R000212_1213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000212_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000212_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000212_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000212_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000212_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000212_0_2 + 9) & 15;
  struct Transaction_R000212_1213_2 st_var_2_1 = {0};
  struct Transaction_R000212_1213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000212_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000212_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000212_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000212_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000212_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000212_0_2 + 11) & 15;
  struct CipherContext_R000212_1213_3 st_var_3_1 = {0};
  struct CipherContext_R000212_1213_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000212_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000212_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000212_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000212_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000212_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000212_0_2 + 13) & 15;
  union ColorPixel_R000212_1213_0 u_var_1;
  union ColorPixel_R000212_1213_0 u_var_2;
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
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 4) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
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
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (st_var_3_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_3_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
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

  switch (stage_v_7_2)
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

  int stage_v_8_1 = ((st_var_0_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_0_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 51)
    {
      chk_sum_1 ^= stage_v_8_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_8_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 51)
    {
      chk_sum_2 ^= stage_v_8_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_9_1 = ((st_var_1_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_1_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 30)
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
  if (stage_v_9_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 30)
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
  int stage_v_10_1 = (st_var_2_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_2_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 12) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 40)
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
  if (stage_v_13_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 40)
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
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 16) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_3_2.buffer[0] * 3) & 63;
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
  int stage_v_17_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (22 & 31);
  int stage_v_17_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (22 & 31);
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= (stage_v_17_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_17_2 << 1) & 127;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 19) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = ((st_var_3_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_3_2.buffer[1] * 2) + 64) & 63;
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
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 22) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 23) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 54)
    {
      chk_sum_1 ^= stage_v_24_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_24_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 54)
    {
      chk_sum_2 ^= stage_v_24_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 28) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (34 & 31);
  int stage_v_29_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (34 & 31);
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= (stage_v_29_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_29_2 << 1) & 127;
  int stage_v_30_1 = ((st_var_2_1.buffer[0] * 2) + 97) & 63;
  int stage_v_30_2 = ((st_var_2_2.buffer[0] * 2) + 97) & 63;
  if (stage_v_30_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_30_1) - 5) & 255;
    if (stage_v_30_1 > 54)
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
  if (stage_v_30_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_30_2) - 5) & 255;
    if (stage_v_30_2 > 54)
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 33) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
  int stage_v_33_1 = table_1[1];
  int stage_v_33_2 = table_2[1];
  table_1[1] = (table_1[2] + 67) & 63;
  table_2[1] = (table_2[2] + 67) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 52)
    {
      chk_sum_1 ^= stage_v_37_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_37_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 52)
    {
      chk_sum_2 ^= stage_v_37_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_39_1 = (st_var_3_1.buffer[0] ^ 42) & 3;
  int stage_v_39_2 = (st_var_3_2.buffer[0] ^ 42) & 3;
  switch (stage_v_39_1)
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

  switch (stage_v_39_2)
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

  int stage_v_40_1 = (st_var_0_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_0_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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
  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
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
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (52 & 31);
  int stage_v_47_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (52 & 31);
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= (stage_v_47_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_47_2 << 1) & 127;
  int stage_v_48_1 = (st_var_0_1.buffer[0] ^ 51) & 3;
  int stage_v_48_2 = (st_var_0_2.buffer[0] ^ 51) & 3;
  switch (stage_v_48_1)
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

  switch (stage_v_48_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 50) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 50) & 15;
  int stage_v_49_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_49_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= stage_v_49_1;
  chk_sum_2 ^= stage_v_49_2;
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
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 52) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 52) & 15;
  int stage_v_51_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_51_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= stage_v_51_1;
  chk_sum_2 ^= stage_v_51_2;
  int stage_v_52_1 = table_1[0];
  int stage_v_52_2 = table_2[0];
  table_1[0] = (table_1[1] + 105) & 63;
  table_2[0] = (table_2[1] + 105) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (st_var_1_1.buffer[0] ^ 56) & 3;
  int stage_v_53_2 = (st_var_1_2.buffer[0] ^ 56) & 3;
  switch (stage_v_53_1)
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

  switch (stage_v_53_2)
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

  int stage_v_54_1 = ((st_var_2_1.buffer[0] * 2) + 169) & 63;
  int stage_v_54_2 = ((st_var_2_2.buffer[0] * 2) + 169) & 63;
  if (stage_v_54_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_54_1) - 5) & 255;
    if (stage_v_54_1 > 40)
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
  if (stage_v_54_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_54_2) - 5) & 255;
    if (stage_v_54_2 > 40)
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
  int stage_v_55_1 = (st_var_3_1.buffer[0] ^ 58) & 3;
  int stage_v_55_2 = (st_var_3_2.buffer[0] ^ 58) & 3;
  switch (stage_v_55_1)
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

  switch (stage_v_55_2)
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

  int stage_v_56_1 = (st_var_0_1.buffer[0] ^ 59) & 3;
  int stage_v_56_2 = (st_var_0_2.buffer[0] ^ 59) & 3;
  switch (stage_v_56_1)
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

  switch (stage_v_56_2)
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

  int stage_v_57_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_57_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_58_1 = (st_var_2_1.buffer[0] ^ 61) & 3;
  int stage_v_58_2 = (st_var_2_2.buffer[0] ^ 61) & 3;
  switch (stage_v_58_1)
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

  switch (stage_v_58_2)
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

  int stage_v_59_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (64 & 31);
  int stage_v_59_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (64 & 31);
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= (stage_v_59_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_59_2 << 1) & 127;
  int stage_v_60_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (65 & 31);
  int stage_v_60_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (65 & 31);
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= (stage_v_60_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_60_2 << 1) & 127;
  int stage_v_61_1 = (st_var_1_1.buffer[0] ^ 64) & 3;
  int stage_v_61_2 = (st_var_1_2.buffer[0] ^ 64) & 3;
  switch (stage_v_61_1)
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

  switch (stage_v_61_2)
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

  int stage_v_62_1 = ((sec_r000212_13_1 + pub_r000212_10_1) + 37) & 127;
  int stage_v_62_2 = ((sec_r000212_13_2 + pub_r000212_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((stage_v_62_1 + pub_r000212_23_1) + 5) & 127;
  int stage_v_63_2 = ((stage_v_62_2 + pub_r000212_23_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((stage_v_63_1 + pub_r000212_8_1) + 10) & 127;
  int stage_v_64_2 = ((stage_v_63_2 + pub_r000212_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((sec_r000212_1_1 + pub_r000212_14_1) + 41) & 127;
  int stage_v_65_2 = ((sec_r000212_1_2 + pub_r000212_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((stage_v_64_1 + pub_r000212_17_1) + 20) & 127;
  int stage_v_66_2 = ((stage_v_64_2 + pub_r000212_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((stage_v_65_1 + pub_r000212_20_1) + 30) & 127;
  int stage_v_67_2 = ((stage_v_65_2 + pub_r000212_20_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((sec_r000212_13_1 + pub_r000212_3_1) + 26) & 127;
  int stage_v_68_2 = ((sec_r000212_13_2 + pub_r000212_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((stage_v_66_1 + pub_r000212_3_1) + 9) & 127;
  int stage_v_69_2 = ((stage_v_66_2 + pub_r000212_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((stage_v_67_1 + pub_r000212_2_1) + 12) & 127;
  int stage_v_70_2 = ((stage_v_67_2 + pub_r000212_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((sec_r000212_0_1 + pub_r000212_1_1) + 38) & 127;
  int stage_v_71_2 = ((sec_r000212_0_2 + pub_r000212_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((sec_r000212_8_1 + pub_r000212_23_1) + 10) & 127;
  int stage_v_72_2 = ((sec_r000212_8_2 + pub_r000212_23_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((stage_v_65_1 + pub_r000212_4_1) + 14) & 127;
  int stage_v_73_2 = ((stage_v_65_2 + pub_r000212_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((stage_v_65_1 + pub_r000212_11_1) + 26) & 127;
  int stage_v_74_2 = ((stage_v_65_2 + pub_r000212_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((stage_v_69_1 + pub_r000212_2_1) + 15) & 127;
  int stage_v_75_2 = ((stage_v_69_2 + pub_r000212_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((stage_v_70_1 + pub_r000212_14_1) + 15) & 127;
  int stage_v_76_2 = ((stage_v_70_2 + pub_r000212_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((stage_v_71_1 + pub_r000212_14_1) + 24) & 127;
  int stage_v_77_2 = ((stage_v_71_2 + pub_r000212_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((stage_v_72_1 + pub_r000212_3_1) + 18) & 127;
  int stage_v_78_2 = ((stage_v_72_2 + pub_r000212_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((sec_r000212_10_1 + pub_r000212_7_1) + 18) & 127;
  int stage_v_79_2 = ((sec_r000212_10_2 + pub_r000212_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((stage_v_71_1 + pub_r000212_8_1) + 14) & 127;
  int stage_v_80_2 = ((stage_v_71_2 + pub_r000212_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((sec_r000212_2_1 + pub_r000212_19_1) + 27) & 127;
  int stage_v_81_2 = ((sec_r000212_2_2 + pub_r000212_19_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((stage_v_72_1 + pub_r000212_20_1) + 9) & 127;
  int stage_v_82_2 = ((stage_v_72_2 + pub_r000212_20_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((stage_v_64_1 + pub_r000212_10_1) + 47) & 127;
  int stage_v_83_2 = ((stage_v_64_2 + pub_r000212_10_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((sec_r000212_18_1 + pub_r000212_9_1) + 16) & 127;
  int stage_v_84_2 = ((sec_r000212_18_2 + pub_r000212_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((stage_v_72_1 + pub_r000212_17_1) + 37) & 127;
  int stage_v_85_2 = ((stage_v_72_2 + pub_r000212_17_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((sec_r000212_3_1 + pub_r000212_4_1) + 45) & 127;
  int stage_v_86_2 = ((sec_r000212_3_2 + pub_r000212_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((stage_v_83_1 + pub_r000212_4_1) + 45) & 127;
  int stage_v_87_2 = ((stage_v_83_2 + pub_r000212_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((sec_r000212_19_1 + pub_r000212_7_1) + 43) & 127;
  int stage_v_88_2 = ((sec_r000212_19_2 + pub_r000212_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((stage_v_65_1 + pub_r000212_1_1) + 23) & 127;
  int stage_v_89_2 = ((stage_v_65_2 + pub_r000212_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((stage_v_83_1 + pub_r000212_6_1) + 22) & 127;
  int stage_v_90_2 = ((stage_v_83_2 + pub_r000212_6_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((sec_r000212_15_1 + pub_r000212_22_1) + 9) & 127;
  int stage_v_91_2 = ((sec_r000212_15_2 + pub_r000212_22_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((stage_v_89_1 + pub_r000212_15_1) + 32) & 127;
  int stage_v_92_2 = ((stage_v_89_2 + pub_r000212_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((stage_v_66_1 + pub_r000212_23_1) + 39) & 127;
  int stage_v_93_2 = ((stage_v_66_2 + pub_r000212_23_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((sec_r000212_12_1 + pub_r000212_10_1) + 41) & 127;
  int stage_v_94_2 = ((sec_r000212_12_2 + pub_r000212_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((sec_r000212_13_1 + pub_r000212_0_1) + 20) & 127;
  int stage_v_95_2 = ((sec_r000212_13_2 + pub_r000212_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((stage_v_88_1 + pub_r000212_13_1) + 9) & 127;
  int stage_v_96_2 = ((stage_v_88_2 + pub_r000212_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((sec_r000212_5_1 + pub_r000212_23_1) + 31) & 127;
  int stage_v_97_2 = ((sec_r000212_5_2 + pub_r000212_23_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((sec_r000212_7_1 + pub_r000212_21_1) + 22) & 127;
  int stage_v_98_2 = ((sec_r000212_7_2 + pub_r000212_21_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((stage_v_65_1 + pub_r000212_18_1) + 22) & 127;
  int stage_v_99_2 = ((stage_v_65_2 + pub_r000212_18_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((stage_v_85_1 + pub_r000212_1_1) + 24) & 127;
  int stage_v_100_2 = ((stage_v_85_2 + pub_r000212_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((stage_v_97_1 + pub_r000212_5_1) + 14) & 127;
  int stage_v_101_2 = ((stage_v_97_2 + pub_r000212_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((sec_r000212_13_1 + pub_r000212_22_1) + 46) & 127;
  int stage_v_102_2 = ((sec_r000212_13_2 + pub_r000212_22_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((stage_v_72_1 + pub_r000212_16_1) + 38) & 127;
  int stage_v_103_2 = ((stage_v_72_2 + pub_r000212_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((stage_v_80_1 + pub_r000212_17_1) + 14) & 127;
  int stage_v_104_2 = ((stage_v_80_2 + pub_r000212_17_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((stage_v_68_1 + pub_r000212_2_1) + 39) & 127;
  int stage_v_105_2 = ((stage_v_68_2 + pub_r000212_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((sec_r000212_18_1 + pub_r000212_19_1) + 7) & 127;
  int stage_v_106_2 = ((sec_r000212_18_2 + pub_r000212_19_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((sec_r000212_16_1 + pub_r000212_4_1) + 26) & 127;
  int stage_v_107_2 = ((sec_r000212_16_2 + pub_r000212_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((stage_v_87_1 + pub_r000212_17_1) + 48) & 127;
  int stage_v_108_2 = ((stage_v_87_2 + pub_r000212_17_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((stage_v_101_1 + pub_r000212_9_1) + 40) & 127;
  int stage_v_109_2 = ((stage_v_101_2 + pub_r000212_9_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((sec_r000212_19_1 + pub_r000212_20_1) + 49) & 127;
  int stage_v_110_2 = ((sec_r000212_19_2 + pub_r000212_20_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((sec_r000212_4_1 + pub_r000212_12_1) + 7) & 127;
  int stage_v_111_2 = ((sec_r000212_4_2 + pub_r000212_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((stage_v_62_1 + pub_r000212_22_1) + 23) & 127;
  int stage_v_112_2 = ((stage_v_62_2 + pub_r000212_22_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((stage_v_68_1 + pub_r000212_2_1) + 9) & 127;
  int stage_v_113_2 = ((stage_v_68_2 + pub_r000212_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((stage_v_65_1 + pub_r000212_5_1) + 45) & 127;
  int stage_v_114_2 = ((stage_v_65_2 + pub_r000212_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((stage_v_68_1 + pub_r000212_1_1) + 28) & 127;
  int stage_v_115_2 = ((stage_v_68_2 + pub_r000212_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((stage_v_73_1 + pub_r000212_19_1) + 39) & 127;
  int stage_v_116_2 = ((stage_v_73_2 + pub_r000212_19_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((stage_v_116_1 + pub_r000212_23_1) + 40) & 127;
  int stage_v_117_2 = ((stage_v_116_2 + pub_r000212_23_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((sec_r000212_11_1 + pub_r000212_4_1) + 6) & 127;
  int stage_v_118_2 = ((sec_r000212_11_2 + pub_r000212_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((sec_r000212_10_1 + pub_r000212_17_1) + 27) & 127;
  int stage_v_119_2 = ((sec_r000212_10_2 + pub_r000212_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((sec_r000212_17_1 + pub_r000212_8_1) + 33) & 127;
  int stage_v_120_2 = ((sec_r000212_17_2 + pub_r000212_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((stage_v_78_1 + pub_r000212_10_1) + 44) & 127;
  int stage_v_121_2 = ((stage_v_78_2 + pub_r000212_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((stage_v_62_1 + pub_r000212_15_1) + 17) & 127;
  int stage_v_122_2 = ((stage_v_62_2 + pub_r000212_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((stage_v_63_1 + pub_r000212_12_1) + 39) & 127;
  int stage_v_123_2 = ((stage_v_63_2 + pub_r000212_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((stage_v_95_1 + pub_r000212_9_1) + 5) & 127;
  int stage_v_124_2 = ((stage_v_95_2 + pub_r000212_9_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((sec_r000212_14_1 + pub_r000212_14_1) + 9) & 127;
  int stage_v_125_2 = ((sec_r000212_14_2 + pub_r000212_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((sec_r000212_7_1 + pub_r000212_8_1) + 7) & 127;
  int stage_v_126_2 = ((sec_r000212_7_2 + pub_r000212_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((stage_v_77_1 + pub_r000212_13_1) + 19) & 127;
  int stage_v_127_2 = ((stage_v_77_2 + pub_r000212_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((sec_r000212_2_1 + pub_r000212_13_1) + 24) & 127;
  int stage_v_128_2 = ((sec_r000212_2_2 + pub_r000212_13_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((sec_r000212_19_1 + pub_r000212_9_1) + 40) & 127;
  int stage_v_129_2 = ((sec_r000212_19_2 + pub_r000212_9_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((stage_v_62_1 + pub_r000212_3_1) + 49) & 127;
  int stage_v_130_2 = ((stage_v_62_2 + pub_r000212_3_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((stage_v_98_1 + pub_r000212_16_1) + 31) & 127;
  int stage_v_131_2 = ((stage_v_98_2 + pub_r000212_16_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((sec_r000212_18_1 + pub_r000212_18_1) + 23) & 127;
  int stage_v_132_2 = ((sec_r000212_18_2 + pub_r000212_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((sec_r000212_1_1 + pub_r000212_14_1) + 42) & 127;
  int stage_v_133_2 = ((sec_r000212_1_2 + pub_r000212_14_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((stage_v_69_1 + pub_r000212_21_1) + 5) & 127;
  int stage_v_134_2 = ((stage_v_69_2 + pub_r000212_21_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((stage_v_119_1 + pub_r000212_18_1) + 31) & 127;
  int stage_v_135_2 = ((stage_v_119_2 + pub_r000212_18_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((sec_r000212_16_1 + pub_r000212_13_1) + 14) & 127;
  int stage_v_136_2 = ((sec_r000212_16_2 + pub_r000212_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((stage_v_74_1 + pub_r000212_7_1) + 44) & 127;
  int stage_v_137_2 = ((stage_v_74_2 + pub_r000212_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((stage_v_67_1 + pub_r000212_9_1) + 38) & 127;
  int stage_v_138_2 = ((stage_v_67_2 + pub_r000212_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((sec_r000212_16_1 + pub_r000212_17_1) + 47) & 127;
  int stage_v_139_2 = ((sec_r000212_16_2 + pub_r000212_17_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((sec_r000212_3_1 + pub_r000212_4_1) + 29) & 127;
  int stage_v_140_2 = ((sec_r000212_3_2 + pub_r000212_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((stage_v_70_1 + pub_r000212_8_1) + 24) & 127;
  int stage_v_141_2 = ((stage_v_70_2 + pub_r000212_8_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((stage_v_119_1 + pub_r000212_6_1) + 10) & 127;
  int stage_v_142_2 = ((stage_v_119_2 + pub_r000212_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((stage_v_101_1 + pub_r000212_5_1) + 15) & 127;
  int stage_v_143_2 = ((stage_v_101_2 + pub_r000212_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((sec_r000212_0_1 + pub_r000212_8_1) + 44) & 127;
  int stage_v_144_2 = ((sec_r000212_0_2 + pub_r000212_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((stage_v_119_1 + pub_r000212_19_1) + 9) & 127;
  int stage_v_145_2 = ((stage_v_119_2 + pub_r000212_19_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((stage_v_117_1 + pub_r000212_14_1) + 30) & 127;
  int stage_v_146_2 = ((stage_v_117_2 + pub_r000212_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((sec_r000212_3_1 + pub_r000212_10_1) + 17) & 127;
  int stage_v_147_2 = ((sec_r000212_3_2 + pub_r000212_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((stage_v_145_1 + pub_r000212_4_1) + 12) & 127;
  int stage_v_148_2 = ((stage_v_145_2 + pub_r000212_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((stage_v_144_1 + pub_r000212_10_1) + 22) & 127;
  int stage_v_149_2 = ((stage_v_144_2 + pub_r000212_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((sec_r000212_17_1 + pub_r000212_3_1) + 8) & 127;
  int stage_v_150_2 = ((sec_r000212_17_2 + pub_r000212_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((sec_r000212_3_1 + pub_r000212_8_1) + 5) & 127;
  int stage_v_151_2 = ((sec_r000212_3_2 + pub_r000212_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((stage_v_80_1 + pub_r000212_21_1) + 44) & 127;
  int stage_v_152_2 = ((stage_v_80_2 + pub_r000212_21_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((stage_v_83_1 + pub_r000212_4_1) + 41) & 127;
  int stage_v_153_2 = ((stage_v_83_2 + pub_r000212_4_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((sec_r000212_9_1 + pub_r000212_21_1) + 42) & 127;
  int stage_v_154_2 = ((sec_r000212_9_2 + pub_r000212_21_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((stage_v_116_1 + pub_r000212_7_1) + 15) & 127;
  int stage_v_155_2 = ((stage_v_116_2 + pub_r000212_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((sec_r000212_14_1 + pub_r000212_14_1) + 28) & 127;
  int stage_v_156_2 = ((sec_r000212_14_2 + pub_r000212_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((sec_r000212_8_1 + pub_r000212_11_1) + 31) & 127;
  int stage_v_157_2 = ((sec_r000212_8_2 + pub_r000212_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((sec_r000212_5_1 + pub_r000212_7_1) + 13) & 127;
  int stage_v_158_2 = ((sec_r000212_5_2 + pub_r000212_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((sec_r000212_6_1 + pub_r000212_14_1) + 13) & 127;
  int stage_v_159_2 = ((sec_r000212_6_2 + pub_r000212_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((stage_v_72_1 + pub_r000212_8_1) + 49) & 127;
  int stage_v_160_2 = ((stage_v_72_2 + pub_r000212_8_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((stage_v_103_1 + pub_r000212_9_1) + 48) & 127;
  int stage_v_161_2 = ((stage_v_103_2 + pub_r000212_9_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((sec_r000212_13_1 + pub_r000212_0_1) + 13) & 127;
  int stage_v_162_2 = ((sec_r000212_13_2 + pub_r000212_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((stage_v_74_1 + pub_r000212_9_1) + 20) & 127;
  int stage_v_163_2 = ((stage_v_74_2 + pub_r000212_9_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((sec_r000212_15_1 + pub_r000212_15_1) + 24) & 127;
  int stage_v_164_2 = ((sec_r000212_15_2 + pub_r000212_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((stage_v_108_1 + pub_r000212_13_1) + 10) & 127;
  int stage_v_165_2 = ((stage_v_108_2 + pub_r000212_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((stage_v_159_1 + pub_r000212_11_1) + 36) & 127;
  int stage_v_166_2 = ((stage_v_159_2 + pub_r000212_11_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((stage_v_116_1 + pub_r000212_13_1) + 27) & 127;
  int stage_v_167_2 = ((stage_v_116_2 + pub_r000212_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((sec_r000212_3_1 + pub_r000212_12_1) + 9) & 127;
  int stage_v_168_2 = ((sec_r000212_3_2 + pub_r000212_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((stage_v_153_1 + pub_r000212_19_1) + 11) & 127;
  int stage_v_169_2 = ((stage_v_153_2 + pub_r000212_19_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((stage_v_134_1 + pub_r000212_18_1) + 40) & 127;
  int stage_v_170_2 = ((stage_v_134_2 + pub_r000212_18_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((sec_r000212_16_1 + pub_r000212_23_1) + 21) & 127;
  int stage_v_171_2 = ((sec_r000212_16_2 + pub_r000212_23_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((stage_v_145_1 + pub_r000212_16_1) + 43) & 127;
  int stage_v_172_2 = ((stage_v_145_2 + pub_r000212_16_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((stage_v_162_1 + pub_r000212_22_1) + 21) & 127;
  int stage_v_173_2 = ((stage_v_162_2 + pub_r000212_22_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((sec_r000212_6_1 + pub_r000212_14_1) + 33) & 127;
  int stage_v_174_2 = ((sec_r000212_6_2 + pub_r000212_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((stage_v_114_1 + pub_r000212_19_1) + 6) & 127;
  int stage_v_175_2 = ((stage_v_114_2 + pub_r000212_19_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((sec_r000212_2_1 + pub_r000212_0_1) + 9) & 127;
  int stage_v_176_2 = ((sec_r000212_2_2 + pub_r000212_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((sec_r000212_12_1 + pub_r000212_5_1) + 18) & 127;
  int stage_v_177_2 = ((sec_r000212_12_2 + pub_r000212_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((stage_v_95_1 + pub_r000212_6_1) + 28) & 127;
  int stage_v_178_2 = ((stage_v_95_2 + pub_r000212_6_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((stage_v_86_1 + pub_r000212_12_1) + 28) & 127;
  int stage_v_179_2 = ((stage_v_86_2 + pub_r000212_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((stage_v_80_1 + pub_r000212_22_1) + 17) & 127;
  int stage_v_180_2 = ((stage_v_80_2 + pub_r000212_22_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((stage_v_152_1 + pub_r000212_22_1) + 11) & 127;
  int stage_v_181_2 = ((stage_v_152_2 + pub_r000212_22_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((stage_v_72_1 + pub_r000212_10_1) + 3) & 127;
  int stage_v_182_2 = ((stage_v_72_2 + pub_r000212_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((sec_r000212_17_1 + pub_r000212_8_1) + 10) & 127;
  int stage_v_183_2 = ((sec_r000212_17_2 + pub_r000212_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((stage_v_114_1 + pub_r000212_7_1) + 26) & 127;
  int stage_v_184_2 = ((stage_v_114_2 + pub_r000212_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((stage_v_151_1 + pub_r000212_13_1) + 8) & 127;
  int stage_v_185_2 = ((stage_v_151_2 + pub_r000212_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((stage_v_134_1 + pub_r000212_5_1) + 8) & 127;
  int stage_v_186_2 = ((stage_v_134_2 + pub_r000212_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((stage_v_89_1 + pub_r000212_17_1) + 25) & 127;
  int stage_v_187_2 = ((stage_v_89_2 + pub_r000212_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((stage_v_65_1 + pub_r000212_14_1) + 46) & 127;
  int stage_v_188_2 = ((stage_v_65_2 + pub_r000212_14_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((stage_v_90_1 + pub_r000212_1_1) + 29) & 127;
  int stage_v_189_2 = ((stage_v_90_2 + pub_r000212_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((stage_v_111_1 + pub_r000212_11_1) + 28) & 127;
  int stage_v_190_2 = ((stage_v_111_2 + pub_r000212_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((sec_r000212_8_1 + pub_r000212_19_1) + 49) & 127;
  int stage_v_191_2 = ((sec_r000212_8_2 + pub_r000212_19_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((stage_v_187_1 + pub_r000212_15_1) + 25) & 127;
  int stage_v_192_2 = ((stage_v_187_2 + pub_r000212_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((stage_v_147_1 + pub_r000212_11_1) + 34) & 127;
  int stage_v_193_2 = ((stage_v_147_2 + pub_r000212_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((stage_v_171_1 + pub_r000212_17_1) + 16) & 127;
  int stage_v_194_2 = ((stage_v_171_2 + pub_r000212_17_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((stage_v_172_1 + pub_r000212_1_1) + 3) & 127;
  int stage_v_195_2 = ((stage_v_172_2 + pub_r000212_1_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((stage_v_131_1 + pub_r000212_4_1) + 13) & 127;
  int stage_v_196_2 = ((stage_v_131_2 + pub_r000212_4_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((sec_r000212_2_1 + pub_r000212_20_1) + 42) & 127;
  int stage_v_197_2 = ((sec_r000212_2_2 + pub_r000212_20_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((stage_v_86_1 + pub_r000212_13_1) + 30) & 127;
  int stage_v_198_2 = ((stage_v_86_2 + pub_r000212_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((stage_v_87_1 + pub_r000212_9_1) + 39) & 127;
  int stage_v_199_2 = ((stage_v_87_2 + pub_r000212_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((stage_v_99_1 + pub_r000212_2_1) + 39) & 127;
  int stage_v_200_2 = ((stage_v_99_2 + pub_r000212_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((stage_v_141_1 + pub_r000212_9_1) + 7) & 127;
  int stage_v_201_2 = ((stage_v_141_2 + pub_r000212_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((stage_v_105_1 + pub_r000212_19_1) + 35) & 127;
  int stage_v_202_2 = ((stage_v_105_2 + pub_r000212_19_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((sec_r000212_13_1 + pub_r000212_5_1) + 4) & 127;
  int stage_v_203_2 = ((sec_r000212_13_2 + pub_r000212_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((stage_v_182_1 + pub_r000212_3_1) + 33) & 127;
  int stage_v_204_2 = ((stage_v_182_2 + pub_r000212_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((sec_r000212_4_1 + pub_r000212_18_1) + 30) & 127;
  int stage_v_205_2 = ((sec_r000212_4_2 + pub_r000212_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((sec_r000212_9_1 + pub_r000212_10_1) + 43) & 127;
  int stage_v_206_2 = ((sec_r000212_9_2 + pub_r000212_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((stage_v_136_1 + pub_r000212_22_1) + 42) & 127;
  int stage_v_207_2 = ((stage_v_136_2 + pub_r000212_22_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((stage_v_154_1 + pub_r000212_20_1) + 8) & 127;
  int stage_v_208_2 = ((stage_v_154_2 + pub_r000212_20_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((sec_r000212_18_1 + pub_r000212_23_1) + 34) & 127;
  int stage_v_209_2 = ((sec_r000212_18_2 + pub_r000212_23_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((stage_v_203_1 + pub_r000212_23_1) + 37) & 127;
  int stage_v_210_2 = ((stage_v_203_2 + pub_r000212_23_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((stage_v_122_1 + pub_r000212_20_1) + 10) & 127;
  int stage_v_211_2 = ((stage_v_122_2 + pub_r000212_20_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((stage_v_188_1 + pub_r000212_11_1) + 17) & 127;
  int stage_v_212_2 = ((stage_v_188_2 + pub_r000212_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((sec_r000212_10_1 + pub_r000212_19_1) + 16) & 127;
  int stage_v_213_2 = ((sec_r000212_10_2 + pub_r000212_19_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((sec_r000212_11_1 + pub_r000212_19_1) + 45) & 127;
  int stage_v_214_2 = ((sec_r000212_11_2 + pub_r000212_19_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((stage_v_98_1 + pub_r000212_23_1) + 23) & 127;
  int stage_v_215_2 = ((stage_v_98_2 + pub_r000212_23_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((stage_v_196_1 + pub_r000212_16_1) + 43) & 127;
  int stage_v_216_2 = ((stage_v_196_2 + pub_r000212_16_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((sec_r000212_16_1 + pub_r000212_18_1) + 49) & 127;
  int stage_v_217_2 = ((sec_r000212_16_2 + pub_r000212_18_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((sec_r000212_12_1 + pub_r000212_0_1) + 12) & 127;
  int stage_v_218_2 = ((sec_r000212_12_2 + pub_r000212_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((stage_v_125_1 + pub_r000212_6_1) + 42) & 127;
  int stage_v_219_2 = ((stage_v_125_2 + pub_r000212_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((stage_v_199_1 + pub_r000212_20_1) + 20) & 127;
  int stage_v_220_2 = ((stage_v_199_2 + pub_r000212_20_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((sec_r000212_3_1 + pub_r000212_1_1) + 28) & 127;
  int stage_v_221_2 = ((sec_r000212_3_2 + pub_r000212_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((sec_r000212_15_1 + pub_r000212_19_1) + 30) & 127;
  int stage_v_222_2 = ((sec_r000212_15_2 + pub_r000212_19_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((stage_v_151_1 + pub_r000212_7_1) + 15) & 127;
  int stage_v_223_2 = ((stage_v_151_2 + pub_r000212_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((stage_v_195_1 + pub_r000212_23_1) + 48) & 127;
  int stage_v_224_2 = ((stage_v_195_2 + pub_r000212_23_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((sec_r000212_16_1 + pub_r000212_12_1) + 27) & 127;
  int stage_v_225_2 = ((sec_r000212_16_2 + pub_r000212_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((stage_v_166_1 + pub_r000212_5_1) + 46) & 127;
  int stage_v_226_2 = ((stage_v_166_2 + pub_r000212_5_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((sec_r000212_6_1 + pub_r000212_8_1) + 15) & 127;
  int stage_v_227_2 = ((sec_r000212_6_2 + pub_r000212_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((sec_r000212_12_1 + pub_r000212_19_1) + 24) & 127;
  int stage_v_228_2 = ((sec_r000212_12_2 + pub_r000212_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((sec_r000212_0_1 + pub_r000212_8_1) + 4) & 127;
  int stage_v_229_2 = ((sec_r000212_0_2 + pub_r000212_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((stage_v_159_1 + pub_r000212_6_1) + 42) & 127;
  int stage_v_230_2 = ((stage_v_159_2 + pub_r000212_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((sec_r000212_9_1 + pub_r000212_4_1) + 40) & 127;
  int stage_v_231_2 = ((sec_r000212_9_2 + pub_r000212_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((sec_r000212_7_1 + pub_r000212_8_1) + 37) & 127;
  int stage_v_232_2 = ((sec_r000212_7_2 + pub_r000212_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((sec_r000212_20_1 + pub_r000212_22_1) + 11) & 127;
  int stage_v_233_2 = ((sec_r000212_20_2 + pub_r000212_22_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((sec_r000212_7_1 + pub_r000212_5_1) + 6) & 127;
  int stage_v_234_2 = ((sec_r000212_7_2 + pub_r000212_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((sec_r000212_5_1 + pub_r000212_21_1) + 40) & 127;
  int stage_v_235_2 = ((sec_r000212_5_2 + pub_r000212_21_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((stage_v_208_1 + pub_r000212_1_1) + 15) & 127;
  int stage_v_236_2 = ((stage_v_208_2 + pub_r000212_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((stage_v_84_1 + pub_r000212_18_1) + 11) & 127;
  int stage_v_237_2 = ((stage_v_84_2 + pub_r000212_18_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((sec_r000212_2_1 + pub_r000212_10_1) + 41) & 127;
  int stage_v_238_2 = ((sec_r000212_2_2 + pub_r000212_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((stage_v_154_1 + pub_r000212_17_1) + 47) & 127;
  int stage_v_239_2 = ((stage_v_154_2 + pub_r000212_17_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((sec_r000212_10_1 + pub_r000212_16_1) + 7) & 127;
  int stage_v_240_2 = ((sec_r000212_10_2 + pub_r000212_16_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((stage_v_189_1 + pub_r000212_15_1) + 18) & 127;
  int stage_v_241_2 = ((stage_v_189_2 + pub_r000212_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((stage_v_183_1 + pub_r000212_1_1) + 5) & 127;
  int stage_v_242_2 = ((stage_v_183_2 + pub_r000212_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((stage_v_125_1 + pub_r000212_15_1) + 24) & 127;
  int stage_v_243_2 = ((stage_v_125_2 + pub_r000212_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((stage_v_82_1 + pub_r000212_8_1) + 47) & 127;
  int stage_v_244_2 = ((stage_v_82_2 + pub_r000212_8_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((stage_v_240_1 + pub_r000212_4_1) + 45) & 127;
  int stage_v_245_2 = ((stage_v_240_2 + pub_r000212_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((stage_v_131_1 + pub_r000212_20_1) + 12) & 127;
  int stage_v_246_2 = ((stage_v_131_2 + pub_r000212_20_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((sec_r000212_12_1 + pub_r000212_18_1) + 16) & 127;
  int stage_v_247_2 = ((sec_r000212_12_2 + pub_r000212_18_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((sec_r000212_14_1 + pub_r000212_3_1) + 45) & 127;
  int stage_v_248_2 = ((sec_r000212_14_2 + pub_r000212_3_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((stage_v_71_1 + pub_r000212_7_1) + 23) & 127;
  int stage_v_249_2 = ((stage_v_71_2 + pub_r000212_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((stage_v_82_1 + pub_r000212_12_1) + 30) & 127;
  int stage_v_250_2 = ((stage_v_82_2 + pub_r000212_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((stage_v_182_1 + pub_r000212_17_1) + 13) & 127;
  int stage_v_251_2 = ((stage_v_182_2 + pub_r000212_17_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((stage_v_239_1 + pub_r000212_12_1) + 25) & 127;
  int stage_v_252_2 = ((stage_v_239_2 + pub_r000212_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((stage_v_154_1 + pub_r000212_19_1) + 33) & 127;
  int stage_v_253_2 = ((stage_v_154_2 + pub_r000212_19_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((sec_r000212_0_1 + pub_r000212_14_1) + 3) & 127;
  int stage_v_254_2 = ((sec_r000212_0_2 + pub_r000212_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((stage_v_110_1 + pub_r000212_20_1) + 40) & 127;
  int stage_v_255_2 = ((stage_v_110_2 + pub_r000212_20_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((sec_r000212_3_1 + pub_r000212_12_1) + 33) & 127;
  int stage_v_256_2 = ((sec_r000212_3_2 + pub_r000212_12_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((stage_v_157_1 + pub_r000212_20_1) + 35) & 127;
  int stage_v_257_2 = ((stage_v_157_2 + pub_r000212_20_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((stage_v_96_1 + pub_r000212_22_1) + 16) & 127;
  int stage_v_258_2 = ((stage_v_96_2 + pub_r000212_22_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((stage_v_189_1 + pub_r000212_11_1) + 49) & 127;
  int stage_v_259_2 = ((stage_v_189_2 + pub_r000212_11_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((stage_v_180_1 + pub_r000212_10_1) + 17) & 127;
  int stage_v_260_2 = ((stage_v_180_2 + pub_r000212_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((sec_r000212_9_1 + pub_r000212_13_1) + 18) & 127;
  int stage_v_261_2 = ((sec_r000212_9_2 + pub_r000212_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((stage_v_129_1 + pub_r000212_17_1) + 9) & 127;
  int stage_v_262_2 = ((stage_v_129_2 + pub_r000212_17_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((sec_r000212_1_1 + pub_r000212_11_1) + 28) & 127;
  int stage_v_263_2 = ((sec_r000212_1_2 + pub_r000212_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((sec_r000212_18_1 + pub_r000212_6_1) + 28) & 127;
  int stage_v_264_2 = ((sec_r000212_18_2 + pub_r000212_6_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((sec_r000212_6_1 + pub_r000212_2_1) + 46) & 127;
  int stage_v_265_2 = ((sec_r000212_6_2 + pub_r000212_2_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((sec_r000212_7_1 + pub_r000212_18_1) + 3) & 127;
  int stage_v_266_2 = ((sec_r000212_7_2 + pub_r000212_18_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((sec_r000212_11_1 + pub_r000212_7_1) + 12) & 127;
  int stage_v_267_2 = ((sec_r000212_11_2 + pub_r000212_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((stage_v_236_1 + pub_r000212_4_1) + 22) & 127;
  int stage_v_268_2 = ((stage_v_236_2 + pub_r000212_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((sec_r000212_14_1 + pub_r000212_3_1) + 40) & 127;
  int stage_v_269_2 = ((sec_r000212_14_2 + pub_r000212_3_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((stage_v_73_1 + pub_r000212_4_1) + 23) & 127;
  int stage_v_270_2 = ((stage_v_73_2 + pub_r000212_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((stage_v_128_1 + pub_r000212_14_1) + 49) & 127;
  int stage_v_271_2 = ((stage_v_128_2 + pub_r000212_14_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((sec_r000212_9_1 + pub_r000212_16_1) + 14) & 127;
  int stage_v_272_2 = ((sec_r000212_9_2 + pub_r000212_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((stage_v_176_1 + pub_r000212_8_1) + 23) & 127;
  int stage_v_273_2 = ((stage_v_176_2 + pub_r000212_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((stage_v_139_1 + pub_r000212_15_1) + 10) & 127;
  int stage_v_274_2 = ((stage_v_139_2 + pub_r000212_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((stage_v_163_1 + pub_r000212_8_1) + 29) & 127;
  int stage_v_275_2 = ((stage_v_163_2 + pub_r000212_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((stage_v_273_1 + pub_r000212_18_1) + 35) & 127;
  int stage_v_276_2 = ((stage_v_273_2 + pub_r000212_18_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((stage_v_207_1 + pub_r000212_8_1) + 10) & 127;
  int stage_v_277_2 = ((stage_v_207_2 + pub_r000212_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((sec_r000212_2_1 + pub_r000212_16_1) + 14) & 127;
  int stage_v_278_2 = ((sec_r000212_2_2 + pub_r000212_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((sec_r000212_10_1 + pub_r000212_10_1) + 34) & 127;
  int stage_v_279_2 = ((sec_r000212_10_2 + pub_r000212_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((sec_r000212_12_1 + pub_r000212_11_1) + 20) & 127;
  int stage_v_280_2 = ((sec_r000212_12_2 + pub_r000212_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((stage_v_64_1 + pub_r000212_23_1) + 13) & 127;
  int stage_v_281_2 = ((stage_v_64_2 + pub_r000212_23_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((stage_v_207_1 + pub_r000212_0_1) + 15) & 127;
  int stage_v_282_2 = ((stage_v_207_2 + pub_r000212_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((stage_v_143_1 + pub_r000212_21_1) + 17) & 127;
  int stage_v_283_2 = ((stage_v_143_2 + pub_r000212_21_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((sec_r000212_14_1 + pub_r000212_12_1) + 28) & 127;
  int stage_v_284_2 = ((sec_r000212_14_2 + pub_r000212_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((stage_v_109_1 + pub_r000212_16_1) + 39) & 127;
  int stage_v_285_2 = ((stage_v_109_2 + pub_r000212_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((sec_r000212_20_1 + pub_r000212_7_1) + 9) & 127;
  int stage_v_286_2 = ((sec_r000212_20_2 + pub_r000212_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((stage_v_89_1 + pub_r000212_7_1) + 20) & 127;
  int stage_v_287_2 = ((stage_v_89_2 + pub_r000212_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((sec_r000212_2_1 + pub_r000212_18_1) + 47) & 127;
  int stage_v_288_2 = ((sec_r000212_2_2 + pub_r000212_18_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((stage_v_204_1 + pub_r000212_3_1) + 22) & 127;
  int stage_v_289_2 = ((stage_v_204_2 + pub_r000212_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((sec_r000212_7_1 + pub_r000212_22_1) + 43) & 127;
  int stage_v_290_2 = ((sec_r000212_7_2 + pub_r000212_22_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((stage_v_75_1 + pub_r000212_20_1) + 48) & 127;
  int stage_v_291_2 = ((stage_v_75_2 + pub_r000212_20_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((stage_v_218_1 + pub_r000212_17_1) + 24) & 127;
  int stage_v_292_2 = ((stage_v_218_2 + pub_r000212_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((stage_v_79_1 + pub_r000212_19_1) + 18) & 127;
  int stage_v_293_2 = ((stage_v_79_2 + pub_r000212_19_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((stage_v_259_1 + pub_r000212_5_1) + 45) & 127;
  int stage_v_294_2 = ((stage_v_259_2 + pub_r000212_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((sec_r000212_10_1 + pub_r000212_4_1) + 45) & 127;
  int stage_v_295_2 = ((sec_r000212_10_2 + pub_r000212_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((stage_v_287_1 + pub_r000212_22_1) + 7) & 127;
  int stage_v_296_2 = ((stage_v_287_2 + pub_r000212_22_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((stage_v_208_1 + pub_r000212_17_1) + 9) & 127;
  int stage_v_297_2 = ((stage_v_208_2 + pub_r000212_17_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((sec_r000212_13_1 + pub_r000212_10_1) + 3) & 127;
  int stage_v_298_2 = ((sec_r000212_13_2 + pub_r000212_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((stage_v_227_1 + pub_r000212_21_1) + 41) & 127;
  int stage_v_299_2 = ((stage_v_227_2 + pub_r000212_21_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((sec_r000212_20_1 + pub_r000212_5_1) + 31) & 127;
  int stage_v_300_2 = ((sec_r000212_20_2 + pub_r000212_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000212_0_1 == pub_r000212_0_2);
  __CPROVER_assume(pub_r000212_8_1 == pub_r000212_8_2);
  __CPROVER_assume(sec_r000212_6_1 != sec_r000212_6_2);
  __CPROVER_assume(pub_r000212_17_1 == pub_r000212_17_2);
  __CPROVER_assume(pub_r000212_19_1 == pub_r000212_19_2);
  __CPROVER_assume(pub_r000212_4_1 == pub_r000212_4_2);
  __CPROVER_assume(pub_r000212_23_1 == pub_r000212_23_2);
  __CPROVER_assume(pub_r000212_21_1 == pub_r000212_21_2);
  __CPROVER_assume(pub_r000212_12_1 == pub_r000212_12_2);
  __CPROVER_assume(sec_r000212_12_1 != sec_r000212_12_2);
  __CPROVER_assume(pub_r000212_3_1 == pub_r000212_3_2);
  __CPROVER_assume(pub_r000212_16_1 == pub_r000212_16_2);
  __CPROVER_assume(sec_r000212_15_1 != sec_r000212_15_2);
  __CPROVER_assume(pub_r000212_18_1 == pub_r000212_18_2);
  __CPROVER_assume(sec_r000212_19_1 != sec_r000212_19_2);
  __CPROVER_assume(sec_r000212_7_1 != sec_r000212_7_2);
  __CPROVER_assume(sec_r000212_18_1 != sec_r000212_18_2);
  __CPROVER_assume(pub_r000212_1_1 == pub_r000212_1_2);
  __CPROVER_assume(pub_r000212_20_1 == pub_r000212_20_2);
  __CPROVER_assume(sec_r000212_13_1 != sec_r000212_13_2);
  __CPROVER_assume(sec_r000212_4_1 != sec_r000212_4_2);
  __CPROVER_assume(sec_r000212_20_1 != sec_r000212_20_2);
  __CPROVER_assume(sec_r000212_3_1 != sec_r000212_3_2);
  __CPROVER_assume(sec_r000212_11_1 != sec_r000212_11_2);
  __CPROVER_assume(sec_r000212_5_1 != sec_r000212_5_2);
  __CPROVER_assume(sec_r000212_10_1 != sec_r000212_10_2);
  __CPROVER_assume(pub_r000212_9_1 == pub_r000212_9_2);
  __CPROVER_assume(pub_r000212_22_1 == pub_r000212_22_2);
  __CPROVER_assume(pub_r000212_11_1 == pub_r000212_11_2);
  __CPROVER_assume(sec_r000212_17_1 != sec_r000212_17_2);
  __CPROVER_assume(sec_r000212_2_1 != sec_r000212_2_2);
  __CPROVER_assume(pub_r000212_6_1 == pub_r000212_6_2);
  __CPROVER_assume(pub_r000212_13_1 == pub_r000212_13_2);
  __CPROVER_assume(sec_r000212_14_1 != sec_r000212_14_2);
  __CPROVER_assume(sec_r000212_1_1 != sec_r000212_1_2);
  __CPROVER_assume(pub_r000212_5_1 == pub_r000212_5_2);
  __CPROVER_assume(pub_r000212_2_1 == pub_r000212_2_2);
  __CPROVER_assume(pub_r000212_7_1 == pub_r000212_7_2);
  __CPROVER_assume(pub_r000212_15_1 == pub_r000212_15_2);
  __CPROVER_assume(sec_r000212_8_1 != sec_r000212_8_2);
  __CPROVER_assume(sec_r000212_0_1 != sec_r000212_0_2);
  __CPROVER_assume(pub_r000212_10_1 == pub_r000212_10_2);
  __CPROVER_assume(sec_r000212_9_1 != sec_r000212_9_2);
  __CPROVER_assume(pub_r000212_14_1 == pub_r000212_14_2);
  __CPROVER_assume(sec_r000212_16_1 != sec_r000212_16_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.port == st_var_0_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.balance == st_var_2_2.balance);
  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.nonce == st_var_3_2.nonce);
  assert(st_var_3_1.flags == st_var_3_2.flags);
  assert(st_var_3_1.round_key == st_var_3_2.round_key);
  assert(st_var_3_1.iv == st_var_3_2.iv);
  assert(st_var_3_1.counter == st_var_3_2.counter);
  assert(st_var_3_1.tag == st_var_3_2.tag);
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
}


