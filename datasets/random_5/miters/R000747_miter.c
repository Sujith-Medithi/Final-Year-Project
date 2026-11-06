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
struct StreamBuffer_R000747_4713_0
{
  int tail;
  short capacity;
  unsigned char watermark;
  unsigned char checksum;
  short state;
  int buffer[3];
};
struct Transaction_R000747_4713_1
{
  int status;
  short fee;
  int auth_code;
  int rate;
  short balance;
  int account_id;
  int buffer[3];
};
struct Vector3D_R000747_4713_2
{
  int heading;
  unsigned char coord_z;
  int coord_y;
  unsigned char pitch;
  int buffer[3];
};
union RegisterBank_R000747_4713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000747_4713_1
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
void fn_R000747_4713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st_1 = {0};
  struct Transaction_R000747_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int tally_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_55_1 > 40)
  {
    acc_1 = ((acc_1 + (tally_55_1 * 2)) + 5) & 127;
    aux_1 ^= tally_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_55_2 > 40)
  {
    acc_2 = ((acc_2 + (tally_55_2 * 2)) + 5) & 127;
    aux_2 ^= tally_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_19_1)
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

  switch (mask_19_2)
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
  int cursor_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_88_1) & 63;
  aux_2 = (aux_2 + cursor_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_55_1 == tally_55_2);
  assert(mask_19_1 == mask_19_2);
  assert(cursor_88_1 == cursor_88_2);
}

int fn_R000747_4713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int tally_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_55 > 40)
  {
    acc = ((acc + (tally_55 * 2)) + 5) & 127;
    aux ^= tally_55 & 15;
  }
  else
  {
    acc = ((acc - tally_55) + 11) & 127;
    aux += 3;
  }
  int mask_19 = (aux + st.buffer[1]) & 3;
  switch (mask_19)
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
  int cursor_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_88) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000747_4713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st_1 = {0};
  struct Vector3D_R000747_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_13_1 = local_arr_1[aux_1 % 3];
  int pivot_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_13_1 == pivot_13_2);
}

int fn_R000747_4713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_13 = local_arr[aux % 3];
  acc = (acc + (pivot_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000747_4713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st_1 = {0};
  struct Vector3D_R000747_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_87_1 = local_arr_1[aux_1 % 3];
  int delta_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_87_2 * 2)) & 127;
  int factor_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_86_1) & 63;
  aux_2 = (aux_2 + factor_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_60_1 > 19)
  {
    acc_1 = ((acc_1 + (weight_60_1 * 2)) + 5) & 127;
    aux_1 ^= weight_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_60_2 > 19)
  {
    acc_2 = ((acc_2 + (weight_60_2 * 2)) + 5) & 127;
    aux_2 ^= weight_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_60_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_87_1 == delta_87_2);
  assert(factor_86_1 == factor_86_2);
  assert(weight_60_1 == weight_60_2);
}

int fn_R000747_4713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int delta_87 = local_arr[aux % 3];
  acc = (acc + (delta_87 * 2)) & 127;
  int factor_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_86) & 63;
  acc ^= aux;
  int weight_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_60 > 19)
  {
    acc = ((acc + (weight_60 * 2)) + 5) & 127;
    aux ^= weight_60 & 15;
  }
  else
  {
    acc = ((acc - weight_60) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000747_4713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000747_4713_0 st_1 = {0};
  struct StreamBuffer_R000747_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int checksum_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_83_1 > 10)
  {
    acc_1 = ((acc_1 + (checksum_83_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_83_2 > 10)
  {
    acc_2 = ((acc_2 + (checksum_83_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_83_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_55_1)
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

  switch (segment_55_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_88_1 = local_arr_1[aux_1 % 3];
  int accumulator_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_88_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_83_1 == checksum_83_2);
  assert(segment_55_1 == segment_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_88_1 == accumulator_88_2);
}

int fn_R000747_4713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000747_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int checksum_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_83 > 10)
  {
    acc = ((acc + (checksum_83 * 2)) + 5) & 127;
    aux ^= checksum_83 & 15;
  }
  else
  {
    acc = ((acc - checksum_83) + 11) & 127;
    aux += 3;
  }
  int segment_55 = (aux + st.buffer[1]) & 3;
  switch (segment_55)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_88 = local_arr[aux % 3];
  acc = (acc + (accumulator_88 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000747_4713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st_1 = {0};
  struct Transaction_R000747_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int delta_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_93_1 > 29)
  {
    acc_1 = ((acc_1 + (delta_93_1 * 2)) + 5) & 127;
    aux_1 ^= delta_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_93_2 > 29)
  {
    acc_2 = ((acc_2 + (delta_93_2 * 2)) + 5) & 127;
    aux_2 ^= delta_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_93_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_75_1) & 63;
  aux_2 = (aux_2 + weight_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_93_1 == delta_93_2);
  assert(weight_75_1 == weight_75_2);
}

int fn_R000747_4713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int delta_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_93 > 29)
  {
    acc = ((acc + (delta_93 * 2)) + 5) & 127;
    aux ^= delta_93 & 15;
  }
  else
  {
    acc = ((acc - delta_93) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000747_4713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st_1 = {0};
  struct Vector3D_R000747_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_87_1 > 10)
  {
    acc_1 = ((acc_1 + (delta_87_1 * 2)) + 5) & 127;
    aux_1 ^= delta_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_87_2 > 10)
  {
    acc_2 = ((acc_2 + (delta_87_2 * 2)) + 5) & 127;
    aux_2 ^= delta_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_41_1)
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

  switch (mask_41_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_87_1 == delta_87_2);
  assert(mask_41_1 == mask_41_2);
}

int fn_R000747_4713_5(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_87 > 10)
  {
    acc = ((acc + (delta_87 * 2)) + 5) & 127;
    aux ^= delta_87 & 15;
  }
  else
  {
    acc = ((acc - delta_87) + 11) & 127;
    aux += 3;
  }
  int mask_41 = (aux + st.buffer[1]) & 3;
  switch (mask_41)
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

void fn_R000747_4713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st_1 = {0};
  struct Transaction_R000747_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_31_1 > 18)
  {
    acc_1 = ((acc_1 + (parity_31_1 * 2)) + 5) & 127;
    aux_1 ^= parity_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_31_2 > 18)
  {
    acc_2 = ((acc_2 + (parity_31_2 * 2)) + 5) & 127;
    aux_2 ^= parity_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_80_1) & 63;
  aux_2 = (aux_2 + vector_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_99_1 = local_arr_1[aux_1 % 3];
  int anchor_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_99_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_31_1 == parity_31_2);
  assert(vector_80_1 == vector_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_99_1 == anchor_99_2);
}

int fn_R000747_4713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_31 > 18)
  {
    acc = ((acc + (parity_31 * 2)) + 5) & 127;
    aux ^= parity_31 & 15;
  }
  else
  {
    acc = ((acc - parity_31) + 11) & 127;
    aux += 3;
  }
  int vector_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_80) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_99 = local_arr[aux % 3];
  acc = (acc + (anchor_99 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000747_4713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st_1 = {0};
  struct Vector3D_R000747_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int weight_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_86_1) & 63;
  aux_2 = (aux_2 + weight_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_65_1 = local_arr_1[aux_1 % 3];
  int phase_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_65_2 * 2)) & 127;
  int mask_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_34_1)
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

  switch (mask_34_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_86_1 == weight_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_65_1 == phase_65_2);
  assert(mask_34_1 == mask_34_2);
}

