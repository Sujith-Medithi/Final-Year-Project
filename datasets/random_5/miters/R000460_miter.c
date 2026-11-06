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
struct Transaction_R000460_6013_0
{
  short balance;
  unsigned char auth_code;
  int status;
  int account_id;
  unsigned char fee;
  unsigned char rate;
  int buffer[3];
};
struct DeviceConfig_R000460_6013_1
{
  int parity;
  short id;
  short port;
  int timeout;
  int baud_rate;
  short stop_bits;
  int buffer[3];
};
struct FilterState_R000460_6013_2
{
  short gain_db;
  unsigned char damping;
  int cutoff;
  short mode;
  int prev_out;
  int buffer[3];
};
struct AudioFrame_R000460_6013_3
{
  unsigned char rms;
  int gain;
  int envelope;
  int channels;
  int peak;
  int buffer[3];
};
union PacketPayload_R000460_6013_0
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
void fn_R000460_6013_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st_1 = {0};
  struct Transaction_R000460_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int checksum_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_67_1)
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

  switch (checksum_67_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_38_1 = local_arr_1[aux_1 % 3];
  int offset_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_38_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_67_1 == checksum_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_38_1 == offset_38_2);
}

int fn_R000460_6013_0(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int checksum_67 = (aux + st.buffer[1]) & 3;
  switch (checksum_67)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_38 = local_arr[aux % 3];
  acc = (acc + (offset_38 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000460_6013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000460_6013_1 st_1 = {0};
  struct DeviceConfig_R000460_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int anchor_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_99_1) & 63;
  aux_2 = (aux_2 + anchor_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_91_1 = local_arr_1[aux_1 % 3];
  int segment_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_91_2 * 2)) & 127;
  int phase_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_12_1)
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

  switch (phase_12_2)
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
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_99_1 == anchor_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_91_1 == segment_91_2);
  assert(phase_12_1 == phase_12_2);
}

int fn_R000460_6013_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000460_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int anchor_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_99) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int segment_91 = local_arr[aux % 3];
  acc = (acc + (segment_91 * 2)) & 127;
  int phase_12 = (aux + st.buffer[1]) & 3;
  switch (phase_12)
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

void fn_R000460_6013_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st_1 = {0};
  struct Transaction_R000460_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int cursor_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_12_1 > 38)
  {
    acc_1 = ((acc_1 + (cursor_12_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_12_2 > 38)
  {
    acc_2 = ((acc_2 + (cursor_12_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_50_1) & 63;
  aux_2 = (aux_2 + index_reg_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_74_1)
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

  switch (parity_74_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_12_1 == cursor_12_2);
  assert(index_reg_50_1 == index_reg_50_2);
  assert(parity_74_1 == parity_74_2);
}

int fn_R000460_6013_2(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int cursor_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_12 > 38)
  {
    acc = ((acc + (cursor_12 * 2)) + 5) & 127;
    aux ^= cursor_12 & 15;
  }
  else
  {
    acc = ((acc - cursor_12) + 11) & 127;
    aux += 3;
  }
  int index_reg_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_50) & 63;
  acc ^= aux;
  int parity_74 = (aux + st.buffer[1]) & 3;
  switch (parity_74)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000460_6013_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000460_6013_2 st_1 = {0};
  struct FilterState_R000460_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int delta_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_72_1) & 63;
  aux_2 = (aux_2 + delta_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_48_1)
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

  switch (bound_48_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_72_1 == delta_72_2);
  assert(bound_48_1 == bound_48_2);
}

int fn_R000460_6013_3(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000460_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int delta_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_72) & 63;
  acc ^= aux;
  int bound_48 = (aux + st.buffer[1]) & 3;
  switch (bound_48)
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

void fn_R000460_6013_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st_1 = {0};
  struct Transaction_R000460_6013_0 st_2 = {0};
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
  int margin_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_16_1)
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

  switch (margin_16_2)
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
  int phase_16_1 = local_arr_1[aux_1 % 3];
  int phase_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_16_2 * 2)) & 127;
  int cursor_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_89_1) & 63;
  aux_2 = (aux_2 + cursor_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_16_1 == margin_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_16_1 == phase_16_2);
  assert(cursor_89_1 == cursor_89_2);
}

int fn_R000460_6013_4(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_16 = (aux + st.buffer[1]) & 3;
  switch (margin_16)
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
  int phase_16 = local_arr[aux % 3];
  acc = (acc + (phase_16 * 2)) & 127;
  int cursor_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_89) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000460_6013_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000460_6013_2 st_1 = {0};
  struct FilterState_R000460_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int weight_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_96_1 > 19)
  {
    acc_1 = ((acc_1 + (weight_96_1 * 2)) + 5) & 127;
    aux_1 ^= weight_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_96_2 > 19)
  {
    acc_2 = ((acc_2 + (weight_96_2 * 2)) + 5) & 127;
    aux_2 ^= weight_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_36_1 = local_arr_1[aux_1 % 3];
  int tally_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_96_1 == weight_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_36_1 == tally_36_2);
}

