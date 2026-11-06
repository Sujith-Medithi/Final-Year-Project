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
struct SensorNode_R000317_1713_0
{
  unsigned char status;
  int threshold;
  unsigned char offset;
  unsigned char gain;
  int reading;
  int buffer[3];
};
struct FilterState_R000317_1713_1
{
  unsigned char mode;
  int prev_out;
  int gain_db;
  unsigned char cutoff;
  unsigned char prev_in;
  int buffer[3];
};
struct Vector3D_R000317_1713_2
{
  int heading;
  unsigned char coord_x;
  unsigned char pitch;
  short coord_y;
  int buffer[3];
};
struct CipherContext_R000317_1713_3
{
  short round_key;
  int iv;
  int tag;
  int flags;
  short counter;
  int buffer[3];
};
union TelemetryField_R000317_1713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000317_1713_1
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
void fn_R000317_1713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000317_1713_1 st_1 = {0};
  struct FilterState_R000317_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_56_1 = local_arr_1[aux_1 % 3];
  int offset_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_56_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_53_1)
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

  switch (offset_53_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_56_1 == offset_56_2);
  assert(offset_53_1 == offset_53_2);
}

int fn_R000317_1713_0(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000317_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int offset_56 = local_arr[aux % 3];
  acc = (acc + (offset_56 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_53 = (aux + st.buffer[1]) & 3;
  switch (offset_53)
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

void fn_R000317_1713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000317_1713_1 st_1 = {0};
  struct FilterState_R000317_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_56_1 = local_arr_1[aux_1 % 3];
  int checksum_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_56_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_10_1) & 63;
  aux_2 = (aux_2 + tally_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_39_1)
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

  switch (anchor_39_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_56_1 == checksum_56_2);
  assert(tally_10_1 == tally_10_2);
  assert(anchor_39_1 == anchor_39_2);
}

int fn_R000317_1713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000317_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int checksum_56 = local_arr[aux % 3];
  acc = (acc + (checksum_56 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_10) & 63;
  acc ^= aux;
  int anchor_39 = (aux + st.buffer[1]) & 3;
  switch (anchor_39)
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

void fn_R000317_1713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000317_1713_0 st_1 = {0};
  struct SensorNode_R000317_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_30_1) & 63;
  aux_2 = (aux_2 + metric_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_32_1)
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

  switch (delta_32_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_30_1 == metric_30_2);
  assert(delta_32_1 == delta_32_2);
}

int fn_R000317_1713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000317_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_30) & 63;
  acc ^= aux;
  int delta_32 = (aux + st.buffer[1]) & 3;
  switch (delta_32)
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

void fn_R000317_1713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000317_1713_3 st_1 = {0};
  struct CipherContext_R000317_1713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int coefficient_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_80_1) & 63;
  aux_2 = (aux_2 + coefficient_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_22_1)
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

  switch (weight_22_2)
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
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_80_1 == coefficient_80_2);
  assert(weight_22_1 == weight_22_2);
}

int fn_R000317_1713_3(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000317_1713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int coefficient_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_80) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_22 = (aux + st.buffer[1]) & 3;
  switch (weight_22)
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

void fn_R000317_1713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000317_1713_0 st_1 = {0};
  struct SensorNode_R000317_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_94_1) & 63;
  aux_2 = (aux_2 + accumulator_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_67_1 = local_arr_1[aux_1 % 3];
  int anchor_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_67_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_94_1 == accumulator_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_67_1 == anchor_67_2);
}

int fn_R000317_1713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000317_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_94) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_67 = local_arr[aux % 3];
  acc = (acc + (anchor_67 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000317_1713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000317_1713_2 st_1 = {0};
  struct Vector3D_R000317_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quantum_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_71_1) & 63;
  aux_2 = (aux_2 + quantum_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_74_1)
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

  switch (accumulator_74_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_58_1 = local_arr_1[aux_1 % 3];
  int scale_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_58_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_71_1 == quantum_71_2);
  assert(accumulator_74_1 == accumulator_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_58_1 == scale_58_2);
}

int fn_R000317_1713_5(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000317_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quantum_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_71) & 63;
  acc ^= aux;
  int accumulator_74 = (aux + st.buffer[1]) & 3;
  switch (accumulator_74)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_58 = local_arr[aux % 3];
  acc = (acc + (scale_58 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000317_1713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000317_1713_3 st_1 = {0};
  struct CipherContext_R000317_1713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int factor_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_55_1 > 12)
  {
    acc_1 = ((acc_1 + (factor_55_1 * 2)) + 5) & 127;
    aux_1 ^= factor_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_55_2 > 12)
  {
    acc_2 = ((acc_2 + (factor_55_2 * 2)) + 5) & 127;
    aux_2 ^= factor_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_49_1)
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

  switch (sample_49_2)
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

  int residue_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_27_1) & 63;
  aux_2 = (aux_2 + residue_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_55_1 == factor_55_2);
  assert(sample_49_1 == sample_49_2);
  assert(residue_27_1 == residue_27_2);
}

int fn_R000317_1713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000317_1713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int factor_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_55 > 12)
  {
    acc = ((acc + (factor_55 * 2)) + 5) & 127;
    aux ^= factor_55 & 15;
  }
  else
  {
    acc = ((acc - factor_55) + 11) & 127;
    aux += 3;
  }
  int sample_49 = (aux + st.buffer[1]) & 3;
  switch (sample_49)
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

  int residue_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_27) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000317_1713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000317_1713_0 st_1 = {0};
  struct SensorNode_R000317_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_43_1 = local_arr_1[aux_1 % 3];
  int checksum_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_43_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_43_1 == checksum_43_2);
}

int fn_R000317_1713_7(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000317_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int checksum_43 = local_arr[aux % 3];
  acc = (acc + (checksum_43 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000317_1713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000317_1713_3 st_1 = {0};
  struct CipherContext_R000317_1713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int parity_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_33_1)
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

  switch (parity_33_2)
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
  int margin_70_1 = local_arr_1[aux_1 % 3];
  int margin_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_70_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_33_1 == parity_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_70_1 == margin_70_2);
}

int fn_R000317_1713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000317_1713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int parity_33 = (aux + st.buffer[1]) & 3;
  switch (parity_33)
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
  int margin_70 = local_arr[aux % 3];
  acc = (acc + (margin_70 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000317_1713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000317_1713_1 st_1 = {0};
  struct FilterState_R000317_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int margin_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_91_1 > 14)
  {
    acc_1 = ((acc_1 + (margin_91_1 * 2)) + 5) & 127;
    aux_1 ^= margin_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_91_2 > 14)
  {
    acc_2 = ((acc_2 + (margin_91_2 * 2)) + 5) & 127;
    aux_2 ^= margin_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_70_1) & 63;
  aux_2 = (aux_2 + cursor_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_91_1 == margin_91_2);
  assert(cursor_70_1 == cursor_70_2);
}

int fn_R000317_1713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000317_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int margin_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_91 > 14)
  {
    acc = ((acc + (margin_91 * 2)) + 5) & 127;
    aux ^= margin_91 & 15;
  }
  else
  {
    acc = ((acc - margin_91) + 11) & 127;
    aux += 3;
  }
  int cursor_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_70) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000317_1713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000317_1713_0 st_1 = {0};
  struct SensorNode_R000317_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_45_1 = local_arr_1[aux_1 % 3];
  int factor_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_45_2 * 2)) & 127;
  int tally_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_86_1 > 20)
  {
    acc_1 = ((acc_1 + (tally_86_1 * 2)) + 5) & 127;
    aux_1 ^= tally_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_86_2 > 20)
  {
    acc_2 = ((acc_2 + (tally_86_2 * 2)) + 5) & 127;
    aux_2 ^= tally_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_80_1)
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

  switch (index_reg_80_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_45_1 == factor_45_2);
  assert(tally_86_1 == tally_86_2);
  assert(index_reg_80_1 == index_reg_80_2);
}

