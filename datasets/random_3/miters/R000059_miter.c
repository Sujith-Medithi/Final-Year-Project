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
struct StreamBuffer_R000059_4807
{
  int head;
  short watermark;
  int checksum;
  int tail;
  int capacity;
  int buffer[3];
};
struct MatrixBlock_R000059_4807
{
  int determinant;
  short dim;
  int scale;
  int buffer[3];
};
struct Transaction_R000059_4807
{
  int fee;
  int auth_code;
  int rate;
  int balance;
  int buffer[3];
};
union ColorPixel_R000059_4807
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
void fn_R000059_4807_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000059_4807 st_1 = {0};
  struct Transaction_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int metric_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_1 > 33)
  {
    acc_1 = ((acc_1 + (metric_1 * 2)) + 5) & 127;
    aux_1 ^= metric_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_2 > 33)
  {
    acc_2 = ((acc_2 + (metric_2 * 2)) + 5) & 127;
    aux_2 ^= metric_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_2) + 11) & 127;
    aux_2 += 3;
  }
  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_1 == metric_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(b_step_1 == b_step_2);
}

int fn_R000059_4807_0(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int metric = ((st.buffer[0] * 3) + aux) & 63;
  if (metric > 33)
  {
    acc = ((acc + (metric * 2)) + 5) & 127;
    aux ^= metric & 15;
  }
  else
  {
    acc = ((acc - metric) + 11) & 127;
    aux += 3;
  }
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 4)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000059_4807_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000059_4807 st_1 = {0};
  struct StreamBuffer_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  switch ((p0_1 + aux_1) & 3)
  {
    case 3:
      acc_1 = (acc_1 + 14) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 5) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 8) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 3:
      acc_2 = (acc_2 + 14) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 5) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 8) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000059_4807_1(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  switch ((p0 + aux) & 3)
  {
    case 3:
      acc = (acc + 14) & 127;
      break;

    case 0:
      acc = (acc + 5) & 127;
      break;

    case 2:
      acc = (acc + 8) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  return (acc + aux) & 127;
}

void fn_R000059_4807_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000059_4807 st_1 = {0};
  struct Transaction_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 6) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 4) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 17) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 2:
      acc_2 = (acc_2 + 6) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 4) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 17) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 2) && (loop_ctr_2 < 2))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000059_4807_2(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 4)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 6) & 127;
      break;

    case 1:
      acc = (acc + 4) & 127;
      break;

    case 3:
      acc = (acc + 17) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int loop_ctr = 0;
  while (loop_ctr < 2)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  return (acc + aux) & 127;
}

void fn_R000059_4807_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000059_4807 st_1 = {0};
  struct Transaction_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 2) && (loop_ctr_2 < 2))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 3)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 3)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  switch ((p0_1 + aux_1) & 3)
  {
    case 0:
      acc_1 = (acc_1 + 8) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 8) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 14) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 0:
      acc_2 = (acc_2 + 8) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 8) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 14) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000059_4807_3(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int loop_ctr = 0;
  while (loop_ctr < 2)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 3)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  switch ((p0 + aux) & 3)
  {
    case 0:
      acc = (acc + 8) & 127;
      break;

    case 2:
      acc = (acc + 8) & 127;
      break;

    case 1:
      acc = (acc + 14) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  return (acc + aux) & 127;
}

void fn_R000059_4807_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000059_4807 st_1 = {0};
  struct StreamBuffer_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 2) && (loop_ctr_2 < 2))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000059_4807_4(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 4)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int loop_ctr = 0;
  while (loop_ctr < 2)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000059_4807_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000059_4807 st_1 = {0};
  struct MatrixBlock_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int delta_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_1 > 44)
  {
    acc_1 = ((acc_1 + (delta_1 * 2)) + 5) & 127;
    aux_1 ^= delta_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_2 > 44)
  {
    acc_2 = ((acc_2 + (delta_2 * 2)) + 5) & 127;
    aux_2 ^= delta_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_2) + 11) & 127;
    aux_2 += 3;
  }
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_1 == delta_2);
  assert(loop_ctr_1 == loop_ctr_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000059_4807_5(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int delta = ((st.buffer[0] * 3) + aux) & 63;
  if (delta > 44)
  {
    acc = ((acc + (delta * 2)) + 5) & 127;
    aux ^= delta & 15;
  }
  else
  {
    acc = ((acc - delta) + 11) & 127;
    aux += 3;
  }
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000059_4807_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000059_4807 st_1 = {0};
  struct StreamBuffer_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  switch ((p0_1 + aux_1) & 3)
  {
    case 3:
      acc_1 = (acc_1 + 13) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 6) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 11) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 3:
      acc_2 = (acc_2 + 13) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 6) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 11) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000059_4807_6(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  switch ((p0 + aux) & 3)
  {
    case 3:
      acc = (acc + 13) & 127;
      break;

    case 0:
      acc = (acc + 6) & 127;
      break;

    case 1:
      acc = (acc + 11) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 4)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  return (acc + aux) & 127;
}

void fn_R000059_4807_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000059_4807 st_1 = {0};
  struct StreamBuffer_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000059_4807_7(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 4)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  return (acc + aux) & 127;
}

