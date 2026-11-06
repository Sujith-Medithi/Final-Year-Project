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
struct StreamBuffer_R000787_8713_0
{
  unsigned char capacity;
  int watermark;
  short checksum;
  int state;
  unsigned char head;
  int buffer[3];
};
struct Vector3D_R000787_8713_1
{
  unsigned char coord_x;
  unsigned char heading;
  short coord_z;
  int pitch;
  int buffer[3];
};
struct DeviceConfig_R000787_8713_2
{
  int parity;
  int baud_rate;
  int timeout;
  int buffer[3];
};
union PacketPayload_R000787_8713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000787_8713_1
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
void fn_R000787_8713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000787_8713_1 st_1 = {0};
  struct Vector3D_R000787_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int quotient_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_56_1) & 63;
  aux_2 = (aux_2 + quotient_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_58_1 = local_arr_1[aux_1 % 3];
  int segment_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_58_2 * 2)) & 127;
  int tally_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_70_1)
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

  switch (tally_70_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_56_1 == quotient_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_58_1 == segment_58_2);
  assert(tally_70_1 == tally_70_2);
}

int fn_R000787_8713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000787_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int quotient_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_56) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int segment_58 = local_arr[aux % 3];
  acc = (acc + (segment_58 * 2)) & 127;
  int tally_70 = (aux + st.buffer[1]) & 3;
  switch (tally_70)
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

void fn_R000787_8713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st_1 = {0};
  struct StreamBuffer_R000787_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_70_1 > 42)
  {
    acc_1 = ((acc_1 + (quotient_70_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_70_2 > 42)
  {
    acc_2 = ((acc_2 + (quotient_70_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_54_1)
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

  switch (anchor_54_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_70_1 == quotient_70_2);
  assert(anchor_54_1 == anchor_54_2);
}

int fn_R000787_8713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_70 > 42)
  {
    acc = ((acc + (quotient_70 * 2)) + 5) & 127;
    aux ^= quotient_70 & 15;
  }
  else
  {
    acc = ((acc - quotient_70) + 11) & 127;
    aux += 3;
  }
  int anchor_54 = (aux + st.buffer[1]) & 3;
  switch (anchor_54)
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

void fn_R000787_8713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000787_8713_2 st_1 = {0};
  struct DeviceConfig_R000787_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_90_1 = local_arr_1[aux_1 % 3];
  int offset_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_90_2 * 2)) & 127;
  int threshold_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_79_1 > 25)
  {
    acc_1 = ((acc_1 + (threshold_79_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_79_2 > 25)
  {
    acc_2 = ((acc_2 + (threshold_79_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_79_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_90_1 == offset_90_2);
  assert(threshold_79_1 == threshold_79_2);
}

int fn_R000787_8713_2(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000787_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_90 = local_arr[aux % 3];
  acc = (acc + (offset_90 * 2)) & 127;
  int threshold_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_79 > 25)
  {
    acc = ((acc + (threshold_79 * 2)) + 5) & 127;
    aux ^= threshold_79 & 15;
  }
  else
  {
    acc = ((acc - threshold_79) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000787_8713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000787_8713_1 st_1 = {0};
  struct Vector3D_R000787_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int margin_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_11_1)
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

  switch (margin_11_2)
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

  int metric_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_86_1 > 20)
  {
    acc_1 = ((acc_1 + (metric_86_1 * 2)) + 5) & 127;
    aux_1 ^= metric_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_86_2 > 20)
  {
    acc_2 = ((acc_2 + (metric_86_2 * 2)) + 5) & 127;
    aux_2 ^= metric_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_86_2) + 11) & 127;
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

  assert(margin_11_1 == margin_11_2);
  assert(metric_86_1 == metric_86_2);
}

int fn_R000787_8713_3(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000787_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int margin_11 = (aux + st.buffer[1]) & 3;
  switch (margin_11)
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

  int metric_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_86 > 20)
  {
    acc = ((acc + (metric_86 * 2)) + 5) & 127;
    aux ^= metric_86 & 15;
  }
  else
  {
    acc = ((acc - metric_86) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000787_8713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000787_8713_2 st_1 = {0};
  struct DeviceConfig_R000787_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_98_1 = local_arr_1[aux_1 % 3];
  int margin_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_98_2 * 2)) & 127;
  int threshold_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_80_1)
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

  switch (threshold_80_2)
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
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_98_1 == margin_98_2);
  assert(threshold_80_1 == threshold_80_2);
}

int fn_R000787_8713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000787_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int margin_98 = local_arr[aux % 3];
  acc = (acc + (margin_98 * 2)) & 127;
  int threshold_80 = (aux + st.buffer[1]) & 3;
  switch (threshold_80)
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

void fn_R000787_8713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st_1 = {0};
  struct StreamBuffer_R000787_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int cursor_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_94_1) & 63;
  aux_2 = (aux_2 + cursor_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_80_1 > 26)
  {
    acc_1 = ((acc_1 + (segment_80_1 * 2)) + 5) & 127;
    aux_1 ^= segment_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_80_2 > 26)
  {
    acc_2 = ((acc_2 + (segment_80_2 * 2)) + 5) & 127;
    aux_2 ^= segment_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_68_1 = local_arr_1[aux_1 % 3];
  int quotient_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_94_1 == cursor_94_2);
  assert(segment_80_1 == segment_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_68_1 == quotient_68_2);
}

int fn_R000787_8713_5(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int cursor_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_94) & 63;
  acc ^= aux;
  int segment_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_80 > 26)
  {
    acc = ((acc + (segment_80 * 2)) + 5) & 127;
    aux ^= segment_80 & 15;
  }
  else
  {
    acc = ((acc - segment_80) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_68 = local_arr[aux % 3];
  acc = (acc + (quotient_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000787_8713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st_1 = {0};
  struct StreamBuffer_R000787_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quotient_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_62_1)
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

  switch (quotient_62_2)
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

  int phase_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_67_1) & 63;
  aux_2 = (aux_2 + phase_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_35_1 = local_arr_1[aux_1 % 3];
  int quotient_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_35_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_62_1 == quotient_62_2);
  assert(phase_67_1 == phase_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_35_1 == quotient_35_2);
}

int fn_R000787_8713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quotient_62 = (aux + st.buffer[1]) & 3;
  switch (quotient_62)
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

  int phase_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_67) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_35 = local_arr[aux % 3];
  acc = (acc + (quotient_35 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000787_8713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st_1 = {0};
  struct StreamBuffer_R000787_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_48_1) & 63;
  aux_2 = (aux_2 + tally_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_12_1)
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

  switch (stride_12_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_48_1 == tally_48_2);
  assert(stride_12_1 == stride_12_2);
}

int fn_R000787_8713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_48) & 63;
  acc ^= aux;
  int stride_12 = (aux + st.buffer[1]) & 3;
  switch (stride_12)
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

void fn_R000787_8713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st_1 = {0};
  struct StreamBuffer_R000787_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_53_1)
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

  switch (delta_53_2)
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

  int tally_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_69_1 > 42)
  {
    acc_1 = ((acc_1 + (tally_69_1 * 2)) + 5) & 127;
    aux_1 ^= tally_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_69_2 > 42)
  {
    acc_2 = ((acc_2 + (tally_69_2 * 2)) + 5) & 127;
    aux_2 ^= tally_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_69_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_53_1 == delta_53_2);
  assert(tally_69_1 == tally_69_2);
}

int fn_R000787_8713_8(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_53 = (aux + st.buffer[1]) & 3;
  switch (delta_53)
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

  int tally_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_69 > 42)
  {
    acc = ((acc + (tally_69 * 2)) + 5) & 127;
    aux ^= tally_69 & 15;
  }
  else
  {
    acc = ((acc - tally_69) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000787_8713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000787_8713_1 st_1 = {0};
  struct Vector3D_R000787_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_65_1) & 63;
  aux_2 = (aux_2 + parity_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
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

  assert(parity_65_1 == parity_65_2);
}

int fn_R000787_8713_9(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000787_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_65) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000787_8713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000787_8713_2 st_1 = {0};
  struct DeviceConfig_R000787_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int bound_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_48_1)
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

  switch (bound_48_2)
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

  int bound_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_30_1) & 63;
  aux_2 = (aux_2 + bound_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_82_1 = local_arr_1[aux_1 % 3];
  int weight_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_82_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_48_1 == bound_48_2);
  assert(bound_30_1 == bound_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_82_1 == weight_82_2);
}