int fn_R000317_1713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000317_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int factor_45 = local_arr[aux % 3];
  acc = (acc + (factor_45 * 2)) & 127;
  int tally_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_86 > 20)
  {
    acc = ((acc + (tally_86 * 2)) + 5) & 127;
    aux ^= tally_86 & 15;
  }
  else
  {
    acc = ((acc - tally_86) + 11) & 127;
    aux += 3;
  }
  int index_reg_80 = (aux + st.buffer[1]) & 3;
  switch (index_reg_80)
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

void fn_R000317_1713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000317_1713_1 st_1 = {0};
  struct FilterState_R000317_1713_1 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_90_1 = local_arr_1[aux_1 % 3];
  int vector_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_90_1 == vector_90_2);
}

int fn_R000317_1713_11(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000317_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_90 = local_arr[aux % 3];
  acc = (acc + (vector_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000317_1713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000317_1713_3 st_1 = {0};
  struct CipherContext_R000317_1713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int sample_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_69_1 > 35)
  {
    acc_1 = ((acc_1 + (sample_69_1 * 2)) + 5) & 127;
    aux_1 ^= sample_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_69_2 > 35)
  {
    acc_2 = ((acc_2 + (sample_69_2 * 2)) + 5) & 127;
    aux_2 ^= sample_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_76_1 = local_arr_1[aux_1 % 3];
  int margin_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_76_2 * 2)) & 127;
  int scale_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_69_1) & 63;
  aux_2 = (aux_2 + scale_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_69_1 == sample_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_76_1 == margin_76_2);
  assert(scale_69_1 == scale_69_2);
}

int fn_R000317_1713_12(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000317_1713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int sample_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_69 > 35)
  {
    acc = ((acc + (sample_69 * 2)) + 5) & 127;
    aux ^= sample_69 & 15;
  }
  else
  {
    acc = ((acc - sample_69) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_76 = local_arr[aux % 3];
  acc = (acc + (margin_76 * 2)) & 127;
  int scale_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_69) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000317_1713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000317_1713_3 st_1 = {0};
  struct CipherContext_R000317_1713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int accumulator_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_93_1) & 63;
  aux_2 = (aux_2 + accumulator_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_98_1 > 33)
  {
    acc_1 = ((acc_1 + (segment_98_1 * 2)) + 5) & 127;
    aux_1 ^= segment_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_98_2 > 33)
  {
    acc_2 = ((acc_2 + (segment_98_2 * 2)) + 5) & 127;
    aux_2 ^= segment_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_93_1 == accumulator_93_2);
  assert(segment_98_1 == segment_98_2);
}

