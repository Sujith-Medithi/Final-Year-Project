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
struct CipherContext_R000637_3713_0
{
  int round_key;
  int nonce;
  int flags;
  short iv;
  int tag;
  unsigned char counter;
  int buffer[3];
};
struct DeviceConfig_R000637_3713_1
{
  int stop_bits;
  unsigned char parity;
  int baud_rate;
  int buffer[3];
};
struct Vector3D_R000637_3713_2
{
  unsigned char coord_z;
  int heading;
  int coord_x;
  int pitch;
  int coord_y;
  int buffer[3];
};
union TelemetryField_R000637_3713_0
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
void fn_R000637_3713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000637_3713_0 st_1 = {0};
  struct CipherContext_R000637_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int weight_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_76_1 > 47)
  {
    acc_1 = ((acc_1 + (weight_76_1 * 2)) + 5) & 127;
    aux_1 ^= weight_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_76_2 > 47)
  {
    acc_2 = ((acc_2 + (weight_76_2 * 2)) + 5) & 127;
    aux_2 ^= weight_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_89_1 = local_arr_1[aux_1 % 3];
  int vector_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_89_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_45_1)
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

  switch (checksum_45_2)
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
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_76_1 == weight_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_89_1 == vector_89_2);
  assert(checksum_45_1 == checksum_45_2);
}

int fn_R000637_3713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000637_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int weight_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_76 > 47)
  {
    acc = ((acc + (weight_76 * 2)) + 5) & 127;
    aux ^= weight_76 & 15;
  }
  else
  {
    acc = ((acc - weight_76) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_89 = local_arr[aux % 3];
  acc = (acc + (vector_89 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_45 = (aux + st.buffer[1]) & 3;
  switch (checksum_45)
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

void fn_R000637_3713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000637_3713_0 st_1 = {0};
  struct CipherContext_R000637_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int offset_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_30_1) & 63;
  aux_2 = (aux_2 + offset_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_50_1 = local_arr_1[aux_1 % 3];
  int factor_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_50_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_30_1 == offset_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_50_1 == factor_50_2);
}

int fn_R000637_3713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000637_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int offset_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_30) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_50 = local_arr[aux % 3];
  acc = (acc + (factor_50 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000637_3713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st_1 = {0};
  struct DeviceConfig_R000637_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_81_1 = local_arr_1[aux_1 % 3];
  int pivot_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_81_2 * 2)) & 127;
  int damping_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_19_1) & 63;
  aux_2 = (aux_2 + damping_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_11_1 > 17)
  {
    acc_1 = ((acc_1 + (tally_11_1 * 2)) + 5) & 127;
    aux_1 ^= tally_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_11_2 > 17)
  {
    acc_2 = ((acc_2 + (tally_11_2 * 2)) + 5) & 127;
    aux_2 ^= tally_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_11_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_81_1 == pivot_81_2);
  assert(damping_19_1 == damping_19_2);
  assert(tally_11_1 == tally_11_2);
}

int fn_R000637_3713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int pivot_81 = local_arr[aux % 3];
  acc = (acc + (pivot_81 * 2)) & 127;
  int damping_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_19) & 63;
  acc ^= aux;
  int tally_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_11 > 17)
  {
    acc = ((acc + (tally_11 * 2)) + 5) & 127;
    aux ^= tally_11 & 15;
  }
  else
  {
    acc = ((acc - tally_11) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000637_3713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st_1 = {0};
  struct DeviceConfig_R000637_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_82_1 = local_arr_1[aux_1 % 3];
  int weight_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_82_1 == weight_82_2);
}

int fn_R000637_3713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_82 = local_arr[aux % 3];
  acc = (acc + (weight_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000637_3713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000637_3713_0 st_1 = {0};
  struct CipherContext_R000637_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int scale_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_42_1 > 30)
  {
    acc_1 = ((acc_1 + (scale_42_1 * 2)) + 5) & 127;
    aux_1 ^= scale_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_42_2 > 30)
  {
    acc_2 = ((acc_2 + (scale_42_2 * 2)) + 5) & 127;
    aux_2 ^= scale_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_42_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_48_1 = local_arr_1[aux_1 % 3];
  int accumulator_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_48_2 * 2)) & 127;
  int bound_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_20_1) & 63;
  aux_2 = (aux_2 + bound_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_42_1 == scale_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_48_1 == accumulator_48_2);
  assert(bound_20_1 == bound_20_2);
}

