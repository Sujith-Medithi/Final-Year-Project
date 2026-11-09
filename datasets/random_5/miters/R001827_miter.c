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
struct DeviceConfig_R001827_2713_0
{
  int id;
  int baud_rate;
  unsigned char stop_bits;
  short parity;
  int buffer[3];
};
struct EventLog_R001827_2713_1
{
  unsigned char facility;
  int seq;
  short code;
  int buffer[3];
};
struct StreamBuffer_R001827_2713_2
{
  int tail;
  int checksum;
  int head;
  int state;
  int capacity;
  int watermark;
  int buffer[3];
};
union PacketPayload_R001827_2713_0
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
void fn_R001827_2713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001827_2713_1 st_1 = {0};
  struct EventLog_R001827_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int factor_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_35_1)
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

  switch (factor_35_2)
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

  int accumulator_12_1 = 0;
  int accumulator_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_12_1 = ((accumulator_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_12_2 = ((accumulator_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_12_1) & 127;
    acc_2 = (acc_2 + accumulator_12_2) & 127;
  }

  int mask_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_71_1 > 32)
  {
    acc_1 = ((acc_1 + (mask_71_1 * 2)) + 5) & 127;
    aux_1 ^= mask_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_71_2 > 32)
  {
    acc_2 = ((acc_2 + (mask_71_2 * 2)) + 5) & 127;
    aux_2 ^= mask_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_71_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_35_1 == factor_35_2);
  assert(accumulator_12_1 == accumulator_12_2);
  assert(mask_71_1 == mask_71_2);
}

int fn_R001827_2713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001827_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int factor_35 = (aux + st.buffer[1]) & 3;
  switch (factor_35)
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

  int accumulator_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_12 = ((accumulator_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_12) & 127;
  }

  int mask_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_71 > 32)
  {
    acc = ((acc + (mask_71 * 2)) + 5) & 127;
    aux ^= mask_71 & 15;
  }
  else
  {
    acc = ((acc - mask_71) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001827_2713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001827_2713_1 st_1 = {0};
  struct EventLog_R001827_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int delta_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_56_1) & 63;
  aux_2 = (aux_2 + delta_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_92_1 > 25)
  {
    acc_1 = ((acc_1 + (index_reg_92_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_92_2 > 25)
  {
    acc_2 = ((acc_2 + (index_reg_92_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_92_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_56_1 == delta_56_2);
  assert(index_reg_92_1 == index_reg_92_2);
}

int fn_R001827_2713_1(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001827_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int delta_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_56) & 63;
  acc ^= aux;
  int index_reg_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_92 > 25)
  {
    acc = ((acc + (index_reg_92 * 2)) + 5) & 127;
    aux ^= index_reg_92 & 15;
  }
  else
  {
    acc = ((acc - index_reg_92) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001827_2713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001827_2713_0 st_1 = {0};
  struct DeviceConfig_R001827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int factor_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_86_1) & 63;
  aux_2 = (aux_2 + factor_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_39_1)
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

  switch (coefficient_39_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_86_1 == factor_86_2);
  assert(coefficient_39_1 == coefficient_39_2);
}

int fn_R001827_2713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int factor_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_86) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_39 = (aux + st.buffer[1]) & 3;
  switch (coefficient_39)
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

void fn_R001827_2713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001827_2713_2 st_1 = {0};
  struct StreamBuffer_R001827_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
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

  int offset_33_1 = 0;
  int offset_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_33_1 = ((offset_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_33_2 = ((offset_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_33_1) & 127;
    acc_2 = (acc_2 + offset_33_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_91_1 == phase_91_2);
  assert(offset_33_1 == offset_33_2);
}

int fn_R001827_2713_3(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001827_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
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

  int offset_33 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_33 = ((offset_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_33) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001827_2713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001827_2713_1 st_1 = {0};
  struct EventLog_R001827_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_87_1 = local_arr_1[aux_1 % 3];
  int parity_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_87_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_87_1 == parity_87_2);
}

int fn_R001827_2713_4(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001827_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int parity_87 = local_arr[aux % 3];
  acc = (acc + (parity_87 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001827_2713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001827_2713_1 st_1 = {0};
  struct EventLog_R001827_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quantum_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_32_1)
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

  switch (quantum_32_2)
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

  int vector_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_14_1) & 63;
  aux_2 = (aux_2 + vector_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_28_1 = local_arr_1[aux_1 % 3];
  int metric_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_32_1 == quantum_32_2);
  assert(vector_14_1 == vector_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_28_1 == metric_28_2);
}

int fn_R001827_2713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001827_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quantum_32 = (aux + st.buffer[1]) & 3;
  switch (quantum_32)
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

  int vector_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_14) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int metric_28 = local_arr[aux % 3];
  acc = (acc + (metric_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001827_2713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001827_2713_0 st_1 = {0};
  struct DeviceConfig_R001827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int pivot_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_88_1)
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

  switch (pivot_88_2)
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
  int vector_35_1 = local_arr_1[aux_1 % 3];
  int vector_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_35_2 * 2)) & 127;
  int damping_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_38_1 > 28)
  {
    acc_1 = ((acc_1 + (damping_38_1 * 2)) + 5) & 127;
    aux_1 ^= damping_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_38_2 > 28)
  {
    acc_2 = ((acc_2 + (damping_38_2 * 2)) + 5) & 127;
    aux_2 ^= damping_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_53_1) & 63;
  aux_2 = (aux_2 + margin_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_88_1 == pivot_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_35_1 == vector_35_2);
  assert(damping_38_1 == damping_38_2);
  assert(margin_53_1 == margin_53_2);
}

int fn_R001827_2713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int pivot_88 = (aux + st.buffer[1]) & 3;
  switch (pivot_88)
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
  int vector_35 = local_arr[aux % 3];
  acc = (acc + (vector_35 * 2)) & 127;
  int damping_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_38 > 28)
  {
    acc = ((acc + (damping_38 * 2)) + 5) & 127;
    aux ^= damping_38 & 15;
  }
  else
  {
    acc = ((acc - damping_38) + 11) & 127;
    aux += 3;
  }
  int margin_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_53) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001827_2713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001827_2713_0 st_1 = {0};
  struct DeviceConfig_R001827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_11_1 = local_arr_1[aux_1 % 3];
  int bound_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_11_2 * 2)) & 127;
  int metric_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_19_1 > 30)
  {
    acc_1 = ((acc_1 + (metric_19_1 * 2)) + 5) & 127;
    aux_1 ^= metric_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_19_2 > 30)
  {
    acc_2 = ((acc_2 + (metric_19_2 * 2)) + 5) & 127;
    aux_2 ^= metric_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_54_1)
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

  switch (sample_54_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_11_1 == bound_11_2);
  assert(metric_19_1 == metric_19_2);
  assert(sample_54_1 == sample_54_2);
}

int fn_R001827_2713_7(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int bound_11 = local_arr[aux % 3];
  acc = (acc + (bound_11 * 2)) & 127;
  int metric_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_19 > 30)
  {
    acc = ((acc + (metric_19 * 2)) + 5) & 127;
    aux ^= metric_19 & 15;
  }
  else
  {
    acc = ((acc - metric_19) + 11) & 127;
    aux += 3;
  }
  int sample_54 = (aux + st.buffer[1]) & 3;
  switch (sample_54)
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

