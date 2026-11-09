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
struct EventLog_R001911_1113_0
{
  short code;
  short severity;
  int facility;
  short signature;
  int buffer[3];
};
struct Transaction_R001911_1113_1
{
  int fee;
  int rate;
  short auth_code;
  unsigned char balance;
  int buffer[3];
};
struct DeviceConfig_R001911_1113_2
{
  int timeout;
  int stop_bits;
  short id;
  int buffer[3];
};
union TelemetryField_R001911_1113_0
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
void fn_R001911_1113_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st_1 = {0};
  struct Transaction_R001911_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_78_1 = local_arr_1[aux_1 % 3];
  int residue_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_78_2 * 2)) & 127;
  int vector_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_60_1) & 63;
  aux_2 = (aux_2 + vector_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_46_1 > 10)
  {
    acc_1 = ((acc_1 + (margin_46_1 * 2)) + 5) & 127;
    aux_1 ^= margin_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_46_2 > 10)
  {
    acc_2 = ((acc_2 + (margin_46_2 * 2)) + 5) & 127;
    aux_2 ^= margin_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
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

  assert(residue_78_1 == residue_78_2);
  assert(vector_60_1 == vector_60_2);
  assert(margin_46_1 == margin_46_2);
}

int fn_R001911_1113_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int residue_78 = local_arr[aux % 3];
  acc = (acc + (residue_78 * 2)) & 127;
  int vector_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_60) & 63;
  acc ^= aux;
  int margin_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_46 > 10)
  {
    acc = ((acc + (margin_46 * 2)) + 5) & 127;
    aux ^= margin_46 & 15;
  }
  else
  {
    acc = ((acc - margin_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001911_1113_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st_1 = {0};
  struct Transaction_R001911_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int bound_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_76_1 > 35)
  {
    acc_1 = ((acc_1 + (bound_76_1 * 2)) + 5) & 127;
    aux_1 ^= bound_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_76_2 > 35)
  {
    acc_2 = ((acc_2 + (bound_76_2 * 2)) + 5) & 127;
    aux_2 ^= bound_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_34_1)
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

  switch (anchor_34_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_76_1 == bound_76_2);
  assert(anchor_34_1 == anchor_34_2);
}

int fn_R001911_1113_1(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int bound_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_76 > 35)
  {
    acc = ((acc + (bound_76 * 2)) + 5) & 127;
    aux ^= bound_76 & 15;
  }
  else
  {
    acc = ((acc - bound_76) + 11) & 127;
    aux += 3;
  }
  int anchor_34 = (aux + st.buffer[1]) & 3;
  switch (anchor_34)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001911_1113_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001911_1113_2 st_1 = {0};
  struct DeviceConfig_R001911_1113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int threshold_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_45_1 > 10)
  {
    acc_1 = ((acc_1 + (threshold_45_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_45_2 > 10)
  {
    acc_2 = ((acc_2 + (threshold_45_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_45_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_12_1) & 63;
  aux_2 = (aux_2 + window_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_72_1 = 0;
  int mask_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_72_1 = ((mask_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_72_2 = ((mask_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_72_1) & 127;
    acc_2 = (acc_2 + mask_72_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_45_1 == threshold_45_2);
  assert(window_12_1 == window_12_2);
  assert(mask_72_1 == mask_72_2);
}

int fn_R001911_1113_2(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001911_1113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int threshold_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_45 > 10)
  {
    acc = ((acc + (threshold_45 * 2)) + 5) & 127;
    aux ^= threshold_45 & 15;
  }
  else
  {
    acc = ((acc - threshold_45) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_12) & 63;
  acc ^= aux;
  int mask_72 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_72 = ((mask_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_72) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001911_1113_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st_1 = {0};
  struct Transaction_R001911_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int weight_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_89_1 > 34)
  {
    acc_1 = ((acc_1 + (weight_89_1 * 2)) + 5) & 127;
    aux_1 ^= weight_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_89_2 > 34)
  {
    acc_2 = ((acc_2 + (weight_89_2 * 2)) + 5) & 127;
    aux_2 ^= weight_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_31_1 = 0;
  int damping_31_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_31_1 = ((damping_31_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_31_2 = ((damping_31_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_31_1) & 127;
    acc_2 = (acc_2 + damping_31_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_89_1 == weight_89_2);
  assert(damping_31_1 == damping_31_2);
}

int fn_R001911_1113_3(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int weight_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_89 > 34)
  {
    acc = ((acc + (weight_89 * 2)) + 5) & 127;
    aux ^= weight_89 & 15;
  }
  else
  {
    acc = ((acc - weight_89) + 11) & 127;
    aux += 3;
  }
  int damping_31 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_31 = ((damping_31 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_31) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001911_1113_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001911_1113_0 st_1 = {0};
  struct EventLog_R001911_1113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int damping_98_1 = 0;
  int damping_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_98_1 = ((damping_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_98_2 = ((damping_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_98_1) & 127;
    acc_2 = (acc_2 + damping_98_2) & 127;
  }

  int tally_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_19_1 > 41)
  {
    acc_1 = ((acc_1 + (tally_19_1 * 2)) + 5) & 127;
    aux_1 ^= tally_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_19_2 > 41)
  {
    acc_2 = ((acc_2 + (tally_19_2 * 2)) + 5) & 127;
    aux_2 ^= tally_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_60_1 = local_arr_1[aux_1 % 3];
  int delta_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_60_2 * 2)) & 127;
  int checksum_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_37_1) & 63;
  aux_2 = (aux_2 + checksum_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_98_1 == damping_98_2);
  assert(tally_19_1 == tally_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_60_1 == delta_60_2);
  assert(checksum_37_1 == checksum_37_2);
}

int fn_R001911_1113_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001911_1113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int damping_98 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_98 = ((damping_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_98) & 127;
  }

  int tally_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_19 > 41)
  {
    acc = ((acc + (tally_19 * 2)) + 5) & 127;
    aux ^= tally_19 & 15;
  }
  else
  {
    acc = ((acc - tally_19) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_60 = local_arr[aux % 3];
  acc = (acc + (delta_60 * 2)) & 127;
  int checksum_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_37) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001911_1113_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001911_1113_0 st_1 = {0};
  struct EventLog_R001911_1113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int cursor_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_23_1)
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

  switch (cursor_23_2)
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

  int window_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_49_1) & 63;
  aux_2 = (aux_2 + window_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_32_1 = local_arr_1[aux_1 % 3];
  int tally_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_23_1 == cursor_23_2);
  assert(window_49_1 == window_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_32_1 == tally_32_2);
}

int fn_R001911_1113_5(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001911_1113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int cursor_23 = (aux + st.buffer[1]) & 3;
  switch (cursor_23)
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

  int window_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_49) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_32 = local_arr[aux % 3];
  acc = (acc + (tally_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001911_1113_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001911_1113_2 st_1 = {0};
  struct DeviceConfig_R001911_1113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_91_1 = local_arr_1[aux_1 % 3];
  int coefficient_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_91_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_77_1)
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

  switch (delta_77_2)
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

  int stride_95_1 = 0;
  int stride_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_95_1 = ((stride_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_95_2 = ((stride_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_95_1) & 127;
    acc_2 = (acc_2 + stride_95_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_91_1 == coefficient_91_2);
  assert(delta_77_1 == delta_77_2);
  assert(stride_95_1 == stride_95_2);
}

int fn_R001911_1113_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001911_1113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int coefficient_91 = local_arr[aux % 3];
  acc = (acc + (coefficient_91 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_77 = (aux + st.buffer[1]) & 3;
  switch (delta_77)
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

  int stride_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_95 = ((stride_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_95) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001911_1113_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st_1 = {0};
  struct Transaction_R001911_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int threshold_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_42_1)
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

  switch (threshold_42_2)
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

  int mask_86_1 = 0;
  int mask_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_86_1 = ((mask_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_86_2 = ((mask_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_86_1) & 127;
    acc_2 = (acc_2 + mask_86_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_42_1 == threshold_42_2);
  assert(mask_86_1 == mask_86_2);
}

int fn_R001911_1113_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int threshold_42 = (aux + st.buffer[1]) & 3;
  switch (threshold_42)
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

  int mask_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_86 = ((mask_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_86) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001911_1113_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001911_1113_2 st_1 = {0};
  struct DeviceConfig_R001911_1113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int quotient_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_63_1 > 10)
  {
    acc_1 = ((acc_1 + (quotient_63_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_63_2 > 10)
  {
    acc_2 = ((acc_2 + (quotient_63_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_72_1)
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

  switch (sample_72_2)
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

  int weight_75_1 = 0;
  int weight_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_75_1 = ((weight_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_75_2 = ((weight_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_75_1) & 127;
    acc_2 = (acc_2 + weight_75_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_63_1 == quotient_63_2);
  assert(sample_72_1 == sample_72_2);
  assert(weight_75_1 == weight_75_2);
}

int fn_R001911_1113_8(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001911_1113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int quotient_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_63 > 10)
  {
    acc = ((acc + (quotient_63 * 2)) + 5) & 127;
    aux ^= quotient_63 & 15;
  }
  else
  {
    acc = ((acc - quotient_63) + 11) & 127;
    aux += 3;
  }
  int sample_72 = (aux + st.buffer[1]) & 3;
  switch (sample_72)
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

  int weight_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_75 = ((weight_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_75) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001911_1113_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st_1 = {0};
  struct Transaction_R001911_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int anchor_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_43_1)
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

  switch (anchor_43_2)
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

  int tracker_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_79_1 > 50)
  {
    acc_1 = ((acc_1 + (tracker_79_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_79_2 > 50)
  {
    acc_2 = ((acc_2 + (tracker_79_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_79_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_43_1 == anchor_43_2);
  assert(tracker_79_1 == tracker_79_2);
}

int fn_R001911_1113_9(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int anchor_43 = (aux + st.buffer[1]) & 3;
  switch (anchor_43)
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

  int tracker_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_79 > 50)
  {
    acc = ((acc + (tracker_79 * 2)) + 5) & 127;
    aux ^= tracker_79 & 15;
  }
  else
  {
    acc = ((acc - tracker_79) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001911_1113_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st_1 = {0};
  struct Transaction_R001911_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int cursor_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_36_1 > 34)
  {
    acc_1 = ((acc_1 + (cursor_36_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_36_2 > 34)
  {
    acc_2 = ((acc_2 + (cursor_36_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_99_1)
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

  switch (cursor_99_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_36_1 == cursor_36_2);
  assert(cursor_99_1 == cursor_99_2);
}

int fn_R001911_1113_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int cursor_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_36 > 34)
  {
    acc = ((acc + (cursor_36 * 2)) + 5) & 127;
    aux ^= cursor_36 & 15;
  }
  else
  {
    acc = ((acc - cursor_36) + 11) & 127;
    aux += 3;
  }
  int cursor_99 = (aux + st.buffer[1]) & 3;
  switch (cursor_99)
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

void fn_R001911_1113_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001911_1113_2 st_1 = {0};
  struct DeviceConfig_R001911_1113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_79_1 = local_arr_1[aux_1 % 3];
  int quotient_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_79_2 * 2)) & 127;
  int tracker_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_66_1)
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

  switch (tracker_66_2)
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

  int quotient_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_61_1) & 63;
  aux_2 = (aux_2 + quotient_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_79_1 == quotient_79_2);
  assert(tracker_66_1 == tracker_66_2);
  assert(quotient_61_1 == quotient_61_2);
}

int fn_R001911_1113_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001911_1113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int quotient_79 = local_arr[aux % 3];
  acc = (acc + (quotient_79 * 2)) & 127;
  int tracker_66 = (aux + st.buffer[1]) & 3;
  switch (tracker_66)
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

  int quotient_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_61) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001911_1113_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001911_1113_0 st_1 = {0};
  struct EventLog_R001911_1113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int tally_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_18_1)
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

  switch (tally_18_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_60_1 > 42)
  {
    acc_1 = ((acc_1 + (quantum_60_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_60_2 > 42)
  {
    acc_2 = ((acc_2 + (quantum_60_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_20_1 = local_arr_1[aux_1 % 3];
  int residue_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_20_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_18_1 == tally_18_2);
  assert(quantum_60_1 == quantum_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_20_1 == residue_20_2);
}

int fn_R001911_1113_12(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001911_1113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int tally_18 = (aux + st.buffer[1]) & 3;
  switch (tally_18)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_60 > 42)
  {
    acc = ((acc + (quantum_60 * 2)) + 5) & 127;
    aux ^= quantum_60 & 15;
  }
  else
  {
    acc = ((acc - quantum_60) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_20 = local_arr[aux % 3];
  acc = (acc + (residue_20 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001911_1113_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001911_1113_0 st_1 = {0};
  struct EventLog_R001911_1113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int metric_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_93_1 > 43)
  {
    acc_1 = ((acc_1 + (metric_93_1 * 2)) + 5) & 127;
    aux_1 ^= metric_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_93_2 > 43)
  {
    acc_2 = ((acc_2 + (metric_93_2 * 2)) + 5) & 127;
    aux_2 ^= metric_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_93_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_50_1)
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

  switch (scale_50_2)
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

  int cursor_25_1 = 0;
  int cursor_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_25_1 = ((cursor_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_25_2 = ((cursor_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_25_1) & 127;
    acc_2 = (acc_2 + cursor_25_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_93_1 == metric_93_2);
  assert(scale_50_1 == scale_50_2);
  assert(cursor_25_1 == cursor_25_2);
}

int fn_R001911_1113_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001911_1113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int metric_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_93 > 43)
  {
    acc = ((acc + (metric_93 * 2)) + 5) & 127;
    aux ^= metric_93 & 15;
  }
  else
  {
    acc = ((acc - metric_93) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_50 = (aux + st.buffer[1]) & 3;
  switch (scale_50)
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

  int cursor_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_25 = ((cursor_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_25) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001911_1113_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st_1 = {0};
  struct Transaction_R001911_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int metric_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_62_1 > 27)
  {
    acc_1 = ((acc_1 + (metric_62_1 * 2)) + 5) & 127;
    aux_1 ^= metric_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_62_2 > 27)
  {
    acc_2 = ((acc_2 + (metric_62_2 * 2)) + 5) & 127;
    aux_2 ^= metric_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_17_1) & 63;
  aux_2 = (aux_2 + offset_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_23_1 = 0;
  int margin_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_23_1 = ((margin_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_23_2 = ((margin_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_23_1) & 127;
    acc_2 = (acc_2 + margin_23_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_62_1 == metric_62_2);
  assert(offset_17_1 == offset_17_2);
  assert(margin_23_1 == margin_23_2);
}

int fn_R001911_1113_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int metric_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_62 > 27)
  {
    acc = ((acc + (metric_62 * 2)) + 5) & 127;
    aux ^= metric_62 & 15;
  }
  else
  {
    acc = ((acc - metric_62) + 11) & 127;
    aux += 3;
  }
  int offset_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_17) & 63;
  acc ^= aux;
  int margin_23 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_23 = ((margin_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_23) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001911_1113_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st_1 = {0};
  struct Transaction_R001911_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_95_1 = local_arr_1[aux_1 % 3];
  int offset_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_95_2 * 2)) & 127;
  int index_reg_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_26_1 > 19)
  {
    acc_1 = ((acc_1 + (index_reg_26_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_26_2 > 19)
  {
    acc_2 = ((acc_2 + (index_reg_26_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_63_1) & 63;
  aux_2 = (aux_2 + delta_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
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

  assert(offset_95_1 == offset_95_2);
  assert(index_reg_26_1 == index_reg_26_2);
  assert(delta_63_1 == delta_63_2);
}

int fn_R001911_1113_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int offset_95 = local_arr[aux % 3];
  acc = (acc + (offset_95 * 2)) & 127;
  int index_reg_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_26 > 19)
  {
    acc = ((acc + (index_reg_26 * 2)) + 5) & 127;
    aux ^= index_reg_26 & 15;
  }
  else
  {
    acc = ((acc - index_reg_26) + 11) & 127;
    aux += 3;
  }
  int delta_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_63) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001911_1113_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001911_1113_2 st_1 = {0};
  struct DeviceConfig_R001911_1113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_47_1 = local_arr_1[aux_1 % 3];
  int margin_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_47_2 * 2)) & 127;
  int residue_72_1 = 0;
  int residue_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_72_1 = ((residue_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_72_2 = ((residue_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_72_1) & 127;
    acc_2 = (acc_2 + residue_72_2) & 127;
  }

  int pivot_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_92_1) & 63;
  aux_2 = (aux_2 + pivot_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_23_1 > 42)
  {
    acc_1 = ((acc_1 + (stride_23_1 * 2)) + 5) & 127;
    aux_1 ^= stride_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_23_2 > 42)
  {
    acc_2 = ((acc_2 + (stride_23_2 * 2)) + 5) & 127;
    aux_2 ^= stride_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_23_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_47_1 == margin_47_2);
  assert(residue_72_1 == residue_72_2);
  assert(pivot_92_1 == pivot_92_2);
  assert(stride_23_1 == stride_23_2);
}

int fn_R001911_1113_16(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001911_1113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int margin_47 = local_arr[aux % 3];
  acc = (acc + (margin_47 * 2)) & 127;
  int residue_72 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_72 = ((residue_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_72) & 127;
  }

  int pivot_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_92) & 63;
  acc ^= aux;
  int stride_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_23 > 42)
  {
    acc = ((acc + (stride_23 * 2)) + 5) & 127;
    aux ^= stride_23 & 15;
  }
  else
  {
    acc = ((acc - stride_23) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001911_1113_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001911_1113_2 st_1 = {0};
  struct DeviceConfig_R001911_1113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int pivot_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_62_1)
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

  switch (pivot_62_2)
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

  int phase_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_55_1) & 63;
  aux_2 = (aux_2 + phase_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_36_1 = 0;
  int parity_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_36_1 = ((parity_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_36_2 = ((parity_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_36_1) & 127;
    acc_2 = (acc_2 + parity_36_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_32_1 = local_arr_1[aux_1 % 3];
  int quotient_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_62_1 == pivot_62_2);
  assert(phase_55_1 == phase_55_2);
  assert(parity_36_1 == parity_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_32_1 == quotient_32_2);
}

int fn_R001911_1113_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001911_1113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int pivot_62 = (aux + st.buffer[1]) & 3;
  switch (pivot_62)
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

  int phase_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_55) & 63;
  acc ^= aux;
  int parity_36 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_36 = ((parity_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_36) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quotient_32 = local_arr[aux % 3];
  acc = (acc + (quotient_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001911_1113_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st_1 = {0};
  struct Transaction_R001911_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int tally_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_62_1)
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

  switch (tally_62_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_62_1 == tally_62_2);
}

int fn_R001911_1113_18(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001911_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int tally_62 = (aux + st.buffer[1]) & 3;
  switch (tally_62)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001911_1113_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001911_1113_2 st_1 = {0};
  struct DeviceConfig_R001911_1113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_38_1 = local_arr_1[aux_1 % 3];
  int mask_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_38_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_38_1 == mask_38_2);
}

int fn_R001911_1113_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001911_1113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int mask_38 = local_arr[aux % 3];
  acc = (acc + (mask_38 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001911_0_1;
  int sec_r001911_0_2;
  int sec_r001911_1_1;
  int sec_r001911_1_2;
  int sec_r001911_2_1;
  int sec_r001911_2_2;
  int sec_r001911_3_1;
  int sec_r001911_3_2;
  int sec_r001911_4_1;
  int sec_r001911_4_2;
  int sec_r001911_5_1;
  int sec_r001911_5_2;
  int sec_r001911_6_1;
  int sec_r001911_6_2;
  int sec_r001911_7_1;
  int sec_r001911_7_2;
  int sec_r001911_8_1;
  int sec_r001911_8_2;
  int sec_r001911_9_1;
  int sec_r001911_9_2;
  int sec_r001911_10_1;
  int sec_r001911_10_2;
  int sec_r001911_11_1;
  int sec_r001911_11_2;
  int sec_r001911_12_1;
  int sec_r001911_12_2;
  int sec_r001911_13_1;
  int sec_r001911_13_2;
  int sec_r001911_14_1;
  int sec_r001911_14_2;
  int sec_r001911_15_1;
  int sec_r001911_15_2;
  int sec_r001911_16_1;
  int sec_r001911_16_2;
  int sec_r001911_17_1;
  int sec_r001911_17_2;
  int sec_r001911_18_1;
  int sec_r001911_18_2;
  int pub_r001911_0_1;
  int pub_r001911_0_2;
  int pub_r001911_1_1;
  int pub_r001911_1_2;
  int pub_r001911_2_1;
  int pub_r001911_2_2;
  int pub_r001911_3_1;
  int pub_r001911_3_2;
  int pub_r001911_4_1;
  int pub_r001911_4_2;
  int pub_r001911_5_1;
  int pub_r001911_5_2;
  int pub_r001911_6_1;
  int pub_r001911_6_2;
  int pub_r001911_7_1;
  int pub_r001911_7_2;
  int pub_r001911_8_1;
  int pub_r001911_8_2;
  int pub_r001911_9_1;
  int pub_r001911_9_2;
  int pub_r001911_10_1;
  int pub_r001911_10_2;
  int pub_r001911_11_1;
  int pub_r001911_11_2;
  int pub_r001911_12_1;
  int pub_r001911_12_2;
  int pub_r001911_13_1;
  int pub_r001911_13_2;
  int pub_r001911_14_1;
  int pub_r001911_14_2;
  int pub_r001911_15_1;
  int pub_r001911_15_2;
  int pub_r001911_16_1;
  int pub_r001911_16_2;
  int pub_r001911_17_1;
  int pub_r001911_17_2;
  int pub_r001911_18_1;
  int pub_r001911_18_2;
  int pub_r001911_19_1;
  int pub_r001911_19_2;
  int pub_r001911_20_1;
  int pub_r001911_20_2;
  int pub_r001911_21_1;
  int pub_r001911_21_2;
  int pub_r001911_22_1;
  int pub_r001911_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001911_0_1 >= (-100)) && (pub_r001911_0_1 <= 100));
  __CPROVER_assume((pub_r001911_0_2 >= (-100)) && (pub_r001911_0_2 <= 100));
  __CPROVER_assume((pub_r001911_1_1 >= (-100)) && (pub_r001911_1_1 <= 100));
  __CPROVER_assume((pub_r001911_1_2 >= (-100)) && (pub_r001911_1_2 <= 100));
  __CPROVER_assume((pub_r001911_2_1 >= (-100)) && (pub_r001911_2_1 <= 100));
  __CPROVER_assume((pub_r001911_2_2 >= (-100)) && (pub_r001911_2_2 <= 100));
  __CPROVER_assume((pub_r001911_3_1 >= (-100)) && (pub_r001911_3_1 <= 100));
  __CPROVER_assume((pub_r001911_3_2 >= (-100)) && (pub_r001911_3_2 <= 100));
  __CPROVER_assume((pub_r001911_4_1 >= (-100)) && (pub_r001911_4_1 <= 100));
  __CPROVER_assume((pub_r001911_4_2 >= (-100)) && (pub_r001911_4_2 <= 100));
  __CPROVER_assume((pub_r001911_5_1 >= (-100)) && (pub_r001911_5_1 <= 100));
  __CPROVER_assume((pub_r001911_5_2 >= (-100)) && (pub_r001911_5_2 <= 100));
  __CPROVER_assume((pub_r001911_6_1 >= (-100)) && (pub_r001911_6_1 <= 100));
  __CPROVER_assume((pub_r001911_6_2 >= (-100)) && (pub_r001911_6_2 <= 100));
  __CPROVER_assume((pub_r001911_7_1 >= (-100)) && (pub_r001911_7_1 <= 100));
  __CPROVER_assume((pub_r001911_7_2 >= (-100)) && (pub_r001911_7_2 <= 100));
  __CPROVER_assume((pub_r001911_8_1 >= (-100)) && (pub_r001911_8_1 <= 100));
  __CPROVER_assume((pub_r001911_8_2 >= (-100)) && (pub_r001911_8_2 <= 100));
  __CPROVER_assume((pub_r001911_9_1 >= (-100)) && (pub_r001911_9_1 <= 100));
  __CPROVER_assume((pub_r001911_9_2 >= (-100)) && (pub_r001911_9_2 <= 100));
  __CPROVER_assume((pub_r001911_10_1 >= (-100)) && (pub_r001911_10_1 <= 100));
  __CPROVER_assume((pub_r001911_10_2 >= (-100)) && (pub_r001911_10_2 <= 100));
  __CPROVER_assume((pub_r001911_11_1 >= (-100)) && (pub_r001911_11_1 <= 100));
  __CPROVER_assume((pub_r001911_11_2 >= (-100)) && (pub_r001911_11_2 <= 100));
  __CPROVER_assume((pub_r001911_12_1 >= (-100)) && (pub_r001911_12_1 <= 100));
  __CPROVER_assume((pub_r001911_12_2 >= (-100)) && (pub_r001911_12_2 <= 100));
  __CPROVER_assume((pub_r001911_13_1 >= (-100)) && (pub_r001911_13_1 <= 100));
  __CPROVER_assume((pub_r001911_13_2 >= (-100)) && (pub_r001911_13_2 <= 100));
  __CPROVER_assume((pub_r001911_14_1 >= (-100)) && (pub_r001911_14_1 <= 100));
  __CPROVER_assume((pub_r001911_14_2 >= (-100)) && (pub_r001911_14_2 <= 100));
  __CPROVER_assume((pub_r001911_15_1 >= (-100)) && (pub_r001911_15_1 <= 100));
  __CPROVER_assume((pub_r001911_15_2 >= (-100)) && (pub_r001911_15_2 <= 100));
  __CPROVER_assume((pub_r001911_16_1 >= (-100)) && (pub_r001911_16_1 <= 100));
  __CPROVER_assume((pub_r001911_16_2 >= (-100)) && (pub_r001911_16_2 <= 100));
  __CPROVER_assume((pub_r001911_17_1 >= (-100)) && (pub_r001911_17_1 <= 100));
  __CPROVER_assume((pub_r001911_17_2 >= (-100)) && (pub_r001911_17_2 <= 100));
  __CPROVER_assume((pub_r001911_18_1 >= (-100)) && (pub_r001911_18_1 <= 100));
  __CPROVER_assume((pub_r001911_18_2 >= (-100)) && (pub_r001911_18_2 <= 100));
  __CPROVER_assume((pub_r001911_19_1 >= (-100)) && (pub_r001911_19_1 <= 100));
  __CPROVER_assume((pub_r001911_19_2 >= (-100)) && (pub_r001911_19_2 <= 100));
  __CPROVER_assume((pub_r001911_20_1 >= (-100)) && (pub_r001911_20_1 <= 100));
  __CPROVER_assume((pub_r001911_20_2 >= (-100)) && (pub_r001911_20_2 <= 100));
  __CPROVER_assume((pub_r001911_21_1 >= (-100)) && (pub_r001911_21_1 <= 100));
  __CPROVER_assume((pub_r001911_21_2 >= (-100)) && (pub_r001911_21_2 <= 100));
  __CPROVER_assume((pub_r001911_22_1 >= (-100)) && (pub_r001911_22_1 <= 100));
  __CPROVER_assume((pub_r001911_22_2 >= (-100)) && (pub_r001911_22_2 <= 100));
  __CPROVER_assume((sec_r001911_0_1 >= 0) && (sec_r001911_0_1 <= 255));
  __CPROVER_assume((sec_r001911_0_2 >= 0) && (sec_r001911_0_2 <= 255));
  __CPROVER_assume((sec_r001911_1_1 >= 0) && (sec_r001911_1_1 <= 255));
  __CPROVER_assume((sec_r001911_1_2 >= 0) && (sec_r001911_1_2 <= 255));
  __CPROVER_assume((sec_r001911_2_1 >= 0) && (sec_r001911_2_1 <= 255));
  __CPROVER_assume((sec_r001911_2_2 >= 0) && (sec_r001911_2_2 <= 255));
  __CPROVER_assume((sec_r001911_3_1 >= 0) && (sec_r001911_3_1 <= 255));
  __CPROVER_assume((sec_r001911_3_2 >= 0) && (sec_r001911_3_2 <= 255));
  __CPROVER_assume((sec_r001911_4_1 >= 0) && (sec_r001911_4_1 <= 255));
  __CPROVER_assume((sec_r001911_4_2 >= 0) && (sec_r001911_4_2 <= 255));
  __CPROVER_assume((sec_r001911_5_1 >= 0) && (sec_r001911_5_1 <= 255));
  __CPROVER_assume((sec_r001911_5_2 >= 0) && (sec_r001911_5_2 <= 255));
  __CPROVER_assume((sec_r001911_6_1 >= 0) && (sec_r001911_6_1 <= 255));
  __CPROVER_assume((sec_r001911_6_2 >= 0) && (sec_r001911_6_2 <= 255));
  __CPROVER_assume((sec_r001911_7_1 >= 0) && (sec_r001911_7_1 <= 255));
  __CPROVER_assume((sec_r001911_7_2 >= 0) && (sec_r001911_7_2 <= 255));
  __CPROVER_assume((sec_r001911_8_1 >= 0) && (sec_r001911_8_1 <= 255));
  __CPROVER_assume((sec_r001911_8_2 >= 0) && (sec_r001911_8_2 <= 255));
  __CPROVER_assume((sec_r001911_9_1 >= 0) && (sec_r001911_9_1 <= 255));
  __CPROVER_assume((sec_r001911_9_2 >= 0) && (sec_r001911_9_2 <= 255));
  __CPROVER_assume((sec_r001911_10_1 >= 0) && (sec_r001911_10_1 <= 255));
  __CPROVER_assume((sec_r001911_10_2 >= 0) && (sec_r001911_10_2 <= 255));
  __CPROVER_assume((sec_r001911_11_1 >= 0) && (sec_r001911_11_1 <= 255));
  __CPROVER_assume((sec_r001911_11_2 >= 0) && (sec_r001911_11_2 <= 255));
  __CPROVER_assume((sec_r001911_12_1 >= 0) && (sec_r001911_12_1 <= 255));
  __CPROVER_assume((sec_r001911_12_2 >= 0) && (sec_r001911_12_2 <= 255));
  __CPROVER_assume((sec_r001911_13_1 >= 0) && (sec_r001911_13_1 <= 255));
  __CPROVER_assume((sec_r001911_13_2 >= 0) && (sec_r001911_13_2 <= 255));
  __CPROVER_assume((sec_r001911_14_1 >= 0) && (sec_r001911_14_1 <= 255));
  __CPROVER_assume((sec_r001911_14_2 >= 0) && (sec_r001911_14_2 <= 255));
  __CPROVER_assume((sec_r001911_15_1 >= 0) && (sec_r001911_15_1 <= 255));
  __CPROVER_assume((sec_r001911_15_2 >= 0) && (sec_r001911_15_2 <= 255));
  __CPROVER_assume((sec_r001911_16_1 >= 0) && (sec_r001911_16_1 <= 255));
  __CPROVER_assume((sec_r001911_16_2 >= 0) && (sec_r001911_16_2 <= 255));
  __CPROVER_assume((sec_r001911_17_1 >= 0) && (sec_r001911_17_1 <= 255));
  __CPROVER_assume((sec_r001911_17_2 >= 0) && (sec_r001911_17_2 <= 255));
  __CPROVER_assume((sec_r001911_18_1 >= 0) && (sec_r001911_18_1 <= 255));
  __CPROVER_assume((sec_r001911_18_2 >= 0) && (sec_r001911_18_2 <= 255));
  struct EventLog_R001911_1113_0 st_var_0_1 = {0};
  struct EventLog_R001911_1113_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001911_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001911_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001911_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001911_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001911_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001911_0_2 + 7) & 15;
  struct Transaction_R001911_1113_1 st_var_1_1 = {0};
  struct Transaction_R001911_1113_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001911_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001911_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001911_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001911_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001911_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001911_0_2 + 9) & 15;
  struct DeviceConfig_R001911_1113_2 st_var_2_1 = {0};
  struct DeviceConfig_R001911_1113_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001911_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001911_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001911_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001911_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001911_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001911_0_2 + 11) & 15;
  union TelemetryField_R001911_1113_0 u_var_1;
  union TelemetryField_R001911_1113_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((pub_r001911_4_1 * 2) + 37) & 63;
  int stage_v_0_2 = ((pub_r001911_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001911_17_1 * 2) + 7) & 63;
  int stage_v_1_2 = ((pub_r001911_17_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001911_18_1 * 2) + 23) & 63;
  int stage_v_2_2 = ((pub_r001911_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001911_20_1 * 2) + 44) & 63;
  int stage_v_3_2 = ((pub_r001911_20_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001911_18_1 * 2) + 24) & 63;
  int stage_v_4_2 = ((pub_r001911_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001911_2_1 * 2) + 26) & 63;
  int stage_v_5_2 = ((pub_r001911_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001911_9_1 * 2) + 25) & 63;
  int stage_v_6_2 = ((pub_r001911_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001911_14_1 * 2) + 27) & 63;
  int stage_v_7_2 = ((pub_r001911_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001911_17_1 * 2) + 14) & 63;
  int stage_v_8_2 = ((pub_r001911_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001911_8_1 * 2) + 40) & 63;
  int stage_v_9_2 = ((pub_r001911_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001911_11_1 * 2) + 42) & 63;
  int stage_v_10_2 = ((pub_r001911_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001911_20_1 * 2) + 48) & 63;
  int stage_v_11_2 = ((pub_r001911_20_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001911_13_1 * 2) + 31) & 63;
  int stage_v_12_2 = ((pub_r001911_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001911_22_1 * 2) + 15) & 63;
  int stage_v_13_2 = ((pub_r001911_22_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001911_18_1 * 2) + 23) & 63;
  int stage_v_14_2 = ((pub_r001911_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001911_15_1 * 2) + 46) & 63;
  int stage_v_15_2 = ((pub_r001911_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001911_20_1 * 2) + 35) & 63;
  int stage_v_16_2 = ((pub_r001911_20_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001911_0_1 * 2) + 38) & 63;
  int stage_v_17_2 = ((pub_r001911_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001911_9_1 * 2) + 13) & 63;
  int stage_v_18_2 = ((pub_r001911_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001911_10_1 * 2) + 28) & 63;
  int stage_v_19_2 = ((pub_r001911_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001911_6_1 * 2) + 21) & 63;
  int stage_v_20_2 = ((pub_r001911_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001911_17_1 * 2) + 9) & 63;
  int stage_v_21_2 = ((pub_r001911_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001911_16_1 * 2) + 9) & 63;
  int stage_v_22_2 = ((pub_r001911_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001911_11_1 * 2) + 50) & 63;
  int stage_v_23_2 = ((pub_r001911_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001911_5_1 * 2) + 22) & 63;
  int stage_v_24_2 = ((pub_r001911_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001911_9_1 * 2) + 15) & 63;
  int stage_v_25_2 = ((pub_r001911_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001911_13_1 * 2) + 40) & 63;
  int stage_v_26_2 = ((pub_r001911_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001911_9_1 * 2) + 33) & 63;
  int stage_v_27_2 = ((pub_r001911_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001911_15_1 * 2) + 46) & 63;
  int stage_v_28_2 = ((pub_r001911_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001911_9_1 * 2) + 46) & 63;
  int stage_v_29_2 = ((pub_r001911_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001911_8_1 * 2) + 6) & 63;
  int stage_v_30_2 = ((pub_r001911_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001911_5_1 * 2) + 31) & 63;
  int stage_v_31_2 = ((pub_r001911_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001911_3_1 * 2) + 44) & 63;
  int stage_v_32_2 = ((pub_r001911_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001911_8_1 * 2) + 22) & 63;
  int stage_v_33_2 = ((pub_r001911_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001911_5_1 * 2) + 22) & 63;
  int stage_v_34_2 = ((pub_r001911_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001911_19_1 * 2) + 7) & 63;
  int stage_v_35_2 = ((pub_r001911_19_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001911_22_1 * 2) + 28) & 63;
  int stage_v_36_2 = ((pub_r001911_22_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001911_16_1 * 2) + 8) & 63;
  int stage_v_37_2 = ((pub_r001911_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001911_6_1 * 2) + 9) & 63;
  int stage_v_38_2 = ((pub_r001911_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001911_18_1 * 2) + 40) & 63;
  int stage_v_39_2 = ((pub_r001911_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001911_14_1 * 2) + 36) & 63;
  int stage_v_40_2 = ((pub_r001911_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001911_3_1 * 2) + 35) & 63;
  int stage_v_41_2 = ((pub_r001911_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001911_0_1 * 2) + 19) & 63;
  int stage_v_42_2 = ((pub_r001911_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001911_8_1 * 2) + 22) & 63;
  int stage_v_43_2 = ((pub_r001911_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001911_12_1 * 2) + 15) & 63;
  int stage_v_44_2 = ((pub_r001911_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001911_1_1 * 2) + 48) & 63;
  int stage_v_45_2 = ((pub_r001911_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001911_4_1 * 2) + 37) & 63;
  int stage_v_46_2 = ((pub_r001911_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001911_19_1 * 2) + 19) & 63;
  int stage_v_47_2 = ((pub_r001911_19_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001911_15_1 * 2) + 37) & 63;
  int stage_v_48_2 = ((pub_r001911_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001911_4_1 * 2) + 38) & 63;
  int stage_v_49_2 = ((pub_r001911_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001911_10_1 * 2) + 50) & 63;
  int stage_v_50_2 = ((pub_r001911_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001911_15_1 * 2) + 46) & 63;
  int stage_v_51_2 = ((pub_r001911_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001911_3_1 * 2) + 46) & 63;
  int stage_v_52_2 = ((pub_r001911_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001911_1_1 * 2) + 9) & 63;
  int stage_v_53_2 = ((pub_r001911_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001911_11_1 * 2) + 36) & 63;
  int stage_v_54_2 = ((pub_r001911_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001911_8_1 * 2) + 31) & 63;
  int stage_v_55_2 = ((pub_r001911_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001911_21_1 * 2) + 15) & 63;
  int stage_v_56_2 = ((pub_r001911_21_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001911_3_1 * 2) + 22) & 63;
  int stage_v_57_2 = ((pub_r001911_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001911_15_1 * 2) + 12) & 63;
  int stage_v_58_2 = ((pub_r001911_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001911_20_1 * 2) + 29) & 63;
  int stage_v_59_2 = ((pub_r001911_20_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001911_3_1 * 2) + 50) & 63;
  int stage_v_60_2 = ((pub_r001911_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001911_7_1 * 2) + 13) & 63;
  int stage_v_61_2 = ((pub_r001911_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001911_0_1 * 2) + 6) & 63;
  int stage_v_62_2 = ((pub_r001911_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001911_4_1 * 2) + 13) & 63;
  int stage_v_63_2 = ((pub_r001911_4_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001911_1_1 * 2) + 28) & 63;
  int stage_v_64_2 = ((pub_r001911_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001911_20_1 * 2) + 41) & 63;
  int stage_v_65_2 = ((pub_r001911_20_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001911_13_1 * 2) + 46) & 63;
  int stage_v_66_2 = ((pub_r001911_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001911_11_1 * 2) + 21) & 63;
  int stage_v_67_2 = ((pub_r001911_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001911_20_1 * 2) + 27) & 63;
  int stage_v_68_2 = ((pub_r001911_20_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001911_7_1 * 2) + 46) & 63;
  int stage_v_69_2 = ((pub_r001911_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001911_18_1 * 2) + 19) & 63;
  int stage_v_70_2 = ((pub_r001911_18_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001911_1_1 * 2) + 35) & 63;
  int stage_v_71_2 = ((pub_r001911_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001911_13_1 * 2) + 36) & 63;
  int stage_v_72_2 = ((pub_r001911_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001911_10_1 * 2) + 44) & 63;
  int stage_v_73_2 = ((pub_r001911_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001911_2_1 * 2) + 34) & 63;
  int stage_v_74_2 = ((pub_r001911_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001911_20_1 * 2) + 19) & 63;
  int stage_v_75_2 = ((pub_r001911_20_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001911_13_1 * 2) + 24) & 63;
  int stage_v_76_2 = ((pub_r001911_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001911_22_1 * 2) + 48) & 63;
  int stage_v_77_2 = ((pub_r001911_22_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001911_4_1 * 2) + 10) & 63;
  int stage_v_78_2 = ((pub_r001911_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001911_20_1 * 2) + 20) & 63;
  int stage_v_79_2 = ((pub_r001911_20_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001911_20_1 * 2) + 9) & 63;
  int stage_v_80_2 = ((pub_r001911_20_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001911_3_1 * 2) + 20) & 63;
  int stage_v_81_2 = ((pub_r001911_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001911_15_1 * 2) + 38) & 63;
  int stage_v_82_2 = ((pub_r001911_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001911_18_1 * 2) + 7) & 63;
  int stage_v_83_2 = ((pub_r001911_18_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001911_8_1 * 2) + 32) & 63;
  int stage_v_84_2 = ((pub_r001911_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001911_7_1 * 2) + 7) & 63;
  int stage_v_85_2 = ((pub_r001911_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001911_5_1 * 2) + 43) & 63;
  int stage_v_86_2 = ((pub_r001911_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001911_2_1 * 2) + 38) & 63;
  int stage_v_87_2 = ((pub_r001911_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001911_19_1 * 2) + 38) & 63;
  int stage_v_88_2 = ((pub_r001911_19_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001911_20_1 * 2) + 18) & 63;
  int stage_v_89_2 = ((pub_r001911_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001911_17_1 * 2) + 18) & 63;
  int stage_v_90_2 = ((pub_r001911_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001911_3_1 * 2) + 25) & 63;
  int stage_v_91_2 = ((pub_r001911_3_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001911_11_1 * 2) + 10) & 63;
  int stage_v_92_2 = ((pub_r001911_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001911_13_1 * 2) + 30) & 63;
  int stage_v_93_2 = ((pub_r001911_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001911_3_1 * 2) + 34) & 63;
  int stage_v_94_2 = ((pub_r001911_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001911_19_1 * 2) + 29) & 63;
  int stage_v_95_2 = ((pub_r001911_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001911_21_1 * 2) + 35) & 63;
  int stage_v_96_2 = ((pub_r001911_21_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001911_13_1 * 2) + 7) & 63;
  int stage_v_97_2 = ((pub_r001911_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001911_15_1 * 2) + 5) & 63;
  int stage_v_98_2 = ((pub_r001911_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001911_14_1 * 2) + 10) & 63;
  int stage_v_99_2 = ((pub_r001911_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001911_1_1 * 2) + 33) & 63;
  int stage_v_100_2 = ((pub_r001911_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001911_17_1 * 2) + 9) & 63;
  int stage_v_101_2 = ((pub_r001911_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001911_12_1 * 2) + 9) & 63;
  int stage_v_102_2 = ((pub_r001911_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001911_7_1 * 2) + 50) & 63;
  int stage_v_103_2 = ((pub_r001911_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001911_6_1 * 2) + 38) & 63;
  int stage_v_104_2 = ((pub_r001911_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001911_1_1 * 2) + 44) & 63;
  int stage_v_105_2 = ((pub_r001911_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001911_6_1 * 2) + 18) & 63;
  int stage_v_106_2 = ((pub_r001911_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001911_21_1 * 2) + 33) & 63;
  int stage_v_107_2 = ((pub_r001911_21_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001911_0_1 * 2) + 13) & 63;
  int stage_v_108_2 = ((pub_r001911_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001911_12_1 * 2) + 30) & 63;
  int stage_v_109_2 = ((pub_r001911_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001911_20_1 * 2) + 7) & 63;
  int stage_v_110_2 = ((pub_r001911_20_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001911_10_1 * 2) + 27) & 63;
  int stage_v_111_2 = ((pub_r001911_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001911_22_1 * 2) + 37) & 63;
  int stage_v_112_2 = ((pub_r001911_22_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001911_0_1 * 2) + 47) & 63;
  int stage_v_113_2 = ((pub_r001911_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001911_9_1 * 2) + 32) & 63;
  int stage_v_114_2 = ((pub_r001911_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001911_6_1 * 2) + 41) & 63;
  int stage_v_115_2 = ((pub_r001911_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001911_15_1 * 2) + 9) & 63;
  int stage_v_116_2 = ((pub_r001911_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001911_11_1 * 2) + 25) & 63;
  int stage_v_117_2 = ((pub_r001911_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001911_0_1 * 2) + 16) & 63;
  int stage_v_118_2 = ((pub_r001911_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001911_14_1 * 2) + 34) & 63;
  int stage_v_119_2 = ((pub_r001911_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001911_13_1 * 2) + 20) & 63;
  int stage_v_120_2 = ((pub_r001911_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001911_19_1 * 2) + 42) & 63;
  int stage_v_121_2 = ((pub_r001911_19_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001911_17_1 * 2) + 47) & 63;
  int stage_v_122_2 = ((pub_r001911_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001911_18_1 * 2) + 11) & 63;
  int stage_v_123_2 = ((pub_r001911_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001911_19_1 * 2) + 50) & 63;
  int stage_v_124_2 = ((pub_r001911_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001911_4_1 * 2) + 9) & 63;
  int stage_v_125_2 = ((pub_r001911_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001911_7_1 * 2) + 29) & 63;
  int stage_v_126_2 = ((pub_r001911_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001911_20_1 * 2) + 24) & 63;
  int stage_v_127_2 = ((pub_r001911_20_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001911_0_1 * 2) + 16) & 63;
  int stage_v_128_2 = ((pub_r001911_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001911_3_1 * 2) + 31) & 63;
  int stage_v_129_2 = ((pub_r001911_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001911_16_1 * 2) + 5) & 63;
  int stage_v_130_2 = ((pub_r001911_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001911_0_1 * 2) + 30) & 63;
  int stage_v_131_2 = ((pub_r001911_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001911_14_1 * 2) + 39) & 63;
  int stage_v_132_2 = ((pub_r001911_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001911_16_1 * 2) + 13) & 63;
  int stage_v_133_2 = ((pub_r001911_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001911_2_1 * 2) + 18) & 63;
  int stage_v_134_2 = ((pub_r001911_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001911_17_1 * 2) + 32) & 63;
  int stage_v_135_2 = ((pub_r001911_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001911_7_1 * 2) + 28) & 63;
  int stage_v_136_2 = ((pub_r001911_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001911_19_1 * 2) + 13) & 63;
  int stage_v_137_2 = ((pub_r001911_19_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001911_22_1 * 2) + 23) & 63;
  int stage_v_138_2 = ((pub_r001911_22_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001911_14_1 * 2) + 49) & 63;
  int stage_v_139_2 = ((pub_r001911_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001911_20_1 * 2) + 6) & 63;
  int stage_v_140_2 = ((pub_r001911_20_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001911_12_1 * 2) + 39) & 63;
  int stage_v_141_2 = ((pub_r001911_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001911_10_1 * 2) + 27) & 63;
  int stage_v_142_2 = ((pub_r001911_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001911_18_1 * 2) + 31) & 63;
  int stage_v_143_2 = ((pub_r001911_18_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001911_2_1 * 2) + 9) & 63;
  int stage_v_144_2 = ((pub_r001911_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001911_11_1 * 2) + 18) & 63;
  int stage_v_145_2 = ((pub_r001911_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001911_2_1 * 2) + 33) & 63;
  int stage_v_146_2 = ((pub_r001911_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001911_0_1 * 2) + 44) & 63;
  int stage_v_147_2 = ((pub_r001911_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001911_17_1 * 2) + 9) & 63;
  int stage_v_148_2 = ((pub_r001911_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001911_5_1 * 2) + 45) & 63;
  int stage_v_149_2 = ((pub_r001911_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001911_20_1 * 2) + 7) & 63;
  int stage_v_150_2 = ((pub_r001911_20_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001911_5_1 * 2) + 14) & 63;
  int stage_v_151_2 = ((pub_r001911_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001911_20_1 * 2) + 39) & 63;
  int stage_v_152_2 = ((pub_r001911_20_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001911_6_1 * 2) + 14) & 63;
  int stage_v_153_2 = ((pub_r001911_6_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001911_3_1 * 2) + 28) & 63;
  int stage_v_154_2 = ((pub_r001911_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001911_18_1 * 2) + 41) & 63;
  int stage_v_155_2 = ((pub_r001911_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001911_2_1 * 2) + 15) & 63;
  int stage_v_156_2 = ((pub_r001911_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001911_7_1 * 2) + 10) & 63;
  int stage_v_157_2 = ((pub_r001911_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001911_17_1 * 2) + 28) & 63;
  int stage_v_158_2 = ((pub_r001911_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001911_5_1 * 2) + 45) & 63;
  int stage_v_159_2 = ((pub_r001911_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001911_10_1 * 2) + 43) & 63;
  int stage_v_160_2 = ((pub_r001911_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001911_2_1 * 2) + 16) & 63;
  int stage_v_161_2 = ((pub_r001911_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001911_5_1 * 2) + 15) & 63;
  int stage_v_162_2 = ((pub_r001911_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001911_19_1 * 2) + 20) & 63;
  int stage_v_163_2 = ((pub_r001911_19_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001911_0_1 * 2) + 19) & 63;
  int stage_v_164_2 = ((pub_r001911_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001911_5_1 * 2) + 25) & 63;
  int stage_v_165_2 = ((pub_r001911_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001911_11_1 * 2) + 29) & 63;
  int stage_v_166_2 = ((pub_r001911_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001911_18_1 * 2) + 31) & 63;
  int stage_v_167_2 = ((pub_r001911_18_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001911_22_1 * 2) + 11) & 63;
  int stage_v_168_2 = ((pub_r001911_22_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001911_13_1 * 2) + 21) & 63;
  int stage_v_169_2 = ((pub_r001911_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001911_11_1 * 2) + 19) & 63;
  int stage_v_170_2 = ((pub_r001911_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001911_13_1 * 2) + 15) & 63;
  int stage_v_171_2 = ((pub_r001911_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001911_21_1 * 2) + 50) & 63;
  int stage_v_172_2 = ((pub_r001911_21_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001911_18_1 * 2) + 38) & 63;
  int stage_v_173_2 = ((pub_r001911_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001911_11_1 * 2) + 26) & 63;
  int stage_v_174_2 = ((pub_r001911_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001911_7_1 * 2) + 26) & 63;
  int stage_v_175_2 = ((pub_r001911_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001911_18_1 * 2) + 14) & 63;
  int stage_v_176_2 = ((pub_r001911_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001911_20_1 * 2) + 7) & 63;
  int stage_v_177_2 = ((pub_r001911_20_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001911_22_1 * 2) + 5) & 63;
  int stage_v_178_2 = ((pub_r001911_22_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001911_19_1 * 2) + 21) & 63;
  int stage_v_179_2 = ((pub_r001911_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001911_0_1 * 2) + 23) & 63;
  int stage_v_180_2 = ((pub_r001911_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001911_9_1 * 2) + 16) & 63;
  int stage_v_181_2 = ((pub_r001911_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001911_6_1 * 2) + 27) & 63;
  int stage_v_182_2 = ((pub_r001911_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001911_7_1 * 2) + 9) & 63;
  int stage_v_183_2 = ((pub_r001911_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001911_3_1 * 2) + 32) & 63;
  int stage_v_184_2 = ((pub_r001911_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001911_3_1 * 2) + 36) & 63;
  int stage_v_185_2 = ((pub_r001911_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001911_20_1 * 2) + 22) & 63;
  int stage_v_186_2 = ((pub_r001911_20_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001911_13_1 * 2) + 35) & 63;
  int stage_v_187_2 = ((pub_r001911_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001911_20_1 * 2) + 11) & 63;
  int stage_v_188_2 = ((pub_r001911_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001911_6_1 * 2) + 34) & 63;
  int stage_v_189_2 = ((pub_r001911_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001911_10_1 * 2) + 11) & 63;
  int stage_v_190_2 = ((pub_r001911_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001911_16_1 * 2) + 8) & 63;
  int stage_v_191_2 = ((pub_r001911_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001911_6_1 * 2) + 24) & 63;
  int stage_v_192_2 = ((pub_r001911_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001911_10_1 * 2) + 33) & 63;
  int stage_v_193_2 = ((pub_r001911_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001911_2_1 * 2) + 35) & 63;
  int stage_v_194_2 = ((pub_r001911_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001911_8_1 * 2) + 12) & 63;
  int stage_v_195_2 = ((pub_r001911_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001911_15_1 * 2) + 48) & 63;
  int stage_v_196_2 = ((pub_r001911_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001911_5_1 * 2) + 24) & 63;
  int stage_v_197_2 = ((pub_r001911_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001911_22_1 * 2) + 9) & 63;
  int stage_v_198_2 = ((pub_r001911_22_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001911_15_1 * 2) + 10) & 63;
  int stage_v_199_2 = ((pub_r001911_15_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001911_16_1 * 2) + 24) & 63;
  int stage_v_200_2 = ((pub_r001911_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001911_22_1 * 2) + 10) & 63;
  int stage_v_201_2 = ((pub_r001911_22_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001911_22_1 * 2) + 47) & 63;
  int stage_v_202_2 = ((pub_r001911_22_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001911_16_1 * 2) + 11) & 63;
  int stage_v_203_2 = ((pub_r001911_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001911_10_1 * 2) + 33) & 63;
  int stage_v_204_2 = ((pub_r001911_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001911_8_1 * 2) + 34) & 63;
  int stage_v_205_2 = ((pub_r001911_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001911_12_1 * 2) + 14) & 63;
  int stage_v_206_2 = ((pub_r001911_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001911_11_1 * 2) + 32) & 63;
  int stage_v_207_2 = ((pub_r001911_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001911_14_1 * 2) + 31) & 63;
  int stage_v_208_2 = ((pub_r001911_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001911_16_1 * 2) + 9) & 63;
  int stage_v_209_2 = ((pub_r001911_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001911_15_1 * 2) + 7) & 63;
  int stage_v_210_2 = ((pub_r001911_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001911_9_1 * 2) + 49) & 63;
  int stage_v_211_2 = ((pub_r001911_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001911_11_1 * 2) + 50) & 63;
  int stage_v_212_2 = ((pub_r001911_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001911_14_1 * 2) + 44) & 63;
  int stage_v_213_2 = ((pub_r001911_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001911_18_1 * 2) + 45) & 63;
  int stage_v_214_2 = ((pub_r001911_18_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001911_6_1 * 2) + 43) & 63;
  int stage_v_215_2 = ((pub_r001911_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001911_17_1 * 2) + 11) & 63;
  int stage_v_216_2 = ((pub_r001911_17_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001911_21_1 * 2) + 38) & 63;
  int stage_v_217_2 = ((pub_r001911_21_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001911_17_1 * 2) + 15) & 63;
  int stage_v_218_2 = ((pub_r001911_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001911_2_1 * 2) + 25) & 63;
  int stage_v_219_2 = ((pub_r001911_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001911_4_1 * 2) + 39) & 63;
  int stage_v_220_2 = ((pub_r001911_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001911_10_1 * 2) + 37) & 63;
  int stage_v_221_2 = ((pub_r001911_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((pub_r001911_9_1 * 2) + 14) & 63;
  int stage_v_222_2 = ((pub_r001911_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001911_22_1 * 2) + 10) & 63;
  int stage_v_223_2 = ((pub_r001911_22_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001911_0_1 * 2) + 36) & 63;
  int stage_v_224_2 = ((pub_r001911_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001911_20_1 * 2) + 30) & 63;
  int stage_v_225_2 = ((pub_r001911_20_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001911_20_1 * 2) + 11) & 63;
  int stage_v_226_2 = ((pub_r001911_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001911_12_1 * 2) + 15) & 63;
  int stage_v_227_2 = ((pub_r001911_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001911_13_1 * 2) + 18) & 63;
  int stage_v_228_2 = ((pub_r001911_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001911_13_1 * 2) + 32) & 63;
  int stage_v_229_2 = ((pub_r001911_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001911_5_1 * 2) + 42) & 63;
  int stage_v_230_2 = ((pub_r001911_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001911_18_1 * 2) + 48) & 63;
  int stage_v_231_2 = ((pub_r001911_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001911_15_1 * 2) + 45) & 63;
  int stage_v_232_2 = ((pub_r001911_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001911_1_1 * 2) + 42) & 63;
  int stage_v_233_2 = ((pub_r001911_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001911_15_1 * 2) + 49) & 63;
  int stage_v_234_2 = ((pub_r001911_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001911_18_1 * 2) + 37) & 63;
  int stage_v_235_2 = ((pub_r001911_18_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001911_19_1 * 2) + 17) & 63;
  int stage_v_236_2 = ((pub_r001911_19_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001911_14_1 * 2) + 20) & 63;
  int stage_v_237_2 = ((pub_r001911_14_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001911_3_1 * 2) + 28) & 63;
  int stage_v_238_2 = ((pub_r001911_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001911_19_1 * 2) + 26) & 63;
  int stage_v_239_2 = ((pub_r001911_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001911_18_1 * 2) + 33) & 63;
  int stage_v_240_2 = ((pub_r001911_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((pub_r001911_3_1 * 2) + 46) & 63;
  int stage_v_241_2 = ((pub_r001911_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((pub_r001911_21_1 * 2) + 21) & 63;
  int stage_v_242_2 = ((pub_r001911_21_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((pub_r001911_2_1 * 2) + 46) & 63;
  int stage_v_243_2 = ((pub_r001911_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((pub_r001911_16_1 * 2) + 35) & 63;
  int stage_v_244_2 = ((pub_r001911_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001911_3_1 * 2) + 42) & 63;
  int stage_v_245_2 = ((pub_r001911_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001911_9_1 * 2) + 10) & 63;
  int stage_v_246_2 = ((pub_r001911_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001911_4_1 * 2) + 9) & 63;
  int stage_v_247_2 = ((pub_r001911_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001911_4_1 * 2) + 15) & 63;
  int stage_v_248_2 = ((pub_r001911_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001911_2_1 * 2) + 13) & 63;
  int stage_v_249_2 = ((pub_r001911_2_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001911_22_1 * 2) + 32) & 63;
  int stage_v_250_2 = ((pub_r001911_22_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001911_3_1 * 2) + 6) & 63;
  int stage_v_251_2 = ((pub_r001911_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((pub_r001911_13_1 * 2) + 33) & 63;
  int stage_v_252_2 = ((pub_r001911_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((pub_r001911_14_1 * 2) + 36) & 63;
  int stage_v_253_2 = ((pub_r001911_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((pub_r001911_17_1 * 2) + 25) & 63;
  int stage_v_254_2 = ((pub_r001911_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001911_8_1 * 2) + 44) & 63;
  int stage_v_255_2 = ((pub_r001911_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001911_0_1 * 2) + 11) & 63;
  int stage_v_256_2 = ((pub_r001911_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001911_10_1 * 2) + 25) & 63;
  int stage_v_257_2 = ((pub_r001911_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001911_6_1 * 2) + 14) & 63;
  int stage_v_258_2 = ((pub_r001911_6_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001911_18_1 * 2) + 34) & 63;
  int stage_v_259_2 = ((pub_r001911_18_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001911_3_1 * 2) + 44) & 63;
  int stage_v_260_2 = ((pub_r001911_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001911_17_1 * 2) + 47) & 63;
  int stage_v_261_2 = ((pub_r001911_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001911_19_1 * 2) + 5) & 63;
  int stage_v_262_2 = ((pub_r001911_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001911_7_1 * 2) + 34) & 63;
  int stage_v_263_2 = ((pub_r001911_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((pub_r001911_18_1 * 2) + 26) & 63;
  int stage_v_264_2 = ((pub_r001911_18_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001911_21_1 * 2) + 47) & 63;
  int stage_v_265_2 = ((pub_r001911_21_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001911_9_1 * 2) + 37) & 63;
  int stage_v_266_2 = ((pub_r001911_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001911_6_1 * 2) + 9) & 63;
  int stage_v_267_2 = ((pub_r001911_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001911_10_1 * 2) + 6) & 63;
  int stage_v_268_2 = ((pub_r001911_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001911_17_1 * 2) + 47) & 63;
  int stage_v_269_2 = ((pub_r001911_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001911_22_1 * 2) + 38) & 63;
  int stage_v_270_2 = ((pub_r001911_22_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001911_21_1 * 2) + 29) & 63;
  int stage_v_271_2 = ((pub_r001911_21_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001911_16_1 * 2) + 8) & 63;
  int stage_v_272_2 = ((pub_r001911_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001911_11_1 * 2) + 31) & 63;
  int stage_v_273_2 = ((pub_r001911_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((pub_r001911_16_1 * 2) + 23) & 63;
  int stage_v_274_2 = ((pub_r001911_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001911_21_1 * 2) + 16) & 63;
  int stage_v_275_2 = ((pub_r001911_21_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((pub_r001911_8_1 * 2) + 28) & 63;
  int stage_v_276_2 = ((pub_r001911_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((pub_r001911_19_1 * 2) + 13) & 63;
  int stage_v_277_2 = ((pub_r001911_19_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((pub_r001911_17_1 * 2) + 50) & 63;
  int stage_v_278_2 = ((pub_r001911_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001911_17_1 * 2) + 36) & 63;
  int stage_v_279_2 = ((pub_r001911_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001911_5_1 * 2) + 40) & 63;
  int stage_v_280_2 = ((pub_r001911_5_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001911_21_1 * 2) + 35) & 63;
  int stage_v_281_2 = ((pub_r001911_21_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((pub_r001911_20_1 * 2) + 5) & 63;
  int stage_v_282_2 = ((pub_r001911_20_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001911_16_1 * 2) + 8) & 63;
  int stage_v_283_2 = ((pub_r001911_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001911_0_1 * 2) + 24) & 63;
  int stage_v_284_2 = ((pub_r001911_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001911_21_1 * 2) + 43) & 63;
  int stage_v_285_2 = ((pub_r001911_21_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001911_12_1 * 2) + 46) & 63;
  int stage_v_286_2 = ((pub_r001911_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001911_15_1 * 2) + 24) & 63;
  int stage_v_287_2 = ((pub_r001911_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001911_15_1 * 2) + 13) & 63;
  int stage_v_288_2 = ((pub_r001911_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((pub_r001911_20_1 * 2) + 37) & 63;
  int stage_v_289_2 = ((pub_r001911_20_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((pub_r001911_5_1 * 2) + 7) & 63;
  int stage_v_290_2 = ((pub_r001911_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((pub_r001911_4_1 * 2) + 10) & 63;
  int stage_v_291_2 = ((pub_r001911_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((pub_r001911_17_1 * 2) + 8) & 63;
  int stage_v_292_2 = ((pub_r001911_17_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001911_17_1 * 2) + 11) & 63;
  int stage_v_293_2 = ((pub_r001911_17_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001911_16_1 * 2) + 21) & 63;
  int stage_v_294_2 = ((pub_r001911_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001911_17_1 * 2) + 7) & 63;
  int stage_v_295_2 = ((pub_r001911_17_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((pub_r001911_5_1 * 2) + 33) & 63;
  int stage_v_296_2 = ((pub_r001911_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001911_21_1 * 2) + 27) & 63;
  int stage_v_297_2 = ((pub_r001911_21_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001911_18_1 * 2) + 9) & 63;
  int stage_v_298_2 = ((pub_r001911_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001911_15_1 * 2) + 40) & 63;
  int stage_v_299_2 = ((pub_r001911_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001911_12_1 * 2) + 27) & 63;
  int stage_v_300_2 = ((pub_r001911_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001911_14_1 * 2) + 26) & 63;
  int stage_v_301_2 = ((pub_r001911_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001911_7_1 * 2) + 9) & 63;
  int stage_v_302_2 = ((pub_r001911_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001911_12_1 * 2) + 36) & 63;
  int stage_v_303_2 = ((pub_r001911_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001911_2_1 * 2) + 25) & 63;
  int stage_v_304_2 = ((pub_r001911_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001911_5_1 * 2) + 40) & 63;
  int stage_v_305_2 = ((pub_r001911_5_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001911_14_1 * 2) + 26) & 63;
  int stage_v_306_2 = ((pub_r001911_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001911_21_1 * 2) + 38) & 63;
  int stage_v_307_2 = ((pub_r001911_21_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001911_12_1 * 2) + 43) & 63;
  int stage_v_308_2 = ((pub_r001911_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001911_15_1 * 2) + 15) & 63;
  int stage_v_309_2 = ((pub_r001911_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001911_21_1 * 2) + 48) & 63;
  int stage_v_310_2 = ((pub_r001911_21_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((pub_r001911_10_1 * 2) + 16) & 63;
  int stage_v_311_2 = ((pub_r001911_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((pub_r001911_8_1 * 2) + 42) & 63;
  int stage_v_312_2 = ((pub_r001911_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = ((pub_r001911_21_1 * 2) + 24) & 63;
  int stage_v_313_2 = ((pub_r001911_21_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = ((pub_r001911_5_1 * 2) + 26) & 63;
  int stage_v_314_2 = ((pub_r001911_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001911_9_1 * 2) + 49) & 63;
  int stage_v_315_2 = ((pub_r001911_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001911_16_1 * 2) + 14) & 63;
  int stage_v_316_2 = ((pub_r001911_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((pub_r001911_17_1 * 2) + 24) & 63;
  int stage_v_317_2 = ((pub_r001911_17_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001911_8_1 * 2) + 27) & 63;
  int stage_v_318_2 = ((pub_r001911_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001911_1_1 * 2) + 44) & 63;
  int stage_v_319_2 = ((pub_r001911_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001911_9_1 * 2) + 7) & 63;
  int stage_v_320_2 = ((pub_r001911_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((pub_r001911_11_1 * 2) + 16) & 63;
  int stage_v_321_2 = ((pub_r001911_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001911_12_1 * 2) + 45) & 63;
  int stage_v_322_2 = ((pub_r001911_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001911_12_1 * 2) + 37) & 63;
  int stage_v_323_2 = ((pub_r001911_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001911_18_1 * 2) + 14) & 63;
  int stage_v_324_2 = ((pub_r001911_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((pub_r001911_0_1 * 2) + 47) & 63;
  int stage_v_325_2 = ((pub_r001911_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((pub_r001911_7_1 * 2) + 41) & 63;
  int stage_v_326_2 = ((pub_r001911_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001911_0_1 * 2) + 29) & 63;
  int stage_v_327_2 = ((pub_r001911_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001911_19_1 * 2) + 34) & 63;
  int stage_v_328_2 = ((pub_r001911_19_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001911_9_1 * 2) + 20) & 63;
  int stage_v_329_2 = ((pub_r001911_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001911_1_1 * 2) + 10) & 63;
  int stage_v_330_2 = ((pub_r001911_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001911_21_1 * 2) + 33) & 63;
  int stage_v_331_2 = ((pub_r001911_21_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001911_14_1 * 2) + 5) & 63;
  int stage_v_332_2 = ((pub_r001911_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001911_15_1 * 2) + 13) & 63;
  int stage_v_333_2 = ((pub_r001911_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001911_4_1 * 2) + 30) & 63;
  int stage_v_334_2 = ((pub_r001911_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((pub_r001911_3_1 * 2) + 23) & 63;
  int stage_v_335_2 = ((pub_r001911_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((pub_r001911_14_1 * 2) + 47) & 63;
  int stage_v_336_2 = ((pub_r001911_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001911_0_1 * 2) + 44) & 63;
  int stage_v_337_2 = ((pub_r001911_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((pub_r001911_7_1 * 2) + 5) & 63;
  int stage_v_338_2 = ((pub_r001911_7_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((pub_r001911_6_1 * 2) + 11) & 63;
  int stage_v_339_2 = ((pub_r001911_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001911_7_1 * 2) + 25) & 63;
  int stage_v_340_2 = ((pub_r001911_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001911_4_1 * 2) + 8) & 63;
  int stage_v_341_2 = ((pub_r001911_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001911_10_1 * 2) + 45) & 63;
  int stage_v_342_2 = ((pub_r001911_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((pub_r001911_17_1 * 2) + 45) & 63;
  int stage_v_343_2 = ((pub_r001911_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001911_0_1 * 2) + 18) & 63;
  int stage_v_344_2 = ((pub_r001911_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((pub_r001911_2_1 * 2) + 44) & 63;
  int stage_v_345_2 = ((pub_r001911_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001911_18_1 * 2) + 6) & 63;
  int stage_v_346_2 = ((pub_r001911_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001911_22_1 * 2) + 38) & 63;
  int stage_v_347_2 = ((pub_r001911_22_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001911_13_1 * 2) + 22) & 63;
  int stage_v_348_2 = ((pub_r001911_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((pub_r001911_0_1 * 2) + 13) & 63;
  int stage_v_349_2 = ((pub_r001911_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = ((pub_r001911_15_1 * 2) + 31) & 63;
  int stage_v_350_2 = ((pub_r001911_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = ((pub_r001911_7_1 * 2) + 19) & 63;
  int stage_v_351_2 = ((pub_r001911_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001911_3_1 * 2) + 16) & 63;
  int stage_v_352_2 = ((pub_r001911_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001911_15_1 * 2) + 44) & 63;
  int stage_v_353_2 = ((pub_r001911_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001911_6_1 * 2) + 13) & 63;
  int stage_v_354_2 = ((pub_r001911_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001911_1_1 * 2) + 16) & 63;
  int stage_v_355_2 = ((pub_r001911_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((pub_r001911_7_1 * 2) + 9) & 63;
  int stage_v_356_2 = ((pub_r001911_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001911_1_1 * 2) + 28) & 63;
  int stage_v_357_2 = ((pub_r001911_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001911_22_1 * 2) + 8) & 63;
  int stage_v_358_2 = ((pub_r001911_22_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001911_19_1 * 2) + 8) & 63;
  int stage_v_359_2 = ((pub_r001911_19_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((pub_r001911_19_1 * 2) + 28) & 63;
  int stage_v_360_2 = ((pub_r001911_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((pub_r001911_10_1 * 2) + 19) & 63;
  int stage_v_361_2 = ((pub_r001911_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001911_0_1 * 2) + 18) & 63;
  int stage_v_362_2 = ((pub_r001911_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001911_4_1 * 2) + 47) & 63;
  int stage_v_363_2 = ((pub_r001911_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001911_22_1 * 2) + 33) & 63;
  int stage_v_364_2 = ((pub_r001911_22_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001911_1_1 * 2) + 6) & 63;
  int stage_v_365_2 = ((pub_r001911_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001911_14_1 * 2) + 27) & 63;
  int stage_v_366_2 = ((pub_r001911_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((pub_r001911_4_1 * 2) + 20) & 63;
  int stage_v_367_2 = ((pub_r001911_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001911_1_1 * 2) + 40) & 63;
  int stage_v_368_2 = ((pub_r001911_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001911_11_1 * 2) + 47) & 63;
  int stage_v_369_2 = ((pub_r001911_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001911_10_1 * 2) + 11) & 63;
  int stage_v_370_2 = ((pub_r001911_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001911_6_1 * 2) + 42) & 63;
  int stage_v_371_2 = ((pub_r001911_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001911_8_1 * 2) + 19) & 63;
  int stage_v_372_2 = ((pub_r001911_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001911_14_1 * 2) + 14) & 63;
  int stage_v_373_2 = ((pub_r001911_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((pub_r001911_14_1 * 2) + 47) & 63;
  int stage_v_374_2 = ((pub_r001911_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((pub_r001911_19_1 * 2) + 49) & 63;
  int stage_v_375_2 = ((pub_r001911_19_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((pub_r001911_3_1 * 2) + 22) & 63;
  int stage_v_376_2 = ((pub_r001911_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001911_22_1 * 2) + 36) & 63;
  int stage_v_377_2 = ((pub_r001911_22_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((pub_r001911_5_1 * 2) + 47) & 63;
  int stage_v_378_2 = ((pub_r001911_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = ((pub_r001911_10_1 * 2) + 45) & 63;
  int stage_v_379_2 = ((pub_r001911_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = ((pub_r001911_14_1 * 2) + 39) & 63;
  int stage_v_380_2 = ((pub_r001911_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001911_14_1 * 2) + 19) & 63;
  int stage_v_381_2 = ((pub_r001911_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = ((pub_r001911_7_1 * 2) + 21) & 63;
  int stage_v_382_2 = ((pub_r001911_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001911_17_1 * 2) + 18) & 63;
  int stage_v_383_2 = ((pub_r001911_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001911_1_1 * 2) + 17) & 63;
  int stage_v_384_2 = ((pub_r001911_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001911_15_1 * 2) + 8) & 63;
  int stage_v_385_2 = ((pub_r001911_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001911_6_1 * 2) + 6) & 63;
  int stage_v_386_2 = ((pub_r001911_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001911_9_1 * 2) + 22) & 63;
  int stage_v_387_2 = ((pub_r001911_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001911_15_1 * 2) + 21) & 63;
  int stage_v_388_2 = ((pub_r001911_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001911_5_1 * 2) + 36) & 63;
  int stage_v_389_2 = ((pub_r001911_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = ((pub_r001911_18_1 * 2) + 26) & 63;
  int stage_v_390_2 = ((pub_r001911_18_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((pub_r001911_10_1 * 2) + 9) & 63;
  int stage_v_391_2 = ((pub_r001911_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001911_17_1 * 2) + 40) & 63;
  int stage_v_392_2 = ((pub_r001911_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001911_21_1 * 2) + 27) & 63;
  int stage_v_393_2 = ((pub_r001911_21_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((pub_r001911_7_1 * 2) + 30) & 63;
  int stage_v_394_2 = ((pub_r001911_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001911_12_1 * 2) + 45) & 63;
  int stage_v_395_2 = ((pub_r001911_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((pub_r001911_17_1 * 2) + 17) & 63;
  int stage_v_396_2 = ((pub_r001911_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((pub_r001911_19_1 * 2) + 49) & 63;
  int stage_v_397_2 = ((pub_r001911_19_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001911_20_1 * 2) + 5) & 63;
  int stage_v_398_2 = ((pub_r001911_20_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001911_21_1 * 2) + 16) & 63;
  int stage_v_399_2 = ((pub_r001911_21_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001911_8_1 * 2) + 50) & 63;
  int stage_v_400_2 = ((pub_r001911_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((pub_r001911_10_1 * 2) + 33) & 63;
  int stage_v_401_2 = ((pub_r001911_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = ((pub_r001911_17_1 * 2) + 33) & 63;
  int stage_v_402_2 = ((pub_r001911_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((pub_r001911_21_1 * 2) + 21) & 63;
  int stage_v_403_2 = ((pub_r001911_21_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = ((pub_r001911_11_1 * 2) + 21) & 63;
  int stage_v_404_2 = ((pub_r001911_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = ((pub_r001911_16_1 * 2) + 33) & 63;
  int stage_v_405_2 = ((pub_r001911_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((pub_r001911_17_1 * 2) + 6) & 63;
  int stage_v_406_2 = ((pub_r001911_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((pub_r001911_14_1 * 2) + 20) & 63;
  int stage_v_407_2 = ((pub_r001911_14_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001911_16_1 * 2) + 8) & 63;
  int stage_v_408_2 = ((pub_r001911_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((pub_r001911_1_1 * 2) + 31) & 63;
  int stage_v_409_2 = ((pub_r001911_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((pub_r001911_2_1 * 2) + 33) & 63;
  int stage_v_410_2 = ((pub_r001911_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001911_4_1 * 2) + 19) & 63;
  int stage_v_411_2 = ((pub_r001911_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((pub_r001911_15_1 * 2) + 8) & 63;
  int stage_v_412_2 = ((pub_r001911_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((pub_r001911_1_1 * 2) + 50) & 63;
  int stage_v_413_2 = ((pub_r001911_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001911_13_1 * 2) + 33) & 63;
  int stage_v_414_2 = ((pub_r001911_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = ((pub_r001911_1_1 * 2) + 33) & 63;
  int stage_v_415_2 = ((pub_r001911_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = ((pub_r001911_12_1 * 2) + 39) & 63;
  int stage_v_416_2 = ((pub_r001911_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = ((pub_r001911_3_1 * 2) + 13) & 63;
  int stage_v_417_2 = ((pub_r001911_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001911_1_1 * 2) + 47) & 63;
  int stage_v_418_2 = ((pub_r001911_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((pub_r001911_16_1 * 2) + 15) & 63;
  int stage_v_419_2 = ((pub_r001911_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = ((pub_r001911_2_1 * 2) + 39) & 63;
  int stage_v_420_2 = ((pub_r001911_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = ((pub_r001911_10_1 * 2) + 34) & 63;
  int stage_v_421_2 = ((pub_r001911_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((pub_r001911_3_1 * 2) + 49) & 63;
  int stage_v_422_2 = ((pub_r001911_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((pub_r001911_8_1 * 2) + 25) & 63;
  int stage_v_423_2 = ((pub_r001911_8_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001911_16_1 * 2) + 38) & 63;
  int stage_v_424_2 = ((pub_r001911_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((pub_r001911_22_1 * 2) + 13) & 63;
  int stage_v_425_2 = ((pub_r001911_22_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = ((pub_r001911_4_1 * 2) + 17) & 63;
  int stage_v_426_2 = ((pub_r001911_4_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((pub_r001911_20_1 * 2) + 25) & 63;
  int stage_v_427_2 = ((pub_r001911_20_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = ((pub_r001911_1_1 * 2) + 13) & 63;
  int stage_v_428_2 = ((pub_r001911_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((pub_r001911_5_1 * 2) + 35) & 63;
  int stage_v_429_2 = ((pub_r001911_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = ((pub_r001911_7_1 * 2) + 30) & 63;
  int stage_v_430_2 = ((pub_r001911_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = ((pub_r001911_2_1 * 2) + 24) & 63;
  int stage_v_431_2 = ((pub_r001911_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = ((pub_r001911_3_1 * 2) + 22) & 63;
  int stage_v_432_2 = ((pub_r001911_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = ((pub_r001911_12_1 * 2) + 49) & 63;
  int stage_v_433_2 = ((pub_r001911_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = ((pub_r001911_17_1 * 2) + 34) & 63;
  int stage_v_434_2 = ((pub_r001911_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = ((pub_r001911_10_1 * 2) + 38) & 63;
  int stage_v_435_2 = ((pub_r001911_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = ((pub_r001911_5_1 * 2) + 33) & 63;
  int stage_v_436_2 = ((pub_r001911_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = ((pub_r001911_9_1 * 2) + 32) & 63;
  int stage_v_437_2 = ((pub_r001911_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = ((pub_r001911_22_1 * 2) + 32) & 63;
  int stage_v_438_2 = ((pub_r001911_22_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((pub_r001911_18_1 * 2) + 17) & 63;
  int stage_v_439_2 = ((pub_r001911_18_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = ((pub_r001911_4_1 * 2) + 38) & 63;
  int stage_v_440_2 = ((pub_r001911_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001911_0_1 * 2) + 24) & 63;
  int stage_v_441_2 = ((pub_r001911_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((pub_r001911_6_1 * 2) + 38) & 63;
  int stage_v_442_2 = ((pub_r001911_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = ((pub_r001911_22_1 * 2) + 38) & 63;
  int stage_v_443_2 = ((pub_r001911_22_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001911_18_1 * 2) + 12) & 63;
  int stage_v_444_2 = ((pub_r001911_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((pub_r001911_16_1 * 2) + 22) & 63;
  int stage_v_445_2 = ((pub_r001911_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = ((pub_r001911_19_1 * 2) + 17) & 63;
  int stage_v_446_2 = ((pub_r001911_19_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = ((pub_r001911_11_1 * 2) + 22) & 63;
  int stage_v_447_2 = ((pub_r001911_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((pub_r001911_8_1 * 2) + 48) & 63;
  int stage_v_448_2 = ((pub_r001911_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = ((pub_r001911_3_1 * 2) + 33) & 63;
  int stage_v_449_2 = ((pub_r001911_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_449_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_449_2) & 127;
  int stage_v_450_1 = ((pub_r001911_5_1 * 2) + 10) & 63;
  int stage_v_450_2 = ((pub_r001911_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = ((pub_r001911_4_1 * 2) + 10) & 63;
  int stage_v_451_2 = ((pub_r001911_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_451_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_451_2) & 127;
  int stage_v_452_1 = ((pub_r001911_19_1 * 2) + 29) & 63;
  int stage_v_452_2 = ((pub_r001911_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((pub_r001911_15_1 * 2) + 9) & 63;
  int stage_v_453_2 = ((pub_r001911_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = ((pub_r001911_19_1 * 2) + 31) & 63;
  int stage_v_454_2 = ((pub_r001911_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = ((pub_r001911_17_1 * 2) + 13) & 63;
  int stage_v_455_2 = ((pub_r001911_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = ((pub_r001911_4_1 * 2) + 24) & 63;
  int stage_v_456_2 = ((pub_r001911_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_456_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_456_2) & 127;
  int stage_v_457_1 = ((pub_r001911_9_1 * 2) + 8) & 63;
  int stage_v_457_2 = ((pub_r001911_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = ((pub_r001911_6_1 * 2) + 8) & 63;
  int stage_v_458_2 = ((pub_r001911_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = ((pub_r001911_15_1 * 2) + 41) & 63;
  int stage_v_459_2 = ((pub_r001911_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_459_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_459_2) & 127;
  int stage_v_460_1 = ((pub_r001911_18_1 * 2) + 23) & 63;
  int stage_v_460_2 = ((pub_r001911_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = ((pub_r001911_13_1 * 2) + 31) & 63;
  int stage_v_461_2 = ((pub_r001911_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = ((pub_r001911_20_1 * 2) + 31) & 63;
  int stage_v_462_2 = ((pub_r001911_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_462_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_462_2) & 127;
  int stage_v_463_1 = ((pub_r001911_11_1 * 2) + 14) & 63;
  int stage_v_463_2 = ((pub_r001911_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_463_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_463_2) & 127;
  int stage_v_464_1 = ((pub_r001911_6_1 * 2) + 8) & 63;
  int stage_v_464_2 = ((pub_r001911_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_464_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_464_2) & 127;
  int stage_v_465_1 = ((pub_r001911_13_1 * 2) + 48) & 63;
  int stage_v_465_2 = ((pub_r001911_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = ((pub_r001911_12_1 * 2) + 41) & 63;
  int stage_v_466_2 = ((pub_r001911_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_466_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_466_2) & 127;
  int stage_v_467_1 = ((pub_r001911_13_1 * 2) + 37) & 63;
  int stage_v_467_2 = ((pub_r001911_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_467_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_467_2) & 127;
  int stage_v_468_1 = ((pub_r001911_12_1 * 2) + 29) & 63;
  int stage_v_468_2 = ((pub_r001911_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_468_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_468_2) & 127;
  int stage_v_469_1 = ((pub_r001911_12_1 * 2) + 20) & 63;
  int stage_v_469_2 = ((pub_r001911_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_469_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_469_2) & 127;
  int stage_v_470_1 = ((pub_r001911_17_1 * 2) + 10) & 63;
  int stage_v_470_2 = ((pub_r001911_17_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_470_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_470_2) & 127;
  int stage_v_471_1 = ((pub_r001911_17_1 * 2) + 49) & 63;
  int stage_v_471_2 = ((pub_r001911_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_471_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_471_2) & 127;
  int stage_v_472_1 = ((pub_r001911_11_1 * 2) + 36) & 63;
  int stage_v_472_2 = ((pub_r001911_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_472_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_472_2) & 127;
  int stage_v_473_1 = ((pub_r001911_6_1 * 2) + 6) & 63;
  int stage_v_473_2 = ((pub_r001911_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_473_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_473_2) & 127;
  int stage_v_474_1 = ((pub_r001911_14_1 * 2) + 12) & 63;
  int stage_v_474_2 = ((pub_r001911_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_474_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_474_2) & 127;
  int stage_v_475_1 = ((pub_r001911_16_1 * 2) + 40) & 63;
  int stage_v_475_2 = ((pub_r001911_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_475_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_475_2) & 127;
  int stage_v_476_1 = ((pub_r001911_11_1 * 2) + 20) & 63;
  int stage_v_476_2 = ((pub_r001911_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_476_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_476_2) & 127;
  int stage_v_477_1 = ((pub_r001911_9_1 * 2) + 48) & 63;
  int stage_v_477_2 = ((pub_r001911_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_477_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_477_2) & 127;
  int stage_v_478_1 = ((pub_r001911_8_1 * 2) + 30) & 63;
  int stage_v_478_2 = ((pub_r001911_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_478_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_478_2) & 127;
  int stage_v_479_1 = ((pub_r001911_21_1 * 2) + 5) & 63;
  int stage_v_479_2 = ((pub_r001911_21_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_479_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_479_2) & 127;
  int stage_v_480_1 = ((pub_r001911_19_1 * 2) + 46) & 63;
  int stage_v_480_2 = ((pub_r001911_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_480_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_480_2) & 127;
  int stage_v_481_1 = ((pub_r001911_12_1 * 2) + 12) & 63;
  int stage_v_481_2 = ((pub_r001911_12_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_481_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_481_2) & 127;
  int stage_v_482_1 = ((pub_r001911_10_1 * 2) + 24) & 63;
  int stage_v_482_2 = ((pub_r001911_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_482_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_482_2) & 127;
  int stage_v_483_1 = ((pub_r001911_22_1 * 2) + 30) & 63;
  int stage_v_483_2 = ((pub_r001911_22_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_483_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_483_2) & 127;
  int stage_v_484_1 = ((pub_r001911_3_1 * 2) + 14) & 63;
  int stage_v_484_2 = ((pub_r001911_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_484_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_484_2) & 127;
  int stage_v_485_1 = ((pub_r001911_14_1 * 2) + 45) & 63;
  int stage_v_485_2 = ((pub_r001911_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_485_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_485_2) & 127;
  int stage_v_486_1 = ((pub_r001911_4_1 * 2) + 33) & 63;
  int stage_v_486_2 = ((pub_r001911_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_486_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_486_2) & 127;
  int stage_v_487_1 = ((pub_r001911_7_1 * 2) + 40) & 63;
  int stage_v_487_2 = ((pub_r001911_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_487_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_487_2) & 127;
  int stage_v_488_1 = ((pub_r001911_17_1 * 2) + 44) & 63;
  int stage_v_488_2 = ((pub_r001911_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_488_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_488_2) & 127;
  int stage_v_489_1 = ((pub_r001911_4_1 * 2) + 23) & 63;
  int stage_v_489_2 = ((pub_r001911_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_489_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_489_2) & 127;
  int stage_v_490_1 = ((pub_r001911_7_1 * 2) + 31) & 63;
  int stage_v_490_2 = ((pub_r001911_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_490_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_490_2) & 127;
  int stage_v_491_1 = ((pub_r001911_16_1 * 2) + 25) & 63;
  int stage_v_491_2 = ((pub_r001911_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_491_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_491_2) & 127;
  int stage_v_492_1 = ((pub_r001911_7_1 * 2) + 22) & 63;
  int stage_v_492_2 = ((pub_r001911_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_492_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_492_2) & 127;
  int stage_v_493_1 = ((pub_r001911_20_1 * 2) + 23) & 63;
  int stage_v_493_2 = ((pub_r001911_20_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_493_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_493_2) & 127;
  int stage_v_494_1 = ((pub_r001911_19_1 * 2) + 21) & 63;
  int stage_v_494_2 = ((pub_r001911_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_494_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_494_2) & 127;
  int stage_v_495_1 = ((pub_r001911_17_1 * 2) + 40) & 63;
  int stage_v_495_2 = ((pub_r001911_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_495_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_495_2) & 127;
  int stage_v_496_1 = ((pub_r001911_7_1 * 2) + 33) & 63;
  int stage_v_496_2 = ((pub_r001911_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_496_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_496_2) & 127;
  int stage_v_497_1 = ((pub_r001911_17_1 * 2) + 43) & 63;
  int stage_v_497_2 = ((pub_r001911_17_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_497_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_497_2) & 127;
  int stage_v_498_1 = ((pub_r001911_5_1 * 2) + 10) & 63;
  int stage_v_498_2 = ((pub_r001911_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_498_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_498_2) & 127;
  int stage_v_499_1 = ((pub_r001911_4_1 * 2) + 10) & 63;
  int stage_v_499_2 = ((pub_r001911_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_499_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_499_2) & 127;
  int stage_v_500_1 = ((pub_r001911_11_1 * 2) + 31) & 63;
  int stage_v_500_2 = ((pub_r001911_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_500_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_500_2) & 127;
  int stage_v_501_1 = ((pub_r001911_17_1 * 2) + 15) & 63;
  int stage_v_501_2 = ((pub_r001911_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_501_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_501_2) & 127;
  int stage_v_502_1 = ((pub_r001911_16_1 * 2) + 11) & 63;
  int stage_v_502_2 = ((pub_r001911_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_502_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_502_2) & 127;
  int stage_v_503_1 = ((pub_r001911_15_1 * 2) + 28) & 63;
  int stage_v_503_2 = ((pub_r001911_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_503_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_503_2) & 127;
  int stage_v_504_1 = ((pub_r001911_4_1 * 2) + 17) & 63;
  int stage_v_504_2 = ((pub_r001911_4_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_504_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_504_2) & 127;
  int stage_v_505_1 = ((pub_r001911_21_1 * 2) + 34) & 63;
  int stage_v_505_2 = ((pub_r001911_21_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_505_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_505_2) & 127;
  int stage_v_506_1 = ((pub_r001911_6_1 * 2) + 45) & 63;
  int stage_v_506_2 = ((pub_r001911_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_506_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_506_2) & 127;
  int stage_v_507_1 = ((pub_r001911_14_1 * 2) + 38) & 63;
  int stage_v_507_2 = ((pub_r001911_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_507_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_507_2) & 127;
  int stage_v_508_1 = ((pub_r001911_22_1 * 2) + 17) & 63;
  int stage_v_508_2 = ((pub_r001911_22_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_508_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_508_2) & 127;
  int stage_v_509_1 = ((pub_r001911_11_1 * 2) + 29) & 63;
  int stage_v_509_2 = ((pub_r001911_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_509_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_509_2) & 127;
  int stage_v_510_1 = ((pub_r001911_16_1 * 2) + 18) & 63;
  int stage_v_510_2 = ((pub_r001911_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_510_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_510_2) & 127;
  int stage_v_511_1 = ((pub_r001911_2_1 * 2) + 27) & 63;
  int stage_v_511_2 = ((pub_r001911_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_511_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_511_2) & 127;
  int stage_v_512_1 = ((pub_r001911_19_1 * 2) + 21) & 63;
  int stage_v_512_2 = ((pub_r001911_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_512_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_512_2) & 127;
  int stage_v_513_1 = ((pub_r001911_11_1 * 2) + 17) & 63;
  int stage_v_513_2 = ((pub_r001911_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_513_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_513_2) & 127;
  int stage_v_514_1 = ((pub_r001911_7_1 * 2) + 50) & 63;
  int stage_v_514_2 = ((pub_r001911_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_514_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_514_2) & 127;
  int stage_v_515_1 = ((pub_r001911_0_1 * 2) + 17) & 63;
  int stage_v_515_2 = ((pub_r001911_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_515_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_515_2) & 127;
  int stage_v_516_1 = ((pub_r001911_9_1 * 2) + 42) & 63;
  int stage_v_516_2 = ((pub_r001911_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_516_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_516_2) & 127;
  int stage_v_517_1 = ((pub_r001911_5_1 * 2) + 9) & 63;
  int stage_v_517_2 = ((pub_r001911_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_517_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_517_2) & 127;
  int stage_v_518_1 = ((pub_r001911_12_1 * 2) + 47) & 63;
  int stage_v_518_2 = ((pub_r001911_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_518_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_518_2) & 127;
  int stage_v_519_1 = ((pub_r001911_0_1 * 2) + 23) & 63;
  int stage_v_519_2 = ((pub_r001911_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_519_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_519_2) & 127;
  int stage_v_520_1 = ((pub_r001911_2_1 * 2) + 31) & 63;
  int stage_v_520_2 = ((pub_r001911_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_520_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_520_2) & 127;
  int stage_v_521_1 = ((pub_r001911_19_1 * 2) + 8) & 63;
  int stage_v_521_2 = ((pub_r001911_19_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_521_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_521_2) & 127;
  int stage_v_522_1 = ((pub_r001911_4_1 * 2) + 11) & 63;
  int stage_v_522_2 = ((pub_r001911_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_522_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_522_2) & 127;
  int stage_v_523_1 = ((pub_r001911_7_1 * 2) + 5) & 63;
  int stage_v_523_2 = ((pub_r001911_7_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_523_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_523_2) & 127;
  int stage_v_524_1 = ((pub_r001911_2_1 * 2) + 10) & 63;
  int stage_v_524_2 = ((pub_r001911_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_524_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_524_2) & 127;
  int stage_v_525_1 = ((pub_r001911_14_1 * 2) + 24) & 63;
  int stage_v_525_2 = ((pub_r001911_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_525_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_525_2) & 127;
  int stage_v_526_1 = ((pub_r001911_0_1 * 2) + 9) & 63;
  int stage_v_526_2 = ((pub_r001911_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_526_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_526_2) & 127;
  int stage_v_527_1 = ((pub_r001911_7_1 * 2) + 38) & 63;
  int stage_v_527_2 = ((pub_r001911_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_527_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_527_2) & 127;
  int stage_v_528_1 = ((pub_r001911_13_1 * 2) + 34) & 63;
  int stage_v_528_2 = ((pub_r001911_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_528_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_528_2) & 127;
  int stage_v_529_1 = ((pub_r001911_2_1 * 2) + 34) & 63;
  int stage_v_529_2 = ((pub_r001911_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_529_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_529_2) & 127;
  int stage_v_530_1 = ((pub_r001911_22_1 * 2) + 18) & 63;
  int stage_v_530_2 = ((pub_r001911_22_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_530_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_530_2) & 127;
  int stage_v_531_1 = ((pub_r001911_15_1 * 2) + 17) & 63;
  int stage_v_531_2 = ((pub_r001911_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_531_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_531_2) & 127;
  int stage_v_532_1 = ((pub_r001911_18_1 * 2) + 16) & 63;
  int stage_v_532_2 = ((pub_r001911_18_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_532_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_532_2) & 127;
  int stage_v_533_1 = ((pub_r001911_19_1 * 2) + 21) & 63;
  int stage_v_533_2 = ((pub_r001911_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_533_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_533_2) & 127;
  int stage_v_534_1 = ((pub_r001911_16_1 * 2) + 41) & 63;
  int stage_v_534_2 = ((pub_r001911_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_534_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_534_2) & 127;
  int stage_v_535_1 = ((pub_r001911_14_1 * 2) + 50) & 63;
  int stage_v_535_2 = ((pub_r001911_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_535_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_535_2) & 127;
  int stage_v_536_1 = ((pub_r001911_16_1 * 2) + 8) & 63;
  int stage_v_536_2 = ((pub_r001911_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_536_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_536_2) & 127;
  int stage_v_537_1 = ((pub_r001911_15_1 * 2) + 19) & 63;
  int stage_v_537_2 = ((pub_r001911_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_537_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_537_2) & 127;
  int stage_v_538_1 = ((pub_r001911_8_1 * 2) + 21) & 63;
  int stage_v_538_2 = ((pub_r001911_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_538_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_538_2) & 127;
  int stage_v_539_1 = ((pub_r001911_17_1 * 2) + 26) & 63;
  int stage_v_539_2 = ((pub_r001911_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_539_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_539_2) & 127;
  int stage_v_540_1 = ((pub_r001911_0_1 * 2) + 26) & 63;
  int stage_v_540_2 = ((pub_r001911_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_540_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_540_2) & 127;
  int stage_v_541_1 = ((pub_r001911_4_1 * 2) + 30) & 63;
  int stage_v_541_2 = ((pub_r001911_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_541_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_541_2) & 127;
  int stage_v_542_1 = ((pub_r001911_20_1 * 2) + 24) & 63;
  int stage_v_542_2 = ((pub_r001911_20_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_542_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_542_2) & 127;
  int stage_v_543_1 = ((pub_r001911_2_1 * 2) + 30) & 63;
  int stage_v_543_2 = ((pub_r001911_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_543_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_543_2) & 127;
  int dead_sec_0_1 = (sec_r001911_0_1 ^ sec_r001911_0_1) * 0;
  int dead_sec_0_2 = (sec_r001911_0_2 ^ sec_r001911_0_2) * 0;
  int dead_sec_1_1 = (sec_r001911_1_1 ^ sec_r001911_1_1) * 0;
  int dead_sec_1_2 = (sec_r001911_1_2 ^ sec_r001911_1_2) * 0;
  int dead_sec_2_1 = (sec_r001911_2_1 ^ sec_r001911_2_1) * 0;
  int dead_sec_2_2 = (sec_r001911_2_2 ^ sec_r001911_2_2) * 0;
  int dead_sec_3_1 = (sec_r001911_3_1 ^ sec_r001911_3_1) * 0;
  int dead_sec_3_2 = (sec_r001911_3_2 ^ sec_r001911_3_2) * 0;
  out_sink_1 = ((((out_sink_1 + dead_sec_0_1) + dead_sec_1_1) + dead_sec_2_1) + dead_sec_3_1) & 255;
  out_sink_2 = ((((out_sink_2 + dead_sec_0_2) + dead_sec_1_2) + dead_sec_2_2) + dead_sec_3_2) & 255;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (chk_sum_1 ^ 0x55) & 127;
  g_telemetry_2 = (chk_sum_2 ^ 0x55) & 127;
  __CPROVER_assume(pub_r001911_9_1 == pub_r001911_9_2);
  __CPROVER_assume(pub_r001911_5_1 == pub_r001911_5_2);
  __CPROVER_assume(pub_r001911_22_1 == pub_r001911_22_2);
  __CPROVER_assume(sec_r001911_11_1 != sec_r001911_11_2);
  __CPROVER_assume(pub_r001911_18_1 == pub_r001911_18_2);
  __CPROVER_assume(sec_r001911_1_1 != sec_r001911_1_2);
  __CPROVER_assume(pub_r001911_8_1 == pub_r001911_8_2);
  __CPROVER_assume(pub_r001911_2_1 == pub_r001911_2_2);
  __CPROVER_assume(sec_r001911_13_1 != sec_r001911_13_2);
  __CPROVER_assume(sec_r001911_0_1 != sec_r001911_0_2);
  __CPROVER_assume(pub_r001911_0_1 == pub_r001911_0_2);
  __CPROVER_assume(pub_r001911_7_1 == pub_r001911_7_2);
  __CPROVER_assume(sec_r001911_6_1 != sec_r001911_6_2);
  __CPROVER_assume(pub_r001911_13_1 == pub_r001911_13_2);
  __CPROVER_assume(sec_r001911_18_1 != sec_r001911_18_2);
  __CPROVER_assume(sec_r001911_9_1 != sec_r001911_9_2);
  __CPROVER_assume(pub_r001911_21_1 == pub_r001911_21_2);
  __CPROVER_assume(sec_r001911_10_1 != sec_r001911_10_2);
  __CPROVER_assume(sec_r001911_12_1 != sec_r001911_12_2);
  __CPROVER_assume(sec_r001911_7_1 != sec_r001911_7_2);
  __CPROVER_assume(pub_r001911_16_1 == pub_r001911_16_2);
  __CPROVER_assume(pub_r001911_19_1 == pub_r001911_19_2);
  __CPROVER_assume(pub_r001911_3_1 == pub_r001911_3_2);
  __CPROVER_assume(sec_r001911_14_1 != sec_r001911_14_2);
  __CPROVER_assume(pub_r001911_10_1 == pub_r001911_10_2);
  __CPROVER_assume(pub_r001911_15_1 == pub_r001911_15_2);
  __CPROVER_assume(sec_r001911_4_1 != sec_r001911_4_2);
  __CPROVER_assume(sec_r001911_8_1 != sec_r001911_8_2);
  __CPROVER_assume(pub_r001911_4_1 == pub_r001911_4_2);
  __CPROVER_assume(sec_r001911_15_1 != sec_r001911_15_2);
  __CPROVER_assume(pub_r001911_1_1 == pub_r001911_1_2);
  __CPROVER_assume(sec_r001911_17_1 != sec_r001911_17_2);
  __CPROVER_assume(sec_r001911_16_1 != sec_r001911_16_2);
  __CPROVER_assume(pub_r001911_6_1 == pub_r001911_6_2);
  __CPROVER_assume(pub_r001911_17_1 == pub_r001911_17_2);
  __CPROVER_assume(pub_r001911_11_1 == pub_r001911_11_2);
  __CPROVER_assume(pub_r001911_14_1 == pub_r001911_14_2);
  __CPROVER_assume(sec_r001911_5_1 != sec_r001911_5_2);
  __CPROVER_assume(sec_r001911_2_1 != sec_r001911_2_2);
  __CPROVER_assume(pub_r001911_20_1 == pub_r001911_20_2);
  __CPROVER_assume(sec_r001911_3_1 != sec_r001911_3_2);
  __CPROVER_assume(pub_r001911_12_1 == pub_r001911_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.id == st_var_2_2.id);
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
  assert(dead_sec_0_1 == dead_sec_0_2);
  assert(dead_sec_1_1 == dead_sec_1_2);
  assert(dead_sec_2_1 == dead_sec_2_2);
  assert(dead_sec_3_1 == dead_sec_3_2);
}