int fn_R000637_3713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000637_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int scale_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_42 > 30)
  {
    acc = ((acc + (scale_42 * 2)) + 5) & 127;
    aux ^= scale_42 & 15;
  }
  else
  {
    acc = ((acc - scale_42) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_48 = local_arr[aux % 3];
  acc = (acc + (accumulator_48 * 2)) & 127;
  int bound_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_20) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000637_3713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st_1 = {0};
  struct DeviceConfig_R000637_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int checksum_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_78_1 > 40)
  {
    acc_1 = ((acc_1 + (checksum_78_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_78_2 > 40)
  {
    acc_2 = ((acc_2 + (checksum_78_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_15_1)
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

  switch (pivot_15_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_10_1) & 63;
  aux_2 = (aux_2 + phase_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_78_1 == checksum_78_2);
  assert(pivot_15_1 == pivot_15_2);
  assert(phase_10_1 == phase_10_2);
}

int fn_R000637_3713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int checksum_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_78 > 40)
  {
    acc = ((acc + (checksum_78 * 2)) + 5) & 127;
    aux ^= checksum_78 & 15;
  }
  else
  {
    acc = ((acc - checksum_78) + 11) & 127;
    aux += 3;
  }
  int pivot_15 = (aux + st.buffer[1]) & 3;
  switch (pivot_15)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_10) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000637_3713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000637_3713_2 st_1 = {0};
  struct Vector3D_R000637_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int bound_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_86_1) & 63;
  aux_2 = (aux_2 + bound_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_84_1 > 18)
  {
    acc_1 = ((acc_1 + (pivot_84_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_84_2 > 18)
  {
    acc_2 = ((acc_2 + (pivot_84_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_16_1)
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

  switch (weight_16_2)
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
  int phase_36_1 = local_arr_1[aux_1 % 3];
  int phase_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_86_1 == bound_86_2);
  assert(pivot_84_1 == pivot_84_2);
  assert(weight_16_1 == weight_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_36_1 == phase_36_2);
}

int fn_R000637_3713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000637_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int bound_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_86) & 63;
  acc ^= aux;
  int pivot_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_84 > 18)
  {
    acc = ((acc + (pivot_84 * 2)) + 5) & 127;
    aux ^= pivot_84 & 15;
  }
  else
  {
    acc = ((acc - pivot_84) + 11) & 127;
    aux += 3;
  }
  int weight_16 = (aux + st.buffer[1]) & 3;
  switch (weight_16)
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
  int phase_36 = local_arr[aux % 3];
  acc = (acc + (phase_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000637_3713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st_1 = {0};
  struct DeviceConfig_R000637_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int vector_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_26_1)
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

  switch (vector_26_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_38_1) & 63;
  aux_2 = (aux_2 + margin_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_15_1 > 19)
  {
    acc_1 = ((acc_1 + (factor_15_1 * 2)) + 5) & 127;
    aux_1 ^= factor_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_15_2 > 19)
  {
    acc_2 = ((acc_2 + (factor_15_2 * 2)) + 5) & 127;
    aux_2 ^= factor_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_15_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_26_1 == vector_26_2);
  assert(margin_38_1 == margin_38_2);
  assert(factor_15_1 == factor_15_2);
}

int fn_R000637_3713_7(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int vector_26 = (aux + st.buffer[1]) & 3;
  switch (vector_26)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_38) & 63;
  acc ^= aux;
  int factor_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_15 > 19)
  {
    acc = ((acc + (factor_15 * 2)) + 5) & 127;
    aux ^= factor_15 & 15;
  }
  else
  {
    acc = ((acc - factor_15) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000637_3713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st_1 = {0};
  struct DeviceConfig_R000637_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_12_1 = local_arr_1[aux_1 % 3];
  int parity_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_12_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_72_1)
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

  switch (quotient_72_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_12_1 == parity_12_2);
  assert(quotient_72_1 == quotient_72_2);
}

int fn_R000637_3713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int parity_12 = local_arr[aux % 3];
  acc = (acc + (parity_12 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_72 = (aux + st.buffer[1]) & 3;
  switch (quotient_72)
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

void fn_R000637_3713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000637_3713_2 st_1 = {0};
  struct Vector3D_R000637_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int parity_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_99_1) & 63;
  aux_2 = (aux_2 + parity_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_93_1)
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

  switch (delta_93_2)
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
  int coefficient_47_1 = local_arr_1[aux_1 % 3];
  int coefficient_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_47_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_99_1 == parity_99_2);
  assert(delta_93_1 == delta_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_47_1 == coefficient_47_2);
}

int fn_R000637_3713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000637_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int parity_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_99) & 63;
  acc ^= aux;
  int delta_93 = (aux + st.buffer[1]) & 3;
  switch (delta_93)
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
  int coefficient_47 = local_arr[aux % 3];
  acc = (acc + (coefficient_47 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000637_3713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000637_3713_0 st_1 = {0};
  struct CipherContext_R000637_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int phase_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_68_1 > 23)
  {
    acc_1 = ((acc_1 + (phase_68_1 * 2)) + 5) & 127;
    aux_1 ^= phase_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_68_2 > 23)
  {
    acc_2 = ((acc_2 + (phase_68_2 * 2)) + 5) & 127;
    aux_2 ^= phase_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_68_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_68_1)
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

  switch (tracker_68_2)
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
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_68_1 == phase_68_2);
  assert(tracker_68_1 == tracker_68_2);
}

int fn_R000637_3713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000637_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int phase_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_68 > 23)
  {
    acc = ((acc + (phase_68 * 2)) + 5) & 127;
    aux ^= phase_68 & 15;
  }
  else
  {
    acc = ((acc - phase_68) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_68 = (aux + st.buffer[1]) & 3;
  switch (tracker_68)
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

void fn_R000637_3713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000637_3713_0 st_1 = {0};
  struct CipherContext_R000637_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int tally_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_29_1) & 63;
  aux_2 = (aux_2 + tally_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_29_1 == tally_29_2);
}

int fn_R000637_3713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000637_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int tally_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_29) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000637_3713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000637_3713_2 st_1 = {0};
  struct Vector3D_R000637_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int checksum_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_63_1)
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

  switch (checksum_63_2)
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

  int damping_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_94_1) & 63;
  aux_2 = (aux_2 + damping_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_63_1 == checksum_63_2);
  assert(damping_94_1 == damping_94_2);
}

int fn_R000637_3713_12(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000637_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int checksum_63 = (aux + st.buffer[1]) & 3;
  switch (checksum_63)
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

  int damping_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_94) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000637_3713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st_1 = {0};
  struct DeviceConfig_R000637_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int weight_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_65_1 > 14)
  {
    acc_1 = ((acc_1 + (weight_65_1 * 2)) + 5) & 127;
    aux_1 ^= weight_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_65_2 > 14)
  {
    acc_2 = ((acc_2 + (weight_65_2 * 2)) + 5) & 127;
    aux_2 ^= weight_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_31_1) & 63;
  aux_2 = (aux_2 + metric_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_72_1 = local_arr_1[aux_1 % 3];
  int threshold_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_72_2 * 2)) & 127;
  int segment_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_25_1)
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

  switch (segment_25_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_65_1 == weight_65_2);
  assert(metric_31_1 == metric_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_72_1 == threshold_72_2);
  assert(segment_25_1 == segment_25_2);
}

int fn_R000637_3713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int weight_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_65 > 14)
  {
    acc = ((acc + (weight_65 * 2)) + 5) & 127;
    aux ^= weight_65 & 15;
  }
  else
  {
    acc = ((acc - weight_65) + 11) & 127;
    aux += 3;
  }
  int metric_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_31) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int threshold_72 = local_arr[aux % 3];
  acc = (acc + (threshold_72 * 2)) & 127;
  int segment_25 = (aux + st.buffer[1]) & 3;
  switch (segment_25)
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

void fn_R000637_3713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st_1 = {0};
  struct DeviceConfig_R000637_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int bound_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_31_1)
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

  switch (bound_31_2)
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

  int parity_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_44_1 > 41)
  {
    acc_1 = ((acc_1 + (parity_44_1 * 2)) + 5) & 127;
    aux_1 ^= parity_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_44_2 > 41)
  {
    acc_2 = ((acc_2 + (parity_44_2 * 2)) + 5) & 127;
    aux_2 ^= parity_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_44_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_31_1 == bound_31_2);
  assert(parity_44_1 == parity_44_2);
}

