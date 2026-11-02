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
struct Vector3D_R000078_6707
{
  int coord_z;
  int coord_x;
  short norm_sq;
  int buffer[3];
};
struct StreamBuffer_R000078_6707
{
  int tail;
  int head;
  int watermark;
  int buffer[3];
};
struct AudioFrame_R000078_6707
{
  int rms;
  int channels;
  int envelope;
  int sample_rate;
  short peak;
  int buffer[3];
};
union ColorPixel_R000078_6707
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
void fn_R000078_6707_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st_1 = {0};
  struct Vector3D_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int accumulator_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_1 > 16)
  {
    acc_1 = ((acc_1 + (accumulator_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_2 > 16)
  {
    acc_2 = ((acc_2 + (accumulator_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_2) + 11) & 127;
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

  switch ((p0_1 + aux_1) & 3)
  {
    case 3:
      acc_1 = (acc_1 + 11) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 11) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 12) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 3:
      acc_2 = (acc_2 + 11) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 11) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 12) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_1 == accumulator_2);
  assert(loop_ctr_1 == loop_ctr_2);
}

int fn_R000078_6707_0(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int accumulator = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator > 16)
  {
    acc = ((acc + (accumulator * 2)) + 5) & 127;
    aux ^= accumulator & 15;
  }
  else
  {
    acc = ((acc - accumulator) + 11) & 127;
    aux += 3;
  }
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  switch ((p0 + aux) & 3)
  {
    case 3:
      acc = (acc + 11) & 127;
      break;

    case 0:
      acc = (acc + 11) & 127;
      break;

    case 1:
      acc = (acc + 12) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  return (acc + aux) & 127;
}

void fn_R000078_6707_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000078_6707 st_1 = {0};
  struct StreamBuffer_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
}

int fn_R000078_6707_1(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 5)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000078_6707_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st_1 = {0};
  struct Vector3D_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  switch ((p0_1 + aux_1) & 3)
  {
    case 1:
      acc_1 = (acc_1 + 13) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 11) & 127;
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
    case 1:
      acc_2 = (acc_2 + 13) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 11) & 127;
      break;

    case 3:
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
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

int fn_R000078_6707_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  switch ((p0 + aux) & 3)
  {
    case 1:
      acc = (acc + 13) & 127;
      break;

    case 0:
      acc = (acc + 11) & 127;
      break;

    case 3:
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

void fn_R000078_6707_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000078_6707 st_1 = {0};
  struct AudioFrame_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  switch ((p0_1 + aux_1) & 3)
  {
    case 3:
      acc_1 = (acc_1 + 6) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 4) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 13) & 127;
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

    case 0:
      acc_2 = (acc_2 + 4) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 13) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 5)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 5)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  int factor_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_1 > 13)
  {
    acc_1 = ((acc_1 + (factor_1 * 2)) + 5) & 127;
    aux_1 ^= factor_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_2 > 13)
  {
    acc_2 = ((acc_2 + (factor_2 * 2)) + 5) & 127;
    aux_2 ^= factor_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_1 == factor_2);
}

int fn_R000078_6707_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  switch ((p0 + aux) & 3)
  {
    case 3:
      acc = (acc + 6) & 127;
      break;

    case 0:
      acc = (acc + 4) & 127;
      break;

    case 2:
      acc = (acc + 13) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 5)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int factor = ((st.buffer[0] * 3) + aux) & 63;
  if (factor > 13)
  {
    acc = ((acc + (factor * 2)) + 5) & 127;
    aux ^= factor & 15;
  }
  else
  {
    acc = ((acc - factor) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000078_6707_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st_1 = {0};
  struct Vector3D_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 3)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 3)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  switch ((p0_1 + aux_1) & 3)
  {
    case 3:
      acc_1 = (acc_1 + 5) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 11) & 127;
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
      acc_2 = (acc_2 + 5) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 11) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 15) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
}

int fn_R000078_6707_4(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 3)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  switch ((p0 + aux) & 3)
  {
    case 3:
      acc = (acc + 5) & 127;
      break;

    case 2:
      acc = (acc + 11) & 127;
      break;

    case 1:
      acc = (acc + 15) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  return (acc + aux) & 127;
}

void fn_R000078_6707_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000078_6707 st_1 = {0};
  struct StreamBuffer_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  assert(loop_ctr_1 == loop_ctr_2);
}

int fn_R000078_6707_5(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
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

void fn_R000078_6707_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st_1 = {0};
  struct Vector3D_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 2)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 2)) + st_2.buffer[k_2 % 3]) & 63;
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
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  int delta_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_1 > 14)
  {
    acc_1 = ((acc_1 + (delta_1 * 2)) + 5) & 127;
    aux_1 ^= delta_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_2 > 14)
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
  assert(st_1.coord_z == st_2.coord_z);
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

  assert(b_step_1 == b_step_2);
  assert(delta_1 == delta_2);
}

int fn_R000078_6707_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 2)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  int delta = ((st.buffer[0] * 3) + aux) & 63;
  if (delta > 14)
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

void fn_R000078_6707_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st_1 = {0};
  struct Vector3D_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 12) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 9) & 127;
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
      acc_2 = (acc_2 + 12) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 9) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 12) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 2)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 2)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

}

int fn_R000078_6707_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 12) & 127;
      break;

    case 1:
      acc = (acc + 9) & 127;
      break;

    case 3:
      acc = (acc + 12) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 2)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  return (acc + aux) & 127;
}

