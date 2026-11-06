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
struct CipherContext_R000837_3713_0
{
  int iv;
  int round_key;
  int tag;
  int counter;
  int buffer[3];
};
struct Vector3D_R000837_3713_1
{
  int heading;
  unsigned char coord_x;
  short coord_y;
  int coord_z;
  int pitch;
  int buffer[3];
};
union RegisterBank_R000837_3713_0
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
void fn_R000837_3713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st_1 = {0};
  struct CipherContext_R000837_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_60_1) & 63;
  aux_2 = (aux_2 + window_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_50_1)
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

  switch (weight_50_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_60_1 == window_60_2);
  assert(weight_50_1 == weight_50_2);
}

int fn_R000837_3713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_60) & 63;
  acc ^= aux;
  int weight_50 = (aux + st.buffer[1]) & 3;
  switch (weight_50)
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

void fn_R000837_3713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st_1 = {0};
  struct CipherContext_R000837_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int tally_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_23_1)
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

  switch (tally_23_2)
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
  int parity_40_1 = local_arr_1[aux_1 % 3];
  int parity_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_40_2 * 2)) & 127;
  int mask_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_71_1 > 38)
  {
    acc_1 = ((acc_1 + (mask_71_1 * 2)) + 5) & 127;
    aux_1 ^= mask_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_71_2 > 38)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_23_1 == tally_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_40_1 == parity_40_2);
  assert(mask_71_1 == mask_71_2);
}

int fn_R000837_3713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int tally_23 = (aux + st.buffer[1]) & 3;
  switch (tally_23)
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
  int parity_40 = local_arr[aux % 3];
  acc = (acc + (parity_40 * 2)) & 127;
  int mask_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_71 > 38)
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

