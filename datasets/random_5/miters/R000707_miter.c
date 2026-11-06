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
struct AudioFrame_R000707_713_0
{
  unsigned char peak;
  unsigned char channels;
  short sample_rate;
  unsigned char rms;
  int buffer[3];
};
struct DeviceConfig_R000707_713_1
{
  short stop_bits;
  int baud_rate;
  short port;
  short parity;
  int timeout;
  int id;
  int buffer[3];
};
struct SensorNode_R000707_713_2
{
  int reading;
  unsigned char threshold;
  short offset;
  int buffer[3];
};
struct Vector3D_R000707_713_3
{
  short coord_x;
  short coord_y;
  int heading;
  unsigned char norm_sq;
  int buffer[3];
};
union ColorPixel_R000707_713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000707_713_1
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
void fn_R000707_713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000707_713_2 st_1 = {0};
  struct SensorNode_R000707_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int metric_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_75_1) & 63;
  aux_2 = (aux_2 + metric_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_81_1 > 34)
  {
    acc_1 = ((acc_1 + (checksum_81_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_81_2 > 34)
  {
    acc_2 = ((acc_2 + (checksum_81_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_81_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_75_1 == metric_75_2);
  assert(checksum_81_1 == checksum_81_2);
}

int fn_R000707_713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000707_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int metric_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_75) & 63;
  acc ^= aux;
  int checksum_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_81 > 34)
  {
    acc = ((acc + (checksum_81 * 2)) + 5) & 127;
    aux ^= checksum_81 & 15;
  }
  else
  {
    acc = ((acc - checksum_81) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000707_713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000707_713_3 st_1 = {0};
  struct Vector3D_R000707_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int window_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_73_1)
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

  switch (window_73_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_73_1 == window_73_2);
}

int fn_R000707_713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000707_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int window_73 = (aux + st.buffer[1]) & 3;
  switch (window_73)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000707_713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000707_713_3 st_1 = {0};
  struct Vector3D_R000707_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int scale_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_11_1 > 42)
  {
    acc_1 = ((acc_1 + (scale_11_1 * 2)) + 5) & 127;
    aux_1 ^= scale_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_11_2 > 42)
  {
    acc_2 = ((acc_2 + (scale_11_2 * 2)) + 5) & 127;
    aux_2 ^= scale_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_17_1)
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

  switch (tally_17_2)
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
  int weight_91_1 = local_arr_1[aux_1 % 3];
  int weight_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_91_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_11_1 == scale_11_2);
  assert(tally_17_1 == tally_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_91_1 == weight_91_2);
}

int fn_R000707_713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000707_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int scale_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_11 > 42)
  {
    acc = ((acc + (scale_11 * 2)) + 5) & 127;
    aux ^= scale_11 & 15;
  }
  else
  {
    acc = ((acc - scale_11) + 11) & 127;
    aux += 3;
  }
  int tally_17 = (aux + st.buffer[1]) & 3;
  switch (tally_17)
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
  int weight_91 = local_arr[aux % 3];
  acc = (acc + (weight_91 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000707_713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000707_713_3 st_1 = {0};
  struct Vector3D_R000707_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_64_1 = local_arr_1[aux_1 % 3];
  int tally_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_64_2 * 2)) & 127;
  int vector_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_70_1 > 27)
  {
    acc_1 = ((acc_1 + (vector_70_1 * 2)) + 5) & 127;
    aux_1 ^= vector_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_70_2 > 27)
  {
    acc_2 = ((acc_2 + (vector_70_2 * 2)) + 5) & 127;
    aux_2 ^= vector_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_64_1 == tally_64_2);
  assert(vector_70_1 == vector_70_2);
}

int fn_R000707_713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000707_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int tally_64 = local_arr[aux % 3];
  acc = (acc + (tally_64 * 2)) & 127;
  int vector_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_70 > 27)
  {
    acc = ((acc + (vector_70 * 2)) + 5) & 127;
    aux ^= vector_70 & 15;
  }
  else
  {
    acc = ((acc - vector_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000707_713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000707_713_1 st_1 = {0};
  struct DeviceConfig_R000707_713_1 st_2 = {0};
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
  int quantum_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_88_1) & 63;
  aux_2 = (aux_2 + quantum_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_33_1 = local_arr_1[aux_1 % 3];
  int weight_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_33_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_88_1 == quantum_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_33_1 == weight_33_2);
}

int fn_R000707_713_4(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000707_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_88) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_33 = local_arr[aux % 3];
  acc = (acc + (weight_33 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000707_713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000707_713_1 st_1 = {0};
  struct DeviceConfig_R000707_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_25_1 = local_arr_1[aux_1 % 3];
  int weight_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_25_2 * 2)) & 127;
  int anchor_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_23_1 > 32)
  {
    acc_1 = ((acc_1 + (anchor_23_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_23_2 > 32)
  {
    acc_2 = ((acc_2 + (anchor_23_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_97_1)
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

  switch (coefficient_97_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_25_1 == weight_25_2);
  assert(anchor_23_1 == anchor_23_2);
  assert(coefficient_97_1 == coefficient_97_2);
}

int fn_R000707_713_5(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000707_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_25 = local_arr[aux % 3];
  acc = (acc + (weight_25 * 2)) & 127;
  int anchor_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_23 > 32)
  {
    acc = ((acc + (anchor_23 * 2)) + 5) & 127;
    aux ^= anchor_23 & 15;
  }
  else
  {
    acc = ((acc - anchor_23) + 11) & 127;
    aux += 3;
  }
  int coefficient_97 = (aux + st.buffer[1]) & 3;
  switch (coefficient_97)
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

  return (acc + aux) & 255;
}

void fn_R000707_713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000707_713_2 st_1 = {0};
  struct SensorNode_R000707_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int mask_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_27_1 > 29)
  {
    acc_1 = ((acc_1 + (mask_27_1 * 2)) + 5) & 127;
    aux_1 ^= mask_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_27_2 > 29)
  {
    acc_2 = ((acc_2 + (mask_27_2 * 2)) + 5) & 127;
    aux_2 ^= mask_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_55_1 = local_arr_1[aux_1 % 3];
  int tally_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_55_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_27_1 == mask_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_55_1 == tally_55_2);
}

int fn_R000707_713_6(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000707_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int mask_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_27 > 29)
  {
    acc = ((acc + (mask_27 * 2)) + 5) & 127;
    aux ^= mask_27 & 15;
  }
  else
  {
    acc = ((acc - mask_27) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_55 = local_arr[aux % 3];
  acc = (acc + (tally_55 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000707_713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000707_713_3 st_1 = {0};
  struct Vector3D_R000707_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int vector_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_47_1) & 63;
  aux_2 = (aux_2 + vector_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_88_1 = local_arr_1[aux_1 % 3];
  int pivot_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_88_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_52_1 > 29)
  {
    acc_1 = ((acc_1 + (delta_52_1 * 2)) + 5) & 127;
    aux_1 ^= delta_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_52_2 > 29)
  {
    acc_2 = ((acc_2 + (delta_52_2 * 2)) + 5) & 127;
    aux_2 ^= delta_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_52_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_47_1 == vector_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_88_1 == pivot_88_2);
  assert(delta_52_1 == delta_52_2);
}

int fn_R000707_713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000707_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int vector_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_47) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_88 = local_arr[aux % 3];
  acc = (acc + (pivot_88 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_52 > 29)
  {
    acc = ((acc + (delta_52 * 2)) + 5) & 127;
    aux ^= delta_52 & 15;
  }
  else
  {
    acc = ((acc - delta_52) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000707_713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000707_713_2 st_1 = {0};
  struct SensorNode_R000707_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_22_1 = local_arr_1[aux_1 % 3];
  int anchor_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_22_2 * 2)) & 127;
  int quotient_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_66_1) & 63;
  aux_2 = (aux_2 + quotient_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_22_1 == anchor_22_2);
  assert(quotient_66_1 == quotient_66_2);
}

int fn_R000707_713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000707_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int anchor_22 = local_arr[aux % 3];
  acc = (acc + (anchor_22 * 2)) & 127;
  int quotient_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_66) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000707_713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000707_713_1 st_1 = {0};
  struct DeviceConfig_R000707_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_32_1 = local_arr_1[aux_1 % 3];
  int coefficient_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_32_2 * 2)) & 127;
  int accumulator_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_46_1) & 63;
  aux_2 = (aux_2 + accumulator_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_32_1 == coefficient_32_2);
  assert(accumulator_46_1 == accumulator_46_2);
}