int fn_R000747_4713_7(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int weight_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_86) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_65 = local_arr[aux % 3];
  acc = (acc + (phase_65 * 2)) & 127;
  int mask_34 = (aux + st.buffer[1]) & 3;
  switch (mask_34)
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

void fn_R000747_4713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st_1 = {0};
  struct Vector3D_R000747_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int sample_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_86_1)
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

  switch (sample_86_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_86_1 == sample_86_2);
}

int fn_R000747_4713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int sample_86 = (aux + st.buffer[1]) & 3;
  switch (sample_86)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000747_4713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st_1 = {0};
  struct Transaction_R000747_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int residue_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_75_1)
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

  switch (residue_75_2)
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

  int offset_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_12_1 > 13)
  {
    acc_1 = ((acc_1 + (offset_12_1 * 2)) + 5) & 127;
    aux_1 ^= offset_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_12_2 > 13)
  {
    acc_2 = ((acc_2 + (offset_12_2 * 2)) + 5) & 127;
    aux_2 ^= offset_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_50_1 = local_arr_1[aux_1 % 3];
  int residue_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_50_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_75_1 == residue_75_2);
  assert(offset_12_1 == offset_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_50_1 == residue_50_2);
}

int fn_R000747_4713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int residue_75 = (aux + st.buffer[1]) & 3;
  switch (residue_75)
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

  int offset_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_12 > 13)
  {
    acc = ((acc + (offset_12 * 2)) + 5) & 127;
    aux ^= offset_12 & 15;
  }
  else
  {
    acc = ((acc - offset_12) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_50 = local_arr[aux % 3];
  acc = (acc + (residue_50 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000747_4713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st_1 = {0};
  struct Vector3D_R000747_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int stride_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_82_1)
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

  switch (stride_82_2)
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

  int residue_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_39_1 > 26)
  {
    acc_1 = ((acc_1 + (residue_39_1 * 2)) + 5) & 127;
    aux_1 ^= residue_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_39_2 > 26)
  {
    acc_2 = ((acc_2 + (residue_39_2 * 2)) + 5) & 127;
    aux_2 ^= residue_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_82_1 == stride_82_2);
  assert(residue_39_1 == residue_39_2);
}

int fn_R000747_4713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int stride_82 = (aux + st.buffer[1]) & 3;
  switch (stride_82)
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

  int residue_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_39 > 26)
  {
    acc = ((acc + (residue_39 * 2)) + 5) & 127;
    aux ^= residue_39 & 15;
  }
  else
  {
    acc = ((acc - residue_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000747_4713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st_1 = {0};
  struct Transaction_R000747_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int threshold_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_19_1) & 63;
  aux_2 = (aux_2 + threshold_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_22_1)
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

  switch (damping_22_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_59_1 = local_arr_1[aux_1 % 3];
  int stride_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_59_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_19_1 == threshold_19_2);
  assert(damping_22_1 == damping_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_59_1 == stride_59_2);
}

int fn_R000747_4713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int threshold_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_19) & 63;
  acc ^= aux;
  int damping_22 = (aux + st.buffer[1]) & 3;
  switch (damping_22)
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

  int local_arr[3] = {4, 9, 15};
  int stride_59 = local_arr[aux % 3];
  acc = (acc + (stride_59 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000747_4713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st_1 = {0};
  struct Vector3D_R000747_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int damping_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_87_1) & 63;
  aux_2 = (aux_2 + damping_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_30_1)
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

  switch (metric_30_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_87_1 == damping_87_2);
  assert(metric_30_1 == metric_30_2);
}

int fn_R000747_4713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int damping_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_87) & 63;
  acc ^= aux;
  int metric_30 = (aux + st.buffer[1]) & 3;
  switch (metric_30)
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

void fn_R000747_4713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st_1 = {0};
  struct Transaction_R000747_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int bound_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_93_1)
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

  switch (bound_93_2)
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

  int damping_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_92_1) & 63;
  aux_2 = (aux_2 + damping_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_93_1 == bound_93_2);
  assert(damping_92_1 == damping_92_2);
}

int fn_R000747_4713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int bound_93 = (aux + st.buffer[1]) & 3;
  switch (bound_93)
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

  int damping_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000747_4713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000747_4713_0 st_1 = {0};
  struct StreamBuffer_R000747_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int pivot_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_22_1) & 63;
  aux_2 = (aux_2 + pivot_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_20_1 > 39)
  {
    acc_1 = ((acc_1 + (factor_20_1 * 2)) + 5) & 127;
    aux_1 ^= factor_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_20_2 > 39)
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_22_1 == pivot_22_2);
  assert(factor_20_1 == factor_20_2);
}

int fn_R000747_4713_14(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000747_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int pivot_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_22) & 63;
  acc ^= aux;
  int factor_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_20 > 39)
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

void fn_R000747_4713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000747_4713_0 st_1 = {0};
  struct StreamBuffer_R000747_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_47_1 = local_arr_1[aux_1 % 3];
  int tally_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_47_2 * 2)) & 127;
  int metric_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_13_1 > 46)
  {
    acc_1 = ((acc_1 + (metric_13_1 * 2)) + 5) & 127;
    aux_1 ^= metric_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_13_2 > 46)
  {
    acc_2 = ((acc_2 + (metric_13_2 * 2)) + 5) & 127;
    aux_2 ^= metric_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_13_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_47_1 == tally_47_2);
  assert(metric_13_1 == metric_13_2);
}

