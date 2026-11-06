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
struct Transaction_R000477_7713_0
{
  short auth_code;
  int balance;
  short fee;
  int account_id;
  unsigned char status;
  int rate;
  int buffer[3];
};
struct FilterState_R000477_7713_1
{
  int mode;
  short prev_out;
  unsigned char prev_in;
  unsigned char damping;
  int cutoff;
  short gain_db;
  int buffer[3];
};
struct SensorNode_R000477_7713_2
{
  int offset;
  int calib;
  int reading;
  int gain;
  int status;
  int buffer[3];
};
struct EventLog_R000477_7713_3
{
  int seq;
  short timestamp;
  int code;
  short severity;
  short signature;
  int buffer[3];
};
union ColorPixel_R000477_7713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000477_7713_1
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
void fn_R000477_7713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st_1 = {0};
  struct SensorNode_R000477_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int mask_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_32_1 > 42)
  {
    acc_1 = ((acc_1 + (mask_32_1 * 2)) + 5) & 127;
    aux_1 ^= mask_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_32_2 > 42)
  {
    acc_2 = ((acc_2 + (mask_32_2 * 2)) + 5) & 127;
    aux_2 ^= mask_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_63_1) & 63;
  aux_2 = (aux_2 + offset_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_78_1)
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

  switch (delta_78_2)
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
  int tally_87_1 = local_arr_1[aux_1 % 3];
  int tally_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_87_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_32_1 == mask_32_2);
  assert(offset_63_1 == offset_63_2);
  assert(delta_78_1 == delta_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_87_1 == tally_87_2);
}

int fn_R000477_7713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int mask_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_32 > 42)
  {
    acc = ((acc + (mask_32 * 2)) + 5) & 127;
    aux ^= mask_32 & 15;
  }
  else
  {
    acc = ((acc - mask_32) + 11) & 127;
    aux += 3;
  }
  int offset_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_63) & 63;
  acc ^= aux;
  int delta_78 = (aux + st.buffer[1]) & 3;
  switch (delta_78)
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
  int tally_87 = local_arr[aux % 3];
  acc = (acc + (tally_87 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st_1 = {0};
  struct Transaction_R000477_7713_0 st_2 = {0};
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
  int checksum_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_23_1) & 63;
  aux_2 = (aux_2 + checksum_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_23_1 == checksum_23_2);
}

int fn_R000477_7713_1(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_23) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000477_7713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st_1 = {0};
  struct Transaction_R000477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int checksum_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_28_1) & 63;
  aux_2 = (aux_2 + checksum_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_28_1 == checksum_28_2);
}

int fn_R000477_7713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int checksum_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_28) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000477_7713_1 st_1 = {0};
  struct FilterState_R000477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quantum_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_38_1) & 63;
  aux_2 = (aux_2 + quantum_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_94_1 > 31)
  {
    acc_1 = ((acc_1 + (quotient_94_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_94_2 > 31)
  {
    acc_2 = ((acc_2 + (quotient_94_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_87_1)
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

  switch (threshold_87_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_38_1 == quantum_38_2);
  assert(quotient_94_1 == quotient_94_2);
  assert(threshold_87_1 == threshold_87_2);
}

int fn_R000477_7713_3(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quantum_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_38) & 63;
  acc ^= aux;
  int quotient_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_94 > 31)
  {
    acc = ((acc + (quotient_94 * 2)) + 5) & 127;
    aux ^= quotient_94 & 15;
  }
  else
  {
    acc = ((acc - quotient_94) + 11) & 127;
    aux += 3;
  }
  int threshold_87 = (aux + st.buffer[1]) & 3;
  switch (threshold_87)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000477_7713_1 st_1 = {0};
  struct FilterState_R000477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int pivot_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_32_1)
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

  switch (pivot_32_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_32_1 == pivot_32_2);
}

int fn_R000477_7713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int pivot_32 = (aux + st.buffer[1]) & 3;
  switch (pivot_32)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st_1 = {0};
  struct SensorNode_R000477_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int anchor_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_31_1) & 63;
  aux_2 = (aux_2 + anchor_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_52_1)
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

  switch (anchor_52_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_31_1 == anchor_31_2);
  assert(anchor_52_1 == anchor_52_2);
}

int fn_R000477_7713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int anchor_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_31) & 63;
  acc ^= aux;
  int anchor_52 = (aux + st.buffer[1]) & 3;
  switch (anchor_52)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st_1 = {0};
  struct SensorNode_R000477_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_82_1 > 31)
  {
    acc_1 = ((acc_1 + (checksum_82_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_82_2 > 31)
  {
    acc_2 = ((acc_2 + (checksum_82_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_85_1) & 63;
  aux_2 = (aux_2 + bound_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_91_1)
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

  switch (phase_91_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_82_1 == checksum_82_2);
  assert(bound_85_1 == bound_85_2);
  assert(phase_91_1 == phase_91_2);
}

int fn_R000477_7713_6(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_82 > 31)
  {
    acc = ((acc + (checksum_82 * 2)) + 5) & 127;
    aux ^= checksum_82 & 15;
  }
  else
  {
    acc = ((acc - checksum_82) + 11) & 127;
    aux += 3;
  }
  int bound_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_85) & 63;
  acc ^= aux;
  int phase_91 = (aux + st.buffer[1]) & 3;
  switch (phase_91)
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

void fn_R000477_7713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_3 st_1 = {0};
  struct EventLog_R000477_7713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_66_1) & 63;
  aux_2 = (aux_2 + checksum_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_17_1 = local_arr_1[aux_1 % 3];
  int offset_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_17_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_66_1 == checksum_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_17_1 == offset_17_2);
}

int fn_R000477_7713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_66) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_17 = local_arr[aux % 3];
  acc = (acc + (offset_17 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st_1 = {0};
  struct SensorNode_R000477_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int window_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_78_1)
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

  switch (window_78_2)
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
  int accumulator_91_1 = local_arr_1[aux_1 % 3];
  int accumulator_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_91_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_78_1 == window_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_91_1 == accumulator_91_2);
}

int fn_R000477_7713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int window_78 = (aux + st.buffer[1]) & 3;
  switch (window_78)
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
  int accumulator_91 = local_arr[aux % 3];
  acc = (acc + (accumulator_91 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st_1 = {0};
  struct Transaction_R000477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int anchor_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_89_1) & 63;
  aux_2 = (aux_2 + anchor_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_83_1 = local_arr_1[aux_1 % 3];
  int cursor_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_83_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_89_1 == anchor_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_83_1 == cursor_83_2);
}

