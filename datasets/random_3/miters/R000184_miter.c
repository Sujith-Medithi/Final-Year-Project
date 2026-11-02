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
struct FilterState_R000184_7407
{
  int damping;
  short cutoff;
  int gain_db;
  int prev_in;
  int prev_out;
  int buffer[3];
};
struct SensorNode_R000184_7407
{
  int threshold;
  int gain;
  int reading;
  int calib;
  int status;
  int buffer[3];
};
struct MatrixBlock_R000184_7407
{
  int determinant;
  int dim;
  int trace;
  int scale;
  int buffer[3];
};
union PacketPayload_R000184_7407
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
void fn_R000184_7407_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st_1 = {0};
  struct MatrixBlock_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  switch ((p0_1 + aux_1) & 3)
  {
    case 0:
      acc_1 = (acc_1 + 9) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 15) & 127;
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
      acc_2 = (acc_2 + 9) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 15) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 17) & 127;
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000184_7407_0(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  switch ((p0 + aux) & 3)
  {
    case 0:
      acc = (acc + 9) & 127;
      break;

    case 1:
      acc = (acc + 15) & 127;
      break;

    case 2:
      acc = (acc + 17) & 127;
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

void fn_R000184_7407_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000184_7407 st_1 = {0};
  struct SensorNode_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 11) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 16) & 127;
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
    case 2:
      acc_2 = (acc_2 + 11) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 16) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 14) & 127;
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
}

int fn_R000184_7407_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 11) & 127;
      break;

    case 0:
      acc = (acc + 16) & 127;
      break;

    case 1:
      acc = (acc + 14) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000184_7407_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000184_7407 st_1 = {0};
  struct SensorNode_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 5) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 12) & 127;
      break;

    case 1:
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
      acc_2 = (acc_2 + 12) & 127;
      break;

    case 1:
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000184_7407_2(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 5) & 127;
      break;

    case 3:
      acc = (acc + 12) & 127;
      break;

    case 1:
      acc = (acc + 17) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

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

void fn_R000184_7407_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000184_7407 st_1 = {0};
  struct FilterState_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
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
    case 1:
      acc_1 = (acc_1 + 14) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 8) & 127;
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
    case 1:
      acc_2 = (acc_2 + 14) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 8) & 127;
      break;

    case 0:
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
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

int fn_R000184_7407_3(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  switch ((p0 + aux) & 3)
  {
    case 1:
      acc = (acc + 14) & 127;
      break;

    case 2:
      acc = (acc + 8) & 127;
      break;

    case 0:
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

  return (acc + aux) & 127;
}

void fn_R000184_7407_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000184_7407 st_1 = {0};
  struct FilterState_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 5)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 5)) + st_2.buffer[k_2 % 3]) & 63;
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
  int bound_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_1 > 50)
  {
    acc_1 = ((acc_1 + (bound_1 * 2)) + 5) & 127;
    aux_1 ^= bound_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_2 > 50)
  {
    acc_2 = ((acc_2 + (bound_2 * 2)) + 5) & 127;
    aux_2 ^= bound_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(b_step_1 == b_step_2);
  assert(bound_1 == bound_2);
}

int fn_R000184_7407_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 5)) + st.buffer[k % 3]) & 63;
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
  int bound = ((st.buffer[0] * 3) + aux) & 63;
  if (bound > 50)
  {
    acc = ((acc + (bound * 2)) + 5) & 127;
    aux ^= bound & 15;
  }
  else
  {
    acc = ((acc - bound) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000184_7407_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000184_7407 st_1 = {0};
  struct FilterState_R000184_7407 st_2 = {0};
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

  int coefficient_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_1 > 31)
  {
    acc_1 = ((acc_1 + (coefficient_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_2 > 31)
  {
    acc_2 = ((acc_2 + (coefficient_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_2) + 11) & 127;
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
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 8) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 14) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 12) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 2:
      acc_2 = (acc_2 + 8) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 14) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 12) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(coefficient_1 == coefficient_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000184_7407_5(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int loop_ctr = 0;
  while (loop_ctr < 2)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int coefficient = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient > 31)
  {
    acc = ((acc + (coefficient * 2)) + 5) & 127;
    aux ^= coefficient & 15;
  }
  else
  {
    acc = ((acc - coefficient) + 11) & 127;
    aux += 3;
  }
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 8) & 127;
      break;

    case 1:
      acc = (acc + 14) & 127;
      break;

    case 3:
      acc = (acc + 12) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  return (acc + aux) & 127;
}

void fn_R000184_7407_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st_1 = {0};
  struct MatrixBlock_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 9) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 12) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 7) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 2:
      acc_2 = (acc_2 + 9) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 12) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 7) & 127;
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000184_7407_6(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 9) & 127;
      break;

    case 3:
      acc = (acc + 12) & 127;
      break;

    case 0:
      acc = (acc + 7) & 127;
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

void fn_R000184_7407_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000184_7407 st_1 = {0};
  struct SensorNode_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
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
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 3)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 3)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000184_7407_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 3)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  return (acc + aux) & 127;
}

void fn_R000184_7407_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st_1 = {0};
  struct MatrixBlock_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int damping_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_1 > 32)
  {
    acc_1 = ((acc_1 + (damping_1 * 2)) + 5) & 127;
    aux_1 ^= damping_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_2 > 32)
  {
    acc_2 = ((acc_2 + (damping_2 * 2)) + 5) & 127;
    aux_2 ^= damping_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_2) + 11) & 127;
    aux_2 += 3;
  }
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_1 == damping_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000184_7407_8(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int damping = ((st.buffer[0] * 3) + aux) & 63;
  if (damping > 32)
  {
    acc = ((acc + (damping * 2)) + 5) & 127;
    aux ^= damping & 15;
  }
  else
  {
    acc = ((acc - damping) + 11) & 127;
    aux += 3;
  }
  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 4)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000184_7407_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st_1 = {0};
  struct MatrixBlock_R000184_7407 st_2 = {0};
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
      acc_1 = (acc_1 + 9) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 13) & 127;
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
      acc_2 = (acc_2 + 9) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 13) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 16) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int delta_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_1 > 46)
  {
    acc_1 = ((acc_1 + (delta_1 * 2)) + 5) & 127;
    aux_1 ^= delta_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_2 > 46)
  {
    acc_2 = ((acc_2 + (delta_2 * 2)) + 5) & 127;
    aux_2 ^= delta_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  assert(delta_1 == delta_2);
}

