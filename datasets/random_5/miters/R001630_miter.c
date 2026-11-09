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
struct Transaction_R001630_3013_0
{
  short fee;
  int auth_code;
  int account_id;
  int buffer[3];
};
struct FilterState_R001630_3013_1
{
  int cutoff;
  short damping;
  unsigned char prev_out;
  int prev_in;
  int buffer[3];
};
struct StreamBuffer_R001630_3013_2
{
  unsigned char head;
  int state;
  short checksum;
  unsigned char capacity;
  unsigned char tail;
  short watermark;
  int buffer[3];
};
struct DeviceConfig_R001630_3013_3
{
  int stop_bits;
  int port;
  short baud_rate;
  int parity;
  int buffer[3];
};
union ColorPixel_R001630_3013_0
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
void fn_R001630_3013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001630_3013_3 st_1 = {0};
  struct DeviceConfig_R001630_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_12_1 > 27)
  {
    acc_1 = ((acc_1 + (quotient_12_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_12_2 > 27)
  {
    acc_2 = ((acc_2 + (quotient_12_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_55_1) & 63;
  aux_2 = (aux_2 + sample_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_12_1 == quotient_12_2);
  assert(sample_55_1 == sample_55_2);
}

int fn_R001630_3013_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001630_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_12 > 27)
  {
    acc = ((acc + (quotient_12 * 2)) + 5) & 127;
    aux ^= quotient_12 & 15;
  }
  else
  {
    acc = ((acc - quotient_12) + 11) & 127;
    aux += 3;
  }
  int sample_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_55) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001630_3013_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st_1 = {0};
  struct Transaction_R001630_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int offset_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_79_1)
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

  switch (offset_79_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_79_1 == offset_79_2);
}

int fn_R001630_3013_1(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int offset_79 = (aux + st.buffer[1]) & 3;
  switch (offset_79)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001630_3013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st_1 = {0};
  struct Transaction_R001630_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_61_1 = local_arr_1[aux_1 % 3];
  int window_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_61_2 * 2)) & 127;
  int index_reg_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_13_1) & 63;
  aux_2 = (aux_2 + index_reg_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_34_1 > 21)
  {
    acc_1 = ((acc_1 + (phase_34_1 * 2)) + 5) & 127;
    aux_1 ^= phase_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_34_2 > 21)
  {
    acc_2 = ((acc_2 + (phase_34_2 * 2)) + 5) & 127;
    aux_2 ^= phase_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_34_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
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

  assert(window_61_1 == window_61_2);
  assert(index_reg_13_1 == index_reg_13_2);
  assert(phase_34_1 == phase_34_2);
}

int fn_R001630_3013_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int window_61 = local_arr[aux % 3];
  acc = (acc + (window_61 * 2)) & 127;
  int index_reg_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_13) & 63;
  acc ^= aux;
  int phase_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_34 > 21)
  {
    acc = ((acc + (phase_34 * 2)) + 5) & 127;
    aux ^= phase_34 & 15;
  }
  else
  {
    acc = ((acc - phase_34) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001630_3013_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001630_3013_2 st_1 = {0};
  struct StreamBuffer_R001630_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int threshold_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_39_1)
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

  switch (threshold_39_2)
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
  int offset_49_1 = local_arr_1[aux_1 % 3];
  int offset_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_49_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_39_1 == threshold_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_49_1 == offset_49_2);
}