int fn_R000477_7713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int anchor_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_89) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_83 = local_arr[aux % 3];
  acc = (acc + (cursor_83 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st_1 = {0};
  struct Transaction_R000477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_60_1 = local_arr_1[aux_1 % 3];
  int segment_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_60_2 * 2)) & 127;
  int threshold_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_81_1)
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

  switch (threshold_81_2)
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

  int coefficient_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_49_1 > 46)
  {
    acc_1 = ((acc_1 + (coefficient_49_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_49_2 > 46)
  {
    acc_2 = ((acc_2 + (coefficient_49_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_49_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_60_1 == segment_60_2);
  assert(threshold_81_1 == threshold_81_2);
  assert(coefficient_49_1 == coefficient_49_2);
}

int fn_R000477_7713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int segment_60 = local_arr[aux % 3];
  acc = (acc + (segment_60 * 2)) & 127;
  int threshold_81 = (aux + st.buffer[1]) & 3;
  switch (threshold_81)
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

  int coefficient_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_49 > 46)
  {
    acc = ((acc + (coefficient_49 * 2)) + 5) & 127;
    aux ^= coefficient_49 & 15;
  }
  else
  {
    acc = ((acc - coefficient_49) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000477_7713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000477_7713_1 st_1 = {0};
  struct FilterState_R000477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_17_1 = local_arr_1[aux_1 % 3];
  int weight_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_17_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_17_1 == weight_17_2);
}

int fn_R000477_7713_11(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int weight_17 = local_arr[aux % 3];
  acc = (acc + (weight_17 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st_1 = {0};
  struct Transaction_R000477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int delta_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_80_1 > 37)
  {
    acc_1 = ((acc_1 + (delta_80_1 * 2)) + 5) & 127;
    aux_1 ^= delta_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_80_2 > 37)
  {
    acc_2 = ((acc_2 + (delta_80_2 * 2)) + 5) & 127;
    aux_2 ^= delta_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_59_1 = local_arr_1[aux_1 % 3];
  int delta_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_59_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_80_1 == delta_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_59_1 == delta_59_2);
}

int fn_R000477_7713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int delta_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_80 > 37)
  {
    acc = ((acc + (delta_80 * 2)) + 5) & 127;
    aux ^= delta_80 & 15;
  }
  else
  {
    acc = ((acc - delta_80) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_59 = local_arr[aux % 3];
  acc = (acc + (delta_59 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st_1 = {0};
  struct SensorNode_R000477_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int threshold_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_34_1) & 63;
  aux_2 = (aux_2 + threshold_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_80_1 > 13)
  {
    acc_1 = ((acc_1 + (weight_80_1 * 2)) + 5) & 127;
    aux_1 ^= weight_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_80_2 > 13)
  {
    acc_2 = ((acc_2 + (weight_80_2 * 2)) + 5) & 127;
    aux_2 ^= weight_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_80_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_34_1 == threshold_34_2);
  assert(weight_80_1 == weight_80_2);
}

int fn_R000477_7713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int threshold_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_34) & 63;
  acc ^= aux;
  int weight_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_80 > 13)
  {
    acc = ((acc + (weight_80 * 2)) + 5) & 127;
    aux ^= weight_80 & 15;
  }
  else
  {
    acc = ((acc - weight_80) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000477_7713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st_1 = {0};
  struct Transaction_R000477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int pivot_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_86_1 > 22)
  {
    acc_1 = ((acc_1 + (pivot_86_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_86_2 > 22)
  {
    acc_2 = ((acc_2 + (pivot_86_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_31_1)
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

  switch (factor_31_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_39_1 = local_arr_1[aux_1 % 3];
  int quotient_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_39_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_86_1 == pivot_86_2);
  assert(factor_31_1 == factor_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_39_1 == quotient_39_2);
}

int fn_R000477_7713_14(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int pivot_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_86 > 22)
  {
    acc = ((acc + (pivot_86 * 2)) + 5) & 127;
    aux ^= pivot_86 & 15;
  }
  else
  {
    acc = ((acc - pivot_86) + 11) & 127;
    aux += 3;
  }
  int factor_31 = (aux + st.buffer[1]) & 3;
  switch (factor_31)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_39 = local_arr[aux % 3];
  acc = (acc + (quotient_39 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000477_7713_1 st_1 = {0};
  struct FilterState_R000477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int damping_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_26_1 > 13)
  {
    acc_1 = ((acc_1 + (damping_26_1 * 2)) + 5) & 127;
    aux_1 ^= damping_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_26_2 > 13)
  {
    acc_2 = ((acc_2 + (damping_26_2 * 2)) + 5) & 127;
    aux_2 ^= damping_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_36_1)
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

  switch (cursor_36_2)
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

  int delta_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_13_1) & 63;
  aux_2 = (aux_2 + delta_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_26_1 == damping_26_2);
  assert(cursor_36_1 == cursor_36_2);
  assert(delta_13_1 == delta_13_2);
}

int fn_R000477_7713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int damping_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_26 > 13)
  {
    acc = ((acc + (damping_26 * 2)) + 5) & 127;
    aux ^= damping_26 & 15;
  }
  else
  {
    acc = ((acc - damping_26) + 11) & 127;
    aux += 3;
  }
  int cursor_36 = (aux + st.buffer[1]) & 3;
  switch (cursor_36)
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

  int delta_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_13) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000477_7713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st_1 = {0};
  struct SensorNode_R000477_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int parity_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_10_1) & 63;
  aux_2 = (aux_2 + parity_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_96_1 > 11)
  {
    acc_1 = ((acc_1 + (anchor_96_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_96_2 > 11)
  {
    acc_2 = ((acc_2 + (anchor_96_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_78_1 = local_arr_1[aux_1 % 3];
  int accumulator_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_78_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_10_1 == parity_10_2);
  assert(anchor_96_1 == anchor_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_78_1 == accumulator_78_2);
}

int fn_R000477_7713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int parity_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_10) & 63;
  acc ^= aux;
  int anchor_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_96 > 11)
  {
    acc = ((acc + (anchor_96 * 2)) + 5) & 127;
    aux ^= anchor_96 & 15;
  }
  else
  {
    acc = ((acc - anchor_96) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_78 = local_arr[aux % 3];
  acc = (acc + (accumulator_78 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_3 st_1 = {0};
  struct EventLog_R000477_7713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int index_reg_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_82_1)
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

  switch (index_reg_82_2)
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

  int checksum_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_74_1) & 63;
  aux_2 = (aux_2 + checksum_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_40_1 = local_arr_1[aux_1 % 3];
  int cursor_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_40_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_82_1 == index_reg_82_2);
  assert(checksum_74_1 == checksum_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_40_1 == cursor_40_2);
}

int fn_R000477_7713_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int index_reg_82 = (aux + st.buffer[1]) & 3;
  switch (index_reg_82)
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

  int checksum_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_74) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_40 = local_arr[aux % 3];
  acc = (acc + (cursor_40 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st_1 = {0};
  struct Transaction_R000477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int vector_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_68_1) & 63;
  aux_2 = (aux_2 + vector_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_73_1 > 15)
  {
    acc_1 = ((acc_1 + (bound_73_1 * 2)) + 5) & 127;
    aux_1 ^= bound_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_73_2 > 15)
  {
    acc_2 = ((acc_2 + (bound_73_2 * 2)) + 5) & 127;
    aux_2 ^= bound_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_73_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_68_1 == vector_68_2);
  assert(bound_73_1 == bound_73_2);
}

int fn_R000477_7713_18(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int vector_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_68) & 63;
  acc ^= aux;
  int bound_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_73 > 15)
  {
    acc = ((acc + (bound_73 * 2)) + 5) & 127;
    aux ^= bound_73 & 15;
  }
  else
  {
    acc = ((acc - bound_73) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st_1 = {0};
  struct SensorNode_R000477_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int tally_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_49_1) & 63;
  aux_2 = (aux_2 + tally_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_94_1 > 25)
  {
    acc_1 = ((acc_1 + (index_reg_94_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_94_2 > 25)
  {
    acc_2 = ((acc_2 + (index_reg_94_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_86_1)
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

  switch (quotient_86_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_49_1 == tally_49_2);
  assert(index_reg_94_1 == index_reg_94_2);
  assert(quotient_86_1 == quotient_86_2);
}

int fn_R000477_7713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int tally_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_49) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_94 > 25)
  {
    acc = ((acc + (index_reg_94 * 2)) + 5) & 127;
    aux ^= index_reg_94 & 15;
  }
  else
  {
    acc = ((acc - index_reg_94) + 11) & 127;
    aux += 3;
  }
  int quotient_86 = (aux + st.buffer[1]) & 3;
  switch (quotient_86)
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

void fn_R000477_7713_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000477_7713_1 st_1 = {0};
  struct FilterState_R000477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int pivot_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_88_1) & 63;
  aux_2 = (aux_2 + pivot_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_26_1 = local_arr_1[aux_1 % 3];
  int checksum_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_26_2 * 2)) & 127;
  int quantum_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_55_1 > 29)
  {
    acc_1 = ((acc_1 + (quantum_55_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_55_2 > 29)
  {
    acc_2 = ((acc_2 + (quantum_55_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_48_1)
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

  switch (margin_48_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_88_1 == pivot_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_26_1 == checksum_26_2);
  assert(quantum_55_1 == quantum_55_2);
  assert(margin_48_1 == margin_48_2);
}

int fn_R000477_7713_20(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int pivot_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_88) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int checksum_26 = local_arr[aux % 3];
  acc = (acc + (checksum_26 * 2)) & 127;
  int quantum_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_55 > 29)
  {
    acc = ((acc + (quantum_55 * 2)) + 5) & 127;
    aux ^= quantum_55 & 15;
  }
  else
  {
    acc = ((acc - quantum_55) + 11) & 127;
    aux += 3;
  }
  int margin_48 = (aux + st.buffer[1]) & 3;
  switch (margin_48)
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

void fn_R000477_7713_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st_1 = {0};
  struct Transaction_R000477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int sample_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_42_1) & 63;
  aux_2 = (aux_2 + sample_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_71_1 = local_arr_1[aux_1 % 3];
  int anchor_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_71_2 * 2)) & 127;
  int window_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_44_1 > 32)
  {
    acc_1 = ((acc_1 + (window_44_1 * 2)) + 5) & 127;
    aux_1 ^= window_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_44_2 > 32)
  {
    acc_2 = ((acc_2 + (window_44_2 * 2)) + 5) & 127;
    aux_2 ^= window_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_86_1)
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

  switch (stride_86_2)
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
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_42_1 == sample_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_71_1 == anchor_71_2);
  assert(window_44_1 == window_44_2);
  assert(stride_86_1 == stride_86_2);
}

int fn_R000477_7713_21(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int sample_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_42) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_71 = local_arr[aux % 3];
  acc = (acc + (anchor_71 * 2)) & 127;
  int window_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_44 > 32)
  {
    acc = ((acc + (window_44 * 2)) + 5) & 127;
    aux ^= window_44 & 15;
  }
  else
  {
    acc = ((acc - window_44) + 11) & 127;
    aux += 3;
  }
  int stride_86 = (aux + st.buffer[1]) & 3;
  switch (stride_86)
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

void fn_R000477_7713_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st_1 = {0};
  struct SensorNode_R000477_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int delta_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_36_1)
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

  switch (delta_36_2)
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

  int vector_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_44_1) & 63;
  aux_2 = (aux_2 + vector_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_36_1 == delta_36_2);
  assert(vector_44_1 == vector_44_2);
}

int fn_R000477_7713_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000477_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int delta_36 = (aux + st.buffer[1]) & 3;
  switch (delta_36)
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

  int vector_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_44) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000477_0_1;
  int sec_r000477_0_2;
  int sec_r000477_1_1;
  int sec_r000477_1_2;
  int sec_r000477_2_1;
  int sec_r000477_2_2;
  int sec_r000477_3_1;
  int sec_r000477_3_2;
  int sec_r000477_4_1;
  int sec_r000477_4_2;
  int sec_r000477_5_1;
  int sec_r000477_5_2;
  int sec_r000477_6_1;
  int sec_r000477_6_2;
  int sec_r000477_7_1;
  int sec_r000477_7_2;
  int sec_r000477_8_1;
  int sec_r000477_8_2;
  int sec_r000477_9_1;
  int sec_r000477_9_2;
  int sec_r000477_10_1;
  int sec_r000477_10_2;
  int sec_r000477_11_1;
  int sec_r000477_11_2;
  int sec_r000477_12_1;
  int sec_r000477_12_2;
  int sec_r000477_13_1;
  int sec_r000477_13_2;
  int sec_r000477_14_1;
  int sec_r000477_14_2;
  int sec_r000477_15_1;
  int sec_r000477_15_2;
  int sec_r000477_16_1;
  int sec_r000477_16_2;
  int sec_r000477_17_1;
  int sec_r000477_17_2;
  int sec_r000477_18_1;
  int sec_r000477_18_2;
  int sec_r000477_19_1;
  int sec_r000477_19_2;
  int sec_r000477_20_1;
  int sec_r000477_20_2;
  int pub_r000477_0_1;
  int pub_r000477_0_2;
  int pub_r000477_1_1;
  int pub_r000477_1_2;
  int pub_r000477_2_1;
  int pub_r000477_2_2;
  int pub_r000477_3_1;
  int pub_r000477_3_2;
  int pub_r000477_4_1;
  int pub_r000477_4_2;
  int pub_r000477_5_1;
  int pub_r000477_5_2;
  int pub_r000477_6_1;
  int pub_r000477_6_2;
  int pub_r000477_7_1;
  int pub_r000477_7_2;
  int pub_r000477_8_1;
  int pub_r000477_8_2;
  int pub_r000477_9_1;
  int pub_r000477_9_2;
  int pub_r000477_10_1;
  int pub_r000477_10_2;
  int pub_r000477_11_1;
  int pub_r000477_11_2;
  int pub_r000477_12_1;
  int pub_r000477_12_2;
  int pub_r000477_13_1;
  int pub_r000477_13_2;
  int pub_r000477_14_1;
  int pub_r000477_14_2;
  int pub_r000477_15_1;
  int pub_r000477_15_2;
  int pub_r000477_16_1;
  int pub_r000477_16_2;
  int pub_r000477_17_1;
  int pub_r000477_17_2;
  int pub_r000477_18_1;
  int pub_r000477_18_2;
  int pub_r000477_19_1;
  int pub_r000477_19_2;
  int pub_r000477_20_1;
  int pub_r000477_20_2;
  int pub_r000477_21_1;
  int pub_r000477_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000477_0_1 >= (-100)) && (pub_r000477_0_1 <= 100));
  __CPROVER_assume((pub_r000477_0_2 >= (-100)) && (pub_r000477_0_2 <= 100));
  __CPROVER_assume((pub_r000477_1_1 >= (-100)) && (pub_r000477_1_1 <= 100));
  __CPROVER_assume((pub_r000477_1_2 >= (-100)) && (pub_r000477_1_2 <= 100));
  __CPROVER_assume((pub_r000477_2_1 >= (-100)) && (pub_r000477_2_1 <= 100));
  __CPROVER_assume((pub_r000477_2_2 >= (-100)) && (pub_r000477_2_2 <= 100));
  __CPROVER_assume((pub_r000477_3_1 >= (-100)) && (pub_r000477_3_1 <= 100));
  __CPROVER_assume((pub_r000477_3_2 >= (-100)) && (pub_r000477_3_2 <= 100));
  __CPROVER_assume((pub_r000477_4_1 >= (-100)) && (pub_r000477_4_1 <= 100));
  __CPROVER_assume((pub_r000477_4_2 >= (-100)) && (pub_r000477_4_2 <= 100));
  __CPROVER_assume((pub_r000477_5_1 >= (-100)) && (pub_r000477_5_1 <= 100));
  __CPROVER_assume((pub_r000477_5_2 >= (-100)) && (pub_r000477_5_2 <= 100));
  __CPROVER_assume((pub_r000477_6_1 >= (-100)) && (pub_r000477_6_1 <= 100));
  __CPROVER_assume((pub_r000477_6_2 >= (-100)) && (pub_r000477_6_2 <= 100));
  __CPROVER_assume((pub_r000477_7_1 >= (-100)) && (pub_r000477_7_1 <= 100));
  __CPROVER_assume((pub_r000477_7_2 >= (-100)) && (pub_r000477_7_2 <= 100));
  __CPROVER_assume((pub_r000477_8_1 >= (-100)) && (pub_r000477_8_1 <= 100));
  __CPROVER_assume((pub_r000477_8_2 >= (-100)) && (pub_r000477_8_2 <= 100));
  __CPROVER_assume((pub_r000477_9_1 >= (-100)) && (pub_r000477_9_1 <= 100));
  __CPROVER_assume((pub_r000477_9_2 >= (-100)) && (pub_r000477_9_2 <= 100));
  __CPROVER_assume((pub_r000477_10_1 >= (-100)) && (pub_r000477_10_1 <= 100));
  __CPROVER_assume((pub_r000477_10_2 >= (-100)) && (pub_r000477_10_2 <= 100));
  __CPROVER_assume((pub_r000477_11_1 >= (-100)) && (pub_r000477_11_1 <= 100));
  __CPROVER_assume((pub_r000477_11_2 >= (-100)) && (pub_r000477_11_2 <= 100));
  __CPROVER_assume((pub_r000477_12_1 >= (-100)) && (pub_r000477_12_1 <= 100));
  __CPROVER_assume((pub_r000477_12_2 >= (-100)) && (pub_r000477_12_2 <= 100));
  __CPROVER_assume((pub_r000477_13_1 >= (-100)) && (pub_r000477_13_1 <= 100));
  __CPROVER_assume((pub_r000477_13_2 >= (-100)) && (pub_r000477_13_2 <= 100));
  __CPROVER_assume((pub_r000477_14_1 >= (-100)) && (pub_r000477_14_1 <= 100));
  __CPROVER_assume((pub_r000477_14_2 >= (-100)) && (pub_r000477_14_2 <= 100));
  __CPROVER_assume((pub_r000477_15_1 >= (-100)) && (pub_r000477_15_1 <= 100));
  __CPROVER_assume((pub_r000477_15_2 >= (-100)) && (pub_r000477_15_2 <= 100));
  __CPROVER_assume((pub_r000477_16_1 >= (-100)) && (pub_r000477_16_1 <= 100));
  __CPROVER_assume((pub_r000477_16_2 >= (-100)) && (pub_r000477_16_2 <= 100));
  __CPROVER_assume((pub_r000477_17_1 >= (-100)) && (pub_r000477_17_1 <= 100));
  __CPROVER_assume((pub_r000477_17_2 >= (-100)) && (pub_r000477_17_2 <= 100));
  __CPROVER_assume((pub_r000477_18_1 >= (-100)) && (pub_r000477_18_1 <= 100));
  __CPROVER_assume((pub_r000477_18_2 >= (-100)) && (pub_r000477_18_2 <= 100));
  __CPROVER_assume((pub_r000477_19_1 >= (-100)) && (pub_r000477_19_1 <= 100));
  __CPROVER_assume((pub_r000477_19_2 >= (-100)) && (pub_r000477_19_2 <= 100));
  __CPROVER_assume((pub_r000477_20_1 >= (-100)) && (pub_r000477_20_1 <= 100));
  __CPROVER_assume((pub_r000477_20_2 >= (-100)) && (pub_r000477_20_2 <= 100));
  __CPROVER_assume((pub_r000477_21_1 >= (-100)) && (pub_r000477_21_1 <= 100));
  __CPROVER_assume((pub_r000477_21_2 >= (-100)) && (pub_r000477_21_2 <= 100));
  __CPROVER_assume((sec_r000477_0_1 >= 0) && (sec_r000477_0_1 <= 255));
  __CPROVER_assume((sec_r000477_0_2 >= 0) && (sec_r000477_0_2 <= 255));
  __CPROVER_assume((sec_r000477_1_1 >= 0) && (sec_r000477_1_1 <= 255));
  __CPROVER_assume((sec_r000477_1_2 >= 0) && (sec_r000477_1_2 <= 255));
  __CPROVER_assume((sec_r000477_2_1 >= 0) && (sec_r000477_2_1 <= 255));
  __CPROVER_assume((sec_r000477_2_2 >= 0) && (sec_r000477_2_2 <= 255));
  __CPROVER_assume((sec_r000477_3_1 >= 0) && (sec_r000477_3_1 <= 255));
  __CPROVER_assume((sec_r000477_3_2 >= 0) && (sec_r000477_3_2 <= 255));
  __CPROVER_assume((sec_r000477_4_1 >= 0) && (sec_r000477_4_1 <= 255));
  __CPROVER_assume((sec_r000477_4_2 >= 0) && (sec_r000477_4_2 <= 255));
  __CPROVER_assume((sec_r000477_5_1 >= 0) && (sec_r000477_5_1 <= 255));
  __CPROVER_assume((sec_r000477_5_2 >= 0) && (sec_r000477_5_2 <= 255));
  __CPROVER_assume((sec_r000477_6_1 >= 0) && (sec_r000477_6_1 <= 255));
  __CPROVER_assume((sec_r000477_6_2 >= 0) && (sec_r000477_6_2 <= 255));
  __CPROVER_assume((sec_r000477_7_1 >= 0) && (sec_r000477_7_1 <= 255));
  __CPROVER_assume((sec_r000477_7_2 >= 0) && (sec_r000477_7_2 <= 255));
  __CPROVER_assume((sec_r000477_8_1 >= 0) && (sec_r000477_8_1 <= 255));
  __CPROVER_assume((sec_r000477_8_2 >= 0) && (sec_r000477_8_2 <= 255));
  __CPROVER_assume((sec_r000477_9_1 >= 0) && (sec_r000477_9_1 <= 255));
  __CPROVER_assume((sec_r000477_9_2 >= 0) && (sec_r000477_9_2 <= 255));
  __CPROVER_assume((sec_r000477_10_1 >= 0) && (sec_r000477_10_1 <= 255));
  __CPROVER_assume((sec_r000477_10_2 >= 0) && (sec_r000477_10_2 <= 255));
  __CPROVER_assume((sec_r000477_11_1 >= 0) && (sec_r000477_11_1 <= 255));
  __CPROVER_assume((sec_r000477_11_2 >= 0) && (sec_r000477_11_2 <= 255));
  __CPROVER_assume((sec_r000477_12_1 >= 0) && (sec_r000477_12_1 <= 255));
  __CPROVER_assume((sec_r000477_12_2 >= 0) && (sec_r000477_12_2 <= 255));
  __CPROVER_assume((sec_r000477_13_1 >= 0) && (sec_r000477_13_1 <= 255));
  __CPROVER_assume((sec_r000477_13_2 >= 0) && (sec_r000477_13_2 <= 255));
  __CPROVER_assume((sec_r000477_14_1 >= 0) && (sec_r000477_14_1 <= 255));
  __CPROVER_assume((sec_r000477_14_2 >= 0) && (sec_r000477_14_2 <= 255));
  __CPROVER_assume((sec_r000477_15_1 >= 0) && (sec_r000477_15_1 <= 255));
  __CPROVER_assume((sec_r000477_15_2 >= 0) && (sec_r000477_15_2 <= 255));
  __CPROVER_assume((sec_r000477_16_1 >= 0) && (sec_r000477_16_1 <= 255));
  __CPROVER_assume((sec_r000477_16_2 >= 0) && (sec_r000477_16_2 <= 255));
  __CPROVER_assume((sec_r000477_17_1 >= 0) && (sec_r000477_17_1 <= 255));
  __CPROVER_assume((sec_r000477_17_2 >= 0) && (sec_r000477_17_2 <= 255));
  __CPROVER_assume((sec_r000477_18_1 >= 0) && (sec_r000477_18_1 <= 255));
  __CPROVER_assume((sec_r000477_18_2 >= 0) && (sec_r000477_18_2 <= 255));
  __CPROVER_assume((sec_r000477_19_1 >= 0) && (sec_r000477_19_1 <= 255));
  __CPROVER_assume((sec_r000477_19_2 >= 0) && (sec_r000477_19_2 <= 255));
  __CPROVER_assume((sec_r000477_20_1 >= 0) && (sec_r000477_20_1 <= 255));
  __CPROVER_assume((sec_r000477_20_2 >= 0) && (sec_r000477_20_2 <= 255));
  struct Transaction_R000477_7713_0 st_var_0_1 = {0};
  struct Transaction_R000477_7713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000477_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000477_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000477_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000477_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000477_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000477_0_2 + 7) & 15;
  struct FilterState_R000477_7713_1 st_var_1_1 = {0};
  struct FilterState_R000477_7713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000477_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000477_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000477_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000477_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000477_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000477_0_2 + 9) & 15;
  struct SensorNode_R000477_7713_2 st_var_2_1 = {0};
  struct SensorNode_R000477_7713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000477_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000477_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000477_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000477_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000477_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000477_0_2 + 11) & 15;
  struct EventLog_R000477_7713_3 st_var_3_1 = {0};
  struct EventLog_R000477_7713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000477_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000477_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000477_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000477_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000477_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000477_0_2 + 13) & 15;
  union ColorPixel_R000477_7713_0 u_var_1;
  union ColorPixel_R000477_7713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (st_var_2_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_2_2.buffer[0] ^ 9) & 3;
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

  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = (st_var_2_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_2_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 51)
    {
      chk_sum_1 ^= stage_v_14_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_14_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 51)
    {
      chk_sum_2 ^= stage_v_14_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_15_1 = ((st_var_3_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_3_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 33)
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
  if (stage_v_15_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 33)
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
  int stage_v_16_1 = table_1[0];
  int stage_v_16_2 = table_2[0];
  table_1[0] = (table_1[1] + 33) & 63;
  table_2[0] = (table_2[1] + 33) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = ((st_var_3_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_3_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 45)
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
  if (stage_v_19_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 45)
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
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((st_var_3_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_3_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 46)
    {
      chk_sum_1 ^= stage_v_23_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_23_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 46)
    {
      chk_sum_2 ^= stage_v_23_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 25) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 25) & 15;
  int stage_v_24_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_24_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= stage_v_24_1;
  chk_sum_2 ^= stage_v_24_2;
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 51)
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
  if (stage_v_26_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 51)
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
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (33 & 31);
  int stage_v_28_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (33 & 31);
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= (stage_v_28_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_28_2 << 1) & 127;
  int stage_v_29_1 = table_1[1];
  int stage_v_29_2 = table_2[1];
  table_1[1] = (table_1[2] + 59) & 63;
  table_2[1] = (table_2[2] + 59) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 31) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_2_2.buffer[0] * 3) & 63;
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
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (st_var_1_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_1_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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

  int stage_v_34_1 = ((st_var_2_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_2_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 55)
    {
      chk_sum_1 ^= stage_v_34_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_34_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 55)
    {
      chk_sum_2 ^= stage_v_34_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 36) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= stage_v_35_1;
  chk_sum_2 ^= stage_v_35_2;
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
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 42)
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
  if (stage_v_37_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 42)
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
  int stage_v_38_1 = ((st_var_2_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_2_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 42)
    {
      chk_sum_1 ^= stage_v_38_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_38_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 42)
    {
      chk_sum_2 ^= stage_v_38_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_39_1 = table_1[3];
  int stage_v_39_2 = table_2[3];
  table_1[3] = (table_1[0] + 79) & 63;
  table_2[3] = (table_2[0] + 79) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
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
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((st_var_3_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_3_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 26)
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
  if (stage_v_43_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 26)
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
  int stage_v_44_1 = ((st_var_0_1.buffer[2] * 2) + 139) & 63;
  int stage_v_44_2 = ((st_var_0_2.buffer[2] * 2) + 139) & 63;
  if (stage_v_44_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 25)
    {
      chk_sum_1 ^= stage_v_44_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_44_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 25)
    {
      chk_sum_2 ^= stage_v_44_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 48) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 48) & 15;
  int stage_v_47_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_47_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= stage_v_47_1;
  chk_sum_2 ^= stage_v_47_2;
  int stage_v_48_1 = ((st_var_0_1.buffer[0] * 2) + 151) & 63;
  int stage_v_48_2 = ((st_var_0_2.buffer[0] * 2) + 151) & 63;
  if (stage_v_48_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_48_1) - 5) & 255;
    if (stage_v_48_1 > 51)
    {
      chk_sum_1 ^= stage_v_48_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_48_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_48_2) - 5) & 255;
    if (stage_v_48_2 > 51)
    {
      chk_sum_2 ^= stage_v_48_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_50_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_50_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_51_1 = (st_var_3_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_3_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  int stage_v_52_1 = ((st_var_0_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_0_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 47)
    {
      chk_sum_1 ^= stage_v_52_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_52_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 47)
    {
      chk_sum_2 ^= stage_v_52_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_53_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_53_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_54_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (59 & 31);
  int stage_v_54_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (59 & 31);
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= (stage_v_54_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_54_2 << 1) & 127;
  int stage_v_55_1 = ((st_var_3_1.buffer[1] * 2) + 172) & 63;
  int stage_v_55_2 = ((st_var_3_2.buffer[1] * 2) + 172) & 63;
  if (stage_v_55_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_55_1) - 5) & 255;
    if (stage_v_55_1 > 35)
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
  if (stage_v_55_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_55_2) - 5) & 255;
    if (stage_v_55_2 > 35)
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
  int stage_v_56_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_56_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_56_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_56_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (st_var_2_1.buffer[0] ^ 61) & 3;
  int stage_v_58_2 = (st_var_2_2.buffer[0] ^ 61) & 3;
  switch (stage_v_58_1)
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

  switch (stage_v_58_2)
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

  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 60) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 60) & 15;
  int stage_v_59_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_59_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= stage_v_59_1;
  chk_sum_2 ^= stage_v_59_2;
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
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_61_1 = ((stage_v_61_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_61_2 = ((stage_v_61_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (st_var_2_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_2_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = table_1[3];
  int stage_v_63_2 = table_2[3];
  table_1[3] = (table_1[0] + 127) & 63;
  table_2[3] = (table_2[0] + 127) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = table_1[0];
  int stage_v_64_2 = table_2[0];
  table_1[0] = (table_1[1] + 129) & 63;
  table_2[0] = (table_2[1] + 129) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (70 & 31);
  int stage_v_65_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (70 & 31);
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= (stage_v_65_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_65_2 << 1) & 127;
  int stage_v_66_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (71 & 31);
  int stage_v_66_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (71 & 31);
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= (stage_v_66_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_66_2 << 1) & 127;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 68) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 68) & 15;
  int stage_v_67_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_67_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= stage_v_67_1;
  chk_sum_2 ^= stage_v_67_2;
  int stage_v_68_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_68_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_68_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_68_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_69_1 = ((st_var_1_1.buffer[0] * 2) + 214) & 63;
  int stage_v_69_2 = ((st_var_1_2.buffer[0] * 2) + 214) & 63;
  if (stage_v_69_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_69_1) - 5) & 255;
    if (stage_v_69_1 > 44)
    {
      chk_sum_1 ^= stage_v_69_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_69_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_69_2) - 5) & 255;
    if (stage_v_69_2 > 44)
    {
      chk_sum_2 ^= stage_v_69_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_70_1 = (st_var_2_1.buffer[0] ^ 73) & 3;
  int stage_v_70_2 = (st_var_2_2.buffer[0] ^ 73) & 3;
  switch (stage_v_70_1)
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

  switch (stage_v_70_2)
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

  int stage_v_71_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_71_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_72_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_72_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_73_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (78 & 31);
  int stage_v_73_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (78 & 31);
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= (stage_v_73_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_73_2 << 1) & 127;
  int stage_v_74_1 = table_1[2];
  int stage_v_74_2 = table_2[2];
  table_1[2] = (table_1[3] + 149) & 63;
  table_2[2] = (table_2[3] + 149) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = table_1[3];
  int stage_v_75_2 = table_2[3];
  table_1[3] = (table_1[0] + 151) & 63;
  table_2[3] = (table_2[0] + 151) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = table_1[0];
  int stage_v_76_2 = table_2[0];
  table_1[0] = (table_1[1] + 153) & 63;
  table_2[0] = (table_2[1] + 153) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((st_var_1_1.buffer[2] * 2) + 238) & 63;
  int stage_v_77_2 = ((st_var_1_2.buffer[2] * 2) + 238) & 63;
  if (stage_v_77_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_77_1) - 5) & 255;
    if (stage_v_77_1 > 41)
    {
      chk_sum_1 ^= stage_v_77_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_77_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_77_2) - 5) & 255;
    if (stage_v_77_2 > 41)
    {
      chk_sum_2 ^= stage_v_77_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_78_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_78_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_78_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_78_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_79_1 = ((st_var_3_1.buffer[1] * 2) + 244) & 63;
  int stage_v_79_2 = ((st_var_3_2.buffer[1] * 2) + 244) & 63;
  if (stage_v_79_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_79_1) - 5) & 255;
    if (stage_v_79_1 > 52)
    {
      chk_sum_1 ^= stage_v_79_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_79_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_79_2) - 5) & 255;
    if (stage_v_79_2 > 52)
    {
      chk_sum_2 ^= stage_v_79_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 81) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 81) & 15;
  int stage_v_80_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_80_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= stage_v_80_1;
  chk_sum_2 ^= stage_v_80_2;
  int stage_v_81_1 = (st_var_1_1.buffer[0] ^ 84) & 3;
  int stage_v_81_2 = (st_var_1_2.buffer[0] ^ 84) & 3;
  switch (stage_v_81_1)
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

  switch (stage_v_81_2)
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

  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_82_1 = ((stage_v_82_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_82_2 = ((stage_v_82_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_83_1 = ((stage_v_83_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_83_2 = ((stage_v_83_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_84_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_85_1 = ((st_var_1_1.buffer[1] * 2) + 262) & 63;
  int stage_v_85_2 = ((st_var_1_2.buffer[1] * 2) + 262) & 63;
  if (stage_v_85_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_85_1) - 5) & 255;
    if (stage_v_85_1 > 48)
    {
      chk_sum_1 ^= stage_v_85_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_85_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_85_2) - 5) & 255;
    if (stage_v_85_2 > 48)
    {
      chk_sum_2 ^= stage_v_85_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_86_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_86_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_87_1 = ((st_var_3_1.buffer[0] * 2) + 268) & 63;
  int stage_v_87_2 = ((st_var_3_2.buffer[0] * 2) + 268) & 63;
  if (stage_v_87_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_87_1) - 5) & 255;
    if (stage_v_87_1 > 34)
    {
      chk_sum_1 ^= stage_v_87_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_87_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_87_2) - 5) & 255;
    if (stage_v_87_2 > 34)
    {
      chk_sum_2 ^= stage_v_87_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_88_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_88_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_88_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_88_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_89_1 = ((st_var_1_1.buffer[2] * 2) + 274) & 63;
  int stage_v_89_2 = ((st_var_1_2.buffer[2] * 2) + 274) & 63;
  if (stage_v_89_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_89_1) - 5) & 255;
    if (stage_v_89_1 > 46)
    {
      chk_sum_1 ^= stage_v_89_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_89_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_89_2) - 5) & 255;
    if (stage_v_89_2 > 46)
    {
      chk_sum_2 ^= stage_v_89_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_90_1 = table_1[2];
  int stage_v_90_2 = table_2[2];
  table_1[2] = (table_1[3] + 181) & 63;
  table_2[2] = (table_2[3] + 181) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 92) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 92) & 15;
  int stage_v_91_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_91_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  chk_sum_1 ^= stage_v_91_1;
  chk_sum_2 ^= stage_v_91_2;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000477_2_1 & 1) != 0)
  {
    if ((sec_r000477_15_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000477_1_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000477_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000477_1_1 + 7) & 127;
  }
  if ((sec_r000477_2_2 & 1) != 0)
  {
    if ((sec_r000477_15_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000477_1_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000477_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000477_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000477_20_1 & 1) != 0)
  {
    if ((sec_r000477_20_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000477_14_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000477_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000477_14_1 + 7) & 127;
  }
  if ((sec_r000477_20_2 & 1) != 0)
  {
    if ((sec_r000477_20_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000477_14_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000477_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000477_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000477_11_1 & 1) != 0)
  {
    if ((sec_r000477_2_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000477_7_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000477_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000477_7_1 + 7) & 127;
  }
  if ((sec_r000477_11_2 & 1) != 0)
  {
    if ((sec_r000477_2_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000477_7_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000477_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000477_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000477_15_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000477_17_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000477_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000477_17_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000477_15_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000477_17_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000477_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000477_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000477_11_1 & 1) != 0)
  {
    if ((sec_r000477_5_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000477_8_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000477_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000477_8_1 + 7) & 127;
  }
  if ((sec_r000477_11_2 & 1) != 0)
  {
    if ((sec_r000477_5_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000477_8_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000477_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000477_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000477_20_1 & 1) != 0)
  {
    if ((sec_r000477_19_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000477_18_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000477_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000477_18_1 + 7) & 127;
  }
  if ((sec_r000477_20_2 & 1) != 0)
  {
    if ((sec_r000477_19_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000477_18_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000477_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000477_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000477_15_1 & 1) != 0)
  {
    if ((sec_r000477_12_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000477_12_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000477_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000477_12_1 + 7) & 127;
  }
  if ((sec_r000477_15_2 & 1) != 0)
  {
    if ((sec_r000477_12_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000477_12_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000477_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000477_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000477_4_1 & 1) != 0)
  {
    if ((sec_r000477_14_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000477_1_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000477_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000477_1_1 + 7) & 127;
  }
  if ((sec_r000477_4_2 & 1) != 0)
  {
    if ((sec_r000477_14_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000477_1_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000477_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000477_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000477_17_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000477_6_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000477_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000477_6_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000477_17_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000477_6_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000477_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000477_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000477_9_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000477_18_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000477_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000477_18_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000477_9_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000477_18_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000477_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000477_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000477_5_1 & 1) != 0)
  {
    if ((sec_r000477_17_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000477_20_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000477_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000477_20_1 + 7) & 127;
  }
  if ((sec_r000477_5_2 & 1) != 0)
  {
    if ((sec_r000477_17_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000477_20_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000477_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000477_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000477_3_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000477_9_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000477_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000477_9_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000477_3_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000477_9_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000477_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000477_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000477_20_1 & 1) != 0)
  {
    if ((sec_r000477_15_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000477_2_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000477_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000477_2_1 + 7) & 127;
  }
  if ((sec_r000477_20_2 & 1) != 0)
  {
    if ((sec_r000477_15_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000477_2_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000477_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000477_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000477_9_1 & 1) != 0)
  {
    if ((sec_r000477_3_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000477_14_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000477_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000477_14_1 + 7) & 127;
  }
  if ((sec_r000477_9_2 & 1) != 0)
  {
    if ((sec_r000477_3_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000477_14_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000477_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000477_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000477_2_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000477_13_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000477_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000477_13_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000477_2_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000477_13_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000477_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000477_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000477_16_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000477_4_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000477_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000477_4_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000477_16_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000477_4_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000477_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000477_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000477_18_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000477_0_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000477_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000477_0_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000477_18_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000477_0_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000477_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000477_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000477_18_1 & 1) != 0)
  {
    if ((sec_r000477_11_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000477_14_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000477_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000477_14_1 + 7) & 127;
  }
  if ((sec_r000477_18_2 & 1) != 0)
  {
    if ((sec_r000477_11_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000477_14_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000477_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000477_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000477_16_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000477_20_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000477_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000477_20_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000477_16_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000477_20_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000477_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000477_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000477_2_1 & 1) != 0)
  {
    if ((sec_r000477_10_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000477_19_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000477_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000477_19_1 + 7) & 127;
  }
  if ((sec_r000477_2_2 & 1) != 0)
  {
    if ((sec_r000477_10_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000477_19_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000477_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000477_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000477_16_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000477_0_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000477_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000477_0_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000477_16_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000477_0_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000477_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000477_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000477_1_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000477_7_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000477_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000477_7_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000477_1_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000477_7_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000477_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000477_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000477_17_1 & 1) != 0)
  {
    if ((sec_r000477_6_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000477_8_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000477_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000477_8_1 + 7) & 127;
  }
  if ((sec_r000477_17_2 & 1) != 0)
  {
    if ((sec_r000477_6_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000477_8_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000477_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000477_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000477_17_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000477_2_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000477_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000477_2_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000477_17_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000477_2_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000477_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000477_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000477_15_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000477_18_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000477_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000477_18_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000477_15_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000477_18_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000477_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000477_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000477_12_1 & 1) != 0)
  {
    if ((sec_r000477_5_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000477_16_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000477_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000477_16_1 + 7) & 127;
  }
  if ((sec_r000477_12_2 & 1) != 0)
  {
    if ((sec_r000477_5_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000477_16_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000477_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000477_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000477_5_1 & 1) != 0)
  {
    if ((sec_r000477_11_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000477_7_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000477_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000477_7_1 + 7) & 127;
  }
  if ((sec_r000477_5_2 & 1) != 0)
  {
    if ((sec_r000477_11_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000477_7_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000477_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000477_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((sec_r000477_4_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000477_19_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000477_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000477_19_1 + 7) & 127;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((sec_r000477_4_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000477_19_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000477_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000477_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000477_8_1 & 1) != 0)
  {
    if ((sec_r000477_16_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000477_5_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000477_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000477_5_1 + 7) & 127;
  }
  if ((sec_r000477_8_2 & 1) != 0)
  {
    if ((sec_r000477_16_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000477_5_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000477_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000477_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000477_7_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000477_2_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000477_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000477_2_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000477_7_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000477_2_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000477_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000477_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000477_1_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000477_16_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000477_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000477_16_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000477_1_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000477_16_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000477_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000477_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000477_14_1 & 1) != 0)
  {
    if ((sec_r000477_14_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000477_5_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000477_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000477_5_1 + 7) & 127;
  }
  if ((sec_r000477_14_2 & 1) != 0)
  {
    if ((sec_r000477_14_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000477_5_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000477_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000477_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000477_11_1 & 1) != 0)
  {
    if ((sec_r000477_19_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000477_1_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000477_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000477_1_1 + 7) & 127;
  }
  if ((sec_r000477_11_2 & 1) != 0)
  {
    if ((sec_r000477_19_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000477_1_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000477_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000477_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000477_9_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000477_5_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000477_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000477_5_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000477_9_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000477_5_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000477_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000477_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000477_5_1 & 1) != 0)
  {
    if ((sec_r000477_4_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000477_5_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000477_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000477_5_1 + 7) & 127;
  }
  if ((sec_r000477_5_2 & 1) != 0)
  {
    if ((sec_r000477_4_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000477_5_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000477_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000477_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000477_1_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000477_11_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000477_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000477_11_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000477_1_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000477_11_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000477_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000477_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000477_17_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000477_19_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000477_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000477_19_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000477_17_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000477_19_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000477_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000477_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000477_11_1 & 1) != 0)
  {
    if ((sec_r000477_14_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000477_12_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000477_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000477_12_1 + 7) & 127;
  }
  if ((sec_r000477_11_2 & 1) != 0)
  {
    if ((sec_r000477_14_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000477_12_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000477_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000477_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000477_16_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000477_0_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000477_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000477_0_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000477_16_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000477_0_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000477_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000477_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000477_3_1 & 1) != 0)
  {
    if ((sec_r000477_5_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000477_16_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000477_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000477_16_1 + 7) & 127;
  }
  if ((sec_r000477_3_2 & 1) != 0)
  {
    if ((sec_r000477_5_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000477_16_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000477_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000477_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000477_7_1 & 1) != 0)
  {
    if ((sec_r000477_13_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000477_19_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000477_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000477_19_1 + 7) & 127;
  }
  if ((sec_r000477_7_2 & 1) != 0)
  {
    if ((sec_r000477_13_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000477_19_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000477_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000477_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000477_15_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000477_5_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000477_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000477_5_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000477_15_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000477_5_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000477_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000477_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((sec_r000477_10_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000477_12_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000477_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000477_12_1 + 7) & 127;
  }
  if ((stage_v_129_2 & 1) != 0)
  {
    if ((sec_r000477_10_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000477_12_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000477_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000477_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000477_1_1 & 1) != 0)
  {
    if ((sec_r000477_15_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000477_1_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000477_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000477_1_1 + 7) & 127;
  }
  if ((sec_r000477_1_2 & 1) != 0)
  {
    if ((sec_r000477_15_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000477_1_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000477_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000477_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000477_9_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000477_1_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000477_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000477_1_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000477_9_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000477_1_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000477_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000477_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((sec_r000477_13_1 & 1) != 0)
  {
    if ((sec_r000477_2_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000477_21_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000477_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000477_21_1 + 7) & 127;
  }
  if ((sec_r000477_13_2 & 1) != 0)
  {
    if ((sec_r000477_2_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000477_21_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000477_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000477_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000477_18_1 & 1) != 0)
  {
    if ((sec_r000477_5_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000477_15_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000477_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000477_15_1 + 7) & 127;
  }
  if ((sec_r000477_18_2 & 1) != 0)
  {
    if ((sec_r000477_5_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000477_15_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000477_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000477_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000477_10_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000477_14_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000477_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000477_14_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000477_10_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000477_14_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000477_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000477_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_139_1 & 1) != 0)
  {
    if ((sec_r000477_15_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000477_15_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000477_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000477_15_1 + 7) & 127;
  }
  if ((stage_v_139_2 & 1) != 0)
  {
    if ((sec_r000477_15_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000477_15_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000477_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000477_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((sec_r000477_16_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000477_20_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000477_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000477_20_1 + 7) & 127;
  }
  if ((stage_v_138_2 & 1) != 0)
  {
    if ((sec_r000477_16_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000477_20_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000477_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000477_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((sec_r000477_2_1 & 1) != 0)
  {
    if ((sec_r000477_16_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000477_17_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000477_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000477_17_1 + 7) & 127;
  }
  if ((sec_r000477_2_2 & 1) != 0)
  {
    if ((sec_r000477_16_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000477_17_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000477_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000477_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((sec_r000477_17_1 & 1) != 0)
  {
    if ((sec_r000477_16_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000477_14_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000477_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000477_14_1 + 7) & 127;
  }
  if ((sec_r000477_17_2 & 1) != 0)
  {
    if ((sec_r000477_16_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000477_14_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000477_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000477_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r000477_6_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000477_20_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000477_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000477_20_1 + 7) & 127;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r000477_6_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000477_20_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000477_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000477_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000477_9_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000477_1_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000477_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000477_1_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000477_9_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000477_1_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000477_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000477_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((sec_r000477_11_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000477_6_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000477_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000477_6_1 + 7) & 127;
  }
  if ((stage_v_134_2 & 1) != 0)
  {
    if ((sec_r000477_11_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000477_6_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000477_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000477_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((sec_r000477_9_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000477_5_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000477_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000477_5_1 + 7) & 127;
  }
  if ((stage_v_141_2 & 1) != 0)
  {
    if ((sec_r000477_9_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000477_5_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000477_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000477_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000477_6_1 & 1) != 0)
  {
    if ((sec_r000477_1_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000477_18_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000477_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000477_18_1 + 7) & 127;
  }
  if ((sec_r000477_6_2 & 1) != 0)
  {
    if ((sec_r000477_1_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000477_18_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000477_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000477_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r000477_1_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000477_14_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000477_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000477_14_1 + 7) & 127;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r000477_1_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000477_14_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000477_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000477_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000477_1_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000477_16_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000477_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000477_16_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000477_1_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000477_16_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000477_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000477_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000477_3_1 & 1) != 0)
  {
    if ((sec_r000477_7_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000477_14_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000477_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000477_14_1 + 7) & 127;
  }
  if ((sec_r000477_3_2 & 1) != 0)
  {
    if ((sec_r000477_7_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000477_14_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000477_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000477_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((sec_r000477_15_1 & 1) != 0)
  {
    if ((sec_r000477_17_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000477_3_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000477_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000477_3_1 + 7) & 127;
  }
  if ((sec_r000477_15_2 & 1) != 0)
  {
    if ((sec_r000477_17_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000477_3_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000477_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000477_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((sec_r000477_16_1 & 1) != 0)
  {
    if ((sec_r000477_0_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000477_12_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000477_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000477_12_1 + 7) & 127;
  }
  if ((sec_r000477_16_2 & 1) != 0)
  {
    if ((sec_r000477_0_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000477_12_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000477_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000477_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000477_3_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000477_9_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000477_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000477_9_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000477_3_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000477_9_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000477_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000477_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((sec_r000477_5_1 & 1) != 0)
  {
    if ((sec_r000477_12_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000477_11_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000477_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000477_11_1 + 7) & 127;
  }
  if ((sec_r000477_5_2 & 1) != 0)
  {
    if ((sec_r000477_12_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000477_11_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000477_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000477_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((sec_r000477_4_1 & 1) != 0)
  {
    if ((sec_r000477_10_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000477_13_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000477_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000477_13_1 + 7) & 127;
  }
  if ((sec_r000477_4_2 & 1) != 0)
  {
    if ((sec_r000477_10_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000477_13_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000477_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000477_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((stage_v_139_1 & 1) != 0)
  {
    if ((sec_r000477_6_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000477_8_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000477_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000477_8_1 + 7) & 127;
  }
  if ((stage_v_139_2 & 1) != 0)
  {
    if ((sec_r000477_6_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000477_8_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000477_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000477_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((sec_r000477_12_1 & 1) != 0)
  {
    if ((sec_r000477_17_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000477_12_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000477_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000477_12_1 + 7) & 127;
  }
  if ((sec_r000477_12_2 & 1) != 0)
  {
    if ((sec_r000477_17_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000477_12_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000477_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000477_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000477_17_1 & 2) != 0)
    {
      stage_v_159_1 = (pub_r000477_1_1 + 31) & 127;
    }
    else
    {
      stage_v_159_1 = (pub_r000477_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_1 = (pub_r000477_1_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000477_17_2 & 2) != 0)
    {
      stage_v_159_2 = (pub_r000477_1_2 + 31) & 127;
    }
    else
    {
      stage_v_159_2 = (pub_r000477_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_2 = (pub_r000477_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((sec_r000477_14_1 & 1) != 0)
  {
    if ((sec_r000477_9_1 & 2) != 0)
    {
      stage_v_160_1 = (pub_r000477_2_1 + 31) & 127;
    }
    else
    {
      stage_v_160_1 = (pub_r000477_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_1 = (pub_r000477_2_1 + 7) & 127;
  }
  if ((sec_r000477_14_2 & 1) != 0)
  {
    if ((sec_r000477_9_2 & 2) != 0)
    {
      stage_v_160_2 = (pub_r000477_2_2 + 31) & 127;
    }
    else
    {
      stage_v_160_2 = (pub_r000477_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_2 = (pub_r000477_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((sec_r000477_9_1 & 1) != 0)
  {
    if ((sec_r000477_8_1 & 2) != 0)
    {
      stage_v_161_1 = (pub_r000477_6_1 + 31) & 127;
    }
    else
    {
      stage_v_161_1 = (pub_r000477_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_1 = (pub_r000477_6_1 + 7) & 127;
  }
  if ((sec_r000477_9_2 & 1) != 0)
  {
    if ((sec_r000477_8_2 & 2) != 0)
    {
      stage_v_161_2 = (pub_r000477_6_2 + 31) & 127;
    }
    else
    {
      stage_v_161_2 = (pub_r000477_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_2 = (pub_r000477_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((sec_r000477_12_1 & 2) != 0)
    {
      stage_v_162_1 = (pub_r000477_17_1 + 31) & 127;
    }
    else
    {
      stage_v_162_1 = (pub_r000477_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_1 = (pub_r000477_17_1 + 7) & 127;
  }
  if ((stage_v_157_2 & 1) != 0)
  {
    if ((sec_r000477_12_2 & 2) != 0)
    {
      stage_v_162_2 = (pub_r000477_17_2 + 31) & 127;
    }
    else
    {
      stage_v_162_2 = (pub_r000477_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_2 = (pub_r000477_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((sec_r000477_17_1 & 2) != 0)
    {
      stage_v_163_1 = (pub_r000477_8_1 + 31) & 127;
    }
    else
    {
      stage_v_163_1 = (pub_r000477_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_1 = (pub_r000477_8_1 + 7) & 127;
  }
  if ((stage_v_150_2 & 1) != 0)
  {
    if ((sec_r000477_17_2 & 2) != 0)
    {
      stage_v_163_2 = (pub_r000477_8_2 + 31) & 127;
    }
    else
    {
      stage_v_163_2 = (pub_r000477_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_2 = (pub_r000477_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000477_2_1 == pub_r000477_2_2);
  __CPROVER_assume(pub_r000477_17_1 == pub_r000477_17_2);
  __CPROVER_assume(sec_r000477_1_1 != sec_r000477_1_2);
  __CPROVER_assume(sec_r000477_12_1 != sec_r000477_12_2);
  __CPROVER_assume(pub_r000477_8_1 == pub_r000477_8_2);
  __CPROVER_assume(sec_r000477_19_1 != sec_r000477_19_2);
  __CPROVER_assume(sec_r000477_0_1 != sec_r000477_0_2);
  __CPROVER_assume(pub_r000477_1_1 == pub_r000477_1_2);
  __CPROVER_assume(sec_r000477_15_1 != sec_r000477_15_2);
  __CPROVER_assume(pub_r000477_3_1 == pub_r000477_3_2);
  __CPROVER_assume(sec_r000477_6_1 != sec_r000477_6_2);
  __CPROVER_assume(sec_r000477_4_1 != sec_r000477_4_2);
  __CPROVER_assume(sec_r000477_18_1 != sec_r000477_18_2);
  __CPROVER_assume(pub_r000477_13_1 == pub_r000477_13_2);
  __CPROVER_assume(sec_r000477_10_1 != sec_r000477_10_2);
  __CPROVER_assume(sec_r000477_11_1 != sec_r000477_11_2);
  __CPROVER_assume(sec_r000477_7_1 != sec_r000477_7_2);
  __CPROVER_assume(pub_r000477_12_1 == pub_r000477_12_2);
  __CPROVER_assume(sec_r000477_5_1 != sec_r000477_5_2);
  __CPROVER_assume(sec_r000477_2_1 != sec_r000477_2_2);
  __CPROVER_assume(pub_r000477_6_1 == pub_r000477_6_2);
  __CPROVER_assume(pub_r000477_0_1 == pub_r000477_0_2);
  __CPROVER_assume(sec_r000477_9_1 != sec_r000477_9_2);
  __CPROVER_assume(pub_r000477_11_1 == pub_r000477_11_2);
  __CPROVER_assume(pub_r000477_15_1 == pub_r000477_15_2);
  __CPROVER_assume(pub_r000477_19_1 == pub_r000477_19_2);
  __CPROVER_assume(pub_r000477_7_1 == pub_r000477_7_2);
  __CPROVER_assume(sec_r000477_3_1 != sec_r000477_3_2);
  __CPROVER_assume(pub_r000477_10_1 == pub_r000477_10_2);
  __CPROVER_assume(pub_r000477_20_1 == pub_r000477_20_2);
  __CPROVER_assume(pub_r000477_9_1 == pub_r000477_9_2);
  __CPROVER_assume(pub_r000477_4_1 == pub_r000477_4_2);
  __CPROVER_assume(sec_r000477_20_1 != sec_r000477_20_2);
  __CPROVER_assume(pub_r000477_21_1 == pub_r000477_21_2);
  __CPROVER_assume(sec_r000477_16_1 != sec_r000477_16_2);
  __CPROVER_assume(sec_r000477_17_1 != sec_r000477_17_2);
  __CPROVER_assume(pub_r000477_5_1 == pub_r000477_5_2);
  __CPROVER_assume(sec_r000477_13_1 != sec_r000477_13_2);
  __CPROVER_assume(pub_r000477_16_1 == pub_r000477_16_2);
  __CPROVER_assume(sec_r000477_8_1 != sec_r000477_8_2);
  __CPROVER_assume(sec_r000477_14_1 != sec_r000477_14_2);
  __CPROVER_assume(pub_r000477_14_1 == pub_r000477_14_2);
  __CPROVER_assume(pub_r000477_18_1 == pub_r000477_18_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.calib == st_var_2_2.calib);
  assert(st_var_2_1.reading == st_var_2_2.reading);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.status == st_var_2_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.seq == st_var_3_2.seq);
  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
  assert(st_var_3_1.code == st_var_3_2.code);
  assert(st_var_3_1.severity == st_var_3_2.severity);
  assert(st_var_3_1.signature == st_var_3_2.signature);
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
}


