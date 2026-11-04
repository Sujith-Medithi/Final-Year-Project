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
struct MatrixBlock_R000927_2713_0
{
  int stride;
  unsigned char trace;
  int determinant;
  int scale;
  unsigned char dim;
  int buffer[3];
};
struct SensorNode_R000927_2713_1
{
  int status;
  short gain;
  unsigned char calib;
  short threshold;
  int buffer[3];
};
struct StreamBuffer_R000927_2713_2
{
  short state;
  int tail;
  int capacity;
  int buffer[3];
};
union PacketPayload_R000927_2713_0
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
void fn_R000927_2713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st_1 = {0};
  struct StreamBuffer_R000927_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int vector_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_45_1) & 63;
  aux_2 = (aux_2 + vector_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_16_1 = local_arr_1[aux_1 % 3];
  int sample_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_16_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_45_1 == vector_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_16_1 == sample_16_2);
}

int fn_R000927_2713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int vector_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_45) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_16 = local_arr[aux % 3];
  acc = (acc + (sample_16 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000927_2713_1 st_1 = {0};
  struct SensorNode_R000927_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_64_1 = local_arr_1[aux_1 % 3];
  int weight_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_64_2 * 2)) & 127;
  int tracker_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_73_1) & 63;
  aux_2 = (aux_2 + tracker_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_83_1)
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

  switch (tracker_83_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_64_1 == weight_64_2);
  assert(tracker_73_1 == tracker_73_2);
  assert(tracker_83_1 == tracker_83_2);
}

int fn_R000927_2713_1(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000927_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_64 = local_arr[aux % 3];
  acc = (acc + (weight_64 * 2)) & 127;
  int tracker_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_73) & 63;
  acc ^= aux;
  int tracker_83 = (aux + st.buffer[1]) & 3;
  switch (tracker_83)
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

void fn_R000927_2713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000927_2713_1 st_1 = {0};
  struct SensorNode_R000927_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int threshold_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_36_1 > 49)
  {
    acc_1 = ((acc_1 + (threshold_36_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_36_2 > 49)
  {
    acc_2 = ((acc_2 + (threshold_36_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_26_1 = 0;
  int anchor_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_26_1 = ((anchor_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_26_2 = ((anchor_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_26_1) & 127;
    acc_2 = (acc_2 + anchor_26_2) & 127;
  }

  int anchor_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_42_1) & 63;
  aux_2 = (aux_2 + anchor_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_98_1)
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

  switch (damping_98_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_36_1 == threshold_36_2);
  assert(anchor_26_1 == anchor_26_2);
  assert(anchor_42_1 == anchor_42_2);
  assert(damping_98_1 == damping_98_2);
}

int fn_R000927_2713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000927_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int threshold_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_36 > 49)
  {
    acc = ((acc + (threshold_36 * 2)) + 5) & 127;
    aux ^= threshold_36 & 15;
  }
  else
  {
    acc = ((acc - threshold_36) + 11) & 127;
    aux += 3;
  }
  int anchor_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_26 = ((anchor_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_26) & 127;
  }

  int anchor_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_42) & 63;
  acc ^= aux;
  int damping_98 = (aux + st.buffer[1]) & 3;
  switch (damping_98)
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

void fn_R000927_2713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st_1 = {0};
  struct StreamBuffer_R000927_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int bound_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_48_1 > 45)
  {
    acc_1 = ((acc_1 + (bound_48_1 * 2)) + 5) & 127;
    aux_1 ^= bound_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_48_2 > 45)
  {
    acc_2 = ((acc_2 + (bound_48_2 * 2)) + 5) & 127;
    aux_2 ^= bound_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_51_1)
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

  switch (coefficient_51_2)
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
  int coefficient_35_1 = local_arr_1[aux_1 % 3];
  int coefficient_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_35_2 * 2)) & 127;
  int checksum_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_28_1) & 63;
  aux_2 = (aux_2 + checksum_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_48_1 == bound_48_2);
  assert(coefficient_51_1 == coefficient_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_35_1 == coefficient_35_2);
  assert(checksum_28_1 == checksum_28_2);
}

int fn_R000927_2713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int bound_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_48 > 45)
  {
    acc = ((acc + (bound_48 * 2)) + 5) & 127;
    aux ^= bound_48 & 15;
  }
  else
  {
    acc = ((acc - bound_48) + 11) & 127;
    aux += 3;
  }
  int coefficient_51 = (aux + st.buffer[1]) & 3;
  switch (coefficient_51)
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
  int coefficient_35 = local_arr[aux % 3];
  acc = (acc + (coefficient_35 * 2)) & 127;
  int checksum_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_28) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000927_2713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000927_2713_1 st_1 = {0};
  struct SensorNode_R000927_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int scale_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_16_1)
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

  switch (scale_16_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_82_1 = local_arr_1[aux_1 % 3];
  int window_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_82_2 * 2)) & 127;
  int metric_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_49_1 > 42)
  {
    acc_1 = ((acc_1 + (metric_49_1 * 2)) + 5) & 127;
    aux_1 ^= metric_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_49_2 > 42)
  {
    acc_2 = ((acc_2 + (metric_49_2 * 2)) + 5) & 127;
    aux_2 ^= metric_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_49_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_16_1 == scale_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_82_1 == window_82_2);
  assert(metric_49_1 == metric_49_2);
}

int fn_R000927_2713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000927_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int scale_16 = (aux + st.buffer[1]) & 3;
  switch (scale_16)
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

  int local_arr[3] = {4, 9, 15};
  int window_82 = local_arr[aux % 3];
  acc = (acc + (window_82 * 2)) & 127;
  int metric_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_49 > 42)
  {
    acc = ((acc + (metric_49 * 2)) + 5) & 127;
    aux ^= metric_49 & 15;
  }
  else
  {
    acc = ((acc - metric_49) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000927_2713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000927_2713_0 st_1 = {0};
  struct MatrixBlock_R000927_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int sample_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_37_1)
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

  switch (sample_37_2)
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

  int factor_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_70_1) & 63;
  aux_2 = (aux_2 + factor_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_97_1 = local_arr_1[aux_1 % 3];
  int stride_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_97_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_37_1 == sample_37_2);
  assert(factor_70_1 == factor_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_97_1 == stride_97_2);
}

int fn_R000927_2713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000927_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int sample_37 = (aux + st.buffer[1]) & 3;
  switch (sample_37)
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

  int factor_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_70) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_97 = local_arr[aux % 3];
  acc = (acc + (stride_97 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000927_2713_0 st_1 = {0};
  struct MatrixBlock_R000927_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int phase_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_31_1) & 63;
  aux_2 = (aux_2 + phase_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_94_1)
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

  switch (mask_94_2)
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
  int quotient_86_1 = local_arr_1[aux_1 % 3];
  int quotient_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_31_1 == phase_31_2);
  assert(mask_94_1 == mask_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_86_1 == quotient_86_2);
}