int fn_R000707_713_9(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000707_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_32 = local_arr[aux % 3];
  acc = (acc + (coefficient_32 * 2)) & 127;
  int accumulator_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_46) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000707_713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000707_713_0 st_1 = {0};
  struct AudioFrame_R000707_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int damping_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_69_1) & 63;
  aux_2 = (aux_2 + damping_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_16_1 > 33)
  {
    acc_1 = ((acc_1 + (index_reg_16_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_16_2 > 33)
  {
    acc_2 = ((acc_2 + (index_reg_16_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_16_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_99_1)
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

  switch (mask_99_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_69_1 == damping_69_2);
  assert(index_reg_16_1 == index_reg_16_2);
  assert(mask_99_1 == mask_99_2);
}

int fn_R000707_713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000707_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int damping_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_69) & 63;
  acc ^= aux;
  int index_reg_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_16 > 33)
  {
    acc = ((acc + (index_reg_16 * 2)) + 5) & 127;
    aux ^= index_reg_16 & 15;
  }
  else
  {
    acc = ((acc - index_reg_16) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_99 = (aux + st.buffer[1]) & 3;
  switch (mask_99)
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

void fn_R000707_713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000707_713_1 st_1 = {0};
  struct DeviceConfig_R000707_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_51_1)
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

  switch (window_51_2)
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

  int segment_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_25_1) & 63;
  aux_2 = (aux_2 + segment_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_50_1 > 34)
  {
    acc_1 = ((acc_1 + (sample_50_1 * 2)) + 5) & 127;
    aux_1 ^= sample_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_50_2 > 34)
  {
    acc_2 = ((acc_2 + (sample_50_2 * 2)) + 5) & 127;
    aux_2 ^= sample_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_50_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_51_1 == window_51_2);
  assert(segment_25_1 == segment_25_2);
  assert(sample_50_1 == sample_50_2);
}

int fn_R000707_713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000707_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_51 = (aux + st.buffer[1]) & 3;
  switch (window_51)
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

  int segment_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_25) & 63;
  acc ^= aux;
  int sample_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_50 > 34)
  {
    acc = ((acc + (sample_50 * 2)) + 5) & 127;
    aux ^= sample_50 & 15;
  }
  else
  {
    acc = ((acc - sample_50) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000707_713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000707_713_1 st_1 = {0};
  struct DeviceConfig_R000707_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_99_1 = local_arr_1[aux_1 % 3];
  int damping_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_99_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_99_1 == damping_99_2);
}

int fn_R000707_713_12(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000707_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int damping_99 = local_arr[aux % 3];
  acc = (acc + (damping_99 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000707_713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000707_713_1 st_1 = {0};
  struct DeviceConfig_R000707_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_85_1)
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

  switch (damping_85_2)
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

  int anchor_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_99_1 > 30)
  {
    acc_1 = ((acc_1 + (anchor_99_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_99_2 > 30)
  {
    acc_2 = ((acc_2 + (anchor_99_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_93_1 = local_arr_1[aux_1 % 3];
  int stride_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_93_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_85_1 == damping_85_2);
  assert(anchor_99_1 == anchor_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_93_1 == stride_93_2);
}

int fn_R000707_713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000707_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_85 = (aux + st.buffer[1]) & 3;
  switch (damping_85)
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

  int anchor_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_99 > 30)
  {
    acc = ((acc + (anchor_99 * 2)) + 5) & 127;
    aux ^= anchor_99 & 15;
  }
  else
  {
    acc = ((acc - anchor_99) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int stride_93 = local_arr[aux % 3];
  acc = (acc + (stride_93 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000707_713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000707_713_3 st_1 = {0};
  struct Vector3D_R000707_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int threshold_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_84_1) & 63;
  aux_2 = (aux_2 + threshold_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_98_1 = local_arr_1[aux_1 % 3];
  int pivot_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_98_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_84_1 == threshold_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_98_1 == pivot_98_2);
}

int fn_R000707_713_14(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000707_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int threshold_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_84) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_98 = local_arr[aux % 3];
  acc = (acc + (pivot_98 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000707_713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000707_713_2 st_1 = {0};
  struct SensorNode_R000707_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int phase_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_55_1 > 49)
  {
    acc_1 = ((acc_1 + (phase_55_1 * 2)) + 5) & 127;
    aux_1 ^= phase_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_55_2 > 49)
  {
    acc_2 = ((acc_2 + (phase_55_2 * 2)) + 5) & 127;
    aux_2 ^= phase_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_55_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_55_1 == phase_55_2);
}

int fn_R000707_713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000707_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int phase_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_55 > 49)
  {
    acc = ((acc + (phase_55 * 2)) + 5) & 127;
    aux ^= phase_55 & 15;
  }
  else
  {
    acc = ((acc - phase_55) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000707_713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000707_713_0 st_1 = {0};
  struct AudioFrame_R000707_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_92_1 = local_arr_1[aux_1 % 3];
  int parity_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_92_2 * 2)) & 127;
  int factor_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_20_1 > 21)
  {
    acc_1 = ((acc_1 + (factor_20_1 * 2)) + 5) & 127;
    aux_1 ^= factor_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_20_2 > 21)
  {
    acc_2 = ((acc_2 + (factor_20_2 * 2)) + 5) & 127;
    aux_2 ^= factor_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_20_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_92_1 == parity_92_2);
  assert(factor_20_1 == factor_20_2);
}

int fn_R000707_713_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000707_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_92 = local_arr[aux % 3];
  acc = (acc + (parity_92 * 2)) & 127;
  int factor_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_20 > 21)
  {
    acc = ((acc + (factor_20 * 2)) + 5) & 127;
    aux ^= factor_20 & 15;
  }
  else
  {
    acc = ((acc - factor_20) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000707_713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000707_713_0 st_1 = {0};
  struct AudioFrame_R000707_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_59_1 = local_arr_1[aux_1 % 3];
  int anchor_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_59_2 * 2)) & 127;
  int coefficient_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_74_1)
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

  switch (coefficient_74_2)
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

  int weight_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_37_1) & 63;
  aux_2 = (aux_2 + weight_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_67_1 > 22)
  {
    acc_1 = ((acc_1 + (sample_67_1 * 2)) + 5) & 127;
    aux_1 ^= sample_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_67_2 > 22)
  {
    acc_2 = ((acc_2 + (sample_67_2 * 2)) + 5) & 127;
    aux_2 ^= sample_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_59_1 == anchor_59_2);
  assert(coefficient_74_1 == coefficient_74_2);
  assert(weight_37_1 == weight_37_2);
  assert(sample_67_1 == sample_67_2);
}