int fn_R000747_4713_15(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000747_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_47 = local_arr[aux % 3];
  acc = (acc + (tally_47 * 2)) & 127;
  int metric_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_13 > 46)
  {
    acc = ((acc + (metric_13 * 2)) + 5) & 127;
    aux ^= metric_13 & 15;
  }
  else
  {
    acc = ((acc - metric_13) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000747_4713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st_1 = {0};
  struct Transaction_R000747_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_59_1 = local_arr_1[aux_1 % 3];
  int cursor_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_59_2 * 2)) & 127;
  int threshold_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_54_1)
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

  switch (threshold_54_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_59_1 == cursor_59_2);
  assert(threshold_54_1 == threshold_54_2);
}

int fn_R000747_4713_16(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int cursor_59 = local_arr[aux % 3];
  acc = (acc + (cursor_59 * 2)) & 127;
  int threshold_54 = (aux + st.buffer[1]) & 3;
  switch (threshold_54)
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

void fn_R000747_4713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st_1 = {0};
  struct Transaction_R000747_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_69_1 > 41)
  {
    acc_1 = ((acc_1 + (anchor_69_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_69_2 > 41)
  {
    acc_2 = ((acc_2 + (anchor_69_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_69_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_69_1 == anchor_69_2);
}

int fn_R000747_4713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_69 > 41)
  {
    acc = ((acc + (anchor_69 * 2)) + 5) & 127;
    aux ^= anchor_69 & 15;
  }
  else
  {
    acc = ((acc - anchor_69) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000747_4713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st_1 = {0};
  struct Transaction_R000747_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_62_1) & 63;
  aux_2 = (aux_2 + window_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_52_1)
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

  switch (quantum_52_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_62_1 == window_62_2);
  assert(quantum_52_1 == quantum_52_2);
}

int fn_R000747_4713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_62) & 63;
  acc ^= aux;
  int quantum_52 = (aux + st.buffer[1]) & 3;
  switch (quantum_52)
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

void fn_R000747_4713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st_1 = {0};
  struct Transaction_R000747_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int parity_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_19_1) & 63;
  aux_2 = (aux_2 + parity_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_10_1 = local_arr_1[aux_1 % 3];
  int stride_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_10_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_19_1 == parity_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_10_1 == stride_10_2);
}

int fn_R000747_4713_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000747_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int parity_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_19) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_10 = local_arr[aux % 3];
  acc = (acc + (stride_10 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000747_4713_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st_1 = {0};
  struct Vector3D_R000747_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int window_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_45_1)
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

  switch (window_45_2)
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
  int mask_75_1 = local_arr_1[aux_1 % 3];
  int mask_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_75_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_45_1 == window_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_75_1 == mask_75_2);
}

