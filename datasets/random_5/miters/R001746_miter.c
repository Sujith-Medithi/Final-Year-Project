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
struct EventLog_R001746_4613_0
{
  int timestamp;
  int seq;
  unsigned char code;
  int buffer[3];
};
struct AudioFrame_R001746_4613_1
{
  short peak;
  short gain;
  unsigned char sample_rate;
  unsigned char rms;
  int buffer[3];
};
struct Transaction_R001746_4613_2
{
  unsigned char account_id;
  unsigned char status;
  int fee;
  int rate;
  short balance;
  int auth_code;
  int buffer[3];
};
struct CipherContext_R001746_4613_3
{
  int tag;
  short round_key;
  short nonce;
  int flags;
  int iv;
  int buffer[3];
};
union TelemetryField_R001746_4613_0
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
void fn_R001746_4613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st_1 = {0};
  struct AudioFrame_R001746_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int mask_42_1 = 0;
  int mask_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_42_1 = ((mask_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_42_2 = ((mask_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_42_1) & 127;
    acc_2 = (acc_2 + mask_42_2) & 127;
  }

  int anchor_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_41_1) & 63;
  aux_2 = (aux_2 + anchor_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_68_1)
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

  switch (sample_68_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_42_1 == mask_42_2);
  assert(anchor_41_1 == anchor_41_2);
  assert(sample_68_1 == sample_68_2);
}

int fn_R001746_4613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int mask_42 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_42 = ((mask_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_42) & 127;
  }

  int anchor_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_41) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_68 = (aux + st.buffer[1]) & 3;
  switch (sample_68)
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

void fn_R001746_4613_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st_1 = {0};
  struct AudioFrame_R001746_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int window_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_82_1)
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

  switch (window_82_2)
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

  int quotient_10_1 = 0;
  int quotient_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_10_1 = ((quotient_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_10_2 = ((quotient_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_10_1) & 127;
    acc_2 = (acc_2 + quotient_10_2) & 127;
  }

  int damping_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_27_1 > 31)
  {
    acc_1 = ((acc_1 + (damping_27_1 * 2)) + 5) & 127;
    aux_1 ^= damping_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_27_2 > 31)
  {
    acc_2 = ((acc_2 + (damping_27_2 * 2)) + 5) & 127;
    aux_2 ^= damping_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_27_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_82_1 == window_82_2);
  assert(quotient_10_1 == quotient_10_2);
  assert(damping_27_1 == damping_27_2);
}

