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
struct FilterState_R000407_713_0
{
  short prev_in;
  unsigned char mode;
  int cutoff;
  short prev_out;
  int damping;
  int buffer[3];
};
struct EventLog_R000407_713_1
{
  unsigned char facility;
  short signature;
  short code;
  short severity;
  short seq;
  short timestamp;
  int buffer[3];
};
struct Transaction_R000407_713_2
{
  short rate;
  unsigned char balance;
  unsigned char account_id;
  unsigned char status;
  short fee;
  unsigned char auth_code;
  int buffer[3];
};
struct AudioFrame_R000407_713_3
{
  short gain;
  int envelope;
  int sample_rate;
  int buffer[3];
};
union RegisterBank_R000407_713_0
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
void fn_R000407_713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000407_713_3 st_1 = {0};
  struct AudioFrame_R000407_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_12_1 = local_arr_1[aux_1 % 3];
  int threshold_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_12_2 * 2)) & 127;
  int window_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_19_1) & 63;
  aux_2 = (aux_2 + window_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_22_1 > 19)
  {
    acc_1 = ((acc_1 + (accumulator_22_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_22_2 > 19)
  {
    acc_2 = ((acc_2 + (accumulator_22_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_22_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_12_1 == threshold_12_2);
  assert(window_19_1 == window_19_2);
  assert(accumulator_22_1 == accumulator_22_2);
}

int fn_R000407_713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000407_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int threshold_12 = local_arr[aux % 3];
  acc = (acc + (threshold_12 * 2)) & 127;
  int window_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_19) & 63;
  acc ^= aux;
  int accumulator_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_22 > 19)
  {
    acc = ((acc + (accumulator_22 * 2)) + 5) & 127;
    aux ^= accumulator_22 & 15;
  }
  else
  {
    acc = ((acc - accumulator_22) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000407_713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000407_713_2 st_1 = {0};
  struct Transaction_R000407_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int index_reg_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_19_1) & 63;
  aux_2 = (aux_2 + index_reg_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_71_1)
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

  switch (mask_71_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_19_1 == index_reg_19_2);
  assert(mask_71_1 == mask_71_2);
}

int fn_R000407_713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000407_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int index_reg_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_19) & 63;
  acc ^= aux;
  int mask_71 = (aux + st.buffer[1]) & 3;
  switch (mask_71)
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

void fn_R000407_713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000407_713_3 st_1 = {0};
  struct AudioFrame_R000407_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int bound_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_76_1 > 18)
  {
    acc_1 = ((acc_1 + (bound_76_1 * 2)) + 5) & 127;
    aux_1 ^= bound_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_76_2 > 18)
  {
    acc_2 = ((acc_2 + (bound_76_2 * 2)) + 5) & 127;
    aux_2 ^= bound_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_76_2) + 11) & 127;
    aux_2 += 3;
  }
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_43_1 = local_arr_1[aux_1 % 3];
  int tally_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_43_2 * 2)) & 127;
  int residue_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_92_1) & 63;
  aux_2 = (aux_2 + residue_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_76_1 == bound_76_2);
  assert(mask_69_1 == mask_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_43_1 == tally_43_2);
  assert(residue_92_1 == residue_92_2);
}

int fn_R000407_713_2(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000407_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int bound_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_76 > 18)
  {
    acc = ((acc + (bound_76 * 2)) + 5) & 127;
    aux ^= bound_76 & 15;
  }
  else
  {
    acc = ((acc - bound_76) + 11) & 127;
    aux += 3;
  }
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

  int local_arr[3] = {4, 9, 15};
  int tally_43 = local_arr[aux % 3];
  acc = (acc + (tally_43 * 2)) & 127;
  int residue_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000407_713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000407_713_3 st_1 = {0};
  struct AudioFrame_R000407_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_58_1) & 63;
  aux_2 = (aux_2 + scale_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_89_1 = local_arr_1[aux_1 % 3];
  int factor_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_89_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_58_1 == scale_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_89_1 == factor_89_2);
}

int fn_R000407_713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000407_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_58) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_89 = local_arr[aux % 3];
  acc = (acc + (factor_89 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000407_713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000407_713_3 st_1 = {0};
  struct AudioFrame_R000407_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_64_1) & 63;
  aux_2 = (aux_2 + cursor_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_54_1 > 36)
  {
    acc_1 = ((acc_1 + (delta_54_1 * 2)) + 5) & 127;
    aux_1 ^= delta_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_54_2 > 36)
  {
    acc_2 = ((acc_2 + (delta_54_2 * 2)) + 5) & 127;
    aux_2 ^= delta_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_54_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_64_1 == cursor_64_2);
  assert(delta_54_1 == delta_54_2);
}

int fn_R000407_713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000407_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_64) & 63;
  acc ^= aux;
  int delta_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_54 > 36)
  {
    acc = ((acc + (delta_54 * 2)) + 5) & 127;
    aux ^= delta_54 & 15;
  }
  else
  {
    acc = ((acc - delta_54) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000407_713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000407_713_0 st_1 = {0};
  struct FilterState_R000407_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int margin_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_81_1 > 16)
  {
    acc_1 = ((acc_1 + (margin_81_1 * 2)) + 5) & 127;
    aux_1 ^= margin_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_81_2 > 16)
  {
    acc_2 = ((acc_2 + (margin_81_2 * 2)) + 5) & 127;
    aux_2 ^= margin_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_81_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_39_1)
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

  switch (stride_39_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_81_1 == margin_81_2);
  assert(stride_39_1 == stride_39_2);
}

int fn_R000407_713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000407_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int margin_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_81 > 16)
  {
    acc = ((acc + (margin_81 * 2)) + 5) & 127;
    aux ^= margin_81 & 15;
  }
  else
  {
    acc = ((acc - margin_81) + 11) & 127;
    aux += 3;
  }
  int stride_39 = (aux + st.buffer[1]) & 3;
  switch (stride_39)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000407_713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000407_713_0 st_1 = {0};
  struct FilterState_R000407_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int threshold_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_57_1)
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

  switch (threshold_57_2)
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
  int parity_40_1 = local_arr_1[aux_1 % 3];
  int parity_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_40_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_57_1 == threshold_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_40_1 == parity_40_2);
}

