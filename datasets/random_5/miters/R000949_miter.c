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
struct Transaction_R000949_4913_0
{
  short account_id;
  int fee;
  short status;
  int buffer[3];
};
struct EventLog_R000949_4913_1
{
  unsigned char facility;
  int severity;
  int code;
  int seq;
  int signature;
  int timestamp;
  int buffer[3];
};
struct DeviceConfig_R000949_4913_2
{
  unsigned char baud_rate;
  short parity;
  short timeout;
  unsigned char port;
  int buffer[3];
};
union TelemetryField_R000949_4913_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000949_4913_1
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
void fn_R000949_4913_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000949_4913_1 st_1 = {0};
  struct EventLog_R000949_4913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int bound_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_16_1) & 63;
  aux_2 = (aux_2 + bound_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_44_1 = local_arr_1[aux_1 % 3];
  int offset_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_16_1 == bound_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_44_1 == offset_44_2);
}

int fn_R000949_4913_0(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000949_4913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int bound_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_16) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_44 = local_arr[aux % 3];
  acc = (acc + (offset_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000949_4913_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st_1 = {0};
  struct DeviceConfig_R000949_4913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int pivot_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_96_1) & 63;
  aux_2 = (aux_2 + pivot_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_72_1)
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

  switch (scale_72_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_96_1 == pivot_96_2);
  assert(scale_72_1 == scale_72_2);
}

int fn_R000949_4913_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int pivot_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_96) & 63;
  acc ^= aux;
  int scale_72 = (aux + st.buffer[1]) & 3;
  switch (scale_72)
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

void fn_R000949_4913_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st_1 = {0};
  struct DeviceConfig_R000949_4913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_75_1 = local_arr_1[aux_1 % 3];
  int metric_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_75_2 * 2)) & 127;
  int weight_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_75_1 > 46)
  {
    acc_1 = ((acc_1 + (weight_75_1 * 2)) + 5) & 127;
    aux_1 ^= weight_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_75_2 > 46)
  {
    acc_2 = ((acc_2 + (weight_75_2 * 2)) + 5) & 127;
    aux_2 ^= weight_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_75_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_75_1 == metric_75_2);
  assert(weight_75_1 == weight_75_2);
}

int fn_R000949_4913_2(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int metric_75 = local_arr[aux % 3];
  acc = (acc + (metric_75 * 2)) & 127;
  int weight_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_75 > 46)
  {
    acc = ((acc + (weight_75 * 2)) + 5) & 127;
    aux ^= weight_75 & 15;
  }
  else
  {
    acc = ((acc - weight_75) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000949_4913_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st_1 = {0};
  struct DeviceConfig_R000949_4913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_87_1 = local_arr_1[aux_1 % 3];
  int residue_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_87_2 * 2)) & 127;
  int index_reg_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_56_1 > 49)
  {
    acc_1 = ((acc_1 + (index_reg_56_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_56_2 > 49)
  {
    acc_2 = ((acc_2 + (index_reg_56_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_87_1 == residue_87_2);
  assert(index_reg_56_1 == index_reg_56_2);
}

int fn_R000949_4913_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int residue_87 = local_arr[aux % 3];
  acc = (acc + (residue_87 * 2)) & 127;
  int index_reg_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_56 > 49)
  {
    acc = ((acc + (index_reg_56 * 2)) + 5) & 127;
    aux ^= index_reg_56 & 15;
  }
  else
  {
    acc = ((acc - index_reg_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000949_4913_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000949_4913_1 st_1 = {0};
  struct EventLog_R000949_4913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int tally_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_62_1 > 43)
  {
    acc_1 = ((acc_1 + (tally_62_1 * 2)) + 5) & 127;
    aux_1 ^= tally_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_62_2 > 43)
  {
    acc_2 = ((acc_2 + (tally_62_2 * 2)) + 5) & 127;
    aux_2 ^= tally_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_28_1)
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

  switch (window_28_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_62_1 == tally_62_2);
  assert(window_28_1 == window_28_2);
}

int fn_R000949_4913_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000949_4913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int tally_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_62 > 43)
  {
    acc = ((acc + (tally_62 * 2)) + 5) & 127;
    aux ^= tally_62 & 15;
  }
  else
  {
    acc = ((acc - tally_62) + 11) & 127;
    aux += 3;
  }
  int window_28 = (aux + st.buffer[1]) & 3;
  switch (window_28)
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

void fn_R000949_4913_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000949_4913_1 st_1 = {0};
  struct EventLog_R000949_4913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int phase_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_58_1)
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

  switch (phase_58_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_23_1) & 63;
  aux_2 = (aux_2 + offset_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_66_1 = local_arr_1[aux_1 % 3];
  int residue_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_58_1 == phase_58_2);
  assert(offset_23_1 == offset_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_66_1 == residue_66_2);
}

int fn_R000949_4913_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000949_4913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int phase_58 = (aux + st.buffer[1]) & 3;
  switch (phase_58)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_23) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_66 = local_arr[aux % 3];
  acc = (acc + (residue_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000949_4913_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st_1 = {0};
  struct DeviceConfig_R000949_4913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int tally_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_36_1 > 44)
  {
    acc_1 = ((acc_1 + (tally_36_1 * 2)) + 5) & 127;
    aux_1 ^= tally_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_36_2 > 44)
  {
    acc_2 = ((acc_2 + (tally_36_2 * 2)) + 5) & 127;
    aux_2 ^= tally_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_36_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_84_1)
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

  switch (coefficient_84_2)
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

  int mask_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_83_1) & 63;
  aux_2 = (aux_2 + mask_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_36_1 == tally_36_2);
  assert(coefficient_84_1 == coefficient_84_2);
  assert(mask_83_1 == mask_83_2);
}

int fn_R000949_4913_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int tally_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_36 > 44)
  {
    acc = ((acc + (tally_36 * 2)) + 5) & 127;
    aux ^= tally_36 & 15;
  }
  else
  {
    acc = ((acc - tally_36) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_84 = (aux + st.buffer[1]) & 3;
  switch (coefficient_84)
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

  int mask_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_83) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000949_4913_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st_1 = {0};
  struct DeviceConfig_R000949_4913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_15_1 = local_arr_1[aux_1 % 3];
  int scale_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_15_2 * 2)) & 127;
  int bound_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_31_1 > 20)
  {
    acc_1 = ((acc_1 + (bound_31_1 * 2)) + 5) & 127;
    aux_1 ^= bound_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_31_2 > 20)
  {
    acc_2 = ((acc_2 + (bound_31_2 * 2)) + 5) & 127;
    aux_2 ^= bound_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_31_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_15_1 == scale_15_2);
  assert(bound_31_1 == bound_31_2);
}

int fn_R000949_4913_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int scale_15 = local_arr[aux % 3];
  acc = (acc + (scale_15 * 2)) & 127;
  int bound_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_31 > 20)
  {
    acc = ((acc + (bound_31 * 2)) + 5) & 127;
    aux ^= bound_31 & 15;
  }
  else
  {
    acc = ((acc - bound_31) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000949_4913_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000949_4913_1 st_1 = {0};
  struct EventLog_R000949_4913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_96_1 = local_arr_1[aux_1 % 3];
  int scale_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_96_2 * 2)) & 127;
  int offset_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_63_1) & 63;
  aux_2 = (aux_2 + offset_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_99_1)
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

  switch (index_reg_99_2)
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

  int mask_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_53_1 > 23)
  {
    acc_1 = ((acc_1 + (mask_53_1 * 2)) + 5) & 127;
    aux_1 ^= mask_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_53_2 > 23)
  {
    acc_2 = ((acc_2 + (mask_53_2 * 2)) + 5) & 127;
    aux_2 ^= mask_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_96_1 == scale_96_2);
  assert(offset_63_1 == offset_63_2);
  assert(index_reg_99_1 == index_reg_99_2);
  assert(mask_53_1 == mask_53_2);
}

int fn_R000949_4913_8(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000949_4913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int scale_96 = local_arr[aux % 3];
  acc = (acc + (scale_96 * 2)) & 127;
  int offset_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_63) & 63;
  acc ^= aux;
  int index_reg_99 = (aux + st.buffer[1]) & 3;
  switch (index_reg_99)
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

  int mask_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_53 > 23)
  {
    acc = ((acc + (mask_53 * 2)) + 5) & 127;
    aux ^= mask_53 & 15;
  }
  else
  {
    acc = ((acc - mask_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000949_4913_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000949_4913_1 st_1 = {0};
  struct EventLog_R000949_4913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_78_1 = local_arr_1[aux_1 % 3];
  int stride_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_78_2 * 2)) & 127;
  int cursor_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_94_1 > 29)
  {
    acc_1 = ((acc_1 + (cursor_94_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_94_2 > 29)
  {
    acc_2 = ((acc_2 + (cursor_94_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_72_1)
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

  switch (weight_72_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_78_1 == stride_78_2);
  assert(cursor_94_1 == cursor_94_2);
  assert(weight_72_1 == weight_72_2);
}

int fn_R000949_4913_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000949_4913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int stride_78 = local_arr[aux % 3];
  acc = (acc + (stride_78 * 2)) & 127;
  int cursor_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_94 > 29)
  {
    acc = ((acc + (cursor_94 * 2)) + 5) & 127;
    aux ^= cursor_94 & 15;
  }
  else
  {
    acc = ((acc - cursor_94) + 11) & 127;
    aux += 3;
  }
  int weight_72 = (aux + st.buffer[1]) & 3;
  switch (weight_72)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000949_4913_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st_1 = {0};
  struct DeviceConfig_R000949_4913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_85_1 > 17)
  {
    acc_1 = ((acc_1 + (tracker_85_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_85_2 > 17)
  {
    acc_2 = ((acc_2 + (tracker_85_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_85_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_85_1 == tracker_85_2);
}

int fn_R000949_4913_10(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_85 > 17)
  {
    acc = ((acc + (tracker_85 * 2)) + 5) & 127;
    aux ^= tracker_85 & 15;
  }
  else
  {
    acc = ((acc - tracker_85) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000949_4913_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000949_4913_1 st_1 = {0};
  struct EventLog_R000949_4913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_94_1 = local_arr_1[aux_1 % 3];
  int metric_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_94_2 * 2)) & 127;
  int offset_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_80_1) & 63;
  aux_2 = (aux_2 + offset_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_94_1 == metric_94_2);
  assert(offset_80_1 == offset_80_2);
}

int fn_R000949_4913_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000949_4913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int metric_94 = local_arr[aux % 3];
  acc = (acc + (metric_94 * 2)) & 127;
  int offset_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000949_4913_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000949_4913_0 st_1 = {0};
  struct Transaction_R000949_4913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_44_1 > 17)
  {
    acc_1 = ((acc_1 + (damping_44_1 * 2)) + 5) & 127;
    aux_1 ^= damping_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_44_2 > 17)
  {
    acc_2 = ((acc_2 + (damping_44_2 * 2)) + 5) & 127;
    aux_2 ^= damping_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_85_1 = local_arr_1[aux_1 % 3];
  int cursor_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_85_2 * 2)) & 127;
  int tracker_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_73_1) & 63;
  aux_2 = (aux_2 + tracker_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_44_1 == damping_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_85_1 == cursor_85_2);
  assert(tracker_73_1 == tracker_73_2);
}

int fn_R000949_4913_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000949_4913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_44 > 17)
  {
    acc = ((acc + (damping_44 * 2)) + 5) & 127;
    aux ^= damping_44 & 15;
  }
  else
  {
    acc = ((acc - damping_44) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_85 = local_arr[aux % 3];
  acc = (acc + (cursor_85 * 2)) & 127;
  int tracker_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_73) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000949_4913_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000949_4913_0 st_1 = {0};
  struct Transaction_R000949_4913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_47_1 = local_arr_1[aux_1 % 3];
  int mask_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_47_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
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

  assert(mask_47_1 == mask_47_2);
}

int fn_R000949_4913_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000949_4913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_47 = local_arr[aux % 3];
  acc = (acc + (mask_47 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000949_4913_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st_1 = {0};
  struct DeviceConfig_R000949_4913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int tally_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_13_1) & 63;
  aux_2 = (aux_2 + tally_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_15_1 = local_arr_1[aux_1 % 3];
  int factor_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_15_2 * 2)) & 127;
  int quotient_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_53_1 > 31)
  {
    acc_1 = ((acc_1 + (quotient_53_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_53_2 > 31)
  {
    acc_2 = ((acc_2 + (quotient_53_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_53_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_74_1)
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

  switch (residue_74_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_13_1 == tally_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_15_1 == factor_15_2);
  assert(quotient_53_1 == quotient_53_2);
  assert(residue_74_1 == residue_74_2);
}

int fn_R000949_4913_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int tally_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_13) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_15 = local_arr[aux % 3];
  acc = (acc + (factor_15 * 2)) & 127;
  int quotient_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_53 > 31)
  {
    acc = ((acc + (quotient_53 * 2)) + 5) & 127;
    aux ^= quotient_53 & 15;
  }
  else
  {
    acc = ((acc - quotient_53) + 11) & 127;
    aux += 3;
  }
  int residue_74 = (aux + st.buffer[1]) & 3;
  switch (residue_74)
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

void fn_R000949_4913_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st_1 = {0};
  struct DeviceConfig_R000949_4913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int mask_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_70_1)
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

  switch (mask_70_2)
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

  int cursor_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_23_1) & 63;
  aux_2 = (aux_2 + cursor_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_70_1 == mask_70_2);
  assert(cursor_23_1 == cursor_23_2);
  assert(weight_42_1 == weight_42_2);
}

int fn_R000949_4913_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int mask_70 = (aux + st.buffer[1]) & 3;
  switch (mask_70)
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

  int cursor_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_23) & 63;
  acc ^= aux;
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

void fn_R000949_4913_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000949_4913_0 st_1 = {0};
  struct Transaction_R000949_4913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int parity_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_40_1 > 36)
  {
    acc_1 = ((acc_1 + (parity_40_1 * 2)) + 5) & 127;
    aux_1 ^= parity_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_40_2 > 36)
  {
    acc_2 = ((acc_2 + (parity_40_2 * 2)) + 5) & 127;
    aux_2 ^= parity_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_69_1 = local_arr_1[aux_1 % 3];
  int scale_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_69_2 * 2)) & 127;
  int damping_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_56_1)
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

  switch (damping_56_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_40_1 == parity_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_69_1 == scale_69_2);
  assert(damping_56_1 == damping_56_2);
}

int fn_R000949_4913_16(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000949_4913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int parity_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_40 > 36)
  {
    acc = ((acc + (parity_40 * 2)) + 5) & 127;
    aux ^= parity_40 & 15;
  }
  else
  {
    acc = ((acc - parity_40) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int scale_69 = local_arr[aux % 3];
  acc = (acc + (scale_69 * 2)) & 127;
  int damping_56 = (aux + st.buffer[1]) & 3;
  switch (damping_56)
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

void fn_R000949_4913_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st_1 = {0};
  struct DeviceConfig_R000949_4913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_41_1 = local_arr_1[aux_1 % 3];
  int mask_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_41_2 * 2)) & 127;
  int tracker_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_44_1)
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

  switch (tracker_44_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_41_1 == mask_41_2);
  assert(tracker_44_1 == tracker_44_2);
}

