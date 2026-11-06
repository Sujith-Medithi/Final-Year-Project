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
struct SensorNode_R000957_5713_0
{
  int gain;
  unsigned char reading;
  int offset;
  int calib;
  int status;
  int threshold;
  int buffer[3];
};
struct Transaction_R000957_5713_1
{
  unsigned char status;
  short balance;
  short fee;
  int auth_code;
  int account_id;
  int buffer[3];
};
struct CipherContext_R000957_5713_2
{
  int flags;
  int nonce;
  int tag;
  short iv;
  int round_key;
  short counter;
  int buffer[3];
};
union TelemetryField_R000957_5713_0
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
void fn_R000957_5713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000957_5713_2 st_1 = {0};
  struct CipherContext_R000957_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_72_1) & 63;
  aux_2 = (aux_2 + factor_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_72_1 = local_arr_1[aux_1 % 3];
  int checksum_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_72_2 * 2)) & 127;
  int threshold_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_24_1)
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

  switch (threshold_24_2)
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
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_72_1 == factor_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_72_1 == checksum_72_2);
  assert(threshold_24_1 == threshold_24_2);
}

int fn_R000957_5713_0(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000957_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_72) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int checksum_72 = local_arr[aux % 3];
  acc = (acc + (checksum_72 * 2)) & 127;
  int threshold_24 = (aux + st.buffer[1]) & 3;
  switch (threshold_24)
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

void fn_R000957_5713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000957_5713_2 st_1 = {0};
  struct CipherContext_R000957_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_83_1 > 49)
  {
    acc_1 = ((acc_1 + (mask_83_1 * 2)) + 5) & 127;
    aux_1 ^= mask_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_83_2 > 49)
  {
    acc_2 = ((acc_2 + (mask_83_2 * 2)) + 5) & 127;
    aux_2 ^= mask_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_83_1 == mask_83_2);
}

int fn_R000957_5713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000957_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_83 > 49)
  {
    acc = ((acc + (mask_83 * 2)) + 5) & 127;
    aux ^= mask_83 & 15;
  }
  else
  {
    acc = ((acc - mask_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000957_5713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st_1 = {0};
  struct SensorNode_R000957_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int residue_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_33_1) & 63;
  aux_2 = (aux_2 + residue_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_58_1)
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

  switch (mask_58_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_85_1 = local_arr_1[aux_1 % 3];
  int factor_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_85_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_33_1 == residue_33_2);
  assert(mask_58_1 == mask_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_85_1 == factor_85_2);
}

int fn_R000957_5713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int residue_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_33) & 63;
  acc ^= aux;
  int mask_58 = (aux + st.buffer[1]) & 3;
  switch (mask_58)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int factor_85 = local_arr[aux % 3];
  acc = (acc + (factor_85 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000957_5713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000957_5713_2 st_1 = {0};
  struct CipherContext_R000957_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_82_1 = local_arr_1[aux_1 % 3];
  int sample_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_82_2 * 2)) & 127;
  int checksum_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_84_1)
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

  switch (checksum_84_2)
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

  int factor_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_38_1) & 63;
  aux_2 = (aux_2 + factor_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_82_1 == sample_82_2);
  assert(checksum_84_1 == checksum_84_2);
  assert(factor_38_1 == factor_38_2);
}

int fn_R000957_5713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000957_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int sample_82 = local_arr[aux % 3];
  acc = (acc + (sample_82 * 2)) & 127;
  int checksum_84 = (aux + st.buffer[1]) & 3;
  switch (checksum_84)
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

  int factor_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_38) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000957_5713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000957_5713_1 st_1 = {0};
  struct Transaction_R000957_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int factor_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_73_1 > 32)
  {
    acc_1 = ((acc_1 + (factor_73_1 * 2)) + 5) & 127;
    aux_1 ^= factor_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_73_2 > 32)
  {
    acc_2 = ((acc_2 + (factor_73_2 * 2)) + 5) & 127;
    aux_2 ^= factor_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_98_1 = local_arr_1[aux_1 % 3];
  int accumulator_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_98_2 * 2)) & 127;
  int weight_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_97_1)
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

  switch (weight_97_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_73_1 == factor_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_98_1 == accumulator_98_2);
  assert(weight_97_1 == weight_97_2);
}

int fn_R000957_5713_4(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000957_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int factor_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_73 > 32)
  {
    acc = ((acc + (factor_73 * 2)) + 5) & 127;
    aux ^= factor_73 & 15;
  }
  else
  {
    acc = ((acc - factor_73) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_98 = local_arr[aux % 3];
  acc = (acc + (accumulator_98 * 2)) & 127;
  int weight_97 = (aux + st.buffer[1]) & 3;
  switch (weight_97)
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

void fn_R000957_5713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000957_5713_1 st_1 = {0};
  struct Transaction_R000957_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int quotient_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_10_1) & 63;
  aux_2 = (aux_2 + quotient_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_75_1)
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

  switch (quotient_75_2)
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
  int tracker_86_1 = local_arr_1[aux_1 % 3];
  int tracker_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_86_2 * 2)) & 127;
  int cursor_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_74_1 > 25)
  {
    acc_1 = ((acc_1 + (cursor_74_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_74_2 > 25)
  {
    acc_2 = ((acc_2 + (cursor_74_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_74_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_10_1 == quotient_10_2);
  assert(quotient_75_1 == quotient_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_86_1 == tracker_86_2);
  assert(cursor_74_1 == cursor_74_2);
}

int fn_R000957_5713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000957_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int quotient_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_10) & 63;
  acc ^= aux;
  int quotient_75 = (aux + st.buffer[1]) & 3;
  switch (quotient_75)
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
  int tracker_86 = local_arr[aux % 3];
  acc = (acc + (tracker_86 * 2)) & 127;
  int cursor_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_74 > 25)
  {
    acc = ((acc + (cursor_74 * 2)) + 5) & 127;
    aux ^= cursor_74 & 15;
  }
  else
  {
    acc = ((acc - cursor_74) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000957_5713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000957_5713_2 st_1 = {0};
  struct CipherContext_R000957_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_91_1 = local_arr_1[aux_1 % 3];
  int phase_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_91_2 * 2)) & 127;
  int metric_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_47_1)
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

  switch (metric_47_2)
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
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_91_1 == phase_91_2);
  assert(metric_47_1 == metric_47_2);
}

int fn_R000957_5713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000957_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_91 = local_arr[aux % 3];
  acc = (acc + (phase_91 * 2)) & 127;
  int metric_47 = (aux + st.buffer[1]) & 3;
  switch (metric_47)
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