int fn_R000407_713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000407_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int threshold_57 = (aux + st.buffer[1]) & 3;
  switch (threshold_57)
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
  int parity_40 = local_arr[aux % 3];
  acc = (acc + (parity_40 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000407_713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000407_713_0 st_1 = {0};
  struct FilterState_R000407_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int parity_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_27_1 > 10)
  {
    acc_1 = ((acc_1 + (parity_27_1 * 2)) + 5) & 127;
    aux_1 ^= parity_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_27_2 > 10)
  {
    acc_2 = ((acc_2 + (parity_27_2 * 2)) + 5) & 127;
    aux_2 ^= parity_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_57_1 = local_arr_1[aux_1 % 3];
  int damping_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_57_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_27_1 == parity_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_57_1 == damping_57_2);
}

int fn_R000407_713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000407_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int parity_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_27 > 10)
  {
    acc = ((acc + (parity_27 * 2)) + 5) & 127;
    aux ^= parity_27 & 15;
  }
  else
  {
    acc = ((acc - parity_27) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int damping_57 = local_arr[aux % 3];
  acc = (acc + (damping_57 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000407_713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000407_713_1 st_1 = {0};
  struct EventLog_R000407_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int phase_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_42_1) & 63;
  aux_2 = (aux_2 + phase_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_30_1 > 17)
  {
    acc_1 = ((acc_1 + (weight_30_1 * 2)) + 5) & 127;
    aux_1 ^= weight_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_30_2 > 17)
  {
    acc_2 = ((acc_2 + (weight_30_2 * 2)) + 5) & 127;
    aux_2 ^= weight_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_30_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_42_1 == phase_42_2);
  assert(weight_30_1 == weight_30_2);
}

int fn_R000407_713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000407_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int phase_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_42) & 63;
  acc ^= aux;
  int weight_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_30 > 17)
  {
    acc = ((acc + (weight_30 * 2)) + 5) & 127;
    aux ^= weight_30 & 15;
  }
  else
  {
    acc = ((acc - weight_30) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000407_713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000407_713_3 st_1 = {0};
  struct AudioFrame_R000407_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_60_1) & 63;
  aux_2 = (aux_2 + quantum_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_14_1 = local_arr_1[aux_1 % 3];
  int damping_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_14_2 * 2)) & 127;
  int sample_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_13_1 > 30)
  {
    acc_1 = ((acc_1 + (sample_13_1 * 2)) + 5) & 127;
    aux_1 ^= sample_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_13_2 > 30)
  {
    acc_2 = ((acc_2 + (sample_13_2 * 2)) + 5) & 127;
    aux_2 ^= sample_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_13_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_60_1 == quantum_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_14_1 == damping_14_2);
  assert(sample_13_1 == sample_13_2);
}

int fn_R000407_713_9(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000407_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_60) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int damping_14 = local_arr[aux % 3];
  acc = (acc + (damping_14 * 2)) & 127;
  int sample_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_13 > 30)
  {
    acc = ((acc + (sample_13 * 2)) + 5) & 127;
    aux ^= sample_13 & 15;
  }
  else
  {
    acc = ((acc - sample_13) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000407_713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000407_713_2 st_1 = {0};
  struct Transaction_R000407_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_99_1) & 63;
  aux_2 = (aux_2 + phase_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_99_1 == phase_99_2);
}

int fn_R000407_713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000407_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000407_713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000407_713_1 st_1 = {0};
  struct EventLog_R000407_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int anchor_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_69_1) & 63;
  aux_2 = (aux_2 + anchor_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_65_1)
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

  switch (quotient_65_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_69_1 == anchor_69_2);
  assert(quotient_65_1 == quotient_65_2);
}

int fn_R000407_713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000407_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int anchor_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_69) & 63;
  acc ^= aux;
  int quotient_65 = (aux + st.buffer[1]) & 3;
  switch (quotient_65)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000407_713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000407_713_1 st_1 = {0};
  struct EventLog_R000407_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_71_1 = local_arr_1[aux_1 % 3];
  int index_reg_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_71_2 * 2)) & 127;
  int threshold_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_68_1)
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

  switch (threshold_68_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_71_1 == index_reg_71_2);
  assert(threshold_68_1 == threshold_68_2);
}

int fn_R000407_713_12(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000407_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int index_reg_71 = local_arr[aux % 3];
  acc = (acc + (index_reg_71 * 2)) & 127;
  int threshold_68 = (aux + st.buffer[1]) & 3;
  switch (threshold_68)
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

void fn_R000407_713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000407_713_2 st_1 = {0};
  struct Transaction_R000407_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int quotient_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_40_1) & 63;
  aux_2 = (aux_2 + quotient_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_63_1 = local_arr_1[aux_1 % 3];
  int sample_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_63_2 * 2)) & 127;
  int factor_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_41_1 > 46)
  {
    acc_1 = ((acc_1 + (factor_41_1 * 2)) + 5) & 127;
    aux_1 ^= factor_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_41_2 > 46)
  {
    acc_2 = ((acc_2 + (factor_41_2 * 2)) + 5) & 127;
    aux_2 ^= factor_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_41_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_40_1 == quotient_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_63_1 == sample_63_2);
  assert(factor_41_1 == factor_41_2);
}

int fn_R000407_713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000407_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int quotient_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_40) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_63 = local_arr[aux % 3];
  acc = (acc + (sample_63 * 2)) & 127;
  int factor_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_41 > 46)
  {
    acc = ((acc + (factor_41 * 2)) + 5) & 127;
    aux ^= factor_41 & 15;
  }
  else
  {
    acc = ((acc - factor_41) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000407_713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000407_713_2 st_1 = {0};
  struct Transaction_R000407_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_12_1 = local_arr_1[aux_1 % 3];
  int segment_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_12_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_49_1) & 63;
  aux_2 = (aux_2 + vector_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_12_1 == segment_12_2);
  assert(vector_49_1 == vector_49_2);
}

