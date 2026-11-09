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
struct SensorNode_R001696_9613_0
{
  int status;
  unsigned char reading;
  int threshold;
  short calib;
  short gain;
  int offset;
  int buffer[3];
};
struct Transaction_R001696_9613_1
{
  int balance;
  short account_id;
  short rate;
  int auth_code;
  unsigned char status;
  int buffer[3];
};
struct FilterState_R001696_9613_2
{
  int mode;
  unsigned char prev_in;
  int prev_out;
  int cutoff;
  int damping;
  short gain_db;
  int buffer[3];
};
union PacketPayload_R001696_9613_0
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
void fn_R001696_9613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001696_9613_1 st_1 = {0};
  struct Transaction_R001696_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int vector_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_10_1 > 12)
  {
    acc_1 = ((acc_1 + (vector_10_1 * 2)) + 5) & 127;
    aux_1 ^= vector_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_10_2 > 12)
  {
    acc_2 = ((acc_2 + (vector_10_2 * 2)) + 5) & 127;
    aux_2 ^= vector_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_26_1 = 0;
  int tracker_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_26_1 = ((tracker_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_26_2 = ((tracker_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_26_1) & 127;
    acc_2 = (acc_2 + tracker_26_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_10_1 == vector_10_2);
  assert(tracker_26_1 == tracker_26_2);
}

int fn_R001696_9613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001696_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int vector_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_10 > 12)
  {
    acc = ((acc + (vector_10 * 2)) + 5) & 127;
    aux ^= vector_10 & 15;
  }
  else
  {
    acc = ((acc - vector_10) + 11) & 127;
    aux += 3;
  }
  int tracker_26 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_26 = ((tracker_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_26) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001696_9613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001696_9613_2 st_1 = {0};
  struct FilterState_R001696_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_29_1 = local_arr_1[aux_1 % 3];
  int tally_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_29_2 * 2)) & 127;
  int factor_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_24_1) & 63;
  aux_2 = (aux_2 + factor_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_42_1 > 41)
  {
    acc_1 = ((acc_1 + (tracker_42_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_42_2 > 41)
  {
    acc_2 = ((acc_2 + (tracker_42_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_42_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_85_1 = 0;
  int accumulator_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_85_1 = ((accumulator_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_85_2 = ((accumulator_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_85_1) & 127;
    acc_2 = (acc_2 + accumulator_85_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_29_1 == tally_29_2);
  assert(factor_24_1 == factor_24_2);
  assert(tracker_42_1 == tracker_42_2);
  assert(accumulator_85_1 == accumulator_85_2);
}

int fn_R001696_9613_1(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001696_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int tally_29 = local_arr[aux % 3];
  acc = (acc + (tally_29 * 2)) & 127;
  int factor_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_24) & 63;
  acc ^= aux;
  int tracker_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_42 > 41)
  {
    acc = ((acc + (tracker_42 * 2)) + 5) & 127;
    aux ^= tracker_42 & 15;
  }
  else
  {
    acc = ((acc - tracker_42) + 11) & 127;
    aux += 3;
  }
  int accumulator_85 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_85 = ((accumulator_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_85) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001696_9613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001696_9613_2 st_1 = {0};
  struct FilterState_R001696_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int mask_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_11_1 > 30)
  {
    acc_1 = ((acc_1 + (mask_11_1 * 2)) + 5) & 127;
    aux_1 ^= mask_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_11_2 > 30)
  {
    acc_2 = ((acc_2 + (mask_11_2 * 2)) + 5) & 127;
    aux_2 ^= mask_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_39_1 = local_arr_1[aux_1 % 3];
  int parity_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_39_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_11_1 == mask_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_39_1 == parity_39_2);
}

int fn_R001696_9613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001696_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int mask_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_11 > 30)
  {
    acc = ((acc + (mask_11 * 2)) + 5) & 127;
    aux ^= mask_11 & 15;
  }
  else
  {
    acc = ((acc - mask_11) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_39 = local_arr[aux % 3];
  acc = (acc + (parity_39 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001696_9613_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001696_9613_2 st_1 = {0};
  struct FilterState_R001696_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int anchor_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_99_1 > 46)
  {
    acc_1 = ((acc_1 + (anchor_99_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_99_2 > 46)
  {
    acc_2 = ((acc_2 + (anchor_99_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_18_1 = local_arr_1[aux_1 % 3];
  int quotient_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_18_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_99_1 == anchor_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_18_1 == quotient_18_2);
}

int fn_R001696_9613_3(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001696_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int anchor_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_99 > 46)
  {
    acc = ((acc + (anchor_99 * 2)) + 5) & 127;
    aux ^= anchor_99 & 15;
  }
  else
  {
    acc = ((acc - anchor_99) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_18 = local_arr[aux % 3];
  acc = (acc + (quotient_18 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001696_9613_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001696_9613_2 st_1 = {0};
  struct FilterState_R001696_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_18_1) & 63;
  aux_2 = (aux_2 + pivot_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_18_1 == pivot_18_2);
}

int fn_R001696_9613_4(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001696_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_18) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001696_9613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001696_9613_2 st_1 = {0};
  struct FilterState_R001696_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int threshold_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_69_1)
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

  switch (threshold_69_2)
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

  int delta_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_12_1) & 63;
  aux_2 = (aux_2 + delta_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_64_1 = 0;
  int quotient_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_64_1 = ((quotient_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_64_2 = ((quotient_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_64_1) & 127;
    acc_2 = (acc_2 + quotient_64_2) & 127;
  }

  int delta_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_94_1 > 10)
  {
    acc_1 = ((acc_1 + (delta_94_1 * 2)) + 5) & 127;
    aux_1 ^= delta_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_94_2 > 10)
  {
    acc_2 = ((acc_2 + (delta_94_2 * 2)) + 5) & 127;
    aux_2 ^= delta_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_94_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_69_1 == threshold_69_2);
  assert(delta_12_1 == delta_12_2);
  assert(quotient_64_1 == quotient_64_2);
  assert(delta_94_1 == delta_94_2);
}

int fn_R001696_9613_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001696_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int threshold_69 = (aux + st.buffer[1]) & 3;
  switch (threshold_69)
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

  int delta_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_12) & 63;
  acc ^= aux;
  int quotient_64 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_64 = ((quotient_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_64) & 127;
  }

  int delta_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_94 > 10)
  {
    acc = ((acc + (delta_94 * 2)) + 5) & 127;
    aux ^= delta_94 & 15;
  }
  else
  {
    acc = ((acc - delta_94) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001696_9613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001696_9613_0 st_1 = {0};
  struct SensorNode_R001696_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int window_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_64_1 > 17)
  {
    acc_1 = ((acc_1 + (window_64_1 * 2)) + 5) & 127;
    aux_1 ^= window_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_64_2 > 17)
  {
    acc_2 = ((acc_2 + (window_64_2 * 2)) + 5) & 127;
    aux_2 ^= window_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_64_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_87_1)
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

  switch (parity_87_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_64_1 == window_64_2);
  assert(parity_87_1 == parity_87_2);
}

int fn_R001696_9613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001696_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int window_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_64 > 17)
  {
    acc = ((acc + (window_64 * 2)) + 5) & 127;
    aux ^= window_64 & 15;
  }
  else
  {
    acc = ((acc - window_64) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_87 = (aux + st.buffer[1]) & 3;
  switch (parity_87)
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

void fn_R001696_9613_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001696_9613_0 st_1 = {0};
  struct SensorNode_R001696_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_59_1) & 63;
  aux_2 = (aux_2 + residue_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_14_1 = 0;
  int mask_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_14_1 = ((mask_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_14_2 = ((mask_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_14_1) & 127;
    acc_2 = (acc_2 + mask_14_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_90_1 = local_arr_1[aux_1 % 3];
  int mask_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_59_1 == residue_59_2);
  assert(mask_14_1 == mask_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_90_1 == mask_90_2);
}

int fn_R001696_9613_7(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001696_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_59) & 63;
  acc ^= aux;
  int mask_14 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_14 = ((mask_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_14) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int mask_90 = local_arr[aux % 3];
  acc = (acc + (mask_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001696_9613_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001696_9613_0 st_1 = {0};
  struct SensorNode_R001696_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int stride_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_82_1) & 63;
  aux_2 = (aux_2 + stride_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_21_1 = 0;
  int stride_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_21_1 = ((stride_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_21_2 = ((stride_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_21_1) & 127;
    acc_2 = (acc_2 + stride_21_2) & 127;
  }

  int margin_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_48_1)
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

  switch (margin_48_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_53_1 = local_arr_1[aux_1 % 3];
  int parity_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_53_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_82_1 == stride_82_2);
  assert(stride_21_1 == stride_21_2);
  assert(margin_48_1 == margin_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_53_1 == parity_53_2);
}

int fn_R001696_9613_8(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001696_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int stride_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_82) & 63;
  acc ^= aux;
  int stride_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_21 = ((stride_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_21) & 127;
  }

  int margin_48 = (aux + st.buffer[1]) & 3;
  switch (margin_48)
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

  int local_arr[3] = {4, 9, 15};
  int parity_53 = local_arr[aux % 3];
  acc = (acc + (parity_53 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001696_9613_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001696_9613_2 st_1 = {0};
  struct FilterState_R001696_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_95_1 = local_arr_1[aux_1 % 3];
  int quantum_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_95_2 * 2)) & 127;
  int index_reg_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_33_1)
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

  switch (index_reg_33_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_95_1 == quantum_95_2);
  assert(index_reg_33_1 == index_reg_33_2);
}

int fn_R001696_9613_9(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001696_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int quantum_95 = local_arr[aux % 3];
  acc = (acc + (quantum_95 * 2)) & 127;
  int index_reg_33 = (aux + st.buffer[1]) & 3;
  switch (index_reg_33)
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

void fn_R001696_9613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001696_9613_0 st_1 = {0};
  struct SensorNode_R001696_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_17_1 = local_arr_1[aux_1 % 3];
  int tracker_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_17_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_17_1 == tracker_17_2);
}

int fn_R001696_9613_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001696_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int tracker_17 = local_arr[aux % 3];
  acc = (acc + (tracker_17 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001696_9613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001696_9613_0 st_1 = {0};
  struct SensorNode_R001696_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_77_1 = local_arr_1[aux_1 % 3];
  int phase_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_77_2 * 2)) & 127;
  int tally_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_27_1 > 21)
  {
    acc_1 = ((acc_1 + (tally_27_1 * 2)) + 5) & 127;
    aux_1 ^= tally_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_27_2 > 21)
  {
    acc_2 = ((acc_2 + (tally_27_2 * 2)) + 5) & 127;
    aux_2 ^= tally_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_27_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_77_1 == phase_77_2);
  assert(tally_27_1 == tally_27_2);
}

int fn_R001696_9613_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001696_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int phase_77 = local_arr[aux % 3];
  acc = (acc + (phase_77 * 2)) & 127;
  int tally_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_27 > 21)
  {
    acc = ((acc + (tally_27 * 2)) + 5) & 127;
    aux ^= tally_27 & 15;
  }
  else
  {
    acc = ((acc - tally_27) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001696_9613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001696_9613_0 st_1 = {0};
  struct SensorNode_R001696_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int residue_89_1 = 0;
  int residue_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_89_1 = ((residue_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_89_2 = ((residue_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_89_1) & 127;
    acc_2 = (acc_2 + residue_89_2) & 127;
  }

  int checksum_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_11_1) & 63;
  aux_2 = (aux_2 + checksum_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_95_1 = local_arr_1[aux_1 % 3];
  int tracker_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_89_1 == residue_89_2);
  assert(checksum_11_1 == checksum_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_95_1 == tracker_95_2);
}

int fn_R001696_9613_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001696_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int residue_89 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_89 = ((residue_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_89) & 127;
  }

  int checksum_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_11) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tracker_95 = local_arr[aux % 3];
  acc = (acc + (tracker_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001696_9613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001696_9613_0 st_1 = {0};
  struct SensorNode_R001696_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_38_1 = local_arr_1[aux_1 % 3];
  int margin_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_38_2 * 2)) & 127;
  int anchor_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_87_1) & 63;
  aux_2 = (aux_2 + anchor_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_56_1)
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

  switch (tally_56_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_38_1 == margin_38_2);
  assert(anchor_87_1 == anchor_87_2);
  assert(tally_56_1 == tally_56_2);
}

int fn_R001696_9613_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001696_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int margin_38 = local_arr[aux % 3];
  acc = (acc + (margin_38 * 2)) & 127;
  int anchor_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_87) & 63;
  acc ^= aux;
  int tally_56 = (aux + st.buffer[1]) & 3;
  switch (tally_56)
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

void main()
{
  int sec_r001696_0_1;
  int sec_r001696_0_2;
  int sec_r001696_1_1;
  int sec_r001696_1_2;
  int sec_r001696_2_1;
  int sec_r001696_2_2;
  int sec_r001696_3_1;
  int sec_r001696_3_2;
  int sec_r001696_4_1;
  int sec_r001696_4_2;
  int sec_r001696_5_1;
  int sec_r001696_5_2;
  int sec_r001696_6_1;
  int sec_r001696_6_2;
  int sec_r001696_7_1;
  int sec_r001696_7_2;
  int sec_r001696_8_1;
  int sec_r001696_8_2;
  int sec_r001696_9_1;
  int sec_r001696_9_2;
  int sec_r001696_10_1;
  int sec_r001696_10_2;
  int sec_r001696_11_1;
  int sec_r001696_11_2;
  int sec_r001696_12_1;
  int sec_r001696_12_2;
  int sec_r001696_13_1;
  int sec_r001696_13_2;
  int sec_r001696_14_1;
  int sec_r001696_14_2;
  int sec_r001696_15_1;
  int sec_r001696_15_2;
  int sec_r001696_16_1;
  int sec_r001696_16_2;
  int pub_r001696_0_1;
  int pub_r001696_0_2;
  int pub_r001696_1_1;
  int pub_r001696_1_2;
  int pub_r001696_2_1;
  int pub_r001696_2_2;
  int pub_r001696_3_1;
  int pub_r001696_3_2;
  int pub_r001696_4_1;
  int pub_r001696_4_2;
  int pub_r001696_5_1;
  int pub_r001696_5_2;
  int pub_r001696_6_1;
  int pub_r001696_6_2;
  int pub_r001696_7_1;
  int pub_r001696_7_2;
  int pub_r001696_8_1;
  int pub_r001696_8_2;
  int pub_r001696_9_1;
  int pub_r001696_9_2;
  int pub_r001696_10_1;
  int pub_r001696_10_2;
  int pub_r001696_11_1;
  int pub_r001696_11_2;
  int pub_r001696_12_1;
  int pub_r001696_12_2;
  int pub_r001696_13_1;
  int pub_r001696_13_2;
  int pub_r001696_14_1;
  int pub_r001696_14_2;
  int pub_r001696_15_1;
  int pub_r001696_15_2;
  int pub_r001696_16_1;
  int pub_r001696_16_2;
  int pub_r001696_17_1;
  int pub_r001696_17_2;
  int pub_r001696_18_1;
  int pub_r001696_18_2;
  int pub_r001696_19_1;
  int pub_r001696_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001696_0_1 >= (-100)) && (pub_r001696_0_1 <= 100));
  __CPROVER_assume((pub_r001696_0_2 >= (-100)) && (pub_r001696_0_2 <= 100));
  __CPROVER_assume((pub_r001696_1_1 >= (-100)) && (pub_r001696_1_1 <= 100));
  __CPROVER_assume((pub_r001696_1_2 >= (-100)) && (pub_r001696_1_2 <= 100));
  __CPROVER_assume((pub_r001696_2_1 >= (-100)) && (pub_r001696_2_1 <= 100));
  __CPROVER_assume((pub_r001696_2_2 >= (-100)) && (pub_r001696_2_2 <= 100));
  __CPROVER_assume((pub_r001696_3_1 >= (-100)) && (pub_r001696_3_1 <= 100));
  __CPROVER_assume((pub_r001696_3_2 >= (-100)) && (pub_r001696_3_2 <= 100));
  __CPROVER_assume((pub_r001696_4_1 >= (-100)) && (pub_r001696_4_1 <= 100));
  __CPROVER_assume((pub_r001696_4_2 >= (-100)) && (pub_r001696_4_2 <= 100));
  __CPROVER_assume((pub_r001696_5_1 >= (-100)) && (pub_r001696_5_1 <= 100));
  __CPROVER_assume((pub_r001696_5_2 >= (-100)) && (pub_r001696_5_2 <= 100));
  __CPROVER_assume((pub_r001696_6_1 >= (-100)) && (pub_r001696_6_1 <= 100));
  __CPROVER_assume((pub_r001696_6_2 >= (-100)) && (pub_r001696_6_2 <= 100));
  __CPROVER_assume((pub_r001696_7_1 >= (-100)) && (pub_r001696_7_1 <= 100));
  __CPROVER_assume((pub_r001696_7_2 >= (-100)) && (pub_r001696_7_2 <= 100));
  __CPROVER_assume((pub_r001696_8_1 >= (-100)) && (pub_r001696_8_1 <= 100));
  __CPROVER_assume((pub_r001696_8_2 >= (-100)) && (pub_r001696_8_2 <= 100));
  __CPROVER_assume((pub_r001696_9_1 >= (-100)) && (pub_r001696_9_1 <= 100));
  __CPROVER_assume((pub_r001696_9_2 >= (-100)) && (pub_r001696_9_2 <= 100));
  __CPROVER_assume((pub_r001696_10_1 >= (-100)) && (pub_r001696_10_1 <= 100));
  __CPROVER_assume((pub_r001696_10_2 >= (-100)) && (pub_r001696_10_2 <= 100));
  __CPROVER_assume((pub_r001696_11_1 >= (-100)) && (pub_r001696_11_1 <= 100));
  __CPROVER_assume((pub_r001696_11_2 >= (-100)) && (pub_r001696_11_2 <= 100));
  __CPROVER_assume((pub_r001696_12_1 >= (-100)) && (pub_r001696_12_1 <= 100));
  __CPROVER_assume((pub_r001696_12_2 >= (-100)) && (pub_r001696_12_2 <= 100));
  __CPROVER_assume((pub_r001696_13_1 >= (-100)) && (pub_r001696_13_1 <= 100));
  __CPROVER_assume((pub_r001696_13_2 >= (-100)) && (pub_r001696_13_2 <= 100));
  __CPROVER_assume((pub_r001696_14_1 >= (-100)) && (pub_r001696_14_1 <= 100));
  __CPROVER_assume((pub_r001696_14_2 >= (-100)) && (pub_r001696_14_2 <= 100));
  __CPROVER_assume((pub_r001696_15_1 >= (-100)) && (pub_r001696_15_1 <= 100));
  __CPROVER_assume((pub_r001696_15_2 >= (-100)) && (pub_r001696_15_2 <= 100));
  __CPROVER_assume((pub_r001696_16_1 >= (-100)) && (pub_r001696_16_1 <= 100));
  __CPROVER_assume((pub_r001696_16_2 >= (-100)) && (pub_r001696_16_2 <= 100));
  __CPROVER_assume((pub_r001696_17_1 >= (-100)) && (pub_r001696_17_1 <= 100));
  __CPROVER_assume((pub_r001696_17_2 >= (-100)) && (pub_r001696_17_2 <= 100));
  __CPROVER_assume((pub_r001696_18_1 >= (-100)) && (pub_r001696_18_1 <= 100));
  __CPROVER_assume((pub_r001696_18_2 >= (-100)) && (pub_r001696_18_2 <= 100));
  __CPROVER_assume((pub_r001696_19_1 >= (-100)) && (pub_r001696_19_1 <= 100));
  __CPROVER_assume((pub_r001696_19_2 >= (-100)) && (pub_r001696_19_2 <= 100));
  __CPROVER_assume((sec_r001696_0_1 >= 0) && (sec_r001696_0_1 <= 255));
  __CPROVER_assume((sec_r001696_0_2 >= 0) && (sec_r001696_0_2 <= 255));
  __CPROVER_assume((sec_r001696_1_1 >= 0) && (sec_r001696_1_1 <= 255));
  __CPROVER_assume((sec_r001696_1_2 >= 0) && (sec_r001696_1_2 <= 255));
  __CPROVER_assume((sec_r001696_2_1 >= 0) && (sec_r001696_2_1 <= 255));
  __CPROVER_assume((sec_r001696_2_2 >= 0) && (sec_r001696_2_2 <= 255));
  __CPROVER_assume((sec_r001696_3_1 >= 0) && (sec_r001696_3_1 <= 255));
  __CPROVER_assume((sec_r001696_3_2 >= 0) && (sec_r001696_3_2 <= 255));
  __CPROVER_assume((sec_r001696_4_1 >= 0) && (sec_r001696_4_1 <= 255));
  __CPROVER_assume((sec_r001696_4_2 >= 0) && (sec_r001696_4_2 <= 255));
  __CPROVER_assume((sec_r001696_5_1 >= 0) && (sec_r001696_5_1 <= 255));
  __CPROVER_assume((sec_r001696_5_2 >= 0) && (sec_r001696_5_2 <= 255));
  __CPROVER_assume((sec_r001696_6_1 >= 0) && (sec_r001696_6_1 <= 255));
  __CPROVER_assume((sec_r001696_6_2 >= 0) && (sec_r001696_6_2 <= 255));
  __CPROVER_assume((sec_r001696_7_1 >= 0) && (sec_r001696_7_1 <= 255));
  __CPROVER_assume((sec_r001696_7_2 >= 0) && (sec_r001696_7_2 <= 255));
  __CPROVER_assume((sec_r001696_8_1 >= 0) && (sec_r001696_8_1 <= 255));
  __CPROVER_assume((sec_r001696_8_2 >= 0) && (sec_r001696_8_2 <= 255));
  __CPROVER_assume((sec_r001696_9_1 >= 0) && (sec_r001696_9_1 <= 255));
  __CPROVER_assume((sec_r001696_9_2 >= 0) && (sec_r001696_9_2 <= 255));
  __CPROVER_assume((sec_r001696_10_1 >= 0) && (sec_r001696_10_1 <= 255));
  __CPROVER_assume((sec_r001696_10_2 >= 0) && (sec_r001696_10_2 <= 255));
  __CPROVER_assume((sec_r001696_11_1 >= 0) && (sec_r001696_11_1 <= 255));
  __CPROVER_assume((sec_r001696_11_2 >= 0) && (sec_r001696_11_2 <= 255));
  __CPROVER_assume((sec_r001696_12_1 >= 0) && (sec_r001696_12_1 <= 255));
  __CPROVER_assume((sec_r001696_12_2 >= 0) && (sec_r001696_12_2 <= 255));
  __CPROVER_assume((sec_r001696_13_1 >= 0) && (sec_r001696_13_1 <= 255));
  __CPROVER_assume((sec_r001696_13_2 >= 0) && (sec_r001696_13_2 <= 255));
  __CPROVER_assume((sec_r001696_14_1 >= 0) && (sec_r001696_14_1 <= 255));
  __CPROVER_assume((sec_r001696_14_2 >= 0) && (sec_r001696_14_2 <= 255));
  __CPROVER_assume((sec_r001696_15_1 >= 0) && (sec_r001696_15_1 <= 255));
  __CPROVER_assume((sec_r001696_15_2 >= 0) && (sec_r001696_15_2 <= 255));
  __CPROVER_assume((sec_r001696_16_1 >= 0) && (sec_r001696_16_1 <= 255));
  __CPROVER_assume((sec_r001696_16_2 >= 0) && (sec_r001696_16_2 <= 255));
  struct SensorNode_R001696_9613_0 st_var_0_1 = {0};
  struct SensorNode_R001696_9613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001696_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001696_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001696_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001696_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001696_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001696_0_2 + 7) & 15;
  struct Transaction_R001696_9613_1 st_var_1_1 = {0};
  struct Transaction_R001696_9613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001696_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001696_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001696_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001696_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001696_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001696_0_2 + 9) & 15;
  struct FilterState_R001696_9613_2 st_var_2_1 = {0};
  struct FilterState_R001696_9613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001696_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001696_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001696_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001696_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001696_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001696_0_2 + 11) & 15;
  union PacketPayload_R001696_9613_0 u_var_1;
  union PacketPayload_R001696_9613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001696_9613_0(sec_r001696_0_1, pub_r001696_1_1, pub_r001696_2_1, pub_r001696_3_1);
  int helper_flow_0_2 = fn_R001696_9613_0(sec_r001696_0_2, pub_r001696_1_2, pub_r001696_2_2, pub_r001696_3_2);
  fn_R001696_9613_0_2(sec_r001696_0_1, pub_r001696_1_1, pub_r001696_2_1, pub_r001696_3_1, sec_r001696_0_2, pub_r001696_1_2, pub_r001696_2_2, pub_r001696_3_2);
  int helper_flow_1_1 = fn_R001696_9613_1(sec_r001696_1_1, pub_r001696_2_1);
  int helper_flow_1_2 = fn_R001696_9613_1(sec_r001696_1_2, pub_r001696_2_2);
  fn_R001696_9613_1_2(sec_r001696_1_1, pub_r001696_2_1, sec_r001696_1_2, pub_r001696_2_2);
  int helper_flow_2_1 = fn_R001696_9613_2(sec_r001696_2_1, pub_r001696_3_1, pub_r001696_4_1, pub_r001696_5_1, pub_r001696_6_1);
  int helper_flow_2_2 = fn_R001696_9613_2(sec_r001696_2_2, pub_r001696_3_2, pub_r001696_4_2, pub_r001696_5_2, pub_r001696_6_2);
  fn_R001696_9613_2_2(sec_r001696_2_1, pub_r001696_3_1, pub_r001696_4_1, pub_r001696_5_1, pub_r001696_6_1, sec_r001696_2_2, pub_r001696_3_2, pub_r001696_4_2, pub_r001696_5_2, pub_r001696_6_2);
  int helper_flow_3_1 = fn_R001696_9613_3(sec_r001696_3_1, sec_r001696_4_1);
  int helper_flow_3_2 = fn_R001696_9613_3(sec_r001696_3_2, sec_r001696_4_2);
  fn_R001696_9613_3_2(sec_r001696_3_1, sec_r001696_4_1, sec_r001696_3_2, sec_r001696_4_2);
  int helper_flow_4_1 = fn_R001696_9613_4(sec_r001696_4_1, pub_r001696_5_1, pub_r001696_6_1);
  int helper_flow_4_2 = fn_R001696_9613_4(sec_r001696_4_2, pub_r001696_5_2, pub_r001696_6_2);
  fn_R001696_9613_4_2(sec_r001696_4_1, pub_r001696_5_1, pub_r001696_6_1, sec_r001696_4_2, pub_r001696_5_2, pub_r001696_6_2);
  int helper_flow_5_1 = fn_R001696_9613_5(sec_r001696_5_1, sec_r001696_6_1, pub_r001696_7_1, pub_r001696_8_1, pub_r001696_9_1);
  int helper_flow_5_2 = fn_R001696_9613_5(sec_r001696_5_2, sec_r001696_6_2, pub_r001696_7_2, pub_r001696_8_2, pub_r001696_9_2);
  fn_R001696_9613_5_2(sec_r001696_5_1, sec_r001696_6_1, pub_r001696_7_1, pub_r001696_8_1, pub_r001696_9_1, sec_r001696_5_2, sec_r001696_6_2, pub_r001696_7_2, pub_r001696_8_2, pub_r001696_9_2);
  int helper_flow_6_1 = fn_R001696_9613_6(sec_r001696_6_1, sec_r001696_7_1, pub_r001696_8_1, pub_r001696_9_1, pub_r001696_10_1);
  int helper_flow_6_2 = fn_R001696_9613_6(sec_r001696_6_2, sec_r001696_7_2, pub_r001696_8_2, pub_r001696_9_2, pub_r001696_10_2);
  fn_R001696_9613_6_2(sec_r001696_6_1, sec_r001696_7_1, pub_r001696_8_1, pub_r001696_9_1, pub_r001696_10_1, sec_r001696_6_2, sec_r001696_7_2, pub_r001696_8_2, pub_r001696_9_2, pub_r001696_10_2);
  int stage_v_0_1 = ((sec_r001696_12_1 + (pub_r001696_2_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((sec_r001696_12_2 + (pub_r001696_2_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((pub_r001696_18_1 * 2) + 47) & 63;
  int stage_v_1_2 = ((pub_r001696_18_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((sec_r001696_4_1 + (pub_r001696_14_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((sec_r001696_4_2 + (pub_r001696_14_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((sec_r001696_4_1 + (pub_r001696_16_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001696_4_2 + (pub_r001696_16_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((sec_r001696_10_1 + (pub_r001696_0_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((sec_r001696_10_2 + (pub_r001696_0_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((pub_r001696_16_1 * 2) + 8) & 63;
  int stage_v_5_2 = ((pub_r001696_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((sec_r001696_14_1 + (pub_r001696_3_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001696_14_2 + (pub_r001696_3_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((stage_v_3_1 + (pub_r001696_11_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((stage_v_3_2 + (pub_r001696_11_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((pub_r001696_7_1 * 2) + 22) & 63;
  int stage_v_8_2 = ((pub_r001696_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((stage_v_2_1 + (pub_r001696_4_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((stage_v_2_2 + (pub_r001696_4_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((stage_v_9_1 + (pub_r001696_10_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((stage_v_9_2 + (pub_r001696_10_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((sec_r001696_15_1 + (pub_r001696_14_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((sec_r001696_15_2 + (pub_r001696_14_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((sec_r001696_3_1 + (pub_r001696_7_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001696_3_2 + (pub_r001696_7_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((helper_flow_5_1 + (pub_r001696_4_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((helper_flow_5_2 + (pub_r001696_4_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((sec_r001696_5_1 + (pub_r001696_3_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((sec_r001696_5_2 + (pub_r001696_3_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((stage_v_0_1 + (pub_r001696_4_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((stage_v_0_2 + (pub_r001696_4_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((pub_r001696_17_1 * 2) + 41) & 63;
  int stage_v_16_2 = ((pub_r001696_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((sec_r001696_16_1 + (pub_r001696_2_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001696_16_2 + (pub_r001696_2_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((helper_flow_5_1 + (pub_r001696_5_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((helper_flow_5_2 + (pub_r001696_5_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((pub_r001696_16_1 * 2) + 28) & 63;
  int stage_v_19_2 = ((pub_r001696_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((sec_r001696_7_1 + (pub_r001696_15_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((sec_r001696_7_2 + (pub_r001696_15_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((pub_r001696_10_1 * 2) + 13) & 63;
  int stage_v_21_2 = ((pub_r001696_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((stage_v_15_1 + (pub_r001696_1_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((stage_v_15_2 + (pub_r001696_1_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((pub_r001696_18_1 * 2) + 36) & 63;
  int stage_v_23_2 = ((pub_r001696_18_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((stage_v_7_1 + (pub_r001696_0_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((stage_v_7_2 + (pub_r001696_0_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((pub_r001696_2_1 * 2) + 31) & 63;
  int stage_v_25_2 = ((pub_r001696_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((sec_r001696_16_1 + (pub_r001696_0_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((sec_r001696_16_2 + (pub_r001696_0_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((sec_r001696_12_1 + (pub_r001696_15_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((sec_r001696_12_2 + (pub_r001696_15_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((pub_r001696_12_1 * 2) + 27) & 63;
  int stage_v_28_2 = ((pub_r001696_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((sec_r001696_9_1 + (pub_r001696_4_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001696_9_2 + (pub_r001696_4_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((stage_v_0_1 + (pub_r001696_4_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((stage_v_0_2 + (pub_r001696_4_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((stage_v_20_1 + (pub_r001696_3_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((stage_v_20_2 + (pub_r001696_3_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((pub_r001696_16_1 * 2) + 24) & 63;
  int stage_v_32_2 = ((pub_r001696_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((helper_flow_1_1 + (pub_r001696_1_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((helper_flow_1_2 + (pub_r001696_1_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((sec_r001696_5_1 + (pub_r001696_8_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((sec_r001696_5_2 + (pub_r001696_8_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((helper_flow_4_1 + (pub_r001696_0_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((helper_flow_4_2 + (pub_r001696_0_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((sec_r001696_2_1 + (pub_r001696_3_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((sec_r001696_2_2 + (pub_r001696_3_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((pub_r001696_0_1 * 2) + 10) & 63;
  int stage_v_37_2 = ((pub_r001696_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((sec_r001696_12_1 + (pub_r001696_11_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((sec_r001696_12_2 + (pub_r001696_11_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((pub_r001696_1_1 * 2) + 50) & 63;
  int stage_v_39_2 = ((pub_r001696_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((stage_v_2_1 + (pub_r001696_8_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_2_2 + (pub_r001696_8_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((pub_r001696_1_1 * 2) + 46) & 63;
  int stage_v_41_2 = ((pub_r001696_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((sec_r001696_6_1 + (pub_r001696_3_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((sec_r001696_6_2 + (pub_r001696_3_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((pub_r001696_16_1 * 2) + 40) & 63;
  int stage_v_43_2 = ((pub_r001696_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((helper_flow_0_1 + (pub_r001696_7_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((helper_flow_0_2 + (pub_r001696_7_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((sec_r001696_12_1 + (pub_r001696_14_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((sec_r001696_12_2 + (pub_r001696_14_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((pub_r001696_18_1 * 2) + 38) & 63;
  int stage_v_46_2 = ((pub_r001696_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((stage_v_12_1 + (pub_r001696_18_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((stage_v_12_2 + (pub_r001696_18_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((stage_v_20_1 + (pub_r001696_2_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((stage_v_20_2 + (pub_r001696_2_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((stage_v_6_1 + (pub_r001696_12_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((stage_v_6_2 + (pub_r001696_12_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((stage_v_48_1 + (pub_r001696_7_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((stage_v_48_2 + (pub_r001696_7_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((stage_v_13_1 + (pub_r001696_19_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((stage_v_13_2 + (pub_r001696_19_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((stage_v_49_1 + (pub_r001696_15_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((stage_v_49_2 + (pub_r001696_15_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((pub_r001696_11_1 * 2) + 46) & 63;
  int stage_v_53_2 = ((pub_r001696_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((stage_v_2_1 + (pub_r001696_13_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((stage_v_2_2 + (pub_r001696_13_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((stage_v_4_1 + (pub_r001696_10_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((stage_v_4_2 + (pub_r001696_10_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((stage_v_44_1 + (pub_r001696_6_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((stage_v_44_2 + (pub_r001696_6_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((pub_r001696_16_1 * 2) + 38) & 63;
  int stage_v_57_2 = ((pub_r001696_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001696_1_1 * 2) + 14) & 63;
  int stage_v_58_2 = ((pub_r001696_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001696_7_1 * 2) + 40) & 63;
  int stage_v_59_2 = ((pub_r001696_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((stage_v_34_1 + (pub_r001696_12_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_34_2 + (pub_r001696_12_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((pub_r001696_5_1 * 2) + 35) & 63;
  int stage_v_61_2 = ((pub_r001696_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((stage_v_12_1 + (pub_r001696_1_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((stage_v_12_2 + (pub_r001696_1_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((helper_flow_4_1 + (pub_r001696_5_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((helper_flow_4_2 + (pub_r001696_5_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((pub_r001696_5_1 * 2) + 39) & 63;
  int stage_v_64_2 = ((pub_r001696_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001696_17_1 * 2) + 12) & 63;
  int stage_v_65_2 = ((pub_r001696_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((stage_v_60_1 + (pub_r001696_3_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((stage_v_60_2 + (pub_r001696_3_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((stage_v_48_1 + (pub_r001696_2_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_48_2 + (pub_r001696_2_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((stage_v_7_1 + (pub_r001696_4_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_7_2 + (pub_r001696_4_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((stage_v_36_1 + (pub_r001696_9_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((stage_v_36_2 + (pub_r001696_9_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((stage_v_40_1 + (pub_r001696_9_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_40_2 + (pub_r001696_9_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((stage_v_10_1 + (pub_r001696_0_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_10_2 + (pub_r001696_0_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((stage_v_15_1 + (pub_r001696_14_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((stage_v_15_2 + (pub_r001696_14_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((stage_v_22_1 + (pub_r001696_12_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_22_2 + (pub_r001696_12_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((stage_v_6_1 + (pub_r001696_10_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_6_2 + (pub_r001696_10_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((stage_v_42_1 + (pub_r001696_9_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_42_2 + (pub_r001696_9_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((pub_r001696_0_1 * 2) + 28) & 63;
  int stage_v_76_2 = ((pub_r001696_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((stage_v_55_1 + (pub_r001696_11_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((stage_v_55_2 + (pub_r001696_11_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((sec_r001696_11_1 + (pub_r001696_8_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((sec_r001696_11_2 + (pub_r001696_8_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((pub_r001696_0_1 * 2) + 50) & 63;
  int stage_v_79_2 = ((pub_r001696_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001696_11_1 * 2) + 29) & 63;
  int stage_v_80_2 = ((pub_r001696_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001696_11_1 * 2) + 40) & 63;
  int stage_v_81_2 = ((pub_r001696_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((stage_v_38_1 + (pub_r001696_2_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((stage_v_38_2 + (pub_r001696_2_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((stage_v_36_1 + (pub_r001696_16_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_36_2 + (pub_r001696_16_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((stage_v_62_1 + (pub_r001696_15_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_62_2 + (pub_r001696_15_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((stage_v_47_1 + (pub_r001696_15_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_47_2 + (pub_r001696_15_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_66_1 + (pub_r001696_17_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_66_2 + (pub_r001696_17_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_82_1 + (pub_r001696_8_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_82_2 + (pub_r001696_8_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((pub_r001696_19_1 * 2) + 37) & 63;
  int stage_v_88_2 = ((pub_r001696_19_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001696_15_1 * 2) + 43) & 63;
  int stage_v_89_2 = ((pub_r001696_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((stage_v_70_1 + (pub_r001696_9_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_70_2 + (pub_r001696_9_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((pub_r001696_12_1 * 2) + 35) & 63;
  int stage_v_91_2 = ((pub_r001696_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((stage_v_68_1 + (pub_r001696_10_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_68_2 + (pub_r001696_10_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((sec_r001696_9_1 + (pub_r001696_7_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((sec_r001696_9_2 + (pub_r001696_7_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((sec_r001696_8_1 + (pub_r001696_4_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((sec_r001696_8_2 + (pub_r001696_4_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_87_1 + (pub_r001696_16_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_87_2 + (pub_r001696_16_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((stage_v_83_1 + (pub_r001696_19_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_83_2 + (pub_r001696_19_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((stage_v_27_1 + (pub_r001696_8_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_27_2 + (pub_r001696_8_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((pub_r001696_0_1 * 2) + 25) & 63;
  int stage_v_98_2 = ((pub_r001696_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((helper_flow_3_1 + (pub_r001696_12_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((helper_flow_3_2 + (pub_r001696_12_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((stage_v_73_1 + (pub_r001696_8_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_73_2 + (pub_r001696_8_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((stage_v_100_1 + (pub_r001696_12_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_100_2 + (pub_r001696_12_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((stage_v_26_1 + (pub_r001696_7_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_26_2 + (pub_r001696_7_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((stage_v_11_1 + (pub_r001696_12_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_11_2 + (pub_r001696_12_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((pub_r001696_3_1 * 2) + 10) & 63;
  int stage_v_104_2 = ((pub_r001696_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001696_5_1 * 2) + 26) & 63;
  int stage_v_105_2 = ((pub_r001696_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((stage_v_11_1 + (pub_r001696_11_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_11_2 + (pub_r001696_11_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((stage_v_35_1 + (pub_r001696_7_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_35_2 + (pub_r001696_7_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((stage_v_99_1 + (pub_r001696_11_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_99_2 + (pub_r001696_11_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_26_1 + (pub_r001696_4_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_26_2 + (pub_r001696_4_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((stage_v_62_1 + (pub_r001696_17_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((stage_v_62_2 + (pub_r001696_17_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((stage_v_93_1 + (pub_r001696_6_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_93_2 + (pub_r001696_6_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((pub_r001696_14_1 * 2) + 17) & 63;
  int stage_v_112_2 = ((pub_r001696_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((stage_v_69_1 + (pub_r001696_19_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((stage_v_69_2 + (pub_r001696_19_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((pub_r001696_3_1 * 2) + 48) & 63;
  int stage_v_114_2 = ((pub_r001696_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001696_11_1 * 2) + 29) & 63;
  int stage_v_115_2 = ((pub_r001696_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((sec_r001696_4_1 + (pub_r001696_3_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((sec_r001696_4_2 + (pub_r001696_3_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((stage_v_51_1 + (pub_r001696_9_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((stage_v_51_2 + (pub_r001696_9_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((pub_r001696_18_1 * 2) + 46) & 63;
  int stage_v_118_2 = ((pub_r001696_18_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001696_13_1 * 2) + 13) & 63;
  int stage_v_119_2 = ((pub_r001696_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001696_19_1 * 2) + 20) & 63;
  int stage_v_120_2 = ((pub_r001696_19_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((stage_v_18_1 + (pub_r001696_6_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_18_2 + (pub_r001696_6_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((stage_v_44_1 + (pub_r001696_7_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_44_2 + (pub_r001696_7_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((pub_r001696_1_1 * 2) + 9) & 63;
  int stage_v_123_2 = ((pub_r001696_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((stage_v_56_1 + (pub_r001696_2_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((stage_v_56_2 + (pub_r001696_2_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((pub_r001696_10_1 * 2) + 17) & 63;
  int stage_v_125_2 = ((pub_r001696_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((stage_v_113_1 + (pub_r001696_1_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_113_2 + (pub_r001696_1_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((stage_v_35_1 + (pub_r001696_10_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_35_2 + (pub_r001696_10_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((pub_r001696_4_1 * 2) + 50) & 63;
  int stage_v_128_2 = ((pub_r001696_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((sec_r001696_9_1 + (pub_r001696_8_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((sec_r001696_9_2 + (pub_r001696_8_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((sec_r001696_0_1 + (pub_r001696_16_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((sec_r001696_0_2 + (pub_r001696_16_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((sec_r001696_9_1 + (pub_r001696_14_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((sec_r001696_9_2 + (pub_r001696_14_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((stage_v_103_1 + (pub_r001696_0_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_103_2 + (pub_r001696_0_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((pub_r001696_19_1 * 2) + 50) & 63;
  int stage_v_133_2 = ((pub_r001696_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001696_8_1 * 2) + 33) & 63;
  int stage_v_134_2 = ((pub_r001696_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001696_16_1 * 2) + 30) & 63;
  int stage_v_135_2 = ((pub_r001696_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((stage_v_29_1 + (pub_r001696_18_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_29_2 + (pub_r001696_18_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((pub_r001696_0_1 * 2) + 49) & 63;
  int stage_v_137_2 = ((pub_r001696_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((stage_v_136_1 + (pub_r001696_17_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_136_2 + (pub_r001696_17_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((pub_r001696_13_1 * 2) + 19) & 63;
  int stage_v_139_2 = ((pub_r001696_13_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001696_18_1 * 2) + 45) & 63;
  int stage_v_140_2 = ((pub_r001696_18_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((stage_v_20_1 + (pub_r001696_3_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_20_2 + (pub_r001696_3_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((pub_r001696_12_1 * 2) + 9) & 63;
  int stage_v_142_2 = ((pub_r001696_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((stage_v_109_1 + (pub_r001696_9_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_109_2 + (pub_r001696_9_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((pub_r001696_19_1 * 2) + 48) & 63;
  int stage_v_144_2 = ((pub_r001696_19_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((stage_v_96_1 + (pub_r001696_0_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_96_2 + (pub_r001696_0_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((pub_r001696_2_1 * 2) + 44) & 63;
  int stage_v_146_2 = ((pub_r001696_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((stage_v_49_1 + (pub_r001696_18_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_49_2 + (pub_r001696_18_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((stage_v_109_1 + (pub_r001696_7_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_109_2 + (pub_r001696_7_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((pub_r001696_5_1 * 2) + 14) & 63;
  int stage_v_149_2 = ((pub_r001696_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((stage_v_69_1 + (pub_r001696_10_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_69_2 + (pub_r001696_10_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((pub_r001696_14_1 * 2) + 41) & 63;
  int stage_v_151_2 = ((pub_r001696_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((stage_v_95_1 + (pub_r001696_19_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_95_2 + (pub_r001696_19_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((stage_v_111_1 + (pub_r001696_12_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_111_2 + (pub_r001696_12_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((pub_r001696_0_1 * 2) + 44) & 63;
  int stage_v_154_2 = ((pub_r001696_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_102_1 + (pub_r001696_6_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_102_2 + (pub_r001696_6_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((pub_r001696_19_1 * 2) + 9) & 63;
  int stage_v_156_2 = ((pub_r001696_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((sec_r001696_5_1 + (pub_r001696_18_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((sec_r001696_5_2 + (pub_r001696_18_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((pub_r001696_18_1 * 2) + 6) & 63;
  int stage_v_158_2 = ((pub_r001696_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001696_15_1 * 2) + 12) & 63;
  int stage_v_159_2 = ((pub_r001696_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001696_7_1 * 2) + 16) & 63;
  int stage_v_160_2 = ((pub_r001696_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((stage_v_84_1 + (pub_r001696_10_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_84_2 + (pub_r001696_10_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((pub_r001696_19_1 * 2) + 50) & 63;
  int stage_v_162_2 = ((pub_r001696_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((stage_v_127_1 + (pub_r001696_16_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_127_2 + (pub_r001696_16_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((stage_v_101_1 + (pub_r001696_11_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_101_2 + (pub_r001696_11_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((stage_v_78_1 + (pub_r001696_15_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_78_2 + (pub_r001696_15_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_63_1 + (pub_r001696_16_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_63_2 + (pub_r001696_16_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((pub_r001696_14_1 * 2) + 41) & 63;
  int stage_v_167_2 = ((pub_r001696_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001696_15_1 * 2) + 20) & 63;
  int stage_v_168_2 = ((pub_r001696_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((stage_v_18_1 + (pub_r001696_3_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_18_2 + (pub_r001696_3_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((sec_r001696_9_1 + (pub_r001696_14_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((sec_r001696_9_2 + (pub_r001696_14_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((stage_v_74_1 + (pub_r001696_10_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_74_2 + (pub_r001696_10_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((pub_r001696_10_1 * 2) + 21) & 63;
  int stage_v_172_2 = ((pub_r001696_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001696_4_1 * 2) + 41) & 63;
  int stage_v_173_2 = ((pub_r001696_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001696_7_1 * 2) + 35) & 63;
  int stage_v_174_2 = ((pub_r001696_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((stage_v_150_1 + (pub_r001696_13_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_150_2 + (pub_r001696_13_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((stage_v_17_1 + (pub_r001696_19_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_17_2 + (pub_r001696_19_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((stage_v_17_1 + (pub_r001696_2_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_17_2 + (pub_r001696_2_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((stage_v_69_1 + (pub_r001696_8_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_69_2 + (pub_r001696_8_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((pub_r001696_13_1 * 2) + 13) & 63;
  int stage_v_179_2 = ((pub_r001696_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((helper_flow_1_1 + (pub_r001696_14_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((helper_flow_1_2 + (pub_r001696_14_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((pub_r001696_9_1 * 2) + 16) & 63;
  int stage_v_181_2 = ((pub_r001696_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_47_1 + (pub_r001696_10_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_47_2 + (pub_r001696_10_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((pub_r001696_10_1 * 2) + 49) & 63;
  int stage_v_183_2 = ((pub_r001696_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001696_5_1 * 2) + 42) & 63;
  int stage_v_184_2 = ((pub_r001696_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((stage_v_169_1 + (pub_r001696_3_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_169_2 + (pub_r001696_3_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((stage_v_116_1 + (pub_r001696_9_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_116_2 + (pub_r001696_9_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((pub_r001696_15_1 * 2) + 42) & 63;
  int stage_v_187_2 = ((pub_r001696_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001696_7_1 * 2) + 31) & 63;
  int stage_v_188_2 = ((pub_r001696_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001696_9_1 * 2) + 23) & 63;
  int stage_v_189_2 = ((pub_r001696_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((stage_v_27_1 + (pub_r001696_8_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_27_2 + (pub_r001696_8_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((stage_v_77_1 + (pub_r001696_10_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((stage_v_77_2 + (pub_r001696_10_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((pub_r001696_1_1 * 2) + 45) & 63;
  int stage_v_192_2 = ((pub_r001696_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((stage_v_185_1 + (pub_r001696_6_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_185_2 + (pub_r001696_6_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((pub_r001696_0_1 * 2) + 35) & 63;
  int stage_v_194_2 = ((pub_r001696_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((stage_v_101_1 + (pub_r001696_16_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_101_2 + (pub_r001696_16_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((stage_v_77_1 + (pub_r001696_15_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_77_2 + (pub_r001696_15_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((stage_v_157_1 + (pub_r001696_18_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_157_2 + (pub_r001696_18_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((stage_v_75_1 + (pub_r001696_15_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_75_2 + (pub_r001696_15_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_195_1 + (pub_r001696_0_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_195_2 + (pub_r001696_0_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_77_1 + (pub_r001696_13_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_77_2 + (pub_r001696_13_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((stage_v_70_1 + (pub_r001696_18_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_70_2 + (pub_r001696_18_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_117_1 + (pub_r001696_17_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_117_2 + (pub_r001696_17_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((sec_r001696_13_1 + (pub_r001696_11_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((sec_r001696_13_2 + (pub_r001696_11_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((stage_v_24_1 + (pub_r001696_9_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_24_2 + (pub_r001696_9_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((stage_v_86_1 + (pub_r001696_13_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_86_2 + (pub_r001696_13_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((pub_r001696_14_1 * 2) + 30) & 63;
  int stage_v_206_2 = ((pub_r001696_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001696_13_1 * 2) + 38) & 63;
  int stage_v_207_2 = ((pub_r001696_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((stage_v_171_1 + (pub_r001696_2_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_171_2 + (pub_r001696_2_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((pub_r001696_0_1 * 2) + 20) & 63;
  int stage_v_209_2 = ((pub_r001696_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((stage_v_185_1 + (pub_r001696_7_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((stage_v_185_2 + (pub_r001696_7_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((pub_r001696_13_1 * 2) + 50) & 63;
  int stage_v_211_2 = ((pub_r001696_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((stage_v_166_1 + (pub_r001696_6_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((stage_v_166_2 + (pub_r001696_6_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((stage_v_171_1 + (pub_r001696_19_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((stage_v_171_2 + (pub_r001696_19_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((stage_v_171_1 + (pub_r001696_1_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_171_2 + (pub_r001696_1_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((stage_v_44_1 + (pub_r001696_2_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((stage_v_44_2 + (pub_r001696_2_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((stage_v_131_1 + (pub_r001696_1_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((stage_v_131_2 + (pub_r001696_1_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((stage_v_107_1 + (pub_r001696_5_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_107_2 + (pub_r001696_5_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((stage_v_95_1 + (pub_r001696_7_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_95_2 + (pub_r001696_7_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((pub_r001696_15_1 * 2) + 27) & 63;
  int stage_v_219_2 = ((pub_r001696_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((sec_r001696_6_1 + (pub_r001696_14_1 * 2)) + 665) & 127;
  int stage_v_220_2 = ((sec_r001696_6_2 + (pub_r001696_14_2 * 2)) + 665) & 127;
  if (stage_v_220_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_220_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_220_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_220_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_221_1 = ((pub_r001696_1_1 * 2) + 37) & 63;
  int stage_v_221_2 = ((pub_r001696_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((pub_r001696_14_1 * 2) + 5) & 63;
  int stage_v_222_2 = ((pub_r001696_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001696_19_1 * 2) + 32) & 63;
  int stage_v_223_2 = ((pub_r001696_19_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001696_12_1 * 2) + 47) & 63;
  int stage_v_224_2 = ((pub_r001696_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((stage_v_122_1 + (pub_r001696_0_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_122_2 + (pub_r001696_0_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_226_1 = ((pub_r001696_12_1 * 2) + 40) & 63;
  int stage_v_226_2 = ((pub_r001696_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((stage_v_38_1 + (pub_r001696_1_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((stage_v_38_2 + (pub_r001696_1_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_228_1 = ((stage_v_147_1 + (pub_r001696_16_1 * 2)) + 689) & 127;
  int stage_v_228_2 = ((stage_v_147_2 + (pub_r001696_16_2 * 2)) + 689) & 127;
  if (stage_v_228_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_228_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_228_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_228_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_229_1 = ((stage_v_122_1 + (pub_r001696_0_1 * 2)) + 692) & 127;
  int stage_v_229_2 = ((stage_v_122_2 + (pub_r001696_0_2 * 2)) + 692) & 127;
  if (stage_v_229_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_229_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_229_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_229_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_230_1 = ((pub_r001696_9_1 * 2) + 13) & 63;
  int stage_v_230_2 = ((pub_r001696_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001696_15_1 * 2) + 9) & 63;
  int stage_v_231_2 = ((pub_r001696_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001696_1_1 * 2) + 36) & 63;
  int stage_v_232_2 = ((pub_r001696_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((stage_v_78_1 + (pub_r001696_19_1 * 2)) + 704) & 127;
  int stage_v_233_2 = ((stage_v_78_2 + (pub_r001696_19_2 * 2)) + 704) & 127;
  if (stage_v_233_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_233_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_233_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_233_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_234_1 = ((pub_r001696_12_1 * 2) + 30) & 63;
  int stage_v_234_2 = ((pub_r001696_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001696_12_1 * 2) + 8) & 63;
  int stage_v_235_2 = ((pub_r001696_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001696_11_1 == pub_r001696_11_2);
  __CPROVER_assume(pub_r001696_4_1 == pub_r001696_4_2);
  __CPROVER_assume(sec_r001696_1_1 != sec_r001696_1_2);
  __CPROVER_assume(pub_r001696_5_1 == pub_r001696_5_2);
  __CPROVER_assume(pub_r001696_3_1 == pub_r001696_3_2);
  __CPROVER_assume(sec_r001696_13_1 != sec_r001696_13_2);
  __CPROVER_assume(pub_r001696_12_1 == pub_r001696_12_2);
  __CPROVER_assume(sec_r001696_3_1 != sec_r001696_3_2);
  __CPROVER_assume(pub_r001696_15_1 == pub_r001696_15_2);
  __CPROVER_assume(pub_r001696_7_1 == pub_r001696_7_2);
  __CPROVER_assume(pub_r001696_0_1 == pub_r001696_0_2);
  __CPROVER_assume(pub_r001696_8_1 == pub_r001696_8_2);
  __CPROVER_assume(pub_r001696_18_1 == pub_r001696_18_2);
  __CPROVER_assume(sec_r001696_8_1 != sec_r001696_8_2);
  __CPROVER_assume(pub_r001696_17_1 == pub_r001696_17_2);
  __CPROVER_assume(pub_r001696_10_1 == pub_r001696_10_2);
  __CPROVER_assume(sec_r001696_15_1 != sec_r001696_15_2);
  __CPROVER_assume(sec_r001696_0_1 != sec_r001696_0_2);
  __CPROVER_assume(pub_r001696_14_1 == pub_r001696_14_2);
  __CPROVER_assume(pub_r001696_19_1 == pub_r001696_19_2);
  __CPROVER_assume(sec_r001696_6_1 != sec_r001696_6_2);
  __CPROVER_assume(sec_r001696_9_1 != sec_r001696_9_2);
  __CPROVER_assume(sec_r001696_12_1 != sec_r001696_12_2);
  __CPROVER_assume(sec_r001696_2_1 != sec_r001696_2_2);
  __CPROVER_assume(pub_r001696_6_1 == pub_r001696_6_2);
  __CPROVER_assume(sec_r001696_4_1 != sec_r001696_4_2);
  __CPROVER_assume(sec_r001696_5_1 != sec_r001696_5_2);
  __CPROVER_assume(pub_r001696_9_1 == pub_r001696_9_2);
  __CPROVER_assume(sec_r001696_10_1 != sec_r001696_10_2);
  __CPROVER_assume(pub_r001696_2_1 == pub_r001696_2_2);
  __CPROVER_assume(sec_r001696_14_1 != sec_r001696_14_2);
  __CPROVER_assume(pub_r001696_16_1 == pub_r001696_16_2);
  __CPROVER_assume(sec_r001696_11_1 != sec_r001696_11_2);
  __CPROVER_assume(pub_r001696_13_1 == pub_r001696_13_2);
  __CPROVER_assume(pub_r001696_1_1 == pub_r001696_1_2);
  __CPROVER_assume(sec_r001696_16_1 != sec_r001696_16_2);
  __CPROVER_assume(sec_r001696_7_1 != sec_r001696_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.balance == st_var_1_2.balance);
  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.status == st_var_1_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.prev_in == st_var_2_2.prev_in);
  assert(st_var_2_1.prev_out == st_var_2_2.prev_out);
  assert(st_var_2_1.cutoff == st_var_2_2.cutoff);
  assert(st_var_2_1.damping == st_var_2_2.damping);
  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
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
}


