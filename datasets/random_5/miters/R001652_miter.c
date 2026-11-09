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
struct StreamBuffer_R001652_5213_0
{
  int tail;
  short head;
  short capacity;
  unsigned char checksum;
  int buffer[3];
};
struct SensorNode_R001652_5213_1
{
  short reading;
  int calib;
  int gain;
  int buffer[3];
};
union PacketPayload_R001652_5213_0
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
void fn_R001652_5213_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st_1 = {0};
  struct SensorNode_R001652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int checksum_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_25_1 > 33)
  {
    acc_1 = ((acc_1 + (checksum_25_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_25_2 > 33)
  {
    acc_2 = ((acc_2 + (checksum_25_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_25_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_10_1 = local_arr_1[aux_1 % 3];
  int factor_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_10_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_25_1 == checksum_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_10_1 == factor_10_2);
}

int fn_R001652_5213_0(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int checksum_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_25 > 33)
  {
    acc = ((acc + (checksum_25 * 2)) + 5) & 127;
    aux ^= checksum_25 & 15;
  }
  else
  {
    acc = ((acc - checksum_25) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_10 = local_arr[aux % 3];
  acc = (acc + (factor_10 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001652_5213_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st_1 = {0};
  struct StreamBuffer_R001652_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int window_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_55_1 > 26)
  {
    acc_1 = ((acc_1 + (window_55_1 * 2)) + 5) & 127;
    aux_1 ^= window_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_55_2 > 26)
  {
    acc_2 = ((acc_2 + (window_55_2 * 2)) + 5) & 127;
    aux_2 ^= window_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_22_1 = 0;
  int anchor_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_22_1 = ((anchor_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_22_2 = ((anchor_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_22_1) & 127;
    acc_2 = (acc_2 + anchor_22_2) & 127;
  }

  int checksum_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_72_1)
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

  switch (checksum_72_2)
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_55_1 == window_55_2);
  assert(anchor_22_1 == anchor_22_2);
  assert(checksum_72_1 == checksum_72_2);
}

int fn_R001652_5213_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int window_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_55 > 26)
  {
    acc = ((acc + (window_55 * 2)) + 5) & 127;
    aux ^= window_55 & 15;
  }
  else
  {
    acc = ((acc - window_55) + 11) & 127;
    aux += 3;
  }
  int anchor_22 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_22 = ((anchor_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_22) & 127;
  }

  int checksum_72 = (aux + st.buffer[1]) & 3;
  switch (checksum_72)
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

void fn_R001652_5213_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st_1 = {0};
  struct SensorNode_R001652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_72_1 = local_arr_1[aux_1 % 3];
  int metric_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_72_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_72_1 == metric_72_2);
}

int fn_R001652_5213_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_72 = local_arr[aux % 3];
  acc = (acc + (metric_72 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001652_5213_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st_1 = {0};
  struct SensorNode_R001652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int delta_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_51_1)
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

  switch (delta_51_2)
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
  int bound_61_1 = local_arr_1[aux_1 % 3];
  int bound_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_61_2 * 2)) & 127;
  int quotient_65_1 = 0;
  int quotient_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_65_1 = ((quotient_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_65_2 = ((quotient_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_65_1) & 127;
    acc_2 = (acc_2 + quotient_65_2) & 127;
  }

  int scale_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_64_1 > 20)
  {
    acc_1 = ((acc_1 + (scale_64_1 * 2)) + 5) & 127;
    aux_1 ^= scale_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_64_2 > 20)
  {
    acc_2 = ((acc_2 + (scale_64_2 * 2)) + 5) & 127;
    aux_2 ^= scale_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_51_1 == delta_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_61_1 == bound_61_2);
  assert(quotient_65_1 == quotient_65_2);
  assert(scale_64_1 == scale_64_2);
}

int fn_R001652_5213_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int delta_51 = (aux + st.buffer[1]) & 3;
  switch (delta_51)
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
  int bound_61 = local_arr[aux % 3];
  acc = (acc + (bound_61 * 2)) & 127;
  int quotient_65 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_65 = ((quotient_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_65) & 127;
  }

  int scale_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_64 > 20)
  {
    acc = ((acc + (scale_64 * 2)) + 5) & 127;
    aux ^= scale_64 & 15;
  }
  else
  {
    acc = ((acc - scale_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001652_5213_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st_1 = {0};
  struct StreamBuffer_R001652_5213_0 st_2 = {0};
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
  int bound_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_75_1 > 32)
  {
    acc_1 = ((acc_1 + (bound_75_1 * 2)) + 5) & 127;
    aux_1 ^= bound_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_75_2 > 32)
  {
    acc_2 = ((acc_2 + (bound_75_2 * 2)) + 5) & 127;
    aux_2 ^= bound_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_28_1)
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

  switch (quantum_28_2)
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

  int residue_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_94_1) & 63;
  aux_2 = (aux_2 + residue_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_75_1 == bound_75_2);
  assert(quantum_28_1 == quantum_28_2);
  assert(residue_94_1 == residue_94_2);
}

int fn_R001652_5213_4(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_75 > 32)
  {
    acc = ((acc + (bound_75 * 2)) + 5) & 127;
    aux ^= bound_75 & 15;
  }
  else
  {
    acc = ((acc - bound_75) + 11) & 127;
    aux += 3;
  }
  int quantum_28 = (aux + st.buffer[1]) & 3;
  switch (quantum_28)
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

  int residue_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_94) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001652_5213_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st_1 = {0};
  struct SensorNode_R001652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_76_1 = local_arr_1[aux_1 % 3];
  int margin_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_76_2 * 2)) & 127;
  int coefficient_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_53_1) & 63;
  aux_2 = (aux_2 + coefficient_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_60_1 > 30)
  {
    acc_1 = ((acc_1 + (anchor_60_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_60_2 > 30)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_76_1 == margin_76_2);
  assert(coefficient_53_1 == coefficient_53_2);
  assert(anchor_60_1 == anchor_60_2);
}

int fn_R001652_5213_5(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_76 = local_arr[aux % 3];
  acc = (acc + (margin_76 * 2)) & 127;
  int coefficient_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_53) & 63;
  acc ^= aux;
  int anchor_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_60 > 30)
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

