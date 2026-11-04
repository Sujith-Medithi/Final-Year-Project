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
struct DeviceConfig_R000276_7613_0
{
  int port;
  int id;
  short timeout;
  short stop_bits;
  unsigned char parity;
  int buffer[3];
};
struct Vector3D_R000276_7613_1
{
  short pitch;
  short coord_z;
  short coord_x;
  short heading;
  int buffer[3];
};
struct FilterState_R000276_7613_2
{
  short prev_in;
  int cutoff;
  unsigned char gain_db;
  unsigned char mode;
  int buffer[3];
};
union TelemetryField_R000276_7613_0
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
void fn_R000276_7613_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000276_7613_1 st_1 = {0};
  struct Vector3D_R000276_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int delta_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_21_1) & 63;
  aux_2 = (aux_2 + delta_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_50_1 = local_arr_1[aux_1 % 3];
  int cursor_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_50_2 * 2)) & 127;
  int tally_79_1 = 0;
  int tally_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_79_1 = ((tally_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_79_2 = ((tally_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_79_1) & 127;
    acc_2 = (acc_2 + tally_79_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_21_1 == delta_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_50_1 == cursor_50_2);
  assert(tally_79_1 == tally_79_2);
}

int fn_R000276_7613_0(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000276_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int delta_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_21) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int cursor_50 = local_arr[aux % 3];
  acc = (acc + (cursor_50 * 2)) & 127;
  int tally_79 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_79 = ((tally_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_79) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000276_7613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000276_7613_1 st_1 = {0};
  struct Vector3D_R000276_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int scale_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_69_1 > 18)
  {
    acc_1 = ((acc_1 + (scale_69_1 * 2)) + 5) & 127;
    aux_1 ^= scale_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_69_2 > 18)
  {
    acc_2 = ((acc_2 + (scale_69_2 * 2)) + 5) & 127;
    aux_2 ^= scale_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_35_1)
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

  switch (tally_35_2)
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
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_69_1 == scale_69_2);
  assert(tally_35_1 == tally_35_2);
}

int fn_R000276_7613_1(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000276_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int scale_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_69 > 18)
  {
    acc = ((acc + (scale_69 * 2)) + 5) & 127;
    aux ^= scale_69 & 15;
  }
  else
  {
    acc = ((acc - scale_69) + 11) & 127;
    aux += 3;
  }
  int tally_35 = (aux + st.buffer[1]) & 3;
  switch (tally_35)
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

void fn_R000276_7613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000276_7613_0 st_1 = {0};
  struct DeviceConfig_R000276_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int tally_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_44_1 > 18)
  {
    acc_1 = ((acc_1 + (tally_44_1 * 2)) + 5) & 127;
    aux_1 ^= tally_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_44_2 > 18)
  {
    acc_2 = ((acc_2 + (tally_44_2 * 2)) + 5) & 127;
    aux_2 ^= tally_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_44_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_21_1 = local_arr_1[aux_1 % 3];
  int margin_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_44_1 == tally_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_21_1 == margin_21_2);
}

int fn_R000276_7613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000276_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int tally_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_44 > 18)
  {
    acc = ((acc + (tally_44 * 2)) + 5) & 127;
    aux ^= tally_44 & 15;
  }
  else
  {
    acc = ((acc - tally_44) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_21 = local_arr[aux % 3];
  acc = (acc + (margin_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000276_7613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000276_7613_0 st_1 = {0};
  struct DeviceConfig_R000276_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int factor_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_51_1 > 27)
  {
    acc_1 = ((acc_1 + (factor_51_1 * 2)) + 5) & 127;
    aux_1 ^= factor_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_51_2 > 27)
  {
    acc_2 = ((acc_2 + (factor_51_2 * 2)) + 5) & 127;
    aux_2 ^= factor_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_49_1)
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

  switch (coefficient_49_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_51_1 == factor_51_2);
  assert(coefficient_49_1 == coefficient_49_2);
}

int fn_R000276_7613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000276_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int factor_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_51 > 27)
  {
    acc = ((acc + (factor_51 * 2)) + 5) & 127;
    aux ^= factor_51 & 15;
  }
  else
  {
    acc = ((acc - factor_51) + 11) & 127;
    aux += 3;
  }
  int coefficient_49 = (aux + st.buffer[1]) & 3;
  switch (coefficient_49)
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

void fn_R000276_7613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000276_7613_1 st_1 = {0};
  struct Vector3D_R000276_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int mask_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_95_1) & 63;
  aux_2 = (aux_2 + mask_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_48_1 = local_arr_1[aux_1 % 3];
  int mask_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_48_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_95_1 == mask_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_48_1 == mask_48_2);
}

int fn_R000276_7613_4(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000276_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int mask_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_95) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_48 = local_arr[aux % 3];
  acc = (acc + (mask_48 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000276_7613_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000276_7613_0 st_1 = {0};
  struct DeviceConfig_R000276_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_54_1)
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

  switch (tracker_54_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_54_1 == tracker_54_2);
}

