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
struct EventLog_R000887_8713_0
{
  unsigned char signature;
  int seq;
  int facility;
  int timestamp;
  short severity;
  unsigned char code;
  int buffer[3];
};
struct DeviceConfig_R000887_8713_1
{
  int baud_rate;
  int id;
  int parity;
  short stop_bits;
  unsigned char timeout;
  int buffer[3];
};
struct Transaction_R000887_8713_2
{
  unsigned char status;
  unsigned char balance;
  int account_id;
  int buffer[3];
};
union ColorPixel_R000887_8713_0
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
void fn_R000887_8713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000887_8713_1 st_1 = {0};
  struct DeviceConfig_R000887_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int tracker_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_49_1)
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

  switch (tracker_49_2)
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

  int bound_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_34_1 > 33)
  {
    acc_1 = ((acc_1 + (bound_34_1 * 2)) + 5) & 127;
    aux_1 ^= bound_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_34_2 > 33)
  {
    acc_2 = ((acc_2 + (bound_34_2 * 2)) + 5) & 127;
    aux_2 ^= bound_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_34_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_49_1 == tracker_49_2);
  assert(bound_34_1 == bound_34_2);
}

int fn_R000887_8713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000887_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int tracker_49 = (aux + st.buffer[1]) & 3;
  switch (tracker_49)
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

  int bound_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_34 > 33)
  {
    acc = ((acc + (bound_34 * 2)) + 5) & 127;
    aux ^= bound_34 & 15;
  }
  else
  {
    acc = ((acc - bound_34) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000887_8713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st_1 = {0};
  struct EventLog_R000887_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int sample_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_60_1) & 63;
  aux_2 = (aux_2 + sample_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_60_1 == sample_60_2);
}

int fn_R000887_8713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int sample_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_60) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000887_8713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st_1 = {0};
  struct EventLog_R000887_8713_0 st_2 = {0};
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
  int margin_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_77_1 > 19)
  {
    acc_1 = ((acc_1 + (margin_77_1 * 2)) + 5) & 127;
    aux_1 ^= margin_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_77_2 > 19)
  {
    acc_2 = ((acc_2 + (margin_77_2 * 2)) + 5) & 127;
    aux_2 ^= margin_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_52_1) & 63;
  aux_2 = (aux_2 + weight_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_77_1 == margin_77_2);
  assert(weight_52_1 == weight_52_2);
}

int fn_R000887_8713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_77 > 19)
  {
    acc = ((acc + (margin_77 * 2)) + 5) & 127;
    aux ^= margin_77 & 15;
  }
  else
  {
    acc = ((acc - margin_77) + 11) & 127;
    aux += 3;
  }
  int weight_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_52) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000887_8713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st_1 = {0};
  struct EventLog_R000887_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int scale_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_83_1) & 63;
  aux_2 = (aux_2 + scale_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_62_1 > 45)
  {
    acc_1 = ((acc_1 + (factor_62_1 * 2)) + 5) & 127;
    aux_1 ^= factor_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_62_2 > 45)
  {
    acc_2 = ((acc_2 + (factor_62_2 * 2)) + 5) & 127;
    aux_2 ^= factor_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_62_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_83_1 == scale_83_2);
  assert(factor_62_1 == factor_62_2);
}

int fn_R000887_8713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int scale_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_83) & 63;
  acc ^= aux;
  int factor_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_62 > 45)
  {
    acc = ((acc + (factor_62 * 2)) + 5) & 127;
    aux ^= factor_62 & 15;
  }
  else
  {
    acc = ((acc - factor_62) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000887_8713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st_1 = {0};
  struct EventLog_R000887_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_98_1 = local_arr_1[aux_1 % 3];
  int damping_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_98_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_98_1 == damping_98_2);
}

int fn_R000887_8713_4(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int damping_98 = local_arr[aux % 3];
  acc = (acc + (damping_98 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000887_8713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000887_8713_2 st_1 = {0};
  struct Transaction_R000887_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int scale_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_87_1)
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

  switch (scale_87_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_85_1) & 63;
  aux_2 = (aux_2 + residue_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_87_1 == scale_87_2);
  assert(residue_85_1 == residue_85_2);
}

int fn_R000887_8713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000887_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int scale_87 = (aux + st.buffer[1]) & 3;
  switch (scale_87)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_85) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000887_8713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000887_8713_1 st_1 = {0};
  struct DeviceConfig_R000887_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_21_1 = local_arr_1[aux_1 % 3];
  int coefficient_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_21_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_85_1 > 16)
  {
    acc_1 = ((acc_1 + (weight_85_1 * 2)) + 5) & 127;
    aux_1 ^= weight_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_85_2 > 16)
  {
    acc_2 = ((acc_2 + (weight_85_2 * 2)) + 5) & 127;
    aux_2 ^= weight_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_92_1)
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

  switch (checksum_92_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_21_1 == coefficient_21_2);
  assert(weight_85_1 == weight_85_2);
  assert(checksum_92_1 == checksum_92_2);
}

int fn_R000887_8713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000887_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int coefficient_21 = local_arr[aux % 3];
  acc = (acc + (coefficient_21 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_85 > 16)
  {
    acc = ((acc + (weight_85 * 2)) + 5) & 127;
    aux ^= weight_85 & 15;
  }
  else
  {
    acc = ((acc - weight_85) + 11) & 127;
    aux += 3;
  }
  int checksum_92 = (aux + st.buffer[1]) & 3;
  switch (checksum_92)
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

void fn_R000887_8713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st_1 = {0};
  struct EventLog_R000887_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_20_1 = local_arr_1[aux_1 % 3];
  int delta_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_20_2 * 2)) & 127;
  int metric_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_49_1 > 50)
  {
    acc_1 = ((acc_1 + (metric_49_1 * 2)) + 5) & 127;
    aux_1 ^= metric_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_49_2 > 50)
  {
    acc_2 = ((acc_2 + (metric_49_2 * 2)) + 5) & 127;
    aux_2 ^= metric_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_49_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_84_1)
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

  switch (factor_84_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_20_1 == delta_20_2);
  assert(metric_49_1 == metric_49_2);
  assert(factor_84_1 == factor_84_2);
}

int fn_R000887_8713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int delta_20 = local_arr[aux % 3];
  acc = (acc + (delta_20 * 2)) & 127;
  int metric_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_49 > 50)
  {
    acc = ((acc + (metric_49 * 2)) + 5) & 127;
    aux ^= metric_49 & 15;
  }
  else
  {
    acc = ((acc - metric_49) + 11) & 127;
    aux += 3;
  }
  int factor_84 = (aux + st.buffer[1]) & 3;
  switch (factor_84)
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

void fn_R000887_8713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000887_8713_2 st_1 = {0};
  struct Transaction_R000887_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_65_1) & 63;
  aux_2 = (aux_2 + margin_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_33_1)
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

  switch (margin_33_2)
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
  int residue_68_1 = local_arr_1[aux_1 % 3];
  int residue_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_65_1 == margin_65_2);
  assert(margin_33_1 == margin_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_68_1 == residue_68_2);
}