void fn_R001827_2713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001827_2713_1 st_1 = {0};
  struct EventLog_R001827_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_48_1 = local_arr_1[aux_1 % 3];
  int tally_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_48_2 * 2)) & 127;
  int metric_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_47_1)
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

  switch (metric_47_2)
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

  int parity_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_62_1) & 63;
  aux_2 = (aux_2 + parity_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_68_1 = 0;
  int factor_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_68_1 = ((factor_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_68_2 = ((factor_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_68_1) & 127;
    acc_2 = (acc_2 + factor_68_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_48_1 == tally_48_2);
  assert(metric_47_1 == metric_47_2);
  assert(parity_62_1 == parity_62_2);
  assert(factor_68_1 == factor_68_2);
}

int fn_R001827_2713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001827_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int tally_48 = local_arr[aux % 3];
  acc = (acc + (tally_48 * 2)) & 127;
  int metric_47 = (aux + st.buffer[1]) & 3;
  switch (metric_47)
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

  int parity_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_62) & 63;
  acc ^= aux;
  int factor_68 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_68 = ((factor_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_68) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001827_2713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001827_2713_0 st_1 = {0};
  struct DeviceConfig_R001827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int scale_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_56_1)
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

  switch (scale_56_2)
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

  int quotient_30_1 = 0;
  int quotient_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_30_1 = ((quotient_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_30_2 = ((quotient_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_30_1) & 127;
    acc_2 = (acc_2 + quotient_30_2) & 127;
  }

  int factor_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_71_1 > 12)
  {
    acc_1 = ((acc_1 + (factor_71_1 * 2)) + 5) & 127;
    aux_1 ^= factor_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_71_2 > 12)
  {
    acc_2 = ((acc_2 + (factor_71_2 * 2)) + 5) & 127;
    aux_2 ^= factor_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_71_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_56_1 == scale_56_2);
  assert(quotient_30_1 == quotient_30_2);
  assert(factor_71_1 == factor_71_2);
}

int fn_R001827_2713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int scale_56 = (aux + st.buffer[1]) & 3;
  switch (scale_56)
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

  int quotient_30 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_30 = ((quotient_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_30) & 127;
  }

  int factor_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_71 > 12)
  {
    acc = ((acc + (factor_71 * 2)) + 5) & 127;
    aux ^= factor_71 & 15;
  }
  else
  {
    acc = ((acc - factor_71) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001827_2713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001827_2713_1 st_1 = {0};
  struct EventLog_R001827_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int vector_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_51_1)
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

  switch (vector_51_2)
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
  int index_reg_23_1 = 0;
  int index_reg_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_23_1 = ((index_reg_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_23_2 = ((index_reg_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_23_1) & 127;
    acc_2 = (acc_2 + index_reg_23_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_51_1 == vector_51_2);
  assert(index_reg_23_1 == index_reg_23_2);
}

int fn_R001827_2713_10(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001827_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int vector_51 = (aux + st.buffer[1]) & 3;
  switch (vector_51)
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
  int index_reg_23 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_23 = ((index_reg_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_23) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001827_2713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001827_2713_2 st_1 = {0};
  struct StreamBuffer_R001827_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int stride_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_32_1)
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

  switch (stride_32_2)
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

  int bound_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_82_1) & 63;
  aux_2 = (aux_2 + bound_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_32_1 == stride_32_2);
  assert(bound_82_1 == bound_82_2);
}

int fn_R001827_2713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001827_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int stride_32 = (aux + st.buffer[1]) & 3;
  switch (stride_32)
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

  int bound_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_82) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001827_2713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001827_2713_0 st_1 = {0};
  struct DeviceConfig_R001827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int factor_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_46_1 > 23)
  {
    acc_1 = ((acc_1 + (factor_46_1 * 2)) + 5) & 127;
    aux_1 ^= factor_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_46_2 > 23)
  {
    acc_2 = ((acc_2 + (factor_46_2 * 2)) + 5) & 127;
    aux_2 ^= factor_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_46_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_88_1) & 63;
  aux_2 = (aux_2 + sample_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_53_1 = 0;
  int segment_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_53_1 = ((segment_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_53_2 = ((segment_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_53_1) & 127;
    acc_2 = (acc_2 + segment_53_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_46_1 == factor_46_2);
  assert(sample_88_1 == sample_88_2);
  assert(segment_53_1 == segment_53_2);
}

int fn_R001827_2713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int factor_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_46 > 23)
  {
    acc = ((acc + (factor_46 * 2)) + 5) & 127;
    aux ^= factor_46 & 15;
  }
  else
  {
    acc = ((acc - factor_46) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_88) & 63;
  acc ^= aux;
  int segment_53 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_53 = ((segment_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_53) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001827_2713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001827_2713_0 st_1 = {0};
  struct DeviceConfig_R001827_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_25_1 > 19)
  {
    acc_1 = ((acc_1 + (weight_25_1 * 2)) + 5) & 127;
    aux_1 ^= weight_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_25_2 > 19)
  {
    acc_2 = ((acc_2 + (weight_25_2 * 2)) + 5) & 127;
    aux_2 ^= weight_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_25_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_25_1 == weight_25_2);
}

int fn_R001827_2713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001827_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_25 > 19)
  {
    acc = ((acc + (weight_25 * 2)) + 5) & 127;
    aux ^= weight_25 & 15;
  }
  else
  {
    acc = ((acc - weight_25) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001827_2713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001827_2713_1 st_1 = {0};
  struct EventLog_R001827_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int metric_33_1 = 0;
  int metric_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_33_1 = ((metric_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_33_2 = ((metric_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_33_1) & 127;
    acc_2 = (acc_2 + metric_33_2) & 127;
  }

  int bound_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_70_1) & 63;
  aux_2 = (aux_2 + bound_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_65_1)
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

  switch (accumulator_65_2)
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
  int accumulator_11_1 = local_arr_1[aux_1 % 3];
  int accumulator_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_11_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_33_1 == metric_33_2);
  assert(bound_70_1 == bound_70_2);
  assert(accumulator_65_1 == accumulator_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_11_1 == accumulator_11_2);
}

int fn_R001827_2713_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001827_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int metric_33 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_33 = ((metric_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_33) & 127;
  }

  int bound_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_70) & 63;
  acc ^= aux;
  int accumulator_65 = (aux + st.buffer[1]) & 3;
  switch (accumulator_65)
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
  int accumulator_11 = local_arr[aux % 3];
  acc = (acc + (accumulator_11 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001827_0_1;
  int sec_r001827_0_2;
  int sec_r001827_1_1;
  int sec_r001827_1_2;
  int sec_r001827_2_1;
  int sec_r001827_2_2;
  int sec_r001827_3_1;
  int sec_r001827_3_2;
  int sec_r001827_4_1;
  int sec_r001827_4_2;
  int sec_r001827_5_1;
  int sec_r001827_5_2;
  int sec_r001827_6_1;
  int sec_r001827_6_2;
  int sec_r001827_7_1;
  int sec_r001827_7_2;
  int sec_r001827_8_1;
  int sec_r001827_8_2;
  int sec_r001827_9_1;
  int sec_r001827_9_2;
  int sec_r001827_10_1;
  int sec_r001827_10_2;
  int sec_r001827_11_1;
  int sec_r001827_11_2;
  int sec_r001827_12_1;
  int sec_r001827_12_2;
  int sec_r001827_13_1;
  int sec_r001827_13_2;
  int sec_r001827_14_1;
  int sec_r001827_14_2;
  int sec_r001827_15_1;
  int sec_r001827_15_2;
  int sec_r001827_16_1;
  int sec_r001827_16_2;
  int sec_r001827_17_1;
  int sec_r001827_17_2;
  int sec_r001827_18_1;
  int sec_r001827_18_2;
  int sec_r001827_19_1;
  int sec_r001827_19_2;
  int sec_r001827_20_1;
  int sec_r001827_20_2;
  int pub_r001827_0_1;
  int pub_r001827_0_2;
  int pub_r001827_1_1;
  int pub_r001827_1_2;
  int pub_r001827_2_1;
  int pub_r001827_2_2;
  int pub_r001827_3_1;
  int pub_r001827_3_2;
  int pub_r001827_4_1;
  int pub_r001827_4_2;
  int pub_r001827_5_1;
  int pub_r001827_5_2;
  int pub_r001827_6_1;
  int pub_r001827_6_2;
  int pub_r001827_7_1;
  int pub_r001827_7_2;
  int pub_r001827_8_1;
  int pub_r001827_8_2;
  int pub_r001827_9_1;
  int pub_r001827_9_2;
  int pub_r001827_10_1;
  int pub_r001827_10_2;
  int pub_r001827_11_1;
  int pub_r001827_11_2;
  int pub_r001827_12_1;
  int pub_r001827_12_2;
  int pub_r001827_13_1;
  int pub_r001827_13_2;
  int pub_r001827_14_1;
  int pub_r001827_14_2;
  int pub_r001827_15_1;
  int pub_r001827_15_2;
  int pub_r001827_16_1;
  int pub_r001827_16_2;
  int pub_r001827_17_1;
  int pub_r001827_17_2;
  int pub_r001827_18_1;
  int pub_r001827_18_2;
  int pub_r001827_19_1;
  int pub_r001827_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001827_0_1 >= (-100)) && (pub_r001827_0_1 <= 100));
  __CPROVER_assume((pub_r001827_0_2 >= (-100)) && (pub_r001827_0_2 <= 100));
  __CPROVER_assume((pub_r001827_1_1 >= (-100)) && (pub_r001827_1_1 <= 100));
  __CPROVER_assume((pub_r001827_1_2 >= (-100)) && (pub_r001827_1_2 <= 100));
  __CPROVER_assume((pub_r001827_2_1 >= (-100)) && (pub_r001827_2_1 <= 100));
  __CPROVER_assume((pub_r001827_2_2 >= (-100)) && (pub_r001827_2_2 <= 100));
  __CPROVER_assume((pub_r001827_3_1 >= (-100)) && (pub_r001827_3_1 <= 100));
  __CPROVER_assume((pub_r001827_3_2 >= (-100)) && (pub_r001827_3_2 <= 100));
  __CPROVER_assume((pub_r001827_4_1 >= (-100)) && (pub_r001827_4_1 <= 100));
  __CPROVER_assume((pub_r001827_4_2 >= (-100)) && (pub_r001827_4_2 <= 100));
  __CPROVER_assume((pub_r001827_5_1 >= (-100)) && (pub_r001827_5_1 <= 100));
  __CPROVER_assume((pub_r001827_5_2 >= (-100)) && (pub_r001827_5_2 <= 100));
  __CPROVER_assume((pub_r001827_6_1 >= (-100)) && (pub_r001827_6_1 <= 100));
  __CPROVER_assume((pub_r001827_6_2 >= (-100)) && (pub_r001827_6_2 <= 100));
  __CPROVER_assume((pub_r001827_7_1 >= (-100)) && (pub_r001827_7_1 <= 100));
  __CPROVER_assume((pub_r001827_7_2 >= (-100)) && (pub_r001827_7_2 <= 100));
  __CPROVER_assume((pub_r001827_8_1 >= (-100)) && (pub_r001827_8_1 <= 100));
  __CPROVER_assume((pub_r001827_8_2 >= (-100)) && (pub_r001827_8_2 <= 100));
  __CPROVER_assume((pub_r001827_9_1 >= (-100)) && (pub_r001827_9_1 <= 100));
  __CPROVER_assume((pub_r001827_9_2 >= (-100)) && (pub_r001827_9_2 <= 100));
  __CPROVER_assume((pub_r001827_10_1 >= (-100)) && (pub_r001827_10_1 <= 100));
  __CPROVER_assume((pub_r001827_10_2 >= (-100)) && (pub_r001827_10_2 <= 100));
  __CPROVER_assume((pub_r001827_11_1 >= (-100)) && (pub_r001827_11_1 <= 100));
  __CPROVER_assume((pub_r001827_11_2 >= (-100)) && (pub_r001827_11_2 <= 100));
  __CPROVER_assume((pub_r001827_12_1 >= (-100)) && (pub_r001827_12_1 <= 100));
  __CPROVER_assume((pub_r001827_12_2 >= (-100)) && (pub_r001827_12_2 <= 100));
  __CPROVER_assume((pub_r001827_13_1 >= (-100)) && (pub_r001827_13_1 <= 100));
  __CPROVER_assume((pub_r001827_13_2 >= (-100)) && (pub_r001827_13_2 <= 100));
  __CPROVER_assume((pub_r001827_14_1 >= (-100)) && (pub_r001827_14_1 <= 100));
  __CPROVER_assume((pub_r001827_14_2 >= (-100)) && (pub_r001827_14_2 <= 100));
  __CPROVER_assume((pub_r001827_15_1 >= (-100)) && (pub_r001827_15_1 <= 100));
  __CPROVER_assume((pub_r001827_15_2 >= (-100)) && (pub_r001827_15_2 <= 100));
  __CPROVER_assume((pub_r001827_16_1 >= (-100)) && (pub_r001827_16_1 <= 100));
  __CPROVER_assume((pub_r001827_16_2 >= (-100)) && (pub_r001827_16_2 <= 100));
  __CPROVER_assume((pub_r001827_17_1 >= (-100)) && (pub_r001827_17_1 <= 100));
  __CPROVER_assume((pub_r001827_17_2 >= (-100)) && (pub_r001827_17_2 <= 100));
  __CPROVER_assume((pub_r001827_18_1 >= (-100)) && (pub_r001827_18_1 <= 100));
  __CPROVER_assume((pub_r001827_18_2 >= (-100)) && (pub_r001827_18_2 <= 100));
  __CPROVER_assume((pub_r001827_19_1 >= (-100)) && (pub_r001827_19_1 <= 100));
  __CPROVER_assume((pub_r001827_19_2 >= (-100)) && (pub_r001827_19_2 <= 100));
  __CPROVER_assume((sec_r001827_0_1 >= 0) && (sec_r001827_0_1 <= 255));
  __CPROVER_assume((sec_r001827_0_2 >= 0) && (sec_r001827_0_2 <= 255));
  __CPROVER_assume((sec_r001827_1_1 >= 0) && (sec_r001827_1_1 <= 255));
  __CPROVER_assume((sec_r001827_1_2 >= 0) && (sec_r001827_1_2 <= 255));
  __CPROVER_assume((sec_r001827_2_1 >= 0) && (sec_r001827_2_1 <= 255));
  __CPROVER_assume((sec_r001827_2_2 >= 0) && (sec_r001827_2_2 <= 255));
  __CPROVER_assume((sec_r001827_3_1 >= 0) && (sec_r001827_3_1 <= 255));
  __CPROVER_assume((sec_r001827_3_2 >= 0) && (sec_r001827_3_2 <= 255));
  __CPROVER_assume((sec_r001827_4_1 >= 0) && (sec_r001827_4_1 <= 255));
  __CPROVER_assume((sec_r001827_4_2 >= 0) && (sec_r001827_4_2 <= 255));
  __CPROVER_assume((sec_r001827_5_1 >= 0) && (sec_r001827_5_1 <= 255));
  __CPROVER_assume((sec_r001827_5_2 >= 0) && (sec_r001827_5_2 <= 255));
  __CPROVER_assume((sec_r001827_6_1 >= 0) && (sec_r001827_6_1 <= 255));
  __CPROVER_assume((sec_r001827_6_2 >= 0) && (sec_r001827_6_2 <= 255));
  __CPROVER_assume((sec_r001827_7_1 >= 0) && (sec_r001827_7_1 <= 255));
  __CPROVER_assume((sec_r001827_7_2 >= 0) && (sec_r001827_7_2 <= 255));
  __CPROVER_assume((sec_r001827_8_1 >= 0) && (sec_r001827_8_1 <= 255));
  __CPROVER_assume((sec_r001827_8_2 >= 0) && (sec_r001827_8_2 <= 255));
  __CPROVER_assume((sec_r001827_9_1 >= 0) && (sec_r001827_9_1 <= 255));
  __CPROVER_assume((sec_r001827_9_2 >= 0) && (sec_r001827_9_2 <= 255));
  __CPROVER_assume((sec_r001827_10_1 >= 0) && (sec_r001827_10_1 <= 255));
  __CPROVER_assume((sec_r001827_10_2 >= 0) && (sec_r001827_10_2 <= 255));
  __CPROVER_assume((sec_r001827_11_1 >= 0) && (sec_r001827_11_1 <= 255));
  __CPROVER_assume((sec_r001827_11_2 >= 0) && (sec_r001827_11_2 <= 255));
  __CPROVER_assume((sec_r001827_12_1 >= 0) && (sec_r001827_12_1 <= 255));
  __CPROVER_assume((sec_r001827_12_2 >= 0) && (sec_r001827_12_2 <= 255));
  __CPROVER_assume((sec_r001827_13_1 >= 0) && (sec_r001827_13_1 <= 255));
  __CPROVER_assume((sec_r001827_13_2 >= 0) && (sec_r001827_13_2 <= 255));
  __CPROVER_assume((sec_r001827_14_1 >= 0) && (sec_r001827_14_1 <= 255));
  __CPROVER_assume((sec_r001827_14_2 >= 0) && (sec_r001827_14_2 <= 255));
  __CPROVER_assume((sec_r001827_15_1 >= 0) && (sec_r001827_15_1 <= 255));
  __CPROVER_assume((sec_r001827_15_2 >= 0) && (sec_r001827_15_2 <= 255));
  __CPROVER_assume((sec_r001827_16_1 >= 0) && (sec_r001827_16_1 <= 255));
  __CPROVER_assume((sec_r001827_16_2 >= 0) && (sec_r001827_16_2 <= 255));
  __CPROVER_assume((sec_r001827_17_1 >= 0) && (sec_r001827_17_1 <= 255));
  __CPROVER_assume((sec_r001827_17_2 >= 0) && (sec_r001827_17_2 <= 255));
  __CPROVER_assume((sec_r001827_18_1 >= 0) && (sec_r001827_18_1 <= 255));
  __CPROVER_assume((sec_r001827_18_2 >= 0) && (sec_r001827_18_2 <= 255));
  __CPROVER_assume((sec_r001827_19_1 >= 0) && (sec_r001827_19_1 <= 255));
  __CPROVER_assume((sec_r001827_19_2 >= 0) && (sec_r001827_19_2 <= 255));
  __CPROVER_assume((sec_r001827_20_1 >= 0) && (sec_r001827_20_1 <= 255));
  __CPROVER_assume((sec_r001827_20_2 >= 0) && (sec_r001827_20_2 <= 255));
  struct DeviceConfig_R001827_2713_0 st_var_0_1 = {0};
  struct DeviceConfig_R001827_2713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001827_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001827_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001827_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001827_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001827_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001827_0_2 + 7) & 15;
  struct EventLog_R001827_2713_1 st_var_1_1 = {0};
  struct EventLog_R001827_2713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001827_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001827_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001827_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001827_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001827_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001827_0_2 + 9) & 15;
  struct StreamBuffer_R001827_2713_2 st_var_2_1 = {0};
  struct StreamBuffer_R001827_2713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001827_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001827_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001827_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001827_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001827_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001827_0_2 + 11) & 15;
  union PacketPayload_R001827_2713_0 u_var_1;
  union PacketPayload_R001827_2713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001827_2713_0(sec_r001827_0_1, pub_r001827_1_1, pub_r001827_2_1, pub_r001827_3_1);
  int helper_flow_0_2 = fn_R001827_2713_0(sec_r001827_0_2, pub_r001827_1_2, pub_r001827_2_2, pub_r001827_3_2);
  fn_R001827_2713_0_2(sec_r001827_0_1, pub_r001827_1_1, pub_r001827_2_1, pub_r001827_3_1, sec_r001827_0_2, pub_r001827_1_2, pub_r001827_2_2, pub_r001827_3_2);
  int helper_flow_1_1 = fn_R001827_2713_1(sec_r001827_1_1, pub_r001827_2_1);
  int helper_flow_1_2 = fn_R001827_2713_1(sec_r001827_1_2, pub_r001827_2_2);
  fn_R001827_2713_1_2(sec_r001827_1_1, pub_r001827_2_1, sec_r001827_1_2, pub_r001827_2_2);
  int helper_flow_2_1 = fn_R001827_2713_2(sec_r001827_2_1, sec_r001827_3_1, pub_r001827_4_1, pub_r001827_5_1);
  int helper_flow_2_2 = fn_R001827_2713_2(sec_r001827_2_2, sec_r001827_3_2, pub_r001827_4_2, pub_r001827_5_2);
  fn_R001827_2713_2_2(sec_r001827_2_1, sec_r001827_3_1, pub_r001827_4_1, pub_r001827_5_1, sec_r001827_2_2, sec_r001827_3_2, pub_r001827_4_2, pub_r001827_5_2);
  int helper_flow_3_1 = fn_R001827_2713_3(sec_r001827_3_1, pub_r001827_4_1);
  int helper_flow_3_2 = fn_R001827_2713_3(sec_r001827_3_2, pub_r001827_4_2);
  fn_R001827_2713_3_2(sec_r001827_3_1, pub_r001827_4_1, sec_r001827_3_2, pub_r001827_4_2);
  int helper_flow_4_1 = fn_R001827_2713_4(sec_r001827_4_1, sec_r001827_5_1);
  int helper_flow_4_2 = fn_R001827_2713_4(sec_r001827_4_2, sec_r001827_5_2);
  fn_R001827_2713_4_2(sec_r001827_4_1, sec_r001827_5_1, sec_r001827_4_2, sec_r001827_5_2);
  int helper_flow_5_1 = fn_R001827_2713_5(sec_r001827_5_1, pub_r001827_6_1, pub_r001827_7_1);
  int helper_flow_5_2 = fn_R001827_2713_5(sec_r001827_5_2, pub_r001827_6_2, pub_r001827_7_2);
  fn_R001827_2713_5_2(sec_r001827_5_1, pub_r001827_6_1, pub_r001827_7_1, sec_r001827_5_2, pub_r001827_6_2, pub_r001827_7_2);
  int helper_flow_6_1 = fn_R001827_2713_6(sec_r001827_6_1, sec_r001827_7_1, pub_r001827_8_1, pub_r001827_9_1);
  int helper_flow_6_2 = fn_R001827_2713_6(sec_r001827_6_2, sec_r001827_7_2, pub_r001827_8_2, pub_r001827_9_2);
  fn_R001827_2713_6_2(sec_r001827_6_1, sec_r001827_7_1, pub_r001827_8_1, pub_r001827_9_1, sec_r001827_6_2, sec_r001827_7_2, pub_r001827_8_2, pub_r001827_9_2);
  int stage_v_0_1 = (sec_r001827_14_1 ^ pub_r001827_18_1) & 63;
  int stage_v_0_2 = (sec_r001827_14_2 ^ pub_r001827_18_2) & 63;
  if ((stage_v_0_1 & 1) != 0)
  {
    if ((sec_r001827_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_0_1 * 2)) & 255;
  }
  if ((stage_v_0_2 & 1) != 0)
  {
    if ((sec_r001827_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_0_2 * 2)) & 255;
  }
  int stage_v_1_1 = ((pub_r001827_9_1 * 2) + 17) & 63;
  int stage_v_1_2 = ((pub_r001827_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001827_2_1 * 2) + 30) & 63;
  int stage_v_2_2 = ((pub_r001827_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001827_16_1 * 2) + 50) & 63;
  int stage_v_3_2 = ((pub_r001827_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (sec_r001827_19_1 ^ pub_r001827_17_1) & 63;
  int stage_v_4_2 = (sec_r001827_19_2 ^ pub_r001827_17_2) & 63;
  if ((stage_v_4_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_4_1 * 2)) & 255;
  }
  if ((stage_v_4_2 & 1) != 0)
  {
    if ((helper_flow_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_4_2 * 2)) & 255;
  }
  int stage_v_5_1 = (sec_r001827_4_1 ^ pub_r001827_6_1) & 63;
  int stage_v_5_2 = (sec_r001827_4_2 ^ pub_r001827_6_2) & 63;
  if ((stage_v_5_1 & 1) != 0)
  {
    if ((stage_v_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_5_1 * 2)) & 255;
  }
  if ((stage_v_5_2 & 1) != 0)
  {
    if ((stage_v_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_5_2 * 2)) & 255;
  }
  int stage_v_6_1 = (sec_r001827_6_1 ^ pub_r001827_11_1) & 63;
  int stage_v_6_2 = (sec_r001827_6_2 ^ pub_r001827_11_2) & 63;
  if ((stage_v_6_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_6_1 * 2)) & 255;
  }
  if ((stage_v_6_2 & 1) != 0)
  {
    if ((helper_flow_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_6_2 * 2)) & 255;
  }
  int stage_v_7_1 = (sec_r001827_2_1 ^ pub_r001827_9_1) & 63;
  int stage_v_7_2 = (sec_r001827_2_2 ^ pub_r001827_9_2) & 63;
  if ((stage_v_7_1 & 1) != 0)
  {
    if ((sec_r001827_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_7_1 * 2)) & 255;
  }
  if ((stage_v_7_2 & 1) != 0)
  {
    if ((sec_r001827_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_7_2 * 2)) & 255;
  }
  int stage_v_8_1 = ((pub_r001827_17_1 * 2) + 32) & 63;
  int stage_v_8_2 = ((pub_r001827_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (sec_r001827_1_1 ^ pub_r001827_7_1) & 63;
  int stage_v_9_2 = (sec_r001827_1_2 ^ pub_r001827_7_2) & 63;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((sec_r001827_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_9_1 * 2)) & 255;
  }
  if ((stage_v_9_2 & 1) != 0)
  {
    if ((sec_r001827_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_9_2 * 2)) & 255;
  }
  int stage_v_10_1 = (helper_flow_4_1 ^ pub_r001827_17_1) & 63;
  int stage_v_10_2 = (helper_flow_4_2 ^ pub_r001827_17_2) & 63;
  if ((stage_v_10_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_10_1 * 2)) & 255;
  }
  if ((stage_v_10_2 & 1) != 0)
  {
    if ((helper_flow_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_10_2 * 2)) & 255;
  }
  int stage_v_11_1 = (stage_v_4_1 ^ pub_r001827_2_1) & 63;
  int stage_v_11_2 = (stage_v_4_2 ^ pub_r001827_2_2) & 63;
  if ((stage_v_11_1 & 1) != 0)
  {
    if ((sec_r001827_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_11_1 * 2)) & 255;
  }
  if ((stage_v_11_2 & 1) != 0)
  {
    if ((sec_r001827_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_11_2 * 2)) & 255;
  }
  int stage_v_12_1 = (stage_v_7_1 ^ pub_r001827_0_1) & 63;
  int stage_v_12_2 = (stage_v_7_2 ^ pub_r001827_0_2) & 63;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_12_1 * 2)) & 255;
  }
  if ((stage_v_12_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_12_2 * 2)) & 255;
  }
  int stage_v_13_1 = ((pub_r001827_16_1 * 2) + 25) & 63;
  int stage_v_13_2 = ((pub_r001827_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (sec_r001827_15_1 ^ pub_r001827_9_1) & 63;
  int stage_v_14_2 = (sec_r001827_15_2 ^ pub_r001827_9_2) & 63;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r001827_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_14_1 * 2)) & 255;
  }
  if ((stage_v_14_2 & 1) != 0)
  {
    if ((sec_r001827_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_14_2 * 2)) & 255;
  }
  int stage_v_15_1 = (sec_r001827_9_1 ^ pub_r001827_1_1) & 63;
  int stage_v_15_2 = (sec_r001827_9_2 ^ pub_r001827_1_2) & 63;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r001827_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_15_1 * 2)) & 255;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r001827_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_15_2 * 2)) & 255;
  }
  int stage_v_16_1 = ((pub_r001827_10_1 * 2) + 46) & 63;
  int stage_v_16_2 = ((pub_r001827_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (sec_r001827_0_1 ^ pub_r001827_17_1) & 63;
  int stage_v_17_2 = (sec_r001827_0_2 ^ pub_r001827_17_2) & 63;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r001827_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_17_1 * 2)) & 255;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r001827_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_17_2 * 2)) & 255;
  }
  int stage_v_18_1 = (stage_v_11_1 ^ pub_r001827_12_1) & 63;
  int stage_v_18_2 = (stage_v_11_2 ^ pub_r001827_12_2) & 63;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r001827_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_18_1 * 2)) & 255;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r001827_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_18_2 * 2)) & 255;
  }
  int stage_v_19_1 = ((pub_r001827_8_1 * 2) + 38) & 63;
  int stage_v_19_2 = ((pub_r001827_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001827_5_1 * 2) + 14) & 63;
  int stage_v_20_2 = ((pub_r001827_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001827_16_1 * 2) + 6) & 63;
  int stage_v_21_2 = ((pub_r001827_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001827_1_1 * 2) + 5) & 63;
  int stage_v_22_2 = ((pub_r001827_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (stage_v_17_1 ^ pub_r001827_15_1) & 63;
  int stage_v_23_2 = (stage_v_17_2 ^ pub_r001827_15_2) & 63;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r001827_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_23_1 * 2)) & 255;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r001827_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_23_2 * 2)) & 255;
  }
  int stage_v_24_1 = ((pub_r001827_17_1 * 2) + 37) & 63;
  int stage_v_24_2 = ((pub_r001827_17_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001827_13_1 * 2) + 8) & 63;
  int stage_v_25_2 = ((pub_r001827_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (sec_r001827_13_1 ^ pub_r001827_19_1) & 63;
  int stage_v_26_2 = (sec_r001827_13_2 ^ pub_r001827_19_2) & 63;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r001827_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_26_1 * 2)) & 255;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r001827_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_26_2 * 2)) & 255;
  }
  int stage_v_27_1 = (sec_r001827_3_1 ^ pub_r001827_16_1) & 63;
  int stage_v_27_2 = (sec_r001827_3_2 ^ pub_r001827_16_2) & 63;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r001827_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_27_1 * 2)) & 255;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r001827_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_27_2 * 2)) & 255;
  }
  int stage_v_28_1 = ((pub_r001827_8_1 * 2) + 46) & 63;
  int stage_v_28_2 = ((pub_r001827_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (sec_r001827_5_1 ^ pub_r001827_16_1) & 63;
  int stage_v_29_2 = (sec_r001827_5_2 ^ pub_r001827_16_2) & 63;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r001827_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_29_1 * 2)) & 255;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r001827_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_29_2 * 2)) & 255;
  }
  int stage_v_30_1 = ((pub_r001827_19_1 * 2) + 29) & 63;
  int stage_v_30_2 = ((pub_r001827_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001827_13_1 * 2) + 9) & 63;
  int stage_v_31_2 = ((pub_r001827_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (sec_r001827_13_1 ^ pub_r001827_9_1) & 63;
  int stage_v_32_2 = (sec_r001827_13_2 ^ pub_r001827_9_2) & 63;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_32_1 * 2)) & 255;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((stage_v_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_32_2 * 2)) & 255;
  }
  int stage_v_33_1 = (stage_v_23_1 ^ pub_r001827_15_1) & 63;
  int stage_v_33_2 = (stage_v_23_2 ^ pub_r001827_15_2) & 63;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r001827_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_33_1 * 2)) & 255;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r001827_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_33_2 * 2)) & 255;
  }
  int stage_v_34_1 = ((pub_r001827_0_1 * 2) + 11) & 63;
  int stage_v_34_2 = ((pub_r001827_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001827_5_1 * 2) + 40) & 63;
  int stage_v_35_2 = ((pub_r001827_5_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001827_9_1 * 2) + 5) & 63;
  int stage_v_36_2 = ((pub_r001827_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001827_18_1 * 2) + 18) & 63;
  int stage_v_37_2 = ((pub_r001827_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (helper_flow_4_1 ^ pub_r001827_7_1) & 63;
  int stage_v_38_2 = (helper_flow_4_2 ^ pub_r001827_7_2) & 63;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_38_1 * 2)) & 255;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((helper_flow_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_38_2 * 2)) & 255;
  }
  int stage_v_39_1 = ((pub_r001827_12_1 * 2) + 7) & 63;
  int stage_v_39_2 = ((pub_r001827_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (sec_r001827_12_1 ^ pub_r001827_13_1) & 63;
  int stage_v_40_2 = (sec_r001827_12_2 ^ pub_r001827_13_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_40_1 * 2)) & 255;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((helper_flow_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_40_2 * 2)) & 255;
  }
  int stage_v_41_1 = (sec_r001827_4_1 ^ pub_r001827_16_1) & 63;
  int stage_v_41_2 = (sec_r001827_4_2 ^ pub_r001827_16_2) & 63;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r001827_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_41_1 * 2)) & 255;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r001827_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_41_2 * 2)) & 255;
  }
  int stage_v_42_1 = ((pub_r001827_6_1 * 2) + 26) & 63;
  int stage_v_42_2 = ((pub_r001827_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001827_4_1 * 2) + 42) & 63;
  int stage_v_43_2 = ((pub_r001827_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (helper_flow_1_1 ^ pub_r001827_9_1) & 63;
  int stage_v_44_2 = (helper_flow_1_2 ^ pub_r001827_9_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r001827_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_44_1 * 2)) & 255;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r001827_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_44_2 * 2)) & 255;
  }
  int stage_v_45_1 = (stage_v_33_1 ^ pub_r001827_12_1) & 63;
  int stage_v_45_2 = (stage_v_33_2 ^ pub_r001827_12_2) & 63;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_45_1 * 2)) & 255;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_45_2 * 2)) & 255;
  }
  int stage_v_46_1 = (helper_flow_6_1 ^ pub_r001827_17_1) & 63;
  int stage_v_46_2 = (helper_flow_6_2 ^ pub_r001827_17_2) & 63;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r001827_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_46_1 * 2)) & 255;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r001827_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_46_2 * 2)) & 255;
  }
  int stage_v_47_1 = (sec_r001827_8_1 ^ pub_r001827_7_1) & 63;
  int stage_v_47_2 = (sec_r001827_8_2 ^ pub_r001827_7_2) & 63;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r001827_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_47_1 * 2)) & 255;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r001827_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_47_2 * 2)) & 255;
  }
  int stage_v_48_1 = (sec_r001827_1_1 ^ pub_r001827_11_1) & 63;
  int stage_v_48_2 = (sec_r001827_1_2 ^ pub_r001827_11_2) & 63;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_48_1 * 2)) & 255;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((stage_v_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_48_2 * 2)) & 255;
  }
  int stage_v_49_1 = (helper_flow_1_1 ^ pub_r001827_16_1) & 63;
  int stage_v_49_2 = (helper_flow_1_2 ^ pub_r001827_16_2) & 63;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_49_1 * 2)) & 255;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((stage_v_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_49_2 * 2)) & 255;
  }
  int stage_v_50_1 = (helper_flow_1_1 ^ pub_r001827_6_1) & 63;
  int stage_v_50_2 = (helper_flow_1_2 ^ pub_r001827_6_2) & 63;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r001827_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_50_1 * 2)) & 255;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r001827_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_50_2 * 2)) & 255;
  }
  int stage_v_51_1 = (stage_v_5_1 ^ pub_r001827_8_1) & 63;
  int stage_v_51_2 = (stage_v_5_2 ^ pub_r001827_8_2) & 63;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((stage_v_46_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_51_1 * 2)) & 255;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((stage_v_46_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_51_2 * 2)) & 255;
  }
  int stage_v_52_1 = (stage_v_27_1 ^ pub_r001827_17_1) & 63;
  int stage_v_52_2 = (stage_v_27_2 ^ pub_r001827_17_2) & 63;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r001827_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_52_1 * 2)) & 255;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r001827_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_52_2 * 2)) & 255;
  }
  int stage_v_53_1 = (sec_r001827_8_1 ^ pub_r001827_19_1) & 63;
  int stage_v_53_2 = (sec_r001827_8_2 ^ pub_r001827_19_2) & 63;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r001827_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_53_1 * 2)) & 255;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r001827_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_53_2 * 2)) & 255;
  }
  int stage_v_54_1 = (stage_v_52_1 ^ pub_r001827_7_1) & 63;
  int stage_v_54_2 = (stage_v_52_2 ^ pub_r001827_7_2) & 63;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r001827_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_54_1 * 2)) & 255;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r001827_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_54_2 * 2)) & 255;
  }
  int stage_v_55_1 = (sec_r001827_14_1 ^ pub_r001827_0_1) & 63;
  int stage_v_55_2 = (sec_r001827_14_2 ^ pub_r001827_0_2) & 63;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r001827_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_55_1 * 2)) & 255;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r001827_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_55_2 * 2)) & 255;
  }
  int stage_v_56_1 = (sec_r001827_7_1 ^ pub_r001827_7_1) & 63;
  int stage_v_56_2 = (sec_r001827_7_2 ^ pub_r001827_7_2) & 63;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_56_1 * 2)) & 255;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_56_2 * 2)) & 255;
  }
  int stage_v_57_1 = (helper_flow_2_1 ^ pub_r001827_6_1) & 63;
  int stage_v_57_2 = (helper_flow_2_2 ^ pub_r001827_6_2) & 63;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r001827_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_57_1 * 2)) & 255;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r001827_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_57_2 * 2)) & 255;
  }
  int stage_v_58_1 = (stage_v_51_1 ^ pub_r001827_7_1) & 63;
  int stage_v_58_2 = (stage_v_51_2 ^ pub_r001827_7_2) & 63;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((stage_v_51_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_58_1 * 2)) & 255;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((stage_v_51_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_58_2 * 2)) & 255;
  }
  int stage_v_59_1 = (stage_v_4_1 ^ pub_r001827_13_1) & 63;
  int stage_v_59_2 = (stage_v_4_2 ^ pub_r001827_13_2) & 63;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((stage_v_57_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_59_1 * 2)) & 255;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((stage_v_57_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_59_2 * 2)) & 255;
  }
  int stage_v_60_1 = (stage_v_49_1 ^ pub_r001827_13_1) & 63;
  int stage_v_60_2 = (stage_v_49_2 ^ pub_r001827_13_2) & 63;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((stage_v_55_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((stage_v_55_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  }
  int stage_v_61_1 = (sec_r001827_18_1 ^ pub_r001827_5_1) & 63;
  int stage_v_61_2 = (sec_r001827_18_2 ^ pub_r001827_5_2) & 63;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_61_1 * 2)) & 255;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((stage_v_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_61_2 * 2)) & 255;
  }
  int stage_v_62_1 = (stage_v_50_1 ^ pub_r001827_5_1) & 63;
  int stage_v_62_2 = (stage_v_50_2 ^ pub_r001827_5_2) & 63;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_62_1 * 2)) & 255;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((helper_flow_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_62_2 * 2)) & 255;
  }
  int stage_v_63_1 = ((pub_r001827_2_1 * 2) + 35) & 63;
  int stage_v_63_2 = ((pub_r001827_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (sec_r001827_19_1 ^ pub_r001827_0_1) & 63;
  int stage_v_64_2 = (sec_r001827_19_2 ^ pub_r001827_0_2) & 63;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r001827_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_64_1 * 2)) & 255;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r001827_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_64_2 * 2)) & 255;
  }
  int stage_v_65_1 = (stage_v_60_1 ^ pub_r001827_1_1) & 63;
  int stage_v_65_2 = (stage_v_60_2 ^ pub_r001827_1_2) & 63;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_65_1 * 2)) & 255;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_65_2 * 2)) & 255;
  }
  int stage_v_66_1 = ((pub_r001827_15_1 * 2) + 42) & 63;
  int stage_v_66_2 = ((pub_r001827_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001827_9_1 * 2) + 45) & 63;
  int stage_v_67_2 = ((pub_r001827_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (stage_v_0_1 ^ pub_r001827_0_1) & 63;
  int stage_v_68_2 = (stage_v_0_2 ^ pub_r001827_0_2) & 63;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r001827_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_68_1 * 2)) & 255;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r001827_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_68_2 * 2)) & 255;
  }
  int stage_v_69_1 = ((pub_r001827_7_1 * 2) + 14) & 63;
  int stage_v_69_2 = ((pub_r001827_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (helper_flow_1_1 ^ pub_r001827_12_1) & 63;
  int stage_v_70_2 = (helper_flow_1_2 ^ pub_r001827_12_2) & 63;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r001827_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_70_1 * 2)) & 255;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r001827_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_70_2 * 2)) & 255;
  }
  int stage_v_71_1 = (stage_v_9_1 ^ pub_r001827_14_1) & 63;
  int stage_v_71_2 = (stage_v_9_2 ^ pub_r001827_14_2) & 63;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((stage_v_61_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_71_1 * 2)) & 255;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((stage_v_61_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_71_2 * 2)) & 255;
  }
  int stage_v_72_1 = (stage_v_54_1 ^ pub_r001827_19_1) & 63;
  int stage_v_72_2 = (stage_v_54_2 ^ pub_r001827_19_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_72_1 * 2)) & 255;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_72_2 * 2)) & 255;
  }
  int stage_v_73_1 = (stage_v_14_1 ^ pub_r001827_19_1) & 63;
  int stage_v_73_2 = (stage_v_14_2 ^ pub_r001827_19_2) & 63;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r001827_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r001827_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  }
  int stage_v_74_1 = ((pub_r001827_10_1 * 2) + 47) & 63;
  int stage_v_74_2 = ((pub_r001827_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001827_9_1 * 2) + 15) & 63;
  int stage_v_75_2 = ((pub_r001827_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = (stage_v_46_1 ^ pub_r001827_18_1) & 63;
  int stage_v_76_2 = (stage_v_46_2 ^ pub_r001827_18_2) & 63;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((stage_v_59_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((stage_v_59_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  }
  int stage_v_77_1 = (sec_r001827_19_1 ^ pub_r001827_8_1) & 63;
  int stage_v_77_2 = (sec_r001827_19_2 ^ pub_r001827_8_2) & 63;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((stage_v_52_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((stage_v_52_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  }
  int stage_v_78_1 = (helper_flow_2_1 ^ pub_r001827_0_1) & 63;
  int stage_v_78_2 = (helper_flow_2_2 ^ pub_r001827_0_2) & 63;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((stage_v_73_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((stage_v_73_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  }
  int stage_v_79_1 = (stage_v_33_1 ^ pub_r001827_14_1) & 63;
  int stage_v_79_2 = (stage_v_33_2 ^ pub_r001827_14_2) & 63;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r001827_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_79_1 * 2)) & 255;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r001827_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_79_2 * 2)) & 255;
  }
  int stage_v_80_1 = (stage_v_45_1 ^ pub_r001827_6_1) & 63;
  int stage_v_80_2 = (stage_v_45_2 ^ pub_r001827_6_2) & 63;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((stage_v_76_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((stage_v_76_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  }
  int stage_v_81_1 = (stage_v_54_1 ^ pub_r001827_7_1) & 63;
  int stage_v_81_2 = (stage_v_54_2 ^ pub_r001827_7_2) & 63;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r001827_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r001827_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  }
  int stage_v_82_1 = (helper_flow_4_1 ^ pub_r001827_1_1) & 63;
  int stage_v_82_2 = (helper_flow_4_2 ^ pub_r001827_1_2) & 63;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((stage_v_33_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((stage_v_33_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  }
  int stage_v_83_1 = ((pub_r001827_6_1 * 2) + 41) & 63;
  int stage_v_83_2 = ((pub_r001827_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (sec_r001827_19_1 ^ pub_r001827_4_1) & 63;
  int stage_v_84_2 = (sec_r001827_19_2 ^ pub_r001827_4_2) & 63;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r001827_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r001827_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  }
  int stage_v_85_1 = (stage_v_46_1 ^ pub_r001827_3_1) & 63;
  int stage_v_85_2 = (stage_v_46_2 ^ pub_r001827_3_2) & 63;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((stage_v_79_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((stage_v_79_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  }
  int stage_v_86_1 = ((pub_r001827_11_1 * 2) + 19) & 63;
  int stage_v_86_2 = ((pub_r001827_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (sec_r001827_20_1 ^ pub_r001827_14_1) & 63;
  int stage_v_87_2 = (sec_r001827_20_2 ^ pub_r001827_14_2) & 63;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((stage_v_27_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  }
  int stage_v_88_1 = (sec_r001827_7_1 ^ pub_r001827_8_1) & 63;
  int stage_v_88_2 = (sec_r001827_7_2 ^ pub_r001827_8_2) & 63;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((stage_v_81_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((stage_v_81_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  }
  int stage_v_89_1 = (stage_v_64_1 ^ pub_r001827_12_1) & 63;
  int stage_v_89_2 = (stage_v_64_2 ^ pub_r001827_12_2) & 63;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((stage_v_49_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((stage_v_49_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  }
  int stage_v_90_1 = ((pub_r001827_6_1 * 2) + 43) & 63;
  int stage_v_90_2 = ((pub_r001827_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = (sec_r001827_12_1 ^ pub_r001827_1_1) & 63;
  int stage_v_91_2 = (sec_r001827_12_2 ^ pub_r001827_1_2) & 63;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((stage_v_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((stage_v_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  }
  int stage_v_92_1 = (stage_v_85_1 ^ pub_r001827_10_1) & 63;
  int stage_v_92_2 = (stage_v_85_2 ^ pub_r001827_10_2) & 63;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((stage_v_73_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((stage_v_73_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  }
  int stage_v_93_1 = (stage_v_72_1 ^ pub_r001827_6_1) & 63;
  int stage_v_93_2 = (stage_v_72_2 ^ pub_r001827_6_2) & 63;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((stage_v_52_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((stage_v_52_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  }
  int stage_v_94_1 = (sec_r001827_1_1 ^ pub_r001827_17_1) & 63;
  int stage_v_94_2 = (sec_r001827_1_2 ^ pub_r001827_17_2) & 63;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r001827_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r001827_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  }
  int stage_v_95_1 = ((pub_r001827_18_1 * 2) + 28) & 63;
  int stage_v_95_2 = ((pub_r001827_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (stage_v_64_1 ^ pub_r001827_5_1) & 63;
  int stage_v_96_2 = (stage_v_64_2 ^ pub_r001827_5_2) & 63;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r001827_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r001827_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  }
  int stage_v_97_1 = ((pub_r001827_8_1 * 2) + 11) & 63;
  int stage_v_97_2 = ((pub_r001827_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (stage_v_41_1 ^ pub_r001827_19_1) & 63;
  int stage_v_98_2 = (stage_v_41_2 ^ pub_r001827_19_2) & 63;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((stage_v_44_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  }
  int stage_v_99_1 = (stage_v_96_1 ^ pub_r001827_17_1) & 63;
  int stage_v_99_2 = (stage_v_96_2 ^ pub_r001827_17_2) & 63;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((stage_v_60_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  }
  int stage_v_100_1 = (sec_r001827_7_1 ^ pub_r001827_2_1) & 63;
  int stage_v_100_2 = (sec_r001827_7_2 ^ pub_r001827_2_2) & 63;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_100_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((stage_v_27_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_100_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  }
  int stage_v_101_1 = ((pub_r001827_1_1 * 2) + 34) & 63;
  int stage_v_101_2 = ((pub_r001827_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (stage_v_57_1 ^ pub_r001827_4_1) & 63;
  int stage_v_102_2 = (stage_v_57_2 ^ pub_r001827_4_2) & 63;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((stage_v_47_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((stage_v_47_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  }
  int stage_v_103_1 = ((pub_r001827_19_1 * 2) + 10) & 63;
  int stage_v_103_2 = ((pub_r001827_19_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001827_4_1 * 2) + 48) & 63;
  int stage_v_104_2 = ((pub_r001827_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001827_17_1 * 2) + 42) & 63;
  int stage_v_105_2 = ((pub_r001827_17_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (stage_v_23_1 ^ pub_r001827_13_1) & 63;
  int stage_v_106_2 = (stage_v_23_2 ^ pub_r001827_13_2) & 63;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r001827_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r001827_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  }
  int stage_v_107_1 = ((pub_r001827_15_1 * 2) + 21) & 63;
  int stage_v_107_2 = ((pub_r001827_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001827_8_1 * 2) + 8) & 63;
  int stage_v_108_2 = ((pub_r001827_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001827_16_1 * 2) + 17) & 63;
  int stage_v_109_2 = ((pub_r001827_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (stage_v_59_1 ^ pub_r001827_16_1) & 63;
  int stage_v_110_2 = (stage_v_59_2 ^ pub_r001827_16_2) & 63;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((stage_v_76_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((stage_v_76_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  }
  int stage_v_111_1 = ((pub_r001827_13_1 * 2) + 30) & 63;
  int stage_v_111_2 = ((pub_r001827_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001827_6_1 * 2) + 48) & 63;
  int stage_v_112_2 = ((pub_r001827_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001827_9_1 * 2) + 18) & 63;
  int stage_v_113_2 = ((pub_r001827_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (stage_v_72_1 ^ pub_r001827_18_1) & 63;
  int stage_v_114_2 = (stage_v_72_2 ^ pub_r001827_18_2) & 63;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((stage_v_68_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((stage_v_68_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  }
  int stage_v_115_1 = ((pub_r001827_16_1 * 2) + 37) & 63;
  int stage_v_115_2 = ((pub_r001827_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (stage_v_12_1 ^ pub_r001827_3_1) & 63;
  int stage_v_116_2 = (stage_v_12_2 ^ pub_r001827_3_2) & 63;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((stage_v_55_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((stage_v_55_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  }
  int stage_v_117_1 = (stage_v_15_1 ^ pub_r001827_9_1) & 63;
  int stage_v_117_2 = (stage_v_15_2 ^ pub_r001827_9_2) & 63;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((stage_v_78_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((stage_v_78_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  }
  int stage_v_118_1 = (helper_flow_5_1 ^ pub_r001827_19_1) & 63;
  int stage_v_118_2 = (helper_flow_5_2 ^ pub_r001827_19_2) & 63;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((stage_v_51_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((stage_v_51_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  }
  int stage_v_119_1 = (stage_v_58_1 ^ pub_r001827_0_1) & 63;
  int stage_v_119_2 = (stage_v_58_2 ^ pub_r001827_0_2) & 63;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((stage_v_100_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((stage_v_100_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  }
  int stage_v_120_1 = ((pub_r001827_9_1 * 2) + 19) & 63;
  int stage_v_120_2 = ((pub_r001827_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001827_4_1 * 2) + 45) & 63;
  int stage_v_121_2 = ((pub_r001827_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (helper_flow_3_1 ^ pub_r001827_19_1) & 63;
  int stage_v_122_2 = (helper_flow_3_2 ^ pub_r001827_19_2) & 63;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  }
  int stage_v_123_1 = (stage_v_15_1 ^ pub_r001827_4_1) & 63;
  int stage_v_123_2 = (stage_v_15_2 ^ pub_r001827_4_2) & 63;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((stage_v_78_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((stage_v_78_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  }
  int stage_v_124_1 = (stage_v_11_1 ^ pub_r001827_9_1) & 63;
  int stage_v_124_2 = (stage_v_11_2 ^ pub_r001827_9_2) & 63;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((stage_v_99_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((stage_v_99_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  }
  int stage_v_125_1 = (sec_r001827_12_1 ^ pub_r001827_4_1) & 63;
  int stage_v_125_2 = (sec_r001827_12_2 ^ pub_r001827_4_2) & 63;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((stage_v_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((stage_v_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  }
  int stage_v_126_1 = (stage_v_49_1 ^ pub_r001827_14_1) & 63;
  int stage_v_126_2 = (stage_v_49_2 ^ pub_r001827_14_2) & 63;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((stage_v_80_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  }
  int stage_v_127_1 = (stage_v_106_1 ^ pub_r001827_10_1) & 63;
  int stage_v_127_2 = (stage_v_106_2 ^ pub_r001827_10_2) & 63;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((stage_v_96_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  }
  if ((stage_v_127_2 & 1) != 0)
  {
    if ((stage_v_96_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  }
  int stage_v_128_1 = ((pub_r001827_9_1 * 2) + 42) & 63;
  int stage_v_128_2 = ((pub_r001827_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001827_15_1 * 2) + 17) & 63;
  int stage_v_129_2 = ((pub_r001827_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001827_16_1 * 2) + 44) & 63;
  int stage_v_130_2 = ((pub_r001827_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (stage_v_61_1 ^ pub_r001827_13_1) & 63;
  int stage_v_131_2 = (stage_v_61_2 ^ pub_r001827_13_2) & 63;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((stage_v_84_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  }
  if ((stage_v_131_2 & 1) != 0)
  {
    if ((stage_v_84_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  }
  int stage_v_132_1 = (stage_v_124_1 ^ pub_r001827_1_1) & 63;
  int stage_v_132_2 = (stage_v_124_2 ^ pub_r001827_1_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((stage_v_46_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((stage_v_46_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  }
  int stage_v_133_1 = (sec_r001827_12_1 ^ pub_r001827_16_1) & 63;
  int stage_v_133_2 = (sec_r001827_12_2 ^ pub_r001827_16_2) & 63;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((stage_v_77_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((stage_v_77_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  }
  int stage_v_134_1 = (stage_v_44_1 ^ pub_r001827_13_1) & 63;
  int stage_v_134_2 = (stage_v_44_2 ^ pub_r001827_13_2) & 63;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((sec_r001827_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  }
  if ((stage_v_134_2 & 1) != 0)
  {
    if ((sec_r001827_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  }
  int stage_v_135_1 = (stage_v_80_1 ^ pub_r001827_6_1) & 63;
  int stage_v_135_2 = (stage_v_80_2 ^ pub_r001827_6_2) & 63;
  if ((stage_v_135_1 & 1) != 0)
  {
    if ((stage_v_84_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  }
  if ((stage_v_135_2 & 1) != 0)
  {
    if ((stage_v_84_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  }
  int stage_v_136_1 = (stage_v_119_1 ^ pub_r001827_10_1) & 63;
  int stage_v_136_2 = (stage_v_119_2 ^ pub_r001827_10_2) & 63;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((stage_v_132_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((stage_v_132_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  }
  int stage_v_137_1 = (stage_v_15_1 ^ pub_r001827_18_1) & 63;
  int stage_v_137_2 = (stage_v_15_2 ^ pub_r001827_18_2) & 63;
  if ((stage_v_137_1 & 1) != 0)
  {
    if ((stage_v_88_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  }
  if ((stage_v_137_2 & 1) != 0)
  {
    if ((stage_v_88_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  }
  int stage_v_138_1 = (stage_v_53_1 ^ pub_r001827_9_1) & 63;
  int stage_v_138_2 = (stage_v_53_2 ^ pub_r001827_9_2) & 63;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((sec_r001827_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  }
  if ((stage_v_138_2 & 1) != 0)
  {
    if ((sec_r001827_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  }
  int stage_v_139_1 = (stage_v_73_1 ^ pub_r001827_19_1) & 63;
  int stage_v_139_2 = (stage_v_73_2 ^ pub_r001827_19_2) & 63;
  if ((stage_v_139_1 & 1) != 0)
  {
    if ((stage_v_99_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  }
  if ((stage_v_139_2 & 1) != 0)
  {
    if ((stage_v_99_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  }
  int stage_v_140_1 = ((pub_r001827_0_1 * 2) + 32) & 63;
  int stage_v_140_2 = ((pub_r001827_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (sec_r001827_16_1 ^ pub_r001827_3_1) & 63;
  int stage_v_141_2 = (sec_r001827_16_2 ^ pub_r001827_3_2) & 63;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((stage_v_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  }
  if ((stage_v_141_2 & 1) != 0)
  {
    if ((stage_v_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  }
  int stage_v_142_1 = (stage_v_137_1 ^ pub_r001827_15_1) & 63;
  int stage_v_142_2 = (stage_v_137_2 ^ pub_r001827_15_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((stage_v_61_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  }
  if ((stage_v_142_2 & 1) != 0)
  {
    if ((stage_v_61_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  }
  int stage_v_143_1 = (stage_v_85_1 ^ pub_r001827_15_1) & 63;
  int stage_v_143_2 = (stage_v_85_2 ^ pub_r001827_15_2) & 63;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((stage_v_88_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  }
  if ((stage_v_143_2 & 1) != 0)
  {
    if ((stage_v_88_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  }
  int stage_v_144_1 = (stage_v_127_1 ^ pub_r001827_2_1) & 63;
  int stage_v_144_2 = (stage_v_127_2 ^ pub_r001827_2_2) & 63;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((stage_v_65_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  }
  if ((stage_v_144_2 & 1) != 0)
  {
    if ((stage_v_65_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  }
  int stage_v_145_1 = (stage_v_18_1 ^ pub_r001827_1_1) & 63;
  int stage_v_145_2 = (stage_v_18_2 ^ pub_r001827_1_2) & 63;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((stage_v_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  }
  if ((stage_v_145_2 & 1) != 0)
  {
    if ((stage_v_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  }
  int stage_v_146_1 = ((pub_r001827_8_1 * 2) + 33) & 63;
  int stage_v_146_2 = ((pub_r001827_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (stage_v_77_1 ^ pub_r001827_7_1) & 63;
  int stage_v_147_2 = (stage_v_77_2 ^ pub_r001827_7_2) & 63;
  if ((stage_v_147_1 & 1) != 0)
  {
    if ((stage_v_118_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  }
  if ((stage_v_147_2 & 1) != 0)
  {
    if ((stage_v_118_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  }
  int stage_v_148_1 = (stage_v_10_1 ^ pub_r001827_14_1) & 63;
  int stage_v_148_2 = (stage_v_10_2 ^ pub_r001827_14_2) & 63;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((stage_v_96_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  }
  if ((stage_v_148_2 & 1) != 0)
  {
    if ((stage_v_96_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  }
  int stage_v_149_1 = ((pub_r001827_4_1 * 2) + 5) & 63;
  int stage_v_149_2 = ((pub_r001827_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (sec_r001827_5_1 ^ pub_r001827_11_1) & 63;
  int stage_v_150_2 = (sec_r001827_5_2 ^ pub_r001827_11_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((stage_v_118_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  }
  if ((stage_v_150_2 & 1) != 0)
  {
    if ((stage_v_118_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  }
  int stage_v_151_1 = (sec_r001827_17_1 ^ pub_r001827_11_1) & 63;
  int stage_v_151_2 = (sec_r001827_17_2 ^ pub_r001827_11_2) & 63;
  if ((stage_v_151_1 & 1) != 0)
  {
    if ((stage_v_139_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  }
  if ((stage_v_151_2 & 1) != 0)
  {
    if ((stage_v_139_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  }
  int stage_v_152_1 = (stage_v_15_1 ^ pub_r001827_11_1) & 63;
  int stage_v_152_2 = (stage_v_15_2 ^ pub_r001827_11_2) & 63;
  if ((stage_v_152_1 & 1) != 0)
  {
    if ((stage_v_94_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  }
  if ((stage_v_152_2 & 1) != 0)
  {
    if ((stage_v_94_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  }
  int stage_v_153_1 = (helper_flow_3_1 ^ pub_r001827_18_1) & 63;
  int stage_v_153_2 = (helper_flow_3_2 ^ pub_r001827_18_2) & 63;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((stage_v_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  }
  if ((stage_v_153_2 & 1) != 0)
  {
    if ((stage_v_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  }
  int stage_v_154_1 = ((pub_r001827_2_1 * 2) + 8) & 63;
  int stage_v_154_2 = ((pub_r001827_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001827_13_1 * 2) + 37) & 63;
  int stage_v_155_2 = ((pub_r001827_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001827_9_1 * 2) + 27) & 63;
  int stage_v_156_2 = ((pub_r001827_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001827_14_1 * 2) + 43) & 63;
  int stage_v_157_2 = ((pub_r001827_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (stage_v_26_1 ^ pub_r001827_16_1) & 63;
  int stage_v_158_2 = (stage_v_26_2 ^ pub_r001827_16_2) & 63;
  if ((stage_v_158_1 & 1) != 0)
  {
    if ((stage_v_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  }
  if ((stage_v_158_2 & 1) != 0)
  {
    if ((stage_v_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  }
  int stage_v_159_1 = ((pub_r001827_17_1 * 2) + 30) & 63;
  int stage_v_159_2 = ((pub_r001827_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (stage_v_124_1 ^ pub_r001827_7_1) & 63;
  int stage_v_160_2 = (stage_v_124_2 ^ pub_r001827_7_2) & 63;
  if ((stage_v_160_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_160_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  }
  if ((stage_v_160_2 & 1) != 0)
  {
    if ((stage_v_60_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_160_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  }
  int stage_v_161_1 = (stage_v_141_1 ^ pub_r001827_13_1) & 63;
  int stage_v_161_2 = (stage_v_141_2 ^ pub_r001827_13_2) & 63;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((stage_v_114_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_161_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  }
  if ((stage_v_161_2 & 1) != 0)
  {
    if ((stage_v_114_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_161_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  }
  int stage_v_162_1 = (stage_v_91_1 ^ pub_r001827_18_1) & 63;
  int stage_v_162_2 = (stage_v_91_2 ^ pub_r001827_18_2) & 63;
  if ((stage_v_162_1 & 1) != 0)
  {
    if ((stage_v_124_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  }
  if ((stage_v_162_2 & 1) != 0)
  {
    if ((stage_v_124_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  }
  int stage_v_163_1 = (stage_v_92_1 ^ pub_r001827_10_1) & 63;
  int stage_v_163_2 = (stage_v_92_2 ^ pub_r001827_10_2) & 63;
  if ((stage_v_163_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_163_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  }
  if ((stage_v_163_2 & 1) != 0)
  {
    if ((stage_v_72_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_163_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  }
  int stage_v_164_1 = (stage_v_82_1 ^ pub_r001827_6_1) & 63;
  int stage_v_164_2 = (stage_v_82_2 ^ pub_r001827_6_2) & 63;
  if ((stage_v_164_1 & 1) != 0)
  {
    if ((sec_r001827_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  }
  if ((stage_v_164_2 & 1) != 0)
  {
    if ((sec_r001827_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  }
  int stage_v_165_1 = (stage_v_15_1 ^ pub_r001827_7_1) & 63;
  int stage_v_165_2 = (stage_v_15_2 ^ pub_r001827_7_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((stage_v_68_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_165_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  }
  if ((stage_v_165_2 & 1) != 0)
  {
    if ((stage_v_68_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_165_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  }
  int stage_v_166_1 = (stage_v_117_1 ^ pub_r001827_4_1) & 63;
  int stage_v_166_2 = (stage_v_117_2 ^ pub_r001827_4_2) & 63;
  if ((stage_v_166_1 & 1) != 0)
  {
    if ((stage_v_162_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_166_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  }
  if ((stage_v_166_2 & 1) != 0)
  {
    if ((stage_v_162_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_166_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  }
  int stage_v_167_1 = ((pub_r001827_13_1 * 2) + 39) & 63;
  int stage_v_167_2 = ((pub_r001827_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = (stage_v_102_1 ^ pub_r001827_16_1) & 63;
  int stage_v_168_2 = (stage_v_102_2 ^ pub_r001827_16_2) & 63;
  if ((stage_v_168_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_168_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  }
  if ((stage_v_168_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_168_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  }
  int stage_v_169_1 = (stage_v_38_1 ^ pub_r001827_12_1) & 63;
  int stage_v_169_2 = (stage_v_38_2 ^ pub_r001827_12_2) & 63;
  if ((stage_v_169_1 & 1) != 0)
  {
    if ((stage_v_106_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_169_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  }
  if ((stage_v_169_2 & 1) != 0)
  {
    if ((stage_v_106_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_169_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  }
  int stage_v_170_1 = ((pub_r001827_11_1 * 2) + 32) & 63;
  int stage_v_170_2 = ((pub_r001827_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (stage_v_81_1 ^ pub_r001827_0_1) & 63;
  int stage_v_171_2 = (stage_v_81_2 ^ pub_r001827_0_2) & 63;
  if ((stage_v_171_1 & 1) != 0)
  {
    if ((stage_v_51_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_171_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  }
  if ((stage_v_171_2 & 1) != 0)
  {
    if ((stage_v_51_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_171_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  }
  int stage_v_172_1 = (stage_v_139_1 ^ pub_r001827_8_1) & 63;
  int stage_v_172_2 = (stage_v_139_2 ^ pub_r001827_8_2) & 63;
  if ((stage_v_172_1 & 1) != 0)
  {
    if ((stage_v_144_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_172_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  }
  if ((stage_v_172_2 & 1) != 0)
  {
    if ((stage_v_144_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_172_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  }
  int stage_v_173_1 = (stage_v_133_1 ^ pub_r001827_17_1) & 63;
  int stage_v_173_2 = (stage_v_133_2 ^ pub_r001827_17_2) & 63;
  if ((stage_v_173_1 & 1) != 0)
  {
    if ((stage_v_126_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_173_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  }
  if ((stage_v_173_2 & 1) != 0)
  {
    if ((stage_v_126_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_173_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  }
  int stage_v_174_1 = (stage_v_166_1 ^ pub_r001827_15_1) & 63;
  int stage_v_174_2 = (stage_v_166_2 ^ pub_r001827_15_2) & 63;
  if ((stage_v_174_1 & 1) != 0)
  {
    if ((stage_v_133_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_174_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  }
  if ((stage_v_174_2 & 1) != 0)
  {
    if ((stage_v_133_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_174_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  }
  int stage_v_175_1 = (stage_v_73_1 ^ pub_r001827_17_1) & 63;
  int stage_v_175_2 = (stage_v_73_2 ^ pub_r001827_17_2) & 63;
  if ((stage_v_175_1 & 1) != 0)
  {
    if ((stage_v_132_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_175_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  }
  if ((stage_v_175_2 & 1) != 0)
  {
    if ((stage_v_132_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_175_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  }
  int stage_v_176_1 = (stage_v_77_1 ^ pub_r001827_18_1) & 63;
  int stage_v_176_2 = (stage_v_77_2 ^ pub_r001827_18_2) & 63;
  if ((stage_v_176_1 & 1) != 0)
  {
    if ((stage_v_137_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_176_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  }
  if ((stage_v_176_2 & 1) != 0)
  {
    if ((stage_v_137_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_176_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  }
  int stage_v_177_1 = ((pub_r001827_7_1 * 2) + 49) & 63;
  int stage_v_177_2 = ((pub_r001827_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001827_3_1 * 2) + 42) & 63;
  int stage_v_178_2 = ((pub_r001827_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (stage_v_15_1 ^ pub_r001827_14_1) & 63;
  int stage_v_179_2 = (stage_v_15_2 ^ pub_r001827_14_2) & 63;
  if ((stage_v_179_1 & 1) != 0)
  {
    if ((stage_v_81_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_179_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  }
  if ((stage_v_179_2 & 1) != 0)
  {
    if ((stage_v_81_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_179_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  }
  int stage_v_180_1 = ((pub_r001827_0_1 * 2) + 46) & 63;
  int stage_v_180_2 = ((pub_r001827_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (stage_v_92_1 ^ pub_r001827_14_1) & 63;
  int stage_v_181_2 = (stage_v_92_2 ^ pub_r001827_14_2) & 63;
  if ((stage_v_181_1 & 1) != 0)
  {
    if ((sec_r001827_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_181_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  }
  if ((stage_v_181_2 & 1) != 0)
  {
    if ((sec_r001827_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_181_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  }
  int stage_v_182_1 = (stage_v_181_1 ^ pub_r001827_15_1) & 63;
  int stage_v_182_2 = (stage_v_181_2 ^ pub_r001827_15_2) & 63;
  if ((stage_v_182_1 & 1) != 0)
  {
    if ((stage_v_116_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_182_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  }
  if ((stage_v_182_2 & 1) != 0)
  {
    if ((stage_v_116_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_182_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  }
  int stage_v_183_1 = (stage_v_166_1 ^ pub_r001827_5_1) & 63;
  int stage_v_183_2 = (stage_v_166_2 ^ pub_r001827_5_2) & 63;
  if ((stage_v_183_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_183_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  }
  if ((stage_v_183_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_183_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  }
  int stage_v_184_1 = (sec_r001827_13_1 ^ pub_r001827_0_1) & 63;
  int stage_v_184_2 = (sec_r001827_13_2 ^ pub_r001827_0_2) & 63;
  if ((stage_v_184_1 & 1) != 0)
  {
    if ((stage_v_116_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_184_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  }
  if ((stage_v_184_2 & 1) != 0)
  {
    if ((stage_v_116_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_184_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  }
  int stage_v_185_1 = (stage_v_77_1 ^ pub_r001827_19_1) & 63;
  int stage_v_185_2 = (stage_v_77_2 ^ pub_r001827_19_2) & 63;
  if ((stage_v_185_1 & 1) != 0)
  {
    if ((stage_v_46_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_185_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  }
  if ((stage_v_185_2 & 1) != 0)
  {
    if ((stage_v_46_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_185_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  }
  int stage_v_186_1 = (sec_r001827_10_1 ^ pub_r001827_10_1) & 63;
  int stage_v_186_2 = (sec_r001827_10_2 ^ pub_r001827_10_2) & 63;
  if ((stage_v_186_1 & 1) != 0)
  {
    if ((stage_v_125_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_186_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  }
  if ((stage_v_186_2 & 1) != 0)
  {
    if ((stage_v_125_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_186_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  }
  int stage_v_187_1 = (stage_v_160_1 ^ pub_r001827_3_1) & 63;
  int stage_v_187_2 = (stage_v_160_2 ^ pub_r001827_3_2) & 63;
  if ((stage_v_187_1 & 1) != 0)
  {
    if ((stage_v_49_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_187_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  }
  if ((stage_v_187_2 & 1) != 0)
  {
    if ((stage_v_49_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_187_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  }
  int stage_v_188_1 = (helper_flow_0_1 ^ pub_r001827_13_1) & 63;
  int stage_v_188_2 = (helper_flow_0_2 ^ pub_r001827_13_2) & 63;
  if ((stage_v_188_1 & 1) != 0)
  {
    if ((stage_v_172_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_188_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  }
  if ((stage_v_188_2 & 1) != 0)
  {
    if ((stage_v_172_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_188_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  }
  int stage_v_189_1 = ((pub_r001827_13_1 * 2) + 7) & 63;
  int stage_v_189_2 = ((pub_r001827_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (sec_r001827_7_1 ^ pub_r001827_11_1) & 63;
  int stage_v_190_2 = (sec_r001827_7_2 ^ pub_r001827_11_2) & 63;
  if ((stage_v_190_1 & 1) != 0)
  {
    if ((stage_v_122_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_190_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  }
  if ((stage_v_190_2 & 1) != 0)
  {
    if ((stage_v_122_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_190_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  }
  int stage_v_191_1 = (stage_v_160_1 ^ pub_r001827_13_1) & 63;
  int stage_v_191_2 = (stage_v_160_2 ^ pub_r001827_13_2) & 63;
  if ((stage_v_191_1 & 1) != 0)
  {
    if ((sec_r001827_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_191_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  }
  if ((stage_v_191_2 & 1) != 0)
  {
    if ((sec_r001827_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_191_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  }
  int stage_v_192_1 = ((pub_r001827_5_1 * 2) + 36) & 63;
  int stage_v_192_2 = ((pub_r001827_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001827_1_1 * 2) + 28) & 63;
  int stage_v_193_2 = ((pub_r001827_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (stage_v_14_1 ^ pub_r001827_14_1) & 63;
  int stage_v_194_2 = (stage_v_14_2 ^ pub_r001827_14_2) & 63;
  if ((stage_v_194_1 & 1) != 0)
  {
    if ((stage_v_135_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_194_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  }
  if ((stage_v_194_2 & 1) != 0)
  {
    if ((stage_v_135_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_194_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  }
  int stage_v_195_1 = (stage_v_176_1 ^ pub_r001827_17_1) & 63;
  int stage_v_195_2 = (stage_v_176_2 ^ pub_r001827_17_2) & 63;
  if ((stage_v_195_1 & 1) != 0)
  {
    if ((stage_v_59_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_195_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  }
  if ((stage_v_195_2 & 1) != 0)
  {
    if ((stage_v_59_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_195_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  }
  int stage_v_196_1 = (stage_v_166_1 ^ pub_r001827_16_1) & 63;
  int stage_v_196_2 = (stage_v_166_2 ^ pub_r001827_16_2) & 63;
  if ((stage_v_196_1 & 1) != 0)
  {
    if ((stage_v_45_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_196_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  }
  if ((stage_v_196_2 & 1) != 0)
  {
    if ((stage_v_45_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_196_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  }
  int stage_v_197_1 = (helper_flow_2_1 ^ pub_r001827_10_1) & 63;
  int stage_v_197_2 = (helper_flow_2_2 ^ pub_r001827_10_2) & 63;
  if ((stage_v_197_1 & 1) != 0)
  {
    if ((stage_v_133_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_197_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  }
  if ((stage_v_197_2 & 1) != 0)
  {
    if ((stage_v_133_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_197_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  }
  int stage_v_198_1 = (helper_flow_2_1 ^ pub_r001827_1_1) & 63;
  int stage_v_198_2 = (helper_flow_2_2 ^ pub_r001827_1_2) & 63;
  if ((stage_v_198_1 & 1) != 0)
  {
    if ((stage_v_162_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_198_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  }
  if ((stage_v_198_2 & 1) != 0)
  {
    if ((stage_v_162_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_198_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  }
  int stage_v_199_1 = (stage_v_48_1 ^ pub_r001827_1_1) & 63;
  int stage_v_199_2 = (stage_v_48_2 ^ pub_r001827_1_2) & 63;
  if ((stage_v_199_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_199_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  }
  if ((stage_v_199_2 & 1) != 0)
  {
    if ((helper_flow_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_199_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  }
  int stage_v_200_1 = (stage_v_68_1 ^ pub_r001827_8_1) & 63;
  int stage_v_200_2 = (stage_v_68_2 ^ pub_r001827_8_2) & 63;
  if ((stage_v_200_1 & 1) != 0)
  {
    if ((stage_v_52_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_200_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  }
  if ((stage_v_200_2 & 1) != 0)
  {
    if ((stage_v_52_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_200_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  }
  int stage_v_201_1 = (stage_v_151_1 ^ pub_r001827_11_1) & 63;
  int stage_v_201_2 = (stage_v_151_2 ^ pub_r001827_11_2) & 63;
  if ((stage_v_201_1 & 1) != 0)
  {
    if ((sec_r001827_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_201_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  }
  if ((stage_v_201_2 & 1) != 0)
  {
    if ((sec_r001827_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_201_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  }
  int stage_v_202_1 = ((pub_r001827_9_1 * 2) + 50) & 63;
  int stage_v_202_2 = ((pub_r001827_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (stage_v_68_1 ^ pub_r001827_5_1) & 63;
  int stage_v_203_2 = (stage_v_68_2 ^ pub_r001827_5_2) & 63;
  if ((stage_v_203_1 & 1) != 0)
  {
    if ((stage_v_59_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_203_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  }
  if ((stage_v_203_2 & 1) != 0)
  {
    if ((stage_v_59_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_203_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  }
  int stage_v_204_1 = (helper_flow_2_1 ^ pub_r001827_18_1) & 63;
  int stage_v_204_2 = (helper_flow_2_2 ^ pub_r001827_18_2) & 63;
  if ((stage_v_204_1 & 1) != 0)
  {
    if ((sec_r001827_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_204_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  }
  if ((stage_v_204_2 & 1) != 0)
  {
    if ((sec_r001827_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_204_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  }
  int stage_v_205_1 = (stage_v_51_1 ^ pub_r001827_14_1) & 63;
  int stage_v_205_2 = (stage_v_51_2 ^ pub_r001827_14_2) & 63;
  if ((stage_v_205_1 & 1) != 0)
  {
    if ((stage_v_201_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_205_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_205_1 * 2)) & 255;
  }
  if ((stage_v_205_2 & 1) != 0)
  {
    if ((stage_v_201_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_205_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_205_2 * 2)) & 255;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001827_0_1 == pub_r001827_0_2);
  __CPROVER_assume(sec_r001827_0_1 != sec_r001827_0_2);
  __CPROVER_assume(sec_r001827_11_1 != sec_r001827_11_2);
  __CPROVER_assume(sec_r001827_15_1 != sec_r001827_15_2);
  __CPROVER_assume(pub_r001827_6_1 == pub_r001827_6_2);
  __CPROVER_assume(sec_r001827_17_1 != sec_r001827_17_2);
  __CPROVER_assume(sec_r001827_7_1 != sec_r001827_7_2);
  __CPROVER_assume(sec_r001827_10_1 != sec_r001827_10_2);
  __CPROVER_assume(sec_r001827_13_1 != sec_r001827_13_2);
  __CPROVER_assume(sec_r001827_3_1 != sec_r001827_3_2);
  __CPROVER_assume(sec_r001827_19_1 != sec_r001827_19_2);
  __CPROVER_assume(sec_r001827_18_1 != sec_r001827_18_2);
  __CPROVER_assume(pub_r001827_4_1 == pub_r001827_4_2);
  __CPROVER_assume(sec_r001827_12_1 != sec_r001827_12_2);
  __CPROVER_assume(pub_r001827_12_1 == pub_r001827_12_2);
  __CPROVER_assume(pub_r001827_5_1 == pub_r001827_5_2);
  __CPROVER_assume(pub_r001827_7_1 == pub_r001827_7_2);
  __CPROVER_assume(pub_r001827_2_1 == pub_r001827_2_2);
  __CPROVER_assume(pub_r001827_8_1 == pub_r001827_8_2);
  __CPROVER_assume(sec_r001827_4_1 != sec_r001827_4_2);
  __CPROVER_assume(sec_r001827_20_1 != sec_r001827_20_2);
  __CPROVER_assume(pub_r001827_3_1 == pub_r001827_3_2);
  __CPROVER_assume(pub_r001827_15_1 == pub_r001827_15_2);
  __CPROVER_assume(pub_r001827_19_1 == pub_r001827_19_2);
  __CPROVER_assume(sec_r001827_2_1 != sec_r001827_2_2);
  __CPROVER_assume(pub_r001827_10_1 == pub_r001827_10_2);
  __CPROVER_assume(pub_r001827_11_1 == pub_r001827_11_2);
  __CPROVER_assume(sec_r001827_5_1 != sec_r001827_5_2);
  __CPROVER_assume(sec_r001827_6_1 != sec_r001827_6_2);
  __CPROVER_assume(pub_r001827_14_1 == pub_r001827_14_2);
  __CPROVER_assume(pub_r001827_18_1 == pub_r001827_18_2);
  __CPROVER_assume(pub_r001827_1_1 == pub_r001827_1_2);
  __CPROVER_assume(sec_r001827_16_1 != sec_r001827_16_2);
  __CPROVER_assume(pub_r001827_17_1 == pub_r001827_17_2);
  __CPROVER_assume(sec_r001827_8_1 != sec_r001827_8_2);
  __CPROVER_assume(sec_r001827_9_1 != sec_r001827_9_2);
  __CPROVER_assume(pub_r001827_9_1 == pub_r001827_9_2);
  __CPROVER_assume(pub_r001827_16_1 == pub_r001827_16_2);
  __CPROVER_assume(sec_r001827_14_1 != sec_r001827_14_2);
  __CPROVER_assume(pub_r001827_13_1 == pub_r001827_13_2);
  __CPROVER_assume(sec_r001827_1_1 != sec_r001827_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.code == st_var_1_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.capacity == st_var_2_2.capacity);
  assert(st_var_2_1.watermark == st_var_2_2.watermark);
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

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
  assert(helper_flow_3_1 == helper_flow_3_2);
  assert(helper_flow_4_1 == helper_flow_4_2);
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
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
}