int fn_R000927_2713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000927_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int phase_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_31) & 63;
  acc ^= aux;
  int mask_94 = (aux + st.buffer[1]) & 3;
  switch (mask_94)
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
  int quotient_86 = local_arr[aux % 3];
  acc = (acc + (quotient_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000927_2713_0 st_1 = {0};
  struct MatrixBlock_R000927_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int tracker_43_1 = 0;
  int tracker_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_43_1 = ((tracker_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_43_2 = ((tracker_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_43_1) & 127;
    acc_2 = (acc_2 + tracker_43_2) & 127;
  }

  int scale_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_26_1 > 12)
  {
    acc_1 = ((acc_1 + (scale_26_1 * 2)) + 5) & 127;
    aux_1 ^= scale_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_26_2 > 12)
  {
    acc_2 = ((acc_2 + (scale_26_2 * 2)) + 5) & 127;
    aux_2 ^= scale_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_25_1)
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

  switch (factor_25_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_43_1 == tracker_43_2);
  assert(scale_26_1 == scale_26_2);
  assert(factor_25_1 == factor_25_2);
}

int fn_R000927_2713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000927_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int tracker_43 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_43 = ((tracker_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_43) & 127;
  }

  int scale_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_26 > 12)
  {
    acc = ((acc + (scale_26 * 2)) + 5) & 127;
    aux ^= scale_26 & 15;
  }
  else
  {
    acc = ((acc - scale_26) + 11) & 127;
    aux += 3;
  }
  int factor_25 = (aux + st.buffer[1]) & 3;
  switch (factor_25)
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

void fn_R000927_2713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000927_2713_1 st_1 = {0};
  struct SensorNode_R000927_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int parity_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_73_1) & 63;
  aux_2 = (aux_2 + parity_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_11_1)
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

  switch (window_11_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_78_1 = local_arr_1[aux_1 % 3];
  int delta_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_78_2 * 2)) & 127;
  int factor_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_62_1 > 48)
  {
    acc_1 = ((acc_1 + (factor_62_1 * 2)) + 5) & 127;
    aux_1 ^= factor_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_62_2 > 48)
  {
    acc_2 = ((acc_2 + (factor_62_2 * 2)) + 5) & 127;
    aux_2 ^= factor_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_62_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_73_1 == parity_73_2);
  assert(window_11_1 == window_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_78_1 == delta_78_2);
  assert(factor_62_1 == factor_62_2);
}