int fn_R000787_8713_10(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000787_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int bound_48 = (aux + st.buffer[1]) & 3;
  switch (bound_48)
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

  int bound_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_30) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_82 = local_arr[aux % 3];
  acc = (acc + (weight_82 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000787_8713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000787_8713_2 st_1 = {0};
  struct DeviceConfig_R000787_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int offset_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_83_1) & 63;
  aux_2 = (aux_2 + offset_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_99_1 > 34)
  {
    acc_1 = ((acc_1 + (metric_99_1 * 2)) + 5) & 127;
    aux_1 ^= metric_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_99_2 > 34)
  {
    acc_2 = ((acc_2 + (metric_99_2 * 2)) + 5) & 127;
    aux_2 ^= metric_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_83_1 == offset_83_2);
  assert(metric_99_1 == metric_99_2);
}

int fn_R000787_8713_11(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000787_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int offset_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_83) & 63;
  acc ^= aux;
  int metric_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_99 > 34)
  {
    acc = ((acc + (metric_99 * 2)) + 5) & 127;
    aux ^= metric_99 & 15;
  }
  else
  {
    acc = ((acc - metric_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000787_8713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000787_8713_1 st_1 = {0};
  struct Vector3D_R000787_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_25_1)
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

  switch (parity_25_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_14_1 = local_arr_1[aux_1 % 3];
  int anchor_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_14_2 * 2)) & 127;
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

  assert(parity_25_1 == parity_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_14_1 == anchor_14_2);
}