int fn_R001746_4613_1(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int window_82 = (aux + st.buffer[1]) & 3;
  switch (window_82)
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

  int quotient_10 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_10 = ((quotient_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_10) & 127;
  }

  int damping_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_27 > 31)
  {
    acc = ((acc + (damping_27 * 2)) + 5) & 127;
    aux ^= damping_27 & 15;
  }
  else
  {
    acc = ((acc - damping_27) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001746_4613_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001746_4613_3 st_1 = {0};
  struct CipherContext_R001746_4613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int anchor_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_36_1) & 63;
  aux_2 = (aux_2 + anchor_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_30_1 = local_arr_1[aux_1 % 3];
  int sample_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_30_2 * 2)) & 127;
  int offset_71_1 = 0;
  int offset_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_71_1 = ((offset_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_71_2 = ((offset_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_71_1) & 127;
    acc_2 = (acc_2 + offset_71_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_36_1 == anchor_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_30_1 == sample_30_2);
  assert(offset_71_1 == offset_71_2);
}

int fn_R001746_4613_2(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001746_4613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int anchor_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_36) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_30 = local_arr[aux % 3];
  acc = (acc + (sample_30 * 2)) & 127;
  int offset_71 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_71 = ((offset_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_71) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001746_4613_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st_1 = {0};
  struct AudioFrame_R001746_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_35_1 > 13)
  {
    acc_1 = ((acc_1 + (quotient_35_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_35_2 > 13)
  {
    acc_2 = ((acc_2 + (quotient_35_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_35_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_35_1 == quotient_35_2);
}

int fn_R001746_4613_3(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_35 > 13)
  {
    acc = ((acc + (quotient_35 * 2)) + 5) & 127;
    aux ^= quotient_35 & 15;
  }
  else
  {
    acc = ((acc - quotient_35) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001746_4613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001746_4613_2 st_1 = {0};
  struct Transaction_R001746_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int weight_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_42_1) & 63;
  aux_2 = (aux_2 + weight_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_80_1)
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

  switch (index_reg_80_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_42_1 == weight_42_2);
  assert(index_reg_80_1 == index_reg_80_2);
}

int fn_R001746_4613_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001746_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int weight_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_42) & 63;
  acc ^= aux;
  int index_reg_80 = (aux + st.buffer[1]) & 3;
  switch (index_reg_80)
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

void fn_R001746_4613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st_1 = {0};
  struct AudioFrame_R001746_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int tally_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_79_1 > 35)
  {
    acc_1 = ((acc_1 + (tally_79_1 * 2)) + 5) & 127;
    aux_1 ^= tally_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_79_2 > 35)
  {
    acc_2 = ((acc_2 + (tally_79_2 * 2)) + 5) & 127;
    aux_2 ^= tally_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_11_1) & 63;
  aux_2 = (aux_2 + vector_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_20_1)
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

  switch (checksum_20_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_79_1 == tally_79_2);
  assert(vector_11_1 == vector_11_2);
  assert(checksum_20_1 == checksum_20_2);
}

int fn_R001746_4613_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int tally_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_79 > 35)
  {
    acc = ((acc + (tally_79 * 2)) + 5) & 127;
    aux ^= tally_79 & 15;
  }
  else
  {
    acc = ((acc - tally_79) + 11) & 127;
    aux += 3;
  }
  int vector_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_11) & 63;
  acc ^= aux;
  int checksum_20 = (aux + st.buffer[1]) & 3;
  switch (checksum_20)
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

void fn_R001746_4613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001746_4613_3 st_1 = {0};
  struct CipherContext_R001746_4613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_54_1 = 0;
  int weight_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_54_1 = ((weight_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_54_2 = ((weight_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_54_1) & 127;
    acc_2 = (acc_2 + weight_54_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_33_1 = local_arr_1[aux_1 % 3];
  int metric_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_33_2 * 2)) & 127;
  int factor_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_94_1 > 19)
  {
    acc_1 = ((acc_1 + (factor_94_1 * 2)) + 5) & 127;
    aux_1 ^= factor_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_94_2 > 19)
  {
    acc_2 = ((acc_2 + (factor_94_2 * 2)) + 5) & 127;
    aux_2 ^= factor_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_94_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_54_1 == weight_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_33_1 == metric_33_2);
  assert(factor_94_1 == factor_94_2);
}

int fn_R001746_4613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001746_4613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_54 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_54 = ((weight_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_54) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int metric_33 = local_arr[aux % 3];
  acc = (acc + (metric_33 * 2)) & 127;
  int factor_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_94 > 19)
  {
    acc = ((acc + (factor_94 * 2)) + 5) & 127;
    aux ^= factor_94 & 15;
  }
  else
  {
    acc = ((acc - factor_94) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001746_4613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001746_4613_2 st_1 = {0};
  struct Transaction_R001746_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_66_1 = 0;
  int sample_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_66_1 = ((sample_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_66_2 = ((sample_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_66_1) & 127;
    acc_2 = (acc_2 + sample_66_2) & 127;
  }

  int anchor_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_10_1)
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

  switch (anchor_10_2)
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

  int cursor_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_63_1) & 63;
  aux_2 = (aux_2 + cursor_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_66_1 == sample_66_2);
  assert(anchor_10_1 == anchor_10_2);
  assert(cursor_63_1 == cursor_63_2);
}

int fn_R001746_4613_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001746_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_66 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_66 = ((sample_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_66) & 127;
  }

  int anchor_10 = (aux + st.buffer[1]) & 3;
  switch (anchor_10)
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

  int cursor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_63) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001746_4613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001746_4613_2 st_1 = {0};
  struct Transaction_R001746_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int factor_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_20_1 > 41)
  {
    acc_1 = ((acc_1 + (factor_20_1 * 2)) + 5) & 127;
    aux_1 ^= factor_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_20_2 > 41)
  {
    acc_2 = ((acc_2 + (factor_20_2 * 2)) + 5) & 127;
    aux_2 ^= factor_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_62_1 = 0;
  int factor_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_62_1 = ((factor_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_62_2 = ((factor_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_62_1) & 127;
    acc_2 = (acc_2 + factor_62_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_20_1 == factor_20_2);
  assert(factor_62_1 == factor_62_2);
}

int fn_R001746_4613_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001746_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int factor_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_20 > 41)
  {
    acc = ((acc + (factor_20 * 2)) + 5) & 127;
    aux ^= factor_20 & 15;
  }
  else
  {
    acc = ((acc - factor_20) + 11) & 127;
    aux += 3;
  }
  int factor_62 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_62 = ((factor_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_62) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001746_4613_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001746_4613_0 st_1 = {0};
  struct EventLog_R001746_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int index_reg_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_16_1) & 63;
  aux_2 = (aux_2 + index_reg_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_31_1 = 0;
  int pivot_31_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_31_1 = ((pivot_31_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_31_2 = ((pivot_31_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_31_1) & 127;
    acc_2 = (acc_2 + pivot_31_2) & 127;
  }

  int delta_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_20_1)
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

  switch (delta_20_2)
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
  int tally_38_1 = local_arr_1[aux_1 % 3];
  int tally_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_38_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_16_1 == index_reg_16_2);
  assert(pivot_31_1 == pivot_31_2);
  assert(delta_20_1 == delta_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_38_1 == tally_38_2);
}

int fn_R001746_4613_9(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001746_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int index_reg_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_16) & 63;
  acc ^= aux;
  int pivot_31 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_31 = ((pivot_31 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_31) & 127;
  }

  int delta_20 = (aux + st.buffer[1]) & 3;
  switch (delta_20)
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
  int tally_38 = local_arr[aux % 3];
  acc = (acc + (tally_38 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001746_4613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st_1 = {0};
  struct AudioFrame_R001746_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int scale_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_22_1) & 63;
  aux_2 = (aux_2 + scale_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_35_1 = 0;
  int cursor_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_35_1 = ((cursor_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_35_2 = ((cursor_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_35_1) & 127;
    acc_2 = (acc_2 + cursor_35_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_77_1)
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

  switch (quotient_77_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_22_1 == scale_22_2);
  assert(cursor_35_1 == cursor_35_2);
  assert(quotient_77_1 == quotient_77_2);
}

int fn_R001746_4613_10(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int scale_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_22) & 63;
  acc ^= aux;
  int cursor_35 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_35 = ((cursor_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_35) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_77 = (aux + st.buffer[1]) & 3;
  switch (quotient_77)
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

void fn_R001746_4613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001746_4613_2 st_1 = {0};
  struct Transaction_R001746_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_74_1 = local_arr_1[aux_1 % 3];
  int tracker_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_74_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_58_1 = 0;
  int delta_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_58_1 = ((delta_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_58_2 = ((delta_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_58_1) & 127;
    acc_2 = (acc_2 + delta_58_2) & 127;
  }

  int cursor_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_45_1 > 48)
  {
    acc_1 = ((acc_1 + (cursor_45_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_45_2 > 48)
  {
    acc_2 = ((acc_2 + (cursor_45_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_45_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_74_1 == tracker_74_2);
  assert(delta_58_1 == delta_58_2);
  assert(cursor_45_1 == cursor_45_2);
}

int fn_R001746_4613_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001746_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int tracker_74 = local_arr[aux % 3];
  acc = (acc + (tracker_74 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_58 = ((delta_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_58) & 127;
  }

  int cursor_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_45 > 48)
  {
    acc = ((acc + (cursor_45 * 2)) + 5) & 127;
    aux ^= cursor_45 & 15;
  }
  else
  {
    acc = ((acc - cursor_45) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001746_4613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st_1 = {0};
  struct AudioFrame_R001746_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int cursor_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_67_1)
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

  switch (cursor_67_2)
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
  int bound_23_1 = local_arr_1[aux_1 % 3];
  int bound_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_23_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_16_1) & 63;
  aux_2 = (aux_2 + tally_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_67_1 == cursor_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_23_1 == bound_23_2);
  assert(tally_16_1 == tally_16_2);
}

int fn_R001746_4613_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int cursor_67 = (aux + st.buffer[1]) & 3;
  switch (cursor_67)
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
  int bound_23 = local_arr[aux % 3];
  acc = (acc + (bound_23 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001746_4613_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001746_4613_2 st_1 = {0};
  struct Transaction_R001746_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_61_1 = local_arr_1[aux_1 % 3];
  int index_reg_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_61_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_60_1)
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

  switch (bound_60_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_61_1 == index_reg_61_2);
  assert(bound_60_1 == bound_60_2);
}

int fn_R001746_4613_13(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001746_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int index_reg_61 = local_arr[aux % 3];
  acc = (acc + (index_reg_61 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_60 = (aux + st.buffer[1]) & 3;
  switch (bound_60)
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

void fn_R001746_4613_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001746_4613_2 st_1 = {0};
  struct Transaction_R001746_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int bound_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_60_1) & 63;
  aux_2 = (aux_2 + bound_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_89_1 = 0;
  int quotient_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_89_1 = ((quotient_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_89_2 = ((quotient_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_89_1) & 127;
    acc_2 = (acc_2 + quotient_89_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_60_1 == bound_60_2);
  assert(quotient_89_1 == quotient_89_2);
}

int fn_R001746_4613_14(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001746_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int bound_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_60) & 63;
  acc ^= aux;
  int quotient_89 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_89 = ((quotient_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_89) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001746_4613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st_1 = {0};
  struct AudioFrame_R001746_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int damping_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_70_1 > 35)
  {
    acc_1 = ((acc_1 + (damping_70_1 * 2)) + 5) & 127;
    aux_1 ^= damping_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_70_2 > 35)
  {
    acc_2 = ((acc_2 + (damping_70_2 * 2)) + 5) & 127;
    aux_2 ^= damping_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_80_1 = local_arr_1[aux_1 % 3];
  int vector_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_80_2 * 2)) & 127;
  int scale_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_65_1)
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

  switch (scale_65_2)
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

  int phase_11_1 = 0;
  int phase_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_11_1 = ((phase_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_11_2 = ((phase_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_11_1) & 127;
    acc_2 = (acc_2 + phase_11_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_70_1 == damping_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_80_1 == vector_80_2);
  assert(scale_65_1 == scale_65_2);
  assert(phase_11_1 == phase_11_2);
}

int fn_R001746_4613_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int damping_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_70 > 35)
  {
    acc = ((acc + (damping_70 * 2)) + 5) & 127;
    aux ^= damping_70 & 15;
  }
  else
  {
    acc = ((acc - damping_70) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_80 = local_arr[aux % 3];
  acc = (acc + (vector_80 * 2)) & 127;
  int scale_65 = (aux + st.buffer[1]) & 3;
  switch (scale_65)
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

  int phase_11 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_11 = ((phase_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_11) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001746_4613_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st_1 = {0};
  struct AudioFrame_R001746_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int quotient_82_1 = 0;
  int quotient_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_82_1 = ((quotient_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_82_2 = ((quotient_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_82_1) & 127;
    acc_2 = (acc_2 + quotient_82_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_90_1) & 63;
  aux_2 = (aux_2 + parity_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_82_1 == quotient_82_2);
  assert(parity_90_1 == parity_90_2);
}

int fn_R001746_4613_16(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int quotient_82 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_82 = ((quotient_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_82) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_90) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001746_4613_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st_1 = {0};
  struct AudioFrame_R001746_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int quantum_44_1 = 0;
  int quantum_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_44_1 = ((quantum_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_44_2 = ((quantum_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_44_1) & 127;
    acc_2 = (acc_2 + quantum_44_2) & 127;
  }

  int coefficient_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_28_1 > 36)
  {
    acc_1 = ((acc_1 + (coefficient_28_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_28_2 > 36)
  {
    acc_2 = ((acc_2 + (coefficient_28_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_28_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_64_1 = local_arr_1[aux_1 % 3];
  int cursor_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_64_2 * 2)) & 127;
  int checksum_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_76_1) & 63;
  aux_2 = (aux_2 + checksum_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_44_1 == quantum_44_2);
  assert(coefficient_28_1 == coefficient_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_64_1 == cursor_64_2);
  assert(checksum_76_1 == checksum_76_2);
}

int fn_R001746_4613_17(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int quantum_44 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_44 = ((quantum_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_44) & 127;
  }

  int coefficient_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_28 > 36)
  {
    acc = ((acc + (coefficient_28 * 2)) + 5) & 127;
    aux ^= coefficient_28 & 15;
  }
  else
  {
    acc = ((acc - coefficient_28) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_64 = local_arr[aux % 3];
  acc = (acc + (cursor_64 * 2)) & 127;
  int checksum_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_76) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001746_4613_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001746_4613_2 st_1 = {0};
  struct Transaction_R001746_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int quantum_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_79_1) & 63;
  aux_2 = (aux_2 + quantum_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_98_1)
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

  switch (bound_98_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_79_1 == quantum_79_2);
  assert(bound_98_1 == bound_98_2);
}

int fn_R001746_4613_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001746_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int quantum_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_79) & 63;
  acc ^= aux;
  int bound_98 = (aux + st.buffer[1]) & 3;
  switch (bound_98)
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

void fn_R001746_4613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st_1 = {0};
  struct AudioFrame_R001746_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int accumulator_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_18_1)
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

  switch (accumulator_18_2)
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
  int factor_53_1 = local_arr_1[aux_1 % 3];
  int factor_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_53_2 * 2)) & 127;
  int anchor_34_1 = 0;
  int anchor_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_34_1 = ((anchor_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_34_2 = ((anchor_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_34_1) & 127;
    acc_2 = (acc_2 + anchor_34_2) & 127;
  }

  int mask_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_96_1) & 63;
  aux_2 = (aux_2 + mask_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_18_1 == accumulator_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_53_1 == factor_53_2);
  assert(anchor_34_1 == anchor_34_2);
  assert(mask_96_1 == mask_96_2);
}

int fn_R001746_4613_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int accumulator_18 = (aux + st.buffer[1]) & 3;
  switch (accumulator_18)
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
  int factor_53 = local_arr[aux % 3];
  acc = (acc + (factor_53 * 2)) & 127;
  int anchor_34 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_34 = ((anchor_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_34) & 127;
  }

  int mask_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001746_4613_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st_1 = {0};
  struct AudioFrame_R001746_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_79_1 = local_arr_1[aux_1 % 3];
  int stride_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_79_2 * 2)) & 127;
  int weight_65_1 = 0;
  int weight_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_65_1 = ((weight_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_65_2 = ((weight_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_65_1) & 127;
    acc_2 = (acc_2 + weight_65_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_23_1)
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

  switch (index_reg_23_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_79_1 == stride_79_2);
  assert(weight_65_1 == weight_65_2);
  assert(index_reg_23_1 == index_reg_23_2);
}

int fn_R001746_4613_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001746_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int stride_79 = local_arr[aux % 3];
  acc = (acc + (stride_79 * 2)) & 127;
  int weight_65 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_65 = ((weight_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_65) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_23 = (aux + st.buffer[1]) & 3;
  switch (index_reg_23)
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

void fn_R001746_4613_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001746_4613_0 st_1 = {0};
  struct EventLog_R001746_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int sample_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_49_1 > 19)
  {
    acc_1 = ((acc_1 + (sample_49_1 * 2)) + 5) & 127;
    aux_1 ^= sample_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_49_2 > 19)
  {
    acc_2 = ((acc_2 + (sample_49_2 * 2)) + 5) & 127;
    aux_2 ^= sample_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_49_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_72_1)
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

  switch (residue_72_2)
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

  int index_reg_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_37_1) & 63;
  aux_2 = (aux_2 + index_reg_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_49_1 == sample_49_2);
  assert(residue_72_1 == residue_72_2);
  assert(index_reg_37_1 == index_reg_37_2);
}

int fn_R001746_4613_21(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001746_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int sample_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_49 > 19)
  {
    acc = ((acc + (sample_49 * 2)) + 5) & 127;
    aux ^= sample_49 & 15;
  }
  else
  {
    acc = ((acc - sample_49) + 11) & 127;
    aux += 3;
  }
  int residue_72 = (aux + st.buffer[1]) & 3;
  switch (residue_72)
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

  int index_reg_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_37) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001746_4613_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001746_4613_0 st_1 = {0};
  struct EventLog_R001746_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int quantum_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_31_1)
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

  switch (quantum_31_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_32_1 = local_arr_1[aux_1 % 3];
  int parity_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_31_1 == quantum_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_32_1 == parity_32_2);
}

int fn_R001746_4613_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001746_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int quantum_31 = (aux + st.buffer[1]) & 3;
  switch (quantum_31)
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

  int local_arr[3] = {4, 9, 15};
  int parity_32 = local_arr[aux % 3];
  acc = (acc + (parity_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001746_0_1;
  int sec_r001746_0_2;
  int sec_r001746_1_1;
  int sec_r001746_1_2;
  int sec_r001746_2_1;
  int sec_r001746_2_2;
  int sec_r001746_3_1;
  int sec_r001746_3_2;
  int sec_r001746_4_1;
  int sec_r001746_4_2;
  int sec_r001746_5_1;
  int sec_r001746_5_2;
  int sec_r001746_6_1;
  int sec_r001746_6_2;
  int sec_r001746_7_1;
  int sec_r001746_7_2;
  int sec_r001746_8_1;
  int sec_r001746_8_2;
  int sec_r001746_9_1;
  int sec_r001746_9_2;
  int sec_r001746_10_1;
  int sec_r001746_10_2;
  int sec_r001746_11_1;
  int sec_r001746_11_2;
  int sec_r001746_12_1;
  int sec_r001746_12_2;
  int sec_r001746_13_1;
  int sec_r001746_13_2;
  int sec_r001746_14_1;
  int sec_r001746_14_2;
  int sec_r001746_15_1;
  int sec_r001746_15_2;
  int pub_r001746_0_1;
  int pub_r001746_0_2;
  int pub_r001746_1_1;
  int pub_r001746_1_2;
  int pub_r001746_2_1;
  int pub_r001746_2_2;
  int pub_r001746_3_1;
  int pub_r001746_3_2;
  int pub_r001746_4_1;
  int pub_r001746_4_2;
  int pub_r001746_5_1;
  int pub_r001746_5_2;
  int pub_r001746_6_1;
  int pub_r001746_6_2;
  int pub_r001746_7_1;
  int pub_r001746_7_2;
  int pub_r001746_8_1;
  int pub_r001746_8_2;
  int pub_r001746_9_1;
  int pub_r001746_9_2;
  int pub_r001746_10_1;
  int pub_r001746_10_2;
  int pub_r001746_11_1;
  int pub_r001746_11_2;
  int pub_r001746_12_1;
  int pub_r001746_12_2;
  int pub_r001746_13_1;
  int pub_r001746_13_2;
  int pub_r001746_14_1;
  int pub_r001746_14_2;
  int pub_r001746_15_1;
  int pub_r001746_15_2;
  int pub_r001746_16_1;
  int pub_r001746_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001746_0_1 >= (-100)) && (pub_r001746_0_1 <= 100));
  __CPROVER_assume((pub_r001746_0_2 >= (-100)) && (pub_r001746_0_2 <= 100));
  __CPROVER_assume((pub_r001746_1_1 >= (-100)) && (pub_r001746_1_1 <= 100));
  __CPROVER_assume((pub_r001746_1_2 >= (-100)) && (pub_r001746_1_2 <= 100));
  __CPROVER_assume((pub_r001746_2_1 >= (-100)) && (pub_r001746_2_1 <= 100));
  __CPROVER_assume((pub_r001746_2_2 >= (-100)) && (pub_r001746_2_2 <= 100));
  __CPROVER_assume((pub_r001746_3_1 >= (-100)) && (pub_r001746_3_1 <= 100));
  __CPROVER_assume((pub_r001746_3_2 >= (-100)) && (pub_r001746_3_2 <= 100));
  __CPROVER_assume((pub_r001746_4_1 >= (-100)) && (pub_r001746_4_1 <= 100));
  __CPROVER_assume((pub_r001746_4_2 >= (-100)) && (pub_r001746_4_2 <= 100));
  __CPROVER_assume((pub_r001746_5_1 >= (-100)) && (pub_r001746_5_1 <= 100));
  __CPROVER_assume((pub_r001746_5_2 >= (-100)) && (pub_r001746_5_2 <= 100));
  __CPROVER_assume((pub_r001746_6_1 >= (-100)) && (pub_r001746_6_1 <= 100));
  __CPROVER_assume((pub_r001746_6_2 >= (-100)) && (pub_r001746_6_2 <= 100));
  __CPROVER_assume((pub_r001746_7_1 >= (-100)) && (pub_r001746_7_1 <= 100));
  __CPROVER_assume((pub_r001746_7_2 >= (-100)) && (pub_r001746_7_2 <= 100));
  __CPROVER_assume((pub_r001746_8_1 >= (-100)) && (pub_r001746_8_1 <= 100));
  __CPROVER_assume((pub_r001746_8_2 >= (-100)) && (pub_r001746_8_2 <= 100));
  __CPROVER_assume((pub_r001746_9_1 >= (-100)) && (pub_r001746_9_1 <= 100));
  __CPROVER_assume((pub_r001746_9_2 >= (-100)) && (pub_r001746_9_2 <= 100));
  __CPROVER_assume((pub_r001746_10_1 >= (-100)) && (pub_r001746_10_1 <= 100));
  __CPROVER_assume((pub_r001746_10_2 >= (-100)) && (pub_r001746_10_2 <= 100));
  __CPROVER_assume((pub_r001746_11_1 >= (-100)) && (pub_r001746_11_1 <= 100));
  __CPROVER_assume((pub_r001746_11_2 >= (-100)) && (pub_r001746_11_2 <= 100));
  __CPROVER_assume((pub_r001746_12_1 >= (-100)) && (pub_r001746_12_1 <= 100));
  __CPROVER_assume((pub_r001746_12_2 >= (-100)) && (pub_r001746_12_2 <= 100));
  __CPROVER_assume((pub_r001746_13_1 >= (-100)) && (pub_r001746_13_1 <= 100));
  __CPROVER_assume((pub_r001746_13_2 >= (-100)) && (pub_r001746_13_2 <= 100));
  __CPROVER_assume((pub_r001746_14_1 >= (-100)) && (pub_r001746_14_1 <= 100));
  __CPROVER_assume((pub_r001746_14_2 >= (-100)) && (pub_r001746_14_2 <= 100));
  __CPROVER_assume((pub_r001746_15_1 >= (-100)) && (pub_r001746_15_1 <= 100));
  __CPROVER_assume((pub_r001746_15_2 >= (-100)) && (pub_r001746_15_2 <= 100));
  __CPROVER_assume((pub_r001746_16_1 >= (-100)) && (pub_r001746_16_1 <= 100));
  __CPROVER_assume((pub_r001746_16_2 >= (-100)) && (pub_r001746_16_2 <= 100));
  __CPROVER_assume((sec_r001746_0_1 >= 0) && (sec_r001746_0_1 <= 255));
  __CPROVER_assume((sec_r001746_0_2 >= 0) && (sec_r001746_0_2 <= 255));
  __CPROVER_assume((sec_r001746_1_1 >= 0) && (sec_r001746_1_1 <= 255));
  __CPROVER_assume((sec_r001746_1_2 >= 0) && (sec_r001746_1_2 <= 255));
  __CPROVER_assume((sec_r001746_2_1 >= 0) && (sec_r001746_2_1 <= 255));
  __CPROVER_assume((sec_r001746_2_2 >= 0) && (sec_r001746_2_2 <= 255));
  __CPROVER_assume((sec_r001746_3_1 >= 0) && (sec_r001746_3_1 <= 255));
  __CPROVER_assume((sec_r001746_3_2 >= 0) && (sec_r001746_3_2 <= 255));
  __CPROVER_assume((sec_r001746_4_1 >= 0) && (sec_r001746_4_1 <= 255));
  __CPROVER_assume((sec_r001746_4_2 >= 0) && (sec_r001746_4_2 <= 255));
  __CPROVER_assume((sec_r001746_5_1 >= 0) && (sec_r001746_5_1 <= 255));
  __CPROVER_assume((sec_r001746_5_2 >= 0) && (sec_r001746_5_2 <= 255));
  __CPROVER_assume((sec_r001746_6_1 >= 0) && (sec_r001746_6_1 <= 255));
  __CPROVER_assume((sec_r001746_6_2 >= 0) && (sec_r001746_6_2 <= 255));
  __CPROVER_assume((sec_r001746_7_1 >= 0) && (sec_r001746_7_1 <= 255));
  __CPROVER_assume((sec_r001746_7_2 >= 0) && (sec_r001746_7_2 <= 255));
  __CPROVER_assume((sec_r001746_8_1 >= 0) && (sec_r001746_8_1 <= 255));
  __CPROVER_assume((sec_r001746_8_2 >= 0) && (sec_r001746_8_2 <= 255));
  __CPROVER_assume((sec_r001746_9_1 >= 0) && (sec_r001746_9_1 <= 255));
  __CPROVER_assume((sec_r001746_9_2 >= 0) && (sec_r001746_9_2 <= 255));
  __CPROVER_assume((sec_r001746_10_1 >= 0) && (sec_r001746_10_1 <= 255));
  __CPROVER_assume((sec_r001746_10_2 >= 0) && (sec_r001746_10_2 <= 255));
  __CPROVER_assume((sec_r001746_11_1 >= 0) && (sec_r001746_11_1 <= 255));
  __CPROVER_assume((sec_r001746_11_2 >= 0) && (sec_r001746_11_2 <= 255));
  __CPROVER_assume((sec_r001746_12_1 >= 0) && (sec_r001746_12_1 <= 255));
  __CPROVER_assume((sec_r001746_12_2 >= 0) && (sec_r001746_12_2 <= 255));
  __CPROVER_assume((sec_r001746_13_1 >= 0) && (sec_r001746_13_1 <= 255));
  __CPROVER_assume((sec_r001746_13_2 >= 0) && (sec_r001746_13_2 <= 255));
  __CPROVER_assume((sec_r001746_14_1 >= 0) && (sec_r001746_14_1 <= 255));
  __CPROVER_assume((sec_r001746_14_2 >= 0) && (sec_r001746_14_2 <= 255));
  __CPROVER_assume((sec_r001746_15_1 >= 0) && (sec_r001746_15_1 <= 255));
  __CPROVER_assume((sec_r001746_15_2 >= 0) && (sec_r001746_15_2 <= 255));
  struct EventLog_R001746_4613_0 st_var_0_1 = {0};
  struct EventLog_R001746_4613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001746_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001746_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001746_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001746_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001746_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001746_0_2 + 7) & 15;
  struct AudioFrame_R001746_4613_1 st_var_1_1 = {0};
  struct AudioFrame_R001746_4613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001746_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001746_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001746_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001746_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001746_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001746_0_2 + 9) & 15;
  struct Transaction_R001746_4613_2 st_var_2_1 = {0};
  struct Transaction_R001746_4613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001746_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001746_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001746_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001746_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001746_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001746_0_2 + 11) & 15;
  struct CipherContext_R001746_4613_3 st_var_3_1 = {0};
  struct CipherContext_R001746_4613_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001746_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001746_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001746_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001746_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001746_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001746_0_2 + 13) & 15;
  union TelemetryField_R001746_4613_0 u_var_1;
  union TelemetryField_R001746_4613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001746_4613_0(sec_r001746_0_1, pub_r001746_1_1, pub_r001746_2_1, pub_r001746_3_1);
  int helper_flow_0_2 = fn_R001746_4613_0(sec_r001746_0_2, pub_r001746_1_2, pub_r001746_2_2, pub_r001746_3_2);
  fn_R001746_4613_0_2(sec_r001746_0_1, pub_r001746_1_1, pub_r001746_2_1, pub_r001746_3_1, sec_r001746_0_2, pub_r001746_1_2, pub_r001746_2_2, pub_r001746_3_2);
  int helper_flow_1_1 = fn_R001746_4613_1(sec_r001746_1_1, sec_r001746_2_1, pub_r001746_3_1);
  int helper_flow_1_2 = fn_R001746_4613_1(sec_r001746_1_2, sec_r001746_2_2, pub_r001746_3_2);
  fn_R001746_4613_1_2(sec_r001746_1_1, sec_r001746_2_1, pub_r001746_3_1, sec_r001746_1_2, sec_r001746_2_2, pub_r001746_3_2);
  int helper_flow_2_1 = fn_R001746_4613_2(sec_r001746_2_1, pub_r001746_3_1, pub_r001746_4_1);
  int helper_flow_2_2 = fn_R001746_4613_2(sec_r001746_2_2, pub_r001746_3_2, pub_r001746_4_2);
  fn_R001746_4613_2_2(sec_r001746_2_1, pub_r001746_3_1, pub_r001746_4_1, sec_r001746_2_2, pub_r001746_3_2, pub_r001746_4_2);
  int helper_flow_3_1 = fn_R001746_4613_3(sec_r001746_3_1, sec_r001746_4_1, pub_r001746_5_1);
  int helper_flow_3_2 = fn_R001746_4613_3(sec_r001746_3_2, sec_r001746_4_2, pub_r001746_5_2);
  fn_R001746_4613_3_2(sec_r001746_3_1, sec_r001746_4_1, pub_r001746_5_1, sec_r001746_3_2, sec_r001746_4_2, pub_r001746_5_2);
  int helper_flow_4_1 = fn_R001746_4613_4(sec_r001746_4_1, pub_r001746_5_1, pub_r001746_6_1, pub_r001746_7_1, pub_r001746_8_1);
  int helper_flow_4_2 = fn_R001746_4613_4(sec_r001746_4_2, pub_r001746_5_2, pub_r001746_6_2, pub_r001746_7_2, pub_r001746_8_2);
  fn_R001746_4613_4_2(sec_r001746_4_1, pub_r001746_5_1, pub_r001746_6_1, pub_r001746_7_1, pub_r001746_8_1, sec_r001746_4_2, pub_r001746_5_2, pub_r001746_6_2, pub_r001746_7_2, pub_r001746_8_2);
  int helper_flow_5_1 = fn_R001746_4613_5(sec_r001746_5_1, sec_r001746_6_1, pub_r001746_7_1, pub_r001746_8_1, pub_r001746_9_1);
  int helper_flow_5_2 = fn_R001746_4613_5(sec_r001746_5_2, sec_r001746_6_2, pub_r001746_7_2, pub_r001746_8_2, pub_r001746_9_2);
  fn_R001746_4613_5_2(sec_r001746_5_1, sec_r001746_6_1, pub_r001746_7_1, pub_r001746_8_1, pub_r001746_9_1, sec_r001746_5_2, sec_r001746_6_2, pub_r001746_7_2, pub_r001746_8_2, pub_r001746_9_2);
  int helper_flow_6_1 = fn_R001746_4613_6(sec_r001746_6_1, sec_r001746_7_1, pub_r001746_8_1, pub_r001746_9_1, pub_r001746_10_1);
  int helper_flow_6_2 = fn_R001746_4613_6(sec_r001746_6_2, sec_r001746_7_2, pub_r001746_8_2, pub_r001746_9_2, pub_r001746_10_2);
  fn_R001746_4613_6_2(sec_r001746_6_1, sec_r001746_7_1, pub_r001746_8_1, pub_r001746_9_1, pub_r001746_10_1, sec_r001746_6_2, sec_r001746_7_2, pub_r001746_8_2, pub_r001746_9_2, pub_r001746_10_2);
  int helper_flow_7_1 = fn_R001746_4613_7(sec_r001746_7_1, pub_r001746_8_1, pub_r001746_9_1, pub_r001746_10_1);
  int helper_flow_7_2 = fn_R001746_4613_7(sec_r001746_7_2, pub_r001746_8_2, pub_r001746_9_2, pub_r001746_10_2);
  fn_R001746_4613_7_2(sec_r001746_7_1, pub_r001746_8_1, pub_r001746_9_1, pub_r001746_10_1, sec_r001746_7_2, pub_r001746_8_2, pub_r001746_9_2, pub_r001746_10_2);
  int helper_flow_8_1 = fn_R001746_4613_8(sec_r001746_8_1, sec_r001746_9_1, pub_r001746_10_1, pub_r001746_11_1, pub_r001746_12_1);
  int helper_flow_8_2 = fn_R001746_4613_8(sec_r001746_8_2, sec_r001746_9_2, pub_r001746_10_2, pub_r001746_11_2, pub_r001746_12_2);
  fn_R001746_4613_8_2(sec_r001746_8_1, sec_r001746_9_1, pub_r001746_10_1, pub_r001746_11_1, pub_r001746_12_1, sec_r001746_8_2, sec_r001746_9_2, pub_r001746_10_2, pub_r001746_11_2, pub_r001746_12_2);
  int helper_flow_9_1 = fn_R001746_4613_9(sec_r001746_9_1, sec_r001746_10_1);
  int helper_flow_9_2 = fn_R001746_4613_9(sec_r001746_9_2, sec_r001746_10_2);
  fn_R001746_4613_9_2(sec_r001746_9_1, sec_r001746_10_1, sec_r001746_9_2, sec_r001746_10_2);
  int stage_v_0_1 = ((pub_r001746_15_1 * 2) + 14) & 63;
  int stage_v_0_2 = ((pub_r001746_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((sec_r001746_15_1 + (pub_r001746_15_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001746_15_2 + (pub_r001746_15_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((pub_r001746_8_1 * 2) + 35) & 63;
  int stage_v_2_2 = ((pub_r001746_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((sec_r001746_11_1 + (pub_r001746_16_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001746_11_2 + (pub_r001746_16_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((helper_flow_6_1 + (pub_r001746_4_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((helper_flow_6_2 + (pub_r001746_4_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((pub_r001746_9_1 * 2) + 35) & 63;
  int stage_v_5_2 = ((pub_r001746_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001746_9_1 * 2) + 38) & 63;
  int stage_v_6_2 = ((pub_r001746_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001746_0_1 * 2) + 46) & 63;
  int stage_v_7_2 = ((pub_r001746_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001746_4_1 * 2) + 29) & 63;
  int stage_v_8_2 = ((pub_r001746_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001746_10_1 * 2) + 28) & 63;
  int stage_v_9_2 = ((pub_r001746_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((sec_r001746_12_1 + (pub_r001746_4_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((sec_r001746_12_2 + (pub_r001746_4_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((helper_flow_1_1 + (pub_r001746_15_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((helper_flow_1_2 + (pub_r001746_15_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((helper_flow_7_1 + (pub_r001746_7_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((helper_flow_7_2 + (pub_r001746_7_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((sec_r001746_0_1 + (pub_r001746_11_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001746_0_2 + (pub_r001746_11_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((sec_r001746_7_1 + (pub_r001746_0_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((sec_r001746_7_2 + (pub_r001746_0_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((stage_v_12_1 + (pub_r001746_1_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((stage_v_12_2 + (pub_r001746_1_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((sec_r001746_13_1 + (pub_r001746_3_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((sec_r001746_13_2 + (pub_r001746_3_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((sec_r001746_11_1 + (pub_r001746_9_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001746_11_2 + (pub_r001746_9_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((pub_r001746_13_1 * 2) + 46) & 63;
  int stage_v_18_2 = ((pub_r001746_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001746_0_1 * 2) + 44) & 63;
  int stage_v_19_2 = ((pub_r001746_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((helper_flow_8_1 + (pub_r001746_9_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((helper_flow_8_2 + (pub_r001746_9_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((pub_r001746_14_1 * 2) + 27) & 63;
  int stage_v_21_2 = ((pub_r001746_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((sec_r001746_0_1 + (pub_r001746_3_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((sec_r001746_0_2 + (pub_r001746_3_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((helper_flow_4_1 + (pub_r001746_0_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((helper_flow_4_2 + (pub_r001746_0_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((pub_r001746_3_1 * 2) + 11) & 63;
  int stage_v_24_2 = ((pub_r001746_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((sec_r001746_4_1 + (pub_r001746_1_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((sec_r001746_4_2 + (pub_r001746_1_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((pub_r001746_16_1 * 2) + 27) & 63;
  int stage_v_26_2 = ((pub_r001746_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001746_0_1 * 2) + 26) & 63;
  int stage_v_27_2 = ((pub_r001746_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((sec_r001746_9_1 + (pub_r001746_0_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((sec_r001746_9_2 + (pub_r001746_0_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((sec_r001746_5_1 + (pub_r001746_1_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001746_5_2 + (pub_r001746_1_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((pub_r001746_13_1 * 2) + 41) & 63;
  int stage_v_30_2 = ((pub_r001746_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((helper_flow_1_1 + (pub_r001746_6_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((helper_flow_1_2 + (pub_r001746_6_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((sec_r001746_6_1 + (pub_r001746_1_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((sec_r001746_6_2 + (pub_r001746_1_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((stage_v_17_1 + (pub_r001746_10_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((stage_v_17_2 + (pub_r001746_10_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((helper_flow_9_1 + (pub_r001746_5_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((helper_flow_9_2 + (pub_r001746_5_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((pub_r001746_1_1 * 2) + 25) & 63;
  int stage_v_35_2 = ((pub_r001746_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((stage_v_32_1 + (pub_r001746_12_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((stage_v_32_2 + (pub_r001746_12_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((pub_r001746_10_1 * 2) + 46) & 63;
  int stage_v_37_2 = ((pub_r001746_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((sec_r001746_14_1 + (pub_r001746_14_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((sec_r001746_14_2 + (pub_r001746_14_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((pub_r001746_3_1 * 2) + 41) & 63;
  int stage_v_39_2 = ((pub_r001746_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((sec_r001746_15_1 + (pub_r001746_10_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((sec_r001746_15_2 + (pub_r001746_10_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((stage_v_17_1 + (pub_r001746_4_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((stage_v_17_2 + (pub_r001746_4_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((helper_flow_4_1 + (pub_r001746_2_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((helper_flow_4_2 + (pub_r001746_2_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((helper_flow_1_1 + (pub_r001746_14_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((helper_flow_1_2 + (pub_r001746_14_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((helper_flow_9_1 + (pub_r001746_7_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((helper_flow_9_2 + (pub_r001746_7_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((helper_flow_0_1 + (pub_r001746_7_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((helper_flow_0_2 + (pub_r001746_7_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((stage_v_22_1 + (pub_r001746_13_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((stage_v_22_2 + (pub_r001746_13_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((pub_r001746_6_1 * 2) + 13) & 63;
  int stage_v_47_2 = ((pub_r001746_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((stage_v_4_1 + (pub_r001746_16_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((stage_v_4_2 + (pub_r001746_16_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((stage_v_48_1 + (pub_r001746_2_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((stage_v_48_2 + (pub_r001746_2_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((stage_v_23_1 + (pub_r001746_15_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((stage_v_23_2 + (pub_r001746_15_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((pub_r001746_11_1 * 2) + 28) & 63;
  int stage_v_51_2 = ((pub_r001746_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001746_8_1 * 2) + 39) & 63;
  int stage_v_52_2 = ((pub_r001746_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001746_14_1 * 2) + 45) & 63;
  int stage_v_53_2 = ((pub_r001746_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001746_13_1 * 2) + 6) & 63;
  int stage_v_54_2 = ((pub_r001746_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((helper_flow_9_1 + (pub_r001746_16_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((helper_flow_9_2 + (pub_r001746_16_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((pub_r001746_0_1 * 2) + 41) & 63;
  int stage_v_56_2 = ((pub_r001746_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((stage_v_50_1 + (pub_r001746_2_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_50_2 + (pub_r001746_2_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((pub_r001746_10_1 * 2) + 32) & 63;
  int stage_v_58_2 = ((pub_r001746_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((stage_v_57_1 + (pub_r001746_12_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((stage_v_57_2 + (pub_r001746_12_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((stage_v_49_1 + (pub_r001746_13_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_49_2 + (pub_r001746_13_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((stage_v_38_1 + (pub_r001746_8_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((stage_v_38_2 + (pub_r001746_8_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((helper_flow_2_1 + (pub_r001746_16_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((helper_flow_2_2 + (pub_r001746_16_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((pub_r001746_11_1 * 2) + 8) & 63;
  int stage_v_63_2 = ((pub_r001746_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((sec_r001746_3_1 + (pub_r001746_12_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((sec_r001746_3_2 + (pub_r001746_12_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((stage_v_3_1 + (pub_r001746_3_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_3_2 + (pub_r001746_3_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((stage_v_3_1 + (pub_r001746_13_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((stage_v_3_2 + (pub_r001746_13_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((stage_v_60_1 + (pub_r001746_7_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_60_2 + (pub_r001746_7_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((stage_v_41_1 + (pub_r001746_10_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_41_2 + (pub_r001746_10_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((sec_r001746_1_1 + (pub_r001746_0_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((sec_r001746_1_2 + (pub_r001746_0_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((pub_r001746_1_1 * 2) + 42) & 63;
  int stage_v_70_2 = ((pub_r001746_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((stage_v_65_1 + (pub_r001746_0_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_65_2 + (pub_r001746_0_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((stage_v_48_1 + (pub_r001746_15_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((stage_v_48_2 + (pub_r001746_15_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((sec_r001746_9_1 + (pub_r001746_1_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((sec_r001746_9_2 + (pub_r001746_1_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((stage_v_62_1 + (pub_r001746_3_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_62_2 + (pub_r001746_3_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((pub_r001746_7_1 * 2) + 8) & 63;
  int stage_v_75_2 = ((pub_r001746_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((stage_v_48_1 + (pub_r001746_8_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((stage_v_48_2 + (pub_r001746_8_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((pub_r001746_5_1 * 2) + 12) & 63;
  int stage_v_77_2 = ((pub_r001746_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((stage_v_57_1 + (pub_r001746_8_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_57_2 + (pub_r001746_8_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((pub_r001746_11_1 * 2) + 7) & 63;
  int stage_v_79_2 = ((pub_r001746_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((stage_v_25_1 + (pub_r001746_2_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_25_2 + (pub_r001746_2_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((sec_r001746_13_1 + (pub_r001746_5_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((sec_r001746_13_2 + (pub_r001746_5_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((sec_r001746_14_1 + (pub_r001746_0_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((sec_r001746_14_2 + (pub_r001746_0_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((helper_flow_8_1 + (pub_r001746_11_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((helper_flow_8_2 + (pub_r001746_11_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((pub_r001746_15_1 * 2) + 9) & 63;
  int stage_v_84_2 = ((pub_r001746_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((stage_v_29_1 + (pub_r001746_0_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_29_2 + (pub_r001746_0_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_85_1 + (pub_r001746_14_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_85_2 + (pub_r001746_14_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((helper_flow_1_1 + (pub_r001746_11_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((helper_flow_1_2 + (pub_r001746_11_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((pub_r001746_13_1 * 2) + 33) & 63;
  int stage_v_88_2 = ((pub_r001746_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001746_5_1 * 2) + 17) & 63;
  int stage_v_89_2 = ((pub_r001746_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001746_9_1 * 2) + 49) & 63;
  int stage_v_90_2 = ((pub_r001746_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001746_2_1 * 2) + 12) & 63;
  int stage_v_91_2 = ((pub_r001746_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((sec_r001746_15_1 + (pub_r001746_9_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((sec_r001746_15_2 + (pub_r001746_9_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((pub_r001746_5_1 * 2) + 24) & 63;
  int stage_v_93_2 = ((pub_r001746_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((stage_v_14_1 + (pub_r001746_12_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_14_2 + (pub_r001746_12_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_10_1 + (pub_r001746_3_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_10_2 + (pub_r001746_3_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((sec_r001746_9_1 + (pub_r001746_6_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((sec_r001746_9_2 + (pub_r001746_6_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((stage_v_95_1 + (pub_r001746_7_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_95_2 + (pub_r001746_7_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((sec_r001746_11_1 + (pub_r001746_12_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((sec_r001746_11_2 + (pub_r001746_12_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((stage_v_28_1 + (pub_r001746_2_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_28_2 + (pub_r001746_2_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((stage_v_15_1 + (pub_r001746_7_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_15_2 + (pub_r001746_7_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((stage_v_12_1 + (pub_r001746_8_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_12_2 + (pub_r001746_8_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((pub_r001746_13_1 * 2) + 8) & 63;
  int stage_v_102_2 = ((pub_r001746_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001746_14_1 * 2) + 12) & 63;
  int stage_v_103_2 = ((pub_r001746_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001746_7_1 * 2) + 48) & 63;
  int stage_v_104_2 = ((pub_r001746_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001746_6_1 * 2) + 32) & 63;
  int stage_v_105_2 = ((pub_r001746_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((stage_v_22_1 + (pub_r001746_5_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_22_2 + (pub_r001746_5_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((stage_v_92_1 + (pub_r001746_9_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_92_2 + (pub_r001746_9_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((stage_v_22_1 + (pub_r001746_7_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_22_2 + (pub_r001746_7_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_15_1 + (pub_r001746_12_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_15_2 + (pub_r001746_12_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((helper_flow_2_1 + (pub_r001746_1_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((helper_flow_2_2 + (pub_r001746_1_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((stage_v_106_1 + (pub_r001746_11_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_106_2 + (pub_r001746_11_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((stage_v_4_1 + (pub_r001746_0_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((stage_v_4_2 + (pub_r001746_0_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((stage_v_40_1 + (pub_r001746_14_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((stage_v_40_2 + (pub_r001746_14_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((stage_v_65_1 + (pub_r001746_8_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_65_2 + (pub_r001746_8_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((sec_r001746_6_1 + (pub_r001746_15_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((sec_r001746_6_2 + (pub_r001746_15_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((helper_flow_4_1 + (pub_r001746_4_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((helper_flow_4_2 + (pub_r001746_4_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((pub_r001746_4_1 * 2) + 47) & 63;
  int stage_v_117_2 = ((pub_r001746_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((stage_v_10_1 + (pub_r001746_13_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_10_2 + (pub_r001746_13_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((stage_v_83_1 + (pub_r001746_10_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_83_2 + (pub_r001746_10_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((stage_v_15_1 + (pub_r001746_15_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_15_2 + (pub_r001746_15_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((pub_r001746_3_1 * 2) + 21) & 63;
  int stage_v_121_2 = ((pub_r001746_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((stage_v_100_1 + (pub_r001746_2_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_100_2 + (pub_r001746_2_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_109_1 + (pub_r001746_15_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_109_2 + (pub_r001746_15_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((pub_r001746_14_1 * 2) + 6) & 63;
  int stage_v_124_2 = ((pub_r001746_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_122_1 + (pub_r001746_7_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_122_2 + (pub_r001746_7_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((stage_v_59_1 + (pub_r001746_11_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_59_2 + (pub_r001746_11_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((stage_v_13_1 + (pub_r001746_10_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_13_2 + (pub_r001746_10_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((helper_flow_5_1 + (pub_r001746_16_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((helper_flow_5_2 + (pub_r001746_16_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((pub_r001746_6_1 * 2) + 8) & 63;
  int stage_v_129_2 = ((pub_r001746_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001746_8_1 * 2) + 27) & 63;
  int stage_v_130_2 = ((pub_r001746_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((stage_v_55_1 + (pub_r001746_2_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_55_2 + (pub_r001746_2_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((pub_r001746_10_1 * 2) + 50) & 63;
  int stage_v_132_2 = ((pub_r001746_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((stage_v_40_1 + (pub_r001746_13_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_40_2 + (pub_r001746_13_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((pub_r001746_0_1 * 2) + 6) & 63;
  int stage_v_134_2 = ((pub_r001746_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((stage_v_97_1 + (pub_r001746_5_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_97_2 + (pub_r001746_5_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((pub_r001746_5_1 * 2) + 49) & 63;
  int stage_v_136_2 = ((pub_r001746_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001746_4_1 * 2) + 33) & 63;
  int stage_v_137_2 = ((pub_r001746_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((sec_r001746_7_1 + (pub_r001746_12_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((sec_r001746_7_2 + (pub_r001746_12_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((pub_r001746_16_1 * 2) + 6) & 63;
  int stage_v_139_2 = ((pub_r001746_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((sec_r001746_13_1 + (pub_r001746_2_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((sec_r001746_13_2 + (pub_r001746_2_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((pub_r001746_13_1 * 2) + 27) & 63;
  int stage_v_141_2 = ((pub_r001746_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((stage_v_42_1 + (pub_r001746_8_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_42_2 + (pub_r001746_8_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((pub_r001746_3_1 * 2) + 45) & 63;
  int stage_v_143_2 = ((pub_r001746_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((stage_v_125_1 + (pub_r001746_7_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_125_2 + (pub_r001746_7_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((stage_v_86_1 + (pub_r001746_1_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_86_2 + (pub_r001746_1_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((stage_v_33_1 + (pub_r001746_16_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_33_2 + (pub_r001746_16_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((stage_v_43_1 + (pub_r001746_0_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_43_2 + (pub_r001746_0_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((pub_r001746_14_1 * 2) + 15) & 63;
  int stage_v_148_2 = ((pub_r001746_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((helper_flow_2_1 + (pub_r001746_10_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((helper_flow_2_2 + (pub_r001746_10_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((stage_v_86_1 + (pub_r001746_4_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_86_2 + (pub_r001746_4_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((pub_r001746_15_1 * 2) + 42) & 63;
  int stage_v_151_2 = ((pub_r001746_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((helper_flow_2_1 + (pub_r001746_0_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((helper_flow_2_2 + (pub_r001746_0_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((pub_r001746_6_1 * 2) + 44) & 63;
  int stage_v_153_2 = ((pub_r001746_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((stage_v_22_1 + (pub_r001746_1_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((stage_v_22_2 + (pub_r001746_1_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((stage_v_86_1 + (pub_r001746_1_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_86_2 + (pub_r001746_1_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((pub_r001746_1_1 * 2) + 23) & 63;
  int stage_v_156_2 = ((pub_r001746_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001746_2_1 * 2) + 42) & 63;
  int stage_v_157_2 = ((pub_r001746_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((stage_v_64_1 + (pub_r001746_6_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_64_2 + (pub_r001746_6_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((helper_flow_7_1 + (pub_r001746_14_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((helper_flow_7_2 + (pub_r001746_14_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_118_1 + (pub_r001746_8_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_118_2 + (pub_r001746_8_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((stage_v_46_1 + (pub_r001746_6_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_46_2 + (pub_r001746_6_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((stage_v_20_1 + (pub_r001746_1_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_20_2 + (pub_r001746_1_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((helper_flow_6_1 + (pub_r001746_8_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((helper_flow_6_2 + (pub_r001746_8_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((pub_r001746_8_1 * 2) + 27) & 63;
  int stage_v_164_2 = ((pub_r001746_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((stage_v_15_1 + (pub_r001746_0_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_15_2 + (pub_r001746_0_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((pub_r001746_16_1 * 2) + 49) & 63;
  int stage_v_166_2 = ((pub_r001746_16_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001746_15_1 * 2) + 40) & 63;
  int stage_v_167_2 = ((pub_r001746_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((stage_v_85_1 + (pub_r001746_12_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_85_2 + (pub_r001746_12_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_80_1 + (pub_r001746_2_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_80_2 + (pub_r001746_2_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((pub_r001746_1_1 * 2) + 43) & 63;
  int stage_v_170_2 = ((pub_r001746_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001746_15_1 * 2) + 16) & 63;
  int stage_v_171_2 = ((pub_r001746_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_120_1 + (pub_r001746_7_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_120_2 + (pub_r001746_7_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((pub_r001746_8_1 * 2) + 17) & 63;
  int stage_v_173_2 = ((pub_r001746_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((stage_v_69_1 + (pub_r001746_3_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_69_2 + (pub_r001746_3_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_59_1 + (pub_r001746_4_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_59_2 + (pub_r001746_4_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((stage_v_43_1 + (pub_r001746_15_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_43_2 + (pub_r001746_15_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((stage_v_112_1 + (pub_r001746_3_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_112_2 + (pub_r001746_3_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((pub_r001746_5_1 * 2) + 26) & 63;
  int stage_v_178_2 = ((pub_r001746_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001746_4_1 * 2) + 5) & 63;
  int stage_v_179_2 = ((pub_r001746_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((stage_v_98_1 + (pub_r001746_3_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_98_2 + (pub_r001746_3_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((stage_v_116_1 + (pub_r001746_3_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_116_2 + (pub_r001746_3_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((pub_r001746_14_1 * 2) + 32) & 63;
  int stage_v_182_2 = ((pub_r001746_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((stage_v_162_1 + (pub_r001746_14_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_162_2 + (pub_r001746_14_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((stage_v_31_1 + (pub_r001746_12_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_31_2 + (pub_r001746_12_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_118_1 + (pub_r001746_6_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_118_2 + (pub_r001746_6_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((pub_r001746_13_1 * 2) + 46) & 63;
  int stage_v_186_2 = ((pub_r001746_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((stage_v_177_1 + (pub_r001746_0_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_177_2 + (pub_r001746_0_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((stage_v_144_1 + (pub_r001746_5_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((stage_v_144_2 + (pub_r001746_5_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((helper_flow_4_1 + (pub_r001746_3_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((helper_flow_4_2 + (pub_r001746_3_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((stage_v_149_1 + (pub_r001746_13_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_149_2 + (pub_r001746_13_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((sec_r001746_15_1 + (pub_r001746_8_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((sec_r001746_15_2 + (pub_r001746_8_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((pub_r001746_15_1 * 2) + 11) & 63;
  int stage_v_192_2 = ((pub_r001746_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001746_4_1 * 2) + 43) & 63;
  int stage_v_193_2 = ((pub_r001746_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((stage_v_4_1 + (pub_r001746_13_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_4_2 + (pub_r001746_13_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((stage_v_194_1 + (pub_r001746_15_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_194_2 + (pub_r001746_15_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((stage_v_11_1 + (pub_r001746_16_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_11_2 + (pub_r001746_16_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((pub_r001746_16_1 * 2) + 23) & 63;
  int stage_v_197_2 = ((pub_r001746_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((sec_r001746_4_1 + (pub_r001746_11_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((sec_r001746_4_2 + (pub_r001746_11_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_133_1 + (pub_r001746_16_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_133_2 + (pub_r001746_16_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_150_1 + (pub_r001746_10_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_150_2 + (pub_r001746_10_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((pub_r001746_15_1 * 2) + 46) & 63;
  int stage_v_201_2 = ((pub_r001746_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001746_1_1 == pub_r001746_1_2);
  __CPROVER_assume(sec_r001746_8_1 != sec_r001746_8_2);
  __CPROVER_assume(sec_r001746_9_1 != sec_r001746_9_2);
  __CPROVER_assume(sec_r001746_14_1 != sec_r001746_14_2);
  __CPROVER_assume(pub_r001746_5_1 == pub_r001746_5_2);
  __CPROVER_assume(pub_r001746_6_1 == pub_r001746_6_2);
  __CPROVER_assume(pub_r001746_9_1 == pub_r001746_9_2);
  __CPROVER_assume(pub_r001746_8_1 == pub_r001746_8_2);
  __CPROVER_assume(sec_r001746_6_1 != sec_r001746_6_2);
  __CPROVER_assume(pub_r001746_3_1 == pub_r001746_3_2);
  __CPROVER_assume(sec_r001746_5_1 != sec_r001746_5_2);
  __CPROVER_assume(sec_r001746_2_1 != sec_r001746_2_2);
  __CPROVER_assume(pub_r001746_14_1 == pub_r001746_14_2);
  __CPROVER_assume(pub_r001746_15_1 == pub_r001746_15_2);
  __CPROVER_assume(pub_r001746_10_1 == pub_r001746_10_2);
  __CPROVER_assume(sec_r001746_10_1 != sec_r001746_10_2);
  __CPROVER_assume(sec_r001746_7_1 != sec_r001746_7_2);
  __CPROVER_assume(sec_r001746_4_1 != sec_r001746_4_2);
  __CPROVER_assume(sec_r001746_3_1 != sec_r001746_3_2);
  __CPROVER_assume(sec_r001746_12_1 != sec_r001746_12_2);
  __CPROVER_assume(pub_r001746_4_1 == pub_r001746_4_2);
  __CPROVER_assume(pub_r001746_16_1 == pub_r001746_16_2);
  __CPROVER_assume(pub_r001746_7_1 == pub_r001746_7_2);
  __CPROVER_assume(pub_r001746_13_1 == pub_r001746_13_2);
  __CPROVER_assume(pub_r001746_0_1 == pub_r001746_0_2);
  __CPROVER_assume(sec_r001746_13_1 != sec_r001746_13_2);
  __CPROVER_assume(sec_r001746_0_1 != sec_r001746_0_2);
  __CPROVER_assume(pub_r001746_12_1 == pub_r001746_12_2);
  __CPROVER_assume(sec_r001746_15_1 != sec_r001746_15_2);
  __CPROVER_assume(pub_r001746_2_1 == pub_r001746_2_2);
  __CPROVER_assume(pub_r001746_11_1 == pub_r001746_11_2);
  __CPROVER_assume(sec_r001746_1_1 != sec_r001746_1_2);
  __CPROVER_assume(sec_r001746_11_1 != sec_r001746_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  assert(st_var_0_1.code == st_var_0_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.balance == st_var_2_2.balance);
  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.tag == st_var_3_2.tag);
  assert(st_var_3_1.round_key == st_var_3_2.round_key);
  assert(st_var_3_1.nonce == st_var_3_2.nonce);
  assert(st_var_3_1.flags == st_var_3_2.flags);
  assert(st_var_3_1.iv == st_var_3_2.iv);
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
}


