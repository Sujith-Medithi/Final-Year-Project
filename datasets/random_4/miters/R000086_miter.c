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
struct CipherContext_R000086_8613_0
{
  unsigned char tag;
  int round_key;
  int flags;
  int nonce;
  int buffer[3];
};
struct EventLog_R000086_8613_1
{
  int facility;
  short seq;
  unsigned char timestamp;
  int buffer[3];
};
union PacketPayload_R000086_8613_0
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
void fn_R000086_8613_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000086_8613_1 st_1 = {0};
  struct EventLog_R000086_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int scale_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_74_1) & 63;
  aux_2 = (aux_2 + scale_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_63_1 > 44)
  {
    acc_1 = ((acc_1 + (index_reg_63_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_63_2 > 44)
  {
    acc_2 = ((acc_2 + (index_reg_63_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_63_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_74_1 == scale_74_2);
  assert(index_reg_63_1 == index_reg_63_2);
}

int fn_R000086_8613_0(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000086_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int scale_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_74) & 63;
  acc ^= aux;
  int index_reg_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_63 > 44)
  {
    acc = ((acc + (index_reg_63 * 2)) + 5) & 127;
    aux ^= index_reg_63 & 15;
  }
  else
  {
    acc = ((acc - index_reg_63) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000086_8613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000086_8613_1 st_1 = {0};
  struct EventLog_R000086_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int segment_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_48_1) & 63;
  aux_2 = (aux_2 + segment_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_41_1 = local_arr_1[aux_1 % 3];
  int delta_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_41_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_48_1 == segment_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_41_1 == delta_41_2);
}

int fn_R000086_8613_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000086_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int segment_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_48) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_41 = local_arr[aux % 3];
  acc = (acc + (delta_41 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000086_8613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000086_8613_1 st_1 = {0};
  struct EventLog_R000086_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int accumulator_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_47_1) & 63;
  aux_2 = (aux_2 + accumulator_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_39_1 > 35)
  {
    acc_1 = ((acc_1 + (parity_39_1 * 2)) + 5) & 127;
    aux_1 ^= parity_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_39_2 > 35)
  {
    acc_2 = ((acc_2 + (parity_39_2 * 2)) + 5) & 127;
    aux_2 ^= parity_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_39_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_47_1 = 0;
  int anchor_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_47_1 = ((anchor_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_47_2 = ((anchor_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_47_1) & 127;
    acc_2 = (acc_2 + anchor_47_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_47_1 == accumulator_47_2);
  assert(parity_39_1 == parity_39_2);
  assert(anchor_47_1 == anchor_47_2);
}

int fn_R000086_8613_2(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000086_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int accumulator_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_47) & 63;
  acc ^= aux;
  int parity_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_39 > 35)
  {
    acc = ((acc + (parity_39 * 2)) + 5) & 127;
    aux ^= parity_39 & 15;
  }
  else
  {
    acc = ((acc - parity_39) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_47 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_47 = ((anchor_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_47) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000086_8613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st_1 = {0};
  struct CipherContext_R000086_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int metric_95_1 = 0;
  int metric_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_95_1 = ((metric_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_95_2 = ((metric_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_95_1) & 127;
    acc_2 = (acc_2 + metric_95_2) & 127;
  }

  int cursor_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_47_1 > 42)
  {
    acc_1 = ((acc_1 + (cursor_47_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_47_2 > 42)
  {
    acc_2 = ((acc_2 + (cursor_47_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_47_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_45_1)
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

  switch (checksum_45_2)
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
  int cursor_63_1 = local_arr_1[aux_1 % 3];
  int cursor_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_63_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_95_1 == metric_95_2);
  assert(cursor_47_1 == cursor_47_2);
  assert(checksum_45_1 == checksum_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_63_1 == cursor_63_2);
}

int fn_R000086_8613_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int metric_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_95 = ((metric_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_95) & 127;
  }

  int cursor_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_47 > 42)
  {
    acc = ((acc + (cursor_47 * 2)) + 5) & 127;
    aux ^= cursor_47 & 15;
  }
  else
  {
    acc = ((acc - cursor_47) + 11) & 127;
    aux += 3;
  }
  int checksum_45 = (aux + st.buffer[1]) & 3;
  switch (checksum_45)
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
  int cursor_63 = local_arr[aux % 3];
  acc = (acc + (cursor_63 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000086_8613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st_1 = {0};
  struct CipherContext_R000086_8613_0 st_2 = {0};
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
  int index_reg_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_96_1) & 63;
  aux_2 = (aux_2 + index_reg_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_99_1 = local_arr_1[aux_1 % 3];
  int delta_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_99_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_96_1 == index_reg_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_99_1 == delta_99_2);
}

int fn_R000086_8613_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_96) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_99 = local_arr[aux % 3];
  acc = (acc + (delta_99 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000086_8613_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st_1 = {0};
  struct CipherContext_R000086_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int vector_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_26_1)
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

  switch (vector_26_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_54_1 = local_arr_1[aux_1 % 3];
  int cursor_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_54_2 * 2)) & 127;
  int bound_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_61_1 > 28)
  {
    acc_1 = ((acc_1 + (bound_61_1 * 2)) + 5) & 127;
    aux_1 ^= bound_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_61_2 > 28)
  {
    acc_2 = ((acc_2 + (bound_61_2 * 2)) + 5) & 127;
    aux_2 ^= bound_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_61_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_26_1 == vector_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_54_1 == cursor_54_2);
  assert(bound_61_1 == bound_61_2);
}

int fn_R000086_8613_5(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int vector_26 = (aux + st.buffer[1]) & 3;
  switch (vector_26)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int cursor_54 = local_arr[aux % 3];
  acc = (acc + (cursor_54 * 2)) & 127;
  int bound_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_61 > 28)
  {
    acc = ((acc + (bound_61 * 2)) + 5) & 127;
    aux ^= bound_61 & 15;
  }
  else
  {
    acc = ((acc - bound_61) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000086_8613_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st_1 = {0};
  struct CipherContext_R000086_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int metric_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_41_1)
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

  switch (metric_41_2)
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

  int residue_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_23_1 > 27)
  {
    acc_1 = ((acc_1 + (residue_23_1 * 2)) + 5) & 127;
    aux_1 ^= residue_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_23_2 > 27)
  {
    acc_2 = ((acc_2 + (residue_23_2 * 2)) + 5) & 127;
    aux_2 ^= residue_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_37_1 = local_arr_1[aux_1 % 3];
  int threshold_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_37_2 * 2)) & 127;
  int offset_64_1 = 0;
  int offset_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_64_1 = ((offset_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_64_2 = ((offset_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_64_1) & 127;
    acc_2 = (acc_2 + offset_64_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_41_1 == metric_41_2);
  assert(residue_23_1 == residue_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_37_1 == threshold_37_2);
  assert(offset_64_1 == offset_64_2);
}

int fn_R000086_8613_6(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int metric_41 = (aux + st.buffer[1]) & 3;
  switch (metric_41)
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

  int residue_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_23 > 27)
  {
    acc = ((acc + (residue_23 * 2)) + 5) & 127;
    aux ^= residue_23 & 15;
  }
  else
  {
    acc = ((acc - residue_23) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_37 = local_arr[aux % 3];
  acc = (acc + (threshold_37 * 2)) & 127;
  int offset_64 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_64 = ((offset_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_64) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000086_8613_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000086_8613_1 st_1 = {0};
  struct EventLog_R000086_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int cursor_55_1 = 0;
  int cursor_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_55_1 = ((cursor_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_55_2 = ((cursor_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_55_1) & 127;
    acc_2 = (acc_2 + cursor_55_2) & 127;
  }

  int weight_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_75_1) & 63;
  aux_2 = (aux_2 + weight_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_16_1)
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

  switch (sample_16_2)
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

  int bound_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_61_1 > 21)
  {
    acc_1 = ((acc_1 + (bound_61_1 * 2)) + 5) & 127;
    aux_1 ^= bound_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_61_2 > 21)
  {
    acc_2 = ((acc_2 + (bound_61_2 * 2)) + 5) & 127;
    aux_2 ^= bound_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_61_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_55_1 == cursor_55_2);
  assert(weight_75_1 == weight_75_2);
  assert(sample_16_1 == sample_16_2);
  assert(bound_61_1 == bound_61_2);
}

int fn_R000086_8613_7(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000086_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int cursor_55 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_55 = ((cursor_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_55) & 127;
  }

  int weight_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_75) & 63;
  acc ^= aux;
  int sample_16 = (aux + st.buffer[1]) & 3;
  switch (sample_16)
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

  int bound_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_61 > 21)
  {
    acc = ((acc + (bound_61 * 2)) + 5) & 127;
    aux ^= bound_61 & 15;
  }
  else
  {
    acc = ((acc - bound_61) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000086_8613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st_1 = {0};
  struct CipherContext_R000086_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int tally_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_24_1) & 63;
  aux_2 = (aux_2 + tally_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_13_1 = local_arr_1[aux_1 % 3];
  int stride_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_13_2 * 2)) & 127;
  int tally_86_1 = 0;
  int tally_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_86_1 = ((tally_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_86_2 = ((tally_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_86_1) & 127;
    acc_2 = (acc_2 + tally_86_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_24_1 == tally_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_13_1 == stride_13_2);
  assert(tally_86_1 == tally_86_2);
}

int fn_R000086_8613_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int tally_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_24) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_13 = local_arr[aux % 3];
  acc = (acc + (stride_13 * 2)) & 127;
  int tally_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_86 = ((tally_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_86) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000086_8613_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st_1 = {0};
  struct CipherContext_R000086_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int threshold_34_1 = 0;
  int threshold_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_34_1 = ((threshold_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_34_2 = ((threshold_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_34_1) & 127;
    acc_2 = (acc_2 + threshold_34_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_34_1 == threshold_34_2);
}

int fn_R000086_8613_9(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int threshold_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_34 = ((threshold_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_34) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000086_8613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st_1 = {0};
  struct CipherContext_R000086_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int phase_95_1 = 0;
  int phase_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_95_1 = ((phase_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_95_2 = ((phase_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_95_1) & 127;
    acc_2 = (acc_2 + phase_95_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_54_1 = local_arr_1[aux_1 % 3];
  int bound_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_54_2 * 2)) & 127;
  int segment_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_42_1) & 63;
  aux_2 = (aux_2 + segment_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_72_1)
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

  switch (factor_72_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_95_1 == phase_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_54_1 == bound_54_2);
  assert(segment_42_1 == segment_42_2);
  assert(factor_72_1 == factor_72_2);
}

int fn_R000086_8613_10(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int phase_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_95 = ((phase_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_95) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int bound_54 = local_arr[aux % 3];
  acc = (acc + (bound_54 * 2)) & 127;
  int segment_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_42) & 63;
  acc ^= aux;
  int factor_72 = (aux + st.buffer[1]) & 3;
  switch (factor_72)
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

void fn_R000086_8613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000086_8613_1 st_1 = {0};
  struct EventLog_R000086_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_62_1 = 0;
  int segment_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_62_1 = ((segment_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_62_2 = ((segment_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_62_1) & 127;
    acc_2 = (acc_2 + segment_62_2) & 127;
  }

  int window_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_35_1) & 63;
  aux_2 = (aux_2 + window_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_81_1)
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

  switch (metric_81_2)
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
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_62_1 == segment_62_2);
  assert(window_35_1 == window_35_2);
  assert(metric_81_1 == metric_81_2);
}

int fn_R000086_8613_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000086_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_62 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_62 = ((segment_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_62) & 127;
  }

  int window_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_35) & 63;
  acc ^= aux;
  int metric_81 = (aux + st.buffer[1]) & 3;
  switch (metric_81)
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

void fn_R000086_8613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000086_8613_1 st_1 = {0};
  struct EventLog_R000086_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_75_1 = local_arr_1[aux_1 % 3];
  int weight_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_75_2 * 2)) & 127;
  int segment_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_13_1)
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

  switch (segment_13_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_75_1 == weight_75_2);
  assert(segment_13_1 == segment_13_2);
}

int fn_R000086_8613_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000086_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int weight_75 = local_arr[aux % 3];
  acc = (acc + (weight_75 * 2)) & 127;
  int segment_13 = (aux + st.buffer[1]) & 3;
  switch (segment_13)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000086_8613_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st_1 = {0};
  struct CipherContext_R000086_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int stride_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_57_1)
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

  switch (stride_57_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_64_1 = local_arr_1[aux_1 % 3];
  int stride_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_64_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_57_1 == stride_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_64_1 == stride_64_2);
}

int fn_R000086_8613_13(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000086_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int stride_57 = (aux + st.buffer[1]) & 3;
  switch (stride_57)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int stride_64 = local_arr[aux % 3];
  acc = (acc + (stride_64 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000086_0_1;
  int sec_r000086_0_2;
  int sec_r000086_1_1;
  int sec_r000086_1_2;
  int sec_r000086_2_1;
  int sec_r000086_2_2;
  int sec_r000086_3_1;
  int sec_r000086_3_2;
  int sec_r000086_4_1;
  int sec_r000086_4_2;
  int sec_r000086_5_1;
  int sec_r000086_5_2;
  int sec_r000086_6_1;
  int sec_r000086_6_2;
  int sec_r000086_7_1;
  int sec_r000086_7_2;
  int sec_r000086_8_1;
  int sec_r000086_8_2;
  int sec_r000086_9_1;
  int sec_r000086_9_2;
  int sec_r000086_10_1;
  int sec_r000086_10_2;
  int sec_r000086_11_1;
  int sec_r000086_11_2;
  int sec_r000086_12_1;
  int sec_r000086_12_2;
  int sec_r000086_13_1;
  int sec_r000086_13_2;
  int sec_r000086_14_1;
  int sec_r000086_14_2;
  int sec_r000086_15_1;
  int sec_r000086_15_2;
  int sec_r000086_16_1;
  int sec_r000086_16_2;
  int sec_r000086_17_1;
  int sec_r000086_17_2;
  int sec_r000086_18_1;
  int sec_r000086_18_2;
  int sec_r000086_19_1;
  int sec_r000086_19_2;
  int sec_r000086_20_1;
  int sec_r000086_20_2;
  int sec_r000086_21_1;
  int sec_r000086_21_2;
  int pub_r000086_0_1;
  int pub_r000086_0_2;
  int pub_r000086_1_1;
  int pub_r000086_1_2;
  int pub_r000086_2_1;
  int pub_r000086_2_2;
  int pub_r000086_3_1;
  int pub_r000086_3_2;
  int pub_r000086_4_1;
  int pub_r000086_4_2;
  int pub_r000086_5_1;
  int pub_r000086_5_2;
  int pub_r000086_6_1;
  int pub_r000086_6_2;
  int pub_r000086_7_1;
  int pub_r000086_7_2;
  int pub_r000086_8_1;
  int pub_r000086_8_2;
  int pub_r000086_9_1;
  int pub_r000086_9_2;
  int pub_r000086_10_1;
  int pub_r000086_10_2;
  int pub_r000086_11_1;
  int pub_r000086_11_2;
  int pub_r000086_12_1;
  int pub_r000086_12_2;
  int pub_r000086_13_1;
  int pub_r000086_13_2;
  int pub_r000086_14_1;
  int pub_r000086_14_2;
  int pub_r000086_15_1;
  int pub_r000086_15_2;
  int pub_r000086_16_1;
  int pub_r000086_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000086_0_1 >= (-100)) && (pub_r000086_0_1 <= 100));
  __CPROVER_assume((pub_r000086_0_2 >= (-100)) && (pub_r000086_0_2 <= 100));
  __CPROVER_assume((pub_r000086_1_1 >= (-100)) && (pub_r000086_1_1 <= 100));
  __CPROVER_assume((pub_r000086_1_2 >= (-100)) && (pub_r000086_1_2 <= 100));
  __CPROVER_assume((pub_r000086_2_1 >= (-100)) && (pub_r000086_2_1 <= 100));
  __CPROVER_assume((pub_r000086_2_2 >= (-100)) && (pub_r000086_2_2 <= 100));
  __CPROVER_assume((pub_r000086_3_1 >= (-100)) && (pub_r000086_3_1 <= 100));
  __CPROVER_assume((pub_r000086_3_2 >= (-100)) && (pub_r000086_3_2 <= 100));
  __CPROVER_assume((pub_r000086_4_1 >= (-100)) && (pub_r000086_4_1 <= 100));
  __CPROVER_assume((pub_r000086_4_2 >= (-100)) && (pub_r000086_4_2 <= 100));
  __CPROVER_assume((pub_r000086_5_1 >= (-100)) && (pub_r000086_5_1 <= 100));
  __CPROVER_assume((pub_r000086_5_2 >= (-100)) && (pub_r000086_5_2 <= 100));
  __CPROVER_assume((pub_r000086_6_1 >= (-100)) && (pub_r000086_6_1 <= 100));
  __CPROVER_assume((pub_r000086_6_2 >= (-100)) && (pub_r000086_6_2 <= 100));
  __CPROVER_assume((pub_r000086_7_1 >= (-100)) && (pub_r000086_7_1 <= 100));
  __CPROVER_assume((pub_r000086_7_2 >= (-100)) && (pub_r000086_7_2 <= 100));
  __CPROVER_assume((pub_r000086_8_1 >= (-100)) && (pub_r000086_8_1 <= 100));
  __CPROVER_assume((pub_r000086_8_2 >= (-100)) && (pub_r000086_8_2 <= 100));
  __CPROVER_assume((pub_r000086_9_1 >= (-100)) && (pub_r000086_9_1 <= 100));
  __CPROVER_assume((pub_r000086_9_2 >= (-100)) && (pub_r000086_9_2 <= 100));
  __CPROVER_assume((pub_r000086_10_1 >= (-100)) && (pub_r000086_10_1 <= 100));
  __CPROVER_assume((pub_r000086_10_2 >= (-100)) && (pub_r000086_10_2 <= 100));
  __CPROVER_assume((pub_r000086_11_1 >= (-100)) && (pub_r000086_11_1 <= 100));
  __CPROVER_assume((pub_r000086_11_2 >= (-100)) && (pub_r000086_11_2 <= 100));
  __CPROVER_assume((pub_r000086_12_1 >= (-100)) && (pub_r000086_12_1 <= 100));
  __CPROVER_assume((pub_r000086_12_2 >= (-100)) && (pub_r000086_12_2 <= 100));
  __CPROVER_assume((pub_r000086_13_1 >= (-100)) && (pub_r000086_13_1 <= 100));
  __CPROVER_assume((pub_r000086_13_2 >= (-100)) && (pub_r000086_13_2 <= 100));
  __CPROVER_assume((pub_r000086_14_1 >= (-100)) && (pub_r000086_14_1 <= 100));
  __CPROVER_assume((pub_r000086_14_2 >= (-100)) && (pub_r000086_14_2 <= 100));
  __CPROVER_assume((pub_r000086_15_1 >= (-100)) && (pub_r000086_15_1 <= 100));
  __CPROVER_assume((pub_r000086_15_2 >= (-100)) && (pub_r000086_15_2 <= 100));
  __CPROVER_assume((pub_r000086_16_1 >= (-100)) && (pub_r000086_16_1 <= 100));
  __CPROVER_assume((pub_r000086_16_2 >= (-100)) && (pub_r000086_16_2 <= 100));
  __CPROVER_assume((sec_r000086_0_1 >= 0) && (sec_r000086_0_1 <= 255));
  __CPROVER_assume((sec_r000086_0_2 >= 0) && (sec_r000086_0_2 <= 255));
  __CPROVER_assume((sec_r000086_1_1 >= 0) && (sec_r000086_1_1 <= 255));
  __CPROVER_assume((sec_r000086_1_2 >= 0) && (sec_r000086_1_2 <= 255));
  __CPROVER_assume((sec_r000086_2_1 >= 0) && (sec_r000086_2_1 <= 255));
  __CPROVER_assume((sec_r000086_2_2 >= 0) && (sec_r000086_2_2 <= 255));
  __CPROVER_assume((sec_r000086_3_1 >= 0) && (sec_r000086_3_1 <= 255));
  __CPROVER_assume((sec_r000086_3_2 >= 0) && (sec_r000086_3_2 <= 255));
  __CPROVER_assume((sec_r000086_4_1 >= 0) && (sec_r000086_4_1 <= 255));
  __CPROVER_assume((sec_r000086_4_2 >= 0) && (sec_r000086_4_2 <= 255));
  __CPROVER_assume((sec_r000086_5_1 >= 0) && (sec_r000086_5_1 <= 255));
  __CPROVER_assume((sec_r000086_5_2 >= 0) && (sec_r000086_5_2 <= 255));
  __CPROVER_assume((sec_r000086_6_1 >= 0) && (sec_r000086_6_1 <= 255));
  __CPROVER_assume((sec_r000086_6_2 >= 0) && (sec_r000086_6_2 <= 255));
  __CPROVER_assume((sec_r000086_7_1 >= 0) && (sec_r000086_7_1 <= 255));
  __CPROVER_assume((sec_r000086_7_2 >= 0) && (sec_r000086_7_2 <= 255));
  __CPROVER_assume((sec_r000086_8_1 >= 0) && (sec_r000086_8_1 <= 255));
  __CPROVER_assume((sec_r000086_8_2 >= 0) && (sec_r000086_8_2 <= 255));
  __CPROVER_assume((sec_r000086_9_1 >= 0) && (sec_r000086_9_1 <= 255));
  __CPROVER_assume((sec_r000086_9_2 >= 0) && (sec_r000086_9_2 <= 255));
  __CPROVER_assume((sec_r000086_10_1 >= 0) && (sec_r000086_10_1 <= 255));
  __CPROVER_assume((sec_r000086_10_2 >= 0) && (sec_r000086_10_2 <= 255));
  __CPROVER_assume((sec_r000086_11_1 >= 0) && (sec_r000086_11_1 <= 255));
  __CPROVER_assume((sec_r000086_11_2 >= 0) && (sec_r000086_11_2 <= 255));
  __CPROVER_assume((sec_r000086_12_1 >= 0) && (sec_r000086_12_1 <= 255));
  __CPROVER_assume((sec_r000086_12_2 >= 0) && (sec_r000086_12_2 <= 255));
  __CPROVER_assume((sec_r000086_13_1 >= 0) && (sec_r000086_13_1 <= 255));
  __CPROVER_assume((sec_r000086_13_2 >= 0) && (sec_r000086_13_2 <= 255));
  __CPROVER_assume((sec_r000086_14_1 >= 0) && (sec_r000086_14_1 <= 255));
  __CPROVER_assume((sec_r000086_14_2 >= 0) && (sec_r000086_14_2 <= 255));
  __CPROVER_assume((sec_r000086_15_1 >= 0) && (sec_r000086_15_1 <= 255));
  __CPROVER_assume((sec_r000086_15_2 >= 0) && (sec_r000086_15_2 <= 255));
  __CPROVER_assume((sec_r000086_16_1 >= 0) && (sec_r000086_16_1 <= 255));
  __CPROVER_assume((sec_r000086_16_2 >= 0) && (sec_r000086_16_2 <= 255));
  __CPROVER_assume((sec_r000086_17_1 >= 0) && (sec_r000086_17_1 <= 255));
  __CPROVER_assume((sec_r000086_17_2 >= 0) && (sec_r000086_17_2 <= 255));
  __CPROVER_assume((sec_r000086_18_1 >= 0) && (sec_r000086_18_1 <= 255));
  __CPROVER_assume((sec_r000086_18_2 >= 0) && (sec_r000086_18_2 <= 255));
  __CPROVER_assume((sec_r000086_19_1 >= 0) && (sec_r000086_19_1 <= 255));
  __CPROVER_assume((sec_r000086_19_2 >= 0) && (sec_r000086_19_2 <= 255));
  __CPROVER_assume((sec_r000086_20_1 >= 0) && (sec_r000086_20_1 <= 255));
  __CPROVER_assume((sec_r000086_20_2 >= 0) && (sec_r000086_20_2 <= 255));
  __CPROVER_assume((sec_r000086_21_1 >= 0) && (sec_r000086_21_1 <= 255));
  __CPROVER_assume((sec_r000086_21_2 >= 0) && (sec_r000086_21_2 <= 255));
  struct CipherContext_R000086_8613_0 st_var_0_1 = {0};
  struct CipherContext_R000086_8613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000086_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000086_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000086_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000086_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000086_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000086_0_2 + 7) & 15;
  struct EventLog_R000086_8613_1 st_var_1_1 = {0};
  struct EventLog_R000086_8613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000086_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000086_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000086_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000086_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000086_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000086_0_2 + 9) & 15;
  union PacketPayload_R000086_8613_0 u_var_1;
  union PacketPayload_R000086_8613_0 u_var_2;
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
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = ((st_var_0_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_0_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 42)
    {
      chk_sum_1 ^= stage_v_2_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_2_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 42)
    {
      chk_sum_2 ^= stage_v_2_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 4) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = (st_var_0_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_0_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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

  int stage_v_5_1 = ((st_var_1_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_1_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 48)
    {
      chk_sum_1 ^= stage_v_5_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_5_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 48)
    {
      chk_sum_2 ^= stage_v_5_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_6_1 = (st_var_0_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_0_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 10) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 12) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = ((st_var_0_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_0_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 31)
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
  if (stage_v_14_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 31)
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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 16) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = ((st_var_0_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_0_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 25)
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
  if (stage_v_16_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 25)
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
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (st_var_1_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_1_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 27) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = ((st_var_0_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_0_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 29)
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
  if (stage_v_28_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 29)
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
  int stage_v_29_1 = (st_var_1_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_1_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 32) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= stage_v_31_1;
  chk_sum_2 ^= stage_v_31_2;
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
  int stage_v_33_1 = ((st_var_1_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_1_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 52)
    {
      chk_sum_1 ^= stage_v_33_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_33_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 52)
    {
      chk_sum_2 ^= stage_v_33_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 41) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = ((st_var_0_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_0_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 32)
    {
      chk_sum_1 ^= stage_v_42_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_42_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 32)
    {
      chk_sum_2 ^= stage_v_42_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_43_1 = ((st_var_1_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_1_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 33)
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
  if (stage_v_43_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 33)
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
  if (stage_v_44_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 47)
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
  if (stage_v_44_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 47)
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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 46) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  int stage_v_47_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_47_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (54 & 31);
  int stage_v_49_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (54 & 31);
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= (stage_v_49_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_49_2 << 1) & 127;
  int stage_v_50_1 = (st_var_0_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_0_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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
  int stage_v_53_1 = table_1[1];
  int stage_v_53_2 = table_2[1];
  table_1[1] = (table_1[2] + 107) & 63;
  table_2[1] = (table_2[2] + 107) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((st_var_0_1.buffer[0] * 2) + 169) & 63;
  int stage_v_54_2 = ((st_var_0_2.buffer[0] * 2) + 169) & 63;
  if (stage_v_54_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_54_1) - 5) & 255;
    if (stage_v_54_1 > 39)
    {
      chk_sum_1 ^= stage_v_54_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_54_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_54_2) - 5) & 255;
    if (stage_v_54_2 > 39)
    {
      chk_sum_2 ^= stage_v_54_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_55_1 = ((st_var_1_1.buffer[1] * 2) + 172) & 63;
  int stage_v_55_2 = ((st_var_1_2.buffer[1] * 2) + 172) & 63;
  if (stage_v_55_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_55_1) - 5) & 255;
    if (stage_v_55_1 > 36)
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
  if (stage_v_55_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_55_2) - 5) & 255;
    if (stage_v_55_2 > 36)
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
  int stage_v_56_1 = (st_var_0_1.buffer[0] ^ 59) & 3;
  int stage_v_56_2 = (st_var_0_2.buffer[0] ^ 59) & 3;
  switch (stage_v_56_1)
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

  switch (stage_v_56_2)
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

  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_58_1 = ((stage_v_58_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_58_2 = ((stage_v_58_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (64 & 31);
  int stage_v_59_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (64 & 31);
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= (stage_v_59_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_59_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 61) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 61) & 15;
  int stage_v_60_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_60_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= stage_v_60_1;
  chk_sum_2 ^= stage_v_60_2;
  int stage_v_61_1 = table_1[1];
  int stage_v_61_2 = table_2[1];
  table_1[1] = (table_1[2] + 123) & 63;
  table_2[1] = (table_2[2] + 123) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (67 & 31);
  int stage_v_62_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (67 & 31);
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= (stage_v_62_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_62_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 64) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 64) & 15;
  int stage_v_63_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_63_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= stage_v_63_1;
  chk_sum_2 ^= stage_v_63_2;
  int stage_v_64_1 = ((st_var_0_1.buffer[1] * 2) + 199) & 63;
  int stage_v_64_2 = ((st_var_0_2.buffer[1] * 2) + 199) & 63;
  if (stage_v_64_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_64_1) - 5) & 255;
    if (stage_v_64_1 > 37)
    {
      chk_sum_1 ^= stage_v_64_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_64_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_64_2) - 5) & 255;
    if (stage_v_64_2 > 37)
    {
      chk_sum_2 ^= stage_v_64_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_65_1 = (st_var_1_1.buffer[0] ^ 68) & 3;
  int stage_v_65_2 = (st_var_1_2.buffer[0] ^ 68) & 3;
  switch (stage_v_65_1)
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

  switch (stage_v_65_2)
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

  int stage_v_66_1 = ((st_var_0_1.buffer[0] * 2) + 205) & 63;
  int stage_v_66_2 = ((st_var_0_2.buffer[0] * 2) + 205) & 63;
  if (stage_v_66_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_66_1) - 5) & 255;
    if (stage_v_66_1 > 26)
    {
      chk_sum_1 ^= stage_v_66_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_66_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_66_2) - 5) & 255;
    if (stage_v_66_2 > 26)
    {
      chk_sum_2 ^= stage_v_66_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_67_1 = ((stage_v_67_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_67_2 = ((stage_v_67_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_68_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_68_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_68_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_69_1 = table_1[1];
  int stage_v_69_2 = table_2[1];
  table_1[1] = (table_1[2] + 139) & 63;
  table_2[1] = (table_2[2] + 139) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((st_var_0_1.buffer[1] * 2) + 217) & 63;
  int stage_v_70_2 = ((st_var_0_2.buffer[1] * 2) + 217) & 63;
  if (stage_v_70_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_70_1) - 5) & 255;
    if (stage_v_70_1 > 51)
    {
      chk_sum_1 ^= stage_v_70_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_70_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_70_2) - 5) & 255;
    if (stage_v_70_2 > 51)
    {
      chk_sum_2 ^= stage_v_70_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_71_1 = ((stage_v_71_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_71_2 = ((stage_v_71_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 54)
    {
      chk_sum_1 ^= stage_v_72_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_72_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 54)
    {
      chk_sum_2 ^= stage_v_72_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 74) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 74) & 15;
  int stage_v_73_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_73_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= stage_v_73_1;
  chk_sum_2 ^= stage_v_73_2;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((st_var_0_1.buffer[1] * 2) + 235) & 63;
  int stage_v_76_2 = ((st_var_0_2.buffer[1] * 2) + 235) & 63;
  if (stage_v_76_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_76_1) - 5) & 255;
    if (stage_v_76_1 > 45)
    {
      chk_sum_1 ^= stage_v_76_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_76_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_76_2) - 5) & 255;
    if (stage_v_76_2 > 45)
    {
      chk_sum_2 ^= stage_v_76_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (st_var_0_1.buffer[0] ^ 81) & 3;
  int stage_v_78_2 = (st_var_0_2.buffer[0] ^ 81) & 3;
  switch (stage_v_78_1)
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

  switch (stage_v_78_2)
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

  int stage_v_79_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (84 & 31);
  int stage_v_79_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (84 & 31);
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  chk_sum_1 ^= (stage_v_79_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_79_2 << 1) & 127;
  int stage_v_80_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_80_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_80_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_80_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 82) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 82) & 15;
  int stage_v_81_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_81_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  chk_sum_1 ^= stage_v_81_1;
  chk_sum_2 ^= stage_v_81_2;
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
  int stage_v_83_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (88 & 31);
  int stage_v_83_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (88 & 31);
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= (stage_v_83_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_83_2 << 1) & 127;
  int stage_v_84_1 = ((st_var_0_1.buffer[0] * 2) + 259) & 63;
  int stage_v_84_2 = ((st_var_0_2.buffer[0] * 2) + 259) & 63;
  if (stage_v_84_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_84_1) - 5) & 255;
    if (stage_v_84_1 > 44)
    {
      chk_sum_1 ^= stage_v_84_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_84_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_84_2) - 5) & 255;
    if (stage_v_84_2 > 44)
    {
      chk_sum_2 ^= stage_v_84_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 86) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 86) & 15;
  int stage_v_85_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_85_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= stage_v_85_1;
  chk_sum_2 ^= stage_v_85_2;
  int stage_v_86_1 = table_1[2];
  int stage_v_86_2 = table_2[2];
  table_1[2] = (table_1[3] + 173) & 63;
  table_2[2] = (table_2[3] + 173) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((st_var_1_1.buffer[0] * 2) + 268) & 63;
  int stage_v_87_2 = ((st_var_1_2.buffer[0] * 2) + 268) & 63;
  if (stage_v_87_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_87_1) - 5) & 255;
    if (stage_v_87_1 > 48)
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
  if (stage_v_87_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_87_2) - 5) & 255;
    if (stage_v_87_2 > 48)
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
  int stage_v_89_1 = (st_var_1_1.buffer[0] ^ 92) & 3;
  int stage_v_89_2 = (st_var_1_2.buffer[0] ^ 92) & 3;
  switch (stage_v_89_1)
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

  switch (stage_v_89_2)
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

  int stage_v_90_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (95 & 31);
  int stage_v_90_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (95 & 31);
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  chk_sum_1 ^= (stage_v_90_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_90_2 << 1) & 127;
  int stage_v_91_1 = table_1[3];
  int stage_v_91_2 = table_2[3];
  table_1[3] = (table_1[0] + 183) & 63;
  table_2[3] = (table_2[0] + 183) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 93) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 93) & 15;
  int stage_v_92_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_92_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  chk_sum_1 ^= stage_v_92_1;
  chk_sum_2 ^= stage_v_92_2;
  int stage_v_93_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_93_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_93_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_93_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_94_1 = ((st_var_0_1.buffer[1] * 2) + 289) & 63;
  int stage_v_94_2 = ((st_var_0_2.buffer[1] * 2) + 289) & 63;
  if (stage_v_94_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_94_1) - 5) & 255;
    if (stage_v_94_1 > 52)
    {
      chk_sum_1 ^= stage_v_94_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_94_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_94_2) - 5) & 255;
    if (stage_v_94_2 > 52)
    {
      chk_sum_2 ^= stage_v_94_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_95_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (100 & 31);
  int stage_v_95_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (100 & 31);
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  chk_sum_1 ^= (stage_v_95_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_95_2 << 1) & 127;
  int stage_v_96_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (101 & 31);
  int stage_v_96_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (101 & 31);
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  chk_sum_1 ^= (stage_v_96_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_96_2 << 1) & 127;
  int stage_v_97_1 = ((st_var_1_1.buffer[1] * 2) + 298) & 63;
  int stage_v_97_2 = ((st_var_1_2.buffer[1] * 2) + 298) & 63;
  if (stage_v_97_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_97_1) - 5) & 255;
    if (stage_v_97_1 > 42)
    {
      chk_sum_1 ^= stage_v_97_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_97_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_97_2) - 5) & 255;
    if (stage_v_97_2 > 42)
    {
      chk_sum_2 ^= stage_v_97_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_98_1 = table_1[2];
  int stage_v_98_2 = table_2[2];
  table_1[2] = (table_1[3] + 197) & 63;
  table_2[2] = (table_2[3] + 197) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((st_var_1_1.buffer[0] * 2) + 304) & 63;
  int stage_v_99_2 = ((st_var_1_2.buffer[0] * 2) + 304) & 63;
  if (stage_v_99_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_99_1) - 5) & 255;
    if (stage_v_99_1 > 50)
    {
      chk_sum_1 ^= stage_v_99_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_99_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_99_2) - 5) & 255;
    if (stage_v_99_2 > 50)
    {
      chk_sum_2 ^= stage_v_99_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 101) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 101) & 15;
  int stage_v_100_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_100_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= stage_v_100_1;
  chk_sum_2 ^= stage_v_100_2;
  int stage_v_101_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_101_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_101_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_101_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_102_1 = ((stage_v_102_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_102_2 = ((stage_v_102_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = table_1[3];
  int stage_v_103_2 = table_2[3];
  table_1[3] = (table_1[0] + 207) & 63;
  table_2[3] = (table_2[0] + 207) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (109 & 31);
  int stage_v_104_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (109 & 31);
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  chk_sum_1 ^= (stage_v_104_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_104_2 << 1) & 127;
  int stage_v_105_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (110 & 31);
  int stage_v_105_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (110 & 31);
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= (stage_v_105_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_105_2 << 1) & 127;
  int stage_v_106_1 = (st_var_0_1.buffer[0] ^ 109) & 3;
  int stage_v_106_2 = (st_var_0_2.buffer[0] ^ 109) & 3;
  switch (stage_v_106_1)
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

  switch (stage_v_106_2)
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

  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_107_1 = ((stage_v_107_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_107_2 = ((stage_v_107_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 109) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 109) & 15;
  int stage_v_108_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_108_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  chk_sum_1 ^= stage_v_108_1;
  chk_sum_2 ^= stage_v_108_2;
  int stage_v_109_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (114 & 31);
  int stage_v_109_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (114 & 31);
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  chk_sum_1 ^= (stage_v_109_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_109_2 << 1) & 127;
  int stage_v_110_1 = (st_var_0_1.buffer[0] ^ 113) & 3;
  int stage_v_110_2 = (st_var_0_2.buffer[0] ^ 113) & 3;
  switch (stage_v_110_1)
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

  switch (stage_v_110_2)
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

  int stage_v_111_1 = table_1[3];
  int stage_v_111_2 = table_2[3];
  table_1[3] = (table_1[0] + 223) & 63;
  table_2[3] = (table_2[0] + 223) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((st_var_0_1.buffer[1] * 2) + 343) & 63;
  int stage_v_112_2 = ((st_var_0_2.buffer[1] * 2) + 343) & 63;
  if (stage_v_112_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_112_1) - 5) & 255;
    if (stage_v_112_1 > 39)
    {
      chk_sum_1 ^= stage_v_112_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_112_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_112_2) - 5) & 255;
    if (stage_v_112_2 > 39)
    {
      chk_sum_2 ^= stage_v_112_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_113_1 = ((stage_v_113_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_113_2 = ((stage_v_113_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 115) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 115) & 15;
  int stage_v_114_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_114_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= stage_v_114_1;
  chk_sum_2 ^= stage_v_114_2;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_115_1 = ((stage_v_115_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_115_2 = ((stage_v_115_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 117) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 117) & 15;
  int stage_v_116_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_116_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  chk_sum_1 ^= stage_v_116_1;
  chk_sum_2 ^= stage_v_116_2;
  int stage_v_117_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_117_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_117_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_117_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_118_1 = ((st_var_0_1.buffer[1] * 2) + 361) & 63;
  int stage_v_118_2 = ((st_var_0_2.buffer[1] * 2) + 361) & 63;
  if (stage_v_118_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_118_1) - 5) & 255;
    if (stage_v_118_1 > 51)
    {
      chk_sum_1 ^= stage_v_118_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_118_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_118_2) - 5) & 255;
    if (stage_v_118_2 > 51)
    {
      chk_sum_2 ^= stage_v_118_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 120) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 120) & 15;
  int stage_v_119_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_119_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  chk_sum_1 ^= stage_v_119_1;
  chk_sum_2 ^= stage_v_119_2;
  int stage_v_120_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (125 & 31);
  int stage_v_120_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (125 & 31);
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  chk_sum_1 ^= (stage_v_120_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_120_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 122) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 122) & 15;
  int stage_v_121_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_121_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  chk_sum_1 ^= stage_v_121_1;
  chk_sum_2 ^= stage_v_121_2;
  int stage_v_122_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (127 & 31);
  int stage_v_122_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (127 & 31);
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  chk_sum_1 ^= (stage_v_122_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_122_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 124) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 124) & 15;
  int stage_v_123_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_123_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  chk_sum_1 ^= stage_v_123_1;
  chk_sum_2 ^= stage_v_123_2;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_124_1 = ((stage_v_124_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_124_2 = ((stage_v_124_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = (st_var_1_1.buffer[0] ^ 128) & 3;
  int stage_v_125_2 = (st_var_1_2.buffer[0] ^ 128) & 3;
  switch (stage_v_125_1)
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

  switch (stage_v_125_2)
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

  int stage_v_126_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_126_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_126_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_126_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_127_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (132 & 31);
  int stage_v_127_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (132 & 31);
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  chk_sum_1 ^= (stage_v_127_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_127_2 << 1) & 127;
  int stage_v_128_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (133 & 31);
  int stage_v_128_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (133 & 31);
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  chk_sum_1 ^= (stage_v_128_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_128_2 << 1) & 127;
  int stage_v_129_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (134 & 31);
  int stage_v_129_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (134 & 31);
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  chk_sum_1 ^= (stage_v_129_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_129_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 131) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 131) & 15;
  int stage_v_130_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_130_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= stage_v_130_1;
  chk_sum_2 ^= stage_v_130_2;
  int stage_v_131_1 = table_1[3];
  int stage_v_131_2 = table_2[3];
  table_1[3] = (table_1[0] + 263) & 63;
  table_2[3] = (table_2[0] + 263) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = table_1[0];
  int stage_v_132_2 = table_2[0];
  table_1[0] = (table_1[1] + 265) & 63;
  table_2[0] = (table_2[1] + 265) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (138 & 31);
  int stage_v_133_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (138 & 31);
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  chk_sum_1 ^= (stage_v_133_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_133_2 << 1) & 127;
  int stage_v_134_1 = table_1[2];
  int stage_v_134_2 = table_2[2];
  table_1[2] = (table_1[3] + 269) & 63;
  table_2[2] = (table_2[3] + 269) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((st_var_1_1.buffer[0] * 2) + 412) & 63;
  int stage_v_135_2 = ((st_var_1_2.buffer[0] * 2) + 412) & 63;
  if (stage_v_135_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_135_1) - 5) & 255;
    if (stage_v_135_1 > 40)
    {
      chk_sum_1 ^= stage_v_135_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_135_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_135_2) - 5) & 255;
    if (stage_v_135_2 > 40)
    {
      chk_sum_2 ^= stage_v_135_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_136_1 = table_1[0];
  int stage_v_136_2 = table_2[0];
  table_1[0] = (table_1[1] + 273) & 63;
  table_2[0] = (table_2[1] + 273) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (st_var_1_1.buffer[0] ^ 140) & 3;
  int stage_v_137_2 = (st_var_1_2.buffer[0] ^ 140) & 3;
  switch (stage_v_137_1)
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

  switch (stage_v_137_2)
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

  int stage_v_138_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (143 & 31);
  int stage_v_138_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (143 & 31);
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  chk_sum_1 ^= (stage_v_138_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_138_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 140) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 140) & 15;
  int stage_v_139_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_139_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  chk_sum_1 ^= stage_v_139_1;
  chk_sum_2 ^= stage_v_139_2;
  int stage_v_140_1 = table_1[0];
  int stage_v_140_2 = table_2[0];
  table_1[0] = (table_1[1] + 281) & 63;
  table_2[0] = (table_2[1] + 281) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = table_1[1];
  int stage_v_141_2 = table_2[1];
  table_1[1] = (table_1[2] + 283) & 63;
  table_2[1] = (table_2[2] + 283) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((st_var_0_1.buffer[1] * 2) + 433) & 63;
  int stage_v_142_2 = ((st_var_0_2.buffer[1] * 2) + 433) & 63;
  if (stage_v_142_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_142_1) - 5) & 255;
    if (stage_v_142_1 > 55)
    {
      chk_sum_1 ^= stage_v_142_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_142_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_142_2) - 5) & 255;
    if (stage_v_142_2 > 55)
    {
      chk_sum_2 ^= stage_v_142_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_144_1 = ((stage_v_144_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_144_2 = ((stage_v_144_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = table_1[1];
  int stage_v_145_2 = table_2[1];
  table_1[1] = (table_1[2] + 291) & 63;
  table_2[1] = (table_2[2] + 291) & 63;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (151 & 31);
  int stage_v_146_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (151 & 31);
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  chk_sum_1 ^= (stage_v_146_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_146_2 << 1) & 127;
  int stage_v_147_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_147_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_147_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_147_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_148_1 = ((stage_v_148_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_148_2 = ((stage_v_148_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_149_1 = ((stage_v_149_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_149_2 = ((stage_v_149_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((st_var_0_1.buffer[0] * 2) + 457) & 63;
  int stage_v_150_2 = ((st_var_0_2.buffer[0] * 2) + 457) & 63;
  if (stage_v_150_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_150_1) - 5) & 255;
    if (stage_v_150_1 > 52)
    {
      chk_sum_1 ^= stage_v_150_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_150_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_150_2) - 5) & 255;
    if (stage_v_150_2 > 52)
    {
      chk_sum_2 ^= stage_v_150_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_151_1 = table_1[3];
  int stage_v_151_2 = table_2[3];
  table_1[3] = (table_1[0] + 303) & 63;
  table_2[3] = (table_2[0] + 303) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (157 & 31);
  int stage_v_152_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (157 & 31);
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  chk_sum_1 ^= (stage_v_152_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_152_2 << 1) & 127;
  int stage_v_153_1 = (st_var_1_1.buffer[0] ^ 156) & 3;
  int stage_v_153_2 = (st_var_1_2.buffer[0] ^ 156) & 3;
  switch (stage_v_153_1)
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

  switch (stage_v_153_2)
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

  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_154_1 = ((stage_v_154_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_154_2 = ((stage_v_154_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_155_1 = ((stage_v_155_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_155_2 = ((stage_v_155_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (161 & 31);
  int stage_v_156_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (161 & 31);
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  chk_sum_1 ^= (stage_v_156_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_156_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 158) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 158) & 15;
  int stage_v_157_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_157_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  chk_sum_1 ^= stage_v_157_1;
  chk_sum_2 ^= stage_v_157_2;
  int stage_v_158_1 = ((st_var_0_1.buffer[2] * 2) + 481) & 63;
  int stage_v_158_2 = ((st_var_0_2.buffer[2] * 2) + 481) & 63;
  if (stage_v_158_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_158_1) - 5) & 255;
    if (stage_v_158_1 > 36)
    {
      chk_sum_1 ^= stage_v_158_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_158_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_158_2) - 5) & 255;
    if (stage_v_158_2 > 36)
    {
      chk_sum_2 ^= stage_v_158_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_159_1 = ((stage_v_159_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_159_2 = ((stage_v_159_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_160_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_160_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_160_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_161_1 = ((st_var_1_1.buffer[2] * 2) + 490) & 63;
  int stage_v_161_2 = ((st_var_1_2.buffer[2] * 2) + 490) & 63;
  if (stage_v_161_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_161_1) - 5) & 255;
    if (stage_v_161_1 > 26)
    {
      chk_sum_1 ^= stage_v_161_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_161_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_161_2) - 5) & 255;
    if (stage_v_161_2 > 26)
    {
      chk_sum_2 ^= stage_v_161_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_162_1 = table_1[2];
  int stage_v_162_2 = table_2[2];
  table_1[2] = (table_1[3] + 325) & 63;
  table_2[2] = (table_2[3] + 325) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((st_var_1_1.buffer[1] * 2) + 496) & 63;
  int stage_v_163_2 = ((st_var_1_2.buffer[1] * 2) + 496) & 63;
  if (stage_v_163_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_163_1) - 5) & 255;
    if (stage_v_163_1 > 52)
    {
      chk_sum_1 ^= stage_v_163_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_163_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_163_2) - 5) & 255;
    if (stage_v_163_2 > 52)
    {
      chk_sum_2 ^= stage_v_163_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_164_1 = ((st_var_0_1.buffer[2] * 2) + 499) & 63;
  int stage_v_164_2 = ((st_var_0_2.buffer[2] * 2) + 499) & 63;
  if (stage_v_164_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_164_1) - 5) & 255;
    if (stage_v_164_1 > 31)
    {
      chk_sum_1 ^= stage_v_164_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_164_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_164_2) - 5) & 255;
    if (stage_v_164_2 > 31)
    {
      chk_sum_2 ^= stage_v_164_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 166) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 166) & 15;
  int stage_v_165_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_165_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  chk_sum_1 ^= stage_v_165_1;
  chk_sum_2 ^= stage_v_165_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 167) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 167) & 15;
  int stage_v_166_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_166_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  chk_sum_1 ^= stage_v_166_1;
  chk_sum_2 ^= stage_v_166_2;
  int stage_v_167_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_167_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_167_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_167_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_168_1 = ((st_var_0_1.buffer[0] * 2) + 511) & 63;
  int stage_v_168_2 = ((st_var_0_2.buffer[0] * 2) + 511) & 63;
  if (stage_v_168_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_168_1) - 5) & 255;
    if (stage_v_168_1 > 34)
    {
      chk_sum_1 ^= stage_v_168_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_168_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_168_2) - 5) & 255;
    if (stage_v_168_2 > 34)
    {
      chk_sum_2 ^= stage_v_168_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_169_1 = ((st_var_1_1.buffer[1] * 2) + 514) & 63;
  int stage_v_169_2 = ((st_var_1_2.buffer[1] * 2) + 514) & 63;
  if (stage_v_169_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_169_1) - 5) & 255;
    if (stage_v_169_1 > 51)
    {
      chk_sum_1 ^= stage_v_169_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_169_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_169_2) - 5) & 255;
    if (stage_v_169_2 > 51)
    {
      chk_sum_2 ^= stage_v_169_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_170_1 = 0;
  int stage_v_170_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_170_1 = ((stage_v_170_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_170_2 = ((stage_v_170_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = table_1[3];
  int stage_v_171_2 = table_2[3];
  table_1[3] = (table_1[0] + 343) & 63;
  table_2[3] = (table_2[0] + 343) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = table_1[0];
  int stage_v_172_2 = table_2[0];
  table_1[0] = (table_1[1] + 345) & 63;
  table_2[0] = (table_2[1] + 345) & 63;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = table_1[1];
  int stage_v_173_2 = table_2[1];
  table_1[1] = (table_1[2] + 347) & 63;
  table_2[1] = (table_2[2] + 347) & 63;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((st_var_0_1.buffer[0] * 2) + 529) & 63;
  int stage_v_174_2 = ((st_var_0_2.buffer[0] * 2) + 529) & 63;
  if (stage_v_174_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_174_1) - 5) & 255;
    if (stage_v_174_1 > 51)
    {
      chk_sum_1 ^= stage_v_174_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_174_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_174_2) - 5) & 255;
    if (stage_v_174_2 > 51)
    {
      chk_sum_2 ^= stage_v_174_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 176) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 176) & 15;
  int stage_v_175_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_175_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  chk_sum_1 ^= stage_v_175_1;
  chk_sum_2 ^= stage_v_175_2;
  int stage_v_176_1 = (st_var_0_1.buffer[0] ^ 179) & 3;
  int stage_v_176_2 = (st_var_0_2.buffer[0] ^ 179) & 3;
  switch (stage_v_176_1)
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

  switch (stage_v_176_2)
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

  int stage_v_177_1 = ((st_var_1_1.buffer[0] * 2) + 538) & 63;
  int stage_v_177_2 = ((st_var_1_2.buffer[0] * 2) + 538) & 63;
  if (stage_v_177_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_177_1) - 5) & 255;
    if (stage_v_177_1 > 42)
    {
      chk_sum_1 ^= stage_v_177_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_177_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_177_2) - 5) & 255;
    if (stage_v_177_2 > 42)
    {
      chk_sum_2 ^= stage_v_177_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_178_1 = ((st_var_0_1.buffer[1] * 2) + 541) & 63;
  int stage_v_178_2 = ((st_var_0_2.buffer[1] * 2) + 541) & 63;
  if (stage_v_178_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_178_1) - 5) & 255;
    if (stage_v_178_1 > 48)
    {
      chk_sum_1 ^= stage_v_178_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_178_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_178_2) - 5) & 255;
    if (stage_v_178_2 > 48)
    {
      chk_sum_2 ^= stage_v_178_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 180) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 180) & 15;
  int stage_v_179_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_179_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  chk_sum_1 ^= stage_v_179_1;
  chk_sum_2 ^= stage_v_179_2;
  int stage_v_180_1 = ((st_var_0_1.buffer[0] * 2) + 547) & 63;
  int stage_v_180_2 = ((st_var_0_2.buffer[0] * 2) + 547) & 63;
  if (stage_v_180_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_180_1) - 5) & 255;
    if (stage_v_180_1 > 46)
    {
      chk_sum_1 ^= stage_v_180_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_180_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_180_2) - 5) & 255;
    if (stage_v_180_2 > 46)
    {
      chk_sum_2 ^= stage_v_180_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_181_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_181_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_181_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_181_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_182_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (187 & 31);
  int stage_v_182_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (187 & 31);
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  chk_sum_1 ^= (stage_v_182_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_182_2 << 1) & 127;
  int stage_v_183_1 = table_1[3];
  int stage_v_183_2 = table_2[3];
  table_1[3] = (table_1[0] + 367) & 63;
  table_2[3] = (table_2[0] + 367) & 63;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 185) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 185) & 15;
  int stage_v_184_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_184_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  chk_sum_1 ^= stage_v_184_1;
  chk_sum_2 ^= stage_v_184_2;
  int stage_v_185_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_185_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_185_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_185_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 187) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 187) & 15;
  int stage_v_186_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_186_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  chk_sum_1 ^= stage_v_186_1;
  chk_sum_2 ^= stage_v_186_2;
  int stage_v_187_1 = 0;
  int stage_v_187_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_187_1 = ((stage_v_187_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_187_2 = ((stage_v_187_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((st_var_0_1.buffer[2] * 2) + 571) & 63;
  int stage_v_188_2 = ((st_var_0_2.buffer[2] * 2) + 571) & 63;
  if (stage_v_188_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_188_1) - 5) & 255;
    if (stage_v_188_1 > 54)
    {
      chk_sum_1 ^= stage_v_188_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_188_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_188_2) - 5) & 255;
    if (stage_v_188_2 > 54)
    {
      chk_sum_2 ^= stage_v_188_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_189_1 = table_1[1];
  int stage_v_189_2 = table_2[1];
  table_1[1] = (table_1[2] + 379) & 63;
  table_2[1] = (table_2[2] + 379) & 63;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = table_1[2];
  int stage_v_190_2 = table_2[2];
  table_1[2] = (table_1[3] + 381) & 63;
  table_2[2] = (table_2[3] + 381) & 63;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (196 & 31);
  int stage_v_191_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (196 & 31);
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  chk_sum_1 ^= (stage_v_191_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_191_2 << 1) & 127;
  int stage_v_192_1 = (st_var_0_1.buffer[0] ^ 195) & 3;
  int stage_v_192_2 = (st_var_0_2.buffer[0] ^ 195) & 3;
  switch (stage_v_192_1)
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

  switch (stage_v_192_2)
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

  int stage_v_193_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (198 & 31);
  int stage_v_193_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (198 & 31);
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  chk_sum_1 ^= (stage_v_193_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_193_2 << 1) & 127;
  int stage_v_194_1 = ((st_var_0_1.buffer[2] * 2) + 589) & 63;
  int stage_v_194_2 = ((st_var_0_2.buffer[2] * 2) + 589) & 63;
  if (stage_v_194_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_194_1) - 5) & 255;
    if (stage_v_194_1 > 37)
    {
      chk_sum_1 ^= stage_v_194_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_194_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_194_2) - 5) & 255;
    if (stage_v_194_2 > 37)
    {
      chk_sum_2 ^= stage_v_194_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_195_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_195_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_195_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_195_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_196_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_196_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_196_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_196_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_197_1 = table_1[1];
  int stage_v_197_2 = table_2[1];
  table_1[1] = (table_1[2] + 395) & 63;
  table_2[1] = (table_2[2] + 395) & 63;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 199) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 199) & 15;
  int stage_v_198_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_198_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  chk_sum_1 ^= stage_v_198_1;
  chk_sum_2 ^= stage_v_198_2;
  int stage_v_199_1 = (st_var_1_1.buffer[0] ^ 202) & 3;
  int stage_v_199_2 = (st_var_1_2.buffer[0] ^ 202) & 3;
  switch (stage_v_199_1)
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

  switch (stage_v_199_2)
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

  int stage_v_200_1 = ((st_var_0_1.buffer[2] * 2) + 607) & 63;
  int stage_v_200_2 = ((st_var_0_2.buffer[2] * 2) + 607) & 63;
  if (stage_v_200_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_200_1) - 5) & 255;
    if (stage_v_200_1 > 52)
    {
      chk_sum_1 ^= stage_v_200_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_200_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_200_2) - 5) & 255;
    if (stage_v_200_2 > 52)
    {
      chk_sum_2 ^= stage_v_200_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_201_1 = 0;
  int stage_v_201_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_201_1 = ((stage_v_201_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_201_2 = ((stage_v_201_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = table_1[2];
  int stage_v_202_2 = table_2[2];
  table_1[2] = (table_1[3] + 405) & 63;
  table_2[2] = (table_2[3] + 405) & 63;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_203_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_203_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_203_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_204_1 = (st_var_0_1.buffer[0] ^ 207) & 3;
  int stage_v_204_2 = (st_var_0_2.buffer[0] ^ 207) & 3;
  switch (stage_v_204_1)
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

  switch (stage_v_204_2)
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

  int stage_v_205_1 = table_1[1];
  int stage_v_205_2 = table_2[1];
  table_1[1] = (table_1[2] + 411) & 63;
  table_2[1] = (table_2[2] + 411) & 63;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = table_1[2];
  int stage_v_206_2 = table_2[2];
  table_1[2] = (table_1[3] + 413) & 63;
  table_2[2] = (table_2[3] + 413) & 63;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_207_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_207_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_207_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_208_1 = table_1[0];
  int stage_v_208_2 = table_2[0];
  table_1[0] = (table_1[1] + 417) & 63;
  table_2[0] = (table_2[1] + 417) & 63;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (214 & 31);
  int stage_v_209_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (214 & 31);
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  chk_sum_1 ^= (stage_v_209_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_209_2 << 1) & 127;
  int stage_v_210_1 = table_1[2];
  int stage_v_210_2 = table_2[2];
  table_1[2] = (table_1[3] + 421) & 63;
  table_2[2] = (table_2[3] + 421) & 63;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = 0;
  int stage_v_211_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_211_1 = ((stage_v_211_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_211_2 = ((stage_v_211_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = (st_var_0_1.buffer[0] ^ 215) & 3;
  int stage_v_212_2 = (st_var_0_2.buffer[0] ^ 215) & 3;
  switch (stage_v_212_1)
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

  switch (stage_v_212_2)
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

  int stage_v_213_1 = ((st_var_1_1.buffer[0] * 2) + 646) & 63;
  int stage_v_213_2 = ((st_var_1_2.buffer[0] * 2) + 646) & 63;
  if (stage_v_213_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_213_1) - 5) & 255;
    if (stage_v_213_1 > 30)
    {
      chk_sum_1 ^= stage_v_213_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_213_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_213_2) - 5) & 255;
    if (stage_v_213_2 > 30)
    {
      chk_sum_2 ^= stage_v_213_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_214_1 = (st_var_0_1.buffer[0] ^ 217) & 3;
  int stage_v_214_2 = (st_var_0_2.buffer[0] ^ 217) & 3;
  switch (stage_v_214_1)
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

  switch (stage_v_214_2)
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

  int stage_v_215_1 = 0;
  int stage_v_215_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_215_1 = ((stage_v_215_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_215_2 = ((stage_v_215_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = 0;
  int stage_v_216_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_216_1 = ((stage_v_216_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_216_2 = ((stage_v_216_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = table_1[1];
  int stage_v_217_2 = table_2[1];
  table_1[1] = (table_1[2] + 435) & 63;
  table_2[1] = (table_2[2] + 435) & 63;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = 0;
  int stage_v_218_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_218_1 = ((stage_v_218_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_218_2 = ((stage_v_218_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = 0;
  int stage_v_219_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_219_1 = ((stage_v_219_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_219_2 = ((stage_v_219_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = table_1[0];
  int stage_v_220_2 = table_2[0];
  table_1[0] = (table_1[1] + 441) & 63;
  table_2[0] = (table_2[1] + 441) & 63;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (226 & 31);
  int stage_v_221_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (226 & 31);
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  chk_sum_1 ^= (stage_v_221_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_221_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 223) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 223) & 15;
  int stage_v_222_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_222_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  chk_sum_1 ^= stage_v_222_1;
  chk_sum_2 ^= stage_v_222_2;
  int stage_v_223_1 = table_1[3];
  int stage_v_223_2 = table_2[3];
  table_1[3] = (table_1[0] + 447) & 63;
  table_2[3] = (table_2[0] + 447) & 63;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((st_var_0_1.buffer[2] * 2) + 679) & 63;
  int stage_v_224_2 = ((st_var_0_2.buffer[2] * 2) + 679) & 63;
  if (stage_v_224_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_224_1) - 5) & 255;
    if (stage_v_224_1 > 49)
    {
      chk_sum_1 ^= stage_v_224_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_224_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_224_2) - 5) & 255;
    if (stage_v_224_2 > 49)
    {
      chk_sum_2 ^= stage_v_224_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int dead_sec_0_1 = (sec_r000086_4_1 & 0) * 0;
  int dead_sec_0_2 = (sec_r000086_4_2 & 0) * 0;
  int dead_sec_1_1 = (sec_r000086_15_1 & 0) * 0;
  int dead_sec_1_2 = (sec_r000086_15_2 & 0) * 0;
  out_sink_1 = ((out_sink_1 + dead_sec_0_1) + dead_sec_1_1) & 255;
  out_sink_2 = ((out_sink_2 + dead_sec_0_2) + dead_sec_1_2) & 255;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000086_9_1 == pub_r000086_9_2);
  __CPROVER_assume(sec_r000086_14_1 != sec_r000086_14_2);
  __CPROVER_assume(pub_r000086_6_1 == pub_r000086_6_2);
  __CPROVER_assume(sec_r000086_20_1 != sec_r000086_20_2);
  __CPROVER_assume(pub_r000086_8_1 == pub_r000086_8_2);
  __CPROVER_assume(pub_r000086_11_1 == pub_r000086_11_2);
  __CPROVER_assume(sec_r000086_0_1 != sec_r000086_0_2);
  __CPROVER_assume(sec_r000086_11_1 != sec_r000086_11_2);
  __CPROVER_assume(sec_r000086_7_1 != sec_r000086_7_2);
  __CPROVER_assume(pub_r000086_2_1 == pub_r000086_2_2);
  __CPROVER_assume(pub_r000086_15_1 == pub_r000086_15_2);
  __CPROVER_assume(sec_r000086_17_1 != sec_r000086_17_2);
  __CPROVER_assume(pub_r000086_14_1 == pub_r000086_14_2);
  __CPROVER_assume(pub_r000086_16_1 == pub_r000086_16_2);
  __CPROVER_assume(sec_r000086_1_1 != sec_r000086_1_2);
  __CPROVER_assume(sec_r000086_10_1 != sec_r000086_10_2);
  __CPROVER_assume(pub_r000086_0_1 == pub_r000086_0_2);
  __CPROVER_assume(pub_r000086_5_1 == pub_r000086_5_2);
  __CPROVER_assume(sec_r000086_13_1 != sec_r000086_13_2);
  __CPROVER_assume(pub_r000086_3_1 == pub_r000086_3_2);
  __CPROVER_assume(sec_r000086_8_1 != sec_r000086_8_2);
  __CPROVER_assume(sec_r000086_6_1 != sec_r000086_6_2);
  __CPROVER_assume(sec_r000086_19_1 != sec_r000086_19_2);
  __CPROVER_assume(pub_r000086_1_1 == pub_r000086_1_2);
  __CPROVER_assume(pub_r000086_4_1 == pub_r000086_4_2);
  __CPROVER_assume(sec_r000086_21_1 != sec_r000086_21_2);
  __CPROVER_assume(pub_r000086_13_1 == pub_r000086_13_2);
  __CPROVER_assume(sec_r000086_16_1 != sec_r000086_16_2);
  __CPROVER_assume(sec_r000086_4_1 != sec_r000086_4_2);
  __CPROVER_assume(sec_r000086_15_1 != sec_r000086_15_2);
  __CPROVER_assume(sec_r000086_12_1 != sec_r000086_12_2);
  __CPROVER_assume(sec_r000086_2_1 != sec_r000086_2_2);
  __CPROVER_assume(sec_r000086_5_1 != sec_r000086_5_2);
  __CPROVER_assume(sec_r000086_9_1 != sec_r000086_9_2);
  __CPROVER_assume(sec_r000086_18_1 != sec_r000086_18_2);
  __CPROVER_assume(pub_r000086_7_1 == pub_r000086_7_2);
  __CPROVER_assume(sec_r000086_3_1 != sec_r000086_3_2);
  __CPROVER_assume(pub_r000086_10_1 == pub_r000086_10_2);
  __CPROVER_assume(pub_r000086_12_1 == pub_r000086_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
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
  assert(dead_sec_0_1 == dead_sec_0_2);
  assert(dead_sec_1_1 == dead_sec_1_2);
}