int fn_R000407_713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000407_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int segment_12 = local_arr[aux % 3];
  acc = (acc + (segment_12 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_49) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000407_0_1;
  int sec_r000407_0_2;
  int sec_r000407_1_1;
  int sec_r000407_1_2;
  int sec_r000407_2_1;
  int sec_r000407_2_2;
  int sec_r000407_3_1;
  int sec_r000407_3_2;
  int sec_r000407_4_1;
  int sec_r000407_4_2;
  int sec_r000407_5_1;
  int sec_r000407_5_2;
  int sec_r000407_6_1;
  int sec_r000407_6_2;
  int sec_r000407_7_1;
  int sec_r000407_7_2;
  int sec_r000407_8_1;
  int sec_r000407_8_2;
  int sec_r000407_9_1;
  int sec_r000407_9_2;
  int sec_r000407_10_1;
  int sec_r000407_10_2;
  int sec_r000407_11_1;
  int sec_r000407_11_2;
  int sec_r000407_12_1;
  int sec_r000407_12_2;
  int sec_r000407_13_1;
  int sec_r000407_13_2;
  int sec_r000407_14_1;
  int sec_r000407_14_2;
  int sec_r000407_15_1;
  int sec_r000407_15_2;
  int sec_r000407_16_1;
  int sec_r000407_16_2;
  int sec_r000407_17_1;
  int sec_r000407_17_2;
  int sec_r000407_18_1;
  int sec_r000407_18_2;
  int sec_r000407_19_1;
  int sec_r000407_19_2;
  int sec_r000407_20_1;
  int sec_r000407_20_2;
  int sec_r000407_21_1;
  int sec_r000407_21_2;
  int sec_r000407_22_1;
  int sec_r000407_22_2;
  int pub_r000407_0_1;
  int pub_r000407_0_2;
  int pub_r000407_1_1;
  int pub_r000407_1_2;
  int pub_r000407_2_1;
  int pub_r000407_2_2;
  int pub_r000407_3_1;
  int pub_r000407_3_2;
  int pub_r000407_4_1;
  int pub_r000407_4_2;
  int pub_r000407_5_1;
  int pub_r000407_5_2;
  int pub_r000407_6_1;
  int pub_r000407_6_2;
  int pub_r000407_7_1;
  int pub_r000407_7_2;
  int pub_r000407_8_1;
  int pub_r000407_8_2;
  int pub_r000407_9_1;
  int pub_r000407_9_2;
  int pub_r000407_10_1;
  int pub_r000407_10_2;
  int pub_r000407_11_1;
  int pub_r000407_11_2;
  int pub_r000407_12_1;
  int pub_r000407_12_2;
  int pub_r000407_13_1;
  int pub_r000407_13_2;
  int pub_r000407_14_1;
  int pub_r000407_14_2;
  int pub_r000407_15_1;
  int pub_r000407_15_2;
  int pub_r000407_16_1;
  int pub_r000407_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000407_0_1 >= (-100)) && (pub_r000407_0_1 <= 100));
  __CPROVER_assume((pub_r000407_0_2 >= (-100)) && (pub_r000407_0_2 <= 100));
  __CPROVER_assume((pub_r000407_1_1 >= (-100)) && (pub_r000407_1_1 <= 100));
  __CPROVER_assume((pub_r000407_1_2 >= (-100)) && (pub_r000407_1_2 <= 100));
  __CPROVER_assume((pub_r000407_2_1 >= (-100)) && (pub_r000407_2_1 <= 100));
  __CPROVER_assume((pub_r000407_2_2 >= (-100)) && (pub_r000407_2_2 <= 100));
  __CPROVER_assume((pub_r000407_3_1 >= (-100)) && (pub_r000407_3_1 <= 100));
  __CPROVER_assume((pub_r000407_3_2 >= (-100)) && (pub_r000407_3_2 <= 100));
  __CPROVER_assume((pub_r000407_4_1 >= (-100)) && (pub_r000407_4_1 <= 100));
  __CPROVER_assume((pub_r000407_4_2 >= (-100)) && (pub_r000407_4_2 <= 100));
  __CPROVER_assume((pub_r000407_5_1 >= (-100)) && (pub_r000407_5_1 <= 100));
  __CPROVER_assume((pub_r000407_5_2 >= (-100)) && (pub_r000407_5_2 <= 100));
  __CPROVER_assume((pub_r000407_6_1 >= (-100)) && (pub_r000407_6_1 <= 100));
  __CPROVER_assume((pub_r000407_6_2 >= (-100)) && (pub_r000407_6_2 <= 100));
  __CPROVER_assume((pub_r000407_7_1 >= (-100)) && (pub_r000407_7_1 <= 100));
  __CPROVER_assume((pub_r000407_7_2 >= (-100)) && (pub_r000407_7_2 <= 100));
  __CPROVER_assume((pub_r000407_8_1 >= (-100)) && (pub_r000407_8_1 <= 100));
  __CPROVER_assume((pub_r000407_8_2 >= (-100)) && (pub_r000407_8_2 <= 100));
  __CPROVER_assume((pub_r000407_9_1 >= (-100)) && (pub_r000407_9_1 <= 100));
  __CPROVER_assume((pub_r000407_9_2 >= (-100)) && (pub_r000407_9_2 <= 100));
  __CPROVER_assume((pub_r000407_10_1 >= (-100)) && (pub_r000407_10_1 <= 100));
  __CPROVER_assume((pub_r000407_10_2 >= (-100)) && (pub_r000407_10_2 <= 100));
  __CPROVER_assume((pub_r000407_11_1 >= (-100)) && (pub_r000407_11_1 <= 100));
  __CPROVER_assume((pub_r000407_11_2 >= (-100)) && (pub_r000407_11_2 <= 100));
  __CPROVER_assume((pub_r000407_12_1 >= (-100)) && (pub_r000407_12_1 <= 100));
  __CPROVER_assume((pub_r000407_12_2 >= (-100)) && (pub_r000407_12_2 <= 100));
  __CPROVER_assume((pub_r000407_13_1 >= (-100)) && (pub_r000407_13_1 <= 100));
  __CPROVER_assume((pub_r000407_13_2 >= (-100)) && (pub_r000407_13_2 <= 100));
  __CPROVER_assume((pub_r000407_14_1 >= (-100)) && (pub_r000407_14_1 <= 100));
  __CPROVER_assume((pub_r000407_14_2 >= (-100)) && (pub_r000407_14_2 <= 100));
  __CPROVER_assume((pub_r000407_15_1 >= (-100)) && (pub_r000407_15_1 <= 100));
  __CPROVER_assume((pub_r000407_15_2 >= (-100)) && (pub_r000407_15_2 <= 100));
  __CPROVER_assume((pub_r000407_16_1 >= (-100)) && (pub_r000407_16_1 <= 100));
  __CPROVER_assume((pub_r000407_16_2 >= (-100)) && (pub_r000407_16_2 <= 100));
  __CPROVER_assume((sec_r000407_0_1 >= 0) && (sec_r000407_0_1 <= 255));
  __CPROVER_assume((sec_r000407_0_2 >= 0) && (sec_r000407_0_2 <= 255));
  __CPROVER_assume((sec_r000407_1_1 >= 0) && (sec_r000407_1_1 <= 255));
  __CPROVER_assume((sec_r000407_1_2 >= 0) && (sec_r000407_1_2 <= 255));
  __CPROVER_assume((sec_r000407_2_1 >= 0) && (sec_r000407_2_1 <= 255));
  __CPROVER_assume((sec_r000407_2_2 >= 0) && (sec_r000407_2_2 <= 255));
  __CPROVER_assume((sec_r000407_3_1 >= 0) && (sec_r000407_3_1 <= 255));
  __CPROVER_assume((sec_r000407_3_2 >= 0) && (sec_r000407_3_2 <= 255));
  __CPROVER_assume((sec_r000407_4_1 >= 0) && (sec_r000407_4_1 <= 255));
  __CPROVER_assume((sec_r000407_4_2 >= 0) && (sec_r000407_4_2 <= 255));
  __CPROVER_assume((sec_r000407_5_1 >= 0) && (sec_r000407_5_1 <= 255));
  __CPROVER_assume((sec_r000407_5_2 >= 0) && (sec_r000407_5_2 <= 255));
  __CPROVER_assume((sec_r000407_6_1 >= 0) && (sec_r000407_6_1 <= 255));
  __CPROVER_assume((sec_r000407_6_2 >= 0) && (sec_r000407_6_2 <= 255));
  __CPROVER_assume((sec_r000407_7_1 >= 0) && (sec_r000407_7_1 <= 255));
  __CPROVER_assume((sec_r000407_7_2 >= 0) && (sec_r000407_7_2 <= 255));
  __CPROVER_assume((sec_r000407_8_1 >= 0) && (sec_r000407_8_1 <= 255));
  __CPROVER_assume((sec_r000407_8_2 >= 0) && (sec_r000407_8_2 <= 255));
  __CPROVER_assume((sec_r000407_9_1 >= 0) && (sec_r000407_9_1 <= 255));
  __CPROVER_assume((sec_r000407_9_2 >= 0) && (sec_r000407_9_2 <= 255));
  __CPROVER_assume((sec_r000407_10_1 >= 0) && (sec_r000407_10_1 <= 255));
  __CPROVER_assume((sec_r000407_10_2 >= 0) && (sec_r000407_10_2 <= 255));
  __CPROVER_assume((sec_r000407_11_1 >= 0) && (sec_r000407_11_1 <= 255));
  __CPROVER_assume((sec_r000407_11_2 >= 0) && (sec_r000407_11_2 <= 255));
  __CPROVER_assume((sec_r000407_12_1 >= 0) && (sec_r000407_12_1 <= 255));
  __CPROVER_assume((sec_r000407_12_2 >= 0) && (sec_r000407_12_2 <= 255));
  __CPROVER_assume((sec_r000407_13_1 >= 0) && (sec_r000407_13_1 <= 255));
  __CPROVER_assume((sec_r000407_13_2 >= 0) && (sec_r000407_13_2 <= 255));
  __CPROVER_assume((sec_r000407_14_1 >= 0) && (sec_r000407_14_1 <= 255));
  __CPROVER_assume((sec_r000407_14_2 >= 0) && (sec_r000407_14_2 <= 255));
  __CPROVER_assume((sec_r000407_15_1 >= 0) && (sec_r000407_15_1 <= 255));
  __CPROVER_assume((sec_r000407_15_2 >= 0) && (sec_r000407_15_2 <= 255));
  __CPROVER_assume((sec_r000407_16_1 >= 0) && (sec_r000407_16_1 <= 255));
  __CPROVER_assume((sec_r000407_16_2 >= 0) && (sec_r000407_16_2 <= 255));
  __CPROVER_assume((sec_r000407_17_1 >= 0) && (sec_r000407_17_1 <= 255));
  __CPROVER_assume((sec_r000407_17_2 >= 0) && (sec_r000407_17_2 <= 255));
  __CPROVER_assume((sec_r000407_18_1 >= 0) && (sec_r000407_18_1 <= 255));
  __CPROVER_assume((sec_r000407_18_2 >= 0) && (sec_r000407_18_2 <= 255));
  __CPROVER_assume((sec_r000407_19_1 >= 0) && (sec_r000407_19_1 <= 255));
  __CPROVER_assume((sec_r000407_19_2 >= 0) && (sec_r000407_19_2 <= 255));
  __CPROVER_assume((sec_r000407_20_1 >= 0) && (sec_r000407_20_1 <= 255));
  __CPROVER_assume((sec_r000407_20_2 >= 0) && (sec_r000407_20_2 <= 255));
  __CPROVER_assume((sec_r000407_21_1 >= 0) && (sec_r000407_21_1 <= 255));
  __CPROVER_assume((sec_r000407_21_2 >= 0) && (sec_r000407_21_2 <= 255));
  __CPROVER_assume((sec_r000407_22_1 >= 0) && (sec_r000407_22_1 <= 255));
  __CPROVER_assume((sec_r000407_22_2 >= 0) && (sec_r000407_22_2 <= 255));
  struct FilterState_R000407_713_0 st_var_0_1 = {0};
  struct FilterState_R000407_713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000407_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000407_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000407_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000407_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000407_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000407_0_2 + 7) & 15;
  struct EventLog_R000407_713_1 st_var_1_1 = {0};
  struct EventLog_R000407_713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000407_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000407_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000407_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000407_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000407_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000407_0_2 + 9) & 15;
  struct Transaction_R000407_713_2 st_var_2_1 = {0};
  struct Transaction_R000407_713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000407_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000407_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000407_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000407_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000407_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000407_0_2 + 11) & 15;
  struct AudioFrame_R000407_713_3 st_var_3_1 = {0};
  struct AudioFrame_R000407_713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000407_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000407_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000407_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000407_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000407_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000407_0_2 + 13) & 15;
  union RegisterBank_R000407_713_0 u_var_1;
  union RegisterBank_R000407_713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 29)
    {
      chk_sum_1 ^= stage_v_0_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_0_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 29)
    {
      chk_sum_2 ^= stage_v_0_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 4) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  int stage_v_7_1 = ((st_var_3_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_3_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 33)
    {
      chk_sum_1 ^= stage_v_7_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_7_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 33)
    {
      chk_sum_2 ^= stage_v_7_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  int stage_v_17_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (22 & 31);
  int stage_v_17_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (22 & 31);
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= (stage_v_17_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_17_2 << 1) & 127;
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 23) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 24) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = table_1[1];
  int stage_v_25_2 = table_2[1];
  table_1[1] = (table_1[2] + 51) & 63;
  table_2[1] = (table_2[2] + 51) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 41)
    {
      chk_sum_1 ^= stage_v_26_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_26_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 41)
    {
      chk_sum_2 ^= stage_v_26_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (33 & 31);
  int stage_v_28_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (33 & 31);
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= (stage_v_28_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_28_2 << 1) & 127;
  int stage_v_29_1 = ((st_var_1_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_1_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 50)
    {
      chk_sum_1 ^= stage_v_29_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_29_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 50)
    {
      chk_sum_2 ^= stage_v_29_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 32) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= stage_v_31_1;
  chk_sum_2 ^= stage_v_31_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 33) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
  int stage_v_33_1 = (st_var_1_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_1_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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

  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
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

  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
  int stage_v_38_1 = (st_var_2_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_2_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
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

  switch (stage_v_38_2)
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
  int stage_v_43_1 = ((st_var_3_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_3_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 44)
    {
      chk_sum_1 ^= stage_v_43_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_43_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 44)
    {
      chk_sum_2 ^= stage_v_43_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 46) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = table_1[2];
  int stage_v_46_2 = table_2[2];
  table_1[2] = (table_1[3] + 93) & 63;
  table_2[2] = (table_2[3] + 93) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (st_var_3_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_3_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
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

  switch (stage_v_47_2)
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

  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((sec_r000407_8_1 & 1) != 0)
  {
    if ((sec_r000407_15_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000407_14_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000407_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000407_14_1 + 7) & 127;
  }
  if ((sec_r000407_8_2 & 1) != 0)
  {
    if ((sec_r000407_15_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000407_14_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000407_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000407_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((sec_r000407_18_1 & 1) != 0)
  {
    if ((sec_r000407_13_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000407_16_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000407_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000407_16_1 + 7) & 127;
  }
  if ((sec_r000407_18_2 & 1) != 0)
  {
    if ((sec_r000407_13_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000407_16_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000407_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000407_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000407_21_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000407_11_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000407_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000407_11_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000407_21_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000407_11_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000407_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000407_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((sec_r000407_11_1 & 1) != 0)
  {
    if ((sec_r000407_18_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000407_2_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000407_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000407_2_1 + 7) & 127;
  }
  if ((sec_r000407_11_2 & 1) != 0)
  {
    if ((sec_r000407_18_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000407_2_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000407_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000407_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000407_10_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000407_11_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000407_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000407_11_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000407_10_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000407_11_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000407_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000407_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000407_16_1 & 1) != 0)
  {
    if ((sec_r000407_4_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000407_9_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000407_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000407_9_1 + 7) & 127;
  }
  if ((sec_r000407_16_2 & 1) != 0)
  {
    if ((sec_r000407_4_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000407_9_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000407_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000407_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000407_18_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000407_4_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000407_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000407_4_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000407_18_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000407_4_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000407_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000407_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000407_20_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000407_16_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000407_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000407_16_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000407_20_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000407_16_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000407_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000407_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((sec_r000407_14_1 & 1) != 0)
  {
    if ((sec_r000407_6_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000407_4_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000407_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000407_4_1 + 7) & 127;
  }
  if ((sec_r000407_14_2 & 1) != 0)
  {
    if ((sec_r000407_6_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000407_4_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000407_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000407_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((sec_r000407_16_1 & 1) != 0)
  {
    if ((sec_r000407_6_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000407_10_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000407_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000407_10_1 + 7) & 127;
  }
  if ((sec_r000407_16_2 & 1) != 0)
  {
    if ((sec_r000407_6_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000407_10_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000407_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000407_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000407_10_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000407_1_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000407_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000407_1_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000407_10_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000407_1_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000407_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000407_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000407_15_1 & 1) != 0)
  {
    if ((sec_r000407_11_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000407_15_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000407_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000407_15_1 + 7) & 127;
  }
  if ((sec_r000407_15_2 & 1) != 0)
  {
    if ((sec_r000407_11_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000407_15_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000407_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000407_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((sec_r000407_18_1 & 1) != 0)
  {
    if ((sec_r000407_19_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000407_9_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000407_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000407_9_1 + 7) & 127;
  }
  if ((sec_r000407_18_2 & 1) != 0)
  {
    if ((sec_r000407_19_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000407_9_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000407_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000407_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000407_0_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000407_2_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000407_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000407_2_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000407_0_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000407_2_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000407_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000407_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((sec_r000407_14_1 & 1) != 0)
  {
    if ((sec_r000407_16_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000407_5_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000407_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000407_5_1 + 7) & 127;
  }
  if ((sec_r000407_14_2 & 1) != 0)
  {
    if ((sec_r000407_16_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000407_5_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000407_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000407_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000407_19_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000407_10_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000407_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000407_10_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000407_19_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000407_10_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000407_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000407_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000407_11_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000407_5_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000407_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000407_5_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000407_11_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000407_5_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000407_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000407_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000407_14_1 & 1) != 0)
  {
    if ((sec_r000407_13_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000407_1_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000407_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000407_1_1 + 7) & 127;
  }
  if ((sec_r000407_14_2 & 1) != 0)
  {
    if ((sec_r000407_13_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000407_1_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000407_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000407_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000407_8_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000407_1_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000407_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000407_1_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000407_8_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000407_1_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000407_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000407_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((sec_r000407_20_1 & 1) != 0)
  {
    if ((sec_r000407_3_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000407_2_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000407_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000407_2_1 + 7) & 127;
  }
  if ((sec_r000407_20_2 & 1) != 0)
  {
    if ((sec_r000407_3_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000407_2_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000407_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000407_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000407_16_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000407_14_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000407_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000407_14_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000407_16_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000407_14_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000407_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000407_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000407_14_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000407_0_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000407_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000407_0_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000407_14_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000407_0_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000407_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000407_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000407_15_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000407_8_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000407_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000407_8_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000407_15_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000407_8_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000407_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000407_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((sec_r000407_10_1 & 1) != 0)
  {
    if ((sec_r000407_13_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000407_5_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000407_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000407_5_1 + 7) & 127;
  }
  if ((sec_r000407_10_2 & 1) != 0)
  {
    if ((sec_r000407_13_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000407_5_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000407_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000407_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000407_9_1 & 1) != 0)
  {
    if ((sec_r000407_6_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000407_1_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000407_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000407_1_1 + 7) & 127;
  }
  if ((sec_r000407_9_2 & 1) != 0)
  {
    if ((sec_r000407_6_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000407_1_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000407_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000407_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000407_10_1 & 1) != 0)
  {
    if ((sec_r000407_1_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000407_5_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000407_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000407_5_1 + 7) & 127;
  }
  if ((sec_r000407_10_2 & 1) != 0)
  {
    if ((sec_r000407_1_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000407_5_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000407_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000407_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000407_21_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000407_16_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000407_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000407_16_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000407_21_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000407_16_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000407_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000407_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000407_11_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000407_7_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000407_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000407_7_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000407_11_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000407_7_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000407_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000407_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000407_20_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000407_15_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000407_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000407_15_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000407_20_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000407_15_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000407_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000407_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000407_4_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000407_3_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000407_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000407_3_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000407_4_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000407_3_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000407_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000407_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000407_19_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000407_2_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000407_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000407_2_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000407_19_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000407_2_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000407_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000407_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000407_9_1 & 1) != 0)
  {
    if ((sec_r000407_16_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000407_15_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000407_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000407_15_1 + 7) & 127;
  }
  if ((sec_r000407_9_2 & 1) != 0)
  {
    if ((sec_r000407_16_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000407_15_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000407_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000407_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000407_10_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000407_15_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000407_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000407_15_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000407_10_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000407_15_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000407_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000407_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000407_21_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000407_13_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000407_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000407_13_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000407_21_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000407_13_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000407_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000407_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000407_21_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000407_0_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000407_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000407_0_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000407_21_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000407_0_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000407_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000407_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000407_22_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000407_11_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000407_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000407_11_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000407_22_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000407_11_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000407_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000407_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000407_11_1 & 1) != 0)
  {
    if ((sec_r000407_20_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000407_8_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000407_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000407_8_1 + 7) & 127;
  }
  if ((sec_r000407_11_2 & 1) != 0)
  {
    if ((sec_r000407_20_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000407_8_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000407_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000407_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000407_7_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000407_11_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000407_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000407_11_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000407_7_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000407_11_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000407_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000407_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000407_19_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000407_15_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000407_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000407_15_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000407_19_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000407_15_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000407_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000407_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000407_1_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000407_8_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000407_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000407_8_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000407_1_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000407_8_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000407_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000407_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000407_14_1 & 1) != 0)
  {
    if ((sec_r000407_6_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000407_15_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000407_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000407_15_1 + 7) & 127;
  }
  if ((sec_r000407_14_2 & 1) != 0)
  {
    if ((sec_r000407_6_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000407_15_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000407_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000407_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000407_20_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000407_2_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000407_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000407_2_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000407_20_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000407_2_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000407_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000407_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000407_20_1 & 1) != 0)
  {
    if ((sec_r000407_21_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000407_16_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000407_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000407_16_1 + 7) & 127;
  }
  if ((sec_r000407_20_2 & 1) != 0)
  {
    if ((sec_r000407_21_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000407_16_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000407_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000407_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000407_5_1 & 1) != 0)
  {
    if ((sec_r000407_17_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000407_13_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000407_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000407_13_1 + 7) & 127;
  }
  if ((sec_r000407_5_2 & 1) != 0)
  {
    if ((sec_r000407_17_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000407_13_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000407_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000407_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000407_6_1 & 1) != 0)
  {
    if ((sec_r000407_14_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000407_2_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000407_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000407_2_1 + 7) & 127;
  }
  if ((sec_r000407_6_2 & 1) != 0)
  {
    if ((sec_r000407_14_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000407_2_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000407_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000407_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000407_22_1 & 1) != 0)
  {
    if ((sec_r000407_5_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000407_2_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000407_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000407_2_1 + 7) & 127;
  }
  if ((sec_r000407_22_2 & 1) != 0)
  {
    if ((sec_r000407_5_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000407_2_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000407_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000407_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000407_10_1 & 1) != 0)
  {
    if ((sec_r000407_0_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000407_12_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000407_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000407_12_1 + 7) & 127;
  }
  if ((sec_r000407_10_2 & 1) != 0)
  {
    if ((sec_r000407_0_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000407_12_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000407_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000407_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000407_13_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000407_8_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000407_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000407_8_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000407_13_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000407_8_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000407_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000407_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000407_7_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000407_10_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000407_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000407_10_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000407_7_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000407_10_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000407_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000407_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000407_14_1 & 1) != 0)
  {
    if ((sec_r000407_2_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000407_8_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000407_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000407_8_1 + 7) & 127;
  }
  if ((sec_r000407_14_2 & 1) != 0)
  {
    if ((sec_r000407_2_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000407_8_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000407_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000407_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000407_17_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000407_12_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000407_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000407_12_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000407_17_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000407_12_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000407_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000407_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000407_10_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000407_5_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000407_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000407_5_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000407_10_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000407_5_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000407_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000407_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000407_17_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000407_5_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000407_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000407_5_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000407_17_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000407_5_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000407_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000407_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000407_15_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000407_8_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000407_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000407_8_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000407_15_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000407_8_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000407_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000407_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000407_11_1 & 1) != 0)
  {
    if ((sec_r000407_9_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000407_14_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000407_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000407_14_1 + 7) & 127;
  }
  if ((sec_r000407_11_2 & 1) != 0)
  {
    if ((sec_r000407_9_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000407_14_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000407_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000407_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000407_17_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000407_15_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000407_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000407_15_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000407_17_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000407_15_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000407_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000407_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000407_11_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000407_6_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000407_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000407_6_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000407_11_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000407_6_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000407_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000407_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000407_5_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000407_10_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000407_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000407_10_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000407_5_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000407_10_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000407_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000407_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000407_18_1 & 1) != 0)
  {
    if ((sec_r000407_16_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000407_1_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000407_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000407_1_1 + 7) & 127;
  }
  if ((sec_r000407_18_2 & 1) != 0)
  {
    if ((sec_r000407_16_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000407_1_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000407_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000407_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000407_17_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000407_14_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000407_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000407_14_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000407_17_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000407_14_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000407_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000407_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000407_15_1 & 1) != 0)
  {
    if ((sec_r000407_18_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000407_14_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000407_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000407_14_1 + 7) & 127;
  }
  if ((sec_r000407_15_2 & 1) != 0)
  {
    if ((sec_r000407_18_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000407_14_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000407_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000407_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000407_4_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000407_14_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000407_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000407_14_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000407_4_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000407_14_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000407_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000407_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000407_6_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000407_12_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000407_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000407_12_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000407_6_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000407_12_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000407_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000407_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000407_6_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000407_14_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000407_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000407_14_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000407_6_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000407_14_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000407_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000407_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000407_12_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000407_7_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000407_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000407_7_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000407_12_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000407_7_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000407_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000407_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000407_4_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000407_5_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000407_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000407_5_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000407_4_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000407_5_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000407_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000407_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000407_22_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000407_7_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000407_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000407_7_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000407_22_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000407_7_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000407_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000407_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000407_9_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000407_14_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000407_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000407_14_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000407_9_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000407_14_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000407_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000407_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000407_5_1 & 1) != 0)
  {
    if ((sec_r000407_16_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000407_3_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000407_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000407_3_1 + 7) & 127;
  }
  if ((sec_r000407_5_2 & 1) != 0)
  {
    if ((sec_r000407_16_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000407_3_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000407_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000407_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000407_18_1 & 1) != 0)
  {
    if ((sec_r000407_16_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000407_0_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000407_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000407_0_1 + 7) & 127;
  }
  if ((sec_r000407_18_2 & 1) != 0)
  {
    if ((sec_r000407_16_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000407_0_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000407_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000407_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000407_6_1 & 1) != 0)
  {
    if ((sec_r000407_5_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000407_14_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000407_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000407_14_1 + 7) & 127;
  }
  if ((sec_r000407_6_2 & 1) != 0)
  {
    if ((sec_r000407_5_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000407_14_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000407_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000407_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000407_2_1 & 1) != 0)
  {
    if ((sec_r000407_13_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000407_15_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000407_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000407_15_1 + 7) & 127;
  }
  if ((sec_r000407_2_2 & 1) != 0)
  {
    if ((sec_r000407_13_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000407_15_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000407_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000407_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000407_4_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000407_4_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000407_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000407_4_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000407_4_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000407_4_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000407_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000407_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000407_11_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000407_5_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000407_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000407_5_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000407_11_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000407_5_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000407_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000407_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000407_22_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000407_10_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000407_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000407_10_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000407_22_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000407_10_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000407_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000407_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000407_14_1 & 1) != 0)
  {
    if ((sec_r000407_15_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000407_4_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000407_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000407_4_1 + 7) & 127;
  }
  if ((sec_r000407_14_2 & 1) != 0)
  {
    if ((sec_r000407_15_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000407_4_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000407_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000407_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000407_16_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000407_1_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000407_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000407_1_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000407_16_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000407_1_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000407_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000407_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000407_15_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000407_13_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000407_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000407_13_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000407_15_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000407_13_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000407_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000407_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000407_11_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000407_2_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000407_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000407_2_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000407_11_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000407_2_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000407_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000407_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000407_16_1 & 1) != 0)
  {
    if ((sec_r000407_11_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000407_0_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000407_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000407_0_1 + 7) & 127;
  }
  if ((sec_r000407_16_2 & 1) != 0)
  {
    if ((sec_r000407_11_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000407_0_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000407_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000407_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((sec_r000407_11_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000407_11_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000407_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000407_11_1 + 7) & 127;
  }
  if ((stage_v_127_2 & 1) != 0)
  {
    if ((sec_r000407_11_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000407_11_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000407_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000407_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000407_8_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000407_7_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000407_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000407_7_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000407_8_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000407_7_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000407_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000407_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000407_9_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000407_13_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000407_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000407_13_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000407_9_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000407_13_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000407_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000407_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000407_5_1 & 1) != 0)
  {
    if ((sec_r000407_20_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000407_9_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000407_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000407_9_1 + 7) & 127;
  }
  if ((sec_r000407_5_2 & 1) != 0)
  {
    if ((sec_r000407_20_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000407_9_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000407_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000407_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r000407_19_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000407_14_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000407_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000407_14_1 + 7) & 127;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r000407_19_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000407_14_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000407_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000407_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000407_22_1 & 1) != 0)
  {
    if ((sec_r000407_4_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000407_3_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000407_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000407_3_1 + 7) & 127;
  }
  if ((sec_r000407_22_2 & 1) != 0)
  {
    if ((sec_r000407_4_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000407_3_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000407_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000407_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000407_17_1 & 1) != 0)
  {
    if ((sec_r000407_5_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000407_2_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000407_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000407_2_1 + 7) & 127;
  }
  if ((sec_r000407_17_2 & 1) != 0)
  {
    if ((sec_r000407_5_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000407_2_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000407_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000407_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000407_19_1 & 1) != 0)
  {
    if ((sec_r000407_18_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000407_2_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000407_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000407_2_1 + 7) & 127;
  }
  if ((sec_r000407_19_2 & 1) != 0)
  {
    if ((sec_r000407_18_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000407_2_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000407_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000407_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000407_19_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000407_2_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000407_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000407_2_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000407_19_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000407_2_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000407_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000407_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000407_7_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000407_14_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000407_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000407_14_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000407_7_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000407_14_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000407_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000407_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000407_15_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000407_14_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000407_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000407_14_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000407_15_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000407_14_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000407_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000407_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000407_7_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000407_0_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000407_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000407_0_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000407_7_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000407_0_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000407_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000407_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((sec_r000407_14_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000407_7_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000407_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000407_7_1 + 7) & 127;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((sec_r000407_14_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000407_7_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000407_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000407_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000407_11_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000407_7_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000407_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000407_7_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000407_11_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000407_7_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000407_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000407_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000407_0_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000407_16_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000407_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000407_16_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000407_0_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000407_16_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000407_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000407_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000407_2_1 & 1) != 0)
  {
    if ((sec_r000407_21_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000407_16_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000407_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000407_16_1 + 7) & 127;
  }
  if ((sec_r000407_2_2 & 1) != 0)
  {
    if ((sec_r000407_21_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000407_16_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000407_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000407_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000407_11_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000407_0_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000407_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000407_0_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000407_11_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000407_0_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000407_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000407_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000407_2_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000407_7_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000407_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000407_7_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000407_2_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000407_7_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000407_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000407_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((sec_r000407_15_1 & 1) != 0)
  {
    if ((sec_r000407_16_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000407_4_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000407_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000407_4_1 + 7) & 127;
  }
  if ((sec_r000407_15_2 & 1) != 0)
  {
    if ((sec_r000407_16_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000407_4_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000407_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000407_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000407_11_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000407_8_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000407_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000407_8_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000407_11_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000407_8_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000407_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000407_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000407_14_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000407_2_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000407_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000407_2_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000407_14_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000407_2_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000407_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000407_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000407_6_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000407_0_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000407_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000407_0_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000407_6_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000407_0_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000407_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000407_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000407_21_1 & 1) != 0)
  {
    if ((sec_r000407_22_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000407_3_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000407_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000407_3_1 + 7) & 127;
  }
  if ((sec_r000407_21_2 & 1) != 0)
  {
    if ((sec_r000407_22_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000407_3_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000407_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000407_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((sec_r000407_17_1 & 1) != 0)
  {
    if ((sec_r000407_0_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000407_2_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000407_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000407_2_1 + 7) & 127;
  }
  if ((sec_r000407_17_2 & 1) != 0)
  {
    if ((sec_r000407_0_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000407_2_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000407_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000407_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000407_8_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000407_16_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000407_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000407_16_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000407_8_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000407_16_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000407_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000407_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000407_20_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000407_1_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000407_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000407_1_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000407_20_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000407_1_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000407_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000407_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((sec_r000407_19_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000407_15_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000407_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000407_15_1 + 7) & 127;
  }
  if ((stage_v_131_2 & 1) != 0)
  {
    if ((sec_r000407_19_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000407_15_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000407_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000407_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((sec_r000407_13_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000407_8_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000407_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000407_8_1 + 7) & 127;
  }
  if ((stage_v_129_2 & 1) != 0)
  {
    if ((sec_r000407_13_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000407_8_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000407_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000407_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000407_11_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000407_6_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000407_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000407_6_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000407_11_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000407_6_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000407_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000407_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000407_3_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000407_10_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000407_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000407_10_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000407_3_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000407_10_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000407_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000407_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000407_14_1 != sec_r000407_14_2);
  __CPROVER_assume(sec_r000407_19_1 != sec_r000407_19_2);
  __CPROVER_assume(pub_r000407_8_1 == pub_r000407_8_2);
  __CPROVER_assume(sec_r000407_20_1 != sec_r000407_20_2);
  __CPROVER_assume(sec_r000407_2_1 != sec_r000407_2_2);
  __CPROVER_assume(sec_r000407_1_1 != sec_r000407_1_2);
  __CPROVER_assume(sec_r000407_3_1 != sec_r000407_3_2);
  __CPROVER_assume(sec_r000407_18_1 != sec_r000407_18_2);
  __CPROVER_assume(pub_r000407_1_1 == pub_r000407_1_2);
  __CPROVER_assume(pub_r000407_16_1 == pub_r000407_16_2);
  __CPROVER_assume(sec_r000407_21_1 != sec_r000407_21_2);
  __CPROVER_assume(pub_r000407_0_1 == pub_r000407_0_2);
  __CPROVER_assume(pub_r000407_3_1 == pub_r000407_3_2);
  __CPROVER_assume(pub_r000407_4_1 == pub_r000407_4_2);
  __CPROVER_assume(pub_r000407_5_1 == pub_r000407_5_2);
  __CPROVER_assume(sec_r000407_5_1 != sec_r000407_5_2);
  __CPROVER_assume(sec_r000407_22_1 != sec_r000407_22_2);
  __CPROVER_assume(pub_r000407_11_1 == pub_r000407_11_2);
  __CPROVER_assume(sec_r000407_7_1 != sec_r000407_7_2);
  __CPROVER_assume(pub_r000407_13_1 == pub_r000407_13_2);
  __CPROVER_assume(sec_r000407_12_1 != sec_r000407_12_2);
  __CPROVER_assume(sec_r000407_13_1 != sec_r000407_13_2);
  __CPROVER_assume(pub_r000407_9_1 == pub_r000407_9_2);
  __CPROVER_assume(pub_r000407_14_1 == pub_r000407_14_2);
  __CPROVER_assume(sec_r000407_4_1 != sec_r000407_4_2);
  __CPROVER_assume(pub_r000407_10_1 == pub_r000407_10_2);
  __CPROVER_assume(sec_r000407_16_1 != sec_r000407_16_2);
  __CPROVER_assume(sec_r000407_15_1 != sec_r000407_15_2);
  __CPROVER_assume(sec_r000407_9_1 != sec_r000407_9_2);
  __CPROVER_assume(pub_r000407_6_1 == pub_r000407_6_2);
  __CPROVER_assume(sec_r000407_8_1 != sec_r000407_8_2);
  __CPROVER_assume(sec_r000407_0_1 != sec_r000407_0_2);
  __CPROVER_assume(pub_r000407_15_1 == pub_r000407_15_2);
  __CPROVER_assume(sec_r000407_11_1 != sec_r000407_11_2);
  __CPROVER_assume(pub_r000407_7_1 == pub_r000407_7_2);
  __CPROVER_assume(sec_r000407_17_1 != sec_r000407_17_2);
  __CPROVER_assume(sec_r000407_10_1 != sec_r000407_10_2);
  __CPROVER_assume(pub_r000407_12_1 == pub_r000407_12_2);
  __CPROVER_assume(sec_r000407_6_1 != sec_r000407_6_2);
  __CPROVER_assume(pub_r000407_2_1 == pub_r000407_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.balance == st_var_2_2.balance);
  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.envelope == st_var_3_2.envelope);
  assert(st_var_3_1.sample_rate == st_var_3_2.sample_rate);
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
}


