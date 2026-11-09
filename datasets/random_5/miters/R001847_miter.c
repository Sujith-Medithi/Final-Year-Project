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
struct FilterState_R001847_4713_0
{
  short damping;
  short cutoff;
  int prev_out;
  int mode;
  unsigned char prev_in;
  unsigned char gain_db;
  int buffer[3];
};
struct Transaction_R001847_4713_1
{
  int balance;
  int account_id;
  int rate;
  int buffer[3];
};
struct StreamBuffer_R001847_4713_2
{
  int watermark;
  short head;
  unsigned char state;
  int buffer[3];
};
struct EventLog_R001847_4713_3
{
  int timestamp;
  int signature;
  short severity;
  unsigned char code;
  int facility;
  int buffer[3];
};
union TelemetryField_R001847_4713_0
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
void fn_R001847_4713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001847_4713_1 st_1 = {0};
  struct Transaction_R001847_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_46_1) & 63;
  aux_2 = (aux_2 + checksum_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_88_1 = local_arr_1[aux_1 % 3];
  int stride_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_88_2 * 2)) & 127;
  int mask_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_16_1 > 47)
  {
    acc_1 = ((acc_1 + (mask_16_1 * 2)) + 5) & 127;
    aux_1 ^= mask_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_16_2 > 47)
  {
    acc_2 = ((acc_2 + (mask_16_2 * 2)) + 5) & 127;
    aux_2 ^= mask_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_16_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_46_1 == checksum_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_88_1 == stride_88_2);
  assert(mask_16_1 == mask_16_2);
}

