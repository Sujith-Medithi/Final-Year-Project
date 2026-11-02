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
struct Transaction_R000085_7407
{
  short account_id;
  int auth_code;
  int rate;
  int buffer[3];
};
struct Vector3D_R000085_7407
{
  int heading;
  short coord_x;
  int norm_sq;
  int buffer[3];
};
union RegisterBank_R000085_7407
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
void fn_R000085_7407_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st_1 = {0};
  struct Vector3D_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  switch ((p0_1 + aux_1) & 3)
  {
    case 3:
      acc_1 = (acc_1 + 7) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 9) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 6) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 3:
      acc_2 = (acc_2 + 7) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 9) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 6) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int metric_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_1 > 35)
  {
    acc_1 = ((acc_1 + (metric_1 * 2)) + 5) & 127;
    aux_1 ^= metric_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_2 > 35)
  {
    acc_2 = ((acc_2 + (metric_2 * 2)) + 5) & 127;
    aux_2 ^= metric_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_2) + 11) & 127;
    aux_2 += 3;
  }
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 3)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 3)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(metric_1 == metric_2);
}

int fn_R000085_7407_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  switch ((p0 + aux) & 3)
  {
    case 3:
      acc = (acc + 7) & 127;
      break;

    case 1:
      acc = (acc + 9) & 127;
      break;

    case 0:
      acc = (acc + 6) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int metric = ((st.buffer[0] * 3) + aux) & 63;
  if (metric > 35)
  {
    acc = ((acc + (metric * 2)) + 5) & 127;
    aux ^= metric & 15;
  }
  else
  {
    acc = ((acc - metric) + 11) & 127;
    aux += 3;
  }
  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 3)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  return (acc + aux) & 127;
}

void fn_R000085_7407_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st_1 = {0};
  struct Vector3D_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000085_7407_1(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
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

void fn_R000085_7407_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st_1 = {0};
  struct Vector3D_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  assert(loop_ctr_1 == loop_ctr_2);
}

int fn_R000085_7407_2(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  return (acc + aux) & 127;
}

void fn_R000085_7407_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st_1 = {0};
  struct Vector3D_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 3)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 3)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  int scale_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_1 > 12)
  {
    acc_1 = ((acc_1 + (scale_1 * 2)) + 5) & 127;
    aux_1 ^= scale_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_2 > 12)
  {
    acc_2 = ((acc_2 + (scale_2 * 2)) + 5) & 127;
    aux_2 ^= scale_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_2) + 11) & 127;
    aux_2 += 3;
  }
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 6) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 8) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 16) & 127;
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

    case 0:
      acc_2 = (acc_2 + 8) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 16) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_1 == scale_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000085_7407_3(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 3)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int scale = ((st.buffer[0] * 3) + aux) & 63;
  if (scale > 12)
  {
    acc = ((acc + (scale * 2)) + 5) & 127;
    aux ^= scale & 15;
  }
  else
  {
    acc = ((acc - scale) + 11) & 127;
    aux += 3;
  }
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 6) & 127;
      break;

    case 0:
      acc = (acc + 8) & 127;
      break;

    case 3:
      acc = (acc + 16) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000085_7407_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st_1 = {0};
  struct Vector3D_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
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
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 16) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 14) & 127;
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
    case 2:
      acc_2 = (acc_2 + 16) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 14) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 11) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
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

int fn_R000085_7407_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
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
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 16) & 127;
      break;

    case 0:
      acc = (acc + 14) & 127;
      break;

    case 1:
      acc = (acc + 11) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  return (acc + aux) & 127;
}

void fn_R000085_7407_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000085_7407 st_1 = {0};
  struct Transaction_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 5)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 5)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
}

int fn_R000085_7407_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 5)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  return (acc + aux) & 127;
}

void fn_R000085_7407_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st_1 = {0};
  struct Vector3D_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  int residue_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_1 > 34)
  {
    acc_1 = ((acc_1 + (residue_1 * 2)) + 5) & 127;
    aux_1 ^= residue_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_2 > 34)
  {
    acc_2 = ((acc_2 + (residue_2 * 2)) + 5) & 127;
    aux_2 ^= residue_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_2) + 11) & 127;
    aux_2 += 3;
  }
  switch ((p0_1 + aux_1) & 3)
  {
    case 0:
      acc_1 = (acc_1 + 10) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 4) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 17) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 0:
      acc_2 = (acc_2 + 10) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 4) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 17) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  assert(residue_1 == residue_2);
}

int fn_R000085_7407_6(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  int residue = ((st.buffer[0] * 3) + aux) & 63;
  if (residue > 34)
  {
    acc = ((acc + (residue * 2)) + 5) & 127;
    aux ^= residue & 15;
  }
  else
  {
    acc = ((acc - residue) + 11) & 127;
    aux += 3;
  }
  switch ((p0 + aux) & 3)
  {
    case 0:
      acc = (acc + 10) & 127;
      break;

    case 3:
      acc = (acc + 4) & 127;
      break;

    case 2:
      acc = (acc + 17) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  return (acc + aux) & 127;
}

void fn_R000085_7407_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st_1 = {0};
  struct Vector3D_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  switch ((p0_1 + aux_1) & 3)
  {
    case 3:
      acc_1 = (acc_1 + 14) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 8) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 12) & 127;
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

    case 1:
      acc_2 = (acc_2 + 8) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 12) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
}

int fn_R000085_7407_7(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  switch ((p0 + aux) & 3)
  {
    case 3:
      acc = (acc + 14) & 127;
      break;

    case 1:
      acc = (acc + 8) & 127;
      break;

    case 2:
      acc = (acc + 12) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000085_7407_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000085_7407 st_1 = {0};
  struct Transaction_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000085_7407_8(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
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

void fn_R000085_7407_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st_1 = {0};
  struct Vector3D_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
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
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 2) && (loop_ctr_2 < 2))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
}

int fn_R000085_7407_9(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  int loop_ctr = 0;
  while (loop_ctr < 2)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  return (acc + aux) & 127;
}