int fn_R000707_713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000707_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int anchor_59 = local_arr[aux % 3];
  acc = (acc + (anchor_59 * 2)) & 127;
  int coefficient_74 = (aux + st.buffer[1]) & 3;
  switch (coefficient_74)
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

  int weight_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_37) & 63;
  acc ^= aux;
  int sample_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_67 > 22)
  {
    acc = ((acc + (sample_67 * 2)) + 5) & 127;
    aux ^= sample_67 & 15;
  }
  else
  {
    acc = ((acc - sample_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000707_713_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000707_713_1 st_1 = {0};
  struct DeviceConfig_R000707_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int residue_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_94_1) & 63;
  aux_2 = (aux_2 + residue_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_86_1 > 10)
  {
    acc_1 = ((acc_1 + (factor_86_1 * 2)) + 5) & 127;
    aux_1 ^= factor_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_86_2 > 10)
  {
    acc_2 = ((acc_2 + (factor_86_2 * 2)) + 5) & 127;
    aux_2 ^= factor_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_86_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_94_1 == residue_94_2);
  assert(factor_86_1 == factor_86_2);
}

int fn_R000707_713_18(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000707_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int residue_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_94) & 63;
  acc ^= aux;
  int factor_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_86 > 10)
  {
    acc = ((acc + (factor_86 * 2)) + 5) & 127;
    aux ^= factor_86 & 15;
  }
  else
  {
    acc = ((acc - factor_86) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000707_0_1;
  int sec_r000707_0_2;
  int sec_r000707_1_1;
  int sec_r000707_1_2;
  int sec_r000707_2_1;
  int sec_r000707_2_2;
  int sec_r000707_3_1;
  int sec_r000707_3_2;
  int sec_r000707_4_1;
  int sec_r000707_4_2;
  int sec_r000707_5_1;
  int sec_r000707_5_2;
  int sec_r000707_6_1;
  int sec_r000707_6_2;
  int sec_r000707_7_1;
  int sec_r000707_7_2;
  int sec_r000707_8_1;
  int sec_r000707_8_2;
  int sec_r000707_9_1;
  int sec_r000707_9_2;
  int sec_r000707_10_1;
  int sec_r000707_10_2;
  int sec_r000707_11_1;
  int sec_r000707_11_2;
  int sec_r000707_12_1;
  int sec_r000707_12_2;
  int sec_r000707_13_1;
  int sec_r000707_13_2;
  int sec_r000707_14_1;
  int sec_r000707_14_2;
  int sec_r000707_15_1;
  int sec_r000707_15_2;
  int sec_r000707_16_1;
  int sec_r000707_16_2;
  int sec_r000707_17_1;
  int sec_r000707_17_2;
  int sec_r000707_18_1;
  int sec_r000707_18_2;
  int sec_r000707_19_1;
  int sec_r000707_19_2;
  int sec_r000707_20_1;
  int sec_r000707_20_2;
  int sec_r000707_21_1;
  int sec_r000707_21_2;
  int sec_r000707_22_1;
  int sec_r000707_22_2;
  int sec_r000707_23_1;
  int sec_r000707_23_2;
  int pub_r000707_0_1;
  int pub_r000707_0_2;
  int pub_r000707_1_1;
  int pub_r000707_1_2;
  int pub_r000707_2_1;
  int pub_r000707_2_2;
  int pub_r000707_3_1;
  int pub_r000707_3_2;
  int pub_r000707_4_1;
  int pub_r000707_4_2;
  int pub_r000707_5_1;
  int pub_r000707_5_2;
  int pub_r000707_6_1;
  int pub_r000707_6_2;
  int pub_r000707_7_1;
  int pub_r000707_7_2;
  int pub_r000707_8_1;
  int pub_r000707_8_2;
  int pub_r000707_9_1;
  int pub_r000707_9_2;
  int pub_r000707_10_1;
  int pub_r000707_10_2;
  int pub_r000707_11_1;
  int pub_r000707_11_2;
  int pub_r000707_12_1;
  int pub_r000707_12_2;
  int pub_r000707_13_1;
  int pub_r000707_13_2;
  int pub_r000707_14_1;
  int pub_r000707_14_2;
  int pub_r000707_15_1;
  int pub_r000707_15_2;
  int pub_r000707_16_1;
  int pub_r000707_16_2;
  int pub_r000707_17_1;
  int pub_r000707_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000707_0_1 >= (-100)) && (pub_r000707_0_1 <= 100));
  __CPROVER_assume((pub_r000707_0_2 >= (-100)) && (pub_r000707_0_2 <= 100));
  __CPROVER_assume((pub_r000707_1_1 >= (-100)) && (pub_r000707_1_1 <= 100));
  __CPROVER_assume((pub_r000707_1_2 >= (-100)) && (pub_r000707_1_2 <= 100));
  __CPROVER_assume((pub_r000707_2_1 >= (-100)) && (pub_r000707_2_1 <= 100));
  __CPROVER_assume((pub_r000707_2_2 >= (-100)) && (pub_r000707_2_2 <= 100));
  __CPROVER_assume((pub_r000707_3_1 >= (-100)) && (pub_r000707_3_1 <= 100));
  __CPROVER_assume((pub_r000707_3_2 >= (-100)) && (pub_r000707_3_2 <= 100));
  __CPROVER_assume((pub_r000707_4_1 >= (-100)) && (pub_r000707_4_1 <= 100));
  __CPROVER_assume((pub_r000707_4_2 >= (-100)) && (pub_r000707_4_2 <= 100));
  __CPROVER_assume((pub_r000707_5_1 >= (-100)) && (pub_r000707_5_1 <= 100));
  __CPROVER_assume((pub_r000707_5_2 >= (-100)) && (pub_r000707_5_2 <= 100));
  __CPROVER_assume((pub_r000707_6_1 >= (-100)) && (pub_r000707_6_1 <= 100));
  __CPROVER_assume((pub_r000707_6_2 >= (-100)) && (pub_r000707_6_2 <= 100));
  __CPROVER_assume((pub_r000707_7_1 >= (-100)) && (pub_r000707_7_1 <= 100));
  __CPROVER_assume((pub_r000707_7_2 >= (-100)) && (pub_r000707_7_2 <= 100));
  __CPROVER_assume((pub_r000707_8_1 >= (-100)) && (pub_r000707_8_1 <= 100));
  __CPROVER_assume((pub_r000707_8_2 >= (-100)) && (pub_r000707_8_2 <= 100));
  __CPROVER_assume((pub_r000707_9_1 >= (-100)) && (pub_r000707_9_1 <= 100));
  __CPROVER_assume((pub_r000707_9_2 >= (-100)) && (pub_r000707_9_2 <= 100));
  __CPROVER_assume((pub_r000707_10_1 >= (-100)) && (pub_r000707_10_1 <= 100));
  __CPROVER_assume((pub_r000707_10_2 >= (-100)) && (pub_r000707_10_2 <= 100));
  __CPROVER_assume((pub_r000707_11_1 >= (-100)) && (pub_r000707_11_1 <= 100));
  __CPROVER_assume((pub_r000707_11_2 >= (-100)) && (pub_r000707_11_2 <= 100));
  __CPROVER_assume((pub_r000707_12_1 >= (-100)) && (pub_r000707_12_1 <= 100));
  __CPROVER_assume((pub_r000707_12_2 >= (-100)) && (pub_r000707_12_2 <= 100));
  __CPROVER_assume((pub_r000707_13_1 >= (-100)) && (pub_r000707_13_1 <= 100));
  __CPROVER_assume((pub_r000707_13_2 >= (-100)) && (pub_r000707_13_2 <= 100));
  __CPROVER_assume((pub_r000707_14_1 >= (-100)) && (pub_r000707_14_1 <= 100));
  __CPROVER_assume((pub_r000707_14_2 >= (-100)) && (pub_r000707_14_2 <= 100));
  __CPROVER_assume((pub_r000707_15_1 >= (-100)) && (pub_r000707_15_1 <= 100));
  __CPROVER_assume((pub_r000707_15_2 >= (-100)) && (pub_r000707_15_2 <= 100));
  __CPROVER_assume((pub_r000707_16_1 >= (-100)) && (pub_r000707_16_1 <= 100));
  __CPROVER_assume((pub_r000707_16_2 >= (-100)) && (pub_r000707_16_2 <= 100));
  __CPROVER_assume((pub_r000707_17_1 >= (-100)) && (pub_r000707_17_1 <= 100));
  __CPROVER_assume((pub_r000707_17_2 >= (-100)) && (pub_r000707_17_2 <= 100));
  __CPROVER_assume((sec_r000707_0_1 >= 0) && (sec_r000707_0_1 <= 255));
  __CPROVER_assume((sec_r000707_0_2 >= 0) && (sec_r000707_0_2 <= 255));
  __CPROVER_assume((sec_r000707_1_1 >= 0) && (sec_r000707_1_1 <= 255));
  __CPROVER_assume((sec_r000707_1_2 >= 0) && (sec_r000707_1_2 <= 255));
  __CPROVER_assume((sec_r000707_2_1 >= 0) && (sec_r000707_2_1 <= 255));
  __CPROVER_assume((sec_r000707_2_2 >= 0) && (sec_r000707_2_2 <= 255));
  __CPROVER_assume((sec_r000707_3_1 >= 0) && (sec_r000707_3_1 <= 255));
  __CPROVER_assume((sec_r000707_3_2 >= 0) && (sec_r000707_3_2 <= 255));
  __CPROVER_assume((sec_r000707_4_1 >= 0) && (sec_r000707_4_1 <= 255));
  __CPROVER_assume((sec_r000707_4_2 >= 0) && (sec_r000707_4_2 <= 255));
  __CPROVER_assume((sec_r000707_5_1 >= 0) && (sec_r000707_5_1 <= 255));
  __CPROVER_assume((sec_r000707_5_2 >= 0) && (sec_r000707_5_2 <= 255));
  __CPROVER_assume((sec_r000707_6_1 >= 0) && (sec_r000707_6_1 <= 255));
  __CPROVER_assume((sec_r000707_6_2 >= 0) && (sec_r000707_6_2 <= 255));
  __CPROVER_assume((sec_r000707_7_1 >= 0) && (sec_r000707_7_1 <= 255));
  __CPROVER_assume((sec_r000707_7_2 >= 0) && (sec_r000707_7_2 <= 255));
  __CPROVER_assume((sec_r000707_8_1 >= 0) && (sec_r000707_8_1 <= 255));
  __CPROVER_assume((sec_r000707_8_2 >= 0) && (sec_r000707_8_2 <= 255));
  __CPROVER_assume((sec_r000707_9_1 >= 0) && (sec_r000707_9_1 <= 255));
  __CPROVER_assume((sec_r000707_9_2 >= 0) && (sec_r000707_9_2 <= 255));
  __CPROVER_assume((sec_r000707_10_1 >= 0) && (sec_r000707_10_1 <= 255));
  __CPROVER_assume((sec_r000707_10_2 >= 0) && (sec_r000707_10_2 <= 255));
  __CPROVER_assume((sec_r000707_11_1 >= 0) && (sec_r000707_11_1 <= 255));
  __CPROVER_assume((sec_r000707_11_2 >= 0) && (sec_r000707_11_2 <= 255));
  __CPROVER_assume((sec_r000707_12_1 >= 0) && (sec_r000707_12_1 <= 255));
  __CPROVER_assume((sec_r000707_12_2 >= 0) && (sec_r000707_12_2 <= 255));
  __CPROVER_assume((sec_r000707_13_1 >= 0) && (sec_r000707_13_1 <= 255));
  __CPROVER_assume((sec_r000707_13_2 >= 0) && (sec_r000707_13_2 <= 255));
  __CPROVER_assume((sec_r000707_14_1 >= 0) && (sec_r000707_14_1 <= 255));
  __CPROVER_assume((sec_r000707_14_2 >= 0) && (sec_r000707_14_2 <= 255));
  __CPROVER_assume((sec_r000707_15_1 >= 0) && (sec_r000707_15_1 <= 255));
  __CPROVER_assume((sec_r000707_15_2 >= 0) && (sec_r000707_15_2 <= 255));
  __CPROVER_assume((sec_r000707_16_1 >= 0) && (sec_r000707_16_1 <= 255));
  __CPROVER_assume((sec_r000707_16_2 >= 0) && (sec_r000707_16_2 <= 255));
  __CPROVER_assume((sec_r000707_17_1 >= 0) && (sec_r000707_17_1 <= 255));
  __CPROVER_assume((sec_r000707_17_2 >= 0) && (sec_r000707_17_2 <= 255));
  __CPROVER_assume((sec_r000707_18_1 >= 0) && (sec_r000707_18_1 <= 255));
  __CPROVER_assume((sec_r000707_18_2 >= 0) && (sec_r000707_18_2 <= 255));
  __CPROVER_assume((sec_r000707_19_1 >= 0) && (sec_r000707_19_1 <= 255));
  __CPROVER_assume((sec_r000707_19_2 >= 0) && (sec_r000707_19_2 <= 255));
  __CPROVER_assume((sec_r000707_20_1 >= 0) && (sec_r000707_20_1 <= 255));
  __CPROVER_assume((sec_r000707_20_2 >= 0) && (sec_r000707_20_2 <= 255));
  __CPROVER_assume((sec_r000707_21_1 >= 0) && (sec_r000707_21_1 <= 255));
  __CPROVER_assume((sec_r000707_21_2 >= 0) && (sec_r000707_21_2 <= 255));
  __CPROVER_assume((sec_r000707_22_1 >= 0) && (sec_r000707_22_1 <= 255));
  __CPROVER_assume((sec_r000707_22_2 >= 0) && (sec_r000707_22_2 <= 255));
  __CPROVER_assume((sec_r000707_23_1 >= 0) && (sec_r000707_23_1 <= 255));
  __CPROVER_assume((sec_r000707_23_2 >= 0) && (sec_r000707_23_2 <= 255));
  struct AudioFrame_R000707_713_0 st_var_0_1 = {0};
  struct AudioFrame_R000707_713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000707_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000707_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000707_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000707_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000707_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000707_0_2 + 7) & 15;
  struct DeviceConfig_R000707_713_1 st_var_1_1 = {0};
  struct DeviceConfig_R000707_713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000707_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000707_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000707_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000707_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000707_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000707_0_2 + 9) & 15;
  struct SensorNode_R000707_713_2 st_var_2_1 = {0};
  struct SensorNode_R000707_713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000707_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000707_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000707_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000707_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000707_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000707_0_2 + 11) & 15;
  struct Vector3D_R000707_713_3 st_var_3_1 = {0};
  struct Vector3D_R000707_713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000707_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000707_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000707_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000707_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000707_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000707_0_2 + 13) & 15;
  union ColorPixel_R000707_713_0 u_var_1;
  union ColorPixel_R000707_713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = ((st_var_3_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_3_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 38)
    {
      chk_sum_1 ^= stage_v_3_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_3_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 38)
    {
      chk_sum_2 ^= stage_v_3_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 30)
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
  if (stage_v_4_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 30)
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
  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = ((st_var_3_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_3_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 27)
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
  if (stage_v_11_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 27)
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
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
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
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 16) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  int stage_v_17_1 = ((st_var_1_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_1_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 33)
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
  if (stage_v_17_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 33)
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
  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 23) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
  int stage_v_23_1 = ((st_var_3_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_3_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 28)
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
  if (stage_v_23_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 28)
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

  switch (stage_v_24_2)
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
  int stage_v_27_1 = (st_var_3_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_3_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
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

  switch (stage_v_27_2)
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

  int stage_v_28_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (33 & 31);
  int stage_v_28_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (33 & 31);
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= (stage_v_28_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_28_2 << 1) & 127;
  int stage_v_29_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_29_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_31_1 = (st_var_3_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_3_2.buffer[0] ^ 34) & 3;
  switch (stage_v_31_1)
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

  switch (stage_v_31_2)
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

  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
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
  int stage_v_35_1 = ((st_var_3_1.buffer[2] * 2) + 112) & 63;
  int stage_v_35_2 = ((st_var_3_2.buffer[2] * 2) + 112) & 63;
  if (stage_v_35_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_35_1) - 5) & 255;
    if (stage_v_35_1 > 38)
    {
      chk_sum_1 ^= stage_v_35_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_35_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_35_2) - 5) & 255;
    if (stage_v_35_2 > 38)
    {
      chk_sum_2 ^= stage_v_35_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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

  switch (stage_v_37_2)
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

  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_39_1 = (st_var_3_1.buffer[0] ^ 42) & 3;
  int stage_v_39_2 = (st_var_3_2.buffer[0] ^ 42) & 3;
  switch (stage_v_39_1)
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

  switch (stage_v_39_2)
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

  int stage_v_40_1 = ((st_var_0_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_0_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 33)
    {
      chk_sum_1 ^= stage_v_40_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_40_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 33)
    {
      chk_sum_2 ^= stage_v_40_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_43_1 = (st_var_3_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_3_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
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

  switch (stage_v_43_2)
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

  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
  int stage_v_45_1 = table_1[1];
  int stage_v_45_2 = table_2[1];
  table_1[1] = (table_1[2] + 91) & 63;
  table_2[1] = (table_2[2] + 91) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
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
  int stage_v_49_1 = table_1[1];
  int stage_v_49_2 = table_2[1];
  table_1[1] = (table_1[2] + 99) & 63;
  table_2[1] = (table_2[2] + 99) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
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
  int stage_v_51_1 = ((st_var_3_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_3_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 54)
    {
      chk_sum_1 ^= stage_v_51_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_51_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 54)
    {
      chk_sum_2 ^= stage_v_51_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_52_1 = (st_var_0_1.buffer[0] ^ 55) & 3;
  int stage_v_52_2 = (st_var_0_2.buffer[0] ^ 55) & 3;
  switch (stage_v_52_1)
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

  switch (stage_v_52_2)
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

  int stage_v_53_1 = table_1[1];
  int stage_v_53_2 = table_2[1];
  table_1[1] = (table_1[2] + 107) & 63;
  table_2[1] = (table_2[2] + 107) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = table_1[2];
  int stage_v_54_2 = table_2[2];
  table_1[2] = (table_1[3] + 109) & 63;
  table_2[2] = (table_2[3] + 109) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (60 & 31);
  int stage_v_55_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (60 & 31);
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= (stage_v_55_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_55_2 << 1) & 127;
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
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 60) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 60) & 15;
  int stage_v_59_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_59_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= stage_v_59_1;
  chk_sum_2 ^= stage_v_59_2;
  int stage_v_60_1 = (st_var_0_1.buffer[0] ^ 63) & 3;
  int stage_v_60_2 = (st_var_0_2.buffer[0] ^ 63) & 3;
  switch (stage_v_60_1)
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

  switch (stage_v_60_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 62) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 62) & 15;
  int stage_v_61_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_61_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= stage_v_61_1;
  chk_sum_2 ^= stage_v_61_2;
  int stage_v_62_1 = ((st_var_2_1.buffer[2] * 2) + 193) & 63;
  int stage_v_62_2 = ((st_var_2_2.buffer[2] * 2) + 193) & 63;
  if (stage_v_62_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_62_1) - 5) & 255;
    if (stage_v_62_1 > 44)
    {
      chk_sum_1 ^= stage_v_62_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_62_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_62_2) - 5) & 255;
    if (stage_v_62_2 > 44)
    {
      chk_sum_2 ^= stage_v_62_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_63_1 = (st_var_3_1.buffer[0] ^ 66) & 3;
  int stage_v_63_2 = (st_var_3_2.buffer[0] ^ 66) & 3;
  switch (stage_v_63_1)
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

  switch (stage_v_63_2)
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

  int stage_v_64_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_64_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_65_1 = (st_var_1_1.buffer[0] ^ 68) & 3;
  int stage_v_65_2 = (st_var_1_2.buffer[0] ^ 68) & 3;
  switch (stage_v_65_1)
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

  switch (stage_v_65_2)
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

  int stage_v_66_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (71 & 31);
  int stage_v_66_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (71 & 31);
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= (stage_v_66_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_66_2 << 1) & 127;
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 69) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 69) & 15;
  int stage_v_68_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_68_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= stage_v_68_1;
  chk_sum_2 ^= stage_v_68_2;
  int stage_v_69_1 = table_1[1];
  int stage_v_69_2 = table_2[1];
  table_1[1] = (table_1[2] + 139) & 63;
  table_2[1] = (table_2[2] + 139) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_70_1 = ((stage_v_70_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_70_2 = ((stage_v_70_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 72) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 72) & 15;
  int stage_v_71_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_71_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= stage_v_71_1;
  chk_sum_2 ^= stage_v_71_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 73) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 73) & 15;
  int stage_v_72_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_72_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= stage_v_72_1;
  chk_sum_2 ^= stage_v_72_2;
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
  int stage_v_75_1 = (st_var_3_1.buffer[0] ^ 78) & 3;
  int stage_v_75_2 = (st_var_3_2.buffer[0] ^ 78) & 3;
  switch (stage_v_75_1)
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

  switch (stage_v_75_2)
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

  int stage_v_76_1 = ((st_var_0_1.buffer[1] * 2) + 235) & 63;
  int stage_v_76_2 = ((st_var_0_2.buffer[1] * 2) + 235) & 63;
  if (stage_v_76_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_76_1) - 5) & 255;
    if (stage_v_76_1 > 51)
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
  if (stage_v_76_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_76_2) - 5) & 255;
    if (stage_v_76_2 > 51)
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
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (83 & 31);
  int stage_v_78_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (83 & 31);
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= (stage_v_78_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_78_2 << 1) & 127;
  int stage_v_79_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_79_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_79_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_79_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_80_1 = (st_var_0_1.buffer[0] ^ 83) & 3;
  int stage_v_80_2 = (st_var_0_2.buffer[0] ^ 83) & 3;
  switch (stage_v_80_1)
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

  switch (stage_v_80_2)
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

  int stage_v_81_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (86 & 31);
  int stage_v_81_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (86 & 31);
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  chk_sum_1 ^= (stage_v_81_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_81_2 << 1) & 127;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 83) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 83) & 15;
  int stage_v_82_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_82_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= stage_v_82_1;
  chk_sum_2 ^= stage_v_82_2;
  int stage_v_83_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_83_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_83_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_83_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_84_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_84_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_85_1 = table_1[1];
  int stage_v_85_2 = table_2[1];
  table_1[1] = (table_1[2] + 171) & 63;
  table_2[1] = (table_2[2] + 171) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
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
  int stage_v_88_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (93 & 31);
  int stage_v_88_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (93 & 31);
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= (stage_v_88_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_88_2 << 1) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 90) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 90) & 15;
  int stage_v_89_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_89_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= stage_v_89_1;
  chk_sum_2 ^= stage_v_89_2;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000707_3_1 & 1) != 0)
  {
    if ((sec_r000707_1_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000707_4_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000707_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000707_4_1 + 7) & 127;
  }
  if ((sec_r000707_3_2 & 1) != 0)
  {
    if ((sec_r000707_1_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000707_4_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000707_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000707_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000707_16_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000707_6_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000707_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000707_6_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000707_16_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000707_6_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000707_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000707_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000707_3_1 & 1) != 0)
  {
    if ((sec_r000707_13_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000707_6_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000707_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000707_6_1 + 7) & 127;
  }
  if ((sec_r000707_3_2 & 1) != 0)
  {
    if ((sec_r000707_13_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000707_6_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000707_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000707_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000707_19_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000707_4_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000707_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000707_4_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000707_19_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000707_4_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000707_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000707_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000707_6_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000707_15_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000707_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000707_15_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000707_6_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000707_15_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000707_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000707_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000707_14_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000707_7_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000707_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000707_7_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000707_14_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000707_7_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000707_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000707_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000707_2_1 & 1) != 0)
  {
    if ((sec_r000707_16_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000707_15_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000707_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000707_15_1 + 7) & 127;
  }
  if ((sec_r000707_2_2 & 1) != 0)
  {
    if ((sec_r000707_16_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000707_15_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000707_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000707_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000707_20_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000707_1_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000707_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000707_1_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000707_20_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000707_1_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000707_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000707_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000707_2_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000707_13_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000707_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000707_13_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000707_2_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000707_13_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000707_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000707_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000707_15_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000707_8_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000707_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000707_8_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000707_15_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000707_8_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000707_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000707_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000707_22_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000707_12_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000707_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000707_12_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000707_22_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000707_12_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000707_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000707_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000707_15_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000707_0_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000707_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000707_0_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000707_15_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000707_0_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000707_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000707_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000707_21_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000707_0_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000707_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000707_0_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000707_21_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000707_0_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000707_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000707_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000707_5_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000707_4_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000707_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000707_4_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000707_5_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000707_4_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000707_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000707_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000707_15_1 & 1) != 0)
  {
    if ((sec_r000707_14_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000707_16_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000707_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000707_16_1 + 7) & 127;
  }
  if ((sec_r000707_15_2 & 1) != 0)
  {
    if ((sec_r000707_14_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000707_16_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000707_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000707_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000707_12_1 & 1) != 0)
  {
    if ((sec_r000707_21_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000707_13_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000707_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000707_13_1 + 7) & 127;
  }
  if ((sec_r000707_12_2 & 1) != 0)
  {
    if ((sec_r000707_21_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000707_13_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000707_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000707_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000707_16_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000707_1_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000707_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000707_1_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000707_16_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000707_1_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000707_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000707_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000707_1_1 & 1) != 0)
  {
    if ((sec_r000707_12_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000707_1_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000707_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000707_1_1 + 7) & 127;
  }
  if ((sec_r000707_1_2 & 1) != 0)
  {
    if ((sec_r000707_12_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000707_1_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000707_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000707_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000707_5_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000707_2_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000707_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000707_2_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000707_5_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000707_2_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000707_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000707_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000707_14_1 & 1) != 0)
  {
    if ((sec_r000707_23_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000707_10_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000707_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000707_10_1 + 7) & 127;
  }
  if ((sec_r000707_14_2 & 1) != 0)
  {
    if ((sec_r000707_23_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000707_10_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000707_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000707_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000707_9_1 & 1) != 0)
  {
    if ((sec_r000707_22_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000707_16_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000707_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000707_16_1 + 7) & 127;
  }
  if ((sec_r000707_9_2 & 1) != 0)
  {
    if ((sec_r000707_22_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000707_16_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000707_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000707_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000707_6_1 & 1) != 0)
  {
    if ((sec_r000707_5_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000707_8_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000707_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000707_8_1 + 7) & 127;
  }
  if ((sec_r000707_6_2 & 1) != 0)
  {
    if ((sec_r000707_5_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000707_8_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000707_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000707_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000707_22_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000707_2_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000707_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000707_2_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000707_22_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000707_2_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000707_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000707_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000707_22_1 & 1) != 0)
  {
    if ((sec_r000707_5_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000707_9_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000707_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000707_9_1 + 7) & 127;
  }
  if ((sec_r000707_22_2 & 1) != 0)
  {
    if ((sec_r000707_5_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000707_9_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000707_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000707_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000707_10_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000707_0_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000707_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000707_0_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000707_10_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000707_0_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000707_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000707_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000707_23_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000707_7_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000707_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000707_7_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000707_23_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000707_7_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000707_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000707_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000707_20_1 & 1) != 0)
  {
    if ((sec_r000707_17_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000707_12_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000707_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000707_12_1 + 7) & 127;
  }
  if ((sec_r000707_20_2 & 1) != 0)
  {
    if ((sec_r000707_17_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000707_12_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000707_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000707_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000707_19_1 & 1) != 0)
  {
    if ((sec_r000707_4_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000707_6_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000707_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000707_6_1 + 7) & 127;
  }
  if ((sec_r000707_19_2 & 1) != 0)
  {
    if ((sec_r000707_4_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000707_6_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000707_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000707_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000707_14_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000707_12_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000707_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000707_12_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000707_14_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000707_12_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000707_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000707_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000707_13_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000707_9_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000707_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000707_9_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000707_13_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000707_9_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000707_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000707_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000707_9_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000707_14_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000707_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000707_14_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000707_9_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000707_14_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000707_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000707_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000707_18_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000707_1_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000707_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000707_1_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000707_18_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000707_1_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000707_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000707_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000707_14_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000707_15_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000707_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000707_15_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000707_14_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000707_15_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000707_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000707_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000707_14_1 & 1) != 0)
  {
    if ((sec_r000707_19_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000707_13_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000707_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000707_13_1 + 7) & 127;
  }
  if ((sec_r000707_14_2 & 1) != 0)
  {
    if ((sec_r000707_19_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000707_13_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000707_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000707_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000707_3_1 & 1) != 0)
  {
    if ((sec_r000707_8_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000707_2_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000707_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000707_2_1 + 7) & 127;
  }
  if ((sec_r000707_3_2 & 1) != 0)
  {
    if ((sec_r000707_8_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000707_2_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000707_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000707_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000707_4_1 & 1) != 0)
  {
    if ((sec_r000707_7_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000707_9_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000707_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000707_9_1 + 7) & 127;
  }
  if ((sec_r000707_4_2 & 1) != 0)
  {
    if ((sec_r000707_7_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000707_9_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000707_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000707_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000707_10_1 & 1) != 0)
  {
    if ((sec_r000707_3_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000707_7_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000707_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000707_7_1 + 7) & 127;
  }
  if ((sec_r000707_10_2 & 1) != 0)
  {
    if ((sec_r000707_3_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000707_7_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000707_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000707_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000707_5_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000707_12_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000707_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000707_12_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000707_5_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000707_12_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000707_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000707_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000707_18_1 & 1) != 0)
  {
    if ((sec_r000707_1_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000707_9_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000707_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000707_9_1 + 7) & 127;
  }
  if ((sec_r000707_18_2 & 1) != 0)
  {
    if ((sec_r000707_1_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000707_9_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000707_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000707_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((sec_r000707_10_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000707_2_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000707_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000707_2_1 + 7) & 127;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((sec_r000707_10_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000707_2_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000707_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000707_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((sec_r000707_1_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000707_2_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000707_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000707_2_1 + 7) & 127;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((sec_r000707_1_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000707_2_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000707_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000707_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000707_4_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000707_3_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000707_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000707_3_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000707_4_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000707_3_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000707_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000707_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000707_16_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000707_6_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000707_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000707_6_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000707_16_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000707_6_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000707_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000707_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((sec_r000707_4_1 & 1) != 0)
  {
    if ((sec_r000707_13_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000707_11_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000707_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000707_11_1 + 7) & 127;
  }
  if ((sec_r000707_4_2 & 1) != 0)
  {
    if ((sec_r000707_13_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000707_11_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000707_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000707_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((sec_r000707_17_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000707_9_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000707_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000707_9_1 + 7) & 127;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((sec_r000707_17_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000707_9_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000707_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000707_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000707_21_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000707_6_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000707_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000707_6_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000707_21_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000707_6_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000707_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000707_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000707_16_1 & 1) != 0)
  {
    if ((sec_r000707_1_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000707_4_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000707_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000707_4_1 + 7) & 127;
  }
  if ((sec_r000707_16_2 & 1) != 0)
  {
    if ((sec_r000707_1_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000707_4_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000707_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000707_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((sec_r000707_12_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000707_12_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000707_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000707_12_1 + 7) & 127;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((sec_r000707_12_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000707_12_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000707_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000707_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000707_8_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000707_7_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000707_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000707_7_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000707_8_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000707_7_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000707_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000707_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_135_1 & 1) != 0)
  {
    if ((sec_r000707_6_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000707_15_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000707_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000707_15_1 + 7) & 127;
  }
  if ((stage_v_135_2 & 1) != 0)
  {
    if ((sec_r000707_6_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000707_15_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000707_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000707_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000707_4_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000707_4_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000707_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000707_4_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000707_4_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000707_4_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000707_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000707_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((sec_r000707_10_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000707_7_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000707_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000707_7_1 + 7) & 127;
  }
  if ((stage_v_131_2 & 1) != 0)
  {
    if ((sec_r000707_10_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000707_7_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000707_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000707_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000707_3_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000707_6_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000707_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000707_6_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000707_3_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000707_6_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000707_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000707_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((sec_r000707_16_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000707_17_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000707_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000707_17_1 + 7) & 127;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((sec_r000707_16_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000707_17_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000707_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000707_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000707_9_1 & 1) != 0)
  {
    if ((sec_r000707_18_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000707_15_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000707_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000707_15_1 + 7) & 127;
  }
  if ((sec_r000707_9_2 & 1) != 0)
  {
    if ((sec_r000707_18_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000707_15_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000707_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000707_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((sec_r000707_2_1 & 1) != 0)
  {
    if ((sec_r000707_10_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000707_17_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000707_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000707_17_1 + 7) & 127;
  }
  if ((sec_r000707_2_2 & 1) != 0)
  {
    if ((sec_r000707_10_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000707_17_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000707_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000707_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000707_9_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000707_11_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000707_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000707_11_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000707_9_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000707_11_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000707_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000707_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000707_23_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000707_8_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000707_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000707_8_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000707_23_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000707_8_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000707_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000707_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000707_7_1 & 1) != 0)
  {
    if ((sec_r000707_22_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000707_0_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000707_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000707_0_1 + 7) & 127;
  }
  if ((sec_r000707_7_2 & 1) != 0)
  {
    if ((sec_r000707_22_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000707_0_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000707_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000707_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((sec_r000707_11_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000707_12_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000707_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000707_12_1 + 7) & 127;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((sec_r000707_11_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000707_12_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000707_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000707_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000707_20_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000707_0_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000707_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000707_0_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000707_20_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000707_0_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000707_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000707_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000707_7_1 & 1) != 0)
  {
    if ((sec_r000707_11_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000707_17_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000707_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000707_17_1 + 7) & 127;
  }
  if ((sec_r000707_7_2 & 1) != 0)
  {
    if ((sec_r000707_11_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000707_17_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000707_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000707_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((sec_r000707_13_1 & 1) != 0)
  {
    if ((sec_r000707_17_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000707_9_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000707_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000707_9_1 + 7) & 127;
  }
  if ((sec_r000707_13_2 & 1) != 0)
  {
    if ((sec_r000707_17_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000707_9_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000707_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000707_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000707_0_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000707_4_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000707_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000707_4_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000707_0_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000707_4_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000707_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000707_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((sec_r000707_16_1 & 1) != 0)
  {
    if ((sec_r000707_16_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000707_0_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000707_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000707_0_1 + 7) & 127;
  }
  if ((sec_r000707_16_2 & 1) != 0)
  {
    if ((sec_r000707_16_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000707_0_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000707_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000707_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((sec_r000707_9_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000707_11_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000707_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000707_11_1 + 7) & 127;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((sec_r000707_9_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000707_11_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000707_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000707_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((sec_r000707_1_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000707_8_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000707_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000707_8_1 + 7) & 127;
  }
  if ((stage_v_150_2 & 1) != 0)
  {
    if ((sec_r000707_1_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000707_8_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000707_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000707_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((sec_r000707_17_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000707_16_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000707_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000707_16_1 + 7) & 127;
  }
  if ((stage_v_154_2 & 1) != 0)
  {
    if ((sec_r000707_17_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000707_16_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000707_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000707_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((sec_r000707_7_1 & 1) != 0)
  {
    if ((sec_r000707_6_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000707_9_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000707_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000707_9_1 + 7) & 127;
  }
  if ((sec_r000707_7_2 & 1) != 0)
  {
    if ((sec_r000707_6_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000707_9_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000707_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000707_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000707_12_1 & 2) != 0)
    {
      stage_v_159_1 = (pub_r000707_13_1 + 31) & 127;
    }
    else
    {
      stage_v_159_1 = (pub_r000707_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_1 = (pub_r000707_13_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000707_12_2 & 2) != 0)
    {
      stage_v_159_2 = (pub_r000707_13_2 + 31) & 127;
    }
    else
    {
      stage_v_159_2 = (pub_r000707_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_2 = (pub_r000707_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((sec_r000707_16_1 & 2) != 0)
    {
      stage_v_160_1 = (pub_r000707_17_1 + 31) & 127;
    }
    else
    {
      stage_v_160_1 = (pub_r000707_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_1 = (pub_r000707_17_1 + 7) & 127;
  }
  if ((stage_v_141_2 & 1) != 0)
  {
    if ((sec_r000707_16_2 & 2) != 0)
    {
      stage_v_160_2 = (pub_r000707_17_2 + 31) & 127;
    }
    else
    {
      stage_v_160_2 = (pub_r000707_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_2 = (pub_r000707_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r000707_23_1 & 2) != 0)
    {
      stage_v_161_1 = (pub_r000707_12_1 + 31) & 127;
    }
    else
    {
      stage_v_161_1 = (pub_r000707_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_1 = (pub_r000707_12_1 + 7) & 127;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r000707_23_2 & 2) != 0)
    {
      stage_v_161_2 = (pub_r000707_12_2 + 31) & 127;
    }
    else
    {
      stage_v_161_2 = (pub_r000707_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_2 = (pub_r000707_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((sec_r000707_18_1 & 1) != 0)
  {
    if ((sec_r000707_13_1 & 2) != 0)
    {
      stage_v_162_1 = (pub_r000707_2_1 + 31) & 127;
    }
    else
    {
      stage_v_162_1 = (pub_r000707_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_1 = (pub_r000707_2_1 + 7) & 127;
  }
  if ((sec_r000707_18_2 & 1) != 0)
  {
    if ((sec_r000707_13_2 & 2) != 0)
    {
      stage_v_162_2 = (pub_r000707_2_2 + 31) & 127;
    }
    else
    {
      stage_v_162_2 = (pub_r000707_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_2 = (pub_r000707_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((sec_r000707_8_1 & 1) != 0)
  {
    if ((sec_r000707_22_1 & 2) != 0)
    {
      stage_v_163_1 = (pub_r000707_4_1 + 31) & 127;
    }
    else
    {
      stage_v_163_1 = (pub_r000707_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_1 = (pub_r000707_4_1 + 7) & 127;
  }
  if ((sec_r000707_8_2 & 1) != 0)
  {
    if ((sec_r000707_22_2 & 2) != 0)
    {
      stage_v_163_2 = (pub_r000707_4_2 + 31) & 127;
    }
    else
    {
      stage_v_163_2 = (pub_r000707_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_2 = (pub_r000707_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  if ((sec_r000707_18_1 & 1) != 0)
  {
    if ((sec_r000707_3_1 & 2) != 0)
    {
      stage_v_164_1 = (pub_r000707_7_1 + 31) & 127;
    }
    else
    {
      stage_v_164_1 = (pub_r000707_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_1 = (pub_r000707_7_1 + 7) & 127;
  }
  if ((sec_r000707_18_2 & 1) != 0)
  {
    if ((sec_r000707_3_2 & 2) != 0)
    {
      stage_v_164_2 = (pub_r000707_7_2 + 31) & 127;
    }
    else
    {
      stage_v_164_2 = (pub_r000707_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_2 = (pub_r000707_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  if ((sec_r000707_21_1 & 1) != 0)
  {
    if ((sec_r000707_21_1 & 2) != 0)
    {
      stage_v_165_1 = (pub_r000707_1_1 + 31) & 127;
    }
    else
    {
      stage_v_165_1 = (pub_r000707_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_1 = (pub_r000707_1_1 + 7) & 127;
  }
  if ((sec_r000707_21_2 & 1) != 0)
  {
    if ((sec_r000707_21_2 & 2) != 0)
    {
      stage_v_165_2 = (pub_r000707_1_2 + 31) & 127;
    }
    else
    {
      stage_v_165_2 = (pub_r000707_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_2 = (pub_r000707_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000707_10_1 & 2) != 0)
    {
      stage_v_166_1 = (pub_r000707_7_1 + 31) & 127;
    }
    else
    {
      stage_v_166_1 = (pub_r000707_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_1 = (pub_r000707_7_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000707_10_2 & 2) != 0)
    {
      stage_v_166_2 = (pub_r000707_7_2 + 31) & 127;
    }
    else
    {
      stage_v_166_2 = (pub_r000707_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_2 = (pub_r000707_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  if ((stage_v_159_1 & 1) != 0)
  {
    if ((sec_r000707_14_1 & 2) != 0)
    {
      stage_v_167_1 = (pub_r000707_0_1 + 31) & 127;
    }
    else
    {
      stage_v_167_1 = (pub_r000707_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_1 = (pub_r000707_0_1 + 7) & 127;
  }
  if ((stage_v_159_2 & 1) != 0)
  {
    if ((sec_r000707_14_2 & 2) != 0)
    {
      stage_v_167_2 = (pub_r000707_0_2 + 31) & 127;
    }
    else
    {
      stage_v_167_2 = (pub_r000707_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_2 = (pub_r000707_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((sec_r000707_12_1 & 2) != 0)
    {
      stage_v_168_1 = (pub_r000707_5_1 + 31) & 127;
    }
    else
    {
      stage_v_168_1 = (pub_r000707_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_168_1 = (pub_r000707_5_1 + 7) & 127;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((sec_r000707_12_2 & 2) != 0)
    {
      stage_v_168_2 = (pub_r000707_5_2 + 31) & 127;
    }
    else
    {
      stage_v_168_2 = (pub_r000707_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_168_2 = (pub_r000707_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = 0;
  int stage_v_169_2 = 0;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((sec_r000707_17_1 & 2) != 0)
    {
      stage_v_169_1 = (pub_r000707_0_1 + 31) & 127;
    }
    else
    {
      stage_v_169_1 = (pub_r000707_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_169_1 = (pub_r000707_0_1 + 7) & 127;
  }
  if ((stage_v_153_2 & 1) != 0)
  {
    if ((sec_r000707_17_2 & 2) != 0)
    {
      stage_v_169_2 = (pub_r000707_0_2 + 31) & 127;
    }
    else
    {
      stage_v_169_2 = (pub_r000707_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_169_2 = (pub_r000707_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = 0;
  int stage_v_170_2 = 0;
  if ((stage_v_147_1 & 1) != 0)
  {
    if ((sec_r000707_7_1 & 2) != 0)
    {
      stage_v_170_1 = (pub_r000707_0_1 + 31) & 127;
    }
    else
    {
      stage_v_170_1 = (pub_r000707_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_170_1 = (pub_r000707_0_1 + 7) & 127;
  }
  if ((stage_v_147_2 & 1) != 0)
  {
    if ((sec_r000707_7_2 & 2) != 0)
    {
      stage_v_170_2 = (pub_r000707_0_2 + 31) & 127;
    }
    else
    {
      stage_v_170_2 = (pub_r000707_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_170_2 = (pub_r000707_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  if ((sec_r000707_3_1 & 1) != 0)
  {
    if ((sec_r000707_12_1 & 2) != 0)
    {
      stage_v_171_1 = (pub_r000707_6_1 + 31) & 127;
    }
    else
    {
      stage_v_171_1 = (pub_r000707_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_171_1 = (pub_r000707_6_1 + 7) & 127;
  }
  if ((sec_r000707_3_2 & 1) != 0)
  {
    if ((sec_r000707_12_2 & 2) != 0)
    {
      stage_v_171_2 = (pub_r000707_6_2 + 31) & 127;
    }
    else
    {
      stage_v_171_2 = (pub_r000707_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_171_2 = (pub_r000707_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = 0;
  int stage_v_172_2 = 0;
  if ((stage_v_171_1 & 1) != 0)
  {
    if ((sec_r000707_6_1 & 2) != 0)
    {
      stage_v_172_1 = (pub_r000707_13_1 + 31) & 127;
    }
    else
    {
      stage_v_172_1 = (pub_r000707_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_172_1 = (pub_r000707_13_1 + 7) & 127;
  }
  if ((stage_v_171_2 & 1) != 0)
  {
    if ((sec_r000707_6_2 & 2) != 0)
    {
      stage_v_172_2 = (pub_r000707_13_2 + 31) & 127;
    }
    else
    {
      stage_v_172_2 = (pub_r000707_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_172_2 = (pub_r000707_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = 0;
  int stage_v_173_2 = 0;
  if ((sec_r000707_10_1 & 1) != 0)
  {
    if ((sec_r000707_12_1 & 2) != 0)
    {
      stage_v_173_1 = (pub_r000707_4_1 + 31) & 127;
    }
    else
    {
      stage_v_173_1 = (pub_r000707_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_173_1 = (pub_r000707_4_1 + 7) & 127;
  }
  if ((sec_r000707_10_2 & 1) != 0)
  {
    if ((sec_r000707_12_2 & 2) != 0)
    {
      stage_v_173_2 = (pub_r000707_4_2 + 31) & 127;
    }
    else
    {
      stage_v_173_2 = (pub_r000707_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_173_2 = (pub_r000707_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = 0;
  int stage_v_174_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000707_13_1 & 2) != 0)
    {
      stage_v_174_1 = (pub_r000707_12_1 + 31) & 127;
    }
    else
    {
      stage_v_174_1 = (pub_r000707_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_174_1 = (pub_r000707_12_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000707_13_2 & 2) != 0)
    {
      stage_v_174_2 = (pub_r000707_12_2 + 31) & 127;
    }
    else
    {
      stage_v_174_2 = (pub_r000707_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_174_2 = (pub_r000707_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = 0;
  int stage_v_175_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000707_9_1 & 2) != 0)
    {
      stage_v_175_1 = (pub_r000707_1_1 + 31) & 127;
    }
    else
    {
      stage_v_175_1 = (pub_r000707_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_175_1 = (pub_r000707_1_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000707_9_2 & 2) != 0)
    {
      stage_v_175_2 = (pub_r000707_1_2 + 31) & 127;
    }
    else
    {
      stage_v_175_2 = (pub_r000707_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_175_2 = (pub_r000707_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000707_13_1 != sec_r000707_13_2);
  __CPROVER_assume(pub_r000707_14_1 == pub_r000707_14_2);
  __CPROVER_assume(pub_r000707_17_1 == pub_r000707_17_2);
  __CPROVER_assume(pub_r000707_3_1 == pub_r000707_3_2);
  __CPROVER_assume(pub_r000707_2_1 == pub_r000707_2_2);
  __CPROVER_assume(sec_r000707_20_1 != sec_r000707_20_2);
  __CPROVER_assume(pub_r000707_13_1 == pub_r000707_13_2);
  __CPROVER_assume(sec_r000707_19_1 != sec_r000707_19_2);
  __CPROVER_assume(sec_r000707_2_1 != sec_r000707_2_2);
  __CPROVER_assume(pub_r000707_5_1 == pub_r000707_5_2);
  __CPROVER_assume(sec_r000707_8_1 != sec_r000707_8_2);
  __CPROVER_assume(sec_r000707_23_1 != sec_r000707_23_2);
  __CPROVER_assume(pub_r000707_10_1 == pub_r000707_10_2);
  __CPROVER_assume(pub_r000707_6_1 == pub_r000707_6_2);
  __CPROVER_assume(sec_r000707_18_1 != sec_r000707_18_2);
  __CPROVER_assume(sec_r000707_9_1 != sec_r000707_9_2);
  __CPROVER_assume(pub_r000707_15_1 == pub_r000707_15_2);
  __CPROVER_assume(sec_r000707_11_1 != sec_r000707_11_2);
  __CPROVER_assume(sec_r000707_14_1 != sec_r000707_14_2);
  __CPROVER_assume(pub_r000707_7_1 == pub_r000707_7_2);
  __CPROVER_assume(sec_r000707_5_1 != sec_r000707_5_2);
  __CPROVER_assume(pub_r000707_11_1 == pub_r000707_11_2);
  __CPROVER_assume(sec_r000707_3_1 != sec_r000707_3_2);
  __CPROVER_assume(sec_r000707_4_1 != sec_r000707_4_2);
  __CPROVER_assume(sec_r000707_10_1 != sec_r000707_10_2);
  __CPROVER_assume(sec_r000707_15_1 != sec_r000707_15_2);
  __CPROVER_assume(pub_r000707_9_1 == pub_r000707_9_2);
  __CPROVER_assume(sec_r000707_12_1 != sec_r000707_12_2);
  __CPROVER_assume(pub_r000707_0_1 == pub_r000707_0_2);
  __CPROVER_assume(pub_r000707_12_1 == pub_r000707_12_2);
  __CPROVER_assume(sec_r000707_17_1 != sec_r000707_17_2);
  __CPROVER_assume(pub_r000707_4_1 == pub_r000707_4_2);
  __CPROVER_assume(pub_r000707_8_1 == pub_r000707_8_2);
  __CPROVER_assume(sec_r000707_0_1 != sec_r000707_0_2);
  __CPROVER_assume(pub_r000707_16_1 == pub_r000707_16_2);
  __CPROVER_assume(sec_r000707_22_1 != sec_r000707_22_2);
  __CPROVER_assume(sec_r000707_7_1 != sec_r000707_7_2);
  __CPROVER_assume(sec_r000707_21_1 != sec_r000707_21_2);
  __CPROVER_assume(sec_r000707_16_1 != sec_r000707_16_2);
  __CPROVER_assume(sec_r000707_1_1 != sec_r000707_1_2);
  __CPROVER_assume(sec_r000707_6_1 != sec_r000707_6_2);
  __CPROVER_assume(pub_r000707_1_1 == pub_r000707_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.id == st_var_1_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.reading == st_var_2_2.reading);
  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.offset == st_var_2_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.coord_x == st_var_3_2.coord_x);
  assert(st_var_3_1.coord_y == st_var_3_2.coord_y);
  assert(st_var_3_1.heading == st_var_3_2.heading);
  assert(st_var_3_1.norm_sq == st_var_3_2.norm_sq);
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
}