int fn_R000637_3713_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int bound_31 = (aux + st.buffer[1]) & 3;
  switch (bound_31)
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

  int parity_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_44 > 41)
  {
    acc = ((acc + (parity_44 * 2)) + 5) & 127;
    aux ^= parity_44 & 15;
  }
  else
  {
    acc = ((acc - parity_44) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000637_3713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000637_3713_0 st_1 = {0};
  struct CipherContext_R000637_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int damping_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_25_1)
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

  switch (damping_25_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_39_1 > 37)
  {
    acc_1 = ((acc_1 + (checksum_39_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_39_2 > 37)
  {
    acc_2 = ((acc_2 + (checksum_39_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_25_1 == damping_25_2);
  assert(checksum_39_1 == checksum_39_2);
}

int fn_R000637_3713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000637_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int damping_25 = (aux + st.buffer[1]) & 3;
  switch (damping_25)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_39 > 37)
  {
    acc = ((acc + (checksum_39 * 2)) + 5) & 127;
    aux ^= checksum_39 & 15;
  }
  else
  {
    acc = ((acc - checksum_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000637_3713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st_1 = {0};
  struct DeviceConfig_R000637_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int offset_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_69_1)
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

  switch (offset_69_2)
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
  int accumulator_55_1 = local_arr_1[aux_1 % 3];
  int accumulator_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_55_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_69_1 == offset_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_55_1 == accumulator_55_2);
}

int fn_R000637_3713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int offset_69 = (aux + st.buffer[1]) & 3;
  switch (offset_69)
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
  int accumulator_55 = local_arr[aux % 3];
  acc = (acc + (accumulator_55 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000637_3713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000637_3713_0 st_1 = {0};
  struct CipherContext_R000637_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int cursor_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_46_1)
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

  switch (cursor_46_2)
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

  int tracker_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_96_1 > 38)
  {
    acc_1 = ((acc_1 + (tracker_96_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_96_2 > 38)
  {
    acc_2 = ((acc_2 + (tracker_96_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_96_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_59_1) & 63;
  aux_2 = (aux_2 + residue_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_46_1 == cursor_46_2);
  assert(tracker_96_1 == tracker_96_2);
  assert(residue_59_1 == residue_59_2);
}

int fn_R000637_3713_17(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000637_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int cursor_46 = (aux + st.buffer[1]) & 3;
  switch (cursor_46)
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

  int tracker_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_96 > 38)
  {
    acc = ((acc + (tracker_96 * 2)) + 5) & 127;
    aux ^= tracker_96 & 15;
  }
  else
  {
    acc = ((acc - tracker_96) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_59) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000637_3713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000637_3713_2 st_1 = {0};
  struct Vector3D_R000637_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_14_1 = local_arr_1[aux_1 % 3];
  int phase_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_14_2 * 2)) & 127;
  int tally_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_52_1) & 63;
  aux_2 = (aux_2 + tally_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_58_1 > 46)
  {
    acc_1 = ((acc_1 + (offset_58_1 * 2)) + 5) & 127;
    aux_1 ^= offset_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_58_2 > 46)
  {
    acc_2 = ((acc_2 + (offset_58_2 * 2)) + 5) & 127;
    aux_2 ^= offset_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_58_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_25_1)
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

  switch (offset_25_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_14_1 == phase_14_2);
  assert(tally_52_1 == tally_52_2);
  assert(offset_58_1 == offset_58_2);
  assert(offset_25_1 == offset_25_2);
}

int fn_R000637_3713_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000637_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int phase_14 = local_arr[aux % 3];
  acc = (acc + (phase_14 * 2)) & 127;
  int tally_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_52) & 63;
  acc ^= aux;
  int offset_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_58 > 46)
  {
    acc = ((acc + (offset_58 * 2)) + 5) & 127;
    aux ^= offset_58 & 15;
  }
  else
  {
    acc = ((acc - offset_58) + 11) & 127;
    aux += 3;
  }
  int offset_25 = (aux + st.buffer[1]) & 3;
  switch (offset_25)
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

void fn_R000637_3713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st_1 = {0};
  struct DeviceConfig_R000637_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int threshold_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_17_1)
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

  switch (threshold_17_2)
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
  int residue_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_83_1 > 15)
  {
    acc_1 = ((acc_1 + (residue_83_1 * 2)) + 5) & 127;
    aux_1 ^= residue_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_83_2 > 15)
  {
    acc_2 = ((acc_2 + (residue_83_2 * 2)) + 5) & 127;
    aux_2 ^= residue_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_17_1 == threshold_17_2);
  assert(residue_83_1 == residue_83_2);
}

int fn_R000637_3713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000637_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int threshold_17 = (aux + st.buffer[1]) & 3;
  switch (threshold_17)
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
  int residue_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_83 > 15)
  {
    acc = ((acc + (residue_83 * 2)) + 5) & 127;
    aux ^= residue_83 & 15;
  }
  else
  {
    acc = ((acc - residue_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000637_0_1;
  int sec_r000637_0_2;
  int sec_r000637_1_1;
  int sec_r000637_1_2;
  int sec_r000637_2_1;
  int sec_r000637_2_2;
  int sec_r000637_3_1;
  int sec_r000637_3_2;
  int sec_r000637_4_1;
  int sec_r000637_4_2;
  int sec_r000637_5_1;
  int sec_r000637_5_2;
  int sec_r000637_6_1;
  int sec_r000637_6_2;
  int sec_r000637_7_1;
  int sec_r000637_7_2;
  int sec_r000637_8_1;
  int sec_r000637_8_2;
  int sec_r000637_9_1;
  int sec_r000637_9_2;
  int sec_r000637_10_1;
  int sec_r000637_10_2;
  int sec_r000637_11_1;
  int sec_r000637_11_2;
  int sec_r000637_12_1;
  int sec_r000637_12_2;
  int sec_r000637_13_1;
  int sec_r000637_13_2;
  int sec_r000637_14_1;
  int sec_r000637_14_2;
  int sec_r000637_15_1;
  int sec_r000637_15_2;
  int sec_r000637_16_1;
  int sec_r000637_16_2;
  int sec_r000637_17_1;
  int sec_r000637_17_2;
  int sec_r000637_18_1;
  int sec_r000637_18_2;
  int pub_r000637_0_1;
  int pub_r000637_0_2;
  int pub_r000637_1_1;
  int pub_r000637_1_2;
  int pub_r000637_2_1;
  int pub_r000637_2_2;
  int pub_r000637_3_1;
  int pub_r000637_3_2;
  int pub_r000637_4_1;
  int pub_r000637_4_2;
  int pub_r000637_5_1;
  int pub_r000637_5_2;
  int pub_r000637_6_1;
  int pub_r000637_6_2;
  int pub_r000637_7_1;
  int pub_r000637_7_2;
  int pub_r000637_8_1;
  int pub_r000637_8_2;
  int pub_r000637_9_1;
  int pub_r000637_9_2;
  int pub_r000637_10_1;
  int pub_r000637_10_2;
  int pub_r000637_11_1;
  int pub_r000637_11_2;
  int pub_r000637_12_1;
  int pub_r000637_12_2;
  int pub_r000637_13_1;
  int pub_r000637_13_2;
  int pub_r000637_14_1;
  int pub_r000637_14_2;
  int pub_r000637_15_1;
  int pub_r000637_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000637_0_1 >= (-100)) && (pub_r000637_0_1 <= 100));
  __CPROVER_assume((pub_r000637_0_2 >= (-100)) && (pub_r000637_0_2 <= 100));
  __CPROVER_assume((pub_r000637_1_1 >= (-100)) && (pub_r000637_1_1 <= 100));
  __CPROVER_assume((pub_r000637_1_2 >= (-100)) && (pub_r000637_1_2 <= 100));
  __CPROVER_assume((pub_r000637_2_1 >= (-100)) && (pub_r000637_2_1 <= 100));
  __CPROVER_assume((pub_r000637_2_2 >= (-100)) && (pub_r000637_2_2 <= 100));
  __CPROVER_assume((pub_r000637_3_1 >= (-100)) && (pub_r000637_3_1 <= 100));
  __CPROVER_assume((pub_r000637_3_2 >= (-100)) && (pub_r000637_3_2 <= 100));
  __CPROVER_assume((pub_r000637_4_1 >= (-100)) && (pub_r000637_4_1 <= 100));
  __CPROVER_assume((pub_r000637_4_2 >= (-100)) && (pub_r000637_4_2 <= 100));
  __CPROVER_assume((pub_r000637_5_1 >= (-100)) && (pub_r000637_5_1 <= 100));
  __CPROVER_assume((pub_r000637_5_2 >= (-100)) && (pub_r000637_5_2 <= 100));
  __CPROVER_assume((pub_r000637_6_1 >= (-100)) && (pub_r000637_6_1 <= 100));
  __CPROVER_assume((pub_r000637_6_2 >= (-100)) && (pub_r000637_6_2 <= 100));
  __CPROVER_assume((pub_r000637_7_1 >= (-100)) && (pub_r000637_7_1 <= 100));
  __CPROVER_assume((pub_r000637_7_2 >= (-100)) && (pub_r000637_7_2 <= 100));
  __CPROVER_assume((pub_r000637_8_1 >= (-100)) && (pub_r000637_8_1 <= 100));
  __CPROVER_assume((pub_r000637_8_2 >= (-100)) && (pub_r000637_8_2 <= 100));
  __CPROVER_assume((pub_r000637_9_1 >= (-100)) && (pub_r000637_9_1 <= 100));
  __CPROVER_assume((pub_r000637_9_2 >= (-100)) && (pub_r000637_9_2 <= 100));
  __CPROVER_assume((pub_r000637_10_1 >= (-100)) && (pub_r000637_10_1 <= 100));
  __CPROVER_assume((pub_r000637_10_2 >= (-100)) && (pub_r000637_10_2 <= 100));
  __CPROVER_assume((pub_r000637_11_1 >= (-100)) && (pub_r000637_11_1 <= 100));
  __CPROVER_assume((pub_r000637_11_2 >= (-100)) && (pub_r000637_11_2 <= 100));
  __CPROVER_assume((pub_r000637_12_1 >= (-100)) && (pub_r000637_12_1 <= 100));
  __CPROVER_assume((pub_r000637_12_2 >= (-100)) && (pub_r000637_12_2 <= 100));
  __CPROVER_assume((pub_r000637_13_1 >= (-100)) && (pub_r000637_13_1 <= 100));
  __CPROVER_assume((pub_r000637_13_2 >= (-100)) && (pub_r000637_13_2 <= 100));
  __CPROVER_assume((pub_r000637_14_1 >= (-100)) && (pub_r000637_14_1 <= 100));
  __CPROVER_assume((pub_r000637_14_2 >= (-100)) && (pub_r000637_14_2 <= 100));
  __CPROVER_assume((pub_r000637_15_1 >= (-100)) && (pub_r000637_15_1 <= 100));
  __CPROVER_assume((pub_r000637_15_2 >= (-100)) && (pub_r000637_15_2 <= 100));
  __CPROVER_assume((sec_r000637_0_1 >= 0) && (sec_r000637_0_1 <= 255));
  __CPROVER_assume((sec_r000637_0_2 >= 0) && (sec_r000637_0_2 <= 255));
  __CPROVER_assume((sec_r000637_1_1 >= 0) && (sec_r000637_1_1 <= 255));
  __CPROVER_assume((sec_r000637_1_2 >= 0) && (sec_r000637_1_2 <= 255));
  __CPROVER_assume((sec_r000637_2_1 >= 0) && (sec_r000637_2_1 <= 255));
  __CPROVER_assume((sec_r000637_2_2 >= 0) && (sec_r000637_2_2 <= 255));
  __CPROVER_assume((sec_r000637_3_1 >= 0) && (sec_r000637_3_1 <= 255));
  __CPROVER_assume((sec_r000637_3_2 >= 0) && (sec_r000637_3_2 <= 255));
  __CPROVER_assume((sec_r000637_4_1 >= 0) && (sec_r000637_4_1 <= 255));
  __CPROVER_assume((sec_r000637_4_2 >= 0) && (sec_r000637_4_2 <= 255));
  __CPROVER_assume((sec_r000637_5_1 >= 0) && (sec_r000637_5_1 <= 255));
  __CPROVER_assume((sec_r000637_5_2 >= 0) && (sec_r000637_5_2 <= 255));
  __CPROVER_assume((sec_r000637_6_1 >= 0) && (sec_r000637_6_1 <= 255));
  __CPROVER_assume((sec_r000637_6_2 >= 0) && (sec_r000637_6_2 <= 255));
  __CPROVER_assume((sec_r000637_7_1 >= 0) && (sec_r000637_7_1 <= 255));
  __CPROVER_assume((sec_r000637_7_2 >= 0) && (sec_r000637_7_2 <= 255));
  __CPROVER_assume((sec_r000637_8_1 >= 0) && (sec_r000637_8_1 <= 255));
  __CPROVER_assume((sec_r000637_8_2 >= 0) && (sec_r000637_8_2 <= 255));
  __CPROVER_assume((sec_r000637_9_1 >= 0) && (sec_r000637_9_1 <= 255));
  __CPROVER_assume((sec_r000637_9_2 >= 0) && (sec_r000637_9_2 <= 255));
  __CPROVER_assume((sec_r000637_10_1 >= 0) && (sec_r000637_10_1 <= 255));
  __CPROVER_assume((sec_r000637_10_2 >= 0) && (sec_r000637_10_2 <= 255));
  __CPROVER_assume((sec_r000637_11_1 >= 0) && (sec_r000637_11_1 <= 255));
  __CPROVER_assume((sec_r000637_11_2 >= 0) && (sec_r000637_11_2 <= 255));
  __CPROVER_assume((sec_r000637_12_1 >= 0) && (sec_r000637_12_1 <= 255));
  __CPROVER_assume((sec_r000637_12_2 >= 0) && (sec_r000637_12_2 <= 255));
  __CPROVER_assume((sec_r000637_13_1 >= 0) && (sec_r000637_13_1 <= 255));
  __CPROVER_assume((sec_r000637_13_2 >= 0) && (sec_r000637_13_2 <= 255));
  __CPROVER_assume((sec_r000637_14_1 >= 0) && (sec_r000637_14_1 <= 255));
  __CPROVER_assume((sec_r000637_14_2 >= 0) && (sec_r000637_14_2 <= 255));
  __CPROVER_assume((sec_r000637_15_1 >= 0) && (sec_r000637_15_1 <= 255));
  __CPROVER_assume((sec_r000637_15_2 >= 0) && (sec_r000637_15_2 <= 255));
  __CPROVER_assume((sec_r000637_16_1 >= 0) && (sec_r000637_16_1 <= 255));
  __CPROVER_assume((sec_r000637_16_2 >= 0) && (sec_r000637_16_2 <= 255));
  __CPROVER_assume((sec_r000637_17_1 >= 0) && (sec_r000637_17_1 <= 255));
  __CPROVER_assume((sec_r000637_17_2 >= 0) && (sec_r000637_17_2 <= 255));
  __CPROVER_assume((sec_r000637_18_1 >= 0) && (sec_r000637_18_1 <= 255));
  __CPROVER_assume((sec_r000637_18_2 >= 0) && (sec_r000637_18_2 <= 255));
  struct CipherContext_R000637_3713_0 st_var_0_1 = {0};
  struct CipherContext_R000637_3713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000637_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000637_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000637_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000637_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000637_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000637_0_2 + 7) & 15;
  struct DeviceConfig_R000637_3713_1 st_var_1_1 = {0};
  struct DeviceConfig_R000637_3713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000637_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000637_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000637_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000637_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000637_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000637_0_2 + 9) & 15;
  struct Vector3D_R000637_3713_2 st_var_2_1 = {0};
  struct Vector3D_R000637_3713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000637_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000637_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000637_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000637_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000637_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000637_0_2 + 11) & 15;
  union TelemetryField_R000637_3713_0 u_var_1;
  union TelemetryField_R000637_3713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 34)
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
  if (stage_v_1_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 34)
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
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 4) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = (st_var_1_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_1_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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

  int stage_v_5_1 = (st_var_2_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_2_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = ((st_var_0_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_0_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 53)
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
  if (stage_v_6_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 53)
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
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  if (stage_v_9_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 45)
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
  if (stage_v_9_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 45)
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
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (20 & 31);
  int stage_v_15_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (20 & 31);
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= (stage_v_15_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_15_2 << 1) & 127;
  int stage_v_16_1 = (st_var_1_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_1_2.buffer[0] ^ 19) & 3;
  switch (stage_v_16_1)
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

  switch (stage_v_16_2)
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

  int stage_v_17_1 = (st_var_2_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_2_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = (st_var_2_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_2_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (st_var_0_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_0_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
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

  switch (stage_v_27_2)
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

  int stage_v_28_1 = (st_var_1_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_1_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 31) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = table_1[3];
  int stage_v_31_2 = table_2[3];
  table_1[3] = (table_1[0] + 63) & 63;
  table_2[3] = (table_2[0] + 63) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 34) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 35) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 36) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= stage_v_35_1;
  chk_sum_2 ^= stage_v_35_2;
  int stage_v_36_1 = table_1[0];
  int stage_v_36_2 = table_2[0];
  table_1[0] = (table_1[1] + 73) & 63;
  table_2[0] = (table_2[1] + 73) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_37_1 = ((stage_v_37_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_37_2 = ((stage_v_37_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((st_var_2_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_2_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 30)
    {
      chk_sum_1 ^= stage_v_38_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_38_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 30)
    {
      chk_sum_2 ^= stage_v_38_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_39_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_39_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_40_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (45 & 31);
  int stage_v_40_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (45 & 31);
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= (stage_v_40_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_40_2 << 1) & 127;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_41_1 = ((stage_v_41_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_41_2 = ((stage_v_41_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (47 & 31);
  int stage_v_42_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (47 & 31);
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= (stage_v_42_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_42_2 << 1) & 127;
  int stage_v_43_1 = (st_var_1_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_1_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
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

  switch (stage_v_43_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 45) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 45) & 15;
  int stage_v_44_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_44_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= stage_v_44_1;
  chk_sum_2 ^= stage_v_44_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 46) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = (st_var_1_1.buffer[0] ^ 49) & 3;
  int stage_v_46_2 = (st_var_1_2.buffer[0] ^ 49) & 3;
  switch (stage_v_46_1)
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

  switch (stage_v_46_2)
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

  int stage_v_47_1 = (st_var_2_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_2_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
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

  switch (stage_v_47_2)
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

  int stage_v_48_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_48_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 50) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 50) & 15;
  int stage_v_49_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_49_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= stage_v_49_1;
  chk_sum_2 ^= stage_v_49_2;
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
  int stage_v_51_1 = ((st_var_0_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_0_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 53)
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
  if (stage_v_51_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 53)
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
  int stage_v_52_1 = ((st_var_1_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_1_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 36)
    {
      chk_sum_1 ^= stage_v_52_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_52_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 36)
    {
      chk_sum_2 ^= stage_v_52_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 54) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 54) & 15;
  int stage_v_53_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_53_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= stage_v_53_1;
  chk_sum_2 ^= stage_v_53_2;
  int stage_v_54_1 = ((st_var_0_1.buffer[0] * 2) + 169) & 63;
  int stage_v_54_2 = ((st_var_0_2.buffer[0] * 2) + 169) & 63;
  if (stage_v_54_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_54_1) - 5) & 255;
    if (stage_v_54_1 > 43)
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
  if (stage_v_54_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_54_2) - 5) & 255;
    if (stage_v_54_2 > 43)
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
  int stage_v_55_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_55_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_56_1 = ((st_var_2_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_2_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 32)
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
  if (stage_v_56_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 32)
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
  int stage_v_57_1 = ((st_var_0_1.buffer[0] * 2) + 178) & 63;
  int stage_v_57_2 = ((st_var_0_2.buffer[0] * 2) + 178) & 63;
  if (stage_v_57_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_57_1) - 5) & 255;
    if (stage_v_57_1 > 51)
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
  if (stage_v_57_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_57_2) - 5) & 255;
    if (stage_v_57_2 > 51)
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
  int stage_v_58_1 = table_1[2];
  int stage_v_58_2 = table_2[2];
  table_1[2] = (table_1[3] + 117) & 63;
  table_2[2] = (table_2[3] + 117) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_59_1 = ((stage_v_59_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_59_2 = ((stage_v_59_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (65 & 31);
  int stage_v_60_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (65 & 31);
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= (stage_v_60_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_60_2 << 1) & 127;
  int stage_v_61_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_61_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_62_1 = (st_var_2_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_2_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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
  int stage_v_65_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (70 & 31);
  int stage_v_65_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (70 & 31);
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= (stage_v_65_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_65_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 67) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 67) & 15;
  int stage_v_66_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_66_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= stage_v_66_1;
  chk_sum_2 ^= stage_v_66_2;
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
  int stage_v_68_1 = table_1[0];
  int stage_v_68_2 = table_2[0];
  table_1[0] = (table_1[1] + 137) & 63;
  table_2[0] = (table_2[1] + 137) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 70) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 70) & 15;
  int stage_v_69_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_69_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= stage_v_69_1;
  chk_sum_2 ^= stage_v_69_2;
  int stage_v_70_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_70_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_71_1 = ((st_var_2_1.buffer[2] * 2) + 220) & 63;
  int stage_v_71_2 = ((st_var_2_2.buffer[2] * 2) + 220) & 63;
  if (stage_v_71_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_71_1) - 5) & 255;
    if (stage_v_71_1 > 51)
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
  if (stage_v_71_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_71_2) - 5) & 255;
    if (stage_v_71_2 > 51)
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
  int stage_v_72_1 = (st_var_0_1.buffer[0] ^ 75) & 3;
  int stage_v_72_2 = (st_var_0_2.buffer[0] ^ 75) & 3;
  switch (stage_v_72_1)
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

  switch (stage_v_72_2)
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

  int stage_v_73_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_73_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000637_14_1 & 1) != 0)
  {
    if ((sec_r000637_1_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000637_1_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000637_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000637_1_1 + 7) & 127;
  }
  if ((sec_r000637_14_2 & 1) != 0)
  {
    if ((sec_r000637_1_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000637_1_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000637_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000637_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000637_8_1 & 1) != 0)
  {
    if ((sec_r000637_10_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000637_6_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000637_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000637_6_1 + 7) & 127;
  }
  if ((sec_r000637_8_2 & 1) != 0)
  {
    if ((sec_r000637_10_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000637_6_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000637_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000637_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000637_6_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000637_4_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000637_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000637_4_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000637_6_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000637_4_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000637_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000637_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000637_15_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000637_0_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000637_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000637_0_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000637_15_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000637_0_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000637_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000637_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000637_13_1 & 1) != 0)
  {
    if ((sec_r000637_5_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000637_10_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000637_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000637_10_1 + 7) & 127;
  }
  if ((sec_r000637_13_2 & 1) != 0)
  {
    if ((sec_r000637_5_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000637_10_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000637_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000637_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000637_9_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000637_10_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000637_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000637_10_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000637_9_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000637_10_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000637_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000637_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000637_2_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000637_6_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000637_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000637_6_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000637_2_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000637_6_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000637_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000637_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000637_1_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000637_4_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000637_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000637_4_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000637_1_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000637_4_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000637_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000637_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000637_11_1 & 1) != 0)
  {
    if ((sec_r000637_2_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000637_0_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000637_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000637_0_1 + 7) & 127;
  }
  if ((sec_r000637_11_2 & 1) != 0)
  {
    if ((sec_r000637_2_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000637_0_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000637_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000637_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000637_8_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000637_12_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000637_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000637_12_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000637_8_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000637_12_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000637_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000637_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000637_17_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000637_15_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000637_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000637_15_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000637_17_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000637_15_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000637_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000637_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000637_9_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000637_1_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000637_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000637_1_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000637_9_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000637_1_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000637_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000637_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000637_13_1 & 1) != 0)
  {
    if ((sec_r000637_16_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000637_14_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000637_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000637_14_1 + 7) & 127;
  }
  if ((sec_r000637_13_2 & 1) != 0)
  {
    if ((sec_r000637_16_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000637_14_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000637_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000637_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((sec_r000637_0_1 & 1) != 0)
  {
    if ((sec_r000637_10_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000637_6_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000637_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000637_6_1 + 7) & 127;
  }
  if ((sec_r000637_0_2 & 1) != 0)
  {
    if ((sec_r000637_10_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000637_6_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000637_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000637_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000637_8_1 & 1) != 0)
  {
    if ((sec_r000637_4_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000637_14_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000637_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000637_14_1 + 7) & 127;
  }
  if ((sec_r000637_8_2 & 1) != 0)
  {
    if ((sec_r000637_4_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000637_14_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000637_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000637_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000637_3_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000637_8_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000637_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000637_8_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000637_3_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000637_8_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000637_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000637_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000637_4_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000637_10_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000637_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000637_10_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000637_4_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000637_10_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000637_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000637_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000637_15_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000637_11_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000637_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000637_11_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000637_15_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000637_11_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000637_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000637_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000637_9_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000637_15_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000637_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000637_15_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000637_9_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000637_15_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000637_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000637_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000637_5_1 & 1) != 0)
  {
    if ((sec_r000637_7_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000637_1_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000637_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000637_1_1 + 7) & 127;
  }
  if ((sec_r000637_5_2 & 1) != 0)
  {
    if ((sec_r000637_7_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000637_1_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000637_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000637_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000637_16_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000637_6_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000637_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000637_6_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000637_16_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000637_6_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000637_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000637_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000637_10_1 & 1) != 0)
  {
    if ((sec_r000637_8_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000637_15_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000637_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000637_15_1 + 7) & 127;
  }
  if ((sec_r000637_10_2 & 1) != 0)
  {
    if ((sec_r000637_8_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000637_15_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000637_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000637_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000637_7_1 & 1) != 0)
  {
    if ((sec_r000637_4_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000637_6_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000637_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000637_6_1 + 7) & 127;
  }
  if ((sec_r000637_7_2 & 1) != 0)
  {
    if ((sec_r000637_4_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000637_6_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000637_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000637_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000637_11_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000637_2_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000637_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000637_2_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000637_11_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000637_2_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000637_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000637_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000637_15_1 & 1) != 0)
  {
    if ((sec_r000637_1_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000637_15_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000637_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000637_15_1 + 7) & 127;
  }
  if ((sec_r000637_15_2 & 1) != 0)
  {
    if ((sec_r000637_1_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000637_15_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000637_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000637_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000637_6_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000637_12_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000637_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000637_12_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000637_6_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000637_12_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000637_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000637_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000637_0_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000637_10_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000637_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000637_10_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000637_0_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000637_10_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000637_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000637_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000637_9_1 & 1) != 0)
  {
    if ((sec_r000637_12_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000637_15_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000637_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000637_15_1 + 7) & 127;
  }
  if ((sec_r000637_9_2 & 1) != 0)
  {
    if ((sec_r000637_12_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000637_15_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000637_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000637_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000637_18_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000637_8_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000637_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000637_8_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000637_18_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000637_8_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000637_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000637_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000637_2_1 & 1) != 0)
  {
    if ((sec_r000637_9_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000637_7_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000637_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000637_7_1 + 7) & 127;
  }
  if ((sec_r000637_2_2 & 1) != 0)
  {
    if ((sec_r000637_9_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000637_7_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000637_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000637_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000637_0_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000637_13_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000637_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000637_13_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000637_0_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000637_13_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000637_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000637_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000637_1_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000637_12_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000637_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000637_12_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000637_1_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000637_12_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000637_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000637_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000637_11_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000637_9_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000637_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000637_9_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000637_11_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000637_9_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000637_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000637_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000637_16_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000637_6_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000637_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000637_6_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000637_16_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000637_6_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000637_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000637_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000637_17_1 & 1) != 0)
  {
    if ((sec_r000637_2_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000637_12_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000637_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000637_12_1 + 7) & 127;
  }
  if ((sec_r000637_17_2 & 1) != 0)
  {
    if ((sec_r000637_2_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000637_12_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000637_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000637_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000637_18_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000637_8_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000637_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000637_8_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000637_18_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000637_8_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000637_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000637_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000637_3_1 & 1) != 0)
  {
    if ((sec_r000637_6_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000637_9_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000637_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000637_9_1 + 7) & 127;
  }
  if ((sec_r000637_3_2 & 1) != 0)
  {
    if ((sec_r000637_6_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000637_9_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000637_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000637_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000637_11_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000637_8_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000637_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000637_8_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000637_11_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000637_8_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000637_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000637_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000637_1_1 & 1) != 0)
  {
    if ((sec_r000637_17_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000637_15_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000637_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000637_15_1 + 7) & 127;
  }
  if ((sec_r000637_1_2 & 1) != 0)
  {
    if ((sec_r000637_17_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000637_15_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000637_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000637_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000637_15_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000637_1_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000637_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000637_1_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000637_15_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000637_1_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000637_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000637_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000637_6_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000637_13_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000637_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000637_13_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000637_6_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000637_13_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000637_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000637_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000637_6_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000637_12_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000637_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000637_12_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000637_6_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000637_12_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000637_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000637_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000637_16_1 & 1) != 0)
  {
    if ((sec_r000637_0_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000637_0_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000637_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000637_0_1 + 7) & 127;
  }
  if ((sec_r000637_16_2 & 1) != 0)
  {
    if ((sec_r000637_0_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000637_0_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000637_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000637_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000637_7_1 & 1) != 0)
  {
    if ((sec_r000637_8_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000637_10_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000637_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000637_10_1 + 7) & 127;
  }
  if ((sec_r000637_7_2 & 1) != 0)
  {
    if ((sec_r000637_8_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000637_10_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000637_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000637_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000637_18_1 & 1) != 0)
  {
    if ((sec_r000637_13_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000637_15_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000637_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000637_15_1 + 7) & 127;
  }
  if ((sec_r000637_18_2 & 1) != 0)
  {
    if ((sec_r000637_13_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000637_15_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000637_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000637_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000637_8_1 & 1) != 0)
  {
    if ((sec_r000637_3_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000637_14_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000637_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000637_14_1 + 7) & 127;
  }
  if ((sec_r000637_8_2 & 1) != 0)
  {
    if ((sec_r000637_3_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000637_14_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000637_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000637_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000637_16_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000637_13_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000637_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000637_13_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000637_16_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000637_13_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000637_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000637_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000637_2_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000637_15_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000637_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000637_15_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000637_2_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000637_15_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000637_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000637_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000637_15_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000637_7_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000637_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000637_7_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000637_15_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000637_7_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000637_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000637_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000637_2_1 & 1) != 0)
  {
    if ((sec_r000637_2_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000637_14_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000637_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000637_14_1 + 7) & 127;
  }
  if ((sec_r000637_2_2 & 1) != 0)
  {
    if ((sec_r000637_2_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000637_14_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000637_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000637_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000637_3_1 & 1) != 0)
  {
    if ((sec_r000637_1_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000637_1_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000637_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000637_1_1 + 7) & 127;
  }
  if ((sec_r000637_3_2 & 1) != 0)
  {
    if ((sec_r000637_1_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000637_1_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000637_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000637_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000637_10_1 & 1) != 0)
  {
    if ((sec_r000637_9_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000637_7_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000637_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000637_7_1 + 7) & 127;
  }
  if ((sec_r000637_10_2 & 1) != 0)
  {
    if ((sec_r000637_9_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000637_7_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000637_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000637_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r000637_18_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000637_11_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000637_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000637_11_1 + 7) & 127;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r000637_18_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000637_11_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000637_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000637_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000637_16_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000637_14_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000637_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000637_14_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000637_16_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000637_14_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000637_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000637_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000637_13_1 & 1) != 0)
  {
    if ((sec_r000637_0_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000637_9_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000637_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000637_9_1 + 7) & 127;
  }
  if ((sec_r000637_13_2 & 1) != 0)
  {
    if ((sec_r000637_0_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000637_9_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000637_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000637_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000637_4_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000637_13_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000637_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000637_13_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000637_4_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000637_13_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000637_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000637_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000637_16_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000637_4_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000637_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000637_4_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000637_16_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000637_4_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000637_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000637_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r000637_8_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000637_3_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000637_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000637_3_1 + 7) & 127;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r000637_8_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000637_3_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000637_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000637_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000637_11_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000637_10_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000637_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000637_10_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000637_11_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000637_10_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000637_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000637_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((sec_r000637_11_1 & 1) != 0)
  {
    if ((sec_r000637_16_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000637_13_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000637_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000637_13_1 + 7) & 127;
  }
  if ((sec_r000637_11_2 & 1) != 0)
  {
    if ((sec_r000637_16_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000637_13_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000637_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000637_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000637_18_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000637_4_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000637_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000637_4_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000637_18_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000637_4_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000637_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000637_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000637_17_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000637_4_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000637_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000637_4_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000637_17_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000637_4_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000637_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000637_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000637_10_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000637_3_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000637_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000637_3_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000637_10_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000637_3_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000637_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000637_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((sec_r000637_5_1 & 1) != 0)
  {
    if ((sec_r000637_5_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000637_5_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000637_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000637_5_1 + 7) & 127;
  }
  if ((sec_r000637_5_2 & 1) != 0)
  {
    if ((sec_r000637_5_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000637_5_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000637_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000637_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000637_15_1 & 1) != 0)
  {
    if ((sec_r000637_15_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000637_2_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000637_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000637_2_1 + 7) & 127;
  }
  if ((sec_r000637_15_2 & 1) != 0)
  {
    if ((sec_r000637_15_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000637_2_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000637_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000637_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000637_13_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000637_0_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000637_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000637_0_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000637_13_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000637_0_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000637_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000637_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000637_5_1 & 1) != 0)
  {
    if ((sec_r000637_5_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000637_3_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000637_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000637_3_1 + 7) & 127;
  }
  if ((sec_r000637_5_2 & 1) != 0)
  {
    if ((sec_r000637_5_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000637_3_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000637_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000637_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000637_15_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000637_12_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000637_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000637_12_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000637_15_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000637_12_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000637_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000637_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((sec_r000637_8_1 & 1) != 0)
  {
    if ((sec_r000637_13_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000637_6_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000637_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000637_6_1 + 7) & 127;
  }
  if ((sec_r000637_8_2 & 1) != 0)
  {
    if ((sec_r000637_13_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000637_6_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000637_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000637_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((sec_r000637_0_1 & 1) != 0)
  {
    if ((sec_r000637_7_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000637_13_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000637_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000637_13_1 + 7) & 127;
  }
  if ((sec_r000637_0_2 & 1) != 0)
  {
    if ((sec_r000637_7_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000637_13_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000637_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000637_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000637_0_1 != sec_r000637_0_2);
  __CPROVER_assume(sec_r000637_10_1 != sec_r000637_10_2);
  __CPROVER_assume(pub_r000637_15_1 == pub_r000637_15_2);
  __CPROVER_assume(sec_r000637_4_1 != sec_r000637_4_2);
  __CPROVER_assume(sec_r000637_2_1 != sec_r000637_2_2);
  __CPROVER_assume(pub_r000637_1_1 == pub_r000637_1_2);
  __CPROVER_assume(sec_r000637_3_1 != sec_r000637_3_2);
  __CPROVER_assume(sec_r000637_18_1 != sec_r000637_18_2);
  __CPROVER_assume(sec_r000637_7_1 != sec_r000637_7_2);
  __CPROVER_assume(sec_r000637_16_1 != sec_r000637_16_2);
  __CPROVER_assume(pub_r000637_7_1 == pub_r000637_7_2);
  __CPROVER_assume(sec_r000637_12_1 != sec_r000637_12_2);
  __CPROVER_assume(sec_r000637_8_1 != sec_r000637_8_2);
  __CPROVER_assume(pub_r000637_3_1 == pub_r000637_3_2);
  __CPROVER_assume(sec_r000637_5_1 != sec_r000637_5_2);
  __CPROVER_assume(pub_r000637_2_1 == pub_r000637_2_2);
  __CPROVER_assume(sec_r000637_1_1 != sec_r000637_1_2);
  __CPROVER_assume(pub_r000637_9_1 == pub_r000637_9_2);
  __CPROVER_assume(pub_r000637_4_1 == pub_r000637_4_2);
  __CPROVER_assume(sec_r000637_11_1 != sec_r000637_11_2);
  __CPROVER_assume(pub_r000637_5_1 == pub_r000637_5_2);
  __CPROVER_assume(sec_r000637_17_1 != sec_r000637_17_2);
  __CPROVER_assume(pub_r000637_6_1 == pub_r000637_6_2);
  __CPROVER_assume(pub_r000637_0_1 == pub_r000637_0_2);
  __CPROVER_assume(pub_r000637_8_1 == pub_r000637_8_2);
  __CPROVER_assume(pub_r000637_10_1 == pub_r000637_10_2);
  __CPROVER_assume(pub_r000637_14_1 == pub_r000637_14_2);
  __CPROVER_assume(sec_r000637_15_1 != sec_r000637_15_2);
  __CPROVER_assume(sec_r000637_9_1 != sec_r000637_9_2);
  __CPROVER_assume(sec_r000637_14_1 != sec_r000637_14_2);
  __CPROVER_assume(pub_r000637_12_1 == pub_r000637_12_2);
  __CPROVER_assume(pub_r000637_13_1 == pub_r000637_13_2);
  __CPROVER_assume(sec_r000637_13_1 != sec_r000637_13_2);
  __CPROVER_assume(pub_r000637_11_1 == pub_r000637_11_2);
  __CPROVER_assume(sec_r000637_6_1 != sec_r000637_6_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.pitch == st_var_2_2.pitch);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
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
}