int fn_R000317_1713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000317_1713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int accumulator_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_93) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_98 > 33)
  {
    acc = ((acc + (segment_98 * 2)) + 5) & 127;
    aux ^= segment_98 & 15;
  }
  else
  {
    acc = ((acc - segment_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000317_1713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000317_1713_2 st_1 = {0};
  struct Vector3D_R000317_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int pivot_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_46_1 > 20)
  {
    acc_1 = ((acc_1 + (pivot_46_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_46_2 > 20)
  {
    acc_2 = ((acc_2 + (pivot_46_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_26_1)
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

  switch (factor_26_2)
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

  int quotient_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_52_1) & 63;
  aux_2 = (aux_2 + quotient_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_46_1 == pivot_46_2);
  assert(factor_26_1 == factor_26_2);
  assert(quotient_52_1 == quotient_52_2);
}

int fn_R000317_1713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000317_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int pivot_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_46 > 20)
  {
    acc = ((acc + (pivot_46 * 2)) + 5) & 127;
    aux ^= pivot_46 & 15;
  }
  else
  {
    acc = ((acc - pivot_46) + 11) & 127;
    aux += 3;
  }
  int factor_26 = (aux + st.buffer[1]) & 3;
  switch (factor_26)
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

  int quotient_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_52) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000317_1713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000317_1713_0 st_1 = {0};
  struct SensorNode_R000317_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int index_reg_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_64_1)
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

  switch (index_reg_64_2)
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

  int threshold_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_23_1) & 63;
  aux_2 = (aux_2 + threshold_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_59_1 > 48)
  {
    acc_1 = ((acc_1 + (coefficient_59_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_59_2 > 48)
  {
    acc_2 = ((acc_2 + (coefficient_59_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_64_1 == index_reg_64_2);
  assert(threshold_23_1 == threshold_23_2);
  assert(coefficient_59_1 == coefficient_59_2);
}

int fn_R000317_1713_15(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000317_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int index_reg_64 = (aux + st.buffer[1]) & 3;
  switch (index_reg_64)
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

  int threshold_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_23) & 63;
  acc ^= aux;
  int coefficient_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_59 > 48)
  {
    acc = ((acc + (coefficient_59 * 2)) + 5) & 127;
    aux ^= coefficient_59 & 15;
  }
  else
  {
    acc = ((acc - coefficient_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000317_1713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000317_1713_3 st_1 = {0};
  struct CipherContext_R000317_1713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int scale_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_70_1 > 17)
  {
    acc_1 = ((acc_1 + (scale_70_1 * 2)) + 5) & 127;
    aux_1 ^= scale_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_70_2 > 17)
  {
    acc_2 = ((acc_2 + (scale_70_2 * 2)) + 5) & 127;
    aux_2 ^= scale_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_14_1)
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

  switch (stride_14_2)
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
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_70_1 == scale_70_2);
  assert(stride_14_1 == stride_14_2);
}

int fn_R000317_1713_16(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000317_1713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int scale_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_70 > 17)
  {
    acc = ((acc + (scale_70 * 2)) + 5) & 127;
    aux ^= scale_70 & 15;
  }
  else
  {
    acc = ((acc - scale_70) + 11) & 127;
    aux += 3;
  }
  int stride_14 = (aux + st.buffer[1]) & 3;
  switch (stride_14)
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

void fn_R000317_1713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000317_1713_1 st_1 = {0};
  struct FilterState_R000317_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int phase_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_42_1 > 19)
  {
    acc_1 = ((acc_1 + (phase_42_1 * 2)) + 5) & 127;
    aux_1 ^= phase_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_42_2 > 19)
  {
    acc_2 = ((acc_2 + (phase_42_2 * 2)) + 5) & 127;
    aux_2 ^= phase_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_42_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_40_1)
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

  switch (quantum_40_2)
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

  int delta_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_94_1) & 63;
  aux_2 = (aux_2 + delta_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_56_1 = local_arr_1[aux_1 % 3];
  int damping_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_42_1 == phase_42_2);
  assert(quantum_40_1 == quantum_40_2);
  assert(delta_94_1 == delta_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_56_1 == damping_56_2);
}

int fn_R000317_1713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000317_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int phase_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_42 > 19)
  {
    acc = ((acc + (phase_42 * 2)) + 5) & 127;
    aux ^= phase_42 & 15;
  }
  else
  {
    acc = ((acc - phase_42) + 11) & 127;
    aux += 3;
  }
  int quantum_40 = (aux + st.buffer[1]) & 3;
  switch (quantum_40)
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

  int delta_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_94) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int damping_56 = local_arr[aux % 3];
  acc = (acc + (damping_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000317_1713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000317_1713_1 st_1 = {0};
  struct FilterState_R000317_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_76_1) & 63;
  aux_2 = (aux_2 + weight_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_39_1 > 16)
  {
    acc_1 = ((acc_1 + (mask_39_1 * 2)) + 5) & 127;
    aux_1 ^= mask_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_39_2 > 16)
  {
    acc_2 = ((acc_2 + (mask_39_2 * 2)) + 5) & 127;
    aux_2 ^= mask_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_20_1 = local_arr_1[aux_1 % 3];
  int checksum_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_20_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_76_1 == weight_76_2);
  assert(mask_39_1 == mask_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_20_1 == checksum_20_2);
}

int fn_R000317_1713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000317_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_76) & 63;
  acc ^= aux;
  int mask_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_39 > 16)
  {
    acc = ((acc + (mask_39 * 2)) + 5) & 127;
    aux ^= mask_39 & 15;
  }
  else
  {
    acc = ((acc - mask_39) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_20 = local_arr[aux % 3];
  acc = (acc + (checksum_20 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000317_0_1;
  int sec_r000317_0_2;
  int sec_r000317_1_1;
  int sec_r000317_1_2;
  int sec_r000317_2_1;
  int sec_r000317_2_2;
  int sec_r000317_3_1;
  int sec_r000317_3_2;
  int sec_r000317_4_1;
  int sec_r000317_4_2;
  int sec_r000317_5_1;
  int sec_r000317_5_2;
  int sec_r000317_6_1;
  int sec_r000317_6_2;
  int sec_r000317_7_1;
  int sec_r000317_7_2;
  int sec_r000317_8_1;
  int sec_r000317_8_2;
  int sec_r000317_9_1;
  int sec_r000317_9_2;
  int sec_r000317_10_1;
  int sec_r000317_10_2;
  int sec_r000317_11_1;
  int sec_r000317_11_2;
  int sec_r000317_12_1;
  int sec_r000317_12_2;
  int sec_r000317_13_1;
  int sec_r000317_13_2;
  int sec_r000317_14_1;
  int sec_r000317_14_2;
  int sec_r000317_15_1;
  int sec_r000317_15_2;
  int sec_r000317_16_1;
  int sec_r000317_16_2;
  int sec_r000317_17_1;
  int sec_r000317_17_2;
  int pub_r000317_0_1;
  int pub_r000317_0_2;
  int pub_r000317_1_1;
  int pub_r000317_1_2;
  int pub_r000317_2_1;
  int pub_r000317_2_2;
  int pub_r000317_3_1;
  int pub_r000317_3_2;
  int pub_r000317_4_1;
  int pub_r000317_4_2;
  int pub_r000317_5_1;
  int pub_r000317_5_2;
  int pub_r000317_6_1;
  int pub_r000317_6_2;
  int pub_r000317_7_1;
  int pub_r000317_7_2;
  int pub_r000317_8_1;
  int pub_r000317_8_2;
  int pub_r000317_9_1;
  int pub_r000317_9_2;
  int pub_r000317_10_1;
  int pub_r000317_10_2;
  int pub_r000317_11_1;
  int pub_r000317_11_2;
  int pub_r000317_12_1;
  int pub_r000317_12_2;
  int pub_r000317_13_1;
  int pub_r000317_13_2;
  int pub_r000317_14_1;
  int pub_r000317_14_2;
  int pub_r000317_15_1;
  int pub_r000317_15_2;
  int pub_r000317_16_1;
  int pub_r000317_16_2;
  int pub_r000317_17_1;
  int pub_r000317_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000317_0_1 >= (-100)) && (pub_r000317_0_1 <= 100));
  __CPROVER_assume((pub_r000317_0_2 >= (-100)) && (pub_r000317_0_2 <= 100));
  __CPROVER_assume((pub_r000317_1_1 >= (-100)) && (pub_r000317_1_1 <= 100));
  __CPROVER_assume((pub_r000317_1_2 >= (-100)) && (pub_r000317_1_2 <= 100));
  __CPROVER_assume((pub_r000317_2_1 >= (-100)) && (pub_r000317_2_1 <= 100));
  __CPROVER_assume((pub_r000317_2_2 >= (-100)) && (pub_r000317_2_2 <= 100));
  __CPROVER_assume((pub_r000317_3_1 >= (-100)) && (pub_r000317_3_1 <= 100));
  __CPROVER_assume((pub_r000317_3_2 >= (-100)) && (pub_r000317_3_2 <= 100));
  __CPROVER_assume((pub_r000317_4_1 >= (-100)) && (pub_r000317_4_1 <= 100));
  __CPROVER_assume((pub_r000317_4_2 >= (-100)) && (pub_r000317_4_2 <= 100));
  __CPROVER_assume((pub_r000317_5_1 >= (-100)) && (pub_r000317_5_1 <= 100));
  __CPROVER_assume((pub_r000317_5_2 >= (-100)) && (pub_r000317_5_2 <= 100));
  __CPROVER_assume((pub_r000317_6_1 >= (-100)) && (pub_r000317_6_1 <= 100));
  __CPROVER_assume((pub_r000317_6_2 >= (-100)) && (pub_r000317_6_2 <= 100));
  __CPROVER_assume((pub_r000317_7_1 >= (-100)) && (pub_r000317_7_1 <= 100));
  __CPROVER_assume((pub_r000317_7_2 >= (-100)) && (pub_r000317_7_2 <= 100));
  __CPROVER_assume((pub_r000317_8_1 >= (-100)) && (pub_r000317_8_1 <= 100));
  __CPROVER_assume((pub_r000317_8_2 >= (-100)) && (pub_r000317_8_2 <= 100));
  __CPROVER_assume((pub_r000317_9_1 >= (-100)) && (pub_r000317_9_1 <= 100));
  __CPROVER_assume((pub_r000317_9_2 >= (-100)) && (pub_r000317_9_2 <= 100));
  __CPROVER_assume((pub_r000317_10_1 >= (-100)) && (pub_r000317_10_1 <= 100));
  __CPROVER_assume((pub_r000317_10_2 >= (-100)) && (pub_r000317_10_2 <= 100));
  __CPROVER_assume((pub_r000317_11_1 >= (-100)) && (pub_r000317_11_1 <= 100));
  __CPROVER_assume((pub_r000317_11_2 >= (-100)) && (pub_r000317_11_2 <= 100));
  __CPROVER_assume((pub_r000317_12_1 >= (-100)) && (pub_r000317_12_1 <= 100));
  __CPROVER_assume((pub_r000317_12_2 >= (-100)) && (pub_r000317_12_2 <= 100));
  __CPROVER_assume((pub_r000317_13_1 >= (-100)) && (pub_r000317_13_1 <= 100));
  __CPROVER_assume((pub_r000317_13_2 >= (-100)) && (pub_r000317_13_2 <= 100));
  __CPROVER_assume((pub_r000317_14_1 >= (-100)) && (pub_r000317_14_1 <= 100));
  __CPROVER_assume((pub_r000317_14_2 >= (-100)) && (pub_r000317_14_2 <= 100));
  __CPROVER_assume((pub_r000317_15_1 >= (-100)) && (pub_r000317_15_1 <= 100));
  __CPROVER_assume((pub_r000317_15_2 >= (-100)) && (pub_r000317_15_2 <= 100));
  __CPROVER_assume((pub_r000317_16_1 >= (-100)) && (pub_r000317_16_1 <= 100));
  __CPROVER_assume((pub_r000317_16_2 >= (-100)) && (pub_r000317_16_2 <= 100));
  __CPROVER_assume((pub_r000317_17_1 >= (-100)) && (pub_r000317_17_1 <= 100));
  __CPROVER_assume((pub_r000317_17_2 >= (-100)) && (pub_r000317_17_2 <= 100));
  __CPROVER_assume((sec_r000317_0_1 >= 0) && (sec_r000317_0_1 <= 255));
  __CPROVER_assume((sec_r000317_0_2 >= 0) && (sec_r000317_0_2 <= 255));
  __CPROVER_assume((sec_r000317_1_1 >= 0) && (sec_r000317_1_1 <= 255));
  __CPROVER_assume((sec_r000317_1_2 >= 0) && (sec_r000317_1_2 <= 255));
  __CPROVER_assume((sec_r000317_2_1 >= 0) && (sec_r000317_2_1 <= 255));
  __CPROVER_assume((sec_r000317_2_2 >= 0) && (sec_r000317_2_2 <= 255));
  __CPROVER_assume((sec_r000317_3_1 >= 0) && (sec_r000317_3_1 <= 255));
  __CPROVER_assume((sec_r000317_3_2 >= 0) && (sec_r000317_3_2 <= 255));
  __CPROVER_assume((sec_r000317_4_1 >= 0) && (sec_r000317_4_1 <= 255));
  __CPROVER_assume((sec_r000317_4_2 >= 0) && (sec_r000317_4_2 <= 255));
  __CPROVER_assume((sec_r000317_5_1 >= 0) && (sec_r000317_5_1 <= 255));
  __CPROVER_assume((sec_r000317_5_2 >= 0) && (sec_r000317_5_2 <= 255));
  __CPROVER_assume((sec_r000317_6_1 >= 0) && (sec_r000317_6_1 <= 255));
  __CPROVER_assume((sec_r000317_6_2 >= 0) && (sec_r000317_6_2 <= 255));
  __CPROVER_assume((sec_r000317_7_1 >= 0) && (sec_r000317_7_1 <= 255));
  __CPROVER_assume((sec_r000317_7_2 >= 0) && (sec_r000317_7_2 <= 255));
  __CPROVER_assume((sec_r000317_8_1 >= 0) && (sec_r000317_8_1 <= 255));
  __CPROVER_assume((sec_r000317_8_2 >= 0) && (sec_r000317_8_2 <= 255));
  __CPROVER_assume((sec_r000317_9_1 >= 0) && (sec_r000317_9_1 <= 255));
  __CPROVER_assume((sec_r000317_9_2 >= 0) && (sec_r000317_9_2 <= 255));
  __CPROVER_assume((sec_r000317_10_1 >= 0) && (sec_r000317_10_1 <= 255));
  __CPROVER_assume((sec_r000317_10_2 >= 0) && (sec_r000317_10_2 <= 255));
  __CPROVER_assume((sec_r000317_11_1 >= 0) && (sec_r000317_11_1 <= 255));
  __CPROVER_assume((sec_r000317_11_2 >= 0) && (sec_r000317_11_2 <= 255));
  __CPROVER_assume((sec_r000317_12_1 >= 0) && (sec_r000317_12_1 <= 255));
  __CPROVER_assume((sec_r000317_12_2 >= 0) && (sec_r000317_12_2 <= 255));
  __CPROVER_assume((sec_r000317_13_1 >= 0) && (sec_r000317_13_1 <= 255));
  __CPROVER_assume((sec_r000317_13_2 >= 0) && (sec_r000317_13_2 <= 255));
  __CPROVER_assume((sec_r000317_14_1 >= 0) && (sec_r000317_14_1 <= 255));
  __CPROVER_assume((sec_r000317_14_2 >= 0) && (sec_r000317_14_2 <= 255));
  __CPROVER_assume((sec_r000317_15_1 >= 0) && (sec_r000317_15_1 <= 255));
  __CPROVER_assume((sec_r000317_15_2 >= 0) && (sec_r000317_15_2 <= 255));
  __CPROVER_assume((sec_r000317_16_1 >= 0) && (sec_r000317_16_1 <= 255));
  __CPROVER_assume((sec_r000317_16_2 >= 0) && (sec_r000317_16_2 <= 255));
  __CPROVER_assume((sec_r000317_17_1 >= 0) && (sec_r000317_17_1 <= 255));
  __CPROVER_assume((sec_r000317_17_2 >= 0) && (sec_r000317_17_2 <= 255));
  struct SensorNode_R000317_1713_0 st_var_0_1 = {0};
  struct SensorNode_R000317_1713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000317_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000317_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000317_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000317_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000317_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000317_0_2 + 7) & 15;
  struct FilterState_R000317_1713_1 st_var_1_1 = {0};
  struct FilterState_R000317_1713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000317_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000317_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000317_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000317_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000317_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000317_0_2 + 9) & 15;
  struct Vector3D_R000317_1713_2 st_var_2_1 = {0};
  struct Vector3D_R000317_1713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000317_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000317_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000317_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000317_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000317_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000317_0_2 + 11) & 15;
  struct CipherContext_R000317_1713_3 st_var_3_1 = {0};
  struct CipherContext_R000317_1713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000317_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000317_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000317_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000317_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000317_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000317_0_2 + 13) & 15;
  union TelemetryField_R000317_1713_0 u_var_1;
  union TelemetryField_R000317_1713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 46)
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
  if (stage_v_0_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 46)
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
  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 43)
    {
      chk_sum_1 ^= stage_v_2_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_2_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 43)
    {
      chk_sum_2 ^= stage_v_2_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_3_1 = (st_var_3_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_3_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (st_var_3_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_3_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  if ((sec_r000317_10_1 & 1) != 0)
  {
    if ((sec_r000317_7_1 & 2) != 0)
    {
      stage_v_12_1 = (pub_r000317_2_1 + 31) & 127;
    }
    else
    {
      stage_v_12_1 = (pub_r000317_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_12_1 = (pub_r000317_2_1 + 7) & 127;
  }
  if ((sec_r000317_10_2 & 1) != 0)
  {
    if ((sec_r000317_7_2 & 2) != 0)
    {
      stage_v_12_2 = (pub_r000317_2_2 + 31) & 127;
    }
    else
    {
      stage_v_12_2 = (pub_r000317_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_12_2 = (pub_r000317_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((sec_r000317_2_1 & 2) != 0)
    {
      stage_v_13_1 = (pub_r000317_12_1 + 31) & 127;
    }
    else
    {
      stage_v_13_1 = (pub_r000317_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_13_1 = (pub_r000317_12_1 + 7) & 127;
  }
  if ((stage_v_12_2 & 1) != 0)
  {
    if ((sec_r000317_2_2 & 2) != 0)
    {
      stage_v_13_2 = (pub_r000317_12_2 + 31) & 127;
    }
    else
    {
      stage_v_13_2 = (pub_r000317_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_13_2 = (pub_r000317_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r000317_8_1 & 2) != 0)
    {
      stage_v_14_1 = (pub_r000317_4_1 + 31) & 127;
    }
    else
    {
      stage_v_14_1 = (pub_r000317_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_14_1 = (pub_r000317_4_1 + 7) & 127;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((sec_r000317_8_2 & 2) != 0)
    {
      stage_v_14_2 = (pub_r000317_4_2 + 31) & 127;
    }
    else
    {
      stage_v_14_2 = (pub_r000317_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_14_2 = (pub_r000317_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r000317_15_1 & 2) != 0)
    {
      stage_v_15_1 = (pub_r000317_8_1 + 31) & 127;
    }
    else
    {
      stage_v_15_1 = (pub_r000317_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_15_1 = (pub_r000317_8_1 + 7) & 127;
  }
  if ((stage_v_14_2 & 1) != 0)
  {
    if ((sec_r000317_15_2 & 2) != 0)
    {
      stage_v_15_2 = (pub_r000317_8_2 + 31) & 127;
    }
    else
    {
      stage_v_15_2 = (pub_r000317_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_15_2 = (pub_r000317_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  if ((sec_r000317_3_1 & 1) != 0)
  {
    if ((sec_r000317_12_1 & 2) != 0)
    {
      stage_v_16_1 = (pub_r000317_4_1 + 31) & 127;
    }
    else
    {
      stage_v_16_1 = (pub_r000317_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_16_1 = (pub_r000317_4_1 + 7) & 127;
  }
  if ((sec_r000317_3_2 & 1) != 0)
  {
    if ((sec_r000317_12_2 & 2) != 0)
    {
      stage_v_16_2 = (pub_r000317_4_2 + 31) & 127;
    }
    else
    {
      stage_v_16_2 = (pub_r000317_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_16_2 = (pub_r000317_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r000317_10_1 & 2) != 0)
    {
      stage_v_17_1 = (pub_r000317_7_1 + 31) & 127;
    }
    else
    {
      stage_v_17_1 = (pub_r000317_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_17_1 = (pub_r000317_7_1 + 7) & 127;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((sec_r000317_10_2 & 2) != 0)
    {
      stage_v_17_2 = (pub_r000317_7_2 + 31) & 127;
    }
    else
    {
      stage_v_17_2 = (pub_r000317_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_17_2 = (pub_r000317_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000317_16_1 & 2) != 0)
    {
      stage_v_18_1 = (pub_r000317_4_1 + 31) & 127;
    }
    else
    {
      stage_v_18_1 = (pub_r000317_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_18_1 = (pub_r000317_4_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000317_16_2 & 2) != 0)
    {
      stage_v_18_2 = (pub_r000317_4_2 + 31) & 127;
    }
    else
    {
      stage_v_18_2 = (pub_r000317_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_18_2 = (pub_r000317_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  if ((sec_r000317_2_1 & 1) != 0)
  {
    if ((sec_r000317_11_1 & 2) != 0)
    {
      stage_v_19_1 = (pub_r000317_1_1 + 31) & 127;
    }
    else
    {
      stage_v_19_1 = (pub_r000317_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_19_1 = (pub_r000317_1_1 + 7) & 127;
  }
  if ((sec_r000317_2_2 & 1) != 0)
  {
    if ((sec_r000317_11_2 & 2) != 0)
    {
      stage_v_19_2 = (pub_r000317_1_2 + 31) & 127;
    }
    else
    {
      stage_v_19_2 = (pub_r000317_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_19_2 = (pub_r000317_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r000317_8_1 & 2) != 0)
    {
      stage_v_20_1 = (pub_r000317_5_1 + 31) & 127;
    }
    else
    {
      stage_v_20_1 = (pub_r000317_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_20_1 = (pub_r000317_5_1 + 7) & 127;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((sec_r000317_8_2 & 2) != 0)
    {
      stage_v_20_2 = (pub_r000317_5_2 + 31) & 127;
    }
    else
    {
      stage_v_20_2 = (pub_r000317_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_20_2 = (pub_r000317_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  if ((sec_r000317_14_1 & 1) != 0)
  {
    if ((sec_r000317_8_1 & 2) != 0)
    {
      stage_v_21_1 = (pub_r000317_7_1 + 31) & 127;
    }
    else
    {
      stage_v_21_1 = (pub_r000317_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_21_1 = (pub_r000317_7_1 + 7) & 127;
  }
  if ((sec_r000317_14_2 & 1) != 0)
  {
    if ((sec_r000317_8_2 & 2) != 0)
    {
      stage_v_21_2 = (pub_r000317_7_2 + 31) & 127;
    }
    else
    {
      stage_v_21_2 = (pub_r000317_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_21_2 = (pub_r000317_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r000317_1_1 & 2) != 0)
    {
      stage_v_22_1 = (pub_r000317_15_1 + 31) & 127;
    }
    else
    {
      stage_v_22_1 = (pub_r000317_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_1 = (pub_r000317_15_1 + 7) & 127;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r000317_1_2 & 2) != 0)
    {
      stage_v_22_2 = (pub_r000317_15_2 + 31) & 127;
    }
    else
    {
      stage_v_22_2 = (pub_r000317_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_2 = (pub_r000317_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r000317_11_1 & 2) != 0)
    {
      stage_v_23_1 = (pub_r000317_1_1 + 31) & 127;
    }
    else
    {
      stage_v_23_1 = (pub_r000317_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_1 = (pub_r000317_1_1 + 7) & 127;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((sec_r000317_11_2 & 2) != 0)
    {
      stage_v_23_2 = (pub_r000317_1_2 + 31) & 127;
    }
    else
    {
      stage_v_23_2 = (pub_r000317_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_2 = (pub_r000317_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((sec_r000317_10_1 & 2) != 0)
    {
      stage_v_24_1 = (pub_r000317_3_1 + 31) & 127;
    }
    else
    {
      stage_v_24_1 = (pub_r000317_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_1 = (pub_r000317_3_1 + 7) & 127;
  }
  if ((stage_v_12_2 & 1) != 0)
  {
    if ((sec_r000317_10_2 & 2) != 0)
    {
      stage_v_24_2 = (pub_r000317_3_2 + 31) & 127;
    }
    else
    {
      stage_v_24_2 = (pub_r000317_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_2 = (pub_r000317_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r000317_13_1 & 2) != 0)
    {
      stage_v_25_1 = (pub_r000317_15_1 + 31) & 127;
    }
    else
    {
      stage_v_25_1 = (pub_r000317_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_1 = (pub_r000317_15_1 + 7) & 127;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((sec_r000317_13_2 & 2) != 0)
    {
      stage_v_25_2 = (pub_r000317_15_2 + 31) & 127;
    }
    else
    {
      stage_v_25_2 = (pub_r000317_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_2 = (pub_r000317_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r000317_9_1 & 2) != 0)
    {
      stage_v_26_1 = (pub_r000317_17_1 + 31) & 127;
    }
    else
    {
      stage_v_26_1 = (pub_r000317_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_1 = (pub_r000317_17_1 + 7) & 127;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((sec_r000317_9_2 & 2) != 0)
    {
      stage_v_26_2 = (pub_r000317_17_2 + 31) & 127;
    }
    else
    {
      stage_v_26_2 = (pub_r000317_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_2 = (pub_r000317_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r000317_10_1 & 2) != 0)
    {
      stage_v_27_1 = (pub_r000317_12_1 + 31) & 127;
    }
    else
    {
      stage_v_27_1 = (pub_r000317_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_1 = (pub_r000317_12_1 + 7) & 127;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r000317_10_2 & 2) != 0)
    {
      stage_v_27_2 = (pub_r000317_12_2 + 31) & 127;
    }
    else
    {
      stage_v_27_2 = (pub_r000317_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_2 = (pub_r000317_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r000317_5_1 & 2) != 0)
    {
      stage_v_28_1 = (pub_r000317_11_1 + 31) & 127;
    }
    else
    {
      stage_v_28_1 = (pub_r000317_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_1 = (pub_r000317_11_1 + 7) & 127;
  }
  if ((stage_v_14_2 & 1) != 0)
  {
    if ((sec_r000317_5_2 & 2) != 0)
    {
      stage_v_28_2 = (pub_r000317_11_2 + 31) & 127;
    }
    else
    {
      stage_v_28_2 = (pub_r000317_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_2 = (pub_r000317_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000317_7_1 & 2) != 0)
    {
      stage_v_29_1 = (pub_r000317_9_1 + 31) & 127;
    }
    else
    {
      stage_v_29_1 = (pub_r000317_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_1 = (pub_r000317_9_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000317_7_2 & 2) != 0)
    {
      stage_v_29_2 = (pub_r000317_9_2 + 31) & 127;
    }
    else
    {
      stage_v_29_2 = (pub_r000317_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_2 = (pub_r000317_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000317_14_1 & 2) != 0)
    {
      stage_v_30_1 = (pub_r000317_14_1 + 31) & 127;
    }
    else
    {
      stage_v_30_1 = (pub_r000317_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_1 = (pub_r000317_14_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000317_14_2 & 2) != 0)
    {
      stage_v_30_2 = (pub_r000317_14_2 + 31) & 127;
    }
    else
    {
      stage_v_30_2 = (pub_r000317_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_2 = (pub_r000317_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r000317_4_1 & 2) != 0)
    {
      stage_v_31_1 = (pub_r000317_7_1 + 31) & 127;
    }
    else
    {
      stage_v_31_1 = (pub_r000317_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_1 = (pub_r000317_7_1 + 7) & 127;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r000317_4_2 & 2) != 0)
    {
      stage_v_31_2 = (pub_r000317_7_2 + 31) & 127;
    }
    else
    {
      stage_v_31_2 = (pub_r000317_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_2 = (pub_r000317_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((sec_r000317_15_1 & 1) != 0)
  {
    if ((sec_r000317_8_1 & 2) != 0)
    {
      stage_v_32_1 = (pub_r000317_6_1 + 31) & 127;
    }
    else
    {
      stage_v_32_1 = (pub_r000317_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_1 = (pub_r000317_6_1 + 7) & 127;
  }
  if ((sec_r000317_15_2 & 1) != 0)
  {
    if ((sec_r000317_8_2 & 2) != 0)
    {
      stage_v_32_2 = (pub_r000317_6_2 + 31) & 127;
    }
    else
    {
      stage_v_32_2 = (pub_r000317_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_2 = (pub_r000317_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r000317_13_1 & 2) != 0)
    {
      stage_v_33_1 = (pub_r000317_4_1 + 31) & 127;
    }
    else
    {
      stage_v_33_1 = (pub_r000317_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_1 = (pub_r000317_4_1 + 7) & 127;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((sec_r000317_13_2 & 2) != 0)
    {
      stage_v_33_2 = (pub_r000317_4_2 + 31) & 127;
    }
    else
    {
      stage_v_33_2 = (pub_r000317_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_2 = (pub_r000317_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000317_4_1 & 2) != 0)
    {
      stage_v_34_1 = (pub_r000317_16_1 + 31) & 127;
    }
    else
    {
      stage_v_34_1 = (pub_r000317_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_1 = (pub_r000317_16_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000317_4_2 & 2) != 0)
    {
      stage_v_34_2 = (pub_r000317_16_2 + 31) & 127;
    }
    else
    {
      stage_v_34_2 = (pub_r000317_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_2 = (pub_r000317_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r000317_12_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000317_16_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000317_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000317_16_1 + 7) & 127;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r000317_12_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000317_16_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000317_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000317_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000317_4_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000317_2_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000317_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000317_2_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000317_4_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000317_2_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000317_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000317_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000317_1_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000317_1_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000317_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000317_1_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000317_1_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000317_1_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000317_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000317_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((sec_r000317_10_1 & 1) != 0)
  {
    if ((sec_r000317_10_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000317_1_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000317_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000317_1_1 + 7) & 127;
  }
  if ((sec_r000317_10_2 & 1) != 0)
  {
    if ((sec_r000317_10_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000317_1_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000317_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000317_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000317_8_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000317_6_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000317_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000317_6_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000317_8_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000317_6_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000317_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000317_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000317_4_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000317_15_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000317_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000317_15_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000317_4_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000317_15_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000317_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000317_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r000317_1_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000317_8_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000317_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000317_8_1 + 7) & 127;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r000317_1_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000317_8_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000317_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000317_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000317_6_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000317_9_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000317_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000317_9_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000317_6_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000317_9_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000317_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000317_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((sec_r000317_2_1 & 1) != 0)
  {
    if ((sec_r000317_15_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000317_3_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000317_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000317_3_1 + 7) & 127;
  }
  if ((sec_r000317_2_2 & 1) != 0)
  {
    if ((sec_r000317_15_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000317_3_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000317_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000317_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000317_9_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000317_8_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000317_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000317_8_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000317_9_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000317_8_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000317_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000317_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((sec_r000317_1_1 & 1) != 0)
  {
    if ((sec_r000317_8_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000317_13_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000317_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000317_13_1 + 7) & 127;
  }
  if ((sec_r000317_1_2 & 1) != 0)
  {
    if ((sec_r000317_8_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000317_13_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000317_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000317_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000317_0_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000317_15_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000317_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000317_15_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000317_0_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000317_15_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000317_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000317_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000317_0_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000317_16_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000317_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000317_16_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000317_0_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000317_16_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000317_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000317_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((sec_r000317_8_1 & 1) != 0)
  {
    if ((sec_r000317_16_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000317_0_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000317_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000317_0_1 + 7) & 127;
  }
  if ((sec_r000317_8_2 & 1) != 0)
  {
    if ((sec_r000317_16_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000317_0_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000317_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000317_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000317_6_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000317_14_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000317_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000317_14_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000317_6_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000317_14_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000317_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000317_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000317_8_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000317_5_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000317_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000317_5_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000317_8_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000317_5_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000317_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000317_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000317_4_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000317_5_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000317_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000317_5_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000317_4_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000317_5_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000317_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000317_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000317_9_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000317_7_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000317_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000317_7_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000317_9_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000317_7_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000317_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000317_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000317_8_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000317_16_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000317_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000317_16_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000317_8_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000317_16_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000317_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000317_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000317_6_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000317_12_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000317_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000317_12_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000317_6_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000317_12_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000317_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000317_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((sec_r000317_16_1 & 1) != 0)
  {
    if ((sec_r000317_9_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000317_16_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000317_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000317_16_1 + 7) & 127;
  }
  if ((sec_r000317_16_2 & 1) != 0)
  {
    if ((sec_r000317_9_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000317_16_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000317_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000317_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((sec_r000317_2_1 & 1) != 0)
  {
    if ((sec_r000317_15_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000317_7_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000317_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000317_7_1 + 7) & 127;
  }
  if ((sec_r000317_2_2 & 1) != 0)
  {
    if ((sec_r000317_15_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000317_7_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000317_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000317_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000317_11_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000317_13_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000317_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000317_13_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000317_11_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000317_13_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000317_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000317_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000317_9_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000317_5_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000317_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000317_5_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000317_9_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000317_5_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000317_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000317_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((sec_r000317_16_1 & 1) != 0)
  {
    if ((sec_r000317_10_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000317_16_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000317_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000317_16_1 + 7) & 127;
  }
  if ((sec_r000317_16_2 & 1) != 0)
  {
    if ((sec_r000317_10_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000317_16_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000317_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000317_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000317_6_1 & 1) != 0)
  {
    if ((sec_r000317_11_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000317_7_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000317_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000317_7_1 + 7) & 127;
  }
  if ((sec_r000317_6_2 & 1) != 0)
  {
    if ((sec_r000317_11_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000317_7_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000317_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000317_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r000317_10_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000317_2_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000317_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000317_2_1 + 7) & 127;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r000317_10_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000317_2_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000317_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000317_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((sec_r000317_16_1 & 1) != 0)
  {
    if ((sec_r000317_12_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000317_17_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000317_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000317_17_1 + 7) & 127;
  }
  if ((sec_r000317_16_2 & 1) != 0)
  {
    if ((sec_r000317_12_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000317_17_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000317_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000317_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r000317_13_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000317_3_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000317_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000317_3_1 + 7) & 127;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r000317_13_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000317_3_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000317_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000317_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000317_2_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000317_3_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000317_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000317_3_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000317_2_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000317_3_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000317_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000317_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000317_16_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000317_13_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000317_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000317_13_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000317_16_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000317_13_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000317_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000317_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000317_17_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000317_14_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000317_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000317_14_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000317_17_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000317_14_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000317_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000317_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000317_17_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000317_2_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000317_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000317_2_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000317_17_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000317_2_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000317_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000317_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r000317_5_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000317_14_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000317_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000317_14_1 + 7) & 127;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((sec_r000317_5_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000317_14_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000317_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000317_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000317_4_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000317_4_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000317_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000317_4_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000317_4_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000317_4_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000317_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000317_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000317_12_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000317_12_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000317_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000317_12_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000317_12_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000317_12_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000317_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000317_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000317_1_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000317_13_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000317_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000317_13_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000317_1_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000317_13_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000317_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000317_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000317_16_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000317_11_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000317_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000317_11_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000317_16_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000317_11_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000317_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000317_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000317_15_1 & 1) != 0)
  {
    if ((sec_r000317_6_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000317_2_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000317_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000317_2_1 + 7) & 127;
  }
  if ((sec_r000317_15_2 & 1) != 0)
  {
    if ((sec_r000317_6_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000317_2_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000317_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000317_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000317_10_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000317_0_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000317_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000317_0_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000317_10_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000317_0_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000317_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000317_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000317_17_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000317_1_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000317_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000317_1_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000317_17_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000317_1_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000317_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000317_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000317_3_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000317_5_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000317_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000317_5_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000317_3_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000317_5_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000317_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000317_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000317_8_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000317_10_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000317_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000317_10_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000317_8_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000317_10_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000317_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000317_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000317_5_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000317_6_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000317_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000317_6_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000317_5_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000317_6_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000317_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000317_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000317_1_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000317_8_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000317_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000317_8_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000317_1_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000317_8_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000317_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000317_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000317_6_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000317_3_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000317_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000317_3_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000317_6_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000317_3_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000317_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000317_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000317_5_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000317_12_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000317_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000317_12_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000317_5_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000317_12_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000317_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000317_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000317_15_1 & 1) != 0)
  {
    if ((sec_r000317_4_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000317_16_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000317_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000317_16_1 + 7) & 127;
  }
  if ((sec_r000317_15_2 & 1) != 0)
  {
    if ((sec_r000317_4_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000317_16_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000317_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000317_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000317_3_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000317_4_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000317_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000317_4_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000317_3_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000317_4_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000317_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000317_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000317_6_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000317_15_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000317_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000317_15_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000317_6_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000317_15_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000317_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000317_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r000317_14_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000317_17_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000317_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000317_17_1 + 7) & 127;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((sec_r000317_14_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000317_17_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000317_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000317_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000317_12_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000317_3_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000317_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000317_3_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000317_12_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000317_3_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000317_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000317_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((sec_r000317_10_1 & 1) != 0)
  {
    if ((sec_r000317_6_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000317_4_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000317_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000317_4_1 + 7) & 127;
  }
  if ((sec_r000317_10_2 & 1) != 0)
  {
    if ((sec_r000317_6_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000317_4_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000317_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000317_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000317_9_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000317_7_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000317_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000317_7_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000317_9_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000317_7_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000317_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000317_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000317_5_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000317_0_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000317_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000317_0_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000317_5_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000317_0_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000317_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000317_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000317_1_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000317_12_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000317_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000317_12_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000317_1_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000317_12_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000317_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000317_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000317_12_1 & 1) != 0)
  {
    if ((sec_r000317_14_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000317_15_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000317_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000317_15_1 + 7) & 127;
  }
  if ((sec_r000317_12_2 & 1) != 0)
  {
    if ((sec_r000317_14_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000317_15_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000317_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000317_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000317_14_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000317_8_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000317_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000317_8_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000317_14_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000317_8_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000317_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000317_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000317_11_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000317_5_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000317_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000317_5_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000317_11_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000317_5_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000317_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000317_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000317_15_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000317_2_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000317_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000317_2_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000317_15_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000317_2_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000317_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000317_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000317_5_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000317_7_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000317_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000317_7_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000317_5_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000317_7_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000317_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000317_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000317_11_1 & 1) != 0)
  {
    if ((sec_r000317_3_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000317_8_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000317_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000317_8_1 + 7) & 127;
  }
  if ((sec_r000317_11_2 & 1) != 0)
  {
    if ((sec_r000317_3_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000317_8_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000317_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000317_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000317_13_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000317_5_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000317_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000317_5_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000317_13_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000317_5_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000317_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000317_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000317_13_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000317_13_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000317_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000317_13_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000317_13_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000317_13_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000317_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000317_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000317_1_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000317_12_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000317_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000317_12_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000317_1_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000317_12_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000317_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000317_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000317_12_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000317_17_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000317_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000317_17_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000317_12_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000317_17_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000317_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000317_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000317_7_1 & 1) != 0)
  {
    if ((sec_r000317_7_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000317_3_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000317_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000317_3_1 + 7) & 127;
  }
  if ((sec_r000317_7_2 & 1) != 0)
  {
    if ((sec_r000317_7_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000317_3_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000317_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000317_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000317_13_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000317_4_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000317_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000317_4_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000317_13_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000317_4_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000317_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000317_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000317_4_1 & 1) != 0)
  {
    if ((sec_r000317_9_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000317_11_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000317_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000317_11_1 + 7) & 127;
  }
  if ((sec_r000317_4_2 & 1) != 0)
  {
    if ((sec_r000317_9_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000317_11_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000317_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000317_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r000317_10_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000317_3_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000317_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000317_3_1 + 7) & 127;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((sec_r000317_10_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000317_3_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000317_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000317_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000317_14_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000317_4_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000317_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000317_4_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000317_14_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000317_4_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000317_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000317_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000317_4_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000317_13_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000317_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000317_13_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000317_4_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000317_13_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000317_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000317_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000317_16_1 & 1) != 0)
  {
    if ((sec_r000317_5_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000317_8_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000317_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000317_8_1 + 7) & 127;
  }
  if ((sec_r000317_16_2 & 1) != 0)
  {
    if ((sec_r000317_5_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000317_8_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000317_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000317_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000317_1_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000317_5_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000317_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000317_5_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000317_1_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000317_5_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000317_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000317_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000317_13_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000317_5_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000317_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000317_5_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000317_13_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000317_5_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000317_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000317_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000317_3_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000317_16_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000317_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000317_16_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000317_3_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000317_16_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000317_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000317_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000317_4_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000317_5_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000317_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000317_5_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000317_4_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000317_5_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000317_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000317_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000317_15_1 & 1) != 0)
  {
    if ((sec_r000317_7_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000317_10_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000317_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000317_10_1 + 7) & 127;
  }
  if ((sec_r000317_15_2 & 1) != 0)
  {
    if ((sec_r000317_7_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000317_10_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000317_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000317_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000317_15_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000317_2_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000317_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000317_2_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000317_15_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000317_2_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000317_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000317_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000317_9_1 & 1) != 0)
  {
    if ((sec_r000317_13_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000317_15_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000317_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000317_15_1 + 7) & 127;
  }
  if ((sec_r000317_9_2 & 1) != 0)
  {
    if ((sec_r000317_13_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000317_15_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000317_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000317_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000317_0_1 & 1) != 0)
  {
    if ((sec_r000317_12_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000317_3_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000317_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000317_3_1 + 7) & 127;
  }
  if ((sec_r000317_0_2 & 1) != 0)
  {
    if ((sec_r000317_12_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000317_3_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000317_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000317_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000317_12_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000317_2_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000317_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000317_2_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000317_12_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000317_2_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000317_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000317_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((sec_r000317_12_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000317_1_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000317_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000317_1_1 + 7) & 127;
  }
  if ((stage_v_12_2 & 1) != 0)
  {
    if ((sec_r000317_12_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000317_1_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000317_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000317_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000317_0_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000317_14_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000317_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000317_14_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000317_0_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000317_14_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000317_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000317_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000317_2_1 & 1) != 0)
  {
    if ((sec_r000317_11_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000317_17_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000317_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000317_17_1 + 7) & 127;
  }
  if ((sec_r000317_2_2 & 1) != 0)
  {
    if ((sec_r000317_11_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000317_17_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000317_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000317_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000317_3_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000317_9_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000317_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000317_9_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000317_3_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000317_9_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000317_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000317_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000317_5_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000317_12_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000317_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000317_12_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000317_5_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000317_12_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000317_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000317_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000317_16_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000317_1_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000317_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000317_1_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000317_16_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000317_1_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000317_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000317_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000317_13_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000317_9_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000317_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000317_9_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000317_13_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000317_9_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000317_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000317_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000317_8_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000317_4_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000317_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000317_4_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000317_8_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000317_4_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000317_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000317_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000317_3_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000317_9_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000317_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000317_9_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000317_3_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000317_9_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000317_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000317_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000317_4_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000317_12_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000317_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000317_12_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000317_4_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000317_12_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000317_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000317_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000317_2_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000317_12_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000317_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000317_12_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000317_2_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000317_12_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000317_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000317_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000317_9_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000317_7_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000317_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000317_7_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000317_9_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000317_7_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000317_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000317_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000317_14_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000317_4_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000317_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000317_4_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000317_14_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000317_4_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000317_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000317_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000317_10_1 & 1) != 0)
  {
    if ((sec_r000317_1_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000317_8_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000317_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000317_8_1 + 7) & 127;
  }
  if ((sec_r000317_10_2 & 1) != 0)
  {
    if ((sec_r000317_1_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000317_8_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000317_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000317_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000317_8_1 & 1) != 0)
  {
    if ((sec_r000317_11_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000317_0_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000317_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000317_0_1 + 7) & 127;
  }
  if ((sec_r000317_8_2 & 1) != 0)
  {
    if ((sec_r000317_11_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000317_0_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000317_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000317_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000317_15_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000317_11_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000317_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000317_11_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000317_15_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000317_11_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000317_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000317_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000317_12_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000317_12_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000317_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000317_12_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000317_12_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000317_12_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000317_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000317_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000317_10_1 & 1) != 0)
  {
    if ((sec_r000317_12_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000317_10_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000317_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000317_10_1 + 7) & 127;
  }
  if ((sec_r000317_10_2 & 1) != 0)
  {
    if ((sec_r000317_12_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000317_10_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000317_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000317_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000317_12_1 & 1) != 0)
  {
    if ((sec_r000317_1_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000317_5_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000317_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000317_5_1 + 7) & 127;
  }
  if ((sec_r000317_12_2 & 1) != 0)
  {
    if ((sec_r000317_1_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000317_5_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000317_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000317_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000317_15_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000317_1_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000317_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000317_1_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000317_15_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000317_1_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000317_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000317_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((sec_r000317_16_1 & 1) != 0)
  {
    if ((sec_r000317_2_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000317_15_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000317_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000317_15_1 + 7) & 127;
  }
  if ((sec_r000317_16_2 & 1) != 0)
  {
    if ((sec_r000317_2_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000317_15_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000317_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000317_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r000317_2_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000317_5_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000317_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000317_5_1 + 7) & 127;
  }
  if ((stage_v_14_2 & 1) != 0)
  {
    if ((sec_r000317_2_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000317_5_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000317_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000317_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000317_17_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000317_13_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000317_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000317_13_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000317_17_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000317_13_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000317_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000317_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000317_9_1 & 1) != 0)
  {
    if ((sec_r000317_2_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000317_15_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000317_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000317_15_1 + 7) & 127;
  }
  if ((sec_r000317_9_2 & 1) != 0)
  {
    if ((sec_r000317_2_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000317_15_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000317_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000317_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000317_10_1 & 1) != 0)
  {
    if ((sec_r000317_17_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000317_11_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000317_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000317_11_1 + 7) & 127;
  }
  if ((sec_r000317_10_2 & 1) != 0)
  {
    if ((sec_r000317_17_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000317_11_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000317_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000317_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000317_13_1 != sec_r000317_13_2);
  __CPROVER_assume(pub_r000317_1_1 == pub_r000317_1_2);
  __CPROVER_assume(sec_r000317_6_1 != sec_r000317_6_2);
  __CPROVER_assume(pub_r000317_0_1 == pub_r000317_0_2);
  __CPROVER_assume(sec_r000317_17_1 != sec_r000317_17_2);
  __CPROVER_assume(sec_r000317_1_1 != sec_r000317_1_2);
  __CPROVER_assume(pub_r000317_12_1 == pub_r000317_12_2);
  __CPROVER_assume(pub_r000317_3_1 == pub_r000317_3_2);
  __CPROVER_assume(pub_r000317_7_1 == pub_r000317_7_2);
  __CPROVER_assume(sec_r000317_3_1 != sec_r000317_3_2);
  __CPROVER_assume(pub_r000317_5_1 == pub_r000317_5_2);
  __CPROVER_assume(sec_r000317_7_1 != sec_r000317_7_2);
  __CPROVER_assume(sec_r000317_11_1 != sec_r000317_11_2);
  __CPROVER_assume(sec_r000317_15_1 != sec_r000317_15_2);
  __CPROVER_assume(pub_r000317_4_1 == pub_r000317_4_2);
  __CPROVER_assume(pub_r000317_9_1 == pub_r000317_9_2);
  __CPROVER_assume(pub_r000317_16_1 == pub_r000317_16_2);
  __CPROVER_assume(pub_r000317_14_1 == pub_r000317_14_2);
  __CPROVER_assume(pub_r000317_17_1 == pub_r000317_17_2);
  __CPROVER_assume(pub_r000317_2_1 == pub_r000317_2_2);
  __CPROVER_assume(pub_r000317_6_1 == pub_r000317_6_2);
  __CPROVER_assume(sec_r000317_14_1 != sec_r000317_14_2);
  __CPROVER_assume(pub_r000317_15_1 == pub_r000317_15_2);
  __CPROVER_assume(sec_r000317_16_1 != sec_r000317_16_2);
  __CPROVER_assume(pub_r000317_13_1 == pub_r000317_13_2);
  __CPROVER_assume(sec_r000317_0_1 != sec_r000317_0_2);
  __CPROVER_assume(sec_r000317_4_1 != sec_r000317_4_2);
  __CPROVER_assume(pub_r000317_8_1 == pub_r000317_8_2);
  __CPROVER_assume(sec_r000317_2_1 != sec_r000317_2_2);
  __CPROVER_assume(sec_r000317_9_1 != sec_r000317_9_2);
  __CPROVER_assume(sec_r000317_5_1 != sec_r000317_5_2);
  __CPROVER_assume(sec_r000317_8_1 != sec_r000317_8_2);
  __CPROVER_assume(pub_r000317_11_1 == pub_r000317_11_2);
  __CPROVER_assume(pub_r000317_10_1 == pub_r000317_10_2);
  __CPROVER_assume(sec_r000317_12_1 != sec_r000317_12_2);
  __CPROVER_assume(sec_r000317_10_1 != sec_r000317_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.pitch == st_var_2_2.pitch);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.round_key == st_var_3_2.round_key);
  assert(st_var_3_1.iv == st_var_3_2.iv);
  assert(st_var_3_1.tag == st_var_3_2.tag);
  assert(st_var_3_1.flags == st_var_3_2.flags);
  assert(st_var_3_1.counter == st_var_3_2.counter);
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
}


