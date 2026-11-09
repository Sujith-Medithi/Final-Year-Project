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
struct EventLog_R001586_8613_0
{
  short facility;
  int seq;
  short timestamp;
  int signature;
  int buffer[3];
};
struct CipherContext_R001586_8613_1
{
  int tag;
  unsigned char nonce;
  int iv;
  int flags;
  int buffer[3];
};
struct Transaction_R001586_8613_2
{
  int account_id;
  short balance;
  unsigned char auth_code;
  int rate;
  int fee;
  int buffer[3];
};
union RegisterBank_R001586_8613_0
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
void fn_R001586_8613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st_1 = {0};
  struct Transaction_R001586_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int weight_48_1 = 0;
  int weight_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_48_1 = ((weight_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_48_2 = ((weight_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_48_1) & 127;
    acc_2 = (acc_2 + weight_48_2) & 127;
  }

  int checksum_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_70_1)
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

  switch (checksum_70_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_48_1 == weight_48_2);
  assert(checksum_70_1 == checksum_70_2);
}

int fn_R001586_8613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int weight_48 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_48 = ((weight_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_48) & 127;
  }

  int checksum_70 = (aux + st.buffer[1]) & 3;
  switch (checksum_70)
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

void fn_R001586_8613_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st_1 = {0};
  struct Transaction_R001586_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int quotient_87_1 = 0;
  int quotient_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_87_1 = ((quotient_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_87_2 = ((quotient_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_87_1) & 127;
    acc_2 = (acc_2 + quotient_87_2) & 127;
  }

  int tally_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_35_1 > 45)
  {
    acc_1 = ((acc_1 + (tally_35_1 * 2)) + 5) & 127;
    aux_1 ^= tally_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_35_2 > 45)
  {
    acc_2 = ((acc_2 + (tally_35_2 * 2)) + 5) & 127;
    aux_2 ^= tally_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_35_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_87_1 == quotient_87_2);
  assert(tally_35_1 == tally_35_2);
}

int fn_R001586_8613_1(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int quotient_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_87 = ((quotient_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_87) & 127;
  }

  int tally_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_35 > 45)
  {
    acc = ((acc + (tally_35 * 2)) + 5) & 127;
    aux ^= tally_35 & 15;
  }
  else
  {
    acc = ((acc - tally_35) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001586_8613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001586_8613_1 st_1 = {0};
  struct CipherContext_R001586_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_60_1) & 63;
  aux_2 = (aux_2 + residue_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_60_1 > 31)
  {
    acc_1 = ((acc_1 + (scale_60_1 * 2)) + 5) & 127;
    aux_1 ^= scale_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_60_2 > 31)
  {
    acc_2 = ((acc_2 + (scale_60_2 * 2)) + 5) & 127;
    aux_2 ^= scale_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_29_1 = local_arr_1[aux_1 % 3];
  int tracker_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_60_1 == residue_60_2);
  assert(scale_60_1 == scale_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_29_1 == tracker_29_2);
}

int fn_R001586_8613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001586_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_60) & 63;
  acc ^= aux;
  int scale_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_60 > 31)
  {
    acc = ((acc + (scale_60 * 2)) + 5) & 127;
    aux ^= scale_60 & 15;
  }
  else
  {
    acc = ((acc - scale_60) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tracker_29 = local_arr[aux % 3];
  acc = (acc + (tracker_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001586_8613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st_1 = {0};
  struct Transaction_R001586_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quantum_37_1 = 0;
  int quantum_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_37_1 = ((quantum_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_37_2 = ((quantum_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_37_1) & 127;
    acc_2 = (acc_2 + quantum_37_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_37_1 == quantum_37_2);
}

int fn_R001586_8613_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quantum_37 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_37 = ((quantum_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_37) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001586_8613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001586_8613_0 st_1 = {0};
  struct EventLog_R001586_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_47_1 = local_arr_1[aux_1 % 3];
  int anchor_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_47_2 * 2)) & 127;
  int quotient_47_1 = 0;
  int quotient_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_47_1 = ((quotient_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_47_2 = ((quotient_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_47_1) & 127;
    acc_2 = (acc_2 + quotient_47_2) & 127;
  }

  int threshold_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_99_1)
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

  switch (threshold_99_2)
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

  int pivot_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_26_1) & 63;
  aux_2 = (aux_2 + pivot_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_47_1 == anchor_47_2);
  assert(quotient_47_1 == quotient_47_2);
  assert(threshold_99_1 == threshold_99_2);
  assert(pivot_26_1 == pivot_26_2);
}

int fn_R001586_8613_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001586_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int anchor_47 = local_arr[aux % 3];
  acc = (acc + (anchor_47 * 2)) & 127;
  int quotient_47 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_47 = ((quotient_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_47) & 127;
  }

  int threshold_99 = (aux + st.buffer[1]) & 3;
  switch (threshold_99)
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

  int pivot_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_26) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001586_8613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001586_8613_0 st_1 = {0};
  struct EventLog_R001586_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_24_1 = local_arr_1[aux_1 % 3];
  int coefficient_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_24_2 * 2)) & 127;
  int sample_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_34_1)
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

  switch (sample_34_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_24_1 == coefficient_24_2);
  assert(sample_34_1 == sample_34_2);
}

int fn_R001586_8613_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001586_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int coefficient_24 = local_arr[aux % 3];
  acc = (acc + (coefficient_24 * 2)) & 127;
  int sample_34 = (aux + st.buffer[1]) & 3;
  switch (sample_34)
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

void fn_R001586_8613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st_1 = {0};
  struct Transaction_R001586_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int segment_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_17_1 > 35)
  {
    acc_1 = ((acc_1 + (segment_17_1 * 2)) + 5) & 127;
    aux_1 ^= segment_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_17_2 > 35)
  {
    acc_2 = ((acc_2 + (segment_17_2 * 2)) + 5) & 127;
    aux_2 ^= segment_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_17_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_79_1)
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

  switch (metric_79_2)
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

  int segment_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_52_1) & 63;
  aux_2 = (aux_2 + segment_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_17_1 == segment_17_2);
  assert(metric_79_1 == metric_79_2);
  assert(segment_52_1 == segment_52_2);
}

int fn_R001586_8613_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int segment_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_17 > 35)
  {
    acc = ((acc + (segment_17 * 2)) + 5) & 127;
    aux ^= segment_17 & 15;
  }
  else
  {
    acc = ((acc - segment_17) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_79 = (aux + st.buffer[1]) & 3;
  switch (metric_79)
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

  int segment_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_52) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001586_8613_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001586_8613_0 st_1 = {0};
  struct EventLog_R001586_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int margin_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_29_1) & 63;
  aux_2 = (aux_2 + margin_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_81_1)
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

  switch (stride_81_2)
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

  int residue_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_31_1 > 24)
  {
    acc_1 = ((acc_1 + (residue_31_1 * 2)) + 5) & 127;
    aux_1 ^= residue_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_31_2 > 24)
  {
    acc_2 = ((acc_2 + (residue_31_2 * 2)) + 5) & 127;
    aux_2 ^= residue_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_31_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_29_1 == margin_29_2);
  assert(stride_81_1 == stride_81_2);
  assert(residue_31_1 == residue_31_2);
}

int fn_R001586_8613_7(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001586_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int margin_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_29) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_81 = (aux + st.buffer[1]) & 3;
  switch (stride_81)
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

  int residue_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_31 > 24)
  {
    acc = ((acc + (residue_31 * 2)) + 5) & 127;
    aux ^= residue_31 & 15;
  }
  else
  {
    acc = ((acc - residue_31) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001586_8613_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001586_8613_0 st_1 = {0};
  struct EventLog_R001586_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int cursor_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_94_1) & 63;
  aux_2 = (aux_2 + cursor_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_52_1 > 25)
  {
    acc_1 = ((acc_1 + (weight_52_1 * 2)) + 5) & 127;
    aux_1 ^= weight_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_52_2 > 25)
  {
    acc_2 = ((acc_2 + (weight_52_2 * 2)) + 5) & 127;
    aux_2 ^= weight_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_59_1 = local_arr_1[aux_1 % 3];
  int cursor_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_59_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_94_1 == cursor_94_2);
  assert(weight_52_1 == weight_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_59_1 == cursor_59_2);
}

