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
struct Transaction_R001942_4213_0
{
  short auth_code;
  int rate;
  unsigned char balance;
  short account_id;
  unsigned char fee;
  int status;
  int buffer[3];
};
struct AudioFrame_R001942_4213_1
{
  int rms;
  short channels;
  unsigned char peak;
  int sample_rate;
  unsigned char envelope;
  int buffer[3];
};
union ColorPixel_R001942_4213_0
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
void fn_R001942_4213_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001942_4213_0 st_1 = {0};
  struct Transaction_R001942_4213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int margin_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_54_1 > 45)
  {
    acc_1 = ((acc_1 + (margin_54_1 * 2)) + 5) & 127;
    aux_1 ^= margin_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_54_2 > 45)
  {
    acc_2 = ((acc_2 + (margin_54_2 * 2)) + 5) & 127;
    aux_2 ^= margin_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_38_1 = 0;
  int margin_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_38_1 = ((margin_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_38_2 = ((margin_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_38_1) & 127;
    acc_2 = (acc_2 + margin_38_2) & 127;
  }

  int quotient_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_38_1) & 63;
  aux_2 = (aux_2 + quotient_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_62_1)
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

  switch (scale_62_2)
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
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_54_1 == margin_54_2);
  assert(margin_38_1 == margin_38_2);
  assert(quotient_38_1 == quotient_38_2);
  assert(scale_62_1 == scale_62_2);
}

int fn_R001942_4213_0(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001942_4213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int margin_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_54 > 45)
  {
    acc = ((acc + (margin_54 * 2)) + 5) & 127;
    aux ^= margin_54 & 15;
  }
  else
  {
    acc = ((acc - margin_54) + 11) & 127;
    aux += 3;
  }
  int margin_38 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_38 = ((margin_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_38) & 127;
  }

  int quotient_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_38) & 63;
  acc ^= aux;
  int scale_62 = (aux + st.buffer[1]) & 3;
  switch (scale_62)
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