void fn_R000085_7407_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000085_7407 st_1 = {0};
  struct Transaction_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
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

int fn_R000085_7407_10(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
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

void fn_R000085_7407_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000085_7407 st_1 = {0};
  struct Transaction_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
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
  int metric_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_1 > 38)
  {
    acc_1 = ((acc_1 + (metric_1 * 2)) + 5) & 127;
    aux_1 ^= metric_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_2 > 38)
  {
    acc_2 = ((acc_2 + (metric_2 * 2)) + 5) & 127;
    aux_2 ^= metric_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_2) + 11) & 127;
    aux_2 += 3;
  }
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 13) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 8) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 9) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 2:
      acc_2 = (acc_2 + 13) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 8) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 9) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(metric_1 == metric_2);
}

int fn_R000085_7407_11(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  int metric = ((st.buffer[0] * 3) + aux) & 63;
  if (metric > 38)
  {
    acc = ((acc + (metric * 2)) + 5) & 127;
    aux ^= metric & 15;
  }
  else
  {
    acc = ((acc - metric) + 11) & 127;
    aux += 3;
  }
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 13) & 127;
      break;

    case 0:
      acc = (acc + 8) & 127;
      break;

    case 3:
      acc = (acc + 9) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  return (acc + aux) & 127;
}

void fn_R000085_7407_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000085_7407 st_1 = {0};
  struct Transaction_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000085_7407_12(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  for (int k = 0; k < 2; k++)
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

void fn_R000085_7407_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st_1 = {0};
  struct Vector3D_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 10) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 6) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 6) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 2:
      acc_2 = (acc_2 + 10) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 6) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 6) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
}

int fn_R000085_7407_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 10) & 127;
      break;

    case 0:
      acc = (acc + 6) & 127;
      break;

    case 3:
      acc = (acc + 6) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  return (acc + aux) & 127;
}

void fn_R000085_7407_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000085_7407 st_1 = {0};
  struct Transaction_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 5)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 5)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  int metric_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_1 > 23)
  {
    acc_1 = ((acc_1 + (metric_1 * 2)) + 5) & 127;
    aux_1 ^= metric_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_2 > 23)
  {
    acc_2 = ((acc_2 + (metric_2 * 2)) + 5) & 127;
    aux_2 ^= metric_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_2) + 11) & 127;
    aux_2 += 3;
  }
  switch ((p0_1 + aux_1) & 3)
  {
    case 3:
      acc_1 = (acc_1 + 14) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 13) & 127;
      break;

    case 1:
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
      acc_2 = (acc_2 + 13) & 127;
      break;

    case 1:
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_1 == metric_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000085_7407_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 5)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int metric = ((st.buffer[0] * 3) + aux) & 63;
  if (metric > 23)
  {
    acc = ((acc + (metric * 2)) + 5) & 127;
    aux ^= metric & 15;
  }
  else
  {
    acc = ((acc - metric) + 11) & 127;
    aux += 3;
  }
  switch ((p0 + aux) & 3)
  {
    case 3:
      acc = (acc + 14) & 127;
      break;

    case 0:
      acc = (acc + 13) & 127;
      break;

    case 1:
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

void fn_R000085_7407_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st_1 = {0};
  struct Vector3D_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 10) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 9) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 10) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 2:
      acc_2 = (acc_2 + 10) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 9) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 10) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int quotient_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_1 > 21)
  {
    acc_1 = ((acc_1 + (quotient_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_2 > 21)
  {
    acc_2 = ((acc_2 + (quotient_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_1 == quotient_2);
}

int fn_R000085_7407_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 10) & 127;
      break;

    case 3:
      acc = (acc + 9) & 127;
      break;

    case 1:
      acc = (acc + 10) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int quotient = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient > 21)
  {
    acc = ((acc + (quotient * 2)) + 5) & 127;
    aux ^= quotient & 15;
  }
  else
  {
    acc = ((acc - quotient) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000085_7407_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st_1 = {0};
  struct Vector3D_R000085_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int residue_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_1 > 21)
  {
    acc_1 = ((acc_1 + (residue_1 * 2)) + 5) & 127;
    aux_1 ^= residue_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_2 > 21)
  {
    acc_2 = ((acc_2 + (residue_2 * 2)) + 5) & 127;
    aux_2 ^= residue_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_2) + 11) & 127;
    aux_2 += 3;
  }
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 17) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 5) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 13) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 2:
      acc_2 = (acc_2 + 17) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 5) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 13) & 127;
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
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_1 == residue_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000085_7407_16(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000085_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int residue = ((st.buffer[0] * 3) + aux) & 63;
  if (residue > 21)
  {
    acc = ((acc + (residue * 2)) + 5) & 127;
    aux ^= residue & 15;
  }
  else
  {
    acc = ((acc - residue) + 11) & 127;
    aux += 3;
  }
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 17) & 127;
      break;

    case 1:
      acc = (acc + 5) & 127;
      break;

    case 0:
      acc = (acc + 13) & 127;
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
  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 4)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  return (acc + aux) & 127;
}