int fn_R000184_7407_9(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 9) & 127;
      break;

    case 1:
      acc = (acc + 13) & 127;
      break;

    case 3:
      acc = (acc + 16) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int delta = ((st.buffer[0] * 3) + aux) & 63;
  if (delta > 46)
  {
    acc = ((acc + (delta * 2)) + 5) & 127;
    aux ^= delta & 15;
  }
  else
  {
    acc = ((acc - delta) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000184_7407_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000184_7407 st_1 = {0};
  struct SensorNode_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 2) && (loop_ctr_2 < 2))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int parity_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_1 > 46)
  {
    acc_1 = ((acc_1 + (parity_1 * 2)) + 5) & 127;
    aux_1 ^= parity_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_2 > 46)
  {
    acc_2 = ((acc_2 + (parity_2 * 2)) + 5) & 127;
    aux_2 ^= parity_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  assert(loop_ctr_1 == loop_ctr_2);
  assert(parity_1 == parity_2);
}

int fn_R000184_7407_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  int loop_ctr = 0;
  while (loop_ctr < 2)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int parity = ((st.buffer[0] * 3) + aux) & 63;
  if (parity > 46)
  {
    acc = ((acc + (parity * 2)) + 5) & 127;
    aux ^= parity & 15;
  }
  else
  {
    acc = ((acc - parity) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000184_7407_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st_1 = {0};
  struct MatrixBlock_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int mask_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_1 > 15)
  {
    acc_1 = ((acc_1 + (mask_1 * 2)) + 5) & 127;
    aux_1 ^= mask_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_2 > 15)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(mask_1 == mask_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000184_7407_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int mask = ((st.buffer[0] * 3) + aux) & 63;
  if (mask > 15)
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

void fn_R000184_7407_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st_1 = {0};
  struct MatrixBlock_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int weight_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_1 > 38)
  {
    acc_1 = ((acc_1 + (weight_1 * 2)) + 5) & 127;
    aux_1 ^= weight_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_2 > 38)
  {
    acc_2 = ((acc_2 + (weight_2 * 2)) + 5) & 127;
    aux_2 ^= weight_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_2) + 11) & 127;
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_1 == weight_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000184_7407_12(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int weight = ((st.buffer[0] * 3) + aux) & 63;
  if (weight > 38)
  {
    acc = ((acc + (weight * 2)) + 5) & 127;
    aux ^= weight & 15;
  }
  else
  {
    acc = ((acc - weight) + 11) & 127;
    aux += 3;
  }
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  return (acc + aux) & 127;
}

void fn_R000184_7407_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000184_7407 st_1 = {0};
  struct FilterState_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  switch ((p0_1 + aux_1) & 3)
  {
    case 3:
      acc_1 = (acc_1 + 6) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 14) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 15) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 3:
      acc_2 = (acc_2 + 6) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 14) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 15) & 127;
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
  int factor_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_1 > 48)
  {
    acc_1 = ((acc_1 + (factor_1 * 2)) + 5) & 127;
    aux_1 ^= factor_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_2 > 48)
  {
    acc_2 = ((acc_2 + (factor_2 * 2)) + 5) & 127;
    aux_2 ^= factor_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_2) + 11) & 127;
    aux_2 += 3;
  }
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(factor_1 == factor_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000184_7407_13(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  switch ((p0 + aux) & 3)
  {
    case 3:
      acc = (acc + 6) & 127;
      break;

    case 2:
      acc = (acc + 14) & 127;
      break;

    case 1:
      acc = (acc + 15) & 127;
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
  int factor = ((st.buffer[0] * 3) + aux) & 63;
  if (factor > 48)
  {
    acc = ((acc + (factor * 2)) + 5) & 127;
    aux ^= factor & 15;
  }
  else
  {
    acc = ((acc - factor) + 11) & 127;
    aux += 3;
  }
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000184_7407_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000184_7407 st_1 = {0};
  struct FilterState_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 2)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 2)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  switch ((p0_1 + aux_1) & 3)
  {
    case 1:
      acc_1 = (acc_1 + 17) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 9) & 127;
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
    case 1:
      acc_2 = (acc_2 + 17) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 9) & 127;
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
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  assert(loop_ctr_1 == loop_ctr_2);
}

int fn_R000184_7407_14(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 2)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  switch ((p0 + aux) & 3)
  {
    case 1:
      acc = (acc + 17) & 127;
      break;

    case 2:
      acc = (acc + 9) & 127;
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
  int loop_ctr = 0;
  while (loop_ctr < 2)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  return (acc + aux) & 127;
}

void fn_R000184_7407_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st_1 = {0};
  struct MatrixBlock_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  switch ((p0_1 + aux_1) & 3)
  {
    case 0:
      acc_1 = (acc_1 + 10) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 5) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 7) & 127;
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

    case 1:
      acc_2 = (acc_2 + 5) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 7) & 127;
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
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int offset_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_1 > 22)
  {
    acc_1 = ((acc_1 + (offset_1 * 2)) + 5) & 127;
    aux_1 ^= offset_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_2 > 22)
  {
    acc_2 = ((acc_2 + (offset_2 * 2)) + 5) & 127;
    aux_2 ^= offset_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(offset_1 == offset_2);
}

int fn_R000184_7407_15(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  switch ((p0 + aux) & 3)
  {
    case 0:
      acc = (acc + 10) & 127;
      break;

    case 1:
      acc = (acc + 5) & 127;
      break;

    case 2:
      acc = (acc + 7) & 127;
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
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int offset = ((st.buffer[0] * 3) + aux) & 63;
  if (offset > 22)
  {
    acc = ((acc + (offset * 2)) + 5) & 127;
    aux ^= offset & 15;
  }
  else
  {
    acc = ((acc - offset) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000184_7407_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000184_7407 st_1 = {0};
  struct SensorNode_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
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

  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 3)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 3)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
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

int fn_R000184_7407_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
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

  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 3)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  return (acc + aux) & 127;
}

void fn_R000184_7407_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000184_7407 st_1 = {0};
  struct SensorNode_R000184_7407 st_2 = {0};
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
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 7) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 16) & 127;
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
    case 2:
      acc_2 = (acc_2 + 7) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 16) & 127;
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
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

int fn_R000184_7407_17(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000184_7407 st = {0};
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
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 7) & 127;
      break;

    case 1:
      acc = (acc + 16) & 127;
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
  return (acc + aux) & 127;
}