void fn_R000078_6707_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st_1 = {0};
  struct Vector3D_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 10) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 13) & 127;
      break;

    case 3:
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

    case 0:
      acc_2 = (acc_2 + 13) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 10) & 127;
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

  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 3)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 3)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  int cursor_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_1 > 36)
  {
    acc_1 = ((acc_1 + (cursor_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_2 > 36)
  {
    acc_2 = ((acc_2 + (cursor_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(cursor_1 == cursor_2);
}

int fn_R000078_6707_8(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 10) & 127;
      break;

    case 0:
      acc = (acc + 13) & 127;
      break;

    case 3:
      acc = (acc + 10) & 127;
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

  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 3)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int cursor = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor > 36)
  {
    acc = ((acc + (cursor * 2)) + 5) & 127;
    aux ^= cursor & 15;
  }
  else
  {
    acc = ((acc - cursor) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000078_6707_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000078_6707 st_1 = {0};
  struct AudioFrame_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int quotient_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_1 > 40)
  {
    acc_1 = ((acc_1 + (quotient_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_2 > 40)
  {
    acc_2 = ((acc_2 + (quotient_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_2) + 11) & 127;
    aux_2 += 3;
  }
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 3)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 3)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_1 == quotient_2);
}

int fn_R000078_6707_9(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quotient = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient > 40)
  {
    acc = ((acc + (quotient * 2)) + 5) & 127;
    aux ^= quotient & 15;
  }
  else
  {
    acc = ((acc - quotient) + 11) & 127;
    aux += 3;
  }
  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 3)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  return (acc + aux) & 127;
}

void fn_R000078_6707_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st_1 = {0};
  struct Vector3D_R000078_6707 st_2 = {0};
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
    aux_1 = ((aux_1 + (k_1 * 3)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 3)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  int cursor_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_1 > 44)
  {
    acc_1 = ((acc_1 + (cursor_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_2 > 44)
  {
    acc_2 = ((acc_2 + (cursor_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
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

  assert(cursor_1 == cursor_2);
}

int fn_R000078_6707_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st = {0};
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
    aux = ((aux + (k * 3)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int cursor = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor > 44)
  {
    acc = ((acc + (cursor * 2)) + 5) & 127;
    aux ^= cursor & 15;
  }
  else
  {
    acc = ((acc - cursor) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000078_6707_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000078_6707 st_1 = {0};
  struct StreamBuffer_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int pivot_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_1 > 15)
  {
    acc_1 = ((acc_1 + (pivot_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_2 > 15)
  {
    acc_2 = ((acc_2 + (pivot_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_2) + 11) & 127;
    aux_2 += 3;
  }
  switch ((p0_1 + aux_1) & 3)
  {
    case 0:
      acc_1 = (acc_1 + 8) & 127;
      break;

    case 1:
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
    case 0:
      acc_2 = (acc_2 + 8) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 8) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 9) & 127;
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_1 == pivot_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000078_6707_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int pivot = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot > 15)
  {
    acc = ((acc + (pivot * 2)) + 5) & 127;
    aux ^= pivot & 15;
  }
  else
  {
    acc = ((acc - pivot) + 11) & 127;
    aux += 3;
  }
  switch ((p0 + aux) & 3)
  {
    case 0:
      acc = (acc + 8) & 127;
      break;

    case 1:
      acc = (acc + 8) & 127;
      break;

    case 3:
      acc = (acc + 9) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000078_6707_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000078_6707 st_1 = {0};
  struct StreamBuffer_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
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

  int index_reg_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_1 > 41)
  {
    acc_1 = ((acc_1 + (index_reg_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_2 > 41)
  {
    acc_2 = ((acc_2 + (index_reg_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_2) + 11) & 127;
    aux_2 += 3;
  }
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 5)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 5)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(index_reg_1 == index_reg_2);
}

int fn_R000078_6707_12(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
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

  int index_reg = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg > 41)
  {
    acc = ((acc + (index_reg * 2)) + 5) & 127;
    aux ^= index_reg & 15;
  }
  else
  {
    acc = ((acc - index_reg) + 11) & 127;
    aux += 3;
  }
  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 5)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  return (acc + aux) & 127;
}

void fn_R000078_6707_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000078_6707 st_1 = {0};
  struct AudioFrame_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
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
    case 1:
      acc_1 = (acc_1 + 12) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 15) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 11) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 1:
      acc_2 = (acc_2 + 12) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 15) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 11) & 127;
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
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

int fn_R000078_6707_13(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 3)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  switch ((p0 + aux) & 3)
  {
    case 1:
      acc = (acc + 12) & 127;
      break;

    case 3:
      acc = (acc + 15) & 127;
      break;

    case 2:
      acc = (acc + 11) & 127;
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

void fn_R000078_6707_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000078_6707 st_1 = {0};
  struct AudioFrame_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
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
  switch ((p0_1 + aux_1) & 3)
  {
    case 1:
      acc_1 = (acc_1 + 17) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 17) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 16) & 127;
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

    case 3:
      acc_2 = (acc_2 + 17) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 16) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(b_step_1 == b_step_2);
  assert(loop_ctr_1 == loop_ctr_2);
}

int fn_R000078_6707_14(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  switch ((p0 + aux) & 3)
  {
    case 1:
      acc = (acc + 17) & 127;
      break;

    case 3:
      acc = (acc + 17) & 127;
      break;

    case 0:
      acc = (acc + 16) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  return (acc + aux) & 127;
}

void fn_R000078_6707_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000078_6707 st_1 = {0};
  struct StreamBuffer_R000078_6707 st_2 = {0};
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
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

int fn_R000078_6707_15(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
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

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000078_6707_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st_1 = {0};
  struct Vector3D_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int index_reg_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_1 > 35)
  {
    acc_1 = ((acc_1 + (index_reg_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_2 > 35)
  {
    acc_2 = ((acc_2 + (index_reg_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_2) + 11) & 127;
    aux_2 += 3;
  }
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 10) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 9) & 127;
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
      acc_2 = (acc_2 + 10) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 9) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 13) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_1 == index_reg_2);
}

int fn_R000078_6707_16(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int index_reg = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg > 35)
  {
    acc = ((acc + (index_reg * 2)) + 5) & 127;
    aux ^= index_reg & 15;
  }
  else
  {
    acc = ((acc - index_reg) + 11) & 127;
    aux += 3;
  }
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 10) & 127;
      break;

    case 3:
      acc = (acc + 9) & 127;
      break;

    case 0:
      acc = (acc + 13) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  return (acc + aux) & 127;
}

void fn_R000078_6707_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000078_6707 st_1 = {0};
  struct StreamBuffer_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 3)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 3)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 10) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 17) & 127;
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
      acc_2 = (acc_2 + 10) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 17) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 17) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int pivot_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_1 > 29)
  {
    acc_1 = ((acc_1 + (pivot_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_2 > 29)
  {
    acc_2 = ((acc_2 + (pivot_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_1 == pivot_2);
}

int fn_R000078_6707_17(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 3)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 10) & 127;
      break;

    case 1:
      acc = (acc + 17) & 127;
      break;

    case 3:
      acc = (acc + 17) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int pivot = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot > 29)
  {
    acc = ((acc + (pivot * 2)) + 5) & 127;
    aux ^= pivot & 15;
  }
  else
  {
    acc = ((acc - pivot) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000078_6707_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000078_6707 st_1 = {0};
  struct AudioFrame_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  switch ((p0_1 + aux_1) & 3)
  {
    case 0:
      acc_1 = (acc_1 + 5) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 4) & 127;
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
    case 0:
      acc_2 = (acc_2 + 5) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 4) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 11) & 127;
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

  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000078_6707_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  switch ((p0 + aux) & 3)
  {
    case 0:
      acc = (acc + 5) & 127;
      break;

    case 2:
      acc = (acc + 4) & 127;
      break;

    case 1:
      acc = (acc + 11) & 127;
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

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000078_6707_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000078_6707 st_1 = {0};
  struct StreamBuffer_R000078_6707 st_2 = {0};
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

  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 2)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 2)) + st_2.buffer[k_2 % 3]) & 63;
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
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

int fn_R000078_6707_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  for (int k = 0; k < 3; k++)
  {
    aux = ((aux + (k * 2)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  return (acc + aux) & 127;
}

void fn_R000078_6707_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st_1 = {0};
  struct Vector3D_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  switch ((p0_1 + aux_1) & 3)
  {
    case 3:
      acc_1 = (acc_1 + 17) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 14) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 5) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 3:
      acc_2 = (acc_2 + 17) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 14) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 5) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
}

