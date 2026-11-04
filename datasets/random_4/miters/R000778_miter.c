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
struct FilterState_R000778_7813_0
{
  int prev_out;
  unsigned char cutoff;
  short damping;
  int mode;
  int prev_in;
  int gain_db;
  int buffer[3];
};
struct Vector3D_R000778_7813_1
{
  int coord_x;
  unsigned char heading;
  int coord_z;
  unsigned char pitch;
  int buffer[3];
};
struct SensorNode_R000778_7813_2
{
  short threshold;
  short offset;
  int reading;
  int buffer[3];
};
struct DeviceConfig_R000778_7813_3
{
  int id;
  short parity;
  int baud_rate;
  unsigned char timeout;
  short port;
  int buffer[3];
};
union ColorPixel_R000778_7813_0
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
void fn_R000778_7813_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000778_7813_1 st_1 = {0};
  struct Vector3D_R000778_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int vector_29_1 = 0;
  int vector_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_29_1 = ((vector_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_29_2 = ((vector_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_29_1) & 127;
    acc_2 = (acc_2 + vector_29_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_73_1 = local_arr_1[aux_1 % 3];
  int parity_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_73_2 * 2)) & 127;
  int parity_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_77_1 > 20)
  {
    acc_1 = ((acc_1 + (parity_77_1 * 2)) + 5) & 127;
    aux_1 ^= parity_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_77_2 > 20)
  {
    acc_2 = ((acc_2 + (parity_77_2 * 2)) + 5) & 127;
    aux_2 ^= parity_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_77_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_29_1 == vector_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_73_1 == parity_73_2);
  assert(parity_77_1 == parity_77_2);
}

int fn_R000778_7813_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000778_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int vector_29 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_29 = ((vector_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_29) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int parity_73 = local_arr[aux % 3];
  acc = (acc + (parity_73 * 2)) & 127;
  int parity_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_77 > 20)
  {
    acc = ((acc + (parity_77 * 2)) + 5) & 127;
    aux ^= parity_77 & 15;
  }
  else
  {
    acc = ((acc - parity_77) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000778_7813_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000778_7813_1 st_1 = {0};
  struct Vector3D_R000778_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int scale_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_87_1 > 20)
  {
    acc_1 = ((acc_1 + (scale_87_1 * 2)) + 5) & 127;
    aux_1 ^= scale_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_87_2 > 20)
  {
    acc_2 = ((acc_2 + (scale_87_2 * 2)) + 5) & 127;
    aux_2 ^= scale_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_89_1 = local_arr_1[aux_1 % 3];
  int residue_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_89_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_13_1)
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

  switch (phase_13_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_87_1 == scale_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_89_1 == residue_89_2);
  assert(phase_13_1 == phase_13_2);
}

