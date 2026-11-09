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
struct Transaction_R001215_1513_0
{
  int account_id;
  int status;
  short rate;
  unsigned char auth_code;
  short fee;
  int balance;
  int buffer[3];
};
struct AudioFrame_R001215_1513_1
{
  int sample_rate;
  int rms;
  int channels;
  int gain;
  int envelope;
  short peak;
  int buffer[3];
};
union PacketPayload_R001215_1513_0
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
void fn_R001215_1513_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st_1 = {0};
  struct AudioFrame_R001215_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int threshold_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_98_1 > 37)
  {
    acc_1 = ((acc_1 + (threshold_98_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_98_2 > 37)
  {
    acc_2 = ((acc_2 + (threshold_98_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_98_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_98_1 == threshold_98_2);
}

int fn_R001215_1513_0(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int threshold_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_98 > 37)
  {
    acc = ((acc + (threshold_98 * 2)) + 5) & 127;
    aux ^= threshold_98 & 15;
  }
  else
  {
    acc = ((acc - threshold_98) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001215_1513_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001215_1513_0 st_1 = {0};
  struct Transaction_R001215_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int margin_76_1 = 0;
  int margin_76_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_76_1 = ((margin_76_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_76_2 = ((margin_76_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_76_1) & 127;
    acc_2 = (acc_2 + margin_76_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_76_1 == margin_76_2);
}

int fn_R001215_1513_1(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001215_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int margin_76 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_76 = ((margin_76 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_76) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001215_1513_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001215_1513_0 st_1 = {0};
  struct Transaction_R001215_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int factor_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_68_1 > 35)
  {
    acc_1 = ((acc_1 + (factor_68_1 * 2)) + 5) & 127;
    aux_1 ^= factor_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_68_2 > 35)
  {
    acc_2 = ((acc_2 + (factor_68_2 * 2)) + 5) & 127;
    aux_2 ^= factor_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_68_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_68_1 == factor_68_2);
}

int fn_R001215_1513_2(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001215_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int factor_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_68 > 35)
  {
    acc = ((acc + (factor_68 * 2)) + 5) & 127;
    aux ^= factor_68 & 15;
  }
  else
  {
    acc = ((acc - factor_68) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001215_1513_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st_1 = {0};
  struct AudioFrame_R001215_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int damping_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_98_1 > 48)
  {
    acc_1 = ((acc_1 + (damping_98_1 * 2)) + 5) & 127;
    aux_1 ^= damping_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_98_2 > 48)
  {
    acc_2 = ((acc_2 + (damping_98_2 * 2)) + 5) & 127;
    aux_2 ^= damping_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_56_1 = local_arr_1[aux_1 % 3];
  int residue_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_56_2 * 2)) & 127;
  int cursor_61_1 = 0;
  int cursor_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_61_1 = ((cursor_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_61_2 = ((cursor_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_61_1) & 127;
    acc_2 = (acc_2 + cursor_61_2) & 127;
  }

  int window_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_15_1) & 63;
  aux_2 = (aux_2 + window_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_98_1 == damping_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_56_1 == residue_56_2);
  assert(cursor_61_1 == cursor_61_2);
  assert(window_15_1 == window_15_2);
}

int fn_R001215_1513_3(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int damping_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_98 > 48)
  {
    acc = ((acc + (damping_98 * 2)) + 5) & 127;
    aux ^= damping_98 & 15;
  }
  else
  {
    acc = ((acc - damping_98) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_56 = local_arr[aux % 3];
  acc = (acc + (residue_56 * 2)) & 127;
  int cursor_61 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_61 = ((cursor_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_61) & 127;
  }

  int window_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_15) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001215_1513_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001215_1513_0 st_1 = {0};
  struct Transaction_R001215_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int quotient_78_1 = 0;
  int quotient_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_78_1 = ((quotient_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_78_2 = ((quotient_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_78_1) & 127;
    acc_2 = (acc_2 + quotient_78_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_94_1)
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

  switch (factor_94_2)
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

  int stride_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_20_1 > 34)
  {
    acc_1 = ((acc_1 + (stride_20_1 * 2)) + 5) & 127;
    aux_1 ^= stride_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_20_2 > 34)
  {
    acc_2 = ((acc_2 + (stride_20_2 * 2)) + 5) & 127;
    aux_2 ^= stride_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_20_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_78_1 == quotient_78_2);
  assert(factor_94_1 == factor_94_2);
  assert(stride_20_1 == stride_20_2);
}

int fn_R001215_1513_4(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001215_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int quotient_78 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_78 = ((quotient_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_78) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_94 = (aux + st.buffer[1]) & 3;
  switch (factor_94)
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

  int stride_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_20 > 34)
  {
    acc = ((acc + (stride_20 * 2)) + 5) & 127;
    aux ^= stride_20 & 15;
  }
  else
  {
    acc = ((acc - stride_20) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001215_1513_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001215_1513_0 st_1 = {0};
  struct Transaction_R001215_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_87_1) & 63;
  aux_2 = (aux_2 + quotient_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_97_1 > 31)
  {
    acc_1 = ((acc_1 + (delta_97_1 * 2)) + 5) & 127;
    aux_1 ^= delta_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_97_2 > 31)
  {
    acc_2 = ((acc_2 + (delta_97_2 * 2)) + 5) & 127;
    aux_2 ^= delta_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_87_1 == quotient_87_2);
  assert(delta_97_1 == delta_97_2);
}

int fn_R001215_1513_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001215_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_87) & 63;
  acc ^= aux;
  int delta_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_97 > 31)
  {
    acc = ((acc + (delta_97 * 2)) + 5) & 127;
    aux ^= delta_97 & 15;
  }
  else
  {
    acc = ((acc - delta_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001215_1513_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st_1 = {0};
  struct AudioFrame_R001215_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int bound_61_1 = 0;
  int bound_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_61_1 = ((bound_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_61_2 = ((bound_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_61_1) & 127;
    acc_2 = (acc_2 + bound_61_2) & 127;
  }

  int weight_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_94_1) & 63;
  aux_2 = (aux_2 + weight_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_60_1 > 20)
  {
    acc_1 = ((acc_1 + (tracker_60_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_60_2 > 20)
  {
    acc_2 = ((acc_2 + (tracker_60_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_60_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_61_1 == bound_61_2);
  assert(weight_94_1 == weight_94_2);
  assert(tracker_60_1 == tracker_60_2);
}

int fn_R001215_1513_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int bound_61 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_61 = ((bound_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_61) & 127;
  }

  int weight_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_94) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_60 > 20)
  {
    acc = ((acc + (tracker_60 * 2)) + 5) & 127;
    aux ^= tracker_60 & 15;
  }
  else
  {
    acc = ((acc - tracker_60) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001215_1513_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st_1 = {0};
  struct AudioFrame_R001215_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int weight_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_18_1)
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

  switch (weight_18_2)
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
  int tracker_86_1 = local_arr_1[aux_1 % 3];
  int tracker_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_86_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_18_1 == weight_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_86_1 == tracker_86_2);
}

int fn_R001215_1513_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int weight_18 = (aux + st.buffer[1]) & 3;
  switch (weight_18)
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
  int tracker_86 = local_arr[aux % 3];
  acc = (acc + (tracker_86 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001215_1513_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st_1 = {0};
  struct AudioFrame_R001215_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int quantum_72_1 = 0;
  int quantum_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_72_1 = ((quantum_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_72_2 = ((quantum_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_72_1) & 127;
    acc_2 = (acc_2 + quantum_72_2) & 127;
  }

  int metric_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_84_1)
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

  switch (metric_84_2)
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

  int metric_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_54_1 > 10)
  {
    acc_1 = ((acc_1 + (metric_54_1 * 2)) + 5) & 127;
    aux_1 ^= metric_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_54_2 > 10)
  {
    acc_2 = ((acc_2 + (metric_54_2 * 2)) + 5) & 127;
    aux_2 ^= metric_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_86_1 = local_arr_1[aux_1 % 3];
  int threshold_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_72_1 == quantum_72_2);
  assert(metric_84_1 == metric_84_2);
  assert(metric_54_1 == metric_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_86_1 == threshold_86_2);
}

int fn_R001215_1513_8(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int quantum_72 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_72 = ((quantum_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_72) & 127;
  }

  int metric_84 = (aux + st.buffer[1]) & 3;
  switch (metric_84)
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

  int metric_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_54 > 10)
  {
    acc = ((acc + (metric_54 * 2)) + 5) & 127;
    aux ^= metric_54 & 15;
  }
  else
  {
    acc = ((acc - metric_54) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_86 = local_arr[aux % 3];
  acc = (acc + (threshold_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001215_1513_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st_1 = {0};
  struct AudioFrame_R001215_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int parity_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_19_1 > 39)
  {
    acc_1 = ((acc_1 + (parity_19_1 * 2)) + 5) & 127;
    aux_1 ^= parity_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_19_2 > 39)
  {
    acc_2 = ((acc_2 + (parity_19_2 * 2)) + 5) & 127;
    aux_2 ^= parity_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_14_1)
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

  switch (anchor_14_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_19_1 == parity_19_2);
  assert(anchor_14_1 == anchor_14_2);
}

int fn_R001215_1513_9(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int parity_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_19 > 39)
  {
    acc = ((acc + (parity_19 * 2)) + 5) & 127;
    aux ^= parity_19 & 15;
  }
  else
  {
    acc = ((acc - parity_19) + 11) & 127;
    aux += 3;
  }
  int anchor_14 = (aux + st.buffer[1]) & 3;
  switch (anchor_14)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001215_1513_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st_1 = {0};
  struct AudioFrame_R001215_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int window_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_82_1 > 36)
  {
    acc_1 = ((acc_1 + (window_82_1 * 2)) + 5) & 127;
    aux_1 ^= window_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_82_2 > 36)
  {
    acc_2 = ((acc_2 + (window_82_2 * 2)) + 5) & 127;
    aux_2 ^= window_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_83_1 = local_arr_1[aux_1 % 3];
  int metric_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_83_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_82_1 == window_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_83_1 == metric_83_2);
}

int fn_R001215_1513_10(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int window_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_82 > 36)
  {
    acc = ((acc + (window_82 * 2)) + 5) & 127;
    aux ^= window_82 & 15;
  }
  else
  {
    acc = ((acc - window_82) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_83 = local_arr[aux % 3];
  acc = (acc + (metric_83 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001215_1513_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st_1 = {0};
  struct AudioFrame_R001215_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int delta_48_1 = 0;
  int delta_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_48_1 = ((delta_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_48_2 = ((delta_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_48_1) & 127;
    acc_2 = (acc_2 + delta_48_2) & 127;
  }

  int segment_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_20_1) & 63;
  aux_2 = (aux_2 + segment_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_71_1 = local_arr_1[aux_1 % 3];
  int window_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_71_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_48_1 == delta_48_2);
  assert(segment_20_1 == segment_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_71_1 == window_71_2);
}

int fn_R001215_1513_11(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int delta_48 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_48 = ((delta_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_48) & 127;
  }

  int segment_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_20) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_71 = local_arr[aux % 3];
  acc = (acc + (window_71 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001215_1513_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st_1 = {0};
  struct AudioFrame_R001215_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int sample_63_1 = 0;
  int sample_63_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_63_1 = ((sample_63_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_63_2 = ((sample_63_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_63_1) & 127;
    acc_2 = (acc_2 + sample_63_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_57_1 = local_arr_1[aux_1 % 3];
  int pivot_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_57_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_63_1 == sample_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_57_1 == pivot_57_2);
}

int fn_R001215_1513_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int sample_63 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_63 = ((sample_63 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_63) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_57 = local_arr[aux % 3];
  acc = (acc + (pivot_57 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001215_1513_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001215_1513_0 st_1 = {0};
  struct Transaction_R001215_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int segment_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_45_1)
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

  switch (segment_45_2)
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

  int quantum_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_65_1) & 63;
  aux_2 = (aux_2 + quantum_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_20_1 > 20)
  {
    acc_1 = ((acc_1 + (coefficient_20_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_20_2 > 20)
  {
    acc_2 = ((acc_2 + (coefficient_20_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_95_1 = 0;
  int offset_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_95_1 = ((offset_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_95_2 = ((offset_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_95_1) & 127;
    acc_2 = (acc_2 + offset_95_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_45_1 == segment_45_2);
  assert(quantum_65_1 == quantum_65_2);
  assert(coefficient_20_1 == coefficient_20_2);
  assert(offset_95_1 == offset_95_2);
}

int fn_R001215_1513_13(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001215_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int segment_45 = (aux + st.buffer[1]) & 3;
  switch (segment_45)
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

  int quantum_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_65) & 63;
  acc ^= aux;
  int coefficient_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_20 > 20)
  {
    acc = ((acc + (coefficient_20 * 2)) + 5) & 127;
    aux ^= coefficient_20 & 15;
  }
  else
  {
    acc = ((acc - coefficient_20) + 11) & 127;
    aux += 3;
  }
  int offset_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_95 = ((offset_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_95) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001215_1513_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001215_1513_0 st_1 = {0};
  struct Transaction_R001215_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int bound_57_1 = 0;
  int bound_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_57_1 = ((bound_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_57_2 = ((bound_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_57_1) & 127;
    acc_2 = (acc_2 + bound_57_2) & 127;
  }

  int threshold_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_69_1) & 63;
  aux_2 = (aux_2 + threshold_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_88_1)
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

  switch (metric_88_2)
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

  int window_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_42_1 > 45)
  {
    acc_1 = ((acc_1 + (window_42_1 * 2)) + 5) & 127;
    aux_1 ^= window_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_42_2 > 45)
  {
    acc_2 = ((acc_2 + (window_42_2 * 2)) + 5) & 127;
    aux_2 ^= window_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_57_1 == bound_57_2);
  assert(threshold_69_1 == threshold_69_2);
  assert(metric_88_1 == metric_88_2);
  assert(window_42_1 == window_42_2);
}

int fn_R001215_1513_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001215_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int bound_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_57 = ((bound_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_57) & 127;
  }

  int threshold_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_69) & 63;
  acc ^= aux;
  int metric_88 = (aux + st.buffer[1]) & 3;
  switch (metric_88)
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

  int window_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_42 > 45)
  {
    acc = ((acc + (window_42 * 2)) + 5) & 127;
    aux ^= window_42 & 15;
  }
  else
  {
    acc = ((acc - window_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001215_1513_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001215_1513_0 st_1 = {0};
  struct Transaction_R001215_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_81_1 = local_arr_1[aux_1 % 3];
  int mask_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_81_2 * 2)) & 127;
  int residue_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_44_1)
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

  switch (residue_44_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_81_1 == mask_81_2);
  assert(residue_44_1 == residue_44_2);
}

int fn_R001215_1513_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001215_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_81 = local_arr[aux % 3];
  acc = (acc + (mask_81 * 2)) & 127;
  int residue_44 = (aux + st.buffer[1]) & 3;
  switch (residue_44)
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

void fn_R001215_1513_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st_1 = {0};
  struct AudioFrame_R001215_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int quantum_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_50_1 > 45)
  {
    acc_1 = ((acc_1 + (quantum_50_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_50_2 > 45)
  {
    acc_2 = ((acc_2 + (quantum_50_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_13_1 = 0;
  int scale_13_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_13_1 = ((scale_13_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_13_2 = ((scale_13_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_13_1) & 127;
    acc_2 = (acc_2 + scale_13_2) & 127;
  }

  int phase_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_10_1) & 63;
  aux_2 = (aux_2 + phase_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_50_1 == quantum_50_2);
  assert(scale_13_1 == scale_13_2);
  assert(phase_10_1 == phase_10_2);
}

int fn_R001215_1513_16(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001215_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int quantum_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_50 > 45)
  {
    acc = ((acc + (quantum_50 * 2)) + 5) & 127;
    aux ^= quantum_50 & 15;
  }
  else
  {
    acc = ((acc - quantum_50) + 11) & 127;
    aux += 3;
  }
  int scale_13 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_13 = ((scale_13 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_13) & 127;
  }

  int phase_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_10) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001215_0_1;
  int sec_r001215_0_2;
  int sec_r001215_1_1;
  int sec_r001215_1_2;
  int sec_r001215_2_1;
  int sec_r001215_2_2;
  int sec_r001215_3_1;
  int sec_r001215_3_2;
  int sec_r001215_4_1;
  int sec_r001215_4_2;
  int sec_r001215_5_1;
  int sec_r001215_5_2;
  int sec_r001215_6_1;
  int sec_r001215_6_2;
  int sec_r001215_7_1;
  int sec_r001215_7_2;
  int sec_r001215_8_1;
  int sec_r001215_8_2;
  int sec_r001215_9_1;
  int sec_r001215_9_2;
  int sec_r001215_10_1;
  int sec_r001215_10_2;
  int sec_r001215_11_1;
  int sec_r001215_11_2;
  int sec_r001215_12_1;
  int sec_r001215_12_2;
  int sec_r001215_13_1;
  int sec_r001215_13_2;
  int sec_r001215_14_1;
  int sec_r001215_14_2;
  int sec_r001215_15_1;
  int sec_r001215_15_2;
  int sec_r001215_16_1;
  int sec_r001215_16_2;
  int pub_r001215_0_1;
  int pub_r001215_0_2;
  int pub_r001215_1_1;
  int pub_r001215_1_2;
  int pub_r001215_2_1;
  int pub_r001215_2_2;
  int pub_r001215_3_1;
  int pub_r001215_3_2;
  int pub_r001215_4_1;
  int pub_r001215_4_2;
  int pub_r001215_5_1;
  int pub_r001215_5_2;
  int pub_r001215_6_1;
  int pub_r001215_6_2;
  int pub_r001215_7_1;
  int pub_r001215_7_2;
  int pub_r001215_8_1;
  int pub_r001215_8_2;
  int pub_r001215_9_1;
  int pub_r001215_9_2;
  int pub_r001215_10_1;
  int pub_r001215_10_2;
  int pub_r001215_11_1;
  int pub_r001215_11_2;
  int pub_r001215_12_1;
  int pub_r001215_12_2;
  int pub_r001215_13_1;
  int pub_r001215_13_2;
  int pub_r001215_14_1;
  int pub_r001215_14_2;
  int pub_r001215_15_1;
  int pub_r001215_15_2;
  int pub_r001215_16_1;
  int pub_r001215_16_2;
  int pub_r001215_17_1;
  int pub_r001215_17_2;
  int pub_r001215_18_1;
  int pub_r001215_18_2;
  int pub_r001215_19_1;
  int pub_r001215_19_2;
  int pub_r001215_20_1;
  int pub_r001215_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001215_0_1 >= (-100)) && (pub_r001215_0_1 <= 100));
  __CPROVER_assume((pub_r001215_0_2 >= (-100)) && (pub_r001215_0_2 <= 100));
  __CPROVER_assume((pub_r001215_1_1 >= (-100)) && (pub_r001215_1_1 <= 100));
  __CPROVER_assume((pub_r001215_1_2 >= (-100)) && (pub_r001215_1_2 <= 100));
  __CPROVER_assume((pub_r001215_2_1 >= (-100)) && (pub_r001215_2_1 <= 100));
  __CPROVER_assume((pub_r001215_2_2 >= (-100)) && (pub_r001215_2_2 <= 100));
  __CPROVER_assume((pub_r001215_3_1 >= (-100)) && (pub_r001215_3_1 <= 100));
  __CPROVER_assume((pub_r001215_3_2 >= (-100)) && (pub_r001215_3_2 <= 100));
  __CPROVER_assume((pub_r001215_4_1 >= (-100)) && (pub_r001215_4_1 <= 100));
  __CPROVER_assume((pub_r001215_4_2 >= (-100)) && (pub_r001215_4_2 <= 100));
  __CPROVER_assume((pub_r001215_5_1 >= (-100)) && (pub_r001215_5_1 <= 100));
  __CPROVER_assume((pub_r001215_5_2 >= (-100)) && (pub_r001215_5_2 <= 100));
  __CPROVER_assume((pub_r001215_6_1 >= (-100)) && (pub_r001215_6_1 <= 100));
  __CPROVER_assume((pub_r001215_6_2 >= (-100)) && (pub_r001215_6_2 <= 100));
  __CPROVER_assume((pub_r001215_7_1 >= (-100)) && (pub_r001215_7_1 <= 100));
  __CPROVER_assume((pub_r001215_7_2 >= (-100)) && (pub_r001215_7_2 <= 100));
  __CPROVER_assume((pub_r001215_8_1 >= (-100)) && (pub_r001215_8_1 <= 100));
  __CPROVER_assume((pub_r001215_8_2 >= (-100)) && (pub_r001215_8_2 <= 100));
  __CPROVER_assume((pub_r001215_9_1 >= (-100)) && (pub_r001215_9_1 <= 100));
  __CPROVER_assume((pub_r001215_9_2 >= (-100)) && (pub_r001215_9_2 <= 100));
  __CPROVER_assume((pub_r001215_10_1 >= (-100)) && (pub_r001215_10_1 <= 100));
  __CPROVER_assume((pub_r001215_10_2 >= (-100)) && (pub_r001215_10_2 <= 100));
  __CPROVER_assume((pub_r001215_11_1 >= (-100)) && (pub_r001215_11_1 <= 100));
  __CPROVER_assume((pub_r001215_11_2 >= (-100)) && (pub_r001215_11_2 <= 100));
  __CPROVER_assume((pub_r001215_12_1 >= (-100)) && (pub_r001215_12_1 <= 100));
  __CPROVER_assume((pub_r001215_12_2 >= (-100)) && (pub_r001215_12_2 <= 100));
  __CPROVER_assume((pub_r001215_13_1 >= (-100)) && (pub_r001215_13_1 <= 100));
  __CPROVER_assume((pub_r001215_13_2 >= (-100)) && (pub_r001215_13_2 <= 100));
  __CPROVER_assume((pub_r001215_14_1 >= (-100)) && (pub_r001215_14_1 <= 100));
  __CPROVER_assume((pub_r001215_14_2 >= (-100)) && (pub_r001215_14_2 <= 100));
  __CPROVER_assume((pub_r001215_15_1 >= (-100)) && (pub_r001215_15_1 <= 100));
  __CPROVER_assume((pub_r001215_15_2 >= (-100)) && (pub_r001215_15_2 <= 100));
  __CPROVER_assume((pub_r001215_16_1 >= (-100)) && (pub_r001215_16_1 <= 100));
  __CPROVER_assume((pub_r001215_16_2 >= (-100)) && (pub_r001215_16_2 <= 100));
  __CPROVER_assume((pub_r001215_17_1 >= (-100)) && (pub_r001215_17_1 <= 100));
  __CPROVER_assume((pub_r001215_17_2 >= (-100)) && (pub_r001215_17_2 <= 100));
  __CPROVER_assume((pub_r001215_18_1 >= (-100)) && (pub_r001215_18_1 <= 100));
  __CPROVER_assume((pub_r001215_18_2 >= (-100)) && (pub_r001215_18_2 <= 100));
  __CPROVER_assume((pub_r001215_19_1 >= (-100)) && (pub_r001215_19_1 <= 100));
  __CPROVER_assume((pub_r001215_19_2 >= (-100)) && (pub_r001215_19_2 <= 100));
  __CPROVER_assume((pub_r001215_20_1 >= (-100)) && (pub_r001215_20_1 <= 100));
  __CPROVER_assume((pub_r001215_20_2 >= (-100)) && (pub_r001215_20_2 <= 100));
  __CPROVER_assume((sec_r001215_0_1 >= 0) && (sec_r001215_0_1 <= 255));
  __CPROVER_assume((sec_r001215_0_2 >= 0) && (sec_r001215_0_2 <= 255));
  __CPROVER_assume((sec_r001215_1_1 >= 0) && (sec_r001215_1_1 <= 255));
  __CPROVER_assume((sec_r001215_1_2 >= 0) && (sec_r001215_1_2 <= 255));
  __CPROVER_assume((sec_r001215_2_1 >= 0) && (sec_r001215_2_1 <= 255));
  __CPROVER_assume((sec_r001215_2_2 >= 0) && (sec_r001215_2_2 <= 255));
  __CPROVER_assume((sec_r001215_3_1 >= 0) && (sec_r001215_3_1 <= 255));
  __CPROVER_assume((sec_r001215_3_2 >= 0) && (sec_r001215_3_2 <= 255));
  __CPROVER_assume((sec_r001215_4_1 >= 0) && (sec_r001215_4_1 <= 255));
  __CPROVER_assume((sec_r001215_4_2 >= 0) && (sec_r001215_4_2 <= 255));
  __CPROVER_assume((sec_r001215_5_1 >= 0) && (sec_r001215_5_1 <= 255));
  __CPROVER_assume((sec_r001215_5_2 >= 0) && (sec_r001215_5_2 <= 255));
  __CPROVER_assume((sec_r001215_6_1 >= 0) && (sec_r001215_6_1 <= 255));
  __CPROVER_assume((sec_r001215_6_2 >= 0) && (sec_r001215_6_2 <= 255));
  __CPROVER_assume((sec_r001215_7_1 >= 0) && (sec_r001215_7_1 <= 255));
  __CPROVER_assume((sec_r001215_7_2 >= 0) && (sec_r001215_7_2 <= 255));
  __CPROVER_assume((sec_r001215_8_1 >= 0) && (sec_r001215_8_1 <= 255));
  __CPROVER_assume((sec_r001215_8_2 >= 0) && (sec_r001215_8_2 <= 255));
  __CPROVER_assume((sec_r001215_9_1 >= 0) && (sec_r001215_9_1 <= 255));
  __CPROVER_assume((sec_r001215_9_2 >= 0) && (sec_r001215_9_2 <= 255));
  __CPROVER_assume((sec_r001215_10_1 >= 0) && (sec_r001215_10_1 <= 255));
  __CPROVER_assume((sec_r001215_10_2 >= 0) && (sec_r001215_10_2 <= 255));
  __CPROVER_assume((sec_r001215_11_1 >= 0) && (sec_r001215_11_1 <= 255));
  __CPROVER_assume((sec_r001215_11_2 >= 0) && (sec_r001215_11_2 <= 255));
  __CPROVER_assume((sec_r001215_12_1 >= 0) && (sec_r001215_12_1 <= 255));
  __CPROVER_assume((sec_r001215_12_2 >= 0) && (sec_r001215_12_2 <= 255));
  __CPROVER_assume((sec_r001215_13_1 >= 0) && (sec_r001215_13_1 <= 255));
  __CPROVER_assume((sec_r001215_13_2 >= 0) && (sec_r001215_13_2 <= 255));
  __CPROVER_assume((sec_r001215_14_1 >= 0) && (sec_r001215_14_1 <= 255));
  __CPROVER_assume((sec_r001215_14_2 >= 0) && (sec_r001215_14_2 <= 255));
  __CPROVER_assume((sec_r001215_15_1 >= 0) && (sec_r001215_15_1 <= 255));
  __CPROVER_assume((sec_r001215_15_2 >= 0) && (sec_r001215_15_2 <= 255));
  __CPROVER_assume((sec_r001215_16_1 >= 0) && (sec_r001215_16_1 <= 255));
  __CPROVER_assume((sec_r001215_16_2 >= 0) && (sec_r001215_16_2 <= 255));
  struct Transaction_R001215_1513_0 st_var_0_1 = {0};
  struct Transaction_R001215_1513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001215_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001215_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001215_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001215_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001215_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001215_0_2 + 7) & 15;
  struct AudioFrame_R001215_1513_1 st_var_1_1 = {0};
  struct AudioFrame_R001215_1513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001215_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001215_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001215_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001215_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001215_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001215_0_2 + 9) & 15;
  union PacketPayload_R001215_1513_0 u_var_1;
  union PacketPayload_R001215_1513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001215_1513_0(sec_r001215_0_1, sec_r001215_1_1);
  int helper_flow_0_2 = fn_R001215_1513_0(sec_r001215_0_2, sec_r001215_1_2);
  fn_R001215_1513_0_2(sec_r001215_0_1, sec_r001215_1_1, sec_r001215_0_2, sec_r001215_1_2);
  int helper_flow_1_1 = fn_R001215_1513_1(sec_r001215_1_1, sec_r001215_2_1, pub_r001215_3_1);
  int helper_flow_1_2 = fn_R001215_1513_1(sec_r001215_1_2, sec_r001215_2_2, pub_r001215_3_2);
  fn_R001215_1513_1_2(sec_r001215_1_1, sec_r001215_2_1, pub_r001215_3_1, sec_r001215_1_2, sec_r001215_2_2, pub_r001215_3_2);
  int helper_flow_2_1 = fn_R001215_1513_2(sec_r001215_2_1, sec_r001215_3_1, pub_r001215_4_1);
  int helper_flow_2_2 = fn_R001215_1513_2(sec_r001215_2_2, sec_r001215_3_2, pub_r001215_4_2);
  fn_R001215_1513_2_2(sec_r001215_2_1, sec_r001215_3_1, pub_r001215_4_1, sec_r001215_2_2, sec_r001215_3_2, pub_r001215_4_2);
  int helper_flow_3_1 = fn_R001215_1513_3(sec_r001215_3_1, pub_r001215_4_1);
  int helper_flow_3_2 = fn_R001215_1513_3(sec_r001215_3_2, pub_r001215_4_2);
  fn_R001215_1513_3_2(sec_r001215_3_1, pub_r001215_4_1, sec_r001215_3_2, pub_r001215_4_2);
  int helper_flow_4_1 = fn_R001215_1513_4(sec_r001215_4_1, pub_r001215_5_1);
  int helper_flow_4_2 = fn_R001215_1513_4(sec_r001215_4_2, pub_r001215_5_2);
  fn_R001215_1513_4_2(sec_r001215_4_1, pub_r001215_5_1, sec_r001215_4_2, pub_r001215_5_2);
  int helper_flow_5_1 = fn_R001215_1513_5(sec_r001215_5_1, pub_r001215_6_1, pub_r001215_7_1, pub_r001215_8_1);
  int helper_flow_5_2 = fn_R001215_1513_5(sec_r001215_5_2, pub_r001215_6_2, pub_r001215_7_2, pub_r001215_8_2);
  fn_R001215_1513_5_2(sec_r001215_5_1, pub_r001215_6_1, pub_r001215_7_1, pub_r001215_8_1, sec_r001215_5_2, pub_r001215_6_2, pub_r001215_7_2, pub_r001215_8_2);
  int helper_flow_6_1 = fn_R001215_1513_6(sec_r001215_6_1, sec_r001215_7_1, pub_r001215_8_1, pub_r001215_9_1, pub_r001215_10_1);
  int helper_flow_6_2 = fn_R001215_1513_6(sec_r001215_6_2, sec_r001215_7_2, pub_r001215_8_2, pub_r001215_9_2, pub_r001215_10_2);
  fn_R001215_1513_6_2(sec_r001215_6_1, sec_r001215_7_1, pub_r001215_8_1, pub_r001215_9_1, pub_r001215_10_1, sec_r001215_6_2, sec_r001215_7_2, pub_r001215_8_2, pub_r001215_9_2, pub_r001215_10_2);
  int helper_flow_7_1 = fn_R001215_1513_7(sec_r001215_7_1, sec_r001215_8_1, pub_r001215_9_1, pub_r001215_10_1, pub_r001215_11_1);
  int helper_flow_7_2 = fn_R001215_1513_7(sec_r001215_7_2, sec_r001215_8_2, pub_r001215_9_2, pub_r001215_10_2, pub_r001215_11_2);
  fn_R001215_1513_7_2(sec_r001215_7_1, sec_r001215_8_1, pub_r001215_9_1, pub_r001215_10_1, pub_r001215_11_1, sec_r001215_7_2, sec_r001215_8_2, pub_r001215_9_2, pub_r001215_10_2, pub_r001215_11_2);
  int helper_flow_8_1 = fn_R001215_1513_8(sec_r001215_8_1, sec_r001215_9_1, pub_r001215_10_1);
  int helper_flow_8_2 = fn_R001215_1513_8(sec_r001215_8_2, sec_r001215_9_2, pub_r001215_10_2);
  fn_R001215_1513_8_2(sec_r001215_8_1, sec_r001215_9_1, pub_r001215_10_1, sec_r001215_8_2, sec_r001215_9_2, pub_r001215_10_2);
  int stage_v_0_1 = ((pub_r001215_2_1 * 2) + 45) & 63;
  int stage_v_0_2 = ((pub_r001215_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((sec_r001215_11_1 << 1) ^ (pub_r001215_11_1 >> 1)) & 127;
  int stage_v_1_2 = ((sec_r001215_11_2 << 1) ^ (pub_r001215_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_1_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_1_2 + 1) & 15;
  out_sink_1 ^= stage_v_1_1 & 63;
  out_sink_2 ^= stage_v_1_2 & 63;
  int stage_v_2_1 = ((sec_r001215_2_1 << 1) ^ (pub_r001215_7_1 >> 1)) & 127;
  int stage_v_2_2 = ((sec_r001215_2_2 << 1) ^ (pub_r001215_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_2_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_2_2 + 1) & 15;
  out_sink_1 ^= stage_v_2_1 & 63;
  out_sink_2 ^= stage_v_2_2 & 63;
  int stage_v_3_1 = ((stage_v_1_1 << 1) ^ (pub_r001215_6_1 >> 1)) & 127;
  int stage_v_3_2 = ((stage_v_1_2 << 1) ^ (pub_r001215_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_3_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_3_2 + 1) & 15;
  out_sink_1 ^= stage_v_3_1 & 63;
  out_sink_2 ^= stage_v_3_2 & 63;
  int stage_v_4_1 = ((stage_v_2_1 << 1) ^ (pub_r001215_16_1 >> 1)) & 127;
  int stage_v_4_2 = ((stage_v_2_2 << 1) ^ (pub_r001215_16_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_4_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_4_2 + 1) & 15;
  out_sink_1 ^= stage_v_4_1 & 63;
  out_sink_2 ^= stage_v_4_2 & 63;
  int stage_v_5_1 = ((sec_r001215_11_1 << 1) ^ (pub_r001215_1_1 >> 1)) & 127;
  int stage_v_5_2 = ((sec_r001215_11_2 << 1) ^ (pub_r001215_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_5_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_5_2 + 1) & 15;
  out_sink_1 ^= stage_v_5_1 & 63;
  out_sink_2 ^= stage_v_5_2 & 63;
  int stage_v_6_1 = ((stage_v_5_1 << 1) ^ (pub_r001215_11_1 >> 1)) & 127;
  int stage_v_6_2 = ((stage_v_5_2 << 1) ^ (pub_r001215_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_6_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_6_2 + 1) & 15;
  out_sink_1 ^= stage_v_6_1 & 63;
  out_sink_2 ^= stage_v_6_2 & 63;
  int stage_v_7_1 = ((pub_r001215_11_1 * 2) + 50) & 63;
  int stage_v_7_2 = ((pub_r001215_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((helper_flow_6_1 << 1) ^ (pub_r001215_1_1 >> 1)) & 127;
  int stage_v_8_2 = ((helper_flow_6_2 << 1) ^ (pub_r001215_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_8_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_8_2 + 1) & 15;
  out_sink_1 ^= stage_v_8_1 & 63;
  out_sink_2 ^= stage_v_8_2 & 63;
  int stage_v_9_1 = ((sec_r001215_4_1 << 1) ^ (pub_r001215_18_1 >> 1)) & 127;
  int stage_v_9_2 = ((sec_r001215_4_2 << 1) ^ (pub_r001215_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_9_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_9_2 + 1) & 15;
  out_sink_1 ^= stage_v_9_1 & 63;
  out_sink_2 ^= stage_v_9_2 & 63;
  int stage_v_10_1 = ((sec_r001215_2_1 << 1) ^ (pub_r001215_6_1 >> 1)) & 127;
  int stage_v_10_2 = ((sec_r001215_2_2 << 1) ^ (pub_r001215_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_10_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_10_2 + 1) & 15;
  out_sink_1 ^= stage_v_10_1 & 63;
  out_sink_2 ^= stage_v_10_2 & 63;
  int stage_v_11_1 = ((stage_v_4_1 << 1) ^ (pub_r001215_2_1 >> 1)) & 127;
  int stage_v_11_2 = ((stage_v_4_2 << 1) ^ (pub_r001215_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_11_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_11_2 + 1) & 15;
  out_sink_1 ^= stage_v_11_1 & 63;
  out_sink_2 ^= stage_v_11_2 & 63;
  int stage_v_12_1 = ((pub_r001215_10_1 * 2) + 10) & 63;
  int stage_v_12_2 = ((pub_r001215_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((sec_r001215_5_1 << 1) ^ (pub_r001215_19_1 >> 1)) & 127;
  int stage_v_13_2 = ((sec_r001215_5_2 << 1) ^ (pub_r001215_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_13_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_13_2 + 1) & 15;
  out_sink_1 ^= stage_v_13_1 & 63;
  out_sink_2 ^= stage_v_13_2 & 63;
  int stage_v_14_1 = ((sec_r001215_12_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_14_2 = ((sec_r001215_12_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_14_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_14_2 + 1) & 15;
  out_sink_1 ^= stage_v_14_1 & 63;
  out_sink_2 ^= stage_v_14_2 & 63;
  int stage_v_15_1 = ((sec_r001215_10_1 << 1) ^ (pub_r001215_8_1 >> 1)) & 127;
  int stage_v_15_2 = ((sec_r001215_10_2 << 1) ^ (pub_r001215_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_15_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_15_2 + 1) & 15;
  out_sink_1 ^= stage_v_15_1 & 63;
  out_sink_2 ^= stage_v_15_2 & 63;
  int stage_v_16_1 = ((sec_r001215_11_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_16_2 = ((sec_r001215_11_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_16_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_16_2 + 1) & 15;
  out_sink_1 ^= stage_v_16_1 & 63;
  out_sink_2 ^= stage_v_16_2 & 63;
  int stage_v_17_1 = ((pub_r001215_8_1 * 2) + 44) & 63;
  int stage_v_17_2 = ((pub_r001215_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((stage_v_6_1 << 1) ^ (pub_r001215_9_1 >> 1)) & 127;
  int stage_v_18_2 = ((stage_v_6_2 << 1) ^ (pub_r001215_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_18_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_18_2 + 1) & 15;
  out_sink_1 ^= stage_v_18_1 & 63;
  out_sink_2 ^= stage_v_18_2 & 63;
  int stage_v_19_1 = ((helper_flow_8_1 << 1) ^ (pub_r001215_5_1 >> 1)) & 127;
  int stage_v_19_2 = ((helper_flow_8_2 << 1) ^ (pub_r001215_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_19_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_19_2 + 1) & 15;
  out_sink_1 ^= stage_v_19_1 & 63;
  out_sink_2 ^= stage_v_19_2 & 63;
  int stage_v_20_1 = ((sec_r001215_14_1 << 1) ^ (pub_r001215_3_1 >> 1)) & 127;
  int stage_v_20_2 = ((sec_r001215_14_2 << 1) ^ (pub_r001215_3_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_20_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_20_2 + 1) & 15;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = ((sec_r001215_11_1 << 1) ^ (pub_r001215_5_1 >> 1)) & 127;
  int stage_v_21_2 = ((sec_r001215_11_2 << 1) ^ (pub_r001215_5_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_21_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_21_2 + 1) & 15;
  out_sink_1 ^= stage_v_21_1 & 63;
  out_sink_2 ^= stage_v_21_2 & 63;
  int stage_v_22_1 = ((sec_r001215_15_1 << 1) ^ (pub_r001215_11_1 >> 1)) & 127;
  int stage_v_22_2 = ((sec_r001215_15_2 << 1) ^ (pub_r001215_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_22_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_22_2 + 1) & 15;
  out_sink_1 ^= stage_v_22_1 & 63;
  out_sink_2 ^= stage_v_22_2 & 63;
  int stage_v_23_1 = ((stage_v_1_1 << 1) ^ (pub_r001215_16_1 >> 1)) & 127;
  int stage_v_23_2 = ((stage_v_1_2 << 1) ^ (pub_r001215_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_23_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_23_2 + 1) & 15;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = ((stage_v_4_1 << 1) ^ (pub_r001215_3_1 >> 1)) & 127;
  int stage_v_24_2 = ((stage_v_4_2 << 1) ^ (pub_r001215_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_24_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_24_2 + 1) & 15;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = ((pub_r001215_15_1 * 2) + 19) & 63;
  int stage_v_25_2 = ((pub_r001215_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001215_2_1 * 2) + 13) & 63;
  int stage_v_26_2 = ((pub_r001215_2_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((helper_flow_7_1 << 1) ^ (pub_r001215_19_1 >> 1)) & 127;
  int stage_v_27_2 = ((helper_flow_7_2 << 1) ^ (pub_r001215_19_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_27_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_27_2 + 1) & 15;
  out_sink_1 ^= stage_v_27_1 & 63;
  out_sink_2 ^= stage_v_27_2 & 63;
  int stage_v_28_1 = ((sec_r001215_9_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_28_2 = ((sec_r001215_9_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_28_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_28_2 + 1) & 15;
  out_sink_1 ^= stage_v_28_1 & 63;
  out_sink_2 ^= stage_v_28_2 & 63;
  int stage_v_29_1 = ((pub_r001215_12_1 * 2) + 48) & 63;
  int stage_v_29_2 = ((pub_r001215_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((sec_r001215_13_1 << 1) ^ (pub_r001215_17_1 >> 1)) & 127;
  int stage_v_30_2 = ((sec_r001215_13_2 << 1) ^ (pub_r001215_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_30_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_30_2 + 1) & 15;
  out_sink_1 ^= stage_v_30_1 & 63;
  out_sink_2 ^= stage_v_30_2 & 63;
  int stage_v_31_1 = ((pub_r001215_5_1 * 2) + 47) & 63;
  int stage_v_31_2 = ((pub_r001215_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((helper_flow_8_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_32_2 = ((helper_flow_8_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_32_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_32_2 + 1) & 15;
  out_sink_1 ^= stage_v_32_1 & 63;
  out_sink_2 ^= stage_v_32_2 & 63;
  int stage_v_33_1 = ((helper_flow_7_1 << 1) ^ (pub_r001215_8_1 >> 1)) & 127;
  int stage_v_33_2 = ((helper_flow_7_2 << 1) ^ (pub_r001215_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_33_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_33_2 + 1) & 15;
  out_sink_1 ^= stage_v_33_1 & 63;
  out_sink_2 ^= stage_v_33_2 & 63;
  int stage_v_34_1 = ((sec_r001215_16_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_34_2 = ((sec_r001215_16_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_34_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_34_2 + 1) & 15;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = ((pub_r001215_6_1 * 2) + 47) & 63;
  int stage_v_35_2 = ((pub_r001215_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001215_18_1 * 2) + 43) & 63;
  int stage_v_36_2 = ((pub_r001215_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001215_14_1 * 2) + 38) & 63;
  int stage_v_37_2 = ((pub_r001215_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((helper_flow_3_1 << 1) ^ (pub_r001215_7_1 >> 1)) & 127;
  int stage_v_38_2 = ((helper_flow_3_2 << 1) ^ (pub_r001215_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_38_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_38_2 + 1) & 15;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = ((pub_r001215_8_1 * 2) + 21) & 63;
  int stage_v_39_2 = ((pub_r001215_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((stage_v_22_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_40_2 = ((stage_v_22_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_40_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_40_2 + 1) & 15;
  out_sink_1 ^= stage_v_40_1 & 63;
  out_sink_2 ^= stage_v_40_2 & 63;
  int stage_v_41_1 = ((sec_r001215_6_1 << 1) ^ (pub_r001215_1_1 >> 1)) & 127;
  int stage_v_41_2 = ((sec_r001215_6_2 << 1) ^ (pub_r001215_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_41_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_41_2 + 1) & 15;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = ((pub_r001215_11_1 * 2) + 17) & 63;
  int stage_v_42_2 = ((pub_r001215_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((sec_r001215_3_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_43_2 = ((sec_r001215_3_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_43_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_43_2 + 1) & 15;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = ((stage_v_13_1 << 1) ^ (pub_r001215_4_1 >> 1)) & 127;
  int stage_v_44_2 = ((stage_v_13_2 << 1) ^ (pub_r001215_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_44_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_44_2 + 1) & 15;
  out_sink_1 ^= stage_v_44_1 & 63;
  out_sink_2 ^= stage_v_44_2 & 63;
  int stage_v_45_1 = ((stage_v_43_1 << 1) ^ (pub_r001215_1_1 >> 1)) & 127;
  int stage_v_45_2 = ((stage_v_43_2 << 1) ^ (pub_r001215_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_45_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_45_2 + 1) & 15;
  out_sink_1 ^= stage_v_45_1 & 63;
  out_sink_2 ^= stage_v_45_2 & 63;
  int stage_v_46_1 = ((pub_r001215_8_1 * 2) + 44) & 63;
  int stage_v_46_2 = ((pub_r001215_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001215_19_1 * 2) + 34) & 63;
  int stage_v_47_2 = ((pub_r001215_19_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001215_10_1 * 2) + 37) & 63;
  int stage_v_48_2 = ((pub_r001215_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((stage_v_18_1 << 1) ^ (pub_r001215_1_1 >> 1)) & 127;
  int stage_v_49_2 = ((stage_v_18_2 << 1) ^ (pub_r001215_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_49_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_49_2 + 1) & 15;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = ((pub_r001215_6_1 * 2) + 46) & 63;
  int stage_v_50_2 = ((pub_r001215_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001215_15_1 * 2) + 33) & 63;
  int stage_v_51_2 = ((pub_r001215_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001215_16_1 * 2) + 15) & 63;
  int stage_v_52_2 = ((pub_r001215_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001215_6_1 * 2) + 17) & 63;
  int stage_v_53_2 = ((pub_r001215_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((stage_v_22_1 << 1) ^ (pub_r001215_2_1 >> 1)) & 127;
  int stage_v_54_2 = ((stage_v_22_2 << 1) ^ (pub_r001215_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_54_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_54_2 + 1) & 15;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = ((pub_r001215_0_1 * 2) + 40) & 63;
  int stage_v_55_2 = ((pub_r001215_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001215_17_1 * 2) + 15) & 63;
  int stage_v_56_2 = ((pub_r001215_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001215_6_1 * 2) + 21) & 63;
  int stage_v_57_2 = ((pub_r001215_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001215_5_1 * 2) + 33) & 63;
  int stage_v_58_2 = ((pub_r001215_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((sec_r001215_8_1 << 1) ^ (pub_r001215_18_1 >> 1)) & 127;
  int stage_v_59_2 = ((sec_r001215_8_2 << 1) ^ (pub_r001215_18_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_59_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_59_2 + 1) & 15;
  out_sink_1 ^= stage_v_59_1 & 63;
  out_sink_2 ^= stage_v_59_2 & 63;
  int stage_v_60_1 = ((pub_r001215_1_1 * 2) + 9) & 63;
  int stage_v_60_2 = ((pub_r001215_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((stage_v_44_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_61_2 = ((stage_v_44_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_61_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_61_2 + 1) & 15;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = ((stage_v_34_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_62_2 = ((stage_v_34_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_62_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_62_2 + 1) & 15;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = ((stage_v_27_1 << 1) ^ (pub_r001215_4_1 >> 1)) & 127;
  int stage_v_63_2 = ((stage_v_27_2 << 1) ^ (pub_r001215_4_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_63_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_63_2 + 1) & 15;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = ((pub_r001215_2_1 * 2) + 29) & 63;
  int stage_v_64_2 = ((pub_r001215_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((sec_r001215_13_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_65_2 = ((sec_r001215_13_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_65_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_65_2 + 1) & 15;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = ((stage_v_44_1 << 1) ^ (pub_r001215_2_1 >> 1)) & 127;
  int stage_v_66_2 = ((stage_v_44_2 << 1) ^ (pub_r001215_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_66_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_66_2 + 1) & 15;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = ((pub_r001215_9_1 * 2) + 34) & 63;
  int stage_v_67_2 = ((pub_r001215_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((sec_r001215_0_1 << 1) ^ (pub_r001215_16_1 >> 1)) & 127;
  int stage_v_68_2 = ((sec_r001215_0_2 << 1) ^ (pub_r001215_16_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_68_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_68_2 + 1) & 15;
  out_sink_1 ^= stage_v_68_1 & 63;
  out_sink_2 ^= stage_v_68_2 & 63;
  int stage_v_69_1 = ((pub_r001215_9_1 * 2) + 35) & 63;
  int stage_v_69_2 = ((pub_r001215_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001215_2_1 * 2) + 7) & 63;
  int stage_v_70_2 = ((pub_r001215_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((stage_v_43_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_71_2 = ((stage_v_43_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_71_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_71_2 + 1) & 15;
  out_sink_1 ^= stage_v_71_1 & 63;
  out_sink_2 ^= stage_v_71_2 & 63;
  int stage_v_72_1 = ((stage_v_13_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_72_2 = ((stage_v_13_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_72_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_72_2 + 1) & 15;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = ((pub_r001215_13_1 * 2) + 6) & 63;
  int stage_v_73_2 = ((pub_r001215_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((sec_r001215_12_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_74_2 = ((sec_r001215_12_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_74_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_74_2 + 1) & 15;
  out_sink_1 ^= stage_v_74_1 & 63;
  out_sink_2 ^= stage_v_74_2 & 63;
  int stage_v_75_1 = ((stage_v_28_1 << 1) ^ (pub_r001215_2_1 >> 1)) & 127;
  int stage_v_75_2 = ((stage_v_28_2 << 1) ^ (pub_r001215_2_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_75_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_75_2 + 1) & 15;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = ((stage_v_32_1 << 1) ^ (pub_r001215_7_1 >> 1)) & 127;
  int stage_v_76_2 = ((stage_v_32_2 << 1) ^ (pub_r001215_7_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_76_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_76_2 + 1) & 15;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = ((sec_r001215_10_1 << 1) ^ (pub_r001215_11_1 >> 1)) & 127;
  int stage_v_77_2 = ((sec_r001215_10_2 << 1) ^ (pub_r001215_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_77_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_77_2 + 1) & 15;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = ((sec_r001215_9_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_78_2 = ((sec_r001215_9_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_78_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_78_2 + 1) & 15;
  out_sink_1 ^= stage_v_78_1 & 63;
  out_sink_2 ^= stage_v_78_2 & 63;
  int stage_v_79_1 = ((stage_v_27_1 << 1) ^ (pub_r001215_8_1 >> 1)) & 127;
  int stage_v_79_2 = ((stage_v_27_2 << 1) ^ (pub_r001215_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_79_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_79_2 + 1) & 15;
  out_sink_1 ^= stage_v_79_1 & 63;
  out_sink_2 ^= stage_v_79_2 & 63;
  int stage_v_80_1 = ((helper_flow_3_1 << 1) ^ (pub_r001215_5_1 >> 1)) & 127;
  int stage_v_80_2 = ((helper_flow_3_2 << 1) ^ (pub_r001215_5_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_80_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_80_2 + 1) & 15;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = ((pub_r001215_10_1 * 2) + 39) & 63;
  int stage_v_81_2 = ((pub_r001215_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001215_17_1 * 2) + 18) & 63;
  int stage_v_82_2 = ((pub_r001215_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001215_9_1 * 2) + 32) & 63;
  int stage_v_83_2 = ((pub_r001215_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((helper_flow_5_1 << 1) ^ (pub_r001215_10_1 >> 1)) & 127;
  int stage_v_84_2 = ((helper_flow_5_2 << 1) ^ (pub_r001215_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_84_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_84_2 + 1) & 15;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = ((sec_r001215_2_1 << 1) ^ (pub_r001215_9_1 >> 1)) & 127;
  int stage_v_85_2 = ((sec_r001215_2_2 << 1) ^ (pub_r001215_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_85_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_85_2 + 1) & 15;
  out_sink_1 ^= stage_v_85_1 & 63;
  out_sink_2 ^= stage_v_85_2 & 63;
  int stage_v_86_1 = ((stage_v_79_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_86_2 = ((stage_v_79_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_86_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_86_2 + 1) & 15;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = ((pub_r001215_15_1 * 2) + 29) & 63;
  int stage_v_87_2 = ((pub_r001215_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((sec_r001215_6_1 << 1) ^ (pub_r001215_5_1 >> 1)) & 127;
  int stage_v_88_2 = ((sec_r001215_6_2 << 1) ^ (pub_r001215_5_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_88_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_88_2 + 1) & 15;
  out_sink_1 ^= stage_v_88_1 & 63;
  out_sink_2 ^= stage_v_88_2 & 63;
  int stage_v_89_1 = ((stage_v_59_1 << 1) ^ (pub_r001215_8_1 >> 1)) & 127;
  int stage_v_89_2 = ((stage_v_59_2 << 1) ^ (pub_r001215_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_89_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_89_2 + 1) & 15;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = ((stage_v_5_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_90_2 = ((stage_v_5_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_90_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_90_2 + 1) & 15;
  out_sink_1 ^= stage_v_90_1 & 63;
  out_sink_2 ^= stage_v_90_2 & 63;
  int stage_v_91_1 = ((pub_r001215_4_1 * 2) + 33) & 63;
  int stage_v_91_2 = ((pub_r001215_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001215_17_1 * 2) + 30) & 63;
  int stage_v_92_2 = ((pub_r001215_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((sec_r001215_16_1 << 1) ^ (pub_r001215_10_1 >> 1)) & 127;
  int stage_v_93_2 = ((sec_r001215_16_2 << 1) ^ (pub_r001215_10_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_93_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_93_2 + 1) & 15;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = ((stage_v_20_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_94_2 = ((stage_v_20_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_94_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_94_2 + 1) & 15;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = ((stage_v_1_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_95_2 = ((stage_v_1_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_95_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_95_2 + 1) & 15;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = ((sec_r001215_0_1 << 1) ^ (pub_r001215_9_1 >> 1)) & 127;
  int stage_v_96_2 = ((sec_r001215_0_2 << 1) ^ (pub_r001215_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_96_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_96_2 + 1) & 15;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = ((pub_r001215_11_1 * 2) + 38) & 63;
  int stage_v_97_2 = ((pub_r001215_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001215_3_1 * 2) + 11) & 63;
  int stage_v_98_2 = ((pub_r001215_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001215_16_1 * 2) + 6) & 63;
  int stage_v_99_2 = ((pub_r001215_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001215_3_1 * 2) + 34) & 63;
  int stage_v_100_2 = ((pub_r001215_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((stage_v_65_1 << 1) ^ (pub_r001215_3_1 >> 1)) & 127;
  int stage_v_101_2 = ((stage_v_65_2 << 1) ^ (pub_r001215_3_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_101_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_101_2 + 1) & 15;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = ((stage_v_30_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_102_2 = ((stage_v_30_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_102_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_102_2 + 1) & 15;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = ((stage_v_66_1 << 1) ^ (pub_r001215_10_1 >> 1)) & 127;
  int stage_v_103_2 = ((stage_v_66_2 << 1) ^ (pub_r001215_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_103_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_103_2 + 1) & 15;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = ((pub_r001215_0_1 * 2) + 23) & 63;
  int stage_v_104_2 = ((pub_r001215_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001215_8_1 * 2) + 6) & 63;
  int stage_v_105_2 = ((pub_r001215_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((stage_v_79_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_106_2 = ((stage_v_79_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_106_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_106_2 + 1) & 15;
  out_sink_1 ^= stage_v_106_1 & 63;
  out_sink_2 ^= stage_v_106_2 & 63;
  int stage_v_107_1 = ((stage_v_43_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_107_2 = ((stage_v_43_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_107_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_107_2 + 1) & 15;
  out_sink_1 ^= stage_v_107_1 & 63;
  out_sink_2 ^= stage_v_107_2 & 63;
  int stage_v_108_1 = ((pub_r001215_11_1 * 2) + 39) & 63;
  int stage_v_108_2 = ((pub_r001215_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001215_2_1 * 2) + 17) & 63;
  int stage_v_109_2 = ((pub_r001215_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((stage_v_88_1 << 1) ^ (pub_r001215_12_1 >> 1)) & 127;
  int stage_v_110_2 = ((stage_v_88_2 << 1) ^ (pub_r001215_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_110_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_110_2 + 1) & 15;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = ((pub_r001215_5_1 * 2) + 24) & 63;
  int stage_v_111_2 = ((pub_r001215_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001215_5_1 * 2) + 13) & 63;
  int stage_v_112_2 = ((pub_r001215_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001215_18_1 * 2) + 35) & 63;
  int stage_v_113_2 = ((pub_r001215_18_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001215_3_1 * 2) + 7) & 63;
  int stage_v_114_2 = ((pub_r001215_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((sec_r001215_16_1 << 1) ^ (pub_r001215_10_1 >> 1)) & 127;
  int stage_v_115_2 = ((sec_r001215_16_2 << 1) ^ (pub_r001215_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_115_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_115_2 + 1) & 15;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = ((pub_r001215_14_1 * 2) + 26) & 63;
  int stage_v_116_2 = ((pub_r001215_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001215_6_1 * 2) + 29) & 63;
  int stage_v_117_2 = ((pub_r001215_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((stage_v_43_1 << 1) ^ (pub_r001215_8_1 >> 1)) & 127;
  int stage_v_118_2 = ((stage_v_43_2 << 1) ^ (pub_r001215_8_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_118_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_118_2 + 1) & 15;
  out_sink_1 ^= stage_v_118_1 & 63;
  out_sink_2 ^= stage_v_118_2 & 63;
  int stage_v_119_1 = ((pub_r001215_1_1 * 2) + 28) & 63;
  int stage_v_119_2 = ((pub_r001215_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001215_4_1 * 2) + 29) & 63;
  int stage_v_120_2 = ((pub_r001215_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((stage_v_6_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_121_2 = ((stage_v_6_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_121_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_121_2 + 1) & 15;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = ((stage_v_94_1 << 1) ^ (pub_r001215_11_1 >> 1)) & 127;
  int stage_v_122_2 = ((stage_v_94_2 << 1) ^ (pub_r001215_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_122_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_122_2 + 1) & 15;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = ((stage_v_90_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_123_2 = ((stage_v_90_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_123_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_123_2 + 1) & 15;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = ((pub_r001215_0_1 * 2) + 39) & 63;
  int stage_v_124_2 = ((pub_r001215_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001215_19_1 * 2) + 5) & 63;
  int stage_v_125_2 = ((pub_r001215_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((stage_v_45_1 << 1) ^ (pub_r001215_19_1 >> 1)) & 127;
  int stage_v_126_2 = ((stage_v_45_2 << 1) ^ (pub_r001215_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_126_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_126_2 + 1) & 15;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = ((pub_r001215_17_1 * 2) + 21) & 63;
  int stage_v_127_2 = ((pub_r001215_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((stage_v_115_1 << 1) ^ (pub_r001215_16_1 >> 1)) & 127;
  int stage_v_128_2 = ((stage_v_115_2 << 1) ^ (pub_r001215_16_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_128_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_128_2 + 1) & 15;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = ((pub_r001215_2_1 * 2) + 18) & 63;
  int stage_v_129_2 = ((pub_r001215_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((stage_v_66_1 << 1) ^ (pub_r001215_16_1 >> 1)) & 127;
  int stage_v_130_2 = ((stage_v_66_2 << 1) ^ (pub_r001215_16_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_130_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_130_2 + 1) & 15;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = ((pub_r001215_7_1 * 2) + 45) & 63;
  int stage_v_131_2 = ((pub_r001215_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((sec_r001215_9_1 << 1) ^ (pub_r001215_2_1 >> 1)) & 127;
  int stage_v_132_2 = ((sec_r001215_9_2 << 1) ^ (pub_r001215_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_132_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_132_2 + 1) & 15;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = ((stage_v_23_1 << 1) ^ (pub_r001215_6_1 >> 1)) & 127;
  int stage_v_133_2 = ((stage_v_23_2 << 1) ^ (pub_r001215_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_133_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_133_2 + 1) & 15;
  out_sink_1 ^= stage_v_133_1 & 63;
  out_sink_2 ^= stage_v_133_2 & 63;
  int stage_v_134_1 = ((sec_r001215_9_1 << 1) ^ (pub_r001215_12_1 >> 1)) & 127;
  int stage_v_134_2 = ((sec_r001215_9_2 << 1) ^ (pub_r001215_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_134_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_134_2 + 1) & 15;
  out_sink_1 ^= stage_v_134_1 & 63;
  out_sink_2 ^= stage_v_134_2 & 63;
  int stage_v_135_1 = ((stage_v_78_1 << 1) ^ (pub_r001215_8_1 >> 1)) & 127;
  int stage_v_135_2 = ((stage_v_78_2 << 1) ^ (pub_r001215_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_135_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_135_2 + 1) & 15;
  out_sink_1 ^= stage_v_135_1 & 63;
  out_sink_2 ^= stage_v_135_2 & 63;
  int stage_v_136_1 = ((stage_v_72_1 << 1) ^ (pub_r001215_10_1 >> 1)) & 127;
  int stage_v_136_2 = ((stage_v_72_2 << 1) ^ (pub_r001215_10_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_136_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_136_2 + 1) & 15;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = ((stage_v_134_1 << 1) ^ (pub_r001215_3_1 >> 1)) & 127;
  int stage_v_137_2 = ((stage_v_134_2 << 1) ^ (pub_r001215_3_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_137_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_137_2 + 1) & 15;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = ((pub_r001215_8_1 * 2) + 33) & 63;
  int stage_v_138_2 = ((pub_r001215_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((stage_v_11_1 << 1) ^ (pub_r001215_12_1 >> 1)) & 127;
  int stage_v_139_2 = ((stage_v_11_2 << 1) ^ (pub_r001215_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_139_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_139_2 + 1) & 15;
  out_sink_1 ^= stage_v_139_1 & 63;
  out_sink_2 ^= stage_v_139_2 & 63;
  int stage_v_140_1 = ((stage_v_3_1 << 1) ^ (pub_r001215_17_1 >> 1)) & 127;
  int stage_v_140_2 = ((stage_v_3_2 << 1) ^ (pub_r001215_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_140_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_140_2 + 1) & 15;
  out_sink_1 ^= stage_v_140_1 & 63;
  out_sink_2 ^= stage_v_140_2 & 63;
  int stage_v_141_1 = ((stage_v_30_1 << 1) ^ (pub_r001215_2_1 >> 1)) & 127;
  int stage_v_141_2 = ((stage_v_30_2 << 1) ^ (pub_r001215_2_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_141_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_141_2 + 1) & 15;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = ((pub_r001215_1_1 * 2) + 23) & 63;
  int stage_v_142_2 = ((pub_r001215_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001215_13_1 * 2) + 32) & 63;
  int stage_v_143_2 = ((pub_r001215_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001215_14_1 * 2) + 29) & 63;
  int stage_v_144_2 = ((pub_r001215_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((stage_v_101_1 << 1) ^ (pub_r001215_1_1 >> 1)) & 127;
  int stage_v_145_2 = ((stage_v_101_2 << 1) ^ (pub_r001215_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_145_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_145_2 + 1) & 15;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = ((stage_v_90_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_146_2 = ((stage_v_90_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_146_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_146_2 + 1) & 15;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = ((pub_r001215_18_1 * 2) + 9) & 63;
  int stage_v_147_2 = ((pub_r001215_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001215_20_1 * 2) + 8) & 63;
  int stage_v_148_2 = ((pub_r001215_20_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001215_13_1 * 2) + 43) & 63;
  int stage_v_149_2 = ((pub_r001215_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((stage_v_43_1 << 1) ^ (pub_r001215_7_1 >> 1)) & 127;
  int stage_v_150_2 = ((stage_v_43_2 << 1) ^ (pub_r001215_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_150_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_150_2 + 1) & 15;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = ((stage_v_14_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_151_2 = ((stage_v_14_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_151_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_151_2 + 1) & 15;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = ((pub_r001215_19_1 * 2) + 38) & 63;
  int stage_v_152_2 = ((pub_r001215_19_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((sec_r001215_5_1 << 1) ^ (pub_r001215_16_1 >> 1)) & 127;
  int stage_v_153_2 = ((sec_r001215_5_2 << 1) ^ (pub_r001215_16_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_153_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_153_2 + 1) & 15;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = ((stage_v_85_1 << 1) ^ (pub_r001215_9_1 >> 1)) & 127;
  int stage_v_154_2 = ((stage_v_85_2 << 1) ^ (pub_r001215_9_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_154_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_154_2 + 1) & 15;
  out_sink_1 ^= stage_v_154_1 & 63;
  out_sink_2 ^= stage_v_154_2 & 63;
  int stage_v_155_1 = ((stage_v_88_1 << 1) ^ (pub_r001215_3_1 >> 1)) & 127;
  int stage_v_155_2 = ((stage_v_88_2 << 1) ^ (pub_r001215_3_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_155_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_155_2 + 1) & 15;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = ((stage_v_11_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_156_2 = ((stage_v_11_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_156_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_156_2 + 1) & 15;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = ((pub_r001215_19_1 * 2) + 9) & 63;
  int stage_v_157_2 = ((pub_r001215_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((stage_v_146_1 << 1) ^ (pub_r001215_18_1 >> 1)) & 127;
  int stage_v_158_2 = ((stage_v_146_2 << 1) ^ (pub_r001215_18_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_158_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_158_2 + 1) & 15;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = ((stage_v_107_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_159_2 = ((stage_v_107_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_159_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_159_2 + 1) & 15;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = ((stage_v_76_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_160_2 = ((stage_v_76_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_160_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_160_2 + 1) & 15;
  out_sink_1 ^= stage_v_160_1 & 63;
  out_sink_2 ^= stage_v_160_2 & 63;
  int stage_v_161_1 = ((pub_r001215_20_1 * 2) + 20) & 63;
  int stage_v_161_2 = ((pub_r001215_20_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((stage_v_30_1 << 1) ^ (pub_r001215_3_1 >> 1)) & 127;
  int stage_v_162_2 = ((stage_v_30_2 << 1) ^ (pub_r001215_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_162_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_162_2 + 1) & 15;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = ((pub_r001215_15_1 * 2) + 16) & 63;
  int stage_v_163_2 = ((pub_r001215_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_79_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_164_2 = ((stage_v_79_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_164_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_164_2 + 1) & 15;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = ((pub_r001215_15_1 * 2) + 23) & 63;
  int stage_v_165_2 = ((pub_r001215_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((stage_v_115_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_166_2 = ((stage_v_115_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_166_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_166_2 + 1) & 15;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = ((pub_r001215_18_1 * 2) + 26) & 63;
  int stage_v_167_2 = ((pub_r001215_18_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((sec_r001215_12_1 << 1) ^ (pub_r001215_3_1 >> 1)) & 127;
  int stage_v_168_2 = ((sec_r001215_12_2 << 1) ^ (pub_r001215_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_168_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_168_2 + 1) & 15;
  out_sink_1 ^= stage_v_168_1 & 63;
  out_sink_2 ^= stage_v_168_2 & 63;
  int stage_v_169_1 = ((stage_v_8_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_169_2 = ((stage_v_8_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_169_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_169_2 + 1) & 15;
  out_sink_1 ^= stage_v_169_1 & 63;
  out_sink_2 ^= stage_v_169_2 & 63;
  int stage_v_170_1 = ((pub_r001215_12_1 * 2) + 24) & 63;
  int stage_v_170_2 = ((pub_r001215_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001215_17_1 * 2) + 10) & 63;
  int stage_v_171_2 = ((pub_r001215_17_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_154_1 << 1) ^ (pub_r001215_17_1 >> 1)) & 127;
  int stage_v_172_2 = ((stage_v_154_2 << 1) ^ (pub_r001215_17_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_172_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_172_2 + 1) & 15;
  out_sink_1 ^= stage_v_172_1 & 63;
  out_sink_2 ^= stage_v_172_2 & 63;
  int stage_v_173_1 = ((stage_v_61_1 << 1) ^ (pub_r001215_9_1 >> 1)) & 127;
  int stage_v_173_2 = ((stage_v_61_2 << 1) ^ (pub_r001215_9_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_173_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_173_2 + 1) & 15;
  out_sink_1 ^= stage_v_173_1 & 63;
  out_sink_2 ^= stage_v_173_2 & 63;
  int stage_v_174_1 = ((stage_v_126_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_174_2 = ((stage_v_126_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_174_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_174_2 + 1) & 15;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = ((stage_v_136_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_175_2 = ((stage_v_136_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_175_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_175_2 + 1) & 15;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = ((sec_r001215_8_1 << 1) ^ (pub_r001215_7_1 >> 1)) & 127;
  int stage_v_176_2 = ((sec_r001215_8_2 << 1) ^ (pub_r001215_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_176_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_176_2 + 1) & 15;
  out_sink_1 ^= stage_v_176_1 & 63;
  out_sink_2 ^= stage_v_176_2 & 63;
  int stage_v_177_1 = ((pub_r001215_0_1 * 2) + 23) & 63;
  int stage_v_177_2 = ((pub_r001215_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((helper_flow_2_1 << 1) ^ (pub_r001215_19_1 >> 1)) & 127;
  int stage_v_178_2 = ((helper_flow_2_2 << 1) ^ (pub_r001215_19_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_178_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_178_2 + 1) & 15;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = ((stage_v_80_1 << 1) ^ (pub_r001215_2_1 >> 1)) & 127;
  int stage_v_179_2 = ((stage_v_80_2 << 1) ^ (pub_r001215_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_179_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_179_2 + 1) & 15;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = ((pub_r001215_11_1 * 2) + 15) & 63;
  int stage_v_180_2 = ((pub_r001215_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((stage_v_18_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_181_2 = ((stage_v_18_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_181_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_181_2 + 1) & 15;
  out_sink_1 ^= stage_v_181_1 & 63;
  out_sink_2 ^= stage_v_181_2 & 63;
  int stage_v_182_1 = ((sec_r001215_7_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_182_2 = ((sec_r001215_7_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_182_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_182_2 + 1) & 15;
  out_sink_1 ^= stage_v_182_1 & 63;
  out_sink_2 ^= stage_v_182_2 & 63;
  int stage_v_183_1 = ((helper_flow_4_1 << 1) ^ (pub_r001215_8_1 >> 1)) & 127;
  int stage_v_183_2 = ((helper_flow_4_2 << 1) ^ (pub_r001215_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_183_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_183_2 + 1) & 15;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = ((stage_v_153_1 << 1) ^ (pub_r001215_1_1 >> 1)) & 127;
  int stage_v_184_2 = ((stage_v_153_2 << 1) ^ (pub_r001215_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_184_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_184_2 + 1) & 15;
  out_sink_1 ^= stage_v_184_1 & 63;
  out_sink_2 ^= stage_v_184_2 & 63;
  int stage_v_185_1 = ((stage_v_95_1 << 1) ^ (pub_r001215_18_1 >> 1)) & 127;
  int stage_v_185_2 = ((stage_v_95_2 << 1) ^ (pub_r001215_18_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_185_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_185_2 + 1) & 15;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = ((pub_r001215_14_1 * 2) + 11) & 63;
  int stage_v_186_2 = ((pub_r001215_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001215_4_1 * 2) + 10) & 63;
  int stage_v_187_2 = ((pub_r001215_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001215_13_1 * 2) + 25) & 63;
  int stage_v_188_2 = ((pub_r001215_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((stage_v_49_1 << 1) ^ (pub_r001215_12_1 >> 1)) & 127;
  int stage_v_189_2 = ((stage_v_49_2 << 1) ^ (pub_r001215_12_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_189_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_189_2 + 1) & 15;
  out_sink_1 ^= stage_v_189_1 & 63;
  out_sink_2 ^= stage_v_189_2 & 63;
  int stage_v_190_1 = ((stage_v_20_1 << 1) ^ (pub_r001215_6_1 >> 1)) & 127;
  int stage_v_190_2 = ((stage_v_20_2 << 1) ^ (pub_r001215_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_190_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_190_2 + 1) & 15;
  out_sink_1 ^= stage_v_190_1 & 63;
  out_sink_2 ^= stage_v_190_2 & 63;
  int stage_v_191_1 = ((sec_r001215_9_1 << 1) ^ (pub_r001215_19_1 >> 1)) & 127;
  int stage_v_191_2 = ((sec_r001215_9_2 << 1) ^ (pub_r001215_19_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_191_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_191_2 + 1) & 15;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = ((stage_v_140_1 << 1) ^ (pub_r001215_10_1 >> 1)) & 127;
  int stage_v_192_2 = ((stage_v_140_2 << 1) ^ (pub_r001215_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_192_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_192_2 + 1) & 15;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = ((stage_v_154_1 << 1) ^ (pub_r001215_18_1 >> 1)) & 127;
  int stage_v_193_2 = ((stage_v_154_2 << 1) ^ (pub_r001215_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_193_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_193_2 + 1) & 15;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = ((pub_r001215_6_1 * 2) + 31) & 63;
  int stage_v_194_2 = ((pub_r001215_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001215_17_1 * 2) + 5) & 63;
  int stage_v_195_2 = ((pub_r001215_17_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((stage_v_10_1 << 1) ^ (pub_r001215_12_1 >> 1)) & 127;
  int stage_v_196_2 = ((stage_v_10_2 << 1) ^ (pub_r001215_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_196_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_196_2 + 1) & 15;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = ((stage_v_16_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_197_2 = ((stage_v_16_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_197_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_197_2 + 1) & 15;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = ((stage_v_72_1 << 1) ^ (pub_r001215_15_1 >> 1)) & 127;
  int stage_v_198_2 = ((stage_v_72_2 << 1) ^ (pub_r001215_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_198_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_198_2 + 1) & 15;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = ((pub_r001215_7_1 * 2) + 44) & 63;
  int stage_v_199_2 = ((pub_r001215_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((stage_v_166_1 << 1) ^ (pub_r001215_11_1 >> 1)) & 127;
  int stage_v_200_2 = ((stage_v_166_2 << 1) ^ (pub_r001215_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_200_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_200_2 + 1) & 15;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = ((pub_r001215_8_1 * 2) + 9) & 63;
  int stage_v_201_2 = ((pub_r001215_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001215_15_1 * 2) + 12) & 63;
  int stage_v_202_2 = ((pub_r001215_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001215_14_1 * 2) + 32) & 63;
  int stage_v_203_2 = ((pub_r001215_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((helper_flow_1_1 << 1) ^ (pub_r001215_15_1 >> 1)) & 127;
  int stage_v_204_2 = ((helper_flow_1_2 << 1) ^ (pub_r001215_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_204_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_204_2 + 1) & 15;
  out_sink_1 ^= stage_v_204_1 & 63;
  out_sink_2 ^= stage_v_204_2 & 63;
  int stage_v_205_1 = ((helper_flow_1_1 << 1) ^ (pub_r001215_2_1 >> 1)) & 127;
  int stage_v_205_2 = ((helper_flow_1_2 << 1) ^ (pub_r001215_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_205_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_205_2 + 1) & 15;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = ((pub_r001215_2_1 * 2) + 25) & 63;
  int stage_v_206_2 = ((pub_r001215_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001215_9_1 * 2) + 29) & 63;
  int stage_v_207_2 = ((pub_r001215_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((stage_v_123_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_208_2 = ((stage_v_123_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_208_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_208_2 + 1) & 15;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = ((stage_v_34_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_209_2 = ((stage_v_34_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_209_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_209_2 + 1) & 15;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = ((stage_v_204_1 << 1) ^ (pub_r001215_5_1 >> 1)) & 127;
  int stage_v_210_2 = ((stage_v_204_2 << 1) ^ (pub_r001215_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_210_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_210_2 + 1) & 15;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = ((stage_v_192_1 << 1) ^ (pub_r001215_19_1 >> 1)) & 127;
  int stage_v_211_2 = ((stage_v_192_2 << 1) ^ (pub_r001215_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_211_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_211_2 + 1) & 15;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = ((stage_v_43_1 << 1) ^ (pub_r001215_15_1 >> 1)) & 127;
  int stage_v_212_2 = ((stage_v_43_2 << 1) ^ (pub_r001215_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_212_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_212_2 + 1) & 15;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = ((stage_v_1_1 << 1) ^ (pub_r001215_17_1 >> 1)) & 127;
  int stage_v_213_2 = ((stage_v_1_2 << 1) ^ (pub_r001215_17_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_213_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_213_2 + 1) & 15;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = ((pub_r001215_18_1 * 2) + 48) & 63;
  int stage_v_214_2 = ((pub_r001215_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((sec_r001215_3_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_215_2 = ((sec_r001215_3_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_215_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_215_2 + 1) & 15;
  out_sink_1 ^= stage_v_215_1 & 63;
  out_sink_2 ^= stage_v_215_2 & 63;
  int stage_v_216_1 = ((stage_v_30_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_216_2 = ((stage_v_30_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_216_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_216_2 + 1) & 15;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = ((pub_r001215_14_1 * 2) + 13) & 63;
  int stage_v_217_2 = ((pub_r001215_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001215_14_1 * 2) + 16) & 63;
  int stage_v_218_2 = ((pub_r001215_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((stage_v_101_1 << 1) ^ (pub_r001215_16_1 >> 1)) & 127;
  int stage_v_219_2 = ((stage_v_101_2 << 1) ^ (pub_r001215_16_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_219_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_219_2 + 1) & 15;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = ((pub_r001215_13_1 * 2) + 26) & 63;
  int stage_v_220_2 = ((pub_r001215_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001215_0_1 * 2) + 31) & 63;
  int stage_v_221_2 = ((pub_r001215_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((sec_r001215_1_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_222_2 = ((sec_r001215_1_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_222_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_222_2 + 1) & 15;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = ((stage_v_24_1 << 1) ^ (pub_r001215_4_1 >> 1)) & 127;
  int stage_v_223_2 = ((stage_v_24_2 << 1) ^ (pub_r001215_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_223_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_223_2 + 1) & 15;
  out_sink_1 ^= stage_v_223_1 & 63;
  out_sink_2 ^= stage_v_223_2 & 63;
  int stage_v_224_1 = ((pub_r001215_15_1 * 2) + 9) & 63;
  int stage_v_224_2 = ((pub_r001215_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((stage_v_121_1 << 1) ^ (pub_r001215_8_1 >> 1)) & 127;
  int stage_v_225_2 = ((stage_v_121_2 << 1) ^ (pub_r001215_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_225_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_225_2 + 1) & 15;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = ((sec_r001215_16_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_226_2 = ((sec_r001215_16_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_226_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_226_2 + 1) & 15;
  out_sink_1 ^= stage_v_226_1 & 63;
  out_sink_2 ^= stage_v_226_2 & 63;
  int stage_v_227_1 = ((pub_r001215_20_1 * 2) + 42) & 63;
  int stage_v_227_2 = ((pub_r001215_20_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001215_1_1 * 2) + 42) & 63;
  int stage_v_228_2 = ((pub_r001215_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001215_2_1 * 2) + 46) & 63;
  int stage_v_229_2 = ((pub_r001215_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((stage_v_176_1 << 1) ^ (pub_r001215_12_1 >> 1)) & 127;
  int stage_v_230_2 = ((stage_v_176_2 << 1) ^ (pub_r001215_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_230_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_230_2 + 1) & 15;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = ((sec_r001215_5_1 << 1) ^ (pub_r001215_17_1 >> 1)) & 127;
  int stage_v_231_2 = ((sec_r001215_5_2 << 1) ^ (pub_r001215_17_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_231_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_231_2 + 1) & 15;
  out_sink_1 ^= stage_v_231_1 & 63;
  out_sink_2 ^= stage_v_231_2 & 63;
  int stage_v_232_1 = ((pub_r001215_9_1 * 2) + 13) & 63;
  int stage_v_232_2 = ((pub_r001215_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((stage_v_209_1 << 1) ^ (pub_r001215_15_1 >> 1)) & 127;
  int stage_v_233_2 = ((stage_v_209_2 << 1) ^ (pub_r001215_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_233_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_233_2 + 1) & 15;
  out_sink_1 ^= stage_v_233_1 & 63;
  out_sink_2 ^= stage_v_233_2 & 63;
  int stage_v_234_1 = ((pub_r001215_17_1 * 2) + 15) & 63;
  int stage_v_234_2 = ((pub_r001215_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001215_9_1 * 2) + 28) & 63;
  int stage_v_235_2 = ((pub_r001215_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001215_8_1 * 2) + 10) & 63;
  int stage_v_236_2 = ((pub_r001215_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((sec_r001215_9_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_237_2 = ((sec_r001215_9_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_237_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_237_2 + 1) & 15;
  out_sink_1 ^= stage_v_237_1 & 63;
  out_sink_2 ^= stage_v_237_2 & 63;
  int stage_v_238_1 = ((pub_r001215_6_1 * 2) + 19) & 63;
  int stage_v_238_2 = ((pub_r001215_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001215_4_1 * 2) + 33) & 63;
  int stage_v_239_2 = ((pub_r001215_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((stage_v_208_1 << 1) ^ (pub_r001215_10_1 >> 1)) & 127;
  int stage_v_240_2 = ((stage_v_208_2 << 1) ^ (pub_r001215_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_240_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_240_2 + 1) & 15;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = ((stage_v_4_1 << 1) ^ (pub_r001215_6_1 >> 1)) & 127;
  int stage_v_241_2 = ((stage_v_4_2 << 1) ^ (pub_r001215_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_241_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_241_2 + 1) & 15;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = ((stage_v_5_1 << 1) ^ (pub_r001215_3_1 >> 1)) & 127;
  int stage_v_242_2 = ((stage_v_5_2 << 1) ^ (pub_r001215_3_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_242_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_242_2 + 1) & 15;
  out_sink_1 ^= stage_v_242_1 & 63;
  out_sink_2 ^= stage_v_242_2 & 63;
  int stage_v_243_1 = ((stage_v_241_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_243_2 = ((stage_v_241_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_243_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_243_2 + 1) & 15;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = ((pub_r001215_5_1 * 2) + 40) & 63;
  int stage_v_244_2 = ((pub_r001215_5_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((stage_v_74_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_245_2 = ((stage_v_74_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_245_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_245_2 + 1) & 15;
  out_sink_1 ^= stage_v_245_1 & 63;
  out_sink_2 ^= stage_v_245_2 & 63;
  int stage_v_246_1 = ((pub_r001215_13_1 * 2) + 19) & 63;
  int stage_v_246_2 = ((pub_r001215_13_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((stage_v_86_1 << 1) ^ (pub_r001215_9_1 >> 1)) & 127;
  int stage_v_247_2 = ((stage_v_86_2 << 1) ^ (pub_r001215_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_247_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_247_2 + 1) & 15;
  out_sink_1 ^= stage_v_247_1 & 63;
  out_sink_2 ^= stage_v_247_2 & 63;
  int stage_v_248_1 = ((stage_v_134_1 << 1) ^ (pub_r001215_12_1 >> 1)) & 127;
  int stage_v_248_2 = ((stage_v_134_2 << 1) ^ (pub_r001215_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_248_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_248_2 + 1) & 15;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = ((stage_v_33_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_249_2 = ((stage_v_33_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_249_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_249_2 + 1) & 15;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = ((pub_r001215_2_1 * 2) + 37) & 63;
  int stage_v_250_2 = ((pub_r001215_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((stage_v_30_1 << 1) ^ (pub_r001215_11_1 >> 1)) & 127;
  int stage_v_251_2 = ((stage_v_30_2 << 1) ^ (pub_r001215_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_251_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_251_2 + 1) & 15;
  out_sink_1 ^= stage_v_251_1 & 63;
  out_sink_2 ^= stage_v_251_2 & 63;
  int stage_v_252_1 = ((stage_v_160_1 << 1) ^ (pub_r001215_10_1 >> 1)) & 127;
  int stage_v_252_2 = ((stage_v_160_2 << 1) ^ (pub_r001215_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_252_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_252_2 + 1) & 15;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = ((pub_r001215_19_1 * 2) + 14) & 63;
  int stage_v_253_2 = ((pub_r001215_19_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((pub_r001215_11_1 * 2) + 21) & 63;
  int stage_v_254_2 = ((pub_r001215_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001215_15_1 * 2) + 34) & 63;
  int stage_v_255_2 = ((pub_r001215_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((stage_v_189_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_256_2 = ((stage_v_189_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_256_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_256_2 + 1) & 15;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = ((pub_r001215_17_1 * 2) + 35) & 63;
  int stage_v_257_2 = ((pub_r001215_17_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001215_15_1 * 2) + 32) & 63;
  int stage_v_258_2 = ((pub_r001215_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((stage_v_88_1 << 1) ^ (pub_r001215_16_1 >> 1)) & 127;
  int stage_v_259_2 = ((stage_v_88_2 << 1) ^ (pub_r001215_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_259_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_259_2 + 1) & 15;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = ((pub_r001215_7_1 * 2) + 35) & 63;
  int stage_v_260_2 = ((pub_r001215_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((stage_v_38_1 << 1) ^ (pub_r001215_2_1 >> 1)) & 127;
  int stage_v_261_2 = ((stage_v_38_2 << 1) ^ (pub_r001215_2_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_261_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_261_2 + 1) & 15;
  out_sink_1 ^= stage_v_261_1 & 63;
  out_sink_2 ^= stage_v_261_2 & 63;
  int stage_v_262_1 = ((stage_v_19_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_262_2 = ((stage_v_19_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_262_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_262_2 + 1) & 15;
  out_sink_1 ^= stage_v_262_1 & 63;
  out_sink_2 ^= stage_v_262_2 & 63;
  int stage_v_263_1 = ((pub_r001215_8_1 * 2) + 35) & 63;
  int stage_v_263_2 = ((pub_r001215_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((pub_r001215_15_1 * 2) + 48) & 63;
  int stage_v_264_2 = ((pub_r001215_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001215_12_1 * 2) + 5) & 63;
  int stage_v_265_2 = ((pub_r001215_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001215_7_1 * 2) + 30) & 63;
  int stage_v_266_2 = ((pub_r001215_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((helper_flow_7_1 << 1) ^ (pub_r001215_9_1 >> 1)) & 127;
  int stage_v_267_2 = ((helper_flow_7_2 << 1) ^ (pub_r001215_9_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_267_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_267_2 + 1) & 15;
  out_sink_1 ^= stage_v_267_1 & 63;
  out_sink_2 ^= stage_v_267_2 & 63;
  int stage_v_268_1 = ((pub_r001215_19_1 * 2) + 30) & 63;
  int stage_v_268_2 = ((pub_r001215_19_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((stage_v_158_1 << 1) ^ (pub_r001215_2_1 >> 1)) & 127;
  int stage_v_269_2 = ((stage_v_158_2 << 1) ^ (pub_r001215_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_269_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_269_2 + 1) & 15;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = ((stage_v_71_1 << 1) ^ (pub_r001215_1_1 >> 1)) & 127;
  int stage_v_270_2 = ((stage_v_71_2 << 1) ^ (pub_r001215_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_270_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_270_2 + 1) & 15;
  out_sink_1 ^= stage_v_270_1 & 63;
  out_sink_2 ^= stage_v_270_2 & 63;
  int stage_v_271_1 = ((pub_r001215_16_1 * 2) + 9) & 63;
  int stage_v_271_2 = ((pub_r001215_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001215_10_1 * 2) + 18) & 63;
  int stage_v_272_2 = ((pub_r001215_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001215_19_1 * 2) + 25) & 63;
  int stage_v_273_2 = ((pub_r001215_19_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((pub_r001215_2_1 * 2) + 17) & 63;
  int stage_v_274_2 = ((pub_r001215_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001215_15_1 * 2) + 20) & 63;
  int stage_v_275_2 = ((pub_r001215_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((stage_v_2_1 << 1) ^ (pub_r001215_16_1 >> 1)) & 127;
  int stage_v_276_2 = ((stage_v_2_2 << 1) ^ (pub_r001215_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_276_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_276_2 + 1) & 15;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = ((pub_r001215_19_1 * 2) + 38) & 63;
  int stage_v_277_2 = ((pub_r001215_19_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((stage_v_205_1 << 1) ^ (pub_r001215_16_1 >> 1)) & 127;
  int stage_v_278_2 = ((stage_v_205_2 << 1) ^ (pub_r001215_16_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_278_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_278_2 + 1) & 15;
  out_sink_1 ^= stage_v_278_1 & 63;
  out_sink_2 ^= stage_v_278_2 & 63;
  int stage_v_279_1 = ((pub_r001215_18_1 * 2) + 42) & 63;
  int stage_v_279_2 = ((pub_r001215_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((stage_v_21_1 << 1) ^ (pub_r001215_12_1 >> 1)) & 127;
  int stage_v_280_2 = ((stage_v_21_2 << 1) ^ (pub_r001215_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_280_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_280_2 + 1) & 15;
  out_sink_1 ^= stage_v_280_1 & 63;
  out_sink_2 ^= stage_v_280_2 & 63;
  int stage_v_281_1 = ((pub_r001215_1_1 * 2) + 11) & 63;
  int stage_v_281_2 = ((pub_r001215_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((stage_v_215_1 << 1) ^ (pub_r001215_16_1 >> 1)) & 127;
  int stage_v_282_2 = ((stage_v_215_2 << 1) ^ (pub_r001215_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_282_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_282_2 + 1) & 15;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = ((pub_r001215_6_1 * 2) + 20) & 63;
  int stage_v_283_2 = ((pub_r001215_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((stage_v_184_1 << 1) ^ (pub_r001215_16_1 >> 1)) & 127;
  int stage_v_284_2 = ((stage_v_184_2 << 1) ^ (pub_r001215_16_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_284_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_284_2 + 1) & 15;
  out_sink_1 ^= stage_v_284_1 & 63;
  out_sink_2 ^= stage_v_284_2 & 63;
  int stage_v_285_1 = ((stage_v_225_1 << 1) ^ (pub_r001215_7_1 >> 1)) & 127;
  int stage_v_285_2 = ((stage_v_225_2 << 1) ^ (pub_r001215_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_285_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_285_2 + 1) & 15;
  out_sink_1 ^= stage_v_285_1 & 63;
  out_sink_2 ^= stage_v_285_2 & 63;
  int stage_v_286_1 = ((stage_v_21_1 << 1) ^ (pub_r001215_9_1 >> 1)) & 127;
  int stage_v_286_2 = ((stage_v_21_2 << 1) ^ (pub_r001215_9_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_286_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_286_2 + 1) & 15;
  out_sink_1 ^= stage_v_286_1 & 63;
  out_sink_2 ^= stage_v_286_2 & 63;
  int stage_v_287_1 = ((sec_r001215_1_1 << 1) ^ (pub_r001215_6_1 >> 1)) & 127;
  int stage_v_287_2 = ((sec_r001215_1_2 << 1) ^ (pub_r001215_6_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_287_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_287_2 + 1) & 15;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = ((pub_r001215_5_1 * 2) + 9) & 63;
  int stage_v_288_2 = ((pub_r001215_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((stage_v_155_1 << 1) ^ (pub_r001215_2_1 >> 1)) & 127;
  int stage_v_289_2 = ((stage_v_155_2 << 1) ^ (pub_r001215_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_289_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_289_2 + 1) & 15;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = ((pub_r001215_6_1 * 2) + 44) & 63;
  int stage_v_290_2 = ((pub_r001215_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((stage_v_243_1 << 1) ^ (pub_r001215_17_1 >> 1)) & 127;
  int stage_v_291_2 = ((stage_v_243_2 << 1) ^ (pub_r001215_17_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_291_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_291_2 + 1) & 15;
  out_sink_1 ^= stage_v_291_1 & 63;
  out_sink_2 ^= stage_v_291_2 & 63;
  int stage_v_292_1 = ((pub_r001215_6_1 * 2) + 38) & 63;
  int stage_v_292_2 = ((pub_r001215_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((stage_v_256_1 << 1) ^ (pub_r001215_4_1 >> 1)) & 127;
  int stage_v_293_2 = ((stage_v_256_2 << 1) ^ (pub_r001215_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_293_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_293_2 + 1) & 15;
  out_sink_1 ^= stage_v_293_1 & 63;
  out_sink_2 ^= stage_v_293_2 & 63;
  int stage_v_294_1 = ((pub_r001215_4_1 * 2) + 35) & 63;
  int stage_v_294_2 = ((pub_r001215_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001215_1_1 * 2) + 44) & 63;
  int stage_v_295_2 = ((pub_r001215_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((stage_v_284_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_296_2 = ((stage_v_284_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_296_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_296_2 + 1) & 15;
  out_sink_1 ^= stage_v_296_1 & 63;
  out_sink_2 ^= stage_v_296_2 & 63;
  int stage_v_297_1 = ((pub_r001215_7_1 * 2) + 12) & 63;
  int stage_v_297_2 = ((pub_r001215_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001215_19_1 * 2) + 31) & 63;
  int stage_v_298_2 = ((pub_r001215_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((helper_flow_0_1 << 1) ^ (pub_r001215_4_1 >> 1)) & 127;
  int stage_v_299_2 = ((helper_flow_0_2 << 1) ^ (pub_r001215_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_299_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_299_2 + 1) & 15;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = ((pub_r001215_7_1 * 2) + 28) & 63;
  int stage_v_300_2 = ((pub_r001215_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((stage_v_130_1 << 1) ^ (pub_r001215_10_1 >> 1)) & 127;
  int stage_v_301_2 = ((stage_v_130_2 << 1) ^ (pub_r001215_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_301_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_301_2 + 1) & 15;
  out_sink_1 ^= stage_v_301_1 & 63;
  out_sink_2 ^= stage_v_301_2 & 63;
  int stage_v_302_1 = ((stage_v_193_1 << 1) ^ (pub_r001215_15_1 >> 1)) & 127;
  int stage_v_302_2 = ((stage_v_193_2 << 1) ^ (pub_r001215_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_302_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_302_2 + 1) & 15;
  out_sink_1 ^= stage_v_302_1 & 63;
  out_sink_2 ^= stage_v_302_2 & 63;
  int stage_v_303_1 = ((pub_r001215_10_1 * 2) + 17) & 63;
  int stage_v_303_2 = ((pub_r001215_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001215_0_1 * 2) + 13) & 63;
  int stage_v_304_2 = ((pub_r001215_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001215_2_1 * 2) + 31) & 63;
  int stage_v_305_2 = ((pub_r001215_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001215_13_1 * 2) + 22) & 63;
  int stage_v_306_2 = ((pub_r001215_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001215_14_1 * 2) + 40) & 63;
  int stage_v_307_2 = ((pub_r001215_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001215_8_1 * 2) + 41) & 63;
  int stage_v_308_2 = ((pub_r001215_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((stage_v_86_1 << 1) ^ (pub_r001215_3_1 >> 1)) & 127;
  int stage_v_309_2 = ((stage_v_86_2 << 1) ^ (pub_r001215_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_309_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_309_2 + 1) & 15;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = ((stage_v_102_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_310_2 = ((stage_v_102_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_310_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_310_2 + 1) & 15;
  out_sink_1 ^= stage_v_310_1 & 63;
  out_sink_2 ^= stage_v_310_2 & 63;
  int stage_v_311_1 = ((pub_r001215_5_1 * 2) + 19) & 63;
  int stage_v_311_2 = ((pub_r001215_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((stage_v_6_1 << 1) ^ (pub_r001215_10_1 >> 1)) & 127;
  int stage_v_312_2 = ((stage_v_6_2 << 1) ^ (pub_r001215_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_312_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_312_2 + 1) & 15;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = ((sec_r001215_12_1 << 1) ^ (pub_r001215_17_1 >> 1)) & 127;
  int stage_v_313_2 = ((sec_r001215_12_2 << 1) ^ (pub_r001215_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_313_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_313_2 + 1) & 15;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = ((pub_r001215_6_1 * 2) + 6) & 63;
  int stage_v_314_2 = ((pub_r001215_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((stage_v_96_1 << 1) ^ (pub_r001215_6_1 >> 1)) & 127;
  int stage_v_315_2 = ((stage_v_96_2 << 1) ^ (pub_r001215_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_315_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_315_2 + 1) & 15;
  out_sink_1 ^= stage_v_315_1 & 63;
  out_sink_2 ^= stage_v_315_2 & 63;
  int stage_v_316_1 = ((stage_v_136_1 << 1) ^ (pub_r001215_7_1 >> 1)) & 127;
  int stage_v_316_2 = ((stage_v_136_2 << 1) ^ (pub_r001215_7_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_316_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_316_2 + 1) & 15;
  out_sink_1 ^= stage_v_316_1 & 63;
  out_sink_2 ^= stage_v_316_2 & 63;
  int stage_v_317_1 = ((pub_r001215_6_1 * 2) + 28) & 63;
  int stage_v_317_2 = ((pub_r001215_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((stage_v_247_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_318_2 = ((stage_v_247_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_318_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_318_2 + 1) & 15;
  out_sink_1 ^= stage_v_318_1 & 63;
  out_sink_2 ^= stage_v_318_2 & 63;
  int stage_v_319_1 = ((stage_v_72_1 << 1) ^ (pub_r001215_4_1 >> 1)) & 127;
  int stage_v_319_2 = ((stage_v_72_2 << 1) ^ (pub_r001215_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_319_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_319_2 + 1) & 15;
  out_sink_1 ^= stage_v_319_1 & 63;
  out_sink_2 ^= stage_v_319_2 & 63;
  int stage_v_320_1 = ((stage_v_13_1 << 1) ^ (pub_r001215_5_1 >> 1)) & 127;
  int stage_v_320_2 = ((stage_v_13_2 << 1) ^ (pub_r001215_5_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_320_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_320_2 + 1) & 15;
  out_sink_1 ^= stage_v_320_1 & 63;
  out_sink_2 ^= stage_v_320_2 & 63;
  int stage_v_321_1 = ((pub_r001215_20_1 * 2) + 11) & 63;
  int stage_v_321_2 = ((pub_r001215_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001215_20_1 * 2) + 27) & 63;
  int stage_v_322_2 = ((pub_r001215_20_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((stage_v_212_1 << 1) ^ (pub_r001215_7_1 >> 1)) & 127;
  int stage_v_323_2 = ((stage_v_212_2 << 1) ^ (pub_r001215_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_323_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_323_2 + 1) & 15;
  out_sink_1 ^= stage_v_323_1 & 63;
  out_sink_2 ^= stage_v_323_2 & 63;
  int stage_v_324_1 = ((pub_r001215_15_1 * 2) + 49) & 63;
  int stage_v_324_2 = ((pub_r001215_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((stage_v_249_1 << 1) ^ (pub_r001215_17_1 >> 1)) & 127;
  int stage_v_325_2 = ((stage_v_249_2 << 1) ^ (pub_r001215_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_325_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_325_2 + 1) & 15;
  out_sink_1 ^= stage_v_325_1 & 63;
  out_sink_2 ^= stage_v_325_2 & 63;
  int stage_v_326_1 = ((pub_r001215_10_1 * 2) + 44) & 63;
  int stage_v_326_2 = ((pub_r001215_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((helper_flow_1_1 << 1) ^ (pub_r001215_15_1 >> 1)) & 127;
  int stage_v_327_2 = ((helper_flow_1_2 << 1) ^ (pub_r001215_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_327_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_327_2 + 1) & 15;
  out_sink_1 ^= stage_v_327_1 & 63;
  out_sink_2 ^= stage_v_327_2 & 63;
  int stage_v_328_1 = ((pub_r001215_9_1 * 2) + 35) & 63;
  int stage_v_328_2 = ((pub_r001215_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001215_19_1 * 2) + 10) & 63;
  int stage_v_329_2 = ((pub_r001215_19_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((stage_v_172_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_330_2 = ((stage_v_172_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_330_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_330_2 + 1) & 15;
  out_sink_1 ^= stage_v_330_1 & 63;
  out_sink_2 ^= stage_v_330_2 & 63;
  int stage_v_331_1 = ((stage_v_80_1 << 1) ^ (pub_r001215_4_1 >> 1)) & 127;
  int stage_v_331_2 = ((stage_v_80_2 << 1) ^ (pub_r001215_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_331_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_331_2 + 1) & 15;
  out_sink_1 ^= stage_v_331_1 & 63;
  out_sink_2 ^= stage_v_331_2 & 63;
  int stage_v_332_1 = ((stage_v_71_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_332_2 = ((stage_v_71_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_332_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_332_2 + 1) & 15;
  out_sink_1 ^= stage_v_332_1 & 63;
  out_sink_2 ^= stage_v_332_2 & 63;
  int stage_v_333_1 = ((stage_v_323_1 << 1) ^ (pub_r001215_17_1 >> 1)) & 127;
  int stage_v_333_2 = ((stage_v_323_2 << 1) ^ (pub_r001215_17_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_333_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_333_2 + 1) & 15;
  out_sink_1 ^= stage_v_333_1 & 63;
  out_sink_2 ^= stage_v_333_2 & 63;
  int stage_v_334_1 = ((stage_v_205_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_334_2 = ((stage_v_205_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_334_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_334_2 + 1) & 15;
  out_sink_1 ^= stage_v_334_1 & 63;
  out_sink_2 ^= stage_v_334_2 & 63;
  int stage_v_335_1 = ((stage_v_182_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_335_2 = ((stage_v_182_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_335_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_335_2 + 1) & 15;
  out_sink_1 ^= stage_v_335_1 & 63;
  out_sink_2 ^= stage_v_335_2 & 63;
  int stage_v_336_1 = ((stage_v_107_1 << 1) ^ (pub_r001215_1_1 >> 1)) & 127;
  int stage_v_336_2 = ((stage_v_107_2 << 1) ^ (pub_r001215_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_336_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_336_2 + 1) & 15;
  out_sink_1 ^= stage_v_336_1 & 63;
  out_sink_2 ^= stage_v_336_2 & 63;
  int stage_v_337_1 = ((pub_r001215_11_1 * 2) + 38) & 63;
  int stage_v_337_2 = ((pub_r001215_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((stage_v_40_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_338_2 = ((stage_v_40_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_338_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_338_2 + 1) & 15;
  out_sink_1 ^= stage_v_338_1 & 63;
  out_sink_2 ^= stage_v_338_2 & 63;
  int stage_v_339_1 = ((stage_v_215_1 << 1) ^ (pub_r001215_1_1 >> 1)) & 127;
  int stage_v_339_2 = ((stage_v_215_2 << 1) ^ (pub_r001215_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_339_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_339_2 + 1) & 15;
  out_sink_1 ^= stage_v_339_1 & 63;
  out_sink_2 ^= stage_v_339_2 & 63;
  int stage_v_340_1 = ((sec_r001215_5_1 << 1) ^ (pub_r001215_15_1 >> 1)) & 127;
  int stage_v_340_2 = ((sec_r001215_5_2 << 1) ^ (pub_r001215_15_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_340_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_340_2 + 1) & 15;
  out_sink_1 ^= stage_v_340_1 & 63;
  out_sink_2 ^= stage_v_340_2 & 63;
  int stage_v_341_1 = ((stage_v_323_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_341_2 = ((stage_v_323_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_341_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_341_2 + 1) & 15;
  out_sink_1 ^= stage_v_341_1 & 63;
  out_sink_2 ^= stage_v_341_2 & 63;
  int stage_v_342_1 = ((pub_r001215_2_1 * 2) + 36) & 63;
  int stage_v_342_2 = ((pub_r001215_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((stage_v_94_1 << 1) ^ (pub_r001215_19_1 >> 1)) & 127;
  int stage_v_343_2 = ((stage_v_94_2 << 1) ^ (pub_r001215_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_343_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_343_2 + 1) & 15;
  out_sink_1 ^= stage_v_343_1 & 63;
  out_sink_2 ^= stage_v_343_2 & 63;
  int stage_v_344_1 = ((stage_v_210_1 << 1) ^ (pub_r001215_7_1 >> 1)) & 127;
  int stage_v_344_2 = ((stage_v_210_2 << 1) ^ (pub_r001215_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_344_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_344_2 + 1) & 15;
  out_sink_1 ^= stage_v_344_1 & 63;
  out_sink_2 ^= stage_v_344_2 & 63;
  int stage_v_345_1 = ((pub_r001215_3_1 * 2) + 45) & 63;
  int stage_v_345_2 = ((pub_r001215_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((stage_v_287_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_346_2 = ((stage_v_287_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_346_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_346_2 + 1) & 15;
  out_sink_1 ^= stage_v_346_1 & 63;
  out_sink_2 ^= stage_v_346_2 & 63;
  int stage_v_347_1 = ((stage_v_182_1 << 1) ^ (pub_r001215_19_1 >> 1)) & 127;
  int stage_v_347_2 = ((stage_v_182_2 << 1) ^ (pub_r001215_19_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_347_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_347_2 + 1) & 15;
  out_sink_1 ^= stage_v_347_1 & 63;
  out_sink_2 ^= stage_v_347_2 & 63;
  int stage_v_348_1 = ((stage_v_16_1 << 1) ^ (pub_r001215_5_1 >> 1)) & 127;
  int stage_v_348_2 = ((stage_v_16_2 << 1) ^ (pub_r001215_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_348_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_348_2 + 1) & 15;
  out_sink_1 ^= stage_v_348_1 & 63;
  out_sink_2 ^= stage_v_348_2 & 63;
  int stage_v_349_1 = ((pub_r001215_20_1 * 2) + 25) & 63;
  int stage_v_349_2 = ((pub_r001215_20_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = ((stage_v_293_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_350_2 = ((stage_v_293_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_350_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_350_2 + 1) & 15;
  out_sink_1 ^= stage_v_350_1 & 63;
  out_sink_2 ^= stage_v_350_2 & 63;
  int stage_v_351_1 = ((stage_v_233_1 << 1) ^ (pub_r001215_11_1 >> 1)) & 127;
  int stage_v_351_2 = ((stage_v_233_2 << 1) ^ (pub_r001215_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_351_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_351_2 + 1) & 15;
  out_sink_1 ^= stage_v_351_1 & 63;
  out_sink_2 ^= stage_v_351_2 & 63;
  int stage_v_352_1 = ((stage_v_15_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_352_2 = ((stage_v_15_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_352_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_352_2 + 1) & 15;
  out_sink_1 ^= stage_v_352_1 & 63;
  out_sink_2 ^= stage_v_352_2 & 63;
  int stage_v_353_1 = ((pub_r001215_4_1 * 2) + 10) & 63;
  int stage_v_353_2 = ((pub_r001215_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001215_0_1 * 2) + 38) & 63;
  int stage_v_354_2 = ((pub_r001215_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((stage_v_96_1 << 1) ^ (pub_r001215_10_1 >> 1)) & 127;
  int stage_v_355_2 = ((stage_v_96_2 << 1) ^ (pub_r001215_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_355_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_355_2 + 1) & 15;
  out_sink_1 ^= stage_v_355_1 & 63;
  out_sink_2 ^= stage_v_355_2 & 63;
  int stage_v_356_1 = ((pub_r001215_6_1 * 2) + 6) & 63;
  int stage_v_356_2 = ((pub_r001215_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((stage_v_40_1 << 1) ^ (pub_r001215_15_1 >> 1)) & 127;
  int stage_v_357_2 = ((stage_v_40_2 << 1) ^ (pub_r001215_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_357_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_357_2 + 1) & 15;
  out_sink_1 ^= stage_v_357_1 & 63;
  out_sink_2 ^= stage_v_357_2 & 63;
  int stage_v_358_1 = ((pub_r001215_8_1 * 2) + 46) & 63;
  int stage_v_358_2 = ((pub_r001215_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001215_18_1 * 2) + 19) & 63;
  int stage_v_359_2 = ((pub_r001215_18_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((pub_r001215_3_1 * 2) + 31) & 63;
  int stage_v_360_2 = ((pub_r001215_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((pub_r001215_1_1 * 2) + 10) & 63;
  int stage_v_361_2 = ((pub_r001215_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001215_5_1 * 2) + 11) & 63;
  int stage_v_362_2 = ((pub_r001215_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((stage_v_43_1 << 1) ^ (pub_r001215_9_1 >> 1)) & 127;
  int stage_v_363_2 = ((stage_v_43_2 << 1) ^ (pub_r001215_9_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_363_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_363_2 + 1) & 15;
  out_sink_1 ^= stage_v_363_1 & 63;
  out_sink_2 ^= stage_v_363_2 & 63;
  int stage_v_364_1 = ((pub_r001215_16_1 * 2) + 39) & 63;
  int stage_v_364_2 = ((pub_r001215_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001215_14_1 * 2) + 48) & 63;
  int stage_v_365_2 = ((pub_r001215_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((stage_v_193_1 << 1) ^ (pub_r001215_5_1 >> 1)) & 127;
  int stage_v_366_2 = ((stage_v_193_2 << 1) ^ (pub_r001215_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_366_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_366_2 + 1) & 15;
  out_sink_1 ^= stage_v_366_1 & 63;
  out_sink_2 ^= stage_v_366_2 & 63;
  int stage_v_367_1 = ((stage_v_341_1 << 1) ^ (pub_r001215_3_1 >> 1)) & 127;
  int stage_v_367_2 = ((stage_v_341_2 << 1) ^ (pub_r001215_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_367_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_367_2 + 1) & 15;
  out_sink_1 ^= stage_v_367_1 & 63;
  out_sink_2 ^= stage_v_367_2 & 63;
  int stage_v_368_1 = ((stage_v_181_1 << 1) ^ (pub_r001215_8_1 >> 1)) & 127;
  int stage_v_368_2 = ((stage_v_181_2 << 1) ^ (pub_r001215_8_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_368_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_368_2 + 1) & 15;
  out_sink_1 ^= stage_v_368_1 & 63;
  out_sink_2 ^= stage_v_368_2 & 63;
  int stage_v_369_1 = ((stage_v_347_1 << 1) ^ (pub_r001215_11_1 >> 1)) & 127;
  int stage_v_369_2 = ((stage_v_347_2 << 1) ^ (pub_r001215_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_369_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_369_2 + 1) & 15;
  out_sink_1 ^= stage_v_369_1 & 63;
  out_sink_2 ^= stage_v_369_2 & 63;
  int stage_v_370_1 = ((stage_v_101_1 << 1) ^ (pub_r001215_7_1 >> 1)) & 127;
  int stage_v_370_2 = ((stage_v_101_2 << 1) ^ (pub_r001215_7_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_370_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_370_2 + 1) & 15;
  out_sink_1 ^= stage_v_370_1 & 63;
  out_sink_2 ^= stage_v_370_2 & 63;
  int stage_v_371_1 = ((stage_v_33_1 << 1) ^ (pub_r001215_8_1 >> 1)) & 127;
  int stage_v_371_2 = ((stage_v_33_2 << 1) ^ (pub_r001215_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_371_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_371_2 + 1) & 15;
  out_sink_1 ^= stage_v_371_1 & 63;
  out_sink_2 ^= stage_v_371_2 & 63;
  int stage_v_372_1 = ((pub_r001215_17_1 * 2) + 13) & 63;
  int stage_v_372_2 = ((pub_r001215_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((sec_r001215_3_1 << 1) ^ (pub_r001215_16_1 >> 1)) & 127;
  int stage_v_373_2 = ((sec_r001215_3_2 << 1) ^ (pub_r001215_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_373_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_373_2 + 1) & 15;
  out_sink_1 ^= stage_v_373_1 & 63;
  out_sink_2 ^= stage_v_373_2 & 63;
  int stage_v_374_1 = ((stage_v_242_1 << 1) ^ (pub_r001215_7_1 >> 1)) & 127;
  int stage_v_374_2 = ((stage_v_242_2 << 1) ^ (pub_r001215_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_374_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_374_2 + 1) & 15;
  out_sink_1 ^= stage_v_374_1 & 63;
  out_sink_2 ^= stage_v_374_2 & 63;
  int stage_v_375_1 = ((pub_r001215_9_1 * 2) + 30) & 63;
  int stage_v_375_2 = ((pub_r001215_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((stage_v_357_1 << 1) ^ (pub_r001215_11_1 >> 1)) & 127;
  int stage_v_376_2 = ((stage_v_357_2 << 1) ^ (pub_r001215_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_376_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_376_2 + 1) & 15;
  out_sink_1 ^= stage_v_376_1 & 63;
  out_sink_2 ^= stage_v_376_2 & 63;
  int stage_v_377_1 = ((stage_v_284_1 << 1) ^ (pub_r001215_9_1 >> 1)) & 127;
  int stage_v_377_2 = ((stage_v_284_2 << 1) ^ (pub_r001215_9_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_377_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_377_2 + 1) & 15;
  out_sink_1 ^= stage_v_377_1 & 63;
  out_sink_2 ^= stage_v_377_2 & 63;
  int stage_v_378_1 = ((stage_v_197_1 << 1) ^ (pub_r001215_18_1 >> 1)) & 127;
  int stage_v_378_2 = ((stage_v_197_2 << 1) ^ (pub_r001215_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_378_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_378_2 + 1) & 15;
  out_sink_1 ^= stage_v_378_1 & 63;
  out_sink_2 ^= stage_v_378_2 & 63;
  int stage_v_379_1 = ((pub_r001215_9_1 * 2) + 25) & 63;
  int stage_v_379_2 = ((pub_r001215_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = ((pub_r001215_16_1 * 2) + 42) & 63;
  int stage_v_380_2 = ((pub_r001215_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001215_6_1 * 2) + 30) & 63;
  int stage_v_381_2 = ((pub_r001215_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = ((stage_v_196_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_382_2 = ((stage_v_196_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_382_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_382_2 + 1) & 15;
  out_sink_1 ^= stage_v_382_1 & 63;
  out_sink_2 ^= stage_v_382_2 & 63;
  int stage_v_383_1 = ((stage_v_153_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_383_2 = ((stage_v_153_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_383_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_383_2 + 1) & 15;
  out_sink_1 ^= stage_v_383_1 & 63;
  out_sink_2 ^= stage_v_383_2 & 63;
  int stage_v_384_1 = ((pub_r001215_18_1 * 2) + 8) & 63;
  int stage_v_384_2 = ((pub_r001215_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001215_6_1 * 2) + 40) & 63;
  int stage_v_385_2 = ((pub_r001215_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001215_5_1 * 2) + 17) & 63;
  int stage_v_386_2 = ((pub_r001215_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001215_17_1 * 2) + 40) & 63;
  int stage_v_387_2 = ((pub_r001215_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001215_17_1 * 2) + 33) & 63;
  int stage_v_388_2 = ((pub_r001215_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((stage_v_262_1 << 1) ^ (pub_r001215_7_1 >> 1)) & 127;
  int stage_v_389_2 = ((stage_v_262_2 << 1) ^ (pub_r001215_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_389_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_389_2 + 1) & 15;
  out_sink_1 ^= stage_v_389_1 & 63;
  out_sink_2 ^= stage_v_389_2 & 63;
  int stage_v_390_1 = ((stage_v_204_1 << 1) ^ (pub_r001215_18_1 >> 1)) & 127;
  int stage_v_390_2 = ((stage_v_204_2 << 1) ^ (pub_r001215_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_390_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_390_2 + 1) & 15;
  out_sink_1 ^= stage_v_390_1 & 63;
  out_sink_2 ^= stage_v_390_2 & 63;
  int stage_v_391_1 = ((pub_r001215_5_1 * 2) + 9) & 63;
  int stage_v_391_2 = ((pub_r001215_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001215_1_1 * 2) + 35) & 63;
  int stage_v_392_2 = ((pub_r001215_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001215_9_1 * 2) + 43) & 63;
  int stage_v_393_2 = ((pub_r001215_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((stage_v_14_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_394_2 = ((stage_v_14_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_394_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_394_2 + 1) & 15;
  out_sink_1 ^= stage_v_394_1 & 63;
  out_sink_2 ^= stage_v_394_2 & 63;
  int stage_v_395_1 = ((stage_v_137_1 << 1) ^ (pub_r001215_2_1 >> 1)) & 127;
  int stage_v_395_2 = ((stage_v_137_2 << 1) ^ (pub_r001215_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_395_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_395_2 + 1) & 15;
  out_sink_1 ^= stage_v_395_1 & 63;
  out_sink_2 ^= stage_v_395_2 & 63;
  int stage_v_396_1 = ((pub_r001215_17_1 * 2) + 46) & 63;
  int stage_v_396_2 = ((pub_r001215_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((stage_v_394_1 << 1) ^ (pub_r001215_1_1 >> 1)) & 127;
  int stage_v_397_2 = ((stage_v_394_2 << 1) ^ (pub_r001215_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_397_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_397_2 + 1) & 15;
  out_sink_1 ^= stage_v_397_1 & 63;
  out_sink_2 ^= stage_v_397_2 & 63;
  int stage_v_398_1 = ((pub_r001215_11_1 * 2) + 30) & 63;
  int stage_v_398_2 = ((pub_r001215_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001215_20_1 * 2) + 41) & 63;
  int stage_v_399_2 = ((pub_r001215_20_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001215_6_1 * 2) + 6) & 63;
  int stage_v_400_2 = ((pub_r001215_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((stage_v_182_1 << 1) ^ (pub_r001215_18_1 >> 1)) & 127;
  int stage_v_401_2 = ((stage_v_182_2 << 1) ^ (pub_r001215_18_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_401_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_401_2 + 1) & 15;
  out_sink_1 ^= stage_v_401_1 & 63;
  out_sink_2 ^= stage_v_401_2 & 63;
  int stage_v_402_1 = ((stage_v_289_1 << 1) ^ (pub_r001215_3_1 >> 1)) & 127;
  int stage_v_402_2 = ((stage_v_289_2 << 1) ^ (pub_r001215_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_402_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_402_2 + 1) & 15;
  out_sink_1 ^= stage_v_402_1 & 63;
  out_sink_2 ^= stage_v_402_2 & 63;
  int stage_v_403_1 = ((stage_v_270_1 << 1) ^ (pub_r001215_17_1 >> 1)) & 127;
  int stage_v_403_2 = ((stage_v_270_2 << 1) ^ (pub_r001215_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_403_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_403_2 + 1) & 15;
  out_sink_1 ^= stage_v_403_1 & 63;
  out_sink_2 ^= stage_v_403_2 & 63;
  int stage_v_404_1 = ((pub_r001215_11_1 * 2) + 32) & 63;
  int stage_v_404_2 = ((pub_r001215_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = ((stage_v_389_1 << 1) ^ (pub_r001215_19_1 >> 1)) & 127;
  int stage_v_405_2 = ((stage_v_389_2 << 1) ^ (pub_r001215_19_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_405_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_405_2 + 1) & 15;
  out_sink_1 ^= stage_v_405_1 & 63;
  out_sink_2 ^= stage_v_405_2 & 63;
  int stage_v_406_1 = ((stage_v_370_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_406_2 = ((stage_v_370_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_406_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_406_2 + 1) & 15;
  out_sink_1 ^= stage_v_406_1 & 63;
  out_sink_2 ^= stage_v_406_2 & 63;
  int stage_v_407_1 = ((pub_r001215_9_1 * 2) + 46) & 63;
  int stage_v_407_2 = ((pub_r001215_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001215_10_1 * 2) + 41) & 63;
  int stage_v_408_2 = ((pub_r001215_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((sec_r001215_10_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_409_2 = ((sec_r001215_10_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_409_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_409_2 + 1) & 15;
  out_sink_1 ^= stage_v_409_1 & 63;
  out_sink_2 ^= stage_v_409_2 & 63;
  int stage_v_410_1 = ((stage_v_21_1 << 1) ^ (pub_r001215_5_1 >> 1)) & 127;
  int stage_v_410_2 = ((stage_v_21_2 << 1) ^ (pub_r001215_5_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_410_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_410_2 + 1) & 15;
  out_sink_1 ^= stage_v_410_1 & 63;
  out_sink_2 ^= stage_v_410_2 & 63;
  int stage_v_411_1 = ((pub_r001215_9_1 * 2) + 5) & 63;
  int stage_v_411_2 = ((pub_r001215_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((stage_v_367_1 << 1) ^ (pub_r001215_7_1 >> 1)) & 127;
  int stage_v_412_2 = ((stage_v_367_2 << 1) ^ (pub_r001215_7_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_412_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_412_2 + 1) & 15;
  out_sink_1 ^= stage_v_412_1 & 63;
  out_sink_2 ^= stage_v_412_2 & 63;
  int stage_v_413_1 = ((pub_r001215_11_1 * 2) + 37) & 63;
  int stage_v_413_2 = ((pub_r001215_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((stage_v_86_1 << 1) ^ (pub_r001215_9_1 >> 1)) & 127;
  int stage_v_414_2 = ((stage_v_86_2 << 1) ^ (pub_r001215_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_414_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_414_2 + 1) & 15;
  out_sink_1 ^= stage_v_414_1 & 63;
  out_sink_2 ^= stage_v_414_2 & 63;
  int stage_v_415_1 = ((pub_r001215_5_1 * 2) + 18) & 63;
  int stage_v_415_2 = ((pub_r001215_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = ((stage_v_336_1 << 1) ^ (pub_r001215_8_1 >> 1)) & 127;
  int stage_v_416_2 = ((stage_v_336_2 << 1) ^ (pub_r001215_8_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_416_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_416_2 + 1) & 15;
  out_sink_1 ^= stage_v_416_1 & 63;
  out_sink_2 ^= stage_v_416_2 & 63;
  int stage_v_417_1 = ((pub_r001215_13_1 * 2) + 19) & 63;
  int stage_v_417_2 = ((pub_r001215_13_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001215_0_1 * 2) + 25) & 63;
  int stage_v_418_2 = ((pub_r001215_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((stage_v_174_1 << 1) ^ (pub_r001215_1_1 >> 1)) & 127;
  int stage_v_419_2 = ((stage_v_174_2 << 1) ^ (pub_r001215_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_419_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_419_2 + 1) & 15;
  out_sink_1 ^= stage_v_419_1 & 63;
  out_sink_2 ^= stage_v_419_2 & 63;
  int stage_v_420_1 = ((stage_v_159_1 << 1) ^ (pub_r001215_16_1 >> 1)) & 127;
  int stage_v_420_2 = ((stage_v_159_2 << 1) ^ (pub_r001215_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_420_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_420_2 + 1) & 15;
  out_sink_1 ^= stage_v_420_1 & 63;
  out_sink_2 ^= stage_v_420_2 & 63;
  int stage_v_421_1 = ((stage_v_323_1 << 1) ^ (pub_r001215_10_1 >> 1)) & 127;
  int stage_v_421_2 = ((stage_v_323_2 << 1) ^ (pub_r001215_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_421_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_421_2 + 1) & 15;
  out_sink_1 ^= stage_v_421_1 & 63;
  out_sink_2 ^= stage_v_421_2 & 63;
  int stage_v_422_1 = ((stage_v_8_1 << 1) ^ (pub_r001215_8_1 >> 1)) & 127;
  int stage_v_422_2 = ((stage_v_8_2 << 1) ^ (pub_r001215_8_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_422_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_422_2 + 1) & 15;
  out_sink_1 ^= stage_v_422_1 & 63;
  out_sink_2 ^= stage_v_422_2 & 63;
  int stage_v_423_1 = ((pub_r001215_10_1 * 2) + 34) & 63;
  int stage_v_423_2 = ((pub_r001215_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001215_11_1 * 2) + 36) & 63;
  int stage_v_424_2 = ((pub_r001215_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((stage_v_259_1 << 1) ^ (pub_r001215_7_1 >> 1)) & 127;
  int stage_v_425_2 = ((stage_v_259_2 << 1) ^ (pub_r001215_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_425_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_425_2 + 1) & 15;
  out_sink_1 ^= stage_v_425_1 & 63;
  out_sink_2 ^= stage_v_425_2 & 63;
  int stage_v_426_1 = ((stage_v_225_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_426_2 = ((stage_v_225_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_426_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_426_2 + 1) & 15;
  out_sink_1 ^= stage_v_426_1 & 63;
  out_sink_2 ^= stage_v_426_2 & 63;
  int stage_v_427_1 = ((pub_r001215_14_1 * 2) + 27) & 63;
  int stage_v_427_2 = ((pub_r001215_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = ((sec_r001215_1_1 << 1) ^ (pub_r001215_11_1 >> 1)) & 127;
  int stage_v_428_2 = ((sec_r001215_1_2 << 1) ^ (pub_r001215_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_428_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_428_2 + 1) & 15;
  out_sink_1 ^= stage_v_428_1 & 63;
  out_sink_2 ^= stage_v_428_2 & 63;
  int stage_v_429_1 = ((stage_v_24_1 << 1) ^ (pub_r001215_10_1 >> 1)) & 127;
  int stage_v_429_2 = ((stage_v_24_2 << 1) ^ (pub_r001215_10_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_429_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_429_2 + 1) & 15;
  out_sink_1 ^= stage_v_429_1 & 63;
  out_sink_2 ^= stage_v_429_2 & 63;
  int stage_v_430_1 = ((stage_v_43_1 << 1) ^ (pub_r001215_5_1 >> 1)) & 127;
  int stage_v_430_2 = ((stage_v_43_2 << 1) ^ (pub_r001215_5_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_430_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_430_2 + 1) & 15;
  out_sink_1 ^= stage_v_430_1 & 63;
  out_sink_2 ^= stage_v_430_2 & 63;
  int stage_v_431_1 = ((pub_r001215_8_1 * 2) + 45) & 63;
  int stage_v_431_2 = ((pub_r001215_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = ((stage_v_141_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_432_2 = ((stage_v_141_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_432_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_432_2 + 1) & 15;
  out_sink_1 ^= stage_v_432_1 & 63;
  out_sink_2 ^= stage_v_432_2 & 63;
  int stage_v_433_1 = ((stage_v_6_1 << 1) ^ (pub_r001215_19_1 >> 1)) & 127;
  int stage_v_433_2 = ((stage_v_6_2 << 1) ^ (pub_r001215_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_433_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_433_2 + 1) & 15;
  out_sink_1 ^= stage_v_433_1 & 63;
  out_sink_2 ^= stage_v_433_2 & 63;
  int stage_v_434_1 = ((stage_v_210_1 << 1) ^ (pub_r001215_10_1 >> 1)) & 127;
  int stage_v_434_2 = ((stage_v_210_2 << 1) ^ (pub_r001215_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_434_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_434_2 + 1) & 15;
  out_sink_1 ^= stage_v_434_1 & 63;
  out_sink_2 ^= stage_v_434_2 & 63;
  int stage_v_435_1 = ((stage_v_32_1 << 1) ^ (pub_r001215_1_1 >> 1)) & 127;
  int stage_v_435_2 = ((stage_v_32_2 << 1) ^ (pub_r001215_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_435_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_435_2 + 1) & 15;
  out_sink_1 ^= stage_v_435_1 & 63;
  out_sink_2 ^= stage_v_435_2 & 63;
  int stage_v_436_1 = ((stage_v_338_1 << 1) ^ (pub_r001215_6_1 >> 1)) & 127;
  int stage_v_436_2 = ((stage_v_338_2 << 1) ^ (pub_r001215_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_436_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_436_2 + 1) & 15;
  out_sink_1 ^= stage_v_436_1 & 63;
  out_sink_2 ^= stage_v_436_2 & 63;
  int stage_v_437_1 = ((pub_r001215_9_1 * 2) + 11) & 63;
  int stage_v_437_2 = ((pub_r001215_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = ((stage_v_355_1 << 1) ^ (pub_r001215_3_1 >> 1)) & 127;
  int stage_v_438_2 = ((stage_v_355_2 << 1) ^ (pub_r001215_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_438_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_438_2 + 1) & 15;
  out_sink_1 ^= stage_v_438_1 & 63;
  out_sink_2 ^= stage_v_438_2 & 63;
  int stage_v_439_1 = ((pub_r001215_19_1 * 2) + 12) & 63;
  int stage_v_439_2 = ((pub_r001215_19_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = ((stage_v_103_1 << 1) ^ (pub_r001215_4_1 >> 1)) & 127;
  int stage_v_440_2 = ((stage_v_103_2 << 1) ^ (pub_r001215_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_440_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_440_2 + 1) & 15;
  out_sink_1 ^= stage_v_440_1 & 63;
  out_sink_2 ^= stage_v_440_2 & 63;
  int stage_v_441_1 = ((pub_r001215_12_1 * 2) + 5) & 63;
  int stage_v_441_2 = ((pub_r001215_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((pub_r001215_1_1 * 2) + 19) & 63;
  int stage_v_442_2 = ((pub_r001215_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = ((pub_r001215_7_1 * 2) + 44) & 63;
  int stage_v_443_2 = ((pub_r001215_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((sec_r001215_11_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_444_2 = ((sec_r001215_11_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_444_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_444_2 + 1) & 15;
  out_sink_1 ^= stage_v_444_1 & 63;
  out_sink_2 ^= stage_v_444_2 & 63;
  int stage_v_445_1 = ((pub_r001215_4_1 * 2) + 19) & 63;
  int stage_v_445_2 = ((pub_r001215_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = ((stage_v_231_1 << 1) ^ (pub_r001215_14_1 >> 1)) & 127;
  int stage_v_446_2 = ((stage_v_231_2 << 1) ^ (pub_r001215_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_446_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_446_2 + 1) & 15;
  out_sink_1 ^= stage_v_446_1 & 63;
  out_sink_2 ^= stage_v_446_2 & 63;
  int stage_v_447_1 = ((pub_r001215_17_1 * 2) + 30) & 63;
  int stage_v_447_2 = ((pub_r001215_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((sec_r001215_0_1 << 1) ^ (pub_r001215_17_1 >> 1)) & 127;
  int stage_v_448_2 = ((sec_r001215_0_2 << 1) ^ (pub_r001215_17_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_448_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_448_2 + 1) & 15;
  out_sink_1 ^= stage_v_448_1 & 63;
  out_sink_2 ^= stage_v_448_2 & 63;
  int stage_v_449_1 = ((stage_v_259_1 << 1) ^ (pub_r001215_8_1 >> 1)) & 127;
  int stage_v_449_2 = ((stage_v_259_2 << 1) ^ (pub_r001215_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_449_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_449_2 + 1) & 15;
  out_sink_1 ^= stage_v_449_1 & 63;
  out_sink_2 ^= stage_v_449_2 & 63;
  int stage_v_450_1 = ((stage_v_291_1 << 1) ^ (pub_r001215_2_1 >> 1)) & 127;
  int stage_v_450_2 = ((stage_v_291_2 << 1) ^ (pub_r001215_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_450_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_450_2 + 1) & 15;
  out_sink_1 ^= stage_v_450_1 & 63;
  out_sink_2 ^= stage_v_450_2 & 63;
  int stage_v_451_1 = ((pub_r001215_3_1 * 2) + 34) & 63;
  int stage_v_451_2 = ((pub_r001215_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_451_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_451_2) & 127;
  int stage_v_452_1 = ((stage_v_336_1 << 1) ^ (pub_r001215_12_1 >> 1)) & 127;
  int stage_v_452_2 = ((stage_v_336_2 << 1) ^ (pub_r001215_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_452_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_452_2 + 1) & 15;
  out_sink_1 ^= stage_v_452_1 & 63;
  out_sink_2 ^= stage_v_452_2 & 63;
  int stage_v_453_1 = ((pub_r001215_3_1 * 2) + 17) & 63;
  int stage_v_453_2 = ((pub_r001215_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = ((stage_v_158_1 << 1) ^ (pub_r001215_4_1 >> 1)) & 127;
  int stage_v_454_2 = ((stage_v_158_2 << 1) ^ (pub_r001215_4_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_454_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_454_2 + 1) & 15;
  out_sink_1 ^= stage_v_454_1 & 63;
  out_sink_2 ^= stage_v_454_2 & 63;
  int stage_v_455_1 = ((pub_r001215_16_1 * 2) + 10) & 63;
  int stage_v_455_2 = ((pub_r001215_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = ((pub_r001215_6_1 * 2) + 15) & 63;
  int stage_v_456_2 = ((pub_r001215_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_456_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_456_2) & 127;
  int stage_v_457_1 = ((stage_v_85_1 << 1) ^ (pub_r001215_7_1 >> 1)) & 127;
  int stage_v_457_2 = ((stage_v_85_2 << 1) ^ (pub_r001215_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_457_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_457_2 + 1) & 15;
  out_sink_1 ^= stage_v_457_1 & 63;
  out_sink_2 ^= stage_v_457_2 & 63;
  int stage_v_458_1 = ((pub_r001215_4_1 * 2) + 22) & 63;
  int stage_v_458_2 = ((pub_r001215_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = ((pub_r001215_7_1 * 2) + 30) & 63;
  int stage_v_459_2 = ((pub_r001215_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_459_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_459_2) & 127;
  int stage_v_460_1 = ((pub_r001215_20_1 * 2) + 43) & 63;
  int stage_v_460_2 = ((pub_r001215_20_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = ((pub_r001215_1_1 * 2) + 28) & 63;
  int stage_v_461_2 = ((pub_r001215_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = ((pub_r001215_13_1 * 2) + 45) & 63;
  int stage_v_462_2 = ((pub_r001215_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_462_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_462_2) & 127;
  int stage_v_463_1 = ((pub_r001215_17_1 * 2) + 41) & 63;
  int stage_v_463_2 = ((pub_r001215_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_463_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_463_2) & 127;
  int stage_v_464_1 = ((stage_v_96_1 << 1) ^ (pub_r001215_4_1 >> 1)) & 127;
  int stage_v_464_2 = ((stage_v_96_2 << 1) ^ (pub_r001215_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_464_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_464_2 + 1) & 15;
  out_sink_1 ^= stage_v_464_1 & 63;
  out_sink_2 ^= stage_v_464_2 & 63;
  int stage_v_465_1 = ((pub_r001215_15_1 * 2) + 20) & 63;
  int stage_v_465_2 = ((pub_r001215_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = ((pub_r001215_5_1 * 2) + 16) & 63;
  int stage_v_466_2 = ((pub_r001215_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_466_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_466_2) & 127;
  int stage_v_467_1 = ((stage_v_10_1 << 1) ^ (pub_r001215_18_1 >> 1)) & 127;
  int stage_v_467_2 = ((stage_v_10_2 << 1) ^ (pub_r001215_18_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_467_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_467_2 + 1) & 15;
  out_sink_1 ^= stage_v_467_1 & 63;
  out_sink_2 ^= stage_v_467_2 & 63;
  int stage_v_468_1 = ((pub_r001215_18_1 * 2) + 42) & 63;
  int stage_v_468_2 = ((pub_r001215_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_468_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_468_2) & 127;
  int stage_v_469_1 = ((pub_r001215_10_1 * 2) + 43) & 63;
  int stage_v_469_2 = ((pub_r001215_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_469_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_469_2) & 127;
  int stage_v_470_1 = ((pub_r001215_19_1 * 2) + 37) & 63;
  int stage_v_470_2 = ((pub_r001215_19_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_470_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_470_2) & 127;
  int stage_v_471_1 = ((stage_v_132_1 << 1) ^ (pub_r001215_4_1 >> 1)) & 127;
  int stage_v_471_2 = ((stage_v_132_2 << 1) ^ (pub_r001215_4_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_471_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_471_2 + 1) & 15;
  out_sink_1 ^= stage_v_471_1 & 63;
  out_sink_2 ^= stage_v_471_2 & 63;
  int stage_v_472_1 = ((stage_v_15_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_472_2 = ((stage_v_15_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_472_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_472_2 + 1) & 15;
  out_sink_1 ^= stage_v_472_1 & 63;
  out_sink_2 ^= stage_v_472_2 & 63;
  int stage_v_473_1 = ((pub_r001215_2_1 * 2) + 21) & 63;
  int stage_v_473_2 = ((pub_r001215_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_473_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_473_2) & 127;
  int stage_v_474_1 = ((stage_v_351_1 << 1) ^ (pub_r001215_3_1 >> 1)) & 127;
  int stage_v_474_2 = ((stage_v_351_2 << 1) ^ (pub_r001215_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_474_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_474_2 + 1) & 15;
  out_sink_1 ^= stage_v_474_1 & 63;
  out_sink_2 ^= stage_v_474_2 & 63;
  int stage_v_475_1 = ((sec_r001215_10_1 << 1) ^ (pub_r001215_10_1 >> 1)) & 127;
  int stage_v_475_2 = ((sec_r001215_10_2 << 1) ^ (pub_r001215_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_475_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_475_2 + 1) & 15;
  out_sink_1 ^= stage_v_475_1 & 63;
  out_sink_2 ^= stage_v_475_2 & 63;
  int stage_v_476_1 = ((stage_v_293_1 << 1) ^ (pub_r001215_12_1 >> 1)) & 127;
  int stage_v_476_2 = ((stage_v_293_2 << 1) ^ (pub_r001215_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_476_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_476_2 + 1) & 15;
  out_sink_1 ^= stage_v_476_1 & 63;
  out_sink_2 ^= stage_v_476_2 & 63;
  int stage_v_477_1 = ((pub_r001215_18_1 * 2) + 20) & 63;
  int stage_v_477_2 = ((pub_r001215_18_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_477_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_477_2) & 127;
  int stage_v_478_1 = ((stage_v_65_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_478_2 = ((stage_v_65_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_478_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_478_2 + 1) & 15;
  out_sink_1 ^= stage_v_478_1 & 63;
  out_sink_2 ^= stage_v_478_2 & 63;
  int stage_v_479_1 = ((pub_r001215_11_1 * 2) + 36) & 63;
  int stage_v_479_2 = ((pub_r001215_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_479_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_479_2) & 127;
  int stage_v_480_1 = ((pub_r001215_15_1 * 2) + 48) & 63;
  int stage_v_480_2 = ((pub_r001215_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_480_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_480_2) & 127;
  int stage_v_481_1 = ((pub_r001215_0_1 * 2) + 38) & 63;
  int stage_v_481_2 = ((pub_r001215_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_481_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_481_2) & 127;
  int stage_v_482_1 = ((stage_v_320_1 << 1) ^ (pub_r001215_6_1 >> 1)) & 127;
  int stage_v_482_2 = ((stage_v_320_2 << 1) ^ (pub_r001215_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_482_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_482_2 + 1) & 15;
  out_sink_1 ^= stage_v_482_1 & 63;
  out_sink_2 ^= stage_v_482_2 & 63;
  int stage_v_483_1 = ((pub_r001215_4_1 * 2) + 37) & 63;
  int stage_v_483_2 = ((pub_r001215_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_483_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_483_2) & 127;
  int stage_v_484_1 = ((pub_r001215_1_1 * 2) + 15) & 63;
  int stage_v_484_2 = ((pub_r001215_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_484_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_484_2) & 127;
  int stage_v_485_1 = ((stage_v_438_1 << 1) ^ (pub_r001215_8_1 >> 1)) & 127;
  int stage_v_485_2 = ((stage_v_438_2 << 1) ^ (pub_r001215_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_485_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_485_2 + 1) & 15;
  out_sink_1 ^= stage_v_485_1 & 63;
  out_sink_2 ^= stage_v_485_2 & 63;
  int stage_v_486_1 = ((pub_r001215_7_1 * 2) + 33) & 63;
  int stage_v_486_2 = ((pub_r001215_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_486_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_486_2) & 127;
  int stage_v_487_1 = ((helper_flow_3_1 << 1) ^ (pub_r001215_18_1 >> 1)) & 127;
  int stage_v_487_2 = ((helper_flow_3_2 << 1) ^ (pub_r001215_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_487_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_487_2 + 1) & 15;
  out_sink_1 ^= stage_v_487_1 & 63;
  out_sink_2 ^= stage_v_487_2 & 63;
  int stage_v_488_1 = ((pub_r001215_7_1 * 2) + 41) & 63;
  int stage_v_488_2 = ((pub_r001215_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_488_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_488_2) & 127;
  int stage_v_489_1 = ((pub_r001215_8_1 * 2) + 41) & 63;
  int stage_v_489_2 = ((pub_r001215_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_489_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_489_2) & 127;
  int stage_v_490_1 = ((pub_r001215_8_1 * 2) + 48) & 63;
  int stage_v_490_2 = ((pub_r001215_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_490_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_490_2) & 127;
  int stage_v_491_1 = ((pub_r001215_16_1 * 2) + 35) & 63;
  int stage_v_491_2 = ((pub_r001215_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_491_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_491_2) & 127;
  int stage_v_492_1 = ((pub_r001215_14_1 * 2) + 28) & 63;
  int stage_v_492_2 = ((pub_r001215_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_492_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_492_2) & 127;
  int stage_v_493_1 = ((stage_v_106_1 << 1) ^ (pub_r001215_0_1 >> 1)) & 127;
  int stage_v_493_2 = ((stage_v_106_2 << 1) ^ (pub_r001215_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_493_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_493_2 + 1) & 15;
  out_sink_1 ^= stage_v_493_1 & 63;
  out_sink_2 ^= stage_v_493_2 & 63;
  int stage_v_494_1 = ((stage_v_416_1 << 1) ^ (pub_r001215_17_1 >> 1)) & 127;
  int stage_v_494_2 = ((stage_v_416_2 << 1) ^ (pub_r001215_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_494_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_494_2 + 1) & 15;
  out_sink_1 ^= stage_v_494_1 & 63;
  out_sink_2 ^= stage_v_494_2 & 63;
  int stage_v_495_1 = ((pub_r001215_6_1 * 2) + 42) & 63;
  int stage_v_495_2 = ((pub_r001215_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_495_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_495_2) & 127;
  int stage_v_496_1 = ((stage_v_181_1 << 1) ^ (pub_r001215_13_1 >> 1)) & 127;
  int stage_v_496_2 = ((stage_v_181_2 << 1) ^ (pub_r001215_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_496_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_496_2 + 1) & 15;
  out_sink_1 ^= stage_v_496_1 & 63;
  out_sink_2 ^= stage_v_496_2 & 63;
  int stage_v_497_1 = ((pub_r001215_6_1 * 2) + 49) & 63;
  int stage_v_497_2 = ((pub_r001215_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_497_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_497_2) & 127;
  int stage_v_498_1 = ((stage_v_107_1 << 1) ^ (pub_r001215_16_1 >> 1)) & 127;
  int stage_v_498_2 = ((stage_v_107_2 << 1) ^ (pub_r001215_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_498_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_498_2 + 1) & 15;
  out_sink_1 ^= stage_v_498_1 & 63;
  out_sink_2 ^= stage_v_498_2 & 63;
  int stage_v_499_1 = ((pub_r001215_17_1 * 2) + 15) & 63;
  int stage_v_499_2 = ((pub_r001215_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_499_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_499_2) & 127;
  int stage_v_500_1 = ((stage_v_33_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_500_2 = ((stage_v_33_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_500_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_500_2 + 1) & 15;
  out_sink_1 ^= stage_v_500_1 & 63;
  out_sink_2 ^= stage_v_500_2 & 63;
  int stage_v_501_1 = ((stage_v_14_1 << 1) ^ (pub_r001215_18_1 >> 1)) & 127;
  int stage_v_501_2 = ((stage_v_14_2 << 1) ^ (pub_r001215_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_501_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_501_2 + 1) & 15;
  out_sink_1 ^= stage_v_501_1 & 63;
  out_sink_2 ^= stage_v_501_2 & 63;
  int stage_v_502_1 = ((pub_r001215_14_1 * 2) + 50) & 63;
  int stage_v_502_2 = ((pub_r001215_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_502_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_502_2) & 127;
  int stage_v_503_1 = ((stage_v_377_1 << 1) ^ (pub_r001215_1_1 >> 1)) & 127;
  int stage_v_503_2 = ((stage_v_377_2 << 1) ^ (pub_r001215_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_503_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_503_2 + 1) & 15;
  out_sink_1 ^= stage_v_503_1 & 63;
  out_sink_2 ^= stage_v_503_2 & 63;
  int stage_v_504_1 = ((stage_v_13_1 << 1) ^ (pub_r001215_20_1 >> 1)) & 127;
  int stage_v_504_2 = ((stage_v_13_2 << 1) ^ (pub_r001215_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_504_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_504_2 + 1) & 15;
  out_sink_1 ^= stage_v_504_1 & 63;
  out_sink_2 ^= stage_v_504_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001215_8_1 == pub_r001215_8_2);
  __CPROVER_assume(sec_r001215_6_1 != sec_r001215_6_2);
  __CPROVER_assume(pub_r001215_6_1 == pub_r001215_6_2);
  __CPROVER_assume(pub_r001215_5_1 == pub_r001215_5_2);
  __CPROVER_assume(pub_r001215_2_1 == pub_r001215_2_2);
  __CPROVER_assume(pub_r001215_12_1 == pub_r001215_12_2);
  __CPROVER_assume(sec_r001215_11_1 != sec_r001215_11_2);
  __CPROVER_assume(sec_r001215_13_1 != sec_r001215_13_2);
  __CPROVER_assume(sec_r001215_5_1 != sec_r001215_5_2);
  __CPROVER_assume(pub_r001215_11_1 == pub_r001215_11_2);
  __CPROVER_assume(sec_r001215_7_1 != sec_r001215_7_2);
  __CPROVER_assume(sec_r001215_2_1 != sec_r001215_2_2);
  __CPROVER_assume(sec_r001215_12_1 != sec_r001215_12_2);
  __CPROVER_assume(sec_r001215_14_1 != sec_r001215_14_2);
  __CPROVER_assume(pub_r001215_4_1 == pub_r001215_4_2);
  __CPROVER_assume(pub_r001215_1_1 == pub_r001215_1_2);
  __CPROVER_assume(sec_r001215_15_1 != sec_r001215_15_2);
  __CPROVER_assume(pub_r001215_3_1 == pub_r001215_3_2);
  __CPROVER_assume(pub_r001215_9_1 == pub_r001215_9_2);
  __CPROVER_assume(sec_r001215_3_1 != sec_r001215_3_2);
  __CPROVER_assume(pub_r001215_17_1 == pub_r001215_17_2);
  __CPROVER_assume(pub_r001215_20_1 == pub_r001215_20_2);
  __CPROVER_assume(pub_r001215_10_1 == pub_r001215_10_2);
  __CPROVER_assume(pub_r001215_19_1 == pub_r001215_19_2);
  __CPROVER_assume(pub_r001215_16_1 == pub_r001215_16_2);
  __CPROVER_assume(sec_r001215_1_1 != sec_r001215_1_2);
  __CPROVER_assume(pub_r001215_14_1 == pub_r001215_14_2);
  __CPROVER_assume(pub_r001215_0_1 == pub_r001215_0_2);
  __CPROVER_assume(pub_r001215_15_1 == pub_r001215_15_2);
  __CPROVER_assume(sec_r001215_4_1 != sec_r001215_4_2);
  __CPROVER_assume(pub_r001215_13_1 == pub_r001215_13_2);
  __CPROVER_assume(sec_r001215_16_1 != sec_r001215_16_2);
  __CPROVER_assume(pub_r001215_18_1 == pub_r001215_18_2);
  __CPROVER_assume(sec_r001215_8_1 != sec_r001215_8_2);
  __CPROVER_assume(sec_r001215_10_1 != sec_r001215_10_2);
  __CPROVER_assume(pub_r001215_7_1 == pub_r001215_7_2);
  __CPROVER_assume(sec_r001215_9_1 != sec_r001215_9_2);
  __CPROVER_assume(sec_r001215_0_1 != sec_r001215_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.peak == st_var_1_2.peak);
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

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
  assert(helper_flow_3_1 == helper_flow_3_2);
  assert(helper_flow_4_1 == helper_flow_4_2);
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
  assert(helper_flow_8_1 == helper_flow_8_2);
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
  assert(stage_v_465_1 == stage_v_465_2);
  assert(stage_v_466_1 == stage_v_466_2);
  assert(stage_v_467_1 == stage_v_467_2);
  assert(stage_v_468_1 == stage_v_468_2);
  assert(stage_v_469_1 == stage_v_469_2);
  assert(stage_v_470_1 == stage_v_470_2);
  assert(stage_v_471_1 == stage_v_471_2);
  assert(stage_v_472_1 == stage_v_472_2);
  assert(stage_v_473_1 == stage_v_473_2);
  assert(stage_v_474_1 == stage_v_474_2);
  assert(stage_v_475_1 == stage_v_475_2);
  assert(stage_v_476_1 == stage_v_476_2);
  assert(stage_v_477_1 == stage_v_477_2);
  assert(stage_v_478_1 == stage_v_478_2);
  assert(stage_v_479_1 == stage_v_479_2);
  assert(stage_v_480_1 == stage_v_480_2);
  assert(stage_v_481_1 == stage_v_481_2);
  assert(stage_v_482_1 == stage_v_482_2);
  assert(stage_v_483_1 == stage_v_483_2);
  assert(stage_v_484_1 == stage_v_484_2);
  assert(stage_v_485_1 == stage_v_485_2);
  assert(stage_v_486_1 == stage_v_486_2);
  assert(stage_v_487_1 == stage_v_487_2);
  assert(stage_v_488_1 == stage_v_488_2);
  assert(stage_v_489_1 == stage_v_489_2);
  assert(stage_v_490_1 == stage_v_490_2);
  assert(stage_v_491_1 == stage_v_491_2);
  assert(stage_v_492_1 == stage_v_492_2);
  assert(stage_v_493_1 == stage_v_493_2);
  assert(stage_v_494_1 == stage_v_494_2);
  assert(stage_v_495_1 == stage_v_495_2);
  assert(stage_v_496_1 == stage_v_496_2);
  assert(stage_v_497_1 == stage_v_497_2);
  assert(stage_v_498_1 == stage_v_498_2);
  assert(stage_v_499_1 == stage_v_499_2);
  assert(stage_v_500_1 == stage_v_500_2);
  assert(stage_v_501_1 == stage_v_501_2);
  assert(stage_v_502_1 == stage_v_502_2);
  assert(stage_v_503_1 == stage_v_503_2);
  assert(stage_v_504_1 == stage_v_504_2);
}