void fn_R000837_3713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st_1 = {0};
  struct Vector3D_R000837_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_55_1 = local_arr_1[aux_1 % 3];
  int margin_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_55_2 * 2)) & 127;
  int accumulator_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_35_1 > 44)
  {
    acc_1 = ((acc_1 + (accumulator_35_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_35_2 > 44)
  {
    acc_2 = ((acc_2 + (accumulator_35_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_35_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_55_1 == margin_55_2);
  assert(accumulator_35_1 == accumulator_35_2);
}

int fn_R000837_3713_2(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int margin_55 = local_arr[aux % 3];
  acc = (acc + (margin_55 * 2)) & 127;
  int accumulator_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_35 > 44)
  {
    acc = ((acc + (accumulator_35 * 2)) + 5) & 127;
    aux ^= accumulator_35 & 15;
  }
  else
  {
    acc = ((acc - accumulator_35) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000837_3713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st_1 = {0};
  struct Vector3D_R000837_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_21_1 = local_arr_1[aux_1 % 3];
  int weight_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_21_2 * 2)) & 127;
  int index_reg_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_79_1) & 63;
  aux_2 = (aux_2 + index_reg_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_17_1 > 50)
  {
    acc_1 = ((acc_1 + (cursor_17_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_17_2 > 50)
  {
    acc_2 = ((acc_2 + (cursor_17_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_17_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_21_1 == weight_21_2);
  assert(index_reg_79_1 == index_reg_79_2);
  assert(cursor_17_1 == cursor_17_2);
}

int fn_R000837_3713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int weight_21 = local_arr[aux % 3];
  acc = (acc + (weight_21 * 2)) & 127;
  int index_reg_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_79) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_17 > 50)
  {
    acc = ((acc + (cursor_17 * 2)) + 5) & 127;
    aux ^= cursor_17 & 15;
  }
  else
  {
    acc = ((acc - cursor_17) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000837_3713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st_1 = {0};
  struct Vector3D_R000837_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int cursor_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_77_1 > 27)
  {
    acc_1 = ((acc_1 + (cursor_77_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_77_2 > 27)
  {
    acc_2 = ((acc_2 + (cursor_77_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_89_1 = local_arr_1[aux_1 % 3];
  int parity_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_89_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_77_1 == cursor_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_89_1 == parity_89_2);
}

int fn_R000837_3713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int cursor_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_77 > 27)
  {
    acc = ((acc + (cursor_77 * 2)) + 5) & 127;
    aux ^= cursor_77 & 15;
  }
  else
  {
    acc = ((acc - cursor_77) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_89 = local_arr[aux % 3];
  acc = (acc + (parity_89 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000837_3713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st_1 = {0};
  struct CipherContext_R000837_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int pivot_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_80_1) & 63;
  aux_2 = (aux_2 + pivot_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_69_1 > 44)
  {
    acc_1 = ((acc_1 + (tracker_69_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_69_2 > 44)
  {
    acc_2 = ((acc_2 + (tracker_69_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_69_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_80_1 == pivot_80_2);
  assert(tracker_69_1 == tracker_69_2);
}

int fn_R000837_3713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int pivot_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_80) & 63;
  acc ^= aux;
  int tracker_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_69 > 44)
  {
    acc = ((acc + (tracker_69 * 2)) + 5) & 127;
    aux ^= tracker_69 & 15;
  }
  else
  {
    acc = ((acc - tracker_69) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000837_3713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st_1 = {0};
  struct Vector3D_R000837_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int threshold_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_51_1 > 24)
  {
    acc_1 = ((acc_1 + (threshold_51_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_51_2 > 24)
  {
    acc_2 = ((acc_2 + (threshold_51_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_29_1)
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

  switch (cursor_29_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_51_1 == threshold_51_2);
  assert(cursor_29_1 == cursor_29_2);
}

int fn_R000837_3713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int threshold_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_51 > 24)
  {
    acc = ((acc + (threshold_51 * 2)) + 5) & 127;
    aux ^= threshold_51 & 15;
  }
  else
  {
    acc = ((acc - threshold_51) + 11) & 127;
    aux += 3;
  }
  int cursor_29 = (aux + st.buffer[1]) & 3;
  switch (cursor_29)
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

void fn_R000837_3713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st_1 = {0};
  struct CipherContext_R000837_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int metric_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_16_1 > 47)
  {
    acc_1 = ((acc_1 + (metric_16_1 * 2)) + 5) & 127;
    aux_1 ^= metric_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_16_2 > 47)
  {
    acc_2 = ((acc_2 + (metric_16_2 * 2)) + 5) & 127;
    aux_2 ^= metric_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_48_1) & 63;
  aux_2 = (aux_2 + window_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_16_1 == metric_16_2);
  assert(window_48_1 == window_48_2);
}

int fn_R000837_3713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int metric_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_16 > 47)
  {
    acc = ((acc + (metric_16 * 2)) + 5) & 127;
    aux ^= metric_16 & 15;
  }
  else
  {
    acc = ((acc - metric_16) + 11) & 127;
    aux += 3;
  }
  int window_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_48) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000837_3713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st_1 = {0};
  struct Vector3D_R000837_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int bound_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_35_1)
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

  switch (bound_35_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_54_1 = local_arr_1[aux_1 % 3];
  int scale_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_54_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_35_1 == bound_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_54_1 == scale_54_2);
}

int fn_R000837_3713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int bound_35 = (aux + st.buffer[1]) & 3;
  switch (bound_35)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_54 = local_arr[aux % 3];
  acc = (acc + (scale_54 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000837_3713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st_1 = {0};
  struct CipherContext_R000837_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_40_1 = local_arr_1[aux_1 % 3];
  int offset_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_40_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_65_1 > 33)
  {
    acc_1 = ((acc_1 + (checksum_65_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_65_2 > 33)
  {
    acc_2 = ((acc_2 + (checksum_65_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_65_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_40_1 == offset_40_2);
  assert(checksum_65_1 == checksum_65_2);
}

int fn_R000837_3713_9(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int offset_40 = local_arr[aux % 3];
  acc = (acc + (offset_40 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_65 > 33)
  {
    acc = ((acc + (checksum_65 * 2)) + 5) & 127;
    aux ^= checksum_65 & 15;
  }
  else
  {
    acc = ((acc - checksum_65) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000837_3713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st_1 = {0};
  struct CipherContext_R000837_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int accumulator_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_63_1) & 63;
  aux_2 = (aux_2 + accumulator_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_63_1 == accumulator_63_2);
}

int fn_R000837_3713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int accumulator_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_63) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000837_3713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st_1 = {0};
  struct Vector3D_R000837_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int bound_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_32_1) & 63;
  aux_2 = (aux_2 + bound_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_30_1 > 43)
  {
    acc_1 = ((acc_1 + (offset_30_1 * 2)) + 5) & 127;
    aux_1 ^= offset_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_30_2 > 43)
  {
    acc_2 = ((acc_2 + (offset_30_2 * 2)) + 5) & 127;
    aux_2 ^= offset_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_30_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_32_1 == bound_32_2);
  assert(offset_30_1 == offset_30_2);
}

int fn_R000837_3713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int bound_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_32) & 63;
  acc ^= aux;
  int offset_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_30 > 43)
  {
    acc = ((acc + (offset_30 * 2)) + 5) & 127;
    aux ^= offset_30 & 15;
  }
  else
  {
    acc = ((acc - offset_30) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000837_3713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st_1 = {0};
  struct Vector3D_R000837_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int coefficient_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_32_1 > 35)
  {
    acc_1 = ((acc_1 + (coefficient_32_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_32_2 > 35)
  {
    acc_2 = ((acc_2 + (coefficient_32_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_85_1) & 63;
  aux_2 = (aux_2 + coefficient_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_98_1)
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

  switch (tracker_98_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_32_1 == coefficient_32_2);
  assert(coefficient_85_1 == coefficient_85_2);
  assert(tracker_98_1 == tracker_98_2);
}

int fn_R000837_3713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int coefficient_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_32 > 35)
  {
    acc = ((acc + (coefficient_32 * 2)) + 5) & 127;
    aux ^= coefficient_32 & 15;
  }
  else
  {
    acc = ((acc - coefficient_32) + 11) & 127;
    aux += 3;
  }
  int coefficient_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_85) & 63;
  acc ^= aux;
  int tracker_98 = (aux + st.buffer[1]) & 3;
  switch (tracker_98)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000837_3713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st_1 = {0};
  struct CipherContext_R000837_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_69_1) & 63;
  aux_2 = (aux_2 + offset_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_69_1 == offset_69_2);
}

int fn_R000837_3713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_69) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000837_3713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st_1 = {0};
  struct CipherContext_R000837_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_30_1)
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

  switch (damping_30_2)
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

  int stride_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_70_1 > 26)
  {
    acc_1 = ((acc_1 + (stride_70_1 * 2)) + 5) & 127;
    aux_1 ^= stride_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_70_2 > 26)
  {
    acc_2 = ((acc_2 + (stride_70_2 * 2)) + 5) & 127;
    aux_2 ^= stride_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_44_1) & 63;
  aux_2 = (aux_2 + weight_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_30_1 == damping_30_2);
  assert(stride_70_1 == stride_70_2);
  assert(weight_44_1 == weight_44_2);
}

int fn_R000837_3713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_30 = (aux + st.buffer[1]) & 3;
  switch (damping_30)
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

  int stride_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_70 > 26)
  {
    acc = ((acc + (stride_70 * 2)) + 5) & 127;
    aux ^= stride_70 & 15;
  }
  else
  {
    acc = ((acc - stride_70) + 11) & 127;
    aux += 3;
  }
  int weight_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000837_3713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st_1 = {0};
  struct CipherContext_R000837_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int offset_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_54_1) & 63;
  aux_2 = (aux_2 + offset_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_90_1 = local_arr_1[aux_1 % 3];
  int tracker_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_90_2 * 2)) & 127;
  int metric_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_16_1)
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

  switch (metric_16_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_54_1 == offset_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_90_1 == tracker_90_2);
  assert(metric_16_1 == metric_16_2);
}

int fn_R000837_3713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int offset_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_54) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_90 = local_arr[aux % 3];
  acc = (acc + (tracker_90 * 2)) & 127;
  int metric_16 = (aux + st.buffer[1]) & 3;
  switch (metric_16)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000837_3713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st_1 = {0};
  struct Vector3D_R000837_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int vector_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_23_1 > 26)
  {
    acc_1 = ((acc_1 + (vector_23_1 * 2)) + 5) & 127;
    aux_1 ^= vector_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_23_2 > 26)
  {
    acc_2 = ((acc_2 + (vector_23_2 * 2)) + 5) & 127;
    aux_2 ^= vector_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_93_1 = local_arr_1[aux_1 % 3];
  int factor_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_93_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_23_1 == vector_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_93_1 == factor_93_2);
}

int fn_R000837_3713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000837_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int vector_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_23 > 26)
  {
    acc = ((acc + (vector_23 * 2)) + 5) & 127;
    aux ^= vector_23 & 15;
  }
  else
  {
    acc = ((acc - vector_23) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_93 = local_arr[aux % 3];
  acc = (acc + (factor_93 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000837_3713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st_1 = {0};
  struct CipherContext_R000837_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_43_1 > 25)
  {
    acc_1 = ((acc_1 + (factor_43_1 * 2)) + 5) & 127;
    aux_1 ^= factor_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_43_2 > 25)
  {
    acc_2 = ((acc_2 + (factor_43_2 * 2)) + 5) & 127;
    aux_2 ^= factor_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_48_1 = local_arr_1[aux_1 % 3];
  int sample_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_48_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_43_1 == factor_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_48_1 == sample_48_2);
}

int fn_R000837_3713_17(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000837_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_43 > 25)
  {
    acc = ((acc + (factor_43 * 2)) + 5) & 127;
    aux ^= factor_43 & 15;
  }
  else
  {
    acc = ((acc - factor_43) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_48 = local_arr[aux % 3];
  acc = (acc + (sample_48 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000837_0_1;
  int sec_r000837_0_2;
  int sec_r000837_1_1;
  int sec_r000837_1_2;
  int sec_r000837_2_1;
  int sec_r000837_2_2;
  int sec_r000837_3_1;
  int sec_r000837_3_2;
  int sec_r000837_4_1;
  int sec_r000837_4_2;
  int sec_r000837_5_1;
  int sec_r000837_5_2;
  int sec_r000837_6_1;
  int sec_r000837_6_2;
  int sec_r000837_7_1;
  int sec_r000837_7_2;
  int sec_r000837_8_1;
  int sec_r000837_8_2;
  int sec_r000837_9_1;
  int sec_r000837_9_2;
  int sec_r000837_10_1;
  int sec_r000837_10_2;
  int sec_r000837_11_1;
  int sec_r000837_11_2;
  int sec_r000837_12_1;
  int sec_r000837_12_2;
  int sec_r000837_13_1;
  int sec_r000837_13_2;
  int sec_r000837_14_1;
  int sec_r000837_14_2;
  int sec_r000837_15_1;
  int sec_r000837_15_2;
  int sec_r000837_16_1;
  int sec_r000837_16_2;
  int sec_r000837_17_1;
  int sec_r000837_17_2;
  int sec_r000837_18_1;
  int sec_r000837_18_2;
  int sec_r000837_19_1;
  int sec_r000837_19_2;
  int sec_r000837_20_1;
  int sec_r000837_20_2;
  int pub_r000837_0_1;
  int pub_r000837_0_2;
  int pub_r000837_1_1;
  int pub_r000837_1_2;
  int pub_r000837_2_1;
  int pub_r000837_2_2;
  int pub_r000837_3_1;
  int pub_r000837_3_2;
  int pub_r000837_4_1;
  int pub_r000837_4_2;
  int pub_r000837_5_1;
  int pub_r000837_5_2;
  int pub_r000837_6_1;
  int pub_r000837_6_2;
  int pub_r000837_7_1;
  int pub_r000837_7_2;
  int pub_r000837_8_1;
  int pub_r000837_8_2;
  int pub_r000837_9_1;
  int pub_r000837_9_2;
  int pub_r000837_10_1;
  int pub_r000837_10_2;
  int pub_r000837_11_1;
  int pub_r000837_11_2;
  int pub_r000837_12_1;
  int pub_r000837_12_2;
  int pub_r000837_13_1;
  int pub_r000837_13_2;
  int pub_r000837_14_1;
  int pub_r000837_14_2;
  int pub_r000837_15_1;
  int pub_r000837_15_2;
  int pub_r000837_16_1;
  int pub_r000837_16_2;
  int pub_r000837_17_1;
  int pub_r000837_17_2;
  int pub_r000837_18_1;
  int pub_r000837_18_2;
  int pub_r000837_19_1;
  int pub_r000837_19_2;
  int pub_r000837_20_1;
  int pub_r000837_20_2;
  int pub_r000837_21_1;
  int pub_r000837_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000837_0_1 >= (-100)) && (pub_r000837_0_1 <= 100));
  __CPROVER_assume((pub_r000837_0_2 >= (-100)) && (pub_r000837_0_2 <= 100));
  __CPROVER_assume((pub_r000837_1_1 >= (-100)) && (pub_r000837_1_1 <= 100));
  __CPROVER_assume((pub_r000837_1_2 >= (-100)) && (pub_r000837_1_2 <= 100));
  __CPROVER_assume((pub_r000837_2_1 >= (-100)) && (pub_r000837_2_1 <= 100));
  __CPROVER_assume((pub_r000837_2_2 >= (-100)) && (pub_r000837_2_2 <= 100));
  __CPROVER_assume((pub_r000837_3_1 >= (-100)) && (pub_r000837_3_1 <= 100));
  __CPROVER_assume((pub_r000837_3_2 >= (-100)) && (pub_r000837_3_2 <= 100));
  __CPROVER_assume((pub_r000837_4_1 >= (-100)) && (pub_r000837_4_1 <= 100));
  __CPROVER_assume((pub_r000837_4_2 >= (-100)) && (pub_r000837_4_2 <= 100));
  __CPROVER_assume((pub_r000837_5_1 >= (-100)) && (pub_r000837_5_1 <= 100));
  __CPROVER_assume((pub_r000837_5_2 >= (-100)) && (pub_r000837_5_2 <= 100));
  __CPROVER_assume((pub_r000837_6_1 >= (-100)) && (pub_r000837_6_1 <= 100));
  __CPROVER_assume((pub_r000837_6_2 >= (-100)) && (pub_r000837_6_2 <= 100));
  __CPROVER_assume((pub_r000837_7_1 >= (-100)) && (pub_r000837_7_1 <= 100));
  __CPROVER_assume((pub_r000837_7_2 >= (-100)) && (pub_r000837_7_2 <= 100));
  __CPROVER_assume((pub_r000837_8_1 >= (-100)) && (pub_r000837_8_1 <= 100));
  __CPROVER_assume((pub_r000837_8_2 >= (-100)) && (pub_r000837_8_2 <= 100));
  __CPROVER_assume((pub_r000837_9_1 >= (-100)) && (pub_r000837_9_1 <= 100));
  __CPROVER_assume((pub_r000837_9_2 >= (-100)) && (pub_r000837_9_2 <= 100));
  __CPROVER_assume((pub_r000837_10_1 >= (-100)) && (pub_r000837_10_1 <= 100));
  __CPROVER_assume((pub_r000837_10_2 >= (-100)) && (pub_r000837_10_2 <= 100));
  __CPROVER_assume((pub_r000837_11_1 >= (-100)) && (pub_r000837_11_1 <= 100));
  __CPROVER_assume((pub_r000837_11_2 >= (-100)) && (pub_r000837_11_2 <= 100));
  __CPROVER_assume((pub_r000837_12_1 >= (-100)) && (pub_r000837_12_1 <= 100));
  __CPROVER_assume((pub_r000837_12_2 >= (-100)) && (pub_r000837_12_2 <= 100));
  __CPROVER_assume((pub_r000837_13_1 >= (-100)) && (pub_r000837_13_1 <= 100));
  __CPROVER_assume((pub_r000837_13_2 >= (-100)) && (pub_r000837_13_2 <= 100));
  __CPROVER_assume((pub_r000837_14_1 >= (-100)) && (pub_r000837_14_1 <= 100));
  __CPROVER_assume((pub_r000837_14_2 >= (-100)) && (pub_r000837_14_2 <= 100));
  __CPROVER_assume((pub_r000837_15_1 >= (-100)) && (pub_r000837_15_1 <= 100));
  __CPROVER_assume((pub_r000837_15_2 >= (-100)) && (pub_r000837_15_2 <= 100));
  __CPROVER_assume((pub_r000837_16_1 >= (-100)) && (pub_r000837_16_1 <= 100));
  __CPROVER_assume((pub_r000837_16_2 >= (-100)) && (pub_r000837_16_2 <= 100));
  __CPROVER_assume((pub_r000837_17_1 >= (-100)) && (pub_r000837_17_1 <= 100));
  __CPROVER_assume((pub_r000837_17_2 >= (-100)) && (pub_r000837_17_2 <= 100));
  __CPROVER_assume((pub_r000837_18_1 >= (-100)) && (pub_r000837_18_1 <= 100));
  __CPROVER_assume((pub_r000837_18_2 >= (-100)) && (pub_r000837_18_2 <= 100));
  __CPROVER_assume((pub_r000837_19_1 >= (-100)) && (pub_r000837_19_1 <= 100));
  __CPROVER_assume((pub_r000837_19_2 >= (-100)) && (pub_r000837_19_2 <= 100));
  __CPROVER_assume((pub_r000837_20_1 >= (-100)) && (pub_r000837_20_1 <= 100));
  __CPROVER_assume((pub_r000837_20_2 >= (-100)) && (pub_r000837_20_2 <= 100));
  __CPROVER_assume((pub_r000837_21_1 >= (-100)) && (pub_r000837_21_1 <= 100));
  __CPROVER_assume((pub_r000837_21_2 >= (-100)) && (pub_r000837_21_2 <= 100));
  __CPROVER_assume((sec_r000837_0_1 >= 0) && (sec_r000837_0_1 <= 255));
  __CPROVER_assume((sec_r000837_0_2 >= 0) && (sec_r000837_0_2 <= 255));
  __CPROVER_assume((sec_r000837_1_1 >= 0) && (sec_r000837_1_1 <= 255));
  __CPROVER_assume((sec_r000837_1_2 >= 0) && (sec_r000837_1_2 <= 255));
  __CPROVER_assume((sec_r000837_2_1 >= 0) && (sec_r000837_2_1 <= 255));
  __CPROVER_assume((sec_r000837_2_2 >= 0) && (sec_r000837_2_2 <= 255));
  __CPROVER_assume((sec_r000837_3_1 >= 0) && (sec_r000837_3_1 <= 255));
  __CPROVER_assume((sec_r000837_3_2 >= 0) && (sec_r000837_3_2 <= 255));
  __CPROVER_assume((sec_r000837_4_1 >= 0) && (sec_r000837_4_1 <= 255));
  __CPROVER_assume((sec_r000837_4_2 >= 0) && (sec_r000837_4_2 <= 255));
  __CPROVER_assume((sec_r000837_5_1 >= 0) && (sec_r000837_5_1 <= 255));
  __CPROVER_assume((sec_r000837_5_2 >= 0) && (sec_r000837_5_2 <= 255));
  __CPROVER_assume((sec_r000837_6_1 >= 0) && (sec_r000837_6_1 <= 255));
  __CPROVER_assume((sec_r000837_6_2 >= 0) && (sec_r000837_6_2 <= 255));
  __CPROVER_assume((sec_r000837_7_1 >= 0) && (sec_r000837_7_1 <= 255));
  __CPROVER_assume((sec_r000837_7_2 >= 0) && (sec_r000837_7_2 <= 255));
  __CPROVER_assume((sec_r000837_8_1 >= 0) && (sec_r000837_8_1 <= 255));
  __CPROVER_assume((sec_r000837_8_2 >= 0) && (sec_r000837_8_2 <= 255));
  __CPROVER_assume((sec_r000837_9_1 >= 0) && (sec_r000837_9_1 <= 255));
  __CPROVER_assume((sec_r000837_9_2 >= 0) && (sec_r000837_9_2 <= 255));
  __CPROVER_assume((sec_r000837_10_1 >= 0) && (sec_r000837_10_1 <= 255));
  __CPROVER_assume((sec_r000837_10_2 >= 0) && (sec_r000837_10_2 <= 255));
  __CPROVER_assume((sec_r000837_11_1 >= 0) && (sec_r000837_11_1 <= 255));
  __CPROVER_assume((sec_r000837_11_2 >= 0) && (sec_r000837_11_2 <= 255));
  __CPROVER_assume((sec_r000837_12_1 >= 0) && (sec_r000837_12_1 <= 255));
  __CPROVER_assume((sec_r000837_12_2 >= 0) && (sec_r000837_12_2 <= 255));
  __CPROVER_assume((sec_r000837_13_1 >= 0) && (sec_r000837_13_1 <= 255));
  __CPROVER_assume((sec_r000837_13_2 >= 0) && (sec_r000837_13_2 <= 255));
  __CPROVER_assume((sec_r000837_14_1 >= 0) && (sec_r000837_14_1 <= 255));
  __CPROVER_assume((sec_r000837_14_2 >= 0) && (sec_r000837_14_2 <= 255));
  __CPROVER_assume((sec_r000837_15_1 >= 0) && (sec_r000837_15_1 <= 255));
  __CPROVER_assume((sec_r000837_15_2 >= 0) && (sec_r000837_15_2 <= 255));
  __CPROVER_assume((sec_r000837_16_1 >= 0) && (sec_r000837_16_1 <= 255));
  __CPROVER_assume((sec_r000837_16_2 >= 0) && (sec_r000837_16_2 <= 255));
  __CPROVER_assume((sec_r000837_17_1 >= 0) && (sec_r000837_17_1 <= 255));
  __CPROVER_assume((sec_r000837_17_2 >= 0) && (sec_r000837_17_2 <= 255));
  __CPROVER_assume((sec_r000837_18_1 >= 0) && (sec_r000837_18_1 <= 255));
  __CPROVER_assume((sec_r000837_18_2 >= 0) && (sec_r000837_18_2 <= 255));
  __CPROVER_assume((sec_r000837_19_1 >= 0) && (sec_r000837_19_1 <= 255));
  __CPROVER_assume((sec_r000837_19_2 >= 0) && (sec_r000837_19_2 <= 255));
  __CPROVER_assume((sec_r000837_20_1 >= 0) && (sec_r000837_20_1 <= 255));
  __CPROVER_assume((sec_r000837_20_2 >= 0) && (sec_r000837_20_2 <= 255));
  struct CipherContext_R000837_3713_0 st_var_0_1 = {0};
  struct CipherContext_R000837_3713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000837_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000837_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000837_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000837_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000837_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000837_0_2 + 7) & 15;
  struct Vector3D_R000837_3713_1 st_var_1_1 = {0};
  struct Vector3D_R000837_3713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000837_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000837_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000837_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000837_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000837_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000837_0_2 + 9) & 15;
  union RegisterBank_R000837_3713_0 u_var_1;
  union RegisterBank_R000837_3713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
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

  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (8 & 31);
  int stage_v_3_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (8 & 31);
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= (stage_v_3_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_3_2 << 1) & 127;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 36)
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
  if (stage_v_4_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 36)
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
  int stage_v_5_1 = ((st_var_1_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_1_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 42)
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
  if (stage_v_5_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 42)
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
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 11) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 48)
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
  if (stage_v_12_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 48)
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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 16) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = ((st_var_0_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_0_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 50)
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
  if (stage_v_18_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 50)
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
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_23_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_23_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_23_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 27) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (33 & 31);
  int stage_v_28_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (33 & 31);
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= (stage_v_28_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_28_2 << 1) & 127;
  int stage_v_29_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (34 & 31);
  int stage_v_29_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (34 & 31);
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= (stage_v_29_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_29_2 << 1) & 127;
  int stage_v_30_1 = (st_var_0_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_0_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = ((st_var_1_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_1_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 55)
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
  if (stage_v_33_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 55)
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
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 35) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 37) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 37) & 15;
  int stage_v_36_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_36_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= stage_v_36_1;
  chk_sum_2 ^= stage_v_36_2;
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 37)
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
  if (stage_v_37_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 37)
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
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 41) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = (st_var_1_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_1_2.buffer[0] ^ 44) & 3;
  switch (stage_v_41_1)
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

  switch (stage_v_41_2)
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

  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_42_1 = ((stage_v_42_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_42_2 = ((stage_v_42_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
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
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = table_1[1];
  int stage_v_45_2 = table_2[1];
  table_1[1] = (table_1[2] + 91) & 63;
  table_2[1] = (table_2[2] + 91) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (st_var_0_1.buffer[0] ^ 49) & 3;
  int stage_v_46_2 = (st_var_0_2.buffer[0] ^ 49) & 3;
  switch (stage_v_46_1)
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

  switch (stage_v_46_2)
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

  int stage_v_47_1 = ((st_var_1_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_1_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 48)
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
  if (stage_v_47_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 48)
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
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = table_1[1];
  int stage_v_49_2 = table_2[1];
  table_1[1] = (table_1[2] + 99) & 63;
  table_2[1] = (table_2[2] + 99) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (55 & 31);
  int stage_v_50_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (55 & 31);
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= (stage_v_50_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_50_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 52) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 52) & 15;
  int stage_v_51_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_51_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= stage_v_51_1;
  chk_sum_2 ^= stage_v_51_2;
  int stage_v_52_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (57 & 31);
  int stage_v_52_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (57 & 31);
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= (stage_v_52_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_52_2 << 1) & 127;
  int stage_v_53_1 = ((st_var_1_1.buffer[2] * 2) + 166) & 63;
  int stage_v_53_2 = ((st_var_1_2.buffer[2] * 2) + 166) & 63;
  if (stage_v_53_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_53_1) - 5) & 255;
    if (stage_v_53_1 > 27)
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
  if (stage_v_53_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_53_2) - 5) & 255;
    if (stage_v_53_2 > 27)
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
  int stage_v_54_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_54_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = table_1[0];
  int stage_v_56_2 = table_2[0];
  table_1[0] = (table_1[1] + 113) & 63;
  table_2[0] = (table_2[1] + 113) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 58) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= stage_v_57_1;
  chk_sum_2 ^= stage_v_57_2;
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = (st_var_1_1.buffer[0] ^ 62) & 3;
  int stage_v_59_2 = (st_var_1_2.buffer[0] ^ 62) & 3;
  switch (stage_v_59_1)
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

  switch (stage_v_59_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 61) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 61) & 15;
  int stage_v_60_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_60_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= stage_v_60_1;
  chk_sum_2 ^= stage_v_60_2;
  int stage_v_61_1 = ((st_var_1_1.buffer[1] * 2) + 190) & 63;
  int stage_v_61_2 = ((st_var_1_2.buffer[1] * 2) + 190) & 63;
  if (stage_v_61_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_61_1) - 5) & 255;
    if (stage_v_61_1 > 26)
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
  if (stage_v_61_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_61_2) - 5) & 255;
    if (stage_v_61_2 > 26)
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
  int stage_v_62_1 = (st_var_0_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_0_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_63_1 = ((stage_v_63_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_63_2 = ((stage_v_63_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((st_var_1_1.buffer[2] * 2) + 202) & 63;
  int stage_v_65_2 = ((st_var_1_2.buffer[2] * 2) + 202) & 63;
  if (stage_v_65_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_65_1) - 5) & 255;
    if (stage_v_65_1 > 53)
    {
      chk_sum_1 ^= stage_v_65_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_65_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_65_2) - 5) & 255;
    if (stage_v_65_2 > 53)
    {
      chk_sum_2 ^= stage_v_65_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_66_1 = table_1[2];
  int stage_v_66_2 = table_2[2];
  table_1[2] = (table_1[3] + 133) & 63;
  table_2[2] = (table_2[3] + 133) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 68) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 68) & 15;
  int stage_v_67_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_67_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= stage_v_67_1;
  chk_sum_2 ^= stage_v_67_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 69) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 69) & 15;
  int stage_v_68_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_68_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= stage_v_68_1;
  chk_sum_2 ^= stage_v_68_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 70) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 70) & 15;
  int stage_v_69_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_69_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= stage_v_69_1;
  chk_sum_2 ^= stage_v_69_2;
  int stage_v_70_1 = ((st_var_0_1.buffer[1] * 2) + 217) & 63;
  int stage_v_70_2 = ((st_var_0_2.buffer[1] * 2) + 217) & 63;
  if (stage_v_70_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_70_1) - 5) & 255;
    if (stage_v_70_1 > 32)
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
  if (stage_v_70_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_70_2) - 5) & 255;
    if (stage_v_70_2 > 32)
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
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 72) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 72) & 15;
  int stage_v_71_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_71_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= stage_v_71_1;
  chk_sum_2 ^= stage_v_71_2;
  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 46)
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
  if (stage_v_72_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 46)
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
  int stage_v_73_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (78 & 31);
  int stage_v_73_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (78 & 31);
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= (stage_v_73_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_73_2 << 1) & 127;
  int stage_v_74_1 = table_1[2];
  int stage_v_74_2 = table_2[2];
  table_1[2] = (table_1[3] + 149) & 63;
  table_2[2] = (table_2[3] + 149) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_75_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_76_1 = (st_var_0_1.buffer[0] ^ 79) & 3;
  int stage_v_76_2 = (st_var_0_2.buffer[0] ^ 79) & 3;
  switch (stage_v_76_1)
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

  switch (stage_v_76_2)
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

  int stage_v_77_1 = table_1[1];
  int stage_v_77_2 = table_2[1];
  table_1[1] = (table_1[2] + 155) & 63;
  table_2[1] = (table_2[2] + 155) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_78_1 = ((stage_v_78_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_78_2 = ((stage_v_78_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = table_1[3];
  int stage_v_79_2 = table_2[3];
  table_1[3] = (table_1[0] + 159) & 63;
  table_2[3] = (table_2[0] + 159) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (st_var_0_1.buffer[0] ^ 83) & 3;
  int stage_v_80_2 = (st_var_0_2.buffer[0] ^ 83) & 3;
  switch (stage_v_80_1)
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

  switch (stage_v_80_2)
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

  int stage_v_81_1 = (st_var_1_1.buffer[0] ^ 84) & 3;
  int stage_v_81_2 = (st_var_1_2.buffer[0] ^ 84) & 3;
  switch (stage_v_81_1)
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

  switch (stage_v_81_2)
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

  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_83_1 = ((stage_v_83_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_83_2 = ((stage_v_83_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_84_1 = ((stage_v_84_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_84_2 = ((stage_v_84_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (st_var_1_1.buffer[0] ^ 88) & 3;
  int stage_v_85_2 = (st_var_1_2.buffer[0] ^ 88) & 3;
  switch (stage_v_85_1)
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

  switch (stage_v_85_2)
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

  int stage_v_86_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_86_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((sec_r000837_4_1 & 1) != 0)
  {
    if ((sec_r000837_7_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000837_8_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000837_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000837_8_1 + 7) & 127;
  }
  if ((sec_r000837_4_2 & 1) != 0)
  {
    if ((sec_r000837_7_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000837_8_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000837_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000837_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000837_12_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000837_18_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000837_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000837_18_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000837_12_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000837_18_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000837_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000837_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000837_8_1 & 1) != 0)
  {
    if ((sec_r000837_7_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000837_8_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000837_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000837_8_1 + 7) & 127;
  }
  if ((sec_r000837_8_2 & 1) != 0)
  {
    if ((sec_r000837_7_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000837_8_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000837_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000837_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000837_19_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000837_4_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000837_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000837_4_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000837_19_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000837_4_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000837_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000837_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000837_1_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000837_10_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000837_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000837_10_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000837_1_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000837_10_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000837_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000837_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000837_15_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000837_11_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000837_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000837_11_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000837_15_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000837_11_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000837_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000837_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000837_5_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000837_0_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000837_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000837_0_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000837_5_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000837_0_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000837_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000837_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000837_16_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000837_9_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000837_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000837_9_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000837_16_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000837_9_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000837_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000837_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000837_11_1 & 1) != 0)
  {
    if ((sec_r000837_13_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000837_17_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000837_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000837_17_1 + 7) & 127;
  }
  if ((sec_r000837_11_2 & 1) != 0)
  {
    if ((sec_r000837_13_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000837_17_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000837_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000837_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000837_13_1 & 1) != 0)
  {
    if ((sec_r000837_19_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000837_15_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000837_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000837_15_1 + 7) & 127;
  }
  if ((sec_r000837_13_2 & 1) != 0)
  {
    if ((sec_r000837_19_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000837_15_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000837_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000837_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000837_9_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000837_9_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000837_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000837_9_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000837_9_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000837_9_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000837_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000837_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000837_0_1 & 1) != 0)
  {
    if ((sec_r000837_4_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000837_21_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000837_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000837_21_1 + 7) & 127;
  }
  if ((sec_r000837_0_2 & 1) != 0)
  {
    if ((sec_r000837_4_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000837_21_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000837_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000837_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000837_4_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000837_2_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000837_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000837_2_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000837_4_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000837_2_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000837_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000837_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000837_3_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000837_3_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000837_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000837_3_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000837_3_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000837_3_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000837_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000837_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000837_5_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000837_11_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000837_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000837_11_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000837_5_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000837_11_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000837_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000837_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000837_13_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000837_6_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000837_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000837_6_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000837_13_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000837_6_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000837_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000837_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000837_20_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000837_2_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000837_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000837_2_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000837_20_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000837_2_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000837_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000837_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000837_0_1 & 1) != 0)
  {
    if ((sec_r000837_7_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000837_15_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000837_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000837_15_1 + 7) & 127;
  }
  if ((sec_r000837_0_2 & 1) != 0)
  {
    if ((sec_r000837_7_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000837_15_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000837_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000837_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000837_9_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000837_3_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000837_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000837_3_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000837_9_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000837_3_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000837_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000837_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000837_14_1 & 1) != 0)
  {
    if ((sec_r000837_2_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000837_6_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000837_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000837_6_1 + 7) & 127;
  }
  if ((sec_r000837_14_2 & 1) != 0)
  {
    if ((sec_r000837_2_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000837_6_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000837_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000837_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000837_15_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000837_13_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000837_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000837_13_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000837_15_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000837_13_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000837_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000837_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000837_13_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000837_14_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000837_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000837_14_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000837_13_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000837_14_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000837_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000837_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000837_3_1 & 1) != 0)
  {
    if ((sec_r000837_18_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000837_3_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000837_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000837_3_1 + 7) & 127;
  }
  if ((sec_r000837_3_2 & 1) != 0)
  {
    if ((sec_r000837_18_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000837_3_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000837_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000837_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000837_9_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000837_21_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000837_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000837_21_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000837_9_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000837_21_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000837_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000837_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000837_1_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000837_12_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000837_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000837_12_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000837_1_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000837_12_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000837_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000837_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000837_12_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000837_6_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000837_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000837_6_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000837_12_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000837_6_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000837_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000837_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000837_4_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000837_19_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000837_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000837_19_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000837_4_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000837_19_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000837_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000837_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((sec_r000837_17_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000837_8_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000837_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000837_8_1 + 7) & 127;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((sec_r000837_17_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000837_8_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000837_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000837_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000837_2_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000837_12_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000837_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000837_12_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000837_2_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000837_12_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000837_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000837_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000837_6_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000837_17_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000837_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000837_17_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000837_6_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000837_17_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000837_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000837_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000837_18_1 & 1) != 0)
  {
    if ((sec_r000837_8_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000837_17_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000837_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000837_17_1 + 7) & 127;
  }
  if ((sec_r000837_18_2 & 1) != 0)
  {
    if ((sec_r000837_8_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000837_17_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000837_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000837_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000837_17_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000837_20_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000837_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000837_20_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000837_17_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000837_20_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000837_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000837_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000837_3_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000837_15_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000837_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000837_15_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000837_3_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000837_15_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000837_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000837_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000837_16_1 & 1) != 0)
  {
    if ((sec_r000837_10_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000837_17_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000837_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000837_17_1 + 7) & 127;
  }
  if ((sec_r000837_16_2 & 1) != 0)
  {
    if ((sec_r000837_10_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000837_17_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000837_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000837_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000837_19_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000837_5_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000837_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000837_5_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000837_19_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000837_5_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000837_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000837_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000837_6_1 & 1) != 0)
  {
    if ((sec_r000837_13_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000837_20_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000837_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000837_20_1 + 7) & 127;
  }
  if ((sec_r000837_6_2 & 1) != 0)
  {
    if ((sec_r000837_13_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000837_20_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000837_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000837_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000837_2_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000837_0_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000837_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000837_0_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000837_2_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000837_0_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000837_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000837_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000837_2_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000837_4_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000837_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000837_4_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000837_2_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000837_4_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000837_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000837_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000837_17_1 & 1) != 0)
  {
    if ((sec_r000837_20_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000837_12_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000837_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000837_12_1 + 7) & 127;
  }
  if ((sec_r000837_17_2 & 1) != 0)
  {
    if ((sec_r000837_20_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000837_12_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000837_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000837_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000837_18_1 & 1) != 0)
  {
    if ((sec_r000837_0_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000837_16_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000837_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000837_16_1 + 7) & 127;
  }
  if ((sec_r000837_18_2 & 1) != 0)
  {
    if ((sec_r000837_0_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000837_16_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000837_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000837_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000837_8_1 & 1) != 0)
  {
    if ((sec_r000837_10_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000837_21_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000837_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000837_21_1 + 7) & 127;
  }
  if ((sec_r000837_8_2 & 1) != 0)
  {
    if ((sec_r000837_10_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000837_21_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000837_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000837_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000837_16_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000837_19_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000837_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000837_19_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000837_16_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000837_19_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000837_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000837_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000837_20_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000837_19_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000837_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000837_19_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000837_20_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000837_19_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000837_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000837_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000837_13_1 & 1) != 0)
  {
    if ((sec_r000837_15_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000837_20_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000837_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000837_20_1 + 7) & 127;
  }
  if ((sec_r000837_13_2 & 1) != 0)
  {
    if ((sec_r000837_15_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000837_20_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000837_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000837_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000837_18_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000837_11_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000837_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000837_11_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000837_18_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000837_11_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000837_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000837_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000837_13_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000837_3_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000837_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000837_3_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000837_13_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000837_3_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000837_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000837_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((sec_r000837_17_1 & 1) != 0)
  {
    if ((sec_r000837_11_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000837_9_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000837_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000837_9_1 + 7) & 127;
  }
  if ((sec_r000837_17_2 & 1) != 0)
  {
    if ((sec_r000837_11_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000837_9_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000837_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000837_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000837_2_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000837_20_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000837_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000837_20_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000837_2_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000837_20_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000837_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000837_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000837_8_1 & 1) != 0)
  {
    if ((sec_r000837_15_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000837_9_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000837_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000837_9_1 + 7) & 127;
  }
  if ((sec_r000837_8_2 & 1) != 0)
  {
    if ((sec_r000837_15_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000837_9_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000837_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000837_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000837_13_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000837_17_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000837_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000837_17_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000837_13_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000837_17_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000837_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000837_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r000837_9_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000837_17_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000837_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000837_17_1 + 7) & 127;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r000837_9_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000837_17_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000837_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000837_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000837_6_1 & 1) != 0)
  {
    if ((sec_r000837_19_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000837_10_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000837_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000837_10_1 + 7) & 127;
  }
  if ((sec_r000837_6_2 & 1) != 0)
  {
    if ((sec_r000837_19_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000837_10_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000837_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000837_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000837_18_1 & 1) != 0)
  {
    if ((sec_r000837_19_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000837_16_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000837_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000837_16_1 + 7) & 127;
  }
  if ((sec_r000837_18_2 & 1) != 0)
  {
    if ((sec_r000837_19_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000837_16_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000837_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000837_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000837_16_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000837_6_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000837_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000837_6_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000837_16_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000837_6_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000837_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000837_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000837_3_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000837_19_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000837_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000837_19_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000837_3_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000837_19_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000837_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000837_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((sec_r000837_19_1 & 1) != 0)
  {
    if ((sec_r000837_17_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000837_2_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000837_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000837_2_1 + 7) & 127;
  }
  if ((sec_r000837_19_2 & 1) != 0)
  {
    if ((sec_r000837_17_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000837_2_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000837_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000837_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000837_7_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000837_3_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000837_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000837_3_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000837_7_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000837_3_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000837_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000837_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000837_9_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000837_11_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000837_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000837_11_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000837_9_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000837_11_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000837_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000837_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((sec_r000837_18_1 & 1) != 0)
  {
    if ((sec_r000837_7_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000837_19_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000837_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000837_19_1 + 7) & 127;
  }
  if ((sec_r000837_18_2 & 1) != 0)
  {
    if ((sec_r000837_7_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000837_19_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000837_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000837_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000837_17_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000837_19_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000837_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000837_19_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000837_17_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000837_19_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000837_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000837_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000837_16_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000837_14_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000837_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000837_14_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000837_16_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000837_14_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000837_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000837_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000837_7_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000837_1_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000837_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000837_1_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000837_7_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000837_1_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000837_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000837_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((sec_r000837_19_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000837_1_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000837_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000837_1_1 + 7) & 127;
  }
  if ((stage_v_148_2 & 1) != 0)
  {
    if ((sec_r000837_19_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000837_1_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000837_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000837_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((sec_r000837_5_1 & 1) != 0)
  {
    if ((sec_r000837_0_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000837_21_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000837_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000837_21_1 + 7) & 127;
  }
  if ((sec_r000837_5_2 & 1) != 0)
  {
    if ((sec_r000837_0_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000837_21_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000837_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000837_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000837_4_1 & 1) != 0)
  {
    if ((sec_r000837_16_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000837_6_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000837_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000837_6_1 + 7) & 127;
  }
  if ((sec_r000837_4_2 & 1) != 0)
  {
    if ((sec_r000837_16_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000837_6_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000837_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000837_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000837_18_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000837_20_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000837_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000837_20_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000837_18_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000837_20_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000837_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000837_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((sec_r000837_13_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000837_8_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000837_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000837_8_1 + 7) & 127;
  }
  if ((stage_v_138_2 & 1) != 0)
  {
    if ((sec_r000837_13_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000837_8_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000837_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000837_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000837_18_1 != sec_r000837_18_2);
  __CPROVER_assume(sec_r000837_10_1 != sec_r000837_10_2);
  __CPROVER_assume(pub_r000837_15_1 == pub_r000837_15_2);
  __CPROVER_assume(pub_r000837_0_1 == pub_r000837_0_2);
  __CPROVER_assume(sec_r000837_11_1 != sec_r000837_11_2);
  __CPROVER_assume(sec_r000837_15_1 != sec_r000837_15_2);
  __CPROVER_assume(pub_r000837_3_1 == pub_r000837_3_2);
  __CPROVER_assume(sec_r000837_19_1 != sec_r000837_19_2);
  __CPROVER_assume(pub_r000837_12_1 == pub_r000837_12_2);
  __CPROVER_assume(sec_r000837_13_1 != sec_r000837_13_2);
  __CPROVER_assume(sec_r000837_12_1 != sec_r000837_12_2);
  __CPROVER_assume(pub_r000837_20_1 == pub_r000837_20_2);
  __CPROVER_assume(pub_r000837_21_1 == pub_r000837_21_2);
  __CPROVER_assume(pub_r000837_18_1 == pub_r000837_18_2);
  __CPROVER_assume(sec_r000837_17_1 != sec_r000837_17_2);
  __CPROVER_assume(pub_r000837_19_1 == pub_r000837_19_2);
  __CPROVER_assume(sec_r000837_7_1 != sec_r000837_7_2);
  __CPROVER_assume(pub_r000837_1_1 == pub_r000837_1_2);
  __CPROVER_assume(pub_r000837_6_1 == pub_r000837_6_2);
  __CPROVER_assume(pub_r000837_13_1 == pub_r000837_13_2);
  __CPROVER_assume(sec_r000837_2_1 != sec_r000837_2_2);
  __CPROVER_assume(sec_r000837_5_1 != sec_r000837_5_2);
  __CPROVER_assume(pub_r000837_11_1 == pub_r000837_11_2);
  __CPROVER_assume(sec_r000837_4_1 != sec_r000837_4_2);
  __CPROVER_assume(pub_r000837_10_1 == pub_r000837_10_2);
  __CPROVER_assume(pub_r000837_5_1 == pub_r000837_5_2);
  __CPROVER_assume(pub_r000837_8_1 == pub_r000837_8_2);
  __CPROVER_assume(sec_r000837_9_1 != sec_r000837_9_2);
  __CPROVER_assume(pub_r000837_14_1 == pub_r000837_14_2);
  __CPROVER_assume(sec_r000837_6_1 != sec_r000837_6_2);
  __CPROVER_assume(sec_r000837_8_1 != sec_r000837_8_2);
  __CPROVER_assume(pub_r000837_2_1 == pub_r000837_2_2);
  __CPROVER_assume(sec_r000837_14_1 != sec_r000837_14_2);
  __CPROVER_assume(sec_r000837_16_1 != sec_r000837_16_2);
  __CPROVER_assume(sec_r000837_1_1 != sec_r000837_1_2);
  __CPROVER_assume(pub_r000837_16_1 == pub_r000837_16_2);
  __CPROVER_assume(pub_r000837_9_1 == pub_r000837_9_2);
  __CPROVER_assume(sec_r000837_3_1 != sec_r000837_3_2);
  __CPROVER_assume(pub_r000837_4_1 == pub_r000837_4_2);
  __CPROVER_assume(pub_r000837_17_1 == pub_r000837_17_2);
  __CPROVER_assume(sec_r000837_0_1 != sec_r000837_0_2);
  __CPROVER_assume(pub_r000837_7_1 == pub_r000837_7_2);
  __CPROVER_assume(sec_r000837_20_1 != sec_r000837_20_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
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
}