void fn_R001942_4213_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st_1 = {0};
  struct AudioFrame_R001942_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int segment_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_72_1) & 63;
  aux_2 = (aux_2 + segment_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_98_1)
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

  switch (threshold_98_2)
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

  int coefficient_58_1 = 0;
  int coefficient_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_58_1 = ((coefficient_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_58_2 = ((coefficient_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_58_1) & 127;
    acc_2 = (acc_2 + coefficient_58_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_72_1 == segment_72_2);
  assert(threshold_98_1 == threshold_98_2);
  assert(coefficient_58_1 == coefficient_58_2);
}

int fn_R001942_4213_1(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int segment_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_72) & 63;
  acc ^= aux;
  int threshold_98 = (aux + st.buffer[1]) & 3;
  switch (threshold_98)
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

  int coefficient_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_58 = ((coefficient_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_58) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001942_4213_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st_1 = {0};
  struct AudioFrame_R001942_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_93_1 = 0;
  int offset_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_93_1 = ((offset_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_93_2 = ((offset_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_93_1) & 127;
    acc_2 = (acc_2 + offset_93_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_87_1 = local_arr_1[aux_1 % 3];
  int residue_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_87_2 * 2)) & 127;
  int stride_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_63_1) & 63;
  aux_2 = (aux_2 + stride_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_93_1 == offset_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_87_1 == residue_87_2);
  assert(stride_63_1 == stride_63_2);
}

int fn_R001942_4213_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_93 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_93 = ((offset_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_93) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int residue_87 = local_arr[aux % 3];
  acc = (acc + (residue_87 * 2)) & 127;
  int stride_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_63) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001942_4213_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001942_4213_0 st_1 = {0};
  struct Transaction_R001942_4213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_24_1 > 42)
  {
    acc_1 = ((acc_1 + (cursor_24_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_24_2 > 42)
  {
    acc_2 = ((acc_2 + (cursor_24_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_74_1 = 0;
  int tally_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_74_1 = ((tally_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_74_2 = ((tally_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_74_1) & 127;
    acc_2 = (acc_2 + tally_74_2) & 127;
  }

  int coefficient_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_48_1) & 63;
  aux_2 = (aux_2 + coefficient_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_24_1 == cursor_24_2);
  assert(tally_74_1 == tally_74_2);
  assert(coefficient_48_1 == coefficient_48_2);
}

int fn_R001942_4213_3(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001942_4213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_24 > 42)
  {
    acc = ((acc + (cursor_24 * 2)) + 5) & 127;
    aux ^= cursor_24 & 15;
  }
  else
  {
    acc = ((acc - cursor_24) + 11) & 127;
    aux += 3;
  }
  int tally_74 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_74 = ((tally_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_74) & 127;
  }

  int coefficient_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001942_4213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st_1 = {0};
  struct AudioFrame_R001942_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int quotient_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_89_1 > 19)
  {
    acc_1 = ((acc_1 + (quotient_89_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_89_2 > 19)
  {
    acc_2 = ((acc_2 + (quotient_89_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_69_1)
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

  switch (anchor_69_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_89_1 == quotient_89_2);
  assert(anchor_69_1 == anchor_69_2);
}

int fn_R001942_4213_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int quotient_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_89 > 19)
  {
    acc = ((acc + (quotient_89 * 2)) + 5) & 127;
    aux ^= quotient_89 & 15;
  }
  else
  {
    acc = ((acc - quotient_89) + 11) & 127;
    aux += 3;
  }
  int anchor_69 = (aux + st.buffer[1]) & 3;
  switch (anchor_69)
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

void fn_R001942_4213_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st_1 = {0};
  struct AudioFrame_R001942_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int quantum_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_41_1)
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

  switch (quantum_41_2)
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

  int mask_25_1 = 0;
  int mask_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_25_1 = ((mask_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_25_2 = ((mask_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_25_1) & 127;
    acc_2 = (acc_2 + mask_25_2) & 127;
  }

  int vector_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_78_1) & 63;
  aux_2 = (aux_2 + vector_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_41_1 == quantum_41_2);
  assert(mask_25_1 == mask_25_2);
  assert(vector_78_1 == vector_78_2);
}

int fn_R001942_4213_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int quantum_41 = (aux + st.buffer[1]) & 3;
  switch (quantum_41)
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

  int mask_25 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_25 = ((mask_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_25) & 127;
  }

  int vector_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_78) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001942_4213_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st_1 = {0};
  struct AudioFrame_R001942_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_50_1 = local_arr_1[aux_1 % 3];
  int quotient_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_50_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_29_1 > 19)
  {
    acc_1 = ((acc_1 + (phase_29_1 * 2)) + 5) & 127;
    aux_1 ^= phase_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_29_2 > 19)
  {
    acc_2 = ((acc_2 + (phase_29_2 * 2)) + 5) & 127;
    aux_2 ^= phase_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_50_1 == quotient_50_2);
  assert(phase_29_1 == phase_29_2);
}

int fn_R001942_4213_6(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int quotient_50 = local_arr[aux % 3];
  acc = (acc + (quotient_50 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_29 > 19)
  {
    acc = ((acc + (phase_29 * 2)) + 5) & 127;
    aux ^= phase_29 & 15;
  }
  else
  {
    acc = ((acc - phase_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001942_4213_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st_1 = {0};
  struct AudioFrame_R001942_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int anchor_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_83_1) & 63;
  aux_2 = (aux_2 + anchor_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_26_1 = 0;
  int scale_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_26_1 = ((scale_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_26_2 = ((scale_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_26_1) & 127;
    acc_2 = (acc_2 + scale_26_2) & 127;
  }

  int parity_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_54_1 > 24)
  {
    acc_1 = ((acc_1 + (parity_54_1 * 2)) + 5) & 127;
    aux_1 ^= parity_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_54_2 > 24)
  {
    acc_2 = ((acc_2 + (parity_54_2 * 2)) + 5) & 127;
    aux_2 ^= parity_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_12_1 = local_arr_1[aux_1 % 3];
  int sample_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_83_1 == anchor_83_2);
  assert(scale_26_1 == scale_26_2);
  assert(parity_54_1 == parity_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_12_1 == sample_12_2);
}

int fn_R001942_4213_7(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int anchor_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_83) & 63;
  acc ^= aux;
  int scale_26 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_26 = ((scale_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_26) & 127;
  }

  int parity_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_54 > 24)
  {
    acc = ((acc + (parity_54 * 2)) + 5) & 127;
    aux ^= parity_54 & 15;
  }
  else
  {
    acc = ((acc - parity_54) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_12 = local_arr[aux % 3];
  acc = (acc + (sample_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001942_4213_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st_1 = {0};
  struct AudioFrame_R001942_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_28_1 = local_arr_1[aux_1 % 3];
  int tally_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_28_2 * 2)) & 127;
  int coefficient_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_24_1)
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

  switch (coefficient_24_2)
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

  int residue_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_96_1 > 46)
  {
    acc_1 = ((acc_1 + (residue_96_1 * 2)) + 5) & 127;
    aux_1 ^= residue_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_96_2 > 46)
  {
    acc_2 = ((acc_2 + (residue_96_2 * 2)) + 5) & 127;
    aux_2 ^= residue_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_96_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_28_1 == tally_28_2);
  assert(coefficient_24_1 == coefficient_24_2);
  assert(residue_96_1 == residue_96_2);
}

int fn_R001942_4213_8(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int tally_28 = local_arr[aux % 3];
  acc = (acc + (tally_28 * 2)) & 127;
  int coefficient_24 = (aux + st.buffer[1]) & 3;
  switch (coefficient_24)
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

  int residue_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_96 > 46)
  {
    acc = ((acc + (residue_96 * 2)) + 5) & 127;
    aux ^= residue_96 & 15;
  }
  else
  {
    acc = ((acc - residue_96) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001942_4213_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001942_4213_0 st_1 = {0};
  struct Transaction_R001942_4213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int segment_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_35_1) & 63;
  aux_2 = (aux_2 + segment_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_49_1)
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

  switch (mask_49_2)
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

  int accumulator_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_58_1 > 36)
  {
    acc_1 = ((acc_1 + (accumulator_58_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_58_2 > 36)
  {
    acc_2 = ((acc_2 + (accumulator_58_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_35_1 == segment_35_2);
  assert(mask_49_1 == mask_49_2);
  assert(accumulator_58_1 == accumulator_58_2);
}

int fn_R001942_4213_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001942_4213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int segment_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_35) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_49 = (aux + st.buffer[1]) & 3;
  switch (mask_49)
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

  int accumulator_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_58 > 36)
  {
    acc = ((acc + (accumulator_58 * 2)) + 5) & 127;
    aux ^= accumulator_58 & 15;
  }
  else
  {
    acc = ((acc - accumulator_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001942_4213_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001942_4213_0 st_1 = {0};
  struct Transaction_R001942_4213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int anchor_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_69_1)
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

  switch (anchor_69_2)
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
  int mask_40_1 = local_arr_1[aux_1 % 3];
  int mask_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_40_2 * 2)) & 127;
  int accumulator_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_26_1 > 22)
  {
    acc_1 = ((acc_1 + (accumulator_26_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_26_2 > 22)
  {
    acc_2 = ((acc_2 + (accumulator_26_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_86_1) & 63;
  aux_2 = (aux_2 + cursor_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_69_1 == anchor_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_40_1 == mask_40_2);
  assert(accumulator_26_1 == accumulator_26_2);
  assert(cursor_86_1 == cursor_86_2);
}

int fn_R001942_4213_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001942_4213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int anchor_69 = (aux + st.buffer[1]) & 3;
  switch (anchor_69)
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
  int mask_40 = local_arr[aux % 3];
  acc = (acc + (mask_40 * 2)) & 127;
  int accumulator_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_26 > 22)
  {
    acc = ((acc + (accumulator_26 * 2)) + 5) & 127;
    aux ^= accumulator_26 & 15;
  }
  else
  {
    acc = ((acc - accumulator_26) + 11) & 127;
    aux += 3;
  }
  int cursor_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001942_4213_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st_1 = {0};
  struct AudioFrame_R001942_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int checksum_12_1 = 0;
  int checksum_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_12_1 = ((checksum_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_12_2 = ((checksum_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_12_1) & 127;
    acc_2 = (acc_2 + checksum_12_2) & 127;
  }

  int mask_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_36_1)
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

  switch (mask_36_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_49_1 = local_arr_1[aux_1 % 3];
  int residue_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_49_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_12_1 == checksum_12_2);
  assert(mask_36_1 == mask_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_49_1 == residue_49_2);
}

int fn_R001942_4213_11(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int checksum_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_12 = ((checksum_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_12) & 127;
  }

  int mask_36 = (aux + st.buffer[1]) & 3;
  switch (mask_36)
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

  int local_arr[3] = {4, 9, 15};
  int residue_49 = local_arr[aux % 3];
  acc = (acc + (residue_49 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001942_4213_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st_1 = {0};
  struct AudioFrame_R001942_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_63_1 = local_arr_1[aux_1 % 3];
  int bound_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_63_2 * 2)) & 127;
  int checksum_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_65_1) & 63;
  aux_2 = (aux_2 + checksum_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_75_1)
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

  switch (cursor_75_2)
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

  int threshold_87_1 = 0;
  int threshold_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_87_1 = ((threshold_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_87_2 = ((threshold_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_87_1) & 127;
    acc_2 = (acc_2 + threshold_87_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_63_1 == bound_63_2);
  assert(checksum_65_1 == checksum_65_2);
  assert(cursor_75_1 == cursor_75_2);
  assert(threshold_87_1 == threshold_87_2);
}

int fn_R001942_4213_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int bound_63 = local_arr[aux % 3];
  acc = (acc + (bound_63 * 2)) & 127;
  int checksum_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_65) & 63;
  acc ^= aux;
  int cursor_75 = (aux + st.buffer[1]) & 3;
  switch (cursor_75)
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

  int threshold_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_87 = ((threshold_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_87) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001942_4213_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001942_4213_0 st_1 = {0};
  struct Transaction_R001942_4213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_51_1 = local_arr_1[aux_1 % 3];
  int anchor_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_51_1 == anchor_51_2);
}

int fn_R001942_4213_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001942_4213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_51 = local_arr[aux % 3];
  acc = (acc + (anchor_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001942_4213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st_1 = {0};
  struct AudioFrame_R001942_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int stride_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_36_1) & 63;
  aux_2 = (aux_2 + stride_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_36_1 == stride_36_2);
}

int fn_R001942_4213_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001942_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int stride_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_36) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001942_4213_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001942_4213_0 st_1 = {0};
  struct Transaction_R001942_4213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_10_1)
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

  switch (damping_10_2)
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
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_10_1 == damping_10_2);
}

int fn_R001942_4213_15(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001942_4213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_10 = (aux + st.buffer[1]) & 3;
  switch (damping_10)
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

void fn_R001942_4213_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001942_4213_0 st_1 = {0};
  struct Transaction_R001942_4213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_33_1 = local_arr_1[aux_1 % 3];
  int residue_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_33_2 * 2)) & 127;
  int vector_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_85_1 > 28)
  {
    acc_1 = ((acc_1 + (vector_85_1 * 2)) + 5) & 127;
    aux_1 ^= vector_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_85_2 > 28)
  {
    acc_2 = ((acc_2 + (vector_85_2 * 2)) + 5) & 127;
    aux_2 ^= vector_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_16_1 = 0;
  int metric_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_16_1 = ((metric_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_16_2 = ((metric_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_16_1) & 127;
    acc_2 = (acc_2 + metric_16_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_33_1 == residue_33_2);
  assert(vector_85_1 == vector_85_2);
  assert(metric_16_1 == metric_16_2);
}

int fn_R001942_4213_16(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001942_4213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int residue_33 = local_arr[aux % 3];
  acc = (acc + (residue_33 * 2)) & 127;
  int vector_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_85 > 28)
  {
    acc = ((acc + (vector_85 * 2)) + 5) & 127;
    aux ^= vector_85 & 15;
  }
  else
  {
    acc = ((acc - vector_85) + 11) & 127;
    aux += 3;
  }
  int metric_16 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_16 = ((metric_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_16) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001942_0_1;
  int sec_r001942_0_2;
  int sec_r001942_1_1;
  int sec_r001942_1_2;
  int sec_r001942_2_1;
  int sec_r001942_2_2;
  int sec_r001942_3_1;
  int sec_r001942_3_2;
  int sec_r001942_4_1;
  int sec_r001942_4_2;
  int sec_r001942_5_1;
  int sec_r001942_5_2;
  int sec_r001942_6_1;
  int sec_r001942_6_2;
  int sec_r001942_7_1;
  int sec_r001942_7_2;
  int sec_r001942_8_1;
  int sec_r001942_8_2;
  int sec_r001942_9_1;
  int sec_r001942_9_2;
  int sec_r001942_10_1;
  int sec_r001942_10_2;
  int sec_r001942_11_1;
  int sec_r001942_11_2;
  int sec_r001942_12_1;
  int sec_r001942_12_2;
  int sec_r001942_13_1;
  int sec_r001942_13_2;
  int sec_r001942_14_1;
  int sec_r001942_14_2;
  int sec_r001942_15_1;
  int sec_r001942_15_2;
  int sec_r001942_16_1;
  int sec_r001942_16_2;
  int sec_r001942_17_1;
  int sec_r001942_17_2;
  int sec_r001942_18_1;
  int sec_r001942_18_2;
  int sec_r001942_19_1;
  int sec_r001942_19_2;
  int sec_r001942_20_1;
  int sec_r001942_20_2;
  int pub_r001942_0_1;
  int pub_r001942_0_2;
  int pub_r001942_1_1;
  int pub_r001942_1_2;
  int pub_r001942_2_1;
  int pub_r001942_2_2;
  int pub_r001942_3_1;
  int pub_r001942_3_2;
  int pub_r001942_4_1;
  int pub_r001942_4_2;
  int pub_r001942_5_1;
  int pub_r001942_5_2;
  int pub_r001942_6_1;
  int pub_r001942_6_2;
  int pub_r001942_7_1;
  int pub_r001942_7_2;
  int pub_r001942_8_1;
  int pub_r001942_8_2;
  int pub_r001942_9_1;
  int pub_r001942_9_2;
  int pub_r001942_10_1;
  int pub_r001942_10_2;
  int pub_r001942_11_1;
  int pub_r001942_11_2;
  int pub_r001942_12_1;
  int pub_r001942_12_2;
  int pub_r001942_13_1;
  int pub_r001942_13_2;
  int pub_r001942_14_1;
  int pub_r001942_14_2;
  int pub_r001942_15_1;
  int pub_r001942_15_2;
  int pub_r001942_16_1;
  int pub_r001942_16_2;
  int pub_r001942_17_1;
  int pub_r001942_17_2;
  int pub_r001942_18_1;
  int pub_r001942_18_2;
  int pub_r001942_19_1;
  int pub_r001942_19_2;
  int pub_r001942_20_1;
  int pub_r001942_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001942_0_1 >= (-100)) && (pub_r001942_0_1 <= 100));
  __CPROVER_assume((pub_r001942_0_2 >= (-100)) && (pub_r001942_0_2 <= 100));
  __CPROVER_assume((pub_r001942_1_1 >= (-100)) && (pub_r001942_1_1 <= 100));
  __CPROVER_assume((pub_r001942_1_2 >= (-100)) && (pub_r001942_1_2 <= 100));
  __CPROVER_assume((pub_r001942_2_1 >= (-100)) && (pub_r001942_2_1 <= 100));
  __CPROVER_assume((pub_r001942_2_2 >= (-100)) && (pub_r001942_2_2 <= 100));
  __CPROVER_assume((pub_r001942_3_1 >= (-100)) && (pub_r001942_3_1 <= 100));
  __CPROVER_assume((pub_r001942_3_2 >= (-100)) && (pub_r001942_3_2 <= 100));
  __CPROVER_assume((pub_r001942_4_1 >= (-100)) && (pub_r001942_4_1 <= 100));
  __CPROVER_assume((pub_r001942_4_2 >= (-100)) && (pub_r001942_4_2 <= 100));
  __CPROVER_assume((pub_r001942_5_1 >= (-100)) && (pub_r001942_5_1 <= 100));
  __CPROVER_assume((pub_r001942_5_2 >= (-100)) && (pub_r001942_5_2 <= 100));
  __CPROVER_assume((pub_r001942_6_1 >= (-100)) && (pub_r001942_6_1 <= 100));
  __CPROVER_assume((pub_r001942_6_2 >= (-100)) && (pub_r001942_6_2 <= 100));
  __CPROVER_assume((pub_r001942_7_1 >= (-100)) && (pub_r001942_7_1 <= 100));
  __CPROVER_assume((pub_r001942_7_2 >= (-100)) && (pub_r001942_7_2 <= 100));
  __CPROVER_assume((pub_r001942_8_1 >= (-100)) && (pub_r001942_8_1 <= 100));
  __CPROVER_assume((pub_r001942_8_2 >= (-100)) && (pub_r001942_8_2 <= 100));
  __CPROVER_assume((pub_r001942_9_1 >= (-100)) && (pub_r001942_9_1 <= 100));
  __CPROVER_assume((pub_r001942_9_2 >= (-100)) && (pub_r001942_9_2 <= 100));
  __CPROVER_assume((pub_r001942_10_1 >= (-100)) && (pub_r001942_10_1 <= 100));
  __CPROVER_assume((pub_r001942_10_2 >= (-100)) && (pub_r001942_10_2 <= 100));
  __CPROVER_assume((pub_r001942_11_1 >= (-100)) && (pub_r001942_11_1 <= 100));
  __CPROVER_assume((pub_r001942_11_2 >= (-100)) && (pub_r001942_11_2 <= 100));
  __CPROVER_assume((pub_r001942_12_1 >= (-100)) && (pub_r001942_12_1 <= 100));
  __CPROVER_assume((pub_r001942_12_2 >= (-100)) && (pub_r001942_12_2 <= 100));
  __CPROVER_assume((pub_r001942_13_1 >= (-100)) && (pub_r001942_13_1 <= 100));
  __CPROVER_assume((pub_r001942_13_2 >= (-100)) && (pub_r001942_13_2 <= 100));
  __CPROVER_assume((pub_r001942_14_1 >= (-100)) && (pub_r001942_14_1 <= 100));
  __CPROVER_assume((pub_r001942_14_2 >= (-100)) && (pub_r001942_14_2 <= 100));
  __CPROVER_assume((pub_r001942_15_1 >= (-100)) && (pub_r001942_15_1 <= 100));
  __CPROVER_assume((pub_r001942_15_2 >= (-100)) && (pub_r001942_15_2 <= 100));
  __CPROVER_assume((pub_r001942_16_1 >= (-100)) && (pub_r001942_16_1 <= 100));
  __CPROVER_assume((pub_r001942_16_2 >= (-100)) && (pub_r001942_16_2 <= 100));
  __CPROVER_assume((pub_r001942_17_1 >= (-100)) && (pub_r001942_17_1 <= 100));
  __CPROVER_assume((pub_r001942_17_2 >= (-100)) && (pub_r001942_17_2 <= 100));
  __CPROVER_assume((pub_r001942_18_1 >= (-100)) && (pub_r001942_18_1 <= 100));
  __CPROVER_assume((pub_r001942_18_2 >= (-100)) && (pub_r001942_18_2 <= 100));
  __CPROVER_assume((pub_r001942_19_1 >= (-100)) && (pub_r001942_19_1 <= 100));
  __CPROVER_assume((pub_r001942_19_2 >= (-100)) && (pub_r001942_19_2 <= 100));
  __CPROVER_assume((pub_r001942_20_1 >= (-100)) && (pub_r001942_20_1 <= 100));
  __CPROVER_assume((pub_r001942_20_2 >= (-100)) && (pub_r001942_20_2 <= 100));
  __CPROVER_assume((sec_r001942_0_1 >= 0) && (sec_r001942_0_1 <= 255));
  __CPROVER_assume((sec_r001942_0_2 >= 0) && (sec_r001942_0_2 <= 255));
  __CPROVER_assume((sec_r001942_1_1 >= 0) && (sec_r001942_1_1 <= 255));
  __CPROVER_assume((sec_r001942_1_2 >= 0) && (sec_r001942_1_2 <= 255));
  __CPROVER_assume((sec_r001942_2_1 >= 0) && (sec_r001942_2_1 <= 255));
  __CPROVER_assume((sec_r001942_2_2 >= 0) && (sec_r001942_2_2 <= 255));
  __CPROVER_assume((sec_r001942_3_1 >= 0) && (sec_r001942_3_1 <= 255));
  __CPROVER_assume((sec_r001942_3_2 >= 0) && (sec_r001942_3_2 <= 255));
  __CPROVER_assume((sec_r001942_4_1 >= 0) && (sec_r001942_4_1 <= 255));
  __CPROVER_assume((sec_r001942_4_2 >= 0) && (sec_r001942_4_2 <= 255));
  __CPROVER_assume((sec_r001942_5_1 >= 0) && (sec_r001942_5_1 <= 255));
  __CPROVER_assume((sec_r001942_5_2 >= 0) && (sec_r001942_5_2 <= 255));
  __CPROVER_assume((sec_r001942_6_1 >= 0) && (sec_r001942_6_1 <= 255));
  __CPROVER_assume((sec_r001942_6_2 >= 0) && (sec_r001942_6_2 <= 255));
  __CPROVER_assume((sec_r001942_7_1 >= 0) && (sec_r001942_7_1 <= 255));
  __CPROVER_assume((sec_r001942_7_2 >= 0) && (sec_r001942_7_2 <= 255));
  __CPROVER_assume((sec_r001942_8_1 >= 0) && (sec_r001942_8_1 <= 255));
  __CPROVER_assume((sec_r001942_8_2 >= 0) && (sec_r001942_8_2 <= 255));
  __CPROVER_assume((sec_r001942_9_1 >= 0) && (sec_r001942_9_1 <= 255));
  __CPROVER_assume((sec_r001942_9_2 >= 0) && (sec_r001942_9_2 <= 255));
  __CPROVER_assume((sec_r001942_10_1 >= 0) && (sec_r001942_10_1 <= 255));
  __CPROVER_assume((sec_r001942_10_2 >= 0) && (sec_r001942_10_2 <= 255));
  __CPROVER_assume((sec_r001942_11_1 >= 0) && (sec_r001942_11_1 <= 255));
  __CPROVER_assume((sec_r001942_11_2 >= 0) && (sec_r001942_11_2 <= 255));
  __CPROVER_assume((sec_r001942_12_1 >= 0) && (sec_r001942_12_1 <= 255));
  __CPROVER_assume((sec_r001942_12_2 >= 0) && (sec_r001942_12_2 <= 255));
  __CPROVER_assume((sec_r001942_13_1 >= 0) && (sec_r001942_13_1 <= 255));
  __CPROVER_assume((sec_r001942_13_2 >= 0) && (sec_r001942_13_2 <= 255));
  __CPROVER_assume((sec_r001942_14_1 >= 0) && (sec_r001942_14_1 <= 255));
  __CPROVER_assume((sec_r001942_14_2 >= 0) && (sec_r001942_14_2 <= 255));
  __CPROVER_assume((sec_r001942_15_1 >= 0) && (sec_r001942_15_1 <= 255));
  __CPROVER_assume((sec_r001942_15_2 >= 0) && (sec_r001942_15_2 <= 255));
  __CPROVER_assume((sec_r001942_16_1 >= 0) && (sec_r001942_16_1 <= 255));
  __CPROVER_assume((sec_r001942_16_2 >= 0) && (sec_r001942_16_2 <= 255));
  __CPROVER_assume((sec_r001942_17_1 >= 0) && (sec_r001942_17_1 <= 255));
  __CPROVER_assume((sec_r001942_17_2 >= 0) && (sec_r001942_17_2 <= 255));
  __CPROVER_assume((sec_r001942_18_1 >= 0) && (sec_r001942_18_1 <= 255));
  __CPROVER_assume((sec_r001942_18_2 >= 0) && (sec_r001942_18_2 <= 255));
  __CPROVER_assume((sec_r001942_19_1 >= 0) && (sec_r001942_19_1 <= 255));
  __CPROVER_assume((sec_r001942_19_2 >= 0) && (sec_r001942_19_2 <= 255));
  __CPROVER_assume((sec_r001942_20_1 >= 0) && (sec_r001942_20_1 <= 255));
  __CPROVER_assume((sec_r001942_20_2 >= 0) && (sec_r001942_20_2 <= 255));
  struct Transaction_R001942_4213_0 st_var_0_1 = {0};
  struct Transaction_R001942_4213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001942_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001942_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001942_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001942_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001942_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001942_0_2 + 7) & 15;
  struct AudioFrame_R001942_4213_1 st_var_1_1 = {0};
  struct AudioFrame_R001942_4213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001942_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001942_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001942_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001942_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001942_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001942_0_2 + 9) & 15;
  union ColorPixel_R001942_4213_0 u_var_1;
  union ColorPixel_R001942_4213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001942_4213_0(sec_r001942_0_1, sec_r001942_1_1, pub_r001942_2_1);
  int helper_flow_0_2 = fn_R001942_4213_0(sec_r001942_0_2, sec_r001942_1_2, pub_r001942_2_2);
  fn_R001942_4213_0_2(sec_r001942_0_1, sec_r001942_1_1, pub_r001942_2_1, sec_r001942_0_2, sec_r001942_1_2, pub_r001942_2_2);
  int helper_flow_1_1 = fn_R001942_4213_1(sec_r001942_1_1, pub_r001942_2_1, pub_r001942_3_1);
  int helper_flow_1_2 = fn_R001942_4213_1(sec_r001942_1_2, pub_r001942_2_2, pub_r001942_3_2);
  fn_R001942_4213_1_2(sec_r001942_1_1, pub_r001942_2_1, pub_r001942_3_1, sec_r001942_1_2, pub_r001942_2_2, pub_r001942_3_2);
  int helper_flow_2_1 = fn_R001942_4213_2(sec_r001942_2_1, sec_r001942_3_1, pub_r001942_4_1, pub_r001942_5_1);
  int helper_flow_2_2 = fn_R001942_4213_2(sec_r001942_2_2, sec_r001942_3_2, pub_r001942_4_2, pub_r001942_5_2);
  fn_R001942_4213_2_2(sec_r001942_2_1, sec_r001942_3_1, pub_r001942_4_1, pub_r001942_5_1, sec_r001942_2_2, sec_r001942_3_2, pub_r001942_4_2, pub_r001942_5_2);
  int helper_flow_3_1 = fn_R001942_4213_3(sec_r001942_3_1, sec_r001942_4_1, pub_r001942_5_1);
  int helper_flow_3_2 = fn_R001942_4213_3(sec_r001942_3_2, sec_r001942_4_2, pub_r001942_5_2);
  fn_R001942_4213_3_2(sec_r001942_3_1, sec_r001942_4_1, pub_r001942_5_1, sec_r001942_3_2, sec_r001942_4_2, pub_r001942_5_2);
  int helper_flow_4_1 = fn_R001942_4213_4(sec_r001942_4_1, pub_r001942_5_1, pub_r001942_6_1, pub_r001942_7_1);
  int helper_flow_4_2 = fn_R001942_4213_4(sec_r001942_4_2, pub_r001942_5_2, pub_r001942_6_2, pub_r001942_7_2);
  fn_R001942_4213_4_2(sec_r001942_4_1, pub_r001942_5_1, pub_r001942_6_1, pub_r001942_7_1, sec_r001942_4_2, pub_r001942_5_2, pub_r001942_6_2, pub_r001942_7_2);
  int helper_flow_5_1 = fn_R001942_4213_5(sec_r001942_5_1, sec_r001942_6_1, pub_r001942_7_1, pub_r001942_8_1, pub_r001942_9_1);
  int helper_flow_5_2 = fn_R001942_4213_5(sec_r001942_5_2, sec_r001942_6_2, pub_r001942_7_2, pub_r001942_8_2, pub_r001942_9_2);
  fn_R001942_4213_5_2(sec_r001942_5_1, sec_r001942_6_1, pub_r001942_7_1, pub_r001942_8_1, pub_r001942_9_1, sec_r001942_5_2, sec_r001942_6_2, pub_r001942_7_2, pub_r001942_8_2, pub_r001942_9_2);
  int stage_v_0_1 = ((pub_r001942_17_1 * 2) + 13) & 63;
  int stage_v_0_2 = ((pub_r001942_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001942_20_1 * 2) + 31) & 63;
  int stage_v_1_2 = ((pub_r001942_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001942_20_1 * 3) + pub_r001942_19_1) + 36) & 127;
  int stage_v_2_2 = (((sec_r001942_20_2 * 3) + pub_r001942_19_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = ((pub_r001942_16_1 * 2) + 41) & 63;
  int stage_v_3_2 = ((pub_r001942_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((sec_r001942_4_1 * 3) + pub_r001942_19_1) + 17) & 127;
  int stage_v_4_2 = (((sec_r001942_4_2 * 3) + pub_r001942_19_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001942_12_1 * 2) + 20) & 63;
  int stage_v_5_2 = ((pub_r001942_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001942_2_1 * 2) + 36) & 63;
  int stage_v_6_2 = ((pub_r001942_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001942_6_1 * 2) + 15) & 63;
  int stage_v_7_2 = ((pub_r001942_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001942_3_1 * 2) + 48) & 63;
  int stage_v_8_2 = ((pub_r001942_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001942_14_1 * 2) + 6) & 63;
  int stage_v_9_2 = ((pub_r001942_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001942_10_1 * 2) + 23) & 63;
  int stage_v_10_2 = ((pub_r001942_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001942_19_1 * 2) + 15) & 63;
  int stage_v_11_2 = ((pub_r001942_19_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001942_3_1 * 2) + 19) & 63;
  int stage_v_12_2 = ((pub_r001942_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001942_9_1 * 2) + 6) & 63;
  int stage_v_13_2 = ((pub_r001942_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001942_7_1 * 2) + 12) & 63;
  int stage_v_14_2 = ((pub_r001942_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001942_15_1 * 2) + 36) & 63;
  int stage_v_15_2 = ((pub_r001942_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((sec_r001942_10_1 * 3) + pub_r001942_4_1) + 6) & 127;
  int stage_v_16_2 = (((sec_r001942_10_2 * 3) + pub_r001942_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = (((sec_r001942_2_1 * 3) + pub_r001942_0_1) + 38) & 127;
  int stage_v_17_2 = (((sec_r001942_2_2 * 3) + pub_r001942_0_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = (((sec_r001942_3_1 * 3) + pub_r001942_19_1) + 42) & 127;
  int stage_v_18_2 = (((sec_r001942_3_2 * 3) + pub_r001942_19_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = ((pub_r001942_2_1 * 2) + 44) & 63;
  int stage_v_19_2 = ((pub_r001942_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (((sec_r001942_3_1 * 3) + pub_r001942_20_1) + 35) & 127;
  int stage_v_20_2 = (((sec_r001942_3_2 * 3) + pub_r001942_20_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = ((pub_r001942_17_1 * 2) + 45) & 63;
  int stage_v_21_2 = ((pub_r001942_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((sec_r001942_17_1 * 3) + pub_r001942_18_1) + 12) & 127;
  int stage_v_22_2 = (((sec_r001942_17_2 * 3) + pub_r001942_18_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = ((pub_r001942_3_1 * 2) + 32) & 63;
  int stage_v_23_2 = ((pub_r001942_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (((sec_r001942_9_1 * 3) + pub_r001942_3_1) + 36) & 127;
  int stage_v_24_2 = (((sec_r001942_9_2 * 3) + pub_r001942_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = ((pub_r001942_17_1 * 2) + 26) & 63;
  int stage_v_25_2 = ((pub_r001942_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001942_1_1 * 2) + 42) & 63;
  int stage_v_26_2 = ((pub_r001942_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001942_10_1 * 2) + 27) & 63;
  int stage_v_27_2 = ((pub_r001942_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001942_17_1 * 2) + 41) & 63;
  int stage_v_28_2 = ((pub_r001942_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001942_11_1 * 2) + 39) & 63;
  int stage_v_29_2 = ((pub_r001942_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((sec_r001942_2_1 * 3) + pub_r001942_16_1) + 41) & 127;
  int stage_v_30_2 = (((sec_r001942_2_2 * 3) + pub_r001942_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = ((pub_r001942_17_1 * 2) + 41) & 63;
  int stage_v_31_2 = ((pub_r001942_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001942_13_1 * 2) + 31) & 63;
  int stage_v_32_2 = ((pub_r001942_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001942_8_1 * 2) + 7) & 63;
  int stage_v_33_2 = ((pub_r001942_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001942_2_1 * 2) + 30) & 63;
  int stage_v_34_2 = ((pub_r001942_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001942_9_1 * 2) + 41) & 63;
  int stage_v_35_2 = ((pub_r001942_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001942_15_1 * 2) + 38) & 63;
  int stage_v_36_2 = ((pub_r001942_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001942_7_1 * 2) + 8) & 63;
  int stage_v_37_2 = ((pub_r001942_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((helper_flow_2_1 * 3) + pub_r001942_4_1) + 23) & 127;
  int stage_v_38_2 = (((helper_flow_2_2 * 3) + pub_r001942_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = ((pub_r001942_0_1 * 2) + 25) & 63;
  int stage_v_39_2 = ((pub_r001942_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001942_4_1 * 2) + 21) & 63;
  int stage_v_40_2 = ((pub_r001942_4_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((sec_r001942_3_1 * 3) + pub_r001942_3_1) + 39) & 127;
  int stage_v_41_2 = (((sec_r001942_3_2 * 3) + pub_r001942_3_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = ((pub_r001942_9_1 * 2) + 23) & 63;
  int stage_v_42_2 = ((pub_r001942_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((stage_v_38_1 * 3) + pub_r001942_20_1) + 27) & 127;
  int stage_v_43_2 = (((stage_v_38_2 * 3) + pub_r001942_20_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = ((pub_r001942_15_1 * 2) + 17) & 63;
  int stage_v_44_2 = ((pub_r001942_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001942_6_1 * 2) + 8) & 63;
  int stage_v_45_2 = ((pub_r001942_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001942_4_1 * 2) + 20) & 63;
  int stage_v_46_2 = ((pub_r001942_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001942_1_1 * 2) + 48) & 63;
  int stage_v_47_2 = ((pub_r001942_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001942_10_1 * 2) + 20) & 63;
  int stage_v_48_2 = ((pub_r001942_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001942_1_1 * 2) + 27) & 63;
  int stage_v_49_2 = ((pub_r001942_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001942_3_1 * 2) + 29) & 63;
  int stage_v_50_2 = ((pub_r001942_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((helper_flow_1_1 * 3) + pub_r001942_12_1) + 7) & 127;
  int stage_v_51_2 = (((helper_flow_1_2 * 3) + pub_r001942_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = ((pub_r001942_17_1 * 2) + 13) & 63;
  int stage_v_52_2 = ((pub_r001942_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((sec_r001942_4_1 * 3) + pub_r001942_6_1) + 45) & 127;
  int stage_v_53_2 = (((sec_r001942_4_2 * 3) + pub_r001942_6_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = (((helper_flow_1_1 * 3) + pub_r001942_11_1) + 40) & 127;
  int stage_v_54_2 = (((helper_flow_1_2 * 3) + pub_r001942_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = ((pub_r001942_10_1 * 2) + 37) & 63;
  int stage_v_55_2 = ((pub_r001942_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001942_12_1 * 2) + 6) & 63;
  int stage_v_56_2 = ((pub_r001942_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (((stage_v_18_1 * 3) + pub_r001942_14_1) + 5) & 127;
  int stage_v_57_2 = (((stage_v_18_2 * 3) + pub_r001942_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = ((pub_r001942_1_1 * 2) + 36) & 63;
  int stage_v_58_2 = ((pub_r001942_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001942_5_1 * 2) + 12) & 63;
  int stage_v_59_2 = ((pub_r001942_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((helper_flow_5_1 * 3) + pub_r001942_19_1) + 32) & 127;
  int stage_v_60_2 = (((helper_flow_5_2 * 3) + pub_r001942_19_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((sec_r001942_3_1 * 3) + pub_r001942_14_1) + 25) & 127;
  int stage_v_61_2 = (((sec_r001942_3_2 * 3) + pub_r001942_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001942_3_1 * 2) + 36) & 63;
  int stage_v_62_2 = ((pub_r001942_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((sec_r001942_20_1 * 3) + pub_r001942_10_1) + 27) & 127;
  int stage_v_63_2 = (((sec_r001942_20_2 * 3) + pub_r001942_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((helper_flow_0_1 * 3) + pub_r001942_11_1) + 24) & 127;
  int stage_v_64_2 = (((helper_flow_0_2 * 3) + pub_r001942_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = ((pub_r001942_17_1 * 2) + 48) & 63;
  int stage_v_65_2 = ((pub_r001942_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001942_10_1 * 2) + 19) & 63;
  int stage_v_66_2 = ((pub_r001942_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001942_3_1 * 2) + 23) & 63;
  int stage_v_67_2 = ((pub_r001942_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001942_7_1 * 2) + 46) & 63;
  int stage_v_68_2 = ((pub_r001942_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = (((stage_v_53_1 * 3) + pub_r001942_15_1) + 34) & 127;
  int stage_v_69_2 = (((stage_v_53_2 * 3) + pub_r001942_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = ((pub_r001942_5_1 * 2) + 31) & 63;
  int stage_v_70_2 = ((pub_r001942_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001942_19_1 * 2) + 41) & 63;
  int stage_v_71_2 = ((pub_r001942_19_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((stage_v_51_1 * 3) + pub_r001942_5_1) + 17) & 127;
  int stage_v_72_2 = (((stage_v_51_2 * 3) + pub_r001942_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = ((pub_r001942_8_1 * 2) + 39) & 63;
  int stage_v_73_2 = ((pub_r001942_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001942_10_1 * 2) + 48) & 63;
  int stage_v_74_2 = ((pub_r001942_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001942_18_1 * 2) + 47) & 63;
  int stage_v_75_2 = ((pub_r001942_18_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = (((sec_r001942_10_1 * 3) + pub_r001942_9_1) + 6) & 127;
  int stage_v_76_2 = (((sec_r001942_10_2 * 3) + pub_r001942_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = ((pub_r001942_12_1 * 2) + 44) & 63;
  int stage_v_77_2 = ((pub_r001942_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001942_2_1 * 2) + 19) & 63;
  int stage_v_78_2 = ((pub_r001942_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001942_8_1 * 2) + 33) & 63;
  int stage_v_79_2 = ((pub_r001942_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001942_17_1 * 2) + 21) & 63;
  int stage_v_80_2 = ((pub_r001942_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((stage_v_63_1 * 3) + pub_r001942_1_1) + 31) & 127;
  int stage_v_81_2 = (((stage_v_63_2 * 3) + pub_r001942_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = ((pub_r001942_9_1 * 2) + 24) & 63;
  int stage_v_82_2 = ((pub_r001942_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001942_7_1 * 2) + 9) & 63;
  int stage_v_83_2 = ((pub_r001942_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((stage_v_24_1 * 3) + pub_r001942_13_1) + 32) & 127;
  int stage_v_84_2 = (((stage_v_24_2 * 3) + pub_r001942_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = (((sec_r001942_9_1 * 3) + pub_r001942_16_1) + 10) & 127;
  int stage_v_85_2 = (((sec_r001942_9_2 * 3) + pub_r001942_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = ((pub_r001942_7_1 * 2) + 46) & 63;
  int stage_v_86_2 = ((pub_r001942_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_22_1 * 3) + pub_r001942_15_1) + 8) & 127;
  int stage_v_87_2 = (((stage_v_22_2 * 3) + pub_r001942_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = ((pub_r001942_9_1 * 2) + 17) & 63;
  int stage_v_88_2 = ((pub_r001942_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001942_3_1 * 2) + 48) & 63;
  int stage_v_89_2 = ((pub_r001942_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001942_18_1 * 2) + 6) & 63;
  int stage_v_90_2 = ((pub_r001942_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001942_10_1 * 2) + 13) & 63;
  int stage_v_91_2 = ((pub_r001942_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001942_18_1 * 2) + 26) & 63;
  int stage_v_92_2 = ((pub_r001942_18_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (((stage_v_61_1 * 3) + pub_r001942_13_1) + 5) & 127;
  int stage_v_93_2 = (((stage_v_61_2 * 3) + pub_r001942_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = ((pub_r001942_11_1 * 2) + 20) & 63;
  int stage_v_94_2 = ((pub_r001942_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001942_18_1 * 2) + 13) & 63;
  int stage_v_95_2 = ((pub_r001942_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((stage_v_20_1 * 3) + pub_r001942_2_1) + 43) & 127;
  int stage_v_96_2 = (((stage_v_20_2 * 3) + pub_r001942_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = ((pub_r001942_7_1 * 2) + 42) & 63;
  int stage_v_97_2 = ((pub_r001942_7_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_4_1 * 3) + pub_r001942_4_1) + 29) & 127;
  int stage_v_98_2 = (((stage_v_4_2 * 3) + pub_r001942_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = ((pub_r001942_6_1 * 2) + 12) & 63;
  int stage_v_99_2 = ((pub_r001942_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001942_4_1 * 2) + 41) & 63;
  int stage_v_100_2 = ((pub_r001942_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_20_1 * 3) + pub_r001942_5_1) + 13) & 127;
  int stage_v_101_2 = (((stage_v_20_2 * 3) + pub_r001942_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001942_6_1 * 2) + 8) & 63;
  int stage_v_102_2 = ((pub_r001942_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001942_18_1 * 2) + 49) & 63;
  int stage_v_103_2 = ((pub_r001942_18_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((stage_v_87_1 * 3) + pub_r001942_16_1) + 30) & 127;
  int stage_v_104_2 = (((stage_v_87_2 * 3) + pub_r001942_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = (((stage_v_53_1 * 3) + pub_r001942_2_1) + 24) & 127;
  int stage_v_105_2 = (((stage_v_53_2 * 3) + pub_r001942_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = (((stage_v_60_1 * 3) + pub_r001942_4_1) + 33) & 127;
  int stage_v_106_2 = (((stage_v_60_2 * 3) + pub_r001942_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = (((stage_v_17_1 * 3) + pub_r001942_12_1) + 25) & 127;
  int stage_v_107_2 = (((stage_v_17_2 * 3) + pub_r001942_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = ((pub_r001942_11_1 * 2) + 38) & 63;
  int stage_v_108_2 = ((pub_r001942_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((sec_r001942_1_1 * 3) + pub_r001942_7_1) + 19) & 127;
  int stage_v_109_2 = (((sec_r001942_1_2 * 3) + pub_r001942_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = ((pub_r001942_9_1 * 2) + 21) & 63;
  int stage_v_110_2 = ((pub_r001942_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001942_15_1 * 2) + 11) & 63;
  int stage_v_111_2 = ((pub_r001942_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001942_3_1 * 2) + 15) & 63;
  int stage_v_112_2 = ((pub_r001942_3_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001942_13_1 * 2) + 10) & 63;
  int stage_v_113_2 = ((pub_r001942_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001942_13_1 * 2) + 42) & 63;
  int stage_v_114_2 = ((pub_r001942_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = (((stage_v_4_1 * 3) + pub_r001942_14_1) + 45) & 127;
  int stage_v_115_2 = (((stage_v_4_2 * 3) + pub_r001942_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = (((stage_v_72_1 * 3) + pub_r001942_9_1) + 25) & 127;
  int stage_v_116_2 = (((stage_v_72_2 * 3) + pub_r001942_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = (((stage_v_84_1 * 3) + pub_r001942_7_1) + 44) & 127;
  int stage_v_117_2 = (((stage_v_84_2 * 3) + pub_r001942_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = ((pub_r001942_20_1 * 2) + 31) & 63;
  int stage_v_118_2 = ((pub_r001942_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001942_1_1 * 2) + 7) & 63;
  int stage_v_119_2 = ((pub_r001942_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001942_19_1 * 2) + 50) & 63;
  int stage_v_120_2 = ((pub_r001942_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001942_20_1 * 2) + 46) & 63;
  int stage_v_121_2 = ((pub_r001942_20_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((stage_v_116_1 * 3) + pub_r001942_8_1) + 44) & 127;
  int stage_v_122_2 = (((stage_v_116_2 * 3) + pub_r001942_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = ((pub_r001942_0_1 * 2) + 8) & 63;
  int stage_v_123_2 = ((pub_r001942_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((stage_v_104_1 * 3) + pub_r001942_3_1) + 32) & 127;
  int stage_v_124_2 = (((stage_v_104_2 * 3) + pub_r001942_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = ((pub_r001942_12_1 * 2) + 37) & 63;
  int stage_v_125_2 = ((pub_r001942_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001942_9_1 * 2) + 48) & 63;
  int stage_v_126_2 = ((pub_r001942_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001942_0_1 * 2) + 31) & 63;
  int stage_v_127_2 = ((pub_r001942_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001942_18_1 * 2) + 11) & 63;
  int stage_v_128_2 = ((pub_r001942_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001942_14_1 * 2) + 29) & 63;
  int stage_v_129_2 = ((pub_r001942_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001942_12_1 * 2) + 18) & 63;
  int stage_v_130_2 = ((pub_r001942_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001942_2_1 * 2) + 31) & 63;
  int stage_v_131_2 = ((pub_r001942_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((sec_r001942_11_1 * 3) + pub_r001942_20_1) + 26) & 127;
  int stage_v_132_2 = (((sec_r001942_11_2 * 3) + pub_r001942_20_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = ((pub_r001942_18_1 * 2) + 17) & 63;
  int stage_v_133_2 = ((pub_r001942_18_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001942_8_1 * 2) + 31) & 63;
  int stage_v_134_2 = ((pub_r001942_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001942_7_1 * 2) + 17) & 63;
  int stage_v_135_2 = ((pub_r001942_7_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001942_1_1 * 2) + 42) & 63;
  int stage_v_136_2 = ((pub_r001942_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (((sec_r001942_20_1 * 3) + pub_r001942_15_1) + 10) & 127;
  int stage_v_137_2 = (((sec_r001942_20_2 * 3) + pub_r001942_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = ((pub_r001942_1_1 * 2) + 47) & 63;
  int stage_v_138_2 = ((pub_r001942_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001942_2_1 * 2) + 16) & 63;
  int stage_v_139_2 = ((pub_r001942_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001942_19_1 * 2) + 21) & 63;
  int stage_v_140_2 = ((pub_r001942_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (((stage_v_61_1 * 3) + pub_r001942_14_1) + 21) & 127;
  int stage_v_141_2 = (((stage_v_61_2 * 3) + pub_r001942_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = ((pub_r001942_17_1 * 2) + 28) & 63;
  int stage_v_142_2 = ((pub_r001942_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001942_9_1 * 2) + 45) & 63;
  int stage_v_143_2 = ((pub_r001942_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001942_8_1 * 2) + 49) & 63;
  int stage_v_144_2 = ((pub_r001942_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001942_17_1 * 2) + 22) & 63;
  int stage_v_145_2 = ((pub_r001942_17_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001942_13_1 * 2) + 33) & 63;
  int stage_v_146_2 = ((pub_r001942_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001942_3_1 * 2) + 11) & 63;
  int stage_v_147_2 = ((pub_r001942_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_84_1 * 3) + pub_r001942_2_1) + 16) & 127;
  int stage_v_148_2 = (((stage_v_84_2 * 3) + pub_r001942_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((sec_r001942_3_1 * 3) + pub_r001942_3_1) + 9) & 127;
  int stage_v_149_2 = (((sec_r001942_3_2 * 3) + pub_r001942_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = ((pub_r001942_7_1 * 2) + 22) & 63;
  int stage_v_150_2 = ((pub_r001942_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001942_4_1 * 2) + 17) & 63;
  int stage_v_151_2 = ((pub_r001942_4_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001942_5_1 * 2) + 11) & 63;
  int stage_v_152_2 = ((pub_r001942_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((helper_flow_4_1 * 3) + pub_r001942_1_1) + 16) & 127;
  int stage_v_153_2 = (((helper_flow_4_2 * 3) + pub_r001942_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = ((pub_r001942_12_1 * 2) + 18) & 63;
  int stage_v_154_2 = ((pub_r001942_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((stage_v_153_1 * 3) + pub_r001942_20_1) + 26) & 127;
  int stage_v_155_2 = (((stage_v_153_2 * 3) + pub_r001942_20_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = ((pub_r001942_17_1 * 2) + 27) & 63;
  int stage_v_156_2 = ((pub_r001942_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = (((helper_flow_2_1 * 3) + pub_r001942_12_1) + 34) & 127;
  int stage_v_157_2 = (((helper_flow_2_2 * 3) + pub_r001942_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = ((pub_r001942_4_1 * 2) + 37) & 63;
  int stage_v_158_2 = ((pub_r001942_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001942_19_1 * 2) + 9) & 63;
  int stage_v_159_2 = ((pub_r001942_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001942_11_1 * 2) + 20) & 63;
  int stage_v_160_2 = ((pub_r001942_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_96_1 * 3) + pub_r001942_18_1) + 15) & 127;
  int stage_v_161_2 = (((stage_v_96_2 * 3) + pub_r001942_18_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = (((stage_v_117_1 * 3) + pub_r001942_10_1) + 12) & 127;
  int stage_v_162_2 = (((stage_v_117_2 * 3) + pub_r001942_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = ((pub_r001942_19_1 * 2) + 5) & 63;
  int stage_v_163_2 = ((pub_r001942_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001942_4_1 * 2) + 31) & 63;
  int stage_v_164_2 = ((pub_r001942_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001942_3_1 * 2) + 17) & 63;
  int stage_v_165_2 = ((pub_r001942_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001942_0_1 * 2) + 22) & 63;
  int stage_v_166_2 = ((pub_r001942_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_105_1 * 3) + pub_r001942_7_1) + 12) & 127;
  int stage_v_167_2 = (((stage_v_105_2 * 3) + pub_r001942_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = (((sec_r001942_19_1 * 3) + pub_r001942_17_1) + 28) & 127;
  int stage_v_168_2 = (((sec_r001942_19_2 * 3) + pub_r001942_17_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = (((stage_v_43_1 * 3) + pub_r001942_7_1) + 5) & 127;
  int stage_v_169_2 = (((stage_v_43_2 * 3) + pub_r001942_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = ((pub_r001942_2_1 * 2) + 19) & 63;
  int stage_v_170_2 = ((pub_r001942_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001942_5_1 * 2) + 10) & 63;
  int stage_v_171_2 = ((pub_r001942_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001942_8_1 * 2) + 12) & 63;
  int stage_v_172_2 = ((pub_r001942_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001942_6_1 * 2) + 11) & 63;
  int stage_v_173_2 = ((pub_r001942_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001942_19_1 * 2) + 5) & 63;
  int stage_v_174_2 = ((pub_r001942_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_109_1 * 3) + pub_r001942_18_1) + 22) & 127;
  int stage_v_175_2 = (((stage_v_109_2 * 3) + pub_r001942_18_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = ((pub_r001942_15_1 * 2) + 19) & 63;
  int stage_v_176_2 = ((pub_r001942_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001942_7_1 * 2) + 12) & 63;
  int stage_v_177_2 = ((pub_r001942_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((sec_r001942_15_1 * 3) + pub_r001942_12_1) + 6) & 127;
  int stage_v_178_2 = (((sec_r001942_15_2 * 3) + pub_r001942_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = (((stage_v_98_1 * 3) + pub_r001942_8_1) + 24) & 127;
  int stage_v_179_2 = (((stage_v_98_2 * 3) + pub_r001942_8_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = (((sec_r001942_14_1 * 3) + pub_r001942_4_1) + 7) & 127;
  int stage_v_180_2 = (((sec_r001942_14_2 * 3) + pub_r001942_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = ((pub_r001942_1_1 * 2) + 24) & 63;
  int stage_v_181_2 = ((pub_r001942_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((stage_v_2_1 * 3) + pub_r001942_20_1) + 21) & 127;
  int stage_v_182_2 = (((stage_v_2_2 * 3) + pub_r001942_20_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = (((sec_r001942_2_1 * 3) + pub_r001942_7_1) + 3) & 127;
  int stage_v_183_2 = (((sec_r001942_2_2 * 3) + pub_r001942_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((sec_r001942_15_1 * 3) + pub_r001942_6_1) + 41) & 127;
  int stage_v_184_2 = (((sec_r001942_15_2 * 3) + pub_r001942_6_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = (((stage_v_162_1 * 3) + pub_r001942_16_1) + 12) & 127;
  int stage_v_185_2 = (((stage_v_162_2 * 3) + pub_r001942_16_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = ((pub_r001942_20_1 * 2) + 34) & 63;
  int stage_v_186_2 = ((pub_r001942_20_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001942_12_1 * 2) + 21) & 63;
  int stage_v_187_2 = ((pub_r001942_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001942_2_1 * 2) + 17) & 63;
  int stage_v_188_2 = ((pub_r001942_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((stage_v_43_1 * 3) + pub_r001942_11_1) + 18) & 127;
  int stage_v_189_2 = (((stage_v_43_2 * 3) + pub_r001942_11_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = (((sec_r001942_4_1 * 3) + pub_r001942_6_1) + 34) & 127;
  int stage_v_190_2 = (((sec_r001942_4_2 * 3) + pub_r001942_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = (((stage_v_168_1 * 3) + pub_r001942_9_1) + 43) & 127;
  int stage_v_191_2 = (((stage_v_168_2 * 3) + pub_r001942_9_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = ((pub_r001942_6_1 * 2) + 39) & 63;
  int stage_v_192_2 = ((pub_r001942_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001942_7_1 * 2) + 15) & 63;
  int stage_v_193_2 = ((pub_r001942_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001942_2_1 * 2) + 7) & 63;
  int stage_v_194_2 = ((pub_r001942_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001942_12_1 * 2) + 10) & 63;
  int stage_v_195_2 = ((pub_r001942_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001942_13_1 * 2) + 14) & 63;
  int stage_v_196_2 = ((pub_r001942_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001942_13_1 * 2) + 26) & 63;
  int stage_v_197_2 = ((pub_r001942_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_141_1 * 3) + pub_r001942_1_1) + 40) & 127;
  int stage_v_198_2 = (((stage_v_141_2 * 3) + pub_r001942_1_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = (((sec_r001942_6_1 * 3) + pub_r001942_12_1) + 31) & 127;
  int stage_v_199_2 = (((sec_r001942_6_2 * 3) + pub_r001942_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = (((stage_v_63_1 * 3) + pub_r001942_13_1) + 35) & 127;
  int stage_v_200_2 = (((stage_v_63_2 * 3) + pub_r001942_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = ((pub_r001942_12_1 * 2) + 23) & 63;
  int stage_v_201_2 = ((pub_r001942_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001942_1_1 * 2) + 47) & 63;
  int stage_v_202_2 = ((pub_r001942_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001942_17_1 * 2) + 7) & 63;
  int stage_v_203_2 = ((pub_r001942_17_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001942_8_1 * 2) + 7) & 63;
  int stage_v_204_2 = ((pub_r001942_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((sec_r001942_19_1 * 3) + pub_r001942_1_1) + 34) & 127;
  int stage_v_205_2 = (((sec_r001942_19_2 * 3) + pub_r001942_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = ((pub_r001942_1_1 * 2) + 29) & 63;
  int stage_v_206_2 = ((pub_r001942_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001942_10_1 * 2) + 32) & 63;
  int stage_v_207_2 = ((pub_r001942_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001942_11_1 * 2) + 39) & 63;
  int stage_v_208_2 = ((pub_r001942_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001942_4_1 * 2) + 13) & 63;
  int stage_v_209_2 = ((pub_r001942_4_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001942_19_1 * 2) + 16) & 63;
  int stage_v_210_2 = ((pub_r001942_19_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001942_9_1 * 2) + 10) & 63;
  int stage_v_211_2 = ((pub_r001942_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = (((stage_v_183_1 * 3) + pub_r001942_0_1) + 29) & 127;
  int stage_v_212_2 = (((stage_v_183_2 * 3) + pub_r001942_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = ((pub_r001942_11_1 * 2) + 16) & 63;
  int stage_v_213_2 = ((pub_r001942_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001942_16_1 * 2) + 35) & 63;
  int stage_v_214_2 = ((pub_r001942_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((sec_r001942_6_1 * 3) + pub_r001942_12_1) + 45) & 127;
  int stage_v_215_2 = (((sec_r001942_6_2 * 3) + pub_r001942_12_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((helper_flow_5_1 * 3) + pub_r001942_7_1) + 27) & 127;
  int stage_v_216_2 = (((helper_flow_5_2 * 3) + pub_r001942_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001942_14_1 * 2) + 47) & 63;
  int stage_v_217_2 = ((pub_r001942_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001942_10_1 * 2) + 44) & 63;
  int stage_v_218_2 = ((pub_r001942_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((stage_v_215_1 * 3) + pub_r001942_3_1) + 26) & 127;
  int stage_v_219_2 = (((stage_v_215_2 * 3) + pub_r001942_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = ((pub_r001942_6_1 * 2) + 29) & 63;
  int stage_v_220_2 = ((pub_r001942_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001942_11_1 * 2) + 21) & 63;
  int stage_v_221_2 = ((pub_r001942_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((pub_r001942_19_1 * 2) + 26) & 63;
  int stage_v_222_2 = ((pub_r001942_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001942_17_1 * 2) + 26) & 63;
  int stage_v_223_2 = ((pub_r001942_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001942_4_1 * 2) + 21) & 63;
  int stage_v_224_2 = ((pub_r001942_4_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_180_1 * 3) + pub_r001942_4_1) + 21) & 127;
  int stage_v_225_2 = (((stage_v_180_2 * 3) + pub_r001942_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = (((sec_r001942_11_1 * 3) + pub_r001942_13_1) + 28) & 127;
  int stage_v_226_2 = (((sec_r001942_11_2 * 3) + pub_r001942_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = ((pub_r001942_16_1 * 2) + 39) & 63;
  int stage_v_227_2 = ((pub_r001942_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001942_7_1 * 2) + 7) & 63;
  int stage_v_228_2 = ((pub_r001942_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((sec_r001942_10_1 * 3) + pub_r001942_1_1) + 40) & 127;
  int stage_v_229_2 = (((sec_r001942_10_2 * 3) + pub_r001942_1_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = ((pub_r001942_10_1 * 2) + 48) & 63;
  int stage_v_230_2 = ((pub_r001942_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001942_5_1 * 2) + 44) & 63;
  int stage_v_231_2 = ((pub_r001942_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001942_8_1 * 2) + 44) & 63;
  int stage_v_232_2 = ((pub_r001942_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001942_0_1 * 2) + 20) & 63;
  int stage_v_233_2 = ((pub_r001942_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = (((stage_v_107_1 * 3) + pub_r001942_11_1) + 33) & 127;
  int stage_v_234_2 = (((stage_v_107_2 * 3) + pub_r001942_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = ((pub_r001942_17_1 * 2) + 5) & 63;
  int stage_v_235_2 = ((pub_r001942_17_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = (((stage_v_167_1 * 3) + pub_r001942_16_1) + 30) & 127;
  int stage_v_236_2 = (((stage_v_167_2 * 3) + pub_r001942_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = ((pub_r001942_9_1 * 2) + 18) & 63;
  int stage_v_237_2 = ((pub_r001942_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = (((sec_r001942_8_1 * 3) + pub_r001942_19_1) + 41) & 127;
  int stage_v_238_2 = (((sec_r001942_8_2 * 3) + pub_r001942_19_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = (((sec_r001942_0_1 * 3) + pub_r001942_2_1) + 18) & 127;
  int stage_v_239_2 = (((sec_r001942_0_2 * 3) + pub_r001942_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = (((stage_v_22_1 * 3) + pub_r001942_12_1) + 11) & 127;
  int stage_v_240_2 = (((stage_v_22_2 * 3) + pub_r001942_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((stage_v_184_1 * 3) + pub_r001942_3_1) + 38) & 127;
  int stage_v_241_2 = (((stage_v_184_2 * 3) + pub_r001942_3_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = ((pub_r001942_6_1 * 2) + 11) & 63;
  int stage_v_242_2 = ((pub_r001942_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((pub_r001942_0_1 * 2) + 31) & 63;
  int stage_v_243_2 = ((pub_r001942_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((stage_v_20_1 * 3) + pub_r001942_10_1) + 10) & 127;
  int stage_v_244_2 = (((stage_v_20_2 * 3) + pub_r001942_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = ((pub_r001942_14_1 * 2) + 33) & 63;
  int stage_v_245_2 = ((pub_r001942_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001942_4_1 * 2) + 6) & 63;
  int stage_v_246_2 = ((pub_r001942_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001942_12_1 * 2) + 22) & 63;
  int stage_v_247_2 = ((pub_r001942_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001942_4_1 * 2) + 25) & 63;
  int stage_v_248_2 = ((pub_r001942_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001942_0_1 * 2) + 43) & 63;
  int stage_v_249_2 = ((pub_r001942_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001942_2_1 * 2) + 10) & 63;
  int stage_v_250_2 = ((pub_r001942_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = (((stage_v_137_1 * 3) + pub_r001942_9_1) + 44) & 127;
  int stage_v_251_2 = (((stage_v_137_2 * 3) + pub_r001942_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = (((sec_r001942_4_1 * 3) + pub_r001942_1_1) + 26) & 127;
  int stage_v_252_2 = (((sec_r001942_4_2 * 3) + pub_r001942_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = ((pub_r001942_13_1 * 2) + 40) & 63;
  int stage_v_253_2 = ((pub_r001942_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((pub_r001942_17_1 * 2) + 34) & 63;
  int stage_v_254_2 = ((pub_r001942_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001942_16_1 * 2) + 24) & 63;
  int stage_v_255_2 = ((pub_r001942_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001942_14_1 * 2) + 35) & 63;
  int stage_v_256_2 = ((pub_r001942_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001942_7_1 * 2) + 25) & 63;
  int stage_v_257_2 = ((pub_r001942_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_85_1 * 3) + pub_r001942_16_1) + 13) & 127;
  int stage_v_258_2 = (((stage_v_85_2 * 3) + pub_r001942_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001942_18_1 * 2) + 23) & 63;
  int stage_v_259_2 = ((pub_r001942_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = (((stage_v_225_1 * 3) + pub_r001942_20_1) + 28) & 127;
  int stage_v_260_2 = (((stage_v_225_2 * 3) + pub_r001942_20_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = ((pub_r001942_17_1 * 2) + 23) & 63;
  int stage_v_261_2 = ((pub_r001942_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001942_14_1 * 2) + 39) & 63;
  int stage_v_262_2 = ((pub_r001942_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001942_10_1 * 2) + 7) & 63;
  int stage_v_263_2 = ((pub_r001942_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((pub_r001942_14_1 * 2) + 23) & 63;
  int stage_v_264_2 = ((pub_r001942_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((stage_v_16_1 * 3) + pub_r001942_0_1) + 5) & 127;
  int stage_v_265_2 = (((stage_v_16_2 * 3) + pub_r001942_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = (((stage_v_72_1 * 3) + pub_r001942_2_1) + 12) & 127;
  int stage_v_266_2 = (((stage_v_72_2 * 3) + pub_r001942_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = (((stage_v_30_1 * 3) + pub_r001942_19_1) + 26) & 127;
  int stage_v_267_2 = (((stage_v_30_2 * 3) + pub_r001942_19_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = ((pub_r001942_9_1 * 2) + 20) & 63;
  int stage_v_268_2 = ((pub_r001942_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001942_19_1 * 2) + 23) & 63;
  int stage_v_269_2 = ((pub_r001942_19_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001942_1_1 * 2) + 48) & 63;
  int stage_v_270_2 = ((pub_r001942_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = (((stage_v_148_1 * 3) + pub_r001942_1_1) + 30) & 127;
  int stage_v_271_2 = (((stage_v_148_2 * 3) + pub_r001942_1_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = (((stage_v_183_1 * 3) + pub_r001942_14_1) + 41) & 127;
  int stage_v_272_2 = (((stage_v_183_2 * 3) + pub_r001942_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = ((pub_r001942_15_1 * 2) + 15) & 63;
  int stage_v_273_2 = ((pub_r001942_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = (((stage_v_43_1 * 3) + pub_r001942_3_1) + 7) & 127;
  int stage_v_274_2 = (((stage_v_43_2 * 3) + pub_r001942_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = (((stage_v_271_1 * 3) + pub_r001942_3_1) + 15) & 127;
  int stage_v_275_2 = (((stage_v_271_2 * 3) + pub_r001942_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = ((pub_r001942_13_1 * 2) + 5) & 63;
  int stage_v_276_2 = ((pub_r001942_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((pub_r001942_10_1 * 2) + 20) & 63;
  int stage_v_277_2 = ((pub_r001942_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = (((stage_v_93_1 * 3) + pub_r001942_11_1) + 34) & 127;
  int stage_v_278_2 = (((stage_v_93_2 * 3) + pub_r001942_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = ((pub_r001942_10_1 * 2) + 31) & 63;
  int stage_v_279_2 = ((pub_r001942_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001942_3_1 * 2) + 18) & 63;
  int stage_v_280_2 = ((pub_r001942_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001942_12_1 * 2) + 6) & 63;
  int stage_v_281_2 = ((pub_r001942_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((pub_r001942_16_1 * 2) + 15) & 63;
  int stage_v_282_2 = ((pub_r001942_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001942_3_1 * 2) + 24) & 63;
  int stage_v_283_2 = ((pub_r001942_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001942_19_1 * 2) + 46) & 63;
  int stage_v_284_2 = ((pub_r001942_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001942_9_1 * 2) + 31) & 63;
  int stage_v_285_2 = ((pub_r001942_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001942_1_1 * 2) + 49) & 63;
  int stage_v_286_2 = ((pub_r001942_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = (((sec_r001942_3_1 * 3) + pub_r001942_10_1) + 9) & 127;
  int stage_v_287_2 = (((sec_r001942_3_2 * 3) + pub_r001942_10_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = ((pub_r001942_9_1 * 2) + 42) & 63;
  int stage_v_288_2 = ((pub_r001942_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((pub_r001942_15_1 * 2) + 36) & 63;
  int stage_v_289_2 = ((pub_r001942_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((pub_r001942_9_1 * 2) + 27) & 63;
  int stage_v_290_2 = ((pub_r001942_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = (((stage_v_219_1 * 3) + pub_r001942_17_1) + 37) & 127;
  int stage_v_291_2 = (((stage_v_219_2 * 3) + pub_r001942_17_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = ((pub_r001942_18_1 * 2) + 48) & 63;
  int stage_v_292_2 = ((pub_r001942_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001942_20_1 * 2) + 12) & 63;
  int stage_v_293_2 = ((pub_r001942_20_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001942_9_1 * 2) + 6) & 63;
  int stage_v_294_2 = ((pub_r001942_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001942_8_1 * 2) + 47) & 63;
  int stage_v_295_2 = ((pub_r001942_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((pub_r001942_15_1 * 2) + 49) & 63;
  int stage_v_296_2 = ((pub_r001942_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001942_13_1 * 2) + 28) & 63;
  int stage_v_297_2 = ((pub_r001942_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((helper_flow_0_1 * 3) + pub_r001942_5_1) + 41) & 127;
  int stage_v_298_2 = (((helper_flow_0_2 * 3) + pub_r001942_5_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001942_16_1 * 2) + 48) & 63;
  int stage_v_299_2 = ((pub_r001942_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001942_3_1 * 2) + 29) & 63;
  int stage_v_300_2 = ((pub_r001942_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001942_10_1 * 2) + 34) & 63;
  int stage_v_301_2 = ((pub_r001942_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = (((stage_v_251_1 * 3) + pub_r001942_17_1) + 20) & 127;
  int stage_v_302_2 = (((stage_v_251_2 * 3) + pub_r001942_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = ((pub_r001942_2_1 * 2) + 31) & 63;
  int stage_v_303_2 = ((pub_r001942_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001942_5_1 * 2) + 50) & 63;
  int stage_v_304_2 = ((pub_r001942_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001942_11_1 * 2) + 42) & 63;
  int stage_v_305_2 = ((pub_r001942_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001942_20_1 * 2) + 6) & 63;
  int stage_v_306_2 = ((pub_r001942_20_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = (((stage_v_17_1 * 3) + pub_r001942_8_1) + 10) & 127;
  int stage_v_307_2 = (((stage_v_17_2 * 3) + pub_r001942_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = ((pub_r001942_8_1 * 2) + 25) & 63;
  int stage_v_308_2 = ((pub_r001942_8_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = (((stage_v_240_1 * 3) + pub_r001942_1_1) + 4) & 127;
  int stage_v_309_2 = (((stage_v_240_2 * 3) + pub_r001942_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = ((pub_r001942_11_1 * 2) + 10) & 63;
  int stage_v_310_2 = ((pub_r001942_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = (((sec_r001942_0_1 * 3) + pub_r001942_15_1) + 22) & 127;
  int stage_v_311_2 = (((sec_r001942_0_2 * 3) + pub_r001942_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = ((pub_r001942_15_1 * 2) + 23) & 63;
  int stage_v_312_2 = ((pub_r001942_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = ((pub_r001942_9_1 * 2) + 38) & 63;
  int stage_v_313_2 = ((pub_r001942_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = ((pub_r001942_14_1 * 2) + 25) & 63;
  int stage_v_314_2 = ((pub_r001942_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001942_9_1 * 2) + 41) & 63;
  int stage_v_315_2 = ((pub_r001942_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001942_16_1 * 2) + 33) & 63;
  int stage_v_316_2 = ((pub_r001942_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((pub_r001942_13_1 * 2) + 7) & 63;
  int stage_v_317_2 = ((pub_r001942_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = (((stage_v_98_1 * 3) + pub_r001942_8_1) + 16) & 127;
  int stage_v_318_2 = (((stage_v_98_2 * 3) + pub_r001942_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = (((stage_v_148_1 * 3) + pub_r001942_18_1) + 23) & 127;
  int stage_v_319_2 = (((stage_v_148_2 * 3) + pub_r001942_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = ((pub_r001942_5_1 * 2) + 50) & 63;
  int stage_v_320_2 = ((pub_r001942_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((pub_r001942_7_1 * 2) + 25) & 63;
  int stage_v_321_2 = ((pub_r001942_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001942_19_1 * 2) + 7) & 63;
  int stage_v_322_2 = ((pub_r001942_19_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001942_19_1 * 2) + 35) & 63;
  int stage_v_323_2 = ((pub_r001942_19_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = (((stage_v_298_1 * 3) + pub_r001942_19_1) + 12) & 127;
  int stage_v_324_2 = (((stage_v_298_2 * 3) + pub_r001942_19_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((sec_r001942_17_1 * 3) + pub_r001942_8_1) + 44) & 127;
  int stage_v_325_2 = (((sec_r001942_17_2 * 3) + pub_r001942_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = ((pub_r001942_9_1 * 2) + 31) & 63;
  int stage_v_326_2 = ((pub_r001942_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001942_9_1 * 2) + 14) & 63;
  int stage_v_327_2 = ((pub_r001942_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = (((stage_v_302_1 * 3) + pub_r001942_15_1) + 19) & 127;
  int stage_v_328_2 = (((stage_v_302_2 * 3) + pub_r001942_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = ((pub_r001942_4_1 * 2) + 41) & 63;
  int stage_v_329_2 = ((pub_r001942_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001942_20_1 * 2) + 14) & 63;
  int stage_v_330_2 = ((pub_r001942_20_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001942_16_1 * 2) + 25) & 63;
  int stage_v_331_2 = ((pub_r001942_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = (((stage_v_318_1 * 3) + pub_r001942_18_1) + 23) & 127;
  int stage_v_332_2 = (((stage_v_318_2 * 3) + pub_r001942_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = ((pub_r001942_5_1 * 2) + 49) & 63;
  int stage_v_333_2 = ((pub_r001942_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = (((stage_v_238_1 * 3) + pub_r001942_5_1) + 38) & 127;
  int stage_v_334_2 = (((stage_v_238_2 * 3) + pub_r001942_5_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = ((pub_r001942_7_1 * 2) + 46) & 63;
  int stage_v_335_2 = ((pub_r001942_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = (((stage_v_87_1 * 3) + pub_r001942_5_1) + 32) & 127;
  int stage_v_336_2 = (((stage_v_87_2 * 3) + pub_r001942_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = ((pub_r001942_17_1 * 2) + 49) & 63;
  int stage_v_337_2 = ((pub_r001942_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((pub_r001942_9_1 * 2) + 48) & 63;
  int stage_v_338_2 = ((pub_r001942_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = (((sec_r001942_11_1 * 3) + pub_r001942_14_1) + 22) & 127;
  int stage_v_339_2 = (((sec_r001942_11_2 * 3) + pub_r001942_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = (((stage_v_191_1 * 3) + pub_r001942_17_1) + 3) & 127;
  int stage_v_340_2 = (((stage_v_191_2 * 3) + pub_r001942_17_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = ((pub_r001942_17_1 * 2) + 36) & 63;
  int stage_v_341_2 = ((pub_r001942_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = (((stage_v_340_1 * 3) + pub_r001942_5_1) + 37) & 127;
  int stage_v_342_2 = (((stage_v_340_2 * 3) + pub_r001942_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = ((pub_r001942_16_1 * 2) + 38) & 63;
  int stage_v_343_2 = ((pub_r001942_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001942_3_1 * 2) + 17) & 63;
  int stage_v_344_2 = ((pub_r001942_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((pub_r001942_19_1 * 2) + 7) & 63;
  int stage_v_345_2 = ((pub_r001942_19_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001942_7_1 * 2) + 45) & 63;
  int stage_v_346_2 = ((pub_r001942_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001942_11_1 * 2) + 21) & 63;
  int stage_v_347_2 = ((pub_r001942_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((stage_v_238_1 * 3) + pub_r001942_4_1) + 26) & 127;
  int stage_v_348_2 = (((stage_v_238_2 * 3) + pub_r001942_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = ((pub_r001942_16_1 * 2) + 45) & 63;
  int stage_v_349_2 = ((pub_r001942_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = (((helper_flow_5_1 * 3) + pub_r001942_3_1) + 28) & 127;
  int stage_v_350_2 = (((helper_flow_5_2 * 3) + pub_r001942_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = ((pub_r001942_12_1 * 2) + 34) & 63;
  int stage_v_351_2 = ((pub_r001942_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001942_13_1 * 2) + 29) & 63;
  int stage_v_352_2 = ((pub_r001942_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = (((stage_v_229_1 * 3) + pub_r001942_8_1) + 35) & 127;
  int stage_v_353_2 = (((stage_v_229_2 * 3) + pub_r001942_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = ((pub_r001942_17_1 * 2) + 48) & 63;
  int stage_v_354_2 = ((pub_r001942_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001942_7_1 * 2) + 37) & 63;
  int stage_v_355_2 = ((pub_r001942_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((pub_r001942_14_1 * 2) + 13) & 63;
  int stage_v_356_2 = ((pub_r001942_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = (((stage_v_85_1 * 3) + pub_r001942_17_1) + 31) & 127;
  int stage_v_357_2 = (((stage_v_85_2 * 3) + pub_r001942_17_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = ((pub_r001942_18_1 * 2) + 21) & 63;
  int stage_v_358_2 = ((pub_r001942_18_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = (((stage_v_191_1 * 3) + pub_r001942_4_1) + 44) & 127;
  int stage_v_359_2 = (((stage_v_191_2 * 3) + pub_r001942_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = ((pub_r001942_3_1 * 2) + 41) & 63;
  int stage_v_360_2 = ((pub_r001942_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = (((stage_v_191_1 * 3) + pub_r001942_16_1) + 44) & 127;
  int stage_v_361_2 = (((stage_v_191_2 * 3) + pub_r001942_16_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = ((pub_r001942_4_1 * 2) + 29) & 63;
  int stage_v_362_2 = ((pub_r001942_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001942_7_1 * 2) + 7) & 63;
  int stage_v_363_2 = ((pub_r001942_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001942_11_1 * 2) + 20) & 63;
  int stage_v_364_2 = ((pub_r001942_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001942_18_1 * 2) + 33) & 63;
  int stage_v_365_2 = ((pub_r001942_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001942_2_1 * 2) + 16) & 63;
  int stage_v_366_2 = ((pub_r001942_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = (((stage_v_169_1 * 3) + pub_r001942_12_1) + 39) & 127;
  int stage_v_367_2 = (((stage_v_169_2 * 3) + pub_r001942_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = (((stage_v_212_1 * 3) + pub_r001942_20_1) + 3) & 127;
  int stage_v_368_2 = (((stage_v_212_2 * 3) + pub_r001942_20_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = ((pub_r001942_2_1 * 2) + 15) & 63;
  int stage_v_369_2 = ((pub_r001942_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = (((stage_v_319_1 * 3) + pub_r001942_9_1) + 12) & 127;
  int stage_v_370_2 = (((stage_v_319_2 * 3) + pub_r001942_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = (((sec_r001942_2_1 * 3) + pub_r001942_5_1) + 42) & 127;
  int stage_v_371_2 = (((sec_r001942_2_2 * 3) + pub_r001942_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = (((stage_v_348_1 * 3) + pub_r001942_4_1) + 35) & 127;
  int stage_v_372_2 = (((stage_v_348_2 * 3) + pub_r001942_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = ((pub_r001942_7_1 * 2) + 33) & 63;
  int stage_v_373_2 = ((pub_r001942_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = (((stage_v_57_1 * 3) + pub_r001942_8_1) + 26) & 127;
  int stage_v_374_2 = (((stage_v_57_2 * 3) + pub_r001942_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_124_1 * 3) + pub_r001942_17_1) + 23) & 127;
  int stage_v_375_2 = (((stage_v_124_2 * 3) + pub_r001942_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001942_14_1 * 2) + 27) & 63;
  int stage_v_376_2 = ((pub_r001942_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = (((stage_v_340_1 * 3) + pub_r001942_18_1) + 41) & 127;
  int stage_v_377_2 = (((stage_v_340_2 * 3) + pub_r001942_18_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = ((pub_r001942_0_1 * 2) + 29) & 63;
  int stage_v_378_2 = ((pub_r001942_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = ((pub_r001942_17_1 * 2) + 30) & 63;
  int stage_v_379_2 = ((pub_r001942_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = ((pub_r001942_2_1 * 2) + 44) & 63;
  int stage_v_380_2 = ((pub_r001942_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001942_8_1 * 2) + 15) & 63;
  int stage_v_381_2 = ((pub_r001942_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = (((stage_v_311_1 * 3) + pub_r001942_5_1) + 32) & 127;
  int stage_v_382_2 = (((stage_v_311_2 * 3) + pub_r001942_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = ((pub_r001942_16_1 * 2) + 5) & 63;
  int stage_v_383_2 = ((pub_r001942_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001942_2_1 * 2) + 6) & 63;
  int stage_v_384_2 = ((pub_r001942_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001942_5_1 * 2) + 29) & 63;
  int stage_v_385_2 = ((pub_r001942_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = (((stage_v_22_1 * 3) + pub_r001942_9_1) + 35) & 127;
  int stage_v_386_2 = (((stage_v_22_2 * 3) + pub_r001942_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_386_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_386_2 * 2)) & 255;
  int stage_v_387_1 = (((sec_r001942_14_1 * 3) + pub_r001942_14_1) + 22) & 127;
  int stage_v_387_2 = (((sec_r001942_14_2 * 3) + pub_r001942_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = (((stage_v_124_1 * 3) + pub_r001942_19_1) + 13) & 127;
  int stage_v_388_2 = (((stage_v_124_2 * 3) + pub_r001942_19_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = ((pub_r001942_5_1 * 2) + 50) & 63;
  int stage_v_389_2 = ((pub_r001942_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = (((stage_v_180_1 * 3) + pub_r001942_4_1) + 34) & 127;
  int stage_v_390_2 = (((stage_v_180_2 * 3) + pub_r001942_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = ((pub_r001942_4_1 * 2) + 39) & 63;
  int stage_v_391_2 = ((pub_r001942_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001942_4_1 * 2) + 50) & 63;
  int stage_v_392_2 = ((pub_r001942_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001942_11_1 * 2) + 46) & 63;
  int stage_v_393_2 = ((pub_r001942_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((pub_r001942_20_1 * 2) + 15) & 63;
  int stage_v_394_2 = ((pub_r001942_20_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001942_13_1 * 2) + 43) & 63;
  int stage_v_395_2 = ((pub_r001942_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((pub_r001942_1_1 * 2) + 30) & 63;
  int stage_v_396_2 = ((pub_r001942_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = (((stage_v_241_1 * 3) + pub_r001942_16_1) + 35) & 127;
  int stage_v_397_2 = (((stage_v_241_2 * 3) + pub_r001942_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = ((pub_r001942_10_1 * 2) + 46) & 63;
  int stage_v_398_2 = ((pub_r001942_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001942_8_1 * 2) + 46) & 63;
  int stage_v_399_2 = ((pub_r001942_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001942_20_1 * 2) + 39) & 63;
  int stage_v_400_2 = ((pub_r001942_20_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((pub_r001942_17_1 * 2) + 34) & 63;
  int stage_v_401_2 = ((pub_r001942_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = (((stage_v_252_1 * 3) + pub_r001942_6_1) + 18) & 127;
  int stage_v_402_2 = (((stage_v_252_2 * 3) + pub_r001942_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = (((sec_r001942_7_1 * 3) + pub_r001942_0_1) + 20) & 127;
  int stage_v_403_2 = (((sec_r001942_7_2 * 3) + pub_r001942_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = (((sec_r001942_20_1 * 3) + pub_r001942_19_1) + 18) & 127;
  int stage_v_404_2 = (((sec_r001942_20_2 * 3) + pub_r001942_19_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = (((stage_v_167_1 * 3) + pub_r001942_14_1) + 31) & 127;
  int stage_v_405_2 = (((stage_v_167_2 * 3) + pub_r001942_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = ((pub_r001942_5_1 * 2) + 46) & 63;
  int stage_v_406_2 = ((pub_r001942_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = (((stage_v_350_1 * 3) + pub_r001942_19_1) + 13) & 127;
  int stage_v_407_2 = (((stage_v_350_2 * 3) + pub_r001942_19_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_407_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_407_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_407_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_407_2 * 2)) & 255;
  int stage_v_408_1 = (((stage_v_370_1 * 3) + pub_r001942_4_1) + 30) & 127;
  int stage_v_408_2 = (((stage_v_370_2 * 3) + pub_r001942_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = ((pub_r001942_6_1 * 2) + 10) & 63;
  int stage_v_409_2 = ((pub_r001942_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((pub_r001942_6_1 * 2) + 32) & 63;
  int stage_v_410_2 = ((pub_r001942_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = (((sec_r001942_14_1 * 3) + pub_r001942_20_1) + 15) & 127;
  int stage_v_411_2 = (((sec_r001942_14_2 * 3) + pub_r001942_20_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_411_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_411_2 * 2)) & 255;
  int stage_v_412_1 = (((stage_v_372_1 * 3) + pub_r001942_11_1) + 11) & 127;
  int stage_v_412_2 = (((stage_v_372_2 * 3) + pub_r001942_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = ((pub_r001942_7_1 * 2) + 46) & 63;
  int stage_v_413_2 = ((pub_r001942_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = (((stage_v_319_1 * 3) + pub_r001942_14_1) + 40) & 127;
  int stage_v_414_2 = (((stage_v_319_2 * 3) + pub_r001942_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_414_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_414_2 * 2)) & 255;
  int stage_v_415_1 = ((pub_r001942_2_1 * 2) + 14) & 63;
  int stage_v_415_2 = ((pub_r001942_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = ((pub_r001942_7_1 * 2) + 36) & 63;
  int stage_v_416_2 = ((pub_r001942_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = (((stage_v_287_1 * 3) + pub_r001942_14_1) + 12) & 127;
  int stage_v_417_2 = (((stage_v_287_2 * 3) + pub_r001942_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = ((pub_r001942_6_1 * 2) + 33) & 63;
  int stage_v_418_2 = ((pub_r001942_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = (((stage_v_22_1 * 3) + pub_r001942_10_1) + 33) & 127;
  int stage_v_419_2 = (((stage_v_22_2 * 3) + pub_r001942_10_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = (((stage_v_96_1 * 3) + pub_r001942_12_1) + 6) & 127;
  int stage_v_420_2 = (((stage_v_96_2 * 3) + pub_r001942_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  int stage_v_421_1 = (((stage_v_342_1 * 3) + pub_r001942_10_1) + 28) & 127;
  int stage_v_421_2 = (((stage_v_342_2 * 3) + pub_r001942_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  int stage_v_422_1 = (((stage_v_183_1 * 3) + pub_r001942_5_1) + 37) & 127;
  int stage_v_422_2 = (((stage_v_183_2 * 3) + pub_r001942_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_422_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_422_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_422_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_422_2 * 2)) & 255;
  int stage_v_423_1 = ((pub_r001942_1_1 * 2) + 35) & 63;
  int stage_v_423_2 = ((pub_r001942_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001942_1_1 * 2) + 13) & 63;
  int stage_v_424_2 = ((pub_r001942_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = (((stage_v_137_1 * 3) + pub_r001942_7_1) + 4) & 127;
  int stage_v_425_2 = (((stage_v_137_2 * 3) + pub_r001942_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = ((pub_r001942_5_1 * 2) + 23) & 63;
  int stage_v_426_2 = ((pub_r001942_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((pub_r001942_8_1 * 2) + 42) & 63;
  int stage_v_427_2 = ((pub_r001942_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = ((pub_r001942_2_1 * 2) + 22) & 63;
  int stage_v_428_2 = ((pub_r001942_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((pub_r001942_14_1 * 2) + 36) & 63;
  int stage_v_429_2 = ((pub_r001942_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = ((pub_r001942_16_1 * 2) + 18) & 63;
  int stage_v_430_2 = ((pub_r001942_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = ((pub_r001942_8_1 * 2) + 16) & 63;
  int stage_v_431_2 = ((pub_r001942_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = (((stage_v_226_1 * 3) + pub_r001942_4_1) + 9) & 127;
  int stage_v_432_2 = (((stage_v_226_2 * 3) + pub_r001942_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = ((pub_r001942_20_1 * 2) + 12) & 63;
  int stage_v_433_2 = ((pub_r001942_20_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = ((pub_r001942_1_1 * 2) + 17) & 63;
  int stage_v_434_2 = ((pub_r001942_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = ((pub_r001942_3_1 * 2) + 27) & 63;
  int stage_v_435_2 = ((pub_r001942_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = ((pub_r001942_3_1 * 2) + 20) & 63;
  int stage_v_436_2 = ((pub_r001942_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = ((pub_r001942_9_1 * 2) + 49) & 63;
  int stage_v_437_2 = ((pub_r001942_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = (((helper_flow_1_1 * 3) + pub_r001942_6_1) + 15) & 127;
  int stage_v_438_2 = (((helper_flow_1_2 * 3) + pub_r001942_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_438_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_438_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_438_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_438_2 * 2)) & 255;
  int stage_v_439_1 = (((stage_v_374_1 * 3) + pub_r001942_17_1) + 39) & 127;
  int stage_v_439_2 = (((stage_v_374_2 * 3) + pub_r001942_17_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_439_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_439_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_439_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_439_2 * 2)) & 255;
  int stage_v_440_1 = ((pub_r001942_9_1 * 2) + 46) & 63;
  int stage_v_440_2 = ((pub_r001942_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001942_4_1 * 2) + 43) & 63;
  int stage_v_441_2 = ((pub_r001942_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((pub_r001942_10_1 * 2) + 37) & 63;
  int stage_v_442_2 = ((pub_r001942_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = ((pub_r001942_11_1 * 2) + 42) & 63;
  int stage_v_443_2 = ((pub_r001942_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001942_16_1 * 2) + 31) & 63;
  int stage_v_444_2 = ((pub_r001942_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((pub_r001942_16_1 * 2) + 6) & 63;
  int stage_v_445_2 = ((pub_r001942_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = (((stage_v_408_1 * 3) + pub_r001942_12_1) + 14) & 127;
  int stage_v_446_2 = (((stage_v_408_2 * 3) + pub_r001942_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_446_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_446_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_446_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_446_2 * 2)) & 255;
  int stage_v_447_1 = (((stage_v_101_1 * 3) + pub_r001942_17_1) + 42) & 127;
  int stage_v_447_2 = (((stage_v_101_2 * 3) + pub_r001942_17_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_447_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_447_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_447_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_447_2 * 2)) & 255;
  int stage_v_448_1 = ((pub_r001942_11_1 * 2) + 5) & 63;
  int stage_v_448_2 = ((pub_r001942_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = ((pub_r001942_0_1 * 2) + 26) & 63;
  int stage_v_449_2 = ((pub_r001942_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_449_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_449_2) & 127;
  int stage_v_450_1 = (((stage_v_61_1 * 3) + pub_r001942_9_1) + 36) & 127;
  int stage_v_450_2 = (((stage_v_61_2 * 3) + pub_r001942_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_450_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_450_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_450_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_450_2 * 2)) & 255;
  int stage_v_451_1 = (((stage_v_386_1 * 3) + pub_r001942_10_1) + 39) & 127;
  int stage_v_451_2 = (((stage_v_386_2 * 3) + pub_r001942_10_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_451_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_451_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_451_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_451_2 * 2)) & 255;
  int stage_v_452_1 = ((pub_r001942_15_1 * 2) + 39) & 63;
  int stage_v_452_2 = ((pub_r001942_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((pub_r001942_18_1 * 2) + 39) & 63;
  int stage_v_453_2 = ((pub_r001942_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = (((stage_v_340_1 * 3) + pub_r001942_17_1) + 44) & 127;
  int stage_v_454_2 = (((stage_v_340_2 * 3) + pub_r001942_17_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_454_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_454_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_454_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_454_2 * 2)) & 255;
  int stage_v_455_1 = (((stage_v_162_1 * 3) + pub_r001942_9_1) + 31) & 127;
  int stage_v_455_2 = (((stage_v_162_2 * 3) + pub_r001942_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_455_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_455_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_455_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_455_2 * 2)) & 255;
  int stage_v_456_1 = ((pub_r001942_5_1 * 2) + 41) & 63;
  int stage_v_456_2 = ((pub_r001942_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_456_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_456_2) & 127;
  int stage_v_457_1 = ((pub_r001942_10_1 * 2) + 9) & 63;
  int stage_v_457_2 = ((pub_r001942_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = ((pub_r001942_20_1 * 2) + 11) & 63;
  int stage_v_458_2 = ((pub_r001942_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = ((pub_r001942_10_1 * 2) + 8) & 63;
  int stage_v_459_2 = ((pub_r001942_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_459_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_459_2) & 127;
  int stage_v_460_1 = (((stage_v_367_1 * 3) + pub_r001942_6_1) + 27) & 127;
  int stage_v_460_2 = (((stage_v_367_2 * 3) + pub_r001942_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_460_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_460_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_460_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_460_2 * 2)) & 255;
  int stage_v_461_1 = ((pub_r001942_4_1 * 2) + 29) & 63;
  int stage_v_461_2 = ((pub_r001942_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = ((pub_r001942_19_1 * 2) + 13) & 63;
  int stage_v_462_2 = ((pub_r001942_19_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_462_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_462_2) & 127;
  int stage_v_463_1 = ((pub_r001942_9_1 * 2) + 23) & 63;
  int stage_v_463_2 = ((pub_r001942_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_463_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_463_2) & 127;
  int stage_v_464_1 = ((pub_r001942_19_1 * 2) + 5) & 63;
  int stage_v_464_2 = ((pub_r001942_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_464_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_464_2) & 127;
  int stage_v_465_1 = ((pub_r001942_1_1 * 2) + 10) & 63;
  int stage_v_465_2 = ((pub_r001942_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = ((pub_r001942_5_1 * 2) + 39) & 63;
  int stage_v_466_2 = ((pub_r001942_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_466_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_466_2) & 127;
  int stage_v_467_1 = (((stage_v_57_1 * 3) + pub_r001942_20_1) + 38) & 127;
  int stage_v_467_2 = (((stage_v_57_2 * 3) + pub_r001942_20_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_467_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_467_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_467_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_467_2 * 2)) & 255;
  int stage_v_468_1 = ((pub_r001942_7_1 * 2) + 47) & 63;
  int stage_v_468_2 = ((pub_r001942_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_468_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_468_2) & 127;
  int stage_v_469_1 = ((pub_r001942_12_1 * 2) + 44) & 63;
  int stage_v_469_2 = ((pub_r001942_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_469_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_469_2) & 127;
  int stage_v_470_1 = ((pub_r001942_15_1 * 2) + 43) & 63;
  int stage_v_470_2 = ((pub_r001942_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_470_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_470_2) & 127;
  int stage_v_471_1 = (((stage_v_132_1 * 3) + pub_r001942_5_1) + 18) & 127;
  int stage_v_471_2 = (((stage_v_132_2 * 3) + pub_r001942_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_471_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_471_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_471_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_471_2 * 2)) & 255;
  int stage_v_472_1 = (((stage_v_359_1 * 3) + pub_r001942_15_1) + 7) & 127;
  int stage_v_472_2 = (((stage_v_359_2 * 3) + pub_r001942_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_472_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_472_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_472_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_472_2 * 2)) & 255;
  int stage_v_473_1 = (((stage_v_234_1 * 3) + pub_r001942_0_1) + 3) & 127;
  int stage_v_473_2 = (((stage_v_234_2 * 3) + pub_r001942_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_473_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_473_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_473_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_473_2 * 2)) & 255;
  int stage_v_474_1 = ((pub_r001942_14_1 * 2) + 34) & 63;
  int stage_v_474_2 = ((pub_r001942_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_474_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_474_2) & 127;
  int stage_v_475_1 = (((sec_r001942_12_1 * 3) + pub_r001942_11_1) + 39) & 127;
  int stage_v_475_2 = (((sec_r001942_12_2 * 3) + pub_r001942_11_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_475_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_475_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_475_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_475_2 * 2)) & 255;
  int stage_v_476_1 = ((pub_r001942_3_1 * 2) + 12) & 63;
  int stage_v_476_2 = ((pub_r001942_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_476_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_476_2) & 127;
  int stage_v_477_1 = (((sec_r001942_11_1 * 3) + pub_r001942_6_1) + 14) & 127;
  int stage_v_477_2 = (((sec_r001942_11_2 * 3) + pub_r001942_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_477_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_477_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_477_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_477_2 * 2)) & 255;
  int stage_v_478_1 = (((stage_v_137_1 * 3) + pub_r001942_7_1) + 43) & 127;
  int stage_v_478_2 = (((stage_v_137_2 * 3) + pub_r001942_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_478_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_478_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_478_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_478_2 * 2)) & 255;
  int stage_v_479_1 = (((stage_v_229_1 * 3) + pub_r001942_6_1) + 4) & 127;
  int stage_v_479_2 = (((stage_v_229_2 * 3) + pub_r001942_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_479_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_479_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_479_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_479_2 * 2)) & 255;
  int stage_v_480_1 = ((pub_r001942_9_1 * 2) + 39) & 63;
  int stage_v_480_2 = ((pub_r001942_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_480_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_480_2) & 127;
  int stage_v_481_1 = (((stage_v_180_1 * 3) + pub_r001942_12_1) + 39) & 127;
  int stage_v_481_2 = (((stage_v_180_2 * 3) + pub_r001942_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_481_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_481_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_481_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_481_2 * 2)) & 255;
  int stage_v_482_1 = ((pub_r001942_2_1 * 2) + 15) & 63;
  int stage_v_482_2 = ((pub_r001942_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_482_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_482_2) & 127;
  int stage_v_483_1 = ((pub_r001942_5_1 * 2) + 41) & 63;
  int stage_v_483_2 = ((pub_r001942_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_483_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_483_2) & 127;
  int stage_v_484_1 = ((pub_r001942_10_1 * 2) + 39) & 63;
  int stage_v_484_2 = ((pub_r001942_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_484_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_484_2) & 127;
  int stage_v_485_1 = ((pub_r001942_15_1 * 2) + 13) & 63;
  int stage_v_485_2 = ((pub_r001942_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_485_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_485_2) & 127;
  int stage_v_486_1 = (((stage_v_54_1 * 3) + pub_r001942_13_1) + 8) & 127;
  int stage_v_486_2 = (((stage_v_54_2 * 3) + pub_r001942_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_486_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_486_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_486_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_486_2 * 2)) & 255;
  int stage_v_487_1 = ((pub_r001942_8_1 * 2) + 43) & 63;
  int stage_v_487_2 = ((pub_r001942_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_487_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_487_2) & 127;
  int stage_v_488_1 = ((pub_r001942_19_1 * 2) + 15) & 63;
  int stage_v_488_2 = ((pub_r001942_19_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_488_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_488_2) & 127;
  int stage_v_489_1 = ((pub_r001942_17_1 * 2) + 36) & 63;
  int stage_v_489_2 = ((pub_r001942_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_489_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_489_2) & 127;
  int stage_v_490_1 = ((pub_r001942_11_1 * 2) + 47) & 63;
  int stage_v_490_2 = ((pub_r001942_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_490_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_490_2) & 127;
  int stage_v_491_1 = ((pub_r001942_1_1 * 2) + 20) & 63;
  int stage_v_491_2 = ((pub_r001942_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_491_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_491_2) & 127;
  int stage_v_492_1 = ((pub_r001942_20_1 * 2) + 6) & 63;
  int stage_v_492_2 = ((pub_r001942_20_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_492_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_492_2) & 127;
  int stage_v_493_1 = (((stage_v_104_1 * 3) + pub_r001942_13_1) + 19) & 127;
  int stage_v_493_2 = (((stage_v_104_2 * 3) + pub_r001942_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_493_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_493_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_493_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_493_2 * 2)) & 255;
  int stage_v_494_1 = (((stage_v_87_1 * 3) + pub_r001942_16_1) + 24) & 127;
  int stage_v_494_2 = (((stage_v_87_2 * 3) + pub_r001942_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_494_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_494_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_494_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_494_2 * 2)) & 255;
  int stage_v_495_1 = ((pub_r001942_12_1 * 2) + 28) & 63;
  int stage_v_495_2 = ((pub_r001942_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_495_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_495_2) & 127;
  int stage_v_496_1 = ((pub_r001942_16_1 * 2) + 16) & 63;
  int stage_v_496_2 = ((pub_r001942_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_496_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_496_2) & 127;
  int stage_v_497_1 = (((sec_r001942_6_1 * 3) + pub_r001942_16_1) + 26) & 127;
  int stage_v_497_2 = (((sec_r001942_6_2 * 3) + pub_r001942_16_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_497_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_497_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_497_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_497_2 * 2)) & 255;
  int stage_v_498_1 = ((pub_r001942_8_1 * 2) + 24) & 63;
  int stage_v_498_2 = ((pub_r001942_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_498_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_498_2) & 127;
  int stage_v_499_1 = (((stage_v_41_1 * 3) + pub_r001942_14_1) + 18) & 127;
  int stage_v_499_2 = (((stage_v_41_2 * 3) + pub_r001942_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_499_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_499_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_499_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_499_2 * 2)) & 255;
  int stage_v_500_1 = ((pub_r001942_1_1 * 2) + 29) & 63;
  int stage_v_500_2 = ((pub_r001942_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_500_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_500_2) & 127;
  int stage_v_501_1 = ((pub_r001942_0_1 * 2) + 16) & 63;
  int stage_v_501_2 = ((pub_r001942_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_501_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_501_2) & 127;
  int stage_v_502_1 = (((stage_v_87_1 * 3) + pub_r001942_10_1) + 12) & 127;
  int stage_v_502_2 = (((stage_v_87_2 * 3) + pub_r001942_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_502_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_502_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_502_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_502_2 * 2)) & 255;
  int stage_v_503_1 = ((pub_r001942_1_1 * 2) + 47) & 63;
  int stage_v_503_2 = ((pub_r001942_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_503_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_503_2) & 127;
  int stage_v_504_1 = (((stage_v_481_1 * 3) + pub_r001942_12_1) + 5) & 127;
  int stage_v_504_2 = (((stage_v_481_2 * 3) + pub_r001942_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_504_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_504_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_504_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_504_2 * 2)) & 255;
  int stage_v_505_1 = (((stage_v_425_1 * 3) + pub_r001942_2_1) + 37) & 127;
  int stage_v_505_2 = (((stage_v_425_2 * 3) + pub_r001942_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_505_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_505_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_505_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_505_2 * 2)) & 255;
  int stage_v_506_1 = ((pub_r001942_1_1 * 2) + 21) & 63;
  int stage_v_506_2 = ((pub_r001942_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_506_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_506_2) & 127;
  int stage_v_507_1 = (((stage_v_361_1 * 3) + pub_r001942_1_1) + 13) & 127;
  int stage_v_507_2 = (((stage_v_361_2 * 3) + pub_r001942_1_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_507_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_507_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_507_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_507_2 * 2)) & 255;
  int stage_v_508_1 = (((stage_v_81_1 * 3) + pub_r001942_16_1) + 19) & 127;
  int stage_v_508_2 = (((stage_v_81_2 * 3) + pub_r001942_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_508_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_508_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_508_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_508_2 * 2)) & 255;
  int stage_v_509_1 = (((stage_v_4_1 * 3) + pub_r001942_4_1) + 34) & 127;
  int stage_v_509_2 = (((stage_v_4_2 * 3) + pub_r001942_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_509_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_509_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_509_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_509_2 * 2)) & 255;
  int stage_v_510_1 = ((pub_r001942_18_1 * 2) + 24) & 63;
  int stage_v_510_2 = ((pub_r001942_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_510_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_510_2) & 127;
  int stage_v_511_1 = ((pub_r001942_10_1 * 2) + 12) & 63;
  int stage_v_511_2 = ((pub_r001942_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_511_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_511_2) & 127;
  int stage_v_512_1 = ((pub_r001942_2_1 * 2) + 46) & 63;
  int stage_v_512_2 = ((pub_r001942_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_512_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_512_2) & 127;
  int stage_v_513_1 = (((stage_v_205_1 * 3) + pub_r001942_7_1) + 18) & 127;
  int stage_v_513_2 = (((stage_v_205_2 * 3) + pub_r001942_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_513_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_513_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_513_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_513_2 * 2)) & 255;
  int stage_v_514_1 = ((pub_r001942_5_1 * 2) + 26) & 63;
  int stage_v_514_2 = ((pub_r001942_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_514_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_514_2) & 127;
  int stage_v_515_1 = ((pub_r001942_10_1 * 2) + 11) & 63;
  int stage_v_515_2 = ((pub_r001942_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_515_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_515_2) & 127;
  int stage_v_516_1 = (((stage_v_339_1 * 3) + pub_r001942_18_1) + 17) & 127;
  int stage_v_516_2 = (((stage_v_339_2 * 3) + pub_r001942_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_516_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_516_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_516_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_516_2 * 2)) & 255;
  int stage_v_517_1 = ((pub_r001942_5_1 * 2) + 34) & 63;
  int stage_v_517_2 = ((pub_r001942_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_517_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_517_2) & 127;
  int stage_v_518_1 = (((stage_v_141_1 * 3) + pub_r001942_9_1) + 28) & 127;
  int stage_v_518_2 = (((stage_v_141_2 * 3) + pub_r001942_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_518_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_518_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_518_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_518_2 * 2)) & 255;
  int stage_v_519_1 = ((pub_r001942_7_1 * 2) + 45) & 63;
  int stage_v_519_2 = ((pub_r001942_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_519_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_519_2) & 127;
  int stage_v_520_1 = ((pub_r001942_0_1 * 2) + 37) & 63;
  int stage_v_520_2 = ((pub_r001942_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_520_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_520_2) & 127;
  int stage_v_521_1 = ((pub_r001942_19_1 * 2) + 50) & 63;
  int stage_v_521_2 = ((pub_r001942_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_521_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_521_2) & 127;
  int stage_v_522_1 = (((stage_v_169_1 * 3) + pub_r001942_10_1) + 40) & 127;
  int stage_v_522_2 = (((stage_v_169_2 * 3) + pub_r001942_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_522_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_522_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_522_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_522_2 * 2)) & 255;
  int stage_v_523_1 = (((stage_v_53_1 * 3) + pub_r001942_6_1) + 11) & 127;
  int stage_v_523_2 = (((stage_v_53_2 * 3) + pub_r001942_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_523_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_523_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_523_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_523_2 * 2)) & 255;
  int stage_v_524_1 = (((stage_v_225_1 * 3) + pub_r001942_12_1) + 12) & 127;
  int stage_v_524_2 = (((stage_v_225_2 * 3) + pub_r001942_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_524_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_524_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_524_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_524_2 * 2)) & 255;
  int stage_v_525_1 = (((stage_v_141_1 * 3) + pub_r001942_16_1) + 27) & 127;
  int stage_v_525_2 = (((stage_v_141_2 * 3) + pub_r001942_16_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_525_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_525_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_525_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_525_2 * 2)) & 255;
  int stage_v_526_1 = ((pub_r001942_20_1 * 2) + 20) & 63;
  int stage_v_526_2 = ((pub_r001942_20_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_526_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_526_2) & 127;
  int stage_v_527_1 = (((stage_v_372_1 * 3) + pub_r001942_2_1) + 34) & 127;
  int stage_v_527_2 = (((stage_v_372_2 * 3) + pub_r001942_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_527_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_527_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_527_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_527_2 * 2)) & 255;
  int stage_v_528_1 = ((pub_r001942_17_1 * 2) + 5) & 63;
  int stage_v_528_2 = ((pub_r001942_17_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_528_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_528_2) & 127;
  int stage_v_529_1 = ((pub_r001942_0_1 * 2) + 27) & 63;
  int stage_v_529_2 = ((pub_r001942_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_529_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_529_2) & 127;
  int stage_v_530_1 = (((stage_v_307_1 * 3) + pub_r001942_18_1) + 31) & 127;
  int stage_v_530_2 = (((stage_v_307_2 * 3) + pub_r001942_18_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_530_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_530_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_530_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_530_2 * 2)) & 255;
  int stage_v_531_1 = (((stage_v_234_1 * 3) + pub_r001942_4_1) + 9) & 127;
  int stage_v_531_2 = (((stage_v_234_2 * 3) + pub_r001942_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_531_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_531_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_531_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_531_2 * 2)) & 255;
  int stage_v_532_1 = ((pub_r001942_7_1 * 2) + 29) & 63;
  int stage_v_532_2 = ((pub_r001942_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_532_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_532_2) & 127;
  int stage_v_533_1 = ((pub_r001942_20_1 * 2) + 45) & 63;
  int stage_v_533_2 = ((pub_r001942_20_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_533_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_533_2) & 127;
  int stage_v_534_1 = (((stage_v_350_1 * 3) + pub_r001942_13_1) + 20) & 127;
  int stage_v_534_2 = (((stage_v_350_2 * 3) + pub_r001942_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_534_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_534_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_534_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_534_2 * 2)) & 255;
  int stage_v_535_1 = ((pub_r001942_18_1 * 2) + 42) & 63;
  int stage_v_535_2 = ((pub_r001942_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_535_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_535_2) & 127;
  int stage_v_536_1 = (((stage_v_20_1 * 3) + pub_r001942_3_1) + 34) & 127;
  int stage_v_536_2 = (((stage_v_20_2 * 3) + pub_r001942_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_536_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_536_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_536_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_536_2 * 2)) & 255;
  int stage_v_537_1 = ((pub_r001942_18_1 * 2) + 9) & 63;
  int stage_v_537_2 = ((pub_r001942_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_537_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_537_2) & 127;
  int stage_v_538_1 = ((pub_r001942_12_1 * 2) + 19) & 63;
  int stage_v_538_2 = ((pub_r001942_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_538_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_538_2) & 127;
  int stage_v_539_1 = (((stage_v_199_1 * 3) + pub_r001942_20_1) + 25) & 127;
  int stage_v_539_2 = (((stage_v_199_2 * 3) + pub_r001942_20_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_539_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_539_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_539_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_539_2 * 2)) & 255;
  int stage_v_540_1 = ((pub_r001942_7_1 * 2) + 23) & 63;
  int stage_v_540_2 = ((pub_r001942_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_540_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_540_2) & 127;
  int stage_v_541_1 = ((pub_r001942_19_1 * 2) + 49) & 63;
  int stage_v_541_2 = ((pub_r001942_19_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_541_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_541_2) & 127;
  int stage_v_542_1 = (((stage_v_117_1 * 3) + pub_r001942_6_1) + 37) & 127;
  int stage_v_542_2 = (((stage_v_117_2 * 3) + pub_r001942_6_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_542_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_542_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_542_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_542_2 * 2)) & 255;
  int stage_v_543_1 = ((pub_r001942_14_1 * 2) + 35) & 63;
  int stage_v_543_2 = ((pub_r001942_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_543_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_543_2) & 127;
  int stage_v_544_1 = (((stage_v_267_1 * 3) + pub_r001942_2_1) + 34) & 127;
  int stage_v_544_2 = (((stage_v_267_2 * 3) + pub_r001942_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_544_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_544_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_544_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_544_2 * 2)) & 255;
  int stage_v_545_1 = (((sec_r001942_16_1 * 3) + pub_r001942_5_1) + 17) & 127;
  int stage_v_545_2 = (((sec_r001942_16_2 * 3) + pub_r001942_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_545_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_545_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_545_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_545_2 * 2)) & 255;
  int stage_v_546_1 = ((pub_r001942_19_1 * 2) + 23) & 63;
  int stage_v_546_2 = ((pub_r001942_19_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_546_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_546_2) & 127;
  int stage_v_547_1 = ((pub_r001942_8_1 * 2) + 45) & 63;
  int stage_v_547_2 = ((pub_r001942_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_547_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_547_2) & 127;
  int stage_v_548_1 = ((pub_r001942_2_1 * 2) + 37) & 63;
  int stage_v_548_2 = ((pub_r001942_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_548_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_548_2) & 127;
  int stage_v_549_1 = ((pub_r001942_20_1 * 2) + 30) & 63;
  int stage_v_549_2 = ((pub_r001942_20_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_549_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_549_2) & 127;
  int stage_v_550_1 = ((pub_r001942_7_1 * 2) + 15) & 63;
  int stage_v_550_2 = ((pub_r001942_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_550_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_550_2) & 127;
  int stage_v_551_1 = ((pub_r001942_10_1 * 2) + 27) & 63;
  int stage_v_551_2 = ((pub_r001942_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_551_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_551_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001942_13_1 != sec_r001942_13_2);
  __CPROVER_assume(pub_r001942_17_1 == pub_r001942_17_2);
  __CPROVER_assume(sec_r001942_0_1 != sec_r001942_0_2);
  __CPROVER_assume(sec_r001942_19_1 != sec_r001942_19_2);
  __CPROVER_assume(sec_r001942_8_1 != sec_r001942_8_2);
  __CPROVER_assume(pub_r001942_14_1 == pub_r001942_14_2);
  __CPROVER_assume(pub_r001942_5_1 == pub_r001942_5_2);
  __CPROVER_assume(sec_r001942_3_1 != sec_r001942_3_2);
  __CPROVER_assume(pub_r001942_1_1 == pub_r001942_1_2);
  __CPROVER_assume(sec_r001942_14_1 != sec_r001942_14_2);
  __CPROVER_assume(sec_r001942_5_1 != sec_r001942_5_2);
  __CPROVER_assume(pub_r001942_12_1 == pub_r001942_12_2);
  __CPROVER_assume(pub_r001942_18_1 == pub_r001942_18_2);
  __CPROVER_assume(sec_r001942_4_1 != sec_r001942_4_2);
  __CPROVER_assume(sec_r001942_2_1 != sec_r001942_2_2);
  __CPROVER_assume(sec_r001942_6_1 != sec_r001942_6_2);
  __CPROVER_assume(sec_r001942_12_1 != sec_r001942_12_2);
  __CPROVER_assume(pub_r001942_8_1 == pub_r001942_8_2);
  __CPROVER_assume(pub_r001942_4_1 == pub_r001942_4_2);
  __CPROVER_assume(sec_r001942_9_1 != sec_r001942_9_2);
  __CPROVER_assume(pub_r001942_20_1 == pub_r001942_20_2);
  __CPROVER_assume(sec_r001942_7_1 != sec_r001942_7_2);
  __CPROVER_assume(pub_r001942_16_1 == pub_r001942_16_2);
  __CPROVER_assume(pub_r001942_6_1 == pub_r001942_6_2);
  __CPROVER_assume(pub_r001942_15_1 == pub_r001942_15_2);
  __CPROVER_assume(pub_r001942_3_1 == pub_r001942_3_2);
  __CPROVER_assume(sec_r001942_11_1 != sec_r001942_11_2);
  __CPROVER_assume(pub_r001942_11_1 == pub_r001942_11_2);
  __CPROVER_assume(sec_r001942_15_1 != sec_r001942_15_2);
  __CPROVER_assume(sec_r001942_10_1 != sec_r001942_10_2);
  __CPROVER_assume(pub_r001942_2_1 == pub_r001942_2_2);
  __CPROVER_assume(pub_r001942_10_1 == pub_r001942_10_2);
  __CPROVER_assume(sec_r001942_1_1 != sec_r001942_1_2);
  __CPROVER_assume(sec_r001942_20_1 != sec_r001942_20_2);
  __CPROVER_assume(pub_r001942_9_1 == pub_r001942_9_2);
  __CPROVER_assume(pub_r001942_0_1 == pub_r001942_0_2);
  __CPROVER_assume(pub_r001942_13_1 == pub_r001942_13_2);
  __CPROVER_assume(sec_r001942_16_1 != sec_r001942_16_2);
  __CPROVER_assume(pub_r001942_19_1 == pub_r001942_19_2);
  __CPROVER_assume(sec_r001942_17_1 != sec_r001942_17_2);
  __CPROVER_assume(sec_r001942_18_1 != sec_r001942_18_2);
  __CPROVER_assume(pub_r001942_7_1 == pub_r001942_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.status == st_var_0_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
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
  assert(stage_v_505_1 == stage_v_505_2);
  assert(stage_v_506_1 == stage_v_506_2);
  assert(stage_v_507_1 == stage_v_507_2);
  assert(stage_v_508_1 == stage_v_508_2);
  assert(stage_v_509_1 == stage_v_509_2);
  assert(stage_v_510_1 == stage_v_510_2);
  assert(stage_v_511_1 == stage_v_511_2);
  assert(stage_v_512_1 == stage_v_512_2);
  assert(stage_v_513_1 == stage_v_513_2);
  assert(stage_v_514_1 == stage_v_514_2);
  assert(stage_v_515_1 == stage_v_515_2);
  assert(stage_v_516_1 == stage_v_516_2);
  assert(stage_v_517_1 == stage_v_517_2);
  assert(stage_v_518_1 == stage_v_518_2);
  assert(stage_v_519_1 == stage_v_519_2);
  assert(stage_v_520_1 == stage_v_520_2);
  assert(stage_v_521_1 == stage_v_521_2);
  assert(stage_v_522_1 == stage_v_522_2);
  assert(stage_v_523_1 == stage_v_523_2);
  assert(stage_v_524_1 == stage_v_524_2);
  assert(stage_v_525_1 == stage_v_525_2);
  assert(stage_v_526_1 == stage_v_526_2);
  assert(stage_v_527_1 == stage_v_527_2);
  assert(stage_v_528_1 == stage_v_528_2);
  assert(stage_v_529_1 == stage_v_529_2);
  assert(stage_v_530_1 == stage_v_530_2);
  assert(stage_v_531_1 == stage_v_531_2);
  assert(stage_v_532_1 == stage_v_532_2);
  assert(stage_v_533_1 == stage_v_533_2);
  assert(stage_v_534_1 == stage_v_534_2);
  assert(stage_v_535_1 == stage_v_535_2);
  assert(stage_v_536_1 == stage_v_536_2);
  assert(stage_v_537_1 == stage_v_537_2);
  assert(stage_v_538_1 == stage_v_538_2);
  assert(stage_v_539_1 == stage_v_539_2);
  assert(stage_v_540_1 == stage_v_540_2);
  assert(stage_v_541_1 == stage_v_541_2);
  assert(stage_v_542_1 == stage_v_542_2);
  assert(stage_v_543_1 == stage_v_543_2);
  assert(stage_v_544_1 == stage_v_544_2);
  assert(stage_v_545_1 == stage_v_545_2);
  assert(stage_v_546_1 == stage_v_546_2);
  assert(stage_v_547_1 == stage_v_547_2);
  assert(stage_v_548_1 == stage_v_548_2);
  assert(stage_v_549_1 == stage_v_549_2);
  assert(stage_v_550_1 == stage_v_550_2);
  assert(stage_v_551_1 == stage_v_551_2);
}


