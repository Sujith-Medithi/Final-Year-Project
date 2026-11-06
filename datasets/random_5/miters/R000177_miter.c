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
struct EventLog_R000177_7713_0
{
  int seq;
  unsigned char signature;
  int code;
  short facility;
  short timestamp;
  int buffer[3];
};
struct Vector3D_R000177_7713_1
{
  int coord_y;
  int norm_sq;
  short coord_z;
  short heading;
  int pitch;
  int buffer[3];
};
union ColorPixel_R000177_7713_0
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
void fn_R000177_7713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st_1 = {0};
  struct EventLog_R000177_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int delta_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_79_1) & 63;
  aux_2 = (aux_2 + delta_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_79_1 == delta_79_2);
}

int fn_R000177_7713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int delta_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_79) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000177_7713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000177_7713_1 st_1 = {0};
  struct Vector3D_R000177_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_11_1 = local_arr_1[aux_1 % 3];
  int tally_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_11_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_11_1 == tally_11_2);
}

int fn_R000177_7713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000177_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_11 = local_arr[aux % 3];
  acc = (acc + (tally_11 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000177_7713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st_1 = {0};
  struct EventLog_R000177_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int checksum_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_87_1)
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

  switch (checksum_87_2)
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

  int damping_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_10_1 > 17)
  {
    acc_1 = ((acc_1 + (damping_10_1 * 2)) + 5) & 127;
    aux_1 ^= damping_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_10_2 > 17)
  {
    acc_2 = ((acc_2 + (damping_10_2 * 2)) + 5) & 127;
    aux_2 ^= damping_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_55_1) & 63;
  aux_2 = (aux_2 + factor_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_87_1 == checksum_87_2);
  assert(damping_10_1 == damping_10_2);
  assert(factor_55_1 == factor_55_2);
}

int fn_R000177_7713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int checksum_87 = (aux + st.buffer[1]) & 3;
  switch (checksum_87)
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

  int damping_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_10 > 17)
  {
    acc = ((acc + (damping_10 * 2)) + 5) & 127;
    aux ^= damping_10 & 15;
  }
  else
  {
    acc = ((acc - damping_10) + 11) & 127;
    aux += 3;
  }
  int factor_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_55) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000177_7713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st_1 = {0};
  struct EventLog_R000177_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_47_1 = local_arr_1[aux_1 % 3];
  int damping_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_47_2 * 2)) & 127;
  int scale_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_26_1)
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

  switch (scale_26_2)
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

  int pivot_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_77_1) & 63;
  aux_2 = (aux_2 + pivot_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_47_1 == damping_47_2);
  assert(scale_26_1 == scale_26_2);
  assert(pivot_77_1 == pivot_77_2);
}

int fn_R000177_7713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int damping_47 = local_arr[aux % 3];
  acc = (acc + (damping_47 * 2)) & 127;
  int scale_26 = (aux + st.buffer[1]) & 3;
  switch (scale_26)
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

  int pivot_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_77) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000177_7713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000177_7713_1 st_1 = {0};
  struct Vector3D_R000177_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_11_1 = local_arr_1[aux_1 % 3];
  int tracker_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_11_2 * 2)) & 127;
  int pivot_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_22_1 > 15)
  {
    acc_1 = ((acc_1 + (pivot_22_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_22_2 > 15)
  {
    acc_2 = ((acc_2 + (pivot_22_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_22_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_11_1 == tracker_11_2);
  assert(pivot_22_1 == pivot_22_2);
}

int fn_R000177_7713_4(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000177_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int tracker_11 = local_arr[aux % 3];
  acc = (acc + (tracker_11 * 2)) & 127;
  int pivot_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_22 > 15)
  {
    acc = ((acc + (pivot_22 * 2)) + 5) & 127;
    aux ^= pivot_22 & 15;
  }
  else
  {
    acc = ((acc - pivot_22) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000177_7713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st_1 = {0};
  struct EventLog_R000177_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_75_1 = local_arr_1[aux_1 % 3];
  int factor_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_75_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_75_1 == factor_75_2);
}

int fn_R000177_7713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int factor_75 = local_arr[aux % 3];
  acc = (acc + (factor_75 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000177_7713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st_1 = {0};
  struct EventLog_R000177_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int phase_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_66_1 > 49)
  {
    acc_1 = ((acc_1 + (phase_66_1 * 2)) + 5) & 127;
    aux_1 ^= phase_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_66_2 > 49)
  {
    acc_2 = ((acc_2 + (phase_66_2 * 2)) + 5) & 127;
    aux_2 ^= phase_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_66_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_45_1) & 63;
  aux_2 = (aux_2 + checksum_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_66_1 == phase_66_2);
  assert(checksum_45_1 == checksum_45_2);
}

int fn_R000177_7713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int phase_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_66 > 49)
  {
    acc = ((acc + (phase_66 * 2)) + 5) & 127;
    aux ^= phase_66 & 15;
  }
  else
  {
    acc = ((acc - phase_66) + 11) & 127;
    aux += 3;
  }
  int checksum_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_45) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000177_7713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000177_7713_1 st_1 = {0};
  struct Vector3D_R000177_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int vector_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_80_1 > 45)
  {
    acc_1 = ((acc_1 + (vector_80_1 * 2)) + 5) & 127;
    aux_1 ^= vector_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_80_2 > 45)
  {
    acc_2 = ((acc_2 + (vector_80_2 * 2)) + 5) & 127;
    aux_2 ^= vector_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_15_1)
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

  switch (window_15_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_80_1 == vector_80_2);
  assert(window_15_1 == window_15_2);
}

int fn_R000177_7713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000177_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int vector_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_80 > 45)
  {
    acc = ((acc + (vector_80 * 2)) + 5) & 127;
    aux ^= vector_80 & 15;
  }
  else
  {
    acc = ((acc - vector_80) + 11) & 127;
    aux += 3;
  }
  int window_15 = (aux + st.buffer[1]) & 3;
  switch (window_15)
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

void fn_R000177_7713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st_1 = {0};
  struct EventLog_R000177_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int bound_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_92_1)
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

  switch (bound_92_2)
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

  int margin_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_38_1 > 40)
  {
    acc_1 = ((acc_1 + (margin_38_1 * 2)) + 5) & 127;
    aux_1 ^= margin_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_38_2 > 40)
  {
    acc_2 = ((acc_2 + (margin_38_2 * 2)) + 5) & 127;
    aux_2 ^= margin_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_55_1) & 63;
  aux_2 = (aux_2 + mask_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_92_1 == bound_92_2);
  assert(margin_38_1 == margin_38_2);
  assert(mask_55_1 == mask_55_2);
}