void fn_R000957_5713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st_1 = {0};
  struct SensorNode_R000957_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int segment_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_98_1)
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

  switch (segment_98_2)
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

  int scale_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_93_1 > 45)
  {
    acc_1 = ((acc_1 + (scale_93_1 * 2)) + 5) & 127;
    aux_1 ^= scale_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_93_2 > 45)
  {
    acc_2 = ((acc_2 + (scale_93_2 * 2)) + 5) & 127;
    aux_2 ^= scale_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_98_1 == segment_98_2);
  assert(scale_93_1 == scale_93_2);
}

int fn_R000957_5713_7(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int segment_98 = (aux + st.buffer[1]) & 3;
  switch (segment_98)
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

  int scale_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_93 > 45)
  {
    acc = ((acc + (scale_93 * 2)) + 5) & 127;
    aux ^= scale_93 & 15;
  }
  else
  {
    acc = ((acc - scale_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000957_5713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st_1 = {0};
  struct SensorNode_R000957_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int cursor_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_75_1)
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

  switch (cursor_75_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_87_1 = local_arr_1[aux_1 % 3];
  int coefficient_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_87_2 * 2)) & 127;
  int tally_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_22_1 > 47)
  {
    acc_1 = ((acc_1 + (tally_22_1 * 2)) + 5) & 127;
    aux_1 ^= tally_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_22_2 > 47)
  {
    acc_2 = ((acc_2 + (tally_22_2 * 2)) + 5) & 127;
    aux_2 ^= tally_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_22_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_75_1 == cursor_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_87_1 == coefficient_87_2);
  assert(tally_22_1 == tally_22_2);
}

int fn_R000957_5713_8(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int cursor_75 = (aux + st.buffer[1]) & 3;
  switch (cursor_75)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_87 = local_arr[aux % 3];
  acc = (acc + (coefficient_87 * 2)) & 127;
  int tally_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_22 > 47)
  {
    acc = ((acc + (tally_22 * 2)) + 5) & 127;
    aux ^= tally_22 & 15;
  }
  else
  {
    acc = ((acc - tally_22) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000957_5713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000957_5713_1 st_1 = {0};
  struct Transaction_R000957_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_33_1 = local_arr_1[aux_1 % 3];
  int bound_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_33_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_33_1 == bound_33_2);
}

int fn_R000957_5713_9(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000957_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int bound_33 = local_arr[aux % 3];
  acc = (acc + (bound_33 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000957_5713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st_1 = {0};
  struct SensorNode_R000957_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int segment_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_10_1)
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

  switch (segment_10_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_10_1 == segment_10_2);
}

int fn_R000957_5713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int segment_10 = (aux + st.buffer[1]) & 3;
  switch (segment_10)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000957_5713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000957_5713_1 st_1 = {0};
  struct Transaction_R000957_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_83_1 = local_arr_1[aux_1 % 3];
  int window_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_83_2 * 2)) & 127;
  int margin_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_76_1 > 11)
  {
    acc_1 = ((acc_1 + (margin_76_1 * 2)) + 5) & 127;
    aux_1 ^= margin_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_76_2 > 11)
  {
    acc_2 = ((acc_2 + (margin_76_2 * 2)) + 5) & 127;
    aux_2 ^= margin_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_15_1)
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

  switch (index_reg_15_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_83_1 == window_83_2);
  assert(margin_76_1 == margin_76_2);
  assert(index_reg_15_1 == index_reg_15_2);
}

int fn_R000957_5713_11(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000957_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int window_83 = local_arr[aux % 3];
  acc = (acc + (window_83 * 2)) & 127;
  int margin_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_76 > 11)
  {
    acc = ((acc + (margin_76 * 2)) + 5) & 127;
    aux ^= margin_76 & 15;
  }
  else
  {
    acc = ((acc - margin_76) + 11) & 127;
    aux += 3;
  }
  int index_reg_15 = (aux + st.buffer[1]) & 3;
  switch (index_reg_15)
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

void fn_R000957_5713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st_1 = {0};
  struct SensorNode_R000957_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int pivot_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_92_1)
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

  switch (pivot_92_2)
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

  int bound_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_33_1 > 44)
  {
    acc_1 = ((acc_1 + (bound_33_1 * 2)) + 5) & 127;
    aux_1 ^= bound_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_33_2 > 44)
  {
    acc_2 = ((acc_2 + (bound_33_2 * 2)) + 5) & 127;
    aux_2 ^= bound_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_79_1) & 63;
  aux_2 = (aux_2 + tally_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_80_1 = local_arr_1[aux_1 % 3];
  int scale_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_92_1 == pivot_92_2);
  assert(bound_33_1 == bound_33_2);
  assert(tally_79_1 == tally_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_80_1 == scale_80_2);
}

int fn_R000957_5713_12(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int pivot_92 = (aux + st.buffer[1]) & 3;
  switch (pivot_92)
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

  int bound_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_33 > 44)
  {
    acc = ((acc + (bound_33 * 2)) + 5) & 127;
    aux ^= bound_33 & 15;
  }
  else
  {
    acc = ((acc - bound_33) + 11) & 127;
    aux += 3;
  }
  int tally_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_79) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_80 = local_arr[aux % 3];
  acc = (acc + (scale_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000957_5713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000957_5713_2 st_1 = {0};
  struct CipherContext_R000957_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int coefficient_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_83_1) & 63;
  aux_2 = (aux_2 + coefficient_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_43_1)
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

  switch (anchor_43_2)
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

  int offset_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_78_1 > 15)
  {
    acc_1 = ((acc_1 + (offset_78_1 * 2)) + 5) & 127;
    aux_1 ^= offset_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_78_2 > 15)
  {
    acc_2 = ((acc_2 + (offset_78_2 * 2)) + 5) & 127;
    aux_2 ^= offset_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_86_1 = local_arr_1[aux_1 % 3];
  int scale_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_83_1 == coefficient_83_2);
  assert(anchor_43_1 == anchor_43_2);
  assert(offset_78_1 == offset_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_86_1 == scale_86_2);
}