int fn_R001630_3013_3(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001630_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int threshold_39 = (aux + st.buffer[1]) & 3;
  switch (threshold_39)
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
  int offset_49 = local_arr[aux % 3];
  acc = (acc + (offset_49 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001630_3013_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001630_3013_3 st_1 = {0};
  struct DeviceConfig_R001630_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int scale_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_56_1 > 25)
  {
    acc_1 = ((acc_1 + (scale_56_1 * 2)) + 5) & 127;
    aux_1 ^= scale_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_56_2 > 25)
  {
    acc_2 = ((acc_2 + (scale_56_2 * 2)) + 5) & 127;
    aux_2 ^= scale_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_84_1 = 0;
  int bound_84_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_84_1 = ((bound_84_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_84_2 = ((bound_84_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_84_1) & 127;
    acc_2 = (acc_2 + bound_84_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_56_1 == scale_56_2);
  assert(bound_84_1 == bound_84_2);
}

int fn_R001630_3013_4(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001630_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int scale_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_56 > 25)
  {
    acc = ((acc + (scale_56 * 2)) + 5) & 127;
    aux ^= scale_56 & 15;
  }
  else
  {
    acc = ((acc - scale_56) + 11) & 127;
    aux += 3;
  }
  int bound_84 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_84 = ((bound_84 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_84) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001630_3013_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001630_3013_1 st_1 = {0};
  struct FilterState_R001630_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int scale_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_81_1) & 63;
  aux_2 = (aux_2 + scale_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_81_1 == scale_81_2);
}

int fn_R001630_3013_5(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001630_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int scale_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_81) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001630_3013_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001630_3013_1 st_1 = {0};
  struct FilterState_R001630_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int anchor_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_72_1) & 63;
  aux_2 = (aux_2 + anchor_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_34_1 = 0;
  int tracker_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_34_1 = ((tracker_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_34_2 = ((tracker_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_34_1) & 127;
    acc_2 = (acc_2 + tracker_34_2) & 127;
  }

  int vector_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_42_1 > 21)
  {
    acc_1 = ((acc_1 + (vector_42_1 * 2)) + 5) & 127;
    aux_1 ^= vector_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_42_2 > 21)
  {
    acc_2 = ((acc_2 + (vector_42_2 * 2)) + 5) & 127;
    aux_2 ^= vector_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_72_1 == anchor_72_2);
  assert(tracker_34_1 == tracker_34_2);
  assert(vector_42_1 == vector_42_2);
}

int fn_R001630_3013_6(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001630_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int anchor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_72) & 63;
  acc ^= aux;
  int tracker_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_34 = ((tracker_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_34) & 127;
  }

  int vector_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_42 > 21)
  {
    acc = ((acc + (vector_42 * 2)) + 5) & 127;
    aux ^= vector_42 & 15;
  }
  else
  {
    acc = ((acc - vector_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001630_3013_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001630_3013_2 st_1 = {0};
  struct StreamBuffer_R001630_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int window_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_46_1 > 12)
  {
    acc_1 = ((acc_1 + (window_46_1 * 2)) + 5) & 127;
    aux_1 ^= window_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_46_2 > 12)
  {
    acc_2 = ((acc_2 + (window_46_2 * 2)) + 5) & 127;
    aux_2 ^= window_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_60_1)
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

  switch (metric_60_2)
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
  int threshold_72_1 = local_arr_1[aux_1 % 3];
  int threshold_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_72_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_46_1 == window_46_2);
  assert(metric_60_1 == metric_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_72_1 == threshold_72_2);
}

int fn_R001630_3013_7(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001630_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int window_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_46 > 12)
  {
    acc = ((acc + (window_46 * 2)) + 5) & 127;
    aux ^= window_46 & 15;
  }
  else
  {
    acc = ((acc - window_46) + 11) & 127;
    aux += 3;
  }
  int metric_60 = (aux + st.buffer[1]) & 3;
  switch (metric_60)
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
  int threshold_72 = local_arr[aux % 3];
  acc = (acc + (threshold_72 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001630_3013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001630_3013_2 st_1 = {0};
  struct StreamBuffer_R001630_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int quantum_15_1 = 0;
  int quantum_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_15_1 = ((quantum_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_15_2 = ((quantum_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_15_1) & 127;
    acc_2 = (acc_2 + quantum_15_2) & 127;
  }

  int factor_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_97_1) & 63;
  aux_2 = (aux_2 + factor_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_37_1 > 12)
  {
    acc_1 = ((acc_1 + (bound_37_1 * 2)) + 5) & 127;
    aux_1 ^= bound_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_37_2 > 12)
  {
    acc_2 = ((acc_2 + (bound_37_2 * 2)) + 5) & 127;
    aux_2 ^= bound_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_37_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_15_1 == quantum_15_2);
  assert(factor_97_1 == factor_97_2);
  assert(bound_37_1 == bound_37_2);
}

int fn_R001630_3013_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001630_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int quantum_15 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_15 = ((quantum_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_15) & 127;
  }

  int factor_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_97) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_37 > 12)
  {
    acc = ((acc + (bound_37 * 2)) + 5) & 127;
    aux ^= bound_37 & 15;
  }
  else
  {
    acc = ((acc - bound_37) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001630_3013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st_1 = {0};
  struct Transaction_R001630_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int checksum_14_1 = 0;
  int checksum_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_14_1 = ((checksum_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_14_2 = ((checksum_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_14_1) & 127;
    acc_2 = (acc_2 + checksum_14_2) & 127;
  }

  int quotient_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_73_1 > 25)
  {
    acc_1 = ((acc_1 + (quotient_73_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_73_2 > 25)
  {
    acc_2 = ((acc_2 + (quotient_73_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_73_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_14_1 == checksum_14_2);
  assert(quotient_73_1 == quotient_73_2);
}

int fn_R001630_3013_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int checksum_14 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_14 = ((checksum_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_14) & 127;
  }

  int quotient_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_73 > 25)
  {
    acc = ((acc + (quotient_73 * 2)) + 5) & 127;
    aux ^= quotient_73 & 15;
  }
  else
  {
    acc = ((acc - quotient_73) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001630_3013_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st_1 = {0};
  struct Transaction_R001630_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int quantum_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_60_1 > 18)
  {
    acc_1 = ((acc_1 + (quantum_60_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_60_2 > 18)
  {
    acc_2 = ((acc_2 + (quantum_60_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_60_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_60_1 == quantum_60_2);
}

int fn_R001630_3013_10(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int quantum_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_60 > 18)
  {
    acc = ((acc + (quantum_60 * 2)) + 5) & 127;
    aux ^= quantum_60 & 15;
  }
  else
  {
    acc = ((acc - quantum_60) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001630_3013_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001630_3013_3 st_1 = {0};
  struct DeviceConfig_R001630_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int factor_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_71_1 > 16)
  {
    acc_1 = ((acc_1 + (factor_71_1 * 2)) + 5) & 127;
    aux_1 ^= factor_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_71_2 > 16)
  {
    acc_2 = ((acc_2 + (factor_71_2 * 2)) + 5) & 127;
    aux_2 ^= factor_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_67_1) & 63;
  aux_2 = (aux_2 + segment_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_36_1 = local_arr_1[aux_1 % 3];
  int stride_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_71_1 == factor_71_2);
  assert(segment_67_1 == segment_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_36_1 == stride_36_2);
}

int fn_R001630_3013_11(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001630_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int factor_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_71 > 16)
  {
    acc = ((acc + (factor_71 * 2)) + 5) & 127;
    aux ^= factor_71 & 15;
  }
  else
  {
    acc = ((acc - factor_71) + 11) & 127;
    aux += 3;
  }
  int segment_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_67) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_36 = local_arr[aux % 3];
  acc = (acc + (stride_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001630_3013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st_1 = {0};
  struct Transaction_R001630_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int tracker_99_1 = 0;
  int tracker_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_99_1 = ((tracker_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_99_2 = ((tracker_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_99_1) & 127;
    acc_2 = (acc_2 + tracker_99_2) & 127;
  }

  int phase_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_90_1) & 63;
  aux_2 = (aux_2 + phase_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_86_1 > 29)
  {
    acc_1 = ((acc_1 + (stride_86_1 * 2)) + 5) & 127;
    aux_1 ^= stride_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_86_2 > 29)
  {
    acc_2 = ((acc_2 + (stride_86_2 * 2)) + 5) & 127;
    aux_2 ^= stride_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_91_1)
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

  switch (anchor_91_2)
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
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_99_1 == tracker_99_2);
  assert(phase_90_1 == phase_90_2);
  assert(stride_86_1 == stride_86_2);
  assert(anchor_91_1 == anchor_91_2);
}

int fn_R001630_3013_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int tracker_99 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_99 = ((tracker_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_99) & 127;
  }

  int phase_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_90) & 63;
  acc ^= aux;
  int stride_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_86 > 29)
  {
    acc = ((acc + (stride_86 * 2)) + 5) & 127;
    aux ^= stride_86 & 15;
  }
  else
  {
    acc = ((acc - stride_86) + 11) & 127;
    aux += 3;
  }
  int anchor_91 = (aux + st.buffer[1]) & 3;
  switch (anchor_91)
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

void fn_R001630_3013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001630_3013_3 st_1 = {0};
  struct DeviceConfig_R001630_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int margin_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_28_1) & 63;
  aux_2 = (aux_2 + margin_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_52_1 = local_arr_1[aux_1 % 3];
  int tracker_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_52_2 * 2)) & 127;
  int margin_62_1 = 0;
  int margin_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_62_1 = ((margin_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_62_2 = ((margin_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_62_1) & 127;
    acc_2 = (acc_2 + margin_62_2) & 127;
  }

  int coefficient_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_78_1 > 42)
  {
    acc_1 = ((acc_1 + (coefficient_78_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_78_2 > 42)
  {
    acc_2 = ((acc_2 + (coefficient_78_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_28_1 == margin_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_52_1 == tracker_52_2);
  assert(margin_62_1 == margin_62_2);
  assert(coefficient_78_1 == coefficient_78_2);
}

int fn_R001630_3013_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001630_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int margin_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_28) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_52 = local_arr[aux % 3];
  acc = (acc + (tracker_52 * 2)) & 127;
  int margin_62 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_62 = ((margin_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_62) & 127;
  }

  int coefficient_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_78 > 42)
  {
    acc = ((acc + (coefficient_78 * 2)) + 5) & 127;
    aux ^= coefficient_78 & 15;
  }
  else
  {
    acc = ((acc - coefficient_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001630_3013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st_1 = {0};
  struct Transaction_R001630_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int index_reg_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_81_1)
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

  switch (index_reg_81_2)
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

  int metric_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_12_1) & 63;
  aux_2 = (aux_2 + metric_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_52_1 = local_arr_1[aux_1 % 3];
  int tracker_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_81_1 == index_reg_81_2);
  assert(metric_12_1 == metric_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_52_1 == tracker_52_2);
}

int fn_R001630_3013_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int index_reg_81 = (aux + st.buffer[1]) & 3;
  switch (index_reg_81)
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

  int metric_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_12) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_52 = local_arr[aux % 3];
  acc = (acc + (tracker_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001630_3013_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001630_3013_1 st_1 = {0};
  struct FilterState_R001630_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int mask_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_68_1 > 19)
  {
    acc_1 = ((acc_1 + (mask_68_1 * 2)) + 5) & 127;
    aux_1 ^= mask_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_68_2 > 19)
  {
    acc_2 = ((acc_2 + (mask_68_2 * 2)) + 5) & 127;
    aux_2 ^= mask_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_39_1) & 63;
  aux_2 = (aux_2 + residue_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_14_1)
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

  switch (quantum_14_2)
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

  int pivot_78_1 = 0;
  int pivot_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_78_1 = ((pivot_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_78_2 = ((pivot_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_78_1) & 127;
    acc_2 = (acc_2 + pivot_78_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_68_1 == mask_68_2);
  assert(residue_39_1 == residue_39_2);
  assert(quantum_14_1 == quantum_14_2);
  assert(pivot_78_1 == pivot_78_2);
}

int fn_R001630_3013_15(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001630_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int mask_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_68 > 19)
  {
    acc = ((acc + (mask_68 * 2)) + 5) & 127;
    aux ^= mask_68 & 15;
  }
  else
  {
    acc = ((acc - mask_68) + 11) & 127;
    aux += 3;
  }
  int residue_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_39) & 63;
  acc ^= aux;
  int quantum_14 = (aux + st.buffer[1]) & 3;
  switch (quantum_14)
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

  int pivot_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_78 = ((pivot_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_78) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001630_3013_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001630_3013_1 st_1 = {0};
  struct FilterState_R001630_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_58_1 = local_arr_1[aux_1 % 3];
  int checksum_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_58_2 * 2)) & 127;
  int index_reg_14_1 = 0;
  int index_reg_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_14_1 = ((index_reg_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_14_2 = ((index_reg_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_14_1) & 127;
    acc_2 = (acc_2 + index_reg_14_2) & 127;
  }

  int tally_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_29_1 > 13)
  {
    acc_1 = ((acc_1 + (tally_29_1 * 2)) + 5) & 127;
    aux_1 ^= tally_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_29_2 > 13)
  {
    acc_2 = ((acc_2 + (tally_29_2 * 2)) + 5) & 127;
    aux_2 ^= tally_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_77_1) & 63;
  aux_2 = (aux_2 + index_reg_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_58_1 == checksum_58_2);
  assert(index_reg_14_1 == index_reg_14_2);
  assert(tally_29_1 == tally_29_2);
  assert(index_reg_77_1 == index_reg_77_2);
}

int fn_R001630_3013_16(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001630_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int checksum_58 = local_arr[aux % 3];
  acc = (acc + (checksum_58 * 2)) & 127;
  int index_reg_14 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_14 = ((index_reg_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_14) & 127;
  }

  int tally_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_29 > 13)
  {
    acc = ((acc + (tally_29 * 2)) + 5) & 127;
    aux ^= tally_29 & 15;
  }
  else
  {
    acc = ((acc - tally_29) + 11) & 127;
    aux += 3;
  }
  int index_reg_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_77) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001630_3013_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001630_3013_2 st_1 = {0};
  struct StreamBuffer_R001630_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_62_1 = local_arr_1[aux_1 % 3];
  int threshold_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_62_2 * 2)) & 127;
  int residue_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_30_1 > 21)
  {
    acc_1 = ((acc_1 + (residue_30_1 * 2)) + 5) & 127;
    aux_1 ^= residue_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_30_2 > 21)
  {
    acc_2 = ((acc_2 + (residue_30_2 * 2)) + 5) & 127;
    aux_2 ^= residue_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_30_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_62_1 == threshold_62_2);
  assert(residue_30_1 == residue_30_2);
}

int fn_R001630_3013_17(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001630_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int threshold_62 = local_arr[aux % 3];
  acc = (acc + (threshold_62 * 2)) & 127;
  int residue_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_30 > 21)
  {
    acc = ((acc + (residue_30 * 2)) + 5) & 127;
    aux ^= residue_30 & 15;
  }
  else
  {
    acc = ((acc - residue_30) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001630_3013_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st_1 = {0};
  struct Transaction_R001630_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int metric_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_70_1 > 15)
  {
    acc_1 = ((acc_1 + (metric_70_1 * 2)) + 5) & 127;
    aux_1 ^= metric_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_70_2 > 15)
  {
    acc_2 = ((acc_2 + (metric_70_2 * 2)) + 5) & 127;
    aux_2 ^= metric_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_45_1 = local_arr_1[aux_1 % 3];
  int quotient_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_45_2 * 2)) & 127;
  int residue_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_24_1) & 63;
  aux_2 = (aux_2 + residue_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_95_1)
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

  switch (phase_95_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_70_1 == metric_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_45_1 == quotient_45_2);
  assert(residue_24_1 == residue_24_2);
  assert(phase_95_1 == phase_95_2);
}

int fn_R001630_3013_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int metric_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_70 > 15)
  {
    acc = ((acc + (metric_70 * 2)) + 5) & 127;
    aux ^= metric_70 & 15;
  }
  else
  {
    acc = ((acc - metric_70) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_45 = local_arr[aux % 3];
  acc = (acc + (quotient_45 * 2)) & 127;
  int residue_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_24) & 63;
  acc ^= aux;
  int phase_95 = (aux + st.buffer[1]) & 3;
  switch (phase_95)
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

void fn_R001630_3013_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001630_3013_1 st_1 = {0};
  struct FilterState_R001630_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int vector_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_53_1)
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

  switch (vector_53_2)
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
  int coefficient_42_1 = local_arr_1[aux_1 % 3];
  int coefficient_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_42_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_53_1 == vector_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_42_1 == coefficient_42_2);
}

int fn_R001630_3013_19(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001630_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int vector_53 = (aux + st.buffer[1]) & 3;
  switch (vector_53)
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
  int coefficient_42 = local_arr[aux % 3];
  acc = (acc + (coefficient_42 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001630_3013_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st_1 = {0};
  struct Transaction_R001630_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int quotient_80_1 = 0;
  int quotient_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_80_1 = ((quotient_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_80_2 = ((quotient_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_80_1) & 127;
    acc_2 = (acc_2 + quotient_80_2) & 127;
  }

  int residue_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_79_1) & 63;
  aux_2 = (aux_2 + residue_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_80_1 == quotient_80_2);
  assert(residue_79_1 == residue_79_2);
}

int fn_R001630_3013_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001630_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int quotient_80 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_80 = ((quotient_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_80) & 127;
  }

  int residue_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_79) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001630_3013_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001630_3013_1 st_1 = {0};
  struct FilterState_R001630_3013_1 st_2 = {0};
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
  int segment_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_21_1) & 63;
  aux_2 = (aux_2 + segment_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_47_1)
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

  switch (damping_47_2)
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

  int window_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_43_1 > 49)
  {
    acc_1 = ((acc_1 + (window_43_1 * 2)) + 5) & 127;
    aux_1 ^= window_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_43_2 > 49)
  {
    acc_2 = ((acc_2 + (window_43_2 * 2)) + 5) & 127;
    aux_2 ^= window_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_43_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_21_1 == segment_21_2);
  assert(damping_47_1 == damping_47_2);
  assert(window_43_1 == window_43_2);
}

int fn_R001630_3013_21(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001630_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_21) & 63;
  acc ^= aux;
  int damping_47 = (aux + st.buffer[1]) & 3;
  switch (damping_47)
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

  int window_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_43 > 49)
  {
    acc = ((acc + (window_43 * 2)) + 5) & 127;
    aux ^= window_43 & 15;
  }
  else
  {
    acc = ((acc - window_43) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001630_3013_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001630_3013_3 st_1 = {0};
  struct DeviceConfig_R001630_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int residue_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_70_1) & 63;
  aux_2 = (aux_2 + residue_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_70_1 == residue_70_2);
}

int fn_R001630_3013_22(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001630_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int residue_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_70) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001630_0_1;
  int sec_r001630_0_2;
  int sec_r001630_1_1;
  int sec_r001630_1_2;
  int sec_r001630_2_1;
  int sec_r001630_2_2;
  int sec_r001630_3_1;
  int sec_r001630_3_2;
  int sec_r001630_4_1;
  int sec_r001630_4_2;
  int sec_r001630_5_1;
  int sec_r001630_5_2;
  int sec_r001630_6_1;
  int sec_r001630_6_2;
  int sec_r001630_7_1;
  int sec_r001630_7_2;
  int sec_r001630_8_1;
  int sec_r001630_8_2;
  int sec_r001630_9_1;
  int sec_r001630_9_2;
  int sec_r001630_10_1;
  int sec_r001630_10_2;
  int sec_r001630_11_1;
  int sec_r001630_11_2;
  int sec_r001630_12_1;
  int sec_r001630_12_2;
  int sec_r001630_13_1;
  int sec_r001630_13_2;
  int sec_r001630_14_1;
  int sec_r001630_14_2;
  int sec_r001630_15_1;
  int sec_r001630_15_2;
  int sec_r001630_16_1;
  int sec_r001630_16_2;
  int sec_r001630_17_1;
  int sec_r001630_17_2;
  int sec_r001630_18_1;
  int sec_r001630_18_2;
  int sec_r001630_19_1;
  int sec_r001630_19_2;
  int sec_r001630_20_1;
  int sec_r001630_20_2;
  int sec_r001630_21_1;
  int sec_r001630_21_2;
  int sec_r001630_22_1;
  int sec_r001630_22_2;
  int pub_r001630_0_1;
  int pub_r001630_0_2;
  int pub_r001630_1_1;
  int pub_r001630_1_2;
  int pub_r001630_2_1;
  int pub_r001630_2_2;
  int pub_r001630_3_1;
  int pub_r001630_3_2;
  int pub_r001630_4_1;
  int pub_r001630_4_2;
  int pub_r001630_5_1;
  int pub_r001630_5_2;
  int pub_r001630_6_1;
  int pub_r001630_6_2;
  int pub_r001630_7_1;
  int pub_r001630_7_2;
  int pub_r001630_8_1;
  int pub_r001630_8_2;
  int pub_r001630_9_1;
  int pub_r001630_9_2;
  int pub_r001630_10_1;
  int pub_r001630_10_2;
  int pub_r001630_11_1;
  int pub_r001630_11_2;
  int pub_r001630_12_1;
  int pub_r001630_12_2;
  int pub_r001630_13_1;
  int pub_r001630_13_2;
  int pub_r001630_14_1;
  int pub_r001630_14_2;
  int pub_r001630_15_1;
  int pub_r001630_15_2;
  int pub_r001630_16_1;
  int pub_r001630_16_2;
  int pub_r001630_17_1;
  int pub_r001630_17_2;
  int pub_r001630_18_1;
  int pub_r001630_18_2;
  int pub_r001630_19_1;
  int pub_r001630_19_2;
  int pub_r001630_20_1;
  int pub_r001630_20_2;
  int pub_r001630_21_1;
  int pub_r001630_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001630_0_1 >= (-100)) && (pub_r001630_0_1 <= 100));
  __CPROVER_assume((pub_r001630_0_2 >= (-100)) && (pub_r001630_0_2 <= 100));
  __CPROVER_assume((pub_r001630_1_1 >= (-100)) && (pub_r001630_1_1 <= 100));
  __CPROVER_assume((pub_r001630_1_2 >= (-100)) && (pub_r001630_1_2 <= 100));
  __CPROVER_assume((pub_r001630_2_1 >= (-100)) && (pub_r001630_2_1 <= 100));
  __CPROVER_assume((pub_r001630_2_2 >= (-100)) && (pub_r001630_2_2 <= 100));
  __CPROVER_assume((pub_r001630_3_1 >= (-100)) && (pub_r001630_3_1 <= 100));
  __CPROVER_assume((pub_r001630_3_2 >= (-100)) && (pub_r001630_3_2 <= 100));
  __CPROVER_assume((pub_r001630_4_1 >= (-100)) && (pub_r001630_4_1 <= 100));
  __CPROVER_assume((pub_r001630_4_2 >= (-100)) && (pub_r001630_4_2 <= 100));
  __CPROVER_assume((pub_r001630_5_1 >= (-100)) && (pub_r001630_5_1 <= 100));
  __CPROVER_assume((pub_r001630_5_2 >= (-100)) && (pub_r001630_5_2 <= 100));
  __CPROVER_assume((pub_r001630_6_1 >= (-100)) && (pub_r001630_6_1 <= 100));
  __CPROVER_assume((pub_r001630_6_2 >= (-100)) && (pub_r001630_6_2 <= 100));
  __CPROVER_assume((pub_r001630_7_1 >= (-100)) && (pub_r001630_7_1 <= 100));
  __CPROVER_assume((pub_r001630_7_2 >= (-100)) && (pub_r001630_7_2 <= 100));
  __CPROVER_assume((pub_r001630_8_1 >= (-100)) && (pub_r001630_8_1 <= 100));
  __CPROVER_assume((pub_r001630_8_2 >= (-100)) && (pub_r001630_8_2 <= 100));
  __CPROVER_assume((pub_r001630_9_1 >= (-100)) && (pub_r001630_9_1 <= 100));
  __CPROVER_assume((pub_r001630_9_2 >= (-100)) && (pub_r001630_9_2 <= 100));
  __CPROVER_assume((pub_r001630_10_1 >= (-100)) && (pub_r001630_10_1 <= 100));
  __CPROVER_assume((pub_r001630_10_2 >= (-100)) && (pub_r001630_10_2 <= 100));
  __CPROVER_assume((pub_r001630_11_1 >= (-100)) && (pub_r001630_11_1 <= 100));
  __CPROVER_assume((pub_r001630_11_2 >= (-100)) && (pub_r001630_11_2 <= 100));
  __CPROVER_assume((pub_r001630_12_1 >= (-100)) && (pub_r001630_12_1 <= 100));
  __CPROVER_assume((pub_r001630_12_2 >= (-100)) && (pub_r001630_12_2 <= 100));
  __CPROVER_assume((pub_r001630_13_1 >= (-100)) && (pub_r001630_13_1 <= 100));
  __CPROVER_assume((pub_r001630_13_2 >= (-100)) && (pub_r001630_13_2 <= 100));
  __CPROVER_assume((pub_r001630_14_1 >= (-100)) && (pub_r001630_14_1 <= 100));
  __CPROVER_assume((pub_r001630_14_2 >= (-100)) && (pub_r001630_14_2 <= 100));
  __CPROVER_assume((pub_r001630_15_1 >= (-100)) && (pub_r001630_15_1 <= 100));
  __CPROVER_assume((pub_r001630_15_2 >= (-100)) && (pub_r001630_15_2 <= 100));
  __CPROVER_assume((pub_r001630_16_1 >= (-100)) && (pub_r001630_16_1 <= 100));
  __CPROVER_assume((pub_r001630_16_2 >= (-100)) && (pub_r001630_16_2 <= 100));
  __CPROVER_assume((pub_r001630_17_1 >= (-100)) && (pub_r001630_17_1 <= 100));
  __CPROVER_assume((pub_r001630_17_2 >= (-100)) && (pub_r001630_17_2 <= 100));
  __CPROVER_assume((pub_r001630_18_1 >= (-100)) && (pub_r001630_18_1 <= 100));
  __CPROVER_assume((pub_r001630_18_2 >= (-100)) && (pub_r001630_18_2 <= 100));
  __CPROVER_assume((pub_r001630_19_1 >= (-100)) && (pub_r001630_19_1 <= 100));
  __CPROVER_assume((pub_r001630_19_2 >= (-100)) && (pub_r001630_19_2 <= 100));
  __CPROVER_assume((pub_r001630_20_1 >= (-100)) && (pub_r001630_20_1 <= 100));
  __CPROVER_assume((pub_r001630_20_2 >= (-100)) && (pub_r001630_20_2 <= 100));
  __CPROVER_assume((pub_r001630_21_1 >= (-100)) && (pub_r001630_21_1 <= 100));
  __CPROVER_assume((pub_r001630_21_2 >= (-100)) && (pub_r001630_21_2 <= 100));
  __CPROVER_assume((sec_r001630_0_1 >= 0) && (sec_r001630_0_1 <= 255));
  __CPROVER_assume((sec_r001630_0_2 >= 0) && (sec_r001630_0_2 <= 255));
  __CPROVER_assume((sec_r001630_1_1 >= 0) && (sec_r001630_1_1 <= 255));
  __CPROVER_assume((sec_r001630_1_2 >= 0) && (sec_r001630_1_2 <= 255));
  __CPROVER_assume((sec_r001630_2_1 >= 0) && (sec_r001630_2_1 <= 255));
  __CPROVER_assume((sec_r001630_2_2 >= 0) && (sec_r001630_2_2 <= 255));
  __CPROVER_assume((sec_r001630_3_1 >= 0) && (sec_r001630_3_1 <= 255));
  __CPROVER_assume((sec_r001630_3_2 >= 0) && (sec_r001630_3_2 <= 255));
  __CPROVER_assume((sec_r001630_4_1 >= 0) && (sec_r001630_4_1 <= 255));
  __CPROVER_assume((sec_r001630_4_2 >= 0) && (sec_r001630_4_2 <= 255));
  __CPROVER_assume((sec_r001630_5_1 >= 0) && (sec_r001630_5_1 <= 255));
  __CPROVER_assume((sec_r001630_5_2 >= 0) && (sec_r001630_5_2 <= 255));
  __CPROVER_assume((sec_r001630_6_1 >= 0) && (sec_r001630_6_1 <= 255));
  __CPROVER_assume((sec_r001630_6_2 >= 0) && (sec_r001630_6_2 <= 255));
  __CPROVER_assume((sec_r001630_7_1 >= 0) && (sec_r001630_7_1 <= 255));
  __CPROVER_assume((sec_r001630_7_2 >= 0) && (sec_r001630_7_2 <= 255));
  __CPROVER_assume((sec_r001630_8_1 >= 0) && (sec_r001630_8_1 <= 255));
  __CPROVER_assume((sec_r001630_8_2 >= 0) && (sec_r001630_8_2 <= 255));
  __CPROVER_assume((sec_r001630_9_1 >= 0) && (sec_r001630_9_1 <= 255));
  __CPROVER_assume((sec_r001630_9_2 >= 0) && (sec_r001630_9_2 <= 255));
  __CPROVER_assume((sec_r001630_10_1 >= 0) && (sec_r001630_10_1 <= 255));
  __CPROVER_assume((sec_r001630_10_2 >= 0) && (sec_r001630_10_2 <= 255));
  __CPROVER_assume((sec_r001630_11_1 >= 0) && (sec_r001630_11_1 <= 255));
  __CPROVER_assume((sec_r001630_11_2 >= 0) && (sec_r001630_11_2 <= 255));
  __CPROVER_assume((sec_r001630_12_1 >= 0) && (sec_r001630_12_1 <= 255));
  __CPROVER_assume((sec_r001630_12_2 >= 0) && (sec_r001630_12_2 <= 255));
  __CPROVER_assume((sec_r001630_13_1 >= 0) && (sec_r001630_13_1 <= 255));
  __CPROVER_assume((sec_r001630_13_2 >= 0) && (sec_r001630_13_2 <= 255));
  __CPROVER_assume((sec_r001630_14_1 >= 0) && (sec_r001630_14_1 <= 255));
  __CPROVER_assume((sec_r001630_14_2 >= 0) && (sec_r001630_14_2 <= 255));
  __CPROVER_assume((sec_r001630_15_1 >= 0) && (sec_r001630_15_1 <= 255));
  __CPROVER_assume((sec_r001630_15_2 >= 0) && (sec_r001630_15_2 <= 255));
  __CPROVER_assume((sec_r001630_16_1 >= 0) && (sec_r001630_16_1 <= 255));
  __CPROVER_assume((sec_r001630_16_2 >= 0) && (sec_r001630_16_2 <= 255));
  __CPROVER_assume((sec_r001630_17_1 >= 0) && (sec_r001630_17_1 <= 255));
  __CPROVER_assume((sec_r001630_17_2 >= 0) && (sec_r001630_17_2 <= 255));
  __CPROVER_assume((sec_r001630_18_1 >= 0) && (sec_r001630_18_1 <= 255));
  __CPROVER_assume((sec_r001630_18_2 >= 0) && (sec_r001630_18_2 <= 255));
  __CPROVER_assume((sec_r001630_19_1 >= 0) && (sec_r001630_19_1 <= 255));
  __CPROVER_assume((sec_r001630_19_2 >= 0) && (sec_r001630_19_2 <= 255));
  __CPROVER_assume((sec_r001630_20_1 >= 0) && (sec_r001630_20_1 <= 255));
  __CPROVER_assume((sec_r001630_20_2 >= 0) && (sec_r001630_20_2 <= 255));
  __CPROVER_assume((sec_r001630_21_1 >= 0) && (sec_r001630_21_1 <= 255));
  __CPROVER_assume((sec_r001630_21_2 >= 0) && (sec_r001630_21_2 <= 255));
  __CPROVER_assume((sec_r001630_22_1 >= 0) && (sec_r001630_22_1 <= 255));
  __CPROVER_assume((sec_r001630_22_2 >= 0) && (sec_r001630_22_2 <= 255));
  struct Transaction_R001630_3013_0 st_var_0_1 = {0};
  struct Transaction_R001630_3013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001630_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001630_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001630_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001630_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001630_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001630_0_2 + 7) & 15;
  struct FilterState_R001630_3013_1 st_var_1_1 = {0};
  struct FilterState_R001630_3013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001630_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001630_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001630_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001630_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001630_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001630_0_2 + 9) & 15;
  struct StreamBuffer_R001630_3013_2 st_var_2_1 = {0};
  struct StreamBuffer_R001630_3013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001630_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001630_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001630_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001630_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001630_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001630_0_2 + 11) & 15;
  struct DeviceConfig_R001630_3013_3 st_var_3_1 = {0};
  struct DeviceConfig_R001630_3013_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001630_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001630_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001630_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001630_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001630_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001630_0_2 + 13) & 15;
  union ColorPixel_R001630_3013_0 u_var_1;
  union ColorPixel_R001630_3013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001630_3013_0(sec_r001630_0_1, pub_r001630_1_1, pub_r001630_2_1, pub_r001630_3_1, pub_r001630_4_1);
  int helper_flow_0_2 = fn_R001630_3013_0(sec_r001630_0_2, pub_r001630_1_2, pub_r001630_2_2, pub_r001630_3_2, pub_r001630_4_2);
  fn_R001630_3013_0_2(sec_r001630_0_1, pub_r001630_1_1, pub_r001630_2_1, pub_r001630_3_1, pub_r001630_4_1, sec_r001630_0_2, pub_r001630_1_2, pub_r001630_2_2, pub_r001630_3_2, pub_r001630_4_2);
  int helper_flow_1_1 = fn_R001630_3013_1(sec_r001630_1_1, sec_r001630_2_1);
  int helper_flow_1_2 = fn_R001630_3013_1(sec_r001630_1_2, sec_r001630_2_2);
  fn_R001630_3013_1_2(sec_r001630_1_1, sec_r001630_2_1, sec_r001630_1_2, sec_r001630_2_2);
  int helper_flow_2_1 = fn_R001630_3013_2(sec_r001630_2_1, sec_r001630_3_1, pub_r001630_4_1, pub_r001630_5_1, pub_r001630_6_1);
  int helper_flow_2_2 = fn_R001630_3013_2(sec_r001630_2_2, sec_r001630_3_2, pub_r001630_4_2, pub_r001630_5_2, pub_r001630_6_2);
  fn_R001630_3013_2_2(sec_r001630_2_1, sec_r001630_3_1, pub_r001630_4_1, pub_r001630_5_1, pub_r001630_6_1, sec_r001630_2_2, sec_r001630_3_2, pub_r001630_4_2, pub_r001630_5_2, pub_r001630_6_2);
  int helper_flow_3_1 = fn_R001630_3013_3(sec_r001630_3_1, sec_r001630_4_1);
  int helper_flow_3_2 = fn_R001630_3013_3(sec_r001630_3_2, sec_r001630_4_2);
  fn_R001630_3013_3_2(sec_r001630_3_1, sec_r001630_4_1, sec_r001630_3_2, sec_r001630_4_2);
  int helper_flow_4_1 = fn_R001630_3013_4(sec_r001630_4_1, pub_r001630_5_1, pub_r001630_6_1);
  int helper_flow_4_2 = fn_R001630_3013_4(sec_r001630_4_2, pub_r001630_5_2, pub_r001630_6_2);
  fn_R001630_3013_4_2(sec_r001630_4_1, pub_r001630_5_1, pub_r001630_6_1, sec_r001630_4_2, pub_r001630_5_2, pub_r001630_6_2);
  int helper_flow_5_1 = fn_R001630_3013_5(sec_r001630_5_1, sec_r001630_6_1);
  int helper_flow_5_2 = fn_R001630_3013_5(sec_r001630_5_2, sec_r001630_6_2);
  fn_R001630_3013_5_2(sec_r001630_5_1, sec_r001630_6_1, sec_r001630_5_2, sec_r001630_6_2);
  int helper_flow_6_1 = fn_R001630_3013_6(sec_r001630_6_1, sec_r001630_7_1, pub_r001630_8_1);
  int helper_flow_6_2 = fn_R001630_3013_6(sec_r001630_6_2, sec_r001630_7_2, pub_r001630_8_2);
  fn_R001630_3013_6_2(sec_r001630_6_1, sec_r001630_7_1, pub_r001630_8_1, sec_r001630_6_2, sec_r001630_7_2, pub_r001630_8_2);
  int helper_flow_7_1 = fn_R001630_3013_7(sec_r001630_7_1, sec_r001630_8_1, pub_r001630_9_1);
  int helper_flow_7_2 = fn_R001630_3013_7(sec_r001630_7_2, sec_r001630_8_2, pub_r001630_9_2);
  fn_R001630_3013_7_2(sec_r001630_7_1, sec_r001630_8_1, pub_r001630_9_1, sec_r001630_7_2, sec_r001630_8_2, pub_r001630_9_2);
  int helper_flow_8_1 = fn_R001630_3013_8(sec_r001630_8_1, pub_r001630_9_1, pub_r001630_10_1, pub_r001630_11_1);
  int helper_flow_8_2 = fn_R001630_3013_8(sec_r001630_8_2, pub_r001630_9_2, pub_r001630_10_2, pub_r001630_11_2);
  fn_R001630_3013_8_2(sec_r001630_8_1, pub_r001630_9_1, pub_r001630_10_1, pub_r001630_11_1, sec_r001630_8_2, pub_r001630_9_2, pub_r001630_10_2, pub_r001630_11_2);
  int helper_flow_9_1 = fn_R001630_3013_9(sec_r001630_9_1, pub_r001630_10_1, pub_r001630_11_1, pub_r001630_12_1, pub_r001630_13_1);
  int helper_flow_9_2 = fn_R001630_3013_9(sec_r001630_9_2, pub_r001630_10_2, pub_r001630_11_2, pub_r001630_12_2, pub_r001630_13_2);
  fn_R001630_3013_9_2(sec_r001630_9_1, pub_r001630_10_1, pub_r001630_11_1, pub_r001630_12_1, pub_r001630_13_1, sec_r001630_9_2, pub_r001630_10_2, pub_r001630_11_2, pub_r001630_12_2, pub_r001630_13_2);
  int helper_flow_10_1 = fn_R001630_3013_10(sec_r001630_10_1, pub_r001630_11_1);
  int helper_flow_10_2 = fn_R001630_3013_10(sec_r001630_10_2, pub_r001630_11_2);
  fn_R001630_3013_10_2(sec_r001630_10_1, pub_r001630_11_1, sec_r001630_10_2, pub_r001630_11_2);
  int stage_v_0_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001630_8_1) & 127;
  int stage_v_0_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001630_8_2) & 127;
  if (stage_v_0_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((sec_r001630_5_1 ^ 0x2A) * 2) + pub_r001630_19_1) & 127;
  int stage_v_1_2 = (((sec_r001630_5_2 ^ 0x2A) * 2) + pub_r001630_19_2) & 127;
  if (stage_v_1_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001630_10_1) & 127;
  int stage_v_2_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001630_10_2) & 127;
  if (stage_v_2_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((sec_r001630_14_1 ^ 0x2A) * 2) + pub_r001630_8_1) & 127;
  int stage_v_3_2 = (((sec_r001630_14_2 ^ 0x2A) * 2) + pub_r001630_8_2) & 127;
  if (stage_v_3_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001630_21_1) & 127;
  int stage_v_4_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001630_21_2) & 127;
  if (stage_v_4_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001630_5_1) & 127;
  int stage_v_5_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001630_5_2) & 127;
  if (stage_v_5_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = ((pub_r001630_18_1 * 2) + 11) & 63;
  int stage_v_6_2 = ((pub_r001630_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001630_18_1) & 127;
  int stage_v_7_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001630_18_2) & 127;
  if (stage_v_7_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001630_9_1) & 127;
  int stage_v_8_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001630_9_2) & 127;
  if (stage_v_8_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((sec_r001630_3_1 ^ 0x2A) * 2) + pub_r001630_10_1) & 127;
  int stage_v_9_2 = (((sec_r001630_3_2 ^ 0x2A) * 2) + pub_r001630_10_2) & 127;
  if (stage_v_9_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (((sec_r001630_13_1 ^ 0x2A) * 2) + pub_r001630_9_1) & 127;
  int stage_v_10_2 = (((sec_r001630_13_2 ^ 0x2A) * 2) + pub_r001630_9_2) & 127;
  if (stage_v_10_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((sec_r001630_3_1 ^ 0x2A) * 2) + pub_r001630_3_1) & 127;
  int stage_v_11_2 = (((sec_r001630_3_2 ^ 0x2A) * 2) + pub_r001630_3_2) & 127;
  if (stage_v_11_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((sec_r001630_0_1 ^ 0x2A) * 2) + pub_r001630_16_1) & 127;
  int stage_v_12_2 = (((sec_r001630_0_2 ^ 0x2A) * 2) + pub_r001630_16_2) & 127;
  if (stage_v_12_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (((sec_r001630_1_1 ^ 0x2A) * 2) + pub_r001630_9_1) & 127;
  int stage_v_13_2 = (((sec_r001630_1_2 ^ 0x2A) * 2) + pub_r001630_9_2) & 127;
  if (stage_v_13_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001630_13_1) & 127;
  int stage_v_14_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001630_13_2) & 127;
  if (stage_v_14_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (((sec_r001630_3_1 ^ 0x2A) * 2) + pub_r001630_16_1) & 127;
  int stage_v_15_2 = (((sec_r001630_3_2 ^ 0x2A) * 2) + pub_r001630_16_2) & 127;
  if (stage_v_15_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001630_2_1) & 127;
  int stage_v_16_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001630_2_2) & 127;
  if (stage_v_16_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001630_6_1) & 127;
  int stage_v_17_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001630_6_2) & 127;
  if (stage_v_17_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((sec_r001630_22_1 ^ 0x2A) * 2) + pub_r001630_5_1) & 127;
  int stage_v_18_2 = (((sec_r001630_22_2 ^ 0x2A) * 2) + pub_r001630_5_2) & 127;
  if (stage_v_18_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = ((pub_r001630_9_1 * 2) + 33) & 63;
  int stage_v_19_2 = ((pub_r001630_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001630_6_1 * 2) + 45) & 63;
  int stage_v_20_2 = ((pub_r001630_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001630_8_1) & 127;
  int stage_v_21_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001630_8_2) & 127;
  if (stage_v_21_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((pub_r001630_5_1 * 2) + 22) & 63;
  int stage_v_22_2 = ((pub_r001630_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001630_17_1) & 127;
  int stage_v_23_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001630_17_2) & 127;
  if (stage_v_23_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((sec_r001630_12_1 ^ 0x2A) * 2) + pub_r001630_3_1) & 127;
  int stage_v_24_2 = (((sec_r001630_12_2 ^ 0x2A) * 2) + pub_r001630_3_2) & 127;
  if (stage_v_24_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((sec_r001630_3_1 ^ 0x2A) * 2) + pub_r001630_11_1) & 127;
  int stage_v_25_2 = (((sec_r001630_3_2 ^ 0x2A) * 2) + pub_r001630_11_2) & 127;
  if (stage_v_25_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((sec_r001630_7_1 ^ 0x2A) * 2) + pub_r001630_2_1) & 127;
  int stage_v_26_2 = (((sec_r001630_7_2 ^ 0x2A) * 2) + pub_r001630_2_2) & 127;
  if (stage_v_26_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((pub_r001630_14_1 * 2) + 30) & 63;
  int stage_v_27_2 = ((pub_r001630_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((sec_r001630_13_1 ^ 0x2A) * 2) + pub_r001630_2_1) & 127;
  int stage_v_28_2 = (((sec_r001630_13_2 ^ 0x2A) * 2) + pub_r001630_2_2) & 127;
  if (stage_v_28_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((pub_r001630_19_1 * 2) + 6) & 63;
  int stage_v_29_2 = ((pub_r001630_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001630_20_1) & 127;
  int stage_v_30_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001630_20_2) & 127;
  if (stage_v_30_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((sec_r001630_0_1 ^ 0x2A) * 2) + pub_r001630_2_1) & 127;
  int stage_v_31_2 = (((sec_r001630_0_2 ^ 0x2A) * 2) + pub_r001630_2_2) & 127;
  if (stage_v_31_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((sec_r001630_8_1 ^ 0x2A) * 2) + pub_r001630_2_1) & 127;
  int stage_v_32_2 = (((sec_r001630_8_2 ^ 0x2A) * 2) + pub_r001630_2_2) & 127;
  if (stage_v_32_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((sec_r001630_22_1 ^ 0x2A) * 2) + pub_r001630_15_1) & 127;
  int stage_v_33_2 = (((sec_r001630_22_2 ^ 0x2A) * 2) + pub_r001630_15_2) & 127;
  if (stage_v_33_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (((sec_r001630_0_1 ^ 0x2A) * 2) + pub_r001630_18_1) & 127;
  int stage_v_34_2 = (((sec_r001630_0_2 ^ 0x2A) * 2) + pub_r001630_18_2) & 127;
  if (stage_v_34_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((sec_r001630_8_1 ^ 0x2A) * 2) + pub_r001630_15_1) & 127;
  int stage_v_35_2 = (((sec_r001630_8_2 ^ 0x2A) * 2) + pub_r001630_15_2) & 127;
  if (stage_v_35_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001630_14_1) & 127;
  int stage_v_36_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001630_14_2) & 127;
  if (stage_v_36_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((pub_r001630_17_1 * 2) + 40) & 63;
  int stage_v_37_2 = ((pub_r001630_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((sec_r001630_20_1 ^ 0x2A) * 2) + pub_r001630_1_1) & 127;
  int stage_v_38_2 = (((sec_r001630_20_2 ^ 0x2A) * 2) + pub_r001630_1_2) & 127;
  if (stage_v_38_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001630_10_1) & 127;
  int stage_v_39_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001630_10_2) & 127;
  if (stage_v_39_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((pub_r001630_1_1 * 2) + 34) & 63;
  int stage_v_40_2 = ((pub_r001630_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((sec_r001630_16_1 ^ 0x2A) * 2) + pub_r001630_4_1) & 127;
  int stage_v_41_2 = (((sec_r001630_16_2 ^ 0x2A) * 2) + pub_r001630_4_2) & 127;
  if (stage_v_41_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((pub_r001630_11_1 * 2) + 38) & 63;
  int stage_v_42_2 = ((pub_r001630_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001630_8_1 * 2) + 39) & 63;
  int stage_v_43_2 = ((pub_r001630_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001630_4_1) & 127;
  int stage_v_44_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001630_4_2) & 127;
  if (stage_v_44_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001630_13_1) & 127;
  int stage_v_45_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001630_13_2) & 127;
  if (stage_v_45_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (((sec_r001630_22_1 ^ 0x2A) * 2) + pub_r001630_13_1) & 127;
  int stage_v_46_2 = (((sec_r001630_22_2 ^ 0x2A) * 2) + pub_r001630_13_2) & 127;
  if (stage_v_46_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001630_12_1) & 127;
  int stage_v_47_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001630_12_2) & 127;
  if (stage_v_47_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((pub_r001630_20_1 * 2) + 41) & 63;
  int stage_v_48_2 = ((pub_r001630_20_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((sec_r001630_10_1 ^ 0x2A) * 2) + pub_r001630_1_1) & 127;
  int stage_v_49_2 = (((sec_r001630_10_2 ^ 0x2A) * 2) + pub_r001630_1_2) & 127;
  if (stage_v_49_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((pub_r001630_1_1 * 2) + 18) & 63;
  int stage_v_50_2 = ((pub_r001630_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001630_1_1) & 127;
  int stage_v_51_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001630_1_2) & 127;
  if (stage_v_51_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001630_1_1) & 127;
  int stage_v_52_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001630_1_2) & 127;
  if (stage_v_52_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((pub_r001630_20_1 * 2) + 14) & 63;
  int stage_v_53_2 = ((pub_r001630_20_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001630_10_1) & 127;
  int stage_v_54_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001630_10_2) & 127;
  if (stage_v_54_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001630_20_1) & 127;
  int stage_v_55_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001630_20_2) & 127;
  if (stage_v_55_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((sec_r001630_5_1 ^ 0x2A) * 2) + pub_r001630_19_1) & 127;
  int stage_v_56_2 = (((sec_r001630_5_2 ^ 0x2A) * 2) + pub_r001630_19_2) & 127;
  if (stage_v_56_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((sec_r001630_16_1 ^ 0x2A) * 2) + pub_r001630_18_1) & 127;
  int stage_v_57_2 = (((sec_r001630_16_2 ^ 0x2A) * 2) + pub_r001630_18_2) & 127;
  if (stage_v_57_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((pub_r001630_2_1 * 2) + 42) & 63;
  int stage_v_58_2 = ((pub_r001630_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (((sec_r001630_9_1 ^ 0x2A) * 2) + pub_r001630_4_1) & 127;
  int stage_v_59_2 = (((sec_r001630_9_2 ^ 0x2A) * 2) + pub_r001630_4_2) & 127;
  if (stage_v_59_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((pub_r001630_21_1 * 2) + 44) & 63;
  int stage_v_60_2 = ((pub_r001630_21_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001630_6_1) & 127;
  int stage_v_61_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001630_6_2) & 127;
  if (stage_v_61_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((pub_r001630_1_1 * 2) + 29) & 63;
  int stage_v_62_2 = ((pub_r001630_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001630_8_1 * 2) + 15) & 63;
  int stage_v_63_2 = ((pub_r001630_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001630_21_1) & 127;
  int stage_v_64_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001630_21_2) & 127;
  if (stage_v_64_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001630_16_1) & 127;
  int stage_v_65_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001630_16_2) & 127;
  if (stage_v_65_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((pub_r001630_7_1 * 2) + 37) & 63;
  int stage_v_66_2 = ((pub_r001630_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001630_13_1 * 2) + 5) & 63;
  int stage_v_67_2 = ((pub_r001630_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001630_21_1 * 2) + 50) & 63;
  int stage_v_68_2 = ((pub_r001630_21_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001630_5_1 * 2) + 21) & 63;
  int stage_v_69_2 = ((pub_r001630_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001630_18_1) & 127;
  int stage_v_70_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001630_18_2) & 127;
  if (stage_v_70_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001630_13_1) & 127;
  int stage_v_71_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001630_13_2) & 127;
  if (stage_v_71_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001630_9_1) & 127;
  int stage_v_72_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001630_9_2) & 127;
  if (stage_v_72_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((sec_r001630_6_1 ^ 0x2A) * 2) + pub_r001630_17_1) & 127;
  int stage_v_73_2 = (((sec_r001630_6_2 ^ 0x2A) * 2) + pub_r001630_17_2) & 127;
  if (stage_v_73_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((sec_r001630_22_1 ^ 0x2A) * 2) + pub_r001630_15_1) & 127;
  int stage_v_74_2 = (((sec_r001630_22_2 ^ 0x2A) * 2) + pub_r001630_15_2) & 127;
  if (stage_v_74_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((sec_r001630_18_1 ^ 0x2A) * 2) + pub_r001630_7_1) & 127;
  int stage_v_75_2 = (((sec_r001630_18_2 ^ 0x2A) * 2) + pub_r001630_7_2) & 127;
  if (stage_v_75_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((pub_r001630_3_1 * 2) + 50) & 63;
  int stage_v_76_2 = ((pub_r001630_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001630_19_1 * 2) + 5) & 63;
  int stage_v_77_2 = ((pub_r001630_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001630_8_1) & 127;
  int stage_v_78_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001630_8_2) & 127;
  if (stage_v_78_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001630_5_1) & 127;
  int stage_v_79_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001630_5_2) & 127;
  if (stage_v_79_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((sec_r001630_20_1 ^ 0x2A) * 2) + pub_r001630_19_1) & 127;
  int stage_v_80_2 = (((sec_r001630_20_2 ^ 0x2A) * 2) + pub_r001630_19_2) & 127;
  if (stage_v_80_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001630_21_1) & 127;
  int stage_v_81_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001630_21_2) & 127;
  if (stage_v_81_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001630_5_1) & 127;
  int stage_v_82_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001630_5_2) & 127;
  if (stage_v_82_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((pub_r001630_19_1 * 2) + 33) & 63;
  int stage_v_83_2 = ((pub_r001630_19_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001630_19_1) & 127;
  int stage_v_84_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001630_19_2) & 127;
  if (stage_v_84_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (((sec_r001630_4_1 ^ 0x2A) * 2) + pub_r001630_8_1) & 127;
  int stage_v_85_2 = (((sec_r001630_4_2 ^ 0x2A) * 2) + pub_r001630_8_2) & 127;
  if (stage_v_85_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((pub_r001630_11_1 * 2) + 30) & 63;
  int stage_v_86_2 = ((pub_r001630_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((sec_r001630_10_1 ^ 0x2A) * 2) + pub_r001630_17_1) & 127;
  int stage_v_87_2 = (((sec_r001630_10_2 ^ 0x2A) * 2) + pub_r001630_17_2) & 127;
  if (stage_v_87_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001630_2_1) & 127;
  int stage_v_88_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001630_2_2) & 127;
  if (stage_v_88_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001630_6_1) & 127;
  int stage_v_89_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001630_6_2) & 127;
  if (stage_v_89_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001630_16_1) & 127;
  int stage_v_90_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001630_16_2) & 127;
  if (stage_v_90_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((sec_r001630_11_1 ^ 0x2A) * 2) + pub_r001630_10_1) & 127;
  int stage_v_91_2 = (((sec_r001630_11_2 ^ 0x2A) * 2) + pub_r001630_10_2) & 127;
  if (stage_v_91_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001630_20_1) & 127;
  int stage_v_92_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001630_20_2) & 127;
  if (stage_v_92_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001630_13_1) & 127;
  int stage_v_93_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001630_13_2) & 127;
  if (stage_v_93_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001630_14_1) & 127;
  int stage_v_94_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001630_14_2) & 127;
  if (stage_v_94_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((pub_r001630_19_1 * 2) + 31) & 63;
  int stage_v_95_2 = ((pub_r001630_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001630_18_1 * 2) + 40) & 63;
  int stage_v_96_2 = ((pub_r001630_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001630_1_1) & 127;
  int stage_v_97_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001630_1_2) & 127;
  if (stage_v_97_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((pub_r001630_8_1 * 2) + 31) & 63;
  int stage_v_98_2 = ((pub_r001630_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (((sec_r001630_4_1 ^ 0x2A) * 2) + pub_r001630_11_1) & 127;
  int stage_v_99_2 = (((sec_r001630_4_2 ^ 0x2A) * 2) + pub_r001630_11_2) & 127;
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
  int stage_v_100_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001630_12_1) & 127;
  int stage_v_100_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001630_12_2) & 127;
  if (stage_v_100_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001630_9_1) & 127;
  int stage_v_101_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001630_9_2) & 127;
  if (stage_v_101_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001630_9_1) & 127;
  int stage_v_102_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001630_9_2) & 127;
  if (stage_v_102_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001630_2_1) & 127;
  int stage_v_103_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001630_2_2) & 127;
  if (stage_v_103_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((pub_r001630_6_1 * 2) + 6) & 63;
  int stage_v_104_2 = ((pub_r001630_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001630_18_1 * 2) + 26) & 63;
  int stage_v_105_2 = ((pub_r001630_18_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001630_9_1 * 2) + 5) & 63;
  int stage_v_106_2 = ((pub_r001630_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001630_18_1) & 127;
  int stage_v_107_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001630_18_2) & 127;
  if (stage_v_107_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001630_19_1) & 127;
  int stage_v_108_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001630_19_2) & 127;
  if (stage_v_108_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((pub_r001630_5_1 * 2) + 5) & 63;
  int stage_v_109_2 = ((pub_r001630_5_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001630_14_1 * 2) + 15) & 63;
  int stage_v_110_2 = ((pub_r001630_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001630_20_1) & 127;
  int stage_v_111_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001630_20_2) & 127;
  if (stage_v_111_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((pub_r001630_21_1 * 2) + 34) & 63;
  int stage_v_112_2 = ((pub_r001630_21_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001630_3_1) & 127;
  int stage_v_113_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001630_3_2) & 127;
  if (stage_v_113_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((pub_r001630_12_1 * 2) + 35) & 63;
  int stage_v_114_2 = ((pub_r001630_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001630_11_1) & 127;
  int stage_v_115_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001630_11_2) & 127;
  if (stage_v_115_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001630_14_1) & 127;
  int stage_v_116_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001630_14_2) & 127;
  if (stage_v_116_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001630_13_1) & 127;
  int stage_v_117_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001630_13_2) & 127;
  if (stage_v_117_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001630_13_1) & 127;
  int stage_v_118_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001630_13_2) & 127;
  if (stage_v_118_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001630_6_1) & 127;
  int stage_v_119_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001630_6_2) & 127;
  if (stage_v_119_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001630_21_1) & 127;
  int stage_v_120_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001630_21_2) & 127;
  if (stage_v_120_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001630_15_1) & 127;
  int stage_v_121_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001630_15_2) & 127;
  if (stage_v_121_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001630_5_1) & 127;
  int stage_v_122_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001630_5_2) & 127;
  if (stage_v_122_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((stage_v_119_1 ^ 0x2A) * 2) + pub_r001630_10_1) & 127;
  int stage_v_123_2 = (((stage_v_119_2 ^ 0x2A) * 2) + pub_r001630_10_2) & 127;
  if (stage_v_123_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001630_6_1) & 127;
  int stage_v_124_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001630_6_2) & 127;
  if (stage_v_124_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001630_13_1) & 127;
  int stage_v_125_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001630_13_2) & 127;
  if (stage_v_125_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((pub_r001630_14_1 * 2) + 31) & 63;
  int stage_v_126_2 = ((pub_r001630_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001630_1_1 * 2) + 45) & 63;
  int stage_v_127_2 = ((pub_r001630_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001630_3_1 * 2) + 47) & 63;
  int stage_v_128_2 = ((pub_r001630_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001630_12_1) & 127;
  int stage_v_129_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001630_12_2) & 127;
  if (stage_v_129_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001630_21_1) & 127;
  int stage_v_130_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001630_21_2) & 127;
  if (stage_v_130_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001630_20_1) & 127;
  int stage_v_131_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001630_20_2) & 127;
  if (stage_v_131_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001630_17_1) & 127;
  int stage_v_132_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001630_17_2) & 127;
  if (stage_v_132_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((pub_r001630_14_1 * 2) + 31) & 63;
  int stage_v_133_2 = ((pub_r001630_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001630_6_1 * 2) + 10) & 63;
  int stage_v_134_2 = ((pub_r001630_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001630_7_1) & 127;
  int stage_v_135_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001630_7_2) & 127;
  if (stage_v_135_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001630_6_1) & 127;
  int stage_v_136_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001630_6_2) & 127;
  if (stage_v_136_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001630_4_1) & 127;
  int stage_v_137_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001630_4_2) & 127;
  if (stage_v_137_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001630_8_1) & 127;
  int stage_v_138_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001630_8_2) & 127;
  if (stage_v_138_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001630_10_1) & 127;
  int stage_v_139_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001630_10_2) & 127;
  if (stage_v_139_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((sec_r001630_4_1 ^ 0x2A) * 2) + pub_r001630_18_1) & 127;
  int stage_v_140_2 = (((sec_r001630_4_2 ^ 0x2A) * 2) + pub_r001630_18_2) & 127;
  if (stage_v_140_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((sec_r001630_21_1 ^ 0x2A) * 2) + pub_r001630_21_1) & 127;
  int stage_v_141_2 = (((sec_r001630_21_2 ^ 0x2A) * 2) + pub_r001630_21_2) & 127;
  if (stage_v_141_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001630_7_1) & 127;
  int stage_v_142_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001630_7_2) & 127;
  if (stage_v_142_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001630_4_1) & 127;
  int stage_v_143_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001630_4_2) & 127;
  if (stage_v_143_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((pub_r001630_6_1 * 2) + 48) & 63;
  int stage_v_144_2 = ((pub_r001630_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001630_4_1) & 127;
  int stage_v_145_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001630_4_2) & 127;
  if (stage_v_145_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((pub_r001630_7_1 * 2) + 29) & 63;
  int stage_v_146_2 = ((pub_r001630_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001630_17_1) & 127;
  int stage_v_147_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001630_17_2) & 127;
  if (stage_v_147_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = (((stage_v_137_1 ^ 0x2A) * 2) + pub_r001630_15_1) & 127;
  int stage_v_148_2 = (((stage_v_137_2 ^ 0x2A) * 2) + pub_r001630_15_2) & 127;
  if (stage_v_148_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001630_10_1) & 127;
  int stage_v_149_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001630_10_2) & 127;
  if (stage_v_149_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001630_12_1) & 127;
  int stage_v_150_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001630_12_2) & 127;
  if (stage_v_150_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001630_21_1) & 127;
  int stage_v_151_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001630_21_2) & 127;
  if (stage_v_151_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((pub_r001630_6_1 * 2) + 37) & 63;
  int stage_v_152_2 = ((pub_r001630_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001630_15_1 * 2) + 41) & 63;
  int stage_v_153_2 = ((pub_r001630_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001630_10_1) & 127;
  int stage_v_154_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001630_10_2) & 127;
  if (stage_v_154_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((sec_r001630_6_1 ^ 0x2A) * 2) + pub_r001630_16_1) & 127;
  int stage_v_155_2 = (((sec_r001630_6_2 ^ 0x2A) * 2) + pub_r001630_16_2) & 127;
  if (stage_v_155_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001630_14_1) & 127;
  int stage_v_156_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001630_14_2) & 127;
  if (stage_v_156_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((pub_r001630_7_1 * 2) + 44) & 63;
  int stage_v_157_2 = ((pub_r001630_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (((sec_r001630_9_1 ^ 0x2A) * 2) + pub_r001630_12_1) & 127;
  int stage_v_158_2 = (((sec_r001630_9_2 ^ 0x2A) * 2) + pub_r001630_12_2) & 127;
  if (stage_v_158_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((stage_v_151_1 ^ 0x2A) * 2) + pub_r001630_18_1) & 127;
  int stage_v_159_2 = (((stage_v_151_2 ^ 0x2A) * 2) + pub_r001630_18_2) & 127;
  if (stage_v_159_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((pub_r001630_0_1 * 2) + 14) & 63;
  int stage_v_160_2 = ((pub_r001630_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((sec_r001630_11_1 ^ 0x2A) * 2) + pub_r001630_16_1) & 127;
  int stage_v_161_2 = (((sec_r001630_11_2 ^ 0x2A) * 2) + pub_r001630_16_2) & 127;
  if (stage_v_161_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001630_11_1) & 127;
  int stage_v_162_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001630_11_2) & 127;
  if (stage_v_162_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001630_13_1) & 127;
  int stage_v_163_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001630_13_2) & 127;
  if (stage_v_163_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((pub_r001630_1_1 * 2) + 27) & 63;
  int stage_v_164_2 = ((pub_r001630_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_138_1 ^ 0x2A) * 2) + pub_r001630_1_1) & 127;
  int stage_v_165_2 = (((stage_v_138_2 ^ 0x2A) * 2) + pub_r001630_1_2) & 127;
  if (stage_v_165_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001630_10_1) & 127;
  int stage_v_166_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001630_10_2) & 127;
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
  int stage_v_167_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001630_5_1) & 127;
  int stage_v_167_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001630_5_2) & 127;
  if (stage_v_167_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001630_3_1) & 127;
  int stage_v_168_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001630_3_2) & 127;
  if (stage_v_168_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001630_4_1) & 127;
  int stage_v_169_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001630_4_2) & 127;
  if (stage_v_169_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_148_1 ^ 0x2A) * 2) + pub_r001630_18_1) & 127;
  int stage_v_170_2 = (((stage_v_148_2 ^ 0x2A) * 2) + pub_r001630_18_2) & 127;
  if (stage_v_170_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((stage_v_162_1 ^ 0x2A) * 2) + pub_r001630_20_1) & 127;
  int stage_v_171_2 = (((stage_v_162_2 ^ 0x2A) * 2) + pub_r001630_20_2) & 127;
  if (stage_v_171_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001630_17_1) & 127;
  int stage_v_172_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001630_17_2) & 127;
  if (stage_v_172_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((pub_r001630_9_1 * 2) + 20) & 63;
  int stage_v_173_2 = ((pub_r001630_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001630_11_1 * 2) + 44) & 63;
  int stage_v_174_2 = ((pub_r001630_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_137_1 ^ 0x2A) * 2) + pub_r001630_18_1) & 127;
  int stage_v_175_2 = (((stage_v_137_2 ^ 0x2A) * 2) + pub_r001630_18_2) & 127;
  if (stage_v_175_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = (((sec_r001630_4_1 ^ 0x2A) * 2) + pub_r001630_3_1) & 127;
  int stage_v_176_2 = (((sec_r001630_4_2 ^ 0x2A) * 2) + pub_r001630_3_2) & 127;
  if (stage_v_176_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001630_10_1) & 127;
  int stage_v_177_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001630_10_2) & 127;
  if (stage_v_177_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((pub_r001630_12_1 * 2) + 16) & 63;
  int stage_v_178_2 = ((pub_r001630_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (((stage_v_132_1 ^ 0x2A) * 2) + pub_r001630_18_1) & 127;
  int stage_v_179_2 = (((stage_v_132_2 ^ 0x2A) * 2) + pub_r001630_18_2) & 127;
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
  int stage_v_180_1 = (((stage_v_81_1 ^ 0x2A) * 2) + pub_r001630_8_1) & 127;
  int stage_v_180_2 = (((stage_v_81_2 ^ 0x2A) * 2) + pub_r001630_8_2) & 127;
  if (stage_v_180_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001630_12_1) & 127;
  int stage_v_181_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001630_12_2) & 127;
  if (stage_v_181_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001630_21_1) & 127;
  int stage_v_182_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001630_21_2) & 127;
  if (stage_v_182_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((pub_r001630_18_1 * 2) + 34) & 63;
  int stage_v_183_2 = ((pub_r001630_18_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001630_17_1 * 2) + 32) & 63;
  int stage_v_184_2 = ((pub_r001630_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001630_15_1) & 127;
  int stage_v_185_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001630_15_2) & 127;
  if (stage_v_185_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((pub_r001630_20_1 * 2) + 9) & 63;
  int stage_v_186_2 = ((pub_r001630_20_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((stage_v_131_1 ^ 0x2A) * 2) + pub_r001630_9_1) & 127;
  int stage_v_187_2 = (((stage_v_131_2 ^ 0x2A) * 2) + pub_r001630_9_2) & 127;
  if (stage_v_187_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((pub_r001630_16_1 * 2) + 14) & 63;
  int stage_v_188_2 = ((pub_r001630_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001630_9_1 * 2) + 5) & 63;
  int stage_v_189_2 = ((pub_r001630_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((sec_r001630_6_1 ^ 0x2A) * 2) + pub_r001630_9_1) & 127;
  int stage_v_190_2 = (((sec_r001630_6_2 ^ 0x2A) * 2) + pub_r001630_9_2) & 127;
  if (stage_v_190_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((pub_r001630_11_1 * 2) + 43) & 63;
  int stage_v_191_2 = ((pub_r001630_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = (((stage_v_154_1 ^ 0x2A) * 2) + pub_r001630_16_1) & 127;
  int stage_v_192_2 = (((stage_v_154_2 ^ 0x2A) * 2) + pub_r001630_16_2) & 127;
  if (stage_v_192_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((sec_r001630_6_1 ^ 0x2A) * 2) + pub_r001630_2_1) & 127;
  int stage_v_193_2 = (((sec_r001630_6_2 ^ 0x2A) * 2) + pub_r001630_2_2) & 127;
  if (stage_v_193_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_180_1 ^ 0x2A) * 2) + pub_r001630_0_1) & 127;
  int stage_v_194_2 = (((stage_v_180_2 ^ 0x2A) * 2) + pub_r001630_0_2) & 127;
  if (stage_v_194_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((pub_r001630_20_1 * 2) + 23) & 63;
  int stage_v_195_2 = ((pub_r001630_20_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((stage_v_151_1 ^ 0x2A) * 2) + pub_r001630_1_1) & 127;
  int stage_v_196_2 = (((stage_v_151_2 ^ 0x2A) * 2) + pub_r001630_1_2) & 127;
  if (stage_v_196_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001630_18_1) & 127;
  int stage_v_197_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001630_18_2) & 127;
  if (stage_v_197_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = (((stage_v_137_1 ^ 0x2A) * 2) + pub_r001630_17_1) & 127;
  int stage_v_198_2 = (((stage_v_137_2 ^ 0x2A) * 2) + pub_r001630_17_2) & 127;
  if (stage_v_198_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = (((stage_v_158_1 ^ 0x2A) * 2) + pub_r001630_7_1) & 127;
  int stage_v_199_2 = (((stage_v_158_2 ^ 0x2A) * 2) + pub_r001630_7_2) & 127;
  if (stage_v_199_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = (((sec_r001630_22_1 ^ 0x2A) * 2) + pub_r001630_21_1) & 127;
  int stage_v_200_2 = (((sec_r001630_22_2 ^ 0x2A) * 2) + pub_r001630_21_2) & 127;
  if (stage_v_200_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = (((stage_v_142_1 ^ 0x2A) * 2) + pub_r001630_12_1) & 127;
  int stage_v_201_2 = (((stage_v_142_2 ^ 0x2A) * 2) + pub_r001630_12_2) & 127;
  if (stage_v_201_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((pub_r001630_6_1 * 2) + 21) & 63;
  int stage_v_202_2 = ((pub_r001630_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001630_18_1) & 127;
  int stage_v_203_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001630_18_2) & 127;
  if (stage_v_203_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001630_11_1) & 127;
  int stage_v_204_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001630_11_2) & 127;
  if (stage_v_204_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = (((stage_v_124_1 ^ 0x2A) * 2) + pub_r001630_2_1) & 127;
  int stage_v_205_2 = (((stage_v_124_2 ^ 0x2A) * 2) + pub_r001630_2_2) & 127;
  if (stage_v_205_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001630_14_1) & 127;
  int stage_v_206_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001630_14_2) & 127;
  if (stage_v_206_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((stage_v_116_1 ^ 0x2A) * 2) + pub_r001630_6_1) & 127;
  int stage_v_207_2 = (((stage_v_116_2 ^ 0x2A) * 2) + pub_r001630_6_2) & 127;
  if (stage_v_207_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((pub_r001630_7_1 * 2) + 47) & 63;
  int stage_v_208_2 = ((pub_r001630_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((stage_v_201_1 ^ 0x2A) * 2) + pub_r001630_19_1) & 127;
  int stage_v_209_2 = (((stage_v_201_2 ^ 0x2A) * 2) + pub_r001630_19_2) & 127;
  if (stage_v_209_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((pub_r001630_4_1 * 2) + 32) & 63;
  int stage_v_210_2 = ((pub_r001630_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_171_1 ^ 0x2A) * 2) + pub_r001630_3_1) & 127;
  int stage_v_211_2 = (((stage_v_171_2 ^ 0x2A) * 2) + pub_r001630_3_2) & 127;
  if (stage_v_211_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((pub_r001630_5_1 * 2) + 41) & 63;
  int stage_v_212_2 = ((pub_r001630_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001630_18_1 * 2) + 8) & 63;
  int stage_v_213_2 = ((pub_r001630_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001630_16_1) & 127;
  int stage_v_214_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001630_16_2) & 127;
  if (stage_v_214_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((pub_r001630_19_1 * 2) + 24) & 63;
  int stage_v_215_2 = ((pub_r001630_19_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = (((sec_r001630_19_1 ^ 0x2A) * 2) + pub_r001630_5_1) & 127;
  int stage_v_216_2 = (((sec_r001630_19_2 ^ 0x2A) * 2) + pub_r001630_5_2) & 127;
  if (stage_v_216_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = (((stage_v_199_1 ^ 0x2A) * 2) + pub_r001630_8_1) & 127;
  int stage_v_217_2 = (((stage_v_199_2 ^ 0x2A) * 2) + pub_r001630_8_2) & 127;
  if (stage_v_217_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((stage_v_118_1 ^ 0x2A) * 2) + pub_r001630_16_1) & 127;
  int stage_v_218_2 = (((stage_v_118_2 ^ 0x2A) * 2) + pub_r001630_16_2) & 127;
  if (stage_v_218_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001630_15_1) & 127;
  int stage_v_219_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001630_15_2) & 127;
  if (stage_v_219_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001630_2_1) & 127;
  int stage_v_220_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001630_2_2) & 127;
  if (stage_v_220_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
  }
  if (stage_v_220_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = (((sec_r001630_1_1 ^ 0x2A) * 2) + pub_r001630_19_1) & 127;
  int stage_v_221_2 = (((sec_r001630_1_2 ^ 0x2A) * 2) + pub_r001630_19_2) & 127;
  if (stage_v_221_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001630_0_1 == pub_r001630_0_2);
  __CPROVER_assume(pub_r001630_1_1 == pub_r001630_1_2);
  __CPROVER_assume(sec_r001630_5_1 != sec_r001630_5_2);
  __CPROVER_assume(sec_r001630_13_1 != sec_r001630_13_2);
  __CPROVER_assume(pub_r001630_21_1 == pub_r001630_21_2);
  __CPROVER_assume(sec_r001630_19_1 != sec_r001630_19_2);
  __CPROVER_assume(pub_r001630_12_1 == pub_r001630_12_2);
  __CPROVER_assume(sec_r001630_18_1 != sec_r001630_18_2);
  __CPROVER_assume(pub_r001630_18_1 == pub_r001630_18_2);
  __CPROVER_assume(sec_r001630_9_1 != sec_r001630_9_2);
  __CPROVER_assume(pub_r001630_9_1 == pub_r001630_9_2);
  __CPROVER_assume(sec_r001630_7_1 != sec_r001630_7_2);
  __CPROVER_assume(pub_r001630_16_1 == pub_r001630_16_2);
  __CPROVER_assume(sec_r001630_17_1 != sec_r001630_17_2);
  __CPROVER_assume(pub_r001630_7_1 == pub_r001630_7_2);
  __CPROVER_assume(pub_r001630_20_1 == pub_r001630_20_2);
  __CPROVER_assume(sec_r001630_15_1 != sec_r001630_15_2);
  __CPROVER_assume(pub_r001630_14_1 == pub_r001630_14_2);
  __CPROVER_assume(pub_r001630_11_1 == pub_r001630_11_2);
  __CPROVER_assume(pub_r001630_17_1 == pub_r001630_17_2);
  __CPROVER_assume(sec_r001630_14_1 != sec_r001630_14_2);
  __CPROVER_assume(pub_r001630_8_1 == pub_r001630_8_2);
  __CPROVER_assume(pub_r001630_19_1 == pub_r001630_19_2);
  __CPROVER_assume(sec_r001630_0_1 != sec_r001630_0_2);
  __CPROVER_assume(pub_r001630_6_1 == pub_r001630_6_2);
  __CPROVER_assume(pub_r001630_13_1 == pub_r001630_13_2);
  __CPROVER_assume(sec_r001630_1_1 != sec_r001630_1_2);
  __CPROVER_assume(sec_r001630_6_1 != sec_r001630_6_2);
  __CPROVER_assume(sec_r001630_10_1 != sec_r001630_10_2);
  __CPROVER_assume(sec_r001630_20_1 != sec_r001630_20_2);
  __CPROVER_assume(pub_r001630_10_1 == pub_r001630_10_2);
  __CPROVER_assume(pub_r001630_15_1 == pub_r001630_15_2);
  __CPROVER_assume(sec_r001630_4_1 != sec_r001630_4_2);
  __CPROVER_assume(sec_r001630_2_1 != sec_r001630_2_2);
  __CPROVER_assume(sec_r001630_3_1 != sec_r001630_3_2);
  __CPROVER_assume(sec_r001630_11_1 != sec_r001630_11_2);
  __CPROVER_assume(sec_r001630_21_1 != sec_r001630_21_2);
  __CPROVER_assume(sec_r001630_8_1 != sec_r001630_8_2);
  __CPROVER_assume(pub_r001630_2_1 == pub_r001630_2_2);
  __CPROVER_assume(pub_r001630_3_1 == pub_r001630_3_2);
  __CPROVER_assume(pub_r001630_5_1 == pub_r001630_5_2);
  __CPROVER_assume(sec_r001630_12_1 != sec_r001630_12_2);
  __CPROVER_assume(sec_r001630_16_1 != sec_r001630_16_2);
  __CPROVER_assume(sec_r001630_22_1 != sec_r001630_22_2);
  __CPROVER_assume(pub_r001630_4_1 == pub_r001630_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  assert(st_var_2_1.capacity == st_var_2_2.capacity);
  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.watermark == st_var_2_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.stop_bits == st_var_3_2.stop_bits);
  assert(st_var_3_1.port == st_var_3_2.port);
  assert(st_var_3_1.baud_rate == st_var_3_2.baud_rate);
  assert(st_var_3_1.parity == st_var_3_2.parity);
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

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
  assert(helper_flow_3_1 == helper_flow_3_2);
  assert(helper_flow_4_1 == helper_flow_4_2);
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
  assert(helper_flow_8_1 == helper_flow_8_2);
  assert(helper_flow_9_1 == helper_flow_9_2);
  assert(helper_flow_10_1 == helper_flow_10_2);
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
}