void fn_R000059_4807_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000059_4807 st_1 = {0};
  struct MatrixBlock_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 5) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 4) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 17) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 2:
      acc_2 = (acc_2 + 5) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 4) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 17) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  int checksum_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_1 > 21)
  {
    acc_1 = ((acc_1 + (checksum_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_2 > 21)
  {
    acc_2 = ((acc_2 + (checksum_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  assert(checksum_1 == checksum_2);
}

int fn_R000059_4807_8(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 5) & 127;
      break;

    case 3:
      acc = (acc + 4) & 127;
      break;

    case 0:
      acc = (acc + 17) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  int checksum = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum > 21)
  {
    acc = ((acc + (checksum * 2)) + 5) & 127;
    aux ^= checksum & 15;
  }
  else
  {
    acc = ((acc - checksum) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000059_4807_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000059_4807 st_1 = {0};
  struct Transaction_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  int mask_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_1 > 34)
  {
    acc_1 = ((acc_1 + (mask_1 * 2)) + 5) & 127;
    aux_1 ^= mask_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_2 > 34)
  {
    acc_2 = ((acc_2 + (mask_2 * 2)) + 5) & 127;
    aux_2 ^= mask_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_2) + 11) & 127;
    aux_2 += 3;
  }
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(mask_1 == mask_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000059_4807_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  int mask = ((st.buffer[0] * 3) + aux) & 63;
  if (mask > 34)
  {
    acc = ((acc + (mask * 2)) + 5) & 127;
    aux ^= mask & 15;
  }
  else
  {
    acc = ((acc - mask) + 11) & 127;
    aux += 3;
  }
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000059_4807_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000059_4807 st_1 = {0};
  struct Transaction_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  switch ((p0_1 + aux_1) & 3)
  {
    case 3:
      acc_1 = (acc_1 + 8) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 11) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 8) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 3:
      acc_2 = (acc_2 + 8) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 11) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 8) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  int metric_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_1 > 31)
  {
    acc_1 = ((acc_1 + (metric_1 * 2)) + 5) & 127;
    aux_1 ^= metric_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_2 > 31)
  {
    acc_2 = ((acc_2 + (metric_2 * 2)) + 5) & 127;
    aux_2 ^= metric_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  assert(metric_1 == metric_2);
}

int fn_R000059_4807_10(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 4)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  switch ((p0 + aux) & 3)
  {
    case 3:
      acc = (acc + 8) & 127;
      break;

    case 1:
      acc = (acc + 11) & 127;
      break;

    case 0:
      acc = (acc + 8) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  int metric = ((st.buffer[0] * 3) + aux) & 63;
  if (metric > 31)
  {
    acc = ((acc + (metric * 2)) + 5) & 127;
    aux ^= metric & 15;
  }
  else
  {
    acc = ((acc - metric) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000059_4807_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000059_4807 st_1 = {0};
  struct StreamBuffer_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 2)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 2)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  int damping_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_1 > 36)
  {
    acc_1 = ((acc_1 + (damping_1 * 2)) + 5) & 127;
    aux_1 ^= damping_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_2 > 36)
  {
    acc_2 = ((acc_2 + (damping_2 * 2)) + 5) & 127;
    aux_2 ^= damping_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_2) + 11) & 127;
    aux_2 += 3;
  }
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_1 == damping_2);
  assert(loop_ctr_1 == loop_ctr_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000059_4807_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 2)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int damping = ((st.buffer[0] * 3) + aux) & 63;
  if (damping > 36)
  {
    acc = ((acc + (damping * 2)) + 5) & 127;
    aux ^= damping & 15;
  }
  else
  {
    acc = ((acc - damping) + 11) & 127;
    aux += 3;
  }
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  return (acc + aux) & 127;
}

void fn_R000059_4807_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000059_4807 st_1 = {0};
  struct Transaction_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
}

int fn_R000059_4807_12(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 4)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  return (acc + aux) & 127;
}

void fn_R000059_4807_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000059_4807 st_1 = {0};
  struct StreamBuffer_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 2) && (loop_ctr_2 < 2))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int metric_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_1 > 40)
  {
    acc_1 = ((acc_1 + (metric_1 * 2)) + 5) & 127;
    aux_1 ^= metric_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_2 > 40)
  {
    acc_2 = ((acc_2 + (metric_2 * 2)) + 5) & 127;
    aux_2 ^= metric_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(metric_1 == metric_2);
}

int fn_R000059_4807_13(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int loop_ctr = 0;
  while (loop_ctr < 2)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int metric = ((st.buffer[0] * 3) + aux) & 63;
  if (metric > 40)
  {
    acc = ((acc + (metric * 2)) + 5) & 127;
    aux ^= metric & 15;
  }
  else
  {
    acc = ((acc - metric) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000059_4807_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000059_4807 st_1 = {0};
  struct Transaction_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int weight_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_1 > 43)
  {
    acc_1 = ((acc_1 + (weight_1 * 2)) + 5) & 127;
    aux_1 ^= weight_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_2 > 43)
  {
    acc_2 = ((acc_2 + (weight_2 * 2)) + 5) & 127;
    aux_2 ^= weight_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_2) + 11) & 127;
    aux_2 += 3;
  }
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(weight_1 == weight_2);
  assert(b_step_1 == b_step_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000059_4807_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int weight = ((st.buffer[0] * 3) + aux) & 63;
  if (weight > 43)
  {
    acc = ((acc + (weight * 2)) + 5) & 127;
    aux ^= weight & 15;
  }
  else
  {
    acc = ((acc - weight) + 11) & 127;
    aux += 3;
  }
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  return (acc + aux) & 127;
}

void fn_R000059_4807_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000059_4807 st_1 = {0};
  struct MatrixBlock_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int phase_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_1 > 27)
  {
    acc_1 = ((acc_1 + (phase_1 * 2)) + 5) & 127;
    aux_1 ^= phase_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_2 > 27)
  {
    acc_2 = ((acc_2 + (phase_2 * 2)) + 5) & 127;
    aux_2 ^= phase_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_2) + 11) & 127;
    aux_2 += 3;
  }
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  switch ((p0_1 + aux_1) & 3)
  {
    case 3:
      acc_1 = (acc_1 + 14) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 17) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 8) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 3:
      acc_2 = (acc_2 + 14) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 17) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 8) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(phase_1 == phase_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000059_4807_15(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int phase = ((st.buffer[0] * 3) + aux) & 63;
  if (phase > 27)
  {
    acc = ((acc + (phase * 2)) + 5) & 127;
    aux ^= phase & 15;
  }
  else
  {
    acc = ((acc - phase) + 11) & 127;
    aux += 3;
  }
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  switch ((p0 + aux) & 3)
  {
    case 3:
      acc = (acc + 14) & 127;
      break;

    case 2:
      acc = (acc + 17) & 127;
      break;

    case 0:
      acc = (acc + 8) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  return (acc + aux) & 127;
}

void fn_R000059_4807_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000059_4807 st_1 = {0};
  struct StreamBuffer_R000059_4807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 2)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 2)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(b_step_1 == b_step_2);
}

int fn_R000059_4807_16(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000059_4807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 2)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  return (acc + aux) & 127;
}