int fn_R001586_8613_8(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001586_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int cursor_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_94) & 63;
  acc ^= aux;
  int weight_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_52 > 25)
  {
    acc = ((acc + (weight_52 * 2)) + 5) & 127;
    aux ^= weight_52 & 15;
  }
  else
  {
    acc = ((acc - weight_52) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_59 = local_arr[aux % 3];
  acc = (acc + (cursor_59 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001586_8613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st_1 = {0};
  struct Transaction_R001586_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_95_1 = local_arr_1[aux_1 % 3];
  int quantum_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_95_2 * 2)) & 127;
  int tracker_58_1 = 0;
  int tracker_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_58_1 = ((tracker_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_58_2 = ((tracker_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_58_1) & 127;
    acc_2 = (acc_2 + tracker_58_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_95_1 == quantum_95_2);
  assert(tracker_58_1 == tracker_58_2);
}

int fn_R001586_8613_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quantum_95 = local_arr[aux % 3];
  acc = (acc + (quantum_95 * 2)) & 127;
  int tracker_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_58 = ((tracker_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_58) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001586_8613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st_1 = {0};
  struct Transaction_R001586_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int threshold_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_87_1)
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

  switch (threshold_87_2)
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

  int scale_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_47_1 > 39)
  {
    acc_1 = ((acc_1 + (scale_47_1 * 2)) + 5) & 127;
    aux_1 ^= scale_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_47_2 > 39)
  {
    acc_2 = ((acc_2 + (scale_47_2 * 2)) + 5) & 127;
    aux_2 ^= scale_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_47_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_99_1 = local_arr_1[aux_1 % 3];
  int delta_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_99_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_87_1 == threshold_87_2);
  assert(scale_47_1 == scale_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_99_1 == delta_99_2);
}

int fn_R001586_8613_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int threshold_87 = (aux + st.buffer[1]) & 3;
  switch (threshold_87)
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

  int scale_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_47 > 39)
  {
    acc = ((acc + (scale_47 * 2)) + 5) & 127;
    aux ^= scale_47 & 15;
  }
  else
  {
    acc = ((acc - scale_47) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_99 = local_arr[aux % 3];
  acc = (acc + (delta_99 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001586_8613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001586_8613_1 st_1 = {0};
  struct CipherContext_R001586_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int index_reg_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_10_1 > 43)
  {
    acc_1 = ((acc_1 + (index_reg_10_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_10_2 > 43)
  {
    acc_2 = ((acc_2 + (index_reg_10_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_85_1)
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

  switch (stride_85_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_10_1 == index_reg_10_2);
  assert(stride_85_1 == stride_85_2);
}

int fn_R001586_8613_11(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001586_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int index_reg_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_10 > 43)
  {
    acc = ((acc + (index_reg_10 * 2)) + 5) & 127;
    aux ^= index_reg_10 & 15;
  }
  else
  {
    acc = ((acc - index_reg_10) + 11) & 127;
    aux += 3;
  }
  int stride_85 = (aux + st.buffer[1]) & 3;
  switch (stride_85)
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

void fn_R001586_8613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001586_8613_1 st_1 = {0};
  struct CipherContext_R001586_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int parity_88_1 = 0;
  int parity_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_88_1 = ((parity_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_88_2 = ((parity_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_88_1) & 127;
    acc_2 = (acc_2 + parity_88_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_84_1 = local_arr_1[aux_1 % 3];
  int mask_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_84_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_88_1 == parity_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_84_1 == mask_84_2);
}

int fn_R001586_8613_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001586_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int parity_88 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_88 = ((parity_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_88) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_84 = local_arr[aux % 3];
  acc = (acc + (mask_84 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001586_8613_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001586_8613_0 st_1 = {0};
  struct EventLog_R001586_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int factor_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_76_1 > 31)
  {
    acc_1 = ((acc_1 + (factor_76_1 * 2)) + 5) & 127;
    aux_1 ^= factor_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_76_2 > 31)
  {
    acc_2 = ((acc_2 + (factor_76_2 * 2)) + 5) & 127;
    aux_2 ^= factor_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_60_1) & 63;
  aux_2 = (aux_2 + quantum_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_76_1 == factor_76_2);
  assert(quantum_60_1 == quantum_60_2);
}

int fn_R001586_8613_13(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001586_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int factor_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_76 > 31)
  {
    acc = ((acc + (factor_76 * 2)) + 5) & 127;
    aux ^= factor_76 & 15;
  }
  else
  {
    acc = ((acc - factor_76) + 11) & 127;
    aux += 3;
  }
  int quantum_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_60) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001586_8613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001586_8613_0 st_1 = {0};
  struct EventLog_R001586_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_23_1 = local_arr_1[aux_1 % 3];
  int stride_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_23_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_23_1 == stride_23_2);
}

int fn_R001586_8613_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001586_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int stride_23 = local_arr[aux % 3];
  acc = (acc + (stride_23 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001586_8613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st_1 = {0};
  struct Transaction_R001586_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int cursor_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_50_1 > 50)
  {
    acc_1 = ((acc_1 + (cursor_50_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_50_2 > 50)
  {
    acc_2 = ((acc_2 + (cursor_50_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_16_1)
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

  switch (parity_16_2)
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

  int quantum_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_55_1) & 63;
  aux_2 = (aux_2 + quantum_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_50_1 == cursor_50_2);
  assert(parity_16_1 == parity_16_2);
  assert(quantum_55_1 == quantum_55_2);
}

int fn_R001586_8613_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int cursor_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_50 > 50)
  {
    acc = ((acc + (cursor_50 * 2)) + 5) & 127;
    aux ^= cursor_50 & 15;
  }
  else
  {
    acc = ((acc - cursor_50) + 11) & 127;
    aux += 3;
  }
  int parity_16 = (aux + st.buffer[1]) & 3;
  switch (parity_16)
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

  int quantum_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_55) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001586_8613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st_1 = {0};
  struct Transaction_R001586_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int bound_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_81_1 > 15)
  {
    acc_1 = ((acc_1 + (bound_81_1 * 2)) + 5) & 127;
    aux_1 ^= bound_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_81_2 > 15)
  {
    acc_2 = ((acc_2 + (bound_81_2 * 2)) + 5) & 127;
    aux_2 ^= bound_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_81_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_75_1 = local_arr_1[aux_1 % 3];
  int scale_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_75_2 * 2)) & 127;
  int coefficient_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_68_1)
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

  switch (coefficient_68_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_81_1 == bound_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_75_1 == scale_75_2);
  assert(coefficient_68_1 == coefficient_68_2);
}

int fn_R001586_8613_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int bound_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_81 > 15)
  {
    acc = ((acc + (bound_81 * 2)) + 5) & 127;
    aux ^= bound_81 & 15;
  }
  else
  {
    acc = ((acc - bound_81) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int scale_75 = local_arr[aux % 3];
  acc = (acc + (scale_75 * 2)) & 127;
  int coefficient_68 = (aux + st.buffer[1]) & 3;
  switch (coefficient_68)
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

void fn_R001586_8613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st_1 = {0};
  struct Transaction_R001586_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int parity_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_13_1)
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

  switch (parity_13_2)
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

  int vector_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_60_1) & 63;
  aux_2 = (aux_2 + vector_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_13_1 == parity_13_2);
  assert(vector_60_1 == vector_60_2);
}

int fn_R001586_8613_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001586_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int parity_13 = (aux + st.buffer[1]) & 3;
  switch (parity_13)
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

  int vector_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_60) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001586_8613_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001586_8613_0 st_1 = {0};
  struct EventLog_R001586_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int scale_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_79_1 > 12)
  {
    acc_1 = ((acc_1 + (scale_79_1 * 2)) + 5) & 127;
    aux_1 ^= scale_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_79_2 > 12)
  {
    acc_2 = ((acc_2 + (scale_79_2 * 2)) + 5) & 127;
    aux_2 ^= scale_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_30_1 = 0;
  int coefficient_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_30_1 = ((coefficient_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_30_2 = ((coefficient_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_30_1) & 127;
    acc_2 = (acc_2 + coefficient_30_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_79_1 == scale_79_2);
  assert(coefficient_30_1 == coefficient_30_2);
}

int fn_R001586_8613_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001586_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int scale_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_79 > 12)
  {
    acc = ((acc + (scale_79 * 2)) + 5) & 127;
    aux ^= scale_79 & 15;
  }
  else
  {
    acc = ((acc - scale_79) + 11) & 127;
    aux += 3;
  }
  int coefficient_30 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_30 = ((coefficient_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_30) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001586_8613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001586_8613_1 st_1 = {0};
  struct CipherContext_R001586_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int anchor_22_1 = 0;
  int anchor_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_22_1 = ((anchor_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_22_2 = ((anchor_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_22_1) & 127;
    acc_2 = (acc_2 + anchor_22_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_22_1 == anchor_22_2);
}

int fn_R001586_8613_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001586_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int anchor_22 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_22 = ((anchor_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_22) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001586_0_1;
  int sec_r001586_0_2;
  int sec_r001586_1_1;
  int sec_r001586_1_2;
  int sec_r001586_2_1;
  int sec_r001586_2_2;
  int sec_r001586_3_1;
  int sec_r001586_3_2;
  int sec_r001586_4_1;
  int sec_r001586_4_2;
  int sec_r001586_5_1;
  int sec_r001586_5_2;
  int sec_r001586_6_1;
  int sec_r001586_6_2;
  int sec_r001586_7_1;
  int sec_r001586_7_2;
  int sec_r001586_8_1;
  int sec_r001586_8_2;
  int sec_r001586_9_1;
  int sec_r001586_9_2;
  int sec_r001586_10_1;
  int sec_r001586_10_2;
  int sec_r001586_11_1;
  int sec_r001586_11_2;
  int sec_r001586_12_1;
  int sec_r001586_12_2;
  int sec_r001586_13_1;
  int sec_r001586_13_2;
  int sec_r001586_14_1;
  int sec_r001586_14_2;
  int sec_r001586_15_1;
  int sec_r001586_15_2;
  int sec_r001586_16_1;
  int sec_r001586_16_2;
  int sec_r001586_17_1;
  int sec_r001586_17_2;
  int sec_r001586_18_1;
  int sec_r001586_18_2;
  int sec_r001586_19_1;
  int sec_r001586_19_2;
  int sec_r001586_20_1;
  int sec_r001586_20_2;
  int pub_r001586_0_1;
  int pub_r001586_0_2;
  int pub_r001586_1_1;
  int pub_r001586_1_2;
  int pub_r001586_2_1;
  int pub_r001586_2_2;
  int pub_r001586_3_1;
  int pub_r001586_3_2;
  int pub_r001586_4_1;
  int pub_r001586_4_2;
  int pub_r001586_5_1;
  int pub_r001586_5_2;
  int pub_r001586_6_1;
  int pub_r001586_6_2;
  int pub_r001586_7_1;
  int pub_r001586_7_2;
  int pub_r001586_8_1;
  int pub_r001586_8_2;
  int pub_r001586_9_1;
  int pub_r001586_9_2;
  int pub_r001586_10_1;
  int pub_r001586_10_2;
  int pub_r001586_11_1;
  int pub_r001586_11_2;
  int pub_r001586_12_1;
  int pub_r001586_12_2;
  int pub_r001586_13_1;
  int pub_r001586_13_2;
  int pub_r001586_14_1;
  int pub_r001586_14_2;
  int pub_r001586_15_1;
  int pub_r001586_15_2;
  int pub_r001586_16_1;
  int pub_r001586_16_2;
  int pub_r001586_17_1;
  int pub_r001586_17_2;
  int pub_r001586_18_1;
  int pub_r001586_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001586_0_1 >= (-100)) && (pub_r001586_0_1 <= 100));
  __CPROVER_assume((pub_r001586_0_2 >= (-100)) && (pub_r001586_0_2 <= 100));
  __CPROVER_assume((pub_r001586_1_1 >= (-100)) && (pub_r001586_1_1 <= 100));
  __CPROVER_assume((pub_r001586_1_2 >= (-100)) && (pub_r001586_1_2 <= 100));
  __CPROVER_assume((pub_r001586_2_1 >= (-100)) && (pub_r001586_2_1 <= 100));
  __CPROVER_assume((pub_r001586_2_2 >= (-100)) && (pub_r001586_2_2 <= 100));
  __CPROVER_assume((pub_r001586_3_1 >= (-100)) && (pub_r001586_3_1 <= 100));
  __CPROVER_assume((pub_r001586_3_2 >= (-100)) && (pub_r001586_3_2 <= 100));
  __CPROVER_assume((pub_r001586_4_1 >= (-100)) && (pub_r001586_4_1 <= 100));
  __CPROVER_assume((pub_r001586_4_2 >= (-100)) && (pub_r001586_4_2 <= 100));
  __CPROVER_assume((pub_r001586_5_1 >= (-100)) && (pub_r001586_5_1 <= 100));
  __CPROVER_assume((pub_r001586_5_2 >= (-100)) && (pub_r001586_5_2 <= 100));
  __CPROVER_assume((pub_r001586_6_1 >= (-100)) && (pub_r001586_6_1 <= 100));
  __CPROVER_assume((pub_r001586_6_2 >= (-100)) && (pub_r001586_6_2 <= 100));
  __CPROVER_assume((pub_r001586_7_1 >= (-100)) && (pub_r001586_7_1 <= 100));
  __CPROVER_assume((pub_r001586_7_2 >= (-100)) && (pub_r001586_7_2 <= 100));
  __CPROVER_assume((pub_r001586_8_1 >= (-100)) && (pub_r001586_8_1 <= 100));
  __CPROVER_assume((pub_r001586_8_2 >= (-100)) && (pub_r001586_8_2 <= 100));
  __CPROVER_assume((pub_r001586_9_1 >= (-100)) && (pub_r001586_9_1 <= 100));
  __CPROVER_assume((pub_r001586_9_2 >= (-100)) && (pub_r001586_9_2 <= 100));
  __CPROVER_assume((pub_r001586_10_1 >= (-100)) && (pub_r001586_10_1 <= 100));
  __CPROVER_assume((pub_r001586_10_2 >= (-100)) && (pub_r001586_10_2 <= 100));
  __CPROVER_assume((pub_r001586_11_1 >= (-100)) && (pub_r001586_11_1 <= 100));
  __CPROVER_assume((pub_r001586_11_2 >= (-100)) && (pub_r001586_11_2 <= 100));
  __CPROVER_assume((pub_r001586_12_1 >= (-100)) && (pub_r001586_12_1 <= 100));
  __CPROVER_assume((pub_r001586_12_2 >= (-100)) && (pub_r001586_12_2 <= 100));
  __CPROVER_assume((pub_r001586_13_1 >= (-100)) && (pub_r001586_13_1 <= 100));
  __CPROVER_assume((pub_r001586_13_2 >= (-100)) && (pub_r001586_13_2 <= 100));
  __CPROVER_assume((pub_r001586_14_1 >= (-100)) && (pub_r001586_14_1 <= 100));
  __CPROVER_assume((pub_r001586_14_2 >= (-100)) && (pub_r001586_14_2 <= 100));
  __CPROVER_assume((pub_r001586_15_1 >= (-100)) && (pub_r001586_15_1 <= 100));
  __CPROVER_assume((pub_r001586_15_2 >= (-100)) && (pub_r001586_15_2 <= 100));
  __CPROVER_assume((pub_r001586_16_1 >= (-100)) && (pub_r001586_16_1 <= 100));
  __CPROVER_assume((pub_r001586_16_2 >= (-100)) && (pub_r001586_16_2 <= 100));
  __CPROVER_assume((pub_r001586_17_1 >= (-100)) && (pub_r001586_17_1 <= 100));
  __CPROVER_assume((pub_r001586_17_2 >= (-100)) && (pub_r001586_17_2 <= 100));
  __CPROVER_assume((pub_r001586_18_1 >= (-100)) && (pub_r001586_18_1 <= 100));
  __CPROVER_assume((pub_r001586_18_2 >= (-100)) && (pub_r001586_18_2 <= 100));
  __CPROVER_assume((sec_r001586_0_1 >= 0) && (sec_r001586_0_1 <= 255));
  __CPROVER_assume((sec_r001586_0_2 >= 0) && (sec_r001586_0_2 <= 255));
  __CPROVER_assume((sec_r001586_1_1 >= 0) && (sec_r001586_1_1 <= 255));
  __CPROVER_assume((sec_r001586_1_2 >= 0) && (sec_r001586_1_2 <= 255));
  __CPROVER_assume((sec_r001586_2_1 >= 0) && (sec_r001586_2_1 <= 255));
  __CPROVER_assume((sec_r001586_2_2 >= 0) && (sec_r001586_2_2 <= 255));
  __CPROVER_assume((sec_r001586_3_1 >= 0) && (sec_r001586_3_1 <= 255));
  __CPROVER_assume((sec_r001586_3_2 >= 0) && (sec_r001586_3_2 <= 255));
  __CPROVER_assume((sec_r001586_4_1 >= 0) && (sec_r001586_4_1 <= 255));
  __CPROVER_assume((sec_r001586_4_2 >= 0) && (sec_r001586_4_2 <= 255));
  __CPROVER_assume((sec_r001586_5_1 >= 0) && (sec_r001586_5_1 <= 255));
  __CPROVER_assume((sec_r001586_5_2 >= 0) && (sec_r001586_5_2 <= 255));
  __CPROVER_assume((sec_r001586_6_1 >= 0) && (sec_r001586_6_1 <= 255));
  __CPROVER_assume((sec_r001586_6_2 >= 0) && (sec_r001586_6_2 <= 255));
  __CPROVER_assume((sec_r001586_7_1 >= 0) && (sec_r001586_7_1 <= 255));
  __CPROVER_assume((sec_r001586_7_2 >= 0) && (sec_r001586_7_2 <= 255));
  __CPROVER_assume((sec_r001586_8_1 >= 0) && (sec_r001586_8_1 <= 255));
  __CPROVER_assume((sec_r001586_8_2 >= 0) && (sec_r001586_8_2 <= 255));
  __CPROVER_assume((sec_r001586_9_1 >= 0) && (sec_r001586_9_1 <= 255));
  __CPROVER_assume((sec_r001586_9_2 >= 0) && (sec_r001586_9_2 <= 255));
  __CPROVER_assume((sec_r001586_10_1 >= 0) && (sec_r001586_10_1 <= 255));
  __CPROVER_assume((sec_r001586_10_2 >= 0) && (sec_r001586_10_2 <= 255));
  __CPROVER_assume((sec_r001586_11_1 >= 0) && (sec_r001586_11_1 <= 255));
  __CPROVER_assume((sec_r001586_11_2 >= 0) && (sec_r001586_11_2 <= 255));
  __CPROVER_assume((sec_r001586_12_1 >= 0) && (sec_r001586_12_1 <= 255));
  __CPROVER_assume((sec_r001586_12_2 >= 0) && (sec_r001586_12_2 <= 255));
  __CPROVER_assume((sec_r001586_13_1 >= 0) && (sec_r001586_13_1 <= 255));
  __CPROVER_assume((sec_r001586_13_2 >= 0) && (sec_r001586_13_2 <= 255));
  __CPROVER_assume((sec_r001586_14_1 >= 0) && (sec_r001586_14_1 <= 255));
  __CPROVER_assume((sec_r001586_14_2 >= 0) && (sec_r001586_14_2 <= 255));
  __CPROVER_assume((sec_r001586_15_1 >= 0) && (sec_r001586_15_1 <= 255));
  __CPROVER_assume((sec_r001586_15_2 >= 0) && (sec_r001586_15_2 <= 255));
  __CPROVER_assume((sec_r001586_16_1 >= 0) && (sec_r001586_16_1 <= 255));
  __CPROVER_assume((sec_r001586_16_2 >= 0) && (sec_r001586_16_2 <= 255));
  __CPROVER_assume((sec_r001586_17_1 >= 0) && (sec_r001586_17_1 <= 255));
  __CPROVER_assume((sec_r001586_17_2 >= 0) && (sec_r001586_17_2 <= 255));
  __CPROVER_assume((sec_r001586_18_1 >= 0) && (sec_r001586_18_1 <= 255));
  __CPROVER_assume((sec_r001586_18_2 >= 0) && (sec_r001586_18_2 <= 255));
  __CPROVER_assume((sec_r001586_19_1 >= 0) && (sec_r001586_19_1 <= 255));
  __CPROVER_assume((sec_r001586_19_2 >= 0) && (sec_r001586_19_2 <= 255));
  __CPROVER_assume((sec_r001586_20_1 >= 0) && (sec_r001586_20_1 <= 255));
  __CPROVER_assume((sec_r001586_20_2 >= 0) && (sec_r001586_20_2 <= 255));
  struct EventLog_R001586_8613_0 st_var_0_1 = {0};
  struct EventLog_R001586_8613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001586_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001586_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001586_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001586_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001586_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001586_0_2 + 7) & 15;
  struct CipherContext_R001586_8613_1 st_var_1_1 = {0};
  struct CipherContext_R001586_8613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001586_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001586_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001586_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001586_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001586_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001586_0_2 + 9) & 15;
  struct Transaction_R001586_8613_2 st_var_2_1 = {0};
  struct Transaction_R001586_8613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001586_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001586_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001586_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001586_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001586_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001586_0_2 + 11) & 15;
  union RegisterBank_R001586_8613_0 u_var_1;
  union RegisterBank_R001586_8613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001586_8613_0(sec_r001586_0_1, sec_r001586_1_1, pub_r001586_2_1, pub_r001586_3_1);
  int helper_flow_0_2 = fn_R001586_8613_0(sec_r001586_0_2, sec_r001586_1_2, pub_r001586_2_2, pub_r001586_3_2);
  fn_R001586_8613_0_2(sec_r001586_0_1, sec_r001586_1_1, pub_r001586_2_1, pub_r001586_3_1, sec_r001586_0_2, sec_r001586_1_2, pub_r001586_2_2, pub_r001586_3_2);
  int helper_flow_1_1 = fn_R001586_8613_1(sec_r001586_1_1, sec_r001586_2_1, pub_r001586_3_1);
  int helper_flow_1_2 = fn_R001586_8613_1(sec_r001586_1_2, sec_r001586_2_2, pub_r001586_3_2);
  fn_R001586_8613_1_2(sec_r001586_1_1, sec_r001586_2_1, pub_r001586_3_1, sec_r001586_1_2, sec_r001586_2_2, pub_r001586_3_2);
  int helper_flow_2_1 = fn_R001586_8613_2(sec_r001586_2_1, sec_r001586_3_1, pub_r001586_4_1, pub_r001586_5_1, pub_r001586_6_1);
  int helper_flow_2_2 = fn_R001586_8613_2(sec_r001586_2_2, sec_r001586_3_2, pub_r001586_4_2, pub_r001586_5_2, pub_r001586_6_2);
  fn_R001586_8613_2_2(sec_r001586_2_1, sec_r001586_3_1, pub_r001586_4_1, pub_r001586_5_1, pub_r001586_6_1, sec_r001586_2_2, sec_r001586_3_2, pub_r001586_4_2, pub_r001586_5_2, pub_r001586_6_2);
  int helper_flow_3_1 = fn_R001586_8613_3(sec_r001586_3_1, pub_r001586_4_1, pub_r001586_5_1, pub_r001586_6_1, pub_r001586_7_1);
  int helper_flow_3_2 = fn_R001586_8613_3(sec_r001586_3_2, pub_r001586_4_2, pub_r001586_5_2, pub_r001586_6_2, pub_r001586_7_2);
  fn_R001586_8613_3_2(sec_r001586_3_1, pub_r001586_4_1, pub_r001586_5_1, pub_r001586_6_1, pub_r001586_7_1, sec_r001586_3_2, pub_r001586_4_2, pub_r001586_5_2, pub_r001586_6_2, pub_r001586_7_2);
  int helper_flow_4_1 = fn_R001586_8613_4(sec_r001586_4_1, sec_r001586_5_1, pub_r001586_6_1, pub_r001586_7_1, pub_r001586_8_1);
  int helper_flow_4_2 = fn_R001586_8613_4(sec_r001586_4_2, sec_r001586_5_2, pub_r001586_6_2, pub_r001586_7_2, pub_r001586_8_2);
  fn_R001586_8613_4_2(sec_r001586_4_1, sec_r001586_5_1, pub_r001586_6_1, pub_r001586_7_1, pub_r001586_8_1, sec_r001586_4_2, sec_r001586_5_2, pub_r001586_6_2, pub_r001586_7_2, pub_r001586_8_2);
  int helper_flow_5_1 = fn_R001586_8613_5(sec_r001586_5_1, pub_r001586_6_1, pub_r001586_7_1, pub_r001586_8_1, pub_r001586_9_1);
  int helper_flow_5_2 = fn_R001586_8613_5(sec_r001586_5_2, pub_r001586_6_2, pub_r001586_7_2, pub_r001586_8_2, pub_r001586_9_2);
  fn_R001586_8613_5_2(sec_r001586_5_1, pub_r001586_6_1, pub_r001586_7_1, pub_r001586_8_1, pub_r001586_9_1, sec_r001586_5_2, pub_r001586_6_2, pub_r001586_7_2, pub_r001586_8_2, pub_r001586_9_2);
  int helper_flow_6_1 = fn_R001586_8613_6(sec_r001586_6_1, sec_r001586_7_1, pub_r001586_8_1, pub_r001586_9_1);
  int helper_flow_6_2 = fn_R001586_8613_6(sec_r001586_6_2, sec_r001586_7_2, pub_r001586_8_2, pub_r001586_9_2);
  fn_R001586_8613_6_2(sec_r001586_6_1, sec_r001586_7_1, pub_r001586_8_1, pub_r001586_9_1, sec_r001586_6_2, sec_r001586_7_2, pub_r001586_8_2, pub_r001586_9_2);
  int helper_flow_7_1 = fn_R001586_8613_7(sec_r001586_7_1, sec_r001586_8_1);
  int helper_flow_7_2 = fn_R001586_8613_7(sec_r001586_7_2, sec_r001586_8_2);
  fn_R001586_8613_7_2(sec_r001586_7_1, sec_r001586_8_1, sec_r001586_7_2, sec_r001586_8_2);
  int stage_v_0_1 = ((helper_flow_3_1 + (pub_r001586_14_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_3_2 + (pub_r001586_14_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((pub_r001586_17_1 * 2) + 35) & 63;
  int stage_v_1_2 = ((pub_r001586_17_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001586_0_1 * 2) + 48) & 63;
  int stage_v_2_2 = ((pub_r001586_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001586_11_1 * 2) + 37) & 63;
  int stage_v_3_2 = ((pub_r001586_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001586_9_1 * 2) + 15) & 63;
  int stage_v_4_2 = ((pub_r001586_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001586_0_1 * 2) + 9) & 63;
  int stage_v_5_2 = ((pub_r001586_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((sec_r001586_18_1 + (pub_r001586_13_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001586_18_2 + (pub_r001586_13_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((pub_r001586_18_1 * 2) + 28) & 63;
  int stage_v_7_2 = ((pub_r001586_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001586_18_1 * 2) + 18) & 63;
  int stage_v_8_2 = ((pub_r001586_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((sec_r001586_20_1 + (pub_r001586_17_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((sec_r001586_20_2 + (pub_r001586_17_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((sec_r001586_8_1 + (pub_r001586_10_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((sec_r001586_8_2 + (pub_r001586_10_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((pub_r001586_11_1 * 2) + 15) & 63;
  int stage_v_11_2 = ((pub_r001586_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((sec_r001586_8_1 + (pub_r001586_16_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001586_8_2 + (pub_r001586_16_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((stage_v_12_1 + (pub_r001586_16_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((stage_v_12_2 + (pub_r001586_16_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((sec_r001586_0_1 + (pub_r001586_10_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((sec_r001586_0_2 + (pub_r001586_10_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((stage_v_10_1 + (pub_r001586_9_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((stage_v_10_2 + (pub_r001586_9_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((pub_r001586_18_1 * 2) + 41) & 63;
  int stage_v_16_2 = ((pub_r001586_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((sec_r001586_10_1 + (pub_r001586_5_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001586_10_2 + (pub_r001586_5_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((pub_r001586_16_1 * 2) + 21) & 63;
  int stage_v_18_2 = ((pub_r001586_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001586_13_1 * 2) + 12) & 63;
  int stage_v_19_2 = ((pub_r001586_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((sec_r001586_7_1 + (pub_r001586_13_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((sec_r001586_7_2 + (pub_r001586_13_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((stage_v_17_1 + (pub_r001586_6_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_17_2 + (pub_r001586_6_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((sec_r001586_13_1 + (pub_r001586_3_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((sec_r001586_13_2 + (pub_r001586_3_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((sec_r001586_18_1 + (pub_r001586_13_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((sec_r001586_18_2 + (pub_r001586_13_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((sec_r001586_18_1 + (pub_r001586_9_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((sec_r001586_18_2 + (pub_r001586_9_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((stage_v_12_1 + (pub_r001586_9_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((stage_v_12_2 + (pub_r001586_9_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((pub_r001586_4_1 * 2) + 32) & 63;
  int stage_v_26_2 = ((pub_r001586_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001586_4_1 * 2) + 31) & 63;
  int stage_v_27_2 = ((pub_r001586_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((helper_flow_7_1 + (pub_r001586_3_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((helper_flow_7_2 + (pub_r001586_3_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((helper_flow_1_1 + (pub_r001586_7_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((helper_flow_1_2 + (pub_r001586_7_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((sec_r001586_5_1 + (pub_r001586_2_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((sec_r001586_5_2 + (pub_r001586_2_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((pub_r001586_13_1 * 2) + 39) & 63;
  int stage_v_31_2 = ((pub_r001586_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((stage_v_6_1 + (pub_r001586_15_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((stage_v_6_2 + (pub_r001586_15_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((stage_v_24_1 + (pub_r001586_4_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((stage_v_24_2 + (pub_r001586_4_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((stage_v_9_1 + (pub_r001586_0_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((stage_v_9_2 + (pub_r001586_0_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((sec_r001586_19_1 + (pub_r001586_3_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((sec_r001586_19_2 + (pub_r001586_3_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((pub_r001586_12_1 * 2) + 23) & 63;
  int stage_v_36_2 = ((pub_r001586_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001586_14_1 * 2) + 42) & 63;
  int stage_v_37_2 = ((pub_r001586_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001586_6_1 * 2) + 50) & 63;
  int stage_v_38_2 = ((pub_r001586_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001586_3_1 * 2) + 47) & 63;
  int stage_v_39_2 = ((pub_r001586_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((stage_v_35_1 + (pub_r001586_6_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_35_2 + (pub_r001586_6_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((sec_r001586_2_1 + (pub_r001586_0_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((sec_r001586_2_2 + (pub_r001586_0_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((stage_v_9_1 + (pub_r001586_11_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((stage_v_9_2 + (pub_r001586_11_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((pub_r001586_16_1 * 2) + 50) & 63;
  int stage_v_43_2 = ((pub_r001586_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((stage_v_28_1 + (pub_r001586_10_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((stage_v_28_2 + (pub_r001586_10_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((stage_v_20_1 + (pub_r001586_7_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((stage_v_20_2 + (pub_r001586_7_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((helper_flow_6_1 + (pub_r001586_11_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((helper_flow_6_2 + (pub_r001586_11_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((pub_r001586_9_1 * 2) + 24) & 63;
  int stage_v_47_2 = ((pub_r001586_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001586_11_1 * 2) + 39) & 63;
  int stage_v_48_2 = ((pub_r001586_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((sec_r001586_17_1 + (pub_r001586_16_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((sec_r001586_17_2 + (pub_r001586_16_2 * 2)) + 152) & 127;
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
  int stage_v_50_1 = ((pub_r001586_4_1 * 2) + 7) & 63;
  int stage_v_50_2 = ((pub_r001586_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((sec_r001586_6_1 + (pub_r001586_13_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((sec_r001586_6_2 + (pub_r001586_13_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((sec_r001586_2_1 + (pub_r001586_10_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((sec_r001586_2_2 + (pub_r001586_10_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((pub_r001586_3_1 * 2) + 18) & 63;
  int stage_v_53_2 = ((pub_r001586_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((helper_flow_4_1 + (pub_r001586_9_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((helper_flow_4_2 + (pub_r001586_9_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((pub_r001586_14_1 * 2) + 45) & 63;
  int stage_v_55_2 = ((pub_r001586_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((stage_v_0_1 + (pub_r001586_4_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((stage_v_0_2 + (pub_r001586_4_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((pub_r001586_0_1 * 2) + 9) & 63;
  int stage_v_57_2 = ((pub_r001586_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((stage_v_34_1 + (pub_r001586_8_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_34_2 + (pub_r001586_8_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((pub_r001586_17_1 * 2) + 20) & 63;
  int stage_v_59_2 = ((pub_r001586_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((stage_v_51_1 + (pub_r001586_5_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_51_2 + (pub_r001586_5_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((pub_r001586_6_1 * 2) + 38) & 63;
  int stage_v_61_2 = ((pub_r001586_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001586_8_1 * 2) + 50) & 63;
  int stage_v_62_2 = ((pub_r001586_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((stage_v_54_1 + (pub_r001586_6_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_54_2 + (pub_r001586_6_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((stage_v_10_1 + (pub_r001586_11_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((stage_v_10_2 + (pub_r001586_11_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((stage_v_46_1 + (pub_r001586_5_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_46_2 + (pub_r001586_5_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((pub_r001586_13_1 * 2) + 24) & 63;
  int stage_v_66_2 = ((pub_r001586_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((sec_r001586_8_1 + (pub_r001586_15_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((sec_r001586_8_2 + (pub_r001586_15_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((stage_v_22_1 + (pub_r001586_13_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_22_2 + (pub_r001586_13_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((sec_r001586_13_1 + (pub_r001586_2_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((sec_r001586_13_2 + (pub_r001586_2_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((pub_r001586_16_1 * 2) + 37) & 63;
  int stage_v_70_2 = ((pub_r001586_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((sec_r001586_4_1 + (pub_r001586_17_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((sec_r001586_4_2 + (pub_r001586_17_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((pub_r001586_14_1 * 2) + 18) & 63;
  int stage_v_72_2 = ((pub_r001586_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((stage_v_20_1 + (pub_r001586_16_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_20_2 + (pub_r001586_16_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((stage_v_0_1 + (pub_r001586_1_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_0_2 + (pub_r001586_1_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((stage_v_20_1 + (pub_r001586_5_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_20_2 + (pub_r001586_5_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((sec_r001586_6_1 + (pub_r001586_2_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((sec_r001586_6_2 + (pub_r001586_2_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((stage_v_75_1 + (pub_r001586_1_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((stage_v_75_2 + (pub_r001586_1_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((stage_v_44_1 + (pub_r001586_0_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_44_2 + (pub_r001586_0_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((stage_v_40_1 + (pub_r001586_2_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_40_2 + (pub_r001586_2_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((stage_v_30_1 + (pub_r001586_5_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_30_2 + (pub_r001586_5_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((pub_r001586_6_1 * 2) + 29) & 63;
  int stage_v_81_2 = ((pub_r001586_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((stage_v_17_1 + (pub_r001586_0_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((stage_v_17_2 + (pub_r001586_0_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((stage_v_71_1 + (pub_r001586_10_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_71_2 + (pub_r001586_10_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((pub_r001586_7_1 * 2) + 42) & 63;
  int stage_v_84_2 = ((pub_r001586_7_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001586_4_1 * 2) + 46) & 63;
  int stage_v_85_2 = ((pub_r001586_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001586_1_1 * 2) + 35) & 63;
  int stage_v_86_2 = ((pub_r001586_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((stage_v_74_1 + (pub_r001586_6_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_74_2 + (pub_r001586_6_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((pub_r001586_18_1 * 2) + 11) & 63;
  int stage_v_88_2 = ((pub_r001586_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((sec_r001586_5_1 + (pub_r001586_14_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((sec_r001586_5_2 + (pub_r001586_14_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((stage_v_76_1 + (pub_r001586_12_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_76_2 + (pub_r001586_12_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((sec_r001586_13_1 + (pub_r001586_15_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((sec_r001586_13_2 + (pub_r001586_15_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((sec_r001586_17_1 + (pub_r001586_6_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((sec_r001586_17_2 + (pub_r001586_6_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((stage_v_91_1 + (pub_r001586_0_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_91_2 + (pub_r001586_0_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((sec_r001586_18_1 + (pub_r001586_18_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((sec_r001586_18_2 + (pub_r001586_18_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((helper_flow_7_1 + (pub_r001586_12_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((helper_flow_7_2 + (pub_r001586_12_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((stage_v_6_1 + (pub_r001586_15_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_6_2 + (pub_r001586_15_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((pub_r001586_12_1 * 2) + 15) & 63;
  int stage_v_97_2 = ((pub_r001586_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((stage_v_14_1 + (pub_r001586_5_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_14_2 + (pub_r001586_5_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((helper_flow_6_1 + (pub_r001586_1_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((helper_flow_6_2 + (pub_r001586_1_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((pub_r001586_18_1 * 2) + 25) & 63;
  int stage_v_100_2 = ((pub_r001586_18_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001586_9_1 * 2) + 27) & 63;
  int stage_v_101_2 = ((pub_r001586_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((stage_v_52_1 + (pub_r001586_8_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_52_2 + (pub_r001586_8_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((stage_v_35_1 + (pub_r001586_4_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_35_2 + (pub_r001586_4_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((pub_r001586_18_1 * 2) + 35) & 63;
  int stage_v_104_2 = ((pub_r001586_18_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((stage_v_33_1 + (pub_r001586_1_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_33_2 + (pub_r001586_1_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((sec_r001586_16_1 + (pub_r001586_16_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((sec_r001586_16_2 + (pub_r001586_16_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((pub_r001586_10_1 * 2) + 49) & 63;
  int stage_v_107_2 = ((pub_r001586_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((sec_r001586_0_1 + (pub_r001586_1_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((sec_r001586_0_2 + (pub_r001586_1_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_17_1 + (pub_r001586_5_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_17_2 + (pub_r001586_5_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((sec_r001586_2_1 + (pub_r001586_12_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((sec_r001586_2_2 + (pub_r001586_12_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((pub_r001586_12_1 * 2) + 24) & 63;
  int stage_v_111_2 = ((pub_r001586_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001586_3_1 * 2) + 31) & 63;
  int stage_v_112_2 = ((pub_r001586_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((sec_r001586_2_1 + (pub_r001586_16_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((sec_r001586_2_2 + (pub_r001586_16_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((stage_v_23_1 + (pub_r001586_2_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_23_2 + (pub_r001586_2_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((stage_v_0_1 + (pub_r001586_10_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_0_2 + (pub_r001586_10_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_68_1 + (pub_r001586_2_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_68_2 + (pub_r001586_2_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((stage_v_23_1 + (pub_r001586_11_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((stage_v_23_2 + (pub_r001586_11_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((stage_v_6_1 + (pub_r001586_5_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_6_2 + (pub_r001586_5_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((pub_r001586_10_1 * 2) + 46) & 63;
  int stage_v_119_2 = ((pub_r001586_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((stage_v_14_1 + (pub_r001586_10_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_14_2 + (pub_r001586_10_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((pub_r001586_8_1 * 2) + 16) & 63;
  int stage_v_121_2 = ((pub_r001586_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((stage_v_20_1 + (pub_r001586_4_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_20_2 + (pub_r001586_4_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((sec_r001586_11_1 + (pub_r001586_11_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((sec_r001586_11_2 + (pub_r001586_11_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((pub_r001586_15_1 * 2) + 37) & 63;
  int stage_v_124_2 = ((pub_r001586_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_105_1 + (pub_r001586_2_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_105_2 + (pub_r001586_2_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((pub_r001586_10_1 * 2) + 35) & 63;
  int stage_v_126_2 = ((pub_r001586_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001586_7_1 * 2) + 7) & 63;
  int stage_v_127_2 = ((pub_r001586_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001586_7_1 * 2) + 34) & 63;
  int stage_v_128_2 = ((pub_r001586_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((stage_v_91_1 + (pub_r001586_6_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_91_2 + (pub_r001586_6_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((stage_v_44_1 + (pub_r001586_0_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_44_2 + (pub_r001586_0_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((pub_r001586_17_1 * 2) + 40) & 63;
  int stage_v_131_2 = ((pub_r001586_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001586_14_1 * 2) + 42) & 63;
  int stage_v_132_2 = ((pub_r001586_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001586_6_1 * 2) + 28) & 63;
  int stage_v_133_2 = ((pub_r001586_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001586_17_1 * 2) + 19) & 63;
  int stage_v_134_2 = ((pub_r001586_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((stage_v_45_1 + (pub_r001586_17_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_45_2 + (pub_r001586_17_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((stage_v_15_1 + (pub_r001586_0_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_15_2 + (pub_r001586_0_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_75_1 + (pub_r001586_6_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_75_2 + (pub_r001586_6_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((stage_v_10_1 + (pub_r001586_7_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_10_2 + (pub_r001586_7_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((stage_v_0_1 + (pub_r001586_6_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((stage_v_0_2 + (pub_r001586_6_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((sec_r001586_6_1 + (pub_r001586_18_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((sec_r001586_6_2 + (pub_r001586_18_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((stage_v_130_1 + (pub_r001586_0_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_130_2 + (pub_r001586_0_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((stage_v_102_1 + (pub_r001586_12_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_102_2 + (pub_r001586_12_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((stage_v_114_1 + (pub_r001586_2_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_114_2 + (pub_r001586_2_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((sec_r001586_0_1 + (pub_r001586_11_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((sec_r001586_0_2 + (pub_r001586_11_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((stage_v_41_1 + (pub_r001586_14_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_41_2 + (pub_r001586_14_2 * 2)) + 440) & 127;
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
  int stage_v_146_1 = ((sec_r001586_2_1 + (pub_r001586_3_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((sec_r001586_2_2 + (pub_r001586_3_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((pub_r001586_17_1 * 2) + 46) & 63;
  int stage_v_147_2 = ((pub_r001586_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((sec_r001586_19_1 + (pub_r001586_7_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((sec_r001586_19_2 + (pub_r001586_7_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((stage_v_125_1 + (pub_r001586_8_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((stage_v_125_2 + (pub_r001586_8_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((pub_r001586_10_1 * 2) + 26) & 63;
  int stage_v_150_2 = ((pub_r001586_10_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((sec_r001586_19_1 + (pub_r001586_6_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((sec_r001586_19_2 + (pub_r001586_6_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((stage_v_33_1 + (pub_r001586_17_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_33_2 + (pub_r001586_17_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((stage_v_94_1 + (pub_r001586_13_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_94_2 + (pub_r001586_13_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((stage_v_103_1 + (pub_r001586_5_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((stage_v_103_2 + (pub_r001586_5_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((stage_v_33_1 + (pub_r001586_4_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_33_2 + (pub_r001586_4_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((stage_v_83_1 + (pub_r001586_15_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_83_2 + (pub_r001586_15_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((stage_v_75_1 + (pub_r001586_13_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_75_2 + (pub_r001586_13_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((stage_v_0_1 + (pub_r001586_9_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_0_2 + (pub_r001586_9_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((sec_r001586_20_1 + (pub_r001586_8_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((sec_r001586_20_2 + (pub_r001586_8_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_90_1 + (pub_r001586_13_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_90_2 + (pub_r001586_13_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((pub_r001586_0_1 * 2) + 42) & 63;
  int stage_v_161_2 = ((pub_r001586_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((helper_flow_3_1 + (pub_r001586_10_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((helper_flow_3_2 + (pub_r001586_10_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((pub_r001586_1_1 * 2) + 12) & 63;
  int stage_v_163_2 = ((pub_r001586_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_21_1 + (pub_r001586_6_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_21_2 + (pub_r001586_6_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((stage_v_145_1 + (pub_r001586_15_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_145_2 + (pub_r001586_15_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_17_1 + (pub_r001586_9_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_17_2 + (pub_r001586_9_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((pub_r001586_14_1 * 2) + 34) & 63;
  int stage_v_167_2 = ((pub_r001586_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001586_8_1 * 2) + 49) & 63;
  int stage_v_168_2 = ((pub_r001586_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((stage_v_109_1 + (pub_r001586_8_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_109_2 + (pub_r001586_8_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((pub_r001586_12_1 * 2) + 17) & 63;
  int stage_v_170_2 = ((pub_r001586_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((stage_v_65_1 + (pub_r001586_14_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_65_2 + (pub_r001586_14_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((stage_v_58_1 + (pub_r001586_13_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_58_2 + (pub_r001586_13_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((stage_v_110_1 + (pub_r001586_0_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_110_2 + (pub_r001586_0_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((stage_v_79_1 + (pub_r001586_12_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_79_2 + (pub_r001586_12_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((pub_r001586_0_1 * 2) + 39) & 63;
  int stage_v_175_2 = ((pub_r001586_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001586_4_1 * 2) + 6) & 63;
  int stage_v_176_2 = ((pub_r001586_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001586_2_1 * 2) + 10) & 63;
  int stage_v_177_2 = ((pub_r001586_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((stage_v_71_1 + (pub_r001586_2_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_71_2 + (pub_r001586_2_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((stage_v_98_1 + (pub_r001586_16_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_98_2 + (pub_r001586_16_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((stage_v_95_1 + (pub_r001586_13_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_95_2 + (pub_r001586_13_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((stage_v_94_1 + (pub_r001586_1_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_94_2 + (pub_r001586_1_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((stage_v_98_1 + (pub_r001586_2_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_98_2 + (pub_r001586_2_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((helper_flow_0_1 + (pub_r001586_10_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((helper_flow_0_2 + (pub_r001586_10_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((pub_r001586_16_1 * 2) + 33) & 63;
  int stage_v_184_2 = ((pub_r001586_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((helper_flow_3_1 + (pub_r001586_5_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((helper_flow_3_2 + (pub_r001586_5_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((pub_r001586_12_1 * 2) + 11) & 63;
  int stage_v_186_2 = ((pub_r001586_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001586_10_1 * 2) + 44) & 63;
  int stage_v_187_2 = ((pub_r001586_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001586_0_1 * 2) + 39) & 63;
  int stage_v_188_2 = ((pub_r001586_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((stage_v_151_1 + (pub_r001586_14_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_151_2 + (pub_r001586_14_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((stage_v_143_1 + (pub_r001586_4_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_143_2 + (pub_r001586_4_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((pub_r001586_5_1 * 2) + 14) & 63;
  int stage_v_191_2 = ((pub_r001586_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001586_13_1 * 2) + 29) & 63;
  int stage_v_192_2 = ((pub_r001586_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001586_11_1 * 2) + 5) & 63;
  int stage_v_193_2 = ((pub_r001586_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((helper_flow_3_1 + (pub_r001586_18_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((helper_flow_3_2 + (pub_r001586_18_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((sec_r001586_12_1 + (pub_r001586_18_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((sec_r001586_12_2 + (pub_r001586_18_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((pub_r001586_8_1 * 2) + 43) & 63;
  int stage_v_196_2 = ((pub_r001586_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((stage_v_82_1 + (pub_r001586_6_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_82_2 + (pub_r001586_6_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((sec_r001586_15_1 + (pub_r001586_0_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((sec_r001586_15_2 + (pub_r001586_0_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_149_1 + (pub_r001586_1_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_149_2 + (pub_r001586_1_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((pub_r001586_9_1 * 2) + 31) & 63;
  int stage_v_200_2 = ((pub_r001586_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((stage_v_6_1 + (pub_r001586_3_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_6_2 + (pub_r001586_3_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_140_1 + (pub_r001586_5_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_140_2 + (pub_r001586_5_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((stage_v_95_1 + (pub_r001586_17_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((stage_v_95_2 + (pub_r001586_17_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((sec_r001586_5_1 + (pub_r001586_12_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((sec_r001586_5_2 + (pub_r001586_12_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((pub_r001586_1_1 * 2) + 12) & 63;
  int stage_v_205_2 = ((pub_r001586_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001586_0_1 * 2) + 8) & 63;
  int stage_v_206_2 = ((pub_r001586_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((stage_v_152_1 + (pub_r001586_5_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((stage_v_152_2 + (pub_r001586_5_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((stage_v_9_1 + (pub_r001586_10_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_9_2 + (pub_r001586_10_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((pub_r001586_1_1 * 2) + 36) & 63;
  int stage_v_209_2 = ((pub_r001586_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((sec_r001586_13_1 + (pub_r001586_18_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((sec_r001586_13_2 + (pub_r001586_18_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((stage_v_166_1 + (pub_r001586_16_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((stage_v_166_2 + (pub_r001586_16_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((pub_r001586_0_1 * 2) + 12) & 63;
  int stage_v_212_2 = ((pub_r001586_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((stage_v_95_1 + (pub_r001586_7_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((stage_v_95_2 + (pub_r001586_7_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((stage_v_120_1 + (pub_r001586_16_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_120_2 + (pub_r001586_16_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((sec_r001586_16_1 + (pub_r001586_17_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((sec_r001586_16_2 + (pub_r001586_17_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((sec_r001586_4_1 + (pub_r001586_9_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((sec_r001586_4_2 + (pub_r001586_9_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((stage_v_158_1 + (pub_r001586_14_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_158_2 + (pub_r001586_14_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((stage_v_45_1 + (pub_r001586_4_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_45_2 + (pub_r001586_4_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((stage_v_190_1 + (pub_r001586_17_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_190_2 + (pub_r001586_17_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((stage_v_129_1 + (pub_r001586_0_1 * 2)) + 665) & 127;
  int stage_v_220_2 = ((stage_v_129_2 + (pub_r001586_0_2 * 2)) + 665) & 127;
  if (stage_v_220_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_220_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_220_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_220_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_221_1 = ((stage_v_79_1 + (pub_r001586_0_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((stage_v_79_2 + (pub_r001586_0_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((pub_r001586_17_1 * 2) + 10) & 63;
  int stage_v_222_2 = ((pub_r001586_17_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001586_12_1 * 2) + 29) & 63;
  int stage_v_223_2 = ((pub_r001586_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((stage_v_122_1 + (pub_r001586_7_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((stage_v_122_2 + (pub_r001586_7_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((stage_v_178_1 + (pub_r001586_8_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_178_2 + (pub_r001586_8_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001586_1_1 != sec_r001586_1_2);
  __CPROVER_assume(pub_r001586_1_1 == pub_r001586_1_2);
  __CPROVER_assume(pub_r001586_11_1 == pub_r001586_11_2);
  __CPROVER_assume(pub_r001586_16_1 == pub_r001586_16_2);
  __CPROVER_assume(pub_r001586_13_1 == pub_r001586_13_2);
  __CPROVER_assume(sec_r001586_12_1 != sec_r001586_12_2);
  __CPROVER_assume(pub_r001586_18_1 == pub_r001586_18_2);
  __CPROVER_assume(pub_r001586_8_1 == pub_r001586_8_2);
  __CPROVER_assume(sec_r001586_19_1 != sec_r001586_19_2);
  __CPROVER_assume(pub_r001586_2_1 == pub_r001586_2_2);
  __CPROVER_assume(sec_r001586_0_1 != sec_r001586_0_2);
  __CPROVER_assume(pub_r001586_17_1 == pub_r001586_17_2);
  __CPROVER_assume(sec_r001586_14_1 != sec_r001586_14_2);
  __CPROVER_assume(sec_r001586_6_1 != sec_r001586_6_2);
  __CPROVER_assume(sec_r001586_8_1 != sec_r001586_8_2);
  __CPROVER_assume(sec_r001586_4_1 != sec_r001586_4_2);
  __CPROVER_assume(sec_r001586_5_1 != sec_r001586_5_2);
  __CPROVER_assume(sec_r001586_15_1 != sec_r001586_15_2);
  __CPROVER_assume(pub_r001586_3_1 == pub_r001586_3_2);
  __CPROVER_assume(sec_r001586_11_1 != sec_r001586_11_2);
  __CPROVER_assume(sec_r001586_10_1 != sec_r001586_10_2);
  __CPROVER_assume(sec_r001586_20_1 != sec_r001586_20_2);
  __CPROVER_assume(pub_r001586_9_1 == pub_r001586_9_2);
  __CPROVER_assume(sec_r001586_2_1 != sec_r001586_2_2);
  __CPROVER_assume(sec_r001586_7_1 != sec_r001586_7_2);
  __CPROVER_assume(pub_r001586_7_1 == pub_r001586_7_2);
  __CPROVER_assume(sec_r001586_16_1 != sec_r001586_16_2);
  __CPROVER_assume(pub_r001586_14_1 == pub_r001586_14_2);
  __CPROVER_assume(sec_r001586_17_1 != sec_r001586_17_2);
  __CPROVER_assume(sec_r001586_9_1 != sec_r001586_9_2);
  __CPROVER_assume(sec_r001586_18_1 != sec_r001586_18_2);
  __CPROVER_assume(pub_r001586_6_1 == pub_r001586_6_2);
  __CPROVER_assume(pub_r001586_10_1 == pub_r001586_10_2);
  __CPROVER_assume(pub_r001586_15_1 == pub_r001586_15_2);
  __CPROVER_assume(pub_r001586_0_1 == pub_r001586_0_2);
  __CPROVER_assume(sec_r001586_3_1 != sec_r001586_3_2);
  __CPROVER_assume(sec_r001586_13_1 != sec_r001586_13_2);
  __CPROVER_assume(pub_r001586_12_1 == pub_r001586_12_2);
  __CPROVER_assume(pub_r001586_5_1 == pub_r001586_5_2);
  __CPROVER_assume(pub_r001586_4_1 == pub_r001586_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.tag == st_var_1_2.tag);
  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  assert(st_var_1_1.iv == st_var_1_2.iv);
  assert(st_var_1_1.flags == st_var_1_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  assert(st_var_2_1.balance == st_var_2_2.balance);
  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.fee == st_var_2_2.fee);
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
  assert(helper_flow_7_1 == helper_flow_7_2);
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
}