int fn_R000957_5713_13(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000957_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int coefficient_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_83) & 63;
  acc ^= aux;
  int anchor_43 = (aux + st.buffer[1]) & 3;
  switch (anchor_43)
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

  int offset_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_78 > 15)
  {
    acc = ((acc + (offset_78 * 2)) + 5) & 127;
    aux ^= offset_78 & 15;
  }
  else
  {
    acc = ((acc - offset_78) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int scale_86 = local_arr[aux % 3];
  acc = (acc + (scale_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000957_5713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st_1 = {0};
  struct SensorNode_R000957_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_23_1 = local_arr_1[aux_1 % 3];
  int factor_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_23_2 * 2)) & 127;
  int vector_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_20_1)
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

  switch (vector_20_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_23_1 == factor_23_2);
  assert(vector_20_1 == vector_20_2);
}

int fn_R000957_5713_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int factor_23 = local_arr[aux % 3];
  acc = (acc + (factor_23 * 2)) & 127;
  int vector_20 = (aux + st.buffer[1]) & 3;
  switch (vector_20)
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

void fn_R000957_5713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st_1 = {0};
  struct SensorNode_R000957_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int index_reg_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_97_1) & 63;
  aux_2 = (aux_2 + index_reg_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_42_1 > 27)
  {
    acc_1 = ((acc_1 + (factor_42_1 * 2)) + 5) & 127;
    aux_1 ^= factor_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_42_2 > 27)
  {
    acc_2 = ((acc_2 + (factor_42_2 * 2)) + 5) & 127;
    aux_2 ^= factor_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_97_1 == index_reg_97_2);
  assert(factor_42_1 == factor_42_2);
}

int fn_R000957_5713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int index_reg_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_97) & 63;
  acc ^= aux;
  int factor_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_42 > 27)
  {
    acc = ((acc + (factor_42 * 2)) + 5) & 127;
    aux ^= factor_42 & 15;
  }
  else
  {
    acc = ((acc - factor_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000957_5713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000957_5713_2 st_1 = {0};
  struct CipherContext_R000957_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_66_1 = local_arr_1[aux_1 % 3];
  int scale_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_66_2 * 2)) & 127;
  int metric_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_77_1)
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

  switch (metric_77_2)
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

  int stride_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_78_1 > 40)
  {
    acc_1 = ((acc_1 + (stride_78_1 * 2)) + 5) & 127;
    aux_1 ^= stride_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_78_2 > 40)
  {
    acc_2 = ((acc_2 + (stride_78_2 * 2)) + 5) & 127;
    aux_2 ^= stride_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_66_1 == scale_66_2);
  assert(metric_77_1 == metric_77_2);
  assert(stride_78_1 == stride_78_2);
}

int fn_R000957_5713_16(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000957_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int scale_66 = local_arr[aux % 3];
  acc = (acc + (scale_66 * 2)) & 127;
  int metric_77 = (aux + st.buffer[1]) & 3;
  switch (metric_77)
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

  int stride_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_78 > 40)
  {
    acc = ((acc + (stride_78 * 2)) + 5) & 127;
    aux ^= stride_78 & 15;
  }
  else
  {
    acc = ((acc - stride_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000957_5713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st_1 = {0};
  struct SensorNode_R000957_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_11_1) & 63;
  aux_2 = (aux_2 + cursor_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_11_1 == cursor_11_2);
}

int fn_R000957_5713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_11) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000957_5713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000957_5713_1 st_1 = {0};
  struct Transaction_R000957_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int scale_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_19_1)
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

  switch (scale_19_2)
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

  int stride_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_61_1 > 36)
  {
    acc_1 = ((acc_1 + (stride_61_1 * 2)) + 5) & 127;
    aux_1 ^= stride_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_61_2 > 36)
  {
    acc_2 = ((acc_2 + (stride_61_2 * 2)) + 5) & 127;
    aux_2 ^= stride_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_90_1 = local_arr_1[aux_1 % 3];
  int threshold_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_90_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_19_1 == scale_19_2);
  assert(stride_61_1 == stride_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_90_1 == threshold_90_2);
}

int fn_R000957_5713_18(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000957_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int scale_19 = (aux + st.buffer[1]) & 3;
  switch (scale_19)
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

  int stride_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_61 > 36)
  {
    acc = ((acc + (stride_61 * 2)) + 5) & 127;
    aux ^= stride_61 & 15;
  }
  else
  {
    acc = ((acc - stride_61) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_90 = local_arr[aux % 3];
  acc = (acc + (threshold_90 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000957_5713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st_1 = {0};
  struct SensorNode_R000957_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int threshold_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_56_1)
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

  switch (threshold_56_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_23_1 = local_arr_1[aux_1 % 3];
  int bound_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_23_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_56_1 == threshold_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_23_1 == bound_23_2);
}

int fn_R000957_5713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000957_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int threshold_56 = (aux + st.buffer[1]) & 3;
  switch (threshold_56)
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

  int local_arr[3] = {4, 9, 15};
  int bound_23 = local_arr[aux % 3];
  acc = (acc + (bound_23 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000957_5713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000957_5713_1 st_1 = {0};
  struct Transaction_R000957_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int threshold_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_86_1)
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

  switch (threshold_86_2)
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
  int quotient_92_1 = local_arr_1[aux_1 % 3];
  int quotient_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_92_2 * 2)) & 127;
  int vector_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_21_1) & 63;
  aux_2 = (aux_2 + vector_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_86_1 == threshold_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_92_1 == quotient_92_2);
  assert(vector_21_1 == vector_21_2);
}