int fn_R000276_7613_5(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000276_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_54 = (aux + st.buffer[1]) & 3;
  switch (tracker_54)
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

void fn_R000276_7613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000276_7613_0 st_1 = {0};
  struct DeviceConfig_R000276_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int accumulator_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_85_1 > 48)
  {
    acc_1 = ((acc_1 + (accumulator_85_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_85_2 > 48)
  {
    acc_2 = ((acc_2 + (accumulator_85_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_90_1 = local_arr_1[aux_1 % 3];
  int window_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_90_2 * 2)) & 127;
  int pivot_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_91_1) & 63;
  aux_2 = (aux_2 + pivot_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_85_1 == accumulator_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_90_1 == window_90_2);
  assert(pivot_91_1 == pivot_91_2);
}

int fn_R000276_7613_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000276_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int accumulator_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_85 > 48)
  {
    acc = ((acc + (accumulator_85 * 2)) + 5) & 127;
    aux ^= accumulator_85 & 15;
  }
  else
  {
    acc = ((acc - accumulator_85) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_90 = local_arr[aux % 3];
  acc = (acc + (window_90 * 2)) & 127;
  int pivot_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_91) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000276_7613_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000276_7613_2 st_1 = {0};
  struct FilterState_R000276_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int tracker_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_23_1)
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

  switch (tracker_23_2)
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

  int coefficient_77_1 = 0;
  int coefficient_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_77_1 = ((coefficient_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_77_2 = ((coefficient_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_77_1) & 127;
    acc_2 = (acc_2 + coefficient_77_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_23_1 == tracker_23_2);
  assert(coefficient_77_1 == coefficient_77_2);
}

int fn_R000276_7613_7(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000276_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int tracker_23 = (aux + st.buffer[1]) & 3;
  switch (tracker_23)
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

  int coefficient_77 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_77 = ((coefficient_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_77) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000276_7613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000276_7613_2 st_1 = {0};
  struct FilterState_R000276_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int index_reg_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_87_1 > 25)
  {
    acc_1 = ((acc_1 + (index_reg_87_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_87_2 > 25)
  {
    acc_2 = ((acc_2 + (index_reg_87_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_31_1 = local_arr_1[aux_1 % 3];
  int checksum_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_87_1 == index_reg_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_31_1 == checksum_31_2);
}

int fn_R000276_7613_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000276_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int index_reg_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_87 > 25)
  {
    acc = ((acc + (index_reg_87 * 2)) + 5) & 127;
    aux ^= index_reg_87 & 15;
  }
  else
  {
    acc = ((acc - index_reg_87) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_31 = local_arr[aux % 3];
  acc = (acc + (checksum_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000276_7613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000276_7613_0 st_1 = {0};
  struct DeviceConfig_R000276_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int weight_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_37_1 > 17)
  {
    acc_1 = ((acc_1 + (weight_37_1 * 2)) + 5) & 127;
    aux_1 ^= weight_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_37_2 > 17)
  {
    acc_2 = ((acc_2 + (weight_37_2 * 2)) + 5) & 127;
    aux_2 ^= weight_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_35_1) & 63;
  aux_2 = (aux_2 + window_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_44_1 = local_arr_1[aux_1 % 3];
  int anchor_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_37_1 == weight_37_2);
  assert(window_35_1 == window_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_44_1 == anchor_44_2);
}

int fn_R000276_7613_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000276_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int weight_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_37 > 17)
  {
    acc = ((acc + (weight_37 * 2)) + 5) & 127;
    aux ^= weight_37 & 15;
  }
  else
  {
    acc = ((acc - weight_37) + 11) & 127;
    aux += 3;
  }
  int window_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_35) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_44 = local_arr[aux % 3];
  acc = (acc + (anchor_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000276_7613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000276_7613_1 st_1 = {0};
  struct Vector3D_R000276_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int weight_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_24_1 > 47)
  {
    acc_1 = ((acc_1 + (weight_24_1 * 2)) + 5) & 127;
    aux_1 ^= weight_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_24_2 > 47)
  {
    acc_2 = ((acc_2 + (weight_24_2 * 2)) + 5) & 127;
    aux_2 ^= weight_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_86_1) & 63;
  aux_2 = (aux_2 + accumulator_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_24_1 == weight_24_2);
  assert(accumulator_86_1 == accumulator_86_2);
}

int fn_R000276_7613_10(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000276_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int weight_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_24 > 47)
  {
    acc = ((acc + (weight_24 * 2)) + 5) & 127;
    aux ^= weight_24 & 15;
  }
  else
  {
    acc = ((acc - weight_24) + 11) & 127;
    aux += 3;
  }
  int accumulator_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000276_7613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000276_7613_2 st_1 = {0};
  struct FilterState_R000276_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quantum_75_1 = 0;
  int quantum_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_75_1 = ((quantum_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_75_2 = ((quantum_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_75_1) & 127;
    acc_2 = (acc_2 + quantum_75_2) & 127;
  }

  int accumulator_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_19_1) & 63;
  aux_2 = (aux_2 + accumulator_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_75_1 == quantum_75_2);
  assert(accumulator_19_1 == accumulator_19_2);
}

int fn_R000276_7613_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000276_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quantum_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_75 = ((quantum_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_75) & 127;
  }

  int accumulator_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_19) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000276_7613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000276_7613_2 st_1 = {0};
  struct FilterState_R000276_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int margin_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_79_1 > 14)
  {
    acc_1 = ((acc_1 + (margin_79_1 * 2)) + 5) & 127;
    aux_1 ^= margin_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_79_2 > 14)
  {
    acc_2 = ((acc_2 + (margin_79_2 * 2)) + 5) & 127;
    aux_2 ^= margin_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_55_1)
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

  switch (vector_55_2)
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

  int damping_19_1 = 0;
  int damping_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_19_1 = ((damping_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_19_2 = ((damping_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_19_1) & 127;
    acc_2 = (acc_2 + damping_19_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_79_1 == margin_79_2);
  assert(vector_55_1 == vector_55_2);
  assert(damping_19_1 == damping_19_2);
}

int fn_R000276_7613_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000276_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int margin_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_79 > 14)
  {
    acc = ((acc + (margin_79 * 2)) + 5) & 127;
    aux ^= margin_79 & 15;
  }
  else
  {
    acc = ((acc - margin_79) + 11) & 127;
    aux += 3;
  }
  int vector_55 = (aux + st.buffer[1]) & 3;
  switch (vector_55)
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

  int damping_19 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_19 = ((damping_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_19) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000276_7613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000276_7613_2 st_1 = {0};
  struct FilterState_R000276_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_60_1 = local_arr_1[aux_1 % 3];
  int quantum_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_60_2 * 2)) & 127;
  int phase_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_20_1 > 19)
  {
    acc_1 = ((acc_1 + (phase_20_1 * 2)) + 5) & 127;
    aux_1 ^= phase_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_20_2 > 19)
  {
    acc_2 = ((acc_2 + (phase_20_2 * 2)) + 5) & 127;
    aux_2 ^= phase_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_20_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_60_1 == quantum_60_2);
  assert(phase_20_1 == phase_20_2);
}

int fn_R000276_7613_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000276_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int quantum_60 = local_arr[aux % 3];
  acc = (acc + (quantum_60 * 2)) & 127;
  int phase_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_20 > 19)
  {
    acc = ((acc + (phase_20 * 2)) + 5) & 127;
    aux ^= phase_20 & 15;
  }
  else
  {
    acc = ((acc - phase_20) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000276_7613_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000276_7613_2 st_1 = {0};
  struct FilterState_R000276_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int pivot_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_77_1)
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

  switch (pivot_77_2)
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

  int quotient_95_1 = 0;
  int quotient_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_95_1 = ((quotient_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_95_2 = ((quotient_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_95_1) & 127;
    acc_2 = (acc_2 + quotient_95_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_77_1 == pivot_77_2);
  assert(quotient_95_1 == quotient_95_2);
}

int fn_R000276_7613_14(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000276_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int pivot_77 = (aux + st.buffer[1]) & 3;
  switch (pivot_77)
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

  int quotient_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_95 = ((quotient_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_95) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000276_7613_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000276_7613_1 st_1 = {0};
  struct Vector3D_R000276_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int coefficient_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_60_1) & 63;
  aux_2 = (aux_2 + coefficient_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_12_1 = local_arr_1[aux_1 % 3];
  int quotient_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_12_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_60_1 == coefficient_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_12_1 == quotient_12_2);
}

int fn_R000276_7613_15(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000276_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int coefficient_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_60) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_12 = local_arr[aux % 3];
  acc = (acc + (quotient_12 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000276_7613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000276_7613_0 st_1 = {0};
  struct DeviceConfig_R000276_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int cursor_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_61_1)
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

  switch (cursor_61_2)
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

  int scale_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_91_1) & 63;
  aux_2 = (aux_2 + scale_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_17_1 = local_arr_1[aux_1 % 3];
  int delta_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_17_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_61_1 == cursor_61_2);
  assert(scale_91_1 == scale_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_17_1 == delta_17_2);
}

int fn_R000276_7613_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000276_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int cursor_61 = (aux + st.buffer[1]) & 3;
  switch (cursor_61)
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

  int scale_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_91) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_17 = local_arr[aux % 3];
  acc = (acc + (delta_17 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000276_7613_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000276_7613_1 st_1 = {0};
  struct Vector3D_R000276_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_29_1)
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

  switch (tracker_29_2)
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
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_29_1 == tracker_29_2);
}

int fn_R000276_7613_17(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000276_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_29 = (aux + st.buffer[1]) & 3;
  switch (tracker_29)
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

void fn_R000276_7613_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000276_7613_0 st_1 = {0};
  struct DeviceConfig_R000276_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int accumulator_66_1 = 0;
  int accumulator_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_66_1 = ((accumulator_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_66_2 = ((accumulator_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_66_1) & 127;
    acc_2 = (acc_2 + accumulator_66_2) & 127;
  }

  int vector_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_79_1 > 42)
  {
    acc_1 = ((acc_1 + (vector_79_1 * 2)) + 5) & 127;
    aux_1 ^= vector_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_79_2 > 42)
  {
    acc_2 = ((acc_2 + (vector_79_2 * 2)) + 5) & 127;
    aux_2 ^= vector_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_79_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_66_1 == accumulator_66_2);
  assert(vector_79_1 == vector_79_2);
}

int fn_R000276_7613_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000276_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int accumulator_66 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_66 = ((accumulator_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_66) & 127;
  }

  int vector_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_79 > 42)
  {
    acc = ((acc + (vector_79 * 2)) + 5) & 127;
    aux ^= vector_79 & 15;
  }
  else
  {
    acc = ((acc - vector_79) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000276_7613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000276_7613_2 st_1 = {0};
  struct FilterState_R000276_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int margin_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_14_1)
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

  switch (margin_14_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_40_1 = local_arr_1[aux_1 % 3];
  int index_reg_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_40_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_14_1 == margin_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_40_1 == index_reg_40_2);
}

int fn_R000276_7613_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000276_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int margin_14 = (aux + st.buffer[1]) & 3;
  switch (margin_14)
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
  int local_arr[3] = {4, 9, 15};
  int index_reg_40 = local_arr[aux % 3];
  acc = (acc + (index_reg_40 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000276_7613_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000276_7613_1 st_1 = {0};
  struct Vector3D_R000276_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int tally_57_1 = 0;
  int tally_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_57_1 = ((tally_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_57_2 = ((tally_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_57_1) & 127;
    acc_2 = (acc_2 + tally_57_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_72_1 > 38)
  {
    acc_1 = ((acc_1 + (quotient_72_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_72_2 > 38)
  {
    acc_2 = ((acc_2 + (quotient_72_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_36_1)
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

  switch (index_reg_36_2)
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
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_57_1 == tally_57_2);
  assert(quotient_72_1 == quotient_72_2);
  assert(index_reg_36_1 == index_reg_36_2);
}

int fn_R000276_7613_20(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000276_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int tally_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_57 = ((tally_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_57) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_72 > 38)
  {
    acc = ((acc + (quotient_72 * 2)) + 5) & 127;
    aux ^= quotient_72 & 15;
  }
  else
  {
    acc = ((acc - quotient_72) + 11) & 127;
    aux += 3;
  }
  int index_reg_36 = (aux + st.buffer[1]) & 3;
  switch (index_reg_36)
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

void main()
{
  int sec_r000276_0_1;
  int sec_r000276_0_2;
  int sec_r000276_1_1;
  int sec_r000276_1_2;
  int sec_r000276_2_1;
  int sec_r000276_2_2;
  int sec_r000276_3_1;
  int sec_r000276_3_2;
  int sec_r000276_4_1;
  int sec_r000276_4_2;
  int sec_r000276_5_1;
  int sec_r000276_5_2;
  int sec_r000276_6_1;
  int sec_r000276_6_2;
  int sec_r000276_7_1;
  int sec_r000276_7_2;
  int sec_r000276_8_1;
  int sec_r000276_8_2;
  int sec_r000276_9_1;
  int sec_r000276_9_2;
  int sec_r000276_10_1;
  int sec_r000276_10_2;
  int sec_r000276_11_1;
  int sec_r000276_11_2;
  int sec_r000276_12_1;
  int sec_r000276_12_2;
  int sec_r000276_13_1;
  int sec_r000276_13_2;
  int sec_r000276_14_1;
  int sec_r000276_14_2;
  int sec_r000276_15_1;
  int sec_r000276_15_2;
  int sec_r000276_16_1;
  int sec_r000276_16_2;
  int pub_r000276_0_1;
  int pub_r000276_0_2;
  int pub_r000276_1_1;
  int pub_r000276_1_2;
  int pub_r000276_2_1;
  int pub_r000276_2_2;
  int pub_r000276_3_1;
  int pub_r000276_3_2;
  int pub_r000276_4_1;
  int pub_r000276_4_2;
  int pub_r000276_5_1;
  int pub_r000276_5_2;
  int pub_r000276_6_1;
  int pub_r000276_6_2;
  int pub_r000276_7_1;
  int pub_r000276_7_2;
  int pub_r000276_8_1;
  int pub_r000276_8_2;
  int pub_r000276_9_1;
  int pub_r000276_9_2;
  int pub_r000276_10_1;
  int pub_r000276_10_2;
  int pub_r000276_11_1;
  int pub_r000276_11_2;
  int pub_r000276_12_1;
  int pub_r000276_12_2;
  int pub_r000276_13_1;
  int pub_r000276_13_2;
  int pub_r000276_14_1;
  int pub_r000276_14_2;
  int pub_r000276_15_1;
  int pub_r000276_15_2;
  int pub_r000276_16_1;
  int pub_r000276_16_2;
  int pub_r000276_17_1;
  int pub_r000276_17_2;
  int pub_r000276_18_1;
  int pub_r000276_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000276_0_1 >= (-100)) && (pub_r000276_0_1 <= 100));
  __CPROVER_assume((pub_r000276_0_2 >= (-100)) && (pub_r000276_0_2 <= 100));
  __CPROVER_assume((pub_r000276_1_1 >= (-100)) && (pub_r000276_1_1 <= 100));
  __CPROVER_assume((pub_r000276_1_2 >= (-100)) && (pub_r000276_1_2 <= 100));
  __CPROVER_assume((pub_r000276_2_1 >= (-100)) && (pub_r000276_2_1 <= 100));
  __CPROVER_assume((pub_r000276_2_2 >= (-100)) && (pub_r000276_2_2 <= 100));
  __CPROVER_assume((pub_r000276_3_1 >= (-100)) && (pub_r000276_3_1 <= 100));
  __CPROVER_assume((pub_r000276_3_2 >= (-100)) && (pub_r000276_3_2 <= 100));
  __CPROVER_assume((pub_r000276_4_1 >= (-100)) && (pub_r000276_4_1 <= 100));
  __CPROVER_assume((pub_r000276_4_2 >= (-100)) && (pub_r000276_4_2 <= 100));
  __CPROVER_assume((pub_r000276_5_1 >= (-100)) && (pub_r000276_5_1 <= 100));
  __CPROVER_assume((pub_r000276_5_2 >= (-100)) && (pub_r000276_5_2 <= 100));
  __CPROVER_assume((pub_r000276_6_1 >= (-100)) && (pub_r000276_6_1 <= 100));
  __CPROVER_assume((pub_r000276_6_2 >= (-100)) && (pub_r000276_6_2 <= 100));
  __CPROVER_assume((pub_r000276_7_1 >= (-100)) && (pub_r000276_7_1 <= 100));
  __CPROVER_assume((pub_r000276_7_2 >= (-100)) && (pub_r000276_7_2 <= 100));
  __CPROVER_assume((pub_r000276_8_1 >= (-100)) && (pub_r000276_8_1 <= 100));
  __CPROVER_assume((pub_r000276_8_2 >= (-100)) && (pub_r000276_8_2 <= 100));
  __CPROVER_assume((pub_r000276_9_1 >= (-100)) && (pub_r000276_9_1 <= 100));
  __CPROVER_assume((pub_r000276_9_2 >= (-100)) && (pub_r000276_9_2 <= 100));
  __CPROVER_assume((pub_r000276_10_1 >= (-100)) && (pub_r000276_10_1 <= 100));
  __CPROVER_assume((pub_r000276_10_2 >= (-100)) && (pub_r000276_10_2 <= 100));
  __CPROVER_assume((pub_r000276_11_1 >= (-100)) && (pub_r000276_11_1 <= 100));
  __CPROVER_assume((pub_r000276_11_2 >= (-100)) && (pub_r000276_11_2 <= 100));
  __CPROVER_assume((pub_r000276_12_1 >= (-100)) && (pub_r000276_12_1 <= 100));
  __CPROVER_assume((pub_r000276_12_2 >= (-100)) && (pub_r000276_12_2 <= 100));
  __CPROVER_assume((pub_r000276_13_1 >= (-100)) && (pub_r000276_13_1 <= 100));
  __CPROVER_assume((pub_r000276_13_2 >= (-100)) && (pub_r000276_13_2 <= 100));
  __CPROVER_assume((pub_r000276_14_1 >= (-100)) && (pub_r000276_14_1 <= 100));
  __CPROVER_assume((pub_r000276_14_2 >= (-100)) && (pub_r000276_14_2 <= 100));
  __CPROVER_assume((pub_r000276_15_1 >= (-100)) && (pub_r000276_15_1 <= 100));
  __CPROVER_assume((pub_r000276_15_2 >= (-100)) && (pub_r000276_15_2 <= 100));
  __CPROVER_assume((pub_r000276_16_1 >= (-100)) && (pub_r000276_16_1 <= 100));
  __CPROVER_assume((pub_r000276_16_2 >= (-100)) && (pub_r000276_16_2 <= 100));
  __CPROVER_assume((pub_r000276_17_1 >= (-100)) && (pub_r000276_17_1 <= 100));
  __CPROVER_assume((pub_r000276_17_2 >= (-100)) && (pub_r000276_17_2 <= 100));
  __CPROVER_assume((pub_r000276_18_1 >= (-100)) && (pub_r000276_18_1 <= 100));
  __CPROVER_assume((pub_r000276_18_2 >= (-100)) && (pub_r000276_18_2 <= 100));
  __CPROVER_assume((sec_r000276_0_1 >= 0) && (sec_r000276_0_1 <= 255));
  __CPROVER_assume((sec_r000276_0_2 >= 0) && (sec_r000276_0_2 <= 255));
  __CPROVER_assume((sec_r000276_1_1 >= 0) && (sec_r000276_1_1 <= 255));
  __CPROVER_assume((sec_r000276_1_2 >= 0) && (sec_r000276_1_2 <= 255));
  __CPROVER_assume((sec_r000276_2_1 >= 0) && (sec_r000276_2_1 <= 255));
  __CPROVER_assume((sec_r000276_2_2 >= 0) && (sec_r000276_2_2 <= 255));
  __CPROVER_assume((sec_r000276_3_1 >= 0) && (sec_r000276_3_1 <= 255));
  __CPROVER_assume((sec_r000276_3_2 >= 0) && (sec_r000276_3_2 <= 255));
  __CPROVER_assume((sec_r000276_4_1 >= 0) && (sec_r000276_4_1 <= 255));
  __CPROVER_assume((sec_r000276_4_2 >= 0) && (sec_r000276_4_2 <= 255));
  __CPROVER_assume((sec_r000276_5_1 >= 0) && (sec_r000276_5_1 <= 255));
  __CPROVER_assume((sec_r000276_5_2 >= 0) && (sec_r000276_5_2 <= 255));
  __CPROVER_assume((sec_r000276_6_1 >= 0) && (sec_r000276_6_1 <= 255));
  __CPROVER_assume((sec_r000276_6_2 >= 0) && (sec_r000276_6_2 <= 255));
  __CPROVER_assume((sec_r000276_7_1 >= 0) && (sec_r000276_7_1 <= 255));
  __CPROVER_assume((sec_r000276_7_2 >= 0) && (sec_r000276_7_2 <= 255));
  __CPROVER_assume((sec_r000276_8_1 >= 0) && (sec_r000276_8_1 <= 255));
  __CPROVER_assume((sec_r000276_8_2 >= 0) && (sec_r000276_8_2 <= 255));
  __CPROVER_assume((sec_r000276_9_1 >= 0) && (sec_r000276_9_1 <= 255));
  __CPROVER_assume((sec_r000276_9_2 >= 0) && (sec_r000276_9_2 <= 255));
  __CPROVER_assume((sec_r000276_10_1 >= 0) && (sec_r000276_10_1 <= 255));
  __CPROVER_assume((sec_r000276_10_2 >= 0) && (sec_r000276_10_2 <= 255));
  __CPROVER_assume((sec_r000276_11_1 >= 0) && (sec_r000276_11_1 <= 255));
  __CPROVER_assume((sec_r000276_11_2 >= 0) && (sec_r000276_11_2 <= 255));
  __CPROVER_assume((sec_r000276_12_1 >= 0) && (sec_r000276_12_1 <= 255));
  __CPROVER_assume((sec_r000276_12_2 >= 0) && (sec_r000276_12_2 <= 255));
  __CPROVER_assume((sec_r000276_13_1 >= 0) && (sec_r000276_13_1 <= 255));
  __CPROVER_assume((sec_r000276_13_2 >= 0) && (sec_r000276_13_2 <= 255));
  __CPROVER_assume((sec_r000276_14_1 >= 0) && (sec_r000276_14_1 <= 255));
  __CPROVER_assume((sec_r000276_14_2 >= 0) && (sec_r000276_14_2 <= 255));
  __CPROVER_assume((sec_r000276_15_1 >= 0) && (sec_r000276_15_1 <= 255));
  __CPROVER_assume((sec_r000276_15_2 >= 0) && (sec_r000276_15_2 <= 255));
  __CPROVER_assume((sec_r000276_16_1 >= 0) && (sec_r000276_16_1 <= 255));
  __CPROVER_assume((sec_r000276_16_2 >= 0) && (sec_r000276_16_2 <= 255));
  struct DeviceConfig_R000276_7613_0 st_var_0_1 = {0};
  struct DeviceConfig_R000276_7613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000276_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000276_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000276_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000276_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000276_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000276_0_2 + 7) & 15;
  struct Vector3D_R000276_7613_1 st_var_1_1 = {0};
  struct Vector3D_R000276_7613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000276_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000276_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000276_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000276_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000276_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000276_0_2 + 9) & 15;
  struct FilterState_R000276_7613_2 st_var_2_1 = {0};
  struct FilterState_R000276_7613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000276_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000276_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000276_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000276_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000276_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000276_0_2 + 11) & 15;
  union TelemetryField_R000276_7613_0 u_var_1;
  union TelemetryField_R000276_7613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (5 & 31);
  int stage_v_0_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (5 & 31);
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= (stage_v_0_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_0_2 << 1) & 127;
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (st_var_0_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_0_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 6) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 7) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 10) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 12) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 16) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = table_1[0];
  int stage_v_16_2 = table_2[0];
  table_1[0] = (table_1[1] + 33) & 63;
  table_2[0] = (table_2[1] + 33) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
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
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (st_var_0_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_0_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
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
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 30) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 30) & 15;
  int stage_v_29_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_29_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= stage_v_29_1;
  chk_sum_2 ^= stage_v_29_2;
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (st_var_1_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_1_2.buffer[0] ^ 34) & 3;
  switch (stage_v_31_1)
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

  switch (stage_v_31_2)
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

  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_33_1 = ((stage_v_33_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_33_2 = ((stage_v_33_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
  int stage_v_36_1 = table_1[0];
  int stage_v_36_2 = table_2[0];
  table_1[0] = (table_1[1] + 73) & 63;
  table_2[0] = (table_2[1] + 73) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 42)
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
  if (stage_v_37_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 42)
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
  int stage_v_38_1 = table_1[2];
  int stage_v_38_2 = table_2[2];
  table_1[2] = (table_1[3] + 77) & 63;
  table_2[2] = (table_2[3] + 77) & 63;
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
  int stage_v_40_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_40_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_40_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_40_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 42) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 42) & 15;
  int stage_v_41_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_41_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= stage_v_41_1;
  chk_sum_2 ^= stage_v_41_2;
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
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = table_1[0];
  int stage_v_44_2 = table_2[0];
  table_1[0] = (table_1[1] + 89) & 63;
  table_2[0] = (table_2[1] + 89) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 46) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = ((st_var_1_1.buffer[1] * 2) + 145) & 63;
  int stage_v_46_2 = ((st_var_1_2.buffer[1] * 2) + 145) & 63;
  if (stage_v_46_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_46_1) - 5) & 255;
    if (stage_v_46_1 > 39)
    {
      chk_sum_1 ^= stage_v_46_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_46_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_46_2) - 5) & 255;
    if (stage_v_46_2 > 39)
    {
      chk_sum_2 ^= stage_v_46_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_47_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (52 & 31);
  int stage_v_47_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (52 & 31);
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= (stage_v_47_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_47_2 << 1) & 127;
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
  if (stage_v_49_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 46)
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
  if (stage_v_49_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 46)
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
  int stage_v_52_1 = (st_var_1_1.buffer[0] ^ 55) & 3;
  int stage_v_52_2 = (st_var_1_2.buffer[0] ^ 55) & 3;
  switch (stage_v_52_1)
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

  switch (stage_v_52_2)
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

  int stage_v_53_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_53_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_56_1 = ((st_var_2_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_2_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 43)
    {
      chk_sum_1 ^= stage_v_56_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_56_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 43)
    {
      chk_sum_2 ^= stage_v_56_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 58) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= stage_v_57_1;
  chk_sum_2 ^= stage_v_57_2;
  int stage_v_58_1 = table_1[2];
  int stage_v_58_2 = table_2[2];
  table_1[2] = (table_1[3] + 117) & 63;
  table_2[2] = (table_2[3] + 117) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = table_1[3];
  int stage_v_59_2 = table_2[3];
  table_1[3] = (table_1[0] + 119) & 63;
  table_2[3] = (table_2[0] + 119) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_60_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_62_1 = ((stage_v_62_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_62_2 = ((stage_v_62_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_63_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 65) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 65) & 15;
  int stage_v_64_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_64_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= stage_v_64_1;
  chk_sum_2 ^= stage_v_64_2;
  int stage_v_65_1 = ((st_var_2_1.buffer[2] * 2) + 202) & 63;
  int stage_v_65_2 = ((st_var_2_2.buffer[2] * 2) + 202) & 63;
  if (stage_v_65_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_65_1) - 5) & 255;
    if (stage_v_65_1 > 35)
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
  if (stage_v_65_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_65_2) - 5) & 255;
    if (stage_v_65_2 > 35)
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
  int stage_v_68_1 = ((st_var_2_1.buffer[2] * 2) + 211) & 63;
  int stage_v_68_2 = ((st_var_2_2.buffer[2] * 2) + 211) & 63;
  if (stage_v_68_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_68_1) - 5) & 255;
    if (stage_v_68_1 > 47)
    {
      chk_sum_1 ^= stage_v_68_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_68_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_68_2) - 5) & 255;
    if (stage_v_68_2 > 47)
    {
      chk_sum_2 ^= stage_v_68_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_69_1 = table_1[1];
  int stage_v_69_2 = table_2[1];
  table_1[1] = (table_1[2] + 139) & 63;
  table_2[1] = (table_2[2] + 139) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 71) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 71) & 15;
  int stage_v_70_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_70_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= stage_v_70_1;
  chk_sum_2 ^= stage_v_70_2;
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
  int stage_v_72_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_72_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 74) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 74) & 15;
  int stage_v_73_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_73_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= stage_v_73_1;
  chk_sum_2 ^= stage_v_73_2;
  int stage_v_74_1 = (st_var_2_1.buffer[0] ^ 77) & 3;
  int stage_v_74_2 = (st_var_2_2.buffer[0] ^ 77) & 3;
  switch (stage_v_74_1)
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

  switch (stage_v_74_2)
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
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_76_1 = ((stage_v_76_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_76_2 = ((stage_v_76_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 78) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 78) & 15;
  int stage_v_77_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_77_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= stage_v_77_1;
  chk_sum_2 ^= stage_v_77_2;
  int stage_v_78_1 = table_1[2];
  int stage_v_78_2 = table_2[2];
  table_1[2] = (table_1[3] + 157) & 63;
  table_2[2] = (table_2[3] + 157) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
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
  if (stage_v_80_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_80_1) - 5) & 255;
    if (stage_v_80_1 > 34)
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
  if (stage_v_80_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_80_2) - 5) & 255;
    if (stage_v_80_2 > 34)
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
  int stage_v_84_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_84_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_87_1 = ((stage_v_87_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (93 & 31);
  int stage_v_88_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (93 & 31);
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= (stage_v_88_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_88_2 << 1) & 127;
  int stage_v_89_1 = table_1[1];
  int stage_v_89_2 = table_2[1];
  table_1[1] = (table_1[2] + 179) & 63;
  table_2[1] = (table_2[2] + 179) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_90_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_90_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_90_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_91_1 = ((stage_v_91_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_91_2 = ((stage_v_91_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 93) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 93) & 15;
  int stage_v_92_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_92_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  chk_sum_1 ^= stage_v_92_1;
  chk_sum_2 ^= stage_v_92_2;
  int stage_v_93_1 = table_1[1];
  int stage_v_93_2 = table_2[1];
  table_1[1] = (table_1[2] + 187) & 63;
  table_2[1] = (table_2[2] + 187) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (st_var_1_1.buffer[0] ^ 97) & 3;
  int stage_v_94_2 = (st_var_1_2.buffer[0] ^ 97) & 3;
  switch (stage_v_94_1)
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

  switch (stage_v_94_2)
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

  int stage_v_95_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (100 & 31);
  int stage_v_95_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (100 & 31);
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  chk_sum_1 ^= (stage_v_95_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_95_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 97) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 97) & 15;
  int stage_v_96_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_96_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  chk_sum_1 ^= stage_v_96_1;
  chk_sum_2 ^= stage_v_96_2;
  int stage_v_97_1 = table_1[1];
  int stage_v_97_2 = table_2[1];
  table_1[1] = (table_1[2] + 195) & 63;
  table_2[1] = (table_2[2] + 195) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((st_var_2_1.buffer[2] * 2) + 301) & 63;
  int stage_v_98_2 = ((st_var_2_2.buffer[2] * 2) + 301) & 63;
  if (stage_v_98_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_98_1) - 5) & 255;
    if (stage_v_98_1 > 35)
    {
      chk_sum_1 ^= stage_v_98_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_98_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_98_2) - 5) & 255;
    if (stage_v_98_2 > 35)
    {
      chk_sum_2 ^= stage_v_98_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_99_1 = (st_var_0_1.buffer[0] ^ 102) & 3;
  int stage_v_99_2 = (st_var_0_2.buffer[0] ^ 102) & 3;
  switch (stage_v_99_1)
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

  switch (stage_v_99_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 101) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 101) & 15;
  int stage_v_100_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_100_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= stage_v_100_1;
  chk_sum_2 ^= stage_v_100_2;
  int stage_v_101_1 = table_1[1];
  int stage_v_101_2 = table_2[1];
  table_1[1] = (table_1[2] + 203) & 63;
  table_2[1] = (table_2[2] + 203) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((st_var_0_1.buffer[0] * 2) + 313) & 63;
  int stage_v_102_2 = ((st_var_0_2.buffer[0] * 2) + 313) & 63;
  if (stage_v_102_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_102_1) - 5) & 255;
    if (stage_v_102_1 > 39)
    {
      chk_sum_1 ^= stage_v_102_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_102_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_102_2) - 5) & 255;
    if (stage_v_102_2 > 39)
    {
      chk_sum_2 ^= stage_v_102_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_103_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_103_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_103_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_103_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_104_1 = ((st_var_2_1.buffer[2] * 2) + 319) & 63;
  int stage_v_104_2 = ((st_var_2_2.buffer[2] * 2) + 319) & 63;
  if (stage_v_104_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_104_1) - 5) & 255;
    if (stage_v_104_1 > 36)
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
  if (stage_v_104_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_104_2) - 5) & 255;
    if (stage_v_104_2 > 36)
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
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_105_1 = ((stage_v_105_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_105_2 = ((stage_v_105_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_106_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_106_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_106_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_107_1 = ((st_var_2_1.buffer[2] * 2) + 328) & 63;
  int stage_v_107_2 = ((st_var_2_2.buffer[2] * 2) + 328) & 63;
  if (stage_v_107_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_107_1) - 5) & 255;
    if (stage_v_107_1 > 51)
    {
      chk_sum_1 ^= stage_v_107_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_107_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_107_2) - 5) & 255;
    if (stage_v_107_2 > 51)
    {
      chk_sum_2 ^= stage_v_107_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_108_1 = table_1[0];
  int stage_v_108_2 = table_2[0];
  table_1[0] = (table_1[1] + 217) & 63;
  table_2[0] = (table_2[1] + 217) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_109_1 = ((stage_v_109_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_109_2 = ((stage_v_109_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (115 & 31);
  int stage_v_110_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (115 & 31);
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  chk_sum_1 ^= (stage_v_110_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_110_2 << 1) & 127;
  int stage_v_111_1 = (st_var_0_1.buffer[0] ^ 114) & 3;
  int stage_v_111_2 = (st_var_0_2.buffer[0] ^ 114) & 3;
  switch (stage_v_111_1)
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

  switch (stage_v_111_2)
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

  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_112_1 = ((stage_v_112_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_112_2 = ((stage_v_112_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_113_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_113_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_113_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_114_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_114_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_114_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_114_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_115_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (120 & 31);
  int stage_v_115_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (120 & 31);
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  chk_sum_1 ^= (stage_v_115_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_115_2 << 1) & 127;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_116_1 = ((stage_v_116_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_116_2 = ((stage_v_116_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((st_var_0_1.buffer[0] * 2) + 358) & 63;
  int stage_v_117_2 = ((st_var_0_2.buffer[0] * 2) + 358) & 63;
  if (stage_v_117_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_117_1) - 5) & 255;
    if (stage_v_117_1 > 53)
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
  if (stage_v_117_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_117_2) - 5) & 255;
    if (stage_v_117_2 > 53)
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

  switch (stage_v_118_2)
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
  int stage_v_120_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_120_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_120_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_120_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 122) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 122) & 15;
  int stage_v_121_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_121_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  chk_sum_1 ^= stage_v_121_1;
  chk_sum_2 ^= stage_v_121_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 123) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 123) & 15;
  int stage_v_122_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_122_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  chk_sum_1 ^= stage_v_122_1;
  chk_sum_2 ^= stage_v_122_2;
  int stage_v_123_1 = table_1[3];
  int stage_v_123_2 = table_2[3];
  table_1[3] = (table_1[0] + 247) & 63;
  table_2[3] = (table_2[0] + 247) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = table_1[0];
  int stage_v_124_2 = table_2[0];
  table_1[0] = (table_1[1] + 249) & 63;
  table_2[0] = (table_2[1] + 249) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = (st_var_2_1.buffer[0] ^ 128) & 3;
  int stage_v_125_2 = (st_var_2_2.buffer[0] ^ 128) & 3;
  switch (stage_v_125_1)
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

  switch (stage_v_125_2)
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

  int stage_v_126_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_126_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_126_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_126_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_127_1 = ((st_var_1_1.buffer[1] * 2) + 388) & 63;
  int stage_v_127_2 = ((st_var_1_2.buffer[1] * 2) + 388) & 63;
  if (stage_v_127_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_127_1) - 5) & 255;
    if (stage_v_127_1 > 44)
    {
      chk_sum_1 ^= stage_v_127_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_127_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_127_2) - 5) & 255;
    if (stage_v_127_2 > 44)
    {
      chk_sum_2 ^= stage_v_127_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 129) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 129) & 15;
  int stage_v_128_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_128_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  chk_sum_1 ^= stage_v_128_1;
  chk_sum_2 ^= stage_v_128_2;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_129_1 = ((stage_v_129_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_129_2 = ((stage_v_129_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = table_1[2];
  int stage_v_130_2 = table_2[2];
  table_1[2] = (table_1[3] + 261) & 63;
  table_2[2] = (table_2[3] + 261) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_131_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_131_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_131_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  int stage_v_134_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (139 & 31);
  int stage_v_134_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (139 & 31);
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  chk_sum_1 ^= (stage_v_134_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_134_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 136) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 136) & 15;
  int stage_v_135_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_135_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  chk_sum_1 ^= stage_v_135_1;
  chk_sum_2 ^= stage_v_135_2;
  int stage_v_136_1 = ((st_var_1_1.buffer[1] * 2) + 415) & 63;
  int stage_v_136_2 = ((st_var_1_2.buffer[1] * 2) + 415) & 63;
  if (stage_v_136_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_136_1) - 5) & 255;
    if (stage_v_136_1 > 51)
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
  if (stage_v_136_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_136_2) - 5) & 255;
    if (stage_v_136_2 > 51)
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
  int stage_v_137_1 = table_1[1];
  int stage_v_137_2 = table_2[1];
  table_1[1] = (table_1[2] + 275) & 63;
  table_2[1] = (table_2[2] + 275) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_138_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_138_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_138_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_139_1 = (st_var_1_1.buffer[0] ^ 142) & 3;
  int stage_v_139_2 = (st_var_1_2.buffer[0] ^ 142) & 3;
  switch (stage_v_139_1)
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

  switch (stage_v_139_2)
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

  int stage_v_140_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_140_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_140_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_140_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_141_1 = ((st_var_0_1.buffer[0] * 2) + 430) & 63;
  int stage_v_141_2 = ((st_var_0_2.buffer[0] * 2) + 430) & 63;
  if (stage_v_141_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_141_1) - 5) & 255;
    if (stage_v_141_1 > 31)
    {
      chk_sum_1 ^= stage_v_141_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_141_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_141_2) - 5) & 255;
    if (stage_v_141_2 > 31)
    {
      chk_sum_2 ^= stage_v_141_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_142_1 = table_1[2];
  int stage_v_142_2 = table_2[2];
  table_1[2] = (table_1[3] + 285) & 63;
  table_2[2] = (table_2[3] + 285) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (st_var_2_1.buffer[0] ^ 146) & 3;
  int stage_v_143_2 = (st_var_2_2.buffer[0] ^ 146) & 3;
  switch (stage_v_143_1)
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

  switch (stage_v_143_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 145) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 145) & 15;
  int stage_v_144_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_144_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  chk_sum_1 ^= stage_v_144_1;
  chk_sum_2 ^= stage_v_144_2;
  int stage_v_145_1 = (st_var_1_1.buffer[0] ^ 148) & 3;
  int stage_v_145_2 = (st_var_1_2.buffer[0] ^ 148) & 3;
  switch (stage_v_145_1)
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

  switch (stage_v_145_2)
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

  int stage_v_146_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_146_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_146_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_146_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_147_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (152 & 31);
  int stage_v_147_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (152 & 31);
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  chk_sum_1 ^= (stage_v_147_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_147_2 << 1) & 127;
  int stage_v_148_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (153 & 31);
  int stage_v_148_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (153 & 31);
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  chk_sum_1 ^= (stage_v_148_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_148_2 << 1) & 127;
  int stage_v_149_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_149_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_149_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_149_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_150_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (155 & 31);
  int stage_v_150_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (155 & 31);
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  chk_sum_1 ^= (stage_v_150_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_150_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 152) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 152) & 15;
  int stage_v_151_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_151_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  chk_sum_1 ^= stage_v_151_1;
  chk_sum_2 ^= stage_v_151_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 153) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 153) & 15;
  int stage_v_152_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_152_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  chk_sum_1 ^= stage_v_152_1;
  chk_sum_2 ^= stage_v_152_2;
  int stage_v_153_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (158 & 31);
  int stage_v_153_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (158 & 31);
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  chk_sum_1 ^= (stage_v_153_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_153_2 << 1) & 127;
  int stage_v_154_1 = (st_var_1_1.buffer[0] ^ 157) & 3;
  int stage_v_154_2 = (st_var_1_2.buffer[0] ^ 157) & 3;
  switch (stage_v_154_1)
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

  switch (stage_v_154_2)
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

  int stage_v_155_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (160 & 31);
  int stage_v_155_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (160 & 31);
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  chk_sum_1 ^= (stage_v_155_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_155_2 << 1) & 127;
  int stage_v_156_1 = table_1[0];
  int stage_v_156_2 = table_2[0];
  table_1[0] = (table_1[1] + 313) & 63;
  table_2[0] = (table_2[1] + 313) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (st_var_1_1.buffer[0] ^ 160) & 3;
  int stage_v_157_2 = (st_var_1_2.buffer[0] ^ 160) & 3;
  switch (stage_v_157_1)
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

  switch (stage_v_157_2)
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

  int stage_v_158_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (163 & 31);
  int stage_v_158_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (163 & 31);
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  chk_sum_1 ^= (stage_v_158_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_158_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 160) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 160) & 15;
  int stage_v_159_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_159_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  chk_sum_1 ^= stage_v_159_1;
  chk_sum_2 ^= stage_v_159_2;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_160_1 = ((stage_v_160_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_160_2 = ((stage_v_160_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 162) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 162) & 15;
  int stage_v_161_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_161_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  chk_sum_1 ^= stage_v_161_1;
  chk_sum_2 ^= stage_v_161_2;
  int stage_v_162_1 = table_1[2];
  int stage_v_162_2 = table_2[2];
  table_1[2] = (table_1[3] + 325) & 63;
  table_2[2] = (table_2[3] + 325) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_163_1 = ((stage_v_163_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_163_2 = ((stage_v_163_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 165) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 165) & 15;
  int stage_v_164_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_164_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  chk_sum_1 ^= stage_v_164_1;
  chk_sum_2 ^= stage_v_164_2;
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
  int stage_v_167_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (172 & 31);
  int stage_v_167_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (172 & 31);
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  chk_sum_1 ^= (stage_v_167_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_167_2 << 1) & 127;
  int stage_v_168_1 = ((st_var_0_1.buffer[0] * 2) + 511) & 63;
  int stage_v_168_2 = ((st_var_0_2.buffer[0] * 2) + 511) & 63;
  if (stage_v_168_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_168_1) - 5) & 255;
    if (stage_v_168_1 > 41)
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
  if (stage_v_168_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_168_2) - 5) & 255;
    if (stage_v_168_2 > 41)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 170) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 170) & 15;
  int stage_v_169_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_169_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  chk_sum_1 ^= stage_v_169_1;
  chk_sum_2 ^= stage_v_169_2;
  int stage_v_170_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_170_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_170_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_170_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_171_1 = table_1[3];
  int stage_v_171_2 = table_2[3];
  table_1[3] = (table_1[0] + 343) & 63;
  table_2[3] = (table_2[0] + 343) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (177 & 31);
  int stage_v_172_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (177 & 31);
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  chk_sum_1 ^= (stage_v_172_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_172_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 174) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 174) & 15;
  int stage_v_173_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_173_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  chk_sum_1 ^= stage_v_173_1;
  chk_sum_2 ^= stage_v_173_2;
  int stage_v_174_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (179 & 31);
  int stage_v_174_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (179 & 31);
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  chk_sum_1 ^= (stage_v_174_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_174_2 << 1) & 127;
  int stage_v_175_1 = ((st_var_1_1.buffer[1] * 2) + 532) & 63;
  int stage_v_175_2 = ((st_var_1_2.buffer[1] * 2) + 532) & 63;
  if (stage_v_175_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_175_1) - 5) & 255;
    if (stage_v_175_1 > 53)
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
  if (stage_v_175_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_175_2) - 5) & 255;
    if (stage_v_175_2 > 53)
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
  int stage_v_176_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (181 & 31);
  int stage_v_176_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (181 & 31);
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  chk_sum_1 ^= (stage_v_176_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_176_2 << 1) & 127;
  int stage_v_177_1 = (st_var_0_1.buffer[0] ^ 180) & 3;
  int stage_v_177_2 = (st_var_0_2.buffer[0] ^ 180) & 3;
  switch (stage_v_177_1)
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

  switch (stage_v_177_2)
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

  int stage_v_178_1 = (st_var_1_1.buffer[0] ^ 181) & 3;
  int stage_v_178_2 = (st_var_1_2.buffer[0] ^ 181) & 3;
  switch (stage_v_178_1)
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

  switch (stage_v_178_2)
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

  int stage_v_179_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_179_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_179_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_179_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_180_1 = table_1[0];
  int stage_v_180_2 = table_2[0];
  table_1[0] = (table_1[1] + 361) & 63;
  table_2[0] = (table_2[1] + 361) & 63;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_181_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_181_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_181_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_182_1 = table_1[2];
  int stage_v_182_2 = table_2[2];
  table_1[2] = (table_1[3] + 365) & 63;
  table_2[2] = (table_2[3] + 365) & 63;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (188 & 31);
  int stage_v_183_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (188 & 31);
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  chk_sum_1 ^= (stage_v_183_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_183_2 << 1) & 127;
  int stage_v_184_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (189 & 31);
  int stage_v_184_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (189 & 31);
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  chk_sum_1 ^= (stage_v_184_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_184_2 << 1) & 127;
  int stage_v_185_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (190 & 31);
  int stage_v_185_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (190 & 31);
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  chk_sum_1 ^= (stage_v_185_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_185_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 187) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 187) & 15;
  int stage_v_186_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_186_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  chk_sum_1 ^= stage_v_186_1;
  chk_sum_2 ^= stage_v_186_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 188) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 188) & 15;
  int stage_v_187_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_187_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  chk_sum_1 ^= stage_v_187_1;
  chk_sum_2 ^= stage_v_187_2;
  int stage_v_188_1 = 0;
  int stage_v_188_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_188_1 = ((stage_v_188_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_188_2 = ((stage_v_188_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 190) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 190) & 15;
  int stage_v_189_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_189_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  chk_sum_1 ^= stage_v_189_1;
  chk_sum_2 ^= stage_v_189_2;
  int stage_v_190_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_190_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_190_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_190_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_191_1 = (st_var_2_1.buffer[0] ^ 194) & 3;
  int stage_v_191_2 = (st_var_2_2.buffer[0] ^ 194) & 3;
  switch (stage_v_191_1)
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

  switch (stage_v_191_2)
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

  int stage_v_192_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (197 & 31);
  int stage_v_192_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (197 & 31);
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  chk_sum_1 ^= (stage_v_192_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_192_2 << 1) & 127;
  int stage_v_193_1 = (st_var_1_1.buffer[0] ^ 196) & 3;
  int stage_v_193_2 = (st_var_1_2.buffer[0] ^ 196) & 3;
  switch (stage_v_193_1)
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

  switch (stage_v_193_2)
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

  int stage_v_194_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (199 & 31);
  int stage_v_194_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (199 & 31);
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  chk_sum_1 ^= (stage_v_194_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_194_2 << 1) & 127;
  int stage_v_195_1 = (st_var_0_1.buffer[0] ^ 198) & 3;
  int stage_v_195_2 = (st_var_0_2.buffer[0] ^ 198) & 3;
  switch (stage_v_195_1)
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

  switch (stage_v_195_2)
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

  int stage_v_196_1 = ((st_var_1_1.buffer[1] * 2) + 595) & 63;
  int stage_v_196_2 = ((st_var_1_2.buffer[1] * 2) + 595) & 63;
  if (stage_v_196_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_196_1) - 5) & 255;
    if (stage_v_196_1 > 36)
    {
      chk_sum_1 ^= stage_v_196_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_196_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_196_2) - 5) & 255;
    if (stage_v_196_2 > 36)
    {
      chk_sum_2 ^= stage_v_196_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_197_1 = (st_var_2_1.buffer[0] ^ 200) & 3;
  int stage_v_197_2 = (st_var_2_2.buffer[0] ^ 200) & 3;
  switch (stage_v_197_1)
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

  switch (stage_v_197_2)
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

  int stage_v_198_1 = 0;
  int stage_v_198_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_198_1 = ((stage_v_198_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_198_2 = ((stage_v_198_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (204 & 31);
  int stage_v_199_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (204 & 31);
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  chk_sum_1 ^= (stage_v_199_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_199_2 << 1) & 127;
  int stage_v_200_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (205 & 31);
  int stage_v_200_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (205 & 31);
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  chk_sum_1 ^= (stage_v_200_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_200_2 << 1) & 127;
  int stage_v_201_1 = ((st_var_0_1.buffer[0] * 2) + 610) & 63;
  int stage_v_201_2 = ((st_var_0_2.buffer[0] * 2) + 610) & 63;
  if (stage_v_201_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_201_1) - 5) & 255;
    if (stage_v_201_1 > 27)
    {
      chk_sum_1 ^= stage_v_201_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_201_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_201_2) - 5) & 255;
    if (stage_v_201_2 > 27)
    {
      chk_sum_2 ^= stage_v_201_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_202_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_202_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_202_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_202_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_203_1 = 0;
  int stage_v_203_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_203_1 = ((stage_v_203_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_203_2 = ((stage_v_203_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((st_var_0_1.buffer[0] * 2) + 619) & 63;
  int stage_v_204_2 = ((st_var_0_2.buffer[0] * 2) + 619) & 63;
  if (stage_v_204_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_204_1) - 5) & 255;
    if (stage_v_204_1 > 39)
    {
      chk_sum_1 ^= stage_v_204_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_204_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_204_2) - 5) & 255;
    if (stage_v_204_2 > 39)
    {
      chk_sum_2 ^= stage_v_204_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_205_1 = ((st_var_1_1.buffer[1] * 2) + 622) & 63;
  int stage_v_205_2 = ((st_var_1_2.buffer[1] * 2) + 622) & 63;
  if (stage_v_205_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_205_1) - 5) & 255;
    if (stage_v_205_1 > 32)
    {
      chk_sum_1 ^= stage_v_205_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_205_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_205_2) - 5) & 255;
    if (stage_v_205_2 > 32)
    {
      chk_sum_2 ^= stage_v_205_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_206_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (211 & 31);
  int stage_v_206_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (211 & 31);
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  chk_sum_1 ^= (stage_v_206_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_206_2 << 1) & 127;
  int stage_v_207_1 = (st_var_0_1.buffer[0] ^ 210) & 3;
  int stage_v_207_2 = (st_var_0_2.buffer[0] ^ 210) & 3;
  switch (stage_v_207_1)
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

  switch (stage_v_207_2)
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

  int stage_v_208_1 = ((st_var_1_1.buffer[1] * 2) + 631) & 63;
  int stage_v_208_2 = ((st_var_1_2.buffer[1] * 2) + 631) & 63;
  if (stage_v_208_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_208_1) - 5) & 255;
    if (stage_v_208_1 > 39)
    {
      chk_sum_1 ^= stage_v_208_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_208_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_208_2) - 5) & 255;
    if (stage_v_208_2 > 39)
    {
      chk_sum_2 ^= stage_v_208_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_209_1 = (st_var_2_1.buffer[0] ^ 212) & 3;
  int stage_v_209_2 = (st_var_2_2.buffer[0] ^ 212) & 3;
  switch (stage_v_209_1)
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

  switch (stage_v_209_2)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 213) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 213) & 15;
  int stage_v_212_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_212_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  chk_sum_1 ^= stage_v_212_1;
  chk_sum_2 ^= stage_v_212_2;
  int stage_v_213_1 = ((st_var_0_1.buffer[0] * 2) + 646) & 63;
  int stage_v_213_2 = ((st_var_0_2.buffer[0] * 2) + 646) & 63;
  if (stage_v_213_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_213_1) - 5) & 255;
    if (stage_v_213_1 > 48)
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
  if (stage_v_213_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_213_2) - 5) & 255;
    if (stage_v_213_2 > 48)
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
  int stage_v_214_1 = table_1[2];
  int stage_v_214_2 = table_2[2];
  table_1[2] = (table_1[3] + 429) & 63;
  table_2[2] = (table_2[3] + 429) & 63;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_215_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_215_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_215_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_216_1 = ((st_var_0_1.buffer[0] * 2) + 655) & 63;
  int stage_v_216_2 = ((st_var_0_2.buffer[0] * 2) + 655) & 63;
  if (stage_v_216_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_216_1) - 5) & 255;
    if (stage_v_216_1 > 32)
    {
      chk_sum_1 ^= stage_v_216_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_216_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_216_2) - 5) & 255;
    if (stage_v_216_2 > 32)
    {
      chk_sum_2 ^= stage_v_216_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_217_1 = ((st_var_1_1.buffer[1] * 2) + 658) & 63;
  int stage_v_217_2 = ((st_var_1_2.buffer[1] * 2) + 658) & 63;
  if (stage_v_217_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_217_1) - 5) & 255;
    if (stage_v_217_1 > 32)
    {
      chk_sum_1 ^= stage_v_217_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_217_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_217_2) - 5) & 255;
    if (stage_v_217_2 > 32)
    {
      chk_sum_2 ^= stage_v_217_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int m_step_0_1 = ((sec_r000276_14_1 + pub_r000276_0_1) + 8) & 127;
  int m_step_0_2 = ((sec_r000276_14_2 + pub_r000276_0_2) + 8) & 127;
  int m_step_1_1 = ((m_step_0_1 + pub_r000276_6_1) + 11) & 127;
  int m_step_1_2 = ((m_step_0_2 + pub_r000276_6_2) + 11) & 127;
  int m_step_2_1 = ((m_step_1_1 + pub_r000276_8_1) + 20) & 127;
  int m_step_2_2 = ((m_step_1_2 + pub_r000276_8_2) + 20) & 127;
  int m_step_3_1 = ((m_step_2_1 + pub_r000276_12_1) + 27) & 127;
  int m_step_3_2 = ((m_step_2_2 + pub_r000276_12_2) + 27) & 127;
  int m_step_4_1 = ((m_step_3_1 + pub_r000276_0_1) + 18) & 127;
  int m_step_4_2 = ((m_step_3_2 + pub_r000276_0_2) + 18) & 127;
  int m_step_5_1 = ((m_step_4_1 + pub_r000276_6_1) + 28) & 127;
  int m_step_5_2 = ((m_step_4_2 + pub_r000276_6_2) + 28) & 127;
  out_sink_1 = (out_sink_1 + m_step_5_1) & 255;
  out_sink_2 = (out_sink_2 + m_step_5_2) & 255;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000276_5_1 == pub_r000276_5_2);
  __CPROVER_assume(sec_r000276_12_1 != sec_r000276_12_2);
  __CPROVER_assume(sec_r000276_3_1 != sec_r000276_3_2);
  __CPROVER_assume(sec_r000276_16_1 != sec_r000276_16_2);
  __CPROVER_assume(sec_r000276_1_1 != sec_r000276_1_2);
  __CPROVER_assume(pub_r000276_15_1 == pub_r000276_15_2);
  __CPROVER_assume(pub_r000276_4_1 == pub_r000276_4_2);
  __CPROVER_assume(pub_r000276_2_1 == pub_r000276_2_2);
  __CPROVER_assume(pub_r000276_1_1 == pub_r000276_1_2);
  __CPROVER_assume(pub_r000276_11_1 == pub_r000276_11_2);
  __CPROVER_assume(pub_r000276_7_1 == pub_r000276_7_2);
  __CPROVER_assume(pub_r000276_6_1 == pub_r000276_6_2);
  __CPROVER_assume(sec_r000276_15_1 != sec_r000276_15_2);
  __CPROVER_assume(pub_r000276_9_1 == pub_r000276_9_2);
  __CPROVER_assume(pub_r000276_3_1 == pub_r000276_3_2);
  __CPROVER_assume(sec_r000276_10_1 != sec_r000276_10_2);
  __CPROVER_assume(pub_r000276_14_1 == pub_r000276_14_2);
  __CPROVER_assume(pub_r000276_10_1 == pub_r000276_10_2);
  __CPROVER_assume(sec_r000276_13_1 != sec_r000276_13_2);
  __CPROVER_assume(sec_r000276_7_1 != sec_r000276_7_2);
  __CPROVER_assume(sec_r000276_0_1 != sec_r000276_0_2);
  __CPROVER_assume(pub_r000276_13_1 == pub_r000276_13_2);
  __CPROVER_assume(sec_r000276_2_1 != sec_r000276_2_2);
  __CPROVER_assume(sec_r000276_8_1 != sec_r000276_8_2);
  __CPROVER_assume(sec_r000276_4_1 != sec_r000276_4_2);
  __CPROVER_assume(pub_r000276_0_1 == pub_r000276_0_2);
  __CPROVER_assume(pub_r000276_8_1 == pub_r000276_8_2);
  __CPROVER_assume(sec_r000276_6_1 != sec_r000276_6_2);
  __CPROVER_assume(sec_r000276_11_1 != sec_r000276_11_2);
  __CPROVER_assume(sec_r000276_5_1 != sec_r000276_5_2);
  __CPROVER_assume(pub_r000276_12_1 == pub_r000276_12_2);
  __CPROVER_assume(pub_r000276_16_1 == pub_r000276_16_2);
  __CPROVER_assume(pub_r000276_17_1 == pub_r000276_17_2);
  __CPROVER_assume(pub_r000276_18_1 == pub_r000276_18_2);
  __CPROVER_assume(sec_r000276_9_1 != sec_r000276_9_2);
  __CPROVER_assume(sec_r000276_14_1 != sec_r000276_14_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.prev_in == st_var_2_2.prev_in);
  assert(st_var_2_1.cutoff == st_var_2_2.cutoff);
  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
  assert(st_var_2_1.mode == st_var_2_2.mode);
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
  assert(m_step_0_1 == m_step_0_2);
  assert(m_step_1_1 == m_step_1_2);
  assert(m_step_2_1 == m_step_2_2);
  assert(m_step_3_1 == m_step_3_2);
  assert(m_step_4_1 == m_step_4_2);
  assert(m_step_5_1 == m_step_5_2);
}