int fn_R000078_6707_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  switch ((p0 + aux) & 3)
  {
    case 3:
      acc = (acc + 17) & 127;
      break;

    case 2:
      acc = (acc + 14) & 127;
      break;

    case 1:
      acc = (acc + 5) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  return (acc + aux) & 127;
}

void fn_R000078_6707_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st_1 = {0};
  struct Vector3D_R000078_6707 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 2) && (loop_ctr_2 < 2))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int stride_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_1 > 45)
  {
    acc_1 = ((acc_1 + (stride_1 * 2)) + 5) & 127;
    aux_1 ^= stride_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_2 > 45)
  {
    acc_2 = ((acc_2 + (stride_2 * 2)) + 5) & 127;
    aux_2 ^= stride_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_2) + 11) & 127;
    aux_2 += 3;
  }
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(stride_1 == stride_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000078_6707_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000078_6707 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int loop_ctr = 0;
  while (loop_ctr < 2)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int stride = ((st.buffer[0] * 3) + aux) & 63;
  if (stride > 45)
  {
    acc = ((acc + (stride * 2)) + 5) & 127;
    aux ^= stride & 15;
  }
  else
  {
    acc = ((acc - stride) + 11) & 127;
    aux += 3;
  }
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void main()
{
  int sec_r000078_0_1;
  int sec_r000078_0_2;
  int sec_r000078_1_1;
  int sec_r000078_1_2;
  int sec_r000078_2_1;
  int sec_r000078_2_2;
  int pub_r000078_0_1;
  int pub_r000078_0_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  struct Vector3D_R000078_6707 st_var_0_1 = {0};
  struct Vector3D_R000078_6707 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000078_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000078_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000078_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000078_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = 7;
  st_var_0_2.buffer[2] = 7;
  struct StreamBuffer_R000078_6707 st_var_1_1 = {0};
  struct StreamBuffer_R000078_6707 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000078_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000078_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000078_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000078_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = 8;
  st_var_1_2.buffer[2] = 8;
  struct AudioFrame_R000078_6707 st_var_2_1 = {0};
  struct AudioFrame_R000078_6707 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000078_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000078_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000078_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000078_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = 9;
  st_var_2_2.buffer[2] = 9;
  union ColorPixel_R000078_6707 u_var_1 = {0};
  union ColorPixel_R000078_6707 u_var_2 = {0};
  u_var_1.word = (pub_r000078_0_1 + 0x42) & 255;
  u_var_2.word = (pub_r000078_0_2 + 0x42) & 255;
  int table_1[4] = {7, 13, 29, 41};
  int table_2[4] = {7, 13, 29, 41};
  int res_0_1 = fn_R000078_6707_0(7, 8);
  int res_0_2 = fn_R000078_6707_0(7, 8);
  fn_R000078_6707_0_2(7, 8, 7, 8);
  out_sink_1 = (out_sink_1 + res_0_1) & 255;
  out_sink_2 = (out_sink_2 + res_0_2) & 255;
  chk_sum_1 ^= (res_0_1 << 1) & 127;
  chk_sum_2 ^= (res_0_2 << 1) & 127;
  int res_1_1 = fn_R000078_6707_1(9, 11, 13);
  int res_1_2 = fn_R000078_6707_1(9, 11, 13);
  fn_R000078_6707_1_2(9, 11, 13, 9, 11, 13);
  out_sink_1 = (out_sink_1 + res_1_1) & 255;
  out_sink_2 = (out_sink_2 + res_1_2) & 255;
  chk_sum_1 ^= (res_1_1 << 1) & 127;
  chk_sum_2 ^= (res_1_2 << 1) & 127;
  int res_2_1 = fn_R000078_6707_2(11, 14, 17, 20);
  int res_2_2 = fn_R000078_6707_2(11, 14, 17, 20);
  fn_R000078_6707_2_2(11, 14, 17, 20, 11, 14, 17, 20);
  out_sink_1 = (out_sink_1 + res_2_1) & 255;
  out_sink_2 = (out_sink_2 + res_2_2) & 255;
  chk_sum_1 ^= (res_2_1 << 1) & 127;
  chk_sum_2 ^= (res_2_2 << 1) & 127;
  int res_3_1 = fn_R000078_6707_3(13, 17, 21, 25);
  int res_3_2 = fn_R000078_6707_3(13, 17, 21, 25);
  fn_R000078_6707_3_2(13, 17, 21, 25, 13, 17, 21, 25);
  out_sink_1 = (out_sink_1 + res_3_1) & 255;
  out_sink_2 = (out_sink_2 + res_3_2) & 255;
  chk_sum_1 ^= (res_3_1 << 1) & 127;
  chk_sum_2 ^= (res_3_2 << 1) & 127;
  int res_4_1 = fn_R000078_6707_4(15, 20);
  int res_4_2 = fn_R000078_6707_4(15, 20);
  fn_R000078_6707_4_2(15, 20, 15, 20);
  out_sink_1 = (out_sink_1 + res_4_1) & 255;
  out_sink_2 = (out_sink_2 + res_4_2) & 255;
  chk_sum_1 ^= (res_4_1 << 1) & 127;
  chk_sum_2 ^= (res_4_2 << 1) & 127;
  int res_5_1 = fn_R000078_6707_5(17, 23, 29);
  int res_5_2 = fn_R000078_6707_5(17, 23, 29);
  fn_R000078_6707_5_2(17, 23, 29, 17, 23, 29);
  out_sink_1 = (out_sink_1 + res_5_1) & 255;
  out_sink_2 = (out_sink_2 + res_5_2) & 255;
  chk_sum_1 ^= (res_5_1 << 1) & 127;
  chk_sum_2 ^= (res_5_2 << 1) & 127;
  int res_6_1 = fn_R000078_6707_6(19, 26, 33, 40);
  int res_6_2 = fn_R000078_6707_6(19, 26, 33, 40);
  fn_R000078_6707_6_2(19, 26, 33, 40, 19, 26, 33, 40);
  out_sink_1 = (out_sink_1 + res_6_1) & 255;
  out_sink_2 = (out_sink_2 + res_6_2) & 255;
  chk_sum_1 ^= (res_6_1 << 1) & 127;
  chk_sum_2 ^= (res_6_2 << 1) & 127;
  int res_7_1 = fn_R000078_6707_7(21, 29, 37, 45);
  int res_7_2 = fn_R000078_6707_7(21, 29, 37, 45);
  fn_R000078_6707_7_2(21, 29, 37, 45, 21, 29, 37, 45);
  out_sink_1 = (out_sink_1 + res_7_1) & 255;
  out_sink_2 = (out_sink_2 + res_7_2) & 255;
  chk_sum_1 ^= (res_7_1 << 1) & 127;
  chk_sum_2 ^= (res_7_2 << 1) & 127;
  int res_8_1 = fn_R000078_6707_8(23, 32);
  int res_8_2 = fn_R000078_6707_8(23, 32);
  fn_R000078_6707_8_2(23, 32, 23, 32);
  out_sink_1 = (out_sink_1 + res_8_1) & 255;
  out_sink_2 = (out_sink_2 + res_8_2) & 255;
  chk_sum_1 ^= (res_8_1 << 1) & 127;
  chk_sum_2 ^= (res_8_2 << 1) & 127;
  int res_9_1 = fn_R000078_6707_9(25, 35, 45);
  int res_9_2 = fn_R000078_6707_9(25, 35, 45);
  fn_R000078_6707_9_2(25, 35, 45, 25, 35, 45);
  out_sink_1 = (out_sink_1 + res_9_1) & 255;
  out_sink_2 = (out_sink_2 + res_9_2) & 255;
  chk_sum_1 ^= (res_9_1 << 1) & 127;
  chk_sum_2 ^= (res_9_2 << 1) & 127;
  int res_10_1 = fn_R000078_6707_10(27, 38, 49, 60);
  int res_10_2 = fn_R000078_6707_10(27, 38, 49, 60);
  fn_R000078_6707_10_2(27, 38, 49, 60, 27, 38, 49, 60);
  out_sink_1 = (out_sink_1 + res_10_1) & 255;
  out_sink_2 = (out_sink_2 + res_10_2) & 255;
  chk_sum_1 ^= (res_10_1 << 1) & 127;
  chk_sum_2 ^= (res_10_2 << 1) & 127;
  int res_11_1 = fn_R000078_6707_11(29, 41, 53, 65);
  int res_11_2 = fn_R000078_6707_11(29, 41, 53, 65);
  fn_R000078_6707_11_2(29, 41, 53, 65, 29, 41, 53, 65);
  out_sink_1 = (out_sink_1 + res_11_1) & 255;
  out_sink_2 = (out_sink_2 + res_11_2) & 255;
  chk_sum_1 ^= (res_11_1 << 1) & 127;
  chk_sum_2 ^= (res_11_2 << 1) & 127;
  int res_12_1 = fn_R000078_6707_12(31, 44, 57);
  int res_12_2 = fn_R000078_6707_12(31, 44, 57);
  fn_R000078_6707_12_2(31, 44, 57, 31, 44, 57);
  out_sink_1 = (out_sink_1 + res_12_1) & 255;
  out_sink_2 = (out_sink_2 + res_12_2) & 255;
  chk_sum_1 ^= (res_12_1 << 1) & 127;
  chk_sum_2 ^= (res_12_2 << 1) & 127;
  int res_13_1 = fn_R000078_6707_13(33, 47);
  int res_13_2 = fn_R000078_6707_13(33, 47);
  fn_R000078_6707_13_2(33, 47, 33, 47);
  out_sink_1 = (out_sink_1 + res_13_1) & 255;
  out_sink_2 = (out_sink_2 + res_13_2) & 255;
  chk_sum_1 ^= (res_13_1 << 1) & 127;
  chk_sum_2 ^= (res_13_2 << 1) & 127;
  int res_14_1 = fn_R000078_6707_14(35, 50, 65);
  int res_14_2 = fn_R000078_6707_14(35, 50, 65);
  fn_R000078_6707_14_2(35, 50, 65, 35, 50, 65);
  out_sink_1 = (out_sink_1 + res_14_1) & 255;
  out_sink_2 = (out_sink_2 + res_14_2) & 255;
  chk_sum_1 ^= (res_14_1 << 1) & 127;
  chk_sum_2 ^= (res_14_2 << 1) & 127;
  int res_15_1 = fn_R000078_6707_15(37, 53, 69);
  int res_15_2 = fn_R000078_6707_15(37, 53, 69);
  fn_R000078_6707_15_2(37, 53, 69, 37, 53, 69);
  out_sink_1 = (out_sink_1 + res_15_1) & 255;
  out_sink_2 = (out_sink_2 + res_15_2) & 255;
  chk_sum_1 ^= (res_15_1 << 1) & 127;
  chk_sum_2 ^= (res_15_2 << 1) & 127;
  int res_16_1 = fn_R000078_6707_16(39, 56);
  int res_16_2 = fn_R000078_6707_16(39, 56);
  fn_R000078_6707_16_2(39, 56, 39, 56);
  out_sink_1 = (out_sink_1 + res_16_1) & 255;
  out_sink_2 = (out_sink_2 + res_16_2) & 255;
  chk_sum_1 ^= (res_16_1 << 1) & 127;
  chk_sum_2 ^= (res_16_2 << 1) & 127;
  int res_17_1 = fn_R000078_6707_17(41, 59, 77);
  int res_17_2 = fn_R000078_6707_17(41, 59, 77);
  fn_R000078_6707_17_2(41, 59, 77, 41, 59, 77);
  out_sink_1 = (out_sink_1 + res_17_1) & 255;
  out_sink_2 = (out_sink_2 + res_17_2) & 255;
  chk_sum_1 ^= (res_17_1 << 1) & 127;
  chk_sum_2 ^= (res_17_2 << 1) & 127;
  int res_18_1 = fn_R000078_6707_18(43, 62, 81, 100);
  int res_18_2 = fn_R000078_6707_18(43, 62, 81, 100);
  fn_R000078_6707_18_2(43, 62, 81, 100, 43, 62, 81, 100);
  out_sink_1 = (out_sink_1 + res_18_1) & 255;
  out_sink_2 = (out_sink_2 + res_18_2) & 255;
  chk_sum_1 ^= (res_18_1 << 1) & 127;
  chk_sum_2 ^= (res_18_2 << 1) & 127;
  int res_19_1 = fn_R000078_6707_19(45, 65, 85, 105);
  int res_19_2 = fn_R000078_6707_19(45, 65, 85, 105);
  fn_R000078_6707_19_2(45, 65, 85, 105, 45, 65, 85, 105);
  out_sink_1 = (out_sink_1 + res_19_1) & 255;
  out_sink_2 = (out_sink_2 + res_19_2) & 255;
  chk_sum_1 ^= (res_19_1 << 1) & 127;
  chk_sum_2 ^= (res_19_2 << 1) & 127;
  int res_20_1 = fn_R000078_6707_20(47, 68, 89, 110);
  int res_20_2 = fn_R000078_6707_20(47, 68, 89, 110);
  fn_R000078_6707_20_2(47, 68, 89, 110, 47, 68, 89, 110);
  out_sink_1 = (out_sink_1 + res_20_1) & 255;
  out_sink_2 = (out_sink_2 + res_20_2) & 255;
  chk_sum_1 ^= (res_20_1 << 1) & 127;
  chk_sum_2 ^= (res_20_2 << 1) & 127;
  int res_21_1 = fn_R000078_6707_21(49, 71, 93, 115);
  int res_21_2 = fn_R000078_6707_21(49, 71, 93, 115);
  fn_R000078_6707_21_2(49, 71, 93, 115, 49, 71, 93, 115);
  out_sink_1 = (out_sink_1 + res_21_1) & 255;
  out_sink_2 = (out_sink_2 + res_21_2) & 255;
  chk_sum_1 ^= (res_21_1 << 1) & 127;
  chk_sum_2 ^= (res_21_2 << 1) & 127;
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
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
  int stage_v_6_1 = ((st_var_0_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_0_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 32)
    {
      chk_sum_1 ^= stage_v_6_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_6_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 32)
    {
      chk_sum_2 ^= stage_v_6_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_7_1 = ((st_var_1_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_1_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 44)
    {
      chk_sum_1 ^= stage_v_7_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_7_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 44)
    {
      chk_sum_2 ^= stage_v_7_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((st_var_2_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_2_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 41)
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
  if (stage_v_11_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 41)
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 38)
    {
      chk_sum_1 ^= stage_v_13_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_13_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 38)
    {
      chk_sum_2 ^= stage_v_13_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = (st_var_0_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_0_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = (st_var_1_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_1_2.buffer[0] ^ 19) & 3;
  switch (stage_v_16_1)
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

  switch (stage_v_16_2)
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

  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (st_var_0_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_0_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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

  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((st_var_2_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_2_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 38)
    {
      chk_sum_1 ^= stage_v_20_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_20_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 38)
    {
      chk_sum_2 ^= stage_v_20_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_21_1 = ((st_var_0_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_0_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 48)
    {
      chk_sum_1 ^= stage_v_21_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_21_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 48)
    {
      chk_sum_2 ^= stage_v_21_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = ((st_var_2_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_2_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 48)
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
  if (stage_v_23_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 48)
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
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = table_1[1];
  int stage_v_25_2 = table_2[1];
  table_1[1] = (table_1[2] + 51) & 63;
  table_2[1] = (table_2[2] + 51) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_26_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = (st_var_1_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_1_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  int stage_v_31_1 = table_1[3];
  int stage_v_31_2 = table_2[3];
  table_1[3] = (table_1[0] + 63) & 63;
  table_2[3] = (table_2[0] + 63) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
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
  int stage_v_33_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_33_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 37) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 37) & 15;
  int stage_v_36_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_36_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= stage_v_36_1;
  chk_sum_2 ^= stage_v_36_2;
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
  int stage_v_39_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_39_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((st_var_2_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_2_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 25)
    {
      chk_sum_1 ^= stage_v_41_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_41_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 25)
    {
      chk_sum_2 ^= stage_v_41_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 43) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 43) & 15;
  int stage_v_42_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_42_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= stage_v_42_1;
  chk_sum_2 ^= stage_v_42_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 44) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  int stage_v_44_1 = ((st_var_2_1.buffer[2] * 2) + 139) & 63;
  int stage_v_44_2 = ((st_var_2_2.buffer[2] * 2) + 139) & 63;
  if (stage_v_44_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 33)
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
  if (stage_v_44_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 33)
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
  int stage_v_45_1 = table_1[1];
  int stage_v_45_2 = table_2[1];
  table_1[1] = (table_1[2] + 91) & 63;
  table_2[1] = (table_2[2] + 91) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  int stage_v_47_1 = ((st_var_2_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_2_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 50)
    {
      chk_sum_1 ^= stage_v_47_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_47_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 50)
    {
      chk_sum_2 ^= stage_v_47_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = table_1[1];
  int stage_v_49_2 = table_2[1];
  table_1[1] = (table_1[2] + 99) & 63;
  table_2[1] = (table_2[2] + 99) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((st_var_2_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_2_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 42)
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
  if (stage_v_50_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 42)
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
  int stage_v_51_1 = (st_var_0_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_0_2.buffer[0] ^ 54) & 3;
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 53) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
  int stage_v_53_1 = ((st_var_2_1.buffer[2] * 2) + 166) & 63;
  int stage_v_53_2 = ((st_var_2_2.buffer[2] * 2) + 166) & 63;
  if (stage_v_53_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_53_1) - 5) & 255;
    if (stage_v_53_1 > 28)
    {
      chk_sum_1 ^= stage_v_53_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_53_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_53_2) - 5) & 255;
    if (stage_v_53_2 > 28)
    {
      chk_sum_2 ^= stage_v_53_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_54_1 = table_1[2];
  int stage_v_54_2 = table_2[2];
  table_1[2] = (table_1[3] + 109) & 63;
  table_2[2] = (table_2[3] + 109) & 63;
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
  int stage_v_56_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_56_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_56_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_56_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_57_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_57_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = table_1[3];
  int stage_v_59_2 = table_2[3];
  table_1[3] = (table_1[0] + 119) & 63;
  table_2[3] = (table_2[0] + 119) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
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
  int stage_v_61_1 = ((st_var_1_1.buffer[1] * 2) + 190) & 63;
  int stage_v_61_2 = ((st_var_1_2.buffer[1] * 2) + 190) & 63;
  if (stage_v_61_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_61_1) - 5) & 255;
    if (stage_v_61_1 > 49)
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
  if (stage_v_61_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_61_2) - 5) & 255;
    if (stage_v_61_2 > 49)
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
  int stage_v_62_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (67 & 31);
  int stage_v_62_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (67 & 31);
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= (stage_v_62_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_62_2 << 1) & 127;
  int stage_v_63_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_63_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_64_1 = table_1[0];
  int stage_v_64_2 = table_2[0];
  table_1[0] = (table_1[1] + 129) & 63;
  table_2[0] = (table_2[1] + 129) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 66) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 66) & 15;
  int stage_v_65_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_65_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= stage_v_65_1;
  chk_sum_2 ^= stage_v_65_2;
  int stage_v_66_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_66_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_66_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_66_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_67_1 = ((stage_v_67_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_67_2 = ((stage_v_67_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (st_var_0_1.buffer[0] ^ 72) & 3;
  int stage_v_69_2 = (st_var_0_2.buffer[0] ^ 72) & 3;
  switch (stage_v_69_1)
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

  switch (stage_v_69_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 71) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 71) & 15;
  int stage_v_70_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_70_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= stage_v_70_1;
  chk_sum_2 ^= stage_v_70_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 72) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 72) & 15;
  int stage_v_71_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_71_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= stage_v_71_1;
  chk_sum_2 ^= stage_v_71_2;
  int stage_v_72_1 = table_1[0];
  int stage_v_72_2 = table_2[0];
  table_1[0] = (table_1[1] + 145) & 63;
  table_2[0] = (table_2[1] + 145) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
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
  int stage_v_75_1 = (st_var_0_1.buffer[0] ^ 78) & 3;
  int stage_v_75_2 = (st_var_0_2.buffer[0] ^ 78) & 3;
  switch (stage_v_75_1)
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

  switch (stage_v_75_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 77) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 77) & 15;
  int stage_v_76_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_76_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= stage_v_76_1;
  chk_sum_2 ^= stage_v_76_2;
  int stage_v_77_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (82 & 31);
  int stage_v_77_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (82 & 31);
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= (stage_v_77_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_77_2 << 1) & 127;
  int stage_v_78_1 = table_1[2];
  int stage_v_78_2 = table_2[2];
  table_1[2] = (table_1[3] + 157) & 63;
  table_2[2] = (table_2[3] + 157) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
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
  int stage_v_80_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (85 & 31);
  int stage_v_80_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (85 & 31);
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= (stage_v_80_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_80_2 << 1) & 127;
  int stage_v_81_1 = ((st_var_0_1.buffer[0] * 2) + 250) & 63;
  int stage_v_81_2 = ((st_var_0_2.buffer[0] * 2) + 250) & 63;
  if (stage_v_81_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_81_1) - 5) & 255;
    if (stage_v_81_1 > 45)
    {
      chk_sum_1 ^= stage_v_81_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_81_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_81_2) - 5) & 255;
    if (stage_v_81_2 > 45)
    {
      chk_sum_2 ^= stage_v_81_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_82_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_82_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_82_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_82_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_83_1 = table_1[3];
  int stage_v_83_2 = table_2[3];
  table_1[3] = (table_1[0] + 167) & 63;
  table_2[3] = (table_2[0] + 167) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((st_var_0_1.buffer[0] * 2) + 259) & 63;
  int stage_v_84_2 = ((st_var_0_2.buffer[0] * 2) + 259) & 63;
  if (stage_v_84_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_84_1) - 5) & 255;
    if (stage_v_84_1 > 29)
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
  if (stage_v_84_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_84_2) - 5) & 255;
    if (stage_v_84_2 > 29)
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
  int stage_v_85_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (90 & 31);
  int stage_v_85_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (90 & 31);
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= (stage_v_85_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_85_2 << 1) & 127;
  int stage_v_86_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (91 & 31);
  int stage_v_86_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (91 & 31);
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= (stage_v_86_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_86_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 88) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 88) & 15;
  int stage_v_87_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_87_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  chk_sum_1 ^= stage_v_87_1;
  chk_sum_2 ^= stage_v_87_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 89) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 89) & 15;
  int stage_v_88_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_88_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= stage_v_88_1;
  chk_sum_2 ^= stage_v_88_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 90) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 90) & 15;
  int stage_v_89_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_89_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= stage_v_89_1;
  chk_sum_2 ^= stage_v_89_2;
  int stage_v_90_1 = (st_var_0_1.buffer[0] ^ 93) & 3;
  int stage_v_90_2 = (st_var_0_2.buffer[0] ^ 93) & 3;
  switch (stage_v_90_1)
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

  switch (stage_v_90_2)
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

  int stage_v_91_1 = ((st_var_1_1.buffer[1] * 2) + 280) & 63;
  int stage_v_91_2 = ((st_var_1_2.buffer[1] * 2) + 280) & 63;
  if (stage_v_91_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_91_1) - 5) & 255;
    if (stage_v_91_1 > 47)
    {
      chk_sum_1 ^= stage_v_91_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_91_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_91_2) - 5) & 255;
    if (stage_v_91_2 > 47)
    {
      chk_sum_2 ^= stage_v_91_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_92_1 = ((stage_v_92_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_92_2 = ((stage_v_92_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = table_1[1];
  int stage_v_93_2 = table_2[1];
  table_1[1] = (table_1[2] + 187) & 63;
  table_2[1] = (table_2[2] + 187) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = table_1[2];
  int stage_v_94_2 = table_2[2];
  table_1[2] = (table_1[3] + 189) & 63;
  table_2[2] = (table_2[3] + 189) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = table_1[3];
  int stage_v_95_2 = table_2[3];
  table_1[3] = (table_1[0] + 191) & 63;
  table_2[3] = (table_2[0] + 191) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_96_1 = ((stage_v_96_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_96_2 = ((stage_v_96_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 98) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 98) & 15;
  int stage_v_97_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_97_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= stage_v_97_1;
  chk_sum_2 ^= stage_v_97_2;
  int stage_v_98_1 = table_1[2];
  int stage_v_98_2 = table_2[2];
  table_1[2] = (table_1[3] + 197) & 63;
  table_2[2] = (table_2[3] + 197) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 100) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 100) & 15;
  int stage_v_99_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_99_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  chk_sum_1 ^= stage_v_99_1;
  chk_sum_2 ^= stage_v_99_2;
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
  int stage_v_102_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_102_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_102_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_102_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_103_1 = table_1[3];
  int stage_v_103_2 = table_2[3];
  table_1[3] = (table_1[0] + 207) & 63;
  table_2[3] = (table_2[0] + 207) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((st_var_2_1.buffer[2] * 2) + 319) & 63;
  int stage_v_104_2 = ((st_var_2_2.buffer[2] * 2) + 319) & 63;
  if (stage_v_104_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_104_1) - 5) & 255;
    if (stage_v_104_1 > 43)
    {
      chk_sum_1 ^= stage_v_104_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_104_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_104_2) - 5) & 255;
    if (stage_v_104_2 > 43)
    {
      chk_sum_2 ^= stage_v_104_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 106) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 106) & 15;
  int stage_v_105_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_105_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= stage_v_105_1;
  chk_sum_2 ^= stage_v_105_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 107) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 107) & 15;
  int stage_v_106_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_106_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  chk_sum_1 ^= stage_v_106_1;
  chk_sum_2 ^= stage_v_106_2;
  int stage_v_107_1 = (st_var_2_1.buffer[0] ^ 110) & 3;
  int stage_v_107_2 = (st_var_2_2.buffer[0] ^ 110) & 3;
  switch (stage_v_107_1)
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

  switch (stage_v_107_2)
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

  int stage_v_108_1 = ((st_var_0_1.buffer[0] * 2) + 331) & 63;
  int stage_v_108_2 = ((st_var_0_2.buffer[0] * 2) + 331) & 63;
  if (stage_v_108_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_108_1) - 5) & 255;
    if (stage_v_108_1 > 37)
    {
      chk_sum_1 ^= stage_v_108_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_108_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_108_2) - 5) & 255;
    if (stage_v_108_2 > 37)
    {
      chk_sum_2 ^= stage_v_108_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_109_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_109_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_109_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_109_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_110_1 = ((st_var_2_1.buffer[2] * 2) + 337) & 63;
  int stage_v_110_2 = ((st_var_2_2.buffer[2] * 2) + 337) & 63;
  if (stage_v_110_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_110_1) - 5) & 255;
    if (stage_v_110_1 > 41)
    {
      chk_sum_1 ^= stage_v_110_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_110_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_110_2) - 5) & 255;
    if (stage_v_110_2 > 41)
    {
      chk_sum_2 ^= stage_v_110_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_111_1 = table_1[3];
  int stage_v_111_2 = table_2[3];
  table_1[3] = (table_1[0] + 223) & 63;
  table_2[3] = (table_2[0] + 223) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (117 & 31);
  int stage_v_112_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (117 & 31);
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  chk_sum_1 ^= (stage_v_112_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_112_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 114) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 114) & 15;
  int stage_v_113_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_113_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  chk_sum_1 ^= stage_v_113_1;
  chk_sum_2 ^= stage_v_113_2;
  int stage_v_114_1 = (st_var_0_1.buffer[0] ^ 117) & 3;
  int stage_v_114_2 = (st_var_0_2.buffer[0] ^ 117) & 3;
  switch (stage_v_114_1)
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

  switch (stage_v_114_2)
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

  int stage_v_115_1 = (st_var_1_1.buffer[0] ^ 118) & 3;
  int stage_v_115_2 = (st_var_1_2.buffer[0] ^ 118) & 3;
  switch (stage_v_115_1)
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

  switch (stage_v_115_2)
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

  int stage_v_116_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (121 & 31);
  int stage_v_116_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (121 & 31);
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  chk_sum_1 ^= (stage_v_116_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_116_2 << 1) & 127;
  int stage_v_117_1 = ((st_var_0_1.buffer[0] * 2) + 358) & 63;
  int stage_v_117_2 = ((st_var_0_2.buffer[0] * 2) + 358) & 63;
  if (stage_v_117_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_117_1) - 5) & 255;
    if (stage_v_117_1 > 33)
    {
      chk_sum_1 ^= stage_v_117_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_117_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_117_2) - 5) & 255;
    if (stage_v_117_2 > 33)
    {
      chk_sum_2 ^= stage_v_117_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_118_1 = (st_var_1_1.buffer[0] ^ 121) & 3;
  int stage_v_118_2 = (st_var_1_2.buffer[0] ^ 121) & 3;
  switch (stage_v_118_1)
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

  switch (stage_v_118_2)
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

  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_119_1 = ((stage_v_119_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_119_2 = ((stage_v_119_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (st_var_0_1.buffer[0] ^ 123) & 3;
  int stage_v_120_2 = (st_var_0_2.buffer[0] ^ 123) & 3;
  switch (stage_v_120_1)
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

  switch (stage_v_120_2)
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

  int stage_v_121_1 = (st_var_1_1.buffer[0] ^ 124) & 3;
  int stage_v_121_2 = (st_var_1_2.buffer[0] ^ 124) & 3;
  switch (stage_v_121_1)
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

  switch (stage_v_121_2)
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

  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_122_1 = ((stage_v_122_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_122_2 = ((stage_v_122_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (128 & 31);
  int stage_v_123_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (128 & 31);
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  chk_sum_1 ^= (stage_v_123_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_123_2 << 1) & 127;
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
  int stage_v_125_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_125_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_125_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_125_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 127) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 127) & 15;
  int stage_v_126_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_126_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  chk_sum_1 ^= stage_v_126_1;
  chk_sum_2 ^= stage_v_126_2;
  int stage_v_127_1 = table_1[3];
  int stage_v_127_2 = table_2[3];
  table_1[3] = (table_1[0] + 255) & 63;
  table_2[3] = (table_2[0] + 255) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_128_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_128_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_128_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_129_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (134 & 31);
  int stage_v_129_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (134 & 31);
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  chk_sum_1 ^= (stage_v_129_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_129_2 << 1) & 127;
  int stage_v_130_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_130_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_130_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_130_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 132) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 132) & 15;
  int stage_v_131_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_131_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  chk_sum_1 ^= stage_v_131_1;
  chk_sum_2 ^= stage_v_131_2;
  int stage_v_132_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (137 & 31);
  int stage_v_132_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (137 & 31);
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  chk_sum_1 ^= (stage_v_132_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_132_2 << 1) & 127;
  int stage_v_133_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (138 & 31);
  int stage_v_133_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (138 & 31);
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  chk_sum_1 ^= (stage_v_133_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_133_2 << 1) & 127;
  int stage_v_134_1 = ((st_var_2_1.buffer[2] * 2) + 409) & 63;
  int stage_v_134_2 = ((st_var_2_2.buffer[2] * 2) + 409) & 63;
  if (stage_v_134_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_134_1) - 5) & 255;
    if (stage_v_134_1 > 33)
    {
      chk_sum_1 ^= stage_v_134_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_134_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_134_2) - 5) & 255;
    if (stage_v_134_2 > 33)
    {
      chk_sum_2 ^= stage_v_134_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_135_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (140 & 31);
  int stage_v_135_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (140 & 31);
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  chk_sum_1 ^= (stage_v_135_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_135_2 << 1) & 127;
  int stage_v_136_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (141 & 31);
  int stage_v_136_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (141 & 31);
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  chk_sum_1 ^= (stage_v_136_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_136_2 << 1) & 127;
  int stage_v_137_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_137_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_138_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (143 & 31);
  int stage_v_138_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (143 & 31);
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  chk_sum_1 ^= (stage_v_138_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_138_2 << 1) & 127;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_139_1 = ((stage_v_139_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_139_2 = ((stage_v_139_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_140_1 = ((stage_v_140_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_140_2 = ((stage_v_140_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (146 & 31);
  int stage_v_141_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (146 & 31);
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  chk_sum_1 ^= (stage_v_141_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_141_2 << 1) & 127;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_142_1 = ((stage_v_142_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_142_2 = ((stage_v_142_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((st_var_2_1.buffer[2] * 2) + 436) & 63;
  int stage_v_143_2 = ((st_var_2_2.buffer[2] * 2) + 436) & 63;
  if (stage_v_143_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_143_1) - 5) & 255;
    if (stage_v_143_1 > 38)
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
  if (stage_v_143_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_143_2) - 5) & 255;
    if (stage_v_143_2 > 38)
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
  int stage_v_145_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_145_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_145_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_145_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_146_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (151 & 31);
  int stage_v_146_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (151 & 31);
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  chk_sum_1 ^= (stage_v_146_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_146_2 << 1) & 127;
  int stage_v_147_1 = table_1[3];
  int stage_v_147_2 = table_2[3];
  table_1[3] = (table_1[0] + 295) & 63;
  table_2[3] = (table_2[0] + 295) & 63;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 149) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 149) & 15;
  int stage_v_148_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_148_2 = (st_var_1_2.buffer[1] * 3) & 63;
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
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_150_1 = ((stage_v_150_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_150_2 = ((stage_v_150_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
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
  int stage_v_153_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_153_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_153_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_153_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 155) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 155) & 15;
  int stage_v_154_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_154_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  chk_sum_1 ^= stage_v_154_1;
  chk_sum_2 ^= stage_v_154_2;
  int stage_v_155_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_155_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_155_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_155_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_156_1 = ((st_var_0_1.buffer[0] * 2) + 475) & 63;
  int stage_v_156_2 = ((st_var_0_2.buffer[0] * 2) + 475) & 63;
  if (stage_v_156_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_156_1) - 5) & 255;
    if (stage_v_156_1 > 52)
    {
      chk_sum_1 ^= stage_v_156_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_156_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_156_2) - 5) & 255;
    if (stage_v_156_2 > 52)
    {
      chk_sum_2 ^= stage_v_156_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_157_1 = table_1[1];
  int stage_v_157_2 = table_2[1];
  table_1[1] = (table_1[2] + 315) & 63;
  table_2[1] = (table_2[2] + 315) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_158_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_158_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_158_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_159_1 = table_1[3];
  int stage_v_159_2 = table_2[3];
  table_1[3] = (table_1[0] + 319) & 63;
  table_2[3] = (table_2[0] + 319) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (165 & 31);
  int stage_v_160_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (165 & 31);
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  chk_sum_1 ^= (stage_v_160_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_160_2 << 1) & 127;
  int stage_v_161_1 = ((st_var_2_1.buffer[2] * 2) + 490) & 63;
  int stage_v_161_2 = ((st_var_2_2.buffer[2] * 2) + 490) & 63;
  if (stage_v_161_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_161_1) - 5) & 255;
    if (stage_v_161_1 > 40)
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
  if (stage_v_161_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_161_2) - 5) & 255;
    if (stage_v_161_2 > 40)
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
  int stage_v_162_1 = (st_var_0_1.buffer[0] ^ 165) & 3;
  int stage_v_162_2 = (st_var_0_2.buffer[0] ^ 165) & 3;
  switch (stage_v_162_1)
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

  switch (stage_v_162_2)
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

  int stage_v_163_1 = (st_var_1_1.buffer[0] ^ 166) & 3;
  int stage_v_163_2 = (st_var_1_2.buffer[0] ^ 166) & 3;
  switch (stage_v_163_1)
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

  switch (stage_v_163_2)
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

  int stage_v_164_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_164_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_164_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_164_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 166) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 166) & 15;
  int stage_v_165_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_165_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  chk_sum_1 ^= stage_v_165_1;
  chk_sum_2 ^= stage_v_165_2;
  int stage_v_166_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_166_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_166_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_166_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_167_1 = table_1[3];
  int stage_v_167_2 = table_2[3];
  table_1[3] = (table_1[0] + 335) & 63;
  table_2[3] = (table_2[0] + 335) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (173 & 31);
  int stage_v_168_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (173 & 31);
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  chk_sum_1 ^= (stage_v_168_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_168_2 << 1) & 127;
  int stage_v_169_1 = 0;
  int stage_v_169_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_169_1 = ((stage_v_169_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_169_2 = ((stage_v_169_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = 0;
  int stage_v_170_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_170_1 = ((stage_v_170_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_170_2 = ((stage_v_170_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 172) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 172) & 15;
  int stage_v_171_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_171_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  chk_sum_1 ^= stage_v_171_1;
  chk_sum_2 ^= stage_v_171_2;
  int stage_v_172_1 = ((st_var_1_1.buffer[1] * 2) + 523) & 63;
  int stage_v_172_2 = ((st_var_1_2.buffer[1] * 2) + 523) & 63;
  if (stage_v_172_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_172_1) - 5) & 255;
    if (stage_v_172_1 > 49)
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
  if (stage_v_172_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_172_2) - 5) & 255;
    if (stage_v_172_2 > 49)
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
  int stage_v_173_1 = table_1[1];
  int stage_v_173_2 = table_2[1];
  table_1[1] = (table_1[2] + 347) & 63;
  table_2[1] = (table_2[2] + 347) & 63;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (st_var_0_1.buffer[0] ^ 177) & 3;
  int stage_v_174_2 = (st_var_0_2.buffer[0] ^ 177) & 3;
  switch (stage_v_174_1)
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

  switch (stage_v_174_2)
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

  int stage_v_175_1 = ((st_var_1_1.buffer[1] * 2) + 532) & 63;
  int stage_v_175_2 = ((st_var_1_2.buffer[1] * 2) + 532) & 63;
  if (stage_v_175_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_175_1) - 5) & 255;
    if (stage_v_175_1 > 31)
    {
      chk_sum_1 ^= stage_v_175_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_175_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_175_2) - 5) & 255;
    if (stage_v_175_2 > 31)
    {
      chk_sum_2 ^= stage_v_175_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_176_1 = ((st_var_2_1.buffer[2] * 2) + 535) & 63;
  int stage_v_176_2 = ((st_var_2_2.buffer[2] * 2) + 535) & 63;
  if (stage_v_176_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_176_1) - 5) & 255;
    if (stage_v_176_1 > 32)
    {
      chk_sum_1 ^= stage_v_176_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_176_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_176_2) - 5) & 255;
    if (stage_v_176_2 > 32)
    {
      chk_sum_2 ^= stage_v_176_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_177_1 = ((st_var_0_1.buffer[0] * 2) + 538) & 63;
  int stage_v_177_2 = ((st_var_0_2.buffer[0] * 2) + 538) & 63;
  if (stage_v_177_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_177_1) - 5) & 255;
    if (stage_v_177_1 > 50)
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
  if (stage_v_177_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_177_2) - 5) & 255;
    if (stage_v_177_2 > 50)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 179) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 179) & 15;
  int stage_v_178_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_178_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  chk_sum_1 ^= stage_v_178_1;
  chk_sum_2 ^= stage_v_178_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 180) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 180) & 15;
  int stage_v_179_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_179_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  chk_sum_1 ^= stage_v_179_1;
  chk_sum_2 ^= stage_v_179_2;
  int stage_v_180_1 = (st_var_0_1.buffer[0] ^ 183) & 3;
  int stage_v_180_2 = (st_var_0_2.buffer[0] ^ 183) & 3;
  switch (stage_v_180_1)
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

  switch (stage_v_180_2)
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

  int stage_v_181_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_181_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_181_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_181_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_182_1 = 0;
  int stage_v_182_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_182_1 = ((stage_v_182_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_182_2 = ((stage_v_182_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = table_1[3];
  int stage_v_183_2 = table_2[3];
  table_1[3] = (table_1[0] + 367) & 63;
  table_2[3] = (table_2[0] + 367) & 63;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 185) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 185) & 15;
  int stage_v_184_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_184_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  chk_sum_1 ^= stage_v_184_1;
  chk_sum_2 ^= stage_v_184_2;
  int stage_v_185_1 = (st_var_2_1.buffer[0] ^ 188) & 3;
  int stage_v_185_2 = (st_var_2_2.buffer[0] ^ 188) & 3;
  switch (stage_v_185_1)
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

  switch (stage_v_185_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 187) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 187) & 15;
  int stage_v_186_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_186_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  chk_sum_1 ^= stage_v_186_1;
  chk_sum_2 ^= stage_v_186_2;
  int stage_v_187_1 = table_1[3];
  int stage_v_187_2 = table_2[3];
  table_1[3] = (table_1[0] + 375) & 63;
  table_2[3] = (table_2[0] + 375) & 63;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int l_bound_1 = (sec_r000078_0_1 & 1) + 1;
  int l_bound_2 = (sec_r000078_0_2 & 1) + 1;
  for (int it_1 = 0, it_2 = 0; (it_1 < l_bound_1) && (it_2 < l_bound_2); it_1++, it_2++)
  {
    out_sink_1 += (it_1 * 3) + 4;
    out_sink_2 += (it_2 * 3) + 4;
  }

  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000078_0_1 != sec_r000078_0_2);
  __CPROVER_assume(sec_r000078_1_1 != sec_r000078_1_2);
  __CPROVER_assume(sec_r000078_2_1 != sec_r000078_2_2);
  __CPROVER_assume(pub_r000078_0_1 == pub_r000078_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.rms == st_var_2_2.rms);
  assert(st_var_2_1.channels == st_var_2_2.channels);
  assert(st_var_2_1.envelope == st_var_2_2.envelope);
  assert(st_var_2_1.sample_rate == st_var_2_2.sample_rate);
  assert(st_var_2_1.peak == st_var_2_2.peak);
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
  assert(res_21_1 == res_21_2);
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
  assert(l_bound_1 == l_bound_2);
}