int fn_R000957_5713_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000957_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int threshold_86 = (aux + st.buffer[1]) & 3;
  switch (threshold_86)
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
  int quotient_92 = local_arr[aux % 3];
  acc = (acc + (quotient_92 * 2)) & 127;
  int vector_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000957_0_1;
  int sec_r000957_0_2;
  int sec_r000957_1_1;
  int sec_r000957_1_2;
  int sec_r000957_2_1;
  int sec_r000957_2_2;
  int sec_r000957_3_1;
  int sec_r000957_3_2;
  int sec_r000957_4_1;
  int sec_r000957_4_2;
  int sec_r000957_5_1;
  int sec_r000957_5_2;
  int sec_r000957_6_1;
  int sec_r000957_6_2;
  int sec_r000957_7_1;
  int sec_r000957_7_2;
  int sec_r000957_8_1;
  int sec_r000957_8_2;
  int sec_r000957_9_1;
  int sec_r000957_9_2;
  int sec_r000957_10_1;
  int sec_r000957_10_2;
  int sec_r000957_11_1;
  int sec_r000957_11_2;
  int sec_r000957_12_1;
  int sec_r000957_12_2;
  int sec_r000957_13_1;
  int sec_r000957_13_2;
  int sec_r000957_14_1;
  int sec_r000957_14_2;
  int sec_r000957_15_1;
  int sec_r000957_15_2;
  int sec_r000957_16_1;
  int sec_r000957_16_2;
  int sec_r000957_17_1;
  int sec_r000957_17_2;
  int sec_r000957_18_1;
  int sec_r000957_18_2;
  int sec_r000957_19_1;
  int sec_r000957_19_2;
  int sec_r000957_20_1;
  int sec_r000957_20_2;
  int pub_r000957_0_1;
  int pub_r000957_0_2;
  int pub_r000957_1_1;
  int pub_r000957_1_2;
  int pub_r000957_2_1;
  int pub_r000957_2_2;
  int pub_r000957_3_1;
  int pub_r000957_3_2;
  int pub_r000957_4_1;
  int pub_r000957_4_2;
  int pub_r000957_5_1;
  int pub_r000957_5_2;
  int pub_r000957_6_1;
  int pub_r000957_6_2;
  int pub_r000957_7_1;
  int pub_r000957_7_2;
  int pub_r000957_8_1;
  int pub_r000957_8_2;
  int pub_r000957_9_1;
  int pub_r000957_9_2;
  int pub_r000957_10_1;
  int pub_r000957_10_2;
  int pub_r000957_11_1;
  int pub_r000957_11_2;
  int pub_r000957_12_1;
  int pub_r000957_12_2;
  int pub_r000957_13_1;
  int pub_r000957_13_2;
  int pub_r000957_14_1;
  int pub_r000957_14_2;
  int pub_r000957_15_1;
  int pub_r000957_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000957_0_1 >= (-100)) && (pub_r000957_0_1 <= 100));
  __CPROVER_assume((pub_r000957_0_2 >= (-100)) && (pub_r000957_0_2 <= 100));
  __CPROVER_assume((pub_r000957_1_1 >= (-100)) && (pub_r000957_1_1 <= 100));
  __CPROVER_assume((pub_r000957_1_2 >= (-100)) && (pub_r000957_1_2 <= 100));
  __CPROVER_assume((pub_r000957_2_1 >= (-100)) && (pub_r000957_2_1 <= 100));
  __CPROVER_assume((pub_r000957_2_2 >= (-100)) && (pub_r000957_2_2 <= 100));
  __CPROVER_assume((pub_r000957_3_1 >= (-100)) && (pub_r000957_3_1 <= 100));
  __CPROVER_assume((pub_r000957_3_2 >= (-100)) && (pub_r000957_3_2 <= 100));
  __CPROVER_assume((pub_r000957_4_1 >= (-100)) && (pub_r000957_4_1 <= 100));
  __CPROVER_assume((pub_r000957_4_2 >= (-100)) && (pub_r000957_4_2 <= 100));
  __CPROVER_assume((pub_r000957_5_1 >= (-100)) && (pub_r000957_5_1 <= 100));
  __CPROVER_assume((pub_r000957_5_2 >= (-100)) && (pub_r000957_5_2 <= 100));
  __CPROVER_assume((pub_r000957_6_1 >= (-100)) && (pub_r000957_6_1 <= 100));
  __CPROVER_assume((pub_r000957_6_2 >= (-100)) && (pub_r000957_6_2 <= 100));
  __CPROVER_assume((pub_r000957_7_1 >= (-100)) && (pub_r000957_7_1 <= 100));
  __CPROVER_assume((pub_r000957_7_2 >= (-100)) && (pub_r000957_7_2 <= 100));
  __CPROVER_assume((pub_r000957_8_1 >= (-100)) && (pub_r000957_8_1 <= 100));
  __CPROVER_assume((pub_r000957_8_2 >= (-100)) && (pub_r000957_8_2 <= 100));
  __CPROVER_assume((pub_r000957_9_1 >= (-100)) && (pub_r000957_9_1 <= 100));
  __CPROVER_assume((pub_r000957_9_2 >= (-100)) && (pub_r000957_9_2 <= 100));
  __CPROVER_assume((pub_r000957_10_1 >= (-100)) && (pub_r000957_10_1 <= 100));
  __CPROVER_assume((pub_r000957_10_2 >= (-100)) && (pub_r000957_10_2 <= 100));
  __CPROVER_assume((pub_r000957_11_1 >= (-100)) && (pub_r000957_11_1 <= 100));
  __CPROVER_assume((pub_r000957_11_2 >= (-100)) && (pub_r000957_11_2 <= 100));
  __CPROVER_assume((pub_r000957_12_1 >= (-100)) && (pub_r000957_12_1 <= 100));
  __CPROVER_assume((pub_r000957_12_2 >= (-100)) && (pub_r000957_12_2 <= 100));
  __CPROVER_assume((pub_r000957_13_1 >= (-100)) && (pub_r000957_13_1 <= 100));
  __CPROVER_assume((pub_r000957_13_2 >= (-100)) && (pub_r000957_13_2 <= 100));
  __CPROVER_assume((pub_r000957_14_1 >= (-100)) && (pub_r000957_14_1 <= 100));
  __CPROVER_assume((pub_r000957_14_2 >= (-100)) && (pub_r000957_14_2 <= 100));
  __CPROVER_assume((pub_r000957_15_1 >= (-100)) && (pub_r000957_15_1 <= 100));
  __CPROVER_assume((pub_r000957_15_2 >= (-100)) && (pub_r000957_15_2 <= 100));
  __CPROVER_assume((sec_r000957_0_1 >= 0) && (sec_r000957_0_1 <= 255));
  __CPROVER_assume((sec_r000957_0_2 >= 0) && (sec_r000957_0_2 <= 255));
  __CPROVER_assume((sec_r000957_1_1 >= 0) && (sec_r000957_1_1 <= 255));
  __CPROVER_assume((sec_r000957_1_2 >= 0) && (sec_r000957_1_2 <= 255));
  __CPROVER_assume((sec_r000957_2_1 >= 0) && (sec_r000957_2_1 <= 255));
  __CPROVER_assume((sec_r000957_2_2 >= 0) && (sec_r000957_2_2 <= 255));
  __CPROVER_assume((sec_r000957_3_1 >= 0) && (sec_r000957_3_1 <= 255));
  __CPROVER_assume((sec_r000957_3_2 >= 0) && (sec_r000957_3_2 <= 255));
  __CPROVER_assume((sec_r000957_4_1 >= 0) && (sec_r000957_4_1 <= 255));
  __CPROVER_assume((sec_r000957_4_2 >= 0) && (sec_r000957_4_2 <= 255));
  __CPROVER_assume((sec_r000957_5_1 >= 0) && (sec_r000957_5_1 <= 255));
  __CPROVER_assume((sec_r000957_5_2 >= 0) && (sec_r000957_5_2 <= 255));
  __CPROVER_assume((sec_r000957_6_1 >= 0) && (sec_r000957_6_1 <= 255));
  __CPROVER_assume((sec_r000957_6_2 >= 0) && (sec_r000957_6_2 <= 255));
  __CPROVER_assume((sec_r000957_7_1 >= 0) && (sec_r000957_7_1 <= 255));
  __CPROVER_assume((sec_r000957_7_2 >= 0) && (sec_r000957_7_2 <= 255));
  __CPROVER_assume((sec_r000957_8_1 >= 0) && (sec_r000957_8_1 <= 255));
  __CPROVER_assume((sec_r000957_8_2 >= 0) && (sec_r000957_8_2 <= 255));
  __CPROVER_assume((sec_r000957_9_1 >= 0) && (sec_r000957_9_1 <= 255));
  __CPROVER_assume((sec_r000957_9_2 >= 0) && (sec_r000957_9_2 <= 255));
  __CPROVER_assume((sec_r000957_10_1 >= 0) && (sec_r000957_10_1 <= 255));
  __CPROVER_assume((sec_r000957_10_2 >= 0) && (sec_r000957_10_2 <= 255));
  __CPROVER_assume((sec_r000957_11_1 >= 0) && (sec_r000957_11_1 <= 255));
  __CPROVER_assume((sec_r000957_11_2 >= 0) && (sec_r000957_11_2 <= 255));
  __CPROVER_assume((sec_r000957_12_1 >= 0) && (sec_r000957_12_1 <= 255));
  __CPROVER_assume((sec_r000957_12_2 >= 0) && (sec_r000957_12_2 <= 255));
  __CPROVER_assume((sec_r000957_13_1 >= 0) && (sec_r000957_13_1 <= 255));
  __CPROVER_assume((sec_r000957_13_2 >= 0) && (sec_r000957_13_2 <= 255));
  __CPROVER_assume((sec_r000957_14_1 >= 0) && (sec_r000957_14_1 <= 255));
  __CPROVER_assume((sec_r000957_14_2 >= 0) && (sec_r000957_14_2 <= 255));
  __CPROVER_assume((sec_r000957_15_1 >= 0) && (sec_r000957_15_1 <= 255));
  __CPROVER_assume((sec_r000957_15_2 >= 0) && (sec_r000957_15_2 <= 255));
  __CPROVER_assume((sec_r000957_16_1 >= 0) && (sec_r000957_16_1 <= 255));
  __CPROVER_assume((sec_r000957_16_2 >= 0) && (sec_r000957_16_2 <= 255));
  __CPROVER_assume((sec_r000957_17_1 >= 0) && (sec_r000957_17_1 <= 255));
  __CPROVER_assume((sec_r000957_17_2 >= 0) && (sec_r000957_17_2 <= 255));
  __CPROVER_assume((sec_r000957_18_1 >= 0) && (sec_r000957_18_1 <= 255));
  __CPROVER_assume((sec_r000957_18_2 >= 0) && (sec_r000957_18_2 <= 255));
  __CPROVER_assume((sec_r000957_19_1 >= 0) && (sec_r000957_19_1 <= 255));
  __CPROVER_assume((sec_r000957_19_2 >= 0) && (sec_r000957_19_2 <= 255));
  __CPROVER_assume((sec_r000957_20_1 >= 0) && (sec_r000957_20_1 <= 255));
  __CPROVER_assume((sec_r000957_20_2 >= 0) && (sec_r000957_20_2 <= 255));
  struct SensorNode_R000957_5713_0 st_var_0_1 = {0};
  struct SensorNode_R000957_5713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000957_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000957_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000957_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000957_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000957_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000957_0_2 + 7) & 15;
  struct Transaction_R000957_5713_1 st_var_1_1 = {0};
  struct Transaction_R000957_5713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000957_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000957_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000957_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000957_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000957_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000957_0_2 + 9) & 15;
  struct CipherContext_R000957_5713_2 st_var_2_1 = {0};
  struct CipherContext_R000957_5713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000957_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000957_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000957_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000957_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000957_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000957_0_2 + 11) & 15;
  union TelemetryField_R000957_5713_0 u_var_1;
  union TelemetryField_R000957_5713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 4) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = ((st_var_2_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_2_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 31)
    {
      chk_sum_1 ^= stage_v_5_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_5_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 31)
    {
      chk_sum_2 ^= stage_v_5_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_6_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_6_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_6_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_6_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_7_1 = ((st_var_1_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_1_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 36)
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
  if (stage_v_7_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 36)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 9) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  int stage_v_9_1 = (st_var_0_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_0_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = ((st_var_0_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_0_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 35)
    {
      chk_sum_1 ^= stage_v_15_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_15_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 35)
    {
      chk_sum_2 ^= stage_v_15_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = (st_var_2_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_2_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
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

  switch (stage_v_17_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
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

  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 21) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  int stage_v_21_1 = (st_var_0_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_0_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 24) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = (st_var_0_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_0_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
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

  switch (stage_v_27_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
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

  int stage_v_28_1 = ((st_var_1_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_1_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 41)
    {
      chk_sum_1 ^= stage_v_28_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_28_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 41)
    {
      chk_sum_2 ^= stage_v_28_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_29_1 = table_1[1];
  int stage_v_29_2 = table_2[1];
  table_1[1] = (table_1[2] + 59) & 63;
  table_2[1] = (table_2[2] + 59) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  int stage_v_31_1 = (st_var_1_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_1_2.buffer[0] ^ 34) & 3;
  switch (stage_v_31_1)
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

  switch (stage_v_31_2)
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

  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 35) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = table_1[0];
  int stage_v_36_2 = table_2[0];
  table_1[0] = (table_1[1] + 73) & 63;
  table_2[0] = (table_2[1] + 73) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_37_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (st_var_0_1.buffer[0] ^ 42) & 3;
  int stage_v_39_2 = (st_var_0_2.buffer[0] ^ 42) & 3;
  switch (stage_v_39_1)
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

  switch (stage_v_39_2)
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

  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_41_1 = ((stage_v_41_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_41_2 = ((stage_v_41_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((st_var_0_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_0_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 45)
    {
      chk_sum_1 ^= stage_v_42_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_42_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 45)
    {
      chk_sum_2 ^= stage_v_42_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 44) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_45_1 = (st_var_0_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_0_2.buffer[0] ^ 48) & 3;
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

  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 48) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 48) & 15;
  int stage_v_47_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_47_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= stage_v_47_1;
  chk_sum_2 ^= stage_v_47_2;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_49_1 = ((stage_v_49_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = table_1[2];
  int stage_v_50_2 = table_2[2];
  table_1[2] = (table_1[3] + 101) & 63;
  table_2[2] = (table_2[3] + 101) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (56 & 31);
  int stage_v_51_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (56 & 31);
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= (stage_v_51_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_51_2 << 1) & 127;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = ((st_var_0_1.buffer[0] * 2) + 169) & 63;
  int stage_v_54_2 = ((st_var_0_2.buffer[0] * 2) + 169) & 63;
  if (stage_v_54_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_54_1) - 5) & 255;
    if (stage_v_54_1 > 42)
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
  if (stage_v_54_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_54_2) - 5) & 255;
    if (stage_v_54_2 > 42)
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
  int stage_v_55_1 = ((st_var_1_1.buffer[1] * 2) + 172) & 63;
  int stage_v_55_2 = ((st_var_1_2.buffer[1] * 2) + 172) & 63;
  if (stage_v_55_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_55_1) - 5) & 255;
    if (stage_v_55_1 > 48)
    {
      chk_sum_1 ^= stage_v_55_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_55_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_55_2) - 5) & 255;
    if (stage_v_55_2 > 48)
    {
      chk_sum_2 ^= stage_v_55_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 57) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 57) & 15;
  int stage_v_56_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_56_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= stage_v_56_1;
  chk_sum_2 ^= stage_v_56_2;
  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 59) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 59) & 15;
  int stage_v_58_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_58_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= stage_v_58_1;
  chk_sum_2 ^= stage_v_58_2;
  int stage_v_59_1 = ((st_var_2_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_2_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 38)
    {
      chk_sum_1 ^= stage_v_59_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_59_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 38)
    {
      chk_sum_2 ^= stage_v_59_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_60_1 = ((stage_v_60_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_60_2 = ((stage_v_60_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (66 & 31);
  int stage_v_61_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (66 & 31);
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= (stage_v_61_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_61_2 << 1) & 127;
  int stage_v_62_1 = ((st_var_2_1.buffer[2] * 2) + 193) & 63;
  int stage_v_62_2 = ((st_var_2_2.buffer[2] * 2) + 193) & 63;
  if (stage_v_62_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_62_1) - 5) & 255;
    if (stage_v_62_1 > 53)
    {
      chk_sum_1 ^= stage_v_62_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_62_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_62_2) - 5) & 255;
    if (stage_v_62_2 > 53)
    {
      chk_sum_2 ^= stage_v_62_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_63_1 = table_1[3];
  int stage_v_63_2 = table_2[3];
  table_1[3] = (table_1[0] + 127) & 63;
  table_2[3] = (table_2[0] + 127) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000957_0_1 & 1) != 0)
  {
    if ((sec_r000957_17_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000957_10_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000957_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000957_10_1 + 7) & 127;
  }
  if ((sec_r000957_0_2 & 1) != 0)
  {
    if ((sec_r000957_17_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000957_10_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000957_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000957_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((sec_r000957_18_1 & 1) != 0)
  {
    if ((sec_r000957_16_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000957_1_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000957_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000957_1_1 + 7) & 127;
  }
  if ((sec_r000957_18_2 & 1) != 0)
  {
    if ((sec_r000957_16_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000957_1_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000957_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000957_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000957_19_1 & 1) != 0)
  {
    if ((sec_r000957_6_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000957_12_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000957_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000957_12_1 + 7) & 127;
  }
  if ((sec_r000957_19_2 & 1) != 0)
  {
    if ((sec_r000957_6_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000957_12_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000957_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000957_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000957_9_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000957_1_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000957_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000957_1_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000957_9_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000957_1_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000957_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000957_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((sec_r000957_11_1 & 1) != 0)
  {
    if ((sec_r000957_3_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000957_8_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000957_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000957_8_1 + 7) & 127;
  }
  if ((sec_r000957_11_2 & 1) != 0)
  {
    if ((sec_r000957_3_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000957_8_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000957_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000957_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000957_10_1 & 1) != 0)
  {
    if ((sec_r000957_15_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000957_15_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000957_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000957_15_1 + 7) & 127;
  }
  if ((sec_r000957_10_2 & 1) != 0)
  {
    if ((sec_r000957_15_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000957_15_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000957_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000957_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((sec_r000957_19_1 & 1) != 0)
  {
    if ((sec_r000957_7_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000957_10_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000957_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000957_10_1 + 7) & 127;
  }
  if ((sec_r000957_19_2 & 1) != 0)
  {
    if ((sec_r000957_7_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000957_10_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000957_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000957_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000957_11_1 & 1) != 0)
  {
    if ((sec_r000957_11_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000957_5_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000957_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000957_5_1 + 7) & 127;
  }
  if ((sec_r000957_11_2 & 1) != 0)
  {
    if ((sec_r000957_11_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000957_5_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000957_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000957_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000957_2_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000957_2_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000957_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000957_2_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000957_2_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000957_2_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000957_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000957_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000957_18_1 & 1) != 0)
  {
    if ((sec_r000957_2_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000957_2_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000957_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000957_2_1 + 7) & 127;
  }
  if ((sec_r000957_18_2 & 1) != 0)
  {
    if ((sec_r000957_2_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000957_2_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000957_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000957_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000957_0_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000957_6_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000957_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000957_6_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000957_0_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000957_6_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000957_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000957_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000957_17_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000957_5_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000957_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000957_5_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000957_17_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000957_5_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000957_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000957_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000957_17_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000957_10_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000957_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000957_10_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000957_17_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000957_10_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000957_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000957_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000957_7_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000957_7_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000957_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000957_7_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000957_7_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000957_7_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000957_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000957_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000957_13_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000957_13_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000957_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000957_13_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000957_13_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000957_13_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000957_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000957_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000957_20_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000957_2_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000957_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000957_2_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000957_20_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000957_2_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000957_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000957_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000957_10_1 & 1) != 0)
  {
    if ((sec_r000957_9_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000957_5_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000957_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000957_5_1 + 7) & 127;
  }
  if ((sec_r000957_10_2 & 1) != 0)
  {
    if ((sec_r000957_9_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000957_5_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000957_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000957_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000957_17_1 & 1) != 0)
  {
    if ((sec_r000957_11_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000957_9_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000957_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000957_9_1 + 7) & 127;
  }
  if ((sec_r000957_17_2 & 1) != 0)
  {
    if ((sec_r000957_11_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000957_9_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000957_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000957_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000957_8_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000957_11_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000957_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000957_11_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000957_8_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000957_11_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000957_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000957_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000957_1_1 & 1) != 0)
  {
    if ((sec_r000957_15_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000957_8_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000957_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000957_8_1 + 7) & 127;
  }
  if ((sec_r000957_1_2 & 1) != 0)
  {
    if ((sec_r000957_15_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000957_8_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000957_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000957_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000957_7_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000957_9_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000957_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000957_9_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000957_7_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000957_9_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000957_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000957_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000957_18_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000957_11_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000957_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000957_11_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000957_18_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000957_11_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000957_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000957_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000957_5_1 & 1) != 0)
  {
    if ((sec_r000957_5_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000957_14_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000957_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000957_14_1 + 7) & 127;
  }
  if ((sec_r000957_5_2 & 1) != 0)
  {
    if ((sec_r000957_5_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000957_14_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000957_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000957_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000957_7_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000957_9_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000957_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000957_9_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000957_7_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000957_9_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000957_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000957_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000957_10_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000957_15_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000957_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000957_15_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000957_10_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000957_15_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000957_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000957_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000957_6_1 & 1) != 0)
  {
    if ((sec_r000957_16_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000957_10_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000957_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000957_10_1 + 7) & 127;
  }
  if ((sec_r000957_6_2 & 1) != 0)
  {
    if ((sec_r000957_16_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000957_10_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000957_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000957_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000957_12_1 & 1) != 0)
  {
    if ((sec_r000957_2_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000957_14_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000957_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000957_14_1 + 7) & 127;
  }
  if ((sec_r000957_12_2 & 1) != 0)
  {
    if ((sec_r000957_2_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000957_14_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000957_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000957_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000957_7_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000957_2_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000957_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000957_2_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000957_7_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000957_2_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000957_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000957_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000957_1_1 & 1) != 0)
  {
    if ((sec_r000957_9_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000957_3_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000957_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000957_3_1 + 7) & 127;
  }
  if ((sec_r000957_1_2 & 1) != 0)
  {
    if ((sec_r000957_9_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000957_3_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000957_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000957_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000957_2_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000957_5_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000957_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000957_5_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000957_2_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000957_5_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000957_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000957_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000957_17_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000957_1_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000957_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000957_1_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000957_17_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000957_1_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000957_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000957_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000957_5_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000957_9_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000957_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000957_9_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000957_5_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000957_9_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000957_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000957_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000957_5_1 & 1) != 0)
  {
    if ((sec_r000957_17_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000957_10_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000957_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000957_10_1 + 7) & 127;
  }
  if ((sec_r000957_5_2 & 1) != 0)
  {
    if ((sec_r000957_17_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000957_10_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000957_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000957_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000957_14_1 & 1) != 0)
  {
    if ((sec_r000957_12_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000957_12_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000957_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000957_12_1 + 7) & 127;
  }
  if ((sec_r000957_14_2 & 1) != 0)
  {
    if ((sec_r000957_12_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000957_12_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000957_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000957_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000957_6_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000957_15_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000957_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000957_15_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000957_6_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000957_15_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000957_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000957_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000957_17_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000957_15_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000957_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000957_15_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000957_17_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000957_15_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000957_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000957_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000957_6_1 & 1) != 0)
  {
    if ((sec_r000957_14_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000957_11_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000957_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000957_11_1 + 7) & 127;
  }
  if ((sec_r000957_6_2 & 1) != 0)
  {
    if ((sec_r000957_14_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000957_11_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000957_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000957_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000957_8_1 & 1) != 0)
  {
    if ((sec_r000957_10_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000957_0_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000957_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000957_0_1 + 7) & 127;
  }
  if ((sec_r000957_8_2 & 1) != 0)
  {
    if ((sec_r000957_10_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000957_0_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000957_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000957_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000957_3_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000957_14_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000957_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000957_14_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000957_3_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000957_14_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000957_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000957_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000957_18_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000957_3_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000957_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000957_3_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000957_18_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000957_3_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000957_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000957_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000957_16_1 & 1) != 0)
  {
    if ((sec_r000957_18_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000957_10_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000957_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000957_10_1 + 7) & 127;
  }
  if ((sec_r000957_16_2 & 1) != 0)
  {
    if ((sec_r000957_18_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000957_10_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000957_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000957_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000957_12_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000957_8_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000957_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000957_8_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000957_12_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000957_8_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000957_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000957_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000957_13_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000957_5_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000957_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000957_5_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000957_13_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000957_5_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000957_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000957_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000957_8_1 & 1) != 0)
  {
    if ((sec_r000957_12_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000957_4_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000957_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000957_4_1 + 7) & 127;
  }
  if ((sec_r000957_8_2 & 1) != 0)
  {
    if ((sec_r000957_12_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000957_4_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000957_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000957_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000957_18_1 & 1) != 0)
  {
    if ((sec_r000957_14_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000957_8_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000957_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000957_8_1 + 7) & 127;
  }
  if ((sec_r000957_18_2 & 1) != 0)
  {
    if ((sec_r000957_14_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000957_8_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000957_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000957_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000957_15_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000957_10_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000957_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000957_10_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000957_15_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000957_10_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000957_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000957_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000957_10_1 & 1) != 0)
  {
    if ((sec_r000957_1_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000957_15_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000957_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000957_15_1 + 7) & 127;
  }
  if ((sec_r000957_10_2 & 1) != 0)
  {
    if ((sec_r000957_1_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000957_15_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000957_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000957_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000957_11_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000957_12_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000957_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000957_12_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000957_11_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000957_12_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000957_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000957_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000957_15_1 & 1) != 0)
  {
    if ((sec_r000957_18_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000957_2_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000957_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000957_2_1 + 7) & 127;
  }
  if ((sec_r000957_15_2 & 1) != 0)
  {
    if ((sec_r000957_18_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000957_2_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000957_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000957_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000957_11_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000957_11_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000957_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000957_11_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000957_11_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000957_11_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000957_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000957_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000957_16_1 & 1) != 0)
  {
    if ((sec_r000957_12_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000957_13_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000957_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000957_13_1 + 7) & 127;
  }
  if ((sec_r000957_16_2 & 1) != 0)
  {
    if ((sec_r000957_12_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000957_13_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000957_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000957_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000957_5_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000957_11_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000957_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000957_11_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000957_5_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000957_11_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000957_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000957_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000957_9_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000957_11_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000957_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000957_11_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000957_9_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000957_11_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000957_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000957_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000957_4_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000957_10_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000957_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000957_10_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000957_4_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000957_10_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000957_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000957_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((sec_r000957_0_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000957_12_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000957_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000957_12_1 + 7) & 127;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((sec_r000957_0_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000957_12_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000957_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000957_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000957_6_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000957_3_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000957_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000957_3_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000957_6_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000957_3_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000957_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000957_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000957_4_1 & 1) != 0)
  {
    if ((sec_r000957_8_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000957_15_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000957_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000957_15_1 + 7) & 127;
  }
  if ((sec_r000957_4_2 & 1) != 0)
  {
    if ((sec_r000957_8_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000957_15_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000957_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000957_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000957_16_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000957_0_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000957_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000957_0_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000957_16_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000957_0_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000957_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000957_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000957_14_1 & 1) != 0)
  {
    if ((sec_r000957_4_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000957_13_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000957_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000957_13_1 + 7) & 127;
  }
  if ((sec_r000957_14_2 & 1) != 0)
  {
    if ((sec_r000957_4_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000957_13_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000957_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000957_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000957_16_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000957_2_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000957_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000957_2_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000957_16_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000957_2_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000957_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000957_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000957_0_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000957_13_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000957_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000957_13_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000957_0_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000957_13_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000957_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000957_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000957_2_1 & 1) != 0)
  {
    if ((sec_r000957_5_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000957_0_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000957_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000957_0_1 + 7) & 127;
  }
  if ((sec_r000957_2_2 & 1) != 0)
  {
    if ((sec_r000957_5_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000957_0_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000957_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000957_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000957_10_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000957_2_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000957_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000957_2_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000957_10_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000957_2_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000957_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000957_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000957_18_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000957_13_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000957_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000957_13_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000957_18_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000957_13_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000957_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000957_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000957_20_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000957_7_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000957_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000957_7_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000957_20_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000957_7_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000957_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000957_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000957_10_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000957_7_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000957_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000957_7_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000957_10_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000957_7_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000957_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000957_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000957_11_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000957_15_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000957_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000957_15_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000957_11_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000957_15_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000957_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000957_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000957_8_1 & 1) != 0)
  {
    if ((sec_r000957_14_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000957_8_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000957_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000957_8_1 + 7) & 127;
  }
  if ((sec_r000957_8_2 & 1) != 0)
  {
    if ((sec_r000957_14_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000957_8_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000957_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000957_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000957_19_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000957_9_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000957_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000957_9_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000957_19_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000957_9_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000957_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000957_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000957_2_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000957_7_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000957_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000957_7_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000957_2_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000957_7_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000957_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000957_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000957_0_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000957_5_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000957_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000957_5_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000957_0_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000957_5_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000957_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000957_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000957_13_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000957_2_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000957_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000957_2_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000957_13_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000957_2_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000957_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000957_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000957_18_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000957_9_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000957_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000957_9_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000957_18_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000957_9_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000957_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000957_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000957_1_1 != sec_r000957_1_2);
  __CPROVER_assume(sec_r000957_19_1 != sec_r000957_19_2);
  __CPROVER_assume(pub_r000957_12_1 == pub_r000957_12_2);
  __CPROVER_assume(sec_r000957_10_1 != sec_r000957_10_2);
  __CPROVER_assume(sec_r000957_3_1 != sec_r000957_3_2);
  __CPROVER_assume(sec_r000957_7_1 != sec_r000957_7_2);
  __CPROVER_assume(pub_r000957_7_1 == pub_r000957_7_2);
  __CPROVER_assume(sec_r000957_17_1 != sec_r000957_17_2);
  __CPROVER_assume(pub_r000957_5_1 == pub_r000957_5_2);
  __CPROVER_assume(pub_r000957_0_1 == pub_r000957_0_2);
  __CPROVER_assume(pub_r000957_15_1 == pub_r000957_15_2);
  __CPROVER_assume(sec_r000957_14_1 != sec_r000957_14_2);
  __CPROVER_assume(sec_r000957_13_1 != sec_r000957_13_2);
  __CPROVER_assume(sec_r000957_16_1 != sec_r000957_16_2);
  __CPROVER_assume(sec_r000957_11_1 != sec_r000957_11_2);
  __CPROVER_assume(sec_r000957_2_1 != sec_r000957_2_2);
  __CPROVER_assume(sec_r000957_6_1 != sec_r000957_6_2);
  __CPROVER_assume(pub_r000957_8_1 == pub_r000957_8_2);
  __CPROVER_assume(pub_r000957_13_1 == pub_r000957_13_2);
  __CPROVER_assume(sec_r000957_5_1 != sec_r000957_5_2);
  __CPROVER_assume(pub_r000957_10_1 == pub_r000957_10_2);
  __CPROVER_assume(pub_r000957_4_1 == pub_r000957_4_2);
  __CPROVER_assume(sec_r000957_20_1 != sec_r000957_20_2);
  __CPROVER_assume(sec_r000957_12_1 != sec_r000957_12_2);
  __CPROVER_assume(sec_r000957_8_1 != sec_r000957_8_2);
  __CPROVER_assume(pub_r000957_2_1 == pub_r000957_2_2);
  __CPROVER_assume(pub_r000957_6_1 == pub_r000957_6_2);
  __CPROVER_assume(pub_r000957_14_1 == pub_r000957_14_2);
  __CPROVER_assume(pub_r000957_3_1 == pub_r000957_3_2);
  __CPROVER_assume(pub_r000957_11_1 == pub_r000957_11_2);
  __CPROVER_assume(sec_r000957_15_1 != sec_r000957_15_2);
  __CPROVER_assume(pub_r000957_1_1 == pub_r000957_1_2);
  __CPROVER_assume(sec_r000957_4_1 != sec_r000957_4_2);
  __CPROVER_assume(pub_r000957_9_1 == pub_r000957_9_2);
  __CPROVER_assume(sec_r000957_18_1 != sec_r000957_18_2);
  __CPROVER_assume(sec_r000957_9_1 != sec_r000957_9_2);
  __CPROVER_assume(sec_r000957_0_1 != sec_r000957_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.flags == st_var_2_2.flags);
  assert(st_var_2_1.nonce == st_var_2_2.nonce);
  assert(st_var_2_1.tag == st_var_2_2.tag);
  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.round_key == st_var_2_2.round_key);
  assert(st_var_2_1.counter == st_var_2_2.counter);
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
}