void fn_R001652_5213_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st_1 = {0};
  struct StreamBuffer_R001652_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int stride_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_53_1 > 30)
  {
    acc_1 = ((acc_1 + (stride_53_1 * 2)) + 5) & 127;
    aux_1 ^= stride_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_53_2 > 30)
  {
    acc_2 = ((acc_2 + (stride_53_2 * 2)) + 5) & 127;
    aux_2 ^= stride_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_53_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_47_1 = local_arr_1[aux_1 % 3];
  int phase_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_47_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_79_1 = 0;
  int mask_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_79_1 = ((mask_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_79_2 = ((mask_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_79_1) & 127;
    acc_2 = (acc_2 + mask_79_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_53_1 == stride_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_47_1 == phase_47_2);
  assert(mask_79_1 == mask_79_2);
}

int fn_R001652_5213_6(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int stride_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_53 > 30)
  {
    acc = ((acc + (stride_53 * 2)) + 5) & 127;
    aux ^= stride_53 & 15;
  }
  else
  {
    acc = ((acc - stride_53) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int phase_47 = local_arr[aux % 3];
  acc = (acc + (phase_47 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_79 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_79 = ((mask_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_79) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001652_5213_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st_1 = {0};
  struct StreamBuffer_R001652_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_21_1 = local_arr_1[aux_1 % 3];
  int factor_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_21_2 * 2)) & 127;
  int window_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_29_1) & 63;
  aux_2 = (aux_2 + window_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_65_1 = 0;
  int index_reg_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_65_1 = ((index_reg_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_65_2 = ((index_reg_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_65_1) & 127;
    acc_2 = (acc_2 + index_reg_65_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_21_1 == factor_21_2);
  assert(window_29_1 == window_29_2);
  assert(index_reg_65_1 == index_reg_65_2);
}

int fn_R001652_5213_7(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int factor_21 = local_arr[aux % 3];
  acc = (acc + (factor_21 * 2)) & 127;
  int window_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_29) & 63;
  acc ^= aux;
  int index_reg_65 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_65 = ((index_reg_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_65) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001652_5213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st_1 = {0};
  struct SensorNode_R001652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int threshold_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_49_1) & 63;
  aux_2 = (aux_2 + threshold_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_53_1)
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

  switch (accumulator_53_2)
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

  int parity_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_95_1 > 20)
  {
    acc_1 = ((acc_1 + (parity_95_1 * 2)) + 5) & 127;
    aux_1 ^= parity_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_95_2 > 20)
  {
    acc_2 = ((acc_2 + (parity_95_2 * 2)) + 5) & 127;
    aux_2 ^= parity_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_95_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_49_1 == threshold_49_2);
  assert(accumulator_53_1 == accumulator_53_2);
  assert(parity_95_1 == parity_95_2);
}

int fn_R001652_5213_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int threshold_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_49) & 63;
  acc ^= aux;
  int accumulator_53 = (aux + st.buffer[1]) & 3;
  switch (accumulator_53)
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

  int parity_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_95 > 20)
  {
    acc = ((acc + (parity_95 * 2)) + 5) & 127;
    aux ^= parity_95 & 15;
  }
  else
  {
    acc = ((acc - parity_95) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001652_5213_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st_1 = {0};
  struct StreamBuffer_R001652_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int anchor_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_75_1) & 63;
  aux_2 = (aux_2 + anchor_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_20_1 = local_arr_1[aux_1 % 3];
  int segment_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_20_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_75_1 == anchor_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_20_1 == segment_20_2);
}

int fn_R001652_5213_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int anchor_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_75) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_20 = local_arr[aux % 3];
  acc = (acc + (segment_20 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001652_5213_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st_1 = {0};
  struct SensorNode_R001652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int threshold_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_11_1 > 49)
  {
    acc_1 = ((acc_1 + (threshold_11_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_11_2 > 49)
  {
    acc_2 = ((acc_2 + (threshold_11_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_83_1)
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

  switch (bound_83_2)
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

  int scale_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_57_1) & 63;
  aux_2 = (aux_2 + scale_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_11_1 == threshold_11_2);
  assert(bound_83_1 == bound_83_2);
  assert(scale_57_1 == scale_57_2);
}

int fn_R001652_5213_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int threshold_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_11 > 49)
  {
    acc = ((acc + (threshold_11 * 2)) + 5) & 127;
    aux ^= threshold_11 & 15;
  }
  else
  {
    acc = ((acc - threshold_11) + 11) & 127;
    aux += 3;
  }
  int bound_83 = (aux + st.buffer[1]) & 3;
  switch (bound_83)
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

  int scale_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_57) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001652_5213_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st_1 = {0};
  struct StreamBuffer_R001652_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_40_1 > 47)
  {
    acc_1 = ((acc_1 + (residue_40_1 * 2)) + 5) & 127;
    aux_1 ^= residue_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_40_2 > 47)
  {
    acc_2 = ((acc_2 + (residue_40_2 * 2)) + 5) & 127;
    aux_2 ^= residue_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_35_1 = 0;
  int accumulator_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_35_1 = ((accumulator_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_35_2 = ((accumulator_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_35_1) & 127;
    acc_2 = (acc_2 + accumulator_35_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_40_1 == residue_40_2);
  assert(accumulator_35_1 == accumulator_35_2);
}

int fn_R001652_5213_11(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_40 > 47)
  {
    acc = ((acc + (residue_40 * 2)) + 5) & 127;
    aux ^= residue_40 & 15;
  }
  else
  {
    acc = ((acc - residue_40) + 11) & 127;
    aux += 3;
  }
  int accumulator_35 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_35 = ((accumulator_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_35) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001652_5213_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st_1 = {0};
  struct SensorNode_R001652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_75_1 = local_arr_1[aux_1 % 3];
  int anchor_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_75_2 * 2)) & 127;
  int margin_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_80_1)
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

  switch (margin_80_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_13_1 = 0;
  int vector_13_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_13_1 = ((vector_13_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_13_2 = ((vector_13_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_13_1) & 127;
    acc_2 = (acc_2 + vector_13_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_75_1 == anchor_75_2);
  assert(margin_80_1 == margin_80_2);
  assert(vector_13_1 == vector_13_2);
}

int fn_R001652_5213_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int anchor_75 = local_arr[aux % 3];
  acc = (acc + (anchor_75 * 2)) & 127;
  int margin_80 = (aux + st.buffer[1]) & 3;
  switch (margin_80)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_13 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_13 = ((vector_13 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_13) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001652_5213_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st_1 = {0};
  struct SensorNode_R001652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_21_1 = local_arr_1[aux_1 % 3];
  int bound_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_21_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_96_1 > 48)
  {
    acc_1 = ((acc_1 + (sample_96_1 * 2)) + 5) & 127;
    aux_1 ^= sample_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_96_2 > 48)
  {
    acc_2 = ((acc_2 + (sample_96_2 * 2)) + 5) & 127;
    aux_2 ^= sample_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_70_1 = 0;
  int scale_70_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_70_1 = ((scale_70_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_70_2 = ((scale_70_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_70_1) & 127;
    acc_2 = (acc_2 + scale_70_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_21_1 == bound_21_2);
  assert(sample_96_1 == sample_96_2);
  assert(scale_70_1 == scale_70_2);
}

int fn_R001652_5213_13(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int bound_21 = local_arr[aux % 3];
  acc = (acc + (bound_21 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_96 > 48)
  {
    acc = ((acc + (sample_96 * 2)) + 5) & 127;
    aux ^= sample_96 & 15;
  }
  else
  {
    acc = ((acc - sample_96) + 11) & 127;
    aux += 3;
  }
  int scale_70 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_70 = ((scale_70 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_70) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001652_5213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st_1 = {0};
  struct SensorNode_R001652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_89_1 = local_arr_1[aux_1 % 3];
  int threshold_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_89_2 * 2)) & 127;
  int tracker_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_60_1 > 30)
  {
    acc_1 = ((acc_1 + (tracker_60_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_60_2 > 30)
  {
    acc_2 = ((acc_2 + (tracker_60_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_97_1) & 63;
  aux_2 = (aux_2 + coefficient_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_89_1 == threshold_89_2);
  assert(tracker_60_1 == tracker_60_2);
  assert(coefficient_97_1 == coefficient_97_2);
}

int fn_R001652_5213_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int threshold_89 = local_arr[aux % 3];
  acc = (acc + (threshold_89 * 2)) & 127;
  int tracker_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_60 > 30)
  {
    acc = ((acc + (tracker_60 * 2)) + 5) & 127;
    aux ^= tracker_60 & 15;
  }
  else
  {
    acc = ((acc - tracker_60) + 11) & 127;
    aux += 3;
  }
  int coefficient_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001652_5213_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st_1 = {0};
  struct StreamBuffer_R001652_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_72_1 = local_arr_1[aux_1 % 3];
  int coefficient_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_72_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_72_1 == coefficient_72_2);
}

int fn_R001652_5213_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int coefficient_72 = local_arr[aux % 3];
  acc = (acc + (coefficient_72 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001652_5213_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st_1 = {0};
  struct SensorNode_R001652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int scale_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_93_1 > 12)
  {
    acc_1 = ((acc_1 + (scale_93_1 * 2)) + 5) & 127;
    aux_1 ^= scale_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_93_2 > 12)
  {
    acc_2 = ((acc_2 + (scale_93_2 * 2)) + 5) & 127;
    aux_2 ^= scale_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_49_1)
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

  switch (factor_49_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_93_1 == scale_93_2);
  assert(factor_49_1 == factor_49_2);
}

int fn_R001652_5213_16(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int scale_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_93 > 12)
  {
    acc = ((acc + (scale_93 * 2)) + 5) & 127;
    aux ^= scale_93 & 15;
  }
  else
  {
    acc = ((acc - scale_93) + 11) & 127;
    aux += 3;
  }
  int factor_49 = (aux + st.buffer[1]) & 3;
  switch (factor_49)
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

void fn_R001652_5213_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st_1 = {0};
  struct SensorNode_R001652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_39_1) & 63;
  aux_2 = (aux_2 + metric_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_75_1 > 22)
  {
    acc_1 = ((acc_1 + (tracker_75_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_75_2 > 22)
  {
    acc_2 = ((acc_2 + (tracker_75_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_11_1 = local_arr_1[aux_1 % 3];
  int vector_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_11_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_39_1 == metric_39_2);
  assert(tracker_75_1 == tracker_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_11_1 == vector_11_2);
}

int fn_R001652_5213_17(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_39) & 63;
  acc ^= aux;
  int tracker_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_75 > 22)
  {
    acc = ((acc + (tracker_75 * 2)) + 5) & 127;
    aux ^= tracker_75 & 15;
  }
  else
  {
    acc = ((acc - tracker_75) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_11 = local_arr[aux % 3];
  acc = (acc + (vector_11 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001652_5213_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st_1 = {0};
  struct SensorNode_R001652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int metric_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_81_1)
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

  switch (metric_81_2)
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

  int damping_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_43_1) & 63;
  aux_2 = (aux_2 + damping_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_99_1 = local_arr_1[aux_1 % 3];
  int margin_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_99_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_81_1 == metric_81_2);
  assert(damping_43_1 == damping_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_99_1 == margin_99_2);
}

int fn_R001652_5213_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int metric_81 = (aux + st.buffer[1]) & 3;
  switch (metric_81)
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

  int damping_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_43) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_99 = local_arr[aux % 3];
  acc = (acc + (margin_99 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001652_5213_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st_1 = {0};
  struct StreamBuffer_R001652_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int sample_50_1 = 0;
  int sample_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_50_1 = ((sample_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_50_2 = ((sample_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_50_1) & 127;
    acc_2 = (acc_2 + sample_50_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_86_1 = local_arr_1[aux_1 % 3];
  int index_reg_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_50_1 == sample_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_86_1 == index_reg_86_2);
}

int fn_R001652_5213_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001652_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int sample_50 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_50 = ((sample_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_50) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int index_reg_86 = local_arr[aux % 3];
  acc = (acc + (index_reg_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001652_5213_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st_1 = {0};
  struct SensorNode_R001652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int vector_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_41_1) & 63;
  aux_2 = (aux_2 + vector_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_81_1 = local_arr_1[aux_1 % 3];
  int accumulator_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_81_2 * 2)) & 127;
  int quantum_23_1 = 0;
  int quantum_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_23_1 = ((quantum_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_23_2 = ((quantum_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_23_1) & 127;
    acc_2 = (acc_2 + quantum_23_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_41_1 == vector_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_81_1 == accumulator_81_2);
  assert(quantum_23_1 == quantum_23_2);
}

int fn_R001652_5213_20(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int vector_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_41) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int accumulator_81 = local_arr[aux % 3];
  acc = (acc + (accumulator_81 * 2)) & 127;
  int quantum_23 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_23 = ((quantum_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_23) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001652_0_1;
  int sec_r001652_0_2;
  int sec_r001652_1_1;
  int sec_r001652_1_2;
  int sec_r001652_2_1;
  int sec_r001652_2_2;
  int sec_r001652_3_1;
  int sec_r001652_3_2;
  int sec_r001652_4_1;
  int sec_r001652_4_2;
  int sec_r001652_5_1;
  int sec_r001652_5_2;
  int sec_r001652_6_1;
  int sec_r001652_6_2;
  int sec_r001652_7_1;
  int sec_r001652_7_2;
  int sec_r001652_8_1;
  int sec_r001652_8_2;
  int sec_r001652_9_1;
  int sec_r001652_9_2;
  int sec_r001652_10_1;
  int sec_r001652_10_2;
  int sec_r001652_11_1;
  int sec_r001652_11_2;
  int sec_r001652_12_1;
  int sec_r001652_12_2;
  int sec_r001652_13_1;
  int sec_r001652_13_2;
  int sec_r001652_14_1;
  int sec_r001652_14_2;
  int sec_r001652_15_1;
  int sec_r001652_15_2;
  int sec_r001652_16_1;
  int sec_r001652_16_2;
  int sec_r001652_17_1;
  int sec_r001652_17_2;
  int pub_r001652_0_1;
  int pub_r001652_0_2;
  int pub_r001652_1_1;
  int pub_r001652_1_2;
  int pub_r001652_2_1;
  int pub_r001652_2_2;
  int pub_r001652_3_1;
  int pub_r001652_3_2;
  int pub_r001652_4_1;
  int pub_r001652_4_2;
  int pub_r001652_5_1;
  int pub_r001652_5_2;
  int pub_r001652_6_1;
  int pub_r001652_6_2;
  int pub_r001652_7_1;
  int pub_r001652_7_2;
  int pub_r001652_8_1;
  int pub_r001652_8_2;
  int pub_r001652_9_1;
  int pub_r001652_9_2;
  int pub_r001652_10_1;
  int pub_r001652_10_2;
  int pub_r001652_11_1;
  int pub_r001652_11_2;
  int pub_r001652_12_1;
  int pub_r001652_12_2;
  int pub_r001652_13_1;
  int pub_r001652_13_2;
  int pub_r001652_14_1;
  int pub_r001652_14_2;
  int pub_r001652_15_1;
  int pub_r001652_15_2;
  int pub_r001652_16_1;
  int pub_r001652_16_2;
  int pub_r001652_17_1;
  int pub_r001652_17_2;
  int pub_r001652_18_1;
  int pub_r001652_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001652_0_1 >= (-100)) && (pub_r001652_0_1 <= 100));
  __CPROVER_assume((pub_r001652_0_2 >= (-100)) && (pub_r001652_0_2 <= 100));
  __CPROVER_assume((pub_r001652_1_1 >= (-100)) && (pub_r001652_1_1 <= 100));
  __CPROVER_assume((pub_r001652_1_2 >= (-100)) && (pub_r001652_1_2 <= 100));
  __CPROVER_assume((pub_r001652_2_1 >= (-100)) && (pub_r001652_2_1 <= 100));
  __CPROVER_assume((pub_r001652_2_2 >= (-100)) && (pub_r001652_2_2 <= 100));
  __CPROVER_assume((pub_r001652_3_1 >= (-100)) && (pub_r001652_3_1 <= 100));
  __CPROVER_assume((pub_r001652_3_2 >= (-100)) && (pub_r001652_3_2 <= 100));
  __CPROVER_assume((pub_r001652_4_1 >= (-100)) && (pub_r001652_4_1 <= 100));
  __CPROVER_assume((pub_r001652_4_2 >= (-100)) && (pub_r001652_4_2 <= 100));
  __CPROVER_assume((pub_r001652_5_1 >= (-100)) && (pub_r001652_5_1 <= 100));
  __CPROVER_assume((pub_r001652_5_2 >= (-100)) && (pub_r001652_5_2 <= 100));
  __CPROVER_assume((pub_r001652_6_1 >= (-100)) && (pub_r001652_6_1 <= 100));
  __CPROVER_assume((pub_r001652_6_2 >= (-100)) && (pub_r001652_6_2 <= 100));
  __CPROVER_assume((pub_r001652_7_1 >= (-100)) && (pub_r001652_7_1 <= 100));
  __CPROVER_assume((pub_r001652_7_2 >= (-100)) && (pub_r001652_7_2 <= 100));
  __CPROVER_assume((pub_r001652_8_1 >= (-100)) && (pub_r001652_8_1 <= 100));
  __CPROVER_assume((pub_r001652_8_2 >= (-100)) && (pub_r001652_8_2 <= 100));
  __CPROVER_assume((pub_r001652_9_1 >= (-100)) && (pub_r001652_9_1 <= 100));
  __CPROVER_assume((pub_r001652_9_2 >= (-100)) && (pub_r001652_9_2 <= 100));
  __CPROVER_assume((pub_r001652_10_1 >= (-100)) && (pub_r001652_10_1 <= 100));
  __CPROVER_assume((pub_r001652_10_2 >= (-100)) && (pub_r001652_10_2 <= 100));
  __CPROVER_assume((pub_r001652_11_1 >= (-100)) && (pub_r001652_11_1 <= 100));
  __CPROVER_assume((pub_r001652_11_2 >= (-100)) && (pub_r001652_11_2 <= 100));
  __CPROVER_assume((pub_r001652_12_1 >= (-100)) && (pub_r001652_12_1 <= 100));
  __CPROVER_assume((pub_r001652_12_2 >= (-100)) && (pub_r001652_12_2 <= 100));
  __CPROVER_assume((pub_r001652_13_1 >= (-100)) && (pub_r001652_13_1 <= 100));
  __CPROVER_assume((pub_r001652_13_2 >= (-100)) && (pub_r001652_13_2 <= 100));
  __CPROVER_assume((pub_r001652_14_1 >= (-100)) && (pub_r001652_14_1 <= 100));
  __CPROVER_assume((pub_r001652_14_2 >= (-100)) && (pub_r001652_14_2 <= 100));
  __CPROVER_assume((pub_r001652_15_1 >= (-100)) && (pub_r001652_15_1 <= 100));
  __CPROVER_assume((pub_r001652_15_2 >= (-100)) && (pub_r001652_15_2 <= 100));
  __CPROVER_assume((pub_r001652_16_1 >= (-100)) && (pub_r001652_16_1 <= 100));
  __CPROVER_assume((pub_r001652_16_2 >= (-100)) && (pub_r001652_16_2 <= 100));
  __CPROVER_assume((pub_r001652_17_1 >= (-100)) && (pub_r001652_17_1 <= 100));
  __CPROVER_assume((pub_r001652_17_2 >= (-100)) && (pub_r001652_17_2 <= 100));
  __CPROVER_assume((pub_r001652_18_1 >= (-100)) && (pub_r001652_18_1 <= 100));
  __CPROVER_assume((pub_r001652_18_2 >= (-100)) && (pub_r001652_18_2 <= 100));
  __CPROVER_assume((sec_r001652_0_1 >= 0) && (sec_r001652_0_1 <= 255));
  __CPROVER_assume((sec_r001652_0_2 >= 0) && (sec_r001652_0_2 <= 255));
  __CPROVER_assume((sec_r001652_1_1 >= 0) && (sec_r001652_1_1 <= 255));
  __CPROVER_assume((sec_r001652_1_2 >= 0) && (sec_r001652_1_2 <= 255));
  __CPROVER_assume((sec_r001652_2_1 >= 0) && (sec_r001652_2_1 <= 255));
  __CPROVER_assume((sec_r001652_2_2 >= 0) && (sec_r001652_2_2 <= 255));
  __CPROVER_assume((sec_r001652_3_1 >= 0) && (sec_r001652_3_1 <= 255));
  __CPROVER_assume((sec_r001652_3_2 >= 0) && (sec_r001652_3_2 <= 255));
  __CPROVER_assume((sec_r001652_4_1 >= 0) && (sec_r001652_4_1 <= 255));
  __CPROVER_assume((sec_r001652_4_2 >= 0) && (sec_r001652_4_2 <= 255));
  __CPROVER_assume((sec_r001652_5_1 >= 0) && (sec_r001652_5_1 <= 255));
  __CPROVER_assume((sec_r001652_5_2 >= 0) && (sec_r001652_5_2 <= 255));
  __CPROVER_assume((sec_r001652_6_1 >= 0) && (sec_r001652_6_1 <= 255));
  __CPROVER_assume((sec_r001652_6_2 >= 0) && (sec_r001652_6_2 <= 255));
  __CPROVER_assume((sec_r001652_7_1 >= 0) && (sec_r001652_7_1 <= 255));
  __CPROVER_assume((sec_r001652_7_2 >= 0) && (sec_r001652_7_2 <= 255));
  __CPROVER_assume((sec_r001652_8_1 >= 0) && (sec_r001652_8_1 <= 255));
  __CPROVER_assume((sec_r001652_8_2 >= 0) && (sec_r001652_8_2 <= 255));
  __CPROVER_assume((sec_r001652_9_1 >= 0) && (sec_r001652_9_1 <= 255));
  __CPROVER_assume((sec_r001652_9_2 >= 0) && (sec_r001652_9_2 <= 255));
  __CPROVER_assume((sec_r001652_10_1 >= 0) && (sec_r001652_10_1 <= 255));
  __CPROVER_assume((sec_r001652_10_2 >= 0) && (sec_r001652_10_2 <= 255));
  __CPROVER_assume((sec_r001652_11_1 >= 0) && (sec_r001652_11_1 <= 255));
  __CPROVER_assume((sec_r001652_11_2 >= 0) && (sec_r001652_11_2 <= 255));
  __CPROVER_assume((sec_r001652_12_1 >= 0) && (sec_r001652_12_1 <= 255));
  __CPROVER_assume((sec_r001652_12_2 >= 0) && (sec_r001652_12_2 <= 255));
  __CPROVER_assume((sec_r001652_13_1 >= 0) && (sec_r001652_13_1 <= 255));
  __CPROVER_assume((sec_r001652_13_2 >= 0) && (sec_r001652_13_2 <= 255));
  __CPROVER_assume((sec_r001652_14_1 >= 0) && (sec_r001652_14_1 <= 255));
  __CPROVER_assume((sec_r001652_14_2 >= 0) && (sec_r001652_14_2 <= 255));
  __CPROVER_assume((sec_r001652_15_1 >= 0) && (sec_r001652_15_1 <= 255));
  __CPROVER_assume((sec_r001652_15_2 >= 0) && (sec_r001652_15_2 <= 255));
  __CPROVER_assume((sec_r001652_16_1 >= 0) && (sec_r001652_16_1 <= 255));
  __CPROVER_assume((sec_r001652_16_2 >= 0) && (sec_r001652_16_2 <= 255));
  __CPROVER_assume((sec_r001652_17_1 >= 0) && (sec_r001652_17_1 <= 255));
  __CPROVER_assume((sec_r001652_17_2 >= 0) && (sec_r001652_17_2 <= 255));
  struct StreamBuffer_R001652_5213_0 st_var_0_1 = {0};
  struct StreamBuffer_R001652_5213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001652_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001652_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001652_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001652_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001652_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001652_0_2 + 7) & 15;
  struct SensorNode_R001652_5213_1 st_var_1_1 = {0};
  struct SensorNode_R001652_5213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001652_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001652_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001652_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001652_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001652_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001652_0_2 + 9) & 15;
  union PacketPayload_R001652_5213_0 u_var_1;
  union PacketPayload_R001652_5213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001652_5213_0(sec_r001652_0_1, sec_r001652_1_1);
  int helper_flow_0_2 = fn_R001652_5213_0(sec_r001652_0_2, sec_r001652_1_2);
  fn_R001652_5213_0_2(sec_r001652_0_1, sec_r001652_1_1, sec_r001652_0_2, sec_r001652_1_2);
  int helper_flow_1_1 = fn_R001652_5213_1(sec_r001652_1_1, sec_r001652_2_1, pub_r001652_3_1, pub_r001652_4_1);
  int helper_flow_1_2 = fn_R001652_5213_1(sec_r001652_1_2, sec_r001652_2_2, pub_r001652_3_2, pub_r001652_4_2);
  fn_R001652_5213_1_2(sec_r001652_1_1, sec_r001652_2_1, pub_r001652_3_1, pub_r001652_4_1, sec_r001652_1_2, sec_r001652_2_2, pub_r001652_3_2, pub_r001652_4_2);
  int helper_flow_2_1 = fn_R001652_5213_2(sec_r001652_2_1, pub_r001652_3_1, pub_r001652_4_1, pub_r001652_5_1, pub_r001652_6_1);
  int helper_flow_2_2 = fn_R001652_5213_2(sec_r001652_2_2, pub_r001652_3_2, pub_r001652_4_2, pub_r001652_5_2, pub_r001652_6_2);
  fn_R001652_5213_2_2(sec_r001652_2_1, pub_r001652_3_1, pub_r001652_4_1, pub_r001652_5_1, pub_r001652_6_1, sec_r001652_2_2, pub_r001652_3_2, pub_r001652_4_2, pub_r001652_5_2, pub_r001652_6_2);
  int stage_v_0_1 = ((pub_r001652_17_1 * 2) + 44) & 63;
  int stage_v_0_2 = ((pub_r001652_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((sec_r001652_6_1 * 3) + pub_r001652_8_1) + 9) & 127;
  int stage_v_1_2 = (((sec_r001652_6_2 * 3) + pub_r001652_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = ((pub_r001652_12_1 * 2) + 44) & 63;
  int stage_v_2_2 = ((pub_r001652_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((sec_r001652_14_1 * 3) + pub_r001652_3_1) + 14) & 127;
  int stage_v_3_2 = (((sec_r001652_14_2 * 3) + pub_r001652_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = (((sec_r001652_8_1 * 3) + pub_r001652_14_1) + 36) & 127;
  int stage_v_4_2 = (((sec_r001652_8_2 * 3) + pub_r001652_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001652_1_1 * 2) + 25) & 63;
  int stage_v_5_2 = ((pub_r001652_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001652_9_1 * 2) + 9) & 63;
  int stage_v_6_2 = ((pub_r001652_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((helper_flow_2_1 * 3) + pub_r001652_2_1) + 4) & 127;
  int stage_v_7_2 = (((helper_flow_2_2 * 3) + pub_r001652_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001652_12_1 * 2) + 13) & 63;
  int stage_v_8_2 = ((pub_r001652_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001652_11_1 * 2) + 21) & 63;
  int stage_v_9_2 = ((pub_r001652_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((sec_r001652_3_1 * 3) + pub_r001652_9_1) + 9) & 127;
  int stage_v_10_2 = (((sec_r001652_3_2 * 3) + pub_r001652_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = (((helper_flow_2_1 * 3) + pub_r001652_7_1) + 30) & 127;
  int stage_v_11_2 = (((helper_flow_2_2 * 3) + pub_r001652_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = ((pub_r001652_13_1 * 2) + 43) & 63;
  int stage_v_12_2 = ((pub_r001652_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001652_7_1 * 2) + 9) & 63;
  int stage_v_13_2 = ((pub_r001652_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001652_4_1 * 2) + 31) & 63;
  int stage_v_14_2 = ((pub_r001652_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((stage_v_1_1 * 3) + pub_r001652_18_1) + 39) & 127;
  int stage_v_15_2 = (((stage_v_1_2 * 3) + pub_r001652_18_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = ((pub_r001652_6_1 * 2) + 9) & 63;
  int stage_v_16_2 = ((pub_r001652_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((sec_r001652_14_1 * 3) + pub_r001652_16_1) + 21) & 127;
  int stage_v_17_2 = (((sec_r001652_14_2 * 3) + pub_r001652_16_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = ((pub_r001652_13_1 * 2) + 18) & 63;
  int stage_v_18_2 = ((pub_r001652_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((sec_r001652_6_1 * 3) + pub_r001652_7_1) + 30) & 127;
  int stage_v_19_2 = (((sec_r001652_6_2 * 3) + pub_r001652_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = (((stage_v_7_1 * 3) + pub_r001652_16_1) + 31) & 127;
  int stage_v_20_2 = (((stage_v_7_2 * 3) + pub_r001652_16_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = (((stage_v_3_1 * 3) + pub_r001652_4_1) + 4) & 127;
  int stage_v_21_2 = (((stage_v_3_2 * 3) + pub_r001652_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = ((pub_r001652_1_1 * 2) + 38) & 63;
  int stage_v_22_2 = ((pub_r001652_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001652_13_1 * 2) + 27) & 63;
  int stage_v_23_2 = ((pub_r001652_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001652_6_1 * 2) + 23) & 63;
  int stage_v_24_2 = ((pub_r001652_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001652_16_1 * 2) + 13) & 63;
  int stage_v_25_2 = ((pub_r001652_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001652_18_1 * 2) + 37) & 63;
  int stage_v_26_2 = ((pub_r001652_18_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001652_18_1 * 2) + 41) & 63;
  int stage_v_27_2 = ((pub_r001652_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001652_4_1 * 2) + 41) & 63;
  int stage_v_28_2 = ((pub_r001652_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001652_0_1 * 2) + 32) & 63;
  int stage_v_29_2 = ((pub_r001652_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001652_7_1 * 2) + 10) & 63;
  int stage_v_30_2 = ((pub_r001652_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001652_4_1 * 2) + 10) & 63;
  int stage_v_31_2 = ((pub_r001652_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001652_3_1 * 2) + 9) & 63;
  int stage_v_32_2 = ((pub_r001652_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((sec_r001652_13_1 * 3) + pub_r001652_8_1) + 11) & 127;
  int stage_v_33_2 = (((sec_r001652_13_2 * 3) + pub_r001652_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = (((stage_v_4_1 * 3) + pub_r001652_5_1) + 42) & 127;
  int stage_v_34_2 = (((stage_v_4_2 * 3) + pub_r001652_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = ((pub_r001652_0_1 * 2) + 26) & 63;
  int stage_v_35_2 = ((pub_r001652_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((stage_v_4_1 * 3) + pub_r001652_0_1) + 36) & 127;
  int stage_v_36_2 = (((stage_v_4_2 * 3) + pub_r001652_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = (((sec_r001652_10_1 * 3) + pub_r001652_16_1) + 34) & 127;
  int stage_v_37_2 = (((sec_r001652_10_2 * 3) + pub_r001652_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = ((pub_r001652_13_1 * 2) + 15) & 63;
  int stage_v_38_2 = ((pub_r001652_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = (((sec_r001652_11_1 * 3) + pub_r001652_7_1) + 41) & 127;
  int stage_v_39_2 = (((sec_r001652_11_2 * 3) + pub_r001652_7_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = ((pub_r001652_2_1 * 2) + 46) & 63;
  int stage_v_40_2 = ((pub_r001652_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001652_10_1 * 2) + 23) & 63;
  int stage_v_41_2 = ((pub_r001652_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (((helper_flow_1_1 * 3) + pub_r001652_6_1) + 12) & 127;
  int stage_v_42_2 = (((helper_flow_1_2 * 3) + pub_r001652_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = ((pub_r001652_17_1 * 2) + 14) & 63;
  int stage_v_43_2 = ((pub_r001652_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((sec_r001652_12_1 * 3) + pub_r001652_15_1) + 22) & 127;
  int stage_v_44_2 = (((sec_r001652_12_2 * 3) + pub_r001652_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = ((pub_r001652_11_1 * 2) + 46) & 63;
  int stage_v_45_2 = ((pub_r001652_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001652_7_1 * 2) + 39) & 63;
  int stage_v_46_2 = ((pub_r001652_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((sec_r001652_12_1 * 3) + pub_r001652_15_1) + 45) & 127;
  int stage_v_47_2 = (((sec_r001652_12_2 * 3) + pub_r001652_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = ((pub_r001652_9_1 * 2) + 13) & 63;
  int stage_v_48_2 = ((pub_r001652_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((sec_r001652_2_1 * 3) + pub_r001652_15_1) + 13) & 127;
  int stage_v_49_2 = (((sec_r001652_2_2 * 3) + pub_r001652_15_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = (((sec_r001652_0_1 * 3) + pub_r001652_8_1) + 19) & 127;
  int stage_v_50_2 = (((sec_r001652_0_2 * 3) + pub_r001652_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = ((pub_r001652_11_1 * 2) + 46) & 63;
  int stage_v_51_2 = ((pub_r001652_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((stage_v_1_1 * 3) + pub_r001652_18_1) + 33) & 127;
  int stage_v_52_2 = (((stage_v_1_2 * 3) + pub_r001652_18_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = ((pub_r001652_17_1 * 2) + 37) & 63;
  int stage_v_53_2 = ((pub_r001652_17_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001652_17_1 * 2) + 34) & 63;
  int stage_v_54_2 = ((pub_r001652_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001652_1_1 * 2) + 26) & 63;
  int stage_v_55_2 = ((pub_r001652_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (((sec_r001652_8_1 * 3) + pub_r001652_2_1) + 23) & 127;
  int stage_v_56_2 = (((sec_r001652_8_2 * 3) + pub_r001652_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = ((pub_r001652_5_1 * 2) + 46) & 63;
  int stage_v_57_2 = ((pub_r001652_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001652_8_1 * 2) + 33) & 63;
  int stage_v_58_2 = ((pub_r001652_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (((sec_r001652_4_1 * 3) + pub_r001652_4_1) + 35) & 127;
  int stage_v_59_2 = (((sec_r001652_4_2 * 3) + pub_r001652_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = (((sec_r001652_9_1 * 3) + pub_r001652_9_1) + 35) & 127;
  int stage_v_60_2 = (((sec_r001652_9_2 * 3) + pub_r001652_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((sec_r001652_14_1 * 3) + pub_r001652_14_1) + 11) & 127;
  int stage_v_61_2 = (((sec_r001652_14_2 * 3) + pub_r001652_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001652_0_1 * 2) + 13) & 63;
  int stage_v_62_2 = ((pub_r001652_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001652_18_1 * 2) + 7) & 63;
  int stage_v_63_2 = ((pub_r001652_18_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001652_6_1 * 2) + 22) & 63;
  int stage_v_64_2 = ((pub_r001652_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001652_13_1 * 2) + 41) & 63;
  int stage_v_65_2 = ((pub_r001652_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001652_5_1 * 2) + 12) & 63;
  int stage_v_66_2 = ((pub_r001652_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001652_4_1 * 2) + 35) & 63;
  int stage_v_67_2 = ((pub_r001652_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001652_7_1 * 2) + 29) & 63;
  int stage_v_68_2 = ((pub_r001652_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001652_14_1 * 2) + 11) & 63;
  int stage_v_69_2 = ((pub_r001652_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001652_9_1 * 2) + 15) & 63;
  int stage_v_70_2 = ((pub_r001652_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001652_13_1 * 2) + 42) & 63;
  int stage_v_71_2 = ((pub_r001652_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001652_4_1 * 2) + 18) & 63;
  int stage_v_72_2 = ((pub_r001652_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001652_1_1 * 2) + 18) & 63;
  int stage_v_73_2 = ((pub_r001652_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001652_2_1 * 2) + 15) & 63;
  int stage_v_74_2 = ((pub_r001652_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001652_13_1 * 2) + 5) & 63;
  int stage_v_75_2 = ((pub_r001652_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001652_12_1 * 2) + 31) & 63;
  int stage_v_76_2 = ((pub_r001652_12_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001652_13_1 * 2) + 44) & 63;
  int stage_v_77_2 = ((pub_r001652_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001652_6_1 * 2) + 33) & 63;
  int stage_v_78_2 = ((pub_r001652_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((stage_v_61_1 * 3) + pub_r001652_11_1) + 27) & 127;
  int stage_v_79_2 = (((stage_v_61_2 * 3) + pub_r001652_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = ((pub_r001652_12_1 * 2) + 7) & 63;
  int stage_v_80_2 = ((pub_r001652_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001652_7_1 * 2) + 46) & 63;
  int stage_v_81_2 = ((pub_r001652_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001652_2_1 * 2) + 40) & 63;
  int stage_v_82_2 = ((pub_r001652_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001652_13_1 * 2) + 22) & 63;
  int stage_v_83_2 = ((pub_r001652_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((sec_r001652_11_1 * 3) + pub_r001652_6_1) + 22) & 127;
  int stage_v_84_2 = (((sec_r001652_11_2 * 3) + pub_r001652_6_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = ((pub_r001652_3_1 * 2) + 24) & 63;
  int stage_v_85_2 = ((pub_r001652_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001652_3_1 * 2) + 5) & 63;
  int stage_v_86_2 = ((pub_r001652_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001652_2_1 * 2) + 33) & 63;
  int stage_v_87_2 = ((pub_r001652_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((stage_v_21_1 * 3) + pub_r001652_16_1) + 32) & 127;
  int stage_v_88_2 = (((stage_v_21_2 * 3) + pub_r001652_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = (((stage_v_33_1 * 3) + pub_r001652_15_1) + 24) & 127;
  int stage_v_89_2 = (((stage_v_33_2 * 3) + pub_r001652_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = ((pub_r001652_8_1 * 2) + 38) & 63;
  int stage_v_90_2 = ((pub_r001652_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = (((stage_v_7_1 * 3) + pub_r001652_9_1) + 27) & 127;
  int stage_v_91_2 = (((stage_v_7_2 * 3) + pub_r001652_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = (((stage_v_49_1 * 3) + pub_r001652_17_1) + 7) & 127;
  int stage_v_92_2 = (((stage_v_49_2 * 3) + pub_r001652_17_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = (((sec_r001652_12_1 * 3) + pub_r001652_17_1) + 19) & 127;
  int stage_v_93_2 = (((sec_r001652_12_2 * 3) + pub_r001652_17_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = ((pub_r001652_0_1 * 2) + 48) & 63;
  int stage_v_94_2 = ((pub_r001652_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001652_3_1 * 2) + 19) & 63;
  int stage_v_95_2 = ((pub_r001652_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((stage_v_20_1 * 3) + pub_r001652_14_1) + 18) & 127;
  int stage_v_96_2 = (((stage_v_20_2 * 3) + pub_r001652_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = ((pub_r001652_11_1 * 2) + 34) & 63;
  int stage_v_97_2 = ((pub_r001652_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((sec_r001652_0_1 * 3) + pub_r001652_3_1) + 17) & 127;
  int stage_v_98_2 = (((sec_r001652_0_2 * 3) + pub_r001652_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = ((pub_r001652_16_1 * 2) + 26) & 63;
  int stage_v_99_2 = ((pub_r001652_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001652_5_1 * 2) + 44) & 63;
  int stage_v_100_2 = ((pub_r001652_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_91_1 * 3) + pub_r001652_5_1) + 6) & 127;
  int stage_v_101_2 = (((stage_v_91_2 * 3) + pub_r001652_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001652_12_1 * 2) + 48) & 63;
  int stage_v_102_2 = ((pub_r001652_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((helper_flow_0_1 * 3) + pub_r001652_15_1) + 19) & 127;
  int stage_v_103_2 = (((helper_flow_0_2 * 3) + pub_r001652_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = (((stage_v_61_1 * 3) + pub_r001652_1_1) + 32) & 127;
  int stage_v_104_2 = (((stage_v_61_2 * 3) + pub_r001652_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001652_10_1 * 2) + 49) & 63;
  int stage_v_105_2 = ((pub_r001652_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((stage_v_4_1 * 3) + pub_r001652_8_1) + 43) & 127;
  int stage_v_106_2 = (((stage_v_4_2 * 3) + pub_r001652_8_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = ((pub_r001652_1_1 * 2) + 22) & 63;
  int stage_v_107_2 = ((pub_r001652_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001652_11_1 * 2) + 42) & 63;
  int stage_v_108_2 = ((pub_r001652_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001652_15_1 * 2) + 34) & 63;
  int stage_v_109_2 = ((pub_r001652_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001652_13_1 * 2) + 45) & 63;
  int stage_v_110_2 = ((pub_r001652_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001652_12_1 * 2) + 9) & 63;
  int stage_v_111_2 = ((pub_r001652_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001652_4_1 * 2) + 32) & 63;
  int stage_v_112_2 = ((pub_r001652_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((sec_r001652_5_1 * 3) + pub_r001652_13_1) + 17) & 127;
  int stage_v_113_2 = (((sec_r001652_5_2 * 3) + pub_r001652_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = ((pub_r001652_5_1 * 2) + 43) & 63;
  int stage_v_114_2 = ((pub_r001652_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = (((stage_v_60_1 * 3) + pub_r001652_7_1) + 38) & 127;
  int stage_v_115_2 = (((stage_v_60_2 * 3) + pub_r001652_7_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = ((pub_r001652_3_1 * 2) + 49) & 63;
  int stage_v_116_2 = ((pub_r001652_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001652_14_1 * 2) + 22) & 63;
  int stage_v_117_2 = ((pub_r001652_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((sec_r001652_7_1 * 3) + pub_r001652_10_1) + 45) & 127;
  int stage_v_118_2 = (((sec_r001652_7_2 * 3) + pub_r001652_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = ((pub_r001652_3_1 * 2) + 38) & 63;
  int stage_v_119_2 = ((pub_r001652_3_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((sec_r001652_1_1 * 3) + pub_r001652_2_1) + 15) & 127;
  int stage_v_120_2 = (((sec_r001652_1_2 * 3) + pub_r001652_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = (((stage_v_113_1 * 3) + pub_r001652_11_1) + 31) & 127;
  int stage_v_121_2 = (((stage_v_113_2 * 3) + pub_r001652_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = ((pub_r001652_9_1 * 2) + 12) & 63;
  int stage_v_122_2 = ((pub_r001652_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001652_1_1 * 2) + 35) & 63;
  int stage_v_123_2 = ((pub_r001652_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001652_15_1 * 2) + 6) & 63;
  int stage_v_124_2 = ((pub_r001652_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (((sec_r001652_2_1 * 3) + pub_r001652_2_1) + 21) & 127;
  int stage_v_125_2 = (((sec_r001652_2_2 * 3) + pub_r001652_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = ((pub_r001652_4_1 * 2) + 49) & 63;
  int stage_v_126_2 = ((pub_r001652_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001652_10_1 * 2) + 21) & 63;
  int stage_v_127_2 = ((pub_r001652_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001652_3_1 * 2) + 25) & 63;
  int stage_v_128_2 = ((pub_r001652_3_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001652_12_1 * 2) + 35) & 63;
  int stage_v_129_2 = ((pub_r001652_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001652_17_1 * 2) + 34) & 63;
  int stage_v_130_2 = ((pub_r001652_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((stage_v_88_1 * 3) + pub_r001652_2_1) + 35) & 127;
  int stage_v_131_2 = (((stage_v_88_2 * 3) + pub_r001652_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = ((pub_r001652_8_1 * 2) + 45) & 63;
  int stage_v_132_2 = ((pub_r001652_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001652_16_1 * 2) + 30) & 63;
  int stage_v_133_2 = ((pub_r001652_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001652_17_1 * 2) + 25) & 63;
  int stage_v_134_2 = ((pub_r001652_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001652_13_1 * 2) + 13) & 63;
  int stage_v_135_2 = ((pub_r001652_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001652_10_1 * 2) + 46) & 63;
  int stage_v_136_2 = ((pub_r001652_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001652_8_1 * 2) + 11) & 63;
  int stage_v_137_2 = ((pub_r001652_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001652_11_1 * 2) + 15) & 63;
  int stage_v_138_2 = ((pub_r001652_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001652_17_1 * 2) + 34) & 63;
  int stage_v_139_2 = ((pub_r001652_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001652_16_1 * 2) + 21) & 63;
  int stage_v_140_2 = ((pub_r001652_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001652_5_1 * 2) + 22) & 63;
  int stage_v_141_2 = ((pub_r001652_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001652_10_1 * 2) + 12) & 63;
  int stage_v_142_2 = ((pub_r001652_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (((stage_v_118_1 * 3) + pub_r001652_1_1) + 11) & 127;
  int stage_v_143_2 = (((stage_v_118_2 * 3) + pub_r001652_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = (((sec_r001652_11_1 * 3) + pub_r001652_13_1) + 19) & 127;
  int stage_v_144_2 = (((sec_r001652_11_2 * 3) + pub_r001652_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((stage_v_3_1 * 3) + pub_r001652_13_1) + 11) & 127;
  int stage_v_145_2 = (((stage_v_3_2 * 3) + pub_r001652_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001652_9_1 * 2) + 6) & 63;
  int stage_v_146_2 = ((pub_r001652_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((stage_v_106_1 * 3) + pub_r001652_5_1) + 24) & 127;
  int stage_v_147_2 = (((stage_v_106_2 * 3) + pub_r001652_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = ((pub_r001652_16_1 * 2) + 19) & 63;
  int stage_v_148_2 = ((pub_r001652_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001652_14_1 * 2) + 38) & 63;
  int stage_v_149_2 = ((pub_r001652_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001652_6_1 * 2) + 45) & 63;
  int stage_v_150_2 = ((pub_r001652_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001652_7_1 * 2) + 18) & 63;
  int stage_v_151_2 = ((pub_r001652_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001652_13_1 * 2) + 30) & 63;
  int stage_v_152_2 = ((pub_r001652_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001652_14_1 * 2) + 49) & 63;
  int stage_v_153_2 = ((pub_r001652_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((stage_v_50_1 * 3) + pub_r001652_17_1) + 43) & 127;
  int stage_v_154_2 = (((stage_v_50_2 * 3) + pub_r001652_17_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = ((pub_r001652_11_1 * 2) + 13) & 63;
  int stage_v_155_2 = ((pub_r001652_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001652_4_1 * 2) + 48) & 63;
  int stage_v_156_2 = ((pub_r001652_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001652_13_1 * 2) + 34) & 63;
  int stage_v_157_2 = ((pub_r001652_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001652_6_1 * 2) + 49) & 63;
  int stage_v_158_2 = ((pub_r001652_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001652_1_1 * 2) + 10) & 63;
  int stage_v_159_2 = ((pub_r001652_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001652_17_1 * 2) + 26) & 63;
  int stage_v_160_2 = ((pub_r001652_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001652_3_1 * 2) + 14) & 63;
  int stage_v_161_2 = ((pub_r001652_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001652_8_1 * 2) + 32) & 63;
  int stage_v_162_2 = ((pub_r001652_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001652_6_1 * 2) + 20) & 63;
  int stage_v_163_2 = ((pub_r001652_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001652_16_1 * 2) + 33) & 63;
  int stage_v_164_2 = ((pub_r001652_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001652_10_1 * 2) + 6) & 63;
  int stage_v_165_2 = ((pub_r001652_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001652_16_1 * 2) + 23) & 63;
  int stage_v_166_2 = ((pub_r001652_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001652_0_1 * 2) + 6) & 63;
  int stage_v_167_2 = ((pub_r001652_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001652_11_1 * 2) + 49) & 63;
  int stage_v_168_2 = ((pub_r001652_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001652_8_1 * 2) + 39) & 63;
  int stage_v_169_2 = ((pub_r001652_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001652_14_1 * 2) + 48) & 63;
  int stage_v_170_2 = ((pub_r001652_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001652_2_1 * 2) + 34) & 63;
  int stage_v_171_2 = ((pub_r001652_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((sec_r001652_0_1 * 3) + pub_r001652_17_1) + 37) & 127;
  int stage_v_172_2 = (((sec_r001652_0_2 * 3) + pub_r001652_17_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = ((pub_r001652_15_1 * 2) + 12) & 63;
  int stage_v_173_2 = ((pub_r001652_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (((stage_v_37_1 * 3) + pub_r001652_14_1) + 9) & 127;
  int stage_v_174_2 = (((stage_v_37_2 * 3) + pub_r001652_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = ((pub_r001652_17_1 * 2) + 6) & 63;
  int stage_v_175_2 = ((pub_r001652_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_39_1 * 3) + pub_r001652_7_1) + 19) & 127;
  int stage_v_176_2 = (((stage_v_39_2 * 3) + pub_r001652_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = (((stage_v_91_1 * 3) + pub_r001652_3_1) + 26) & 127;
  int stage_v_177_2 = (((stage_v_91_2 * 3) + pub_r001652_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = (((stage_v_154_1 * 3) + pub_r001652_8_1) + 9) & 127;
  int stage_v_178_2 = (((stage_v_154_2 * 3) + pub_r001652_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = ((pub_r001652_2_1 * 2) + 14) & 63;
  int stage_v_179_2 = ((pub_r001652_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001652_10_1 * 2) + 40) & 63;
  int stage_v_180_2 = ((pub_r001652_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((stage_v_96_1 * 3) + pub_r001652_2_1) + 43) & 127;
  int stage_v_181_2 = (((stage_v_96_2 * 3) + pub_r001652_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = ((pub_r001652_6_1 * 2) + 24) & 63;
  int stage_v_182_2 = ((pub_r001652_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001652_5_1 * 2) + 15) & 63;
  int stage_v_183_2 = ((pub_r001652_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (((stage_v_104_1 * 3) + pub_r001652_7_1) + 33) & 127;
  int stage_v_184_2 = (((stage_v_104_2 * 3) + pub_r001652_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = (((stage_v_47_1 * 3) + pub_r001652_5_1) + 14) & 127;
  int stage_v_185_2 = (((stage_v_47_2 * 3) + pub_r001652_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = ((pub_r001652_1_1 * 2) + 38) & 63;
  int stage_v_186_2 = ((pub_r001652_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001652_3_1 * 2) + 34) & 63;
  int stage_v_187_2 = ((pub_r001652_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001652_9_1 * 2) + 24) & 63;
  int stage_v_188_2 = ((pub_r001652_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((sec_r001652_17_1 * 3) + pub_r001652_2_1) + 45) & 127;
  int stage_v_189_2 = (((sec_r001652_17_2 * 3) + pub_r001652_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = ((pub_r001652_10_1 * 2) + 39) & 63;
  int stage_v_190_2 = ((pub_r001652_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001652_11_1 * 2) + 47) & 63;
  int stage_v_191_2 = ((pub_r001652_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001652_17_1 * 2) + 9) & 63;
  int stage_v_192_2 = ((pub_r001652_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((sec_r001652_7_1 * 3) + pub_r001652_8_1) + 4) & 127;
  int stage_v_193_2 = (((sec_r001652_7_2 * 3) + pub_r001652_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = (((stage_v_189_1 * 3) + pub_r001652_0_1) + 42) & 127;
  int stage_v_194_2 = (((stage_v_189_2 * 3) + pub_r001652_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = ((pub_r001652_9_1 * 2) + 16) & 63;
  int stage_v_195_2 = ((pub_r001652_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((stage_v_10_1 * 3) + pub_r001652_1_1) + 6) & 127;
  int stage_v_196_2 = (((stage_v_10_2 * 3) + pub_r001652_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = ((pub_r001652_8_1 * 2) + 6) & 63;
  int stage_v_197_2 = ((pub_r001652_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_145_1 * 3) + pub_r001652_8_1) + 28) & 127;
  int stage_v_198_2 = (((stage_v_145_2 * 3) + pub_r001652_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001652_13_1 * 2) + 10) & 63;
  int stage_v_199_2 = ((pub_r001652_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001652_16_1 * 2) + 42) & 63;
  int stage_v_200_2 = ((pub_r001652_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001652_3_1 * 2) + 19) & 63;
  int stage_v_201_2 = ((pub_r001652_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001652_3_1 * 2) + 39) & 63;
  int stage_v_202_2 = ((pub_r001652_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001652_3_1 * 2) + 20) & 63;
  int stage_v_203_2 = ((pub_r001652_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001652_4_1 * 2) + 41) & 63;
  int stage_v_204_2 = ((pub_r001652_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((sec_r001652_0_1 * 3) + pub_r001652_16_1) + 9) & 127;
  int stage_v_205_2 = (((sec_r001652_0_2 * 3) + pub_r001652_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = ((pub_r001652_2_1 * 2) + 43) & 63;
  int stage_v_206_2 = ((pub_r001652_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001652_16_1 * 2) + 14) & 63;
  int stage_v_207_2 = ((pub_r001652_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001652_11_1 * 2) + 25) & 63;
  int stage_v_208_2 = ((pub_r001652_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001652_4_1 * 2) + 7) & 63;
  int stage_v_209_2 = ((pub_r001652_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001652_13_1 * 2) + 46) & 63;
  int stage_v_210_2 = ((pub_r001652_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001652_2_1 * 2) + 22) & 63;
  int stage_v_211_2 = ((pub_r001652_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = (((stage_v_125_1 * 3) + pub_r001652_4_1) + 25) & 127;
  int stage_v_212_2 = (((stage_v_125_2 * 3) + pub_r001652_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = (((stage_v_185_1 * 3) + pub_r001652_1_1) + 39) & 127;
  int stage_v_213_2 = (((stage_v_185_2 * 3) + pub_r001652_1_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = (((helper_flow_0_1 * 3) + pub_r001652_13_1) + 9) & 127;
  int stage_v_214_2 = (((helper_flow_0_2 * 3) + pub_r001652_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = ((pub_r001652_0_1 * 2) + 32) & 63;
  int stage_v_215_2 = ((pub_r001652_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001652_5_1 * 2) + 17) & 63;
  int stage_v_216_2 = ((pub_r001652_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001652_8_1 * 2) + 28) & 63;
  int stage_v_217_2 = ((pub_r001652_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = (((stage_v_52_1 * 3) + pub_r001652_3_1) + 22) & 127;
  int stage_v_218_2 = (((stage_v_52_2 * 3) + pub_r001652_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = ((pub_r001652_11_1 * 2) + 10) & 63;
  int stage_v_219_2 = ((pub_r001652_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001652_6_1 * 2) + 30) & 63;
  int stage_v_220_2 = ((pub_r001652_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001652_4_1 * 2) + 49) & 63;
  int stage_v_221_2 = ((pub_r001652_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = (((sec_r001652_11_1 * 3) + pub_r001652_3_1) + 45) & 127;
  int stage_v_222_2 = (((sec_r001652_11_2 * 3) + pub_r001652_3_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001652_6_1 * 2) + 30) & 63;
  int stage_v_223_2 = ((pub_r001652_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001652_9_1 * 2) + 50) & 63;
  int stage_v_224_2 = ((pub_r001652_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001652_12_1 * 2) + 31) & 63;
  int stage_v_225_2 = ((pub_r001652_12_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001652_9_1 * 2) + 6) & 63;
  int stage_v_226_2 = ((pub_r001652_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = (((stage_v_172_1 * 3) + pub_r001652_3_1) + 35) & 127;
  int stage_v_227_2 = (((stage_v_172_2 * 3) + pub_r001652_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = ((pub_r001652_4_1 * 2) + 23) & 63;
  int stage_v_228_2 = ((pub_r001652_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001652_0_1 * 2) + 36) & 63;
  int stage_v_229_2 = ((pub_r001652_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001652_1_1 * 2) + 33) & 63;
  int stage_v_230_2 = ((pub_r001652_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001652_6_1 * 2) + 16) & 63;
  int stage_v_231_2 = ((pub_r001652_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001652_6_1 * 2) + 10) & 63;
  int stage_v_232_2 = ((pub_r001652_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001652_12_1 * 2) + 21) & 63;
  int stage_v_233_2 = ((pub_r001652_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = (((stage_v_185_1 * 3) + pub_r001652_4_1) + 16) & 127;
  int stage_v_234_2 = (((stage_v_185_2 * 3) + pub_r001652_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = (((stage_v_36_1 * 3) + pub_r001652_4_1) + 8) & 127;
  int stage_v_235_2 = (((stage_v_36_2 * 3) + pub_r001652_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = ((pub_r001652_12_1 * 2) + 17) & 63;
  int stage_v_236_2 = ((pub_r001652_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001652_5_1 * 2) + 22) & 63;
  int stage_v_237_2 = ((pub_r001652_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001652_10_1 * 2) + 33) & 63;
  int stage_v_238_2 = ((pub_r001652_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = (((stage_v_154_1 * 3) + pub_r001652_17_1) + 29) & 127;
  int stage_v_239_2 = (((stage_v_154_2 * 3) + pub_r001652_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = (((sec_r001652_14_1 * 3) + pub_r001652_0_1) + 25) & 127;
  int stage_v_240_2 = (((sec_r001652_14_2 * 3) + pub_r001652_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((helper_flow_2_1 * 3) + pub_r001652_9_1) + 25) & 127;
  int stage_v_241_2 = (((helper_flow_2_2 * 3) + pub_r001652_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = ((pub_r001652_8_1 * 2) + 19) & 63;
  int stage_v_242_2 = ((pub_r001652_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((pub_r001652_12_1 * 2) + 27) & 63;
  int stage_v_243_2 = ((pub_r001652_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((pub_r001652_4_1 * 2) + 39) & 63;
  int stage_v_244_2 = ((pub_r001652_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001652_16_1 * 2) + 47) & 63;
  int stage_v_245_2 = ((pub_r001652_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = (((stage_v_96_1 * 3) + pub_r001652_11_1) + 10) & 127;
  int stage_v_246_2 = (((stage_v_96_2 * 3) + pub_r001652_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = (((stage_v_19_1 * 3) + pub_r001652_18_1) + 11) & 127;
  int stage_v_247_2 = (((stage_v_19_2 * 3) + pub_r001652_18_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = ((pub_r001652_15_1 * 2) + 31) & 63;
  int stage_v_248_2 = ((pub_r001652_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = (((helper_flow_0_1 * 3) + pub_r001652_3_1) + 25) & 127;
  int stage_v_249_2 = (((helper_flow_0_2 * 3) + pub_r001652_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = ((pub_r001652_12_1 * 2) + 49) & 63;
  int stage_v_250_2 = ((pub_r001652_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = (((sec_r001652_8_1 * 3) + pub_r001652_18_1) + 17) & 127;
  int stage_v_251_2 = (((sec_r001652_8_2 * 3) + pub_r001652_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = ((pub_r001652_12_1 * 2) + 33) & 63;
  int stage_v_252_2 = ((pub_r001652_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((pub_r001652_6_1 * 2) + 46) & 63;
  int stage_v_253_2 = ((pub_r001652_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((pub_r001652_3_1 * 2) + 24) & 63;
  int stage_v_254_2 = ((pub_r001652_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001652_18_1 * 2) + 50) & 63;
  int stage_v_255_2 = ((pub_r001652_18_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001652_4_1 * 2) + 44) & 63;
  int stage_v_256_2 = ((pub_r001652_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = (((stage_v_131_1 * 3) + pub_r001652_7_1) + 24) & 127;
  int stage_v_257_2 = (((stage_v_131_2 * 3) + pub_r001652_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = (((sec_r001652_11_1 * 3) + pub_r001652_1_1) + 32) & 127;
  int stage_v_258_2 = (((sec_r001652_11_2 * 3) + pub_r001652_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = (((stage_v_194_1 * 3) + pub_r001652_18_1) + 14) & 127;
  int stage_v_259_2 = (((stage_v_194_2 * 3) + pub_r001652_18_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = (((stage_v_91_1 * 3) + pub_r001652_1_1) + 17) & 127;
  int stage_v_260_2 = (((stage_v_91_2 * 3) + pub_r001652_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = ((pub_r001652_2_1 * 2) + 6) & 63;
  int stage_v_261_2 = ((pub_r001652_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = (((stage_v_218_1 * 3) + pub_r001652_3_1) + 28) & 127;
  int stage_v_262_2 = (((stage_v_218_2 * 3) + pub_r001652_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = (((stage_v_131_1 * 3) + pub_r001652_0_1) + 11) & 127;
  int stage_v_263_2 = (((stage_v_131_2 * 3) + pub_r001652_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = ((pub_r001652_5_1 * 2) + 21) & 63;
  int stage_v_264_2 = ((pub_r001652_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001652_3_1 * 2) + 35) & 63;
  int stage_v_265_2 = ((pub_r001652_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001652_12_1 * 2) + 19) & 63;
  int stage_v_266_2 = ((pub_r001652_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001652_4_1 * 2) + 14) & 63;
  int stage_v_267_2 = ((pub_r001652_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001652_10_1 * 2) + 27) & 63;
  int stage_v_268_2 = ((pub_r001652_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = (((stage_v_44_1 * 3) + pub_r001652_13_1) + 30) & 127;
  int stage_v_269_2 = (((stage_v_44_2 * 3) + pub_r001652_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = (((stage_v_239_1 * 3) + pub_r001652_3_1) + 36) & 127;
  int stage_v_270_2 = (((stage_v_239_2 * 3) + pub_r001652_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = ((pub_r001652_0_1 * 2) + 42) & 63;
  int stage_v_271_2 = ((pub_r001652_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = (((stage_v_234_1 * 3) + pub_r001652_10_1) + 39) & 127;
  int stage_v_272_2 = (((stage_v_234_2 * 3) + pub_r001652_10_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = (((sec_r001652_13_1 * 3) + pub_r001652_17_1) + 15) & 127;
  int stage_v_273_2 = (((sec_r001652_13_2 * 3) + pub_r001652_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = ((pub_r001652_11_1 * 2) + 24) & 63;
  int stage_v_274_2 = ((pub_r001652_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001652_2_1 * 2) + 14) & 63;
  int stage_v_275_2 = ((pub_r001652_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = (((stage_v_257_1 * 3) + pub_r001652_5_1) + 32) & 127;
  int stage_v_276_2 = (((stage_v_257_2 * 3) + pub_r001652_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = (((stage_v_15_1 * 3) + pub_r001652_2_1) + 10) & 127;
  int stage_v_277_2 = (((stage_v_15_2 * 3) + pub_r001652_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = ((pub_r001652_2_1 * 2) + 21) & 63;
  int stage_v_278_2 = ((pub_r001652_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = (((sec_r001652_3_1 * 3) + pub_r001652_18_1) + 44) & 127;
  int stage_v_279_2 = (((sec_r001652_3_2 * 3) + pub_r001652_18_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = (((stage_v_279_1 * 3) + pub_r001652_5_1) + 45) & 127;
  int stage_v_280_2 = (((stage_v_279_2 * 3) + pub_r001652_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = ((pub_r001652_5_1 * 2) + 44) & 63;
  int stage_v_281_2 = ((pub_r001652_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((pub_r001652_9_1 * 2) + 7) & 63;
  int stage_v_282_2 = ((pub_r001652_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001652_11_1 * 2) + 42) & 63;
  int stage_v_283_2 = ((pub_r001652_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = (((stage_v_115_1 * 3) + pub_r001652_7_1) + 33) & 127;
  int stage_v_284_2 = (((stage_v_115_2 * 3) + pub_r001652_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = ((pub_r001652_14_1 * 2) + 34) & 63;
  int stage_v_285_2 = ((pub_r001652_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = (((stage_v_17_1 * 3) + pub_r001652_14_1) + 15) & 127;
  int stage_v_286_2 = (((stage_v_17_2 * 3) + pub_r001652_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = (((sec_r001652_7_1 * 3) + pub_r001652_15_1) + 3) & 127;
  int stage_v_287_2 = (((sec_r001652_7_2 * 3) + pub_r001652_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((stage_v_194_1 * 3) + pub_r001652_14_1) + 6) & 127;
  int stage_v_288_2 = (((stage_v_194_2 * 3) + pub_r001652_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = ((pub_r001652_0_1 * 2) + 18) & 63;
  int stage_v_289_2 = ((pub_r001652_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = (((stage_v_198_1 * 3) + pub_r001652_5_1) + 7) & 127;
  int stage_v_290_2 = (((stage_v_198_2 * 3) + pub_r001652_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = (((stage_v_15_1 * 3) + pub_r001652_4_1) + 8) & 127;
  int stage_v_291_2 = (((stage_v_15_2 * 3) + pub_r001652_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = ((pub_r001652_11_1 * 2) + 11) & 63;
  int stage_v_292_2 = ((pub_r001652_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001652_13_1 * 2) + 35) & 63;
  int stage_v_293_2 = ((pub_r001652_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = (((stage_v_79_1 * 3) + pub_r001652_15_1) + 8) & 127;
  int stage_v_294_2 = (((stage_v_79_2 * 3) + pub_r001652_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = (((stage_v_98_1 * 3) + pub_r001652_14_1) + 35) & 127;
  int stage_v_295_2 = (((stage_v_98_2 * 3) + pub_r001652_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = ((pub_r001652_18_1 * 2) + 46) & 63;
  int stage_v_296_2 = ((pub_r001652_18_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = (((stage_v_214_1 * 3) + pub_r001652_9_1) + 9) & 127;
  int stage_v_297_2 = (((stage_v_214_2 * 3) + pub_r001652_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = ((pub_r001652_11_1 * 2) + 45) & 63;
  int stage_v_298_2 = ((pub_r001652_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = (((stage_v_91_1 * 3) + pub_r001652_6_1) + 44) & 127;
  int stage_v_299_2 = (((stage_v_91_2 * 3) + pub_r001652_6_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = ((pub_r001652_13_1 * 2) + 10) & 63;
  int stage_v_300_2 = ((pub_r001652_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001652_9_1 * 2) + 44) & 63;
  int stage_v_301_2 = ((pub_r001652_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001652_10_1 * 2) + 8) & 63;
  int stage_v_302_2 = ((pub_r001652_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = (((stage_v_84_1 * 3) + pub_r001652_15_1) + 19) & 127;
  int stage_v_303_2 = (((stage_v_84_2 * 3) + pub_r001652_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = (((stage_v_93_1 * 3) + pub_r001652_9_1) + 20) & 127;
  int stage_v_304_2 = (((stage_v_93_2 * 3) + pub_r001652_9_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = ((pub_r001652_8_1 * 2) + 35) & 63;
  int stage_v_305_2 = ((pub_r001652_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001652_9_1 * 2) + 48) & 63;
  int stage_v_306_2 = ((pub_r001652_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = (((stage_v_42_1 * 3) + pub_r001652_0_1) + 39) & 127;
  int stage_v_307_2 = (((stage_v_42_2 * 3) + pub_r001652_0_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = (((stage_v_299_1 * 3) + pub_r001652_0_1) + 33) & 127;
  int stage_v_308_2 = (((stage_v_299_2 * 3) + pub_r001652_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = (((stage_v_101_1 * 3) + pub_r001652_4_1) + 20) & 127;
  int stage_v_309_2 = (((stage_v_101_2 * 3) + pub_r001652_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = (((stage_v_56_1 * 3) + pub_r001652_18_1) + 40) & 127;
  int stage_v_310_2 = (((stage_v_56_2 * 3) + pub_r001652_18_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = ((pub_r001652_7_1 * 2) + 34) & 63;
  int stage_v_311_2 = ((pub_r001652_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = (((sec_r001652_11_1 * 3) + pub_r001652_13_1) + 15) & 127;
  int stage_v_312_2 = (((sec_r001652_11_2 * 3) + pub_r001652_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = ((pub_r001652_2_1 * 2) + 18) & 63;
  int stage_v_313_2 = ((pub_r001652_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = (((stage_v_42_1 * 3) + pub_r001652_6_1) + 42) & 127;
  int stage_v_314_2 = (((stage_v_42_2 * 3) + pub_r001652_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = (((stage_v_218_1 * 3) + pub_r001652_3_1) + 35) & 127;
  int stage_v_315_2 = (((stage_v_218_2 * 3) + pub_r001652_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = ((pub_r001652_10_1 * 2) + 12) & 63;
  int stage_v_316_2 = ((pub_r001652_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = (((stage_v_184_1 * 3) + pub_r001652_3_1) + 20) & 127;
  int stage_v_317_2 = (((stage_v_184_2 * 3) + pub_r001652_3_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = ((pub_r001652_14_1 * 2) + 7) & 63;
  int stage_v_318_2 = ((pub_r001652_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001652_2_1 * 2) + 27) & 63;
  int stage_v_319_2 = ((pub_r001652_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = (((stage_v_312_1 * 3) + pub_r001652_14_1) + 17) & 127;
  int stage_v_320_2 = (((stage_v_312_2 * 3) + pub_r001652_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = (((stage_v_304_1 * 3) + pub_r001652_0_1) + 17) & 127;
  int stage_v_321_2 = (((stage_v_304_2 * 3) + pub_r001652_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = ((pub_r001652_16_1 * 2) + 38) & 63;
  int stage_v_322_2 = ((pub_r001652_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001652_17_1 * 2) + 21) & 63;
  int stage_v_323_2 = ((pub_r001652_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001652_8_1 * 2) + 29) & 63;
  int stage_v_324_2 = ((pub_r001652_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((pub_r001652_7_1 * 2) + 22) & 63;
  int stage_v_325_2 = ((pub_r001652_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = (((stage_v_279_1 * 3) + pub_r001652_14_1) + 17) & 127;
  int stage_v_326_2 = (((stage_v_279_2 * 3) + pub_r001652_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = (((stage_v_39_1 * 3) + pub_r001652_17_1) + 6) & 127;
  int stage_v_327_2 = (((stage_v_39_2 * 3) + pub_r001652_17_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = ((pub_r001652_12_1 * 2) + 12) & 63;
  int stage_v_328_2 = ((pub_r001652_12_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001652_2_1 * 2) + 16) & 63;
  int stage_v_329_2 = ((pub_r001652_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001652_9_1 * 2) + 42) & 63;
  int stage_v_330_2 = ((pub_r001652_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001652_6_1 * 2) + 49) & 63;
  int stage_v_331_2 = ((pub_r001652_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001652_13_1 * 2) + 13) & 63;
  int stage_v_332_2 = ((pub_r001652_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001652_0_1 * 2) + 30) & 63;
  int stage_v_333_2 = ((pub_r001652_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = (((stage_v_103_1 * 3) + pub_r001652_9_1) + 12) & 127;
  int stage_v_334_2 = (((stage_v_103_2 * 3) + pub_r001652_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = ((pub_r001652_13_1 * 2) + 22) & 63;
  int stage_v_335_2 = ((pub_r001652_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((pub_r001652_10_1 * 2) + 24) & 63;
  int stage_v_336_2 = ((pub_r001652_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001652_4_1 * 2) + 26) & 63;
  int stage_v_337_2 = ((pub_r001652_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = (((stage_v_251_1 * 3) + pub_r001652_14_1) + 10) & 127;
  int stage_v_338_2 = (((stage_v_251_2 * 3) + pub_r001652_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = ((pub_r001652_18_1 * 2) + 49) & 63;
  int stage_v_339_2 = ((pub_r001652_18_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = (((stage_v_60_1 * 3) + pub_r001652_8_1) + 4) & 127;
  int stage_v_340_2 = (((stage_v_60_2 * 3) + pub_r001652_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = ((pub_r001652_16_1 * 2) + 28) & 63;
  int stage_v_341_2 = ((pub_r001652_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001652_13_1 * 2) + 36) & 63;
  int stage_v_342_2 = ((pub_r001652_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((pub_r001652_15_1 * 2) + 26) & 63;
  int stage_v_343_2 = ((pub_r001652_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001652_17_1 * 2) + 5) & 63;
  int stage_v_344_2 = ((pub_r001652_17_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((pub_r001652_3_1 * 2) + 6) & 63;
  int stage_v_345_2 = ((pub_r001652_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001652_18_1 * 2) + 44) & 63;
  int stage_v_346_2 = ((pub_r001652_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = (((stage_v_303_1 * 3) + pub_r001652_15_1) + 19) & 127;
  int stage_v_347_2 = (((stage_v_303_2 * 3) + pub_r001652_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = ((pub_r001652_10_1 * 2) + 5) & 63;
  int stage_v_348_2 = ((pub_r001652_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = (((stage_v_36_1 * 3) + pub_r001652_5_1) + 6) & 127;
  int stage_v_349_2 = (((stage_v_36_2 * 3) + pub_r001652_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((stage_v_37_1 * 3) + pub_r001652_3_1) + 18) & 127;
  int stage_v_350_2 = (((stage_v_37_2 * 3) + pub_r001652_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = ((pub_r001652_15_1 * 2) + 34) & 63;
  int stage_v_351_2 = ((pub_r001652_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = (((stage_v_213_1 * 3) + pub_r001652_9_1) + 13) & 127;
  int stage_v_352_2 = (((stage_v_213_2 * 3) + pub_r001652_9_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = (((stage_v_91_1 * 3) + pub_r001652_12_1) + 36) & 127;
  int stage_v_353_2 = (((stage_v_91_2 * 3) + pub_r001652_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = ((pub_r001652_14_1 * 2) + 45) & 63;
  int stage_v_354_2 = ((pub_r001652_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001652_7_1 * 2) + 32) & 63;
  int stage_v_355_2 = ((pub_r001652_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = (((stage_v_101_1 * 3) + pub_r001652_12_1) + 36) & 127;
  int stage_v_356_2 = (((stage_v_101_2 * 3) + pub_r001652_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = ((pub_r001652_7_1 * 2) + 27) & 63;
  int stage_v_357_2 = ((pub_r001652_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001652_12_1 * 2) + 10) & 63;
  int stage_v_358_2 = ((pub_r001652_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001652_6_1 * 2) + 46) & 63;
  int stage_v_359_2 = ((pub_r001652_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = (((stage_v_93_1 * 3) + pub_r001652_5_1) + 15) & 127;
  int stage_v_360_2 = (((stage_v_93_2 * 3) + pub_r001652_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = ((pub_r001652_2_1 * 2) + 32) & 63;
  int stage_v_361_2 = ((pub_r001652_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001652_5_1 * 2) + 36) & 63;
  int stage_v_362_2 = ((pub_r001652_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = (((helper_flow_1_1 * 3) + pub_r001652_18_1) + 41) & 127;
  int stage_v_363_2 = (((helper_flow_1_2 * 3) + pub_r001652_18_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = (((stage_v_304_1 * 3) + pub_r001652_16_1) + 40) & 127;
  int stage_v_364_2 = (((stage_v_304_2 * 3) + pub_r001652_16_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = ((pub_r001652_1_1 * 2) + 9) & 63;
  int stage_v_365_2 = ((pub_r001652_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = (((sec_r001652_8_1 * 3) + pub_r001652_8_1) + 30) & 127;
  int stage_v_366_2 = (((sec_r001652_8_2 * 3) + pub_r001652_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = ((pub_r001652_17_1 * 2) + 29) & 63;
  int stage_v_367_2 = ((pub_r001652_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = (((stage_v_193_1 * 3) + pub_r001652_11_1) + 36) & 127;
  int stage_v_368_2 = (((stage_v_193_2 * 3) + pub_r001652_11_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = (((stage_v_49_1 * 3) + pub_r001652_10_1) + 20) & 127;
  int stage_v_369_2 = (((stage_v_49_2 * 3) + pub_r001652_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = (((stage_v_11_1 * 3) + pub_r001652_11_1) + 21) & 127;
  int stage_v_370_2 = (((stage_v_11_2 * 3) + pub_r001652_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = ((pub_r001652_6_1 * 2) + 45) & 63;
  int stage_v_371_2 = ((pub_r001652_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001652_6_1 * 2) + 15) & 63;
  int stage_v_372_2 = ((pub_r001652_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001652_12_1 * 2) + 47) & 63;
  int stage_v_373_2 = ((pub_r001652_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((pub_r001652_14_1 * 2) + 10) & 63;
  int stage_v_374_2 = ((pub_r001652_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((pub_r001652_1_1 * 2) + 37) & 63;
  int stage_v_375_2 = ((pub_r001652_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = (((helper_flow_2_1 * 3) + pub_r001652_0_1) + 22) & 127;
  int stage_v_376_2 = (((helper_flow_2_2 * 3) + pub_r001652_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = (((stage_v_376_1 * 3) + pub_r001652_13_1) + 42) & 127;
  int stage_v_377_2 = (((stage_v_376_2 * 3) + pub_r001652_13_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = ((pub_r001652_1_1 * 2) + 39) & 63;
  int stage_v_378_2 = ((pub_r001652_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = ((pub_r001652_15_1 * 2) + 14) & 63;
  int stage_v_379_2 = ((pub_r001652_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = (((stage_v_349_1 * 3) + pub_r001652_11_1) + 30) & 127;
  int stage_v_380_2 = (((stage_v_349_2 * 3) + pub_r001652_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = ((pub_r001652_9_1 * 2) + 34) & 63;
  int stage_v_381_2 = ((pub_r001652_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = ((pub_r001652_3_1 * 2) + 16) & 63;
  int stage_v_382_2 = ((pub_r001652_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001652_12_1 * 2) + 25) & 63;
  int stage_v_383_2 = ((pub_r001652_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = (((stage_v_145_1 * 3) + pub_r001652_5_1) + 33) & 127;
  int stage_v_384_2 = (((stage_v_145_2 * 3) + pub_r001652_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = ((pub_r001652_1_1 * 2) + 11) & 63;
  int stage_v_385_2 = ((pub_r001652_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = (((stage_v_317_1 * 3) + pub_r001652_18_1) + 24) & 127;
  int stage_v_386_2 = (((stage_v_317_2 * 3) + pub_r001652_18_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_386_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_386_2 * 2)) & 255;
  int stage_v_387_1 = ((pub_r001652_8_1 * 2) + 34) & 63;
  int stage_v_387_2 = ((pub_r001652_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = (((stage_v_279_1 * 3) + pub_r001652_15_1) + 12) & 127;
  int stage_v_388_2 = (((stage_v_279_2 * 3) + pub_r001652_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = ((pub_r001652_6_1 * 2) + 43) & 63;
  int stage_v_389_2 = ((pub_r001652_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = (((stage_v_386_1 * 3) + pub_r001652_13_1) + 4) & 127;
  int stage_v_390_2 = (((stage_v_386_2 * 3) + pub_r001652_13_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = (((sec_r001652_16_1 * 3) + pub_r001652_10_1) + 32) & 127;
  int stage_v_391_2 = (((sec_r001652_16_2 * 3) + pub_r001652_10_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((stage_v_91_1 * 3) + pub_r001652_16_1) + 8) & 127;
  int stage_v_392_2 = (((stage_v_91_2 * 3) + pub_r001652_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = (((stage_v_321_1 * 3) + pub_r001652_7_1) + 24) & 127;
  int stage_v_393_2 = (((stage_v_321_2 * 3) + pub_r001652_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = (((stage_v_259_1 * 3) + pub_r001652_12_1) + 13) & 127;
  int stage_v_394_2 = (((stage_v_259_2 * 3) + pub_r001652_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = (((stage_v_314_1 * 3) + pub_r001652_4_1) + 15) & 127;
  int stage_v_395_2 = (((stage_v_314_2 * 3) + pub_r001652_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = ((pub_r001652_1_1 * 2) + 28) & 63;
  int stage_v_396_2 = ((pub_r001652_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((pub_r001652_12_1 * 2) + 7) & 63;
  int stage_v_397_2 = ((pub_r001652_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001652_17_1 * 2) + 20) & 63;
  int stage_v_398_2 = ((pub_r001652_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = (((stage_v_368_1 * 3) + pub_r001652_1_1) + 12) & 127;
  int stage_v_399_2 = (((stage_v_368_2 * 3) + pub_r001652_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = (((stage_v_257_1 * 3) + pub_r001652_11_1) + 11) & 127;
  int stage_v_400_2 = (((stage_v_257_2 * 3) + pub_r001652_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = (((stage_v_315_1 * 3) + pub_r001652_10_1) + 32) & 127;
  int stage_v_401_2 = (((stage_v_315_2 * 3) + pub_r001652_10_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_401_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_401_2 * 2)) & 255;
  int stage_v_402_1 = ((pub_r001652_18_1 * 2) + 31) & 63;
  int stage_v_402_2 = ((pub_r001652_18_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((pub_r001652_3_1 * 2) + 46) & 63;
  int stage_v_403_2 = ((pub_r001652_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = (((stage_v_101_1 * 3) + pub_r001652_11_1) + 6) & 127;
  int stage_v_404_2 = (((stage_v_101_2 * 3) + pub_r001652_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = ((pub_r001652_14_1 * 2) + 49) & 63;
  int stage_v_405_2 = ((pub_r001652_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = (((stage_v_172_1 * 3) + pub_r001652_17_1) + 45) & 127;
  int stage_v_406_2 = (((stage_v_172_2 * 3) + pub_r001652_17_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = (((stage_v_352_1 * 3) + pub_r001652_4_1) + 35) & 127;
  int stage_v_407_2 = (((stage_v_352_2 * 3) + pub_r001652_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_407_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_407_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_407_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_407_2 * 2)) & 255;
  int stage_v_408_1 = (((sec_r001652_6_1 * 3) + pub_r001652_1_1) + 25) & 127;
  int stage_v_408_2 = (((sec_r001652_6_2 * 3) + pub_r001652_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = ((pub_r001652_5_1 * 2) + 19) & 63;
  int stage_v_409_2 = ((pub_r001652_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((pub_r001652_18_1 * 2) + 18) & 63;
  int stage_v_410_2 = ((pub_r001652_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = (((stage_v_317_1 * 3) + pub_r001652_14_1) + 33) & 127;
  int stage_v_411_2 = (((stage_v_317_2 * 3) + pub_r001652_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_411_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_411_2 * 2)) & 255;
  int stage_v_412_1 = ((pub_r001652_11_1 * 2) + 6) & 63;
  int stage_v_412_2 = ((pub_r001652_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = (((stage_v_20_1 * 3) + pub_r001652_1_1) + 41) & 127;
  int stage_v_413_2 = (((stage_v_20_2 * 3) + pub_r001652_1_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_413_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_413_2 * 2)) & 255;
  int stage_v_414_1 = ((pub_r001652_15_1 * 2) + 41) & 63;
  int stage_v_414_2 = ((pub_r001652_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = ((pub_r001652_1_1 * 2) + 41) & 63;
  int stage_v_415_2 = ((pub_r001652_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = (((sec_r001652_13_1 * 3) + pub_r001652_13_1) + 9) & 127;
  int stage_v_416_2 = (((sec_r001652_13_2 * 3) + pub_r001652_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = (((stage_v_263_1 * 3) + pub_r001652_1_1) + 22) & 127;
  int stage_v_417_2 = (((stage_v_263_2 * 3) + pub_r001652_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = ((pub_r001652_17_1 * 2) + 6) & 63;
  int stage_v_418_2 = ((pub_r001652_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = (((stage_v_222_1 * 3) + pub_r001652_8_1) + 19) & 127;
  int stage_v_419_2 = (((stage_v_222_2 * 3) + pub_r001652_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = ((pub_r001652_3_1 * 2) + 11) & 63;
  int stage_v_420_2 = ((pub_r001652_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = ((pub_r001652_0_1 * 2) + 38) & 63;
  int stage_v_421_2 = ((pub_r001652_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((pub_r001652_3_1 * 2) + 6) & 63;
  int stage_v_422_2 = ((pub_r001652_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((pub_r001652_10_1 * 2) + 32) & 63;
  int stage_v_423_2 = ((pub_r001652_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = (((stage_v_240_1 * 3) + pub_r001652_6_1) + 11) & 127;
  int stage_v_424_2 = (((stage_v_240_2 * 3) + pub_r001652_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_424_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_424_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_424_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_424_2 * 2)) & 255;
  int stage_v_425_1 = ((pub_r001652_10_1 * 2) + 14) & 63;
  int stage_v_425_2 = ((pub_r001652_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = ((pub_r001652_15_1 * 2) + 42) & 63;
  int stage_v_426_2 = ((pub_r001652_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((pub_r001652_17_1 * 2) + 43) & 63;
  int stage_v_427_2 = ((pub_r001652_17_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = ((pub_r001652_14_1 * 2) + 19) & 63;
  int stage_v_428_2 = ((pub_r001652_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((pub_r001652_13_1 * 2) + 17) & 63;
  int stage_v_429_2 = ((pub_r001652_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = ((pub_r001652_12_1 * 2) + 17) & 63;
  int stage_v_430_2 = ((pub_r001652_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = ((pub_r001652_3_1 * 2) + 41) & 63;
  int stage_v_431_2 = ((pub_r001652_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = ((pub_r001652_0_1 * 2) + 21) & 63;
  int stage_v_432_2 = ((pub_r001652_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = (((stage_v_79_1 * 3) + pub_r001652_11_1) + 30) & 127;
  int stage_v_433_2 = (((stage_v_79_2 * 3) + pub_r001652_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = (((stage_v_177_1 * 3) + pub_r001652_2_1) + 31) & 127;
  int stage_v_434_2 = (((stage_v_177_2 * 3) + pub_r001652_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_434_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_434_2 * 2)) & 255;
  int stage_v_435_1 = ((pub_r001652_6_1 * 2) + 32) & 63;
  int stage_v_435_2 = ((pub_r001652_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = (((stage_v_353_1 * 3) + pub_r001652_2_1) + 18) & 127;
  int stage_v_436_2 = (((stage_v_353_2 * 3) + pub_r001652_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_436_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_436_2 * 2)) & 255;
  int stage_v_437_1 = (((stage_v_380_1 * 3) + pub_r001652_10_1) + 15) & 127;
  int stage_v_437_2 = (((stage_v_380_2 * 3) + pub_r001652_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  int stage_v_438_1 = ((pub_r001652_5_1 * 2) + 43) & 63;
  int stage_v_438_2 = ((pub_r001652_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((pub_r001652_2_1 * 2) + 13) & 63;
  int stage_v_439_2 = ((pub_r001652_2_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = (((stage_v_399_1 * 3) + pub_r001652_7_1) + 19) & 127;
  int stage_v_440_2 = (((stage_v_399_2 * 3) + pub_r001652_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_440_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_440_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_440_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_440_2 * 2)) & 255;
  int stage_v_441_1 = (((stage_v_407_1 * 3) + pub_r001652_12_1) + 38) & 127;
  int stage_v_441_2 = (((stage_v_407_2 * 3) + pub_r001652_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_441_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_441_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_441_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_441_2 * 2)) & 255;
  int stage_v_442_1 = (((stage_v_181_1 * 3) + pub_r001652_5_1) + 29) & 127;
  int stage_v_442_2 = (((stage_v_181_2 * 3) + pub_r001652_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_442_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_442_2 * 2)) & 255;
  int stage_v_443_1 = ((pub_r001652_18_1 * 2) + 23) & 63;
  int stage_v_443_2 = ((pub_r001652_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001652_10_1 * 2) + 9) & 63;
  int stage_v_444_2 = ((pub_r001652_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((pub_r001652_3_1 * 2) + 15) & 63;
  int stage_v_445_2 = ((pub_r001652_3_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = ((pub_r001652_6_1 * 2) + 32) & 63;
  int stage_v_446_2 = ((pub_r001652_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001652_11_1 != sec_r001652_11_2);
  __CPROVER_assume(sec_r001652_7_1 != sec_r001652_7_2);
  __CPROVER_assume(pub_r001652_16_1 == pub_r001652_16_2);
  __CPROVER_assume(pub_r001652_7_1 == pub_r001652_7_2);
  __CPROVER_assume(sec_r001652_12_1 != sec_r001652_12_2);
  __CPROVER_assume(sec_r001652_8_1 != sec_r001652_8_2);
  __CPROVER_assume(sec_r001652_3_1 != sec_r001652_3_2);
  __CPROVER_assume(sec_r001652_0_1 != sec_r001652_0_2);
  __CPROVER_assume(sec_r001652_15_1 != sec_r001652_15_2);
  __CPROVER_assume(pub_r001652_0_1 == pub_r001652_0_2);
  __CPROVER_assume(pub_r001652_11_1 == pub_r001652_11_2);
  __CPROVER_assume(pub_r001652_17_1 == pub_r001652_17_2);
  __CPROVER_assume(pub_r001652_12_1 == pub_r001652_12_2);
  __CPROVER_assume(sec_r001652_9_1 != sec_r001652_9_2);
  __CPROVER_assume(pub_r001652_4_1 == pub_r001652_4_2);
  __CPROVER_assume(pub_r001652_8_1 == pub_r001652_8_2);
  __CPROVER_assume(sec_r001652_5_1 != sec_r001652_5_2);
  __CPROVER_assume(pub_r001652_10_1 == pub_r001652_10_2);
  __CPROVER_assume(sec_r001652_14_1 != sec_r001652_14_2);
  __CPROVER_assume(pub_r001652_2_1 == pub_r001652_2_2);
  __CPROVER_assume(pub_r001652_15_1 == pub_r001652_15_2);
  __CPROVER_assume(pub_r001652_9_1 == pub_r001652_9_2);
  __CPROVER_assume(sec_r001652_13_1 != sec_r001652_13_2);
  __CPROVER_assume(sec_r001652_17_1 != sec_r001652_17_2);
  __CPROVER_assume(pub_r001652_18_1 == pub_r001652_18_2);
  __CPROVER_assume(sec_r001652_10_1 != sec_r001652_10_2);
  __CPROVER_assume(pub_r001652_14_1 == pub_r001652_14_2);
  __CPROVER_assume(pub_r001652_5_1 == pub_r001652_5_2);
  __CPROVER_assume(pub_r001652_13_1 == pub_r001652_13_2);
  __CPROVER_assume(sec_r001652_2_1 != sec_r001652_2_2);
  __CPROVER_assume(pub_r001652_3_1 == pub_r001652_3_2);
  __CPROVER_assume(pub_r001652_1_1 == pub_r001652_1_2);
  __CPROVER_assume(sec_r001652_16_1 != sec_r001652_16_2);
  __CPROVER_assume(sec_r001652_4_1 != sec_r001652_4_2);
  __CPROVER_assume(sec_r001652_6_1 != sec_r001652_6_2);
  __CPROVER_assume(pub_r001652_6_1 == pub_r001652_6_2);
  __CPROVER_assume(sec_r001652_1_1 != sec_r001652_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.tail == st_var_0_2.tail);
  assert(st_var_0_1.head == st_var_0_2.head);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.gain == st_var_1_2.gain);
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

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
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
  assert(stage_v_316_1 == stage_v_316_2);
  assert(stage_v_317_1 == stage_v_317_2);
  assert(stage_v_318_1 == stage_v_318_2);
  assert(stage_v_319_1 == stage_v_319_2);
  assert(stage_v_320_1 == stage_v_320_2);
  assert(stage_v_321_1 == stage_v_321_2);
  assert(stage_v_322_1 == stage_v_322_2);
  assert(stage_v_323_1 == stage_v_323_2);
  assert(stage_v_324_1 == stage_v_324_2);
  assert(stage_v_325_1 == stage_v_325_2);
  assert(stage_v_326_1 == stage_v_326_2);
  assert(stage_v_327_1 == stage_v_327_2);
  assert(stage_v_328_1 == stage_v_328_2);
  assert(stage_v_329_1 == stage_v_329_2);
  assert(stage_v_330_1 == stage_v_330_2);
  assert(stage_v_331_1 == stage_v_331_2);
  assert(stage_v_332_1 == stage_v_332_2);
  assert(stage_v_333_1 == stage_v_333_2);
  assert(stage_v_334_1 == stage_v_334_2);
  assert(stage_v_335_1 == stage_v_335_2);
  assert(stage_v_336_1 == stage_v_336_2);
  assert(stage_v_337_1 == stage_v_337_2);
  assert(stage_v_338_1 == stage_v_338_2);
  assert(stage_v_339_1 == stage_v_339_2);
  assert(stage_v_340_1 == stage_v_340_2);
  assert(stage_v_341_1 == stage_v_341_2);
  assert(stage_v_342_1 == stage_v_342_2);
  assert(stage_v_343_1 == stage_v_343_2);
  assert(stage_v_344_1 == stage_v_344_2);
  assert(stage_v_345_1 == stage_v_345_2);
  assert(stage_v_346_1 == stage_v_346_2);
  assert(stage_v_347_1 == stage_v_347_2);
  assert(stage_v_348_1 == stage_v_348_2);
  assert(stage_v_349_1 == stage_v_349_2);
  assert(stage_v_350_1 == stage_v_350_2);
  assert(stage_v_351_1 == stage_v_351_2);
  assert(stage_v_352_1 == stage_v_352_2);
  assert(stage_v_353_1 == stage_v_353_2);
  assert(stage_v_354_1 == stage_v_354_2);
  assert(stage_v_355_1 == stage_v_355_2);
  assert(stage_v_356_1 == stage_v_356_2);
  assert(stage_v_357_1 == stage_v_357_2);
  assert(stage_v_358_1 == stage_v_358_2);
  assert(stage_v_359_1 == stage_v_359_2);
  assert(stage_v_360_1 == stage_v_360_2);
  assert(stage_v_361_1 == stage_v_361_2);
  assert(stage_v_362_1 == stage_v_362_2);
  assert(stage_v_363_1 == stage_v_363_2);
  assert(stage_v_364_1 == stage_v_364_2);
  assert(stage_v_365_1 == stage_v_365_2);
  assert(stage_v_366_1 == stage_v_366_2);
  assert(stage_v_367_1 == stage_v_367_2);
  assert(stage_v_368_1 == stage_v_368_2);
  assert(stage_v_369_1 == stage_v_369_2);
  assert(stage_v_370_1 == stage_v_370_2);
  assert(stage_v_371_1 == stage_v_371_2);
  assert(stage_v_372_1 == stage_v_372_2);
  assert(stage_v_373_1 == stage_v_373_2);
  assert(stage_v_374_1 == stage_v_374_2);
  assert(stage_v_375_1 == stage_v_375_2);
  assert(stage_v_376_1 == stage_v_376_2);
  assert(stage_v_377_1 == stage_v_377_2);
  assert(stage_v_378_1 == stage_v_378_2);
  assert(stage_v_379_1 == stage_v_379_2);
  assert(stage_v_380_1 == stage_v_380_2);
  assert(stage_v_381_1 == stage_v_381_2);
  assert(stage_v_382_1 == stage_v_382_2);
  assert(stage_v_383_1 == stage_v_383_2);
  assert(stage_v_384_1 == stage_v_384_2);
  assert(stage_v_385_1 == stage_v_385_2);
  assert(stage_v_386_1 == stage_v_386_2);
  assert(stage_v_387_1 == stage_v_387_2);
  assert(stage_v_388_1 == stage_v_388_2);
  assert(stage_v_389_1 == stage_v_389_2);
  assert(stage_v_390_1 == stage_v_390_2);
  assert(stage_v_391_1 == stage_v_391_2);
  assert(stage_v_392_1 == stage_v_392_2);
  assert(stage_v_393_1 == stage_v_393_2);
  assert(stage_v_394_1 == stage_v_394_2);
  assert(stage_v_395_1 == stage_v_395_2);
  assert(stage_v_396_1 == stage_v_396_2);
  assert(stage_v_397_1 == stage_v_397_2);
  assert(stage_v_398_1 == stage_v_398_2);
  assert(stage_v_399_1 == stage_v_399_2);
  assert(stage_v_400_1 == stage_v_400_2);
  assert(stage_v_401_1 == stage_v_401_2);
  assert(stage_v_402_1 == stage_v_402_2);
  assert(stage_v_403_1 == stage_v_403_2);
  assert(stage_v_404_1 == stage_v_404_2);
  assert(stage_v_405_1 == stage_v_405_2);
  assert(stage_v_406_1 == stage_v_406_2);
  assert(stage_v_407_1 == stage_v_407_2);
  assert(stage_v_408_1 == stage_v_408_2);
  assert(stage_v_409_1 == stage_v_409_2);
  assert(stage_v_410_1 == stage_v_410_2);
  assert(stage_v_411_1 == stage_v_411_2);
  assert(stage_v_412_1 == stage_v_412_2);
  assert(stage_v_413_1 == stage_v_413_2);
  assert(stage_v_414_1 == stage_v_414_2);
  assert(stage_v_415_1 == stage_v_415_2);
  assert(stage_v_416_1 == stage_v_416_2);
  assert(stage_v_417_1 == stage_v_417_2);
  assert(stage_v_418_1 == stage_v_418_2);
  assert(stage_v_419_1 == stage_v_419_2);
  assert(stage_v_420_1 == stage_v_420_2);
  assert(stage_v_421_1 == stage_v_421_2);
  assert(stage_v_422_1 == stage_v_422_2);
  assert(stage_v_423_1 == stage_v_423_2);
  assert(stage_v_424_1 == stage_v_424_2);
  assert(stage_v_425_1 == stage_v_425_2);
  assert(stage_v_426_1 == stage_v_426_2);
  assert(stage_v_427_1 == stage_v_427_2);
  assert(stage_v_428_1 == stage_v_428_2);
  assert(stage_v_429_1 == stage_v_429_2);
  assert(stage_v_430_1 == stage_v_430_2);
  assert(stage_v_431_1 == stage_v_431_2);
  assert(stage_v_432_1 == stage_v_432_2);
  assert(stage_v_433_1 == stage_v_433_2);
  assert(stage_v_434_1 == stage_v_434_2);
  assert(stage_v_435_1 == stage_v_435_2);
  assert(stage_v_436_1 == stage_v_436_2);
  assert(stage_v_437_1 == stage_v_437_2);
  assert(stage_v_438_1 == stage_v_438_2);
  assert(stage_v_439_1 == stage_v_439_2);
  assert(stage_v_440_1 == stage_v_440_2);
  assert(stage_v_441_1 == stage_v_441_2);
  assert(stage_v_442_1 == stage_v_442_2);
  assert(stage_v_443_1 == stage_v_443_2);
  assert(stage_v_444_1 == stage_v_444_2);
  assert(stage_v_445_1 == stage_v_445_2);
  assert(stage_v_446_1 == stage_v_446_2);
}