void main()
{
  int sec_r000085_0_1;
  int sec_r000085_0_2;
  int sec_r000085_1_1;
  int sec_r000085_1_2;
  int sec_r000085_2_1;
  int sec_r000085_2_2;
  int pub_r000085_0_1;
  int pub_r000085_0_2;
  int pub_r000085_1_1;
  int pub_r000085_1_2;
  int pub_r000085_2_1;
  int pub_r000085_2_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  struct Transaction_R000085_7407 st_var_0_1 = {0};
  struct Transaction_R000085_7407 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000085_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000085_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000085_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000085_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = 7;
  st_var_0_2.buffer[2] = 7;
  struct Vector3D_R000085_7407 st_var_1_1 = {0};
  struct Vector3D_R000085_7407 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000085_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000085_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000085_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000085_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = 8;
  st_var_1_2.buffer[2] = 8;
  union RegisterBank_R000085_7407 u_var_1 = {0};
  union RegisterBank_R000085_7407 u_var_2 = {0};
  u_var_1.word = (pub_r000085_0_1 + 0x42) & 255;
  u_var_2.word = (pub_r000085_0_2 + 0x42) & 255;
  int table_1[4] = {7, 13, 29, 41};
  int table_2[4] = {7, 13, 29, 41};
  int res_0_1 = fn_R000085_7407_0(7, 8, 9, 10);
  int res_0_2 = fn_R000085_7407_0(7, 8, 9, 10);
  fn_R000085_7407_0_2(7, 8, 9, 10, 7, 8, 9, 10);
  out_sink_1 = (out_sink_1 + res_0_1) & 255;
  out_sink_2 = (out_sink_2 + res_0_2) & 255;
  chk_sum_1 ^= (res_0_1 << 1) & 127;
  chk_sum_2 ^= (res_0_2 << 1) & 127;
  int res_1_1 = fn_R000085_7407_1(9, 11);
  int res_1_2 = fn_R000085_7407_1(9, 11);
  fn_R000085_7407_1_2(9, 11, 9, 11);
  out_sink_1 = (out_sink_1 + res_1_1) & 255;
  out_sink_2 = (out_sink_2 + res_1_2) & 255;
  chk_sum_1 ^= (res_1_1 << 1) & 127;
  chk_sum_2 ^= (res_1_2 << 1) & 127;
  int res_2_1 = fn_R000085_7407_2(11, 14, 17);
  int res_2_2 = fn_R000085_7407_2(11, 14, 17);
  fn_R000085_7407_2_2(11, 14, 17, 11, 14, 17);
  out_sink_1 = (out_sink_1 + res_2_1) & 255;
  out_sink_2 = (out_sink_2 + res_2_2) & 255;
  chk_sum_1 ^= (res_2_1 << 1) & 127;
  chk_sum_2 ^= (res_2_2 << 1) & 127;
  int res_3_1 = fn_R000085_7407_3(13, 17, 21);
  int res_3_2 = fn_R000085_7407_3(13, 17, 21);
  fn_R000085_7407_3_2(13, 17, 21, 13, 17, 21);
  out_sink_1 = (out_sink_1 + res_3_1) & 255;
  out_sink_2 = (out_sink_2 + res_3_2) & 255;
  chk_sum_1 ^= (res_3_1 << 1) & 127;
  chk_sum_2 ^= (res_3_2 << 1) & 127;
  int res_4_1 = fn_R000085_7407_4(15, 20, 25, 30);
  int res_4_2 = fn_R000085_7407_4(15, 20, 25, 30);
  fn_R000085_7407_4_2(15, 20, 25, 30, 15, 20, 25, 30);
  out_sink_1 = (out_sink_1 + res_4_1) & 255;
  out_sink_2 = (out_sink_2 + res_4_2) & 255;
  chk_sum_1 ^= (res_4_1 << 1) & 127;
  chk_sum_2 ^= (res_4_2 << 1) & 127;
  int res_5_1 = fn_R000085_7407_5(17, 23, 29, 35);
  int res_5_2 = fn_R000085_7407_5(17, 23, 29, 35);
  fn_R000085_7407_5_2(17, 23, 29, 35, 17, 23, 29, 35);
  out_sink_1 = (out_sink_1 + res_5_1) & 255;
  out_sink_2 = (out_sink_2 + res_5_2) & 255;
  chk_sum_1 ^= (res_5_1 << 1) & 127;
  chk_sum_2 ^= (res_5_2 << 1) & 127;
  int res_6_1 = fn_R000085_7407_6(19, 26);
  int res_6_2 = fn_R000085_7407_6(19, 26);
  fn_R000085_7407_6_2(19, 26, 19, 26);
  out_sink_1 = (out_sink_1 + res_6_1) & 255;
  out_sink_2 = (out_sink_2 + res_6_2) & 255;
  chk_sum_1 ^= (res_6_1 << 1) & 127;
  chk_sum_2 ^= (res_6_2 << 1) & 127;
  int res_7_1 = fn_R000085_7407_7(21, 29, 37);
  int res_7_2 = fn_R000085_7407_7(21, 29, 37);
  fn_R000085_7407_7_2(21, 29, 37, 21, 29, 37);
  out_sink_1 = (out_sink_1 + res_7_1) & 255;
  out_sink_2 = (out_sink_2 + res_7_2) & 255;
  chk_sum_1 ^= (res_7_1 << 1) & 127;
  chk_sum_2 ^= (res_7_2 << 1) & 127;
  int res_8_1 = fn_R000085_7407_8(23, 32, 41);
  int res_8_2 = fn_R000085_7407_8(23, 32, 41);
  fn_R000085_7407_8_2(23, 32, 41, 23, 32, 41);
  out_sink_1 = (out_sink_1 + res_8_1) & 255;
  out_sink_2 = (out_sink_2 + res_8_2) & 255;
  chk_sum_1 ^= (res_8_1 << 1) & 127;
  chk_sum_2 ^= (res_8_2 << 1) & 127;
  int res_9_1 = fn_R000085_7407_9(25, 35);
  int res_9_2 = fn_R000085_7407_9(25, 35);
  fn_R000085_7407_9_2(25, 35, 25, 35);
  out_sink_1 = (out_sink_1 + res_9_1) & 255;
  out_sink_2 = (out_sink_2 + res_9_2) & 255;
  chk_sum_1 ^= (res_9_1 << 1) & 127;
  chk_sum_2 ^= (res_9_2 << 1) & 127;
  int res_10_1 = fn_R000085_7407_10(27, 38);
  int res_10_2 = fn_R000085_7407_10(27, 38);
  fn_R000085_7407_10_2(27, 38, 27, 38);
  out_sink_1 = (out_sink_1 + res_10_1) & 255;
  out_sink_2 = (out_sink_2 + res_10_2) & 255;
  chk_sum_1 ^= (res_10_1 << 1) & 127;
  chk_sum_2 ^= (res_10_2 << 1) & 127;
  int res_11_1 = fn_R000085_7407_11(29, 41);
  int res_11_2 = fn_R000085_7407_11(29, 41);
  fn_R000085_7407_11_2(29, 41, 29, 41);
  out_sink_1 = (out_sink_1 + res_11_1) & 255;
  out_sink_2 = (out_sink_2 + res_11_2) & 255;
  chk_sum_1 ^= (res_11_1 << 1) & 127;
  chk_sum_2 ^= (res_11_2 << 1) & 127;
  int res_12_1 = fn_R000085_7407_12(31, 44);
  int res_12_2 = fn_R000085_7407_12(31, 44);
  fn_R000085_7407_12_2(31, 44, 31, 44);
  out_sink_1 = (out_sink_1 + res_12_1) & 255;
  out_sink_2 = (out_sink_2 + res_12_2) & 255;
  chk_sum_1 ^= (res_12_1 << 1) & 127;
  chk_sum_2 ^= (res_12_2 << 1) & 127;
  int res_13_1 = fn_R000085_7407_13(33, 47, 61, 75);
  int res_13_2 = fn_R000085_7407_13(33, 47, 61, 75);
  fn_R000085_7407_13_2(33, 47, 61, 75, 33, 47, 61, 75);
  out_sink_1 = (out_sink_1 + res_13_1) & 255;
  out_sink_2 = (out_sink_2 + res_13_2) & 255;
  chk_sum_1 ^= (res_13_1 << 1) & 127;
  chk_sum_2 ^= (res_13_2 << 1) & 127;
  int res_14_1 = fn_R000085_7407_14(35, 50, 65, 80);
  int res_14_2 = fn_R000085_7407_14(35, 50, 65, 80);
  fn_R000085_7407_14_2(35, 50, 65, 80, 35, 50, 65, 80);
  out_sink_1 = (out_sink_1 + res_14_1) & 255;
  out_sink_2 = (out_sink_2 + res_14_2) & 255;
  chk_sum_1 ^= (res_14_1 << 1) & 127;
  chk_sum_2 ^= (res_14_2 << 1) & 127;
  int res_15_1 = fn_R000085_7407_15(37, 53, 69, 85);
  int res_15_2 = fn_R000085_7407_15(37, 53, 69, 85);
  fn_R000085_7407_15_2(37, 53, 69, 85, 37, 53, 69, 85);
  out_sink_1 = (out_sink_1 + res_15_1) & 255;
  out_sink_2 = (out_sink_2 + res_15_2) & 255;
  chk_sum_1 ^= (res_15_1 << 1) & 127;
  chk_sum_2 ^= (res_15_2 << 1) & 127;
  int res_16_1 = fn_R000085_7407_16(39, 56);
  int res_16_2 = fn_R000085_7407_16(39, 56);
  fn_R000085_7407_16_2(39, 56, 39, 56);
  out_sink_1 = (out_sink_1 + res_16_1) & 255;
  out_sink_2 = (out_sink_2 + res_16_2) & 255;
  chk_sum_1 ^= (res_16_1 << 1) & 127;
  chk_sum_2 ^= (res_16_2 << 1) & 127;
  int stage_v_0_1 = table_1[0];
  int stage_v_0_2 = table_2[0];
  table_1[0] = (table_1[1] + 1) & 63;
  table_2[0] = (table_2[1] + 1) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((st_var_0_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_0_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 53)
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
  if (stage_v_2_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 53)
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
  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 29)
    {
      chk_sum_1 ^= stage_v_4_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_4_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 29)
    {
      chk_sum_2 ^= stage_v_4_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = ((st_var_0_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_0_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 39)
    {
      chk_sum_1 ^= stage_v_8_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_8_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 39)
    {
      chk_sum_2 ^= stage_v_8_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
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
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 44)
    {
      chk_sum_1 ^= stage_v_12_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_12_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 44)
    {
      chk_sum_2 ^= stage_v_12_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
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
  int stage_v_17_1 = ((st_var_1_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_1_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 44)
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
  if (stage_v_17_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 44)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_22_1 = (st_var_0_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_0_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = ((st_var_1_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_1_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 36)
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
  if (stage_v_23_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 36)
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
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = table_1[1];
  int stage_v_25_2 = table_2[1];
  table_1[1] = (table_1[2] + 51) & 63;
  table_2[1] = (table_2[2] + 51) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (st_var_0_1.buffer[0] ^ 29) & 3;
  int stage_v_26_2 = (st_var_0_2.buffer[0] ^ 29) & 3;
  switch (stage_v_26_1)
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

  switch (stage_v_26_2)
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

  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((st_var_1_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_1_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 34)
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
  if (stage_v_29_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 34)
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
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  int stage_v_31_1 = ((st_var_1_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_1_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 55)
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
  if (stage_v_31_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 55)
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
  int stage_v_32_1 = ((st_var_0_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_0_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 31)
    {
      chk_sum_1 ^= stage_v_32_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_32_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 31)
    {
      chk_sum_2 ^= stage_v_32_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_33_1 = table_1[1];
  int stage_v_33_2 = table_2[1];
  table_1[1] = (table_1[2] + 67) & 63;
  table_2[1] = (table_2[2] + 67) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
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
  int stage_v_35_1 = (st_var_1_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_1_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
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

  switch (stage_v_35_2)
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

  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 30)
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
  if (stage_v_37_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 30)
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
  int stage_v_38_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (43 & 31);
  int stage_v_38_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (43 & 31);
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= (stage_v_38_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_38_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 40) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_40_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_40_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_40_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = (st_var_0_1.buffer[0] ^ 45) & 3;
  int stage_v_42_2 = (st_var_0_2.buffer[0] ^ 45) & 3;
  switch (stage_v_42_1)
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

  switch (stage_v_42_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 44) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 45) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 45) & 15;
  int stage_v_44_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_44_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= stage_v_44_1;
  chk_sum_2 ^= stage_v_44_2;
  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (52 & 31);
  int stage_v_47_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (52 & 31);
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= (stage_v_47_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_47_2 << 1) & 127;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 50) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 50) & 15;
  int stage_v_49_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_49_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= stage_v_49_1;
  chk_sum_2 ^= stage_v_49_2;
  int stage_v_50_1 = ((st_var_0_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_0_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 50)
    {
      chk_sum_1 ^= stage_v_50_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_50_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 50)
    {
      chk_sum_2 ^= stage_v_50_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 52) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 52) & 15;
  int stage_v_51_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_51_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= stage_v_51_1;
  chk_sum_2 ^= stage_v_51_2;
  int stage_v_52_1 = (st_var_0_1.buffer[0] ^ 55) & 3;
  int stage_v_52_2 = (st_var_0_2.buffer[0] ^ 55) & 3;
  switch (stage_v_52_1)
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

  switch (stage_v_52_2)
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

  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_54_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 56) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 56) & 15;
  int stage_v_55_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_55_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= stage_v_55_1;
  chk_sum_2 ^= stage_v_55_2;
  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  int stage_v_57_1 = ((st_var_1_1.buffer[0] * 2) + 178) & 63;
  int stage_v_57_2 = ((st_var_1_2.buffer[0] * 2) + 178) & 63;
  if (stage_v_57_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_57_1) - 5) & 255;
    if (stage_v_57_1 > 55)
    {
      chk_sum_1 ^= stage_v_57_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_57_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_57_2) - 5) & 255;
    if (stage_v_57_2 > 55)
    {
      chk_sum_2 ^= stage_v_57_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (64 & 31);
  int stage_v_59_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (64 & 31);
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= (stage_v_59_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_59_2 << 1) & 127;
  int stage_v_60_1 = table_1[0];
  int stage_v_60_2 = table_2[0];
  table_1[0] = (table_1[1] + 121) & 63;
  table_2[0] = (table_2[1] + 121) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_61_1 = ((stage_v_61_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_61_2 = ((stage_v_61_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (st_var_0_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_0_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  int stage_v_64_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_64_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 66) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 66) & 15;
  int stage_v_65_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_65_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= stage_v_65_1;
  chk_sum_2 ^= stage_v_65_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 67) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 67) & 15;
  int stage_v_66_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_66_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= stage_v_66_1;
  chk_sum_2 ^= stage_v_66_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 68) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 68) & 15;
  int stage_v_67_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_67_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= stage_v_67_1;
  chk_sum_2 ^= stage_v_67_2;
  int stage_v_68_1 = table_1[0];
  int stage_v_68_2 = table_2[0];
  table_1[0] = (table_1[1] + 137) & 63;
  table_2[0] = (table_2[1] + 137) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (74 & 31);
  int stage_v_69_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (74 & 31);
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= (stage_v_69_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_69_2 << 1) & 127;
  int stage_v_70_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_70_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_71_1 = ((st_var_1_1.buffer[2] * 2) + 220) & 63;
  int stage_v_71_2 = ((st_var_1_2.buffer[2] * 2) + 220) & 63;
  if (stage_v_71_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_71_1) - 5) & 255;
    if (stage_v_71_1 > 30)
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
  if (stage_v_71_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_71_2) - 5) & 255;
    if (stage_v_71_2 > 30)
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
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_72_1 = ((stage_v_72_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_72_2 = ((stage_v_72_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_73_1 = ((stage_v_73_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_73_2 = ((stage_v_73_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
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
  int stage_v_75_1 = ((st_var_1_1.buffer[0] * 2) + 232) & 63;
  int stage_v_75_2 = ((st_var_1_2.buffer[0] * 2) + 232) & 63;
  if (stage_v_75_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_75_1) - 5) & 255;
    if (stage_v_75_1 > 33)
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
  if (stage_v_75_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_75_2) - 5) & 255;
    if (stage_v_75_2 > 33)
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
  int stage_v_76_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (81 & 31);
  int stage_v_76_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (81 & 31);
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= (stage_v_76_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_76_2 << 1) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 78) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 78) & 15;
  int stage_v_77_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_77_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= stage_v_77_1;
  chk_sum_2 ^= stage_v_77_2;
  int stage_v_78_1 = (st_var_0_1.buffer[0] ^ 81) & 3;
  int stage_v_78_2 = (st_var_0_2.buffer[0] ^ 81) & 3;
  switch (stage_v_78_1)
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

  switch (stage_v_78_2)
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
  int stage_v_80_1 = (st_var_0_1.buffer[0] ^ 83) & 3;
  int stage_v_80_2 = (st_var_0_2.buffer[0] ^ 83) & 3;
  switch (stage_v_80_1)
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

  switch (stage_v_80_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 82) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 82) & 15;
  int stage_v_81_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_81_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  chk_sum_1 ^= stage_v_81_1;
  chk_sum_2 ^= stage_v_81_2;
  int stage_v_82_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (87 & 31);
  int stage_v_82_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (87 & 31);
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= (stage_v_82_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_82_2 << 1) & 127;
  int stage_v_83_1 = table_1[3];
  int stage_v_83_2 = table_2[3];
  table_1[3] = (table_1[0] + 167) & 63;
  table_2[3] = (table_2[0] + 167) & 63;
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
  if (stage_v_85_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_85_1) - 5) & 255;
    if (stage_v_85_1 > 43)
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
  if (stage_v_85_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_85_2) - 5) & 255;
    if (stage_v_85_2 > 43)
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
  int stage_v_88_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (93 & 31);
  int stage_v_88_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (93 & 31);
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= (stage_v_88_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_88_2 << 1) & 127;
  int stage_v_89_1 = (st_var_1_1.buffer[0] ^ 92) & 3;
  int stage_v_89_2 = (st_var_1_2.buffer[0] ^ 92) & 3;
  switch (stage_v_89_1)
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

  switch (stage_v_89_2)
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

  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_90_1 = ((stage_v_90_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_90_2 = ((stage_v_90_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = table_1[3];
  int stage_v_91_2 = table_2[3];
  table_1[3] = (table_1[0] + 183) & 63;
  table_2[3] = (table_2[0] + 183) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_92_1 = ((stage_v_92_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_92_2 = ((stage_v_92_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_93_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_93_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_93_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_94_1 = table_1[2];
  int stage_v_94_2 = table_2[2];
  table_1[2] = (table_1[3] + 189) & 63;
  table_2[2] = (table_2[3] + 189) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((st_var_1_1.buffer[2] * 2) + 292) & 63;
  int stage_v_95_2 = ((st_var_1_2.buffer[2] * 2) + 292) & 63;
  if (stage_v_95_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_95_1) - 5) & 255;
    if (stage_v_95_1 > 43)
    {
      chk_sum_1 ^= stage_v_95_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_95_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_95_2) - 5) & 255;
    if (stage_v_95_2 > 43)
    {
      chk_sum_2 ^= stage_v_95_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_96_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_96_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_96_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_96_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 98) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 98) & 15;
  int stage_v_97_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_97_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= stage_v_97_1;
  chk_sum_2 ^= stage_v_97_2;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_98_1 = ((stage_v_98_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_98_2 = ((stage_v_98_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((st_var_1_1.buffer[0] * 2) + 304) & 63;
  int stage_v_99_2 = ((st_var_1_2.buffer[0] * 2) + 304) & 63;
  if (stage_v_99_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_99_1) - 5) & 255;
    if (stage_v_99_1 > 31)
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
  if (stage_v_99_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_99_2) - 5) & 255;
    if (stage_v_99_2 > 31)
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
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_100_1 = ((stage_v_100_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_100_2 = ((stage_v_100_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((st_var_1_1.buffer[2] * 2) + 310) & 63;
  int stage_v_101_2 = ((st_var_1_2.buffer[2] * 2) + 310) & 63;
  if (stage_v_101_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_101_1) - 5) & 255;
    if (stage_v_101_1 > 32)
    {
      chk_sum_1 ^= stage_v_101_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_101_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_101_2) - 5) & 255;
    if (stage_v_101_2 > 32)
    {
      chk_sum_2 ^= stage_v_101_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_102_1 = table_1[2];
  int stage_v_102_2 = table_2[2];
  table_1[2] = (table_1[3] + 205) & 63;
  table_2[2] = (table_2[3] + 205) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((st_var_1_1.buffer[1] * 2) + 316) & 63;
  int stage_v_103_2 = ((st_var_1_2.buffer[1] * 2) + 316) & 63;
  if (stage_v_103_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_103_1) - 5) & 255;
    if (stage_v_103_1 > 25)
    {
      chk_sum_1 ^= stage_v_103_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_103_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_103_2) - 5) & 255;
    if (stage_v_103_2 > 25)
    {
      chk_sum_2 ^= stage_v_103_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_104_1 = ((stage_v_104_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_104_2 = ((stage_v_104_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((st_var_1_1.buffer[0] * 2) + 322) & 63;
  int stage_v_105_2 = ((st_var_1_2.buffer[0] * 2) + 322) & 63;
  if (stage_v_105_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_105_1) - 5) & 255;
    if (stage_v_105_1 > 37)
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
  if (stage_v_105_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_105_2) - 5) & 255;
    if (stage_v_105_2 > 37)
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
  int stage_v_106_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_106_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_106_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_106_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 108) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 108) & 15;
  int stage_v_107_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_107_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  chk_sum_1 ^= stage_v_107_1;
  chk_sum_2 ^= stage_v_107_2;
  int stage_v_108_1 = table_1[0];
  int stage_v_108_2 = table_2[0];
  table_1[0] = (table_1[1] + 217) & 63;
  table_2[0] = (table_2[1] + 217) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = table_1[1];
  int stage_v_109_2 = table_2[1];
  table_1[1] = (table_1[2] + 219) & 63;
  table_2[1] = (table_2[2] + 219) & 63;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_110_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_110_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_110_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_111_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (116 & 31);
  int stage_v_111_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (116 & 31);
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  chk_sum_1 ^= (stage_v_111_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_111_2 << 1) & 127;
  int stage_v_112_1 = ((st_var_0_1.buffer[1] * 2) + 343) & 63;
  int stage_v_112_2 = ((st_var_0_2.buffer[1] * 2) + 343) & 63;
  if (stage_v_112_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_112_1) - 5) & 255;
    if (stage_v_112_1 > 41)
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
  if (stage_v_112_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_112_2) - 5) & 255;
    if (stage_v_112_2 > 41)
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
  int stage_v_113_1 = ((st_var_1_1.buffer[2] * 2) + 346) & 63;
  int stage_v_113_2 = ((st_var_1_2.buffer[2] * 2) + 346) & 63;
  if (stage_v_113_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_113_1) - 5) & 255;
    if (stage_v_113_1 > 25)
    {
      chk_sum_1 ^= stage_v_113_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_113_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_113_2) - 5) & 255;
    if (stage_v_113_2 > 25)
    {
      chk_sum_2 ^= stage_v_113_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_114_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (119 & 31);
  int stage_v_114_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (119 & 31);
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= (stage_v_114_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_114_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 116) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 116) & 15;
  int stage_v_115_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_115_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  chk_sum_1 ^= stage_v_115_1;
  chk_sum_2 ^= stage_v_115_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 117) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 117) & 15;
  int stage_v_116_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_116_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  chk_sum_1 ^= stage_v_116_1;
  chk_sum_2 ^= stage_v_116_2;
  int stage_v_117_1 = (st_var_1_1.buffer[0] ^ 120) & 3;
  int stage_v_117_2 = (st_var_1_2.buffer[0] ^ 120) & 3;
  switch (stage_v_117_1)
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

  switch (stage_v_117_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 119) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 119) & 15;
  int stage_v_118_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_118_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  chk_sum_1 ^= stage_v_118_1;
  chk_sum_2 ^= stage_v_118_2;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_119_1 = ((stage_v_119_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_119_2 = ((stage_v_119_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((st_var_0_1.buffer[0] * 2) + 367) & 63;
  int stage_v_120_2 = ((st_var_0_2.buffer[0] * 2) + 367) & 63;
  if (stage_v_120_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_120_1) - 5) & 255;
    if (stage_v_120_1 > 30)
    {
      chk_sum_1 ^= stage_v_120_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_120_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_120_2) - 5) & 255;
    if (stage_v_120_2 > 30)
    {
      chk_sum_2 ^= stage_v_120_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_121_1 = ((st_var_1_1.buffer[1] * 2) + 370) & 63;
  int stage_v_121_2 = ((st_var_1_2.buffer[1] * 2) + 370) & 63;
  if (stage_v_121_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_121_1) - 5) & 255;
    if (stage_v_121_1 > 49)
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
  if (stage_v_121_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_121_2) - 5) & 255;
    if (stage_v_121_2 > 49)
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
  int stage_v_122_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_122_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_122_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_122_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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
  int stage_v_124_1 = ((st_var_0_1.buffer[1] * 2) + 379) & 63;
  int stage_v_124_2 = ((st_var_0_2.buffer[1] * 2) + 379) & 63;
  if (stage_v_124_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_124_1) - 5) & 255;
    if (stage_v_124_1 > 29)
    {
      chk_sum_1 ^= stage_v_124_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_124_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_124_2) - 5) & 255;
    if (stage_v_124_2 > 29)
    {
      chk_sum_2 ^= stage_v_124_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_125_1 = ((st_var_1_1.buffer[2] * 2) + 382) & 63;
  int stage_v_125_2 = ((st_var_1_2.buffer[2] * 2) + 382) & 63;
  if (stage_v_125_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_125_1) - 5) & 255;
    if (stage_v_125_1 > 39)
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
  if (stage_v_125_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_125_2) - 5) & 255;
    if (stage_v_125_2 > 39)
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
  int stage_v_126_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_126_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_126_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_126_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_127_1 = (st_var_1_1.buffer[0] ^ 130) & 3;
  int stage_v_127_2 = (st_var_1_2.buffer[0] ^ 130) & 3;
  switch (stage_v_127_1)
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

  switch (stage_v_127_2)
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

  int stage_v_128_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_128_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_128_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_128_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_129_1 = table_1[1];
  int stage_v_129_2 = table_2[1];
  table_1[1] = (table_1[2] + 259) & 63;
  table_2[1] = (table_2[2] + 259) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (135 & 31);
  int stage_v_130_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (135 & 31);
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= (stage_v_130_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_130_2 << 1) & 127;
  int stage_v_131_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_131_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_131_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_131_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_132_1 = ((st_var_0_1.buffer[0] * 2) + 403) & 63;
  int stage_v_132_2 = ((st_var_0_2.buffer[0] * 2) + 403) & 63;
  if (stage_v_132_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_132_1) - 5) & 255;
    if (stage_v_132_1 > 30)
    {
      chk_sum_1 ^= stage_v_132_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_132_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_132_2) - 5) & 255;
    if (stage_v_132_2 > 30)
    {
      chk_sum_2 ^= stage_v_132_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_133_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_133_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_133_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_133_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_134_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_134_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_134_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_134_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_135_1 = ((st_var_1_1.buffer[0] * 2) + 412) & 63;
  int stage_v_135_2 = ((st_var_1_2.buffer[0] * 2) + 412) & 63;
  if (stage_v_135_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_135_1) - 5) & 255;
    if (stage_v_135_1 > 43)
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
  if (stage_v_135_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_135_2) - 5) & 255;
    if (stage_v_135_2 > 43)
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
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_136_1 = ((stage_v_136_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_136_2 = ((stage_v_136_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_137_1 = ((stage_v_137_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_137_2 = ((stage_v_137_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 139) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 139) & 15;
  int stage_v_138_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_138_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  chk_sum_1 ^= stage_v_138_1;
  chk_sum_2 ^= stage_v_138_2;
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
  int stage_v_140_1 = table_1[0];
  int stage_v_140_2 = table_2[0];
  table_1[0] = (table_1[1] + 281) & 63;
  table_2[0] = (table_2[1] + 281) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (146 & 31);
  int stage_v_141_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (146 & 31);
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  chk_sum_1 ^= (stage_v_141_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_141_2 << 1) & 127;
  int stage_v_142_1 = table_1[2];
  int stage_v_142_2 = table_2[2];
  table_1[2] = (table_1[3] + 285) & 63;
  table_2[2] = (table_2[3] + 285) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((st_var_1_1.buffer[2] * 2) + 436) & 63;
  int stage_v_143_2 = ((st_var_1_2.buffer[2] * 2) + 436) & 63;
  if (stage_v_143_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_143_1) - 5) & 255;
    if (stage_v_143_1 > 32)
    {
      chk_sum_1 ^= stage_v_143_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_143_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_143_2) - 5) & 255;
    if (stage_v_143_2 > 32)
    {
      chk_sum_2 ^= stage_v_143_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_144_1 = ((st_var_0_1.buffer[0] * 2) + 439) & 63;
  int stage_v_144_2 = ((st_var_0_2.buffer[0] * 2) + 439) & 63;
  if (stage_v_144_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_144_1) - 5) & 255;
    if (stage_v_144_1 > 45)
    {
      chk_sum_1 ^= stage_v_144_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_144_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_144_2) - 5) & 255;
    if (stage_v_144_2 > 45)
    {
      chk_sum_2 ^= stage_v_144_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_145_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_145_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_145_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_145_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 147) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 147) & 15;
  int stage_v_146_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_146_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  chk_sum_1 ^= stage_v_146_1;
  chk_sum_2 ^= stage_v_146_2;
  int stage_v_147_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_147_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_147_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_147_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 149) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 149) & 15;
  int stage_v_148_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_148_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  chk_sum_1 ^= stage_v_148_1;
  chk_sum_2 ^= stage_v_148_2;
  int stage_v_149_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (154 & 31);
  int stage_v_149_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (154 & 31);
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  chk_sum_1 ^= (stage_v_149_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_149_2 << 1) & 127;
  int stage_v_150_1 = table_1[2];
  int stage_v_150_2 = table_2[2];
  table_1[2] = (table_1[3] + 301) & 63;
  table_2[2] = (table_2[3] + 301) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = (st_var_1_1.buffer[0] ^ 154) & 3;
  int stage_v_151_2 = (st_var_1_2.buffer[0] ^ 154) & 3;
  switch (stage_v_151_1)
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

  switch (stage_v_151_2)
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

  int stage_v_152_1 = (st_var_0_1.buffer[0] ^ 155) & 3;
  int stage_v_152_2 = (st_var_0_2.buffer[0] ^ 155) & 3;
  switch (stage_v_152_1)
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

  switch (stage_v_152_2)
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

  int stage_v_153_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_153_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_153_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_153_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 155) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 155) & 15;
  int stage_v_154_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_154_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  chk_sum_1 ^= stage_v_154_1;
  chk_sum_2 ^= stage_v_154_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 156) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 156) & 15;
  int stage_v_155_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_155_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  chk_sum_1 ^= stage_v_155_1;
  chk_sum_2 ^= stage_v_155_2;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_156_1 = ((stage_v_156_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_156_2 = ((stage_v_156_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((st_var_1_1.buffer[1] * 2) + 478) & 63;
  int stage_v_157_2 = ((st_var_1_2.buffer[1] * 2) + 478) & 63;
  if (stage_v_157_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_157_1) - 5) & 255;
    if (stage_v_157_1 > 54)
    {
      chk_sum_1 ^= stage_v_157_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_157_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_157_2) - 5) & 255;
    if (stage_v_157_2 > 54)
    {
      chk_sum_2 ^= stage_v_157_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 159) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 159) & 15;
  int stage_v_158_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_158_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  chk_sum_1 ^= stage_v_158_1;
  chk_sum_2 ^= stage_v_158_2;
  int stage_v_159_1 = ((st_var_1_1.buffer[0] * 2) + 484) & 63;
  int stage_v_159_2 = ((st_var_1_2.buffer[0] * 2) + 484) & 63;
  if (stage_v_159_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_159_1) - 5) & 255;
    if (stage_v_159_1 > 29)
    {
      chk_sum_1 ^= stage_v_159_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_159_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_159_2) - 5) & 255;
    if (stage_v_159_2 > 29)
    {
      chk_sum_2 ^= stage_v_159_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 161) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 161) & 15;
  int stage_v_160_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_160_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  chk_sum_1 ^= stage_v_160_1;
  chk_sum_2 ^= stage_v_160_2;
  int stage_v_161_1 = table_1[1];
  int stage_v_161_2 = table_2[1];
  table_1[1] = (table_1[2] + 323) & 63;
  table_2[1] = (table_2[2] + 323) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((st_var_0_1.buffer[0] * 2) + 493) & 63;
  int stage_v_162_2 = ((st_var_0_2.buffer[0] * 2) + 493) & 63;
  if (stage_v_162_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_162_1) - 5) & 255;
    if (stage_v_162_1 > 28)
    {
      chk_sum_1 ^= stage_v_162_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_162_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_162_2) - 5) & 255;
    if (stage_v_162_2 > 28)
    {
      chk_sum_2 ^= stage_v_162_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_163_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (168 & 31);
  int stage_v_163_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (168 & 31);
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  chk_sum_1 ^= (stage_v_163_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_163_2 << 1) & 127;
  int stage_v_164_1 = ((st_var_0_1.buffer[2] * 2) + 499) & 63;
  int stage_v_164_2 = ((st_var_0_2.buffer[2] * 2) + 499) & 63;
  if (stage_v_164_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_164_1) - 5) & 255;
    if (stage_v_164_1 > 35)
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
  if (stage_v_164_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_164_2) - 5) & 255;
    if (stage_v_164_2 > 35)
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
  int stage_v_165_1 = (st_var_1_1.buffer[0] ^ 168) & 3;
  int stage_v_165_2 = (st_var_1_2.buffer[0] ^ 168) & 3;
  switch (stage_v_165_1)
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

  switch (stage_v_165_2)
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

  int stage_v_166_1 = ((st_var_0_1.buffer[1] * 2) + 505) & 63;
  int stage_v_166_2 = ((st_var_0_2.buffer[1] * 2) + 505) & 63;
  if (stage_v_166_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_166_1) - 5) & 255;
    if (stage_v_166_1 > 37)
    {
      chk_sum_1 ^= stage_v_166_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_166_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_166_2) - 5) & 255;
    if (stage_v_166_2 > 37)
    {
      chk_sum_2 ^= stage_v_166_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_167_1 = (st_var_1_1.buffer[0] ^ 170) & 3;
  int stage_v_167_2 = (st_var_1_2.buffer[0] ^ 170) & 3;
  switch (stage_v_167_1)
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

  switch (stage_v_167_2)
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

  int s_lut_1[4] = {19, 43, 71, 97};
  int s_lut_2[4] = {19, 43, 71, 97};
  int s_idx_1 = sec_r000085_0_1 & 3;
  int s_idx_2 = sec_r000085_0_2 & 3;
  out_sink_1 += s_lut_1[s_idx_1];
  out_sink_2 += s_lut_2[s_idx_2];
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000085_2_1 == pub_r000085_2_2);
  __CPROVER_assume(sec_r000085_0_1 != sec_r000085_0_2);
  __CPROVER_assume(sec_r000085_2_1 != sec_r000085_2_2);
  __CPROVER_assume(pub_r000085_1_1 == pub_r000085_1_2);
  __CPROVER_assume(sec_r000085_1_1 != sec_r000085_1_2);
  __CPROVER_assume(pub_r000085_0_1 == pub_r000085_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
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
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    assert(s_lut_1[i_0] == s_lut_2[i_0]);
  }

  assert(s_idx_1 == s_idx_2);
}