void fn_R000184_7407_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st_1 = {0};
  struct MatrixBlock_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int threshold_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_1 > 15)
  {
    acc_1 = ((acc_1 + (threshold_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_2 > 15)
  {
    acc_2 = ((acc_2 + (threshold_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_2) + 11) & 127;
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_1 == threshold_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000184_7407_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int threshold = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold > 15)
  {
    acc = ((acc + (threshold * 2)) + 5) & 127;
    aux ^= threshold & 15;
  }
  else
  {
    acc = ((acc - threshold) + 11) & 127;
    aux += 3;
  }
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

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000184_7407_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000184_7407 st_1 = {0};
  struct SensorNode_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
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
    aux_1 = ((aux_1 + (k_1 * 5)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 5)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  int margin_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_1 > 30)
  {
    acc_1 = ((acc_1 + (margin_1 * 2)) + 5) & 127;
    aux_1 ^= margin_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_2 > 30)
  {
    acc_2 = ((acc_2 + (margin_2 * 2)) + 5) & 127;
    aux_2 ^= margin_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(b_step_1 == b_step_2);
  assert(margin_1 == margin_2);
}

int fn_R000184_7407_19(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 5)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  int margin = ((st.buffer[0] * 3) + aux) & 63;
  if (margin > 30)
  {
    acc = ((acc + (margin * 2)) + 5) & 127;
    aux ^= margin & 15;
  }
  else
  {
    acc = ((acc - margin) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000184_7407_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st_1 = {0};
  struct MatrixBlock_R000184_7407 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
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
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int accumulator_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_1 > 49)
  {
    acc_1 = ((acc_1 + (accumulator_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_2 > 49)
  {
    acc_2 = ((acc_2 + (accumulator_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  assert(loop_ctr_1 == loop_ctr_2);
  assert(accumulator_1 == accumulator_2);
}

int fn_R000184_7407_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000184_7407 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 4)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int accumulator = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator > 49)
  {
    acc = ((acc + (accumulator * 2)) + 5) & 127;
    aux ^= accumulator & 15;
  }
  else
  {
    acc = ((acc - accumulator) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void main()
{
  int sec_r000184_0_1;
  int sec_r000184_0_2;
  int sec_r000184_1_1;
  int sec_r000184_1_2;
  int pub_r000184_0_1;
  int pub_r000184_0_2;
  int pub_r000184_1_1;
  int pub_r000184_1_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  struct FilterState_R000184_7407 st_var_0_1 = {0};
  struct FilterState_R000184_7407 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000184_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000184_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000184_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000184_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = 7;
  st_var_0_2.buffer[2] = 7;
  struct SensorNode_R000184_7407 st_var_1_1 = {0};
  struct SensorNode_R000184_7407 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000184_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000184_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000184_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000184_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = 8;
  st_var_1_2.buffer[2] = 8;
  struct MatrixBlock_R000184_7407 st_var_2_1 = {0};
  struct MatrixBlock_R000184_7407 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000184_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000184_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000184_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000184_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = 9;
  st_var_2_2.buffer[2] = 9;
  union PacketPayload_R000184_7407 u_var_1 = {0};
  union PacketPayload_R000184_7407 u_var_2 = {0};
  u_var_1.word = (pub_r000184_0_1 + 0x42) & 255;
  u_var_2.word = (pub_r000184_0_2 + 0x42) & 255;
  int table_1[4] = {7, 13, 29, 41};
  int table_2[4] = {7, 13, 29, 41};
  int res_0_1 = fn_R000184_7407_0(7, 8, 9);
  int res_0_2 = fn_R000184_7407_0(7, 8, 9);
  fn_R000184_7407_0_2(7, 8, 9, 7, 8, 9);
  out_sink_1 = (out_sink_1 + res_0_1) & 255;
  out_sink_2 = (out_sink_2 + res_0_2) & 255;
  chk_sum_1 ^= (res_0_1 << 1) & 127;
  chk_sum_2 ^= (res_0_2 << 1) & 127;
  int res_1_1 = fn_R000184_7407_1(9, 11, 13, 15);
  int res_1_2 = fn_R000184_7407_1(9, 11, 13, 15);
  fn_R000184_7407_1_2(9, 11, 13, 15, 9, 11, 13, 15);
  out_sink_1 = (out_sink_1 + res_1_1) & 255;
  out_sink_2 = (out_sink_2 + res_1_2) & 255;
  chk_sum_1 ^= (res_1_1 << 1) & 127;
  chk_sum_2 ^= (res_1_2 << 1) & 127;
  int res_2_1 = fn_R000184_7407_2(11, 14);
  int res_2_2 = fn_R000184_7407_2(11, 14);
  fn_R000184_7407_2_2(11, 14, 11, 14);
  out_sink_1 = (out_sink_1 + res_2_1) & 255;
  out_sink_2 = (out_sink_2 + res_2_2) & 255;
  chk_sum_1 ^= (res_2_1 << 1) & 127;
  chk_sum_2 ^= (res_2_2 << 1) & 127;
  int res_3_1 = fn_R000184_7407_3(13, 17, 21);
  int res_3_2 = fn_R000184_7407_3(13, 17, 21);
  fn_R000184_7407_3_2(13, 17, 21, 13, 17, 21);
  out_sink_1 = (out_sink_1 + res_3_1) & 255;
  out_sink_2 = (out_sink_2 + res_3_2) & 255;
  chk_sum_1 ^= (res_3_1 << 1) & 127;
  chk_sum_2 ^= (res_3_2 << 1) & 127;
  int res_4_1 = fn_R000184_7407_4(15, 20, 25, 30);
  int res_4_2 = fn_R000184_7407_4(15, 20, 25, 30);
  fn_R000184_7407_4_2(15, 20, 25, 30, 15, 20, 25, 30);
  out_sink_1 = (out_sink_1 + res_4_1) & 255;
  out_sink_2 = (out_sink_2 + res_4_2) & 255;
  chk_sum_1 ^= (res_4_1 << 1) & 127;
  chk_sum_2 ^= (res_4_2 << 1) & 127;
  int res_5_1 = fn_R000184_7407_5(17, 23, 29);
  int res_5_2 = fn_R000184_7407_5(17, 23, 29);
  fn_R000184_7407_5_2(17, 23, 29, 17, 23, 29);
  out_sink_1 = (out_sink_1 + res_5_1) & 255;
  out_sink_2 = (out_sink_2 + res_5_2) & 255;
  chk_sum_1 ^= (res_5_1 << 1) & 127;
  chk_sum_2 ^= (res_5_2 << 1) & 127;
  int res_6_1 = fn_R000184_7407_6(19, 26);
  int res_6_2 = fn_R000184_7407_6(19, 26);
  fn_R000184_7407_6_2(19, 26, 19, 26);
  out_sink_1 = (out_sink_1 + res_6_1) & 255;
  out_sink_2 = (out_sink_2 + res_6_2) & 255;
  chk_sum_1 ^= (res_6_1 << 1) & 127;
  chk_sum_2 ^= (res_6_2 << 1) & 127;
  int res_7_1 = fn_R000184_7407_7(21, 29, 37, 45);
  int res_7_2 = fn_R000184_7407_7(21, 29, 37, 45);
  fn_R000184_7407_7_2(21, 29, 37, 45, 21, 29, 37, 45);
  out_sink_1 = (out_sink_1 + res_7_1) & 255;
  out_sink_2 = (out_sink_2 + res_7_2) & 255;
  chk_sum_1 ^= (res_7_1 << 1) & 127;
  chk_sum_2 ^= (res_7_2 << 1) & 127;
  int res_8_1 = fn_R000184_7407_8(23, 32, 41);
  int res_8_2 = fn_R000184_7407_8(23, 32, 41);
  fn_R000184_7407_8_2(23, 32, 41, 23, 32, 41);
  out_sink_1 = (out_sink_1 + res_8_1) & 255;
  out_sink_2 = (out_sink_2 + res_8_2) & 255;
  chk_sum_1 ^= (res_8_1 << 1) & 127;
  chk_sum_2 ^= (res_8_2 << 1) & 127;
  int res_9_1 = fn_R000184_7407_9(25, 35);
  int res_9_2 = fn_R000184_7407_9(25, 35);
  fn_R000184_7407_9_2(25, 35, 25, 35);
  out_sink_1 = (out_sink_1 + res_9_1) & 255;
  out_sink_2 = (out_sink_2 + res_9_2) & 255;
  chk_sum_1 ^= (res_9_1 << 1) & 127;
  chk_sum_2 ^= (res_9_2 << 1) & 127;
  int res_10_1 = fn_R000184_7407_10(27, 38, 49, 60);
  int res_10_2 = fn_R000184_7407_10(27, 38, 49, 60);
  fn_R000184_7407_10_2(27, 38, 49, 60, 27, 38, 49, 60);
  out_sink_1 = (out_sink_1 + res_10_1) & 255;
  out_sink_2 = (out_sink_2 + res_10_2) & 255;
  chk_sum_1 ^= (res_10_1 << 1) & 127;
  chk_sum_2 ^= (res_10_2 << 1) & 127;
  int res_11_1 = fn_R000184_7407_11(29, 41, 53, 65);
  int res_11_2 = fn_R000184_7407_11(29, 41, 53, 65);
  fn_R000184_7407_11_2(29, 41, 53, 65, 29, 41, 53, 65);
  out_sink_1 = (out_sink_1 + res_11_1) & 255;
  out_sink_2 = (out_sink_2 + res_11_2) & 255;
  chk_sum_1 ^= (res_11_1 << 1) & 127;
  chk_sum_2 ^= (res_11_2 << 1) & 127;
  int res_12_1 = fn_R000184_7407_12(31, 44);
  int res_12_2 = fn_R000184_7407_12(31, 44);
  fn_R000184_7407_12_2(31, 44, 31, 44);
  out_sink_1 = (out_sink_1 + res_12_1) & 255;
  out_sink_2 = (out_sink_2 + res_12_2) & 255;
  chk_sum_1 ^= (res_12_1 << 1) & 127;
  chk_sum_2 ^= (res_12_2 << 1) & 127;
  int res_13_1 = fn_R000184_7407_13(33, 47);
  int res_13_2 = fn_R000184_7407_13(33, 47);
  fn_R000184_7407_13_2(33, 47, 33, 47);
  out_sink_1 = (out_sink_1 + res_13_1) & 255;
  out_sink_2 = (out_sink_2 + res_13_2) & 255;
  chk_sum_1 ^= (res_13_1 << 1) & 127;
  chk_sum_2 ^= (res_13_2 << 1) & 127;
  int res_14_1 = fn_R000184_7407_14(35, 50);
  int res_14_2 = fn_R000184_7407_14(35, 50);
  fn_R000184_7407_14_2(35, 50, 35, 50);
  out_sink_1 = (out_sink_1 + res_14_1) & 255;
  out_sink_2 = (out_sink_2 + res_14_2) & 255;
  chk_sum_1 ^= (res_14_1 << 1) & 127;
  chk_sum_2 ^= (res_14_2 << 1) & 127;
  int res_15_1 = fn_R000184_7407_15(37, 53);
  int res_15_2 = fn_R000184_7407_15(37, 53);
  fn_R000184_7407_15_2(37, 53, 37, 53);
  out_sink_1 = (out_sink_1 + res_15_1) & 255;
  out_sink_2 = (out_sink_2 + res_15_2) & 255;
  chk_sum_1 ^= (res_15_1 << 1) & 127;
  chk_sum_2 ^= (res_15_2 << 1) & 127;
  int res_16_1 = fn_R000184_7407_16(39, 56, 73, 90);
  int res_16_2 = fn_R000184_7407_16(39, 56, 73, 90);
  fn_R000184_7407_16_2(39, 56, 73, 90, 39, 56, 73, 90);
  out_sink_1 = (out_sink_1 + res_16_1) & 255;
  out_sink_2 = (out_sink_2 + res_16_2) & 255;
  chk_sum_1 ^= (res_16_1 << 1) & 127;
  chk_sum_2 ^= (res_16_2 << 1) & 127;
  int res_17_1 = fn_R000184_7407_17(41, 59, 77);
  int res_17_2 = fn_R000184_7407_17(41, 59, 77);
  fn_R000184_7407_17_2(41, 59, 77, 41, 59, 77);
  out_sink_1 = (out_sink_1 + res_17_1) & 255;
  out_sink_2 = (out_sink_2 + res_17_2) & 255;
  chk_sum_1 ^= (res_17_1 << 1) & 127;
  chk_sum_2 ^= (res_17_2 << 1) & 127;
  int res_18_1 = fn_R000184_7407_18(43, 62, 81, 100);
  int res_18_2 = fn_R000184_7407_18(43, 62, 81, 100);
  fn_R000184_7407_18_2(43, 62, 81, 100, 43, 62, 81, 100);
  out_sink_1 = (out_sink_1 + res_18_1) & 255;
  out_sink_2 = (out_sink_2 + res_18_2) & 255;
  chk_sum_1 ^= (res_18_1 << 1) & 127;
  chk_sum_2 ^= (res_18_2 << 1) & 127;
  int res_19_1 = fn_R000184_7407_19(45, 65, 85);
  int res_19_2 = fn_R000184_7407_19(45, 65, 85);
  fn_R000184_7407_19_2(45, 65, 85, 45, 65, 85);
  out_sink_1 = (out_sink_1 + res_19_1) & 255;
  out_sink_2 = (out_sink_2 + res_19_2) & 255;
  chk_sum_1 ^= (res_19_1 << 1) & 127;
  chk_sum_2 ^= (res_19_2 << 1) & 127;
  int res_20_1 = fn_R000184_7407_20(47, 68, 89, 110);
  int res_20_2 = fn_R000184_7407_20(47, 68, 89, 110);
  fn_R000184_7407_20_2(47, 68, 89, 110, 47, 68, 89, 110);
  out_sink_1 = (out_sink_1 + res_20_1) & 255;
  out_sink_2 = (out_sink_2 + res_20_2) & 255;
  chk_sum_1 ^= (res_20_1 << 1) & 127;
  chk_sum_2 ^= (res_20_2 << 1) & 127;
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 40)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 40)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 38)
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
  if (stage_v_2_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 38)
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
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (st_var_1_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_1_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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

  int stage_v_5_1 = ((st_var_2_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_2_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 46)
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
  if (stage_v_5_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 46)
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
  int stage_v_6_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_6_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_6_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_6_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_7_1 = (st_var_1_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_1_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
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

  switch (stage_v_7_2)
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

  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = ((st_var_0_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_0_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 38)
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
  if (stage_v_9_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 38)
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
  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_11_1 = ((st_var_2_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_2_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 40)
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
  if (stage_v_11_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 40)
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
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 55)
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
  if (stage_v_12_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 55)
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
  if (stage_v_15_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 47)
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
  if (stage_v_15_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 47)
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
  if (stage_v_16_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 40)
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
  if (stage_v_16_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 40)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 18) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  int stage_v_18_1 = (st_var_0_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_0_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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

  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (st_var_2_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_2_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 22) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 23) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
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
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_26_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 28) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  int stage_v_28_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (33 & 31);
  int stage_v_28_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (33 & 31);
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= (stage_v_28_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_28_2 << 1) & 127;
  int stage_v_29_1 = ((st_var_2_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_2_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 36)
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
  if (stage_v_29_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 36)
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
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_31_1 = ((stage_v_31_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_31_2 = ((stage_v_31_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_32_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_32_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_32_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_33_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_33_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  int stage_v_37_1 = (st_var_1_1.buffer[0] ^ 40) & 3;
  int stage_v_37_2 = (st_var_1_2.buffer[0] ^ 40) & 3;
  switch (stage_v_37_1)
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

  switch (stage_v_37_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 39) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (46 & 31);
  int stage_v_41_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (46 & 31);
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= (stage_v_41_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_41_2 << 1) & 127;
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = table_1[3];
  int stage_v_43_2 = table_2[3];
  table_1[3] = (table_1[0] + 87) & 63;
  table_2[3] = (table_2[0] + 87) & 63;
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
  int stage_v_45_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (50 & 31);
  int stage_v_45_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (50 & 31);
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= (stage_v_45_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_45_2 << 1) & 127;
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (st_var_1_1.buffer[0] ^ 52) & 3;
  int stage_v_49_2 = (st_var_1_2.buffer[0] ^ 52) & 3;
  switch (stage_v_49_1)
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

  switch (stage_v_49_2)
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

  int stage_v_50_1 = (st_var_2_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_2_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (56 & 31);
  int stage_v_51_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (56 & 31);
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= (stage_v_51_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_51_2 << 1) & 127;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (st_var_2_1.buffer[0] ^ 56) & 3;
  int stage_v_53_2 = (st_var_2_2.buffer[0] ^ 56) & 3;
  switch (stage_v_53_1)
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

  switch (stage_v_53_2)
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

  int stage_v_54_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_54_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_55_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (60 & 31);
  int stage_v_55_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (60 & 31);
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= (stage_v_55_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_55_2 << 1) & 127;
  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  int stage_v_57_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_57_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_58_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (63 & 31);
  int stage_v_58_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (63 & 31);
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= (stage_v_58_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_58_2 << 1) & 127;
  int stage_v_59_1 = (st_var_2_1.buffer[0] ^ 62) & 3;
  int stage_v_59_2 = (st_var_2_2.buffer[0] ^ 62) & 3;
  switch (stage_v_59_1)
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

  switch (stage_v_59_2)
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
  int stage_v_61_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_61_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_62_1 = table_1[2];
  int stage_v_62_2 = table_2[2];
  table_1[2] = (table_1[3] + 125) & 63;
  table_2[2] = (table_2[3] + 125) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((st_var_0_1.buffer[0] * 2) + 196) & 63;
  int stage_v_63_2 = ((st_var_0_2.buffer[0] * 2) + 196) & 63;
  if (stage_v_63_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_63_1) - 5) & 255;
    if (stage_v_63_1 > 46)
    {
      chk_sum_1 ^= stage_v_63_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_63_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_63_2) - 5) & 255;
    if (stage_v_63_2 > 46)
    {
      chk_sum_2 ^= stage_v_63_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_64_1 = ((st_var_1_1.buffer[1] * 2) + 199) & 63;
  int stage_v_64_2 = ((st_var_1_2.buffer[1] * 2) + 199) & 63;
  if (stage_v_64_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_64_1) - 5) & 255;
    if (stage_v_64_1 > 53)
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
  if (stage_v_64_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_64_2) - 5) & 255;
    if (stage_v_64_2 > 53)
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
  int stage_v_65_1 = table_1[1];
  int stage_v_65_2 = table_2[1];
  table_1[1] = (table_1[2] + 131) & 63;
  table_2[1] = (table_2[2] + 131) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_66_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_66_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_66_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_67_1 = (st_var_1_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_1_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  int stage_v_68_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_68_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_68_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_68_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_71_1 = ((st_var_2_1.buffer[2] * 2) + 220) & 63;
  int stage_v_71_2 = ((st_var_2_2.buffer[2] * 2) + 220) & 63;
  if (stage_v_71_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_71_1) - 5) & 255;
    if (stage_v_71_1 > 49)
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
  if (stage_v_71_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_71_2) - 5) & 255;
    if (stage_v_71_2 > 49)
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
  int stage_v_72_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (77 & 31);
  int stage_v_72_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (77 & 31);
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= (stage_v_72_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_72_2 << 1) & 127;
  int stage_v_73_1 = table_1[1];
  int stage_v_73_2 = table_2[1];
  table_1[1] = (table_1[2] + 147) & 63;
  table_2[1] = (table_2[2] + 147) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (79 & 31);
  int stage_v_74_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (79 & 31);
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  chk_sum_1 ^= (stage_v_74_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_74_2 << 1) & 127;
  int stage_v_75_1 = ((st_var_0_1.buffer[0] * 2) + 232) & 63;
  int stage_v_75_2 = ((st_var_0_2.buffer[0] * 2) + 232) & 63;
  if (stage_v_75_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_75_1) - 5) & 255;
    if (stage_v_75_1 > 28)
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
  if (stage_v_75_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_75_2) - 5) & 255;
    if (stage_v_75_2 > 28)
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
  int stage_v_76_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_76_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_76_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_76_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_77_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_77_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_77_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_77_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_78_1 = (st_var_0_1.buffer[0] ^ 81) & 3;
  int stage_v_78_2 = (st_var_0_2.buffer[0] ^ 81) & 3;
  switch (stage_v_78_1)
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

  switch (stage_v_78_2)
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
  int stage_v_80_1 = ((st_var_2_1.buffer[2] * 2) + 247) & 63;
  int stage_v_80_2 = ((st_var_2_2.buffer[2] * 2) + 247) & 63;
  if (stage_v_80_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_80_1) - 5) & 255;
    if (stage_v_80_1 > 37)
    {
      chk_sum_1 ^= stage_v_80_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_80_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_80_2) - 5) & 255;
    if (stage_v_80_2 > 37)
    {
      chk_sum_2 ^= stage_v_80_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 82) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 82) & 15;
  int stage_v_81_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_81_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  chk_sum_1 ^= stage_v_81_1;
  chk_sum_2 ^= stage_v_81_2;
  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_83_1 = ((stage_v_83_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_83_2 = ((stage_v_83_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = table_1[0];
  int stage_v_84_2 = table_2[0];
  table_1[0] = (table_1[1] + 169) & 63;
  table_2[0] = (table_2[1] + 169) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 86) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 86) & 15;
  int stage_v_85_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_85_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= stage_v_85_1;
  chk_sum_2 ^= stage_v_85_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 87) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 87) & 15;
  int stage_v_86_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_86_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= stage_v_86_1;
  chk_sum_2 ^= stage_v_86_2;
  int stage_v_87_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (92 & 31);
  int stage_v_87_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (92 & 31);
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  chk_sum_1 ^= (stage_v_87_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_87_2 << 1) & 127;
  int stage_v_88_1 = table_1[0];
  int stage_v_88_2 = table_2[0];
  table_1[0] = (table_1[1] + 177) & 63;
  table_2[0] = (table_2[1] + 177) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_89_1 = ((stage_v_89_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_89_2 = ((stage_v_89_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((st_var_0_1.buffer[0] * 2) + 277) & 63;
  int stage_v_90_2 = ((st_var_0_2.buffer[0] * 2) + 277) & 63;
  if (stage_v_90_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_90_1) - 5) & 255;
    if (stage_v_90_1 > 32)
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
  if (stage_v_90_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_90_2) - 5) & 255;
    if (stage_v_90_2 > 32)
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
  int stage_v_91_1 = (st_var_1_1.buffer[0] ^ 94) & 3;
  int stage_v_91_2 = (st_var_1_2.buffer[0] ^ 94) & 3;
  switch (stage_v_91_1)
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

  switch (stage_v_91_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 93) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 93) & 15;
  int stage_v_92_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_92_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  chk_sum_1 ^= stage_v_92_1;
  chk_sum_2 ^= stage_v_92_2;
  int stage_v_93_1 = ((st_var_0_1.buffer[0] * 2) + 286) & 63;
  int stage_v_93_2 = ((st_var_0_2.buffer[0] * 2) + 286) & 63;
  if (stage_v_93_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_93_1) - 5) & 255;
    if (stage_v_93_1 > 35)
    {
      chk_sum_1 ^= stage_v_93_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_93_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_93_2) - 5) & 255;
    if (stage_v_93_2 > 35)
    {
      chk_sum_2 ^= stage_v_93_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_94_1 = table_1[2];
  int stage_v_94_2 = table_2[2];
  table_1[2] = (table_1[3] + 189) & 63;
  table_2[2] = (table_2[3] + 189) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (st_var_2_1.buffer[0] ^ 98) & 3;
  int stage_v_95_2 = (st_var_2_2.buffer[0] ^ 98) & 3;
  switch (stage_v_95_1)
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

  switch (stage_v_95_2)
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

  int stage_v_96_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_96_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_96_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_96_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_97_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (102 & 31);
  int stage_v_97_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (102 & 31);
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= (stage_v_97_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_97_2 << 1) & 127;
  int stage_v_98_1 = (st_var_2_1.buffer[0] ^ 101) & 3;
  int stage_v_98_2 = (st_var_2_2.buffer[0] ^ 101) & 3;
  switch (stage_v_98_1)
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

  switch (stage_v_98_2)
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

  int stage_v_99_1 = ((st_var_0_1.buffer[0] * 2) + 304) & 63;
  int stage_v_99_2 = ((st_var_0_2.buffer[0] * 2) + 304) & 63;
  if (stage_v_99_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_99_1) - 5) & 255;
    if (stage_v_99_1 > 37)
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
  if (stage_v_99_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_99_2) - 5) & 255;
    if (stage_v_99_2 > 37)
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
  int stage_v_100_1 = (st_var_1_1.buffer[0] ^ 103) & 3;
  int stage_v_100_2 = (st_var_1_2.buffer[0] ^ 103) & 3;
  switch (stage_v_100_1)
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

  switch (stage_v_100_2)
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

  int stage_v_101_1 = ((st_var_2_1.buffer[2] * 2) + 310) & 63;
  int stage_v_101_2 = ((st_var_2_2.buffer[2] * 2) + 310) & 63;
  if (stage_v_101_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_101_1) - 5) & 255;
    if (stage_v_101_1 > 45)
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
  if (stage_v_101_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_101_2) - 5) & 255;
    if (stage_v_101_2 > 45)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 103) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 103) & 15;
  int stage_v_102_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_102_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  chk_sum_1 ^= stage_v_102_1;
  chk_sum_2 ^= stage_v_102_2;
  int stage_v_103_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_103_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_103_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_103_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_104_1 = (st_var_2_1.buffer[0] ^ 107) & 3;
  int stage_v_104_2 = (st_var_2_2.buffer[0] ^ 107) & 3;
  switch (stage_v_104_1)
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

  switch (stage_v_104_2)
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

  int stage_v_105_1 = table_1[1];
  int stage_v_105_2 = table_2[1];
  table_1[1] = (table_1[2] + 211) & 63;
  table_2[1] = (table_2[2] + 211) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (111 & 31);
  int stage_v_106_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (111 & 31);
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  chk_sum_1 ^= (stage_v_106_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_106_2 << 1) & 127;
  int stage_v_107_1 = (st_var_2_1.buffer[0] ^ 110) & 3;
  int stage_v_107_2 = (st_var_2_2.buffer[0] ^ 110) & 3;
  switch (stage_v_107_1)
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

  switch (stage_v_107_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 109) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 109) & 15;
  int stage_v_108_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_108_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  chk_sum_1 ^= stage_v_108_1;
  chk_sum_2 ^= stage_v_108_2;
  int stage_v_109_1 = table_1[1];
  int stage_v_109_2 = table_2[1];
  table_1[1] = (table_1[2] + 219) & 63;
  table_2[1] = (table_2[2] + 219) & 63;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = table_1[2];
  int stage_v_110_2 = table_2[2];
  table_1[2] = (table_1[3] + 221) & 63;
  table_2[2] = (table_2[3] + 221) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (st_var_0_1.buffer[0] ^ 114) & 3;
  int stage_v_111_2 = (st_var_0_2.buffer[0] ^ 114) & 3;
  switch (stage_v_111_1)
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

  switch (stage_v_111_2)
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

  int stage_v_112_1 = ((st_var_1_1.buffer[1] * 2) + 343) & 63;
  int stage_v_112_2 = ((st_var_1_2.buffer[1] * 2) + 343) & 63;
  if (stage_v_112_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_112_1) - 5) & 255;
    if (stage_v_112_1 > 50)
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
  if (stage_v_112_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_112_2) - 5) & 255;
    if (stage_v_112_2 > 50)
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
  int stage_v_113_1 = ((st_var_2_1.buffer[2] * 2) + 346) & 63;
  int stage_v_113_2 = ((st_var_2_2.buffer[2] * 2) + 346) & 63;
  if (stage_v_113_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_113_1) - 5) & 255;
    if (stage_v_113_1 > 32)
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
  if (stage_v_113_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_113_2) - 5) & 255;
    if (stage_v_113_2 > 32)
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
  int stage_v_114_1 = table_1[2];
  int stage_v_114_2 = table_2[2];
  table_1[2] = (table_1[3] + 229) & 63;
  table_2[2] = (table_2[3] + 229) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_115_1 = ((stage_v_115_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_115_2 = ((stage_v_115_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_116_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_116_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_116_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_117_1 = (st_var_0_1.buffer[0] ^ 120) & 3;
  int stage_v_117_2 = (st_var_0_2.buffer[0] ^ 120) & 3;
  switch (stage_v_117_1)
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

  switch (stage_v_117_2)
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

  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_118_1 = ((stage_v_118_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_118_2 = ((stage_v_118_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (124 & 31);
  int stage_v_119_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (124 & 31);
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  chk_sum_1 ^= (stage_v_119_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_119_2 << 1) & 127;
  int stage_v_120_1 = (st_var_0_1.buffer[0] ^ 123) & 3;
  int stage_v_120_2 = (st_var_0_2.buffer[0] ^ 123) & 3;
  switch (stage_v_120_1)
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

  switch (stage_v_120_2)
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

  int stage_v_121_1 = ((st_var_1_1.buffer[1] * 2) + 370) & 63;
  int stage_v_121_2 = ((st_var_1_2.buffer[1] * 2) + 370) & 63;
  if (stage_v_121_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_121_1) - 5) & 255;
    if (stage_v_121_1 > 38)
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
  if (stage_v_121_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_121_2) - 5) & 255;
    if (stage_v_121_2 > 38)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 124) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 124) & 15;
  int stage_v_123_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_123_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  chk_sum_1 ^= stage_v_123_1;
  chk_sum_2 ^= stage_v_123_2;
  int stage_v_124_1 = (st_var_1_1.buffer[0] ^ 127) & 3;
  int stage_v_124_2 = (st_var_1_2.buffer[0] ^ 127) & 3;
  switch (stage_v_124_1)
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

  switch (stage_v_124_2)
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

  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_125_1 = ((stage_v_125_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_125_2 = ((stage_v_125_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
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

  switch (stage_v_127_2)
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

  int stage_v_128_1 = table_1[0];
  int stage_v_128_2 = table_2[0];
  table_1[0] = (table_1[1] + 257) & 63;
  table_2[0] = (table_2[1] + 257) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_129_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_129_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_129_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_130_1 = (st_var_1_1.buffer[0] ^ 133) & 3;
  int stage_v_130_2 = (st_var_1_2.buffer[0] ^ 133) & 3;
  switch (stage_v_130_1)
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

  switch (stage_v_130_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 132) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 132) & 15;
  int stage_v_131_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_131_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  chk_sum_1 ^= stage_v_131_1;
  chk_sum_2 ^= stage_v_131_2;
  int stage_v_132_1 = (st_var_0_1.buffer[0] ^ 135) & 3;
  int stage_v_132_2 = (st_var_0_2.buffer[0] ^ 135) & 3;
  switch (stage_v_132_1)
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

  switch (stage_v_132_2)
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

  int stage_v_133_1 = table_1[1];
  int stage_v_133_2 = table_2[1];
  table_1[1] = (table_1[2] + 267) & 63;
  table_2[1] = (table_2[2] + 267) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 135) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 135) & 15;
  int stage_v_134_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_134_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  chk_sum_1 ^= stage_v_134_1;
  chk_sum_2 ^= stage_v_134_2;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_135_1 = ((stage_v_135_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_135_2 = ((stage_v_135_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = table_1[0];
  int stage_v_136_2 = table_2[0];
  table_1[0] = (table_1[1] + 273) & 63;
  table_2[0] = (table_2[1] + 273) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((st_var_2_1.buffer[2] * 2) + 418) & 63;
  int stage_v_137_2 = ((st_var_2_2.buffer[2] * 2) + 418) & 63;
  if (stage_v_137_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_137_1) - 5) & 255;
    if (stage_v_137_1 > 30)
    {
      chk_sum_1 ^= stage_v_137_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_137_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_137_2) - 5) & 255;
    if (stage_v_137_2 > 30)
    {
      chk_sum_2 ^= stage_v_137_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_138_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_138_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_138_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_138_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_139_1 = table_1[3];
  int stage_v_139_2 = table_2[3];
  table_1[3] = (table_1[0] + 279) & 63;
  table_2[3] = (table_2[0] + 279) & 63;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (st_var_2_1.buffer[0] ^ 143) & 3;
  int stage_v_140_2 = (st_var_2_2.buffer[0] ^ 143) & 3;
  switch (stage_v_140_1)
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

  switch (stage_v_140_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 142) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 142) & 15;
  int stage_v_141_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_141_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  chk_sum_1 ^= stage_v_141_1;
  chk_sum_2 ^= stage_v_141_2;
  int stage_v_142_1 = table_1[2];
  int stage_v_142_2 = table_2[2];
  table_1[2] = (table_1[3] + 285) & 63;
  table_2[2] = (table_2[3] + 285) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_143_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_143_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_143_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 145) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 145) & 15;
  int stage_v_144_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_144_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  chk_sum_1 ^= stage_v_144_1;
  chk_sum_2 ^= stage_v_144_2;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_145_1 = ((stage_v_145_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_145_2 = ((stage_v_145_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  }

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
  int stage_v_148_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (153 & 31);
  int stage_v_148_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (153 & 31);
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  chk_sum_1 ^= (stage_v_148_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_148_2 << 1) & 127;
  int stage_v_149_1 = table_1[1];
  int stage_v_149_2 = table_2[1];
  table_1[1] = (table_1[2] + 299) & 63;
  table_2[1] = (table_2[2] + 299) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((st_var_0_1.buffer[0] * 2) + 457) & 63;
  int stage_v_150_2 = ((st_var_0_2.buffer[0] * 2) + 457) & 63;
  if (stage_v_150_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_150_1) - 5) & 255;
    if (stage_v_150_1 > 42)
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
  if (stage_v_150_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_150_2) - 5) & 255;
    if (stage_v_150_2 > 42)
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
  int stage_v_152_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_152_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_153_1 = ((st_var_0_1.buffer[0] * 2) + 466) & 63;
  int stage_v_153_2 = ((st_var_0_2.buffer[0] * 2) + 466) & 63;
  if (stage_v_153_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_153_1) - 5) & 255;
    if (stage_v_153_1 > 48)
    {
      chk_sum_1 ^= stage_v_153_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_153_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_153_2) - 5) & 255;
    if (stage_v_153_2 > 48)
    {
      chk_sum_2 ^= stage_v_153_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 155) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 155) & 15;
  int stage_v_154_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_154_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  chk_sum_1 ^= stage_v_154_1;
  chk_sum_2 ^= stage_v_154_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 156) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 156) & 15;
  int stage_v_155_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_155_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  chk_sum_1 ^= stage_v_155_1;
  chk_sum_2 ^= stage_v_155_2;
  int stage_v_156_1 = table_1[0];
  int stage_v_156_2 = table_2[0];
  table_1[0] = (table_1[1] + 313) & 63;
  table_2[0] = (table_2[1] + 313) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_157_1 = ((stage_v_157_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_157_2 = ((stage_v_157_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (st_var_2_1.buffer[0] ^ 161) & 3;
  int stage_v_158_2 = (st_var_2_2.buffer[0] ^ 161) & 3;
  switch (stage_v_158_1)
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

  switch (stage_v_158_2)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 161) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 161) & 15;
  int stage_v_160_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_160_2 = (st_var_1_2.buffer[1] * 3) & 63;
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
  int stage_v_162_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_162_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_162_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_162_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_163_1 = table_1[3];
  int stage_v_163_2 = table_2[3];
  table_1[3] = (table_1[0] + 327) & 63;
  table_2[3] = (table_2[0] + 327) & 63;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = table_1[0];
  int stage_v_164_2 = table_2[0];
  table_1[0] = (table_1[1] + 329) & 63;
  table_2[0] = (table_2[1] + 329) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (170 & 31);
  int stage_v_165_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (170 & 31);
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  chk_sum_1 ^= (stage_v_165_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_165_2 << 1) & 127;
  int stage_v_166_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (171 & 31);
  int stage_v_166_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (171 & 31);
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  chk_sum_1 ^= (stage_v_166_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_166_2 << 1) & 127;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_167_1 = ((stage_v_167_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_167_2 = ((stage_v_167_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_168_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_168_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_168_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_169_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (174 & 31);
  int stage_v_169_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (174 & 31);
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  chk_sum_1 ^= (stage_v_169_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_169_2 << 1) & 127;
  int stage_v_170_1 = table_1[2];
  int stage_v_170_2 = table_2[2];
  table_1[2] = (table_1[3] + 341) & 63;
  table_2[2] = (table_2[3] + 341) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_171_1 = ((stage_v_171_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_171_2 = ((stage_v_171_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((st_var_1_1.buffer[1] * 2) + 523) & 63;
  int stage_v_172_2 = ((st_var_1_2.buffer[1] * 2) + 523) & 63;
  if (stage_v_172_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_172_1) - 5) & 255;
    if (stage_v_172_1 > 42)
    {
      chk_sum_1 ^= stage_v_172_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_172_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_172_2) - 5) & 255;
    if (stage_v_172_2 > 42)
    {
      chk_sum_2 ^= stage_v_172_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_173_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_173_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_173_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_173_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_174_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_174_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_174_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_174_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_175_1 = (st_var_1_1.buffer[0] ^ 178) & 3;
  int stage_v_175_2 = (st_var_1_2.buffer[0] ^ 178) & 3;
  switch (stage_v_175_1)
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

  switch (stage_v_175_2)
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

  int s_lut_1[4] = {19, 43, 71, 97};
  int s_lut_2[4] = {19, 43, 71, 97};
  int s_idx_1 = sec_r000184_0_1 & 3;
  int s_idx_2 = sec_r000184_0_2 & 3;
  out_sink_1 += s_lut_1[s_idx_1];
  out_sink_2 += s_lut_2[s_idx_2];
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000184_1_1 != sec_r000184_1_2);
  __CPROVER_assume(pub_r000184_1_1 == pub_r000184_1_2);
  __CPROVER_assume(sec_r000184_0_1 != sec_r000184_0_2);
  __CPROVER_assume(pub_r000184_0_1 == pub_r000184_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.status == st_var_1_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.trace == st_var_2_2.trace);
  assert(st_var_2_1.scale == st_var_2_2.scale);
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
  assert(res_17_1 == res_17_2);
  assert(res_18_1 == res_18_2);
  assert(res_19_1 == res_19_2);
  assert(res_20_1 == res_20_2);
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
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    assert(s_lut_1[i_0] == s_lut_2[i_0]);
  }

  assert(s_idx_1 == s_idx_2);
}