void main()
{
  int sec_r000059_0_1;
  int sec_r000059_0_2;
  int sec_r000059_1_1;
  int sec_r000059_1_2;
  int sec_r000059_2_1;
  int sec_r000059_2_2;
  int pub_r000059_0_1;
  int pub_r000059_0_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  struct StreamBuffer_R000059_4807 st_var_0_1 = {0};
  struct StreamBuffer_R000059_4807 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000059_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000059_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000059_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000059_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = 7;
  st_var_0_2.buffer[2] = 7;
  struct MatrixBlock_R000059_4807 st_var_1_1 = {0};
  struct MatrixBlock_R000059_4807 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000059_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000059_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000059_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000059_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = 8;
  st_var_1_2.buffer[2] = 8;
  struct Transaction_R000059_4807 st_var_2_1 = {0};
  struct Transaction_R000059_4807 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000059_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000059_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000059_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000059_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = 9;
  st_var_2_2.buffer[2] = 9;
  union ColorPixel_R000059_4807 u_var_1 = {0};
  union ColorPixel_R000059_4807 u_var_2 = {0};
  u_var_1.word = (pub_r000059_0_1 + 0x42) & 255;
  u_var_2.word = (pub_r000059_0_2 + 0x42) & 255;
  int table_1[4] = {7, 13, 29, 41};
  int table_2[4] = {7, 13, 29, 41};
  int res_0_1 = fn_R000059_4807_0(7, 8, 9);
  int res_0_2 = fn_R000059_4807_0(7, 8, 9);
  fn_R000059_4807_0_2(7, 8, 9, 7, 8, 9);
  out_sink_1 = (out_sink_1 + res_0_1) & 255;
  out_sink_2 = (out_sink_2 + res_0_2) & 255;
  chk_sum_1 ^= (res_0_1 << 1) & 127;
  chk_sum_2 ^= (res_0_2 << 1) & 127;
  int res_1_1 = fn_R000059_4807_1(9, 11);
  int res_1_2 = fn_R000059_4807_1(9, 11);
  fn_R000059_4807_1_2(9, 11, 9, 11);
  out_sink_1 = (out_sink_1 + res_1_1) & 255;
  out_sink_2 = (out_sink_2 + res_1_2) & 255;
  chk_sum_1 ^= (res_1_1 << 1) & 127;
  chk_sum_2 ^= (res_1_2 << 1) & 127;
  int res_2_1 = fn_R000059_4807_2(11, 14, 17);
  int res_2_2 = fn_R000059_4807_2(11, 14, 17);
  fn_R000059_4807_2_2(11, 14, 17, 11, 14, 17);
  out_sink_1 = (out_sink_1 + res_2_1) & 255;
  out_sink_2 = (out_sink_2 + res_2_2) & 255;
  chk_sum_1 ^= (res_2_1 << 1) & 127;
  chk_sum_2 ^= (res_2_2 << 1) & 127;
  int res_3_1 = fn_R000059_4807_3(13, 17);
  int res_3_2 = fn_R000059_4807_3(13, 17);
  fn_R000059_4807_3_2(13, 17, 13, 17);
  out_sink_1 = (out_sink_1 + res_3_1) & 255;
  out_sink_2 = (out_sink_2 + res_3_2) & 255;
  chk_sum_1 ^= (res_3_1 << 1) & 127;
  chk_sum_2 ^= (res_3_2 << 1) & 127;
  int res_4_1 = fn_R000059_4807_4(15, 20, 25);
  int res_4_2 = fn_R000059_4807_4(15, 20, 25);
  fn_R000059_4807_4_2(15, 20, 25, 15, 20, 25);
  out_sink_1 = (out_sink_1 + res_4_1) & 255;
  out_sink_2 = (out_sink_2 + res_4_2) & 255;
  chk_sum_1 ^= (res_4_1 << 1) & 127;
  chk_sum_2 ^= (res_4_2 << 1) & 127;
  int res_5_1 = fn_R000059_4807_5(17, 23, 29);
  int res_5_2 = fn_R000059_4807_5(17, 23, 29);
  fn_R000059_4807_5_2(17, 23, 29, 17, 23, 29);
  out_sink_1 = (out_sink_1 + res_5_1) & 255;
  out_sink_2 = (out_sink_2 + res_5_2) & 255;
  chk_sum_1 ^= (res_5_1 << 1) & 127;
  chk_sum_2 ^= (res_5_2 << 1) & 127;
  int res_6_1 = fn_R000059_4807_6(19, 26, 33);
  int res_6_2 = fn_R000059_4807_6(19, 26, 33);
  fn_R000059_4807_6_2(19, 26, 33, 19, 26, 33);
  out_sink_1 = (out_sink_1 + res_6_1) & 255;
  out_sink_2 = (out_sink_2 + res_6_2) & 255;
  chk_sum_1 ^= (res_6_1 << 1) & 127;
  chk_sum_2 ^= (res_6_2 << 1) & 127;
  int res_7_1 = fn_R000059_4807_7(21, 29);
  int res_7_2 = fn_R000059_4807_7(21, 29);
  fn_R000059_4807_7_2(21, 29, 21, 29);
  out_sink_1 = (out_sink_1 + res_7_1) & 255;
  out_sink_2 = (out_sink_2 + res_7_2) & 255;
  chk_sum_1 ^= (res_7_1 << 1) & 127;
  chk_sum_2 ^= (res_7_2 << 1) & 127;
  int res_8_1 = fn_R000059_4807_8(23, 32, 41);
  int res_8_2 = fn_R000059_4807_8(23, 32, 41);
  fn_R000059_4807_8_2(23, 32, 41, 23, 32, 41);
  out_sink_1 = (out_sink_1 + res_8_1) & 255;
  out_sink_2 = (out_sink_2 + res_8_2) & 255;
  chk_sum_1 ^= (res_8_1 << 1) & 127;
  chk_sum_2 ^= (res_8_2 << 1) & 127;
  int res_9_1 = fn_R000059_4807_9(25, 35, 45, 55);
  int res_9_2 = fn_R000059_4807_9(25, 35, 45, 55);
  fn_R000059_4807_9_2(25, 35, 45, 55, 25, 35, 45, 55);
  out_sink_1 = (out_sink_1 + res_9_1) & 255;
  out_sink_2 = (out_sink_2 + res_9_2) & 255;
  chk_sum_1 ^= (res_9_1 << 1) & 127;
  chk_sum_2 ^= (res_9_2 << 1) & 127;
  int res_10_1 = fn_R000059_4807_10(27, 38);
  int res_10_2 = fn_R000059_4807_10(27, 38);
  fn_R000059_4807_10_2(27, 38, 27, 38);
  out_sink_1 = (out_sink_1 + res_10_1) & 255;
  out_sink_2 = (out_sink_2 + res_10_2) & 255;
  chk_sum_1 ^= (res_10_1 << 1) & 127;
  chk_sum_2 ^= (res_10_2 << 1) & 127;
  int res_11_1 = fn_R000059_4807_11(29, 41, 53, 65);
  int res_11_2 = fn_R000059_4807_11(29, 41, 53, 65);
  fn_R000059_4807_11_2(29, 41, 53, 65, 29, 41, 53, 65);
  out_sink_1 = (out_sink_1 + res_11_1) & 255;
  out_sink_2 = (out_sink_2 + res_11_2) & 255;
  chk_sum_1 ^= (res_11_1 << 1) & 127;
  chk_sum_2 ^= (res_11_2 << 1) & 127;
  int res_12_1 = fn_R000059_4807_12(31, 44);
  int res_12_2 = fn_R000059_4807_12(31, 44);
  fn_R000059_4807_12_2(31, 44, 31, 44);
  out_sink_1 = (out_sink_1 + res_12_1) & 255;
  out_sink_2 = (out_sink_2 + res_12_2) & 255;
  chk_sum_1 ^= (res_12_1 << 1) & 127;
  chk_sum_2 ^= (res_12_2 << 1) & 127;
  int res_13_1 = fn_R000059_4807_13(33, 47);
  int res_13_2 = fn_R000059_4807_13(33, 47);
  fn_R000059_4807_13_2(33, 47, 33, 47);
  out_sink_1 = (out_sink_1 + res_13_1) & 255;
  out_sink_2 = (out_sink_2 + res_13_2) & 255;
  chk_sum_1 ^= (res_13_1 << 1) & 127;
  chk_sum_2 ^= (res_13_2 << 1) & 127;
  int res_14_1 = fn_R000059_4807_14(35, 50, 65, 80);
  int res_14_2 = fn_R000059_4807_14(35, 50, 65, 80);
  fn_R000059_4807_14_2(35, 50, 65, 80, 35, 50, 65, 80);
  out_sink_1 = (out_sink_1 + res_14_1) & 255;
  out_sink_2 = (out_sink_2 + res_14_2) & 255;
  chk_sum_1 ^= (res_14_1 << 1) & 127;
  chk_sum_2 ^= (res_14_2 << 1) & 127;
  int res_15_1 = fn_R000059_4807_15(37, 53);
  int res_15_2 = fn_R000059_4807_15(37, 53);
  fn_R000059_4807_15_2(37, 53, 37, 53);
  out_sink_1 = (out_sink_1 + res_15_1) & 255;
  out_sink_2 = (out_sink_2 + res_15_2) & 255;
  chk_sum_1 ^= (res_15_1 << 1) & 127;
  chk_sum_2 ^= (res_15_2 << 1) & 127;
  int res_16_1 = fn_R000059_4807_16(39, 56, 73);
  int res_16_2 = fn_R000059_4807_16(39, 56, 73);
  fn_R000059_4807_16_2(39, 56, 73, 39, 56, 73);
  out_sink_1 = (out_sink_1 + res_16_1) & 255;
  out_sink_2 = (out_sink_2 + res_16_2) & 255;
  chk_sum_1 ^= (res_16_1 << 1) & 127;
  chk_sum_2 ^= (res_16_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 1) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 1) & 15;
  int stage_v_0_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_0_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= stage_v_0_1;
  chk_sum_2 ^= stage_v_0_2;
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 5) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 8) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = (st_var_2_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_2_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = (st_var_1_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_1_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = ((st_var_2_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_2_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 53)
    {
      chk_sum_1 ^= stage_v_11_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_11_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 53)
    {
      chk_sum_2 ^= stage_v_11_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = ((st_var_0_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_0_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 25)
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
  if (stage_v_15_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 25)
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
  int stage_v_16_1 = ((st_var_1_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_1_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 33)
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
  if (stage_v_16_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 33)
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
  int stage_v_17_1 = ((st_var_2_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_2_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 52)
    {
      chk_sum_1 ^= stage_v_17_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_17_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 52)
    {
      chk_sum_2 ^= stage_v_17_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_18_1 = ((st_var_0_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_0_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 26)
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
  if (stage_v_18_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 26)
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
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 21) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  int stage_v_21_1 = (st_var_0_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_0_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = ((st_var_1_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_1_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 41)
    {
      chk_sum_1 ^= stage_v_22_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_22_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 41)
    {
      chk_sum_2 ^= stage_v_22_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((st_var_0_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_0_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 44)
    {
      chk_sum_1 ^= stage_v_27_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_27_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 44)
    {
      chk_sum_2 ^= stage_v_27_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((st_var_2_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_2_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 37)
    {
      chk_sum_1 ^= stage_v_29_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_29_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 37)
    {
      chk_sum_2 ^= stage_v_29_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((st_var_1_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_1_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 39)
    {
      chk_sum_1 ^= stage_v_31_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_31_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 39)
    {
      chk_sum_2 ^= stage_v_31_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = table_1[1];
  int stage_v_33_2 = table_2[1];
  table_1[1] = (table_1[2] + 67) & 63;
  table_2[1] = (table_2[2] + 67) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 35) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = table_1[0];
  int stage_v_36_2 = table_2[0];
  table_1[0] = (table_1[1] + 73) & 63;
  table_2[0] = (table_2[1] + 73) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
  int stage_v_38_1 = ((st_var_2_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_2_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 40)
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
  if (stage_v_38_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 40)
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
  int stage_v_40_1 = (st_var_1_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_1_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = ((st_var_0_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_0_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 44)
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
  if (stage_v_42_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 44)
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
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 45) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 45) & 15;
  int stage_v_44_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_44_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= stage_v_44_1;
  chk_sum_2 ^= stage_v_44_2;
  int stage_v_45_1 = (st_var_0_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_0_2.buffer[0] ^ 48) & 3;
  switch (stage_v_45_1)
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

  switch (stage_v_45_2)
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

  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_47_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 49) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 49) & 15;
  int stage_v_48_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_48_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= stage_v_48_1;
  chk_sum_2 ^= stage_v_48_2;
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 55)
    {
      chk_sum_1 ^= stage_v_49_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_49_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 55)
    {
      chk_sum_2 ^= stage_v_49_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_50_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_50_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_51_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_51_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = table_1[1];
  int stage_v_53_2 = table_2[1];
  table_1[1] = (table_1[2] + 107) & 63;
  table_2[1] = (table_2[2] + 107) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
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
  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
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
  int stage_v_59_1 = ((st_var_2_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_2_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 39)
    {
      chk_sum_1 ^= stage_v_59_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_59_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 39)
    {
      chk_sum_2 ^= stage_v_59_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_60_1 = ((st_var_0_1.buffer[0] * 2) + 187) & 63;
  int stage_v_60_2 = ((st_var_0_2.buffer[0] * 2) + 187) & 63;
  if (stage_v_60_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_60_1) - 5) & 255;
    if (stage_v_60_1 > 38)
    {
      chk_sum_1 ^= stage_v_60_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_60_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_60_2) - 5) & 255;
    if (stage_v_60_2 > 38)
    {
      chk_sum_2 ^= stage_v_60_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_61_1 = ((st_var_1_1.buffer[1] * 2) + 190) & 63;
  int stage_v_61_2 = ((st_var_1_2.buffer[1] * 2) + 190) & 63;
  if (stage_v_61_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_61_1) - 5) & 255;
    if (stage_v_61_1 > 47)
    {
      chk_sum_1 ^= stage_v_61_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_61_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_61_2) - 5) & 255;
    if (stage_v_61_2 > 47)
    {
      chk_sum_2 ^= stage_v_61_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 63) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 63) & 15;
  int stage_v_62_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_62_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= stage_v_62_1;
  chk_sum_2 ^= stage_v_62_2;
  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  int stage_v_64_1 = (st_var_1_1.buffer[0] ^ 67) & 3;
  int stage_v_64_2 = (st_var_1_2.buffer[0] ^ 67) & 3;
  switch (stage_v_64_1)
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

  switch (stage_v_64_2)
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

  int stage_v_65_1 = (st_var_2_1.buffer[0] ^ 68) & 3;
  int stage_v_65_2 = (st_var_2_2.buffer[0] ^ 68) & 3;
  switch (stage_v_65_1)
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

  switch (stage_v_65_2)
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

  int stage_v_66_1 = table_1[2];
  int stage_v_66_2 = table_2[2];
  table_1[2] = (table_1[3] + 133) & 63;
  table_2[2] = (table_2[3] + 133) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (72 & 31);
  int stage_v_67_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (72 & 31);
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= (stage_v_67_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_67_2 << 1) & 127;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((st_var_1_1.buffer[1] * 2) + 217) & 63;
  int stage_v_70_2 = ((st_var_1_2.buffer[1] * 2) + 217) & 63;
  if (stage_v_70_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_70_1) - 5) & 255;
    if (stage_v_70_1 > 49)
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
  if (stage_v_70_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_70_2) - 5) & 255;
    if (stage_v_70_2 > 49)
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
  int stage_v_71_1 = ((st_var_2_1.buffer[2] * 2) + 220) & 63;
  int stage_v_71_2 = ((st_var_2_2.buffer[2] * 2) + 220) & 63;
  if (stage_v_71_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_71_1) - 5) & 255;
    if (stage_v_71_1 > 41)
    {
      chk_sum_1 ^= stage_v_71_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_71_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_71_2) - 5) & 255;
    if (stage_v_71_2 > 41)
    {
      chk_sum_2 ^= stage_v_71_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_72_1 = (st_var_0_1.buffer[0] ^ 75) & 3;
  int stage_v_72_2 = (st_var_0_2.buffer[0] ^ 75) & 3;
  switch (stage_v_72_1)
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

  switch (stage_v_72_2)
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

  int stage_v_73_1 = ((st_var_1_1.buffer[1] * 2) + 226) & 63;
  int stage_v_73_2 = ((st_var_1_2.buffer[1] * 2) + 226) & 63;
  if (stage_v_73_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_73_1) - 5) & 255;
    if (stage_v_73_1 > 43)
    {
      chk_sum_1 ^= stage_v_73_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_73_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_73_2) - 5) & 255;
    if (stage_v_73_2 > 43)
    {
      chk_sum_2 ^= stage_v_73_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((st_var_0_1.buffer[0] * 2) + 232) & 63;
  int stage_v_75_2 = ((st_var_0_2.buffer[0] * 2) + 232) & 63;
  if (stage_v_75_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_75_1) - 5) & 255;
    if (stage_v_75_1 > 50)
    {
      chk_sum_1 ^= stage_v_75_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_75_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_75_2) - 5) & 255;
    if (stage_v_75_2 > 50)
    {
      chk_sum_2 ^= stage_v_75_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 77) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 77) & 15;
  int stage_v_76_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_76_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= stage_v_76_1;
  chk_sum_2 ^= stage_v_76_2;
  int stage_v_77_1 = (st_var_2_1.buffer[0] ^ 80) & 3;
  int stage_v_77_2 = (st_var_2_2.buffer[0] ^ 80) & 3;
  switch (stage_v_77_1)
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

  switch (stage_v_77_2)
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

  int stage_v_78_1 = (st_var_0_1.buffer[0] ^ 81) & 3;
  int stage_v_78_2 = (st_var_0_2.buffer[0] ^ 81) & 3;
  switch (stage_v_78_1)
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

  switch (stage_v_78_2)
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

  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_80_1 = ((stage_v_80_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_80_2 = ((stage_v_80_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 83) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 83) & 15;
  int stage_v_82_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_82_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= stage_v_82_1;
  chk_sum_2 ^= stage_v_82_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 84) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 84) & 15;
  int stage_v_83_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_83_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= stage_v_83_1;
  chk_sum_2 ^= stage_v_83_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 85) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 85) & 15;
  int stage_v_84_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_84_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  chk_sum_1 ^= stage_v_84_1;
  chk_sum_2 ^= stage_v_84_2;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_85_1 = ((stage_v_85_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_85_2 = ((stage_v_85_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = table_1[2];
  int stage_v_86_2 = table_2[2];
  table_1[2] = (table_1[3] + 173) & 63;
  table_2[2] = (table_2[3] + 173) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_87_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_87_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_87_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_88_1 = table_1[0];
  int stage_v_88_2 = table_2[0];
  table_1[0] = (table_1[1] + 177) & 63;
  table_2[0] = (table_2[1] + 177) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 90) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 90) & 15;
  int stage_v_89_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_89_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= stage_v_89_1;
  chk_sum_2 ^= stage_v_89_2;
  int stage_v_90_1 = ((st_var_0_1.buffer[0] * 2) + 277) & 63;
  int stage_v_90_2 = ((st_var_0_2.buffer[0] * 2) + 277) & 63;
  if (stage_v_90_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_90_1) - 5) & 255;
    if (stage_v_90_1 > 38)
    {
      chk_sum_1 ^= stage_v_90_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_90_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_90_2) - 5) & 255;
    if (stage_v_90_2 > 38)
    {
      chk_sum_2 ^= stage_v_90_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 92) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 92) & 15;
  int stage_v_91_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_91_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  chk_sum_1 ^= stage_v_91_1;
  chk_sum_2 ^= stage_v_91_2;
  int stage_v_92_1 = (st_var_2_1.buffer[0] ^ 95) & 3;
  int stage_v_92_2 = (st_var_2_2.buffer[0] ^ 95) & 3;
  switch (stage_v_92_1)
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

  switch (stage_v_92_2)
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

  int stage_v_93_1 = table_1[1];
  int stage_v_93_2 = table_2[1];
  table_1[1] = (table_1[2] + 187) & 63;
  table_2[1] = (table_2[2] + 187) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_94_1 = ((stage_v_94_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_94_2 = ((stage_v_94_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_95_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_95_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_95_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_96_1 = (st_var_0_1.buffer[0] ^ 99) & 3;
  int stage_v_96_2 = (st_var_0_2.buffer[0] ^ 99) & 3;
  switch (stage_v_96_1)
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

  switch (stage_v_96_2)
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

  int stage_v_97_1 = table_1[1];
  int stage_v_97_2 = table_2[1];
  table_1[1] = (table_1[2] + 195) & 63;
  table_2[1] = (table_2[2] + 195) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (st_var_2_1.buffer[0] ^ 101) & 3;
  int stage_v_98_2 = (st_var_2_2.buffer[0] ^ 101) & 3;
  switch (stage_v_98_1)
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

  switch (stage_v_98_2)
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

  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_99_1 = ((stage_v_99_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_99_2 = ((stage_v_99_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (105 & 31);
  int stage_v_100_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (105 & 31);
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= (stage_v_100_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_100_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 102) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 102) & 15;
  int stage_v_101_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_101_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  chk_sum_1 ^= stage_v_101_1;
  chk_sum_2 ^= stage_v_101_2;
  int stage_v_102_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (107 & 31);
  int stage_v_102_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (107 & 31);
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  chk_sum_1 ^= (stage_v_102_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_102_2 << 1) & 127;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_103_1 = ((stage_v_103_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_103_2 = ((stage_v_103_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (109 & 31);
  int stage_v_104_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (109 & 31);
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  chk_sum_1 ^= (stage_v_104_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_104_2 << 1) & 127;
  int stage_v_105_1 = ((st_var_0_1.buffer[0] * 2) + 322) & 63;
  int stage_v_105_2 = ((st_var_0_2.buffer[0] * 2) + 322) & 63;
  if (stage_v_105_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_105_1) - 5) & 255;
    if (stage_v_105_1 > 25)
    {
      chk_sum_1 ^= stage_v_105_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_105_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_105_2) - 5) & 255;
    if (stage_v_105_2 > 25)
    {
      chk_sum_2 ^= stage_v_105_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_106_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (111 & 31);
  int stage_v_106_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (111 & 31);
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  chk_sum_1 ^= (stage_v_106_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_106_2 << 1) & 127;
  int stage_v_107_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (112 & 31);
  int stage_v_107_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (112 & 31);
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  chk_sum_1 ^= (stage_v_107_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_107_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 109) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 109) & 15;
  int stage_v_108_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_108_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  chk_sum_1 ^= stage_v_108_1;
  chk_sum_2 ^= stage_v_108_2;
  int stage_v_109_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_109_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_109_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_109_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_110_1 = (st_var_2_1.buffer[0] ^ 113) & 3;
  int stage_v_110_2 = (st_var_2_2.buffer[0] ^ 113) & 3;
  switch (stage_v_110_1)
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

  switch (stage_v_110_2)
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

  int stage_v_111_1 = table_1[3];
  int stage_v_111_2 = table_2[3];
  table_1[3] = (table_1[0] + 223) & 63;
  table_2[3] = (table_2[0] + 223) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_112_1 = ((stage_v_112_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_112_2 = ((stage_v_112_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_113_1 = ((stage_v_113_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_113_2 = ((stage_v_113_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = table_1[2];
  int stage_v_114_2 = table_2[2];
  table_1[2] = (table_1[3] + 229) & 63;
  table_2[2] = (table_2[3] + 229) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = (st_var_1_1.buffer[0] ^ 118) & 3;
  int stage_v_115_2 = (st_var_1_2.buffer[0] ^ 118) & 3;
  switch (stage_v_115_1)
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

  switch (stage_v_115_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 117) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 117) & 15;
  int stage_v_116_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_116_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  chk_sum_1 ^= stage_v_116_1;
  chk_sum_2 ^= stage_v_116_2;
  int stage_v_117_1 = (st_var_0_1.buffer[0] ^ 120) & 3;
  int stage_v_117_2 = (st_var_0_2.buffer[0] ^ 120) & 3;
  switch (stage_v_117_1)
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

  switch (stage_v_117_2)
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

  int stage_v_118_1 = ((st_var_1_1.buffer[1] * 2) + 361) & 63;
  int stage_v_118_2 = ((st_var_1_2.buffer[1] * 2) + 361) & 63;
  if (stage_v_118_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_118_1) - 5) & 255;
    if (stage_v_118_1 > 48)
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
  if (stage_v_118_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_118_2) - 5) & 255;
    if (stage_v_118_2 > 48)
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
  int stage_v_119_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_119_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_119_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_119_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 121) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 121) & 15;
  int stage_v_120_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_120_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  chk_sum_1 ^= stage_v_120_1;
  chk_sum_2 ^= stage_v_120_2;
  int stage_v_121_1 = ((st_var_1_1.buffer[1] * 2) + 370) & 63;
  int stage_v_121_2 = ((st_var_1_2.buffer[1] * 2) + 370) & 63;
  if (stage_v_121_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_121_1) - 5) & 255;
    if (stage_v_121_1 > 44)
    {
      chk_sum_1 ^= stage_v_121_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_121_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_121_2) - 5) & 255;
    if (stage_v_121_2 > 44)
    {
      chk_sum_2 ^= stage_v_121_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 123) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 123) & 15;
  int stage_v_122_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_122_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  chk_sum_1 ^= stage_v_122_1;
  chk_sum_2 ^= stage_v_122_2;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_123_1 = ((stage_v_123_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_123_2 = ((stage_v_123_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (st_var_1_1.buffer[0] ^ 127) & 3;
  int stage_v_124_2 = (st_var_1_2.buffer[0] ^ 127) & 3;
  switch (stage_v_124_1)
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

  switch (stage_v_124_2)
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

  int stage_v_125_1 = ((st_var_2_1.buffer[2] * 2) + 382) & 63;
  int stage_v_125_2 = ((st_var_2_2.buffer[2] * 2) + 382) & 63;
  if (stage_v_125_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_125_1) - 5) & 255;
    if (stage_v_125_1 > 45)
    {
      chk_sum_1 ^= stage_v_125_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_125_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_125_2) - 5) & 255;
    if (stage_v_125_2 > 45)
    {
      chk_sum_2 ^= stage_v_125_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_126_1 = table_1[2];
  int stage_v_126_2 = table_2[2];
  table_1[2] = (table_1[3] + 253) & 63;
  table_2[2] = (table_2[3] + 253) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_127_1 = ((stage_v_127_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_127_2 = ((stage_v_127_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_128_1 = ((stage_v_128_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_128_2 = ((stage_v_128_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_129_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_129_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_129_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_130_1 = table_1[2];
  int stage_v_130_2 = table_2[2];
  table_1[2] = (table_1[3] + 261) & 63;
  table_2[2] = (table_2[3] + 261) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (136 & 31);
  int stage_v_131_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (136 & 31);
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  chk_sum_1 ^= (stage_v_131_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_131_2 << 1) & 127;
  int stage_v_132_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (137 & 31);
  int stage_v_132_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (137 & 31);
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  chk_sum_1 ^= (stage_v_132_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_132_2 << 1) & 127;
  int stage_v_133_1 = table_1[1];
  int stage_v_133_2 = table_2[1];
  table_1[1] = (table_1[2] + 267) & 63;
  table_2[1] = (table_2[2] + 267) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (139 & 31);
  int stage_v_134_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (139 & 31);
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  chk_sum_1 ^= (stage_v_134_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_134_2 << 1) & 127;
  int stage_v_135_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (140 & 31);
  int stage_v_135_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (140 & 31);
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  chk_sum_1 ^= (stage_v_135_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_135_2 << 1) & 127;
  int stage_v_136_1 = ((st_var_1_1.buffer[1] * 2) + 415) & 63;
  int stage_v_136_2 = ((st_var_1_2.buffer[1] * 2) + 415) & 63;
  if (stage_v_136_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_136_1) - 5) & 255;
    if (stage_v_136_1 > 35)
    {
      chk_sum_1 ^= stage_v_136_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_136_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_136_2) - 5) & 255;
    if (stage_v_136_2 > 35)
    {
      chk_sum_2 ^= stage_v_136_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 138) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 138) & 15;
  int stage_v_137_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_137_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  chk_sum_1 ^= stage_v_137_1;
  chk_sum_2 ^= stage_v_137_2;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_138_1 = ((stage_v_138_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_138_2 = ((stage_v_138_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_139_1 = ((stage_v_139_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_139_2 = ((stage_v_139_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_140_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_140_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_140_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_141_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_141_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_141_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_141_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_142_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (147 & 31);
  int stage_v_142_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (147 & 31);
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= (stage_v_142_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_142_2 << 1) & 127;
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
  int stage_v_144_1 = table_1[0];
  int stage_v_144_2 = table_2[0];
  table_1[0] = (table_1[1] + 289) & 63;
  table_2[0] = (table_2[1] + 289) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (150 & 31);
  int stage_v_145_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (150 & 31);
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  chk_sum_1 ^= (stage_v_145_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_145_2 << 1) & 127;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_146_1 = ((stage_v_146_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_146_2 = ((stage_v_146_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (152 & 31);
  int stage_v_147_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (152 & 31);
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  chk_sum_1 ^= (stage_v_147_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_147_2 << 1) & 127;
  int stage_v_148_1 = ((st_var_1_1.buffer[1] * 2) + 451) & 63;
  int stage_v_148_2 = ((st_var_1_2.buffer[1] * 2) + 451) & 63;
  if (stage_v_148_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_148_1) - 5) & 255;
    if (stage_v_148_1 > 49)
    {
      chk_sum_1 ^= stage_v_148_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_148_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_148_2) - 5) & 255;
    if (stage_v_148_2 > 49)
    {
      chk_sum_2 ^= stage_v_148_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_149_1 = ((st_var_2_1.buffer[2] * 2) + 454) & 63;
  int stage_v_149_2 = ((st_var_2_2.buffer[2] * 2) + 454) & 63;
  if (stage_v_149_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_149_1) - 5) & 255;
    if (stage_v_149_1 > 29)
    {
      chk_sum_1 ^= stage_v_149_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_149_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_149_2) - 5) & 255;
    if (stage_v_149_2 > 29)
    {
      chk_sum_2 ^= stage_v_149_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_150_1 = table_1[2];
  int stage_v_150_2 = table_2[2];
  table_1[2] = (table_1[3] + 301) & 63;
  table_2[2] = (table_2[3] + 301) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 152) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 152) & 15;
  int stage_v_151_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_151_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  chk_sum_1 ^= stage_v_151_1;
  chk_sum_2 ^= stage_v_151_2;
  int stage_v_152_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (157 & 31);
  int stage_v_152_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (157 & 31);
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  chk_sum_1 ^= (stage_v_152_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_152_2 << 1) & 127;
  int stage_v_153_1 = table_1[1];
  int stage_v_153_2 = table_2[1];
  table_1[1] = (table_1[2] + 307) & 63;
  table_2[1] = (table_2[2] + 307) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 155) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 155) & 15;
  int stage_v_154_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_154_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  chk_sum_1 ^= stage_v_154_1;
  chk_sum_2 ^= stage_v_154_2;
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 157) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 157) & 15;
  int stage_v_156_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_156_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  chk_sum_1 ^= stage_v_156_1;
  chk_sum_2 ^= stage_v_156_2;
  int stage_v_157_1 = (st_var_1_1.buffer[0] ^ 160) & 3;
  int stage_v_157_2 = (st_var_1_2.buffer[0] ^ 160) & 3;
  switch (stage_v_157_1)
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

  switch (stage_v_157_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 159) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 159) & 15;
  int stage_v_158_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_158_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  chk_sum_1 ^= stage_v_158_1;
  chk_sum_2 ^= stage_v_158_2;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_159_1 = ((stage_v_159_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_159_2 = ((stage_v_159_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 161) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 161) & 15;
  int stage_v_160_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_160_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  chk_sum_1 ^= stage_v_160_1;
  chk_sum_2 ^= stage_v_160_2;
  int stage_v_161_1 = ((st_var_2_1.buffer[2] * 2) + 490) & 63;
  int stage_v_161_2 = ((st_var_2_2.buffer[2] * 2) + 490) & 63;
  if (stage_v_161_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_161_1) - 5) & 255;
    if (stage_v_161_1 > 39)
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
  if (stage_v_161_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_161_2) - 5) & 255;
    if (stage_v_161_2 > 39)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 163) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 163) & 15;
  int stage_v_162_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_162_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  chk_sum_1 ^= stage_v_162_1;
  chk_sum_2 ^= stage_v_162_2;
  int stage_v_163_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_163_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_163_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_163_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_164_1 = ((stage_v_164_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_164_2 = ((stage_v_164_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (170 & 31);
  int stage_v_165_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (170 & 31);
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  chk_sum_1 ^= (stage_v_165_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_165_2 << 1) & 127;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_166_1 = ((stage_v_166_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_166_2 = ((stage_v_166_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((st_var_2_1.buffer[2] * 2) + 508) & 63;
  int stage_v_167_2 = ((st_var_2_2.buffer[2] * 2) + 508) & 63;
  if (stage_v_167_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_167_1) - 5) & 255;
    if (stage_v_167_1 > 26)
    {
      chk_sum_1 ^= stage_v_167_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_167_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_167_2) - 5) & 255;
    if (stage_v_167_2 > 26)
    {
      chk_sum_2 ^= stage_v_167_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_168_1 = ((st_var_0_1.buffer[0] * 2) + 511) & 63;
  int stage_v_168_2 = ((st_var_0_2.buffer[0] * 2) + 511) & 63;
  if (stage_v_168_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_168_1) - 5) & 255;
    if (stage_v_168_1 > 52)
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
  if (stage_v_168_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_168_2) - 5) & 255;
    if (stage_v_168_2 > 52)
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
  int stage_v_169_1 = 0;
  int stage_v_169_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_169_1 = ((stage_v_169_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_169_2 = ((stage_v_169_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_170_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_170_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_170_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_171_1 = ((stage_v_171_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_171_2 = ((stage_v_171_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = table_1[0];
  int stage_v_172_2 = table_2[0];
  table_1[0] = (table_1[1] + 345) & 63;
  table_2[0] = (table_2[1] + 345) & 63;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_173_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_173_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_173_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_174_1 = table_1[2];
  int stage_v_174_2 = table_2[2];
  table_1[2] = (table_1[3] + 349) & 63;
  table_2[2] = (table_2[3] + 349) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = (st_var_1_1.buffer[0] ^ 178) & 3;
  int stage_v_175_2 = (st_var_1_2.buffer[0] ^ 178) & 3;
  switch (stage_v_175_1)
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

  switch (stage_v_175_2)
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

  int stage_v_176_1 = 0;
  int stage_v_176_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_176_1 = ((stage_v_176_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_176_2 = ((stage_v_176_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_177_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_177_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_177_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_178_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_178_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_178_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_178_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  if ((sec_r000059_0_1 & 7) > 3)
  {
    out_sink_1 += 77;
  }
  else
  {
    out_sink_1 -= 33;
  }
  if ((sec_r000059_0_2 & 7) > 3)
  {
    out_sink_2 += 77;
  }
  else
  {
    out_sink_2 -= 33;
  }
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000059_0_1 == pub_r000059_0_2);
  __CPROVER_assume(sec_r000059_2_1 != sec_r000059_2_2);
  __CPROVER_assume(sec_r000059_0_1 != sec_r000059_0_2);
  __CPROVER_assume(sec_r000059_1_1 != sec_r000059_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.head == st_var_0_2.head);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.tail == st_var_0_2.tail);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  assert(st_var_1_1.dim == st_var_1_2.dim);
  assert(st_var_1_1.scale == st_var_1_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.fee == st_var_2_2.fee);
  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.balance == st_var_2_2.balance);
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

  assert(res_0_1 == res_0_2);
  assert(res_1_1 == res_1_2);
  assert(res_2_1 == res_2_2);
  assert(res_3_1 == res_3_2);
  assert(res_4_1 == res_4_2);
  assert(res_5_1 == res_5_2);
  assert(res_6_1 == res_6_2);
  assert(res_7_1 == res_7_2);
  assert(res_8_1 == res_8_2);
  assert(res_9_1 == res_9_2);
  assert(res_10_1 == res_10_2);
  assert(res_11_1 == res_11_2);
  assert(res_12_1 == res_12_2);
  assert(res_13_1 == res_13_2);
  assert(res_14_1 == res_14_2);
  assert(res_15_1 == res_15_2);
  assert(res_16_1 == res_16_2);
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
}