int fn_R000177_7713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int bound_92 = (aux + st.buffer[1]) & 3;
  switch (bound_92)
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

  int margin_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_38 > 40)
  {
    acc = ((acc + (margin_38 * 2)) + 5) & 127;
    aux ^= margin_38 & 15;
  }
  else
  {
    acc = ((acc - margin_38) + 11) & 127;
    aux += 3;
  }
  int mask_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_55) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000177_7713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000177_7713_1 st_1 = {0};
  struct Vector3D_R000177_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int quantum_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_37_1)
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

  switch (quantum_37_2)
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

  int tally_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_55_1) & 63;
  aux_2 = (aux_2 + tally_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_30_1 = local_arr_1[aux_1 % 3];
  int margin_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_30_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_37_1 == quantum_37_2);
  assert(tally_55_1 == tally_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_30_1 == margin_30_2);
}

int fn_R000177_7713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000177_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int quantum_37 = (aux + st.buffer[1]) & 3;
  switch (quantum_37)
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

  int tally_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_55) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_30 = local_arr[aux % 3];
  acc = (acc + (margin_30 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000177_7713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st_1 = {0};
  struct EventLog_R000177_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int margin_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_16_1)
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

  switch (margin_16_2)
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

  int pivot_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_69_1) & 63;
  aux_2 = (aux_2 + pivot_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_16_1 == margin_16_2);
  assert(pivot_69_1 == pivot_69_2);
}

int fn_R000177_7713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int margin_16 = (aux + st.buffer[1]) & 3;
  switch (margin_16)
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

  int pivot_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_69) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000177_7713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st_1 = {0};
  struct EventLog_R000177_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int index_reg_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_83_1) & 63;
  aux_2 = (aux_2 + index_reg_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_13_1 > 50)
  {
    acc_1 = ((acc_1 + (quantum_13_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_13_2 > 50)
  {
    acc_2 = ((acc_2 + (quantum_13_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_13_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_83_1 == index_reg_83_2);
  assert(quantum_13_1 == quantum_13_2);
}

int fn_R000177_7713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int index_reg_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_83) & 63;
  acc ^= aux;
  int quantum_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_13 > 50)
  {
    acc = ((acc + (quantum_13 * 2)) + 5) & 127;
    aux ^= quantum_13 & 15;
  }
  else
  {
    acc = ((acc - quantum_13) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000177_7713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st_1 = {0};
  struct EventLog_R000177_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_57_1 > 31)
  {
    acc_1 = ((acc_1 + (mask_57_1 * 2)) + 5) & 127;
    aux_1 ^= mask_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_57_2 > 31)
  {
    acc_2 = ((acc_2 + (mask_57_2 * 2)) + 5) & 127;
    aux_2 ^= mask_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_57_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_57_1 == mask_57_2);
}

int fn_R000177_7713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_57 > 31)
  {
    acc = ((acc + (mask_57 * 2)) + 5) & 127;
    aux ^= mask_57 & 15;
  }
  else
  {
    acc = ((acc - mask_57) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000177_7713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000177_7713_1 st_1 = {0};
  struct Vector3D_R000177_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int residue_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_35_1) & 63;
  aux_2 = (aux_2 + residue_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_61_1)
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

  switch (offset_61_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_35_1 == residue_35_2);
  assert(offset_61_1 == offset_61_2);
}

int fn_R000177_7713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000177_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int residue_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_35) & 63;
  acc ^= aux;
  int offset_61 = (aux + st.buffer[1]) & 3;
  switch (offset_61)
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

  return (acc + aux) & 255;
}

void fn_R000177_7713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000177_7713_1 st_1 = {0};
  struct Vector3D_R000177_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_37_1)
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

  switch (delta_37_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_37_1 == delta_37_2);
}