int fn_R000949_4913_17(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000949_4913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int mask_41 = local_arr[aux % 3];
  acc = (acc + (mask_41 * 2)) & 127;
  int tracker_44 = (aux + st.buffer[1]) & 3;
  switch (tracker_44)
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

void fn_R000949_4913_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000949_4913_0 st_1 = {0};
  struct Transaction_R000949_4913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int anchor_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_75_1)
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

  switch (anchor_75_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_14_1 = local_arr_1[aux_1 % 3];
  int delta_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_14_2 * 2)) & 127;
  int quantum_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_38_1 > 26)
  {
    acc_1 = ((acc_1 + (quantum_38_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_38_2 > 26)
  {
    acc_2 = ((acc_2 + (quantum_38_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_75_1 == anchor_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_14_1 == delta_14_2);
  assert(quantum_38_1 == quantum_38_2);
}

int fn_R000949_4913_18(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000949_4913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int anchor_75 = (aux + st.buffer[1]) & 3;
  switch (anchor_75)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_14 = local_arr[aux % 3];
  acc = (acc + (delta_14 * 2)) & 127;
  int quantum_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_38 > 26)
  {
    acc = ((acc + (quantum_38 * 2)) + 5) & 127;
    aux ^= quantum_38 & 15;
  }
  else
  {
    acc = ((acc - quantum_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000949_4913_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000949_4913_0 st_1 = {0};
  struct Transaction_R000949_4913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int metric_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_73_1)
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

  switch (metric_73_2)
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

  int coefficient_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_97_1 > 11)
  {
    acc_1 = ((acc_1 + (coefficient_97_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_97_2 > 11)
  {
    acc_2 = ((acc_2 + (coefficient_97_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_73_1 == metric_73_2);
  assert(coefficient_97_1 == coefficient_97_2);
}

int fn_R000949_4913_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000949_4913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int metric_73 = (aux + st.buffer[1]) & 3;
  switch (metric_73)
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

  int coefficient_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_97 > 11)
  {
    acc = ((acc + (coefficient_97 * 2)) + 5) & 127;
    aux ^= coefficient_97 & 15;
  }
  else
  {
    acc = ((acc - coefficient_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000949_4913_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000949_4913_1 st_1 = {0};
  struct EventLog_R000949_4913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int tally_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_35_1 > 10)
  {
    acc_1 = ((acc_1 + (tally_35_1 * 2)) + 5) & 127;
    aux_1 ^= tally_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_35_2 > 10)
  {
    acc_2 = ((acc_2 + (tally_35_2 * 2)) + 5) & 127;
    aux_2 ^= tally_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_28_1 = local_arr_1[aux_1 % 3];
  int tally_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_28_2 * 2)) & 127;
  int threshold_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_38_1)
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

  switch (threshold_38_2)
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

  int metric_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_73_1) & 63;
  aux_2 = (aux_2 + metric_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_35_1 == tally_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_28_1 == tally_28_2);
  assert(threshold_38_1 == threshold_38_2);
  assert(metric_73_1 == metric_73_2);
}

int fn_R000949_4913_20(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000949_4913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int tally_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_35 > 10)
  {
    acc = ((acc + (tally_35 * 2)) + 5) & 127;
    aux ^= tally_35 & 15;
  }
  else
  {
    acc = ((acc - tally_35) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_28 = local_arr[aux % 3];
  acc = (acc + (tally_28 * 2)) & 127;
  int threshold_38 = (aux + st.buffer[1]) & 3;
  switch (threshold_38)
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

  int metric_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_73) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000949_0_1;
  int sec_r000949_0_2;
  int sec_r000949_1_1;
  int sec_r000949_1_2;
  int sec_r000949_2_1;
  int sec_r000949_2_2;
  int sec_r000949_3_1;
  int sec_r000949_3_2;
  int sec_r000949_4_1;
  int sec_r000949_4_2;
  int sec_r000949_5_1;
  int sec_r000949_5_2;
  int sec_r000949_6_1;
  int sec_r000949_6_2;
  int sec_r000949_7_1;
  int sec_r000949_7_2;
  int sec_r000949_8_1;
  int sec_r000949_8_2;
  int sec_r000949_9_1;
  int sec_r000949_9_2;
  int sec_r000949_10_1;
  int sec_r000949_10_2;
  int sec_r000949_11_1;
  int sec_r000949_11_2;
  int sec_r000949_12_1;
  int sec_r000949_12_2;
  int sec_r000949_13_1;
  int sec_r000949_13_2;
  int sec_r000949_14_1;
  int sec_r000949_14_2;
  int sec_r000949_15_1;
  int sec_r000949_15_2;
  int pub_r000949_0_1;
  int pub_r000949_0_2;
  int pub_r000949_1_1;
  int pub_r000949_1_2;
  int pub_r000949_2_1;
  int pub_r000949_2_2;
  int pub_r000949_3_1;
  int pub_r000949_3_2;
  int pub_r000949_4_1;
  int pub_r000949_4_2;
  int pub_r000949_5_1;
  int pub_r000949_5_2;
  int pub_r000949_6_1;
  int pub_r000949_6_2;
  int pub_r000949_7_1;
  int pub_r000949_7_2;
  int pub_r000949_8_1;
  int pub_r000949_8_2;
  int pub_r000949_9_1;
  int pub_r000949_9_2;
  int pub_r000949_10_1;
  int pub_r000949_10_2;
  int pub_r000949_11_1;
  int pub_r000949_11_2;
  int pub_r000949_12_1;
  int pub_r000949_12_2;
  int pub_r000949_13_1;
  int pub_r000949_13_2;
  int pub_r000949_14_1;
  int pub_r000949_14_2;
  int pub_r000949_15_1;
  int pub_r000949_15_2;
  int pub_r000949_16_1;
  int pub_r000949_16_2;
  int pub_r000949_17_1;
  int pub_r000949_17_2;
  int pub_r000949_18_1;
  int pub_r000949_18_2;
  int pub_r000949_19_1;
  int pub_r000949_19_2;
  int pub_r000949_20_1;
  int pub_r000949_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000949_0_1 >= (-100)) && (pub_r000949_0_1 <= 100));
  __CPROVER_assume((pub_r000949_0_2 >= (-100)) && (pub_r000949_0_2 <= 100));
  __CPROVER_assume((pub_r000949_1_1 >= (-100)) && (pub_r000949_1_1 <= 100));
  __CPROVER_assume((pub_r000949_1_2 >= (-100)) && (pub_r000949_1_2 <= 100));
  __CPROVER_assume((pub_r000949_2_1 >= (-100)) && (pub_r000949_2_1 <= 100));
  __CPROVER_assume((pub_r000949_2_2 >= (-100)) && (pub_r000949_2_2 <= 100));
  __CPROVER_assume((pub_r000949_3_1 >= (-100)) && (pub_r000949_3_1 <= 100));
  __CPROVER_assume((pub_r000949_3_2 >= (-100)) && (pub_r000949_3_2 <= 100));
  __CPROVER_assume((pub_r000949_4_1 >= (-100)) && (pub_r000949_4_1 <= 100));
  __CPROVER_assume((pub_r000949_4_2 >= (-100)) && (pub_r000949_4_2 <= 100));
  __CPROVER_assume((pub_r000949_5_1 >= (-100)) && (pub_r000949_5_1 <= 100));
  __CPROVER_assume((pub_r000949_5_2 >= (-100)) && (pub_r000949_5_2 <= 100));
  __CPROVER_assume((pub_r000949_6_1 >= (-100)) && (pub_r000949_6_1 <= 100));
  __CPROVER_assume((pub_r000949_6_2 >= (-100)) && (pub_r000949_6_2 <= 100));
  __CPROVER_assume((pub_r000949_7_1 >= (-100)) && (pub_r000949_7_1 <= 100));
  __CPROVER_assume((pub_r000949_7_2 >= (-100)) && (pub_r000949_7_2 <= 100));
  __CPROVER_assume((pub_r000949_8_1 >= (-100)) && (pub_r000949_8_1 <= 100));
  __CPROVER_assume((pub_r000949_8_2 >= (-100)) && (pub_r000949_8_2 <= 100));
  __CPROVER_assume((pub_r000949_9_1 >= (-100)) && (pub_r000949_9_1 <= 100));
  __CPROVER_assume((pub_r000949_9_2 >= (-100)) && (pub_r000949_9_2 <= 100));
  __CPROVER_assume((pub_r000949_10_1 >= (-100)) && (pub_r000949_10_1 <= 100));
  __CPROVER_assume((pub_r000949_10_2 >= (-100)) && (pub_r000949_10_2 <= 100));
  __CPROVER_assume((pub_r000949_11_1 >= (-100)) && (pub_r000949_11_1 <= 100));
  __CPROVER_assume((pub_r000949_11_2 >= (-100)) && (pub_r000949_11_2 <= 100));
  __CPROVER_assume((pub_r000949_12_1 >= (-100)) && (pub_r000949_12_1 <= 100));
  __CPROVER_assume((pub_r000949_12_2 >= (-100)) && (pub_r000949_12_2 <= 100));
  __CPROVER_assume((pub_r000949_13_1 >= (-100)) && (pub_r000949_13_1 <= 100));
  __CPROVER_assume((pub_r000949_13_2 >= (-100)) && (pub_r000949_13_2 <= 100));
  __CPROVER_assume((pub_r000949_14_1 >= (-100)) && (pub_r000949_14_1 <= 100));
  __CPROVER_assume((pub_r000949_14_2 >= (-100)) && (pub_r000949_14_2 <= 100));
  __CPROVER_assume((pub_r000949_15_1 >= (-100)) && (pub_r000949_15_1 <= 100));
  __CPROVER_assume((pub_r000949_15_2 >= (-100)) && (pub_r000949_15_2 <= 100));
  __CPROVER_assume((pub_r000949_16_1 >= (-100)) && (pub_r000949_16_1 <= 100));
  __CPROVER_assume((pub_r000949_16_2 >= (-100)) && (pub_r000949_16_2 <= 100));
  __CPROVER_assume((pub_r000949_17_1 >= (-100)) && (pub_r000949_17_1 <= 100));
  __CPROVER_assume((pub_r000949_17_2 >= (-100)) && (pub_r000949_17_2 <= 100));
  __CPROVER_assume((pub_r000949_18_1 >= (-100)) && (pub_r000949_18_1 <= 100));
  __CPROVER_assume((pub_r000949_18_2 >= (-100)) && (pub_r000949_18_2 <= 100));
  __CPROVER_assume((pub_r000949_19_1 >= (-100)) && (pub_r000949_19_1 <= 100));
  __CPROVER_assume((pub_r000949_19_2 >= (-100)) && (pub_r000949_19_2 <= 100));
  __CPROVER_assume((pub_r000949_20_1 >= (-100)) && (pub_r000949_20_1 <= 100));
  __CPROVER_assume((pub_r000949_20_2 >= (-100)) && (pub_r000949_20_2 <= 100));
  __CPROVER_assume((sec_r000949_0_1 >= 0) && (sec_r000949_0_1 <= 255));
  __CPROVER_assume((sec_r000949_0_2 >= 0) && (sec_r000949_0_2 <= 255));
  __CPROVER_assume((sec_r000949_1_1 >= 0) && (sec_r000949_1_1 <= 255));
  __CPROVER_assume((sec_r000949_1_2 >= 0) && (sec_r000949_1_2 <= 255));
  __CPROVER_assume((sec_r000949_2_1 >= 0) && (sec_r000949_2_1 <= 255));
  __CPROVER_assume((sec_r000949_2_2 >= 0) && (sec_r000949_2_2 <= 255));
  __CPROVER_assume((sec_r000949_3_1 >= 0) && (sec_r000949_3_1 <= 255));
  __CPROVER_assume((sec_r000949_3_2 >= 0) && (sec_r000949_3_2 <= 255));
  __CPROVER_assume((sec_r000949_4_1 >= 0) && (sec_r000949_4_1 <= 255));
  __CPROVER_assume((sec_r000949_4_2 >= 0) && (sec_r000949_4_2 <= 255));
  __CPROVER_assume((sec_r000949_5_1 >= 0) && (sec_r000949_5_1 <= 255));
  __CPROVER_assume((sec_r000949_5_2 >= 0) && (sec_r000949_5_2 <= 255));
  __CPROVER_assume((sec_r000949_6_1 >= 0) && (sec_r000949_6_1 <= 255));
  __CPROVER_assume((sec_r000949_6_2 >= 0) && (sec_r000949_6_2 <= 255));
  __CPROVER_assume((sec_r000949_7_1 >= 0) && (sec_r000949_7_1 <= 255));
  __CPROVER_assume((sec_r000949_7_2 >= 0) && (sec_r000949_7_2 <= 255));
  __CPROVER_assume((sec_r000949_8_1 >= 0) && (sec_r000949_8_1 <= 255));
  __CPROVER_assume((sec_r000949_8_2 >= 0) && (sec_r000949_8_2 <= 255));
  __CPROVER_assume((sec_r000949_9_1 >= 0) && (sec_r000949_9_1 <= 255));
  __CPROVER_assume((sec_r000949_9_2 >= 0) && (sec_r000949_9_2 <= 255));
  __CPROVER_assume((sec_r000949_10_1 >= 0) && (sec_r000949_10_1 <= 255));
  __CPROVER_assume((sec_r000949_10_2 >= 0) && (sec_r000949_10_2 <= 255));
  __CPROVER_assume((sec_r000949_11_1 >= 0) && (sec_r000949_11_1 <= 255));
  __CPROVER_assume((sec_r000949_11_2 >= 0) && (sec_r000949_11_2 <= 255));
  __CPROVER_assume((sec_r000949_12_1 >= 0) && (sec_r000949_12_1 <= 255));
  __CPROVER_assume((sec_r000949_12_2 >= 0) && (sec_r000949_12_2 <= 255));
  __CPROVER_assume((sec_r000949_13_1 >= 0) && (sec_r000949_13_1 <= 255));
  __CPROVER_assume((sec_r000949_13_2 >= 0) && (sec_r000949_13_2 <= 255));
  __CPROVER_assume((sec_r000949_14_1 >= 0) && (sec_r000949_14_1 <= 255));
  __CPROVER_assume((sec_r000949_14_2 >= 0) && (sec_r000949_14_2 <= 255));
  __CPROVER_assume((sec_r000949_15_1 >= 0) && (sec_r000949_15_1 <= 255));
  __CPROVER_assume((sec_r000949_15_2 >= 0) && (sec_r000949_15_2 <= 255));
  struct Transaction_R000949_4913_0 st_var_0_1 = {0};
  struct Transaction_R000949_4913_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000949_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000949_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000949_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000949_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000949_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000949_0_2 + 7) & 15;
  struct EventLog_R000949_4913_1 st_var_1_1 = {0};
  struct EventLog_R000949_4913_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000949_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000949_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000949_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000949_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000949_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000949_0_2 + 9) & 15;
  struct DeviceConfig_R000949_4913_2 st_var_2_1 = {0};
  struct DeviceConfig_R000949_4913_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000949_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000949_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000949_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000949_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000949_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000949_0_2 + 11) & 15;
  union TelemetryField_R000949_4913_0 u_var_1;
  union TelemetryField_R000949_4913_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 33)
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
  if (stage_v_0_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 33)
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
  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 3) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 4) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = ((st_var_0_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_0_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 28)
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
  if (stage_v_9_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 28)
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
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 42)
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
  if (stage_v_13_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 42)
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
  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (st_var_0_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_0_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  int stage_v_17_1 = (st_var_2_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_2_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = ((st_var_0_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_0_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 25)
    {
      chk_sum_1 ^= stage_v_18_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_18_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 25)
    {
      chk_sum_2 ^= stage_v_18_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int s_idx_19_1 = sec_r000949_13_1 & 3;
  int s_idx_19_2 = sec_r000949_13_2 & 3;
  int stage_v_19_1 = (table_1[s_idx_19_1] + pub_r000949_5_1) & 127;
  int stage_v_19_2 = (table_2[s_idx_19_2] + pub_r000949_5_2) & 127;
  table_1[s_idx_19_1] = (stage_v_19_1 + 7) & 63;
  table_2[s_idx_19_2] = (stage_v_19_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int s_idx_20_1 = sec_r000949_6_1 & 3;
  int s_idx_20_2 = sec_r000949_6_2 & 3;
  int stage_v_20_1 = (table_1[s_idx_20_1] + pub_r000949_5_1) & 127;
  int stage_v_20_2 = (table_2[s_idx_20_2] + pub_r000949_5_2) & 127;
  table_1[s_idx_20_1] = (stage_v_20_1 + 7) & 63;
  table_2[s_idx_20_2] = (stage_v_20_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int s_idx_21_1 = stage_v_20_1 & 3;
  int s_idx_21_2 = stage_v_20_2 & 3;
  int stage_v_21_1 = (table_1[s_idx_21_1] + pub_r000949_16_1) & 127;
  int stage_v_21_2 = (table_2[s_idx_21_2] + pub_r000949_16_2) & 127;
  table_1[s_idx_21_1] = (stage_v_21_1 + 7) & 63;
  table_2[s_idx_21_2] = (stage_v_21_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int s_idx_22_1 = stage_v_19_1 & 3;
  int s_idx_22_2 = stage_v_19_2 & 3;
  int stage_v_22_1 = (table_1[s_idx_22_1] + pub_r000949_8_1) & 127;
  int stage_v_22_2 = (table_2[s_idx_22_2] + pub_r000949_8_2) & 127;
  table_1[s_idx_22_1] = (stage_v_22_1 + 7) & 63;
  table_2[s_idx_22_2] = (stage_v_22_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int s_idx_23_1 = stage_v_21_1 & 3;
  int s_idx_23_2 = stage_v_21_2 & 3;
  int stage_v_23_1 = (table_1[s_idx_23_1] + pub_r000949_14_1) & 127;
  int stage_v_23_2 = (table_2[s_idx_23_2] + pub_r000949_14_2) & 127;
  table_1[s_idx_23_1] = (stage_v_23_1 + 7) & 63;
  table_2[s_idx_23_2] = (stage_v_23_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int s_idx_24_1 = sec_r000949_9_1 & 3;
  int s_idx_24_2 = sec_r000949_9_2 & 3;
  int stage_v_24_1 = (table_1[s_idx_24_1] + pub_r000949_11_1) & 127;
  int stage_v_24_2 = (table_2[s_idx_24_2] + pub_r000949_11_2) & 127;
  table_1[s_idx_24_1] = (stage_v_24_1 + 7) & 63;
  table_2[s_idx_24_2] = (stage_v_24_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int s_idx_25_1 = sec_r000949_8_1 & 3;
  int s_idx_25_2 = sec_r000949_8_2 & 3;
  int stage_v_25_1 = (table_1[s_idx_25_1] + pub_r000949_7_1) & 127;
  int stage_v_25_2 = (table_2[s_idx_25_2] + pub_r000949_7_2) & 127;
  table_1[s_idx_25_1] = (stage_v_25_1 + 7) & 63;
  table_2[s_idx_25_2] = (stage_v_25_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int s_idx_26_1 = stage_v_24_1 & 3;
  int s_idx_26_2 = stage_v_24_2 & 3;
  int stage_v_26_1 = (table_1[s_idx_26_1] + pub_r000949_17_1) & 127;
  int stage_v_26_2 = (table_2[s_idx_26_2] + pub_r000949_17_2) & 127;
  table_1[s_idx_26_1] = (stage_v_26_1 + 7) & 63;
  table_2[s_idx_26_2] = (stage_v_26_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int s_idx_27_1 = stage_v_24_1 & 3;
  int s_idx_27_2 = stage_v_24_2 & 3;
  int stage_v_27_1 = (table_1[s_idx_27_1] + pub_r000949_14_1) & 127;
  int stage_v_27_2 = (table_2[s_idx_27_2] + pub_r000949_14_2) & 127;
  table_1[s_idx_27_1] = (stage_v_27_1 + 7) & 63;
  table_2[s_idx_27_2] = (stage_v_27_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int s_idx_28_1 = sec_r000949_9_1 & 3;
  int s_idx_28_2 = sec_r000949_9_2 & 3;
  int stage_v_28_1 = (table_1[s_idx_28_1] + pub_r000949_5_1) & 127;
  int stage_v_28_2 = (table_2[s_idx_28_2] + pub_r000949_5_2) & 127;
  table_1[s_idx_28_1] = (stage_v_28_1 + 7) & 63;
  table_2[s_idx_28_2] = (stage_v_28_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int s_idx_29_1 = stage_v_19_1 & 3;
  int s_idx_29_2 = stage_v_19_2 & 3;
  int stage_v_29_1 = (table_1[s_idx_29_1] + pub_r000949_10_1) & 127;
  int stage_v_29_2 = (table_2[s_idx_29_2] + pub_r000949_10_2) & 127;
  table_1[s_idx_29_1] = (stage_v_29_1 + 7) & 63;
  table_2[s_idx_29_2] = (stage_v_29_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int s_idx_30_1 = stage_v_25_1 & 3;
  int s_idx_30_2 = stage_v_25_2 & 3;
  int stage_v_30_1 = (table_1[s_idx_30_1] + pub_r000949_9_1) & 127;
  int stage_v_30_2 = (table_2[s_idx_30_2] + pub_r000949_9_2) & 127;
  table_1[s_idx_30_1] = (stage_v_30_1 + 7) & 63;
  table_2[s_idx_30_2] = (stage_v_30_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int s_idx_31_1 = stage_v_30_1 & 3;
  int s_idx_31_2 = stage_v_30_2 & 3;
  int stage_v_31_1 = (table_1[s_idx_31_1] + pub_r000949_2_1) & 127;
  int stage_v_31_2 = (table_2[s_idx_31_2] + pub_r000949_2_2) & 127;
  table_1[s_idx_31_1] = (stage_v_31_1 + 7) & 63;
  table_2[s_idx_31_2] = (stage_v_31_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int s_idx_32_1 = stage_v_25_1 & 3;
  int s_idx_32_2 = stage_v_25_2 & 3;
  int stage_v_32_1 = (table_1[s_idx_32_1] + pub_r000949_6_1) & 127;
  int stage_v_32_2 = (table_2[s_idx_32_2] + pub_r000949_6_2) & 127;
  table_1[s_idx_32_1] = (stage_v_32_1 + 7) & 63;
  table_2[s_idx_32_2] = (stage_v_32_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int s_idx_33_1 = sec_r000949_14_1 & 3;
  int s_idx_33_2 = sec_r000949_14_2 & 3;
  int stage_v_33_1 = (table_1[s_idx_33_1] + pub_r000949_1_1) & 127;
  int stage_v_33_2 = (table_2[s_idx_33_2] + pub_r000949_1_2) & 127;
  table_1[s_idx_33_1] = (stage_v_33_1 + 7) & 63;
  table_2[s_idx_33_2] = (stage_v_33_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int s_idx_34_1 = stage_v_31_1 & 3;
  int s_idx_34_2 = stage_v_31_2 & 3;
  int stage_v_34_1 = (table_1[s_idx_34_1] + pub_r000949_9_1) & 127;
  int stage_v_34_2 = (table_2[s_idx_34_2] + pub_r000949_9_2) & 127;
  table_1[s_idx_34_1] = (stage_v_34_1 + 7) & 63;
  table_2[s_idx_34_2] = (stage_v_34_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int s_idx_35_1 = stage_v_31_1 & 3;
  int s_idx_35_2 = stage_v_31_2 & 3;
  int stage_v_35_1 = (table_1[s_idx_35_1] + pub_r000949_11_1) & 127;
  int stage_v_35_2 = (table_2[s_idx_35_2] + pub_r000949_11_2) & 127;
  table_1[s_idx_35_1] = (stage_v_35_1 + 7) & 63;
  table_2[s_idx_35_2] = (stage_v_35_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int s_idx_36_1 = sec_r000949_0_1 & 3;
  int s_idx_36_2 = sec_r000949_0_2 & 3;
  int stage_v_36_1 = (table_1[s_idx_36_1] + pub_r000949_20_1) & 127;
  int stage_v_36_2 = (table_2[s_idx_36_2] + pub_r000949_20_2) & 127;
  table_1[s_idx_36_1] = (stage_v_36_1 + 7) & 63;
  table_2[s_idx_36_2] = (stage_v_36_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int s_idx_37_1 = stage_v_32_1 & 3;
  int s_idx_37_2 = stage_v_32_2 & 3;
  int stage_v_37_1 = (table_1[s_idx_37_1] + pub_r000949_2_1) & 127;
  int stage_v_37_2 = (table_2[s_idx_37_2] + pub_r000949_2_2) & 127;
  table_1[s_idx_37_1] = (stage_v_37_1 + 7) & 63;
  table_2[s_idx_37_2] = (stage_v_37_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int s_idx_38_1 = stage_v_34_1 & 3;
  int s_idx_38_2 = stage_v_34_2 & 3;
  int stage_v_38_1 = (table_1[s_idx_38_1] + pub_r000949_3_1) & 127;
  int stage_v_38_2 = (table_2[s_idx_38_2] + pub_r000949_3_2) & 127;
  table_1[s_idx_38_1] = (stage_v_38_1 + 7) & 63;
  table_2[s_idx_38_2] = (stage_v_38_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int s_idx_39_1 = sec_r000949_15_1 & 3;
  int s_idx_39_2 = sec_r000949_15_2 & 3;
  int stage_v_39_1 = (table_1[s_idx_39_1] + pub_r000949_3_1) & 127;
  int stage_v_39_2 = (table_2[s_idx_39_2] + pub_r000949_3_2) & 127;
  table_1[s_idx_39_1] = (stage_v_39_1 + 7) & 63;
  table_2[s_idx_39_2] = (stage_v_39_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int s_idx_40_1 = stage_v_28_1 & 3;
  int s_idx_40_2 = stage_v_28_2 & 3;
  int stage_v_40_1 = (table_1[s_idx_40_1] + pub_r000949_7_1) & 127;
  int stage_v_40_2 = (table_2[s_idx_40_2] + pub_r000949_7_2) & 127;
  table_1[s_idx_40_1] = (stage_v_40_1 + 7) & 63;
  table_2[s_idx_40_2] = (stage_v_40_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int s_idx_41_1 = sec_r000949_8_1 & 3;
  int s_idx_41_2 = sec_r000949_8_2 & 3;
  int stage_v_41_1 = (table_1[s_idx_41_1] + pub_r000949_12_1) & 127;
  int stage_v_41_2 = (table_2[s_idx_41_2] + pub_r000949_12_2) & 127;
  table_1[s_idx_41_1] = (stage_v_41_1 + 7) & 63;
  table_2[s_idx_41_2] = (stage_v_41_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int s_idx_42_1 = sec_r000949_13_1 & 3;
  int s_idx_42_2 = sec_r000949_13_2 & 3;
  int stage_v_42_1 = (table_1[s_idx_42_1] + pub_r000949_1_1) & 127;
  int stage_v_42_2 = (table_2[s_idx_42_2] + pub_r000949_1_2) & 127;
  table_1[s_idx_42_1] = (stage_v_42_1 + 7) & 63;
  table_2[s_idx_42_2] = (stage_v_42_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int s_idx_43_1 = stage_v_29_1 & 3;
  int s_idx_43_2 = stage_v_29_2 & 3;
  int stage_v_43_1 = (table_1[s_idx_43_1] + pub_r000949_1_1) & 127;
  int stage_v_43_2 = (table_2[s_idx_43_2] + pub_r000949_1_2) & 127;
  table_1[s_idx_43_1] = (stage_v_43_1 + 7) & 63;
  table_2[s_idx_43_2] = (stage_v_43_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int s_idx_44_1 = stage_v_43_1 & 3;
  int s_idx_44_2 = stage_v_43_2 & 3;
  int stage_v_44_1 = (table_1[s_idx_44_1] + pub_r000949_11_1) & 127;
  int stage_v_44_2 = (table_2[s_idx_44_2] + pub_r000949_11_2) & 127;
  table_1[s_idx_44_1] = (stage_v_44_1 + 7) & 63;
  table_2[s_idx_44_2] = (stage_v_44_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int s_idx_45_1 = stage_v_43_1 & 3;
  int s_idx_45_2 = stage_v_43_2 & 3;
  int stage_v_45_1 = (table_1[s_idx_45_1] + pub_r000949_16_1) & 127;
  int stage_v_45_2 = (table_2[s_idx_45_2] + pub_r000949_16_2) & 127;
  table_1[s_idx_45_1] = (stage_v_45_1 + 7) & 63;
  table_2[s_idx_45_2] = (stage_v_45_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int s_idx_46_1 = stage_v_25_1 & 3;
  int s_idx_46_2 = stage_v_25_2 & 3;
  int stage_v_46_1 = (table_1[s_idx_46_1] + pub_r000949_13_1) & 127;
  int stage_v_46_2 = (table_2[s_idx_46_2] + pub_r000949_13_2) & 127;
  table_1[s_idx_46_1] = (stage_v_46_1 + 7) & 63;
  table_2[s_idx_46_2] = (stage_v_46_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int s_idx_47_1 = sec_r000949_13_1 & 3;
  int s_idx_47_2 = sec_r000949_13_2 & 3;
  int stage_v_47_1 = (table_1[s_idx_47_1] + pub_r000949_16_1) & 127;
  int stage_v_47_2 = (table_2[s_idx_47_2] + pub_r000949_16_2) & 127;
  table_1[s_idx_47_1] = (stage_v_47_1 + 7) & 63;
  table_2[s_idx_47_2] = (stage_v_47_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int s_idx_48_1 = stage_v_35_1 & 3;
  int s_idx_48_2 = stage_v_35_2 & 3;
  int stage_v_48_1 = (table_1[s_idx_48_1] + pub_r000949_7_1) & 127;
  int stage_v_48_2 = (table_2[s_idx_48_2] + pub_r000949_7_2) & 127;
  table_1[s_idx_48_1] = (stage_v_48_1 + 7) & 63;
  table_2[s_idx_48_2] = (stage_v_48_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int s_idx_49_1 = sec_r000949_4_1 & 3;
  int s_idx_49_2 = sec_r000949_4_2 & 3;
  int stage_v_49_1 = (table_1[s_idx_49_1] + pub_r000949_10_1) & 127;
  int stage_v_49_2 = (table_2[s_idx_49_2] + pub_r000949_10_2) & 127;
  table_1[s_idx_49_1] = (stage_v_49_1 + 7) & 63;
  table_2[s_idx_49_2] = (stage_v_49_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int s_idx_50_1 = sec_r000949_8_1 & 3;
  int s_idx_50_2 = sec_r000949_8_2 & 3;
  int stage_v_50_1 = (table_1[s_idx_50_1] + pub_r000949_20_1) & 127;
  int stage_v_50_2 = (table_2[s_idx_50_2] + pub_r000949_20_2) & 127;
  table_1[s_idx_50_1] = (stage_v_50_1 + 7) & 63;
  table_2[s_idx_50_2] = (stage_v_50_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int s_idx_51_1 = sec_r000949_5_1 & 3;
  int s_idx_51_2 = sec_r000949_5_2 & 3;
  int stage_v_51_1 = (table_1[s_idx_51_1] + pub_r000949_10_1) & 127;
  int stage_v_51_2 = (table_2[s_idx_51_2] + pub_r000949_10_2) & 127;
  table_1[s_idx_51_1] = (stage_v_51_1 + 7) & 63;
  table_2[s_idx_51_2] = (stage_v_51_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int s_idx_52_1 = stage_v_36_1 & 3;
  int s_idx_52_2 = stage_v_36_2 & 3;
  int stage_v_52_1 = (table_1[s_idx_52_1] + pub_r000949_18_1) & 127;
  int stage_v_52_2 = (table_2[s_idx_52_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_52_1] = (stage_v_52_1 + 7) & 63;
  table_2[s_idx_52_2] = (stage_v_52_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int s_idx_53_1 = sec_r000949_3_1 & 3;
  int s_idx_53_2 = sec_r000949_3_2 & 3;
  int stage_v_53_1 = (table_1[s_idx_53_1] + pub_r000949_13_1) & 127;
  int stage_v_53_2 = (table_2[s_idx_53_2] + pub_r000949_13_2) & 127;
  table_1[s_idx_53_1] = (stage_v_53_1 + 7) & 63;
  table_2[s_idx_53_2] = (stage_v_53_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int s_idx_54_1 = sec_r000949_2_1 & 3;
  int s_idx_54_2 = sec_r000949_2_2 & 3;
  int stage_v_54_1 = (table_1[s_idx_54_1] + pub_r000949_17_1) & 127;
  int stage_v_54_2 = (table_2[s_idx_54_2] + pub_r000949_17_2) & 127;
  table_1[s_idx_54_1] = (stage_v_54_1 + 7) & 63;
  table_2[s_idx_54_2] = (stage_v_54_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int s_idx_55_1 = stage_v_22_1 & 3;
  int s_idx_55_2 = stage_v_22_2 & 3;
  int stage_v_55_1 = (table_1[s_idx_55_1] + pub_r000949_2_1) & 127;
  int stage_v_55_2 = (table_2[s_idx_55_2] + pub_r000949_2_2) & 127;
  table_1[s_idx_55_1] = (stage_v_55_1 + 7) & 63;
  table_2[s_idx_55_2] = (stage_v_55_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int s_idx_56_1 = stage_v_36_1 & 3;
  int s_idx_56_2 = stage_v_36_2 & 3;
  int stage_v_56_1 = (table_1[s_idx_56_1] + pub_r000949_12_1) & 127;
  int stage_v_56_2 = (table_2[s_idx_56_2] + pub_r000949_12_2) & 127;
  table_1[s_idx_56_1] = (stage_v_56_1 + 7) & 63;
  table_2[s_idx_56_2] = (stage_v_56_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int s_idx_57_1 = stage_v_44_1 & 3;
  int s_idx_57_2 = stage_v_44_2 & 3;
  int stage_v_57_1 = (table_1[s_idx_57_1] + pub_r000949_13_1) & 127;
  int stage_v_57_2 = (table_2[s_idx_57_2] + pub_r000949_13_2) & 127;
  table_1[s_idx_57_1] = (stage_v_57_1 + 7) & 63;
  table_2[s_idx_57_2] = (stage_v_57_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int s_idx_58_1 = sec_r000949_5_1 & 3;
  int s_idx_58_2 = sec_r000949_5_2 & 3;
  int stage_v_58_1 = (table_1[s_idx_58_1] + pub_r000949_7_1) & 127;
  int stage_v_58_2 = (table_2[s_idx_58_2] + pub_r000949_7_2) & 127;
  table_1[s_idx_58_1] = (stage_v_58_1 + 7) & 63;
  table_2[s_idx_58_2] = (stage_v_58_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int s_idx_59_1 = stage_v_48_1 & 3;
  int s_idx_59_2 = stage_v_48_2 & 3;
  int stage_v_59_1 = (table_1[s_idx_59_1] + pub_r000949_6_1) & 127;
  int stage_v_59_2 = (table_2[s_idx_59_2] + pub_r000949_6_2) & 127;
  table_1[s_idx_59_1] = (stage_v_59_1 + 7) & 63;
  table_2[s_idx_59_2] = (stage_v_59_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int s_idx_60_1 = stage_v_42_1 & 3;
  int s_idx_60_2 = stage_v_42_2 & 3;
  int stage_v_60_1 = (table_1[s_idx_60_1] + pub_r000949_19_1) & 127;
  int stage_v_60_2 = (table_2[s_idx_60_2] + pub_r000949_19_2) & 127;
  table_1[s_idx_60_1] = (stage_v_60_1 + 7) & 63;
  table_2[s_idx_60_2] = (stage_v_60_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int s_idx_61_1 = sec_r000949_13_1 & 3;
  int s_idx_61_2 = sec_r000949_13_2 & 3;
  int stage_v_61_1 = (table_1[s_idx_61_1] + pub_r000949_9_1) & 127;
  int stage_v_61_2 = (table_2[s_idx_61_2] + pub_r000949_9_2) & 127;
  table_1[s_idx_61_1] = (stage_v_61_1 + 7) & 63;
  table_2[s_idx_61_2] = (stage_v_61_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int s_idx_62_1 = sec_r000949_14_1 & 3;
  int s_idx_62_2 = sec_r000949_14_2 & 3;
  int stage_v_62_1 = (table_1[s_idx_62_1] + pub_r000949_13_1) & 127;
  int stage_v_62_2 = (table_2[s_idx_62_2] + pub_r000949_13_2) & 127;
  table_1[s_idx_62_1] = (stage_v_62_1 + 7) & 63;
  table_2[s_idx_62_2] = (stage_v_62_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int s_idx_63_1 = stage_v_37_1 & 3;
  int s_idx_63_2 = stage_v_37_2 & 3;
  int stage_v_63_1 = (table_1[s_idx_63_1] + pub_r000949_14_1) & 127;
  int stage_v_63_2 = (table_2[s_idx_63_2] + pub_r000949_14_2) & 127;
  table_1[s_idx_63_1] = (stage_v_63_1 + 7) & 63;
  table_2[s_idx_63_2] = (stage_v_63_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int s_idx_64_1 = stage_v_20_1 & 3;
  int s_idx_64_2 = stage_v_20_2 & 3;
  int stage_v_64_1 = (table_1[s_idx_64_1] + pub_r000949_4_1) & 127;
  int stage_v_64_2 = (table_2[s_idx_64_2] + pub_r000949_4_2) & 127;
  table_1[s_idx_64_1] = (stage_v_64_1 + 7) & 63;
  table_2[s_idx_64_2] = (stage_v_64_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int s_idx_65_1 = sec_r000949_15_1 & 3;
  int s_idx_65_2 = sec_r000949_15_2 & 3;
  int stage_v_65_1 = (table_1[s_idx_65_1] + pub_r000949_18_1) & 127;
  int stage_v_65_2 = (table_2[s_idx_65_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_65_1] = (stage_v_65_1 + 7) & 63;
  table_2[s_idx_65_2] = (stage_v_65_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int s_idx_66_1 = sec_r000949_6_1 & 3;
  int s_idx_66_2 = sec_r000949_6_2 & 3;
  int stage_v_66_1 = (table_1[s_idx_66_1] + pub_r000949_19_1) & 127;
  int stage_v_66_2 = (table_2[s_idx_66_2] + pub_r000949_19_2) & 127;
  table_1[s_idx_66_1] = (stage_v_66_1 + 7) & 63;
  table_2[s_idx_66_2] = (stage_v_66_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int s_idx_67_1 = stage_v_29_1 & 3;
  int s_idx_67_2 = stage_v_29_2 & 3;
  int stage_v_67_1 = (table_1[s_idx_67_1] + pub_r000949_18_1) & 127;
  int stage_v_67_2 = (table_2[s_idx_67_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_67_1] = (stage_v_67_1 + 7) & 63;
  table_2[s_idx_67_2] = (stage_v_67_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int s_idx_68_1 = stage_v_30_1 & 3;
  int s_idx_68_2 = stage_v_30_2 & 3;
  int stage_v_68_1 = (table_1[s_idx_68_1] + pub_r000949_5_1) & 127;
  int stage_v_68_2 = (table_2[s_idx_68_2] + pub_r000949_5_2) & 127;
  table_1[s_idx_68_1] = (stage_v_68_1 + 7) & 63;
  table_2[s_idx_68_2] = (stage_v_68_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int s_idx_69_1 = stage_v_20_1 & 3;
  int s_idx_69_2 = stage_v_20_2 & 3;
  int stage_v_69_1 = (table_1[s_idx_69_1] + pub_r000949_18_1) & 127;
  int stage_v_69_2 = (table_2[s_idx_69_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_69_1] = (stage_v_69_1 + 7) & 63;
  table_2[s_idx_69_2] = (stage_v_69_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int s_idx_70_1 = stage_v_21_1 & 3;
  int s_idx_70_2 = stage_v_21_2 & 3;
  int stage_v_70_1 = (table_1[s_idx_70_1] + pub_r000949_11_1) & 127;
  int stage_v_70_2 = (table_2[s_idx_70_2] + pub_r000949_11_2) & 127;
  table_1[s_idx_70_1] = (stage_v_70_1 + 7) & 63;
  table_2[s_idx_70_2] = (stage_v_70_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int s_idx_71_1 = stage_v_41_1 & 3;
  int s_idx_71_2 = stage_v_41_2 & 3;
  int stage_v_71_1 = (table_1[s_idx_71_1] + pub_r000949_13_1) & 127;
  int stage_v_71_2 = (table_2[s_idx_71_2] + pub_r000949_13_2) & 127;
  table_1[s_idx_71_1] = (stage_v_71_1 + 7) & 63;
  table_2[s_idx_71_2] = (stage_v_71_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int s_idx_72_1 = stage_v_65_1 & 3;
  int s_idx_72_2 = stage_v_65_2 & 3;
  int stage_v_72_1 = (table_1[s_idx_72_1] + pub_r000949_2_1) & 127;
  int stage_v_72_2 = (table_2[s_idx_72_2] + pub_r000949_2_2) & 127;
  table_1[s_idx_72_1] = (stage_v_72_1 + 7) & 63;
  table_2[s_idx_72_2] = (stage_v_72_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int s_idx_73_1 = stage_v_60_1 & 3;
  int s_idx_73_2 = stage_v_60_2 & 3;
  int stage_v_73_1 = (table_1[s_idx_73_1] + pub_r000949_17_1) & 127;
  int stage_v_73_2 = (table_2[s_idx_73_2] + pub_r000949_17_2) & 127;
  table_1[s_idx_73_1] = (stage_v_73_1 + 7) & 63;
  table_2[s_idx_73_2] = (stage_v_73_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int s_idx_74_1 = stage_v_32_1 & 3;
  int s_idx_74_2 = stage_v_32_2 & 3;
  int stage_v_74_1 = (table_1[s_idx_74_1] + pub_r000949_9_1) & 127;
  int stage_v_74_2 = (table_2[s_idx_74_2] + pub_r000949_9_2) & 127;
  table_1[s_idx_74_1] = (stage_v_74_1 + 7) & 63;
  table_2[s_idx_74_2] = (stage_v_74_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int s_idx_75_1 = stage_v_53_1 & 3;
  int s_idx_75_2 = stage_v_53_2 & 3;
  int stage_v_75_1 = (table_1[s_idx_75_1] + pub_r000949_17_1) & 127;
  int stage_v_75_2 = (table_2[s_idx_75_2] + pub_r000949_17_2) & 127;
  table_1[s_idx_75_1] = (stage_v_75_1 + 7) & 63;
  table_2[s_idx_75_2] = (stage_v_75_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int s_idx_76_1 = stage_v_48_1 & 3;
  int s_idx_76_2 = stage_v_48_2 & 3;
  int stage_v_76_1 = (table_1[s_idx_76_1] + pub_r000949_13_1) & 127;
  int stage_v_76_2 = (table_2[s_idx_76_2] + pub_r000949_13_2) & 127;
  table_1[s_idx_76_1] = (stage_v_76_1 + 7) & 63;
  table_2[s_idx_76_2] = (stage_v_76_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int s_idx_77_1 = stage_v_58_1 & 3;
  int s_idx_77_2 = stage_v_58_2 & 3;
  int stage_v_77_1 = (table_1[s_idx_77_1] + pub_r000949_4_1) & 127;
  int stage_v_77_2 = (table_2[s_idx_77_2] + pub_r000949_4_2) & 127;
  table_1[s_idx_77_1] = (stage_v_77_1 + 7) & 63;
  table_2[s_idx_77_2] = (stage_v_77_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int s_idx_78_1 = stage_v_76_1 & 3;
  int s_idx_78_2 = stage_v_76_2 & 3;
  int stage_v_78_1 = (table_1[s_idx_78_1] + pub_r000949_5_1) & 127;
  int stage_v_78_2 = (table_2[s_idx_78_2] + pub_r000949_5_2) & 127;
  table_1[s_idx_78_1] = (stage_v_78_1 + 7) & 63;
  table_2[s_idx_78_2] = (stage_v_78_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int s_idx_79_1 = stage_v_45_1 & 3;
  int s_idx_79_2 = stage_v_45_2 & 3;
  int stage_v_79_1 = (table_1[s_idx_79_1] + pub_r000949_3_1) & 127;
  int stage_v_79_2 = (table_2[s_idx_79_2] + pub_r000949_3_2) & 127;
  table_1[s_idx_79_1] = (stage_v_79_1 + 7) & 63;
  table_2[s_idx_79_2] = (stage_v_79_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int s_idx_80_1 = stage_v_77_1 & 3;
  int s_idx_80_2 = stage_v_77_2 & 3;
  int stage_v_80_1 = (table_1[s_idx_80_1] + pub_r000949_20_1) & 127;
  int stage_v_80_2 = (table_2[s_idx_80_2] + pub_r000949_20_2) & 127;
  table_1[s_idx_80_1] = (stage_v_80_1 + 7) & 63;
  table_2[s_idx_80_2] = (stage_v_80_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int s_idx_81_1 = stage_v_55_1 & 3;
  int s_idx_81_2 = stage_v_55_2 & 3;
  int stage_v_81_1 = (table_1[s_idx_81_1] + pub_r000949_18_1) & 127;
  int stage_v_81_2 = (table_2[s_idx_81_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_81_1] = (stage_v_81_1 + 7) & 63;
  table_2[s_idx_81_2] = (stage_v_81_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int s_idx_82_1 = sec_r000949_9_1 & 3;
  int s_idx_82_2 = sec_r000949_9_2 & 3;
  int stage_v_82_1 = (table_1[s_idx_82_1] + pub_r000949_11_1) & 127;
  int stage_v_82_2 = (table_2[s_idx_82_2] + pub_r000949_11_2) & 127;
  table_1[s_idx_82_1] = (stage_v_82_1 + 7) & 63;
  table_2[s_idx_82_2] = (stage_v_82_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int s_idx_83_1 = sec_r000949_4_1 & 3;
  int s_idx_83_2 = sec_r000949_4_2 & 3;
  int stage_v_83_1 = (table_1[s_idx_83_1] + pub_r000949_12_1) & 127;
  int stage_v_83_2 = (table_2[s_idx_83_2] + pub_r000949_12_2) & 127;
  table_1[s_idx_83_1] = (stage_v_83_1 + 7) & 63;
  table_2[s_idx_83_2] = (stage_v_83_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int s_idx_84_1 = sec_r000949_3_1 & 3;
  int s_idx_84_2 = sec_r000949_3_2 & 3;
  int stage_v_84_1 = (table_1[s_idx_84_1] + pub_r000949_4_1) & 127;
  int stage_v_84_2 = (table_2[s_idx_84_2] + pub_r000949_4_2) & 127;
  table_1[s_idx_84_1] = (stage_v_84_1 + 7) & 63;
  table_2[s_idx_84_2] = (stage_v_84_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int s_idx_85_1 = sec_r000949_11_1 & 3;
  int s_idx_85_2 = sec_r000949_11_2 & 3;
  int stage_v_85_1 = (table_1[s_idx_85_1] + pub_r000949_14_1) & 127;
  int stage_v_85_2 = (table_2[s_idx_85_2] + pub_r000949_14_2) & 127;
  table_1[s_idx_85_1] = (stage_v_85_1 + 7) & 63;
  table_2[s_idx_85_2] = (stage_v_85_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int s_idx_86_1 = stage_v_51_1 & 3;
  int s_idx_86_2 = stage_v_51_2 & 3;
  int stage_v_86_1 = (table_1[s_idx_86_1] + pub_r000949_15_1) & 127;
  int stage_v_86_2 = (table_2[s_idx_86_2] + pub_r000949_15_2) & 127;
  table_1[s_idx_86_1] = (stage_v_86_1 + 7) & 63;
  table_2[s_idx_86_2] = (stage_v_86_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int s_idx_87_1 = sec_r000949_11_1 & 3;
  int s_idx_87_2 = sec_r000949_11_2 & 3;
  int stage_v_87_1 = (table_1[s_idx_87_1] + pub_r000949_15_1) & 127;
  int stage_v_87_2 = (table_2[s_idx_87_2] + pub_r000949_15_2) & 127;
  table_1[s_idx_87_1] = (stage_v_87_1 + 7) & 63;
  table_2[s_idx_87_2] = (stage_v_87_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int s_idx_88_1 = sec_r000949_4_1 & 3;
  int s_idx_88_2 = sec_r000949_4_2 & 3;
  int stage_v_88_1 = (table_1[s_idx_88_1] + pub_r000949_15_1) & 127;
  int stage_v_88_2 = (table_2[s_idx_88_2] + pub_r000949_15_2) & 127;
  table_1[s_idx_88_1] = (stage_v_88_1 + 7) & 63;
  table_2[s_idx_88_2] = (stage_v_88_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int s_idx_89_1 = sec_r000949_4_1 & 3;
  int s_idx_89_2 = sec_r000949_4_2 & 3;
  int stage_v_89_1 = (table_1[s_idx_89_1] + pub_r000949_12_1) & 127;
  int stage_v_89_2 = (table_2[s_idx_89_2] + pub_r000949_12_2) & 127;
  table_1[s_idx_89_1] = (stage_v_89_1 + 7) & 63;
  table_2[s_idx_89_2] = (stage_v_89_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int s_idx_90_1 = stage_v_72_1 & 3;
  int s_idx_90_2 = stage_v_72_2 & 3;
  int stage_v_90_1 = (table_1[s_idx_90_1] + pub_r000949_6_1) & 127;
  int stage_v_90_2 = (table_2[s_idx_90_2] + pub_r000949_6_2) & 127;
  table_1[s_idx_90_1] = (stage_v_90_1 + 7) & 63;
  table_2[s_idx_90_2] = (stage_v_90_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int s_idx_91_1 = stage_v_67_1 & 3;
  int s_idx_91_2 = stage_v_67_2 & 3;
  int stage_v_91_1 = (table_1[s_idx_91_1] + pub_r000949_7_1) & 127;
  int stage_v_91_2 = (table_2[s_idx_91_2] + pub_r000949_7_2) & 127;
  table_1[s_idx_91_1] = (stage_v_91_1 + 7) & 63;
  table_2[s_idx_91_2] = (stage_v_91_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int s_idx_92_1 = stage_v_78_1 & 3;
  int s_idx_92_2 = stage_v_78_2 & 3;
  int stage_v_92_1 = (table_1[s_idx_92_1] + pub_r000949_5_1) & 127;
  int stage_v_92_2 = (table_2[s_idx_92_2] + pub_r000949_5_2) & 127;
  table_1[s_idx_92_1] = (stage_v_92_1 + 7) & 63;
  table_2[s_idx_92_2] = (stage_v_92_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int s_idx_93_1 = stage_v_44_1 & 3;
  int s_idx_93_2 = stage_v_44_2 & 3;
  int stage_v_93_1 = (table_1[s_idx_93_1] + pub_r000949_15_1) & 127;
  int stage_v_93_2 = (table_2[s_idx_93_2] + pub_r000949_15_2) & 127;
  table_1[s_idx_93_1] = (stage_v_93_1 + 7) & 63;
  table_2[s_idx_93_2] = (stage_v_93_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int s_idx_94_1 = sec_r000949_13_1 & 3;
  int s_idx_94_2 = sec_r000949_13_2 & 3;
  int stage_v_94_1 = (table_1[s_idx_94_1] + pub_r000949_4_1) & 127;
  int stage_v_94_2 = (table_2[s_idx_94_2] + pub_r000949_4_2) & 127;
  table_1[s_idx_94_1] = (stage_v_94_1 + 7) & 63;
  table_2[s_idx_94_2] = (stage_v_94_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int s_idx_95_1 = stage_v_24_1 & 3;
  int s_idx_95_2 = stage_v_24_2 & 3;
  int stage_v_95_1 = (table_1[s_idx_95_1] + pub_r000949_18_1) & 127;
  int stage_v_95_2 = (table_2[s_idx_95_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_95_1] = (stage_v_95_1 + 7) & 63;
  table_2[s_idx_95_2] = (stage_v_95_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int s_idx_96_1 = stage_v_81_1 & 3;
  int s_idx_96_2 = stage_v_81_2 & 3;
  int stage_v_96_1 = (table_1[s_idx_96_1] + pub_r000949_6_1) & 127;
  int stage_v_96_2 = (table_2[s_idx_96_2] + pub_r000949_6_2) & 127;
  table_1[s_idx_96_1] = (stage_v_96_1 + 7) & 63;
  table_2[s_idx_96_2] = (stage_v_96_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int s_idx_97_1 = stage_v_59_1 & 3;
  int s_idx_97_2 = stage_v_59_2 & 3;
  int stage_v_97_1 = (table_1[s_idx_97_1] + pub_r000949_10_1) & 127;
  int stage_v_97_2 = (table_2[s_idx_97_2] + pub_r000949_10_2) & 127;
  table_1[s_idx_97_1] = (stage_v_97_1 + 7) & 63;
  table_2[s_idx_97_2] = (stage_v_97_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int s_idx_98_1 = stage_v_25_1 & 3;
  int s_idx_98_2 = stage_v_25_2 & 3;
  int stage_v_98_1 = (table_1[s_idx_98_1] + pub_r000949_6_1) & 127;
  int stage_v_98_2 = (table_2[s_idx_98_2] + pub_r000949_6_2) & 127;
  table_1[s_idx_98_1] = (stage_v_98_1 + 7) & 63;
  table_2[s_idx_98_2] = (stage_v_98_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int s_idx_99_1 = sec_r000949_11_1 & 3;
  int s_idx_99_2 = sec_r000949_11_2 & 3;
  int stage_v_99_1 = (table_1[s_idx_99_1] + pub_r000949_20_1) & 127;
  int stage_v_99_2 = (table_2[s_idx_99_2] + pub_r000949_20_2) & 127;
  table_1[s_idx_99_1] = (stage_v_99_1 + 7) & 63;
  table_2[s_idx_99_2] = (stage_v_99_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int s_idx_100_1 = stage_v_72_1 & 3;
  int s_idx_100_2 = stage_v_72_2 & 3;
  int stage_v_100_1 = (table_1[s_idx_100_1] + pub_r000949_17_1) & 127;
  int stage_v_100_2 = (table_2[s_idx_100_2] + pub_r000949_17_2) & 127;
  table_1[s_idx_100_1] = (stage_v_100_1 + 7) & 63;
  table_2[s_idx_100_2] = (stage_v_100_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int s_idx_101_1 = stage_v_24_1 & 3;
  int s_idx_101_2 = stage_v_24_2 & 3;
  int stage_v_101_1 = (table_1[s_idx_101_1] + pub_r000949_7_1) & 127;
  int stage_v_101_2 = (table_2[s_idx_101_2] + pub_r000949_7_2) & 127;
  table_1[s_idx_101_1] = (stage_v_101_1 + 7) & 63;
  table_2[s_idx_101_2] = (stage_v_101_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int s_idx_102_1 = sec_r000949_4_1 & 3;
  int s_idx_102_2 = sec_r000949_4_2 & 3;
  int stage_v_102_1 = (table_1[s_idx_102_1] + pub_r000949_20_1) & 127;
  int stage_v_102_2 = (table_2[s_idx_102_2] + pub_r000949_20_2) & 127;
  table_1[s_idx_102_1] = (stage_v_102_1 + 7) & 63;
  table_2[s_idx_102_2] = (stage_v_102_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int s_idx_103_1 = stage_v_48_1 & 3;
  int s_idx_103_2 = stage_v_48_2 & 3;
  int stage_v_103_1 = (table_1[s_idx_103_1] + pub_r000949_7_1) & 127;
  int stage_v_103_2 = (table_2[s_idx_103_2] + pub_r000949_7_2) & 127;
  table_1[s_idx_103_1] = (stage_v_103_1 + 7) & 63;
  table_2[s_idx_103_2] = (stage_v_103_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int s_idx_104_1 = sec_r000949_12_1 & 3;
  int s_idx_104_2 = sec_r000949_12_2 & 3;
  int stage_v_104_1 = (table_1[s_idx_104_1] + pub_r000949_7_1) & 127;
  int stage_v_104_2 = (table_2[s_idx_104_2] + pub_r000949_7_2) & 127;
  table_1[s_idx_104_1] = (stage_v_104_1 + 7) & 63;
  table_2[s_idx_104_2] = (stage_v_104_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int s_idx_105_1 = stage_v_85_1 & 3;
  int s_idx_105_2 = stage_v_85_2 & 3;
  int stage_v_105_1 = (table_1[s_idx_105_1] + pub_r000949_12_1) & 127;
  int stage_v_105_2 = (table_2[s_idx_105_2] + pub_r000949_12_2) & 127;
  table_1[s_idx_105_1] = (stage_v_105_1 + 7) & 63;
  table_2[s_idx_105_2] = (stage_v_105_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int s_idx_106_1 = stage_v_53_1 & 3;
  int s_idx_106_2 = stage_v_53_2 & 3;
  int stage_v_106_1 = (table_1[s_idx_106_1] + pub_r000949_18_1) & 127;
  int stage_v_106_2 = (table_2[s_idx_106_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_106_1] = (stage_v_106_1 + 7) & 63;
  table_2[s_idx_106_2] = (stage_v_106_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int s_idx_107_1 = stage_v_64_1 & 3;
  int s_idx_107_2 = stage_v_64_2 & 3;
  int stage_v_107_1 = (table_1[s_idx_107_1] + pub_r000949_9_1) & 127;
  int stage_v_107_2 = (table_2[s_idx_107_2] + pub_r000949_9_2) & 127;
  table_1[s_idx_107_1] = (stage_v_107_1 + 7) & 63;
  table_2[s_idx_107_2] = (stage_v_107_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int s_idx_108_1 = sec_r000949_10_1 & 3;
  int s_idx_108_2 = sec_r000949_10_2 & 3;
  int stage_v_108_1 = (table_1[s_idx_108_1] + pub_r000949_12_1) & 127;
  int stage_v_108_2 = (table_2[s_idx_108_2] + pub_r000949_12_2) & 127;
  table_1[s_idx_108_1] = (stage_v_108_1 + 7) & 63;
  table_2[s_idx_108_2] = (stage_v_108_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int s_idx_109_1 = sec_r000949_6_1 & 3;
  int s_idx_109_2 = sec_r000949_6_2 & 3;
  int stage_v_109_1 = (table_1[s_idx_109_1] + pub_r000949_18_1) & 127;
  int stage_v_109_2 = (table_2[s_idx_109_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_109_1] = (stage_v_109_1 + 7) & 63;
  table_2[s_idx_109_2] = (stage_v_109_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int s_idx_110_1 = stage_v_53_1 & 3;
  int s_idx_110_2 = stage_v_53_2 & 3;
  int stage_v_110_1 = (table_1[s_idx_110_1] + pub_r000949_11_1) & 127;
  int stage_v_110_2 = (table_2[s_idx_110_2] + pub_r000949_11_2) & 127;
  table_1[s_idx_110_1] = (stage_v_110_1 + 7) & 63;
  table_2[s_idx_110_2] = (stage_v_110_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int s_idx_111_1 = sec_r000949_9_1 & 3;
  int s_idx_111_2 = sec_r000949_9_2 & 3;
  int stage_v_111_1 = (table_1[s_idx_111_1] + pub_r000949_18_1) & 127;
  int stage_v_111_2 = (table_2[s_idx_111_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_111_1] = (stage_v_111_1 + 7) & 63;
  table_2[s_idx_111_2] = (stage_v_111_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int s_idx_112_1 = sec_r000949_6_1 & 3;
  int s_idx_112_2 = sec_r000949_6_2 & 3;
  int stage_v_112_1 = (table_1[s_idx_112_1] + pub_r000949_14_1) & 127;
  int stage_v_112_2 = (table_2[s_idx_112_2] + pub_r000949_14_2) & 127;
  table_1[s_idx_112_1] = (stage_v_112_1 + 7) & 63;
  table_2[s_idx_112_2] = (stage_v_112_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int s_idx_113_1 = stage_v_55_1 & 3;
  int s_idx_113_2 = stage_v_55_2 & 3;
  int stage_v_113_1 = (table_1[s_idx_113_1] + pub_r000949_11_1) & 127;
  int stage_v_113_2 = (table_2[s_idx_113_2] + pub_r000949_11_2) & 127;
  table_1[s_idx_113_1] = (stage_v_113_1 + 7) & 63;
  table_2[s_idx_113_2] = (stage_v_113_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int s_idx_114_1 = sec_r000949_13_1 & 3;
  int s_idx_114_2 = sec_r000949_13_2 & 3;
  int stage_v_114_1 = (table_1[s_idx_114_1] + pub_r000949_19_1) & 127;
  int stage_v_114_2 = (table_2[s_idx_114_2] + pub_r000949_19_2) & 127;
  table_1[s_idx_114_1] = (stage_v_114_1 + 7) & 63;
  table_2[s_idx_114_2] = (stage_v_114_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int s_idx_115_1 = sec_r000949_0_1 & 3;
  int s_idx_115_2 = sec_r000949_0_2 & 3;
  int stage_v_115_1 = (table_1[s_idx_115_1] + pub_r000949_19_1) & 127;
  int stage_v_115_2 = (table_2[s_idx_115_2] + pub_r000949_19_2) & 127;
  table_1[s_idx_115_1] = (stage_v_115_1 + 7) & 63;
  table_2[s_idx_115_2] = (stage_v_115_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int s_idx_116_1 = stage_v_61_1 & 3;
  int s_idx_116_2 = stage_v_61_2 & 3;
  int stage_v_116_1 = (table_1[s_idx_116_1] + pub_r000949_10_1) & 127;
  int stage_v_116_2 = (table_2[s_idx_116_2] + pub_r000949_10_2) & 127;
  table_1[s_idx_116_1] = (stage_v_116_1 + 7) & 63;
  table_2[s_idx_116_2] = (stage_v_116_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int s_idx_117_1 = sec_r000949_3_1 & 3;
  int s_idx_117_2 = sec_r000949_3_2 & 3;
  int stage_v_117_1 = (table_1[s_idx_117_1] + pub_r000949_8_1) & 127;
  int stage_v_117_2 = (table_2[s_idx_117_2] + pub_r000949_8_2) & 127;
  table_1[s_idx_117_1] = (stage_v_117_1 + 7) & 63;
  table_2[s_idx_117_2] = (stage_v_117_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int s_idx_118_1 = stage_v_101_1 & 3;
  int s_idx_118_2 = stage_v_101_2 & 3;
  int stage_v_118_1 = (table_1[s_idx_118_1] + pub_r000949_17_1) & 127;
  int stage_v_118_2 = (table_2[s_idx_118_2] + pub_r000949_17_2) & 127;
  table_1[s_idx_118_1] = (stage_v_118_1 + 7) & 63;
  table_2[s_idx_118_2] = (stage_v_118_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int s_idx_119_1 = stage_v_95_1 & 3;
  int s_idx_119_2 = stage_v_95_2 & 3;
  int stage_v_119_1 = (table_1[s_idx_119_1] + pub_r000949_19_1) & 127;
  int stage_v_119_2 = (table_2[s_idx_119_2] + pub_r000949_19_2) & 127;
  table_1[s_idx_119_1] = (stage_v_119_1 + 7) & 63;
  table_2[s_idx_119_2] = (stage_v_119_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int s_idx_120_1 = sec_r000949_4_1 & 3;
  int s_idx_120_2 = sec_r000949_4_2 & 3;
  int stage_v_120_1 = (table_1[s_idx_120_1] + pub_r000949_5_1) & 127;
  int stage_v_120_2 = (table_2[s_idx_120_2] + pub_r000949_5_2) & 127;
  table_1[s_idx_120_1] = (stage_v_120_1 + 7) & 63;
  table_2[s_idx_120_2] = (stage_v_120_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int s_idx_121_1 = sec_r000949_7_1 & 3;
  int s_idx_121_2 = sec_r000949_7_2 & 3;
  int stage_v_121_1 = (table_1[s_idx_121_1] + pub_r000949_20_1) & 127;
  int stage_v_121_2 = (table_2[s_idx_121_2] + pub_r000949_20_2) & 127;
  table_1[s_idx_121_1] = (stage_v_121_1 + 7) & 63;
  table_2[s_idx_121_2] = (stage_v_121_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int s_idx_122_1 = stage_v_108_1 & 3;
  int s_idx_122_2 = stage_v_108_2 & 3;
  int stage_v_122_1 = (table_1[s_idx_122_1] + pub_r000949_12_1) & 127;
  int stage_v_122_2 = (table_2[s_idx_122_2] + pub_r000949_12_2) & 127;
  table_1[s_idx_122_1] = (stage_v_122_1 + 7) & 63;
  table_2[s_idx_122_2] = (stage_v_122_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int s_idx_123_1 = stage_v_37_1 & 3;
  int s_idx_123_2 = stage_v_37_2 & 3;
  int stage_v_123_1 = (table_1[s_idx_123_1] + pub_r000949_15_1) & 127;
  int stage_v_123_2 = (table_2[s_idx_123_2] + pub_r000949_15_2) & 127;
  table_1[s_idx_123_1] = (stage_v_123_1 + 7) & 63;
  table_2[s_idx_123_2] = (stage_v_123_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int s_idx_124_1 = sec_r000949_2_1 & 3;
  int s_idx_124_2 = sec_r000949_2_2 & 3;
  int stage_v_124_1 = (table_1[s_idx_124_1] + pub_r000949_13_1) & 127;
  int stage_v_124_2 = (table_2[s_idx_124_2] + pub_r000949_13_2) & 127;
  table_1[s_idx_124_1] = (stage_v_124_1 + 7) & 63;
  table_2[s_idx_124_2] = (stage_v_124_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int s_idx_125_1 = stage_v_85_1 & 3;
  int s_idx_125_2 = stage_v_85_2 & 3;
  int stage_v_125_1 = (table_1[s_idx_125_1] + pub_r000949_17_1) & 127;
  int stage_v_125_2 = (table_2[s_idx_125_2] + pub_r000949_17_2) & 127;
  table_1[s_idx_125_1] = (stage_v_125_1 + 7) & 63;
  table_2[s_idx_125_2] = (stage_v_125_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int s_idx_126_1 = stage_v_40_1 & 3;
  int s_idx_126_2 = stage_v_40_2 & 3;
  int stage_v_126_1 = (table_1[s_idx_126_1] + pub_r000949_17_1) & 127;
  int stage_v_126_2 = (table_2[s_idx_126_2] + pub_r000949_17_2) & 127;
  table_1[s_idx_126_1] = (stage_v_126_1 + 7) & 63;
  table_2[s_idx_126_2] = (stage_v_126_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int s_idx_127_1 = stage_v_80_1 & 3;
  int s_idx_127_2 = stage_v_80_2 & 3;
  int stage_v_127_1 = (table_1[s_idx_127_1] + pub_r000949_5_1) & 127;
  int stage_v_127_2 = (table_2[s_idx_127_2] + pub_r000949_5_2) & 127;
  table_1[s_idx_127_1] = (stage_v_127_1 + 7) & 63;
  table_2[s_idx_127_2] = (stage_v_127_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int s_idx_128_1 = stage_v_38_1 & 3;
  int s_idx_128_2 = stage_v_38_2 & 3;
  int stage_v_128_1 = (table_1[s_idx_128_1] + pub_r000949_17_1) & 127;
  int stage_v_128_2 = (table_2[s_idx_128_2] + pub_r000949_17_2) & 127;
  table_1[s_idx_128_1] = (stage_v_128_1 + 7) & 63;
  table_2[s_idx_128_2] = (stage_v_128_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int s_idx_129_1 = stage_v_98_1 & 3;
  int s_idx_129_2 = stage_v_98_2 & 3;
  int stage_v_129_1 = (table_1[s_idx_129_1] + pub_r000949_18_1) & 127;
  int stage_v_129_2 = (table_2[s_idx_129_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_129_1] = (stage_v_129_1 + 7) & 63;
  table_2[s_idx_129_2] = (stage_v_129_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int s_idx_130_1 = sec_r000949_15_1 & 3;
  int s_idx_130_2 = sec_r000949_15_2 & 3;
  int stage_v_130_1 = (table_1[s_idx_130_1] + pub_r000949_9_1) & 127;
  int stage_v_130_2 = (table_2[s_idx_130_2] + pub_r000949_9_2) & 127;
  table_1[s_idx_130_1] = (stage_v_130_1 + 7) & 63;
  table_2[s_idx_130_2] = (stage_v_130_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int s_idx_131_1 = stage_v_117_1 & 3;
  int s_idx_131_2 = stage_v_117_2 & 3;
  int stage_v_131_1 = (table_1[s_idx_131_1] + pub_r000949_10_1) & 127;
  int stage_v_131_2 = (table_2[s_idx_131_2] + pub_r000949_10_2) & 127;
  table_1[s_idx_131_1] = (stage_v_131_1 + 7) & 63;
  table_2[s_idx_131_2] = (stage_v_131_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int s_idx_132_1 = stage_v_36_1 & 3;
  int s_idx_132_2 = stage_v_36_2 & 3;
  int stage_v_132_1 = (table_1[s_idx_132_1] + pub_r000949_16_1) & 127;
  int stage_v_132_2 = (table_2[s_idx_132_2] + pub_r000949_16_2) & 127;
  table_1[s_idx_132_1] = (stage_v_132_1 + 7) & 63;
  table_2[s_idx_132_2] = (stage_v_132_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int s_idx_133_1 = sec_r000949_8_1 & 3;
  int s_idx_133_2 = sec_r000949_8_2 & 3;
  int stage_v_133_1 = (table_1[s_idx_133_1] + pub_r000949_5_1) & 127;
  int stage_v_133_2 = (table_2[s_idx_133_2] + pub_r000949_5_2) & 127;
  table_1[s_idx_133_1] = (stage_v_133_1 + 7) & 63;
  table_2[s_idx_133_2] = (stage_v_133_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int s_idx_134_1 = sec_r000949_1_1 & 3;
  int s_idx_134_2 = sec_r000949_1_2 & 3;
  int stage_v_134_1 = (table_1[s_idx_134_1] + pub_r000949_18_1) & 127;
  int stage_v_134_2 = (table_2[s_idx_134_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_134_1] = (stage_v_134_1 + 7) & 63;
  table_2[s_idx_134_2] = (stage_v_134_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int s_idx_135_1 = stage_v_69_1 & 3;
  int s_idx_135_2 = stage_v_69_2 & 3;
  int stage_v_135_1 = (table_1[s_idx_135_1] + pub_r000949_16_1) & 127;
  int stage_v_135_2 = (table_2[s_idx_135_2] + pub_r000949_16_2) & 127;
  table_1[s_idx_135_1] = (stage_v_135_1 + 7) & 63;
  table_2[s_idx_135_2] = (stage_v_135_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int s_idx_136_1 = sec_r000949_5_1 & 3;
  int s_idx_136_2 = sec_r000949_5_2 & 3;
  int stage_v_136_1 = (table_1[s_idx_136_1] + pub_r000949_18_1) & 127;
  int stage_v_136_2 = (table_2[s_idx_136_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_136_1] = (stage_v_136_1 + 7) & 63;
  table_2[s_idx_136_2] = (stage_v_136_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int s_idx_137_1 = stage_v_128_1 & 3;
  int s_idx_137_2 = stage_v_128_2 & 3;
  int stage_v_137_1 = (table_1[s_idx_137_1] + pub_r000949_10_1) & 127;
  int stage_v_137_2 = (table_2[s_idx_137_2] + pub_r000949_10_2) & 127;
  table_1[s_idx_137_1] = (stage_v_137_1 + 7) & 63;
  table_2[s_idx_137_2] = (stage_v_137_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int s_idx_138_1 = stage_v_29_1 & 3;
  int s_idx_138_2 = stage_v_29_2 & 3;
  int stage_v_138_1 = (table_1[s_idx_138_1] + pub_r000949_9_1) & 127;
  int stage_v_138_2 = (table_2[s_idx_138_2] + pub_r000949_9_2) & 127;
  table_1[s_idx_138_1] = (stage_v_138_1 + 7) & 63;
  table_2[s_idx_138_2] = (stage_v_138_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int s_idx_139_1 = sec_r000949_0_1 & 3;
  int s_idx_139_2 = sec_r000949_0_2 & 3;
  int stage_v_139_1 = (table_1[s_idx_139_1] + pub_r000949_2_1) & 127;
  int stage_v_139_2 = (table_2[s_idx_139_2] + pub_r000949_2_2) & 127;
  table_1[s_idx_139_1] = (stage_v_139_1 + 7) & 63;
  table_2[s_idx_139_2] = (stage_v_139_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int s_idx_140_1 = stage_v_136_1 & 3;
  int s_idx_140_2 = stage_v_136_2 & 3;
  int stage_v_140_1 = (table_1[s_idx_140_1] + pub_r000949_18_1) & 127;
  int stage_v_140_2 = (table_2[s_idx_140_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_140_1] = (stage_v_140_1 + 7) & 63;
  table_2[s_idx_140_2] = (stage_v_140_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int s_idx_141_1 = sec_r000949_9_1 & 3;
  int s_idx_141_2 = sec_r000949_9_2 & 3;
  int stage_v_141_1 = (table_1[s_idx_141_1] + pub_r000949_16_1) & 127;
  int stage_v_141_2 = (table_2[s_idx_141_2] + pub_r000949_16_2) & 127;
  table_1[s_idx_141_1] = (stage_v_141_1 + 7) & 63;
  table_2[s_idx_141_2] = (stage_v_141_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int s_idx_142_1 = stage_v_67_1 & 3;
  int s_idx_142_2 = stage_v_67_2 & 3;
  int stage_v_142_1 = (table_1[s_idx_142_1] + pub_r000949_20_1) & 127;
  int stage_v_142_2 = (table_2[s_idx_142_2] + pub_r000949_20_2) & 127;
  table_1[s_idx_142_1] = (stage_v_142_1 + 7) & 63;
  table_2[s_idx_142_2] = (stage_v_142_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int s_idx_143_1 = stage_v_47_1 & 3;
  int s_idx_143_2 = stage_v_47_2 & 3;
  int stage_v_143_1 = (table_1[s_idx_143_1] + pub_r000949_17_1) & 127;
  int stage_v_143_2 = (table_2[s_idx_143_2] + pub_r000949_17_2) & 127;
  table_1[s_idx_143_1] = (stage_v_143_1 + 7) & 63;
  table_2[s_idx_143_2] = (stage_v_143_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int s_idx_144_1 = stage_v_100_1 & 3;
  int s_idx_144_2 = stage_v_100_2 & 3;
  int stage_v_144_1 = (table_1[s_idx_144_1] + pub_r000949_7_1) & 127;
  int stage_v_144_2 = (table_2[s_idx_144_2] + pub_r000949_7_2) & 127;
  table_1[s_idx_144_1] = (stage_v_144_1 + 7) & 63;
  table_2[s_idx_144_2] = (stage_v_144_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int s_idx_145_1 = stage_v_95_1 & 3;
  int s_idx_145_2 = stage_v_95_2 & 3;
  int stage_v_145_1 = (table_1[s_idx_145_1] + pub_r000949_11_1) & 127;
  int stage_v_145_2 = (table_2[s_idx_145_2] + pub_r000949_11_2) & 127;
  table_1[s_idx_145_1] = (stage_v_145_1 + 7) & 63;
  table_2[s_idx_145_2] = (stage_v_145_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int s_idx_146_1 = sec_r000949_10_1 & 3;
  int s_idx_146_2 = sec_r000949_10_2 & 3;
  int stage_v_146_1 = (table_1[s_idx_146_1] + pub_r000949_20_1) & 127;
  int stage_v_146_2 = (table_2[s_idx_146_2] + pub_r000949_20_2) & 127;
  table_1[s_idx_146_1] = (stage_v_146_1 + 7) & 63;
  table_2[s_idx_146_2] = (stage_v_146_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int s_idx_147_1 = stage_v_101_1 & 3;
  int s_idx_147_2 = stage_v_101_2 & 3;
  int stage_v_147_1 = (table_1[s_idx_147_1] + pub_r000949_7_1) & 127;
  int stage_v_147_2 = (table_2[s_idx_147_2] + pub_r000949_7_2) & 127;
  table_1[s_idx_147_1] = (stage_v_147_1 + 7) & 63;
  table_2[s_idx_147_2] = (stage_v_147_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int s_idx_148_1 = stage_v_122_1 & 3;
  int s_idx_148_2 = stage_v_122_2 & 3;
  int stage_v_148_1 = (table_1[s_idx_148_1] + pub_r000949_9_1) & 127;
  int stage_v_148_2 = (table_2[s_idx_148_2] + pub_r000949_9_2) & 127;
  table_1[s_idx_148_1] = (stage_v_148_1 + 7) & 63;
  table_2[s_idx_148_2] = (stage_v_148_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int s_idx_149_1 = stage_v_121_1 & 3;
  int s_idx_149_2 = stage_v_121_2 & 3;
  int stage_v_149_1 = (table_1[s_idx_149_1] + pub_r000949_4_1) & 127;
  int stage_v_149_2 = (table_2[s_idx_149_2] + pub_r000949_4_2) & 127;
  table_1[s_idx_149_1] = (stage_v_149_1 + 7) & 63;
  table_2[s_idx_149_2] = (stage_v_149_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int s_idx_150_1 = stage_v_110_1 & 3;
  int s_idx_150_2 = stage_v_110_2 & 3;
  int stage_v_150_1 = (table_1[s_idx_150_1] + pub_r000949_10_1) & 127;
  int stage_v_150_2 = (table_2[s_idx_150_2] + pub_r000949_10_2) & 127;
  table_1[s_idx_150_1] = (stage_v_150_1 + 7) & 63;
  table_2[s_idx_150_2] = (stage_v_150_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int s_idx_151_1 = sec_r000949_14_1 & 3;
  int s_idx_151_2 = sec_r000949_14_2 & 3;
  int stage_v_151_1 = (table_1[s_idx_151_1] + pub_r000949_12_1) & 127;
  int stage_v_151_2 = (table_2[s_idx_151_2] + pub_r000949_12_2) & 127;
  table_1[s_idx_151_1] = (stage_v_151_1 + 7) & 63;
  table_2[s_idx_151_2] = (stage_v_151_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int s_idx_152_1 = sec_r000949_4_1 & 3;
  int s_idx_152_2 = sec_r000949_4_2 & 3;
  int stage_v_152_1 = (table_1[s_idx_152_1] + pub_r000949_10_1) & 127;
  int stage_v_152_2 = (table_2[s_idx_152_2] + pub_r000949_10_2) & 127;
  table_1[s_idx_152_1] = (stage_v_152_1 + 7) & 63;
  table_2[s_idx_152_2] = (stage_v_152_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int s_idx_153_1 = stage_v_89_1 & 3;
  int s_idx_153_2 = stage_v_89_2 & 3;
  int stage_v_153_1 = (table_1[s_idx_153_1] + pub_r000949_4_1) & 127;
  int stage_v_153_2 = (table_2[s_idx_153_2] + pub_r000949_4_2) & 127;
  table_1[s_idx_153_1] = (stage_v_153_1 + 7) & 63;
  table_2[s_idx_153_2] = (stage_v_153_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int s_idx_154_1 = sec_r000949_13_1 & 3;
  int s_idx_154_2 = sec_r000949_13_2 & 3;
  int stage_v_154_1 = (table_1[s_idx_154_1] + pub_r000949_16_1) & 127;
  int stage_v_154_2 = (table_2[s_idx_154_2] + pub_r000949_16_2) & 127;
  table_1[s_idx_154_1] = (stage_v_154_1 + 7) & 63;
  table_2[s_idx_154_2] = (stage_v_154_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int s_idx_155_1 = sec_r000949_10_1 & 3;
  int s_idx_155_2 = sec_r000949_10_2 & 3;
  int stage_v_155_1 = (table_1[s_idx_155_1] + pub_r000949_14_1) & 127;
  int stage_v_155_2 = (table_2[s_idx_155_2] + pub_r000949_14_2) & 127;
  table_1[s_idx_155_1] = (stage_v_155_1 + 7) & 63;
  table_2[s_idx_155_2] = (stage_v_155_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int s_idx_156_1 = stage_v_121_1 & 3;
  int s_idx_156_2 = stage_v_121_2 & 3;
  int stage_v_156_1 = (table_1[s_idx_156_1] + pub_r000949_4_1) & 127;
  int stage_v_156_2 = (table_2[s_idx_156_2] + pub_r000949_4_2) & 127;
  table_1[s_idx_156_1] = (stage_v_156_1 + 7) & 63;
  table_2[s_idx_156_2] = (stage_v_156_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int s_idx_157_1 = stage_v_58_1 & 3;
  int s_idx_157_2 = stage_v_58_2 & 3;
  int stage_v_157_1 = (table_1[s_idx_157_1] + pub_r000949_3_1) & 127;
  int stage_v_157_2 = (table_2[s_idx_157_2] + pub_r000949_3_2) & 127;
  table_1[s_idx_157_1] = (stage_v_157_1 + 7) & 63;
  table_2[s_idx_157_2] = (stage_v_157_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int s_idx_158_1 = stage_v_145_1 & 3;
  int s_idx_158_2 = stage_v_145_2 & 3;
  int stage_v_158_1 = (table_1[s_idx_158_1] + pub_r000949_18_1) & 127;
  int stage_v_158_2 = (table_2[s_idx_158_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_158_1] = (stage_v_158_1 + 7) & 63;
  table_2[s_idx_158_2] = (stage_v_158_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int s_idx_159_1 = stage_v_92_1 & 3;
  int s_idx_159_2 = stage_v_92_2 & 3;
  int stage_v_159_1 = (table_1[s_idx_159_1] + pub_r000949_4_1) & 127;
  int stage_v_159_2 = (table_2[s_idx_159_2] + pub_r000949_4_2) & 127;
  table_1[s_idx_159_1] = (stage_v_159_1 + 7) & 63;
  table_2[s_idx_159_2] = (stage_v_159_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int s_idx_160_1 = stage_v_104_1 & 3;
  int s_idx_160_2 = stage_v_104_2 & 3;
  int stage_v_160_1 = (table_1[s_idx_160_1] + pub_r000949_12_1) & 127;
  int stage_v_160_2 = (table_2[s_idx_160_2] + pub_r000949_12_2) & 127;
  table_1[s_idx_160_1] = (stage_v_160_1 + 7) & 63;
  table_2[s_idx_160_2] = (stage_v_160_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int s_idx_161_1 = stage_v_130_1 & 3;
  int s_idx_161_2 = stage_v_130_2 & 3;
  int stage_v_161_1 = (table_1[s_idx_161_1] + pub_r000949_17_1) & 127;
  int stage_v_161_2 = (table_2[s_idx_161_2] + pub_r000949_17_2) & 127;
  table_1[s_idx_161_1] = (stage_v_161_1 + 7) & 63;
  table_2[s_idx_161_2] = (stage_v_161_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int s_idx_162_1 = stage_v_120_1 & 3;
  int s_idx_162_2 = stage_v_120_2 & 3;
  int stage_v_162_1 = (table_1[s_idx_162_1] + pub_r000949_15_1) & 127;
  int stage_v_162_2 = (table_2[s_idx_162_2] + pub_r000949_15_2) & 127;
  table_1[s_idx_162_1] = (stage_v_162_1 + 7) & 63;
  table_2[s_idx_162_2] = (stage_v_162_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int s_idx_163_1 = stage_v_22_1 & 3;
  int s_idx_163_2 = stage_v_22_2 & 3;
  int stage_v_163_1 = (table_1[s_idx_163_1] + pub_r000949_7_1) & 127;
  int stage_v_163_2 = (table_2[s_idx_163_2] + pub_r000949_7_2) & 127;
  table_1[s_idx_163_1] = (stage_v_163_1 + 7) & 63;
  table_2[s_idx_163_2] = (stage_v_163_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int s_idx_164_1 = stage_v_24_1 & 3;
  int s_idx_164_2 = stage_v_24_2 & 3;
  int stage_v_164_1 = (table_1[s_idx_164_1] + pub_r000949_2_1) & 127;
  int stage_v_164_2 = (table_2[s_idx_164_2] + pub_r000949_2_2) & 127;
  table_1[s_idx_164_1] = (stage_v_164_1 + 7) & 63;
  table_2[s_idx_164_2] = (stage_v_164_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int s_idx_165_1 = stage_v_21_1 & 3;
  int s_idx_165_2 = stage_v_21_2 & 3;
  int stage_v_165_1 = (table_1[s_idx_165_1] + pub_r000949_2_1) & 127;
  int stage_v_165_2 = (table_2[s_idx_165_2] + pub_r000949_2_2) & 127;
  table_1[s_idx_165_1] = (stage_v_165_1 + 7) & 63;
  table_2[s_idx_165_2] = (stage_v_165_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int s_idx_166_1 = stage_v_96_1 & 3;
  int s_idx_166_2 = stage_v_96_2 & 3;
  int stage_v_166_1 = (table_1[s_idx_166_1] + pub_r000949_20_1) & 127;
  int stage_v_166_2 = (table_2[s_idx_166_2] + pub_r000949_20_2) & 127;
  table_1[s_idx_166_1] = (stage_v_166_1 + 7) & 63;
  table_2[s_idx_166_2] = (stage_v_166_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int s_idx_167_1 = stage_v_139_1 & 3;
  int s_idx_167_2 = stage_v_139_2 & 3;
  int stage_v_167_1 = (table_1[s_idx_167_1] + pub_r000949_13_1) & 127;
  int stage_v_167_2 = (table_2[s_idx_167_2] + pub_r000949_13_2) & 127;
  table_1[s_idx_167_1] = (stage_v_167_1 + 7) & 63;
  table_2[s_idx_167_2] = (stage_v_167_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int s_idx_168_1 = sec_r000949_2_1 & 3;
  int s_idx_168_2 = sec_r000949_2_2 & 3;
  int stage_v_168_1 = (table_1[s_idx_168_1] + pub_r000949_14_1) & 127;
  int stage_v_168_2 = (table_2[s_idx_168_2] + pub_r000949_14_2) & 127;
  table_1[s_idx_168_1] = (stage_v_168_1 + 7) & 63;
  table_2[s_idx_168_2] = (stage_v_168_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int s_idx_169_1 = stage_v_50_1 & 3;
  int s_idx_169_2 = stage_v_50_2 & 3;
  int stage_v_169_1 = (table_1[s_idx_169_1] + pub_r000949_10_1) & 127;
  int stage_v_169_2 = (table_2[s_idx_169_2] + pub_r000949_10_2) & 127;
  table_1[s_idx_169_1] = (stage_v_169_1 + 7) & 63;
  table_2[s_idx_169_2] = (stage_v_169_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int s_idx_170_1 = stage_v_157_1 & 3;
  int s_idx_170_2 = stage_v_157_2 & 3;
  int stage_v_170_1 = (table_1[s_idx_170_1] + pub_r000949_13_1) & 127;
  int stage_v_170_2 = (table_2[s_idx_170_2] + pub_r000949_13_2) & 127;
  table_1[s_idx_170_1] = (stage_v_170_1 + 7) & 63;
  table_2[s_idx_170_2] = (stage_v_170_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int s_idx_171_1 = stage_v_53_1 & 3;
  int s_idx_171_2 = stage_v_53_2 & 3;
  int stage_v_171_1 = (table_1[s_idx_171_1] + pub_r000949_2_1) & 127;
  int stage_v_171_2 = (table_2[s_idx_171_2] + pub_r000949_2_2) & 127;
  table_1[s_idx_171_1] = (stage_v_171_1 + 7) & 63;
  table_2[s_idx_171_2] = (stage_v_171_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int s_idx_172_1 = stage_v_113_1 & 3;
  int s_idx_172_2 = stage_v_113_2 & 3;
  int stage_v_172_1 = (table_1[s_idx_172_1] + pub_r000949_14_1) & 127;
  int stage_v_172_2 = (table_2[s_idx_172_2] + pub_r000949_14_2) & 127;
  table_1[s_idx_172_1] = (stage_v_172_1 + 7) & 63;
  table_2[s_idx_172_2] = (stage_v_172_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int s_idx_173_1 = sec_r000949_14_1 & 3;
  int s_idx_173_2 = sec_r000949_14_2 & 3;
  int stage_v_173_1 = (table_1[s_idx_173_1] + pub_r000949_17_1) & 127;
  int stage_v_173_2 = (table_2[s_idx_173_2] + pub_r000949_17_2) & 127;
  table_1[s_idx_173_1] = (stage_v_173_1 + 7) & 63;
  table_2[s_idx_173_2] = (stage_v_173_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int s_idx_174_1 = stage_v_36_1 & 3;
  int s_idx_174_2 = stage_v_36_2 & 3;
  int stage_v_174_1 = (table_1[s_idx_174_1] + pub_r000949_5_1) & 127;
  int stage_v_174_2 = (table_2[s_idx_174_2] + pub_r000949_5_2) & 127;
  table_1[s_idx_174_1] = (stage_v_174_1 + 7) & 63;
  table_2[s_idx_174_2] = (stage_v_174_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int s_idx_175_1 = stage_v_106_1 & 3;
  int s_idx_175_2 = stage_v_106_2 & 3;
  int stage_v_175_1 = (table_1[s_idx_175_1] + pub_r000949_9_1) & 127;
  int stage_v_175_2 = (table_2[s_idx_175_2] + pub_r000949_9_2) & 127;
  table_1[s_idx_175_1] = (stage_v_175_1 + 7) & 63;
  table_2[s_idx_175_2] = (stage_v_175_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int s_idx_176_1 = sec_r000949_7_1 & 3;
  int s_idx_176_2 = sec_r000949_7_2 & 3;
  int stage_v_176_1 = (table_1[s_idx_176_1] + pub_r000949_1_1) & 127;
  int stage_v_176_2 = (table_2[s_idx_176_2] + pub_r000949_1_2) & 127;
  table_1[s_idx_176_1] = (stage_v_176_1 + 7) & 63;
  table_2[s_idx_176_2] = (stage_v_176_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int s_idx_177_1 = sec_r000949_2_1 & 3;
  int s_idx_177_2 = sec_r000949_2_2 & 3;
  int stage_v_177_1 = (table_1[s_idx_177_1] + pub_r000949_12_1) & 127;
  int stage_v_177_2 = (table_2[s_idx_177_2] + pub_r000949_12_2) & 127;
  table_1[s_idx_177_1] = (stage_v_177_1 + 7) & 63;
  table_2[s_idx_177_2] = (stage_v_177_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int s_idx_178_1 = stage_v_94_1 & 3;
  int s_idx_178_2 = stage_v_94_2 & 3;
  int stage_v_178_1 = (table_1[s_idx_178_1] + pub_r000949_18_1) & 127;
  int stage_v_178_2 = (table_2[s_idx_178_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_178_1] = (stage_v_178_1 + 7) & 63;
  table_2[s_idx_178_2] = (stage_v_178_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int s_idx_179_1 = sec_r000949_8_1 & 3;
  int s_idx_179_2 = sec_r000949_8_2 & 3;
  int stage_v_179_1 = (table_1[s_idx_179_1] + pub_r000949_9_1) & 127;
  int stage_v_179_2 = (table_2[s_idx_179_2] + pub_r000949_9_2) & 127;
  table_1[s_idx_179_1] = (stage_v_179_1 + 7) & 63;
  table_2[s_idx_179_2] = (stage_v_179_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int s_idx_180_1 = sec_r000949_12_1 & 3;
  int s_idx_180_2 = sec_r000949_12_2 & 3;
  int stage_v_180_1 = (table_1[s_idx_180_1] + pub_r000949_3_1) & 127;
  int stage_v_180_2 = (table_2[s_idx_180_2] + pub_r000949_3_2) & 127;
  table_1[s_idx_180_1] = (stage_v_180_1 + 7) & 63;
  table_2[s_idx_180_2] = (stage_v_180_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int s_idx_181_1 = sec_r000949_14_1 & 3;
  int s_idx_181_2 = sec_r000949_14_2 & 3;
  int stage_v_181_1 = (table_1[s_idx_181_1] + pub_r000949_1_1) & 127;
  int stage_v_181_2 = (table_2[s_idx_181_2] + pub_r000949_1_2) & 127;
  table_1[s_idx_181_1] = (stage_v_181_1 + 7) & 63;
  table_2[s_idx_181_2] = (stage_v_181_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int s_idx_182_1 = stage_v_81_1 & 3;
  int s_idx_182_2 = stage_v_81_2 & 3;
  int stage_v_182_1 = (table_1[s_idx_182_1] + pub_r000949_0_1) & 127;
  int stage_v_182_2 = (table_2[s_idx_182_2] + pub_r000949_0_2) & 127;
  table_1[s_idx_182_1] = (stage_v_182_1 + 7) & 63;
  table_2[s_idx_182_2] = (stage_v_182_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int s_idx_183_1 = stage_v_73_1 & 3;
  int s_idx_183_2 = stage_v_73_2 & 3;
  int stage_v_183_1 = (table_1[s_idx_183_1] + pub_r000949_20_1) & 127;
  int stage_v_183_2 = (table_2[s_idx_183_2] + pub_r000949_20_2) & 127;
  table_1[s_idx_183_1] = (stage_v_183_1 + 7) & 63;
  table_2[s_idx_183_2] = (stage_v_183_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int s_idx_184_1 = sec_r000949_3_1 & 3;
  int s_idx_184_2 = sec_r000949_3_2 & 3;
  int stage_v_184_1 = (table_1[s_idx_184_1] + pub_r000949_15_1) & 127;
  int stage_v_184_2 = (table_2[s_idx_184_2] + pub_r000949_15_2) & 127;
  table_1[s_idx_184_1] = (stage_v_184_1 + 7) & 63;
  table_2[s_idx_184_2] = (stage_v_184_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int s_idx_185_1 = stage_v_86_1 & 3;
  int s_idx_185_2 = stage_v_86_2 & 3;
  int stage_v_185_1 = (table_1[s_idx_185_1] + pub_r000949_20_1) & 127;
  int stage_v_185_2 = (table_2[s_idx_185_2] + pub_r000949_20_2) & 127;
  table_1[s_idx_185_1] = (stage_v_185_1 + 7) & 63;
  table_2[s_idx_185_2] = (stage_v_185_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int s_idx_186_1 = sec_r000949_8_1 & 3;
  int s_idx_186_2 = sec_r000949_8_2 & 3;
  int stage_v_186_1 = (table_1[s_idx_186_1] + pub_r000949_14_1) & 127;
  int stage_v_186_2 = (table_2[s_idx_186_2] + pub_r000949_14_2) & 127;
  table_1[s_idx_186_1] = (stage_v_186_1 + 7) & 63;
  table_2[s_idx_186_2] = (stage_v_186_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int s_idx_187_1 = stage_v_92_1 & 3;
  int s_idx_187_2 = stage_v_92_2 & 3;
  int stage_v_187_1 = (table_1[s_idx_187_1] + pub_r000949_11_1) & 127;
  int stage_v_187_2 = (table_2[s_idx_187_2] + pub_r000949_11_2) & 127;
  table_1[s_idx_187_1] = (stage_v_187_1 + 7) & 63;
  table_2[s_idx_187_2] = (stage_v_187_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int s_idx_188_1 = stage_v_31_1 & 3;
  int s_idx_188_2 = stage_v_31_2 & 3;
  int stage_v_188_1 = (table_1[s_idx_188_1] + pub_r000949_17_1) & 127;
  int stage_v_188_2 = (table_2[s_idx_188_2] + pub_r000949_17_2) & 127;
  table_1[s_idx_188_1] = (stage_v_188_1 + 7) & 63;
  table_2[s_idx_188_2] = (stage_v_188_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int s_idx_189_1 = stage_v_76_1 & 3;
  int s_idx_189_2 = stage_v_76_2 & 3;
  int stage_v_189_1 = (table_1[s_idx_189_1] + pub_r000949_19_1) & 127;
  int stage_v_189_2 = (table_2[s_idx_189_2] + pub_r000949_19_2) & 127;
  table_1[s_idx_189_1] = (stage_v_189_1 + 7) & 63;
  table_2[s_idx_189_2] = (stage_v_189_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int s_idx_190_1 = sec_r000949_3_1 & 3;
  int s_idx_190_2 = sec_r000949_3_2 & 3;
  int stage_v_190_1 = (table_1[s_idx_190_1] + pub_r000949_10_1) & 127;
  int stage_v_190_2 = (table_2[s_idx_190_2] + pub_r000949_10_2) & 127;
  table_1[s_idx_190_1] = (stage_v_190_1 + 7) & 63;
  table_2[s_idx_190_2] = (stage_v_190_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int s_idx_191_1 = sec_r000949_9_1 & 3;
  int s_idx_191_2 = sec_r000949_9_2 & 3;
  int stage_v_191_1 = (table_1[s_idx_191_1] + pub_r000949_16_1) & 127;
  int stage_v_191_2 = (table_2[s_idx_191_2] + pub_r000949_16_2) & 127;
  table_1[s_idx_191_1] = (stage_v_191_1 + 7) & 63;
  table_2[s_idx_191_2] = (stage_v_191_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int s_idx_192_1 = stage_v_98_1 & 3;
  int s_idx_192_2 = stage_v_98_2 & 3;
  int stage_v_192_1 = (table_1[s_idx_192_1] + pub_r000949_10_1) & 127;
  int stage_v_192_2 = (table_2[s_idx_192_2] + pub_r000949_10_2) & 127;
  table_1[s_idx_192_1] = (stage_v_192_1 + 7) & 63;
  table_2[s_idx_192_2] = (stage_v_192_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int s_idx_193_1 = sec_r000949_12_1 & 3;
  int s_idx_193_2 = sec_r000949_12_2 & 3;
  int stage_v_193_1 = (table_1[s_idx_193_1] + pub_r000949_7_1) & 127;
  int stage_v_193_2 = (table_2[s_idx_193_2] + pub_r000949_7_2) & 127;
  table_1[s_idx_193_1] = (stage_v_193_1 + 7) & 63;
  table_2[s_idx_193_2] = (stage_v_193_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int s_idx_194_1 = stage_v_78_1 & 3;
  int s_idx_194_2 = stage_v_78_2 & 3;
  int stage_v_194_1 = (table_1[s_idx_194_1] + pub_r000949_13_1) & 127;
  int stage_v_194_2 = (table_2[s_idx_194_2] + pub_r000949_13_2) & 127;
  table_1[s_idx_194_1] = (stage_v_194_1 + 7) & 63;
  table_2[s_idx_194_2] = (stage_v_194_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int s_idx_195_1 = stage_v_23_1 & 3;
  int s_idx_195_2 = stage_v_23_2 & 3;
  int stage_v_195_1 = (table_1[s_idx_195_1] + pub_r000949_9_1) & 127;
  int stage_v_195_2 = (table_2[s_idx_195_2] + pub_r000949_9_2) & 127;
  table_1[s_idx_195_1] = (stage_v_195_1 + 7) & 63;
  table_2[s_idx_195_2] = (stage_v_195_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int s_idx_196_1 = stage_v_55_1 & 3;
  int s_idx_196_2 = stage_v_55_2 & 3;
  int stage_v_196_1 = (table_1[s_idx_196_1] + pub_r000949_11_1) & 127;
  int stage_v_196_2 = (table_2[s_idx_196_2] + pub_r000949_11_2) & 127;
  table_1[s_idx_196_1] = (stage_v_196_1 + 7) & 63;
  table_2[s_idx_196_2] = (stage_v_196_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int s_idx_197_1 = stage_v_126_1 & 3;
  int s_idx_197_2 = stage_v_126_2 & 3;
  int stage_v_197_1 = (table_1[s_idx_197_1] + pub_r000949_7_1) & 127;
  int stage_v_197_2 = (table_2[s_idx_197_2] + pub_r000949_7_2) & 127;
  table_1[s_idx_197_1] = (stage_v_197_1 + 7) & 63;
  table_2[s_idx_197_2] = (stage_v_197_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int s_idx_198_1 = stage_v_129_1 & 3;
  int s_idx_198_2 = stage_v_129_2 & 3;
  int stage_v_198_1 = (table_1[s_idx_198_1] + pub_r000949_9_1) & 127;
  int stage_v_198_2 = (table_2[s_idx_198_2] + pub_r000949_9_2) & 127;
  table_1[s_idx_198_1] = (stage_v_198_1 + 7) & 63;
  table_2[s_idx_198_2] = (stage_v_198_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int s_idx_199_1 = stage_v_119_1 & 3;
  int s_idx_199_2 = stage_v_119_2 & 3;
  int stage_v_199_1 = (table_1[s_idx_199_1] + pub_r000949_13_1) & 127;
  int stage_v_199_2 = (table_2[s_idx_199_2] + pub_r000949_13_2) & 127;
  table_1[s_idx_199_1] = (stage_v_199_1 + 7) & 63;
  table_2[s_idx_199_2] = (stage_v_199_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int s_idx_200_1 = stage_v_28_1 & 3;
  int s_idx_200_2 = stage_v_28_2 & 3;
  int stage_v_200_1 = (table_1[s_idx_200_1] + pub_r000949_19_1) & 127;
  int stage_v_200_2 = (table_2[s_idx_200_2] + pub_r000949_19_2) & 127;
  table_1[s_idx_200_1] = (stage_v_200_1 + 7) & 63;
  table_2[s_idx_200_2] = (stage_v_200_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int s_idx_201_1 = sec_r000949_5_1 & 3;
  int s_idx_201_2 = sec_r000949_5_2 & 3;
  int stage_v_201_1 = (table_1[s_idx_201_1] + pub_r000949_5_1) & 127;
  int stage_v_201_2 = (table_2[s_idx_201_2] + pub_r000949_5_2) & 127;
  table_1[s_idx_201_1] = (stage_v_201_1 + 7) & 63;
  table_2[s_idx_201_2] = (stage_v_201_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int s_idx_202_1 = stage_v_114_1 & 3;
  int s_idx_202_2 = stage_v_114_2 & 3;
  int stage_v_202_1 = (table_1[s_idx_202_1] + pub_r000949_17_1) & 127;
  int stage_v_202_2 = (table_2[s_idx_202_2] + pub_r000949_17_2) & 127;
  table_1[s_idx_202_1] = (stage_v_202_1 + 7) & 63;
  table_2[s_idx_202_2] = (stage_v_202_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int s_idx_203_1 = stage_v_180_1 & 3;
  int s_idx_203_2 = stage_v_180_2 & 3;
  int stage_v_203_1 = (table_1[s_idx_203_1] + pub_r000949_15_1) & 127;
  int stage_v_203_2 = (table_2[s_idx_203_2] + pub_r000949_15_2) & 127;
  table_1[s_idx_203_1] = (stage_v_203_1 + 7) & 63;
  table_2[s_idx_203_2] = (stage_v_203_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int s_idx_204_1 = stage_v_183_1 & 3;
  int s_idx_204_2 = stage_v_183_2 & 3;
  int stage_v_204_1 = (table_1[s_idx_204_1] + pub_r000949_4_1) & 127;
  int stage_v_204_2 = (table_2[s_idx_204_2] + pub_r000949_4_2) & 127;
  table_1[s_idx_204_1] = (stage_v_204_1 + 7) & 63;
  table_2[s_idx_204_2] = (stage_v_204_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int s_idx_205_1 = stage_v_138_1 & 3;
  int s_idx_205_2 = stage_v_138_2 & 3;
  int stage_v_205_1 = (table_1[s_idx_205_1] + pub_r000949_12_1) & 127;
  int stage_v_205_2 = (table_2[s_idx_205_2] + pub_r000949_12_2) & 127;
  table_1[s_idx_205_1] = (stage_v_205_1 + 7) & 63;
  table_2[s_idx_205_2] = (stage_v_205_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int s_idx_206_1 = stage_v_74_1 & 3;
  int s_idx_206_2 = stage_v_74_2 & 3;
  int stage_v_206_1 = (table_1[s_idx_206_1] + pub_r000949_18_1) & 127;
  int stage_v_206_2 = (table_2[s_idx_206_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_206_1] = (stage_v_206_1 + 7) & 63;
  table_2[s_idx_206_2] = (stage_v_206_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int s_idx_207_1 = stage_v_175_1 & 3;
  int s_idx_207_2 = stage_v_175_2 & 3;
  int stage_v_207_1 = (table_1[s_idx_207_1] + pub_r000949_6_1) & 127;
  int stage_v_207_2 = (table_2[s_idx_207_2] + pub_r000949_6_2) & 127;
  table_1[s_idx_207_1] = (stage_v_207_1 + 7) & 63;
  table_2[s_idx_207_2] = (stage_v_207_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int s_idx_208_1 = stage_v_165_1 & 3;
  int s_idx_208_2 = stage_v_165_2 & 3;
  int stage_v_208_1 = (table_1[s_idx_208_1] + pub_r000949_9_1) & 127;
  int stage_v_208_2 = (table_2[s_idx_208_2] + pub_r000949_9_2) & 127;
  table_1[s_idx_208_1] = (stage_v_208_1 + 7) & 63;
  table_2[s_idx_208_2] = (stage_v_208_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int s_idx_209_1 = stage_v_202_1 & 3;
  int s_idx_209_2 = stage_v_202_2 & 3;
  int stage_v_209_1 = (table_1[s_idx_209_1] + pub_r000949_20_1) & 127;
  int stage_v_209_2 = (table_2[s_idx_209_2] + pub_r000949_20_2) & 127;
  table_1[s_idx_209_1] = (stage_v_209_1 + 7) & 63;
  table_2[s_idx_209_2] = (stage_v_209_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int s_idx_210_1 = sec_r000949_15_1 & 3;
  int s_idx_210_2 = sec_r000949_15_2 & 3;
  int stage_v_210_1 = (table_1[s_idx_210_1] + pub_r000949_6_1) & 127;
  int stage_v_210_2 = (table_2[s_idx_210_2] + pub_r000949_6_2) & 127;
  table_1[s_idx_210_1] = (stage_v_210_1 + 7) & 63;
  table_2[s_idx_210_2] = (stage_v_210_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int s_idx_211_1 = stage_v_208_1 & 3;
  int s_idx_211_2 = stage_v_208_2 & 3;
  int stage_v_211_1 = (table_1[s_idx_211_1] + pub_r000949_2_1) & 127;
  int stage_v_211_2 = (table_2[s_idx_211_2] + pub_r000949_2_2) & 127;
  table_1[s_idx_211_1] = (stage_v_211_1 + 7) & 63;
  table_2[s_idx_211_2] = (stage_v_211_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int s_idx_212_1 = sec_r000949_12_1 & 3;
  int s_idx_212_2 = sec_r000949_12_2 & 3;
  int stage_v_212_1 = (table_1[s_idx_212_1] + pub_r000949_20_1) & 127;
  int stage_v_212_2 = (table_2[s_idx_212_2] + pub_r000949_20_2) & 127;
  table_1[s_idx_212_1] = (stage_v_212_1 + 7) & 63;
  table_2[s_idx_212_2] = (stage_v_212_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int s_idx_213_1 = stage_v_116_1 & 3;
  int s_idx_213_2 = stage_v_116_2 & 3;
  int stage_v_213_1 = (table_1[s_idx_213_1] + pub_r000949_6_1) & 127;
  int stage_v_213_2 = (table_2[s_idx_213_2] + pub_r000949_6_2) & 127;
  table_1[s_idx_213_1] = (stage_v_213_1 + 7) & 63;
  table_2[s_idx_213_2] = (stage_v_213_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int s_idx_214_1 = stage_v_120_1 & 3;
  int s_idx_214_2 = stage_v_120_2 & 3;
  int stage_v_214_1 = (table_1[s_idx_214_1] + pub_r000949_10_1) & 127;
  int stage_v_214_2 = (table_2[s_idx_214_2] + pub_r000949_10_2) & 127;
  table_1[s_idx_214_1] = (stage_v_214_1 + 7) & 63;
  table_2[s_idx_214_2] = (stage_v_214_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int s_idx_215_1 = stage_v_50_1 & 3;
  int s_idx_215_2 = stage_v_50_2 & 3;
  int stage_v_215_1 = (table_1[s_idx_215_1] + pub_r000949_12_1) & 127;
  int stage_v_215_2 = (table_2[s_idx_215_2] + pub_r000949_12_2) & 127;
  table_1[s_idx_215_1] = (stage_v_215_1 + 7) & 63;
  table_2[s_idx_215_2] = (stage_v_215_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int s_idx_216_1 = stage_v_129_1 & 3;
  int s_idx_216_2 = stage_v_129_2 & 3;
  int stage_v_216_1 = (table_1[s_idx_216_1] + pub_r000949_12_1) & 127;
  int stage_v_216_2 = (table_2[s_idx_216_2] + pub_r000949_12_2) & 127;
  table_1[s_idx_216_1] = (stage_v_216_1 + 7) & 63;
  table_2[s_idx_216_2] = (stage_v_216_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int s_idx_217_1 = stage_v_176_1 & 3;
  int s_idx_217_2 = stage_v_176_2 & 3;
  int stage_v_217_1 = (table_1[s_idx_217_1] + pub_r000949_18_1) & 127;
  int stage_v_217_2 = (table_2[s_idx_217_2] + pub_r000949_18_2) & 127;
  table_1[s_idx_217_1] = (stage_v_217_1 + 7) & 63;
  table_2[s_idx_217_2] = (stage_v_217_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int s_idx_218_1 = sec_r000949_2_1 & 3;
  int s_idx_218_2 = sec_r000949_2_2 & 3;
  int stage_v_218_1 = (table_1[s_idx_218_1] + pub_r000949_14_1) & 127;
  int stage_v_218_2 = (table_2[s_idx_218_2] + pub_r000949_14_2) & 127;
  table_1[s_idx_218_1] = (stage_v_218_1 + 7) & 63;
  table_2[s_idx_218_2] = (stage_v_218_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int s_idx_219_1 = stage_v_28_1 & 3;
  int s_idx_219_2 = stage_v_28_2 & 3;
  int stage_v_219_1 = (table_1[s_idx_219_1] + pub_r000949_17_1) & 127;
  int stage_v_219_2 = (table_2[s_idx_219_2] + pub_r000949_17_2) & 127;
  table_1[s_idx_219_1] = (stage_v_219_1 + 7) & 63;
  table_2[s_idx_219_2] = (stage_v_219_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int s_idx_220_1 = stage_v_179_1 & 3;
  int s_idx_220_2 = stage_v_179_2 & 3;
  int stage_v_220_1 = (table_1[s_idx_220_1] + pub_r000949_1_1) & 127;
  int stage_v_220_2 = (table_2[s_idx_220_2] + pub_r000949_1_2) & 127;
  table_1[s_idx_220_1] = (stage_v_220_1 + 7) & 63;
  table_2[s_idx_220_2] = (stage_v_220_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int s_idx_221_1 = stage_v_122_1 & 3;
  int s_idx_221_2 = stage_v_122_2 & 3;
  int stage_v_221_1 = (table_1[s_idx_221_1] + pub_r000949_10_1) & 127;
  int stage_v_221_2 = (table_2[s_idx_221_2] + pub_r000949_10_2) & 127;
  table_1[s_idx_221_1] = (stage_v_221_1 + 7) & 63;
  table_2[s_idx_221_2] = (stage_v_221_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int s_idx_222_1 = stage_v_80_1 & 3;
  int s_idx_222_2 = stage_v_80_2 & 3;
  int stage_v_222_1 = (table_1[s_idx_222_1] + pub_r000949_11_1) & 127;
  int stage_v_222_2 = (table_2[s_idx_222_2] + pub_r000949_11_2) & 127;
  table_1[s_idx_222_1] = (stage_v_222_1 + 7) & 63;
  table_2[s_idx_222_2] = (stage_v_222_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int s_idx_223_1 = sec_r000949_2_1 & 3;
  int s_idx_223_2 = sec_r000949_2_2 & 3;
  int stage_v_223_1 = (table_1[s_idx_223_1] + pub_r000949_6_1) & 127;
  int stage_v_223_2 = (table_2[s_idx_223_2] + pub_r000949_6_2) & 127;
  table_1[s_idx_223_1] = (stage_v_223_1 + 7) & 63;
  table_2[s_idx_223_2] = (stage_v_223_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int s_idx_224_1 = stage_v_164_1 & 3;
  int s_idx_224_2 = stage_v_164_2 & 3;
  int stage_v_224_1 = (table_1[s_idx_224_1] + pub_r000949_20_1) & 127;
  int stage_v_224_2 = (table_2[s_idx_224_2] + pub_r000949_20_2) & 127;
  table_1[s_idx_224_1] = (stage_v_224_1 + 7) & 63;
  table_2[s_idx_224_2] = (stage_v_224_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int s_idx_225_1 = stage_v_35_1 & 3;
  int s_idx_225_2 = stage_v_35_2 & 3;
  int stage_v_225_1 = (table_1[s_idx_225_1] + pub_r000949_4_1) & 127;
  int stage_v_225_2 = (table_2[s_idx_225_2] + pub_r000949_4_2) & 127;
  table_1[s_idx_225_1] = (stage_v_225_1 + 7) & 63;
  table_2[s_idx_225_2] = (stage_v_225_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int s_idx_226_1 = sec_r000949_5_1 & 3;
  int s_idx_226_2 = sec_r000949_5_2 & 3;
  int stage_v_226_1 = (table_1[s_idx_226_1] + pub_r000949_9_1) & 127;
  int stage_v_226_2 = (table_2[s_idx_226_2] + pub_r000949_9_2) & 127;
  table_1[s_idx_226_1] = (stage_v_226_1 + 7) & 63;
  table_2[s_idx_226_2] = (stage_v_226_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int s_idx_227_1 = sec_r000949_13_1 & 3;
  int s_idx_227_2 = sec_r000949_13_2 & 3;
  int stage_v_227_1 = (table_1[s_idx_227_1] + pub_r000949_3_1) & 127;
  int stage_v_227_2 = (table_2[s_idx_227_2] + pub_r000949_3_2) & 127;
  table_1[s_idx_227_1] = (stage_v_227_1 + 7) & 63;
  table_2[s_idx_227_2] = (stage_v_227_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000949_0_1 != sec_r000949_0_2);
  __CPROVER_assume(sec_r000949_5_1 != sec_r000949_5_2);
  __CPROVER_assume(pub_r000949_9_1 == pub_r000949_9_2);
  __CPROVER_assume(sec_r000949_9_1 != sec_r000949_9_2);
  __CPROVER_assume(sec_r000949_13_1 != sec_r000949_13_2);
  __CPROVER_assume(sec_r000949_11_1 != sec_r000949_11_2);
  __CPROVER_assume(pub_r000949_12_1 == pub_r000949_12_2);
  __CPROVER_assume(pub_r000949_3_1 == pub_r000949_3_2);
  __CPROVER_assume(sec_r000949_3_1 != sec_r000949_3_2);
  __CPROVER_assume(sec_r000949_1_1 != sec_r000949_1_2);
  __CPROVER_assume(pub_r000949_15_1 == pub_r000949_15_2);
  __CPROVER_assume(sec_r000949_14_1 != sec_r000949_14_2);
  __CPROVER_assume(pub_r000949_20_1 == pub_r000949_20_2);
  __CPROVER_assume(pub_r000949_4_1 == pub_r000949_4_2);
  __CPROVER_assume(sec_r000949_15_1 != sec_r000949_15_2);
  __CPROVER_assume(pub_r000949_16_1 == pub_r000949_16_2);
  __CPROVER_assume(sec_r000949_7_1 != sec_r000949_7_2);
  __CPROVER_assume(pub_r000949_17_1 == pub_r000949_17_2);
  __CPROVER_assume(sec_r000949_12_1 != sec_r000949_12_2);
  __CPROVER_assume(pub_r000949_14_1 == pub_r000949_14_2);
  __CPROVER_assume(pub_r000949_6_1 == pub_r000949_6_2);
  __CPROVER_assume(pub_r000949_1_1 == pub_r000949_1_2);
  __CPROVER_assume(pub_r000949_7_1 == pub_r000949_7_2);
  __CPROVER_assume(pub_r000949_18_1 == pub_r000949_18_2);
  __CPROVER_assume(sec_r000949_8_1 != sec_r000949_8_2);
  __CPROVER_assume(pub_r000949_11_1 == pub_r000949_11_2);
  __CPROVER_assume(sec_r000949_2_1 != sec_r000949_2_2);
  __CPROVER_assume(pub_r000949_2_1 == pub_r000949_2_2);
  __CPROVER_assume(sec_r000949_4_1 != sec_r000949_4_2);
  __CPROVER_assume(pub_r000949_13_1 == pub_r000949_13_2);
  __CPROVER_assume(pub_r000949_5_1 == pub_r000949_5_2);
  __CPROVER_assume(pub_r000949_8_1 == pub_r000949_8_2);
  __CPROVER_assume(sec_r000949_6_1 != sec_r000949_6_2);
  __CPROVER_assume(pub_r000949_10_1 == pub_r000949_10_2);
  __CPROVER_assume(sec_r000949_10_1 != sec_r000949_10_2);
  __CPROVER_assume(pub_r000949_19_1 == pub_r000949_19_2);
  __CPROVER_assume(pub_r000949_0_1 == pub_r000949_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.status == st_var_0_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  assert(st_var_2_1.port == st_var_2_2.port);
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
  assert(s_idx_19_1 == s_idx_19_2);
  assert(stage_v_19_1 == stage_v_19_2);
  assert(s_idx_20_1 == s_idx_20_2);
  assert(stage_v_20_1 == stage_v_20_2);
  assert(s_idx_21_1 == s_idx_21_2);
  assert(stage_v_21_1 == stage_v_21_2);
  assert(s_idx_22_1 == s_idx_22_2);
  assert(stage_v_22_1 == stage_v_22_2);
  assert(s_idx_23_1 == s_idx_23_2);
  assert(stage_v_23_1 == stage_v_23_2);
  assert(s_idx_24_1 == s_idx_24_2);
  assert(stage_v_24_1 == stage_v_24_2);
  assert(s_idx_25_1 == s_idx_25_2);
  assert(stage_v_25_1 == stage_v_25_2);
  assert(s_idx_26_1 == s_idx_26_2);
  assert(stage_v_26_1 == stage_v_26_2);
  assert(s_idx_27_1 == s_idx_27_2);
  assert(stage_v_27_1 == stage_v_27_2);
  assert(s_idx_28_1 == s_idx_28_2);
  assert(stage_v_28_1 == stage_v_28_2);
  assert(s_idx_29_1 == s_idx_29_2);
  assert(stage_v_29_1 == stage_v_29_2);
  assert(s_idx_30_1 == s_idx_30_2);
  assert(stage_v_30_1 == stage_v_30_2);
  assert(s_idx_31_1 == s_idx_31_2);
  assert(stage_v_31_1 == stage_v_31_2);
  assert(s_idx_32_1 == s_idx_32_2);
  assert(stage_v_32_1 == stage_v_32_2);
  assert(s_idx_33_1 == s_idx_33_2);
  assert(stage_v_33_1 == stage_v_33_2);
  assert(s_idx_34_1 == s_idx_34_2);
  assert(stage_v_34_1 == stage_v_34_2);
  assert(s_idx_35_1 == s_idx_35_2);
  assert(stage_v_35_1 == stage_v_35_2);
  assert(s_idx_36_1 == s_idx_36_2);
  assert(stage_v_36_1 == stage_v_36_2);
  assert(s_idx_37_1 == s_idx_37_2);
  assert(stage_v_37_1 == stage_v_37_2);
  assert(s_idx_38_1 == s_idx_38_2);
  assert(stage_v_38_1 == stage_v_38_2);
  assert(s_idx_39_1 == s_idx_39_2);
  assert(stage_v_39_1 == stage_v_39_2);
  assert(s_idx_40_1 == s_idx_40_2);
  assert(stage_v_40_1 == stage_v_40_2);
  assert(s_idx_41_1 == s_idx_41_2);
  assert(stage_v_41_1 == stage_v_41_2);
  assert(s_idx_42_1 == s_idx_42_2);
  assert(stage_v_42_1 == stage_v_42_2);
  assert(s_idx_43_1 == s_idx_43_2);
  assert(stage_v_43_1 == stage_v_43_2);
  assert(s_idx_44_1 == s_idx_44_2);
  assert(stage_v_44_1 == stage_v_44_2);
  assert(s_idx_45_1 == s_idx_45_2);
  assert(stage_v_45_1 == stage_v_45_2);
  assert(s_idx_46_1 == s_idx_46_2);
  assert(stage_v_46_1 == stage_v_46_2);
  assert(s_idx_47_1 == s_idx_47_2);
  assert(stage_v_47_1 == stage_v_47_2);
  assert(s_idx_48_1 == s_idx_48_2);
  assert(stage_v_48_1 == stage_v_48_2);
  assert(s_idx_49_1 == s_idx_49_2);
  assert(stage_v_49_1 == stage_v_49_2);
  assert(s_idx_50_1 == s_idx_50_2);
  assert(stage_v_50_1 == stage_v_50_2);
  assert(s_idx_51_1 == s_idx_51_2);
  assert(stage_v_51_1 == stage_v_51_2);
  assert(s_idx_52_1 == s_idx_52_2);
  assert(stage_v_52_1 == stage_v_52_2);
  assert(s_idx_53_1 == s_idx_53_2);
  assert(stage_v_53_1 == stage_v_53_2);
  assert(s_idx_54_1 == s_idx_54_2);
  assert(stage_v_54_1 == stage_v_54_2);
  assert(s_idx_55_1 == s_idx_55_2);
  assert(stage_v_55_1 == stage_v_55_2);
  assert(s_idx_56_1 == s_idx_56_2);
  assert(stage_v_56_1 == stage_v_56_2);
  assert(s_idx_57_1 == s_idx_57_2);
  assert(stage_v_57_1 == stage_v_57_2);
  assert(s_idx_58_1 == s_idx_58_2);
  assert(stage_v_58_1 == stage_v_58_2);
  assert(s_idx_59_1 == s_idx_59_2);
  assert(stage_v_59_1 == stage_v_59_2);
  assert(s_idx_60_1 == s_idx_60_2);
  assert(stage_v_60_1 == stage_v_60_2);
  assert(s_idx_61_1 == s_idx_61_2);
  assert(stage_v_61_1 == stage_v_61_2);
  assert(s_idx_62_1 == s_idx_62_2);
  assert(stage_v_62_1 == stage_v_62_2);
  assert(s_idx_63_1 == s_idx_63_2);
  assert(stage_v_63_1 == stage_v_63_2);
  assert(s_idx_64_1 == s_idx_64_2);
  assert(stage_v_64_1 == stage_v_64_2);
  assert(s_idx_65_1 == s_idx_65_2);
  assert(stage_v_65_1 == stage_v_65_2);
  assert(s_idx_66_1 == s_idx_66_2);
  assert(stage_v_66_1 == stage_v_66_2);
  assert(s_idx_67_1 == s_idx_67_2);
  assert(stage_v_67_1 == stage_v_67_2);
  assert(s_idx_68_1 == s_idx_68_2);
  assert(stage_v_68_1 == stage_v_68_2);
  assert(s_idx_69_1 == s_idx_69_2);
  assert(stage_v_69_1 == stage_v_69_2);
  assert(s_idx_70_1 == s_idx_70_2);
  assert(stage_v_70_1 == stage_v_70_2);
  assert(s_idx_71_1 == s_idx_71_2);
  assert(stage_v_71_1 == stage_v_71_2);
  assert(s_idx_72_1 == s_idx_72_2);
  assert(stage_v_72_1 == stage_v_72_2);
  assert(s_idx_73_1 == s_idx_73_2);
  assert(stage_v_73_1 == stage_v_73_2);
  assert(s_idx_74_1 == s_idx_74_2);
  assert(stage_v_74_1 == stage_v_74_2);
  assert(s_idx_75_1 == s_idx_75_2);
  assert(stage_v_75_1 == stage_v_75_2);
  assert(s_idx_76_1 == s_idx_76_2);
  assert(stage_v_76_1 == stage_v_76_2);
  assert(s_idx_77_1 == s_idx_77_2);
  assert(stage_v_77_1 == stage_v_77_2);
  assert(s_idx_78_1 == s_idx_78_2);
  assert(stage_v_78_1 == stage_v_78_2);
  assert(s_idx_79_1 == s_idx_79_2);
  assert(stage_v_79_1 == stage_v_79_2);
  assert(s_idx_80_1 == s_idx_80_2);
  assert(stage_v_80_1 == stage_v_80_2);
  assert(s_idx_81_1 == s_idx_81_2);
  assert(stage_v_81_1 == stage_v_81_2);
  assert(s_idx_82_1 == s_idx_82_2);
  assert(stage_v_82_1 == stage_v_82_2);
  assert(s_idx_83_1 == s_idx_83_2);
  assert(stage_v_83_1 == stage_v_83_2);
  assert(s_idx_84_1 == s_idx_84_2);
  assert(stage_v_84_1 == stage_v_84_2);
  assert(s_idx_85_1 == s_idx_85_2);
  assert(stage_v_85_1 == stage_v_85_2);
  assert(s_idx_86_1 == s_idx_86_2);
  assert(stage_v_86_1 == stage_v_86_2);
  assert(s_idx_87_1 == s_idx_87_2);
  assert(stage_v_87_1 == stage_v_87_2);
  assert(s_idx_88_1 == s_idx_88_2);
  assert(stage_v_88_1 == stage_v_88_2);
  assert(s_idx_89_1 == s_idx_89_2);
  assert(stage_v_89_1 == stage_v_89_2);
  assert(s_idx_90_1 == s_idx_90_2);
  assert(stage_v_90_1 == stage_v_90_2);
  assert(s_idx_91_1 == s_idx_91_2);
  assert(stage_v_91_1 == stage_v_91_2);
  assert(s_idx_92_1 == s_idx_92_2);
  assert(stage_v_92_1 == stage_v_92_2);
  assert(s_idx_93_1 == s_idx_93_2);
  assert(stage_v_93_1 == stage_v_93_2);
  assert(s_idx_94_1 == s_idx_94_2);
  assert(stage_v_94_1 == stage_v_94_2);
  assert(s_idx_95_1 == s_idx_95_2);
  assert(stage_v_95_1 == stage_v_95_2);
  assert(s_idx_96_1 == s_idx_96_2);
  assert(stage_v_96_1 == stage_v_96_2);
  assert(s_idx_97_1 == s_idx_97_2);
  assert(stage_v_97_1 == stage_v_97_2);
  assert(s_idx_98_1 == s_idx_98_2);
  assert(stage_v_98_1 == stage_v_98_2);
  assert(s_idx_99_1 == s_idx_99_2);
  assert(stage_v_99_1 == stage_v_99_2);
  assert(s_idx_100_1 == s_idx_100_2);
  assert(stage_v_100_1 == stage_v_100_2);
  assert(s_idx_101_1 == s_idx_101_2);
  assert(stage_v_101_1 == stage_v_101_2);
  assert(s_idx_102_1 == s_idx_102_2);
  assert(stage_v_102_1 == stage_v_102_2);
  assert(s_idx_103_1 == s_idx_103_2);
  assert(stage_v_103_1 == stage_v_103_2);
  assert(s_idx_104_1 == s_idx_104_2);
  assert(stage_v_104_1 == stage_v_104_2);
  assert(s_idx_105_1 == s_idx_105_2);
  assert(stage_v_105_1 == stage_v_105_2);
  assert(s_idx_106_1 == s_idx_106_2);
  assert(stage_v_106_1 == stage_v_106_2);
  assert(s_idx_107_1 == s_idx_107_2);
  assert(stage_v_107_1 == stage_v_107_2);
  assert(s_idx_108_1 == s_idx_108_2);
  assert(stage_v_108_1 == stage_v_108_2);
  assert(s_idx_109_1 == s_idx_109_2);
  assert(stage_v_109_1 == stage_v_109_2);
  assert(s_idx_110_1 == s_idx_110_2);
  assert(stage_v_110_1 == stage_v_110_2);
  assert(s_idx_111_1 == s_idx_111_2);
  assert(stage_v_111_1 == stage_v_111_2);
  assert(s_idx_112_1 == s_idx_112_2);
  assert(stage_v_112_1 == stage_v_112_2);
  assert(s_idx_113_1 == s_idx_113_2);
  assert(stage_v_113_1 == stage_v_113_2);
  assert(s_idx_114_1 == s_idx_114_2);
  assert(stage_v_114_1 == stage_v_114_2);
  assert(s_idx_115_1 == s_idx_115_2);
  assert(stage_v_115_1 == stage_v_115_2);
  assert(s_idx_116_1 == s_idx_116_2);
  assert(stage_v_116_1 == stage_v_116_2);
  assert(s_idx_117_1 == s_idx_117_2);
  assert(stage_v_117_1 == stage_v_117_2);
  assert(s_idx_118_1 == s_idx_118_2);
  assert(stage_v_118_1 == stage_v_118_2);
  assert(s_idx_119_1 == s_idx_119_2);
  assert(stage_v_119_1 == stage_v_119_2);
  assert(s_idx_120_1 == s_idx_120_2);
  assert(stage_v_120_1 == stage_v_120_2);
  assert(s_idx_121_1 == s_idx_121_2);
  assert(stage_v_121_1 == stage_v_121_2);
  assert(s_idx_122_1 == s_idx_122_2);
  assert(stage_v_122_1 == stage_v_122_2);
  assert(s_idx_123_1 == s_idx_123_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(s_idx_124_1 == s_idx_124_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(s_idx_125_1 == s_idx_125_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(s_idx_126_1 == s_idx_126_2);
  assert(stage_v_126_1 == stage_v_126_2);
  assert(s_idx_127_1 == s_idx_127_2);
  assert(stage_v_127_1 == stage_v_127_2);
  assert(s_idx_128_1 == s_idx_128_2);
  assert(stage_v_128_1 == stage_v_128_2);
  assert(s_idx_129_1 == s_idx_129_2);
  assert(stage_v_129_1 == stage_v_129_2);
  assert(s_idx_130_1 == s_idx_130_2);
  assert(stage_v_130_1 == stage_v_130_2);
  assert(s_idx_131_1 == s_idx_131_2);
  assert(stage_v_131_1 == stage_v_131_2);
  assert(s_idx_132_1 == s_idx_132_2);
  assert(stage_v_132_1 == stage_v_132_2);
  assert(s_idx_133_1 == s_idx_133_2);
  assert(stage_v_133_1 == stage_v_133_2);
  assert(s_idx_134_1 == s_idx_134_2);
  assert(stage_v_134_1 == stage_v_134_2);
  assert(s_idx_135_1 == s_idx_135_2);
  assert(stage_v_135_1 == stage_v_135_2);
  assert(s_idx_136_1 == s_idx_136_2);
  assert(stage_v_136_1 == stage_v_136_2);
  assert(s_idx_137_1 == s_idx_137_2);
  assert(stage_v_137_1 == stage_v_137_2);
  assert(s_idx_138_1 == s_idx_138_2);
  assert(stage_v_138_1 == stage_v_138_2);
  assert(s_idx_139_1 == s_idx_139_2);
  assert(stage_v_139_1 == stage_v_139_2);
  assert(s_idx_140_1 == s_idx_140_2);
  assert(stage_v_140_1 == stage_v_140_2);
  assert(s_idx_141_1 == s_idx_141_2);
  assert(stage_v_141_1 == stage_v_141_2);
  assert(s_idx_142_1 == s_idx_142_2);
  assert(stage_v_142_1 == stage_v_142_2);
  assert(s_idx_143_1 == s_idx_143_2);
  assert(stage_v_143_1 == stage_v_143_2);
  assert(s_idx_144_1 == s_idx_144_2);
  assert(stage_v_144_1 == stage_v_144_2);
  assert(s_idx_145_1 == s_idx_145_2);
  assert(stage_v_145_1 == stage_v_145_2);
  assert(s_idx_146_1 == s_idx_146_2);
  assert(stage_v_146_1 == stage_v_146_2);
  assert(s_idx_147_1 == s_idx_147_2);
  assert(stage_v_147_1 == stage_v_147_2);
  assert(s_idx_148_1 == s_idx_148_2);
  assert(stage_v_148_1 == stage_v_148_2);
  assert(s_idx_149_1 == s_idx_149_2);
  assert(stage_v_149_1 == stage_v_149_2);
  assert(s_idx_150_1 == s_idx_150_2);
  assert(stage_v_150_1 == stage_v_150_2);
  assert(s_idx_151_1 == s_idx_151_2);
  assert(stage_v_151_1 == stage_v_151_2);
  assert(s_idx_152_1 == s_idx_152_2);
  assert(stage_v_152_1 == stage_v_152_2);
  assert(s_idx_153_1 == s_idx_153_2);
  assert(stage_v_153_1 == stage_v_153_2);
  assert(s_idx_154_1 == s_idx_154_2);
  assert(stage_v_154_1 == stage_v_154_2);
  assert(s_idx_155_1 == s_idx_155_2);
  assert(stage_v_155_1 == stage_v_155_2);
  assert(s_idx_156_1 == s_idx_156_2);
  assert(stage_v_156_1 == stage_v_156_2);
  assert(s_idx_157_1 == s_idx_157_2);
  assert(stage_v_157_1 == stage_v_157_2);
  assert(s_idx_158_1 == s_idx_158_2);
  assert(stage_v_158_1 == stage_v_158_2);
  assert(s_idx_159_1 == s_idx_159_2);
  assert(stage_v_159_1 == stage_v_159_2);
  assert(s_idx_160_1 == s_idx_160_2);
  assert(stage_v_160_1 == stage_v_160_2);
  assert(s_idx_161_1 == s_idx_161_2);
  assert(stage_v_161_1 == stage_v_161_2);
  assert(s_idx_162_1 == s_idx_162_2);
  assert(stage_v_162_1 == stage_v_162_2);
  assert(s_idx_163_1 == s_idx_163_2);
  assert(stage_v_163_1 == stage_v_163_2);
  assert(s_idx_164_1 == s_idx_164_2);
  assert(stage_v_164_1 == stage_v_164_2);
  assert(s_idx_165_1 == s_idx_165_2);
  assert(stage_v_165_1 == stage_v_165_2);
  assert(s_idx_166_1 == s_idx_166_2);
  assert(stage_v_166_1 == stage_v_166_2);
  assert(s_idx_167_1 == s_idx_167_2);
  assert(stage_v_167_1 == stage_v_167_2);
  assert(s_idx_168_1 == s_idx_168_2);
  assert(stage_v_168_1 == stage_v_168_2);
  assert(s_idx_169_1 == s_idx_169_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(s_idx_170_1 == s_idx_170_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(s_idx_171_1 == s_idx_171_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(s_idx_172_1 == s_idx_172_2);
  assert(stage_v_172_1 == stage_v_172_2);
  assert(s_idx_173_1 == s_idx_173_2);
  assert(stage_v_173_1 == stage_v_173_2);
  assert(s_idx_174_1 == s_idx_174_2);
  assert(stage_v_174_1 == stage_v_174_2);
  assert(s_idx_175_1 == s_idx_175_2);
  assert(stage_v_175_1 == stage_v_175_2);
  assert(s_idx_176_1 == s_idx_176_2);
  assert(stage_v_176_1 == stage_v_176_2);
  assert(s_idx_177_1 == s_idx_177_2);
  assert(stage_v_177_1 == stage_v_177_2);
  assert(s_idx_178_1 == s_idx_178_2);
  assert(stage_v_178_1 == stage_v_178_2);
  assert(s_idx_179_1 == s_idx_179_2);
  assert(stage_v_179_1 == stage_v_179_2);
  assert(s_idx_180_1 == s_idx_180_2);
  assert(stage_v_180_1 == stage_v_180_2);
  assert(s_idx_181_1 == s_idx_181_2);
  assert(stage_v_181_1 == stage_v_181_2);
  assert(s_idx_182_1 == s_idx_182_2);
  assert(stage_v_182_1 == stage_v_182_2);
  assert(s_idx_183_1 == s_idx_183_2);
  assert(stage_v_183_1 == stage_v_183_2);
  assert(s_idx_184_1 == s_idx_184_2);
  assert(stage_v_184_1 == stage_v_184_2);
  assert(s_idx_185_1 == s_idx_185_2);
  assert(stage_v_185_1 == stage_v_185_2);
  assert(s_idx_186_1 == s_idx_186_2);
  assert(stage_v_186_1 == stage_v_186_2);
  assert(s_idx_187_1 == s_idx_187_2);
  assert(stage_v_187_1 == stage_v_187_2);
  assert(s_idx_188_1 == s_idx_188_2);
  assert(stage_v_188_1 == stage_v_188_2);
  assert(s_idx_189_1 == s_idx_189_2);
  assert(stage_v_189_1 == stage_v_189_2);
  assert(s_idx_190_1 == s_idx_190_2);
  assert(stage_v_190_1 == stage_v_190_2);
  assert(s_idx_191_1 == s_idx_191_2);
  assert(stage_v_191_1 == stage_v_191_2);
  assert(s_idx_192_1 == s_idx_192_2);
  assert(stage_v_192_1 == stage_v_192_2);
  assert(s_idx_193_1 == s_idx_193_2);
  assert(stage_v_193_1 == stage_v_193_2);
  assert(s_idx_194_1 == s_idx_194_2);
  assert(stage_v_194_1 == stage_v_194_2);
  assert(s_idx_195_1 == s_idx_195_2);
  assert(stage_v_195_1 == stage_v_195_2);
  assert(s_idx_196_1 == s_idx_196_2);
  assert(stage_v_196_1 == stage_v_196_2);
  assert(s_idx_197_1 == s_idx_197_2);
  assert(stage_v_197_1 == stage_v_197_2);
  assert(s_idx_198_1 == s_idx_198_2);
  assert(stage_v_198_1 == stage_v_198_2);
  assert(s_idx_199_1 == s_idx_199_2);
  assert(stage_v_199_1 == stage_v_199_2);
  assert(s_idx_200_1 == s_idx_200_2);
  assert(stage_v_200_1 == stage_v_200_2);
  assert(s_idx_201_1 == s_idx_201_2);
  assert(stage_v_201_1 == stage_v_201_2);
  assert(s_idx_202_1 == s_idx_202_2);
  assert(stage_v_202_1 == stage_v_202_2);
  assert(s_idx_203_1 == s_idx_203_2);
  assert(stage_v_203_1 == stage_v_203_2);
  assert(s_idx_204_1 == s_idx_204_2);
  assert(stage_v_204_1 == stage_v_204_2);
  assert(s_idx_205_1 == s_idx_205_2);
  assert(stage_v_205_1 == stage_v_205_2);
  assert(s_idx_206_1 == s_idx_206_2);
  assert(stage_v_206_1 == stage_v_206_2);
  assert(s_idx_207_1 == s_idx_207_2);
  assert(stage_v_207_1 == stage_v_207_2);
  assert(s_idx_208_1 == s_idx_208_2);
  assert(stage_v_208_1 == stage_v_208_2);
  assert(s_idx_209_1 == s_idx_209_2);
  assert(stage_v_209_1 == stage_v_209_2);
  assert(s_idx_210_1 == s_idx_210_2);
  assert(stage_v_210_1 == stage_v_210_2);
  assert(s_idx_211_1 == s_idx_211_2);
  assert(stage_v_211_1 == stage_v_211_2);
  assert(s_idx_212_1 == s_idx_212_2);
  assert(stage_v_212_1 == stage_v_212_2);
  assert(s_idx_213_1 == s_idx_213_2);
  assert(stage_v_213_1 == stage_v_213_2);
  assert(s_idx_214_1 == s_idx_214_2);
  assert(stage_v_214_1 == stage_v_214_2);
  assert(s_idx_215_1 == s_idx_215_2);
  assert(stage_v_215_1 == stage_v_215_2);
  assert(s_idx_216_1 == s_idx_216_2);
  assert(stage_v_216_1 == stage_v_216_2);
  assert(s_idx_217_1 == s_idx_217_2);
  assert(stage_v_217_1 == stage_v_217_2);
  assert(s_idx_218_1 == s_idx_218_2);
  assert(stage_v_218_1 == stage_v_218_2);
  assert(s_idx_219_1 == s_idx_219_2);
  assert(stage_v_219_1 == stage_v_219_2);
  assert(s_idx_220_1 == s_idx_220_2);
  assert(stage_v_220_1 == stage_v_220_2);
  assert(s_idx_221_1 == s_idx_221_2);
  assert(stage_v_221_1 == stage_v_221_2);
  assert(s_idx_222_1 == s_idx_222_2);
  assert(stage_v_222_1 == stage_v_222_2);
  assert(s_idx_223_1 == s_idx_223_2);
  assert(stage_v_223_1 == stage_v_223_2);
  assert(s_idx_224_1 == s_idx_224_2);
  assert(stage_v_224_1 == stage_v_224_2);
  assert(s_idx_225_1 == s_idx_225_2);
  assert(stage_v_225_1 == stage_v_225_2);
  assert(s_idx_226_1 == s_idx_226_2);
  assert(stage_v_226_1 == stage_v_226_2);
  assert(s_idx_227_1 == s_idx_227_2);
  assert(stage_v_227_1 == stage_v_227_2);
}