int fn_R001847_4713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001847_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_46) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_88 = local_arr[aux % 3];
  acc = (acc + (stride_88 * 2)) & 127;
  int mask_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_16 > 47)
  {
    acc = ((acc + (mask_16 * 2)) + 5) & 127;
    aux ^= mask_16 & 15;
  }
  else
  {
    acc = ((acc - mask_16) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001847_4713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001847_4713_0 st_1 = {0};
  struct FilterState_R001847_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_56_1 = local_arr_1[aux_1 % 3];
  int margin_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_56_2 * 2)) & 127;
  int delta_75_1 = 0;
  int delta_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_75_1 = ((delta_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_75_2 = ((delta_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_75_1) & 127;
    acc_2 = (acc_2 + delta_75_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_56_1 == margin_56_2);
  assert(delta_75_1 == delta_75_2);
}

int fn_R001847_4713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001847_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int margin_56 = local_arr[aux % 3];
  acc = (acc + (margin_56 * 2)) & 127;
  int delta_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_75 = ((delta_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_75) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001847_4713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001847_4713_2 st_1 = {0};
  struct StreamBuffer_R001847_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int quantum_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_22_1 > 49)
  {
    acc_1 = ((acc_1 + (quantum_22_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_22_2 > 49)
  {
    acc_2 = ((acc_2 + (quantum_22_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_36_1 = 0;
  int metric_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_36_1 = ((metric_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_36_2 = ((metric_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_36_1) & 127;
    acc_2 = (acc_2 + metric_36_2) & 127;
  }

  int mask_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_22_1)
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

  switch (mask_22_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_22_1 == quantum_22_2);
  assert(metric_36_1 == metric_36_2);
  assert(mask_22_1 == mask_22_2);
}

int fn_R001847_4713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001847_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int quantum_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_22 > 49)
  {
    acc = ((acc + (quantum_22 * 2)) + 5) & 127;
    aux ^= quantum_22 & 15;
  }
  else
  {
    acc = ((acc - quantum_22) + 11) & 127;
    aux += 3;
  }
  int metric_36 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_36 = ((metric_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_36) & 127;
  }

  int mask_22 = (aux + st.buffer[1]) & 3;
  switch (mask_22)
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

void fn_R001847_4713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001847_4713_2 st_1 = {0};
  struct StreamBuffer_R001847_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_89_1 = local_arr_1[aux_1 % 3];
  int quantum_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_89_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_11_1 > 15)
  {
    acc_1 = ((acc_1 + (tracker_11_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_11_2 > 15)
  {
    acc_2 = ((acc_2 + (tracker_11_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_11_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_89_1 == quantum_89_2);
  assert(tracker_11_1 == tracker_11_2);
}

int fn_R001847_4713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001847_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int quantum_89 = local_arr[aux % 3];
  acc = (acc + (quantum_89 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_11 > 15)
  {
    acc = ((acc + (tracker_11 * 2)) + 5) & 127;
    aux ^= tracker_11 & 15;
  }
  else
  {
    acc = ((acc - tracker_11) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001847_4713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001847_4713_1 st_1 = {0};
  struct Transaction_R001847_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int quantum_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_78_1 > 50)
  {
    acc_1 = ((acc_1 + (quantum_78_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_78_2 > 50)
  {
    acc_2 = ((acc_2 + (quantum_78_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_99_1 = local_arr_1[aux_1 % 3];
  int quotient_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_99_2 * 2)) & 127;
  int offset_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_33_1) & 63;
  aux_2 = (aux_2 + offset_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_78_1 == quantum_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_99_1 == quotient_99_2);
  assert(offset_33_1 == offset_33_2);
}

int fn_R001847_4713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001847_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int quantum_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_78 > 50)
  {
    acc = ((acc + (quantum_78 * 2)) + 5) & 127;
    aux ^= quantum_78 & 15;
  }
  else
  {
    acc = ((acc - quantum_78) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_99 = local_arr[aux % 3];
  acc = (acc + (quotient_99 * 2)) & 127;
  int offset_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_33) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001847_4713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001847_4713_3 st_1 = {0};
  struct EventLog_R001847_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int mask_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_87_1)
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

  switch (mask_87_2)
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
  int scale_53_1 = local_arr_1[aux_1 % 3];
  int scale_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_53_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_87_1 == mask_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_53_1 == scale_53_2);
}

int fn_R001847_4713_5(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001847_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int mask_87 = (aux + st.buffer[1]) & 3;
  switch (mask_87)
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
  int scale_53 = local_arr[aux % 3];
  acc = (acc + (scale_53 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001847_4713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001847_4713_2 st_1 = {0};
  struct StreamBuffer_R001847_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_43_1 = local_arr_1[aux_1 % 3];
  int scale_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_43_2 * 2)) & 127;
  int factor_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_45_1 > 31)
  {
    acc_1 = ((acc_1 + (factor_45_1 * 2)) + 5) & 127;
    aux_1 ^= factor_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_45_2 > 31)
  {
    acc_2 = ((acc_2 + (factor_45_2 * 2)) + 5) & 127;
    aux_2 ^= factor_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_64_1 = 0;
  int delta_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_64_1 = ((delta_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_64_2 = ((delta_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_64_1) & 127;
    acc_2 = (acc_2 + delta_64_2) & 127;
  }

  int weight_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_92_1) & 63;
  aux_2 = (aux_2 + weight_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_43_1 == scale_43_2);
  assert(factor_45_1 == factor_45_2);
  assert(delta_64_1 == delta_64_2);
  assert(weight_92_1 == weight_92_2);
}

int fn_R001847_4713_6(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001847_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int scale_43 = local_arr[aux % 3];
  acc = (acc + (scale_43 * 2)) & 127;
  int factor_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_45 > 31)
  {
    acc = ((acc + (factor_45 * 2)) + 5) & 127;
    aux ^= factor_45 & 15;
  }
  else
  {
    acc = ((acc - factor_45) + 11) & 127;
    aux += 3;
  }
  int delta_64 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_64 = ((delta_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_64) & 127;
  }

  int weight_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001847_4713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001847_4713_0 st_1 = {0};
  struct FilterState_R001847_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int residue_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_77_1)
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

  switch (residue_77_2)
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

  int index_reg_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_77_1) & 63;
  aux_2 = (aux_2 + index_reg_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_40_1 = 0;
  int window_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_40_1 = ((window_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_40_2 = ((window_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_40_1) & 127;
    acc_2 = (acc_2 + window_40_2) & 127;
  }

  int tracker_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_28_1 > 41)
  {
    acc_1 = ((acc_1 + (tracker_28_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_28_2 > 41)
  {
    acc_2 = ((acc_2 + (tracker_28_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_28_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_77_1 == residue_77_2);
  assert(index_reg_77_1 == index_reg_77_2);
  assert(window_40_1 == window_40_2);
  assert(tracker_28_1 == tracker_28_2);
}

int fn_R001847_4713_7(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001847_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int residue_77 = (aux + st.buffer[1]) & 3;
  switch (residue_77)
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

  int index_reg_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_77) & 63;
  acc ^= aux;
  int window_40 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_40 = ((window_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_40) & 127;
  }

  int tracker_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_28 > 41)
  {
    acc = ((acc + (tracker_28 * 2)) + 5) & 127;
    aux ^= tracker_28 & 15;
  }
  else
  {
    acc = ((acc - tracker_28) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001847_4713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001847_4713_3 st_1 = {0};
  struct EventLog_R001847_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int accumulator_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_88_1)
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

  switch (accumulator_88_2)
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

  int mask_89_1 = 0;
  int mask_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_89_1 = ((mask_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_89_2 = ((mask_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_89_1) & 127;
    acc_2 = (acc_2 + mask_89_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_88_1 == accumulator_88_2);
  assert(mask_89_1 == mask_89_2);
}

int fn_R001847_4713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001847_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int accumulator_88 = (aux + st.buffer[1]) & 3;
  switch (accumulator_88)
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

  int mask_89 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_89 = ((mask_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_89) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001847_4713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001847_4713_3 st_1 = {0};
  struct EventLog_R001847_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_89_1 > 42)
  {
    acc_1 = ((acc_1 + (segment_89_1 * 2)) + 5) & 127;
    aux_1 ^= segment_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_89_2 > 42)
  {
    acc_2 = ((acc_2 + (segment_89_2 * 2)) + 5) & 127;
    aux_2 ^= segment_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_89_1 == segment_89_2);
}

int fn_R001847_4713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001847_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_89 > 42)
  {
    acc = ((acc + (segment_89 * 2)) + 5) & 127;
    aux ^= segment_89 & 15;
  }
  else
  {
    acc = ((acc - segment_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001847_4713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001847_4713_2 st_1 = {0};
  struct StreamBuffer_R001847_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int metric_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_39_1) & 63;
  aux_2 = (aux_2 + metric_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_48_1 > 19)
  {
    acc_1 = ((acc_1 + (cursor_48_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_48_2 > 19)
  {
    acc_2 = ((acc_2 + (cursor_48_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_83_1 = local_arr_1[aux_1 % 3];
  int pivot_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_83_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_39_1 == metric_39_2);
  assert(cursor_48_1 == cursor_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_83_1 == pivot_83_2);
}

int fn_R001847_4713_10(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001847_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int metric_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_39) & 63;
  acc ^= aux;
  int cursor_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_48 > 19)
  {
    acc = ((acc + (cursor_48 * 2)) + 5) & 127;
    aux ^= cursor_48 & 15;
  }
  else
  {
    acc = ((acc - cursor_48) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int pivot_83 = local_arr[aux % 3];
  acc = (acc + (pivot_83 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001847_4713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001847_4713_2 st_1 = {0};
  struct StreamBuffer_R001847_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_33_1 = local_arr_1[aux_1 % 3];
  int quantum_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_33_2 * 2)) & 127;
  int window_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_20_1 > 48)
  {
    acc_1 = ((acc_1 + (window_20_1 * 2)) + 5) & 127;
    aux_1 ^= window_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_20_2 > 48)
  {
    acc_2 = ((acc_2 + (window_20_2 * 2)) + 5) & 127;
    aux_2 ^= window_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_20_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_33_1 == quantum_33_2);
  assert(window_20_1 == window_20_2);
}

int fn_R001847_4713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001847_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int quantum_33 = local_arr[aux % 3];
  acc = (acc + (quantum_33 * 2)) & 127;
  int window_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_20 > 48)
  {
    acc = ((acc + (window_20 * 2)) + 5) & 127;
    aux ^= window_20 & 15;
  }
  else
  {
    acc = ((acc - window_20) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001847_4713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001847_4713_0 st_1 = {0};
  struct FilterState_R001847_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int segment_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_10_1)
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

  switch (segment_10_2)
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

  int coefficient_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_86_1 > 27)
  {
    acc_1 = ((acc_1 + (coefficient_86_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_86_2 > 27)
  {
    acc_2 = ((acc_2 + (coefficient_86_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_65_1 = local_arr_1[aux_1 % 3];
  int tally_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_65_2 * 2)) & 127;
  int delta_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_71_1) & 63;
  aux_2 = (aux_2 + delta_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_10_1 == segment_10_2);
  assert(coefficient_86_1 == coefficient_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_65_1 == tally_65_2);
  assert(delta_71_1 == delta_71_2);
}

int fn_R001847_4713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001847_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int segment_10 = (aux + st.buffer[1]) & 3;
  switch (segment_10)
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

  int coefficient_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_86 > 27)
  {
    acc = ((acc + (coefficient_86 * 2)) + 5) & 127;
    aux ^= coefficient_86 & 15;
  }
  else
  {
    acc = ((acc - coefficient_86) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_65 = local_arr[aux % 3];
  acc = (acc + (tally_65 * 2)) & 127;
  int delta_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_71) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001847_4713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001847_4713_0 st_1 = {0};
  struct FilterState_R001847_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int mask_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_43_1)
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

  switch (mask_43_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_59_1) & 63;
  aux_2 = (aux_2 + anchor_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_85_1 = local_arr_1[aux_1 % 3];
  int phase_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_85_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_43_1 == mask_43_2);
  assert(anchor_59_1 == anchor_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_85_1 == phase_85_2);
}

int fn_R001847_4713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001847_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int mask_43 = (aux + st.buffer[1]) & 3;
  switch (mask_43)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_59) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_85 = local_arr[aux % 3];
  acc = (acc + (phase_85 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001847_4713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001847_4713_2 st_1 = {0};
  struct StreamBuffer_R001847_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_79_1 = local_arr_1[aux_1 % 3];
  int weight_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_79_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_58_1)
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

  switch (quotient_58_2)
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

  int window_96_1 = 0;
  int window_96_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_96_1 = ((window_96_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_96_2 = ((window_96_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_96_1) & 127;
    acc_2 = (acc_2 + window_96_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_79_1 == weight_79_2);
  assert(quotient_58_1 == quotient_58_2);
  assert(window_96_1 == window_96_2);
}

int fn_R001847_4713_14(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001847_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int weight_79 = local_arr[aux % 3];
  acc = (acc + (weight_79 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_58 = (aux + st.buffer[1]) & 3;
  switch (quotient_58)
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

  int window_96 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_96 = ((window_96 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_96) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001847_4713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001847_4713_3 st_1 = {0};
  struct EventLog_R001847_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_38_1)
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

  switch (mask_38_2)
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
  int mask_25_1 = local_arr_1[aux_1 % 3];
  int mask_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_25_2 * 2)) & 127;
  int threshold_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_73_1) & 63;
  aux_2 = (aux_2 + threshold_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_38_1 == mask_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_25_1 == mask_25_2);
  assert(threshold_73_1 == threshold_73_2);
}

int fn_R001847_4713_15(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001847_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_38 = (aux + st.buffer[1]) & 3;
  switch (mask_38)
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
  int mask_25 = local_arr[aux % 3];
  acc = (acc + (mask_25 * 2)) & 127;
  int threshold_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_73) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001847_4713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001847_4713_1 st_1 = {0};
  struct Transaction_R001847_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int quotient_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_92_1) & 63;
  aux_2 = (aux_2 + quotient_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_73_1 > 49)
  {
    acc_1 = ((acc_1 + (delta_73_1 * 2)) + 5) & 127;
    aux_1 ^= delta_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_73_2 > 49)
  {
    acc_2 = ((acc_2 + (delta_73_2 * 2)) + 5) & 127;
    aux_2 ^= delta_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_96_1 = local_arr_1[aux_1 % 3];
  int checksum_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_96_2 * 2)) & 127;
  int pivot_97_1 = 0;
  int pivot_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_97_1 = ((pivot_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_97_2 = ((pivot_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_97_1) & 127;
    acc_2 = (acc_2 + pivot_97_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_92_1 == quotient_92_2);
  assert(delta_73_1 == delta_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_96_1 == checksum_96_2);
  assert(pivot_97_1 == pivot_97_2);
}

int fn_R001847_4713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001847_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int quotient_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_92) & 63;
  acc ^= aux;
  int delta_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_73 > 49)
  {
    acc = ((acc + (delta_73 * 2)) + 5) & 127;
    aux ^= delta_73 & 15;
  }
  else
  {
    acc = ((acc - delta_73) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_96 = local_arr[aux % 3];
  acc = (acc + (checksum_96 * 2)) & 127;
  int pivot_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_97 = ((pivot_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_97) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001847_4713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001847_4713_2 st_1 = {0};
  struct StreamBuffer_R001847_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_17_1 = local_arr_1[aux_1 % 3];
  int parity_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_17_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_17_1 == parity_17_2);
}

int fn_R001847_4713_17(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001847_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int parity_17 = local_arr[aux % 3];
  acc = (acc + (parity_17 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001847_4713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001847_4713_0 st_1 = {0};
  struct FilterState_R001847_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_10_1 = 0;
  int anchor_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_10_1 = ((anchor_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_10_2 = ((anchor_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_10_1) & 127;
    acc_2 = (acc_2 + anchor_10_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_10_1 == anchor_10_2);
}

int fn_R001847_4713_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001847_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_10 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_10 = ((anchor_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_10) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001847_0_1;
  int sec_r001847_0_2;
  int sec_r001847_1_1;
  int sec_r001847_1_2;
  int sec_r001847_2_1;
  int sec_r001847_2_2;
  int sec_r001847_3_1;
  int sec_r001847_3_2;
  int sec_r001847_4_1;
  int sec_r001847_4_2;
  int sec_r001847_5_1;
  int sec_r001847_5_2;
  int sec_r001847_6_1;
  int sec_r001847_6_2;
  int sec_r001847_7_1;
  int sec_r001847_7_2;
  int sec_r001847_8_1;
  int sec_r001847_8_2;
  int sec_r001847_9_1;
  int sec_r001847_9_2;
  int sec_r001847_10_1;
  int sec_r001847_10_2;
  int sec_r001847_11_1;
  int sec_r001847_11_2;
  int sec_r001847_12_1;
  int sec_r001847_12_2;
  int sec_r001847_13_1;
  int sec_r001847_13_2;
  int sec_r001847_14_1;
  int sec_r001847_14_2;
  int sec_r001847_15_1;
  int sec_r001847_15_2;
  int pub_r001847_0_1;
  int pub_r001847_0_2;
  int pub_r001847_1_1;
  int pub_r001847_1_2;
  int pub_r001847_2_1;
  int pub_r001847_2_2;
  int pub_r001847_3_1;
  int pub_r001847_3_2;
  int pub_r001847_4_1;
  int pub_r001847_4_2;
  int pub_r001847_5_1;
  int pub_r001847_5_2;
  int pub_r001847_6_1;
  int pub_r001847_6_2;
  int pub_r001847_7_1;
  int pub_r001847_7_2;
  int pub_r001847_8_1;
  int pub_r001847_8_2;
  int pub_r001847_9_1;
  int pub_r001847_9_2;
  int pub_r001847_10_1;
  int pub_r001847_10_2;
  int pub_r001847_11_1;
  int pub_r001847_11_2;
  int pub_r001847_12_1;
  int pub_r001847_12_2;
  int pub_r001847_13_1;
  int pub_r001847_13_2;
  int pub_r001847_14_1;
  int pub_r001847_14_2;
  int pub_r001847_15_1;
  int pub_r001847_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001847_0_1 >= (-100)) && (pub_r001847_0_1 <= 100));
  __CPROVER_assume((pub_r001847_0_2 >= (-100)) && (pub_r001847_0_2 <= 100));
  __CPROVER_assume((pub_r001847_1_1 >= (-100)) && (pub_r001847_1_1 <= 100));
  __CPROVER_assume((pub_r001847_1_2 >= (-100)) && (pub_r001847_1_2 <= 100));
  __CPROVER_assume((pub_r001847_2_1 >= (-100)) && (pub_r001847_2_1 <= 100));
  __CPROVER_assume((pub_r001847_2_2 >= (-100)) && (pub_r001847_2_2 <= 100));
  __CPROVER_assume((pub_r001847_3_1 >= (-100)) && (pub_r001847_3_1 <= 100));
  __CPROVER_assume((pub_r001847_3_2 >= (-100)) && (pub_r001847_3_2 <= 100));
  __CPROVER_assume((pub_r001847_4_1 >= (-100)) && (pub_r001847_4_1 <= 100));
  __CPROVER_assume((pub_r001847_4_2 >= (-100)) && (pub_r001847_4_2 <= 100));
  __CPROVER_assume((pub_r001847_5_1 >= (-100)) && (pub_r001847_5_1 <= 100));
  __CPROVER_assume((pub_r001847_5_2 >= (-100)) && (pub_r001847_5_2 <= 100));
  __CPROVER_assume((pub_r001847_6_1 >= (-100)) && (pub_r001847_6_1 <= 100));
  __CPROVER_assume((pub_r001847_6_2 >= (-100)) && (pub_r001847_6_2 <= 100));
  __CPROVER_assume((pub_r001847_7_1 >= (-100)) && (pub_r001847_7_1 <= 100));
  __CPROVER_assume((pub_r001847_7_2 >= (-100)) && (pub_r001847_7_2 <= 100));
  __CPROVER_assume((pub_r001847_8_1 >= (-100)) && (pub_r001847_8_1 <= 100));
  __CPROVER_assume((pub_r001847_8_2 >= (-100)) && (pub_r001847_8_2 <= 100));
  __CPROVER_assume((pub_r001847_9_1 >= (-100)) && (pub_r001847_9_1 <= 100));
  __CPROVER_assume((pub_r001847_9_2 >= (-100)) && (pub_r001847_9_2 <= 100));
  __CPROVER_assume((pub_r001847_10_1 >= (-100)) && (pub_r001847_10_1 <= 100));
  __CPROVER_assume((pub_r001847_10_2 >= (-100)) && (pub_r001847_10_2 <= 100));
  __CPROVER_assume((pub_r001847_11_1 >= (-100)) && (pub_r001847_11_1 <= 100));
  __CPROVER_assume((pub_r001847_11_2 >= (-100)) && (pub_r001847_11_2 <= 100));
  __CPROVER_assume((pub_r001847_12_1 >= (-100)) && (pub_r001847_12_1 <= 100));
  __CPROVER_assume((pub_r001847_12_2 >= (-100)) && (pub_r001847_12_2 <= 100));
  __CPROVER_assume((pub_r001847_13_1 >= (-100)) && (pub_r001847_13_1 <= 100));
  __CPROVER_assume((pub_r001847_13_2 >= (-100)) && (pub_r001847_13_2 <= 100));
  __CPROVER_assume((pub_r001847_14_1 >= (-100)) && (pub_r001847_14_1 <= 100));
  __CPROVER_assume((pub_r001847_14_2 >= (-100)) && (pub_r001847_14_2 <= 100));
  __CPROVER_assume((pub_r001847_15_1 >= (-100)) && (pub_r001847_15_1 <= 100));
  __CPROVER_assume((pub_r001847_15_2 >= (-100)) && (pub_r001847_15_2 <= 100));
  __CPROVER_assume((sec_r001847_0_1 >= 0) && (sec_r001847_0_1 <= 255));
  __CPROVER_assume((sec_r001847_0_2 >= 0) && (sec_r001847_0_2 <= 255));
  __CPROVER_assume((sec_r001847_1_1 >= 0) && (sec_r001847_1_1 <= 255));
  __CPROVER_assume((sec_r001847_1_2 >= 0) && (sec_r001847_1_2 <= 255));
  __CPROVER_assume((sec_r001847_2_1 >= 0) && (sec_r001847_2_1 <= 255));
  __CPROVER_assume((sec_r001847_2_2 >= 0) && (sec_r001847_2_2 <= 255));
  __CPROVER_assume((sec_r001847_3_1 >= 0) && (sec_r001847_3_1 <= 255));
  __CPROVER_assume((sec_r001847_3_2 >= 0) && (sec_r001847_3_2 <= 255));
  __CPROVER_assume((sec_r001847_4_1 >= 0) && (sec_r001847_4_1 <= 255));
  __CPROVER_assume((sec_r001847_4_2 >= 0) && (sec_r001847_4_2 <= 255));
  __CPROVER_assume((sec_r001847_5_1 >= 0) && (sec_r001847_5_1 <= 255));
  __CPROVER_assume((sec_r001847_5_2 >= 0) && (sec_r001847_5_2 <= 255));
  __CPROVER_assume((sec_r001847_6_1 >= 0) && (sec_r001847_6_1 <= 255));
  __CPROVER_assume((sec_r001847_6_2 >= 0) && (sec_r001847_6_2 <= 255));
  __CPROVER_assume((sec_r001847_7_1 >= 0) && (sec_r001847_7_1 <= 255));
  __CPROVER_assume((sec_r001847_7_2 >= 0) && (sec_r001847_7_2 <= 255));
  __CPROVER_assume((sec_r001847_8_1 >= 0) && (sec_r001847_8_1 <= 255));
  __CPROVER_assume((sec_r001847_8_2 >= 0) && (sec_r001847_8_2 <= 255));
  __CPROVER_assume((sec_r001847_9_1 >= 0) && (sec_r001847_9_1 <= 255));
  __CPROVER_assume((sec_r001847_9_2 >= 0) && (sec_r001847_9_2 <= 255));
  __CPROVER_assume((sec_r001847_10_1 >= 0) && (sec_r001847_10_1 <= 255));
  __CPROVER_assume((sec_r001847_10_2 >= 0) && (sec_r001847_10_2 <= 255));
  __CPROVER_assume((sec_r001847_11_1 >= 0) && (sec_r001847_11_1 <= 255));
  __CPROVER_assume((sec_r001847_11_2 >= 0) && (sec_r001847_11_2 <= 255));
  __CPROVER_assume((sec_r001847_12_1 >= 0) && (sec_r001847_12_1 <= 255));
  __CPROVER_assume((sec_r001847_12_2 >= 0) && (sec_r001847_12_2 <= 255));
  __CPROVER_assume((sec_r001847_13_1 >= 0) && (sec_r001847_13_1 <= 255));
  __CPROVER_assume((sec_r001847_13_2 >= 0) && (sec_r001847_13_2 <= 255));
  __CPROVER_assume((sec_r001847_14_1 >= 0) && (sec_r001847_14_1 <= 255));
  __CPROVER_assume((sec_r001847_14_2 >= 0) && (sec_r001847_14_2 <= 255));
  __CPROVER_assume((sec_r001847_15_1 >= 0) && (sec_r001847_15_1 <= 255));
  __CPROVER_assume((sec_r001847_15_2 >= 0) && (sec_r001847_15_2 <= 255));
  struct FilterState_R001847_4713_0 st_var_0_1 = {0};
  struct FilterState_R001847_4713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001847_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001847_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001847_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001847_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001847_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001847_0_2 + 7) & 15;
  struct Transaction_R001847_4713_1 st_var_1_1 = {0};
  struct Transaction_R001847_4713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001847_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001847_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001847_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001847_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001847_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001847_0_2 + 9) & 15;
  struct StreamBuffer_R001847_4713_2 st_var_2_1 = {0};
  struct StreamBuffer_R001847_4713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001847_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001847_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001847_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001847_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001847_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001847_0_2 + 11) & 15;
  struct EventLog_R001847_4713_3 st_var_3_1 = {0};
  struct EventLog_R001847_4713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001847_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001847_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001847_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001847_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001847_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001847_0_2 + 13) & 15;
  union TelemetryField_R001847_4713_0 u_var_1;
  union TelemetryField_R001847_4713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001847_4713_0(sec_r001847_0_1, sec_r001847_1_1, pub_r001847_2_1, pub_r001847_3_1);
  int helper_flow_0_2 = fn_R001847_4713_0(sec_r001847_0_2, sec_r001847_1_2, pub_r001847_2_2, pub_r001847_3_2);
  fn_R001847_4713_0_2(sec_r001847_0_1, sec_r001847_1_1, pub_r001847_2_1, pub_r001847_3_1, sec_r001847_0_2, sec_r001847_1_2, pub_r001847_2_2, pub_r001847_3_2);
  int helper_flow_1_1 = fn_R001847_4713_1(sec_r001847_1_1, sec_r001847_2_1, pub_r001847_3_1, pub_r001847_4_1);
  int helper_flow_1_2 = fn_R001847_4713_1(sec_r001847_1_2, sec_r001847_2_2, pub_r001847_3_2, pub_r001847_4_2);
  fn_R001847_4713_1_2(sec_r001847_1_1, sec_r001847_2_1, pub_r001847_3_1, pub_r001847_4_1, sec_r001847_1_2, sec_r001847_2_2, pub_r001847_3_2, pub_r001847_4_2);
  int helper_flow_2_1 = fn_R001847_4713_2(sec_r001847_2_1, pub_r001847_3_1, pub_r001847_4_1);
  int helper_flow_2_2 = fn_R001847_4713_2(sec_r001847_2_2, pub_r001847_3_2, pub_r001847_4_2);
  fn_R001847_4713_2_2(sec_r001847_2_1, pub_r001847_3_1, pub_r001847_4_1, sec_r001847_2_2, pub_r001847_3_2, pub_r001847_4_2);
  int helper_flow_3_1 = fn_R001847_4713_3(sec_r001847_3_1, pub_r001847_4_1, pub_r001847_5_1, pub_r001847_6_1, pub_r001847_7_1);
  int helper_flow_3_2 = fn_R001847_4713_3(sec_r001847_3_2, pub_r001847_4_2, pub_r001847_5_2, pub_r001847_6_2, pub_r001847_7_2);
  fn_R001847_4713_3_2(sec_r001847_3_1, pub_r001847_4_1, pub_r001847_5_1, pub_r001847_6_1, pub_r001847_7_1, sec_r001847_3_2, pub_r001847_4_2, pub_r001847_5_2, pub_r001847_6_2, pub_r001847_7_2);
  int helper_flow_4_1 = fn_R001847_4713_4(sec_r001847_4_1, pub_r001847_5_1, pub_r001847_6_1, pub_r001847_7_1, pub_r001847_8_1);
  int helper_flow_4_2 = fn_R001847_4713_4(sec_r001847_4_2, pub_r001847_5_2, pub_r001847_6_2, pub_r001847_7_2, pub_r001847_8_2);
  fn_R001847_4713_4_2(sec_r001847_4_1, pub_r001847_5_1, pub_r001847_6_1, pub_r001847_7_1, pub_r001847_8_1, sec_r001847_4_2, pub_r001847_5_2, pub_r001847_6_2, pub_r001847_7_2, pub_r001847_8_2);
  int helper_flow_5_1 = fn_R001847_4713_5(sec_r001847_5_1, pub_r001847_6_1);
  int helper_flow_5_2 = fn_R001847_4713_5(sec_r001847_5_2, pub_r001847_6_2);
  fn_R001847_4713_5_2(sec_r001847_5_1, pub_r001847_6_1, sec_r001847_5_2, pub_r001847_6_2);
  int helper_flow_6_1 = fn_R001847_4713_6(sec_r001847_6_1, pub_r001847_7_1);
  int helper_flow_6_2 = fn_R001847_4713_6(sec_r001847_6_2, pub_r001847_7_2);
  fn_R001847_4713_6_2(sec_r001847_6_1, pub_r001847_7_1, sec_r001847_6_2, pub_r001847_7_2);
  int helper_flow_7_1 = fn_R001847_4713_7(sec_r001847_7_1, pub_r001847_8_1);
  int helper_flow_7_2 = fn_R001847_4713_7(sec_r001847_7_2, pub_r001847_8_2);
  fn_R001847_4713_7_2(sec_r001847_7_1, pub_r001847_8_1, sec_r001847_7_2, pub_r001847_8_2);
  int helper_flow_8_1 = fn_R001847_4713_8(sec_r001847_8_1, pub_r001847_9_1, pub_r001847_10_1, pub_r001847_11_1);
  int helper_flow_8_2 = fn_R001847_4713_8(sec_r001847_8_2, pub_r001847_9_2, pub_r001847_10_2, pub_r001847_11_2);
  fn_R001847_4713_8_2(sec_r001847_8_1, pub_r001847_9_1, pub_r001847_10_1, pub_r001847_11_1, sec_r001847_8_2, pub_r001847_9_2, pub_r001847_10_2, pub_r001847_11_2);
  int helper_flow_9_1 = fn_R001847_4713_9(sec_r001847_9_1, sec_r001847_10_1, pub_r001847_11_1, pub_r001847_12_1);
  int helper_flow_9_2 = fn_R001847_4713_9(sec_r001847_9_2, sec_r001847_10_2, pub_r001847_11_2, pub_r001847_12_2);
  fn_R001847_4713_9_2(sec_r001847_9_1, sec_r001847_10_1, pub_r001847_11_1, pub_r001847_12_1, sec_r001847_9_2, sec_r001847_10_2, pub_r001847_11_2, pub_r001847_12_2);
  int helper_flow_10_1 = fn_R001847_4713_10(sec_r001847_10_1, sec_r001847_11_1);
  int helper_flow_10_2 = fn_R001847_4713_10(sec_r001847_10_2, sec_r001847_11_2);
  fn_R001847_4713_10_2(sec_r001847_10_1, sec_r001847_11_1, sec_r001847_10_2, sec_r001847_11_2);
  int stage_v_0_1 = (helper_flow_8_1 ^ pub_r001847_12_1) & 63;
  int stage_v_0_2 = (helper_flow_8_2 ^ pub_r001847_12_2) & 63;
  if ((stage_v_0_1 & 1) != 0)
  {
    if ((sec_r001847_12_1 & 2) != 0)
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
    if ((sec_r001847_12_2 & 2) != 0)
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
  int stage_v_1_1 = (sec_r001847_2_1 ^ pub_r001847_13_1) & 63;
  int stage_v_1_2 = (sec_r001847_2_2 ^ pub_r001847_13_2) & 63;
  if ((stage_v_1_1 & 1) != 0)
  {
    if ((sec_r001847_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_1_1 * 2)) & 255;
  }
  if ((stage_v_1_2 & 1) != 0)
  {
    if ((sec_r001847_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_1_2 * 2)) & 255;
  }
  int stage_v_2_1 = (helper_flow_9_1 ^ pub_r001847_12_1) & 63;
  int stage_v_2_2 = (helper_flow_9_2 ^ pub_r001847_12_2) & 63;
  if ((stage_v_2_1 & 1) != 0)
  {
    if ((sec_r001847_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_2_1 * 2)) & 255;
  }
  if ((stage_v_2_2 & 1) != 0)
  {
    if ((sec_r001847_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_2_2 * 2)) & 255;
  }
  int stage_v_3_1 = (sec_r001847_4_1 ^ pub_r001847_1_1) & 63;
  int stage_v_3_2 = (sec_r001847_4_2 ^ pub_r001847_1_2) & 63;
  if ((stage_v_3_1 & 1) != 0)
  {
    if ((sec_r001847_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_3_1 * 2)) & 255;
  }
  if ((stage_v_3_2 & 1) != 0)
  {
    if ((sec_r001847_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_3_2 * 2)) & 255;
  }
  int stage_v_4_1 = (sec_r001847_14_1 ^ pub_r001847_6_1) & 63;
  int stage_v_4_2 = (sec_r001847_14_2 ^ pub_r001847_6_2) & 63;
  if ((stage_v_4_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
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
    if ((helper_flow_0_2 & 2) != 0)
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
  int stage_v_5_1 = (sec_r001847_15_1 ^ pub_r001847_13_1) & 63;
  int stage_v_5_2 = (sec_r001847_15_2 ^ pub_r001847_13_2) & 63;
  if ((stage_v_5_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
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
    if ((helper_flow_2_2 & 2) != 0)
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
  int stage_v_6_1 = (helper_flow_8_1 ^ pub_r001847_2_1) & 63;
  int stage_v_6_2 = (helper_flow_8_2 ^ pub_r001847_2_2) & 63;
  if ((stage_v_6_1 & 1) != 0)
  {
    if ((sec_r001847_4_1 & 2) != 0)
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
    if ((sec_r001847_4_2 & 2) != 0)
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
  int stage_v_7_1 = ((pub_r001847_1_1 * 2) + 17) & 63;
  int stage_v_7_2 = ((pub_r001847_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (sec_r001847_5_1 ^ pub_r001847_11_1) & 63;
  int stage_v_8_2 = (sec_r001847_5_2 ^ pub_r001847_11_2) & 63;
  if ((stage_v_8_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_8_1 * 2)) & 255;
  }
  if ((stage_v_8_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_8_2 * 2)) & 255;
  }
  int stage_v_9_1 = (stage_v_1_1 ^ pub_r001847_14_1) & 63;
  int stage_v_9_2 = (stage_v_1_2 ^ pub_r001847_14_2) & 63;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
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
    if ((helper_flow_6_2 & 2) != 0)
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
  int stage_v_10_1 = (stage_v_4_1 ^ pub_r001847_3_1) & 63;
  int stage_v_10_2 = (stage_v_4_2 ^ pub_r001847_3_2) & 63;
  if ((stage_v_10_1 & 1) != 0)
  {
    if ((sec_r001847_15_1 & 2) != 0)
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
    if ((sec_r001847_15_2 & 2) != 0)
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
  int stage_v_11_1 = ((pub_r001847_10_1 * 2) + 34) & 63;
  int stage_v_11_2 = ((pub_r001847_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (sec_r001847_12_1 ^ pub_r001847_9_1) & 63;
  int stage_v_12_2 = (sec_r001847_12_2 ^ pub_r001847_9_2) & 63;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((sec_r001847_0_1 & 2) != 0)
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
    if ((sec_r001847_0_2 & 2) != 0)
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
  int stage_v_13_1 = (helper_flow_5_1 ^ pub_r001847_11_1) & 63;
  int stage_v_13_2 = (helper_flow_5_2 ^ pub_r001847_11_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r001847_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_13_1 * 2)) & 255;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((sec_r001847_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_13_2 * 2)) & 255;
  }
  int stage_v_14_1 = (helper_flow_6_1 ^ pub_r001847_10_1) & 63;
  int stage_v_14_2 = (helper_flow_6_2 ^ pub_r001847_10_2) & 63;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r001847_2_1 & 2) != 0)
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
    if ((sec_r001847_2_2 & 2) != 0)
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
  int stage_v_15_1 = (sec_r001847_12_1 ^ pub_r001847_14_1) & 63;
  int stage_v_15_2 = (sec_r001847_12_2 ^ pub_r001847_14_2) & 63;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r001847_9_1 & 2) != 0)
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
    if ((sec_r001847_9_2 & 2) != 0)
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
  int stage_v_16_1 = ((pub_r001847_12_1 * 2) + 43) & 63;
  int stage_v_16_2 = ((pub_r001847_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (stage_v_0_1 ^ pub_r001847_7_1) & 63;
  int stage_v_17_2 = (stage_v_0_2 ^ pub_r001847_7_2) & 63;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r001847_10_1 & 2) != 0)
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
    if ((sec_r001847_10_2 & 2) != 0)
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
  int stage_v_18_1 = ((pub_r001847_10_1 * 2) + 17) & 63;
  int stage_v_18_2 = ((pub_r001847_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (stage_v_9_1 ^ pub_r001847_10_1) & 63;
  int stage_v_19_2 = (stage_v_9_2 ^ pub_r001847_10_2) & 63;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_19_1 * 2)) & 255;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((stage_v_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_19_2 * 2)) & 255;
  }
  int stage_v_20_1 = (helper_flow_8_1 ^ pub_r001847_8_1) & 63;
  int stage_v_20_2 = (helper_flow_8_2 ^ pub_r001847_8_2) & 63;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r001847_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_20_1 * 2)) & 255;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r001847_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_20_2 * 2)) & 255;
  }
  int stage_v_21_1 = (stage_v_0_1 ^ pub_r001847_4_1) & 63;
  int stage_v_21_2 = (stage_v_0_2 ^ pub_r001847_4_2) & 63;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_21_1 * 2)) & 255;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_21_2 * 2)) & 255;
  }
  int stage_v_22_1 = ((pub_r001847_6_1 * 2) + 12) & 63;
  int stage_v_22_2 = ((pub_r001847_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (sec_r001847_12_1 ^ pub_r001847_12_1) & 63;
  int stage_v_23_2 = (sec_r001847_12_2 ^ pub_r001847_12_2) & 63;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
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
    if ((helper_flow_5_2 & 2) != 0)
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
  int stage_v_24_1 = (stage_v_23_1 ^ pub_r001847_9_1) & 63;
  int stage_v_24_2 = (stage_v_23_2 ^ pub_r001847_9_2) & 63;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_24_1 * 2)) & 255;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((helper_flow_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_24_2 * 2)) & 255;
  }
  int stage_v_25_1 = ((pub_r001847_1_1 * 2) + 32) & 63;
  int stage_v_25_2 = ((pub_r001847_1_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001847_4_1 * 2) + 9) & 63;
  int stage_v_26_2 = ((pub_r001847_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = (helper_flow_0_1 ^ pub_r001847_10_1) & 63;
  int stage_v_27_2 = (helper_flow_0_2 ^ pub_r001847_10_2) & 63;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((stage_v_8_1 & 2) != 0)
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
    if ((stage_v_8_2 & 2) != 0)
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
  int stage_v_28_1 = ((pub_r001847_8_1 * 2) + 17) & 63;
  int stage_v_28_2 = ((pub_r001847_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (sec_r001847_5_1 ^ pub_r001847_8_1) & 63;
  int stage_v_29_2 = (sec_r001847_5_2 ^ pub_r001847_8_2) & 63;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((helper_flow_9_1 & 2) != 0)
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
    if ((helper_flow_9_2 & 2) != 0)
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
  int stage_v_30_1 = (helper_flow_7_1 ^ pub_r001847_4_1) & 63;
  int stage_v_30_2 = (helper_flow_7_2 ^ pub_r001847_4_2) & 63;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_30_1 * 2)) & 255;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_30_2 * 2)) & 255;
  }
  int stage_v_31_1 = (stage_v_13_1 ^ pub_r001847_9_1) & 63;
  int stage_v_31_2 = (stage_v_13_2 ^ pub_r001847_9_2) & 63;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((stage_v_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_31_1 * 2)) & 255;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((stage_v_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_31_2 * 2)) & 255;
  }
  int stage_v_32_1 = (stage_v_29_1 ^ pub_r001847_8_1) & 63;
  int stage_v_32_2 = (stage_v_29_2 ^ pub_r001847_8_2) & 63;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
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
    if ((stage_v_27_2 & 2) != 0)
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
  int stage_v_33_1 = ((pub_r001847_2_1 * 2) + 33) & 63;
  int stage_v_33_2 = ((pub_r001847_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (stage_v_4_1 ^ pub_r001847_3_1) & 63;
  int stage_v_34_2 = (stage_v_4_2 ^ pub_r001847_3_2) & 63;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r001847_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_34_1 * 2)) & 255;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r001847_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_34_2 * 2)) & 255;
  }
  int stage_v_35_1 = (stage_v_21_1 ^ pub_r001847_2_1) & 63;
  int stage_v_35_2 = (stage_v_21_2 ^ pub_r001847_2_2) & 63;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_35_1 * 2)) & 255;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_35_2 * 2)) & 255;
  }
  int stage_v_36_1 = (sec_r001847_3_1 ^ pub_r001847_8_1) & 63;
  int stage_v_36_2 = (sec_r001847_3_2 ^ pub_r001847_8_2) & 63;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_36_1 * 2)) & 255;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_36_2 * 2)) & 255;
  }
  int stage_v_37_1 = ((pub_r001847_8_1 * 2) + 14) & 63;
  int stage_v_37_2 = ((pub_r001847_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (helper_flow_2_1 ^ pub_r001847_3_1) & 63;
  int stage_v_38_2 = (helper_flow_2_2 ^ pub_r001847_3_2) & 63;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
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
    if ((stage_v_23_2 & 2) != 0)
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
  int stage_v_39_1 = (sec_r001847_14_1 ^ pub_r001847_6_1) & 63;
  int stage_v_39_2 = (sec_r001847_14_2 ^ pub_r001847_6_2) & 63;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r001847_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_39_1 * 2)) & 255;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r001847_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_39_2 * 2)) & 255;
  }
  int stage_v_40_1 = (stage_v_8_1 ^ pub_r001847_1_1) & 63;
  int stage_v_40_2 = (stage_v_8_2 ^ pub_r001847_1_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r001847_11_1 & 2) != 0)
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
    if ((sec_r001847_11_2 & 2) != 0)
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
  int stage_v_41_1 = (stage_v_39_1 ^ pub_r001847_2_1) & 63;
  int stage_v_41_2 = (stage_v_39_2 ^ pub_r001847_2_2) & 63;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((stage_v_4_1 & 2) != 0)
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
    if ((stage_v_4_2 & 2) != 0)
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
  int stage_v_42_1 = ((pub_r001847_5_1 * 2) + 43) & 63;
  int stage_v_42_2 = ((pub_r001847_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (stage_v_38_1 ^ pub_r001847_1_1) & 63;
  int stage_v_43_2 = (stage_v_38_2 ^ pub_r001847_1_2) & 63;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r001847_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_43_1 * 2)) & 255;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r001847_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_43_2 * 2)) & 255;
  }
  int stage_v_44_1 = (stage_v_17_1 ^ pub_r001847_14_1) & 63;
  int stage_v_44_2 = (stage_v_17_2 ^ pub_r001847_14_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((stage_v_12_1 & 2) != 0)
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
    if ((stage_v_12_2 & 2) != 0)
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
  int stage_v_45_1 = (stage_v_34_1 ^ pub_r001847_6_1) & 63;
  int stage_v_45_2 = (stage_v_34_2 ^ pub_r001847_6_2) & 63;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((stage_v_5_1 & 2) != 0)
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
    if ((stage_v_5_2 & 2) != 0)
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
  int stage_v_46_1 = (helper_flow_8_1 ^ pub_r001847_9_1) & 63;
  int stage_v_46_2 = (helper_flow_8_2 ^ pub_r001847_9_2) & 63;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
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
    if ((stage_v_21_2 & 2) != 0)
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
  int stage_v_47_1 = ((pub_r001847_7_1 * 2) + 13) & 63;
  int stage_v_47_2 = ((pub_r001847_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001847_5_1 * 2) + 41) & 63;
  int stage_v_48_2 = ((pub_r001847_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001847_11_1 * 2) + 5) & 63;
  int stage_v_49_2 = ((pub_r001847_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (stage_v_0_1 ^ pub_r001847_12_1) & 63;
  int stage_v_50_2 = (stage_v_0_2 ^ pub_r001847_12_2) & 63;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
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
    if ((helper_flow_5_2 & 2) != 0)
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
  int stage_v_51_1 = ((pub_r001847_9_1 * 2) + 5) & 63;
  int stage_v_51_2 = ((pub_r001847_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001847_9_1 * 2) + 26) & 63;
  int stage_v_52_2 = ((pub_r001847_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001847_10_1 * 2) + 50) & 63;
  int stage_v_53_2 = ((pub_r001847_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001847_6_1 * 2) + 31) & 63;
  int stage_v_54_2 = ((pub_r001847_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (sec_r001847_11_1 ^ pub_r001847_3_1) & 63;
  int stage_v_55_2 = (sec_r001847_11_2 ^ pub_r001847_3_2) & 63;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
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
    if ((stage_v_34_2 & 2) != 0)
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
  int stage_v_56_1 = (stage_v_8_1 ^ pub_r001847_10_1) & 63;
  int stage_v_56_2 = (stage_v_8_2 ^ pub_r001847_10_2) & 63;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r001847_8_1 & 2) != 0)
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
    if ((sec_r001847_8_2 & 2) != 0)
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
  int stage_v_57_1 = (stage_v_50_1 ^ pub_r001847_15_1) & 63;
  int stage_v_57_2 = (stage_v_50_2 ^ pub_r001847_15_2) & 63;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((stage_v_35_1 & 2) != 0)
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
    if ((stage_v_35_2 & 2) != 0)
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
  int stage_v_58_1 = ((pub_r001847_15_1 * 2) + 43) & 63;
  int stage_v_58_2 = ((pub_r001847_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (sec_r001847_2_1 ^ pub_r001847_4_1) & 63;
  int stage_v_59_2 = (sec_r001847_2_2 ^ pub_r001847_4_2) & 63;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r001847_13_1 & 2) != 0)
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
    if ((sec_r001847_13_2 & 2) != 0)
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
  int stage_v_60_1 = ((pub_r001847_2_1 * 2) + 36) & 63;
  int stage_v_60_2 = ((pub_r001847_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001847_11_1 * 2) + 41) & 63;
  int stage_v_61_2 = ((pub_r001847_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001847_14_1 * 2) + 41) & 63;
  int stage_v_62_2 = ((pub_r001847_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (helper_flow_7_1 ^ pub_r001847_9_1) & 63;
  int stage_v_63_2 = (helper_flow_7_2 ^ pub_r001847_9_2) & 63;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_63_1 * 2)) & 255;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((stage_v_38_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_63_2 * 2)) & 255;
  }
  int stage_v_64_1 = ((pub_r001847_6_1 * 2) + 30) & 63;
  int stage_v_64_2 = ((pub_r001847_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001847_4_1 * 2) + 41) & 63;
  int stage_v_65_2 = ((pub_r001847_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (stage_v_44_1 ^ pub_r001847_6_1) & 63;
  int stage_v_66_2 = (stage_v_44_2 ^ pub_r001847_6_2) & 63;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((stage_v_36_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_66_1 * 2)) & 255;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((stage_v_36_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_66_2 * 2)) & 255;
  }
  int stage_v_67_1 = ((pub_r001847_9_1 * 2) + 17) & 63;
  int stage_v_67_2 = ((pub_r001847_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (stage_v_63_1 ^ pub_r001847_11_1) & 63;
  int stage_v_68_2 = (stage_v_63_2 ^ pub_r001847_11_2) & 63;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((stage_v_43_1 & 2) != 0)
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
    if ((stage_v_43_2 & 2) != 0)
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
  int stage_v_69_1 = (stage_v_59_1 ^ pub_r001847_2_1) & 63;
  int stage_v_69_2 = (stage_v_59_2 ^ pub_r001847_2_2) & 63;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((stage_v_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_69_1 * 2)) & 255;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((stage_v_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_69_2 * 2)) & 255;
  }
  int stage_v_70_1 = (stage_v_66_1 ^ pub_r001847_0_1) & 63;
  int stage_v_70_2 = (stage_v_66_2 ^ pub_r001847_0_2) & 63;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r001847_10_1 & 2) != 0)
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
    if ((sec_r001847_10_2 & 2) != 0)
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
  int stage_v_71_1 = ((pub_r001847_14_1 * 2) + 21) & 63;
  int stage_v_71_2 = ((pub_r001847_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (sec_r001847_8_1 ^ pub_r001847_13_1) & 63;
  int stage_v_72_2 = (sec_r001847_8_2 ^ pub_r001847_13_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((stage_v_70_1 & 2) != 0)
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
    if ((stage_v_70_2 & 2) != 0)
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
  int stage_v_73_1 = (sec_r001847_13_1 ^ pub_r001847_4_1) & 63;
  int stage_v_73_2 = (sec_r001847_13_2 ^ pub_r001847_4_2) & 63;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r001847_4_1 & 2) != 0)
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
    if ((sec_r001847_4_2 & 2) != 0)
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
  int stage_v_74_1 = ((pub_r001847_15_1 * 2) + 12) & 63;
  int stage_v_74_2 = ((pub_r001847_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (helper_flow_3_1 ^ pub_r001847_7_1) & 63;
  int stage_v_75_2 = (helper_flow_3_2 ^ pub_r001847_7_2) & 63;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((stage_v_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_75_1 * 2)) & 255;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((stage_v_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_75_2 * 2)) & 255;
  }
  int stage_v_76_1 = ((pub_r001847_5_1 * 2) + 9) & 63;
  int stage_v_76_2 = ((pub_r001847_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (sec_r001847_1_1 ^ pub_r001847_9_1) & 63;
  int stage_v_77_2 = (sec_r001847_1_2 ^ pub_r001847_9_2) & 63;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
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
    if ((stage_v_38_2 & 2) != 0)
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
  int stage_v_78_1 = ((pub_r001847_8_1 * 2) + 31) & 63;
  int stage_v_78_2 = ((pub_r001847_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001847_10_1 * 2) + 29) & 63;
  int stage_v_79_2 = ((pub_r001847_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (stage_v_20_1 ^ pub_r001847_14_1) & 63;
  int stage_v_80_2 = (stage_v_20_2 ^ pub_r001847_14_2) & 63;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((stage_v_63_1 & 2) != 0)
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
    if ((stage_v_63_2 & 2) != 0)
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
  int stage_v_81_1 = (stage_v_23_1 ^ pub_r001847_0_1) & 63;
  int stage_v_81_2 = (stage_v_23_2 ^ pub_r001847_0_2) & 63;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((stage_v_50_1 & 2) != 0)
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
    if ((stage_v_50_2 & 2) != 0)
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
  int stage_v_82_1 = (stage_v_40_1 ^ pub_r001847_2_1) & 63;
  int stage_v_82_2 = (stage_v_40_2 ^ pub_r001847_2_2) & 63;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r001847_4_1 & 2) != 0)
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
    if ((sec_r001847_4_2 & 2) != 0)
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
  int stage_v_83_1 = ((pub_r001847_3_1 * 2) + 28) & 63;
  int stage_v_83_2 = ((pub_r001847_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (stage_v_81_1 ^ pub_r001847_7_1) & 63;
  int stage_v_84_2 = (stage_v_81_2 ^ pub_r001847_7_2) & 63;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((stage_v_68_1 & 2) != 0)
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
    if ((stage_v_68_2 & 2) != 0)
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
  int stage_v_85_1 = (sec_r001847_9_1 ^ pub_r001847_13_1) & 63;
  int stage_v_85_2 = (sec_r001847_9_2 ^ pub_r001847_13_2) & 63;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((stage_v_45_1 & 2) != 0)
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
    if ((stage_v_45_2 & 2) != 0)
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
  int stage_v_86_1 = ((pub_r001847_12_1 * 2) + 27) & 63;
  int stage_v_86_2 = ((pub_r001847_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001847_12_1 * 2) + 37) & 63;
  int stage_v_87_2 = ((pub_r001847_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (stage_v_15_1 ^ pub_r001847_10_1) & 63;
  int stage_v_88_2 = (stage_v_15_2 ^ pub_r001847_10_2) & 63;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((stage_v_59_1 & 2) != 0)
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
    if ((stage_v_59_2 & 2) != 0)
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
  int stage_v_89_1 = (sec_r001847_3_1 ^ pub_r001847_11_1) & 63;
  int stage_v_89_2 = (sec_r001847_3_2 ^ pub_r001847_11_2) & 63;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((stage_v_81_1 & 2) != 0)
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
    if ((stage_v_81_2 & 2) != 0)
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
  int stage_v_90_1 = (helper_flow_5_1 ^ pub_r001847_7_1) & 63;
  int stage_v_90_2 = (helper_flow_5_2 ^ pub_r001847_7_2) & 63;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((stage_v_38_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  }
  int stage_v_91_1 = ((pub_r001847_8_1 * 2) + 8) & 63;
  int stage_v_91_2 = ((pub_r001847_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (stage_v_66_1 ^ pub_r001847_4_1) & 63;
  int stage_v_92_2 = (stage_v_66_2 ^ pub_r001847_4_2) & 63;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((stage_v_19_1 & 2) != 0)
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
    if ((stage_v_19_2 & 2) != 0)
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
  int stage_v_93_1 = ((pub_r001847_3_1 * 2) + 20) & 63;
  int stage_v_93_2 = ((pub_r001847_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (stage_v_92_1 ^ pub_r001847_0_1) & 63;
  int stage_v_94_2 = (stage_v_92_2 ^ pub_r001847_0_2) & 63;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((stage_v_57_1 & 2) != 0)
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
    if ((stage_v_57_2 & 2) != 0)
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
  int stage_v_95_1 = (stage_v_89_1 ^ pub_r001847_4_1) & 63;
  int stage_v_95_2 = (stage_v_89_2 ^ pub_r001847_4_2) & 63;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((stage_v_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((stage_v_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  }
  int stage_v_96_1 = (stage_v_57_1 ^ pub_r001847_9_1) & 63;
  int stage_v_96_2 = (stage_v_57_2 ^ pub_r001847_9_2) & 63;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_97_1 = ((pub_r001847_12_1 * 2) + 35) & 63;
  int stage_v_97_2 = ((pub_r001847_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (helper_flow_9_1 ^ pub_r001847_2_1) & 63;
  int stage_v_98_2 = (helper_flow_9_2 ^ pub_r001847_2_2) & 63;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((stage_v_84_1 & 2) != 0)
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
    if ((stage_v_84_2 & 2) != 0)
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
  int stage_v_99_1 = (helper_flow_9_1 ^ pub_r001847_13_1) & 63;
  int stage_v_99_2 = (helper_flow_9_2 ^ pub_r001847_13_2) & 63;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((stage_v_45_1 & 2) != 0)
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
    if ((stage_v_45_2 & 2) != 0)
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
  int stage_v_100_1 = ((pub_r001847_13_1 * 2) + 43) & 63;
  int stage_v_100_2 = ((pub_r001847_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001847_6_1 * 2) + 17) & 63;
  int stage_v_101_2 = ((pub_r001847_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001847_2_1 * 2) + 22) & 63;
  int stage_v_102_2 = ((pub_r001847_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (stage_v_41_1 ^ pub_r001847_1_1) & 63;
  int stage_v_103_2 = (stage_v_41_2 ^ pub_r001847_1_2) & 63;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((stage_v_35_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((stage_v_35_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  }
  int stage_v_104_1 = (stage_v_34_1 ^ pub_r001847_5_1) & 63;
  int stage_v_104_2 = (stage_v_34_2 ^ pub_r001847_5_2) & 63;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((stage_v_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((stage_v_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  }
  int stage_v_105_1 = ((pub_r001847_12_1 * 2) + 40) & 63;
  int stage_v_105_2 = ((pub_r001847_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001847_5_1 * 2) + 16) & 63;
  int stage_v_106_2 = ((pub_r001847_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001847_6_1 * 2) + 10) & 63;
  int stage_v_107_2 = ((pub_r001847_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (sec_r001847_9_1 ^ pub_r001847_7_1) & 63;
  int stage_v_108_2 = (sec_r001847_9_2 ^ pub_r001847_7_2) & 63;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((stage_v_46_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((stage_v_46_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  }
  int stage_v_109_1 = (stage_v_17_1 ^ pub_r001847_3_1) & 63;
  int stage_v_109_2 = (stage_v_17_2 ^ pub_r001847_3_2) & 63;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r001847_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r001847_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  }
  int stage_v_110_1 = (stage_v_95_1 ^ pub_r001847_6_1) & 63;
  int stage_v_110_2 = (stage_v_95_2 ^ pub_r001847_6_2) & 63;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((stage_v_57_1 & 2) != 0)
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
    if ((stage_v_57_2 & 2) != 0)
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
  int stage_v_111_1 = (sec_r001847_10_1 ^ pub_r001847_0_1) & 63;
  int stage_v_111_2 = (sec_r001847_10_2 ^ pub_r001847_0_2) & 63;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((stage_v_50_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((stage_v_50_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  }
  int stage_v_112_1 = ((pub_r001847_0_1 * 2) + 32) & 63;
  int stage_v_112_2 = ((pub_r001847_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (stage_v_3_1 ^ pub_r001847_13_1) & 63;
  int stage_v_113_2 = (stage_v_3_2 ^ pub_r001847_13_2) & 63;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r001847_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r001847_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  }
  int stage_v_114_1 = (stage_v_41_1 ^ pub_r001847_8_1) & 63;
  int stage_v_114_2 = (stage_v_41_2 ^ pub_r001847_8_2) & 63;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((stage_v_31_1 & 2) != 0)
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
    if ((stage_v_31_2 & 2) != 0)
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
  int stage_v_115_1 = (sec_r001847_9_1 ^ pub_r001847_2_1) & 63;
  int stage_v_115_2 = (sec_r001847_9_2 ^ pub_r001847_2_2) & 63;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((stage_v_114_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_115_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((stage_v_114_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_115_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  }
  int stage_v_116_1 = ((pub_r001847_0_1 * 2) + 20) & 63;
  int stage_v_116_2 = ((pub_r001847_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001847_15_1 * 2) + 28) & 63;
  int stage_v_117_2 = ((pub_r001847_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (stage_v_34_1 ^ pub_r001847_10_1) & 63;
  int stage_v_118_2 = (stage_v_34_2 ^ pub_r001847_10_2) & 63;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
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
    if ((stage_v_72_2 & 2) != 0)
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
  int stage_v_119_1 = (stage_v_24_1 ^ pub_r001847_8_1) & 63;
  int stage_v_119_2 = (stage_v_24_2 ^ pub_r001847_8_2) & 63;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
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
    if ((stage_v_44_2 & 2) != 0)
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
  int stage_v_120_1 = (stage_v_66_1 ^ pub_r001847_15_1) & 63;
  int stage_v_120_2 = (stage_v_66_2 ^ pub_r001847_15_2) & 63;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((stage_v_29_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((stage_v_29_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  }
  int stage_v_121_1 = (sec_r001847_6_1 ^ pub_r001847_11_1) & 63;
  int stage_v_121_2 = (sec_r001847_6_2 ^ pub_r001847_11_2) & 63;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((stage_v_72_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  }
  int stage_v_122_1 = (stage_v_104_1 ^ pub_r001847_6_1) & 63;
  int stage_v_122_2 = (stage_v_104_2 ^ pub_r001847_6_2) & 63;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
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
    if ((stage_v_6_2 & 2) != 0)
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
  int stage_v_123_1 = (stage_v_0_1 ^ pub_r001847_5_1) & 63;
  int stage_v_123_2 = (stage_v_0_2 ^ pub_r001847_5_2) & 63;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
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
    if ((stage_v_13_2 & 2) != 0)
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
  int stage_v_124_1 = (stage_v_88_1 ^ pub_r001847_10_1) & 63;
  int stage_v_124_2 = (stage_v_88_2 ^ pub_r001847_10_2) & 63;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r001847_10_1 & 2) != 0)
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
    if ((sec_r001847_10_2 & 2) != 0)
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
  int stage_v_125_1 = ((pub_r001847_7_1 * 2) + 18) & 63;
  int stage_v_125_2 = ((pub_r001847_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (stage_v_69_1 ^ pub_r001847_12_1) & 63;
  int stage_v_126_2 = (stage_v_69_2 ^ pub_r001847_12_2) & 63;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((stage_v_59_1 & 2) != 0)
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
    if ((stage_v_59_2 & 2) != 0)
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
  int stage_v_127_1 = (sec_r001847_8_1 ^ pub_r001847_3_1) & 63;
  int stage_v_127_2 = (sec_r001847_8_2 ^ pub_r001847_3_2) & 63;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((stage_v_109_1 & 2) != 0)
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
    if ((stage_v_109_2 & 2) != 0)
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
  int stage_v_128_1 = ((pub_r001847_9_1 * 2) + 44) & 63;
  int stage_v_128_2 = ((pub_r001847_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (stage_v_122_1 ^ pub_r001847_14_1) & 63;
  int stage_v_129_2 = (stage_v_122_2 ^ pub_r001847_14_2) & 63;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((stage_v_126_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  }
  if ((stage_v_129_2 & 1) != 0)
  {
    if ((stage_v_126_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  }
  int stage_v_130_1 = ((pub_r001847_8_1 * 2) + 21) & 63;
  int stage_v_130_2 = ((pub_r001847_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (stage_v_5_1 ^ pub_r001847_1_1) & 63;
  int stage_v_131_2 = (stage_v_5_2 ^ pub_r001847_1_2) & 63;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_132_1 = (stage_v_17_1 ^ pub_r001847_2_1) & 63;
  int stage_v_132_2 = (stage_v_17_2 ^ pub_r001847_2_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((stage_v_15_1 & 2) != 0)
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
    if ((stage_v_15_2 & 2) != 0)
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
  int stage_v_133_1 = ((pub_r001847_8_1 * 2) + 12) & 63;
  int stage_v_133_2 = ((pub_r001847_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = (stage_v_6_1 ^ pub_r001847_1_1) & 63;
  int stage_v_134_2 = (stage_v_6_2 ^ pub_r001847_1_2) & 63;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
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
    if ((stage_v_34_2 & 2) != 0)
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
  int stage_v_135_1 = ((pub_r001847_1_1 * 2) + 10) & 63;
  int stage_v_135_2 = ((pub_r001847_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001847_8_1 * 2) + 8) & 63;
  int stage_v_136_2 = ((pub_r001847_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (helper_flow_5_1 ^ pub_r001847_8_1) & 63;
  int stage_v_137_2 = (helper_flow_5_2 ^ pub_r001847_8_2) & 63;
  if ((stage_v_137_1 & 1) != 0)
  {
    if ((stage_v_55_1 & 2) != 0)
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
    if ((stage_v_55_2 & 2) != 0)
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
  int stage_v_138_1 = (stage_v_44_1 ^ pub_r001847_3_1) & 63;
  int stage_v_138_2 = (stage_v_44_2 ^ pub_r001847_3_2) & 63;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((stage_v_70_1 & 2) != 0)
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
    if ((stage_v_70_2 & 2) != 0)
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
  int stage_v_139_1 = (stage_v_15_1 ^ pub_r001847_9_1) & 63;
  int stage_v_139_2 = (stage_v_15_2 ^ pub_r001847_9_2) & 63;
  if ((stage_v_139_1 & 1) != 0)
  {
    if ((stage_v_118_1 & 2) != 0)
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
    if ((stage_v_118_2 & 2) != 0)
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
  int stage_v_140_1 = (helper_flow_0_1 ^ pub_r001847_6_1) & 63;
  int stage_v_140_2 = (helper_flow_0_2 ^ pub_r001847_6_2) & 63;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((stage_v_66_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  }
  if ((stage_v_140_2 & 1) != 0)
  {
    if ((stage_v_66_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  }
  int stage_v_141_1 = (stage_v_92_1 ^ pub_r001847_7_1) & 63;
  int stage_v_141_2 = (stage_v_92_2 ^ pub_r001847_7_2) & 63;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((stage_v_17_1 & 2) != 0)
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
    if ((stage_v_17_2 & 2) != 0)
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
  int stage_v_142_1 = (stage_v_21_1 ^ pub_r001847_15_1) & 63;
  int stage_v_142_2 = (stage_v_21_2 ^ pub_r001847_15_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
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
    if ((stage_v_34_2 & 2) != 0)
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
  int stage_v_143_1 = (sec_r001847_6_1 ^ pub_r001847_6_1) & 63;
  int stage_v_143_2 = (sec_r001847_6_2 ^ pub_r001847_6_2) & 63;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((stage_v_57_1 & 2) != 0)
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
    if ((stage_v_57_2 & 2) != 0)
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
  int stage_v_144_1 = (stage_v_30_1 ^ pub_r001847_12_1) & 63;
  int stage_v_144_2 = (stage_v_30_2 ^ pub_r001847_12_2) & 63;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((sec_r001847_2_1 & 2) != 0)
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
    if ((sec_r001847_2_2 & 2) != 0)
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
  int stage_v_145_1 = (stage_v_123_1 ^ pub_r001847_4_1) & 63;
  int stage_v_145_2 = (stage_v_123_2 ^ pub_r001847_4_2) & 63;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((stage_v_0_1 & 2) != 0)
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
    if ((stage_v_0_2 & 2) != 0)
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
  int stage_v_146_1 = ((pub_r001847_5_1 * 2) + 17) & 63;
  int stage_v_146_2 = ((pub_r001847_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (stage_v_3_1 ^ pub_r001847_3_1) & 63;
  int stage_v_147_2 = (stage_v_3_2 ^ pub_r001847_3_2) & 63;
  if ((stage_v_147_1 & 1) != 0)
  {
    if ((stage_v_145_1 & 2) != 0)
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
    if ((stage_v_145_2 & 2) != 0)
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
  int stage_v_148_1 = ((pub_r001847_14_1 * 2) + 31) & 63;
  int stage_v_148_2 = ((pub_r001847_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (stage_v_108_1 ^ pub_r001847_8_1) & 63;
  int stage_v_149_2 = (stage_v_108_2 ^ pub_r001847_8_2) & 63;
  if ((stage_v_149_1 & 1) != 0)
  {
    if ((stage_v_85_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  }
  if ((stage_v_149_2 & 1) != 0)
  {
    if ((stage_v_85_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  }
  int stage_v_150_1 = ((pub_r001847_9_1 * 2) + 35) & 63;
  int stage_v_150_2 = ((pub_r001847_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001847_9_1 * 2) + 39) & 63;
  int stage_v_151_2 = ((pub_r001847_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001847_11_1 * 2) + 10) & 63;
  int stage_v_152_2 = ((pub_r001847_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001847_8_1 * 2) + 31) & 63;
  int stage_v_153_2 = ((pub_r001847_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (stage_v_6_1 ^ pub_r001847_15_1) & 63;
  int stage_v_154_2 = (stage_v_6_2 ^ pub_r001847_15_2) & 63;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((stage_v_127_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_154_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  }
  if ((stage_v_154_2 & 1) != 0)
  {
    if ((stage_v_127_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_154_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  }
  int stage_v_155_1 = (stage_v_8_1 ^ pub_r001847_3_1) & 63;
  int stage_v_155_2 = (stage_v_8_2 ^ pub_r001847_3_2) & 63;
  if ((stage_v_155_1 & 1) != 0)
  {
    if ((stage_v_110_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_155_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  }
  if ((stage_v_155_2 & 1) != 0)
  {
    if ((stage_v_110_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_155_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  }
  int stage_v_156_1 = ((pub_r001847_15_1 * 2) + 37) & 63;
  int stage_v_156_2 = ((pub_r001847_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = (stage_v_111_1 ^ pub_r001847_6_1) & 63;
  int stage_v_157_2 = (stage_v_111_2 ^ pub_r001847_6_2) & 63;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((stage_v_88_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  }
  if ((stage_v_157_2 & 1) != 0)
  {
    if ((stage_v_88_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  }
  int stage_v_158_1 = ((pub_r001847_9_1 * 2) + 50) & 63;
  int stage_v_158_2 = ((pub_r001847_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001847_10_1 * 2) + 12) & 63;
  int stage_v_159_2 = ((pub_r001847_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (stage_v_43_1 ^ pub_r001847_14_1) & 63;
  int stage_v_160_2 = (stage_v_43_2 ^ pub_r001847_14_2) & 63;
  if ((stage_v_160_1 & 1) != 0)
  {
    if ((stage_v_41_1 & 2) != 0)
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
    if ((stage_v_41_2 & 2) != 0)
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
  int stage_v_161_1 = (stage_v_29_1 ^ pub_r001847_13_1) & 63;
  int stage_v_161_2 = (stage_v_29_2 ^ pub_r001847_13_2) & 63;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((stage_v_119_1 & 2) != 0)
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
    if ((stage_v_119_2 & 2) != 0)
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
  int stage_v_162_1 = (stage_v_45_1 ^ pub_r001847_2_1) & 63;
  int stage_v_162_2 = (stage_v_45_2 ^ pub_r001847_2_2) & 63;
  if ((stage_v_162_1 & 1) != 0)
  {
    if ((stage_v_99_1 & 2) != 0)
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
    if ((stage_v_99_2 & 2) != 0)
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
  int stage_v_163_1 = (stage_v_31_1 ^ pub_r001847_8_1) & 63;
  int stage_v_163_2 = (stage_v_31_2 ^ pub_r001847_8_2) & 63;
  if ((stage_v_163_1 & 1) != 0)
  {
    if ((stage_v_98_1 & 2) != 0)
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
    if ((stage_v_98_2 & 2) != 0)
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
  int stage_v_164_1 = (stage_v_36_1 ^ pub_r001847_1_1) & 63;
  int stage_v_164_2 = (stage_v_36_2 ^ pub_r001847_1_2) & 63;
  if ((stage_v_164_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
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
    if ((stage_v_38_2 & 2) != 0)
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
  int stage_v_165_1 = (stage_v_15_1 ^ pub_r001847_10_1) & 63;
  int stage_v_165_2 = (stage_v_15_2 ^ pub_r001847_10_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((stage_v_39_1 & 2) != 0)
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
    if ((stage_v_39_2 & 2) != 0)
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
  int stage_v_166_1 = ((pub_r001847_7_1 * 2) + 41) & 63;
  int stage_v_166_2 = ((pub_r001847_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (stage_v_124_1 ^ pub_r001847_3_1) & 63;
  int stage_v_167_2 = (stage_v_124_2 ^ pub_r001847_3_2) & 63;
  if ((stage_v_167_1 & 1) != 0)
  {
    if ((stage_v_63_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_167_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  }
  if ((stage_v_167_2 & 1) != 0)
  {
    if ((stage_v_63_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_167_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  }
  int stage_v_168_1 = (stage_v_32_1 ^ pub_r001847_0_1) & 63;
  int stage_v_168_2 = (stage_v_32_2 ^ pub_r001847_0_2) & 63;
  if ((stage_v_168_1 & 1) != 0)
  {
    if ((stage_v_75_1 & 2) != 0)
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
    if ((stage_v_75_2 & 2) != 0)
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
  int stage_v_169_1 = (sec_r001847_7_1 ^ pub_r001847_13_1) & 63;
  int stage_v_169_2 = (sec_r001847_7_2 ^ pub_r001847_13_2) & 63;
  if ((stage_v_169_1 & 1) != 0)
  {
    if ((stage_v_142_1 & 2) != 0)
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
    if ((stage_v_142_2 & 2) != 0)
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
  int stage_v_170_1 = (stage_v_142_1 ^ pub_r001847_0_1) & 63;
  int stage_v_170_2 = (stage_v_142_2 ^ pub_r001847_0_2) & 63;
  if ((stage_v_170_1 & 1) != 0)
  {
    if ((stage_v_147_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_170_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  }
  if ((stage_v_170_2 & 1) != 0)
  {
    if ((stage_v_147_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_170_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  }
  int stage_v_171_1 = (stage_v_20_1 ^ pub_r001847_15_1) & 63;
  int stage_v_171_2 = (stage_v_20_2 ^ pub_r001847_15_2) & 63;
  if ((stage_v_171_1 & 1) != 0)
  {
    if ((stage_v_9_1 & 2) != 0)
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
    if ((stage_v_9_2 & 2) != 0)
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
  int stage_v_172_1 = ((pub_r001847_12_1 * 2) + 9) & 63;
  int stage_v_172_2 = ((pub_r001847_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (sec_r001847_8_1 ^ pub_r001847_3_1) & 63;
  int stage_v_173_2 = (sec_r001847_8_2 ^ pub_r001847_3_2) & 63;
  if ((stage_v_173_1 & 1) != 0)
  {
    if ((helper_flow_10_1 & 2) != 0)
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
    if ((helper_flow_10_2 & 2) != 0)
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
  int stage_v_174_1 = ((pub_r001847_10_1 * 2) + 36) & 63;
  int stage_v_174_2 = ((pub_r001847_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (sec_r001847_6_1 ^ pub_r001847_14_1) & 63;
  int stage_v_175_2 = (sec_r001847_6_2 ^ pub_r001847_14_2) & 63;
  if ((stage_v_175_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
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
    if ((helper_flow_3_2 & 2) != 0)
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
  int stage_v_176_1 = ((pub_r001847_12_1 * 2) + 49) & 63;
  int stage_v_176_2 = ((pub_r001847_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001847_14_1 * 2) + 50) & 63;
  int stage_v_177_2 = ((pub_r001847_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (stage_v_129_1 ^ pub_r001847_12_1) & 63;
  int stage_v_178_2 = (stage_v_129_2 ^ pub_r001847_12_2) & 63;
  if ((stage_v_178_1 & 1) != 0)
  {
    if ((stage_v_157_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_178_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  }
  if ((stage_v_178_2 & 1) != 0)
  {
    if ((stage_v_157_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_178_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  }
  int stage_v_179_1 = (stage_v_5_1 ^ pub_r001847_8_1) & 63;
  int stage_v_179_2 = (stage_v_5_2 ^ pub_r001847_8_2) & 63;
  if ((stage_v_179_1 & 1) != 0)
  {
    if ((stage_v_111_1 & 2) != 0)
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
    if ((stage_v_111_2 & 2) != 0)
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
  int stage_v_180_1 = (sec_r001847_0_1 ^ pub_r001847_13_1) & 63;
  int stage_v_180_2 = (sec_r001847_0_2 ^ pub_r001847_13_2) & 63;
  if ((stage_v_180_1 & 1) != 0)
  {
    if ((stage_v_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_180_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  }
  if ((stage_v_180_2 & 1) != 0)
  {
    if ((stage_v_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_180_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  }
  int stage_v_181_1 = ((pub_r001847_5_1 * 2) + 7) & 63;
  int stage_v_181_2 = ((pub_r001847_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (stage_v_178_1 ^ pub_r001847_4_1) & 63;
  int stage_v_182_2 = (stage_v_178_2 ^ pub_r001847_4_2) & 63;
  if ((stage_v_182_1 & 1) != 0)
  {
    if ((stage_v_161_1 & 2) != 0)
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
    if ((stage_v_161_2 & 2) != 0)
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
  int stage_v_183_1 = (stage_v_131_1 ^ pub_r001847_7_1) & 63;
  int stage_v_183_2 = (stage_v_131_2 ^ pub_r001847_7_2) & 63;
  if ((stage_v_183_1 & 1) != 0)
  {
    if ((stage_v_84_1 & 2) != 0)
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
    if ((stage_v_84_2 & 2) != 0)
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
  int stage_v_184_1 = ((pub_r001847_5_1 * 2) + 35) & 63;
  int stage_v_184_2 = ((pub_r001847_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (stage_v_179_1 ^ pub_r001847_4_1) & 63;
  int stage_v_185_2 = (stage_v_179_2 ^ pub_r001847_4_2) & 63;
  if ((stage_v_185_1 & 1) != 0)
  {
    if ((stage_v_121_1 & 2) != 0)
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
    if ((stage_v_121_2 & 2) != 0)
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
  int stage_v_186_1 = (sec_r001847_4_1 ^ pub_r001847_12_1) & 63;
  int stage_v_186_2 = (sec_r001847_4_2 ^ pub_r001847_12_2) & 63;
  if ((stage_v_186_1 & 1) != 0)
  {
    if ((stage_v_55_1 & 2) != 0)
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
    if ((stage_v_55_2 & 2) != 0)
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
  int stage_v_187_1 = (stage_v_154_1 ^ pub_r001847_4_1) & 63;
  int stage_v_187_2 = (stage_v_154_2 ^ pub_r001847_4_2) & 63;
  if ((stage_v_187_1 & 1) != 0)
  {
    if ((stage_v_0_1 & 2) != 0)
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
    if ((stage_v_0_2 & 2) != 0)
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
  int stage_v_188_1 = (stage_v_157_1 ^ pub_r001847_7_1) & 63;
  int stage_v_188_2 = (stage_v_157_2 ^ pub_r001847_7_2) & 63;
  if ((stage_v_188_1 & 1) != 0)
  {
    if ((stage_v_92_1 & 2) != 0)
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
    if ((stage_v_92_2 & 2) != 0)
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
  int stage_v_189_1 = (stage_v_161_1 ^ pub_r001847_14_1) & 63;
  int stage_v_189_2 = (stage_v_161_2 ^ pub_r001847_14_2) & 63;
  if ((stage_v_189_1 & 1) != 0)
  {
    if ((stage_v_155_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_189_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  }
  if ((stage_v_189_2 & 1) != 0)
  {
    if ((stage_v_155_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_189_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  }
  int stage_v_190_1 = (stage_v_41_1 ^ pub_r001847_0_1) & 63;
  int stage_v_190_2 = (stage_v_41_2 ^ pub_r001847_0_2) & 63;
  if ((stage_v_190_1 & 1) != 0)
  {
    if ((stage_v_0_1 & 2) != 0)
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
    if ((stage_v_0_2 & 2) != 0)
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
  int stage_v_191_1 = (stage_v_178_1 ^ pub_r001847_0_1) & 63;
  int stage_v_191_2 = (stage_v_178_2 ^ pub_r001847_0_2) & 63;
  if ((stage_v_191_1 & 1) != 0)
  {
    if ((stage_v_103_1 & 2) != 0)
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
    if ((stage_v_103_2 & 2) != 0)
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
  int stage_v_192_1 = (sec_r001847_11_1 ^ pub_r001847_14_1) & 63;
  int stage_v_192_2 = (sec_r001847_11_2 ^ pub_r001847_14_2) & 63;
  if ((stage_v_192_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_192_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  }
  if ((stage_v_192_2 & 1) != 0)
  {
    if ((stage_v_38_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_192_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  }
  int stage_v_193_1 = (stage_v_183_1 ^ pub_r001847_6_1) & 63;
  int stage_v_193_2 = (stage_v_183_2 ^ pub_r001847_6_2) & 63;
  if ((stage_v_193_1 & 1) != 0)
  {
    if ((sec_r001847_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_193_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  }
  if ((stage_v_193_2 & 1) != 0)
  {
    if ((sec_r001847_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_193_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  }
  int stage_v_194_1 = ((pub_r001847_11_1 * 2) + 32) & 63;
  int stage_v_194_2 = ((pub_r001847_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (stage_v_193_1 ^ pub_r001847_14_1) & 63;
  int stage_v_195_2 = (stage_v_193_2 ^ pub_r001847_14_2) & 63;
  if ((stage_v_195_1 & 1) != 0)
  {
    if ((stage_v_31_1 & 2) != 0)
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
    if ((stage_v_31_2 & 2) != 0)
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
  int stage_v_196_1 = ((pub_r001847_15_1 * 2) + 49) & 63;
  int stage_v_196_2 = ((pub_r001847_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001847_11_1 * 2) + 37) & 63;
  int stage_v_197_2 = ((pub_r001847_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (stage_v_4_1 ^ pub_r001847_3_1) & 63;
  int stage_v_198_2 = (stage_v_4_2 ^ pub_r001847_3_2) & 63;
  if ((stage_v_198_1 & 1) != 0)
  {
    if ((stage_v_161_1 & 2) != 0)
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
    if ((stage_v_161_2 & 2) != 0)
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
  int stage_v_199_1 = (stage_v_55_1 ^ pub_r001847_10_1) & 63;
  int stage_v_199_2 = (stage_v_55_2 ^ pub_r001847_10_2) & 63;
  if ((stage_v_199_1 & 1) != 0)
  {
    if ((stage_v_57_1 & 2) != 0)
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
    if ((stage_v_57_2 & 2) != 0)
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
  int stage_v_200_1 = (stage_v_21_1 ^ pub_r001847_8_1) & 63;
  int stage_v_200_2 = (stage_v_21_2 ^ pub_r001847_8_2) & 63;
  if ((stage_v_200_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
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
    if ((stage_v_10_2 & 2) != 0)
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
  int stage_v_201_1 = (stage_v_17_1 ^ pub_r001847_6_1) & 63;
  int stage_v_201_2 = (stage_v_17_2 ^ pub_r001847_6_2) & 63;
  if ((stage_v_201_1 & 1) != 0)
  {
    if ((sec_r001847_3_1 & 2) != 0)
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
    if ((sec_r001847_3_2 & 2) != 0)
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
  int stage_v_202_1 = (helper_flow_1_1 ^ pub_r001847_15_1) & 63;
  int stage_v_202_2 = (helper_flow_1_2 ^ pub_r001847_15_2) & 63;
  if ((stage_v_202_1 & 1) != 0)
  {
    if ((sec_r001847_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_202_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_202_1 * 2)) & 255;
  }
  if ((stage_v_202_2 & 1) != 0)
  {
    if ((sec_r001847_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_202_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_202_2 * 2)) & 255;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001847_8_1 == pub_r001847_8_2);
  __CPROVER_assume(pub_r001847_2_1 == pub_r001847_2_2);
  __CPROVER_assume(sec_r001847_4_1 != sec_r001847_4_2);
  __CPROVER_assume(pub_r001847_0_1 == pub_r001847_0_2);
  __CPROVER_assume(pub_r001847_11_1 == pub_r001847_11_2);
  __CPROVER_assume(sec_r001847_1_1 != sec_r001847_1_2);
  __CPROVER_assume(sec_r001847_10_1 != sec_r001847_10_2);
  __CPROVER_assume(sec_r001847_7_1 != sec_r001847_7_2);
  __CPROVER_assume(sec_r001847_5_1 != sec_r001847_5_2);
  __CPROVER_assume(sec_r001847_12_1 != sec_r001847_12_2);
  __CPROVER_assume(sec_r001847_14_1 != sec_r001847_14_2);
  __CPROVER_assume(pub_r001847_5_1 == pub_r001847_5_2);
  __CPROVER_assume(pub_r001847_15_1 == pub_r001847_15_2);
  __CPROVER_assume(pub_r001847_1_1 == pub_r001847_1_2);
  __CPROVER_assume(pub_r001847_3_1 == pub_r001847_3_2);
  __CPROVER_assume(sec_r001847_0_1 != sec_r001847_0_2);
  __CPROVER_assume(sec_r001847_8_1 != sec_r001847_8_2);
  __CPROVER_assume(sec_r001847_13_1 != sec_r001847_13_2);
  __CPROVER_assume(pub_r001847_12_1 == pub_r001847_12_2);
  __CPROVER_assume(pub_r001847_14_1 == pub_r001847_14_2);
  __CPROVER_assume(pub_r001847_13_1 == pub_r001847_13_2);
  __CPROVER_assume(sec_r001847_6_1 != sec_r001847_6_2);
  __CPROVER_assume(pub_r001847_4_1 == pub_r001847_4_2);
  __CPROVER_assume(pub_r001847_9_1 == pub_r001847_9_2);
  __CPROVER_assume(sec_r001847_11_1 != sec_r001847_11_2);
  __CPROVER_assume(sec_r001847_2_1 != sec_r001847_2_2);
  __CPROVER_assume(sec_r001847_15_1 != sec_r001847_15_2);
  __CPROVER_assume(pub_r001847_10_1 == pub_r001847_10_2);
  __CPROVER_assume(sec_r001847_9_1 != sec_r001847_9_2);
  __CPROVER_assume(pub_r001847_6_1 == pub_r001847_6_2);
  __CPROVER_assume(pub_r001847_7_1 == pub_r001847_7_2);
  __CPROVER_assume(sec_r001847_3_1 != sec_r001847_3_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.balance == st_var_1_2.balance);
  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  assert(st_var_1_1.rate == st_var_1_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.watermark == st_var_2_2.watermark);
  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.state == st_var_2_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
  assert(st_var_3_1.signature == st_var_3_2.signature);
  assert(st_var_3_1.severity == st_var_3_2.severity);
  assert(st_var_3_1.code == st_var_3_2.code);
  assert(st_var_3_1.facility == st_var_3_2.facility);
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
}