int fn_R000778_7813_1(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000778_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int scale_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_87 > 20)
  {
    acc = ((acc + (scale_87 * 2)) + 5) & 127;
    aux ^= scale_87 & 15;
  }
  else
  {
    acc = ((acc - scale_87) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_89 = local_arr[aux % 3];
  acc = (acc + (residue_89 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_13 = (aux + st.buffer[1]) & 3;
  switch (phase_13)
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

void fn_R000778_7813_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000778_7813_3 st_1 = {0};
  struct DeviceConfig_R000778_7813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int delta_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_85_1) & 63;
  aux_2 = (aux_2 + delta_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_79_1 > 34)
  {
    acc_1 = ((acc_1 + (pivot_79_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_79_2 > 34)
  {
    acc_2 = ((acc_2 + (pivot_79_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_35_1 = 0;
  int window_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_35_1 = ((window_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_35_2 = ((window_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_35_1) & 127;
    acc_2 = (acc_2 + window_35_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_85_1 == delta_85_2);
  assert(pivot_79_1 == pivot_79_2);
  assert(window_35_1 == window_35_2);
}

int fn_R000778_7813_2(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000778_7813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int delta_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_85) & 63;
  acc ^= aux;
  int pivot_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_79 > 34)
  {
    acc = ((acc + (pivot_79 * 2)) + 5) & 127;
    aux ^= pivot_79 & 15;
  }
  else
  {
    acc = ((acc - pivot_79) + 11) & 127;
    aux += 3;
  }
  int window_35 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_35 = ((window_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_35) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000778_7813_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000778_7813_2 st_1 = {0};
  struct SensorNode_R000778_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_11_1 = local_arr_1[aux_1 % 3];
  int index_reg_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_11_2 * 2)) & 127;
  int metric_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_97_1) & 63;
  aux_2 = (aux_2 + metric_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_31_1)
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

  switch (coefficient_31_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_11_1 == index_reg_11_2);
  assert(metric_97_1 == metric_97_2);
  assert(coefficient_31_1 == coefficient_31_2);
}

int fn_R000778_7813_3(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000778_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int index_reg_11 = local_arr[aux % 3];
  acc = (acc + (index_reg_11 * 2)) & 127;
  int metric_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_97) & 63;
  acc ^= aux;
  int coefficient_31 = (aux + st.buffer[1]) & 3;
  switch (coefficient_31)
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

void fn_R000778_7813_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000778_7813_1 st_1 = {0};
  struct Vector3D_R000778_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int threshold_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_22_1 > 44)
  {
    acc_1 = ((acc_1 + (threshold_22_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_22_2 > 44)
  {
    acc_2 = ((acc_2 + (threshold_22_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_30_1)
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

  switch (stride_30_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_22_1 == threshold_22_2);
  assert(stride_30_1 == stride_30_2);
}

int fn_R000778_7813_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000778_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int threshold_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_22 > 44)
  {
    acc = ((acc + (threshold_22 * 2)) + 5) & 127;
    aux ^= threshold_22 & 15;
  }
  else
  {
    acc = ((acc - threshold_22) + 11) & 127;
    aux += 3;
  }
  int stride_30 = (aux + st.buffer[1]) & 3;
  switch (stride_30)
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

void fn_R000778_7813_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000778_7813_1 st_1 = {0};
  struct Vector3D_R000778_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int mask_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_52_1) & 63;
  aux_2 = (aux_2 + mask_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_94_1 > 21)
  {
    acc_1 = ((acc_1 + (offset_94_1 * 2)) + 5) & 127;
    aux_1 ^= offset_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_94_2 > 21)
  {
    acc_2 = ((acc_2 + (offset_94_2 * 2)) + 5) & 127;
    aux_2 ^= offset_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_94_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_52_1 == mask_52_2);
  assert(offset_94_1 == offset_94_2);
}

int fn_R000778_7813_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000778_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int mask_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_52) & 63;
  acc ^= aux;
  int offset_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_94 > 21)
  {
    acc = ((acc + (offset_94 * 2)) + 5) & 127;
    aux ^= offset_94 & 15;
  }
  else
  {
    acc = ((acc - offset_94) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000778_7813_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000778_7813_3 st_1 = {0};
  struct DeviceConfig_R000778_7813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int checksum_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_81_1)
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

  switch (checksum_81_2)
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
  int cursor_35_1 = local_arr_1[aux_1 % 3];
  int cursor_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_35_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_81_1 == checksum_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_35_1 == cursor_35_2);
}

int fn_R000778_7813_6(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000778_7813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int checksum_81 = (aux + st.buffer[1]) & 3;
  switch (checksum_81)
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
  int cursor_35 = local_arr[aux % 3];
  acc = (acc + (cursor_35 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000778_7813_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000778_7813_3 st_1 = {0};
  struct DeviceConfig_R000778_7813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_31_1 = local_arr_1[aux_1 % 3];
  int accumulator_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_31_2 * 2)) & 127;
  int checksum_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_47_1) & 63;
  aux_2 = (aux_2 + checksum_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_31_1 == accumulator_31_2);
  assert(checksum_47_1 == checksum_47_2);
}

int fn_R000778_7813_7(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000778_7813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int accumulator_31 = local_arr[aux % 3];
  acc = (acc + (accumulator_31 * 2)) & 127;
  int checksum_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000778_7813_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000778_7813_1 st_1 = {0};
  struct Vector3D_R000778_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int window_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_23_1)
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

  switch (window_23_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_76_1 = 0;
  int margin_76_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_76_1 = ((margin_76_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_76_2 = ((margin_76_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_76_1) & 127;
    acc_2 = (acc_2 + margin_76_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_23_1 == window_23_2);
  assert(margin_76_1 == margin_76_2);
}

int fn_R000778_7813_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000778_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int window_23 = (aux + st.buffer[1]) & 3;
  switch (window_23)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_76 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_76 = ((margin_76 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_76) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000778_7813_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000778_7813_0 st_1 = {0};
  struct FilterState_R000778_7813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int margin_44_1 = 0;
  int margin_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_44_1 = ((margin_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_44_2 = ((margin_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_44_1) & 127;
    acc_2 = (acc_2 + margin_44_2) & 127;
  }

  int anchor_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_60_1 > 35)
  {
    acc_1 = ((acc_1 + (anchor_60_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_60_2 > 35)
  {
    acc_2 = ((acc_2 + (anchor_60_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_60_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_44_1 == margin_44_2);
  assert(anchor_60_1 == anchor_60_2);
}

int fn_R000778_7813_9(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000778_7813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int margin_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_44 = ((margin_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_44) & 127;
  }

  int anchor_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_60 > 35)
  {
    acc = ((acc + (anchor_60 * 2)) + 5) & 127;
    aux ^= anchor_60 & 15;
  }
  else
  {
    acc = ((acc - anchor_60) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000778_7813_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000778_7813_0 st_1 = {0};
  struct FilterState_R000778_7813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int threshold_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_44_1) & 63;
  aux_2 = (aux_2 + threshold_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_67_1)
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

  switch (delta_67_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_44_1 == threshold_44_2);
  assert(delta_67_1 == delta_67_2);
}

int fn_R000778_7813_10(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000778_7813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int threshold_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_44) & 63;
  acc ^= aux;
  int delta_67 = (aux + st.buffer[1]) & 3;
  switch (delta_67)
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

void fn_R000778_7813_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000778_7813_0 st_1 = {0};
  struct FilterState_R000778_7813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int tracker_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_60_1 > 38)
  {
    acc_1 = ((acc_1 + (tracker_60_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_60_2 > 38)
  {
    acc_2 = ((acc_2 + (tracker_60_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_30_1) & 63;
  aux_2 = (aux_2 + factor_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_19_1 = 0;
  int tracker_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_19_1 = ((tracker_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_19_2 = ((tracker_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_19_1) & 127;
    acc_2 = (acc_2 + tracker_19_2) & 127;
  }

  int anchor_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_95_1)
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

  switch (anchor_95_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_60_1 == tracker_60_2);
  assert(factor_30_1 == factor_30_2);
  assert(tracker_19_1 == tracker_19_2);
  assert(anchor_95_1 == anchor_95_2);
}

int fn_R000778_7813_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000778_7813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int tracker_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_60 > 38)
  {
    acc = ((acc + (tracker_60 * 2)) + 5) & 127;
    aux ^= tracker_60 & 15;
  }
  else
  {
    acc = ((acc - tracker_60) + 11) & 127;
    aux += 3;
  }
  int factor_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_30) & 63;
  acc ^= aux;
  int tracker_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_19 = ((tracker_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_19) & 127;
  }

  int anchor_95 = (aux + st.buffer[1]) & 3;
  switch (anchor_95)
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

void fn_R000778_7813_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000778_7813_3 st_1 = {0};
  struct DeviceConfig_R000778_7813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_96_1 = local_arr_1[aux_1 % 3];
  int damping_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_96_2 * 2)) & 127;
  int window_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_79_1 > 26)
  {
    acc_1 = ((acc_1 + (window_79_1 * 2)) + 5) & 127;
    aux_1 ^= window_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_79_2 > 26)
  {
    acc_2 = ((acc_2 + (window_79_2 * 2)) + 5) & 127;
    aux_2 ^= window_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_74_1)
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

  switch (index_reg_74_2)
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

  int stride_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_76_1) & 63;
  aux_2 = (aux_2 + stride_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_96_1 == damping_96_2);
  assert(window_79_1 == window_79_2);
  assert(index_reg_74_1 == index_reg_74_2);
  assert(stride_76_1 == stride_76_2);
}

int fn_R000778_7813_12(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000778_7813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int damping_96 = local_arr[aux % 3];
  acc = (acc + (damping_96 * 2)) & 127;
  int window_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_79 > 26)
  {
    acc = ((acc + (window_79 * 2)) + 5) & 127;
    aux ^= window_79 & 15;
  }
  else
  {
    acc = ((acc - window_79) + 11) & 127;
    aux += 3;
  }
  int index_reg_74 = (aux + st.buffer[1]) & 3;
  switch (index_reg_74)
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

  int stride_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_76) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000778_7813_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000778_7813_2 st_1 = {0};
  struct SensorNode_R000778_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int parity_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_59_1 > 15)
  {
    acc_1 = ((acc_1 + (parity_59_1 * 2)) + 5) & 127;
    aux_1 ^= parity_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_59_2 > 15)
  {
    acc_2 = ((acc_2 + (parity_59_2 * 2)) + 5) & 127;
    aux_2 ^= parity_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_59_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_59_1 == parity_59_2);
}

int fn_R000778_7813_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000778_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int parity_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_59 > 15)
  {
    acc = ((acc + (parity_59 * 2)) + 5) & 127;
    aux ^= parity_59 & 15;
  }
  else
  {
    acc = ((acc - parity_59) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000778_7813_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000778_7813_0 st_1 = {0};
  struct FilterState_R000778_7813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int pivot_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_15_1 > 46)
  {
    acc_1 = ((acc_1 + (pivot_15_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_15_2 > 46)
  {
    acc_2 = ((acc_2 + (pivot_15_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_15_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_97_1)
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

  switch (threshold_97_2)
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

  int threshold_48_1 = 0;
  int threshold_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_48_1 = ((threshold_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_48_2 = ((threshold_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_48_1) & 127;
    acc_2 = (acc_2 + threshold_48_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_15_1 == pivot_15_2);
  assert(threshold_97_1 == threshold_97_2);
  assert(threshold_48_1 == threshold_48_2);
}

int fn_R000778_7813_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000778_7813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int pivot_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_15 > 46)
  {
    acc = ((acc + (pivot_15 * 2)) + 5) & 127;
    aux ^= pivot_15 & 15;
  }
  else
  {
    acc = ((acc - pivot_15) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_97 = (aux + st.buffer[1]) & 3;
  switch (threshold_97)
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

  int threshold_48 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_48 = ((threshold_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_48) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000778_7813_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000778_7813_2 st_1 = {0};
  struct SensorNode_R000778_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int window_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_10_1)
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

  switch (window_10_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_68_1 = local_arr_1[aux_1 % 3];
  int scale_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_68_2 * 2)) & 127;
  int window_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_12_1 > 31)
  {
    acc_1 = ((acc_1 + (window_12_1 * 2)) + 5) & 127;
    aux_1 ^= window_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_12_2 > 31)
  {
    acc_2 = ((acc_2 + (window_12_2 * 2)) + 5) & 127;
    aux_2 ^= window_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_10_1 == window_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_68_1 == scale_68_2);
  assert(window_12_1 == window_12_2);
}

int fn_R000778_7813_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000778_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int window_10 = (aux + st.buffer[1]) & 3;
  switch (window_10)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_68 = local_arr[aux % 3];
  acc = (acc + (scale_68 * 2)) & 127;
  int window_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_12 > 31)
  {
    acc = ((acc + (window_12 * 2)) + 5) & 127;
    aux ^= window_12 & 15;
  }
  else
  {
    acc = ((acc - window_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000778_0_1;
  int sec_r000778_0_2;
  int sec_r000778_1_1;
  int sec_r000778_1_2;
  int sec_r000778_2_1;
  int sec_r000778_2_2;
  int sec_r000778_3_1;
  int sec_r000778_3_2;
  int sec_r000778_4_1;
  int sec_r000778_4_2;
  int sec_r000778_5_1;
  int sec_r000778_5_2;
  int sec_r000778_6_1;
  int sec_r000778_6_2;
  int sec_r000778_7_1;
  int sec_r000778_7_2;
  int sec_r000778_8_1;
  int sec_r000778_8_2;
  int sec_r000778_9_1;
  int sec_r000778_9_2;
  int sec_r000778_10_1;
  int sec_r000778_10_2;
  int sec_r000778_11_1;
  int sec_r000778_11_2;
  int sec_r000778_12_1;
  int sec_r000778_12_2;
  int sec_r000778_13_1;
  int sec_r000778_13_2;
  int sec_r000778_14_1;
  int sec_r000778_14_2;
  int sec_r000778_15_1;
  int sec_r000778_15_2;
  int sec_r000778_16_1;
  int sec_r000778_16_2;
  int sec_r000778_17_1;
  int sec_r000778_17_2;
  int sec_r000778_18_1;
  int sec_r000778_18_2;
  int sec_r000778_19_1;
  int sec_r000778_19_2;
  int sec_r000778_20_1;
  int sec_r000778_20_2;
  int sec_r000778_21_1;
  int sec_r000778_21_2;
  int pub_r000778_0_1;
  int pub_r000778_0_2;
  int pub_r000778_1_1;
  int pub_r000778_1_2;
  int pub_r000778_2_1;
  int pub_r000778_2_2;
  int pub_r000778_3_1;
  int pub_r000778_3_2;
  int pub_r000778_4_1;
  int pub_r000778_4_2;
  int pub_r000778_5_1;
  int pub_r000778_5_2;
  int pub_r000778_6_1;
  int pub_r000778_6_2;
  int pub_r000778_7_1;
  int pub_r000778_7_2;
  int pub_r000778_8_1;
  int pub_r000778_8_2;
  int pub_r000778_9_1;
  int pub_r000778_9_2;
  int pub_r000778_10_1;
  int pub_r000778_10_2;
  int pub_r000778_11_1;
  int pub_r000778_11_2;
  int pub_r000778_12_1;
  int pub_r000778_12_2;
  int pub_r000778_13_1;
  int pub_r000778_13_2;
  int pub_r000778_14_1;
  int pub_r000778_14_2;
  int pub_r000778_15_1;
  int pub_r000778_15_2;
  int pub_r000778_16_1;
  int pub_r000778_16_2;
  int pub_r000778_17_1;
  int pub_r000778_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000778_0_1 >= (-100)) && (pub_r000778_0_1 <= 100));
  __CPROVER_assume((pub_r000778_0_2 >= (-100)) && (pub_r000778_0_2 <= 100));
  __CPROVER_assume((pub_r000778_1_1 >= (-100)) && (pub_r000778_1_1 <= 100));
  __CPROVER_assume((pub_r000778_1_2 >= (-100)) && (pub_r000778_1_2 <= 100));
  __CPROVER_assume((pub_r000778_2_1 >= (-100)) && (pub_r000778_2_1 <= 100));
  __CPROVER_assume((pub_r000778_2_2 >= (-100)) && (pub_r000778_2_2 <= 100));
  __CPROVER_assume((pub_r000778_3_1 >= (-100)) && (pub_r000778_3_1 <= 100));
  __CPROVER_assume((pub_r000778_3_2 >= (-100)) && (pub_r000778_3_2 <= 100));
  __CPROVER_assume((pub_r000778_4_1 >= (-100)) && (pub_r000778_4_1 <= 100));
  __CPROVER_assume((pub_r000778_4_2 >= (-100)) && (pub_r000778_4_2 <= 100));
  __CPROVER_assume((pub_r000778_5_1 >= (-100)) && (pub_r000778_5_1 <= 100));
  __CPROVER_assume((pub_r000778_5_2 >= (-100)) && (pub_r000778_5_2 <= 100));
  __CPROVER_assume((pub_r000778_6_1 >= (-100)) && (pub_r000778_6_1 <= 100));
  __CPROVER_assume((pub_r000778_6_2 >= (-100)) && (pub_r000778_6_2 <= 100));
  __CPROVER_assume((pub_r000778_7_1 >= (-100)) && (pub_r000778_7_1 <= 100));
  __CPROVER_assume((pub_r000778_7_2 >= (-100)) && (pub_r000778_7_2 <= 100));
  __CPROVER_assume((pub_r000778_8_1 >= (-100)) && (pub_r000778_8_1 <= 100));
  __CPROVER_assume((pub_r000778_8_2 >= (-100)) && (pub_r000778_8_2 <= 100));
  __CPROVER_assume((pub_r000778_9_1 >= (-100)) && (pub_r000778_9_1 <= 100));
  __CPROVER_assume((pub_r000778_9_2 >= (-100)) && (pub_r000778_9_2 <= 100));
  __CPROVER_assume((pub_r000778_10_1 >= (-100)) && (pub_r000778_10_1 <= 100));
  __CPROVER_assume((pub_r000778_10_2 >= (-100)) && (pub_r000778_10_2 <= 100));
  __CPROVER_assume((pub_r000778_11_1 >= (-100)) && (pub_r000778_11_1 <= 100));
  __CPROVER_assume((pub_r000778_11_2 >= (-100)) && (pub_r000778_11_2 <= 100));
  __CPROVER_assume((pub_r000778_12_1 >= (-100)) && (pub_r000778_12_1 <= 100));
  __CPROVER_assume((pub_r000778_12_2 >= (-100)) && (pub_r000778_12_2 <= 100));
  __CPROVER_assume((pub_r000778_13_1 >= (-100)) && (pub_r000778_13_1 <= 100));
  __CPROVER_assume((pub_r000778_13_2 >= (-100)) && (pub_r000778_13_2 <= 100));
  __CPROVER_assume((pub_r000778_14_1 >= (-100)) && (pub_r000778_14_1 <= 100));
  __CPROVER_assume((pub_r000778_14_2 >= (-100)) && (pub_r000778_14_2 <= 100));
  __CPROVER_assume((pub_r000778_15_1 >= (-100)) && (pub_r000778_15_1 <= 100));
  __CPROVER_assume((pub_r000778_15_2 >= (-100)) && (pub_r000778_15_2 <= 100));
  __CPROVER_assume((pub_r000778_16_1 >= (-100)) && (pub_r000778_16_1 <= 100));
  __CPROVER_assume((pub_r000778_16_2 >= (-100)) && (pub_r000778_16_2 <= 100));
  __CPROVER_assume((pub_r000778_17_1 >= (-100)) && (pub_r000778_17_1 <= 100));
  __CPROVER_assume((pub_r000778_17_2 >= (-100)) && (pub_r000778_17_2 <= 100));
  __CPROVER_assume((sec_r000778_0_1 >= 0) && (sec_r000778_0_1 <= 255));
  __CPROVER_assume((sec_r000778_0_2 >= 0) && (sec_r000778_0_2 <= 255));
  __CPROVER_assume((sec_r000778_1_1 >= 0) && (sec_r000778_1_1 <= 255));
  __CPROVER_assume((sec_r000778_1_2 >= 0) && (sec_r000778_1_2 <= 255));
  __CPROVER_assume((sec_r000778_2_1 >= 0) && (sec_r000778_2_1 <= 255));
  __CPROVER_assume((sec_r000778_2_2 >= 0) && (sec_r000778_2_2 <= 255));
  __CPROVER_assume((sec_r000778_3_1 >= 0) && (sec_r000778_3_1 <= 255));
  __CPROVER_assume((sec_r000778_3_2 >= 0) && (sec_r000778_3_2 <= 255));
  __CPROVER_assume((sec_r000778_4_1 >= 0) && (sec_r000778_4_1 <= 255));
  __CPROVER_assume((sec_r000778_4_2 >= 0) && (sec_r000778_4_2 <= 255));
  __CPROVER_assume((sec_r000778_5_1 >= 0) && (sec_r000778_5_1 <= 255));
  __CPROVER_assume((sec_r000778_5_2 >= 0) && (sec_r000778_5_2 <= 255));
  __CPROVER_assume((sec_r000778_6_1 >= 0) && (sec_r000778_6_1 <= 255));
  __CPROVER_assume((sec_r000778_6_2 >= 0) && (sec_r000778_6_2 <= 255));
  __CPROVER_assume((sec_r000778_7_1 >= 0) && (sec_r000778_7_1 <= 255));
  __CPROVER_assume((sec_r000778_7_2 >= 0) && (sec_r000778_7_2 <= 255));
  __CPROVER_assume((sec_r000778_8_1 >= 0) && (sec_r000778_8_1 <= 255));
  __CPROVER_assume((sec_r000778_8_2 >= 0) && (sec_r000778_8_2 <= 255));
  __CPROVER_assume((sec_r000778_9_1 >= 0) && (sec_r000778_9_1 <= 255));
  __CPROVER_assume((sec_r000778_9_2 >= 0) && (sec_r000778_9_2 <= 255));
  __CPROVER_assume((sec_r000778_10_1 >= 0) && (sec_r000778_10_1 <= 255));
  __CPROVER_assume((sec_r000778_10_2 >= 0) && (sec_r000778_10_2 <= 255));
  __CPROVER_assume((sec_r000778_11_1 >= 0) && (sec_r000778_11_1 <= 255));
  __CPROVER_assume((sec_r000778_11_2 >= 0) && (sec_r000778_11_2 <= 255));
  __CPROVER_assume((sec_r000778_12_1 >= 0) && (sec_r000778_12_1 <= 255));
  __CPROVER_assume((sec_r000778_12_2 >= 0) && (sec_r000778_12_2 <= 255));
  __CPROVER_assume((sec_r000778_13_1 >= 0) && (sec_r000778_13_1 <= 255));
  __CPROVER_assume((sec_r000778_13_2 >= 0) && (sec_r000778_13_2 <= 255));
  __CPROVER_assume((sec_r000778_14_1 >= 0) && (sec_r000778_14_1 <= 255));
  __CPROVER_assume((sec_r000778_14_2 >= 0) && (sec_r000778_14_2 <= 255));
  __CPROVER_assume((sec_r000778_15_1 >= 0) && (sec_r000778_15_1 <= 255));
  __CPROVER_assume((sec_r000778_15_2 >= 0) && (sec_r000778_15_2 <= 255));
  __CPROVER_assume((sec_r000778_16_1 >= 0) && (sec_r000778_16_1 <= 255));
  __CPROVER_assume((sec_r000778_16_2 >= 0) && (sec_r000778_16_2 <= 255));
  __CPROVER_assume((sec_r000778_17_1 >= 0) && (sec_r000778_17_1 <= 255));
  __CPROVER_assume((sec_r000778_17_2 >= 0) && (sec_r000778_17_2 <= 255));
  __CPROVER_assume((sec_r000778_18_1 >= 0) && (sec_r000778_18_1 <= 255));
  __CPROVER_assume((sec_r000778_18_2 >= 0) && (sec_r000778_18_2 <= 255));
  __CPROVER_assume((sec_r000778_19_1 >= 0) && (sec_r000778_19_1 <= 255));
  __CPROVER_assume((sec_r000778_19_2 >= 0) && (sec_r000778_19_2 <= 255));
  __CPROVER_assume((sec_r000778_20_1 >= 0) && (sec_r000778_20_1 <= 255));
  __CPROVER_assume((sec_r000778_20_2 >= 0) && (sec_r000778_20_2 <= 255));
  __CPROVER_assume((sec_r000778_21_1 >= 0) && (sec_r000778_21_1 <= 255));
  __CPROVER_assume((sec_r000778_21_2 >= 0) && (sec_r000778_21_2 <= 255));
  struct FilterState_R000778_7813_0 st_var_0_1 = {0};
  struct FilterState_R000778_7813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000778_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000778_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000778_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000778_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000778_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000778_0_2 + 7) & 15;
  struct Vector3D_R000778_7813_1 st_var_1_1 = {0};
  struct Vector3D_R000778_7813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000778_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000778_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000778_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000778_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000778_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000778_0_2 + 9) & 15;
  struct SensorNode_R000778_7813_2 st_var_2_1 = {0};
  struct SensorNode_R000778_7813_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000778_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000778_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000778_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000778_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000778_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000778_0_2 + 11) & 15;
  struct DeviceConfig_R000778_7813_3 st_var_3_1 = {0};
  struct DeviceConfig_R000778_7813_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000778_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000778_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000778_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000778_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000778_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000778_0_2 + 13) & 15;
  union ColorPixel_R000778_7813_0 u_var_1;
  union ColorPixel_R000778_7813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 33)
    {
      chk_sum_1 ^= stage_v_0_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_0_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 33)
    {
      chk_sum_2 ^= stage_v_0_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 4) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 7) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 8) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
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
  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (st_var_2_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_2_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = (st_var_3_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_3_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 43)
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
  if (stage_v_13_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 43)
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
  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 38)
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
  if (stage_v_14_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 38)
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
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 19) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = (st_var_3_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_3_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
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

  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 24) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_3_2.buffer[2] * 3) & 63;
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
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 35)
    {
      chk_sum_1 ^= stage_v_26_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_26_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 35)
    {
      chk_sum_2 ^= stage_v_26_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_27_1 = ((st_var_3_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_3_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 30)
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
  if (stage_v_27_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 30)
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
  int stage_v_28_1 = ((st_var_0_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_0_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 45)
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
  if (stage_v_28_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 45)
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
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 31) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  int stage_v_32_1 = (st_var_0_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_0_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
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

  switch (stage_v_32_2)
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

  int stage_v_33_1 = (st_var_1_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_1_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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

  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 36) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= stage_v_35_1;
  chk_sum_2 ^= stage_v_35_2;
  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 39)
    {
      chk_sum_1 ^= stage_v_36_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_36_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 39)
    {
      chk_sum_2 ^= stage_v_36_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_37_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_37_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 39) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  int stage_v_39_1 = ((st_var_3_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_3_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 49)
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
  if (stage_v_39_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 49)
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
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 40)
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
  if (stage_v_41_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 40)
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
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_42_1 = ((stage_v_42_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_42_2 = ((stage_v_42_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (st_var_3_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_3_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
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

  switch (stage_v_43_2)
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

  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 46) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = ((st_var_2_1.buffer[1] * 2) + 145) & 63;
  int stage_v_46_2 = ((st_var_2_2.buffer[1] * 2) + 145) & 63;
  if (stage_v_46_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_46_1) - 5) & 255;
    if (stage_v_46_1 > 44)
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
  if (stage_v_46_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_46_2) - 5) & 255;
    if (stage_v_46_2 > 44)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 49) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 49) & 15;
  int stage_v_48_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_48_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= stage_v_48_1;
  chk_sum_2 ^= stage_v_48_2;
  int stage_v_49_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (54 & 31);
  int stage_v_49_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (54 & 31);
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= (stage_v_49_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_49_2 << 1) & 127;
  int stage_v_50_1 = ((st_var_2_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_2_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 52)
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
  if (stage_v_50_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 52)
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
  int stage_v_51_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (56 & 31);
  int stage_v_51_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (56 & 31);
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= (stage_v_51_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_51_2 << 1) & 127;
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
  int stage_v_55_1 = ((st_var_3_1.buffer[1] * 2) + 172) & 63;
  int stage_v_55_2 = ((st_var_3_2.buffer[1] * 2) + 172) & 63;
  if (stage_v_55_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_55_1) - 5) & 255;
    if (stage_v_55_1 > 43)
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
  if (stage_v_55_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_55_2) - 5) & 255;
    if (stage_v_55_2 > 43)
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

  switch (stage_v_56_2)
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

  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
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
  int stage_v_60_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_60_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_61_1 = ((st_var_1_1.buffer[1] * 2) + 190) & 63;
  int stage_v_61_2 = ((st_var_1_2.buffer[1] * 2) + 190) & 63;
  if (stage_v_61_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_61_1) - 5) & 255;
    if (stage_v_61_1 > 51)
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
  if (stage_v_61_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_61_2) - 5) & 255;
    if (stage_v_61_2 > 51)
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
  int stage_v_62_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_62_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_63_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_63_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_64_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (69 & 31);
  int stage_v_64_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (69 & 31);
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= (stage_v_64_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_64_2 << 1) & 127;
  int stage_v_65_1 = table_1[1];
  int stage_v_65_2 = table_2[1];
  table_1[1] = (table_1[2] + 131) & 63;
  table_2[1] = (table_2[2] + 131) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (st_var_2_1.buffer[0] ^ 69) & 3;
  int stage_v_66_2 = (st_var_2_2.buffer[0] ^ 69) & 3;
  switch (stage_v_66_1)
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

  switch (stage_v_66_2)
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
  int stage_v_68_1 = ((st_var_0_1.buffer[2] * 2) + 211) & 63;
  int stage_v_68_2 = ((st_var_0_2.buffer[2] * 2) + 211) & 63;
  if (stage_v_68_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_68_1) - 5) & 255;
    if (stage_v_68_1 > 46)
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
  if (stage_v_68_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_68_2) - 5) & 255;
    if (stage_v_68_2 > 46)
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
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 71) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 71) & 15;
  int stage_v_70_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_70_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= stage_v_70_1;
  chk_sum_2 ^= stage_v_70_2;
  int stage_v_71_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (76 & 31);
  int stage_v_71_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (76 & 31);
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= (stage_v_71_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_71_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 73) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 73) & 15;
  int stage_v_72_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_72_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= stage_v_72_1;
  chk_sum_2 ^= stage_v_72_2;
  int stage_v_73_1 = (st_var_1_1.buffer[0] ^ 76) & 3;
  int stage_v_73_2 = (st_var_1_2.buffer[0] ^ 76) & 3;
  switch (stage_v_73_1)
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

  switch (stage_v_73_2)
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

  int stage_v_74_1 = table_1[2];
  int stage_v_74_2 = table_2[2];
  table_1[2] = (table_1[3] + 149) & 63;
  table_2[2] = (table_2[3] + 149) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = table_1[3];
  int stage_v_75_2 = table_2[3];
  table_1[3] = (table_1[0] + 151) & 63;
  table_2[3] = (table_2[0] + 151) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = table_1[0];
  int stage_v_76_2 = table_2[0];
  table_1[0] = (table_1[1] + 153) & 63;
  table_2[0] = (table_2[1] + 153) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 78) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 78) & 15;
  int stage_v_77_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_77_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= stage_v_77_1;
  chk_sum_2 ^= stage_v_77_2;
  int stage_v_78_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (83 & 31);
  int stage_v_78_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (83 & 31);
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= (stage_v_78_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_78_2 << 1) & 127;
  int stage_v_79_1 = (st_var_3_1.buffer[0] ^ 82) & 3;
  int stage_v_79_2 = (st_var_3_2.buffer[0] ^ 82) & 3;
  switch (stage_v_79_1)
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

  switch (stage_v_79_2)
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

  int stage_v_81_1 = ((st_var_1_1.buffer[0] * 2) + 250) & 63;
  int stage_v_81_2 = ((st_var_1_2.buffer[0] * 2) + 250) & 63;
  if (stage_v_81_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_81_1) - 5) & 255;
    if (stage_v_81_1 > 52)
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
  if (stage_v_81_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_81_2) - 5) & 255;
    if (stage_v_81_2 > 52)
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
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 83) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 83) & 15;
  int stage_v_82_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_82_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= stage_v_82_1;
  chk_sum_2 ^= stage_v_82_2;
  int stage_v_83_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (88 & 31);
  int stage_v_83_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (88 & 31);
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= (stage_v_83_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_83_2 << 1) & 127;
  int stage_v_84_1 = ((st_var_0_1.buffer[0] * 2) + 259) & 63;
  int stage_v_84_2 = ((st_var_0_2.buffer[0] * 2) + 259) & 63;
  if (stage_v_84_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_84_1) - 5) & 255;
    if (stage_v_84_1 > 47)
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
  if (stage_v_84_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_84_2) - 5) & 255;
    if (stage_v_84_2 > 47)
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
  int stage_v_85_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_85_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_85_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_85_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_86_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_86_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 88) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 88) & 15;
  int stage_v_87_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_87_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  chk_sum_1 ^= stage_v_87_1;
  chk_sum_2 ^= stage_v_87_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 89) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 89) & 15;
  int stage_v_88_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_88_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= stage_v_88_1;
  chk_sum_2 ^= stage_v_88_2;
  int stage_v_89_1 = ((st_var_1_1.buffer[2] * 2) + 274) & 63;
  int stage_v_89_2 = ((st_var_1_2.buffer[2] * 2) + 274) & 63;
  if (stage_v_89_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_89_1) - 5) & 255;
    if (stage_v_89_1 > 55)
    {
      chk_sum_1 ^= stage_v_89_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_89_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_89_2) - 5) & 255;
    if (stage_v_89_2 > 55)
    {
      chk_sum_2 ^= stage_v_89_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
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
  int stage_v_93_1 = (st_var_1_1.buffer[0] ^ 96) & 3;
  int stage_v_93_2 = (st_var_1_2.buffer[0] ^ 96) & 3;
  switch (stage_v_93_1)
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

  switch (stage_v_93_2)
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

  int stage_v_94_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_94_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_94_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_94_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_95_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (100 & 31);
  int stage_v_95_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (100 & 31);
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  chk_sum_1 ^= (stage_v_95_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_95_2 << 1) & 127;
  int stage_v_96_1 = ((st_var_0_1.buffer[0] * 2) + 295) & 63;
  int stage_v_96_2 = ((st_var_0_2.buffer[0] * 2) + 295) & 63;
  if (stage_v_96_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_96_1) - 5) & 255;
    if (stage_v_96_1 > 48)
    {
      chk_sum_1 ^= stage_v_96_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_96_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_96_2) - 5) & 255;
    if (stage_v_96_2 > 48)
    {
      chk_sum_2 ^= stage_v_96_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
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

  switch (stage_v_98_2)
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

  int stage_v_99_1 = ((st_var_3_1.buffer[0] * 2) + 304) & 63;
  int stage_v_99_2 = ((st_var_3_2.buffer[0] * 2) + 304) & 63;
  if (stage_v_99_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_99_1) - 5) & 255;
    if (stage_v_99_1 > 46)
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
  if (stage_v_99_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_99_2) - 5) & 255;
    if (stage_v_99_2 > 46)
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
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_100_1 = ((stage_v_100_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_100_2 = ((stage_v_100_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (st_var_1_1.buffer[0] ^ 104) & 3;
  int stage_v_101_2 = (st_var_1_2.buffer[0] ^ 104) & 3;
  switch (stage_v_101_1)
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

  switch (stage_v_101_2)
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
  int stage_v_104_1 = table_1[0];
  int stage_v_104_2 = table_2[0];
  table_1[0] = (table_1[1] + 209) & 63;
  table_2[0] = (table_2[1] + 209) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 106) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 106) & 15;
  int stage_v_105_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_105_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= stage_v_105_1;
  chk_sum_2 ^= stage_v_105_2;
  int stage_v_106_1 = table_1[2];
  int stage_v_106_2 = table_2[2];
  table_1[2] = (table_1[3] + 213) & 63;
  table_2[2] = (table_2[3] + 213) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_107_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_107_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_107_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_108_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_108_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_108_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_108_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_109_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_109_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_109_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_109_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_110_1 = ((stage_v_110_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_110_2 = ((stage_v_110_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = table_1[3];
  int stage_v_111_2 = table_2[3];
  table_1[3] = (table_1[0] + 223) & 63;
  table_2[3] = (table_2[0] + 223) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = table_1[0];
  int stage_v_112_2 = table_2[0];
  table_1[0] = (table_1[1] + 225) & 63;
  table_2[0] = (table_2[1] + 225) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = table_1[1];
  int stage_v_113_2 = table_2[1];
  table_1[1] = (table_1[2] + 227) & 63;
  table_2[1] = (table_2[2] + 227) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_114_1 = ((stage_v_114_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_114_2 = ((stage_v_114_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_115_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_115_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_115_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_116_1 = ((stage_v_116_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_116_2 = ((stage_v_116_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 118) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 118) & 15;
  int stage_v_117_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_117_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  chk_sum_1 ^= stage_v_117_1;
  chk_sum_2 ^= stage_v_117_2;
  int stage_v_118_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (123 & 31);
  int stage_v_118_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (123 & 31);
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  chk_sum_1 ^= (stage_v_118_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_118_2 << 1) & 127;
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

  switch (stage_v_120_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 122) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 122) & 15;
  int stage_v_121_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_121_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  chk_sum_1 ^= stage_v_121_1;
  chk_sum_2 ^= stage_v_121_2;
  int stage_v_122_1 = (st_var_2_1.buffer[0] ^ 125) & 3;
  int stage_v_122_2 = (st_var_2_2.buffer[0] ^ 125) & 3;
  switch (stage_v_122_1)
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

  switch (stage_v_122_2)
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

  int stage_v_123_1 = (st_var_3_1.buffer[0] ^ 126) & 3;
  int stage_v_123_2 = (st_var_3_2.buffer[0] ^ 126) & 3;
  switch (stage_v_123_1)
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

  switch (stage_v_123_2)
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

  int stage_v_124_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (129 & 31);
  int stage_v_124_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (129 & 31);
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  chk_sum_1 ^= (stage_v_124_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_124_2 << 1) & 127;
  int stage_v_125_1 = table_1[1];
  int stage_v_125_2 = table_2[1];
  table_1[1] = (table_1[2] + 251) & 63;
  table_2[1] = (table_2[2] + 251) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
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
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_128_1 = ((stage_v_128_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_128_2 = ((stage_v_128_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
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
  int stage_v_131_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (136 & 31);
  int stage_v_131_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (136 & 31);
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  chk_sum_1 ^= (stage_v_131_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_131_2 << 1) & 127;
  int stage_v_132_1 = (st_var_0_1.buffer[0] ^ 135) & 3;
  int stage_v_132_2 = (st_var_0_2.buffer[0] ^ 135) & 3;
  switch (stage_v_132_1)
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

  switch (stage_v_132_2)
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

  int stage_v_133_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (138 & 31);
  int stage_v_133_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (138 & 31);
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  chk_sum_1 ^= (stage_v_133_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_133_2 << 1) & 127;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_134_1 = ((stage_v_134_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_134_2 = ((stage_v_134_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 136) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 136) & 15;
  int stage_v_135_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_135_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  chk_sum_1 ^= stage_v_135_1;
  chk_sum_2 ^= stage_v_135_2;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_136_1 = ((stage_v_136_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_136_2 = ((stage_v_136_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (142 & 31);
  int stage_v_137_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (142 & 31);
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  chk_sum_1 ^= (stage_v_137_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_137_2 << 1) & 127;
  int stage_v_138_1 = ((st_var_2_1.buffer[0] * 2) + 421) & 63;
  int stage_v_138_2 = ((st_var_2_2.buffer[0] * 2) + 421) & 63;
  if (stage_v_138_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_138_1) - 5) & 255;
    if (stage_v_138_1 > 40)
    {
      chk_sum_1 ^= stage_v_138_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_138_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_138_2) - 5) & 255;
    if (stage_v_138_2 > 40)
    {
      chk_sum_2 ^= stage_v_138_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_140_1 = (st_var_0_1.buffer[0] ^ 143) & 3;
  int stage_v_140_2 = (st_var_0_2.buffer[0] ^ 143) & 3;
  switch (stage_v_140_1)
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

  switch (stage_v_140_2)
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

  int stage_v_141_1 = ((st_var_1_1.buffer[0] * 2) + 430) & 63;
  int stage_v_141_2 = ((st_var_1_2.buffer[0] * 2) + 430) & 63;
  if (stage_v_141_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_141_1) - 5) & 255;
    if (stage_v_141_1 > 52)
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
  if (stage_v_141_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_141_2) - 5) & 255;
    if (stage_v_141_2 > 52)
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
  int stage_v_142_1 = ((st_var_2_1.buffer[1] * 2) + 433) & 63;
  int stage_v_142_2 = ((st_var_2_2.buffer[1] * 2) + 433) & 63;
  if (stage_v_142_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_142_1) - 5) & 255;
    if (stage_v_142_1 > 50)
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
  if (stage_v_142_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_142_2) - 5) & 255;
    if (stage_v_142_2 > 50)
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
  int stage_v_143_1 = ((st_var_3_1.buffer[2] * 2) + 436) & 63;
  int stage_v_143_2 = ((st_var_3_2.buffer[2] * 2) + 436) & 63;
  if (stage_v_143_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_143_1) - 5) & 255;
    if (stage_v_143_1 > 44)
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
  if (stage_v_143_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_143_2) - 5) & 255;
    if (stage_v_143_2 > 44)
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
  int stage_v_144_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (149 & 31);
  int stage_v_144_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (149 & 31);
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  chk_sum_1 ^= (stage_v_144_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_144_2 << 1) & 127;
  int stage_v_145_1 = ((st_var_1_1.buffer[1] * 2) + 442) & 63;
  int stage_v_145_2 = ((st_var_1_2.buffer[1] * 2) + 442) & 63;
  if (stage_v_145_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_145_1) - 5) & 255;
    if (stage_v_145_1 > 51)
    {
      chk_sum_1 ^= stage_v_145_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_145_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_145_2) - 5) & 255;
    if (stage_v_145_2 > 51)
    {
      chk_sum_2 ^= stage_v_145_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_146_1 = table_1[2];
  int stage_v_146_2 = table_2[2];
  table_1[2] = (table_1[3] + 293) & 63;
  table_2[2] = (table_2[3] + 293) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = table_1[3];
  int stage_v_147_2 = table_2[3];
  table_1[3] = (table_1[0] + 295) & 63;
  table_2[3] = (table_2[0] + 295) & 63;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((st_var_0_1.buffer[1] * 2) + 451) & 63;
  int stage_v_148_2 = ((st_var_0_2.buffer[1] * 2) + 451) & 63;
  if (stage_v_148_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_148_1) - 5) & 255;
    if (stage_v_148_1 > 38)
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
  if (stage_v_148_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_148_2) - 5) & 255;
    if (stage_v_148_2 > 38)
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
  int stage_v_150_1 = ((st_var_2_1.buffer[0] * 2) + 457) & 63;
  int stage_v_150_2 = ((st_var_2_2.buffer[0] * 2) + 457) & 63;
  if (stage_v_150_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_150_1) - 5) & 255;
    if (stage_v_150_1 > 54)
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
  if (stage_v_150_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_150_2) - 5) & 255;
    if (stage_v_150_2 > 54)
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 153) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 153) & 15;
  int stage_v_152_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_152_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  chk_sum_1 ^= stage_v_152_1;
  chk_sum_2 ^= stage_v_152_2;
  int stage_v_153_1 = ((st_var_1_1.buffer[0] * 2) + 466) & 63;
  int stage_v_153_2 = ((st_var_1_2.buffer[0] * 2) + 466) & 63;
  if (stage_v_153_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_153_1) - 5) & 255;
    if (stage_v_153_1 > 44)
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
  if (stage_v_153_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_153_2) - 5) & 255;
    if (stage_v_153_2 > 44)
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
  int stage_v_154_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_154_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_154_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_154_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_155_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (160 & 31);
  int stage_v_155_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (160 & 31);
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  chk_sum_1 ^= (stage_v_155_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_155_2 << 1) & 127;
  int stage_v_156_1 = (st_var_0_1.buffer[0] ^ 159) & 3;
  int stage_v_156_2 = (st_var_0_2.buffer[0] ^ 159) & 3;
  switch (stage_v_156_1)
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

  switch (stage_v_156_2)
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

  int stage_v_157_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (162 & 31);
  int stage_v_157_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (162 & 31);
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  chk_sum_1 ^= (stage_v_157_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_157_2 << 1) & 127;
  int stage_v_158_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (163 & 31);
  int stage_v_158_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (163 & 31);
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  chk_sum_1 ^= (stage_v_158_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_158_2 << 1) & 127;
  int stage_v_159_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_159_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_159_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_159_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 161) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 161) & 15;
  int stage_v_160_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_160_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  chk_sum_1 ^= stage_v_160_1;
  chk_sum_2 ^= stage_v_160_2;
  int stage_v_161_1 = ((st_var_1_1.buffer[2] * 2) + 490) & 63;
  int stage_v_161_2 = ((st_var_1_2.buffer[2] * 2) + 490) & 63;
  if (stage_v_161_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_161_1) - 5) & 255;
    if (stage_v_161_1 > 35)
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
  if (stage_v_161_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_161_2) - 5) & 255;
    if (stage_v_161_2 > 35)
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
  int stage_v_162_1 = (st_var_2_1.buffer[0] ^ 165) & 3;
  int stage_v_162_2 = (st_var_2_2.buffer[0] ^ 165) & 3;
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

  int stage_v_163_1 = ((st_var_3_1.buffer[1] * 2) + 496) & 63;
  int stage_v_163_2 = ((st_var_3_2.buffer[1] * 2) + 496) & 63;
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
  if (stage_v_164_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_164_1) - 5) & 255;
    if (stage_v_164_1 > 50)
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
  if (stage_v_164_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_164_2) - 5) & 255;
    if (stage_v_164_2 > 50)
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
  int stage_v_165_1 = ((st_var_1_1.buffer[0] * 2) + 502) & 63;
  int stage_v_165_2 = ((st_var_1_2.buffer[0] * 2) + 502) & 63;
  if (stage_v_165_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_165_1) - 5) & 255;
    if (stage_v_165_1 > 42)
    {
      chk_sum_1 ^= stage_v_165_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_165_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_165_2) - 5) & 255;
    if (stage_v_165_2 > 42)
    {
      chk_sum_2 ^= stage_v_165_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_166_1 = (st_var_2_1.buffer[0] ^ 169) & 3;
  int stage_v_166_2 = (st_var_2_2.buffer[0] ^ 169) & 3;
  switch (stage_v_166_1)
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

  switch (stage_v_166_2)
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

  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 168) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 168) & 15;
  int stage_v_167_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_167_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  chk_sum_1 ^= stage_v_167_1;
  chk_sum_2 ^= stage_v_167_2;
  int stage_v_168_1 = (st_var_0_1.buffer[0] ^ 171) & 3;
  int stage_v_168_2 = (st_var_0_2.buffer[0] ^ 171) & 3;
  switch (stage_v_168_1)
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

  switch (stage_v_168_2)
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

  int stage_v_169_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_169_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_169_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_169_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_170_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (175 & 31);
  int stage_v_170_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (175 & 31);
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  chk_sum_1 ^= (stage_v_170_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_170_2 << 1) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 172) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 172) & 15;
  int stage_v_171_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_171_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  chk_sum_1 ^= stage_v_171_1;
  chk_sum_2 ^= stage_v_171_2;
  int stage_v_172_1 = table_1[0];
  int stage_v_172_2 = table_2[0];
  table_1[0] = (table_1[1] + 345) & 63;
  table_2[0] = (table_2[1] + 345) & 63;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (178 & 31);
  int stage_v_173_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (178 & 31);
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  chk_sum_1 ^= (stage_v_173_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_173_2 << 1) & 127;
  int stage_v_174_1 = table_1[2];
  int stage_v_174_2 = table_2[2];
  table_1[2] = (table_1[3] + 349) & 63;
  table_2[2] = (table_2[3] + 349) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_175_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_175_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_175_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_176_1 = 0;
  int stage_v_176_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_176_1 = ((stage_v_176_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_176_2 = ((stage_v_176_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((st_var_1_1.buffer[0] * 2) + 538) & 63;
  int stage_v_177_2 = ((st_var_1_2.buffer[0] * 2) + 538) & 63;
  if (stage_v_177_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_177_1) - 5) & 255;
    if (stage_v_177_1 > 36)
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
  if (stage_v_177_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_177_2) - 5) & 255;
    if (stage_v_177_2 > 36)
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
  int stage_v_178_1 = (st_var_2_1.buffer[0] ^ 181) & 3;
  int stage_v_178_2 = (st_var_2_2.buffer[0] ^ 181) & 3;
  switch (stage_v_178_1)
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

  switch (stage_v_178_2)
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

  int stage_v_179_1 = 0;
  int stage_v_179_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_179_1 = ((stage_v_179_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_179_2 = ((stage_v_179_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_180_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_180_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_180_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_181_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_181_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_181_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_181_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_182_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_182_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_182_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_182_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_183_1 = table_1[3];
  int stage_v_183_2 = table_2[3];
  table_1[3] = (table_1[0] + 367) & 63;
  table_2[3] = (table_2[0] + 367) & 63;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_184_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_184_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_184_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_185_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (190 & 31);
  int stage_v_185_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (190 & 31);
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  chk_sum_1 ^= (stage_v_185_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_185_2 << 1) & 127;
  int stage_v_186_1 = table_1[2];
  int stage_v_186_2 = table_2[2];
  table_1[2] = (table_1[3] + 373) & 63;
  table_2[2] = (table_2[3] + 373) & 63;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 188) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 188) & 15;
  int stage_v_187_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_187_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  chk_sum_1 ^= stage_v_187_1;
  chk_sum_2 ^= stage_v_187_2;
  int stage_v_188_1 = table_1[0];
  int stage_v_188_2 = table_2[0];
  table_1[0] = (table_1[1] + 377) & 63;
  table_2[0] = (table_2[1] + 377) & 63;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 190) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 190) & 15;
  int stage_v_189_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_189_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  chk_sum_1 ^= stage_v_189_1;
  chk_sum_2 ^= stage_v_189_2;
  int stage_v_190_1 = 0;
  int stage_v_190_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_190_1 = ((stage_v_190_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_190_2 = ((stage_v_190_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = 0;
  int stage_v_191_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_191_1 = ((stage_v_191_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_191_2 = ((stage_v_191_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((st_var_0_1.buffer[0] * 2) + 583) & 63;
  int stage_v_192_2 = ((st_var_0_2.buffer[0] * 2) + 583) & 63;
  if (stage_v_192_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_192_1) - 5) & 255;
    if (stage_v_192_1 > 55)
    {
      chk_sum_1 ^= stage_v_192_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_192_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_192_2) - 5) & 255;
    if (stage_v_192_2 > 55)
    {
      chk_sum_2 ^= stage_v_192_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_193_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_193_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_193_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_193_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 195) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 195) & 15;
  int stage_v_194_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_194_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  chk_sum_1 ^= stage_v_194_1;
  chk_sum_2 ^= stage_v_194_2;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 196) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 196) & 15;
  int stage_v_195_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_195_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  chk_sum_1 ^= stage_v_195_1;
  chk_sum_2 ^= stage_v_195_2;
  int stage_v_196_1 = (st_var_0_1.buffer[0] ^ 199) & 3;
  int stage_v_196_2 = (st_var_0_2.buffer[0] ^ 199) & 3;
  switch (stage_v_196_1)
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

  switch (stage_v_196_2)
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

  int l_bound_0_1 = (sec_r000778_14_1 & 1) + 1;
  int l_bound_0_2 = (sec_r000778_14_2 & 1) + 1;
  for (int it_1 = 0, it_2 = 0; (it_1 < l_bound_0_1) && (it_2 < l_bound_0_2); it_1++, it_2++)
  {
    out_sink_1 += (it_1 * 3) + 6;
    out_sink_2 += (it_2 * 3) + 6;
  }

  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000778_17_1 == pub_r000778_17_2);
  __CPROVER_assume(sec_r000778_21_1 != sec_r000778_21_2);
  __CPROVER_assume(sec_r000778_5_1 != sec_r000778_5_2);
  __CPROVER_assume(sec_r000778_7_1 != sec_r000778_7_2);
  __CPROVER_assume(sec_r000778_8_1 != sec_r000778_8_2);
  __CPROVER_assume(pub_r000778_15_1 == pub_r000778_15_2);
  __CPROVER_assume(sec_r000778_15_1 != sec_r000778_15_2);
  __CPROVER_assume(sec_r000778_4_1 != sec_r000778_4_2);
  __CPROVER_assume(pub_r000778_6_1 == pub_r000778_6_2);
  __CPROVER_assume(pub_r000778_11_1 == pub_r000778_11_2);
  __CPROVER_assume(pub_r000778_5_1 == pub_r000778_5_2);
  __CPROVER_assume(pub_r000778_3_1 == pub_r000778_3_2);
  __CPROVER_assume(pub_r000778_10_1 == pub_r000778_10_2);
  __CPROVER_assume(sec_r000778_14_1 != sec_r000778_14_2);
  __CPROVER_assume(sec_r000778_6_1 != sec_r000778_6_2);
  __CPROVER_assume(pub_r000778_0_1 == pub_r000778_0_2);
  __CPROVER_assume(pub_r000778_2_1 == pub_r000778_2_2);
  __CPROVER_assume(sec_r000778_0_1 != sec_r000778_0_2);
  __CPROVER_assume(sec_r000778_16_1 != sec_r000778_16_2);
  __CPROVER_assume(pub_r000778_1_1 == pub_r000778_1_2);
  __CPROVER_assume(pub_r000778_9_1 == pub_r000778_9_2);
  __CPROVER_assume(pub_r000778_16_1 == pub_r000778_16_2);
  __CPROVER_assume(pub_r000778_8_1 == pub_r000778_8_2);
  __CPROVER_assume(sec_r000778_18_1 != sec_r000778_18_2);
  __CPROVER_assume(sec_r000778_10_1 != sec_r000778_10_2);
  __CPROVER_assume(sec_r000778_12_1 != sec_r000778_12_2);
  __CPROVER_assume(pub_r000778_4_1 == pub_r000778_4_2);
  __CPROVER_assume(sec_r000778_13_1 != sec_r000778_13_2);
  __CPROVER_assume(sec_r000778_1_1 != sec_r000778_1_2);
  __CPROVER_assume(sec_r000778_17_1 != sec_r000778_17_2);
  __CPROVER_assume(sec_r000778_9_1 != sec_r000778_9_2);
  __CPROVER_assume(pub_r000778_7_1 == pub_r000778_7_2);
  __CPROVER_assume(pub_r000778_13_1 == pub_r000778_13_2);
  __CPROVER_assume(pub_r000778_14_1 == pub_r000778_14_2);
  __CPROVER_assume(sec_r000778_2_1 != sec_r000778_2_2);
  __CPROVER_assume(sec_r000778_11_1 != sec_r000778_11_2);
  __CPROVER_assume(sec_r000778_3_1 != sec_r000778_3_2);
  __CPROVER_assume(pub_r000778_12_1 == pub_r000778_12_2);
  __CPROVER_assume(sec_r000778_19_1 != sec_r000778_19_2);
  __CPROVER_assume(sec_r000778_20_1 != sec_r000778_20_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.reading == st_var_2_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.id == st_var_3_2.id);
  assert(st_var_3_1.parity == st_var_3_2.parity);
  assert(st_var_3_1.baud_rate == st_var_3_2.baud_rate);
  assert(st_var_3_1.timeout == st_var_3_2.timeout);
  assert(st_var_3_1.port == st_var_3_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_3_1.buffer[i_buffer] == st_var_3_2.buffer[i_buffer]);
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
  assert(l_bound_0_1 == l_bound_0_2);
}