int fn_R000787_8713_12(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000787_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_25 = (aux + st.buffer[1]) & 3;
  switch (parity_25)
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

  int local_arr[3] = {4, 9, 15};
  int anchor_14 = local_arr[aux % 3];
  acc = (acc + (anchor_14 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000787_8713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st_1 = {0};
  struct StreamBuffer_R000787_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int pivot_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_63_1 > 38)
  {
    acc_1 = ((acc_1 + (pivot_63_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_63_2 > 38)
  {
    acc_2 = ((acc_2 + (pivot_63_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_81_1) & 63;
  aux_2 = (aux_2 + factor_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_57_1 = local_arr_1[aux_1 % 3];
  int factor_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_57_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_63_1 == pivot_63_2);
  assert(factor_81_1 == factor_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_57_1 == factor_57_2);
}

int fn_R000787_8713_13(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int pivot_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_63 > 38)
  {
    acc = ((acc + (pivot_63 * 2)) + 5) & 127;
    aux ^= pivot_63 & 15;
  }
  else
  {
    acc = ((acc - pivot_63) + 11) & 127;
    aux += 3;
  }
  int factor_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_81) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int factor_57 = local_arr[aux % 3];
  acc = (acc + (factor_57 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000787_8713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000787_8713_1 st_1 = {0};
  struct Vector3D_R000787_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_95_1 > 33)
  {
    acc_1 = ((acc_1 + (sample_95_1 * 2)) + 5) & 127;
    aux_1 ^= sample_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_95_2 > 33)
  {
    acc_2 = ((acc_2 + (sample_95_2 * 2)) + 5) & 127;
    aux_2 ^= sample_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_95_2) + 11) & 127;
    aux_2 += 3;
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

  assert(sample_95_1 == sample_95_2);
}

int fn_R000787_8713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000787_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_95 > 33)
  {
    acc = ((acc + (sample_95 * 2)) + 5) & 127;
    aux ^= sample_95 & 15;
  }
  else
  {
    acc = ((acc - sample_95) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000787_8713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st_1 = {0};
  struct StreamBuffer_R000787_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_16_1 > 44)
  {
    acc_1 = ((acc_1 + (residue_16_1 * 2)) + 5) & 127;
    aux_1 ^= residue_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_16_2 > 44)
  {
    acc_2 = ((acc_2 + (residue_16_2 * 2)) + 5) & 127;
    aux_2 ^= residue_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_16_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_16_1 == residue_16_2);
}

int fn_R000787_8713_15(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_16 > 44)
  {
    acc = ((acc + (residue_16 * 2)) + 5) & 127;
    aux ^= residue_16 & 15;
  }
  else
  {
    acc = ((acc - residue_16) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000787_8713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st_1 = {0};
  struct StreamBuffer_R000787_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int damping_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_83_1) & 63;
  aux_2 = (aux_2 + damping_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_19_1 > 23)
  {
    acc_1 = ((acc_1 + (tracker_19_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_19_2 > 23)
  {
    acc_2 = ((acc_2 + (tracker_19_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_19_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_83_1 == damping_83_2);
  assert(tracker_19_1 == tracker_19_2);
}

int fn_R000787_8713_16(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int damping_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_83) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_19 > 23)
  {
    acc = ((acc + (tracker_19 * 2)) + 5) & 127;
    aux ^= tracker_19 & 15;
  }
  else
  {
    acc = ((acc - tracker_19) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000787_8713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000787_8713_2 st_1 = {0};
  struct DeviceConfig_R000787_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int coefficient_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_89_1) & 63;
  aux_2 = (aux_2 + coefficient_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_64_1 > 44)
  {
    acc_1 = ((acc_1 + (quantum_64_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_64_2 > 44)
  {
    acc_2 = ((acc_2 + (quantum_64_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_89_1 == coefficient_89_2);
  assert(quantum_64_1 == quantum_64_2);
}

int fn_R000787_8713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000787_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int coefficient_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_89) & 63;
  acc ^= aux;
  int quantum_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_64 > 44)
  {
    acc = ((acc + (quantum_64 * 2)) + 5) & 127;
    aux ^= quantum_64 & 15;
  }
  else
  {
    acc = ((acc - quantum_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000787_8713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st_1 = {0};
  struct StreamBuffer_R000787_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int pivot_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_29_1)
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

  switch (pivot_29_2)
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

  int vector_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_14_1) & 63;
  aux_2 = (aux_2 + vector_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_29_1 == pivot_29_2);
  assert(vector_14_1 == vector_14_2);
}

int fn_R000787_8713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000787_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int pivot_29 = (aux + st.buffer[1]) & 3;
  switch (pivot_29)
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

  int vector_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_14) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000787_0_1;
  int sec_r000787_0_2;
  int sec_r000787_1_1;
  int sec_r000787_1_2;
  int sec_r000787_2_1;
  int sec_r000787_2_2;
  int sec_r000787_3_1;
  int sec_r000787_3_2;
  int sec_r000787_4_1;
  int sec_r000787_4_2;
  int sec_r000787_5_1;
  int sec_r000787_5_2;
  int sec_r000787_6_1;
  int sec_r000787_6_2;
  int sec_r000787_7_1;
  int sec_r000787_7_2;
  int sec_r000787_8_1;
  int sec_r000787_8_2;
  int sec_r000787_9_1;
  int sec_r000787_9_2;
  int sec_r000787_10_1;
  int sec_r000787_10_2;
  int sec_r000787_11_1;
  int sec_r000787_11_2;
  int sec_r000787_12_1;
  int sec_r000787_12_2;
  int sec_r000787_13_1;
  int sec_r000787_13_2;
  int sec_r000787_14_1;
  int sec_r000787_14_2;
  int sec_r000787_15_1;
  int sec_r000787_15_2;
  int sec_r000787_16_1;
  int sec_r000787_16_2;
  int sec_r000787_17_1;
  int sec_r000787_17_2;
  int sec_r000787_18_1;
  int sec_r000787_18_2;
  int sec_r000787_19_1;
  int sec_r000787_19_2;
  int sec_r000787_20_1;
  int sec_r000787_20_2;
  int sec_r000787_21_1;
  int sec_r000787_21_2;
  int sec_r000787_22_1;
  int sec_r000787_22_2;
  int pub_r000787_0_1;
  int pub_r000787_0_2;
  int pub_r000787_1_1;
  int pub_r000787_1_2;
  int pub_r000787_2_1;
  int pub_r000787_2_2;
  int pub_r000787_3_1;
  int pub_r000787_3_2;
  int pub_r000787_4_1;
  int pub_r000787_4_2;
  int pub_r000787_5_1;
  int pub_r000787_5_2;
  int pub_r000787_6_1;
  int pub_r000787_6_2;
  int pub_r000787_7_1;
  int pub_r000787_7_2;
  int pub_r000787_8_1;
  int pub_r000787_8_2;
  int pub_r000787_9_1;
  int pub_r000787_9_2;
  int pub_r000787_10_1;
  int pub_r000787_10_2;
  int pub_r000787_11_1;
  int pub_r000787_11_2;
  int pub_r000787_12_1;
  int pub_r000787_12_2;
  int pub_r000787_13_1;
  int pub_r000787_13_2;
  int pub_r000787_14_1;
  int pub_r000787_14_2;
  int pub_r000787_15_1;
  int pub_r000787_15_2;
  int pub_r000787_16_1;
  int pub_r000787_16_2;
  int pub_r000787_17_1;
  int pub_r000787_17_2;
  int pub_r000787_18_1;
  int pub_r000787_18_2;
  int pub_r000787_19_1;
  int pub_r000787_19_2;
  int pub_r000787_20_1;
  int pub_r000787_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000787_0_1 >= (-100)) && (pub_r000787_0_1 <= 100));
  __CPROVER_assume((pub_r000787_0_2 >= (-100)) && (pub_r000787_0_2 <= 100));
  __CPROVER_assume((pub_r000787_1_1 >= (-100)) && (pub_r000787_1_1 <= 100));
  __CPROVER_assume((pub_r000787_1_2 >= (-100)) && (pub_r000787_1_2 <= 100));
  __CPROVER_assume((pub_r000787_2_1 >= (-100)) && (pub_r000787_2_1 <= 100));
  __CPROVER_assume((pub_r000787_2_2 >= (-100)) && (pub_r000787_2_2 <= 100));
  __CPROVER_assume((pub_r000787_3_1 >= (-100)) && (pub_r000787_3_1 <= 100));
  __CPROVER_assume((pub_r000787_3_2 >= (-100)) && (pub_r000787_3_2 <= 100));
  __CPROVER_assume((pub_r000787_4_1 >= (-100)) && (pub_r000787_4_1 <= 100));
  __CPROVER_assume((pub_r000787_4_2 >= (-100)) && (pub_r000787_4_2 <= 100));
  __CPROVER_assume((pub_r000787_5_1 >= (-100)) && (pub_r000787_5_1 <= 100));
  __CPROVER_assume((pub_r000787_5_2 >= (-100)) && (pub_r000787_5_2 <= 100));
  __CPROVER_assume((pub_r000787_6_1 >= (-100)) && (pub_r000787_6_1 <= 100));
  __CPROVER_assume((pub_r000787_6_2 >= (-100)) && (pub_r000787_6_2 <= 100));
  __CPROVER_assume((pub_r000787_7_1 >= (-100)) && (pub_r000787_7_1 <= 100));
  __CPROVER_assume((pub_r000787_7_2 >= (-100)) && (pub_r000787_7_2 <= 100));
  __CPROVER_assume((pub_r000787_8_1 >= (-100)) && (pub_r000787_8_1 <= 100));
  __CPROVER_assume((pub_r000787_8_2 >= (-100)) && (pub_r000787_8_2 <= 100));
  __CPROVER_assume((pub_r000787_9_1 >= (-100)) && (pub_r000787_9_1 <= 100));
  __CPROVER_assume((pub_r000787_9_2 >= (-100)) && (pub_r000787_9_2 <= 100));
  __CPROVER_assume((pub_r000787_10_1 >= (-100)) && (pub_r000787_10_1 <= 100));
  __CPROVER_assume((pub_r000787_10_2 >= (-100)) && (pub_r000787_10_2 <= 100));
  __CPROVER_assume((pub_r000787_11_1 >= (-100)) && (pub_r000787_11_1 <= 100));
  __CPROVER_assume((pub_r000787_11_2 >= (-100)) && (pub_r000787_11_2 <= 100));
  __CPROVER_assume((pub_r000787_12_1 >= (-100)) && (pub_r000787_12_1 <= 100));
  __CPROVER_assume((pub_r000787_12_2 >= (-100)) && (pub_r000787_12_2 <= 100));
  __CPROVER_assume((pub_r000787_13_1 >= (-100)) && (pub_r000787_13_1 <= 100));
  __CPROVER_assume((pub_r000787_13_2 >= (-100)) && (pub_r000787_13_2 <= 100));
  __CPROVER_assume((pub_r000787_14_1 >= (-100)) && (pub_r000787_14_1 <= 100));
  __CPROVER_assume((pub_r000787_14_2 >= (-100)) && (pub_r000787_14_2 <= 100));
  __CPROVER_assume((pub_r000787_15_1 >= (-100)) && (pub_r000787_15_1 <= 100));
  __CPROVER_assume((pub_r000787_15_2 >= (-100)) && (pub_r000787_15_2 <= 100));
  __CPROVER_assume((pub_r000787_16_1 >= (-100)) && (pub_r000787_16_1 <= 100));
  __CPROVER_assume((pub_r000787_16_2 >= (-100)) && (pub_r000787_16_2 <= 100));
  __CPROVER_assume((pub_r000787_17_1 >= (-100)) && (pub_r000787_17_1 <= 100));
  __CPROVER_assume((pub_r000787_17_2 >= (-100)) && (pub_r000787_17_2 <= 100));
  __CPROVER_assume((pub_r000787_18_1 >= (-100)) && (pub_r000787_18_1 <= 100));
  __CPROVER_assume((pub_r000787_18_2 >= (-100)) && (pub_r000787_18_2 <= 100));
  __CPROVER_assume((pub_r000787_19_1 >= (-100)) && (pub_r000787_19_1 <= 100));
  __CPROVER_assume((pub_r000787_19_2 >= (-100)) && (pub_r000787_19_2 <= 100));
  __CPROVER_assume((pub_r000787_20_1 >= (-100)) && (pub_r000787_20_1 <= 100));
  __CPROVER_assume((pub_r000787_20_2 >= (-100)) && (pub_r000787_20_2 <= 100));
  __CPROVER_assume((sec_r000787_0_1 >= 0) && (sec_r000787_0_1 <= 255));
  __CPROVER_assume((sec_r000787_0_2 >= 0) && (sec_r000787_0_2 <= 255));
  __CPROVER_assume((sec_r000787_1_1 >= 0) && (sec_r000787_1_1 <= 255));
  __CPROVER_assume((sec_r000787_1_2 >= 0) && (sec_r000787_1_2 <= 255));
  __CPROVER_assume((sec_r000787_2_1 >= 0) && (sec_r000787_2_1 <= 255));
  __CPROVER_assume((sec_r000787_2_2 >= 0) && (sec_r000787_2_2 <= 255));
  __CPROVER_assume((sec_r000787_3_1 >= 0) && (sec_r000787_3_1 <= 255));
  __CPROVER_assume((sec_r000787_3_2 >= 0) && (sec_r000787_3_2 <= 255));
  __CPROVER_assume((sec_r000787_4_1 >= 0) && (sec_r000787_4_1 <= 255));
  __CPROVER_assume((sec_r000787_4_2 >= 0) && (sec_r000787_4_2 <= 255));
  __CPROVER_assume((sec_r000787_5_1 >= 0) && (sec_r000787_5_1 <= 255));
  __CPROVER_assume((sec_r000787_5_2 >= 0) && (sec_r000787_5_2 <= 255));
  __CPROVER_assume((sec_r000787_6_1 >= 0) && (sec_r000787_6_1 <= 255));
  __CPROVER_assume((sec_r000787_6_2 >= 0) && (sec_r000787_6_2 <= 255));
  __CPROVER_assume((sec_r000787_7_1 >= 0) && (sec_r000787_7_1 <= 255));
  __CPROVER_assume((sec_r000787_7_2 >= 0) && (sec_r000787_7_2 <= 255));
  __CPROVER_assume((sec_r000787_8_1 >= 0) && (sec_r000787_8_1 <= 255));
  __CPROVER_assume((sec_r000787_8_2 >= 0) && (sec_r000787_8_2 <= 255));
  __CPROVER_assume((sec_r000787_9_1 >= 0) && (sec_r000787_9_1 <= 255));
  __CPROVER_assume((sec_r000787_9_2 >= 0) && (sec_r000787_9_2 <= 255));
  __CPROVER_assume((sec_r000787_10_1 >= 0) && (sec_r000787_10_1 <= 255));
  __CPROVER_assume((sec_r000787_10_2 >= 0) && (sec_r000787_10_2 <= 255));
  __CPROVER_assume((sec_r000787_11_1 >= 0) && (sec_r000787_11_1 <= 255));
  __CPROVER_assume((sec_r000787_11_2 >= 0) && (sec_r000787_11_2 <= 255));
  __CPROVER_assume((sec_r000787_12_1 >= 0) && (sec_r000787_12_1 <= 255));
  __CPROVER_assume((sec_r000787_12_2 >= 0) && (sec_r000787_12_2 <= 255));
  __CPROVER_assume((sec_r000787_13_1 >= 0) && (sec_r000787_13_1 <= 255));
  __CPROVER_assume((sec_r000787_13_2 >= 0) && (sec_r000787_13_2 <= 255));
  __CPROVER_assume((sec_r000787_14_1 >= 0) && (sec_r000787_14_1 <= 255));
  __CPROVER_assume((sec_r000787_14_2 >= 0) && (sec_r000787_14_2 <= 255));
  __CPROVER_assume((sec_r000787_15_1 >= 0) && (sec_r000787_15_1 <= 255));
  __CPROVER_assume((sec_r000787_15_2 >= 0) && (sec_r000787_15_2 <= 255));
  __CPROVER_assume((sec_r000787_16_1 >= 0) && (sec_r000787_16_1 <= 255));
  __CPROVER_assume((sec_r000787_16_2 >= 0) && (sec_r000787_16_2 <= 255));
  __CPROVER_assume((sec_r000787_17_1 >= 0) && (sec_r000787_17_1 <= 255));
  __CPROVER_assume((sec_r000787_17_2 >= 0) && (sec_r000787_17_2 <= 255));
  __CPROVER_assume((sec_r000787_18_1 >= 0) && (sec_r000787_18_1 <= 255));
  __CPROVER_assume((sec_r000787_18_2 >= 0) && (sec_r000787_18_2 <= 255));
  __CPROVER_assume((sec_r000787_19_1 >= 0) && (sec_r000787_19_1 <= 255));
  __CPROVER_assume((sec_r000787_19_2 >= 0) && (sec_r000787_19_2 <= 255));
  __CPROVER_assume((sec_r000787_20_1 >= 0) && (sec_r000787_20_1 <= 255));
  __CPROVER_assume((sec_r000787_20_2 >= 0) && (sec_r000787_20_2 <= 255));
  __CPROVER_assume((sec_r000787_21_1 >= 0) && (sec_r000787_21_1 <= 255));
  __CPROVER_assume((sec_r000787_21_2 >= 0) && (sec_r000787_21_2 <= 255));
  __CPROVER_assume((sec_r000787_22_1 >= 0) && (sec_r000787_22_1 <= 255));
  __CPROVER_assume((sec_r000787_22_2 >= 0) && (sec_r000787_22_2 <= 255));
  struct StreamBuffer_R000787_8713_0 st_var_0_1 = {0};
  struct StreamBuffer_R000787_8713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000787_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000787_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000787_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000787_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000787_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000787_0_2 + 7) & 15;
  struct Vector3D_R000787_8713_1 st_var_1_1 = {0};
  struct Vector3D_R000787_8713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000787_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000787_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000787_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000787_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000787_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000787_0_2 + 9) & 15;
  struct DeviceConfig_R000787_8713_2 st_var_2_1 = {0};
  struct DeviceConfig_R000787_8713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000787_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000787_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000787_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000787_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000787_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000787_0_2 + 11) & 15;
  union PacketPayload_R000787_8713_0 u_var_1;
  union PacketPayload_R000787_8713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = table_1[0];
  int stage_v_0_2 = table_2[0];
  table_1[0] = (table_1[1] + 1) & 63;
  table_2[0] = (table_2[1] + 1) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_4_1 = ((stage_v_4_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_4_2 = ((stage_v_4_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = ((st_var_2_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_2_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 26)
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
  if (stage_v_5_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 26)
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
  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 10) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = ((st_var_1_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_1_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 45)
    {
      chk_sum_1 ^= stage_v_10_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_10_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 45)
    {
      chk_sum_2 ^= stage_v_10_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  if ((sec_r000787_3_1 & 1) != 0)
  {
    if ((sec_r000787_6_1 & 2) != 0)
    {
      stage_v_14_1 = (pub_r000787_4_1 + 31) & 127;
    }
    else
    {
      stage_v_14_1 = (pub_r000787_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_14_1 = (pub_r000787_4_1 + 7) & 127;
  }
  if ((sec_r000787_3_2 & 1) != 0)
  {
    if ((sec_r000787_6_2 & 2) != 0)
    {
      stage_v_14_2 = (pub_r000787_4_2 + 31) & 127;
    }
    else
    {
      stage_v_14_2 = (pub_r000787_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_14_2 = (pub_r000787_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  if ((sec_r000787_15_1 & 1) != 0)
  {
    if ((sec_r000787_18_1 & 2) != 0)
    {
      stage_v_15_1 = (pub_r000787_20_1 + 31) & 127;
    }
    else
    {
      stage_v_15_1 = (pub_r000787_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_15_1 = (pub_r000787_20_1 + 7) & 127;
  }
  if ((sec_r000787_15_2 & 1) != 0)
  {
    if ((sec_r000787_18_2 & 2) != 0)
    {
      stage_v_15_2 = (pub_r000787_20_2 + 31) & 127;
    }
    else
    {
      stage_v_15_2 = (pub_r000787_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_15_2 = (pub_r000787_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000787_7_1 & 2) != 0)
    {
      stage_v_16_1 = (pub_r000787_2_1 + 31) & 127;
    }
    else
    {
      stage_v_16_1 = (pub_r000787_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_16_1 = (pub_r000787_2_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000787_7_2 & 2) != 0)
    {
      stage_v_16_2 = (pub_r000787_2_2 + 31) & 127;
    }
    else
    {
      stage_v_16_2 = (pub_r000787_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_16_2 = (pub_r000787_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r000787_17_1 & 2) != 0)
    {
      stage_v_17_1 = (pub_r000787_14_1 + 31) & 127;
    }
    else
    {
      stage_v_17_1 = (pub_r000787_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_17_1 = (pub_r000787_14_1 + 7) & 127;
  }
  if ((stage_v_14_2 & 1) != 0)
  {
    if ((sec_r000787_17_2 & 2) != 0)
    {
      stage_v_17_2 = (pub_r000787_14_2 + 31) & 127;
    }
    else
    {
      stage_v_17_2 = (pub_r000787_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_17_2 = (pub_r000787_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r000787_7_1 & 2) != 0)
    {
      stage_v_18_1 = (pub_r000787_0_1 + 31) & 127;
    }
    else
    {
      stage_v_18_1 = (pub_r000787_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_18_1 = (pub_r000787_0_1 + 7) & 127;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((sec_r000787_7_2 & 2) != 0)
    {
      stage_v_18_2 = (pub_r000787_0_2 + 31) & 127;
    }
    else
    {
      stage_v_18_2 = (pub_r000787_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_18_2 = (pub_r000787_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r000787_17_1 & 2) != 0)
    {
      stage_v_19_1 = (pub_r000787_11_1 + 31) & 127;
    }
    else
    {
      stage_v_19_1 = (pub_r000787_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_19_1 = (pub_r000787_11_1 + 7) & 127;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((sec_r000787_17_2 & 2) != 0)
    {
      stage_v_19_2 = (pub_r000787_11_2 + 31) & 127;
    }
    else
    {
      stage_v_19_2 = (pub_r000787_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_19_2 = (pub_r000787_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000787_13_1 & 2) != 0)
    {
      stage_v_20_1 = (pub_r000787_3_1 + 31) & 127;
    }
    else
    {
      stage_v_20_1 = (pub_r000787_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_20_1 = (pub_r000787_3_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000787_13_2 & 2) != 0)
    {
      stage_v_20_2 = (pub_r000787_3_2 + 31) & 127;
    }
    else
    {
      stage_v_20_2 = (pub_r000787_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_20_2 = (pub_r000787_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000787_2_1 & 2) != 0)
    {
      stage_v_21_1 = (pub_r000787_17_1 + 31) & 127;
    }
    else
    {
      stage_v_21_1 = (pub_r000787_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_21_1 = (pub_r000787_17_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000787_2_2 & 2) != 0)
    {
      stage_v_21_2 = (pub_r000787_17_2 + 31) & 127;
    }
    else
    {
      stage_v_21_2 = (pub_r000787_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_21_2 = (pub_r000787_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  if ((sec_r000787_1_1 & 1) != 0)
  {
    if ((sec_r000787_1_1 & 2) != 0)
    {
      stage_v_22_1 = (pub_r000787_0_1 + 31) & 127;
    }
    else
    {
      stage_v_22_1 = (pub_r000787_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_1 = (pub_r000787_0_1 + 7) & 127;
  }
  if ((sec_r000787_1_2 & 1) != 0)
  {
    if ((sec_r000787_1_2 & 2) != 0)
    {
      stage_v_22_2 = (pub_r000787_0_2 + 31) & 127;
    }
    else
    {
      stage_v_22_2 = (pub_r000787_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_2 = (pub_r000787_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r000787_12_1 & 2) != 0)
    {
      stage_v_23_1 = (pub_r000787_5_1 + 31) & 127;
    }
    else
    {
      stage_v_23_1 = (pub_r000787_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_1 = (pub_r000787_5_1 + 7) & 127;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r000787_12_2 & 2) != 0)
    {
      stage_v_23_2 = (pub_r000787_5_2 + 31) & 127;
    }
    else
    {
      stage_v_23_2 = (pub_r000787_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_2 = (pub_r000787_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000787_1_1 & 2) != 0)
    {
      stage_v_24_1 = (pub_r000787_16_1 + 31) & 127;
    }
    else
    {
      stage_v_24_1 = (pub_r000787_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_1 = (pub_r000787_16_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000787_1_2 & 2) != 0)
    {
      stage_v_24_2 = (pub_r000787_16_2 + 31) & 127;
    }
    else
    {
      stage_v_24_2 = (pub_r000787_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_2 = (pub_r000787_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000787_20_1 & 2) != 0)
    {
      stage_v_25_1 = (pub_r000787_8_1 + 31) & 127;
    }
    else
    {
      stage_v_25_1 = (pub_r000787_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_1 = (pub_r000787_8_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000787_20_2 & 2) != 0)
    {
      stage_v_25_2 = (pub_r000787_8_2 + 31) & 127;
    }
    else
    {
      stage_v_25_2 = (pub_r000787_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_2 = (pub_r000787_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000787_11_1 & 2) != 0)
    {
      stage_v_26_1 = (pub_r000787_13_1 + 31) & 127;
    }
    else
    {
      stage_v_26_1 = (pub_r000787_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_1 = (pub_r000787_13_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000787_11_2 & 2) != 0)
    {
      stage_v_26_2 = (pub_r000787_13_2 + 31) & 127;
    }
    else
    {
      stage_v_26_2 = (pub_r000787_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_2 = (pub_r000787_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((sec_r000787_22_1 & 1) != 0)
  {
    if ((sec_r000787_21_1 & 2) != 0)
    {
      stage_v_27_1 = (pub_r000787_2_1 + 31) & 127;
    }
    else
    {
      stage_v_27_1 = (pub_r000787_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_1 = (pub_r000787_2_1 + 7) & 127;
  }
  if ((sec_r000787_22_2 & 1) != 0)
  {
    if ((sec_r000787_21_2 & 2) != 0)
    {
      stage_v_27_2 = (pub_r000787_2_2 + 31) & 127;
    }
    else
    {
      stage_v_27_2 = (pub_r000787_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_2 = (pub_r000787_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((sec_r000787_0_1 & 1) != 0)
  {
    if ((sec_r000787_22_1 & 2) != 0)
    {
      stage_v_28_1 = (pub_r000787_17_1 + 31) & 127;
    }
    else
    {
      stage_v_28_1 = (pub_r000787_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_1 = (pub_r000787_17_1 + 7) & 127;
  }
  if ((sec_r000787_0_2 & 1) != 0)
  {
    if ((sec_r000787_22_2 & 2) != 0)
    {
      stage_v_28_2 = (pub_r000787_17_2 + 31) & 127;
    }
    else
    {
      stage_v_28_2 = (pub_r000787_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_2 = (pub_r000787_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000787_7_1 & 2) != 0)
    {
      stage_v_29_1 = (pub_r000787_17_1 + 31) & 127;
    }
    else
    {
      stage_v_29_1 = (pub_r000787_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_1 = (pub_r000787_17_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000787_7_2 & 2) != 0)
    {
      stage_v_29_2 = (pub_r000787_17_2 + 31) & 127;
    }
    else
    {
      stage_v_29_2 = (pub_r000787_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_2 = (pub_r000787_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((sec_r000787_8_1 & 1) != 0)
  {
    if ((sec_r000787_14_1 & 2) != 0)
    {
      stage_v_30_1 = (pub_r000787_17_1 + 31) & 127;
    }
    else
    {
      stage_v_30_1 = (pub_r000787_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_1 = (pub_r000787_17_1 + 7) & 127;
  }
  if ((sec_r000787_8_2 & 1) != 0)
  {
    if ((sec_r000787_14_2 & 2) != 0)
    {
      stage_v_30_2 = (pub_r000787_17_2 + 31) & 127;
    }
    else
    {
      stage_v_30_2 = (pub_r000787_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_2 = (pub_r000787_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((sec_r000787_12_1 & 1) != 0)
  {
    if ((sec_r000787_17_1 & 2) != 0)
    {
      stage_v_31_1 = (pub_r000787_19_1 + 31) & 127;
    }
    else
    {
      stage_v_31_1 = (pub_r000787_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_1 = (pub_r000787_19_1 + 7) & 127;
  }
  if ((sec_r000787_12_2 & 1) != 0)
  {
    if ((sec_r000787_17_2 & 2) != 0)
    {
      stage_v_31_2 = (pub_r000787_19_2 + 31) & 127;
    }
    else
    {
      stage_v_31_2 = (pub_r000787_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_2 = (pub_r000787_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r000787_21_1 & 2) != 0)
    {
      stage_v_32_1 = (pub_r000787_19_1 + 31) & 127;
    }
    else
    {
      stage_v_32_1 = (pub_r000787_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_1 = (pub_r000787_19_1 + 7) & 127;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r000787_21_2 & 2) != 0)
    {
      stage_v_32_2 = (pub_r000787_19_2 + 31) & 127;
    }
    else
    {
      stage_v_32_2 = (pub_r000787_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_2 = (pub_r000787_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((sec_r000787_4_1 & 1) != 0)
  {
    if ((sec_r000787_9_1 & 2) != 0)
    {
      stage_v_33_1 = (pub_r000787_20_1 + 31) & 127;
    }
    else
    {
      stage_v_33_1 = (pub_r000787_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_1 = (pub_r000787_20_1 + 7) & 127;
  }
  if ((sec_r000787_4_2 & 1) != 0)
  {
    if ((sec_r000787_9_2 & 2) != 0)
    {
      stage_v_33_2 = (pub_r000787_20_2 + 31) & 127;
    }
    else
    {
      stage_v_33_2 = (pub_r000787_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_2 = (pub_r000787_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000787_16_1 & 2) != 0)
    {
      stage_v_34_1 = (pub_r000787_13_1 + 31) & 127;
    }
    else
    {
      stage_v_34_1 = (pub_r000787_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_1 = (pub_r000787_13_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000787_16_2 & 2) != 0)
    {
      stage_v_34_2 = (pub_r000787_13_2 + 31) & 127;
    }
    else
    {
      stage_v_34_2 = (pub_r000787_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_2 = (pub_r000787_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((sec_r000787_19_1 & 1) != 0)
  {
    if ((sec_r000787_6_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000787_2_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000787_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000787_2_1 + 7) & 127;
  }
  if ((sec_r000787_19_2 & 1) != 0)
  {
    if ((sec_r000787_6_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000787_2_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000787_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000787_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000787_4_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000787_9_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000787_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000787_9_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000787_4_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000787_9_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000787_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000787_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((sec_r000787_0_1 & 1) != 0)
  {
    if ((sec_r000787_2_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000787_20_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000787_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000787_20_1 + 7) & 127;
  }
  if ((sec_r000787_0_2 & 1) != 0)
  {
    if ((sec_r000787_2_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000787_20_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000787_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000787_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((sec_r000787_1_1 & 1) != 0)
  {
    if ((sec_r000787_0_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000787_14_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000787_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000787_14_1 + 7) & 127;
  }
  if ((sec_r000787_1_2 & 1) != 0)
  {
    if ((sec_r000787_0_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000787_14_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000787_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000787_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r000787_8_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000787_7_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000787_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000787_7_1 + 7) & 127;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r000787_8_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000787_7_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000787_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000787_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000787_4_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000787_8_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000787_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000787_8_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000787_4_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000787_8_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000787_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000787_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000787_5_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000787_5_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000787_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000787_5_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000787_5_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000787_5_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000787_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000787_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000787_1_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000787_3_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000787_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000787_3_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000787_1_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000787_3_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000787_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000787_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((sec_r000787_3_1 & 1) != 0)
  {
    if ((sec_r000787_6_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000787_10_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000787_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000787_10_1 + 7) & 127;
  }
  if ((sec_r000787_3_2 & 1) != 0)
  {
    if ((sec_r000787_6_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000787_10_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000787_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000787_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000787_3_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000787_18_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000787_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000787_18_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000787_3_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000787_18_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000787_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000787_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000787_22_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000787_19_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000787_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000787_19_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000787_22_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000787_19_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000787_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000787_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((sec_r000787_9_1 & 1) != 0)
  {
    if ((sec_r000787_22_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000787_4_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000787_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000787_4_1 + 7) & 127;
  }
  if ((sec_r000787_9_2 & 1) != 0)
  {
    if ((sec_r000787_22_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000787_4_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000787_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000787_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000787_19_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000787_6_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000787_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000787_6_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000787_19_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000787_6_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000787_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000787_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000787_20_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000787_5_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000787_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000787_5_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000787_20_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000787_5_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000787_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000787_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000787_22_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000787_6_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000787_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000787_6_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000787_22_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000787_6_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000787_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000787_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r000787_12_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000787_20_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000787_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000787_20_1 + 7) & 127;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((sec_r000787_12_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000787_20_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000787_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000787_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((sec_r000787_1_1 & 1) != 0)
  {
    if ((sec_r000787_21_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000787_19_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000787_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000787_19_1 + 7) & 127;
  }
  if ((sec_r000787_1_2 & 1) != 0)
  {
    if ((sec_r000787_21_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000787_19_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000787_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000787_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000787_4_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000787_12_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000787_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000787_12_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000787_4_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000787_12_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000787_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000787_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000787_18_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000787_9_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000787_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000787_9_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000787_18_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000787_9_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000787_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000787_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r000787_4_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000787_9_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000787_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000787_9_1 + 7) & 127;
  }
  if ((stage_v_14_2 & 1) != 0)
  {
    if ((sec_r000787_4_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000787_9_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000787_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000787_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((sec_r000787_12_1 & 1) != 0)
  {
    if ((sec_r000787_21_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000787_6_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000787_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000787_6_1 + 7) & 127;
  }
  if ((sec_r000787_12_2 & 1) != 0)
  {
    if ((sec_r000787_21_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000787_6_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000787_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000787_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000787_20_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000787_17_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000787_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000787_17_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000787_20_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000787_17_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000787_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000787_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000787_5_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000787_4_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000787_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000787_4_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000787_5_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000787_4_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000787_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000787_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000787_21_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000787_11_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000787_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000787_11_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000787_21_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000787_11_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000787_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000787_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((sec_r000787_15_1 & 1) != 0)
  {
    if ((sec_r000787_2_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000787_18_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000787_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000787_18_1 + 7) & 127;
  }
  if ((sec_r000787_15_2 & 1) != 0)
  {
    if ((sec_r000787_2_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000787_18_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000787_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000787_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000787_0_1 & 1) != 0)
  {
    if ((sec_r000787_4_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000787_11_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000787_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000787_11_1 + 7) & 127;
  }
  if ((sec_r000787_0_2 & 1) != 0)
  {
    if ((sec_r000787_4_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000787_11_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000787_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000787_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000787_19_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000787_17_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000787_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000787_17_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000787_19_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000787_17_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000787_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000787_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000787_11_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000787_0_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000787_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000787_0_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000787_11_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000787_0_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000787_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000787_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r000787_5_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000787_9_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000787_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000787_9_1 + 7) & 127;
  }
  if ((stage_v_14_2 & 1) != 0)
  {
    if ((sec_r000787_5_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000787_9_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000787_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000787_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r000787_17_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000787_2_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000787_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000787_2_1 + 7) & 127;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((sec_r000787_17_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000787_2_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000787_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000787_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000787_9_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000787_19_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000787_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000787_19_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000787_9_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000787_19_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000787_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000787_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000787_20_1 & 1) != 0)
  {
    if ((sec_r000787_14_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000787_17_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000787_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000787_17_1 + 7) & 127;
  }
  if ((sec_r000787_20_2 & 1) != 0)
  {
    if ((sec_r000787_14_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000787_17_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000787_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000787_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000787_21_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000787_17_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000787_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000787_17_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000787_21_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000787_17_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000787_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000787_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000787_4_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000787_18_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000787_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000787_18_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000787_4_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000787_18_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000787_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000787_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000787_10_1 & 1) != 0)
  {
    if ((sec_r000787_8_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000787_18_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000787_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000787_18_1 + 7) & 127;
  }
  if ((sec_r000787_10_2 & 1) != 0)
  {
    if ((sec_r000787_8_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000787_18_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000787_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000787_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000787_17_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000787_4_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000787_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000787_4_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000787_17_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000787_4_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000787_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000787_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000787_8_1 & 1) != 0)
  {
    if ((sec_r000787_21_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000787_11_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000787_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000787_11_1 + 7) & 127;
  }
  if ((sec_r000787_8_2 & 1) != 0)
  {
    if ((sec_r000787_21_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000787_11_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000787_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000787_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((sec_r000787_22_1 & 1) != 0)
  {
    if ((sec_r000787_9_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000787_3_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000787_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000787_3_1 + 7) & 127;
  }
  if ((sec_r000787_22_2 & 1) != 0)
  {
    if ((sec_r000787_9_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000787_3_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000787_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000787_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000787_10_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000787_20_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000787_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000787_20_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000787_10_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000787_20_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000787_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000787_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000787_12_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000787_3_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000787_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000787_3_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000787_12_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000787_3_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000787_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000787_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000787_9_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000787_5_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000787_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000787_5_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000787_9_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000787_5_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000787_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000787_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r000787_10_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000787_18_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000787_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000787_18_1 + 7) & 127;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r000787_10_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000787_18_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000787_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000787_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000787_1_1 & 1) != 0)
  {
    if ((sec_r000787_0_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000787_6_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000787_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000787_6_1 + 7) & 127;
  }
  if ((sec_r000787_1_2 & 1) != 0)
  {
    if ((sec_r000787_0_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000787_6_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000787_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000787_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000787_15_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000787_11_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000787_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000787_11_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000787_15_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000787_11_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000787_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000787_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000787_17_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000787_9_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000787_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000787_9_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000787_17_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000787_9_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000787_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000787_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000787_8_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000787_2_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000787_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000787_2_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000787_8_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000787_2_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000787_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000787_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000787_10_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000787_9_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000787_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000787_9_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000787_10_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000787_9_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000787_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000787_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000787_10_1 & 1) != 0)
  {
    if ((sec_r000787_12_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000787_2_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000787_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000787_2_1 + 7) & 127;
  }
  if ((sec_r000787_10_2 & 1) != 0)
  {
    if ((sec_r000787_12_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000787_2_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000787_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000787_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000787_20_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000787_1_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000787_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000787_1_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000787_20_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000787_1_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000787_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000787_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000787_13_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000787_6_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000787_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000787_6_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000787_13_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000787_6_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000787_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000787_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000787_17_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000787_16_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000787_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000787_16_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000787_17_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000787_16_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000787_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000787_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000787_11_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000787_11_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000787_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000787_11_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000787_11_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000787_11_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000787_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000787_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000787_5_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000787_1_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000787_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000787_1_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000787_5_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000787_1_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000787_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000787_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r000787_14_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000787_9_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000787_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000787_9_1 + 7) & 127;
  }
  if ((stage_v_14_2 & 1) != 0)
  {
    if ((sec_r000787_14_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000787_9_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000787_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000787_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000787_0_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000787_10_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000787_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000787_10_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000787_0_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000787_10_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000787_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000787_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000787_15_1 & 1) != 0)
  {
    if ((sec_r000787_9_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000787_4_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000787_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000787_4_1 + 7) & 127;
  }
  if ((sec_r000787_15_2 & 1) != 0)
  {
    if ((sec_r000787_9_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000787_4_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000787_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000787_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000787_8_1 & 1) != 0)
  {
    if ((sec_r000787_6_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000787_11_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000787_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000787_11_1 + 7) & 127;
  }
  if ((sec_r000787_8_2 & 1) != 0)
  {
    if ((sec_r000787_6_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000787_11_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000787_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000787_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000787_16_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000787_15_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000787_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000787_15_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000787_16_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000787_15_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000787_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000787_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000787_14_1 & 1) != 0)
  {
    if ((sec_r000787_18_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000787_7_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000787_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000787_7_1 + 7) & 127;
  }
  if ((sec_r000787_14_2 & 1) != 0)
  {
    if ((sec_r000787_18_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000787_7_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000787_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000787_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000787_18_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000787_15_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000787_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000787_15_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000787_18_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000787_15_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000787_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000787_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000787_19_1 & 1) != 0)
  {
    if ((sec_r000787_7_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000787_12_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000787_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000787_12_1 + 7) & 127;
  }
  if ((sec_r000787_19_2 & 1) != 0)
  {
    if ((sec_r000787_7_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000787_12_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000787_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000787_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000787_21_1 & 1) != 0)
  {
    if ((sec_r000787_8_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000787_9_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000787_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000787_9_1 + 7) & 127;
  }
  if ((sec_r000787_21_2 & 1) != 0)
  {
    if ((sec_r000787_8_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000787_9_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000787_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000787_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000787_22_1 & 1) != 0)
  {
    if ((sec_r000787_21_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000787_18_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000787_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000787_18_1 + 7) & 127;
  }
  if ((sec_r000787_22_2 & 1) != 0)
  {
    if ((sec_r000787_21_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000787_18_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000787_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000787_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000787_0_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000787_3_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000787_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000787_3_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000787_0_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000787_3_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000787_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000787_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000787_20_1 & 1) != 0)
  {
    if ((sec_r000787_3_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000787_0_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000787_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000787_0_1 + 7) & 127;
  }
  if ((sec_r000787_20_2 & 1) != 0)
  {
    if ((sec_r000787_3_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000787_0_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000787_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000787_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000787_20_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000787_17_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000787_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000787_17_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000787_20_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000787_17_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000787_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000787_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000787_1_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000787_15_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000787_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000787_15_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000787_1_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000787_15_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000787_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000787_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000787_5_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000787_11_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000787_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000787_11_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000787_5_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000787_11_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000787_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000787_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000787_17_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000787_4_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000787_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000787_4_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000787_17_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000787_4_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000787_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000787_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000787_0_1 & 1) != 0)
  {
    if ((sec_r000787_20_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000787_15_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000787_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000787_15_1 + 7) & 127;
  }
  if ((sec_r000787_0_2 & 1) != 0)
  {
    if ((sec_r000787_20_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000787_15_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000787_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000787_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000787_10_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000787_19_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000787_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000787_19_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000787_10_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000787_19_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000787_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000787_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000787_8_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000787_12_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000787_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000787_12_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000787_8_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000787_12_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000787_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000787_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000787_20_1 & 1) != 0)
  {
    if ((sec_r000787_7_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000787_13_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000787_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000787_13_1 + 7) & 127;
  }
  if ((sec_r000787_20_2 & 1) != 0)
  {
    if ((sec_r000787_7_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000787_13_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000787_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000787_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000787_4_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000787_13_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000787_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000787_13_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000787_4_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000787_13_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000787_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000787_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000787_17_1 & 1) != 0)
  {
    if ((sec_r000787_1_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000787_6_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000787_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000787_6_1 + 7) & 127;
  }
  if ((sec_r000787_17_2 & 1) != 0)
  {
    if ((sec_r000787_1_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000787_6_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000787_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000787_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000787_9_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000787_6_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000787_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000787_6_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000787_9_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000787_6_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000787_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000787_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000787_13_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000787_18_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000787_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000787_18_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000787_13_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000787_18_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000787_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000787_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000787_21_1 & 1) != 0)
  {
    if ((sec_r000787_13_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000787_1_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000787_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000787_1_1 + 7) & 127;
  }
  if ((sec_r000787_21_2 & 1) != 0)
  {
    if ((sec_r000787_13_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000787_1_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000787_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000787_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000787_12_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000787_9_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000787_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000787_9_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000787_12_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000787_9_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000787_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000787_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000787_21_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000787_12_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000787_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000787_12_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000787_21_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000787_12_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000787_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000787_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000787_22_1 & 1) != 0)
  {
    if ((sec_r000787_2_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000787_3_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000787_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000787_3_1 + 7) & 127;
  }
  if ((sec_r000787_22_2 & 1) != 0)
  {
    if ((sec_r000787_2_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000787_3_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000787_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000787_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000787_14_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000787_3_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000787_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000787_3_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000787_14_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000787_3_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000787_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000787_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000787_4_1 & 1) != 0)
  {
    if ((sec_r000787_7_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000787_12_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000787_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000787_12_1 + 7) & 127;
  }
  if ((sec_r000787_4_2 & 1) != 0)
  {
    if ((sec_r000787_7_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000787_12_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000787_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000787_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000787_11_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000787_15_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000787_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000787_15_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000787_11_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000787_15_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000787_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000787_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000787_9_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000787_2_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000787_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000787_2_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000787_9_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000787_2_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000787_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000787_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r000787_20_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000787_4_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000787_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000787_4_1 + 7) & 127;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((sec_r000787_20_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000787_4_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000787_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000787_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000787_15_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000787_10_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000787_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000787_10_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000787_15_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000787_10_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000787_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000787_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000787_11_1 & 1) != 0)
  {
    if ((sec_r000787_8_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000787_13_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000787_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000787_13_1 + 7) & 127;
  }
  if ((sec_r000787_11_2 & 1) != 0)
  {
    if ((sec_r000787_8_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000787_13_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000787_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000787_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000787_3_1 & 1) != 0)
  {
    if ((sec_r000787_19_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000787_3_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000787_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000787_3_1 + 7) & 127;
  }
  if ((sec_r000787_3_2 & 1) != 0)
  {
    if ((sec_r000787_19_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000787_3_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000787_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000787_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000787_21_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000787_19_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000787_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000787_19_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000787_21_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000787_19_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000787_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000787_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000787_4_1 & 1) != 0)
  {
    if ((sec_r000787_15_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000787_6_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000787_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000787_6_1 + 7) & 127;
  }
  if ((sec_r000787_4_2 & 1) != 0)
  {
    if ((sec_r000787_15_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000787_6_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000787_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000787_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000787_18_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000787_19_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000787_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000787_19_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000787_18_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000787_19_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000787_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000787_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000787_22_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000787_20_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000787_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000787_20_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000787_22_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000787_20_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000787_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000787_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000787_15_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000787_10_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000787_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000787_10_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000787_15_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000787_10_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000787_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000787_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000787_19_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000787_15_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000787_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000787_15_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000787_19_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000787_15_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000787_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000787_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000787_4_1 & 1) != 0)
  {
    if ((sec_r000787_14_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000787_16_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000787_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000787_16_1 + 7) & 127;
  }
  if ((sec_r000787_4_2 & 1) != 0)
  {
    if ((sec_r000787_14_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000787_16_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000787_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000787_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000787_5_1 & 1) != 0)
  {
    if ((sec_r000787_10_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000787_9_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000787_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000787_9_1 + 7) & 127;
  }
  if ((sec_r000787_5_2 & 1) != 0)
  {
    if ((sec_r000787_10_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000787_9_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000787_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000787_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000787_19_1 & 1) != 0)
  {
    if ((sec_r000787_10_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000787_18_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000787_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000787_18_1 + 7) & 127;
  }
  if ((sec_r000787_19_2 & 1) != 0)
  {
    if ((sec_r000787_10_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000787_18_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000787_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000787_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000787_11_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000787_14_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000787_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000787_14_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000787_11_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000787_14_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000787_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000787_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r000787_7_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000787_9_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000787_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000787_9_1 + 7) & 127;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r000787_7_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000787_9_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000787_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000787_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000787_20_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000787_9_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000787_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000787_9_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000787_20_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000787_9_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000787_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000787_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000787_9_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000787_14_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000787_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000787_14_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000787_9_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000787_14_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000787_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000787_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000787_22_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000787_8_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000787_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000787_8_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000787_22_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000787_8_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000787_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000787_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000787_3_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000787_13_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000787_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000787_13_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000787_3_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000787_13_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000787_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000787_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000787_10_1 & 1) != 0)
  {
    if ((sec_r000787_11_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000787_2_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000787_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000787_2_1 + 7) & 127;
  }
  if ((sec_r000787_10_2 & 1) != 0)
  {
    if ((sec_r000787_11_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000787_2_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000787_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000787_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000787_12_1 & 1) != 0)
  {
    if ((sec_r000787_5_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000787_1_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000787_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000787_1_1 + 7) & 127;
  }
  if ((sec_r000787_12_2 & 1) != 0)
  {
    if ((sec_r000787_5_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000787_1_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000787_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000787_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000787_19_1 & 1) != 0)
  {
    if ((sec_r000787_0_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000787_4_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000787_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000787_4_1 + 7) & 127;
  }
  if ((sec_r000787_19_2 & 1) != 0)
  {
    if ((sec_r000787_0_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000787_4_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000787_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000787_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000787_0_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000787_2_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000787_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000787_2_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000787_0_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000787_2_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000787_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000787_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((sec_r000787_20_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000787_11_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000787_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000787_11_1 + 7) & 127;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((sec_r000787_20_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000787_11_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000787_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000787_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000787_13_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000787_9_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000787_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000787_9_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000787_13_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000787_9_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000787_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000787_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000787_4_1 != sec_r000787_4_2);
  __CPROVER_assume(pub_r000787_19_1 == pub_r000787_19_2);
  __CPROVER_assume(pub_r000787_0_1 == pub_r000787_0_2);
  __CPROVER_assume(pub_r000787_17_1 == pub_r000787_17_2);
  __CPROVER_assume(sec_r000787_21_1 != sec_r000787_21_2);
  __CPROVER_assume(sec_r000787_3_1 != sec_r000787_3_2);
  __CPROVER_assume(sec_r000787_13_1 != sec_r000787_13_2);
  __CPROVER_assume(pub_r000787_1_1 == pub_r000787_1_2);
  __CPROVER_assume(pub_r000787_13_1 == pub_r000787_13_2);
  __CPROVER_assume(sec_r000787_9_1 != sec_r000787_9_2);
  __CPROVER_assume(sec_r000787_1_1 != sec_r000787_1_2);
  __CPROVER_assume(pub_r000787_7_1 == pub_r000787_7_2);
  __CPROVER_assume(pub_r000787_18_1 == pub_r000787_18_2);
  __CPROVER_assume(sec_r000787_12_1 != sec_r000787_12_2);
  __CPROVER_assume(pub_r000787_15_1 == pub_r000787_15_2);
  __CPROVER_assume(sec_r000787_18_1 != sec_r000787_18_2);
  __CPROVER_assume(sec_r000787_11_1 != sec_r000787_11_2);
  __CPROVER_assume(pub_r000787_9_1 == pub_r000787_9_2);
  __CPROVER_assume(pub_r000787_10_1 == pub_r000787_10_2);
  __CPROVER_assume(pub_r000787_16_1 == pub_r000787_16_2);
  __CPROVER_assume(sec_r000787_2_1 != sec_r000787_2_2);
  __CPROVER_assume(pub_r000787_8_1 == pub_r000787_8_2);
  __CPROVER_assume(sec_r000787_19_1 != sec_r000787_19_2);
  __CPROVER_assume(sec_r000787_8_1 != sec_r000787_8_2);
  __CPROVER_assume(sec_r000787_7_1 != sec_r000787_7_2);
  __CPROVER_assume(sec_r000787_10_1 != sec_r000787_10_2);
  __CPROVER_assume(pub_r000787_2_1 == pub_r000787_2_2);
  __CPROVER_assume(pub_r000787_3_1 == pub_r000787_3_2);
  __CPROVER_assume(sec_r000787_0_1 != sec_r000787_0_2);
  __CPROVER_assume(sec_r000787_22_1 != sec_r000787_22_2);
  __CPROVER_assume(pub_r000787_12_1 == pub_r000787_12_2);
  __CPROVER_assume(sec_r000787_5_1 != sec_r000787_5_2);
  __CPROVER_assume(pub_r000787_4_1 == pub_r000787_4_2);
  __CPROVER_assume(sec_r000787_15_1 != sec_r000787_15_2);
  __CPROVER_assume(pub_r000787_6_1 == pub_r000787_6_2);
  __CPROVER_assume(sec_r000787_17_1 != sec_r000787_17_2);
  __CPROVER_assume(pub_r000787_14_1 == pub_r000787_14_2);
  __CPROVER_assume(sec_r000787_6_1 != sec_r000787_6_2);
  __CPROVER_assume(sec_r000787_14_1 != sec_r000787_14_2);
  __CPROVER_assume(pub_r000787_11_1 == pub_r000787_11_2);
  __CPROVER_assume(pub_r000787_5_1 == pub_r000787_5_2);
  __CPROVER_assume(sec_r000787_20_1 != sec_r000787_20_2);
  __CPROVER_assume(sec_r000787_16_1 != sec_r000787_16_2);
  __CPROVER_assume(pub_r000787_20_1 == pub_r000787_20_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.state == st_var_0_2.state);
  assert(st_var_0_1.head == st_var_0_2.head);
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

  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.timeout == st_var_2_2.timeout);
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
}