int fn_R000177_7713_14(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000177_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_37 = (aux + st.buffer[1]) & 3;
  switch (delta_37)
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

void fn_R000177_7713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st_1 = {0};
  struct EventLog_R000177_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int residue_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_23_1)
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

  switch (residue_23_2)
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

  int quantum_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_72_1) & 63;
  aux_2 = (aux_2 + quantum_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_23_1 = local_arr_1[aux_1 % 3];
  int vector_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_23_2 * 2)) & 127;
  int cursor_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_83_1 > 38)
  {
    acc_1 = ((acc_1 + (cursor_83_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_83_2 > 38)
  {
    acc_2 = ((acc_2 + (cursor_83_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_23_1 == residue_23_2);
  assert(quantum_72_1 == quantum_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_23_1 == vector_23_2);
  assert(cursor_83_1 == cursor_83_2);
}

int fn_R000177_7713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int residue_23 = (aux + st.buffer[1]) & 3;
  switch (residue_23)
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

  int quantum_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_72) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int vector_23 = local_arr[aux % 3];
  acc = (acc + (vector_23 * 2)) & 127;
  int cursor_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_83 > 38)
  {
    acc = ((acc + (cursor_83 * 2)) + 5) & 127;
    aux ^= cursor_83 & 15;
  }
  else
  {
    acc = ((acc - cursor_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000177_7713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st_1 = {0};
  struct EventLog_R000177_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_21_1 = local_arr_1[aux_1 % 3];
  int index_reg_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_21_2 * 2)) & 127;
  int cursor_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_12_1) & 63;
  aux_2 = (aux_2 + cursor_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_21_1 == index_reg_21_2);
  assert(cursor_12_1 == cursor_12_2);
}

int fn_R000177_7713_16(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int index_reg_21 = local_arr[aux % 3];
  acc = (acc + (index_reg_21 * 2)) & 127;
  int cursor_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_12) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000177_7713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st_1 = {0};
  struct EventLog_R000177_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int quotient_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_88_1 > 18)
  {
    acc_1 = ((acc_1 + (quotient_88_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_88_2 > 18)
  {
    acc_2 = ((acc_2 + (quotient_88_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_88_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_91_1)
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

  switch (quotient_91_2)
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

  int quotient_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_64_1) & 63;
  aux_2 = (aux_2 + quotient_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_88_1 == quotient_88_2);
  assert(quotient_91_1 == quotient_91_2);
  assert(quotient_64_1 == quotient_64_2);
}

int fn_R000177_7713_17(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000177_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int quotient_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_88 > 18)
  {
    acc = ((acc + (quotient_88 * 2)) + 5) & 127;
    aux ^= quotient_88 & 15;
  }
  else
  {
    acc = ((acc - quotient_88) + 11) & 127;
    aux += 3;
  }
  int quotient_91 = (aux + st.buffer[1]) & 3;
  switch (quotient_91)
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

  int quotient_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000177_0_1;
  int sec_r000177_0_2;
  int sec_r000177_1_1;
  int sec_r000177_1_2;
  int sec_r000177_2_1;
  int sec_r000177_2_2;
  int sec_r000177_3_1;
  int sec_r000177_3_2;
  int sec_r000177_4_1;
  int sec_r000177_4_2;
  int sec_r000177_5_1;
  int sec_r000177_5_2;
  int sec_r000177_6_1;
  int sec_r000177_6_2;
  int sec_r000177_7_1;
  int sec_r000177_7_2;
  int sec_r000177_8_1;
  int sec_r000177_8_2;
  int sec_r000177_9_1;
  int sec_r000177_9_2;
  int sec_r000177_10_1;
  int sec_r000177_10_2;
  int sec_r000177_11_1;
  int sec_r000177_11_2;
  int sec_r000177_12_1;
  int sec_r000177_12_2;
  int sec_r000177_13_1;
  int sec_r000177_13_2;
  int sec_r000177_14_1;
  int sec_r000177_14_2;
  int sec_r000177_15_1;
  int sec_r000177_15_2;
  int pub_r000177_0_1;
  int pub_r000177_0_2;
  int pub_r000177_1_1;
  int pub_r000177_1_2;
  int pub_r000177_2_1;
  int pub_r000177_2_2;
  int pub_r000177_3_1;
  int pub_r000177_3_2;
  int pub_r000177_4_1;
  int pub_r000177_4_2;
  int pub_r000177_5_1;
  int pub_r000177_5_2;
  int pub_r000177_6_1;
  int pub_r000177_6_2;
  int pub_r000177_7_1;
  int pub_r000177_7_2;
  int pub_r000177_8_1;
  int pub_r000177_8_2;
  int pub_r000177_9_1;
  int pub_r000177_9_2;
  int pub_r000177_10_1;
  int pub_r000177_10_2;
  int pub_r000177_11_1;
  int pub_r000177_11_2;
  int pub_r000177_12_1;
  int pub_r000177_12_2;
  int pub_r000177_13_1;
  int pub_r000177_13_2;
  int pub_r000177_14_1;
  int pub_r000177_14_2;
  int pub_r000177_15_1;
  int pub_r000177_15_2;
  int pub_r000177_16_1;
  int pub_r000177_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000177_0_1 >= (-100)) && (pub_r000177_0_1 <= 100));
  __CPROVER_assume((pub_r000177_0_2 >= (-100)) && (pub_r000177_0_2 <= 100));
  __CPROVER_assume((pub_r000177_1_1 >= (-100)) && (pub_r000177_1_1 <= 100));
  __CPROVER_assume((pub_r000177_1_2 >= (-100)) && (pub_r000177_1_2 <= 100));
  __CPROVER_assume((pub_r000177_2_1 >= (-100)) && (pub_r000177_2_1 <= 100));
  __CPROVER_assume((pub_r000177_2_2 >= (-100)) && (pub_r000177_2_2 <= 100));
  __CPROVER_assume((pub_r000177_3_1 >= (-100)) && (pub_r000177_3_1 <= 100));
  __CPROVER_assume((pub_r000177_3_2 >= (-100)) && (pub_r000177_3_2 <= 100));
  __CPROVER_assume((pub_r000177_4_1 >= (-100)) && (pub_r000177_4_1 <= 100));
  __CPROVER_assume((pub_r000177_4_2 >= (-100)) && (pub_r000177_4_2 <= 100));
  __CPROVER_assume((pub_r000177_5_1 >= (-100)) && (pub_r000177_5_1 <= 100));
  __CPROVER_assume((pub_r000177_5_2 >= (-100)) && (pub_r000177_5_2 <= 100));
  __CPROVER_assume((pub_r000177_6_1 >= (-100)) && (pub_r000177_6_1 <= 100));
  __CPROVER_assume((pub_r000177_6_2 >= (-100)) && (pub_r000177_6_2 <= 100));
  __CPROVER_assume((pub_r000177_7_1 >= (-100)) && (pub_r000177_7_1 <= 100));
  __CPROVER_assume((pub_r000177_7_2 >= (-100)) && (pub_r000177_7_2 <= 100));
  __CPROVER_assume((pub_r000177_8_1 >= (-100)) && (pub_r000177_8_1 <= 100));
  __CPROVER_assume((pub_r000177_8_2 >= (-100)) && (pub_r000177_8_2 <= 100));
  __CPROVER_assume((pub_r000177_9_1 >= (-100)) && (pub_r000177_9_1 <= 100));
  __CPROVER_assume((pub_r000177_9_2 >= (-100)) && (pub_r000177_9_2 <= 100));
  __CPROVER_assume((pub_r000177_10_1 >= (-100)) && (pub_r000177_10_1 <= 100));
  __CPROVER_assume((pub_r000177_10_2 >= (-100)) && (pub_r000177_10_2 <= 100));
  __CPROVER_assume((pub_r000177_11_1 >= (-100)) && (pub_r000177_11_1 <= 100));
  __CPROVER_assume((pub_r000177_11_2 >= (-100)) && (pub_r000177_11_2 <= 100));
  __CPROVER_assume((pub_r000177_12_1 >= (-100)) && (pub_r000177_12_1 <= 100));
  __CPROVER_assume((pub_r000177_12_2 >= (-100)) && (pub_r000177_12_2 <= 100));
  __CPROVER_assume((pub_r000177_13_1 >= (-100)) && (pub_r000177_13_1 <= 100));
  __CPROVER_assume((pub_r000177_13_2 >= (-100)) && (pub_r000177_13_2 <= 100));
  __CPROVER_assume((pub_r000177_14_1 >= (-100)) && (pub_r000177_14_1 <= 100));
  __CPROVER_assume((pub_r000177_14_2 >= (-100)) && (pub_r000177_14_2 <= 100));
  __CPROVER_assume((pub_r000177_15_1 >= (-100)) && (pub_r000177_15_1 <= 100));
  __CPROVER_assume((pub_r000177_15_2 >= (-100)) && (pub_r000177_15_2 <= 100));
  __CPROVER_assume((pub_r000177_16_1 >= (-100)) && (pub_r000177_16_1 <= 100));
  __CPROVER_assume((pub_r000177_16_2 >= (-100)) && (pub_r000177_16_2 <= 100));
  __CPROVER_assume((sec_r000177_0_1 >= 0) && (sec_r000177_0_1 <= 255));
  __CPROVER_assume((sec_r000177_0_2 >= 0) && (sec_r000177_0_2 <= 255));
  __CPROVER_assume((sec_r000177_1_1 >= 0) && (sec_r000177_1_1 <= 255));
  __CPROVER_assume((sec_r000177_1_2 >= 0) && (sec_r000177_1_2 <= 255));
  __CPROVER_assume((sec_r000177_2_1 >= 0) && (sec_r000177_2_1 <= 255));
  __CPROVER_assume((sec_r000177_2_2 >= 0) && (sec_r000177_2_2 <= 255));
  __CPROVER_assume((sec_r000177_3_1 >= 0) && (sec_r000177_3_1 <= 255));
  __CPROVER_assume((sec_r000177_3_2 >= 0) && (sec_r000177_3_2 <= 255));
  __CPROVER_assume((sec_r000177_4_1 >= 0) && (sec_r000177_4_1 <= 255));
  __CPROVER_assume((sec_r000177_4_2 >= 0) && (sec_r000177_4_2 <= 255));
  __CPROVER_assume((sec_r000177_5_1 >= 0) && (sec_r000177_5_1 <= 255));
  __CPROVER_assume((sec_r000177_5_2 >= 0) && (sec_r000177_5_2 <= 255));
  __CPROVER_assume((sec_r000177_6_1 >= 0) && (sec_r000177_6_1 <= 255));
  __CPROVER_assume((sec_r000177_6_2 >= 0) && (sec_r000177_6_2 <= 255));
  __CPROVER_assume((sec_r000177_7_1 >= 0) && (sec_r000177_7_1 <= 255));
  __CPROVER_assume((sec_r000177_7_2 >= 0) && (sec_r000177_7_2 <= 255));
  __CPROVER_assume((sec_r000177_8_1 >= 0) && (sec_r000177_8_1 <= 255));
  __CPROVER_assume((sec_r000177_8_2 >= 0) && (sec_r000177_8_2 <= 255));
  __CPROVER_assume((sec_r000177_9_1 >= 0) && (sec_r000177_9_1 <= 255));
  __CPROVER_assume((sec_r000177_9_2 >= 0) && (sec_r000177_9_2 <= 255));
  __CPROVER_assume((sec_r000177_10_1 >= 0) && (sec_r000177_10_1 <= 255));
  __CPROVER_assume((sec_r000177_10_2 >= 0) && (sec_r000177_10_2 <= 255));
  __CPROVER_assume((sec_r000177_11_1 >= 0) && (sec_r000177_11_1 <= 255));
  __CPROVER_assume((sec_r000177_11_2 >= 0) && (sec_r000177_11_2 <= 255));
  __CPROVER_assume((sec_r000177_12_1 >= 0) && (sec_r000177_12_1 <= 255));
  __CPROVER_assume((sec_r000177_12_2 >= 0) && (sec_r000177_12_2 <= 255));
  __CPROVER_assume((sec_r000177_13_1 >= 0) && (sec_r000177_13_1 <= 255));
  __CPROVER_assume((sec_r000177_13_2 >= 0) && (sec_r000177_13_2 <= 255));
  __CPROVER_assume((sec_r000177_14_1 >= 0) && (sec_r000177_14_1 <= 255));
  __CPROVER_assume((sec_r000177_14_2 >= 0) && (sec_r000177_14_2 <= 255));
  __CPROVER_assume((sec_r000177_15_1 >= 0) && (sec_r000177_15_1 <= 255));
  __CPROVER_assume((sec_r000177_15_2 >= 0) && (sec_r000177_15_2 <= 255));
  struct EventLog_R000177_7713_0 st_var_0_1 = {0};
  struct EventLog_R000177_7713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000177_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000177_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000177_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000177_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000177_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000177_0_2 + 7) & 15;
  struct Vector3D_R000177_7713_1 st_var_1_1 = {0};
  struct Vector3D_R000177_7713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000177_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000177_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000177_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000177_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000177_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000177_0_2 + 9) & 15;
  union ColorPixel_R000177_7713_0 u_var_1;
  union ColorPixel_R000177_7713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 47)
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
  if (stage_v_1_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 47)
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
  int stage_v_3_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (8 & 31);
  int stage_v_3_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (8 & 31);
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= (stage_v_3_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_3_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = (st_var_0_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_0_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 8) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 10) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 12) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_1_2.buffer[2] * 3) & 63;
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
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = ((st_var_0_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_0_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 36)
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
  if (stage_v_14_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 36)
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
  int stage_v_15_1 = ((st_var_1_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_1_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 49)
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
  if (stage_v_15_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 49)
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
  int stage_v_16_1 = (st_var_0_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_0_2.buffer[0] ^ 19) & 3;
  switch (stage_v_16_1)
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

  switch (stage_v_16_2)
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

  int stage_v_17_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (22 & 31);
  int stage_v_17_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (22 & 31);
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= (stage_v_17_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_17_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
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
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 23) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 24) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 25) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 25) & 15;
  int stage_v_24_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_24_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= stage_v_24_1;
  chk_sum_2 ^= stage_v_24_2;
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 27) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
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
  if (stage_v_33_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 54)
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
  if (stage_v_33_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 54)
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
  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 39) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  int stage_v_39_1 = ((st_var_1_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_1_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 25)
    {
      chk_sum_1 ^= stage_v_39_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_39_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 25)
    {
      chk_sum_2 ^= stage_v_39_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_40_1 = (st_var_0_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_0_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 35)
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
  if (stage_v_41_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 35)
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
  int stage_v_44_1 = (st_var_0_1.buffer[0] ^ 47) & 3;
  int stage_v_44_2 = (st_var_0_2.buffer[0] ^ 47) & 3;
  switch (stage_v_44_1)
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

  switch (stage_v_44_2)
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
  if (stage_v_47_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 27)
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
  if (stage_v_47_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 27)
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
  int stage_v_48_1 = ((st_var_0_1.buffer[0] * 2) + 151) & 63;
  int stage_v_48_2 = ((st_var_0_2.buffer[0] * 2) + 151) & 63;
  if (stage_v_48_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_48_1) - 5) & 255;
    if (stage_v_48_1 > 48)
    {
      chk_sum_1 ^= stage_v_48_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_48_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_48_2) - 5) & 255;
    if (stage_v_48_2 > 48)
    {
      chk_sum_2 ^= stage_v_48_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_49_1 = (st_var_1_1.buffer[0] ^ 52) & 3;
  int stage_v_49_2 = (st_var_1_2.buffer[0] ^ 52) & 3;
  switch (stage_v_49_1)
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

  switch (stage_v_49_2)
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

  int stage_v_50_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (55 & 31);
  int stage_v_50_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (55 & 31);
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= (stage_v_50_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_50_2 << 1) & 127;
  int stage_v_51_1 = (st_var_1_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_1_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  int stage_v_52_1 = table_1[0];
  int stage_v_52_2 = table_2[0];
  table_1[0] = (table_1[1] + 105) & 63;
  table_2[0] = (table_2[1] + 105) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 55) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 55) & 15;
  int stage_v_54_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_54_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= stage_v_54_1;
  chk_sum_2 ^= stage_v_54_2;
  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (st_var_0_1.buffer[0] ^ 59) & 3;
  int stage_v_56_2 = (st_var_0_2.buffer[0] ^ 59) & 3;
  switch (stage_v_56_1)
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

  switch (stage_v_56_2)
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

  int stage_v_57_1 = ((st_var_1_1.buffer[0] * 2) + 178) & 63;
  int stage_v_57_2 = ((st_var_1_2.buffer[0] * 2) + 178) & 63;
  if (stage_v_57_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_57_1) - 5) & 255;
    if (stage_v_57_1 > 34)
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
  if (stage_v_57_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_57_2) - 5) & 255;
    if (stage_v_57_2 > 34)
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
  int stage_v_58_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (63 & 31);
  int stage_v_58_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (63 & 31);
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= (stage_v_58_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_58_2 << 1) & 127;
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
  int stage_v_61_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (66 & 31);
  int stage_v_61_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (66 & 31);
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= (stage_v_61_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_61_2 << 1) & 127;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
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
  int stage_v_65_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_65_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_65_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_65_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((st_var_1_1.buffer[1] * 2) + 208) & 63;
  int stage_v_67_2 = ((st_var_1_2.buffer[1] * 2) + 208) & 63;
  if (stage_v_67_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_67_1) - 5) & 255;
    if (stage_v_67_1 > 51)
    {
      chk_sum_1 ^= stage_v_67_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_67_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_67_2) - 5) & 255;
    if (stage_v_67_2 > 51)
    {
      chk_sum_2 ^= stage_v_67_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_68_1 = (st_var_0_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_0_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
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

  switch (stage_v_68_2)
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

  int stage_v_69_1 = (st_var_1_1.buffer[0] ^ 72) & 3;
  int stage_v_69_2 = (st_var_1_2.buffer[0] ^ 72) & 3;
  switch (stage_v_69_1)
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

  switch (stage_v_69_2)
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

  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((sec_r000177_0_1 & 1) != 0)
  {
    if ((sec_r000177_12_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000177_14_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000177_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000177_14_1 + 7) & 127;
  }
  if ((sec_r000177_0_2 & 1) != 0)
  {
    if ((sec_r000177_12_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000177_14_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000177_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000177_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000177_3_1 & 1) != 0)
  {
    if ((sec_r000177_15_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000177_14_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000177_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000177_14_1 + 7) & 127;
  }
  if ((sec_r000177_3_2 & 1) != 0)
  {
    if ((sec_r000177_15_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000177_14_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000177_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000177_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000177_8_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000177_8_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000177_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000177_8_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000177_8_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000177_8_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000177_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000177_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000177_7_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000177_5_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000177_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000177_5_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000177_7_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000177_5_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000177_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000177_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000177_6_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000177_14_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000177_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000177_14_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000177_6_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000177_14_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000177_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000177_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000177_12_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000177_3_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000177_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000177_3_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000177_12_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000177_3_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000177_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000177_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000177_12_1 & 1) != 0)
  {
    if ((sec_r000177_7_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000177_14_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000177_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000177_14_1 + 7) & 127;
  }
  if ((sec_r000177_12_2 & 1) != 0)
  {
    if ((sec_r000177_7_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000177_14_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000177_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000177_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000177_5_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000177_7_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000177_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000177_7_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000177_5_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000177_7_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000177_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000177_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000177_1_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000177_2_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000177_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000177_2_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000177_1_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000177_2_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000177_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000177_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000177_1_1 & 1) != 0)
  {
    if ((sec_r000177_6_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000177_12_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000177_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000177_12_1 + 7) & 127;
  }
  if ((sec_r000177_1_2 & 1) != 0)
  {
    if ((sec_r000177_6_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000177_12_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000177_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000177_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000177_4_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000177_12_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000177_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000177_12_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000177_4_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000177_12_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000177_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000177_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000177_4_1 & 1) != 0)
  {
    if ((sec_r000177_14_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000177_2_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000177_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000177_2_1 + 7) & 127;
  }
  if ((sec_r000177_4_2 & 1) != 0)
  {
    if ((sec_r000177_14_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000177_2_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000177_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000177_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000177_1_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000177_8_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000177_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000177_8_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000177_1_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000177_8_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000177_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000177_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000177_2_1 & 1) != 0)
  {
    if ((sec_r000177_8_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000177_9_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000177_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000177_9_1 + 7) & 127;
  }
  if ((sec_r000177_2_2 & 1) != 0)
  {
    if ((sec_r000177_8_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000177_9_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000177_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000177_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000177_8_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000177_1_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000177_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000177_1_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000177_8_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000177_1_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000177_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000177_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000177_9_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000177_6_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000177_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000177_6_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000177_9_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000177_6_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000177_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000177_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000177_5_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000177_14_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000177_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000177_14_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000177_5_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000177_14_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000177_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000177_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000177_9_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000177_5_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000177_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000177_5_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000177_9_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000177_5_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000177_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000177_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000177_0_1 & 1) != 0)
  {
    if ((sec_r000177_15_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000177_9_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000177_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000177_9_1 + 7) & 127;
  }
  if ((sec_r000177_0_2 & 1) != 0)
  {
    if ((sec_r000177_15_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000177_9_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000177_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000177_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000177_14_1 & 1) != 0)
  {
    if ((sec_r000177_9_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000177_9_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000177_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000177_9_1 + 7) & 127;
  }
  if ((sec_r000177_14_2 & 1) != 0)
  {
    if ((sec_r000177_9_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000177_9_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000177_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000177_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000177_12_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000177_8_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000177_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000177_8_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000177_12_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000177_8_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000177_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000177_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000177_0_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000177_7_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000177_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000177_7_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000177_0_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000177_7_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000177_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000177_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000177_9_1 & 1) != 0)
  {
    if ((sec_r000177_8_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000177_16_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000177_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000177_16_1 + 7) & 127;
  }
  if ((sec_r000177_9_2 & 1) != 0)
  {
    if ((sec_r000177_8_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000177_16_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000177_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000177_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000177_14_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000177_13_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000177_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000177_13_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000177_14_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000177_13_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000177_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000177_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000177_15_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000177_13_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000177_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000177_13_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000177_15_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000177_13_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000177_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000177_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000177_8_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000177_12_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000177_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000177_12_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000177_8_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000177_12_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000177_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000177_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000177_13_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000177_9_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000177_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000177_9_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000177_13_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000177_9_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000177_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000177_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000177_13_1 & 1) != 0)
  {
    if ((sec_r000177_11_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000177_15_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000177_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000177_15_1 + 7) & 127;
  }
  if ((sec_r000177_13_2 & 1) != 0)
  {
    if ((sec_r000177_11_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000177_15_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000177_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000177_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000177_7_1 & 1) != 0)
  {
    if ((sec_r000177_8_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000177_4_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000177_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000177_4_1 + 7) & 127;
  }
  if ((sec_r000177_7_2 & 1) != 0)
  {
    if ((sec_r000177_8_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000177_4_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000177_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000177_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000177_6_1 & 1) != 0)
  {
    if ((sec_r000177_3_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000177_8_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000177_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000177_8_1 + 7) & 127;
  }
  if ((sec_r000177_6_2 & 1) != 0)
  {
    if ((sec_r000177_3_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000177_8_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000177_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000177_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000177_11_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000177_10_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000177_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000177_10_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000177_11_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000177_10_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000177_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000177_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000177_14_1 & 1) != 0)
  {
    if ((sec_r000177_10_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000177_12_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000177_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000177_12_1 + 7) & 127;
  }
  if ((sec_r000177_14_2 & 1) != 0)
  {
    if ((sec_r000177_10_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000177_12_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000177_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000177_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000177_11_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000177_2_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000177_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000177_2_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000177_11_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000177_2_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000177_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000177_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000177_15_1 & 1) != 0)
  {
    if ((sec_r000177_14_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000177_12_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000177_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000177_12_1 + 7) & 127;
  }
  if ((sec_r000177_15_2 & 1) != 0)
  {
    if ((sec_r000177_14_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000177_12_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000177_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000177_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000177_4_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000177_8_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000177_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000177_8_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000177_4_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000177_8_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000177_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000177_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000177_8_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000177_5_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000177_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000177_5_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000177_8_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000177_5_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000177_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000177_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000177_2_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000177_7_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000177_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000177_7_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000177_2_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000177_7_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000177_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000177_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000177_8_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000177_0_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000177_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000177_0_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000177_8_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000177_0_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000177_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000177_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000177_5_1 & 1) != 0)
  {
    if ((sec_r000177_8_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000177_12_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000177_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000177_12_1 + 7) & 127;
  }
  if ((sec_r000177_5_2 & 1) != 0)
  {
    if ((sec_r000177_8_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000177_12_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000177_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000177_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000177_11_1 & 1) != 0)
  {
    if ((sec_r000177_7_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000177_10_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000177_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000177_10_1 + 7) & 127;
  }
  if ((sec_r000177_11_2 & 1) != 0)
  {
    if ((sec_r000177_7_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000177_10_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000177_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000177_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000177_15_1 & 1) != 0)
  {
    if ((sec_r000177_10_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000177_6_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000177_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000177_6_1 + 7) & 127;
  }
  if ((sec_r000177_15_2 & 1) != 0)
  {
    if ((sec_r000177_10_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000177_6_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000177_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000177_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000177_7_1 & 1) != 0)
  {
    if ((sec_r000177_3_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000177_10_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000177_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000177_10_1 + 7) & 127;
  }
  if ((sec_r000177_7_2 & 1) != 0)
  {
    if ((sec_r000177_3_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000177_10_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000177_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000177_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000177_1_1 & 1) != 0)
  {
    if ((sec_r000177_5_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000177_8_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000177_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000177_8_1 + 7) & 127;
  }
  if ((sec_r000177_1_2 & 1) != 0)
  {
    if ((sec_r000177_5_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000177_8_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000177_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000177_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000177_11_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000177_2_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000177_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000177_2_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000177_11_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000177_2_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000177_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000177_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000177_3_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000177_0_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000177_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000177_0_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000177_3_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000177_0_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000177_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000177_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000177_9_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000177_9_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000177_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000177_9_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000177_9_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000177_9_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000177_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000177_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000177_8_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000177_8_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000177_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000177_8_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000177_8_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000177_8_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000177_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000177_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000177_4_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000177_5_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000177_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000177_5_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000177_4_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000177_5_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000177_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000177_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000177_7_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000177_7_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000177_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000177_7_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000177_7_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000177_7_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000177_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000177_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000177_4_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000177_8_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000177_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000177_8_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000177_4_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000177_8_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000177_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000177_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000177_7_1 & 1) != 0)
  {
    if ((sec_r000177_9_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000177_5_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000177_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000177_5_1 + 7) & 127;
  }
  if ((sec_r000177_7_2 & 1) != 0)
  {
    if ((sec_r000177_9_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000177_5_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000177_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000177_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000177_15_1 & 1) != 0)
  {
    if ((sec_r000177_7_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000177_3_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000177_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000177_3_1 + 7) & 127;
  }
  if ((sec_r000177_15_2 & 1) != 0)
  {
    if ((sec_r000177_7_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000177_3_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000177_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000177_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000177_1_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000177_10_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000177_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000177_10_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000177_1_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000177_10_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000177_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000177_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000177_8_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000177_1_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000177_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000177_1_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000177_8_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000177_1_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000177_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000177_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000177_8_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000177_7_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000177_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000177_7_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000177_8_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000177_7_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000177_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000177_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000177_12_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000177_15_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000177_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000177_15_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000177_12_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000177_15_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000177_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000177_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000177_2_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000177_6_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000177_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000177_6_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000177_2_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000177_6_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000177_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000177_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000177_3_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000177_15_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000177_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000177_15_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000177_3_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000177_15_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000177_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000177_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((sec_r000177_2_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000177_0_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000177_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000177_0_1 + 7) & 127;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((sec_r000177_2_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000177_0_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000177_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000177_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000177_7_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000177_15_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000177_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000177_15_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000177_7_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000177_15_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000177_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000177_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000177_15_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000177_14_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000177_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000177_14_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000177_15_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000177_14_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000177_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000177_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000177_4_1 & 1) != 0)
  {
    if ((sec_r000177_13_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000177_4_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000177_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000177_4_1 + 7) & 127;
  }
  if ((sec_r000177_4_2 & 1) != 0)
  {
    if ((sec_r000177_13_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000177_4_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000177_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000177_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000177_2_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000177_8_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000177_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000177_8_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000177_2_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000177_8_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000177_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000177_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((sec_r000177_3_1 & 1) != 0)
  {
    if ((sec_r000177_0_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000177_5_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000177_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000177_5_1 + 7) & 127;
  }
  if ((sec_r000177_3_2 & 1) != 0)
  {
    if ((sec_r000177_0_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000177_5_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000177_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000177_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000177_6_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000177_14_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000177_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000177_14_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000177_6_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000177_14_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000177_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000177_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000177_12_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000177_8_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000177_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000177_8_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000177_12_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000177_8_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000177_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000177_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000177_1_1 & 1) != 0)
  {
    if ((sec_r000177_10_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000177_6_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000177_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000177_6_1 + 7) & 127;
  }
  if ((sec_r000177_1_2 & 1) != 0)
  {
    if ((sec_r000177_10_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000177_6_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000177_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000177_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000177_7_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000177_8_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000177_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000177_8_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000177_7_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000177_8_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000177_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000177_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000177_15_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000177_5_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000177_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000177_5_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000177_15_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000177_5_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000177_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000177_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000177_11_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000177_3_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000177_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000177_3_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000177_11_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000177_3_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000177_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000177_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_137_1 & 1) != 0)
  {
    if ((sec_r000177_2_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000177_15_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000177_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000177_15_1 + 7) & 127;
  }
  if ((stage_v_137_2 & 1) != 0)
  {
    if ((sec_r000177_2_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000177_15_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000177_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000177_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000177_7_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000177_3_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000177_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000177_3_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000177_7_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000177_3_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000177_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000177_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((sec_r000177_9_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000177_3_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000177_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000177_3_1 + 7) & 127;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((sec_r000177_9_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000177_3_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000177_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000177_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000177_4_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000177_10_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000177_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000177_10_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000177_4_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000177_10_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000177_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000177_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000177_12_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000177_12_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000177_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000177_12_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000177_12_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000177_12_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000177_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000177_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000177_0_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000177_8_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000177_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000177_8_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000177_0_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000177_8_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000177_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000177_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((sec_r000177_6_1 & 1) != 0)
  {
    if ((sec_r000177_12_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000177_5_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000177_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000177_5_1 + 7) & 127;
  }
  if ((sec_r000177_6_2 & 1) != 0)
  {
    if ((sec_r000177_12_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000177_5_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000177_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000177_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((sec_r000177_9_1 & 1) != 0)
  {
    if ((sec_r000177_1_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000177_11_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000177_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000177_11_1 + 7) & 127;
  }
  if ((sec_r000177_9_2 & 1) != 0)
  {
    if ((sec_r000177_1_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000177_11_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000177_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000177_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((sec_r000177_2_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000177_4_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000177_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000177_4_1 + 7) & 127;
  }
  if ((stage_v_146_2 & 1) != 0)
  {
    if ((sec_r000177_2_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000177_4_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000177_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000177_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r000177_6_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000177_6_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000177_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000177_6_1 + 7) & 127;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r000177_6_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000177_6_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000177_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000177_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r000177_2_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000177_5_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000177_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000177_5_1 + 7) & 127;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r000177_2_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000177_5_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000177_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000177_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000177_13_1 & 1) != 0)
  {
    if ((sec_r000177_12_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000177_13_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000177_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000177_13_1 + 7) & 127;
  }
  if ((sec_r000177_13_2 & 1) != 0)
  {
    if ((sec_r000177_12_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000177_13_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000177_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000177_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((sec_r000177_1_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000177_7_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000177_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000177_7_1 + 7) & 127;
  }
  if ((stage_v_144_2 & 1) != 0)
  {
    if ((sec_r000177_1_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000177_7_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000177_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000177_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000177_12_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000177_9_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000177_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000177_9_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000177_12_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000177_9_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000177_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000177_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((sec_r000177_15_1 & 1) != 0)
  {
    if ((sec_r000177_8_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000177_14_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000177_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000177_14_1 + 7) & 127;
  }
  if ((sec_r000177_15_2 & 1) != 0)
  {
    if ((sec_r000177_8_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000177_14_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000177_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000177_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((sec_r000177_15_1 & 1) != 0)
  {
    if ((sec_r000177_4_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000177_14_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000177_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000177_14_1 + 7) & 127;
  }
  if ((sec_r000177_15_2 & 1) != 0)
  {
    if ((sec_r000177_4_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000177_14_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000177_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000177_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((sec_r000177_1_1 & 1) != 0)
  {
    if ((sec_r000177_4_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000177_5_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000177_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000177_5_1 + 7) & 127;
  }
  if ((sec_r000177_1_2 & 1) != 0)
  {
    if ((sec_r000177_4_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000177_5_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000177_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000177_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((sec_r000177_15_1 & 1) != 0)
  {
    if ((sec_r000177_3_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000177_14_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000177_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000177_14_1 + 7) & 127;
  }
  if ((sec_r000177_15_2 & 1) != 0)
  {
    if ((sec_r000177_3_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000177_14_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000177_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000177_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000177_4_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000177_1_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000177_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000177_1_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000177_4_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000177_1_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000177_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000177_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r000177_2_1 & 2) != 0)
    {
      stage_v_159_1 = (pub_r000177_10_1 + 31) & 127;
    }
    else
    {
      stage_v_159_1 = (pub_r000177_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_1 = (pub_r000177_10_1 + 7) & 127;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r000177_2_2 & 2) != 0)
    {
      stage_v_159_2 = (pub_r000177_10_2 + 31) & 127;
    }
    else
    {
      stage_v_159_2 = (pub_r000177_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_2 = (pub_r000177_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000177_12_1 & 2) != 0)
    {
      stage_v_160_1 = (pub_r000177_15_1 + 31) & 127;
    }
    else
    {
      stage_v_160_1 = (pub_r000177_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_1 = (pub_r000177_15_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000177_12_2 & 2) != 0)
    {
      stage_v_160_2 = (pub_r000177_15_2 + 31) & 127;
    }
    else
    {
      stage_v_160_2 = (pub_r000177_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_2 = (pub_r000177_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000177_13_1 & 2) != 0)
    {
      stage_v_161_1 = (pub_r000177_3_1 + 31) & 127;
    }
    else
    {
      stage_v_161_1 = (pub_r000177_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_1 = (pub_r000177_3_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000177_13_2 & 2) != 0)
    {
      stage_v_161_2 = (pub_r000177_3_2 + 31) & 127;
    }
    else
    {
      stage_v_161_2 = (pub_r000177_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_2 = (pub_r000177_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000177_2_1 & 2) != 0)
    {
      stage_v_162_1 = (pub_r000177_4_1 + 31) & 127;
    }
    else
    {
      stage_v_162_1 = (pub_r000177_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_1 = (pub_r000177_4_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000177_2_2 & 2) != 0)
    {
      stage_v_162_2 = (pub_r000177_4_2 + 31) & 127;
    }
    else
    {
      stage_v_162_2 = (pub_r000177_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_2 = (pub_r000177_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000177_7_1 & 2) != 0)
    {
      stage_v_163_1 = (pub_r000177_13_1 + 31) & 127;
    }
    else
    {
      stage_v_163_1 = (pub_r000177_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_1 = (pub_r000177_13_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000177_7_2 & 2) != 0)
    {
      stage_v_163_2 = (pub_r000177_13_2 + 31) & 127;
    }
    else
    {
      stage_v_163_2 = (pub_r000177_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_2 = (pub_r000177_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  if ((sec_r000177_12_1 & 1) != 0)
  {
    if ((sec_r000177_11_1 & 2) != 0)
    {
      stage_v_164_1 = (pub_r000177_0_1 + 31) & 127;
    }
    else
    {
      stage_v_164_1 = (pub_r000177_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_1 = (pub_r000177_0_1 + 7) & 127;
  }
  if ((sec_r000177_12_2 & 1) != 0)
  {
    if ((sec_r000177_11_2 & 2) != 0)
    {
      stage_v_164_2 = (pub_r000177_0_2 + 31) & 127;
    }
    else
    {
      stage_v_164_2 = (pub_r000177_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_2 = (pub_r000177_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000177_11_1 & 2) != 0)
    {
      stage_v_165_1 = (pub_r000177_7_1 + 31) & 127;
    }
    else
    {
      stage_v_165_1 = (pub_r000177_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_1 = (pub_r000177_7_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000177_11_2 & 2) != 0)
    {
      stage_v_165_2 = (pub_r000177_7_2 + 31) & 127;
    }
    else
    {
      stage_v_165_2 = (pub_r000177_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_2 = (pub_r000177_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000177_0_1 & 2) != 0)
    {
      stage_v_166_1 = (pub_r000177_2_1 + 31) & 127;
    }
    else
    {
      stage_v_166_1 = (pub_r000177_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_1 = (pub_r000177_2_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000177_0_2 & 2) != 0)
    {
      stage_v_166_2 = (pub_r000177_2_2 + 31) & 127;
    }
    else
    {
      stage_v_166_2 = (pub_r000177_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_2 = (pub_r000177_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((sec_r000177_3_1 & 2) != 0)
    {
      stage_v_167_1 = (pub_r000177_8_1 + 31) & 127;
    }
    else
    {
      stage_v_167_1 = (pub_r000177_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_1 = (pub_r000177_8_1 + 7) & 127;
  }
  if ((stage_v_154_2 & 1) != 0)
  {
    if ((sec_r000177_3_2 & 2) != 0)
    {
      stage_v_167_2 = (pub_r000177_8_2 + 31) & 127;
    }
    else
    {
      stage_v_167_2 = (pub_r000177_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_2 = (pub_r000177_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000177_5_1 == pub_r000177_5_2);
  __CPROVER_assume(sec_r000177_7_1 != sec_r000177_7_2);
  __CPROVER_assume(sec_r000177_12_1 != sec_r000177_12_2);
  __CPROVER_assume(sec_r000177_15_1 != sec_r000177_15_2);
  __CPROVER_assume(sec_r000177_5_1 != sec_r000177_5_2);
  __CPROVER_assume(pub_r000177_4_1 == pub_r000177_4_2);
  __CPROVER_assume(pub_r000177_16_1 == pub_r000177_16_2);
  __CPROVER_assume(sec_r000177_9_1 != sec_r000177_9_2);
  __CPROVER_assume(pub_r000177_13_1 == pub_r000177_13_2);
  __CPROVER_assume(pub_r000177_6_1 == pub_r000177_6_2);
  __CPROVER_assume(sec_r000177_6_1 != sec_r000177_6_2);
  __CPROVER_assume(pub_r000177_14_1 == pub_r000177_14_2);
  __CPROVER_assume(pub_r000177_8_1 == pub_r000177_8_2);
  __CPROVER_assume(sec_r000177_10_1 != sec_r000177_10_2);
  __CPROVER_assume(pub_r000177_2_1 == pub_r000177_2_2);
  __CPROVER_assume(sec_r000177_1_1 != sec_r000177_1_2);
  __CPROVER_assume(pub_r000177_15_1 == pub_r000177_15_2);
  __CPROVER_assume(sec_r000177_0_1 != sec_r000177_0_2);
  __CPROVER_assume(pub_r000177_1_1 == pub_r000177_1_2);
  __CPROVER_assume(pub_r000177_12_1 == pub_r000177_12_2);
  __CPROVER_assume(pub_r000177_11_1 == pub_r000177_11_2);
  __CPROVER_assume(sec_r000177_13_1 != sec_r000177_13_2);
  __CPROVER_assume(sec_r000177_14_1 != sec_r000177_14_2);
  __CPROVER_assume(sec_r000177_8_1 != sec_r000177_8_2);
  __CPROVER_assume(pub_r000177_9_1 == pub_r000177_9_2);
  __CPROVER_assume(sec_r000177_3_1 != sec_r000177_3_2);
  __CPROVER_assume(sec_r000177_11_1 != sec_r000177_11_2);
  __CPROVER_assume(pub_r000177_3_1 == pub_r000177_3_2);
  __CPROVER_assume(pub_r000177_10_1 == pub_r000177_10_2);
  __CPROVER_assume(sec_r000177_4_1 != sec_r000177_4_2);
  __CPROVER_assume(pub_r000177_0_1 == pub_r000177_0_2);
  __CPROVER_assume(sec_r000177_2_1 != sec_r000177_2_2);
  __CPROVER_assume(pub_r000177_7_1 == pub_r000177_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.heading == st_var_1_2.heading);
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
}