int fn_R000927_2713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000927_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int parity_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_73) & 63;
  acc ^= aux;
  int window_11 = (aux + st.buffer[1]) & 3;
  switch (window_11)
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

  int local_arr[3] = {4, 9, 15};
  int delta_78 = local_arr[aux % 3];
  acc = (acc + (delta_78 * 2)) & 127;
  int factor_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_62 > 48)
  {
    acc = ((acc + (factor_62 * 2)) + 5) & 127;
    aux ^= factor_62 & 15;
  }
  else
  {
    acc = ((acc - factor_62) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000927_2713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st_1 = {0};
  struct StreamBuffer_R000927_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int stride_59_1 = 0;
  int stride_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_59_1 = ((stride_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_59_2 = ((stride_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_59_1) & 127;
    acc_2 = (acc_2 + stride_59_2) & 127;
  }

  int tracker_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_90_1) & 63;
  aux_2 = (aux_2 + tracker_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_59_1 == stride_59_2);
  assert(tracker_90_1 == tracker_90_2);
}

int fn_R000927_2713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int stride_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_59 = ((stride_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_59) & 127;
  }

  int tracker_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_90) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000927_2713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st_1 = {0};
  struct StreamBuffer_R000927_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_44_1 > 47)
  {
    acc_1 = ((acc_1 + (pivot_44_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_44_2 > 47)
  {
    acc_2 = ((acc_2 + (pivot_44_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_80_1 = local_arr_1[aux_1 % 3];
  int scale_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_44_1 == pivot_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_80_1 == scale_80_2);
}

int fn_R000927_2713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_44 > 47)
  {
    acc = ((acc + (pivot_44 * 2)) + 5) & 127;
    aux ^= pivot_44 & 15;
  }
  else
  {
    acc = ((acc - pivot_44) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int scale_80 = local_arr[aux % 3];
  acc = (acc + (scale_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st_1 = {0};
  struct StreamBuffer_R000927_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int quotient_67_1 = 0;
  int quotient_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_67_1 = ((quotient_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_67_2 = ((quotient_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_67_1) & 127;
    acc_2 = (acc_2 + quotient_67_2) & 127;
  }

  int quantum_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_43_1 > 44)
  {
    acc_1 = ((acc_1 + (quantum_43_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_43_2 > 44)
  {
    acc_2 = ((acc_2 + (quantum_43_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_81_1) & 63;
  aux_2 = (aux_2 + parity_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_67_1 == quotient_67_2);
  assert(quantum_43_1 == quantum_43_2);
  assert(parity_81_1 == parity_81_2);
}

int fn_R000927_2713_11(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int quotient_67 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_67 = ((quotient_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_67) & 127;
  }

  int quantum_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_43 > 44)
  {
    acc = ((acc + (quantum_43 * 2)) + 5) & 127;
    aux ^= quantum_43 & 15;
  }
  else
  {
    acc = ((acc - quantum_43) + 11) & 127;
    aux += 3;
  }
  int parity_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_81) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000927_2713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000927_2713_0 st_1 = {0};
  struct MatrixBlock_R000927_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int checksum_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_74_1)
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

  switch (checksum_74_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_74_1 == checksum_74_2);
}

int fn_R000927_2713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000927_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int checksum_74 = (aux + st.buffer[1]) & 3;
  switch (checksum_74)
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

void fn_R000927_2713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st_1 = {0};
  struct StreamBuffer_R000927_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_24_1)
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

  switch (scale_24_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_53_1 = local_arr_1[aux_1 % 3];
  int scale_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_53_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_24_1 == scale_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_53_1 == scale_53_2);
}

int fn_R000927_2713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_24 = (aux + st.buffer[1]) & 3;
  switch (scale_24)
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

  int local_arr[3] = {4, 9, 15};
  int scale_53 = local_arr[aux % 3];
  acc = (acc + (scale_53 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st_1 = {0};
  struct StreamBuffer_R000927_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int mask_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_61_1 > 19)
  {
    acc_1 = ((acc_1 + (mask_61_1 * 2)) + 5) & 127;
    aux_1 ^= mask_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_61_2 > 19)
  {
    acc_2 = ((acc_2 + (mask_61_2 * 2)) + 5) & 127;
    aux_2 ^= mask_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_21_1 = 0;
  int quantum_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_21_1 = ((quantum_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_21_2 = ((quantum_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_21_1) & 127;
    acc_2 = (acc_2 + quantum_21_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_61_1 == mask_61_2);
  assert(quantum_21_1 == quantum_21_2);
}

int fn_R000927_2713_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int mask_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_61 > 19)
  {
    acc = ((acc + (mask_61 * 2)) + 5) & 127;
    aux ^= mask_61 & 15;
  }
  else
  {
    acc = ((acc - mask_61) + 11) & 127;
    aux += 3;
  }
  int quantum_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_21 = ((quantum_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_21) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000927_2713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st_1 = {0};
  struct StreamBuffer_R000927_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_22_1 = local_arr_1[aux_1 % 3];
  int accumulator_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_22_2 * 2)) & 127;
  int segment_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_19_1 > 44)
  {
    acc_1 = ((acc_1 + (segment_19_1 * 2)) + 5) & 127;
    aux_1 ^= segment_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_19_2 > 44)
  {
    acc_2 = ((acc_2 + (segment_19_2 * 2)) + 5) & 127;
    aux_2 ^= segment_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_16_1)
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

  switch (anchor_16_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_22_1 == accumulator_22_2);
  assert(segment_19_1 == segment_19_2);
  assert(anchor_16_1 == anchor_16_2);
}

int fn_R000927_2713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_22 = local_arr[aux % 3];
  acc = (acc + (accumulator_22 * 2)) & 127;
  int segment_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_19 > 44)
  {
    acc = ((acc + (segment_19 * 2)) + 5) & 127;
    aux ^= segment_19 & 15;
  }
  else
  {
    acc = ((acc - segment_19) + 11) & 127;
    aux += 3;
  }
  int anchor_16 = (aux + st.buffer[1]) & 3;
  switch (anchor_16)
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

void fn_R000927_2713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st_1 = {0};
  struct StreamBuffer_R000927_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int quotient_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_75_1 > 28)
  {
    acc_1 = ((acc_1 + (quotient_75_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_75_2 > 28)
  {
    acc_2 = ((acc_2 + (quotient_75_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_98_1)
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

  switch (quantum_98_2)
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

  int delta_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_71_1) & 63;
  aux_2 = (aux_2 + delta_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_75_1 == quotient_75_2);
  assert(quantum_98_1 == quantum_98_2);
  assert(delta_71_1 == delta_71_2);
}

int fn_R000927_2713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int quotient_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_75 > 28)
  {
    acc = ((acc + (quotient_75 * 2)) + 5) & 127;
    aux ^= quotient_75 & 15;
  }
  else
  {
    acc = ((acc - quotient_75) + 11) & 127;
    aux += 3;
  }
  int quantum_98 = (aux + st.buffer[1]) & 3;
  switch (quantum_98)
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

  int delta_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_71) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000927_2713_1 st_1 = {0};
  struct SensorNode_R000927_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int checksum_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_98_1 > 21)
  {
    acc_1 = ((acc_1 + (checksum_98_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_98_2 > 21)
  {
    acc_2 = ((acc_2 + (checksum_98_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_98_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_35_1) & 63;
  aux_2 = (aux_2 + window_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_68_1)
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

  switch (anchor_68_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_98_1 == checksum_98_2);
  assert(window_35_1 == window_35_2);
  assert(anchor_68_1 == anchor_68_2);
}

int fn_R000927_2713_17(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000927_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int checksum_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_98 > 21)
  {
    acc = ((acc + (checksum_98 * 2)) + 5) & 127;
    aux ^= checksum_98 & 15;
  }
  else
  {
    acc = ((acc - checksum_98) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_35) & 63;
  acc ^= aux;
  int anchor_68 = (aux + st.buffer[1]) & 3;
  switch (anchor_68)
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

void fn_R000927_2713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000927_2713_0 st_1 = {0};
  struct MatrixBlock_R000927_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int window_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_53_1 > 24)
  {
    acc_1 = ((acc_1 + (window_53_1 * 2)) + 5) & 127;
    aux_1 ^= window_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_53_2 > 24)
  {
    acc_2 = ((acc_2 + (window_53_2 * 2)) + 5) & 127;
    aux_2 ^= window_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_53_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_44_1)
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

  switch (offset_44_2)
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

  int bound_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_64_1) & 63;
  aux_2 = (aux_2 + bound_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_29_1 = local_arr_1[aux_1 % 3];
  int mask_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_53_1 == window_53_2);
  assert(offset_44_1 == offset_44_2);
  assert(bound_64_1 == bound_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_29_1 == mask_29_2);
}

int fn_R000927_2713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000927_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int window_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_53 > 24)
  {
    acc = ((acc + (window_53 * 2)) + 5) & 127;
    aux ^= window_53 & 15;
  }
  else
  {
    acc = ((acc - window_53) + 11) & 127;
    aux += 3;
  }
  int offset_44 = (aux + st.buffer[1]) & 3;
  switch (offset_44)
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

  int bound_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_64) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int mask_29 = local_arr[aux % 3];
  acc = (acc + (mask_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000927_2713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st_1 = {0};
  struct StreamBuffer_R000927_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_81_1 = 0;
  int anchor_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_81_1 = ((anchor_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_81_2 = ((anchor_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_81_1) & 127;
    acc_2 = (acc_2 + anchor_81_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_30_1 = local_arr_1[aux_1 % 3];
  int residue_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_30_2 * 2)) & 127;
  int sample_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_88_1)
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

  switch (sample_88_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_81_1 == anchor_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_30_1 == residue_30_2);
  assert(sample_88_1 == sample_88_2);
}

int fn_R000927_2713_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000927_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_81 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_81 = ((anchor_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_81) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int residue_30 = local_arr[aux % 3];
  acc = (acc + (residue_30 * 2)) & 127;
  int sample_88 = (aux + st.buffer[1]) & 3;
  switch (sample_88)
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

void fn_R000927_2713_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000927_2713_0 st_1 = {0};
  struct MatrixBlock_R000927_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_75_1 = local_arr_1[aux_1 % 3];
  int phase_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_75_2 * 2)) & 127;
  int damping_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_91_1)
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

  switch (damping_91_2)
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

  int quotient_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_90_1 > 30)
  {
    acc_1 = ((acc_1 + (quotient_90_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_90_2 > 30)
  {
    acc_2 = ((acc_2 + (quotient_90_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_90_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_75_1 == phase_75_2);
  assert(damping_91_1 == damping_91_2);
  assert(quotient_90_1 == quotient_90_2);
}

int fn_R000927_2713_20(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000927_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int phase_75 = local_arr[aux % 3];
  acc = (acc + (phase_75 * 2)) & 127;
  int damping_91 = (aux + st.buffer[1]) & 3;
  switch (damping_91)
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

  int quotient_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_90 > 30)
  {
    acc = ((acc + (quotient_90 * 2)) + 5) & 127;
    aux ^= quotient_90 & 15;
  }
  else
  {
    acc = ((acc - quotient_90) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000927_0_1;
  int sec_r000927_0_2;
  int sec_r000927_1_1;
  int sec_r000927_1_2;
  int sec_r000927_2_1;
  int sec_r000927_2_2;
  int sec_r000927_3_1;
  int sec_r000927_3_2;
  int sec_r000927_4_1;
  int sec_r000927_4_2;
  int sec_r000927_5_1;
  int sec_r000927_5_2;
  int sec_r000927_6_1;
  int sec_r000927_6_2;
  int sec_r000927_7_1;
  int sec_r000927_7_2;
  int sec_r000927_8_1;
  int sec_r000927_8_2;
  int sec_r000927_9_1;
  int sec_r000927_9_2;
  int sec_r000927_10_1;
  int sec_r000927_10_2;
  int sec_r000927_11_1;
  int sec_r000927_11_2;
  int sec_r000927_12_1;
  int sec_r000927_12_2;
  int sec_r000927_13_1;
  int sec_r000927_13_2;
  int sec_r000927_14_1;
  int sec_r000927_14_2;
  int sec_r000927_15_1;
  int sec_r000927_15_2;
  int sec_r000927_16_1;
  int sec_r000927_16_2;
  int sec_r000927_17_1;
  int sec_r000927_17_2;
  int sec_r000927_18_1;
  int sec_r000927_18_2;
  int sec_r000927_19_1;
  int sec_r000927_19_2;
  int sec_r000927_20_1;
  int sec_r000927_20_2;
  int pub_r000927_0_1;
  int pub_r000927_0_2;
  int pub_r000927_1_1;
  int pub_r000927_1_2;
  int pub_r000927_2_1;
  int pub_r000927_2_2;
  int pub_r000927_3_1;
  int pub_r000927_3_2;
  int pub_r000927_4_1;
  int pub_r000927_4_2;
  int pub_r000927_5_1;
  int pub_r000927_5_2;
  int pub_r000927_6_1;
  int pub_r000927_6_2;
  int pub_r000927_7_1;
  int pub_r000927_7_2;
  int pub_r000927_8_1;
  int pub_r000927_8_2;
  int pub_r000927_9_1;
  int pub_r000927_9_2;
  int pub_r000927_10_1;
  int pub_r000927_10_2;
  int pub_r000927_11_1;
  int pub_r000927_11_2;
  int pub_r000927_12_1;
  int pub_r000927_12_2;
  int pub_r000927_13_1;
  int pub_r000927_13_2;
  int pub_r000927_14_1;
  int pub_r000927_14_2;
  int pub_r000927_15_1;
  int pub_r000927_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000927_0_1 >= (-100)) && (pub_r000927_0_1 <= 100));
  __CPROVER_assume((pub_r000927_0_2 >= (-100)) && (pub_r000927_0_2 <= 100));
  __CPROVER_assume((pub_r000927_1_1 >= (-100)) && (pub_r000927_1_1 <= 100));
  __CPROVER_assume((pub_r000927_1_2 >= (-100)) && (pub_r000927_1_2 <= 100));
  __CPROVER_assume((pub_r000927_2_1 >= (-100)) && (pub_r000927_2_1 <= 100));
  __CPROVER_assume((pub_r000927_2_2 >= (-100)) && (pub_r000927_2_2 <= 100));
  __CPROVER_assume((pub_r000927_3_1 >= (-100)) && (pub_r000927_3_1 <= 100));
  __CPROVER_assume((pub_r000927_3_2 >= (-100)) && (pub_r000927_3_2 <= 100));
  __CPROVER_assume((pub_r000927_4_1 >= (-100)) && (pub_r000927_4_1 <= 100));
  __CPROVER_assume((pub_r000927_4_2 >= (-100)) && (pub_r000927_4_2 <= 100));
  __CPROVER_assume((pub_r000927_5_1 >= (-100)) && (pub_r000927_5_1 <= 100));
  __CPROVER_assume((pub_r000927_5_2 >= (-100)) && (pub_r000927_5_2 <= 100));
  __CPROVER_assume((pub_r000927_6_1 >= (-100)) && (pub_r000927_6_1 <= 100));
  __CPROVER_assume((pub_r000927_6_2 >= (-100)) && (pub_r000927_6_2 <= 100));
  __CPROVER_assume((pub_r000927_7_1 >= (-100)) && (pub_r000927_7_1 <= 100));
  __CPROVER_assume((pub_r000927_7_2 >= (-100)) && (pub_r000927_7_2 <= 100));
  __CPROVER_assume((pub_r000927_8_1 >= (-100)) && (pub_r000927_8_1 <= 100));
  __CPROVER_assume((pub_r000927_8_2 >= (-100)) && (pub_r000927_8_2 <= 100));
  __CPROVER_assume((pub_r000927_9_1 >= (-100)) && (pub_r000927_9_1 <= 100));
  __CPROVER_assume((pub_r000927_9_2 >= (-100)) && (pub_r000927_9_2 <= 100));
  __CPROVER_assume((pub_r000927_10_1 >= (-100)) && (pub_r000927_10_1 <= 100));
  __CPROVER_assume((pub_r000927_10_2 >= (-100)) && (pub_r000927_10_2 <= 100));
  __CPROVER_assume((pub_r000927_11_1 >= (-100)) && (pub_r000927_11_1 <= 100));
  __CPROVER_assume((pub_r000927_11_2 >= (-100)) && (pub_r000927_11_2 <= 100));
  __CPROVER_assume((pub_r000927_12_1 >= (-100)) && (pub_r000927_12_1 <= 100));
  __CPROVER_assume((pub_r000927_12_2 >= (-100)) && (pub_r000927_12_2 <= 100));
  __CPROVER_assume((pub_r000927_13_1 >= (-100)) && (pub_r000927_13_1 <= 100));
  __CPROVER_assume((pub_r000927_13_2 >= (-100)) && (pub_r000927_13_2 <= 100));
  __CPROVER_assume((pub_r000927_14_1 >= (-100)) && (pub_r000927_14_1 <= 100));
  __CPROVER_assume((pub_r000927_14_2 >= (-100)) && (pub_r000927_14_2 <= 100));
  __CPROVER_assume((pub_r000927_15_1 >= (-100)) && (pub_r000927_15_1 <= 100));
  __CPROVER_assume((pub_r000927_15_2 >= (-100)) && (pub_r000927_15_2 <= 100));
  __CPROVER_assume((sec_r000927_0_1 >= 0) && (sec_r000927_0_1 <= 255));
  __CPROVER_assume((sec_r000927_0_2 >= 0) && (sec_r000927_0_2 <= 255));
  __CPROVER_assume((sec_r000927_1_1 >= 0) && (sec_r000927_1_1 <= 255));
  __CPROVER_assume((sec_r000927_1_2 >= 0) && (sec_r000927_1_2 <= 255));
  __CPROVER_assume((sec_r000927_2_1 >= 0) && (sec_r000927_2_1 <= 255));
  __CPROVER_assume((sec_r000927_2_2 >= 0) && (sec_r000927_2_2 <= 255));
  __CPROVER_assume((sec_r000927_3_1 >= 0) && (sec_r000927_3_1 <= 255));
  __CPROVER_assume((sec_r000927_3_2 >= 0) && (sec_r000927_3_2 <= 255));
  __CPROVER_assume((sec_r000927_4_1 >= 0) && (sec_r000927_4_1 <= 255));
  __CPROVER_assume((sec_r000927_4_2 >= 0) && (sec_r000927_4_2 <= 255));
  __CPROVER_assume((sec_r000927_5_1 >= 0) && (sec_r000927_5_1 <= 255));
  __CPROVER_assume((sec_r000927_5_2 >= 0) && (sec_r000927_5_2 <= 255));
  __CPROVER_assume((sec_r000927_6_1 >= 0) && (sec_r000927_6_1 <= 255));
  __CPROVER_assume((sec_r000927_6_2 >= 0) && (sec_r000927_6_2 <= 255));
  __CPROVER_assume((sec_r000927_7_1 >= 0) && (sec_r000927_7_1 <= 255));
  __CPROVER_assume((sec_r000927_7_2 >= 0) && (sec_r000927_7_2 <= 255));
  __CPROVER_assume((sec_r000927_8_1 >= 0) && (sec_r000927_8_1 <= 255));
  __CPROVER_assume((sec_r000927_8_2 >= 0) && (sec_r000927_8_2 <= 255));
  __CPROVER_assume((sec_r000927_9_1 >= 0) && (sec_r000927_9_1 <= 255));
  __CPROVER_assume((sec_r000927_9_2 >= 0) && (sec_r000927_9_2 <= 255));
  __CPROVER_assume((sec_r000927_10_1 >= 0) && (sec_r000927_10_1 <= 255));
  __CPROVER_assume((sec_r000927_10_2 >= 0) && (sec_r000927_10_2 <= 255));
  __CPROVER_assume((sec_r000927_11_1 >= 0) && (sec_r000927_11_1 <= 255));
  __CPROVER_assume((sec_r000927_11_2 >= 0) && (sec_r000927_11_2 <= 255));
  __CPROVER_assume((sec_r000927_12_1 >= 0) && (sec_r000927_12_1 <= 255));
  __CPROVER_assume((sec_r000927_12_2 >= 0) && (sec_r000927_12_2 <= 255));
  __CPROVER_assume((sec_r000927_13_1 >= 0) && (sec_r000927_13_1 <= 255));
  __CPROVER_assume((sec_r000927_13_2 >= 0) && (sec_r000927_13_2 <= 255));
  __CPROVER_assume((sec_r000927_14_1 >= 0) && (sec_r000927_14_1 <= 255));
  __CPROVER_assume((sec_r000927_14_2 >= 0) && (sec_r000927_14_2 <= 255));
  __CPROVER_assume((sec_r000927_15_1 >= 0) && (sec_r000927_15_1 <= 255));
  __CPROVER_assume((sec_r000927_15_2 >= 0) && (sec_r000927_15_2 <= 255));
  __CPROVER_assume((sec_r000927_16_1 >= 0) && (sec_r000927_16_1 <= 255));
  __CPROVER_assume((sec_r000927_16_2 >= 0) && (sec_r000927_16_2 <= 255));
  __CPROVER_assume((sec_r000927_17_1 >= 0) && (sec_r000927_17_1 <= 255));
  __CPROVER_assume((sec_r000927_17_2 >= 0) && (sec_r000927_17_2 <= 255));
  __CPROVER_assume((sec_r000927_18_1 >= 0) && (sec_r000927_18_1 <= 255));
  __CPROVER_assume((sec_r000927_18_2 >= 0) && (sec_r000927_18_2 <= 255));
  __CPROVER_assume((sec_r000927_19_1 >= 0) && (sec_r000927_19_1 <= 255));
  __CPROVER_assume((sec_r000927_19_2 >= 0) && (sec_r000927_19_2 <= 255));
  __CPROVER_assume((sec_r000927_20_1 >= 0) && (sec_r000927_20_1 <= 255));
  __CPROVER_assume((sec_r000927_20_2 >= 0) && (sec_r000927_20_2 <= 255));
  struct MatrixBlock_R000927_2713_0 st_var_0_1 = {0};
  struct MatrixBlock_R000927_2713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000927_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000927_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000927_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000927_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000927_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000927_0_2 + 7) & 15;
  struct SensorNode_R000927_2713_1 st_var_1_1 = {0};
  struct SensorNode_R000927_2713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000927_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000927_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000927_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000927_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000927_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000927_0_2 + 9) & 15;
  struct StreamBuffer_R000927_2713_2 st_var_2_1 = {0};
  struct StreamBuffer_R000927_2713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000927_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000927_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000927_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000927_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000927_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000927_0_2 + 11) & 15;
  union PacketPayload_R000927_2713_0 u_var_1;
  union PacketPayload_R000927_2713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 1) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 1) & 15;
  int stage_v_0_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_0_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= stage_v_0_1;
  chk_sum_2 ^= stage_v_0_2;
  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 4) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
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
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = ((st_var_2_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_2_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 54)
    {
      chk_sum_1 ^= stage_v_8_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_8_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 54)
    {
      chk_sum_2 ^= stage_v_8_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 11) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = ((st_var_2_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_2_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 48)
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
  if (stage_v_11_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 48)
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
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  switch (stage_v_16_2)
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

  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = (st_var_2_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_2_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = ((st_var_0_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_0_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 33)
    {
      chk_sum_1 ^= stage_v_21_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_21_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 33)
    {
      chk_sum_2 ^= stage_v_21_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
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
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_29_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_30_1 = ((st_var_0_1.buffer[0] * 2) + 97) & 63;
  int stage_v_30_2 = ((st_var_0_2.buffer[0] * 2) + 97) & 63;
  if (stage_v_30_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_30_1) - 5) & 255;
    if (stage_v_30_1 > 54)
    {
      chk_sum_1 ^= stage_v_30_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_30_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_30_2) - 5) & 255;
    if (stage_v_30_2 > 54)
    {
      chk_sum_2 ^= stage_v_30_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_33_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
  int stage_v_36_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_36_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 39) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  int stage_v_39_1 = ((st_var_0_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_0_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 42)
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
  if (stage_v_39_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 42)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 41) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = ((st_var_2_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_2_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 46)
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
  if (stage_v_41_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 46)
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
  int stage_v_42_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (47 & 31);
  int stage_v_42_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (47 & 31);
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= (stage_v_42_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_42_2 << 1) & 127;
  int stage_v_43_1 = table_1[3];
  int stage_v_43_2 = table_2[3];
  table_1[3] = (table_1[0] + 87) & 63;
  table_2[3] = (table_2[0] + 87) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 45) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 45) & 15;
  int stage_v_44_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_44_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= stage_v_44_1;
  chk_sum_2 ^= stage_v_44_2;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 47) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 47) & 15;
  int stage_v_46_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_46_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= stage_v_46_1;
  chk_sum_2 ^= stage_v_46_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 48) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 48) & 15;
  int stage_v_47_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_47_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= stage_v_47_1;
  chk_sum_2 ^= stage_v_47_2;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_50_1 = ((st_var_2_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_2_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 51)
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
  if (stage_v_50_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 51)
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
  int stage_v_51_1 = ((st_var_0_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_0_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 35)
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
  if (stage_v_51_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 35)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 53) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
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
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_58_1 = ((stage_v_58_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_58_2 = ((stage_v_58_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 60) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 60) & 15;
  int stage_v_59_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_59_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= stage_v_59_1;
  chk_sum_2 ^= stage_v_59_2;
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
  if (stage_v_61_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_61_1) - 5) & 255;
    if (stage_v_61_1 > 25)
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
  if (stage_v_61_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_61_2) - 5) & 255;
    if (stage_v_61_2 > 25)
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
  int stage_v_63_1 = (st_var_0_1.buffer[0] ^ 66) & 3;
  int stage_v_63_2 = (st_var_0_2.buffer[0] ^ 66) & 3;
  switch (stage_v_63_1)
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

  switch (stage_v_63_2)
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

  int stage_v_64_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (69 & 31);
  int stage_v_64_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (69 & 31);
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= (stage_v_64_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_64_2 << 1) & 127;
  int stage_v_65_1 = ((st_var_2_1.buffer[2] * 2) + 202) & 63;
  int stage_v_65_2 = ((st_var_2_2.buffer[2] * 2) + 202) & 63;
  if (stage_v_65_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_65_1) - 5) & 255;
    if (stage_v_65_1 > 28)
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
  if (stage_v_65_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_65_2) - 5) & 255;
    if (stage_v_65_2 > 28)
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
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
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
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (st_var_0_1.buffer[0] ^ 72) & 3;
  int stage_v_69_2 = (st_var_0_2.buffer[0] ^ 72) & 3;
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

  int stage_v_70_1 = table_1[2];
  int stage_v_70_2 = table_2[2];
  table_1[2] = (table_1[3] + 141) & 63;
  table_2[2] = (table_2[3] + 141) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((st_var_2_1.buffer[2] * 2) + 220) & 63;
  int stage_v_71_2 = ((st_var_2_2.buffer[2] * 2) + 220) & 63;
  if (stage_v_71_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_71_1) - 5) & 255;
    if (stage_v_71_1 > 29)
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
  if (stage_v_71_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_71_2) - 5) & 255;
    if (stage_v_71_2 > 29)
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
  int stage_v_72_1 = table_1[0];
  int stage_v_72_2 = table_2[0];
  table_1[0] = (table_1[1] + 145) & 63;
  table_2[0] = (table_2[1] + 145) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = table_1[1];
  int stage_v_73_2 = table_2[1];
  table_1[1] = (table_1[2] + 147) & 63;
  table_2[1] = (table_2[2] + 147) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (st_var_2_1.buffer[0] ^ 77) & 3;
  int stage_v_74_2 = (st_var_2_2.buffer[0] ^ 77) & 3;
  switch (stage_v_74_1)
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

  switch (stage_v_74_2)
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

  int stage_v_75_1 = ((st_var_0_1.buffer[0] * 2) + 232) & 63;
  int stage_v_75_2 = ((st_var_0_2.buffer[0] * 2) + 232) & 63;
  if (stage_v_75_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_75_1) - 5) & 255;
    if (stage_v_75_1 > 47)
    {
      chk_sum_1 ^= stage_v_75_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_75_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_75_2) - 5) & 255;
    if (stage_v_75_2 > 47)
    {
      chk_sum_2 ^= stage_v_75_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_76_1 = ((st_var_1_1.buffer[1] * 2) + 235) & 63;
  int stage_v_76_2 = ((st_var_1_2.buffer[1] * 2) + 235) & 63;
  if (stage_v_76_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_76_1) - 5) & 255;
    if (stage_v_76_1 > 41)
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
  if (stage_v_76_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_76_2) - 5) & 255;
    if (stage_v_76_2 > 41)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 78) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 78) & 15;
  int stage_v_77_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_77_2 = (st_var_2_2.buffer[2] * 3) & 63;
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
  int stage_v_79_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_79_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_79_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_79_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_80_1 = ((st_var_2_1.buffer[2] * 2) + 247) & 63;
  int stage_v_80_2 = ((st_var_2_2.buffer[2] * 2) + 247) & 63;
  if (stage_v_80_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_80_1) - 5) & 255;
    if (stage_v_80_1 > 54)
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
  if (stage_v_80_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_80_2) - 5) & 255;
    if (stage_v_80_2 > 54)
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
  int stage_v_81_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (86 & 31);
  int stage_v_81_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (86 & 31);
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  chk_sum_1 ^= (stage_v_81_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_81_2 << 1) & 127;
  int stage_v_82_1 = (st_var_1_1.buffer[0] ^ 85) & 3;
  int stage_v_82_2 = (st_var_1_2.buffer[0] ^ 85) & 3;
  switch (stage_v_82_1)
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

  switch (stage_v_82_2)
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
  int stage_v_84_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (89 & 31);
  int stage_v_84_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (89 & 31);
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  chk_sum_1 ^= (stage_v_84_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_84_2 << 1) & 127;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_85_1 = ((stage_v_85_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_85_2 = ((stage_v_85_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_86_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_87_1 = ((st_var_0_1.buffer[0] * 2) + 268) & 63;
  int stage_v_87_2 = ((st_var_0_2.buffer[0] * 2) + 268) & 63;
  if (stage_v_87_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_87_1) - 5) & 255;
    if (stage_v_87_1 > 30)
    {
      chk_sum_1 ^= stage_v_87_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_87_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_87_2) - 5) & 255;
    if (stage_v_87_2 > 30)
    {
      chk_sum_2 ^= stage_v_87_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_90_1 = (st_var_0_1.buffer[0] ^ 93) & 3;
  int stage_v_90_2 = (st_var_0_2.buffer[0] ^ 93) & 3;
  switch (stage_v_90_1)
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

  switch (stage_v_90_2)
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

  int stage_v_91_1 = table_1[3];
  int stage_v_91_2 = table_2[3];
  table_1[3] = (table_1[0] + 183) & 63;
  table_2[3] = (table_2[0] + 183) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_92_1 = ((stage_v_92_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_92_2 = ((stage_v_92_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((st_var_0_1.buffer[0] * 2) + 286) & 63;
  int stage_v_93_2 = ((st_var_0_2.buffer[0] * 2) + 286) & 63;
  if (stage_v_93_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_93_1) - 5) & 255;
    if (stage_v_93_1 > 33)
    {
      chk_sum_1 ^= stage_v_93_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_93_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_93_2) - 5) & 255;
    if (stage_v_93_2 > 33)
    {
      chk_sum_2 ^= stage_v_93_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_94_1 = ((stage_v_94_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_94_2 = ((stage_v_94_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_95_1 = ((stage_v_95_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_95_2 = ((stage_v_95_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
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
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_97_1 = ((stage_v_97_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_97_2 = ((stage_v_97_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_98_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_98_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_98_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_99_1 = ((stage_v_99_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_99_2 = ((stage_v_99_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (st_var_1_1.buffer[0] ^ 103) & 3;
  int stage_v_100_2 = (st_var_1_2.buffer[0] ^ 103) & 3;
  switch (stage_v_100_1)
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

  switch (stage_v_100_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 102) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 102) & 15;
  int stage_v_101_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_101_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  chk_sum_1 ^= stage_v_101_1;
  chk_sum_2 ^= stage_v_101_2;
  int stage_v_102_1 = table_1[2];
  int stage_v_102_2 = table_2[2];
  table_1[2] = (table_1[3] + 205) & 63;
  table_2[2] = (table_2[3] + 205) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (108 & 31);
  int stage_v_103_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (108 & 31);
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  chk_sum_1 ^= (stage_v_103_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_103_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 105) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 105) & 15;
  int stage_v_104_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_104_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  chk_sum_1 ^= stage_v_104_1;
  chk_sum_2 ^= stage_v_104_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 106) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 106) & 15;
  int stage_v_105_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_105_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= stage_v_105_1;
  chk_sum_2 ^= stage_v_105_2;
  int stage_v_106_1 = (st_var_1_1.buffer[0] ^ 109) & 3;
  int stage_v_106_2 = (st_var_1_2.buffer[0] ^ 109) & 3;
  switch (stage_v_106_1)
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

  switch (stage_v_106_2)
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

  int stage_v_107_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (112 & 31);
  int stage_v_107_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (112 & 31);
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  chk_sum_1 ^= (stage_v_107_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_107_2 << 1) & 127;
  int stage_v_108_1 = ((st_var_0_1.buffer[0] * 2) + 331) & 63;
  int stage_v_108_2 = ((st_var_0_2.buffer[0] * 2) + 331) & 63;
  if (stage_v_108_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_108_1) - 5) & 255;
    if (stage_v_108_1 > 26)
    {
      chk_sum_1 ^= stage_v_108_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_108_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_108_2) - 5) & 255;
    if (stage_v_108_2 > 26)
    {
      chk_sum_2 ^= stage_v_108_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_109_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (114 & 31);
  int stage_v_109_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (114 & 31);
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  chk_sum_1 ^= (stage_v_109_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_109_2 << 1) & 127;
  int stage_v_110_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_110_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_110_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_110_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 112) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 112) & 15;
  int stage_v_111_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_111_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  chk_sum_1 ^= stage_v_111_1;
  chk_sum_2 ^= stage_v_111_2;
  int stage_v_112_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (117 & 31);
  int stage_v_112_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (117 & 31);
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  chk_sum_1 ^= (stage_v_112_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_112_2 << 1) & 127;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_113_1 = ((stage_v_113_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_113_2 = ((stage_v_113_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = table_1[2];
  int stage_v_114_2 = table_2[2];
  table_1[2] = (table_1[3] + 229) & 63;
  table_2[2] = (table_2[3] + 229) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_115_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_115_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_115_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_116_1 = (st_var_2_1.buffer[0] ^ 119) & 3;
  int stage_v_116_2 = (st_var_2_2.buffer[0] ^ 119) & 3;
  switch (stage_v_116_1)
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

  switch (stage_v_116_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 118) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 118) & 15;
  int stage_v_117_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_117_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  chk_sum_1 ^= stage_v_117_1;
  chk_sum_2 ^= stage_v_117_2;
  int stage_v_118_1 = table_1[2];
  int stage_v_118_2 = table_2[2];
  table_1[2] = (table_1[3] + 237) & 63;
  table_2[2] = (table_2[3] + 237) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 120) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 120) & 15;
  int stage_v_119_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_119_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  chk_sum_1 ^= stage_v_119_1;
  chk_sum_2 ^= stage_v_119_2;
  int stage_v_120_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (125 & 31);
  int stage_v_120_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (125 & 31);
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  chk_sum_1 ^= (stage_v_120_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_120_2 << 1) & 127;
  int stage_v_121_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_121_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_121_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_121_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_122_1 = ((stage_v_122_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_122_2 = ((stage_v_122_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (128 & 31);
  int stage_v_123_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (128 & 31);
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  chk_sum_1 ^= (stage_v_123_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_123_2 << 1) & 127;
  int stage_v_124_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_124_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_124_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_124_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 126) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 126) & 15;
  int stage_v_125_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_125_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  chk_sum_1 ^= stage_v_125_1;
  chk_sum_2 ^= stage_v_125_2;
  int stage_v_126_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_126_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_126_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_126_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 128) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 128) & 15;
  int stage_v_127_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_127_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  chk_sum_1 ^= stage_v_127_1;
  chk_sum_2 ^= stage_v_127_2;
  int stage_v_128_1 = ((st_var_2_1.buffer[2] * 2) + 391) & 63;
  int stage_v_128_2 = ((st_var_2_2.buffer[2] * 2) + 391) & 63;
  if (stage_v_128_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_128_1) - 5) & 255;
    if (stage_v_128_1 > 41)
    {
      chk_sum_1 ^= stage_v_128_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_128_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_128_2) - 5) & 255;
    if (stage_v_128_2 > 41)
    {
      chk_sum_2 ^= stage_v_128_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_129_1 = (st_var_0_1.buffer[0] ^ 132) & 3;
  int stage_v_129_2 = (st_var_0_2.buffer[0] ^ 132) & 3;
  switch (stage_v_129_1)
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

  switch (stage_v_129_2)
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

  int stage_v_130_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_130_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_130_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_130_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_131_1 = ((stage_v_131_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_131_2 = ((stage_v_131_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (137 & 31);
  int stage_v_132_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (137 & 31);
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  chk_sum_1 ^= (stage_v_132_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_132_2 << 1) & 127;
  int stage_v_133_1 = ((st_var_1_1.buffer[1] * 2) + 406) & 63;
  int stage_v_133_2 = ((st_var_1_2.buffer[1] * 2) + 406) & 63;
  if (stage_v_133_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_133_1) - 5) & 255;
    if (stage_v_133_1 > 43)
    {
      chk_sum_1 ^= stage_v_133_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_133_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_133_2) - 5) & 255;
    if (stage_v_133_2 > 43)
    {
      chk_sum_2 ^= stage_v_133_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_134_1 = table_1[2];
  int stage_v_134_2 = table_2[2];
  table_1[2] = (table_1[3] + 269) & 63;
  table_2[2] = (table_2[3] + 269) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = table_1[3];
  int stage_v_135_2 = table_2[3];
  table_1[3] = (table_1[0] + 271) & 63;
  table_2[3] = (table_2[0] + 271) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = table_1[0];
  int stage_v_136_2 = table_2[0];
  table_1[0] = (table_1[1] + 273) & 63;
  table_2[0] = (table_2[1] + 273) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((st_var_2_1.buffer[2] * 2) + 418) & 63;
  int stage_v_137_2 = ((st_var_2_2.buffer[2] * 2) + 418) & 63;
  if (stage_v_137_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_137_1) - 5) & 255;
    if (stage_v_137_1 > 32)
    {
      chk_sum_1 ^= stage_v_137_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_137_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_137_2) - 5) & 255;
    if (stage_v_137_2 > 32)
    {
      chk_sum_2 ^= stage_v_137_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_138_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_138_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_138_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_138_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 140) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 140) & 15;
  int stage_v_139_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_139_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  chk_sum_1 ^= stage_v_139_1;
  chk_sum_2 ^= stage_v_139_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 141) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 141) & 15;
  int stage_v_140_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_140_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  chk_sum_1 ^= stage_v_140_1;
  chk_sum_2 ^= stage_v_140_2;
  int stage_v_141_1 = table_1[1];
  int stage_v_141_2 = table_2[1];
  table_1[1] = (table_1[2] + 283) & 63;
  table_2[1] = (table_2[2] + 283) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 143) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 143) & 15;
  int stage_v_142_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_142_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= stage_v_142_1;
  chk_sum_2 ^= stage_v_142_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 144) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 144) & 15;
  int stage_v_143_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_143_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  chk_sum_1 ^= stage_v_143_1;
  chk_sum_2 ^= stage_v_143_2;
  int stage_v_144_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (149 & 31);
  int stage_v_144_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (149 & 31);
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  chk_sum_1 ^= (stage_v_144_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_144_2 << 1) & 127;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_145_1 = ((stage_v_145_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_145_2 = ((stage_v_145_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 147) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 147) & 15;
  int stage_v_146_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_146_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  chk_sum_1 ^= stage_v_146_1;
  chk_sum_2 ^= stage_v_146_2;
  int stage_v_147_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_147_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_147_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_147_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_148_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_148_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_148_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_148_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_149_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (154 & 31);
  int stage_v_149_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (154 & 31);
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  chk_sum_1 ^= (stage_v_149_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_149_2 << 1) & 127;
  int stage_v_150_1 = table_1[2];
  int stage_v_150_2 = table_2[2];
  table_1[2] = (table_1[3] + 301) & 63;
  table_2[2] = (table_2[3] + 301) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = table_1[3];
  int stage_v_151_2 = table_2[3];
  table_1[3] = (table_1[0] + 303) & 63;
  table_2[3] = (table_2[0] + 303) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_152_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_153_1 = (st_var_0_1.buffer[0] ^ 156) & 3;
  int stage_v_153_2 = (st_var_0_2.buffer[0] ^ 156) & 3;
  switch (stage_v_153_1)
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

  switch (stage_v_153_2)
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

  int stage_v_154_1 = table_1[2];
  int stage_v_154_2 = table_2[2];
  table_1[2] = (table_1[3] + 309) & 63;
  table_2[2] = (table_2[3] + 309) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 156) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 156) & 15;
  int stage_v_155_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_155_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  chk_sum_1 ^= stage_v_155_1;
  chk_sum_2 ^= stage_v_155_2;
  int stage_v_156_1 = (st_var_0_1.buffer[0] ^ 159) & 3;
  int stage_v_156_2 = (st_var_0_2.buffer[0] ^ 159) & 3;
  switch (stage_v_156_1)
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

  switch (stage_v_156_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 158) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 158) & 15;
  int stage_v_157_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_157_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  chk_sum_1 ^= stage_v_157_1;
  chk_sum_2 ^= stage_v_157_2;
  int stage_v_158_1 = table_1[2];
  int stage_v_158_2 = table_2[2];
  table_1[2] = (table_1[3] + 317) & 63;
  table_2[2] = (table_2[3] + 317) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (st_var_0_1.buffer[0] ^ 162) & 3;
  int stage_v_159_2 = (st_var_0_2.buffer[0] ^ 162) & 3;
  switch (stage_v_159_1)
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

  switch (stage_v_159_2)
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

  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_160_1 = ((stage_v_160_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_160_2 = ((stage_v_160_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_161_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_161_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_161_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_162_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (167 & 31);
  int stage_v_162_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (167 & 31);
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  chk_sum_1 ^= (stage_v_162_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_162_2 << 1) & 127;
  int stage_v_163_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_163_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_163_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_163_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_164_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (169 & 31);
  int stage_v_164_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (169 & 31);
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  chk_sum_1 ^= (stage_v_164_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_164_2 << 1) & 127;
  int stage_v_165_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_165_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_165_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_165_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
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
  int stage_v_168_1 = table_1[0];
  int stage_v_168_2 = table_2[0];
  table_1[0] = (table_1[1] + 337) & 63;
  table_2[0] = (table_2[1] + 337) & 63;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_169_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_169_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_169_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_170_1 = 0;
  int stage_v_170_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_170_1 = ((stage_v_170_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_170_2 = ((stage_v_170_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_171_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_171_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_171_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_172_1 = table_1[0];
  int stage_v_172_2 = table_2[0];
  table_1[0] = (table_1[1] + 345) & 63;
  table_2[0] = (table_2[1] + 345) & 63;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_173_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_173_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_173_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_174_1 = (st_var_0_1.buffer[0] ^ 177) & 3;
  int stage_v_174_2 = (st_var_0_2.buffer[0] ^ 177) & 3;
  switch (stage_v_174_1)
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

  switch (stage_v_174_2)
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
  int stage_v_177_1 = (st_var_0_1.buffer[0] ^ 180) & 3;
  int stage_v_177_2 = (st_var_0_2.buffer[0] ^ 180) & 3;
  switch (stage_v_177_1)
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

  switch (stage_v_177_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 179) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 179) & 15;
  int stage_v_178_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_178_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  chk_sum_1 ^= stage_v_178_1;
  chk_sum_2 ^= stage_v_178_2;
  int stage_v_179_1 = table_1[3];
  int stage_v_179_2 = table_2[3];
  table_1[3] = (table_1[0] + 359) & 63;
  table_2[3] = (table_2[0] + 359) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 181) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 181) & 15;
  int stage_v_180_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_180_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  chk_sum_1 ^= stage_v_180_1;
  chk_sum_2 ^= stage_v_180_2;
  int stage_v_181_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (186 & 31);
  int stage_v_181_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (186 & 31);
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  chk_sum_1 ^= (stage_v_181_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_181_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 183) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 183) & 15;
  int stage_v_182_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_182_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  chk_sum_1 ^= stage_v_182_1;
  chk_sum_2 ^= stage_v_182_2;
  int stage_v_183_1 = table_1[3];
  int stage_v_183_2 = table_2[3];
  table_1[3] = (table_1[0] + 367) & 63;
  table_2[3] = (table_2[0] + 367) & 63;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = (st_var_1_1.buffer[0] ^ 187) & 3;
  int stage_v_184_2 = (st_var_1_2.buffer[0] ^ 187) & 3;
  switch (stage_v_184_1)
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

  switch (stage_v_184_2)
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

  int stage_v_185_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_185_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_185_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_185_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_186_1 = ((st_var_0_1.buffer[0] * 2) + 565) & 63;
  int stage_v_186_2 = ((st_var_0_2.buffer[0] * 2) + 565) & 63;
  if (stage_v_186_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_186_1) - 5) & 255;
    if (stage_v_186_1 > 51)
    {
      chk_sum_1 ^= stage_v_186_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_186_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_186_2) - 5) & 255;
    if (stage_v_186_2 > 51)
    {
      chk_sum_2 ^= stage_v_186_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_187_1 = ((st_var_1_1.buffer[1] * 2) + 568) & 63;
  int stage_v_187_2 = ((st_var_1_2.buffer[1] * 2) + 568) & 63;
  if (stage_v_187_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_187_1) - 5) & 255;
    if (stage_v_187_1 > 34)
    {
      chk_sum_1 ^= stage_v_187_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_187_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_187_2) - 5) & 255;
    if (stage_v_187_2 > 34)
    {
      chk_sum_2 ^= stage_v_187_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_188_1 = 0;
  int stage_v_188_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_188_1 = ((stage_v_188_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_188_2 = ((stage_v_188_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((st_var_0_1.buffer[0] * 2) + 574) & 63;
  int stage_v_189_2 = ((st_var_0_2.buffer[0] * 2) + 574) & 63;
  if (stage_v_189_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_189_1) - 5) & 255;
    if (stage_v_189_1 > 27)
    {
      chk_sum_1 ^= stage_v_189_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_189_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_189_2) - 5) & 255;
    if (stage_v_189_2 > 27)
    {
      chk_sum_2 ^= stage_v_189_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_190_1 = ((st_var_1_1.buffer[1] * 2) + 577) & 63;
  int stage_v_190_2 = ((st_var_1_2.buffer[1] * 2) + 577) & 63;
  if (stage_v_190_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_190_1) - 5) & 255;
    if (stage_v_190_1 > 50)
    {
      chk_sum_1 ^= stage_v_190_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_190_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_190_2) - 5) & 255;
    if (stage_v_190_2 > 50)
    {
      chk_sum_2 ^= stage_v_190_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_191_1 = 0;
  int stage_v_191_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
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
  if (stage_v_192_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_192_1) - 5) & 255;
    if (stage_v_192_1 > 33)
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
  if (stage_v_192_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_192_2) - 5) & 255;
    if (stage_v_192_2 > 33)
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
  int stage_v_193_1 = 0;
  int stage_v_193_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_193_1 = ((stage_v_193_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_193_2 = ((stage_v_193_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_194_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_194_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_194_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_195_1 = 0;
  int stage_v_195_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_195_1 = ((stage_v_195_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_195_2 = ((stage_v_195_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = 0;
  int stage_v_196_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_196_1 = ((stage_v_196_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_196_2 = ((stage_v_196_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (st_var_2_1.buffer[0] ^ 200) & 3;
  int stage_v_197_2 = (st_var_2_2.buffer[0] ^ 200) & 3;
  switch (stage_v_197_1)
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

  switch (stage_v_197_2)
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

  int m_var_1 = (sec_r000927_17_1 ^ 0x55) & 63;
  int m_var_2 = (sec_r000927_17_2 ^ 0x55) & 63;
  if (m_var_1 > 29)
  {
    out_sink_1 += ((m_var_1 * 2) + pub_r000927_1_1) & 127;
  }
  else
  {
    out_sink_1 -= (m_var_1 + 8) & 31;
  }
  if (m_var_2 > 29)
  {
    out_sink_2 += ((m_var_2 * 2) + pub_r000927_1_2) & 127;
  }
  else
  {
    out_sink_2 -= (m_var_2 + 8) & 31;
  }
  out_sink_1 ^= sec_r000927_20_1 & 15;
  out_sink_2 ^= sec_r000927_20_2 & 15;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000927_2_1 == pub_r000927_2_2);
  __CPROVER_assume(pub_r000927_15_1 == pub_r000927_15_2);
  __CPROVER_assume(sec_r000927_4_1 != sec_r000927_4_2);
  __CPROVER_assume(sec_r000927_9_1 != sec_r000927_9_2);
  __CPROVER_assume(pub_r000927_10_1 == pub_r000927_10_2);
  __CPROVER_assume(sec_r000927_14_1 != sec_r000927_14_2);
  __CPROVER_assume(sec_r000927_17_1 != sec_r000927_17_2);
  __CPROVER_assume(sec_r000927_8_1 != sec_r000927_8_2);
  __CPROVER_assume(sec_r000927_18_1 != sec_r000927_18_2);
  __CPROVER_assume(pub_r000927_14_1 == pub_r000927_14_2);
  __CPROVER_assume(sec_r000927_20_1 != sec_r000927_20_2);
  __CPROVER_assume(pub_r000927_5_1 == pub_r000927_5_2);
  __CPROVER_assume(sec_r000927_1_1 != sec_r000927_1_2);
  __CPROVER_assume(pub_r000927_0_1 == pub_r000927_0_2);
  __CPROVER_assume(sec_r000927_12_1 != sec_r000927_12_2);
  __CPROVER_assume(pub_r000927_6_1 == pub_r000927_6_2);
  __CPROVER_assume(sec_r000927_3_1 != sec_r000927_3_2);
  __CPROVER_assume(pub_r000927_1_1 == pub_r000927_1_2);
  __CPROVER_assume(pub_r000927_8_1 == pub_r000927_8_2);
  __CPROVER_assume(sec_r000927_2_1 != sec_r000927_2_2);
  __CPROVER_assume(pub_r000927_3_1 == pub_r000927_3_2);
  __CPROVER_assume(sec_r000927_0_1 != sec_r000927_0_2);
  __CPROVER_assume(pub_r000927_7_1 == pub_r000927_7_2);
  __CPROVER_assume(sec_r000927_11_1 != sec_r000927_11_2);
  __CPROVER_assume(sec_r000927_13_1 != sec_r000927_13_2);
  __CPROVER_assume(pub_r000927_12_1 == pub_r000927_12_2);
  __CPROVER_assume(sec_r000927_5_1 != sec_r000927_5_2);
  __CPROVER_assume(pub_r000927_4_1 == pub_r000927_4_2);
  __CPROVER_assume(sec_r000927_7_1 != sec_r000927_7_2);
  __CPROVER_assume(sec_r000927_10_1 != sec_r000927_10_2);
  __CPROVER_assume(sec_r000927_6_1 != sec_r000927_6_2);
  __CPROVER_assume(sec_r000927_16_1 != sec_r000927_16_2);
  __CPROVER_assume(pub_r000927_9_1 == pub_r000927_9_2);
  __CPROVER_assume(pub_r000927_11_1 == pub_r000927_11_2);
  __CPROVER_assume(sec_r000927_19_1 != sec_r000927_19_2);
  __CPROVER_assume(sec_r000927_15_1 != sec_r000927_15_2);
  __CPROVER_assume(pub_r000927_13_1 == pub_r000927_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.capacity == st_var_2_2.capacity);
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
  assert(m_var_1 == m_var_2);
}


