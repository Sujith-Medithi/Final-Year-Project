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
struct Vector3D_R000882_8213_0
{
  int coord_x;
  unsigned char pitch;
  int norm_sq;
  unsigned char coord_y;
  int coord_z;
  int heading;
  int buffer[3];
};
struct Transaction_R000882_8213_1
{
  unsigned char rate;
  int account_id;
  int fee;
  int status;
  int buffer[3];
};
union PacketPayload_R000882_8213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000882_8213_1
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
void fn_R000882_8213_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st_1 = {0};
  struct Transaction_R000882_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_60_1 > 30)
  {
    acc_1 = ((acc_1 + (index_reg_60_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_60_2 > 30)
  {
    acc_2 = ((acc_2 + (index_reg_60_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_65_1 = local_arr_1[aux_1 % 3];
  int window_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_65_2 * 2)) & 127;
  int damping_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_91_1)
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

  switch (damping_91_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_60_1 == index_reg_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_65_1 == window_65_2);
  assert(damping_91_1 == damping_91_2);
}

int fn_R000882_8213_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_60 > 30)
  {
    acc = ((acc + (index_reg_60 * 2)) + 5) & 127;
    aux ^= index_reg_60 & 15;
  }
  else
  {
    acc = ((acc - index_reg_60) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_65 = local_arr[aux % 3];
  acc = (acc + (window_65 * 2)) & 127;
  int damping_91 = (aux + st.buffer[1]) & 3;
  switch (damping_91)
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

void fn_R000882_8213_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st_1 = {0};
  struct Vector3D_R000882_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_75_1 = local_arr_1[aux_1 % 3];
  int weight_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_75_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_82_1)
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

  switch (threshold_82_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_75_1 == weight_75_2);
  assert(threshold_82_1 == threshold_82_2);
}

int fn_R000882_8213_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int weight_75 = local_arr[aux % 3];
  acc = (acc + (weight_75 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_82 = (aux + st.buffer[1]) & 3;
  switch (threshold_82)
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

void fn_R000882_8213_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st_1 = {0};
  struct Vector3D_R000882_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int quotient_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_24_1)
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

  switch (quotient_24_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_55_1) & 63;
  aux_2 = (aux_2 + mask_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_24_1 == quotient_24_2);
  assert(mask_55_1 == mask_55_2);
}

int fn_R000882_8213_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int quotient_24 = (aux + st.buffer[1]) & 3;
  switch (quotient_24)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_55) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000882_8213_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st_1 = {0};
  struct Transaction_R000882_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int tracker_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_55_1)
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

  switch (tracker_55_2)
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
  int pivot_23_1 = local_arr_1[aux_1 % 3];
  int pivot_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_23_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_80_1 > 28)
  {
    acc_1 = ((acc_1 + (index_reg_80_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_80_2 > 28)
  {
    acc_2 = ((acc_2 + (index_reg_80_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_80_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_55_1 == tracker_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_23_1 == pivot_23_2);
  assert(index_reg_80_1 == index_reg_80_2);
}

int fn_R000882_8213_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int tracker_55 = (aux + st.buffer[1]) & 3;
  switch (tracker_55)
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
  int pivot_23 = local_arr[aux % 3];
  acc = (acc + (pivot_23 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_80 > 28)
  {
    acc = ((acc + (index_reg_80 * 2)) + 5) & 127;
    aux ^= index_reg_80 & 15;
  }
  else
  {
    acc = ((acc - index_reg_80) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000882_8213_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st_1 = {0};
  struct Vector3D_R000882_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int margin_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_59_1 > 21)
  {
    acc_1 = ((acc_1 + (margin_59_1 * 2)) + 5) & 127;
    aux_1 ^= margin_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_59_2 > 21)
  {
    acc_2 = ((acc_2 + (margin_59_2 * 2)) + 5) & 127;
    aux_2 ^= margin_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_31_1 = local_arr_1[aux_1 % 3];
  int margin_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_31_2 * 2)) & 127;
  int anchor_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_64_1) & 63;
  aux_2 = (aux_2 + anchor_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_59_1 == margin_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_31_1 == margin_31_2);
  assert(anchor_64_1 == anchor_64_2);
}

int fn_R000882_8213_4(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int margin_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_59 > 21)
  {
    acc = ((acc + (margin_59 * 2)) + 5) & 127;
    aux ^= margin_59 & 15;
  }
  else
  {
    acc = ((acc - margin_59) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_31 = local_arr[aux % 3];
  acc = (acc + (margin_31 * 2)) & 127;
  int anchor_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000882_8213_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st_1 = {0};
  struct Transaction_R000882_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_47_1 = local_arr_1[aux_1 % 3];
  int sample_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_47_2 * 2)) & 127;
  int cursor_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_42_1) & 63;
  aux_2 = (aux_2 + cursor_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_69_1)
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

  switch (phase_69_2)
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

  int anchor_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_65_1 > 50)
  {
    acc_1 = ((acc_1 + (anchor_65_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_65_2 > 50)
  {
    acc_2 = ((acc_2 + (anchor_65_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_65_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_47_1 == sample_47_2);
  assert(cursor_42_1 == cursor_42_2);
  assert(phase_69_1 == phase_69_2);
  assert(anchor_65_1 == anchor_65_2);
}

int fn_R000882_8213_5(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int sample_47 = local_arr[aux % 3];
  acc = (acc + (sample_47 * 2)) & 127;
  int cursor_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_42) & 63;
  acc ^= aux;
  int phase_69 = (aux + st.buffer[1]) & 3;
  switch (phase_69)
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

  int anchor_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_65 > 50)
  {
    acc = ((acc + (anchor_65 * 2)) + 5) & 127;
    aux ^= anchor_65 & 15;
  }
  else
  {
    acc = ((acc - anchor_65) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000882_8213_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st_1 = {0};
  struct Transaction_R000882_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int mask_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_42_1) & 63;
  aux_2 = (aux_2 + mask_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_54_1 > 24)
  {
    acc_1 = ((acc_1 + (pivot_54_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_54_2 > 24)
  {
    acc_2 = ((acc_2 + (pivot_54_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_43_1 = local_arr_1[aux_1 % 3];
  int weight_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_43_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_42_1 == mask_42_2);
  assert(pivot_54_1 == pivot_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_43_1 == weight_43_2);
}

int fn_R000882_8213_6(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int mask_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_42) & 63;
  acc ^= aux;
  int pivot_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_54 > 24)
  {
    acc = ((acc + (pivot_54 * 2)) + 5) & 127;
    aux ^= pivot_54 & 15;
  }
  else
  {
    acc = ((acc - pivot_54) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int weight_43 = local_arr[aux % 3];
  acc = (acc + (weight_43 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000882_8213_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st_1 = {0};
  struct Transaction_R000882_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_65_1 = local_arr_1[aux_1 % 3];
  int residue_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_65_2 * 2)) & 127;
  int window_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_62_1 > 16)
  {
    acc_1 = ((acc_1 + (window_62_1 * 2)) + 5) & 127;
    aux_1 ^= window_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_62_2 > 16)
  {
    acc_2 = ((acc_2 + (window_62_2 * 2)) + 5) & 127;
    aux_2 ^= window_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_62_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_65_1 == residue_65_2);
  assert(window_62_1 == window_62_2);
}

int fn_R000882_8213_7(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_65 = local_arr[aux % 3];
  acc = (acc + (residue_65 * 2)) & 127;
  int window_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_62 > 16)
  {
    acc = ((acc + (window_62 * 2)) + 5) & 127;
    aux ^= window_62 & 15;
  }
  else
  {
    acc = ((acc - window_62) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000882_8213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st_1 = {0};
  struct Transaction_R000882_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int threshold_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_50_1 > 14)
  {
    acc_1 = ((acc_1 + (threshold_50_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_50_2 > 14)
  {
    acc_2 = ((acc_2 + (threshold_50_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_62_1) & 63;
  aux_2 = (aux_2 + metric_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_50_1 == threshold_50_2);
  assert(metric_62_1 == metric_62_2);
}

int fn_R000882_8213_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int threshold_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_50 > 14)
  {
    acc = ((acc + (threshold_50 * 2)) + 5) & 127;
    aux ^= threshold_50 & 15;
  }
  else
  {
    acc = ((acc - threshold_50) + 11) & 127;
    aux += 3;
  }
  int metric_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_62) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000882_8213_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st_1 = {0};
  struct Vector3D_R000882_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int checksum_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_39_1 > 50)
  {
    acc_1 = ((acc_1 + (checksum_39_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_39_2 > 50)
  {
    acc_2 = ((acc_2 + (checksum_39_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_34_1)
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

  switch (tracker_34_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_64_1) & 63;
  aux_2 = (aux_2 + phase_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_39_1 == checksum_39_2);
  assert(tracker_34_1 == tracker_34_2);
  assert(phase_64_1 == phase_64_2);
}

int fn_R000882_8213_9(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int checksum_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_39 > 50)
  {
    acc = ((acc + (checksum_39 * 2)) + 5) & 127;
    aux ^= checksum_39 & 15;
  }
  else
  {
    acc = ((acc - checksum_39) + 11) & 127;
    aux += 3;
  }
  int tracker_34 = (aux + st.buffer[1]) & 3;
  switch (tracker_34)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000882_8213_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st_1 = {0};
  struct Transaction_R000882_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_59_1) & 63;
  aux_2 = (aux_2 + pivot_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_93_1 > 10)
  {
    acc_1 = ((acc_1 + (phase_93_1 * 2)) + 5) & 127;
    aux_1 ^= phase_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_93_2 > 10)
  {
    acc_2 = ((acc_2 + (phase_93_2 * 2)) + 5) & 127;
    aux_2 ^= phase_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_71_1)
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

  switch (vector_71_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_59_1 == pivot_59_2);
  assert(phase_93_1 == phase_93_2);
  assert(vector_71_1 == vector_71_2);
}

int fn_R000882_8213_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_59) & 63;
  acc ^= aux;
  int phase_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_93 > 10)
  {
    acc = ((acc + (phase_93 * 2)) + 5) & 127;
    aux ^= phase_93 & 15;
  }
  else
  {
    acc = ((acc - phase_93) + 11) & 127;
    aux += 3;
  }
  int vector_71 = (aux + st.buffer[1]) & 3;
  switch (vector_71)
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

  return (acc + aux) & 255;
}

void fn_R000882_8213_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st_1 = {0};
  struct Vector3D_R000882_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int residue_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_60_1 > 44)
  {
    acc_1 = ((acc_1 + (residue_60_1 * 2)) + 5) & 127;
    aux_1 ^= residue_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_60_2 > 44)
  {
    acc_2 = ((acc_2 + (residue_60_2 * 2)) + 5) & 127;
    aux_2 ^= residue_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_37_1)
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

  switch (cursor_37_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_61_1 = local_arr_1[aux_1 % 3];
  int cursor_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_61_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_60_1 == residue_60_2);
  assert(cursor_37_1 == cursor_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_61_1 == cursor_61_2);
}

int fn_R000882_8213_11(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int residue_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_60 > 44)
  {
    acc = ((acc + (residue_60 * 2)) + 5) & 127;
    aux ^= residue_60 & 15;
  }
  else
  {
    acc = ((acc - residue_60) + 11) & 127;
    aux += 3;
  }
  int cursor_37 = (aux + st.buffer[1]) & 3;
  switch (cursor_37)
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

  int local_arr[3] = {4, 9, 15};
  int cursor_61 = local_arr[aux % 3];
  acc = (acc + (cursor_61 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000882_8213_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st_1 = {0};
  struct Vector3D_R000882_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_27_1 = local_arr_1[aux_1 % 3];
  int factor_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_27_2 * 2)) & 127;
  int tracker_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_24_1 > 39)
  {
    acc_1 = ((acc_1 + (tracker_24_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_24_2 > 39)
  {
    acc_2 = ((acc_2 + (tracker_24_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_71_1) & 63;
  aux_2 = (aux_2 + metric_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_27_1 == factor_27_2);
  assert(tracker_24_1 == tracker_24_2);
  assert(metric_71_1 == metric_71_2);
}

int fn_R000882_8213_12(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int factor_27 = local_arr[aux % 3];
  acc = (acc + (factor_27 * 2)) & 127;
  int tracker_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_24 > 39)
  {
    acc = ((acc + (tracker_24 * 2)) + 5) & 127;
    aux ^= tracker_24 & 15;
  }
  else
  {
    acc = ((acc - tracker_24) + 11) & 127;
    aux += 3;
  }
  int metric_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_71) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000882_8213_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st_1 = {0};
  struct Transaction_R000882_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int pivot_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_38_1) & 63;
  aux_2 = (aux_2 + pivot_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_71_1 > 49)
  {
    acc_1 = ((acc_1 + (cursor_71_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_71_2 > 49)
  {
    acc_2 = ((acc_2 + (cursor_71_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_34_1)
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

  switch (accumulator_34_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_38_1 == pivot_38_2);
  assert(cursor_71_1 == cursor_71_2);
  assert(accumulator_34_1 == accumulator_34_2);
}

int fn_R000882_8213_13(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int pivot_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_38) & 63;
  acc ^= aux;
  int cursor_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_71 > 49)
  {
    acc = ((acc + (cursor_71 * 2)) + 5) & 127;
    aux ^= cursor_71 & 15;
  }
  else
  {
    acc = ((acc - cursor_71) + 11) & 127;
    aux += 3;
  }
  int accumulator_34 = (aux + st.buffer[1]) & 3;
  switch (accumulator_34)
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

void fn_R000882_8213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st_1 = {0};
  struct Transaction_R000882_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int mask_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_70_1) & 63;
  aux_2 = (aux_2 + mask_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_70_1 == mask_70_2);
}

int fn_R000882_8213_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int mask_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_70) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000882_8213_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st_1 = {0};
  struct Vector3D_R000882_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int phase_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_32_1 > 19)
  {
    acc_1 = ((acc_1 + (phase_32_1 * 2)) + 5) & 127;
    aux_1 ^= phase_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_32_2 > 19)
  {
    acc_2 = ((acc_2 + (phase_32_2 * 2)) + 5) & 127;
    aux_2 ^= phase_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_72_1)
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

  switch (weight_72_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_32_1 == phase_32_2);
  assert(weight_72_1 == weight_72_2);
}

int fn_R000882_8213_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int phase_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_32 > 19)
  {
    acc = ((acc + (phase_32 * 2)) + 5) & 127;
    aux ^= phase_32 & 15;
  }
  else
  {
    acc = ((acc - phase_32) + 11) & 127;
    aux += 3;
  }
  int weight_72 = (aux + st.buffer[1]) & 3;
  switch (weight_72)
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

void fn_R000882_8213_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st_1 = {0};
  struct Transaction_R000882_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int anchor_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_65_1)
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

  switch (anchor_65_2)
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

  int threshold_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_98_1 > 39)
  {
    acc_1 = ((acc_1 + (threshold_98_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_98_2 > 39)
  {
    acc_2 = ((acc_2 + (threshold_98_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_65_1 == anchor_65_2);
  assert(threshold_98_1 == threshold_98_2);
}

int fn_R000882_8213_16(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int anchor_65 = (aux + st.buffer[1]) & 3;
  switch (anchor_65)
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

  int threshold_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_98 > 39)
  {
    acc = ((acc + (threshold_98 * 2)) + 5) & 127;
    aux ^= threshold_98 & 15;
  }
  else
  {
    acc = ((acc - threshold_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000882_8213_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st_1 = {0};
  struct Transaction_R000882_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int scale_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_55_1) & 63;
  aux_2 = (aux_2 + scale_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_86_1)
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

  switch (anchor_86_2)
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
  int checksum_63_1 = local_arr_1[aux_1 % 3];
  int checksum_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_63_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_55_1 == scale_55_2);
  assert(anchor_86_1 == anchor_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_63_1 == checksum_63_2);
}

int fn_R000882_8213_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int scale_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_55) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_86 = (aux + st.buffer[1]) & 3;
  switch (anchor_86)
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
  int checksum_63 = local_arr[aux % 3];
  acc = (acc + (checksum_63 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000882_8213_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st_1 = {0};
  struct Transaction_R000882_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_31_1) & 63;
  aux_2 = (aux_2 + vector_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_31_1 == vector_31_2);
}

int fn_R000882_8213_18(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000882_8213_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st_1 = {0};
  struct Transaction_R000882_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int window_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_89_1 > 14)
  {
    acc_1 = ((acc_1 + (window_89_1 * 2)) + 5) & 127;
    aux_1 ^= window_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_89_2 > 14)
  {
    acc_2 = ((acc_2 + (window_89_2 * 2)) + 5) & 127;
    aux_2 ^= window_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_64_1) & 63;
  aux_2 = (aux_2 + accumulator_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_66_1 = local_arr_1[aux_1 % 3];
  int margin_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_89_1 == window_89_2);
  assert(accumulator_64_1 == accumulator_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_66_1 == margin_66_2);
}

int fn_R000882_8213_19(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000882_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int window_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_89 > 14)
  {
    acc = ((acc + (window_89 * 2)) + 5) & 127;
    aux ^= window_89 & 15;
  }
  else
  {
    acc = ((acc - window_89) + 11) & 127;
    aux += 3;
  }
  int accumulator_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_64) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_66 = local_arr[aux % 3];
  acc = (acc + (margin_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000882_8213_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st_1 = {0};
  struct Vector3D_R000882_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_39_1 = local_arr_1[aux_1 % 3];
  int quantum_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_39_2 * 2)) & 127;
  int vector_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_43_1)
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

  switch (vector_43_2)
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

  int checksum_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_88_1) & 63;
  aux_2 = (aux_2 + checksum_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_39_1 == quantum_39_2);
  assert(vector_43_1 == vector_43_2);
  assert(checksum_88_1 == checksum_88_2);
}

int fn_R000882_8213_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000882_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int quantum_39 = local_arr[aux % 3];
  acc = (acc + (quantum_39 * 2)) & 127;
  int vector_43 = (aux + st.buffer[1]) & 3;
  switch (vector_43)
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

  int checksum_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_88) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000882_0_1;
  int sec_r000882_0_2;
  int sec_r000882_1_1;
  int sec_r000882_1_2;
  int sec_r000882_2_1;
  int sec_r000882_2_2;
  int sec_r000882_3_1;
  int sec_r000882_3_2;
  int sec_r000882_4_1;
  int sec_r000882_4_2;
  int sec_r000882_5_1;
  int sec_r000882_5_2;
  int sec_r000882_6_1;
  int sec_r000882_6_2;
  int sec_r000882_7_1;
  int sec_r000882_7_2;
  int sec_r000882_8_1;
  int sec_r000882_8_2;
  int sec_r000882_9_1;
  int sec_r000882_9_2;
  int sec_r000882_10_1;
  int sec_r000882_10_2;
  int sec_r000882_11_1;
  int sec_r000882_11_2;
  int sec_r000882_12_1;
  int sec_r000882_12_2;
  int sec_r000882_13_1;
  int sec_r000882_13_2;
  int sec_r000882_14_1;
  int sec_r000882_14_2;
  int sec_r000882_15_1;
  int sec_r000882_15_2;
  int sec_r000882_16_1;
  int sec_r000882_16_2;
  int sec_r000882_17_1;
  int sec_r000882_17_2;
  int sec_r000882_18_1;
  int sec_r000882_18_2;
  int pub_r000882_0_1;
  int pub_r000882_0_2;
  int pub_r000882_1_1;
  int pub_r000882_1_2;
  int pub_r000882_2_1;
  int pub_r000882_2_2;
  int pub_r000882_3_1;
  int pub_r000882_3_2;
  int pub_r000882_4_1;
  int pub_r000882_4_2;
  int pub_r000882_5_1;
  int pub_r000882_5_2;
  int pub_r000882_6_1;
  int pub_r000882_6_2;
  int pub_r000882_7_1;
  int pub_r000882_7_2;
  int pub_r000882_8_1;
  int pub_r000882_8_2;
  int pub_r000882_9_1;
  int pub_r000882_9_2;
  int pub_r000882_10_1;
  int pub_r000882_10_2;
  int pub_r000882_11_1;
  int pub_r000882_11_2;
  int pub_r000882_12_1;
  int pub_r000882_12_2;
  int pub_r000882_13_1;
  int pub_r000882_13_2;
  int pub_r000882_14_1;
  int pub_r000882_14_2;
  int pub_r000882_15_1;
  int pub_r000882_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000882_0_1 >= (-100)) && (pub_r000882_0_1 <= 100));
  __CPROVER_assume((pub_r000882_0_2 >= (-100)) && (pub_r000882_0_2 <= 100));
  __CPROVER_assume((pub_r000882_1_1 >= (-100)) && (pub_r000882_1_1 <= 100));
  __CPROVER_assume((pub_r000882_1_2 >= (-100)) && (pub_r000882_1_2 <= 100));
  __CPROVER_assume((pub_r000882_2_1 >= (-100)) && (pub_r000882_2_1 <= 100));
  __CPROVER_assume((pub_r000882_2_2 >= (-100)) && (pub_r000882_2_2 <= 100));
  __CPROVER_assume((pub_r000882_3_1 >= (-100)) && (pub_r000882_3_1 <= 100));
  __CPROVER_assume((pub_r000882_3_2 >= (-100)) && (pub_r000882_3_2 <= 100));
  __CPROVER_assume((pub_r000882_4_1 >= (-100)) && (pub_r000882_4_1 <= 100));
  __CPROVER_assume((pub_r000882_4_2 >= (-100)) && (pub_r000882_4_2 <= 100));
  __CPROVER_assume((pub_r000882_5_1 >= (-100)) && (pub_r000882_5_1 <= 100));
  __CPROVER_assume((pub_r000882_5_2 >= (-100)) && (pub_r000882_5_2 <= 100));
  __CPROVER_assume((pub_r000882_6_1 >= (-100)) && (pub_r000882_6_1 <= 100));
  __CPROVER_assume((pub_r000882_6_2 >= (-100)) && (pub_r000882_6_2 <= 100));
  __CPROVER_assume((pub_r000882_7_1 >= (-100)) && (pub_r000882_7_1 <= 100));
  __CPROVER_assume((pub_r000882_7_2 >= (-100)) && (pub_r000882_7_2 <= 100));
  __CPROVER_assume((pub_r000882_8_1 >= (-100)) && (pub_r000882_8_1 <= 100));
  __CPROVER_assume((pub_r000882_8_2 >= (-100)) && (pub_r000882_8_2 <= 100));
  __CPROVER_assume((pub_r000882_9_1 >= (-100)) && (pub_r000882_9_1 <= 100));
  __CPROVER_assume((pub_r000882_9_2 >= (-100)) && (pub_r000882_9_2 <= 100));
  __CPROVER_assume((pub_r000882_10_1 >= (-100)) && (pub_r000882_10_1 <= 100));
  __CPROVER_assume((pub_r000882_10_2 >= (-100)) && (pub_r000882_10_2 <= 100));
  __CPROVER_assume((pub_r000882_11_1 >= (-100)) && (pub_r000882_11_1 <= 100));
  __CPROVER_assume((pub_r000882_11_2 >= (-100)) && (pub_r000882_11_2 <= 100));
  __CPROVER_assume((pub_r000882_12_1 >= (-100)) && (pub_r000882_12_1 <= 100));
  __CPROVER_assume((pub_r000882_12_2 >= (-100)) && (pub_r000882_12_2 <= 100));
  __CPROVER_assume((pub_r000882_13_1 >= (-100)) && (pub_r000882_13_1 <= 100));
  __CPROVER_assume((pub_r000882_13_2 >= (-100)) && (pub_r000882_13_2 <= 100));
  __CPROVER_assume((pub_r000882_14_1 >= (-100)) && (pub_r000882_14_1 <= 100));
  __CPROVER_assume((pub_r000882_14_2 >= (-100)) && (pub_r000882_14_2 <= 100));
  __CPROVER_assume((pub_r000882_15_1 >= (-100)) && (pub_r000882_15_1 <= 100));
  __CPROVER_assume((pub_r000882_15_2 >= (-100)) && (pub_r000882_15_2 <= 100));
  __CPROVER_assume((sec_r000882_0_1 >= 0) && (sec_r000882_0_1 <= 255));
  __CPROVER_assume((sec_r000882_0_2 >= 0) && (sec_r000882_0_2 <= 255));
  __CPROVER_assume((sec_r000882_1_1 >= 0) && (sec_r000882_1_1 <= 255));
  __CPROVER_assume((sec_r000882_1_2 >= 0) && (sec_r000882_1_2 <= 255));
  __CPROVER_assume((sec_r000882_2_1 >= 0) && (sec_r000882_2_1 <= 255));
  __CPROVER_assume((sec_r000882_2_2 >= 0) && (sec_r000882_2_2 <= 255));
  __CPROVER_assume((sec_r000882_3_1 >= 0) && (sec_r000882_3_1 <= 255));
  __CPROVER_assume((sec_r000882_3_2 >= 0) && (sec_r000882_3_2 <= 255));
  __CPROVER_assume((sec_r000882_4_1 >= 0) && (sec_r000882_4_1 <= 255));
  __CPROVER_assume((sec_r000882_4_2 >= 0) && (sec_r000882_4_2 <= 255));
  __CPROVER_assume((sec_r000882_5_1 >= 0) && (sec_r000882_5_1 <= 255));
  __CPROVER_assume((sec_r000882_5_2 >= 0) && (sec_r000882_5_2 <= 255));
  __CPROVER_assume((sec_r000882_6_1 >= 0) && (sec_r000882_6_1 <= 255));
  __CPROVER_assume((sec_r000882_6_2 >= 0) && (sec_r000882_6_2 <= 255));
  __CPROVER_assume((sec_r000882_7_1 >= 0) && (sec_r000882_7_1 <= 255));
  __CPROVER_assume((sec_r000882_7_2 >= 0) && (sec_r000882_7_2 <= 255));
  __CPROVER_assume((sec_r000882_8_1 >= 0) && (sec_r000882_8_1 <= 255));
  __CPROVER_assume((sec_r000882_8_2 >= 0) && (sec_r000882_8_2 <= 255));
  __CPROVER_assume((sec_r000882_9_1 >= 0) && (sec_r000882_9_1 <= 255));
  __CPROVER_assume((sec_r000882_9_2 >= 0) && (sec_r000882_9_2 <= 255));
  __CPROVER_assume((sec_r000882_10_1 >= 0) && (sec_r000882_10_1 <= 255));
  __CPROVER_assume((sec_r000882_10_2 >= 0) && (sec_r000882_10_2 <= 255));
  __CPROVER_assume((sec_r000882_11_1 >= 0) && (sec_r000882_11_1 <= 255));
  __CPROVER_assume((sec_r000882_11_2 >= 0) && (sec_r000882_11_2 <= 255));
  __CPROVER_assume((sec_r000882_12_1 >= 0) && (sec_r000882_12_1 <= 255));
  __CPROVER_assume((sec_r000882_12_2 >= 0) && (sec_r000882_12_2 <= 255));
  __CPROVER_assume((sec_r000882_13_1 >= 0) && (sec_r000882_13_1 <= 255));
  __CPROVER_assume((sec_r000882_13_2 >= 0) && (sec_r000882_13_2 <= 255));
  __CPROVER_assume((sec_r000882_14_1 >= 0) && (sec_r000882_14_1 <= 255));
  __CPROVER_assume((sec_r000882_14_2 >= 0) && (sec_r000882_14_2 <= 255));
  __CPROVER_assume((sec_r000882_15_1 >= 0) && (sec_r000882_15_1 <= 255));
  __CPROVER_assume((sec_r000882_15_2 >= 0) && (sec_r000882_15_2 <= 255));
  __CPROVER_assume((sec_r000882_16_1 >= 0) && (sec_r000882_16_1 <= 255));
  __CPROVER_assume((sec_r000882_16_2 >= 0) && (sec_r000882_16_2 <= 255));
  __CPROVER_assume((sec_r000882_17_1 >= 0) && (sec_r000882_17_1 <= 255));
  __CPROVER_assume((sec_r000882_17_2 >= 0) && (sec_r000882_17_2 <= 255));
  __CPROVER_assume((sec_r000882_18_1 >= 0) && (sec_r000882_18_1 <= 255));
  __CPROVER_assume((sec_r000882_18_2 >= 0) && (sec_r000882_18_2 <= 255));
  struct Vector3D_R000882_8213_0 st_var_0_1 = {0};
  struct Vector3D_R000882_8213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000882_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000882_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000882_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000882_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000882_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000882_0_2 + 7) & 15;
  struct Transaction_R000882_8213_1 st_var_1_1 = {0};
  struct Transaction_R000882_8213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000882_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000882_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000882_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000882_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000882_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000882_0_2 + 9) & 15;
  union PacketPayload_R000882_8213_0 u_var_1;
  union PacketPayload_R000882_8213_0 u_var_2;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  int stage_v_5_1 = (st_var_1_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_1_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = ((st_var_0_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_0_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 41)
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
  if (stage_v_6_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 41)
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
  int stage_v_7_1 = (st_var_1_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_1_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
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

  switch (stage_v_7_2)
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

  int stage_v_8_1 = (st_var_0_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_0_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = ((st_var_1_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_1_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 39)
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
  if (stage_v_9_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 39)
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
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = (st_var_0_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_0_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = ((st_var_0_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_0_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 48)
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
  if (stage_v_20_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 48)
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
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
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

  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((st_var_1_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_1_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 51)
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
  if (stage_v_23_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 51)
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
  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((st_var_1_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_1_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 49)
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
  if (stage_v_27_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 49)
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
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 30) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 30) & 15;
  int stage_v_29_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_29_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= stage_v_29_1;
  chk_sum_2 ^= stage_v_29_2;
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
  int stage_v_31_1 = table_1[3];
  int stage_v_31_2 = table_2[3];
  table_1[3] = (table_1[0] + 63) & 63;
  table_2[3] = (table_2[0] + 63) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 37) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 37) & 15;
  int stage_v_36_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_36_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= stage_v_36_1;
  chk_sum_2 ^= stage_v_36_2;
  int stage_v_37_1 = (st_var_1_1.buffer[0] ^ 40) & 3;
  int stage_v_37_2 = (st_var_1_2.buffer[0] ^ 40) & 3;
  switch (stage_v_37_1)
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

  switch (stage_v_37_2)
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

  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 40) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = (st_var_0_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_0_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = table_1[1];
  int stage_v_41_2 = table_2[1];
  table_1[1] = (table_1[2] + 83) & 63;
  table_2[1] = (table_2[2] + 83) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (st_var_0_1.buffer[0] ^ 45) & 3;
  int stage_v_42_2 = (st_var_0_2.buffer[0] ^ 45) & 3;
  switch (stage_v_42_1)
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

  switch (stage_v_42_2)
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

  int stage_v_43_1 = ((st_var_1_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_1_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 46)
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
  if (stage_v_43_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 46)
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
  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 46) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (st_var_0_1.buffer[0] ^ 51) & 3;
  int stage_v_48_2 = (st_var_0_2.buffer[0] ^ 51) & 3;
  switch (stage_v_48_1)
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

  switch (stage_v_48_2)
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

  int stage_v_49_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (54 & 31);
  int stage_v_49_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (54 & 31);
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= (stage_v_49_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_49_2 << 1) & 127;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_50_1 = ((stage_v_50_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_50_2 = ((stage_v_50_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_51_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_52_1 = ((sec_r000882_1_1 + pub_r000882_9_1) + 32) & 127;
  int stage_v_52_2 = ((sec_r000882_1_2 + pub_r000882_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((sec_r000882_11_1 + pub_r000882_12_1) + 32) & 127;
  int stage_v_53_2 = ((sec_r000882_11_2 + pub_r000882_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((stage_v_53_1 + pub_r000882_3_1) + 17) & 127;
  int stage_v_54_2 = ((stage_v_53_2 + pub_r000882_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((stage_v_53_1 + pub_r000882_12_1) + 21) & 127;
  int stage_v_55_2 = ((stage_v_53_2 + pub_r000882_12_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((stage_v_54_1 + pub_r000882_5_1) + 18) & 127;
  int stage_v_56_2 = ((stage_v_54_2 + pub_r000882_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((stage_v_52_1 + pub_r000882_9_1) + 6) & 127;
  int stage_v_57_2 = ((stage_v_52_2 + pub_r000882_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((stage_v_57_1 + pub_r000882_0_1) + 14) & 127;
  int stage_v_58_2 = ((stage_v_57_2 + pub_r000882_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((stage_v_54_1 + pub_r000882_0_1) + 48) & 127;
  int stage_v_59_2 = ((stage_v_54_2 + pub_r000882_0_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((stage_v_58_1 + pub_r000882_15_1) + 48) & 127;
  int stage_v_60_2 = ((stage_v_58_2 + pub_r000882_15_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((stage_v_53_1 + pub_r000882_4_1) + 18) & 127;
  int stage_v_61_2 = ((stage_v_53_2 + pub_r000882_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((stage_v_54_1 + pub_r000882_4_1) + 36) & 127;
  int stage_v_62_2 = ((stage_v_54_2 + pub_r000882_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((stage_v_59_1 + pub_r000882_9_1) + 36) & 127;
  int stage_v_63_2 = ((stage_v_59_2 + pub_r000882_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((stage_v_58_1 + pub_r000882_13_1) + 7) & 127;
  int stage_v_64_2 = ((stage_v_58_2 + pub_r000882_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((stage_v_62_1 + pub_r000882_0_1) + 24) & 127;
  int stage_v_65_2 = ((stage_v_62_2 + pub_r000882_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((stage_v_56_1 + pub_r000882_15_1) + 31) & 127;
  int stage_v_66_2 = ((stage_v_56_2 + pub_r000882_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((sec_r000882_3_1 + pub_r000882_1_1) + 18) & 127;
  int stage_v_67_2 = ((sec_r000882_3_2 + pub_r000882_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((sec_r000882_13_1 + pub_r000882_15_1) + 25) & 127;
  int stage_v_68_2 = ((sec_r000882_13_2 + pub_r000882_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((stage_v_68_1 + pub_r000882_13_1) + 36) & 127;
  int stage_v_69_2 = ((stage_v_68_2 + pub_r000882_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((stage_v_64_1 + pub_r000882_14_1) + 30) & 127;
  int stage_v_70_2 = ((stage_v_64_2 + pub_r000882_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((stage_v_69_1 + pub_r000882_5_1) + 33) & 127;
  int stage_v_71_2 = ((stage_v_69_2 + pub_r000882_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((sec_r000882_4_1 + pub_r000882_2_1) + 18) & 127;
  int stage_v_72_2 = ((sec_r000882_4_2 + pub_r000882_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((sec_r000882_4_1 + pub_r000882_13_1) + 7) & 127;
  int stage_v_73_2 = ((sec_r000882_4_2 + pub_r000882_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((sec_r000882_13_1 + pub_r000882_4_1) + 33) & 127;
  int stage_v_74_2 = ((sec_r000882_13_2 + pub_r000882_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((sec_r000882_18_1 + pub_r000882_9_1) + 6) & 127;
  int stage_v_75_2 = ((sec_r000882_18_2 + pub_r000882_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((stage_v_67_1 + pub_r000882_5_1) + 24) & 127;
  int stage_v_76_2 = ((stage_v_67_2 + pub_r000882_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((stage_v_74_1 + pub_r000882_6_1) + 25) & 127;
  int stage_v_77_2 = ((stage_v_74_2 + pub_r000882_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((stage_v_72_1 + pub_r000882_3_1) + 41) & 127;
  int stage_v_78_2 = ((stage_v_72_2 + pub_r000882_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((stage_v_67_1 + pub_r000882_2_1) + 35) & 127;
  int stage_v_79_2 = ((stage_v_67_2 + pub_r000882_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((stage_v_52_1 + pub_r000882_13_1) + 35) & 127;
  int stage_v_80_2 = ((stage_v_52_2 + pub_r000882_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((sec_r000882_8_1 + pub_r000882_9_1) + 35) & 127;
  int stage_v_81_2 = ((sec_r000882_8_2 + pub_r000882_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((stage_v_57_1 + pub_r000882_9_1) + 15) & 127;
  int stage_v_82_2 = ((stage_v_57_2 + pub_r000882_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((stage_v_73_1 + pub_r000882_5_1) + 33) & 127;
  int stage_v_83_2 = ((stage_v_73_2 + pub_r000882_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((stage_v_72_1 + pub_r000882_1_1) + 28) & 127;
  int stage_v_84_2 = ((stage_v_72_2 + pub_r000882_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((stage_v_62_1 + pub_r000882_0_1) + 32) & 127;
  int stage_v_85_2 = ((stage_v_62_2 + pub_r000882_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((stage_v_68_1 + pub_r000882_15_1) + 20) & 127;
  int stage_v_86_2 = ((stage_v_68_2 + pub_r000882_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((stage_v_82_1 + pub_r000882_6_1) + 23) & 127;
  int stage_v_87_2 = ((stage_v_82_2 + pub_r000882_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((stage_v_70_1 + pub_r000882_6_1) + 16) & 127;
  int stage_v_88_2 = ((stage_v_70_2 + pub_r000882_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((stage_v_87_1 + pub_r000882_4_1) + 40) & 127;
  int stage_v_89_2 = ((stage_v_87_2 + pub_r000882_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((stage_v_58_1 + pub_r000882_14_1) + 38) & 127;
  int stage_v_90_2 = ((stage_v_58_2 + pub_r000882_14_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((stage_v_85_1 + pub_r000882_6_1) + 42) & 127;
  int stage_v_91_2 = ((stage_v_85_2 + pub_r000882_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((stage_v_83_1 + pub_r000882_8_1) + 9) & 127;
  int stage_v_92_2 = ((stage_v_83_2 + pub_r000882_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((stage_v_56_1 + pub_r000882_15_1) + 11) & 127;
  int stage_v_93_2 = ((stage_v_56_2 + pub_r000882_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((sec_r000882_0_1 + pub_r000882_8_1) + 11) & 127;
  int stage_v_94_2 = ((sec_r000882_0_2 + pub_r000882_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((sec_r000882_12_1 + pub_r000882_7_1) + 4) & 127;
  int stage_v_95_2 = ((sec_r000882_12_2 + pub_r000882_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((stage_v_64_1 + pub_r000882_10_1) + 23) & 127;
  int stage_v_96_2 = ((stage_v_64_2 + pub_r000882_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((stage_v_57_1 + pub_r000882_1_1) + 5) & 127;
  int stage_v_97_2 = ((stage_v_57_2 + pub_r000882_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((sec_r000882_10_1 + pub_r000882_13_1) + 7) & 127;
  int stage_v_98_2 = ((sec_r000882_10_2 + pub_r000882_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((stage_v_71_1 + pub_r000882_7_1) + 44) & 127;
  int stage_v_99_2 = ((stage_v_71_2 + pub_r000882_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((stage_v_86_1 + pub_r000882_10_1) + 25) & 127;
  int stage_v_100_2 = ((stage_v_86_2 + pub_r000882_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((sec_r000882_6_1 + pub_r000882_4_1) + 18) & 127;
  int stage_v_101_2 = ((sec_r000882_6_2 + pub_r000882_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((stage_v_80_1 + pub_r000882_0_1) + 20) & 127;
  int stage_v_102_2 = ((stage_v_80_2 + pub_r000882_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((sec_r000882_6_1 + pub_r000882_8_1) + 18) & 127;
  int stage_v_103_2 = ((sec_r000882_6_2 + pub_r000882_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((stage_v_77_1 + pub_r000882_11_1) + 16) & 127;
  int stage_v_104_2 = ((stage_v_77_2 + pub_r000882_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((sec_r000882_13_1 + pub_r000882_9_1) + 30) & 127;
  int stage_v_105_2 = ((sec_r000882_13_2 + pub_r000882_9_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((sec_r000882_13_1 + pub_r000882_15_1) + 49) & 127;
  int stage_v_106_2 = ((sec_r000882_13_2 + pub_r000882_15_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((sec_r000882_9_1 + pub_r000882_14_1) + 16) & 127;
  int stage_v_107_2 = ((sec_r000882_9_2 + pub_r000882_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((sec_r000882_1_1 + pub_r000882_12_1) + 41) & 127;
  int stage_v_108_2 = ((sec_r000882_1_2 + pub_r000882_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((sec_r000882_18_1 + pub_r000882_4_1) + 31) & 127;
  int stage_v_109_2 = ((sec_r000882_18_2 + pub_r000882_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((sec_r000882_3_1 + pub_r000882_0_1) + 35) & 127;
  int stage_v_110_2 = ((sec_r000882_3_2 + pub_r000882_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((stage_v_89_1 + pub_r000882_8_1) + 5) & 127;
  int stage_v_111_2 = ((stage_v_89_2 + pub_r000882_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((stage_v_92_1 + pub_r000882_9_1) + 21) & 127;
  int stage_v_112_2 = ((stage_v_92_2 + pub_r000882_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((stage_v_97_1 + pub_r000882_2_1) + 48) & 127;
  int stage_v_113_2 = ((stage_v_97_2 + pub_r000882_2_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((stage_v_85_1 + pub_r000882_12_1) + 41) & 127;
  int stage_v_114_2 = ((stage_v_85_2 + pub_r000882_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((stage_v_96_1 + pub_r000882_7_1) + 27) & 127;
  int stage_v_115_2 = ((stage_v_96_2 + pub_r000882_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((sec_r000882_4_1 + pub_r000882_9_1) + 10) & 127;
  int stage_v_116_2 = ((sec_r000882_4_2 + pub_r000882_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((stage_v_54_1 + pub_r000882_7_1) + 27) & 127;
  int stage_v_117_2 = ((stage_v_54_2 + pub_r000882_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((sec_r000882_11_1 + pub_r000882_9_1) + 19) & 127;
  int stage_v_118_2 = ((sec_r000882_11_2 + pub_r000882_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((sec_r000882_5_1 + pub_r000882_5_1) + 12) & 127;
  int stage_v_119_2 = ((sec_r000882_5_2 + pub_r000882_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((stage_v_73_1 + pub_r000882_3_1) + 4) & 127;
  int stage_v_120_2 = ((stage_v_73_2 + pub_r000882_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((stage_v_107_1 + pub_r000882_6_1) + 15) & 127;
  int stage_v_121_2 = ((stage_v_107_2 + pub_r000882_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((stage_v_102_1 + pub_r000882_1_1) + 32) & 127;
  int stage_v_122_2 = ((stage_v_102_2 + pub_r000882_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((sec_r000882_9_1 + pub_r000882_12_1) + 47) & 127;
  int stage_v_123_2 = ((sec_r000882_9_2 + pub_r000882_12_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((sec_r000882_6_1 + pub_r000882_4_1) + 29) & 127;
  int stage_v_124_2 = ((sec_r000882_6_2 + pub_r000882_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((stage_v_60_1 + pub_r000882_12_1) + 32) & 127;
  int stage_v_125_2 = ((stage_v_60_2 + pub_r000882_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((stage_v_113_1 + pub_r000882_1_1) + 10) & 127;
  int stage_v_126_2 = ((stage_v_113_2 + pub_r000882_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((stage_v_71_1 + pub_r000882_13_1) + 47) & 127;
  int stage_v_127_2 = ((stage_v_71_2 + pub_r000882_13_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((sec_r000882_18_1 + pub_r000882_3_1) + 38) & 127;
  int stage_v_128_2 = ((sec_r000882_18_2 + pub_r000882_3_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((sec_r000882_5_1 + pub_r000882_10_1) + 39) & 127;
  int stage_v_129_2 = ((sec_r000882_5_2 + pub_r000882_10_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((stage_v_127_1 + pub_r000882_6_1) + 19) & 127;
  int stage_v_130_2 = ((stage_v_127_2 + pub_r000882_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((stage_v_123_1 + pub_r000882_4_1) + 46) & 127;
  int stage_v_131_2 = ((stage_v_123_2 + pub_r000882_4_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((stage_v_121_1 + pub_r000882_7_1) + 6) & 127;
  int stage_v_132_2 = ((stage_v_121_2 + pub_r000882_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((stage_v_64_1 + pub_r000882_5_1) + 12) & 127;
  int stage_v_133_2 = ((stage_v_64_2 + pub_r000882_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((stage_v_103_1 + pub_r000882_2_1) + 44) & 127;
  int stage_v_134_2 = ((stage_v_103_2 + pub_r000882_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((stage_v_73_1 + pub_r000882_0_1) + 23) & 127;
  int stage_v_135_2 = ((stage_v_73_2 + pub_r000882_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((sec_r000882_12_1 + pub_r000882_0_1) + 4) & 127;
  int stage_v_136_2 = ((sec_r000882_12_2 + pub_r000882_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((stage_v_136_1 + pub_r000882_5_1) + 12) & 127;
  int stage_v_137_2 = ((stage_v_136_2 + pub_r000882_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((stage_v_73_1 + pub_r000882_14_1) + 19) & 127;
  int stage_v_138_2 = ((stage_v_73_2 + pub_r000882_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((stage_v_101_1 + pub_r000882_12_1) + 29) & 127;
  int stage_v_139_2 = ((stage_v_101_2 + pub_r000882_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((stage_v_107_1 + pub_r000882_0_1) + 20) & 127;
  int stage_v_140_2 = ((stage_v_107_2 + pub_r000882_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((stage_v_65_1 + pub_r000882_12_1) + 39) & 127;
  int stage_v_141_2 = ((stage_v_65_2 + pub_r000882_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((stage_v_61_1 + pub_r000882_14_1) + 23) & 127;
  int stage_v_142_2 = ((stage_v_61_2 + pub_r000882_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((sec_r000882_15_1 + pub_r000882_1_1) + 24) & 127;
  int stage_v_143_2 = ((sec_r000882_15_2 + pub_r000882_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((stage_v_136_1 + pub_r000882_11_1) + 8) & 127;
  int stage_v_144_2 = ((stage_v_136_2 + pub_r000882_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((stage_v_61_1 + pub_r000882_14_1) + 14) & 127;
  int stage_v_145_2 = ((stage_v_61_2 + pub_r000882_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((sec_r000882_13_1 + pub_r000882_9_1) + 31) & 127;
  int stage_v_146_2 = ((sec_r000882_13_2 + pub_r000882_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((stage_v_124_1 + pub_r000882_11_1) + 11) & 127;
  int stage_v_147_2 = ((stage_v_124_2 + pub_r000882_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((sec_r000882_14_1 + pub_r000882_1_1) + 24) & 127;
  int stage_v_148_2 = ((sec_r000882_14_2 + pub_r000882_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((stage_v_127_1 + pub_r000882_12_1) + 16) & 127;
  int stage_v_149_2 = ((stage_v_127_2 + pub_r000882_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((stage_v_135_1 + pub_r000882_1_1) + 31) & 127;
  int stage_v_150_2 = ((stage_v_135_2 + pub_r000882_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((stage_v_145_1 + pub_r000882_8_1) + 22) & 127;
  int stage_v_151_2 = ((stage_v_145_2 + pub_r000882_8_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((stage_v_83_1 + pub_r000882_6_1) + 23) & 127;
  int stage_v_152_2 = ((stage_v_83_2 + pub_r000882_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((stage_v_63_1 + pub_r000882_9_1) + 18) & 127;
  int stage_v_153_2 = ((stage_v_63_2 + pub_r000882_9_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((sec_r000882_11_1 + pub_r000882_9_1) + 6) & 127;
  int stage_v_154_2 = ((sec_r000882_11_2 + pub_r000882_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((stage_v_84_1 + pub_r000882_0_1) + 31) & 127;
  int stage_v_155_2 = ((stage_v_84_2 + pub_r000882_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((stage_v_116_1 + pub_r000882_12_1) + 15) & 127;
  int stage_v_156_2 = ((stage_v_116_2 + pub_r000882_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((stage_v_152_1 + pub_r000882_15_1) + 48) & 127;
  int stage_v_157_2 = ((stage_v_152_2 + pub_r000882_15_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((stage_v_77_1 + pub_r000882_8_1) + 40) & 127;
  int stage_v_158_2 = ((stage_v_77_2 + pub_r000882_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((stage_v_144_1 + pub_r000882_2_1) + 18) & 127;
  int stage_v_159_2 = ((stage_v_144_2 + pub_r000882_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((sec_r000882_3_1 + pub_r000882_1_1) + 29) & 127;
  int stage_v_160_2 = ((sec_r000882_3_2 + pub_r000882_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((stage_v_135_1 + pub_r000882_2_1) + 4) & 127;
  int stage_v_161_2 = ((stage_v_135_2 + pub_r000882_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((stage_v_62_1 + pub_r000882_6_1) + 47) & 127;
  int stage_v_162_2 = ((stage_v_62_2 + pub_r000882_6_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((sec_r000882_5_1 + pub_r000882_10_1) + 43) & 127;
  int stage_v_163_2 = ((sec_r000882_5_2 + pub_r000882_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((stage_v_133_1 + pub_r000882_12_1) + 29) & 127;
  int stage_v_164_2 = ((stage_v_133_2 + pub_r000882_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((stage_v_114_1 + pub_r000882_6_1) + 26) & 127;
  int stage_v_165_2 = ((stage_v_114_2 + pub_r000882_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((stage_v_71_1 + pub_r000882_11_1) + 40) & 127;
  int stage_v_166_2 = ((stage_v_71_2 + pub_r000882_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((stage_v_132_1 + pub_r000882_8_1) + 10) & 127;
  int stage_v_167_2 = ((stage_v_132_2 + pub_r000882_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((sec_r000882_11_1 + pub_r000882_15_1) + 35) & 127;
  int stage_v_168_2 = ((sec_r000882_11_2 + pub_r000882_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((stage_v_54_1 + pub_r000882_1_1) + 27) & 127;
  int stage_v_169_2 = ((stage_v_54_2 + pub_r000882_1_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((sec_r000882_7_1 + pub_r000882_2_1) + 12) & 127;
  int stage_v_170_2 = ((sec_r000882_7_2 + pub_r000882_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((sec_r000882_1_1 + pub_r000882_15_1) + 20) & 127;
  int stage_v_171_2 = ((sec_r000882_1_2 + pub_r000882_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((stage_v_102_1 + pub_r000882_13_1) + 15) & 127;
  int stage_v_172_2 = ((stage_v_102_2 + pub_r000882_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((stage_v_84_1 + pub_r000882_5_1) + 14) & 127;
  int stage_v_173_2 = ((stage_v_84_2 + pub_r000882_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((stage_v_103_1 + pub_r000882_0_1) + 34) & 127;
  int stage_v_174_2 = ((stage_v_103_2 + pub_r000882_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((sec_r000882_11_1 + pub_r000882_6_1) + 12) & 127;
  int stage_v_175_2 = ((sec_r000882_11_2 + pub_r000882_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((stage_v_80_1 + pub_r000882_9_1) + 18) & 127;
  int stage_v_176_2 = ((stage_v_80_2 + pub_r000882_9_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((sec_r000882_0_1 + pub_r000882_6_1) + 38) & 127;
  int stage_v_177_2 = ((sec_r000882_0_2 + pub_r000882_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((stage_v_162_1 + pub_r000882_1_1) + 10) & 127;
  int stage_v_178_2 = ((stage_v_162_2 + pub_r000882_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((sec_r000882_8_1 + pub_r000882_9_1) + 3) & 127;
  int stage_v_179_2 = ((sec_r000882_8_2 + pub_r000882_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((stage_v_178_1 + pub_r000882_8_1) + 28) & 127;
  int stage_v_180_2 = ((stage_v_178_2 + pub_r000882_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((sec_r000882_3_1 + pub_r000882_13_1) + 21) & 127;
  int stage_v_181_2 = ((sec_r000882_3_2 + pub_r000882_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((stage_v_175_1 + pub_r000882_10_1) + 24) & 127;
  int stage_v_182_2 = ((stage_v_175_2 + pub_r000882_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((stage_v_169_1 + pub_r000882_12_1) + 29) & 127;
  int stage_v_183_2 = ((stage_v_169_2 + pub_r000882_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((stage_v_64_1 + pub_r000882_1_1) + 26) & 127;
  int stage_v_184_2 = ((stage_v_64_2 + pub_r000882_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((sec_r000882_1_1 + pub_r000882_3_1) + 28) & 127;
  int stage_v_185_2 = ((sec_r000882_1_2 + pub_r000882_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((stage_v_122_1 + pub_r000882_3_1) + 12) & 127;
  int stage_v_186_2 = ((stage_v_122_2 + pub_r000882_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((stage_v_74_1 + pub_r000882_1_1) + 31) & 127;
  int stage_v_187_2 = ((stage_v_74_2 + pub_r000882_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((stage_v_76_1 + pub_r000882_4_1) + 25) & 127;
  int stage_v_188_2 = ((stage_v_76_2 + pub_r000882_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((stage_v_116_1 + pub_r000882_13_1) + 42) & 127;
  int stage_v_189_2 = ((stage_v_116_2 + pub_r000882_13_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((sec_r000882_8_1 + pub_r000882_13_1) + 19) & 127;
  int stage_v_190_2 = ((sec_r000882_8_2 + pub_r000882_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((stage_v_124_1 + pub_r000882_8_1) + 43) & 127;
  int stage_v_191_2 = ((stage_v_124_2 + pub_r000882_8_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((sec_r000882_15_1 + pub_r000882_7_1) + 13) & 127;
  int stage_v_192_2 = ((sec_r000882_15_2 + pub_r000882_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((sec_r000882_13_1 + pub_r000882_2_1) + 32) & 127;
  int stage_v_193_2 = ((sec_r000882_13_2 + pub_r000882_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((stage_v_170_1 + pub_r000882_11_1) + 22) & 127;
  int stage_v_194_2 = ((stage_v_170_2 + pub_r000882_11_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((stage_v_180_1 + pub_r000882_15_1) + 32) & 127;
  int stage_v_195_2 = ((stage_v_180_2 + pub_r000882_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((stage_v_141_1 + pub_r000882_0_1) + 18) & 127;
  int stage_v_196_2 = ((stage_v_141_2 + pub_r000882_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((sec_r000882_9_1 + pub_r000882_12_1) + 33) & 127;
  int stage_v_197_2 = ((sec_r000882_9_2 + pub_r000882_12_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((sec_r000882_6_1 + pub_r000882_14_1) + 10) & 127;
  int stage_v_198_2 = ((sec_r000882_6_2 + pub_r000882_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((stage_v_131_1 + pub_r000882_0_1) + 5) & 127;
  int stage_v_199_2 = ((stage_v_131_2 + pub_r000882_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((stage_v_160_1 + pub_r000882_0_1) + 16) & 127;
  int stage_v_200_2 = ((stage_v_160_2 + pub_r000882_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((stage_v_170_1 + pub_r000882_1_1) + 48) & 127;
  int stage_v_201_2 = ((stage_v_170_2 + pub_r000882_1_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((stage_v_71_1 + pub_r000882_14_1) + 41) & 127;
  int stage_v_202_2 = ((stage_v_71_2 + pub_r000882_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((stage_v_61_1 + pub_r000882_10_1) + 16) & 127;
  int stage_v_203_2 = ((stage_v_61_2 + pub_r000882_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((stage_v_53_1 + pub_r000882_1_1) + 21) & 127;
  int stage_v_204_2 = ((stage_v_53_2 + pub_r000882_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((stage_v_72_1 + pub_r000882_13_1) + 27) & 127;
  int stage_v_205_2 = ((stage_v_72_2 + pub_r000882_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((stage_v_53_1 + pub_r000882_9_1) + 34) & 127;
  int stage_v_206_2 = ((stage_v_53_2 + pub_r000882_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((sec_r000882_13_1 + pub_r000882_14_1) + 28) & 127;
  int stage_v_207_2 = ((sec_r000882_13_2 + pub_r000882_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((stage_v_88_1 + pub_r000882_7_1) + 27) & 127;
  int stage_v_208_2 = ((stage_v_88_2 + pub_r000882_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((stage_v_143_1 + pub_r000882_9_1) + 4) & 127;
  int stage_v_209_2 = ((stage_v_143_2 + pub_r000882_9_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((stage_v_183_1 + pub_r000882_7_1) + 21) & 127;
  int stage_v_210_2 = ((stage_v_183_2 + pub_r000882_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((stage_v_106_1 + pub_r000882_10_1) + 16) & 127;
  int stage_v_211_2 = ((stage_v_106_2 + pub_r000882_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((sec_r000882_10_1 + pub_r000882_5_1) + 12) & 127;
  int stage_v_212_2 = ((sec_r000882_10_2 + pub_r000882_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((stage_v_76_1 + pub_r000882_4_1) + 10) & 127;
  int stage_v_213_2 = ((stage_v_76_2 + pub_r000882_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((stage_v_113_1 + pub_r000882_13_1) + 26) & 127;
  int stage_v_214_2 = ((stage_v_113_2 + pub_r000882_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((sec_r000882_18_1 + pub_r000882_12_1) + 29) & 127;
  int stage_v_215_2 = ((sec_r000882_18_2 + pub_r000882_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((stage_v_72_1 + pub_r000882_9_1) + 9) & 127;
  int stage_v_216_2 = ((stage_v_72_2 + pub_r000882_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((stage_v_201_1 + pub_r000882_14_1) + 13) & 127;
  int stage_v_217_2 = ((stage_v_201_2 + pub_r000882_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((sec_r000882_12_1 + pub_r000882_15_1) + 14) & 127;
  int stage_v_218_2 = ((sec_r000882_12_2 + pub_r000882_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((stage_v_144_1 + pub_r000882_14_1) + 38) & 127;
  int stage_v_219_2 = ((stage_v_144_2 + pub_r000882_14_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((stage_v_86_1 + pub_r000882_3_1) + 6) & 127;
  int stage_v_220_2 = ((stage_v_86_2 + pub_r000882_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((stage_v_135_1 + pub_r000882_11_1) + 47) & 127;
  int stage_v_221_2 = ((stage_v_135_2 + pub_r000882_11_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((stage_v_209_1 + pub_r000882_0_1) + 32) & 127;
  int stage_v_222_2 = ((stage_v_209_2 + pub_r000882_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((stage_v_138_1 + pub_r000882_8_1) + 45) & 127;
  int stage_v_223_2 = ((stage_v_138_2 + pub_r000882_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((stage_v_122_1 + pub_r000882_14_1) + 36) & 127;
  int stage_v_224_2 = ((stage_v_122_2 + pub_r000882_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((stage_v_83_1 + pub_r000882_8_1) + 21) & 127;
  int stage_v_225_2 = ((stage_v_83_2 + pub_r000882_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((stage_v_118_1 + pub_r000882_8_1) + 36) & 127;
  int stage_v_226_2 = ((stage_v_118_2 + pub_r000882_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((sec_r000882_8_1 + pub_r000882_4_1) + 49) & 127;
  int stage_v_227_2 = ((sec_r000882_8_2 + pub_r000882_4_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((stage_v_210_1 + pub_r000882_12_1) + 46) & 127;
  int stage_v_228_2 = ((stage_v_210_2 + pub_r000882_12_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((stage_v_158_1 + pub_r000882_1_1) + 11) & 127;
  int stage_v_229_2 = ((stage_v_158_2 + pub_r000882_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((stage_v_203_1 + pub_r000882_14_1) + 41) & 127;
  int stage_v_230_2 = ((stage_v_203_2 + pub_r000882_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((stage_v_133_1 + pub_r000882_14_1) + 14) & 127;
  int stage_v_231_2 = ((stage_v_133_2 + pub_r000882_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((sec_r000882_7_1 + pub_r000882_9_1) + 39) & 127;
  int stage_v_232_2 = ((sec_r000882_7_2 + pub_r000882_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((stage_v_167_1 + pub_r000882_14_1) + 32) & 127;
  int stage_v_233_2 = ((stage_v_167_2 + pub_r000882_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((stage_v_109_1 + pub_r000882_2_1) + 13) & 127;
  int stage_v_234_2 = ((stage_v_109_2 + pub_r000882_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((stage_v_142_1 + pub_r000882_2_1) + 45) & 127;
  int stage_v_235_2 = ((stage_v_142_2 + pub_r000882_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((stage_v_186_1 + pub_r000882_2_1) + 3) & 127;
  int stage_v_236_2 = ((stage_v_186_2 + pub_r000882_2_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((stage_v_201_1 + pub_r000882_10_1) + 18) & 127;
  int stage_v_237_2 = ((stage_v_201_2 + pub_r000882_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((sec_r000882_5_1 + pub_r000882_0_1) + 37) & 127;
  int stage_v_238_2 = ((sec_r000882_5_2 + pub_r000882_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((stage_v_63_1 + pub_r000882_0_1) + 46) & 127;
  int stage_v_239_2 = ((stage_v_63_2 + pub_r000882_0_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((stage_v_234_1 + pub_r000882_8_1) + 45) & 127;
  int stage_v_240_2 = ((stage_v_234_2 + pub_r000882_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((sec_r000882_1_1 + pub_r000882_1_1) + 10) & 127;
  int stage_v_241_2 = ((sec_r000882_1_2 + pub_r000882_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((stage_v_188_1 + pub_r000882_8_1) + 21) & 127;
  int stage_v_242_2 = ((stage_v_188_2 + pub_r000882_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((sec_r000882_10_1 + pub_r000882_4_1) + 21) & 127;
  int stage_v_243_2 = ((sec_r000882_10_2 + pub_r000882_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((sec_r000882_5_1 + pub_r000882_6_1) + 46) & 127;
  int stage_v_244_2 = ((sec_r000882_5_2 + pub_r000882_6_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((stage_v_84_1 + pub_r000882_15_1) + 14) & 127;
  int stage_v_245_2 = ((stage_v_84_2 + pub_r000882_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((sec_r000882_12_1 + pub_r000882_4_1) + 34) & 127;
  int stage_v_246_2 = ((sec_r000882_12_2 + pub_r000882_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((sec_r000882_5_1 + pub_r000882_4_1) + 49) & 127;
  int stage_v_247_2 = ((sec_r000882_5_2 + pub_r000882_4_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((stage_v_146_1 + pub_r000882_5_1) + 25) & 127;
  int stage_v_248_2 = ((stage_v_146_2 + pub_r000882_5_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((stage_v_152_1 + pub_r000882_3_1) + 45) & 127;
  int stage_v_249_2 = ((stage_v_152_2 + pub_r000882_3_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((stage_v_56_1 + pub_r000882_1_1) + 6) & 127;
  int stage_v_250_2 = ((stage_v_56_2 + pub_r000882_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((stage_v_197_1 + pub_r000882_1_1) + 30) & 127;
  int stage_v_251_2 = ((stage_v_197_2 + pub_r000882_1_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((stage_v_103_1 + pub_r000882_11_1) + 15) & 127;
  int stage_v_252_2 = ((stage_v_103_2 + pub_r000882_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((stage_v_117_1 + pub_r000882_12_1) + 26) & 127;
  int stage_v_253_2 = ((stage_v_117_2 + pub_r000882_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((sec_r000882_13_1 + pub_r000882_0_1) + 10) & 127;
  int stage_v_254_2 = ((sec_r000882_13_2 + pub_r000882_0_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((sec_r000882_16_1 + pub_r000882_1_1) + 11) & 127;
  int stage_v_255_2 = ((sec_r000882_16_2 + pub_r000882_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((stage_v_54_1 + pub_r000882_6_1) + 13) & 127;
  int stage_v_256_2 = ((stage_v_54_2 + pub_r000882_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((sec_r000882_6_1 + pub_r000882_7_1) + 48) & 127;
  int stage_v_257_2 = ((sec_r000882_6_2 + pub_r000882_7_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((sec_r000882_10_1 + pub_r000882_3_1) + 22) & 127;
  int stage_v_258_2 = ((sec_r000882_10_2 + pub_r000882_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((stage_v_63_1 + pub_r000882_4_1) + 45) & 127;
  int stage_v_259_2 = ((stage_v_63_2 + pub_r000882_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((sec_r000882_10_1 + pub_r000882_7_1) + 11) & 127;
  int stage_v_260_2 = ((sec_r000882_10_2 + pub_r000882_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((stage_v_174_1 + pub_r000882_9_1) + 25) & 127;
  int stage_v_261_2 = ((stage_v_174_2 + pub_r000882_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((stage_v_60_1 + pub_r000882_14_1) + 4) & 127;
  int stage_v_262_2 = ((stage_v_60_2 + pub_r000882_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((sec_r000882_12_1 + pub_r000882_4_1) + 23) & 127;
  int stage_v_263_2 = ((sec_r000882_12_2 + pub_r000882_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((sec_r000882_2_1 + pub_r000882_2_1) + 5) & 127;
  int stage_v_264_2 = ((sec_r000882_2_2 + pub_r000882_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((stage_v_180_1 + pub_r000882_8_1) + 36) & 127;
  int stage_v_265_2 = ((stage_v_180_2 + pub_r000882_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((sec_r000882_18_1 + pub_r000882_7_1) + 26) & 127;
  int stage_v_266_2 = ((sec_r000882_18_2 + pub_r000882_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((sec_r000882_18_1 + pub_r000882_2_1) + 46) & 127;
  int stage_v_267_2 = ((sec_r000882_18_2 + pub_r000882_2_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((sec_r000882_9_1 + pub_r000882_3_1) + 19) & 127;
  int stage_v_268_2 = ((sec_r000882_9_2 + pub_r000882_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((stage_v_179_1 + pub_r000882_1_1) + 19) & 127;
  int stage_v_269_2 = ((stage_v_179_2 + pub_r000882_1_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((stage_v_143_1 + pub_r000882_2_1) + 32) & 127;
  int stage_v_270_2 = ((stage_v_143_2 + pub_r000882_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((sec_r000882_10_1 + pub_r000882_5_1) + 39) & 127;
  int stage_v_271_2 = ((sec_r000882_10_2 + pub_r000882_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((sec_r000882_9_1 + pub_r000882_7_1) + 19) & 127;
  int stage_v_272_2 = ((sec_r000882_9_2 + pub_r000882_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((stage_v_152_1 + pub_r000882_6_1) + 6) & 127;
  int stage_v_273_2 = ((stage_v_152_2 + pub_r000882_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((stage_v_211_1 + pub_r000882_2_1) + 43) & 127;
  int stage_v_274_2 = ((stage_v_211_2 + pub_r000882_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((sec_r000882_9_1 + pub_r000882_7_1) + 22) & 127;
  int stage_v_275_2 = ((sec_r000882_9_2 + pub_r000882_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((stage_v_238_1 + pub_r000882_0_1) + 34) & 127;
  int stage_v_276_2 = ((stage_v_238_2 + pub_r000882_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((stage_v_108_1 + pub_r000882_4_1) + 45) & 127;
  int stage_v_277_2 = ((stage_v_108_2 + pub_r000882_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((stage_v_137_1 + pub_r000882_11_1) + 9) & 127;
  int stage_v_278_2 = ((stage_v_137_2 + pub_r000882_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((sec_r000882_4_1 + pub_r000882_0_1) + 19) & 127;
  int stage_v_279_2 = ((sec_r000882_4_2 + pub_r000882_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((stage_v_93_1 + pub_r000882_5_1) + 3) & 127;
  int stage_v_280_2 = ((stage_v_93_2 + pub_r000882_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((stage_v_173_1 + pub_r000882_1_1) + 35) & 127;
  int stage_v_281_2 = ((stage_v_173_2 + pub_r000882_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((sec_r000882_0_1 + pub_r000882_4_1) + 42) & 127;
  int stage_v_282_2 = ((sec_r000882_0_2 + pub_r000882_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((stage_v_68_1 + pub_r000882_3_1) + 7) & 127;
  int stage_v_283_2 = ((stage_v_68_2 + pub_r000882_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((stage_v_204_1 + pub_r000882_4_1) + 39) & 127;
  int stage_v_284_2 = ((stage_v_204_2 + pub_r000882_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((stage_v_142_1 + pub_r000882_14_1) + 37) & 127;
  int stage_v_285_2 = ((stage_v_142_2 + pub_r000882_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((sec_r000882_5_1 + pub_r000882_9_1) + 41) & 127;
  int stage_v_286_2 = ((sec_r000882_5_2 + pub_r000882_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((stage_v_150_1 + pub_r000882_2_1) + 20) & 127;
  int stage_v_287_2 = ((stage_v_150_2 + pub_r000882_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((sec_r000882_7_1 + pub_r000882_9_1) + 30) & 127;
  int stage_v_288_2 = ((sec_r000882_7_2 + pub_r000882_9_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((stage_v_264_1 + pub_r000882_11_1) + 39) & 127;
  int stage_v_289_2 = ((stage_v_264_2 + pub_r000882_11_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((sec_r000882_8_1 + pub_r000882_0_1) + 46) & 127;
  int stage_v_290_2 = ((sec_r000882_8_2 + pub_r000882_0_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((stage_v_65_1 + pub_r000882_2_1) + 40) & 127;
  int stage_v_291_2 = ((stage_v_65_2 + pub_r000882_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((stage_v_244_1 + pub_r000882_14_1) + 10) & 127;
  int stage_v_292_2 = ((stage_v_244_2 + pub_r000882_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((stage_v_235_1 + pub_r000882_5_1) + 11) & 127;
  int stage_v_293_2 = ((stage_v_235_2 + pub_r000882_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((stage_v_169_1 + pub_r000882_12_1) + 28) & 127;
  int stage_v_294_2 = ((stage_v_169_2 + pub_r000882_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((stage_v_204_1 + pub_r000882_4_1) + 23) & 127;
  int stage_v_295_2 = ((stage_v_204_2 + pub_r000882_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((sec_r000882_12_1 + pub_r000882_13_1) + 19) & 127;
  int stage_v_296_2 = ((sec_r000882_12_2 + pub_r000882_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((stage_v_251_1 + pub_r000882_5_1) + 37) & 127;
  int stage_v_297_2 = ((stage_v_251_2 + pub_r000882_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((stage_v_245_1 + pub_r000882_11_1) + 37) & 127;
  int stage_v_298_2 = ((stage_v_245_2 + pub_r000882_11_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((sec_r000882_17_1 + pub_r000882_13_1) + 46) & 127;
  int stage_v_299_2 = ((sec_r000882_17_2 + pub_r000882_13_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((stage_v_81_1 + pub_r000882_10_1) + 24) & 127;
  int stage_v_300_2 = ((stage_v_81_2 + pub_r000882_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((sec_r000882_16_1 + pub_r000882_0_1) + 46) & 127;
  int stage_v_301_2 = ((sec_r000882_16_2 + pub_r000882_0_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((stage_v_111_1 + pub_r000882_5_1) + 17) & 127;
  int stage_v_302_2 = ((stage_v_111_2 + pub_r000882_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((stage_v_177_1 + pub_r000882_15_1) + 48) & 127;
  int stage_v_303_2 = ((stage_v_177_2 + pub_r000882_15_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((stage_v_167_1 + pub_r000882_0_1) + 6) & 127;
  int stage_v_304_2 = ((stage_v_167_2 + pub_r000882_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((stage_v_204_1 + pub_r000882_0_1) + 44) & 127;
  int stage_v_305_2 = ((stage_v_204_2 + pub_r000882_0_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((sec_r000882_16_1 + pub_r000882_3_1) + 9) & 127;
  int stage_v_306_2 = ((sec_r000882_16_2 + pub_r000882_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((stage_v_299_1 + pub_r000882_15_1) + 22) & 127;
  int stage_v_307_2 = ((stage_v_299_2 + pub_r000882_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((stage_v_184_1 + pub_r000882_4_1) + 37) & 127;
  int stage_v_308_2 = ((stage_v_184_2 + pub_r000882_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((stage_v_155_1 + pub_r000882_10_1) + 27) & 127;
  int stage_v_309_2 = ((stage_v_155_2 + pub_r000882_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((sec_r000882_7_1 + pub_r000882_0_1) + 47) & 127;
  int stage_v_310_2 = ((sec_r000882_7_2 + pub_r000882_0_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((sec_r000882_2_1 + pub_r000882_15_1) + 44) & 127;
  int stage_v_311_2 = ((sec_r000882_2_2 + pub_r000882_15_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((sec_r000882_18_1 + pub_r000882_11_1) + 9) & 127;
  int stage_v_312_2 = ((sec_r000882_18_2 + pub_r000882_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int stage_v_313_1 = ((stage_v_202_1 + pub_r000882_1_1) + 32) & 127;
  int stage_v_313_2 = ((stage_v_202_2 + pub_r000882_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int stage_v_314_1 = ((stage_v_164_1 + pub_r000882_2_1) + 4) & 127;
  int stage_v_314_2 = ((stage_v_164_2 + pub_r000882_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int stage_v_315_1 = ((sec_r000882_14_1 + pub_r000882_7_1) + 45) & 127;
  int stage_v_315_2 = ((sec_r000882_14_2 + pub_r000882_7_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000882_0_1 != sec_r000882_0_2);
  __CPROVER_assume(sec_r000882_7_1 != sec_r000882_7_2);
  __CPROVER_assume(pub_r000882_7_1 == pub_r000882_7_2);
  __CPROVER_assume(pub_r000882_14_1 == pub_r000882_14_2);
  __CPROVER_assume(sec_r000882_16_1 != sec_r000882_16_2);
  __CPROVER_assume(pub_r000882_8_1 == pub_r000882_8_2);
  __CPROVER_assume(pub_r000882_15_1 == pub_r000882_15_2);
  __CPROVER_assume(sec_r000882_12_1 != sec_r000882_12_2);
  __CPROVER_assume(pub_r000882_6_1 == pub_r000882_6_2);
  __CPROVER_assume(pub_r000882_9_1 == pub_r000882_9_2);
  __CPROVER_assume(sec_r000882_11_1 != sec_r000882_11_2);
  __CPROVER_assume(sec_r000882_5_1 != sec_r000882_5_2);
  __CPROVER_assume(pub_r000882_4_1 == pub_r000882_4_2);
  __CPROVER_assume(pub_r000882_3_1 == pub_r000882_3_2);
  __CPROVER_assume(sec_r000882_18_1 != sec_r000882_18_2);
  __CPROVER_assume(pub_r000882_10_1 == pub_r000882_10_2);
  __CPROVER_assume(sec_r000882_1_1 != sec_r000882_1_2);
  __CPROVER_assume(pub_r000882_13_1 == pub_r000882_13_2);
  __CPROVER_assume(sec_r000882_17_1 != sec_r000882_17_2);
  __CPROVER_assume(pub_r000882_1_1 == pub_r000882_1_2);
  __CPROVER_assume(sec_r000882_4_1 != sec_r000882_4_2);
  __CPROVER_assume(sec_r000882_9_1 != sec_r000882_9_2);
  __CPROVER_assume(sec_r000882_3_1 != sec_r000882_3_2);
  __CPROVER_assume(sec_r000882_10_1 != sec_r000882_10_2);
  __CPROVER_assume(sec_r000882_6_1 != sec_r000882_6_2);
  __CPROVER_assume(sec_r000882_15_1 != sec_r000882_15_2);
  __CPROVER_assume(sec_r000882_13_1 != sec_r000882_13_2);
  __CPROVER_assume(pub_r000882_11_1 == pub_r000882_11_2);
  __CPROVER_assume(sec_r000882_8_1 != sec_r000882_8_2);
  __CPROVER_assume(pub_r000882_2_1 == pub_r000882_2_2);
  __CPROVER_assume(pub_r000882_12_1 == pub_r000882_12_2);
  __CPROVER_assume(pub_r000882_0_1 == pub_r000882_0_2);
  __CPROVER_assume(sec_r000882_2_1 != sec_r000882_2_2);
  __CPROVER_assume(pub_r000882_5_1 == pub_r000882_5_2);
  __CPROVER_assume(sec_r000882_14_1 != sec_r000882_14_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.status == st_var_1_2.status);
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
  assert(stage_v_236_1 == stage_v_236_2);
  assert(stage_v_237_1 == stage_v_237_2);
  assert(stage_v_238_1 == stage_v_238_2);
  assert(stage_v_239_1 == stage_v_239_2);
  assert(stage_v_240_1 == stage_v_240_2);
  assert(stage_v_241_1 == stage_v_241_2);
  assert(stage_v_242_1 == stage_v_242_2);
  assert(stage_v_243_1 == stage_v_243_2);
  assert(stage_v_244_1 == stage_v_244_2);
  assert(stage_v_245_1 == stage_v_245_2);
  assert(stage_v_246_1 == stage_v_246_2);
  assert(stage_v_247_1 == stage_v_247_2);
  assert(stage_v_248_1 == stage_v_248_2);
  assert(stage_v_249_1 == stage_v_249_2);
  assert(stage_v_250_1 == stage_v_250_2);
  assert(stage_v_251_1 == stage_v_251_2);
  assert(stage_v_252_1 == stage_v_252_2);
  assert(stage_v_253_1 == stage_v_253_2);
  assert(stage_v_254_1 == stage_v_254_2);
  assert(stage_v_255_1 == stage_v_255_2);
  assert(stage_v_256_1 == stage_v_256_2);
  assert(stage_v_257_1 == stage_v_257_2);
  assert(stage_v_258_1 == stage_v_258_2);
  assert(stage_v_259_1 == stage_v_259_2);
  assert(stage_v_260_1 == stage_v_260_2);
  assert(stage_v_261_1 == stage_v_261_2);
  assert(stage_v_262_1 == stage_v_262_2);
  assert(stage_v_263_1 == stage_v_263_2);
  assert(stage_v_264_1 == stage_v_264_2);
  assert(stage_v_265_1 == stage_v_265_2);
  assert(stage_v_266_1 == stage_v_266_2);
  assert(stage_v_267_1 == stage_v_267_2);
  assert(stage_v_268_1 == stage_v_268_2);
  assert(stage_v_269_1 == stage_v_269_2);
  assert(stage_v_270_1 == stage_v_270_2);
  assert(stage_v_271_1 == stage_v_271_2);
  assert(stage_v_272_1 == stage_v_272_2);
  assert(stage_v_273_1 == stage_v_273_2);
  assert(stage_v_274_1 == stage_v_274_2);
  assert(stage_v_275_1 == stage_v_275_2);
  assert(stage_v_276_1 == stage_v_276_2);
  assert(stage_v_277_1 == stage_v_277_2);
  assert(stage_v_278_1 == stage_v_278_2);
  assert(stage_v_279_1 == stage_v_279_2);
  assert(stage_v_280_1 == stage_v_280_2);
  assert(stage_v_281_1 == stage_v_281_2);
  assert(stage_v_282_1 == stage_v_282_2);
  assert(stage_v_283_1 == stage_v_283_2);
  assert(stage_v_284_1 == stage_v_284_2);
  assert(stage_v_285_1 == stage_v_285_2);
  assert(stage_v_286_1 == stage_v_286_2);
  assert(stage_v_287_1 == stage_v_287_2);
  assert(stage_v_288_1 == stage_v_288_2);
  assert(stage_v_289_1 == stage_v_289_2);
  assert(stage_v_290_1 == stage_v_290_2);
  assert(stage_v_291_1 == stage_v_291_2);
  assert(stage_v_292_1 == stage_v_292_2);
  assert(stage_v_293_1 == stage_v_293_2);
  assert(stage_v_294_1 == stage_v_294_2);
  assert(stage_v_295_1 == stage_v_295_2);
  assert(stage_v_296_1 == stage_v_296_2);
  assert(stage_v_297_1 == stage_v_297_2);
  assert(stage_v_298_1 == stage_v_298_2);
  assert(stage_v_299_1 == stage_v_299_2);
  assert(stage_v_300_1 == stage_v_300_2);
  assert(stage_v_301_1 == stage_v_301_2);
  assert(stage_v_302_1 == stage_v_302_2);
  assert(stage_v_303_1 == stage_v_303_2);
  assert(stage_v_304_1 == stage_v_304_2);
  assert(stage_v_305_1 == stage_v_305_2);
  assert(stage_v_306_1 == stage_v_306_2);
  assert(stage_v_307_1 == stage_v_307_2);
  assert(stage_v_308_1 == stage_v_308_2);
  assert(stage_v_309_1 == stage_v_309_2);
  assert(stage_v_310_1 == stage_v_310_2);
  assert(stage_v_311_1 == stage_v_311_2);
  assert(stage_v_312_1 == stage_v_312_2);
  assert(stage_v_313_1 == stage_v_313_2);
  assert(stage_v_314_1 == stage_v_314_2);
  assert(stage_v_315_1 == stage_v_315_2);
}