int fn_R000460_6013_5(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000460_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int weight_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_96 > 19)
  {
    acc = ((acc + (weight_96 * 2)) + 5) & 127;
    aux ^= weight_96 & 15;
  }
  else
  {
    acc = ((acc - weight_96) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_36 = local_arr[aux % 3];
  acc = (acc + (tally_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000460_6013_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000460_6013_2 st_1 = {0};
  struct FilterState_R000460_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int delta_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_55_1)
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

  switch (delta_55_2)
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
  int cursor_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_62_1 > 19)
  {
    acc_1 = ((acc_1 + (cursor_62_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_62_2 > 19)
  {
    acc_2 = ((acc_2 + (cursor_62_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_98_1) & 63;
  aux_2 = (aux_2 + tally_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_55_1 == delta_55_2);
  assert(cursor_62_1 == cursor_62_2);
  assert(tally_98_1 == tally_98_2);
}

int fn_R000460_6013_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000460_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int delta_55 = (aux + st.buffer[1]) & 3;
  switch (delta_55)
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
  int cursor_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_62 > 19)
  {
    acc = ((acc + (cursor_62 * 2)) + 5) & 127;
    aux ^= cursor_62 & 15;
  }
  else
  {
    acc = ((acc - cursor_62) + 11) & 127;
    aux += 3;
  }
  int tally_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_98) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000460_6013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st_1 = {0};
  struct Transaction_R000460_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int cursor_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_69_1)
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

  switch (cursor_69_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_84_1) & 63;
  aux_2 = (aux_2 + window_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_69_1 == cursor_69_2);
  assert(window_84_1 == window_84_2);
}

int fn_R000460_6013_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int cursor_69 = (aux + st.buffer[1]) & 3;
  switch (cursor_69)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000460_6013_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000460_6013_2 st_1 = {0};
  struct FilterState_R000460_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int parity_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_97_1 > 22)
  {
    acc_1 = ((acc_1 + (parity_97_1 * 2)) + 5) & 127;
    aux_1 ^= parity_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_97_2 > 22)
  {
    acc_2 = ((acc_2 + (parity_97_2 * 2)) + 5) & 127;
    aux_2 ^= parity_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_18_1 = local_arr_1[aux_1 % 3];
  int segment_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_18_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_97_1 == parity_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_18_1 == segment_18_2);
}

int fn_R000460_6013_8(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000460_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int parity_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_97 > 22)
  {
    acc = ((acc + (parity_97 * 2)) + 5) & 127;
    aux ^= parity_97 & 15;
  }
  else
  {
    acc = ((acc - parity_97) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_18 = local_arr[aux % 3];
  acc = (acc + (segment_18 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000460_6013_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000460_6013_3 st_1 = {0};
  struct AudioFrame_R000460_6013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int coefficient_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_78_1 > 44)
  {
    acc_1 = ((acc_1 + (coefficient_78_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_78_2 > 44)
  {
    acc_2 = ((acc_2 + (coefficient_78_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_78_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_38_1 = local_arr_1[aux_1 % 3];
  int scale_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_38_2 * 2)) & 127;
  int tracker_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_74_1) & 63;
  aux_2 = (aux_2 + tracker_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_78_1 == coefficient_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_38_1 == scale_38_2);
  assert(tracker_74_1 == tracker_74_2);
}

int fn_R000460_6013_9(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000460_6013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int coefficient_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_78 > 44)
  {
    acc = ((acc + (coefficient_78 * 2)) + 5) & 127;
    aux ^= coefficient_78 & 15;
  }
  else
  {
    acc = ((acc - coefficient_78) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_38 = local_arr[aux % 3];
  acc = (acc + (scale_38 * 2)) & 127;
  int tracker_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_74) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000460_6013_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st_1 = {0};
  struct Transaction_R000460_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int checksum_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_73_1 > 34)
  {
    acc_1 = ((acc_1 + (checksum_73_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_73_2 > 34)
  {
    acc_2 = ((acc_2 + (checksum_73_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_50_1)
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

  switch (damping_50_2)
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

  int margin_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_46_1) & 63;
  aux_2 = (aux_2 + margin_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_73_1 == checksum_73_2);
  assert(damping_50_1 == damping_50_2);
  assert(margin_46_1 == margin_46_2);
}

int fn_R000460_6013_10(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int checksum_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_73 > 34)
  {
    acc = ((acc + (checksum_73 * 2)) + 5) & 127;
    aux ^= checksum_73 & 15;
  }
  else
  {
    acc = ((acc - checksum_73) + 11) & 127;
    aux += 3;
  }
  int damping_50 = (aux + st.buffer[1]) & 3;
  switch (damping_50)
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

  int margin_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_46) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000460_6013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000460_6013_3 st_1 = {0};
  struct AudioFrame_R000460_6013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_71_1 = local_arr_1[aux_1 % 3];
  int phase_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_71_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_87_1)
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

  switch (accumulator_87_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_71_1 == phase_71_2);
  assert(accumulator_87_1 == accumulator_87_2);
}

int fn_R000460_6013_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000460_6013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int phase_71 = local_arr[aux % 3];
  acc = (acc + (phase_71 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_87 = (aux + st.buffer[1]) & 3;
  switch (accumulator_87)
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

void fn_R000460_6013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000460_6013_2 st_1 = {0};
  struct FilterState_R000460_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int pivot_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_73_1 > 49)
  {
    acc_1 = ((acc_1 + (pivot_73_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_73_2 > 49)
  {
    acc_2 = ((acc_2 + (pivot_73_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_73_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_76_1)
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

  switch (mask_76_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_73_1 == pivot_73_2);
  assert(mask_76_1 == mask_76_2);
}

int fn_R000460_6013_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000460_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int pivot_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_73 > 49)
  {
    acc = ((acc + (pivot_73 * 2)) + 5) & 127;
    aux ^= pivot_73 & 15;
  }
  else
  {
    acc = ((acc - pivot_73) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_76 = (aux + st.buffer[1]) & 3;
  switch (mask_76)
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

void fn_R000460_6013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000460_6013_3 st_1 = {0};
  struct AudioFrame_R000460_6013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quotient_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_46_1 > 18)
  {
    acc_1 = ((acc_1 + (quotient_46_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_46_2 > 18)
  {
    acc_2 = ((acc_2 + (quotient_46_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_97_1 = local_arr_1[aux_1 % 3];
  int tally_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_97_2 * 2)) & 127;
  int pivot_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_51_1) & 63;
  aux_2 = (aux_2 + pivot_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_98_1)
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

  switch (threshold_98_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_46_1 == quotient_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_97_1 == tally_97_2);
  assert(pivot_51_1 == pivot_51_2);
  assert(threshold_98_1 == threshold_98_2);
}

int fn_R000460_6013_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000460_6013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quotient_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_46 > 18)
  {
    acc = ((acc + (quotient_46 * 2)) + 5) & 127;
    aux ^= quotient_46 & 15;
  }
  else
  {
    acc = ((acc - quotient_46) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_97 = local_arr[aux % 3];
  acc = (acc + (tally_97 * 2)) & 127;
  int pivot_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_51) & 63;
  acc ^= aux;
  int threshold_98 = (aux + st.buffer[1]) & 3;
  switch (threshold_98)
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

void fn_R000460_6013_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st_1 = {0};
  struct Transaction_R000460_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_81_1) & 63;
  aux_2 = (aux_2 + bound_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_53_1)
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

  switch (weight_53_2)
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
  int bound_96_1 = local_arr_1[aux_1 % 3];
  int bound_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_96_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_81_1 == bound_81_2);
  assert(weight_53_1 == weight_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_96_1 == bound_96_2);
}

int fn_R000460_6013_14(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_81) & 63;
  acc ^= aux;
  int weight_53 = (aux + st.buffer[1]) & 3;
  switch (weight_53)
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
  int bound_96 = local_arr[aux % 3];
  acc = (acc + (bound_96 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000460_6013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st_1 = {0};
  struct Transaction_R000460_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int scale_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_48_1) & 63;
  aux_2 = (aux_2 + scale_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_69_1 = local_arr_1[aux_1 % 3];
  int pivot_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_69_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_48_1 == scale_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_69_1 == pivot_69_2);
}

int fn_R000460_6013_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int scale_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_48) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_69 = local_arr[aux % 3];
  acc = (acc + (pivot_69 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000460_6013_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000460_6013_1 st_1 = {0};
  struct DeviceConfig_R000460_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quotient_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_89_1) & 63;
  aux_2 = (aux_2 + quotient_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_48_1 > 29)
  {
    acc_1 = ((acc_1 + (stride_48_1 * 2)) + 5) & 127;
    aux_1 ^= stride_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_48_2 > 29)
  {
    acc_2 = ((acc_2 + (stride_48_2 * 2)) + 5) & 127;
    aux_2 ^= stride_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_48_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_94_1 = local_arr_1[aux_1 % 3];
  int tally_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_94_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_89_1 == quotient_89_2);
  assert(stride_48_1 == stride_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_94_1 == tally_94_2);
}

int fn_R000460_6013_16(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000460_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quotient_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_89) & 63;
  acc ^= aux;
  int stride_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_48 > 29)
  {
    acc = ((acc + (stride_48 * 2)) + 5) & 127;
    aux ^= stride_48 & 15;
  }
  else
  {
    acc = ((acc - stride_48) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_94 = local_arr[aux % 3];
  acc = (acc + (tally_94 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000460_6013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000460_6013_1 st_1 = {0};
  struct DeviceConfig_R000460_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int cursor_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_65_1) & 63;
  aux_2 = (aux_2 + cursor_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_56_1 > 16)
  {
    acc_1 = ((acc_1 + (offset_56_1 * 2)) + 5) & 127;
    aux_1 ^= offset_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_56_2 > 16)
  {
    acc_2 = ((acc_2 + (offset_56_2 * 2)) + 5) & 127;
    aux_2 ^= offset_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_61_1 = local_arr_1[aux_1 % 3];
  int margin_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_61_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_65_1 == cursor_65_2);
  assert(offset_56_1 == offset_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_61_1 == margin_61_2);
}

int fn_R000460_6013_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000460_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int cursor_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_65) & 63;
  acc ^= aux;
  int offset_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_56 > 16)
  {
    acc = ((acc + (offset_56 * 2)) + 5) & 127;
    aux ^= offset_56 & 15;
  }
  else
  {
    acc = ((acc - offset_56) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_61 = local_arr[aux % 3];
  acc = (acc + (margin_61 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000460_6013_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st_1 = {0};
  struct Transaction_R000460_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_43_1 = local_arr_1[aux_1 % 3];
  int damping_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_43_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_43_1 == damping_43_2);
}

int fn_R000460_6013_18(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000460_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int damping_43 = local_arr[aux % 3];
  acc = (acc + (damping_43 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000460_6013_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000460_6013_3 st_1 = {0};
  struct AudioFrame_R000460_6013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int tracker_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_95_1 > 21)
  {
    acc_1 = ((acc_1 + (tracker_95_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_95_2 > 21)
  {
    acc_2 = ((acc_2 + (tracker_95_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_95_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_95_1 == tracker_95_2);
}

int fn_R000460_6013_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000460_6013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int tracker_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_95 > 21)
  {
    acc = ((acc + (tracker_95 * 2)) + 5) & 127;
    aux ^= tracker_95 & 15;
  }
  else
  {
    acc = ((acc - tracker_95) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000460_6013_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000460_6013_2 st_1 = {0};
  struct FilterState_R000460_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_95_1 = local_arr_1[aux_1 % 3];
  int bound_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_95_2 * 2)) & 127;
  int tracker_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_24_1 > 28)
  {
    acc_1 = ((acc_1 + (tracker_24_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_24_2 > 28)
  {
    acc_2 = ((acc_2 + (tracker_24_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_24_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_95_1 == bound_95_2);
  assert(tracker_24_1 == tracker_24_2);
}

int fn_R000460_6013_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000460_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int bound_95 = local_arr[aux % 3];
  acc = (acc + (bound_95 * 2)) & 127;
  int tracker_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_24 > 28)
  {
    acc = ((acc + (tracker_24 * 2)) + 5) & 127;
    aux ^= tracker_24 & 15;
  }
  else
  {
    acc = ((acc - tracker_24) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000460_6013_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000460_6013_1 st_1 = {0};
  struct DeviceConfig_R000460_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_21_1) & 63;
  aux_2 = (aux_2 + cursor_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_70_1 > 49)
  {
    acc_1 = ((acc_1 + (sample_70_1 * 2)) + 5) & 127;
    aux_1 ^= sample_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_70_2 > 49)
  {
    acc_2 = ((acc_2 + (sample_70_2 * 2)) + 5) & 127;
    aux_2 ^= sample_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_10_1 = local_arr_1[aux_1 % 3];
  int metric_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_10_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_21_1 == cursor_21_2);
  assert(sample_70_1 == sample_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_10_1 == metric_10_2);
}

int fn_R000460_6013_21(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000460_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_21) & 63;
  acc ^= aux;
  int sample_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_70 > 49)
  {
    acc = ((acc + (sample_70 * 2)) + 5) & 127;
    aux ^= sample_70 & 15;
  }
  else
  {
    acc = ((acc - sample_70) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_10 = local_arr[aux % 3];
  acc = (acc + (metric_10 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000460_0_1;
  int sec_r000460_0_2;
  int sec_r000460_1_1;
  int sec_r000460_1_2;
  int sec_r000460_2_1;
  int sec_r000460_2_2;
  int sec_r000460_3_1;
  int sec_r000460_3_2;
  int sec_r000460_4_1;
  int sec_r000460_4_2;
  int sec_r000460_5_1;
  int sec_r000460_5_2;
  int sec_r000460_6_1;
  int sec_r000460_6_2;
  int sec_r000460_7_1;
  int sec_r000460_7_2;
  int sec_r000460_8_1;
  int sec_r000460_8_2;
  int sec_r000460_9_1;
  int sec_r000460_9_2;
  int sec_r000460_10_1;
  int sec_r000460_10_2;
  int sec_r000460_11_1;
  int sec_r000460_11_2;
  int sec_r000460_12_1;
  int sec_r000460_12_2;
  int sec_r000460_13_1;
  int sec_r000460_13_2;
  int sec_r000460_14_1;
  int sec_r000460_14_2;
  int sec_r000460_15_1;
  int sec_r000460_15_2;
  int pub_r000460_0_1;
  int pub_r000460_0_2;
  int pub_r000460_1_1;
  int pub_r000460_1_2;
  int pub_r000460_2_1;
  int pub_r000460_2_2;
  int pub_r000460_3_1;
  int pub_r000460_3_2;
  int pub_r000460_4_1;
  int pub_r000460_4_2;
  int pub_r000460_5_1;
  int pub_r000460_5_2;
  int pub_r000460_6_1;
  int pub_r000460_6_2;
  int pub_r000460_7_1;
  int pub_r000460_7_2;
  int pub_r000460_8_1;
  int pub_r000460_8_2;
  int pub_r000460_9_1;
  int pub_r000460_9_2;
  int pub_r000460_10_1;
  int pub_r000460_10_2;
  int pub_r000460_11_1;
  int pub_r000460_11_2;
  int pub_r000460_12_1;
  int pub_r000460_12_2;
  int pub_r000460_13_1;
  int pub_r000460_13_2;
  int pub_r000460_14_1;
  int pub_r000460_14_2;
  int pub_r000460_15_1;
  int pub_r000460_15_2;
  int pub_r000460_16_1;
  int pub_r000460_16_2;
  int pub_r000460_17_1;
  int pub_r000460_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000460_0_1 >= (-100)) && (pub_r000460_0_1 <= 100));
  __CPROVER_assume((pub_r000460_0_2 >= (-100)) && (pub_r000460_0_2 <= 100));
  __CPROVER_assume((pub_r000460_1_1 >= (-100)) && (pub_r000460_1_1 <= 100));
  __CPROVER_assume((pub_r000460_1_2 >= (-100)) && (pub_r000460_1_2 <= 100));
  __CPROVER_assume((pub_r000460_2_1 >= (-100)) && (pub_r000460_2_1 <= 100));
  __CPROVER_assume((pub_r000460_2_2 >= (-100)) && (pub_r000460_2_2 <= 100));
  __CPROVER_assume((pub_r000460_3_1 >= (-100)) && (pub_r000460_3_1 <= 100));
  __CPROVER_assume((pub_r000460_3_2 >= (-100)) && (pub_r000460_3_2 <= 100));
  __CPROVER_assume((pub_r000460_4_1 >= (-100)) && (pub_r000460_4_1 <= 100));
  __CPROVER_assume((pub_r000460_4_2 >= (-100)) && (pub_r000460_4_2 <= 100));
  __CPROVER_assume((pub_r000460_5_1 >= (-100)) && (pub_r000460_5_1 <= 100));
  __CPROVER_assume((pub_r000460_5_2 >= (-100)) && (pub_r000460_5_2 <= 100));
  __CPROVER_assume((pub_r000460_6_1 >= (-100)) && (pub_r000460_6_1 <= 100));
  __CPROVER_assume((pub_r000460_6_2 >= (-100)) && (pub_r000460_6_2 <= 100));
  __CPROVER_assume((pub_r000460_7_1 >= (-100)) && (pub_r000460_7_1 <= 100));
  __CPROVER_assume((pub_r000460_7_2 >= (-100)) && (pub_r000460_7_2 <= 100));
  __CPROVER_assume((pub_r000460_8_1 >= (-100)) && (pub_r000460_8_1 <= 100));
  __CPROVER_assume((pub_r000460_8_2 >= (-100)) && (pub_r000460_8_2 <= 100));
  __CPROVER_assume((pub_r000460_9_1 >= (-100)) && (pub_r000460_9_1 <= 100));
  __CPROVER_assume((pub_r000460_9_2 >= (-100)) && (pub_r000460_9_2 <= 100));
  __CPROVER_assume((pub_r000460_10_1 >= (-100)) && (pub_r000460_10_1 <= 100));
  __CPROVER_assume((pub_r000460_10_2 >= (-100)) && (pub_r000460_10_2 <= 100));
  __CPROVER_assume((pub_r000460_11_1 >= (-100)) && (pub_r000460_11_1 <= 100));
  __CPROVER_assume((pub_r000460_11_2 >= (-100)) && (pub_r000460_11_2 <= 100));
  __CPROVER_assume((pub_r000460_12_1 >= (-100)) && (pub_r000460_12_1 <= 100));
  __CPROVER_assume((pub_r000460_12_2 >= (-100)) && (pub_r000460_12_2 <= 100));
  __CPROVER_assume((pub_r000460_13_1 >= (-100)) && (pub_r000460_13_1 <= 100));
  __CPROVER_assume((pub_r000460_13_2 >= (-100)) && (pub_r000460_13_2 <= 100));
  __CPROVER_assume((pub_r000460_14_1 >= (-100)) && (pub_r000460_14_1 <= 100));
  __CPROVER_assume((pub_r000460_14_2 >= (-100)) && (pub_r000460_14_2 <= 100));
  __CPROVER_assume((pub_r000460_15_1 >= (-100)) && (pub_r000460_15_1 <= 100));
  __CPROVER_assume((pub_r000460_15_2 >= (-100)) && (pub_r000460_15_2 <= 100));
  __CPROVER_assume((pub_r000460_16_1 >= (-100)) && (pub_r000460_16_1 <= 100));
  __CPROVER_assume((pub_r000460_16_2 >= (-100)) && (pub_r000460_16_2 <= 100));
  __CPROVER_assume((pub_r000460_17_1 >= (-100)) && (pub_r000460_17_1 <= 100));
  __CPROVER_assume((pub_r000460_17_2 >= (-100)) && (pub_r000460_17_2 <= 100));
  __CPROVER_assume((sec_r000460_0_1 >= 0) && (sec_r000460_0_1 <= 255));
  __CPROVER_assume((sec_r000460_0_2 >= 0) && (sec_r000460_0_2 <= 255));
  __CPROVER_assume((sec_r000460_1_1 >= 0) && (sec_r000460_1_1 <= 255));
  __CPROVER_assume((sec_r000460_1_2 >= 0) && (sec_r000460_1_2 <= 255));
  __CPROVER_assume((sec_r000460_2_1 >= 0) && (sec_r000460_2_1 <= 255));
  __CPROVER_assume((sec_r000460_2_2 >= 0) && (sec_r000460_2_2 <= 255));
  __CPROVER_assume((sec_r000460_3_1 >= 0) && (sec_r000460_3_1 <= 255));
  __CPROVER_assume((sec_r000460_3_2 >= 0) && (sec_r000460_3_2 <= 255));
  __CPROVER_assume((sec_r000460_4_1 >= 0) && (sec_r000460_4_1 <= 255));
  __CPROVER_assume((sec_r000460_4_2 >= 0) && (sec_r000460_4_2 <= 255));
  __CPROVER_assume((sec_r000460_5_1 >= 0) && (sec_r000460_5_1 <= 255));
  __CPROVER_assume((sec_r000460_5_2 >= 0) && (sec_r000460_5_2 <= 255));
  __CPROVER_assume((sec_r000460_6_1 >= 0) && (sec_r000460_6_1 <= 255));
  __CPROVER_assume((sec_r000460_6_2 >= 0) && (sec_r000460_6_2 <= 255));
  __CPROVER_assume((sec_r000460_7_1 >= 0) && (sec_r000460_7_1 <= 255));
  __CPROVER_assume((sec_r000460_7_2 >= 0) && (sec_r000460_7_2 <= 255));
  __CPROVER_assume((sec_r000460_8_1 >= 0) && (sec_r000460_8_1 <= 255));
  __CPROVER_assume((sec_r000460_8_2 >= 0) && (sec_r000460_8_2 <= 255));
  __CPROVER_assume((sec_r000460_9_1 >= 0) && (sec_r000460_9_1 <= 255));
  __CPROVER_assume((sec_r000460_9_2 >= 0) && (sec_r000460_9_2 <= 255));
  __CPROVER_assume((sec_r000460_10_1 >= 0) && (sec_r000460_10_1 <= 255));
  __CPROVER_assume((sec_r000460_10_2 >= 0) && (sec_r000460_10_2 <= 255));
  __CPROVER_assume((sec_r000460_11_1 >= 0) && (sec_r000460_11_1 <= 255));
  __CPROVER_assume((sec_r000460_11_2 >= 0) && (sec_r000460_11_2 <= 255));
  __CPROVER_assume((sec_r000460_12_1 >= 0) && (sec_r000460_12_1 <= 255));
  __CPROVER_assume((sec_r000460_12_2 >= 0) && (sec_r000460_12_2 <= 255));
  __CPROVER_assume((sec_r000460_13_1 >= 0) && (sec_r000460_13_1 <= 255));
  __CPROVER_assume((sec_r000460_13_2 >= 0) && (sec_r000460_13_2 <= 255));
  __CPROVER_assume((sec_r000460_14_1 >= 0) && (sec_r000460_14_1 <= 255));
  __CPROVER_assume((sec_r000460_14_2 >= 0) && (sec_r000460_14_2 <= 255));
  __CPROVER_assume((sec_r000460_15_1 >= 0) && (sec_r000460_15_1 <= 255));
  __CPROVER_assume((sec_r000460_15_2 >= 0) && (sec_r000460_15_2 <= 255));
  struct Transaction_R000460_6013_0 st_var_0_1 = {0};
  struct Transaction_R000460_6013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000460_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000460_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000460_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000460_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000460_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000460_0_2 + 7) & 15;
  struct DeviceConfig_R000460_6013_1 st_var_1_1 = {0};
  struct DeviceConfig_R000460_6013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000460_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000460_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000460_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000460_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000460_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000460_0_2 + 9) & 15;
  struct FilterState_R000460_6013_2 st_var_2_1 = {0};
  struct FilterState_R000460_6013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000460_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000460_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000460_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000460_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000460_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000460_0_2 + 11) & 15;
  struct AudioFrame_R000460_6013_3 st_var_3_1 = {0};
  struct AudioFrame_R000460_6013_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000460_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000460_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000460_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000460_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000460_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000460_0_2 + 13) & 15;
  union PacketPayload_R000460_6013_0 u_var_1;
  union PacketPayload_R000460_6013_0 u_var_2;
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
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = (st_var_3_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_3_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
  int stage_v_6_1 = (st_var_2_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_2_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  int stage_v_9_1 = ((st_var_1_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_1_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 41)
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
  if (stage_v_9_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 41)
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
  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  int stage_v_17_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (22 & 31);
  int stage_v_17_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (22 & 31);
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= (stage_v_17_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_17_2 << 1) & 127;
  int stage_v_18_1 = ((st_var_2_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_2_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 33)
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
  if (stage_v_18_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 33)
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
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = ((st_var_0_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_0_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 42)
    {
      chk_sum_1 ^= stage_v_20_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_20_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 42)
    {
      chk_sum_2 ^= stage_v_20_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = ((sec_r000460_7_1 ^ 0x2A) + pub_r000460_10_1) & 127;
  int stage_v_23_2 = ((sec_r000460_7_2 ^ 0x2A) + pub_r000460_10_2) & 127;
  if (stage_v_23_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = ((stage_v_23_1 ^ 0x2A) + pub_r000460_17_1) & 127;
  int stage_v_24_2 = ((stage_v_23_2 ^ 0x2A) + pub_r000460_17_2) & 127;
  if (stage_v_24_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((sec_r000460_5_1 ^ 0x2A) + pub_r000460_7_1) & 127;
  int stage_v_25_2 = ((sec_r000460_5_2 ^ 0x2A) + pub_r000460_7_2) & 127;
  if (stage_v_25_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((sec_r000460_8_1 ^ 0x2A) + pub_r000460_0_1) & 127;
  int stage_v_26_2 = ((sec_r000460_8_2 ^ 0x2A) + pub_r000460_0_2) & 127;
  if (stage_v_26_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((stage_v_25_1 ^ 0x2A) + pub_r000460_1_1) & 127;
  int stage_v_27_2 = ((stage_v_25_2 ^ 0x2A) + pub_r000460_1_2) & 127;
  if (stage_v_27_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((stage_v_26_1 ^ 0x2A) + pub_r000460_3_1) & 127;
  int stage_v_28_2 = ((stage_v_26_2 ^ 0x2A) + pub_r000460_3_2) & 127;
  if (stage_v_28_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((stage_v_24_1 ^ 0x2A) + pub_r000460_16_1) & 127;
  int stage_v_29_2 = ((stage_v_24_2 ^ 0x2A) + pub_r000460_16_2) & 127;
  if (stage_v_29_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((stage_v_29_1 ^ 0x2A) + pub_r000460_16_1) & 127;
  int stage_v_30_2 = ((stage_v_29_2 ^ 0x2A) + pub_r000460_16_2) & 127;
  if (stage_v_30_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((stage_v_23_1 ^ 0x2A) + pub_r000460_4_1) & 127;
  int stage_v_31_2 = ((stage_v_23_2 ^ 0x2A) + pub_r000460_4_2) & 127;
  if (stage_v_31_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((sec_r000460_11_1 ^ 0x2A) + pub_r000460_4_1) & 127;
  int stage_v_32_2 = ((sec_r000460_11_2 ^ 0x2A) + pub_r000460_4_2) & 127;
  if (stage_v_32_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((sec_r000460_5_1 ^ 0x2A) + pub_r000460_2_1) & 127;
  int stage_v_33_2 = ((sec_r000460_5_2 ^ 0x2A) + pub_r000460_2_2) & 127;
  if (stage_v_33_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = ((sec_r000460_14_1 ^ 0x2A) + pub_r000460_1_1) & 127;
  int stage_v_34_2 = ((sec_r000460_14_2 ^ 0x2A) + pub_r000460_1_2) & 127;
  if (stage_v_34_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((stage_v_27_1 ^ 0x2A) + pub_r000460_2_1) & 127;
  int stage_v_35_2 = ((stage_v_27_2 ^ 0x2A) + pub_r000460_2_2) & 127;
  if (stage_v_35_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((stage_v_27_1 ^ 0x2A) + pub_r000460_13_1) & 127;
  int stage_v_36_2 = ((stage_v_27_2 ^ 0x2A) + pub_r000460_13_2) & 127;
  if (stage_v_36_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((stage_v_25_1 ^ 0x2A) + pub_r000460_0_1) & 127;
  int stage_v_37_2 = ((stage_v_25_2 ^ 0x2A) + pub_r000460_0_2) & 127;
  if (stage_v_37_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((stage_v_23_1 ^ 0x2A) + pub_r000460_3_1) & 127;
  int stage_v_38_2 = ((stage_v_23_2 ^ 0x2A) + pub_r000460_3_2) & 127;
  if (stage_v_38_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((sec_r000460_7_1 ^ 0x2A) + pub_r000460_16_1) & 127;
  int stage_v_39_2 = ((sec_r000460_7_2 ^ 0x2A) + pub_r000460_16_2) & 127;
  if (stage_v_39_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((stage_v_27_1 ^ 0x2A) + pub_r000460_14_1) & 127;
  int stage_v_40_2 = ((stage_v_27_2 ^ 0x2A) + pub_r000460_14_2) & 127;
  if (stage_v_40_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((stage_v_39_1 ^ 0x2A) + pub_r000460_2_1) & 127;
  int stage_v_41_2 = ((stage_v_39_2 ^ 0x2A) + pub_r000460_2_2) & 127;
  if (stage_v_41_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((stage_v_25_1 ^ 0x2A) + pub_r000460_5_1) & 127;
  int stage_v_42_2 = ((stage_v_25_2 ^ 0x2A) + pub_r000460_5_2) & 127;
  if (stage_v_42_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((stage_v_36_1 ^ 0x2A) + pub_r000460_9_1) & 127;
  int stage_v_43_2 = ((stage_v_36_2 ^ 0x2A) + pub_r000460_9_2) & 127;
  if (stage_v_43_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((stage_v_42_1 ^ 0x2A) + pub_r000460_5_1) & 127;
  int stage_v_44_2 = ((stage_v_42_2 ^ 0x2A) + pub_r000460_5_2) & 127;
  if (stage_v_44_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((stage_v_28_1 ^ 0x2A) + pub_r000460_11_1) & 127;
  int stage_v_45_2 = ((stage_v_28_2 ^ 0x2A) + pub_r000460_11_2) & 127;
  if (stage_v_45_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((sec_r000460_8_1 ^ 0x2A) + pub_r000460_3_1) & 127;
  int stage_v_46_2 = ((sec_r000460_8_2 ^ 0x2A) + pub_r000460_3_2) & 127;
  if (stage_v_46_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((sec_r000460_8_1 ^ 0x2A) + pub_r000460_3_1) & 127;
  int stage_v_47_2 = ((sec_r000460_8_2 ^ 0x2A) + pub_r000460_3_2) & 127;
  if (stage_v_47_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((stage_v_23_1 ^ 0x2A) + pub_r000460_1_1) & 127;
  int stage_v_48_2 = ((stage_v_23_2 ^ 0x2A) + pub_r000460_1_2) & 127;
  if (stage_v_48_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((stage_v_36_1 ^ 0x2A) + pub_r000460_9_1) & 127;
  int stage_v_49_2 = ((stage_v_36_2 ^ 0x2A) + pub_r000460_9_2) & 127;
  if (stage_v_49_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((stage_v_48_1 ^ 0x2A) + pub_r000460_5_1) & 127;
  int stage_v_50_2 = ((stage_v_48_2 ^ 0x2A) + pub_r000460_5_2) & 127;
  if (stage_v_50_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((stage_v_39_1 ^ 0x2A) + pub_r000460_10_1) & 127;
  int stage_v_51_2 = ((stage_v_39_2 ^ 0x2A) + pub_r000460_10_2) & 127;
  if (stage_v_51_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((stage_v_26_1 ^ 0x2A) + pub_r000460_15_1) & 127;
  int stage_v_52_2 = ((stage_v_26_2 ^ 0x2A) + pub_r000460_15_2) & 127;
  if (stage_v_52_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((stage_v_27_1 ^ 0x2A) + pub_r000460_14_1) & 127;
  int stage_v_53_2 = ((stage_v_27_2 ^ 0x2A) + pub_r000460_14_2) & 127;
  if (stage_v_53_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((sec_r000460_2_1 ^ 0x2A) + pub_r000460_7_1) & 127;
  int stage_v_54_2 = ((sec_r000460_2_2 ^ 0x2A) + pub_r000460_7_2) & 127;
  if (stage_v_54_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((stage_v_53_1 ^ 0x2A) + pub_r000460_5_1) & 127;
  int stage_v_55_2 = ((stage_v_53_2 ^ 0x2A) + pub_r000460_5_2) & 127;
  if (stage_v_55_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((sec_r000460_0_1 ^ 0x2A) + pub_r000460_7_1) & 127;
  int stage_v_56_2 = ((sec_r000460_0_2 ^ 0x2A) + pub_r000460_7_2) & 127;
  if (stage_v_56_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((sec_r000460_7_1 ^ 0x2A) + pub_r000460_10_1) & 127;
  int stage_v_57_2 = ((sec_r000460_7_2 ^ 0x2A) + pub_r000460_10_2) & 127;
  if (stage_v_57_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((stage_v_30_1 ^ 0x2A) + pub_r000460_3_1) & 127;
  int stage_v_58_2 = ((stage_v_30_2 ^ 0x2A) + pub_r000460_3_2) & 127;
  if (stage_v_58_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((stage_v_51_1 ^ 0x2A) + pub_r000460_15_1) & 127;
  int stage_v_59_2 = ((stage_v_51_2 ^ 0x2A) + pub_r000460_15_2) & 127;
  if (stage_v_59_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((stage_v_50_1 ^ 0x2A) + pub_r000460_11_1) & 127;
  int stage_v_60_2 = ((stage_v_50_2 ^ 0x2A) + pub_r000460_11_2) & 127;
  if (stage_v_60_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((stage_v_55_1 ^ 0x2A) + pub_r000460_15_1) & 127;
  int stage_v_61_2 = ((stage_v_55_2 ^ 0x2A) + pub_r000460_15_2) & 127;
  if (stage_v_61_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((stage_v_23_1 ^ 0x2A) + pub_r000460_16_1) & 127;
  int stage_v_62_2 = ((stage_v_23_2 ^ 0x2A) + pub_r000460_16_2) & 127;
  if (stage_v_62_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((sec_r000460_15_1 ^ 0x2A) + pub_r000460_15_1) & 127;
  int stage_v_63_2 = ((sec_r000460_15_2 ^ 0x2A) + pub_r000460_15_2) & 127;
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
  int stage_v_64_1 = ((stage_v_41_1 ^ 0x2A) + pub_r000460_1_1) & 127;
  int stage_v_64_2 = ((stage_v_41_2 ^ 0x2A) + pub_r000460_1_2) & 127;
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
  int stage_v_65_1 = ((stage_v_62_1 ^ 0x2A) + pub_r000460_8_1) & 127;
  int stage_v_65_2 = ((stage_v_62_2 ^ 0x2A) + pub_r000460_8_2) & 127;
  if (stage_v_65_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((stage_v_51_1 ^ 0x2A) + pub_r000460_3_1) & 127;
  int stage_v_66_2 = ((stage_v_51_2 ^ 0x2A) + pub_r000460_3_2) & 127;
  if (stage_v_66_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((stage_v_39_1 ^ 0x2A) + pub_r000460_2_1) & 127;
  int stage_v_67_2 = ((stage_v_39_2 ^ 0x2A) + pub_r000460_2_2) & 127;
  if (stage_v_67_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((stage_v_41_1 ^ 0x2A) + pub_r000460_15_1) & 127;
  int stage_v_68_2 = ((stage_v_41_2 ^ 0x2A) + pub_r000460_15_2) & 127;
  if (stage_v_68_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((stage_v_49_1 ^ 0x2A) + pub_r000460_6_1) & 127;
  int stage_v_69_2 = ((stage_v_49_2 ^ 0x2A) + pub_r000460_6_2) & 127;
  if (stage_v_69_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((stage_v_33_1 ^ 0x2A) + pub_r000460_9_1) & 127;
  int stage_v_70_2 = ((stage_v_33_2 ^ 0x2A) + pub_r000460_9_2) & 127;
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
  int stage_v_71_1 = ((stage_v_34_1 ^ 0x2A) + pub_r000460_11_1) & 127;
  int stage_v_71_2 = ((stage_v_34_2 ^ 0x2A) + pub_r000460_11_2) & 127;
  if (stage_v_71_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((stage_v_69_1 ^ 0x2A) + pub_r000460_16_1) & 127;
  int stage_v_72_2 = ((stage_v_69_2 ^ 0x2A) + pub_r000460_16_2) & 127;
  if (stage_v_72_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((sec_r000460_14_1 ^ 0x2A) + pub_r000460_8_1) & 127;
  int stage_v_73_2 = ((sec_r000460_14_2 ^ 0x2A) + pub_r000460_8_2) & 127;
  if (stage_v_73_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((sec_r000460_0_1 ^ 0x2A) + pub_r000460_2_1) & 127;
  int stage_v_74_2 = ((sec_r000460_0_2 ^ 0x2A) + pub_r000460_2_2) & 127;
  if (stage_v_74_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((sec_r000460_14_1 ^ 0x2A) + pub_r000460_0_1) & 127;
  int stage_v_75_2 = ((sec_r000460_14_2 ^ 0x2A) + pub_r000460_0_2) & 127;
  if (stage_v_75_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((sec_r000460_1_1 ^ 0x2A) + pub_r000460_17_1) & 127;
  int stage_v_76_2 = ((sec_r000460_1_2 ^ 0x2A) + pub_r000460_17_2) & 127;
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
  int stage_v_77_1 = ((sec_r000460_9_1 ^ 0x2A) + pub_r000460_13_1) & 127;
  int stage_v_77_2 = ((sec_r000460_9_2 ^ 0x2A) + pub_r000460_13_2) & 127;
  if (stage_v_77_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((stage_v_63_1 ^ 0x2A) + pub_r000460_9_1) & 127;
  int stage_v_78_2 = ((stage_v_63_2 ^ 0x2A) + pub_r000460_9_2) & 127;
  if (stage_v_78_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((stage_v_77_1 ^ 0x2A) + pub_r000460_0_1) & 127;
  int stage_v_79_2 = ((stage_v_77_2 ^ 0x2A) + pub_r000460_0_2) & 127;
  if (stage_v_79_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((stage_v_30_1 ^ 0x2A) + pub_r000460_5_1) & 127;
  int stage_v_80_2 = ((stage_v_30_2 ^ 0x2A) + pub_r000460_5_2) & 127;
  if (stage_v_80_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((stage_v_52_1 ^ 0x2A) + pub_r000460_0_1) & 127;
  int stage_v_81_2 = ((stage_v_52_2 ^ 0x2A) + pub_r000460_0_2) & 127;
  if (stage_v_81_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((stage_v_58_1 ^ 0x2A) + pub_r000460_4_1) & 127;
  int stage_v_82_2 = ((stage_v_58_2 ^ 0x2A) + pub_r000460_4_2) & 127;
  if (stage_v_82_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((stage_v_41_1 ^ 0x2A) + pub_r000460_3_1) & 127;
  int stage_v_83_2 = ((stage_v_41_2 ^ 0x2A) + pub_r000460_3_2) & 127;
  if (stage_v_83_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((stage_v_31_1 ^ 0x2A) + pub_r000460_13_1) & 127;
  int stage_v_84_2 = ((stage_v_31_2 ^ 0x2A) + pub_r000460_13_2) & 127;
  if (stage_v_84_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((stage_v_71_1 ^ 0x2A) + pub_r000460_3_1) & 127;
  int stage_v_85_2 = ((stage_v_71_2 ^ 0x2A) + pub_r000460_3_2) & 127;
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
  int stage_v_86_1 = ((stage_v_40_1 ^ 0x2A) + pub_r000460_15_1) & 127;
  int stage_v_86_2 = ((stage_v_40_2 ^ 0x2A) + pub_r000460_15_2) & 127;
  if (stage_v_86_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((stage_v_74_1 ^ 0x2A) + pub_r000460_4_1) & 127;
  int stage_v_87_2 = ((stage_v_74_2 ^ 0x2A) + pub_r000460_4_2) & 127;
  if (stage_v_87_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((stage_v_64_1 ^ 0x2A) + pub_r000460_15_1) & 127;
  int stage_v_88_2 = ((stage_v_64_2 ^ 0x2A) + pub_r000460_15_2) & 127;
  if (stage_v_88_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((stage_v_55_1 ^ 0x2A) + pub_r000460_16_1) & 127;
  int stage_v_89_2 = ((stage_v_55_2 ^ 0x2A) + pub_r000460_16_2) & 127;
  if (stage_v_89_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((sec_r000460_2_1 ^ 0x2A) + pub_r000460_13_1) & 127;
  int stage_v_90_2 = ((sec_r000460_2_2 ^ 0x2A) + pub_r000460_13_2) & 127;
  if (stage_v_90_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((sec_r000460_11_1 ^ 0x2A) + pub_r000460_6_1) & 127;
  int stage_v_91_2 = ((sec_r000460_11_2 ^ 0x2A) + pub_r000460_6_2) & 127;
  if (stage_v_91_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((stage_v_73_1 ^ 0x2A) + pub_r000460_1_1) & 127;
  int stage_v_92_2 = ((stage_v_73_2 ^ 0x2A) + pub_r000460_1_2) & 127;
  if (stage_v_92_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((stage_v_50_1 ^ 0x2A) + pub_r000460_6_1) & 127;
  int stage_v_93_2 = ((stage_v_50_2 ^ 0x2A) + pub_r000460_6_2) & 127;
  if (stage_v_93_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((sec_r000460_6_1 ^ 0x2A) + pub_r000460_10_1) & 127;
  int stage_v_94_2 = ((sec_r000460_6_2 ^ 0x2A) + pub_r000460_10_2) & 127;
  if (stage_v_94_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((sec_r000460_7_1 ^ 0x2A) + pub_r000460_12_1) & 127;
  int stage_v_95_2 = ((sec_r000460_7_2 ^ 0x2A) + pub_r000460_12_2) & 127;
  if (stage_v_95_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((stage_v_83_1 ^ 0x2A) + pub_r000460_15_1) & 127;
  int stage_v_96_2 = ((stage_v_83_2 ^ 0x2A) + pub_r000460_15_2) & 127;
  if (stage_v_96_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((stage_v_81_1 ^ 0x2A) + pub_r000460_9_1) & 127;
  int stage_v_97_2 = ((stage_v_81_2 ^ 0x2A) + pub_r000460_9_2) & 127;
  if (stage_v_97_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((stage_v_43_1 ^ 0x2A) + pub_r000460_10_1) & 127;
  int stage_v_98_2 = ((stage_v_43_2 ^ 0x2A) + pub_r000460_10_2) & 127;
  if (stage_v_98_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((stage_v_62_1 ^ 0x2A) + pub_r000460_9_1) & 127;
  int stage_v_99_2 = ((stage_v_62_2 ^ 0x2A) + pub_r000460_9_2) & 127;
  if (stage_v_99_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((stage_v_34_1 ^ 0x2A) + pub_r000460_15_1) & 127;
  int stage_v_100_2 = ((stage_v_34_2 ^ 0x2A) + pub_r000460_15_2) & 127;
  if (stage_v_100_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((sec_r000460_14_1 ^ 0x2A) + pub_r000460_5_1) & 127;
  int stage_v_101_2 = ((sec_r000460_14_2 ^ 0x2A) + pub_r000460_5_2) & 127;
  if (stage_v_101_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((sec_r000460_12_1 ^ 0x2A) + pub_r000460_14_1) & 127;
  int stage_v_102_2 = ((sec_r000460_12_2 ^ 0x2A) + pub_r000460_14_2) & 127;
  if (stage_v_102_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((stage_v_81_1 ^ 0x2A) + pub_r000460_10_1) & 127;
  int stage_v_103_2 = ((stage_v_81_2 ^ 0x2A) + pub_r000460_10_2) & 127;
  if (stage_v_103_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((sec_r000460_10_1 ^ 0x2A) + pub_r000460_10_1) & 127;
  int stage_v_104_2 = ((sec_r000460_10_2 ^ 0x2A) + pub_r000460_10_2) & 127;
  if (stage_v_104_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((stage_v_74_1 ^ 0x2A) + pub_r000460_3_1) & 127;
  int stage_v_105_2 = ((stage_v_74_2 ^ 0x2A) + pub_r000460_3_2) & 127;
  if (stage_v_105_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((stage_v_76_1 ^ 0x2A) + pub_r000460_5_1) & 127;
  int stage_v_106_2 = ((stage_v_76_2 ^ 0x2A) + pub_r000460_5_2) & 127;
  if (stage_v_106_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((stage_v_35_1 ^ 0x2A) + pub_r000460_7_1) & 127;
  int stage_v_107_2 = ((stage_v_35_2 ^ 0x2A) + pub_r000460_7_2) & 127;
  if (stage_v_107_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((stage_v_70_1 ^ 0x2A) + pub_r000460_11_1) & 127;
  int stage_v_108_2 = ((stage_v_70_2 ^ 0x2A) + pub_r000460_11_2) & 127;
  if (stage_v_108_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((sec_r000460_0_1 ^ 0x2A) + pub_r000460_14_1) & 127;
  int stage_v_109_2 = ((sec_r000460_0_2 ^ 0x2A) + pub_r000460_14_2) & 127;
  if (stage_v_109_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((stage_v_96_1 ^ 0x2A) + pub_r000460_3_1) & 127;
  int stage_v_110_2 = ((stage_v_96_2 ^ 0x2A) + pub_r000460_3_2) & 127;
  if (stage_v_110_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((sec_r000460_12_1 ^ 0x2A) + pub_r000460_13_1) & 127;
  int stage_v_111_2 = ((sec_r000460_12_2 ^ 0x2A) + pub_r000460_13_2) & 127;
  if (stage_v_111_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((sec_r000460_7_1 ^ 0x2A) + pub_r000460_2_1) & 127;
  int stage_v_112_2 = ((sec_r000460_7_2 ^ 0x2A) + pub_r000460_2_2) & 127;
  if (stage_v_112_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((sec_r000460_10_1 ^ 0x2A) + pub_r000460_0_1) & 127;
  int stage_v_113_2 = ((sec_r000460_10_2 ^ 0x2A) + pub_r000460_0_2) & 127;
  if (stage_v_113_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((stage_v_77_1 ^ 0x2A) + pub_r000460_8_1) & 127;
  int stage_v_114_2 = ((stage_v_77_2 ^ 0x2A) + pub_r000460_8_2) & 127;
  if (stage_v_114_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((stage_v_58_1 ^ 0x2A) + pub_r000460_12_1) & 127;
  int stage_v_115_2 = ((stage_v_58_2 ^ 0x2A) + pub_r000460_12_2) & 127;
  if (stage_v_115_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((stage_v_101_1 ^ 0x2A) + pub_r000460_2_1) & 127;
  int stage_v_116_2 = ((stage_v_101_2 ^ 0x2A) + pub_r000460_2_2) & 127;
  if (stage_v_116_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((stage_v_38_1 ^ 0x2A) + pub_r000460_11_1) & 127;
  int stage_v_117_2 = ((stage_v_38_2 ^ 0x2A) + pub_r000460_11_2) & 127;
  if (stage_v_117_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((stage_v_83_1 ^ 0x2A) + pub_r000460_10_1) & 127;
  int stage_v_118_2 = ((stage_v_83_2 ^ 0x2A) + pub_r000460_10_2) & 127;
  if (stage_v_118_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((sec_r000460_10_1 ^ 0x2A) + pub_r000460_15_1) & 127;
  int stage_v_119_2 = ((sec_r000460_10_2 ^ 0x2A) + pub_r000460_15_2) & 127;
  if (stage_v_119_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((sec_r000460_13_1 ^ 0x2A) + pub_r000460_2_1) & 127;
  int stage_v_120_2 = ((sec_r000460_13_2 ^ 0x2A) + pub_r000460_2_2) & 127;
  if (stage_v_120_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((sec_r000460_15_1 ^ 0x2A) + pub_r000460_17_1) & 127;
  int stage_v_121_2 = ((sec_r000460_15_2 ^ 0x2A) + pub_r000460_17_2) & 127;
  if (stage_v_121_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((sec_r000460_5_1 ^ 0x2A) + pub_r000460_16_1) & 127;
  int stage_v_122_2 = ((sec_r000460_5_2 ^ 0x2A) + pub_r000460_16_2) & 127;
  if (stage_v_122_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((sec_r000460_4_1 ^ 0x2A) + pub_r000460_11_1) & 127;
  int stage_v_123_2 = ((sec_r000460_4_2 ^ 0x2A) + pub_r000460_11_2) & 127;
  if (stage_v_123_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((sec_r000460_1_1 ^ 0x2A) + pub_r000460_17_1) & 127;
  int stage_v_124_2 = ((sec_r000460_1_2 ^ 0x2A) + pub_r000460_17_2) & 127;
  if (stage_v_124_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((stage_v_95_1 ^ 0x2A) + pub_r000460_14_1) & 127;
  int stage_v_125_2 = ((stage_v_95_2 ^ 0x2A) + pub_r000460_14_2) & 127;
  if (stage_v_125_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((sec_r000460_6_1 ^ 0x2A) + pub_r000460_9_1) & 127;
  int stage_v_126_2 = ((sec_r000460_6_2 ^ 0x2A) + pub_r000460_9_2) & 127;
  if (stage_v_126_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((stage_v_87_1 ^ 0x2A) + pub_r000460_10_1) & 127;
  int stage_v_127_2 = ((stage_v_87_2 ^ 0x2A) + pub_r000460_10_2) & 127;
  if (stage_v_127_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((stage_v_63_1 ^ 0x2A) + pub_r000460_8_1) & 127;
  int stage_v_128_2 = ((stage_v_63_2 ^ 0x2A) + pub_r000460_8_2) & 127;
  if (stage_v_128_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((stage_v_41_1 ^ 0x2A) + pub_r000460_12_1) & 127;
  int stage_v_129_2 = ((stage_v_41_2 ^ 0x2A) + pub_r000460_12_2) & 127;
  if (stage_v_129_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((stage_v_124_1 ^ 0x2A) + pub_r000460_9_1) & 127;
  int stage_v_130_2 = ((stage_v_124_2 ^ 0x2A) + pub_r000460_9_2) & 127;
  if (stage_v_130_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((stage_v_104_1 ^ 0x2A) + pub_r000460_11_1) & 127;
  int stage_v_131_2 = ((stage_v_104_2 ^ 0x2A) + pub_r000460_11_2) & 127;
  if (stage_v_131_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((stage_v_72_1 ^ 0x2A) + pub_r000460_3_1) & 127;
  int stage_v_132_2 = ((stage_v_72_2 ^ 0x2A) + pub_r000460_3_2) & 127;
  if (stage_v_132_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((sec_r000460_9_1 ^ 0x2A) + pub_r000460_9_1) & 127;
  int stage_v_133_2 = ((sec_r000460_9_2 ^ 0x2A) + pub_r000460_9_2) & 127;
  if (stage_v_133_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((sec_r000460_10_1 ^ 0x2A) + pub_r000460_11_1) & 127;
  int stage_v_134_2 = ((sec_r000460_10_2 ^ 0x2A) + pub_r000460_11_2) & 127;
  if (stage_v_134_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((stage_v_48_1 ^ 0x2A) + pub_r000460_8_1) & 127;
  int stage_v_135_2 = ((stage_v_48_2 ^ 0x2A) + pub_r000460_8_2) & 127;
  if (stage_v_135_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((sec_r000460_1_1 ^ 0x2A) + pub_r000460_17_1) & 127;
  int stage_v_136_2 = ((sec_r000460_1_2 ^ 0x2A) + pub_r000460_17_2) & 127;
  if (stage_v_136_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((stage_v_133_1 ^ 0x2A) + pub_r000460_10_1) & 127;
  int stage_v_137_2 = ((stage_v_133_2 ^ 0x2A) + pub_r000460_10_2) & 127;
  if (stage_v_137_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((sec_r000460_5_1 ^ 0x2A) + pub_r000460_11_1) & 127;
  int stage_v_138_2 = ((sec_r000460_5_2 ^ 0x2A) + pub_r000460_11_2) & 127;
  if (stage_v_138_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((stage_v_134_1 ^ 0x2A) + pub_r000460_12_1) & 127;
  int stage_v_139_2 = ((stage_v_134_2 ^ 0x2A) + pub_r000460_12_2) & 127;
  if (stage_v_139_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((stage_v_34_1 ^ 0x2A) + pub_r000460_12_1) & 127;
  int stage_v_140_2 = ((stage_v_34_2 ^ 0x2A) + pub_r000460_12_2) & 127;
  if (stage_v_140_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((stage_v_133_1 ^ 0x2A) + pub_r000460_10_1) & 127;
  int stage_v_141_2 = ((stage_v_133_2 ^ 0x2A) + pub_r000460_10_2) & 127;
  if (stage_v_141_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((stage_v_52_1 ^ 0x2A) + pub_r000460_2_1) & 127;
  int stage_v_142_2 = ((stage_v_52_2 ^ 0x2A) + pub_r000460_2_2) & 127;
  if (stage_v_142_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((stage_v_124_1 ^ 0x2A) + pub_r000460_4_1) & 127;
  int stage_v_143_2 = ((stage_v_124_2 ^ 0x2A) + pub_r000460_4_2) & 127;
  if (stage_v_143_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((sec_r000460_14_1 ^ 0x2A) + pub_r000460_11_1) & 127;
  int stage_v_144_2 = ((sec_r000460_14_2 ^ 0x2A) + pub_r000460_11_2) & 127;
  if (stage_v_144_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((stage_v_83_1 ^ 0x2A) + pub_r000460_15_1) & 127;
  int stage_v_145_2 = ((stage_v_83_2 ^ 0x2A) + pub_r000460_15_2) & 127;
  if (stage_v_145_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((stage_v_78_1 ^ 0x2A) + pub_r000460_4_1) & 127;
  int stage_v_146_2 = ((stage_v_78_2 ^ 0x2A) + pub_r000460_4_2) & 127;
  if (stage_v_146_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((sec_r000460_5_1 ^ 0x2A) + pub_r000460_3_1) & 127;
  int stage_v_147_2 = ((sec_r000460_5_2 ^ 0x2A) + pub_r000460_3_2) & 127;
  if (stage_v_147_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((stage_v_124_1 ^ 0x2A) + pub_r000460_7_1) & 127;
  int stage_v_148_2 = ((stage_v_124_2 ^ 0x2A) + pub_r000460_7_2) & 127;
  if (stage_v_148_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((stage_v_25_1 ^ 0x2A) + pub_r000460_17_1) & 127;
  int stage_v_149_2 = ((stage_v_25_2 ^ 0x2A) + pub_r000460_17_2) & 127;
  if (stage_v_149_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((stage_v_95_1 ^ 0x2A) + pub_r000460_6_1) & 127;
  int stage_v_150_2 = ((stage_v_95_2 ^ 0x2A) + pub_r000460_6_2) & 127;
  if (stage_v_150_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((stage_v_29_1 ^ 0x2A) + pub_r000460_4_1) & 127;
  int stage_v_151_2 = ((stage_v_29_2 ^ 0x2A) + pub_r000460_4_2) & 127;
  if (stage_v_151_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((sec_r000460_13_1 ^ 0x2A) + pub_r000460_6_1) & 127;
  int stage_v_152_2 = ((sec_r000460_13_2 ^ 0x2A) + pub_r000460_6_2) & 127;
  if (stage_v_152_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((sec_r000460_14_1 ^ 0x2A) + pub_r000460_3_1) & 127;
  int stage_v_153_2 = ((sec_r000460_14_2 ^ 0x2A) + pub_r000460_3_2) & 127;
  if (stage_v_153_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((stage_v_102_1 ^ 0x2A) + pub_r000460_8_1) & 127;
  int stage_v_154_2 = ((stage_v_102_2 ^ 0x2A) + pub_r000460_8_2) & 127;
  if (stage_v_154_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((sec_r000460_10_1 ^ 0x2A) + pub_r000460_16_1) & 127;
  int stage_v_155_2 = ((sec_r000460_10_2 ^ 0x2A) + pub_r000460_16_2) & 127;
  if (stage_v_155_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((stage_v_113_1 ^ 0x2A) + pub_r000460_11_1) & 127;
  int stage_v_156_2 = ((stage_v_113_2 ^ 0x2A) + pub_r000460_11_2) & 127;
  if (stage_v_156_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((sec_r000460_8_1 ^ 0x2A) + pub_r000460_13_1) & 127;
  int stage_v_157_2 = ((sec_r000460_8_2 ^ 0x2A) + pub_r000460_13_2) & 127;
  if (stage_v_157_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((stage_v_147_1 ^ 0x2A) + pub_r000460_8_1) & 127;
  int stage_v_158_2 = ((stage_v_147_2 ^ 0x2A) + pub_r000460_8_2) & 127;
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
  int stage_v_159_1 = ((stage_v_69_1 ^ 0x2A) + pub_r000460_12_1) & 127;
  int stage_v_159_2 = ((stage_v_69_2 ^ 0x2A) + pub_r000460_12_2) & 127;
  if (stage_v_159_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((stage_v_30_1 ^ 0x2A) + pub_r000460_6_1) & 127;
  int stage_v_160_2 = ((stage_v_30_2 ^ 0x2A) + pub_r000460_6_2) & 127;
  if (stage_v_160_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((stage_v_68_1 ^ 0x2A) + pub_r000460_0_1) & 127;
  int stage_v_161_2 = ((stage_v_68_2 ^ 0x2A) + pub_r000460_0_2) & 127;
  if (stage_v_161_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((stage_v_70_1 ^ 0x2A) + pub_r000460_1_1) & 127;
  int stage_v_162_2 = ((stage_v_70_2 ^ 0x2A) + pub_r000460_1_2) & 127;
  if (stage_v_162_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((sec_r000460_13_1 ^ 0x2A) + pub_r000460_9_1) & 127;
  int stage_v_163_2 = ((sec_r000460_13_2 ^ 0x2A) + pub_r000460_9_2) & 127;
  if (stage_v_163_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((stage_v_91_1 ^ 0x2A) + pub_r000460_12_1) & 127;
  int stage_v_164_2 = ((stage_v_91_2 ^ 0x2A) + pub_r000460_12_2) & 127;
  if (stage_v_164_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((stage_v_95_1 ^ 0x2A) + pub_r000460_13_1) & 127;
  int stage_v_165_2 = ((stage_v_95_2 ^ 0x2A) + pub_r000460_13_2) & 127;
  if (stage_v_165_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((stage_v_141_1 ^ 0x2A) + pub_r000460_12_1) & 127;
  int stage_v_166_2 = ((stage_v_141_2 ^ 0x2A) + pub_r000460_12_2) & 127;
  if (stage_v_166_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((sec_r000460_5_1 ^ 0x2A) + pub_r000460_12_1) & 127;
  int stage_v_167_2 = ((sec_r000460_5_2 ^ 0x2A) + pub_r000460_12_2) & 127;
  if (stage_v_167_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((sec_r000460_1_1 ^ 0x2A) + pub_r000460_9_1) & 127;
  int stage_v_168_2 = ((sec_r000460_1_2 ^ 0x2A) + pub_r000460_9_2) & 127;
  if (stage_v_168_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((sec_r000460_10_1 ^ 0x2A) + pub_r000460_5_1) & 127;
  int stage_v_169_2 = ((sec_r000460_10_2 ^ 0x2A) + pub_r000460_5_2) & 127;
  if (stage_v_169_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((stage_v_95_1 ^ 0x2A) + pub_r000460_1_1) & 127;
  int stage_v_170_2 = ((stage_v_95_2 ^ 0x2A) + pub_r000460_1_2) & 127;
  if (stage_v_170_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((stage_v_55_1 ^ 0x2A) + pub_r000460_16_1) & 127;
  int stage_v_171_2 = ((stage_v_55_2 ^ 0x2A) + pub_r000460_16_2) & 127;
  if (stage_v_171_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((stage_v_32_1 ^ 0x2A) + pub_r000460_11_1) & 127;
  int stage_v_172_2 = ((stage_v_32_2 ^ 0x2A) + pub_r000460_11_2) & 127;
  if (stage_v_172_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((sec_r000460_8_1 ^ 0x2A) + pub_r000460_1_1) & 127;
  int stage_v_173_2 = ((sec_r000460_8_2 ^ 0x2A) + pub_r000460_1_2) & 127;
  if (stage_v_173_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((stage_v_90_1 ^ 0x2A) + pub_r000460_1_1) & 127;
  int stage_v_174_2 = ((stage_v_90_2 ^ 0x2A) + pub_r000460_1_2) & 127;
  if (stage_v_174_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((stage_v_60_1 ^ 0x2A) + pub_r000460_13_1) & 127;
  int stage_v_175_2 = ((stage_v_60_2 ^ 0x2A) + pub_r000460_13_2) & 127;
  if (stage_v_175_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((stage_v_34_1 ^ 0x2A) + pub_r000460_6_1) & 127;
  int stage_v_176_2 = ((stage_v_34_2 ^ 0x2A) + pub_r000460_6_2) & 127;
  if (stage_v_176_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((stage_v_34_1 ^ 0x2A) + pub_r000460_10_1) & 127;
  int stage_v_177_2 = ((stage_v_34_2 ^ 0x2A) + pub_r000460_10_2) & 127;
  if (stage_v_177_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((sec_r000460_2_1 ^ 0x2A) + pub_r000460_10_1) & 127;
  int stage_v_178_2 = ((sec_r000460_2_2 ^ 0x2A) + pub_r000460_10_2) & 127;
  if (stage_v_178_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((stage_v_69_1 ^ 0x2A) + pub_r000460_1_1) & 127;
  int stage_v_179_2 = ((stage_v_69_2 ^ 0x2A) + pub_r000460_1_2) & 127;
  if (stage_v_179_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((stage_v_113_1 ^ 0x2A) + pub_r000460_6_1) & 127;
  int stage_v_180_2 = ((stage_v_113_2 ^ 0x2A) + pub_r000460_6_2) & 127;
  if (stage_v_180_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((sec_r000460_3_1 ^ 0x2A) + pub_r000460_9_1) & 127;
  int stage_v_181_2 = ((sec_r000460_3_2 ^ 0x2A) + pub_r000460_9_2) & 127;
  if (stage_v_181_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((stage_v_173_1 ^ 0x2A) + pub_r000460_0_1) & 127;
  int stage_v_182_2 = ((stage_v_173_2 ^ 0x2A) + pub_r000460_0_2) & 127;
  if (stage_v_182_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((sec_r000460_2_1 ^ 0x2A) + pub_r000460_8_1) & 127;
  int stage_v_183_2 = ((sec_r000460_2_2 ^ 0x2A) + pub_r000460_8_2) & 127;
  if (stage_v_183_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((stage_v_139_1 ^ 0x2A) + pub_r000460_1_1) & 127;
  int stage_v_184_2 = ((stage_v_139_2 ^ 0x2A) + pub_r000460_1_2) & 127;
  if (stage_v_184_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((stage_v_118_1 ^ 0x2A) + pub_r000460_11_1) & 127;
  int stage_v_185_2 = ((stage_v_118_2 ^ 0x2A) + pub_r000460_11_2) & 127;
  if (stage_v_185_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((stage_v_55_1 ^ 0x2A) + pub_r000460_1_1) & 127;
  int stage_v_186_2 = ((stage_v_55_2 ^ 0x2A) + pub_r000460_1_2) & 127;
  if (stage_v_186_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((sec_r000460_0_1 ^ 0x2A) + pub_r000460_12_1) & 127;
  int stage_v_187_2 = ((sec_r000460_0_2 ^ 0x2A) + pub_r000460_12_2) & 127;
  if (stage_v_187_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((stage_v_183_1 ^ 0x2A) + pub_r000460_16_1) & 127;
  int stage_v_188_2 = ((stage_v_183_2 ^ 0x2A) + pub_r000460_16_2) & 127;
  if (stage_v_188_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((stage_v_132_1 ^ 0x2A) + pub_r000460_4_1) & 127;
  int stage_v_189_2 = ((stage_v_132_2 ^ 0x2A) + pub_r000460_4_2) & 127;
  if (stage_v_189_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((stage_v_142_1 ^ 0x2A) + pub_r000460_10_1) & 127;
  int stage_v_190_2 = ((stage_v_142_2 ^ 0x2A) + pub_r000460_10_2) & 127;
  if (stage_v_190_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((stage_v_179_1 ^ 0x2A) + pub_r000460_17_1) & 127;
  int stage_v_191_2 = ((stage_v_179_2 ^ 0x2A) + pub_r000460_17_2) & 127;
  if (stage_v_191_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((stage_v_111_1 ^ 0x2A) + pub_r000460_6_1) & 127;
  int stage_v_192_2 = ((stage_v_111_2 ^ 0x2A) + pub_r000460_6_2) & 127;
  if (stage_v_192_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((stage_v_187_1 ^ 0x2A) + pub_r000460_6_1) & 127;
  int stage_v_193_2 = ((stage_v_187_2 ^ 0x2A) + pub_r000460_6_2) & 127;
  if (stage_v_193_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((stage_v_123_1 ^ 0x2A) + pub_r000460_6_1) & 127;
  int stage_v_194_2 = ((stage_v_123_2 ^ 0x2A) + pub_r000460_6_2) & 127;
  if (stage_v_194_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((stage_v_134_1 ^ 0x2A) + pub_r000460_9_1) & 127;
  int stage_v_195_2 = ((stage_v_134_2 ^ 0x2A) + pub_r000460_9_2) & 127;
  if (stage_v_195_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((stage_v_140_1 ^ 0x2A) + pub_r000460_16_1) & 127;
  int stage_v_196_2 = ((stage_v_140_2 ^ 0x2A) + pub_r000460_16_2) & 127;
  if (stage_v_196_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((sec_r000460_12_1 ^ 0x2A) + pub_r000460_0_1) & 127;
  int stage_v_197_2 = ((sec_r000460_12_2 ^ 0x2A) + pub_r000460_0_2) & 127;
  if (stage_v_197_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((stage_v_42_1 ^ 0x2A) + pub_r000460_12_1) & 127;
  int stage_v_198_2 = ((stage_v_42_2 ^ 0x2A) + pub_r000460_12_2) & 127;
  if (stage_v_198_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((stage_v_130_1 ^ 0x2A) + pub_r000460_6_1) & 127;
  int stage_v_199_2 = ((stage_v_130_2 ^ 0x2A) + pub_r000460_6_2) & 127;
  if (stage_v_199_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((stage_v_106_1 ^ 0x2A) + pub_r000460_8_1) & 127;
  int stage_v_200_2 = ((stage_v_106_2 ^ 0x2A) + pub_r000460_8_2) & 127;
  if (stage_v_200_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((stage_v_28_1 ^ 0x2A) + pub_r000460_17_1) & 127;
  int stage_v_201_2 = ((stage_v_28_2 ^ 0x2A) + pub_r000460_17_2) & 127;
  if (stage_v_201_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((stage_v_99_1 ^ 0x2A) + pub_r000460_7_1) & 127;
  int stage_v_202_2 = ((stage_v_99_2 ^ 0x2A) + pub_r000460_7_2) & 127;
  if (stage_v_202_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((stage_v_29_1 ^ 0x2A) + pub_r000460_16_1) & 127;
  int stage_v_203_2 = ((stage_v_29_2 ^ 0x2A) + pub_r000460_16_2) & 127;
  if (stage_v_203_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((sec_r000460_7_1 ^ 0x2A) + pub_r000460_8_1) & 127;
  int stage_v_204_2 = ((sec_r000460_7_2 ^ 0x2A) + pub_r000460_8_2) & 127;
  if (stage_v_204_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((stage_v_63_1 ^ 0x2A) + pub_r000460_14_1) & 127;
  int stage_v_205_2 = ((stage_v_63_2 ^ 0x2A) + pub_r000460_14_2) & 127;
  if (stage_v_205_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((sec_r000460_8_1 ^ 0x2A) + pub_r000460_17_1) & 127;
  int stage_v_206_2 = ((sec_r000460_8_2 ^ 0x2A) + pub_r000460_17_2) & 127;
  if (stage_v_206_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((sec_r000460_8_1 ^ 0x2A) + pub_r000460_1_1) & 127;
  int stage_v_207_2 = ((sec_r000460_8_2 ^ 0x2A) + pub_r000460_1_2) & 127;
  if (stage_v_207_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((stage_v_75_1 ^ 0x2A) + pub_r000460_0_1) & 127;
  int stage_v_208_2 = ((stage_v_75_2 ^ 0x2A) + pub_r000460_0_2) & 127;
  if (stage_v_208_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000460_11_1 != sec_r000460_11_2);
  __CPROVER_assume(pub_r000460_2_1 == pub_r000460_2_2);
  __CPROVER_assume(sec_r000460_8_1 != sec_r000460_8_2);
  __CPROVER_assume(sec_r000460_15_1 != sec_r000460_15_2);
  __CPROVER_assume(sec_r000460_4_1 != sec_r000460_4_2);
  __CPROVER_assume(sec_r000460_0_1 != sec_r000460_0_2);
  __CPROVER_assume(pub_r000460_9_1 == pub_r000460_9_2);
  __CPROVER_assume(sec_r000460_10_1 != sec_r000460_10_2);
  __CPROVER_assume(pub_r000460_14_1 == pub_r000460_14_2);
  __CPROVER_assume(pub_r000460_17_1 == pub_r000460_17_2);
  __CPROVER_assume(sec_r000460_3_1 != sec_r000460_3_2);
  __CPROVER_assume(sec_r000460_13_1 != sec_r000460_13_2);
  __CPROVER_assume(pub_r000460_3_1 == pub_r000460_3_2);
  __CPROVER_assume(sec_r000460_6_1 != sec_r000460_6_2);
  __CPROVER_assume(pub_r000460_6_1 == pub_r000460_6_2);
  __CPROVER_assume(pub_r000460_5_1 == pub_r000460_5_2);
  __CPROVER_assume(sec_r000460_14_1 != sec_r000460_14_2);
  __CPROVER_assume(pub_r000460_0_1 == pub_r000460_0_2);
  __CPROVER_assume(sec_r000460_7_1 != sec_r000460_7_2);
  __CPROVER_assume(pub_r000460_11_1 == pub_r000460_11_2);
  __CPROVER_assume(sec_r000460_9_1 != sec_r000460_9_2);
  __CPROVER_assume(sec_r000460_5_1 != sec_r000460_5_2);
  __CPROVER_assume(pub_r000460_15_1 == pub_r000460_15_2);
  __CPROVER_assume(pub_r000460_13_1 == pub_r000460_13_2);
  __CPROVER_assume(sec_r000460_1_1 != sec_r000460_1_2);
  __CPROVER_assume(pub_r000460_4_1 == pub_r000460_4_2);
  __CPROVER_assume(pub_r000460_8_1 == pub_r000460_8_2);
  __CPROVER_assume(pub_r000460_1_1 == pub_r000460_1_2);
  __CPROVER_assume(sec_r000460_2_1 != sec_r000460_2_2);
  __CPROVER_assume(pub_r000460_7_1 == pub_r000460_7_2);
  __CPROVER_assume(pub_r000460_16_1 == pub_r000460_16_2);
  __CPROVER_assume(pub_r000460_10_1 == pub_r000460_10_2);
  __CPROVER_assume(pub_r000460_12_1 == pub_r000460_12_2);
  __CPROVER_assume(sec_r000460_12_1 != sec_r000460_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
  assert(st_var_2_1.damping == st_var_2_2.damping);
  assert(st_var_2_1.cutoff == st_var_2_2.cutoff);
  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.prev_out == st_var_2_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.rms == st_var_3_2.rms);
  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.envelope == st_var_3_2.envelope);
  assert(st_var_3_1.channels == st_var_3_2.channels);
  assert(st_var_3_1.peak == st_var_3_2.peak);
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
}