int fn_R000887_8713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000887_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_65) & 63;
  acc ^= aux;
  int margin_33 = (aux + st.buffer[1]) & 3;
  switch (margin_33)
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
  int residue_68 = local_arr[aux % 3];
  acc = (acc + (residue_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000887_8713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st_1 = {0};
  struct EventLog_R000887_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int segment_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_64_1 > 11)
  {
    acc_1 = ((acc_1 + (segment_64_1 * 2)) + 5) & 127;
    aux_1 ^= segment_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_64_2 > 11)
  {
    acc_2 = ((acc_2 + (segment_64_2 * 2)) + 5) & 127;
    aux_2 ^= segment_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_64_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_28_1)
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

  switch (index_reg_28_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_64_1 == segment_64_2);
  assert(index_reg_28_1 == index_reg_28_2);
}

int fn_R000887_8713_9(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int segment_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_64 > 11)
  {
    acc = ((acc + (segment_64 * 2)) + 5) & 127;
    aux ^= segment_64 & 15;
  }
  else
  {
    acc = ((acc - segment_64) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_28 = (aux + st.buffer[1]) & 3;
  switch (index_reg_28)
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

void fn_R000887_8713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000887_8713_2 st_1 = {0};
  struct Transaction_R000887_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_83_1 > 34)
  {
    acc_1 = ((acc_1 + (pivot_83_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_83_2 > 34)
  {
    acc_2 = ((acc_2 + (pivot_83_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_83_1 == pivot_83_2);
}

int fn_R000887_8713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000887_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_83 > 34)
  {
    acc = ((acc + (pivot_83 * 2)) + 5) & 127;
    aux ^= pivot_83 & 15;
  }
  else
  {
    acc = ((acc - pivot_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000887_8713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st_1 = {0};
  struct EventLog_R000887_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int vector_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_18_1)
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

  switch (vector_18_2)
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

  int accumulator_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_84_1 > 30)
  {
    acc_1 = ((acc_1 + (accumulator_84_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_84_2 > 30)
  {
    acc_2 = ((acc_2 + (accumulator_84_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_84_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_18_1 == vector_18_2);
  assert(accumulator_84_1 == accumulator_84_2);
}

int fn_R000887_8713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int vector_18 = (aux + st.buffer[1]) & 3;
  switch (vector_18)
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

  int accumulator_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_84 > 30)
  {
    acc = ((acc + (accumulator_84 * 2)) + 5) & 127;
    aux ^= accumulator_84 & 15;
  }
  else
  {
    acc = ((acc - accumulator_84) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000887_8713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st_1 = {0};
  struct EventLog_R000887_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int threshold_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_76_1) & 63;
  aux_2 = (aux_2 + threshold_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_29_1)
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

  switch (quantum_29_2)
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
  int index_reg_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_25_1 > 34)
  {
    acc_1 = ((acc_1 + (index_reg_25_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_25_2 > 34)
  {
    acc_2 = ((acc_2 + (index_reg_25_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_25_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_76_1 == threshold_76_2);
  assert(quantum_29_1 == quantum_29_2);
  assert(index_reg_25_1 == index_reg_25_2);
}

int fn_R000887_8713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int threshold_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_76) & 63;
  acc ^= aux;
  int quantum_29 = (aux + st.buffer[1]) & 3;
  switch (quantum_29)
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
  int index_reg_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_25 > 34)
  {
    acc = ((acc + (index_reg_25 * 2)) + 5) & 127;
    aux ^= index_reg_25 & 15;
  }
  else
  {
    acc = ((acc - index_reg_25) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000887_8713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st_1 = {0};
  struct EventLog_R000887_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int coefficient_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_86_1 > 21)
  {
    acc_1 = ((acc_1 + (coefficient_86_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_86_2 > 21)
  {
    acc_2 = ((acc_2 + (coefficient_86_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_39_1)
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

  switch (tally_39_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_86_1 == coefficient_86_2);
  assert(tally_39_1 == tally_39_2);
}

int fn_R000887_8713_13(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int coefficient_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_86 > 21)
  {
    acc = ((acc + (coefficient_86 * 2)) + 5) & 127;
    aux ^= coefficient_86 & 15;
  }
  else
  {
    acc = ((acc - coefficient_86) + 11) & 127;
    aux += 3;
  }
  int tally_39 = (aux + st.buffer[1]) & 3;
  switch (tally_39)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000887_8713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000887_8713_1 st_1 = {0};
  struct DeviceConfig_R000887_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_14_1 = local_arr_1[aux_1 % 3];
  int factor_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_14_2 * 2)) & 127;
  int tally_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_74_1 > 18)
  {
    acc_1 = ((acc_1 + (tally_74_1 * 2)) + 5) & 127;
    aux_1 ^= tally_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_74_2 > 18)
  {
    acc_2 = ((acc_2 + (tally_74_2 * 2)) + 5) & 127;
    aux_2 ^= tally_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_80_1) & 63;
  aux_2 = (aux_2 + anchor_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_69_1)
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

  switch (pivot_69_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_14_1 == factor_14_2);
  assert(tally_74_1 == tally_74_2);
  assert(anchor_80_1 == anchor_80_2);
  assert(pivot_69_1 == pivot_69_2);
}

int fn_R000887_8713_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000887_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int factor_14 = local_arr[aux % 3];
  acc = (acc + (factor_14 * 2)) & 127;
  int tally_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_74 > 18)
  {
    acc = ((acc + (tally_74 * 2)) + 5) & 127;
    aux ^= tally_74 & 15;
  }
  else
  {
    acc = ((acc - tally_74) + 11) & 127;
    aux += 3;
  }
  int anchor_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_80) & 63;
  acc ^= aux;
  int pivot_69 = (aux + st.buffer[1]) & 3;
  switch (pivot_69)
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

void fn_R000887_8713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000887_8713_1 st_1 = {0};
  struct DeviceConfig_R000887_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_16_1 = local_arr_1[aux_1 % 3];
  int cursor_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_16_2 * 2)) & 127;
  int segment_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_70_1) & 63;
  aux_2 = (aux_2 + segment_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_74_1)
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

  switch (cursor_74_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_16_1 == cursor_16_2);
  assert(segment_70_1 == segment_70_2);
  assert(cursor_74_1 == cursor_74_2);
}

int fn_R000887_8713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000887_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int cursor_16 = local_arr[aux % 3];
  acc = (acc + (cursor_16 * 2)) & 127;
  int segment_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_70) & 63;
  acc ^= aux;
  int cursor_74 = (aux + st.buffer[1]) & 3;
  switch (cursor_74)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000887_8713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st_1 = {0};
  struct EventLog_R000887_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int cursor_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_17_1) & 63;
  aux_2 = (aux_2 + cursor_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_89_1 > 11)
  {
    acc_1 = ((acc_1 + (parity_89_1 * 2)) + 5) & 127;
    aux_1 ^= parity_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_89_2 > 11)
  {
    acc_2 = ((acc_2 + (parity_89_2 * 2)) + 5) & 127;
    aux_2 ^= parity_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_48_1)
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

  switch (factor_48_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_17_1 == cursor_17_2);
  assert(parity_89_1 == parity_89_2);
  assert(factor_48_1 == factor_48_2);
}

int fn_R000887_8713_16(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000887_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int cursor_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_17) & 63;
  acc ^= aux;
  int parity_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_89 > 11)
  {
    acc = ((acc + (parity_89 * 2)) + 5) & 127;
    aux ^= parity_89 & 15;
  }
  else
  {
    acc = ((acc - parity_89) + 11) & 127;
    aux += 3;
  }
  int factor_48 = (aux + st.buffer[1]) & 3;
  switch (factor_48)
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

void fn_R000887_8713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000887_8713_2 st_1 = {0};
  struct Transaction_R000887_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int threshold_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_77_1)
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

  switch (threshold_77_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_91_1) & 63;
  aux_2 = (aux_2 + weight_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_95_1 = local_arr_1[aux_1 % 3];
  int pivot_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_77_1 == threshold_77_2);
  assert(weight_91_1 == weight_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_95_1 == pivot_95_2);
}

int fn_R000887_8713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000887_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int threshold_77 = (aux + st.buffer[1]) & 3;
  switch (threshold_77)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_91) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_95 = local_arr[aux % 3];
  acc = (acc + (pivot_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000887_8713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000887_8713_2 st_1 = {0};
  struct Transaction_R000887_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int quantum_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_88_1 > 11)
  {
    acc_1 = ((acc_1 + (quantum_88_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_88_2 > 11)
  {
    acc_2 = ((acc_2 + (quantum_88_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_88_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_77_1) & 63;
  aux_2 = (aux_2 + delta_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_14_1)
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

  switch (checksum_14_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_88_1 == quantum_88_2);
  assert(delta_77_1 == delta_77_2);
  assert(checksum_14_1 == checksum_14_2);
}

int fn_R000887_8713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000887_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int quantum_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_88 > 11)
  {
    acc = ((acc + (quantum_88 * 2)) + 5) & 127;
    aux ^= quantum_88 & 15;
  }
  else
  {
    acc = ((acc - quantum_88) + 11) & 127;
    aux += 3;
  }
  int delta_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_77) & 63;
  acc ^= aux;
  int checksum_14 = (aux + st.buffer[1]) & 3;
  switch (checksum_14)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000887_8713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000887_8713_1 st_1 = {0};
  struct DeviceConfig_R000887_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_59_1) & 63;
  aux_2 = (aux_2 + accumulator_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_59_1 == accumulator_59_2);
}

int fn_R000887_8713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000887_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_59) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000887_8713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000887_8713_2 st_1 = {0};
  struct Transaction_R000887_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_51_1 = local_arr_1[aux_1 % 3];
  int tally_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_51_1 == tally_51_2);
}

int fn_R000887_8713_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000887_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_51 = local_arr[aux % 3];
  acc = (acc + (tally_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000887_0_1;
  int sec_r000887_0_2;
  int sec_r000887_1_1;
  int sec_r000887_1_2;
  int sec_r000887_2_1;
  int sec_r000887_2_2;
  int sec_r000887_3_1;
  int sec_r000887_3_2;
  int sec_r000887_4_1;
  int sec_r000887_4_2;
  int sec_r000887_5_1;
  int sec_r000887_5_2;
  int sec_r000887_6_1;
  int sec_r000887_6_2;
  int sec_r000887_7_1;
  int sec_r000887_7_2;
  int sec_r000887_8_1;
  int sec_r000887_8_2;
  int sec_r000887_9_1;
  int sec_r000887_9_2;
  int sec_r000887_10_1;
  int sec_r000887_10_2;
  int sec_r000887_11_1;
  int sec_r000887_11_2;
  int sec_r000887_12_1;
  int sec_r000887_12_2;
  int sec_r000887_13_1;
  int sec_r000887_13_2;
  int sec_r000887_14_1;
  int sec_r000887_14_2;
  int sec_r000887_15_1;
  int sec_r000887_15_2;
  int sec_r000887_16_1;
  int sec_r000887_16_2;
  int sec_r000887_17_1;
  int sec_r000887_17_2;
  int sec_r000887_18_1;
  int sec_r000887_18_2;
  int sec_r000887_19_1;
  int sec_r000887_19_2;
  int sec_r000887_20_1;
  int sec_r000887_20_2;
  int pub_r000887_0_1;
  int pub_r000887_0_2;
  int pub_r000887_1_1;
  int pub_r000887_1_2;
  int pub_r000887_2_1;
  int pub_r000887_2_2;
  int pub_r000887_3_1;
  int pub_r000887_3_2;
  int pub_r000887_4_1;
  int pub_r000887_4_2;
  int pub_r000887_5_1;
  int pub_r000887_5_2;
  int pub_r000887_6_1;
  int pub_r000887_6_2;
  int pub_r000887_7_1;
  int pub_r000887_7_2;
  int pub_r000887_8_1;
  int pub_r000887_8_2;
  int pub_r000887_9_1;
  int pub_r000887_9_2;
  int pub_r000887_10_1;
  int pub_r000887_10_2;
  int pub_r000887_11_1;
  int pub_r000887_11_2;
  int pub_r000887_12_1;
  int pub_r000887_12_2;
  int pub_r000887_13_1;
  int pub_r000887_13_2;
  int pub_r000887_14_1;
  int pub_r000887_14_2;
  int pub_r000887_15_1;
  int pub_r000887_15_2;
  int pub_r000887_16_1;
  int pub_r000887_16_2;
  int pub_r000887_17_1;
  int pub_r000887_17_2;
  int pub_r000887_18_1;
  int pub_r000887_18_2;
  int pub_r000887_19_1;
  int pub_r000887_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000887_0_1 >= (-100)) && (pub_r000887_0_1 <= 100));
  __CPROVER_assume((pub_r000887_0_2 >= (-100)) && (pub_r000887_0_2 <= 100));
  __CPROVER_assume((pub_r000887_1_1 >= (-100)) && (pub_r000887_1_1 <= 100));
  __CPROVER_assume((pub_r000887_1_2 >= (-100)) && (pub_r000887_1_2 <= 100));
  __CPROVER_assume((pub_r000887_2_1 >= (-100)) && (pub_r000887_2_1 <= 100));
  __CPROVER_assume((pub_r000887_2_2 >= (-100)) && (pub_r000887_2_2 <= 100));
  __CPROVER_assume((pub_r000887_3_1 >= (-100)) && (pub_r000887_3_1 <= 100));
  __CPROVER_assume((pub_r000887_3_2 >= (-100)) && (pub_r000887_3_2 <= 100));
  __CPROVER_assume((pub_r000887_4_1 >= (-100)) && (pub_r000887_4_1 <= 100));
  __CPROVER_assume((pub_r000887_4_2 >= (-100)) && (pub_r000887_4_2 <= 100));
  __CPROVER_assume((pub_r000887_5_1 >= (-100)) && (pub_r000887_5_1 <= 100));
  __CPROVER_assume((pub_r000887_5_2 >= (-100)) && (pub_r000887_5_2 <= 100));
  __CPROVER_assume((pub_r000887_6_1 >= (-100)) && (pub_r000887_6_1 <= 100));
  __CPROVER_assume((pub_r000887_6_2 >= (-100)) && (pub_r000887_6_2 <= 100));
  __CPROVER_assume((pub_r000887_7_1 >= (-100)) && (pub_r000887_7_1 <= 100));
  __CPROVER_assume((pub_r000887_7_2 >= (-100)) && (pub_r000887_7_2 <= 100));
  __CPROVER_assume((pub_r000887_8_1 >= (-100)) && (pub_r000887_8_1 <= 100));
  __CPROVER_assume((pub_r000887_8_2 >= (-100)) && (pub_r000887_8_2 <= 100));
  __CPROVER_assume((pub_r000887_9_1 >= (-100)) && (pub_r000887_9_1 <= 100));
  __CPROVER_assume((pub_r000887_9_2 >= (-100)) && (pub_r000887_9_2 <= 100));
  __CPROVER_assume((pub_r000887_10_1 >= (-100)) && (pub_r000887_10_1 <= 100));
  __CPROVER_assume((pub_r000887_10_2 >= (-100)) && (pub_r000887_10_2 <= 100));
  __CPROVER_assume((pub_r000887_11_1 >= (-100)) && (pub_r000887_11_1 <= 100));
  __CPROVER_assume((pub_r000887_11_2 >= (-100)) && (pub_r000887_11_2 <= 100));
  __CPROVER_assume((pub_r000887_12_1 >= (-100)) && (pub_r000887_12_1 <= 100));
  __CPROVER_assume((pub_r000887_12_2 >= (-100)) && (pub_r000887_12_2 <= 100));
  __CPROVER_assume((pub_r000887_13_1 >= (-100)) && (pub_r000887_13_1 <= 100));
  __CPROVER_assume((pub_r000887_13_2 >= (-100)) && (pub_r000887_13_2 <= 100));
  __CPROVER_assume((pub_r000887_14_1 >= (-100)) && (pub_r000887_14_1 <= 100));
  __CPROVER_assume((pub_r000887_14_2 >= (-100)) && (pub_r000887_14_2 <= 100));
  __CPROVER_assume((pub_r000887_15_1 >= (-100)) && (pub_r000887_15_1 <= 100));
  __CPROVER_assume((pub_r000887_15_2 >= (-100)) && (pub_r000887_15_2 <= 100));
  __CPROVER_assume((pub_r000887_16_1 >= (-100)) && (pub_r000887_16_1 <= 100));
  __CPROVER_assume((pub_r000887_16_2 >= (-100)) && (pub_r000887_16_2 <= 100));
  __CPROVER_assume((pub_r000887_17_1 >= (-100)) && (pub_r000887_17_1 <= 100));
  __CPROVER_assume((pub_r000887_17_2 >= (-100)) && (pub_r000887_17_2 <= 100));
  __CPROVER_assume((pub_r000887_18_1 >= (-100)) && (pub_r000887_18_1 <= 100));
  __CPROVER_assume((pub_r000887_18_2 >= (-100)) && (pub_r000887_18_2 <= 100));
  __CPROVER_assume((pub_r000887_19_1 >= (-100)) && (pub_r000887_19_1 <= 100));
  __CPROVER_assume((pub_r000887_19_2 >= (-100)) && (pub_r000887_19_2 <= 100));
  __CPROVER_assume((sec_r000887_0_1 >= 0) && (sec_r000887_0_1 <= 255));
  __CPROVER_assume((sec_r000887_0_2 >= 0) && (sec_r000887_0_2 <= 255));
  __CPROVER_assume((sec_r000887_1_1 >= 0) && (sec_r000887_1_1 <= 255));
  __CPROVER_assume((sec_r000887_1_2 >= 0) && (sec_r000887_1_2 <= 255));
  __CPROVER_assume((sec_r000887_2_1 >= 0) && (sec_r000887_2_1 <= 255));
  __CPROVER_assume((sec_r000887_2_2 >= 0) && (sec_r000887_2_2 <= 255));
  __CPROVER_assume((sec_r000887_3_1 >= 0) && (sec_r000887_3_1 <= 255));
  __CPROVER_assume((sec_r000887_3_2 >= 0) && (sec_r000887_3_2 <= 255));
  __CPROVER_assume((sec_r000887_4_1 >= 0) && (sec_r000887_4_1 <= 255));
  __CPROVER_assume((sec_r000887_4_2 >= 0) && (sec_r000887_4_2 <= 255));
  __CPROVER_assume((sec_r000887_5_1 >= 0) && (sec_r000887_5_1 <= 255));
  __CPROVER_assume((sec_r000887_5_2 >= 0) && (sec_r000887_5_2 <= 255));
  __CPROVER_assume((sec_r000887_6_1 >= 0) && (sec_r000887_6_1 <= 255));
  __CPROVER_assume((sec_r000887_6_2 >= 0) && (sec_r000887_6_2 <= 255));
  __CPROVER_assume((sec_r000887_7_1 >= 0) && (sec_r000887_7_1 <= 255));
  __CPROVER_assume((sec_r000887_7_2 >= 0) && (sec_r000887_7_2 <= 255));
  __CPROVER_assume((sec_r000887_8_1 >= 0) && (sec_r000887_8_1 <= 255));
  __CPROVER_assume((sec_r000887_8_2 >= 0) && (sec_r000887_8_2 <= 255));
  __CPROVER_assume((sec_r000887_9_1 >= 0) && (sec_r000887_9_1 <= 255));
  __CPROVER_assume((sec_r000887_9_2 >= 0) && (sec_r000887_9_2 <= 255));
  __CPROVER_assume((sec_r000887_10_1 >= 0) && (sec_r000887_10_1 <= 255));
  __CPROVER_assume((sec_r000887_10_2 >= 0) && (sec_r000887_10_2 <= 255));
  __CPROVER_assume((sec_r000887_11_1 >= 0) && (sec_r000887_11_1 <= 255));
  __CPROVER_assume((sec_r000887_11_2 >= 0) && (sec_r000887_11_2 <= 255));
  __CPROVER_assume((sec_r000887_12_1 >= 0) && (sec_r000887_12_1 <= 255));
  __CPROVER_assume((sec_r000887_12_2 >= 0) && (sec_r000887_12_2 <= 255));
  __CPROVER_assume((sec_r000887_13_1 >= 0) && (sec_r000887_13_1 <= 255));
  __CPROVER_assume((sec_r000887_13_2 >= 0) && (sec_r000887_13_2 <= 255));
  __CPROVER_assume((sec_r000887_14_1 >= 0) && (sec_r000887_14_1 <= 255));
  __CPROVER_assume((sec_r000887_14_2 >= 0) && (sec_r000887_14_2 <= 255));
  __CPROVER_assume((sec_r000887_15_1 >= 0) && (sec_r000887_15_1 <= 255));
  __CPROVER_assume((sec_r000887_15_2 >= 0) && (sec_r000887_15_2 <= 255));
  __CPROVER_assume((sec_r000887_16_1 >= 0) && (sec_r000887_16_1 <= 255));
  __CPROVER_assume((sec_r000887_16_2 >= 0) && (sec_r000887_16_2 <= 255));
  __CPROVER_assume((sec_r000887_17_1 >= 0) && (sec_r000887_17_1 <= 255));
  __CPROVER_assume((sec_r000887_17_2 >= 0) && (sec_r000887_17_2 <= 255));
  __CPROVER_assume((sec_r000887_18_1 >= 0) && (sec_r000887_18_1 <= 255));
  __CPROVER_assume((sec_r000887_18_2 >= 0) && (sec_r000887_18_2 <= 255));
  __CPROVER_assume((sec_r000887_19_1 >= 0) && (sec_r000887_19_1 <= 255));
  __CPROVER_assume((sec_r000887_19_2 >= 0) && (sec_r000887_19_2 <= 255));
  __CPROVER_assume((sec_r000887_20_1 >= 0) && (sec_r000887_20_1 <= 255));
  __CPROVER_assume((sec_r000887_20_2 >= 0) && (sec_r000887_20_2 <= 255));
  struct EventLog_R000887_8713_0 st_var_0_1 = {0};
  struct EventLog_R000887_8713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000887_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000887_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000887_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000887_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000887_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000887_0_2 + 7) & 15;
  struct DeviceConfig_R000887_8713_1 st_var_1_1 = {0};
  struct DeviceConfig_R000887_8713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000887_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000887_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000887_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000887_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000887_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000887_0_2 + 9) & 15;
  struct Transaction_R000887_8713_2 st_var_2_1 = {0};
  struct Transaction_R000887_8713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000887_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000887_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000887_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000887_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000887_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000887_0_2 + 11) & 15;
  union ColorPixel_R000887_8713_0 u_var_1;
  union ColorPixel_R000887_8713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_0_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_0_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_0_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
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
  int stage_v_6_1 = (st_var_0_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_0_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (st_var_0_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_0_2.buffer[0] ^ 12) & 3;
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 11) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = (st_var_0_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_0_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = ((st_var_1_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_1_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 27)
    {
      chk_sum_1 ^= stage_v_16_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_16_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 27)
    {
      chk_sum_2 ^= stage_v_16_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = ((st_var_1_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_1_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 49)
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
  if (stage_v_19_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 49)
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
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((st_var_0_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_0_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 51)
    {
      chk_sum_1 ^= stage_v_21_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_21_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 51)
    {
      chk_sum_2 ^= stage_v_21_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 25) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 25) & 15;
  int stage_v_24_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_24_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= stage_v_24_1;
  chk_sum_2 ^= stage_v_24_2;
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 44)
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
  if (stage_v_26_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 44)
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
  int stage_v_28_1 = ((st_var_1_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_1_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 43)
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
  if (stage_v_28_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 43)
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
  int stage_v_29_1 = (st_var_2_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_2_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 31) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  int stage_v_32_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_32_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_32_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_32_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_33_1 = ((stage_v_33_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_33_2 = ((stage_v_33_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 30)
    {
      chk_sum_1 ^= stage_v_36_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_36_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 30)
    {
      chk_sum_2 ^= stage_v_36_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_37_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_37_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 40) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_40_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_40_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_40_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_43_1 = ((st_var_1_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_1_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 31)
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
  if (stage_v_43_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 31)
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
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_45_1 = ((st_var_0_1.buffer[0] * 2) + 142) & 63;
  int stage_v_45_2 = ((st_var_0_2.buffer[0] * 2) + 142) & 63;
  if (stage_v_45_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_45_1) - 5) & 255;
    if (stage_v_45_1 > 37)
    {
      chk_sum_1 ^= stage_v_45_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_45_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_45_2) - 5) & 255;
    if (stage_v_45_2 > 37)
    {
      chk_sum_2 ^= stage_v_45_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
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
  int stage_v_47_1 = ((st_var_2_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_2_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 51)
    {
      chk_sum_1 ^= stage_v_47_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_47_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 51)
    {
      chk_sum_2 ^= stage_v_47_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (54 & 31);
  int stage_v_49_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (54 & 31);
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= (stage_v_49_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_49_2 << 1) & 127;
  int stage_v_50_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_50_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = table_1[0];
  int stage_v_52_2 = table_2[0];
  table_1[0] = (table_1[1] + 105) & 63;
  table_2[0] = (table_2[1] + 105) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_53_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 56) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 56) & 15;
  int stage_v_55_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_55_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= stage_v_55_1;
  chk_sum_2 ^= stage_v_55_2;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((st_var_0_1.buffer[0] * 2) + 178) & 63;
  int stage_v_57_2 = ((st_var_0_2.buffer[0] * 2) + 178) & 63;
  if (stage_v_57_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_57_1) - 5) & 255;
    if (stage_v_57_1 > 25)
    {
      chk_sum_1 ^= stage_v_57_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_57_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_57_2) - 5) & 255;
    if (stage_v_57_2 > 25)
    {
      chk_sum_2 ^= stage_v_57_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (64 & 31);
  int stage_v_59_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (64 & 31);
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= (stage_v_59_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_59_2 << 1) & 127;
  int stage_v_60_1 = (st_var_0_1.buffer[0] ^ 63) & 3;
  int stage_v_60_2 = (st_var_0_2.buffer[0] ^ 63) & 3;
  switch (stage_v_60_1)
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

  switch (stage_v_60_2)
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

  int stage_v_61_1 = (st_var_1_1.buffer[0] ^ 64) & 3;
  int stage_v_61_2 = (st_var_1_2.buffer[0] ^ 64) & 3;
  switch (stage_v_61_1)
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

  switch (stage_v_61_2)
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

  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((sec_r000887_10_1 & 1) != 0)
  {
    if ((sec_r000887_3_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000887_10_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000887_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000887_10_1 + 7) & 127;
  }
  if ((sec_r000887_10_2 & 1) != 0)
  {
    if ((sec_r000887_3_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000887_10_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000887_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000887_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000887_20_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000887_5_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000887_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000887_5_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000887_20_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000887_5_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000887_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000887_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000887_1_1 & 1) != 0)
  {
    if ((sec_r000887_1_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000887_15_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000887_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000887_15_1 + 7) & 127;
  }
  if ((sec_r000887_1_2 & 1) != 0)
  {
    if ((sec_r000887_1_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000887_15_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000887_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000887_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000887_14_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000887_7_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000887_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000887_7_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000887_14_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000887_7_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000887_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000887_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000887_8_1 & 1) != 0)
  {
    if ((sec_r000887_16_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000887_17_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000887_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000887_17_1 + 7) & 127;
  }
  if ((sec_r000887_8_2 & 1) != 0)
  {
    if ((sec_r000887_16_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000887_17_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000887_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000887_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000887_16_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000887_6_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000887_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000887_6_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000887_16_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000887_6_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000887_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000887_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000887_9_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000887_3_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000887_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000887_3_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000887_9_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000887_3_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000887_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000887_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000887_8_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000887_9_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000887_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000887_9_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000887_8_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000887_9_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000887_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000887_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000887_3_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000887_12_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000887_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000887_12_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000887_3_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000887_12_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000887_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000887_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000887_1_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000887_0_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000887_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000887_0_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000887_1_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000887_0_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000887_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000887_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000887_3_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000887_11_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000887_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000887_11_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000887_3_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000887_11_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000887_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000887_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000887_0_1 & 1) != 0)
  {
    if ((sec_r000887_12_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000887_17_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000887_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000887_17_1 + 7) & 127;
  }
  if ((sec_r000887_0_2 & 1) != 0)
  {
    if ((sec_r000887_12_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000887_17_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000887_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000887_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000887_8_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000887_13_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000887_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000887_13_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000887_8_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000887_13_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000887_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000887_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000887_20_1 & 1) != 0)
  {
    if ((sec_r000887_4_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000887_11_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000887_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000887_11_1 + 7) & 127;
  }
  if ((sec_r000887_20_2 & 1) != 0)
  {
    if ((sec_r000887_4_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000887_11_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000887_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000887_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000887_1_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000887_18_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000887_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000887_18_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000887_1_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000887_18_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000887_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000887_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000887_11_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000887_14_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000887_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000887_14_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000887_11_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000887_14_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000887_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000887_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000887_2_1 & 1) != 0)
  {
    if ((sec_r000887_20_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000887_2_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000887_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000887_2_1 + 7) & 127;
  }
  if ((sec_r000887_2_2 & 1) != 0)
  {
    if ((sec_r000887_20_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000887_2_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000887_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000887_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000887_8_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000887_18_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000887_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000887_18_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000887_8_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000887_18_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000887_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000887_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000887_0_1 & 1) != 0)
  {
    if ((sec_r000887_0_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000887_3_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000887_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000887_3_1 + 7) & 127;
  }
  if ((sec_r000887_0_2 & 1) != 0)
  {
    if ((sec_r000887_0_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000887_3_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000887_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000887_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000887_10_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000887_1_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000887_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000887_1_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000887_10_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000887_1_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000887_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000887_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000887_5_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000887_4_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000887_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000887_4_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000887_5_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000887_4_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000887_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000887_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000887_0_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000887_18_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000887_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000887_18_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000887_0_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000887_18_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000887_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000887_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000887_9_1 & 1) != 0)
  {
    if ((sec_r000887_9_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000887_2_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000887_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000887_2_1 + 7) & 127;
  }
  if ((sec_r000887_9_2 & 1) != 0)
  {
    if ((sec_r000887_9_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000887_2_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000887_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000887_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000887_1_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000887_18_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000887_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000887_18_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000887_1_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000887_18_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000887_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000887_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000887_9_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000887_14_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000887_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000887_14_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000887_9_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000887_14_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000887_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000887_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((sec_r000887_6_1 & 1) != 0)
  {
    if ((sec_r000887_20_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000887_0_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000887_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000887_0_1 + 7) & 127;
  }
  if ((sec_r000887_6_2 & 1) != 0)
  {
    if ((sec_r000887_20_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000887_0_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000887_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000887_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000887_13_1 & 1) != 0)
  {
    if ((sec_r000887_3_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000887_6_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000887_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000887_6_1 + 7) & 127;
  }
  if ((sec_r000887_13_2 & 1) != 0)
  {
    if ((sec_r000887_3_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000887_6_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000887_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000887_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000887_20_1 & 1) != 0)
  {
    if ((sec_r000887_17_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000887_1_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000887_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000887_1_1 + 7) & 127;
  }
  if ((sec_r000887_20_2 & 1) != 0)
  {
    if ((sec_r000887_17_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000887_1_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000887_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000887_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000887_6_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000887_17_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000887_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000887_17_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000887_6_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000887_17_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000887_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000887_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000887_3_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000887_6_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000887_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000887_6_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000887_3_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000887_6_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000887_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000887_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000887_19_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000887_18_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000887_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000887_18_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000887_19_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000887_18_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000887_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000887_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000887_0_1 & 1) != 0)
  {
    if ((sec_r000887_4_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000887_3_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000887_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000887_3_1 + 7) & 127;
  }
  if ((sec_r000887_0_2 & 1) != 0)
  {
    if ((sec_r000887_4_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000887_3_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000887_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000887_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000887_0_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000887_8_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000887_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000887_8_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000887_0_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000887_8_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000887_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000887_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000887_4_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000887_10_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000887_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000887_10_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000887_4_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000887_10_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000887_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000887_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000887_1_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000887_8_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000887_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000887_8_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000887_1_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000887_8_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000887_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000887_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000887_9_1 & 1) != 0)
  {
    if ((sec_r000887_20_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000887_18_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000887_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000887_18_1 + 7) & 127;
  }
  if ((sec_r000887_9_2 & 1) != 0)
  {
    if ((sec_r000887_20_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000887_18_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000887_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000887_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000887_1_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000887_14_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000887_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000887_14_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000887_1_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000887_14_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000887_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000887_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000887_10_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000887_13_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000887_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000887_13_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000887_10_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000887_13_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000887_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000887_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000887_9_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000887_14_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000887_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000887_14_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000887_9_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000887_14_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000887_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000887_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000887_16_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000887_14_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000887_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000887_14_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000887_16_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000887_14_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000887_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000887_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000887_12_1 & 1) != 0)
  {
    if ((sec_r000887_6_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000887_15_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000887_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000887_15_1 + 7) & 127;
  }
  if ((sec_r000887_12_2 & 1) != 0)
  {
    if ((sec_r000887_6_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000887_15_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000887_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000887_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000887_11_1 & 1) != 0)
  {
    if ((sec_r000887_13_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000887_11_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000887_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000887_11_1 + 7) & 127;
  }
  if ((sec_r000887_11_2 & 1) != 0)
  {
    if ((sec_r000887_13_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000887_11_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000887_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000887_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000887_7_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000887_14_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000887_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000887_14_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000887_7_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000887_14_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000887_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000887_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000887_20_1 & 1) != 0)
  {
    if ((sec_r000887_8_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000887_0_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000887_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000887_0_1 + 7) & 127;
  }
  if ((sec_r000887_20_2 & 1) != 0)
  {
    if ((sec_r000887_8_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000887_0_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000887_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000887_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000887_4_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000887_0_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000887_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000887_0_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000887_4_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000887_0_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000887_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000887_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000887_17_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000887_15_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000887_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000887_15_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000887_17_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000887_15_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000887_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000887_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000887_6_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000887_0_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000887_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000887_0_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000887_6_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000887_0_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000887_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000887_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000887_13_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000887_6_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000887_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000887_6_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000887_13_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000887_6_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000887_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000887_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000887_3_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000887_16_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000887_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000887_16_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000887_3_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000887_16_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000887_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000887_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000887_3_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000887_18_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000887_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000887_18_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000887_3_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000887_18_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000887_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000887_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000887_20_1 & 1) != 0)
  {
    if ((sec_r000887_1_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000887_1_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000887_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000887_1_1 + 7) & 127;
  }
  if ((sec_r000887_20_2 & 1) != 0)
  {
    if ((sec_r000887_1_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000887_1_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000887_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000887_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000887_2_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000887_2_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000887_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000887_2_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000887_2_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000887_2_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000887_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000887_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000887_7_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000887_9_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000887_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000887_9_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000887_7_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000887_9_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000887_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000887_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000887_15_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000887_7_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000887_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000887_7_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000887_15_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000887_7_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000887_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000887_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000887_15_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000887_14_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000887_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000887_14_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000887_15_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000887_14_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000887_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000887_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000887_8_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000887_17_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000887_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000887_17_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000887_8_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000887_17_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000887_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000887_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000887_0_1 & 1) != 0)
  {
    if ((sec_r000887_2_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000887_18_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000887_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000887_18_1 + 7) & 127;
  }
  if ((sec_r000887_0_2 & 1) != 0)
  {
    if ((sec_r000887_2_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000887_18_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000887_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000887_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000887_1_1 & 1) != 0)
  {
    if ((sec_r000887_15_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000887_16_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000887_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000887_16_1 + 7) & 127;
  }
  if ((sec_r000887_1_2 & 1) != 0)
  {
    if ((sec_r000887_15_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000887_16_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000887_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000887_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000887_10_1 & 1) != 0)
  {
    if ((sec_r000887_8_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000887_16_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000887_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000887_16_1 + 7) & 127;
  }
  if ((sec_r000887_10_2 & 1) != 0)
  {
    if ((sec_r000887_8_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000887_16_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000887_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000887_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000887_5_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000887_14_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000887_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000887_14_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000887_5_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000887_14_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000887_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000887_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000887_19_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000887_17_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000887_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000887_17_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000887_19_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000887_17_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000887_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000887_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000887_14_1 & 1) != 0)
  {
    if ((sec_r000887_15_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000887_11_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000887_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000887_11_1 + 7) & 127;
  }
  if ((sec_r000887_14_2 & 1) != 0)
  {
    if ((sec_r000887_15_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000887_11_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000887_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000887_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000887_1_1 & 1) != 0)
  {
    if ((sec_r000887_8_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000887_19_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000887_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000887_19_1 + 7) & 127;
  }
  if ((sec_r000887_1_2 & 1) != 0)
  {
    if ((sec_r000887_8_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000887_19_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000887_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000887_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000887_3_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000887_1_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000887_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000887_1_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000887_3_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000887_1_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000887_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000887_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000887_15_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000887_4_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000887_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000887_4_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000887_15_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000887_4_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000887_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000887_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000887_15_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000887_10_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000887_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000887_10_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000887_15_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000887_10_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000887_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000887_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((sec_r000887_2_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000887_4_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000887_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000887_4_1 + 7) & 127;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((sec_r000887_2_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000887_4_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000887_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000887_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000887_15_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000887_6_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000887_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000887_6_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000887_15_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000887_6_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000887_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000887_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000887_3_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000887_5_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000887_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000887_5_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000887_3_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000887_5_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000887_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000887_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000887_2_1 & 1) != 0)
  {
    if ((sec_r000887_19_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000887_19_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000887_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000887_19_1 + 7) & 127;
  }
  if ((sec_r000887_2_2 & 1) != 0)
  {
    if ((sec_r000887_19_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000887_19_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000887_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000887_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000887_7_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000887_8_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000887_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000887_8_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000887_7_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000887_8_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000887_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000887_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000887_13_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000887_9_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000887_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000887_9_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000887_13_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000887_9_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000887_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000887_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000887_16_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000887_18_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000887_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000887_18_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000887_16_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000887_18_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000887_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000887_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000887_17_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000887_14_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000887_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000887_14_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000887_17_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000887_14_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000887_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000887_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000887_15_1 & 1) != 0)
  {
    if ((sec_r000887_20_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000887_12_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000887_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000887_12_1 + 7) & 127;
  }
  if ((sec_r000887_15_2 & 1) != 0)
  {
    if ((sec_r000887_20_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000887_12_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000887_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000887_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((sec_r000887_17_1 & 1) != 0)
  {
    if ((sec_r000887_12_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000887_10_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000887_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000887_10_1 + 7) & 127;
  }
  if ((sec_r000887_17_2 & 1) != 0)
  {
    if ((sec_r000887_12_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000887_10_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000887_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000887_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000887_1_1 & 1) != 0)
  {
    if ((sec_r000887_11_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000887_18_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000887_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000887_18_1 + 7) & 127;
  }
  if ((sec_r000887_1_2 & 1) != 0)
  {
    if ((sec_r000887_11_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000887_18_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000887_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000887_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000887_2_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000887_4_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000887_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000887_4_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000887_2_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000887_4_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000887_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000887_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000887_14_1 & 1) != 0)
  {
    if ((sec_r000887_2_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000887_11_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000887_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000887_11_1 + 7) & 127;
  }
  if ((sec_r000887_14_2 & 1) != 0)
  {
    if ((sec_r000887_2_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000887_11_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000887_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000887_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000887_14_1 & 1) != 0)
  {
    if ((sec_r000887_9_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000887_14_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000887_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000887_14_1 + 7) & 127;
  }
  if ((sec_r000887_14_2 & 1) != 0)
  {
    if ((sec_r000887_9_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000887_14_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000887_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000887_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((sec_r000887_7_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000887_2_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000887_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000887_2_1 + 7) & 127;
  }
  if ((stage_v_140_2 & 1) != 0)
  {
    if ((sec_r000887_7_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000887_2_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000887_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000887_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000887_5_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000887_9_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000887_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000887_9_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000887_5_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000887_9_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000887_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000887_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000887_4_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000887_4_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000887_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000887_4_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000887_4_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000887_4_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000887_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000887_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000887_1_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000887_15_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000887_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000887_15_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000887_1_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000887_15_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000887_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000887_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((sec_r000887_4_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000887_14_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000887_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000887_14_1 + 7) & 127;
  }
  if ((stage_v_145_2 & 1) != 0)
  {
    if ((sec_r000887_4_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000887_14_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000887_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000887_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((sec_r000887_5_1 & 1) != 0)
  {
    if ((sec_r000887_8_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000887_9_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000887_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000887_9_1 + 7) & 127;
  }
  if ((sec_r000887_5_2 & 1) != 0)
  {
    if ((sec_r000887_8_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000887_9_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000887_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000887_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000887_20_1 & 1) != 0)
  {
    if ((sec_r000887_3_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000887_14_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000887_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000887_14_1 + 7) & 127;
  }
  if ((sec_r000887_20_2 & 1) != 0)
  {
    if ((sec_r000887_3_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000887_14_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000887_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000887_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((sec_r000887_12_1 & 1) != 0)
  {
    if ((sec_r000887_7_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000887_0_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000887_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000887_0_1 + 7) & 127;
  }
  if ((sec_r000887_12_2 & 1) != 0)
  {
    if ((sec_r000887_7_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000887_0_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000887_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000887_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((sec_r000887_14_1 & 1) != 0)
  {
    if ((sec_r000887_19_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000887_7_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000887_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000887_7_1 + 7) & 127;
  }
  if ((sec_r000887_14_2 & 1) != 0)
  {
    if ((sec_r000887_19_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000887_7_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000887_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000887_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r000887_18_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000887_17_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000887_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000887_17_1 + 7) & 127;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r000887_18_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000887_17_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000887_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000887_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000887_16_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000887_10_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000887_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000887_10_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000887_16_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000887_10_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000887_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000887_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000887_12_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000887_18_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000887_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000887_18_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000887_12_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000887_18_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000887_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000887_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((sec_r000887_3_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000887_6_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000887_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000887_6_1 + 7) & 127;
  }
  if ((stage_v_138_2 & 1) != 0)
  {
    if ((sec_r000887_3_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000887_6_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000887_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000887_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((sec_r000887_12_1 & 1) != 0)
  {
    if ((sec_r000887_13_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000887_12_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000887_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000887_12_1 + 7) & 127;
  }
  if ((sec_r000887_12_2 & 1) != 0)
  {
    if ((sec_r000887_13_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000887_12_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000887_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000887_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((sec_r000887_2_1 & 1) != 0)
  {
    if ((sec_r000887_6_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000887_12_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000887_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000887_12_1 + 7) & 127;
  }
  if ((sec_r000887_2_2 & 1) != 0)
  {
    if ((sec_r000887_6_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000887_12_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000887_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000887_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((stage_v_139_1 & 1) != 0)
  {
    if ((sec_r000887_7_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000887_12_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000887_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000887_12_1 + 7) & 127;
  }
  if ((stage_v_139_2 & 1) != 0)
  {
    if ((sec_r000887_7_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000887_12_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000887_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000887_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000887_3_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000887_18_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000887_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000887_18_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000887_3_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000887_18_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000887_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000887_18_2 + 7) & 127;
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
  __CPROVER_assume(pub_r000887_18_1 == pub_r000887_18_2);
  __CPROVER_assume(sec_r000887_10_1 != sec_r000887_10_2);
  __CPROVER_assume(pub_r000887_8_1 == pub_r000887_8_2);
  __CPROVER_assume(sec_r000887_14_1 != sec_r000887_14_2);
  __CPROVER_assume(pub_r000887_2_1 == pub_r000887_2_2);
  __CPROVER_assume(sec_r000887_17_1 != sec_r000887_17_2);
  __CPROVER_assume(sec_r000887_7_1 != sec_r000887_7_2);
  __CPROVER_assume(sec_r000887_19_1 != sec_r000887_19_2);
  __CPROVER_assume(sec_r000887_6_1 != sec_r000887_6_2);
  __CPROVER_assume(pub_r000887_5_1 == pub_r000887_5_2);
  __CPROVER_assume(sec_r000887_3_1 != sec_r000887_3_2);
  __CPROVER_assume(pub_r000887_9_1 == pub_r000887_9_2);
  __CPROVER_assume(sec_r000887_11_1 != sec_r000887_11_2);
  __CPROVER_assume(sec_r000887_20_1 != sec_r000887_20_2);
  __CPROVER_assume(sec_r000887_8_1 != sec_r000887_8_2);
  __CPROVER_assume(sec_r000887_12_1 != sec_r000887_12_2);
  __CPROVER_assume(pub_r000887_14_1 == pub_r000887_14_2);
  __CPROVER_assume(pub_r000887_10_1 == pub_r000887_10_2);
  __CPROVER_assume(pub_r000887_16_1 == pub_r000887_16_2);
  __CPROVER_assume(sec_r000887_1_1 != sec_r000887_1_2);
  __CPROVER_assume(pub_r000887_1_1 == pub_r000887_1_2);
  __CPROVER_assume(pub_r000887_17_1 == pub_r000887_17_2);
  __CPROVER_assume(sec_r000887_5_1 != sec_r000887_5_2);
  __CPROVER_assume(pub_r000887_0_1 == pub_r000887_0_2);
  __CPROVER_assume(pub_r000887_12_1 == pub_r000887_12_2);
  __CPROVER_assume(pub_r000887_15_1 == pub_r000887_15_2);
  __CPROVER_assume(pub_r000887_3_1 == pub_r000887_3_2);
  __CPROVER_assume(pub_r000887_7_1 == pub_r000887_7_2);
  __CPROVER_assume(sec_r000887_0_1 != sec_r000887_0_2);
  __CPROVER_assume(pub_r000887_11_1 == pub_r000887_11_2);
  __CPROVER_assume(sec_r000887_13_1 != sec_r000887_13_2);
  __CPROVER_assume(sec_r000887_2_1 != sec_r000887_2_2);
  __CPROVER_assume(sec_r000887_15_1 != sec_r000887_15_2);
  __CPROVER_assume(sec_r000887_18_1 != sec_r000887_18_2);
  __CPROVER_assume(pub_r000887_13_1 == pub_r000887_13_2);
  __CPROVER_assume(pub_r000887_6_1 == pub_r000887_6_2);
  __CPROVER_assume(pub_r000887_19_1 == pub_r000887_19_2);
  __CPROVER_assume(pub_r000887_4_1 == pub_r000887_4_2);
  __CPROVER_assume(sec_r000887_16_1 != sec_r000887_16_2);
  __CPROVER_assume(sec_r000887_4_1 != sec_r000887_4_2);
  __CPROVER_assume(sec_r000887_9_1 != sec_r000887_9_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.code == st_var_0_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.balance == st_var_2_2.balance);
  assert(st_var_2_1.account_id == st_var_2_2.account_id);
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
}