int fn_R000747_4713_20(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int window_45 = (aux + st.buffer[1]) & 3;
  switch (window_45)
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
  int mask_75 = local_arr[aux % 3];
  acc = (acc + (mask_75 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000747_4713_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st_1 = {0};
  struct Vector3D_R000747_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int accumulator_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_84_1)
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

  switch (accumulator_84_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_91_1) & 63;
  aux_2 = (aux_2 + margin_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_64_1 > 23)
  {
    acc_1 = ((acc_1 + (damping_64_1 * 2)) + 5) & 127;
    aux_1 ^= damping_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_64_2 > 23)
  {
    acc_2 = ((acc_2 + (damping_64_2 * 2)) + 5) & 127;
    aux_2 ^= damping_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_84_1 == accumulator_84_2);
  assert(margin_91_1 == margin_91_2);
  assert(damping_64_1 == damping_64_2);
}

int fn_R000747_4713_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000747_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int accumulator_84 = (aux + st.buffer[1]) & 3;
  switch (accumulator_84)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_91) & 63;
  acc ^= aux;
  int damping_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_64 > 23)
  {
    acc = ((acc + (damping_64 * 2)) + 5) & 127;
    aux ^= damping_64 & 15;
  }
  else
  {
    acc = ((acc - damping_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000747_0_1;
  int sec_r000747_0_2;
  int sec_r000747_1_1;
  int sec_r000747_1_2;
  int sec_r000747_2_1;
  int sec_r000747_2_2;
  int sec_r000747_3_1;
  int sec_r000747_3_2;
  int sec_r000747_4_1;
  int sec_r000747_4_2;
  int sec_r000747_5_1;
  int sec_r000747_5_2;
  int sec_r000747_6_1;
  int sec_r000747_6_2;
  int sec_r000747_7_1;
  int sec_r000747_7_2;
  int sec_r000747_8_1;
  int sec_r000747_8_2;
  int sec_r000747_9_1;
  int sec_r000747_9_2;
  int sec_r000747_10_1;
  int sec_r000747_10_2;
  int sec_r000747_11_1;
  int sec_r000747_11_2;
  int sec_r000747_12_1;
  int sec_r000747_12_2;
  int sec_r000747_13_1;
  int sec_r000747_13_2;
  int sec_r000747_14_1;
  int sec_r000747_14_2;
  int sec_r000747_15_1;
  int sec_r000747_15_2;
  int sec_r000747_16_1;
  int sec_r000747_16_2;
  int sec_r000747_17_1;
  int sec_r000747_17_2;
  int sec_r000747_18_1;
  int sec_r000747_18_2;
  int pub_r000747_0_1;
  int pub_r000747_0_2;
  int pub_r000747_1_1;
  int pub_r000747_1_2;
  int pub_r000747_2_1;
  int pub_r000747_2_2;
  int pub_r000747_3_1;
  int pub_r000747_3_2;
  int pub_r000747_4_1;
  int pub_r000747_4_2;
  int pub_r000747_5_1;
  int pub_r000747_5_2;
  int pub_r000747_6_1;
  int pub_r000747_6_2;
  int pub_r000747_7_1;
  int pub_r000747_7_2;
  int pub_r000747_8_1;
  int pub_r000747_8_2;
  int pub_r000747_9_1;
  int pub_r000747_9_2;
  int pub_r000747_10_1;
  int pub_r000747_10_2;
  int pub_r000747_11_1;
  int pub_r000747_11_2;
  int pub_r000747_12_1;
  int pub_r000747_12_2;
  int pub_r000747_13_1;
  int pub_r000747_13_2;
  int pub_r000747_14_1;
  int pub_r000747_14_2;
  int pub_r000747_15_1;
  int pub_r000747_15_2;
  int pub_r000747_16_1;
  int pub_r000747_16_2;
  int pub_r000747_17_1;
  int pub_r000747_17_2;
  int pub_r000747_18_1;
  int pub_r000747_18_2;
  int pub_r000747_19_1;
  int pub_r000747_19_2;
  int pub_r000747_20_1;
  int pub_r000747_20_2;
  int pub_r000747_21_1;
  int pub_r000747_21_2;
  int pub_r000747_22_1;
  int pub_r000747_22_2;
  int pub_r000747_23_1;
  int pub_r000747_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000747_0_1 >= (-100)) && (pub_r000747_0_1 <= 100));
  __CPROVER_assume((pub_r000747_0_2 >= (-100)) && (pub_r000747_0_2 <= 100));
  __CPROVER_assume((pub_r000747_1_1 >= (-100)) && (pub_r000747_1_1 <= 100));
  __CPROVER_assume((pub_r000747_1_2 >= (-100)) && (pub_r000747_1_2 <= 100));
  __CPROVER_assume((pub_r000747_2_1 >= (-100)) && (pub_r000747_2_1 <= 100));
  __CPROVER_assume((pub_r000747_2_2 >= (-100)) && (pub_r000747_2_2 <= 100));
  __CPROVER_assume((pub_r000747_3_1 >= (-100)) && (pub_r000747_3_1 <= 100));
  __CPROVER_assume((pub_r000747_3_2 >= (-100)) && (pub_r000747_3_2 <= 100));
  __CPROVER_assume((pub_r000747_4_1 >= (-100)) && (pub_r000747_4_1 <= 100));
  __CPROVER_assume((pub_r000747_4_2 >= (-100)) && (pub_r000747_4_2 <= 100));
  __CPROVER_assume((pub_r000747_5_1 >= (-100)) && (pub_r000747_5_1 <= 100));
  __CPROVER_assume((pub_r000747_5_2 >= (-100)) && (pub_r000747_5_2 <= 100));
  __CPROVER_assume((pub_r000747_6_1 >= (-100)) && (pub_r000747_6_1 <= 100));
  __CPROVER_assume((pub_r000747_6_2 >= (-100)) && (pub_r000747_6_2 <= 100));
  __CPROVER_assume((pub_r000747_7_1 >= (-100)) && (pub_r000747_7_1 <= 100));
  __CPROVER_assume((pub_r000747_7_2 >= (-100)) && (pub_r000747_7_2 <= 100));
  __CPROVER_assume((pub_r000747_8_1 >= (-100)) && (pub_r000747_8_1 <= 100));
  __CPROVER_assume((pub_r000747_8_2 >= (-100)) && (pub_r000747_8_2 <= 100));
  __CPROVER_assume((pub_r000747_9_1 >= (-100)) && (pub_r000747_9_1 <= 100));
  __CPROVER_assume((pub_r000747_9_2 >= (-100)) && (pub_r000747_9_2 <= 100));
  __CPROVER_assume((pub_r000747_10_1 >= (-100)) && (pub_r000747_10_1 <= 100));
  __CPROVER_assume((pub_r000747_10_2 >= (-100)) && (pub_r000747_10_2 <= 100));
  __CPROVER_assume((pub_r000747_11_1 >= (-100)) && (pub_r000747_11_1 <= 100));
  __CPROVER_assume((pub_r000747_11_2 >= (-100)) && (pub_r000747_11_2 <= 100));
  __CPROVER_assume((pub_r000747_12_1 >= (-100)) && (pub_r000747_12_1 <= 100));
  __CPROVER_assume((pub_r000747_12_2 >= (-100)) && (pub_r000747_12_2 <= 100));
  __CPROVER_assume((pub_r000747_13_1 >= (-100)) && (pub_r000747_13_1 <= 100));
  __CPROVER_assume((pub_r000747_13_2 >= (-100)) && (pub_r000747_13_2 <= 100));
  __CPROVER_assume((pub_r000747_14_1 >= (-100)) && (pub_r000747_14_1 <= 100));
  __CPROVER_assume((pub_r000747_14_2 >= (-100)) && (pub_r000747_14_2 <= 100));
  __CPROVER_assume((pub_r000747_15_1 >= (-100)) && (pub_r000747_15_1 <= 100));
  __CPROVER_assume((pub_r000747_15_2 >= (-100)) && (pub_r000747_15_2 <= 100));
  __CPROVER_assume((pub_r000747_16_1 >= (-100)) && (pub_r000747_16_1 <= 100));
  __CPROVER_assume((pub_r000747_16_2 >= (-100)) && (pub_r000747_16_2 <= 100));
  __CPROVER_assume((pub_r000747_17_1 >= (-100)) && (pub_r000747_17_1 <= 100));
  __CPROVER_assume((pub_r000747_17_2 >= (-100)) && (pub_r000747_17_2 <= 100));
  __CPROVER_assume((pub_r000747_18_1 >= (-100)) && (pub_r000747_18_1 <= 100));
  __CPROVER_assume((pub_r000747_18_2 >= (-100)) && (pub_r000747_18_2 <= 100));
  __CPROVER_assume((pub_r000747_19_1 >= (-100)) && (pub_r000747_19_1 <= 100));
  __CPROVER_assume((pub_r000747_19_2 >= (-100)) && (pub_r000747_19_2 <= 100));
  __CPROVER_assume((pub_r000747_20_1 >= (-100)) && (pub_r000747_20_1 <= 100));
  __CPROVER_assume((pub_r000747_20_2 >= (-100)) && (pub_r000747_20_2 <= 100));
  __CPROVER_assume((pub_r000747_21_1 >= (-100)) && (pub_r000747_21_1 <= 100));
  __CPROVER_assume((pub_r000747_21_2 >= (-100)) && (pub_r000747_21_2 <= 100));
  __CPROVER_assume((pub_r000747_22_1 >= (-100)) && (pub_r000747_22_1 <= 100));
  __CPROVER_assume((pub_r000747_22_2 >= (-100)) && (pub_r000747_22_2 <= 100));
  __CPROVER_assume((pub_r000747_23_1 >= (-100)) && (pub_r000747_23_1 <= 100));
  __CPROVER_assume((pub_r000747_23_2 >= (-100)) && (pub_r000747_23_2 <= 100));
  __CPROVER_assume((sec_r000747_0_1 >= 0) && (sec_r000747_0_1 <= 255));
  __CPROVER_assume((sec_r000747_0_2 >= 0) && (sec_r000747_0_2 <= 255));
  __CPROVER_assume((sec_r000747_1_1 >= 0) && (sec_r000747_1_1 <= 255));
  __CPROVER_assume((sec_r000747_1_2 >= 0) && (sec_r000747_1_2 <= 255));
  __CPROVER_assume((sec_r000747_2_1 >= 0) && (sec_r000747_2_1 <= 255));
  __CPROVER_assume((sec_r000747_2_2 >= 0) && (sec_r000747_2_2 <= 255));
  __CPROVER_assume((sec_r000747_3_1 >= 0) && (sec_r000747_3_1 <= 255));
  __CPROVER_assume((sec_r000747_3_2 >= 0) && (sec_r000747_3_2 <= 255));
  __CPROVER_assume((sec_r000747_4_1 >= 0) && (sec_r000747_4_1 <= 255));
  __CPROVER_assume((sec_r000747_4_2 >= 0) && (sec_r000747_4_2 <= 255));
  __CPROVER_assume((sec_r000747_5_1 >= 0) && (sec_r000747_5_1 <= 255));
  __CPROVER_assume((sec_r000747_5_2 >= 0) && (sec_r000747_5_2 <= 255));
  __CPROVER_assume((sec_r000747_6_1 >= 0) && (sec_r000747_6_1 <= 255));
  __CPROVER_assume((sec_r000747_6_2 >= 0) && (sec_r000747_6_2 <= 255));
  __CPROVER_assume((sec_r000747_7_1 >= 0) && (sec_r000747_7_1 <= 255));
  __CPROVER_assume((sec_r000747_7_2 >= 0) && (sec_r000747_7_2 <= 255));
  __CPROVER_assume((sec_r000747_8_1 >= 0) && (sec_r000747_8_1 <= 255));
  __CPROVER_assume((sec_r000747_8_2 >= 0) && (sec_r000747_8_2 <= 255));
  __CPROVER_assume((sec_r000747_9_1 >= 0) && (sec_r000747_9_1 <= 255));
  __CPROVER_assume((sec_r000747_9_2 >= 0) && (sec_r000747_9_2 <= 255));
  __CPROVER_assume((sec_r000747_10_1 >= 0) && (sec_r000747_10_1 <= 255));
  __CPROVER_assume((sec_r000747_10_2 >= 0) && (sec_r000747_10_2 <= 255));
  __CPROVER_assume((sec_r000747_11_1 >= 0) && (sec_r000747_11_1 <= 255));
  __CPROVER_assume((sec_r000747_11_2 >= 0) && (sec_r000747_11_2 <= 255));
  __CPROVER_assume((sec_r000747_12_1 >= 0) && (sec_r000747_12_1 <= 255));
  __CPROVER_assume((sec_r000747_12_2 >= 0) && (sec_r000747_12_2 <= 255));
  __CPROVER_assume((sec_r000747_13_1 >= 0) && (sec_r000747_13_1 <= 255));
  __CPROVER_assume((sec_r000747_13_2 >= 0) && (sec_r000747_13_2 <= 255));
  __CPROVER_assume((sec_r000747_14_1 >= 0) && (sec_r000747_14_1 <= 255));
  __CPROVER_assume((sec_r000747_14_2 >= 0) && (sec_r000747_14_2 <= 255));
  __CPROVER_assume((sec_r000747_15_1 >= 0) && (sec_r000747_15_1 <= 255));
  __CPROVER_assume((sec_r000747_15_2 >= 0) && (sec_r000747_15_2 <= 255));
  __CPROVER_assume((sec_r000747_16_1 >= 0) && (sec_r000747_16_1 <= 255));
  __CPROVER_assume((sec_r000747_16_2 >= 0) && (sec_r000747_16_2 <= 255));
  __CPROVER_assume((sec_r000747_17_1 >= 0) && (sec_r000747_17_1 <= 255));
  __CPROVER_assume((sec_r000747_17_2 >= 0) && (sec_r000747_17_2 <= 255));
  __CPROVER_assume((sec_r000747_18_1 >= 0) && (sec_r000747_18_1 <= 255));
  __CPROVER_assume((sec_r000747_18_2 >= 0) && (sec_r000747_18_2 <= 255));
  struct StreamBuffer_R000747_4713_0 st_var_0_1 = {0};
  struct StreamBuffer_R000747_4713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000747_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000747_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000747_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000747_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000747_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000747_0_2 + 7) & 15;
  struct Transaction_R000747_4713_1 st_var_1_1 = {0};
  struct Transaction_R000747_4713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000747_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000747_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000747_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000747_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000747_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000747_0_2 + 9) & 15;
  struct Vector3D_R000747_4713_2 st_var_2_1 = {0};
  struct Vector3D_R000747_4713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000747_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000747_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000747_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000747_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000747_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000747_0_2 + 11) & 15;
  union RegisterBank_R000747_4713_0 u_var_1;
  union RegisterBank_R000747_4713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 45)
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
  if (stage_v_0_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 45)
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
  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
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

  switch (stage_v_7_2)
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
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = (st_var_1_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_1_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = (st_var_2_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_2_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (20 & 31);
  int stage_v_15_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (20 & 31);
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= (stage_v_15_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_15_2 << 1) & 127;
  int stage_v_16_1 = ((st_var_1_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_1_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 34)
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
  if (stage_v_16_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 34)
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
  int stage_v_17_1 = ((st_var_2_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_2_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 38)
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
  if (stage_v_17_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 38)
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
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 20) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 20) & 15;
  int stage_v_19_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_19_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= stage_v_19_1;
  chk_sum_2 ^= stage_v_19_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 21) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  int stage_v_21_1 = (st_var_0_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_0_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (28 & 31);
  int stage_v_23_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (28 & 31);
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= (stage_v_23_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_23_2 << 1) & 127;
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_26_1 = (st_var_2_1.buffer[0] ^ 29) & 3;
  int stage_v_26_2 = (st_var_2_2.buffer[0] ^ 29) & 3;
  switch (stage_v_26_1)
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

  switch (stage_v_26_2)
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

  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (33 & 31);
  int stage_v_28_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (33 & 31);
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= (stage_v_28_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_28_2 << 1) & 127;
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
  int stage_v_30_1 = (st_var_0_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_0_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  int stage_v_31_1 = (st_var_1_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_1_2.buffer[0] ^ 34) & 3;
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 33) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 35) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = (st_var_2_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_2_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
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

  switch (stage_v_35_2)
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

  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 40) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (45 & 31);
  int stage_v_40_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (45 & 31);
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= (stage_v_40_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_40_2 << 1) & 127;
  int stage_v_41_1 = ((st_var_2_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_2_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 43)
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
  if (stage_v_41_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 43)
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
  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_43_1 = (st_var_1_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_1_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
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

  switch (stage_v_43_2)
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
  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
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
  int stage_v_48_1 = ((st_var_0_1.buffer[0] * 2) + 151) & 63;
  int stage_v_48_2 = ((st_var_0_2.buffer[0] * 2) + 151) & 63;
  if (stage_v_48_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_48_1) - 5) & 255;
    if (stage_v_48_1 > 39)
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
  if (stage_v_48_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_48_2) - 5) & 255;
    if (stage_v_48_2 > 39)
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

  switch (stage_v_49_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 51) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 51) & 15;
  int stage_v_50_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_50_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= stage_v_50_1;
  chk_sum_2 ^= stage_v_50_2;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_51_1 = ((stage_v_51_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (st_var_1_1.buffer[0] ^ 55) & 3;
  int stage_v_52_2 = (st_var_1_2.buffer[0] ^ 55) & 3;
  switch (stage_v_52_1)
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

  switch (stage_v_52_2)
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

  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((st_var_0_1.buffer[0] * 2) + 169) & 63;
  int stage_v_54_2 = ((st_var_0_2.buffer[0] * 2) + 169) & 63;
  if (stage_v_54_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_54_1) - 5) & 255;
    if (stage_v_54_1 > 38)
    {
      chk_sum_1 ^= stage_v_54_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_54_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_54_2) - 5) & 255;
    if (stage_v_54_2 > 38)
    {
      chk_sum_2 ^= stage_v_54_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 56) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 56) & 15;
  int stage_v_55_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_55_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= stage_v_55_1;
  chk_sum_2 ^= stage_v_55_2;
  int stage_v_56_1 = (st_var_2_1.buffer[0] ^ 59) & 3;
  int stage_v_56_2 = (st_var_2_2.buffer[0] ^ 59) & 3;
  switch (stage_v_56_1)
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

  switch (stage_v_56_2)
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
  int stage_v_59_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_59_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_60_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (65 & 31);
  int stage_v_60_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (65 & 31);
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= (stage_v_60_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_60_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 62) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 62) & 15;
  int stage_v_61_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_61_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= stage_v_61_1;
  chk_sum_2 ^= stage_v_61_2;
  int stage_v_62_1 = (st_var_2_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_2_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_63_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_64_1 = (st_var_1_1.buffer[0] ^ 67) & 3;
  int stage_v_64_2 = (st_var_1_2.buffer[0] ^ 67) & 3;
  switch (stage_v_64_1)
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

  switch (stage_v_64_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 66) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 66) & 15;
  int stage_v_65_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_65_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= stage_v_65_1;
  chk_sum_2 ^= stage_v_65_2;
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
  int stage_v_67_1 = table_1[3];
  int stage_v_67_2 = table_2[3];
  table_1[3] = (table_1[0] + 135) & 63;
  table_2[3] = (table_2[0] + 135) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (st_var_2_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_2_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
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

  switch (stage_v_68_2)
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

  int stage_v_69_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_69_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_70_1 = table_1[2];
  int stage_v_70_2 = table_2[2];
  table_1[2] = (table_1[3] + 141) & 63;
  table_2[2] = (table_2[3] + 141) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000747_10_1 & 1) != 0)
  {
    if ((sec_r000747_8_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000747_9_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000747_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000747_9_1 + 7) & 127;
  }
  if ((sec_r000747_10_2 & 1) != 0)
  {
    if ((sec_r000747_8_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000747_9_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000747_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000747_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000747_4_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000747_9_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000747_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000747_9_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000747_4_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000747_9_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000747_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000747_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000747_11_1 & 1) != 0)
  {
    if ((sec_r000747_9_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000747_8_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000747_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000747_8_1 + 7) & 127;
  }
  if ((sec_r000747_11_2 & 1) != 0)
  {
    if ((sec_r000747_9_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000747_8_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000747_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000747_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000747_8_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000747_12_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000747_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000747_12_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000747_8_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000747_12_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000747_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000747_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000747_17_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000747_15_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000747_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000747_15_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000747_17_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000747_15_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000747_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000747_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000747_6_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000747_4_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000747_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000747_4_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000747_6_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000747_4_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000747_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000747_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000747_1_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000747_10_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000747_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000747_10_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000747_1_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000747_10_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000747_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000747_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000747_13_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000747_19_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000747_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000747_19_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000747_13_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000747_19_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000747_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000747_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000747_18_1 & 1) != 0)
  {
    if ((sec_r000747_7_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000747_19_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000747_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000747_19_1 + 7) & 127;
  }
  if ((sec_r000747_18_2 & 1) != 0)
  {
    if ((sec_r000747_7_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000747_19_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000747_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000747_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000747_1_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000747_3_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000747_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000747_3_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000747_1_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000747_3_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000747_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000747_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000747_9_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000747_11_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000747_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000747_11_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000747_9_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000747_11_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000747_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000747_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000747_5_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000747_3_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000747_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000747_3_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000747_5_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000747_3_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000747_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000747_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000747_2_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000747_18_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000747_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000747_18_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000747_2_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000747_18_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000747_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000747_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000747_7_1 & 1) != 0)
  {
    if ((sec_r000747_13_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000747_2_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000747_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000747_2_1 + 7) & 127;
  }
  if ((sec_r000747_7_2 & 1) != 0)
  {
    if ((sec_r000747_13_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000747_2_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000747_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000747_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000747_5_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000747_19_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000747_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000747_19_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000747_5_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000747_19_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000747_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000747_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000747_4_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000747_7_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000747_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000747_7_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000747_4_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000747_7_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000747_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000747_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000747_6_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000747_17_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000747_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000747_17_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000747_6_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000747_17_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000747_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000747_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000747_13_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000747_0_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000747_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000747_0_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000747_13_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000747_0_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000747_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000747_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000747_8_1 & 1) != 0)
  {
    if ((sec_r000747_10_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000747_10_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000747_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000747_10_1 + 7) & 127;
  }
  if ((sec_r000747_8_2 & 1) != 0)
  {
    if ((sec_r000747_10_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000747_10_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000747_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000747_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000747_11_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000747_15_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000747_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000747_15_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000747_11_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000747_15_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000747_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000747_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000747_12_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000747_3_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000747_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000747_3_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000747_12_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000747_3_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000747_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000747_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000747_16_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000747_21_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000747_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000747_21_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000747_16_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000747_21_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000747_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000747_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000747_8_1 & 1) != 0)
  {
    if ((sec_r000747_0_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000747_14_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000747_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000747_14_1 + 7) & 127;
  }
  if ((sec_r000747_8_2 & 1) != 0)
  {
    if ((sec_r000747_0_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000747_14_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000747_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000747_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000747_12_1 & 1) != 0)
  {
    if ((sec_r000747_18_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000747_17_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000747_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000747_17_1 + 7) & 127;
  }
  if ((sec_r000747_12_2 & 1) != 0)
  {
    if ((sec_r000747_18_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000747_17_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000747_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000747_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000747_17_1 & 1) != 0)
  {
    if ((sec_r000747_5_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000747_18_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000747_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000747_18_1 + 7) & 127;
  }
  if ((sec_r000747_17_2 & 1) != 0)
  {
    if ((sec_r000747_5_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000747_18_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000747_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000747_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000747_17_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000747_1_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000747_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000747_1_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000747_17_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000747_1_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000747_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000747_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000747_13_1 & 1) != 0)
  {
    if ((sec_r000747_4_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000747_22_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000747_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000747_22_1 + 7) & 127;
  }
  if ((sec_r000747_13_2 & 1) != 0)
  {
    if ((sec_r000747_4_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000747_22_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000747_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000747_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000747_7_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000747_8_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000747_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000747_8_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000747_7_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000747_8_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000747_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000747_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000747_17_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000747_5_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000747_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000747_5_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000747_17_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000747_5_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000747_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000747_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000747_3_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000747_1_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000747_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000747_1_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000747_3_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000747_1_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000747_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000747_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000747_6_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000747_2_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000747_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000747_2_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000747_6_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000747_2_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000747_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000747_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000747_13_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000747_23_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000747_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000747_23_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000747_13_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000747_23_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000747_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000747_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000747_2_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000747_21_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000747_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000747_21_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000747_2_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000747_21_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000747_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000747_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000747_15_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000747_23_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000747_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000747_23_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000747_15_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000747_23_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000747_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000747_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000747_5_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000747_12_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000747_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000747_12_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000747_5_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000747_12_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000747_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000747_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000747_10_1 & 1) != 0)
  {
    if ((sec_r000747_4_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000747_5_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000747_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000747_5_1 + 7) & 127;
  }
  if ((sec_r000747_10_2 & 1) != 0)
  {
    if ((sec_r000747_4_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000747_5_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000747_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000747_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000747_11_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000747_11_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000747_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000747_11_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000747_11_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000747_11_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000747_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000747_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000747_16_1 & 1) != 0)
  {
    if ((sec_r000747_14_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000747_22_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000747_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000747_22_1 + 7) & 127;
  }
  if ((sec_r000747_16_2 & 1) != 0)
  {
    if ((sec_r000747_14_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000747_22_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000747_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000747_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000747_7_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000747_6_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000747_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000747_6_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000747_7_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000747_6_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000747_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000747_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000747_4_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000747_4_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000747_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000747_4_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000747_4_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000747_4_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000747_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000747_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000747_10_1 & 1) != 0)
  {
    if ((sec_r000747_10_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000747_1_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000747_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000747_1_1 + 7) & 127;
  }
  if ((sec_r000747_10_2 & 1) != 0)
  {
    if ((sec_r000747_10_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000747_1_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000747_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000747_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000747_13_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000747_16_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000747_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000747_16_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000747_13_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000747_16_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000747_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000747_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000747_3_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000747_16_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000747_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000747_16_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000747_3_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000747_16_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000747_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000747_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000747_11_1 & 1) != 0)
  {
    if ((sec_r000747_15_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000747_7_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000747_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000747_7_1 + 7) & 127;
  }
  if ((sec_r000747_11_2 & 1) != 0)
  {
    if ((sec_r000747_15_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000747_7_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000747_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000747_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000747_1_1 & 1) != 0)
  {
    if ((sec_r000747_4_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000747_10_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000747_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000747_10_1 + 7) & 127;
  }
  if ((sec_r000747_1_2 & 1) != 0)
  {
    if ((sec_r000747_4_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000747_10_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000747_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000747_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000747_8_1 & 1) != 0)
  {
    if ((sec_r000747_11_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000747_11_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000747_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000747_11_1 + 7) & 127;
  }
  if ((sec_r000747_8_2 & 1) != 0)
  {
    if ((sec_r000747_11_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000747_11_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000747_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000747_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000747_11_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000747_3_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000747_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000747_3_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000747_11_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000747_3_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000747_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000747_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000747_13_1 & 1) != 0)
  {
    if ((sec_r000747_4_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000747_14_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000747_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000747_14_1 + 7) & 127;
  }
  if ((sec_r000747_13_2 & 1) != 0)
  {
    if ((sec_r000747_4_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000747_14_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000747_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000747_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000747_15_1 & 1) != 0)
  {
    if ((sec_r000747_1_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000747_21_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000747_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000747_21_1 + 7) & 127;
  }
  if ((sec_r000747_15_2 & 1) != 0)
  {
    if ((sec_r000747_1_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000747_21_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000747_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000747_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000747_11_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000747_22_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000747_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000747_22_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000747_11_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000747_22_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000747_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000747_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000747_12_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000747_19_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000747_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000747_19_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000747_12_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000747_19_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000747_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000747_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000747_6_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000747_11_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000747_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000747_11_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000747_6_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000747_11_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000747_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000747_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000747_12_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000747_6_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000747_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000747_6_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000747_12_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000747_6_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000747_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000747_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000747_12_1 & 1) != 0)
  {
    if ((sec_r000747_14_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000747_17_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000747_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000747_17_1 + 7) & 127;
  }
  if ((sec_r000747_12_2 & 1) != 0)
  {
    if ((sec_r000747_14_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000747_17_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000747_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000747_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000747_15_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000747_17_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000747_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000747_17_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000747_15_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000747_17_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000747_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000747_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000747_8_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000747_20_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000747_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000747_20_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000747_8_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000747_20_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000747_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000747_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000747_7_1 & 1) != 0)
  {
    if ((sec_r000747_16_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000747_4_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000747_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000747_4_1 + 7) & 127;
  }
  if ((sec_r000747_7_2 & 1) != 0)
  {
    if ((sec_r000747_16_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000747_4_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000747_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000747_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r000747_12_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000747_23_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000747_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000747_23_1 + 7) & 127;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r000747_12_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000747_23_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000747_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000747_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000747_13_1 & 1) != 0)
  {
    if ((sec_r000747_1_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000747_7_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000747_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000747_7_1 + 7) & 127;
  }
  if ((sec_r000747_13_2 & 1) != 0)
  {
    if ((sec_r000747_1_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000747_7_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000747_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000747_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000747_12_1 & 1) != 0)
  {
    if ((sec_r000747_6_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000747_19_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000747_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000747_19_1 + 7) & 127;
  }
  if ((sec_r000747_12_2 & 1) != 0)
  {
    if ((sec_r000747_6_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000747_19_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000747_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000747_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000747_7_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000747_22_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000747_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000747_22_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000747_7_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000747_22_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000747_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000747_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000747_13_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000747_8_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000747_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000747_8_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000747_13_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000747_8_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000747_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000747_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000747_14_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000747_7_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000747_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000747_7_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000747_14_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000747_7_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000747_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000747_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000747_18_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000747_10_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000747_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000747_10_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000747_18_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000747_10_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000747_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000747_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000747_7_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000747_1_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000747_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000747_1_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000747_7_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000747_1_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000747_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000747_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((sec_r000747_8_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000747_23_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000747_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000747_23_1 + 7) & 127;
  }
  if ((stage_v_134_2 & 1) != 0)
  {
    if ((sec_r000747_8_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000747_23_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000747_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000747_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000747_10_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000747_11_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000747_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000747_11_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000747_10_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000747_11_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000747_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000747_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000747_3_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000747_10_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000747_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000747_10_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000747_3_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000747_10_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000747_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000747_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000747_21_1 == pub_r000747_21_2);
  __CPROVER_assume(sec_r000747_2_1 != sec_r000747_2_2);
  __CPROVER_assume(pub_r000747_18_1 == pub_r000747_18_2);
  __CPROVER_assume(sec_r000747_6_1 != sec_r000747_6_2);
  __CPROVER_assume(pub_r000747_1_1 == pub_r000747_1_2);
  __CPROVER_assume(pub_r000747_10_1 == pub_r000747_10_2);
  __CPROVER_assume(sec_r000747_3_1 != sec_r000747_3_2);
  __CPROVER_assume(pub_r000747_12_1 == pub_r000747_12_2);
  __CPROVER_assume(sec_r000747_1_1 != sec_r000747_1_2);
  __CPROVER_assume(pub_r000747_4_1 == pub_r000747_4_2);
  __CPROVER_assume(pub_r000747_6_1 == pub_r000747_6_2);
  __CPROVER_assume(sec_r000747_9_1 != sec_r000747_9_2);
  __CPROVER_assume(pub_r000747_13_1 == pub_r000747_13_2);
  __CPROVER_assume(pub_r000747_0_1 == pub_r000747_0_2);
  __CPROVER_assume(pub_r000747_5_1 == pub_r000747_5_2);
  __CPROVER_assume(pub_r000747_7_1 == pub_r000747_7_2);
  __CPROVER_assume(pub_r000747_20_1 == pub_r000747_20_2);
  __CPROVER_assume(sec_r000747_4_1 != sec_r000747_4_2);
  __CPROVER_assume(pub_r000747_8_1 == pub_r000747_8_2);
  __CPROVER_assume(pub_r000747_17_1 == pub_r000747_17_2);
  __CPROVER_assume(pub_r000747_11_1 == pub_r000747_11_2);
  __CPROVER_assume(sec_r000747_14_1 != sec_r000747_14_2);
  __CPROVER_assume(sec_r000747_11_1 != sec_r000747_11_2);
  __CPROVER_assume(pub_r000747_19_1 == pub_r000747_19_2);
  __CPROVER_assume(sec_r000747_16_1 != sec_r000747_16_2);
  __CPROVER_assume(sec_r000747_8_1 != sec_r000747_8_2);
  __CPROVER_assume(sec_r000747_7_1 != sec_r000747_7_2);
  __CPROVER_assume(sec_r000747_18_1 != sec_r000747_18_2);
  __CPROVER_assume(sec_r000747_10_1 != sec_r000747_10_2);
  __CPROVER_assume(pub_r000747_14_1 == pub_r000747_14_2);
  __CPROVER_assume(sec_r000747_0_1 != sec_r000747_0_2);
  __CPROVER_assume(sec_r000747_5_1 != sec_r000747_5_2);
  __CPROVER_assume(sec_r000747_12_1 != sec_r000747_12_2);
  __CPROVER_assume(pub_r000747_9_1 == pub_r000747_9_2);
  __CPROVER_assume(pub_r000747_23_1 == pub_r000747_23_2);
  __CPROVER_assume(sec_r000747_15_1 != sec_r000747_15_2);
  __CPROVER_assume(pub_r000747_16_1 == pub_r000747_16_2);
  __CPROVER_assume(pub_r000747_3_1 == pub_r000747_3_2);
  __CPROVER_assume(sec_r000747_17_1 != sec_r000747_17_2);
  __CPROVER_assume(pub_r000747_15_1 == pub_r000747_15_2);
  __CPROVER_assume(sec_r000747_13_1 != sec_r000747_13_2);
  __CPROVER_assume(pub_r000747_2_1 == pub_r000747_2_2);
  __CPROVER_assume(pub_r000747_22_1 == pub_r000747_22_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.tail == st_var_0_2.tail);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.state == st_var_0_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  assert(st_var_2_1.pitch == st_var_2_2.pitch);
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
}


